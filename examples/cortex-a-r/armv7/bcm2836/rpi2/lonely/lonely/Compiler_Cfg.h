/**
 * @file Compiler_Cfg.h
 *
 * @section desc File description
 *
 * Compiler abstraction for all AUTOSAR Modules
 *
 * @section copyright Copyright
 *
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005-2007
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */
#ifndef COMPILER_CFG_H
#define COMPILER_CFG_H

/*****************************************************************************/
/* DEFINITION OF MACROS                                                      */
/*****************************************************************************/

/*****************************************************************************/
/* Communication stack global definitions                                    */
/*****************************************************************************/
#define AUTOSAR_COMSTACKDATA                          __long_call__


/*****************************************************************************/
/* GPT                                                                       */
/*****************************************************************************/
#define GPT_CODE                                      AUTOMATIC
#define GPT_VAR_NOINIT                                __long_call__
#define GPT_VAR_POWER_ON_INIT                         AUTOMATIC
#define GPT_VAR_FAST                                  AUTOMATIC
#define GPT_VAR                                       AUTOMATIC
#define GPT_CONST                                     AUTOMATIC
#define GPT_APPL_DATA                                 AUTOMATIC
#define GPT_APPL_CONST                                AUTOMATIC
#define GPT_APPL_CODE                                 __short_call__

/*****************************************************************************/
/* ECUM                                                                      */
/*****************************************************************************/
#define ECUM_CODE                                     AUTOMATIC
#define ECUM_VAR_NOINIT                               __long_call__
#define ECUM_VAR_POWER_ON_INIT                        AUTOMATIC
#define ECUM_VAR_FAST                                 AUTOMATIC
#define ECUM_VAR                                      AUTOMATIC
#define ECUM_CONST                                    __long_call__
#define ECUM_APPL_DATA                                AUTOMATIC
#define ECUM_APPL_CONST                               AUTOMATIC
#define ECUM_APPL_CODE                                __short_call__

/*****************************************************************************/
/* SchM                                                                      */
/*****************************************************************************/
#define SCHM_CODE                                     AUTOMATIC
#define SCHM_VAR_NOINIT                               __long_call__
#define SCHM_VAR_POWER_ON_INIT                        AUTOMATIC
#define SCHM_VAR_FAST                                 AUTOMATIC
#define SCHM_VAR                                      AUTOMATIC
#define SCHM_CONST                                    AUTOMATIC
#define SCHM_APPL_DATA                                __long_call__
#define SCHM_APPL_CONST                               AUTOMATIC
#define SCHM_APPL_CODE                                __short_call__

/*****************************************************************************/
/* OS                                                                        */
/*****************************************************************************/
#define OS_CODE                                       AUTOMATIC
#define OS_VAR_NOINIT                                 AUTOMATIC
#define OS_VAR_POWER_ON_INIT                          AUTOMATIC
#define OS_VAR_FAST                                   AUTOMATIC
#define OS_VAR                                        AUTOMATIC
#define OS_CONST                                      AUTOMATIC
#define OS_APPL_DATA                                  AUTOMATIC
#define OS_APPL_CONST                                 AUTOMATIC
#define OS_APPL_CODE                                  AUTOMATIC

/*****************************************************************************/
/* COM                                                                       */
/*****************************************************************************/
#define COM_CODE                                      AUTOMATIC
#define COM_VAR_NOINIT                                AUTOMATIC
#define COM_VAR_POWER_ON_INIT                         AUTOMATIC
#define COM_VAR_FAST                                  AUTOMATIC
#define COM_VAR                                       AUTOMATIC
#define COM_CONST                                     AUTOMATIC
#define COM_APPL_DATA                                 AUTOMATIC
#define COM_APPL_CONST                                AUTOMATIC
#define COM_APPL_CODE                                 AUTOMATIC

/*****************************************************************************/
/* MCU                                                                       */
/*****************************************************************************/
#define MCU_CODE                                      AUTOMATIC
#define MCU_VAR_NOINIT                                __long_call__
#define MCU_VAR_POWER_ON_INIT                         AUTOMATIC
#define MCU_VAR_FAST                                  AUTOMATIC
#define MCU_VAR                                       AUTOMATIC
#define MCU_CONST                                     AUTOMATIC
#define MCU_APPL_DATA                                 AUTOMATIC
#define MCU_APPL_CONST                                AUTOMATIC
#define MCU_APPL_CODE                                 AUTOMATIC

