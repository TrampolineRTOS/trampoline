#include <stdlib.h>
#include <stdio.h>

#include "tpl_can_driver.h"

/* send frame registers */
reg_id_t send_frame_reg_ids[] = { SEND_FRAME_REG_1,
                                  SEND_FRAME_REG_2,
                                  SEND_FRAME_REG_3,
                                  SEND_FRAME_REG_4,
                                  SEND_FRAME_REG_5,
                                  SEND_FRAME_REG_6 };

/* receive frame registers */
reg_id_t receive_frame_reg_ids[] = {  RECEIVE_FRAME_REG_1,
                                      RECEIVE_FRAME_REG_2,
                                      RECEIVE_FRAME_REG_3,
                                      RECEIVE_FRAME_REG_4,
                                      RECEIVE_FRAME_REG_5,
                                      RECEIVE_FRAME_REG_6 };

/* filter registers */
reg_id_t filter_reg_ids[] = { FILTER_REG_1,
                              FILTER_REG_2,
                              FILTER_REG_3,
                              FILTER_REG_4,
                              FILTER_REG_5,
                              FILTER_REG_6,
                              FILTER_REG_7,
                              FILTER_REG_8,
                              FILTER_REG_9,
                              FILTER_REG_10,
                              FILTER_REG_11,
                              FILTER_REG_12,
                              FILTER_REG_13,
                              FILTER_REG_14,
                              FILTER_REG_15,
                              FILTER_REG_16  };

/*====================
 *  transfert
 *====================*/

/**
 *  send an ipdu
 *
 *  @param  ipc   structure used for communication
 *  @param  ipdu  ipdu to send
 */
void send_ipdu(ipc_t* ipc, dev_id_t can_device, tpl_sending_ipdu* ipdu)
{
  /* variables */
  frame_t frame;
  frame_to_reg frame_reg;
  reg_id_t mask = 0;
  int i;
  
  /* prepare the frame */
  frame.arbitration.identifier.std_id = (int) ipdu->id;         /* the frame identifier is the ipdu identifier  */
  frame.arbitration.identifier.ext_id = -1;                     /* no extend identifier for ipdu sending        */
  frame.arbitration.rtr               = (char) 0;               /* 0 : data frame                               */
  frame.arbitration.ide               = (char) 0;               /* 0 : standard frame                           */
  frame.dlc                           = (char) ipdu->nb_message;  /* data length                                  */
  
  /* Make registers from frame */
  frame_reg.reg[0] = frame.arbitration.identifier.std_id;  
  frame_reg.reg[1] = frame.arbitration.identifier.ext_id;  
  frame_reg.reg[2] = frame.arbitration.rtr;  
    
  unsigned char * ptr_ide;

//printf("&frame_reg.reg[2] : %d\n",(int)sizeof(&frame_reg.reg[2]));
  ptr_ide = (void *)&frame_reg.reg[2];
  ptr_ide += (int)(sizeof(char));
  *ptr_ide = frame.arbitration.ide;
  
  frame_reg.reg[3] = frame.dlc;  
  
  for(i = 0; i < (ipdu->nb_message) ; i ++)
  {
      ptr_ide = (void *)&frame_reg.reg[4];
      ptr_ide += i*(int)sizeof(char);
      *ptr_ide = ipdu->buf[i];
  }
     
  /* write registers */
  for(i = 0; i < FRAME_REG_NUMBER; i++) {
    vp_ipc_write_reg(ipc, can_device | send_frame_reg_ids[i], frame_reg.reg[i]);
  }

  /* create mask */
  for(i = 0; i < (sizeof(send_frame_reg_ids) / sizeof(reg_id_t)); i++) {
    mask |= send_frame_reg_ids[i];
  }
  mask |= can_device;
  
  /* signal update */
  vp_ipc_signal_update(ipc, can_device, mask);
}

/**
 *  receive an ipdu
 *
 *  @param  ipc   structure used for communication
 *  @param  ipdu  ipdu witch will take the receive ipdu value
 */
void receive_ipdu(ipc_t* ipc, dev_id_t can_device, tpl_receiving_ipdu* ipdu)
{
  /* variables */
  frame_to_reg frame_reg;
  frame_t frame;
  int i;
  
  /* read registers */
  for(i = 0; i < FRAME_REG_NUMBER; i++) {
    frame_reg.reg[i] = vp_ipc_read_reg(ipc, can_device | receive_frame_reg_ids[i]);
  }
    
  /* Make fram from registers */
  frame.arbitration.identifier.std_id = frame_reg.reg[0];  
  frame.arbitration.identifier.ext_id = frame_reg.reg[1];  
  frame.arbitration.rtr = frame_reg.reg[2];  
    
  unsigned char * ptr_ide;
  ptr_ide = (void *)&frame_reg.reg[2];
  ptr_ide += (int)sizeof(char);
  frame.arbitration.ide = *ptr_ide;
    
  frame.dlc = frame_reg.reg[3];  
    
  /* Make ipdu */
  ipdu->nb_message =  frame.dlc;
  ipdu->id = frame.arbitration.identifier.std_id;    
  
  /* if the frame is a data frame */
  if(frame.arbitration.rtr == (char) 0) {
    /* Make ipdu from registers */
    for(i = 0; i < (ipdu->nb_message) ; i ++)
    {
        ptr_ide = (void *)&frame_reg.reg[4];
        ptr_ide += i*(int)sizeof(char);
        ipdu->buf[i] = *ptr_ide;
    }
  }
  /* else the ipdu is null */
  else {
    if(frame.arbitration.rtr == (char) 1) {
      ipdu = NULL;
    }
    else {
      fprintf(stderr, "[%d] %s \n", __LINE__, __FILE__);
      perror("receive_ipdu() : bad parameter rtr of received frame");
    }
  }
}

