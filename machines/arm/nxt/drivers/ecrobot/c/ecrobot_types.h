#ifndef _ECROBOT_TYPES_H_
#define _ECROBOT_TYPES_H_

#include "drivers/lejos_nxj/src/nxtvm/platform/nxt/mytypes.h"

typedef          char CHAR; /* NOTE: ARM GCC treats "char" as unsigned */

#ifdef NXT_JSP
#ifndef UINT_DEFINED
#define UINT_DEFINED
typedef unsigned int UINT;
#endif
#else
typedef unsigned  int UINT;
#endif
typedef   signed  int SINT;
typedef         float F32;
typedef        double F64;

#endif
