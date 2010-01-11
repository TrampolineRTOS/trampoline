/**
 * @addtogroup pilotes_arm_gpio
 * @{
 */

/**
 * @file gpio.c
 *
 * @brief Implémentation du pilote du contrôleur d'entrées/sorties généralistes (GPIO) du microcontrôleur OKI ML675001
 *
 * $Author: GuillaumeSavaton $
 * $Date: 2007/09/19 07:16:40 $
 *
 * @version 2.0
 * $Revision: 1.4 $
 *
 * @todo Renommer ce fichier en gpio.c
 */

#include "gpio.h"
#include "gpio_registres.h"

static GPIO_Port *GPIO_instance;
static GPIO_Registre *GPIO_gpctl;

/**
 * @name Fonction d'initialisation
 * @{
 */

void GPIO_initialiser ()
{
   GPIO_instance = (GPIO_Port*)GPIO_ADRESSE_BASE;
   GPIO_gpctl = (GPIO_Registre*)GPIO_ADRESSE_GPCTL;
}

/** @} */

/**
 * @name Fonctions de configuration
 * @{
 */

void GPIO_activer_fonctions (int fonctions)
{
   GPIO_gpctl->valeur |= fonctions;
}
  
void GPIO_desactiver_fonctions (int fonctions)
{
   GPIO_gpctl->valeur &= ~fonctions;
}
  
void GPIO_set_entrees (int port, UInt16 masque)
{
   GPIO_instance[port].gppm.valeur &= ~masque;
}

void GPIO_set_sorties (int port, UInt16 masque)
{
   GPIO_instance[port].gppm.valeur |= masque;
}

/** @} */

/**
 * @name Fonctions de lecture/écriture sur les ports
 * @{
 */

UInt16 GPIO_lire (int port)
{
   if(port == GPIO_PORT_E)
      return GPIO_instance[port].gppi.valeur & GPIO_MASQUE_E;
   else
      return GPIO_instance[port].gppi.valeur & GPIO_MASQUE_A_D;
}

void GPIO_ecrire (int port, UInt16 valeur)
{
   GPIO_instance[port].gppo.valeur = valeur;
}

/** @} */

/** @} */

