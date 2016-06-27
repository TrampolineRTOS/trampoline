/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline AUTOSAR IOC services implementation
 *
 * $Date$ - $Rev$
 * $Author$
 * $URL$
 */
/* MISRA RULE 3.1 VIOLATION: special character is used in comments for svn integration, the code can survive to this ! */

#include "Std_Types.h"
#include "tpl_ioc_internal_types.h"
#include "tpl_ioc_queue.h"
#include "tpl_os_error.h"
#include "tpl_ioc_kernel.h"
#include "tpl_ioc.h"
#include "tpl_os_kernel.h"
#include "tpl_as_definitions.h"
#include "tpl_as_app_kernel.h"
/*#include "embUnit.h"*/

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
extern void tpl_get_task_lock(void);
extern void tpl_release_task_lock(void);
#if APP_COUNT > 0
extern CONSTP2CONST(tpl_app_access, AUTOMATIC, OS_APPL_CONST)
tpl_app_table[APP_COUNT];
#endif

#if (IOC_QUEUED_COUNT > 0)
/**
 * service for sending an IOC queued message
 *
 * @param ioc_id identifier of the ioc
 * @param ioc_data pointer to the data struct to send
 *
 * @retval IOC_E_OK no error
 * @retval IOC_E_LIMIT queue is full
 *
 */
FUNC(Std_ReturnType, OS_CODE) tpl_ioc_send_queued_service(
  VAR(tpl_ioc_id, AUTOMATIC) ioc_id,
  P2CONST(tpl_ioc_message, AUTOMATIC, OS_VAR) ioc_data
)
{
  P2CONST(tpl_ioc_queued_mo, AUTOMATIC, OS_CONST) ioc_stat;
  P2CONST(tpl_ioc_queue, AUTOMATIC, OS_CONST)     queue_stat;
  VAR(tpl_ioc_buffer, AUTOMATIC)                  data_ptr;
  P2VAR(uint8, AUTOMATIC, AUTOMATIC)			  ioc_data_ptr;
  VAR(tpl_status, AUTOMATIC)                      result = E_OK;
  VAR(Std_ReturnType, AUTOMATIC)                  ioc_result=IOC_E_OK;
  VAR(tpl_ioc_size, AUTOMATIC)                    message;
	
  /*  lock the task system  */
  LOCK_KERNEL()

  /*  store information for error hook routine    */
  STORE_SERVICE(IOCServiceId_IOC_Send)
  STORE_IOC_ID(ioc_id)

  /*  check a ioc_id error   */
  /* MISRA RULE 13.7 VIOLATION: result is always E_OK here,
     but this is a generic macro and it has to be tested */
  CHECK_IOC_ID_ERROR(ioc_id, result)

	/* check access right */
  CHECK_ACCESS_WRITE_IOC_ID(ioc_id, result)
	
#if IOC_COUNT > 0
  IF_NO_EXTENDED_ERROR(result)

    ioc_stat = tpl_ioc_queued_table[ioc_id];

    /* loop on all message to send, which means all parameters
       which can be passed to API call */
    for(message=0; message<ioc_stat->nb_mo; message++)
    {
      /* static decriptor of the current queue for the current message */
      queue_stat = &(ioc_stat->queue[message]);
      /* get the pointer to were to copy the message */
      data_ptr=tpl_ioc_queue_element_for_write(queue_stat);
      if(data_ptr!=NULL)
      {
        /*tpl_memcpy(data_ptr, ioc_data[message].data, queue_stat->element_size);*/
		int size = queue_stat->element_size;
		ioc_data_ptr = ioc_data[message].data;
		while (size > 0) {
			*data_ptr = *ioc_data_ptr;
			data_ptr++;
			ioc_data_ptr++;
			size--;
		}  
      }
      else
      {
        /* if data_ptr is null, it means the queue is full */
        ioc_result = IOC_E_LIMIT;
        queue_stat->dyn_desc->overflow=TRUE;
      }
    }

  IF_NO_EXTENDED_ERROR_END()
#endif

  PROCESS_ERROR(result)

  /*  unlock the task structures  */
  UNLOCK_KERNEL()

  /*
   * in case ioc_result is IOC_E_OK but result is not E_OK,
   * it means we detected an error not handled by IOC error codes
   */
  if((ioc_result==IOC_E_OK) && (result!=E_OK))
  {
    ioc_result = IOC_E_NOT_OK;
  }
  return ioc_result;
}


