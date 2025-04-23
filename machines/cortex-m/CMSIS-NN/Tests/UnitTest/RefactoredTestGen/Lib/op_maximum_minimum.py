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

class Op_maximum_minimum(Lib.op_utils.Op_type):

    def get_shapes(params):
        shapes = {}
        shapes["input_tensor_1"] = (params["batch_1"], params["height_1"], params["width_1"], params["channel_1"])
        shapes["input_tensor_2"] = (params["batch_2"], params["height_2"], params["width_2"], params["channel_2"])
        shapes["representational_dataset"] = (params["batch_1"], params["height_1"], params["width_1"], params["channel_1"])
        shapes["representational_dataset2"] = (params["batch_2"], params["height_2"], params["width_2"], params["channel_2"])
        shapes["different_in_shapes"]=True

        return shapes

    def generate_keras_model(shapes, params):
        tf.keras.backend.clear_session()
        layer_type = None
        if params['layer_type'] == "minimum":
            layer_type = tf.minimum
        elif params['layer_type'] == "maximum":
            layer_type = tf.maximum

        input_1_shape = (params["batch_1"], params["height_1"], params["width_1"], params["channel_1"])
        input_2_shape = (params["batch_2"], params["height_2"], params["width_2"], params["channel_2"])
        input_1 = keras.layers.Input(batch_input_shape=input_1_shape)
        input_2 = keras.layers.Input(batch_input_shape=input_2_shape)

        layer = layer_type(input_1, input_2)
        model = keras.Model([input_1, input_2], [layer])

        return model

    def generate_data_tflite(tflite_fname, params):
        tensors = {}
        effective_scales = {}
        scales = {}
        generated_params = {}
        aliases = {}

        # To be removed
        aliases["output_multiplier"] = "output_mult"
        aliases["output"] = "output_ref"

        interpreter = Interpreter(str(tflite_fname), experimental_op_resolver_type=OpResolverType.BUILTIN_REF)
        interpreter.allocate_tensors()
        tensor_details = interpreter.get_tensor_details()

        input_1 = tensor_details[0]
        input_2 = tensor_details[1]

        input_details = interpreter.get_input_details()
        (scales["scale_1"], scales["zero_point_1"]) = input_details[0]['quantization']
        (scales["scale_2"], scales["zero_point2"]) = input_details[1]['quantization']

        output_details = interpreter.get_output_details()
        (scales["output_scale"], scales["output_zero_point"]) = output_details[0]['quantization']

        minval = Lib.op_utils.get_dtype_min(params["input_data_type"])
        maxval = Lib.op_utils.get_dtype_max(params["input_data_type"])

        n_output = output_details[0]['shape'][0]
        h_output = output_details[0]['shape'][1]
        w_output = output_details[0]['shape'][2]
        c_output = output_details[0]['shape'][3]

        generated_params["dst_size"] = n_output * h_output * w_output * c_output
        generated_params["output_batch"] = n_output
        generated_params["output_height"] = h_output
        generated_params["output_width"] = w_output
        generated_params["output_channel"] = c_output
        generated_params["input_1_offset"] = -input_1['quantization_parameters']['zero_points'][0]
        generated_params["input_2_offset"] = -input_2['quantization_parameters']['zero_points'][0]
        generated_params["output_offset"] = output_details[0]['quantization'][1]

        def quantize_scale(scales):
            effective_output_scale = scales["scale_1"] * scales["scale_2"] / scales["output_scale"]

            significand, shift = math.frexp(effective_output_scale)
            significand_q31 = round(significand * (1 << 31))
            return significand_q31, shift

        mult, shift = quantize_scale(scales)
        generated_params["output_multiplier"] = mult
        generated_params["output_shift"] = shift

        return Lib.op_utils.Generated_data(generated_params, tensors, scales, effective_scales, aliases)

