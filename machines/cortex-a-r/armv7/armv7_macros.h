/*
 * Read a CP15 register into an ARM register
 *
 * MRC p15, Op1, Rt, CRn, CRm, Op2
 *
 * Write a CP15 register from an ARM register
 *
 * MCR p15, Op1, Rt, CRn, CRm, Op2
 */

/*
 * VMSA CP15 c0 register summary, identification registers
 *
 */
/* CRn = c0 */
/* B4.1.41 CSSELR, Cache Size Selection Register, VMSA */
#define Cop_Write_CSSELR(r) \
  mcr	p15, #2, r, cr0, cr0, #0

/* B4.1.19 CCSIDR, Cache Size ID Registers, VMSA */
#define Cop_Read_CCSIDR(r) \
  mrc	p15, #1, r, cr0, cr0, #0

/* B4.1.20 CLIDR, Cache Level ID Register, VMSA */
#define Cop_Read_CLIDR(r) \
  mrc	p15, #1, r0, cr0, cr0, #1

/* B4.1.106 MPIDR, Multiprocessor Affinity Register, VMSA */
#define Cop_Read_MPID(r) \
  mrc p15, #0, r, cr0, cr0, #5

/*
 * VMSA CP15 c1 register summary, system control registers
 *
 */
/* CRn = c1 */
/* B4.1.129 SCR, Secure Configuration Register, Security Extensions */
#define Cop_Read_SCR(r) \
  mrc p15, 0, r, cr1, cr1, 0

  /* B4.1.129 SCR, Secure Configuration Register, Security Extensions */
#define Cop_Write_SCR(r) \
  mcr p15, 0, r1, cr1, cr1, 0

/*
 * VMSA CP15 c7 register summary, Cache maintenance, address translation,
 * and other functions
 * D12.7.10 CP15 c7, Cache and branch predictor operations
 * See table D12-8
 *
 */
/* ICIALLUIS, Invalidate all instruction caches to PoU Inner Shareable ø */
#define Cop_Write_ICIALLUIS(r) \
  mcr p15, #0, r, cr7, cr1, #0
/* ICIALLU, Invalidate all instruction caches to PoU */
#define Cop_Write_ICIALLU(r) \
  mcr p15, #0, r, cr7, cr5, #0

/* B4.1.17 BPIALLIS, Branch Predictor Invalidate All, Inner Shareable, VMSA */
#define Cop_Write_BPIALLIS(r) \
  mcr p15, #0, r, cr7, cr5, #6

/* B4.1.50 DCISW, Data Cache Invalidate by Set/Way, VMSA */
#define Cop_Write_DCISW(r) \
  mcr	p15, #0, r, cr7, cr6, #2

/* B4.1.46 DCCMVAC, Data Cache Clean by MVA to PoC, VMSA */
#define Cop_Write_DCCMVAC(r) \
  mcr p15, #0, r, cr7, cr10, #1

/* B4.1.45 DCCISW, Data Cache Clean and Invalidate by Set/Way, VMSA */
#define Cop_Write_DCCISW(r) \
  mcr	p15, #0, r, cr7, cr14, #2

/*
 * VMSA CP15 c8 register summary, TLB maintenance operations
 * D12.7.13 CP15 c8, VMSA TLB support
 * B3.10 TLB maintenance requirements
 *
 */
/* B4.1.138 TLBIALLIS, TLB Invalidate All, Inner Shareable, VMSA only */
#define Cop_Write_TLBIALLIS(r) \
  mcr p15, #0, r, cr8, cr3, #0

/* B4.1.98 ITLBIALL, Instruction TLB Invalidate All, VMSA only */
#define Cop_Write_ITLBIALL(r) \
  mcr p15, #0, r, cr8, cr5, #0

/* B4.1.53 DTLBIALL, Data TLB Invalidate All, VMSA only */
#define Cop_Write_DTLBIALL(r) \
  mcr p15, #0, r, cr8, cr6, #0

/* B4.1.136 TLBIALLH, TLB Invalidate All, Hyp mode, Virtualization Extensions */
#define Cop_Write_TLBIALLH(r) \
  mcr p15, #0, r, cr8, cr7, #0

/*
 * Security Extensions registers
 * VMSA CP15 c12
 *
 */
/* VBAR, Vector Base Address Register, B4.1.156 */
#define Cop_Read_VBAR(r) \
  mrc p15, #0, r, cr12, cr0, #0

#define Cop_Write_VBAR(r) \
  mcr p15, #0, r, cr12, cr0, #0
