/**
 *
 * This application test the timers (timer0 to initialize lcd and timer1 with IRQ for systemcounter)
 * and the lcd in the same time.
 * prepare the binary to UBOOT 
* arm-elf-objcopy -R .comment -O binary  armadeus_apf9328_exe  /tmp/armadeus_apf9328_exe
 * and uplaod the image on the board
 *
 */


#include "tpl_os.h"

#define APP_Task_task1_START_SEC_CODE
#include "tpl_memmap.h"

FUNC(int, OS_APPL_CODE) main(void)
{            
	
	
	
	
	
	
	
	
	unsigned long value = 0xffffffff;
	unsigned long * adresse ;
	char tab[1024];
	adresse = 0x21c300;
	int b=0,a=0;

    StartOS(OSDEFAULTAPPMODE);
	
    return 0;
}
#define APP_Task_task1_STOP_SEC_CODE
#include "tpl_memmap.h"


#define OS_START_SEC_VAR_32BIT
#include "tpl_memmap.h"
VAR(int, OS_VAR) switch_count = 0;
VAR(TaskType, OS_VAR) new_task;
#define OS_STOP_SEC_VAR_32BIT
#include "tpl_memmap.h"

#define APP_Task_task1_START_SEC_CONST_32BIT
#include "tpl_memmap.h"
CONST(int, AUTOMATIC) toto = 0;
#define APP_Task_task1_STOP_SEC_CONST_32BIT
#include "tpl_memmap.h"

#define APP_Task_task1_START_SEC_VAR_32BIT
#include "tpl_memmap.h"
VAR(int, AUTOMATIC) titi = 0;
#define APP_Task_task1_STOP_SEC_VAR_32BIT
#include "tpl_memmap.h"


DeclareTask(task1);


#define APP_Task_task1_START_SEC_CODE
#include "tpl_memmap.h"
#define ADRESSETIME 0x204004;
#define LEDON  0xffffffff;
#define LEDOFF 0x00000000;
#define ADRESSELED  0x21c300;

static void ledOn(){
	unsigned long * adresse ;
	adresse = (unsigned long *)ADRESSELED;
	*adresse = LEDON;
}


static void ledOff(){
	unsigned long * adresse ;
	adresse = (unsigned long *)ADRESSELED;
	*adresse = LEDOFF;
}
static void pause(int delay){
	unsigned long * adresse ;
	int c=0,d = 0;
	adresse =(unsigned long *) ADRESSETIME;
	*adresse = c;
	
	while((d-c) != delay){
		d = * adresse;
	}
	
	
	
}

TASK(task1)
{
	unsigned long value = 0xffffffff;
	unsigned long * adresse ;
	adresse = 0x21c300;
	
	int (*printf)( const char *format, ...) = 0x0bf90e34;//adresse du printf de uboot
	
	while(1) {
		ledOn();
		pause(1);
		printf("Led Off \n");
		ledOff();
		
		pause(3);
		printf("Led ON \n");
	}
	
	TerminateTask();
    
}
TASK(task2)
{
}

#define APP_Task_task1_STOP_SEC_CODE
#include "tpl_memmap.h"

