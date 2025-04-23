/*
 * SPDX-FileCopyrightText: Copyright 2022-2024 Arm Limited and/or its affiliates <open-source-office@arm.com>
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

#include "unity.h"
#include <arm_nnfunctions.h>

#include "../TestData/maxpool_int16/test_data.h"
#include "../TestData/maxpool_int16_1/test_data.h"
#include "../TestData/maxpool_int16_2/test_data.h"
#include "../Utils/validate.h"

#define REPEAT_NUM (2)

void maxpool_int16_arm_max_pool_s16(void)
{
    const arm_cmsis_nn_status expected = ARM_CMSIS_NN_SUCCESS;
    int16_t output[MAXPOOL_INT16_OUTPUT_W * MAXPOOL_INT16_OUTPUT_H * MAXPOOL_INT16_INPUT_C * MAXPOOL_INT16_BATCH_SIZE] =
        {0};

    cmsis_nn_context ctx;
    cmsis_nn_pool_params pool_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims output_dims;

    const int16_t *input_data = maxpool_int16_input_tensor;

    input_dims.n = MAXPOOL_INT16_BATCH_SIZE;
    input_dims.w = MAXPOOL_INT16_INPUT_W;
    input_dims.h = MAXPOOL_INT16_INPUT_H;
    input_dims.c = MAXPOOL_INT16_INPUT_C;
    filter_dims.w = MAXPOOL_INT16_FILTER_W;
    filter_dims.h = MAXPOOL_INT16_FILTER_H;
    output_dims.w = MAXPOOL_INT16_OUTPUT_W;
    output_dims.h = MAXPOOL_INT16_OUTPUT_H;
    output_dims.c = MAXPOOL_INT16_INPUT_C;

    pool_params.padding.w = MAXPOOL_INT16_PADDING_W;
    pool_params.padding.h = MAXPOOL_INT16_PADDING_H;
    pool_params.stride.w = MAXPOOL_INT16_STRIDE_W;
    pool_params.stride.h = MAXPOOL_INT16_STRIDE_H;

    pool_params.activation.min = MAXPOOL_INT16_ACTIVATION_MIN;
    pool_params.activation.max = MAXPOOL_INT16_ACTIVATION_MAX;

    for (int i = 0; i < REPEAT_NUM; i++)
    {
        arm_cmsis_nn_status result =
            arm_max_pool_s16(&ctx, &pool_params, &input_dims, input_data, &filter_dims, &output_dims, output);

        TEST_ASSERT_EQUAL(expected, result);
        TEST_ASSERT_TRUE(validate_s16(output,
                                      maxpool_int16_output,
                                      MAXPOOL_INT16_OUTPUT_W * MAXPOOL_INT16_OUTPUT_H * MAXPOOL_INT16_INPUT_C *
                                          MAXPOOL_INT16_BATCH_SIZE));
    }
}

void maxpool_int16_1_arm_max_pool_s16(void)
{
    const arm_cmsis_nn_status expected = ARM_CMSIS_NN_SUCCESS;
    int16_t output[MAXPOOL_INT16_1_OUTPUT_W * MAXPOOL_INT16_1_OUTPUT_H * MAXPOOL_INT16_1_INPUT_C *
                   MAXPOOL_INT16_1_BATCH_SIZE] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_pool_params pool_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims output_dims;

    const int16_t *input_data = maxpool_int16_1_input_tensor;

    input_dims.n = MAXPOOL_INT16_1_BATCH_SIZE;
    input_dims.w = MAXPOOL_INT16_1_INPUT_W;
    input_dims.h = MAXPOOL_INT16_1_INPUT_H;
    input_dims.c = MAXPOOL_INT16_1_INPUT_C;
    filter_dims.w = MAXPOOL_INT16_1_FILTER_W;
    filter_dims.h = MAXPOOL_INT16_1_FILTER_H;
    output_dims.w = MAXPOOL_INT16_1_OUTPUT_W;
    output_dims.h = MAXPOOL_INT16_1_OUTPUT_H;
    output_dims.c = MAXPOOL_INT16_1_INPUT_C;

    pool_params.padding.w = MAXPOOL_INT16_1_PADDING_W;
    pool_params.padding.h = MAXPOOL_INT16_1_PADDING_H;
    pool_params.stride.w = MAXPOOL_INT16_1_STRIDE_W;
    pool_params.stride.h = MAXPOOL_INT16_1_STRIDE_H;

    pool_params.activation.min = MAXPOOL_INT16_1_ACTIVATION_MIN;
    pool_params.activation.max = MAXPOOL_INT16_1_ACTIVATION_MAX;

    for (int i = 0; i < REPEAT_NUM; i++)
    {
        arm_cmsis_nn_status result =
            arm_max_pool_s16(&ctx, &pool_params, &input_dims, input_data, &filter_dims, &output_dims, output);

        TEST_ASSERT_EQUAL(expected, result);
        TEST_ASSERT_TRUE(validate_s16(output,
                                      maxpool_int16_1_output,
                                      MAXPOOL_INT16_1_OUTPUT_W * MAXPOOL_INT16_1_OUTPUT_H * MAXPOOL_INT16_1_INPUT_C *
                                          MAXPOOL_INT16_1_BATCH_SIZE));
    }
}

void maxpool_int16_2_arm_max_pool_s16(void)
{
    const arm_cmsis_nn_status expected = ARM_CMSIS_NN_SUCCESS;
    int16_t output[MAXPOOL_INT16_2_OUTPUT_W * MAXPOOL_INT16_2_OUTPUT_H * MAXPOOL_INT16_2_INPUT_C *
                   MAXPOOL_INT16_2_BATCH_SIZE] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_pool_params pool_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims output_dims;

    const int16_t *input_data = maxpool_int16_2_input_tensor;

    input_dims.n = MAXPOOL_INT16_2_BATCH_SIZE;
    input_dims.w = MAXPOOL_INT16_2_INPUT_W;
    input_dims.h = MAXPOOL_INT16_2_INPUT_H;
    input_dims.c = MAXPOOL_INT16_2_INPUT_C;
    filter_dims.w = MAXPOOL_INT16_2_FILTER_W;
    filter_dims.h = MAXPOOL_INT16_2_FILTER_H;
    output_dims.w = MAXPOOL_INT16_2_OUTPUT_W;
    output_dims.h = MAXPOOL_INT16_2_OUTPUT_H;
    output_dims.c = MAXPOOL_INT16_2_INPUT_C;

    pool_params.padding.w = MAXPOOL_INT16_2_PADDING_W;
    pool_params.padding.h = MAXPOOL_INT16_2_PADDING_H;
    pool_params.stride.w = MAXPOOL_INT16_2_STRIDE_W;
    pool_params.stride.h = MAXPOOL_INT16_2_STRIDE_H;

    pool_params.activation.min = MAXPOOL_INT16_2_ACTIVATION_MIN;
    pool_params.activation.max = MAXPOOL_INT16_2_ACTIVATION_MAX;

    for (int i = 0; i < REPEAT_NUM; i++)
    {
        arm_cmsis_nn_status result =
            arm_max_pool_s16(&ctx, &pool_params, &input_dims, input_data, &filter_dims, &output_dims, output);

        TEST_ASSERT_EQUAL(expected, result);
        TEST_ASSERT_TRUE(validate_s16(output,
                                      maxpool_int16_2_output,
                                      MAXPOOL_INT16_2_OUTPUT_W * MAXPOOL_INT16_2_OUTPUT_H * MAXPOOL_INT16_2_INPUT_C *
                                          MAXPOOL_INT16_2_BATCH_SIZE));
    }
}

void maxpool_int16_param_fail_arm_max_pool_s16(void)
{
    const arm_cmsis_nn_status expected = ARM_CMSIS_NN_ARG_ERROR;
    int16_t output[MAXPOOL_INT16_2_OUTPUT_W * MAXPOOL_INT16_2_OUTPUT_H * MAXPOOL_INT16_2_INPUT_C *
                   MAXPOOL_INT16_2_BATCH_SIZE] = {0};

    cmsis_nn_context ctx = {};
    cmsis_nn_pool_params pool_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims output_dims;

    const int16_t *input_data = maxpool_int16_2_input_tensor;

    input_dims.n = -MAXPOOL_INT16_2_BATCH_SIZE;
    input_dims.w = MAXPOOL_INT16_2_INPUT_W;
    input_dims.h = MAXPOOL_INT16_2_INPUT_H;
    input_dims.c = MAXPOOL_INT16_2_INPUT_C;
    filter_dims.w = MAXPOOL_INT16_2_FILTER_W;
    filter_dims.h = MAXPOOL_INT16_2_FILTER_H;
    output_dims.w = MAXPOOL_INT16_2_OUTPUT_W;
    output_dims.h = MAXPOOL_INT16_2_OUTPUT_H;
    output_dims.c = MAXPOOL_INT16_2_INPUT_C;

    pool_params.padding.w = MAXPOOL_INT16_2_PADDING_W;
    pool_params.padding.h = MAXPOOL_INT16_2_PADDING_H;
    pool_params.stride.w = MAXPOOL_INT16_2_STRIDE_W;
    pool_params.stride.h = MAXPOOL_INT16_2_STRIDE_H;

    pool_params.activation.min = MAXPOOL_INT16_2_ACTIVATION_MIN;
    pool_params.activation.max = MAXPOOL_INT16_2_ACTIVATION_MAX;

    arm_cmsis_nn_status result =
        arm_max_pool_s16(&ctx, &pool_params, &input_dims, input_data, &filter_dims, &output_dims, output);

    TEST_ASSERT_EQUAL(expected, result);
}
