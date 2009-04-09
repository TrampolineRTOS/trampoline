/**
 * @addtogroup pilote_arm_uart
 * @{
 */

/**
 * @file uart.c
 *
 * @brief Implémentation du pilote de l'UART du microcontrôleur OKI ML675001
 *
 * $Author: LaurentMenard $
 * $Date: 2008/01/17 08:47:20 $
 *
 * @version 2.0
 * $Revision: 1.1.1.1 $
 */

#include "uart.h"
#include "uart_registres.h"
#include "uart_parametres_possibles.h"
#include "uart_configuration_par_defaut.h"

#include "horloge.h"
#include "gpio.h"
#include "interruption.h"

/*#include <stdlib.h>*/

/**
 * @brief Instance de la structure de donnée qui représente l'UART
 *
 * Cette structure est initialisée par la fonction UART_initialiser()
 */
static volatile UART *UART_instance;

/**
 * @name Fonction d'initialisation
 * @{
 */

void UART_initialiser()
{
   UART_instance = (UART*)UART_ADRESSE_BASE;

   /* Activation de la fonction secondaire du port qui gère les broches de l'UART */
   GPIO_activer_fonctions (GPIO_FONCTION_UART);

   /* Activation de la génération d'horloge pour l'UART */
   Horloge_activer (HORLOGE_UART);

   /* Configuration de l'UART avec les réglages par défaut */
   UART_desactiver_interruptions (UART_EVT_TOUS);
	UART_set_format_trame (UART_LONGUEUR_CARACTERE_PAR_DEFAUT, UART_BITS_DE_STOP_PAR_DEFAUT, UART_PARITE_PAR_DEFAUT);
   UART_set_vitesse (UART_VITESSE_PAR_DEFAUT);

   /* Désactiver l'utilisation des FIFOs */
   UART_instance->iir_fcr.fcr.utiliser_fifo = UART_DESACTIVER_FIFO;

   /* Si un caractère est en attente, vider le tampon de réception */
   if(UART_evenement (UART_EVT_RECEPTION))
      UART_recevoir_caractere ();

   /* Libérer la ligne, si ce n'est pas déjà le cas */
	UART_instance->lcr.forcer_arret = UART_LIBERER_LIGNE;
}
 
/** @} */

/**
 * @name Fonctions de configuration
 * @{
 */

void UART_set_format_trame (UART_LongueurCaractere longueur_caractere, UART_LongueurArret nombre_bits_de_stop, UART_TypeParite type_parite)
{
   UART_instance->lcr.longueur_caractere = longueur_caractere;
   UART_instance->lcr.nombre_bits_de_stop = nombre_bits_de_stop;
   UART_instance->lcr.type_parite = type_parite;
}

void UART_set_vitesse (UART_Vitesse vitesse)
{
	int facteur_division;
   /* Activer l'accès aux registres de configuration du diviseur de fréquence */
   UART_instance->lcr.acces_diviseur = UART_ACTIVER_REGLAGE_VITESSE;

   /* Calcul du facteur de division de fréquence et affectation aux registres de configuration du diviseur */
   facteur_division=Horloge_get_frequence_compteurs() / vitesse / 16;
   UART_instance->rbr_thr_dll.valeur = facteur_division & 0xFF;
   UART_instance->ier_dlm.valeur = facteur_division >> 8;

   /* Désactiver l'accès aux registres de configuration du diviseur de fréquence */
   UART_instance->lcr.acces_diviseur = UART_DESACTIVER_REGLAGE_VITESSE;
}

void UART_set_seuil_fifo (UART_SeuilFifo seuil)
{
   UART_instance->iir_fcr.fcr.utiliser_fifo = UART_DESACTIVER_FIFO;

   UART_instance->iir_fcr.fcr.vider_fifo_reception = UART_VIDER_FIFO;
   UART_instance->iir_fcr.fcr.vider_fifo_emission = UART_VIDER_FIFO;

   UART_instance->iir_fcr.fcr.vider_fifo_reception = UART_FIFO_EN_SERVICE;
   UART_instance->iir_fcr.fcr.vider_fifo_emission = UART_FIFO_EN_SERVICE;

   UART_instance->iir_fcr.fcr.seuil = seuil;

   UART_instance->iir_fcr.fcr.utiliser_fifo = UART_ACTIVER_FIFO;
}

/** @} */

/**
 * @name Fonction d'émission/réception en scrutation
 * @{
 */

void UART_envoyer_caractere (char caractere)
{
	while(! UART_evenement (UART_EVT_PRET_A_EMETTRE));
	UART_instance->rbr_thr_dll.valeur = caractere;
}

char UART_recevoir_caractere ()
{
	while(! UART_evenement (UART_EVT_RECEPTION));
	return UART_instance->rbr_thr_dll.valeur;
}

void UART_envoyer_chaine (const char* chaine)
{
	while(*chaine)
	{
		UART_envoyer_caractere (*chaine);
      ++chaine;
	}
}

/** @} */

/**
 * @name Fonctions de gestion des événements
 * @{
 */

void UART_activer_interruptions (UART_MasqueEvenements sources)
{
	UART_instance->ier_dlm.valeur |= sources;
}

void UART_desactiver_interruptions (UART_MasqueEvenements sources)
{
	UART_instance->ier_dlm.valeur &= sources;
}

int UART_evenement (UART_Evenement evenement)
{
   /* Les erreurs de dépassement de délai en réception ne sont pas traitées */
   switch(evenement)
   {
      case UART_EVT_RECEPTION:
         return UART_instance->lsr.donnee_recue == UART_TAMPON_RECEPTION_PLEIN;
         /* Le test ci-dessous ne fonctionne que si les interruptions sont activées : */
         /* return UART_instance->iir_fcr.iir.code == UART_IIR_RECEPTION;*/

      case UART_EVT_PRET_A_EMETTRE:
         return UART_instance->lsr.emetteur_pret == UART_EMISSION_PRET;
         /* Le test ci-dessous ne fonctionne que si les interruptions sont activées : */
         /* return UART_instance->iir_fcr.iir.code == UART_IIR_PRET_A_EMETTRE;*/

      case UART_EVT_ERREUR_RECEPTION:
         return UART_instance->lsr.erreur_parite ||
                UART_instance->lsr.erreur_format;
         /* Le test ci-dessous ne fonctionne que si les interruptions sont activées : */
         /* return UART_instance->iir_fcr.iir.code == UART_IIR_ERREUR_RECEPTION;*/

      case UART_EVT_SYNCHRO_MODEM:
         return UART_instance->msr.evt_cts ||
                UART_instance->msr.evt_dsr ||
                UART_instance->msr.evt_ri ||
                UART_instance->msr.evt_dcd;
         /* Le test ci-dessous ne fonctionne que si les interruptions sont activées : */
         /*return UART_instance->iir_fcr.iir.code == UART_IIR_SYNCHRO_MODEM;*/
   }

   return 0;
}

/** @} */

/** @} */

