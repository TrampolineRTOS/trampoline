/**
 * @addtogroup pilote_arm_memoire
 * @{
 */

/**
 * @file memoire_configuration_par_defaut.h
 *
 * @brief Configuration par défaut du contrôleur mémoire
 *
 * $Author$
 * $Date$
 *
 * @version 1.0
 * $Revision$
 */

#ifndef H_MEMOIRE_CONFIGURATION_PAR_DEFAUT
#define H_MEMOIRE_CONFIGURATION_PAR_DEFAUT

/**
 * @name Valeurs par défaut des registres du contrôleur mémoire
 * @{
 */

/**
 * @brief Configuration par défaut du bus mémoire externe
 *
 * Bus d'entrées/sorties :
 * - ROM externe : 16 bits
 * - RAM externe : non
 * - I/O 0 et 1 (Ethernet) : 16 bits
 * - I/O 2 et 3 (CPLD) : 16 bits
 */
#define MEMOIRE_BWC_PAR_DEFAUT 0x0288

/**
 * @brief Taille par défaut du bus de données vers la SDRAM
 * 
 * Ce paramètre est contraint par le cablage de la mémoire sur la carte EB675001.
 * Le modèle mémoire choisi a un bus de données sur 16 bits.
 */
#define MEMOIRE_DBWC_PAR_DEFAUT 0x02

/**
 * @brief Type de SDRAM par défaut
 *
 * - SDRAM avec adresses de colonnes sur 9 bits (A8 à A0).
 * - Le temps de préchargement est fixé à 2 périodes d'horloge.
 * - Le rafraîchissement automatique CBR est activé.
 * - La mise en veille automatique n'est pas activée.
 */
#define MEMOIRE_DRMC_PAR_DEFAUT 0x81

/**
 * @brief Temps d'accès par défaut à la SDRAM
 *
 * - tRCD = 20 ns < 2 Tclk
 * - tRAS = 45 ns < 3 Tclk
 * - tRP  = 20 ns < 2 Tclk
 * - tDPL = 15 ns < 1 Tclk
 */
#define MEMOIRE_DRPC_PAR_DEFAUT 0x02

/**
 * @brief Mode de fonctionnement par défaut
 *
 * - Latence CAS = 3 périodes d'horloge
 * - Modifier la configuration du contrôleur
 */
#define MEMOIRE_SDMD_PAR_DEFAUT 0x81

/**
 * @brief Facteur de division de fréquence par défaut pour le rafraîchissement CBR automatique
 *
 * Rafraîchissement de la mémoire complète en 64 ms.
 * Pour 8192 lignes, cela nous donne 128000 lignes par seconde.
 *
 * Pour une raison inconnue, les sources fournis avec la carte EB675001
 * effectue un réglage à 64150 Hz avec doublement de période (soit 32 KHz).
 * Les tests confirment que cela suffit.
 */
#define MEMOIRE_RFSH1_PAR_DEFAUT 0x0399

/**
 * @brief Division de fréquence supplémentaire pour le rafraîchissement CBR automatique
 *
 * Doublement de période
 */
#define MEMOIRE_RFSH0_PAR_DEFAUT 0x00

/**
 * @brief Délai de mise en veille par défaut
 *
 * Fixé à 16 période d'horloges.
 * Inutilisé pour le moment.
 */
#define MEMOIRE_RDWC_PAR_DEFAUT 0x0F

/** @brief Valeur de déverrouillage du registre de remapping de la banque mémoire 0 en DRAM */
#define MEMOIRE_RMPCON_DEVERROUILLER 0x3C

/** @brief Remapping de la banque mémoire 0 en DRAM */
#define MEMOIRE_RMPCON_DRAM 0x09

/** @brief Remapping de la banque mémoire 0 en ROM */
#define MEMOIRE_RMPCON_ROM 0x00

/** @brief Remapping de la banque mémoire 0 en ROM */
#define MEMOIRE_RMPCON_MASQUE_ROM 0x08

/** @} */

#endif

/** @} */

