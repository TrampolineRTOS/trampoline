//---------------------------------------------------------------------------*
//                                                                           *
//                       File 'template_invocation.h'                        *
//             Generated by version version GALGAS_BETA_VERSION              *
//                    november 17th, 2010, at 19h29'51"                      *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#ifndef template_invocation_ENTITIES_DEFINED
#define template_invocation_ENTITIES_DEFINED

//---------------------------------------------------------------------------*

#include "galgas2/predefined-types.h"

//---------------------------------------------------------------------------*

#include "goil_routines.h"
#include "goil_basic_types.h"
#include "template_semantics.h"

//---------------------------------------------------------------------------*

class GALGAS__32_stringlist ;
class GALGAS_application ;
class GALGAS_auto_5F_bool_5F_class ;
class GALGAS_auto_5F_sint_33__32__5F_class ;
class GALGAS_auto_5F_sint_36__34__5F_class ;
class GALGAS_auto_5F_string_5F_class ;
class GALGAS_auto_5F_uint_33__32__5F_class ;
class GALGAS_auto_5F_uint_36__34__5F_class ;
class GALGAS_autostart_5F_false ;
class GALGAS_autostart_5F_obj ;
class GALGAS_autostart_5F_void ;
class GALGAS_basic_5F_type ;
class GALGAS_binaryset ;
class GALGAS_bool ;
class GALGAS_bool_5F_class ;
class GALGAS_char ;
class GALGAS_data ;
class GALGAS_double ;
class GALGAS_filewrapper ;
class GALGAS_float_5F_class ;
class GALGAS_float_5F_empty_5F_set ;
class GALGAS_float_5F_set ;
class GALGAS_function ;
class GALGAS_functionlist ;
class GALGAS_goilTemplateEnumationList ;
class GALGAS_goilTemplateExpressionList ;
class GALGAS_goilTemplateFieldMap ;
class GALGAS_goilTemplateFieldMapList ;
class GALGAS_goilTemplateType ;
class GALGAS_goilTemplateTypeList ;
class GALGAS_goilTemplateValue ;
class GALGAS_goilTemplateVariableMap ;
class GALGAS_ident_5F_list ;
class GALGAS_ident_5F_list_5F_map ;
class GALGAS_ident_5F_map ;
class GALGAS_imp_5F_obj_5F_ref ;
class GALGAS_imp_5F_sca_5F_type ;
class GALGAS_imp_5F_type ;
class GALGAS_lbool ;
class GALGAS_lchar ;
class GALGAS_ldouble ;
class GALGAS_list_5F_sint_33__32_ ;
class GALGAS_list_5F_sint_36__34_ ;
class GALGAS_list_5F_uint_33__32_ ;
class GALGAS_list_5F_uint_36__34_ ;
class GALGAS_location ;
class GALGAS_lsint ;
class GALGAS_lsint_36__34_ ;
class GALGAS_lstring ;
class GALGAS_lstringMap ;
class GALGAS_lstringlist ;
class GALGAS_luint ;
class GALGAS_luint_36__34_ ;
class GALGAS_luintlist ;
class GALGAS_number_5F_set ;
class GALGAS_object ;
class GALGAS_objectlist ;
class GALGAS_oil_5F_obj ;
class GALGAS_prefix_5F_map ;
class GALGAS_sint ;
class GALGAS_sint_33__32__5F_class ;
class GALGAS_sint_33__32__5F_empty_5F_set ;
class GALGAS_sint_33__32__5F_list ;
class GALGAS_sint_33__32__5F_range ;
class GALGAS_sint_33__32__5F_set ;
class GALGAS_sint_33__32__5F_type ;
class GALGAS_sint_36__34_ ;
class GALGAS_sint_36__34__5F_class ;
class GALGAS_sint_36__34__5F_empty_5F_set ;
class GALGAS_sint_36__34__5F_list ;
class GALGAS_sint_36__34__5F_range ;
class GALGAS_sint_36__34__5F_set ;
class GALGAS_sint_36__34__5F_type ;
class GALGAS_string ;
class GALGAS_stringMap ;
class GALGAS_string_5F_class ;
class GALGAS_stringlist ;
class GALGAS_stringset ;
class GALGAS_stringset_5F_map ;
class GALGAS_type ;
class GALGAS_typelist ;
class GALGAS_uint ;
class GALGAS_uint_33__32__5F_class ;
class GALGAS_uint_33__32__5F_empty_5F_set ;
class GALGAS_uint_33__32__5F_list ;
class GALGAS_uint_33__32__5F_range ;
class GALGAS_uint_33__32__5F_set ;
class GALGAS_uint_33__32__5F_type ;
class GALGAS_uint_36__34_ ;
class GALGAS_uint_36__34__5F_class ;
class GALGAS_uint_36__34__5F_empty_5F_set ;
class GALGAS_uint_36__34__5F_list ;
class GALGAS_uint_36__34__5F_range ;
class GALGAS_uint_36__34__5F_set ;
class GALGAS_uint_36__34__5F_type ;
class GALGAS_uint_36__34_list ;
class GALGAS_uintlist ;
class GALGAS_void ;
class GALGAS_void_5F_bool_5F_class ;
class GALGAS_void_5F_float_5F_class ;
class GALGAS_void_5F_sint_33__32__5F_class ;
class GALGAS_void_5F_sint_36__34__5F_class ;
class GALGAS_void_5F_string_5F_class ;
class GALGAS_void_5F_type ;
class GALGAS_void_5F_uint_33__32__5F_class ;
class GALGAS_void_5F_uint_36__34__5F_class ;

