#include <msp430.h>
#include <stdlib.h> /* NULL */

#include "adc12_b.h"

//#include <assert.h>

#define OS_START_SEC_CODE
#include "tpl_memmap.h"

uint8_t ADC12_B_init(uint16_t baseAddress,
                  ADC12_B_initParam *param)
{
  uint8_t retVal = 1; // Modifier avec le type Autosar

  //Make sure the ENC bit is cleared before initializing the ADC12
  HWREG8(baseAddress + OFS_ADC12CTL0_L) &= ~ADC12ENC;

  //Turn OFF ADC12B Module & Clear Interrupt Registers
  HWREG16(baseAddress + OFS_ADC12CTL0) &= ~(ADC12ON + ADC12ENC + ADC12SC);
  HWREG16(baseAddress + OFS_ADC12IER0) &= 0x0000;  //Reset ALL interrupt enables
  HWREG16(baseAddress + OFS_ADC12IER1) &= 0x0000;
  HWREG16(baseAddress + OFS_ADC12IER2) &= 0x0000;
  HWREG16(baseAddress + OFS_ADC12IFGR0) &= 0x0000;  //Reset ALL interrupt flags
  HWREG16(baseAddress + OFS_ADC12IFGR1) &= 0x0000;
  HWREG16(baseAddress + OFS_ADC12IFGR2) &= 0x0000;

  //Set ADC12B Control 1
  HWREG16(baseAddress + OFS_ADC12CTL1) =
    param->sampleHoldSignalSourceSelect //Setup the Sample-and-Hold Source
    + (param->clockSourceDivider & ADC12DIV_7) //Set Clock Divider
    + (param->clockSourcePredivider & ADC12PDIV__64)
    + param->clockSourceSelect; //Setup Clock Source

  //Set ADC12B Control 2
  HWREG16(baseAddress + OFS_ADC12CTL2) = ADC12RES_2; //Default resolution to 12-bits

  //Set ADC12B Control 3
  HWREG16(baseAddress + OFS_ADC12CTL3) = param->internalChannelMap; // Map internal channels

  return (retVal);
}

void ADC12_B_enable(uint16_t baseAddress)
{
  // Clear ENC bit
  HWREG8(baseAddress + OFS_ADC12CTL0_L) &= ~ADC12ENC;

  //Enable the ADC12B Module
  HWREG8(baseAddress + OFS_ADC12CTL0_L) |= ADC12ON;
}

void ADC12_B_disable(uint16_t baseAddress)
{
    // Clear ENC bit
    HWREG8(baseAddress + OFS_ADC12CTL0_L) &= ~ADC12ENC;

    //Disable ADC12B module
    HWREG8(baseAddress + OFS_ADC12CTL0_L) &= ~ADC12ON;
}

void ADC12_B_setupSamplingTimer(uint16_t baseAddress,
                                uint16_t clockCycleHoldCountLowMem,
                                uint16_t clockCycleHoldCountHighMem,
                                uint16_t multipleSamplesEnabled)
{
  HWREG16(baseAddress + OFS_ADC12CTL1) |= ADC12SHP;

  //Reset clock cycle hold counts and msc bit before setting them
  HWREG16(baseAddress + OFS_ADC12CTL0) &= ~(ADC12SHT0_15 + ADC12SHT1_15 + ADC12MSC);

  //Set clock cycle hold counts and msc bit
  HWREG16(baseAddress + OFS_ADC12CTL0) |= clockCycleHoldCountLowMem
                                          + (clockCycleHoldCountHighMem << 4)
                                          + multipleSamplesEnabled;
}

void ADC12_B_disableSamplingTimer(uint16_t baseAddress)
{
  HWREG16(baseAddress + OFS_ADC12CTL1) &= ~(ADC12SHP);
}

void ADC12_B_configureMemory(uint16_t baseAddress,
                             ADC12_B_configureMemoryParam *param)
{
  //Make sure the ENC bit is cleared before configuring a Memory Buffer Control
  //    assert(!(HWREG16(baseAddress + OFS_ADC12CTL0) & ADC12ENC));

  if (!(HWREG16(baseAddress + OFS_ADC12CTL0) & ADC12ENC))
  {
    //Set the offset in respect to ADC12MCTL0
    uint16_t memoryBufferControlOffset = (OFS_ADC12MCTL0 + param->memoryBufferControlIndex);

    //Reset the memory buffer control and Set the input source
    HWREG16(baseAddress + memoryBufferControlOffset) =
      param->inputSourceSelect //Set Input Source
      + param->refVoltageSourceSelect //Set Vref+/-
      + param->endOfSequence; //Set End of Sequence

    HWREG16(baseAddress + memoryBufferControlOffset) &= ~(ADC12WINC);

    HWREG16(baseAddress + memoryBufferControlOffset) |= param->windowComparatorSelect;
    //(OFS_ADC12MCTL0_H + memoryIndex) == offset of OFS_ADC12MCTLX_H

    HWREG16(baseAddress + memoryBufferControlOffset) &= ~(ADC12DIF);

    HWREG16(baseAddress + memoryBufferControlOffset) |= param->differentialModeSelect;
    //(OFS_ADC12MCTL0_H + memoryIndex) == offset of OFS_ADC12MCTLX_H
  }
}

