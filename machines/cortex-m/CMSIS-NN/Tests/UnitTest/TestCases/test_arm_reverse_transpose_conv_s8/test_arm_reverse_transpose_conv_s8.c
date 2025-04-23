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
#include <unity.h>

#include "../TestData/reverse_transpose_conv_1/test_data.h"
#include "../TestData/reverse_transpose_conv_2/test_data.h"
#include "../TestData/reverse_transpose_conv_3/test_data.h"
#include "../TestData/reverse_transpose_conv_4/test_data.h"
#include "../Utils/utils.h"
#include "../Utils/validate.h"

void reverse_transpose_conv_1_arm_transpose_conv_s8(void)
{
    const arm_cmsis_nn_status expected = ARM_CMSIS_NN_SUCCESS;
    int8_t output[REVERSE_TRANSPOSE_CONV_1_DST_SIZE] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_context reverse_conv_ctx;
    cmsis_nn_transpose_conv_params transpose_conv_params;
    cmsis_nn_per_channel_quant_params quant_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims bias_dims = {0};
    cmsis_nn_dims output_dims;

    const int32_t *bias_data = reverse_transpose_conv_1_biases;
    const int8_t *kernel_data = reverse_transpose_conv_1_weights;
    const int8_t *input_data = reverse_transpose_conv_1_input;
    const int8_t *output_ref = reverse_transpose_conv_1_output_ref;
    const int32_t output_ref_size = REVERSE_TRANSPOSE_CONV_1_DST_SIZE;

    input_dims.n = REVERSE_TRANSPOSE_CONV_1_INPUT_BATCHES;
    input_dims.w = REVERSE_TRANSPOSE_CONV_1_INPUT_W;
    input_dims.h = REVERSE_TRANSPOSE_CONV_1_INPUT_H;
    input_dims.c = REVERSE_TRANSPOSE_CONV_1_IN_CH;
    filter_dims.w = REVERSE_TRANSPOSE_CONV_1_FILTER_X;
    filter_dims.h = REVERSE_TRANSPOSE_CONV_1_FILTER_Y;
    filter_dims.n = REVERSE_TRANSPOSE_CONV_1_OUT_CH;
    filter_dims.c = REVERSE_TRANSPOSE_CONV_1_IN_CH;
    output_dims.n = REVERSE_TRANSPOSE_CONV_1_INPUT_BATCHES;
    output_dims.w = REVERSE_TRANSPOSE_CONV_1_OUTPUT_W;
    output_dims.h = REVERSE_TRANSPOSE_CONV_1_OUTPUT_H;
    output_dims.c = REVERSE_TRANSPOSE_CONV_1_OUT_CH;

    transpose_conv_params.padding.w = REVERSE_TRANSPOSE_CONV_1_PAD_X;
    transpose_conv_params.padding.h = REVERSE_TRANSPOSE_CONV_1_PAD_Y;
    transpose_conv_params.padding_offsets.w = REVERSE_TRANSPOSE_CONV_1_PAD_X_WITH_OFFSET;
    transpose_conv_params.padding_offsets.h = REVERSE_TRANSPOSE_CONV_1_PAD_Y_WITH_OFFSET;

    transpose_conv_params.stride.w = REVERSE_TRANSPOSE_CONV_1_STRIDE_X;
    transpose_conv_params.stride.h = REVERSE_TRANSPOSE_CONV_1_STRIDE_Y;
    transpose_conv_params.dilation.w = REVERSE_TRANSPOSE_CONV_1_DILATION_X;
    transpose_conv_params.dilation.h = REVERSE_TRANSPOSE_CONV_1_DILATION_Y;

    transpose_conv_params.input_offset = REVERSE_TRANSPOSE_CONV_1_INPUT_OFFSET;
    transpose_conv_params.output_offset = REVERSE_TRANSPOSE_CONV_1_OUTPUT_OFFSET;
    transpose_conv_params.activation.min = REVERSE_TRANSPOSE_CONV_1_OUT_ACTIVATION_MIN;
    transpose_conv_params.activation.max = REVERSE_TRANSPOSE_CONV_1_OUT_ACTIVATION_MAX;
    quant_params.multiplier = (int32_t *)reverse_transpose_conv_1_output_mult;
    quant_params.shift = (int32_t *)reverse_transpose_conv_1_output_shift;

    const int32_t buf_size =
        arm_transpose_conv_s8_get_buffer_size(&transpose_conv_params, &input_dims, &filter_dims, &output_dims);
    ctx.buf = malloc(buf_size);
    ctx.size = buf_size;

    const int32_t reverse_conv_buf_size =
        arm_transpose_conv_s8_get_reverse_conv_buffer_size(&transpose_conv_params, &input_dims, &filter_dims);
    reverse_conv_ctx.buf = malloc(reverse_conv_buf_size);
    reverse_conv_ctx.size = reverse_conv_buf_size;

    arm_cmsis_nn_status result = arm_transpose_conv_wrapper_s8(&ctx,
                                                               &reverse_conv_ctx,
                                                               &transpose_conv_params,
                                                               &quant_params,
                                                               &input_dims,
                                                               input_data,
                                                               &filter_dims,
                                                               kernel_data,
                                                               &bias_dims,
                                                               bias_data,
                                                               &output_dims,
                                                               output);

    if (reverse_conv_ctx.buf)
    {
        // The caller is responsible to clear the scratch buffers for security reasons if applicable.
        memset(reverse_conv_ctx.buf, 0, reverse_conv_ctx.size);
        free(reverse_conv_ctx.buf);
    }

    if (ctx.buf)
    {
        // The caller is responsible to clear the scratch buffers for security reasons if applicable.
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }

    TEST_ASSERT_EQUAL(expected, result);
    TEST_ASSERT_TRUE(validate(output, output_ref, output_ref_size));
}

