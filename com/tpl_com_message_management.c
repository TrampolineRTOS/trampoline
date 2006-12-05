/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline est protégé par la loi sur la propriété intellectuelle
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline Message Object implementation
 *
 * $Date$ - $Rev$
 * $Author$
 * $URL$
 */

#include "tpl_os.h"
#include "tpl_com.h"
#include "tpl_os_error.h"
#include "tpl_com_error.h"
#include "tpl_com_kernel.h"

StatusType SendMessage(MessageIdentifier mess_id, ApplicationDataRef data)
{
    /*  init the error to no error                  */
    StatusType result = E_OK;
    tpl_base_sending_mo *smo;
    

    /*  lock the task structures                    */
    LOCK_WHEN_TASK()
    
    /*  store information for error hook routine    */
    STORE_COM_SERVICE(COMServiceId_SendMessage)
    STORE_COM_MESSAGE_ID(mess_id)
    STORE_COM_APPLICATION_DATA_REF(data)

    /*  Check the error                             */
    CHECK_SEND_MESSAGE_ID_ERROR(mess_id,result)
    CHECK_NOT_ZERO_LENGTH(mess_id,result);
    
#ifndef NO_SEND_MESSAGE
    IF_NO_EXTENDED_ERROR(result)
    /*  get the message object from its id          */
    smo = (tpl_base_sending_mo *)tpl_send_message_table[mess_id];
    /*  call the sending function                   */
    smo->sender(smo, data);
    END_IF_NO_EXTENDED_ERROR()
#endif

    PROCESS_COM_ERROR(result)

    UNLOCK_WHEN_TASK()
    
    return result;
}

StatusType ReceiveMessage(MessageIdentifier mess_id, ApplicationDataRef data)
{
    /*  init the error to no error                  */
    StatusType result = E_OK;
    tpl_base_receiving_mo	*rmo;

    /*  lock the task structures                    */
    LOCK_WHEN_TASK()
    
    STORE_COM_SERVICE(COMServiceId_ReceiveMessage)
    STORE_COM_MESSAGE_ID(mess_id)
    STORE_COM_APPLICATION_DATA_REF(data)

    /*  Check the error                             */
    CHECK_RECEIVE_MESSAGE_ID_ERROR(mess_id,result)
    
    if ((tpl_send_message_table[mess_id]->type != RECEIVE_UNQUEUED_INTERNAL) &&
        (tpl_send_message_table[mess_id]->type != RECEIVE_QUEUED_INTERNAL)
#ifdef WITH_EXTERNAL_COM
        && (tpl_send_message_table[mess_id]->type != RECEIVE_UNQUEUED_EXTERNAL)
        && (tpl_send_message_table[mess_id]->type != RECEIVE_QUEUED_EXTERNAL)
#endif
        ) {
        return tpl_last_result = E_COM_ID;
    }
#endif

    return tpl_last_result = rmo->receiver(rmo, data);

}

StatusType SendZeroMessage(MessageIdentifier mess_id)
{
    /*  init the error to no error                  */
    StatusType result = E_OK;
    tpl_base_sending_mo *smo;
    

    /*  lock the task structures                    */
    LOCK_WHEN_TASK()
    
    /*  store information for error hook routine    */
    STORE_COM_SERVICE(COMServiceId_SendZeroMessage)
    STORE_COM_MESSAGE_ID(mess_id)

    /*  Check the error                             */
    CHECK_SEND_MESSAGE_ID_ERROR(mess_id,result)
    CHECK_ZERO_LENGTH(mess_id,result)
    
#ifndef NO_SEND_MESSAGE
    IF_NO_EXTENDED_ERROR(result)
    /*  get the message object from its id          */
    smo = (tpl_base_sending_mo *)tpl_send_message_table[mess_id];
    /*  call the sending function                   */
    smo->sender(smo, NULL);
    END_IF_NO_EXTENDED_ERROR()
#endif

    PROCESS_COM_ERROR(result)

    UNLOCK_WHEN_TASK()
    
    return result;
}