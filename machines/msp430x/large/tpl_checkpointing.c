#include "tpl_app_define.h"
#if WITH_CHECKPOINTING == YES

#include "tpl_os.h"
#include "msp430.h"
#include "tpl_chkpt_adc.h"
#include <stdint.h>


/*----------------------------------------------------------------------------*/
/* TASK that checks the remaining energy, based on a measure of the ADC       */
/*----------------------------------------------------------------------------*/
#define APP_Task_task_tpl_chkpt_energy_START_SEC_CODE
#include "tpl_memmap.h"

TASK(task_tpl_chkpt_energy)
{
  uint16 vccRaw;

  vccRaw = readPowerVoltage_simple();

  if (vccRaw < HIBERNATE_THRESHOLD) {
    Hibernate();
  } else {
    TerminateTask ();
  }
  //we never get there...
}
#define APP_Task_task_tpl_chkpt_energy_STOP_SEC_CODE
#include "tpl_memmap.h"


#endif //WITH_CHECKPOINTING
