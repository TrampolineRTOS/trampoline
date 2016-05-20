/*
 * @file tpl_it_handler.s
 *
 * @section desc File description
 *
 * Trampoline external interrupt handler for PowerPC port
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright(c) IRCCyN 2005-2007
 * Autosar extension is copyright(c) IRCCyN and ESEO 2007
 * libpcl port is copyright(c) Jean-Francois Deverge 2006
 * ARM7 port is copyright(c) ESEO 2007
 * hcs12 port is copyright(c) Geensys 2007
 * MPC5674F port - copyright(c) 2016 propriété de l'IRT Saint Exupery, tous droits reservés
 *
 * Trampoline and its Autosar extension are protected by the
 * French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#include "tpl_os_definitions.h"
#include "tpl_os_application_def.h"
#include "tpl_os_kernel_stack.h"
#include "tpl_os_process_stack.h"
#include "tpl_assembler.h"
#include "tpl_app_define.h"

TPL_EXTERN  tpl_kern
TPL_EXTERN  tpl_it_table
TPL_EXTERN  tpl_previous_cpu_prio

TPL_EXTERN  tpl_save_context
TPL_EXTERN  tpl_load_context
TPL_EXTERN  tpl_kernel_mp
TPL_EXTERN  tpl_user_mp
TPL_EXTERN  tpl_set_process_mp
TPL_EXTERN  tpl_enter_kernel
TPL_EXTERN  tpl_leave_kernel
TPL_EXTERN  tpl_it_id
TPL_EXTERN  tpl_ack_irq
TPL_EXTERN  tpl_run_elected
TPL_EXTERN  tpl_set_cpu_prio

  .data
  .align  4
  /* 
   * Save returned value from called ISR routine.
   * Depending on this value, the tpl_ack_irq is executed in the end handler 
   * or delayed later when calling terminateISR2 service
   */
call_ack_irq:
  .long   0

  .text
  .section  .EI_vector CODE_ACCESS_RIGHT
  .global tpl_it_vector
tpl_it_vector:
/* ------------ VLE ---------------------------------------------------------*/
#if(WITH_VLE == YES)
  e_b   tpl_it_handler
/* ------------ NO VLE ------------------------------------------------------*/
#else
  b     tpl_it_handler
#endif
  .type tpl_it_vector,@function
  .size tpl_it_vector,$-tpl_it_vector


  .section  .EI_handler CODE_ACCESS_RIGHT
  .global tpl_it_handler

/*
 * tpl_it_handler should be called directly from the external interrupt
 * vector by an unconditional branch(relative or absolute)
 *
 * tpl_it_handler switches on the system stack and saves the registers
 * in the context of the process that was running when the interrupt was got
 * then it calls tpl_central_interrupt_handler
 * at last it restores the registers from the context of the current running
 * process(which might be different since tpl_central_interrupt_handler may
 * do a rescheduling).
 */
tpl_it_handler:

/* ------------ VLE ---------------------------------------------------------*/
#if(WITH_VLE == YES) 
  /*
   * When entering tpl_it_handler,we are on a process stack. Since
   * some registers are needed to work,they are saved on the process stack
   * using the same scheme as in a system call function
   *
   *          |              |
   *          +--------------+
   *  SP-> +0 |      r11     |
   *          +--------------+
   *       +4 |      r12     |
   *          +--------------+
   *       +8 |      lr      |
   *          +--------------+
   *      +12 |      cr      |
   *          +--------------+
   *      +16 |      r0      |
   *          +--------------+
   */
   
   /* 
    * MPC5674F_Porting_Modif: if hw mode for intc is used, r0 is saved when executing 
    * the it hw vector (in tpl_intc_hw_table.s) to get the id (stored in r0) 
    */ 
#if(INTC_HW_MODE == NO) 
  se_subi   r1,PS_FOOTPRINT
  e_stw     r0,PS_R0(r1)
#endif  
  e_stw     r11,PS_R11(r1)
  e_stw     r12,PS_R12(r1)
  mflr      r11
  e_stw     r11,PS_LR(r1)
  mfcr      r11
  e_stw     r11,PS_CR(r1)

  /*
   * Does the stuff to enter in kernel
   */
  e_bl      tpl_enter_kernel
 
  /*
   * Save r3 in the kernel stack. It is from here it will be get to be saved
   * in the context of the interrupted process	
   */
  e_stw     r3,KS_RETURN_CODE(r1)
  
  /* 
   * MPC5674F_Porting_Modif: Enable processor recognition 
   * of interrupts to pass eventual ISR1 interrupts (inevitably when HW mode is used).
   */
#if(INTC_HW_MODE == YES) 
  wrteei  1                        /* Set MSR[EE]=1  */
