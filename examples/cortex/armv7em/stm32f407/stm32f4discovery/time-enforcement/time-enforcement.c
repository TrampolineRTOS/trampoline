#include "tp.h"
#include "tpl_os.h"

#define APP_Task_t_delay_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(int, OS_APPL_CODE) main(void)
{
  initBoard();
  StartOS(OSDEFAULTAPPMODE);
  return 0;
}

TASK(t_delay)
{
  ledToggle(BLUE);
  TerminateTask();
}
#define APP_Task_t_delay_STOP_SEC_CODE
#include "tpl_memmap.h"

#define APP_Task_t_nodelay_START_SEC_CODE
#include "tpl_memmap.h"

TASK(back)
{
  ledToggle(RED);
  TerminateTask();
}

#define APP_Task_t_nodelay_STOP_SEC_CODE
#include "tpl_memmap.h"

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
/*
 *  * This is necessary for ST libraries
 *   */
FUNC(void, OS_CODE) assert_failed(uint8_t* file, uint32_t line)
{
}

FUNC(void, OS_CODE) PreUserServiceHook(uint32 serviceID) {
    /* 
     * TODO: get proc_id through parameters
     * FIXME: not functionnal w/ memory protection activated
     */
    tpl_proc_id running = tpl_kern.running_id;

    /*
     * Identify the transitions that has been taken
     */
    tpl_te_model_state source_state = tpl_te_model_states[running];
    tpl_te_transition** trans_function = tpl_te_models[running];
    tpl_te_transition* outgoings = trans_function[source_state].transitions;
    uint8 outgoings_count = trans_function[source_state].count;
    uint8 cpt = 0;
    while ((cpt < outgoings_count) && (outgoings[cpt].service_id != serviceID)) {
        cpt++;
    }
    tpl_te_transition trans = outgoings[cpt];
   
    /* Wait for eft if the transistion has been fired early */
    tpl_te_earliest_firing_time eft = trans.eft;
    tpl_te_wait_enforcement_timer(0, eft);

    /* Update current state */
    tpl_te_states[running] = trans.target_state;
}

FUNC(void, OS_CODE) PostUserServiceHook(uint32 serviceID) {
    tpl_set_enforcement_timer(0);
}

FUNC(void, OS_CODE) PreTaskHook()
{
  TaskType task_id = 0;
  GetTaskID(&task_id);
  if (task_id == blink) {
    ledOn(ORANGE);
  }
}

FUNC(void, OS_CODE) PostTaskHook()
{
  TaskType task_id = 0;
  GetTaskID(&task_id);
  if (task_id == blink) {
    ledOff(ORANGE);
  }
}
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"
