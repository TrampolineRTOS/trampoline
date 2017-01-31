/*
 *
 */

#ifndef TPL_FABRIC_DEFINITIONS_H
#define TPL_FABRIC_DEFINITIONS_H


#define BIT(n)  (1 << (n))


#define AD_REG_OS_INSTRU_SCH_AND_SERVICE 0x50000020

/**********************************************************************************
*	Instrumention of system call handler
***********************************************************************************/
#define ID_CALL_HANDLER   BIT(0)
#define ID_CALL_SERVICE   BIT(1)
#define ID_CALL_CONTEXT	  BIT(2)
/********************************************************************************/

/**********************************************************************************
*	Instrumentation of Trampoline service
************************************************************************************/
/*tpl_os_task_kernel*/
#define HW_FUNC_ACTIVATE_TASK_SERVICE	BIT(3)
#define HW_FUNC_TERMINATE_TASK_SERVICE	BIT(4)
#define HW_FUNC_CHAIN_TASK_SERVICE		BIT(5)
#define HW_FUNC_SCHEDULE_SERVICE		BIT(6)
#define HW_FUNC_GET_TASK_ID_SERVICE		BIT(7)
#define HW_FUNC_GET_TASK_STATE_SERVICE	BIT(8)

/*tpl_os_event_kernel*/
#define HW_FUNC_SET_EVENT_SERVICE		BIT(9)
#define HW_FUNC_CLEAR_EVENT_SERVICE		BIT(10)
#define HW_FUNC_GET_EVENT_SERVICE		BIT(11)
#define HW_FUNC_WAIT_EVENT_SERVICE		BIT(12)

#define AD_REG_OS_INSTRU_KERNEL_FUNCTIONS 0x50000024

/**********************************************************************************
*	Instrumentation of OS Kernel functions
************************************************************************************/
/*tpl_os_task_kernel*/
#define HW_FUNC_COMPARE_ENTRIES				BIT(0)
#define HW_FUNC_BUBBLE_UP					BIT(1)
#define HW_FUNC_BUBBLE_DOWN					BIT(2)
#define HW_FUNC_PUT_NEW_PROC				BIT(3)
#define HW_FUNC_PUT_PREEMPTED_PROC			BIT(4)
#define HW_FUNC_REMOVE_FRONT_PROC			BIT(5)
#define HW_FUNC_GET_INTERNAL_RESOURCE		BIT(6)
#define HW_FUNC_RELEASE_INTERNAL_RESOURCE	BIT(7)
#define HW_FUNC_PREEMPT 					BIT(8)
#define HW_FUNC_RUN_ELECTED					BIT(9)
#define HW_FUNC_START						BIT(10)
#define	HW_FUNC_SCHEDULE_FROM_RUNNING		BIT(11)
#define HW_FUNC_TERMINATE					BIT(12)
#define HW_FUNC_BLOCK						BIT(13)
#define HW_FUNC_ACTIVATE_TASK				BIT(14)
#define HW_FUNC_RELEASE						BIT(15)
#define HW_FUNC_SET_EVENT					BIT(16)
#define HW_FUNC_INIT_PROC					BIT(17)
#define HW_FUNC_INIT_OS						BIT(18)

		

#endif /* TPL_FABRIC_DEFINITIONS_H */
