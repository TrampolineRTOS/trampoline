/*
 *  tpl_as_st_definitions.h
 *  trampoline
 *
 *  Created by Jean-Luc Béchennec on 20/11/07.
 *  Copyright 2007 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef TPL_AS_ST_DEFINITIONS_H
#define TPL_AS_ST_DEFINITIONS_H

/* Schedule tables states */

#define SCHEDULETABLE_AUTOSTART                 TIME_OBJ_AUTOSTART
#define SCHEDULETABLE_NOT_STARTED               TIME_OBJ_SLEEP
#define SCHEDULETABLE_RUNNING                   TIME_OBJ_ACTIVE
#define SCHEDULETABLE_NEXT                      (TIME_OBJ_ACTIVE | 0x04)
#define SCHEDULETABLE_WAITING                   (TIME_OBJ_ACTIVE | 0x08)
#define SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS   (TIME_OBJ_ACTIVE | 0x0C)

#endif /* TPL_AS_ST_DEFINITIONS_H */
