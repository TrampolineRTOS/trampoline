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
import copy
import tensorflow as tf
import math
import numpy as np

from tensorflow.lite.python.interpreter import Interpreter
from tensorflow.lite.python.interpreter import OpResolverType
import tf_keras as keras


class Op_transpose(Lib.op_utils.Op_type):

    def get_shapes(params):
        shapes = {}
        input_shape = copy.deepcopy(params["in_dim"])
        shapes["input_tensor"] = input_shape
        shapes["representational_dataset"] = input_shape

        return shapes

    def generate_keras_model(shapes, params):
        input_shape = shapes["input_tensor"]
        input_lhs = keras.layers.Input(batch_input_shape=input_shape)
        layer = tf.transpose(input_lhs, perm=params["perm"])
        model = keras.Model([input_lhs], [layer])

        return model

    def generate_data_tflite(tflite_fname, params):
        tensors = {}
        effective_scales = {}
        scales = {}
        generated_params = {}
        aliases = {}

        input_shape = params["in_dim"]
        perm = params["perm"]
        perm_size = len(perm)

        generated_params["size"] = math.prod(x for x in input_shape)
        generated_params["perm_size"] = perm_size

        # Derive output dims and fill with zeroes for C unit test file glue
        if perm_size == 2:
            generated_params["out_dim"] = \
                [input_shape[perm[0]], input_shape[perm[1]], 0, 0]
            params["in_dim"].append(0)
            params["in_dim"].append(0)
        elif perm_size == 3:
            generated_params["out_dim"] = \
                [input_shape[perm[0]], input_shape[perm[1]], input_shape[perm[2]], 0]
            params["in_dim"].append(0)
        elif perm_size == 4:
            generated_params["out_dim"] = \
                [input_shape[perm[0]], input_shape[perm[1]], input_shape[perm[2]], input_shape[perm[3]]]
        else:
            raise RuntimeError("Permutation size not supported")

        return Lib.op_utils.Generated_data(generated_params, tensors, scales, effective_scales, aliases)
