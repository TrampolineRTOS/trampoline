/**
 * @addtogroup pilote_arm_timer
 * @{
 */

/**
 * @file timer_parametres_possibles.h
 *
 * @brief D�finition des constantes utilisables pour param�trer les timers du microcontr�leur OKI ML675001
 *
 * $Author$
 * $Date$
 *
 * @version 2.0
 * $Revision$
 */

#ifndef H_TIMER_PARAMETRES_POSSIBLES
#define H_TIMER_PARAMETRES_POSSIBLES

/**
 * @name Modes de fonctionnement des timers
 * @{
 */

/** @brief Timer configur� en comptage d'intervalle */
#define TIMER_INTERVAL 0

/** @brief Timer configur� en mode "one-shot" */
#define TIMER_ONE_SHOT 1

/** @} */

/**
 * @name D�marrage/arr�t d'un timer
 * @{
 */

/** @brief Commande de d�marrage d'un timer */
#define TIMER_DEMARRER 1

/** @brief Commande d'arr�t d'un timer */
#define TIMER_ARRETER 0

/** @} */

/**
 * @name Gestion des �v�nements
 * @{
 */

/** @brief Commande d'activation des demandes d'interruptions */
#define TIMER_ACTIVER_INTERRUPTIONS  1

/** @brief Commande de d�sactivation des demandes d'interruptions */
#define TIMER_DESACTIVER_INTERRUPTIONS 0 

/** @brief Commande d'acquittement des demandes d'interruptions */
#define TIMER_ACQUITTER_INTERRUPTION 1

/** @brief Indicateur de d�bordement d'un timer */
#define TIMER_DEBORDEMENT 1

/** @} */

/**
 * @name R�glage des pr�diviseurs
 * @{
 */

/** @brief Pas de pr�division */ 
#define TIMER_PREDIVISEUR_1  0

/** @brief Pr�division par 2 */
#define TIMER_PREDIVISEUR_2  1

/** @brief Pr�division par 4 */
#define TIMER_PREDIVISEUR_4  2

/** @brief Pr�division par 8 */
#define TIMER_PREDIVISEUR_8  3

/** @brief Pr�division par 16 */
#define TIMER_PREDIVISEUR_16  4

/** @brief Pr�division par 32 */
#define TIMER_PREDIVISEUR_32  5

/** @} */

/**
 * @name Autres constantes
 * @{
 */

/** @brief Nombre de timers utilisables */
#define TIMER_NOMBRE 6

/** @brief nom du premier timer */
#define TIMER_0 0
/** @brief nom du deuxieme timer */
#define TIMER_1 1
/** @brief nom du troisieme timer */
#define TIMER_2 2
/** @brief nom du quatrieme timer */
#define TIMER_3 3
/** @brief nom du cinquieme timer */
#define TIMER_4 4
/** @brief nom du sixieme timer */
#define TIMER_5 5

/** @} */

#endif

/** @} */

