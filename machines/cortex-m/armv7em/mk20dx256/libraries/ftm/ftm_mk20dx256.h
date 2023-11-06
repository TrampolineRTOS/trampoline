/**
 * @file ftm_mk20dx256.h
 *
 * @section descr File description
 *
 * mk20dx256 fonctions to toy with the FTM: FlexTimer Module
 * Check page 251, 257 and chapter 36, pages 769-900 of the mk20dx256 manual
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) CNRS, University of Nantes, Ecole Centrale de Nantes
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the GNU Public Licence V2.
 * Check the LICENSE file in the root directory of Trampoline
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#ifndef FTM_MK20DX256_H
#define FTM_MK20DX256_H

#include "tpl_compiler.h"
#include "tpl_os_std_types.h"
#include "tpl_machine.h"
#include "tpl_os_definitions.h"

#include "mk20dx256.h"

typedef struct {
  VAR(uint32, TYPEDEF) FTM_CH_CSC; /**< Channel status and control */
  VAR(uint32, TYPEDEF) FTM_CH_CV;  /**< Channel value              */
} ftm_channel;

typedef struct {
  VAR(uint32, TYPEDEF) FTM_SC;          /**< FTM status and control         */
  VAR(uint32, TYPEDEF) FTM_CNT;         /**< FTM counter                    */
  VAR(uint32, TYPEDEF) FTM_MOD;         /**< FTM modulo                     */
  VAR(ftm_channel, TYPEDEF) FTM_CH[8];  /**< FTM channels                   */
  VAR(uint32, TYPEDEF) FTM_CNTIN;       /**< FTM counter initial value      */
  VAR(uint32, TYPEDEF) FTM_STATUS;      /**< FTM capture and compare status */
  VAR(uint32, TYPEDEF) FTM_MODE;        /**< FTM features mode selection    */
  VAR(uint32, TYPEDEF) FTM_SYNC;        /**< FTM synchronization            */
  VAR(uint32, TYPEDEF) FTM_OUTINIT;     /**< FTM initial state ch outputs   */
  VAR(uint32, TYPEDEF) FTM_OUTMASK;     /**< FTM ch outputs mask            */
  VAR(uint32, TYPEDEF) FTM_COMBINE;     /**< FTM fcts for linked channels   */
  VAR(uint32, TYPEDEF) FTM_DEADTIME;    /**< FTM deadtime insertion control */
  VAR(uint32, TYPEDEF) FTM_EXTTRIG;     /**< FTM external trigger           */
  VAR(uint32, TYPEDEF) FTM_POL;         /**< FTM channel polarity           */
  VAR(uint32, TYPEDEF) FTM_FMS;         /**< FTM fault mode status          */
  VAR(uint32, TYPEDEF) FTM_FILTER;      /**< FTM input capture filter ctrl  */
  VAR(uint32, TYPEDEF) FTM_FLTCTRL;     /**< FTM fault ctrl                 */
  VAR(uint32, TYPEDEF) FTM_QDCTRL;      /**< FTM quad decoder ctrl & status */
  VAR(uint32, TYPEDEF) FTM_CONF;        /**< FTM configuration              */
  VAR(uint32, TYPEDEF) FTM_FLTPOL;      /**< FTM fault input polarity       */
  VAR(uint32, TYPEDEF) FTM_SYNCONF;     /**< FTM synchronization conf       */
  VAR(uint32, TYPEDEF) FTM_INVCTRL;     /**< FTM inverting control          */
  VAR(uint32, TYPEDEF) FTM_SWOCTRL;     /**< FTM software output control    */
  VAR(uint32, TYPEDEF) FTM_PWMLOAD;     /**< FTM PWM load                   */
} ftm;

static CONSTP2VAR(ftm, OS_CONST, OS_VAR) ftm_adress[3] = {
  (ftm *)0x40038000,
  (ftm *)0x40039000,
  (ftm *)0x400B8000
};

