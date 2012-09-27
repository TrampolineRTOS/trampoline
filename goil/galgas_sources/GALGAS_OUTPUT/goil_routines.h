//---------------------------------------------------------------------------*
//                                                                           *
//                          File 'goil_routines.h'                           *
//                    Generated by version version 2.1.4                     *
//                      january 11th, 2011, at 16h5'3"                       *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#ifndef goil_routines_ENTITIES_DEFINED
#define goil_routines_ENTITIES_DEFINED

//---------------------------------------------------------------------------*

#include "galgas2/predefined-types.h"

//---------------------------------------------------------------------------*

#include "goil_basic_types.h"

//---------------------------------------------------------------------------*


//---------------------------------------------------------------------------*
//                                                                           *
//                          Function 'projectName'                           *
//                                                                           *
//---------------------------------------------------------------------------*

GALGAS_string function_projectName (C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                            Function 'oil_dir'                             *
//                                                                           *
//---------------------------------------------------------------------------*

GALGAS_string function_oil_5F_dir (C_Compiler * inCompiler
                                   COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                              Function 'arch'                              *
//                                                                           *
//---------------------------------------------------------------------------*

GALGAS_string function_arch (C_Compiler * inCompiler
                             COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                              Function 'chip'                              *
//                                                                           *
//---------------------------------------------------------------------------*

GALGAS_string function_chip (C_Compiler * inCompiler
                             COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                             Function 'board'                              *
//                                                                           *
//---------------------------------------------------------------------------*

GALGAS_string function_board (C_Compiler * inCompiler
                              COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                       Function 'add_path_component'                       *
//                                                                           *
//---------------------------------------------------------------------------*

GALGAS_string function_add_5F_path_5F_component (GALGAS_string inArgument0,
                                                 GALGAS_string inArgument1,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                     Function 'rootTemplatesDirectory'                     *
//                                                                           *
//---------------------------------------------------------------------------*

GALGAS_string function_rootTemplatesDirectory (C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                      Function 'templates_directory'                       *
//                                                                           *
//---------------------------------------------------------------------------*

GALGAS_string function_templates_5F_directory (GALGAS_string inArgument0,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                    Function 'template_string_if_exist'                    *
//                                                                           *
//---------------------------------------------------------------------------*

GALGAS_string function_template_5F_string_5F_if_5F_exist (GALGAS_string inArgument0,
                                                          GALGAS_string inArgument1,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                        Function 'template_string'                         *
//                                                                           *
//---------------------------------------------------------------------------*

GALGAS_string function_template_5F_string (GALGAS_string inArgument0,
                                           GALGAS_string inArgument1,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                        Function 'templateFilePath'                        *
//                                                                           *
//---------------------------------------------------------------------------*

GALGAS_string function_templateFilePath (const GALGAS_string & constinArgument0,
                                         const GALGAS_string & constinArgument1,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                      Function 'allTemplateFilePaths'                      *
//                                                                           *
//---------------------------------------------------------------------------*

GALGAS_stringlist function_allTemplateFilePaths (const GALGAS_string & constinArgument0,
                                                 const GALGAS_string & constinArgument1,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                          Function 'config_file'                           *
//                                                                           *
//---------------------------------------------------------------------------*

GALGAS_lstring function_config_5F_file (C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                       Function 'extra_config_file'                        *
//                                                                           *
//---------------------------------------------------------------------------*

GALGAS_lstring function_extra_5F_config_5F_file (C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                            Routine 'doReplace'                            *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_doReplace (GALGAS_string & ioArgument0,
                        GALGAS_string inArgument1,
                        GALGAS_string inArgument2,
                        C_Compiler * inCompiler
                        COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                       Routine 'do_replace_default'                        *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_do_5F_replace_5F_default (GALGAS_string & ioArgument0,
                                       GALGAS_string inArgument1,
                                       GALGAS_string inArgument2,
                                       GALGAS_string inArgument3,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                           Routine 'table_core'                            *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_table_5F_core (GALGAS_string inArgument0,
                            GALGAS_string inArgument1,
                            GALGAS_string inArgument2,
                            GALGAS_stringset inArgument3,
                            GALGAS_string & ioArgument4,
                            GALGAS_string & ioArgument5,
                            C_Compiler * inCompiler
                            COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                        Routine 'add_to_stringset'                         *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_add_5F_to_5F_stringset (GALGAS_stringset & ioArgument0,
                                     GALGAS_string inArgument1,
                                     C_Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                          Routine 'file_in_path'                           *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_file_5F_in_5F_path (GALGAS_lstring & ioArgument0,
                                 C_Compiler * inCompiler
                                 COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                        Routine 'is_in_lstringlist'                        *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_is_5F_in_5F_lstringlist (GALGAS_lstringlist inArgument0,
                                      GALGAS_lstring inArgument1,
                                      GALGAS_lstring & outArgument2,
                                      GALGAS_bool & outArgument3,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                        Function 'isInLstringlist'                         *
//                                                                           *
//---------------------------------------------------------------------------*

GALGAS_bool function_isInLstringlist (GALGAS_lstringlist inArgument0,
                                      GALGAS_lstring inArgument1,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                       Routine 'add_lstring_unique'                        *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_add_5F_lstring_5F_unique (GALGAS_lstringlist & ioArgument0,
                                       GALGAS_lstring inArgument1,
                                       GALGAS_string inArgument2,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                      Routine 'set_lstring_if_empty'                       *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_set_5F_lstring_5F_if_5F_empty (GALGAS_lstring & ioArgument0,
                                            GALGAS_lstring inArgument1,
                                            GALGAS_string inArgument2,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                 Routine 'add_makefile_flag_if_not_empty'                  *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_add_5F_makefile_5F_flag_5F_if_5F_not_5F_empty (GALGAS_string & ioArgument0,
                                                            GALGAS_string inArgument1,
                                                            GALGAS_string inArgument2,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                          Function 'lstringWith'                           *
//                                                                           *
//---------------------------------------------------------------------------*

GALGAS_lstring function_lstringWith (GALGAS_string inArgument0,
                                     C_Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                          Function 'stripString'                           *
//                                                                           *
//---------------------------------------------------------------------------*

GALGAS_string function_stripString (GALGAS_string inArgument0,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                        Routine 'errorNoFileFound'                         *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_errorNoFileFound (const GALGAS_stringlist constinArgument0,
                               const GALGAS_string constinArgument1,
                               const GALGAS_lstring constinArgument2,
                               C_Compiler * inCompiler
                               COMMA_LOCATION_ARGS) ;

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

#endif