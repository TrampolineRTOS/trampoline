#ifndef __ARCH_CC_H__
#define __ARCH_CC_H__

#include "utils.h"

#define LWIP_ERR_T  int

#define LWIP_PROVIDE_ERRNO

/* Define (sn)printf formatters for these lwIP types */
#define U16_F "u"
#define S16_F "d"
#define X16_F "x"
#define U32_F "u"
#define S32_F "d"
#define X32_F "x"

/* Compiler hints for packing structures */
#define PACK_STRUCT_FIELD(x)    x
#define PACK_STRUCT_STRUCT  __attribute__((packed))
#define PACK_STRUCT_BEGIN
#define PACK_STRUCT_END

/* Plaform specific diagnostic output */
#define LWIP_PLATFORM_DIAG(x)   do {                \
        debug_msg x;                               \
    } while (0)

#define LWIP_PLATFORM_ASSERT(x) do {                \
    } while (0)

#endif /* __ARCH_CC_H__ */
