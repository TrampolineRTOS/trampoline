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


class FullyConnectedSettings(TestSettings):

    def __init__(self,
                 dataset,
                 testtype,
                 regenerate_weights,
                 regenerate_input,
                 regenerate_biases,
                 schema_file,
                 in_ch=1,
                 out_ch=1,
                 x_in=1,
                 y_in=1,
                 w_x=1,
                 w_y=1,
                 stride_x=1,
                 stride_y=1,
                 pad=False,
                 randmin=TestSettings.INT8_MIN,
                 randmax=TestSettings.INT8_MAX,
                 batches=1,
                 generate_bias=True,
                 out_activation_min=None,
                 out_activation_max=None,
                 int16xint8=False,
                 bias_min=TestSettings.INT32_MIN,
                 bias_max=TestSettings.INT32_MAX,
                 interpreter="tensorflow",
                 input_scale=0.1,
                 input_zp=0,
                 w_scale=0.005,
                 w_zp=0,
                 bias_scale=0.00002,
                 bias_zp=0,
                 output_scale=0.1,
                 output_zp=0,
                 int4_weights=False
                 ):
        super().__init__(dataset,
                         testtype,
                         regenerate_weights,
                         regenerate_input,
                         regenerate_biases,
                         schema_file,
                         in_ch,
                         out_ch,
                         x_in,
                         y_in,
                         x_in,
                         y_in,
                         stride_x,
                         stride_y,
                         pad,
                         randmin,
                         randmax,
                         batches,
                         generate_bias=generate_bias,
                         out_activation_min=out_activation_min,
                         out_activation_max=out_activation_max,
                         int16xint8=int16xint8,
                         bias_min=bias_min,
                         bias_max=bias_max,
                         interpreter=interpreter,
                         int4_weights=int4_weights)

        self.filter_zero_point = w_zp

        if self.int4_weights or self.filter_zero_point:
            if self.generate_bias:
                self.json_template = "TestCases/Common/fc_weights_template.json"
            else:
                self.json_template = "TestCases/Common/fc_weights_template_null_bias.json"

            weight_type = "INT4" if self.int4_weights else "INT8"

            self.json_replacements = {
                "batches": batches,
                "input_size": in_ch * x_in * y_in,
                "input_scale": input_scale,
                "input_zp": input_zp,
                "w_type": weight_type,
                "w_scale": w_scale,
                "w_zp": w_zp,
                "bias_size": out_ch,
                "bias_scale": bias_scale,
                "bias_zp": bias_zp,
                "output_size": out_ch,
                "output_scale": output_scale,
                "output_zp": output_zp
            }

    def write_c_config_header(self) -> None:
        super().write_c_config_header()

        filename = self.config_data
        filepath = self.headers_dir + filename
        prefix = self.testdataset.upper()

        with open(filepath, "a") as f:
            f.write("#define {}_OUTPUT_MULTIPLIER {}\n".format(prefix, self.quantized_multiplier))
            f.write("#define {}_OUTPUT_SHIFT {}\n".format(prefix, self.quantized_shift))
            f.write("#define {}_ACCUMULATION_DEPTH {}\n".format(prefix, self.input_ch * self.x_input * self.y_input))
            f.write("#define {}_INPUT_OFFSET {}\n".format(prefix, -self.input_zero_point))
            f.write("#define {}_FILTER_OFFSET {}\n".format(prefix, -self.filter_zero_point))
            f.write("#define {}_OUTPUT_OFFSET {}\n".format(prefix, self.output_zero_point))

    def quantize_multiplier(self, weights_scale):
        input_product_scale = self.input_scale * weights_scale
        if input_product_scale < 0:
            raise RuntimeError("negative input product scale")
        real_multipler = input_product_scale / self.output_scale
        (self.quantized_multiplier, self.quantized_shift) = self.quantize_scale(real_multipler)

    def generate_data(self, input_data=None, weights=None, biases=None) -> None:

        if self.is_int16xint8:
            inttype = tf.int16
            datatype = "int16_t"
            bias_datatype = "int64_t"
        else:
            inttype = tf.int8
            datatype = "int8_t"
            bias_datatype = "int32_t"

        # Generate data
        fc_input_format = [self.batches, self.input_ch * self.x_input * self.y_input]
        if input_data is not None:
            input_data = tf.reshape(input_data, fc_input_format)
        else:
           input_data = self.get_randomized_input_data(input_data, fc_input_format)

        # Generate bias
        if self.generate_bias:
            biases = self.get_randomized_bias_data(biases)
        else:
            biases = None

        if self.filter_zero_point:
            temp1 = self.model_path
            temp2 = self.json_template

            fc_weights_format = [self.input_ch * self.y_input * self.x_input * self.output_ch]
            if weights is not None:
                weights = tf.reshape(weights, fc_weights_format)
            else:
                weights = self.get_randomized_data(fc_weights_format,
                                                   self.kernel_table_file,
                                                   minrange=TestSettings.INT8_MIN,
                                                   maxrange=TestSettings.INT8_MAX,
                                                   regenerate=self.regenerate_new_weights)

            self.model_path = self.model_path
            self.json_template = self.json_template
            generated_json = self.generate_json_from_template(weights, bias_data=biases, bias_buffer=2)
            self.flatc_generate_tflite(generated_json, self.schema_file)

            weights_size = weights.numpy().size
            filter_index = 1
            bias_index = 2

        elif self.int4_weights:
            # Generate weights, both packed and unpacked model from JSON
            temp1 = self.model_path
            temp2 = self.json_template

            fc_weights_format = [self.input_ch * self.y_input * self.x_input * self.output_ch]
            if weights is not None:
                weights = tf.reshape(weights, fc_weights_format)
            else:
                weights = self.get_randomized_data(fc_weights_format,
                                                   self.kernel_table_file,
                                                   minrange=TestSettings.INT4_MIN,
                                                   maxrange=TestSettings.INT4_MAX,
                                                   regenerate=self.regenerate_new_weights)

            # Unpacked model is used for reference during debugging only and not used by default
            self.model_path = self.model_path + "_unpacked"
            self.json_template = self.json_template[:-5] + "_unpacked.json"
            generated_json = self.generate_json_from_template(weights, bias_data=biases, bias_buffer=2)
            self.flatc_generate_tflite(generated_json, self.schema_file)

            self.model_path = temp1
            self.json_template = temp2

            uneven = len(weights) % 2
            if uneven:
                weights = tf.experimental.numpy.append(weights, 0)

            temp = np.reshape(weights, (len(weights) // 2, 2)).astype(np.uint8)
            temp = 0xff & ((0xf0 & (temp[:, 1] << 4)) | (temp[:, 0] & 0xf))
            weights = tf.convert_to_tensor(temp)
            weights_size = weights.numpy().size * 2

            if uneven:
                weights_size = weights_size - 1

            generated_json = self.generate_json_from_template(weights, bias_data=biases, bias_buffer=2)
            self.flatc_generate_tflite(generated_json, self.schema_file)

            filter_index = 1
            bias_index = 2

        else:
            fc_weights_format = [self.input_ch * self.y_input * self.x_input, self.output_ch]
            if weights is not None:
                weights = tf.reshape(weights, fc_weights_format)
            else:
                weights = self.get_randomized_data(fc_weights_format,
                                                   self.kernel_table_file,
                                                   minrange=TestSettings.INT32_MIN,
                                                   maxrange=TestSettings.INT32_MAX,
                                                   regenerate=self.regenerate_new_weights)
            weights_size = weights.numpy().size

            # Generate model in tensorflow with one fully_connected layer
            model = keras.models.Sequential()
            model.add(
                keras.layers.InputLayer(input_shape=(self.y_input * self.x_input * self.input_ch, ),
                                        batch_size=self.batches))
            fully_connected_layer = keras.layers.Dense(self.output_ch, activation=None, use_bias=self.generate_bias)
            model.add(fully_connected_layer)
            if self.generate_bias:
                fully_connected_layer.set_weights([weights, biases])
            else:
                fully_connected_layer.set_weights([weights])
            self.convert_model(model, inttype)

            bias_index = 1
            if self.generate_bias:
                filter_index = 2
            else:
                filter_index = 1

        interpreter = self.interpret_model(input_data, inttype)

        # Get layer information
        all_layers_details = interpreter.get_tensor_details()
        filter_layer = all_layers_details[filter_index]
        bias_layer = all_layers_details[bias_index]

        if weights_size != interpreter.get_tensor(filter_layer['index']).size or \
           (self.generate_bias and biases.numpy().size != interpreter.get_tensor(bias_layer['index']).size):
            raise RuntimeError(f"Dimension mismatch for {self.testdataset}")

        weights_zero_point = filter_layer['quantization_parameters']['zero_points'][0]
        if weights_zero_point != self.filter_zero_point:
            raise RuntimeError(f"Filter zero point point mismatch for {self.filter_zero_point}")

        self.x_output = 1
        self.y_output = 1

        weights_scale = filter_layer['quantization_parameters']['scales'][0]
        self.quantize_multiplier(weights_scale)

        # Generate reference output
        output_details = interpreter.get_output_details()
        interpreter.invoke()
        output_data = interpreter.get_tensor(output_details[0]["index"])

        # Save results
        self.generate_c_array(self.input_data_file_prefix, input_data, datatype=datatype)
        self.generate_c_array(
            self.weight_data_file_prefix, interpreter.get_tensor(filter_layer['index']), pack=self.int4_weights)
        if not self.generate_bias:
            bias = []
        else:
            bias = interpreter.get_tensor(bias_layer['index'])
        self.generate_c_array(self.bias_data_file_prefix, bias, datatype=bias_datatype)

        self.generate_c_array(self.output_data_file_prefix,
                              np.clip(output_data, self.out_activation_min, self.out_activation_max),
                              datatype=datatype)
        self.write_c_config_header()
        self.write_c_header_wrapper()
