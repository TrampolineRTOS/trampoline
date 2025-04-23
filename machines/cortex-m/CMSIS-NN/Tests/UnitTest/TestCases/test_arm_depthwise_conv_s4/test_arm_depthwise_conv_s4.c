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

#include <arm_nnfunctions.h>
#include <stdlib.h>
#include <unity.h>

#include "../TestData/depthwise_int4_generic/test_data.h"
#include "../TestData/depthwise_int4_generic_2/test_data.h"
#include "../TestData/depthwise_int4_generic_3/test_data.h"
#include "../TestData/depthwise_int4_generic_4/test_data.h"
#include "../TestData/depthwise_int4_generic_5/test_data.h"
#include "../TestData/depthwise_int4_generic_6/test_data.h"
#include "../Utils/utils.h"
#include "../Utils/validate.h"

void depthwise_int4_generic_arm_depthwise_conv_s4(void)
{
    const arm_cmsis_nn_status expected = ARM_CMSIS_NN_SUCCESS;
    int8_t output[DEPTHWISE_INT4_GENERIC_DST_SIZE] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_dw_conv_params dw_conv_params;
    cmsis_nn_per_channel_quant_params quant_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims bias_dims;
    cmsis_nn_dims output_dims;

    const int32_t *bias_data = depthwise_int4_generic_biases;
    const int8_t *kernel_data = depthwise_int4_generic_weights;
    const int8_t *input_data = depthwise_int4_generic_input;

    input_dims.n = DEPTHWISE_INT4_GENERIC_INPUT_BATCHES;
    input_dims.w = DEPTHWISE_INT4_GENERIC_INPUT_W;
    input_dims.h = DEPTHWISE_INT4_GENERIC_INPUT_H;
    input_dims.c = DEPTHWISE_INT4_GENERIC_IN_CH;
    filter_dims.w = DEPTHWISE_INT4_GENERIC_FILTER_X;
    filter_dims.h = DEPTHWISE_INT4_GENERIC_FILTER_Y;
    output_dims.w = DEPTHWISE_INT4_GENERIC_OUTPUT_W;
    output_dims.h = DEPTHWISE_INT4_GENERIC_OUTPUT_H;
    output_dims.c = DEPTHWISE_INT4_GENERIC_OUT_CH;

    dw_conv_params.padding.w = DEPTHWISE_INT4_GENERIC_PAD_X;
    dw_conv_params.padding.h = DEPTHWISE_INT4_GENERIC_PAD_Y;
    dw_conv_params.stride.w = DEPTHWISE_INT4_GENERIC_STRIDE_X;
    dw_conv_params.stride.h = DEPTHWISE_INT4_GENERIC_STRIDE_Y;
    dw_conv_params.dilation.w = DEPTHWISE_INT4_GENERIC_DILATION_X;
    dw_conv_params.dilation.h = DEPTHWISE_INT4_GENERIC_DILATION_Y;

    dw_conv_params.ch_mult = DEPTHWISE_INT4_GENERIC_CH_MULT;

    dw_conv_params.input_offset = DEPTHWISE_INT4_GENERIC_INPUT_OFFSET;
    dw_conv_params.output_offset = DEPTHWISE_INT4_GENERIC_OUTPUT_OFFSET;
    dw_conv_params.activation.min = DEPTHWISE_INT4_GENERIC_OUT_ACTIVATION_MIN;
    dw_conv_params.activation.max = DEPTHWISE_INT4_GENERIC_OUT_ACTIVATION_MAX;
    quant_params.multiplier = (int32_t *)depthwise_int4_generic_output_mult;
    quant_params.shift = (int32_t *)depthwise_int4_generic_output_shift;

    ctx.size = arm_depthwise_conv_wrapper_s4_get_buffer_size(&dw_conv_params, &input_dims, &filter_dims, &output_dims);
    TEST_ASSERT_TRUE(ctx.size == 0);

    ctx.buf = malloc(ctx.size);

    arm_cmsis_nn_status result = arm_depthwise_conv_s4(&ctx,
                                                       &dw_conv_params,
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
        memset(ctx.buf, 0, ctx.size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(expected, result);
    TEST_ASSERT_TRUE(validate(output, depthwise_int4_generic_output_ref, DEPTHWISE_INT4_GENERIC_DST_SIZE));
    memset(output, 0, DEPTHWISE_INT4_GENERIC_DST_SIZE);

    ctx.buf = malloc(ctx.size);
    result = arm_depthwise_conv_wrapper_s4(&ctx,
                                           &dw_conv_params,
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
        memset(ctx.buf, 0, ctx.size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(expected, result);
    TEST_ASSERT_TRUE(validate(output, depthwise_int4_generic_output_ref, DEPTHWISE_INT4_GENERIC_DST_SIZE));
    memset(output, 0, DEPTHWISE_INT4_GENERIC_DST_SIZE);
}

void depthwise_int4_generic_2_arm_depthwise_conv_s4(void)
{
    const arm_cmsis_nn_status expected = ARM_CMSIS_NN_SUCCESS;
    int8_t output[DEPTHWISE_INT4_GENERIC_2_DST_SIZE] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_dw_conv_params dw_conv_params;
    cmsis_nn_per_channel_quant_params quant_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims bias_dims;
    cmsis_nn_dims output_dims;

    const int32_t *bias_data = depthwise_int4_generic_2_biases;
    const int8_t *kernel_data = depthwise_int4_generic_2_weights;
    const int8_t *input_data = depthwise_int4_generic_2_input;

    input_dims.n = DEPTHWISE_INT4_GENERIC_2_INPUT_BATCHES;
    input_dims.w = DEPTHWISE_INT4_GENERIC_2_INPUT_W;
    input_dims.h = DEPTHWISE_INT4_GENERIC_2_INPUT_H;
    input_dims.c = DEPTHWISE_INT4_GENERIC_2_IN_CH;
    filter_dims.w = DEPTHWISE_INT4_GENERIC_2_FILTER_X;
    filter_dims.h = DEPTHWISE_INT4_GENERIC_2_FILTER_Y;
    output_dims.w = DEPTHWISE_INT4_GENERIC_2_OUTPUT_W;
    output_dims.h = DEPTHWISE_INT4_GENERIC_2_OUTPUT_H;
    output_dims.c = DEPTHWISE_INT4_GENERIC_2_OUT_CH;

    dw_conv_params.padding.w = DEPTHWISE_INT4_GENERIC_2_PAD_X;
    dw_conv_params.padding.h = DEPTHWISE_INT4_GENERIC_2_PAD_Y;
    dw_conv_params.stride.w = DEPTHWISE_INT4_GENERIC_2_STRIDE_X;
    dw_conv_params.stride.h = DEPTHWISE_INT4_GENERIC_2_STRIDE_Y;
    dw_conv_params.dilation.w = DEPTHWISE_INT4_GENERIC_2_DILATION_X;
    dw_conv_params.dilation.h = DEPTHWISE_INT4_GENERIC_2_DILATION_Y;

    dw_conv_params.ch_mult = DEPTHWISE_INT4_GENERIC_2_CH_MULT;

    dw_conv_params.input_offset = DEPTHWISE_INT4_GENERIC_2_INPUT_OFFSET;
    dw_conv_params.output_offset = DEPTHWISE_INT4_GENERIC_2_OUTPUT_OFFSET;
    dw_conv_params.activation.min = DEPTHWISE_INT4_GENERIC_2_OUT_ACTIVATION_MIN;
    dw_conv_params.activation.max = DEPTHWISE_INT4_GENERIC_2_OUT_ACTIVATION_MAX;
    quant_params.multiplier = (int32_t *)depthwise_int4_generic_2_output_mult;
    quant_params.shift = (int32_t *)depthwise_int4_generic_2_output_shift;

    ctx.size = arm_depthwise_conv_wrapper_s4_get_buffer_size(&dw_conv_params, &input_dims, &filter_dims, &output_dims);
    TEST_ASSERT_TRUE(ctx.size == 0);

    ctx.buf = malloc(ctx.size);

    arm_cmsis_nn_status result = arm_depthwise_conv_s4(&ctx,
                                                       &dw_conv_params,
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
        memset(ctx.buf, 0, ctx.size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(expected, result);
    TEST_ASSERT_TRUE(validate(output, depthwise_int4_generic_2_output_ref, DEPTHWISE_INT4_GENERIC_2_DST_SIZE));
    memset(output, 0, DEPTHWISE_INT4_GENERIC_2_DST_SIZE);

    ctx.buf = malloc(ctx.size);
    result = arm_depthwise_conv_wrapper_s4(&ctx,
                                           &dw_conv_params,
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
        memset(ctx.buf, 0, ctx.size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(expected, result);
    TEST_ASSERT_TRUE(validate(output, depthwise_int4_generic_2_output_ref, DEPTHWISE_INT4_GENERIC_2_DST_SIZE));
    memset(output, 0, DEPTHWISE_INT4_GENERIC_2_DST_SIZE);
}

void depthwise_int4_generic_3_arm_depthwise_conv_s4(void)
{
    const arm_cmsis_nn_status expected = ARM_CMSIS_NN_SUCCESS;
    int8_t output[DEPTHWISE_INT4_GENERIC_3_DST_SIZE] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_dw_conv_params dw_conv_params;
    cmsis_nn_per_channel_quant_params quant_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims bias_dims;
    cmsis_nn_dims output_dims;

    const int32_t *bias_data = depthwise_int4_generic_3_biases;
    const int8_t *kernel_data = depthwise_int4_generic_3_weights;
    const int8_t *input_data = depthwise_int4_generic_3_input;

    input_dims.n = DEPTHWISE_INT4_GENERIC_3_INPUT_BATCHES;
    input_dims.w = DEPTHWISE_INT4_GENERIC_3_INPUT_W;
    input_dims.h = DEPTHWISE_INT4_GENERIC_3_INPUT_H;
    input_dims.c = DEPTHWISE_INT4_GENERIC_3_IN_CH;
    filter_dims.w = DEPTHWISE_INT4_GENERIC_3_FILTER_X;
    filter_dims.h = DEPTHWISE_INT4_GENERIC_3_FILTER_Y;
    output_dims.w = DEPTHWISE_INT4_GENERIC_3_OUTPUT_W;
    output_dims.h = DEPTHWISE_INT4_GENERIC_3_OUTPUT_H;
    output_dims.c = DEPTHWISE_INT4_GENERIC_3_OUT_CH;

    dw_conv_params.padding.w = DEPTHWISE_INT4_GENERIC_3_PAD_X;
    dw_conv_params.padding.h = DEPTHWISE_INT4_GENERIC_3_PAD_Y;
    dw_conv_params.stride.w = DEPTHWISE_INT4_GENERIC_3_STRIDE_X;
    dw_conv_params.stride.h = DEPTHWISE_INT4_GENERIC_3_STRIDE_Y;
    dw_conv_params.dilation.w = DEPTHWISE_INT4_GENERIC_3_DILATION_X;
    dw_conv_params.dilation.h = DEPTHWISE_INT4_GENERIC_3_DILATION_Y;

    dw_conv_params.ch_mult = DEPTHWISE_INT4_GENERIC_3_CH_MULT;

    dw_conv_params.input_offset = DEPTHWISE_INT4_GENERIC_3_INPUT_OFFSET;
    dw_conv_params.output_offset = DEPTHWISE_INT4_GENERIC_3_OUTPUT_OFFSET;
    dw_conv_params.activation.min = DEPTHWISE_INT4_GENERIC_3_OUT_ACTIVATION_MIN;
    dw_conv_params.activation.max = DEPTHWISE_INT4_GENERIC_3_OUT_ACTIVATION_MAX;
    quant_params.multiplier = (int32_t *)depthwise_int4_generic_3_output_mult;
    quant_params.shift = (int32_t *)depthwise_int4_generic_3_output_shift;

    ctx.size = arm_depthwise_conv_wrapper_s4_get_buffer_size(&dw_conv_params, &input_dims, &filter_dims, &output_dims);
    TEST_ASSERT_TRUE(ctx.size == 0);

    ctx.buf = malloc(ctx.size);

    arm_cmsis_nn_status result = arm_depthwise_conv_s4(&ctx,
                                                       &dw_conv_params,
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
        memset(ctx.buf, 0, ctx.size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(expected, result);
    TEST_ASSERT_TRUE(validate(output, depthwise_int4_generic_3_output_ref, DEPTHWISE_INT4_GENERIC_3_DST_SIZE));
    memset(output, 0, DEPTHWISE_INT4_GENERIC_3_DST_SIZE);

    ctx.buf = malloc(ctx.size);
    result = arm_depthwise_conv_wrapper_s4(&ctx,
                                           &dw_conv_params,
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
        memset(ctx.buf, 0, ctx.size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(expected, result);
    TEST_ASSERT_TRUE(validate(output, depthwise_int4_generic_3_output_ref, DEPTHWISE_INT4_GENERIC_3_DST_SIZE));
    memset(output, 0, DEPTHWISE_INT4_GENERIC_3_DST_SIZE);
}

void depthwise_int4_generic_4_arm_depthwise_conv_s4(void)
{
    const arm_cmsis_nn_status expected = ARM_CMSIS_NN_SUCCESS;
    int8_t output[DEPTHWISE_INT4_GENERIC_4_DST_SIZE] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_dw_conv_params dw_conv_params;
    cmsis_nn_per_channel_quant_params quant_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims bias_dims;
    cmsis_nn_dims output_dims;

    const int32_t *bias_data = depthwise_int4_generic_4_biases;
    const int8_t *kernel_data = depthwise_int4_generic_4_weights;
    const int8_t *input_data = depthwise_int4_generic_4_input;

    input_dims.n = DEPTHWISE_INT4_GENERIC_4_INPUT_BATCHES;
    input_dims.w = DEPTHWISE_INT4_GENERIC_4_INPUT_W;
    input_dims.h = DEPTHWISE_INT4_GENERIC_4_INPUT_H;
    input_dims.c = DEPTHWISE_INT4_GENERIC_4_IN_CH;
    filter_dims.w = DEPTHWISE_INT4_GENERIC_4_FILTER_X;
    filter_dims.h = DEPTHWISE_INT4_GENERIC_4_FILTER_Y;
    output_dims.w = DEPTHWISE_INT4_GENERIC_4_OUTPUT_W;
    output_dims.h = DEPTHWISE_INT4_GENERIC_4_OUTPUT_H;
    output_dims.c = DEPTHWISE_INT4_GENERIC_4_OUT_CH;

    dw_conv_params.padding.w = DEPTHWISE_INT4_GENERIC_4_PAD_X;
    dw_conv_params.padding.h = DEPTHWISE_INT4_GENERIC_4_PAD_Y;
    dw_conv_params.stride.w = DEPTHWISE_INT4_GENERIC_4_STRIDE_X;
    dw_conv_params.stride.h = DEPTHWISE_INT4_GENERIC_4_STRIDE_Y;
    dw_conv_params.dilation.w = DEPTHWISE_INT4_GENERIC_4_DILATION_X;
    dw_conv_params.dilation.h = DEPTHWISE_INT4_GENERIC_4_DILATION_Y;

    dw_conv_params.ch_mult = DEPTHWISE_INT4_GENERIC_4_CH_MULT;

    dw_conv_params.input_offset = DEPTHWISE_INT4_GENERIC_4_INPUT_OFFSET;
    dw_conv_params.output_offset = DEPTHWISE_INT4_GENERIC_4_OUTPUT_OFFSET;
    dw_conv_params.activation.min = DEPTHWISE_INT4_GENERIC_4_OUT_ACTIVATION_MIN;
    dw_conv_params.activation.max = DEPTHWISE_INT4_GENERIC_4_OUT_ACTIVATION_MAX;
    quant_params.multiplier = (int32_t *)depthwise_int4_generic_4_output_mult;
    quant_params.shift = (int32_t *)depthwise_int4_generic_4_output_shift;

    ctx.size = arm_depthwise_conv_wrapper_s4_get_buffer_size(&dw_conv_params, &input_dims, &filter_dims, &output_dims);
    TEST_ASSERT_TRUE(ctx.size == 0);

    ctx.buf = malloc(ctx.size);

    arm_cmsis_nn_status result = arm_depthwise_conv_s4(&ctx,
                                                       &dw_conv_params,
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
        memset(ctx.buf, 0, ctx.size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(expected, result);
    TEST_ASSERT_TRUE(validate(output, depthwise_int4_generic_4_output_ref, DEPTHWISE_INT4_GENERIC_4_DST_SIZE));
    memset(output, 0, DEPTHWISE_INT4_GENERIC_4_DST_SIZE);

    ctx.buf = malloc(ctx.size);
    result = arm_depthwise_conv_wrapper_s4(&ctx,
                                           &dw_conv_params,
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
        memset(ctx.buf, 0, ctx.size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(expected, result);
    TEST_ASSERT_TRUE(validate(output, depthwise_int4_generic_4_output_ref, DEPTHWISE_INT4_GENERIC_4_DST_SIZE));
    memset(output, 0, DEPTHWISE_INT4_GENERIC_4_DST_SIZE);
}

void depthwise_int4_generic_5_arm_depthwise_conv_s4(void)
{
    const arm_cmsis_nn_status expected = ARM_CMSIS_NN_SUCCESS;
    int8_t output[DEPTHWISE_INT4_GENERIC_5_DST_SIZE] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_dw_conv_params dw_conv_params;
    cmsis_nn_per_channel_quant_params quant_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims bias_dims;
    cmsis_nn_dims output_dims;

    const int32_t *bias_data = depthwise_int4_generic_5_biases;
    const int8_t *kernel_data = depthwise_int4_generic_5_weights;
    const int8_t *input_data = depthwise_int4_generic_5_input;

    input_dims.n = DEPTHWISE_INT4_GENERIC_5_INPUT_BATCHES;
    input_dims.w = DEPTHWISE_INT4_GENERIC_5_INPUT_W;
    input_dims.h = DEPTHWISE_INT4_GENERIC_5_INPUT_H;
    input_dims.c = DEPTHWISE_INT4_GENERIC_5_IN_CH;
    filter_dims.w = DEPTHWISE_INT4_GENERIC_5_FILTER_X;
    filter_dims.h = DEPTHWISE_INT4_GENERIC_5_FILTER_Y;
    output_dims.w = DEPTHWISE_INT4_GENERIC_5_OUTPUT_W;
    output_dims.h = DEPTHWISE_INT4_GENERIC_5_OUTPUT_H;
    output_dims.c = DEPTHWISE_INT4_GENERIC_5_OUT_CH;

    dw_conv_params.padding.w = DEPTHWISE_INT4_GENERIC_5_PAD_X;
    dw_conv_params.padding.h = DEPTHWISE_INT4_GENERIC_5_PAD_Y;
    dw_conv_params.stride.w = DEPTHWISE_INT4_GENERIC_5_STRIDE_X;
    dw_conv_params.stride.h = DEPTHWISE_INT4_GENERIC_5_STRIDE_Y;
    dw_conv_params.dilation.w = DEPTHWISE_INT4_GENERIC_5_DILATION_X;
    dw_conv_params.dilation.h = DEPTHWISE_INT4_GENERIC_5_DILATION_Y;

    dw_conv_params.ch_mult = DEPTHWISE_INT4_GENERIC_5_CH_MULT;

    dw_conv_params.input_offset = DEPTHWISE_INT4_GENERIC_5_INPUT_OFFSET;
    dw_conv_params.output_offset = DEPTHWISE_INT4_GENERIC_5_OUTPUT_OFFSET;
    dw_conv_params.activation.min = DEPTHWISE_INT4_GENERIC_5_OUT_ACTIVATION_MIN;
    dw_conv_params.activation.max = DEPTHWISE_INT4_GENERIC_5_OUT_ACTIVATION_MAX;
    quant_params.multiplier = (int32_t *)depthwise_int4_generic_5_output_mult;
    quant_params.shift = (int32_t *)depthwise_int4_generic_5_output_shift;

    ctx.size = arm_depthwise_conv_wrapper_s4_get_buffer_size(&dw_conv_params, &input_dims, &filter_dims, &output_dims);
    TEST_ASSERT_TRUE(ctx.size == 0);

    ctx.buf = malloc(ctx.size);

    arm_cmsis_nn_status result = arm_depthwise_conv_s4(&ctx,
                                                       &dw_conv_params,
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
        memset(ctx.buf, 0, ctx.size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(expected, result);
    TEST_ASSERT_TRUE(validate(output, depthwise_int4_generic_5_output_ref, DEPTHWISE_INT4_GENERIC_5_DST_SIZE));
    memset(output, 0, DEPTHWISE_INT4_GENERIC_5_DST_SIZE);

    ctx.buf = malloc(ctx.size);
    result = arm_depthwise_conv_wrapper_s4(&ctx,
                                           &dw_conv_params,
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
        memset(ctx.buf, 0, ctx.size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(expected, result);
    TEST_ASSERT_TRUE(validate(output, depthwise_int4_generic_5_output_ref, DEPTHWISE_INT4_GENERIC_5_DST_SIZE));
    memset(output, 0, DEPTHWISE_INT4_GENERIC_5_DST_SIZE);
}

void depthwise_int4_generic_6_arm_depthwise_conv_s4(void)
{
    const arm_cmsis_nn_status expected = ARM_CMSIS_NN_SUCCESS;
    int8_t output[DEPTHWISE_INT4_GENERIC_6_DST_SIZE] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_dw_conv_params dw_conv_params;
    cmsis_nn_per_channel_quant_params quant_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims bias_dims;
    cmsis_nn_dims output_dims;

    const int32_t *bias_data = depthwise_int4_generic_6_biases;
    const int8_t *kernel_data = depthwise_int4_generic_6_weights;
    const int8_t *input_data = depthwise_int4_generic_6_input;

    input_dims.n = DEPTHWISE_INT4_GENERIC_6_INPUT_BATCHES;
    input_dims.w = DEPTHWISE_INT4_GENERIC_6_INPUT_W;
    input_dims.h = DEPTHWISE_INT4_GENERIC_6_INPUT_H;
    input_dims.c = DEPTHWISE_INT4_GENERIC_6_IN_CH;
    filter_dims.w = DEPTHWISE_INT4_GENERIC_6_FILTER_X;
    filter_dims.h = DEPTHWISE_INT4_GENERIC_6_FILTER_Y;
    output_dims.w = DEPTHWISE_INT4_GENERIC_6_OUTPUT_W;
    output_dims.h = DEPTHWISE_INT4_GENERIC_6_OUTPUT_H;
    output_dims.c = DEPTHWISE_INT4_GENERIC_6_OUT_CH;

    dw_conv_params.padding.w = DEPTHWISE_INT4_GENERIC_6_PAD_X;
    dw_conv_params.padding.h = DEPTHWISE_INT4_GENERIC_6_PAD_Y;
    dw_conv_params.stride.w = DEPTHWISE_INT4_GENERIC_6_STRIDE_X;
    dw_conv_params.stride.h = DEPTHWISE_INT4_GENERIC_6_STRIDE_Y;
    dw_conv_params.dilation.w = DEPTHWISE_INT4_GENERIC_6_DILATION_X;
    dw_conv_params.dilation.h = DEPTHWISE_INT4_GENERIC_6_DILATION_Y;

    dw_conv_params.ch_mult = DEPTHWISE_INT4_GENERIC_6_CH_MULT;

    dw_conv_params.input_offset = DEPTHWISE_INT4_GENERIC_6_INPUT_OFFSET;
    dw_conv_params.output_offset = DEPTHWISE_INT4_GENERIC_6_OUTPUT_OFFSET;
    dw_conv_params.activation.min = DEPTHWISE_INT4_GENERIC_6_OUT_ACTIVATION_MIN;
    dw_conv_params.activation.max = DEPTHWISE_INT4_GENERIC_6_OUT_ACTIVATION_MAX;
    quant_params.multiplier = (int32_t *)depthwise_int4_generic_6_output_mult;
    quant_params.shift = (int32_t *)depthwise_int4_generic_6_output_shift;

    ctx.size = arm_depthwise_conv_wrapper_s4_get_buffer_size(&dw_conv_params, &input_dims, &filter_dims, &output_dims);
    TEST_ASSERT_TRUE(ctx.size == 0);

    ctx.buf = malloc(ctx.size);

    arm_cmsis_nn_status result = arm_depthwise_conv_s4(&ctx,
                                                       &dw_conv_params,
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
        memset(ctx.buf, 0, ctx.size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(expected, result);
    TEST_ASSERT_TRUE(validate(output, depthwise_int4_generic_6_output_ref, DEPTHWISE_INT4_GENERIC_6_DST_SIZE));
    memset(output, 0, DEPTHWISE_INT4_GENERIC_6_DST_SIZE);

    ctx.buf = malloc(ctx.size);
    result = arm_depthwise_conv_wrapper_s4(&ctx,
                                           &dw_conv_params,
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
        memset(ctx.buf, 0, ctx.size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(expected, result);
    TEST_ASSERT_TRUE(validate(output, depthwise_int4_generic_6_output_ref, DEPTHWISE_INT4_GENERIC_6_DST_SIZE));
    memset(output, 0, DEPTHWISE_INT4_GENERIC_6_DST_SIZE);
}