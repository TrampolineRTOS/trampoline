//---------------------------------------------------------------------------*
//                                                                           *
//                          File 'config_type.cpp'                           *
//                        Generated by version 1.9.1                         *
//                    september 21th, 2009, at 18h19'2"                      *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

//---------------------------------------------------------------------------*

#include "version_libpm.h"
#if LIBPM_VERSION != 572
  #error "This file has been compiled with a version of GALGAS different than the version of libpm"
#endif

//---------------------------------------------------------------------------*

#include <typeinfo>
#include "utilities/MF_MemoryControl.h"
#include "files/C_TextFileWrite.h"
#include "galgas/C_galgas_CLI_Options.h"
#include "config_type.h"

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define SOURCE_FILE_AT_LINE(line) "config_type.ggs", line
  #define COMMA_SOURCE_FILE_AT_LINE(line) , SOURCE_FILE_AT_LINE(line)
#else
  #define SOURCE_FILE_AT_LINE(line) 
  #define COMMA_SOURCE_FILE_AT_LINE(line) 
#endif


//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//                          class 'cPtr_os_config'                           *
//                                                                           *
//---------------------------------------------------------------------------*

cPtr_os_config::
cPtr_os_config (const GGS_bool& argument_0,
                                const GGS_bool& argument_1,
                                const GGS_bool& argument_2,
                                const GGS_bool& argument_3,
                                const GGS_bool& argument_4,
                                const GGS_bool& argument_5,
                                const GGS_bool& argument_6,
                                const GGS_bool& argument_7,
                                const GGS_bool& argument_8,
                                const GGS_bool& argument_9,
                                const GGS_bool& argument_10,
                                const GGS_bool& argument_11,
                                const GGS_bool& argument_12,
                                const GGS_bool& argument_13,
                                const GGS_bool& argument_14,
                                const GGS_bool& argument_15,
                                const GGS_bool& argument_16,
                                const GGS_uint & argument_17
                                COMMA_LOCATION_ARGS)
:cPtr__AC_galgas_class (THERE),
with_compilersettings (argument_0),
with_memmap (argument_1),
with_com (argument_2),
with_autosar (argument_3),
with_osapplication (argument_4),
with_timingprotection (argument_5),
with_stackmonitoring (argument_6),
with_memoryprotection (argument_7),
with_systemcall (argument_8),
with_errorhook (argument_9),
with_startuphook (argument_10),
with_shutdownhook (argument_11),
with_pretaskhook (argument_12),
with_postaskhook (argument_13),
with_protectionhook (argument_14),
with_trace (argument_15),
with_it_table (argument_16),
scalability_class (argument_17) {
}

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  cPtr_os_config * GGS_os_config::
  operator () (LOCATION_ARGS) const {
    macroValidPointerThere (mPointer) ;
    MF_Assert (dynamic_cast <cPtr_os_config *> (mPointer) != NULL,
               "dynamic cast error", 0, 0) ;
    return (cPtr_os_config *) mPointer ;
  }
#endif

//---------------------------------------------------------------------------*

