/* Interrupt table vector */

/* External handlers */

/* KEEP(tpl_reset_handler) */
/* KEEP(tpl_MPU_violation) */
/* KEEP(tpl_primary_irq_handler_TIMER3_A0_VECTOR) */
/* KEEP(tpl_direct_irq_handler_USCI_A0_VECTOR) */

/* Interrupt table vector 
 *
 * The table is hardcoded in the link script, because the large model
 * uses 32-bit pointers, but interrupt vector requires 16-bit pointers.
 * The conversion can not be done in C. In the link script, the SHORT() 
 * keyword can convert addresses.
 * Of course, all the interrupt routine must reside in the lower 
 * memory (below 64K)
 */

  /* 0xFFB4, LEA_VECTOR       */ SHORT(tpl_null_it)
  /* 0xFFB6, PORT8_VECTOR     */ SHORT(tpl_null_it)
  /* 0xFFB8, PORT7_VECTOR     */ SHORT(tpl_null_it)
  /* 0xFFBA, EUSCI_B3_VECTOR  */ SHORT(tpl_null_it)
  /* 0xFFBC, EUSCI_B2_VECTOR  */ SHORT(tpl_null_it)
  /* 0xFFBE, EUSCI_B1_VECTOR  */ SHORT(tpl_null_it)
  /* 0xFFC0, EUSCI_A3_VECTOR  */ SHORT(tpl_null_it)
  /* 0xFFC2, EUSCI_A2_VECTOR  */ SHORT(tpl_null_it)
  /* 0xFFC4, PORT6_VECTOR     */ SHORT(tpl_null_it)
  /* 0xFFC6, PORT5_VECTOR     */ SHORT(tpl_null_it)
  /* 0xFFC8, TIMER4_A1_VECTOR */ SHORT(tpl_null_it)
  /* 0xFFCA, TIMER4_A0_VECTOR */ SHORT(tpl_null_it)
  /* 0xFFCC, AES256_VECTOR    */ SHORT(tpl_null_it)
  /* 0xFFCE, RTC_VECTOR       */ SHORT(tpl_null_it)
  /* 0xFFD0, PORT4_VECTOR     */ SHORT(tpl_null_it)
  /* 0xFFD2, PORT3_VECTOR     */ SHORT(tpl_null_it)
  /* 0xFFD4, TIMER3_A1_VECTOR */ SHORT(tpl_null_it)
  /* 0xFFD6, TIMER3_A0_VECTOR */ SHORT(tpl_primary_irq_handler_TIMER3_A0_VECTOR)
  /* 0xFFD8, PORT2_VECTOR     */ SHORT(tpl_null_it)
  /* 0xFFDA, TIMER2_A1_VECTOR */ SHORT(tpl_null_it)
  /* 0xFFDC, TIMER2_A0_VECTOR */ SHORT(tpl_null_it)
  /* 0xFFDE, PORT1_VECTOR     */ SHORT(tpl_null_it)
  /* 0xFFE0, TIMER1_A1_VECTOR */ SHORT(tpl_null_it)
  /* 0xFFE2, TIMER1_A0_VECTOR */ SHORT(tpl_null_it)
  /* 0xFFE4, DMA_VECTOR       */ SHORT(tpl_null_it)
  /* 0xFFE6, USCI_A1_VECTOR   */ SHORT(tpl_null_it)
  /* 0xFFE8, TIMER0_A1_VECTOR */ SHORT(tpl_null_it)
  /* 0xFFEA, TIMER0_A0_VECTOR */ SHORT(tpl_null_it)
  /* 0xFFEC, ADC12_VECTOR     */ SHORT(tpl_null_it)
  /* 0xFFEE, USCI_B0_VECTOR   */ SHORT(tpl_null_it)
  /* 0xFFF0, USCI_A0_VECTOR   */ SHORT(tpl_direct_irq_handler_USCI_A0_VECTOR)
  /* 0xFFF2, WDT_VECTOR       */ SHORT(tpl_null_it)
  /* 0xFFF4, TIMER0_B1_VECTOR */ SHORT(tpl_null_it)
  /* 0xFFF6, TIMER0_B0_VECTOR */ SHORT(tpl_null_it)
  /* 0xFFF8, COMP_E_VECTOR    */ SHORT(tpl_null_it)
  /* 0xFFFA, UNMI_VECTOR      */ SHORT(tpl_null_it)
  /* 0xFFFC, SYSNMI_VECTOR    */ SHORT(tpl_MPU_violation)
  /* 0xFFFE, RESET_VECTOR     */ SHORT(tpl_reset_handler)
/* End of file tpl_interrupt_vectors.ld */
