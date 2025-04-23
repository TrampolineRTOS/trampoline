/*
 * SPDX-FileCopyrightText: Copyright 2024 Arm Limited and/or its affiliates <open-source-office@arm.com>
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

#include "../TestData/batch_matmul_1_s8/test_data.h"
#include "../TestData/batch_matmul_2_s8/test_data.h"
#include "../TestData/batch_matmul_3_s8/test_data.h"
#include "../TestData/batch_matmul_4_s8/test_data.h"
#include "../TestData/batch_matmul_5_s8/test_data.h"
#include "../Utils/validate.h"
#include <arm_nnfunctions.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unity.h>

/*
 * We want to transpose LHS as usual if adj_x is 1. When adj_y is 1, we actually already have the rhs in the desired
 * shape, as our matmul kernel is expecting the rhs to be transposed. We have 2 versions of each input tensor a regular
 * and transposed version. So we just replace _input with _transposed in the tensor name and use that. We also switch
 * the ROWS and COLS macro in the shape.
 */

// Adj_x = 0, Adj_y=0
void batch_matmul_1_s8(void)
{
    cmsis_nn_context ctx;
    cmsis_nn_bmm_params bmm_params = {0, // adj_x
                                      0, // adj_y
                                      {BATCH_MATMUL_1_S8_LHS_OFFSET,
                                       BATCH_MATMUL_1_S8_RHS_OFFSET,
                                       BATCH_MATMUL_1_S8_OUTPUT_OFFSET,
                                       {BATCH_MATMUL_1_S8_ACTIVATION_MIN, BATCH_MATMUL_1_S8_ACTIVATION_MAX}}};
    cmsis_nn_per_tensor_quant_params quant_params = {BATCH_MATMUL_1_S8_OUTPUT_MULTIPLIER,
                                                     BATCH_MATMUL_1_S8_OUTPUT_SHIFT};
    cmsis_nn_dims lhs_shape_nt = {BATCH_MATMUL_1_S8_LHS_BATCH,
                                  BATCH_MATMUL_1_S8_LHS_HEIGHT,
                                  BATCH_MATMUL_1_S8_LHS_ROWS,
                                  BATCH_MATMUL_1_S8_LHS_COLS};
    // Adj_y = 0, but we actually want to transpose rhs.
    cmsis_nn_dims rhs_shape_t = {BATCH_MATMUL_1_S8_RHS_BATCH,
                                 BATCH_MATMUL_1_S8_RHS_HEIGHT,
                                 BATCH_MATMUL_1_S8_RHS_COLS,
                                 BATCH_MATMUL_1_S8_RHS_ROWS};
    cmsis_nn_dims output_shape = {BATCH_MATMUL_1_S8_OUTPUT_BATCH,
                                  BATCH_MATMUL_1_S8_OUTPUT_HEIGHT,
                                  BATCH_MATMUL_1_S8_OUTPUT_ROWS,
                                  BATCH_MATMUL_1_S8_OUTPUT_COLS};

    int8_t output[BATCH_MATMUL_1_S8_DST_SIZE] = {0};
    const int32_t output_size = BATCH_MATMUL_1_S8_DST_SIZE;
    const int8_t *lhs_input = batch_matmul_1_s8_lhs_input_tensor;
    const int8_t *rhs_input = batch_matmul_1_s8_rhs_transposed_tensor;

    int32_t buf_size = arm_fully_connected_s8_get_buffer_size(&output_shape);
    ctx.buf = malloc(buf_size);
    ctx.size = 0;

    arm_cmsis_nn_status result = arm_batch_matmul_s8(
        &ctx, &bmm_params, &quant_params, &lhs_shape_nt, lhs_input, &rhs_shape_t, rhs_input, &output_shape, output);

    if (ctx.buf)
    {
        // The caller is responsible to clear the scratch buffers for security reasons if applicable.
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(ARM_CMSIS_NN_SUCCESS, result);
    TEST_ASSERT_TRUE(validate(output, batch_matmul_1_s8_output, output_size));
}

// Adj_x = 0, Adj_y=1
void batch_matmul_2_s8(void)
{
    cmsis_nn_context ctx;
    cmsis_nn_bmm_params bmm_params = {0, // adj_x
                                      1, // adj_y
                                      {BATCH_MATMUL_2_S8_LHS_OFFSET,
                                       BATCH_MATMUL_2_S8_RHS_OFFSET,
                                       BATCH_MATMUL_2_S8_OUTPUT_OFFSET,
                                       {BATCH_MATMUL_2_S8_ACTIVATION_MIN, BATCH_MATMUL_2_S8_ACTIVATION_MAX}}};
    cmsis_nn_per_tensor_quant_params quant_params = {BATCH_MATMUL_2_S8_OUTPUT_MULTIPLIER,
                                                     BATCH_MATMUL_2_S8_OUTPUT_SHIFT};
    cmsis_nn_dims lhs_shape_nt = {BATCH_MATMUL_2_S8_LHS_BATCH,
                                  BATCH_MATMUL_2_S8_LHS_HEIGHT,
                                  BATCH_MATMUL_2_S8_LHS_ROWS,
                                  BATCH_MATMUL_2_S8_LHS_COLS};
    // Adj_y = 1, but we do not want to transpose rhs.
    cmsis_nn_dims rhs_shape_nt = {BATCH_MATMUL_2_S8_RHS_BATCH,
                                  BATCH_MATMUL_2_S8_RHS_HEIGHT,
                                  BATCH_MATMUL_2_S8_RHS_ROWS,
                                  BATCH_MATMUL_2_S8_RHS_COLS};
    cmsis_nn_dims output_shape = {BATCH_MATMUL_2_S8_OUTPUT_BATCH,
                                  BATCH_MATMUL_2_S8_OUTPUT_HEIGHT,
                                  BATCH_MATMUL_2_S8_OUTPUT_ROWS,
                                  BATCH_MATMUL_2_S8_OUTPUT_COLS};

    int8_t output[BATCH_MATMUL_2_S8_DST_SIZE] = {0};
    const int32_t output_size = BATCH_MATMUL_2_S8_DST_SIZE;
    const int8_t *lhs_input = batch_matmul_2_s8_lhs_input_tensor;
    const int8_t *rhs_input = batch_matmul_2_s8_rhs_input_tensor;

    int32_t buf_size = arm_fully_connected_s8_get_buffer_size(&output_shape);
    ctx.buf = malloc(buf_size);
    ctx.size = 0;

    arm_cmsis_nn_status result = arm_batch_matmul_s8(
        &ctx, &bmm_params, &quant_params, &lhs_shape_nt, lhs_input, &rhs_shape_nt, rhs_input, &output_shape, output);

    if (ctx.buf)
    {
        // The caller is responsible to clear the scratch buffers for security reasons if applicable.
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(ARM_CMSIS_NN_SUCCESS, result);
    TEST_ASSERT_TRUE(validate(output, batch_matmul_2_s8_output, output_size));
}

// Adj_x = 1, Adj_y=0
void batch_matmul_3_s8(void)
{
    cmsis_nn_context ctx;
    cmsis_nn_bmm_params bmm_params = {1, // adj_x
                                      0, // adj_y
                                      {BATCH_MATMUL_3_S8_LHS_OFFSET,
                                       BATCH_MATMUL_3_S8_RHS_OFFSET,
                                       BATCH_MATMUL_3_S8_OUTPUT_OFFSET,
                                       {BATCH_MATMUL_3_S8_ACTIVATION_MIN, BATCH_MATMUL_3_S8_ACTIVATION_MAX}}};
    cmsis_nn_per_tensor_quant_params quant_params = {BATCH_MATMUL_3_S8_OUTPUT_MULTIPLIER,
                                                     BATCH_MATMUL_3_S8_OUTPUT_SHIFT};
    // Adj_x = 1, so we transpose lhs
    cmsis_nn_dims lhs_shape_t = {BATCH_MATMUL_3_S8_LHS_BATCH,
                                 BATCH_MATMUL_3_S8_LHS_HEIGHT,
                                 BATCH_MATMUL_3_S8_LHS_COLS,
                                 BATCH_MATMUL_3_S8_LHS_ROWS};
    // Adj_y = 0, but we want to transpose rhs
    cmsis_nn_dims rhs_shape_t = {BATCH_MATMUL_3_S8_RHS_BATCH,
                                 BATCH_MATMUL_3_S8_RHS_HEIGHT,
                                 BATCH_MATMUL_3_S8_RHS_COLS,
                                 BATCH_MATMUL_3_S8_RHS_ROWS};
    cmsis_nn_dims output_shape = {BATCH_MATMUL_3_S8_OUTPUT_BATCH,
                                  BATCH_MATMUL_3_S8_OUTPUT_HEIGHT,
                                  BATCH_MATMUL_3_S8_OUTPUT_ROWS,
                                  BATCH_MATMUL_3_S8_OUTPUT_COLS};

    int8_t output[BATCH_MATMUL_3_S8_DST_SIZE] = {0};
    const int32_t output_size = BATCH_MATMUL_3_S8_DST_SIZE;
    const int8_t *lhs_input = batch_matmul_3_s8_lhs_transposed_tensor;
    const int8_t *rhs_input = batch_matmul_3_s8_rhs_transposed_tensor;

    int32_t buf_size = arm_fully_connected_s8_get_buffer_size(&output_shape);
    ctx.buf = malloc(buf_size);
    ctx.size = 0;

    arm_cmsis_nn_status result = arm_batch_matmul_s8(
        &ctx, &bmm_params, &quant_params, &lhs_shape_t, lhs_input, &rhs_shape_t, rhs_input, &output_shape, output);

    if (ctx.buf)
    {
        // The caller is responsible to clear the scratch buffers for security reasons if applicable.
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(ARM_CMSIS_NN_SUCCESS, result);
    TEST_ASSERT_TRUE(validate(output, batch_matmul_3_s8_output, output_size));
}

// Adj_x = 1, Adj_y=1
void batch_matmul_4_s8(void)
{
    cmsis_nn_context ctx;
    cmsis_nn_bmm_params bmm_params = {1, // adj_x
                                      1, // adj_y
                                      {BATCH_MATMUL_4_S8_LHS_OFFSET,
                                       BATCH_MATMUL_4_S8_RHS_OFFSET,
                                       BATCH_MATMUL_4_S8_OUTPUT_OFFSET,
                                       {BATCH_MATMUL_4_S8_ACTIVATION_MIN, BATCH_MATMUL_4_S8_ACTIVATION_MAX}}};
    cmsis_nn_per_tensor_quant_params quant_params = {BATCH_MATMUL_4_S8_OUTPUT_MULTIPLIER,
                                                     BATCH_MATMUL_4_S8_OUTPUT_SHIFT};
    // Adj_x = 1, so we transpose lhs
    cmsis_nn_dims lhs_shape_t = {BATCH_MATMUL_4_S8_LHS_BATCH,
                                 BATCH_MATMUL_4_S8_LHS_HEIGHT,
                                 BATCH_MATMUL_4_S8_LHS_COLS,
                                 BATCH_MATMUL_4_S8_LHS_ROWS};
    // Adj_y = 1, but we do not want to transpose rhs
    cmsis_nn_dims rhs_shape_nt = {BATCH_MATMUL_4_S8_RHS_BATCH,
                                  BATCH_MATMUL_4_S8_RHS_HEIGHT,
                                  BATCH_MATMUL_4_S8_RHS_ROWS,
                                  BATCH_MATMUL_4_S8_RHS_COLS};
    cmsis_nn_dims output_shape = {BATCH_MATMUL_4_S8_OUTPUT_BATCH,
                                  BATCH_MATMUL_4_S8_OUTPUT_HEIGHT,
                                  BATCH_MATMUL_4_S8_OUTPUT_ROWS,
                                  BATCH_MATMUL_4_S8_OUTPUT_COLS};

    int8_t output[BATCH_MATMUL_4_S8_DST_SIZE] = {0};
    const int32_t output_size = BATCH_MATMUL_4_S8_DST_SIZE;
    const int8_t *lhs_input = batch_matmul_4_s8_lhs_transposed_tensor;
    const int8_t *rhs_input = batch_matmul_4_s8_rhs_input_tensor;

    int32_t buf_size = arm_fully_connected_s8_get_buffer_size(&output_shape);
    ctx.buf = malloc(buf_size);
    ctx.size = 0;

    arm_cmsis_nn_status result = arm_batch_matmul_s8(
        &ctx, &bmm_params, &quant_params, &lhs_shape_t, lhs_input, &rhs_shape_nt, rhs_input, &output_shape, output);

    if (ctx.buf)
    {
        // The caller is responsible to clear the scratch buffers for security reasons if applicable.
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(ARM_CMSIS_NN_SUCCESS, result);
    TEST_ASSERT_TRUE(validate(output, batch_matmul_4_s8_output, output_size));
}

// Adj_x = 0, Adj_y=1
void batch_matmul_5_s8(void)
{
    cmsis_nn_context ctx;
    cmsis_nn_bmm_params bmm_params = {0, // adj_x
                                      1, // adj_y
                                      {BATCH_MATMUL_5_S8_LHS_OFFSET,
                                       BATCH_MATMUL_5_S8_RHS_OFFSET,
                                       BATCH_MATMUL_5_S8_OUTPUT_OFFSET,
                                       {BATCH_MATMUL_5_S8_ACTIVATION_MIN, BATCH_MATMUL_5_S8_ACTIVATION_MAX}}};
    cmsis_nn_per_tensor_quant_params quant_params = {BATCH_MATMUL_5_S8_OUTPUT_MULTIPLIER,
                                                     BATCH_MATMUL_5_S8_OUTPUT_SHIFT};
    cmsis_nn_dims lhs_shape_nt = {BATCH_MATMUL_5_S8_LHS_BATCH,
                                  BATCH_MATMUL_5_S8_LHS_HEIGHT,
                                  BATCH_MATMUL_5_S8_LHS_ROWS,
                                  BATCH_MATMUL_5_S8_LHS_COLS};
    // Adj_y = 1, but we do not want to transpose rhs.
    cmsis_nn_dims rhs_shape_nt = {BATCH_MATMUL_5_S8_RHS_BATCH,
                                  BATCH_MATMUL_5_S8_RHS_HEIGHT,
                                  BATCH_MATMUL_5_S8_RHS_ROWS,
                                  BATCH_MATMUL_5_S8_RHS_COLS};
    cmsis_nn_dims output_shape = {BATCH_MATMUL_5_S8_OUTPUT_BATCH,
                                  BATCH_MATMUL_5_S8_OUTPUT_HEIGHT,
                                  BATCH_MATMUL_5_S8_OUTPUT_ROWS,
                                  BATCH_MATMUL_5_S8_OUTPUT_COLS};

    int8_t output[BATCH_MATMUL_5_S8_DST_SIZE] = {0};
    const int32_t output_size = BATCH_MATMUL_5_S8_DST_SIZE;
    const int8_t *lhs_input = batch_matmul_5_s8_lhs_input_tensor;
    const int8_t *rhs_input = batch_matmul_5_s8_rhs_input_tensor;

    int32_t buf_size = arm_fully_connected_s8_get_buffer_size(&output_shape);
    ctx.buf = malloc(buf_size);
    ctx.size = 0;

    arm_cmsis_nn_status result = arm_batch_matmul_s8(
        &ctx, &bmm_params, &quant_params, &lhs_shape_nt, lhs_input, &rhs_shape_nt, rhs_input, &output_shape, output);

    if (ctx.buf)
    {
        // The caller is responsible to clear the scratch buffers for security reasons if applicable.
        memset(ctx.buf, 0, buf_size);
        free(ctx.buf);
    }
    TEST_ASSERT_EQUAL(ARM_CMSIS_NN_SUCCESS, result);
    TEST_ASSERT_TRUE(validate(output, batch_matmul_5_s8_output, output_size));
}