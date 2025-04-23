/*
 * SPDX-FileCopyrightText: Copyright 2010-2024 Arm Limited and/or its affiliates <open-source-office@arm.com>
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <arm_nnfunctions.h>
#include <stdlib.h>
#include <unity.h>

#include "../TestData/kernel1x1/test_data.h"
#include "../TestData/kernel1x1_stride_x/test_data.h"
#include "../TestData/kernel1x1_stride_x_y/test_data.h"
#include "../TestData/kernel1x1_stride_x_y_1/test_data.h"
#include "../TestData/kernel1x1_stride_x_y_2/test_data.h"
#include "../Utils/validate.h"

void kernel1x1_arm_convolve_1x1_s8_fast(void)
{
    const arm_cmsis_nn_status expected = ARM_CMSIS_NN_SUCCESS;
    int8_t output[KERNEL1X1_DST_SIZE] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_conv_params conv_params;
    cmsis_nn_per_channel_quant_params quant_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims bias_dims;
    cmsis_nn_dims output_dims;

    const int32_t *bias_data = kernel1x1_biases;
    const int8_t *input_data = kernel1x1_input;

    input_dims.n = KERNEL1X1_INPUT_BATCHES;
    input_dims.h = KERNEL1X1_INPUT_H;
    input_dims.w = KERNEL1X1_INPUT_W;
    input_dims.c = KERNEL1X1_IN_CH;
    filter_dims.n = KERNEL1X1_OUT_CH;
    filter_dims.h = KERNEL1X1_FILTER_Y;
    filter_dims.w = KERNEL1X1_FILTER_X;
    filter_dims.c = KERNEL1X1_IN_CH;
    output_dims.n = KERNEL1X1_INPUT_BATCHES;
    output_dims.h = KERNEL1X1_OUTPUT_H;
    output_dims.w = KERNEL1X1_OUTPUT_W;
    output_dims.c = KERNEL1X1_OUT_CH;

    conv_params.padding.h = KERNEL1X1_PAD_Y;
    conv_params.padding.w = KERNEL1X1_PAD_X;
    conv_params.stride.h = KERNEL1X1_STRIDE_Y;
    conv_params.stride.w = KERNEL1X1_STRIDE_X;

    bias_dims.n = 1;
    bias_dims.h = 1;
    bias_dims.w = 1;
    bias_dims.c = output_dims.c;

    conv_params.input_offset = KERNEL1X1_INPUT_OFFSET;
    conv_params.output_offset = KERNEL1X1_OUTPUT_OFFSET;
    conv_params.activation.min = KERNEL1X1_OUT_ACTIVATION_MIN;
    conv_params.activation.max = KERNEL1X1_OUT_ACTIVATION_MAX;
    quant_params.multiplier = (int32_t *)kernel1x1_output_mult;
    quant_params.shift = (int32_t *)kernel1x1_output_shift;

    const int32_t buf_size = arm_convolve_1x1_s8_fast_get_buffer_size(&input_dims);
    ctx.buf = malloc(buf_size);
    ctx.size = 0;

    arm_cmsis_nn_status result = arm_convolve_1x1_s8_fast(&ctx,
                                                          &conv_params,
                                                          &quant_params,
                                                          &input_dims,
                                                          input_data,
                                                          &filter_dims,
                                                          kernel1x1_weights,
                                                          &bias_dims,
                                                          bias_data,
                                                          &output_dims,
                                                          output);

    if (ctx.buf)
    {
        // The caller is responsible to clear the scratch buffers for security reasons if applicable.
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(expected, result);
    TEST_ASSERT_TRUE(validate(output, kernel1x1_output_ref, KERNEL1X1_DST_SIZE));
}

void kernel1x1_stride_x_arm_convolve_1x1_s8(void)
{
    const arm_cmsis_nn_status expected = ARM_CMSIS_NN_SUCCESS;
    int8_t output[KERNEL1X1_STRIDE_X_DST_SIZE] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_conv_params conv_params;
    cmsis_nn_per_channel_quant_params quant_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims bias_dims;
    cmsis_nn_dims output_dims;

    const int32_t *bias_data = kernel1x1_stride_x_biases;
    const int8_t *input_data = kernel1x1_stride_x_input;

    input_dims.n = KERNEL1X1_STRIDE_X_INPUT_BATCHES;
    input_dims.h = KERNEL1X1_STRIDE_X_INPUT_H;
    input_dims.w = KERNEL1X1_STRIDE_X_INPUT_W;
    input_dims.c = KERNEL1X1_STRIDE_X_IN_CH;

    filter_dims.n = KERNEL1X1_STRIDE_X_OUT_CH;
    filter_dims.h = KERNEL1X1_STRIDE_X_FILTER_Y;
    filter_dims.w = KERNEL1X1_STRIDE_X_FILTER_X;
    filter_dims.c = KERNEL1X1_STRIDE_X_IN_CH;

    output_dims.n = KERNEL1X1_STRIDE_X_INPUT_BATCHES;
    output_dims.h = KERNEL1X1_STRIDE_X_OUTPUT_H;
    output_dims.w = KERNEL1X1_STRIDE_X_OUTPUT_W;
    output_dims.c = KERNEL1X1_STRIDE_X_OUT_CH;

    bias_dims.n = 1;
    bias_dims.h = 1;
    bias_dims.w = 1;
    bias_dims.c = output_dims.c;

    conv_params.padding.w = KERNEL1X1_STRIDE_X_PAD_X;
    conv_params.padding.h = KERNEL1X1_STRIDE_X_PAD_Y;
    conv_params.stride.w = KERNEL1X1_STRIDE_X_STRIDE_X;
    conv_params.stride.h = KERNEL1X1_STRIDE_X_STRIDE_Y;

    conv_params.input_offset = KERNEL1X1_STRIDE_X_INPUT_OFFSET;
    conv_params.output_offset = KERNEL1X1_STRIDE_X_OUTPUT_OFFSET;
    conv_params.activation.min = KERNEL1X1_STRIDE_X_OUT_ACTIVATION_MIN;
    conv_params.activation.max = KERNEL1X1_STRIDE_X_OUT_ACTIVATION_MAX;
    quant_params.multiplier = (int32_t *)kernel1x1_stride_x_output_mult;
    quant_params.shift = (int32_t *)kernel1x1_stride_x_output_shift;

    const int32_t buf_size = arm_convolve_1x1_s8_fast_get_buffer_size(&input_dims);
    ctx.buf = NULL;
    ctx.size = 0;

    arm_cmsis_nn_status result = arm_convolve_1x1_s8_fast(&ctx,
                                                          &conv_params,
                                                          &quant_params,
                                                          &input_dims,
                                                          input_data,
                                                          &filter_dims,
                                                          kernel1x1_stride_x_weights,
                                                          &bias_dims,
                                                          bias_data,
                                                          &output_dims,
                                                          output);

    if (ctx.buf)
    {
        // The caller is responsible to clear the scratch buffers for security reasons if applicable.
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(ARM_CMSIS_NN_ARG_ERROR, result);

    result = arm_convolve_1x1_s8(&ctx,
                                 &conv_params,
                                 &quant_params,
                                 &input_dims,
                                 input_data,
                                 &filter_dims,
                                 kernel1x1_stride_x_weights,
                                 &bias_dims,
                                 bias_data,
                                 &output_dims,
                                 output);
    TEST_ASSERT_EQUAL(expected, result);

    TEST_ASSERT_TRUE(validate(output, kernel1x1_stride_x_output_ref, KERNEL1X1_STRIDE_X_DST_SIZE));
}

void kernel1x1_stride_x_y_arm_convolve_1x1_s8(void)
{
    const arm_cmsis_nn_status expected = ARM_CMSIS_NN_SUCCESS;
    int8_t output[KERNEL1X1_STRIDE_X_Y_DST_SIZE] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_conv_params conv_params;
    cmsis_nn_per_channel_quant_params quant_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims bias_dims;
    cmsis_nn_dims output_dims;

    const int32_t *bias_data = kernel1x1_stride_x_y_biases;
    const int8_t *input_data = kernel1x1_stride_x_y_input;

    input_dims.n = KERNEL1X1_STRIDE_X_Y_INPUT_BATCHES;
    input_dims.h = KERNEL1X1_STRIDE_X_Y_INPUT_H;
    input_dims.w = KERNEL1X1_STRIDE_X_Y_INPUT_W;
    input_dims.c = KERNEL1X1_STRIDE_X_Y_IN_CH;

    filter_dims.n = KERNEL1X1_STRIDE_X_Y_OUT_CH;
    filter_dims.h = KERNEL1X1_STRIDE_X_Y_FILTER_Y;
    filter_dims.w = KERNEL1X1_STRIDE_X_Y_FILTER_X;
    filter_dims.c = KERNEL1X1_STRIDE_X_Y_IN_CH;

    output_dims.n = KERNEL1X1_STRIDE_X_Y_INPUT_BATCHES;
    output_dims.h = KERNEL1X1_STRIDE_X_Y_OUTPUT_H;
    output_dims.w = KERNEL1X1_STRIDE_X_Y_OUTPUT_W;
    output_dims.c = KERNEL1X1_STRIDE_X_Y_OUT_CH;

    bias_dims.n = 1;
    bias_dims.h = 1;
    bias_dims.w = 1;
    bias_dims.c = output_dims.c;

    conv_params.padding.w = KERNEL1X1_STRIDE_X_Y_PAD_X;
    conv_params.padding.h = KERNEL1X1_STRIDE_X_Y_PAD_Y;
    conv_params.stride.w = KERNEL1X1_STRIDE_X_Y_STRIDE_X;
    conv_params.stride.h = KERNEL1X1_STRIDE_X_Y_STRIDE_Y;

    conv_params.input_offset = KERNEL1X1_STRIDE_X_Y_INPUT_OFFSET;
    conv_params.output_offset = KERNEL1X1_STRIDE_X_Y_OUTPUT_OFFSET;
    conv_params.activation.min = KERNEL1X1_STRIDE_X_Y_OUT_ACTIVATION_MIN;
    conv_params.activation.max = KERNEL1X1_STRIDE_X_Y_OUT_ACTIVATION_MAX;
    quant_params.multiplier = (int32_t *)kernel1x1_stride_x_y_output_mult;
    quant_params.shift = (int32_t *)kernel1x1_stride_x_y_output_shift;

    const int32_t buf_size =
        arm_convolve_wrapper_s8_get_buffer_size(&conv_params, &input_dims, &filter_dims, &output_dims);
    ctx.buf = malloc(buf_size);
    ctx.size = buf_size;

    arm_cmsis_nn_status result = arm_convolve_wrapper_s8(&ctx,
                                                         &conv_params,
                                                         &quant_params,
                                                         &input_dims,
                                                         input_data,
                                                         &filter_dims,
                                                         kernel1x1_stride_x_y_weights,
                                                         &bias_dims,
                                                         bias_data,
                                                         &output_dims,
                                                         output);
    TEST_ASSERT_TRUE(validate(output, kernel1x1_stride_x_y_output_ref, KERNEL1X1_STRIDE_X_Y_DST_SIZE));

    if (ctx.buf)
    {
        // The caller is responsible to clear the scratch buffers for security reasons if applicable.
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
        ctx.size = 0;
    }
    memset(output, 0, sizeof(output));

    result = arm_convolve_1x1_s8(&ctx,
                                 &conv_params,
                                 &quant_params,
                                 &input_dims,
                                 input_data,
                                 &filter_dims,
                                 kernel1x1_stride_x_y_weights,
                                 &bias_dims,
                                 bias_data,
                                 &output_dims,
                                 output);
    TEST_ASSERT_EQUAL(expected, result);

    TEST_ASSERT_TRUE(validate(output, kernel1x1_stride_x_y_output_ref, KERNEL1X1_STRIDE_X_Y_DST_SIZE));
}

void kernel1x1_stride_x_y_1_arm_convolve_1x1_s8(void)
{
    const arm_cmsis_nn_status expected = ARM_CMSIS_NN_SUCCESS;
    int8_t output[KERNEL1X1_STRIDE_X_Y_1_DST_SIZE] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_conv_params conv_params;
    cmsis_nn_per_channel_quant_params quant_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims bias_dims;
    cmsis_nn_dims output_dims;

    const int32_t *bias_data = kernel1x1_stride_x_y_1_biases;
    const int8_t *input_data = kernel1x1_stride_x_y_1_input;

    input_dims.n = KERNEL1X1_STRIDE_X_Y_1_INPUT_BATCHES;
    input_dims.h = KERNEL1X1_STRIDE_X_Y_1_INPUT_H;
    input_dims.w = KERNEL1X1_STRIDE_X_Y_1_INPUT_W;
    input_dims.c = KERNEL1X1_STRIDE_X_Y_1_IN_CH;

    filter_dims.n = KERNEL1X1_STRIDE_X_Y_1_OUT_CH;
    filter_dims.h = KERNEL1X1_STRIDE_X_Y_1_FILTER_Y;
    filter_dims.w = KERNEL1X1_STRIDE_X_Y_1_FILTER_X;
    filter_dims.c = KERNEL1X1_STRIDE_X_Y_1_IN_CH;

    output_dims.n = KERNEL1X1_STRIDE_X_Y_1_INPUT_BATCHES;
    output_dims.h = KERNEL1X1_STRIDE_X_Y_1_OUTPUT_H;
    output_dims.w = KERNEL1X1_STRIDE_X_Y_1_OUTPUT_W;
    output_dims.c = KERNEL1X1_STRIDE_X_Y_1_OUT_CH;

    bias_dims.n = 1;
    bias_dims.h = 1;
    bias_dims.w = 1;
    bias_dims.c = output_dims.c;

    conv_params.padding.w = KERNEL1X1_STRIDE_X_Y_1_PAD_X;
    conv_params.padding.h = KERNEL1X1_STRIDE_X_Y_1_PAD_Y;
    conv_params.stride.w = KERNEL1X1_STRIDE_X_Y_1_STRIDE_X;
    conv_params.stride.h = KERNEL1X1_STRIDE_X_Y_1_STRIDE_Y;

    conv_params.input_offset = KERNEL1X1_STRIDE_X_Y_1_INPUT_OFFSET;
    conv_params.output_offset = KERNEL1X1_STRIDE_X_Y_1_OUTPUT_OFFSET;
    conv_params.activation.min = KERNEL1X1_STRIDE_X_Y_1_OUT_ACTIVATION_MIN;
    conv_params.activation.max = KERNEL1X1_STRIDE_X_Y_1_OUT_ACTIVATION_MAX;
    quant_params.multiplier = (int32_t *)kernel1x1_stride_x_y_1_output_mult;
    quant_params.shift = (int32_t *)kernel1x1_stride_x_y_1_output_shift;

    ctx.size = 0;
    ctx.buf = NULL;

    arm_cmsis_nn_status result = arm_convolve_1x1_s8(&ctx,
                                                     &conv_params,
                                                     &quant_params,
                                                     &input_dims,
                                                     input_data,
                                                     &filter_dims,
                                                     kernel1x1_stride_x_y_1_weights,
                                                     &bias_dims,
                                                     bias_data,
                                                     &output_dims,
                                                     output);
    TEST_ASSERT_EQUAL(expected, result);

    TEST_ASSERT_TRUE(validate(output, kernel1x1_stride_x_y_1_output_ref, KERNEL1X1_STRIDE_X_Y_1_DST_SIZE));
}

void kernel1x1_stride_x_y_2_arm_convolve_1x1_s8(void)
{
    const arm_cmsis_nn_status expected = ARM_CMSIS_NN_SUCCESS;
    int8_t output[KERNEL1X1_STRIDE_X_Y_2_DST_SIZE] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_conv_params conv_params;
    cmsis_nn_per_channel_quant_params quant_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims bias_dims;
    cmsis_nn_dims output_dims;

    const int32_t *bias_data = kernel1x1_stride_x_y_2_biases;
    const int8_t *input_data = kernel1x1_stride_x_y_2_input;

    input_dims.n = KERNEL1X1_STRIDE_X_Y_2_INPUT_BATCHES;
    input_dims.h = KERNEL1X1_STRIDE_X_Y_2_INPUT_H;
    input_dims.w = KERNEL1X1_STRIDE_X_Y_2_INPUT_W;
    input_dims.c = KERNEL1X1_STRIDE_X_Y_2_IN_CH;

    filter_dims.n = KERNEL1X1_STRIDE_X_Y_2_OUT_CH;
    filter_dims.h = KERNEL1X1_STRIDE_X_Y_2_FILTER_Y;
    filter_dims.w = KERNEL1X1_STRIDE_X_Y_2_FILTER_X;
    filter_dims.c = KERNEL1X1_STRIDE_X_Y_2_IN_CH;

    output_dims.n = KERNEL1X1_STRIDE_X_Y_2_INPUT_BATCHES;
    output_dims.h = KERNEL1X1_STRIDE_X_Y_2_OUTPUT_H;
    output_dims.w = KERNEL1X1_STRIDE_X_Y_2_OUTPUT_W;
    output_dims.c = KERNEL1X1_STRIDE_X_Y_2_OUT_CH;

    bias_dims.n = 1;
    bias_dims.h = 1;
    bias_dims.w = 1;
    bias_dims.c = output_dims.c;

    conv_params.padding.w = KERNEL1X1_STRIDE_X_Y_2_PAD_X;
    conv_params.padding.h = KERNEL1X1_STRIDE_X_Y_2_PAD_Y;
    conv_params.stride.w = KERNEL1X1_STRIDE_X_Y_2_STRIDE_X;
    conv_params.stride.h = KERNEL1X1_STRIDE_X_Y_2_STRIDE_Y;

    conv_params.input_offset = KERNEL1X1_STRIDE_X_Y_2_INPUT_OFFSET;
    conv_params.output_offset = KERNEL1X1_STRIDE_X_Y_2_OUTPUT_OFFSET;
    conv_params.activation.min = KERNEL1X1_STRIDE_X_Y_2_OUT_ACTIVATION_MIN;
    conv_params.activation.max = KERNEL1X1_STRIDE_X_Y_2_OUT_ACTIVATION_MAX;
    quant_params.multiplier = (int32_t *)kernel1x1_stride_x_y_2_output_mult;
    quant_params.shift = (int32_t *)kernel1x1_stride_x_y_2_output_shift;

    ctx.size = 0;
    ctx.buf = NULL;

    arm_cmsis_nn_status result = arm_convolve_1x1_s8(&ctx,
                                                     &conv_params,
                                                     &quant_params,
                                                     &input_dims,
                                                     input_data,
                                                     &filter_dims,
                                                     kernel1x1_stride_x_y_2_weights,
                                                     &bias_dims,
                                                     bias_data,
                                                     &output_dims,
                                                     output);
    TEST_ASSERT_EQUAL(expected, result);

    TEST_ASSERT_TRUE(validate(output, kernel1x1_stride_x_y_2_output_ref, KERNEL1X1_STRIDE_X_Y_2_DST_SIZE));
}

void buffer_size_arm_convolve_1x1_s8_fast(void)
{
    cmsis_nn_conv_params conv_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims output_dims;

    input_dims.n = KERNEL1X1_INPUT_BATCHES;
    input_dims.w = KERNEL1X1_INPUT_W;
    input_dims.h = KERNEL1X1_INPUT_H;
    input_dims.c = KERNEL1X1_IN_CH;
    filter_dims.w = KERNEL1X1_FILTER_X;
    filter_dims.h = KERNEL1X1_FILTER_Y;
    output_dims.w = KERNEL1X1_OUTPUT_W;
    output_dims.h = KERNEL1X1_OUTPUT_H;
    output_dims.c = KERNEL1X1_OUT_CH;

    conv_params.padding.w = KERNEL1X1_PAD_X;
    conv_params.padding.h = KERNEL1X1_PAD_Y;
    conv_params.stride.w = KERNEL1X1_STRIDE_X;
    conv_params.stride.h = KERNEL1X1_STRIDE_Y;
    conv_params.dilation.w = KERNEL1X1_DILATION_X;
    conv_params.dilation.h = KERNEL1X1_DILATION_Y;

    conv_params.input_offset = KERNEL1X1_INPUT_OFFSET;
    conv_params.output_offset = KERNEL1X1_OUTPUT_OFFSET;
    conv_params.activation.min = KERNEL1X1_OUT_ACTIVATION_MIN;
    conv_params.activation.max = KERNEL1X1_OUT_ACTIVATION_MAX;

    TEST_ASSERT_EQUAL(conv_params.stride.w, 1);
    TEST_ASSERT_EQUAL(conv_params.stride.h, 1);

    const int32_t buf_size = arm_convolve_1x1_s8_fast_get_buffer_size(&input_dims);
    const int32_t wrapper_buf_size =
        arm_convolve_wrapper_s8_get_buffer_size(&conv_params, &input_dims, &filter_dims, &output_dims);

    TEST_ASSERT_EQUAL(wrapper_buf_size, buf_size);
}

void buffer_size_mve_arm_convolve_1x1_s8_fast(void)
{
#if defined(ARM_MATH_MVEI)
    cmsis_nn_conv_params conv_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims output_dims;

    input_dims.n = KERNEL1X1_STRIDE_X_Y_2_INPUT_BATCHES;
    input_dims.w = KERNEL1X1_STRIDE_X_Y_2_INPUT_W;
    input_dims.h = KERNEL1X1_STRIDE_X_Y_2_INPUT_H;
    input_dims.c = KERNEL1X1_STRIDE_X_Y_2_IN_CH;
    filter_dims.w = KERNEL1X1_STRIDE_X_Y_2_FILTER_X;
    filter_dims.h = KERNEL1X1_STRIDE_X_Y_2_FILTER_Y;
    output_dims.w = KERNEL1X1_STRIDE_X_Y_2_OUTPUT_W;
    output_dims.h = KERNEL1X1_STRIDE_X_Y_2_OUTPUT_H;
    output_dims.c = KERNEL1X1_STRIDE_X_Y_2_OUT_CH;

    conv_params.padding.w = KERNEL1X1_STRIDE_X_Y_2_PAD_X;
    conv_params.padding.h = KERNEL1X1_STRIDE_X_Y_2_PAD_Y;
    conv_params.stride.w = KERNEL1X1_STRIDE_X_Y_2_STRIDE_X;
    conv_params.stride.h = KERNEL1X1_STRIDE_X_Y_2_STRIDE_Y;
    conv_params.dilation.w = KERNEL1X1_STRIDE_X_Y_2_DILATION_X;
    conv_params.dilation.h = KERNEL1X1_STRIDE_X_Y_2_DILATION_Y;

    conv_params.input_offset = KERNEL1X1_STRIDE_X_Y_2_INPUT_OFFSET;
    conv_params.output_offset = KERNEL1X1_STRIDE_X_Y_2_OUTPUT_OFFSET;
    conv_params.activation.min = KERNEL1X1_STRIDE_X_Y_2_OUT_ACTIVATION_MIN;
    conv_params.activation.max = KERNEL1X1_STRIDE_X_Y_2_OUT_ACTIVATION_MAX;

    const int32_t wrapper_buf_size =
        arm_convolve_wrapper_s8_get_buffer_size(&conv_params, &input_dims, &filter_dims, &output_dims);
    const int32_t mve_wrapper_buf_size =
        arm_convolve_wrapper_s8_get_buffer_size_mve(&conv_params, &input_dims, &filter_dims, &output_dims);

    TEST_ASSERT_EQUAL(wrapper_buf_size, mve_wrapper_buf_size);
#endif
}

void buffer_size_dsp_arm_convolve_1x1_s8_fast(void)
{
#if defined(ARM_MATH_DSP) && !defined(ARM_MATH_MVEI)
    cmsis_nn_conv_params conv_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims output_dims;

    input_dims.n = KERNEL1X1_STRIDE_X_Y_2_INPUT_BATCHES;
    input_dims.w = KERNEL1X1_STRIDE_X_Y_2_INPUT_W;
    input_dims.h = KERNEL1X1_STRIDE_X_Y_2_INPUT_H;
    input_dims.c = KERNEL1X1_STRIDE_X_Y_2_IN_CH;
    filter_dims.w = KERNEL1X1_STRIDE_X_Y_2_FILTER_X;
    filter_dims.h = KERNEL1X1_STRIDE_X_Y_2_FILTER_Y;
    output_dims.w = KERNEL1X1_STRIDE_X_Y_2_OUTPUT_W;
    output_dims.h = KERNEL1X1_STRIDE_X_Y_2_OUTPUT_H;
    output_dims.c = KERNEL1X1_STRIDE_X_Y_2_OUT_CH;

    conv_params.padding.w = KERNEL1X1_STRIDE_X_Y_2_PAD_X;
    conv_params.padding.h = KERNEL1X1_STRIDE_X_Y_2_PAD_Y;
    conv_params.stride.w = KERNEL1X1_STRIDE_X_Y_2_STRIDE_X;
    conv_params.stride.h = KERNEL1X1_STRIDE_X_Y_2_STRIDE_Y;
    conv_params.dilation.w = KERNEL1X1_STRIDE_X_Y_2_DILATION_X;
    conv_params.dilation.h = KERNEL1X1_STRIDE_X_Y_2_DILATION_Y;

    conv_params.input_offset = KERNEL1X1_STRIDE_X_Y_2_INPUT_OFFSET;
    conv_params.output_offset = KERNEL1X1_STRIDE_X_Y_2_OUTPUT_OFFSET;
    conv_params.activation.min = KERNEL1X1_STRIDE_X_Y_2_OUT_ACTIVATION_MIN;
    conv_params.activation.max = KERNEL1X1_STRIDE_X_Y_2_OUT_ACTIVATION_MAX;

    const int32_t wrapper_buf_size =
        arm_convolve_wrapper_s8_get_buffer_size(&conv_params, &input_dims, &filter_dims, &output_dims);
    const int32_t dsp_wrapper_buf_size =
        arm_convolve_wrapper_s8_get_buffer_size_dsp(&conv_params, &input_dims, &filter_dims, &output_dims);

    TEST_ASSERT_EQUAL(wrapper_buf_size, dsp_wrapper_buf_size);
#endif
}