/*
 * So access to a FTM is done using FTM_TIMER(n). n being 0, 1 or 2
 */
#define FTM_TIMER(n)  (*ftm_adress[n])

/**
 * Enable clock gating for the FTM.
 *
 * @param timer The ftm number in range 0:2
 *
 * @return E_OK       timer is in range 0:2
 * @return E_OS_VALUE timer is out of range
 *
 * For FTM0 and FTM1, this is done by setting bit SIM_SCGC6_FTM0 to 1 or
 * SIM_SCGC6_FTM1 to 1 in the SIM_SCGC6 register.
 *
 * For FTM2, this is done by setting bit SIM_SCGC3_FTM2 in SIM_SCGC3 register.
 *
 * See pages 251 and 257 of the mk20dx256 manual.
 *
 * AT RESET the ftm modules clock gating is disabled
 */
INLINE_FUNC(tpl_status, OS_CODE) FTMEnableClock(
  CONST(uint32, AUTOMATIC) timer)
{
  if (timer > 2) return E_OS_VALUE;
  if      (timer == 0) SIM_SCGC6 |= SIM_SCGC6_FTM0;
  else if (timer == 1) SIM_SCGC6 |= SIM_SCGC6_FTM1;
  else if (timer == 2) SIM_SCGC3 |= SIM_SCGC3_FTM2;
  return E_OK;
}

/**
 * Disable clock gating for the FTM.
 *
 * @param timer The ftm number in range 0:2
 *
 * @return E_OK       timer is in range 0:2
 * @return E_OS_VALUE timer is out of range
 *
 * For FTM0 and FTM1, this is done by clearing bit SIM_SCGC6_FTM0 or
 * SIM_SCGC6_FTM1 in the SIM_SCGC6 register.
 *
 * For FTM2, this is done by clearing bit SIM_SCGC3_FTM2 in SIM_SCGC3 register.
 *
 * See pages 251 and 257 of the mk20dx256 manual.
 *
 * AT RESET the ftm modules clock gating is disabled
 */
INLINE_FUNC(tpl_status, OS_CODE) FTMDisableClock(
  CONST(uint32, AUTOMATIC) timer)
{
  if (timer > 2) return E_OS_VALUE;
  if      (timer == 0) SIM_SCGC6 &= ~SIM_SCGC6_FTM0;
  else if (timer == 1) SIM_SCGC6 &= ~SIM_SCGC6_FTM1;
  else if (timer == 2) SIM_SCGC3 &= ~SIM_SCGC3_FTM2;
  return E_OK;
}

/**
 *
 * Enable access to the FTM registers on AIPS0 peripheral bridge in
 * unprivileged thread mode
 *
 * @param timer The ftm number in range 0:2
 *
 * @return E_OK       timer is in range 0:2
 * @return E_OS_VALUE timer is out of range
 *
 * This is done by setting bits SP, WP et TP to 0 in corresponding PACR
 * register.
 * - PACRH of AIPS0, slot 0 for FTM0
 * - PACRH of AIPS0, slot 1 for FTM1
 * - PACRH of AIPS1, slot 0 for FTM2
 *
 * See pages 147 and 345-361 of the mk20dx256 manual.
 */
INLINE_FUNC(tpl_status, OS_CODE) FTMEnableUserAccess(
  CONST(uint32, AUTOMATIC) timer)
{
  if (timer > 2) return E_OS_VALUE;
  if (timer < 2)
  {
    /* for FTM0 and FTM1, slot corresponds to the timer # */
    AIPS0_PACRH &=
      ~(AIPS_PACR_SP(timer) | AIPS_PACR_WP(timer) | AIPS_PACR_TP(timer));
  }
  else
  {
    /* for FTM2 */
    AIPS1_PACRH &= ~(AIPS_PACR_SP(0) | AIPS_PACR_WP(0) | AIPS_PACR_TP(0));
  }
  return E_OK;
}

