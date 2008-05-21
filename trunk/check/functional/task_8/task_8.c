/*
 *     t0, t1, t2 et t3 sont extended,
 *
*/

#include <stdio.h>
#include "tpl_os.h"
#include "tpl_os_generated_configuration.h"
#include "tc_check.h"

char* file = __FILE__;

#define invalidtaskid 1000
/*
 * Define the buffers
 */
tc_buf_entry w[20] = {
	{ 22,    E_OS_RESOURCE},
	{ 9,     E_OK         },
	{ 25,    E_OK         },
	{ 15,    E_OS_ID      },
	{ 16,    E_OS_ACCESS  },
	{ 17,    E_OS_STATE   },	
	{ 26,    E_OK         }
};

tc_buf_entry g[20];

tc_buf_loc l[20];


#define _XOPEN_SOURCE 500
//#include <unistd.h>

void StartupHook(void);

int main(void)
{
	StartupHook();
    StartOS(OSDEFAULTAPPMODE);
	
    return 0;
}

void StartupHook(void)
{
    printf("Starting task_7 checking\n");
    tc_init_buffer(w,g,l,20);
}

void ShutdownHook(StatusType _error)
{
    tc_check(10);
}

StatusType result;


TASK(t0) {		/* Au d√©marage de l'OS, t0 est running */

	ActivateTask(t1);

/* t1, set event avec une t‚che en suspended
    Test case 15 */
	result = GetEvent(invalidtaskid,EV1);
    if (result == E_OS_ID) tc_report_error(15,result,file,__LINE__);
    else tc_report_error(-15,result,file,__LINE__);
	
/* t1, set event avec une t‚che en suspended
    Test case 16 */
	result = GetEvent(t0,EV1);
    if (result == E_OS_ACCESS) tc_report_error(16,result,file,__LINE__);
    else tc_report_error(-16,result,file,__LINE__);

/* t1, set event avec une t‚che en suspended
    Test case 17 */
	result = GetEvent(t2,EV1);
    if (result == E_OS_STATE) tc_report_error(17,result,file,__LINE__);
    else tc_report_error(-17,result,file,__LINE__);

	SetEvent(t1,EV1);

	

}

TASK(t1) {

	GetResource(res);

/* t1, set event avec une t‚che en suspended
    Test case 22 */
	result = WaitEvent(EV1);
    if (result == E_OS_RESOURCE) tc_report_error(22,result,file,__LINE__);
    else tc_report_error(-22,result,file,__LINE__);

	ReleaseResource(res);
	
	/* t1, set event avec une t‚che en suspended
    Test case 9 */
	result = SetEvent(t1, EV1);
    if (result == E_OK) tc_report(9,file,__LINE__);
    else tc_report_error(-9,result,file,__LINE__);

	/* t1, set event avec une t‚che en suspended
    Test case 25 */
	result = WaitEvent(EV1);
    if (result == E_OK) tc_report(25,file,__LINE__);
    else tc_report_error(-25,result,file,__LINE__);

	ClearEvent(EV1);

	/* t1, set event avec une t‚che en suspended
    Test case 26 */
	result = WaitEvent(EV1);
    if (result == E_OK) tc_report(26,file,__LINE__);
    else tc_report_error(-26,result,file,__LINE__);

	tc_check(10);
	/* t3 ferme l'OS */
    ShutdownOS(E_OK);

}





TASK(t2) {

	tc_report(100,file,__LINE__);

	TerminateTask();
}

TASK(time_error)
{	
	tc_check(10);
	/* t3 ferme l'OS */
    ShutdownOS(E_OK);	
}
