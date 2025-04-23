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

class Op_pad(Lib.op_utils.Op_type):

    def get_shapes(params):
        shapes = {}
        shapes["input_tensor"] = (params["input_n"], params["input_h"], params["input_w"], params["input_c"])
        shapes["representational_dataset"] = shapes["input_tensor"]

        return shapes

    def generate_keras_model(shapes, params):

        model = keras.models.Sequential()
        model.add(keras.layers.InputLayer(input_shape=shapes["input_tensor"][1:]))

        if (params["pre_pad_n"] == params["post_pad_n"] == params["pre_pad_h"] == params["post_pad_h"] == 0):
            model.add(keras.layers.ZeroPadding2D(padding=((params["pre_pad_w"], params["post_pad_w"]), (params["pre_pad_c"], params["post_pad_c"])), data_format="channels_first"))
        elif (params["pre_pad_n"] == params["post_pad_n"] == params["pre_pad_c"] == params["post_pad_c"] == 0):
            model.add(keras.layers.ZeroPadding2D(padding=((params["pre_pad_h"], params["post_pad_h"]), (params["pre_pad_w"], params["post_pad_w"])), data_format="channels_last"))
        else:
            raise ValueError(f"Keras can only generate padding for (h,w) or (w,c), the others must be zero.")

        return model

    def generate_data_tflite(tflite_fname, params):
        tensors = {}
        effective_scales = {}
        scales = {}
        generated_params = {}

        generated_params["pad_value"] = -128

        interpreter = Interpreter(str(tflite_fname), experimental_op_resolver_type=OpResolverType.BUILTIN_REF)
        interpreter.allocate_tensors()

        output_details = interpreter.get_output_details()
        output_n = output_details[0]['shape'][3]
        output_h = output_details[0]['shape'][2]
        output_w = output_details[0]['shape'][1]
        output_c = output_details[0]['shape'][0]

        generated_params["output_size"] = output_n * output_h * output_w * output_c;

        return Lib.op_utils.Generated_data(generated_params, tensors, scales, effective_scales)

