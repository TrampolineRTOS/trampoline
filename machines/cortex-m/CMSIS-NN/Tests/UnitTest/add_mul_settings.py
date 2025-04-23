# SPDX-FileCopyrightText: Copyright 2010-2024 Arm Limited and/or its affiliates <open-source-office@arm.com>
#
# SPDX-License-Identifier: Apache-2.0
#
# Licensed under the Apache License, Version 2.0 (the License); you may
# not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an AS IS BASIS, WITHOUT
# WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
from test_settings import TestSettings

import tensorflow as tf
import numpy as np
import keras


class AddMulSettings(TestSettings):

    def __init__(self,
                 dataset,
                 testtype,
                 regenerate_weights,
                 regenerate_input,
                 regenerate_biases,
                 schema_file,
                 channels=1,
                 x_in=4,
                 y_in=4,
                 decimal_input=6,
                 randmin=TestSettings.INT8_MIN,
                 randmax=TestSettings.INT8_MAX,
                 out_activation_min=TestSettings.INT8_MIN,
                 out_activation_max=TestSettings.INT8_MAX,
                 int16xint8=False,
                 interpreter="tensorflow"):
        super().__init__(dataset,
                         testtype,
                         regenerate_weights,
                         regenerate_input,
                         regenerate_biases,
                         schema_file,
                         in_ch=channels,
                         out_ch=channels,
                         x_in=x_in,
                         y_in=y_in,
                         w_x=1,
                         w_y=1,
                         stride_x=1,
                         stride_y=1,
                         pad=False,
                         randmin=randmin,
                         randmax=randmax,
                         batches=1,
                         generate_bias=False,
                         relu6=False,
                         out_activation_min=out_activation_min,
                         out_activation_max=out_activation_max,
                         int16xint8=int16xint8,
                         interpreter=interpreter)

        self.x_input = self.x_output = x_in
        self.y_input = self.y_output = y_in
        self.decimal_input = decimal_input

        self.left_shift = 15 if self.is_int16xint8 else 20

    def generate_data(self, input_data1=None, input_data2=None) -> None:
        input_shape = (1, self.y_input, self.x_input, self.input_ch)

        input_data1 = self.get_randomized_data(list(input_shape),
                                               self.inputs_table_file,
                                               regenerate=self.regenerate_new_input,
                                               decimals=self.decimal_input)
        input_data2 = self.get_randomized_data(list(input_shape),
                                               self.kernel_table_file,
                                               regenerate=self.regenerate_new_weights,
                                               decimals=self.decimal_input)

        if self.is_int16xint8:
            inttype = "int16_t"
            inttype_tf = tf.int16
        else:
            inttype = "int8_t"
            inttype_tf = tf.int8

        # Create a one-layer functional Keras model as add/mul cannot use a sequntial Keras model.
        input1 = keras.layers.Input(shape=input_shape[1:])
        input2 = keras.layers.Input(shape=input_shape[1:])
        if self.test_type == 'add':
            layer = keras.layers.Add()([input1, input2])
        elif self.test_type == 'mul':
            layer = keras.layers.Multiply()([input1, input2])
        else:
            raise RuntimeError("Wrong test type")
        out = keras.layers.Lambda(function=lambda x: x)(layer)
        model = keras.models.Model(inputs=[input1, input2], outputs=out)

        interpreter = self.convert_and_interpret(model, inttype_tf)

        input_details = interpreter.get_input_details()
        interpreter.set_tensor(input_details[0]["index"], tf.cast(input_data1, inttype_tf))
        interpreter.set_tensor(input_details[1]["index"], tf.cast(input_data2, inttype_tf))

        # Calculate multipliers, shifts and offsets.
        (input1_scale, self.input1_zero_point) = input_details[0]['quantization']
        (input2_scale, self.input2_zero_point) = input_details[1]['quantization']
        self.input1_zero_point = -self.input1_zero_point
        self.input2_zero_point = -self.input2_zero_point
        double_max_input_scale = max(input1_scale, input2_scale) * 2
        (self.input1_mult, self.input1_shift) = self.quantize_scale(input1_scale / double_max_input_scale)
        (self.input2_mult, self.input2_shift) = self.quantize_scale(input2_scale / double_max_input_scale)

        if self.test_type == 'add':
            actual_output_scale = double_max_input_scale / ((1 << self.left_shift) * self.output_scale)
        elif self.test_type == 'mul':
            actual_output_scale = input1_scale * input2_scale / self.output_scale
        (self.output_mult, self.output_shift) = self.quantize_scale(actual_output_scale)

        # Generate reference.
        interpreter.invoke()
        output_details = interpreter.get_output_details()
        output_data = interpreter.get_tensor(output_details[0]["index"])
        self.generate_c_array("input1", input_data1, datatype=inttype)
        self.generate_c_array("input2", input_data2, datatype=inttype)
        self.generate_c_array(self.output_data_file_prefix,
                              np.clip(output_data, self.out_activation_min, self.out_activation_max),
                              datatype=inttype)

        self.write_c_config_header()
        self.write_c_header_wrapper()

    def write_c_config_header(self) -> None:
        super().write_c_config_header(write_common_parameters=False)

        filename = self.config_data
        filepath = self.headers_dir + filename
        prefix = self.testdataset.upper()

        with open(filepath, "a") as f:
            f.write("#define {}_DST_SIZE {}\n".format(prefix,
                                                      self.batches * self.y_input * self.x_input * self.input_ch))
            f.write("#define {}_OUT_ACTIVATION_MIN {}\n".format(prefix, self.out_activation_min))
            f.write("#define {}_OUT_ACTIVATION_MAX {}\n".format(prefix, self.out_activation_max))
            f.write("#define {}_INPUT1_OFFSET {}\n".format(prefix, self.input1_zero_point))
            f.write("#define {}_INPUT2_OFFSET {}\n".format(prefix, self.input2_zero_point))
            f.write("#define {}_OUTPUT_MULT {}\n".format(prefix, self.output_mult))
            f.write("#define {}_OUTPUT_SHIFT {}\n".format(prefix, self.output_shift))
            f.write("#define {}_OUTPUT_OFFSET {}\n".format(prefix, self.output_zero_point))
            if self.test_type == 'add':
                f.write("#define {}_LEFT_SHIFT {}\n".format(prefix, self.left_shift))
                f.write("#define {}_INPUT1_SHIFT {}\n".format(prefix, self.input1_shift))
                f.write("#define {}_INPUT2_SHIFT {}\n".format(prefix, self.input2_shift))
                f.write("#define {}_INPUT1_MULT {}\n".format(prefix, self.input1_mult))
                f.write("#define {}_INPUT2_MULT {}\n".format(prefix, self.input2_mult))
