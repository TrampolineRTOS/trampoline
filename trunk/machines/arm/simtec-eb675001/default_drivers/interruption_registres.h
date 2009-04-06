/**
 * @addtogroup pilote_arm_interruption
 * @{
 */

/**
 * @file interruption_registres.h
 *
 * @brief Définition des registres du contrôleur d'interruptions du microcontrôleur OKI ML675001
 *
 * $Author$
 * $Date$
 *
 * @version 2.0
 * $Revision$
 */

#ifndef H_INTERRUPTION_REGISTRES
#define H_INTERRUPTION_REGISTRES

/**
 * @name Adressage des registres du contrôleur d'interruptions
 * @{
 */

/** @brief Adresse de base des registres du contrôleur d'interruptions, banque 1 */
#define INTERRUPTION_ADRESSE_BASE_1 0x78000000

/** @brief Adresse de base des registres du contrôleur d'interruptions, banque 2 */
#define INTERRUPTION_ADRESSE_BASE_2 0x7BF00000

/** @} */

/** @brief Champs du registre ILC0 pour la configuration des niveaux de priorité des sources d'interruptions 0 à 7 */
typedef struct
{
   /** @brief Niveau de priorité de la source d'interruptions IRQ 0 (timer système) */
   unsigned ilr0 : 3;

   unsigned : 1;

   /** @brief Niveau de priorité des sources d'interruptions IRQ 1 et 2 (watchdog) */
   unsigned ilr1 : 3;

   unsigned : 9;

   /** @brief Niveau de priorité des sources d'interruptions IRQ 4 et 5 (ports A et B du module GPIO) */
   unsigned ilr4 : 3;

   unsigned : 5;

   /** @brief Niveau de priorité des sources d'interruptions IRQ 6 et 7 (ports C, D et E du module GPIO) */
   unsigned ilr6 : 3;

   unsigned : 5;
} Interruption_RegIlc0;

/** @brief Champs du registre ILC1 pour la configuration des niveaux de priorité des sources d'interruptions 8 à 15 */
typedef struct
{
   /** @brief Niveau de priorité de la source d'interruptions IRQ 8 (interruption logicielle) */
   unsigned ilr8 : 3;

   unsigned : 1;

   /** @brief Niveau de priorité de la source d'interruptions IRQ 9 (interruption UART) */
   unsigned ilr9 : 3;

   unsigned : 1;

   /** @brief Niveau de priorité de la source d'interruptions IRQ 10 (interruption SIO) */
   unsigned ilr10 : 3;

   unsigned : 1;

   /** @brief Niveau de priorité de la source d'interruptions IRQ 11 (interruption convertisseur A/N) */
   unsigned ilr11 : 3;

   unsigned : 1;

   /** @brief Niveau de priorité de la source d'interruptions IRQ 12 (interruption PWM 0) */
   unsigned ilr12 : 3;

   unsigned : 1;

   /** @brief Niveau de priorité de la source d'interruptions IRQ 13 (interruption PWM 1) */
   unsigned ilr13 : 3;

   unsigned : 1;

   /** @brief Niveau de priorité de la source d'interruptions IRQ 14 (interruption SSIO) */
   unsigned ilr14 : 3;

   unsigned : 1;

   /** @brief Niveau de priorité de la source d'interruptions IRQ 15 (interruption I2C) */
   unsigned ilr15 : 3;

   unsigned : 1;

} Interruption_RegIlc1;

