#include <stdio.h>
#include "tpl_os.h"


#define _XOPEN_SOURCE 500
#include <unistd.h>

int main(void)
{
    StartOS(OSDEFAULTAPPMODE);
    return 0;
}

void PreTaskHook(void)
{
    TaskType id;
    GetTaskID(&id);
    printf("Before %d\n",id);
}

void PostTaskHook(void)
{
    TaskType id;
    GetTaskID(&id);
    printf("After %d\n",id);
}

void StartupHook(void)
{
    printf("Starting !\n");
}

void ShutdownHook(StatusType error)
{
    printf("Bye bye :)\n");
}

DeclareAlarm(active_a_task);
DeclareAlarm(delai);

TASK(a_task)
{
    static int activations = 0;
    
    TaskType id;
    GetTaskID(&id);
    
    activations++;
    
    printf("I am a task, my id is %d, #%d\n",id,activations);
    
    if (activations == 10) {
      CancelAlarm(active_a_task);
      SetRelAlarm(delai,400,0);
      activations = 0;
    }

	TerminateTask();
}

TASK(reveil) {
  SetRelAlarm(active_a_task,100,100);
  TerminateTask();
}
