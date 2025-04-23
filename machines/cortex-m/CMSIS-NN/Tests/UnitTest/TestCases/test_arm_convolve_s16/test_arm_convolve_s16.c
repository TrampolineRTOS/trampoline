/*
 * SPDX-FileCopyrightText: Copyright 2010-2024 Arm Limited and/or its affiliates <open-source-office@arm.com> All rights
 * reserved.
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

#include "../TestData/int16xint8/test_data.h"
#include "../TestData/int16xint8_dilation_1/test_data.h"
#include "../TestData/int16xint8_dilation_2/test_data.h"
#include "../TestData/int16xint8_dilation_3/test_data.h"
#include "../TestData/int16xint8_spill/test_data.h"
#include "../TestData/int16xint8_spill2/test_data.h"
#include "../TestData/int16xint8xint32_1/test_data.h"
#include "../TestData/int16xint8xint32_2/test_data.h"
#include "../TestData/int16xint8xint32_3/test_data.h"
#include "../TestData/int16xint8xint32_4/test_data.h"
#include "../TestData/int16xint8xint32_5/test_data.h"
#include "../TestData/int16xint8xint32_6/test_data.h"
#include "../TestData/requantize_s64/test_data.h"
#include "../Utils/validate.h"

void int16xint8_arm_convolve_s16(void)
{
    int16_t output[INT16XINT8_DST_SIZE] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_conv_params conv_params;
    cmsis_nn_per_channel_quant_params quant_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims bias_dims;
    cmsis_nn_dims output_dims;

    const int64_t *int64_bias_data = int16xint8_biases;
    const cmsis_nn_bias_data bias_data = {int64_bias_data, false};
    const int8_t *kernel_data = int16xint8_weights;
    const int16_t *input_data = int16xint8_input;
    const int16_t *output_ref = int16xint8_output_ref;
    const int32_t output_ref_size = INT16XINT8_DST_SIZE;

    input_dims.n = INT16XINT8_INPUT_BATCHES;
    input_dims.w = INT16XINT8_INPUT_W;
    input_dims.h = INT16XINT8_INPUT_H;
    input_dims.c = INT16XINT8_IN_CH;
    filter_dims.w = INT16XINT8_FILTER_X;
    filter_dims.h = INT16XINT8_FILTER_Y;
    output_dims.w = INT16XINT8_OUTPUT_W;
    output_dims.h = INT16XINT8_OUTPUT_H;
    output_dims.c = INT16XINT8_OUT_CH;

    conv_params.padding.w = INT16XINT8_PAD_X;
    conv_params.padding.h = INT16XINT8_PAD_Y;
    conv_params.stride.w = INT16XINT8_STRIDE_X;
    conv_params.stride.h = INT16XINT8_STRIDE_Y;
    conv_params.dilation.w = INT16XINT8_DILATION_X;
    conv_params.dilation.h = INT16XINT8_DILATION_Y;

    conv_params.input_offset = 0;
    conv_params.output_offset = 0;
    conv_params.activation.min = INT16XINT8_OUT_ACTIVATION_MIN;
    conv_params.activation.max = INT16XINT8_OUT_ACTIVATION_MAX;
    quant_params.multiplier = (int32_t *)int16xint8_output_mult;
    quant_params.shift = (int32_t *)int16xint8_output_shift;

    int buf_size = arm_convolve_s16_get_buffer_size(&input_dims, &filter_dims);
    ctx.buf = malloc(buf_size);
    arm_cmsis_nn_status result;
    result = arm_convolve_s16(&ctx,
                              &conv_params,
                              &quant_params,
                              &input_dims,
                              input_data,
                              &filter_dims,
                              kernel_data,
                              &bias_dims,
                              &bias_data,
                              &output_dims,
                              output);
    if (ctx.buf)
    {
        // The caller is responsible to clear the scratch buffers for security reasons if applicable.
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(ARM_CMSIS_NN_SUCCESS, result);
    TEST_ASSERT_TRUE(validate_s16(output, output_ref, output_ref_size));
    memset(output, 0, sizeof(output));

    buf_size = arm_convolve_wrapper_s16_get_buffer_size(&conv_params, &input_dims, &filter_dims, &output_dims);
    ctx.buf = malloc(buf_size);

    result = arm_convolve_wrapper_s16(&ctx,
                                      &conv_params,
                                      &quant_params,
                                      &input_dims,
                                      input_data,
                                      &filter_dims,
                                      kernel_data,
                                      &bias_dims,
                                      &bias_data,
                                      &output_dims,
                                      output);
    if (ctx.buf)
    {
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(ARM_CMSIS_NN_SUCCESS, result);
    TEST_ASSERT_TRUE(validate_s16(output, output_ref, output_ref_size));
}

void requantize_s64_arm_convolve_s16(void)
{
    int16_t output[REQUANTIZE_S64_DST_SIZE] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_conv_params conv_params;
    cmsis_nn_per_channel_quant_params quant_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims bias_dims;
    cmsis_nn_dims output_dims;

    const int64_t *int64_bias_data = requantize_s64_biases;
    const cmsis_nn_bias_data bias_data = {int64_bias_data, false};
    const int8_t *kernel_data = requantize_s64_weights;
    const int16_t *input_data = requantize_s64_input;
    const int16_t *output_ref = requantize_s64_output_ref;
    const int32_t output_ref_size = REQUANTIZE_S64_DST_SIZE;

    input_dims.n = REQUANTIZE_S64_INPUT_BATCHES;
    input_dims.w = REQUANTIZE_S64_INPUT_W;
    input_dims.h = REQUANTIZE_S64_INPUT_H;
    input_dims.c = REQUANTIZE_S64_IN_CH;
    filter_dims.w = REQUANTIZE_S64_FILTER_X;
    filter_dims.h = REQUANTIZE_S64_FILTER_Y;
    output_dims.w = REQUANTIZE_S64_OUTPUT_W;
    output_dims.h = REQUANTIZE_S64_OUTPUT_H;
    output_dims.c = REQUANTIZE_S64_OUT_CH;

    conv_params.padding.w = REQUANTIZE_S64_PAD_X;
    conv_params.padding.h = REQUANTIZE_S64_PAD_Y;
    conv_params.stride.w = REQUANTIZE_S64_STRIDE_X;
    conv_params.stride.h = REQUANTIZE_S64_STRIDE_Y;
    conv_params.dilation.w = REQUANTIZE_S64_DILATION_X;
    conv_params.dilation.h = REQUANTIZE_S64_DILATION_Y;

    conv_params.input_offset = REQUANTIZE_S64_INPUT_OFFSET;
    conv_params.output_offset = REQUANTIZE_S64_OUTPUT_OFFSET;
    conv_params.activation.min = REQUANTIZE_S64_OUT_ACTIVATION_MIN;
    conv_params.activation.max = REQUANTIZE_S64_OUT_ACTIVATION_MAX;
    quant_params.multiplier = (int32_t *)requantize_s64_output_mult;
    quant_params.shift = (int32_t *)requantize_s64_output_shift;

    int buf_size = arm_convolve_s16_get_buffer_size(&input_dims, &filter_dims);
    ctx.buf = malloc(buf_size);

    arm_cmsis_nn_status result = arm_convolve_s16(&ctx,
                                                  &conv_params,
                                                  &quant_params,
                                                  &input_dims,
                                                  input_data,
                                                  &filter_dims,
                                                  kernel_data,
                                                  &bias_dims,
                                                  &bias_data,
                                                  &output_dims,
                                                  output);
    if (ctx.buf)
    {
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(ARM_CMSIS_NN_SUCCESS, result);
    TEST_ASSERT_TRUE(validate_s16(output, output_ref, output_ref_size));
    memset(output, 0, sizeof(output));

    buf_size = arm_convolve_wrapper_s16_get_buffer_size(&conv_params, &input_dims, &filter_dims, &output_dims);
    ctx.buf = malloc(buf_size);

    result = arm_convolve_wrapper_s16(&ctx,
                                      &conv_params,
                                      &quant_params,
                                      &input_dims,
                                      input_data,
                                      &filter_dims,
                                      kernel_data,
                                      &bias_dims,
                                      &bias_data,
                                      &output_dims,
                                      output);

    if (ctx.buf)
    {
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(ARM_CMSIS_NN_SUCCESS, result);
    TEST_ASSERT_TRUE(validate_s16(output, output_ref, output_ref_size));
}

void int16xint8_dilation_1_arm_convolve_s16(void)
{
    int16_t output[INT16XINT8_DILATION_1_DST_SIZE] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_conv_params conv_params;
    cmsis_nn_per_channel_quant_params quant_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims bias_dims;
    cmsis_nn_dims output_dims;

    const int64_t *int64_bias_data = int16xint8_dilation_1_biases;
    const cmsis_nn_bias_data bias_data = {int64_bias_data, false};
    const int8_t *kernel_data = int16xint8_dilation_1_weights;
    const int16_t *input_data = int16xint8_dilation_1_input;
    const int16_t *output_ref = int16xint8_dilation_1_output_ref;
    const int32_t output_ref_size = INT16XINT8_DILATION_1_DST_SIZE;

    input_dims.n = INT16XINT8_DILATION_1_INPUT_BATCHES;
    input_dims.w = INT16XINT8_DILATION_1_INPUT_W;
    input_dims.h = INT16XINT8_DILATION_1_INPUT_H;
    input_dims.c = INT16XINT8_DILATION_1_IN_CH;
    filter_dims.w = INT16XINT8_DILATION_1_FILTER_X;
    filter_dims.h = INT16XINT8_DILATION_1_FILTER_Y;
    output_dims.w = INT16XINT8_DILATION_1_OUTPUT_W;
    output_dims.h = INT16XINT8_DILATION_1_OUTPUT_H;
    output_dims.c = INT16XINT8_DILATION_1_OUT_CH;

    conv_params.padding.w = INT16XINT8_DILATION_1_PAD_X;
    conv_params.padding.h = INT16XINT8_DILATION_1_PAD_Y;
    conv_params.stride.w = INT16XINT8_DILATION_1_STRIDE_X;
    conv_params.stride.h = INT16XINT8_DILATION_1_STRIDE_Y;
    conv_params.dilation.w = INT16XINT8_DILATION_1_DILATION_X;
    conv_params.dilation.h = INT16XINT8_DILATION_1_DILATION_Y;

    conv_params.input_offset = INT16XINT8_DILATION_1_INPUT_OFFSET;
    conv_params.output_offset = INT16XINT8_DILATION_1_OUTPUT_OFFSET;
    conv_params.activation.min = INT16XINT8_DILATION_1_OUT_ACTIVATION_MIN;
    conv_params.activation.max = INT16XINT8_DILATION_1_OUT_ACTIVATION_MAX;
    quant_params.multiplier = (int32_t *)int16xint8_dilation_1_output_mult;
    quant_params.shift = (int32_t *)int16xint8_dilation_1_output_shift;

    int buf_size = arm_convolve_s16_get_buffer_size(&input_dims, &filter_dims);
    ctx.buf = malloc(buf_size);

    arm_cmsis_nn_status result = arm_convolve_s16(&ctx,
                                                  &conv_params,
                                                  &quant_params,
                                                  &input_dims,
                                                  input_data,
                                                  &filter_dims,
                                                  kernel_data,
                                                  &bias_dims,
                                                  &bias_data,
                                                  &output_dims,
                                                  output);
    if (ctx.buf)
    {
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(ARM_CMSIS_NN_SUCCESS, result);
    TEST_ASSERT_TRUE(validate_s16(output, output_ref, output_ref_size));
    memset(output, 0, sizeof(output));

    buf_size = arm_convolve_wrapper_s16_get_buffer_size(&conv_params, &input_dims, &filter_dims, &output_dims);
    ctx.buf = malloc(buf_size);

    result = arm_convolve_wrapper_s16(&ctx,
                                      &conv_params,
                                      &quant_params,
                                      &input_dims,
                                      input_data,
                                      &filter_dims,
                                      kernel_data,
                                      &bias_dims,
                                      &bias_data,
                                      &output_dims,
                                      output);

    if (ctx.buf)
    {
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(ARM_CMSIS_NN_SUCCESS, result);
    TEST_ASSERT_TRUE(validate_s16(output, output_ref, output_ref_size));
}

void int16xint8_dilation_2_arm_convolve_s16(void)
{
    int16_t output[INT16XINT8_DILATION_2_DST_SIZE] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_conv_params conv_params;
    cmsis_nn_per_channel_quant_params quant_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims bias_dims;
    cmsis_nn_dims output_dims;

    const int64_t *int64_bias_data = int16xint8_dilation_2_biases;
    const cmsis_nn_bias_data bias_data = {int64_bias_data, false};
    const int8_t *kernel_data = int16xint8_dilation_2_weights;
    const int16_t *input_data = int16xint8_dilation_2_input;
    const int16_t *output_ref = int16xint8_dilation_2_output_ref;
    const int32_t output_ref_size = INT16XINT8_DILATION_2_DST_SIZE;

    input_dims.n = INT16XINT8_DILATION_2_INPUT_BATCHES;
    input_dims.w = INT16XINT8_DILATION_2_INPUT_W;
    input_dims.h = INT16XINT8_DILATION_2_INPUT_H;
    input_dims.c = INT16XINT8_DILATION_2_IN_CH;
    filter_dims.w = INT16XINT8_DILATION_2_FILTER_X;
    filter_dims.h = INT16XINT8_DILATION_2_FILTER_Y;
    output_dims.w = INT16XINT8_DILATION_2_OUTPUT_W;
    output_dims.h = INT16XINT8_DILATION_2_OUTPUT_H;
    output_dims.c = INT16XINT8_DILATION_2_OUT_CH;

    conv_params.padding.w = INT16XINT8_DILATION_2_PAD_X;
    conv_params.padding.h = INT16XINT8_DILATION_2_PAD_Y;
    conv_params.stride.w = INT16XINT8_DILATION_2_STRIDE_X;
    conv_params.stride.h = INT16XINT8_DILATION_2_STRIDE_Y;
    conv_params.dilation.w = INT16XINT8_DILATION_2_DILATION_X;
    conv_params.dilation.h = INT16XINT8_DILATION_2_DILATION_Y;

    conv_params.input_offset = INT16XINT8_DILATION_2_INPUT_OFFSET;
    conv_params.output_offset = INT16XINT8_DILATION_2_OUTPUT_OFFSET;
    conv_params.activation.min = INT16XINT8_DILATION_2_OUT_ACTIVATION_MIN;
    conv_params.activation.max = INT16XINT8_DILATION_2_OUT_ACTIVATION_MAX;
    quant_params.multiplier = (int32_t *)int16xint8_dilation_2_output_mult;
    quant_params.shift = (int32_t *)int16xint8_dilation_2_output_shift;

    int buf_size = arm_convolve_s16_get_buffer_size(&input_dims, &filter_dims);
    ctx.buf = malloc(buf_size);

    arm_cmsis_nn_status result = arm_convolve_s16(&ctx,
                                                  &conv_params,
                                                  &quant_params,
                                                  &input_dims,
                                                  input_data,
                                                  &filter_dims,
                                                  kernel_data,
                                                  &bias_dims,
                                                  &bias_data,
                                                  &output_dims,
                                                  output);
    if (ctx.buf)
    {
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(ARM_CMSIS_NN_SUCCESS, result);
    TEST_ASSERT_TRUE(validate_s16(output, output_ref, output_ref_size));
    memset(output, 0, sizeof(output));

    buf_size = arm_convolve_wrapper_s16_get_buffer_size(&conv_params, &input_dims, &filter_dims, &output_dims);
    ctx.buf = malloc(buf_size);

    result = arm_convolve_wrapper_s16(&ctx,
                                      &conv_params,
                                      &quant_params,
                                      &input_dims,
                                      input_data,
                                      &filter_dims,
                                      kernel_data,
                                      &bias_dims,
                                      &bias_data,
                                      &output_dims,
                                      output);

    if (ctx.buf)
    {
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(ARM_CMSIS_NN_SUCCESS, result);
    TEST_ASSERT_TRUE(validate_s16(output, output_ref, output_ref_size));
}

void int16xint8_dilation_3_arm_convolve_s16(void)
{
    int16_t output[INT16XINT8_DILATION_3_DST_SIZE] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_conv_params conv_params;
    cmsis_nn_per_channel_quant_params quant_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims bias_dims;
    cmsis_nn_dims output_dims;

    const int64_t *int64_bias_data = int16xint8_dilation_3_biases;
    const cmsis_nn_bias_data bias_data = {int64_bias_data, false};
    const int8_t *kernel_data = int16xint8_dilation_3_weights;
    const int16_t *input_data = int16xint8_dilation_3_input;
    const int16_t *output_ref = int16xint8_dilation_3_output_ref;
    const int32_t output_ref_size = INT16XINT8_DILATION_3_DST_SIZE;

    input_dims.n = INT16XINT8_DILATION_3_INPUT_BATCHES;
    input_dims.w = INT16XINT8_DILATION_3_INPUT_W;
    input_dims.h = INT16XINT8_DILATION_3_INPUT_H;
    input_dims.c = INT16XINT8_DILATION_3_IN_CH;
    filter_dims.w = INT16XINT8_DILATION_3_FILTER_X;
    filter_dims.h = INT16XINT8_DILATION_3_FILTER_Y;
    output_dims.w = INT16XINT8_DILATION_3_OUTPUT_W;
    output_dims.h = INT16XINT8_DILATION_3_OUTPUT_H;
    output_dims.c = INT16XINT8_DILATION_3_OUT_CH;

    conv_params.padding.w = INT16XINT8_DILATION_3_PAD_X;
    conv_params.padding.h = INT16XINT8_DILATION_3_PAD_Y;
    conv_params.stride.w = INT16XINT8_DILATION_3_STRIDE_X;
    conv_params.stride.h = INT16XINT8_DILATION_3_STRIDE_Y;
    conv_params.dilation.w = INT16XINT8_DILATION_3_DILATION_X;
    conv_params.dilation.h = INT16XINT8_DILATION_3_DILATION_Y;

    conv_params.input_offset = INT16XINT8_DILATION_3_INPUT_OFFSET;
    conv_params.output_offset = INT16XINT8_DILATION_3_OUTPUT_OFFSET;
    conv_params.activation.min = INT16XINT8_DILATION_3_OUT_ACTIVATION_MIN;
    conv_params.activation.max = INT16XINT8_DILATION_3_OUT_ACTIVATION_MAX;
    quant_params.multiplier = (int32_t *)int16xint8_dilation_3_output_mult;
    quant_params.shift = (int32_t *)int16xint8_dilation_3_output_shift;

    int buf_size = arm_convolve_s16_get_buffer_size(&input_dims, &filter_dims);
    ctx.buf = malloc(buf_size);

    arm_cmsis_nn_status result = arm_convolve_s16(&ctx,
                                                  &conv_params,
                                                  &quant_params,
                                                  &input_dims,
                                                  input_data,
                                                  &filter_dims,
                                                  kernel_data,
                                                  &bias_dims,
                                                  &bias_data,
                                                  &output_dims,
                                                  output);
    if (ctx.buf)
    {
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(ARM_CMSIS_NN_SUCCESS, result);
    TEST_ASSERT_TRUE(validate_s16(output, output_ref, output_ref_size));
    memset(output, 0, sizeof(output));

    buf_size = arm_convolve_wrapper_s16_get_buffer_size(&conv_params, &input_dims, &filter_dims, &output_dims);
    ctx.buf = malloc(buf_size);

    result = arm_convolve_wrapper_s16(&ctx,
                                      &conv_params,
                                      &quant_params,
                                      &input_dims,
                                      input_data,
                                      &filter_dims,
                                      kernel_data,
                                      &bias_dims,
                                      &bias_data,
                                      &output_dims,
                                      output);

    if (ctx.buf)
    {
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(ARM_CMSIS_NN_SUCCESS, result);
    TEST_ASSERT_TRUE(validate_s16(output, output_ref, output_ref_size));
}

void buffer_size_arm_convolve_s16(void)
{
    cmsis_nn_conv_params conv_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims output_dims;

    input_dims.n = INT16XINT8_DILATION_3_INPUT_BATCHES;
    input_dims.w = INT16XINT8_DILATION_3_INPUT_W;
    input_dims.h = INT16XINT8_DILATION_3_INPUT_H;
    input_dims.c = INT16XINT8_DILATION_3_IN_CH;
    filter_dims.w = INT16XINT8_DILATION_3_FILTER_X;
    filter_dims.h = INT16XINT8_DILATION_3_FILTER_Y;
    output_dims.w = INT16XINT8_DILATION_3_OUTPUT_W;
    output_dims.h = INT16XINT8_DILATION_3_OUTPUT_H;
    output_dims.c = INT16XINT8_DILATION_3_OUT_CH;

    conv_params.padding.w = INT16XINT8_DILATION_3_PAD_X;
    conv_params.padding.h = INT16XINT8_DILATION_3_PAD_Y;
    conv_params.stride.w = INT16XINT8_DILATION_3_STRIDE_X;
    conv_params.stride.h = INT16XINT8_DILATION_3_STRIDE_Y;
    conv_params.dilation.w = INT16XINT8_DILATION_3_DILATION_X;
    conv_params.dilation.h = INT16XINT8_DILATION_3_DILATION_Y;

    conv_params.input_offset = INT16XINT8_DILATION_3_INPUT_OFFSET;
    conv_params.output_offset = INT16XINT8_DILATION_3_OUTPUT_OFFSET;
    conv_params.activation.min = INT16XINT8_DILATION_3_OUT_ACTIVATION_MIN;
    conv_params.activation.max = INT16XINT8_DILATION_3_OUT_ACTIVATION_MAX;

    const int32_t buf_size = arm_convolve_s16_get_buffer_size(&input_dims, &filter_dims);
    const int32_t wrapper_buf_size =
        arm_convolve_wrapper_s16_get_buffer_size(&conv_params, &input_dims, &filter_dims, &output_dims);

    TEST_ASSERT_EQUAL(wrapper_buf_size, buf_size);
}

void buffer_size_mve_arm_convolve_s16(void)
{
#if defined(ARM_MATH_MVEI)
    cmsis_nn_conv_params conv_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims output_dims;

    input_dims.n = INT16XINT8_DILATION_3_INPUT_BATCHES;
    input_dims.w = INT16XINT8_DILATION_3_INPUT_W;
    input_dims.h = INT16XINT8_DILATION_3_INPUT_H;
    input_dims.c = INT16XINT8_DILATION_3_IN_CH;
    filter_dims.w = INT16XINT8_DILATION_3_FILTER_X;
    filter_dims.h = INT16XINT8_DILATION_3_FILTER_Y;
    output_dims.w = INT16XINT8_DILATION_3_OUTPUT_W;
    output_dims.h = INT16XINT8_DILATION_3_OUTPUT_H;
    output_dims.c = INT16XINT8_DILATION_3_OUT_CH;

    conv_params.padding.w = INT16XINT8_DILATION_3_PAD_X;
    conv_params.padding.h = INT16XINT8_DILATION_3_PAD_Y;
    conv_params.stride.w = INT16XINT8_DILATION_3_STRIDE_X;
    conv_params.stride.h = INT16XINT8_DILATION_3_STRIDE_Y;
    conv_params.dilation.w = INT16XINT8_DILATION_3_DILATION_X;
    conv_params.dilation.h = INT16XINT8_DILATION_3_DILATION_Y;

    conv_params.input_offset = INT16XINT8_DILATION_3_INPUT_OFFSET;
    conv_params.output_offset = INT16XINT8_DILATION_3_OUTPUT_OFFSET;
    conv_params.activation.min = INT16XINT8_DILATION_3_OUT_ACTIVATION_MIN;
    conv_params.activation.max = INT16XINT8_DILATION_3_OUT_ACTIVATION_MAX;

    const int32_t wrapper_buf_size =
        arm_convolve_wrapper_s16_get_buffer_size(&conv_params, &input_dims, &filter_dims, &output_dims);
    const int32_t mve_wrapper_buf_size =
        arm_convolve_wrapper_s16_get_buffer_size_mve(&conv_params, &input_dims, &filter_dims, &output_dims);

    TEST_ASSERT_EQUAL(wrapper_buf_size, mve_wrapper_buf_size);
#endif
}

void buffer_size_dsp_arm_convolve_s16(void)
{
#if defined(ARM_MATH_DSP) && !defined(ARM_MATH_MVEI)
    cmsis_nn_conv_params conv_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims output_dims;

    input_dims.n = INT16XINT8_DILATION_3_INPUT_BATCHES;
    input_dims.w = INT16XINT8_DILATION_3_INPUT_W;
    input_dims.h = INT16XINT8_DILATION_3_INPUT_H;
    input_dims.c = INT16XINT8_DILATION_3_IN_CH;
    filter_dims.w = INT16XINT8_DILATION_3_FILTER_X;
    filter_dims.h = INT16XINT8_DILATION_3_FILTER_Y;
    output_dims.w = INT16XINT8_DILATION_3_OUTPUT_W;
    output_dims.h = INT16XINT8_DILATION_3_OUTPUT_H;
    output_dims.c = INT16XINT8_DILATION_3_OUT_CH;

    conv_params.padding.w = INT16XINT8_DILATION_3_PAD_X;
    conv_params.padding.h = INT16XINT8_DILATION_3_PAD_Y;
    conv_params.stride.w = INT16XINT8_DILATION_3_STRIDE_X;
    conv_params.stride.h = INT16XINT8_DILATION_3_STRIDE_Y;
    conv_params.dilation.w = INT16XINT8_DILATION_3_DILATION_X;
    conv_params.dilation.h = INT16XINT8_DILATION_3_DILATION_Y;

    conv_params.input_offset = INT16XINT8_DILATION_3_INPUT_OFFSET;
    conv_params.output_offset = INT16XINT8_DILATION_3_OUTPUT_OFFSET;
    conv_params.activation.min = INT16XINT8_DILATION_3_OUT_ACTIVATION_MIN;
    conv_params.activation.max = INT16XINT8_DILATION_3_OUT_ACTIVATION_MAX;

    const int32_t wrapper_buf_size =
        arm_convolve_wrapper_s16_get_buffer_size(&conv_params, &input_dims, &filter_dims, &output_dims);
    const int32_t dsp_wrapper_buf_size =
        arm_convolve_wrapper_s16_get_buffer_size_dsp(&conv_params, &input_dims, &filter_dims, &output_dims);

    TEST_ASSERT_EQUAL(wrapper_buf_size, dsp_wrapper_buf_size);
#endif
}

void int16xint8_spill_arm_convolve_s16(void)
{
    int16_t output[INT16XINT8_SPILL_DST_SIZE] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_conv_params conv_params;
    cmsis_nn_per_channel_quant_params quant_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims bias_dims;
    cmsis_nn_dims output_dims;

    const int64_t *int64_bias_data = int16xint8_spill_biases;
    const cmsis_nn_bias_data bias_data = {int64_bias_data, false};
    const int8_t *kernel_data = int16xint8_spill_weights;
    const int16_t *input_data = int16xint8_spill_input;
    const int16_t *output_ref = int16xint8_spill_output_ref;
    const int32_t output_ref_size = INT16XINT8_SPILL_DST_SIZE;

    input_dims.n = INT16XINT8_SPILL_INPUT_BATCHES;
    input_dims.w = INT16XINT8_SPILL_INPUT_W;
    input_dims.h = INT16XINT8_SPILL_INPUT_H;
    input_dims.c = INT16XINT8_SPILL_IN_CH;
    filter_dims.w = INT16XINT8_SPILL_FILTER_X;
    filter_dims.h = INT16XINT8_SPILL_FILTER_Y;
    output_dims.w = INT16XINT8_SPILL_OUTPUT_W;
    output_dims.h = INT16XINT8_SPILL_OUTPUT_H;
    output_dims.c = INT16XINT8_SPILL_OUT_CH;

    conv_params.padding.w = INT16XINT8_SPILL_PAD_X;
    conv_params.padding.h = INT16XINT8_SPILL_PAD_Y;
    conv_params.stride.w = INT16XINT8_SPILL_STRIDE_X;
    conv_params.stride.h = INT16XINT8_SPILL_STRIDE_Y;
    conv_params.dilation.w = INT16XINT8_SPILL_DILATION_X;
    conv_params.dilation.h = INT16XINT8_SPILL_DILATION_Y;

    conv_params.input_offset = 0;
    conv_params.output_offset = 0;
    conv_params.activation.min = INT16XINT8_SPILL_OUT_ACTIVATION_MIN;
    conv_params.activation.max = INT16XINT8_SPILL_OUT_ACTIVATION_MAX;
    quant_params.multiplier = (int32_t *)int16xint8_spill_output_mult;
    quant_params.shift = (int32_t *)int16xint8_spill_output_shift;

    int buf_size = arm_convolve_s16_get_buffer_size(&input_dims, &filter_dims);
    ctx.buf = malloc(buf_size);
    arm_cmsis_nn_status result;
    result = arm_convolve_s16(&ctx,
                              &conv_params,
                              &quant_params,
                              &input_dims,
                              input_data,
                              &filter_dims,
                              kernel_data,
                              &bias_dims,
                              &bias_data,
                              &output_dims,
                              output);
    if (ctx.buf)
    {
        // The caller is responsible to clear the scratch buffers for security reasons if applicable.
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(ARM_CMSIS_NN_SUCCESS, result);
    TEST_ASSERT_TRUE(validate_s16(output, output_ref, output_ref_size));
    memset(output, 0, sizeof(output));

    buf_size = arm_convolve_wrapper_s16_get_buffer_size(&conv_params, &input_dims, &filter_dims, &output_dims);
    ctx.buf = malloc(buf_size);

    result = arm_convolve_wrapper_s16(&ctx,
                                      &conv_params,
                                      &quant_params,
                                      &input_dims,
                                      input_data,
                                      &filter_dims,
                                      kernel_data,
                                      &bias_dims,
                                      &bias_data,
                                      &output_dims,
                                      output);
    if (ctx.buf)
    {
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(ARM_CMSIS_NN_SUCCESS, result);
    TEST_ASSERT_TRUE(validate_s16(output, output_ref, output_ref_size));
}

void int16xint8_spill2_arm_convolve_s16(void)
{
    int16_t output[INT16XINT8_SPILL2_DST_SIZE] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_conv_params conv_params;
    cmsis_nn_per_channel_quant_params quant_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims bias_dims;
    cmsis_nn_dims output_dims;

    const int64_t *int64_bias_data = int16xint8_spill2_biases;
    const cmsis_nn_bias_data bias_data = {int64_bias_data, false};
    const int8_t *kernel_data = int16xint8_spill2_weights;
    const int16_t *input_data = int16xint8_spill2_input;
    const int16_t *output_ref = int16xint8_spill2_output_ref;
    const int32_t output_ref_size = INT16XINT8_SPILL2_DST_SIZE;

    input_dims.n = INT16XINT8_SPILL2_INPUT_BATCHES;
    input_dims.w = INT16XINT8_SPILL2_INPUT_W;
    input_dims.h = INT16XINT8_SPILL2_INPUT_H;
    input_dims.c = INT16XINT8_SPILL2_IN_CH;
    filter_dims.w = INT16XINT8_SPILL2_FILTER_X;
    filter_dims.h = INT16XINT8_SPILL2_FILTER_Y;
    output_dims.w = INT16XINT8_SPILL2_OUTPUT_W;
    output_dims.h = INT16XINT8_SPILL2_OUTPUT_H;
    output_dims.c = INT16XINT8_SPILL2_OUT_CH;

    conv_params.padding.w = INT16XINT8_SPILL2_PAD_X;
    conv_params.padding.h = INT16XINT8_SPILL2_PAD_Y;
    conv_params.stride.w = INT16XINT8_SPILL2_STRIDE_X;
    conv_params.stride.h = INT16XINT8_SPILL2_STRIDE_Y;
    conv_params.dilation.w = INT16XINT8_SPILL2_DILATION_X;
    conv_params.dilation.h = INT16XINT8_SPILL2_DILATION_Y;

    conv_params.input_offset = 0;
    conv_params.output_offset = 0;
    conv_params.activation.min = INT16XINT8_SPILL2_OUT_ACTIVATION_MIN;
    conv_params.activation.max = INT16XINT8_SPILL2_OUT_ACTIVATION_MAX;
    quant_params.multiplier = (int32_t *)int16xint8_spill2_output_mult;
    quant_params.shift = (int32_t *)int16xint8_spill2_output_shift;

    int buf_size = arm_convolve_s16_get_buffer_size(&input_dims, &filter_dims);
    ctx.buf = malloc(buf_size);
    arm_cmsis_nn_status result;
    result = arm_convolve_s16(&ctx,
                              &conv_params,
                              &quant_params,
                              &input_dims,
                              input_data,
                              &filter_dims,
                              kernel_data,
                              &bias_dims,
                              &bias_data,
                              &output_dims,
                              output);
    if (ctx.buf)
    {
        // The caller is responsible to clear the scratch buffers for security reasons if applicable.
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(ARM_CMSIS_NN_SUCCESS, result);
    TEST_ASSERT_TRUE(validate_s16(output, output_ref, output_ref_size));
    memset(output, 0, sizeof(output));

    buf_size = arm_convolve_wrapper_s16_get_buffer_size(&conv_params, &input_dims, &filter_dims, &output_dims);
    ctx.buf = malloc(buf_size);

    result = arm_convolve_wrapper_s16(&ctx,
                                      &conv_params,
                                      &quant_params,
                                      &input_dims,
                                      input_data,
                                      &filter_dims,
                                      kernel_data,
                                      &bias_dims,
                                      &bias_data,
                                      &output_dims,
                                      output);
    if (ctx.buf)
    {
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(ARM_CMSIS_NN_SUCCESS, result);
    TEST_ASSERT_TRUE(validate_s16(output, output_ref, output_ref_size));
}

void int16xint8xint32_1_arm_convolve_s16(void)
{
    int16_t output[INT16XINT8XINT32_1_DST_SIZE] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_conv_params conv_params;
    cmsis_nn_per_channel_quant_params quant_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims bias_dims;
    cmsis_nn_dims output_dims;

    const int32_t *int32_bias_data = int16xint8xint32_1_biases;
    const cmsis_nn_bias_data bias_data = {int32_bias_data, true};
    const int8_t *kernel_data = int16xint8xint32_1_weights;
    const int16_t *input_data = int16xint8xint32_1_input;
    const int16_t *output_ref = int16xint8xint32_1_output_ref;
    const int32_t output_ref_size = INT16XINT8XINT32_1_DST_SIZE;

    input_dims.n = INT16XINT8XINT32_1_INPUT_BATCHES;
    input_dims.w = INT16XINT8XINT32_1_INPUT_W;
    input_dims.h = INT16XINT8XINT32_1_INPUT_H;
    input_dims.c = INT16XINT8XINT32_1_IN_CH;
    filter_dims.w = INT16XINT8XINT32_1_FILTER_X;
    filter_dims.h = INT16XINT8XINT32_1_FILTER_Y;
    output_dims.w = INT16XINT8XINT32_1_OUTPUT_W;
    output_dims.h = INT16XINT8XINT32_1_OUTPUT_H;
    output_dims.c = INT16XINT8XINT32_1_OUT_CH;

    conv_params.padding.w = INT16XINT8XINT32_1_PAD_X;
    conv_params.padding.h = INT16XINT8XINT32_1_PAD_Y;
    conv_params.stride.w = INT16XINT8XINT32_1_STRIDE_X;
    conv_params.stride.h = INT16XINT8XINT32_1_STRIDE_Y;
    conv_params.dilation.w = INT16XINT8XINT32_1_DILATION_X;
    conv_params.dilation.h = INT16XINT8XINT32_1_DILATION_Y;

    conv_params.input_offset = 0;
    conv_params.output_offset = 0;
    conv_params.activation.min = INT16XINT8XINT32_1_OUT_ACTIVATION_MIN;
    conv_params.activation.max = INT16XINT8XINT32_1_OUT_ACTIVATION_MAX;
    quant_params.multiplier = (int32_t *)int16xint8xint32_1_output_mult;
    quant_params.shift = (int32_t *)int16xint8xint32_1_output_shift;

    int buf_size = arm_convolve_s16_get_buffer_size(&input_dims, &filter_dims);
    ctx.buf = malloc(buf_size);
    arm_cmsis_nn_status result;
    result = arm_convolve_s16(&ctx,
                              &conv_params,
                              &quant_params,
                              &input_dims,
                              input_data,
                              &filter_dims,
                              kernel_data,
                              &bias_dims,
                              &bias_data,
                              &output_dims,
                              output);
    if (ctx.buf)
    {
        // The caller is responsible to clear the scratch buffers for security reasons if applicable.
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(ARM_CMSIS_NN_SUCCESS, result);
    TEST_ASSERT_TRUE(validate_s16(output, output_ref, output_ref_size));
    memset(output, 0, sizeof(output));

    buf_size = arm_convolve_wrapper_s16_get_buffer_size(&conv_params, &input_dims, &filter_dims, &output_dims);
    ctx.buf = malloc(buf_size);

    result = arm_convolve_wrapper_s16(&ctx,
                                      &conv_params,
                                      &quant_params,
                                      &input_dims,
                                      input_data,
                                      &filter_dims,
                                      kernel_data,
                                      &bias_dims,
                                      &bias_data,
                                      &output_dims,
                                      output);
    if (ctx.buf)
    {
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(ARM_CMSIS_NN_SUCCESS, result);
    TEST_ASSERT_TRUE(validate_s16(output, output_ref, output_ref_size));
}

void int16xint8xint32_2_arm_convolve_s16(void)
{
    int16_t output[INT16XINT8XINT32_2_DST_SIZE] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_conv_params conv_params;
    cmsis_nn_per_channel_quant_params quant_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims bias_dims;
    cmsis_nn_dims output_dims;

    const int32_t *int32_bias_data = int16xint8xint32_2_biases;
    const cmsis_nn_bias_data bias_data = {int32_bias_data, true};
    const int8_t *kernel_data = int16xint8xint32_2_weights;
    const int16_t *input_data = int16xint8xint32_2_input;
    const int16_t *output_ref = int16xint8xint32_2_output_ref;
    const int32_t output_ref_size = INT16XINT8XINT32_2_DST_SIZE;

    input_dims.n = INT16XINT8XINT32_2_INPUT_BATCHES;
    input_dims.w = INT16XINT8XINT32_2_INPUT_W;
    input_dims.h = INT16XINT8XINT32_2_INPUT_H;
    input_dims.c = INT16XINT8XINT32_2_IN_CH;
    filter_dims.w = INT16XINT8XINT32_2_FILTER_X;
    filter_dims.h = INT16XINT8XINT32_2_FILTER_Y;
    output_dims.w = INT16XINT8XINT32_2_OUTPUT_W;
    output_dims.h = INT16XINT8XINT32_2_OUTPUT_H;
    output_dims.c = INT16XINT8XINT32_2_OUT_CH;

    conv_params.padding.w = INT16XINT8XINT32_2_PAD_X;
    conv_params.padding.h = INT16XINT8XINT32_2_PAD_Y;
    conv_params.stride.w = INT16XINT8XINT32_2_STRIDE_X;
    conv_params.stride.h = INT16XINT8XINT32_2_STRIDE_Y;
    conv_params.dilation.w = INT16XINT8XINT32_2_DILATION_X;
    conv_params.dilation.h = INT16XINT8XINT32_2_DILATION_Y;

    conv_params.input_offset = 0;
    conv_params.output_offset = 0;
    conv_params.activation.min = INT16XINT8XINT32_2_OUT_ACTIVATION_MIN;
    conv_params.activation.max = INT16XINT8XINT32_2_OUT_ACTIVATION_MAX;
    quant_params.multiplier = (int32_t *)int16xint8xint32_2_output_mult;
    quant_params.shift = (int32_t *)int16xint8xint32_2_output_shift;

    int buf_size = arm_convolve_s16_get_buffer_size(&input_dims, &filter_dims);
    ctx.buf = malloc(buf_size);
    arm_cmsis_nn_status result;
    result = arm_convolve_s16(&ctx,
                              &conv_params,
                              &quant_params,
                              &input_dims,
                              input_data,
                              &filter_dims,
                              kernel_data,
                              &bias_dims,
                              &bias_data,
                              &output_dims,
                              output);
    if (ctx.buf)
    {
        // The caller is responsible to clear the scratch buffers for security reasons if applicable.
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(ARM_CMSIS_NN_SUCCESS, result);
    TEST_ASSERT_TRUE(validate_s16(output, output_ref, output_ref_size));
    memset(output, 0, sizeof(output));

    buf_size = arm_convolve_wrapper_s16_get_buffer_size(&conv_params, &input_dims, &filter_dims, &output_dims);
    ctx.buf = malloc(buf_size);

    result = arm_convolve_wrapper_s16(&ctx,
                                      &conv_params,
                                      &quant_params,
                                      &input_dims,
                                      input_data,
                                      &filter_dims,
                                      kernel_data,
                                      &bias_dims,
                                      &bias_data,
                                      &output_dims,
                                      output);
    if (ctx.buf)
    {
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(ARM_CMSIS_NN_SUCCESS, result);
    TEST_ASSERT_TRUE(validate_s16(output, output_ref, output_ref_size));
}

void int16xint8xint32_3_arm_convolve_s16(void)
{
    int16_t output[INT16XINT8XINT32_3_DST_SIZE] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_conv_params conv_params;
    cmsis_nn_per_channel_quant_params quant_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims bias_dims;
    cmsis_nn_dims output_dims;

    const int32_t *int32_bias_data = int16xint8xint32_3_biases;
    const cmsis_nn_bias_data bias_data = {int32_bias_data, true};
    const int8_t *kernel_data = int16xint8xint32_3_weights;
    const int16_t *input_data = int16xint8xint32_3_input;
    const int16_t *output_ref = int16xint8xint32_3_output_ref;
    const int32_t output_ref_size = INT16XINT8XINT32_3_DST_SIZE;

    input_dims.n = INT16XINT8XINT32_3_INPUT_BATCHES;
    input_dims.w = INT16XINT8XINT32_3_INPUT_W;
    input_dims.h = INT16XINT8XINT32_3_INPUT_H;
    input_dims.c = INT16XINT8XINT32_3_IN_CH;
    filter_dims.w = INT16XINT8XINT32_3_FILTER_X;
    filter_dims.h = INT16XINT8XINT32_3_FILTER_Y;
    output_dims.w = INT16XINT8XINT32_3_OUTPUT_W;
    output_dims.h = INT16XINT8XINT32_3_OUTPUT_H;
    output_dims.c = INT16XINT8XINT32_3_OUT_CH;

    conv_params.padding.w = INT16XINT8XINT32_3_PAD_X;
    conv_params.padding.h = INT16XINT8XINT32_3_PAD_Y;
    conv_params.stride.w = INT16XINT8XINT32_3_STRIDE_X;
    conv_params.stride.h = INT16XINT8XINT32_3_STRIDE_Y;
    conv_params.dilation.w = INT16XINT8XINT32_3_DILATION_X;
    conv_params.dilation.h = INT16XINT8XINT32_3_DILATION_Y;

    conv_params.input_offset = 0;
    conv_params.output_offset = 0;
    conv_params.activation.min = INT16XINT8XINT32_3_OUT_ACTIVATION_MIN;
    conv_params.activation.max = INT16XINT8XINT32_3_OUT_ACTIVATION_MAX;
    quant_params.multiplier = (int32_t *)int16xint8xint32_3_output_mult;
    quant_params.shift = (int32_t *)int16xint8xint32_3_output_shift;

    int buf_size = arm_convolve_s16_get_buffer_size(&input_dims, &filter_dims);
    ctx.buf = malloc(buf_size);
    arm_cmsis_nn_status result;
    result = arm_convolve_s16(&ctx,
                              &conv_params,
                              &quant_params,
                              &input_dims,
                              input_data,
                              &filter_dims,
                              kernel_data,
                              &bias_dims,
                              &bias_data,
                              &output_dims,
                              output);
    if (ctx.buf)
    {
        // The caller is responsible to clear the scratch buffers for security reasons if applicable.
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(ARM_CMSIS_NN_SUCCESS, result);
    TEST_ASSERT_TRUE(validate_s16(output, output_ref, output_ref_size));
    memset(output, 0, sizeof(output));

    buf_size = arm_convolve_wrapper_s16_get_buffer_size(&conv_params, &input_dims, &filter_dims, &output_dims);
    ctx.buf = malloc(buf_size);

    result = arm_convolve_wrapper_s16(&ctx,
                                      &conv_params,
                                      &quant_params,
                                      &input_dims,
                                      input_data,
                                      &filter_dims,
                                      kernel_data,
                                      &bias_dims,
                                      &bias_data,
                                      &output_dims,
                                      output);
    if (ctx.buf)
    {
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(ARM_CMSIS_NN_SUCCESS, result);
    TEST_ASSERT_TRUE(validate_s16(output, output_ref, output_ref_size));
}

void int16xint8xint32_4_arm_convolve_s16(void)
{
    int16_t output[INT16XINT8XINT32_4_DST_SIZE] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_conv_params conv_params;
    cmsis_nn_per_channel_quant_params quant_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims bias_dims;
    cmsis_nn_dims output_dims;

    const int32_t *int32_bias_data = int16xint8xint32_4_biases;
    const cmsis_nn_bias_data bias_data = {int32_bias_data, true};
    const int8_t *kernel_data = int16xint8xint32_4_weights;
    const int16_t *input_data = int16xint8xint32_4_input;
    const int16_t *output_ref = int16xint8xint32_4_output_ref;
    const int32_t output_ref_size = INT16XINT8XINT32_4_DST_SIZE;

    input_dims.n = INT16XINT8XINT32_4_INPUT_BATCHES;
    input_dims.w = INT16XINT8XINT32_4_INPUT_W;
    input_dims.h = INT16XINT8XINT32_4_INPUT_H;
    input_dims.c = INT16XINT8XINT32_4_IN_CH;
    filter_dims.w = INT16XINT8XINT32_4_FILTER_X;
    filter_dims.h = INT16XINT8XINT32_4_FILTER_Y;
    output_dims.w = INT16XINT8XINT32_4_OUTPUT_W;
    output_dims.h = INT16XINT8XINT32_4_OUTPUT_H;
    output_dims.c = INT16XINT8XINT32_4_OUT_CH;

    conv_params.padding.w = INT16XINT8XINT32_4_PAD_X;
    conv_params.padding.h = INT16XINT8XINT32_4_PAD_Y;
    conv_params.stride.w = INT16XINT8XINT32_4_STRIDE_X;
    conv_params.stride.h = INT16XINT8XINT32_4_STRIDE_Y;
    conv_params.dilation.w = INT16XINT8XINT32_4_DILATION_X;
    conv_params.dilation.h = INT16XINT8XINT32_4_DILATION_Y;

    conv_params.input_offset = 0;
    conv_params.output_offset = 0;
    conv_params.activation.min = INT16XINT8XINT32_4_OUT_ACTIVATION_MIN;
    conv_params.activation.max = INT16XINT8XINT32_4_OUT_ACTIVATION_MAX;
    quant_params.multiplier = (int32_t *)int16xint8xint32_4_output_mult;
    quant_params.shift = (int32_t *)int16xint8xint32_4_output_shift;

    int buf_size = arm_convolve_s16_get_buffer_size(&input_dims, &filter_dims);
    ctx.buf = malloc(buf_size);
    arm_cmsis_nn_status result;
    result = arm_convolve_s16(&ctx,
                              &conv_params,
                              &quant_params,
                              &input_dims,
                              input_data,
                              &filter_dims,
                              kernel_data,
                              &bias_dims,
                              &bias_data,
                              &output_dims,
                              output);
    if (ctx.buf)
    {
        // The caller is responsible to clear the scratch buffers for security reasons if applicable.
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(ARM_CMSIS_NN_SUCCESS, result);
    TEST_ASSERT_TRUE(validate_s16(output, output_ref, output_ref_size));
    memset(output, 0, sizeof(output));

    buf_size = arm_convolve_wrapper_s16_get_buffer_size(&conv_params, &input_dims, &filter_dims, &output_dims);
    ctx.buf = malloc(buf_size);

    result = arm_convolve_wrapper_s16(&ctx,
                                      &conv_params,
                                      &quant_params,
                                      &input_dims,
                                      input_data,
                                      &filter_dims,
                                      kernel_data,
                                      &bias_dims,
                                      &bias_data,
                                      &output_dims,
                                      output);
    if (ctx.buf)
    {
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(ARM_CMSIS_NN_SUCCESS, result);
    TEST_ASSERT_TRUE(validate_s16(output, output_ref, output_ref_size));
}

void int16xint8xint32_5_arm_convolve_s16(void)
{
    int16_t output[INT16XINT8XINT32_5_DST_SIZE] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_conv_params conv_params;
    cmsis_nn_per_channel_quant_params quant_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims bias_dims;
    cmsis_nn_dims output_dims;

    const int32_t *int32_bias_data = int16xint8xint32_5_biases;
    const cmsis_nn_bias_data bias_data = {int32_bias_data, true};
    const int8_t *kernel_data = int16xint8xint32_5_weights;
    const int16_t *input_data = int16xint8xint32_5_input;
    const int16_t *output_ref = int16xint8xint32_5_output_ref;
    const int32_t output_ref_size = INT16XINT8XINT32_5_DST_SIZE;

    input_dims.n = INT16XINT8XINT32_5_INPUT_BATCHES;
    input_dims.w = INT16XINT8XINT32_5_INPUT_W;
    input_dims.h = INT16XINT8XINT32_5_INPUT_H;
    input_dims.c = INT16XINT8XINT32_5_IN_CH;
    filter_dims.w = INT16XINT8XINT32_5_FILTER_X;
    filter_dims.h = INT16XINT8XINT32_5_FILTER_Y;
    output_dims.w = INT16XINT8XINT32_5_OUTPUT_W;
    output_dims.h = INT16XINT8XINT32_5_OUTPUT_H;
    output_dims.c = INT16XINT8XINT32_5_OUT_CH;

    conv_params.padding.w = INT16XINT8XINT32_5_PAD_X;
    conv_params.padding.h = INT16XINT8XINT32_5_PAD_Y;
    conv_params.stride.w = INT16XINT8XINT32_5_STRIDE_X;
    conv_params.stride.h = INT16XINT8XINT32_5_STRIDE_Y;
    conv_params.dilation.w = INT16XINT8XINT32_5_DILATION_X;
    conv_params.dilation.h = INT16XINT8XINT32_5_DILATION_Y;

    conv_params.input_offset = 0;
    conv_params.output_offset = 0;
    conv_params.activation.min = INT16XINT8XINT32_5_OUT_ACTIVATION_MIN;
    conv_params.activation.max = INT16XINT8XINT32_5_OUT_ACTIVATION_MAX;
    quant_params.multiplier = (int32_t *)int16xint8xint32_5_output_mult;
    quant_params.shift = (int32_t *)int16xint8xint32_5_output_shift;

    int buf_size = arm_convolve_s16_get_buffer_size(&input_dims, &filter_dims);
    ctx.buf = malloc(buf_size);
    arm_cmsis_nn_status result;
    result = arm_convolve_s16(&ctx,
                              &conv_params,
                              &quant_params,
                              &input_dims,
                              input_data,
                              &filter_dims,
                              kernel_data,
                              &bias_dims,
                              &bias_data,
                              &output_dims,
                              output);
    if (ctx.buf)
    {
        // The caller is responsible to clear the scratch buffers for security reasons if applicable.
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(ARM_CMSIS_NN_SUCCESS, result);
    TEST_ASSERT_TRUE(validate_s16(output, output_ref, output_ref_size));
    memset(output, 0, sizeof(output));

    buf_size = arm_convolve_wrapper_s16_get_buffer_size(&conv_params, &input_dims, &filter_dims, &output_dims);
    ctx.buf = malloc(buf_size);

    result = arm_convolve_wrapper_s16(&ctx,
                                      &conv_params,
                                      &quant_params,
                                      &input_dims,
                                      input_data,
                                      &filter_dims,
                                      kernel_data,
                                      &bias_dims,
                                      &bias_data,
                                      &output_dims,
                                      output);
    if (ctx.buf)
    {
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(ARM_CMSIS_NN_SUCCESS, result);
    TEST_ASSERT_TRUE(validate_s16(output, output_ref, output_ref_size));
}

void int16xint8xint32_6_arm_convolve_s16(void)
{
    int16_t output[INT16XINT8XINT32_6_DST_SIZE] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_conv_params conv_params;
    cmsis_nn_per_channel_quant_params quant_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims bias_dims;
    cmsis_nn_dims output_dims;

    const int32_t *int32_bias_data = int16xint8xint32_6_biases;
    const cmsis_nn_bias_data bias_data = {int32_bias_data, true};
    const int8_t *kernel_data = int16xint8xint32_6_weights;
    const int16_t *input_data = int16xint8xint32_6_input;
    const int16_t *output_ref = int16xint8xint32_6_output_ref;
    const int32_t output_ref_size = INT16XINT8XINT32_6_DST_SIZE;

    input_dims.n = INT16XINT8XINT32_6_INPUT_BATCHES;
    input_dims.w = INT16XINT8XINT32_6_INPUT_W;
    input_dims.h = INT16XINT8XINT32_6_INPUT_H;
    input_dims.c = INT16XINT8XINT32_6_IN_CH;
    filter_dims.w = INT16XINT8XINT32_6_FILTER_X;
    filter_dims.h = INT16XINT8XINT32_6_FILTER_Y;
    output_dims.w = INT16XINT8XINT32_6_OUTPUT_W;
    output_dims.h = INT16XINT8XINT32_6_OUTPUT_H;
    output_dims.c = INT16XINT8XINT32_6_OUT_CH;

    conv_params.padding.w = INT16XINT8XINT32_6_PAD_X;
    conv_params.padding.h = INT16XINT8XINT32_6_PAD_Y;
    conv_params.stride.w = INT16XINT8XINT32_6_STRIDE_X;
    conv_params.stride.h = INT16XINT8XINT32_6_STRIDE_Y;
    conv_params.dilation.w = INT16XINT8XINT32_6_DILATION_X;
    conv_params.dilation.h = INT16XINT8XINT32_6_DILATION_Y;

    conv_params.input_offset = 0;
    conv_params.output_offset = 0;
    conv_params.activation.min = INT16XINT8XINT32_6_OUT_ACTIVATION_MIN;
    conv_params.activation.max = INT16XINT8XINT32_6_OUT_ACTIVATION_MAX;
    quant_params.multiplier = (int32_t *)int16xint8xint32_6_output_mult;
    quant_params.shift = (int32_t *)int16xint8xint32_6_output_shift;

    int buf_size = arm_convolve_s16_get_buffer_size(&input_dims, &filter_dims);
    ctx.buf = malloc(buf_size);
    arm_cmsis_nn_status result;
    result = arm_convolve_s16(&ctx,
                              &conv_params,
                              &quant_params,
                              &input_dims,
                              input_data,
                              &filter_dims,
                              kernel_data,
                              &bias_dims,
                              &bias_data,
                              &output_dims,
                              output);
    if (ctx.buf)
    {
        // The caller is responsible to clear the scratch buffers for security reasons if applicable.
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(ARM_CMSIS_NN_SUCCESS, result);
    TEST_ASSERT_TRUE(validate_s16(output, output_ref, output_ref_size));
    memset(output, 0, sizeof(output));

    buf_size = arm_convolve_wrapper_s16_get_buffer_size(&conv_params, &input_dims, &filter_dims, &output_dims);
    ctx.buf = malloc(buf_size);

    result = arm_convolve_wrapper_s16(&ctx,
                                      &conv_params,
                                      &quant_params,
                                      &input_dims,
                                      input_data,
                                      &filter_dims,
                                      kernel_data,
                                      &bias_dims,
                                      &bias_data,
                                      &output_dims,
                                      output);
    if (ctx.buf)
    {
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(ARM_CMSIS_NN_SUCCESS, result);
    TEST_ASSERT_TRUE(validate_s16(output, output_ref, output_ref_size));
}
