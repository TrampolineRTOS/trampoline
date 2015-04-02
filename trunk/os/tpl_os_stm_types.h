#include "tpl_os_internal_types.h" //pour tpl_core_id

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
	
