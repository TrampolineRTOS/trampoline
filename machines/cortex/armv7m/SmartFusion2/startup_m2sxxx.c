#include <sys/types.h>

void __attribute__((weak)) tpl_continue_reset_handler(void);

// The CMSIS system initialisation routine.
extern void SystemInit(void);

//required by the debugger on softConsole IDE (smartFusion2)
extern int __smartfusion2_memory_remap;
extern int __mirrored_nvm;

// Initialise the data section
inline void data_init(unsigned int* from, unsigned int* section_begin, unsigned int* section_end);

// Begin address for the initialisation values of the .data section.
// defined in linker script
extern unsigned int _sidata;
// Begin address for the .data section; defined in linker script
extern unsigned int _sdata;
// End address for the .data section; defined in linker script
extern unsigned int _edata;

// Clear the bss section
inline void bss_init(unsigned int* section_begin, unsigned int* section_end);

// Begin address for the .bss section; defined in linker script
extern unsigned int __bss_start__;
// End address for the .bss section; defined in linker script
extern unsigned int __bss_end__;

// Iterate over all the preinit/init routines.
extern void __libc_init_array(void);

// Run all the cleanup routines.
extern void __libc_fini_array(void);

// The entry point for the application.
// main() is the entry point for Newlib based applications
extern int main(void);

// The implementation for the exit routine, where for embedded
// applications, a system reset is performed.
extern void _exit(int);

//*****************************************************************************

inline void
__attribute__((always_inline)) data_init(unsigned int* from, unsigned int* section_begin,
    unsigned int* section_end)
{
  // Iterate and copy word by word.
  // It is assumed that the pointers are word aligned.
  unsigned int *p = section_begin;
  while (p < section_end)
    *p++ = *from++;
}

inline void __attribute__((always_inline))
bss_init(unsigned int* section_begin, unsigned int* section_end)
{
  // Iterate and clear word by word.
  // It is assumed that the pointers are word aligned.
  unsigned int *p = section_begin;
  while (p < section_end)
    *p++ = 0;
}

// These magic symbols are provided by the linker.
extern void (*__preinit_array_start[])(void) __attribute__((weak));
extern void (*__preinit_array_end[])(void) __attribute__((weak));
extern void (*__init_array_start[])(void) __attribute__((weak));
extern void (*__init_array_end[])(void) __attribute__((weak));
extern void (*__fini_array_start[])(void) __attribute__((weak));
extern void (*__fini_array_end[])(void) __attribute__((weak));

// Iterate over all the preinit/init routines.
inline void __libc_init_array(void)
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
inline void __libc_fini_array(void)
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
//void __attribute__ ((section(".after_vectors"))) 
void tpl_continue_reset_handler(void)
{
  /*
   * Initialize the stacks and mode
   */
  
   
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

// System initialisation, executed before constructors.
void __attribute__((section(".after_vectors"))) system_init()
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

//mandatory function called by CMSIS
void mscc_post_hw_cfg_init() {
	//dummy code so that the 2 required symbol are available.
	volatile int tmp = __mirrored_nvm;
	tmp = __smartfusion2_memory_remap;
}
