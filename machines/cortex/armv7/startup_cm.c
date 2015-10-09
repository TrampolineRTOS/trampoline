//
// This file is part of the GNU ARM Eclipse Plug-in
// Copyright (c) 2013 Liviu Ionescu
//
// This module contains the startup code for a portable Cortex-M
// C/C++ application, built with CMSIS and newlib.
//
// The actual steps performed are:
// - clear the BSS area
// - run the preinit array, where, as the first entry, a separate routine
// is used to copy the initialised data section and to configure the
// system call via the CMSIS SystemInit()
// - run the init array (for the C++ static constructors)
// - branch to main()
// - run the fini array (for the C++ static destructors)
// - call _exit(), directly or via exit()
//
// After Reset the Cortex-M processor is in Thread mode,
// priority is Privileged, and the Stack is set to Main.
//
// The normal configuration is standalone, with all support
// functions implemented locally.
//
// If required, the standard startup files can be called to
// perform all initialisations (define USE_STARTUP_FILES).

#include <sys/types.h>

#if defined (__cplusplus)
extern "C"
  {
#endif

void __attribute__((weak))
Reset_Handler(void);

#if defined(USE_STARTUP_FILES)
extern void
_start(void);

extern int
__register_exitproc(int type, void (*fn) (void), void *arg, void *d);
#endif

// The CMSIS system initialisation routine.
extern void
SystemInit(void);

// Initialise the data section
inline void
data_init(unsigned int* from, unsigned int* section_begin,
    unsigned int* section_end);

// Begin address for the initialisation values of the .data section.
// defined in linker script
extern unsigned int _sidata;
// Begin address for the .data section; defined in linker script
extern unsigned int _sdata;
// End address for the .data section; defined in linker script
extern unsigned int _edata;

#if !defined(USE_STARTUP_FILES)

// Clear the bss section
inline void
bss_init(unsigned int* section_begin, unsigned int* section_end);

// Begin address for the .bss section; defined in linker script
extern unsigned int __bss_start__;
// End address for the .bss section; defined in linker script
extern unsigned int __bss_end__;

// Iterate over all the preinit/init routines.
extern void
__libc_init_array(void);

// Run all the cleanup routines.
extern void
__libc_fini_array(void);

// The entry point for the application.
// main() is the entry point for Newlib based applications
extern int
main(void);

// The implementation for the exit routine, where for embedded
// applications, a system reset is performed.
extern void
_exit(int);

#endif

//*****************************************************************************
#if defined (__cplusplus)
} // extern "C"
#endif

inline void
__attribute__((always_inline))
data_init(unsigned int* from, unsigned int* section_begin,
    unsigned int* section_end)
{
  // Iterate and copy word by word.
  // It is assumed that the pointers are word aligned.
  unsigned int *p = section_begin;
  while (p < section_end)
    *p++ = *from++;
}

#if !defined(USE_STARTUP_FILES)

inline void
__attribute__((always_inline))
bss_init(unsigned int* section_begin, unsigned int* section_end)
{
  // Iterate and clear word by word.
  // It is assumed that the pointers are word aligned.
  unsigned int *p = section_begin;
  while (p < section_end)
    *p++ = 0;
}

#endif

#if defined(USE_STARTUP_FILES)

// This is useful when using certain libraries that came with custom
// startup files, like librdimon.a.

// Go to the startup code, that is expected to perform the
// usual initialisations, i.e. clear the BSS, run the
// init arrays and call main().

#if defined(DEBUG)

// The DEBUG version is not naked, to allow breakpoints at Reset_Handler
void __attribute__ ((section(".after_vectors")))
Reset_Handler(void)
  {
    _start();
  }

#else

// The Release version is optimised to a quick branch to _start.
void __attribute__ ((section(".after_vectors"), naked))
Reset_Handler(void)
  {
    asm volatile
    (
        " b _start \n"
        :
        :
        :
    );
  }

#endif

#else

// These magic symbols are provided by the linker.
extern void
(*__preinit_array_start[])(void) __attribute__((weak));
extern void
(*__preinit_array_end[])(void) __attribute__((weak));
extern void
(*__init_array_start[])(void) __attribute__((weak));
extern void
(*__init_array_end[])(void) __attribute__((weak));
extern void
(*__fini_array_start[])(void) __attribute__((weak));
extern void
(*__fini_array_end[])(void) __attribute__((weak));

// Iterate over all the preinit/init routines.
inline void
__libc_init_array(void)
{
  size_t count;
  size_t i;

  count = __preinit_array_end - __preinit_array_start;
  for (i = 0; i < count; i++)
    __preinit_array_start[i]();

  // If you need to run the code in the .init section, please use
  // the startup files, since this requires the code in crti.o and crtn.o
  // to add the function prologue/epilogue.
  //_init();

  count = __init_array_end - __init_array_start;
  for (i = 0; i < count; i++)
    __init_array_start[i]();
}

// Run all the cleanup routines.
inline void
__libc_fini_array(void)
{
  size_t count;
  size_t i;

  count = __fini_array_end - __fini_array_start;
  for (i = count; i > 0; i--)
    __fini_array_start[i - 1]();

  // If you need to run the code in the .fini section, please use
  // the startup files, since this requires the code in crti.o and crtn.o
  // to add the function prologue/epilogue.
  //_fini();
}

// This is the place where Cortex-M core will go immediately after reset.
void __attribute__ ((section(".after_vectors")))
Reset_Handler(void)
{

  // Use Old Style Data and BSS section initialisation,
  // That will initialise a single BSS sections.

  // Zero fill the bss segment
  bss_init(&__bss_start__, &__bss_end__);

  // Call the standard library initialisation (mandatory, SystemInit()
  // and C++ static constructors are called from here).
  __libc_init_array();

  // Call the main entry point, and save the exit code.
  int r = main();

  // Run the static destructors.
  __libc_fini_array();

  // On test platforms, like semihosting, this can be used to inform
  // the host on the test result.
  // On embedded platforms, usually reset the processor.
  _exit(r);

}

#endif

// System initialisation, executed before constructors.
void
__attribute__((section(".after_vectors")))
system_init()
{
  // Copy the data segment from Flash to RAM.
  // This is here since some library crt0 code does not perform it there
  // so we must be sure it is executed somewhere.
  // (for example librdimon)
  data_init(&_sidata, &_sdata, &_edata);

  // Call the CSMSIS system initialisation routine
  SystemInit();
}

// The .preinit_array_sysinit section is defined in sections.ld as the first
// sub-section in the .preinit_array, so it is guaranteed that this function
// is executed before all other initialisations.
void* __attribute__((section(".preinit_array_sysinit")))
p_system_init = (void*) system_init; // pointer to the above function

#if defined(USE_STARTUP_FILES)

// This function is required since the one included in newlib seems buggy
// and the startup files crash when using the semihosting configuration.
// The problem requires further investigations, but in the meantime
// considering that embedded applications rarely return from main,
// it is patched to return -1.

int
__register_exitproc(int type, void (*fn) (void), void *arg, void *d)
{
  return -1;
}

#endif
