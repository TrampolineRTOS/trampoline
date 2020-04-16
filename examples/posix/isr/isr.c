#include <stdio.h>
#include "tpl_os.h"

#define _XOPEN_SOURCE 500

void ErrorHook(StatusType error) {
}

void StartupHook(void) {
	printf("Start !\r\n");
}

void ShutdownHook(StatusType error) {
	printf("Bye bye\r\n");
}

void PreTaskHook(void)
{
  TaskType id;
  GetTaskID(&id);
  printf("Before %d\r\n",id);
}

void PostTaskHook(void)
{
  TaskType id;
  GetTaskID(&id);
  printf("After %d\r\n",id);
}

int main(void)
{
  StartOS(OSDEFAULTAPPMODE);
  return 0;
}

ISR(apushed) {
  printf("a\r\n");
}

ISR (bpushed) {
  printf("b\r\n");
}

TASK(background) {
	unsigned int i;
	while(1) {
		printf("Background\r\n");
		for(i=0;i<10E7; i++);
	}
	TerminateTask();
}