/** @brief Champs du registre ILC pour la configuration des niveaux de priorité des sources d'interruptions 16 à 31 */
typedef struct
{
   /** @brief Niveau de priorité des sources d'interruptions IRQ 16 et 17 (timers 0 et 1) */
   unsigned ilr16 : 3;

   unsigned : 1;

   /** @brief Niveau de priorité des sources d'interruptions IRQ 18 et 19 (timers 3 et 4) */
   unsigned ilr18 : 3;

   unsigned : 1;

   /** @brief Niveau de priorité des sources d'interruptions IRQ 20 et 21 (timers 4 et 5) */
   unsigned ilr20 : 3;

   unsigned : 1;

   /** @brief Niveau de priorité de la source d'interruption IRQ 22 (interruption externe 0) */
   unsigned ilr22 : 3;

   unsigned : 1;

   /** @brief Niveau de priorité des sources d'interruptions IRQ 24 et 25 (DMA) */
   unsigned ilr24 : 3;

   unsigned : 1;

   /** @brief Niveau de priorité de la source d'interruption IRQ 26 (interruption externe 1) */
   unsigned ilr26 : 3;

   unsigned : 1;

   /** @brief Niveau de priorité de la source d'interruption IRQ 28 (interruption externe 2) */
   unsigned ilr28 : 3;

   unsigned : 1;

   /** @brief Niveau de priorité de la source d'interruption IRQ 31 (interruption externe 3) */
   unsigned ilr30 : 3;

   unsigned : 1;

} Interruption_RegIlc;

/** @brief Champs du registre IDM pour la configuration du mode de détection des interruptions externes */
typedef struct
{
   unsigned : 6;

   /** @brief Mode de détection des interruptions externes sur l'entrée 0 */
   unsigned idm22 : 2;

   unsigned : 2;

   /** @brief Mode de détection des interruptions externes sur l'entrée 1 */
   unsigned idm26 : 2;
   
   /** @brief Mode de détection des interruptions externes sur l'entrée 2 */
   unsigned idm28 : 2;

   /** @brief Mode de détection des interruptions externes sur l'entrée 3 */
   unsigned idm31 : 2;

} Interruption_RegIdm;

/** @brief Champs du registre IRN pour l'identification de la source d'une demande d'interruption */
typedef struct
{
   /** @brief Numéro de la source d'interruption */
   unsigned source : 7;

   unsigned : 25;

} Interruption_RegIrn;

/** @brief Agencement des registres du contrôleur d'interruptions dans le plan d'adressage (banque 1) */
typedef struct
{
   /** @brief Registre d'état des demandes d'interruption, sources IRQ 0 à 15 */
   UInt32 irq;

   /** @brief Registre d'état des interruptions logicielles (inutilisé dans ce pilote) */
   UInt32 irqs;

   /** @brief Registre d'état des demandes d'interruptions rapides (FIQ) */
   UInt32 fiq;

   /** @brief Accès direct à la valeur de l'entrée EFIQ */
   UInt32 fiqraw;

   /** @brief Activation/désactivation des interruptions rapides (FIQ) */
   UInt32 fiqen;

   /** @brief Numéro de la source de la demande d'interruption IRQ de plus haute priorité en attente */
   Interruption_RegIrn irn;

   /** @brief Niveau de priorité de la demande d'interruption en cours (sous forme de masque) */
   UInt32 cil;

   /** @brief Réservé */
   UInt32 remplissage;

   /** @brief Registre de contrôle des niveaux de priorité des sources d'interruptions IRQ 0 à 7 */
   Interruption_RegIlc0 ilc0;

   /** @brief Registre de contrôle des niveaux de priorité des sources d'interruptions */
   Interruption_RegIlc1 ilc1;

   /** @brief Registre d'acquittement des interruptions pour un niveau de priorité donné */
   UInt32 cilcl;

   /** @brief Niveau de priorité de la demande d'interruption en cours, sous forme entière */
   UInt32 cile;

} Interruption1;

/** @brief Agencement des registres du contrôleur d'interruptions dans le plan d'adressage (banque 2) */
typedef struct
{
   /** @brief Réservé */
   UInt32 remplissage1;

   /** @brief Acquittement des demandes d'interruption externes */
   UInt32 ircl;

   /** @brief Réservé */
   UInt32 remplissage2;

   /** @brief Réservé */
   UInt32 remplissage3;

   /** @brief Registre d'état des demandes d'interruption, sources IRQ 16 à 31 */
   UInt32 irqa;

   /** @brief Mode de détection des demandes d'interruptions externes */
   Interruption_RegIdm idm;

   /** @brief Contrôle du niveau de priorité des IRQ */
   Interruption_RegIlc ilc;

} Interruption2;

#endif

/** @}*/ 

