/**
 * @file config.c
 *
 * @section desc File description
 *
 * @section copyright Copyright
 *
 * Trampoline Test Suite
 *
 * Trampoline Test Suite is copyright (c) IRCCyN 2005-2007
 * Trampoline Test Suite is protected by the French intellectual property law.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; version 2
 * of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#include "tpl_app_define.h"
#include "tpl_registers.h"

#if WITH_AUTOSAR == YES
  #include "Os.h"
#else
  #include "tpl_os.h"
#endif

#if ALARM_COUNT > 0
  #include "tpl_os_alarm_kernel.h"
  #include "tpl_os_timeobj_kernel.h"
#endif

#include "embUnit.h"

#define SOFT_IRQ_CORE0  0
#define SOFT_IRQ_CORE1  0

#if ALARM_COUNT > 0
/*
 * @def WaitActivationOneShotAlarm
 *
 * This function wait for alarm one shot alarm expiration
 *
 * @param Alarm Alarm id
 *
 */
void WaitActivationOneShotAlarm(AlarmType Alarm){
  int result_inst_;
  int max_allowed_value = 1;
  TickType result_inst_tt;

  do{
    GetAlarm(Alarm,&result_inst_tt);
    max_allowed_value = tpl_alarm_table[Alarm]->stat_part->counter->max_allowed_value;
    /* for debug stdimpl_print("one shot alarm : ticks = %lu\n",result_inst_tt); */
  }while((SetRelAlarm(Alarm, max_allowed_value, 0) == E_OS_STATE));

  result_inst_ = CancelAlarm(Alarm); /* Cancel the previous alarm usefull only for the test */
  TEST_ASSERT_EQUAL_INT(E_OK, result_inst_);
}
#endif

#if (NUMBER_OF_CORES > 1) && (SPINLOCK_COUNT > 0)
/*
 * @def SyncAllCores
 *
 * This function creates a barrier to sync all running cores.
 *
 * @param Alarm Alarm id
 *
 */
tpl_core_id syncAllCores_maxCores = NUMBER_OF_CORES;

void SyncAllCores(SpinlockIdType spinlock)
{
  StatusType retval;
  retval = GetSpinlock(spinlock);
  if(retval != E_OK)
  {
    addFailure("Cannot get spinlock.\n", __LINE__, __FILE__);
    return;
  }
  syncAllCores_maxCores--;
  retval = ReleaseSpinlock(spinlock);
  if(retval != E_OK)
  {
    addFailure("Cannot release spinlock.\n", __LINE__, __FILE__);
    return;
  }
  while(syncAllCores_maxCores);
}
#endif /* (NUMBER_OF_CORES > 1) && (SPINLOCK_COUNT > 0) */

void sendSoftwareIt(int to_core_id)
{
  if(to_core_id == 0)
  {
    TPL_INTC(0).SSCIR[SOFT_IRQ_CORE0] = INTC_SSCIR_SET;
  }
  else
  {
    TPL_INTC(1).SSCIR[SOFT_IRQ_CORE0] = INTC_SSCIR_SET;
  }
}


