  . = ALIGN(16); /* MPC5510 MPU requires 16 bytes alignment */
  __SEG_START_ISR_$ISR_NAME$_CODE_RGN = .;
  * (.ISR_$ISR_NAME$SECCODE)
  . = ALIGN(16);
  __SEG_END_ISR_$ISR_NAME$_CODE_RGN = . - 1;
  