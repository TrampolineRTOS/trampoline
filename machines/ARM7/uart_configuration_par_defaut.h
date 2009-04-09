/**
 * @addtogroup pilote_arm_uart
 * @{
 */

/**
 * @file uart_configuration_par_defaut.h
 *
 * @brief Réglages par défaut des paramètres de fonctionnement de l'UART
 *
 * $Author: LaurentMenard $
 * $Date: 2008/01/17 08:47:20 $
 *
 * @version 2.0
 * $Revision: 1.1.1.1 $
 */

#ifndef H_UART_CONFIGURATION_PAR_DEFAUT
#define H_UART_CONFIGURATION_PAR_DEFAUT

#include "uart_parametres_possibles.h"

/**
 * @name Valeurs des réglages par défaut
 * @{
 */

/** @brief Taille par défaut des caractères échangés sur la liaison série */
#define UART_LONGUEUR_CARACTERE_PAR_DEFAUT UART_LONGUEUR_CARACTERE_8_BITS

/** @brief Nombre de bits d'arrêt par défaut */
#define UART_BITS_DE_STOP_PAR_DEFAUT UART_LONGUEUR_ARRET_1_BIT

/** @brief Type de contrôle de parité par défaut */
#define UART_PARITE_PAR_DEFAUT UART_PARITE_AUCUNE

/** @brief Vitesse par défaut, en bits/s */
#define UART_VITESSE_PAR_DEFAUT 9600

/** @brief Seuil par défaut de détection du remplissage de la FIFO */
#define UART_SEUIL_FIFO_PAR_DEFAUT 0

/** @brief Vitesse de communication minimale (en bits/s) */
#define UART_VITESSE_MIN 75

/** @brief Vitesse de communication maximale (en bits/s) */
#define UART_VITESSE_MAX 115200

/** @} */

#endif

/** @} */

