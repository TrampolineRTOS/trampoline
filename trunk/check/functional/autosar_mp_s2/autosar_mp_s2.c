#include "Os.h"
#include "tpl_app_define.h"

#if TARGET_ARCH == ARCH_POSIX
#include <stdio.h>
#endif

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
DeclareTask(t2_app_nontrusted1);
DeclareTask(t1_app_nontrusted2);
DeclareTask(t1_app_trusted1);
DeclareTask(t2_app_trusted1);
DeclareTask(t1_app_trusted2);

/**
 * Vars
 *
 */
#define APP_Task_t1_app_nontrusted1_START_SEC_VAR_32BIT
#include "tpl_memmap.h"
VAR(u32, OS_APPL_DATA) var_t1_app_nontrusted1 = 0;
#define APP_Task_t1_app_nontrusted1_STOP_SEC_VAR_32BIT
#include "tpl_memmap.h"
#define APP_Task_t2_app_nontrusted1_START_SEC_VAR_32BIT
#include "tpl_memmap.h"
VAR(u32, OS_APPL_DATA) var_t2_app_nontrusted1 = 0;
#define APP_Task_t2_app_nontrusted1_STOP_SEC_VAR_32BIT
#include "tpl_memmap.h"
#define APP_Task_t1_app_nontrusted2_START_SEC_VAR_32BIT
#include "tpl_memmap.h"
VAR(u32, OS_APPL_DATA) var_t1_app_nontrusted2 = 0;
#define APP_Task_t1_app_nontrusted2_STOP_SEC_VAR_32BIT
#include "tpl_memmap.h"
#define APP_Task_t1_app_trusted1_START_SEC_VAR_32BIT
#include "tpl_memmap.h"
VAR(u32, OS_APPL_DATA) var_t1_app_trusted1 = 0;
#define APP_Task_t1_app_trusted1_STOP_SEC_VAR_32BIT
#include "tpl_memmap.h"
#define APP_Task_t2_app_trusted1_START_SEC_VAR_32BIT
#include "tpl_memmap.h"
VAR(u32, OS_APPL_DATA) var_t2_app_trusted1 = 0;
#define APP_Task_t2_app_trusted1_STOP_SEC_VAR_32BIT
#include "tpl_memmap.h"
#define APP_Task_t1_app_trusted2_START_SEC_VAR_32BIT
#include "tpl_memmap.h"
VAR(u32, OS_APPL_DATA) var_t1_app_trusted2 = 0;
#define APP_Task_t1_app_trusted2_STOP_SEC_VAR_32BIT
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
  
  /* OS087 : read/write own Task/OsIsr's data section -> YES
   - read
   - write   
   */
  var_t1_app_nontrusted1++; // if just read, the linker discards the variable...
  
  /* OS195-OS356 : (read/)write other Task/OsIsr from non-trusted OS application -> NO
   - non-trusted (same) - read
   - non-trusted (same) - write
   - non-trusted - read
   - non-trusted - write
   - trusted - read
   - trusted - write
   */
  var_t1_app_nontrusted1 = var_t2_app_nontrusted1;
  // TODO : CALL PROTECTION_HOOK
  var_t2_app_nontrusted1 = var_t1_app_nontrusted1;
  // TODO : CALL PROTECTION_HOOK
  
  var_t1_app_nontrusted1 = var_t1_app_nontrusted2;
  // TODO : CALL PROTECTION_HOOK
  var_t1_app_nontrusted2 = var_t1_app_nontrusted1;
  // TODO : CALL PROTECTION_HOOK
  
  var_t1_app_nontrusted1 = var_t1_app_trusted1;
  // TODO : CALL PROTECTION_HOOK
  var_t1_app_trusted1 = var_t1_app_nontrusted1;
  // TODO : CALL PROTECTION_HOOK
    
  WaitEvent(Event1);
  
#if TARGET_ARCH == ARCH_POSIX
  printf("4.t1_app_nontrusted1 - Event received -> ShutdownOS \n");
#endif
  
  ShutdownOS(E_OK);
}
#define APP_Task_t1_app_nontrusted1_STOP_SEC_CODE
#include "tpl_memmap.h"

/**
 * t2_app_nontrusted1
 *
 */
#define APP_Task_t2_app_nontrusted1_START_SEC_CODE
#include "tpl_memmap.h"
TASK(t2_app_nontrusted1)
{
  /* We shouldn't be here but it's just to force the variable to be in the mapping */
  var_t2_app_nontrusted1++;
  
}
#define APP_Task_t2_app_nontrusted1_STOP_SEC_CODE
#include "tpl_memmap.h"

/**
 * t1_app_nontrusted2
 *
 */
#define APP_Task_t1_app_nontrusted2_START_SEC_CODE
#include "tpl_memmap.h"
TASK(t1_app_nontrusted2)
{
  /* We shouldn't be here but it's just to force the variable to be in the mapping */
  var_t1_app_nontrusted2++; 
  
}
#define APP_Task_t1_app_nontrusted2_STOP_SEC_CODE
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
  printf("2.t1_app_trusted1 \n");
#endif
  /* OS087 : read/write own Task/OsIsr's data section -> YES
   - read
   - write   
   */
  var_t1_app_trusted1++; // if just read, the linker discards the variable...
  
  /* (read/)write other Task/OsIsr from trusted OS application -> YES (OS195-OS356)
   - trusted (same) - read
   - trusted (same) - write
   - trusted - read
   - trusted - write
   - non-trusted - read
   - non-trusted - write
   */
  var_t1_app_trusted1 = var_t2_app_trusted1;
  var_t2_app_trusted1 = var_t1_app_trusted1;
  
  var_t1_app_trusted1 = var_t1_app_trusted2;
  var_t1_app_trusted2 = var_t1_app_trusted1;
  
  var_t1_app_trusted1 = var_t1_app_nontrusted1;
  var_t1_app_nontrusted1 = var_t1_app_trusted1;
  
  SetEvent(t1_app_nontrusted1, Event1);
  
#if TARGET_ARCH == ARCH_POSIX
  printf("3.t1_app_trusted1 - Event set\n");
#endif  
  
  TerminateTask();
  
}
#define APP_Task_t1_app_trusted1_STOP_SEC_CODE
#include "tpl_memmap.h"

/**
 * t2_app_trusted1
 *
 */
#define APP_Task_t2_app_trusted1_START_SEC_CODE
#include "tpl_memmap.h"
TASK(t2_app_trusted1)
{
  /* We shouldn't be here but it's just to force the variable to be in the mapping */
  var_t2_app_trusted1++;
  
}
#define APP_Task_t2_app_trusted1_STOP_SEC_CODE
#include "tpl_memmap.h"

/**
 * t1_app_trusted2
 *
 */
#define APP_Task_t1_app_trusted2_START_SEC_CODE
#include "tpl_memmap.h"
TASK(t1_app_trusted2)
{
  /* We shouldn't be here but it's just to force the variable to be in the mapping */
  var_t1_app_trusted2++; 
  
}
#define APP_Task_t1_app_trusted2_STOP_SEC_CODE
#include "tpl_memmap.h"