void ADC12_B_setWindowCompAdvanced(uint16_t baseAddress,
                                   uint16_t highThreshold,
                                   uint16_t lowThreshold)
{
}

void ADC12_B_enableInterrupt(uint16_t baseAddress,
                             uint16_t interruptMask0,
                             uint16_t interruptMask1,
                             uint16_t interruptMask2)
{
  HWREG16(baseAddress + OFS_ADC12IER0) |= interruptMask0;
  HWREG16(baseAddress + OFS_ADC12IER1) |= interruptMask1;
  HWREG16(baseAddress + OFS_ADC12IER2) |= interruptMask2;
}

void ADC12_B_disableInterrupt(uint16_t baseAddress,
                              uint16_t interruptMask0,
                              uint16_t interruptMask1,
                              uint16_t interruptMask2)
{
  HWREG16(baseAddress + OFS_ADC12IER0) &= ~(interruptMask0);
  HWREG16(baseAddress + OFS_ADC12IER1) &= ~(interruptMask1);
  HWREG16(baseAddress + OFS_ADC12IER2) &= ~(interruptMask2);
}

void ADC12_B_clearInterrupt(uint16_t baseAddress,
                            uint8_t interruptRegisterChoice,
                            uint16_t memoryInterruptFlagMask)
{
  HWREG16(baseAddress + OFS_ADC12IFGR0 + 2 * interruptRegisterChoice) &= ~(memoryInterruptFlagMask);
}

uint16_t ADC12_B_getInterruptStatus(uint16_t baseAddress,
                                    uint8_t interruptRegisterChoice,
                                    uint16_t memoryInterruptFlagMask)
{
  return (HWREG16(baseAddress + OFS_ADC12IFGR0 + 2 * interruptRegisterChoice) & memoryInterruptFlagMask);
}

void ADC12_B_startConversion(uint16_t baseAddress,
                             uint16_t startingMemoryBufferIndex,
                             uint8_t conversionSequenceModeSelect)
{
  //Reset the ENC bit to set the starting memory address and conversion mode
  //sequence
  HWREG8(baseAddress + OFS_ADC12CTL0_L) &= ~(ADC12ENC);
  //Reset the bits about to be set
  HWREG16(baseAddress + OFS_ADC12CTL3) &= ~(ADC12CSTARTADD_31);
  HWREG16(baseAddress + OFS_ADC12CTL1) &= ~(ADC12CONSEQ_3);

  HWREG16(baseAddress + OFS_ADC12CTL3) |= startingMemoryBufferIndex;
  HWREG16(baseAddress + OFS_ADC12CTL1) |= conversionSequenceModeSelect;
  HWREG8(baseAddress + OFS_ADC12CTL0_L) |= ADC12ENC + ADC12SC;
}

void ADC12_B_disableConversions(uint16_t baseAddress,
                                uint8_t preempt)
{
}

uint16_t ADC12_B_getResults(uint16_t baseAddress,
                            uint8_t memoryBufferIndex)
{
  return (HWREG16(baseAddress + (OFS_ADC12MEM0 + memoryBufferIndex)));
  //(0x60 + memoryBufferIndex) == offset of ADC12MEMx
}

void ADC12_B_setResolution(uint16_t baseAddress,
                           uint8_t resolutionSelect)
{
  HWREG8(baseAddress + OFS_ADC12CTL2_L) &= ~(ADC12RES_3);
  HWREG8(baseAddress + OFS_ADC12CTL2_L) |= resolutionSelect;
}

void ADC12_B_setSampleHoldSignalInversion(uint16_t baseAddress,
                                          uint16_t invertedSignal)
{
}

void ADC12_B_setDataReadBackFormat(uint16_t baseAddress,
                                   uint8_t readBackFormat)
{
}

void ADC12_B_setAdcPowerMode(uint16_t baseAddress,
                             uint8_t powerMode)
{
}

uint32_t ADC12_B_getMemoryAddressForDMA(uint16_t baseAddress,
                                        uint8_t memoryIndex)
{
  return 0;
}

uint8_t ADC12_B_isBusy(uint16_t baseAddress)
{
  return 0;
}

#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"