/**
 * service for receiving an IOC queued message
 *
 * @param ioc_id identifier of the ioc
 * @param ioc_data pointer to the data struct to receive
 *
 * @retval IOC_E_OK no error
 * @retval IOC_E_NO_DATA no data to receive
 * @retval IOC_E_LOST_DATA previous send caused a queue overflow
 *
 */
FUNC(Std_ReturnType, OS_CODE) tpl_ioc_receive_queued_service(
  VAR(tpl_ioc_id, AUTOMATIC) ioc_id,
  P2CONST(tpl_ioc_message, AUTOMATIC, OS_VAR) ioc_data
)
{
  P2CONST(tpl_ioc_queued_mo, AUTOMATIC, OS_CONST) ioc_stat;
  P2CONST(tpl_ioc_queue, AUTOMATIC, OS_CONST)     queue_stat;
  VAR(tpl_ioc_buffer, AUTOMATIC)                  data_ptr;
  P2VAR(uint8, AUTOMATIC, AUTOMATIC)			  ioc_data_ptr;
  VAR(tpl_status, AUTOMATIC)                      result = E_OK;
  VAR(Std_ReturnType, AUTOMATIC)                  ioc_result=IOC_E_OK;
  VAR(tpl_ioc_size, AUTOMATIC)                    message;

  /*  lock the task system  */
  LOCK_KERNEL()

  /*  store information for error hook routine    */
  STORE_SERVICE(IOCServiceId_IOC_Receive)
  STORE_IOC_ID(ioc_id)

  /*  check a ioc_id error   */
  /* MISRA RULE 13.7 VIOLATION: result is always E_OK here,
     but this is a generic macro and it has to be tested */
  CHECK_IOC_ID_ERROR(ioc_id, result)

  /* check access right */
  CHECK_ACCESS_READ_IOC_ID(ioc_id, result)

#if IOC_COUNT > 0
  IF_NO_EXTENDED_ERROR(result)

    ioc_stat = tpl_ioc_queued_table[ioc_id];

    /* loop on all message to receive, which means all parameters
       which can be passed to API call */
    for(message=0; message<ioc_stat->nb_mo; message++)
    {
      /* static decriptor of the current queue for the current message */
      queue_stat = &(ioc_stat->queue[message]);
      /* get the pointer to were to copy the message from */
      data_ptr=tpl_ioc_queue_element_for_read(queue_stat);

	if(data_ptr!=NULL)
      {
        /*tpl_memcpy(ioc_data[message].data, data_ptr, queue_stat->element_size);*/
		int size = queue_stat->element_size;
		ioc_data_ptr = ioc_data[message].data;
		while (size > 0) {
		  *ioc_data_ptr = *data_ptr;
		  ioc_data_ptr++;
		  data_ptr++;
		  size--;
		}  
		  
      }
      else
      {
        /* if data_ptr is null, it means the queue is empty,
           there is nothing to receive */
        ioc_result = IOC_E_NO_DATA;

      }

      /* if an overflow has beed detected during send,
         it is notified here to the receiver */
      if(queue_stat->dyn_desc->overflow==TRUE)
      {
        ioc_result = IOC_E_LOST_DATA;
        queue_stat->dyn_desc->overflow=FALSE;
      }
    }

  IF_NO_EXTENDED_ERROR_END()
#endif

  PROCESS_ERROR(result)

  /*  unlock the task structures  */
  UNLOCK_KERNEL()

  /*
   * in case ioc_result is IOC_E_OK but result is not E_OK,
   * it means we detected an error not handled by IOC error codes
   */
  if((ioc_result==IOC_E_OK) && (result!=E_OK))
  {
    ioc_result = IOC_E_NOT_OK;
  }
  return ioc_result;
}


/**
 * service for emptying an IOC queue
 *
 * @param ioc_id identifier of the ioc
 *
 * @retval IOC_E_OK no error
 *
 */
