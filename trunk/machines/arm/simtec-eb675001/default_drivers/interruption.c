 /**
 * @addtogroup pilote_arm_interruption
 * @{
 */

/**
 * @file interruption.c
 *
 * @brief Implémentation du pilote du contrôleur d'interruptions du microcontrôleur OKI ML675001
 *
 * @todo Ajouter les autres gestionnaires d'exceptions
 *
 * $Author$
 * $Date$
 *
 * @version 2.0
 * $Revision$
 */

#include "interruption.h"
#include "interruption_parametres_possibles.h"
#include "interruption_configuration_par_defaut.h"
#include "interruption_registres.h"

#define NULL ((void *)0)

/**
 * @brief Tableau des fonctions de gestion d'interruptions (IRQ)
 *
 * Chaque élément de ce tableau correspond à une source d'interruption supportée
 */
static Interruption_Gestionnaire Interruption_gestionnaires_irq [ INTERRUPTION_NOMBRE_SOURCES ]; 

/**
 * @brief Tableau de pointeurs vers les données utilisateur à passer aux gestionnaires d'interruptions (IRQ)
 */
static void *Interruption_arguments_irq [ INTERRUPTION_NOMBRE_SOURCES ];

/** @brief Pointeur vers la fonction de gestion des interruptions rapides (FIQ) */
static Interruption_Gestionnaire Interruption_gestionnaire_fiq;

/** @brief Pointeur vers les données utilisateur à passer au gestionnaire d'interruptiosn rapides (FIQ) */
static void * Interruption_arguments_fiq;

/** @brief Tableau des enregistrements de gestionnaires d'appels systèmes (SWI) */
static struct
{
   /** @brief Numéro d'appel système */
   UInt32 numero_service;

   /** @brief Pointeur vers la fonction de traitement de la demande de service */
   Interruption_GestionnaireAppelSysteme gestionnaire;

} Interruption_gestionnaires_swi [ INTERRUPTION_NOMBRE_SERVICES_SYSTEME ];

/** @brief Nombre de services systèmes enregistres */
static UInt32 Interruption_nombre_services;

/**
 * @name Gestionnaires d'interruptions
 * @{
 */

/**
 * @brief Gestionnaire d'interruption par défaut pour les sources supportées
 */
static void Interruption_gestionnaire_par_defaut ();

/** @} */

/**
 * @name Fonctions d'initialisation 
 * @{
 */

void Interruption_initialiser ()
{
   int s;
   Interruption_desactiver_irq ();
   Interruption_desactiver_fiq ();

   /* Mise en place d'un gestionnaire par défaut pour les différentes sources d'interruptions
    * et désactivation de toutes les sources */

   for(s=0; s<INTERRUPTION_NOMBRE_SOURCES; s++) {
      Interruption_set_gestionnaire_irq (s, Interruption_gestionnaire_par_defaut, NULL);
      Interruption_set_priorite(s, 0);
   }
   Interruption_set_gestionnaire_fiq (Interruption_gestionnaire_par_defaut, NULL);

   Interruption_nombre_services = 0;

   /* Détection sur niveau bas par défaut pour les interruptions externes */
   Interruption_set_detection (INTERRUPTION_EXTERNE_0, INTERRUPTION_DETECTION_NIVEAU_BAS);
   Interruption_set_detection (INTERRUPTION_EXTERNE_1, INTERRUPTION_DETECTION_NIVEAU_BAS);
   Interruption_set_detection (INTERRUPTION_EXTERNE_2, INTERRUPTION_DETECTION_NIVEAU_BAS);
   Interruption_set_detection (INTERRUPTION_EXTERNE_3, INTERRUPTION_DETECTION_NIVEAU_BAS);
}
 
/** @} */ 

/**
 * @name Fonctions de configuration
 * @{
 */

