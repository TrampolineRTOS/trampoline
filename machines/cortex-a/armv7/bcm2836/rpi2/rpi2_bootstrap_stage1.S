#include "armv7_macros.h"

.extern __SP_fiq_
.extern __SP_irq_
.extern __SP_mon_
.extern __SP_und_
.extern __SP_abt_
.extern __SP_svc_
.extern __SP_hyp_
.extern __SP_usr_

#define ARMV7_CP15_C0_MPID_MPE                (1 << 31)
#define ARMV7_CP15_C0_MPID_U_UNIPROCESSOR     (1 << 30)
#define ARMV7_CP15_C0_MPID_U_MULTIPROCESSOR   (0 << 30)
#define ARMV7_CP15_C0_MPID_CLUSTERID_MASK     (0xF << 8)
#define ARMV7_CP15_C0_MPID_CPUID_MASK         (3 << 0)

#define ARM_MODE_BITS                         (0x0000001F)
#define ARM_MODE_SYS                          (0x1F)
#define RPI2_VECTOR_TABLE_BASE                (0x00001000)

.section .startup_code, "ax"
/* ---------------------------------------------------------------- */
/**
 * @internal
 *
 * _start
 *
 * _start is the first function called after a cpu reset.
 * This function must be referenced in the link script with the keyword ENTRY:
 * ENTRY(_start)
 *
 * On Raspberry Pi 2 the cpu is started by the GPU.
 * The GPU starts the cpu either in Hypervisor or Supervisor mode, depending
 * on the configuration written in the file config.txt that is on the sd card.
 *
 * @param
 *
 * We can have parameters if the binary file is launched with a bootloader.
 * Those parameters shall be compliant with u-boot and linux boot process :
 * r0 - Zero
 * r1 - Machine Type (Raspberry Pi 2 or BCM2709 = 0x0C42)
 * r2- Address of the ARM Tags structure (Normally 0x0100)
 *
 */
.global _start
_start:
  /* Save parameters
   * r0 - Zero
   * r1 - Machine Type (Raspberry Pi 2 or BCM2709 = 0x0C42)
   * r2 - Address of the ARM Tags structure (Normally 0x0100)
   * ldr r3, .LARMTagsAddress
   * cmp r2, #0
   * moveq r2, #0x0100
   * str r2, [r3]
   *
   * Save the ARM Machine Type that the bootloader should have passed to us
   * in R1. See: http://www.arm.linux.org.uk/developer/machines/
   * ldr r3, .LARMMachineType
   * str r1, [r3]
   */

  /* Save the ARM Boot Mode that the CPU was in at startup */
  ldr r3, StartupBootMode
  mrs r0, cpsr
  and r0, r0, #0x0000001F /* #ARM_MODE_BITS mask */
  str r0, [r3]

  /* Save the Vector Base Address that was current at startup */
  ldr r3, StartupBootVectors
  Cop_Read_VBAR(r0)
  str r0, [r3]

  /* Continue execution at the StartupHandler */
  b startup

  /* Holds the CPU startup mode */
StartupBootMode:
  .long 0x0
  /* Holds the Vector Base Address on startup */
StartupBootVectors:
  .long 0x0
  /* Holds the Vector Base Address on startup */
  /*
.LARMTagsAddress:
  .long ARMTagsAddress
.LARMMachineType:
  .long ARMMachineType*/
_start_end:

/* ---------------------------------------------------------------- */
/**
 * @internal
 *
 * startup
 *
 * startup function does the following steps:
 * - Check start mode and switch to Supervisor Mode
 * - Setup stacks
 * - Switch the CPU to Secure Mode
 * - Invalidate Caches
 * - Invalidate TLB
 * - Switch to System Mode
 * - Copy the definitive Vector Table to RPI2_VECTOR_TABLE_BASE
 * - Set the Vector Base Address register in the System Control
 *
 * @param
 *
 * None
 *
 */
