#include <msp430.h>
#include <stdlib.h> /* NULL */

#include "ref_a.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

void Ref_A_setReferenceVoltage(uint16_t baseAddress,
                               uint8_t referenceVoltageSelect)
{
  HWREG8(baseAddress + OFS_REFCTL0_L) &= ~(REFVSEL_3);
  HWREG8(baseAddress + OFS_REFCTL0_L) |= referenceVoltageSelect;
}

void Ref_A_disableTempSensor(uint16_t baseAddress)
{
  HWREG8(baseAddress + OFS_REFCTL0_L) |= REFTCOFF;
}

void Ref_A_enableTempSensor(uint16_t baseAddress)
{
  HWREG8(baseAddress + OFS_REFCTL0_L) &= ~(REFTCOFF);
}

void Ref_A_enableReferenceVoltageOutput(uint16_t baseAddress)
{
  HWREG8(baseAddress + OFS_REFCTL0_L) |= REFOUT;
}

void Ref_A_disableReferenceVoltageOutput(uint16_t baseAddress)
{
  HWREG8(baseAddress + OFS_REFCTL0_L) &= ~(REFOUT);
}

void Ref_A_enableReferenceVoltage(uint16_t baseAddress)
{
  HWREG8(baseAddress + OFS_REFCTL0_L) |= REFON;
}

void Ref_A_disableReferenceVoltage(uint16_t baseAddress)
{
  HWREG8(baseAddress + OFS_REFCTL0_L) &= ~(REFON);
}

uint16_t Ref_A_getBandgapMode(uint16_t baseAddress)
{
  return (HWREG16((baseAddress) + OFS_REFCTL0) & BGMODE);
}

uint8_t Ref_A_isBandgapActive(uint16_t baseAddress)
{
  if (HWREG16((baseAddress) + OFS_REFCTL0) & REFBGACT)
  {
    return (REF_A_ACTIVE);
  }
  else
  {
    return (REF_A_INACTIVE);
  }
}

uint16_t Ref_A_isRefGenBusy(uint16_t baseAddress)
{
  return (HWREG16((baseAddress) + OFS_REFCTL0) & REFGENBUSY);
}

uint8_t Ref_A_isRefGenActive(uint16_t baseAddress)
{
  if(HWREG16((baseAddress) + OFS_REFCTL0) & REFGENACT)
  {
    return (REF_A_ACTIVE);
  }
  else
  {
    return (REF_A_INACTIVE);
  }
}

uint8_t Ref_A_isBufferedBandgapVoltageReady(uint16_t baseAddress)
{
  if(HWREG16((baseAddress) + OFS_REFCTL0) & REFBGRDY)
  {
    return (REF_A_READY);
  }
  else
  {
    return (REF_A_NOTREADY);
  }
}

uint8_t Ref_A_isVariableReferenceVoltageOutputReady(uint16_t baseAddress)
{
  if(HWREG16((baseAddress) + OFS_REFCTL0) & REFGENRDY)
  {
    return (REF_A_READY);
  }
  else
  {
    return (REF_A_NOTREADY);
  }
}

void Ref_A_setReferenceVoltageOneTimeTrigger(uint16_t baseAddress)
{
  HWREG8(baseAddress + OFS_REFCTL0_L) |= REFGENOT;
}

void Ref_A_setBufferedBandgapVoltageOneTimeTrigger(uint16_t baseAddress)
{
  HWREG8(baseAddress + OFS_REFCTL0_L) |= REFBGOT;
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

