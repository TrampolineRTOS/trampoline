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
 
/*
 * tpl_send_static_internal_message sends a message from an internal only
 * sending message object to a set of internal receiving message object.
 * this function is attached to the sending message object.
 */ 
void tpl_send_static_internal_message(tpl_base_sending_mo *smo, tpl_application_data *data)
{
    /*  cast the base mo to the correct type of mo                          */
    tpl_internal_sending_mo *ismo = (tpl_internal_sending_mo *)smo;
    /*  get the first of the receiving mo                                   */
    tpl_base_receiving_mo *rmo = ismo->internal_target;
    /*  iterate through the receiving mo to copy the data to the receivers  */
    while (rmo != NULL) {
        rmo->receiver(rmo, data);
        rmo = rmo->next_mo;
    }
}

/*
 * tpl_send_static_external_message sends a message from an external only
 * sending message object to an IPDU.
 * This function is attached to the sending message object.
 */
void tpl_send_static_external_message(tpl_base_sending_mo *smo, tpl_application_data *data)
{
    /*  filter the message                                                      */
    if (tpl_filtering(smo, data)) {
        /*  cast the base mo to the correct typo of mo                          */
        tpl_external_sending_mo *esmo = (tpl_etpl_external_sending_mo *)smo;
        /*  get the target ipdu                                                 */
        tpl_sending_ipdu *ipdu = esmo->external_target;
    }
}

StatusType SendMessage(MessageIdentifier mess_id, ApplicationDataRef data)
{
    /*  init the error to no error  */
    StatusType result = E_OK;
    tpl_base_sending_mo *smo;
    

    /*  lock the task structures    */
    LOCK_WHEN_TASK()
    
    /*  store information for error hook routine    */
    STORE_SERVICE(COMServiceId_SendMessage)
    STORE_MESSAGE_ID(mess_id)
    STORE_DATA_REF(data)

    CHECK_MESSAGE_ID_ERROR(mess_id,result)
    CHECK_NOT_ZERO_LENGTH(mess_id,result);
    
#ifndef NO_MESSAGE
    IF_NO_EXTENDED_ERROR(result)
    /*  get the message object from its id  */
    smo = tpl_send_message_table[mess_id];
    /*  call the sending function           */
    smo->sender(smo, data);
    END_IF_NO_EXTENDED_ERROR()
#endif

    PROCESS_COM_ERROR(result)

    UNLOCK_WHEN_TASK()
    
    return result;
}

StatusType ReceiveMessage(MessageIdentifier mess_id, ApplicationDataRef data)
{
    tpl_receive_mo    *rmo;

#ifdef COM_EXTENDED
    if (mess_id > RECEIVE_MESSAGE_COUNT) {
        return tpl_last_result = E_COM_ID;
    }
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

    return tpl_last_result = rmo->receive_function(rmo, data);

}

StatusType SendZeroMessage(MessageIdentifier mess_id)
{
    
}