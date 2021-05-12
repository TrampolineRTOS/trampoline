/* Interrupt table vector */
#include "tpl_compiler.h"
#include "tpl_os.h"
#include "tpl_os_interrupt_kernel.h"
#include "tpl_machine.h"

/* External handlers */

extern FUNC(void, OS_CODE) tpl_reset_handler (P2CONST(void, OS_APPL_DATA, AUTOMATIC));
extern FUNC(void, OS_CODE) tpl_MPU_violation (P2CONST(void, OS_APPL_DATA, AUTOMATIC));
extern FUNC(void, OS_CODE) tpl_direct_irq_handler_LEA_VECTOR(P2CONST(void, OS_APPL_DATA, AUTOMATIC));
extern FUNC(void, OS_CODE) tpl_primary_irq_handler_TIMER3_A0_VECTOR(P2CONST(void, OS_APPL_DATA, AUTOMATIC));
extern FUNC(void, OS_CODE) tpl_direct_irq_handler_USCI_A0_VECTOR(P2CONST(void, OS_APPL_DATA, AUTOMATIC));

/* Interrupt table vector */

__attribute__ ((section(".isr_vector"))) CONST(tpl_it_handler, AUTOMATIC) tpl_it_vectors[38] = {

  /* 0xFFB4, LEA_VECTOR       */ (tpl_it_handler)tpl_direct_irq_handler_LEA_VECTOR,
  /* 0xFFB6, PORT8_VECTOR     */ (tpl_it_handler)tpl_null_it,
  /* 0xFFB8, PORT7_VECTOR     */ (tpl_it_handler)tpl_null_it,
  /* 0xFFBA, EUSCI_B3_VECTOR  */ (tpl_it_handler)tpl_null_it,
  /* 0xFFBC, EUSCI_B2_VECTOR  */ (tpl_it_handler)tpl_null_it,
  /* 0xFFBE, EUSCI_B1_VECTOR  */ (tpl_it_handler)tpl_null_it,
  /* 0xFFC0, EUSCI_A3_VECTOR  */ (tpl_it_handler)tpl_null_it,
  /* 0xFFC2, EUSCI_A2_VECTOR  */ (tpl_it_handler)tpl_null_it,
  /* 0xFFC4, PORT6_VECTOR     */ (tpl_it_handler)tpl_null_it,
  /* 0xFFC6, PORT5_VECTOR     */ (tpl_it_handler)tpl_null_it,
  /* 0xFFC8, TIMER4_A1_VECTOR */ (tpl_it_handler)tpl_null_it,
  /* 0xFFCA, TIMER4_A0_VECTOR */ (tpl_it_handler)tpl_null_it,
  /* 0xFFCC, AES256_VECTOR    */ (tpl_it_handler)tpl_null_it,
  /* 0xFFCE, RTC_VECTOR       */ (tpl_it_handler)tpl_null_it,
  /* 0xFFD0, PORT4_VECTOR     */ (tpl_it_handler)tpl_null_it,
  /* 0xFFD2, PORT3_VECTOR     */ (tpl_it_handler)tpl_null_it,
  /* 0xFFD4, TIMER3_A1_VECTOR */ (tpl_it_handler)tpl_null_it,
  /* 0xFFD6, TIMER3_A0_VECTOR */ (tpl_it_handler)tpl_primary_irq_handler_TIMER3_A0_VECTOR,
  /* 0xFFD8, PORT2_VECTOR     */ (tpl_it_handler)tpl_null_it,
  /* 0xFFDA, TIMER2_A1_VECTOR */ (tpl_it_handler)tpl_null_it,
  /* 0xFFDC, TIMER2_A0_VECTOR */ (tpl_it_handler)tpl_null_it,
  /* 0xFFDE, PORT1_VECTOR     */ (tpl_it_handler)tpl_null_it,
  /* 0xFFE0, TIMER1_A1_VECTOR */ (tpl_it_handler)tpl_null_it,
  /* 0xFFE2, TIMER1_A0_VECTOR */ (tpl_it_handler)tpl_null_it,
  /* 0xFFE4, DMA_VECTOR       */ (tpl_it_handler)tpl_null_it,
  /* 0xFFE6, USCI_A1_VECTOR   */ (tpl_it_handler)tpl_null_it,
  /* 0xFFE8, TIMER0_A1_VECTOR */ (tpl_it_handler)tpl_null_it,
  /* 0xFFEA, TIMER0_A0_VECTOR */ (tpl_it_handler)tpl_null_it,
  /* 0xFFEC, ADC12_VECTOR     */ (tpl_it_handler)tpl_null_it,
  /* 0xFFEE, USCI_B0_VECTOR   */ (tpl_it_handler)tpl_null_it,
  /* 0xFFF0, USCI_A0_VECTOR   */ (tpl_it_handler)tpl_direct_irq_handler_USCI_A0_VECTOR,
  /* 0xFFF2, WDT_VECTOR       */ (tpl_it_handler)tpl_null_it,
  /* 0xFFF4, TIMER0_B1_VECTOR */ (tpl_it_handler)tpl_null_it,
  /* 0xFFF6, TIMER0_B0_VECTOR */ (tpl_it_handler)tpl_null_it,
  /* 0xFFF8, COMP_E_VECTOR    */ (tpl_it_handler)tpl_null_it,
  /* 0xFFFA, UNMI_VECTOR      */ (tpl_it_handler)tpl_null_it,
  /* 0xFFFC, SYSNMI_VECTOR    */ (tpl_it_handler)tpl_MPU_violation,
  /* 0xFFFE, RESET_VECTOR     */ (tpl_it_handler)tpl_reset_handler
};

/* End of file tpl_interrupt_vectors.c */