startup:
  /* */
  bl startupSwitchMode
  /* */
  bl setupStacks
  /* */
  bl startupSecureMode
  /* Invalidate all Caches before starting the boot process */
  bl ARMv7InvalidateCache
  bl ARMv7InvalidateL1DataCache
  bl ARMv7CleanAndInvalidateDataCache

  /* Invalidate the TLB before starting the boot process */
  bl ARMv7InvalidateTLB
  bl ARMv7InvalidateDataTLB
  bl ARMv7InvalidateInstructionTLB

  /*
   * Change to System Mode and ensure all interrupts are disabled
   * so the ARM processor is in a known state.
   */
  bl switchToSysMode
  /* Disable interrupts and switch to System mode */
  cpsid if, #ARM_MODE_SYS

  /* Copy the ARM exception table from Vectors to the vector base address */
  mov r0, #RPI2_VECTOR_TABLE_BASE
  ldr r1, =vectors
  ldmia r1!, {r2-r9}
  stmia r0!, {r2-r9}
  ldmia r1!, {r2-r9}
  stmia r0!, {r2-r9}
  /*
   * Set the Vector Base Address register in the System Control
   * register to the address of the vector table base above.
   */
  mov r0, #RPI2_VECTOR_TABLE_BASE
  Cop_Write_VBAR(r0)

  /* Branch to second stage boot process */
  b tpl_armv7_bootstrap_stage2
startup_end:

/* ---------------------------------------------------------------- */
/**
 * @internal
 *
 * setupStacks
 *
 * setupStacks function initializes stacks:
 * - __SP_fiq_top_ : not used, not initialized
 * - __SP_irq_top_ :
 * - __SP_mon_top_ : not used, not initialized
 * - __SP_und_top_ :
 * - __SP_abt_top_ :
 * - __SP_svc_top_ :
 * - __SP_hyp_top_ :
 * - __SP_usr_top_ :
 *
 * @param
 *
 * None
 *
 */
 setupStacks:
  /* ldr r0, =__SP_fiq_ */
  /* msr SP_fiq, r0 */
  ldr r0, =__SP_irq_top_
  msr SP_irq, r0
  /* ldr r0, =__SP_mon_ */
  /* msr SP_mon, r0 */
  /* ldr r0, =__SP_und_ */
  /* msr SP_und, r0 */
  /* ldr r0, =__SP_abt_ */
  /* msr SP_abt, r0 */
  /*  La pile pour le mode Superviseur est positionnée avant */
  ldr r0, =__SP_svc_top_
  msr SP_svc, r0
  /* ldr r0, =__SP_hyp_ */
  /* msr SP_hyp, r0 */
  ldr r0, =__SP_usr_top_
  msr SP_usr, r0

  bx lr
setupStacks_end:

/* ---------------------------------------------------------------- */
/**
 * @internal
 *
 * startupSwitchMode
 *
 * startupSwitchMode function tests the current mode of the cpu. If the mode
 * is Hypervisor Mode then we switch to Supervisor Mode else we return.
 * Switching to Supervisor Mode from Hypervisor Mode is explained in :
 * B1.3.4 ELR_hyp
 *
 * @param
 *
 * None
 *
 */
startupSwitchMode:
  /* Get the CPSR */
  mrs r0, cpsr
  /* Test for HYP mode */
  eor r0, r0, #0x1A /* #ARM_MODE_HYP */
  tst r0, #0x1F /* #ARM_MODE_BITS */
  /* Clear the mode bits */
  bic r0, r0, #0x1F /* #ARM_MODE_BITS */
  /* Mask IRQ/FIQ bits and set SVC mode */
  orr r0, r0, #(0x80 | 0x40 | 0x13) /* #(ARM_I_BIT | ARM_F_BIT | ARM_MODE_SVC) */

  /* Return if not in HYP mode */
  bne startupSwitchMode_noSwitch

  /* Mask the Abort bit */
  orr r0, r0, #0x100 /* #ARM_A_BIT */
  /* Load the SPSR */
  msr spsr_cxsf, r0
  /* Return to SVC mode */
  msr ELR_hyp, lr
  eret
startupSwitchMode_noSwitch:
  /* Set the CPSR (C fields) */
  msr cpsr_c, r0

  /* Return to startup */
  bx lr
startupSwitchMode_end:

