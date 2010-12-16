
/*=======================================================================================
 	Auteur T.R.
  02 Oct 2010
  Processeur : STM32F103RB
  Logiciel dev : µVision 4
  Module qui configure le système d'IT externe (IT sur front d'une broche)
________________________________________________________________________________________
REVS
	[PEH 01/11/2010] Remise en forme des prototypes suppression du la configuration des
	ports directements pour les IT externes afin de rendre indŽpendant le pilote.
________________________________________________________________________________________
TODO

=======================================================================================*/

#ifndef _NVIC_IT_EXT_H__
#define _NVIC_IT_EXT_H__

#include "stm_regs.h"


// Front
#define FALLING_EGDE 0
#define RISING_EDGE 1
#define FALLING_RISING_EDGE 2

/**
* Configure an external IT
* @param line_number connected [0..15]
* @param edge to react (see definitions)
* @param priority [0..15]
**/
void NVIC_Ext_IT (u8 line_number, u8 edge, u8 priority);


#endif