/**
 *
 * Enable the field write protection in FTM registers
 *
 * @param timer   The FTM number in range 0:2
 *
 * @return E_OK       timer is in range 0:2
 * @return E_OS_VALUE timer is out of range
 *
 * This is done by clearing MODE[WPDIS]
 *
 * See page 790 of the mk20dx256 manual.
 */
INLINE_FUNC(tpl_status, OS_CODE) FTMEnableProtection(
  CONST(uint32, AUTOMATIC) timer)
{
  if (timer > 2) return E_OS_VALUE;
  FTM_TIMER(timer).FTM_MODE &= ~FTM_MODE_WPDIS;
  return E_OK;
}

/**
 *
 * Disable the field write protection in FTM registers
 *
 * @param timer   The FTM number in range 0:2
 *
 * @return E_OK       timer is in range 0:2
 * @return E_OS_VALUE timer is out of range
 *
 * This is done by setting MODE[WPDIS]
 *
 * See page 790 of the mk20dx256 manual.
 */
INLINE_FUNC(tpl_status, OS_CODE) FTMDisableProtection(
  CONST(uint32, AUTOMATIC) timer)
{
  if (timer > 2) return E_OS_VALUE;
  FTM_TIMER(timer).FTM_MODE |= FTM_MODE_WPDIS;
  return E_OK;
}

/**
 *
 * Return true if the timer has overflown
 *
 * @param timer   The FTM number in range 0:2
 *
 * @return TRUE   if TOF bit is set, FALSE otherwise
 *                if the timer is in range 0:2
 * @return FALSE  if the timer is out of range
 *
 * This is done by reading the TOF bit.
 *
 * See page 780 the mk20dx256 manual.
 */
INLINE_FUNC(tpl_bool, OS_CODE) FTMOverflow(
  CONST(uint32, AUTOMATIC) timer)
{
  if (timer < 3)
  {
    /* Get a boolean result according to TOF bit */
    CONST(tpl_bool, AUTOMATIC) overflow =
      (FTM_TIMER(timer).FTM_SC & FTM_SC_TOF) != 0;
    return overflow;
  }
  else return FALSE;
}

/**
 *
 * Acknowledge the interrupt by reading SC sans writing a 0 in
 * the TOF bit.
 *
 * @param timer   The FTM number in range 0:2
 *
 * @return TRUE   if TOF bit is set, FALSE otherwise
 * @return FALSE  if the timer is out of range
 *
 * See page 780 the mk20dx256 manual.
 */
INLINE_FUNC(tpl_bool, OS_CODE) FTMAcknowledgeTimerInterrupt(
  CONST(uint32, AUTOMATIC) timer)
{
  if (timer < 3)
  {
    /* Get a boolean result according to TOF bit */
    CONST(tpl_bool, AUTOMATIC) overflow =
      (FTM_TIMER(timer).FTM_SC & FTM_SC_TOF) != 0;
    /* Reset the TOF bit */
    FTM_TIMER(timer).FTM_SC &= ~FTM_SC_TOF;
    return overflow;
  }
  else return FALSE;
}

/**
 * Enable the FTM timer n interrupt.
 *
 * @param timer The FTM number in range 0:2
 *
 * @return E_OK       timer is in range 0:2
 * @return E_OS_VALUE timer is out of range
 *
 * This is done by setting bit TOIE to 1 in the FTM_SCn register
 * See page 781 of the mk20dx256 manual.
 */
INLINE_FUNC(tpl_status, OS_CODE) FTMEnableTimerInterrupt(
  CONST(uint32, AUTOMATIC) timer)
{
  if (timer > 2) return E_OS_VALUE;
  FTM_TIMER(timer).FTM_SC |= FTM_SC_TOIE;
  return E_OK;
}

/**
 * Disable the FTM timer n interrupt.
 *
 * @param timer The FTM number in range 0:2
 *
 * @return E_OK       timer is in range 0:2
 * @return E_OS_VALUE timer is out of range
 *
 * This is done by setting bit TOIE to 0 in the FTM_SCn register
 * See page 781 of the mk20dx256 manual.
 */