/*====================
 *  acceptance
 *====================*/

/**
 *  say if an identifier is standard
 *
 *  @param  identifier  identifier to test
 *  @return             TRUE if the identifier is standard, else FALSE
 */
int is_standard_identifier(identifier_t* identifier)
{
  /* variable */
  int result = FALSE;

  /* test if the identifier isn't extend */
  if(identifier->ext_id == -1) {
    result = TRUE;
  }
  
  return result;
}

/**
 *  say if an identifier is already in a filter
 *
 *  @param  filter      filter to test
 *  @param  identifier  identifier to search
 *  @return             TRUE if the identifier exists, else FALSE
 */
int is_existed_identifier(filter_t filter, identifier_t* identifier)
{
  /* variable */
  int result = FALSE;
  int i;

  /* if the identifier is standard */
  if(is_standard_identifier(identifier) == TRUE) {
    /* browse filter to search the identifier */
    for(  i = 0;
          i < FILTER_LENGTH &&
          result == FALSE;
          i++               ) {
      /*  if current identifier in the filter is standard
          and equals to the identifier to test            */
      if( is_standard_identifier(&filter[i]) == TRUE  &&
          filter[i].std_id == identifier->std_id      ) {
        /* the identifier exists */
        result = TRUE;
      }
    }
  }
  /* if the identifier is extend */
  else {
    /* browse filter to search the identifier */
    for(  i = 0;
          i < FILTER_LENGTH &&
          result == FALSE;
          i++               ) {
      /*  if current identifier int the filter is extend
          and equals to the identifier to test            */
      if( is_standard_identifier(&filter[i]) == FALSE &&
          filter[i].std_id == identifier->std_id      &&
          filter[i].ext_id == identifier->ext_id      ) {
        /* the identifier exists */
        result = TRUE;
      }
    }
  }

  return result;  
}

/**
 *  say if a filter is empty
 *
 *  @param  filter  filter to test
 *  @return         TRUE if the filter is empty, else FALSE
 */
int is_empty_filter(filter_t filter)
{
  /* variables */
  int result = TRUE;
  int i;

  /* browse the filter */
  for(  i = 0;
        i < FILTER_LENGTH &&
        result  == TRUE;
        i++               ) {
    /* if one identifier is present */
    if(filter[i].std_id != -1) {
      /* the filter isn't empty */
      result = FALSE;
    }
  }

  return result;
}

/**
 *  say if a filter is full
 *
 *  @param  filter  filter to test
 *  @return         TRUE if the filter is full, else FALSE
 */
int is_full_filter(filter_t filter)
{
  /* variables */
  int result = TRUE;
  int i;

  /* browse the filter */
  for(  i = 0;
        i < FILTER_LENGTH &&
        result == TRUE;
        i++               ) {
    /* if one field of the filter is empty */
    if(filter[i].std_id == -1) {
      /* the filter isn't full */
      result = FALSE;
    }
  }

  return result;
}

/**
 *  initialize a filter
 *
 *  @param  filter  filter to initialize
 */
void init_filter(filter_t filter)
{
  /* variable */
  int i;

  /* initalization */
  /* browse the filter */
  for(i = 0; i < FILTER_LENGTH; i++) {
    /* all elements take -1 value */
    filter[i].std_id = -1;
    filter[i].ext_id = -1;
  }
}

/**
 *  add an identifier to a filter
 *
 *  @param  filter      filter where add an identifier
 *  @param  identifier  identifier to add
 */
void add_identifier_to_filter(filter_t filter, identifier_t* identifier)
{
  /* variables */
  int i;
  int end_of_browse = FALSE;

  /* if the filter isn't full
     and the identifier doesn't exists */
  if(is_full_filter(filter) == FALSE) {
    if(is_existed_identifier(filter, identifier) == FALSE) {
      /* browse filter and add identifier at the first free space */
      for(  i = 0;
            i < FILTER_LENGTH       &&
            end_of_browse == FALSE;
            i++                     ) {
        /* if there is an empty field */
        if(filter[i].std_id == -1) {
          /* put the identifier in this field */
          filter[i].std_id = identifier->std_id;
          if(is_standard_identifier(identifier) == FALSE) {
            filter[i].ext_id = identifier->ext_id;
          }
          /* stop to browse the filter */
          end_of_browse = TRUE;
        }
      }
    }
    else
      fprintf(stderr, "[%d] %s \n", __LINE__, __FILE__);
      perror("add_identifier_to_filter() : the identifier already exists in the filter");
  }
  else
    fprintf(stderr, "[%d] %s \n", __LINE__, __FILE__);
    perror("add_identifier_to_filter() : the filter is full, can't add another identifier");
}

