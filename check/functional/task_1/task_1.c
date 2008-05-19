/*
 *      t0 est preemptive, les autres sont basic
 *
*/

#include <stdio.h>
#include "tpl_os.h"
#include "tpl_os_generated_configuration.h"
#include "tc_check.h"

char* file = __FILE__;
/*
 * Define the buffers
 */
tc_buf_entry w[20] = {
   { 1,     E_OS_ID     },
   { 103,   E_OK        },
   { 2,     E_OK        },
   { READY, E_OK        },
   { 12,    E_OK        },
   { 3,     E_OK        },
   { 4,     E_OK        },
   { 5,     E_OK        },
   { 10,    E_OS_LIMIT  },
   { 30,    E_OS_LIMIT  },
   { 13,    E_OK        },
   { 14,    E_OK        },
   { 104,   E_OK        },
   { 104,   E_OK        },
   { 101,   E_OK        },
   { 104,   E_OK        },
   { 101,   E_OK        },
   { 102,   E_OK        },
   { 15,    E_OS_LIMIT  }
};

tc_buf_entry g[20];

tc_buf_loc l[20];

#define _XOPEN_SOURCE 500
#include <unistd.h>

int main(void)
{
    StartOS(OSDEFAULTAPPMODE);
    return 0;
}

void StartupHook(void)
{
    printf("Starting task_1 checking\n");
    tc_init_buffer(w,g,l,20);
}

void ShutdownHook(StatusType error) 
{
    tc_check(10);
}

TASK(t0)  /* Au démarage de l'OS, t0 est running. */
{
    StatusType result;
    TaskStateType state;

/* Activation d'une tache dont l'identifiant est invalide : case 1 */
    result = ActivateTask(100);
    if (result == E_OS_ID) tc_report_error(1,result,file,__LINE__);
    else tc_report_error(-1,result,file,__LINE__);

/* t0, préemptive, active t3, tache basique de priorité plus grande.
   test case */
    result = ActivateTask(t3);   /* T3 devient running et renvoie OK*/
    if (result == E_OK) tc_report_error(3,result,file,__LINE__);
    else tc_report_error(-3,result,file,__LINE__);
/* t3 se termine */

/* t0, préemptive, active t2, tache basique de priorité plus faible
   Test case 4 */
    result = ActivateTask(t2);      /* Pas de préemption */
    GetTaskState(t2,&state);        /* t2 est ready */
    if (result == E_OK && state == READY) tc_report(4,file,__LINE__);
    else tc_report(-4,file,__LINE__);
    
/* t0, préemptive, active t1, tache basique de priorité égale.
   Test case 5 */
    result = ActivateTask(t1);  /* Pas de préemption */
    GetTaskState(t1,&state);        /* t1 est ready */
    if (result == E_OK && state == READY) tc_report(5,file,__LINE__);
    else tc_report(-5,file,__LINE__);

/* t0 active de nouveau t2, de max d'activation 1.
   Test case 10 */
    result = ActivateTask(t2);
    if (result == E_OS_LIMIT) tc_report_error(10,result,file,__LINE__);
    else tc_report_error(-10,result,file,__LINE__);

/* Chain de la tache t2 : case 30 */
    result = ChainTask(t2);
    if (result == E_OS_LIMIT) tc_report_error(30,result,file,__LINE__);
    else tc_report_error(-30,result,file,__LINE__);

/* t0, préemptive, active t4, tache basic ready, qui n'a pas dépassé son max. d'activation.
   Test case 13 */
    result = ActivateTask(t4);
    GetTaskState(t4,&state);        /* t4 est ready */
    if (result == E_OK && state == 1) tc_report_error(13,result,file,__LINE__);
    else tc_report_error(-13,result,file,__LINE__);

/* t0, préemptive, active de nouveau t1, tache basic ready, qui n'a pas dépassé son max. d'activation.
   Test case 14 */
    result = ActivateTask(t1);
    GetTaskState(t1,&state);        /* t1 est ready */
    if (result == E_OK && state == 1) tc_report_error(14,result,file,__LINE__);
    else tc_report_error(-14,result,file,__LINE__);

/*t0 se termine.*/
	TerminateTask();
}

TASK(t1) {
    tc_report(101,file,__LINE__);
	TerminateTask();
}

TASK(t2) {
    StatusType result2;
    
    tc_report(102,file,__LINE__);

/* t2 active t2, de même priorité et dont le nombre max. d'activation est de 1.
   Test case 15 */
    result2 = ActivateTask(t2);
    if (result2 == E_OS_LIMIT) tc_report_error(15,result2,file,__LINE__);
    else tc_report_error(-15,result2,file,__LINE__);

/* t2 ferme l'OS */
    ShutdownOS(E_OK);
	TerminateTask();
}

TASK(t3) {
    StatusType result3;
    TaskStateType state3;

    tc_report(103,file,__LINE__);
    
/* t3, non préemptive, active t4, tache basique suspended */
/* test case 2 */
    result3 = ActivateTask(t4);
    if (result3 == E_OK) tc_report_error(2,result3,file,__LINE__);
    else tc_report_error(-2,result3,file,__LINE__);
    
    GetTaskState(t4,&state3);   /* t4 est ready */
    tc_report(state3,file,__LINE__);
    
/* t3, non préemptive, active de nouveau t4, tache basique ready,
   qui n'a pas dépassé son max. d'activation. */
/* test case 12 */
    result3 = ActivateTask(t4);
    if (result3 == E_OK) tc_report_error(12,result3,file,__LINE__);
    else tc_report_error(-12,result3,file,__LINE__);

	TerminateTask();
}

TASK(t4) {
    tc_report(104,file,__LINE__);
	TerminateTask();
}