/* ---------------------------------------------------------------- */
/**
 * @internal
 *
 * startupSecureMode
 *
 * startupSecureMode function
 *
 * @param
 *
 * None
 *
 */
startupSecureMode:
  /* Check the secure boot configuration */
  mov r0, #0x1 /* #RPI2_SECURE_BOOT */
  cmp r0, #0
  beq startupSecureMode_noSecure
  /* Attempt to switch back to secure world by performing a */
  /* secure monitor call to the Secure Monitor handler. */
  /* Get the vector base address from the System Control register. */
  Cop_Read_VBAR(r0)
  /* Get the address of the secure vectors */
  ldr r1, =secureVectors
  /* Copy the secure vector table */
  ldmia r1!, {r2-r9}
  stmia r0!, {r2-r9}
  ldmia r1!, {r2-r9}
  stmia r0!, {r2-r9}
  /* Clean Data Cache MVA */
  mov r12, #0
  Cop_Write_DCCMVAC(r12)
  /* Perform a data synchronisation barrier */
  dsb
  /* Invalidate Instruction Cache */
  mov r12, #0
  Cop_Write_ICIALLU(r12)
  /* Flush Branch Target Cache */
  mov r12, #0
  Cop_Write_BPIALLIS(r12)
  /* Perform a data synchronisation barrier */
  dsb
  /* Perform an instruction synchronisation barrier */
  isb
  /* Perform a secure monitor call (Not supported by the FPC compiler) */
  smc #0
startupSecureMode_noSecure:
  /* Return to startup */
  bx lr
startupSecureMode_end:

/* ---------------------------------------------------------------- */
/**
 * @internal
 *
 * switchToSysMode
 *
 * switchToSysMode function
 *
 * @param
 *
 * None
 *
 */
switchToSysMode:
  /* Disable interrupts and switch to SYS mode */
  cpsid if, #ARM_MODE_SYS

  /* Copy the ARM exception table from Vectors to the vector base address. */
  mov r0, #RPI2_VECTOR_TABLE_BASE
  ldr r1, =vectors
  ldmia r1!, {r2-r9}
  stmia r0!, {r2-r9}
  ldmia r1!, {r2-r9}
  stmia r0!, {r2-r9}
  /* Set the Vector Base Address register in the System Control */
  /* register to the address of the vector table base above. */
  mov r0, #RPI2_VECTOR_TABLE_BASE
  Cop_Write_VBAR(r0)
  /* Return to startup */
  bx lr
switchToSysMode_end:

/* ---------------------------------------------------------------- */
/**
 * @internal
 *
 * switchToUserMode
 *
 * switchToUserMode function
 *
 * @param
 *
 * None
 *
 */
switchToUserMode:
  cpsid if
  cps #0x1F /* #ARM_MODE_USR */
  /* Return to caller */
  bx lr
switchToUserMode_end:


/* ---------------------------------------------------------------- */
/**
 * @internal
 *
 * ARMv7InvalidateCache
 *
 * ARMv7InvalidateCache function
 *
 * @param
 *
 * None
 *
 */
.global ARMv7InvalidateCache
ARMv7InvalidateCache:
  /* Get the MPID register from the system control coprocessor CP15 */
  Cop_Read_MPID(r0)

  /* Mask off the Multiprocessor Extensions bit (MPE) */
  and r1, r0, #ARMV7_CP15_C0_MPID_MPE
  cmp r1, #0
  beq ARMv7InvalidateCache_LUniprocessor

  /* Mask off the Uniprocessor bit (U) */
  and r1, r0, #ARMV7_CP15_C0_MPID_U_UNIPROCESSOR
  cmp r1, #0
  bne ARMv7InvalidateCache_LUniprocessor

  /* Invalidate all instruction caches to PoU (Inner Shareable) */
  mov r12, #0
  Cop_Write_ICIALLUIS(r12)

  /* Perform a data synchronization barrier */
  dsb

  /* Branch to ARMv7InvalidateDataCache (Will return to caller via LR) */
  b ARMv7InvalidateDataCache

