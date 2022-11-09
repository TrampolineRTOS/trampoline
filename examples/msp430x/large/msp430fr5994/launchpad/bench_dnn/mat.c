/**
 * \file mat.c
 *
 * \copyright Copyright 2022 The ImmortalThreads authors. All rights reserved.
 * \license MIT License. See accompanying file LICENSE.txt at
 * https://github.com/tinysystems/ImmortalThreads/blob/main/LICENSE.txt
 */

#include "includes/matlib/mat.h"
// #include "/opt/energia-1.8.10E23/hardware/tools/msp430/include/string.h"
#include <string.h>

uint16_t _offset_calc(mat_t *m, uint16_t idxs[],
                                              uint16_t len) {
  uint16_t offset = 0;
  for (uint16_t i = 0; i < len; i++) {
    offset += m->strides[i] * idxs[i];
  }
  return offset;
}

void mat_reshape(mat_t *m, uint16_t dims[], uint16_t len) {
  m->len_dims = len;
  uint16_t running_stride = 1;
  memset(m->strides, 1, sizeof(uint16_t) * (len + 1));
  for (uint16_t i = 0; i < len; i++) {
    m->dims[i] = dims[i];
    m->strides[len - i - 1] = running_stride;
    running_stride *= dims[len - i - 1];
  }
}

mat_t mat_constrain(mat_t *m, uint16_t idxs[], uint16_t len) {
  uint16_t len_dims = m->len_dims - len;
  uint16_t offset = _offset_calc(m, idxs, len);
  mat_t c_m;
  c_m.len_dims = len_dims;
  memcpy(c_m.dims, m->dims + len, sizeof(uint16_t) * len_dims);
  memset(c_m.strides, 1, sizeof(uint16_t) * (len_dims + 1));
  memcpy(c_m.strides, m->strides + len, sizeof(uint16_t) * len_dims);
  memcpy(c_m.sparse.dims, m->sparse.dims + len, sizeof(uint16_t) * 10);
  c_m.data = m->data + offset;
  c_m.sparse.len_dims = m->sparse.len_dims;
  c_m.sparse.offsets = m->sparse.offsets + offset;
  c_m.sparse.sizes = m->sparse.sizes;
  return c_m;
}

fixed mat_get(mat_t *m, uint16_t idxs[], uint16_t len) {
  return *mat_ptr(m, idxs, len);
}

fixed *mat_ptr(mat_t *m, uint16_t idxs[], uint16_t len) {
  return m->data + _offset_calc(m, idxs, len);
}

void mat_set(mat_t *m, fixed v, uint16_t idxs[], uint16_t len) {
  *(m->data + _offset_calc(m, idxs, len)) = v;
}

uint16_t mat_get_dim(mat_t *m, uint16_t axis) { return m->dims[axis]; }

uint16_t mat_get_stride(mat_t *m, uint16_t axis) { return m->strides[axis]; }

void mat_transpose(mat_t *m) {
  uint16_t start = 0;
  uint16_t end = m->len_dims - 1;
  while (start < end) {
    uint16_t tmp = m->dims[start];
    m->dims[start] = m->dims[end];
    m->dims[end] = tmp;

    tmp = m->strides[start];
    m->strides[start] = m->strides[end];
    m->strides[end] = tmp;

    start++;
    end--;
  }
}

void mat_copy(mat_t *src, mat_t *dest) {
  memcpy(dest->dims, src->dims, sizeof(uint16_t) * src->len_dims);
  memset(dest->strides, 1, sizeof(uint16_t) * src->len_dims);
  memcpy(dest->strides, src->strides, sizeof(uint16_t) * src->len_dims);
  memcpy(dest->sparse.dims, src->sparse.dims,
         sizeof(uint16_t) * src->sparse.len_dims);
  dest->data = src->data;
  dest->len_dims = src->len_dims;
  dest->sparse.len_dims = src->sparse.len_dims;
  dest->sparse.offsets = src->sparse.offsets;
  dest->sparse.sizes = src->sparse.sizes;
}

void mat_dump(mat_t *m, uint16_t which) {
  uint16_t rows = MAT_GET_DIM(m, m->len_dims - 2);
  uint16_t cols = MAT_GET_DIM(m, m->len_dims - 1);

  for (uint16_t i = 0; i < rows; i++) {
    for (uint16_t j = 0; j < cols; j++) {
    }
  }
}

void mat_debug_dump(mat_t *m, uint16_t which, fixed *dest) {
  fixed *dest_ptr = dest;
  uint16_t rows = MAT_GET_DIM(m, m->len_dims - 2);
  uint16_t cols = MAT_GET_DIM(m, m->len_dims - 1);
  for (uint16_t i = 0; i < rows; i++) {
    for (uint16_t j = 0; j < cols; j++) {
      *dest_ptr = MAT_GET(m, which, i, j);
      dest_ptr++;
    }
  }
}
