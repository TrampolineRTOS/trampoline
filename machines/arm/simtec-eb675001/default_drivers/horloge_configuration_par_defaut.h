/**
 * @addtogroup pilote_arm_horloge
 * @{
 */

/**
 * @file horloge_configuration_par_defaut.h
 *
 * @brief Valeurs par défaut des paramètres de configuration du générateur d'horloge
 *
 * $Author$
 * $Date$
 *
 * @version 1.0
 * $Revision$
 */

#ifndef H_HORLOGE_CONFIGURATION_PAR_DEFAUT
#define H_HORLOGE_CONFIGURATION_PAR_DEFAUT

/**
 * @name Réglages par défaut du générateur d'horloges
 * @{
 */

/** @brief Facteur de division par défaut pour la fréquence de l'horloge CPU */
#define HORLOGE_DIVISEUR_CPU_PAR_DEFAUT 1

/** @brief Facteur de division par défaut pour la fréquence d'horloge des timers et interfaces série */
#define HORLOGE_DIVISEUR_COMPTEURS_PAR_DEFAUT 1

/** @brief Fréquence d'horloge système */
#define HORLOGE_FREQUENCE_HCLK 59000000

/** @} */

#endif

/** @} */

