#include <stdio.h>
#include "tpl_os.h"

int main(void)
{
    StartOS(OSDEFAULTAPPMODE);
    return 0;
}

TASK(my_periodic_task)
{
    static int occurence = 0;
    
    occurence++;
    printf("Activation #%d\n",occurence);
    
    TerminateTask();
}

