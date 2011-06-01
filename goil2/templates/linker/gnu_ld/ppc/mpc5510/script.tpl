ENTRY(_start)

MEMORY
{
  system_reset        (ax) : ORIGIN = 0x100,  LENGTH = 0x100
  machine_check       (ax) : ORIGIN = 0x200,  LENGTH = 0x100
  data_storage        (ax) : ORIGIN = 0x300,  LENGTH = 0x100
  instruction_storage (ax) : ORIGIN = 0x400,  LENGTH = 0x100
  external_interrupt  (ax) : ORIGIN = 0x500,  LENGTH = 0x100
  alignment           (ax) : ORIGIN = 0x600,  LENGTH = 0x100
  program             (ax) : ORIGIN = 0x700,  LENGTH = 0x100
  fp_unavailable      (ax) : ORIGIN = 0x800,  LENGTH = 0x100
  decrementer         (ax) : ORIGIN = 0x900,  LENGTH = 0x100
  reserved_A00        (ax) : ORIGIN = 0xA00,  LENGTH = 0x100
  reserved_B00        (ax) : ORIGIN = 0xB00,  LENGTH = 0x100
  system_call         (ax) : ORIGIN = 0xC00,  LENGTH = 0x100
  trace               (ax) : ORIGIN = 0xD00,  LENGTH = 0x100
  fp_assist           (ax) : ORIGIN = 0xE00,  LENGTH = 0x100
  
  ram                (wax) : ORIGIN = 0x3000, LENGTH = 16M
                            /* 16 Mo of Volatile memory*/
}

SECTIONS
{
  /*
   * code and consts of the operating system (Trampoline).
   * this section is not accessible from an untrusted process
   */
  . = ALIGN(4);
  ostext : {
    *(.SC_handler)
    *(.EI_handler)
    *(.osCode)
  } > ram

  . = ALIGN(4);
  osconst : {
    *(.osConst)
  } > ram
  
  /*
   * remaining .text (ie no section given)
   */
  text_garbage : {
    *(.text)
    *(.ctors)
    *(.dtors)

  } > ram

  other_garbage : {
    *(.init)
    *(.fini)
  } > ram
  
  /*
   * vars of the operating system (Trampoline)
   */
  osvars : {
    *(.osVar)
  } > ram

  /*
   * code and consts of the processes of the applications
   */
	apptext ALIGN(16) : { /* MPC5510 MPU requires 16 bytes alignment */
    __SEG_START_APP_CODE_CONST_RGN = .;
    *(.osApiConst)  /* API constants    */
    *(.rodata)      /* litteral strings */
    *(.osApiCode)   /* API functions    */
$USER_CODE$
  } > ram
  appconst ALIGN(16) : {
$USER_CONST$
    . = ALIGN(16);
    __SEG_START_APP_CODE_CONST_RGN = . - 1;
  } > ram
  
  /*
   * bss data
   */
  bss_data ALIGN(16) : {
    *(.bss) *(.sbss)  /* *(.sbss2) */
  } > ram
  . = ALIGN(16);

  /*
   * private data of processes
   */
  procvars : {
$PROC_VAR$
  } > ram

  /*
   * stack of processes
   */
  procstack : {
$PROC_STACK$
  } > ram

  /*
   * os application data
   */
  appvars : {
$APP_VAR$
  } > ram
  
  /*
   * garbage
   */
  data_garbage : {
    *(.data)
    *(.sdata)
    *(.sdata2)
    *(.got)
    *(.got1)
    *(.got2)
    *(.fixup)
    *(.gcc_except_table)
    *(.eh_frame)
    *(.jcr)
  } > ram
  .comment :        { *(.comment)        } > ram
  relocatable : {
    *(.rela.*)
  } > ram

	.vector_external_interrupt : { *(.EI_vector) } > external_interrupt
  .vector_system_call :        { *(.SC_vector) } > system_call

}

