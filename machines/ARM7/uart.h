/**
 * @addtogroup pilote_arm_uart
 * Pilote de l'interface série asynchrone (UART) du microcontrôleur OKI ML675001
 * @{
 */

/**
 * @file uart.h
 *
 * @brief Interface du pilote de l'UART du microcontrôleur OKI ML675001.
 *
 * $Author: LaurentMenard $
 * $Date: 2008/01/17 08:47:20 $
 *
 * @version 2.0
 * $Revision: 1.1.1.1 $
 */

#ifndef H_UART
#define H_UART

#include "uart_parametres_possibles.h"

/**
 * @name Fonction d'initialisation
 * @{
 */

/**
 * @brief Initialisation de l'UART
 *
 * Cette fonction initialise l'UART avec les réglages par défaut définis dans le fichier uart_configuration_par_defaut.h 
 *
 * @pre Le module GPIO est initialisé
 * @post L'UART est prêt à fonctionner
 * @post Les tampons d'émission et de réception sont vides
 * @post Les interruptions UART sont désactivées
 */
void UART_initialiser ();

/** @} */

/**
 * @name Fonctions de configuration
 * @{
 */

/**
 * @brief Configuration du format de trame
 *
 * @param longueur_caractere Nombre de bits de données dans une trame
 * @param nombre_bits_de_stop Nombre de bits d'arrêt en fin de trame
 * @param type_parite Choix du contrôle de parité
 *
 * @pre L'UART est correctement initialisée
 *
 * @post L'UART est prêt à fonctionner avec les réglages indiqués
 */
void UART_set_format_trame (UART_LongueurCaractere longueur_caractere, UART_LongueurArret nombre_bits_de_stop, UART_TypeParite type_parite);

/**
 * @brief Configuration de la vitesse de communication
 *
 * @param vitesse La vitesse de communication, en bits par seconde
 *
 * @pre L'UART est correctement initialisée
 */
void UART_set_vitesse (UART_Vitesse vitesse);

/**
 * @brief Réglage du niveau de remplissage des FIFO pour les demandes d'interruption
 *
 * Cette fonction active le mode "buffered" de l'UART, vides les tampons de réception et d'émission,
 * et configure les FIFO pour qu'une demande d'interruption soit effectuée lorsqu'un seuil de remplissage
 * a été atteint.
 *
 * @param seuil Le niveau de remplissage pour lequel une demande d'interruption doit être effectuée
 *
 * @pre L'UART est correctement initialisée
 */
void UART_set_seuil_fifo (UART_SeuilFifo seuil);

/** @} */

/**
 * @name Fonction d'émission/réception en scrutation
 * @{
 */

/**
 * @brief Envoi d'un caractère sur la liaison série
 *
 * Cette fonction attend que l'UART soit prêt à émettre, puis envoie un caractère sur la liaison serie.
 *
 * @param caractere Le caractère à envoyer
 *
 * @pre L'UART est correctement initialisée
 */
void UART_envoyer_caractere (char caractere);

/**
 * @brief Envoi d'une chaîne de caractères sur la liaison série
 *
 * La chaîne de caractères passée en paramètre est envoyée, caractère par caractère, sur la liaison série.
 *
 * @param chaine Pointeur sur le premier caractère à envoyer
 *
 * @pre La chaîne passée en paramètre doit être une chaîne C valide (à zéro terminal)
 * @pre L'UART est correctement initialisée
 */
void UART_envoyer_chaine (const char* chaine);

/**
 * @brief Réception d'un caractère sur la liaison série
 *
 * Lecture bloquante d'un caractère reçu : si le tampon de réception est vide au moment de
 * l'appel, la fonction se met en attente.
 *
 * @return Le caractère reçu
 *
 * @pre L'UART est correctement initialisée
 */
char UART_recevoir_caractere ();

/** @} */

/**
 * @name Fonctions de gestion des événements
 * @{
 */

/**
 * @brief Activation des interruptions
 *
 * Cette fonction active les interruptions UART pour les sources indiquées.
 *
 * @param sources Les causes possibles de demandes d'interruptions autorisées (valeurs possibles : UART_EVT_RECEPTION, UART_EVT_PRET_A_EMETTRE, UART_EVT_ERREUR_RECEPTION, UART_EVT_ERREUR_MODEM, éventuellement combinées avec l'opérateur '|')
 *
 * @pre L'UART est correctement initialisée
 */
void UART_activer_interruptions (UART_MasqueEvenements sources);

/**
 * @brief Désactivation des interruptions
 *
 * Cette fonction désactive les interruptions UART pour les sources indiquées.
 *
 * @param sources Les causes possibles de demandes d'interruptions à désactiver (valeurs possibles : UART_EVT_RECEPTION, UART_EVT_PRET_A_EMETTRE, UART_EVT_ERREUR_RECEPTION, UART_EVT_ERREUR_MODEM, éventuellement combinées avec l'opérateur '|')
 *
 * @pre L'UART est correctement initialisée
 */
void UART_desactiver_interruptions (UART_MasqueEvenements sources);

/**
 * @brief Tester si un événement vient de se produire
 *
 * @param evenement Identifiant de l'événement à tester (valeurs supportées : UART_EVT_RECEPTION, UART_EVT_PRET_A_EMETTRE, UART_EVT_ERREUR_RECEPTION, UART_EVT_ERREUR_MODEM)
 * @return une valeur non nulle si l'événement testé a été détecté, 0 sinon
 */
int UART_evenement (UART_Evenement evenement);

/** @} */

#endif

/** @} */

