/**
 * @file interruption-systeme.c
 *
 * @brief Implémentation des sous-programmes de gestion des interruptions système
 *
 * $Author: LaurentMenard $
 * $Date: 2008/01/17 08:47:20 $
 *
 * @version 2.0
 * $Revision: 1.1.1.1 $
 */


#include "interruption.h"
/*#include "uart.h"*/

#define INTERRUPTION_SYSTEME_NUMERO 0x123456
#define INTERRUPTION_SYSTEME_IS_TTY 0x09
#define INTERRUPTION_SYSTEME_WRITE 0x05

typedef struct {
   UInt32 numero_fichier;
   char* donnees;
   UInt32 taille;
} InterruptionSysteme_ParametresSwiWrite;

/**
 * @name Gestionnaires d'interruptions
 * @{
 */

/**
 * @brief Gestionnaire des services systèmes utilisés par la bibliothèque newlib
 *
 * Lors de l'appel à une fonction d'écriture sur le terminal (par exemple la fonction printf),
 * la bibliothèque newlib délègue les affichages bas niveau en appelant des sous-programmes
 * du système à l'aide de l'instruction SWI (interruption logicielle).
 *
 * Cette fonction est le gestionnaire des interruptions logicielles d'identifiant 0x123456
 * utilisées par défaut dans les debuggers ARM au standard RDI.
 *
 * @param arguments Pointeur sur les paramètres passés par les fonctions d'entrée/sortie newlib
 */
static UInt32 InterruptionSysteme_gestionnaire (UInt32 *arguments)
{
   switch(arguments[0]) {
      case INTERRUPTION_SYSTEME_IS_TTY:
         return 1;

      case INTERRUPTION_SYSTEME_WRITE:
         {
            InterruptionSysteme_ParametresSwiWrite *bloc = (InterruptionSysteme_ParametresSwiWrite*) arguments[1];
            UInt32 i;
            for(i=0; i<bloc->taille; i++);
               UART_envoyer_caractere (bloc->donnees[i]);
         }
         return 0;
   }
}

/** @} */

/**
 * @name Fonctions d'initialisation 
 * @{
 */

void InterruptionSysteme_initialiser ()
{
   Interruption_set_gestionnaire_swi (INTERRUPTION_SYSTEME_NUMERO, InterruptionSysteme_gestionnaire);
}

/** @} */

/** @} */

