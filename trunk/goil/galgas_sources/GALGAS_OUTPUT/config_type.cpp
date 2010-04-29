//---------------------------------------------------------------------------*
//                                                                           *
//                          File 'config_type.cpp'                           *
//                       Generated by version 1.9.11                         *
//                      april 29th, 2010, at 10h36'54"                       *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

//---------------------------------------------------------------------------*

#include "version_libpm.h"
#if CURRENT_LIBPM_VERSION != 725
  #error "This file has been compiled with a version of GALGAS that uses libpm version 725, different than the current version (CURRENT_LIBPM_VERSION) of libpm"
#endif

//---------------------------------------------------------------------------*

#include <typeinfo>
#include "utilities/MF_MemoryControl.h"
#include "files/C_TextFileWrite.h"
#include "galgas/C_galgas_CLI_Options.h"
#include "config_type.h"

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define SOURCE_FILE_AT_LINE(line) "config_type.gSemantics", line
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
    macroValidObjectThere (mPointer, cPtr_os_config) ;
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
  const GGS_bool cond_1247 = with_compilersettings ;
  if (cond_1247.isBuiltAndTrue ()) {
    var_cas_res.appendCString ("#define WITH_COMPILER_SETTINGS            YES\n") ;
  }else if (cond_1247.isBuiltAndFalse ()) {
    var_cas_res.appendCString ("#define WITH_COMPILER_SETTINGS            NO\n") ;
  }
  const GGS_bool cond_1412 = with_memmap ;
  if (cond_1412.isBuiltAndTrue ()) {
    var_cas_res.appendCString ("#define WITH_MEMMAP                       YES\n") ;
  }else if (cond_1412.isBuiltAndFalse ()) {
    var_cas_res.appendCString ("#define WITH_MEMMAP                       NO\n") ;
  }
  const GGS_bool cond_1574 = with_com ;
  if (cond_1574.isBuiltAndTrue ()) {
    var_cas_res.appendCString ("#define WITH_COM                          YES\n") ;
  }else if (cond_1574.isBuiltAndFalse ()) {
    var_cas_res.appendCString ("#define WITH_COM                          NO\n") ;
  }
  const GGS_bool cond_1740 = with_autosar ;
  if (cond_1740.isBuiltAndTrue ()) {
    var_cas_res.appendCString ("#define WITH_AUTOSAR                      YES\n") ;
  }else if (cond_1740.isBuiltAndFalse ()) {
    var_cas_res.appendCString ("#define WITH_AUTOSAR                      NO\n") ;
  }
  const GGS_bool cond_1912 = with_osapplication ;
  if (cond_1912.isBuiltAndTrue ()) {
    var_cas_res.appendCString ("#define WITH_OSAPPLICATION                YES\n") ;
  }else if (cond_1912.isBuiltAndFalse ()) {
    var_cas_res.appendCString ("#define WITH_OSAPPLICATION                NO\n") ;
  }
  const GGS_bool cond_2087 = with_timingprotection ;
  if (cond_2087.isBuiltAndTrue ()) {
    var_cas_res.appendCString ("#define WITH_AUTOSAR_TIMING_PROTECTION    YES\n") ;
  }else if (cond_2087.isBuiltAndFalse ()) {
    var_cas_res.appendCString ("#define WITH_AUTOSAR_TIMING_PROTECTION    NO\n") ;
  }
  const GGS_bool cond_2261 = with_stackmonitoring ;
  if (cond_2261.isBuiltAndTrue ()) {
    var_cas_res.appendCString ("#define WITH_AUTOSAR_STACK_MONITORING     YES\n") ;
  }else if (cond_2261.isBuiltAndFalse ()) {
    var_cas_res.appendCString ("#define WITH_AUTOSAR_STACK_MONITORING     NO\n") ;
  }
  const GGS_bool cond_2436 = with_memoryprotection ;
  if (cond_2436.isBuiltAndTrue ()) {
    var_cas_res.appendCString ("#define WITH_MEMORY_PROTECTION            YES\n") ;
  }else if (cond_2436.isBuiltAndFalse ()) {
    var_cas_res.appendCString ("#define WITH_MEMORY_PROTECTION            NO\n") ;
  }
  const GGS_bool cond_2605 = with_systemcall ;
  if (cond_2605.isBuiltAndTrue ()) {
    var_cas_res.appendCString ("#define WITH_SYSTEM_CALL                  YES\n") ;
  }else if (cond_2605.isBuiltAndFalse ()) {
    var_cas_res.appendCString ("#define WITH_SYSTEM_CALL                  NO\n") ;
  }
  const GGS_bool cond_2773 = with_errorhook ;
  if (cond_2773.isBuiltAndTrue ()) {
    var_cas_res.appendCString ("#define WITH_ERROR_HOOK                   YES\n") ;
  }else if (cond_2773.isBuiltAndFalse ()) {
    var_cas_res.appendCString ("#define WITH_ERROR_HOOK                   NO\n") ;
  }
  const GGS_bool cond_2943 = with_startuphook ;
  if (cond_2943.isBuiltAndTrue ()) {
    var_cas_res.appendCString ("#define WITH_STARTUP_HOOK                 YES\n") ;
  }else if (cond_2943.isBuiltAndFalse ()) {
    var_cas_res.appendCString ("#define WITH_STARTUP_HOOK                 NO\n") ;
  }
  const GGS_bool cond_3114 = with_shutdownhook ;
  if (cond_3114.isBuiltAndTrue ()) {
    var_cas_res.appendCString ("#define WITH_SHUTDOWN_HOOK                YES\n") ;
  }else if (cond_3114.isBuiltAndFalse ()) {
    var_cas_res.appendCString ("#define WITH_SHUTDOWN_HOOK                NO\n") ;
  }
  const GGS_bool cond_3284 = with_pretaskhook ;
  if (cond_3284.isBuiltAndTrue ()) {
    var_cas_res.appendCString ("#define WITH_PRE_TASK_HOOK                YES\n") ;
  }else if (cond_3284.isBuiltAndFalse ()) {
    var_cas_res.appendCString ("#define WITH_PRE_TASK_HOOK                NO\n") ;
  }
  const GGS_bool cond_3454 = with_postaskhook ;
  if (cond_3454.isBuiltAndTrue ()) {
    var_cas_res.appendCString ("#define WITH_POST_TASK_HOOK               YES\n") ;
  }else if (cond_3454.isBuiltAndFalse ()) {
    var_cas_res.appendCString ("#define WITH_POST_TASK_HOOK               NO\n") ;
  }
  const GGS_bool cond_3627 = with_protectionhook ;
  if (cond_3627.isBuiltAndTrue ()) {
    var_cas_res.appendCString ("#define WITH_PROTECTION_HOOK              YES\n") ;
  }else if (cond_3627.isBuiltAndFalse ()) {
    var_cas_res.appendCString ("#define WITH_PROTECTION_HOOK              NO\n") ;
  }
  const GGS_bool cond_3791 = with_trace ;
  if (cond_3791.isBuiltAndTrue ()) {
    var_cas_res.appendCString ("#define WITH_TRACE                        YES\n") ;
  }else if (cond_3791.isBuiltAndFalse ()) {
    var_cas_res.appendCString ("#define WITH_TRACE                        NO\n") ;
  }
  var_cas_res.appendCString ("#define SCALABILITY_CLASS                 ") ;
  var_cas_res.dotAssign_operation (scalability_class.reader_string (inLexique COMMA_SOURCE_FILE_AT_LINE (135))) ;
}

