
#include "tpl_clocks.h"
#include <msp430.h>
#include <stdint.h>

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

/*
 * msp430-gcc 4.6.3 from Energia 1.8.7E21 define both NWAITS_x and NACCESS_x
 * msp430-gcc 4.7.0 installed by Howebrew have older version of the headers and
 *                  does not define NWAITS_x
 * In addition the header for MSP430FR5994 does not define NACCESS_x.
 * Thanks TI for this mess !
 * So the following fix it.
 */
#if !(defined NWAITS_0) && defined NACCESS_0
#define NWAITS_0 NACCESS_0
#endif
#if !(defined NWAITS_1) && defined NACCESS_1
#define NWAITS_1 NACCESS_1
#endif
#if !(defined NWAITS_2) && defined NACCESS_2
#define NWAITS_2 NACCESS_2
#endif

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
  FRCTL0 = FWPW | NWAITS_2;           /* add 2 waitstaites -> up to 24MHz ok. */

  switch(freq) {
    case 1:
      CSCTL1 = DCOFSEL_0;             /* 1 MHz                                */
      FRCTL0 = FWPW | NWAITS_0;       /* no wait state required               */
      break;
    case 2:
      CSCTL1 = DCOFSEL_3;             /* 4 MHz                                */
      CSCTL3 |= DIVM__2;              /* divide by 2.                         */
      FRCTL0 = FWPW | NWAITS_0;       /* no wait state required               */
      break;
    case 4:
      CSCTL1 = DCOFSEL_3;             /* 4 MHz                                */
      FRCTL0 = FWPW | NWAITS_0;       /* no wait state required               */
      break;
    case 6:
      CSCTL1 = DCOFSEL_6 | DCORSEL;   /* 24 MHz                               */
      CSCTL3 |= DIVM__4;              /* divide by 4                          */
      FRCTL0 = FWPW | NWAITS_0;       /* no wait state required               */
      break;
    case 8:
      CSCTL1 = DCOFSEL_6 ;            /* 8MHz                                 */
      FRCTL0 = FWPW | NWAITS_0;       /* no wait state required               */
      break;
    case 12:
      CSCTL1 = DCOFSEL_6 | DCORSEL;   /* 24 MHz                               */
      CSCTL3 |= DIVM__2;              /* divide by 2.                         */
      FRCTL0 = FWPW | NWAITS_1;       /* add 1 waitstaite                     */
      break;
    case 16:
      CSCTL1 = DCOFSEL_4 | DCORSEL;   /* 16 MHz                               */
      FRCTL0 = FWPW | NWAITS_1;       /* add 1 waitstaite                     */
      break;
    case 21:
      CSCTL1 = DCOFSEL_5 | DCORSEL;   /* 21 MHz                               */
      FRCTL0 = FWPW | NWAITS_1;       /* add 1 waitstaite                     */
      break;
    case 24:
      CSCTL1 = DCOFSEL_6 | DCORSEL;   /* 24 MHz                               */
      FRCTL0 = FWPW | NWAITS_2;       /* add 2 waitstaites                    */
      break;
    default:                          /* all other cases: choose 8MHz         */
      CSCTL1 = DCOFSEL_6 ;            /* 8MHz                                 */
      FRCTL0 = FWPW | NWAITS_0;       /* no wait state required               */
      break;
	}
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"
