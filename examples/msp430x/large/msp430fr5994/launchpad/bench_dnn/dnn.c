/**
 * \file dnn.c
 *
 * \copyright Copyright 2022 The ImmortalThreads authors. All rights reserved.
 * \license MIT License. See accompanying file LICENSE.txt at
 * https://github.com/tinysystems/ImmortalThreads/blob/main/LICENSE.txt
 */

#include "tpl_os.h"

#include "includes/dnnlib/dnn.h"
#include "includes/dnnlib/dnn_calc.h"
#include <stdlib.h>

#define APP_Task_dnn_main_START_SEC_VAR_NON_VOLATILE_UNSPECIFIED
#include "tpl_memmap.h"
VAR(dnn_param, AUTOMATIC) params;
#define APP_Task_dnn_main_STOP_SEC_VAR_NON_VOLATILE_UNSPECIFIED
#include "tpl_memmap.h"
// __fram dnn_param params;

#define APP_Task_dnn_main_START_SEC_FRAM_UP_VAR_FRAM_UP_16BIT
#include "tpl_memmap.h"
VAR(fixed, AUTOMATIC) layer_buffers[LAYER_BUF_NUMBER][CONFIG_LAYER_BUF_SIZE];
VAR(fixed, AUTOMATIC) mat_buffers[MAT_BUF_NUMBER][MAT_BUF_SIZE];
#define APP_Task_dnn_main_STOP_SEC_FRAM_UP_VAR_FRAM_UP_16BIT
#include "tpl_memmap.h"
// __hifram fixed layer_buffers[LAYER_BUF_NUMBER][CONFIG_LAYER_BUF_SIZE];
// __hifram fixed mat_buffers[MAT_BUF_NUMBER][MAT_BUF_SIZE];

#define APP_Task_dnn_main_START_SEC_VAR_NON_VOLATILE_UNSPECIFIED
#include "tpl_memmap.h"
VAR(mat_t, AUTOMATIC) m = {.data = layer_buffers[2]};
P2VAR(mat_t, AUTOMATIC, OS_APPL_DATA) inter = &m;
VAR(mat_t, AUTOMATIC) c_src, c_filter, c_dest, c_inter;
P2VAR(mat_t, AUTOMATIC, OS_APPL_DATA) c_filter_ptr = &c_filter;
P2VAR(mat_t, AUTOMATIC, OS_APPL_DATA) c_src_ptr = &c_src;
P2VAR(mat_t, AUTOMATIC, OS_APPL_DATA) c_dest_ptr = &c_dest;
P2VAR(mat_t, AUTOMATIC, OS_APPL_DATA) c_inter_ptr = &c_inter;
#define APP_Task_dnn_main_STOP_SEC_VAR_NON_VOLATILE_UNSPECIFIED
#include "tpl_memmap.h"

// static __fram mat_t m = {.data = layer_buffers[2]};
// static __fram mat_t *inter = &m;
// static __fram mat_t c_src, c_filter, c_dest, c_inter;
// static __fram mat_t *c_filter_ptr = &c_filter;
// static __fram mat_t *c_src_ptr = &c_src;
// static __fram mat_t *c_dest_ptr = &c_dest;
// static __fram mat_t *c_inter_ptr = &c_inter;

void pooling(mat_t *src, mat_t *dest) {
  uint16_t layers = MAT_GET_DIM(src, 0);
  uint16_t rows = MAT_GET_DIM(src, 1);
  uint16_t k;
  uint16_t j;
  for (uint16_t i = 0; i < layers; i++) {
    for (j = 0; j < rows; j += params.stride[1]) {
      for (k = 0; k < rows; k += params.stride[2]) {
        fixed max = MAT_GET(src, i, j, k);
        for (uint16_t l = 0; l < params.size[1]; l++) {
          for (uint16_t m = 0; m < params.size[2]; m++) {
            fixed val = MAT_GET(src, i, j + l, k + m);
            if (F_LT(max, val))
              max = val;
          }
        }
        MAT_SET(dest, max, i, j / params.stride[1], k / params.stride[2]);
      }
      k = 0;
    }
    j = 0;
  }
}

void relu(mat_t *src, mat_t *dest) {

  uint16_t total_elements = MAT_GET_DIM(src, 0) * MAT_GET_DIM(src, 1);
  if (src->len_dims == 3) {
    total_elements *= MAT_GET_DIM(src, 2);
  }
  fixed max = F_LIT(0.0);
  for (uint16_t i = 0; i < total_elements; i++) {
    max = *(src->data + i);
    *(dest->data + i) = (F_LT(max, F_LIT(0.0))) ? F_LIT(0.0) : max;
  }
}

uint16_t prediction(mat_t *src) {
  uint16_t predict;
  fixed max = 0;

  for (uint16_t i = 0; i < 10; i++) {
    fixed v = MAT_GET(src, i, 0);
    if (v > max) {
      predict = i;
      max = v;
    }
  }
  return predict;
}

