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

class Op_batch_matmul(Lib.op_utils.Op_type):

    def get_shapes(params):
        shapes = {}
        shapes["lhs_input_tensor"] = (params["lhs_batch"], params["lhs_height"], params["lhs_rows"], params["lhs_cols"])
        shapes["rhs_input_tensor"] = (params["rhs_batch"], params["rhs_height"], params["rhs_rows"], params["rhs_cols"])
        shapes["representational_dataset"] = (params["lhs_batch"], params["lhs_height"], params["lhs_rows"], params["lhs_cols"])
        shapes["representational_dataset2"] = (params["rhs_batch"], params["rhs_height"], params["rhs_rows"], params["rhs_cols"])
        shapes["different_in_shapes"]=True

        return shapes

    def generate_keras_model(shapes, params):
        tf.keras.backend.clear_session()
        input_shape_lhs = (params["lhs_batch"], params["lhs_height"], params["lhs_rows"], params["lhs_cols"])
        input_shape_rhs = (params["rhs_batch"], params["rhs_height"], params["rhs_rows"], params["rhs_cols"])
        input_lhs = keras.layers.Input(batch_input_shape=input_shape_lhs)
        input_rhs = keras.layers.Input(batch_input_shape=input_shape_rhs)

        layer = tf.matmul(input_lhs, input_rhs, transpose_a=params["adj_x"], transpose_b=params["adj_y"])
        model = keras.Model([input_lhs, input_rhs], [layer])

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

        lhs = tensor_details[0]
        rhs = tensor_details[1]

        input_details = interpreter.get_input_details()
        (scales["lhs_scale"], scales["lhs_zero_point"]) = input_details[0]['quantization']
        (scales["rhs_scale"], scales["rhs_zero_point"]) = input_details[1]['quantization']

        output_details = interpreter.get_output_details()
        (scales["output_scale"], scales["output_zero_point"]) = output_details[0]['quantization']

        tensors["lhs_input_tensor"] = interpreter.get_tensor(lhs['index'])
        tensors["rhs_input_tensor"] = interpreter.get_tensor(rhs['index'])
        tensors["lhs_transposed_tensor"] = tf.transpose(tensors["lhs_input_tensor"], [0,1,3,2]).numpy()
        tensors["rhs_transposed_tensor"] = tf.transpose(tensors["rhs_input_tensor"], [0,1,3,2]).numpy()

        minval = Lib.op_utils.get_dtype_min(params["input_data_type"])
        maxval = Lib.op_utils.get_dtype_max(params["input_data_type"])

        n_output = output_details[0]['shape'][0]
        h_output = output_details[0]['shape'][1]
        w_output = output_details[0]['shape'][2]
        c_output = output_details[0]['shape'][3]

        generated_params["dst_size"] = n_output * h_output * w_output * c_output
        generated_params["output_batch"] = n_output
        generated_params["output_height"] = h_output
        generated_params["output_rows"] = w_output
        generated_params["output_cols"] = c_output
        generated_params["lhs_offset"] = -lhs['quantization_parameters']['zero_points'][0]
        generated_params["rhs_offset"] = -rhs['quantization_parameters']['zero_points'][0]
        generated_params["output_offset"] = output_details[0]['quantization'][1]
        generated_params["activation_min"] = minval
        generated_params["activation_max"] = maxval

        def quantize_scale(scales):
            effective_output_scale = scales["lhs_scale"] * scales["rhs_scale"] / scales["output_scale"]

            significand, shift = math.frexp(effective_output_scale)
            significand_q31 = round(significand * (1 << 31))
            return significand_q31, shift

        mult, shift = quantize_scale(scales)
        generated_params["output_multiplier"] = mult
        generated_params["output_shift"] = shift

        return Lib.op_utils.Generated_data(generated_params, tensors, scales, effective_scales, aliases)