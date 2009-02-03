/**
 * @addtogroup pilote_arm_gpio
 * Pilote du contrôleur d'entrées/sorties généralistes (GPIO) du microcontrôleur OKI ML675001
 * @{
 */

/**
 * @file gpio.h
 *
 * @brief Interface du pilote du contrôleur d'entrées/sorties généralistes (GPIO) du microcontrôleur OKI ML675001
 *
 * $Author: LaurentMenard $
 * $Date: 2008/01/17 08:47:20 $
 *
 * @version 2.0
 * $Revision: 1.1.1.1 $
 *
 * @todo Gestion des interruptions
 */

#ifndef H_GPIO
#define H_GPIO

#include "gpio_parametres_possibles.h"

#include "miro_types.h"

/**
 * @name Fonction d'initialisation
 * @{
 */

/**
 * @brief Initialisation des entrées/sorties généralistes
 *
 * @post une instance de la Classe Gpio est créé ainsi que tous ses registres  
 */

void GPIO_initialiser ();

/** @} */

/**
 * @name Fonctions de configuration
 * @{
 */

/**
 * @brief Activation des fonctions spéciales des broches du GPIO
 *
 * Certaines broches du GPIO sont multiplexées avec d'autres périphériques (UART, contrôleur I2C, etc).
 * Cela signifie que ces broches sont utilisables soit commes des entrées/sorties généralistes
 * (fonction "primaire" gérée par le GPIO), soit commes des broches d'un autre périphérique (fonction
 * "secondaire").
 *
 * Cette fonction permet de sélectionner les périphériques pour lesquels les broches GPIO doivent être
 * configurées pour leur fonction secondaire.
 *
 * @param fonctions Un masque désignant les fonctions spéciales à activer (voir fichier gpio_parametres_possibles.h, section "Fonctions spéciales des broches d'entrée/sortie)
 */
void GPIO_activer_fonctions (int fonctions);


/**
 * @brief Désactivation des fonctions spéciales des broches du GPIO
 *
 * Certaines broches du GPIO sont multiplexées avec d'autres périphériques (UART, contrôleur I2C, etc).
 * Cela signifie que ces broches sont utilisables soit commes des entrées/sorties généralistes
 * (fonction "primaire" gérée par le GPIO), soit commes des broches d'un autre périphérique (fonction
 * "secondaire").
 *
 * Cette fonction permet de sélectionner les périphériques pour lesquels les broches GPIO doivent être
 * configurées pour leur fonction primaire.
 *
 * @param fonctions Un masque désignant les fonctions spéciales à désactiver (voir fichier gpio_parametres_possibles.h, section "Fonctions spéciales des broches d'entrée/sortie)
 */
void GPIO_desactiver_fonctions (int fonctions);

/**
 * @brief Configuration de certaines broches d'un port en tant qu'entrées
 *
 * Pour chaque port géré par le GPIO (plus précisément pour chaque port configuré pour sa fonction primaire),
 * il est possible de régler broche par broche le sens de circulation des informations (entrée ou sortie du microcontrôleur).
 * Pour le port sélectionné, cette fonction accepte en paramètre un masque qui définit les broches devant être configurées
 * en entrées : chaque bit du masque correspond à une broche, la broche numéro 0 correspondant au bit de poids faible du masque.
 *
 * @param port Identifiant du port à configurer
 * @param masque Masque des broches à configurer (bits à 1 pour les broches à mettre en entrée)
 */
void GPIO_set_entrees (int port, UInt16 masque);

/**
 * @brief Configuration de certaines broches d'un port en tant que sorties
 *
 * Pour chaque port géré par le GPIO (plus précisément pour chaque port configuré pour sa fonction primaire),
 * il est possible de régler broche par broche le sens de circulation des informations (entrée ou sortie du microcontrôleur).
 * Pour le port sélectionné, cette fonction accepte en paramètre un masque qui définit les broches devant être configurées
 * en sorties : chaque bit du masque correspond à une broche, la broche numéro 0 correspondant au bit de poids faible du masque.
 *
 * @param port Identifiant du port à configurer
 * @param masque Masque des broches à configurer (bits à 1 pour les broches à mettre en sortie)
 */
void GPIO_set_sorties (int port, UInt16 masque);

/** @} */

/**
 * @name Fonctions de lecture/écriture sur les ports
 * @{
 */

/**
 * @brief Lire la valeur d'un port
 *
 * @param port Identifiant du port à lire
 * @return La valeur courante des broches du port
 */
UInt16 GPIO_lire (int port);

/**
 * @brief Ecrire une valeur sur un port
 *
 * @param port Identifiant du port sur lequel écrire
 * @param valeur La valeur à écrire
 */
void GPIO_ecrire (int port, UInt16 valeur);

/** @} */

#endif

/** @} */

