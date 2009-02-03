/**
 * @addtogroup pilote_arm_uart
 * @{
 */

/**
 * @file uart_registres.h
 *
 * @brief Définitions de constantes et de types pour l'accès aux registres de l'UART
 *
 * $Author: LaurentMenard $
 * $Date: 2008/01/17 08:47:20 $
 *
 * @version 2.0
 * $Revision: 1.1.1.1 $
 */

#ifndef H_UART_REGISTRES
#define H_UART_REGISTRES

#include <miro_types.h>

/**
 * @name Adressage des registres de l'UART
 * @{
 */

/** @brief Adresse de base des registres de l'UART */
#define UART_ADRESSE_BASE 0xB7B00000

/** @} */

/** @brief Champs du registre de configuration du format de trame (LCR) */
typedef struct
{	
	/** Bits 0 à 1 : nombre de bits de données dans une trame */
	unsigned longueur_caractere : 2;

	/** Bit 2 : nombre de bits de stop */
	unsigned nombre_bits_de_stop : 1;

	/** Bits 3 à 5 : type de contrôle de parité */
	unsigned type_parite : 3;

	/** Bit 6 : fonctionnement normal/arrêt des échanges */
	unsigned forcer_arret : 1;

	/** Bit 7 : accès à la configuration du diviseur de fréquence */
	unsigned acces_diviseur : 1;

   unsigned : 24;

} UART_RegLcr;

/** @brief Champs du registre de configuration des FIFO de l'UART (FCR) */
typedef struct
{	
	/** Bit 0 : activation/désactivation des FIFO */
	unsigned utiliser_fifo : 1;

	/** Bit 1 : vider la FIFO de réception */
	unsigned vider_fifo_reception : 1;

	/** Bit 2 : vider la FIFO d'émission */
	unsigned vider_fifo_emission : 1;

	/** Bit 3 : sélectionner le mode d'utilisation du DMA (non supporté) */
	unsigned selectionner_mode_dma : 1;

	/** Bit 4 à 5 : réservés */	
	unsigned : 2;

	/** Bit 6 à 7 : seuil de remplissage d'une FIFO pour le déclenchement d'une demande d'interruption */
	unsigned seuil : 2;

   unsigned : 24;

} UART_RegFcr;

/** @brief Champs du registre d'état de la communication série (LSR) */
typedef struct
{
	/** Bit 0 : indicateur de réception d'une nouvelle donnée */
	unsigned donnee_recue : 1;

	/** Bit 1 : indicateur d'écrasement de donnée (overrun) */
	unsigned overrun : 1;

	/** Bit 2 : indicateur d'erreur de parité */
	unsigned erreur_parite : 1;

	/** Bit 3 : indicateur d'erreur de format de trame */
	unsigned erreur_format : 1;

	/** Bit 4 : indicateur de demande d'arrêt des communications */
	unsigned demande_arret : 1;

	/** Bit 5 : indicateur de tampon d'émission vide */
	unsigned tampon_vide : 1;

	/** Bit 6 : indicateur d'ématteur prêt à émettre */
	unsigned emetteur_pret : 1;

	/** Bit 7 : indicateur d'erreur général dans le cas d'une opération avec FIFO */
	unsigned erreur: 1;

   unsigned : 24;

} UART_RegLsr;

/** @brief Champs du registre d'état des demandes d'interruptions (IIR) */
typedef struct
{
   /** @brief Indicateur général de demande d'interruption */
   unsigned irq : 1;

   /** @brief Le code de l'événement détecté */
   unsigned code : 3;

   unsigned : 28;

} UART_RegIir;

/**
 * @brief Type générique pour les registres de l'UART
 *
 * Les registres sont tous sur 8 bits, alignés sur des adresses multiples de 4.
 */
typedef struct
{
   /** @brief La valeur du registre */
   UInt8 valeur;

   unsigned : 24;
} UART_Reg8;

/** @brief Champs du registre d'état du modem */
typedef struct
{
   unsigned evt_cts : 1;
   unsigned evt_dsr : 1;
   unsigned evt_ri : 1;
   unsigned evt_dcd : 1;
   unsigned cts : 1;
   unsigned dsr : 1;
   unsigned ri : 1;
   unsigned dcd : 1;
   unsigned : 24;
} UART_RegMsr;

/**
 * @brief Structure de données pour l'ensemble des registres de l'UART
 */
typedef struct
{
   /** @brief Tampon d'émission/réception ou configuration de l'octet de poids faible du diviseur de fréquence */
   UART_Reg8 rbr_thr_dll;

   /** @brief Activation/désactivation des interruptions, ou configuration de l'octet de poids fort du diviseur de fréquence */
   UART_Reg8 ier_dlm;

   /** @brief Indicateurs d'interruptions en attente, ou configuration des FIFO */
   union
   {
      UART_RegIir iir;
      UART_RegFcr fcr;
   } iir_fcr;

   /** @brief Configuration des trames série */
   UART_RegLcr lcr;

   /** @brief Configuration du contrôle de flux */
   UART_Reg8 mcr;

   /** @brief Registre d'état de la communication série */
   UART_RegLsr lsr;

   /** @brief Registre d'état du contrôle de flux */
   UART_RegMsr msr;
   
   /** @brief Registre à usage général */
   UART_Reg8 scr;

} UART;

#endif

/** @} */

