#include "Os.h"
#include "tpl_app_define.h"

#if TARGET_ARCH == ARCH_POSIX
  #include <stdio.h>
#endif

#if TARGET_ARCH == ARCH_ARM
  #define RANDOM_PERIPHERAL_ADRESS AT91C_TC0_RC /* i2c period */
#elif TARGET_ARCH == ARCH_PPC
  VAR(u32, OS_CODE) PITC = 0;
  // TODO : find register to the timer period for example
  #define RANDOM_PERIPHERAL_ADRESS &PITC /* timer period */
#elif TARGET_ARCH == ARCH_POSIX
  #define OS_START_SEC_VAR_32BIT
  #include "tpl_memmap.h"
  VAR(u32, OS_CODE) var_to_test_peripheral_access = 0;
  #define OS_STOP_SEC_VAR_32BIT
  #include "tpl_memmap.h"
  #define RANDOM_PERIPHERAL_ADRESS &var_to_test_peripheral_access
#endif

/**
 * Common library
 *
 */
#define APP_COMMON_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(StatusType, OS_CODE) test_common_function(u32 cmp, u32 value)
{
  StatusType ret = 0;
  if (value < cmp)
  {
    ret = 1;
  }
  return ret;
}
#define APP_COMMON_STOP_SEC_CODE
#include "tpl_memmap.h"

/**
 * OS_CODE
 *
 */
#define OS_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(int, OS_CODE) main(void)
{  
	StartOS(OSDEFAULTAPPMODE);
	return 0;
}
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

DeclareEvent(Event1);
DeclareTask(t1_app_nontrusted1);
DeclareTask(t1_app_trusted1);

/**
 * Vars
 *
 */
#define APP_Task_t1_app_nontrusted1_START_SEC_VAR_32BIT
#include "tpl_memmap.h"
VAR(u32, OS_APPL_DATA) var1_t1_app_nontrusted1 = 1;
VAR(u32, OS_APPL_DATA) var2_t1_app_nontrusted1 = 0;
#define APP_Task_t1_app_nontrusted1_STOP_SEC_VAR_32BIT
#include "tpl_memmap.h"

#define APP_Task_t1_app_trusted1_START_SEC_VAR_32BIT
#include "tpl_memmap.h"
VAR(u32, OS_APPL_DATA) var1_t1_app_trusted1 = 1;
VAR(u32, OS_APPL_DATA) var2_t1_app_trusted1 = 0;
#define APP_Task_t1_app_trusted1_STOP_SEC_VAR_32BIT
#include "tpl_memmap.h"

/**
 * t1_app_nontrusted1
 *
 */
#define APP_Task_t1_app_nontrusted1_START_SEC_CODE
#include "tpl_memmap.h"
TASK(t1_app_nontrusted1)
{
#if TARGET_ARCH == ARCH_POSIX
  printf("1.t1_app_nontrusted1 \n");
#endif
  
  // TODO (currently not supported by Trampoline) OS027
  
  /* OS081 : execute code in common section from all OS application -> YES */
  var1_t1_app_nontrusted1 = test_common_function(var1_t1_app_nontrusted1,var2_t1_app_nontrusted1);
  /* check returned value */
#if TARGET_ARCH == ARCH_POSIX
  printf("2.t1_app_nontrusted1 - return value from test_common_function=%lu (should be 1)\n",var1_t1_app_nontrusted1);
#endif
  
  /* read/write access to peripheral by trusted OS application -> NO (OS209) */
  var1_t1_app_nontrusted1 = *RANDOM_PERIPHERAL_ADRESS;
  *RANDOM_PERIPHERAL_ADRESS = var2_t1_app_nontrusted1;
#if TARGET_ARCH == ARCH_POSIX
  printf("3.t1_app_nontrusted1 - random peripheral adress value = %lu (should be 0)\n",var1_t1_app_nontrusted1);
#endif
  
  // TODO (currently not supported by Trampoline) OS083 : read/write to their (non-trusted OS application) assigned peripherals -> YES 
  
  WaitEvent(Event1);
  
#if TARGET_ARCH == ARCH_POSIX
  printf("8.t1_app_nontrusted1 - Event received -> ShutdownOS \n");
#endif
  
  ShutdownOS(E_OK);
}
#define APP_Task_t1_app_nontrusted1_STOP_SEC_CODE
#include "tpl_memmap.h"

/**
 * t1_app_trusted1
 *
 */
#define APP_Task_t1_app_trusted1_START_SEC_CODE
#include "tpl_memmap.h"
TASK(t1_app_trusted1)
{
#if TARGET_ARCH == ARCH_POSIX
  printf("4.t1_app_trusted1 \n");
#endif
  
  /* OS081 : execute code in common section from all OS application -> YES */
  var1_t1_app_trusted1 = test_common_function(var1_t1_app_trusted1,var2_t1_app_trusted1);
  /* check returned value */
#if TARGET_ARCH == ARCH_POSIX
  printf("5.t1_app_trusted1 - return value from test_common_function=%lu (should be 1)\n",var1_t1_app_trusted1);
#endif
  
  /* OS209 : read/write access to peripheral by trusted OS application -> YES */
  var1_t1_app_trusted1 = *RANDOM_PERIPHERAL_ADRESS;
  *RANDOM_PERIPHERAL_ADRESS = var2_t1_app_trusted1;
#if TARGET_ARCH == ARCH_POSIX
  printf("6.t1_app_trusted1 - random peripheral adress value = %lu (should be 0)\n",var1_t1_app_trusted1);
#endif  
  
  SetEvent(t1_app_nontrusted1, Event1);
  
#if TARGET_ARCH == ARCH_POSIX
  printf("7.t1_app_trusted1 - Event set\n");
#endif  
  
  TerminateTask();
  
}
#define APP_Task_t1_app_trusted1_STOP_SEC_CODE
#include "tpl_memmap.h"

