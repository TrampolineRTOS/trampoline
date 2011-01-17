/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline is protected by the French intellectual property law.
 *
 * This software is distributed under the Lesser GNU Public Licence
 *
 * Trampoline filtering machinery header.
 *
 * $Date$
 * $Rev$
 * $Author$
 * $URL$
 */

#ifndef __TPL_COM_FILTERING_H__
#define __TPL_COM_FILTERING_H__

#include "tpl_os_internal_types.h"
#include "tpl_com_types.h"

/*
 * Forward declarations
 */
struct TPL_FILTER_DESC;

/*
 * filtering function pointer
 */
typedef tpl_bool (*tpl_filter_func)(
  CONSTP2CONST(struct TPL_FILTER_DESC, AUTOMATIC, OS_CODE),
  CONSTP2CONST(void, AUTOMATIC, OS_VAR),
  CONSTP2CONST(void, AUTOMATIC, OS_VAR)
);

/*!
 *  \struct TPL_FILTER_DESC
 * 
 *  \brief  Base structure of filter descriptor
 *
 *  This structure contains the pointer to the filter function only. It is
 *  the common part for the filter descriptor structures and is extended to
 *  add the filter parameters.
 */
struct TPL_FILTER_DESC {
    /*  filtering function pointer  */
    const tpl_filter_func filter ;
};

typedef struct TPL_FILTER_DESC tpl_filter_desc ;
typedef tpl_filter_desc tpl_noparam_filter_desc ;

/*
 * Occurence counting used for filtering
 */
struct TPL_OCCURENCE_FILTER_DESC {
    /*  base filter desc                        */
    tpl_filter_desc     b_desc ;
    /*  period of the filter                    */
    const tpl_com_count period;
	/*  offset from the period					*/
	const tpl_com_count offset;
    /*  pointer to the occurence of the data    */
    tpl_com_count       *occurence;
};

typedef struct TPL_OCCURENCE_FILTER_DESC tpl_occurence_filter_desc;

#define OS_START_SEC_CODE
#include "tpl_memmap.h"
FUNC(tpl_bool, OS_CODE) tpl_filtering(
  P2CONST(tpl_com_data, AUTOMATIC, OS_VAR)            old_data,
  P2CONST(tpl_com_data, AUTOMATIC, OS_VAR)            new_data,
  CONSTP2CONST(tpl_filter_desc, AUTOMATIC, OS_CONST)  filter_desc);
#define OS_STOP_SEC_CODE
#include "tpl_memmap.h"

#endif
