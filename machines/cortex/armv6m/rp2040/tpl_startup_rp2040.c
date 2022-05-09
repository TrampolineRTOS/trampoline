#include <sys/types.h>
#include "pico.h"
#include "hardware/structs/resets.h"
#include "hardware/clocks.h" //MHZ

void __attribute__((weak)) tpl_continue_reset_handler(void);

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

// The entry point for the application.
// main() is the entry point for Newlib based applications
extern int main(void);

// The implementation for the exit routine, where for embedded
// applications, a system reset is performed.
extern void _exit(int);

// clock configuration (tpl_clock_rp2040.c)
extern void clocks_init(void);

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
void system_init();

/* TODO: should be replaced by the SDK version.*/
void tpl_clocks_init(void);
#include "hardware/structs/iobank0.h"
#include "hardware/structs/sio.h"
#define LED_BUILTIN 25

//CMSIS compatibility
//you may use clock_get_hz() form rp2_common/hardware_clocks/clocks.c
uint32_t SystemCoreClock = 125 * MHZ;

/*
 * on rp2040, the boot needs many stages:
 * - first boot stage: 256 bytes from boot2_w25q080_2_padded_checksum.s
 *   init the QSPI to use the external flash
 * - second boot stage: crt0.S
 *   load the interrupt vector and call the reset interrupt
 * - third stage boot: tpl_startup.S (common to each cortex)
 * - fourth stage boot: here
 *   init the clocks, data init, bss and call the main()
 */
void __attribute__ ((section(".osCode"))) 
tpl_continue_reset_handler(void)
{
  //tmp
  sio_hw->gpio_oe_set = 1ul << LED_BUILTIN; // enable output
  sio_hw->gpio_clr = 1ul << LED_BUILTIN;    // clear
  iobank0_hw->io[LED_BUILTIN].ctrl = 5; //5 is alternate function for SIO
  sio_hw->gpio_togl = 1ul << LED_BUILTIN;

  size_t count;
  size_t i;
  // Reset all peripherals to put system into a known state,
  // - except for QSPI pads and the XIP IO bank, as this is fatal if running from flash
  // - and the PLLs, as this is fatal if clock muxing has not been reset on this boot
  const uint32_t peripheralsNotResetted =
    RESETS_RESET_IO_QSPI_BITS |
    RESETS_RESET_PADS_QSPI_BITS |
    RESETS_RESET_PLL_USB_BITS |
    RESETS_RESET_PLL_SYS_BITS
  ;
  resets_hw->reset |= ~ peripheralsNotResetted ;

  // Remove reset from peripherals which are clocked only by clk_sys and
  // clk_ref. Other peripherals stay in reset until we've configured clocks.
  const uint32_t otherPeripherals =
     RESETS_RESET_ADC_BITS |
     RESETS_RESET_RTC_BITS |
     RESETS_RESET_SPI0_BITS |
     RESETS_RESET_SPI1_BITS |
     RESETS_RESET_UART0_BITS |
     RESETS_RESET_UART1_BITS |
     RESETS_RESET_USBCTRL_BITS;
  const uint32_t reset = RESETS_RESET_BITS & ~ otherPeripherals ;
  resets_hw->reset &= ~reset ;
  //--- Wait for reset done
  while ((reset & ~resets_hw->reset_done) != 0) {}
  /*
   * Initialize the stacks and mode
   */
  
   
  // Use Old Style Data and BSS section initialisation,
  // That will initialise a single BSS sections.

  // Zero fill the bss segment
  bss_init(&__bss_start__, &__bss_end__);

  data_init(&_sidata, &_sdata, &_edata);
  // pre-init runs really early since we need it even for memcpy and divide!
  // (basically anything in aeabi that uses bootrom)
  count = __preinit_array_end - __preinit_array_start;
  for (i = 0; i < count; i++)
    __preinit_array_start[i]();

  // After calling preinit we have enough runtime to do the exciting maths
  // in clocks_init
  tpl_clocks_init();

  // Peripheral clocks should now all be running
  resets_hw->reset |= otherPeripherals ;
  resets_hw->reset &= ~ otherPeripherals ;
  while ((otherPeripherals & ~resets_hw->reset_done) != 0) {}

  // Start and end points of the constructor list,
  // defined by the linker script.
  count = __init_array_end - __init_array_start;
  for (i = 0; i < count; i++)
    __init_array_start[i]();
  // Call the main entry point, and save the exit code.
  int r = main();

  // Run the static destructors.
  count = __fini_array_end - __fini_array_start;
  for (i = count; i > 0; i--)
    __fini_array_start[i - 1]();

  // On test platforms, like semihosting, this can be used to inform
  // the host on the test result.
  // On embedded platforms, usually reset the processor.
  _exit(r);

}

//void _exit(__attribute__((unused)) int status) {
//}