void Interruption_set_priorite (int source, int niveau)
{
   Interruption1 *Interruption_banque1 = (Interruption1*)INTERRUPTION_ADRESSE_BASE_1;
   Interruption2 *Interruption_banque2 = (Interruption2*)INTERRUPTION_ADRESSE_BASE_2;

	switch(source)
	{
      case INTERRUPTION_TIMER_SYSTEME:                
         Interruption_banque1->ilc0.ilr0 = niveau;
         break;

      case INTERRUPTION_WATCHDOG:                     
      case INTERRUPTION_INTERVALLE_WATCHDOG:          
         Interruption_banque1->ilc0.ilr1 = niveau;
         break;

      case INTERRUPTION_GPIO_A:                       
      case INTERRUPTION_GPIO_B:                       
         Interruption_banque1->ilc0.ilr4 = niveau;
         break;

      case INTERRUPTION_GPIO_C:                       
      case INTERRUPTION_GPIO_DE:                      
         Interruption_banque1->ilc0.ilr6 = niveau;
         break;

      case INTERRUPTION_LOGICIELLE:                   
         Interruption_banque1->ilc1.ilr8 = niveau;
         break;

      case INTERRUPTION_UART:                         
         Interruption_banque1->ilc1.ilr9 = niveau;
         break;

      case INTERRUPTION_SIO:                          
         Interruption_banque1->ilc1.ilr10 = niveau;
         break;

      case INTERRUPTION_CONVERTISSEUR_AN:             
         Interruption_banque1->ilc1.ilr11 = niveau;
         break;

      case INTERRUPTION_PWM_0:                        
         Interruption_banque1->ilc1.ilr12 = niveau;
         break;

      case INTERRUPTION_PWM_1:                        
         Interruption_banque1->ilc1.ilr13 = niveau;
         break;

      case INTERRUPTION_SSIO:                        
         Interruption_banque1->ilc1.ilr14 = niveau;
         break;

      case INTERRUPTION_I2C:                          
         Interruption_banque1->ilc1.ilr15 = niveau;
         break;

      case INTERRUPTION_TIMER_0:                      
      case INTERRUPTION_TIMER_1:                      
         Interruption_banque2->ilc.ilr16 = niveau;
         break;

      case INTERRUPTION_TIMER_2:                      
      case INTERRUPTION_TIMER_3:                      
         Interruption_banque2->ilc.ilr18 = niveau;
         break;

      case INTERRUPTION_TIMER_4:                      
      case INTERRUPTION_TIMER_5:                      
         Interruption_banque2->ilc.ilr20 = niveau;
         break;

      case INTERRUPTION_EXTERNE_0:                    
         Interruption_banque2->ilc.ilr22 = niveau;
         break;

      case INTERRUPTION_DMA_0:                        
      case INTERRUPTION_DMA_1:                        
         Interruption_banque2->ilc.ilr24 = niveau;
         break;

      case INTERRUPTION_EXTERNE_1:                    
         Interruption_banque2->ilc.ilr26 = niveau;
         break;

      case INTERRUPTION_EXTERNE_2:                    
      case INTERRUPTION_EXTERNE_3:                    
         Interruption_banque2->ilc.ilr28 = niveau;
	}
}