ARMv7InvalidateCache_LUniprocessor:
  /* Invalidate all instruction caches to PoU */
  mov r12, #0
  Cop_Write_ICIALLU(r12)

  /* Perform a data synchronization barrier */
  dsb

  /* Branch to ARMv7InvalidateDataCache (Will return to caller via LR) */
  b ARMv7InvalidateDataCache
ARMv7InvalidateCache_end:

/* ---------------------------------------------------------------- */
/**
 * @internal
 *
 * ARMv7InvalidateTLB
 *
 * ARMv7InvalidateTLB function performs an invalidate entire TLB operation
 * using the c8 (TLB Operations) register of system control coprocessor CP15
 * See page B3-138 of the ARMv7 Architecture Reference Manual
 *
 * @param
 *
 * None
 *
 */
.global ARMv7InvalidateTLB
ARMv7InvalidateTLB:
  /* Get the MPID register from the system control coprocessor CP15 */
  Cop_Read_MPID(r0)

  /* Mask off the Multiprocessor Extensions bit (MPE) */
  and r1, r0, #ARMV7_CP15_C0_MPID_MPE
  cmp r1, #0
  beq ARMv7InvalidateTLB_LUniprocessor

  /* Mask off the Uniprocessor bit (U) */
  and r1, r0, #ARMV7_CP15_C0_MPID_U_UNIPROCESSOR
  cmp r1, #0
  bne ARMv7InvalidateTLB_LUniprocessor

  /* Invalidate entire TLB (Unified/Inner Shareable) */
  mov r12, #0
  Cop_Write_TLBIALLIS(r12)

  /* Perform a data synchronization barrier */
  dsb

  /* Return to caller */
  bx lr

ARMv7InvalidateTLB_LUniprocessor:
  /* Invalidate entire TLB (Unlocked/Unified) */
  mov r12, #0
  Cop_Write_TLBIALLH(r12)
  /* Perform a data synchronization barrier */
  dsb
  /* Return to caller */
  bx lr
ARMv7InvalidateTLB_end:

/* ---------------------------------------------------------------- */
/**
 * @internal
 *
 * ARMv7InvalidateDataCache
 *
 * ARMv7InvalidateDataCache function perform an invalidate entire data
 * cache operation
 * See page B3-127 of the ARMv7 Architecture Reference Manual
 *
 * @param
 *
 * None
 *
 */
 ARMv7InvalidateDataCache:
  Cop_Read_CLIDR(r0)
  tst	r0, #0x07000000
  beq	ARMv7InvalidateDataCache_LDone
  mov	r3, #0			                 /* start with L1 */

ARMv7InvalidateDataCache_LStart:
 add	r2, r3, r3, lsr #1	             /* r2 = level * 3 / 2 */
 mov	r1, r0, lsr r2		             /* r1 = cache type */
 tst	r1, #6			                 /* is it unified or data? */
 beq	ARMv7InvalidateDataCache_LNext	                         /* nope, skip level */

 Cop_Write_CSSELR(r3)	     /* select cache level */
 isb
 Cop_Read_CCSIDR(r0)	     /* read CCSIDR */

 ubfx	ip, r0, #0, #3		             /* get linesize from CCSIDR */
 add	ip, ip, #4		                 /* apply bias */
 ubfx	r2, r0, #13, #15	             /* get numsets - 1 from CCSIDR */
 lsl	r2, r2, ip		                 /* shift to set position */
 orr	r3, r3, r2		                 /* merge set into way/set/level */
 mov	r1, #1
 lsl	r1, r1, ip		                 /* r1 = set decr */

 ubfx	ip, r0, #3, #10		             /* get numways - 1 from [to be discarded] CCSIDR */
 clz	r2, ip			                 /* number of bits to MSB of way */
 lsl	ip, ip, r2		                 /* shift by that into way position */
 mov	r0, #1
 lsl	r2, r0, r2		                 /* r2 now contains the way decr */
 mov	r0, r3 			                 /* get sets/level (no way yet) */
 orr	r3, r3, ip		                 /* merge way into way/set/level */
 bfc	r0, #0, #4		                 /* clear low 4 bits (level) to get numset - 1 */
 sub	r2, r2, r0		                 /* subtract from way decr */

