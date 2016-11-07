/**
 * @file autosar_mp_s3/autosar_mp_s3.c
 *
 * @section desc File description
 *
 * @section copyright Copyright
 *
 * Trampoline Test Suite
 *
 * Trampoline Test Suite is copyright (c) IRCCyN 2005-2007
 * Trampoline Test Suite is protected by the French intellectual property law.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2
 * of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#include "Os.h"
#include "tpl_app_define.h"

#if TARGET_ARCH == ARCH_POSIX
#include <stdio.h>
#endif

#if TARGET_ARCH == ARCH_ARM
  #define RANDOM_STACK_ADRESS irq_stack_bottom
#elif TARGET_ARCH == ARCH_PPC
  #define RANDOM_STACK_ADRESS tpl_kernel_stack
#elif TARGET_ARCH == ARCH_POSIX
  #define OS_START_SEC_VAR_32BIT
  #include "tpl_memmap.h"
  VAR(u32, OS_CODE) var_to_test_stack_adress = 0;
  #define OS_STOP_SEC_VAR_32BIT
  #include "tpl_memmap.h"
  #define RANDOM_STACK_ADRESS var_to_test_stack_adress
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
extern VAR(tpl_stack_word, OS_APPL_DATA) t1_app_nontrusted1_stack_zone[500/sizeof(tpl_stack_word)];
extern VAR(tpl_stack_word, OS_APPL_DATA) t2_app_nontrusted1_stack_zone[500/sizeof(tpl_stack_word)];
extern VAR(tpl_stack_word, OS_APPL_DATA) t1_app_nontrusted2_stack_zone[500/sizeof(tpl_stack_word)];
extern VAR(tpl_stack_word, OS_APPL_DATA) t1_app_trusted1_stack_zone[500/sizeof(tpl_stack_word)];
extern VAR(tpl_stack_word, OS_APPL_DATA) t2_app_trusted1_stack_zone[500/sizeof(tpl_stack_word)];
extern VAR(tpl_stack_word, OS_APPL_DATA) t1_app_trusted2_stack_zone[500/sizeof(tpl_stack_word)];
#if TARGET_ARCH == ARCH_ARM
  extern VAR(u32, OS_VAR) irq_stack_bottom;
#elif TARGET_ARCH == ARCH_PPC
  extern VAR(u32, OS_VAR) tpl_kernel_stack;
#endif
/**
 * Vars
 *
 */
#define APP_Task_t1_app_nontrusted1_START_SEC_VAR_32BIT
#include "tpl_memmap.h"
VAR(u32, OS_APPL_DATA) var_t1_app_nontrusted1 = 0;
#define APP_Task_t1_app_nontrusted1_STOP_SEC_VAR_32BIT
#include "tpl_memmap.h"

#define APP_Task_t1_app_trusted1_START_SEC_VAR_32BIT
#include "tpl_memmap.h"
VAR(u32, OS_APPL_DATA) var_t1_app_trusted1 = 0;
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
  
  /* OS196 : read/write own Task/OsIsr's private stack -> YES
   - read
   - write   
   */
  DisableAllInterrupts();
  var_t1_app_nontrusted1 = t1_app_nontrusted1_stack_zone[1];
  t1_app_nontrusted1_stack_zone[1] = var_t1_app_nontrusted1;
  EnableAllInterrupts();
  
  /* OS208-OS355 : (read/)write other Task/OsIsr stack from non-trusted OS application -> NO
   - non-trusted (same) - read
   - non-trusted (same) - write
   - non-trusted - read
   - non-trusted - write
   - trusted - read
   - trusted - write
   */
  var_t1_app_nontrusted1 = t2_app_nontrusted1_stack_zone[1];
  /* TODO : CALL PROTECTION_HOOK */
  t2_app_nontrusted1_stack_zone[1] = var_t1_app_nontrusted1;
  /* TODO : CALL PROTECTION_HOOK */
  
  var_t1_app_nontrusted1 = t1_app_nontrusted2_stack_zone[1];
  /* TODO : CALL PROTECTION_HOOK */
  t1_app_nontrusted2_stack_zone[1] = var_t1_app_nontrusted1;
  /* TODO : CALL PROTECTION_HOOK */
  
  var_t1_app_nontrusted1 = t1_app_trusted1_stack_zone[1];
  /* TODO : CALL PROTECTION_HOOK */
  t1_app_trusted1_stack_zone[1] = var_t1_app_nontrusted1;
  /* TODO : CALL PROTECTION_HOOK */
    
  /* OS198 : (read/)write OS's stack section from non-trusted OS application -> NO (!! This test is specific dependant)
   - read
   - write   
   */
  var_t1_app_nontrusted1 = RANDOM_STACK_ADRESS;
  /* TODO : CALL PROTECTION_HOOK */
  RANDOM_STACK_ADRESS = var_t1_app_nontrusted1;
  /* TODO : CALL PROTECTION_HOOK */

  
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

  /* OS196 : read/write own Task/OsIsr's private stack -> YES
   - read
   - write   
   */
  DisableAllInterrupts();
  var_t1_app_trusted1 = t1_app_trusted1_stack_zone[1];
  t1_app_trusted1_stack_zone[1] = var_t1_app_nontrusted1;
  EnableAllInterrupts();
  
  /* (read/)write other Task/OsIsr stack from non-trusted OS application -> YES (OS208-OS355)
   - trusted (same) - read
   - trusted (same) - write
   - trusted - read
   - trusted - write
   - non-trusted - read
   - non-trusted - write
   */
  DisableAllInterrupts();
  var_t1_app_trusted1 = t2_app_trusted1_stack_zone[1];
  t2_app_trusted1_stack_zone[1] = var_t1_app_trusted1;
  
  var_t1_app_trusted1 = t1_app_trusted2_stack_zone[1];
  t1_app_trusted2_stack_zone[1] = var_t1_app_trusted1;
  
  var_t1_app_trusted1 = t1_app_nontrusted1_stack_zone[1];
  t1_app_nontrusted1_stack_zone[1] = var_t1_app_trusted1;
  EnableAllInterrupts();
  
  /* (read/)write OS's stack section from non-trusted OS application -> YES (OS198) (!! This test is specific dependant)
   - read
   - write   
   */
  DisableAllInterrupts();
  var_t1_app_trusted1 = RANDOM_STACK_ADRESS;
  RANDOM_STACK_ADRESS = var_t1_app_trusted1;
  EnableAllInterrupts();

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
  
}
#define APP_Task_t1_app_trusted2_STOP_SEC_CODE
#include "tpl_memmap.h"

/* End of file autosar_mp_s3/autosar_mp_s3.c */
