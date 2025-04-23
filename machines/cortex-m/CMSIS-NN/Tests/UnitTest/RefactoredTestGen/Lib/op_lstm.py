# SPDX-FileCopyrightText: Copyright 2024 Arm Limited and/or its affiliates <open-source-office@arm.com>
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
import Lib.op_utils
import tensorflow as tf
import math
import numpy as np

from tensorflow.lite.python.interpreter import Interpreter
from tensorflow.lite.python.interpreter import OpResolverType
import tf_keras as keras

class Op_lstm(Lib.op_utils.Op_type):

    def get_shapes(params):
        shapes = {}
        if params["time_major"] and params["tflite_generator"] == "json":
            shapes["input_tensor"] = (params["time_steps"], params["batch_size"], params["input_size"])
        else:
            shapes["input_tensor"] = (params["batch_size"], params["time_steps"], params["input_size"])

        shapes["input_weights"] = (params["input_size"], params["hidden_size"])
        shapes["all_input_weights"] = (params["input_size"], params["hidden_size"] * 4)

        shapes["hidden_weights"] = (params["hidden_size"], params["hidden_size"])
        shapes["all_hidden_weights"] = (params["hidden_size"], params["hidden_size"] * 4)

        shapes["bias"] = (1, params["hidden_size"])
        shapes["all_bias"] = (params["hidden_size"] * 4, )

        shapes["representational_dataset"] = (params["batch_size"], params["time_steps"], params["input_size"])
        return shapes

    def generate_keras_model(shapes, params):
        input_layer = keras.layers.Input(shape=(params["time_steps"], params["input_size"]),
                                            batch_size=params["batch_size"],
                                            name='input')

        # NOTE: use_bias = False results in an unrolled lstm operator, so it is not really supported in TFLM
        if params["time_major"]:
            time_major_offset = 1
            input_layer_transposed = tf.transpose(input_layer, perm=[1, 0, 2])
            lstm_layer = keras.layers.LSTM(units=params["hidden_size"],
                                              time_major=params["time_major"],
                                              return_sequences=True)(input_layer_transposed)
        else:
            time_major_offset = 0
            lstm_layer = keras.layers.LSTM(units=params["hidden_size"],
                                              time_major=params["time_major"],
                                              return_sequences=True)(input_layer)

        model = keras.Model(input_layer, lstm_layer, name="LSTM")

        input_weights = Lib.op_utils.generate_tf_tensor(shapes["all_input_weights"], -1, 1, decimals=8)
        model.layers[1 + time_major_offset].weights[0].assign(input_weights)

        hidden_weights = Lib.op_utils.generate_tf_tensor(shapes["all_hidden_weights"], -1, 1, decimals=8)
        model.layers[1 + time_major_offset].weights[1].assign(hidden_weights)

        biases = Lib.op_utils.generate_tf_tensor(shapes["all_bias"], -1, 1, decimals=8) * 0
        model.layers[1 + time_major_offset].weights[2].assign(biases)

        return model

    def generate_data_tflite(tflite_fname, params):
        tensors = {}
        effective_scales = {}
        scales = {}
        generated_params = {}

        interpreter = Interpreter(str(tflite_fname), experimental_op_resolver_type=OpResolverType.BUILTIN_REF)
        interpreter.allocate_tensors()
        tensor_details = interpreter.get_tensor_details()

        if params["time_major"]:
            time_major_offset = 1
        else:
            time_major_offset = 0

        input_state = tensor_details[0]
        scales["input_scale"] = input_state['quantization_parameters']['scales'][0]
        cell_state = tensor_details[14 + time_major_offset * 2]
        scales["cell_scale"] = cell_state['quantization_parameters']['scales'][0]
        output_state = tensor_details[13 + time_major_offset * 2]
        scales["output_scale"] = output_state['quantization_parameters']['scales'][0]

        tmp = math.log(scales["cell_scale"]) * (1 / math.log(2))
        generated_params["cell_scale_power"] = int(round(tmp))

        effective_scales["forget_to_cell"] = pow(2, -15) * scales["cell_scale"] / scales["cell_scale"]
        effective_scales["input_to_cell"] = pow(2, -15) * pow(2, -15) / scales["cell_scale"]
        effective_scales["output"] = pow(2, -15) * pow(2, -15) / scales["output_scale"]

        #Help-function to read tensors and scales from tflite-model and calculating corresponding effective scale
        def calc_scale(name, input_scale, tensor_index):
            detail = tensor_details[tensor_index + time_major_offset]
            tensors[name + "_weights"] = interpreter.get_tensor(detail["index"]).flatten()
            scales[name + "_scale"] = detail['quantization_parameters']['scales'][0]
            effective_scales[name] = input_scale * scales[name + "_scale"] / pow(2, -12)

        calc_scale("output_gate_hidden", scales["output_scale"], 5)
        calc_scale("cell_gate_hidden", scales["output_scale"], 6)
        calc_scale("forget_gate_hidden", scales["output_scale"], 7)
        calc_scale("input_gate_hidden", scales["output_scale"], 8)

        calc_scale("output_gate_input", scales["input_scale"], 9)
        calc_scale("cell_gate_input", scales["input_scale"], 10)
        calc_scale("forget_gate_input", scales["input_scale"], 11)
        calc_scale("input_gate_input", scales["input_scale"], 12)

        tensors["output_gate_bias"] = interpreter.get_tensor(1 + time_major_offset).flatten()
        tensors["cell_gate_bias"] = interpreter.get_tensor(2 + time_major_offset).flatten()
        tensors["forget_gate_bias"] = interpreter.get_tensor(3 + time_major_offset).flatten()
        tensors["input_gate_bias"] = interpreter.get_tensor(4 + time_major_offset).flatten()

        generated_params["input_zero_point"] = -input_state['quantization_parameters']['zero_points'][0]
        generated_params["output_zero_point"] = tensor_details[20 + time_major_offset *
                                                               2]['quantization_parameters']['zero_points'][0]
        generated_params["cell_clip"] = Lib.op_utils.get_dtype_max("int16_t")

        return Lib.op_utils.Generated_data(generated_params, tensors, scales, effective_scales)

    def generate_data_json(shapes, params):
        tensors = {}
        scales = {}
        effective_scales = {}
        generated_params = {}

        maxval = 0.001
        minval = 0.0001

        scales["input_scale"] = np.round(np.random.rand(1) * (maxval - minval) + minval, 6)[0]
        scales["cell_scale"] = np.round(np.random.rand(1) * (maxval - minval) + maxval, 6)[0]
        scales["output_scale"] = np.round(np.random.rand(1) * (maxval - minval) + minval, 6)[0]

        tmp = math.log(scales["cell_scale"]) * (1 / math.log(2))
        generated_params["cell_scale_power"] = int(round(tmp))

        effective_scales["forget_to_cell"] = pow(2, -15) * scales["cell_scale"] / scales["cell_scale"]
        effective_scales["input_to_cell"] = pow(2, -15) * pow(2, -15) / scales["cell_scale"]
        effective_scales["output"] = pow(2, -15) * pow(2, -15) / scales["output_scale"]

        #Help-function to generate a scale, and calculating corresponding effective scale
        def create_scales(name, input_scale1):
            scales[name + "_scale"] = np.round(np.random.rand(1) * (maxval - minval) + minval, 6)[0]
            effective_scales[name] = input_scale1 * scales[name + "_scale"] / pow(2, -12)

        create_scales("output_gate_hidden", scales["output_scale"])
        create_scales("cell_gate_hidden", scales["output_scale"])
        create_scales("forget_gate_hidden", scales["output_scale"])
        create_scales("input_gate_hidden", scales["output_scale"])

        create_scales("output_gate_input", scales["input_scale"])
        create_scales("cell_gate_input", scales["input_scale"])
        create_scales("forget_gate_input", scales["input_scale"])
        create_scales("input_gate_input", scales["input_scale"])

        minval = Lib.op_utils.get_dtype_min(params["weights_data_type"])
        maxval = Lib.op_utils.get_dtype_max(params["weights_data_type"])
        tensors["input_gate_hidden_weights"] = np.random.randint(minval, maxval, size=shapes["hidden_weights"])
        tensors["forget_gate_hidden_weights"] = np.random.randint(minval, maxval, size=shapes["hidden_weights"])
        tensors["cell_gate_hidden_weights"] = np.random.randint(minval, maxval, size=shapes["hidden_weights"])
        tensors["output_gate_hidden_weights"] = np.random.randint(minval, maxval, size=shapes["hidden_weights"])
        tensors["input_gate_input_weights"] = np.random.randint(minval, maxval, size=shapes["input_weights"])
        tensors["forget_gate_input_weights"] = np.random.randint(minval, maxval, size=shapes["input_weights"])
        tensors["cell_gate_input_weights"] = np.random.randint(minval, maxval, size=shapes["input_weights"])
        tensors["output_gate_input_weights"] = np.random.randint(minval, maxval, size=shapes["input_weights"])

        maxval = Lib.op_utils.get_dtype_max(params["input_data_type"])
        minval = 0 # Negative weights are not supported in test generation
        tensors["input_gate_bias"] = np.random.randint(minval, maxval, size=shapes["bias"])
        tensors["forget_gate_bias"] = np.random.randint(minval, maxval, size=shapes["bias"])
        tensors["cell_gate_bias"] = np.random.randint(minval, maxval, size=shapes["bias"])
        tensors["output_gate_bias"] = np.random.randint(minval, maxval, size=shapes["bias"])

        minval = Lib.op_utils.get_dtype_min(params["input_data_type"])
        maxval = Lib.op_utils.get_dtype_max(params["input_data_type"])
        generated_params["output_zero_point"] = 0
        generated_params["input_zero_point"] = 0
        generated_params["cell_clip"] = Lib.op_utils.get_dtype_max("int16_t")

        return Lib.op_utils.Generated_data(generated_params, tensors, scales, effective_scales)
