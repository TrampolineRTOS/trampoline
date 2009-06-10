%module ipc
%include typemaps.i

%{
/* Includes the header in the wrapper code */
#include "ipc_mod.h"
#include "consts.h"
%}

/* Parse the header file to generate wrappers */
%include "ipc_mod.h"
%include "consts.h"
typedef signed long long int int64_t;
typedef int dev_id_t;
typedef int reg_t;
