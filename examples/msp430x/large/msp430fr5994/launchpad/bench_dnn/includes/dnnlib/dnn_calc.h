/*
 * dnn_calc.h
 *
 *  Created on: 24 Haz 2020
 *      Author: eren
 */

#ifndef INCLUDES_DNNLIB_DNN_CALC_H_
#define INCLUDES_DNNLIB_DNN_CALC_H_

#include "../../includes/matlib/mat.h"

void con_mul(mat_t *src, mat_t *dest, mat_t *filter);

void fc_sparse_mul(mat_t *src, mat_t *dest, mat_t *filter);

void fc_dense_mul(mat_t *src, mat_t *dest, mat_t *filter);

void ds_zero(mat_t *src, mat_t *dest);

void ds_add(mat_t *src, mat_t *dest, mat_t *filter);

void dm_add(mat_t *src, mat_t *dest, mat_t *bias);

#endif /* INCLUDES_DNNLIB_DNN_CALC_H_ */
