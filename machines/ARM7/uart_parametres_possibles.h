/**
 * @addtogroup pilote_arm_uart
 * @{
 */

/**
 * @file uart_parametres_possibles.h
 *
 * @brief Définition des valeurs autorisées pour les paramètres de configuration de l'UART
 *
 * $Author: LaurentMenard $
 * $Date: 2008/01/17 08:47:20 $
 *
 * @version 2.0
 * $Revision: 1.1.1.1 $
 */

#ifndef H_UART_PARAMETRES_POSSIBLES
#define H_UART_PARAMETRES_POSSIBLES

#include "miro_types.h"

/**
 * @brief Valeurs possibles pour le nombre de bits par caractère
 *
 * L'UART supporte des tailles de caractères de 5 à 8 bits.
 *
 * (registre UARTLCR, bits 1-0)
 */
typedef enum
{
   /** @brief 5 bits de données par trame */
   UART_LONGUEUR_CARACTERE_5_BITS,

   /** @brief 6 bits de données par trame */
   UART_LONGUEUR_CARACTERE_6_BITS,

   /** @brief 7 bits de données par trame */
   UART_LONGUEUR_CARACTERE_7_BITS,

   /** @brief 8 bits de données par trame */
   UART_LONGUEUR_CARACTERE_8_BITS

} UART_LongueurCaractere;

/**
 * @brief Valeurs possibles pour le nombre de bits d'arrêt 
 *
 * (registre UARTLCR, bit 2)
 */
typedef enum
{
   /** @brief 1 bits d'arrêt */
   UART_LONGUEUR_ARRET_1_BIT,

   /** @brief 2 bits d'arrêt */
   UART_LONGUEUR_ARRET_2_BITS

} UART_LongueurArret;

/**
 * @brief Valeurs possibles pour le choix du contrôle de parité 
 *
 * (registre UARTLCR, bits 5-3)
 */
typedef enum
{
   /** @brief Pas de contrôle de parité */
   UART_PARITE_AUCUNE,

   /** @brief Contrôle de parité paire */
   UART_PARITE_IMPAIRE,

   /** @brief Contrôle de parité impaire */
   UART_PARITE_PAIRE = 3,

   /** @brief Bit de parité toujours à 0 (space) */
   UART_PARITE_0 = 5,

   /** @brief Bit de parité toujours à 1 (mark) */
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
 * @brief Types d'événements produits par l'UART
 *
 * Cette énumération fournit les identifiants des causes possibles de demande d'interruption
 * de la part de l'UART.
 *
 * (UARTIER, bits 3-0)
 */
typedef enum
{
   /** @brief Demande d'interruption sur réception de données */
   UART_EVT_RECEPTION = 1,

   /** @brief Demande d'interruption dès que l'UART est prêt à émettre */
   UART_EVT_PRET_A_EMETTRE = 2,

   /** @brief Demande d'interruption sur erreur de réception */
   UART_EVT_ERREUR_RECEPTION = 4,

   /** @brief Demande d'interruption sur signal de contrôle de flux */
   UART_EVT_SYNCHRO_MODEM = 8,

   /** @brief Toutes les demandes d'interruption */
   UART_EVT_TOUS = UART_EVT_RECEPTION|UART_EVT_PRET_A_EMETTRE|UART_EVT_ERREUR_RECEPTION|UART_EVT_SYNCHRO_MODEM

} UART_Evenement;

/**
 * @brief Type de masque pour grouper la gestion de plusieurs événements
 *
 * On construit un tel masque en combinant les identifiants des événements (énumération UART_Evenement)
 * à l'aide de l'opérateur "|".
 */
typedef UInt8 UART_MasqueEvenements;

/**
 * @brief Valeurs de contrôle de l'arrêt des échanges (privé)
 *
 * (registre UARTLCR, bit 6)
 */
typedef enum
{
   /** @brief Mode de fonctionnement normal de l'UART */
   UART_LIBERER_LIGNE,

   /** @brief Forçage de la sortie série à 0 (break) */
   UART_BLOQUER_LIGNE

} UART_EtatLigne;


/**
 * @brief Valeurs de contrôle de l'accès aux registres de réglage de la vitesse de communication (privé)
 *
 * (registre UARTLCR, bit 7)
 */
typedef enum
{
   /** @brief Désactiver l'accès aux registres de réglage de la vitesse de communication */
   UART_DESACTIVER_REGLAGE_VITESSE,

   /** @brief Activer l'accès aux registres de réglage de la vitesse de communication */
   UART_ACTIVER_REGLAGE_VITESSE

} UART_AccesReglageVitesse;

/** @} */

/**
 * @brief Codes des demandes d'interruptions en attente (privé)
 *
 * (UARTIIR, bits 3-1)
 */
typedef enum
{
   /** @brief Détection d'une demande d'interruption sur erreur de contrôle de flux */
   UART_IIR_SYNCHRO_MODEM,

   /** @brief Détection d'une demande d'interruption dès que l'UART est prêt à émettre */
   UART_IIR_PRET_A_EMETTRE,

   /** @brief Détection d'une demande d'interruption sur réception de données */
   UART_IIR_RECEPTION,

   /** @brief Détection d'une demande d'interruption sur erreur de réception */
   UART_IIR_ERREUR_RECEPTION,

   /** @brief Détection d'une demande d'interruption pour cause de dépassement de délai en réception */
   UART_IIR_ERREUR_DELAI = 6

} UART_CodeInterruption;

/**
 * @brief Commandes d'activation/désactivation des FIFO d'émission et de réception (privé)
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
 * @brief Commandes de purge des FIFO (privé)
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
 * @brief Constantes utilisées pour les tests de réception (privé)
 *
 * (UARTLSR, bit 0)
 */
typedef enum
{
   /** @brief Aucune donnée reçue */
   UART_TAMPON_RECEPTION_VIDE,

   /** @brief Présence d'une donnée dans le tampon de réception */
   UART_TAMPON_RECEPTION_PLEIN

} UART_EtatReception;

/**
 * @brief Constantes utilisées pour les tests avant émission (privé)
 *
 * (UARTLSR, bit 6)
 */
typedef enum
{
   /** @brief Une transmission est en cours */
   UART_EMISSION_EN_COURS,

   /** @brief L'UART est prêt à émettre */
   UART_EMISSION_PRET

} UART_EtatEmission;

#endif

/** @} */

