//---------------------------------------------------------------------------*
//                                                                           *
//                           File 'api_parser.h'                             *
//             Generated by version version GALGAS_BETA_VERSION              *
//                    november 17th, 2010, at 19h29'51"                      *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#ifndef api_parser_ENTITIES_DEFINED
#define api_parser_ENTITIES_DEFINED

//---------------------------------------------------------------------------*

#include "galgas2/predefined-types.h"

//---------------------------------------------------------------------------*

#include "api_scanner.h"

//---------------------------------------------------------------------------*

#include "template_semantics.h"

//---------------------------------------------------------------------------*

class GALGAS__32_stringlist ;
class GALGAS_application ;
class GALGAS_binaryset ;
class GALGAS_bool ;
class GALGAS_char ;
class GALGAS_data ;
class GALGAS_double ;
class GALGAS_filewrapper ;
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
class GALGAS_lbool ;
class GALGAS_lchar ;
class GALGAS_ldouble ;
class GALGAS_location ;
class GALGAS_lsint ;
class GALGAS_lsint_36__34_ ;
class GALGAS_lstring ;
class GALGAS_lstringlist ;
class GALGAS_luint ;
class GALGAS_luint_36__34_ ;
class GALGAS_luintlist ;
class GALGAS_object ;
class GALGAS_objectlist ;
class GALGAS_sint ;
class GALGAS_sint_36__34_ ;
class GALGAS_string ;
class GALGAS_stringlist ;
class GALGAS_stringset ;
class GALGAS_type ;
class GALGAS_typelist ;
class GALGAS_uint ;
class GALGAS_uint_36__34_ ;
class GALGAS_uint_36__34_list ;
class GALGAS_uintlist ;

//---------------------------------------------------------------------------*
//                                                                           *
//                   Parser class 'api_parser' declaration                   *
//                                                                           *
//---------------------------------------------------------------------------*

class cParser_api_5F_parser {
//--- Virtual destructor
  public : virtual ~ cParser_api_5F_parser (void) {}

//--- Non terminal declarations
  protected : virtual void nt_api_5F_section_ (GALGAS_goilTemplateFieldMapList & outArgument0,
                                               C_Lexique_api_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_api_5F_start_ (GALGAS_goilTemplateVariableMap & ioArgument0,
                                             C_Lexique_api_5F_scanner * inLexique) = 0 ;


//--- Rule declarations
  protected : void rule_api_5F_parser_api_5F_start_i0_ (GALGAS_goilTemplateVariableMap & ioArgument0,
                                                        C_Lexique_api_5F_scanner * inLexique) ;

  protected : void rule_api_5F_parser_api_5F_section_i1_ (GALGAS_goilTemplateFieldMapList & outArgument0,
                                                          C_Lexique_api_5F_scanner * inLexique) ;



//--- Select methods
  protected : virtual PMSInt32 select_api_5F_parser_0 (C_Lexique_api_5F_scanner *) = 0 ;

  protected : virtual PMSInt32 select_api_5F_parser_1 (C_Lexique_api_5F_scanner *) = 0 ;

  protected : virtual PMSInt32 select_api_5F_parser_2 (C_Lexique_api_5F_scanner *) = 0 ;

  protected : virtual PMSInt32 select_api_5F_parser_3 (C_Lexique_api_5F_scanner *) = 0 ;


} ;

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

#endif
