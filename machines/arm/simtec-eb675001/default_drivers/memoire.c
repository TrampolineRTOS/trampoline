/**
 * @addtogroup pilote_arm_memoire
 * @{
 */

/**
 * @file memoire.c
 *
 * @brief Implémentation du pilote du contrôleur mémoire du microcontrôleur OKI ML675001
 *
 * Ce module n'utilise pas de variable globale de manière à pouvoir être exécuté intégralement
 * en ROM au démarrage.
 *
 * $Author$
 * $Date$
 *
 * @version 1.0
 * $Revision$
 */

#include "memoire.h"
#include "memoire_configuration_par_defaut.h"
#include "memoire_registres.h"
#include "horloge.h"

void Memoire_initialiser ()
{
  int i;

  /* Configuration de la largeur du bus externe */
  UInt32 *bwc = (UInt32*)MEMOIRE_BWC_REG;
  *bwc = MEMOIRE_BWC_PAR_DEFAUT;

  /* Mettre en service la mémoire dynamique, si nécessaire */
  if(Memoire_execution_en_rom ()) {
    Horloge_activer (HORLOGE_DRAM);

    Memoire_ControleurSDRAM *controleur_sdram = (Memoire_ControleurSDRAM*)MEMOIRE_CONTROLEUR_DRAM_ADRESSE_BASE;

    /* 1. Attendre au moins 200 microsecondes avant d'initialiser le contrôleur
     *    On utilise une boucle d'attente plutôt qu'un timer. */
    for(i= HORLOGE_FREQUENCE_HCLK / 5000; i > 0; i--);

    /* 2. Configurer la largeur de bus et les temps d'accès */
    controleur_sdram->dbwc = MEMOIRE_DBWC_PAR_DEFAUT;
    controleur_sdram->drpc = MEMOIRE_DRPC_PAR_DEFAUT;

    /* 3. Forcer un préchargement et 8 cycles de rafraîchissement */
    controleur_sdram->dcmd = SDRAM_PRECHARGE_ALL;
    for(i=0; i<8; i++)
      controleur_sdram->dcmd = SDRAM_REFRESH;

    /* 4. Configurer les autres paramètres de fonctionnement de la DRAM,
     *    les cycles de rafraîchissement automatique et la mise en veille */
    controleur_sdram->drmc = MEMOIRE_DRMC_PAR_DEFAUT;
    controleur_sdram->sdmd = MEMOIRE_SDMD_PAR_DEFAUT;
    controleur_sdram->rfsh0 = MEMOIRE_RFSH0_PAR_DEFAUT;
    controleur_sdram->rfsh1 = MEMOIRE_RFSH1_PAR_DEFAUT;
    controleur_sdram->rdwc = MEMOIRE_RDWC_PAR_DEFAUT;
  }
}

int Memoire_execution_en_rom ()
{
  UInt32 *rmpcon = (UInt32*)MEMOIRE_RMPCON_REG;
  return (*rmpcon & MEMOIRE_RMPCON_MASQUE_ROM) == MEMOIRE_RMPCON_ROM;
}

int Memoire_execution_en_dram ()
{
  UInt32 *rmpcon = (UInt32*)MEMOIRE_RMPCON_REG;
  return *rmpcon == MEMOIRE_RMPCON_DRAM;
}

void Memoire_basculer_dram ()
{
   /* Copier cette fonction de la ROM vers la DRAM. */

   /* Les instructions du programme sont copiées
    * de l'étiquette Memoire_basculer_dram_debut_copie
    * à l'étiquette Memoire_basculer_dram_fin_copie. */
   UInt32 *src = (UInt32*)&&Memoire_basculer_dram_debut_copie;
   UInt32 *fin_src = (UInt32*)&&Memoire_basculer_dram_fin_copie;

   /* La destination de la copie est l'adresse de base
    * de la banque de DRAM */
   UInt32 *dest = (UInt32*)MEMOIRE_DRAM_ADRESSE_BASE;

   /* La copie se fait par mots de 32 bits.
    * Le nombre de mots à copier est assez petit */
   while(src < fin_src)
      *dest ++ = *src ++;

   UInt32 *rmpcon = (UInt32*)MEMOIRE_RMPCON_REG;

Memoire_basculer_dram_debut_copie:

   /* Positionner la DRAM en tant que banque 0 */
   *rmpcon = MEMOIRE_RMPCON_DEVERROUILLER;
   *rmpcon = MEMOIRE_RMPCON_DRAM;

   /* Branchement au vecteur reset */
   __asm__("mov pc, #0");

Memoire_basculer_dram_fin_copie:
   ;
}

#if 0
void Memoire_charger_en_dram ()
{
	UInt32 *rmpcon = (UInt32*)MEMOIRE_RMPCON_REG;
	UInt32 *ptr_bss = &debut_bss;
   /* Copier le contenu de la ROM vers la DRAM */
   UInt32 *ptr_rom = &debut_rom;
   UInt32 *ptr_ram = (UInt32*)MEMOIRE_DRAM_ADRESSE_BASE;

   while(ptr_rom < &fin_rom)
      *ptr_ram ++ = *ptr_rom ++;

   /* Positionner la DRAM en tant que banque 0 */
   
   *rmpcon = MEMOIRE_RMPCON_DEVERROUILLER;
   *rmpcon = MEMOIRE_RMPCON_DRAM;

  /* Remettre à zéro la section BSS */
  
  /*while(ptr_bss < &fin_bss)
    *ptr_bss ++ = 0;*/
}
#endif

/** @} */

