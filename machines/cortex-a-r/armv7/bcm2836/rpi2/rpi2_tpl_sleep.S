/**
 * @file olimex_tpl_sleep.S
 *
 * @section descr File description
 *
 * Implementation of tpl_sleep function, called by idle task
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Copyright ESEO for function and data structures documentation and ARM port
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#define OS_START_SEC_CODE
#include "tpl_as_memmap.h"

/* We want tpl_sleep not to use stack. Writing in assembler make us able to
 * prevent this. */
.global tpl_sleep
tpl_sleep:
#ifdef DISABLED_FOR_DEBUG_FACILITY /* as the JTAG probe hangs down too */
  /*
   * halts OKI CPU
   */
  #ldr r0, =0xB8000004
  #mov r1, #0x3C
  #mov r2, #4
  #str r1, [r0]
  #str r2, [r0]
#endif
  /* falls into infinite loop */ 
  b .

#define OS_STOP_SEC_CODE
#include "tpl_as_memmap.h"

#define OS_START_LTORG
#include "tpl_as_memmap.h"
#define OS_STOP_LTORG
#include "tpl_as_memmap.h"

/* End of file olimex_tpl_sleep.S */
