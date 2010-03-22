#include "tpl_os.h"
#include "vp_ipc_devices.h"
#include "tpl_machine.h"
#include <math.h>

#include <stdio.h>

#include "../viper2/device/tpl_can_driver.h"

/* Task declaration */
DeclareEvent(Event1);
DeclareEvent(Event2);
DeclareEvent(Event3);
DeclareEvent(Event4);
DeclareTask(task1);
DeclareTask(task1s);
void lcd1(int secondes);

/* Variables initialization */
int taskactivation = 0;
int time = 0;
int i;

int main(void)
{
    StartOS(OSDEFAULTAPPMODE);
    return 0;
}

void StartupHook(void)
{
    printf("[TPL1] Starting !\n");
}

void ShutdownHook(StatusType error)
{
  printf("[TPL1] Ending !\n");
}

TASK(task1)
{
  //printf("[TPL1] task1 activated !\n");	
  
  for(i=0;i<1000000;i++);
  
  WaitEvent(Event1);
  ClearEvent(Event1);
  
  for(i=0;i<1000000;i++);
  
  WaitEvent(Event2);
  ClearEvent(Event2);
  
  for(i=0;i<1000000;i++);
  
  WaitEvent(Event3);
  ClearEvent(Event3);
  
  for(i=0;i<1000000;i++);
  
  WaitEvent(Event4);
  ClearEvent(Event4);
  
  for(i=0;i<1000000;i++);
  
  taskactivation++;
  if (taskactivation >= 20)
  {
    ActivateTask(task1s); 
    taskactivation=0;
  }
    
  TerminateTask();
}

TASK(task1s)
{
  //printf("[TPL1] task1s activated !\n");
  time++;
  lcd1(time);
  
  TerminateTask();
}

void lcd1(int secondes)
{
  char stringtosend[3];
  stringtosend[0] = (secondes /100) % 10 + '0';
	stringtosend[1] = (secondes /10) % 10 + '0';
	stringtosend[2] = secondes % 10 + '0';
  
  vp_ipc_write_reg(&viper, LCD1_LCD1_REG0, (reg_t)stringtosend[2]);
  vp_ipc_write_reg(&viper, LCD1_LCD1_REG1, (reg_t)stringtosend[1]);
  vp_ipc_write_reg(&viper, LCD1_LCD1_REG2, (reg_t)stringtosend[0]);
  vp_ipc_signal_update(&viper, &global_shared_memory, LCD1, LCD1_REG0 | LCD1_REG1 | LCD1_REG2);
}
