/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline est protÈgÈ par la loi sur la propriÈtÈ intellectuelle
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline communication errors macro, functions and datatypes header
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#ifndef __TPL_COM_ERROR_H__
#define __TPL_COM_ERROR_H__

#include "tpl_com_definitions.h"
#include "tpl_com_internal.h"

#if WITH_COM_ERROR_HOOK == YES

#include "tpl_service_ids.h"

union COM_PARAM_BLOCK {
    COMApplicationModeType  app_mode;
    COMShutdownModeType     shut_mode;
    MessageIdentifier       mess_id;
};

struct COM_PARAM_PARAM_BLOCK {
    tpl_com_data            *data_ref;
    LengthRef               length_ref;
    union COM_PARAM_BLOCK   id_or_mode;
};

struct COM_SERVICE_CALL_DESCRIPTOR {
    unsigned char                   service_id;
    struct COM_PARAM_PARAM_BLOCK    parameters;
};

typedef struct COM_SERVICE_CALL_DESCRIPTOR tpl_com_service_call_descriptor;

extern tpl_com_service_call_descriptor tpl_com_service;

/*
 * macros to access the service id and its parameters from hook routine
 */
#define COMErrorGetServiceId()   (tpl_com_service.service_id)

/*  StartCOM parameter  */
#define COMError_StartCOM_Mode()   \
    (tpl_com_service.parameters.id_or_mode.app_mode)

/*  StopCOM parameter  */
#define COMError_StopCOM_Mode()   \
    (tpl_com_service.parameters.id_or_mode.app_mode)

/*  InitMessage Message parameter  */
#define COMError_InitMessage_Message()   \
    (tpl_com_service.parameters.id_or_mode.mess_id)

/*  InitMessage DataRef parameter  */
#define COMError_InitMessage_DataRef()   \
    (tpl_com_service.parameters.data_ref)

/*  SendMessage Message parameter  */
#define COMError_SendMessage_Message()   \
    (tpl_com_service.parameters.id_or_mode.mess_id)

/*  SendMessage DataRef parameter  */
#define COMError_SendMessage_DataRef()   \
    (tpl_com_service.parameters.data_ref)

/*  ReceiveMessage Message parameter  */
#define COMError_ReceiveMessage_Message()   \
    (tpl_com_service.parameters.id_or_mode.mess_id)

/*  ReceiveMessage DataRef parameter  */
#define COMError_ReceiveMessage_DataRef()   \
    (tpl_com_service.parameters.data_ref)

/*  SendDynamicMessage Message parameter  */
#define COMError_SendDynamicMessage_Message()   \
    (tpl_com_service.parameters.id_or_mode.mess_id)

/*  SendDynamicMessage DataRef parameter  */
#define COMError_SendDynamicMessage_DataRef()   \
    (tpl_com_service.parameters.data_ref)

/*  SendDynamicMessage LengthRef parameter  */
#define COMError_SendDynamicMessage_LengthRef()   \
    (tpl_com_service.parameters.length_ref)

/*  ReceiveDynamicMessage Message parameter  */
#define COMError_ReceiveDynamicMessage_Message()   \
    (tpl_com_service.parameters.id_or_mode.mess_id)

/*  ReceiveDynamicMessage DataRef parameter  */
#define COMError_ReceiveDynamicMessage_DataRef()   \
    (tpl_com_service.parameters.data_ref)

/*  ReceiveDynamicMessage LengthRef parameter  */
#define COMError_ReceiveDynamicMessage_LengthRef()   \
    (tpl_com_service.parameters.length_ref)

/*  SendZeroMessage Message parameter  */
#define COMError_SendZeroMessage_Message()   \
    (tpl_com_service.parameters.id_or_mode.mess_id)

/*  GetMessageStatus Message parameter  */
#define COMError_GetMessageStatus_Message()   \
    (tpl_com_service.parameters.id_or_mode.mess_id)

#endif
/* of WITH_COM_ERROR_HOOK  */

/*
 * STORE_COM_SERVICE
 */
#if WITH_COM_ERROR_HOOK == YES
#   define STORE_COM_SERVICE(service)   \
    tpl_com_service.service_id = (service);
#else
#   define STORE_COM_SERVICE(service)
#endif

/*
 * STORE_COM_APP_MODE
 */
#if WITH_COM_ERROR_HOOK == YES
#   define STORE_COM_APP_MODE(app_mode)   \
    tpl_com_service.parameters.id_or_mode.app_mode = (app_mode);
#else
#   define STORE_COM_APP_MODE(app_mode)
#endif

/*
 * STORE_COM_MESSAGE_ID
 */
#if WITH_COM_ERROR_HOOK == YES
#   define STORE_COM_MESSAGE_ID(mess_id)   \
    tpl_com_service.parameters.id_or_mode.mess_id = (mess_id);
#else
#   define STORE_COM_MESSAGE_ID(mess_id)
#endif

/*
 * STORE_COM_APPLICATION_DATA_REF
 */
#if WITH_COM_ERROR_HOOK == YES
#   define STORE_COM_APPLICATION_DATA_REF(data_ref1)   \
    tpl_com_service.parameters.data_ref = (tpl_com_data *)(data_ref1);
#else
#   define STORE_COM_APPLICATION_DATA_REF(data_ref1)
#endif

/*
 * STORE_COM_LENGTH_REF
 */
#if WITH_COM_ERROR_HOOK == YES
#   define STORE_COM_LENGTH_REF(length_ref)   \
    tpl_com_service.parameters.length_ref = (length_ref);
#else
#   define STORE_COM_LENGTH_REF(length_ref)
#endif