/* r3 = ways/sets/level, r2 = way decr, r1 = set decr, r0 and ip are free */
ARMv7InvalidateDataCache_LLoop:
  Cop_Write_DCISW(r3)	                       /* invalidate line */
 cmp	r3, #15			                           /* are we done with this level (way/set == 0) */
 bls	ARMv7InvalidateDataCache_LNext	       /* yes, go to next level */
 ubfx	r0, r3, #4, #18		                     /* extract set bits */
 cmp	r0, #0			                           /* compare */
 subne	r3, r3, r1		                       /* non-zero?, decrement set # */
 subeq	r3, r3, r2		                       /* zero?, decrement way # and restore set count */
 b	ARMv7InvalidateDataCache_LLoop

ARMv7InvalidateDataCache_LNext:
 dsb
 Cop_Read_CLIDR(r0)	                        /* read CLIDR */
 ubfx	ip, r0, #24, #3		                    /* narrow to LoC */
 add	r3, r3, #2		                        /* go to next level */
 cmp	r3, ip, lsl #1		                    /* compare */
 blt	ARMv7InvalidateDataCache_LStart		    /* not done, next level (r0 == CLIDR) */

ARMv7InvalidateDataCache_LDone:
 mov	r0, #0			                         /* default back to cache level 0 */
 Cop_Write_CSSELR(r0)	                     /* select cache level */
 dsb
 isb
 /* Return to caller */
 bx lr
ARMv7InvalidateDataCache_end:

/* ---------------------------------------------------------------- */
/**
 * @internal
 *
 * ARMv7InvalidateL1DataCache
 *
 * ARMv7InvalidateL1DataCache function perform an invalidate entire L1
 * data cache operation
 * See page B3-127 of the ARMv7 Architecture Reference Manual
 *
 * @param
 *
 * None
 *
 */
 ARMv7InvalidateL1DataCache:
  Cop_Read_CLIDR(r0)	                    /* read CLIDR */
  and	r0, r0, #0x7		            /* check L1 */
  bxeq	lr			            /* return if no L1 cache */
  mov	r3, #0			            /* start with L1 */

  Cop_Write_CSSELR(r3)                      /* select cache level */
  isb
  Cop_Read_CCSIDR(r0)	                    /* read CCSIDR */

  ubfx	ip, r0, #0, #3		            /* get linesize from CCSIDR */
  add	ip, ip, #4		            /* apply bias */
  ubfx	r2, r0, #13, #15	            /* get numsets - 1 from CCSIDR */
  lsl	r2, r2, ip		            /* shift to set position */
  orr	r3, r3, r2		            /* merge set into way/set/level */
  mov	r1, #1
  lsl	r1, r1, ip		            /* r1 = set decr */

  ubfx	ip, r0, #3, #10		       /* get numways - 1 from [to be discarded] CCSIDR */
  clz	r2, ip			            /* number of bits to MSB of way */
  lsl	ip, ip, r2		            /* shift by that into way position */
  mov	r0, #1
  lsl	r2, r0, r2		            /* r2 now contains the way decr */
  mov	r0, r3 			            /* get sets/level (no way yet) */
  orr	r3, r3, ip		            /* merge way into way/set/level */
  bfc	r0, #0, #4		            /* clear low 4 bits (level) to get numset - 1 */
  sub	r2, r2, r0		            /* subtract from way decr */

/* r3 = ways/sets/level, r2 = way decr, r1 = set decr, r0 and ip are free */
ARMv7InvalidateL1DataCache_LLoop:
  Cop_Write_DCISW(r3)	                    /* invalidate line */
  cmp	r3, #15			          /* are we done with this level (way/set == 0) */
  bls	ARMv7InvalidateL1DataCache_LDone    /* yes, we've finished */
  ubfx	r0, r3, #4, #18		            /* extract set bits */
  cmp	r0, #0			            /* compare */
  subne	r3, r3, r1		            /* non-zero?, decrement set # */
  subeq	r3, r3, r2		        /* zero?, decrement way # and restore set count */
  b	ARMv7InvalidateL1DataCache_LLoop

