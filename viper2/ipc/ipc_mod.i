%module ipc
%include typemaps.i

%{
/* Includes the header in the wrapper code */
#include "ipc_mod.h"
%}

/* Parse the header file to generate wrappers */
%include "ipc_mod.h"
typedef signed long long int dev_id_t;