int Interruption_get_priorite (int source)
{
   Interruption1 *Interruption_banque1 = (Interruption1*)INTERRUPTION_ADRESSE_BASE_1;
   Interruption2 *Interruption_banque2 = (Interruption2*)INTERRUPTION_ADRESSE_BASE_2;

	switch(source)
	{
      case INTERRUPTION_TIMER_SYSTEME:                
         return Interruption_banque1->ilc0.ilr0;
         break;

      case INTERRUPTION_WATCHDOG:                     
      case INTERRUPTION_INTERVALLE_WATCHDOG:          
         return Interruption_banque1->ilc0.ilr1;
         break;

      case INTERRUPTION_GPIO_A:                       
      case INTERRUPTION_GPIO_B:                       
         return Interruption_banque1->ilc0.ilr4;
         break;

      case INTERRUPTION_GPIO_C:                       
      case INTERRUPTION_GPIO_DE:                      
         return Interruption_banque1->ilc0.ilr6;
         break;

      case INTERRUPTION_LOGICIELLE:                   
         return Interruption_banque1->ilc1.ilr8;
         break;

      case INTERRUPTION_UART:                         
         return Interruption_banque1->ilc1.ilr9;
         break;

      case INTERRUPTION_SIO:                          
         return Interruption_banque1->ilc1.ilr10;
         break;

      case INTERRUPTION_CONVERTISSEUR_AN:             
         return Interruption_banque1->ilc1.ilr11;
         break;

      case INTERRUPTION_PWM_0:                        
         return Interruption_banque1->ilc1.ilr12;
         break;

      case INTERRUPTION_PWM_1:                        
         return Interruption_banque1->ilc1.ilr13;
         break;

      case INTERRUPTION_SSIO:                         
         return Interruption_banque1->ilc1.ilr14;
         break;

      case INTERRUPTION_I2C:                          
         return Interruption_banque1->ilc1.ilr15;
         break;

      case INTERRUPTION_TIMER_0:                      
      case INTERRUPTION_TIMER_1:                      
         return Interruption_banque2->ilc.ilr16;
         break;

      case INTERRUPTION_TIMER_2:                      
      case INTERRUPTION_TIMER_3:                      
         return Interruption_banque2->ilc.ilr18;
         break;

      case INTERRUPTION_TIMER_4:                      
      case INTERRUPTION_TIMER_5:                      
         return Interruption_banque2->ilc.ilr20;
         break;

      case INTERRUPTION_EXTERNE_0:                    
         return Interruption_banque2->ilc.ilr22;
         break;

      case INTERRUPTION_DMA_0:                        
      case INTERRUPTION_DMA_1:                        
         return Interruption_banque2->ilc.ilr24;
         break;

      case INTERRUPTION_EXTERNE_1:                    
         return Interruption_banque2->ilc.ilr26;
         break;

      case INTERRUPTION_EXTERNE_2:                    
      case INTERRUPTION_EXTERNE_3:                    
         return Interruption_banque2->ilc.ilr28;
	}
}

void Interruption_set_gestionnaire_irq (int source, Interruption_Gestionnaire gestionnaire, void *arguments)
{
	Interruption_gestionnaires_irq[source] = gestionnaire;
   Interruption_arguments_irq[source] = arguments;
}

void Interruption_set_gestionnaire_fiq (Interruption_Gestionnaire gestionnaire, void *arguments)
{
	Interruption_gestionnaire_fiq = gestionnaire;
   Interruption_arguments_fiq = arguments;
}

void Interruption_set_gestionnaire_swi (UInt32 numero_service, Interruption_GestionnaireAppelSysteme gestionnaire)
{
   if(Interruption_nombre_services < INTERRUPTION_NOMBRE_SERVICES_SYSTEME) {
      Interruption_gestionnaires_swi [Interruption_nombre_services].numero_service = numero_service;
      Interruption_gestionnaires_swi [Interruption_nombre_services].gestionnaire = gestionnaire;
      ++ Interruption_nombre_services;
   }
}

void Interruption_set_detection (int source, int mode)
{
   Interruption2 *Interruption_banque2 = (Interruption2*)INTERRUPTION_ADRESSE_BASE_2;

   switch(source)
   {
      case INTERRUPTION_EXTERNE_0:                    
         Interruption_banque2->idm.idm22 = mode;
         break;

      case INTERRUPTION_EXTERNE_1:                    
         Interruption_banque2->idm.idm26 = mode;
         break;

      case INTERRUPTION_EXTERNE_2:                    
         Interruption_banque2->idm.idm28 = mode;
         break;

      case INTERRUPTION_EXTERNE_3:                    
         Interruption_banque2->idm.idm31 = mode;
   }
}

/** @} */

/**
 * @name Gestionnaires d'interruptions
 * @{
 */

/**
 * @brief Gestionnaire principal des interruptions de type IRQ
 *
 * Cette fonction est invoquée systématiquement pour toutes les demandes d'interruptions de type IRQ.
 * Elle se charge de rediriger le traitement vers le gestionnaire affecté à la source de la demande.
 */
