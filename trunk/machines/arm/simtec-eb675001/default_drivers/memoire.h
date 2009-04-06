/**
 * @addtogroup pilote_arm_memoire
 * Pilote du contrôleur mémoire du microcontrôleur OKI ML675001
 * @{
 */

/**
 * @file memoire.h
 *
 * @brief Interface du pilote du contrôleur mémoire du microcontrôleur OKI ML675001
 *
 * $Author$
 * $Date$
 *
 * @version 1.0
 * $Revision$
 */

#ifndef H_MEMOIRE
#define H_MEMOIRE

/**
 * @brief Initialiser le contrôleur mémoire
 *
 * Cette fonction initialise la gestion des bus externes et le contrôleur
 * de RAM dynamique.
 * Elle met à zéro la mémoire des variables statiques (section BSS).
 *
 * Si l'application est actuellement chargée en mémoire morte, cette fonction
 * effectue automatiquement le basculement en mémoire vive : pour ce faire, les
 * sections de programme et de données sont intégralement recopiées de la ROM vers la
 * DRAM, puis la banque 0 de la mémoire est reconfigurée pour pointer vers la DRAM.
 */
void Memoire_initialiser ();

void Memoire_basculer_dram ();

int Memoire_execution_en_rom ();

int Memoire_execution_en_dram ();

#endif

/** @} */

