/**
 * @addtogroup pilote_arm_gpio
 * @{
 */

/**
 * @file gpio_registres.h
 *
 * @brief Définition des registres du contrôleur d'entrées/sorties généralistes (GPIO) du microcontrôleur OKI ML675001
 *
 * $Author: LaurentMenard $
 * $Date: 2008/01/17 08:47:20 $
 *
 * @version 2.0
 * $Revision: 1.1.1.1 $
 */

#ifndef H_GPIO_REGISTRES
#define H_GPIO_REGISTRES

#include "miro_types.h"

/**
 * @name Adresses de base des registres du module GPIO
 * @{
 */

/** @brief Adresse de base des registres des ports du module GPIO */
#define GPIO_ADRESSE_BASE 0xB7A01000

/** @brief Adresse du registre de configuration global du module GPIO */
#define GPIO_ADRESSE_GPCTL 0xB7000000

/** @} */

/**
 * @name Masque des registres d'entrée en fonction du port
 * @{
 */

/** @brief Masque de sélection des bits utiles en lecture des ports A à D */
#define GPIO_MASQUE_A_D 0x00FF

/** @brief Masque de sélection des bits utiles en lecture du port E */
#define GPIO_MASQUE_E 0x03FF

/** @} */

/**
 * @brief Structure de registre générique pour le GPIO
 *
 * Les registres sont tous sur 16 bits, alignés sur des adresses multiples de 4.
 */
typedef struct
{
   /** @brief La valeur du registre */
   UInt16 valeur;

   unsigned : 16;
} GPIO_Registre;

/**
 * @brief Structure d'un port du GPIO
 *
 * Les registres spécifiques à chaque port sont disposés dans un espace adressable contigu.
 * Tous les ports se présentent de la même façon.
 */
typedef struct
{
   /** @brief Registre de sortie du port */
   GPIO_Registre gppo;

   /** @brief Registre d'entrée du port */
   GPIO_Registre gppi;

   /** @brief Registre de configuration des entrées/sorties */
   GPIO_Registre gppm;

   /** @brief Registre d'activation/désactivation des interruptions */
   GPIO_Registre gpie;

   /** @brief Registre de configuration de la polarité des interruptions */
   GPIO_Registre gpip;

   /** @brief Registre d'état des demandes d'interruptions en attente */
   GPIO_Registre gpis;

   /** @brief Espace inutilisé */
   GPIO_Registre remplissage1;

   /** @brief Espace inutilisé */
   GPIO_Registre remplissage2;

} GPIO_Port;

#endif

/** @} */