#endif  
  
  /*
   * Save the context of the running process.
   */
  e_lis     r11,TPL_HIG(tpl_kern)
  e_or2i    r11,TPL_LOW(tpl_kern)
  e_stw     r11,KS_KERN_PTR(r1) /* save the ptr for future use  */
  
  /*
   * Reset the tpl_need_switch variable to NO_NEED_SWITCH before
   * calling the handler This is needed because,beside tpl_schedule,
   * no service modify this variable. So an old value is retained
   */
  e_li      r12,NO_NEED_SWITCH
  e_stb     r12,24(r11)          /* MPC5674F_Porting_Modif : modify the offset (20->24) to point to need_switch field in the tpl_kern struct */
  
  /*
   * Save the context of the interrupted process
   * The pointer to the context is in r3
   */
  e_lwz     r3,0(r11)           /* get the context pointer */
  e_bl      tpl_save_context		
	
  /* 
   * MPC5674F_Porting_Modif: when using the INTC hw mode id has been 
   * stored in r0 before calling this handler. for the case of sw mode
   * id of the it is read from intc_iackr register 
   */    
#if(INTC_HW_MODE == YES)
  se_mr   r3,r0
#else  
  /*
   * Get the id of the interrupt
   * (it is returned in r3)
   */
  e_bl      tpl_it_id
#endif	
  
  /*
   * Get a pointer to the it table
   * This table is generated an can be found in tpl_app_config.c file
   */
  e_lis     r11,TPL_HIG(tpl_it_table)
  e_or2i    r11,TPL_LOW(tpl_it_table)
   
  /*
   * convert the it id to an offset. Each entry of the tpl_it_vector
   * uses 2 x 4 bytes words on a 32 bits PowerPC. The first word
   * id the function pointer of the it handler. The second word is
   * its parameter (so it is loaded in r3) 
   */
  e_slwi    r12,r3,3
  lwzx      r0,r11,r12
  e_addi    r12,r12,4
  mtlr      r0
  lwzx      r3,r11,r12
  /*
   * Call the IT routine
   */
  se_blrl

  /*
   * test tpl_need_switch to see if a rescheduling occured
   */
  e_lwz     r11,KS_KERN_PTR(r1)
  e_lbz     r12,24(r11)          /* MPC5674F_Porting_Modif : modified the offset(0->24) to point to need_switch field in the tpl_kern struct */
  e_andi.   r12,r12,NEED_SWITCH

  e_beq     no_context_switch

#if WITH_FLOAT == YES
  /*
   * TODO: HERE WE SHOULD HAVE THE CONTEXT SWITCH FOR FP REGISTERS
   */
#endif

#if WITH_MEMORY_PROTECTION == YES
  e_lwz     r11,KS_KERN_PTR(r1)
  e_lwz     r3,16(r11)    		   /* get the id of the process which get the cpu */
  e_bl      tpl_set_process_mp     /* set the memory protection scheme */
#endif

  /* MPC5674F_Porting_Modif : Add the set of instructions below to support the kernel modifications(tpl_run_elected call to get s_running task id) */ 
  se_li     r3,0                	/* Initially set save parameter to 0 to pass it as argument to tpl_run_elected (set later to 1 if necessary) */
  e_lwz     r11,KS_KERN_PTR(r1) 	/* Point to the tpl_kern struct */
  e_lbz     r12,24(r11)         	/* get tpl_kern[].need_switch */
  e_andi.   r12,r12,NEED_SAVE	
  e_beq     call_tpl_run_elected
  se_li     r3,1          			/* set save parameter to 1 */
call_tpl_run_elected:  
  e_bl      tpl_run_elected     	/* get s_running */
	
no_context_switch:
  /*
   * load the context of the running process. The pointer to the context
   * is in r3
   */
  e_lwz     r11,KS_KERN_PTR(r1)
  e_lwz     r3,0(r11)                         /* get s_running */
  e_bl      tpl_load_context

  /*
   * Get back registers that was saved in the system stack
   */
  e_lwz     r3,KS_RETURN_CODE(r1)             /* get r3 */

  /* 
   * MPC5674F_Porting_Modif: Disable processor recognition of interrupts. 
   * only when we have ISR1 -> INTC HW mode is used
   */
#if(INTC_HW_MODE == YES)    
  wrteei  0					   /* Set MSR[EE]=0  */
#endif  
  	
  e_bl      tpl_ack_irq    

no_prio_restore:   

  /*
   * does the stuff to leave the kernel
   */
  e_bl      tpl_leave_kernel

  /*  restore the registers before returning  */

  e_lwz     r0,PS_R0(r1)
  e_lwz     r11,PS_CR(r1)
  mtcr      r11
  e_lwz     r11,PS_LR(r1)
  mtlr      r11
  e_lwz     r12,PS_R12(r1)
  e_lwz     r11,PS_R11(r1)

  se_addi   r1,PS_FOOTPRINT

  se_rfi
