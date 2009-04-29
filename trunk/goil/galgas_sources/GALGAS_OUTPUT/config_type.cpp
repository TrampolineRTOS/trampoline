//---------------------------------------------------------------------------*
//                                                                           *
//                          File 'config_type.cpp'                           *
//                        Generated by version 1.8.1                         *
//                      april 23th, 2009, at 14h20'14"                       *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

//---------------------------------------------------------------------------*

#include "version_libpm.h"
#if LIBPM_VERSION != 456
  #error "This file has been compiled with a version of GALGAS different than the version of libpm"
#endif

//---------------------------------------------------------------------------*

#include <typeinfo>
#include "utilities/MF_MemoryControl.h"
#include "files/C_TextFileWrite.h"
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
//                           class 'cPtr_config'                             *
//                                                                           *
//---------------------------------------------------------------------------*

cPtr_config::
cPtr_config (const GGS_bool& argument_0,
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
                                const GGS_uint & argument_16
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
scalability_class (argument_16) {
}

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  cPtr_config * GGS_config::
  operator () (LOCATION_ARGS) const {
    macroValidPointerThere (mPointer) ;
    MF_Assert (dynamic_cast <cPtr_config *> (mPointer) != NULL,
               "dynamic cast error", 0, 0) ;
    return (cPtr_config *) mPointer ;
  }
#endif

//---------------------------------------------------------------------------*

bool cPtr_config::
isEqualToObject (const cPtr__AC_galgas_class * inOperand) const {
  bool equal = typeid (this) == typeid (inOperand) ;
  if (equal) {
    const cPtr_config * _p = dynamic_cast <const cPtr_config *> (inOperand) ;
    macroValidPointer (_p) ;
    equal = with_compilersettings._operator_isEqual (_p->with_compilersettings).boolValue ()
         && with_memmap._operator_isEqual (_p->with_memmap).boolValue ()
         && with_com._operator_isEqual (_p->with_com).boolValue ()
         && with_autosar._operator_isEqual (_p->with_autosar).boolValue ()
         && with_osapplication._operator_isEqual (_p->with_osapplication).boolValue ()
         && with_timingprotection._operator_isEqual (_p->with_timingprotection).boolValue ()
         && with_stackmonitoring._operator_isEqual (_p->with_stackmonitoring).boolValue ()
         && with_memoryprotection._operator_isEqual (_p->with_memoryprotection).boolValue ()
         && with_systemcall._operator_isEqual (_p->with_systemcall).boolValue ()
         && with_errorhook._operator_isEqual (_p->with_errorhook).boolValue ()
         && with_startuphook._operator_isEqual (_p->with_startuphook).boolValue ()
         && with_shutdownhook._operator_isEqual (_p->with_shutdownhook).boolValue ()
         && with_pretaskhook._operator_isEqual (_p->with_pretaskhook).boolValue ()
         && with_postaskhook._operator_isEqual (_p->with_postaskhook).boolValue ()
         && with_protectionhook._operator_isEqual (_p->with_protectionhook).boolValue ()
         && with_trace._operator_isEqual (_p->with_trace).boolValue ()
         && scalability_class._operator_isEqual (_p->scalability_class).boolValue () ;
  }
  return equal ;
}

//---------------------------------------------------------------------------*

void cPtr_config::
method_generate (C_Compiler & _inLexique,
                                GGS_string& var_cas_res COMMA_UNUSED_LOCATION_ARGS) const {
  var_cas_res = GGS_string (true, "") ;
  if ((with_compilersettings).isBuiltAndTrue ()) {
    var_cas_res.appendCstring ("#define WITH_COMPILER_SETTINGS            YES\n") ;
  }else{
    var_cas_res.appendCstring ("#define WITH_COMPILER_SETTINGS            NO\n") ;
  }
  if ((with_memmap).isBuiltAndTrue ()) {
    var_cas_res.appendCstring ("#define WITH_MEMMAP                       YES\n") ;
  }else{
    var_cas_res.appendCstring ("#define WITH_MEMMAP                       NO\n") ;
  }
  if ((with_com).isBuiltAndTrue ()) {
    var_cas_res.appendCstring ("#define WITH_COM                          YES\n") ;
  }else{
    var_cas_res.appendCstring ("#define WITH_COM                          NO\n") ;
  }
  if ((with_autosar).isBuiltAndTrue ()) {
    var_cas_res.appendCstring ("#define WITH_AUTOSAR                      YES\n") ;
  }else{
    var_cas_res.appendCstring ("#define WITH_AUTOSAR                      NO\n") ;
  }
  if ((with_osapplication).isBuiltAndTrue ()) {
    var_cas_res.appendCstring ("#define WITH_OSAPPLICATION                YES\n") ;
  }else{
    var_cas_res.appendCstring ("#define WITH_OSAPPLICATION                NO\n") ;
  }
  if ((with_timingprotection).isBuiltAndTrue ()) {
    var_cas_res.appendCstring ("#define WITH_AUTOSAR_TIMING_PROTECTION    YES\n") ;
  }else{
    var_cas_res.appendCstring ("#define WITH_AUTOSAR_TIMING_PROTECTION    NO\n") ;
  }
  if ((with_stackmonitoring).isBuiltAndTrue ()) {
    var_cas_res.appendCstring ("#define WITH_AUTOSAR_STACK_MONITORING     YES\n") ;
  }else{
    var_cas_res.appendCstring ("#define WITH_AUTOSAR_STACK_MONITORING     NO\n") ;
  }
  if ((with_memoryprotection).isBuiltAndTrue ()) {
    var_cas_res.appendCstring ("#define WITH_MEMORY_PROTECTION            YES\n") ;
  }else{
    var_cas_res.appendCstring ("#define WITH_MEMORY_PROTECTION            NO\n") ;
  }
  if ((with_systemcall).isBuiltAndTrue ()) {
    var_cas_res.appendCstring ("#define WITH_SYSTEM_CALL                  YES\n") ;
  }else{
    var_cas_res.appendCstring ("#define WITH_SYSTEM_CALL                  NO\n") ;
  }
  if ((with_errorhook).isBuiltAndTrue ()) {
    var_cas_res.appendCstring ("#define WITH_ERROR_HOOK                   YES\n") ;
  }else{
    var_cas_res.appendCstring ("#define WITH_ERROR_HOOK                   NO\n") ;
  }
  if ((with_startuphook).isBuiltAndTrue ()) {
    var_cas_res.appendCstring ("#define WITH_STARTUP_HOOK                 YES\n") ;
  }else{
    var_cas_res.appendCstring ("#define WITH_STARTUP_HOOK                 NO\n") ;
  }
  if ((with_shutdownhook).isBuiltAndTrue ()) {
    var_cas_res.appendCstring ("#define WITH_SHUTDOWN_HOOK                YES\n") ;
  }else{
    var_cas_res.appendCstring ("#define WITH_SHUTDOWN_HOOK                NO\n") ;
  }
  if ((with_pretaskhook).isBuiltAndTrue ()) {
    var_cas_res.appendCstring ("#define WITH_PRE_TASK_HOOK                YES\n") ;
  }else{
    var_cas_res.appendCstring ("#define WITH_PRE_TASK_HOOK                NO\n") ;
  }
  if ((with_postaskhook).isBuiltAndTrue ()) {
    var_cas_res.appendCstring ("#define WITH_POST_TASK_HOOK               YES\n") ;
  }else{
    var_cas_res.appendCstring ("#define WITH_POST_TASK_HOOK               NO\n") ;
  }
  if ((with_protectionhook).isBuiltAndTrue ()) {
    var_cas_res.appendCstring ("#define WITH_PROTECTION_HOOK              YES\n") ;
  }else{
    var_cas_res.appendCstring ("#define WITH_PROTECTION_HOOK              NO\n") ;
  }
  if ((with_trace).isBuiltAndTrue ()) {
    var_cas_res.appendCstring ("#define WITH_TRACE                        YES\n") ;
  }else{
    var_cas_res.appendCstring ("#define WITH_TRACE                        NO\n") ;
  }
  var_cas_res.appendCstring ("#define SCALABILITY_CLASS                 ") ;
  var_cas_res._dotAssign_operation (scalability_class.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (131))) ;
}

