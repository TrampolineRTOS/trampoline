/**
 * @addtogroup pilotes_arm_uart
 * Pilote de l'interface s�rie asynchrone (UART) du microcontr�leur OKI ML675001
 * @{
 */

/**
 * @file uart.h
 *
 * @brief Interface du pilote de l'UART du microcontr�leur OKI ML675001.
 *
 * $Author: GuillaumeSavaton $
 * $Date: 2007/09/19 07:16:40 $
 *
 * @version 2.0
 * $Revision: 1.6 $
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
 * Cette fonction initialise l'UART avec les r�glages par d�faut d�finis dans le fichier uart_configuration_par_defaut.h 
 *
 * @pre Le module GPIO est initialis�
 * @post L'UART est pr�t � fonctionner
 * @post Les tampons d'�mission et de r�ception sont vides
 * @post Les interruptions UART sont d�sactiv�es
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
 * @param longueur_caractere Nombre de bits de donn�es dans une trame
 * @param nombre_bits_de_stop Nombre de bits d'arr�t en fin de trame
 * @param type_parite Choix du contr�le de parit�
 *
 * @pre L'UART est correctement initialis�e
 *
 * @post L'UART est pr�t � fonctionner avec les r�glages indiqu�s
 */
void UART_set_format_trame (UART_LongueurCaractere longueur_caractere, UART_LongueurArret nombre_bits_de_stop, UART_TypeParite type_parite);

/**
 * @brief Configuration de la vitesse de communication
 *
 * @param vitesse La vitesse de communication, en bits par seconde
 *
 * @pre L'UART est correctement initialis�e
 */
void UART_set_vitesse (UART_Vitesse vitesse);

/**
 * @brief R�glage du niveau de remplissage des FIFO pour les demandes d'interruption
 *
 * Cette fonction active le mode "buffered" de l'UART, vides les tampons de r�ception et d'�mission,
 * et configure les FIFO pour qu'une demande d'interruption soit effectu�e lorsqu'un seuil de remplissage
 * a �t� atteint.
 *
 * @param seuil Le niveau de remplissage pour lequel une demande d'interruption doit �tre effectu�e
 *
 * @pre L'UART est correctement initialis�e
 */
void UART_set_seuil_fifo (UART_SeuilFifo seuil);

/** @} */

/**
 * @name Fonction d'�mission/r�ception en scrutation
 * @{
 */

/**
 * @brief Envoi d'un caract�re sur la liaison s�rie
 *
 * Cette fonction attend que l'UART soit pr�t � �mettre, puis envoie un caract�re sur la liaison serie.
 *
 * @param caractere Le caract�re � envoyer
 *
 * @pre L'UART est correctement initialis�e
 */
void UART_envoyer_caractere (char caractere);

/**
 * @brief Envoi d'une cha�ne de caract�res sur la liaison s�rie
 *
 * La cha�ne de caract�res pass�e en param�tre est envoy�e, caract�re par caract�re, sur la liaison s�rie.
 *
 * @param chaine Pointeur sur le premier caract�re � envoyer
 *
 * @pre La cha�ne pass�e en param�tre doit �tre une cha�ne C valide (� z�ro terminal)
 * @pre L'UART est correctement initialis�e
 */
void UART_envoyer_chaine (char* chaine);

/**
 * @brief R�ception d'un caract�re sur la liaison s�rie
 *
 * Lecture bloquante d'un caract�re re�u : si le tampon de r�ception est vide au moment de
 * l'appel, la fonction se met en attente.
 *
 * @return Le caract�re re�u
 *
 * @pre L'UART est correctement initialis�e
 */
char UART_recevoir_caractere ();

/** @} */

/**
 * @name Fonctions de gestion des �v�nements
 * @{
 */

/**
 * @brief Activation des interruptions
 *
 * Cette fonction active les interruptions UART pour les sources indiqu�es.
 *
 * @param sources Les causes possibles de demandes d'interruptions autoris�es (valeurs possibles : UART_EVT_RECEPTION, UART_EVT_PRET_A_EMETTRE, UART_EVT_ERREUR_RECEPTION, UART_EVT_ERREUR_MODEM, �ventuellement combin�es avec l'op�rateur '|')
 *
 * @pre L'UART est correctement initialis�e
 */
void UART_activer_interruptions (UART_MasqueEvenements sources);

/**
 * @brief D�sactivation des interruptions
 *
 * Cette fonction d�sactive les interruptions UART pour les sources indiqu�es.
 *
 * @param sources Les causes possibles de demandes d'interruptions � d�sactiver (valeurs possibles : UART_EVT_RECEPTION, UART_EVT_PRET_A_EMETTRE, UART_EVT_ERREUR_RECEPTION, UART_EVT_ERREUR_MODEM, �ventuellement combin�es avec l'op�rateur '|')
 *
 * @pre L'UART est correctement initialis�e
 */
void UART_desactiver_interruptions (UART_MasqueEvenements sources);

/**
 * @brief Tester si un �v�nement vient de se produire
 *
 * @param evenement Identifiant de l'�v�nement � tester (valeurs support�es : UART_EVT_RECEPTION, UART_EVT_PRET_A_EMETTRE, UART_EVT_ERREUR_RECEPTION, UART_EVT_ERREUR_MODEM)
 * @return une valeur non nulle si l'�v�nement test� a �t� d�tect�, 0 sinon
 */
int UART_evenement (UART_Evenement evenement);

/** @} */

#endif

/** @} */

