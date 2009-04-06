/**
 * @addtogroup pilote_arm_horloge
 * @{
 */

/**
 * @file horloge_registres.h
 *
 * @brief Définition des registres du générateur d'horloge
 *
 * $Author$
 * $Date$
 *
 * @version 1.0
 * $Revision$
 */

#ifndef H_HORLOGE_REGISTRES
#define H_HORLOGE_REGISTRES

#include "miro_types.h"

/**
 * @name Adressage des registres du générateur d'horloges
 * @{
 */

/** @brief Registre de contrôle du générateur d'horloge pour les timers et interfaces séries */
#define HORLOGE_REG_BCKCTL 0xB7000004

/** @brief Registre de configuration des diviseurs de fréquence */
#define HORLOGE_REG_CGBNT0 0xB8000008

/** @} */

/** @brief Type du registre d'activation/désactivation des horloges */
typedef UInt16 Horloge_RegBckctl;

/** @brief Structure de donnée pour l'accès au registre de configuration des diviseurs de fréquence */
typedef struct
{
   /** @brief Réglage du diviseur de fréquence CPU */
   unsigned division_cpu : 3;

   unsigned : 1;

   /** @brief Réglage du diviseur de fréquence pour les timers et interfaces séries */
   unsigned division_compteurs : 3;

   unsigned : 25;

} Horloge_RegCgbnt0;

#endif

/** @} */

