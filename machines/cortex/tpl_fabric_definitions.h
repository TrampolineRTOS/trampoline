/*
 *
 */

#ifndef TPL_FABRIC_DEFINITIONS_H
#define TPL_FABRIC_DEFINITIONS_H


#define BIT(n)  (1 << (n))


#define AD_REG_OS_INSTRU_SERVICE 0x50000020
#define NO_SERVICE				 0xFF



#define AD_REG_OS_INSTRU_KERNEL_FUNCTIONS 0x50000024
/**********************************************************************************
*	Instrumention of system call handler
***********************************************************************************/
#define ID_CALL_HANDLER   BIT(0)
#define ID_CALL_SERVICE   BIT(1)
#define ID_CALL_CONTEXT	  BIT(2)
/********************************************************************************/
/**********************************************************************************
*	Instrumentation of OS Kernel functions
************************************************************************************/
/*tpl_os_task_kernel*/
#define HW_FUNC_COMPARE_ENTRIES				BIT(3)
#define HW_FUNC_BUBBLE_UP					BIT(4)
#define HW_FUNC_BUBBLE_DOWN					BIT(5)
#define HW_FUNC_PUT_NEW_PROC				BIT(6)
#define HW_FUNC_PUT_PREEMPTED_PROC			BIT(7)
#define HW_FUNC_REMOVE_FRONT_PROC			BIT(8)
#define HW_FUNC_GET_INTERNAL_RESOURCE		BIT(9)
#define HW_FUNC_RELEASE_INTERNAL_RESOURCE	BIT(10)
#define HW_FUNC_PREEMPT 					BIT(11)
#define HW_FUNC_RUN_ELECTED					BIT(12)
#define HW_FUNC_START						BIT(13)
#define	HW_FUNC_SCHEDULE_FROM_RUNNING		BIT(14)
#define HW_FUNC_TERMINATE					BIT(15)
#define HW_FUNC_BLOCK						BIT(16)
#define HW_FUNC_ACTIVATE_TASK				BIT(17)
#define HW_FUNC_RELEASE						BIT(18)
#define HW_FUNC_SET_EVENT					BIT(19)
#define HW_FUNC_INIT_PROC					BIT(20)
#define HW_FUNC_INIT_OS						BIT(21)
#define HW_FUNC_REMOVE_PROC					BIT(22)
#define HW_FUNC_START_SCHEDULING			BIT(23)

/*tpl_os_action*/
#define HW_FUNC_ACTION_ACTIVATE_TASK		BIT(24)
#define HW_FUNC_ACTION_SETEVENT				BIT(25)		

#endif /* TPL_FABRIC_DEFINITIONS_H */
