/**
 * @file extint.c
 *
 * @section descr File description
 *
 * Trampoline core exported definitions
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
 * $Date:$
 * $Rev:$
 * $Author:$
 * $URL:$
 */

#include "extint.h"

void InitExtInt(void)
{
  InitEInt0();
  InitEInt2();
}

void InitEInt0(void)
{
  PINSEL1 = (PINSEL1 & ~(0x00000003)) | (0x00000001);

  /* Enable external internupt (EINT0 |= 1 ; EINT1 |= 2 ; EINT2 |= 4 ; EINT3 |= 8) to wake up the ARM from power down mode */ 
  //EXTWAKE |= 0x1;
  
  /* Level (0) or edge (1) sensitive mode */
  EXTMODE |= (0x00000001);
  /* Which pin will cause an interrupt (low-falling=0 high-rising=1) */ 
  EXTPOLAR |= (0x00000001);
  /* Reset interrupt flags after changing mode (EINT0=1 ; EINT1=2 ; EINT2=4 ; EINT3=8) */
  EXTINT |= (0x00000001);
  
  //--- 6. Use vector 14 for EINT0 interrupt
  VICVectAddr7 = (unsigned long) EINT0InterruptServiceRoutine ;
  VICVectCntl7 = 0x20 | 14;
  
  /* -------------------------------------
   * BE CAREFUL : 
   * 0x20 above is to enable the interrupt
   * and 14 is the 0x4000 for the EINT0
   * interrrupt as you can see it again as
   * below
   * ------------------------------------*/
  
  //--- 7. Use IRQ for receiving characters
  VICIntEnClr  = 0x4000 ; // EINT0 interrupt generates IRQ
  VICIntEnable |= 0x4000 ; // Enable  EINT0 interrupt

}

void EINT0InterruptServiceRoutine(void)
{
  /* Reset interrupt flags after receiving interrupt */
  EXTINT |= (0x00000001);  
}

void InitEInt2(void)
{
  
  PINSEL0 = (PINSEL0 & ~(0xc0000000)) | (0x80000000);
  
  /* Enable external internupt (EINT0 |= 1 ; EINT1 |= 2 ; EINT2 |= 4 ; EINT3 |= 8) to wake up the ARM from power down mode */ 
  //EXTWAKE |= 0x1;
  
  /* Level (0) or edge (1) sensitive mode */
  EXTMODE |= (0x00000004);
  /* Which pin will cause an interrupt (low-falling=0 high-rising=1) */ 
  EXTPOLAR |= (0x00000004);
  /* Reset interrupt flags after changing mode (EINT0=1 ; EINT1=2 ; EINT2=4 ; EINT3=8) */
  EXTINT |= (0x00000004);
  
  //--- 6. Use vector 15 for EINT2 interrupt
  VICVectAddr8 = (unsigned long) EINT2InterruptServiceRoutine ;
  VICVectCntl8 = 0x20 | 16;
  
  /* -------------------------------------
   * BE CAREFUL : 
   * 0x20 above is to enable the interrupt
   * and 16 is the 0x10000 for the EINT2
   * interrrupt as you can see it again as
   * below
   * ------------------------------------*/
  
  //--- 7. Use IRQ for receiving characters
  VICIntEnClr  = 0x10000 ; // EINT2 interrupt generates IRQ
  VICIntEnable |= 0x10000 ; // Enable  EINT2 interrupt  
}

void EINT2InterruptServiceRoutine(void)
{
  /* Reset interrupt flags after receiving interrupt */
  EXTINT |= (0x00000004);  
}

/* End of file extint.c */
