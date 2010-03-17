/**
 * @addtogroup pilotes_arm_uart
 * @{
 */

/**
 * @file uart_parametres_possibles.h
 *
 * @brief D�finition des valeurs autoris�es pour les param�tres de configuration de l'UART
 *
 * $Author: GuillaumeSavaton $
 * $Date: 2007/09/19 07:16:40 $
 *
 * @version 2.0
 * $Revision: 1.6 $
 */

#ifndef H_UART_PARAMETRES_POSSIBLES
#define H_UART_PARAMETRES_POSSIBLES

#include "miro_types.h"

/**
 * @brief Valeurs possibles pour le nombre de bits par caract�re
 *
 * L'UART supporte des tailles de caract�res de 5 � 8 bits.
 *
 * (registre UARTLCR, bits 1-0)
 */
typedef enum
{
   /** @brief 5 bits de donn�es par trame */
   UART_LONGUEUR_CARACTERE_5_BITS,

   /** @brief 6 bits de donn�es par trame */
   UART_LONGUEUR_CARACTERE_6_BITS,

   /** @brief 7 bits de donn�es par trame */
   UART_LONGUEUR_CARACTERE_7_BITS,

   /** @brief 8 bits de donn�es par trame */
   UART_LONGUEUR_CARACTERE_8_BITS

} UART_LongueurCaractere;

/**
 * @brief Valeurs possibles pour le nombre de bits d'arr�t 
 *
 * (registre UARTLCR, bit 2)
 */
typedef enum
{
   /** @brief 1 bits d'arr�t */
   UART_LONGUEUR_ARRET_1_BIT,

   /** @brief 2 bits d'arr�t */
   UART_LONGUEUR_ARRET_2_BITS

} UART_LongueurArret;

/**
 * @brief Valeurs possibles pour le choix du contr�le de parit� 
 *
 * (registre UARTLCR, bits 5-3)
 */
typedef enum
{
   /** @brief Pas de contr�le de parit� */
   UART_PARITE_AUCUNE,

   /** @brief Contr�le de parit� paire */
   UART_PARITE_IMPAIRE,

   /** @brief Contr�le de parit� impaire */
   UART_PARITE_PAIRE = 3,

   /** @brief Bit de parit� toujours � 0 (space) */
   UART_PARITE_0 = 5,

   /** @brief Bit de parit� toujours � 1 (mark) */
   UART_PARITE_1 = 7

} UART_TypeParite;

/**
 * @brief Seuil de remplissage des FIFO pour les demandes d'interruption
 *
 * (UARTFCR, bits 7-6)
 */
typedef enum
{
   /** @brief Demande d'interruption lorsque la FIFO contient au moins un octet */
   UART_SEUIL_FIFO_1_OCTET,

   /** @brief Demande d'interruption lorsque la FIFO contient au moins 4 octets */
   UART_SEUIL_FIFO_4_OCTETS,

   /** @brief Demande d'interruption lorsque la FIFO contient au moins 8 octets */
   UART_SEUIL_FIFO_8_OCTETS,

   /** @brief Demande d'interruption lorsque la FIFO contient au moins 14 octets */
   UART_SEUIL_FIFO_14_OCTETS

} UART_SeuilFifo;

/** @brief Vitesse de communication, en bits par seconde */
typedef UInt32 UART_Vitesse;

/**
 * @brief Types d'�v�nements produits par l'UART
 *
 * Cette �num�ration fournit les identifiants des causes possibles de demande d'interruption
 * de la part de l'UART.
 *
 * (UARTIER, bits 3-0)
 */
typedef enum
{
   /** @brief Demande d'interruption sur r�ception de donn�es */
   UART_EVT_RECEPTION = 1,

   /** @brief Demande d'interruption d�s que l'UART est pr�t � �mettre */
   UART_EVT_PRET_A_EMETTRE = 2,

   /** @brief Demande d'interruption sur erreur de r�ception */
   UART_EVT_ERREUR_RECEPTION = 4,

   /** @brief Demande d'interruption sur signal de contr�le de flux */
   UART_EVT_SYNCHRO_MODEM = 8,

   /** @brief Toutes les demandes d'interruption */
   UART_EVT_TOUS = UART_EVT_RECEPTION|UART_EVT_PRET_A_EMETTRE|UART_EVT_ERREUR_RECEPTION|UART_EVT_SYNCHRO_MODEM

} UART_Evenement;

