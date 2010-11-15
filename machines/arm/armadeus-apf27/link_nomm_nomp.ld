MEMORY
{
    bootrom (rx) : ORIGIN = 0x00000000, LENGTH = 16K /* hard-wired into microcontroller */
    dram0 (wx)   : ORIGIN = 0xA0000000, LENGTH = 64M
    dram1 (wx)   : ORIGIN = 0xB0000000, LENGTH = 64M
    fvram (wx)   : ORIGIN = 0xFFF00000, LENGTH = 979K /* free (unused by system) VRAM memory */
    vvram (wx)   : ORIGIN = 0xFFFF4C00, LENGTH = 45K  /* vector RAM */
}

ENTRY (tpl_arm_bootstrap_entry)

SECTIONS
{
  /* "root" vector table cannot be written on iMX27, so we drop this section at load */
  .vectbl (NOLOAD) : {
    *(.vectbl)
  } > bootrom

  .text : ALIGN(4) SUBALIGN(4) {
    /* these sections are used to boot from u-boot easily */
     *(.ubootsupport) 
    /* legacy text section */
    *(.text)
    *(.osApiCode) /* to be removed when then goil template "code/tpl_invoque.goilTemplate" will use MemMap.h */
    *(.glue_7*)
    *(.vfp11_veneer)
    *(.v4_bx) 
  } > dram0

  .rodata : ALIGN(4) SUBALIGN(4) {
    *(.rodata)
    *(.rodata*) 
    *(.rdata)
  } > dram0
  
  /*
   * vars
   */
  .data : ALIGN(4) SUBALIGN(4) {
    *(.data)
    *(.data*) 
  } > dram0

  .bss (NOLOAD) : ALIGN(4) SUBALIGN(4) {
    common_zeroed_vars_begin = .;
    *(.bss)
    *(.bss*)
    common_zeroed_vars_end = .;
    *(.COMMON)
    *(.stacks)
  } > dram0

  .imx27_vectors (NOLOAD) : {
    . += 0xb2f0; /* jump to 0xfffffef0 */
    KEEP (* (.exceptionTable))
    . = 0xb300; /* jump to 0xffffff00 */
    KEEP (* (.interrupt_table))
  } > vvram 
}

