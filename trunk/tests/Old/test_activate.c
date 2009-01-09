#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#include <check.h>

#include <stdio.h>
#include "tpl_os.h"
#include "tpl_kernel.h" //for tpl_task_table

TASK(t11)
{
	printf("t11\n");
	TerminateTask();
}

TASK(t21)
{
	printf("t21\n");
	TerminateTask();
}

TASK(t22)
{
	printf("t22\n");
	TerminateTask();
}
TASK(t23)
{
	printf("t23\n");
	TerminateTask();
}
TASK(t31)
{
	printf("t31\n");
	TerminateTask();
}
TASK(t32)
{
	printf("t32\n");
	TerminateTask();
}
TASK(t41)
{
	printf("t41\n");
	TerminateTask();
}

void damned() {
    printf("Callback damned !\n");
}

tpl_task *tpl_get_task(void);
void tpl_put_task(tpl_task *);

/* check pointers at beginning: next_set */
void check_init_next_set()
{
	int i;
	for(i=0; i<7; i++)
		fail_unless(tpl_task_table[i] -> next_set == NULL,"error");
}
/* check pointers at beginning: next_task */
void check_init_next_task()
{
	int i;
	for(i=0; i<7; i++)
		fail_unless(tpl_task_table[i] -> next_task == NULL,"error");
}

/* check tasks that are never connected to a next_task. */
void reinitInitVal()
{
	int i;
	for(i=0; i<7; i++) 
	{
		tpl_task_table[i] -> next_task = (void *)1;
		tpl_task_table[i] -> next_set = (void *)1;
	}
}

START_TEST(init_task_list_struct)
{
	check_init_next_set();
	check_init_next_task();
	/* testing: tpl_put_task in file tpl_kernel.c
	 * beginning: no task (idle task is running).
	 */
	fail_unless(tpl_task_list_head == NULL,
		"task list not NULL at init");
}
END_TEST		
START_TEST(tpl_put_task_insert_first_task)
{	
	reinitInitVal();
	/* insert a first task: priority 3 */
	tpl_put_task(tpl_task_table[t31]);
	fail_unless(tpl_task_list_head == tpl_task_table[t31],
		"task 31 not inserted");
	fail_unless(tpl_task_table[t31] -> next_set == NULL,
		"task 31 not connected to idle task");
	fail_unless(tpl_task_table[t31] -> next_task == NULL,
		"task 31 not inserted");
}
END_TEST		
START_TEST(tpl_put_task_insert_highest_priority_task)
{	
	reinitInitVal();
	/* insert a task with a higher priority: priority 4 */
	tpl_put_task(tpl_task_table[t31]);
	tpl_put_task(tpl_task_table[t41]);
	fail_unless(tpl_task_list_head == tpl_task_table[t41],
			"task 41 not inserted correctly");
	fail_unless(tpl_task_table[t41] -> next_set == tpl_task_table[t31],
		"task 41 not inserted correctly");
	fail_unless(tpl_task_table[t41] -> next_task == NULL,
		"task 41 has not a NULL next_task");
	fail_unless(tpl_task_table[t31] -> next_set == NULL,
		"task 31 has not a NULL next_set");
}
END_TEST		
START_TEST(tpl_put_task_insert_lowest_priority_task)
{	
	reinitInitVal();
	/* insert a task with the lowest priority: priority 1 */
	tpl_put_task(tpl_task_table[t31]);
	tpl_put_task(tpl_task_table[t21]);
	fail_unless(tpl_task_list_head == tpl_task_table[t31],
			"t11 not inserted correctly");
	fail_unless(tpl_task_table[t31] -> next_set == tpl_task_table[t21],
			"t11 not inserted correctly");
	fail_unless(tpl_task_table[t21] -> next_task == NULL,
		"task 21 has not a NULL next_task");
	fail_unless(tpl_task_table[t21] -> next_set == NULL,
		"task 21 has not a NULL next_set");

}
END_TEST		
START_TEST(tpl_put_task_insert_task_between_2_tasks)
{	
	reinitInitVal();
	tpl_put_task(tpl_task_table[t31]);
	tpl_put_task(tpl_task_table[t11]);
	/* insert a task at the between two tasks: priority 2 */
	tpl_put_task(tpl_task_table[t21]);
	fail_unless(tpl_task_table[t31] -> next_set == tpl_task_table[t21],
			"t21 not inserted correctly");
	fail_unless(tpl_task_table[t21] -> next_set == tpl_task_table[t11],
			"t21 not inserted correctly");			
	fail_unless(tpl_task_table[t21] -> next_task == NULL,
			"t21 not inserted correctly");

}
END_TEST		
START_TEST(tpl_put_task_insert_task_in_set)
{		
	reinitInitVal();
	tpl_put_task(tpl_task_table[t21]);
	/* insert a task in a set. */
	tpl_put_task(tpl_task_table[t22]);
	fail_unless(tpl_task_table[t21] -> next_task == tpl_task_table[t22],
			"error in adding  t22");
	fail_unless(tpl_task_table[t22] -> next_task == NULL,
			"error in adding t22");
}
END_TEST	
START_TEST(tpl_put_task_insert_task_in_set2)
{		
	reinitInitVal();

	tpl_put_task(tpl_task_table[t21]);
	tpl_put_task(tpl_task_table[t22]);
	/* insert a task in a set. */
	tpl_put_task(tpl_task_table[t23]);
	fail_unless(tpl_task_table[t22] -> next_task == tpl_task_table[t23],
			"error in adding  t23");
	fail_unless(tpl_task_table[t23] -> next_task == NULL,
			"error in adding t23");
}
END_TEST		
	
