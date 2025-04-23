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
import numpy as np
import tensorflow as tf


class Generated_data():
    """ Container for all generated data"""

    def __init__(self, params, tensors, scales, effective_scales, aliases={}):
        self.params = params  # All other params which are generated rather than given in the test-plan
        self.tensors = tensors  # All tensors
        self.scales = scales  # Scales used in the tflite model
        self.effective_scales = effective_scales  # Scales used by CMSIS-NN
        self.aliases = aliases  # Optional for backward compability with old unit tests


class Op_type():
    """ op_type interface """

    @staticmethod
    def get_shapes(args):
        """ Returns a struct of all shapes used by the operator """
        raise NotImplementedError

    @staticmethod
    def generate_keras_model(output_path, shapes, params):
        """ Returns a non-quantized tflite-model with given shapes and params"""
        raise NotImplementedError

    @staticmethod
    def generate_data_tflite(tflite_path, params) -> Generated_data:
        """
            Parses quantized tensors, scales, and other parameter from the given tflite-file, calculates effective
            scales, and returns them as three structs
        """
        raise NotImplementedError

    @staticmethod
    def generate_data_json(shapes, params) -> Generated_data:
        """
           Generates quantized tensors, scales, and other parameters with given shapes and params, calculates effecitve
           scales, and returns them as four structs
        """
        raise NotImplementedError

    @staticmethod
    def post_model_update(tflite_path, generated_data, params) -> Generated_data:
        """
           Optional function for updating parameters after model has been created.
        """
        return generated_data


def generate_tf_tensor(dims, minval, maxval, decimals=0, datatype=tf.float32):
    array = minval + (maxval - minval) * np.random.rand(*dims)
    array = np.round(array, decimals=decimals)
    tensor = tf.convert_to_tensor(array, dtype=datatype)

    return tensor


def get_dtype(name, params):
    if "bias" in name:
        return params["bias_data_type"]
    elif "weight" in name or "kernel" in name:
        if params["weights_data_type"] == "int4_t":
            return "int8_t"
        return params["weights_data_type"]
    elif "multiplier" in name or "shift" in name:
        return params["shift_and_mult_data_type"]
    elif "input" in name or "output" in name or "transpose" in name:
        return params["input_data_type"]
    else:
        raise Exception(f"Unable to deduce dtype from name '{name}'")


def get_tf_dtype(dtype):
    if dtype == "int8_t":
        return tf.int8
    if dtype == "int16_t":
        return tf.int16
    else:
        raise Exception(f"Unrecognized dtype '{dtype}'")


def get_np_dtype(dtype):
    if dtype == "int8_t" or dtype == "int4_t":
        return np.uint8
    if dtype == "int16_t":
        return np.uint16
    if dtype == "int32_t":
        return np.uint32
    if dtype == "int64_t":
        return np.uint64
    else:
        raise Exception(f"Unrecognized dtype '{dtype}'")


def get_dtype_len(dtype):
    if dtype == "int8_t" or dtype == "int4_t":
        return 1
    elif dtype == "int16_t":
        return 2
    elif dtype == "int32_t" or dtype == "float":
        return 4
    elif dtype == "int64_t" or dtype == "double":
        return 8
    else:
        raise Exception(f"Unrecognized dtype '{dtype}'")


def get_dtype_max(dtype):
    if dtype == "int4_t":
        return 7
    if dtype == "int8_t":
        return 127
    elif dtype == "int16_t":
        return 32767
    elif dtype == "int32_t":
        return 2147483647
    elif dtype == "int64_t":
        return 9223372036854775807
    else:
        raise Exception(f"Unrecognized dtype '{dtype}'")


def get_dtype_min(dtype):
    if dtype == "int4_t":
        return -8
    if dtype == "int8_t":
        return -128
    elif dtype == "int16_t":
        return -32768
    elif dtype == "int32_t":
        return -2147483648
    elif dtype == "int64_t":
        return -9223372036854775808
    else:
        raise Exception(f"Unrecognized dtype '{dtype}'")

def generate_quantize_per_channel_multiplier(params, scales):
    def quantize_scale(scale):
        significand, shift = math.frexp(scale)
        significand_q31 = round(significand * (1 << 31))
        return significand_q31, shift

    num_channels = params["out_ch"]
    per_channel_multiplier = []
    per_channel_shift = []

    if len(scales["scaling_factors"]) != num_channels:
        raise RuntimeError("Missing scaling factors")

    for i in range(num_channels):
        effective_output_scale = scales["input_scale"] * scales["scaling_factors"][i] / scales["output_scale"]
        (quantized_multiplier, shift) = quantize_scale(effective_output_scale)

        per_channel_multiplier.append(quantized_multiplier)
        per_channel_shift.append(shift)

    return per_channel_multiplier, per_channel_shift
