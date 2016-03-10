/*----------------------------------------------------------------------------*/
/*                                                                            */
/*                                   Link script                              */
/*                                                                            */
/*                                   stm32f407                                */
/*                                                                            */
/* <INIT_POLICY>                                                              */
/* - NO_INIT :          used for variables that are never cleared and never   */
/*                      initialized.                                          */
/* - CLEARED :          used for variables that are cleared to zero after     */
/*                      every reset.                                          */
/* - POWER_ON_CLEARED : used for variables that are cleared to zero only      */
/*                      after power on reset.                                 */
/* - INIT :             used for variables that are initialized with values   */
/*                      after every  reset.                                   */
/* - POWER_ON_INIT :    used for variables that are initialized with values   */
/*                      only after power on reset.                            */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*                                   Configuration                            */
/*                                                                            */
/*----------------------------------------------------------------------------*/

ENTRY(tpl_reset_handler)

/* Highest address of the user mode stack */
_estack = 0x20020000;    /* end of 128K RAM on AHB bus*/

/* Generate a link error if heap and stack don't fit into RAM */
_Min_Heap_Size = 0;      /* required amount of heap  */
_Min_Stack_Size = 0x400; /* required amount of stack */

/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*                                   Memory                                   */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/* Specify the memory areas for stm32f407 */
MEMORY
{
  VECTOR (rx)     : ORIGIN = 0x08000000, LENGTH = 0x188
  FLASH (rx)      : ORIGIN = 0x08000188, LENGTH = 0xFE78
  RAM (xrw)       : ORIGIN = 0x20000000, LENGTH = 192K
  MEMORY_B1 (rx)  : ORIGIN = 0x60000000, LENGTH = 0x0
}


/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*                                ISR Vectors                                 */
/*                                                                            */
/*----------------------------------------------------------------------------*/

SECTIONS {
  /* The startup code goes first into FLASH */
  .isr_vector : {
    . = ALIGN(4);
    KEEP(*(.isr_vector)) /* Startup code */
    . = ALIGN(4);
  } >VECTOR
}

/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*                                    Code                                    */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/*
 * code and const of the operating system (Trampoline).
 * this section is not accessible from an untrusted process
 */
SECTIONS {
  . = ALIGN(4);
  /* --- code of OS --- */
  ostext : {
    *(.SC_handler)
    *(.EI_handler)
    *(.osCode)
    *(.osApiCode)  /* API functions */
    *(.appCommonCode)
  } >FLASH
  . = ALIGN(4);
  /* --- const of OS --- */
  osconst : {
    *(.osConst)
    *(.osApiConst) /* API constants */
  } >FLASH
}

/*
 * code and const of the processes of the applications ]
 */
SECTIONS {
  . = ALIGN(4);
  apptext : {
    __PROGCONST_SECTION_START = .;
    __SEG_START_APP_CODE_CONST_RGN = .;
  . = ALIGN(4);
  /* --- Sections for application code --- */

  /* --- Sections for code of tasks and ISR --- */
    *(.Task_blinkCode)

  } >FLASH
  . = ALIGN(4);
  appconst : {
  /* --- Sections for application const --- */
    *(.rodata)     /* litteral strings (constants, strings, etc.) */
    *(.rodata*)    /* litteral strings (constants, strings, etc.) */

  } >FLASH
}

/*
 * Sections for const of tasks and ISR
 */
