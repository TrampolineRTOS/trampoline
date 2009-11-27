#include "tpl_os.h"
#include <stdio.h>
#include "tpl_default_tasks_workstation.h"

/* define */
#define CYCLETIME = 100

/* Variable initialisation */
int motor_speed = 20;
static unsigned char minutes = 0;
static char secondes = -1;
static unsigned char i = 0;
static char affPeriodeStr[] = {'0','0','0','0',' ','m','s'};
static char affichageStr[5] = {'0','0',':','0','0'};
int periode_per_ten;
unsigned char signa_sin[10] = {0,78,149,206,242,255,242,206,149,78};

/* Task declaration */
DeclareAlarm(alarmeHeure);
DeclareAlarm(alarmeSignal);
DeclareTask(gestionSignal);
DeclareTask(gestionHeure);
DeclareResource(ressourceAfficheur);
DeclareResource(ressourceConfigAlarme);
DeclareTask(BPMoins);
DeclareTask(BPPlus);

int main(void)
{
	InitApp();
    StartOS(OSDEFAULTAPPMODE);
    return 0;
}

void StartupHook(void)
{
    printf("[TPL] Starting !\n");
}

void ShutdownHook(StatusType error)
{
    printf("[TPL] Ending !\n");
}

TASK(Init){
    
	GetResource(ressourceAfficheur);
	affichePeriode();
	ReleaseResource(ressourceAfficheur);
	TerminateTask();
}

TASK(gestionSignal)
{	
	/* start dialoguing DAC */
	start_dialoguing_dac();
	
	i++;
	if ( i == 10 )
	{
		i = 0;
	}
	/* send value to DAC */
    dac(signa_sin[i]);
    
	
	/* stop dialoguing DAC */
	stop_dialoguing_dac();
	
	TerminateTask();
}


TASK(gestionHeure)
{
	/* start dialoguing lcd */
	start_dialoguing_lcd();

	secondes++;
	if(secondes == 60) {
		secondes = 0;
		minutes++;
	}
	GetResource(ressourceAfficheur);
	afficheHeure(minutes, secondes);
	ReleaseResource(ressourceAfficheur);
	
	/* stop dialoguing lcd */
	stop_dialoguing_lcd();
	
	TerminateTask();
}

ISR(BPMoins) 
{
	GetResource(ressourceConfigAlarme);
	periode_per_ten -= 1;
	if(periode_per_ten < 1) periode_per_ten = 1;
	CancelAlarm(alarmeSignal);
	SetRelAlarm(alarmeSignal, periode_per_ten, periode_per_ten);
	ReleaseResource(ressourceConfigAlarme);
	
	GetResource(ressourceAfficheur);
	affichePeriode();
	ReleaseResource(ressourceAfficheur);
	
}

ISR(BPPlus)
{
	GetResource(ressourceConfigAlarme);
	periode_per_ten += 1;
	if(periode_per_ten > 50) periode_per_ten = 50;
	CancelAlarm(alarmeSignal);
	SetRelAlarm(alarmeSignal, periode_per_ten, periode_per_ten);
	ReleaseResource(ressourceConfigAlarme);
	
	GetResource(ressourceAfficheur);
	affichePeriode();
	ReleaseResource(ressourceAfficheur);
	
} 

void InitApp(void)
{
	/*DP2 |= 0x0C00; //COMP0 et COMP1 en sortie.
	 lcd_Init();	
	 
	 DP8 = 0xFF; //init P8 en sortie.
	 //initialisation du tableau pour le signal sinusoidal.
	 
	 //configuration des boutons poussoirs. Trap 10 et 11, CC0IC et CC1IC.
	 //CCMODx = 001 -> capture on positive transition.
	 CCM0 = 0x011; //capture pour CC0 et CC1. (BP0 et BP1)
	 //validation des ITs.
	 CC0IC = 0x68; //IE=1, LVL 10, GLVL 0
	 CC1IC = 0x69; //IE=1, LVL 10, GLVL 1
	 */
	
	periode_per_ten = 2;
}

void afficheHeure(const unsigned char minutes, const unsigned char secondes)
{
	affichageStr[0] = (minutes /10) % 10 + '0';
	affichageStr[1] = minutes % 10 + '0';
	affichageStr[3] = (secondes /10) % 10 + '0';
	affichageStr[4] = secondes % 10 + '0';
	
	/* send string to lcd 1 */
	lcd1(affichageStr); 
}

void affichePeriode()
{
	int periode = periode_per_ten*10;
	affPeriodeStr[0] = periode/100 %10 + '0';
	affPeriodeStr[1] = periode/10 %10 + '0';
	affPeriodeStr[2] = periode %10 + '0';
	
	/* send string to lcd 2 */
	lcd2(affPeriodeStr); 

}


