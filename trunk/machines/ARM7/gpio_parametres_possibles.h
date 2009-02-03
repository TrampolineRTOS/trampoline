/**
 * @addtogroup pilote_arm_gpio
 * @{
 */

/**
 * @file gpio_parametres_possibles.h
 *
 * @brief Définitions de constantes pour le paramétrage du contrôleur d'entrées/sorties généralistes (GPIO) du microcontrôleur OKI ML675001
 *
 * $Author: LaurentMenard $
 * $Date: 2008/01/17 08:47:20 $
 *
 * @version 2.0
 * $Revision: 1.1.1.1 $
 */

#ifndef H_GPIO_PARAMETRES_POSSIBLES
#define H_GPIO_PARAMETRES_POSSIBLES

/**
 * @name Masques des fonctions spéciales des broches d'entrée/sortie
 * @{
 */

/** @brief Activation/désactivation des broches de l'UART (PIOA7-0) */
#define GPIO_FONCTION_UART 0x0001

/** @brief Activation/désactivation des broches de l'interface série (PIOB7-6) */
#define GPIO_FONCTION_SERIAL_INTERFACE 0x0002

/** @brief Activation/désactivation des broches XA du bus externe (PIOC6-2) */
#define GPIO_FONCTION_XA 0x0004

/** @brief Activation/désactivation du canal DMA 0 (PIOB4,1,0) */
#define GPIO_FONCTION_DMA_0 0x0008

/** @brief Activation/désactivation du canal DMA 1 (PIOB5,3,2) */
#define GPIO_FONCTION_DMA_1 0x0010

/** @brief Activation/désactivation des sorties PWM (PIOC1-0) */
#define GPIO_FONCTION_PWM 0x0020

/** @brief Activation/désactivation de l'entrée XWAIT du bus externe (PIOD0) */
#define GPIO_FONCTION_XWAIT 0x0040

/** @brief Activation/désactivation du signal R/W du bus externe (PIOC7) */
#define GPIO_FONCTION_XWR 0x0080

/** @brief Activation/désactivation des broches du SSIO (PIOE2-0) */
#define GPIO_FONCTION_SSIO 0x0100

/** @brief Activation/désactivation des broches de l'interface I2C (PIOE4-3) */
#define GPIO_FONCTION_I2C 0x0200

/** @brief Activation/désactivation de la broche d'interruption externe 0 (PIOE5) */
#define GPIO_FONCTION_EXINT_0 0x0400

/** @brief Activation/désactivation de la broche d'interruption externe 1 (PIOE6) */
#define GPIO_FONCTION_EXINT_1 0x0800

/** @brief Activation/désactivation de la broche d'interruption externe 2 (PIOE7) */
#define GPIO_FONCTION_EXINT_2 0x1000

/** @brief Activation/désactivation de la broche d'interruption externe 3 (PIOE8) */
#define GPIO_FONCTION_EXINT_3 0x2000

/** @brief Activation/désactivation de la broche d'interruption externe rapide (PIOE9) */
#define GPIO_FONCTION_EFIQ 0x4000

/** @} */

/**
 * @name Identifiants des ports du module GPIO
 * @{
 */

/** @brief Identifiant du port A */
#define GPIO_PORT_A 0

/** @brief Identifiant du port B */
#define GPIO_PORT_B 1

/** @brief Identifiant du port C */
#define GPIO_PORT_C 2

/** @brief Identifiant du port D */
#define GPIO_PORT_D 3

/** @brief Identifiant du port E */
#define GPIO_PORT_E 4

/** @} */

#endif

/** @} */

