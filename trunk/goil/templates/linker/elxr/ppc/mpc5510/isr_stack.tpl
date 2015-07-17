  . = ALIGN(16); /* MPC5510 MPU requires 16 bytes alignment */
  __SEG_START_ISR_$ISR_NAME$_STACK_RGN = .;
  * (.ISR_$ISR_NAME$SECSTACK)
  . = ALIGN(16);
  __SEG_END_ISR_$ISR_NAME$_STACK_RGN = . - 1;
  