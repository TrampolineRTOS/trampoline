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
import math
from test_settings import TestSettings
import tensorflow as tf
import keras

class SoftmaxSettings(TestSettings):
    softmax_input_integer_bits = 5

    def __init__(self,
                 dataset,
                 testtype,
                 regenerate_weights,
                 regenerate_input,
                 regenerate_biases,
                 schema_file,
                 x_in=5,
                 y_in=1,
                 randmin=TestSettings.INT8_MIN,
                 randmax=TestSettings.INT8_MAX,
                 int16xint8=False,
                 inInt8outInt16=False,
                 input_scale=0.003922,
                 input_zp=-128,
                 interpreter="tensorflow"):
        super().__init__(dataset,
                         testtype,
                         regenerate_weights,
                         regenerate_input,
                         regenerate_biases,
                         schema_file,
                         1,
                         1,
                         x_in,
                         y_in,
                         1,
                         1,
                         1,
                         1,
                         False,
                         randmin,
                         randmax,
                         int16xint8=int16xint8,
                         interpreter=interpreter)
        self.x_input = self.x_output = x_in
        self.y_input = self.y_output = y_in
        self.inInt8outInt16 = inInt8outInt16

        if self.inInt8outInt16 and self.is_int16xint8:
            raise RuntimeError("Specify input as either s8 or s16")

        if self.inInt8outInt16:
            self.input_scale = input_scale
            self.json_template = "TestCases/Common/Softmax/softmax_int8_to_int16_template.json"
            self.json_replacements = {
                "num_rows": self.y_input,
                "row_size": self.x_input,
                "input_scale": input_scale,
                "input_zp": input_zp
            }

    def calc_softmax_params(self):
        if self.is_int16xint8:
            input_scale_beta_rescale = self.input_scale / (10.0 / 65535.0)
            (self.input_multiplier, self.input_left_shift) = self.quantize_scale(input_scale_beta_rescale)
        else:
            input_real_multiplier = min(self.input_scale * (1 << (31 - self.softmax_input_integer_bits)), (1 << 31) - 1)
            (self.input_multiplier, self.input_left_shift) = self.quantize_scale(input_real_multiplier)

            self.diff_min = ((1 << self.softmax_input_integer_bits) - 1) * \
                            (1 << (31 - self.softmax_input_integer_bits)) / \
                            (1 << self.input_left_shift)
            self.diff_min = math.floor(self.diff_min)

    def write_c_config_header(self) -> None:
        super().write_c_config_header(write_common_parameters=False)

        filename = self.config_data
        filepath = self.headers_dir + filename
        prefix = self.testdataset.upper()

        with open(filepath, "a") as f:
            f.write("#define {}_NUM_ROWS {}\n".format(prefix, self.y_input))
            f.write("#define {}_ROW_SIZE {}\n".format(prefix, self.x_input))
            f.write("#define {}_INPUT_MULT {}\n".format(prefix, self.input_multiplier))
            f.write("#define {}_INPUT_LEFT_SHIFT {}\n".format(prefix, self.input_left_shift))
            if not self.is_int16xint8:
                f.write("#define {}_DIFF_MIN {}\n".format(prefix, -self.diff_min))
            f.write("#define {}_DST_SIZE {}\n".format(prefix, self.x_output * self.y_output))

    def get_softmax_randomized_input_data(self, input_data, input_shape):
        # Generate or load saved input data unless hardcoded data provided.
        if input_data is not None:
            input_data = tf.reshape(input_data, input_shape)
        else:
            input_data = self.get_randomized_data(input_shape,
                                                  self.inputs_table_file,
                                                  regenerate=self.regenerate_new_input)
        return input_data

    def generate_data(self, input_data=None, weights=None, biases=None) -> None:
        input_data = self.get_softmax_randomized_input_data(input_data, [self.y_input, self.x_input])

        if self.is_int16xint8:
            inttype = tf.int16
            datatype = "int16_t"
        else:
            inttype = tf.int8
            datatype = "int8_t"

        self.generate_c_array(self.input_data_file_prefix, input_data, datatype=datatype)

        # Generate reference.
        if self.inInt8outInt16:
            # Output is int16.
            datatype = "int16_t"

            # Keras does not support int8 input and int16 output for Softmax.
            # Using a template json instead.
            generated_json = self.generate_json_from_template()
            self.flatc_generate_tflite(generated_json, self.schema_file)

            interpreter = self.Interpreter(model_path=str(self.model_path_tflite),
                                           experimental_op_resolver_type=self.OpResolverType.BUILTIN_REF)
            interpreter.allocate_tensors()
            all_layers_details = interpreter.get_tensor_details()
            input_layer = all_layers_details[0]
            output_layer = all_layers_details[1]

            interpreter.set_tensor(input_layer["index"], tf.cast(input_data, tf.int8))
            interpreter.invoke()
            output_data = interpreter.get_tensor(output_layer["index"])
        else:
            # Create a one-layer Keras model.
            model = keras.models.Sequential()
            input_shape = (self.y_input, self.x_input)
            model.add(keras.layers.Softmax(input_shape=input_shape))

            interpreter = self.convert_and_interpret(model, inttype, tf.expand_dims(input_data, axis=0))
            output_details = interpreter.get_output_details()
            interpreter.invoke()
            output_data = interpreter.get_tensor(output_details[0]["index"])

        self.calc_softmax_params()
        self.generate_c_array(self.output_data_file_prefix, output_data, datatype=datatype)

        self.write_c_config_header()
        self.write_c_header_wrapper()
