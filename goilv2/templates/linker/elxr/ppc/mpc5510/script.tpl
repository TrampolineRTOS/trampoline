ENTRY(_start)

MEMORY
{
  IT_vectors (ax) : ORIGIN = 0,      LENGTH = 0x3000
  ram (wax) :       ORIGIN = 0x3000, LENGTH = 16M /* 16 Mo of Volatile memory*/
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

	.vector 0xC00 : { *(.SC_handler ) }> IT_vectors

}