/*****************************************************************************/
/* CAN TP                                                                    */
/*****************************************************************************/
#define CANTP_CODE                                    AUTOMATIC
#define CANTP_VAR_NOINIT                              __long_call__
#define CANTP_VAR_POWER_ON_INIT                       AUTOMATIC
#define CANTP_VAR_FAST                                AUTOMATIC
#define CANTP_VAR                                     AUTOMATIC
#define CANTP_CONST                                   AUTOMATIC
#define CANTP_APPL_DATA                               AUTOMATIC
#define CANTP_APPL_CONST                              AUTOMATIC
#define CANTP_APPL_CODE                               __short_call__

/*****************************************************************************/
/* FRIF                                                                      */
/*****************************************************************************/
#define FRIF_CODE                                     AUTOMATIC
#define FRIF_VAR_NOINIT                               __long_call__
#define FRIF_VAR_POWER_ON_INIT                        AUTOMATIC
#define FRIF_VAR_FAST                                 AUTOMATIC
#define FRIF_VAR                                      AUTOMATIC
#define FRIF_CONST                                    AUTOMATIC
#define FRIF_APPL_DATA                                AUTOMATIC
#define FRIF_APPL_CONST                               AUTOMATIC
#define FRIF_APPL_CODE                                __short_call__

/*****************************************************************************/
/* LINIF                                                                     */
/*****************************************************************************/
#define LINIF_CODE                                    AUTOMATIC
#define LINIF_VAR_NOINIT                              __long_call__
#define LINIF_VAR_POWER_ON_INIT                       AUTOMATIC
#define LINIF_VAR_FAST                                AUTOMATIC
#define LINIF_VAR                                     AUTOMATIC
#define LINIF_CONST                                   AUTOMATIC
#define LINIF_APPL_DATA                               AUTOMATIC
#define LINIF_APPL_CONST                              AUTOMATIC
#define LINIF_APPL_CODE                               __short_call__

/*****************************************************************************/
/* LINTP                                                                     */
/*****************************************************************************/
#define LINTP_CODE                                    AUTOMATIC
#define LINTP_VAR_NOINIT                              __long_call__
#define LINTP_VAR_POWER_ON_INIT                       AUTOMATIC
#define LINTP_VAR_FAST                                AUTOMATIC
#define LINTP_VAR                                     AUTOMATIC
#define LINTP_CONST                                   AUTOMATIC
#define LINTP_APPL_DATA                               AUTOMATIC
#define LINTP_APPL_CONST                              AUTOMATIC
#define LINTP_APPL_CODE                               __short_call__

/*****************************************************************************/
/* WDGM                                                                      */
/*****************************************************************************/
#define WDGM_CODE                                     AUTOMATIC
#define WDGM_VAR_NOINIT                               __long_call__
#define WDGM_VAR_POWER_ON_INIT                        AUTOMATIC
#define WDGM_VAR_FAST                                 AUTOMATIC
#define WDGM_VAR                                      AUTOMATIC
#define WDGM_CONST                                    AUTOMATIC
#define WDGM_APPL_DATA                                AUTOMATIC
#define WDGM_APPL_CONST                               AUTOMATIC
#define WDGM_APPL_CODE                                __short_call__

/*****************************************************************************/
/* WdgIf                                                                     */
/*****************************************************************************/
#define WDGIF_CODE                                    AUTOMATIC
#define WDGIF_VAR_NOINIT                              __long_call__
#define WDGIF_VAR_POWER_ON_INIT                       AUTOMATIC
#define WDGIF_VAR_FAST                                AUTOMATIC
#define WDGIF_VAR                                     AUTOMATIC
#define WDGIF_CONST                                   AUTOMATIC
#define WDGIF_APPL_DATA                               AUTOMATIC
#define WDGIF_APPL_CONST                              AUTOMATIC
#define WDGIF_APPL_CODE                               __short_call__

#endif /* COMPILER_CFG_H */

