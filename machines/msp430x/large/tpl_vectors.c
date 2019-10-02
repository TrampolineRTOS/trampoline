/* Interrupt table vector */
#include "tpl_compiler.h"
#include "tpl_os.h"
#include "tpl_os_interrupt_kernel.h"
#include "tpl_machine.h"

extern FUNC(void, OS_CODE) tpl_reset_handler(void);
extern FUNC(void, OS_CODE) TIMER3_A0_Handler(void);
extern FUNC(void, OS_CODE) tpl_MPU_violation(void);


/* Interrupt table vector -- start at 0xFF80 */

__attribute__ ((section(".isr_vector"))) CONST(tpl_it_handler, OS_CONST) tpl_it_vectors[64] = {
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it,
  (tpl_it_handler)tpl_null_it, /* AES256_VECTOR        0xFFCC AES256 */
  (tpl_it_handler)tpl_null_it, /* RTC_VECTOR           0xFFCE RTC */
  (tpl_it_handler)tpl_null_it, /* PORT4_VECTOR         0xFFD0 Port 4 */
  (tpl_it_handler)tpl_null_it, /* PORT3_VECTOR         0xFFD2 Port 3 */
  (tpl_it_handler)tpl_null_it, /* TIMER3_A1_VECTOR     0xFFD4 Timer3_A2 CC1, TA */
  (tpl_it_handler)TIMER3_A0_Handler, /* TIMER3_A0_VECTOR     0xFFD6 Timer3_A2 CC0 */
  (tpl_it_handler)tpl_null_it, /* PORT2_VECTOR         0xFFD8 Port 2 */
  (tpl_it_handler)tpl_null_it, /* TIMER2_A1_VECTOR     0xFFDA Timer2_A2 CC1, TA */
  (tpl_it_handler)tpl_null_it, /* TIMER2_A0_VECTOR     0xFFDC Timer2_A2 CC0 */
  (tpl_it_handler)tpl_null_it, /* PORT1_VECTOR         0xFFDE Port 1 */
  (tpl_it_handler)tpl_null_it, /* TIMER1_A1_VECTOR     0xFFE0 Timer1_A3 CC1-2, TA */
  (tpl_it_handler)tpl_null_it, /* TIMER1_A0_VECTOR     0xFFE2 Timer1_A3 CC0 */
  (tpl_it_handler)tpl_null_it, /* DMA_VECTOR           0xFFE4 DMA */
  (tpl_it_handler)tpl_null_it, /* USCI_A1_VECTOR       0xFFE6 USCI A1 Receive/Transmit */
  (tpl_it_handler)tpl_null_it, /* TIMER0_A1_VECTOR     0xFFE8 Timer0_A3 CC1-2, TA */
  (tpl_it_handler)tpl_null_it, /* TIMER0_A0_VECTOR     0xFFEA Timer0_A3 CC0 */
  (tpl_it_handler)tpl_null_it, /* ADC12_VECTOR         0xFFEC ADC */
  (tpl_it_handler)tpl_null_it, /* USCI_B0_VECTOR       0xFFEE USCI B0 Receive/Transmit */
  (tpl_it_handler)tpl_null_it, /* USCI_A0_VECTOR       0xFFF0 USCI A0 Receive/Transmit */
  (tpl_it_handler)tpl_null_it, /* WDT_VECTOR           0xFFF2 Watchdog Timer */
  (tpl_it_handler)tpl_null_it, /* TIMER0_B1_VECTOR     0xFFF4 Timer0_B7 CC1-6, TB */
  (tpl_it_handler)tpl_null_it, /* TIMER0_B0_VECTOR     0xFFF6 Timer0_B7 CC0 */
  (tpl_it_handler)tpl_null_it, /* COMP_E_VECTOR        0xFFF8 Comparator E */
  (tpl_it_handler)tpl_null_it, /* UNMI_VECTOR          0xFFFA User Non-maskable */
  (tpl_it_handler)tpl_MPU_violation, /* SYSNMI_VECTOR        0xFFFC System Non-maskable */
  (tpl_it_handler)tpl_reset_handler  /* RESET_VECTOR         0xFFFE Reset [Highest Priority] */
};

