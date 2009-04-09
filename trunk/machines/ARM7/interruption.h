/**
 * @addtogroup pilote_arm_interruption
 * Pilote du contrôleur d'interruptions du microcontrôleur OKI ML675001
 * @{
 */

/**
 * @file interruption.h
 *
 * @brief Interface du pilote du contrôleur d'interruptions du microcontrôleur OKI ML675001
 *
 * $Author: LaurentMenard $
 * $Date: 2008/01/17 08:47:20 $
 *
 * @version 2.0
 * $Revision: 1.1.1.1 $
 */

#ifndef H_INTERRUPTION
#define H_INTERRUPTION

#include "interruption_parametres_possibles.h"

#include "miro_types.h"

/** @brief Type de fonction acceptable comme gestionnaire d'interruption */
typedef void (*Interruption_Gestionnaire)(void *arguments);

/** @brief Type de fonction acceptable comme gestionnaire d'appel système (SWI) */
typedef UInt32 (*Interruption_GestionnaireAppelSysteme)(UInt32 *arguments);

/**
 * @name Fonction d'initialisation 
 * @{
 */ 

/**
 * @brief Initialisation de la gestion des interruptions
 *
 * @post Les interruptions sont masquées
 */
void Interruption_initialiser (); 
 
/** @}*/ 
 
/**
 * @name Fonctions de configuration
 * @{
 */

/**
 * @brief Affectation d'un niveau de priorité à une source d'interruption donnée
 *
 * Les identifiants des sources d'interruptions sont détaillés dans le fichier interruption_parametres_possibles.h.
 * Un niveau de priorité doit être compris entre 0 (source d'interruption désactivée) et 7 (priorité la plus élevée).
 *
 * @param source Numéro de la source d'interruption
 * @param niveau Niveau de priorité
 */
void Interruption_set_priorite (int source, int niveau);

/**
 * @brief Lecture du niveau de priorité d'une source d'interruption
 *
 * Les identifiants des sources d'interruptions sont détaillés dans le fichier interruption_parametres_possibles.h.
 *
 * @param source Numéro de la source d'interruption
 * @param niveau Niveau de priorité
 */
int Interruption_get_priorite (int source);

/**
 * @brief Installation d'une fonction de traitement d'interruption pour une source donnée
 *
 * @param source Numéro de la source d'interruption
 * @param gestionnaire Pointeur vers la fonction de traitement
 */
void Interruption_set_gestionnaire_irq (int source, Interruption_Gestionnaire gestionnaire, void *arguments);

/**
 * @brief Installation d'une fonction de traitement d'interruption rapide
 *
 * @param gestionnaire Pointeur vers la fonction de traitement
 */
void Interruption_set_gestionnaire_fiq (Interruption_Gestionnaire gestionnaire, void *arguments);

/**
 * @brief Installation d'une fonction de traitement des interruptions logicielles
 *
 * @param gestionnaire Pointeur vers la fonction de traitement
 */
void Interruption_set_gestionnaire_swi (UInt32 numero_service, Interruption_GestionnaireAppelSysteme gestionnaire);

/**
 * @brief Réglage du mode de détection d'une demande d'interruption externe
 *
 * @param source Numéro de la source d'interruption (doit correspondre à une interruption externe)
 * @param mode Niveau ou front actif de l'entrée interruption
 */
void Interruption_set_detection (int source, int mode);

/** @} */

/**
 * @name Fonctions de gestion des événements
 * @{
 */

/**
 * @brief Activer la détection des IRQ par le processeur
 */
void Interruption_activer_irq ();

/**
 * @brief Désactiver la détection des IRQ par le processeur
 */
void Interruption_desactiver_irq ();

/**
 * @brief Activer la détection des FIQ par le processeur
 */
void Interruption_activer_fiq ();

/**
 * @brief Désactiver la détection des FIQ par le processeur
 */
void Interruption_desactiver_fiq ();

/** @} */

#endif

/** @}*/ 