//---------------------------------------------------------------------------*

void cPtr_os_config::
appendForDescription (C_String & ioString,
                      const PMSInt32 inIndentation) const {
  ioString << "->@os_config:"
           << with_compilersettings.reader_description (inIndentation + 1)
           << with_memmap.reader_description (inIndentation + 1)
           << with_com.reader_description (inIndentation + 1)
           << with_autosar.reader_description (inIndentation + 1)
           << with_osapplication.reader_description (inIndentation + 1)
           << with_timingprotection.reader_description (inIndentation + 1)
           << with_stackmonitoring.reader_description (inIndentation + 1)
           << with_memoryprotection.reader_description (inIndentation + 1)
           << with_systemcall.reader_description (inIndentation + 1)
           << with_errorhook.reader_description (inIndentation + 1)
           << with_startuphook.reader_description (inIndentation + 1)
           << with_shutdownhook.reader_description (inIndentation + 1)
           << with_pretaskhook.reader_description (inIndentation + 1)
           << with_postaskhook.reader_description (inIndentation + 1)
           << with_protectionhook.reader_description (inIndentation + 1)
           << with_trace.reader_description (inIndentation + 1)
           << with_it_table.reader_description (inIndentation + 1)
           << scalability_class.reader_description (inIndentation + 1) ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//                              Class message                                *
//                                                                           *
//---------------------------------------------------------------------------*

const char * cPtr_os_config::
instanceMessage (void) const {
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

AC_galgasClassRunTimeInformationEX * cPtr_os_config::galgasRTTI (void) const {
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

const C_galgas_type_descriptorEX kTypeDescriptor_GGS_os_config ("os_config", true, NULL) ;

//---------------------------------------------------------------------------*

GGS_os_config::
GGS_os_config (const cPtr__AC_galgas_class * inPointer) {
  macroAssignObject (mPointer, (cPtr__AC_galgas_class *) inPointer) ;
}

//---------------------------------------------------------------------------*

GGS_os_config::
GGS_os_config (cPtr__AC_galgas_class & inObject) {
  macroAssignObject (mPointer, & inObject) ;
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
                                       inPointer->instanceMessage ()
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
  macroRetainObject (result.mPointer) ;
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

AC_galgasClassRunTimeInformationEX * GGS_os_config::galgasObjectRunTimeInfo (void) const {
  AC_galgasClassRunTimeInformationEX * result = NULL ;
  if (mPointer != NULL) {
    result = mPointer->galgasRTTI () ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

C_galgasRootClassRunTimeInformationEX gClassInfoFor__os_config ("os_config", & kTypeDescriptor_GGS_os_config) ;

//---------------------------------------------------------------------------*

GGS_object GGS_os_config::reader_object (void) const {
  GGS_object result ;
  if (isBuilt ()) {
    GGS_os_config * p = NULL ;
    macroMyNew (p, GGS_os_config (*this)) ;
    result = GGS_object (p) ;
  }
  return result ;
}

//---------------------------------------------------------------------------*

GGS_os_config GGS_os_config::castFromObject (C_Compiler & inLexique,
                                   const GGS_object & inObject,
                                   const GGS_location & inErrorLocation
                                   COMMA_LOCATION_ARGS) {
  GGS_os_config result ;
  const GGS__root * embeddedObject = inObject.embeddedObject () ;
  if (NULL != embeddedObject) {
    const GGS_os_config * p = dynamic_cast <const GGS_os_config *> (embeddedObject) ;
    if (NULL != p) {
      result = * p ;
    }else{
      castFromObjectErrorSignaling (inLexique, inErrorLocation, & kTypeDescriptor_GGS_os_config, embeddedObject COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*

const C_galgas_type_descriptorEX * GGS_os_config::typeDescriptor (void) const {
  return & kTypeDescriptor_GGS_os_config ;
}

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
  GGS_bool var_cas_itt = gOption_goil_5F_options_posix_5F_it.reader_value () ;
  GGS_bool var_cas_tp = GGS_bool (false) ;
  {
    GGS_task_map::cEnumerator enumerator_4268 (var_cas_cpu.reader_tasks (inLexique COMMA_SOURCE_FILE_AT_LINE (154)), true) ;
    const GGS_task_map::cElement * operand_4268 = NULL ;
    while (((operand_4268 = enumerator_4268.nextObject ()))) {
      macroValidPointer (operand_4268) ;
      { const GGS_timing_prot _var_4368 = operand_4268->mInfo.task.reader_timing_prot (inLexique COMMA_SOURCE_FILE_AT_LINE (155)) ; // CAST instruction
        if (_var_4368.getPtr () != NULL) {
          macroValidPointer (_var_4368.getPtr ()) ;
          if (typeid (cPtr_timing_prot_task) == typeid (* (_var_4368.getPtr ()))) {
            var_cas_tp = GGS_bool (true) ;
          }else{
          }
        }
      }
    }
  }
  {
    GGS_isr_map::cEnumerator enumerator_4401 (var_cas_cpu.reader_isrs (inLexique COMMA_SOURCE_FILE_AT_LINE (159)), true) ;
    const GGS_isr_map::cElement * operand_4401 = NULL ;
    while (((operand_4401 = enumerator_4401.nextObject ()))) {
      macroValidPointer (operand_4401) ;
      { const GGS_timing_prot _var_4498 = operand_4401->mInfo.isr.reader_timing_prot (inLexique COMMA_SOURCE_FILE_AT_LINE (160)) ; // CAST instruction
        if (_var_4498.getPtr () != NULL) {
          macroValidPointer (_var_4498.getPtr ()) ;
          if (typeid (cPtr_timing_prot_isr) == typeid (* (_var_4498.getPtr ()))) {
            var_cas_tp = GGS_bool (true) ;
          }else{
          }
        }
      }
    }
  }
  var_cas_cfg = GGS_os_config ::constructor_new (inLexique, GGS_bool (false), GGS_bool (false), GGS_bool (false), GGS_bool (false), GGS_bool (false), var_cas_tp, GGS_bool (false), GGS_bool (false), GGS_bool (false), GGS_bool (false), GGS_bool (false), GGS_bool (false), GGS_bool (false), GGS_bool (false), GGS_bool (false), GGS_bool (false), var_cas_itt, GGS_uint (1U) COMMA_SOURCE_FILE_AT_LINE (165)) ;
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE function_os_cfg\n") ;
  #endif
  return var_cas_cfg ;
}

//---------------------------------------------------------------------------*

static GGS_object functionForGenericCall_os_cfg (C_Compiler & inLexique,
                           const GGS_objectlist & inEffectiveParameterArray,
                           const GGS_location & inErrorLocation
                           COMMA_LOCATION_ARGS) {
  const GGS_root_obj  arg_0 = GGS_root_obj ::castFromObject (inLexique, inEffectiveParameterArray.reader_mValueAtIndex (inLexique, GGS_uint (0) COMMA_THERE), inErrorLocation COMMA_THERE) ;
  const GGS_os_config  result = function_os_cfg (inLexique,
                            arg_0
                            COMMA_THERE) ;
  return result.reader_object () ;
}

//---------------------------------------------------------------------------*

static const C_galgas_type_descriptorEX *
kArgumentTypeList_os_cfg [1] = {& kTypeDescriptor_GGS_root_obj } ;

const C_galgas_function_descriptorEX
kFunction_descriptor_os_cfg ("os_cfg",
                              functionForGenericCall_os_cfg,
                              & kTypeDescriptor_GGS_os_config ,
                              1,
                              kArgumentTypeList_os_cfg) ;

//---------------------------------------------------------------------------*

