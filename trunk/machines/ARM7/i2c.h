/**
 * @addtogroup pilote_arm_i2c
 * Pilote du contrôleur de bus I2C du microcontrôleur OKI ML675001
 * @{
 */

/**
 * @file i2c.h
 *
 * @brief Interface du pilote de contrôleur I2C pour le microcontrôleur OKI ML675001
 *
 * $Author: LaurentMenard $
 * $Date: 2008/01/17 08:47:20 $
 *
 * @version 1.0
 * $Revision: 1.1.1.1 $
 */

#include "miro_types.h"

#ifndef H_I2C
#define H_I2C

/**
 * @brief Codes d'erreur de communication
 *
 * Ces codes sont retournés par la fonction I2C_get_code_erreur()
 */
typedef enum
{
   /** @brief Un acquittement a été reçu pour l'adresse et pour la donnée échangée sur le bus */
   I2C_OK,

   /** @brief Aucun esclave I2C n'a acquitté l'adresse utilisée pour le dernier transfert */
   I2C_ERREUR_ADRESSE,

   /** @brief L'esclave I2C à qui une donnée était destinée n'a pas acquitté la trame de donnée */
   I2C_ERREUR_DONNEE
} I2C_CodeErreur;

/**
 * @name Fonction d'initialisation
 * @{
 */

/**
 * @brief Initialisation du contrôleur de bus I2C
 *
 * Cette fonction initialise le contrôleur de bus I2C avec les réglages définis dans le fichier
 * i2c_configuration_par_defaut.h
 */
void I2C_initialiser ();

/** @} */

/**
 * @name Fonctions de configuration
 * @{
 */ 

/**
 * @brief Configuration de la vitesse de transmission
 *
 * Cette fonction permet de reconfigurer la fréquence de l'horloge I2C.
 * Deux valeurs de vitesse sont proposées : 100 kHz (mode standard) et 400 kHz (mode rapide).
 *
 * @param vitesse Choix de la vitesse (valeurs possibles : I2C_MODE_STANDARD, I2C_MODE_RAPIDE)
 */
void I2C_set_vitesse (int vitesse);
 
/** @} */

/**
 * @name Fonctions d'échanges de données
 * @{
 */

/**
 * @brief Ecriture d'une donnée sur le bus I2C
 *
 * Cette fonction envoie un octet à un périphérique I2C.
 * Lorsque cette fonction se termine, la trame d'écriture n'est pas arrêtée.
 * Des appels successifs à cette fonction vers la même adresse se feront donc
 * dans la même trame I2C.
 *
 * @param adresse L'adresse du périphérique sur le bus I2C
 * @param donnee La donnée à écrire
 */
void I2C_ecrire (UInt8 adresse, UInt8 donnee);

/**
 * @brief Ecriture d'une donnée sur le bus I2C et fin de trame
 *
 * Cette fonction envoie un octet à un périphérique I2C et termine la trame en cours.
 *
 * @param adresse L'adresse du périphérique sur le bus I2C
 * @param donnee La donnée à écrire
 */
void I2C_ecrire_et_stopper (UInt8 adresse, UInt8 donnee);

/**
 * @brief lecture d'une donnée provenant du bus I2C
 *
 * Cette fonction effectue la lecture d'un octet sur un périphérique I2C.
 * Lorsque cette fonction se termine, la trame de lecture n'est pas arrêtée.
 * Des appels successifs à cette fonction vers la même adresse se feront donc
 * dans la même trame I2C.
 *
 * @param adresse L'adresse du périphérique sur le bus I2C
 * @return La donnée lue
 */
UInt8 I2C_lire (UInt8 adresse);

/**
 * @brief lecture d'une donnée provenant du bus I2C et fin de trame
 *
 * Cette fonction effectue la lecture d'un octet sur un périphérique I2C et termine la trame en cours.
 *
 * @param adresse L'adresse du périphérique sur le bus I2C
 * @return La donnée lue
 */
UInt8 I2C_lire_et_stopper(UInt8 adresse);

/**
 * @brief Attendre l'acquittement d'un esclave I2C
 *
 * Cette fonction attend la fin du transfert en cours.
 * Dès que la condition d'acquittement a été reçue de la part de l'esclave, cette fonction
 * acquitte automatiquement les demandes d'interruptions en cours.
 *
 * Les éventuelles erreurs peuvent être obtenues à l'aide de la fonction I2C_get_code_erreur().
 */
void I2C_attendre_acquittement ();

/** @} */

/**
 * @name Fonctions de gestion des événements
 * @{
 */

/**
 * @brief Activer les demandes d'interruption I2C.
 */
void I2C_activer_interruptions ();

/**
 * @brief Désactiver les demandes d'interruption I2C.
 */
void I2C_desactiver_interruptions ();

/** @} */

/**
 * @name Fonctions de gestion des erreurs
 * @{
 */

I2C_CodeErreur I2C_get_code_erreur ();

/** @} */

#endif

/** @} */

