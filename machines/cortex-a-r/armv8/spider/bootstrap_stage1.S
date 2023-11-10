.extern __SP_fiq_
.extern __SP_irq_
.extern __SP_mon_
.extern __SP_und_
.extern __SP_abt_
.extern __SP_svc_
.extern __SP_hyp_
.extern __SP_usr_

#define ARM_MODE_BITS                         (0x0000001F)

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
 * At boot time the processor is in Supervisor mode and interrupts are
 * disabled.
 *
 */
.global _start
_start:

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

  /* Init HSCTLR (Hyp System Control Register) */
//  ldr r0, = #0x30C5181A //FSY (HSCTLR_RES1 | SCTLR_I_BIT | SCTLR_C_BIT)
//  mcr p15, 4, r0, c1, c0, 0

  /* Init HACTLR: Enable EL1 access to all IMP DEF registers */
//  ldr r0, =HACTLR_INIT
//  mcr p15, 4, r0, c1, c0, 1

  /* Mask the Abort bit */
  orr r0, r0, #0x100 /* #ARM_A_BIT */
  /* Load the SPSR */
  msr spsr_cxsf, r0
  /* Return to SVC mode */

  ldr r0, =setupStacks
  msr elr_hyp, r0
  dsb
  isb
  eret

startupSwitchMode_noSwitch:
  /* Set the CPSR (C fields) */
  msr cpsr_c, r0


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
  /*  SVC stack is initialized before */
  ldr r0, =__SP_svc_top_
  msr SP_svc, r0
  /* ldr r0, =__SP_hyp_ */
  /* msr SP_hyp, r0 */
  ldr r0, =__SP_usr_top_
  msr SP_usr, r0

  /* Branch to second stage boot process */
  b tpl_bootstrap_stage2

/* ---------------------------------------------------------------- */
/**
 * @internal
 *
 * reset_handler
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
 * undefined_handler
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
 * prefetch_handler
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
 * data_handler
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
 * reserved_handler
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
 * fiq_handler
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
 * smc_handler
 *
 * @param
 *
 * None
 *
 */
.global smc_handler
smc_handler:
  //Cop_Read_SCR(r1)
  bic r1, r1, #1
  //Cop_Write_SCR(r1)
  movs pc, lr
smc_handler_end:

/* ---------------------------------------------------------------- */
/**
 * @internal
 *
 * dummy
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
   * enable_irq
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
