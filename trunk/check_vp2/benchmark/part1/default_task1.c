//tpl_task_table[step1]->exec_desc.activate_count=0;




#include "../os/tpl_os.h"
#include "tpl_os_generated_configuration.h"
#include <stdio.h>

#include "tpl_benchmark.h"
#include "tpl_os_it.h"

#define UNUSED 0
#define USED 1
#define ONGOING 2


#include "tpl_os_kernel.h"

// Definition of the pointeur
unsigned int tpl_benchmark_tick = 0;

// Definition of the structure

struct TPL_STRUCT_BENCHMARK {
			VAR(u8, AUTOMATIC) used; 
			/* used may be in 3 states
			  	- UNUSED : if the function is not used
				- ONGOING : if the measure of function is ongoing 
				- USED : if the measure is already do           	*/

			VAR(u16, AUTOMATIC) time;
			/* time contains the length of execution of function    */

			};

typedef struct TPL_STRUCT_BENCHMARK tpl_struct_benchmark;

VAR(tpl_struct_benchmark, AUTOMATIC) tpl_benchmark[21];

VAR(u16, AUTOMATIC) time;  // intermediate variable to memorize the time

VAR(u8, AUTOMATIC) i;

 

void tpl_init_benchmark_timer();



void InitApp(void)
{
	tpl_init_benchmark_timer();
	for ( i=0;i<=20;i++ )
		{
		tpl_benchmark[i].used = UNUSED;
		tpl_benchmark[i].time = 0;
		} 
}


void tpl_load_value(int number)
	{
	tpl_benchmark[number].time = time;
	tpl_benchmark[number].used = USED;
	}


#define tpl_measure_state(number) tpl_benchmark[number].used

#define tpl_take_value(number) tpl_benchmark[number].time

void tpl_change_state (int number,u8 state)
	{
	tpl_benchmark[number].used = state;
	}


void time_alarm (void)
{
if(tpl_benchmark_tick > time)
	{
	tpl_benchmark_tick = 0 - tpl_benchmark_tick;
	time += tpl_benchmark_tick;
	}
else{time -= tpl_benchmark_tick;}
}

void result_edition (void)
{
time = get_tb();	  // Memorization of time

//********************************************************************************

//SuspendAllInterrupts();
/*edition of result*/
	putchar('+'); // point out the beginning of send data
	
	for(i=0;i<=20;i++)
		{
			// send the number of the function
			printf("%c : ",i+'A');

			// if the measure is do, his value is send
			if (tpl_measure_state(i) == USED)
				{printf("%d %cs@\n", (tpl_take_value(i)* TPL_BENCHMARK_MULTIPLIER / TPL_BENCHMARK_DIVISOR ), TPL_BENCHMARK_UNIT );
				}

			// else, send unused
			else printf("unused@\n");

			// initialization of structure
			tpl_change_state (i,UNUSED);
		}
	
	putchar('*'); // point out the end of send data
//EnableAllInterrupts();
}


TASK(step1)
{
	time = get_tb();	  // Memorization of time
	time_alarm();
	if(tpl_measure_state(1) == UNUSED)
	{

	/*Function n0 : Alarm => Result*/
	tpl_load_value(0);

	/*Start of Benchmark*/
	printf("\nStart@\n");


//********************************************************************************
	/*Function n1.1 : ActivateTask_NEX_1 => Start*/
	set_tb();
	ActivateTask(step2);
	time = get_tb();	   // Memorization of time

	/*Function n1.1 : ActivateTask_NEX_1 => Result*/
	tpl_load_value(1);

	/*Function n1.2 : ActivateTask_NEX_2 => Start*/
	set_tb();
	ActivateTask(step2);

	time = get_tb();	   // Memorization of time

	/*Function n1.2 : ActivateTask_NEX_2 => Result*/
	tpl_load_value(2);

	/*Function n1.3 : ActivateTask_NEX_3 => Start*/
	set_tb();
	ActivateTask(step2);

	time = get_tb();	   // Memorization of time

	/*Function n1.3 : ActivateTask_NEX_3 => Result*/
	tpl_load_value(3);
//********************************************************************************
	/*Function n2.1 : ActivateTask_EX_1 => Start*/
	set_tb();
	ActivateTask(pool);

	time = get_tb();	   // Memorization of time

	/*Function n2.1 : ActivateTask_EX_1 => Result*/
	tpl_load_value(4);

	/*Function n2.2 : ActivateTask_EX_2 => Start*/
	set_tb();
	ActivateTask(pool);

	time = get_tb();	   // Memorization of time

	/*Function n2.2 : ActivateTask_EX_2 => Result*/
	tpl_load_value(5);

	/*Function n2.3 : ActivateTask_EX_3 => Start*/
	set_tb();
	ActivateTask(pool);

	time = get_tb();	   // Memorization of time

	/*Function n2.3 : ActivateTask_EX_3 => Result*/
	tpl_load_value(6);

//********************************************************************************
	
	/*Function n3.1 : ActivateTask_P>_NEX => Start*/
	set_tb();
	ActivateTask(pool2);

//********************************************************************************
	}
	i=0;
    TerminateTask();
}

  
TASK(step2)
{
	time = get_tb();	   // Memorization of time

		if(tpl_measure_state(17) == UNUSED)
			{
			/*Function n7.1 : WaitEvent1 => Result*/
			tpl_load_value(17);
			}
		else 
			{
			/*Function n7.3 : SetEvent => Start*/
			tpl_change_state(19,ONGOING);
			}
			
			
			/*Function n7.2 : WaitEvent2 => Start*/
			set_tb();
			SetEvent(pool,EV1);

			time = get_tb();	   // Memorization of time

			if(tpl_measure_state(19) == ONGOING)
			{
			/*Function n7.3 : SetEvent => Result*/
			tpl_load_value(19);

			result_edition();
			}

			TerminateTask();
}


