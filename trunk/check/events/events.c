/*
 *     Gestion des évènements
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
    { 1,        E_OS_ID        },
    { 6,        E_OK        },
    { 100,      E_OK        },
    { 102,      E_OK        },
    { 7,        E_OK        }
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
    printf("Starting events checking\n");
    tc_init_buffer(w,g,l,20);
}

void ShutdownHook(StatusType error) 
{
    tc_check(10);
}

TASK(t0) {
    StatusType result;
    EventMaskType event;

/* erreur d'identifiant case1 */
    result = SetEvent(100,evt1);
    if (result == E_OS_ID) tc_report_error(1,result,file,__LINE__);
    else tc_report_error(-1,result,file,__LINE__);
    
/* t1 est une tache BASIC : case 2 */
    result = SetEvent(t1,evt1);
    if (result == E_OS_ACCESS) {
        printf("case 2 OK\n");
    }else printf("Erreur case 2 : %d\n",result);

/* Activation de la tache t1 */
    printf("Activation de t1\n");
    result = ActivateTask(t1);
    if (result != E_OK) {
        printf("Erreur activation t1 : %d\n",result);
    }


/* t0 est extended : case 14 */
    result = ClearEvent(evt1);
    if (result == E_OK) {
        printf("case 14 OK\n");
    }else printf("Erreur case 14 : %d\n",result);

/* invalid task ID : case 15 */
    result = GetEvent(100,&event);
  if (result == E_OS_ID) {
        printf("case 15 OK\n");
    }else printf("Erreur case 15 : %d\n",result);

/* t1 est une tache BASIC : case 16 */
    result = GetEvent(t1,&event);
  if (result == E_OS_ACCESS) {
        printf("case 16 OK\n");
    }else printf("Erreur case 16 : %d\n",result);

/* Active t2 (extended, priorité plus forte) => t2 est running */
    printf("Activation de t2\n");
    result = ActivateTask(t2);
    if (result != E_OK) {
        printf("Erreur activation t2 : %d\n",result);
    }

	TerminateTask();
}

TASK(t1) {
    StatusType result1;
    EventMaskType event;

    printf("t1 is running\n");
/* t0 est suspended, extended : case 3 */
    result1 = SetEvent(t0,evt1);
  if (result1 == E_OS_STATE) {
        printf("case 3 OK\n");
    }else printf("Erreur case 3 : %d\n",result1);

/* t0 est suspended, extended : case 17  */
    result1 = GetEvent(t0,&event);
  if (result1 == E_OS_STATE) {
        printf("case 17 OK\n");
    }else printf("Erreur case 17 : %d\n",result1);

/* t1 est une tache BASIC : case 11 */
    result1 = ClearEvent(evt1);
  if (result1 == E_OS_ACCESS) {
        printf("case 11 OK\n");
    }else printf("Erreur case 11 : %d\n",result1);

/* t1 est une tache BASIC : case 21 */
    result1 = WaitEvent(evt1);
  if (result1 == E_OS_ACCESS) {
        printf("case 21 OK\n");
    }else printf("Erreur case 21 : %d\n",result1);

/* t2 waiting : case 5 */
    result1 = SetEvent(t2,evt1);
  if (result1 == E_OK) {
        printf("case 5 OK\n");
    }else printf("Erreur case 5 : %d\n",result1);

/* t2 waiting : case 4 */
    result1 = SetEvent(t2,evt2);
  if (result1 == E_OK) {
        printf("case 4 OK\n");
    }else printf("Erreur case 4 : %d\n",result1);

ShutdownOS(E_OK);
	TerminateTask();
}

TASK(t2) {
    printf("t2 is running\n");

/* attente de l'évènement 2, t2 est waiting*/
    WaitEvent(evt2);

        TerminateTask();
}

