/**
 * @addtogroup pilote_arm_horloge
 * @{
 */

/**
 * @file horloge_parametres_possibles.h
 *
 * @brief Définition des valeurs de paramètres autorisées pour la configuration du générateur d'horloge
 *
 * $Author$
 * $Date$
 *
 * @version 1.0
 * $Revision$
 */

#ifndef H_HORLOGE_PARAMETRES_POSSIBLES
#define H_HORLOGE_PARAMETRES_POSSIBLES

/**
 * @name Sélection des signaux d'horloge à activer/désactiver (registre BCKCTL)
 * @{
 */

/** @brief Activation/désactivation de l'horloge du convertisseur A/N */
#define HORLOGE_CONVERTISSEUR_ANALOGIQUE_NUMERIQUE 0x01

/** @brief Activation/désactivation de l'horloge du générateur de signaux PWM */
#define HORLOGE_PWM 0x02

/** @brief Activation/désactivation de l'horloge du timer 0 */
#define HORLOGE_TIMER0 0x04

/** @brief Activation/désactivation de l'horloge du timer 1 */
#define HORLOGE_TIMER1 0x08

/** @brief Activation/désactivation de l'horloge du timer 2 */
#define HORLOGE_TIMER2 0x10

/** @brief Activation/désactivation de l'horloge du timer 3 */
#define HORLOGE_TIMER3 0x20

/** @brief Activation/désactivation de l'horloge du timer 4 */
#define HORLOGE_TIMER4 0x40

/** @brief Activation/désactivation de l'horloge du timer 5 */
#define HORLOGE_TIMER5 0x80

/** @brief Activation/désactivation de l'horloge du contrôleur de DRAM */
#define HORLOGE_DRAM 0x100

/** @brief Activation/désactivation de l'horloge du contrôleur DMA */
#define HORLOGE_DMA 0x200

/** @brief Activation/désactivation de l'horloge de l'UART */
#define HORLOGE_UART 0x400

/** @brief Activation/désactivation de l'horloge de l'interface série synchrone */
#define HORLOGE_SSIO 0x800

/** @brief Activation/désactivation de l'horloge du contrôleur de bus I2C */
#define HORLOGE_I2C 0x1000

/** @brief Activation/désactivation de tous les signaux d'horloge périphériques */
#define HORLOGE_TOUTES (HORLOGE_CONVERTISSEUR_ANALOGIQUE_NUMERIQUE|HORLOGE_PWM|HORLOGE_TIMER0|HORLOGE_TIMER1|HORLOGE_TIMER2|HORLOGE_TIMER3|HORLOGE_TIMER4|HORLOGE_TIMER5|HORLOGE_DMA|HORLOGE_UART|HORLOGE_SSIO|HORLOGE_I2C)

/** @} */

/**
 * @name Réglages des diviseurs de fréquence (registre CGBNT0)
 * @{
 */

/** @brief Pas de division de fréquence */
#define HORLOGE_FACTEUR_DIVISION_1 0

/** @brief Division de fréquence par 2 */
#define HORLOGE_FACTEUR_DIVISION_2 1

/** @brief Division de fréquence par 4 */
#define HORLOGE_FACTEUR_DIVISION_4 2

/** @brief Division de fréquence par 8 */
#define HORLOGE_FACTEUR_DIVISION_8 3

/** @brief Division de fréquence par 16 */
#define HORLOGE_FACTEUR_DIVISION_16 4

/** @brief Division de fréquence par 32 */
#define HORLOGE_FACTEUR_DIVISION_32 5

/** @} */

#endif

/** @} */

