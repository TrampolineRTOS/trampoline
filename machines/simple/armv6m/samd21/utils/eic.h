#ifndef __EIC_H__
#define __EIC_H__
#include "clock.h"

#include "pinAccess.h"

//type de front
#define NONE    0 //rien
#define RISING  1 //front montant
#define FALLING 2 //front descendant
#define BOTH    3 //front montant ET descendant

//Détection de front sur une entrée EIC.
// * eicNum: numéro d'entrée EIC (0 à 15)
// * withFilter: valeur logique pour filtrage du signal d'entrée
// * edgeType: voir symboles au dessus: de NONE à BOTH
int EICConfig(unsigned char eicNum,
              unsigned char withFilter,
              unsigned char edgeType);

//initialisation de la source d'horloge EIC
//=> voir clock.h
int EICInitClock(int source);

#endif