void reverse_transpose_conv_2_arm_transpose_conv_s8(void)
{
    const arm_cmsis_nn_status expected = ARM_CMSIS_NN_SUCCESS;
    int8_t output[REVERSE_TRANSPOSE_CONV_2_DST_SIZE] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_context reverse_conv_ctx;
    cmsis_nn_transpose_conv_params transpose_conv_params;
    cmsis_nn_per_channel_quant_params quant_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims bias_dims = {0};
    cmsis_nn_dims output_dims;

    const int32_t *bias_data = reverse_transpose_conv_2_biases;
    const int8_t *kernel_data = reverse_transpose_conv_2_weights;
    const int8_t *input_data = reverse_transpose_conv_2_input;
    const int8_t *output_ref = reverse_transpose_conv_2_output_ref;
    const int32_t output_ref_size = REVERSE_TRANSPOSE_CONV_2_DST_SIZE;

    input_dims.n = REVERSE_TRANSPOSE_CONV_2_INPUT_BATCHES;
    input_dims.w = REVERSE_TRANSPOSE_CONV_2_INPUT_W;
    input_dims.h = REVERSE_TRANSPOSE_CONV_2_INPUT_H;
    input_dims.c = REVERSE_TRANSPOSE_CONV_2_IN_CH;
    filter_dims.w = REVERSE_TRANSPOSE_CONV_2_FILTER_X;
    filter_dims.h = REVERSE_TRANSPOSE_CONV_2_FILTER_Y;
    filter_dims.n = REVERSE_TRANSPOSE_CONV_2_OUT_CH;
    filter_dims.c = REVERSE_TRANSPOSE_CONV_2_IN_CH;
    output_dims.n = REVERSE_TRANSPOSE_CONV_2_INPUT_BATCHES;
    output_dims.w = REVERSE_TRANSPOSE_CONV_2_OUTPUT_W;
    output_dims.h = REVERSE_TRANSPOSE_CONV_2_OUTPUT_H;
    output_dims.c = REVERSE_TRANSPOSE_CONV_2_OUT_CH;

    transpose_conv_params.padding.w = REVERSE_TRANSPOSE_CONV_2_PAD_X;
    transpose_conv_params.padding.h = REVERSE_TRANSPOSE_CONV_2_PAD_Y;
    transpose_conv_params.padding_offsets.w = REVERSE_TRANSPOSE_CONV_2_PAD_X_WITH_OFFSET;
    transpose_conv_params.padding_offsets.h = REVERSE_TRANSPOSE_CONV_2_PAD_Y_WITH_OFFSET;

    transpose_conv_params.stride.w = REVERSE_TRANSPOSE_CONV_2_STRIDE_X;
    transpose_conv_params.stride.h = REVERSE_TRANSPOSE_CONV_2_STRIDE_Y;
    transpose_conv_params.dilation.w = REVERSE_TRANSPOSE_CONV_2_DILATION_X;
    transpose_conv_params.dilation.h = REVERSE_TRANSPOSE_CONV_2_DILATION_Y;

    transpose_conv_params.input_offset = REVERSE_TRANSPOSE_CONV_2_INPUT_OFFSET;
    transpose_conv_params.output_offset = REVERSE_TRANSPOSE_CONV_2_OUTPUT_OFFSET;
    transpose_conv_params.activation.min = REVERSE_TRANSPOSE_CONV_2_OUT_ACTIVATION_MIN;
    transpose_conv_params.activation.max = REVERSE_TRANSPOSE_CONV_2_OUT_ACTIVATION_MAX;
    quant_params.multiplier = (int32_t *)reverse_transpose_conv_2_output_mult;
    quant_params.shift = (int32_t *)reverse_transpose_conv_2_output_shift;

    const int32_t buf_size =
        arm_transpose_conv_s8_get_buffer_size(&transpose_conv_params, &input_dims, &filter_dims, &output_dims);
    ctx.buf = malloc(buf_size);
    ctx.size = buf_size;

    const int32_t reverse_conv_buf_size =
        arm_transpose_conv_s8_get_reverse_conv_buffer_size(&transpose_conv_params, &input_dims, &filter_dims);
    reverse_conv_ctx.buf = malloc(reverse_conv_buf_size);
    reverse_conv_ctx.size = reverse_conv_buf_size;

    arm_cmsis_nn_status result = arm_transpose_conv_wrapper_s8(&ctx,
                                                               &reverse_conv_ctx,
                                                               &transpose_conv_params,
                                                               &quant_params,
                                                               &input_dims,
                                                               input_data,
                                                               &filter_dims,
                                                               kernel_data,
                                                               &bias_dims,
                                                               bias_data,
                                                               &output_dims,
                                                               output);

    if (reverse_conv_ctx.buf)
    {
        // The caller is responsible to clear the scratch buffers for security reasons if applicable.
        memset(reverse_conv_ctx.buf, 0, reverse_conv_ctx.size);
        free(reverse_conv_ctx.buf);
    }

    if (ctx.buf)
    {
        // The caller is responsible to clear the scratch buffers for security reasons if applicable.
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(expected, result);
    TEST_ASSERT_TRUE(validate(output, output_ref, output_ref_size));
}

void reverse_transpose_conv_3_arm_transpose_conv_s8(void)
{
    const arm_cmsis_nn_status expected = ARM_CMSIS_NN_SUCCESS;
    int8_t output[REVERSE_TRANSPOSE_CONV_3_DST_SIZE] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_context reverse_conv_ctx;
    cmsis_nn_transpose_conv_params transpose_conv_params;
    cmsis_nn_per_channel_quant_params quant_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims bias_dims = {0};
    cmsis_nn_dims output_dims;

    const int32_t *bias_data = reverse_transpose_conv_3_biases;
    const int8_t *kernel_data = reverse_transpose_conv_3_weights;
    const int8_t *input_data = reverse_transpose_conv_3_input;
    const int8_t *output_ref = reverse_transpose_conv_3_output_ref;
    const int32_t output_ref_size = REVERSE_TRANSPOSE_CONV_3_DST_SIZE;

    input_dims.n = REVERSE_TRANSPOSE_CONV_3_INPUT_BATCHES;
    input_dims.w = REVERSE_TRANSPOSE_CONV_3_INPUT_W;
    input_dims.h = REVERSE_TRANSPOSE_CONV_3_INPUT_H;
    input_dims.c = REVERSE_TRANSPOSE_CONV_3_IN_CH;
    filter_dims.w = REVERSE_TRANSPOSE_CONV_3_FILTER_X;
    filter_dims.h = REVERSE_TRANSPOSE_CONV_3_FILTER_Y;
    filter_dims.n = REVERSE_TRANSPOSE_CONV_3_OUT_CH;
    filter_dims.c = REVERSE_TRANSPOSE_CONV_3_IN_CH;
    output_dims.n = REVERSE_TRANSPOSE_CONV_3_INPUT_BATCHES;
    output_dims.w = REVERSE_TRANSPOSE_CONV_3_OUTPUT_W;
    output_dims.h = REVERSE_TRANSPOSE_CONV_3_OUTPUT_H;
    output_dims.c = REVERSE_TRANSPOSE_CONV_3_OUT_CH;

    transpose_conv_params.padding.w = REVERSE_TRANSPOSE_CONV_3_PAD_X;
    transpose_conv_params.padding.h = REVERSE_TRANSPOSE_CONV_3_PAD_Y;
    transpose_conv_params.padding_offsets.w = REVERSE_TRANSPOSE_CONV_3_PAD_X_WITH_OFFSET;
    transpose_conv_params.padding_offsets.h = REVERSE_TRANSPOSE_CONV_3_PAD_Y_WITH_OFFSET;

    transpose_conv_params.stride.w = REVERSE_TRANSPOSE_CONV_3_STRIDE_X;
    transpose_conv_params.stride.h = REVERSE_TRANSPOSE_CONV_3_STRIDE_Y;
    transpose_conv_params.dilation.w = REVERSE_TRANSPOSE_CONV_3_DILATION_X;
    transpose_conv_params.dilation.h = REVERSE_TRANSPOSE_CONV_3_DILATION_Y;

    transpose_conv_params.input_offset = REVERSE_TRANSPOSE_CONV_3_INPUT_OFFSET;
    transpose_conv_params.output_offset = REVERSE_TRANSPOSE_CONV_3_OUTPUT_OFFSET;
    transpose_conv_params.activation.min = REVERSE_TRANSPOSE_CONV_3_OUT_ACTIVATION_MIN;
    transpose_conv_params.activation.max = REVERSE_TRANSPOSE_CONV_3_OUT_ACTIVATION_MAX;
    quant_params.multiplier = (int32_t *)reverse_transpose_conv_3_output_mult;
    quant_params.shift = (int32_t *)reverse_transpose_conv_3_output_shift;

    const int32_t buf_size =
        arm_transpose_conv_s8_get_buffer_size(&transpose_conv_params, &input_dims, &filter_dims, &output_dims);
    ctx.buf = malloc(buf_size);
    ctx.size = buf_size;

    const int32_t reverse_conv_buf_size =
        arm_transpose_conv_s8_get_reverse_conv_buffer_size(&transpose_conv_params, &input_dims, &filter_dims);
    reverse_conv_ctx.buf = malloc(reverse_conv_buf_size);
    reverse_conv_ctx.size = reverse_conv_buf_size;

    arm_cmsis_nn_status result = arm_transpose_conv_wrapper_s8(&ctx,
                                                               &reverse_conv_ctx,
                                                               &transpose_conv_params,
                                                               &quant_params,
                                                               &input_dims,
                                                               input_data,
                                                               &filter_dims,
                                                               kernel_data,
                                                               &bias_dims,
                                                               bias_data,
                                                               &output_dims,
                                                               output);

    if (reverse_conv_ctx.buf)
    {
        // The caller is responsible to clear the scratch buffers for security reasons if applicable.
        memset(reverse_conv_ctx.buf, 0, reverse_conv_ctx.size);
        free(reverse_conv_ctx.buf);
    }

    if (ctx.buf)
    {
        // The caller is responsible to clear the scratch buffers for security reasons if applicable.
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(expected, result);
    TEST_ASSERT_TRUE(validate(output, output_ref, output_ref_size));
}

void reverse_transpose_conv_4_arm_transpose_conv_s8(void)
{
    const arm_cmsis_nn_status expected = ARM_CMSIS_NN_SUCCESS;
    int8_t output[REVERSE_TRANSPOSE_CONV_4_DST_SIZE] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_context reverse_conv_ctx;
    cmsis_nn_transpose_conv_params transpose_conv_params;
    cmsis_nn_per_channel_quant_params quant_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims bias_dims = {0};
    cmsis_nn_dims output_dims;

    const int32_t *bias_data = reverse_transpose_conv_4_biases;
    const int8_t *kernel_data = reverse_transpose_conv_4_weights;
    const int8_t *input_data = reverse_transpose_conv_4_input;
    const int8_t *output_ref = reverse_transpose_conv_4_output_ref;
    const int32_t output_ref_size = REVERSE_TRANSPOSE_CONV_4_DST_SIZE;

    input_dims.n = REVERSE_TRANSPOSE_CONV_4_INPUT_BATCHES;
    input_dims.w = REVERSE_TRANSPOSE_CONV_4_INPUT_W;
    input_dims.h = REVERSE_TRANSPOSE_CONV_4_INPUT_H;
    input_dims.c = REVERSE_TRANSPOSE_CONV_4_IN_CH;
    filter_dims.w = REVERSE_TRANSPOSE_CONV_4_FILTER_X;
    filter_dims.h = REVERSE_TRANSPOSE_CONV_4_FILTER_Y;
    filter_dims.n = REVERSE_TRANSPOSE_CONV_4_OUT_CH;
    filter_dims.c = REVERSE_TRANSPOSE_CONV_4_IN_CH;
    output_dims.n = REVERSE_TRANSPOSE_CONV_4_INPUT_BATCHES;
    output_dims.w = REVERSE_TRANSPOSE_CONV_4_OUTPUT_W;
    output_dims.h = REVERSE_TRANSPOSE_CONV_4_OUTPUT_H;
    output_dims.c = REVERSE_TRANSPOSE_CONV_4_OUT_CH;

    transpose_conv_params.padding.w = REVERSE_TRANSPOSE_CONV_4_PAD_X;
    transpose_conv_params.padding.h = REVERSE_TRANSPOSE_CONV_4_PAD_Y;
    transpose_conv_params.padding_offsets.w = REVERSE_TRANSPOSE_CONV_4_PAD_X_WITH_OFFSET;
    transpose_conv_params.padding_offsets.h = REVERSE_TRANSPOSE_CONV_4_PAD_Y_WITH_OFFSET;

    transpose_conv_params.stride.w = REVERSE_TRANSPOSE_CONV_4_STRIDE_X;
    transpose_conv_params.stride.h = REVERSE_TRANSPOSE_CONV_4_STRIDE_Y;
    transpose_conv_params.dilation.w = REVERSE_TRANSPOSE_CONV_4_DILATION_X;
    transpose_conv_params.dilation.h = REVERSE_TRANSPOSE_CONV_4_DILATION_Y;

    transpose_conv_params.input_offset = REVERSE_TRANSPOSE_CONV_4_INPUT_OFFSET;
    transpose_conv_params.output_offset = REVERSE_TRANSPOSE_CONV_4_OUTPUT_OFFSET;
    transpose_conv_params.activation.min = REVERSE_TRANSPOSE_CONV_4_OUT_ACTIVATION_MIN;
    transpose_conv_params.activation.max = REVERSE_TRANSPOSE_CONV_4_OUT_ACTIVATION_MAX;
    quant_params.multiplier = (int32_t *)reverse_transpose_conv_4_output_mult;
    quant_params.shift = (int32_t *)reverse_transpose_conv_4_output_shift;

    const int32_t buf_size =
        arm_transpose_conv_s8_get_buffer_size(&transpose_conv_params, &input_dims, &filter_dims, &output_dims);
    ctx.buf = malloc(buf_size);
    ctx.size = buf_size;

    const int32_t reverse_conv_buf_size =
        arm_transpose_conv_s8_get_reverse_conv_buffer_size(&transpose_conv_params, &input_dims, &filter_dims);
    reverse_conv_ctx.buf = malloc(reverse_conv_buf_size);
    reverse_conv_ctx.size = reverse_conv_buf_size;

    arm_cmsis_nn_status result = arm_transpose_conv_wrapper_s8(&ctx,
                                                               &reverse_conv_ctx,
                                                               &transpose_conv_params,
                                                               &quant_params,
                                                               &input_dims,
                                                               input_data,
                                                               &filter_dims,
                                                               kernel_data,
                                                               &bias_dims,
                                                               bias_data,
                                                               &output_dims,
                                                               output);

    if (reverse_conv_ctx.buf)
    {
        // The caller is responsible to clear the scratch buffers for security reasons if applicable.
        memset(reverse_conv_ctx.buf, 0, reverse_conv_ctx.size);
        free(reverse_conv_ctx.buf);
    }

    if (ctx.buf)
    {
        // The caller is responsible to clear the scratch buffers for security reasons if applicable.
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(expected, result);
    TEST_ASSERT_TRUE(validate(output, output_ref, output_ref_size));
}