bool cPtr_os_config::
isEqualToObject (const cPtr__AC_galgas_class * inOperand) const {
  bool equal = typeid (this) == typeid (inOperand) ;
  if (equal) {
    const cPtr_os_config * ptr = dynamic_cast <const cPtr_os_config *> (inOperand) ;
    macroValidPointer (ptr) ;
    equal = with_compilersettings.operator_isEqual (ptr->with_compilersettings).boolValue ()
         && with_memmap.operator_isEqual (ptr->with_memmap).boolValue ()
         && with_com.operator_isEqual (ptr->with_com).boolValue ()
         && with_autosar.operator_isEqual (ptr->with_autosar).boolValue ()
         && with_osapplication.operator_isEqual (ptr->with_osapplication).boolValue ()
         && with_timingprotection.operator_isEqual (ptr->with_timingprotection).boolValue ()
         && with_stackmonitoring.operator_isEqual (ptr->with_stackmonitoring).boolValue ()
         && with_memoryprotection.operator_isEqual (ptr->with_memoryprotection).boolValue ()
         && with_systemcall.operator_isEqual (ptr->with_systemcall).boolValue ()
         && with_errorhook.operator_isEqual (ptr->with_errorhook).boolValue ()
         && with_startuphook.operator_isEqual (ptr->with_startuphook).boolValue ()
         && with_shutdownhook.operator_isEqual (ptr->with_shutdownhook).boolValue ()
         && with_pretaskhook.operator_isEqual (ptr->with_pretaskhook).boolValue ()
         && with_postaskhook.operator_isEqual (ptr->with_postaskhook).boolValue ()
         && with_protectionhook.operator_isEqual (ptr->with_protectionhook).boolValue ()
         && with_trace.operator_isEqual (ptr->with_trace).boolValue ()
         && with_it_table.operator_isEqual (ptr->with_it_table).boolValue ()
         && scalability_class.operator_isEqual (ptr->scalability_class).boolValue () ;
  }
  return equal ;
}

//---------------------------------------------------------------------------*

void cPtr_os_config::
method_generate (C_Compiler & inLexique,
                                GGS_string& var_cas_res COMMA_UNUSED_LOCATION_ARGS) const {
  var_cas_res = GGS_string ("") ;
  if ((with_compilersettings).isBuiltAndTrue ()) {
    var_cas_res.appendCString ("#define WITH_COMPILER_SETTINGS            YES\n") ;
  }else{
    var_cas_res.appendCString ("#define WITH_COMPILER_SETTINGS            NO\n") ;
  }
  if ((with_memmap).isBuiltAndTrue ()) {
    var_cas_res.appendCString ("#define WITH_MEMMAP                       YES\n") ;
  }else{
    var_cas_res.appendCString ("#define WITH_MEMMAP                       NO\n") ;
  }
  if ((with_com).isBuiltAndTrue ()) {
    var_cas_res.appendCString ("#define WITH_COM                          YES\n") ;
  }else{
    var_cas_res.appendCString ("#define WITH_COM                          NO\n") ;
  }
  if ((with_autosar).isBuiltAndTrue ()) {
    var_cas_res.appendCString ("#define WITH_AUTOSAR                      YES\n") ;
  }else{
    var_cas_res.appendCString ("#define WITH_AUTOSAR                      NO\n") ;
  }
  if ((with_osapplication).isBuiltAndTrue ()) {
    var_cas_res.appendCString ("#define WITH_OSAPPLICATION                YES\n") ;
  }else{
    var_cas_res.appendCString ("#define WITH_OSAPPLICATION                NO\n") ;
  }
  if ((with_timingprotection).isBuiltAndTrue ()) {
    var_cas_res.appendCString ("#define WITH_AUTOSAR_TIMING_PROTECTION    YES\n") ;
  }else{
    var_cas_res.appendCString ("#define WITH_AUTOSAR_TIMING_PROTECTION    NO\n") ;
  }
  if ((with_stackmonitoring).isBuiltAndTrue ()) {
    var_cas_res.appendCString ("#define WITH_AUTOSAR_STACK_MONITORING     YES\n") ;
  }else{
    var_cas_res.appendCString ("#define WITH_AUTOSAR_STACK_MONITORING     NO\n") ;
  }
  if ((with_memoryprotection).isBuiltAndTrue ()) {
    var_cas_res.appendCString ("#define WITH_MEMORY_PROTECTION            YES\n") ;
  }else{
    var_cas_res.appendCString ("#define WITH_MEMORY_PROTECTION            NO\n") ;
  }
  if ((with_systemcall).isBuiltAndTrue ()) {
    var_cas_res.appendCString ("#define WITH_SYSTEM_CALL                  YES\n") ;
  }else{
    var_cas_res.appendCString ("#define WITH_SYSTEM_CALL                  NO\n") ;
  }
  if ((with_errorhook).isBuiltAndTrue ()) {
    var_cas_res.appendCString ("#define WITH_ERROR_HOOK                   YES\n") ;
  }else{
    var_cas_res.appendCString ("#define WITH_ERROR_HOOK                   NO\n") ;
  }
  if ((with_startuphook).isBuiltAndTrue ()) {
    var_cas_res.appendCString ("#define WITH_STARTUP_HOOK                 YES\n") ;
  }else{
    var_cas_res.appendCString ("#define WITH_STARTUP_HOOK                 NO\n") ;
  }
  if ((with_shutdownhook).isBuiltAndTrue ()) {
    var_cas_res.appendCString ("#define WITH_SHUTDOWN_HOOK                YES\n") ;
  }else{
    var_cas_res.appendCString ("#define WITH_SHUTDOWN_HOOK                NO\n") ;
  }
  if ((with_pretaskhook).isBuiltAndTrue ()) {
    var_cas_res.appendCString ("#define WITH_PRE_TASK_HOOK                YES\n") ;
  }else{
    var_cas_res.appendCString ("#define WITH_PRE_TASK_HOOK                NO\n") ;
  }
  if ((with_postaskhook).isBuiltAndTrue ()) {
    var_cas_res.appendCString ("#define WITH_POST_TASK_HOOK               YES\n") ;
  }else{
    var_cas_res.appendCString ("#define WITH_POST_TASK_HOOK               NO\n") ;
  }
  if ((with_protectionhook).isBuiltAndTrue ()) {
    var_cas_res.appendCString ("#define WITH_PROTECTION_HOOK              YES\n") ;
  }else{
    var_cas_res.appendCString ("#define WITH_PROTECTION_HOOK              NO\n") ;
  }
  if ((with_trace).isBuiltAndTrue ()) {
    var_cas_res.appendCString ("#define WITH_TRACE                        YES\n") ;
  }else{
    var_cas_res.appendCString ("#define WITH_TRACE                        NO\n") ;
  }
  var_cas_res.appendCString ("#define SCALABILITY_CLASS                 ") ;
  var_cas_res.dotAssign_operation (scalability_class.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (135))) ;
}

