  . = ALIGN(16); /* MPC5510 MPU requires 16 bytes alignment */
  __SEG_START_$PROC_KIND$_$TASK_NAME$_VAR_RGN = .;
  * (.$PROC_KIND$_$TASK_NAME$Var)
  . = ALIGN(16);
  __SEG_END_$PROC_KIND$_$TASK_NAME$_VAR_RGN = . - 1;
  