void convol(mat_t *src, mat_t *dest, mat_t *w, mat_t *b) {

  // MAT_RESHAPE(inter, dest->dims, dest->len_dims);
  mat_reshape(inter, dest->dims, dest->len_dims);
  uint16_t filters = w->sparse.dims[0];

  uint16_t running_size = 0;

  for (uint16_t i = 0; i < filters; i++) {
    if (w->sparse.sizes[i] > 0) {

      c_filter = MAT_CONSTRAIN(w, running_size); // Selecting filter
      c_filter.dims[0] = w->sparse.sizes[i];
      c_filter.sparse.len_dims = w->sparse.len_dims - 1;
      c_inter =
          (b == NULL)
              ? MAT_CONSTRAIN(dest, i)
              : MAT_CONSTRAIN(
                    inter, i); // destination of selected filter's feature map

      running_size =
          running_size + w->sparse.sizes[i];   // Filter element size positio
      con_mul(src, c_inter_ptr, c_filter_ptr); // convolving
    } else {

      c_inter = (b == NULL) ? MAT_CONSTRAIN(dest, i) : MAT_CONSTRAIN(inter, i);
      ds_zero(src, c_inter_ptr);
    }
  }
  if (b != NULL) {
    for (uint16_t i = 0; i < filters; i++) {

      // Assumes filter, dest, src in that order
      c_inter = MAT_CONSTRAIN(inter, i);
      c_filter = MAT_CONSTRAIN(b, i);
      c_dest = MAT_CONSTRAIN(dest, i);

      ds_add(c_inter_ptr, c_dest_ptr, c_filter_ptr);
    }
  }
}

void convol_depth(mat_t *src, mat_t *dest, mat_t *w, mat_t *b) {

  mat_reshape(inter, dest->dims, dest->len_dims);
  uint16_t filters = w->sparse.dims[0];
  uint16_t running_size = 0;

  for (uint16_t i = 0; i < filters; i++) {
    if (w->sparse.sizes[i] > 0) {

      c_filter = MAT_CONSTRAIN(w, running_size); // Selecting filter
      c_filter.dims[0] = w->sparse.sizes[i];
      c_filter.sparse.len_dims = w->sparse.len_dims - 1;
      c_inter =
          (b == NULL)
              ? MAT_CONSTRAIN(dest, i)
              : MAT_CONSTRAIN(
                    inter, i); // destination of selected filter's feature map
      c_src = MAT_CONSTRAIN(src, i);
      MAT_RESHAPE(c_src_ptr, 1, MAT_GET_DIM(src, 1), MAT_GET_DIM(src, 2));
      running_size =
          running_size + w->sparse.sizes[i]; // Filter element size position

      con_mul(c_src_ptr, c_inter_ptr, c_filter_ptr); // convolving
    }
  }
  if (b != NULL) {
    for (uint16_t i = 0; i < filters; i++) {

      // Assumes filter, dest, src in that order
      c_inter = MAT_CONSTRAIN(inter, i);
      c_filter = MAT_CONSTRAIN(b, i);
      c_dest = MAT_CONSTRAIN(dest, i);

      ds_add(c_inter_ptr, c_dest_ptr, c_filter_ptr);
    }
  }
}
/*
void convol_biasing (mat_t *src, mat_t *dest,  mat_t *w, mat_t *bias){



   //Biasing

    uint16_t b_rows=dest->dims[1];
    uint16_t b_cols=dest->dims[2];
    uint16_t total_elements= b_rows*b_cols;
    uint16_t filters = w->sparse.dims[0];
    uint16_t i,j;


    for(i=0;i<filters;i++){
        for(j=0;j<total_elements;j++){

            if(bias == NULL) {
                fixed sw = MAT_GET(src, total_elements*i + j);
                MAT_SET(dest, sw, i,j);
              }else {
                fixed sw = F_ADD(MAT_GET(src, total_elements*i +
j),MAT_GET(bias, i)); MAT_SET(dest, sw, i,j);
              }
        }
    }


}
*/
void fc_sparse(mat_t *src, mat_t *dest, mat_t *w, mat_t *b) {

  mat_reshape(inter, dest->dims, dest->len_dims);

  // Sparse mat mul

  fc_sparse_mul(src, (b == NULL) ? dest : inter, w); // Sparse mat mul

  if (b != NULL) {
    // Bias
    dm_add(inter, dest, b);
  }
}

void fc_dense(mat_t *src, mat_t *dest, mat_t *w, mat_t *b) {
  mat_reshape(inter, dest->dims, dest->len_dims);

  // Dense mat mul
  fc_dense_mul(src, (b == NULL) ? dest : inter, w);
  if (b != NULL) {
    // Bias
    dm_add(inter, dest, b);
  }
}

/*
void fc_biasing (mat_t *src, mat_t *dest, mat_t *bias){

    // Bias

        uint16_t rows = MAT_GET_DIM(src, 0);
        uint16_t cols = MAT_GET_DIM(src, 1);

        for(uint16_t i = 0; i < rows; i++ ) {
            for(uint16_t j = 0; j < cols; j++) {

                if(bias == NULL) {
                    fixed w = MAT_GET(src, i, j);
                    MAT_SET(dest, w, i, j);
                }else{
                    fixed w = F_ADD(MAT_GET(src, i, j), MAT_GET(bias, i, j));
                    MAT_SET(dest, w, i, j);
                }

            }

        }

}

*/
