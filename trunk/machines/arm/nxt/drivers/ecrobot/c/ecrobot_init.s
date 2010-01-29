@  This is the init for an AT91SAM7S64
@ This code is entered with interrupts disabled
@ This code should work as start code from flash or RAM.
@ It does not have to be placed at address 0 since it will copy the vectors
@ there if needed.
@



@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

@ Macros to do memory initialisation

	.macro  mem_copy,  source, source_end, dest
	ldr   r0,=\source
	ldr   r1,=\source_end
	ldr   r2,=\dest
	bl    mem_copy_func
	.endm

	.macro mem_initialise, dest, dest_end, val
	ldr   r0,=\dest
	ldr   r1,=\dest_end
	ldr   r2,=\val
	bl    mem_init_func
	.endm

	.macro mac_string str
	.string \str
	.endm


@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


	.extern main

	.global start	
	.global undef_handler
	.global swi_handler
	.global prefetch_abort_handler
	.global data_abort_handler
	.global reserved_handler

	.text
	.code 32
	.align 	0

@ Flash is always a 1MB
@ RAM is always at 2MB
@ 0MB will be flash or RAM depending on the remap state.
@
start:
        
@ Disable interrupts (IRQ and FIQ). Should not have to do this, but lets not assume anything
@	mrs  r0,cpsr
@	orr  r0,r0,#0xc0
@	msr  cpsr_all,r0

