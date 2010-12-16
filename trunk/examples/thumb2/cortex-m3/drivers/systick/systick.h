
/*=======================================================================================
 	Auteur T.R.
  2 Oct 2010
  Processeur : STM32F103RB
  Logiciel dev : µVision 4
  Module qui configure le timer système Systick
  Validé en simu
________________________________________________________________________________________
REVS
	[PEH 01/11/2010] Remise en forme des prototypes et indŽpendance des fonctions d'IT
	avec les configuration
________________________________________________________________________________________
TODO

=======================================================================================*/



#ifndef _TIMER_SYSTICK_H__
#define _TIMER_SYSTICK_H__

#include "stm_regs.h"
/***
** Initialize the systick timer
** @param frequency in Hz of the systick timer
** @param priority of the IT
***/

void Init_Systick(u32 frequency, u8 priority);


#endif
