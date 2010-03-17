/**
 * @addtogroup pilotes_arm_uart
 * @{
 */

/**
 * @file uart_registres.h
 *
 * @brief D�finitions de constantes et de types pour l'acc�s aux registres de l'UART
 *
 * $Author: GuillaumeSavaton $
 * $Date: 2007/09/19 07:16:40 $
 *
 * @version 2.0
 * $Revision: 1.6 $
 */

#ifndef H_UART_REGISTRES
#define H_UART_REGISTRES

#include "miro_types.h"

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
	/** Bits 0 � 1 : nombre de bits de donn�es dans une trame */
	unsigned longueur_caractere : 2;

	/** Bit 2 : nombre de bits de stop */
	unsigned nombre_bits_de_stop : 1;

	/** Bits 3 � 5 : type de contr�le de parit� */
	unsigned type_parite : 3;

	/** Bit 6 : fonctionnement normal/arr�t des �changes */
	unsigned forcer_arret : 1;

	/** Bit 7 : acc�s � la configuration du diviseur de fr�quence */
	unsigned acces_diviseur : 1;

   unsigned : 24;

} UART_RegLcr;

/** @brief Champs du registre de configuration des FIFO de l'UART (FCR) */
typedef struct
{	
	/** Bit 0 : activation/d�sactivation des FIFO */
	unsigned utiliser_fifo : 1;

	/** Bit 1 : vider la FIFO de r�ception */
	unsigned vider_fifo_reception : 1;

	/** Bit 2 : vider la FIFO d'�mission */
	unsigned vider_fifo_emission : 1;

	/** Bit 3 : s�lectionner le mode d'utilisation du DMA (non support�) */
	unsigned selectionner_mode_dma : 1;

	/** Bit 4 � 5 : r�serv�s */	
	unsigned : 2;

	/** Bit 6 � 7 : seuil de remplissage d'une FIFO pour le d�clenchement d'une demande d'interruption */
	unsigned seuil : 2;

   unsigned : 24;

} UART_RegFcr;

/** @brief Champs du registre d'�tat de la communication s�rie (LSR) */
typedef struct
{
	/** Bit 0 : indicateur de r�ception d'une nouvelle donn�e */
	unsigned donnee_recue : 1;

	/** Bit 1 : indicateur d'�crasement de donn�e (overrun) */
	unsigned overrun : 1;

	/** Bit 2 : indicateur d'erreur de parit� */
	unsigned erreur_parite : 1;

	/** Bit 3 : indicateur d'erreur de format de trame */
	unsigned erreur_format : 1;

	/** Bit 4 : indicateur de demande d'arr�t des communications */
	unsigned demande_arret : 1;

	/** Bit 5 : indicateur de tampon d'�mission vide */
	unsigned tampon_vide : 1;

	/** Bit 6 : indicateur d'�matteur pr�t � �mettre */
	unsigned emetteur_pret : 1;

	/** Bit 7 : indicateur d'erreur g�n�ral dans le cas d'une op�ration avec FIFO */
	unsigned erreur: 1;

   unsigned : 24;

} UART_RegLsr;

/** @brief Champs du registre d'�tat des demandes d'interruptions (IIR) */
typedef struct
{
   /** @brief Indicateur g�n�ral de demande d'interruption */
   unsigned irq : 1;

   /** @brief Le code de l'�v�nement d�tect� */
   unsigned code : 3;

   unsigned : 28;

} UART_RegIir;

/**
 * @brief Type g�n�rique pour les registres de l'UART
 *
 * Les registres sont tous sur 8 bits, align�s sur des adresses multiples de 4.
 */
typedef struct
{
   /** @brief La valeur du registre */
   UInt8 valeur;

   unsigned : 24;
} UART_Reg8;

/** @brief Champs du registre d'�tat du modem */
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
 * @brief Structure de donn�es pour l'ensemble des registres de l'UART
 */
typedef struct
{
   /** @brief Tampon d'�mission/r�ception ou configuration de l'octet de poids faible du diviseur de fr�quence */
   UART_Reg8 rbr_thr_dll;

   /** @brief Activation/d�sactivation des interruptions, ou configuration de l'octet de poids fort du diviseur de fr�quence */
   UART_Reg8 ier_dlm;

   /** @brief Indicateurs d'interruptions en attente, ou configuration des FIFO */
   union
   {
      UART_RegIir iir;
      UART_RegFcr fcr;
   } iir_fcr;

   /** @brief Configuration des trames s�rie */
   UART_RegLcr lcr;

   /** @brief Configuration du contr�le de flux */
   UART_Reg8 mcr;

   /** @brief Registre d'�tat de la communication s�rie */
   UART_RegLsr lsr;

   /** @brief Registre d'�tat du contr�le de flux */
   UART_RegMsr msr;
   
   /** @brief Registre � usage g�n�ral */
   UART_Reg8 scr;

} UART;

#endif

/** @} */

