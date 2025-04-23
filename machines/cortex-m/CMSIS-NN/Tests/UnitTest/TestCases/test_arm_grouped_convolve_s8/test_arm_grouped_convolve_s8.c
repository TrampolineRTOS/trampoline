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

#include <stdlib.h>

#include <arm_nnfunctions.h>
#include <unity.h>

#include "../TestData/grouped_conv_1/test_data.h"
#include "../TestData/grouped_conv_2/test_data.h"
#include "../TestData/grouped_conv_3/test_data.h"
#include "../TestData/grouped_conv_4/test_data.h"
#include "../Utils/validate.h"

void grouped_conv_arm_grouped_convolve_1_s8(void)
{
    const arm_cmsis_nn_status expected = ARM_CMSIS_NN_SUCCESS;
    int8_t output[GROUPED_CONV_1_DST_SIZE] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_conv_params conv_params;
    cmsis_nn_per_channel_quant_params quant_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims bias_dims;
    cmsis_nn_dims output_dims;

    const int32_t *bias_data = grouped_conv_1_biases;
    const int8_t *kernel_data = grouped_conv_1_weights;
    const int8_t *input_data = grouped_conv_1_input;
    const int8_t *output_ref = grouped_conv_1_output_ref;
    const int32_t output_ref_size = GROUPED_CONV_1_DST_SIZE;

    input_dims.n = GROUPED_CONV_1_INPUT_BATCHES;
    input_dims.w = GROUPED_CONV_1_INPUT_W;
    input_dims.h = GROUPED_CONV_1_INPUT_H;
    input_dims.c = GROUPED_CONV_1_IN_CH;
    filter_dims.w = GROUPED_CONV_1_FILTER_X;
    filter_dims.h = GROUPED_CONV_1_FILTER_Y;
    filter_dims.c = GROUPED_CONV_1_FILTER_CH;
    output_dims.w = GROUPED_CONV_1_OUTPUT_W;
    output_dims.h = GROUPED_CONV_1_OUTPUT_H;
    output_dims.c = GROUPED_CONV_1_OUT_CH;

    conv_params.padding.w = GROUPED_CONV_1_PAD_X;
    conv_params.padding.h = GROUPED_CONV_1_PAD_Y;
    conv_params.stride.w = GROUPED_CONV_1_STRIDE_X;
    conv_params.stride.h = GROUPED_CONV_1_STRIDE_Y;
    conv_params.dilation.w = GROUPED_CONV_1_DILATION_X;
    conv_params.dilation.h = GROUPED_CONV_1_DILATION_Y;

    conv_params.input_offset = GROUPED_CONV_1_INPUT_OFFSET;
    conv_params.output_offset = GROUPED_CONV_1_OUTPUT_OFFSET;
    conv_params.activation.min = GROUPED_CONV_1_OUT_ACTIVATION_MIN;
    conv_params.activation.max = GROUPED_CONV_1_OUT_ACTIVATION_MAX;
    quant_params.multiplier = (int32_t *)grouped_conv_1_output_mult;
    quant_params.shift = (int32_t *)grouped_conv_1_output_shift;

    int32_t buf_size = arm_convolve_s8_get_buffer_size(&input_dims, &filter_dims);
    ctx.buf = malloc(buf_size);
    ctx.size = 0;

    arm_cmsis_nn_status result = arm_convolve_s8(&ctx,
                                                 &conv_params,
                                                 &quant_params,
                                                 &input_dims,
                                                 input_data,
                                                 &filter_dims,
                                                 kernel_data,
                                                 &bias_dims,
                                                 bias_data,
                                                 NULL,
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
}

void grouped_conv_arm_grouped_convolve_2_s8(void)
{
    const arm_cmsis_nn_status expected = ARM_CMSIS_NN_SUCCESS;
    int8_t output[GROUPED_CONV_2_DST_SIZE] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_conv_params conv_params;
    cmsis_nn_per_channel_quant_params quant_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims bias_dims;
    cmsis_nn_dims output_dims;

    const int32_t *bias_data = grouped_conv_2_biases;
    const int8_t *kernel_data = grouped_conv_2_weights;
    const int8_t *input_data = grouped_conv_2_input;
    const int8_t *output_ref = grouped_conv_2_output_ref;
    const int32_t output_ref_size = GROUPED_CONV_2_DST_SIZE;

    input_dims.n = GROUPED_CONV_2_INPUT_BATCHES;
    input_dims.w = GROUPED_CONV_2_INPUT_W;
    input_dims.h = GROUPED_CONV_2_INPUT_H;
    input_dims.c = GROUPED_CONV_2_IN_CH;
    filter_dims.w = GROUPED_CONV_2_FILTER_X;
    filter_dims.h = GROUPED_CONV_2_FILTER_Y;
    filter_dims.c = GROUPED_CONV_2_FILTER_CH;
    output_dims.w = GROUPED_CONV_2_OUTPUT_W;
    output_dims.h = GROUPED_CONV_2_OUTPUT_H;
    output_dims.c = GROUPED_CONV_2_OUT_CH;

    conv_params.padding.w = GROUPED_CONV_2_PAD_X;
    conv_params.padding.h = GROUPED_CONV_2_PAD_Y;
    conv_params.stride.w = GROUPED_CONV_2_STRIDE_X;
    conv_params.stride.h = GROUPED_CONV_2_STRIDE_Y;
    conv_params.dilation.w = GROUPED_CONV_2_DILATION_X;
    conv_params.dilation.h = GROUPED_CONV_2_DILATION_Y;

    conv_params.input_offset = GROUPED_CONV_2_INPUT_OFFSET;
    conv_params.output_offset = GROUPED_CONV_2_OUTPUT_OFFSET;
    conv_params.activation.min = GROUPED_CONV_2_OUT_ACTIVATION_MIN;
    conv_params.activation.max = GROUPED_CONV_2_OUT_ACTIVATION_MAX;
    quant_params.multiplier = (int32_t *)grouped_conv_2_output_mult;
    quant_params.shift = (int32_t *)grouped_conv_2_output_shift;

    int32_t buf_size = arm_convolve_s8_get_buffer_size(&input_dims, &filter_dims);
    ctx.buf = malloc(buf_size);
    ctx.size = 0;

    arm_cmsis_nn_status result = arm_convolve_s8(&ctx,
                                                 &conv_params,
                                                 &quant_params,
                                                 &input_dims,
                                                 input_data,
                                                 &filter_dims,
                                                 kernel_data,
                                                 &bias_dims,
                                                 bias_data,
                                                 NULL,
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
}

void grouped_conv_arm_grouped_convolve_3_s8(void)
{
    const arm_cmsis_nn_status expected = ARM_CMSIS_NN_SUCCESS;
    int8_t output[GROUPED_CONV_3_DST_SIZE] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_conv_params conv_params;
    cmsis_nn_per_channel_quant_params quant_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims bias_dims;
    cmsis_nn_dims output_dims;

    const int32_t *bias_data = grouped_conv_3_biases;
    const int8_t *kernel_data = grouped_conv_3_weights;
    const int8_t *input_data = grouped_conv_3_input;
    const int8_t *output_ref = grouped_conv_3_output_ref;
    const int32_t output_ref_size = GROUPED_CONV_3_DST_SIZE;

    input_dims.n = GROUPED_CONV_3_INPUT_BATCHES;
    input_dims.w = GROUPED_CONV_3_INPUT_W;
    input_dims.h = GROUPED_CONV_3_INPUT_H;
    input_dims.c = GROUPED_CONV_3_IN_CH;
    filter_dims.w = GROUPED_CONV_3_FILTER_X;
    filter_dims.h = GROUPED_CONV_3_FILTER_Y;
    filter_dims.c = GROUPED_CONV_3_FILTER_CH;
    output_dims.w = GROUPED_CONV_3_OUTPUT_W;
    output_dims.h = GROUPED_CONV_3_OUTPUT_H;
    output_dims.c = GROUPED_CONV_3_OUT_CH;

    conv_params.padding.w = GROUPED_CONV_3_PAD_X;
    conv_params.padding.h = GROUPED_CONV_3_PAD_Y;
    conv_params.stride.w = GROUPED_CONV_3_STRIDE_X;
    conv_params.stride.h = GROUPED_CONV_3_STRIDE_Y;
    conv_params.dilation.w = GROUPED_CONV_3_DILATION_X;
    conv_params.dilation.h = GROUPED_CONV_3_DILATION_Y;

    conv_params.input_offset = GROUPED_CONV_3_INPUT_OFFSET;
    conv_params.output_offset = GROUPED_CONV_3_OUTPUT_OFFSET;
    conv_params.activation.min = GROUPED_CONV_3_OUT_ACTIVATION_MIN;
    conv_params.activation.max = GROUPED_CONV_3_OUT_ACTIVATION_MAX;
    quant_params.multiplier = (int32_t *)grouped_conv_3_output_mult;
    quant_params.shift = (int32_t *)grouped_conv_3_output_shift;

    int32_t buf_size = arm_convolve_s8_get_buffer_size(&input_dims, &filter_dims);
    ctx.buf = malloc(buf_size);
    ctx.size = 0;

    arm_cmsis_nn_status result = arm_convolve_s8(&ctx,
                                                 &conv_params,
                                                 &quant_params,
                                                 &input_dims,
                                                 input_data,
                                                 &filter_dims,
                                                 kernel_data,
                                                 &bias_dims,
                                                 bias_data,
                                                 NULL,
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
}

void grouped_conv_arm_grouped_convolve_4_s8(void)
{
    const arm_cmsis_nn_status expected = ARM_CMSIS_NN_SUCCESS;
    int8_t output[GROUPED_CONV_4_DST_SIZE] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_conv_params conv_params;
    cmsis_nn_per_channel_quant_params quant_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims bias_dims;
    cmsis_nn_dims output_dims;

    const int32_t *bias_data = grouped_conv_4_biases;
    const int8_t *kernel_data = grouped_conv_4_weights;
    const int8_t *input_data = grouped_conv_4_input;
    const int8_t *output_ref = grouped_conv_4_output_ref;
    const int32_t output_ref_size = GROUPED_CONV_4_DST_SIZE;

    input_dims.n = GROUPED_CONV_4_INPUT_BATCHES;
    input_dims.w = GROUPED_CONV_4_INPUT_W;
    input_dims.h = GROUPED_CONV_4_INPUT_H;
    input_dims.c = GROUPED_CONV_4_IN_CH;
    filter_dims.w = GROUPED_CONV_4_FILTER_X;
    filter_dims.h = GROUPED_CONV_4_FILTER_Y;
    filter_dims.c = GROUPED_CONV_4_FILTER_CH;
    output_dims.w = GROUPED_CONV_4_OUTPUT_W;
    output_dims.h = GROUPED_CONV_4_OUTPUT_H;
    output_dims.c = GROUPED_CONV_4_OUT_CH;

    conv_params.padding.w = GROUPED_CONV_4_PAD_X;
    conv_params.padding.h = GROUPED_CONV_4_PAD_Y;
    conv_params.stride.w = GROUPED_CONV_4_STRIDE_X;
    conv_params.stride.h = GROUPED_CONV_4_STRIDE_Y;
    conv_params.dilation.w = GROUPED_CONV_4_DILATION_X;
    conv_params.dilation.h = GROUPED_CONV_4_DILATION_Y;

    conv_params.input_offset = GROUPED_CONV_4_INPUT_OFFSET;
    conv_params.output_offset = GROUPED_CONV_4_OUTPUT_OFFSET;
    conv_params.activation.min = GROUPED_CONV_4_OUT_ACTIVATION_MIN;
    conv_params.activation.max = GROUPED_CONV_4_OUT_ACTIVATION_MAX;
    quant_params.multiplier = (int32_t *)grouped_conv_4_output_mult;
    quant_params.shift = (int32_t *)grouped_conv_4_output_shift;

    int32_t buf_size = arm_convolve_s8_get_buffer_size(&input_dims, &filter_dims);
    ctx.buf = malloc(buf_size);
    ctx.size = 0;

    arm_cmsis_nn_status result = arm_convolve_s8(&ctx,
                                                 &conv_params,
                                                 &quant_params,
                                                 &input_dims,
                                                 input_data,
                                                 &filter_dims,
                                                 kernel_data,
                                                 &bias_dims,
                                                 bias_data,
                                                 NULL,
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
}