SECTIONS {
  . = ALIGN(4);
  procconst : {
      *(.Task_blink_SEC_CONST_32BIT)
      *(.Task_blink_SEC_CALIB_32BIT)
      *(.Task_blink_SEC_CARTO_32BIT)
      *(.Task_blink_SEC_CONFIG_DATA_32BIT)
      *(.Task_blink_SEC_CONST_16BIT)
      *(.Task_blink_SEC_CALIB_16BIT)
      *(.Task_blink_SEC_CARTO_16BIT)
      *(.Task_blink_SEC_CONFIG_DATA_16BIT)
      *(.Task_blink_SEC_CONST_8BIT)
      *(.Task_blink_SEC_CALIB_8BIT)
      *(.Task_blink_SEC_CARTO_8BIT)
      *(.Task_blink_SEC_CONFIG_DATA_8BIT)
      *(.Task_blink_SEC_CONST_BOOLEAN)
      *(.Task_blink_SEC_CALIB_BOOLEAN)
      *(.Task_blink_SEC_CARTO_BOOLEAN)
      *(.Task_blink_SEC_CONFIG_DATA_BOOLEAN)
      *(.Task_blink_SEC_CONST_UNSPECIFIED)
      *(.Task_blink_SEC_CALIB_UNSPECIFIED)
      *(.Task_blink_SEC_CARTO_UNSPECIFIED)
      *(.Task_blink_SEC_CONFIG_DATA_UNSPECIFIED)
    
    . = ALIGN(4);
    __SEG_STOP_APP_CODE_CONST_RGN = . - 1;
    __PROGCONST_SECTION_STOP = . - 1;
  } >FLASH
}

  /* remaining .text (ie no section given) */
SECTIONS {
  .text :
  {
    . = ALIGN(4);
    *(.text)           /* .text sections (code) */
    *(.text*)          /* .text* sections (code) */
    *(.glue_7)         /* glue arm to thumb code */
    *(.glue_7t)        /* glue thumb to arm code */
 *(.eh_frame)

    KEEP (*(.init))
    KEEP (*(.fini))

    . = ALIGN(4);
    _etext = .;        /* define a global symbols at end of code */
    _exit = .;
  } >FLASH
}

SECTIONS {
   .ARM.extab   : { *(.ARM.extab* .gnu.linkonce.armextab.*) } >FLASH
    .ARM : {
    __exidx_start = .;
      *(.ARM.exidx*)
      __exidx_end = .;
    } >FLASH
}

SECTIONS {
  .preinit_array     :
  {
    PROVIDE_HIDDEN (__preinit_array_start = .);
    KEEP (*(.preinit_array*))
    PROVIDE_HIDDEN (__preinit_array_end = .);
  } >FLASH
}

SECTIONS {
  .init_array :
  {
    PROVIDE_HIDDEN (__init_array_start = .);
    KEEP (*(SORT(.init_array.*)))
    KEEP (*(.init_array*))
    PROVIDE_HIDDEN (__init_array_end = .);
  } >FLASH
}

SECTIONS {
  .fini_array :
  {
    PROVIDE_HIDDEN (__fini_array_start = .);
    KEEP (*(.fini_array*))
    KEEP (*(SORT(.fini_array.*)))
    PROVIDE_HIDDEN (__fini_array_end = .);
  } >FLASH
}  

  /* used by the startup to initialize data */
SECTIONS {
  _sidata = .;

  /* Initialized data sections goes into RAM, load LMA copy after code */
  .data : AT ( _sidata )
  {
    . = ALIGN(4);
    _sdata = .;        /* create a global symbol at data start */
    *(.data)           /* .data sections */
    *(.data*)          /* .data* sections */
    *(.osVar)

/* Initialized variables section of Task blink */
    *(.Task_blink_SEC_VAR_POWER_ON_INIT_32BIT)
    *(.Task_blink_SEC_VAR_POWER_ON_INIT_16BIT)
    *(.Task_blink_SEC_VAR_POWER_ON_INIT_8BIT)
    *(.Task_blink_SEC_VAR_POWER_ON_INIT_BOOLEAN)
    *(.Task_blink_SEC_VAR_POWER_ON_INIT_UNSPECIFIED)

    . = ALIGN(4);
    _edata = .;        /* define a global symbol at data end */
  } >RAM
}

  /*
   * private data of processes
   */
