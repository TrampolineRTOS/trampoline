/*
 * SPDX-FileCopyrightText: Copyright 2023 Arm Limited and/or its affiliates <open-source-office@arm.com>
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

#include "../TestData/fully_connected_int4/test_data.h"
#include "../TestData/fully_connected_int4_2/test_data.h"
#include "../TestData/fully_connected_int4_3/test_data.h"
#include "../TestData/fully_connected_int4_4/test_data.h"
#include "../TestData/fully_connected_int4_5/test_data.h"
#include "../TestData/fully_connected_int4_6/test_data.h"

#include "../Utils/validate.h"

void fully_connected_int4_arm_fully_connected_s4(void)
{
    const arm_cmsis_nn_status expected = ARM_CMSIS_NN_SUCCESS;
    int8_t output[FULLY_CONNECTED_INT4_DST_SIZE] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_fc_params fc_params;
    cmsis_nn_per_tensor_quant_params quant_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims bias_dims = {};
    cmsis_nn_dims output_dims;

    const int32_t *bias_data = fully_connected_int4_biases;
    const int8_t *kernel_data = fully_connected_int4_weights;
    const int8_t *input_data = fully_connected_int4_input;
    const int8_t *output_ref = fully_connected_int4_output_ref;
    const int32_t output_ref_size = FULLY_CONNECTED_INT4_DST_SIZE;

    input_dims.n = FULLY_CONNECTED_INT4_INPUT_BATCHES;
    input_dims.w = FULLY_CONNECTED_INT4_INPUT_W;
    input_dims.h = FULLY_CONNECTED_INT4_INPUT_H;
    input_dims.c = FULLY_CONNECTED_INT4_IN_CH;
    filter_dims.n = FULLY_CONNECTED_INT4_ACCUMULATION_DEPTH;
    filter_dims.c = FULLY_CONNECTED_INT4_OUT_CH;
    output_dims.n = FULLY_CONNECTED_INT4_INPUT_BATCHES;
    output_dims.c = FULLY_CONNECTED_INT4_OUT_CH;

    fc_params.input_offset = FULLY_CONNECTED_INT4_INPUT_OFFSET;
    fc_params.filter_offset = 0;
    fc_params.output_offset = FULLY_CONNECTED_INT4_OUTPUT_OFFSET;
    fc_params.activation.min = FULLY_CONNECTED_INT4_OUT_ACTIVATION_MIN;
    fc_params.activation.max = FULLY_CONNECTED_INT4_OUT_ACTIVATION_MAX;

    quant_params.multiplier = FULLY_CONNECTED_INT4_OUTPUT_MULTIPLIER;
    quant_params.shift = FULLY_CONNECTED_INT4_OUTPUT_SHIFT;

    int32_t buf_size = 0;
    ctx.buf = malloc(buf_size);
    ctx.size = buf_size;

    arm_cmsis_nn_status result = arm_fully_connected_s4(&ctx,
                                                        &fc_params,
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
}

void fully_connected_int4_arm_fully_connected_s4_2(void)
{
    const arm_cmsis_nn_status expected = ARM_CMSIS_NN_SUCCESS;
    int8_t output[FULLY_CONNECTED_INT4_2_DST_SIZE] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_fc_params fc_params;
    cmsis_nn_per_tensor_quant_params quant_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims bias_dims = {};
    cmsis_nn_dims output_dims;

    const int32_t *bias_data = fully_connected_int4_2_biases;
    const int8_t *kernel_data = fully_connected_int4_2_weights;
    const int8_t *input_data = fully_connected_int4_2_input;
    const int8_t *output_ref = fully_connected_int4_2_output_ref;
    const int32_t output_ref_size = FULLY_CONNECTED_INT4_2_DST_SIZE;

    input_dims.n = FULLY_CONNECTED_INT4_2_INPUT_BATCHES;
    input_dims.w = FULLY_CONNECTED_INT4_2_INPUT_W;
    input_dims.h = FULLY_CONNECTED_INT4_2_INPUT_H;
    input_dims.c = FULLY_CONNECTED_INT4_2_IN_CH;
    filter_dims.n = FULLY_CONNECTED_INT4_2_ACCUMULATION_DEPTH;
    filter_dims.c = FULLY_CONNECTED_INT4_2_OUT_CH;
    output_dims.n = FULLY_CONNECTED_INT4_2_INPUT_BATCHES;
    output_dims.c = FULLY_CONNECTED_INT4_2_OUT_CH;

    fc_params.input_offset = FULLY_CONNECTED_INT4_2_INPUT_OFFSET;
    fc_params.filter_offset = 0;
    fc_params.output_offset = FULLY_CONNECTED_INT4_2_OUTPUT_OFFSET;
    fc_params.activation.min = FULLY_CONNECTED_INT4_2_OUT_ACTIVATION_MIN;
    fc_params.activation.max = FULLY_CONNECTED_INT4_2_OUT_ACTIVATION_MAX;

    quant_params.multiplier = FULLY_CONNECTED_INT4_2_OUTPUT_MULTIPLIER;
    quant_params.shift = FULLY_CONNECTED_INT4_2_OUTPUT_SHIFT;

    int32_t buf_size = 0;
    ctx.buf = malloc(buf_size);
    ctx.size = buf_size;

    arm_cmsis_nn_status result = arm_fully_connected_s4(&ctx,
                                                        &fc_params,
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
}

void fully_connected_int4_arm_fully_connected_s4_3(void)
{
    const arm_cmsis_nn_status expected = ARM_CMSIS_NN_SUCCESS;
    int8_t output[FULLY_CONNECTED_INT4_3_DST_SIZE] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_fc_params fc_params;
    cmsis_nn_per_tensor_quant_params quant_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims bias_dims = {};
    cmsis_nn_dims output_dims;

    const int32_t *bias_data = fully_connected_int4_3_biases;
    const int8_t *kernel_data = fully_connected_int4_3_weights;
    const int8_t *input_data = fully_connected_int4_3_input;
    const int8_t *output_ref = fully_connected_int4_3_output_ref;
    const int32_t output_ref_size = FULLY_CONNECTED_INT4_3_DST_SIZE;

    input_dims.n = FULLY_CONNECTED_INT4_3_INPUT_BATCHES;
    input_dims.w = FULLY_CONNECTED_INT4_3_INPUT_W;
    input_dims.h = FULLY_CONNECTED_INT4_3_INPUT_H;
    input_dims.c = FULLY_CONNECTED_INT4_3_IN_CH;
    filter_dims.n = FULLY_CONNECTED_INT4_3_ACCUMULATION_DEPTH;
    filter_dims.c = FULLY_CONNECTED_INT4_3_OUT_CH;
    output_dims.n = FULLY_CONNECTED_INT4_3_INPUT_BATCHES;
    output_dims.c = FULLY_CONNECTED_INT4_3_OUT_CH;

    fc_params.input_offset = FULLY_CONNECTED_INT4_3_INPUT_OFFSET;
    fc_params.filter_offset = 0;
    fc_params.output_offset = FULLY_CONNECTED_INT4_3_OUTPUT_OFFSET;
    fc_params.activation.min = FULLY_CONNECTED_INT4_3_OUT_ACTIVATION_MIN;
    fc_params.activation.max = FULLY_CONNECTED_INT4_3_OUT_ACTIVATION_MAX;

    quant_params.multiplier = FULLY_CONNECTED_INT4_3_OUTPUT_MULTIPLIER;
    quant_params.shift = FULLY_CONNECTED_INT4_3_OUTPUT_SHIFT;

    int32_t buf_size = 0;
    ctx.buf = malloc(buf_size);
    ctx.size = buf_size;

    arm_cmsis_nn_status result = arm_fully_connected_s4(&ctx,
                                                        &fc_params,
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
}

void fully_connected_int4_arm_fully_connected_s4_4(void)
{
    const arm_cmsis_nn_status expected = ARM_CMSIS_NN_SUCCESS;
    int8_t output[FULLY_CONNECTED_INT4_4_DST_SIZE] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_fc_params fc_params;
    cmsis_nn_per_tensor_quant_params quant_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims bias_dims = {};
    cmsis_nn_dims output_dims;

    const int32_t *bias_data = fully_connected_int4_4_biases;
    const int8_t *kernel_data = fully_connected_int4_4_weights;
    const int8_t *input_data = fully_connected_int4_4_input;
    const int8_t *output_ref = fully_connected_int4_4_output_ref;
    const int32_t output_ref_size = FULLY_CONNECTED_INT4_4_DST_SIZE;

    input_dims.n = FULLY_CONNECTED_INT4_4_INPUT_BATCHES;
    input_dims.w = FULLY_CONNECTED_INT4_4_INPUT_W;
    input_dims.h = FULLY_CONNECTED_INT4_4_INPUT_H;
    input_dims.c = FULLY_CONNECTED_INT4_4_IN_CH;
    filter_dims.n = FULLY_CONNECTED_INT4_4_ACCUMULATION_DEPTH;
    filter_dims.c = FULLY_CONNECTED_INT4_4_OUT_CH;
    output_dims.n = FULLY_CONNECTED_INT4_4_INPUT_BATCHES;
    output_dims.c = FULLY_CONNECTED_INT4_4_OUT_CH;

    fc_params.input_offset = FULLY_CONNECTED_INT4_4_INPUT_OFFSET;
    fc_params.filter_offset = 0;
    fc_params.output_offset = FULLY_CONNECTED_INT4_4_OUTPUT_OFFSET;
    fc_params.activation.min = FULLY_CONNECTED_INT4_4_OUT_ACTIVATION_MIN;
    fc_params.activation.max = FULLY_CONNECTED_INT4_4_OUT_ACTIVATION_MAX;

    quant_params.multiplier = FULLY_CONNECTED_INT4_4_OUTPUT_MULTIPLIER;
    quant_params.shift = FULLY_CONNECTED_INT4_4_OUTPUT_SHIFT;

    int32_t buf_size = 0;
    ctx.buf = malloc(buf_size);
    ctx.size = buf_size;

    arm_cmsis_nn_status result = arm_fully_connected_s4(&ctx,
                                                        &fc_params,
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
}

void fully_connected_int4_arm_fully_connected_s4_5(void)
{
    const arm_cmsis_nn_status expected = ARM_CMSIS_NN_SUCCESS;
    int8_t output[FULLY_CONNECTED_INT4_5_DST_SIZE] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_fc_params fc_params;
    cmsis_nn_per_tensor_quant_params quant_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims bias_dims = {};
    cmsis_nn_dims output_dims;

    const int32_t *bias_data = fully_connected_int4_5_biases;
    const int8_t *kernel_data = fully_connected_int4_5_weights;
    const int8_t *input_data = fully_connected_int4_5_input;
    const int8_t *output_ref = fully_connected_int4_5_output_ref;
    const int32_t output_ref_size = FULLY_CONNECTED_INT4_5_DST_SIZE;

    input_dims.n = FULLY_CONNECTED_INT4_5_INPUT_BATCHES;
    input_dims.w = FULLY_CONNECTED_INT4_5_INPUT_W;
    input_dims.h = FULLY_CONNECTED_INT4_5_INPUT_H;
    input_dims.c = FULLY_CONNECTED_INT4_5_IN_CH;
    filter_dims.n = FULLY_CONNECTED_INT4_5_ACCUMULATION_DEPTH;
    filter_dims.c = FULLY_CONNECTED_INT4_5_OUT_CH;
    output_dims.n = FULLY_CONNECTED_INT4_5_INPUT_BATCHES;
    output_dims.c = FULLY_CONNECTED_INT4_5_OUT_CH;

    fc_params.input_offset = FULLY_CONNECTED_INT4_5_INPUT_OFFSET;
    fc_params.filter_offset = 0;
    fc_params.output_offset = FULLY_CONNECTED_INT4_5_OUTPUT_OFFSET;
    fc_params.activation.min = FULLY_CONNECTED_INT4_5_OUT_ACTIVATION_MIN;
    fc_params.activation.max = FULLY_CONNECTED_INT4_5_OUT_ACTIVATION_MAX;

    quant_params.multiplier = FULLY_CONNECTED_INT4_5_OUTPUT_MULTIPLIER;
    quant_params.shift = FULLY_CONNECTED_INT4_5_OUTPUT_SHIFT;

    int32_t buf_size = 0;
    ctx.buf = malloc(buf_size);
    ctx.size = buf_size;

    arm_cmsis_nn_status result = arm_fully_connected_s4(&ctx,
                                                        &fc_params,
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
}

void fully_connected_int4_arm_fully_connected_s4_6(void)
{
    const arm_cmsis_nn_status expected = ARM_CMSIS_NN_SUCCESS;
    int8_t output[FULLY_CONNECTED_INT4_6_DST_SIZE] = {0};

    cmsis_nn_context ctx;
    cmsis_nn_fc_params fc_params;
    cmsis_nn_per_tensor_quant_params quant_params;
    cmsis_nn_dims input_dims;
    cmsis_nn_dims filter_dims;
    cmsis_nn_dims bias_dims = {};
    cmsis_nn_dims output_dims;

    const int32_t *bias_data = 0;
    const int8_t *kernel_data = fully_connected_int4_6_weights;
    const int8_t *input_data = fully_connected_int4_6_input;
    const int8_t *output_ref = fully_connected_int4_6_output_ref;
    const int32_t output_ref_size = FULLY_CONNECTED_INT4_6_DST_SIZE;

    input_dims.n = FULLY_CONNECTED_INT4_6_INPUT_BATCHES;
    input_dims.w = FULLY_CONNECTED_INT4_6_INPUT_W;
    input_dims.h = FULLY_CONNECTED_INT4_6_INPUT_H;
    input_dims.c = FULLY_CONNECTED_INT4_6_IN_CH;
    filter_dims.n = FULLY_CONNECTED_INT4_6_ACCUMULATION_DEPTH;
    filter_dims.c = FULLY_CONNECTED_INT4_6_OUT_CH;
    output_dims.n = FULLY_CONNECTED_INT4_6_INPUT_BATCHES;
    output_dims.c = FULLY_CONNECTED_INT4_6_OUT_CH;

    fc_params.input_offset = FULLY_CONNECTED_INT4_6_INPUT_OFFSET;
    fc_params.filter_offset = 0;
    fc_params.output_offset = FULLY_CONNECTED_INT4_6_OUTPUT_OFFSET;
    fc_params.activation.min = FULLY_CONNECTED_INT4_6_OUT_ACTIVATION_MIN;
    fc_params.activation.max = FULLY_CONNECTED_INT4_6_OUT_ACTIVATION_MAX;

    quant_params.multiplier = FULLY_CONNECTED_INT4_6_OUTPUT_MULTIPLIER;
    quant_params.shift = FULLY_CONNECTED_INT4_6_OUTPUT_SHIFT;

    int32_t buf_size = 0;
    ctx.buf = malloc(buf_size);
    ctx.size = buf_size;

    arm_cmsis_nn_status result = arm_fully_connected_s4(&ctx,
                                                        &fc_params,
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
}