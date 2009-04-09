/**
 * @addtogroup pilote_arm_i2c
 * @{
 */

/**
 * @file i2c.c
 *
 * @brief Implémentation du pilote de contrôleur I2C pour le microcontrôleur OKI ML675001
 *
 * $Author: LaurentMenard $
 * $Date: 2008/01/17 08:47:20 $
 *
 * @version 2.0
 * $Revision: 1.1.1.1 $
 */

#include "i2c.h"
#include "i2c_registres.h"
#include "i2c_parametres_possibles.h"
#include "i2c_configuration_par_defaut.h"
#include "gpio.h"
#include "horloge.h"

/** @brief Etats possibles du pilote */
typedef enum 
{
   /** @brief Pas de communication en cours */
   I2C_TRAME_REPOS,

   /** @brief Une trame de lecture a été entamée */
	I2C_TRAME_LECTURE,

   /** @brief Une trame d'écriture a été entamée */
   I2C_TRAME_ECRITURE

} I2C_EtatTrame;

/** @brief Etat courant du pilote */
static I2C_EtatTrame I2C_etat_trame;

/** @brief Adresse de l'esclave pour lequel un transfert est en cours */
static int I2C_adresse_courante;

/** @brief Accès aux registres du contrôleur I2C */
static I2C* I2C_instance;

/** @brief Image du registre d'état après une détection d'acquittement */
static I2C_RegSr I2C_erreurs;

/**
 * @name Fonction d'initialisation
 * @{
 */

void I2C_initialiser ()
{
   /* Activer le générateur d'horloge pour le contrôleur I2C */
   Horloge_activer (HORLOGE_I2C);

   /* Activer les broches du contrôleur I2C */
   GPIO_activer_fonctions (GPIO_FONCTION_I2C);

   /* Initialisation de l'état courant du pilote */
   I2C_etat_trame = I2C_TRAME_REPOS;

   /* Initialisation du pointeur vers les registres du contrôleur I2C */
   I2C_instance = (I2C*)I2C_ADRESSE_BASE;

   /* Initialisation de la fréquence d'horloge */
	I2C_set_vitesse (I2C_MODE_PAR_DEFAUT);
}

/** @} */

/**
 * @name Fonctions de configuration
 * @{
 */

void I2C_set_vitesse (int vitesse)
{
   
   int division;
   I2C_instance->clr.valeur = vitesse;

   
   if(vitesse == I2C_MODE_RAPIDE)
      division = HORLOGE_FREQUENCE_HCLK / I2C_FREQUENCE_RAPIDE;
   else
      division = HORLOGE_FREQUENCE_HCLK / I2C_FREQUENCE_STANDARD;

   if(division % 8 < 4)
      I2C_instance->bc.valeur =  division / 8;
   else
      I2C_instance->bc.valeur = division / 8 + 1;
}

/** @} */

/**
 * @name Fonctions d'échanges de données
 * @{
 */

void I2C_ecrire (UInt8 adresse, UInt8 donnee)
{
   /* Positionner l'adresse, la donnée et le sens de transfert */
   I2C_instance->sad.rw = I2C_ECRITURE;
   I2C_instance->sad.sad = adresse;
   I2C_instance->dr.valeur = donnee;

   /* En cas de changement d'adresse ou de sens de transfert,
    * générer un restart */
	if (I2C_etat_trame == I2C_TRAME_ECRITURE && I2C_adresse_courante != adresse
    || I2C_etat_trame == I2C_TRAME_LECTURE)
      I2C_instance->con.en = I2C_REDEMARRER;
   else
      I2C_instance->con.en = I2C_CONTINUER; 

   /* Déclencher l'écriture en laissant la trame ouverte */
	I2C_instance->con.oc = I2C_LAISSER_OUVERT;
   I2C_instance->con.stcm = I2C_TRANSFERER;

   /* Mettre à jour l'état courant du pilote */
	I2C_etat_trame = I2C_TRAME_ECRITURE;
	I2C_adresse_courante = adresse;
}