SECTIONS {
  .Task_blink_SEC_VAR : {
    . = ALIGN(__SEG_ALIGN_Task_blink_VAR_RGN);
    __SEG_START_Task_blink_VAR_RGN = .;
  /* --- Initialized variables section of Task blink */
    *(.Task_blink_SEC_VAR_NOINIT_32BIT)
    *(.Task_blink_SEC_VAR_FAST_32BIT)
    *(.Task_blink_SEC_VAR_32BIT)
    *(.Task_blink_SEC_VAR_NOINIT_16BIT)
    *(.Task_blink_SEC_VAR_FAST_16BIT)
    *(.Task_blink_SEC_VAR_16BIT)
    *(.Task_blink_SEC_VAR_NOINIT_8BIT)
    *(.Task_blink_SEC_VAR_FAST_8BIT)
    *(.Task_blink_SEC_VAR_8BIT)
    *(.Task_blink_SEC_VAR_NOINIT_BOOLEAN)
    *(.Task_blink_SEC_VAR_FAST_BOOLEAN)
    *(.Task_blink_SEC_VAR_BOOLEAN)
    *(.Task_blink_SEC_VAR_NOINIT_UNSPECIFIED)
    *(.Task_blink_SEC_VAR_FAST_UNSPECIFIED)
    *(.Task_blink_SEC_VAR_UNSPECIFIED)
     __SEG_END_Task_blink_VAR_RGN = .;
     __SEG_SIZE_Task_blink_VAR_RGN = (__SEG_END_Task_blink_VAR_RGN - __SEG_START_Task_blink_VAR_RGN) < 4K ? 4K : __SEG_SIZE_Task_blink_VAR_RGN;
     __SEG_SIZE_Task_blink_VAR_RGN = (__SEG_END_Task_blink_VAR_RGN - __SEG_START_Task_blink_VAR_RGN) < 1K ? 1K : __SEG_SIZE_Task_blink_VAR_RGN;
     __SEG_SIZE_Task_blink_VAR_RGN = (__SEG_END_Task_blink_VAR_RGN - __SEG_START_Task_blink_VAR_RGN) < 512 ? 512 : __SEG_SIZE_Task_blink_VAR_RGN;
     __SEG_SIZE_Task_blink_VAR_RGN = (__SEG_END_Task_blink_VAR_RGN - __SEG_START_Task_blink_VAR_RGN) < 256 ? 256 : __SEG_SIZE_Task_blink_VAR_RGN;
     __SEG_SIZE_Task_blink_VAR_RGN = (__SEG_END_Task_blink_VAR_RGN - __SEG_START_Task_blink_VAR_RGN) < 128 ? 128 : __SEG_SIZE_Task_blink_VAR_RGN;
     __SEG_SIZE_Task_blink_VAR_RGN = (__SEG_END_Task_blink_VAR_RGN - __SEG_START_Task_blink_VAR_RGN) < 64 ? 64 : __SEG_SIZE_Task_blink_VAR_RGN;
     __SEG_SIZE_Task_blink_VAR_RGN = (__SEG_END_Task_blink_VAR_RGN - __SEG_START_Task_blink_VAR_RGN) < 32 ? 32 : __SEG_SIZE_Task_blink_VAR_RGN;
     __SEG_ALIGN_Task_blink_VAR_RGN = __SEG_SIZE_Task_blink_VAR_RGN;
  } >RAM
}

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*                                Stack of processes                          */
/*                                                                            */
/*----------------------------------------------------------------------------*/

