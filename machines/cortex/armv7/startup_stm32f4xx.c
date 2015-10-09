//
// This file is part of the GNU ARM Eclipse Plug-in
// Copyright (c) 2013 Liviu Ionescu
//

#include "stm32f4xx.h"

#if defined (__VFP_FP__) && !defined (__SOFTFP__)

void
__attribute__((section(".after_vectors")))
fpu_init()
  {
    // Code to enable the Cortex-M4 FPU only included
    // if appropriate build options have been selected.
    // Code taken from Section 7.1, Cortex-M4 TRM (DDI0439C)
    asm volatile
    (
        " LDR.W           R0, =0xE000ED88 \n" // CPACR is located at address 0xE000ED88
        " LDR             R1, [R0] \n"// Read CPACR
        " ORR             R1, R1, #(0xF << 20) \n"// Set bits 20-23 to enable CP10 and CP11 coprocessor
        " STR             R1, [R0]"// Write back the modified value to the CPACR
        : /* out */
        : /* in */
        : /* clobber */
    );
  }

// The .preinit_array_platform section is defined in sections.ld as the second
// sub-section in the .preinit_array, so it is guaranteed that this function
// is executed after SystemInit and before all other initialisations.
void*
__attribute__((section(".preinit_array_platform")))
p_fpu_init = (void*)fpu_init;
#endif // (__VFP_FP__) && !(__SOFTFP__)

// Usually main() doesn't return, but if it does, on debug
// we'll just enter an infinite loop, while on Release we restart.
// You can redefine it in the application, if more functionality
// is required
void
__attribute__((weak))
_exit(int r)
{
#if defined(DEBUG)
  while(1)
  ;
#else
  NVIC_SystemReset();
  while (1)
    ;
#endif
}

