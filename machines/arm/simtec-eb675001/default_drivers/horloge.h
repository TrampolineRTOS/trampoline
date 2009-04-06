/**
 * @addtogroup pilote_arm_horloge
 * Pilote du générateur d'horloge du microcontrôleur OKI ML675001
 * @{
 */

/**
 * @file horloge.h
 *
 * @brief Interface du pilote du générateur d'horloge du microcontrôleur OKI ML675001
 *
 * $Author$
 * $Date$
 *
 * @version 1.0
 * $Revision$
 */

#ifndef H_HORLOGE
#define H_HORLOGE

#include "horloge_parametres_possibles.h"
#include "horloge_configuration_par_defaut.h"

/**
 * @name Fonction d'initialisation
 * @{
 */

/**
 * @brief Initialiser le contrôleur des signaux d'horloge interne
 *
 * Le contrôleur des signaux d'horloge est initialisé avec les rélgages par défaut
 * définis dans le fichier horloge_configuration_par_defaut.h
 *
 * @post Toutes les horloges des périphériques sont désactivées
 */
void Horloge_initialiser ();

/** @} */

/**
 * @name Fonctions de configuration de la génération des signaux d'horloge
 * @{
 */

/**
 * @brief Activation de signaux d'horloges
 *
 * Cette fonction active les signaux indiqués en paramètre.
 *
 * @param sources Masque des signaux d'horloge à activer (valeurs possibles : HORLOGE_CONVERTISSEUR_ANALOGIQUE_NUMERIQUE, HORLOGE_PWM, HORLOGE_TIMER0, HORLOGE_TIMER1, HORLOGE_TIMER2, HORLOGE_TIMER3, HORLOGE_TIMER4, HORLOGE_TIMER5, HORLOGE_DRAM, HORLOGE_DMA, HORLOGE_UART, HORLOGE_SSIO, HORLOGE_I2C ; ces valeurs peuvent être combinées à l'aide de l'opérateur '|')
 *
 * @pre Le contrôleur d'horloge doit avoir été initialisé
 */
void Horloge_activer (int sources);

/**
 * @brief Désactivation de signaux d'horloges
 *
 * Cette fonction désactive les signaux indiqués en paramètre.
 *
 * @param sources Masque des signaux d'horloge à désactiver (valeurs possibles : HORLOGE_CONVERTISSEUR_ANALOGIQUE_NUMERIQUE, HORLOGE_PWM, HORLOGE_TIMER0, HORLOGE_TIMER1, HORLOGE_TIMER2, HORLOGE_TIMER3, HORLOGE_TIMER4, HORLOGE_TIMER5, HORLOGE_DRAM, HORLOGE_DMA, HORLOGE_UART, HORLOGE_SSIO, HORLOGE_I2C ; ces valeurs peuvent être combinées à l'aide de l'opérateur '|')
 *
 * @pre Le contrôleur d'horloge doit avoir été initialisé
 */
void Horloge_desactiver (int sources);

/**
 * @brief Réglage des diviseurs de fréquence
 *
 * Cette fonction configure les diviseurs de fréquence pour l'horloge CPU et pour les signaux d'horloge
 * destinés aux périphériques (timers, interfaces séries, convertisseur A/N, générateur de PWM)
 *
 * @param facteur_cpu Facteur de division de fréquence CPU (valeurs possibles : 1, 2, 4, 8, 16, 32)
 * @param facteur_compteurs Facteur de division de fréquence pour l'horloge des périphériques (valeurs possibles : 1, 2, 4, 8, 16, 32)
 *
 * @pre Le contrôleur d'horloge doit avoir été initialisé
 */
void Horloge_set_diviseurs (int facteur_cpu, int facteur_compteurs);

/** @} */

/**
 * @name Fonction de calcul de fréquence d'horloge
 * @{
 */

/**
 * @brief Calcul de la fréquence du signal d'horloge destiné aux périphériques
 *
 * @return La valeur de la fréquence, en Hz
 *
 * @pre Le contrôleur d'horloge doit avoir été initialisé
 */
int Horloge_get_frequence_compteurs ();

/** @} */

#endif

/** @} */

