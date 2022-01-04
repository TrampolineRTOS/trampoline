#if WITH_CHECKPOINTING == YES

#include "tpl_os.h"
#include "msp430.h"

#define APP_COMMON_START_SEC_CODE
#include "tpl_memmap.h"

FUNC(void, OS_CODE) tpl_init_io_for_reset_handler(void)
{
  /*
   * Disable the GPIO power-on default high-impedance mode
   * to activate previously configured port settings
   */
  PM5CTL0 &= ~LOCKLPM5;
  /* set GPIO P5.6 (button S1) as an input, with internal pull-up */
  P5DIR &= ~(1<<6); /* input                        */
  P5REN |= 1<<6;    /* pull-up/down resistor enable */
  P5OUT |= 1<<6;    /* pull-up                      */
}

FUNC(int, OS_CODE) tpl_cold_startup(void)
{
  return (((P5IN >> 6) & 1) == 0); //button pushed during startup ?
}

#define APP_COMMON_STOP_SEC_CODE
#include "tpl_memmap.h"
#endif //WITH_CHECKPOINTING
