/**
 * @addtogroup pilote_arm_timer
 * @{
 */

/**
 * @file timer_configuration_par_defaut.h
 *
 * @brief Réglages par défaut pour la configuration des timers du microcontrôleur OKI ML675001
 *
 * $Author$
 * $Date$
 *
 * @version 2.0
 * $Revision$
 */

#ifndef H_TIMER_CONFIGURATION_PAR_DEFAUT
#define H_TIMER_CONFIGURATION_PAR_DEFAUT

#include "timer_parametres_possibles.h"

/**
 * @name Réglages par défaut
 * @{
 */

/** @brief Mode de comptage par défaut */
#define TIMER_MODE_PAR_DEFAUT TIMER_INTERVAL

/** @brief Facteur de prédivision par défaut */
#define TIMER_PREDIVISEUR_PAR_DEFAUT TIMER_PREDIVISEUR_1

/** @brief Valeur initiale par défaut */
#define TIMER_VALEUR_INITIALE_PAR_DEFAUT 0

/** @brief Valeur finale par défaut */
#define TIMER_VALEUR_FINALE_PAR_DEFAUT 1024

/** @} */

#endif

/** @} */

