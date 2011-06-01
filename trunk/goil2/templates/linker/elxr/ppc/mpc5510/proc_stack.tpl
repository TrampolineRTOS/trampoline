  . = ALIGN(16); /* MPC5510 MPU requires 16 bytes alignment */
  __SEG_START_$PROC_KIND$_$TASK_NAME$_STACK_RGN = .;
  * (.$PROC_KIND$_$TASK_NAME$Stack)
  . = ALIGN(16);
  __SEG_END_$PROC_KIND$_$TASK_NAME$_STACK_RGN = . - 1;
  