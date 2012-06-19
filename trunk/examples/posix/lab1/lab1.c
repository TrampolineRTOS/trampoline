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

DeclareEvent(evt_0);
DeclareEvent(evt_1);
DeclareEvent(evt_t1);
DeclareTask(task_t1);
DeclareEvent(evt_t2);
DeclareTask(task_t2);
DeclareEvent(evt_t3);
DeclareTask(task_t3);
DeclareTask(server);

/*TASK(task_0)
{
    EventMaskType event_got;
    TaskType id;
    GetTaskID(&id);
    WaitEvent(evt_0);
    printf("I am task_0, my id is %d\n",id);
    ClearEvent(evt_0);
	TerminateTask();
        
}
TASK(task_1)
{
    EventMaskType event_got;
    TaskType id;
    GetTaskID(&id);
    WaitEvent(evt_1);
    printf("I am task_1, my id is %d\n",id);
    ClearEvent(evt_1);
	TerminateTask();
        
}
TASK(a_task)
{
    TaskType id;
    GetTaskID(&id);
    
    printf("I am a task, my id is %d\n",id);
    ActivateTask(task_0);
    ActivateTask(task_1);
    SetEvent(task_0,evt_0);
    SetEvent(task_1,evt_1);
    //ShutdownOS(E_OK);
    TerminateTask();
    //StatusType result= ChainTask(task_0);
   
//    if (result==E_OS_ID)
//    printf("The error is E_OS_ID and value is %d\n",result);
//    else if (result==E_OS_LIMIT)
//    printf("The error is E_OS_LIMIT and value is %d\n",result);
//    else
//    printf("There is no error");
}*/
TASK(server)
{
    EventMaskType event_got;
    TaskType id;
    GetTaskID(&id);
    ActivateTask(task_t1);
    ActivateTask(task_t2);
    ActivateTask(task_t3); 
    while(1){
//      printrl();
      printf("\nI am a task, my id is %d\n",id);
      WaitEvent(evt_t1 | evt_t2 | evt_t3);
      GetEvent(server, &event_got);
      if(event_got & evt_t1 )
      {
        printf("I executed task t1");
        ClearEvent(evt_t1);
        ActivateTask(task_t1);
      }
      if(event_got & evt_t2 )
      {
        printf("I executed task t2");
        ClearEvent(evt_t2);
        ActivateTask(task_t2);
      }
      if(event_got & evt_t3 )
      {
        printf("I executed task t3");
        ClearEvent(evt_t3);
        ActivateTask(task_t3);
      }
    }

    //ShutdownOS(E_OK);
    //TerminateTask();

}
TASK(task_t1)
{
    
    TaskType id;
    GetTaskID(&id);
   
    printf("I am t1, my id is %d\n",id);
    SetEvent(server,evt_t1);
    
	TerminateTask();
        
}

TASK(task_t2)
{
    
    TaskType id;
    GetTaskID(&id);
   
    printf("I am t2, my id is %d\n",id);
    SetEvent(server,evt_t2);
    
	TerminateTask();
        
}

TASK(task_t3)
{
    
    TaskType id;
    GetTaskID(&id);
   
    printf("I am t3, my id is %d\n",id);
    SetEvent(server,evt_t3);
    
	TerminateTask();
        
}


