#ifndef  __SYSTICK_H__
#  define __SYSTICK_H__

#  include "mytypes.h"

void systick_init(void);

U32 systick_get_ms(void);

void systick_wait_ms(U32 ms);

void systick_wait_ns(U32 n);

void systick_test(void);

void systick_suspend(void);

void systick_resume(void);

#endif