/**
 *  remove an identifier to a filter
 *
 *  @param  filter      filter where remove an identifier
 *  @param  identifier  identifier to remove
 */
void remove_identifier_to_filter(filter_t filter, identifier_t* identifier)
{
  /* variables */
  int i;
  int end_of_browse = FALSE;

  /* if the filter isn't empty
     and the identifier exists */
  if(is_empty_filter(filter) == FALSE) {
    if(is_existed_identifier(filter, identifier) == TRUE) {
      /* browse filter and add identifier at the first free space */
      for(  i = 0;
            i < FILTER_LENGTH       &&
            end_of_browse == FALSE;
            i++                     ) {
        /* when the identifier is find in the filter */
        if( filter[i].std_id == identifier->std_id  &&
            filter[i].ext_id == identifier->ext_id  ) {
          /* empty the field */
          filter[i].std_id = -1;
          if(is_standard_identifier(identifier) == FALSE) {
            filter[i].ext_id = -1;
          }
          /* stop to browse the filter */
          end_of_browse = TRUE;
        }
      }
    }
    else
      fprintf(stderr, "[%d] %s \n", __LINE__, __FILE__);
      perror("remove_identifier_to_filter() : the identifier isn't existed, action canceled");
  }
  else
    fprintf(stderr, "[%d] %s \n", __LINE__, __FILE__);
    perror("remove_identifier_to_filter() : the filter is empty, can't remove identifier");
}

/**
 *  uptate the filter registers
 *
 *  @param  ipc     structure used for communication
 *  @param  filter  filter to write in registers
 */
void update_filter(ipc_t* ipc, dev_id_t can_device, filter_t filter)
{
  /* variables */
  filter_conversion_union_t convert;
  reg_id_t mask = 0;
  int i;
  int j;
  int k;
  
  /* prepare registers */
  for(i = 0; i < FILTER_LENGTH; i++) {
    convert.filter[i].std_id = filter[i].std_id;
    convert.filter[i].ext_id = filter[i].ext_id;
  }

  /* write registers */
  for(j = 0; j < FILTER_REG_NUMBER; j++) {
    vp_ipc_write_reg(ipc, can_device | filter_reg_ids[j], convert.reg[j]);
  }

  /* create mask */
  for(k = 0; k < (sizeof(filter_reg_ids) / sizeof(reg_id_t)); k++) {
    mask |= filter_reg_ids[j];
  }
  mask |= can_device;
    
  /* signal update */
  vp_ipc_signal_update(ipc, can_device, mask);
}

/**
 *  read the filter registers
 *
 *  @param  ipc     structure used for communication
 *  @param  filter  filter wich will take the read filter
 */
void read_filter(ipc_t* ipc, filter_t filter)
{ 
  /* variables */
  filter_conversion_union_t convert;
  int i;
  int j;

  /* read registers */
  for(i = 0; i < FILTER_REG_NUMBER; i++) {
    convert.reg[i] = vp_ipc_read_reg(ipc, filter_reg_ids[i]);
  }

  /* take the filter */
  /*filter = convert.filter;*/
  for(j = 0; j < FILTER_LENGTH; j++) {
    filter[j] = convert.filter[j];
  }
}

/**
 *  test if a frame is acceptable
 *
 *  @param  frame   frame to test
 *  @param  filter  filter to used to test the acceptance
 *  @return         TRUE if the frame is acceptable, else FALSE
 */
int frame_acceptance(frame_t* frame, filter_t filter)
{
  /* variable */
  int result = FALSE;
  int i;

  /* test if the frame is acceptable */
  switch((int) frame->arbitration.ide) {
    /* standard frame */
    case 0 :
      /* browse the filter */
      for(  i = 0;
            i < FILTER_LENGTH &&
            result == FALSE;
            i++               ) {
        /* if the frame's identifier is in the filter */
        if( is_standard_identifier(&filter[i]) == TRUE                &&
            frame->arbitration.identifier.std_id == filter[i].std_id  ) {
          /* the frame is acceptable */
          result = TRUE;
        }
      }
    break;

    /* extends frame */
    case 1 :
      /* browse the filter */
      for(  i = 0;
            i < FILTER_LENGTH &&
            result == FALSE;
            i++               ) {
        /* if the frame's identifier is in the filter */
        if( is_standard_identifier(&filter[i]) == FALSE               &&
            frame->arbitration.identifier.std_id == filter[i].std_id  &&
            frame->arbitration.identifier.ext_id == filter[i].ext_id  ) {
          /* the frame is acceptable */
          result = TRUE;
        }
      }
    break;

    default :
      fprintf(stderr, "[%d] %s \n", __LINE__, __FILE__);
      perror("frame_acceptance() : the frame to test isn't correctly parameter");
    break;
  }

  return result;
}

