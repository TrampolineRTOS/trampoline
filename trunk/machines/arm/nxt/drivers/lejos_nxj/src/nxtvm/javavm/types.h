#ifndef _TYPES_H
#define _TYPES_H

#include "drivers/lejos_nxj/src/nxtvm/platform/nxt/platform_config.h"

typedef byte boolean;

/*
 * The following types must be defined in platform_config.h:
 * JBYTE
 * JSHORT
 * JINT
 * TWOBYTES
 * FOURBYTES
 */


typedef float        JFLOAT;
typedef JBYTE        JBOOLEAN;
typedef JSHORT       JCHAR;
typedef FOURBYTES    REFERENCE;
typedef FOURBYTES    STACKWORD;

typedef union
{
  JFLOAT fnum;
  STACKWORD sword;
} AuxConvUnion1;

typedef struct
{
  STACKWORD hi;
  STACKWORD lo;
} JLONG;


#ifndef LITTLE_ENDIAN
#error LITTLE_ENDIAN not defined in platform_config.h
#endif

#define jfloat2word(FLOAT_) (((AuxConvUnion1) (FLOAT_)).sword)
#define word2jfloat(WORD_)  (((AuxConvUnion1) (WORD_)).fnum)
#define byte2jint(BYTE_)    ((JINT) (signed char) (BYTE_))
#define word2jint(WORD_)    ((JINT) (WORD_))
#define word2jshort(WORD_)  ((JSHORT) (WORD_))
#define word2obj(WORD_)     ((Object *) word2ptr(WORD_))
#define obj2word(OBJ_)      ptr2word(OBJ_)
#define obj2ref(OBJ_)       ptr2ref(OBJ_)
#define obj2ptr(OBJ_)       ((void *) (OBJ_))
#define ptr2ref(PTR_)       ((REFERENCE) ptr2word(PTR_))
#define ref2ptr(REF_)       word2ptr((STACKWORD) (REF_))
#define ref2obj(REF_)       ((Object *) ref2ptr(REF_))

#if 0
static inline JINT jlong_compare (JLONG a1, JLONG a2)
{
  if (a1.hi == a2.hi)
    return a1.lo - a2.lo;
  return a1.hi - a2.hi;
}
#endif

#endif // _TYPES_H