ARMv7InvalidateL1DataCache_LDone:
  dsb
  mov	r0, #0			            /* default back to cache level 0 */
  Cop_Write_CSSELR(r0)	                    /* select cache level */
  dsb
  isb

  bx lr
ARMv7InvalidateL1DataCache_end:

ARMv7CleanAndInvalidateDataCache:
  Cop_Read_CLIDR(r0)	                      /* read CLIDR */
  tst	r0, #0x07000000
  bxeq	lr
  mov	r3, #0			              /* start with L1 */

ARMv7CleanAndInvalidateDataCache_LStart:
  add	r2, r3, r3, lsr #1	              /* r2 = level * 3 / 2 */
  mov	r1, r0, lsr r2		              /* r1 = cache type */
  tst	r1, #6			             /* is it unified or data? */
  beq	ARMv7CleanAndInvalidateDataCache_LNext /* nope, skip level */

  Cop_Write_CSSELR(r3)	                   /* select cache level */
  isb
  Cop_Read_CCSIDR(r0)	                      /* read CCSIDR */

  ubfx	ip, r0, #0, #3		                  /* get linesize from CCSIDR */
  add	ip, ip, #4		                        /* apply bias */
  ubfx	r2, r0, #13, #15	                  /* get numsets - 1 from CCSIDR */
  lsl	r2, r2, ip		                        /* shift to set position */
  orr	r3, r3, r2		                        /* merge set into way/set/level */
  mov	r1, #1
  lsl	r1, r1, ip		                        /* r1 = set decr */

  ubfx	ip, r0, #3, #10		       /* get numways - 1 from [to be discarded] CCSIDR */
  clz	r2, ip			                    /* number of bits to MSB of way */
  lsl	ip, ip, r2		                    /* shift by that into way position */
  mov	r0, #1
  lsl	r2, r0, r2		                        /* r2 now contains the way decr */
  mov	r0, r3 			                        /* get sets/level (no way yet) */
  orr	r3, r3, ip		                        /* merge way into way/set/level */
  bfc	r0, #0, #4		                        /* clear low 4 bits (level) to get numset - 1 */
  sub	r2, r2, r0		                        /* subtract from way decr */

/* r3 = ways/sets/level, r2 = way decr, r1 = set decr, r0 and ip are free */
ARMv7CleanAndInvalidateDataCache_LLoop:
  Cop_Write_DCCISW(r3)	                     /* clean and invalidate line */
  cmp	r3, #15			          /* are we done with this level (way/set == 0) */
  bls	ARMv7CleanAndInvalidateDataCache_LNext /* yes, go to next level */
  ubfx	r0, r3, #4, #18		                   /* extract set bits */
  cmp	r0, #0			                           /* compare */
  subne r3, r3, r1                           /* non-zero?, decrement */
  subeq	r3, r3, r2		        /* zero?, decrement way # and restore set count */
  b ARMv7CleanAndInvalidateDataCache_LLoop

ARMv7CleanAndInvalidateDataCache_LNext:
  dsb
  Cop_Read_CLIDR(r0)	                        /* read CLIDR */
  ubfx	ip, r0, #24, #3		                    /* narrow to LoC */
  add	r3, r3, #2		                          /* go to next level */
  cmp	r3, ip, lsl #1		                      /* compare */
  blt	ARMv7CleanAndInvalidateDataCache_LStart /* not done, next level (r0 == CLIDR) */

LARMv7CleanAndInvalidateDataCache_Done:
  mov	r0, #0			                  /* default back to cache level 0 */
  Cop_Write_CSSELR(r0)	                      /* select cache level */
  dsb
  isb
  bx lr
ARMv7CleanAndInvalidateDataCache_end:

/* ---------------------------------------------------------------- */
/**
 * @internal
 *
 * ARMv7InvalidateDataTLB
 *
 * ARMv7InvalidateDataTLB function perform
 *
 * @param
 *
 * None
 *
 */
ARMv7InvalidateDataTLB:
  /* Invalidate data TLB (Unlocked/Data) */
  mov r12, #0
  Cop_Write_DTLBIALL(r12)
  /* Perform a data synchronization barrier */
  dsb
  bx lr
