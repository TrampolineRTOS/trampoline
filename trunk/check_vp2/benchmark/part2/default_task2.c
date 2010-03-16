#include "../os/tpl_os.h"
#include "tpl_os_generated_configuration.h"
#include <stdio.h>

#include "tpl_benchmark.h"
#include "tpl_os_it.h"

# define UNUSED 0
# define USED 1
# define ONGOING 2

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

VAR(tpl_struct_benchmark, AUTOMATIC) tpl_benchmark[16];

VAR(u16, AUTOMATIC) time;  // intermediate variable to memorize the time

VAR(u8, AUTOMATIC) i;

int get_tb();
void set_tb(); 

void tpl_init_benchmark_timer();


void InitApp(void)
{
	tpl_init_benchmark_timer();
	for ( i=0;i<=15;i++ )
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


void alarm_callback_testCallBack (void)
{
	time = get_tb();	  // Memorization of time
	time_alarm();

	/*Function n10 : Alarm_CallBack => Result*/
	tpl_load_value(6);
}


void result_edition (void)
{
time = get_tb();	  // Memorization of time

/*Function n15 : call_function => Result*/
tpl_load_value(15);

//********************************************************************************

SuspendAllInterrupts();
/*edition of result*/
	putchar('+'); // point out the beginning of send data
	
	for(i=0;i<=15;i++)
		{
			// send the number of the function
			printf("%c : ",i+'V');

			// if the measure is do, his value is send
			if (tpl_measure_state(i) == USED)
				{printf("%d %cs@\n", (tpl_take_value(i)*TPL_BENCHMARK_MULTIPLIER/TPL_BENCHMARK_DIVISOR),TPL_BENCHMARK_UNIT);
				}

			// else, send unused
			else printf("unused@\n");

			// initialization of structure
			tpl_change_state (i,UNUSED);
		}
	
	putchar('*'); // point out the end of send data
EnableAllInterrupts();
}


TASK(step1)
{
	/*Start of Benchmark*/
	printf("\nStart@\n");
//********************************************************************************

	ActivateTask(pool1);

//********************************************************************************	
	i=0;
    TerminateTask();
}


TASK(pool1)  
{
	/*Cancel of the global alarm*/
	CancelAlarm(ZeAlarm);

	/*Function n8.11 : SetRelAlarm1 => Start*/
	set_tb();
	SetRelAlarm(Alarm1,50,1);

	time = get_tb();     // Memorization of time

	/*Function n8.11 : SetRelAlarm1 => Result*/
	tpl_load_value(0);

		/*Start of all alarms*/
		SetRelAlarm(Alarm2,50,1);
		SetRelAlarm(Alarm3,50,1);
		SetRelAlarm(Alarm4,50,1);

	/*Function n8.12 : SetRelAlarm2 => Start*/
	set_tb();
	SetRelAlarm(Alarm5,50,1);
  
	time = get_tb();     // Memorization of time

	/*Function n8.12 : SetRelAlarm2 => Result*/
	tpl_load_value(1);

		/*Start of all alarms*/
		SetRelAlarm(Alarm6,50,1);
		SetRelAlarm(Alarm7,50,1);
		SetRelAlarm(Alarm8,50,1);
 	    SetRelAlarm(Alarm10,50,1);

	/*Function n8.13 : SetRelAlarm3 => Start*/
	set_tb();
	SetRelAlarm(Alarm9,55,1);
  
	time = get_tb();     // Memorization of time

	/*Function n8.13 : SetRelAlarm3 => Result*/
	tpl_load_value(2);


	/*Function n8.21 : CancelAlarm1 => Start*/
	set_tb();
	CancelAlarm(Alarm10);
  
	time = get_tb();     // Memorization of time

	/*Function n8.21 : CancelAlarm1 => Result*/
	tpl_load_value(3);

    	/*Stopping of all alarms*/
		CancelAlarm(Alarm2);
		CancelAlarm(Alarm3);
		CancelAlarm(Alarm4);
		CancelAlarm(Alarm5);
		CancelAlarm(Alarm6);
		CancelAlarm(Alarm7);				   
		CancelAlarm(Alarm8);
		CancelAlarm(Alarm9);

	/*Function n8.22 : CancelAlarm2 => Start*/
	set_tb();
	CancelAlarm(Alarm1);

	time = get_tb();     // Memorization of time

	/*Function n8.22 : CancelAlarm2 => Result*/
	tpl_load_value(4);

//********************************************************************************

	/*Function n9 : Alarm_SetEvent => Start*/
	SetRelAlarm(Alarm3,2,1);
	set_tb();
	WaitEvent(EV3);

	time = get_tb();	  // Memorization of time
	time_alarm();

	/*Function n9 : Alarm_SetEvent => Result*/
	tpl_load_value(5);

	CancelAlarm(Alarm3);
	
//********************************************************************************

	/*Function n10 : Alarm_CallBack => Start*/
	SetRelAlarm(Alarm4,2,1);

	while(tpl_measure_state(6)!=USED);

	CancelAlarm(Alarm4); 

//********************************************************************************

	/*Function n11 : Alarm_ActivateTask_EX => Start*/
	SetRelAlarm(Alarm5,1,1);

	i=0;
	set_tb();
	while (i!=1)
		{
		if(tpl_task_table[pool4]->exec_desc.activate_count==1)
			{
			time = get_tb();
			time_alarm();

			/*Function n11.1 : Alarm_ActivateTask_EX_1 => Result*/
			tpl_load_value(7);
			i=1;
			}
		}
	set_tb();
	while (i!=2)
		{
		if(tpl_task_table[pool4]->exec_desc.activate_count==2)
			{
			time = get_tb();
			time_alarm();

			/*Function n11.2 : Alarm_ActivateTask_EX_2 => Result*/
			tpl_load_value(8);
			i=2;
			}
		}
	tpl_benchmark_tick=0;
	set_tb();
	while (i!=3)
		{
		if(tpl_benchmark_tick!=0)
			{
			time = get_tb();
			time_alarm();

			/*Function n11.3 : Alarm_ActivateTask_EX_3 => Result*/
			tpl_load_value(9);
			i=3;
			}
		}
	CancelAlarm(Alarm5);
	
//********************************************************************************

	/*Function n12 : Alarm_ActivateTask_NEX => Start*/				  
	SetRelAlarm(Alarm6,1,1);
	i=0;
	set_tb();
	while (i!=1)
		{
		if(tpl_task_table[pool5]->exec_desc.activate_count==1)
			{
			time = get_tb();
			time_alarm();

			/*Function n12.1 : Alarm_ActivateTask_NEX_1 => Result*/
			tpl_load_value(10);
			i=1;
			}
		}
   set_tb();
	while (i!=2)
		{
		if(tpl_task_table[pool5]->exec_desc.activate_count==2)
			{
			time = get_tb();
			time_alarm();

			/*Function n12.2 : Alarm_ActivateTask_NEX_2 => Result*/
			tpl_load_value(11);
			i=2;
			tpl_benchmark_tick=0;
			}
		}
	set_tb();
	while (i!=3)
		{
		if(tpl_benchmark_tick!=0)
			{
			time = get_tb();
			time_alarm();

			/*Function n12.2 : Alarm_ActivateTask_NEX_2 => Result*/
			tpl_load_value(12);
			i=3;
			}
		}
	CancelAlarm(Alarm6);  

//********************************************************************************

	/*Restart of the global alarm*/
	SetRelAlarm(ZeAlarm,1000,1000);
	i=0;
   TerminateTask();
}


TASK (pool2)
{
	time = get_tb();	   // Memorization of time
		
//********************************************************************************
	
	/*Function n13.2 : Alarm_ActivateTask_P>_NEX => Result*/
	if (tpl_measure_state(14) == ONGOING)
		{
		time_alarm();
		tpl_load_value(14);
		TerminateTask();
		}
	TerminateTask();
}



 TASK(pool4)
{
	time = get_tb();

	if(tpl_measure_state(13) == UNUSED){TerminateTask();}
	
	time_alarm();

	/*Function n13.1 : Alarm_ActivateTask_P>_EX => Result*/
	tpl_load_value(13);
	CancelAlarm(Alarm5);
	tpl_change_state(14,ONGOING);

	/*Function n13.2 : Alarm_ActivateTask_P>_NEX => Start*/
	set_tb();
	SetRelAlarm(Alarm7,1,1);
	while(tpl_measure_state(14)!=USED);
	CancelAlarm(Alarm7);

	TerminateTask();
}


 TASK(pool5)
{
	if (tpl_measure_state(13)==UNUSED)
		{
		
//********************************************************************************

		/*Function n13.1 : Alarm_ActivateTask_P>_EX => Start*/
		tpl_change_state(13,ONGOING);
		set_tb();
		SetRelAlarm(Alarm5,1,1);
		while(tpl_measure_state(13)!=USED);

//********************************************************************************		
		}
	else
		{
		/*Function n15 : call_function => Start*/
		set_tb();
		result_edition();
		}

	TerminateTask();
}

