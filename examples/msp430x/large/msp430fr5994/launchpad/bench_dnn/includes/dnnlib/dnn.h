/*
 * dnn.h
 *
 *  Created on: 24 Haz 2020
 *      Author: eren
 */

#ifndef INCLUDES_DNNLIB_DNN_H_
#define INCLUDES_DNNLIB_DNN_H_

#include "../../includes/matlib/mat.h"
#include <stdbool.h>
#include <stdint.h>

#define CONFIG_LAYER_BUF_SIZE 0x3D41
#define LAYER_BUF_NUMBER 3
#define MAT_BUF_NUMBER 3
#define MAT_BUF_SIZE 0x310
extern fixed layer_buffers[LAYER_BUF_NUMBER][CONFIG_LAYER_BUF_SIZE];
extern fixed mat_buffers[MAT_BUF_NUMBER][MAT_BUF_SIZE];

typedef struct {
  bool same_padding;
  bool transpose;
  uint16_t stride[3]; // pooling window strides(layer, rows, collumns)
  uint16_t size[3];   // pooling window size (layer, rows, collumns)
} dnn_param;

extern dnn_param params;

void convol(mat_t *src, mat_t *dest, mat_t *w, mat_t *b);

void convol_depth(mat_t *src, mat_t *dest, mat_t *w, mat_t *b);

void fc_sparse(mat_t *src, mat_t *dest, mat_t *weight, mat_t *bias);

void fc_dense(mat_t *src, mat_t *dest, mat_t *weight, mat_t *bias);

void pooling(mat_t *src, mat_t *dest);

void relu(mat_t *src, mat_t *dest);

uint16_t prediction(mat_t *src);

#endif /* INCLUDES_DNNLIB_DNN_H_ */
