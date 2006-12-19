/*
 * Trampoline OS
 *
 * Trampoline is copyright (c) IRCCyN 2005+
 * Trampoline est protégé par la loi sur la propriété intellectuelle
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

#include "tpl_os_types.h"
#include "tpl_com_types.h"

/*
 * Forward declarations
 */
struct TPL_FILTER_DESC;

/*
 * filtering function pointer
 */
typedef bool (*tpl_filter_func)(
    struct TPL_FILTER_DESC *,
    tpl_com_value,
    tpl_com_value
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
    tpl_filter_func filter ;
};

typedef struct TPL_FILTER_DESC tpl_filter_desc ;
typedef tpl_filter_desc tpl_noparam_filter_desc ;

/*
 * Mask used for filtering
 */
struct TPL_MASK_FILTER_DESC {
    /*  base filter desc                */
    tpl_filter_desc     b_desc ;
    /*  mask                            */
    tpl_com_value       mask;
};

typedef struct TPL_MASK_FILTER_DESC tpl_mask_filter_desc;

/*
 * Mask and comparison value used for filtering
 */
struct TPL_MASK_X_FILTER_DESC {
    /*  base filter desc                */
    tpl_filter_desc     b_desc ;
    /*  mask                            */
    tpl_com_value       mask;
    /*  comparison value                */
    tpl_com_value       x;
};

typedef struct TPL_MASK_X_FILTER_DESC tpl_mask_x_filter_desc;

/*
 * Interval used for filtering
 */
struct TPL_INTERVAL_FILTER_DESC {
    /*  base filter desc                */
    tpl_filter_desc     b_desc ;
    /*  minimum value of the interval   */
    tpl_com_value       min;
    /*  maximum value of the interval   */
    tpl_com_value       max;
};

typedef struct TPL_INTERVAL_FILTER_DESC tpl_interval_filter_desc;

/*
 * Occurence counting used for filtering
 */
struct TPL_OCCURENCE_FILTER_DESC {
    /*  base filter desc                        */
    tpl_filter_desc     b_desc ;
    /*  period of the filter                    */
    tpl_com_count       period;
    /*  pointer to the occurence of the data    */
    tpl_com_count       *occurence;
};

typedef struct TPL_OCCURENCE_FILTER_DESC tpl_occurence_filter_desc;

bool tpl_filtering(
    unsigned char *,
    unsigned char *,
    tpl_message_size,
    tpl_filter_desc *);

#endif