START_TEST(tpl_get_task_check)
{		
	tpl_task *tempTask;
	reinitInitVal();
	tpl_put_task(tpl_task_table[t21]);
	tpl_put_task(tpl_task_table[t31]);
	/* ok. Now check the get fonction. */
	tempTask = tpl_get_task();
	fail_unless(tpl_task_table[t31] == tempTask,"get task start");
	fail_unless(tpl_task_list_head == tpl_task_table[t21],"get task head");
}
END_TEST		
START_TEST(tpl_get_and_put_task)
{		
	reinitInitVal();
	tpl_put_task(tpl_task_table[t21]);
	tpl_put_task(tpl_task_table[t22]);
	tpl_put_task(tpl_task_table[t23]);
	/* put the task again. Must be at the end of the set. Check it
	 * t22 -> t23 -> t21
	 */
	tpl_put_task(tpl_get_task());
	fail_unless(tpl_task_list_head == tpl_task_table[t22],"error");
	fail_unless(tpl_task_table[t22] -> next_task == tpl_task_table[t23],"error");
	fail_unless(tpl_task_table[t23] -> next_task == tpl_task_table[t21],"error");
	fail_unless(tpl_task_table[t21] -> next_task == NULL,"reinit");
}
END_TEST		
START_TEST(tpl_get_task_check_next_set)
{		
	reinitInitVal();
	tpl_put_task(tpl_task_table[t21]);
	tpl_put_task(tpl_task_table[t22]);
	tpl_put_task(tpl_task_table[t11]);
	fail_unless(tpl_task_table[t21] -> next_set == tpl_task_table[t11]);
	fail_unless(tpl_task_table[t22] -> next_set == NULL);
	/* the next_set pointer is used only with the first task in the next_task list.
	 * if the head of the list is get, the pointer must be updated.
	 */
	tpl_get_task();
	fail_unless(tpl_task_table[t21] -> next_set == tpl_task_table[t11]);
}
END_TEST		

START_TEST(tpl_get_task_on_null_list)
{			
	tpl_task *tempTask;
	reinitInitVal();
	fail_unless(tpl_task_list_head == NULL, "head not NULL");
	tempTask = tpl_get_task(); /* remove nothing. */
	fail_unless(tempTask == NULL, "task not NULL");
}
END_TEST

START_TEST(ActivateNoRunningTask)
{
	tpl_status result;
	fail_unless(tpl_task_table[t11] -> state == SUSPENDED, "task not SUSPENDED");
	fail_unless(tpl_task_table[t11] -> activate_count == 0, "activation not ok");
	result = ActivateTask(t11);
	fail_unless(result==E_OK,"bad result in ActivateTask");
	/*only one task. Must be READY -> schedule -> RUNNING */
	fail_unless(tpl_task_table[t11] -> state == RUNNING, "task not RUNNING");
	fail_unless(tpl_task_table[t11] -> activate_count == 1, "activation not ok2");
}
END_TEST

START_TEST(ActivateHigherPriorityTask)
{
	ActivateTask(t11);
	fail_unless(tpl_task_table[t11] -> state == RUNNING, "task not RUNNING");
	fail_unless(tpl_task_table[t11] -> activate_count == 1, "activation not ok2");
	fail_unless(tpl_task_table[t21] -> state == SUSPENDED, "task not SUSPENDED");
	fail_unless(tpl_task_table[t21] -> activate_count == 0, "activation not ok");
	ActivateTask(t21);
	fail_unless(tpl_task_table[t11] -> state == READY, "task not READY");
	fail_unless(tpl_task_table[t11] -> activate_count == 1, "activation not ok2");
	fail_unless(tpl_task_table[t21] -> state == RUNNING, "task not RUNNING");
	fail_unless(tpl_task_table[t21] -> activate_count == 1, "activation not ok2");
}
END_TEST

