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

#include "../TestData/avgpooling_int16/test_data.h"
#include "../TestData/avgpooling_int16_1/test_data.h"
#include "../TestData/avgpooling_int16_2/test_data.h"
#include "../TestData/avgpooling_int16_3/test_data.h"
#include "../Utils/validate.h"

void avgpooling_int16_arm_avgpool_s16(void)
{
    const arm_cmsis_nn_status expected = ARM_CMSIS_NN_SUCCESS;
    int16_t output[AVGPOOLING_INT16_OUTPUT_C * AVGPOOLING_INT16_OUTPUT_W * AVGPOOLING_INT16_OUTPUT_H *
                   AVGPOOLING_INT16_BATCH_SIZE] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_pool_params pool_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims output_dims;

    const int16_t *input_data = avgpooling_int16_input_tensor;

    input_dims.n = AVGPOOLING_INT16_BATCH_SIZE;
    input_dims.w = AVGPOOLING_INT16_INPUT_W;
    input_dims.h = AVGPOOLING_INT16_INPUT_H;
    input_dims.c = AVGPOOLING_INT16_INPUT_C;
    filter_dims.w = AVGPOOLING_INT16_FILTER_W;
    filter_dims.h = AVGPOOLING_INT16_FILTER_H;
    output_dims.w = AVGPOOLING_INT16_OUTPUT_W;
    output_dims.h = AVGPOOLING_INT16_OUTPUT_H;
    output_dims.c = AVGPOOLING_INT16_INPUT_C;

    pool_params.padding.w = AVGPOOLING_INT16_PADDING_W;
    pool_params.padding.h = AVGPOOLING_INT16_PADDING_H;
    pool_params.stride.w = AVGPOOLING_INT16_STRIDE_W;
    pool_params.stride.h = AVGPOOLING_INT16_STRIDE_H;

    pool_params.activation.min = AVGPOOLING_INT16_ACTIVATION_MIN;
    pool_params.activation.max = AVGPOOLING_INT16_ACTIVATION_MAX;

    ctx.size = arm_avgpool_s16_get_buffer_size(AVGPOOLING_INT16_OUTPUT_W, AVGPOOLING_INT16_INPUT_C);
    ctx.buf = malloc(ctx.size);

    arm_cmsis_nn_status result =
        arm_avgpool_s16(&ctx, &pool_params, &input_dims, input_data, &filter_dims, &output_dims, output);

    if (ctx.buf)
    {
        // The caller is responsible to clear the scratch buffers for security reasons if applicable.
        memset(ctx.buf, 0, ctx.size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(expected, result);
    TEST_ASSERT_TRUE(validate_s16(output,
                                  avgpooling_int16_output,
                                  AVGPOOLING_INT16_OUTPUT_C * AVGPOOLING_INT16_OUTPUT_W * AVGPOOLING_INT16_OUTPUT_H *
                                      AVGPOOLING_INT16_BATCH_SIZE));
}

void avgpooling_int16_1_arm_avgpool_s16(void)
{
    const arm_cmsis_nn_status expected = ARM_CMSIS_NN_SUCCESS;
    int16_t output[AVGPOOLING_INT16_1_OUTPUT_C * AVGPOOLING_INT16_1_OUTPUT_W * AVGPOOLING_INT16_1_OUTPUT_H *
                   AVGPOOLING_INT16_1_BATCH_SIZE] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_pool_params pool_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims output_dims;

    const int16_t *input_data = avgpooling_int16_1_input_tensor;

    input_dims.n = AVGPOOLING_INT16_1_BATCH_SIZE;
    input_dims.w = AVGPOOLING_INT16_1_INPUT_W;
    input_dims.h = AVGPOOLING_INT16_1_INPUT_H;
    input_dims.c = AVGPOOLING_INT16_1_INPUT_C;
    filter_dims.w = AVGPOOLING_INT16_1_FILTER_W;
    filter_dims.h = AVGPOOLING_INT16_1_FILTER_H;
    output_dims.w = AVGPOOLING_INT16_1_OUTPUT_W;
    output_dims.h = AVGPOOLING_INT16_1_OUTPUT_H;
    output_dims.c = AVGPOOLING_INT16_1_INPUT_C;

    pool_params.padding.w = AVGPOOLING_INT16_1_PADDING_W;
    pool_params.padding.h = AVGPOOLING_INT16_1_PADDING_H;
    pool_params.stride.w = AVGPOOLING_INT16_1_STRIDE_W;
    pool_params.stride.h = AVGPOOLING_INT16_1_STRIDE_H;

    pool_params.activation.min = AVGPOOLING_INT16_1_ACTIVATION_MIN;
    pool_params.activation.max = AVGPOOLING_INT16_1_ACTIVATION_MAX;

    ctx.size = arm_avgpool_s16_get_buffer_size(AVGPOOLING_INT16_1_OUTPUT_W, AVGPOOLING_INT16_1_INPUT_C);
    ctx.buf = malloc(ctx.size);

    arm_cmsis_nn_status result =
        arm_avgpool_s16(&ctx, &pool_params, &input_dims, input_data, &filter_dims, &output_dims, output);

    if (ctx.buf)
    {
        memset(ctx.buf, 0, ctx.size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(expected, result);
    TEST_ASSERT_TRUE(validate_s16(output,
                                  avgpooling_int16_1_output,
                                  AVGPOOLING_INT16_1_OUTPUT_C * AVGPOOLING_INT16_1_OUTPUT_W *
                                      AVGPOOLING_INT16_1_OUTPUT_H * AVGPOOLING_INT16_1_BATCH_SIZE));
}

void avgpooling_int16_2_arm_avgpool_s16(void)
{
    const arm_cmsis_nn_status expected = ARM_CMSIS_NN_SUCCESS;
    int16_t output[AVGPOOLING_INT16_2_OUTPUT_C * AVGPOOLING_INT16_2_OUTPUT_W * AVGPOOLING_INT16_2_OUTPUT_H *
                   AVGPOOLING_INT16_2_BATCH_SIZE] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_pool_params pool_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims output_dims;

    const int16_t *input_data = avgpooling_int16_2_input_tensor;

    input_dims.n = AVGPOOLING_INT16_2_BATCH_SIZE;
    input_dims.w = AVGPOOLING_INT16_2_INPUT_W;
    input_dims.h = AVGPOOLING_INT16_2_INPUT_H;
    input_dims.c = AVGPOOLING_INT16_2_INPUT_C;
    filter_dims.w = AVGPOOLING_INT16_2_FILTER_W;
    filter_dims.h = AVGPOOLING_INT16_2_FILTER_H;
    output_dims.w = AVGPOOLING_INT16_2_OUTPUT_W;
    output_dims.h = AVGPOOLING_INT16_2_OUTPUT_H;
    output_dims.c = AVGPOOLING_INT16_2_INPUT_C;

    pool_params.padding.w = AVGPOOLING_INT16_2_PADDING_W;
    pool_params.padding.h = AVGPOOLING_INT16_2_PADDING_H;
    pool_params.stride.w = AVGPOOLING_INT16_2_STRIDE_W;
    pool_params.stride.h = AVGPOOLING_INT16_2_STRIDE_H;

    pool_params.activation.min = AVGPOOLING_INT16_2_ACTIVATION_MIN;
    pool_params.activation.max = AVGPOOLING_INT16_2_ACTIVATION_MAX;

    ctx.size = arm_avgpool_s16_get_buffer_size(AVGPOOLING_INT16_2_OUTPUT_W, AVGPOOLING_INT16_2_INPUT_C);
    ctx.buf = malloc(ctx.size);

    arm_cmsis_nn_status result =
        arm_avgpool_s16(&ctx, &pool_params, &input_dims, input_data, &filter_dims, &output_dims, output);

    if (ctx.buf)
    {
        memset(ctx.buf, 0, ctx.size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(expected, result);
    TEST_ASSERT_TRUE(validate_s16(output,
                                  avgpooling_int16_2_output,
                                  AVGPOOLING_INT16_2_OUTPUT_C * AVGPOOLING_INT16_2_OUTPUT_W *
                                      AVGPOOLING_INT16_2_OUTPUT_H * AVGPOOLING_INT16_2_BATCH_SIZE));
}

void avgpooling_int16_3_arm_avgpool_s16(void)
{
    const arm_cmsis_nn_status expected = ARM_CMSIS_NN_SUCCESS;
    int16_t output[AVGPOOLING_INT16_3_OUTPUT_C * AVGPOOLING_INT16_3_OUTPUT_W * AVGPOOLING_INT16_3_OUTPUT_H *
                   AVGPOOLING_INT16_3_BATCH_SIZE] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_pool_params pool_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims output_dims;

    const int16_t *input_data = avgpooling_int16_3_input_tensor;

    input_dims.n = AVGPOOLING_INT16_3_BATCH_SIZE;
    input_dims.w = AVGPOOLING_INT16_3_INPUT_W;
    input_dims.h = AVGPOOLING_INT16_3_INPUT_H;
    input_dims.c = AVGPOOLING_INT16_3_INPUT_C;
    filter_dims.w = AVGPOOLING_INT16_3_FILTER_W;
    filter_dims.h = AVGPOOLING_INT16_3_FILTER_H;
    output_dims.w = AVGPOOLING_INT16_3_OUTPUT_W;
    output_dims.h = AVGPOOLING_INT16_3_OUTPUT_H;
    output_dims.c = AVGPOOLING_INT16_3_INPUT_C;

    pool_params.padding.w = AVGPOOLING_INT16_3_PADDING_W;
    pool_params.padding.h = AVGPOOLING_INT16_3_PADDING_H;
    pool_params.stride.w = AVGPOOLING_INT16_3_STRIDE_W;
    pool_params.stride.h = AVGPOOLING_INT16_3_STRIDE_H;

    pool_params.activation.min = AVGPOOLING_INT16_3_ACTIVATION_MIN;
    pool_params.activation.max = AVGPOOLING_INT16_3_ACTIVATION_MAX;

    ctx.size = arm_avgpool_s16_get_buffer_size(AVGPOOLING_INT16_3_OUTPUT_W, AVGPOOLING_INT16_3_INPUT_C);
    ctx.buf = malloc(ctx.size);

    arm_cmsis_nn_status result =
        arm_avgpool_s16(&ctx, &pool_params, &input_dims, input_data, &filter_dims, &output_dims, output);

    if (ctx.buf)
    {
        memset(ctx.buf, 0, ctx.size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(expected, result);
    TEST_ASSERT_TRUE(validate_s16(output,
                                  avgpooling_int16_3_output,
                                  AVGPOOLING_INT16_3_OUTPUT_C * AVGPOOLING_INT16_3_OUTPUT_W *
                                      AVGPOOLING_INT16_3_OUTPUT_H * AVGPOOLING_INT16_3_BATCH_SIZE));
}

void buffer_size_mve_arm_avgpool_s16(void)
{
#if defined(ARM_MATH_MVEI)
    const int32_t buf_size = arm_avgpool_s16_get_buffer_size(AVGPOOLING_INT16_3_OUTPUT_W, AVGPOOLING_INT16_3_INPUT_C);
    const int32_t mve_buf_size =
        arm_avgpool_s16_get_buffer_size_mve(AVGPOOLING_INT16_3_OUTPUT_W, AVGPOOLING_INT16_3_INPUT_C);

    TEST_ASSERT_EQUAL(buf_size, mve_buf_size);
#endif
}

void buffer_size_dsp_arm_avgpool_s16(void)
{
#if defined(ARM_MATH_DSP) && !defined(ARM_MATH_MVEI)
    const int32_t buf_size = arm_avgpool_s16_get_buffer_size(AVGPOOLING_INT16_3_OUTPUT_W, AVGPOOLING_INT16_3_INPUT_C);
    const int32_t dsp_buf_size =
        arm_avgpool_s16_get_buffer_size_dsp(AVGPOOLING_INT16_3_OUTPUT_W, AVGPOOLING_INT16_3_INPUT_C);

    TEST_ASSERT_EQUAL(buf_size, dsp_buf_size);
#endif
}

void avgpooling_int16_param_fail_arm_avgpool_s16(void)
{
    const arm_cmsis_nn_status expected = ARM_CMSIS_NN_ARG_ERROR;
    int16_t output[AVGPOOLING_INT16_3_OUTPUT_C * AVGPOOLING_INT16_3_OUTPUT_W * AVGPOOLING_INT16_3_OUTPUT_H *
                   AVGPOOLING_INT16_3_BATCH_SIZE] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_pool_params pool_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims output_dims;

    const int16_t *input_data = avgpooling_int16_3_input_tensor;

    input_dims.n = 0;
    input_dims.w = AVGPOOLING_INT16_3_INPUT_W;
    input_dims.h = AVGPOOLING_INT16_3_INPUT_H;
    input_dims.c = AVGPOOLING_INT16_3_INPUT_C;
    filter_dims.w = AVGPOOLING_INT16_3_FILTER_W;
    filter_dims.h = AVGPOOLING_INT16_3_FILTER_H;
    output_dims.w = AVGPOOLING_INT16_3_OUTPUT_W;
    output_dims.h = AVGPOOLING_INT16_3_OUTPUT_H;
    output_dims.c = AVGPOOLING_INT16_3_INPUT_C;

    pool_params.padding.w = AVGPOOLING_INT16_3_PADDING_W;
    pool_params.padding.h = AVGPOOLING_INT16_3_PADDING_H;
    pool_params.stride.w = AVGPOOLING_INT16_3_STRIDE_W;
    pool_params.stride.h = AVGPOOLING_INT16_3_STRIDE_H;

    pool_params.activation.min = AVGPOOLING_INT16_3_ACTIVATION_MIN;
    pool_params.activation.max = AVGPOOLING_INT16_3_ACTIVATION_MAX;

    ctx.size = arm_avgpool_s16_get_buffer_size(AVGPOOLING_INT16_3_OUTPUT_W, AVGPOOLING_INT16_3_INPUT_C);
    ctx.buf = malloc(ctx.size);

    arm_cmsis_nn_status result =
        arm_avgpool_s16(&ctx, &pool_params, &input_dims, input_data, &filter_dims, &output_dims, output);

    if (ctx.buf)
    {
        memset(ctx.buf, 0, ctx.size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(expected, result);
}