/*-----------------------------------------------------------------------------
 * PROCESS_COM_ERROR
 * This maccro generates the code to call the error hook, when
 * an error occured, if the WITH_ERROR_HOOK flag is on and no
 * code at all if the flag is off.
 */
#if WITH_COM_ERROR_HOOK == YES
#define PROCESS_COM_ERROR_ERRHOOK(error) tpl_call_com_error_hook(error);
#else
#define PROCESS_COM_ERROR_ERRHOOK(error)
#endif

#if WITH_ORTI == YES
#define PROCESS_COM_ERROR_ORTI(error) \
  {                                   \
    GET_CURRENT_CORE_ID(core_id)      \
    TPL_LAST_ERROR(core_id) = error;  \
  }
#else
#define PROCESS_COM_ERROR_ORTI(error)
#endif

#if (WITH_COM_ERROR_HOOK == YES) || (WITH_ORTI == YES)
#define PROCESS_COM_ERROR(error)        \
  if (error != E_OK) {                  \
      PROCESS_COM_ERROR_ERRHOOK(error)  \
      PROCESS_COM_ERROR_ORTI(error)     \
  }
#else
#define PROCESS_COM_ERROR(error)
#endif

/*-----------------------------------------------------------------------------
 * PROCESS_GETMESSAGESTATUS_ERROR
 * This maccro generates the code to call the error hook, when
 * an error occured in GetMessageStatus, if the WITH_ERROR_HOOK flag is on and no
 * code at all if the flag is off.
 */
#if (WITH_COM_ERROR_HOOK == YES) && (WITH_COM_EXTENDED == YES)
#define PROCESS_GETMESSAGESTATUS_ERROR(error)		\
	if (result == E_COM_ID){						\
			tpl_call_com_error_hook(error);			\
	}
#else
#define PROCESS_GETMESSAGESTATUS_ERROR(error)
#endif

/*-----------------------------------------------------------------------------
 * CHECK_SEND_MESSAGE_ID_ERROR macro definition
 * This macro defines the appropriate error program
 * for out of range mess_id for sending message objects.
 * It is used in sending com services that use mess_id as parameter.
 */

/* No extended error checking (! COM_EXTENDED)  */
#if WITH_COM_EXTENDED == NO
    /* Does not check the mess_id in this case */
#   define CHECK_SEND_MESSAGE_ID_ERROR(mess_id,result)
#else
#   define CHECK_SEND_MESSAGE_ID_ERROR(mess_id,result)      \
    if (result == E_OK && mess_id >= SEND_MESSAGE_COUNT) {  \
        result = E_COM_ID;                                  \
    }
#endif

/*-----------------------------------------------------------------------------
 * CHECK_RECEIVE_MESSAGE_ID_ERROR macro definition
 * This macro defines the appropriate error program
 * for out of range mess_id for receiving message objects.
 * It is used in receiving com services that use mess_id as parameter.
 */

/* No extended error checking (! COM_EXTENDED)  */
#if WITH_COM_EXTENDED == NO
    /* Does not check the mess_id in this case */
#   define CHECK_RECEIVE_MESSAGE_ID_ERROR(mess_id,result)
#else
#   define CHECK_RECEIVE_MESSAGE_ID_ERROR(mess_id,result)       \
    if (result == E_OK && mess_id >= RECEIVE_MESSAGE_COUNT) {   \
        result = E_COM_ID;                                      \
    }
#endif

/*-----------------------------------------------------------------------------
 * CHECK_NOT_ZERO_LENGTH_SEND macro definition
 * This macro defines the appropriate error program
 * for not zero length mess_id for sending message objects.
 */

/* No extended error checking (! COM_EXTENDED)  */
#if WITH_COM_EXTENDED == NO
    /* Does not check the mess_id in this case */
#   define CHECK_NOT_ZERO_LENGTH_SEND(mess_id,result)
#else
#if WITH_EXTERNAL_COM == YES
#   define CHECK_NOT_ZERO_LENGTH_SEND(mess_id,result)   \
    if (result == E_OK &&                               \
        tpl_send_message_table[mess_id]->sender ==      \
            tpl_send_zero_internal_message ||           \
        tpl_send_message_table[mess_id]->sender ==      \
            tpl_send_zero_external_message) {           \
        result = E_COM_ID;                              \
    }
#else
#   define CHECK_NOT_ZERO_LENGTH_SEND(mess_id,result)   \
    if (result == E_OK &&                               \
        tpl_send_message_table[mess_id]->sender ==      \
            tpl_send_zero_internal_message ) {           \
        result = E_COM_ID;                              \
    }
#endif
#endif

/*-----------------------------------------------------------------------------
 * CHECK_ZERO_LENGTH_SEND macro definition
 * This macro defines the appropriate error program
 * for zero length mess_id for sending message objects.
 */

/* No extended error checking (! COM_EXTENDED)  */
#if WITH_COM_EXTENDED == NO
    /* Does not check the mess_id in this case */
#   define CHECK_ZERO_LENGTH_SEND(mess_id,result)
#else
#if WITH_EXTERNAL_COM == YES
#   define CHECK_ZERO_LENGTH_SEND(mess_id,result)       \
    if (result == E_OK &&                               \
        tpl_send_message_table[mess_id]->sender !=      \
            tpl_send_zero_internal_message &&           \
        tpl_send_message_table[mess_id]->sender !=      \
            tpl_send_zero_external_message) {           \
        result = E_COM_ID;                              \
    }
#else
#   define CHECK_ZERO_LENGTH_SEND(mess_id,result)       \
    if (result == E_OK &&                               \
        tpl_send_message_table[mess_id]->sender !=      \
            tpl_send_zero_internal_message) {           \
        result = E_COM_ID;                              \
    }
#endif
#endif

/*	__TPL_COM_ERROR_H__	*/
#endif