START_TEST(ActivateLowerPriorityTask)
{
	ActivateTask(t21);
	fail_unless(tpl_task_table[t21] -> state == RUNNING, "task not RUNNING");
	fail_unless(tpl_task_table[t21] -> activate_count == 1, "activation not ok2");
	fail_unless(tpl_task_table[t11] -> state == SUSPENDED, "task not SUSPENDED");
	fail_unless(tpl_task_table[t11] -> activate_count == 0, "activation not ok");
	ActivateTask(t11);
	fail_unless(tpl_task_table[t11] -> state == READY, "task not READY");
	fail_unless(tpl_task_table[t11] -> activate_count == 1, "activation not ok2");
	fail_unless(tpl_task_table[t21] -> state == RUNNING, "task not RUNNING");
	fail_unless(tpl_task_table[t21] -> activate_count == 1, "activation not ok2");
}
END_TEST

START_TEST(ActivateARunningTask)
{
	ActivateTask(t21);
	fail_unless(tpl_task_table[t21] -> state == RUNNING, "task not RUNNING");
	fail_unless(tpl_task_table[t21] -> activate_count == 1, "activation not ok2");
	ActivateTask(t21);
	fail_unless(tpl_task_table[t21] -> state == RUNNING, "task not RUNNING");
	fail_unless(tpl_task_table[t21] -> activate_count == 2, "activation not ok2");
}
END_TEST

START_TEST(ActivateAReadyTask)
{
	ActivateTask(t21);
	ActivateTask(t11);
	fail_unless(tpl_task_table[t11] -> state == READY, "task not READY");
	fail_unless(tpl_task_table[t11] -> activate_count == 1, "activation not ok2");
	fail_unless(tpl_task_table[t21] -> state == RUNNING, "task not RUNNING");
	fail_unless(tpl_task_table[t21] -> activate_count == 1, "activation not ok2");
	ActivateTask(t11);
	fail_unless(tpl_task_table[t11] -> state == READY, "task not READY");
	fail_unless(tpl_task_table[t11] -> activate_count == 2, "activation not ok2");
}
END_TEST

START_TEST(ActivateAMaxActivatedTask)
{
	tpl_status result;
	ActivateTask(t11); /*max activation is 3 for t11*/
	ActivateTask(t11);
	ActivateTask(t11);
	fail_unless(tpl_task_table[t11] -> activate_count == 3, "activation not ok2");
	result = ActivateTask(t11);
	fail_unless(tpl_task_table[t11] -> activate_count == 3, "max activation not ok");
	fail_unless(result == E_OS_LIMIT, "not returning E_OS_LIMIT");
}
END_TEST

START_TEST(ActivateABadTasskID)
{
	tpl_status result;
	#ifdef OS_EXTENDED
		result = ActivateTask(30); /*bad task ID.*/
		fail_unless(result == E_OS_ID, "not returning E_OS_ID");
	#endif
}
END_TEST



Suite *trampoline_suite (void)
{
  Suite *s;
  TCase *tc_ActivateTask;
  TCase *tc_getPut;
  s = suite_create("Trampoline_ActivateTask");
  tc_getPut = tcase_create("tpl_put_task and tpl_get_task");
  suite_add_tcase (s, tc_getPut);
  tcase_add_test (tc_getPut, init_task_list_struct);
  tcase_add_test (tc_getPut, tpl_put_task_insert_first_task);
  tcase_add_test (tc_getPut, tpl_put_task_insert_highest_priority_task);
  tcase_add_test (tc_getPut, tpl_put_task_insert_lowest_priority_task);
  tcase_add_test (tc_getPut, tpl_put_task_insert_task_between_2_tasks);
  tcase_add_test (tc_getPut, tpl_put_task_insert_task_in_set);
  tcase_add_test (tc_getPut, tpl_put_task_insert_task_in_set2);
  tcase_add_test (tc_getPut, tpl_get_task_check);
  tcase_add_test (tc_getPut, tpl_get_and_put_task);
  tcase_add_test (tc_getPut, tpl_get_task_check_next_set);
  tcase_add_test (tc_getPut, tpl_get_task_on_null_list);
  
  tc_ActivateTask = tcase_create("ActivateTask");
  suite_add_tcase (s, tc_ActivateTask);
  tcase_add_test (tc_ActivateTask, ActivateNoRunningTask);
  tcase_add_test (tc_ActivateTask, ActivateHigherPriorityTask);
  tcase_add_test (tc_ActivateTask, ActivateLowerPriorityTask);
  tcase_add_test (tc_ActivateTask, ActivateARunningTask);
  tcase_add_test (tc_ActivateTask, ActivateAReadyTask);
  tcase_add_test (tc_ActivateTask, ActivateAMaxActivatedTask);
  tcase_add_test (tc_ActivateTask, ActivateABadTasskID);
  return s;
}

int main (void)
{
  int nf;
  Suite *s = trampoline_suite();
  SRunner *sr = srunner_create(s);
  srunner_run_all (sr, CK_VERBOSE); /* CK_NORMAL */
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (nf == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
