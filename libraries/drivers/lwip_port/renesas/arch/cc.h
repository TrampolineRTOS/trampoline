#ifndef __ARCH_CC_H__
#define __ARCH_CC_H__

#include "utils.h"

// Hack to use our own 'atoi' function in order to prevent usage of libc one, because libc 'atoi' has many dependencies
#undef atoi
//unsigned int atoi(const unsigned char* s);
int atoi(const char *num);

#define LWIP_ERR_T  int

#define LWIP_PROVIDE_ERRNO

/* Define (sn)printf formatters for these lwIP types */
#define U16_F "u"
#define S16_F "d"
#define X16_F "x"
#define U32_F "u"
#define S32_F "d"
#define X32_F "x"

#define BYTE_ORDER LITTLE_ENDIAN

/* Compiler hints for packing structures */
#define PACK_STRUCT_FIELD(x)    x
#define PACK_STRUCT_STRUCT  __attribute__((packed))
#define PACK_STRUCT_BEGIN
#define PACK_STRUCT_END

/* Plaform specific diagnostic output */
#define LWIP_PLATFORM_DIAG(x)   do {                \
        debug_msg x;                                \
    } while (0)

#define LWIP_PLATFORM_ASSERT(x) do {                \
        while(1);                                   \
    } while (0)

#endif /* __ARCH_CC_H__ */
