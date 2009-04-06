/**
 * @addtogroup pilote_arm_horloge
 * @{
 */

/**
 * @file horloge.c
 *
 * @brief Implémentation du pilote du gestionnaire d'horloge du microcontrôleur OKI ML675001
 *
 * Ce module n'utilise pas de variable globale de manière à pouvoir être exécuté intégralement
 * en ROM au démarrage.
 *
 * $Author$
 * $Date$
 *
 * @version 1.0
 * $Revision$
 */

#include "horloge.h"
#include "horloge_registres.h"
#include "horloge_parametres_possibles.h"
#include "horloge_configuration_par_defaut.h"
#include "memoire.h"

/**
 * @name Fonction d'initialisation
 * @{
 */

void Horloge_initialiser ()
{
   Horloge_set_diviseurs(HORLOGE_DIVISEUR_CPU_PAR_DEFAUT, HORLOGE_DIVISEUR_COMPTEURS_PAR_DEFAUT);

   /* Si le programme s'exécute en DRAM, ne pas désactiver l'horloge du contrôleur de DRAM */
   if(Memoire_execution_en_dram ())
      Horloge_desactiver(HORLOGE_TOUTES & ~HORLOGE_DRAM);
   else
      Horloge_desactiver(HORLOGE_TOUTES);
}

/** @} */

/**
 * @name Fonctions de configuration de la génération des signaux d'horloge
 * @{
 */

void Horloge_activer (int sources)
{
   Horloge_RegBckctl *bckctl = (Horloge_RegBckctl*)HORLOGE_REG_BCKCTL;
   *bckctl &= ~sources;
}

void Horloge_desactiver (int sources)
{
   Horloge_RegBckctl *bckctl = (Horloge_RegBckctl*)HORLOGE_REG_BCKCTL;
   *bckctl |= sources;
}

void Horloge_set_diviseurs (int facteur_cpu, int facteur_compteurs)
{
   Horloge_RegCgbnt0 *cgbnt = (Horloge_RegCgbnt0*)HORLOGE_REG_CGBNT0;
   cgbnt->division_cpu = 1 << (facteur_cpu - 1);
   cgbnt->division_compteurs = 1 << (facteur_compteurs - 1);
}

/** @} */

/**
 * @name Fonction de calcul de fréquence d'horloge
 * @{
 */

int Horloge_get_frequence_compteurs ()
{
   Horloge_RegCgbnt0 *cgbnt = (Horloge_RegCgbnt0*)HORLOGE_REG_CGBNT0;
   int decalage = 1;
   switch(cgbnt->division_compteurs)
   {
      case HORLOGE_FACTEUR_DIVISION_1: decalage = 0; break;
      case HORLOGE_FACTEUR_DIVISION_2: decalage = 1; break;
      case HORLOGE_FACTEUR_DIVISION_4: decalage = 2; break;
      case HORLOGE_FACTEUR_DIVISION_8: decalage = 3; break;
      case HORLOGE_FACTEUR_DIVISION_16: decalage = 4; break;
      case HORLOGE_FACTEUR_DIVISION_32: decalage = 5; break;
   }
   return HORLOGE_FREQUENCE_HCLK >> decalage;
}

/** @} */

/** @} */

