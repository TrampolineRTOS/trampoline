/**
 * @addtogroup pilote_arm_timer
 * @{
 */

/**
 * @file timer_registres.h
 *
 * @brief Définition des registres des timers du microcontrôleur OKI ML675001
 *
 * $Author$
 * $Date$
 *
 * @version 2.0
 * $Revision$
 */

#ifndef H_TIMER_REGISTRES
#define H_TIMER_REGISTRES

/**
 * @name Adressage des registres des timers
 * @{
 */

/** @brief Adresse de base des registres des timers */
#define TIMER_ADRESSE_BASE 0xB7F00000

/** @} */

/**
 * @brief Structure générique des registres des timers
 *
 * Tous les registres sont sur 16 bits, alignés sur des adresses multiples de 4
 */
typedef volatile struct
{
   /** @brief La valeur du registre */
   UInt16 valeur;

   unsigned : 16;

} Timer_Registre;

/** @brief Champs des registres de contrôle des timers (CNTL) */
typedef volatile struct
{
   /** @brief Mode de comptage, intervalle ou "one-shot" */
   unsigned mode : 1;

   unsigned : 2;

   /** @brief Commande de démarrage/arrêt d'un timer */
   unsigned start : 1;

   /** @brief Activation/désactivation des demandes d'interruptions */
   unsigned ie : 1;

   /** @brief Sélection du facteur de prédivision */
   unsigned clksel : 3;

   unsigned : 24;

} Timer_RegCntl;

/** @brief Champs des registres d'état des timers (STAT) */
typedef volatile struct
{
   /** @brief Indicateur de débordement (demande d'interruption en attente) */
   unsigned status : 1;

   unsigned : 31;

} Timer_RegStat;

/** @brief Agencement des registres de chaque timer dans le plan d'adressage */
typedef volatile struct
{
   /** @brief Registre de contrôle d'un timer */
   Timer_RegCntl cntl;

   /** @brief Valeur initiale d'un timer */
   Timer_Registre base;

   /** @brief Valeur courante d'un timer */
   Timer_Registre cnt;

   /** @brief Valeur finale d'un timer */
   Timer_Registre cmp;

   /** @brief Registre d'état d'un timer */
   Timer_RegStat stat;

   /** @brief Réservé */
   UInt32 remplissage1;

   /** @brief Réservé */
   UInt32 remplissage2;

   /** @brief Réservé */
   UInt32 remplissage3;

} Timer;

#endif

/** @} */