FUNC(StatusType, OS_CODE) tpl_ioc_empty_queue_service(
  VAR(tpl_ioc_id, AUTOMATIC) ioc_id
)
{
  P2CONST(tpl_ioc_queued_mo, AUTOMATIC, OS_CONST) ioc_stat;
  P2CONST(tpl_ioc_queue, AUTOMATIC, OS_CONST)     queue_stat;
  VAR(tpl_status, AUTOMATIC)                      result = E_OK;
  VAR(Std_ReturnType, AUTOMATIC)                  ioc_result=IOC_E_OK;
  VAR(tpl_ioc_size, AUTOMATIC)                    message;


  /*  lock the task system  */
  LOCK_KERNEL()

  /*  store information for error hook routine    */
  STORE_SERVICE(IOCServiceId_IOC_EmptyQueue)
  STORE_IOC_ID(ioc_id)

  /*  check a ioc_id error   */
  /* MISRA RULE 13.7 VIOLATION: result is always E_OK here,
     but this is a generic macro and it has to be tested */
  CHECK_IOC_ID_ERROR(ioc_id, result)

  /* check access right */
  CHECK_ACCESS_WRITE_IOC_ID(ioc_id, result)


#if IOC_COUNT > 0
  IF_NO_EXTENDED_ERROR(result)

    ioc_stat = tpl_ioc_queued_table[ioc_id];

    /* loop on all message to clear */
    for(message=0; message<ioc_stat->nb_mo; message++)
    {
      queue_stat = &(ioc_stat->queue[message]);
      queue_stat->dyn_desc->size=0;
      queue_stat->dyn_desc->overflow = FALSE;

    }

  IF_NO_EXTENDED_ERROR_END()
#endif

  PROCESS_ERROR(result)

  /*  unlock the task structures  */
  UNLOCK_KERNEL()

  /*
   * in case ioc_result is IOC_E_OK but result is not E_OK,
   * it means we detected an error not handled by IOC error codes
   */
  if(result!=E_OK)
  {
    ioc_result = IOC_E_NOT_OK;
  }
  return ioc_result;
}

#endif


#if (IOC_UNQUEUED_COUNT > 0)
/**
 * service for sending an IOC unqueued message
 *
 * @param ioc_id identifier of the ioc
 * @param ioc_data pointer to the data struct to send
 *
 * @retval IOC_E_OK no error
 *
 */
FUNC(Std_ReturnType, OS_CODE) tpl_ioc_send_unqueued_service(
  VAR(tpl_ioc_id, AUTOMATIC) ioc_id,
  P2CONST(tpl_ioc_message, AUTOMATIC, OS_VAR) ioc_data
)
{
  P2CONST(tpl_ioc_unqueued_mo, AUTOMATIC, OS_CONST) ioc_stat;
  VAR(tpl_ioc_buffer, AUTOMATIC)                    data_ptr;
  P2VAR(uint8, AUTOMATIC, AUTOMATIC)			  ioc_data_ptr;
  VAR(tpl_status, AUTOMATIC)                        result = E_OK;
  VAR(Std_ReturnType, AUTOMATIC)                    ioc_result=IOC_E_OK;
  VAR(tpl_ioc_size, AUTOMATIC)                      message;

  /*  lock the task system  */
  LOCK_KERNEL()

  /*  store information for error hook routine    */
  STORE_SERVICE(IOCServiceId_IOC_Write)
  STORE_IOC_ID(ioc_id)

  /*  check a ioc_id error   */
  /* MISRA RULE 13.7 VIOLATION: result is always E_OK here,
     but this is a generic macro and it has to be tested */
  CHECK_IOC_ID_ERROR(ioc_id, result)

  /* check access right */
  CHECK_ACCESS_WRITE_IOC_ID(ioc_id, result)


#if IOC_COUNT > 0
  IF_NO_EXTENDED_ERROR(result)

    ioc_stat = tpl_ioc_unqueued_table[ioc_id-IOC_QUEUED_COUNT];

    /* loop on all message to send, which means all parameters
       which can be passed to API call */
    for(message=0; message<ioc_stat->nb_mo; message++)
    {
      data_ptr=ioc_stat->buffer[message];

      /*tpl_memcpy(data_ptr, ioc_data[message].data, ioc_stat->element_size[message]);*/
	  int size = ioc_stat->element_size[message];
	  ioc_data_ptr = ioc_data[message].data;
	  while (size > 0) {
		*data_ptr = *ioc_data_ptr;
		data_ptr++;
		ioc_data_ptr++;
		size--;
	  }  
		
    }

  IF_NO_EXTENDED_ERROR_END()
#endif

  PROCESS_ERROR(result)

  /*  unlock the task structures  */
  UNLOCK_KERNEL()

  /*
   * in case ioc_result is IOC_E_OK but result is not E_OK,
   * it means we detected an error not handled by IOC error codes
   */
  if((ioc_result==IOC_E_OK) && (result!=E_OK))
  {
    ioc_result = IOC_E_NOT_OK;
  }
  return ioc_result;
}


