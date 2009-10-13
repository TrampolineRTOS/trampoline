#ifndef __TPL_CAN_DRIVER_H
#define __TPL_CAN_DRIVER_H

#include "../com/tpl_com_ipdu.h"
#include "registers.h"
#include "viper.h"

/*====================
 *  constantes
 *====================*/

/**
 *  number of elements in the filter
 */
#define FILTER_LENGTH    8

/**
 *  number of registers needed to contain
 *  one filter
 *
 *  TODO bad : need to depend on filter_t size
 */
#define FILTER_REG_NUMBER 16

/**
 *  number of registers needed to contain
 *  one frame
 *
 *  TODO bad : need to depend on frame_t size
 */
#define FRAME_REG_NUMBER  6

/**
 *  frame identifiers
 */
enum {  IDENTIFIER_1,
        IDENTIFIER_2,
        IDENTIFIER_3  };

/**
 *  variables for boolean tests
 */
#ifndef TRUE
#define TRUE    (1)
#endif
#ifndef FALSE
#define FALSE   (0)
#endif

/**
 *  registers (cast a frame before sending it)
 *
 */
typedef struct {
    reg_t reg[FRAME_REG_NUMBER];
}frame_to_reg;

/*====================
 *  types
 *====================*/

/**
 *  type of frame
 *
 *  0 : data frame
 *  1 : remote frame
 */
typedef char rtr_t;  /* 1 byte */

/**
 *  length of frame
 *
 *  0..8
 */
typedef char dlc_t;  /* 1 byte */

/**
 *  format of frame
 *
 *  0 : standard frame
 *  1 : extend frame
 */
typedef char ide_t;  /* 1 byte */

/**
 *  identifier type
 *
 *  standard frame  : just used std_id
 *  extend frame    : used  std_id and ext_id
 */
typedef struct {
  int std_id; /* 4 bytes */
  int ext_id; /* 4 bytes */
}
identifier_t;

/**
 *  filter type
 *
 *  array of identifiers
 */
typedef identifier_t filter_t[FILTER_LENGTH]; /* 64 bytes */

/**
 *  data type
 */
typedef struct {
  int byte_1;
  int byte_2;
}
data_t;

/**
 *  arbitration type
 */
typedef  struct {
  identifier_t  identifier;
  rtr_t         rtr;
  ide_t         ide;
}
arbitration_t;

/**
 *  frame type
 */
typedef struct {
  arbitration_t arbitration;
  dlc_t         dlc;
  data_t        data;
}
frame_t;

/**
 *  union used for conversion
 *  
 *  frame to register
 *  register to frame
 */
typedef union {
  reg_t   reg[FRAME_REG_NUMBER];
  frame_t frame;
}
frame_conversion_union_t;

/**
 *  union used for conversion
 *
 *  filter to register
 *  register to filter
 */
typedef union {
  reg_t     reg[FILTER_REG_NUMBER];
  filter_t  filter;
}
filter_conversion_union_t;

/**
 *  union used for conversion
 *
 *  data to ipdu
 *  ipdu to data
 */
typedef union {
  data_t              data;
  tpl_sending_ipdu    s_ipdu;
}
s_ipdu_conversion_union_t;

/**
 *  union used for conversion
 *
 *  data to ipdu
 *  ipdu to data
 */
typedef union {
  data_t              data;
  tpl_receiving_ipdu  r_ipdu;
}
r_ipdu_conversion_union_t;

/*====================
 *  prototypes
 *====================*/

/**
 *  send an ipdu
 *  
 *  @param  ipc   structure used for communication
 *  @param  can_device CAN device's mask
 *  @param  ipdu  ipdu to send
 */
void send_ipdu(ipc_t* ipc, dev_id_t can_device, tpl_sending_ipdu* ipdu);

/**
 *  receive an ipdu
 *  
 *  @param  ipc   structure used for communication
 *  @param  can_device CAN device's mask
 *  @param  ipdu  ipdu wich will take the receive ipdu value
 */
void receive_ipdu(ipc_t* ipc, dev_id_t can_device, tpl_receiving_ipdu* ipdu);

/**
 *  say if an identifier is standard
 *  
 *  @param  identifier  identifier to test
 *  @return             TRUE if the identifier is standard, else FALSE
 */
int is_standard_identifier(identifier_t* identifier);

/**
 *  say if an identifier is already in a filter
 *
 *  @param  filter      filter to test
 *  @param  identifier  identifier to search
 *  @return             TRUE if the identifier exists, else FALSE
 */
int is_existed_identifier(filter_t filter, identifier_t* identifier);

/**
 *  say if a filter is empty
 *
 *  @param  filter  filter to test
 *  @return         TRUE if the filter is empty, else FALSE
 */
int is_empty_filter(filter_t filter);

/**
 *  say if a filter is full
 *
 *  @param  filter  filter to test
 *  @return         TRUE if the filter is full, else FALSE
 */
int is_full_filter(filter_t filter);

/**
 *  initialize a filter
 *  
 *  @param  filter  filter to initialize
 */
void init_filter(filter_t filter);

/**
 *  add an identifier to a filter
 *  
 *  @param  filter      filter where add an identifier
 *  @param  identifier  identifier to add
 */
void add_identifier_to_filter(filter_t filter, identifier_t* identifier);

/**
 *  remove an identifier to a filter
 *  
 *  @param  filter      filter where remove an identifier
 *  @param  identifier  identifier to remove
 */
void remove_identifier_to_filter(filter_t filter, identifier_t* identifier);

/**
 *  update the filter registers
 *  
 *  @param  ipc     structure used for communication
 *  @param  can_device CAN device's mask
 *  @param  filter  filter to write in registers
 */
void update_filter(ipc_t* ipc, dev_id_t can_device, filter_t filtre);

/**
 *  read the filter registers
 *
 *  @param  ipc     structure used for communication
 *  @param  filter  filter wich will take the read filter
 */
void read_filter(ipc_t* ipc, filter_t filter);

/**
 *  test if a frame is acceptable
 *  
 *  @param  frame   frame to test
 *  @param  filter  filter to used to test the acceptance
 *  @return         TRUE if the frame is acceptable, else FALSE
 */
int frame_acceptance(frame_t* frame, filter_t filter);

#endif