INLINE_FUNC(tpl_status, OS_CODE) FTMDisableTimerInterrupt(
  CONST(uint32, AUTOMATIC) timer)
{
  if (timer > 2) return E_OS_VALUE;
  FTM_TIMER(timer).FTM_SC &= ~FTM_SC_TOIE;
  return E_OK;
}

/**
 * Enable the timer by setting a clock source
 *
 * @param timer the FTM number in range 0:2
 * @param clock the clock source in range 0:3
 *
 * @return E_OK         args are ok
 * @return E_OS_VALUE   timer is out of range
 * @return E_OS_NOFUNC  clock source is not in range 0:3
 *
 * See page 781 of the mk20dx256 manual.
 */
#define FTM_NoClock             (0x00ul)
#define FTM_SystemClock         (0x01ul)
#define FTM_FixedFrequencyClock (0x02ul)
#define FTM_ExternalClock       (0x03ul)

INLINE_FUNC(tpl_status, OS_CODE) FTMSetClockSource(
  CONST(uint32, AUTOMATIC) timer,
  CONST(uint32, AUTOMATIC) clock)
{
  if (timer > 2) return E_OS_VALUE;
  if (clock > 3) return E_OS_NOFUNC;
  FTM_TIMER(timer).FTM_SC &= ~FTM_SC_CLKS(0x03); /* reset field to no clock */
  FTM_TIMER(timer).FTM_SC |= FTM_SC_CLKS(clock);
  return E_OK;
}

/**
 * Disable the timer by setting the clock source to no clock (0)
 *
 * @param timer the FTM number in range 0:2
 *
 * @return E_OK         timer is in range 0:2
 * @return E_OS_VALUE   timer is out of range
 *
 * See page 781 of the mk20dx256 manual.
 */
INLINE_FUNC(tpl_status, OS_CODE) FTMStopCounter(
  CONST(uint32, AUTOMATIC) timer)
{
  if (timer > 2) return E_OS_VALUE;
  FTM_TIMER(timer).FTM_SC &= ~FTM_SC_CLKS(0x03); /* reset field to no clock */
  return E_OK;
}

/**
 * Set the timer counter in up counting mode
 *
 * @param timer the FTM number in range 0:2
 *
 * @return E_OK         timer is in range 0:2
 * @return E_OS_VALUE   timer is out of range
 *
 * See page 781 of the mk20dx256 manual.
 */
INLINE_FUNC(tpl_status, OS_CODE) FTMSetUpCounting(
  CONST(uint32, AUTOMATIC) timer)
{
  if (timer > 2) return E_OS_VALUE;
  FTM_TIMER(timer).FTM_SC &= ~FTM_SC_CPWMS; /* CPWMS = 0 */
  return E_OK;
}

/**
 * Set the timer counter in up-down counting mode
 *
 * @param timer the FTM number in range 0:2
 *
 * @return E_OK         timer is in range 0:2
 * @return E_OS_VALUE   timer is out of range
 *
 * See page 781 of the mk20dx256 manual.
 */
INLINE_FUNC(tpl_status, OS_CODE) FTMSetUpDownCounting(
  CONST(uint32, AUTOMATIC) timer)
{
  if (timer > 2) return E_OS_VALUE;
  FTM_TIMER(timer).FTM_SC |= FTM_SC_CPWMS; /* CPWMS = 1 */
  return E_OK;
}

/**
 * Set the timer counter prescaler
 *
 * @param timer the FTM number in range 0:2
 * @param prescaler in range 0:7
 *
 * @return E_OK         timer is in range 0:2
 * @return E_OS_VALUE   timer is out of range
 * @return E_OS_NOFUNC  prescaler is out of range
 *
 * See page 781 of the mk20dx256 manual.
 */