//---------------------------------------------------------------------------*
//                                                                           *
//                        Function 'allowedFunctions'                        *
//                                                                           *
//---------------------------------------------------------------------------*

GALGAS_stringset function_allowedFunctions (C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                           Function 'fullPrefix'                           *
//                                                                           *
//---------------------------------------------------------------------------*

GALGAS_string function_fullPrefix (const GALGAS_goilTemplateVariableMap & constinArgument0,
                                   const GALGAS_lstring & constinArgument1,
                                   C_Compiler * inCompiler
                                   COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                      Function 'displayTypeAndValue'                       *
//                                                                           *
//---------------------------------------------------------------------------*

GALGAS_string function_displayTypeAndValue (const GALGAS_goilTemplateType & constinArgument0,
                                            const GALGAS_goilTemplateValue & constinArgument1,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                   Routine 'displayTemplateVariableMap'                    *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_displayTemplateVariableMap (const GALGAS_goilTemplateVariableMap constinArgument0,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                         Routine 'displayPathList'                         *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_displayPathList (const GALGAS_stringlist constinArgument0,
                              C_Compiler * inCompiler
                              COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                       Routine 'findFileInHierarchy'                       *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_findFileInHierarchy (const GALGAS_string constinArgument0,
                                  const GALGAS_string constinArgument1,
                                  const GALGAS_string constinArgument2,
                                  GALGAS_stringlist & ioArgument3,
                                  GALGAS_bool & ioArgument4,
                                  GALGAS_string & ioArgument5,
                                  C_Compiler * inCompiler
                                  COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                     Routine 'findAllFilesInHierarchy'                     *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_findAllFilesInHierarchy (const GALGAS_string constinArgument0,
                                      const GALGAS_string constinArgument1,
                                      const GALGAS_string constinArgument2,
                                      GALGAS_stringlist & ioArgument3,
                                      GALGAS_stringlist & ioArgument4,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                       Routine 'findFileInPathList'                        *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_findFileInPathList (const GALGAS_string constinArgument0,
                                 const GALGAS_stringlist constinArgument1,
                                 const GALGAS_string constinArgument2,
                                 GALGAS_stringlist & outArgument3,
                                 GALGAS_bool & outArgument4,
                                 GALGAS_string & outArgument5,
                                 C_Compiler * inCompiler
                                 COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                     Routine 'findAllFilesInPathList'                      *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_findAllFilesInPathList (const GALGAS_string constinArgument0,
                                     const GALGAS_stringlist constinArgument1,
                                     const GALGAS_string constinArgument2,
                                     GALGAS_stringlist & outArgument3,
                                     GALGAS_stringlist & outArgument4,
                                     C_Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                     Routine 'goilTemplateInvocation'                      *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_goilTemplateInvocation (const GALGAS_lstring constinArgument0,
                                     const GALGAS_string constinArgument1,
                                     const GALGAS_string constinArgument2,
                                     const GALGAS_string constinArgument3,
                                     const GALGAS_bool constinArgument4,
                                     const GALGAS_goilTemplateVariableMap constinArgument5,
                                     GALGAS_string & ioArgument6,
                                     GALGAS_bool & outArgument7,
                                     C_Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) ;

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

#endif