SECTIONS {
  /* --- Section of stack of Task blink  */
  .Task_blink_SEC_STACK : {
    . = ALIGN(__SEG_ALIGN_Task_blink_STACK_RGN);
    __SEG_START_Task_blink_STACK_RGN = .;
    *(.Task_blinkStack)
    . = ALIGN(4);
    __SEG_END_Task_blink_STACK_RGN = .;
    __SEG_SIZE_Task_blink_STACK_RGN = (__SEG_END_Task_blink_STACK_RGN - __SEG_START_Task_blink_STACK_RGN) < 4K ? 4K : __SEG_SIZE_Task_blink_STACK_RGN;
    __SEG_SIZE_Task_blink_STACK_RGN = (__SEG_END_Task_blink_STACK_RGN - __SEG_START_Task_blink_STACK_RGN) < 1K ? 1K : __SEG_SIZE_Task_blink_STACK_RGN;
    __SEG_SIZE_Task_blink_STACK_RGN = (__SEG_END_Task_blink_STACK_RGN - __SEG_START_Task_blink_STACK_RGN) < 512 ? 512 : __SEG_SIZE_Task_blink_STACK_RGN;
    __SEG_SIZE_Task_blink_STACK_RGN = (__SEG_END_Task_blink_STACK_RGN - __SEG_START_Task_blink_STACK_RGN) < 256 ? 256 : __SEG_SIZE_Task_blink_STACK_RGN;
    __SEG_SIZE_Task_blink_STACK_RGN = (__SEG_END_Task_blink_STACK_RGN - __SEG_START_Task_blink_STACK_RGN) < 128 ? 128 : __SEG_SIZE_Task_blink_STACK_RGN;
    __SEG_SIZE_Task_blink_STACK_RGN = (__SEG_END_Task_blink_STACK_RGN - __SEG_START_Task_blink_STACK_RGN) < 64 ? 64 : __SEG_SIZE_Task_blink_STACK_RGN;
    __SEG_SIZE_Task_blink_STACK_RGN = (__SEG_END_Task_blink_STACK_RGN - __SEG_START_Task_blink_STACK_RGN) < 32 ? 32 : __SEG_SIZE_Task_blink_STACK_RGN;
    __SEG_ALIGN_Task_blink_STACK_RGN = __SEG_SIZE_Task_blink_STACK_RGN;
  } >RAM

}

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*                                OS application data                         */
/*                                                                            */
/*----------------------------------------------------------------------------*/

SECTIONS {
  /*
   * os application data
   */
   appvars : {
 
  } >RAM
}

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*                          Data (initialized data)                           */
/*                                                                            */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*                          BSS (uninitialized data)                          */
/*                                                                            */
/*----------------------------------------------------------------------------*/

SECTIONS {
  . = ALIGN(4);
  .bss :
  {
    /* This is used by the startup in order to initialize the .bss secion */
    _sbss = .;         /* define a global symbol at bss start */
    __bss_start__ = _sbss;
    *(.bss)
    *(.bss*)
    *(COMMON)
    . = ALIGN(4);
    _ebss = .;         /* define a global symbol at bss end */
    __bss_end__ = _ebss;
  } >RAM
}

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*                                    Heap                                    */
/*                                                                            */
/*----------------------------------------------------------------------------*/

  /* _user_heap_stack section, used to check that there is enough RAM left */
SECTIONS {
  ._user_heap_stack :
  {
    . = ALIGN(4);
    __heap_start__ = . ;
    PROVIDE ( end = . );
    PROVIDE ( _end = . );
    . = . + _Min_Heap_Size;
    . = . + _Min_Stack_Size;
    . = ALIGN(4);
  } >RAM
}

  /* MEMORY_bank1 section, code must be located here explicitly            */
  /* Example: extern int foo(void) __attribute__ ((section (".mb1text"))); */
SECTIONS {
  .memory_b1_text :
  {
    *(.mb1text)        /* .mb1text sections (code) */
    *(.mb1text*)       /* .mb1text* sections (code)  */
    *(.mb1rodata)      /* read-only data (constants) */
    *(.mb1rodata*)
  } >MEMORY_B1
}

  /* Remove information from the standard libraries */
SECTIONS {
  /DISCARD/ :
  {
    libc.a ( * )
    libm.a ( * )
    libgcc.a ( * )
  }

  .ARM.attributes 0 : { *(.ARM.attributes) }
}