ARMv7InvalidateDataTLB_end:

/* ---------------------------------------------------------------- */
/**
 * @internal
 *
 * ARMv7InvalidateDataTLB
 *
 * ARMv7InvalidateDataTLB function perform
 *
 * @param
 *
 * None
 *
 */
ARMv7InvalidateInstructionTLB:
  /* Invalidate instruction TLB (Unlocked/Instruction) */
  mov r12, #0
  Cop_Write_ITLBIALL(r12)
  /* Perform a data synchronization barrier */
  dsb
  bx lr
ARMv7InvalidateInstructionTLB_end:

/* ---------------------------------------------------------------- */
/**
 * @internal
 *
 * ARMv7InvalidateDataTLB
 *
 * ARMv7InvalidateDataTLB function perform
 *
 * @param
 *
 * None
 *
 */
.global reset_handler
reset_handler:
  bx lr
reset_handler_end:

/* ---------------------------------------------------------------- */
/**
 * @internal
 *
 * ARMv7InvalidateDataTLB
 *
 * ARMv7InvalidateDataTLB function perform
 *
 * @param
 *
 * None
 *
 */
.global undefined_handler
undefined_handler:
  push {r0-r12, lr}
  bl c_undefined_handler
  pop {r0-r12, lr}
  subs pc,lr,#4
undefined_handler_end:

/* ---------------------------------------------------------------- */
/**
 * @internal
 *
 * ARMv7InvalidateDataTLB
 *
 * ARMv7InvalidateDataTLB function perform
 *
 * @param
 *
 * None
 *
 */
.global prefetch_handler
prefetch_handler:
  push {r0-r12, lr}
  bl c_prefetch_handler
  pop {r0-r12, lr}
  subs pc,lr,#4
prefetch_handler_end:

/* ---------------------------------------------------------------- */
/**
 * @internal
 *
 * ARMv7InvalidateDataTLB
 *
 * ARMv7InvalidateDataTLB function perform
 *
 * @param
 *
 * None
 *
 */
.global data_handler
data_handler:
  push {r0-r12, lr}
  bl c_data_handler
  pop {r0-r12, lr}
  subs pc,lr,#8
data_handler_end:

/* ---------------------------------------------------------------- */
/**
 * @internal
 *
 * ARMv7InvalidateDataTLB
 *
 * ARMv7InvalidateDataTLB function perform
 *
 * @param
 *
 * None
 *
 */
.global reserved_handler
reserved_handler:
  push {r0-r12, lr}
  bl c_reserved_handler
  pop {r0-r12, lr}
  subs pc,lr,#4
reserved_handler_end:

/* ---------------------------------------------------------------- */
/**
 * @internal
 *
 * ARMv7InvalidateDataTLB
 *
 * ARMv7InvalidateDataTLB function perform
 *
 * @param
 *
 * None
 *
 */
.global fiq_handler
fiq_handler:
  push {r0-r12, lr}
  bl c_fiq_handler
  pop {r0-r12, lr}
  subs pc,lr,#4
fiq_handler_end:

/* ---------------------------------------------------------------- */
/**
 * @internal
 *
 * ARMv7InvalidateDataTLB
 *
 * ARMv7InvalidateDataTLB function perform
 *
 * @param
 *
 * None
 *
 */
.global smc_handler
smc_handler:
  Cop_Read_SCR(r1)
  bic r1, r1, #1
  Cop_Write_SCR(r1)
  movs pc, lr
smc_handler_end:

/* ---------------------------------------------------------------- */
/**
 * @internal
 *
 * ARMv7InvalidateDataTLB
 *
 * ARMv7InvalidateDataTLB function perform
 *
 * @param
 *
 * None
 *
 */
.global dummy
dummy:
  bx lr

  /* ---------------------------------------------------------------- */
  /**
   * @internal
   *
   * ARMv7InvalidateDataTLB
   *
   * ARMv7InvalidateDataTLB function perform
   *
   * @param
   *
   * None
   *
   */
.global enable_irq
enable_irq:
  mrs r0,cpsr
  bic r0,r0,#0x80
  msr cpsr_c,r0
  bx lr
enable_irq_end:
