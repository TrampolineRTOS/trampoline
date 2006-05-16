/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline est protege par la loi sur la propriete intellectuelle
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline 32 bits Darwin X86 process machine dependant stuff
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

.text

/*
 * offset of registers in the trampoline register bank. 
 * THIS MUST BE COHERENT WITH THE STRUCTURE DEFINED IN 
 * THE FILE tpl_machine.h
 * This also must be coherent with the linux structure 
 * when receiving a posix signal (see file:
 * /arch/i386/kernel/signal.c 
 * of linux sources, setup_sigcontext fonction).
 */

.set CTX_gs_OFFSET,0
.set CTX_fs_OFFSET,4
.set CTX_es_OFFSET,8
.set CTX_ds_OFFSET,12
.set CTX_edi_OFFSET,16
.set CTX_esi_OFFSET,20
.set CTX_ebp_OFFSET,24
.set CTX_esp_OFFSET,28
.set CTX_ebx_OFFSET,32
.set CTX_edx_OFFSET,36
.set CTX_ecx_OFFSET,40
.set CTX_eax_OFFSET,44
.set CTX_eip_OFFSET,48
.set CTX_cs_OFFSET,52
.set CTX_eflags_OFFSET,56
.set CTX_ss_OFFSET,60


/* offset in the Linux POSIX Frame.
 * When a signal is received, registers are save onto the stack frame.
 * This offset gives the start of the register bank in the stack.
 * Registers in the Linux Frame are in the same order as in Trampoline
 * register structure.
*/
.set FRAME_OFFSET,39

/* .set __TPL_GET_LINUX_FRAME_OFFSET__,1 */


.globl tpl_switch_context
	.type	tpl_switch_context, @function
tpl_switch_context:

	/* stack frame management. */
	pushl	%ebp
	movl	%esp, %ebp
	
	/* if no old context is defined, jump to the save part */
	
	/* Save eax that will be use to store oldcontext's @  */
	pushl	%eax 
	/* eax gets @ of oldcontext (first argument)  */
	movl	8(%ebp), %eax 

	/* if eax=0, oldcontext = NULL  */
	/* no save of the current context in this case */

	cmpl	$0, %eax 
	je	nosave 

	/* get ic from oldcontext  */
	movl	(%eax), %eax 

	/* Save the current context in the old context  */
	/* save 16 bits registers onto oldcontext's structure  */
	movw	%gs , CTX_gs_OFFSET(%eax) 
	movw	%fs , CTX_fs_OFFSET(%eax) 
	movw	%es , CTX_es_OFFSET(%eax) 
	movw	%ds , CTX_ds_OFFSET(%eax) 
	movl	%edi, CTX_edi_OFFSET(%eax) 
	movl	%esi, CTX_esi_OFFSET(%eax) 
	movl	%ebp, CTX_ebp_OFFSET(%eax) 
	/*esp saved later. */
	movl	%ebx, CTX_ebx_OFFSET(%eax) 
	movl	%edx, CTX_edx_OFFSET(%eax) 
	movl	%ecx, CTX_ecx_OFFSET(%eax) 

	/* move @ of oldcontext to ebx, in order to store eax  */
	/* (since ebx is already stored)  */
	movl	%eax, %ebx 
	popl	%eax 
	movl	%eax, CTX_eax_OFFSET(%ebx) 

	/* save now the stack pointer: eax has been poped.  */
	movl	%esp, CTX_esp_OFFSET(%ebx) 

	/*return address.  */
	pushl	%eax 
	movl	4(%ebp), %eax 
	movl	%eax, CTX_eip_OFFSET(%ebx) /* save the return address */

	movw	%cs , CTX_cs_OFFSET(%ebx) 
	movl	$0, CTX_eflags_OFFSET(%ebx) 
	movw	%ss , CTX_ss_OFFSET(%ebx)  /* eflags set to 0 */

nosave:  
	/*
	 * restore the current context to the new context 
	 */
	

	/* to preserve the stack (same nb of push/pop)  */
	popl	%eax 

	/* First, remove ebp and eip from the stack.  */
	popl	%eax 
	popl	%eax 

	/* eax is used to save @ of newcontext  */
	movl	12(%ebp), %eax 
	/* eax gets ic of new context */
	movl	(%eax), %eax 

	/* movw	CTX_gs_OFFSET(%eax), %gs  */
	/* movw	CTX_fs_OFFSET(%eax), %fs  */
	/* movw	CTX_es_OFFSET(%eax), %es  */
	/* movw	CTX_ds_OFFSET(%eax), %ds  */
	/* movw	CTX_cs_OFFSET(%eax), %cs */
	/* movw	CTX_ss_OFFSET(%eax), %ss */
	movl	CTX_edi_OFFSET(%eax), %edi 
	movl	CTX_esi_OFFSET(%eax), %esi 
	movl	CTX_ebx_OFFSET(%eax), %ebx 
	movl	CTX_edx_OFFSET(%eax), %edx 
	movl	CTX_ecx_OFFSET(%eax), %ecx 

/***************************** switch stack *********************************/
	movl	CTX_esp_OFFSET(%eax), %esp 

	/* the stack wil have eip, ebp and eflags in that order  */
	/* restore eip, using ebx, not yet restored */
	movl	CTX_eip_OFFSET(%eax), %ebx 
	pushl %ebx 
	movl	CTX_ebp_OFFSET(%eax), %ebx 
	pushl %ebx 
	movl	CTX_eflags_OFFSET(%eax), %ebx 
	pushl %ebx

	/* use ebx, to restore eax.  */
	pushl	%ebx 
	movl	%eax, %ebx 
	movl	CTX_eax_OFFSET(%ebx), %eax 

	/* release the lock */
	/* first. Save on the stack registers that may be modified 
	 * by the function call: i.e all the registers: 
	 * eip, ebp, eflags and ebx are on the stack.
	 **/
	pushl %eax
	pushl %ecx
	pushl %edx
	pushl %esi
	pushl %edi
	/* pushw %ss */
	/* pushw %ds */
	/* pushw %es */
	/* pushw %fs */
	/* pushw %gs  */
	/* Then call the function.*/
	call tpl_release_task_lock
	/* and restore registers. */
	/* popw %gs */
	/* popw %fs */
	/* popw %es */
	/* popw %ds */
	/* popw %ss */
	popl %edi
	popl %esi
	popl %edx
	popl %ecx
	popl %eax
	
	/*restore ebx */
	popl	%ebx 
	/* restore flags from top of stack  */
	/* ********** following instructions SHOULD NOT change flags  */
	popf
	/* frame restore. */
	popl	%ebp
	ret

	.size	tpl_switch_context, .-tpl_switch_context


.ifnotdef __TPL_GET_LINUX_FRAME_OFFSET__

.globl tpl_switch_context_from_it
	.type	tpl_switch_context_from_it, @function
tpl_switch_context_from_it:
	/* stack frame management. */
	pushl	%ebp
	movl	%esp, %ebp

	/* the registers are saved on the frame used when taking into account
	 * the POSIX signal
	 * First: store the old context from the values saved in the frame.
	*/

	/* if no old context is defined, jump the save procedure */
	/* eax gets @ of oldcontext (first argument) */
	movl	8(%ebp), %eax 

	/* 
	* if eax=0, oldcontext = NULL 
	* no save of the current context in this case
	*/
	cmpl	$0, %eax 
	je	nosaveIT 

	/* get ic from oldcontext */
	movl	(%eax), %eax 


	/* Save the context stored in the frame in the old context */
	/* save registers onto oldcontext's structure */
	movl	FRAME_OFFSET*4+CTX_gs_OFFSET(%ebp) ,  %ebx 
	movl	%ebx ,  CTX_gs_OFFSET(%eax) 
	movl	FRAME_OFFSET*4+CTX_fs_OFFSET(%ebp) ,  %ebx 
	movl	%ebx ,  CTX_fs_OFFSET(%eax) 
	movl	FRAME_OFFSET*4+CTX_es_OFFSET(%ebp) ,  %ebx 
	movl	%ebx ,  CTX_es_OFFSET(%eax) 
	movl	FRAME_OFFSET*4+CTX_ds_OFFSET(%ebp) ,  %ebx 
	movl	%ebx ,  CTX_ds_OFFSET(%eax) 
	movl	FRAME_OFFSET*4+CTX_edi_OFFSET(%ebp) ,  %ebx 
	movl	%ebx ,  CTX_edi_OFFSET(%eax) 
	movl	FRAME_OFFSET*4+CTX_esi_OFFSET(%ebp) ,  %ebx 
	movl	%ebx ,  CTX_esi_OFFSET(%eax) 
	movl	FRAME_OFFSET*4+CTX_ebp_OFFSET(%ebp) ,  %ebx 
	movl	%ebx ,  CTX_ebp_OFFSET(%eax) 
	movl	FRAME_OFFSET*4+CTX_esp_OFFSET(%ebp) ,  %ebx 
	movl	%ebx ,  CTX_esp_OFFSET(%eax) 
	movl	FRAME_OFFSET*4+CTX_ebx_OFFSET(%ebp) ,  %ebx 
	movl	%ebx ,  CTX_ebx_OFFSET(%eax) 
	movl	FRAME_OFFSET*4+CTX_edx_OFFSET(%ebp) ,  %ebx 
	movl	%ebx ,  CTX_edx_OFFSET(%eax) 
	movl	FRAME_OFFSET*4+CTX_ecx_OFFSET(%ebp) ,  %ebx 
	movl	%ebx ,  CTX_ecx_OFFSET(%eax) 
	movl	FRAME_OFFSET*4+CTX_eax_OFFSET(%ebp) ,  %ebx 
	movl	%ebx ,  CTX_eax_OFFSET(%eax) 

	/* 2 dummy ints added in the linux signal frame */

	movl	(FRAME_OFFSET+2)*4+CTX_eip_OFFSET(%ebp) ,  %ebx 
	movl	%ebx ,  CTX_eip_OFFSET(%eax) 
	movl	(FRAME_OFFSET+2)*4+CTX_cs_OFFSET(%ebp) ,  %ebx 
	movl	%ebx ,  CTX_cs_OFFSET(%eax) 
	movl	(FRAME_OFFSET+2)*4+CTX_eflags_OFFSET(%ebp) ,  %ebx 
	movl	%ebx ,  CTX_eflags_OFFSET(%eax) 

	/* 1 dummy int added in the linux signal frame */

	movl	(FRAME_OFFSET+3)*4+CTX_ss_OFFSET(%ebp) ,  %ebx 
	movl	%ebx ,  CTX_ss_OFFSET(%eax) 

