  . = ALIGN(16); /* MPC5510 MPU requires 16 bytes alignment */
  __SEG_START_APP_$APP_NAME$_VAR_RGN = .;
  * (.$APP_NAME$Var)
  . = ALIGN(16);
  __SEG_END_TASK_$APP_NAME$_VAR_RGN = . - 1;
  