/**
 * service for  receiving an IOC unqueued message
 *
 * @param ioc_id identifier of the ioc
 * @param ioc_data pointer to the data struct to receive
 *
 * @retval IOC_E_OK no error
 *
 */
FUNC(StatusType, OS_CODE) tpl_ioc_receive_unqueued_service(
  VAR(tpl_ioc_id, AUTOMATIC) ioc_id,
  P2CONST(tpl_ioc_message, AUTOMATIC, OS_VAR) ioc_data
)
{
  P2CONST(tpl_ioc_unqueued_mo, AUTOMATIC, OS_CONST) ioc_stat;
  VAR(tpl_ioc_buffer, AUTOMATIC)                    data_ptr;
  P2VAR(uint8, AUTOMATIC, AUTOMATIC)			  ioc_data_ptr;
  VAR(tpl_status, AUTOMATIC)                        result = E_OK;
  VAR(Std_ReturnType, AUTOMATIC)                    ioc_result=IOC_E_OK;
  VAR(tpl_ioc_size, AUTOMATIC)                      message;


  /*  lock the task system  */
  LOCK_KERNEL()

  /*  store information for error hook routine    */
  STORE_SERVICE(IOCServiceId_IOC_Receive)
  STORE_IOC_ID(ioc_id)

  /*  check a ioc_id error   */
  /* MISRA RULE 13.7 VIOLATION: result is always E_OK here,
     but this is a generic macro and it has to be tested */
  CHECK_IOC_ID_ERROR(ioc_id, result)

  /* check access right */
  CHECK_ACCESS_READ_IOC_ID(ioc_id, result)

#if IOC_COUNT > 0
  IF_NO_EXTENDED_ERROR(result)

    ioc_stat = tpl_ioc_unqueued_table[ioc_id-IOC_QUEUED_COUNT];

    /* loop on all message to receive, which means all parameters
       which can be passed to API call */
    for(message=0; message<ioc_stat->nb_mo; message++)
    {
      data_ptr = ioc_stat->buffer[message];

      /*tpl_memcpy(ioc_data[message].data, data_ptr, ioc_stat->element_size[message]);*/
	  int size = ioc_stat->element_size[message];
	  ioc_data_ptr = ioc_data[message].data;
	  while (size > 0) {
		*ioc_data_ptr = *data_ptr;
		ioc_data_ptr++;
		data_ptr++;
		size--;
	  }  
		
    }

  IF_NO_EXTENDED_ERROR_END()
#endif

  PROCESS_ERROR(result)

  /*  unlock the task structures  */
  UNLOCK_KERNEL()

  /*
   * in case ioc_result is IOC_E_OK but result is not E_OK,
   * it means we detected an error not handled by IOC error codes
   */
  if((ioc_result==IOC_E_OK) && (result!=E_OK))
  {
    ioc_result = IOC_E_NOT_OK;
  }
  return ioc_result;
}

/**
 * function for init of IOC unqueued buffers
 *
 *
 */
FUNC(void, OS_CODE) tpl_ioc_init_unqueued(void)
{
  P2CONST(tpl_ioc_unqueued_mo, AUTOMATIC, OS_CONST) ioc_stat;
  VAR(tpl_ioc_buffer, AUTOMATIC)                    data_src;
  VAR(tpl_ioc_buffer, AUTOMATIC)                    data_dst;
  VAR(uint32, AUTOMATIC)                            ioc_index;
  VAR(tpl_ioc_size, AUTOMATIC)                      message;

  /* loop on all unqueued configured IOCs */
  for(ioc_index=0; ioc_index<IOC_UNQUEUED_COUNT; ioc_index++)
  {
    ioc_stat=tpl_ioc_unqueued_table[ioc_index];

    /* loop on all messages for one IOC */
    for(message=0; message<ioc_stat->nb_mo; message++)
    {
      /* get the init pointer to copy from */
      data_src = ioc_stat->init_buffer[message];

      /* if the ptr is not null, it means there is an init data to copy */
      if(data_src!=NULL_PTR)
      {
        data_dst = ioc_stat->buffer[message];

        /* tpl_memcpy(data_dst, data_src, ioc_stat->element_size[message]); */
		  
		int size = ioc_stat->element_size[message];
		while (size > 0) {
		  *data_dst = *data_src;
		  data_dst++;
		  data_src++;
		  size--;
		}  
		  
      }
    }
  }
}

#endif


#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"
