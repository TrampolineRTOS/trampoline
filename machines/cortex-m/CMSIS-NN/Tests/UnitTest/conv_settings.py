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
from test_settings import TestSettings

import tensorflow as tf
import numpy as np
import math
import keras


class ConvSettings(TestSettings):

    def __init__(self,
                 dataset,
                 testtype,
                 regenerate_weights,
                 regenerate_input,
                 regenerate_biases,
                 schema_file,
                 in_ch=1,
                 out_ch=1,
                 x_in=7,
                 y_in=7,
                 w_x=3,
                 w_y=3,
                 stride_x=2,
                 stride_y=2,
                 groups=1,
                 pad=True,
                 randmin=TestSettings.INT8_MIN,
                 randmax=TestSettings.INT8_MAX,
                 batches=1,
                 generate_bias=True,
                 relu6=False,
                 out_activation_min=None,
                 out_activation_max=None,
                 int16xint8=False,
                 int16xint8_int32=False,
                 bias_min=TestSettings.INT32_MIN,
                 bias_max=TestSettings.INT32_MAX,
                 dilation_x=1,
                 dilation_y=1,
                 interpreter="tensorflow",
                 int4_weights=False,
                 weights_min=TestSettings.INT32_MIN,
                 weights_max=TestSettings.INT32_MAX):
        super().__init__(dataset,
                         testtype,
                         regenerate_weights,
                         regenerate_input,
                         regenerate_biases,
                         schema_file,
                         in_ch,
                         out_ch,
                         x_in,
                         y_in,
                         w_x,
                         w_y,
                         stride_x,
                         stride_y,
                         pad,
                         randmin,
                         randmax,
                         batches,
                         generate_bias=generate_bias,
                         relu6=relu6,
                         out_activation_min=out_activation_min,
                         out_activation_max=out_activation_max,
                         int16xint8=int16xint8,
                         bias_min=bias_min,
                         bias_max=bias_max,
                         dilation_x=dilation_x,
                         dilation_y=dilation_y,
                         interpreter=interpreter,
                         int4_weights=int4_weights)

        self.scaling_factors = []
        self.groups = groups

        self.weights_min = weights_min
        self.weights_max = weights_max

        if int16xint8_int32:
            if not self.is_int16xint8:
                raise RuntimeError("ERROR: int16x8 with int32 bias only relevant for int16x8")
            if not self.test_type == 'conv':
                raise RuntimeError("ERROR: int16x8 with int32 bias only supported for conv")
        self.int16xint8_int32 = int16xint8_int32

        if self.test_type == 'depthwise_conv':
            self.channel_multiplier = self.output_ch // self.input_ch
            if self.output_ch % self.input_ch != 0:
                raise RuntimeError("out channel ({}) is not multiple of in channel ({})".format(out_ch, in_ch))
            if groups != 1:
                raise RuntimeError("ERROR: Groups cannot be used for depthwise convolution")
        else:
            self.channel_multiplier = 0

        self.filter_ch = in_ch // groups
        if in_ch % groups != 0:
            raise RuntimeError("ERROR: Input channels {} must be an even multiple of groups {}".format(in_ch, groups))
        if out_ch % groups != 0:
            raise RuntimeError("ERROR: Output channels {} must be an even multiple of groups {}".format(out_ch, groups))

        if self.int4_weights:
            if self.test_type == 'conv':
                self.json_template = "TestCases/Common/conv2d_s4_weights_template.json"
            elif self.test_type == 'depthwise_conv':
                self.json_template = "TestCases/Common/dw_s4_weights_template.json"

    def write_c_config_header(self) -> None:
        super().write_c_config_header()

        filename = self.config_data
        filepath = self.headers_dir + filename
        prefix = self.testdataset.upper()

        with open(filepath, "a") as f:
            self.write_common_config(f, prefix)
            if self.test_type == 'depthwise_conv':
                f.write("#define {}_CH_MULT {}\n".format(prefix, self.channel_multiplier))
            f.write("#define {}_INPUT_OFFSET {}\n".format(prefix, -self.input_zero_point))
            f.write("#define {}_OUTPUT_OFFSET {}\n".format(prefix, self.output_zero_point))
            f.write("#define {}_DILATION_X {}\n".format(prefix, self.dilation_x))
            f.write("#define {}_DILATION_Y {}\n".format(prefix, self.dilation_y))
            if self.groups != 1:
                f.write("#define {}_FILTER_CH {}\n".format(prefix, self.filter_ch))
            if self.test_type == 'transpose_conv':
                f.write("#define {}_PAD_X_WITH_OFFSET {}\n".format(prefix, self.pad_x_with_offset))
                f.write("#define {}_PAD_Y_WITH_OFFSET {}\n".format(prefix, self.pad_y_with_offset))

    def generate_quantize_per_channel_multiplier(self):
        num_channels = self.output_ch
        per_channel_multiplier = []
        per_channel_shift = []

        if len(self.scaling_factors) != num_channels:
            raise RuntimeError("Missing scaling factors")

        for i in range(num_channels):
            effective_output_scale = self.input_scale * self.scaling_factors[i] / self.output_scale
            (quantized_multiplier, shift) = self.quantize_scale(effective_output_scale)

            per_channel_multiplier.append(quantized_multiplier)
            per_channel_shift.append(shift)

        return per_channel_multiplier, per_channel_shift

    def generate_int4_scale(self, scale, shift, input_scale):
        self.output_scale = scale
        self.output_zp = shift
        self.input_scale = input_scale
        self.scaling_factors = np.random.uniform(0.001, 0.01, [self.output_ch]).tolist()
        per_channel_multiplier, per_channel_shift = self.generate_quantize_per_channel_multiplier()

        while any((x > 31 or x < -31) for x in per_channel_shift):
            self.output_scale = self.output_scale / 10
            per_channel_multiplier, per_channel_shift = self.generate_quantize_per_channel_multiplier()

        return self.output_scale, self.output_zp

    # TODO
    def quantize_float_data(self, data=None, quantization_bit_range=8, quantization_type="affine", tf_tensor=False):
        if data is not None:
            if tf_tensor:
                data = data.numpy()
            data_max = np.amax(data)
            data_min = np.amin(data)

            if quantization_type.lower() == "affine":
                data_min = min(data_min, 0.0)
                data_max = max(data_max, 0.0)

                scale = (data_max - data_min) / (pow(2, quantization_bit_range) - 1)
                zero_point = -(round(data_max * scale)) - pow(2, quantization_bit_range - 1)
                zero_point = max(zero_point, pow(quantization_bit_range - 1) - 1)
                zero_point = min(zero_point, -pow(quantization_bit_range - 1))

            elif quantization_type.lower() == "symmetric":
                absolute_max = max(abs(data_min), abs(data_max))
                scale = absolute_max / (pow(2, quantization_bit_range - 1) - 1)
                zero_point = 0

            else:
                raise RuntimeError("Quantization scheme not supported")

            scale = 0.1 if scale == 0 else scale
            quantized_data = [(x // scale) + zero_point for x in data]
            return tf.convert_to_tensor(quantized_data), scale, zero_point

    def generate_data(self, input_data=None, weights=None, biases=None) -> None:
        if self.is_int16xint8:
            inttype = tf.int16
            datatype = "int16_t"
            bias_datatype = "int32_t" if self.int16xint8_int32 else "int64_t"
        else:
            inttype = tf.int8
            datatype = "int8_t"
            bias_datatype = "int32_t"

        input_data = self.get_randomized_input_data(input_data)
        biases = self.get_randomized_bias_data(biases)

        if self.test_type == 'conv' or self.test_type == 'transpose_conv':
            out_channel = self.output_ch
        elif self.test_type == 'depthwise_conv':
            out_channel = self.channel_multiplier

        if self.int4_weights:
            w_shape = [self.filter_y * self.filter_x * self.input_ch * out_channel]

            if weights is not None:
                weights = tf.reshape(weights, w_shape)
            else:
                weights = self.get_randomized_data(w_shape,
                                                   self.kernel_table_file,
                                                   minrange=TestSettings.INT4_MIN,
                                                   maxrange=TestSettings.INT4_MAX,
                                                   decimals=1,
                                                   regenerate=self.regenerate_new_weights)

            input_scale = 0.046774
            input_zp = -128

            if w_shape[0] % 2:
                weights = np.append(weights, [0])

            if self.test_type == 'depthwise_conv':
                bias_scale = [64751.269531] * self.output_ch
                bias_zp = [0] * self.output_ch
                if self.generate_bias:
                    output_scale, output_zp = self.generate_int4_scale(4684910.0, -2, input_scale)
                else:
                    output_scale = 0.525255
                    output_zp = 2
            else:
                quant_bias, bias_scale, bias_zp = self.quantize_float_data(
                    biases, quantization_bit_range=8, quantization_type="symmetric", tf_tensor=not self.generate_bias)
                bias_scale = [bias_scale] * self.output_ch
                bias_zp = [bias_zp] * self.output_ch

                output_scale = np.random.uniform(0.02, 0.06)
                output_zp = 0

            scaling_factors = np.random.uniform(0.001, 0.01, [self.output_ch]).tolist()
            w_zp = [0] * self.output_ch

            if self.has_padding:
                # TODO dilation with padding
                output_x = math.ceil(float(self.x_input) / float(self.stride_x))
                output_y = math.ceil(float(self.y_input) / float(self.stride_y))
            else:
                dilation_filter_x = (self.filter_x - 1) * (self.dilation_x - 1)
                dilation_filter_y = (self.filter_y - 1) * (self.dilation_y - 1)

                output_x = math.ceil(float(self.x_input - self.filter_x - dilation_filter_x + 1) / float(self.stride_x))
                output_y = math.ceil(float(self.y_input - self.filter_y - dilation_filter_y + 1) / float(self.stride_y))

            self.json_replacements = {
                "batches": self.batches,
                "input_ch": self.input_ch,
                "output_ch": self.output_ch,
                "input_x": self.x_input,
                "input_y": self.y_input,
                "weight_x": self.filter_x,
                "weight_y": self.filter_y,
                "output_x": output_x,
                "output_y": output_y,
                "input_scale": input_scale,
                "input_zp": input_zp,
                "w_scale": scaling_factors,
                "w_zp": w_zp,
                "bias_scale": bias_scale,
                "bias_zp": bias_zp,
                "output_scale": output_scale,
                "output_zp": output_zp,
                "stride_x": self.stride_x,
                "stride_y": self.stride_y,
                "dilation_x": self.dilation_x,
                "dilation_y": self.dilation_y,
                "type_pad": self.padding,
                "ch_mult": self.channel_multiplier
            }

            # Pack weights
            temp = np.reshape(weights, (len(weights) // 2, 2)).astype(np.uint8)
            temp = 0xff & ((0xf0 & (temp[:, 1] << 4)) | (temp[:, 0] & 0xf))
            weights = tf.convert_to_tensor(temp)

            # Generate tflite model
            if self.test_type == 'depthwise_conv':
                generated_json = self.generate_json_from_template(
                    None, weights, int8_time_weights=True, bias_data=biases, bias_buffer=3)
            else:
                generated_json = self.generate_json_from_template(weights, int8_time_weights=False,
                                                                  bias_data=quant_bias, bias_buffer=2)

            self.flatc_generate_tflite(generated_json, self.schema_file)

            filter_index = 1
            bias_index = 2

        else:
            if self.test_type == 'transpose_conv':
                weight_shape = [self.filter_y, self.filter_x, out_channel, self.input_ch]
            else:
                weight_shape = [self.filter_y, self.filter_x, self.filter_ch, out_channel]

            if weights is not None:
                weights = tf.reshape(weights, weight_shape)
            else:
                weights = self.get_randomized_data(weight_shape,
                                                   self.kernel_table_file,
                                                   minrange=self.weights_min,
                                                   maxrange=self.weights_max,
                                                   decimals=1,
                                                   regenerate=self.regenerate_new_weights)

            # Create a one layer Keras model.
            model = keras.models.Sequential()
            input_shape = (self.batches, self.y_input, self.x_input, self.input_ch)
            model.add(keras.layers.InputLayer(input_shape=input_shape[1:], batch_size=self.batches))
            if self.test_type == 'conv':
                conv_layer = keras.layers.Conv2D(self.output_ch,
                                                 kernel_size=(self.filter_y, self.filter_x),
                                                 strides=(self.stride_y, self.stride_x),
                                                 padding=self.padding,
                                                 input_shape=input_shape[1:],
                                                 dilation_rate=(self.dilation_y, self.dilation_x),
                                                 groups=self.groups,
                                                 use_bias=self.generate_bias)
                model.add(conv_layer)
                if self.generate_bias:
                    conv_layer.set_weights([weights, biases])
                else:
                    conv_layer.set_weights([weights])
            elif self.test_type == 'depthwise_conv':
                depthwise_layer = keras.layers.DepthwiseConv2D(kernel_size=(self.filter_y, self.filter_x),
                                                               strides=(self.stride_y, self.stride_x),
                                                               padding=self.padding,
                                                               depth_multiplier=self.channel_multiplier,
                                                               input_shape=input_shape[1:],
                                                               dilation_rate=(self.dilation_y, self.dilation_x),
                                                               use_bias=self.generate_bias)
                model.add(depthwise_layer)
                if self.generate_bias:
                    depthwise_layer.set_weights([weights, biases])
                else:
                    depthwise_layer.set_weights([weights])
            elif self.test_type == 'transpose_conv':
                transposed_conv_layer = keras.layers.Conv2DTranspose(self.output_ch,
                                                                     kernel_size=(self.filter_y, self.filter_x),
                                                                     strides=(self.stride_y, self.stride_x),
                                                                     padding=self.padding,
                                                                     input_shape=input_shape[1:],
                                                                     dilation_rate=(self.dilation_y,
                                                                                    self.dilation_x),
                                                                     use_bias=self.generate_bias)
                model.add(transposed_conv_layer)
                if self.generate_bias:
                    transposed_conv_layer.set_weights([weights, biases])
                else:
                    transposed_conv_layer.set_weights([weights])

            if self.test_type == 'transpose_conv' and self.generate_bias:
                filter_index = 3
                bias_index = 2
            elif self.is_int16xint8 and self.generate_bias:
                filter_index = 1
                bias_index = 2
            else:
                filter_index = 2
                bias_index = 1

            self.convert_model(model, inttype, int16x8_int32bias=self.int16xint8_int32)

        interpreter = self.interpret_model(input_data, inttype)

        all_layers_details = interpreter.get_tensor_details()
        filter_layer = all_layers_details[filter_index]

        if not self.int4_weights and not self.generate_bias:
            bias_layer = None
            biases = []
        else:
            bias_layer = all_layers_details[bias_index]

        if self.int4_weights:
            expected_weight_size = math.ceil(interpreter.get_tensor(filter_layer['index']).size / 2)
        else:
            expected_weight_size = interpreter.get_tensor(filter_layer['index']).size

        if weights.numpy().size != expected_weight_size or \
                (self.generate_bias and biases.numpy().size != interpreter.get_tensor(bias_layer['index']).size):
            raise RuntimeError(f"Dimension mismatch for {self.testdataset}")

        output_details = interpreter.get_output_details()

        self.x_output = output_details[0]['shape'][2]
        self.y_output = output_details[0]['shape'][1]

        if self.test_type == 'transpose_conv':
            self.calculate_padding(self.x_input, self.y_input, self.x_output, self.y_output)
        else:
            self.calculate_padding(self.x_output, self.y_output, self.x_input, self.y_input)

        self.generate_c_array(self.input_data_file_prefix, input_data, datatype=datatype)
        self.generate_c_array(
            self.weight_data_file_prefix, interpreter.get_tensor(filter_layer['index']), pack=self.int4_weights)

        self.scaling_factors = filter_layer['quantization_parameters']['scales']
        per_channel_multiplier, per_channel_shift = self.generate_quantize_per_channel_multiplier()
        self.generate_c_array("output_mult", per_channel_multiplier, datatype='int32_t')
        self.generate_c_array("output_shift", per_channel_shift, datatype='int32_t')

        if self.generate_bias:
            self.generate_c_array(
                self.bias_data_file_prefix, interpreter.get_tensor(bias_layer['index']), bias_datatype)
        else:
            self.generate_c_array(
                self.bias_data_file_prefix, biases, bias_datatype)

        # Generate reference
        interpreter.invoke()
        output_data = interpreter.get_tensor(output_details[0]["index"])
        self.generate_c_array(self.output_data_file_prefix,
                              np.clip(output_data, self.out_activation_min, self.out_activation_max),
                              datatype=datatype)

        self.write_c_config_header()
        self.write_c_header_wrapper()
