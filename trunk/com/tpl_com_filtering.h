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
union TPL_FILTER_PARAM;


/*
 * filtering function pointer
 */
typedef bool (*tpl_filter_func)(
    union TPL_FILTER_PARAM *,
    tpl_com_value,
    tpl_com_value
);

/*
 * Mask used for filtering
 */
struct TPL_MASK_FILTER_PARAM {
    /*  mask                */
    tpl_com_value   mask;
    /*  comparison value    */
    tpl_com_value   x;
};

typedef struct TPL_MASK_FILTER_PARAM tpl_mask;

/*
 * Interval used for filtering
 */
struct TPL_INTERVAL_FILTER_PARAM {
    tpl_com_value   min;
    tpl_com_value   max;
};

typedef struct TPL_INTERVAL_FILTER_PARAM tpl_interval;

/*
 * Occurence counting used for filtering
 */
struct TPL_OCCURENCE_FILTER_PARAM {
    /*  period of the filter                    */
    tpl_com_count   period;
    /*  pointer to the occurence of the data    */
    tpl_com_count   *occurence;
};

typedef struct TPL_OCCURENCE_FILTER_PARAM tpl_occurence;

/*
 * Filter params union
 */
union TPL_FILTER_PARAM {
    /*  mask                */
    tpl_mask        mask;
    /*  interval            */
    tpl_interval    interval;
    /*  every               */
    tpl_occurence   every;
};

typedef union TPL_FILTER_PARAM tpl_filter_param;

/*
 * Filter descriptor
 */
struct TPL_FILTER_DESC {
    /*  pointer to the filter function  */
    tpl_filter_func     filter;
    /*  parameters of the filter        */
    tpl_filter_param    param;
};

typedef struct TPL_FILTER_DESC tpl_filter_desc;

#endif
