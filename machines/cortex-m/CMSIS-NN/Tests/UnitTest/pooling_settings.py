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

import numpy as np
import tensorflow as tf
import keras

class PoolingSettings(TestSettings):

    def __init__(self,
                 dataset,
                 testtype,
                 regenerate_weights,
                 regenerate_input,
                 regenerate_biases,
                 schema_file,
                 channels=8,
                 x_in=4,
                 y_in=4,
                 w_x=4,
                 w_y=4,
                 stride_x=1,
                 stride_y=1,
                 randmin=TestSettings.INT8_MIN,
                 randmax=TestSettings.INT8_MAX,
                 bias_min=TestSettings.INT32_MIN,
                 bias_max=TestSettings.INT32_MAX,
                 batches=1,
                 pad=False,
                 relu6=False,
                 out_activation_min=None,
                 out_activation_max=None,
                 int16xint8=False,
                 interpreter="tensorflow"):
        super().__init__(dataset,
                         testtype,
                         regenerate_weights,
                         regenerate_input,
                         regenerate_biases,
                         schema_file,
                         channels,
                         channels,
                         x_in,
                         y_in,
                         w_x,
                         w_y,
                         stride_x,
                         stride_y,
                         pad,
                         randmin=randmin,
                         randmax=randmax,
                         batches=batches,
                         relu6=relu6,
                         out_activation_min=out_activation_min,
                         out_activation_max=out_activation_max,
                         int16xint8=int16xint8,
                         interpreter=interpreter)

    def generate_data(self, input_data=None) -> None:
        if self.is_int16xint8:
            datatype = "int16_t"
            inttype = tf.int16
        else:
            datatype = "int8_t"
            inttype = tf.int8

        input_data = self.get_randomized_input_data(input_data)
        self.generate_c_array(self.input_data_file_prefix, input_data, datatype=datatype)

        input_data = tf.cast(input_data, tf.float32)

        # Create a one-layer Keras model
        model = keras.models.Sequential()
        input_shape = (self.batches, self.y_input, self.x_input, self.input_ch)
        model.add(keras.layers.InputLayer(input_shape=input_shape[1:], batch_size=self.batches))
        if self.test_type == 'avgpool':
            model.add(
                keras.layers.AveragePooling2D(pool_size=(self.filter_y, self.filter_x),
                                                 strides=(self.stride_y, self.stride_x),
                                                 padding=self.padding.lower(),
                                                 input_shape=input_shape[1:]))
        elif self.test_type == 'maxpool':
            model.add(
                keras.layers.MaxPooling2D(pool_size=(self.filter_y, self.filter_x),
                                             strides=(self.stride_y, self.stride_x),
                                             padding=self.padding.lower(),
                                             input_shape=input_shape[1:]))
        else:
            raise RuntimeError("Wrong test type")

        interpreter = self.convert_and_interpret(model, inttype, input_data)

        output_details = interpreter.get_output_details()

        self.x_output = output_details[0]['shape'][2]
        self.y_output = output_details[0]['shape'][1]

        self.calculate_padding(self.x_output, self.y_output, self.x_input, self.y_input)

        # Generate reference
        interpreter.invoke()
        output_data = interpreter.get_tensor(output_details[0]["index"])
        self.generate_c_array(self.output_data_file_prefix,
                              np.clip(output_data, self.out_activation_min, self.out_activation_max),
                              datatype=datatype)

        self.write_c_config_header()
        self.write_c_header_wrapper()

    def write_c_config_header(self) -> None:
        super().write_c_config_header()

        filename = self.config_data
        filepath = self.headers_dir + filename
        prefix = self.testdataset.upper()

        with open(filepath, "a") as f:
            self.write_common_config(f, prefix)