//---------------------------------------------------------------------------*

void cPtr_config::
appendForDescription (C_Compiler & _inLexique,
                      C_String & ioString,
                      const sint32 inIndentation
                      COMMA_LOCATION_ARGS) const {
  ioString << "->@config:"
           << with_compilersettings.reader_description  (_inLexique COMMA_THERE, inIndentation + 1)
           << with_memmap.reader_description  (_inLexique COMMA_THERE, inIndentation + 1)
           << with_com.reader_description  (_inLexique COMMA_THERE, inIndentation + 1)
           << with_autosar.reader_description  (_inLexique COMMA_THERE, inIndentation + 1)
           << with_osapplication.reader_description  (_inLexique COMMA_THERE, inIndentation + 1)
           << with_timingprotection.reader_description  (_inLexique COMMA_THERE, inIndentation + 1)
           << with_stackmonitoring.reader_description  (_inLexique COMMA_THERE, inIndentation + 1)
           << with_memoryprotection.reader_description  (_inLexique COMMA_THERE, inIndentation + 1)
           << with_systemcall.reader_description  (_inLexique COMMA_THERE, inIndentation + 1)
           << with_errorhook.reader_description  (_inLexique COMMA_THERE, inIndentation + 1)
           << with_startuphook.reader_description  (_inLexique COMMA_THERE, inIndentation + 1)
           << with_shutdownhook.reader_description  (_inLexique COMMA_THERE, inIndentation + 1)
           << with_pretaskhook.reader_description  (_inLexique COMMA_THERE, inIndentation + 1)
           << with_postaskhook.reader_description  (_inLexique COMMA_THERE, inIndentation + 1)
           << with_protectionhook.reader_description  (_inLexique COMMA_THERE, inIndentation + 1)
           << with_trace.reader_description  (_inLexique COMMA_THERE, inIndentation + 1)
           << scalability_class.reader_description  (_inLexique COMMA_THERE, inIndentation + 1) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//                              Class message                                *
//                                                                           *
//---------------------------------------------------------------------------*

const char * cPtr_config::
_message (void) const {
  return "" ;
}

//---------------------------------------------------------------------------*

const char * cPtr_config::
_static_message (void) {
  return "" ;
}

//---------------------------------------------------------------------------*

C_galgas_class_inspector _gInspectorFor_config (& typeid (cPtr_config), NULL
, "") ;
//---------------------------------------------------------------------------*

AC_galgasClassRunTimeInformation * cPtr_config::galgasRTTI (void) const {
  return & gClassInfoFor__config ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//                        GALGAS class 'GGS_config'                          *
//                                                                           *
//---------------------------------------------------------------------------*

GGS_config::
GGS_config (cPtr__AC_galgas_class * inPointer) {
  macroAssignPointer (mPointer, inPointer) ;
}

//---------------------------------------------------------------------------*

GGS_config::
GGS_config (cPtr__AC_galgas_class & inObject) {
  macroAssignPointer (mPointer, & inObject) ;
}

//---------------------------------------------------------------------------*

//--- _castFrom class method (implements cast expression)
GGS_config GGS_config::
_castFrom (C_Compiler & inLexique,
           cPtr__AC_galgas_class * inPointer,
           const bool inUseKindOfClass,
           const GGS_location & inErrorLocation
           COMMA_LOCATION_ARGS) {
  GGS_config _result ;
  if (inPointer != NULL) {
    macroValidPointer (inPointer) ;
    const bool ok = inUseKindOfClass
      ? (dynamic_cast <cPtr_config *> (inPointer) != NULL)
      : (typeid (cPtr_config) == typeid (*inPointer)) ;
    if (ok) {
      _result = GGS_config (inPointer) ;
    }else{
      inErrorLocation.signalCastError (inLexique,
                                       & typeid (cPtr_config),
                                       inUseKindOfClass,
                                       inPointer->_message ()
                                       COMMA_THERE) ;
    }
  }
  return _result ;
}

//---------------------------------------------------------------------------*

GGS_config GGS_config::
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
                 const GGS_uint & argument_16
                                COMMA_LOCATION_ARGS) {
  GGS_config result ;
  macroMyNew (result.mPointer, cPtr_config (argument_0,
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
                                argument_16 COMMA_THERE)) ;
  return result ;
}

//---------------------------------------------------------------------------*

GGS_bool GGS_config::
reader_with_compilersettings (C_Compiler & /* inLexique */ COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_bool  result ;
  if (mPointer != NULL) {
    macroValidPointer (mPointer) ;
    MF_Assert (dynamic_cast <cPtr_config *> (mPointer) != NULL,
               "dynamic cast error", 0, 0) ;
    result = ((cPtr_config *) mPointer)->with_compilersettings ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GGS_bool GGS_config::
reader_with_memmap (C_Compiler & /* inLexique */ COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_bool  result ;
  if (mPointer != NULL) {
    macroValidPointer (mPointer) ;
    MF_Assert (dynamic_cast <cPtr_config *> (mPointer) != NULL,
               "dynamic cast error", 0, 0) ;
    result = ((cPtr_config *) mPointer)->with_memmap ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GGS_bool GGS_config::
reader_with_com (C_Compiler & /* inLexique */ COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_bool  result ;
  if (mPointer != NULL) {
    macroValidPointer (mPointer) ;
    MF_Assert (dynamic_cast <cPtr_config *> (mPointer) != NULL,
               "dynamic cast error", 0, 0) ;
    result = ((cPtr_config *) mPointer)->with_com ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GGS_bool GGS_config::
reader_with_autosar (C_Compiler & /* inLexique */ COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_bool  result ;
  if (mPointer != NULL) {
    macroValidPointer (mPointer) ;
    MF_Assert (dynamic_cast <cPtr_config *> (mPointer) != NULL,
               "dynamic cast error", 0, 0) ;
    result = ((cPtr_config *) mPointer)->with_autosar ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GGS_bool GGS_config::
reader_with_osapplication (C_Compiler & /* inLexique */ COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_bool  result ;
  if (mPointer != NULL) {
    macroValidPointer (mPointer) ;
    MF_Assert (dynamic_cast <cPtr_config *> (mPointer) != NULL,
               "dynamic cast error", 0, 0) ;
    result = ((cPtr_config *) mPointer)->with_osapplication ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GGS_bool GGS_config::
reader_with_timingprotection (C_Compiler & /* inLexique */ COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_bool  result ;
  if (mPointer != NULL) {
    macroValidPointer (mPointer) ;
    MF_Assert (dynamic_cast <cPtr_config *> (mPointer) != NULL,
               "dynamic cast error", 0, 0) ;
    result = ((cPtr_config *) mPointer)->with_timingprotection ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GGS_bool GGS_config::
reader_with_stackmonitoring (C_Compiler & /* inLexique */ COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_bool  result ;
  if (mPointer != NULL) {
    macroValidPointer (mPointer) ;
    MF_Assert (dynamic_cast <cPtr_config *> (mPointer) != NULL,
               "dynamic cast error", 0, 0) ;
    result = ((cPtr_config *) mPointer)->with_stackmonitoring ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GGS_bool GGS_config::
reader_with_memoryprotection (C_Compiler & /* inLexique */ COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_bool  result ;
  if (mPointer != NULL) {
    macroValidPointer (mPointer) ;
    MF_Assert (dynamic_cast <cPtr_config *> (mPointer) != NULL,
               "dynamic cast error", 0, 0) ;
    result = ((cPtr_config *) mPointer)->with_memoryprotection ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GGS_bool GGS_config::
reader_with_systemcall (C_Compiler & /* inLexique */ COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_bool  result ;
  if (mPointer != NULL) {
    macroValidPointer (mPointer) ;
    MF_Assert (dynamic_cast <cPtr_config *> (mPointer) != NULL,
               "dynamic cast error", 0, 0) ;
    result = ((cPtr_config *) mPointer)->with_systemcall ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GGS_bool GGS_config::
reader_with_errorhook (C_Compiler & /* inLexique */ COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_bool  result ;
  if (mPointer != NULL) {
    macroValidPointer (mPointer) ;
    MF_Assert (dynamic_cast <cPtr_config *> (mPointer) != NULL,
               "dynamic cast error", 0, 0) ;
    result = ((cPtr_config *) mPointer)->with_errorhook ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GGS_bool GGS_config::
reader_with_startuphook (C_Compiler & /* inLexique */ COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_bool  result ;
  if (mPointer != NULL) {
    macroValidPointer (mPointer) ;
    MF_Assert (dynamic_cast <cPtr_config *> (mPointer) != NULL,
               "dynamic cast error", 0, 0) ;
    result = ((cPtr_config *) mPointer)->with_startuphook ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GGS_bool GGS_config::
reader_with_shutdownhook (C_Compiler & /* inLexique */ COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_bool  result ;
  if (mPointer != NULL) {
    macroValidPointer (mPointer) ;
    MF_Assert (dynamic_cast <cPtr_config *> (mPointer) != NULL,
               "dynamic cast error", 0, 0) ;
    result = ((cPtr_config *) mPointer)->with_shutdownhook ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GGS_bool GGS_config::
reader_with_pretaskhook (C_Compiler & /* inLexique */ COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_bool  result ;
  if (mPointer != NULL) {
    macroValidPointer (mPointer) ;
    MF_Assert (dynamic_cast <cPtr_config *> (mPointer) != NULL,
               "dynamic cast error", 0, 0) ;
    result = ((cPtr_config *) mPointer)->with_pretaskhook ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GGS_bool GGS_config::
reader_with_postaskhook (C_Compiler & /* inLexique */ COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_bool  result ;
  if (mPointer != NULL) {
    macroValidPointer (mPointer) ;
    MF_Assert (dynamic_cast <cPtr_config *> (mPointer) != NULL,
               "dynamic cast error", 0, 0) ;
    result = ((cPtr_config *) mPointer)->with_postaskhook ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GGS_bool GGS_config::
reader_with_protectionhook (C_Compiler & /* inLexique */ COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_bool  result ;
  if (mPointer != NULL) {
    macroValidPointer (mPointer) ;
    MF_Assert (dynamic_cast <cPtr_config *> (mPointer) != NULL,
               "dynamic cast error", 0, 0) ;
    result = ((cPtr_config *) mPointer)->with_protectionhook ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GGS_bool GGS_config::
reader_with_trace (C_Compiler & /* inLexique */ COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_bool  result ;
  if (mPointer != NULL) {
    macroValidPointer (mPointer) ;
    MF_Assert (dynamic_cast <cPtr_config *> (mPointer) != NULL,
               "dynamic cast error", 0, 0) ;
    result = ((cPtr_config *) mPointer)->with_trace ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GGS_uint  GGS_config::
reader_scalability_class (C_Compiler & /* inLexique */ COMMA_UNUSED_LOCATION_ARGS) const {
  GGS_uint   result ;
  if (mPointer != NULL) {
    macroValidPointer (mPointer) ;
    MF_Assert (dynamic_cast <cPtr_config *> (mPointer) != NULL,
               "dynamic cast error", 0, 0) ;
    result = ((cPtr_config *) mPointer)->scalability_class ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

const char * GGS_config::actualTypeName (void) const {
  return "config" ;
}

//---------------------------------------------------------------------------*

AC_galgasClassRunTimeInformation * GGS_config::_galgasObjectRunTimeInfo (void) const {
  AC_galgasClassRunTimeInformation * result = NULL ;
  if (mPointer != NULL) {
    result = mPointer->galgasRTTI () ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

C_galgasRootClassRunTimeInformation gClassInfoFor__config ("config") ;

//---------------------------------------------------------------------------*