/**
 * @brief Type de masque pour grouper la gestion de plusieurs �v�nements
 *
 * On construit un tel masque en combinant les identifiants des �v�nements (�num�ration UART_Evenement)
 * � l'aide de l'op�rateur "|".
 */
typedef UInt8 UART_MasqueEvenements;

/**
 * @brief Valeurs de contr�le de l'arr�t des �changes (priv�)
 *
 * (registre UARTLCR, bit 6)
 */
typedef enum
{
   /** @brief Mode de fonctionnement normal de l'UART */
   UART_LIBERER_LIGNE,

   /** @brief For�age de la sortie s�rie � 0 (break) */
   UART_BLOQUER_LIGNE

} UART_EtatLigne;


/**
 * @brief Valeurs de contr�le de l'acc�s aux registres de r�glage de la vitesse de communication (priv�)
 *
 * (registre UARTLCR, bit 7)
 */
typedef enum
{
   /** @brief D�sactiver l'acc�s aux registres de r�glage de la vitesse de communication */
   UART_DESACTIVER_REGLAGE_VITESSE,

   /** @brief Activer l'acc�s aux registres de r�glage de la vitesse de communication */
   UART_ACTIVER_REGLAGE_VITESSE

} UART_AccesReglageVitesse;

/** @} */

/**
 * @brief Codes des demandes d'interruptions en attente (priv�)
 *
 * (UARTIIR, bits 3-1)
 */
typedef enum
{
   /** @brief D�tection d'une demande d'interruption sur erreur de contr�le de flux */
   UART_IIR_SYNCHRO_MODEM,

   /** @brief D�tection d'une demande d'interruption d�s que l'UART est pr�t � �mettre */
   UART_IIR_PRET_A_EMETTRE,

   /** @brief D�tection d'une demande d'interruption sur r�ception de donn�es */
   UART_IIR_RECEPTION,

   /** @brief D�tection d'une demande d'interruption sur erreur de r�ception */
   UART_IIR_ERREUR_RECEPTION,

   /** @brief D�tection d'une demande d'interruption pour cause de d�passement de d�lai en r�ception */
   UART_IIR_ERREUR_DELAI = 6

} UART_CodeInterruption;

/**
 * @brief Commandes d'activation/d�sactivation des FIFO d'�mission et de r�ception (priv�)
 *
 * (UARTFCR, bit 0)
 */
typedef enum
{
   /** @brief Ne pas utiliser les FIFO */
   UART_DESACTIVER_FIFO,

   /** @brief Utiliser les FIFO */
   UART_ACTIVER_FIFO

} UART_UtilisationFifo;

/**
 * @brief Commandes de purge des FIFO (priv�)
 *
 * (UARTFCR, bits 2-1)
 */
typedef enum
{
   /** @brief FIFO en fonctionnement normal */
   UART_FIFO_EN_SERVICE,

   /** @brief Vider une FIFO */
   UART_VIDER_FIFO

} UART_CommandePurgeFifo;

/**
 * @brief Constantes utilis�es pour les tests de r�ception (priv�)
 *
 * (UARTLSR, bit 0)
 */
typedef enum
{
   /** @brief Aucune donn�e re�ue */
   UART_TAMPON_RECEPTION_VIDE,

   /** @brief Pr�sence d'une donn�e dans le tampon de r�ception */
   UART_TAMPON_RECEPTION_PLEIN

} UART_EtatReception;

/**
 * @brief Constantes utilis�es pour les tests avant �mission (priv�)
 *
 * (UARTLSR, bit 6)
 */
typedef enum
{
   /** @brief Une transmission est en cours */
   UART_EMISSION_EN_COURS,

   /** @brief L'UART est pr�t � �mettre */
   UART_EMISSION_PRET

} UART_EtatEmission;

#endif

/** @} */