/* ------------ NO VLE ------------------------------------------------------*/
#else

  /*
   * When entering tpl_it_handler,we are on a process stack. Since
   * some registers are needed to work,they are saved on the process stack
   * using the same scheme as in a system call function
   *
   *          |              |
   *          +--------------+
   *  SP-> +0 |      r11     |
   *          +--------------+
   *       +4 |      r12     |
   *          +--------------+
   *       +8 |      lr      |
   *          +--------------+
   *      +12 |      cr      |
   *          +--------------+
   *      +16 |      r0      |
   *          +--------------+
   */
  subi  r1,r1,PS_FOOTPRINT
  stw   r11,0(r1)
  stw   r12,4(r1)
  mflr  r11
  stw   r11,8(r1)
  mfcr  r11
  stw   r11,12(r1)
  stw   r0,16(r1)
  stw   r0,PS_R0(r1)

  /*
   * Does the stuff to enter in kernel
   */
  bl    tpl_enter_kernel

  /*
   * Save r3 in the kernel stack. It is from here it will be get to be saved
   * in the context of the interrupted process
   */
  stw   r3,KS_RETURN_CODE(r1)

  /*
   * Save the context of the running process.
   */
  lis   r11,TPL_HIG(tpl_kern)
  ori   r11,r11,TPL_LOW(tpl_kern)
  stw   r11,KS_KERN_PTR(r1) 	 /* save the ptr for future use  */
  /*
   * Reset the tpl_need_switch variable to NO_NEED_SWITCH before
   * calling the handler This is needed because,beside tpl_schedule,
   * no service modify this variable. So an old value is retained
   */
  li    r12,NO_NEED_SWITCH
  stb   r12,20(r11)

  /*
   * Save the context of the interrupted process
   * The pointer to the context is in r3
   */
  lwz   r3,4(r11)           /* get the context pointer */
  bl    tpl_save_context

  /*
   * Get the id of the interrupt
   * (it is returned in r3)
   */
  bl    tpl_it_id

  /*
   * Get a pointer to the it table
   * This table is generated an can be found in tpl_app_config.c file
   */
  lis   r11,TPL_HIG(tpl_it_table)
  ori   r11,r11,TPL_LOW(tpl_it_table)
  /*
   * convert the it id to an offset. Each entry of the tpl_it_vector
   * uses 2 x 4 bytes words on a 32 bits PowerPC. The first word
   * id the function pointer of the it handler. The second word is
   * its parameter(so it is loaded in r3)
   */
  slwi  r12,r3,3
  lwzx  r0,r11,r12
  mtlr  r0
  /* load the it handler parameter */
  addi  r12,r12,4
  lwzx  r3,r11,r12
  /*
   * Call the IT routine
   */
  blrl

  /*
   * test tpl_need_switch to see if a rescheduling occured
   */
  lwz   r11,KS_KERN_PTR(r1)
  lbz   r12,24(r11) 		/* modified 0 -> 24,point to need_switch field of tpl_kern struct */ 
  andi. r12,r12,NEED_SWITCH

  beq   no_context_switch

#if WITH_FLOAT == YES
  /*
   * TODO: HERE WE SHOULD HAVE THE CONTEXT SWITCH FOR FP REGISTERS
   */
#endif

#if WITH_MEMORY_PROTECTION == YES
  lwz   r11,KS_KERN_PTR(r1)
  lwz   r3,16(r11)    			  /* get the id of the process which get the cpu  */
  bl    tpl_set_process_mp        /* set the memory protection scheme */
#endif

no_context_switch:

  /*
   * load the context of the running process. The pointer to the context
   * is in r3
   */
  lwz   r11,KS_KERN_PTR(r1)
  lwz   r3,4(r11)                         /* get s_running */
  bl    tpl_load_context

  /*
   * r3 is restored(ie get back the return code)
   */
  e_lwz r3,KS_RETURN_CODE(r1)

  /*
   * does the stuff to leave the kernel
   */
  bl    tpl_leave_kernel

  /*  restore the registers befor returning  */

  lwz   r0,PS_R0(r1)
  lwz   r0,16(r1)
  lwz   r11,12(r1)
  mtcr  r11
  lwz   r11,8(r1)
  mtlr  r11
  lwz   r12,4(r1)
  lwz   r11,0(r1)

  addi  r1,r1,PS_FOOTPRINT

  rfi
#endif

  .type tpl_it_handler,@function
  .size tpl_it_handler,$-tpl_it_handler

