/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline is protected by the French intellectual property law.
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
#include "tpl_machine.h"
#include "tpl_com_error.h"
#include "tpl_com_base_mo.h"
#include "tpl_com_app_def.h"

void tpl_get_task_lock(void);
void tpl_release_task_lock(void);

StatusType SendMessage(MessageIdentifier mess_id, ApplicationDataRef data)
{
    /*  init the error to no error                  */
    StatusType result = E_OK;

#ifndef NO_SEND_MESSAGE
    tpl_base_sending_mo *smo = NULL;
#endif
    

    /*  lock the task structures                    */
    LOCK_WHEN_TASK()
    
    /*  store information for error hook routine    */
    STORE_COM_SERVICE(COMServiceId_SendMessage)
    STORE_COM_MESSAGE_ID(mess_id)
    STORE_COM_APPLICATION_DATA_REF(data)

    /*  Check the error                             */
    CHECK_SEND_MESSAGE_ID_ERROR(mess_id,result)
    CHECK_NOT_ZERO_LENGTH_SEND(mess_id,result);
    
#ifndef NO_SEND_MESSAGE
    IF_NO_EXTENDED_ERROR(result)
    /*  get the message object from its id          */
    smo = (tpl_base_sending_mo *)tpl_send_message_table[mess_id];
    /*  call the sending function                   */
    smo->sender(smo, data);
    IF_NO_EXTENDED_ERROR_END()
#endif

    PROCESS_COM_ERROR(result)

    UNLOCK_WHEN_TASK()
    
    return result;
}

StatusType ReceiveMessage(MessageIdentifier mess_id, ApplicationDataRef data)
{
    /*  init the error to no error                  */
    StatusType result = E_OK;

#ifndef NO_RECEIVE_MESSAGE
    tpl_data_receiving_mo	*rmo = NULL;
#endif

    /*  lock the task structures                    */
    LOCK_WHEN_TASK()
    
    STORE_COM_SERVICE(COMServiceId_ReceiveMessage)
    STORE_COM_MESSAGE_ID(mess_id)
    STORE_COM_APPLICATION_DATA_REF(data)

    /*  Check the error                             */
    CHECK_RECEIVE_MESSAGE_ID_ERROR(mess_id,result)

#ifndef NO_RECEIVE_MESSAGE
    IF_NO_EXTENDED_ERROR(result)
    /*  get the message object from its id          */
    rmo = (tpl_data_receiving_mo *)tpl_receive_message_table[mess_id];
    /*  call the sending function                   */
    rmo->copier(data, rmo);
    IF_NO_EXTENDED_ERROR_END()
#endif

    PROCESS_COM_ERROR(result)

    UNLOCK_WHEN_TASK()
    
    return result;
}

StatusType SendZeroMessage(MessageIdentifier mess_id)
{
    /*  init the error to no error                  */
    StatusType result = E_OK;

#ifndef NO_SEND_MESSAGE
    tpl_base_sending_mo *smo = NULL;
#endif

    /*  lock the task structures                    */
    LOCK_WHEN_TASK()
    
    /*  store information for error hook routine    */
    STORE_COM_SERVICE(COMServiceId_SendZeroMessage)
    STORE_COM_MESSAGE_ID(mess_id)

    /*  Check the error                             */
    CHECK_SEND_MESSAGE_ID_ERROR(mess_id,result)
    CHECK_ZERO_LENGTH_SEND(mess_id,result)
    
#ifndef NO_SEND_MESSAGE
    IF_NO_EXTENDED_ERROR(result)
    /*  get the message object from its id          */
    smo = (tpl_base_sending_mo *)tpl_send_message_table[mess_id];
    /*  call the sending function                   */
    smo->sender(smo, NULL);
    IF_NO_EXTENDED_ERROR_END()
#endif

    PROCESS_COM_ERROR(result)

    UNLOCK_WHEN_TASK()
    
    return result;
}
