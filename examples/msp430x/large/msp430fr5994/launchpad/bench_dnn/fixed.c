/**
 * \file fixed.c
 *
 * \copyright Copyright 2022 The ImmortalThreads authors. All rights reserved.
 * \license MIT License. See accompanying file LICENSE.txt at
 * https://github.com/tinysystems/ImmortalThreads/blob/main/LICENSE.txt
 */

#include "includes/fixedlib/fixed.h"
#include <stdint.h>

fixed f_sqrt(fixed a) {
  fixed tmp = F_MUL(F_LIT(0.5), a);
#ifdef CONFIG_FIXED_PRECISE
  for (uint16_t i = 0; i < 8; i++) {
#else
  for (uint16_t i = 0; i < 4; i++) {
#endif
    tmp = F_MUL(F_LIT(0.5), F_ADD(tmp, F_DIV(a, tmp)));
  }
  return tmp;
}

fixed f_cos(fixed a) {
  fixed tmp = a;
  // Scale
  if (F_LT(F_TWO_PI, tmp)) {
    fixed close = F_MUL(F_TWO_PI, -F_ROUND(F_DIV(tmp, F_TWO_PI)));
    tmp = F_ADD(tmp, close);
  } else if (F_LT(tmp, -F_TWO_PI)) {
    fixed close = F_MUL(F_TWO_PI, F_ROUND(F_DIV(-tmp, F_TWO_PI)));
    tmp = F_ADD(tmp, close);
  }

  // Center around -F_PI and F_PI
  if (F_LT(tmp, -F_PI)) {
    tmp = F_ADD(F_TWO_PI, tmp);
  } else if (F_LT(F_PI, tmp)) {
    tmp = F_ADD(-F_TWO_PI, tmp);
  }

  // Shift
  tmp = F_ADD(tmp, F_HALF_PI);
  if (F_LT(F_PI, tmp)) {
    tmp = F_ADD(-F_TWO_PI, tmp);
  }

  // Apply cos/sin
  fixed first_term = F_MUL(F_LIT(1.27323954), tmp);
  fixed second_term = F_MUL(F_MUL(F_LIT(0.405284735), tmp), tmp);
  if (F_LT(tmp, F_LIT(0))) {
    tmp = first_term + second_term;
#ifdef CONFIG_FIXED_PRECISE
    if (F_LT(tmp, F_LIT(0))) {
      return F_ADD(F_MUL(F_LIT(0.225), F_ADD(F_MUL(tmp, -tmp), -tmp)), tmp);
    }
    return F_ADD(F_MUL(F_LIT(0.225), F_ADD(F_MUL(tmp, tmp), -tmp)), tmp);
#else
    return tmp;
#endif
  }
  tmp = first_term - second_term;
#ifdef CONFIG_FIXED_PRECISE
  if (F_LT(tmp, F_LIT(0))) {
    return F_ADD(F_MUL(F_LIT(0.225), F_ADD(F_MUL(tmp, -tmp), -tmp)), tmp);
  }
  return F_ADD(F_MUL(F_LIT(0.225), F_ADD(F_MUL(tmp, tmp), -tmp)), tmp);
#else
  return tmp;
#endif
}

fixed f_sin(fixed a) {
  fixed tmp = a;
  // Scale
  if (F_LT(F_TWO_PI, tmp)) {
    fixed close = F_MUL(F_TWO_PI, -F_ROUND(F_DIV(tmp, F_TWO_PI)));
    tmp = F_ADD(tmp, close);
  } else if (F_LT(tmp, -F_TWO_PI)) {
    fixed close = F_MUL(F_TWO_PI, F_ROUND(F_DIV(-tmp, F_TWO_PI)));
    tmp = F_ADD(tmp, close);
  }

  // Center around -F_PI and F_PI
  if (F_LT(tmp, -F_PI)) {
    tmp = F_ADD(F_TWO_PI, tmp);
  } else if (F_LT(F_PI, tmp)) {
    tmp = F_ADD(-F_TWO_PI, tmp);
  }

  // Apply cos/sin
  fixed first_term = F_MUL(F_LIT(1.27323954), tmp);
  fixed second_term = F_MUL(F_MUL(F_LIT(0.405284735), tmp), tmp);
  if (F_LT(tmp, F_LIT(0))) {
    tmp = first_term + second_term;
#ifdef CONFIG_FIXED_PRECISE
    if (F_LT(tmp, F_LIT(0))) {
      return F_ADD(F_MUL(F_LIT(0.225), F_ADD(F_MUL(tmp, -tmp), -tmp)), tmp);
    }
    return F_ADD(F_MUL(F_LIT(0.225), F_ADD(F_MUL(tmp, tmp), -tmp)), tmp);
#else
    return tmp;
#endif
  }
  tmp = first_term - second_term;
#ifdef CONFIG_FIXED_PRECISE
  if (F_LT(tmp, F_LIT(0))) {
    return F_ADD(F_MUL(F_LIT(0.225), F_ADD(F_MUL(tmp, -tmp), -tmp)), tmp);
  }
  return F_ADD(F_MUL(F_LIT(0.225), F_ADD(F_MUL(tmp, tmp), -tmp)), tmp);
#else
  return tmp;
#endif
}
