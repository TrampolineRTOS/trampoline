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

#include "arm_nnfunctions.h"
#include "unity.h"

#include "../TestData/avgpooling/test_data.h"
#include "../TestData/avgpooling_1/test_data.h"
#include "../TestData/avgpooling_2/test_data.h"
#include "../TestData/avgpooling_3/test_data.h"
#include "../TestData/avgpooling_4/test_data.h"
#include "../TestData/avgpooling_5/test_data.h"
#include "../Utils/validate.h"

void avgpooling_arm_avgpool_s8(void)
{
    const arm_cmsis_nn_status expected = ARM_CMSIS_NN_SUCCESS;
    int8_t output[AVGPOOLING_OUTPUT_W * AVGPOOLING_OUTPUT_H * AVGPOOLING_BATCH_SIZE * AVGPOOLING_OUTPUT_C] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_pool_params pool_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims output_dims;

    const int8_t *input_data = avgpooling_input_tensor;

    input_dims.n = AVGPOOLING_BATCH_SIZE;
    input_dims.w = AVGPOOLING_INPUT_W;
    input_dims.h = AVGPOOLING_INPUT_H;
    input_dims.c = AVGPOOLING_INPUT_C;
    filter_dims.w = AVGPOOLING_FILTER_W;
    filter_dims.h = AVGPOOLING_FILTER_H;
    output_dims.w = AVGPOOLING_OUTPUT_W;
    output_dims.h = AVGPOOLING_OUTPUT_H;
    output_dims.c = AVGPOOLING_OUTPUT_C;

    pool_params.padding.w = AVGPOOLING_PADDING_W;
    pool_params.padding.h = AVGPOOLING_PADDING_H;
    pool_params.stride.w = AVGPOOLING_STRIDE_W;
    pool_params.stride.h = AVGPOOLING_STRIDE_H;

    pool_params.activation.min = AVGPOOLING_ACTIVATION_MIN;
    pool_params.activation.max = AVGPOOLING_ACTIVATION_MAX;

    ctx.size = arm_avgpool_s8_get_buffer_size(AVGPOOLING_OUTPUT_W, AVGPOOLING_INPUT_C);
    ctx.buf = malloc(ctx.size);

    arm_cmsis_nn_status result =
        arm_avgpool_s8(&ctx, &pool_params, &input_dims, input_data, &filter_dims, &output_dims, output);

    if (ctx.buf)
    {
        // The caller is responsible to clear the scratch buffers for security reasons if applicable.
        memset(ctx.buf, 0, ctx.size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(expected, result);
    TEST_ASSERT_TRUE(validate(output,
                              avgpooling_output,
                              AVGPOOLING_OUTPUT_W * AVGPOOLING_OUTPUT_H * AVGPOOLING_BATCH_SIZE * AVGPOOLING_OUTPUT_C));
}

void avgpooling_1_arm_avgpool_s8(void)
{
    const arm_cmsis_nn_status expected = ARM_CMSIS_NN_SUCCESS;
    int8_t output[AVGPOOLING_1_OUTPUT_W * AVGPOOLING_1_OUTPUT_H * AVGPOOLING_1_BATCH_SIZE * AVGPOOLING_1_OUTPUT_C] = {
        0};

    cmsis_nn_context ctx;
    cmsis_nn_pool_params pool_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims output_dims;

    const int8_t *input_data = avgpooling_1_input_tensor;

    input_dims.n = AVGPOOLING_1_BATCH_SIZE;
    input_dims.w = AVGPOOLING_1_INPUT_W;
    input_dims.h = AVGPOOLING_1_INPUT_H;
    input_dims.c = AVGPOOLING_1_INPUT_C;
    filter_dims.w = AVGPOOLING_1_FILTER_W;
    filter_dims.h = AVGPOOLING_1_FILTER_H;
    output_dims.w = AVGPOOLING_1_OUTPUT_W;
    output_dims.h = AVGPOOLING_1_OUTPUT_H;
    output_dims.c = AVGPOOLING_1_OUTPUT_C;

    pool_params.padding.w = AVGPOOLING_1_PADDING_W;
    pool_params.padding.h = AVGPOOLING_1_PADDING_H;
    pool_params.stride.w = AVGPOOLING_1_STRIDE_W;
    pool_params.stride.h = AVGPOOLING_1_STRIDE_H;

    pool_params.activation.min = AVGPOOLING_1_ACTIVATION_MIN;
    pool_params.activation.max = AVGPOOLING_1_ACTIVATION_MAX;

    ctx.size = arm_avgpool_s8_get_buffer_size(AVGPOOLING_1_OUTPUT_W, AVGPOOLING_1_INPUT_C);
    ctx.buf = malloc(ctx.size);

    arm_cmsis_nn_status result =
        arm_avgpool_s8(&ctx, &pool_params, &input_dims, input_data, &filter_dims, &output_dims, output);

    if (ctx.buf)
    {
        memset(ctx.buf, 0, ctx.size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(expected, result);
    TEST_ASSERT_TRUE(
        validate(output,
                 avgpooling_1_output,
                 AVGPOOLING_1_OUTPUT_W * AVGPOOLING_1_OUTPUT_H * AVGPOOLING_1_BATCH_SIZE * AVGPOOLING_1_OUTPUT_C));
}

void avgpooling_2_arm_avgpool_s8(void)
{
    const arm_cmsis_nn_status expected = ARM_CMSIS_NN_SUCCESS;
    int8_t output[AVGPOOLING_2_OUTPUT_W * AVGPOOLING_2_OUTPUT_H * AVGPOOLING_2_BATCH_SIZE * AVGPOOLING_2_OUTPUT_C] = {
        0};

    cmsis_nn_context ctx;
    cmsis_nn_pool_params pool_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims output_dims;

    const int8_t *input_data = avgpooling_2_input_tensor;

    input_dims.n = AVGPOOLING_2_BATCH_SIZE;
    input_dims.w = AVGPOOLING_2_INPUT_W;
    input_dims.h = AVGPOOLING_2_INPUT_H;
    input_dims.c = AVGPOOLING_2_INPUT_C;
    filter_dims.w = AVGPOOLING_2_FILTER_W;
    filter_dims.h = AVGPOOLING_2_FILTER_H;
    output_dims.w = AVGPOOLING_2_OUTPUT_W;
    output_dims.h = AVGPOOLING_2_OUTPUT_H;
    output_dims.c = AVGPOOLING_2_OUTPUT_C;

    pool_params.padding.w = AVGPOOLING_2_PADDING_W;
    pool_params.padding.h = AVGPOOLING_2_PADDING_H;
    pool_params.stride.w = AVGPOOLING_2_STRIDE_W;
    pool_params.stride.h = AVGPOOLING_2_STRIDE_H;

    pool_params.activation.min = AVGPOOLING_2_ACTIVATION_MIN;
    pool_params.activation.max = AVGPOOLING_2_ACTIVATION_MAX;

    ctx.size = arm_avgpool_s8_get_buffer_size(AVGPOOLING_2_OUTPUT_W, AVGPOOLING_2_INPUT_C);
    ctx.buf = malloc(ctx.size);

    arm_cmsis_nn_status result =
        arm_avgpool_s8(&ctx, &pool_params, &input_dims, input_data, &filter_dims, &output_dims, output);

    if (ctx.buf)
    {
        memset(ctx.buf, 0, ctx.size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(expected, result);
    TEST_ASSERT_TRUE(
        validate(output,
                 avgpooling_2_output,
                 AVGPOOLING_2_OUTPUT_W * AVGPOOLING_2_OUTPUT_H * AVGPOOLING_2_BATCH_SIZE * AVGPOOLING_2_OUTPUT_C));
}

void avgpooling_3_arm_avgpool_s8(void)
{
    const arm_cmsis_nn_status expected = ARM_CMSIS_NN_SUCCESS;
    int8_t output[AVGPOOLING_3_OUTPUT_W * AVGPOOLING_3_OUTPUT_H * AVGPOOLING_3_BATCH_SIZE * AVGPOOLING_3_OUTPUT_C] = {
        0};

    cmsis_nn_context ctx;
    cmsis_nn_pool_params pool_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims output_dims;

    const int8_t *input_data = avgpooling_3_input_tensor;

    input_dims.n = AVGPOOLING_3_BATCH_SIZE;
    input_dims.w = AVGPOOLING_3_INPUT_W;
    input_dims.h = AVGPOOLING_3_INPUT_H;
    input_dims.c = AVGPOOLING_3_INPUT_C;
    filter_dims.w = AVGPOOLING_3_FILTER_W;
    filter_dims.h = AVGPOOLING_3_FILTER_H;
    output_dims.w = AVGPOOLING_3_OUTPUT_W;
    output_dims.h = AVGPOOLING_3_OUTPUT_H;
    output_dims.c = AVGPOOLING_3_OUTPUT_C;

    pool_params.padding.w = AVGPOOLING_3_PADDING_W;
    pool_params.padding.h = AVGPOOLING_3_PADDING_H;
    pool_params.stride.w = AVGPOOLING_3_STRIDE_W;
    pool_params.stride.h = AVGPOOLING_3_STRIDE_H;

    pool_params.activation.min = AVGPOOLING_3_ACTIVATION_MIN;
    pool_params.activation.max = AVGPOOLING_3_ACTIVATION_MAX;

    ctx.size = arm_avgpool_s8_get_buffer_size(AVGPOOLING_3_OUTPUT_W, AVGPOOLING_3_INPUT_C);
    ctx.buf = malloc(ctx.size);

    arm_cmsis_nn_status result =
        arm_avgpool_s8(&ctx, &pool_params, &input_dims, input_data, &filter_dims, &output_dims, output);

    if (ctx.buf)
    {
        memset(ctx.buf, 0, ctx.size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(expected, result);
    TEST_ASSERT_TRUE(
        validate(output,
                 avgpooling_3_output,
                 AVGPOOLING_3_OUTPUT_W * AVGPOOLING_3_OUTPUT_H * AVGPOOLING_3_BATCH_SIZE * AVGPOOLING_3_OUTPUT_C));
}

void avgpooling_4_arm_avgpool_s8(void)
{
    const arm_cmsis_nn_status expected = ARM_CMSIS_NN_SUCCESS;
    int8_t output[AVGPOOLING_4_OUTPUT_W * AVGPOOLING_4_OUTPUT_H * AVGPOOLING_4_BATCH_SIZE * AVGPOOLING_4_OUTPUT_C] = {
        0};

    cmsis_nn_context ctx;
    cmsis_nn_pool_params pool_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims output_dims;

    const int8_t *input_data = avgpooling_4_input_tensor;

    input_dims.n = AVGPOOLING_4_BATCH_SIZE;
    input_dims.w = AVGPOOLING_4_INPUT_W;
    input_dims.h = AVGPOOLING_4_INPUT_H;
    input_dims.c = AVGPOOLING_4_INPUT_C;
    filter_dims.w = AVGPOOLING_4_FILTER_W;
    filter_dims.h = AVGPOOLING_4_FILTER_H;
    output_dims.w = AVGPOOLING_4_OUTPUT_W;
    output_dims.h = AVGPOOLING_4_OUTPUT_H;
    output_dims.c = AVGPOOLING_4_OUTPUT_C;

    pool_params.padding.w = AVGPOOLING_4_PADDING_W;
    pool_params.padding.h = AVGPOOLING_4_PADDING_H;
    pool_params.stride.w = AVGPOOLING_4_STRIDE_W;
    pool_params.stride.h = AVGPOOLING_4_STRIDE_H;

    pool_params.activation.min = AVGPOOLING_4_ACTIVATION_MIN;
    pool_params.activation.max = AVGPOOLING_4_ACTIVATION_MAX;

    ctx.size = arm_avgpool_s8_get_buffer_size(AVGPOOLING_4_OUTPUT_W, AVGPOOLING_4_INPUT_C);
    ctx.buf = malloc(ctx.size);

    arm_cmsis_nn_status result =
        arm_avgpool_s8(&ctx, &pool_params, &input_dims, input_data, &filter_dims, &output_dims, output);

    if (ctx.buf)
    {
        memset(ctx.buf, 0, ctx.size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(expected, result);
    TEST_ASSERT_TRUE(
        validate(output,
                 avgpooling_4_output,
                 AVGPOOLING_4_OUTPUT_W * AVGPOOLING_4_OUTPUT_H * AVGPOOLING_4_BATCH_SIZE * AVGPOOLING_4_OUTPUT_C));
}

void avgpooling_5_arm_avgpool_s8(void)
{
    const arm_cmsis_nn_status expected = ARM_CMSIS_NN_SUCCESS;
    int8_t output[AVGPOOLING_5_OUTPUT_W * AVGPOOLING_5_OUTPUT_H * AVGPOOLING_5_BATCH_SIZE * AVGPOOLING_5_OUTPUT_C] = {
        0};

    cmsis_nn_context ctx;
    cmsis_nn_pool_params pool_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims output_dims;

    const int8_t *input_data = avgpooling_5_input_tensor;

    input_dims.n = AVGPOOLING_5_BATCH_SIZE;
    input_dims.w = AVGPOOLING_5_INPUT_W;
    input_dims.h = AVGPOOLING_5_INPUT_H;
    input_dims.c = AVGPOOLING_5_INPUT_C;
    filter_dims.w = AVGPOOLING_5_FILTER_W;
    filter_dims.h = AVGPOOLING_5_FILTER_H;
    output_dims.w = AVGPOOLING_5_OUTPUT_W;
    output_dims.h = AVGPOOLING_5_OUTPUT_H;
    output_dims.c = AVGPOOLING_5_OUTPUT_C;

    pool_params.padding.w = AVGPOOLING_5_PADDING_W;
    pool_params.padding.h = AVGPOOLING_5_PADDING_H;
    pool_params.stride.w = AVGPOOLING_5_STRIDE_W;
    pool_params.stride.h = AVGPOOLING_5_STRIDE_H;

    pool_params.activation.min = AVGPOOLING_5_ACTIVATION_MIN;
    pool_params.activation.max = AVGPOOLING_5_ACTIVATION_MAX;

    ctx.size = arm_avgpool_s8_get_buffer_size(AVGPOOLING_5_OUTPUT_W, AVGPOOLING_5_INPUT_C);
    ctx.buf = malloc(ctx.size);

    arm_cmsis_nn_status result =
        arm_avgpool_s8(&ctx, &pool_params, &input_dims, input_data, &filter_dims, &output_dims, output);

    if (ctx.buf)
    {
        memset(ctx.buf, 0, ctx.size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(expected, result);
    TEST_ASSERT_TRUE(
        validate(output,
                 avgpooling_5_output,
                 AVGPOOLING_5_OUTPUT_W * AVGPOOLING_5_OUTPUT_H * AVGPOOLING_5_BATCH_SIZE * AVGPOOLING_5_OUTPUT_C));
}

void buffer_size_mve_arm_avgpool_s8(void)
{
#if defined(ARM_MATH_MVEI)
    const int32_t buf_size = arm_avgpool_s8_get_buffer_size(AVGPOOLING_5_OUTPUT_W, AVGPOOLING_5_INPUT_C);
    const int32_t mve_buf_size = arm_avgpool_s8_get_buffer_size_mve(AVGPOOLING_5_OUTPUT_W, AVGPOOLING_5_INPUT_C);

    TEST_ASSERT_EQUAL(buf_size, mve_buf_size);
#endif
}

void buffer_size_dsp_arm_avgpool_s8(void)
{
#if defined(ARM_MATH_DSP) && !defined(ARM_MATH_MVEI)
    const int32_t buf_size = arm_avgpool_s8_get_buffer_size(AVGPOOLING_5_OUTPUT_W, AVGPOOLING_5_INPUT_C);
    const int32_t dsp_buf_size = arm_avgpool_s8_get_buffer_size_dsp(AVGPOOLING_5_OUTPUT_W, AVGPOOLING_5_INPUT_C);

    TEST_ASSERT_EQUAL(buf_size, dsp_buf_size);
#endif
}

void avgpooling_param_fail_arm_avgpool_s8(void)
{
    const arm_cmsis_nn_status expected = ARM_CMSIS_NN_ARG_ERROR;
    int8_t output[AVGPOOLING_5_OUTPUT_W * AVGPOOLING_5_OUTPUT_H * AVGPOOLING_5_BATCH_SIZE * AVGPOOLING_5_OUTPUT_C] = {
        0};

    cmsis_nn_context ctx;
    cmsis_nn_pool_params pool_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims output_dims;

    const int8_t *input_data = avgpooling_5_input_tensor;

    input_dims.n = -AVGPOOLING_5_BATCH_SIZE;
    input_dims.w = AVGPOOLING_5_INPUT_W;
    input_dims.h = AVGPOOLING_5_INPUT_H;
    input_dims.c = AVGPOOLING_5_INPUT_C;
    filter_dims.w = AVGPOOLING_5_FILTER_W;
    filter_dims.h = AVGPOOLING_5_FILTER_H;
    output_dims.w = AVGPOOLING_5_OUTPUT_W;
    output_dims.h = AVGPOOLING_5_OUTPUT_H;
    output_dims.c = AVGPOOLING_5_OUTPUT_C;

    pool_params.padding.w = AVGPOOLING_5_PADDING_W;
    pool_params.padding.h = AVGPOOLING_5_PADDING_H;
    pool_params.stride.w = AVGPOOLING_5_STRIDE_W;
    pool_params.stride.h = AVGPOOLING_5_STRIDE_H;

    pool_params.activation.min = AVGPOOLING_5_ACTIVATION_MIN;
    pool_params.activation.max = AVGPOOLING_5_ACTIVATION_MAX;

    ctx.size = arm_avgpool_s8_get_buffer_size(AVGPOOLING_5_OUTPUT_W, AVGPOOLING_5_INPUT_C);
    ctx.buf = malloc(ctx.size);

    arm_cmsis_nn_status result =
        arm_avgpool_s8(&ctx, &pool_params, &input_dims, input_data, &filter_dims, &output_dims, output);

    if (ctx.buf)
    {
        memset(ctx.buf, 0, ctx.size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(expected, result);
}