/* Corresponding prescaler values */
#define FTM_PS_1    (0x00ul)
#define FTM_PS_2    (0x01ul)
#define FTM_PS_4    (0x02ul)
#define FTM_PS_8    (0x03ul)
#define FTM_PS_16   (0x04ul)
#define FTM_PS_32   (0x05ul)
#define FTM_PS_64   (0x06ul)
#define FTM_PS_128  (0x07ul)

INLINE_FUNC(tpl_status, OS_CODE) FTMSetPrescaler(
  CONST(uint32, AUTOMATIC) timer,
  CONST(uint32, AUTOMATIC) prescaler)
{
  if (timer > 2) return E_OS_VALUE;
  FTM_TIMER(timer).FTM_SC &= ~FTM_SC_PS(7);          /* Reset prescaler to 0 */
  FTM_TIMER(timer).FTM_SC |= FTM_SC_PS(prescaler);  /* Set the new value    */
  return E_OK;
}

/**
 * Get the value of the counter
 *
 * @param timer the FTM number in range 0:2
 *
 * @return counter value if timer is in range 0:2
 * @return 0             if timer is out of range
 *
 * See page 781-782 of the mk20dx256 manual.
 */
INLINE_FUNC(uint32, OS_CODE) FTMCounterValue(
  CONST(uint32, AUTOMATIC) timer)
{
  if (timer > 2) return 0;
  return FTM_TIMER(timer).FTM_CNT;
}

/**
 * Reset the value of the counter to its min value
 *
 * @param timer the FTM number in range 0:2
 *
 * @return E_OK         timer is in range 0:2
 * @return E_OS_VALUE   timer is out of range
 *
 * See page 781-782 of the mk20dx256 manual.
 */
INLINE_FUNC(uint32, OS_CODE) FTMResetCounterValue(
  CONST(uint32, AUTOMATIC) timer)
{
  if (timer > 2) return E_OS_VALUE;
  /* Writing any value to CNT reset the counter to its min value (CNTIN) */
  FTM_TIMER(timer).FTM_CNT = 0;
  return E_OK;
}

/**
 * Set the minimum counter value aka FTMx_CNTIN
 *
 * @param timer the FTM number in range 0:2
 *
 * @return E_OK         timer is in range 0:2
 * @return E_OS_VALUE   timer is out of range
 *
 * See page 786 of the mk20dx256 manual.
 */
INLINE_FUNC(tpl_status, OS_CODE) FTMSetMinCounterValue(
  CONST(uint32, AUTOMATIC) timer,
  CONST(uint32, AUTOMATIC) value)
{
  if (timer > 2) return E_OS_VALUE;
  FTM_TIMER(timer).FTM_CNTIN = value;
  return E_OK;
}

/**
 * Set the maximum counter value aka FTMx_MOD
 *
 * @param timer the FTM number in range 0:2
 *
 * @return E_OK         timer is in range 0:2
 * @return E_OS_VALUE   timer is out of range
 *
 * See page 782 of the mk20dx256 manual.
 */
INLINE_FUNC(tpl_status, OS_CODE) FTMSetMaxCounterValue(
  CONST(uint32, AUTOMATIC) timer,
  CONST(uint32, AUTOMATIC) value)
{
  if (timer > 2) return E_OS_VALUE;
  FTM_TIMER(timer).FTM_MOD = value;
  return E_OK;
}


#ifdef __cplusplus
extern "C" {
#endif

/**
 * Acknowledge the FMT 0, 1 and 2 3 interrupts.
 *
 * Functions to be used by the handlers generated by goil
 *
 * This is done by writing a 0 in bit TOF of CSR
 * See page 905-906 of the mk20dx256 manual.
 */
FUNC(void, OS_CODE) FTM0_IRQ_ClearFlag();
FUNC(void, OS_CODE) FTM1_IRQ_ClearFlag();
FUNC(void, OS_CODE) FTM2_IRQ_ClearFlag();

#ifdef __cplusplus
}
#endif

#endif

/* end of file ftm_mk20dx256.h */
