/*
 * SPDX-FileCopyrightText: Copyright 2023-2024 Arm Limited and/or its affiliates <open-source-office@arm.com>
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

#include <stdlib.h>

#include <arm_nnfunctions.h>
#include <unity.h>

#include "../TestData/basic_2_int4/test_data.h"
#include "../TestData/basic_int4/test_data.h"
#include "../TestData/conv_1_x_n_1_int4/test_data.h"
#include "../TestData/conv_1_x_n_2_int4/test_data.h"
#include "../TestData/conv_1_x_n_3_int4/test_data.h"
#include "../TestData/conv_1_x_n_4_int4/test_data.h"
#include "../TestData/conv_1_x_n_5_int4/test_data.h"
#include "../TestData/conv_2_int4/test_data.h"
#include "../TestData/conv_2x2_dilation_5x5_input_int4/test_data.h"
#include "../TestData/conv_2x2_dilation_int4/test_data.h"
#include "../TestData/conv_2x3_dilation_int4/test_data.h"
#include "../TestData/conv_3_int4/test_data.h"
#include "../TestData/conv_3x2_dilation_int4/test_data.h"
#include "../TestData/conv_3x3_dilation_5x5_input_int4/test_data.h"
#include "../TestData/conv_4_int4/test_data.h"
#include "../TestData/conv_5_int4/test_data.h"
#include "../TestData/conv_dilation_golden_int4/test_data.h"
#include "../TestData/conv_out_activation_int4/test_data.h"
#include "../TestData/stride2pad1_int4/test_data.h"
#include "../Utils/validate.h"

void basic_arm_convolve_s4(void)
{
    const arm_cmsis_nn_status expected = ARM_CMSIS_NN_SUCCESS;
    int8_t output[BASIC_INT4_DST_SIZE] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_conv_params conv_params;
    cmsis_nn_per_channel_quant_params quant_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims bias_dims;
    cmsis_nn_dims output_dims;

    const int32_t *bias_data = basic_int4_biases;
    const int8_t *kernel_data = basic_int4_weights;
    const int8_t *input_data = basic_int4_input;
    const int8_t *output_ref = basic_int4_output_ref;
    const int32_t output_ref_size = BASIC_INT4_DST_SIZE;

    input_dims.n = BASIC_INT4_INPUT_BATCHES;
    input_dims.w = BASIC_INT4_INPUT_W;
    input_dims.h = BASIC_INT4_INPUT_H;
    input_dims.c = BASIC_INT4_IN_CH;
    filter_dims.w = BASIC_INT4_FILTER_X;
    filter_dims.h = BASIC_INT4_FILTER_Y;
    output_dims.w = BASIC_INT4_OUTPUT_W;
    output_dims.h = BASIC_INT4_OUTPUT_H;
    output_dims.c = BASIC_INT4_OUT_CH;

    conv_params.padding.w = BASIC_INT4_PAD_X;
    conv_params.padding.h = BASIC_INT4_PAD_Y;
    conv_params.stride.w = BASIC_INT4_STRIDE_X;
    conv_params.stride.h = BASIC_INT4_STRIDE_Y;
    conv_params.dilation.w = BASIC_INT4_DILATION_X;
    conv_params.dilation.h = BASIC_INT4_DILATION_Y;

    conv_params.input_offset = BASIC_INT4_INPUT_OFFSET;
    conv_params.output_offset = BASIC_INT4_OUTPUT_OFFSET;
    conv_params.activation.min = BASIC_INT4_OUT_ACTIVATION_MIN;
    conv_params.activation.max = BASIC_INT4_OUT_ACTIVATION_MAX;
    quant_params.multiplier = (int32_t *)basic_int4_output_mult;
    quant_params.shift = (int32_t *)basic_int4_output_shift;

    int32_t buf_size = arm_convolve_s4_get_buffer_size(&input_dims, &filter_dims);
    ctx.buf = malloc(buf_size);
    ctx.size = 0;

    arm_cmsis_nn_status result = arm_convolve_s4(&ctx,
                                                 &conv_params,
                                                 &quant_params,
                                                 &input_dims,
                                                 input_data,
                                                 &filter_dims,
                                                 kernel_data,
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
    TEST_ASSERT_TRUE(validate(output, output_ref, output_ref_size));
    memset(output, 0, sizeof(output));

    buf_size = arm_convolve_wrapper_s4_get_buffer_size(&conv_params, &input_dims, &filter_dims, &output_dims);
    ctx.buf = malloc(buf_size);
    ctx.size = 0;

    result = arm_convolve_wrapper_s4(&ctx,
                                     &conv_params,
                                     &quant_params,
                                     &input_dims,
                                     input_data,
                                     &filter_dims,
                                     kernel_data,
                                     &bias_dims,
                                     bias_data,
                                     &output_dims,
                                     output);

    if (ctx.buf)
    {
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(expected, result);
    TEST_ASSERT_TRUE(validate(output, output_ref, output_ref_size));
}

void basic_2_arm_convolve_s4(void)
{
    const arm_cmsis_nn_status expected = ARM_CMSIS_NN_SUCCESS;
    int8_t output[BASIC_2_INT4_DST_SIZE] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_conv_params conv_params;
    cmsis_nn_per_channel_quant_params quant_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims bias_dims;
    cmsis_nn_dims output_dims;

    const int32_t *bias_data = basic_2_int4_biases;
    const int8_t *kernel_data = basic_2_int4_weights;
    const int8_t *input_data = basic_2_int4_input;
    const int8_t *output_ref = basic_2_int4_output_ref;
    const int32_t output_ref_size = BASIC_2_INT4_DST_SIZE;

    input_dims.n = BASIC_2_INT4_INPUT_BATCHES;
    input_dims.w = BASIC_2_INT4_INPUT_W;
    input_dims.h = BASIC_2_INT4_INPUT_H;
    input_dims.c = BASIC_2_INT4_IN_CH;
    filter_dims.w = BASIC_2_INT4_FILTER_X;
    filter_dims.h = BASIC_2_INT4_FILTER_Y;
    output_dims.w = BASIC_2_INT4_OUTPUT_W;
    output_dims.h = BASIC_2_INT4_OUTPUT_H;
    output_dims.c = BASIC_2_INT4_OUT_CH;

    conv_params.padding.w = BASIC_2_INT4_PAD_X;
    conv_params.padding.h = BASIC_2_INT4_PAD_Y;
    conv_params.stride.w = BASIC_2_INT4_STRIDE_X;
    conv_params.stride.h = BASIC_2_INT4_STRIDE_Y;
    conv_params.dilation.w = BASIC_2_INT4_DILATION_X;
    conv_params.dilation.h = BASIC_2_INT4_DILATION_Y;

    conv_params.input_offset = BASIC_2_INT4_INPUT_OFFSET;
    conv_params.output_offset = BASIC_2_INT4_OUTPUT_OFFSET;
    conv_params.activation.min = BASIC_2_INT4_OUT_ACTIVATION_MIN;
    conv_params.activation.max = BASIC_2_INT4_OUT_ACTIVATION_MAX;
    quant_params.multiplier = (int32_t *)basic_2_int4_output_mult;
    quant_params.shift = (int32_t *)basic_2_int4_output_shift;

    int32_t buf_size = arm_convolve_s4_get_buffer_size(&input_dims, &filter_dims);
    ctx.buf = malloc(buf_size);
    ctx.size = 0;

    arm_cmsis_nn_status result = arm_convolve_s4(&ctx,
                                                 &conv_params,
                                                 &quant_params,
                                                 &input_dims,
                                                 input_data,
                                                 &filter_dims,
                                                 kernel_data,
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
    TEST_ASSERT_TRUE(validate(output, output_ref, output_ref_size));
    memset(output, 0, sizeof(output));

    buf_size = arm_convolve_wrapper_s4_get_buffer_size(&conv_params, &input_dims, &filter_dims, &output_dims);
    ctx.buf = malloc(buf_size);
    ctx.size = 0;

    result = arm_convolve_wrapper_s4(&ctx,
                                     &conv_params,
                                     &quant_params,
                                     &input_dims,
                                     input_data,
                                     &filter_dims,
                                     kernel_data,
                                     &bias_dims,
                                     bias_data,
                                     &output_dims,
                                     output);

    if (ctx.buf)
    {
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(expected, result);
    TEST_ASSERT_TRUE(validate(output, output_ref, output_ref_size));
}

void stride2pad1_arm_convolve_s4(void)
{
    const arm_cmsis_nn_status expected = ARM_CMSIS_NN_SUCCESS;
    int8_t output[STRIDE2PAD1_INT4_DST_SIZE] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_conv_params conv_params;
    cmsis_nn_per_channel_quant_params quant_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims bias_dims;
    cmsis_nn_dims output_dims;

    const int32_t *bias_data = stride2pad1_int4_biases;
    const int8_t *kernel_data = stride2pad1_int4_weights;
    const int8_t *input_data = stride2pad1_int4_input;
    const int8_t *output_ref = stride2pad1_int4_output_ref;
    const int32_t output_ref_size = STRIDE2PAD1_INT4_DST_SIZE;

    input_dims.n = STRIDE2PAD1_INT4_INPUT_BATCHES;
    input_dims.w = STRIDE2PAD1_INT4_INPUT_W;
    input_dims.h = STRIDE2PAD1_INT4_INPUT_H;
    input_dims.c = STRIDE2PAD1_INT4_IN_CH;
    filter_dims.w = STRIDE2PAD1_INT4_FILTER_X;
    filter_dims.h = STRIDE2PAD1_INT4_FILTER_Y;
    output_dims.w = STRIDE2PAD1_INT4_OUTPUT_W;
    output_dims.h = STRIDE2PAD1_INT4_OUTPUT_H;
    output_dims.c = STRIDE2PAD1_INT4_OUT_CH;

    conv_params.padding.w = STRIDE2PAD1_INT4_PAD_X;
    conv_params.padding.h = STRIDE2PAD1_INT4_PAD_Y;
    conv_params.stride.w = STRIDE2PAD1_INT4_STRIDE_X;
    conv_params.stride.h = STRIDE2PAD1_INT4_STRIDE_Y;
    conv_params.dilation.w = STRIDE2PAD1_INT4_DILATION_X;
    conv_params.dilation.h = STRIDE2PAD1_INT4_DILATION_Y;

    conv_params.input_offset = STRIDE2PAD1_INT4_INPUT_OFFSET;
    conv_params.output_offset = STRIDE2PAD1_INT4_OUTPUT_OFFSET;
    conv_params.activation.min = STRIDE2PAD1_INT4_OUT_ACTIVATION_MIN;
    conv_params.activation.max = STRIDE2PAD1_INT4_OUT_ACTIVATION_MAX;
    quant_params.multiplier = (int32_t *)stride2pad1_int4_output_mult;
    quant_params.shift = (int32_t *)stride2pad1_int4_output_shift;

    int32_t buf_size = arm_convolve_s4_get_buffer_size(&input_dims, &filter_dims);
    ctx.buf = malloc(buf_size);
    ctx.size = 0;

    arm_cmsis_nn_status result = arm_convolve_s4(&ctx,
                                                 &conv_params,
                                                 &quant_params,
                                                 &input_dims,
                                                 input_data,
                                                 &filter_dims,
                                                 kernel_data,
                                                 &bias_dims,
                                                 bias_data,
                                                 &output_dims,
                                                 output);

    if (ctx.buf)
    {
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(expected, result);
    TEST_ASSERT_TRUE(validate(output, output_ref, output_ref_size));
    memset(output, 0, sizeof(output));

    buf_size = arm_convolve_wrapper_s4_get_buffer_size(&conv_params, &input_dims, &filter_dims, &output_dims);
    ctx.buf = malloc(buf_size);
    ctx.size = 0;

    result = arm_convolve_wrapper_s4(&ctx,
                                     &conv_params,
                                     &quant_params,
                                     &input_dims,
                                     input_data,
                                     &filter_dims,
                                     kernel_data,
                                     &bias_dims,
                                     bias_data,
                                     &output_dims,
                                     output);

    if (ctx.buf)
    {
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(expected, result);
    TEST_ASSERT_TRUE(validate(output, output_ref, output_ref_size));
}

void conv_2_arm_convolve_s4(void)
{
    const arm_cmsis_nn_status expected = ARM_CMSIS_NN_SUCCESS;
    int8_t output[CONV_2_INT4_DST_SIZE] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_conv_params conv_params;
    cmsis_nn_per_channel_quant_params quant_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims bias_dims;
    cmsis_nn_dims output_dims;

    const int32_t *bias_data = conv_2_int4_biases;
    const int8_t *kernel_data = conv_2_int4_weights;
    const int8_t *input_data = conv_2_int4_input;
    const int8_t *output_ref = conv_2_int4_output_ref;
    const int32_t output_ref_size = CONV_2_INT4_DST_SIZE;

    input_dims.n = CONV_2_INT4_INPUT_BATCHES;
    input_dims.w = CONV_2_INT4_INPUT_W;
    input_dims.h = CONV_2_INT4_INPUT_H;
    input_dims.c = CONV_2_INT4_IN_CH;
    filter_dims.w = CONV_2_INT4_FILTER_X;
    filter_dims.h = CONV_2_INT4_FILTER_Y;
    output_dims.w = CONV_2_INT4_OUTPUT_W;
    output_dims.h = CONV_2_INT4_OUTPUT_H;
    output_dims.c = CONV_2_INT4_OUT_CH;

    conv_params.padding.w = CONV_2_INT4_PAD_X;
    conv_params.padding.h = CONV_2_INT4_PAD_Y;
    conv_params.stride.w = CONV_2_INT4_STRIDE_X;
    conv_params.stride.h = CONV_2_INT4_STRIDE_Y;
    conv_params.dilation.w = CONV_2_INT4_DILATION_X;
    conv_params.dilation.h = CONV_2_INT4_DILATION_Y;

    conv_params.input_offset = CONV_2_INT4_INPUT_OFFSET;
    conv_params.output_offset = CONV_2_INT4_OUTPUT_OFFSET;
    conv_params.activation.min = CONV_2_INT4_OUT_ACTIVATION_MIN;
    conv_params.activation.max = CONV_2_INT4_OUT_ACTIVATION_MAX;
    quant_params.multiplier = (int32_t *)conv_2_int4_output_mult;
    quant_params.shift = (int32_t *)conv_2_int4_output_shift;

    int32_t buf_size = arm_convolve_s4_get_buffer_size(&input_dims, &filter_dims);
    ctx.buf = malloc(buf_size);
    ctx.size = 0;

    arm_cmsis_nn_status result = arm_convolve_s4(&ctx,
                                                 &conv_params,
                                                 &quant_params,
                                                 &input_dims,
                                                 input_data,
                                                 &filter_dims,
                                                 conv_2_int4_weights,
                                                 &bias_dims,
                                                 bias_data,
                                                 &output_dims,
                                                 output);

    if (ctx.buf)
    {
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(expected, result);
    TEST_ASSERT_TRUE(validate(output, output_ref, output_ref_size));
    memset(output, 0, sizeof(output));

    buf_size = arm_convolve_wrapper_s4_get_buffer_size(&conv_params, &input_dims, &filter_dims, &output_dims);
    ctx.buf = malloc(buf_size);
    ctx.size = 0;

    result = arm_convolve_wrapper_s4(&ctx,
                                     &conv_params,
                                     &quant_params,
                                     &input_dims,
                                     input_data,
                                     &filter_dims,
                                     kernel_data,
                                     &bias_dims,
                                     bias_data,
                                     &output_dims,
                                     output);

    if (ctx.buf)
    {
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(expected, result);
    TEST_ASSERT_TRUE(validate(output, output_ref, output_ref_size));
}

void conv_3_arm_convolve_s4(void)
{
    const arm_cmsis_nn_status expected = ARM_CMSIS_NN_SUCCESS;
    int8_t output[CONV_3_INT4_DST_SIZE] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_conv_params conv_params;
    cmsis_nn_per_channel_quant_params quant_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims bias_dims;
    cmsis_nn_dims output_dims;

    const int32_t *bias_data = conv_3_int4_biases;
    const int8_t *kernel_data = conv_3_int4_weights;
    const int8_t *input_data = conv_3_int4_input;
    const int8_t *output_ref = conv_3_int4_output_ref;
    const int32_t output_ref_size = CONV_3_INT4_DST_SIZE;

    input_dims.n = CONV_3_INT4_INPUT_BATCHES;
    input_dims.w = CONV_3_INT4_INPUT_W;
    input_dims.h = CONV_3_INT4_INPUT_H;
    input_dims.c = CONV_3_INT4_IN_CH;
    filter_dims.w = CONV_3_INT4_FILTER_X;
    filter_dims.h = CONV_3_INT4_FILTER_Y;
    output_dims.w = CONV_3_INT4_OUTPUT_W;
    output_dims.h = CONV_3_INT4_OUTPUT_H;
    output_dims.c = CONV_3_INT4_OUT_CH;

    conv_params.padding.w = CONV_3_INT4_PAD_X;
    conv_params.padding.h = CONV_3_INT4_PAD_Y;
    conv_params.stride.w = CONV_3_INT4_STRIDE_X;
    conv_params.stride.h = CONV_3_INT4_STRIDE_Y;
    conv_params.dilation.w = CONV_3_INT4_DILATION_X;
    conv_params.dilation.h = CONV_3_INT4_DILATION_Y;

    conv_params.input_offset = CONV_3_INT4_INPUT_OFFSET;
    conv_params.output_offset = CONV_3_INT4_OUTPUT_OFFSET;
    conv_params.activation.min = CONV_3_INT4_OUT_ACTIVATION_MIN;
    conv_params.activation.max = CONV_3_INT4_OUT_ACTIVATION_MAX;
    quant_params.multiplier = (int32_t *)conv_3_int4_output_mult;
    quant_params.shift = (int32_t *)conv_3_int4_output_shift;

    int32_t buf_size = arm_convolve_s4_get_buffer_size(&input_dims, &filter_dims);
    ctx.buf = malloc(buf_size);
    ctx.size = 0;

    arm_cmsis_nn_status result = arm_convolve_s4(&ctx,
                                                 &conv_params,
                                                 &quant_params,
                                                 &input_dims,
                                                 input_data,
                                                 &filter_dims,
                                                 conv_3_int4_weights,
                                                 &bias_dims,
                                                 bias_data,
                                                 &output_dims,
                                                 output);

    if (ctx.buf)
    {
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(expected, result);
    TEST_ASSERT_TRUE(validate(output, output_ref, output_ref_size));
    memset(output, 0, sizeof(output));

    buf_size = arm_convolve_wrapper_s4_get_buffer_size(&conv_params, &input_dims, &filter_dims, &output_dims);
    ctx.buf = malloc(buf_size);
    ctx.size = 0;

    result = arm_convolve_wrapper_s4(&ctx,
                                     &conv_params,
                                     &quant_params,
                                     &input_dims,
                                     input_data,
                                     &filter_dims,
                                     kernel_data,
                                     &bias_dims,
                                     bias_data,
                                     &output_dims,
                                     output);

    if (ctx.buf)
    {
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(expected, result);
    TEST_ASSERT_TRUE(validate(output, output_ref, output_ref_size));
}

void conv_4_arm_convolve_s4(void)
{
    const arm_cmsis_nn_status expected = ARM_CMSIS_NN_SUCCESS;
    int8_t output[CONV_4_INT4_DST_SIZE] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_conv_params conv_params;
    cmsis_nn_per_channel_quant_params quant_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims bias_dims;
    cmsis_nn_dims output_dims;

    const int32_t *bias_data = conv_4_int4_biases;
    const int8_t *kernel_data = conv_4_int4_weights;
    const int8_t *input_data = conv_4_int4_input;
    const int8_t *output_ref = conv_4_int4_output_ref;
    const int32_t output_ref_size = CONV_4_INT4_DST_SIZE;

    input_dims.n = CONV_4_INT4_INPUT_BATCHES;
    input_dims.w = CONV_4_INT4_INPUT_W;
    input_dims.h = CONV_4_INT4_INPUT_H;
    input_dims.c = CONV_4_INT4_IN_CH;
    filter_dims.w = CONV_4_INT4_FILTER_X;
    filter_dims.h = CONV_4_INT4_FILTER_Y;
    output_dims.w = CONV_4_INT4_OUTPUT_W;
    output_dims.h = CONV_4_INT4_OUTPUT_H;
    output_dims.c = CONV_4_INT4_OUT_CH;

    conv_params.padding.w = CONV_4_INT4_PAD_X;
    conv_params.padding.h = CONV_4_INT4_PAD_Y;
    conv_params.stride.w = CONV_4_INT4_STRIDE_X;
    conv_params.stride.h = CONV_4_INT4_STRIDE_Y;
    conv_params.dilation.w = CONV_4_INT4_DILATION_X;
    conv_params.dilation.h = CONV_4_INT4_DILATION_Y;

    conv_params.input_offset = CONV_4_INT4_INPUT_OFFSET;
    conv_params.output_offset = CONV_4_INT4_OUTPUT_OFFSET;
    conv_params.activation.min = CONV_4_INT4_OUT_ACTIVATION_MIN;
    conv_params.activation.max = CONV_4_INT4_OUT_ACTIVATION_MAX;
    quant_params.multiplier = (int32_t *)conv_4_int4_output_mult;
    quant_params.shift = (int32_t *)conv_4_int4_output_shift;

    int32_t buf_size = arm_convolve_s4_get_buffer_size(&input_dims, &filter_dims);
    ctx.buf = malloc(buf_size);
    ctx.size = 0;

    arm_cmsis_nn_status result = arm_convolve_s4(&ctx,
                                                 &conv_params,
                                                 &quant_params,
                                                 &input_dims,
                                                 input_data,
                                                 &filter_dims,
                                                 conv_4_int4_weights,
                                                 &bias_dims,
                                                 bias_data,
                                                 &output_dims,
                                                 output);

    if (ctx.buf)
    {
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(expected, result);
    TEST_ASSERT_TRUE(validate(output, output_ref, output_ref_size));
    memset(output, 0, sizeof(output));

    buf_size = arm_convolve_wrapper_s4_get_buffer_size(&conv_params, &input_dims, &filter_dims, &output_dims);
    ctx.buf = malloc(buf_size);
    ctx.size = 0;

    result = arm_convolve_wrapper_s4(&ctx,
                                     &conv_params,
                                     &quant_params,
                                     &input_dims,
                                     input_data,
                                     &filter_dims,
                                     kernel_data,
                                     &bias_dims,
                                     bias_data,
                                     &output_dims,
                                     output);

    if (ctx.buf)
    {
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(expected, result);
    TEST_ASSERT_TRUE(validate(output, output_ref, output_ref_size));
}

void conv_out_activation_arm_convolve_s4(void)
{
    int8_t output[CONV_OUT_ACTIVATION_INT4_DST_SIZE] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_conv_params conv_params;
    cmsis_nn_per_channel_quant_params quant_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims bias_dims;
    cmsis_nn_dims output_dims;

    const int32_t *bias_data = conv_out_activation_int4_biases;
    const int8_t *kernel_data = conv_out_activation_int4_weights;
    const int8_t *input_data = conv_out_activation_int4_input;
    const int8_t *output_ref = conv_out_activation_int4_output_ref;
    const int32_t output_ref_size = CONV_OUT_ACTIVATION_INT4_DST_SIZE;

    input_dims.n = CONV_OUT_ACTIVATION_INT4_INPUT_BATCHES;
    input_dims.w = CONV_OUT_ACTIVATION_INT4_INPUT_W;
    input_dims.h = CONV_OUT_ACTIVATION_INT4_INPUT_H;
    input_dims.c = CONV_OUT_ACTIVATION_INT4_IN_CH;
    filter_dims.w = CONV_OUT_ACTIVATION_INT4_FILTER_X;
    filter_dims.h = CONV_OUT_ACTIVATION_INT4_FILTER_Y;
    output_dims.w = CONV_OUT_ACTIVATION_INT4_OUTPUT_W;
    output_dims.h = CONV_OUT_ACTIVATION_INT4_OUTPUT_H;
    output_dims.c = CONV_OUT_ACTIVATION_INT4_OUT_CH;

    conv_params.padding.w = CONV_OUT_ACTIVATION_INT4_PAD_X;
    conv_params.padding.h = CONV_OUT_ACTIVATION_INT4_PAD_Y;
    conv_params.stride.w = CONV_OUT_ACTIVATION_INT4_STRIDE_X;
    conv_params.stride.h = CONV_OUT_ACTIVATION_INT4_STRIDE_Y;
    conv_params.dilation.w = CONV_OUT_ACTIVATION_INT4_DILATION_X;
    conv_params.dilation.h = CONV_OUT_ACTIVATION_INT4_DILATION_Y;

    conv_params.input_offset = CONV_OUT_ACTIVATION_INT4_INPUT_OFFSET;
    conv_params.output_offset = CONV_OUT_ACTIVATION_INT4_OUTPUT_OFFSET;
    conv_params.activation.min = CONV_OUT_ACTIVATION_INT4_OUT_ACTIVATION_MIN;
    conv_params.activation.max = CONV_OUT_ACTIVATION_INT4_OUT_ACTIVATION_MAX;
    quant_params.multiplier = (int32_t *)conv_out_activation_int4_output_mult;
    quant_params.shift = (int32_t *)conv_out_activation_int4_output_shift;

    int32_t buf_size = arm_convolve_wrapper_s4_get_buffer_size(&conv_params, &input_dims, &filter_dims, &output_dims);
    ctx.buf = malloc(buf_size);

    arm_cmsis_nn_status result = arm_convolve_wrapper_s4(&ctx,
                                                         &conv_params,
                                                         &quant_params,
                                                         &input_dims,
                                                         input_data,
                                                         &filter_dims,
                                                         kernel_data,
                                                         &bias_dims,
                                                         bias_data,
                                                         &output_dims,
                                                         output);
    if (ctx.buf)
    {
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(ARM_CMSIS_NN_SUCCESS, result);
    TEST_ASSERT_TRUE(validate(output, output_ref, output_ref_size));
}

void conv_2x2_dilation_arm_convolve_s4(void)
{
    int8_t output[CONV_2X2_DILATION_INT4_DST_SIZE] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_conv_params conv_params;
    cmsis_nn_per_channel_quant_params quant_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims bias_dims;
    cmsis_nn_dims output_dims;

    const arm_cmsis_nn_status expected = ARM_CMSIS_NN_SUCCESS;
    const int32_t *bias_data = conv_2x2_dilation_int4_biases;
    const int8_t *kernel_data = conv_2x2_dilation_int4_weights;
    const int8_t *input_data = conv_2x2_dilation_int4_input;
    const int8_t *output_ref = conv_2x2_dilation_int4_output_ref;
    const int32_t output_ref_size = CONV_2X2_DILATION_INT4_DST_SIZE;

    input_dims.n = CONV_2X2_DILATION_INT4_INPUT_BATCHES;
    input_dims.w = CONV_2X2_DILATION_INT4_INPUT_W;
    input_dims.h = CONV_2X2_DILATION_INT4_INPUT_H;
    input_dims.c = CONV_2X2_DILATION_INT4_IN_CH;
    filter_dims.w = CONV_2X2_DILATION_INT4_FILTER_X;
    filter_dims.h = CONV_2X2_DILATION_INT4_FILTER_Y;
    output_dims.w = CONV_2X2_DILATION_INT4_OUTPUT_W;
    output_dims.h = CONV_2X2_DILATION_INT4_OUTPUT_H;
    output_dims.c = CONV_2X2_DILATION_INT4_OUT_CH;

    conv_params.padding.w = CONV_2X2_DILATION_INT4_PAD_X;
    conv_params.padding.h = CONV_2X2_DILATION_INT4_PAD_Y;
    conv_params.stride.w = CONV_2X2_DILATION_INT4_STRIDE_X;
    conv_params.stride.h = CONV_2X2_DILATION_INT4_STRIDE_Y;
    conv_params.dilation.w = CONV_2X2_DILATION_INT4_DILATION_X;
    conv_params.dilation.h = CONV_2X2_DILATION_INT4_DILATION_Y;

    conv_params.input_offset = CONV_2X2_DILATION_INT4_INPUT_OFFSET;
    conv_params.output_offset = CONV_2X2_DILATION_INT4_OUTPUT_OFFSET;
    conv_params.activation.min = CONV_2X2_DILATION_INT4_OUT_ACTIVATION_MIN;
    conv_params.activation.max = CONV_2X2_DILATION_INT4_OUT_ACTIVATION_MAX;
    quant_params.multiplier = (int32_t *)conv_2x2_dilation_int4_output_mult;
    quant_params.shift = (int32_t *)conv_2x2_dilation_int4_output_shift;

    int32_t buf_size = arm_convolve_s4_get_buffer_size(&input_dims, &filter_dims);
    ctx.buf = malloc(buf_size);
    ctx.size = 0;

    arm_cmsis_nn_status result = arm_convolve_s4(&ctx,
                                                 &conv_params,
                                                 &quant_params,
                                                 &input_dims,
                                                 input_data,
                                                 &filter_dims,
                                                 kernel_data,
                                                 &bias_dims,
                                                 bias_data,
                                                 &output_dims,
                                                 output);

    if (ctx.buf)
    {
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(expected, result);
    TEST_ASSERT_TRUE(validate(output, output_ref, output_ref_size));
    memset(output, 0, sizeof(output));

    buf_size = arm_convolve_wrapper_s4_get_buffer_size(&conv_params, &input_dims, &filter_dims, &output_dims);
    ctx.buf = malloc(buf_size);
    ctx.size = 0;

    result = arm_convolve_wrapper_s4(&ctx,
                                     &conv_params,
                                     &quant_params,
                                     &input_dims,
                                     input_data,
                                     &filter_dims,
                                     kernel_data,
                                     &bias_dims,
                                     bias_data,
                                     &output_dims,
                                     output);

    if (ctx.buf)
    {
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(expected, result);
    TEST_ASSERT_TRUE(validate(output, output_ref, output_ref_size));
}

void conv_2x2_dilation_5x5_input_arm_convolve_s4(void)
{
    int8_t output[CONV_2X2_DILATION_5X5_INPUT_INT4_DST_SIZE] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_conv_params conv_params;
    cmsis_nn_per_channel_quant_params quant_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims bias_dims;
    cmsis_nn_dims output_dims;

    const int32_t *bias_data = conv_2x2_dilation_5x5_input_int4_biases;
    const int8_t *kernel_data = conv_2x2_dilation_5x5_input_int4_weights;
    const int8_t *input_data = conv_2x2_dilation_5x5_input_int4_input;
    const int8_t *output_ref = conv_2x2_dilation_5x5_input_int4_output_ref;
    const int32_t output_ref_size = CONV_2X2_DILATION_5X5_INPUT_INT4_DST_SIZE;
    const arm_cmsis_nn_status expected = ARM_CMSIS_NN_SUCCESS;

    input_dims.n = CONV_2X2_DILATION_5X5_INPUT_INT4_INPUT_BATCHES;
    input_dims.w = CONV_2X2_DILATION_5X5_INPUT_INT4_INPUT_W;
    input_dims.h = CONV_2X2_DILATION_5X5_INPUT_INT4_INPUT_H;
    input_dims.c = CONV_2X2_DILATION_5X5_INPUT_INT4_IN_CH;
    filter_dims.w = CONV_2X2_DILATION_5X5_INPUT_INT4_FILTER_X;
    filter_dims.h = CONV_2X2_DILATION_5X5_INPUT_INT4_FILTER_Y;
    output_dims.w = CONV_2X2_DILATION_5X5_INPUT_INT4_OUTPUT_W;
    output_dims.h = CONV_2X2_DILATION_5X5_INPUT_INT4_OUTPUT_H;
    output_dims.c = CONV_2X2_DILATION_5X5_INPUT_INT4_OUT_CH;

    conv_params.padding.w = CONV_2X2_DILATION_5X5_INPUT_INT4_PAD_X;
    conv_params.padding.h = CONV_2X2_DILATION_5X5_INPUT_INT4_PAD_Y;
    conv_params.stride.w = CONV_2X2_DILATION_5X5_INPUT_INT4_STRIDE_X;
    conv_params.stride.h = CONV_2X2_DILATION_5X5_INPUT_INT4_STRIDE_Y;
    conv_params.dilation.w = CONV_2X2_DILATION_5X5_INPUT_INT4_DILATION_X;
    conv_params.dilation.h = CONV_2X2_DILATION_5X5_INPUT_INT4_DILATION_Y;

    conv_params.input_offset = CONV_2X2_DILATION_5X5_INPUT_INT4_INPUT_OFFSET;
    conv_params.output_offset = CONV_2X2_DILATION_5X5_INPUT_INT4_OUTPUT_OFFSET;
    conv_params.activation.min = CONV_2X2_DILATION_5X5_INPUT_INT4_OUT_ACTIVATION_MIN;
    conv_params.activation.max = CONV_2X2_DILATION_5X5_INPUT_INT4_OUT_ACTIVATION_MAX;
    quant_params.multiplier = (int32_t *)conv_2x2_dilation_5x5_input_int4_output_mult;
    quant_params.shift = (int32_t *)conv_2x2_dilation_5x5_input_int4_output_shift;

    int32_t buf_size = arm_convolve_s4_get_buffer_size(&input_dims, &filter_dims);
    ctx.buf = malloc(buf_size);

    arm_cmsis_nn_status result = arm_convolve_s4(&ctx,
                                                 &conv_params,
                                                 &quant_params,
                                                 &input_dims,
                                                 input_data,
                                                 &filter_dims,
                                                 kernel_data,
                                                 &bias_dims,
                                                 bias_data,
                                                 &output_dims,
                                                 output);
    if (ctx.buf)
    {
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(expected, result);
    TEST_ASSERT_TRUE(validate(output, output_ref, output_ref_size));
    memset(output, 0, sizeof(output));

    buf_size = arm_convolve_wrapper_s4_get_buffer_size(&conv_params, &input_dims, &filter_dims, &output_dims);
    ctx.buf = malloc(buf_size);
    ctx.size = 0;

    result = arm_convolve_wrapper_s4(&ctx,
                                     &conv_params,
                                     &quant_params,
                                     &input_dims,
                                     input_data,
                                     &filter_dims,
                                     kernel_data,
                                     &bias_dims,
                                     bias_data,
                                     &output_dims,
                                     output);

    if (ctx.buf)
    {
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(expected, result);
    TEST_ASSERT_TRUE(validate(output, output_ref, output_ref_size));
}

void conv_3x3_dilation_5x5_input_arm_convolve_s4(void)
{
    int8_t output[CONV_3X3_DILATION_5X5_INPUT_INT4_DST_SIZE] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_conv_params conv_params;
    cmsis_nn_per_channel_quant_params quant_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims bias_dims;
    cmsis_nn_dims output_dims;

    const int32_t *bias_data = conv_3x3_dilation_5x5_input_int4_biases;
    const int8_t *kernel_data = conv_3x3_dilation_5x5_input_int4_weights;
    const int8_t *input_data = conv_3x3_dilation_5x5_input_int4_input;
    const int8_t *output_ref = conv_3x3_dilation_5x5_input_int4_output_ref;
    const int32_t output_ref_size = CONV_3X3_DILATION_5X5_INPUT_INT4_DST_SIZE;
    const arm_cmsis_nn_status expected = ARM_CMSIS_NN_SUCCESS;

    input_dims.n = CONV_3X3_DILATION_5X5_INPUT_INT4_INPUT_BATCHES;
    input_dims.w = CONV_3X3_DILATION_5X5_INPUT_INT4_INPUT_W;
    input_dims.h = CONV_3X3_DILATION_5X5_INPUT_INT4_INPUT_H;
    input_dims.c = CONV_3X3_DILATION_5X5_INPUT_INT4_IN_CH;
    filter_dims.w = CONV_3X3_DILATION_5X5_INPUT_INT4_FILTER_X;
    filter_dims.h = CONV_3X3_DILATION_5X5_INPUT_INT4_FILTER_Y;
    output_dims.w = CONV_3X3_DILATION_5X5_INPUT_INT4_OUTPUT_W;
    output_dims.h = CONV_3X3_DILATION_5X5_INPUT_INT4_OUTPUT_H;
    output_dims.c = CONV_3X3_DILATION_5X5_INPUT_INT4_OUT_CH;

    conv_params.padding.w = CONV_3X3_DILATION_5X5_INPUT_INT4_PAD_X;
    conv_params.padding.h = CONV_3X3_DILATION_5X5_INPUT_INT4_PAD_Y;
    conv_params.stride.w = CONV_3X3_DILATION_5X5_INPUT_INT4_STRIDE_X;
    conv_params.stride.h = CONV_3X3_DILATION_5X5_INPUT_INT4_STRIDE_Y;
    conv_params.dilation.w = CONV_3X3_DILATION_5X5_INPUT_INT4_DILATION_X;
    conv_params.dilation.h = CONV_3X3_DILATION_5X5_INPUT_INT4_DILATION_Y;

    conv_params.input_offset = CONV_3X3_DILATION_5X5_INPUT_INT4_INPUT_OFFSET;
    conv_params.output_offset = CONV_3X3_DILATION_5X5_INPUT_INT4_OUTPUT_OFFSET;
    conv_params.activation.min = CONV_3X3_DILATION_5X5_INPUT_INT4_OUT_ACTIVATION_MIN;
    conv_params.activation.max = CONV_3X3_DILATION_5X5_INPUT_INT4_OUT_ACTIVATION_MAX;
    quant_params.multiplier = (int32_t *)conv_3x3_dilation_5x5_input_int4_output_mult;
    quant_params.shift = (int32_t *)conv_3x3_dilation_5x5_input_int4_output_shift;

    int32_t buf_size = arm_convolve_s4_get_buffer_size(&input_dims, &filter_dims);
    ctx.buf = malloc(buf_size);

    arm_cmsis_nn_status result = arm_convolve_s4(&ctx,
                                                 &conv_params,
                                                 &quant_params,
                                                 &input_dims,
                                                 input_data,
                                                 &filter_dims,
                                                 kernel_data,
                                                 &bias_dims,
                                                 bias_data,
                                                 &output_dims,
                                                 output);
    if (ctx.buf)
    {
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(expected, result);
    TEST_ASSERT_TRUE(validate(output, output_ref, output_ref_size));
    memset(output, 0, sizeof(output));

    buf_size = arm_convolve_wrapper_s4_get_buffer_size(&conv_params, &input_dims, &filter_dims, &output_dims);
    ctx.buf = malloc(buf_size);
    ctx.size = 0;

    result = arm_convolve_wrapper_s4(&ctx,
                                     &conv_params,
                                     &quant_params,
                                     &input_dims,
                                     input_data,
                                     &filter_dims,
                                     kernel_data,
                                     &bias_dims,
                                     bias_data,
                                     &output_dims,
                                     output);

    if (ctx.buf)
    {
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(expected, result);
    TEST_ASSERT_TRUE(validate(output, output_ref, output_ref_size));
}

void conv_2x3_dilation_arm_convolve_s4(void)
{
    int8_t output[CONV_2X3_DILATION_INT4_DST_SIZE] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_conv_params conv_params;
    cmsis_nn_per_channel_quant_params quant_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims bias_dims;
    cmsis_nn_dims output_dims;

    const int32_t *bias_data = conv_2x3_dilation_int4_biases;
    const int8_t *kernel_data = conv_2x3_dilation_int4_weights;
    const int8_t *input_data = conv_2x3_dilation_int4_input;
    const int8_t *output_ref = conv_2x3_dilation_int4_output_ref;
    const int32_t output_ref_size = CONV_2X3_DILATION_INT4_DST_SIZE;
    const arm_cmsis_nn_status expected = ARM_CMSIS_NN_SUCCESS;

    input_dims.n = CONV_2X3_DILATION_INT4_INPUT_BATCHES;
    input_dims.w = CONV_2X3_DILATION_INT4_INPUT_W;
    input_dims.h = CONV_2X3_DILATION_INT4_INPUT_H;
    input_dims.c = CONV_2X3_DILATION_INT4_IN_CH;
    filter_dims.w = CONV_2X3_DILATION_INT4_FILTER_X;
    filter_dims.h = CONV_2X3_DILATION_INT4_FILTER_Y;
    output_dims.w = CONV_2X3_DILATION_INT4_OUTPUT_W;
    output_dims.h = CONV_2X3_DILATION_INT4_OUTPUT_H;
    output_dims.c = CONV_2X3_DILATION_INT4_OUT_CH;

    conv_params.padding.w = CONV_2X3_DILATION_INT4_PAD_X;
    conv_params.padding.h = CONV_2X3_DILATION_INT4_PAD_Y;
    conv_params.stride.w = CONV_2X3_DILATION_INT4_STRIDE_X;
    conv_params.stride.h = CONV_2X3_DILATION_INT4_STRIDE_Y;
    conv_params.dilation.w = CONV_2X3_DILATION_INT4_DILATION_X;
    conv_params.dilation.h = CONV_2X3_DILATION_INT4_DILATION_Y;

    conv_params.input_offset = CONV_2X3_DILATION_INT4_INPUT_OFFSET;
    conv_params.output_offset = CONV_2X3_DILATION_INT4_OUTPUT_OFFSET;
    conv_params.activation.min = CONV_2X3_DILATION_INT4_OUT_ACTIVATION_MIN;
    conv_params.activation.max = CONV_2X3_DILATION_INT4_OUT_ACTIVATION_MAX;
    quant_params.multiplier = (int32_t *)conv_2x3_dilation_int4_output_mult;
    quant_params.shift = (int32_t *)conv_2x3_dilation_int4_output_shift;

    int32_t buf_size = arm_convolve_s4_get_buffer_size(&input_dims, &filter_dims);
    ctx.buf = malloc(buf_size);

    arm_cmsis_nn_status result = arm_convolve_s4(&ctx,
                                                 &conv_params,
                                                 &quant_params,
                                                 &input_dims,
                                                 input_data,
                                                 &filter_dims,
                                                 kernel_data,
                                                 &bias_dims,
                                                 bias_data,
                                                 &output_dims,
                                                 output);
    if (ctx.buf)
    {
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(expected, result);
    TEST_ASSERT_TRUE(validate(output, output_ref, output_ref_size));
    memset(output, 0, sizeof(output));

    buf_size = arm_convolve_wrapper_s4_get_buffer_size(&conv_params, &input_dims, &filter_dims, &output_dims);
    ctx.buf = malloc(buf_size);
    ctx.size = 0;

    result = arm_convolve_wrapper_s4(&ctx,
                                     &conv_params,
                                     &quant_params,
                                     &input_dims,
                                     input_data,
                                     &filter_dims,
                                     kernel_data,
                                     &bias_dims,
                                     bias_data,
                                     &output_dims,
                                     output);

    if (ctx.buf)
    {
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(expected, result);
    TEST_ASSERT_TRUE(validate(output, output_ref, output_ref_size));
}

void conv_3x2_dilation_arm_convolve_s4(void)
{
    int8_t output[CONV_3X2_DILATION_INT4_DST_SIZE] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_conv_params conv_params;
    cmsis_nn_per_channel_quant_params quant_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims bias_dims;
    cmsis_nn_dims output_dims;

    const int32_t *bias_data = conv_3x2_dilation_int4_biases;
    const int8_t *kernel_data = conv_3x2_dilation_int4_weights;
    const int8_t *input_data = conv_3x2_dilation_int4_input;
    const int8_t *output_ref = conv_3x2_dilation_int4_output_ref;
    const int32_t output_ref_size = CONV_3X2_DILATION_INT4_DST_SIZE;
    const arm_cmsis_nn_status expected = ARM_CMSIS_NN_SUCCESS;

    input_dims.n = CONV_3X2_DILATION_INT4_INPUT_BATCHES;
    input_dims.w = CONV_3X2_DILATION_INT4_INPUT_W;
    input_dims.h = CONV_3X2_DILATION_INT4_INPUT_H;
    input_dims.c = CONV_3X2_DILATION_INT4_IN_CH;
    filter_dims.w = CONV_3X2_DILATION_INT4_FILTER_X;
    filter_dims.h = CONV_3X2_DILATION_INT4_FILTER_Y;
    output_dims.w = CONV_3X2_DILATION_INT4_OUTPUT_W;
    output_dims.h = CONV_3X2_DILATION_INT4_OUTPUT_H;
    output_dims.c = CONV_3X2_DILATION_INT4_OUT_CH;

    conv_params.padding.w = CONV_3X2_DILATION_INT4_PAD_X;
    conv_params.padding.h = CONV_3X2_DILATION_INT4_PAD_Y;
    conv_params.stride.w = CONV_3X2_DILATION_INT4_STRIDE_X;
    conv_params.stride.h = CONV_3X2_DILATION_INT4_STRIDE_Y;
    conv_params.dilation.w = CONV_3X2_DILATION_INT4_DILATION_X;
    conv_params.dilation.h = CONV_3X2_DILATION_INT4_DILATION_Y;

    conv_params.input_offset = CONV_3X2_DILATION_INT4_INPUT_OFFSET;
    conv_params.output_offset = CONV_3X2_DILATION_INT4_OUTPUT_OFFSET;
    conv_params.activation.min = CONV_3X2_DILATION_INT4_OUT_ACTIVATION_MIN;
    conv_params.activation.max = CONV_3X2_DILATION_INT4_OUT_ACTIVATION_MAX;
    quant_params.multiplier = (int32_t *)conv_3x2_dilation_int4_output_mult;
    quant_params.shift = (int32_t *)conv_3x2_dilation_int4_output_shift;

    int32_t buf_size = arm_convolve_s4_get_buffer_size(&input_dims, &filter_dims);
    ctx.buf = malloc(buf_size);

    arm_cmsis_nn_status result = arm_convolve_s4(&ctx,
                                                 &conv_params,
                                                 &quant_params,
                                                 &input_dims,
                                                 input_data,
                                                 &filter_dims,
                                                 kernel_data,
                                                 &bias_dims,
                                                 bias_data,
                                                 &output_dims,
                                                 output);
    if (ctx.buf)
    {
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(expected, result);
    TEST_ASSERT_TRUE(validate(output, output_ref, output_ref_size));
    memset(output, 0, sizeof(output));

    buf_size = arm_convolve_wrapper_s4_get_buffer_size(&conv_params, &input_dims, &filter_dims, &output_dims);
    ctx.buf = malloc(buf_size);
    ctx.size = 0;

    result = arm_convolve_wrapper_s4(&ctx,
                                     &conv_params,
                                     &quant_params,
                                     &input_dims,
                                     input_data,
                                     &filter_dims,
                                     kernel_data,
                                     &bias_dims,
                                     bias_data,
                                     &output_dims,
                                     output);

    if (ctx.buf)
    {
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(expected, result);
    TEST_ASSERT_TRUE(validate(output, output_ref, output_ref_size));
}

void conv_dilation_golden_arm_convolve_s4(void)
{
    int8_t output[CONV_DILATION_GOLDEN_INT4_DST_SIZE] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_conv_params conv_params;
    cmsis_nn_per_channel_quant_params quant_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims bias_dims;
    cmsis_nn_dims output_dims;

    const int32_t *bias_data = conv_dilation_golden_int4_biases;
    const int8_t *kernel_data = conv_dilation_golden_int4_weights;
    const int8_t *input_data = conv_dilation_golden_int4_input;
    const int8_t *output_ref = conv_dilation_golden_int4_output_ref;
    const int32_t output_ref_size = CONV_DILATION_GOLDEN_INT4_DST_SIZE;
    const arm_cmsis_nn_status expected = ARM_CMSIS_NN_SUCCESS;

    input_dims.n = CONV_DILATION_GOLDEN_INT4_INPUT_BATCHES;
    input_dims.w = CONV_DILATION_GOLDEN_INT4_INPUT_W;
    input_dims.h = CONV_DILATION_GOLDEN_INT4_INPUT_H;
    input_dims.c = CONV_DILATION_GOLDEN_INT4_IN_CH;
    filter_dims.w = CONV_DILATION_GOLDEN_INT4_FILTER_X;
    filter_dims.h = CONV_DILATION_GOLDEN_INT4_FILTER_Y;
    output_dims.w = CONV_DILATION_GOLDEN_INT4_OUTPUT_W;
    output_dims.h = CONV_DILATION_GOLDEN_INT4_OUTPUT_H;
    output_dims.c = CONV_DILATION_GOLDEN_INT4_OUT_CH;

    conv_params.padding.w = CONV_DILATION_GOLDEN_INT4_PAD_X;
    conv_params.padding.h = CONV_DILATION_GOLDEN_INT4_PAD_Y;
    conv_params.stride.w = CONV_DILATION_GOLDEN_INT4_STRIDE_X;
    conv_params.stride.h = CONV_DILATION_GOLDEN_INT4_STRIDE_Y;
    conv_params.dilation.w = CONV_DILATION_GOLDEN_INT4_DILATION_X;
    conv_params.dilation.h = CONV_DILATION_GOLDEN_INT4_DILATION_Y;

    conv_params.input_offset = CONV_DILATION_GOLDEN_INT4_INPUT_OFFSET;
    conv_params.output_offset = CONV_DILATION_GOLDEN_INT4_OUTPUT_OFFSET;
    conv_params.activation.min = CONV_DILATION_GOLDEN_INT4_OUT_ACTIVATION_MIN;
    conv_params.activation.max = CONV_DILATION_GOLDEN_INT4_OUT_ACTIVATION_MAX;
    quant_params.multiplier = (int32_t *)conv_dilation_golden_int4_output_mult;
    quant_params.shift = (int32_t *)conv_dilation_golden_int4_output_shift;

    int32_t buf_size = arm_convolve_s4_get_buffer_size(&input_dims, &filter_dims);
    ctx.buf = malloc(buf_size);

    arm_cmsis_nn_status result = arm_convolve_s4(&ctx,
                                                 &conv_params,
                                                 &quant_params,
                                                 &input_dims,
                                                 input_data,
                                                 &filter_dims,
                                                 kernel_data,
                                                 &bias_dims,
                                                 bias_data,
                                                 &output_dims,
                                                 output);
    if (ctx.buf)
    {
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(expected, result);
    TEST_ASSERT_TRUE(validate(output, output_ref, output_ref_size));
    memset(output, 0, sizeof(output));

    buf_size = arm_convolve_wrapper_s4_get_buffer_size(&conv_params, &input_dims, &filter_dims, &output_dims);
    ctx.buf = malloc(buf_size);
    ctx.size = 0;

    result = arm_convolve_wrapper_s4(&ctx,
                                     &conv_params,
                                     &quant_params,
                                     &input_dims,
                                     input_data,
                                     &filter_dims,
                                     kernel_data,
                                     &bias_dims,
                                     bias_data,
                                     &output_dims,
                                     output);

    if (ctx.buf)
    {
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(expected, result);
    TEST_ASSERT_TRUE(validate(output, output_ref, output_ref_size));
}

void conv_5_arm_convolve_s4(void)
{
    const arm_cmsis_nn_status expected = ARM_CMSIS_NN_SUCCESS;
    int8_t output[CONV_5_INT4_DST_SIZE] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_conv_params conv_params;
    cmsis_nn_per_channel_quant_params quant_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims bias_dims;
    cmsis_nn_dims output_dims;

    const int32_t *bias_data = conv_5_int4_biases;
    const int8_t *kernel_data = conv_5_int4_weights;
    const int8_t *input_data = conv_5_int4_input;
    const int8_t *output_ref = conv_5_int4_output_ref;
    const int32_t output_ref_size = CONV_5_INT4_DST_SIZE;

    input_dims.n = CONV_5_INT4_INPUT_BATCHES;
    input_dims.w = CONV_5_INT4_INPUT_W;
    input_dims.h = CONV_5_INT4_INPUT_H;
    input_dims.c = CONV_5_INT4_IN_CH;
    filter_dims.w = CONV_5_INT4_FILTER_X;
    filter_dims.h = CONV_5_INT4_FILTER_Y;
    output_dims.w = CONV_5_INT4_OUTPUT_W;
    output_dims.h = CONV_5_INT4_OUTPUT_H;
    output_dims.c = CONV_5_INT4_OUT_CH;

    conv_params.padding.w = CONV_5_INT4_PAD_X;
    conv_params.padding.h = CONV_5_INT4_PAD_Y;
    conv_params.stride.w = CONV_5_INT4_STRIDE_X;
    conv_params.stride.h = CONV_5_INT4_STRIDE_Y;
    conv_params.dilation.w = CONV_5_INT4_DILATION_X;
    conv_params.dilation.h = CONV_5_INT4_DILATION_Y;

    conv_params.input_offset = CONV_5_INT4_INPUT_OFFSET;
    conv_params.output_offset = CONV_5_INT4_OUTPUT_OFFSET;
    conv_params.activation.min = CONV_5_INT4_OUT_ACTIVATION_MIN;
    conv_params.activation.max = CONV_5_INT4_OUT_ACTIVATION_MAX;
    quant_params.multiplier = (int32_t *)conv_5_int4_output_mult;
    quant_params.shift = (int32_t *)conv_5_int4_output_shift;

    int32_t buf_size = arm_convolve_s4_get_buffer_size(&input_dims, &filter_dims);
    ctx.buf = malloc(buf_size);
    ctx.size = 0;

    arm_cmsis_nn_status result = arm_convolve_s4(&ctx,
                                                 &conv_params,
                                                 &quant_params,
                                                 &input_dims,
                                                 input_data,
                                                 &filter_dims,
                                                 conv_5_int4_weights,
                                                 &bias_dims,
                                                 bias_data,
                                                 &output_dims,
                                                 output);

    if (ctx.buf)
    {
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(expected, result);
    TEST_ASSERT_TRUE(validate(output, output_ref, output_ref_size));
    memset(output, 0, sizeof(output));

    buf_size = arm_convolve_wrapper_s4_get_buffer_size(&conv_params, &input_dims, &filter_dims, &output_dims);
    ctx.buf = malloc(buf_size);
    ctx.size = 0;

    result = arm_convolve_wrapper_s4(&ctx,
                                     &conv_params,
                                     &quant_params,
                                     &input_dims,
                                     input_data,
                                     &filter_dims,
                                     kernel_data,
                                     &bias_dims,
                                     bias_data,
                                     &output_dims,
                                     output);

    if (ctx.buf)
    {
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(expected, result);
    TEST_ASSERT_TRUE(validate(output, output_ref, output_ref_size));
}

void buffer_size_arm_convolve_s4(void)
{
    cmsis_nn_conv_params conv_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims output_dims;

    input_dims.n = CONV_5_INT4_INPUT_BATCHES;
    input_dims.w = CONV_5_INT4_INPUT_W;
    input_dims.h = CONV_5_INT4_INPUT_H;
    input_dims.c = CONV_5_INT4_IN_CH;
    filter_dims.w = CONV_5_INT4_FILTER_X;
    filter_dims.h = CONV_5_INT4_FILTER_Y;
    output_dims.w = CONV_5_INT4_OUTPUT_W;
    output_dims.h = CONV_5_INT4_OUTPUT_H;
    output_dims.c = CONV_5_INT4_OUT_CH;

    conv_params.padding.w = CONV_5_INT4_PAD_X;
    conv_params.padding.h = CONV_5_INT4_PAD_Y;
    conv_params.stride.w = CONV_5_INT4_STRIDE_X;
    conv_params.stride.h = CONV_5_INT4_STRIDE_Y;
    conv_params.dilation.w = CONV_5_INT4_DILATION_X;
    conv_params.dilation.h = CONV_5_INT4_DILATION_Y;

    conv_params.input_offset = CONV_5_INT4_INPUT_OFFSET;
    conv_params.output_offset = CONV_5_INT4_OUTPUT_OFFSET;
    conv_params.activation.min = CONV_5_INT4_OUT_ACTIVATION_MIN;
    conv_params.activation.max = CONV_5_INT4_OUT_ACTIVATION_MAX;

    const int32_t buf_size = arm_convolve_s4_get_buffer_size(&input_dims, &filter_dims);
    const int32_t wrapper_buf_size =
        arm_convolve_wrapper_s4_get_buffer_size(&conv_params, &input_dims, &filter_dims, &output_dims);

    TEST_ASSERT_EQUAL(wrapper_buf_size, buf_size);
}

void buffer_size_mve_arm_convolve_s4(void)
{
#if defined(ARM_MATH_MVEI)
    cmsis_nn_conv_params conv_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims output_dims;

    input_dims.n = CONV_5_INT4_INPUT_BATCHES;
    input_dims.w = CONV_5_INT4_INPUT_W;
    input_dims.h = CONV_5_INT4_INPUT_H;
    input_dims.c = CONV_5_INT4_IN_CH;
    filter_dims.w = CONV_5_INT4_FILTER_X;
    filter_dims.h = CONV_5_INT4_FILTER_Y;
    output_dims.w = CONV_5_INT4_OUTPUT_W;
    output_dims.h = CONV_5_INT4_OUTPUT_H;
    output_dims.c = CONV_5_INT4_OUT_CH;

    conv_params.padding.w = CONV_5_INT4_PAD_X;
    conv_params.padding.h = CONV_5_INT4_PAD_Y;
    conv_params.stride.w = CONV_5_INT4_STRIDE_X;
    conv_params.stride.h = CONV_5_INT4_STRIDE_Y;
    conv_params.dilation.w = CONV_5_INT4_DILATION_X;
    conv_params.dilation.h = CONV_5_INT4_DILATION_Y;

    conv_params.input_offset = CONV_5_INT4_INPUT_OFFSET;
    conv_params.output_offset = CONV_5_INT4_OUTPUT_OFFSET;
    conv_params.activation.min = CONV_5_INT4_OUT_ACTIVATION_MIN;
    conv_params.activation.max = CONV_5_INT4_OUT_ACTIVATION_MAX;

    const int32_t wrapper_buf_size =
        arm_convolve_wrapper_s4_get_buffer_size(&conv_params, &input_dims, &filter_dims, &output_dims);
    const int32_t mve_wrapper_buf_size =
        arm_convolve_wrapper_s4_get_buffer_size_mve(&conv_params, &input_dims, &filter_dims, &output_dims);

    TEST_ASSERT_EQUAL(wrapper_buf_size, mve_wrapper_buf_size);
#endif
}

void buffer_size_dsp_arm_convolve_s4(void)
{
#if defined(ARM_MATH_DSP) && !defined(ARM_MATH_MVEI)
    cmsis_nn_conv_params conv_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims output_dims;

    input_dims.n = CONV_5_INT4_INPUT_BATCHES;
    input_dims.w = CONV_5_INT4_INPUT_W;
    input_dims.h = CONV_5_INT4_INPUT_H;
    input_dims.c = CONV_5_INT4_IN_CH;
    filter_dims.w = CONV_5_INT4_FILTER_X;
    filter_dims.h = CONV_5_INT4_FILTER_Y;
    output_dims.w = CONV_5_INT4_OUTPUT_W;
    output_dims.h = CONV_5_INT4_OUTPUT_H;
    output_dims.c = CONV_5_INT4_OUT_CH;

    conv_params.padding.w = CONV_5_INT4_PAD_X;
    conv_params.padding.h = CONV_5_INT4_PAD_Y;
    conv_params.stride.w = CONV_5_INT4_STRIDE_X;
    conv_params.stride.h = CONV_5_INT4_STRIDE_Y;
    conv_params.dilation.w = CONV_5_INT4_DILATION_X;
    conv_params.dilation.h = CONV_5_INT4_DILATION_Y;

    conv_params.input_offset = CONV_5_INT4_INPUT_OFFSET;
    conv_params.output_offset = CONV_5_INT4_OUTPUT_OFFSET;
    conv_params.activation.min = CONV_5_INT4_OUT_ACTIVATION_MIN;
    conv_params.activation.max = CONV_5_INT4_OUT_ACTIVATION_MAX;

    const int32_t wrapper_buf_size =
        arm_convolve_wrapper_s4_get_buffer_size(&conv_params, &input_dims, &filter_dims, &output_dims);
    const int32_t dsp_wrapper_buf_size =
        arm_convolve_wrapper_s4_get_buffer_size_dsp(&conv_params, &input_dims, &filter_dims, &output_dims);

    TEST_ASSERT_EQUAL(wrapper_buf_size, dsp_wrapper_buf_size);
#endif
}

void conv_1_x_n_1_arm_convolve_s4(void)
{
    const arm_cmsis_nn_status expected = ARM_CMSIS_NN_SUCCESS;
    int8_t output[CONV_1_X_N_1_INT4_DST_SIZE] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_conv_params conv_params;
    cmsis_nn_per_channel_quant_params quant_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims bias_dims;
    cmsis_nn_dims output_dims;

    const int32_t *bias_data = conv_1_x_n_1_int4_biases;
    const int8_t *kernel_data = conv_1_x_n_1_int4_weights;
    const int8_t *input_data = conv_1_x_n_1_int4_input;
    const int8_t *output_ref = conv_1_x_n_1_int4_output_ref;
    const int32_t output_ref_size = CONV_1_X_N_1_INT4_DST_SIZE;

    input_dims.n = CONV_1_X_N_1_INT4_INPUT_BATCHES;
    input_dims.w = CONV_1_X_N_1_INT4_INPUT_W;
    input_dims.h = CONV_1_X_N_1_INT4_INPUT_H;
    input_dims.c = CONV_1_X_N_1_INT4_IN_CH;
    filter_dims.w = CONV_1_X_N_1_INT4_FILTER_X;
    filter_dims.h = CONV_1_X_N_1_INT4_FILTER_Y;
    output_dims.w = CONV_1_X_N_1_INT4_OUTPUT_W;
    output_dims.h = CONV_1_X_N_1_INT4_OUTPUT_H;
    output_dims.c = CONV_1_X_N_1_INT4_OUT_CH;

    conv_params.padding.w = CONV_1_X_N_1_INT4_PAD_X;
    conv_params.padding.h = CONV_1_X_N_1_INT4_PAD_Y;
    conv_params.stride.w = CONV_1_X_N_1_INT4_STRIDE_X;
    conv_params.stride.h = CONV_1_X_N_1_INT4_STRIDE_Y;
    conv_params.dilation.w = CONV_1_X_N_1_INT4_DILATION_X;
    conv_params.dilation.h = CONV_1_X_N_1_INT4_DILATION_Y;

    conv_params.input_offset = CONV_1_X_N_1_INT4_INPUT_OFFSET;
    conv_params.output_offset = CONV_1_X_N_1_INT4_OUTPUT_OFFSET;
    conv_params.activation.min = CONV_1_X_N_1_INT4_OUT_ACTIVATION_MIN;
    conv_params.activation.max = CONV_1_X_N_1_INT4_OUT_ACTIVATION_MAX;
    quant_params.multiplier = (int32_t *)conv_1_x_n_1_int4_output_mult;
    quant_params.shift = (int32_t *)conv_1_x_n_1_int4_output_shift;

    int32_t buf_size = arm_convolve_s4_get_buffer_size(&input_dims, &filter_dims);
    ctx.buf = malloc(buf_size);
    ctx.size = 0;

    arm_cmsis_nn_status result = arm_convolve_wrapper_s4(&ctx,
                                                         &conv_params,
                                                         &quant_params,
                                                         &input_dims,
                                                         input_data,
                                                         &filter_dims,
                                                         kernel_data,
                                                         &bias_dims,
                                                         bias_data,
                                                         &output_dims,
                                                         output);

    if (ctx.buf)
    {
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(expected, result);
    TEST_ASSERT_TRUE(validate(output, output_ref, output_ref_size));
    memset(output, 0, sizeof(output));

    buf_size = arm_convolve_wrapper_s4_get_buffer_size(&conv_params, &input_dims, &filter_dims, &output_dims);
    ctx.buf = malloc(buf_size);

    result = arm_convolve_1_x_n_s4(&ctx,
                                   &conv_params,
                                   &quant_params,
                                   &input_dims,
                                   input_data,
                                   &filter_dims,
                                   kernel_data,
                                   &bias_dims,
                                   bias_data,
                                   &output_dims,
                                   output);
    if (ctx.buf)
    {
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(ARM_CMSIS_NN_SUCCESS, result);
    TEST_ASSERT_TRUE(validate(output, output_ref, output_ref_size));
}

void conv_1_x_n_2_arm_convolve_s4(void)
{
    const arm_cmsis_nn_status expected = ARM_CMSIS_NN_SUCCESS;
    int8_t output[CONV_1_X_N_2_INT4_DST_SIZE] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_conv_params conv_params;
    cmsis_nn_per_channel_quant_params quant_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims bias_dims;
    cmsis_nn_dims output_dims;

    const int32_t *bias_data = conv_1_x_n_2_int4_biases;
    const int8_t *kernel_data = conv_1_x_n_2_int4_weights;
    const int8_t *input_data = conv_1_x_n_2_int4_input;
    const int8_t *output_ref = conv_1_x_n_2_int4_output_ref;
    const int32_t output_ref_size = CONV_1_X_N_2_INT4_DST_SIZE;

    input_dims.n = CONV_1_X_N_2_INT4_INPUT_BATCHES;
    input_dims.w = CONV_1_X_N_2_INT4_INPUT_W;
    input_dims.h = CONV_1_X_N_2_INT4_INPUT_H;
    input_dims.c = CONV_1_X_N_2_INT4_IN_CH;
    filter_dims.w = CONV_1_X_N_2_INT4_FILTER_X;
    filter_dims.h = CONV_1_X_N_2_INT4_FILTER_Y;
    output_dims.w = CONV_1_X_N_2_INT4_OUTPUT_W;
    output_dims.h = CONV_1_X_N_2_INT4_OUTPUT_H;
    output_dims.c = CONV_1_X_N_2_INT4_OUT_CH;

    conv_params.padding.w = CONV_1_X_N_2_INT4_PAD_X;
    conv_params.padding.h = CONV_1_X_N_2_INT4_PAD_Y;
    conv_params.stride.w = CONV_1_X_N_2_INT4_STRIDE_X;
    conv_params.stride.h = CONV_1_X_N_2_INT4_STRIDE_Y;
    conv_params.dilation.w = CONV_1_X_N_2_INT4_DILATION_X;
    conv_params.dilation.h = CONV_1_X_N_2_INT4_DILATION_Y;

    conv_params.input_offset = CONV_1_X_N_2_INT4_INPUT_OFFSET;
    conv_params.output_offset = CONV_1_X_N_2_INT4_OUTPUT_OFFSET;
    conv_params.activation.min = CONV_1_X_N_2_INT4_OUT_ACTIVATION_MIN;
    conv_params.activation.max = CONV_1_X_N_2_INT4_OUT_ACTIVATION_MAX;
    quant_params.multiplier = (int32_t *)conv_1_x_n_2_int4_output_mult;
    quant_params.shift = (int32_t *)conv_1_x_n_2_int4_output_shift;

    int32_t buf_size = arm_convolve_s4_get_buffer_size(&input_dims, &filter_dims);
    ctx.buf = malloc(buf_size);
    ctx.size = 0;

    arm_cmsis_nn_status result = arm_convolve_wrapper_s4(&ctx,
                                                         &conv_params,
                                                         &quant_params,
                                                         &input_dims,
                                                         input_data,
                                                         &filter_dims,
                                                         kernel_data,
                                                         &bias_dims,
                                                         bias_data,
                                                         &output_dims,
                                                         output);

    if (ctx.buf)
    {
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(expected, result);
    memset(output, 0, sizeof(output));

    buf_size = arm_convolve_wrapper_s4_get_buffer_size(&conv_params, &input_dims, &filter_dims, &output_dims);

    ctx.buf = malloc(buf_size);

    result = arm_convolve_1_x_n_s4(&ctx,
                                   &conv_params,
                                   &quant_params,
                                   &input_dims,
                                   input_data,
                                   &filter_dims,
                                   kernel_data,
                                   &bias_dims,
                                   bias_data,
                                   &output_dims,
                                   output);
    if (ctx.buf)
    {
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(ARM_CMSIS_NN_SUCCESS, result);
    TEST_ASSERT_TRUE(validate(output, output_ref, output_ref_size));
}

void conv_1_x_n_3_arm_convolve_s4(void)
{
    int8_t output[CONV_1_X_N_3_INT4_DST_SIZE] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_conv_params conv_params;
    cmsis_nn_per_channel_quant_params quant_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims bias_dims;
    cmsis_nn_dims output_dims;

    const int32_t *bias_data = conv_1_x_n_3_int4_biases;
    const int8_t *kernel_data = conv_1_x_n_3_int4_weights;
    const int8_t *input_data = conv_1_x_n_3_int4_input;
    const int8_t *output_ref = conv_1_x_n_3_int4_output_ref;
    const int32_t output_ref_size = CONV_1_X_N_3_INT4_DST_SIZE;

    input_dims.n = CONV_1_X_N_3_INT4_INPUT_BATCHES;
    input_dims.w = CONV_1_X_N_3_INT4_INPUT_W;
    input_dims.h = CONV_1_X_N_3_INT4_INPUT_H;
    input_dims.c = CONV_1_X_N_3_INT4_IN_CH;
    filter_dims.w = CONV_1_X_N_3_INT4_FILTER_X;
    filter_dims.h = CONV_1_X_N_3_INT4_FILTER_Y;
    output_dims.w = CONV_1_X_N_3_INT4_OUTPUT_W;
    output_dims.h = CONV_1_X_N_3_INT4_OUTPUT_H;
    output_dims.c = CONV_1_X_N_3_INT4_OUT_CH;

    conv_params.padding.w = CONV_1_X_N_3_INT4_PAD_X;
    conv_params.padding.h = CONV_1_X_N_3_INT4_PAD_Y;
    conv_params.stride.w = CONV_1_X_N_3_INT4_STRIDE_X;
    conv_params.stride.h = CONV_1_X_N_3_INT4_STRIDE_Y;
    conv_params.dilation.w = CONV_1_X_N_3_INT4_DILATION_X;
    conv_params.dilation.h = CONV_1_X_N_3_INT4_DILATION_Y;

    conv_params.input_offset = CONV_1_X_N_3_INT4_INPUT_OFFSET;
    conv_params.output_offset = CONV_1_X_N_3_INT4_OUTPUT_OFFSET;
    conv_params.activation.min = CONV_1_X_N_3_INT4_OUT_ACTIVATION_MIN;
    conv_params.activation.max = CONV_1_X_N_3_INT4_OUT_ACTIVATION_MAX;
    quant_params.multiplier = (int32_t *)conv_1_x_n_3_int4_output_mult;
    quant_params.shift = (int32_t *)conv_1_x_n_3_int4_output_shift;

    int32_t buf_size = arm_convolve_s4_get_buffer_size(&input_dims, &filter_dims);
    ctx.buf = malloc(buf_size);
    ctx.size = 0;

    arm_cmsis_nn_status result = arm_convolve_wrapper_s4(&ctx,
                                                         &conv_params,
                                                         &quant_params,
                                                         &input_dims,
                                                         input_data,
                                                         &filter_dims,
                                                         kernel_data,
                                                         &bias_dims,
                                                         bias_data,
                                                         &output_dims,
                                                         output);

    if (ctx.buf)
    {
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(ARM_CMSIS_NN_SUCCESS, result);
    TEST_ASSERT_TRUE(validate(output, output_ref, output_ref_size));
    memset(output, 0, sizeof(output));

    buf_size = arm_convolve_wrapper_s4_get_buffer_size(&conv_params, &input_dims, &filter_dims, &output_dims);
    ctx.buf = malloc(buf_size);

    result = arm_convolve_1_x_n_s4(&ctx,
                                   &conv_params,
                                   &quant_params,
                                   &input_dims,
                                   input_data,
                                   &filter_dims,
                                   kernel_data,
                                   &bias_dims,
                                   bias_data,
                                   &output_dims,
                                   output);
    if (ctx.buf)
    {
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(ARM_CMSIS_NN_SUCCESS, result);
    TEST_ASSERT_TRUE(validate(output, output_ref, output_ref_size));
}

void conv_1_x_n_4_arm_convolve_s4(void)
{
    const arm_cmsis_nn_status expected = ARM_CMSIS_NN_SUCCESS;
    int8_t output[CONV_1_X_N_4_INT4_DST_SIZE] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_conv_params conv_params;
    cmsis_nn_per_channel_quant_params quant_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims bias_dims;
    cmsis_nn_dims output_dims;

    const int32_t *bias_data = conv_1_x_n_4_int4_biases;
    const int8_t *kernel_data = conv_1_x_n_4_int4_weights;
    const int8_t *input_data = conv_1_x_n_4_int4_input;
    const int8_t *output_ref = conv_1_x_n_4_int4_output_ref;
    const int32_t output_ref_size = CONV_1_X_N_4_INT4_DST_SIZE;

    input_dims.n = CONV_1_X_N_4_INT4_INPUT_BATCHES;
    input_dims.w = CONV_1_X_N_4_INT4_INPUT_W;
    input_dims.h = CONV_1_X_N_4_INT4_INPUT_H;
    input_dims.c = CONV_1_X_N_4_INT4_IN_CH;
    filter_dims.w = CONV_1_X_N_4_INT4_FILTER_X;
    filter_dims.h = CONV_1_X_N_4_INT4_FILTER_Y;
    output_dims.w = CONV_1_X_N_4_INT4_OUTPUT_W;
    output_dims.h = CONV_1_X_N_4_INT4_OUTPUT_H;
    output_dims.c = CONV_1_X_N_4_INT4_OUT_CH;

    conv_params.padding.w = CONV_1_X_N_4_INT4_PAD_X;
    conv_params.padding.h = CONV_1_X_N_4_INT4_PAD_Y;
    conv_params.stride.w = CONV_1_X_N_4_INT4_STRIDE_X;
    conv_params.stride.h = CONV_1_X_N_4_INT4_STRIDE_Y;
    conv_params.dilation.w = CONV_1_X_N_4_INT4_DILATION_X;
    conv_params.dilation.h = CONV_1_X_N_4_INT4_DILATION_Y;

    conv_params.input_offset = CONV_1_X_N_4_INT4_INPUT_OFFSET;
    conv_params.output_offset = CONV_1_X_N_4_INT4_OUTPUT_OFFSET;
    conv_params.activation.min = CONV_1_X_N_4_INT4_OUT_ACTIVATION_MIN;
    conv_params.activation.max = CONV_1_X_N_4_INT4_OUT_ACTIVATION_MAX;
    quant_params.multiplier = (int32_t *)conv_1_x_n_4_int4_output_mult;
    quant_params.shift = (int32_t *)conv_1_x_n_4_int4_output_shift;

    int32_t buf_size = arm_convolve_s4_get_buffer_size(&input_dims, &filter_dims);

    ctx.buf = malloc(buf_size);
    ctx.size = 0;

    arm_cmsis_nn_status result = arm_convolve_wrapper_s4(&ctx,
                                                         &conv_params,
                                                         &quant_params,
                                                         &input_dims,
                                                         input_data,
                                                         &filter_dims,
                                                         kernel_data,
                                                         &bias_dims,
                                                         bias_data,
                                                         &output_dims,
                                                         output);

    if (ctx.buf)
    {
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(expected, result);
    TEST_ASSERT_TRUE(validate(output, output_ref, output_ref_size));
    memset(output, 0, sizeof(output));

    buf_size = arm_convolve_wrapper_s4_get_buffer_size(&conv_params, &input_dims, &filter_dims, &output_dims);

    ctx.buf = malloc(buf_size);

    result = arm_convolve_1_x_n_s4(&ctx,
                                   &conv_params,
                                   &quant_params,
                                   &input_dims,
                                   input_data,
                                   &filter_dims,
                                   kernel_data,
                                   &bias_dims,
                                   bias_data,
                                   &output_dims,
                                   output);
    if (ctx.buf)
    {
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(ARM_CMSIS_NN_SUCCESS, result);
    TEST_ASSERT_TRUE(validate(output, output_ref, output_ref_size));
}

void conv_1_x_n_5_arm_convolve_s4(void)
{
    const arm_cmsis_nn_status expected = ARM_CMSIS_NN_SUCCESS;
    int8_t output[CONV_1_X_N_5_INT4_DST_SIZE] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_conv_params conv_params;
    cmsis_nn_per_channel_quant_params quant_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims bias_dims;
    cmsis_nn_dims output_dims;

    const int32_t *bias_data = conv_1_x_n_5_int4_biases;
    const int8_t *kernel_data = conv_1_x_n_5_int4_weights;
    const int8_t *input_data = conv_1_x_n_5_int4_input;
    const int8_t *output_ref = conv_1_x_n_5_int4_output_ref;
    const int32_t output_ref_size = CONV_1_X_N_5_INT4_DST_SIZE;

    input_dims.n = CONV_1_X_N_5_INT4_INPUT_BATCHES;
    input_dims.w = CONV_1_X_N_5_INT4_INPUT_W;
    input_dims.h = CONV_1_X_N_5_INT4_INPUT_H;
    input_dims.c = CONV_1_X_N_5_INT4_IN_CH;
    filter_dims.w = CONV_1_X_N_5_INT4_FILTER_X;
    filter_dims.h = CONV_1_X_N_5_INT4_FILTER_Y;
    output_dims.w = CONV_1_X_N_5_INT4_OUTPUT_W;
    output_dims.h = CONV_1_X_N_5_INT4_OUTPUT_H;
    output_dims.c = CONV_1_X_N_5_INT4_OUT_CH;

    conv_params.padding.w = CONV_1_X_N_5_INT4_PAD_X;
    conv_params.padding.h = CONV_1_X_N_5_INT4_PAD_Y;
    conv_params.stride.w = CONV_1_X_N_5_INT4_STRIDE_X;
    conv_params.stride.h = CONV_1_X_N_5_INT4_STRIDE_Y;
    conv_params.dilation.w = CONV_1_X_N_5_INT4_DILATION_X;
    conv_params.dilation.h = CONV_1_X_N_5_INT4_DILATION_Y;

    conv_params.input_offset = CONV_1_X_N_5_INT4_INPUT_OFFSET;
    conv_params.output_offset = CONV_1_X_N_5_INT4_OUTPUT_OFFSET;
    conv_params.activation.min = CONV_1_X_N_5_INT4_OUT_ACTIVATION_MIN;
    conv_params.activation.max = CONV_1_X_N_5_INT4_OUT_ACTIVATION_MAX;
    quant_params.multiplier = (int32_t *)conv_1_x_n_5_int4_output_mult;
    quant_params.shift = (int32_t *)conv_1_x_n_5_int4_output_shift;

    int32_t buf_size = arm_convolve_s4_get_buffer_size(&input_dims, &filter_dims);
    ctx.buf = malloc(buf_size);
    ctx.size = 0;

    arm_cmsis_nn_status result = arm_convolve_wrapper_s4(&ctx,
                                                         &conv_params,
                                                         &quant_params,
                                                         &input_dims,
                                                         input_data,
                                                         &filter_dims,
                                                         kernel_data,
                                                         &bias_dims,
                                                         bias_data,
                                                         &output_dims,
                                                         output);

    if (ctx.buf)
    {
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(expected, result);
    memset(output, 0, sizeof(output));

    buf_size = arm_convolve_wrapper_s4_get_buffer_size(&conv_params, &input_dims, &filter_dims, &output_dims);
    ctx.buf = malloc(buf_size);

    result = arm_convolve_1_x_n_s4(&ctx,
                                   &conv_params,
                                   &quant_params,
                                   &input_dims,
                                   input_data,
                                   &filter_dims,
                                   kernel_data,
                                   &bias_dims,
                                   bias_data,
                                   &output_dims,
                                   output);
    if (ctx.buf)
    {
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(ARM_CMSIS_NN_SUCCESS, result);
    TEST_ASSERT_TRUE(validate(output, output_ref, output_ref_size));
}
