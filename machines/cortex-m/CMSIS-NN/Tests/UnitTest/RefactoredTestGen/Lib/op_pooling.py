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

class Op_pooling(Lib.op_utils.Op_type):

    def get_shapes(params):
        shapes = {}
        shapes["input_tensor"] = (params["batch_size"], params["input_h"], params["input_w"], params["input_c"])
        shapes["representational_dataset"] = shapes["input_tensor"]

        return shapes

    def generate_keras_model(shapes, params):
        model = keras.models.Sequential()
        model.add(keras.layers.InputLayer(input_shape=shapes["input_tensor"][1:], batch_size=shapes["input_tensor"][0]))
        if params["op_type"] == 'avgpool':
            model.add(
                keras.layers.AveragePooling2D(pool_size=(params["filter_h"], params["filter_w"]),
                                             strides=(params["stride_h"], params["stride_w"]),
                                             padding=params["pad"],
                                             input_shape=shapes["input_tensor"][1:]))
        elif params["op_type"] == 'maxpool':
            model.add(
                keras.layers.MaxPooling2D(pool_size=(params["filter_h"], params["filter_w"]),
                                             strides=(params["stride_h"], params["stride_w"]),
                                             padding=params["pad"],
                                             input_shape=shapes["input_tensor"][1:]))
        else:
            raise RuntimeError("Wrong test type")


        return model

    def generate_data_tflite(tflite_fname, params):
        tensors = {}
        effective_scales = {}
        scales = {}
        generated_params = {}

        interpreter = Interpreter(str(tflite_fname), experimental_op_resolver_type=OpResolverType.BUILTIN_REF)
        interpreter.allocate_tensors()
        output_details = interpreter.get_output_details()

        generated_params["output_c"] = output_details[0]['shape'][3]
        generated_params["output_w"] = output_details[0]['shape'][2]
        generated_params["output_h"] = output_details[0]['shape'][1]

        if params["pad"] == "SAME":
            pad_along_width = max((generated_params["output_w"] - 1) * params["stride_w"] + params["filter_w"] - params["input_w"], 0)
            pad_along_height = max((generated_params["output_h"] - 1) * params["stride_h"] + params["filter_h"] - params["input_h"], 0)

            generated_params["padding_h"] = pad_along_height // 2
            generated_params["padding_w"] = pad_along_width // 2
        else:
            generated_params["padding_h"] = 0
            generated_params["padding_w"] = 0

        return Lib.op_utils.Generated_data(generated_params, tensors, scales, effective_scales)
