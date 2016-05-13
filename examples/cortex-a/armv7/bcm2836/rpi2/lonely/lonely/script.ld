ENTRY (Vec_reset)
/* SEARCH_DIR(.) */

MEMORY
{
  internal_ram : org = 0x00008000, len = 0x1000000
}

SECTIONS {
  .vectbl : {
    *(.vectbl);
    . = ALIGN(4);
  } > internal_ram
}

SECTIONS
{
  /*
   * code and consts of the operating system (Trampoline).
   * this section is not accessible from an untrusted process
   */
  . = ALIGN(4);
  ostext : {
    *(.osCode)
  } > internal_ram

  . = ALIGN(4);
  osconst : {
    *(.osConst)
  } > internal_ram

  /*
   * remaining .text (ie no section given)
   */
  . = ALIGN(4);
  text_garbage : {
    *(.text)
    *(.glue_7)
    *(.glue_7t)
  } > internal_ram

  /*
   * vars of the operating system (Trampoline)
   */
  . = ALIGN(4);
  osvars : {
    *(.osVar)
    *(.stacks) /* TODO : is it the best place ? */
  } > internal_ram

  /*
   * code and consts of the processes of the applications
   */
  apptext ALIGN(16) : { /* MPC5510 MPU requires 16 bytes alignment */
    __SEG_START_APP_CODE_CONST_RGN = .;
    *(.osApiConst)  /* API constants    */
    *(.rodata)      /* litteral strings */
    *(.osApiCode)   /* API functions    */
    /* Sections for code of tasks and ISR */
    *(.Task_task1Code)

    *(.Task_task2Code)

    *(.Task_task3Code)

    *(.ISR_isr_button2Code)

    *(.ISR_isr_button1Code)

  } > internal_ram

  appconst ALIGN(16) : {
/* Sections for const of tasks and ISR */
      *(.Task_task1_SEC_CONST_32BIT)
      *(.Task_task1_SEC_CALIB_32BIT)
      *(.Task_task1_SEC_CARTO_32BIT)
      *(.Task_task1_SEC_CONFIG_DATA_32BIT)
      *(.Task_task1_SEC_CONST_16BIT)
      *(.Task_task1_SEC_CALIB_16BIT)
      *(.Task_task1_SEC_CARTO_16BIT)
      *(.Task_task1_SEC_CONFIG_DATA_16BIT)
      *(.Task_task1_SEC_CONST_8BIT)
      *(.Task_task1_SEC_CALIB_8BIT)
      *(.Task_task1_SEC_CARTO_8BIT)
      *(.Task_task1_SEC_CONFIG_DATA_8BIT)
      *(.Task_task1_SEC_CONST_BOOLEAN)
      *(.Task_task1_SEC_CALIB_BOOLEAN)
      *(.Task_task1_SEC_CARTO_BOOLEAN)
      *(.Task_task1_SEC_CONFIG_DATA_BOOLEAN)
      *(.Task_task1_SEC_CONST_UNSPECIFIED)
      *(.Task_task1_SEC_CALIB_UNSPECIFIED)
      *(.Task_task1_SEC_CARTO_UNSPECIFIED)
      *(.Task_task1_SEC_CONFIG_DATA_UNSPECIFIED)
      *(.Task_task2_SEC_CONST_32BIT)
      *(.Task_task2_SEC_CALIB_32BIT)
      *(.Task_task2_SEC_CARTO_32BIT)
      *(.Task_task2_SEC_CONFIG_DATA_32BIT)
      *(.Task_task2_SEC_CONST_16BIT)
      *(.Task_task2_SEC_CALIB_16BIT)
      *(.Task_task2_SEC_CARTO_16BIT)
      *(.Task_task2_SEC_CONFIG_DATA_16BIT)
      *(.Task_task2_SEC_CONST_8BIT)
      *(.Task_task2_SEC_CALIB_8BIT)
      *(.Task_task2_SEC_CARTO_8BIT)
      *(.Task_task2_SEC_CONFIG_DATA_8BIT)
      *(.Task_task2_SEC_CONST_BOOLEAN)
      *(.Task_task2_SEC_CALIB_BOOLEAN)
      *(.Task_task2_SEC_CARTO_BOOLEAN)
      *(.Task_task2_SEC_CONFIG_DATA_BOOLEAN)
      *(.Task_task2_SEC_CONST_UNSPECIFIED)
      *(.Task_task2_SEC_CALIB_UNSPECIFIED)
      *(.Task_task2_SEC_CARTO_UNSPECIFIED)
      *(.Task_task2_SEC_CONFIG_DATA_UNSPECIFIED)
      *(.Task_task3_SEC_CONST_32BIT)
      *(.Task_task3_SEC_CALIB_32BIT)
      *(.Task_task3_SEC_CARTO_32BIT)
      *(.Task_task3_SEC_CONFIG_DATA_32BIT)
      *(.Task_task3_SEC_CONST_16BIT)
      *(.Task_task3_SEC_CALIB_16BIT)
      *(.Task_task3_SEC_CARTO_16BIT)
      *(.Task_task3_SEC_CONFIG_DATA_16BIT)
      *(.Task_task3_SEC_CONST_8BIT)
      *(.Task_task3_SEC_CALIB_8BIT)
      *(.Task_task3_SEC_CARTO_8BIT)
      *(.Task_task3_SEC_CONFIG_DATA_8BIT)
      *(.Task_task3_SEC_CONST_BOOLEAN)
      *(.Task_task3_SEC_CALIB_BOOLEAN)
      *(.Task_task3_SEC_CARTO_BOOLEAN)
      *(.Task_task3_SEC_CONFIG_DATA_BOOLEAN)
      *(.Task_task3_SEC_CONST_UNSPECIFIED)
      *(.Task_task3_SEC_CALIB_UNSPECIFIED)
      *(.Task_task3_SEC_CARTO_UNSPECIFIED)
      *(.Task_task3_SEC_CONFIG_DATA_UNSPECIFIED)
      *(.ISR_isr_button2_SEC_CONST_32BIT)
      *(.ISR_isr_button2_SEC_CALIB_32BIT)
      *(.ISR_isr_button2_SEC_CARTO_32BIT)
      *(.ISR_isr_button2_SEC_CONFIG_DATA_32BIT)
      *(.ISR_isr_button2_SEC_CONST_16BIT)
      *(.ISR_isr_button2_SEC_CALIB_16BIT)
      *(.ISR_isr_button2_SEC_CARTO_16BIT)
      *(.ISR_isr_button2_SEC_CONFIG_DATA_16BIT)
      *(.ISR_isr_button2_SEC_CONST_8BIT)
      *(.ISR_isr_button2_SEC_CALIB_8BIT)
      *(.ISR_isr_button2_SEC_CARTO_8BIT)
      *(.ISR_isr_button2_SEC_CONFIG_DATA_8BIT)
      *(.ISR_isr_button2_SEC_CONST_BOOLEAN)
      *(.ISR_isr_button2_SEC_CALIB_BOOLEAN)
      *(.ISR_isr_button2_SEC_CARTO_BOOLEAN)
      *(.ISR_isr_button2_SEC_CONFIG_DATA_BOOLEAN)
      *(.ISR_isr_button2_SEC_CONST_UNSPECIFIED)
      *(.ISR_isr_button2_SEC_CALIB_UNSPECIFIED)
      *(.ISR_isr_button2_SEC_CARTO_UNSPECIFIED)
      *(.ISR_isr_button2_SEC_CONFIG_DATA_UNSPECIFIED)
      *(.ISR_isr_button1_SEC_CONST_32BIT)
      *(.ISR_isr_button1_SEC_CALIB_32BIT)
      *(.ISR_isr_button1_SEC_CARTO_32BIT)
      *(.ISR_isr_button1_SEC_CONFIG_DATA_32BIT)
      *(.ISR_isr_button1_SEC_CONST_16BIT)
      *(.ISR_isr_button1_SEC_CALIB_16BIT)
      *(.ISR_isr_button1_SEC_CARTO_16BIT)
      *(.ISR_isr_button1_SEC_CONFIG_DATA_16BIT)
      *(.ISR_isr_button1_SEC_CONST_8BIT)
      *(.ISR_isr_button1_SEC_CALIB_8BIT)
      *(.ISR_isr_button1_SEC_CARTO_8BIT)
      *(.ISR_isr_button1_SEC_CONFIG_DATA_8BIT)
      *(.ISR_isr_button1_SEC_CONST_BOOLEAN)
      *(.ISR_isr_button1_SEC_CALIB_BOOLEAN)
      *(.ISR_isr_button1_SEC_CARTO_BOOLEAN)
      *(.ISR_isr_button1_SEC_CONFIG_DATA_BOOLEAN)
      *(.ISR_isr_button1_SEC_CONST_UNSPECIFIED)
      *(.ISR_isr_button1_SEC_CALIB_UNSPECIFIED)
      *(.ISR_isr_button1_SEC_CARTO_UNSPECIFIED)
      *(.ISR_isr_button1_SEC_CONFIG_DATA_UNSPECIFIED)

    . = ALIGN(16);
    __SEG_STOP_APP_CODE_CONST_RGN = . - 1;
  } > internal_ram

  /*
   * bss data
   */
  .bss ALIGN(16) : {
    *(.bss)
    *(COMMON)
  } > internal_ram
  . = ALIGN(16);

  /*
   * private data of processes
   */
  procvars : {
    __SEG_START_Task_task1_VAR_RGN = .;
/* Initialized variables section of Task task1 */
    *(.Task_task1_SEC_VAR_NOINIT_32BIT)
    *(.Task_task1_SEC_VAR_POWER_ON_INIT_32BIT)
    *(.Task_task1_SEC_VAR_FAST_32BIT)
    *(.Task_task1_SEC_VAR_32BIT)
    *(.Task_task1_SEC_VAR_NOINIT_16BIT)
    *(.Task_task1_SEC_VAR_POWER_ON_INIT_16BIT)
    *(.Task_task1_SEC_VAR_FAST_16BIT)
    *(.Task_task1_SEC_VAR_16BIT)
    *(.Task_task1_SEC_VAR_NOINIT_8BIT)
    *(.Task_task1_SEC_VAR_POWER_ON_INIT_8BIT)
    *(.Task_task1_SEC_VAR_FAST_8BIT)
    *(.Task_task1_SEC_VAR_8BIT)
    *(.Task_task1_SEC_VAR_NOINIT_BOOLEAN)
    *(.Task_task1_SEC_VAR_POWER_ON_INIT_BOOLEAN)
    *(.Task_task1_SEC_VAR_FAST_BOOLEAN)
    *(.Task_task1_SEC_VAR_BOOLEAN)
    *(.Task_task1_SEC_VAR_NOINIT_UNSPECIFIED)
    *(.Task_task1_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
    *(.Task_task1_SEC_VAR_FAST_UNSPECIFIED)
    *(.Task_task1_SEC_VAR_UNSPECIFIED)
    __SEG_END_Task_task1_VAR_RGN = ALIGN(16) - 1;
    __SEG_START_Task_task2_VAR_RGN = .;
/* Initialized variables section of Task task2 */
    *(.Task_task2_SEC_VAR_NOINIT_32BIT)
    *(.Task_task2_SEC_VAR_POWER_ON_INIT_32BIT)
    *(.Task_task2_SEC_VAR_FAST_32BIT)
    *(.Task_task2_SEC_VAR_32BIT)
    *(.Task_task2_SEC_VAR_NOINIT_16BIT)
    *(.Task_task2_SEC_VAR_POWER_ON_INIT_16BIT)
    *(.Task_task2_SEC_VAR_FAST_16BIT)
    *(.Task_task2_SEC_VAR_16BIT)
    *(.Task_task2_SEC_VAR_NOINIT_8BIT)
    *(.Task_task2_SEC_VAR_POWER_ON_INIT_8BIT)
    *(.Task_task2_SEC_VAR_FAST_8BIT)
    *(.Task_task2_SEC_VAR_8BIT)
    *(.Task_task2_SEC_VAR_NOINIT_BOOLEAN)
    *(.Task_task2_SEC_VAR_POWER_ON_INIT_BOOLEAN)
    *(.Task_task2_SEC_VAR_FAST_BOOLEAN)
    *(.Task_task2_SEC_VAR_BOOLEAN)
    *(.Task_task2_SEC_VAR_NOINIT_UNSPECIFIED)
    *(.Task_task2_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
    *(.Task_task2_SEC_VAR_FAST_UNSPECIFIED)
    *(.Task_task2_SEC_VAR_UNSPECIFIED)
    __SEG_END_Task_task2_VAR_RGN = ALIGN(16) - 1;
    __SEG_START_Task_task3_VAR_RGN = .;
/* Initialized variables section of Task task3 */
    *(.Task_task3_SEC_VAR_NOINIT_32BIT)
    *(.Task_task3_SEC_VAR_POWER_ON_INIT_32BIT)
    *(.Task_task3_SEC_VAR_FAST_32BIT)
    *(.Task_task3_SEC_VAR_32BIT)
    *(.Task_task3_SEC_VAR_NOINIT_16BIT)
    *(.Task_task3_SEC_VAR_POWER_ON_INIT_16BIT)
    *(.Task_task3_SEC_VAR_FAST_16BIT)
    *(.Task_task3_SEC_VAR_16BIT)
    *(.Task_task3_SEC_VAR_NOINIT_8BIT)
    *(.Task_task3_SEC_VAR_POWER_ON_INIT_8BIT)
    *(.Task_task3_SEC_VAR_FAST_8BIT)
    *(.Task_task3_SEC_VAR_8BIT)
    *(.Task_task3_SEC_VAR_NOINIT_BOOLEAN)
    *(.Task_task3_SEC_VAR_POWER_ON_INIT_BOOLEAN)
    *(.Task_task3_SEC_VAR_FAST_BOOLEAN)
    *(.Task_task3_SEC_VAR_BOOLEAN)
    *(.Task_task3_SEC_VAR_NOINIT_UNSPECIFIED)
    *(.Task_task3_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
    *(.Task_task3_SEC_VAR_FAST_UNSPECIFIED)
    *(.Task_task3_SEC_VAR_UNSPECIFIED)
    __SEG_END_Task_task3_VAR_RGN = ALIGN(16) - 1;
    __SEG_START_ISR_isr_button2_VAR_RGN = .;
/* Initialized variables section of ISR isr_button2 */
    *(.ISR_isr_button2_SEC_VAR_NOINIT_32BIT)
    *(.ISR_isr_button2_SEC_VAR_POWER_ON_INIT_32BIT)
    *(.ISR_isr_button2_SEC_VAR_FAST_32BIT)
    *(.ISR_isr_button2_SEC_VAR_32BIT)
    *(.ISR_isr_button2_SEC_VAR_NOINIT_16BIT)
    *(.ISR_isr_button2_SEC_VAR_POWER_ON_INIT_16BIT)
    *(.ISR_isr_button2_SEC_VAR_FAST_16BIT)
    *(.ISR_isr_button2_SEC_VAR_16BIT)
    *(.ISR_isr_button2_SEC_VAR_NOINIT_8BIT)
    *(.ISR_isr_button2_SEC_VAR_POWER_ON_INIT_8BIT)
    *(.ISR_isr_button2_SEC_VAR_FAST_8BIT)
    *(.ISR_isr_button2_SEC_VAR_8BIT)
    *(.ISR_isr_button2_SEC_VAR_NOINIT_BOOLEAN)
    *(.ISR_isr_button2_SEC_VAR_POWER_ON_INIT_BOOLEAN)
    *(.ISR_isr_button2_SEC_VAR_FAST_BOOLEAN)
    *(.ISR_isr_button2_SEC_VAR_BOOLEAN)
    *(.ISR_isr_button2_SEC_VAR_NOINIT_UNSPECIFIED)
    *(.ISR_isr_button2_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
    *(.ISR_isr_button2_SEC_VAR_FAST_UNSPECIFIED)
    *(.ISR_isr_button2_SEC_VAR_UNSPECIFIED)
    __SEG_END_ISR_isr_button2_VAR_RGN = ALIGN(16) - 1;
    __SEG_START_ISR_isr_button1_VAR_RGN = .;
/* Initialized variables section of ISR isr_button1 */
    *(.ISR_isr_button1_SEC_VAR_NOINIT_32BIT)
    *(.ISR_isr_button1_SEC_VAR_POWER_ON_INIT_32BIT)
    *(.ISR_isr_button1_SEC_VAR_FAST_32BIT)
    *(.ISR_isr_button1_SEC_VAR_32BIT)
    *(.ISR_isr_button1_SEC_VAR_NOINIT_16BIT)
    *(.ISR_isr_button1_SEC_VAR_POWER_ON_INIT_16BIT)
    *(.ISR_isr_button1_SEC_VAR_FAST_16BIT)
    *(.ISR_isr_button1_SEC_VAR_16BIT)
    *(.ISR_isr_button1_SEC_VAR_NOINIT_8BIT)
    *(.ISR_isr_button1_SEC_VAR_POWER_ON_INIT_8BIT)
    *(.ISR_isr_button1_SEC_VAR_FAST_8BIT)
    *(.ISR_isr_button1_SEC_VAR_8BIT)
    *(.ISR_isr_button1_SEC_VAR_NOINIT_BOOLEAN)
    *(.ISR_isr_button1_SEC_VAR_POWER_ON_INIT_BOOLEAN)
    *(.ISR_isr_button1_SEC_VAR_FAST_BOOLEAN)
    *(.ISR_isr_button1_SEC_VAR_BOOLEAN)
    *(.ISR_isr_button1_SEC_VAR_NOINIT_UNSPECIFIED)
    *(.ISR_isr_button1_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)
    *(.ISR_isr_button1_SEC_VAR_FAST_UNSPECIFIED)
    *(.ISR_isr_button1_SEC_VAR_UNSPECIFIED)
    __SEG_END_ISR_isr_button1_VAR_RGN = ALIGN(16) - 1;

  } > internal_ram

  /*
   * stack of processes
   */
  procstack : {

  /* Section of stack of Task task1  */
    __SEG_START_Task_task1_STACK_RGN = .;
    *(.Task_task1Stack)
    __SEG_END_Task_task1_STACK_RGN = ALIGN(16) - 1;

  /* Section of stack of Task task2  */
    __SEG_START_Task_task2_STACK_RGN = .;
    *(.Task_task2Stack)
    __SEG_END_Task_task2_STACK_RGN = ALIGN(16) - 1;

  /* Section of stack of Task task3  */
    __SEG_START_Task_task3_STACK_RGN = .;
    *(.Task_task3Stack)
    __SEG_END_Task_task3_STACK_RGN = ALIGN(16) - 1;

  /* Section of stack of ISR isr_button2  */
    __SEG_START_ISR_isr_button2_STACK_RGN = .;
    *(.ISR_isr_button2Stack)
    __SEG_END_ISR_isr_button2_STACK_RGN = ALIGN(16) - 1;

  /* Section of stack of ISR isr_button1  */
    __SEG_START_ISR_isr_button1_STACK_RGN = .;
    *(.ISR_isr_button1Stack)
    __SEG_END_ISR_isr_button1_STACK_RGN = ALIGN(16) - 1;

  } >internal_ram

  /*
   * os application data
   */
  appvars : {
/* $APP_VAR$ */
  } > internal_ram

  /*
   * garbage
   */
  data_garbage : {
    *(.data)
  } > internal_ram

  .comment : {
    *(.comment)
  } > internal_ram

  debug : {
    *(.debug);
    . = ALIGN(4);
    *(.debug_srcinfo);
    . = ALIGN(4);
    *(.debug_sfnames);
    . = ALIGN(4);
    *(.debug_aranges*);
    . = ALIGN(4);
    *(.debug_pubnames*);
    . = ALIGN(4);
    *(.debug_info*);
    . = ALIGN(4);
    *(.debug_abbrev*);
    . = ALIGN(4);
    *(.debug_line*);
    . = ALIGN(4);
    *(.debug_frame*);
    . = ALIGN(4);
    *(.debug_str*);
    . = ALIGN(4);
    *(.debug_loc*);
    . = ALIGN(4);
    *(.debug_macinfo);
    . = ALIGN(4);
    *(.debug_weaknames);
    . = ALIGN(4);
    *(.debug_funcnames);
    . = ALIGN(4);
    *(.debug_typenames);
    . = ALIGN(4);
    *(.debug_varnames);
    . = ALIGN(4);
  } > internal_ram

}
