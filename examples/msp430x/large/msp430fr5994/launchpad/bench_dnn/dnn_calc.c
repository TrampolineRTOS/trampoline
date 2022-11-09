/**
 * \file dnn_calc.c
 *
 * \copyright Copyright 2022 The ImmortalThreads authors. All rights reserved.
 * \license MIT License. See accompanying file LICENSE.txt at
 * https://github.com/tinysystems/ImmortalThreads/blob/main/LICENSE.txt
 */

#include "tpl_os.h"
#include "includes/dnnlib/dnn.h"
#include "includes/dnnlib/dnn_calc.h"
#include <stdbool.h>
#include <stdlib.h>


#define APP_Task_dnn_main_START_SEC_VAR_NON_VOLATILE_UNSPECIFIED
#include "tpl_memmap.h"
VAR(mat_t, AUTOMATIC) buf = {.data = mat_buffers[0]};
P2VAR(mat_t, AUTOMATIC, OS_APPL_DATA) buffer = &buf;
#define APP_Task_dnn_main_STOP_SEC_VAR_NON_VOLATILE_UNSPECIFIED
#include "tpl_memmap.h"

// static __fram mat_t buf = {.data = mat_buffers[0]};
// static __fram mat_t *buffer = &buf;

void con_mul(mat_t *src, mat_t *dest, mat_t *filter) {
  mat_t *inter = buffer;
  uint16_t rows = MAT_GET_DIM(dest, 0); // input rows
  uint16_t cols = MAT_GET_DIM(dest, 1); // input columns
  MAT_RESHAPE(inter, rows, cols);

  uint16_t frows = filter->sparse.dims[1]; // filter rows
  uint16_t fcols = filter->sparse.dims[2]; // filter columns
  uint16_t total_elements = MAT_GET_DIM(filter, 0);
  uint16_t swap = 1;

  uint16_t pos = 0;
  uint16_t idx = 0;

  for (pos; pos < total_elements; pos++) {
    swap = swap ^ 0x01;
    mat_t *tmp = dest;
    if (pos != 0) { // Swap buffers
      dest = inter;
      inter = tmp;
    }
    bool zero = false;
    if (pos == 0) {
      zero = true;
      idx += filter->sparse.offsets[pos];
    }
    uint16_t k = idx / (fcols * frows);           // Layers
    uint16_t l = (idx % (fcols * frows)) / fcols; // Rows
    uint16_t n = idx % fcols;                     // Cols

    fixed f = MAT_GET(filter, pos);

    fixed *dest_ptr = MAT_PTR(dest, 0, 0);
    fixed *inter_ptr = MAT_PTR(inter, 0, 0);
    for (uint16_t i = 0; i < rows * params.stride[1]; i += params.stride[1]) {
      fixed *src_ptr = MAT_PTR(src, k, i + l, n);
      for (uint16_t j = 0; j < cols * params.stride[2]; j += params.stride[2]) {
        fixed w = 0;
        if (!params.same_padding ||
            (i + l < MAT_GET_DIM(src, 1) && j + n < MAT_GET_DIM(src, 2))) {
          w = F_MUL(f, *src_ptr);
        }
        if (!zero) {
          w = F_ADD(w, *inter_ptr);
          inter_ptr++;
        }

        *dest_ptr = w;
        dest_ptr++;
        src_ptr += params.stride[2];
      }
    }
    idx = idx + filter->sparse.offsets[pos + 1];
  }

  if (swap) {
    for (uint16_t i = 0; i < rows; i++) {
      for (uint16_t j = 0; j < cols; j++) {
        MAT_SET(inter, MAT_GET(dest, i, j), i, j);
      }
    }
  }
}

void fc_sparse_mul(mat_t *src, mat_t *dest, mat_t *filter) {

  uint16_t rows = MAT_GET_DIM(dest, 0);

  for (uint16_t i = 0; i < rows; i++) {
    uint16_t start = filter->sparse.sizes[i];
    uint16_t end = filter->sparse.sizes[i + 1];
    uint16_t col_idx = start;
    fixed *filter_ptr = MAT_PTR(filter, col_idx);
    fixed *dest_ptr = MAT_PTR(dest, i, 0);
    uint16_t *offset = filter->sparse.offsets + col_idx;

    /*
     if(i == pos_bak.i && j == pos_bak.j) { // Restore it i, j are the same
         *dest_ptr = val_bak;
     }*/
    if (start == end) {
      // val_bak = 0;
      // pos_bak.i = i;
      *dest_ptr = 0;
    }

    for (uint16_t j = 0; j < end - start; j++) {
      fixed w = F_MUL(MAT_GET(src, *offset, 0), *filter_ptr++);
      if (j == 0) {
        *dest_ptr = w; // Zeroing the vector
      } else {

        w = F_ADD(w, *dest_ptr);
        *dest_ptr = w;
      }
      offset++;
    }
    dest_ptr++;
  }
}

void fc_dense_mul(mat_t *src, mat_t *dest, mat_t *filter) {

  uint16_t rows = MAT_GET_DIM(filter, 0);
  uint16_t cols = MAT_GET_DIM(filter, 1);
  fixed *dest_ptr = MAT_PTR(dest, 0, 0);

  for (uint16_t i = 0; i < rows; i++) {
    fixed *src_ptr = MAT_PTR(src, 0, 0);
    uint16_t k = 0;
    for (uint16_t j = 0; j < cols; j++) {
      fixed w = F_MUL(MAT_GET(filter, i, j), *src_ptr);
      if (k > 0) {
        w = F_ADD(w, *dest_ptr);
      }
      *dest_ptr = w;
      k++;
      src_ptr++;
    }
    dest_ptr++;
  }
}

void ds_add(mat_t *src, mat_t *dest, mat_t *filter) {

  uint16_t rows = MAT_GET_DIM(src, 0);
  uint16_t cols = MAT_GET_DIM(src, 1);
  for (uint16_t i = 0; i < rows; i++) {
    for (uint16_t j = 0; j < cols; j++) {
      fixed w = F_ADD(MAT_GET(src, i, j), MAT_GET(filter, 0));
      MAT_SET(dest, w, i, j);
    }
  }
}

void ds_zero(mat_t *src, mat_t *dest) {
  uint16_t rows = MAT_GET_DIM(src, 0);
  uint16_t cols = MAT_GET_DIM(src, 1);
  for (uint16_t i = 0; i < rows; i++) {
    for (uint16_t j = 0; j < cols; j++) {
      MAT_SET(dest, 0, i, j);
    }
  }
}

void dm_add(mat_t *src, mat_t *dest, mat_t *bias) {

  // Bias

  uint16_t rows = MAT_GET_DIM(src, 0);
  uint16_t cols = MAT_GET_DIM(src, 1);

  for (uint16_t i = 0; i < rows; i++) {
    for (uint16_t j = 0; j < cols; j++) {
      fixed w = F_ADD(MAT_GET(src, i, j), MAT_GET(bias, i, j));
      MAT_SET(dest, w, i, j);
    }
  }
}