nosaveIT:  

	/* eax is used to save @ of newcontext */

	movl	12(%ebp), %eax 
	/* eax gets ic of new context*/
	movl	(%eax), %eax 

	/* movl	CTX_gs_OFFSET(%eax) ,  %ebx */
	/* movl	%ebx ,  FRAME_OFFSET*4+CTX_gs_OFFSET(%ebp)*/ 
	/* movl	CTX_fs_OFFSET(%eax) ,  %ebx */
	/* movl	%ebx ,  FRAME_OFFSET*4+CTX_fs_OFFSET(%ebp)*/ 
	/* movl	CTX_es_OFFSET(%eax) ,  %ebx */
	/* movl	%ebx ,  FRAME_OFFSET*4+CTX_es_OFFSET(%ebp)*/ 
	/* movl	CTX_ds_OFFSET(%eax) ,  %ebx */
	/* movl	%ebx ,  FRAME_OFFSET*4+CTX_ds_OFFSET(%ebp)*/ 
	movl	CTX_edi_OFFSET(%eax) ,  %ebx 
	movl	%ebx ,  FRAME_OFFSET*4+CTX_edi_OFFSET(%ebp) 
	movl	CTX_esi_OFFSET(%eax) ,  %ebx 
	movl	%ebx ,  FRAME_OFFSET*4+CTX_esi_OFFSET(%ebp) 
	movl	CTX_ebp_OFFSET(%eax) ,  %ebx 
	movl	%ebx ,  FRAME_OFFSET*4+CTX_ebp_OFFSET(%ebp) 
	movl	CTX_esp_OFFSET(%eax) ,  %ebx 
	movl	%ebx ,  FRAME_OFFSET*4+CTX_esp_OFFSET(%ebp) 
	movl	CTX_ebx_OFFSET(%eax) ,  %ebx 
	movl	%ebx ,  FRAME_OFFSET*4+CTX_ebx_OFFSET(%ebp) 
	movl	CTX_edx_OFFSET(%eax) ,  %ebx 
	movl	%ebx ,  FRAME_OFFSET*4+CTX_edx_OFFSET(%ebp) 
	movl	CTX_ecx_OFFSET(%eax) ,  %ebx 
	movl	%ebx ,  FRAME_OFFSET*4+CTX_ecx_OFFSET(%ebp) 
	movl	CTX_eax_OFFSET(%eax) ,  %ebx 
	movl	%ebx ,  FRAME_OFFSET*4+CTX_eax_OFFSET(%ebp) 
	
	/* 2 dummy ints added in the linux signal frame */

	movl	CTX_eip_OFFSET(%eax) ,  %ebx 
	movl	%ebx ,  (FRAME_OFFSET+2)*4+CTX_eip_OFFSET(%ebp) 
	/* movl	CTX_cs_OFFSET(%eax) ,  %ebx  */
	/* movl	%ebx ,  (FRAME_OFFSET+2)*4+CTX_cs_OFFSET(%ebp)  */
	movl	CTX_eflags_OFFSET(%eax) ,  %ebx 
	movl	%ebx ,  (FRAME_OFFSET+2)*4+CTX_eflags_OFFSET(%ebp) 
	
	/* 1 dummy int added in the linux signal frame */

	/* movl	CTX_ss_OFFSET(%eax) ,  %ebx */
	/* movl	%ebx ,  (FRAME_OFFSET+3)*4+CTX_ss_OFFSET(%ebp) */
	

	popl	%ebp
	ret
	.size	tpl_switch_context_from_it, .-tpl_switch_context_from_it

.endif /* __TPL_GET_LINUX_FRAME_OFFSET__ */

