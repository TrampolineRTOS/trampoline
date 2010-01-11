/**
 * @file simtec_bootstrap_stage2.c
 *
 * @section descr File description
 *
 * Second part of the bootstrap for SIMTEC
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
#include "tpl_machine.h"
#include "simtec_driver_adapter.h"

/* TODO: use MemMap.h */

/* These external variables represent symbols defined in
 * ldscript file. They are used to know where each section
 * has been located */
extern u16 debut_bss;
extern u16 fin_bss;
extern u16 debut_rom;
extern u16 fin_rom;
extern u16 debut_data;
extern u16 fin_data;

extern int main ();

/* this function should not return as
 * it is called straight after reset
 */
void tpl_arm_bootstrap_stage2 ()
{
  simtec_memory_setup_defaults ();

  /*
   * initialіze memory segments
   */
  /* BSS section should be zeroed */
  u16 *ptr_bss = &debut_bss;
  while((int)ptr_bss < (int)&fin_bss)
    *ptr_bss ++ = 0;

  /* DATA section initial values copied from ROM */
  u16 *data_src, *data_dst;
  data_src = &fin_rom;
  data_dst = &debut_data;
  while (data_dst != &fin_data)
    *data_dst++ = *data_src++;

  /*
   * start application (which may start Trampoline via StartOS)
   */
  main ();

  /* ends in a loop, as we should not return from "reset call" */
  while (1);
}
