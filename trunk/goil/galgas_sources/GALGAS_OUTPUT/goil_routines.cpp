//---------------------------------------------------------------------------*
//                                                                           *
//                         File 'goil_routines.cpp'                          *
//                        Generated by version 1.8.1                         *
//                      april 20th, 2009, at 17h2'26"                        *
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
#include "goil_routines.h"

//---------------------------------------------------------------------------*

#ifndef DO_NOT_GENERATE_CHECKINGS
  #define SOURCE_FILE_AT_LINE(line) "goil_routines.ggs", line
  #define COMMA_SOURCE_FILE_AT_LINE(line) , SOURCE_FILE_AT_LINE(line)
#else
  #define SOURCE_FILE_AT_LINE(line) 
  #define COMMA_SOURCE_FILE_AT_LINE(line) 
#endif


//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

//---------------------------------------------------------------------------*
//                                                                           *
//                    Implementation of routine "target"                     *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_target (C_Compiler & _inLexique,
                                GGS_string & var_cas_target_platform COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_target at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  var_cas_target_platform = GGS_string (true, _inLexique.stringOptionValueFromKeys ("goil_options", "target_platform" COMMA_SOURCE_FILE_AT_LINE (7))) ;
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_target\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//                     Implementation of routine "arch"                      *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_arch (C_Compiler & _inLexique,
                                GGS_string & var_cas_arch_name COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_arch at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  GGS_stringlist  var_cas_components ;
  var_cas_components = GGS_string (true, _inLexique.stringOptionValueFromKeys ("goil_options", "target_platform" COMMA_SOURCE_FILE_AT_LINE (13))).reader_componentsSeparatedByString (_inLexique, GGS_string (true, "/") COMMA_SOURCE_FILE_AT_LINE (13)) ;
  const GGS_stringlist  _temp_482 = var_cas_components ;
  if (_temp_482._isBuilt ()) {
    _temp_482 (HERE)->method_first (_inLexique, var_cas_arch_name COMMA_SOURCE_FILE_AT_LINE (14)) ;
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_arch\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//             Implementation of routine "templates_directory"               *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_templates_directory (C_Compiler & _inLexique,
                                GGS_string & var_cas_temp_dir COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_templates_directory at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  var_cas_temp_dir = GGS_string (true, "") ;
  if (((GGS_string (true, _inLexique.stringOptionValueFromKeys ("goil_options", "template_dir" COMMA_SOURCE_FILE_AT_LINE (20))))._operator_isNotEqual (GGS_string (true, ""))).isBuiltAndTrue ()) {
    var_cas_temp_dir = GGS_string (true, _inLexique.stringOptionValueFromKeys ("goil_options", "template_dir" COMMA_SOURCE_FILE_AT_LINE (21))) ;
  }else{
    var_cas_temp_dir = GGS_string::constructor_stringWithEnvironmentVariableOrEmpty (_inLexique, GGS_string (true, "GOIL_TEMPLATES") COMMA_HERE) ;
  }
  if (((var_cas_temp_dir)._operator_isNotEqual (GGS_string (true, ""))).isBuiltAndTrue ()) {
    var_cas_temp_dir = var_cas_temp_dir.reader_unixPathWithNativePath (_inLexique COMMA_SOURCE_FILE_AT_LINE (27)) ;
    if (((var_cas_temp_dir.reader_characterAtIndex (_inLexique, GGS_uint (true, 0U) COMMA_SOURCE_FILE_AT_LINE (29)))._operator_isNotEqual (GGS_char (true, '/'))).isBuiltAndTrue ()) {
      GGS_string var_cas_curdir ;
      var_cas_curdir = GGS_string::constructor_stringWithCurrentDirectory (_inLexique COMMA_HERE) ;
      if ((((var_cas_temp_dir.reader_characterAtIndex (_inLexique, GGS_uint (true, 0U) COMMA_SOURCE_FILE_AT_LINE (31)))._operator_isEqual (GGS_char (true, '.')))._operator_and ((var_cas_temp_dir.reader_characterAtIndex (_inLexique, GGS_uint (true, 1U) COMMA_SOURCE_FILE_AT_LINE (31)))._operator_isEqual (GGS_char (true, '/')))).isBuiltAndTrue ()) {
        var_cas_temp_dir = var_cas_temp_dir.reader_stringByRemovingCharacterAtIndex (_inLexique, GGS_uint (true, 0U) COMMA_SOURCE_FILE_AT_LINE (32)).reader_stringByRemovingCharacterAtIndex (_inLexique, GGS_uint (true, 0U) COMMA_SOURCE_FILE_AT_LINE (32)) ;
      }
      var_cas_temp_dir = ((var_cas_curdir)._operator_concat (GGS_string (true, "/")))._operator_concat (var_cas_temp_dir) ;
    }
    if (((var_cas_temp_dir.reader_characterAtIndex (_inLexique, var_cas_temp_dir.reader_length (_inLexique COMMA_SOURCE_FILE_AT_LINE (36))._substract_operation (_inLexique, GGS_uint (true, 1U) COMMA_SOURCE_FILE_AT_LINE (36)) COMMA_SOURCE_FILE_AT_LINE (36)))._operator_isNotEqual (GGS_char (true, '/'))).isBuiltAndTrue ()) {
      var_cas_temp_dir.appendCstring ("/") ;
    }
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_templates_directory\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//        Implementation of routine "retrieveTemplateStringIfExist"          *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_retrieveTemplateStringIfExist (C_Compiler & _inLexique,
                                GGS_string & var_cas_templateString,
                                GGS_string  var_cas_obj COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_retrieveTemplateStringIfExist at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  GGS_string var_cas_target_platform ;
  GGS_string var_cas_targ_tpl ;
  var_cas_targ_tpl = GGS_string (true, "") ;
  ::routine_target (_inLexique,  var_cas_target_platform COMMA_SOURCE_FILE_AT_LINE (50)) ;
  GGS_string var_cas_temp_dir ;
  ::routine_templates_directory (_inLexique,  var_cas_temp_dir COMMA_SOURCE_FILE_AT_LINE (54)) ;
  var_cas_targ_tpl = ((((var_cas_temp_dir)._operator_concat (var_cas_target_platform))._operator_concat (GGS_string (true, "/")))._operator_concat (var_cas_obj))._operator_concat (GGS_string (true, ".tpl")) ;
  if ((var_cas_targ_tpl.reader_fileExists (_inLexique COMMA_SOURCE_FILE_AT_LINE (59))).isBuiltAndTrue ()) {
    var_cas_templateString = GGS_string::constructor_stringWithContentsOfFile (_inLexique, var_cas_targ_tpl COMMA_HERE) ;
  }else{
    var_cas_targ_tpl = (((var_cas_temp_dir)._operator_concat (GGS_string (true, "all_targets/")))._operator_concat (var_cas_obj))._operator_concat (GGS_string (true, ".tpl")) ;
    if ((var_cas_targ_tpl.reader_fileExists (_inLexique COMMA_SOURCE_FILE_AT_LINE (64))).isBuiltAndTrue ()) {
      var_cas_templateString = GGS_string::constructor_stringWithContentsOfFile (_inLexique, var_cas_targ_tpl COMMA_HERE) ;
    }else{
      var_cas_templateString = GGS_string (true, "") ;
    }
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_retrieveTemplateStringIfExist\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//            Implementation of routine "retrieveTemplateString"             *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_retrieveTemplateString (C_Compiler & _inLexique,
                                GGS_string & var_cas_templateString,
                                GGS_string  var_cas_obj COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_retrieveTemplateString at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  ::routine_retrieveTemplateStringIfExist (_inLexique,  var_cas_templateString,  var_cas_obj COMMA_SOURCE_FILE_AT_LINE (74)) ;
  if (((var_cas_templateString)._operator_isEqual (GGS_string (true, ""))).isBuiltAndTrue ()) {
    GGS_string var_cas_target_platform ;
    ::routine_target (_inLexique,  var_cas_target_platform COMMA_SOURCE_FILE_AT_LINE (77)) ;
    GGS_string var_cas_temp_dir ;
    ::routine_templates_directory (_inLexique,  var_cas_temp_dir COMMA_SOURCE_FILE_AT_LINE (79)) ;
    GGS_location (_inLexique).reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, (((((((GGS_string (true, "No template found for "))._operator_concat (var_cas_obj))._operator_concat (GGS_string (true, " (searched in ")))._operator_concat (var_cas_temp_dir))._operator_concat (var_cas_target_platform))._operator_concat (GGS_string (true, " and in ")))._operator_concat (var_cas_temp_dir))._operator_concat (GGS_string (true, "all_targets)")) COMMA_SOURCE_FILE_AT_LINE (82)) ;
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_retrieveTemplateString\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//                 Implementation of routine "config_file"                   *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_config_file (C_Compiler & _inLexique,
                                GGS_lstring  & var_cas_cfg_file COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_config_file at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  GGS_string var_cas_template_dir ;
  ::routine_templates_directory (_inLexique,  var_cas_template_dir COMMA_SOURCE_FILE_AT_LINE (89)) ;
  GGS_string var_cas_target_platform ;
  ::routine_target (_inLexique,  var_cas_target_platform COMMA_SOURCE_FILE_AT_LINE (91)) ;
  GGS_string var_cas_cfg ;
  var_cas_cfg = ((var_cas_template_dir)._operator_concat (var_cas_target_platform))._operator_concat (GGS_string (true, "/target.cfg")) ;
  if (((var_cas_cfg.reader_fileExists (_inLexique COMMA_SOURCE_FILE_AT_LINE (93)))._operator_not ()).isBuiltAndTrue ()) {
    var_cas_cfg = GGS_string (true, "") ;
  }
  var_cas_cfg_file = GGS_lstring ::constructor_new (_inLexique, var_cas_cfg, GGS_location (_inLexique) COMMA_HERE) ;
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_config_file\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//                    Implementation of routine "prefix"                     *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_prefix (C_Compiler & _inLexique,
                                GGS_prefix_map   var_cas_p,
                                GGS_string  var_cas_key,
                                GGS_string & var_cas_val COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_prefix at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  GGS_lstring  var_cas_lkey ;
  var_cas_lkey = GGS_lstring ::constructor_new (_inLexique, var_cas_key, GGS_location (_inLexique) COMMA_HERE) ;
  GGS_string automatic_var_0 ;
  const GGS_prefix_map  _temp_3426 = var_cas_p ;
  if (_temp_3426._isBuilt ()) {
    _temp_3426 (HERE)->method_prefix (_inLexique, var_cas_lkey, var_cas_val, automatic_var_0 COMMA_SOURCE_FILE_AT_LINE (101)) ;
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_prefix\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//                Implementation of routine "performReplace"                 *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_performReplace (C_Compiler & _inLexique,
                                GGS_prefix_map   var_cas_p,
                                GGS_string  var_cas_key,
                                GGS_string  var_cas_name,
                                GGS_string & var_cas_res COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_performReplace at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  GGS_lstring  var_cas_lkey ;
  var_cas_lkey = GGS_lstring ::constructor_new (_inLexique, var_cas_key, GGS_location (_inLexique) COMMA_HERE) ;
  GGS_string var_cas_prefix ;
  GGS_string var_cas_tag_to_rep ;
  const GGS_prefix_map  _temp_3648 = var_cas_p ;
  if (_temp_3648._isBuilt ()) {
    _temp_3648 (HERE)->method_prefix (_inLexique, var_cas_lkey, var_cas_prefix, var_cas_tag_to_rep COMMA_SOURCE_FILE_AT_LINE (108)) ;
  }
  var_cas_res = var_cas_res.reader_stringByReplacingStringByString (_inLexique, var_cas_tag_to_rep, (var_cas_prefix)._operator_concat (var_cas_name) COMMA_SOURCE_FILE_AT_LINE (109)) ;
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_performReplace\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//                  Implementation of routine "doReplace"                    *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_doReplace (C_Compiler & _inLexique,
                                GGS_string & var_cas_s,
                                GGS_string  var_cas_o,
                                GGS_string  var_cas_n COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_doReplace at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  var_cas_s = var_cas_s.reader_stringByReplacingStringByString (_inLexique, var_cas_o, var_cas_n COMMA_SOURCE_FILE_AT_LINE (113)) ;
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_doReplace\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//              Implementation of routine "replace_no_prefix"                *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_replace_no_prefix (C_Compiler & _inLexique,
                                GGS_prefix_map   var_cas_p,
                                GGS_string  var_cas_key,
                                GGS_string  var_cas_name,
                                GGS_string & var_cas_res COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_replace_no_prefix at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  GGS_lstring  var_cas_lkey ;
  var_cas_lkey = GGS_lstring ::constructor_new (_inLexique, var_cas_key, GGS_location (_inLexique) COMMA_HERE) ;
  GGS_string var_cas_tag_to_rep ;
  GGS_string automatic_var_1 ;
  const GGS_prefix_map  _temp_4082 = var_cas_p ;
  if (_temp_4082._isBuilt ()) {
    _temp_4082 (HERE)->method_prefix (_inLexique, var_cas_lkey, automatic_var_1, var_cas_tag_to_rep COMMA_SOURCE_FILE_AT_LINE (120)) ;
  }
  var_cas_res = var_cas_res.reader_stringByReplacingStringByString (_inLexique, var_cas_tag_to_rep, var_cas_name COMMA_SOURCE_FILE_AT_LINE (121)) ;
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_replace_no_prefix\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//                  Implementation of routine "table_core"                   *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_table_core (C_Compiler & _inLexique,
                                GGS_string  var_cas_typename,
                                GGS_string  var_cas_varname,
                                GGS_string  var_cas_obj_prefix,
                                GGS_stringset   var_cas_names,
                                GGS_string & var_cas_header,
                                GGS_string & var_cas_implementation COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_table_core at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  GGS_uint  var_cas_n ;
  var_cas_n = GGS_uint (true, 0U) ;
  {
    GGS_stringset::cEnumerator enumerator_4564 (var_cas_names, true) ;
    while (enumerator_4564.hc ()) {
      var_cas_header = (((((((var_cas_header)._operator_concat (GGS_string (true, "#define ")))._operator_concat (var_cas_varname))._operator_concat (GGS_string (true, "_id_of_")))._operator_concat (enumerator_4564._key (HERE)))._operator_concat (GGS_string (true, "  ")))._operator_concat (var_cas_n.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (141))))._operator_concat (GGS_string (true, "\n")) ;
      var_cas_header = (((((((var_cas_header)._operator_concat (GGS_string (true, "#define ")))._operator_concat (enumerator_4564._key (HERE)))._operator_concat (GGS_string (true, "  ")))._operator_concat (var_cas_varname))._operator_concat (GGS_string (true, "_id_of_")))._operator_concat (enumerator_4564._key (HERE)))._operator_concat (GGS_string (true, "\n")) ;
      var_cas_implementation = (((((var_cas_implementation)._operator_concat (GGS_string (true, "    (tpl_")))._operator_concat (var_cas_typename))._operator_concat (GGS_string (true, " *)&")))._operator_concat (var_cas_obj_prefix))._operator_concat (enumerator_4564._key (HERE)) ;
      var_cas_n._increment_operation (_inLexique COMMA_SOURCE_FILE_AT_LINE (151)) ;
      if (((var_cas_n)._operator_isNotEqual (var_cas_names.reader_count (_inLexique COMMA_SOURCE_FILE_AT_LINE (152)))).isBuiltAndTrue ()) {
        var_cas_implementation = (var_cas_implementation)._operator_concat (GGS_string (true, ",\n")) ;
      }else{
        var_cas_implementation = (var_cas_implementation)._operator_concat (GGS_string (true, "\n")) ;
      }
      enumerator_4564.next () ;
    }
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_table_core\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//                  Implementation of routine "obj_table"                    *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_obj_table (C_Compiler & _inLexique,
                                GGS_string  var_cas_typename,
                                GGS_string  var_cas_varname,
                                GGS_string  var_cas_prefix,
                                GGS_prefix_map   var_cas_p,
                                GGS_stringset   var_cas_names,
                                GGS_string & var_cas_header,
                                GGS_string & var_cas_implementation COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_obj_table at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  var_cas_implementation = ((((((GGS_string (true, "tpl_"))._operator_concat (var_cas_typename))._operator_concat (GGS_string (true, " *tpl_")))._operator_concat (var_cas_varname))._operator_concat (GGS_string (true, "_table[")))._operator_concat (var_cas_varname.reader_uppercaseString (_inLexique COMMA_SOURCE_FILE_AT_LINE (171))))._operator_concat (GGS_string (true, "_COUNT] = {\n")) ;
  var_cas_header = GGS_string (true, "\n") ;
  GGS_string var_cas_obj_prefix ;
  GGS_string var_cas_obj_ids ;
  var_cas_obj_ids = GGS_string (true, "") ;
  ::routine_prefix (_inLexique,  var_cas_p,  var_cas_prefix,  var_cas_obj_prefix COMMA_SOURCE_FILE_AT_LINE (176)) ;
  ::routine_table_core (_inLexique,  var_cas_typename,  var_cas_varname,  var_cas_obj_prefix,  var_cas_names,  var_cas_header,  var_cas_implementation COMMA_SOURCE_FILE_AT_LINE (177)) ;
  var_cas_implementation = (var_cas_implementation)._operator_concat (GGS_string (true, "};\n")) ;
  if (((var_cas_names.reader_count (_inLexique COMMA_SOURCE_FILE_AT_LINE (180)))._operator_isEqual (GGS_uint (true, 0U))).isBuiltAndTrue ()) {
    var_cas_implementation = GGS_string (true, "") ;
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_obj_table\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//         Implementation of routine "additional_int_key_required"           *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_additional_int_key_required (C_Compiler & _inLexique,
                                const GGS_string  var_cas_key,
                                const GGS_ident_map   var_cas_others,
                                const GGS_lstring   var_cas_name,
                                GGS_uint  & var_cas_result COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_additional_int_key_required at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  var_cas_result = GGS_uint (true, 0U) ;
  if ((var_cas_others.reader_hasKey (_inLexique, var_cas_key COMMA_SOURCE_FILE_AT_LINE (192))).isBuiltAndTrue ()) {
    GGS_basic_type  var_cas_value ;
    const GGS_ident_map  _temp_6442 = var_cas_others ;
    if (_temp_6442._isBuilt ()) {
      _temp_6442 (HERE)->method_get (_inLexique, GGS_lstring ::constructor_new (_inLexique, var_cas_key, GGS_location (_inLexique) COMMA_HERE), var_cas_value COMMA_SOURCE_FILE_AT_LINE (194)) ;
    }
    { const GGS_basic_type _var_6929 = var_cas_value ; // CAST instruction
      if (_var_6929.getPtr () != NULL) {
        macroValidPointer (_var_6929.getPtr ()) ;
        if (typeid (cPtr_uint64_class) == typeid (* (_var_6929.getPtr ()))) {
          const GGS_uint64_class var_cas_v (_var_6929.getPtr ()) ;
          var_cas_result = var_cas_v.reader_value (_inLexique COMMA_SOURCE_FILE_AT_LINE (197)).reader_uint (_inLexique COMMA_SOURCE_FILE_AT_LINE (197)) ;
        }else if (typeid (cPtr_uint32_class) == typeid (* (_var_6929.getPtr ()))) {
          const GGS_uint32_class var_cas_v (_var_6929.getPtr ()) ;
          var_cas_result = var_cas_v.reader_value (_inLexique COMMA_SOURCE_FILE_AT_LINE (199)) ;
        }else if (typeid (cPtr_void_uint32_class) == typeid (* (_var_6929.getPtr ()))) {
          var_cas_name.reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, (var_cas_key)._operator_concat (GGS_string (true, " should have a default value")) COMMA_SOURCE_FILE_AT_LINE (202)) ;
        }else if (typeid (cPtr_auto_uint32_class) == typeid (* (_var_6929.getPtr ()))) {
          var_cas_name.reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, (var_cas_key)._operator_concat (GGS_string (true, " should not be an auto attribute")) COMMA_SOURCE_FILE_AT_LINE (204)) ;
        }else{
          var_cas_name.reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, (var_cas_key)._operator_concat (GGS_string (true, " should be an integer")) COMMA_SOURCE_FILE_AT_LINE (206)) ;
        }
      }
    }
  }else{
    var_cas_name.reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, (var_cas_key)._operator_concat (GGS_string (true, " not defined")) COMMA_SOURCE_FILE_AT_LINE (209)) ;
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_additional_int_key_required\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//        Implementation of routine "additional_string_key_required"         *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_additional_string_key_required (C_Compiler & _inLexique,
                                const GGS_string  var_cas_key,
                                const GGS_ident_map   var_cas_others,
                                const GGS_lstring   var_cas_name,
                                GGS_string & var_cas_result COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_additional_string_key_required at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  var_cas_result = GGS_string (true, "") ;
  if ((var_cas_others.reader_hasKey (_inLexique, var_cas_key COMMA_SOURCE_FILE_AT_LINE (219))).isBuiltAndTrue ()) {
    GGS_basic_type  var_cas_value ;
    const GGS_ident_map  _temp_7246 = var_cas_others ;
    if (_temp_7246._isBuilt ()) {
      _temp_7246 (HERE)->method_get (_inLexique, GGS_lstring ::constructor_new (_inLexique, var_cas_key, GGS_location (_inLexique) COMMA_HERE), var_cas_value COMMA_SOURCE_FILE_AT_LINE (222)) ;
    }
    { const GGS_basic_type _var_7451 = var_cas_value ; // CAST instruction
      if (_var_7451.getPtr () != NULL) {
        macroValidPointer (_var_7451.getPtr ()) ;
        if (typeid (cPtr_string_class) == typeid (* (_var_7451.getPtr ()))) {
          const GGS_string_class var_cas_s (_var_7451.getPtr ()) ;
          var_cas_result = var_cas_s.reader_value (_inLexique COMMA_SOURCE_FILE_AT_LINE (225)) ;
        }else{
          var_cas_name.reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, (var_cas_key)._operator_concat (GGS_string (true, " should be a string")) COMMA_SOURCE_FILE_AT_LINE (228)) ;
        }
      }
    }
  }else{
    var_cas_name.reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, ((GGS_string (true, "no "))._operator_concat (var_cas_key))._operator_concat (GGS_string (true, " specified")) COMMA_SOURCE_FILE_AT_LINE (231)) ;
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_additional_string_key_required\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//         Implementation of routine "additional_bool_key_required"          *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_additional_bool_key_required (C_Compiler & _inLexique,
                                const GGS_string  var_cas_key,
                                const GGS_ident_map   var_cas_others,
                                const GGS_lstring   var_cas_name,
                                GGS_bool & var_cas_result COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_additional_bool_key_required at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  var_cas_result = GGS_bool (true, false) ;
  if ((var_cas_others.reader_hasKey (_inLexique, var_cas_key COMMA_SOURCE_FILE_AT_LINE (241))).isBuiltAndTrue ()) {
    GGS_basic_type  var_cas_value ;
    const GGS_ident_map  _temp_7781 = var_cas_others ;
    if (_temp_7781._isBuilt ()) {
      _temp_7781 (HERE)->method_get (_inLexique, GGS_lstring ::constructor_new (_inLexique, var_cas_key, GGS_location (_inLexique) COMMA_HERE), var_cas_value COMMA_SOURCE_FILE_AT_LINE (244)) ;
    }
    { const GGS_basic_type _var_7985 = var_cas_value ; // CAST instruction
      if (_var_7985.getPtr () != NULL) {
        macroValidPointer (_var_7985.getPtr ()) ;
        if (typeid (cPtr_bool_class) == typeid (* (_var_7985.getPtr ()))) {
          const GGS_bool_class var_cas_b (_var_7985.getPtr ()) ;
          var_cas_result = var_cas_b.reader_value (_inLexique COMMA_SOURCE_FILE_AT_LINE (247)) ;
        }else{
          var_cas_name.reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, (var_cas_key)._operator_concat (GGS_string (true, " should be a boolean")) COMMA_SOURCE_FILE_AT_LINE (250)) ;
        }
      }
    }
  }else{
    var_cas_name.reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, ((GGS_string (true, "no "))._operator_concat (var_cas_key))._operator_concat (GGS_string (true, " specified")) COMMA_SOURCE_FILE_AT_LINE (253)) ;
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_additional_bool_key_required\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//               Implementation of routine "add_to_stringset"                *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_add_to_stringset (C_Compiler & _inLexique,
                                GGS_stringset  & var_cas_ss,
                                GGS_string  var_cas_new COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_add_to_stringset at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  if ((var_cas_ss.reader_hasKey (_inLexique, var_cas_new COMMA_SOURCE_FILE_AT_LINE (260))).isBuiltAndTrue ()) {
    GGS_location (_inLexique).reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, ((GGS_string (true, "'"))._operator_concat (var_cas_new))._operator_concat (GGS_string (true, "' is already declared before")) COMMA_SOURCE_FILE_AT_LINE (262)) ;
  }else{
    var_cas_ss._addAssign_operation (var_cas_new) ;
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_add_to_stringset\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//                 Implementation of routine "file_in_path"                  *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_file_in_path (C_Compiler & _inLexique,
                                GGS_lstring  & var_cas_file_name COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_file_in_path at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  GGS_string var_cas_include_path ;
  var_cas_include_path = GGS_string::constructor_stringWithEnvironmentVariable (_inLexique, GGS_string (true, "GOIL_INCLUDE_PATH") COMMA_HERE) ;
  GGS_stringlist  var_cas_path_list ;
  var_cas_path_list = var_cas_include_path.reader_componentsSeparatedByString (_inLexique, GGS_string (true, ":") COMMA_SOURCE_FILE_AT_LINE (271)) ;
  GGS_bool var_cas_not_found ;
  var_cas_not_found = GGS_bool (true, true) ;
  {
    GGS_stringlist::cEnumerator enumerator_8557 (var_cas_path_list, true) ;
    const GGS_stringlist::cElement * operand_8557 = NULL ;
    while (((operand_8557 = enumerator_8557.nextObject ()))) {
      macroValidPointer (operand_8557) ;
      GGS_string var_cas_full_file_path ;
      var_cas_full_file_path = operand_8557->mValue ;
      if (((var_cas_full_file_path)._operator_isNotEqual (GGS_string (true, ""))).isBuiltAndTrue ()) {
        if (((var_cas_full_file_path.reader_characterAtIndex (_inLexique, var_cas_full_file_path.reader_length (_inLexique COMMA_SOURCE_FILE_AT_LINE (276))._substract_operation (_inLexique, GGS_uint (true, 1U) COMMA_SOURCE_FILE_AT_LINE (276)) COMMA_SOURCE_FILE_AT_LINE (276)))._operator_isNotEqual (GGS_char (true, '/'))).isBuiltAndTrue ()) {
          var_cas_full_file_path.appendCstring ("/") ;
        }
      }
      var_cas_full_file_path._dotAssign_operation (var_cas_file_name.ggs_string ()) ;
      if (((var_cas_full_file_path.reader_fileExists (_inLexique COMMA_SOURCE_FILE_AT_LINE (281)))._operator_and (var_cas_not_found)).isBuiltAndTrue ()) {
        var_cas_file_name = GGS_lstring ::constructor_new (_inLexique, var_cas_full_file_path, GGS_location (_inLexique) COMMA_HERE) ;
        var_cas_not_found = GGS_bool (true, false) ;
      }
    }
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_file_in_path\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//              Implementation of routine "is_in_lstringlist"                *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_is_in_lstringlist (C_Compiler & _inLexique,
                                GGS_lstringlist   var_cas_l,
                                GGS_lstring   var_cas_e,
                                GGS_lstring  & var_cas_f,
                                GGS_bool & var_cas_p COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_is_in_lstringlist at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  var_cas_p = GGS_bool (true, false) ;
  var_cas_f = GGS_lstring ::constructor_new (_inLexique, GGS_string (true, ""), GGS_location (_inLexique) COMMA_HERE) ;
  {
    GGS_lstringlist::cEnumerator enumerator_9227 (var_cas_l, true) ;
    const GGS_lstringlist::cElement * operand_9227 = NULL ;
    while (((operand_9227 = enumerator_9227.nextObject ()))) {
      macroValidPointer (operand_9227) ;
      if (((operand_9227->mValue.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (297)))._operator_isEqual (var_cas_e.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (297)))).isBuiltAndTrue ()) {
        var_cas_p = GGS_bool (true, true) ;
        var_cas_f = operand_9227->mValue ;
      }
    }
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_is_in_lstringlist\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//              Implementation of routine "add_lstring_unique"               *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_add_lstring_unique (C_Compiler & _inLexique,
                                GGS_lstringlist  & var_cas_l,
                                GGS_lstring   var_cas_e,
                                GGS_string  var_cas_att COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_add_lstring_unique at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  GGS_bool var_cas_found ;
  GGS_lstring  var_cas_res ;
  ::routine_is_in_lstringlist (_inLexique,  var_cas_l,  var_cas_e,  var_cas_res,  var_cas_found COMMA_SOURCE_FILE_AT_LINE (311)) ;
  if ((var_cas_found).isBuiltAndTrue ()) {
    var_cas_e.reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, (((var_cas_att)._operator_concat (GGS_string (true, " ")))._operator_concat (var_cas_e.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (313))))._operator_concat (GGS_string (true, " has already be listed")) COMMA_SOURCE_FILE_AT_LINE (314)) ;
    var_cas_res.reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, GGS_string (true, "was listed here") COMMA_SOURCE_FILE_AT_LINE (315)) ;
  }else{
    var_cas_l._addAssign_operation (var_cas_e) ;
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_add_lstring_unique\n") ;
  #endif
}

