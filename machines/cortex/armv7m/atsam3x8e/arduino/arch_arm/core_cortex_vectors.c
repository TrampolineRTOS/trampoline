/*
  Copyright (c) 2015 Thibaut VIARD.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifdef __cplusplus
extern "C" {
#endif

#define __SAM3X8E__
#include "sam.h"
#include "core_hooks.h"
#include "core_cortex_vectors.h"
#include "core_variant.h"
#include "core_delay.h"           // for SysTick_DefaultHandler()
#include <stdint.h>

/* Symbols exported from linker script */
extern uint32_t __etext ;
extern uint32_t __data_start__ ;
extern uint32_t __data_end__ ;
extern uint32_t __bss_start__ ;
extern uint32_t __bss_end__ ;
extern uint32_t __StackTop;

extern int main( void ) ;
/* symbols from libc */
extern void __libc_init_array(void);

void vector_halt(void)
{
  // Halts
  __BKPT(0);
  while (1);
}

/**
 * \brief This is the code that gets called on processor reset.
 * Initializes the device and call the main() routine.
 */
// void Reset_Handler( void )
// {
//   uint32_t *pSrc, *pDest;
//
//   /* Initialize the initialized data section */
//   pSrc = &__etext;
//   pDest = &__data_start__;
//
//   if ( (&__data_start__ != &__data_end__) && (pSrc != pDest) )
//   {
//     for (; pDest < &__data_end__ ; pDest++, pSrc++ )
//     {
//       *pDest = *pSrc ;
//     }
//   }
//
//   /* Clear the zero section */
//   if ( &__bss_start__ != &__bss_end__ )
//   {
//     for ( pDest = &__bss_start__ ; pDest < &__bss_end__ ; pDest++ )
//     {
//       *pDest = 0ul ;
//     }
//   }
//
//   /* exception_table being initialized, setup vectors in RAM */
//   vectorSetOrigin( &exception_table );
//
//   /* Initialize the system */
//   SystemInit() ;
//
//   /* calls _init() functions, C++ constructors included */
//   __libc_init_array();
//
//   /* Branch to main function */
//   main() ;
//
//   /* Infinite loop */
//   while ( 1 )
//   {
//   }
// }

#if defined DEBUG && (DEBUG == 1)
#warning "DEBUG handlers activated"

// void HardFault_Handler(void)
// {
//   __BKPT(13);
//   while (1);
// }
//
// void NMI_Handler(void)
// {
//   __BKPT(14);
//   while (1);
// }
//
// void MemManage_Handler(void)
// {
//   __BKPT(12);
//   while (1);
// }
//
// void BusFault_Handler(void)
// {
//   __BKPT(11);
//   while (1);
// }
//
void UsageFault_Handler(void)
{
  __BKPT(10);
  while (1);
}
//
// void DebugMon_Handler(void)
// {
//   __BKPT(4);
//   while (1);
// }

#else

// void HardFault_Handler (void) __attribute__ ((weak, alias("vector_halt")));
// void NMI_Handler       (void) __attribute__ ((weak, alias("vector_halt")));
// void MemManage_Handler (void) __attribute__ ((weak, alias("vector_halt")));
// void BusFault_Handler  (void) __attribute__ ((weak, alias("vector_halt")));
void UsageFault_Handler(void) __attribute__ ((weak, alias("vector_halt")));
// void DebugMon_Handler  (void) __attribute__ ((weak, alias("vector_halt")));

#endif // DEBUG=1

// void SVC_Handler(void)
// {
//   svcHook();
// }
//
// void PendSV_Handler(void)
// {
//   pendSVHook();
// }
//
// void SysTick_Handler(void)
// {
//   if (sysTickHook() != 0)
//   {
//     return;
//   }
//
//   SysTick_DefaultHandler();
// }

/* Exception Table */
__attribute__ ((section(".isr_vector")))
const CoreVectors startup_exception_table=
{
  /* Configure Initial Stack Pointer, using linker-generated symbols */
  .pvStack = (void*) (&__StackTop),

  // .pfnReset_Handler      = (void*) Reset_Handler,
  // .pfnNMI_Handler        = (void*) (0UL),
  // .pfnHardFault_Handler  = (void*) HardFault_Handler,
  // .pfnMemManage_Handler  = (void*) MemManage_Handler,
  // .pfnBusFault_Handler   = (void*) BusFault_Handler,
  .pfnUsageFault_Handler = (void*) UsageFault_Handler,
  .pfnReserved1_Handler  = (void*) (0UL),          /* Reserved */
  .pfnReserved2_Handler  = (void*) (0UL),          /* Reserved */
  .pfnReserved3_Handler  = (void*) (0UL),          /* Reserved */
  .pfnReserved4_Handler  = (void*) (0UL),          /* Reserved */
  // .pfnSVC_Handler        = (void*) (0UL),
  // .pfnDebugMon_Handler   = (void*) (0UL),
  .pfnReserved5_Handler  = (void*) (0UL),          /* Reserved */
  // .pfnPendSV_Handler     = (void*) (0UL),
  // .pfnSysTick_Handler    = (void*) (0UL),
 };

void* vectorSetOrigin(DeviceVectors* pBase)
{
  void* p=(void*)(SCB->VTOR);

  /* relocate vector table */
  __disable_irq();
  SCB->VTOR = ((uint32_t)pBase)&SCB_VTOR_TBLOFF_Msk;
  __DSB();
  __enable_irq();

  return p;
}

void* vectorAssign(IRQn_Type number, void (*isr)(void))
{
  uint32_t* pulTable=(uint32_t*)(SCB->VTOR);
  void *p=(void*)(pulTable+number+16);

  __disable_irq();
  pulTable[number+16]=(uint32_t)isr ;
  __DSB();
  __enable_irq();

  return p;
}

void* vectorReset(IRQn_Type number)
{
  uint32_t* pulTable=(uint32_t*)(SCB->VTOR);
  void *p=(void*)(pulTable+number+16);

  __disable_irq();
  pulTable[number+16]=(uint32_t)vector_halt ;
  __DSB();
  __enable_irq();

  return p;
}

#ifdef __cplusplus
}
#endif