__attribute__ ((interrupt ("IRQ")))
void Interruption_gestionnaire_principal_irq ()
{
   Interruption1 *Interruption_banque1 = (Interruption1*)INTERRUPTION_ADRESSE_BASE_1;

   /* Identification du numéro de la source de la demande */
   int source = Interruption_banque1->irn.source;

   /* Invocation du gestionnaire d'interruption pour la source identifiée */
   Interruption_gestionnaires_irq[source] (Interruption_arguments_irq[source]);

   Interruption_acquitter_niveau_courant ();
}

void Interruption_acquitter_niveau_courant ()
{
   Interruption1 *Interruption_banque1 = (Interruption1*)INTERRUPTION_ADRESSE_BASE_1;
   Interruption2 *Interruption_banque2 = (Interruption2*)INTERRUPTION_ADRESSE_BASE_2;

   int source = Interruption_banque1->irn.source;

   /* Acquittement de la demande pour le niveau de priorité courant */
   Interruption_banque1->cilcl = INTERRUPTION_ACQUITTEMENT;

   /* Acquittement de la demande pour une interruption externe avec détection sur front */
   if(source == INTERRUPTION_EXTERNE_0 ||
      source == INTERRUPTION_EXTERNE_1 ||
      source == INTERRUPTION_EXTERNE_2 ||
      source == INTERRUPTION_EXTERNE_3)
      Interruption_banque2->ircl = source;
}

/**
 * @brief Gestionnaire principal des interruptions de type FIQ
 *
 * Cette fonction est invoquée systématiquement pour toutes les demandes d'interruptions de type FIQ.
 * Elle se charge de rediriger le traitement vers le gestionnaire affecté à la source de la demande.
 */
__attribute__ ((interrupt ("FIQ")))
void Interruption_gestionnaire_principal_fiq ()
{
   Interruption_gestionnaire_fiq (Interruption_arguments_fiq);

   /* @todo Acquitter les FIQ ?*/
}

UInt32 Interruption_gestionnaire_principal_swi (UInt32 numero_service, UInt32 *arguments)
{
   UInt32 i;
   for(i=0; i<Interruption_nombre_services; i++) {
      if(Interruption_gestionnaires_swi[i].numero_service == numero_service)
         return Interruption_gestionnaires_swi[i].gestionnaire(arguments);
   }
}

static void Interruption_gestionnaire_par_defaut ()
{
   
}

/** @} */

/**
 * @name Fonctions de gestion des événements
 * @{
 */
int Interruption_get_source ()
{
  Interruption1 *Interruption_banque1 = (Interruption1*)INTERRUPTION_ADRESSE_BASE_1;
  return Interruption_banque1->irn.source;
}

void Interruption_activer_irq ()
{
   /* Ce sous-programme agit directement sur le registre d'état
    * en positionnant à 0 le bit IRQ (bit 7) */
   __asm__(
      "mrs r4, cpsr;"
      "bic r4, r4, #0x80;"
      "msr cpsr_c, r4"
   );
}

void Interruption_desactiver_irq ()
{
   /* Ce sous-programme agit directement sur le registre d'état
    * en positionnant à 1 le bit IRQ (bit 7) */
   __asm__(
      "mrs r4, cpsr;"
      "orr r4, r4, #0x80;"
      "msr cpsr_c, r4"
   );
}

void Interruption_activer_fiq ()
{
   /* Ce sous-programme agit directement sur le registre d'état
    * en positionnant à 0 le bit FIQ (bit 6) */
   __asm__(
      "mrs r4, cpsr;"
      "bic r4, r4, #0x40;"
      "msr cpsr_c, r4"
   );
}

void Interruption_desactiver_fiq ()
{
   /* Ce sous-programme agit directement sur le registre d'état
    * en positionnant à 1 le bit FIQ (bit 6) */
   __asm__(
      "mrs r4, cpsr;"
      "orr r4, r4, #0x40;"
      "msr cpsr_c, r4"
   );
}

/** @} */

/** @}*/ 

