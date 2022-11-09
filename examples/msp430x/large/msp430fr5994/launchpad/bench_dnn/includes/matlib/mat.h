#ifndef MAT_H
#define MAT_H

#include "../../includes/fixedlib/fixed.h"
#include <stdint.h>

typedef struct {
  uint16_t dims[10];
  uint16_t len_dims;
  uint16_t strides[10];
  fixed *data;
  struct {
    uint16_t dims[10];
    uint16_t len_dims;
    uint16_t *offsets;
    uint16_t *sizes;
  } sparse;
} mat_t;

#define MAT_NUMARGS(...) (sizeof((uint16_t[]){__VA_ARGS__}) / sizeof(uint16_t))

#define MAT_RESHAPE(m, ...)                                                    \
  (mat_reshape(m, ((uint16_t[]){__VA_ARGS__}), MAT_NUMARGS(__VA_ARGS__)))

#define MAT_CONSTRAIN(m, ...)                                                  \
  (mat_constrain(m, ((uint16_t[]){__VA_ARGS__}), MAT_NUMARGS(__VA_ARGS__)))

#define MAT_GET(m, ...)                                                        \
  ((MAT_NUMARGS(__VA_ARGS__) == 1)                                             \
       ? *(m->data + ((uint16_t[]){__VA_ARGS__})[0])                           \
       : (MAT_NUMARGS(__VA_ARGS__) == 2)                                       \
             ? *(m->data + ((uint16_t[]){__VA_ARGS__})[0] * m->strides[0] +    \
                 ((uint16_t[]){__VA_ARGS__})[1])                               \
             : (MAT_NUMARGS(__VA_ARGS__) == 3)                                 \
                   ? *(m->data +                                               \
                       ((uint16_t[]){__VA_ARGS__})[0] * m->strides[0] +        \
                       m->strides[1] * ((uint16_t[]){__VA_ARGS__})[1] +        \
                       ((uint16_t[]){__VA_ARGS__})[2])                         \
                   : mat_get(m, ((uint16_t[]){__VA_ARGS__}),                   \
                             MAT_NUMARGS(__VA_ARGS__)))

#define MAT_PTR(m, ...)                                                        \
  ((MAT_NUMARGS(__VA_ARGS__) == 1)                                             \
       ? (m->data + ((uint16_t[]){__VA_ARGS__})[0])                            \
       : (MAT_NUMARGS(__VA_ARGS__) == 2)                                       \
             ? (m->data + ((uint16_t[]){__VA_ARGS__})[0] * m->strides[0] +     \
                ((uint16_t[]){__VA_ARGS__})[1])                                \
             : (MAT_NUMARGS(__VA_ARGS__) == 3)                                 \
                   ? (m->data +                                                \
                      ((uint16_t[]){__VA_ARGS__})[0] * m->strides[0] +         \
                      m->strides[1] * ((uint16_t[]){__VA_ARGS__})[1] +         \
                      ((uint16_t[]){__VA_ARGS__})[2])                          \
                   : mat_ptr(m, ((uint16_t[]){__VA_ARGS__}),                   \
                             MAT_NUMARGS(__VA_ARGS__)))

#define MAT_SET(m, val, ...)                                                   \
  ((MAT_NUMARGS(__VA_ARGS__) == 1)                                             \
       ? *(m->data + ((uint16_t[]){__VA_ARGS__})[0]) = val                     \
       : (MAT_NUMARGS(__VA_ARGS__) == 2)                                       \
             ? *(m->data + ((uint16_t[]){__VA_ARGS__})[0] * m->strides[0] +    \
                 ((uint16_t[]){__VA_ARGS__})[1]) = val                         \
             : (MAT_NUMARGS(__VA_ARGS__) == 3)                                 \
                   ? *(m->data +                                               \
                       ((uint16_t[]){__VA_ARGS__})[0] * m->strides[0] +        \
                       m->strides[1] * ((uint16_t[]){__VA_ARGS__})[1] +        \
                       ((uint16_t[]){__VA_ARGS__})[2]) = val                   \
                   : mat_set(m, val, ((uint16_t[]){__VA_ARGS__}),              \
                             MAT_NUMARGS(__VA_ARGS__)))

#define MAT_GET_DIM(m, axis) (mat_get_dim(m, axis))

#define MAT_GET_STRIDE(m, aixs) (mat_get_stride(m, axis))

#define MAT_TRANSPOSE(m) (mat_transpose(m))

#define MAT_COPY(src, dest) (mat_copy(src, dest))

#ifdef CONFIG_CONSOLE
#define MAT_DUMP(m, w) (mat_dump(m, w))
#else
#define MAT_DUMP(m, w) (void)(0)
#endif

#define MAT_DEBUG_DUMP(m, v, d) (mat_debug_dump(m, v, d))

void mat_reshape(mat_t *, uint16_t[], uint16_t);
mat_t mat_constrain(mat_t *, uint16_t[], uint16_t);
fixed mat_get(mat_t *, uint16_t[], uint16_t);
fixed *mat_ptr(mat_t *, uint16_t[], uint16_t);
void mat_set(mat_t *, fixed, uint16_t[], uint16_t);
uint16_t mat_get_dim(mat_t *, uint16_t);
uint16_t mat_get_stride(mat_t *, uint16_t);
void mat_transpose(mat_t *);
void mat_copy(mat_t *, mat_t *);
void mat_dump(mat_t *, uint16_t);
void mat_debug_dump(mat_t *, uint16_t, fixed *);

#endif
