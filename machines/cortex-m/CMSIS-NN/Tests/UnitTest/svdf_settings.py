# SPDX-FileCopyrightText: Copyright 2010-2023 Arm Limited and/or its affiliates <open-source-office@arm.com>
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


class SVDFSettings(TestSettings):

    def __init__(self,
                 dataset,
                 testtype,
                 regenerate_weights,
                 regenerate_input,
                 regenerate_biases,
                 schema_file,
                 batches=2,
                 number_inputs=2,
                 rank=8,
                 memory_size=10,
                 randmin=TestSettings.INT8_MIN,
                 randmax=TestSettings.INT8_MAX,
                 input_size=3,
                 number_units=4,
                 generate_bias=True,
                 int8_time_weights=False,
                 input_scale=0.1,
                 input_zp=0,
                 w_1_scale=0.005,
                 w_1_zp=0,
                 w_2_scale=0.005,
                 w_2_zp=0,
                 bias_scale=0.00002,
                 bias_zp=0,
                 state_scale=0.005,
                 state_zp=0,
                 output_scale=0.1,
                 output_zp=0,
                 interpreter="tensorflow"):
        super().__init__(dataset,
                         testtype,
                         regenerate_weights,
                         regenerate_input,
                         regenerate_biases,
                         schema_file,
                         1,
                         1,
                         1,
                         1,
                         1,
                         1,
                         1,
                         1,
                         False,
                         randmin,
                         randmax,
                         generate_bias=generate_bias,
                         interpreter=interpreter)
        self.batches = batches
        self.number_units = number_units
        self.input_size = input_size
        self.memory_size = memory_size
        self.rank = rank
        self.number_filters = self.number_units * self.rank
        self.time_table_file = self.pregenerated_data_dir + self.testdataset + '/' + 'time_data.txt'

        self.number_inputs = number_inputs
        self.input_sequence_length = self.number_inputs * self.input_size * self.batches

        self.int8_time_weights = int8_time_weights

        if self.int8_time_weights:
            self.json_template = "TestCases/Common/svdf_s8_weights_template.json"
            self.in_activation_max = TestSettings.INT8_MAX
            self.in_activation_min = TestSettings.INT8_MIN

        else:
            self.json_template = "TestCases/Common/svdf_template.json"
            self.in_activation_max = TestSettings.INT16_MAX
            self.in_activation_min = TestSettings.INT16_MIN

        self.json_replacements = {
            "memory_sizeXnumber_filters": self.memory_size * self.number_filters,
            "batches": self.batches,
            "input_size": self.input_size,
            "number_filters": self.number_filters,
            "memory_size": self.memory_size,
            "number_units": self.number_units,
            "rank_value": self.rank,
            "input_scale": input_scale,
            "input_zp": input_zp,
            "w_1_scale": w_1_scale,
            "w_1_zp": w_1_zp,
            "w_2_scale": w_2_scale,
            "w_2_zp": w_2_zp,
            "bias_scale": bias_scale,
            "bias_zp": bias_zp,
            "state_scale": state_scale,
            "state_zp": state_zp,
            "output_scale": output_scale,
            "output_zp": output_zp
        }

    def calc_multipliers_and_shifts(self, input_scale, weights_1_scale, weights_2_scale, state_scale, output_scale):
        effective_scale_1 = weights_1_scale * input_scale / state_scale
        effective_scale_2 = state_scale * weights_2_scale / output_scale
        (self.multiplier_in, self.shift_1) = self.quantize_scale(effective_scale_1)
        (self.multiplier_out, self.shift_2) = self.quantize_scale(effective_scale_2)

    def write_c_config_header(self) -> None:
        super().write_c_config_header(write_common_parameters=False)

        filename = self.config_data
        filepath = self.headers_dir + filename
        prefix = self.testdataset.upper()

        with open(filepath, "a") as f:
            f.write("#define {}_MULTIPLIER_IN {}\n".format(prefix, self.multiplier_in))
            f.write("#define {}_MULTIPLIER_OUT {}\n".format(prefix, self.multiplier_out))
            f.write("#define {}_SHIFT_1 {}\n".format(prefix, self.shift_1))
            f.write("#define {}_SHIFT_2 {}\n".format(prefix, self.shift_2))
            f.write("#define {}_IN_ACTIVATION_MIN {}\n".format(prefix, self.in_activation_min))
            f.write("#define {}_IN_ACTIVATION_MAX {}\n".format(prefix, self.in_activation_max))
            f.write("#define {}_RANK {}\n".format(prefix, self.rank))
            f.write("#define {}_FEATURE_BATCHES {}\n".format(prefix, self.number_filters))
            f.write("#define {}_TIME_BATCHES {}\n".format(prefix, self.memory_size))
            f.write("#define {}_INPUT_SIZE {}\n".format(prefix, self.input_size))
            f.write("#define {}_DST_SIZE {}\n".format(prefix, self.number_units * self.batches))
            f.write("#define {}_OUT_ACTIVATION_MIN {}\n".format(prefix, self.out_activation_min))
            f.write("#define {}_OUT_ACTIVATION_MAX {}\n".format(prefix, self.out_activation_max))
            f.write("#define {}_INPUT_BATCHES {}\n".format(prefix, self.batches))
            f.write("#define {}_INPUT_OFFSET {}\n".format(prefix, self.input_zero_point))
            f.write("#define {}_OUTPUT_OFFSET {}\n".format(prefix, self.output_zero_point))

    def generate_data(self, input_data=None, weights=None, biases=None, time_data=None, state_data=None) -> None:
        if self.int8_time_weights:
            if not self.use_tflite_micro_interpreter:
                print("Warning: interpreter tflite_micro must be used for SVDF int8. Skipping generating headers.")
                return

        # TODO: Make this compatible with newer versions than 2.10.
        if float(('.'.join(tf.__version__.split('.')[:2]))) > 2.10:
            print("Warning: tensorflow version > 2.10 not supported for SVDF unit tests. Skipping generating headers")
            return

        if input_data is not None:
            input_data = tf.reshape(input_data, [self.input_sequence_length])
        else:
            input_data = self.get_randomized_data([self.input_sequence_length],
                                                  self.inputs_table_file,
                                                  regenerate=self.regenerate_new_input)
        self.generate_c_array("input_sequence", input_data)

        if weights is not None:
            weights_feature_data = tf.reshape(weights, [self.number_filters, self.input_size])
        else:
            weights_feature_data = self.get_randomized_data([self.number_filters, self.input_size],
                                                            self.kernel_table_file,
                                                            regenerate=self.regenerate_new_weights)

        if time_data is not None:
            weights_time_data = tf.reshape(time_data, [self.number_filters, self.memory_size])
        else:
            weights_time_data = self.get_randomized_data([self.number_filters, self.memory_size],
                                                         self.time_table_file,
                                                         regenerate=self.regenerate_new_weights)

        if not self.generate_bias:
            biases = [0] * self.number_units
        if biases is not None:
            biases = tf.reshape(biases, [self.number_units])
        else:
            biases = self.get_randomized_data([self.number_units],
                                              self.bias_table_file,
                                              regenerate=self.regenerate_new_weights)

        # Generate tflite model
        generated_json = self.generate_json_from_template(weights_feature_data,
                                                          weights_time_data,
                                                          biases,
                                                          self.int8_time_weights)
        self.flatc_generate_tflite(generated_json, self.schema_file)

        # Run TFL interpreter
        interpreter = self.Interpreter(model_path=str(self.model_path_tflite),
                                       experimental_op_resolver_type=self.OpResolverType.BUILTIN_REF)
        interpreter.allocate_tensors()

        # Read back scales and zero points from tflite model
        all_layers_details = interpreter.get_tensor_details()
        input_layer = all_layers_details[0]
        weights_1_layer = all_layers_details[1]
        weights_2_layer = all_layers_details[2]
        bias_layer = all_layers_details[3]
        state_layer = all_layers_details[4]
        output_layer = all_layers_details[5]
        (input_scale, self.input_zero_point) = self.get_scale_and_zp(input_layer)
        (weights_1_scale, zero_point) = self.get_scale_and_zp(weights_1_layer)
        (weights_2_scale, zero_point) = self.get_scale_and_zp(weights_2_layer)
        (bias_scale, zero_point) = self.get_scale_and_zp(bias_layer)
        (state_scale, zero_point) = self.get_scale_and_zp(state_layer)
        (output_scale, self.output_zero_point) = self.get_scale_and_zp(output_layer)

        self.calc_multipliers_and_shifts(input_scale, weights_1_scale, weights_2_scale, state_scale, output_scale)

        # Generate unit test C headers
        self.generate_c_array("weights_feature", interpreter.get_tensor(weights_1_layer['index']))
        self.generate_c_array(self.bias_data_file_prefix, interpreter.get_tensor(bias_layer['index']), "int32_t")

        if self.int8_time_weights:
            self.generate_c_array("weights_time", interpreter.get_tensor(weights_2_layer['index']), datatype='int8_t')
            self.generate_c_array("state", interpreter.get_tensor(state_layer['index']), "int8_t")
        else:
            self.generate_c_array("weights_time", interpreter.get_tensor(weights_2_layer['index']), datatype='int16_t')
            self.generate_c_array("state", interpreter.get_tensor(state_layer['index']), "int16_t")

        if self.use_tflite_micro_interpreter:
            interpreter = self.tflite_micro.runtime.Interpreter.from_file(model_path=str(self.model_path_tflite))

        # Generate reference output
        svdf_ref = None
        for i in range(self.number_inputs):
            start = i * self.input_size * self.batches
            end = i * self.input_size * self.batches + self.input_size * self.batches
            input_sequence = input_data[start:end]
            input_sequence = tf.reshape(input_sequence, [self.batches, self.input_size])
            if self.use_tflite_micro_interpreter:
                interpreter.set_input(tf.cast(input_sequence, tf.int8), input_layer["index"])
            else:
                interpreter.set_tensor(input_layer["index"], tf.cast(input_sequence, tf.int8))
            interpreter.invoke()
            if self.use_tflite_micro_interpreter:
                svdf_ref = interpreter.get_output(0)
            else:
                svdf_ref = interpreter.get_tensor(output_layer["index"])
        self.generate_c_array(self.output_data_file_prefix, svdf_ref)

        self.write_c_config_header()
        self.write_c_header_wrapper()

    def get_scale_and_zp(self, layer):
        return (layer['quantization_parameters']['scales'][0], layer['quantization_parameters']['zero_points'][0])
