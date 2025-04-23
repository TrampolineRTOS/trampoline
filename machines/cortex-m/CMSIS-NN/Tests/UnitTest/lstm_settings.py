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
import numpy as np
import tf_keras as keras

class LSTMSettings(TestSettings):

    def __init__(self,
                 dataset,
                 testtype,
                 regenerate_weights,
                 regenerate_input,
                 regenerate_biases,
                 schema_file,
                 batches=2,
                 time_steps=2,
                 number_inputs=3,
                 number_units=4,
                 time_major=True,
                 randmin=TestSettings.INT8_MIN,
                 randmax=TestSettings.INT8_MAX,
                 generate_bias=True,
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
        self.time_steps = time_steps
        self.number_units = number_units
        self.number_inputs = number_inputs

        self.kernel_hidden_table_file = self.pregenerated_data_dir + self.testdataset + '/' + 'kernel_hidden.txt'

        self.time_major = time_major

        self.in_activation_max = TestSettings.INT16_MAX
        self.in_activation_min = TestSettings.INT16_MIN

        self.lstm_scales = []

        # Layer indexes. Works with tensorflow 2.10 and 2.11.
        self.output_gate_bias_index = 1
        self.cell_gate_bias_index = 2
        self.forget_gate_bias_index = 3
        self.input_gate_bias_index = 4
        self.recurrent_input_to_output_w_index = 5
        self.recurrent_input_to_cell_w_index = 6
        self.recurrent_input_to_forget_w_index = 7
        self.recurrent_input_to_input_w_index = 8
        self.input_to_output_w_index = 9
        self.input_to_cell_w_index = 10
        self.input_to_forget_w_index = 11
        self.input_to_input_w_index = 12
        self.output_state_index = 13
        self.cell_state_index = 14
        self.input_norm_coeff_index = 15
        self.forget_norm_coeff_index = 16
        self.cell_norm_coeff_index = 17
        self.output_norm_coeff_index = 18
        self.effective_hidden_scale_intermediate_index = 20

    def generate_data(self, input_data=None, weights=None, hidden_weights=None, biases=None) -> None:

        input_dims = [self.batches, self.time_steps, self.number_inputs]
        if input_data is not None:
            input_data = tf.reshape(input_data, input_dims)
        else:
            input_data = self.get_randomized_data(input_dims,
                                                  self.inputs_table_file,
                                                  regenerate=self.regenerate_new_input)

        # This will be the same size when there is no projection.
        number_cells = self.number_units

        # Each LSTM cell has 4 input weights, 4 hidden (recurrent or cell state) weights and 4 biases.
        number_w_b = 4

        if weights is not None:
            weights = tf.reshape(weights, [self.number_inputs, number_cells * number_w_b])
        else:
            weights = self.get_randomized_data([self.number_inputs, number_cells * number_w_b],
                                               self.kernel_table_file,
                                               regenerate=self.regenerate_new_weights,
                                               decimals=8,
                                               minrange=-1.0,
                                               maxrange=1.0)

        if hidden_weights is not None:
            hidden_weights = tf.reshape(hidden_weights, [number_cells, number_cells * number_w_b])
        else:
            hidden_weights = self.get_randomized_data([number_cells, number_cells * number_w_b],
                                                      self.kernel_hidden_table_file,
                                                      regenerate=self.regenerate_new_weights,
                                                      decimals=8,
                                                      minrange=-1.0,
                                                      maxrange=1.0)
        if not self.generate_bias:
            biases = [0] * number_cells * number_w_b
        if biases is not None:
            biases = tf.reshape(biases, [number_cells * number_w_b])
        else:
            biases = self.get_randomized_data([number_cells * number_w_b],
                                              self.bias_table_file,
                                              regenerate=self.regenerate_new_bias,
                                              decimals=8,
                                              minrange=-1.0,
                                              maxrange=1.0)

        # Create a Keras based LSTM model.
        input_layer = keras.layers.Input(shape=(self.time_steps, self.number_inputs),
                                            batch_size=self.batches,
                                            name='input')
        if self.time_major:
            input_layer_transposed = tf.transpose(input_layer, perm=[1, 0, 2])
            lstm_layer = keras.layers.LSTM(units=self.number_units,
                                              time_major=self.time_major,
                                              return_sequences=True)(input_layer_transposed)
        else:
            lstm_layer = keras.layers.LSTM(units=self.number_units,
                                              time_major=self.time_major,
                                              return_sequences=True)(input_layer)
        model = keras.Model(input_layer, lstm_layer, name="LSTM")

        if self.time_major:
            time_major_offset = 1
            shape = (self.time_steps, self.batches, self.number_inputs)
        else:
            time_major_offset = 0
            shape = (self.batches, self.time_steps, self.number_inputs)

        # Writing weight and bias to model.
        print("Updating weights", model.layers[1 + time_major_offset].weights[0].name)
        model.layers[1 + time_major_offset].weights[0].assign(weights)
        print("Updating hidden weights", model.layers[1 + time_major_offset].weights[1].name)
        model.layers[1 + time_major_offset].weights[1].assign(hidden_weights)
        print("Updating bias", model.layers[1 + time_major_offset].weights[2].name)
        model.layers[1 + time_major_offset].weights[2].assign(biases)

        interpreter = self.convert_and_interpret(model, tf.int8, input_data, dataset_shape=shape)

        all_layers_details = interpreter.get_tensor_details()

        for i in all_layers_details:
            self.lstm_scales.append(i['quantization_parameters']['scales'])

        input_data_for_index = all_layers_details[0]

        input_gate_bias = all_layers_details[self.input_gate_bias_index + time_major_offset]
        forget_gate_bias = all_layers_details[self.forget_gate_bias_index + time_major_offset]
        cell_gate_bias = all_layers_details[self.cell_gate_bias_index + time_major_offset]
        output_gate_bias = all_layers_details[self.output_gate_bias_index + time_major_offset]

        input_to_input_w = all_layers_details[self.input_to_input_w_index + time_major_offset]
        input_to_forget_w = all_layers_details[self.input_to_forget_w_index + time_major_offset]
        input_to_cell_w = all_layers_details[self.input_to_cell_w_index + time_major_offset]
        input_to_output_w = all_layers_details[self.input_to_output_w_index + time_major_offset]

        recurrent_input_to_input_w = all_layers_details[self.recurrent_input_to_input_w_index + time_major_offset]
        recurrent_input_to_forget_w = all_layers_details[self.recurrent_input_to_forget_w_index + time_major_offset]
        recurrent_input_to_cell_w = all_layers_details[self.recurrent_input_to_cell_w_index + time_major_offset]
        recurrent_input_to_output_w = all_layers_details[self.recurrent_input_to_output_w_index + time_major_offset]

        if self.time_major:
            time_major_offset = 2

        output_state = all_layers_details[self.output_state_index + time_major_offset]
        cell_state = all_layers_details[self.cell_state_index + time_major_offset]

        input_norm_coeff = all_layers_details[self.input_norm_coeff_index + time_major_offset]
        forget_norm_coeff = all_layers_details[self.forget_norm_coeff_index + time_major_offset]
        cell_norm_coeff = all_layers_details[self.cell_norm_coeff_index + time_major_offset]
        output_norm_coeff = all_layers_details[self.output_norm_coeff_index + time_major_offset]

        # For scale and zero point.
        effective_hidden_scale_intermediate = all_layers_details[
            self.effective_hidden_scale_intermediate_index + time_major_offset]

        input_details = interpreter.get_input_details()
        output_details = interpreter.get_output_details()
        actual_input_data = interpreter.get_tensor(input_details[0]["index"])
        if (input_data.numpy().shape != actual_input_data.shape) or \
           not ((input_data.numpy().astype(int) == actual_input_data).all().astype(int)):
            raise RuntimeError("Input data mismatch")

        self.generate_c_array(self.input_data_file_prefix, interpreter.get_tensor(input_data_for_index['index']))
        self.generate_c_array("input_to_input_w", interpreter.get_tensor(input_to_input_w['index']))
        self.generate_c_array("input_to_forget_w", interpreter.get_tensor(input_to_forget_w['index']))
        self.generate_c_array("input_to_cell_w", interpreter.get_tensor(input_to_cell_w['index']))
        self.generate_c_array("input_to_output_w", interpreter.get_tensor(input_to_output_w['index']))
        self.generate_c_array("recurrent_input_to_input_w", interpreter.get_tensor(recurrent_input_to_input_w['index']))
        self.generate_c_array("recurrent_input_to_forget_w",
                              interpreter.get_tensor(recurrent_input_to_forget_w['index']))
        self.generate_c_array("recurrent_input_to_cell_w", interpreter.get_tensor(recurrent_input_to_cell_w['index']))
        self.generate_c_array("recurrent_input_to_output_w",
                              interpreter.get_tensor(recurrent_input_to_output_w['index']))

        # Peephole not supported so these are nullptrs.
        self.generate_c_array("cell_to_input", [], datatype='int16_t')
        self.generate_c_array("cell_to_forget", [], datatype='int16_t')
        self.generate_c_array("cell_to_output", [], datatype='int16_t')

        self.generate_c_array("input_gate_bias", interpreter.get_tensor(input_gate_bias['index']), datatype='int32_t')
        self.generate_c_array("cell_gate_bias", interpreter.get_tensor(cell_gate_bias['index']), datatype='int32_t')
        self.generate_c_array("forget_gate_bias", interpreter.get_tensor(forget_gate_bias['index']), datatype='int32_t')
        self.generate_c_array("output_gate_bias", interpreter.get_tensor(output_gate_bias['index']), datatype='int32_t')

        # Projection not supported so these are nullptrs.
        self.generate_c_array("projection_weights", [])
        self.generate_c_array("projection_bias", [], datatype='int32_t')

        self.generate_c_array("output_state", interpreter.get_tensor(output_state['index']), const="")
        self.generate_c_array("cell_state", interpreter.get_tensor(cell_state['index']), datatype='int16_t', const="")

        self.generate_c_array("input_norm_coeff", interpreter.get_tensor(input_norm_coeff['index']))
        self.generate_c_array("forget_norm_coeff", interpreter.get_tensor(forget_norm_coeff['index']))
        self.generate_c_array("cell_norm_coeff", interpreter.get_tensor(cell_norm_coeff['index']))
        self.generate_c_array("output_norm_coeff", interpreter.get_tensor(output_norm_coeff['index']))

        input_scale = input_data_for_index['quantization_parameters']['scales'][0]
        self.data_zp = input_data_for_index['quantization_parameters']['zero_points'][0]
        cell_scale = cell_state['quantization_parameters']['scales'][0]
        output_state_scale = output_state['quantization_parameters']['scales'][0]
        input_zp = input_data_for_index['quantization_parameters']['zero_points'][0]
        output_zp = output_details[0]['quantization_parameters']['zero_points'][0]
        output_state_zp = output_state['quantization_parameters']['zero_points'][0]
        self.hidden_zp = effective_hidden_scale_intermediate['quantization_parameters']['zero_points'][0]
        self.output_state_offset = output_state_zp

        tmp = math.log(cell_scale) * (1 / math.log(2))
        self.cell_state_shift = int(round(tmp))

        self.calc_scales(input_scale, output_state_scale, cell_scale)

        # Calculate effective biases.
        input_zp = -input_zp
        output_zp = -output_zp
        output_state_zp = -output_state_zp
        input_to_forget_eff_bias = self.calc_effective_bias(interpreter, input_zp, input_to_forget_w, forget_gate_bias)
        recurrent_to_forget_eff_bias = self.calc_effective_bias(interpreter, output_state_zp,
                                                                recurrent_input_to_forget_w, None, False)
        input_to_cell_eff_bias = self.calc_effective_bias(interpreter, input_zp, input_to_cell_w, cell_gate_bias)
        recurrent_to_cell_eff_bias = self.calc_effective_bias(interpreter, output_state_zp, recurrent_input_to_cell_w,
                                                              None, False)
        input_to_output_eff_bias = self.calc_effective_bias(interpreter, input_zp, input_to_output_w, output_gate_bias)
        recurrent_to_output_eff_bias = self.calc_effective_bias(interpreter, output_state_zp,
                                                                recurrent_input_to_output_w, None, False)
        input_to_input_eff_bias = self.calc_effective_bias(interpreter, input_zp, input_to_input_w, input_gate_bias)

        recurrent_to_input_eff_bias = self.calc_effective_bias(interpreter, output_state_zp, recurrent_input_to_input_w,
                                                               None, False)

        self.generate_c_array("input_to_input_eff_bias", input_to_input_eff_bias, datatype='int32_t')
        self.generate_c_array("input_to_forget_eff_bias", input_to_forget_eff_bias, datatype='int32_t')
        self.generate_c_array("input_to_cell_eff_bias", input_to_cell_eff_bias, datatype='int32_t')
        self.generate_c_array("input_to_output_eff_bias", input_to_output_eff_bias, datatype='int32_t')
        self.generate_c_array("recurrent_to_input_eff_bias", recurrent_to_input_eff_bias, datatype='int32_t')
        self.generate_c_array("recurrent_to_cell_eff_bias", recurrent_to_cell_eff_bias, datatype='int32_t')
        self.generate_c_array("recurrent_to_forget_eff_bias", recurrent_to_forget_eff_bias, datatype='int32_t')
        self.generate_c_array("recurrent_to_output_eff_bias", recurrent_to_output_eff_bias, datatype='int32_t')

        # Generate reference
        if self.use_tflite_micro_interpreter:
            interpreter = self.tflite_micro.runtime.Interpreter.from_file(model_path=str(self.model_path_tflite))
            interpreter.set_input(tf.cast(input_data, tf.int8), input_details[0]["index"])
            interpreter.invoke()
            output_data = interpreter.get_output(0)
        else:
            interpreter.invoke()
            output_data = interpreter.get_tensor(output_details[0]["index"])

        self.generate_c_array(self.output_data_file_prefix, output_data, datatype='int8_t')

        self.write_c_config_header()
        self.write_c_header_wrapper()

    def calc_scales(self, input_scale, output_state_scale, cell_scale):
        intermediate_scale = pow(2, -12)

        if self.time_major:
            time_major_offset = 1
        else:
            time_major_offset = 0


        self.effective_forget_scale = pow(2, -15) / cell_scale * cell_scale
        self.effective_input_scale = pow(2, -15) / cell_scale * pow(2, -15)
        self.effective_hidden_scale = pow(2, -15) / output_state_scale * pow(2, -15)

        self.i2i_effective_scale = input_scale * self.lstm_scales[self.input_to_input_w_index + time_major_offset][0] \
            / intermediate_scale
        self.i2f_effective_scale = input_scale * self.lstm_scales[self.input_to_forget_w_index + time_major_offset][0] \
            / intermediate_scale
        self.i2c_effective_scale = input_scale * self.lstm_scales[self.input_to_cell_w_index + time_major_offset][0] \
            / intermediate_scale
        self.i2o_effective_scale = input_scale * self.lstm_scales[self.input_to_output_w_index + time_major_offset][0] \
            / intermediate_scale

        self.r2i_effective_scale = output_state_scale * self.lstm_scales[self.recurrent_input_to_input_w_index +
                                                                         time_major_offset][0] / intermediate_scale
        self.r2f_effective_scale = output_state_scale * self.lstm_scales[self.recurrent_input_to_forget_w_index +
                                                                         time_major_offset][0] / intermediate_scale
        self.r2c_effective_scale = output_state_scale * self.lstm_scales[self.recurrent_input_to_cell_w_index +
                                                                         time_major_offset][0] / intermediate_scale
        self.r2o_effective_scale = output_state_scale * self.lstm_scales[self.recurrent_input_to_output_w_index +
                                                                         time_major_offset][0] / intermediate_scale

    def calc_effective_bias(self, interpreter, zero_point, weight_tensor, bias_tensor, has_bias=True) -> list:

        weights = interpreter.get_tensor(weight_tensor['index'])
        dims = weight_tensor['shape']
        row = dims[0]
        col = dims[1]

        if has_bias:
            bias_data = interpreter.get_tensor(bias_tensor['index'])
            output = bias_data
        else:
            output = np.zeros((row, ), dtype=np.int32)

        for i_row in range(row):
            row_sum = 0
            for i_col in range(col):
                row_sum = row_sum + weights[i_row][i_col]
            output[i_row] = output[i_row] + row_sum * zero_point

        return output

    def write_c_config_header(self) -> None:
        super().write_c_config_header(write_common_parameters=False)

        filename = self.config_data
        filepath = self.headers_dir + filename
        prefix = self.testdataset.upper()

        with open(filepath, "a") as f:
            f.write("#define {}_BUFFER_SIZE {}\n".format(prefix, self.batches * self.number_units))
            f.write("#define {}_INPUT_BATCHES {}\n".format(prefix, self.batches))
            f.write("#define {}_DST_SIZE {}\n".format(prefix, self.batches * self.time_steps * self.number_units))
            f.write("#define {}_TIME_STEPS {}\n".format(prefix, self.time_steps))
            f.write("#define {}_NUMBER_UNITS {}\n".format(prefix, self.number_units))
            f.write("#define {}_NUMBER_INPUTS {}\n".format(prefix, self.number_inputs))
            f.write("#define {}_TIME_MAJOR {}\n".format(prefix, int(self.time_major)))
            f.write("#define {}_IN_ACTIVATION_MIN {}\n".format(prefix, self.in_activation_min))
            f.write("#define {}_IN_ACTIVATION_MAX {}\n".format(prefix, self.in_activation_max))

            (multiplier, shift) = self.quantize_scale(self.i2i_effective_scale)
            f.write("#define {}_IN_TO_INPUT_MULTIPLIER {}\n".format(prefix, multiplier))
            f.write("#define {}_IN_TO_INPUT_SHIFT {}\n".format(prefix, shift))
            (multiplier, shift) = self.quantize_scale(self.i2f_effective_scale)
            f.write("#define {}_IN_TO_FORGET_MULTIPLIER {}\n".format(prefix, multiplier))
            f.write("#define {}_IN_TO_FORGET_SHIFT {}\n".format(prefix, shift))
            (multiplier, shift) = self.quantize_scale(self.i2c_effective_scale)
            f.write("#define {}_IN_TO_CELL_MULTIPLIER {}\n".format(prefix, multiplier))
            f.write("#define {}_IN_TO_CELL_SHIFT {}\n".format(prefix, shift))
            (multiplier, shift) = self.quantize_scale(self.i2o_effective_scale)
            f.write("#define {}_IN_TO_OUTPUT_MULTIPLIER {}\n".format(prefix, multiplier))
            f.write("#define {}_IN_TO_OUTPUT_SHIFT {}\n".format(prefix, shift))

            (multiplier, shift) = self.quantize_scale(self.r2i_effective_scale)
            f.write("#define {}_RECURRENT_TO_INPUT_MULTIPLIER {}\n".format(prefix, multiplier))
            f.write("#define {}_RECURRENT_TO_INPUT_SHIFT {}\n".format(prefix, shift))
            (multiplier, shift) = self.quantize_scale(self.r2f_effective_scale)
            f.write("#define {}_RECURRENT_TO_FORGET_MULTIPLIER {}\n".format(prefix, multiplier))
            f.write("#define {}_RECURRENT_TO_FORGET_SHIFT {}\n".format(prefix, shift))
            (multiplier, shift) = self.quantize_scale(self.r2c_effective_scale)
            f.write("#define {}_RECURRENT_TO_CELL_MULTIPLIER {}\n".format(prefix, multiplier))
            f.write("#define {}_RECURRENT_TO_CELL_SHIFT {}\n".format(prefix, shift))
            (multiplier, shift) = self.quantize_scale(self.r2o_effective_scale)
            f.write("#define {}_RECURRENT_TO_OUTPUT_MULTIPLIER {}\n".format(prefix, multiplier))
            f.write("#define {}_RECURRENT_TO_OUTPUT_SHIFT {}\n".format(prefix, shift))


            (multiplier, shift) = self.quantize_scale(self.effective_forget_scale)
            f.write("#define {}_FORGET_MULTIPLIER {}\n".format(prefix, multiplier))
            f.write("#define {}_FORGET_SHIFT {}\n".format(prefix, shift))

            (multiplier, shift) = self.quantize_scale(self.effective_input_scale)
            f.write("#define {}_INPUT_MULTIPLIER {}\n".format(prefix, multiplier))
            f.write("#define {}_INPUT_SHIFT {}\n".format(prefix, shift))

            (multiplier, shift) = self.quantize_scale(self.effective_hidden_scale)
            f.write("#define {}_HIDDEN_MULTIPLIER {}\n".format(prefix, multiplier))
            f.write("#define {}_HIDDEN_SHIFT {}\n".format(prefix, shift))

            f.write("#define {}_HIDDEN_OFFSET {}\n".format(prefix, self.hidden_zp))
            f.write("#define {}_DATA_OFFSET {}\n".format(prefix, -self.data_zp))

            f.write("#define {}_OUTPUT_STATE_OFFSET {}\n".format(prefix, self.output_state_offset))
            f.write("#define {}_CELL_STATE_SHIFT {}\n".format(prefix, self.cell_state_shift))

            for i in range(len(self.lstm_scales)):
                if len(self.lstm_scales[i]) == 0:
                    continue
                (multiplier, shift) = self.quantize_scale(self.lstm_scales[i][0])

