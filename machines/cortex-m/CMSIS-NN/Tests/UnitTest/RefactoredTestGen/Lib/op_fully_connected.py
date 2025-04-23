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

import math

import Lib.op_utils

from tensorflow.lite.python.interpreter import Interpreter
from tensorflow.lite.python.interpreter import OpResolverType

import numpy as np
import keras


def quantize_multiplier(input_scale, weights_scale, output_scale):
    def quantize_scale(scale):
        significand, shift = math.frexp(scale)
        significand_q31 = round(significand * (1 << 31))
        return significand_q31, shift

    input_product_scale = input_scale * weights_scale
    if input_product_scale < 0:
        raise RuntimeError("negative input product scale")
    real_multipler = input_product_scale / output_scale
    return quantize_scale(real_multipler)


class Op_fully_connected(Lib.op_utils.Op_type):

    def get_shapes(params):
        shapes = {}

        # Common default parameters
        params["batch_size"] = 1 if "batch_size" not in params else params["batch_size"]
        params["generate_bias"] = True if "generate_bias" not in params else params["generate_bias"]
        if "out_activation_min" not in params:
            params["out_activation_min"] = Lib.op_utils.get_dtype_min(params["input_data_type"])
        if "out_activation_max" not in params:
            params["out_activation_max"] = Lib.op_utils.get_dtype_max(params["input_data_type"])

        if params["weights_data_type"] == "int4_t":
            w_min = Lib.op_utils.get_dtype_min("int4_t")
            w_max = Lib.op_utils.get_dtype_max("int4_t")
            b_min = Lib.op_utils.get_dtype_min("int8_t")
            b_max = Lib.op_utils.get_dtype_max("int8_t")
            print("dadasdas")
        else:
            w_min = Lib.op_utils.get_dtype_min("int32_t")
            w_max = Lib.op_utils.get_dtype_max("int32_t")
            b_min = Lib.op_utils.get_dtype_min("int32_t")
            b_max = Lib.op_utils.get_dtype_max("int32_t")

        if "bias_min" not in params:
            params["bias_min"] = b_min
        if "bias_max" not in params:
            params["bias_max"] = b_max

        if "weights_min" not in params:
            params["weights_min"] = w_min
        if "weights_max" not in params:
            params["weights_max"] = w_max

        in_ch = params["in_ch"]
        out_ch = params["out_ch"]

        shapes["input_tensor"] = (params["batch_size"], in_ch)
        shapes["weight_shape"] = (in_ch, out_ch)

        if params["generate_bias"]:
            shapes["bias_shape"] = [out_ch]
        else:
            shapes["bias_shape"] = []

        if params["tflite_generator"] == "json":
            if params["generate_bias"]:
                params["json_template"] = "fully_connected.json"
            else:
                params["json_template"] = "fully_connected_null_bias.json"
        else:
            shapes["representational_dataset"] = (params["batch_size"], 1, 1, in_ch)

        return shapes

    def generate_data_json(shapes, params):
        tensors = {}
        effective_scales = {}
        scales = {}
        generated_params = {}
        aliases = {}

        generated_params["input_batches"] = params["batch_size"]
        generated_params["input_w"] = 1
        generated_params["input_h"] = 1
        generated_params["dst_size"] = params["out_ch"] * params["batch_size"]
        generated_params["accumulation_depth"] = params["in_ch"]
        generated_params["input_offset"] = -params["input_zp"]
        generated_params["output_offset"] = params["output_zp"]

        # To be removed
        aliases["input_bias"] = "biases"
        aliases["output"] = "output_ref"
        aliases["input_weights"] = "weights"

        weights = np.random.randint(
            params["weights_min"], params["weights_max"], size=shapes["weight_shape"])

        uneven = weights.size % 2
        if uneven:
            weights = np.append(weights, 0)

        temp = np.reshape(weights, (weights.size // 2, 2)).astype(np.uint8)
        weights = 0xff & ((0xf0 & (temp[:, 1] << 4)) | (temp[:, 0] & 0xf))
        tensors["input_weights"] = weights

        if params["generate_bias"]:
            tensors["input_bias"] = np.random.randint(
                params["bias_min"],
                params["bias_max"],
                size=shapes["bias_shape"])
        else:
            tensors["input_bias"] = None

        generated_params["output_multiplier"], generated_params["output_shift"] = quantize_multiplier(
            params["input_scale"], params["w_scale"], params["output_scale"])

        return Lib.op_utils.Generated_data(generated_params, tensors, scales, effective_scales, aliases)

    def generate_data_tflite(tflite_fname, params):
        tensors = {}
        effective_scales = {}
        scales = {}
        generated_params = {}
        aliases = {}

        # To be removed
        aliases["output_multiplier"] = "output_mult"
        aliases["bias"] = "biases"
        aliases["output"] = "output_ref"

        interpreter = Interpreter(str(tflite_fname), experimental_op_resolver_type=OpResolverType.BUILTIN_REF)
        interpreter.allocate_tensors()
        tensor_details = interpreter.get_tensor_details()

        bias_index = 1
        if params["generate_bias"]:
            filter_index = 2
        else:
            filter_index = 1

        filter_layer = tensor_details[filter_index]
        scales["scaling_factors"] = filter_layer['quantization_parameters']['scales']

        if params["generate_bias"]:
            bias_layer = tensor_details[bias_index]
        else:
            bias_layer = None

        input_details = interpreter.get_input_details()
        (scales["input_scale"], scales["input_zero_point"]) = input_details[0]['quantization']

        output_details = interpreter.get_output_details()
        (scales["output_scale"], scales["output_zero_point"]) = output_details[0]['quantization']

        tensors["weights"] = interpreter.get_tensor(filter_layer['index'])
        if params["generate_bias"]:
            tensors["bias"] = interpreter.get_tensor(bias_layer['index'])
        else:
            tensors["bias"] = None

        generated_params["input_batches"] = params["batch_size"]
        generated_params["input_w"] = 1
        generated_params["input_h"] = 1
        generated_params["dst_size"] = params["out_ch"] * params["batch_size"]
        generated_params["accumulation_depth"] = params["in_ch"]
        generated_params["input_offset"] = -scales["input_zero_point"]
        generated_params["output_offset"] = scales["output_zero_point"]

        if params["per_channel_quant"]:
            per_channel_multiplier, per_channel_shift = Lib.op_utils.generate_quantize_per_channel_multiplier(
                params, scales)
            tensors["output_multiplier"] = np.array(per_channel_multiplier)
            tensors["output_shift"] = np.array(per_channel_shift)
        else:
            weights_scale = filter_layer['quantization_parameters']['scales'][0]
            generated_params["output_multiplier"], generated_params["output_shift"] = quantize_multiplier(
                scales["input_scale"], weights_scale, scales["output_scale"])

        return Lib.op_utils.Generated_data(generated_params, tensors, scales, effective_scales, aliases)

    def generate_keras_model(shapes, params):

        model = keras.models.Sequential()
        model.add(
            keras.layers.InputLayer(input_shape=(params["in_ch"], ), batch_size=params["batch_size"]))

        fully_connected_layer = keras.layers.Dense(params["out_ch"], activation=None, use_bias=params["generate_bias"])
        model.add(fully_connected_layer)

        weights = Lib.op_utils.generate_tf_tensor(
            shapes["weight_shape"], params["weights_min"], params["weights_max"], decimals=8)

        if params["generate_bias"]:
            bias = Lib.op_utils.generate_tf_tensor(
                shapes["bias_shape"], params["bias_min"], params["bias_max"])
            fully_connected_layer.set_weights([weights, bias])
        else:
            fully_connected_layer.set_weights([weights])

        return model
