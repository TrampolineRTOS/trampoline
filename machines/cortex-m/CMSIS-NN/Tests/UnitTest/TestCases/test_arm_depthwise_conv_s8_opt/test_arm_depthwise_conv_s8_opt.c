/*
 * SPDX-FileCopyrightText: Copyright 2010-2023 Arm Limited and/or its affiliates <open-source-office@arm.com>
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

#include "../TestData/basic/test_data.h"
#include "../TestData/depthwise_eq_in_out_ch/test_data.h"
#include "../TestData/depthwise_null_bias_0/test_data.h"
#include "../TestData/depthwise_out_activation/test_data.h"
#include "../TestData/depthwise_sub_block/test_data.h"
#include "../TestData/depthwise_x_stride/test_data.h"
#include "../Utils/utils.h"
#include "../Utils/validate.h"

void basic_arm_depthwise_conv_s8_opt(void)
{
    const arm_cmsis_nn_status expected = ARM_CMSIS_NN_SUCCESS;
    int8_t output[BASIC_DST_SIZE] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_dw_conv_params dw_conv_params;
    cmsis_nn_per_channel_quant_params quant_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims bias_dims;
    cmsis_nn_dims output_dims;

    const int32_t *bias_data = basic_biases;
    const int8_t *kernel_data = basic_weights;
    const int8_t *input_data = basic_input;

    input_dims.n = BASIC_INPUT_BATCHES;
    input_dims.w = BASIC_INPUT_W;
    input_dims.h = BASIC_INPUT_H;
    input_dims.c = BASIC_IN_CH;
    filter_dims.w = BASIC_FILTER_X;
    filter_dims.h = BASIC_FILTER_Y;
    output_dims.w = BASIC_OUTPUT_W;
    output_dims.h = BASIC_OUTPUT_H;
    output_dims.c = BASIC_OUT_CH;

    dw_conv_params.padding.w = BASIC_PAD_X;
    dw_conv_params.padding.h = BASIC_PAD_Y;
    dw_conv_params.stride.w = BASIC_STRIDE_X;
    dw_conv_params.stride.h = BASIC_STRIDE_Y;
    dw_conv_params.dilation.w = BASIC_DILATION_X;
    dw_conv_params.dilation.h = BASIC_DILATION_Y;

    dw_conv_params.ch_mult = 1;

    dw_conv_params.input_offset = BASIC_INPUT_OFFSET;
    dw_conv_params.output_offset = BASIC_OUTPUT_OFFSET;
    dw_conv_params.activation.min = BASIC_OUT_ACTIVATION_MIN;
    dw_conv_params.activation.max = BASIC_OUT_ACTIVATION_MAX;
    quant_params.multiplier = (int32_t *)basic_output_mult;
    quant_params.shift = (int32_t *)basic_output_shift;

    ctx.size = arm_depthwise_conv_s8_opt_get_buffer_size(&input_dims, &filter_dims);

#if defined(ARM_MATH_DSP)
    TEST_ASSERT_TRUE(ctx.size > 0);
#else
    TEST_ASSERT_EQUAL(ctx.size, 0);
#endif

    ctx.buf = malloc(ctx.size);

    arm_cmsis_nn_status result = arm_depthwise_conv_s8_opt(&ctx,
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
    TEST_ASSERT_TRUE(validate(output, basic_output_ref, BASIC_DST_SIZE));

    const int32_t wrapper_buf_size =
        arm_depthwise_conv_wrapper_s8_get_buffer_size(&dw_conv_params, &input_dims, &filter_dims, &output_dims);

    TEST_ASSERT_EQUAL(wrapper_buf_size, ctx.size);

    ctx.buf = malloc(wrapper_buf_size);

    result = arm_depthwise_conv_wrapper_s8(&ctx,
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
        memset(ctx.buf, 0, wrapper_buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(expected, result);
    TEST_ASSERT_TRUE(validate(output, basic_output_ref, BASIC_DST_SIZE));
}

void depthwise_eq_in_out_ch_arm_depthwise_conv_s8_opt(void)
{
    const arm_cmsis_nn_status expected = ARM_CMSIS_NN_SUCCESS;
    int8_t output[DEPTHWISE_EQ_IN_OUT_CH_DST_SIZE] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_dw_conv_params dw_conv_params;
    cmsis_nn_per_channel_quant_params quant_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims bias_dims;
    cmsis_nn_dims output_dims;

    const int32_t *bias_data = get_bias_address(depthwise_eq_in_out_ch_biases, DEPTHWISE_EQ_IN_OUT_CH_IN_CH);
    const int8_t *kernel_data = depthwise_eq_in_out_ch_weights;
    const int8_t *input_data = depthwise_eq_in_out_ch_input;

    input_dims.n = DEPTHWISE_EQ_IN_OUT_CH_INPUT_BATCHES;
    input_dims.w = DEPTHWISE_EQ_IN_OUT_CH_INPUT_W;
    input_dims.h = DEPTHWISE_EQ_IN_OUT_CH_INPUT_H;
    input_dims.c = DEPTHWISE_EQ_IN_OUT_CH_IN_CH;
    filter_dims.w = DEPTHWISE_EQ_IN_OUT_CH_FILTER_X;
    filter_dims.h = DEPTHWISE_EQ_IN_OUT_CH_FILTER_Y;
    output_dims.w = DEPTHWISE_EQ_IN_OUT_CH_OUTPUT_W;
    output_dims.h = DEPTHWISE_EQ_IN_OUT_CH_OUTPUT_H;
    output_dims.c = DEPTHWISE_EQ_IN_OUT_CH_OUT_CH;

    dw_conv_params.padding.w = DEPTHWISE_EQ_IN_OUT_CH_PAD_X;
    dw_conv_params.padding.h = DEPTHWISE_EQ_IN_OUT_CH_PAD_Y;
    dw_conv_params.stride.w = DEPTHWISE_EQ_IN_OUT_CH_STRIDE_X;
    dw_conv_params.stride.h = DEPTHWISE_EQ_IN_OUT_CH_STRIDE_Y;
    dw_conv_params.dilation.w = DEPTHWISE_EQ_IN_OUT_CH_DILATION_X;
    dw_conv_params.dilation.h = DEPTHWISE_EQ_IN_OUT_CH_DILATION_Y;

    dw_conv_params.ch_mult = 1;

    dw_conv_params.input_offset = DEPTHWISE_EQ_IN_OUT_CH_INPUT_OFFSET;
    dw_conv_params.output_offset = DEPTHWISE_EQ_IN_OUT_CH_OUTPUT_OFFSET;
    dw_conv_params.activation.min = DEPTHWISE_EQ_IN_OUT_CH_OUT_ACTIVATION_MIN;
    dw_conv_params.activation.max = DEPTHWISE_EQ_IN_OUT_CH_OUT_ACTIVATION_MAX;
    quant_params.multiplier = (int32_t *)depthwise_eq_in_out_ch_output_mult;
    quant_params.shift = (int32_t *)depthwise_eq_in_out_ch_output_shift;

    ctx.size = arm_depthwise_conv_s8_opt_get_buffer_size(&input_dims, &filter_dims);

#if defined(ARM_MATH_DSP)
    TEST_ASSERT_TRUE(ctx.size > 0);
#else
    TEST_ASSERT_EQUAL(ctx.size, 0);
#endif

    ctx.buf = malloc(ctx.size);

    arm_cmsis_nn_status result = arm_depthwise_conv_s8_opt(&ctx,
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
        memset(ctx.buf, 0, ctx.size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(expected, result);
    TEST_ASSERT_TRUE(validate(output, depthwise_eq_in_out_ch_output_ref, DEPTHWISE_EQ_IN_OUT_CH_DST_SIZE));

    const int32_t wrapper_buf_size =
        arm_depthwise_conv_wrapper_s8_get_buffer_size(&dw_conv_params, &input_dims, &filter_dims, &output_dims);

    TEST_ASSERT_EQUAL(wrapper_buf_size, ctx.size);

    ctx.buf = malloc(wrapper_buf_size);

    result = arm_depthwise_conv_wrapper_s8(&ctx,
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
        memset(ctx.buf, 0, wrapper_buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(expected, result);
    TEST_ASSERT_TRUE(validate(output, depthwise_eq_in_out_ch_output_ref, DEPTHWISE_EQ_IN_OUT_CH_DST_SIZE));
}

void depthwise_sub_block_arm_depthwise_conv_s8_opt(void)
{
    const arm_cmsis_nn_status expected = ARM_CMSIS_NN_SUCCESS;
    int8_t output[DEPTHWISE_SUB_BLOCK_DST_SIZE] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_dw_conv_params dw_conv_params;
    cmsis_nn_per_channel_quant_params quant_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims bias_dims;
    cmsis_nn_dims output_dims;

    const int32_t *bias_data = get_bias_address(depthwise_sub_block_biases, DEPTHWISE_SUB_BLOCK_IN_CH);
    const int8_t *kernel_data = depthwise_sub_block_weights;
    const int8_t *input_data = depthwise_sub_block_input;

    input_dims.n = DEPTHWISE_SUB_BLOCK_INPUT_BATCHES;
    input_dims.w = DEPTHWISE_SUB_BLOCK_INPUT_W;
    input_dims.h = DEPTHWISE_SUB_BLOCK_INPUT_H;
    input_dims.c = DEPTHWISE_SUB_BLOCK_IN_CH;
    filter_dims.w = DEPTHWISE_SUB_BLOCK_FILTER_X;
    filter_dims.h = DEPTHWISE_SUB_BLOCK_FILTER_Y;
    output_dims.w = DEPTHWISE_SUB_BLOCK_OUTPUT_W;
    output_dims.h = DEPTHWISE_SUB_BLOCK_OUTPUT_H;
    output_dims.c = DEPTHWISE_SUB_BLOCK_OUT_CH;

    dw_conv_params.padding.w = DEPTHWISE_SUB_BLOCK_PAD_X;
    dw_conv_params.padding.h = DEPTHWISE_SUB_BLOCK_PAD_Y;
    dw_conv_params.stride.w = DEPTHWISE_SUB_BLOCK_STRIDE_X;
    dw_conv_params.stride.h = DEPTHWISE_SUB_BLOCK_STRIDE_Y;
    dw_conv_params.dilation.w = DEPTHWISE_SUB_BLOCK_DILATION_X;
    dw_conv_params.dilation.h = DEPTHWISE_SUB_BLOCK_DILATION_Y;

    dw_conv_params.ch_mult = 1;

    dw_conv_params.input_offset = DEPTHWISE_SUB_BLOCK_INPUT_OFFSET;
    dw_conv_params.output_offset = DEPTHWISE_SUB_BLOCK_OUTPUT_OFFSET;
    dw_conv_params.activation.min = DEPTHWISE_SUB_BLOCK_OUT_ACTIVATION_MIN;
    dw_conv_params.activation.max = DEPTHWISE_SUB_BLOCK_OUT_ACTIVATION_MAX;
    quant_params.multiplier = (int32_t *)depthwise_sub_block_output_mult;
    quant_params.shift = (int32_t *)depthwise_sub_block_output_shift;

    ctx.size = arm_depthwise_conv_s8_opt_get_buffer_size(&input_dims, &filter_dims);

#if defined(ARM_MATH_DSP)
    TEST_ASSERT_TRUE(ctx.size > 0);
#else
    TEST_ASSERT_EQUAL(ctx.size, 0);
#endif

    ctx.buf = malloc(ctx.size);

    arm_cmsis_nn_status result = arm_depthwise_conv_s8_opt(&ctx,
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
        memset(ctx.buf, 0, ctx.size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(expected, result);
    TEST_ASSERT_TRUE(validate(output, depthwise_sub_block_output_ref, DEPTHWISE_SUB_BLOCK_DST_SIZE));

    const int32_t wrapper_buf_size =
        arm_depthwise_conv_wrapper_s8_get_buffer_size(&dw_conv_params, &input_dims, &filter_dims, &output_dims);

    TEST_ASSERT_EQUAL(wrapper_buf_size, ctx.size);

    ctx.buf = malloc(wrapper_buf_size);

    result = arm_depthwise_conv_wrapper_s8(&ctx,
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
        memset(ctx.buf, 0, wrapper_buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(expected, result);
    TEST_ASSERT_TRUE(validate(output, depthwise_sub_block_output_ref, DEPTHWISE_SUB_BLOCK_DST_SIZE));
}

void depthwise_out_activation_arm_depthwise_conv_s8_opt(void)
{
    const arm_cmsis_nn_status expected = ARM_CMSIS_NN_SUCCESS;
    int8_t output[DEPTHWISE_OUT_ACTIVATION_DST_SIZE] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_dw_conv_params dw_conv_params;
    cmsis_nn_per_channel_quant_params quant_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims bias_dims = {};
    cmsis_nn_dims output_dims;

    const int32_t output_ref_size = DEPTHWISE_OUT_ACTIVATION_DST_SIZE;
    const int32_t *bias_data = get_bias_address(depthwise_out_activation_biases, DEPTHWISE_OUT_ACTIVATION_OUT_CH);
    const int8_t *kernel_data = depthwise_out_activation_weights;
    const int8_t *input_data = depthwise_out_activation_input;

    input_dims.n = DEPTHWISE_OUT_ACTIVATION_INPUT_BATCHES;
    input_dims.w = DEPTHWISE_OUT_ACTIVATION_INPUT_W;
    input_dims.h = DEPTHWISE_OUT_ACTIVATION_INPUT_H;
    input_dims.c = DEPTHWISE_OUT_ACTIVATION_IN_CH;
    filter_dims.w = DEPTHWISE_OUT_ACTIVATION_FILTER_X;
    filter_dims.h = DEPTHWISE_OUT_ACTIVATION_FILTER_Y;
    output_dims.w = DEPTHWISE_OUT_ACTIVATION_OUTPUT_W;
    output_dims.h = DEPTHWISE_OUT_ACTIVATION_OUTPUT_H;
    output_dims.c = DEPTHWISE_OUT_ACTIVATION_OUT_CH;

    dw_conv_params.padding.w = DEPTHWISE_OUT_ACTIVATION_PAD_X;
    dw_conv_params.padding.h = DEPTHWISE_OUT_ACTIVATION_PAD_Y;
    dw_conv_params.stride.w = DEPTHWISE_OUT_ACTIVATION_STRIDE_X;
    dw_conv_params.stride.h = DEPTHWISE_OUT_ACTIVATION_STRIDE_Y;
    dw_conv_params.ch_mult = DEPTHWISE_OUT_ACTIVATION_CH_MULT;
    dw_conv_params.dilation.w = DEPTHWISE_OUT_ACTIVATION_DILATION_X;
    dw_conv_params.dilation.h = DEPTHWISE_OUT_ACTIVATION_DILATION_Y;

    dw_conv_params.input_offset = DEPTHWISE_OUT_ACTIVATION_INPUT_OFFSET;
    dw_conv_params.output_offset = DEPTHWISE_OUT_ACTIVATION_OUTPUT_OFFSET;
    dw_conv_params.activation.min = DEPTHWISE_OUT_ACTIVATION_OUT_ACTIVATION_MIN;
    dw_conv_params.activation.max = DEPTHWISE_OUT_ACTIVATION_OUT_ACTIVATION_MAX;
    quant_params.multiplier = (int32_t *)depthwise_out_activation_output_mult;
    quant_params.shift = (int32_t *)depthwise_out_activation_output_shift;

    ctx.size = arm_depthwise_conv_s8_opt_get_buffer_size(&input_dims, &filter_dims);

#if defined(ARM_MATH_DSP)
    TEST_ASSERT_TRUE(ctx.size > 0);
#else
    TEST_ASSERT_EQUAL(ctx.size, 0);
#endif

    ctx.buf = malloc(ctx.size);

    arm_cmsis_nn_status result = arm_depthwise_conv_s8_opt(&ctx,
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
        memset(ctx.buf, 0, ctx.size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(expected, result);
    TEST_ASSERT_TRUE(validate(output, depthwise_out_activation_output_ref, output_ref_size));
    memset(output, 0, sizeof(output));

    const int32_t buf_size =
        arm_depthwise_conv_wrapper_s8_get_buffer_size(&dw_conv_params, &input_dims, &filter_dims, &output_dims);

    TEST_ASSERT_EQUAL(buf_size, ctx.size);

    ctx.buf = malloc(buf_size);
    ctx.size = buf_size;

    result = arm_depthwise_conv_wrapper_s8(&ctx,
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
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(expected, result);
    TEST_ASSERT_TRUE(validate(output, depthwise_out_activation_output_ref, output_ref_size));
}

void depthwise_null_bias_0_arm_depthwise_conv_s8_opt(void)
{
    const arm_cmsis_nn_status expected = ARM_CMSIS_NN_SUCCESS;
    int8_t output[DEPTHWISE_NULL_BIAS_0_DST_SIZE] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_dw_conv_params dw_conv_params;
    cmsis_nn_per_channel_quant_params quant_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims bias_dims = {};
    cmsis_nn_dims output_dims;

    const int32_t *bias_data = get_bias_address(depthwise_null_bias_0_biases, DEPTHWISE_NULL_BIAS_0_OUT_CH);
    const int8_t *kernel_data = depthwise_null_bias_0_weights;
    const int8_t *input_data = depthwise_null_bias_0_input;

    input_dims.n = DEPTHWISE_NULL_BIAS_0_INPUT_BATCHES;
    input_dims.w = DEPTHWISE_NULL_BIAS_0_INPUT_W;
    input_dims.h = DEPTHWISE_NULL_BIAS_0_INPUT_H;
    input_dims.c = DEPTHWISE_NULL_BIAS_0_IN_CH;
    filter_dims.w = DEPTHWISE_NULL_BIAS_0_FILTER_X;
    filter_dims.h = DEPTHWISE_NULL_BIAS_0_FILTER_Y;
    output_dims.w = DEPTHWISE_NULL_BIAS_0_OUTPUT_W;
    output_dims.h = DEPTHWISE_NULL_BIAS_0_OUTPUT_H;
    output_dims.c = DEPTHWISE_NULL_BIAS_0_OUT_CH;

    dw_conv_params.padding.w = DEPTHWISE_NULL_BIAS_0_PAD_X;
    dw_conv_params.padding.h = DEPTHWISE_NULL_BIAS_0_PAD_Y;
    dw_conv_params.stride.w = DEPTHWISE_NULL_BIAS_0_STRIDE_X;
    dw_conv_params.stride.h = DEPTHWISE_NULL_BIAS_0_STRIDE_Y;
    dw_conv_params.dilation.w = DEPTHWISE_NULL_BIAS_0_DILATION_X;
    dw_conv_params.dilation.h = DEPTHWISE_NULL_BIAS_0_DILATION_Y;

    dw_conv_params.ch_mult = DEPTHWISE_NULL_BIAS_0_CH_MULT;

    dw_conv_params.input_offset = DEPTHWISE_NULL_BIAS_0_INPUT_OFFSET;
    dw_conv_params.output_offset = DEPTHWISE_NULL_BIAS_0_OUTPUT_OFFSET;
    dw_conv_params.activation.min = DEPTHWISE_NULL_BIAS_0_OUT_ACTIVATION_MIN;
    dw_conv_params.activation.max = DEPTHWISE_NULL_BIAS_0_OUT_ACTIVATION_MAX;
    quant_params.multiplier = (int32_t *)depthwise_null_bias_0_output_mult;
    quant_params.shift = (int32_t *)depthwise_null_bias_0_output_shift;

    ctx.size = arm_depthwise_conv_s8_opt_get_buffer_size(&input_dims, &filter_dims);

#if defined(ARM_MATH_DSP)
    TEST_ASSERT_TRUE(ctx.size > 0);
#else
    TEST_ASSERT_EQUAL(ctx.size, 0);
#endif

    ctx.buf = malloc(ctx.size);

    arm_cmsis_nn_status result = arm_depthwise_conv_s8_opt(&ctx,
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
        memset(ctx.buf, 0, ctx.size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(expected, result);
    TEST_ASSERT_TRUE(validate(output, depthwise_null_bias_0_output_ref, DEPTHWISE_NULL_BIAS_0_DST_SIZE));

    const int32_t buf_size =
        arm_depthwise_conv_wrapper_s8_get_buffer_size(&dw_conv_params, &input_dims, &filter_dims, &output_dims);

    TEST_ASSERT_EQUAL(buf_size, ctx.size);

    ctx.buf = malloc(buf_size);
    ctx.size = buf_size;

    result = arm_depthwise_conv_wrapper_s8(&ctx,
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
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(expected, result);
    TEST_ASSERT_TRUE(validate(output, depthwise_null_bias_0_output_ref, DEPTHWISE_NULL_BIAS_0_DST_SIZE));
}

void depthwise_x_stride_arm_depthwise_conv_s8_opt(void)
{
    const arm_cmsis_nn_status expected = ARM_CMSIS_NN_SUCCESS;
    int8_t output[DEPTHWISE_X_STRIDE_DST_SIZE] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_dw_conv_params dw_conv_params;
    cmsis_nn_per_channel_quant_params quant_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims bias_dims;
    cmsis_nn_dims output_dims;

    const int32_t *bias_data = get_bias_address(depthwise_x_stride_biases, DEPTHWISE_X_STRIDE_IN_CH);
    const int8_t *kernel_data = depthwise_x_stride_weights;
    const int8_t *input_data = depthwise_x_stride_input;

    input_dims.n = DEPTHWISE_X_STRIDE_INPUT_BATCHES;
    input_dims.w = DEPTHWISE_X_STRIDE_INPUT_W;
    input_dims.h = DEPTHWISE_X_STRIDE_INPUT_H;
    input_dims.c = DEPTHWISE_X_STRIDE_IN_CH;
    filter_dims.w = DEPTHWISE_X_STRIDE_FILTER_X;
    filter_dims.h = DEPTHWISE_X_STRIDE_FILTER_Y;
    output_dims.w = DEPTHWISE_X_STRIDE_OUTPUT_W;
    output_dims.h = DEPTHWISE_X_STRIDE_OUTPUT_H;
    output_dims.c = DEPTHWISE_X_STRIDE_OUT_CH;

    dw_conv_params.padding.w = DEPTHWISE_X_STRIDE_PAD_X;
    dw_conv_params.padding.h = DEPTHWISE_X_STRIDE_PAD_Y;
    dw_conv_params.stride.w = DEPTHWISE_X_STRIDE_STRIDE_X;
    dw_conv_params.stride.h = DEPTHWISE_X_STRIDE_STRIDE_Y;
    dw_conv_params.dilation.w = DEPTHWISE_X_STRIDE_DILATION_X;
    dw_conv_params.dilation.h = DEPTHWISE_X_STRIDE_DILATION_Y;

    dw_conv_params.ch_mult = 1;

    dw_conv_params.input_offset = DEPTHWISE_X_STRIDE_INPUT_OFFSET;
    dw_conv_params.output_offset = DEPTHWISE_X_STRIDE_OUTPUT_OFFSET;
    dw_conv_params.activation.min = DEPTHWISE_X_STRIDE_OUT_ACTIVATION_MIN;
    dw_conv_params.activation.max = DEPTHWISE_X_STRIDE_OUT_ACTIVATION_MAX;
    quant_params.multiplier = (int32_t *)depthwise_x_stride_output_mult;
    quant_params.shift = (int32_t *)depthwise_x_stride_output_shift;

    ctx.size = arm_depthwise_conv_s8_opt_get_buffer_size(&input_dims, &filter_dims);

#if defined(ARM_MATH_DSP)
    TEST_ASSERT_TRUE(ctx.size > 0);
#else
    TEST_ASSERT_EQUAL(ctx.size, 0);
#endif

    ctx.buf = malloc(ctx.size);

    arm_cmsis_nn_status result = arm_depthwise_conv_s8_opt(&ctx,
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
        memset(ctx.buf, 0, ctx.size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(expected, result);
    TEST_ASSERT_TRUE(validate(output, depthwise_x_stride_output_ref, DEPTHWISE_X_STRIDE_DST_SIZE));

    const int32_t wrapper_buf_size =
        arm_depthwise_conv_wrapper_s8_get_buffer_size(&dw_conv_params, &input_dims, &filter_dims, &output_dims);

    TEST_ASSERT_EQUAL(wrapper_buf_size, ctx.size);

    ctx.buf = malloc(wrapper_buf_size);

    result = arm_depthwise_conv_wrapper_s8(&ctx,
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
        memset(ctx.buf, 0, wrapper_buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(expected, result);
    TEST_ASSERT_TRUE(validate(output, depthwise_x_stride_output_ref, DEPTHWISE_X_STRIDE_DST_SIZE));
}

void buffer_size_arm_depthwise_conv_s8_opt(void)
{
    cmsis_nn_dw_conv_params conv_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims output_dims;

    input_dims.n = DEPTHWISE_X_STRIDE_INPUT_BATCHES;
    input_dims.w = DEPTHWISE_X_STRIDE_INPUT_W;
    input_dims.h = DEPTHWISE_X_STRIDE_INPUT_H;
    input_dims.c = DEPTHWISE_X_STRIDE_IN_CH;
    filter_dims.w = DEPTHWISE_X_STRIDE_FILTER_X;
    filter_dims.h = DEPTHWISE_X_STRIDE_FILTER_Y;
    output_dims.w = DEPTHWISE_X_STRIDE_OUTPUT_W;
    output_dims.h = DEPTHWISE_X_STRIDE_OUTPUT_H;
    output_dims.c = DEPTHWISE_X_STRIDE_OUT_CH;

    conv_params.padding.w = DEPTHWISE_X_STRIDE_PAD_X;
    conv_params.padding.h = DEPTHWISE_X_STRIDE_PAD_Y;
    conv_params.stride.w = DEPTHWISE_X_STRIDE_STRIDE_X;
    conv_params.stride.h = DEPTHWISE_X_STRIDE_STRIDE_Y;
    conv_params.dilation.w = DEPTHWISE_X_STRIDE_DILATION_X;
    conv_params.dilation.h = DEPTHWISE_X_STRIDE_DILATION_Y;
    conv_params.ch_mult = DEPTHWISE_X_STRIDE_CH_MULT;
    conv_params.input_offset = DEPTHWISE_X_STRIDE_INPUT_OFFSET;
    conv_params.output_offset = DEPTHWISE_X_STRIDE_OUTPUT_OFFSET;
    conv_params.activation.min = DEPTHWISE_X_STRIDE_OUT_ACTIVATION_MIN;
    conv_params.activation.max = DEPTHWISE_X_STRIDE_OUT_ACTIVATION_MAX;

    const int32_t buf_size = arm_depthwise_conv_s8_opt_get_buffer_size(&input_dims, &filter_dims);
    const int32_t wrapper_buf_size =
        arm_depthwise_conv_wrapper_s8_get_buffer_size(&conv_params, &input_dims, &filter_dims, &output_dims);

    TEST_ASSERT_EQUAL(wrapper_buf_size, buf_size);
}

void buffer_size_mve_arm_depthwise_conv_s8_opt(void)
{
#if defined(ARM_MATH_MVEI)
    cmsis_nn_dw_conv_params conv_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims output_dims;

    input_dims.n = DEPTHWISE_X_STRIDE_INPUT_BATCHES;
    input_dims.w = DEPTHWISE_X_STRIDE_INPUT_W;
    input_dims.h = DEPTHWISE_X_STRIDE_INPUT_H;
    input_dims.c = DEPTHWISE_X_STRIDE_IN_CH;
    filter_dims.w = DEPTHWISE_X_STRIDE_FILTER_X;
    filter_dims.h = DEPTHWISE_X_STRIDE_FILTER_Y;
    output_dims.w = DEPTHWISE_X_STRIDE_OUTPUT_W;
    output_dims.h = DEPTHWISE_X_STRIDE_OUTPUT_H;
    output_dims.c = DEPTHWISE_X_STRIDE_OUT_CH;

    conv_params.padding.w = DEPTHWISE_X_STRIDE_PAD_X;
    conv_params.padding.h = DEPTHWISE_X_STRIDE_PAD_Y;
    conv_params.stride.w = DEPTHWISE_X_STRIDE_STRIDE_X;
    conv_params.stride.h = DEPTHWISE_X_STRIDE_STRIDE_Y;
    conv_params.dilation.w = DEPTHWISE_X_STRIDE_DILATION_X;
    conv_params.dilation.h = DEPTHWISE_X_STRIDE_DILATION_Y;
    conv_params.ch_mult = DEPTHWISE_X_STRIDE_CH_MULT;
    conv_params.input_offset = DEPTHWISE_X_STRIDE_INPUT_OFFSET;
    conv_params.output_offset = DEPTHWISE_X_STRIDE_OUTPUT_OFFSET;
    conv_params.activation.min = DEPTHWISE_X_STRIDE_OUT_ACTIVATION_MIN;
    conv_params.activation.max = DEPTHWISE_X_STRIDE_OUT_ACTIVATION_MAX;

    const int32_t wrapper_buf_size =
        arm_depthwise_conv_wrapper_s8_get_buffer_size(&conv_params, &input_dims, &filter_dims, &output_dims);
    const int32_t mve_wrapper_buf_size =
        arm_depthwise_conv_wrapper_s8_get_buffer_size_mve(&conv_params, &input_dims, &filter_dims, &output_dims);

    TEST_ASSERT_EQUAL(wrapper_buf_size, mve_wrapper_buf_size);
#endif
}

void buffer_size_dsp_arm_depthwise_conv_s8_opt(void)
{
#if defined(ARM_MATH_DSP) && !defined(ARM_MATH_MVEI)
    cmsis_nn_dw_conv_params conv_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims output_dims;

    input_dims.n = DEPTHWISE_X_STRIDE_INPUT_BATCHES;
    input_dims.w = DEPTHWISE_X_STRIDE_INPUT_W;
    input_dims.h = DEPTHWISE_X_STRIDE_INPUT_H;
    input_dims.c = DEPTHWISE_X_STRIDE_IN_CH;
    filter_dims.w = DEPTHWISE_X_STRIDE_FILTER_X;
    filter_dims.h = DEPTHWISE_X_STRIDE_FILTER_Y;
    output_dims.w = DEPTHWISE_X_STRIDE_OUTPUT_W;
    output_dims.h = DEPTHWISE_X_STRIDE_OUTPUT_H;
    output_dims.c = DEPTHWISE_X_STRIDE_OUT_CH;

    conv_params.padding.w = DEPTHWISE_X_STRIDE_PAD_X;
    conv_params.padding.h = DEPTHWISE_X_STRIDE_PAD_Y;
    conv_params.stride.w = DEPTHWISE_X_STRIDE_STRIDE_X;
    conv_params.stride.h = DEPTHWISE_X_STRIDE_STRIDE_Y;
    conv_params.dilation.w = DEPTHWISE_X_STRIDE_DILATION_X;
    conv_params.dilation.h = DEPTHWISE_X_STRIDE_DILATION_Y;

    conv_params.ch_mult = DEPTHWISE_X_STRIDE_CH_MULT;

    conv_params.input_offset = DEPTHWISE_X_STRIDE_INPUT_OFFSET;
    conv_params.output_offset = DEPTHWISE_X_STRIDE_OUTPUT_OFFSET;
    conv_params.activation.min = DEPTHWISE_X_STRIDE_OUT_ACTIVATION_MIN;
    conv_params.activation.max = DEPTHWISE_X_STRIDE_OUT_ACTIVATION_MAX;

    const int32_t wrapper_buf_size =
        arm_depthwise_conv_wrapper_s8_get_buffer_size(&conv_params, &input_dims, &filter_dims, &output_dims);
    const int32_t dsp_wrapper_buf_size =
        arm_depthwise_conv_wrapper_s8_get_buffer_size_dsp(&conv_params, &input_dims, &filter_dims, &output_dims);

    TEST_ASSERT_EQUAL(wrapper_buf_size, dsp_wrapper_buf_size);
#endif
}
