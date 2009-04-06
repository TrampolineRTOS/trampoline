/**
 * @addtogroup pilote_arm_timer
 * Pilote des timers du microcontrôleur OKI ML675001
 * @{
 */

/**
 * @file timer.h
 *
 * @brief Interface du pilote des timers du microcontrôleur OKI ML675001
 *
 * $Author$
 * $Date$
 *
 * @version 2.0
 * $Revision$
 */

#ifndef H_TIMER
#define H_TIMER

#include "timer_parametres_possibles.h"
#include "miro_types.h"

/**
 * @name Fonction d'initialisation
 * @{
 */

/**
 * @brief Initialisation de tous les timers
 *
 * Cette fonction initialise tous les timers avec les réglages par défaut définis dans le
 * fichier timer_configuration_par_defaut.h.
 * Toutes les timers sont arrêtés et toutes les interruptions timers sont désactivées.
 */
void Timer_initialiser ();

/** @} */

/**
 * @name Fonctions de configuration
 * @{
 */

/**
 * @brief Réglage du mode de fonctionnement d'un timer
 *
 * @param timer Le numéro du timer à configurer (entre 0 et 5)
 * @param mode Le mode de comptage (valeurs possibles : TIMER_INTERVAL, TIMER_ONE_SHOT)
 */
void Timer_set_mode (int timer, int mode);

/**
 * @brief Réglage du prédiviseur d'un timer
 *
 * @param timer Le numéro du timer à configurer (entre 0 et 5)
 * @param pre Le facteur de prédivision (valeurs possibles : TIMER_PREDIVISEUR_1 à TIMER_PREDIVISEUR_32)
 */
void Timer_set_prediviseur (int timer, int pre);

/**
 * @brief Réglage de la valeur initiale d'un timer
 *
 * Lorsque le timer atteind sa valeur finale, il se recharge automatiquement avec sa valeur initiale.
 *
 * @param timer Le numéro du timer à configurer (entre 0 et 5)
 * @param valeur La valeur initiale à affecter au timer
 */
void Timer_set_valeur_initiale (int timer, UInt16 valeur);

/**
 * @brief Réglage de la valeur finale d'un timer
 *
 * Lorsque le timer atteind sa valeur finale, il se recharge automatiquement avec sa valeur initiale.
 *
 * @param timer Le numéro du timer à configurer (entre 0 et 5)
 * @param valeur La valeur finale à affecter au timer
 */
void Timer_set_valeur_finale (int timer, UInt16 valeur);

/**
 * @brief Réglage automatique d'un timer pour une durée fixée, en microsecondes
 *
 * Cette fonction calcule automatiquement le modulo et le facteur de prédivision du timer
 * pour atteindre la durée souhaitée.
 * Si cette durée excède les possibilités du timer, elle retourne un facteur de post-division
 * à appliquer.
 *
 * @param timer Le numéro du timer à configurer (entre 0 et 5)
 * @param duree La durée entre deux rebouclages, en microsecondes
 * @return Un facteur de postdivision, si nécessaire
 */
UInt32 Timer_set_periode (int timer, UInt32 duree);

/** @} */

/**
 * @name Fonctions de gestion des événements
 * @{
 */

/**
 * @brief Activer les demandes d'interruption pour un timer
 *
 * @param timer Le numéro du timer à configurer (entre 0 et 5)
 */
void Timer_activer_interruptions (int timer);

/**
 * @brief Désactiver les demandes d'interruption pour un timer
 *
 * @param timer Le numéro du timer à configurer (entre 0 et 5)
 */
void Timer_desactiver_interruptions (int timer);

/**
 * @brief Tester l'état d'un timer
 *
 * @param timer Le numéro du timer à tester (entre 0 et 5)
 * @return 0 si le timer n'a pas encore atteint sa valeur finale, une valeur non nulle si le timer a démarré un nouveau cycle de comptage
 */
int Timer_evenement (int timer);

/**
 * @brief Acquitter un événement timer
 *
 * Cette fonction remet à zéro l'indicateur de débordement d'un timer.
 *
 * @param timer Le numéro du timer (entre 0 et 5)
 */
void Timer_acquitter_evenement (int timer);

/** @} */

/**
 * @name Fonctions de contrôle du fonctionnement d'un timer
 * @{
 */

/**
 * @brief Démarrer un timer
 *
 * @param timer Le numéro du timer à démarrer (entre 0 et 5)
 */
void Timer_demarrer (int timer);

/**
 * @brief Arrêter un timer
 *
 * @param timer Le numéro du timer à arrêter (entre 0 et 5)
 */
void Timer_arreter (int timer);

/**
 * @brief Lire la valeur courante du compteur
 *
 * @param timer Le numéro du timer à tester (entre 0 et 5)
 * @return La valeur courante du compteur
 */
UInt16 Timer_get_valeur (int timer);

/**
 * @brief Temporisation bloquante
 *
 * Cette fonction utilise le timer 1 pour mettre le programme en attente pendant
 * une durée fixée.
 *
 * @param timer Le numéro du timer à utiliser (entre 0 et 5)
 * @param duree Durée d'attente, en microsecondes
 */
void Timer_attendre (int timer, UInt32 duree);

/** @} */

#endif

/** @} */

