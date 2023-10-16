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
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301,
 * USA.
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#include "tpl_app_define.h"
#include "tpl_dow.h"

#if WITH_AUTOSAR == YES
#include "Os.h"
#else
#include "tpl_os.h"
#endif

#if ALARM_COUNT > 0
#include "tpl_os_alarm_kernel.h"
#include "tpl_os_timeobj_kernel.h"
#endif

#if ALARM_COUNT > 0
/* ----------------------------------------------------------------------------
 *  ALARMS UTILS
 */
extern CONSTP2VAR(tpl_time_obj, AUTOMATIC,
                  OS_APPL_DATA) tpl_alarm_table[ALARM_COUNT];

/*
 * @def WaitActivationPeriodicAlarm
 *
 * This function wait for alarm periodic alarm expiration
 *
 * @param Alarm Alarm id
 *
 */
void WaitActivationPeriodicAlarm(AlarmType Alarm)
{
  uint32 temp, result_inst_;
  TickType result_inst_tt;
  result_inst_tt = 0;
  do
  {
    temp = result_inst_tt;
    result_inst_ = GetAlarm(Alarm, &result_inst_tt);
    /* for debug stdimpl_print("periodic alarm : ticks = %u (temp =
     * %u)\n",result_inst_tt,temp); */
  } while ((temp >= result_inst_tt) || (temp == (0)));
}

/*
 * @def WaitActivationOneShotAlarm
 *
 * This function wait for alarm one shot alarm expiration
 *
 * @param Alarm Alarm id
 *
 */
void WaitActivationOneShotAlarm(AlarmType Alarm)
{

  int result_inst_;
  TickType result_inst_tt;

  do
  {
    GetAlarm(Alarm, &result_inst_tt);
    /* for debug stdimpl_print("one shot alarm : ticks = %lu\n",result_inst_tt);
     */
  } while ((
      SetRelAlarm(Alarm,
                  tpl_alarm_table[Alarm]->stat_part->counter->max_allowed_value,
                  0) == E_OS_STATE));

  result_inst_ = CancelAlarm(
      Alarm); /* Cancel the previous alarm usefull only for the test */
  TEST_ASSERT_EQUAL_INT(E_OK, result_inst_);
}

#endif /* ALARM_COUNT > 0 */

#if (COUNTER_COUNT > 0) && (WITH_AUTOSAR == YES)
/* ----------------------------------------------------------------------------
 *  COUNTERS UTILS
 */

extern CONSTP2VAR(tpl_counter, OS_VAR,
                  OS_APPL_DATA) tpl_counter_table[COUNTER_COUNT];

/*
 * @def WaitCounterDeltaValue
 *
 * This function use tpl_counter_table, which is part of memory protection.
 * This function should be executed with trusted funtion
 *
 * @param Counter Counter id
 * @param delta_value Delta value to wait to the counter #Counter
 *
 */
void WaitCounterDeltaValue(CounterType Counter, TickType delta_value)
{

  StatusType status_was;
  TickType value_was, value_exp;

  /* if delta_value > OSMAXALLOWEDVALUE */
  DOW_ASSERT(delta_value <= tpl_counter_table[Counter]->max_allowed_value);

  /* find the expected value (value_exp) from the actual value (value_was) and
   * delta value (delta_value) */
  GetCounterValue(Counter, &value_was);
  value_exp = value_was + delta_value;

  /* if value_exp is higher than OSMAXALLOXEDVALUE, do value_exp -
   * OSMAXALLOWEDVALUE */
  if (value_exp > tpl_counter_table[Counter]->max_allowed_value)
  {
    value_exp -= (tpl_counter_table[Counter]->max_allowed_value + 1);
  }

  do
  {
    status_was = GetCounterValue(Counter, &value_was);
  } while (value_was != value_exp);
}
#endif /* COUNTER_COUNT > 0 && WITH_AUTOSAR == YES */

#if (NUMBER_OF_CORES > 1) && (SPINLOCK_COUNT > 0)
/* ----------------------------------------------------------------------------
 *  MULTICORE UTILS
 */
/*
 * @def SyncAllCores
 *
 * This function creates a barrier to sync all running cores.
 *
 */
tpl_core_id syncAllCores_maxCores[SPINLOCK_COUNT];
uint8 syncAllCores_initialized = 0;

void SyncAllCores_Init(void)
{
  uint8 i;
  for (i = 0; i < SPINLOCK_COUNT; i++)
  {
    syncAllCores_maxCores[i] = NUMBER_OF_CORES;
  }

  syncAllCores_initialized = 1;
}

void SyncAllCores(SpinlockIdType spinlock)
{
  StatusType retval;
  if (!syncAllCores_initialized)
  {
    addFailure("SyncAllCores called without init.\n", __LINE__, __FILE__);
    return;
  }

  retval = GetSpinlock(spinlock);
  if (retval != E_OK)
  {
    addFailure("Cannot get spinlock.\n", __LINE__, __FILE__);
    return;
  }
  syncAllCores_maxCores[spinlock] = syncAllCores_maxCores[spinlock] - 1;
  retval = ReleaseSpinlock(spinlock);
  if (retval != E_OK)
  {
    addFailure("Cannot release spinlock.\n", __LINE__, __FILE__);
    return;
  }
  while (syncAllCores_maxCores[spinlock])
    ;
}
#else
void SyncAllCores_Init(void)
{
}
#endif /* (NUMBER_OF_CORES > 1) && (SPINLOCK_COUNT > 0) */
