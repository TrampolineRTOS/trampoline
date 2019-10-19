
#include "tpl_clocks.h"
#include <msp430.h>
#include <stdint.h>

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/*
 * We configure here the DCO as input clock for the MCU (MCLK)
 * Wait states are required
 */
FUNC(void,OS_CODE) tpl_set_mcu_clock(uint16_t freq)
{
  CSCTL0 = CSKEY;                     /* Get access to CSCTLx regs.           */

  CSCTL2 &= ~SELM_7;                  /* Set DCO as MCLK (clear field..       */
  CSCTL2 |= SELM__DCOCLK;             /* .. and set correct DCO value)        */

  CSCTL3 &= ~(DIVM0 | DIVM1 | DIVM2); /*  clear DIVM Field (source divider)   */
  /*
   * Wait states for the FRAM are required above 8 MHz (1), and 16 MHz (2):
	 * When we change the clock settings, we must be sure that the wait states
   * are:
   * - set before increasing the clock speed
   * - removed after decreasing the clock speed
   * We set the wait states to 2 cycles here, and we adapt after for
   * low frequencies.
   */
  FRCTL0 = FWPW | NACCESS_2;          /* add 2 waitstaites -> up to 24MHz ok. */

  switch(freq) {
    case 1:
      CSCTL1 = DCOFSEL_0;             /* 1 MHz                                */
      FRCTL0 = FWPW | NACCESS_0;      /* no wait state required               */
      break;
    case 2:
      CSCTL1 = DCOFSEL_3;             /* 4 MHz                                */
      CSCTL3 |= DIVM__2;              /* divide by 2.                         */
      FRCTL0 = FWPW | NACCESS_0;      /* no wait state required               */
      break;
    case 4:
      CSCTL1 = DCOFSEL_3;             /* 4 MHz                                */
      FRCTL0 = FWPW | NACCESS_0;      /* no wait state required               */
      break;
    case 6:
      CSCTL1 = DCOFSEL_6 | DCORSEL;   /* 24 MHz                               */
      CSCTL3 |= DIVM__4;              /* divide by 4                          */
      FRCTL0 = FWPW | NACCESS_0;      /* no wait state required               */
      break;
    case 8:
      CSCTL1 = DCOFSEL_6 ;            /* 8MHz                                 */
      FRCTL0 = FWPW | NACCESS_0;      /* no wait state required               */
      break;
    case 12:
      CSCTL1 = DCOFSEL_6 | DCORSEL;   /* 24 MHz                               */
      CSCTL3 |= DIVM__2;              /* divide by 2.                         */
      FRCTL0 = FWPW | NACCESS_1;      /* add 1 waitstaite                     */
      break;
    case 16:
      CSCTL1 = DCOFSEL_4 | DCORSEL;   /* 16 MHz                               */
      FRCTL0 = FWPW | NACCESS_1;      /* add 1 waitstaite                     */
      break;
    case 21:
      CSCTL1 = DCOFSEL_5 | DCORSEL;   /* 21 MHz                               */
      FRCTL0 = FWPW | NACCESS_1;      /* add 1 waitstaite                     */
      break;
    case 24:
      CSCTL1 = DCOFSEL_6 | DCORSEL;   /* 24 MHz                               */
      FRCTL0 = FWPW | NACCESS_2;      /* add 2 waitstaites                    */
      break;
    default:                          /* all other cases: choose 8MHz         */
      CSCTL1 = DCOFSEL_6 ;            /* 8MHz                                 */
      FRCTL0 = FWPW | NACCESS_0;      /* no wait state required               */
      break;
	}
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"