TASK(pool)
{
	if(i == 0){i++;TerminateTask();}
	
	/*Function n6.1 : GetResource => Start*/
	set_tb();
	GetResource(test);

	time = get_tb();		 // Memorization of time

	/*Function n6.1 : GetResource => Result*/
	tpl_load_value(15);

	/*Function n6.2 : ReleaseResource => Start*/
	set_tb();
	ReleaseResource(test);
  
	time = get_tb();		 // Memorization of time

	/*Function n6.2 : ReleaseResource => Result*/
	tpl_load_value(16);

//********************************************************************************

	/*Function n7.1 : WaitEvent1 => Start*/
	set_tb();
	WaitEvent(EV1);
	

	time = get_tb();     // Memorization of time
		
	/*Function n7.2 : WaitEvent2 => Result*/
	tpl_load_value(18);

	/*Function n7.4 : ClearEvent => Start*/
    set_tb();
	ClearEvent(EV1);

	time = get_tb();     // Memorization of time

	/*Function n7.4 : ClearEvent => Result*/
	tpl_load_value(20);

	TerminateTask();
}

TASK (pool2)
{
	time = get_tb();	   // Memorization of time
		

	if (tpl_measure_state(7) == UNUSED)
		{
		/*Function n3.1 : ActivateTask_P>_NEX => Result*/
		tpl_load_value(7);
		/*Function n3.2 : ActivateTask_P>_EX => Start*/
		set_tb();
		ActivateTask(pool3);

//********************************************************************************

		time = get_tb();	   // Memorization of time

		/*Function n4.1 : TerminateTask1 => Result*/
		tpl_load_value(9);
		/*Function n4.2 : TerminateTask2 => Start*/
		set_tb();
		TerminateTask();
		}
	else
		{
		if (tpl_measure_state(10) == UNUSED) 
			{
			/*Function n4.2 : TerminateTask2 => Result*/
			tpl_load_value(10);

//********************************************************************************

			/*Function n5.1 : ChainTask1 => Start*/
			set_tb();
			ChainTask(pool3);
			}
		else
			{
			if (tpl_measure_state(12) == UNUSED) 
				{
				/*Function n5.2 : ChaineTask2 => Result*/
				tpl_load_value(12);

				ActivateTask(pool3);

				time = get_tb();	   // Memorization of time

				/*Function n5.3 : ChaineTask3 => Result*/
				tpl_load_value(13);

				/*Function n5.4 : ChainTask4 => Start*/
				set_tb();
				ChainTask(pool2);
				}
			else
				{
				if (tpl_measure_state(14) == UNUSED) 
					{
					/*Function n5.5 : ChaineTask5 => Result*/
					tpl_load_value(14);
					TerminateTask();
					}
				else{TerminateTask();}
				}
			}
		}
}


TASK (pool3)
{
	time = get_tb();	   // Memorization of time

	if(tpl_measure_state(8) == UNUSED)
		{
		/*Function n3.2 : ActivateTask_P>_EX => Result*/
		tpl_load_value(8);

		ActivateTask(pool2);

//********************************************************************************

		/*Function n4.1 : TerminateTask1 => Start*/
		set_tb();
		TerminateTask();

//********************************************************************************

		}
	else
		{
		if(tpl_measure_state(11) == UNUSED)
			{
			/*Function n5.1 : ChaineTask1 => Result*/
			tpl_load_value(11);
			/*Function n5.2 : ChainTask2 => Start*/
			set_tb();
			ChainTask(pool2);
			}
		else
			{
			if(tpl_measure_state(13) == UNUSED)
				{
				/*Function n5.3 : ChainTask3 => Start*/
				set_tb();
				ChainTask(pool2);
				}
			 else
				{
				  TerminateTask();
				}
			}
		}
}		