void I2C_ecrire_et_stopper (UInt8 adresse, UInt8 donnee)
{
   /* Positionner l'adresse, la donnée et le sens de transfert */
   I2C_instance->sad.rw = I2C_ECRITURE;
   I2C_instance->sad.sad = adresse;
   I2C_instance->dr.valeur = donnee;

   /* En cas de changement d'adresse ou de sens de transfert,
    * générer un restart */
	if (I2C_etat_trame == I2C_TRAME_ECRITURE && I2C_adresse_courante != adresse
    || I2C_etat_trame == I2C_TRAME_LECTURE)
      I2C_instance->con.en = I2C_REDEMARRER;
   else
      I2C_instance->con.en = I2C_CONTINUER; 

   /* Déclencher l'écriture en refermant la trame */
	I2C_instance->con.oc = I2C_FERMER;
   I2C_instance->con.stcm = I2C_TRANSFERER;

   /* Mettre à jour l'état courant du pilote */
	I2C_etat_trame = I2C_TRAME_REPOS;
}

UInt8 I2C_lire(UInt8 adresse)
{
   /* Positionner l'adresse et le sens de transfert */
   I2C_instance->sad.rw = I2C_LECTURE;
   I2C_instance->sad.sad = adresse;

   /* En cas de changement d'adresse ou de sens de transfert,
    * générer un restart */
	if (I2C_etat_trame == I2C_TRAME_LECTURE && I2C_adresse_courante != adresse
    || I2C_etat_trame == I2C_TRAME_ECRITURE)
      I2C_instance->con.en = I2C_REDEMARRER;
   else
      I2C_instance->con.en = I2C_CONTINUER; 

   /* Déclencher la lecture en laissant la trame ouverte */
	I2C_instance->con.oc = I2C_LAISSER_OUVERT;
   I2C_instance->con.stcm = I2C_TRANSFERER;
   I2C_instance->con.restr = I2C_ACQUITTER_RECEPTION;

   /* La lecture est bloquante */
	I2C_attendre_acquittement ();

   /* Mettre à jour l'état courant du pilote */
	I2C_etat_trame = I2C_TRAME_LECTURE;
	I2C_adresse_courante = adresse;

   /* Lire et retourner l'octet reçu */
	return I2C_instance->dr.valeur;
}

UInt8 I2C_lire_et_stopper(UInt8 adresse)
{
   /* Positionner l'adresse et le sens de transfert */
   I2C_instance->sad.rw = I2C_LECTURE;
   I2C_instance->sad.sad = adresse;

   /* En cas de changement d'adresse ou de sens de transfert,
    * générer un restart */
	if (I2C_etat_trame == I2C_TRAME_LECTURE && I2C_adresse_courante != adresse
    || I2C_etat_trame == I2C_TRAME_ECRITURE)
      I2C_instance->con.en = I2C_REDEMARRER;
   else
      I2C_instance->con.en = I2C_CONTINUER; 

   /* Déclencher la lecture en refermant la trame */
	I2C_instance->con.oc = I2C_FERMER;
   I2C_instance->con.stcm = I2C_TRANSFERER;
   I2C_instance->con.restr = I2C_ACQUITTER_RECEPTION;

   /* La lecture est bloquante */
	I2C_attendre_acquittement ();

   /* Mettre à jour l'état courant du pilote */
	I2C_etat_trame = I2C_TRAME_REPOS;

   /* Lire et retourner l'octet reçu */
	return I2C_instance->dr.valeur;
}

void I2C_attendre_acquittement()
{
   /* Attendre la levée de l'indicateur de demande d'interruption */
   while(I2C_instance->ir.valeur != I2C_DEMANDE_INTERRUPTION);

   /* Gestion des erreurs */
   I2C_erreurs = I2C_instance->sr;

   /* Acquitter la demande d'interruption */
   I2C_instance->ir.valeur = I2C_ACQUITTER_INTERRUPTION;
}

/** @} */

/**
 * @name Fonctions de gestion des événements
 * @{
 */

void I2C_activer_interruptions ()
{
   I2C_instance->imr.valeur = I2C_ACTIVER_INTERRUPTIONS;
}

void I2C_desactiver_interruptions ()
{
   I2C_instance->imr.valeur = I2C_DESACTIVER_INTERRUPTIONS;
}

/** @} */

/**
 * @name Fonctions de gestion des erreurs
 * @{
 */

I2C_CodeErreur I2C_get_code_erreur ()
{
   if(I2C_erreurs.aak == I2C_ERREUR)
      return I2C_ERREUR_ADRESSE;
   else if(I2C_erreurs.dak == I2C_ERREUR)
      return I2C_ERREUR_DONNEE;
   else
      return I2C_OK;
}

/** @} */

/** @} */

