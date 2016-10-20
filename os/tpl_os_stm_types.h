/**
 * @file tpl_os_stm_types.h
 *
 * @section descr File description
 *
 * Types definitions for STM-HRT.
 *
 * @section copyright Copyright
 *
 * Trampoline RTOS
 *
 * Trampoline is copyright (c) CNRS, University of Nantes, Ecole Centrale de Nantes
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the GNU Public Licence V2.
 * Check the LICENSE file in the root directory of Trampoline
 *
 * @section infos File informations
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#include "tpl_os_internal_types.h" /* pour tpl_core_id */

/**
 * @typedef tpl_stm_object_id
 *
 * Object id
 */
typedef uint32 tpl_stm_object_id;

/**
 * @typedef ObjectType
 *
 * Object identifier
 *
 */
typedef tpl_stm_object_id  ObjectType;

/**
 * @typedef tpl_stm_data
 *
 * Object data
 */
typedef void tpl_stm_data;

#define DeclareObject(object_id) extern CONST(ObjectType, AUTOMATIC) object_id

