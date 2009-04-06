/**
 * @addtogroup pilote_arm_memoire
 * @{
 */

/**
 * @file memoire_registres.h
 *
 * @brief Définition des registres du contrôleur mémoire
 *
 * $Author$
 * $Date$
 *
 * @version 1.0
 * $Revision$
 */

#ifndef H_MEMOIRE_REGISTRES
#define H_MEMOIRE_REGISTRES

#include "miro_types.h"

/** @brief Adresse du registre de configuration de largeur de bus externe */  
#define MEMOIRE_BWC_REG 0x78100000

/** @brief Adresse du registre de configuration du mapping de la banque 0 */
#define MEMOIRE_RMPCON_REG 0xB8000010

/** @brief Adresse de base des registres du contrôleur SDRAM */
#define MEMOIRE_CONTROLEUR_DRAM_ADRESSE_BASE 0x78180000

/** @brief Adresse de début de la DRAM */
#define MEMOIRE_DRAM_ADRESSE_BASE 0xC0000000

/** @brief Taille de la DRAM, en octets */
#define MEMOIRE_DRAM_TAILLE 0x2000000

typedef enum {
   SDRAM_NO_OPERATION = 0x00,
   SDRAM_PRECHARGE_ALL = 0x04,
   SDRAM_REFRESH,
   SDRAM_START_SELF_REFRESH,
   SDRAM_STOP_SELF_REFRESH,
} Memoire_CommandeSDRAM ;

typedef struct {
   UInt32 dbwc;
   UInt32 drmc;
   UInt32 drpc;
   UInt32 sdmd;
   UInt32 dcmd;
   UInt32 rfsh0;
   UInt32 rdwc;
   UInt32 rfsh1;
} Memoire_ControleurSDRAM;

#endif

/** @} */

