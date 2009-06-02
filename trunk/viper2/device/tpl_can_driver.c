#include <stdlib.h>
#include <stdio.h>

#include "tpl_can_driver.h"

/* frame registers */
reg_id_t frame_reg_ids[] = {  CAN_FRAME_REG_1,
			      CAN_FRAME_REG_2,
			      CAN_FRAME_REG_3,
			      CAN_FRAME_REG_4,
			      CAN_FRAME_REG_5,
			      CAN_FRAME_REG_6 };
/* filter registers */
reg_id_t filter_reg_ids[] = { CAN_FILTER_REG_1,
			      CAN_FILTER_REG_2,
			      CAN_FILTER_REG_3,
			      CAN_FILTER_REG_4,
			      CAN_FILTER_REG_5,
			      CAN_FILTER_REG_6,
			      CAN_FILTER_REG_7,
			      CAN_FILTER_REG_8,
			      CAN_FILTER_REG_9,
			      CAN_FILTER_REG_10,
			      CAN_FILTER_REG_11,
			      CAN_FILTER_REG_12,
			      CAN_FILTER_REG_13,
			      CAN_FILTER_REG_14,
			      CAN_FILTER_REG_15,
			      CAN_FILTER_REG_16	};

/*====================
 *  transfert
 *====================*/

/**
 *  send an ipdu
 *
 *  @param  ipc	  structure used for communication
 *  @param  ipdu  ipdu to send
 */
void send_ipdu(ipc_t* ipc, tpl_ipdu* ipdu)
{
  /* variables */
  frame_conversion_union_t convert;
  reg_id_t mask = 0;
  int i;
  int j;
  
  /* prepare the frame */
  convert.frame.arbitration.identifier.std_id = IDENTIFIER_1;		/* ???		      */
  convert.frame.arbitration.rtr		      = (char) 0;		/* 0 : data frame     */
  convert.frame.arbitration.ide		      = (char) 0;		/* 0 : standard frame */
  convert.frame.dlc			      = (char) sizeof(data_t);	/* data length	      */

  /* copy the ipdu in the frame */
  convert.frame.data.bytes_1 = ipdu->bytes_1;
  convert.frame.data.bytes_2 = ipdu->bytes_2;
  
  /* write registers */
  for(i = 0; i < FRAME_REG_NUMBER; i++)
    vp_ipc_write_reg(ipc, frame_reg_ids[i], &convert.reg[i]);

  /* create mask */
  for(j = 0; j < (sizeof(frame_reg_ids) / sizeof(reg_id_t)); j++)
    mask |= frame_reg_ids[j];
  
  /* signal update */
  vp_ipc_signal_update(ipc, CAN, mask);
}

/**
 *  receive an ipdu
 *
 *  @param  ipc	  structure used for communication
 *  @param  ipdu  ipdu witch will take the receive ipdu value
 */
void receive_ipdu(ipc_t* ipc, tpl_ipdu* ipdu)
{
  /* variables */
  frame_conversion_union_t convert;
  int i;
  
  /* read registers */
  for(i = 0; i < FRAME_REG_NUMBER; i++)
    convert.reg[i] = vp_ipc_read_reg(ipc, frame_reg_ids[i]);

  /* if the frame is a data frame */
  if(convert.frame.arbitration.rtr == (char) 0) {
    /* take the ipdu */
    ipdu->bytes_1 = convert.frame.data.bytes_1;
    ipdu->bytes_2 = convert.frame.data.bytes_2;
  }
  /* else the ipdu is null */
  else {
    if(convert.frame.arbitration.rtr == (char) 1)
      ipdu = NULL;
    else
      printf("Bad parameter rtr of received frame...\n");
  }
}

/*====================
 *  acceptance
 *====================*/

/**
 *  say if an identifier is standard
 *
 *  @param  identifier	identifier to test
 *  @return		TRUE if the identifier is standard, else FALSE
 */
int is_standard_identifier(identifier_t* identifier)
{
  /* variable */
  int result = FALSE;

  /* test if the identifier isn't extend */
  if(identifier->ext_id == -1)
    result = TRUE;
  
  return result;
}

/**
 *  say if an identifier is already in a filter
 *
 *  @param  filter	filter to test
 *  @param  identifier	identifier to search
 *  @return		TRUE if the identifier exists, else FALSE
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
	  i++		    )
      /* if current identifier in the filter is standard
	 and equals to the identifier to test		 */
      if( is_standard_identifier(&filter[i]) == TRUE  &&
	  filter[i].std_id == identifier->std_id      )
	/* the identifier exists */
	result = TRUE;
  }
  /* if the identifier is extend */
  else {
      /* browse filter to search the identifier */
      for(  i = 0;
	    i < FILTER_LENGTH &&
	    result == FALSE;
	    i++		      )
	/* if current identifier int the filter is extend
	   and equals to the identifier to test		  */
	if( is_standard_identifier(&filter[i]) == FALSE	&&
	    filter[i].std_id == identifier->std_id	&&
	    filter[i].ext_id == identifier->ext_id	)
	  /* the identifier exists */
	  result = TRUE;
  }

  return result;  
}

