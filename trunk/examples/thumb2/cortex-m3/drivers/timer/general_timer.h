
/*=======================================================================================
	Auteur T.R.
	sept 2010
	Processeur : STM32F103RB
	Logiciel dev : µVision 4
	Module qui configure les general-purpose timers
=======================================================================================
REVS
	PEH 01/11/2010 remise en forme du code et remonage du pilote en general_timer
	suppression du TIM1 dans le configuration, devra tre fait ˆ part.

======================================================================================= */

#ifndef _GENERAL_TIMER_H__
#define _GENERAL_TIMER_H__

#include "stm_regs.h" 

/**
* Initialize general purpose timer
* @param *timer [TIM2, TIM3, TIM4]
* @param frequency in Hz
**/
void General_Timer_Init(TIM_TypeDef *timer, u32 frequency );

/**
* Configure the interruption of the counter of a timer
* @param *timer [TIM2, TIM3, TIM4]
* @param priority of the interruption [0..15]
**/
void General_Timer_Configure_Counter_IT(TIM_TypeDef *timer, u8 priority);

/**
* Configure a channel of a timer as a PWM (the port as to be configured as alternate push_pull)
* @param *timer [TIM2, TIM3, TIM4]
* @param channel to configure
* @param frequency of the PWM in Hz
**/
void General_Timer_Configure_As_PWM(TIM_TypeDef *Timer, u8 channel, u32 frequency);

																					 /**
* Configure a channel of a timer as a PWM (the port as to be configured as alternate push_pull)
* @param *timer [TIM2, TIM3, TIM4]
* @param channel to configure
* @param duty_cycle in percentage [0..100]
**/
void General_Timer_Set_Duty_Cyle_PWM(TIM_TypeDef *Timer, u8 channel, u32 duty_cycle);









//___________________________________________________________________________________
//
//    Programmation du timer en mode codeur incrémental
//___________________________________________________________________________________
//
//________ Rappel sur les ressources __________________________________________________
//
//  3 Timer "general Purpose", TIM2, TIM3 et TIM4
//  Chacun d'entre eux dispose de 4 voies de sorties numérotées de 1 à 4
//  Mapping des IO:
//  	TM2_CH1_ETR - PA0 	TM3_CH1 - PA6		TIM4_CH1 - PB6	
//    	TM2_CH2 - PA1		TM3_CH2 - PA7		TIM4_CH2 - PB7

//
//   Dans ce mode, le timerx utilise les 2 entrées 1 et 2
//
//
//  ________ Comment utiliser la lib ? __________________________________________________
//   
// char Timer_Inc_Init(char Timer, char Resolution);
// C'est la fonction de configuration du timer en question en mode codeur incrémental
//		-  	renvoie un char (erreur), 0 si OK, 1 s'il s'est produit une erreur.
//    	- 	char Timer : de 2 à 4 spécifie le numéro de timer
// 		-  	char Resolution	:  1 cptag/dectpage sur front up/down de ch2 (réso dique *2)
//							   2 cptag/dectpage sur front up/down de ch1 (réso dique *2)
//							   3 cptag/dectpage sur front up/down de ch1 et ch2	(réso dique *4)
// Le user doit placer les bonnes broches en entrée
//__________ Exemple de configuration : _________________________________________________
//
// 
//
//=======================================================================================

char Timer_Inc_Init(TIM_TypeDef *Timer, char Resolution);

#define Reso_Demie_Per_Ch1 2
#define Reso_Demie_Per_Ch2 1
#define Reso_Quart_Per 3

#define Reset_Timer_2 TIM2->CNT=0
#define Reset_Timer_3 TIM3->CNT=0
#define Reset_Timer_4 TIM4->CNT=0

// permet de récupérer la valeur du codeur incrémental correspondant au timer spécifié
// ex : Valeur = CodeurInc(TIM3);
#define CodeurInc(Tim) Tim->CNT; 


//___________________________________________________________________________________
//
//    Programmation du timer en mode capture 
//___________________________________________________________________________________
//

vu16 Capture_Init(TIM_TypeDef *Timer, char Voie, float Largeur_Pulse_Max_us, vu16 Resolution, char Prio);
//
// Configure le périphérique timer cité de manière à
// - pouvoir capturer une durée dont la maximum est précisé
// - avec une résolution donnée
// - Sur la voie précisée
// - la mesure de durée se fait par IT dont la priorité est Prio
// Renvoie la résolution effective. 0 s'il y a un pb.
// Capture sur front montant puis descendant.
// 4 mesures possibles par timer, mais bien sûr avec la même réso

vu16 Lire_Duree_Pulse(TIM_TypeDef *Timer,int Voie);
// placer TIM1 à TIM4, et le numéro de voie, 1 à 4.


#endif
