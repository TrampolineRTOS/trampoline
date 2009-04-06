/**
 * @addtogroup pilote_arm_timer
 * @{
 */

/**
 * @file Timer.c
 *
 * @brief Implémentation du pilote des timers du microcontrôleur OKI ML675001
 *
 * $Author$
 * $Date$
 *
 * @version 2.0
 * $Revision$
 */

#include "timer.h"
#include "timer_registres.h"
#include "timer_parametres_possibles.h"
#include "timer_configuration_par_defaut.h"
#include "horloge.h"

static Timer* Timer_instances;

/**
 * @name Fonction d'initialisation
 * @{
 */

void Timer_initialiser ()
{
	   int t;
	
   /** @todo N'activer que les horloges des timers qui seront utilisés */
   Horloge_activer (HORLOGE_TIMER0);
   Horloge_activer (HORLOGE_TIMER1);
   Horloge_activer (HORLOGE_TIMER2);
   Horloge_activer (HORLOGE_TIMER3);
   Horloge_activer (HORLOGE_TIMER4);
   Horloge_activer (HORLOGE_TIMER5);

   Timer_instances = (Timer*)TIMER_ADRESSE_BASE;
   

   for(t=0; t<TIMER_NOMBRE; t++)
   {
      Timer_arreter (t);
      Timer_acquitter_evenement (t);
      Timer_desactiver_interruptions (t);
      Timer_set_mode (t, TIMER_MODE_PAR_DEFAUT);
      Timer_set_prediviseur (t, TIMER_PREDIVISEUR_PAR_DEFAUT);
      Timer_set_valeur_initiale (t, TIMER_VALEUR_INITIALE_PAR_DEFAUT);
      Timer_set_valeur_finale (t, TIMER_VALEUR_FINALE_PAR_DEFAUT);
   }
}

/** @} */

/**
 * @name Fonctions de configuration
 * @{
 */

void Timer_set_mode (int timer, int mode)
{
	Timer_instances[timer].cntl.mode = mode;
}

void Timer_set_prediviseur (int timer, int pre)
{
   Timer_instances[timer].cntl.clksel = pre;
}

void Timer_set_valeur_initiale (int timer, UInt16 valeur)
{
  	Timer_instances[timer].base.valeur = valeur;
}

void Timer_set_valeur_finale (int timer, UInt16 valeur)
{
  	Timer_instances[timer].cmp.valeur = valeur;
}

UInt32 Timer_set_periode (int timer, UInt32 duree)
{
   UInt32 modulo = Horloge_get_frequence_compteurs () / 1000000 * duree;
   UInt32 prediviseur = 1;
   UInt32 postdiviseur = 1;

   while(modulo > 0x10000) {
      modulo /= 2;
      if(prediviseur < 32)
         prediviseur *= 2;
      else
         postdiviseur *= 2;
   }

   switch(prediviseur) {
      case 1: Timer_set_prediviseur (timer, TIMER_PREDIVISEUR_1); break;
      case 2: Timer_set_prediviseur (timer, TIMER_PREDIVISEUR_2); break;
      case 4: Timer_set_prediviseur (timer, TIMER_PREDIVISEUR_4); break;
      case 8: Timer_set_prediviseur (timer, TIMER_PREDIVISEUR_8); break;
      case 16: Timer_set_prediviseur (timer, TIMER_PREDIVISEUR_16); break;
      case 32: Timer_set_prediviseur (timer, TIMER_PREDIVISEUR_32);
   }

   Timer_set_valeur_initiale (timer, 0);
   Timer_set_valeur_finale (timer, modulo-1);

   return postdiviseur;
}

/** @} */

/**
 * @name Fonctions de gestion des événements
 * @{
 */

void Timer_activer_interruptions (int timer)
{
   Timer_instances[timer].cntl.ie = TIMER_ACTIVER_INTERRUPTIONS;
}

void Timer_desactiver_interruptions (int timer)
{
   Timer_instances[timer].cntl.ie = TIMER_DESACTIVER_INTERRUPTIONS;
}

int Timer_evenement (int timer)
{
   return Timer_instances[timer].stat.status == TIMER_DEBORDEMENT;
}

void Timer_acquitter_evenement (int timer)
{
   Timer_instances[timer].stat.status = TIMER_ACQUITTER_INTERRUPTION;
}

/** @} */

/**
 * @name Fonctions de contrôle du fonctionnement d'un timer
 * @{
 */

void Timer_demarrer (int timer)
{
   Timer_instances[timer].cntl.start = TIMER_DEMARRER;
}

void Timer_arreter (int timer)
{
   Timer_instances[timer].cntl.start = TIMER_ARRETER;
}

UInt16 Timer_get_valeur (int timer)
{
	return Timer_instances[timer].cnt.valeur;
}

void Timer_attendre (int timer, UInt32 duree)
{
	UInt32 postdivision;
   /* Régler le timer pour la durée souhaitée */
   Timer_set_mode (timer, TIMER_INTERVAL);
   postdivision = Timer_set_periode (timer, duree);

   /* Démarrer le timer et remettre à zéro les indicateurs d'état */
   Timer_demarrer (timer);
   Timer_acquitter_evenement (timer);

   /* Laisser le timer tourner pendant le nombre de cycles de comptage
    * déterminé plus haut */
   while(postdivision) {
      while(! Timer_evenement (timer));
      Timer_acquitter_evenement (timer);
      -- postdivision;
   }

   /* C'est fini */
   Timer_arreter (timer);
}

/** @} */

/** @} */

