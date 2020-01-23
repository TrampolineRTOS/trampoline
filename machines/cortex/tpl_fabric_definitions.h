/*
 *
 */

#ifndef TPL_FABRIC_DEFINITIONS_H
#define TPL_FABRIC_DEFINITIONS_H


//#define BIT(n)  (1 << (n))
#define BIT(n) ((0x1 << (n)) + (0x400 << (n)) + (0x100000 << (n))) //data triplication

/*********************************************************************************************************************************************/

#define AD_REG_OS_INSTRU_SERVICE 0x50000000
#define NO_SERVICE				 0xFF

/*********************************************************************************************************************************************/

/*§§§§§§§§§§§§§§§§§§ INSTRUMENTATION OF EVENTS §§§§§§§§§§§§§§§§§§§§*/

#define AD_REG_OS_INSTRU_KERNEL_FUNCTIONS 0x50000004
	/**********************************************************************************
	*	Instrumention of system call handler
	***********************************************************************************/
	#define ID_CALL_HANDLER_ENTER   BIT(0)
	#define ID_CALL_HANDLER_EXIT   BIT(1)
	#define ID_CALL_SERVICE_ENTER   BIT(2)
	#define ID_CALL_SERVICE_EXIT   BIT(3)
	#define ID_CALL_CONTEXT_ENTER	  BIT(4)
	#define ID_CALL_CONTEXT_EXIT	  BIT(5)
	/**********************************************************************************
	*	Instrumentation of OS Kernel functions
	************************************************************************************/
	/*tpl_os_task_kernel*/
	#define HW_FUNC_COMPARE_ENTRIES_ENTER			BIT(6)
	#define HW_FUNC_COMPARE_ENTRIES_EXIT			BIT(7)
	#define HW_FUNC_BUBBLE_UP_ENTER				BIT(8)
	#define HW_FUNC_BUBBLE_UP_EXIT				BIT(9)

#define AD_REG_OS_INSTRU_KERNEL_FUNCTIONS_2 0x50000008
	#define HW_FUNC_BUBBLE_DOWN_ENTER			BIT(0)
	#define HW_FUNC_BUBBLE_DOWN_EXIT			BIT(1)
	#define HW_FUNC_PUT_NEW_PROC_ENTER			BIT(2)
	#define HW_FUNC_PUT_NEW_PROC_EXIT			BIT(3)
	#define HW_FUNC_PUT_PREEMPTED_PROC_ENTER		BIT(4)
	#define HW_FUNC_PUT_PREEMPTED_PROC_EXIT			BIT(5)
	#define HW_FUNC_REMOVE_FRONT_PROC_ENTER			BIT(6)
	#define HW_FUNC_REMOVE_FRONT_PROC_EXIT			BIT(7)
	#define HW_FUNC_GET_INTERNAL_RESOURCE_ENTER		BIT(8)
	#define HW_FUNC_GET_INTERNAL_RESOURCE_EXIT		BIT(9)

#define AD_REG_OS_INSTRU_KERNEL_FUNCTIONS_3 0x5000000c
	#define HW_FUNC_RELEASE_INTERNAL_RESOURCE_ENTER		BIT(0)
	#define HW_FUNC_RELEASE_INTERNAL_RESOURCE_EXIT		BIT(1)
	#define HW_FUNC_PREEMPT_ENTER 				BIT(2)
	#define HW_FUNC_PREEMPT_EXIT 				BIT(3)
	#define HW_FUNC_RUN_ELECTED_ENTER			BIT(4)
	#define HW_FUNC_RUN_ELECTED_EXIT			BIT(5)
	#define HW_FUNC_START_ENTER				BIT(6)
	#define HW_FUNC_START_EXIT				BIT(7)
	#define	HW_FUNC_SCHEDULE_FROM_RUNNING_ENTER		BIT(8)
	#define	HW_FUNC_SCHEDULE_FROM_RUNNING_EXIT		BIT(9)

#define AD_REG_OS_INSTRU_KERNEL_FUNCTIONS_4 0x50000010
	#define HW_FUNC_TERMINATE_ENTER				BIT(0)
	#define HW_FUNC_TERMINATE_EXIT				BIT(1)
	#define HW_FUNC_BLOCK_ENTER				BIT(2)
	#define HW_FUNC_BLOCK_EXIT				BIT(3)
	#define HW_FUNC_ACTIVATE_TASK_ENTER			BIT(4)
	#define HW_FUNC_ACTIVATE_TASK_EXIT			BIT(5)
	#define HW_FUNC_RELEASE_ENTER				BIT(6)
	#define HW_FUNC_RELEASE_EXIT				BIT(7)
	#define HW_FUNC_SET_EVENT_ENTER				BIT(8)
	#define HW_FUNC_SET_EVENT_EXIT				BIT(9)

#define AD_REG_OS_INSTRU_KERNEL_FUNCTIONS_5 0x50000014
	#define HW_FUNC_INIT_PROC_ENTER				BIT(0)
	#define HW_FUNC_INIT_PROC_EXIT				BIT(1)
	#define HW_FUNC_INIT_OS_ENTER				BIT(2)
	#define HW_FUNC_INIT_OS_EXIT				BIT(3)
	#define HW_FUNC_REMOVE_PROC_ENTER			BIT(4)
	#define HW_FUNC_REMOVE_PROC_EXIT			BIT(5)
	#define HW_FUNC_START_SCHEDULING_ENTER			BIT(6)
	#define HW_FUNC_START_SCHEDULING_EXIT			BIT(7)
/*tpl_os_action*/
	#define HW_FUNC_ACTION_ACTIVATE_TASK_ENTER		BIT(8)
	#define HW_FUNC_ACTION_ACTIVATE_TASK_EXIT		BIT(9)

#define AD_REG_OS_INSTRU_KERNEL_FUNCTIONS_6 0x50000018
	#define HW_FUNC_ACTION_SETEVENT_ENTER			BIT(0)	
	#define HW_FUNC_ACTION_SETEVENT_EXIT			BIT(1)
/*tpl_ctx_switch*/
	#define ID_CALL_SAVE_ENTER				BIT(2)
	#define ID_CALL_SAVE_EXIT				BIT(3)
/*********************************************************************************************************************************************/


/**********************************************************************************
*	Instrumention of IRQ SystemCounter
***********************************************************************************/
#endif /* TPL_FABRIC_DEFINITIONS_H */