/**
 *  say if a filter is empty
 *
 *  @param  filter  filter to test
 *  @return	    TRUE if the filter is empty, else FALSE
 */
int is_empty_filter(filter_t filter)
{
  /* variables */
  int result = TRUE;
  int i;

  /* browse the filter */
  for(	i = 0;
	i < FILTER_LENGTH &&
	result  == TRUE;
	i++		  )
    /* if one identifier is present */
    if(filter[i].std_id != -1)
      /* the filter isn't empty */
      result = FALSE;

  return result;
}

/**
 *  say if a filter is full
 *
 *  @param  filter  filter to test
 *  @return	    TRUE if the filter is full, else FALSE
 */
int is_full_filter(filter_t filter)
{
  /* variables */
  int result = TRUE;
  int i;

  /* browse the filter */
  for(	i = 0;
	i < FILTER_LENGTH &&
	result == TRUE;
	i++		  )
    /* if one field of the filter is empty */
    if(filter[i].std_id == -1)
      /* the filter isn't full */
      result = FALSE;

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
 *  @param  filter	filter where add an identifier
 *  @param  identifier	identifier to add
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
	    i < FILTER_LENGTH	    &&
	    end_of_browse == FALSE;
	    i++			    )
	/* if there is an empty field */
	if(filter[i].std_id == -1) {
	  /* put the identifier in this field */
	  filter[i].std_id = identifier->std_id;
	  if(is_standard_identifier(identifier) == FALSE)
	    filter[i].ext_id = identifier->ext_id;
	  /* stop to browse the filter */
	  end_of_browse = TRUE;
	}
    }
    else
      printf("The identifier already exists in the filter, action canceled...\n");
  }
  else
    printf("The filter is full, can't add another identifier...\n");
}

/**
 *  remove an identifier to a filter
 *
 *  @param  filter	filter where remove an identifier
 *  @param  identifier	identifier to remove
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
	    i < FILTER_LENGTH	    &&
	    end_of_browse == FALSE;
	    i++			    )
	/* when the identifier is find in the filter */
	if( filter[i].std_id == identifier->std_id  &&
	    filter[i].ext_id == identifier->ext_id  ) {
	  /* empty the field */
	  filter[i].std_id = -1;
	  if(is_standard_identifier(identifier) == FALSE)
	    filter[i].ext_id = -1;
	  /* stop to browse the filter */
	  end_of_browse = TRUE;
	}
    }
    else
      printf("The identifier isn't existed, action canceled...\n");
  }
  else
    printf("The filter is empty, can't remove identifier...\n");
}

/**
 *  uptate the filter registers
 *
 *  @param  ipc	    structure used for communication
 *  @param  filter  filter to write in registers
 */
void update_filter(ipc_t* ipc, filter_t filter)
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
  for(j = 0; j < FILTER_REG_NUMBER; j++)
    vp_ipc_write_reg(ipc, filter_reg_ids[j], &convert.reg[j]);

  /* create mask */
  for(k = 0; k < (sizeof(filter_reg_ids) / sizeof(reg_id_t)); k++)
    mask |= filter_reg_ids[j];

  /* signal update */
  vp_ipc_signal_update(ipc, CAN, mask);
}

/**
 *  read the filter registers
 *
 *  @param  ipc	    structure used for communication
 *  @param  filter  filter wich will take the read filter
 */
void read_filter(ipc_t* ipc, filter_t filter)
{
  
  /* variables */
  filter_conversion_union_t convert;
  int i;
  int j;

  /* read registers */
  for(i = 0; i < FILTER_REG_NUMBER; i++)
    convert.reg[i] = vp_ipc_read_reg(ipc, filter_reg_ids[i]);

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
 *  @return	    TRUE if the frame is acceptable, else FALSE
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
	    i++		      )
	/* if the frame's identifier is in the filter */
	if( is_standard_identifier(&filter[i]) == TRUE		      &&
	    frame->arbitration.identifier.std_id == filter[i].std_id  )
	  /* the frame is acceptable */
	  result = TRUE;
    break;

    /* extends frame */
    case 1 :
      /* browse the filter */
      for(  i = 0;
	    i < FILTER_LENGTH &&
	    result == FALSE;
	    i++		      )
	/* if the frame's identifier is in the filter */
	if( is_standard_identifier(&filter[i]) == FALSE		      &&
	    frame->arbitration.identifier.std_id == filter[i].std_id  &&
	    frame->arbitration.identifier.ext_id == filter[i].ext_id  )
	  /* the frame is acceptable */
	  result = TRUE;
    break;

    default :
      printf("The frame to test isn't correctly parameter...\n");
    break;
  }

  return result;
}

