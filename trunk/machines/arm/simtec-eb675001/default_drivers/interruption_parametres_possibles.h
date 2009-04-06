/**
 * @addtogroup pilote_arm_interruption
 * @{
 */

/**
 * @file interruption_parametres_possibles.h
 *
 * @brief Constantes utilisables pour la configuration du contrôleur d'interruptions du microcontrôleur OKI ML675001
 *
 * $Author$
 * $Date$
 *
 * @version 2.0
 * $Revision$
 */

#ifndef H_INTERRUPTION_PARAMETRES_POSSIBLES
#define H_INTERRUPTION_PARAMETRES_POSSIBLES

/**
 * @name Identifiants des sources d'interruptions
 * @{
 */

/** @brief Nombre de sources d'interruptions utilisables */
#define INTERRUPTION_NOMBRE_SOURCES 32

/** @brief IRQ 0 : demande d'interruption du timer système */
#define INTERRUPTION_TIMER_SYSTEME 0

/** @brief IRQ 1 : demande d'interruption du timer "chien de garde" (watchdog timer) */
#define INTERRUPTION_WATCHDOG 1

/** @brief IRQ 2 : demande d'interruption du timer "chien de garde" lorsqu'il est utilisé en tant que compteur d'intervalle */
#define INTERRUPTION_INTERVALLE_WATCHDOG 2

/** @brief IRQ 4 : demande d'interruption sur détection d'événement sur le port A du module GPIO */
#define INTERRUPTION_GPIO_A 4

/** @brief IRQ 5 : demande d'interruption sur détection d'événement sur le port B du module GPIO */
#define INTERRUPTION_GPIO_B 5

/** @brief IRQ 6 : demande d'interruption sur détection d'événement sur le port C du module GPIO */
#define INTERRUPTION_GPIO_C 6

/** @brief IRQ 7 : demande d'interruption sur détection d'événement sur le port D ou E du module GPIO */
#define INTERRUPTION_GPIO_DE 7

/** @brief IRQ 8 : demande d'interruption "logicielle" */
#define INTERRUPTION_LOGICIELLE 8

/** @brief IRQ 9 : demande d'interruption UART */
#define INTERRUPTION_UART 9

/** @brief IRQ 10 : demande d'interruption de l'interface série asynchrone SIO */
#define INTERRUPTION_SIO 10

/** @brief IRQ 11 : demande d'interruption du convertisseur analogique/numérique */
#define INTERRUPTION_CONVERTISSEUR_AN 11

/** @brief IRQ 12 : demande d'interruption du générateur de signaux PWM 0 */
#define INTERRUPTION_PWM_0 12

/** @brief IRQ 13 : demande d'interruption du générateur de signaux PWM 1 */
#define INTERRUPTION_PWM_1 13

/** @brief IRQ 14 : demande d'interruption de l'interface série synchrone */
#define INTERRUPTION_SSIO 14

/** @brief IRQ 15 : demande d'interruption du contrôleur de bus I2C */
#define INTERRUPTION_I2C 15

/** @brief IRQ 16 : demande d'interruption du timer 0 */
#define INTERRUPTION_TIMER_0 16

/** @brief IRQ 17 : demande d'interruption du timer 1 */
#define INTERRUPTION_TIMER_1 17

/** @brief IRQ 18 : demande d'interruption du timer 2 */
#define INTERRUPTION_TIMER_2 18

/** @brief IRQ 19 : demande d'interruption du timer 3 */
#define INTERRUPTION_TIMER_3 19

/** @brief IRQ 20 : demande d'interruption du timer 4 */
#define INTERRUPTION_TIMER_4 20

/** @brief IRQ 21 : demande d'interruption du timer 5 */
#define INTERRUPTION_TIMER_5 21

/** @brief IRQ 22 : demande d'interruption externe 0 */
#define INTERRUPTION_EXTERNE_0 22

/** @brief IRQ 24 : demande d'interruption du canal DMA 0 */
#define INTERRUPTION_DMA_0 24

/** @brief IRQ 24 : demande d'interruption du canal DMA 1 */
#define INTERRUPTION_DMA_1 25

/** @brief IRQ 26 : demande d'interruption externe 1 */
#define INTERRUPTION_EXTERNE_1 26

/** @brief IRQ 28 : demande d'interruption externe 2 */
#define INTERRUPTION_EXTERNE_2 28

/** @brief IRQ 31 : demande d'interruption externe 3 */
#define INTERRUPTION_EXTERNE_3 31

/** @brief Valeur de l'indicateur de FIQ (registres FIQ, FIQRAW, FIQEN) */
#define INTERRUPTION_FIQ 1

/** @} */

/**
 * @name Modes de détection des interruptions externes
 * @{
 */

/** @brief Interruption sur niveau bas du signal */
#define INTERRUPTION_DETECTION_NIVEAU_BAS 0

/** @brief Interruption sur niveau haut du signal */
#define INTERRUPTION_DETECTION_NIVEAU_HAUT 1

/** @brief Interruption sur front descendant du signal */
#define INTERRUPTION_DETECTION_FRONT_DESCENDANT 2

/** @brief Interruption sur front montant du signal */
#define INTERRUPTION_DETECTION_FRONT_MONTANT 3

/** @} */

/**
 * @name Commande d'acquittement des interruptions
 * @{
 */

/** @brief Valeur d'acquittement du niveau de priorité le plus élevé des demandes en cours (registre CILCL) */
#define INTERRUPTION_ACQUITTEMENT 1

/** @} */

#endif

/** @}*/ 

