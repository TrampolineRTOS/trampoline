/**
 * @addtogroup pilote_arm_interruption
 * @{
 */

/**
 * @file interruption-systeme.h
 *
 * @brief Interface des sous-programmes de gestion des interruptions système
 *
 * $Author: LaurentMenard $
 * $Date: 2008/01/17 08:47:20 $
 *
 * @version 2.0
 * $Revision: 1.1.1.1 $
 */

/**
 * @name Fonctions d'initialisation 
 * @{
 */

/**
 * @brief Initialisation du vecteur d'interruptions système ARM RDI
 *
 * Cette fonction installe le vecteur d'interruptions SWI 0x123456
 * utilisé par défaut dans les debuggers ARM au standard RDI.
 *
 * Cette interruption est utilisée par les fonctions d'affichage de la bibliothèque
 * newlib.
 */
void InterruptionSysteme_initialiser ();

/** @} */

/** @} */