//---------------------------------------------------------------------------*

void cPtr_os_config::
appendForDescription (C_Compiler & inLexique,
                      C_String & ioString,
                      const sint32 inIndentation
                      COMMA_LOCATION_ARGS) const {
  ioString << "->@os_config:"
           << with_compilersettings.reader_description  (inLexique COMMA_THERE, inIndentation + 1)
           << with_memmap.reader_description  (inLexique COMMA_THERE, inIndentation + 1)
           << with_com.reader_description  (inLexique COMMA_THERE, inIndentation + 1)
           << with_autosar.reader_description  (inLexique COMMA_THERE, inIndentation + 1)
           << with_osapplication.reader_description  (inLexique COMMA_THERE, inIndentation + 1)
           << with_timingprotection.reader_description  (inLexique COMMA_THERE, inIndentation + 1)
           << with_stackmonitoring.reader_description  (inLexique COMMA_THERE, inIndentation + 1)
           << with_memoryprotection.reader_description  (inLexique COMMA_THERE, inIndentation + 1)
           << with_systemcall.reader_description  (inLexique COMMA_THERE, inIndentation + 1)
           << with_errorhook.reader_description  (inLexique COMMA_THERE, inIndentation + 1)
           << with_startuphook.reader_description  (inLexique COMMA_THERE, inIndentation + 1)
           << with_shutdownhook.reader_description  (inLexique COMMA_THERE, inIndentation + 1)
           << with_pretaskhook.reader_description  (inLexique COMMA_THERE, inIndentation + 1)
           << with_postaskhook.reader_description  (inLexique COMMA_THERE, inIndentation + 1)
           << with_protectionhook.reader_description  (inLexique COMMA_THERE, inIndentation + 1)
           << with_trace.reader_description  (inLexique COMMA_THERE, inIndentation + 1)
           << with_it_table.reader_description  (inLexique COMMA_THERE, inIndentation + 1)
           << scalability_class.reader_description  (inLexique COMMA_THERE, inIndentation + 1) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//                              Class message                                *
//                                                                           *
//---------------------------------------------------------------------------*

const char * cPtr_os_config::
_message (void) const {
  return "" ;
}

//---------------------------------------------------------------------------*

const char * cPtr_os_config::
_static_message (void) {
  return "" ;
}

//---------------------------------------------------------------------------*

C_galgas_class_inspector _gInspectorFor_os_config (& typeid (cPtr_os_config), NULL, "") ;

//---------------------------------------------------------------------------*

AC_galgasClassRunTimeInformation * cPtr_os_config::galgasRTTI (void) const {
  return & gClassInfoFor__os_config ;
}

//---------------------------------------------------------------------------*

cPtr__AC_galgas_class * cPtr_os_config::makeClone (void) const {
  cPtr__AC_galgas_class * result = NULL ;
  macroMyNew (result, cPtr_os_config (with_compilersettings, with_memmap, with_com, with_autosar, with_osapplication, with_timingprotection, with_stackmonitoring, with_memoryprotection, with_systemcall, with_errorhook, with_startuphook, with_shutdownhook, with_pretaskhook, with_postaskhook, with_protectionhook, with_trace, with_it_table, scalability_class COMMA_HERE)) ;
  return result ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//                       GALGAS class 'GGS_os_config'                        *
//                                                                           *
//---------------------------------------------------------------------------*

GGS_os_config::
GGS_os_config (const cPtr__AC_galgas_class * inPointer) {
  macroAssignPointer (mPointer, (cPtr__AC_galgas_class *) inPointer) ;
}

//---------------------------------------------------------------------------*

GGS_os_config::
GGS_os_config (cPtr__AC_galgas_class & inObject) {
  macroAssignPointer (mPointer, & inObject) ;
}

//---------------------------------------------------------------------------*

//--- castFrom class method (implements cast expression)
GGS_os_config GGS_os_config::
castFrom (C_Compiler & inLexique,
           cPtr__AC_galgas_class * inPointer,
           const bool inUseKindOfClass,
           const GGS_location & inErrorLocation
           COMMA_LOCATION_ARGS) {
  GGS_os_config result ;
  if (inPointer != NULL) {
    macroValidPointer (inPointer) ;
    const bool ok = inUseKindOfClass
      ? (dynamic_cast <cPtr_os_config *> (inPointer) != NULL)
      : (typeid (cPtr_os_config) == typeid (*inPointer)) ;
    if (ok) {
      result = GGS_os_config (inPointer) ;
    }else{
      inErrorLocation.signalCastError (inLexique,
                                       & typeid (cPtr_os_config),
                                       inUseKindOfClass,
                                       inPointer->_message ()
                                       COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*

GGS_os_config GGS_os_config::
constructor_new (C_Compiler & /* inLexique */,
                 const GGS_bool& argument_0,
                 const GGS_bool& argument_1,
                 const GGS_bool& argument_2,
                 const GGS_bool& argument_3,
                 const GGS_bool& argument_4,
                 const GGS_bool& argument_5,
                 const GGS_bool& argument_6,
                 const GGS_bool& argument_7,
                 const GGS_bool& argument_8,
                 const GGS_bool& argument_9,
                 const GGS_bool& argument_10,
                 const GGS_bool& argument_11,
                 const GGS_bool& argument_12,
                 const GGS_bool& argument_13,
                 const GGS_bool& argument_14,
                 const GGS_bool& argument_15,
                 const GGS_bool& argument_16,
                 const GGS_uint & argument_17
                                COMMA_LOCATION_ARGS) {
  GGS_os_config result ;
  macroMyNew (result.mPointer, cPtr_os_config (argument_0,
                                argument_1,
                                argument_2,
                                argument_3,
                                argument_4,
                                argument_5,
                                argument_6,
                                argument_7,
                                argument_8,
                                argument_9,
                                argument_10,
                                argument_11,
                                argument_12,
                                argument_13,
                                argument_14,
                                argument_15,
                                argument_16,
                                argument_17 COMMA_THERE)) ;
  return result ;
}

//---------------------------------------------------------------------------*

GGS_bool GGS_os_config::
reader_with_compilersettings (C_Compiler & /* inLexique */ COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_bool  result ;
  if (mPointer != NULL) {
    macroValidPointer (mPointer) ;
    MF_Assert (dynamic_cast <cPtr_os_config *> (mPointer) != NULL,
               "dynamic cast error", 0, 0) ;
    result = ((cPtr_os_config *) mPointer)->with_compilersettings ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GGS_bool GGS_os_config::
reader_with_memmap (C_Compiler & /* inLexique */ COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_bool  result ;
  if (mPointer != NULL) {
    macroValidPointer (mPointer) ;
    MF_Assert (dynamic_cast <cPtr_os_config *> (mPointer) != NULL,
               "dynamic cast error", 0, 0) ;
    result = ((cPtr_os_config *) mPointer)->with_memmap ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GGS_bool GGS_os_config::
reader_with_com (C_Compiler & /* inLexique */ COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_bool  result ;
  if (mPointer != NULL) {
    macroValidPointer (mPointer) ;
    MF_Assert (dynamic_cast <cPtr_os_config *> (mPointer) != NULL,
               "dynamic cast error", 0, 0) ;
    result = ((cPtr_os_config *) mPointer)->with_com ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GGS_bool GGS_os_config::
reader_with_autosar (C_Compiler & /* inLexique */ COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_bool  result ;
  if (mPointer != NULL) {
    macroValidPointer (mPointer) ;
    MF_Assert (dynamic_cast <cPtr_os_config *> (mPointer) != NULL,
               "dynamic cast error", 0, 0) ;
    result = ((cPtr_os_config *) mPointer)->with_autosar ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GGS_bool GGS_os_config::
reader_with_osapplication (C_Compiler & /* inLexique */ COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_bool  result ;
  if (mPointer != NULL) {
    macroValidPointer (mPointer) ;
    MF_Assert (dynamic_cast <cPtr_os_config *> (mPointer) != NULL,
               "dynamic cast error", 0, 0) ;
    result = ((cPtr_os_config *) mPointer)->with_osapplication ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GGS_bool GGS_os_config::
reader_with_timingprotection (C_Compiler & /* inLexique */ COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_bool  result ;
  if (mPointer != NULL) {
    macroValidPointer (mPointer) ;
    MF_Assert (dynamic_cast <cPtr_os_config *> (mPointer) != NULL,
               "dynamic cast error", 0, 0) ;
    result = ((cPtr_os_config *) mPointer)->with_timingprotection ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GGS_bool GGS_os_config::
reader_with_stackmonitoring (C_Compiler & /* inLexique */ COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_bool  result ;
  if (mPointer != NULL) {
    macroValidPointer (mPointer) ;
    MF_Assert (dynamic_cast <cPtr_os_config *> (mPointer) != NULL,
               "dynamic cast error", 0, 0) ;
    result = ((cPtr_os_config *) mPointer)->with_stackmonitoring ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GGS_bool GGS_os_config::
reader_with_memoryprotection (C_Compiler & /* inLexique */ COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_bool  result ;
  if (mPointer != NULL) {
    macroValidPointer (mPointer) ;
    MF_Assert (dynamic_cast <cPtr_os_config *> (mPointer) != NULL,
               "dynamic cast error", 0, 0) ;
    result = ((cPtr_os_config *) mPointer)->with_memoryprotection ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GGS_bool GGS_os_config::
reader_with_systemcall (C_Compiler & /* inLexique */ COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_bool  result ;
  if (mPointer != NULL) {
    macroValidPointer (mPointer) ;
    MF_Assert (dynamic_cast <cPtr_os_config *> (mPointer) != NULL,
               "dynamic cast error", 0, 0) ;
    result = ((cPtr_os_config *) mPointer)->with_systemcall ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GGS_bool GGS_os_config::
reader_with_errorhook (C_Compiler & /* inLexique */ COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_bool  result ;
  if (mPointer != NULL) {
    macroValidPointer (mPointer) ;
    MF_Assert (dynamic_cast <cPtr_os_config *> (mPointer) != NULL,
               "dynamic cast error", 0, 0) ;
    result = ((cPtr_os_config *) mPointer)->with_errorhook ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GGS_bool GGS_os_config::
reader_with_startuphook (C_Compiler & /* inLexique */ COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_bool  result ;
  if (mPointer != NULL) {
    macroValidPointer (mPointer) ;
    MF_Assert (dynamic_cast <cPtr_os_config *> (mPointer) != NULL,
               "dynamic cast error", 0, 0) ;
    result = ((cPtr_os_config *) mPointer)->with_startuphook ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GGS_bool GGS_os_config::
reader_with_shutdownhook (C_Compiler & /* inLexique */ COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_bool  result ;
  if (mPointer != NULL) {
    macroValidPointer (mPointer) ;
    MF_Assert (dynamic_cast <cPtr_os_config *> (mPointer) != NULL,
               "dynamic cast error", 0, 0) ;
    result = ((cPtr_os_config *) mPointer)->with_shutdownhook ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GGS_bool GGS_os_config::
reader_with_pretaskhook (C_Compiler & /* inLexique */ COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_bool  result ;
  if (mPointer != NULL) {
    macroValidPointer (mPointer) ;
    MF_Assert (dynamic_cast <cPtr_os_config *> (mPointer) != NULL,
               "dynamic cast error", 0, 0) ;
    result = ((cPtr_os_config *) mPointer)->with_pretaskhook ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GGS_bool GGS_os_config::
reader_with_postaskhook (C_Compiler & /* inLexique */ COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_bool  result ;
  if (mPointer != NULL) {
    macroValidPointer (mPointer) ;
    MF_Assert (dynamic_cast <cPtr_os_config *> (mPointer) != NULL,
               "dynamic cast error", 0, 0) ;
    result = ((cPtr_os_config *) mPointer)->with_postaskhook ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GGS_bool GGS_os_config::
reader_with_protectionhook (C_Compiler & /* inLexique */ COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_bool  result ;
  if (mPointer != NULL) {
    macroValidPointer (mPointer) ;
    MF_Assert (dynamic_cast <cPtr_os_config *> (mPointer) != NULL,
               "dynamic cast error", 0, 0) ;
    result = ((cPtr_os_config *) mPointer)->with_protectionhook ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GGS_bool GGS_os_config::
reader_with_trace (C_Compiler & /* inLexique */ COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_bool  result ;
  if (mPointer != NULL) {
    macroValidPointer (mPointer) ;
    MF_Assert (dynamic_cast <cPtr_os_config *> (mPointer) != NULL,
               "dynamic cast error", 0, 0) ;
    result = ((cPtr_os_config *) mPointer)->with_trace ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GGS_bool GGS_os_config::
reader_with_it_table (C_Compiler & /* inLexique */ COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_bool  result ;
  if (mPointer != NULL) {
    macroValidPointer (mPointer) ;
    MF_Assert (dynamic_cast <cPtr_os_config *> (mPointer) != NULL,
               "dynamic cast error", 0, 0) ;
    result = ((cPtr_os_config *) mPointer)->with_it_table ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GGS_uint  GGS_os_config::
reader_scalability_class (C_Compiler & /* inLexique */ COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_uint   result ;
  if (mPointer != NULL) {
    macroValidPointer (mPointer) ;
    MF_Assert (dynamic_cast <cPtr_os_config *> (mPointer) != NULL,
               "dynamic cast error", 0, 0) ;
    result = ((cPtr_os_config *) mPointer)->scalability_class ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

const char * GGS_os_config::actualTypeName (void) const {
  return "os_config" ;
}

//---------------------------------------------------------------------------*

AC_galgasClassRunTimeInformation * GGS_os_config::galgasObjectRunTimeInfo (void) const {
  AC_galgasClassRunTimeInformation * result = NULL ;
  if (mPointer != NULL) {
    result = mPointer->galgasRTTI () ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

C_galgasRootClassRunTimeInformation gClassInfoFor__os_config ("os_config") ;

//---------------------------------------------------------------------------*
//                                                                           *
//                   Implementation of function "os_cfg"                     *
//                                                                           *
//---------------------------------------------------------------------------*

GGS_os_config  function_os_cfg (C_Compiler & inLexique,
                                GGS_root_obj   var_cas_cpu COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER function_os_cfg at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  GGS_os_config  var_cas_cfg ;
  GGS_bool var_cas_itt ;
  var_cas_itt = gOption_goil_5F_options_posix_5F_it.value () ;
  GGS_bool var_cas_tp ;
  var_cas_tp = GGS_bool (false) ;
  {
    GGS_task_map::cEnumerator enumerator_4255 (var_cas_cpu.reader_tasks (inLexique COMMA_SOURCE_FILE_AT_LINE (154)), true) ;
    const GGS_task_map::cElement * operand_4255 = NULL ;
    while (((operand_4255 = enumerator_4255.nextObject ()))) {
      macroValidPointer (operand_4255) ;
      { const GGS_timing_prot _var_4355 = operand_4255->mInfo.task.reader_timing_prot (inLexique COMMA_SOURCE_FILE_AT_LINE (155)) ; // CAST instruction
        if (_var_4355.getPtr () != NULL) {
          macroValidPointer (_var_4355.getPtr ()) ;
          if (typeid (cPtr_timing_prot_task) == typeid (* (_var_4355.getPtr ()))) {
            var_cas_tp = GGS_bool (true) ;
          }else{
          }
        }
      }
    }
  }
  {
    GGS_isr_map::cEnumerator enumerator_4388 (var_cas_cpu.reader_isrs (inLexique COMMA_SOURCE_FILE_AT_LINE (159)), true) ;
    const GGS_isr_map::cElement * operand_4388 = NULL ;
    while (((operand_4388 = enumerator_4388.nextObject ()))) {
      macroValidPointer (operand_4388) ;
      { const GGS_timing_prot _var_4485 = operand_4388->mInfo.isr.reader_timing_prot (inLexique COMMA_SOURCE_FILE_AT_LINE (160)) ; // CAST instruction
        if (_var_4485.getPtr () != NULL) {
          macroValidPointer (_var_4485.getPtr ()) ;
          if (typeid (cPtr_timing_prot_isr) == typeid (* (_var_4485.getPtr ()))) {
            var_cas_tp = GGS_bool (true) ;
          }else{
          }
        }
      }
    }
  }
  var_cas_cfg = GGS_os_config ::constructor_new (inLexique, GGS_bool (false), GGS_bool (false), GGS_bool (false), GGS_bool (false), GGS_bool (false), var_cas_tp, GGS_bool (false), GGS_bool (false), GGS_bool (false), GGS_bool (false), GGS_bool (false), GGS_bool (false), GGS_bool (false), GGS_bool (false), GGS_bool (false), GGS_bool (false), var_cas_itt, GGS_uint (1U) COMMA_HERE) ;
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE function_os_cfg\n") ;
  #endif
  return var_cas_cfg ;
}

//---------------------------------------------------------------------------*

