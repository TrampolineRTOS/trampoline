#ifndef __TPL_COM_IPDU_H__
#define __TPL_COM_IPDU_H__

#include "viper.h"

/*====================
 *  constantes
 *====================*/

/**
 *  definition of transmission modes
 */
#define DIRECT_TRANSMISSION   0x1 /* 01 */
#define PERIODIC_TRANSMISSION 0x2 /* 10 */
#define MIXED_TRANSMISSION    0x3 /* 11 */

/*====================
 *  types
 *====================*/

/**
 *  TODO not here, just for test
 *
 *  size : 1 byte
 */
/* typedef unsigned char u8; // in machines/XXXX/tpl_os_std_types.h */
 
/**
 *  TODO not here, just for test
 */
typedef struct {
  unsigned char    data[4];
  char  byte_start; /* 0..7 */
  char  bit_start;  /* 0..7 */
  char  byte_end;   /* 0..7 */
  char  bit_end;    /* 0..7 */
}
tpl_sending_mo;

/**
 *  TODO not here, just for test
 */
typedef struct {
  tpl_sending_mo mo;
  char  id;
}
tpl_receiving_mo;

/**
 *  ipdu structure
 */
typedef struct {
  unsigned char    *buf;
  char  nb_message;
  char  transmission_mode;
  char  id;
}
tpl_sending_ipdu;

/**
 *  ipdu structure
 */
typedef tpl_sending_ipdu tpl_receiving_ipdu;

/*====================
 *  prototypes
 *====================*/

/**
 *  put a message object in an ipdu
 *
 *  @param  mo    message object to put in an ipdu
 *  @param  ipdu  ipdu where put a message object
 *  @return       modified ipdu
 */
void tpl_put_message_object_in_ipdu(tpl_sending_ipdu *ipdu, tpl_sending_mo *mo);

/**
 *  get a message object from an ipdu
 *  
 *  @param  ipdu  ipdu to extract the message object
 *  @param  mo    extract message object
 *  @return       extract message object
 */
void tpl_get_message_object_from_ipdu(tpl_receiving_ipdu *ipdu, tpl_receiving_mo *mo);

/**
 *  send an ipdu
 *
 *  @param  ipdu  ipdu to send
 */
void tpl_send_ipdu(ipc_t *ipc, tpl_sending_ipdu *ipdu);

/**
 *  recive an ipdu
 *
 *  @param  ipdu  ipdu target
 *  @return       receive ipdu  
 */
void tpl_receive_ipdu(ipc_t *ipc, tpl_receiving_ipdu *ipdu);

#endif