@
@ This patch resets the chip
@
@ patch begin
@	ldr r0, =0xfffffd00
@0:
@	ldr r1, [r0, #4] @ RSTC_SR
@	ands r1, r1, #0x20000
@	bne 0b
@	ldr r1, =0xa5000004
@	ldr r1, [r0] @ RSTC_CR
@1:
@	ldr r1, [r0, #4] @ RSTC_SR
@	ands r1, r1, #0x20000
@	bne 1b
@ patch end

@
@ Do the remapping, if required, so that RAM is at address 0.
@
@  We read what is at address 0 and 2MB
@ We then invert what is at 2MB and read at 0 again
@ If address 0 has changed, then RAM is already at 0, so there is
@ no need to remap

@	ldr  r0,=0x000000
@	ldr  r2,=0x200000
@	ldr  r3,[r0]
@	ldr  r4,[r2]
@	ldr  r5,=0xFFFFFFFF
@	eor  r5,r4,r5
@	str  r5,[r2]
@	ldr  r5,[r0]
@	str  r4,[r2]

@	cmp  r3,r5
@	bne  skip_remap_toggle

@	ldr  r0,=0xFFFFFF00
@	ldr  r1,=1
@	str  r1,[r0]

@skip_remap_toggle:

@		b    continue_boot


continue_boot:

@   MC_FMR:
@   Set up flash memory accessing and memory for 48 MHz FMCN = 50)
@   2 wait states (FWS = 1)
@   No special flags
@

@	ldr r0,=0xFFFFFF60
@	ldr r1,=((72 << 16) | (1 << 8))
@	str r1,[r0]

@
@    Disable watchdog
@    Set MDT_MR disable bit. 
@    Note: probably want to set this differently at some stage...
@
@	ldr r0,=0xFFFFFD44
@	ldr r1,=0x00008000
@	str r1,[r0]

@
@    Set up PLL & clock source
@    The main crystal is 18.432 MHz
@    We want as close as we can get to 48MHz
@    We use the PLL to generate 18432000 / 14 * 73 = 96109714
@    We then divide this by 2

@ Start main osc

@	ldr r0,=0xFFFFFC20  @ PMC_MOR
@	ldr r1,=0x00000601
@	str r1,[r0]

@	ldr r0,=0xFFFFFC68  @ PMC_SR
@wait_MOSCS:
@	ldr r1,[r0]
@	ands r1,r1,#1
@	beq wait_MOSCS

	@ set up PLL
@	ldr r0,=0xFFFFFC2C  @ PMC_PLLR
@	ldr r1,=0x00481C0E
@	str r1,[r0]

@	ldr r0,=0xFFFFFC68  @ PMC_SR
@wait_pll_lock:
@	ldr r1,[r0]
@	ands r1,r1,#4
@	beq wait_pll_lock

@	ldr r0,=0xFFFFFC68  @ PMC_SR
@wait_MCLK_Ready0:
@	ldr r1,[r0]
@	ands r1,r1,#8
@	beq  wait_MCLK_Ready0

@ Set up master clock to use clock div 2
@	ldr r0,=0xFFFFFC30 @ PMC_MCKR
@	ldr r1,=0x4
@	str r1,[r0]

@	ldr r0,=0xFFFFFC68  @ PMC_SR
@wait_MCLK_Ready1:
@	ldr r1,[r0]
@	ands r1,r1,#8
@	beq  wait_MCLK_Ready1

@ Set up master clock to use PLL clock div 2
@	ldr r0,=0xFFFFFC30 @ PMC_MCKR
@	ldr r1,=0x7
@	str r1,[r0]

@	ldr r0,=0xFFFFFC68  @ PMC_SR
@wait_MCLK_Ready2:
@	ldr r1,[r0]
@	ands r1,r1,#8
@	beq  wait_MCLK_Ready2


@
@
@ Copy the vector table
@
@vector_copy:
@	mem_copy       __vectors_load_start__, __vectors_load_end__, __vectors_ram_start__

@
@ Initialise memory regions
@
@data_copy:
@	mem_copy       __data_load_start__, __data_load_end__, __data_ram_start__
@ram_text_copy:
@	mem_copy       __ramtext_load_start__, __ramtext_load_end__, __ramtext_ram_start__
@bss_init:
@	mem_initialise __bss_start__, __bss_end__, 0

/*removed by fp */
@stack_init_0:
@	mem_initialise __stack_start__, __stack_end__, 0x6b617453 @ 'Stak'

@
@   Set up stacks etc.
@   We set up the irq and system stacks
@   We switch to system mode for further execution
@   NB Stacks should be 8-byte aligned for APCS
@   They should already be aligned, but we mask the values to make sure.
@
@stack_init_1:
@ Set up Interrupt stack
@                msr   CPSR_c,#0xD2 @ IRQ mode, IRQ, FIQ off
@                ldr   r0, =__irq_stack__
@                mov   sp,r0
@		bic   sp,sp,#7    @ make sure it is 8-byte aligned

@
@ Set up System stack
@		msr   CPSR_c,#0xDF		@ System mode , I and F bits set (interrupts disabled)
@		ldr   r3, =__system_stack__
@		mov   sp, r3
@		bic   sp,sp,#7    @ make sure it is 8-byte aligned

  /* added by fp */
  /* setup IRQ mode initial stack pointer */
  msr cpsr_c, #(0b10010 | 0b10000000 | 0b01000000)
    ldr sp, =irq_stack_bottom

    /* setup FIQ mode initial stack pointer */
  msr cpsr_c, #(0b10001 | 0b10000000 | 0b01000000)
    ldr sp, =fiq_stack_bottom

    /* setup service (syscall) mode initial stack pointer */
  msr cpsr_c, #(0b10011 | 0b10000000 | 0b01000000)
    ldr sp, =svc_stack_bottom

  msr cpsr_c, #(0b10111 | 0b10000000 | 0b01000000)
    ldr sp, =abt_stack_bottom

  msr cpsr_c, #(0b11011 | 0b10000000 | 0b01000000)
    ldr sp, =und_stack_bottom

  /* setup user mode initial stack pointer */
  msr cpsr_c, #(0b11111 | 0b10000000 | 0b01000000)
    ldr sp, =usr_stack_bottom
    
    

@ Set up initial frame pointers etc
@		mov     a2, #0						@ Second arg: fill value
@		mov	fp, a2							@ Null frame pointer
@		mov	r7, a2							@ Null frame pointer for Thumb

@ Kick into main code using interworking

    bl tpl_arm_initialize_board

    ldr r5,=main
	mov lr,pc
	bx  r5

@ If we get here then main returned -- bad!
main_returned:
	b main_returned




@
@ Dummy handlers
@

undef_handler:
	b undef_handler
swi_handler:
	b swi_handler
prefetch_abort_handler:
	b prefetch_abort_handler

/*modified by fp*/
	@.extern data_abort_pc
	@.extern data_abort_C

data_abort_handler:
	b data_abort_handler
    @ldr r0,=data_abort_pc
	@str lr,[r0]
	@msr   CPSR_c,#0xDF		@ System mode , I and F bits set (interrupts disabled)
	@ldr r0,=data_abort_C
	@mov lr,pc
	@bx  r0
data_abort_C_returned:
	b data_abort_C_returned
reserved_handler:
	b reserved_handler



@ Little helper funcs


@ mem_copy_func r0 = source start, r1 = end of source, r2 = destination
@ Will not copy if source == destination
@ Will try to use ldm/stm if 16-byte aligned.
mem_copy_func:
	@ bail if source and dest addresses are the same
	cmp   r0,r2
	bxeq  lr
	
	@ test if all addressed are 16-byte aligned, if so use ldm/stm copy
	mov   r3,r0
	orr   r3,r3,r1
	orr   r3,r3,r2
	ands  r3,r3,#15
	beq     mcf_16_aligned
	
	@ else use 4-byte aligned loop
mcf_loop:
	cmp   r0,r1
	ldrlo r3,[r2],#4 
	strlo r3,[r0],#4 
	blo   mcf_loop
	bx    lr

mcf_16_aligned:
	cmp   r0,r1
	ldmloia r0!,{r3-r6}
	stmloia r2!,{r3-r6}
	blo   mcf_16_aligned
	bx    lr
	

@ mem_init_func: r0 = start address, r1 = end address, r2 is value to write
@ If start and end addresses are multiples of 16 then we use stms to do the
@ storing.
mem_init_func:
	orr   r3,r0,r1
	ands  r3,r2,#15
	beq   mif_16_aligned
mif_loop:
	cmp   r0,r1
	strlo r2,[r0],#4 
	blo   mif_loop
	bx    lr

mif_16_aligned:
	mov   r3,r2
	mov   r4,r2
	mov   r5,r2
mif_16_loop:
	cmp   r0,r1
	stmloia r0!,{r2-r5}
	blo   mif_16_loop
	bx    lr