//---------------------------------------------------------------------------*
//                                                                           *
//             Implementation of routine "set_lstring_if_empty"              *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_set_lstring_if_empty (C_Compiler & _inLexique,
                                GGS_lstring  & var_cas_s,
                                GGS_lstring   var_cas_ns,
                                GGS_string  var_cas_att COMMA_UNUSED_LOCATION_ARGS) {
  #ifdef DEBUG_TRACE_ENABLED
    printf ("ENTER routine_set_lstring_if_empty at %s:%d\n", __FILE__, __LINE__) ;
  #endif
  if (((var_cas_s.reader_string (_inLexique COMMA_SOURCE_FILE_AT_LINE (325)))._operator_isEqual (GGS_string (true, ""))).isBuiltAndTrue ()) {
    var_cas_s = var_cas_ns ;
  }else{
    var_cas_ns.reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, (GGS_string (true, "Redefinition of "))._operator_concat (var_cas_att) COMMA_SOURCE_FILE_AT_LINE (329)) ;
    var_cas_s.reader_location (_inLexique COMMA_HERE).signalGGSSemanticError (_inLexique, GGS_string (true, "was defined here") COMMA_SOURCE_FILE_AT_LINE (330)) ;
  }
  #ifdef DEBUG_TRACE_ENABLED
    printf ("LEAVE routine_set_lstring_if_empty\n") ;
  #endif
}

//---------------------------------------------------------------------------*

