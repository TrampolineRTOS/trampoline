#include "galgas2/C_Compiler.h"
#include "galgas2/C_galgas_io.h"
#include "galgas2/C_galgas_CLI_Options.h"
#include "utilities/C_PrologueEpilogue.h"

//----------------------------------------------------------------------------------------------------------------------

#include "all-declarations-6.h"

//---------------------------------------------------------------------------------------------------------------------*

#include "utilities/MF_MemoryControl.h"
#include "galgas2/C_galgas_CLI_Options.h"

#include "files/C_FileManager.h"

//---------------------------------------------------------------------------------------------------------------------*


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                   L L ( 1 )    P R O D U C T I O N    R U L E S                                      
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

#define TERMINAL(t)     ((t)+1)
#define NONTERMINAL(nt) ((-nt)-1)
#define END_PRODUCTION  (0)

static const int16_t gProductions_options_grammar [] = {
// At index 0 : <option_parser_start>, in file 'options_parser.ggs', line 29
  NONTERMINAL (1) // <option_item>
, NONTERMINAL (4) // <select_options_5F_parser_0>
, END_PRODUCTION
// At index 3 : <option_item>, in file 'options_parser.ggs', line 39
, TERMINAL (C_Lexique_options_5F_scanner::kToken_idf) // $idf$
, TERMINAL (C_Lexique_options_5F_scanner::kToken__3D_) // $=$
, NONTERMINAL (5) // <select_options_5F_parser_1>
, END_PRODUCTION
// At index 7 : <option_value>, in file 'options_parser.ggs', line 53
, TERMINAL (C_Lexique_options_5F_scanner::kToken_string) // $string$
, END_PRODUCTION
// At index 9 : <option_value>, in file 'options_parser.ggs', line 60
, TERMINAL (C_Lexique_options_5F_scanner::kToken_idf) // $idf$
, END_PRODUCTION
// At index 11 : <option_value>, in file 'options_parser.ggs', line 67
, TERMINAL (C_Lexique_options_5F_scanner::kToken_uint_5F_number) // $uint_number$
, END_PRODUCTION
// At index 13 : <option_value>, in file 'options_parser.ggs', line 74
, TERMINAL (C_Lexique_options_5F_scanner::kToken_float_5F_number) // $float_number$
, END_PRODUCTION
// At index 15 : <option_value>, in file 'options_parser.ggs', line 81
, TERMINAL (C_Lexique_options_5F_scanner::kToken__2D_) // $-$
, NONTERMINAL (6) // <select_options_5F_parser_2>
, END_PRODUCTION
// At index 18 : <list_option_value>, in file 'options_parser.ggs', line 94
, TERMINAL (C_Lexique_options_5F_scanner::kToken__28_) // $($
, NONTERMINAL (2) // <option_value>
, NONTERMINAL (7) // <select_options_5F_parser_3>
, TERMINAL (C_Lexique_options_5F_scanner::kToken__29_) // $)$
, END_PRODUCTION
//---- Added productions from 'select' and 'repeat' instructions
// At index 23 : <select_options_5F_parser_0>, in file 'options_parser.ggs', line 33
, END_PRODUCTION
// At index 24 : <select_options_5F_parser_0>, in file 'options_parser.ggs', line 33
, TERMINAL (C_Lexique_options_5F_scanner::kToken__2C_) // $,$
, NONTERMINAL (1) // <option_item>
, NONTERMINAL (4) // <select_options_5F_parser_0>
, END_PRODUCTION
// At index 28 : <select_options_5F_parser_1>, in file 'options_parser.ggs', line 45
, NONTERMINAL (2) // <option_value>
, END_PRODUCTION
// At index 30 : <select_options_5F_parser_1>, in file 'options_parser.ggs', line 45
, NONTERMINAL (3) // <list_option_value>
, END_PRODUCTION
// At index 32 : <select_options_5F_parser_2>, in file 'options_parser.ggs', line 85
, TERMINAL (C_Lexique_options_5F_scanner::kToken_uint_5F_number) // $uint_number$
, END_PRODUCTION
// At index 34 : <select_options_5F_parser_2>, in file 'options_parser.ggs', line 85
, TERMINAL (C_Lexique_options_5F_scanner::kToken_float_5F_number) // $float_number$
, END_PRODUCTION
// At index 36 : <select_options_5F_parser_3>, in file 'options_parser.ggs', line 99
, END_PRODUCTION
// At index 37 : <select_options_5F_parser_3>, in file 'options_parser.ggs', line 99
, TERMINAL (C_Lexique_options_5F_scanner::kToken__2C_) // $,$
, NONTERMINAL (2) // <option_value>
, NONTERMINAL (7) // <select_options_5F_parser_3>
, END_PRODUCTION
// At index 41 : <>, in file '.ggs', line 0
, NONTERMINAL (0) // <option_parser_start>
, END_PRODUCTION
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                          P R O D U C T I O N    N A M E S                                            
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const cProductionNameDescriptor gProductionNames_options_grammar [17] = {
 {"<option_parser_start>", "options_parser", 0}, // at index 0
 {"<option_item>", "options_parser", 3}, // at index 1
 {"<option_value>", "options_parser", 7}, // at index 2
 {"<option_value>", "options_parser", 9}, // at index 3
 {"<option_value>", "options_parser", 11}, // at index 4
 {"<option_value>", "options_parser", 13}, // at index 5
 {"<option_value>", "options_parser", 15}, // at index 6
 {"<list_option_value>", "options_parser", 18}, // at index 7
 {"<select_options_5F_parser_0>", "options_parser", 23}, // at index 8
 {"<select_options_5F_parser_0>", "options_parser", 24}, // at index 9
 {"<select_options_5F_parser_1>", "options_parser", 28}, // at index 10
 {"<select_options_5F_parser_1>", "options_parser", 30}, // at index 11
 {"<select_options_5F_parser_2>", "options_parser", 32}, // at index 12
 {"<select_options_5F_parser_2>", "options_parser", 34}, // at index 13
 {"<select_options_5F_parser_3>", "options_parser", 36}, // at index 14
 {"<select_options_5F_parser_3>", "options_parser", 37}, // at index 15
 {"<>", "", 41} // at index 16
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                 L L ( 1 )    P R O D U C T I O N    I N D E X E S                                    
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gProductionIndexes_options_grammar [17] = {
0, // index 0 : <option_parser_start>, in file 'options_parser.ggs', line 29
3, // index 1 : <option_item>, in file 'options_parser.ggs', line 39
7, // index 2 : <option_value>, in file 'options_parser.ggs', line 53
9, // index 3 : <option_value>, in file 'options_parser.ggs', line 60
11, // index 4 : <option_value>, in file 'options_parser.ggs', line 67
13, // index 5 : <option_value>, in file 'options_parser.ggs', line 74
15, // index 6 : <option_value>, in file 'options_parser.ggs', line 81
18, // index 7 : <list_option_value>, in file 'options_parser.ggs', line 94
23, // index 8 : <select_options_5F_parser_0>, in file 'options_parser.ggs', line 33
24, // index 9 : <select_options_5F_parser_0>, in file 'options_parser.ggs', line 33
28, // index 10 : <select_options_5F_parser_1>, in file 'options_parser.ggs', line 45
30, // index 11 : <select_options_5F_parser_1>, in file 'options_parser.ggs', line 45
32, // index 12 : <select_options_5F_parser_2>, in file 'options_parser.ggs', line 85
34, // index 13 : <select_options_5F_parser_2>, in file 'options_parser.ggs', line 85
36, // index 14 : <select_options_5F_parser_3>, in file 'options_parser.ggs', line 99
37, // index 15 : <select_options_5F_parser_3>, in file 'options_parser.ggs', line 99
41 // index 16 : <>, in file '.ggs', line 0
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                           L L ( 1 )    F I R S T    P R O D U C T I O N    I N D E X E S                             
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gFirstProductionIndexes_options_grammar [10] = {
0, // at 0 : <option_parser_start>
1, // at 1 : <option_item>
2, // at 2 : <option_value>
7, // at 3 : <list_option_value>
8, // at 4 : <select_options_5F_parser_0>
10, // at 5 : <select_options_5F_parser_1>
12, // at 6 : <select_options_5F_parser_2>
14, // at 7 : <select_options_5F_parser_3>
16, // at 8 : <>
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                    L L ( 1 )    D E C I S I O N    T A B L E S                                       
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gDecision_options_grammar [] = {
// At index 0 : <option_parser_start> only one production, no choice
  -1,
// At index 1 : <option_item> only one production, no choice
  -1,
// At index 2 : <option_value>
C_Lexique_options_5F_scanner::kToken_string, -1, // Choice 1
C_Lexique_options_5F_scanner::kToken_idf, -1, // Choice 2
C_Lexique_options_5F_scanner::kToken_uint_5F_number, -1, // Choice 3
C_Lexique_options_5F_scanner::kToken_float_5F_number, -1, // Choice 4
C_Lexique_options_5F_scanner::kToken__2D_, -1, // Choice 5
  -1,
// At index 13 : <list_option_value> only one production, no choice
  -1,
//---- Added non terminal symbols from 'select' and 'repeat' instructions
// At index 14 : <select_options_5F_parser_0>
C_Lexique_options_5F_scanner::kToken_, -1, // Choice 1
C_Lexique_options_5F_scanner::kToken__2C_, -1, // Choice 2
  -1,
// At index 19 : <select_options_5F_parser_1>
C_Lexique_options_5F_scanner::kToken_idf, C_Lexique_options_5F_scanner::kToken_string, C_Lexique_options_5F_scanner::kToken_uint_5F_number, C_Lexique_options_5F_scanner::kToken_float_5F_number, C_Lexique_options_5F_scanner::kToken__2D_, -1, // Choice 1
C_Lexique_options_5F_scanner::kToken__28_, -1, // Choice 2
  -1,
// At index 28 : <select_options_5F_parser_2>
C_Lexique_options_5F_scanner::kToken_uint_5F_number, -1, // Choice 1
C_Lexique_options_5F_scanner::kToken_float_5F_number, -1, // Choice 2
  -1,
// At index 33 : <select_options_5F_parser_3>
C_Lexique_options_5F_scanner::kToken__29_, -1, // Choice 1
C_Lexique_options_5F_scanner::kToken__2C_, -1, // Choice 2
  -1,
// At index 38 : <> only one production, no choice
  -1,
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            L L ( 1 )    D E C I S I O N    T A B L E S    I N D E X E S                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gDecisionIndexes_options_grammar [10] = {
0, // at 0 : <option_parser_start>
1, // at 1 : <option_item>
2, // at 2 : <option_value>
13, // at 3 : <list_option_value>
14, // at 4 : <select_options_5F_parser_0>
19, // at 5 : <select_options_5F_parser_1>
28, // at 6 : <select_options_5F_parser_2>
33, // at 7 : <select_options_5F_parser_3>
38, // at 8 : <>
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                 'option_parser_start' non terminal implementation                                    
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_options_5F_grammar::nt_option_5F_parser_5F_start_parse (C_Lexique_options_5F_scanner * inLexique) {
  rule_options_5F_parser_option_5F_parser_5F_start_i0_parse(inLexique) ;
}

void cGrammar_options_5F_grammar::nt_option_5F_parser_5F_start_ (GALGAS_gtlData & parameter_1,
                                C_Lexique_options_5F_scanner * inLexique) {
  rule_options_5F_parser_option_5F_parser_5F_start_i0_(parameter_1, inLexique) ;
}

void cGrammar_options_5F_grammar::performIndexing (C_Compiler * /* inCompiler */,
             const C_String & /* inSourceFilePath */) {
}

void cGrammar_options_5F_grammar::performOnlyLexicalAnalysis (C_Compiler * inCompiler,
             const C_String & inSourceFilePath) {
  C_Lexique_options_5F_scanner * scanner = NULL ;
  macroMyNew (scanner, C_Lexique_options_5F_scanner (inCompiler, inSourceFilePath COMMA_HERE)) ;
  if (scanner->sourceText ().isValid ()) {
    scanner->performLexicalAnalysis () ;
  }
  macroDetachSharedObject (scanner) ;
}

void cGrammar_options_5F_grammar::performOnlySyntaxAnalysis (C_Compiler * inCompiler,
             const C_String & inSourceFilePath) {
  C_Lexique_options_5F_scanner * scanner = NULL ;
  macroMyNew (scanner, C_Lexique_options_5F_scanner (inCompiler, inSourceFilePath COMMA_HERE)) ;
  if (scanner->sourceText ().isValid ()) {
    scanner->performTopDownParsing (gProductions_options_grammar, gProductionNames_options_grammar, gProductionIndexes_options_grammar,
                                    gFirstProductionIndexes_options_grammar, gDecision_options_grammar, gDecisionIndexes_options_grammar, 41) ;
  }
  macroDetachSharedObject (scanner) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                        Grammar start symbol implementation                                           
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_options_5F_grammar::_performSourceFileParsing_ (C_Compiler * inCompiler,
                                GALGAS_lstring inFilePath,
                                GALGAS_gtlData &  parameter_1
                                COMMA_LOCATION_ARGS) {
  if (inFilePath.isValid ()) {
    const GALGAS_string filePathAsString = inFilePath.readProperty_string () ;
    C_String filePath = filePathAsString.stringValue () ;
    if (! C_FileManager::isAbsolutePath (filePath)) {
      filePath = inCompiler->sourceFilePath ().stringByDeletingLastPathComponent ().stringByAppendingPathComponent (filePath) ;
    }
    if (C_FileManager::fileExistsAtPath (filePath)) {
    C_Lexique_options_5F_scanner * scanner = NULL ;
    macroMyNew (scanner, C_Lexique_options_5F_scanner (inCompiler, filePath COMMA_HERE)) ;
    if (scanner->sourceText ().isValid ()) {
      const bool ok = scanner->performTopDownParsing (gProductions_options_grammar, gProductionNames_options_grammar, gProductionIndexes_options_grammar,
                                                      gFirstProductionIndexes_options_grammar, gDecision_options_grammar, gDecisionIndexes_options_grammar, 41) ;
      if (ok && ! executionModeIsSyntaxAnalysisOnly ()) {
        cGrammar_options_5F_grammar grammar ;
        grammar.nt_option_5F_parser_5F_start_ (parameter_1, scanner) ;
        }
      }else{
        C_String message ;
        message << "the '" << filePath << "' file exists, but cannot be read" ;
        const GALGAS_location errorLocation (inFilePath.readProperty_location ()) ;
        inCompiler->semanticErrorAtLocation (errorLocation, message, TC_Array <C_FixItDescription> () COMMA_THERE) ;
      }
      macroDetachSharedObject (scanner) ;
    }else{
      C_String message ;
      message << "the '" << filePath << "' file does not exist" ;
      const GALGAS_location errorLocation (inFilePath.readProperty_location ()) ;
      inCompiler->semanticErrorAtLocation (errorLocation, message, TC_Array <C_FixItDescription> () COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_options_5F_grammar::_performSourceStringParsing_ (C_Compiler * inCompiler,
                                GALGAS_string inSourceString,
                                GALGAS_string inNameString,
                                GALGAS_gtlData &  parameter_1
                                COMMA_UNUSED_LOCATION_ARGS) {
  if (inSourceString.isValid () && inNameString.isValid ()) {
    const C_String sourceString = inSourceString.stringValue () ;
    const C_String nameString = inNameString.stringValue () ;
    C_Lexique_options_5F_scanner * scanner = NULL ;
    macroMyNew (scanner, C_Lexique_options_5F_scanner (inCompiler, sourceString, nameString COMMA_HERE)) ;
    const bool ok = scanner->performTopDownParsing (gProductions_options_grammar, gProductionNames_options_grammar, gProductionIndexes_options_grammar,
                                                    gFirstProductionIndexes_options_grammar, gDecision_options_grammar, gDecisionIndexes_options_grammar, 41) ;
    if (ok && ! executionModeIsSyntaxAnalysisOnly ()) {
      cGrammar_options_5F_grammar grammar ;
      grammar.nt_option_5F_parser_5F_start_ (parameter_1, scanner) ;
    }
    macroDetachSharedObject (scanner) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                     'option_item' non terminal implementation                                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_options_5F_grammar::nt_option_5F_item_parse (C_Lexique_options_5F_scanner * inLexique) {
  rule_options_5F_parser_option_5F_item_i1_parse(inLexique) ;
}

void cGrammar_options_5F_grammar::nt_option_5F_item_ (GALGAS_gtlData & parameter_1,
                                C_Lexique_options_5F_scanner * inLexique) {
  rule_options_5F_parser_option_5F_item_i1_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                     'option_value' non terminal implementation                                       
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_options_5F_grammar::nt_option_5F_value_parse (C_Lexique_options_5F_scanner * inLexique) {
  switch (inLexique->nextProductionIndex ()) {
  case 1 :
    rule_options_5F_parser_option_5F_value_i2_parse(inLexique) ;
    break ;
  case 2 :
    rule_options_5F_parser_option_5F_value_i3_parse(inLexique) ;
    break ;
  case 3 :
    rule_options_5F_parser_option_5F_value_i4_parse(inLexique) ;
    break ;
  case 4 :
    rule_options_5F_parser_option_5F_value_i5_parse(inLexique) ;
    break ;
  case 5 :
    rule_options_5F_parser_option_5F_value_i6_parse(inLexique) ;
    break ;
  default :
    break ;
  }
}

void cGrammar_options_5F_grammar::nt_option_5F_value_ (GALGAS_gtlData & parameter_1,
                                C_Lexique_options_5F_scanner * inLexique) {
  switch (inLexique->nextProductionIndex ()) {
  case 1 :
    rule_options_5F_parser_option_5F_value_i2_(parameter_1, inLexique) ;
    break ;
  case 2 :
    rule_options_5F_parser_option_5F_value_i3_(parameter_1, inLexique) ;
    break ;
  case 3 :
    rule_options_5F_parser_option_5F_value_i4_(parameter_1, inLexique) ;
    break ;
  case 4 :
    rule_options_5F_parser_option_5F_value_i5_(parameter_1, inLexique) ;
    break ;
  case 5 :
    rule_options_5F_parser_option_5F_value_i6_(parameter_1, inLexique) ;
    break ;
  default :
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                  'list_option_value' non terminal implementation                                     
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_options_5F_grammar::nt_list_5F_option_5F_value_parse (C_Lexique_options_5F_scanner * inLexique) {
  rule_options_5F_parser_list_5F_option_5F_value_i7_parse(inLexique) ;
}

void cGrammar_options_5F_grammar::nt_list_5F_option_5F_value_ (GALGAS_gtlData & parameter_1,
                                C_Lexique_options_5F_scanner * inLexique) {
  rule_options_5F_parser_list_5F_option_5F_value_i7_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                           'select_options_5F_parser_0' added non terminal implementation                             
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_options_5F_grammar::select_options_5F_parser_0 (C_Lexique_options_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                           'select_options_5F_parser_1' added non terminal implementation                             
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_options_5F_grammar::select_options_5F_parser_1 (C_Lexique_options_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                           'select_options_5F_parser_2' added non terminal implementation                             
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_options_5F_grammar::select_options_5F_parser_2 (C_Lexique_options_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                           'select_options_5F_parser_3' added non terminal implementation                             
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_options_5F_grammar::select_options_5F_parser_3 (C_Lexique_options_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*



//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxml_5F_parser::rule_arxml_5F_parser_arxml_5F_start_5F_symbol_i0_ (GALGAS_arxmlNode & outArgument_rootNode,
                                                                                 const GALGAS_bool constinArgument_includeComments,
                                                                                 const GALGAS_bool constinArgument_doNotCondenseWhiteSpaces,
                                                                                 C_Lexique_arxml_5F_scanner * inCompiler) {
  outArgument_rootNode.drop () ; // Release 'out' argument
  GALGAS_implementation var_imp_930 = GALGAS_implementation::constructor_new (GALGAS_implementationMap::constructor_emptyMap (SOURCE_FILE ("arxml_parser.galgas", 36))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 36)) ;
  GALGAS_applicationDefinition var_application_1024 = function_emptyApplicationDefinition (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 37)) ;
  GALGAS_string var_fileIncludeList_1081 = GALGAS_string::makeEmptyString () ;
  GALGAS_bool var_debug_1104 = GALGAS_bool (false) ;
  GALGAS_string var_s_1234 = GALGAS_string::constructor_retrieveAndResetTemplateString (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 44)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsStrictSup, var_s_1234.getter_length (SOURCE_FILE ("arxml_parser.galgas", 45)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 46)), GALGAS_string ("No character is allowed before XML header"), fixItArray1  COMMA_SOURCE_FILE ("arxml_parser.galgas", 46)) ;
    }
  }
  inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken__3C__3F_ COMMA_SOURCE_FILE ("arxml_parser.galgas", 49)) ;
  GALGAS_lstring var_name_1412 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken_name COMMA_SOURCE_FILE ("arxml_parser.galgas", 50)) ;
  GALGAS_arxmlAttributeMap var_attributes_1445 = GALGAS_arxmlAttributeMap::constructor_emptyMap (SOURCE_FILE ("arxml_parser.galgas", 52)) ;
  bool repeatFlag_2 = true ;
  while (repeatFlag_2) {
    switch (select_arxml_5F_parser_0 (inCompiler)) {
    case 2: {
      GALGAS_lstring var_attributeName_1513 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken_name COMMA_SOURCE_FILE ("arxml_parser.galgas", 55)) ;
      inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxml_parser.galgas", 56)) ;
      GALGAS_lstring var_attributeValue_1562 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken_value COMMA_SOURCE_FILE ("arxml_parser.galgas", 57)) ;
      {
      var_attributes_1445.setter_insertKey (var_attributeName_1513, var_attributeValue_1562, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 58)) ;
      }
    } break ;
    default:
      repeatFlag_2 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken__3F__3E_ COMMA_SOURCE_FILE ("arxml_parser.galgas", 60)) ;
  GALGAS_arxmlNodeList var_nodes_1676 = GALGAS_arxmlNodeList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 62)) ;
  nt_element_5F_list_ (var_nodes_1676, constinArgument_includeComments, constinArgument_doNotCondenseWhiteSpaces, inCompiler) ;
  outArgument_rootNode = GALGAS_arxmlElementNode::constructor_new (var_name_1412, var_attributes_1445, var_nodes_1676  COMMA_SOURCE_FILE ("arxml_parser.galgas", 68)) ;
  GALGAS_lstring var_autosarVersion_2004 ;
  GALGAS_lstring var_autosarDescription_2038 ;
  {
  routine_getAutosarVersion (outArgument_rootNode, var_autosarVersion_2004, var_autosarDescription_2038, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 81)) ;
  }
  enumGalgasBool test_3 = kBoolTrue ;
  if (kBoolTrue == test_3) {
    test_3 = GALGAS_bool (kIsEqual, var_autosarVersion_2004.readProperty_string ().objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
    if (kBoolTrue == test_3) {
      TC_Array <C_FixItDescription> fixItArray4 ;
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 84)), GALGAS_string ("[TPS_ECUC_06005][TPS_ECUC_08053] : Missing AUTOSAR version"), fixItArray4  COMMA_SOURCE_FILE ("arxml_parser.galgas", 84)) ;
    }
  }
  GALGAS_stringlist var_autosarVlist_2327 = var_autosarVersion_2004.readProperty_string ().getter_componentsSeparatedByString (GALGAS_string (".") COMMA_SOURCE_FILE ("arxml_parser.galgas", 88)) ;
  GALGAS_string var_versionFirst_2432 ;
  {
  var_autosarVlist_2327.setter_popFirst (var_versionFirst_2432, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 89)) ;
  }
  GALGAS_string var_versionSecond_2487 ;
  {
  var_autosarVlist_2327.setter_popFirst (var_versionSecond_2487, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 90)) ;
  }
  GALGAS_lstring var_autosarShortVersion_2523 = GALGAS_lstring::constructor_new (var_versionFirst_2432.add_operation (GALGAS_string ("."), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 91)).add_operation (var_versionSecond_2487, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 91)), var_autosarVersion_2004.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 91)) ;
  {
  routine_displayOil (GALGAS_string ("\n"
    "OIL_VERSION = \"").add_operation (var_autosarShortVersion_2523.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 93)).add_operation (GALGAS_string ("\";\n"
    "\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 93)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 93)) ;
  }
  {
  var_application_1024.setter_setVersion (var_autosarShortVersion_2523 COMMA_SOURCE_FILE ("arxml_parser.galgas", 95)) ;
  }
  {
  var_application_1024.setter_setVersionDescription (var_autosarDescription_2038 COMMA_SOURCE_FILE ("arxml_parser.galgas", 96)) ;
  }
  GALGAS_string var_autosarVersionNoDot_3028 = var_autosarVersion_2004.readProperty_string ().getter_stringByReplacingStringByString (GALGAS_string ("."), GALGAS_string ("-"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 105)) ;
  GALGAS_string var_autosarMetaFile_3183 = GALGAS_string ("AUTOSAR_").add_operation (var_autosarVersionNoDot_3028, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 107)).add_operation (GALGAS_string (".xsd"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 107)) ;
  GALGAS_string var_filePath_3250 = function_templates_5F_directory (GALGAS_string ("arxmlMeta"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 108)).add_operation (var_autosarMetaFile_3183, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 108)) ;
  GALGAS_arxmlMetaClassMap var_classMap_3334 ;
  enumGalgasBool test_5 = kBoolTrue ;
  if (kBoolTrue == test_5) {
    test_5 = var_filePath_3250.getter_fileExists (SOURCE_FILE ("arxml_parser.galgas", 111)).operator_not (SOURCE_FILE ("arxml_parser.galgas", 111)).boolEnum () ;
    if (kBoolTrue == test_5) {
      TC_Array <C_FixItDescription> fixItArray6 ;
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 112)), GALGAS_string ("The corresponding metafile ").add_operation (var_filePath_3250, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 112)).add_operation (GALGAS_string (" does not"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 112)).add_operation (GALGAS_string (" exists. The Metamodel can be found here : "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 112)).add_operation (GALGAS_string ("http://www.autosar.org/specification -> Methodology and Templates -> "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 113)).add_operation (GALGAS_string ("Templates -> AUTOSAR_MMOD_XMLSchema.zip."), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 114)), fixItArray6  COMMA_SOURCE_FILE ("arxml_parser.galgas", 112)) ;
    }
  }
  var_classMap_3334.drop () ;
  cGrammar_arxmlmetaparser_5F_grammar::_performSourceFileParsing_ (inCompiler, function_lstringWith (var_filePath_3250, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 118)), var_classMap_3334, var_debug_1104  COMMA_SOURCE_FILE ("arxml_parser.galgas", 118)) ;
  GALGAS_arxmlElementValue var_rootValue_3908 ;
  {
  routine_nodeToClass (outArgument_rootNode, var_classMap_3334, var_rootValue_3908, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 124)) ;
  }
  {
  routine_includeConfigs (var_imp_930, var_application_1024, var_fileIncludeList_1081, var_autosarShortVersion_2523, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 136)) ;
  }
  {
  routine_convertToOil (var_imp_930, var_application_1024, var_rootValue_3908, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 143)) ;
  }
  callExtensionMethod_checkObjectReferences ((cPtr_implementation *) var_imp_930.ptr (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 154)) ;
  enumGalgasBool test_7 = kBoolTrue ;
  if (kBoolTrue == test_7) {
    test_7 = GALGAS_bool (kIsEqual, GALGAS_uint::constructor_errorCount (SOURCE_FILE ("arxml_parser.galgas", 156)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
    if (kBoolTrue == test_7) {
      {
      routine_setDefaults (var_imp_930, var_application_1024, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 157)) ;
      }
    }
  }
  enumGalgasBool test_8 = kBoolTrue ;
  if (kBoolTrue == test_8) {
    test_8 = GALGAS_bool (kIsEqual, GALGAS_uint::constructor_errorCount (SOURCE_FILE ("arxml_parser.galgas", 164)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
    if (kBoolTrue == test_8) {
      {
      routine_verifyAll (var_imp_930, var_application_1024, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 165)) ;
      }
    }
  }
  enumGalgasBool test_9 = kBoolTrue ;
  if (kBoolTrue == test_9) {
    test_9 = GALGAS_bool (kIsEqual, GALGAS_uint::constructor_errorCount (SOURCE_FILE ("arxml_parser.galgas", 167)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
    if (kBoolTrue == test_9) {
      GALGAS_gtlData var_templateData_5227 = callExtensionGetter_templateData ((const cPtr_applicationDefinition *) var_application_1024.ptr (), var_imp_930, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 168)) ;
      {
      routine_generate_5F_all (var_templateData_5227, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 171)) ;
      }
    }
  }
  var_fileIncludeList_1081 = GALGAS_string::constructor_stringWithSourceFilePath (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 174)).getter_lastPathComponent (SOURCE_FILE ("arxml_parser.galgas", 174)).add_operation (GALGAS_string (":"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 174)).add_operation (var_fileIncludeList_1081, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 174)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 174)) ;
  GALGAS_string var_oilDepFileName_5542 = GALGAS_string::constructor_stringWithSourceFilePath (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 175)).getter_stringByDeletingLastPathComponent (SOURCE_FILE ("arxml_parser.galgas", 175)).add_operation (GALGAS_string ("/build/"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 175)).add_operation (GALGAS_string::constructor_stringWithSourceFilePath (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 176)).getter_lastPathComponent (SOURCE_FILE ("arxml_parser.galgas", 176)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 176)).add_operation (GALGAS_string (".dep"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 176)) ;
  var_fileIncludeList_1081.method_writeToFile (var_oilDepFileName_5542, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 178)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxml_5F_parser::rule_arxml_5F_parser_arxml_5F_start_5F_symbol_i0_parse (C_Lexique_arxml_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken__3C__3F_ COMMA_SOURCE_FILE ("arxml_parser.galgas", 49)) ;
  inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken_name COMMA_SOURCE_FILE ("arxml_parser.galgas", 50)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_arxml_5F_parser_0 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken_name COMMA_SOURCE_FILE ("arxml_parser.galgas", 55)) ;
      inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxml_parser.galgas", 56)) ;
      inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken_value COMMA_SOURCE_FILE ("arxml_parser.galgas", 57)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken__3F__3E_ COMMA_SOURCE_FILE ("arxml_parser.galgas", 60)) ;
  nt_element_5F_list_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxml_5F_parser::rule_arxml_5F_parser_element_5F_list_i1_ (GALGAS_arxmlNodeList & ioArgument_nodes,
                                                                        const GALGAS_bool constinArgument_includeComments,
                                                                        const GALGAS_bool constinArgument_doNotCondenseWhiteSpaces,
                                                                        C_Lexique_arxml_5F_scanner * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_arxml_5F_parser_1 (inCompiler)) {
    case 2: {
      {
      routine_addText (ioArgument_nodes, constinArgument_doNotCondenseWhiteSpaces, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 193)) ;
      }
      nt_element_ (ioArgument_nodes, constinArgument_includeComments, constinArgument_doNotCondenseWhiteSpaces, inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxml_5F_parser::rule_arxml_5F_parser_element_5F_list_i1_parse (C_Lexique_arxml_5F_scanner * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_arxml_5F_parser_1 (inCompiler)) {
    case 2: {
      nt_element_parse (inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxml_5F_parser::rule_arxml_5F_parser_element_i2_ (GALGAS_arxmlNodeList & ioArgument_nodes,
                                                                const GALGAS_bool constinArgument_includeComments,
                                                                const GALGAS_bool /* constinArgument_doNotCondenseWhiteSpaces */,
                                                                C_Lexique_arxml_5F_scanner * inCompiler) {
  GALGAS_lstring var_commentString_6457 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken_comment COMMA_SOURCE_FILE ("arxml_parser.galgas", 210)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = constinArgument_includeComments.boolEnum () ;
    if (kBoolTrue == test_0) {
      ioArgument_nodes.addAssign_operation (GALGAS_arxmlCommentNode::constructor_new (var_commentString_6457  COMMA_SOURCE_FILE ("arxml_parser.galgas", 212))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 212)) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxml_5F_parser::rule_arxml_5F_parser_element_i2_parse (C_Lexique_arxml_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken_comment COMMA_SOURCE_FILE ("arxml_parser.galgas", 210)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxml_5F_parser::rule_arxml_5F_parser_element_i3_ (GALGAS_arxmlNodeList & ioArgument_nodes,
                                                                const GALGAS_bool constinArgument_includeComments,
                                                                const GALGAS_bool constinArgument_doNotCondenseWhiteSpaces,
                                                                C_Lexique_arxml_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken__3C_ COMMA_SOURCE_FILE ("arxml_parser.galgas", 223)) ;
  GALGAS_lstring var_name_6782 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken_name COMMA_SOURCE_FILE ("arxml_parser.galgas", 224)) ;
  GALGAS_arxmlAttributeMap var_attributeMap_6816 = GALGAS_arxmlAttributeMap::constructor_emptyMap (SOURCE_FILE ("arxml_parser.galgas", 225)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_arxml_5F_parser_2 (inCompiler)) {
    case 2: {
      GALGAS_lstring var_attributeName_6884 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken_name COMMA_SOURCE_FILE ("arxml_parser.galgas", 228)) ;
      inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxml_parser.galgas", 229)) ;
      GALGAS_lstring var_attributeValue_6933 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken_value COMMA_SOURCE_FILE ("arxml_parser.galgas", 230)) ;
      {
      var_attributeMap_6816.setter_insertKey (var_attributeName_6884, var_attributeValue_6933, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 231)) ;
      }
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  GALGAS_arxmlNodeList var_nodeList_7028 = GALGAS_arxmlNodeList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 234)) ;
  switch (select_arxml_5F_parser_3 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken__2F__3E_ COMMA_SOURCE_FILE ("arxml_parser.galgas", 236)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxml_parser.galgas", 238)) ;
    nt_element_5F_list_ (var_nodeList_7028, constinArgument_includeComments, constinArgument_doNotCondenseWhiteSpaces, inCompiler) ;
    {
    routine_addText (var_nodeList_7028, constinArgument_doNotCondenseWhiteSpaces, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 244)) ;
    }
    inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken__3C__2F_ COMMA_SOURCE_FILE ("arxml_parser.galgas", 246)) ;
    GALGAS_lstring var_closingName_7267 = inCompiler->synthetizedAttribute_tokenString () ;
    inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken_name COMMA_SOURCE_FILE ("arxml_parser.galgas", 247)) ;
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = GALGAS_bool (kIsNotEqual, var_closingName_7267.readProperty_string ().objectCompare (var_name_6782.readProperty_string ())).boolEnum () ;
      if (kBoolTrue == test_1) {
        TC_Array <C_FixItDescription> fixItArray2 ;
        inCompiler->emitSemanticError (var_closingName_7267.readProperty_location (), GALGAS_string ("incorrect closing tag </").add_operation (var_closingName_7267.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 249)).add_operation (GALGAS_string ("> instead of </"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 250)).add_operation (var_name_6782.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 250)).add_operation (GALGAS_string (">"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 250)), fixItArray2  COMMA_SOURCE_FILE ("arxml_parser.galgas", 249)) ;
      }
    }
    inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxml_parser.galgas", 252)) ;
  } break ;
  default:
    break ;
  }
  ioArgument_nodes.addAssign_operation (GALGAS_arxmlElementNode::constructor_new (var_name_6782, var_attributeMap_6816, var_nodeList_7028  COMMA_SOURCE_FILE ("arxml_parser.galgas", 255))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 255)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxml_5F_parser::rule_arxml_5F_parser_element_i3_parse (C_Lexique_arxml_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken__3C_ COMMA_SOURCE_FILE ("arxml_parser.galgas", 223)) ;
  inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken_name COMMA_SOURCE_FILE ("arxml_parser.galgas", 224)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_arxml_5F_parser_2 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken_name COMMA_SOURCE_FILE ("arxml_parser.galgas", 228)) ;
      inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxml_parser.galgas", 229)) ;
      inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken_value COMMA_SOURCE_FILE ("arxml_parser.galgas", 230)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  switch (select_arxml_5F_parser_3 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken__2F__3E_ COMMA_SOURCE_FILE ("arxml_parser.galgas", 236)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxml_parser.galgas", 238)) ;
    nt_element_5F_list_parse (inCompiler) ;
    inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken__3C__2F_ COMMA_SOURCE_FILE ("arxml_parser.galgas", 246)) ;
    inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken_name COMMA_SOURCE_FILE ("arxml_parser.galgas", 247)) ;
    inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxml_parser.galgas", 252)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_arxmlElementNode::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_arxmlElementNode * p = (const cPtr_arxmlElementNode *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_arxmlElementNode) ;
  if (kOperandEqual == result) {
    result = mProperty_name.objectCompare (p->mProperty_name) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_attributes.objectCompare (p->mProperty_attributes) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_enclosedNodes.objectCompare (p->mProperty_enclosedNodes) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_arxmlElementNode::objectCompare (const GALGAS_arxmlElementNode & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementNode::GALGAS_arxmlElementNode (void) :
GALGAS_arxmlNode () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementNode GALGAS_arxmlElementNode::constructor_default (LOCATION_ARGS) {
  return GALGAS_arxmlElementNode::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                                   GALGAS_arxmlAttributeMap::constructor_emptyMap (HERE),
                                                   GALGAS_arxmlNodeList::constructor_emptyList (HERE)
                                                   COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementNode::GALGAS_arxmlElementNode (const cPtr_arxmlElementNode * inSourcePtr) :
GALGAS_arxmlNode (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_arxmlElementNode) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementNode GALGAS_arxmlElementNode::constructor_new (const GALGAS_lstring & inAttribute_name,
                                                                  const GALGAS_arxmlAttributeMap & inAttribute_attributes,
                                                                  const GALGAS_arxmlNodeList & inAttribute_enclosedNodes
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_arxmlElementNode result ;
  if (inAttribute_name.isValid () && inAttribute_attributes.isValid () && inAttribute_enclosedNodes.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_arxmlElementNode (inAttribute_name, inAttribute_attributes, inAttribute_enclosedNodes COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_arxmlElementNode::readProperty_name (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_lstring () ;
  }else{
    const cPtr_arxmlElementNode * p = (const cPtr_arxmlElementNode *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlElementNode) ;
    return p->mProperty_name ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_arxmlElementNode::getter_name (UNUSED_LOCATION_ARGS) const {
  return mProperty_name ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlAttributeMap GALGAS_arxmlElementNode::readProperty_attributes (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_arxmlAttributeMap () ;
  }else{
    const cPtr_arxmlElementNode * p = (const cPtr_arxmlElementNode *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlElementNode) ;
    return p->mProperty_attributes ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlAttributeMap cPtr_arxmlElementNode::getter_attributes (UNUSED_LOCATION_ARGS) const {
  return mProperty_attributes ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlNodeList GALGAS_arxmlElementNode::readProperty_enclosedNodes (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_arxmlNodeList () ;
  }else{
    const cPtr_arxmlElementNode * p = (const cPtr_arxmlElementNode *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlElementNode) ;
    return p->mProperty_enclosedNodes ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlNodeList cPtr_arxmlElementNode::getter_enclosedNodes (UNUSED_LOCATION_ARGS) const {
  return mProperty_enclosedNodes ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlElementNode::setter_setName (GALGAS_lstring inValue
                                              COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_arxmlElementNode * p = (cPtr_arxmlElementNode *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlElementNode) ;
    p->mProperty_name = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_arxmlElementNode::setter_setName (GALGAS_lstring inValue
                                            COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_name = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlElementNode::setter_setAttributes (GALGAS_arxmlAttributeMap inValue
                                                    COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_arxmlElementNode * p = (cPtr_arxmlElementNode *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlElementNode) ;
    p->mProperty_attributes = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_arxmlElementNode::setter_setAttributes (GALGAS_arxmlAttributeMap inValue
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_attributes = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlElementNode::setter_setEnclosedNodes (GALGAS_arxmlNodeList inValue
                                                       COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_arxmlElementNode * p = (cPtr_arxmlElementNode *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlElementNode) ;
    p->mProperty_enclosedNodes = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_arxmlElementNode::setter_setEnclosedNodes (GALGAS_arxmlNodeList inValue
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_enclosedNodes = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @arxmlElementNode class
//----------------------------------------------------------------------------------------------------------------------

cPtr_arxmlElementNode::cPtr_arxmlElementNode (const GALGAS_lstring & in_name,
                                              const GALGAS_arxmlAttributeMap & in_attributes,
                                              const GALGAS_arxmlNodeList & in_enclosedNodes
                                              COMMA_LOCATION_ARGS) :
cPtr_arxmlNode (THERE),
mProperty_name (in_name),
mProperty_attributes (in_attributes),
mProperty_enclosedNodes (in_enclosedNodes) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_arxmlElementNode::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_arxmlElementNode ;
}

void cPtr_arxmlElementNode::description (C_String & ioString,
                                         const int32_t inIndentation) const {
  ioString << "[@arxmlElementNode:" ;
  mProperty_name.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_attributes.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_enclosedNodes.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_arxmlElementNode::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_arxmlElementNode (mProperty_name, mProperty_attributes, mProperty_enclosedNodes COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//@arxmlElementNode type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_arxmlElementNode ("arxmlElementNode",
                                         & kTypeDescriptor_GALGAS_arxmlNode) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_arxmlElementNode::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_arxmlElementNode ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_arxmlElementNode::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_arxmlElementNode (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementNode GALGAS_arxmlElementNode::extractObject (const GALGAS_object & inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) {
  GALGAS_arxmlElementNode result ;
  const GALGAS_arxmlElementNode * p = (const GALGAS_arxmlElementNode *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_arxmlElementNode *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("arxmlElementNode", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@arxmlElementNode getSubElements'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_arxmlElementNode::method_getSubElements (GALGAS_arxmlElementList & outArgument_nodeList,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_nodeList = GALGAS_arxmlElementList::constructor_emptyList (SOURCE_FILE ("arxml_types.galgas", 208)) ;
  cEnumerator_arxmlNodeList enumerator_4572 (this->mProperty_enclosedNodes, kENUMERATION_UP) ;
  while (enumerator_4572.hasCurrentObject ()) {
    enumGalgasBool test_0 = kBoolTrue ;
    if (kBoolTrue == test_0) {
      test_0 = GALGAS_bool (enumerator_4572.current_node (HERE).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_arxmlElementNode).boolEnum () ;
      if (kBoolTrue == test_0) {
        GALGAS_arxmlElementNode temp_1 ;
        if (enumerator_4572.current_node (HERE).isValid ()) {
          if (NULL != dynamic_cast <const cPtr_arxmlElementNode *> (enumerator_4572.current_node (HERE).ptr ())) {
            temp_1 = (cPtr_arxmlElementNode *) enumerator_4572.current_node (HERE).ptr () ;
          }else{
            inCompiler->castError ("arxmlElementNode", enumerator_4572.current_node (HERE).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("arxml_types.galgas", 212)) ;
          }
        }
        GALGAS_arxmlElementNode var_currentElement_4684 = temp_1 ;
        outArgument_nodeList.addAssign_operation (var_currentElement_4684  COMMA_SOURCE_FILE ("arxml_types.galgas", 213)) ;
      }
    }
    enumerator_4572.gotoNextObject () ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_getSubElements (cPtr_arxmlElementNode * inObject,
                                         GALGAS_arxmlElementList & out_nodeList,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
  out_nodeList.drop () ;
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_arxmlElementNode) ;
    inObject->method_getSubElements  (out_nodeList, inCompiler COMMA_THERE) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@arxmlElementNode getText'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_arxmlElementNode::method_getText (GALGAS_lstring & ioArgument_value,
                                            GALGAS_bool & ioArgument_found,
                                            C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) {
  cEnumerator_arxmlNodeList enumerator_5184 (this->mProperty_enclosedNodes, kENUMERATION_UP) ;
  bool bool_0 = ioArgument_found.operator_not (SOURCE_FILE ("arxml_types.galgas", 241)).isValidAndTrue () ;
  if (enumerator_5184.hasCurrentObject () && bool_0) {
    while (enumerator_5184.hasCurrentObject () && bool_0) {
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = GALGAS_bool (enumerator_5184.current_node (HERE).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_arxmlTextNode).boolEnum () ;
        if (kBoolTrue == test_1) {
          GALGAS_arxmlTextNode temp_2 ;
          if (enumerator_5184.current_node (HERE).isValid ()) {
            if (NULL != dynamic_cast <const cPtr_arxmlTextNode *> (enumerator_5184.current_node (HERE).ptr ())) {
              temp_2 = (cPtr_arxmlTextNode *) enumerator_5184.current_node (HERE).ptr () ;
            }else{
              inCompiler->castError ("arxmlTextNode", enumerator_5184.current_node (HERE).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("arxml_types.galgas", 244)) ;
            }
          }
          GALGAS_arxmlTextNode var_textnode_5300 = temp_2 ;
          callExtensionMethod_getText ((cPtr_arxmlTextNode *) var_textnode_5300.ptr (), ioArgument_value, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 245)) ;
          ioArgument_found = GALGAS_bool (true) ;
        }
      }
      enumerator_5184.gotoNextObject () ;
      if (enumerator_5184.hasCurrentObject ()) {
        bool_0 = ioArgument_found.operator_not (SOURCE_FILE ("arxml_types.galgas", 241)).isValidAndTrue () ;
      }
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_getText (cPtr_arxmlElementNode * inObject,
                                  GALGAS_lstring & io_value,
                                  GALGAS_bool & io_found,
                                  C_Compiler * inCompiler
                                  COMMA_LOCATION_ARGS) {
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_arxmlElementNode) ;
    inObject->method_getText  (io_value, io_found, inCompiler COMMA_THERE) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@arxmlElementNode getAttributes'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_arxmlElementNode::method_getAttributes (GALGAS_arxmlAttributeMap & ioArgument_outAttributes,
                                                  C_Compiler * /* inCompiler */
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  ioArgument_outAttributes = this->mProperty_attributes ;
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_getAttributes (cPtr_arxmlElementNode * inObject,
                                        GALGAS_arxmlAttributeMap & io_outAttributes,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) {
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_arxmlElementNode) ;
    inObject->method_getAttributes  (io_outAttributes, inCompiler COMMA_THERE) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@arxmlElementNode getAttribute'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_arxmlElementNode::method_getAttribute (GALGAS_string inArgument_attributeName,
                                                 GALGAS_lstring & outArgument_outAttribute,
                                                 C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  this->mProperty_attributes.method_searchKey (function_lstringWith (inArgument_attributeName, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 261)), outArgument_outAttribute, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 261)) ;
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_getAttribute (cPtr_arxmlElementNode * inObject,
                                       GALGAS_string in_attributeName,
                                       GALGAS_lstring & out_outAttribute,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) {
  out_outAttribute.drop () ;
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_arxmlElementNode) ;
    inObject->method_getAttribute  (in_attributeName, out_outAttribute, inCompiler COMMA_THERE) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@arxmlElementNode getName'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_arxmlElementNode::method_getName (GALGAS_lstring & outArgument_outName,
                                            C_Compiler * /* inCompiler */
                                            COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_outName = this->mProperty_name ;
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_getName (cPtr_arxmlElementNode * inObject,
                                  GALGAS_lstring & out_outName,
                                  C_Compiler * inCompiler
                                  COMMA_LOCATION_ARGS) {
  out_outName.drop () ;
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_arxmlElementNode) ;
    inObject->method_getName  (out_outName, inCompiler COMMA_THERE) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_arxmlCommentNode::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_arxmlCommentNode * p = (const cPtr_arxmlCommentNode *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_arxmlCommentNode) ;
  if (kOperandEqual == result) {
    result = mProperty_comment.objectCompare (p->mProperty_comment) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_arxmlCommentNode::objectCompare (const GALGAS_arxmlCommentNode & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlCommentNode::GALGAS_arxmlCommentNode (void) :
GALGAS_arxmlNode () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlCommentNode GALGAS_arxmlCommentNode::constructor_default (LOCATION_ARGS) {
  return GALGAS_arxmlCommentNode::constructor_new (GALGAS_lstring::constructor_default (HERE)
                                                   COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlCommentNode::GALGAS_arxmlCommentNode (const cPtr_arxmlCommentNode * inSourcePtr) :
GALGAS_arxmlNode (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_arxmlCommentNode) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlCommentNode GALGAS_arxmlCommentNode::constructor_new (const GALGAS_lstring & inAttribute_comment
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_arxmlCommentNode result ;
  if (inAttribute_comment.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_arxmlCommentNode (inAttribute_comment COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_arxmlCommentNode::readProperty_comment (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_lstring () ;
  }else{
    const cPtr_arxmlCommentNode * p = (const cPtr_arxmlCommentNode *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlCommentNode) ;
    return p->mProperty_comment ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_arxmlCommentNode::getter_comment (UNUSED_LOCATION_ARGS) const {
  return mProperty_comment ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlCommentNode::setter_setComment (GALGAS_lstring inValue
                                                 COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_arxmlCommentNode * p = (cPtr_arxmlCommentNode *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlCommentNode) ;
    p->mProperty_comment = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_arxmlCommentNode::setter_setComment (GALGAS_lstring inValue
                                               COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_comment = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @arxmlCommentNode class
//----------------------------------------------------------------------------------------------------------------------

cPtr_arxmlCommentNode::cPtr_arxmlCommentNode (const GALGAS_lstring & in_comment
                                              COMMA_LOCATION_ARGS) :
cPtr_arxmlNode (THERE),
mProperty_comment (in_comment) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_arxmlCommentNode::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_arxmlCommentNode ;
}

void cPtr_arxmlCommentNode::description (C_String & ioString,
                                         const int32_t inIndentation) const {
  ioString << "[@arxmlCommentNode:" ;
  mProperty_comment.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_arxmlCommentNode::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_arxmlCommentNode (mProperty_comment COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//@arxmlCommentNode type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_arxmlCommentNode ("arxmlCommentNode",
                                         & kTypeDescriptor_GALGAS_arxmlNode) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_arxmlCommentNode::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_arxmlCommentNode ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_arxmlCommentNode::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_arxmlCommentNode (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlCommentNode GALGAS_arxmlCommentNode::extractObject (const GALGAS_object & inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) {
  GALGAS_arxmlCommentNode result ;
  const GALGAS_arxmlCommentNode * p = (const GALGAS_arxmlCommentNode *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_arxmlCommentNode *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("arxmlCommentNode", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_arxmlTextNode::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_arxmlTextNode * p = (const cPtr_arxmlTextNode *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_arxmlTextNode) ;
  if (kOperandEqual == result) {
    result = mProperty_text.objectCompare (p->mProperty_text) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_arxmlTextNode::objectCompare (const GALGAS_arxmlTextNode & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlTextNode::GALGAS_arxmlTextNode (void) :
GALGAS_arxmlNode () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlTextNode GALGAS_arxmlTextNode::constructor_default (LOCATION_ARGS) {
  return GALGAS_arxmlTextNode::constructor_new (GALGAS_lstring::constructor_default (HERE)
                                                COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlTextNode::GALGAS_arxmlTextNode (const cPtr_arxmlTextNode * inSourcePtr) :
GALGAS_arxmlNode (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_arxmlTextNode) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlTextNode GALGAS_arxmlTextNode::constructor_new (const GALGAS_lstring & inAttribute_text
                                                            COMMA_LOCATION_ARGS) {
  GALGAS_arxmlTextNode result ;
  if (inAttribute_text.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_arxmlTextNode (inAttribute_text COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_arxmlTextNode::readProperty_text (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_lstring () ;
  }else{
    const cPtr_arxmlTextNode * p = (const cPtr_arxmlTextNode *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlTextNode) ;
    return p->mProperty_text ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_arxmlTextNode::getter_text (UNUSED_LOCATION_ARGS) const {
  return mProperty_text ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlTextNode::setter_setText (GALGAS_lstring inValue
                                           COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_arxmlTextNode * p = (cPtr_arxmlTextNode *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlTextNode) ;
    p->mProperty_text = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_arxmlTextNode::setter_setText (GALGAS_lstring inValue
                                         COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_text = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @arxmlTextNode class
//----------------------------------------------------------------------------------------------------------------------

cPtr_arxmlTextNode::cPtr_arxmlTextNode (const GALGAS_lstring & in_text
                                        COMMA_LOCATION_ARGS) :
cPtr_arxmlNode (THERE),
mProperty_text (in_text) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_arxmlTextNode::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_arxmlTextNode ;
}

void cPtr_arxmlTextNode::description (C_String & ioString,
                                      const int32_t inIndentation) const {
  ioString << "[@arxmlTextNode:" ;
  mProperty_text.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_arxmlTextNode::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_arxmlTextNode (mProperty_text COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//@arxmlTextNode type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_arxmlTextNode ("arxmlTextNode",
                                      & kTypeDescriptor_GALGAS_arxmlNode) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_arxmlTextNode::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_arxmlTextNode ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_arxmlTextNode::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_arxmlTextNode (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlTextNode GALGAS_arxmlTextNode::extractObject (const GALGAS_object & inObject,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) {
  GALGAS_arxmlTextNode result ;
  const GALGAS_arxmlTextNode * p = (const GALGAS_arxmlTextNode *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_arxmlTextNode *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("arxmlTextNode", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@arxmlTextNode getText'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_arxmlTextNode::method_getText (GALGAS_lstring & outArgument_outText,
                                         C_Compiler * /* inCompiler */
                                         COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_outText = this->mProperty_text ;
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_getText (cPtr_arxmlTextNode * inObject,
                                  GALGAS_lstring & out_outText,
                                  C_Compiler * inCompiler
                                  COMMA_LOCATION_ARGS) {
  out_outText.drop () ;
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_arxmlTextNode) ;
    inObject->method_getText  (out_outText, inCompiler COMMA_THERE) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_arxmlElementValue::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_arxmlElementValue * p = (const cPtr_arxmlElementValue *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_arxmlElementValue) ;
  if (kOperandEqual == result) {
    result = mProperty_type.objectCompare (p->mProperty_type) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_text.objectCompare (p->mProperty_text) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_elements.objectCompare (p->mProperty_elements) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_attributes.objectCompare (p->mProperty_attributes) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_arxmlElementValue::objectCompare (const GALGAS_arxmlElementValue & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementValue::GALGAS_arxmlElementValue (void) :
AC_GALGAS_value_class () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementValue GALGAS_arxmlElementValue::constructor_default (LOCATION_ARGS) {
  return GALGAS_arxmlElementValue::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                                    GALGAS_lstring::constructor_default (HERE),
                                                    GALGAS_arxmlElementValueMap::constructor_emptyMap (HERE),
                                                    GALGAS_arxmlAttributeMap::constructor_emptyMap (HERE)
                                                    COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementValue::GALGAS_arxmlElementValue (const cPtr_arxmlElementValue * inSourcePtr) :
AC_GALGAS_value_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_arxmlElementValue) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementValue GALGAS_arxmlElementValue::constructor_new (const GALGAS_lstring & inAttribute_type,
                                                                    const GALGAS_lstring & inAttribute_text,
                                                                    const GALGAS_arxmlElementValueMap & inAttribute_elements,
                                                                    const GALGAS_arxmlAttributeMap & inAttribute_attributes
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_arxmlElementValue result ;
  if (inAttribute_type.isValid () && inAttribute_text.isValid () && inAttribute_elements.isValid () && inAttribute_attributes.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_arxmlElementValue (inAttribute_type, inAttribute_text, inAttribute_elements, inAttribute_attributes COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_arxmlElementValue::readProperty_type (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_lstring () ;
  }else{
    const cPtr_arxmlElementValue * p = (const cPtr_arxmlElementValue *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlElementValue) ;
    return p->mProperty_type ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_arxmlElementValue::getter_type (UNUSED_LOCATION_ARGS) const {
  return mProperty_type ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_arxmlElementValue::readProperty_text (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_lstring () ;
  }else{
    const cPtr_arxmlElementValue * p = (const cPtr_arxmlElementValue *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlElementValue) ;
    return p->mProperty_text ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_arxmlElementValue::getter_text (UNUSED_LOCATION_ARGS) const {
  return mProperty_text ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementValueMap GALGAS_arxmlElementValue::readProperty_elements (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_arxmlElementValueMap () ;
  }else{
    const cPtr_arxmlElementValue * p = (const cPtr_arxmlElementValue *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlElementValue) ;
    return p->mProperty_elements ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementValueMap cPtr_arxmlElementValue::getter_elements (UNUSED_LOCATION_ARGS) const {
  return mProperty_elements ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlAttributeMap GALGAS_arxmlElementValue::readProperty_attributes (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_arxmlAttributeMap () ;
  }else{
    const cPtr_arxmlElementValue * p = (const cPtr_arxmlElementValue *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlElementValue) ;
    return p->mProperty_attributes ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlAttributeMap cPtr_arxmlElementValue::getter_attributes (UNUSED_LOCATION_ARGS) const {
  return mProperty_attributes ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlElementValue::setter_setType (GALGAS_lstring inValue
                                               COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_arxmlElementValue * p = (cPtr_arxmlElementValue *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlElementValue) ;
    p->mProperty_type = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_arxmlElementValue::setter_setType (GALGAS_lstring inValue
                                             COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_type = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlElementValue::setter_setText (GALGAS_lstring inValue
                                               COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_arxmlElementValue * p = (cPtr_arxmlElementValue *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlElementValue) ;
    p->mProperty_text = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_arxmlElementValue::setter_setText (GALGAS_lstring inValue
                                             COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_text = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlElementValue::setter_setElements (GALGAS_arxmlElementValueMap inValue
                                                   COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_arxmlElementValue * p = (cPtr_arxmlElementValue *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlElementValue) ;
    p->mProperty_elements = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_arxmlElementValue::setter_setElements (GALGAS_arxmlElementValueMap inValue
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_elements = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlElementValue::setter_setAttributes (GALGAS_arxmlAttributeMap inValue
                                                     COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_arxmlElementValue * p = (cPtr_arxmlElementValue *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlElementValue) ;
    p->mProperty_attributes = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_arxmlElementValue::setter_setAttributes (GALGAS_arxmlAttributeMap inValue
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_attributes = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @arxmlElementValue class
//----------------------------------------------------------------------------------------------------------------------

cPtr_arxmlElementValue::cPtr_arxmlElementValue (const GALGAS_lstring & in_type,
                                                const GALGAS_lstring & in_text,
                                                const GALGAS_arxmlElementValueMap & in_elements,
                                                const GALGAS_arxmlAttributeMap & in_attributes
                                                COMMA_LOCATION_ARGS) :
acPtr_class (THERE),
mProperty_type (in_type),
mProperty_text (in_text),
mProperty_elements (in_elements),
mProperty_attributes (in_attributes) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_arxmlElementValue::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_arxmlElementValue ;
}

void cPtr_arxmlElementValue::description (C_String & ioString,
                                          const int32_t inIndentation) const {
  ioString << "[@arxmlElementValue:" ;
  mProperty_type.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_text.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_elements.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_attributes.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_arxmlElementValue::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_arxmlElementValue (mProperty_type, mProperty_text, mProperty_elements, mProperty_attributes COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//@arxmlElementValue type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_arxmlElementValue ("arxmlElementValue",
                                          NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_arxmlElementValue::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_arxmlElementValue ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_arxmlElementValue::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_arxmlElementValue (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementValue GALGAS_arxmlElementValue::extractObject (const GALGAS_object & inObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_arxmlElementValue result ;
  const GALGAS_arxmlElementValue * p = (const GALGAS_arxmlElementValue *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_arxmlElementValue *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("arxmlElementValue", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Extension setter '@arxmlElementValue insertElement'
//
//----------------------------------------------------------------------------------------------------------------------

static TC_UniqueArray <extensionSetterSignature_arxmlElementValue_insertElement> gExtensionModifierTable_arxmlElementValue_insertElement ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionSetter_insertElement (const int32_t inClassIndex,
                                         extensionSetterSignature_arxmlElementValue_insertElement inModifier) {
  gExtensionModifierTable_arxmlElementValue_insertElement.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionSetter_insertElement (cPtr_arxmlElementValue * inObject,
                                        GALGAS_lstring in_key,
                                        GALGAS_arxmlElementValue in_element,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_arxmlElementValue) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_arxmlElementValue_insertElement f = NULL ;
    if (classIndex < gExtensionModifierTable_arxmlElementValue_insertElement.count ()) {
      f = gExtensionModifierTable_arxmlElementValue_insertElement (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_arxmlElementValue_insertElement.count ()) {
           f = gExtensionModifierTable_arxmlElementValue_insertElement (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_arxmlElementValue_insertElement.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, in_key, in_element, inCompiler COMMA_THERE) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void extensionSetter_arxmlElementValue_insertElement (cPtr_arxmlElementValue * inObject,
                                                             GALGAS_lstring inArgument_key,
                                                             GALGAS_arxmlElementValue inArgument_element,
                                                             C_Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_arxmlElementValue * object = inObject ;
  macroValidSharedObject (object, cPtr_arxmlElementValue) ;
  GALGAS_arxmlElementValueList var_keyList_8400 ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = object->mProperty_elements.getter_hasKey (inArgument_key.readProperty_string () COMMA_SOURCE_FILE ("arxml_types.galgas", 385)).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      object->mProperty_elements.setter_removeKey (inArgument_key, var_keyList_8400, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 386)) ;
      }
    }
  }
  if (kBoolFalse == test_0) {
    var_keyList_8400 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_types.galgas", 388)) ;
  }
  var_keyList_8400.addAssign_operation (inArgument_element  COMMA_SOURCE_FILE ("arxml_types.galgas", 390)) ;
  {
  object->mProperty_elements.setter_insertKey (inArgument_key, var_keyList_8400, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 391)) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionSetter_arxmlElementValue_insertElement (void) {
  enterExtensionSetter_insertElement (kTypeDescriptor_GALGAS_arxmlElementValue.mSlotID,
                                      extensionSetter_arxmlElementValue_insertElement) ;
}

//----------------------------------------------------------------------------------------------------------------------

static void freeExtensionModifier_arxmlElementValue_insertElement (void) {
  gExtensionModifierTable_arxmlElementValue_insertElement.free () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gSetter_arxmlElementValue_insertElement (defineExtensionSetter_arxmlElementValue_insertElement,
                                                            freeExtensionModifier_arxmlElementValue_insertElement) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@arxmlElementValue getElementsByPath'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_arxmlElementValue::method_getElementsByPath (GALGAS_stringlist inArgument_path,
                                                       GALGAS_arxmlElementValueList & ioArgument_outElements,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, inArgument_path.getter_length (SOURCE_FILE ("arxml_types.galgas", 398)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      const GALGAS_arxmlElementValue temp_1 = this ;
      ioArgument_outElements.addAssign_operation (temp_1  COMMA_SOURCE_FILE ("arxml_types.galgas", 399)) ;
    }
  }
  if (kBoolFalse == test_0) {
    GALGAS_stringlist var_pathCopy_8759 = inArgument_path ;
    GALGAS_string var_nextInPathName_8797 ;
    GALGAS_arxmlElementValueList var_nextInPathElems_8844 ;
    {
    var_pathCopy_8759.setter_popFirst (var_nextInPathName_8797, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 404)) ;
    }
    const GALGAS_arxmlElementValue temp_2 = this ;
    callExtensionMethod_getElements ((cPtr_arxmlElementValue *) temp_2.ptr (), var_nextInPathName_8797, var_nextInPathElems_8844, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 405)) ;
    cEnumerator_arxmlElementValueList enumerator_8978 (var_nextInPathElems_8844, kENUMERATION_UP) ;
    while (enumerator_8978.hasCurrentObject ()) {
      callExtensionMethod_getElementsByPath ((cPtr_arxmlElementValue *) enumerator_8978.current_value (HERE).ptr (), var_pathCopy_8759, ioArgument_outElements, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 407)) ;
      enumerator_8978.gotoNextObject () ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_getElementsByPath (cPtr_arxmlElementValue * inObject,
                                            GALGAS_stringlist in_path,
                                            GALGAS_arxmlElementValueList & io_outElements,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_arxmlElementValue) ;
    inObject->method_getElementsByPath  (in_path, io_outElements, inCompiler COMMA_THERE) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@arxmlElementValue getElements'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_arxmlElementValue::method_getElements (GALGAS_string inArgument_elementName,
                                                 GALGAS_arxmlElementValueList & outArgument_outElements,
                                                 C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring var_key_9197 = GALGAS_lstring::constructor_new (inArgument_elementName, GALGAS_location::constructor_nowhere (SOURCE_FILE ("arxml_types.galgas", 416))  COMMA_SOURCE_FILE ("arxml_types.galgas", 416)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = this->mProperty_elements.getter_hasKey (var_key_9197.readProperty_string () COMMA_SOURCE_FILE ("arxml_types.galgas", 417)).boolEnum () ;
    if (kBoolTrue == test_0) {
      this->mProperty_elements.method_searchKey (var_key_9197, outArgument_outElements, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 418)) ;
    }
  }
  if (kBoolFalse == test_0) {
    outArgument_outElements = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_types.galgas", 420)) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_getElements (cPtr_arxmlElementValue * inObject,
                                      GALGAS_string in_elementName,
                                      GALGAS_arxmlElementValueList & out_outElements,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) {
  out_outElements.drop () ;
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_arxmlElementValue) ;
    inObject->method_getElements  (in_elementName, out_outElements, inCompiler COMMA_THERE) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@arxmlElementValue getElement'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_arxmlElementValue::method_getElement (GALGAS_string inArgument_elementName,
                                                GALGAS_arxmlElementValue & outArgument_outElement,
                                                C_Compiler * inCompiler
                                                COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_arxmlElementValueList var_foundElements_9479 ;
  const GALGAS_arxmlElementValue temp_0 = this ;
  callExtensionMethod_getElements ((cPtr_arxmlElementValue *) temp_0.ptr (), inArgument_elementName, var_foundElements_9479, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 429)) ;
  enumGalgasBool test_1 = kBoolTrue ;
  if (kBoolTrue == test_1) {
    test_1 = GALGAS_bool (kIsNotEqual, var_foundElements_9479.getter_length (SOURCE_FILE ("arxml_types.galgas", 430)).objectCompare (GALGAS_uint (uint32_t (1U)))).boolEnum () ;
    if (kBoolTrue == test_1) {
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxml_types.galgas", 431)), GALGAS_string ("Found ").add_operation (var_foundElements_9479.getter_length (SOURCE_FILE ("arxml_types.galgas", 431)).getter_string (SOURCE_FILE ("arxml_types.galgas", 431)), inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 431)).add_operation (GALGAS_string (" elements"), inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 431)).add_operation (GALGAS_string (" while searching for exactly one "), inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 431)).add_operation (inArgument_elementName, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 432)).add_operation (GALGAS_string (" in "), inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 432)).add_operation (this->mProperty_type.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 433)), fixItArray2  COMMA_SOURCE_FILE ("arxml_types.galgas", 431)) ;
      outArgument_outElement.drop () ; // Release error dropped variable
    }
  }
  if (kBoolFalse == test_1) {
    var_foundElements_9479.method_first (outArgument_outElement, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 435)) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_getElement (cPtr_arxmlElementValue * inObject,
                                     GALGAS_string in_elementName,
                                     GALGAS_arxmlElementValue & out_outElement,
                                     C_Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) {
  out_outElement.drop () ;
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_arxmlElementValue) ;
    inObject->method_getElement  (in_elementName, out_outElement, inCompiler COMMA_THERE) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@arxmlElementValue hasElement'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_arxmlElementValue::getter_hasElement (GALGAS_string inArgument_elementName,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_outBool ; // Returned variable
  GALGAS_arxmlElementValueList var_foundElements_9932 ;
  const GALGAS_arxmlElementValue temp_0 = this ;
  callExtensionMethod_getElements ((cPtr_arxmlElementValue *) temp_0.ptr (), inArgument_elementName, var_foundElements_9932, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 444)) ;
  enumGalgasBool test_1 = kBoolTrue ;
  if (kBoolTrue == test_1) {
    test_1 = GALGAS_bool (kIsNotEqual, var_foundElements_9932.getter_length (SOURCE_FILE ("arxml_types.galgas", 445)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
    if (kBoolTrue == test_1) {
      result_outBool = GALGAS_bool (true) ;
    }
  }
  if (kBoolFalse == test_1) {
    result_outBool = GALGAS_bool (false) ;
  }
//---
  return result_outBool ;
}



//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool callExtensionGetter_hasElement (const cPtr_arxmlElementValue * inObject,
                                            GALGAS_string in_elementName,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
  GALGAS_bool result ;
  if (nullptr != inObject) {
    result = inObject->getter_hasElement (in_elementName, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@arxmlElementValue getTextFromElement'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_arxmlElementValue::getter_getTextFromElement (GALGAS_string inArgument_elementName,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result_outText ; // Returned variable
  GALGAS_arxmlElementValue var_textElement_10203 ;
  const GALGAS_arxmlElementValue temp_0 = this ;
  callExtensionMethod_getElement ((cPtr_arxmlElementValue *) temp_0.ptr (), inArgument_elementName, var_textElement_10203, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 457)) ;
  result_outText = var_textElement_10203.readProperty_text () ;
//---
  return result_outText ;
}



//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring callExtensionGetter_getTextFromElement (const cPtr_arxmlElementValue * inObject,
                                                       GALGAS_string in_elementName,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) {
  GALGAS_lstring result ;
  if (nullptr != inObject) {
    result = inObject->getter_getTextFromElement (in_elementName, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@arxmlElementValue getAllTextsInSelf'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_arxmlElementValue::method_getAllTextsInSelf (GALGAS_string inArgument_separator,
                                                       GALGAS_lstring & ioArgument_outString,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsNotEqual, this->mProperty_text.readProperty_string ().objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = GALGAS_bool (kIsNotEqual, ioArgument_outString.readProperty_string ().objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
        if (kBoolTrue == test_1) {
          ioArgument_outString.mProperty_string.plusAssign_operation(inArgument_separator, inCompiler  COMMA_SOURCE_FILE ("arxml_types.galgas", 467)) ;
        }
      }
      enumGalgasBool test_2 = kBoolTrue ;
      if (kBoolTrue == test_2) {
        test_2 = GALGAS_bool (kIsEqual, ioArgument_outString.readProperty_location ().objectCompare (GALGAS_location::constructor_nowhere (SOURCE_FILE ("arxml_types.galgas", 469)))).boolEnum () ;
        if (kBoolTrue == test_2) {
          ioArgument_outString.setter_setLocation (this->mProperty_text.readProperty_location () COMMA_SOURCE_FILE ("arxml_types.galgas", 470)) ;
        }
      }
      ioArgument_outString.mProperty_string.plusAssign_operation(this->mProperty_text.readProperty_string (), inCompiler  COMMA_SOURCE_FILE ("arxml_types.galgas", 472)) ;
    }
  }
  cEnumerator_arxmlElementValueMap enumerator_10634 (this->mProperty_elements, kENUMERATION_UP) ;
  while (enumerator_10634.hasCurrentObject ()) {
    cEnumerator_arxmlElementValueList enumerator_10660 (enumerator_10634.current_values (HERE), kENUMERATION_UP) ;
    while (enumerator_10660.hasCurrentObject ()) {
      callExtensionMethod_getAllTextsInSelf ((cPtr_arxmlElementValue *) enumerator_10660.current_value (HERE).ptr (), inArgument_separator, ioArgument_outString, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 477)) ;
      enumerator_10660.gotoNextObject () ;
    }
    enumerator_10634.gotoNextObject () ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_getAllTextsInSelf (cPtr_arxmlElementValue * inObject,
                                            GALGAS_string in_separator,
                                            GALGAS_lstring & io_outString,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_arxmlElementValue) ;
    inObject->method_getAllTextsInSelf  (in_separator, io_outString, inCompiler COMMA_THERE) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@arxmlElementValue getAttributeValueFromElement'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_arxmlElementValue::getter_getAttributeValueFromElement (GALGAS_string inArgument_elementName,
                                                                            GALGAS_string inArgument_attributeName,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result_outText ; // Returned variable
  GALGAS_arxmlElementValue var_textElement_10909 ;
  const GALGAS_arxmlElementValue temp_0 = this ;
  callExtensionMethod_getElement ((cPtr_arxmlElementValue *) temp_0.ptr (), inArgument_elementName, var_textElement_10909, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 488)) ;
  GALGAS_lstring var_attributeNamelString_10991 = GALGAS_lstring::constructor_new (inArgument_attributeName, GALGAS_location::constructor_nowhere (SOURCE_FILE ("arxml_types.galgas", 489))  COMMA_SOURCE_FILE ("arxml_types.galgas", 489)) ;
  var_textElement_10909.readProperty_attributes ().method_searchKey (var_attributeNamelString_10991, result_outText, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 490)) ;
//---
  return result_outText ;
}



//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring callExtensionGetter_getAttributeValueFromElement (const cPtr_arxmlElementValue * inObject,
                                                                 GALGAS_string in_elementName,
                                                                 GALGAS_string in_attributeName,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) {
  GALGAS_lstring result ;
  if (nullptr != inObject) {
    result = inObject->getter_getAttributeValueFromElement (in_elementName, in_attributeName, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_arxmlMetaClass::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_arxmlMetaClass * p = (const cPtr_arxmlMetaClass *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_arxmlMetaClass) ;
  if (kOperandEqual == result) {
    result = mProperty_name.objectCompare (p->mProperty_name) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_isAbstract.objectCompare (p->mProperty_isAbstract) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_lElement.objectCompare (p->mProperty_lElement) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_lElementLegacy.objectCompare (p->mProperty_lElementLegacy) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_lAttribute.objectCompare (p->mProperty_lAttribute) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_lAttributeLegacy.objectCompare (p->mProperty_lAttributeLegacy) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_desc.objectCompare (p->mProperty_desc) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_arxmlMetaClass::objectCompare (const GALGAS_arxmlMetaClass & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaClass::GALGAS_arxmlMetaClass (void) :
AC_GALGAS_value_class () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaClass GALGAS_arxmlMetaClass::constructor_default (LOCATION_ARGS) {
  return GALGAS_arxmlMetaClass::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                                 GALGAS_bool::constructor_default (HERE),
                                                 GALGAS_arxmlMetaElementList::constructor_emptyList (HERE),
                                                 GALGAS_arxmlMetaElementList::constructor_emptyList (HERE),
                                                 GALGAS_arxmlMetaAttributeList::constructor_emptyList (HERE),
                                                 GALGAS_arxmlMetaAttributeList::constructor_emptyList (HERE),
                                                 GALGAS_lstring::constructor_default (HERE)
                                                 COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaClass::GALGAS_arxmlMetaClass (const cPtr_arxmlMetaClass * inSourcePtr) :
AC_GALGAS_value_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_arxmlMetaClass) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaClass GALGAS_arxmlMetaClass::constructor_new (const GALGAS_lstring & inAttribute_name,
                                                              const GALGAS_bool & inAttribute_isAbstract,
                                                              const GALGAS_arxmlMetaElementList & inAttribute_lElement,
                                                              const GALGAS_arxmlMetaElementList & inAttribute_lElementLegacy,
                                                              const GALGAS_arxmlMetaAttributeList & inAttribute_lAttribute,
                                                              const GALGAS_arxmlMetaAttributeList & inAttribute_lAttributeLegacy,
                                                              const GALGAS_lstring & inAttribute_desc
                                                              COMMA_LOCATION_ARGS) {
  GALGAS_arxmlMetaClass result ;
  if (inAttribute_name.isValid () && inAttribute_isAbstract.isValid () && inAttribute_lElement.isValid () && inAttribute_lElementLegacy.isValid () && inAttribute_lAttribute.isValid () && inAttribute_lAttributeLegacy.isValid () && inAttribute_desc.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_arxmlMetaClass (inAttribute_name, inAttribute_isAbstract, inAttribute_lElement, inAttribute_lElementLegacy, inAttribute_lAttribute, inAttribute_lAttributeLegacy, inAttribute_desc COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_arxmlMetaClass::readProperty_name (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_lstring () ;
  }else{
    const cPtr_arxmlMetaClass * p = (const cPtr_arxmlMetaClass *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlMetaClass) ;
    return p->mProperty_name ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_arxmlMetaClass::getter_name (UNUSED_LOCATION_ARGS) const {
  return mProperty_name ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_arxmlMetaClass::readProperty_isAbstract (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_bool () ;
  }else{
    const cPtr_arxmlMetaClass * p = (const cPtr_arxmlMetaClass *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlMetaClass) ;
    return p->mProperty_isAbstract ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_arxmlMetaClass::getter_isAbstract (UNUSED_LOCATION_ARGS) const {
  return mProperty_isAbstract ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaElementList GALGAS_arxmlMetaClass::readProperty_lElement (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_arxmlMetaElementList () ;
  }else{
    const cPtr_arxmlMetaClass * p = (const cPtr_arxmlMetaClass *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlMetaClass) ;
    return p->mProperty_lElement ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaElementList cPtr_arxmlMetaClass::getter_lElement (UNUSED_LOCATION_ARGS) const {
  return mProperty_lElement ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaElementList GALGAS_arxmlMetaClass::readProperty_lElementLegacy (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_arxmlMetaElementList () ;
  }else{
    const cPtr_arxmlMetaClass * p = (const cPtr_arxmlMetaClass *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlMetaClass) ;
    return p->mProperty_lElementLegacy ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaElementList cPtr_arxmlMetaClass::getter_lElementLegacy (UNUSED_LOCATION_ARGS) const {
  return mProperty_lElementLegacy ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaAttributeList GALGAS_arxmlMetaClass::readProperty_lAttribute (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_arxmlMetaAttributeList () ;
  }else{
    const cPtr_arxmlMetaClass * p = (const cPtr_arxmlMetaClass *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlMetaClass) ;
    return p->mProperty_lAttribute ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaAttributeList cPtr_arxmlMetaClass::getter_lAttribute (UNUSED_LOCATION_ARGS) const {
  return mProperty_lAttribute ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaAttributeList GALGAS_arxmlMetaClass::readProperty_lAttributeLegacy (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_arxmlMetaAttributeList () ;
  }else{
    const cPtr_arxmlMetaClass * p = (const cPtr_arxmlMetaClass *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlMetaClass) ;
    return p->mProperty_lAttributeLegacy ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaAttributeList cPtr_arxmlMetaClass::getter_lAttributeLegacy (UNUSED_LOCATION_ARGS) const {
  return mProperty_lAttributeLegacy ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_arxmlMetaClass::readProperty_desc (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_lstring () ;
  }else{
    const cPtr_arxmlMetaClass * p = (const cPtr_arxmlMetaClass *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlMetaClass) ;
    return p->mProperty_desc ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_arxmlMetaClass::getter_desc (UNUSED_LOCATION_ARGS) const {
  return mProperty_desc ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaClass::setter_setName (GALGAS_lstring inValue
                                            COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_arxmlMetaClass * p = (cPtr_arxmlMetaClass *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlMetaClass) ;
    p->mProperty_name = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_arxmlMetaClass::setter_setName (GALGAS_lstring inValue
                                          COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_name = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaClass::setter_setIsAbstract (GALGAS_bool inValue
                                                  COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_arxmlMetaClass * p = (cPtr_arxmlMetaClass *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlMetaClass) ;
    p->mProperty_isAbstract = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_arxmlMetaClass::setter_setIsAbstract (GALGAS_bool inValue
                                                COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_isAbstract = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaClass::setter_setLElement (GALGAS_arxmlMetaElementList inValue
                                                COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_arxmlMetaClass * p = (cPtr_arxmlMetaClass *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlMetaClass) ;
    p->mProperty_lElement = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_arxmlMetaClass::setter_setLElement (GALGAS_arxmlMetaElementList inValue
                                              COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_lElement = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaClass::setter_setLElementLegacy (GALGAS_arxmlMetaElementList inValue
                                                      COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_arxmlMetaClass * p = (cPtr_arxmlMetaClass *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlMetaClass) ;
    p->mProperty_lElementLegacy = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_arxmlMetaClass::setter_setLElementLegacy (GALGAS_arxmlMetaElementList inValue
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_lElementLegacy = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaClass::setter_setLAttribute (GALGAS_arxmlMetaAttributeList inValue
                                                  COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_arxmlMetaClass * p = (cPtr_arxmlMetaClass *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlMetaClass) ;
    p->mProperty_lAttribute = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_arxmlMetaClass::setter_setLAttribute (GALGAS_arxmlMetaAttributeList inValue
                                                COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_lAttribute = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaClass::setter_setLAttributeLegacy (GALGAS_arxmlMetaAttributeList inValue
                                                        COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_arxmlMetaClass * p = (cPtr_arxmlMetaClass *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlMetaClass) ;
    p->mProperty_lAttributeLegacy = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_arxmlMetaClass::setter_setLAttributeLegacy (GALGAS_arxmlMetaAttributeList inValue
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_lAttributeLegacy = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaClass::setter_setDesc (GALGAS_lstring inValue
                                            COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_arxmlMetaClass * p = (cPtr_arxmlMetaClass *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlMetaClass) ;
    p->mProperty_desc = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_arxmlMetaClass::setter_setDesc (GALGAS_lstring inValue
                                          COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_desc = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @arxmlMetaClass class
//----------------------------------------------------------------------------------------------------------------------

cPtr_arxmlMetaClass::cPtr_arxmlMetaClass (const GALGAS_lstring & in_name,
                                          const GALGAS_bool & in_isAbstract,
                                          const GALGAS_arxmlMetaElementList & in_lElement,
                                          const GALGAS_arxmlMetaElementList & in_lElementLegacy,
                                          const GALGAS_arxmlMetaAttributeList & in_lAttribute,
                                          const GALGAS_arxmlMetaAttributeList & in_lAttributeLegacy,
                                          const GALGAS_lstring & in_desc
                                          COMMA_LOCATION_ARGS) :
acPtr_class (THERE),
mProperty_name (in_name),
mProperty_isAbstract (in_isAbstract),
mProperty_lElement (in_lElement),
mProperty_lElementLegacy (in_lElementLegacy),
mProperty_lAttribute (in_lAttribute),
mProperty_lAttributeLegacy (in_lAttributeLegacy),
mProperty_desc (in_desc) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_arxmlMetaClass::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_arxmlMetaClass ;
}

void cPtr_arxmlMetaClass::description (C_String & ioString,
                                       const int32_t inIndentation) const {
  ioString << "[@arxmlMetaClass:" ;
  mProperty_name.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_isAbstract.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_lElement.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_lElementLegacy.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_lAttribute.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_lAttributeLegacy.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_desc.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_arxmlMetaClass::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_arxmlMetaClass (mProperty_name, mProperty_isAbstract, mProperty_lElement, mProperty_lElementLegacy, mProperty_lAttribute, mProperty_lAttributeLegacy, mProperty_desc COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//@arxmlMetaClass type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_arxmlMetaClass ("arxmlMetaClass",
                                       NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_arxmlMetaClass::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_arxmlMetaClass ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_arxmlMetaClass::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_arxmlMetaClass (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaClass GALGAS_arxmlMetaClass::extractObject (const GALGAS_object & inObject,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) {
  GALGAS_arxmlMetaClass result ;
  const GALGAS_arxmlMetaClass * p = (const GALGAS_arxmlMetaClass *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_arxmlMetaClass *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("arxmlMetaClass", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Extension setter '@arxmlMetaClass legacyAddParameters'
//
//----------------------------------------------------------------------------------------------------------------------

static TC_UniqueArray <extensionSetterSignature_arxmlMetaClass_legacyAddParameters> gExtensionModifierTable_arxmlMetaClass_legacyAddParameters ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionSetter_legacyAddParameters (const int32_t inClassIndex,
                                               extensionSetterSignature_arxmlMetaClass_legacyAddParameters inModifier) {
  gExtensionModifierTable_arxmlMetaClass_legacyAddParameters.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionSetter_legacyAddParameters (cPtr_arxmlMetaClass * inObject,
                                              GALGAS_arxmlMetaClassMap & io_classMap,
                                              GALGAS_lstringlist in_successors,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_arxmlMetaClass) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_arxmlMetaClass_legacyAddParameters f = NULL ;
    if (classIndex < gExtensionModifierTable_arxmlMetaClass_legacyAddParameters.count ()) {
      f = gExtensionModifierTable_arxmlMetaClass_legacyAddParameters (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_arxmlMetaClass_legacyAddParameters.count ()) {
           f = gExtensionModifierTable_arxmlMetaClass_legacyAddParameters (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_arxmlMetaClass_legacyAddParameters.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, io_classMap, in_successors, inCompiler COMMA_THERE) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void extensionSetter_arxmlMetaClass_legacyAddParameters (cPtr_arxmlMetaClass * inObject,
                                                                GALGAS_arxmlMetaClassMap & ioArgument_classMap,
                                                                GALGAS_lstringlist inArgument_successors,
                                                                C_Compiler * inCompiler
                                                                COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_arxmlMetaClass * object = inObject ;
  macroValidSharedObject (object, cPtr_arxmlMetaClass) ;
  cEnumerator_lstringlist enumerator_2557 (inArgument_successors, kENUMERATION_UP) ;
  while (enumerator_2557.hasCurrentObject ()) {
    {
    extensionSetter_updateLegacyParameters (ioArgument_classMap, enumerator_2557.current_mValue (HERE), object->mProperty_lElement, object->mProperty_lAttribute, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 95)) ;
    }
    enumerator_2557.gotoNextObject () ;
  }
}
//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionSetter_arxmlMetaClass_legacyAddParameters (void) {
  enterExtensionSetter_legacyAddParameters (kTypeDescriptor_GALGAS_arxmlMetaClass.mSlotID,
                                            extensionSetter_arxmlMetaClass_legacyAddParameters) ;
}

//----------------------------------------------------------------------------------------------------------------------

static void freeExtensionModifier_arxmlMetaClass_legacyAddParameters (void) {
  gExtensionModifierTable_arxmlMetaClass_legacyAddParameters.free () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gSetter_arxmlMetaClass_legacyAddParameters (defineExtensionSetter_arxmlMetaClass_legacyAddParameters,
                                                               freeExtensionModifier_arxmlMetaClass_legacyAddParameters) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension setter '@arxmlMetaClass legacyUpdate'
//
//----------------------------------------------------------------------------------------------------------------------

static TC_UniqueArray <extensionSetterSignature_arxmlMetaClass_legacyUpdate> gExtensionModifierTable_arxmlMetaClass_legacyUpdate ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionSetter_legacyUpdate (const int32_t inClassIndex,
                                        extensionSetterSignature_arxmlMetaClass_legacyUpdate inModifier) {
  gExtensionModifierTable_arxmlMetaClass_legacyUpdate.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionSetter_legacyUpdate (cPtr_arxmlMetaClass * inObject,
                                       GALGAS_arxmlMetaElementList in_iElement,
                                       GALGAS_arxmlMetaAttributeList in_iAttribute,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_arxmlMetaClass) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_arxmlMetaClass_legacyUpdate f = NULL ;
    if (classIndex < gExtensionModifierTable_arxmlMetaClass_legacyUpdate.count ()) {
      f = gExtensionModifierTable_arxmlMetaClass_legacyUpdate (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_arxmlMetaClass_legacyUpdate.count ()) {
           f = gExtensionModifierTable_arxmlMetaClass_legacyUpdate (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_arxmlMetaClass_legacyUpdate.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, in_iElement, in_iAttribute, inCompiler COMMA_THERE) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void extensionSetter_arxmlMetaClass_legacyUpdate (cPtr_arxmlMetaClass * inObject,
                                                         GALGAS_arxmlMetaElementList inArgument_iElement,
                                                         GALGAS_arxmlMetaAttributeList inArgument_iAttribute,
                                                         C_Compiler * inCompiler
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_arxmlMetaClass * object = inObject ;
  macroValidSharedObject (object, cPtr_arxmlMetaClass) ;
  object->mProperty_lElementLegacy.plusAssign_operation(inArgument_iElement, inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 105)) ;
  object->mProperty_lAttributeLegacy.plusAssign_operation(inArgument_iAttribute, inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 106)) ;
}
//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionSetter_arxmlMetaClass_legacyUpdate (void) {
  enterExtensionSetter_legacyUpdate (kTypeDescriptor_GALGAS_arxmlMetaClass.mSlotID,
                                     extensionSetter_arxmlMetaClass_legacyUpdate) ;
}

//----------------------------------------------------------------------------------------------------------------------

static void freeExtensionModifier_arxmlMetaClass_legacyUpdate (void) {
  gExtensionModifierTable_arxmlMetaClass_legacyUpdate.free () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gSetter_arxmlMetaClass_legacyUpdate (defineExtensionSetter_arxmlMetaClass_legacyUpdate,
                                                        freeExtensionModifier_arxmlMetaClass_legacyUpdate) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@arxmlMetaClass display'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_arxmlMetaClass::method_display (GALGAS_arxmlMetaClassMap /* inArgument_classMap */,
                                          GALGAS_string & ioArgument_ioString,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string var_svgString_2960 = GALGAS_string::makeEmptyString () ;
  GALGAS_string var_classNameRepr_2993 = this->mProperty_name.readProperty_string () ;
  var_svgString_2960.plusAssign_operation(GALGAS_string ("############################################################\n"), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 116)) ;
  var_svgString_2960.plusAssign_operation(GALGAS_string ("# ").add_operation (this->mProperty_name.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 117)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 117)), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 117)) ;
  var_svgString_2960.plusAssign_operation(GALGAS_string ("# <").add_operation (this->mProperty_desc.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 118)).add_operation (GALGAS_string (">\n"), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 118)), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 118)) ;
  var_svgString_2960.plusAssign_operation(GALGAS_string ("#\n"), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 119)) ;
  var_svgString_2960.plusAssign_operation(GALGAS_string ("list @").add_operation (var_classNameRepr_2993, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 122)).add_operation (GALGAS_string ("list\n"
    "{\n"), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 122)), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 122)) ;
  var_svgString_2960.plusAssign_operation(GALGAS_string ("  @").add_operation (var_classNameRepr_2993, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 123)).add_operation (GALGAS_string (" elem\n"), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 123)), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 123)) ;
  var_svgString_2960.plusAssign_operation(GALGAS_string ("}\n"), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 124)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = this->mProperty_isAbstract.boolEnum () ;
    if (kBoolTrue == test_0) {
      var_svgString_2960.plusAssign_operation(GALGAS_string ("abstract "), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 128)) ;
    }
  }
  var_svgString_2960.plusAssign_operation(GALGAS_string ("class @").add_operation (var_classNameRepr_2993, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 132)).add_operation (GALGAS_string ("\n"
    "{\n"), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 132)), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 132)) ;
  cEnumerator_arxmlMetaElementList enumerator_3693 (this->mProperty_lElementLegacy, kENUMERATION_UP) ;
  while (enumerator_3693.hasCurrentObject ()) {
    GALGAS_string var_elemTypeRepr_3744 = enumerator_3693.current_lElement (HERE).readProperty_type ().readProperty_string () ;
    GALGAS_string var_elemNameRepr_3798 = enumerator_3693.current_lElement (HERE).readProperty_name ().readProperty_string () ;
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = GALGAS_bool (kIsEqual, enumerator_3693.current_lElement (HERE).readProperty_type ().readProperty_string ().objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
      if (kBoolTrue == test_1) {
        TC_Array <C_FixItDescription> fixItArray2 ;
        inCompiler->emitSemanticWarning (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 142)), GALGAS_string ("Missing element's type : ").add_operation (var_elemNameRepr_3798, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 142)), fixItArray2  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 142)) ;
      }
    }
    var_svgString_2960.plusAssign_operation(GALGAS_string ("  @").add_operation (var_elemTypeRepr_3744, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 168)), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 168)) ;
    enumGalgasBool test_3 = kBoolTrue ;
    if (kBoolTrue == test_3) {
      GALGAS_bool test_4 = GALGAS_bool (kIsNotEqual, enumerator_3693.current_lElement (HERE).readProperty_minOccurs ().readProperty_string ().objectCompare (enumerator_3693.current_lElement (HERE).readProperty_maxOccurs ().readProperty_string ())) ;
      if (kBoolTrue != test_4.boolEnum ()) {
        test_4 = GALGAS_bool (kIsNotEqual, enumerator_3693.current_lElement (HERE).readProperty_minOccurs ().readProperty_string ().objectCompare (GALGAS_string ("1"))) ;
      }
      test_3 = test_4.boolEnum () ;
      if (kBoolTrue == test_3) {
        var_svgString_2960.plusAssign_operation(GALGAS_string ("list"), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 175)) ;
      }
    }
    var_svgString_2960.plusAssign_operation(GALGAS_string (" elem").add_operation (var_elemNameRepr_3798, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 179)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 179)), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 179)) ;
    enumerator_3693.gotoNextObject () ;
  }
  cEnumerator_arxmlMetaAttributeList enumerator_5325 (this->mProperty_lAttributeLegacy, kENUMERATION_UP) ;
  while (enumerator_5325.hasCurrentObject ()) {
    GALGAS_string var_attrTypeRepr_5378 = enumerator_5325.current_lAttribute (HERE).readProperty_type ().readProperty_string () ;
    GALGAS_string var_attrNameRepr_5434 = enumerator_5325.current_lAttribute (HERE).readProperty_name ().readProperty_string () ;
    enumGalgasBool test_5 = kBoolTrue ;
    if (kBoolTrue == test_5) {
      test_5 = GALGAS_bool (kIsNotEqual, enumerator_5325.current_lAttribute (HERE).readProperty_type ().readProperty_string ().objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
      if (kBoolTrue == test_5) {
      }
    }
    var_svgString_2960.plusAssign_operation(GALGAS_string ("  @").add_operation (var_attrTypeRepr_5378, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 218)).add_operation (GALGAS_string (" "), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 218)).add_operation (var_attrNameRepr_5434, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 218)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 218)), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 218)) ;
    enumGalgasBool test_6 = kBoolTrue ;
    if (kBoolTrue == test_6) {
      GALGAS_bool test_7 = GALGAS_bool (kIsEqual, enumerator_5325.current_lAttribute (HERE).readProperty_use ().readProperty_string ().objectCompare (GALGAS_string::makeEmptyString ())) ;
      if (kBoolTrue != test_7.boolEnum ()) {
        test_7 = GALGAS_bool (kIsEqual, enumerator_5325.current_lAttribute (HERE).readProperty_use ().readProperty_string ().objectCompare (GALGAS_string ("optional"))) ;
      }
      test_6 = test_7.boolEnum () ;
      if (kBoolTrue == test_6) {
        var_svgString_2960.plusAssign_operation(GALGAS_string ("list"), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 225)) ;
      }
    }
    var_svgString_2960.plusAssign_operation(GALGAS_string (" attr").add_operation (var_attrNameRepr_5434, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 229)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 229)), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 229)) ;
    enumerator_5325.gotoNextObject () ;
  }
  var_svgString_2960.plusAssign_operation(GALGAS_string ("}\n"
    "\n"), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 232)) ;
  ioArgument_ioString = ioArgument_ioString.add_operation (var_svgString_2960, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 233)) ;
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_display (cPtr_arxmlMetaClass * inObject,
                                  GALGAS_arxmlMetaClassMap in_classMap,
                                  GALGAS_string & io_ioString,
                                  C_Compiler * inCompiler
                                  COMMA_LOCATION_ARGS) {
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_arxmlMetaClass) ;
    inObject->method_display  (in_classMap, io_ioString, inCompiler COMMA_THERE) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Extension setter '@arxmlMetaClass addElement'
//
//----------------------------------------------------------------------------------------------------------------------

static TC_UniqueArray <extensionSetterSignature_arxmlMetaClass_addElement> gExtensionModifierTable_arxmlMetaClass_addElement ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionSetter_addElement (const int32_t inClassIndex,
                                      extensionSetterSignature_arxmlMetaClass_addElement inModifier) {
  gExtensionModifierTable_arxmlMetaClass_addElement.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionSetter_addElement (cPtr_arxmlMetaClass * inObject,
                                     GALGAS_arxmlMetaElement in_mElement,
                                     C_Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_arxmlMetaClass) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_arxmlMetaClass_addElement f = NULL ;
    if (classIndex < gExtensionModifierTable_arxmlMetaClass_addElement.count ()) {
      f = gExtensionModifierTable_arxmlMetaClass_addElement (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_arxmlMetaClass_addElement.count ()) {
           f = gExtensionModifierTable_arxmlMetaClass_addElement (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_arxmlMetaClass_addElement.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, in_mElement, inCompiler COMMA_THERE) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void extensionSetter_arxmlMetaClass_addElement (cPtr_arxmlMetaClass * inObject,
                                                       GALGAS_arxmlMetaElement inArgument_mElement,
                                                       C_Compiler * /* inCompiler */
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_arxmlMetaClass * object = inObject ;
  macroValidSharedObject (object, cPtr_arxmlMetaClass) ;
  GALGAS_bool var_exists_7181 = GALGAS_bool (false) ;
  cEnumerator_arxmlMetaElementList enumerator_7223 (object->mProperty_lElement, kENUMERATION_UP) ;
  while (enumerator_7223.hasCurrentObject ()) {
    enumGalgasBool test_0 = kBoolTrue ;
    if (kBoolTrue == test_0) {
      GALGAS_bool test_1 = GALGAS_bool (kIsEqual, enumerator_7223.current_lElement (HERE).readProperty_name ().readProperty_string ().objectCompare (inArgument_mElement.readProperty_name ().readProperty_string ())) ;
      if (kBoolTrue == test_1.boolEnum ()) {
        test_1 = GALGAS_bool (kIsEqual, enumerator_7223.current_lElement (HERE).readProperty_type ().readProperty_string ().objectCompare (inArgument_mElement.readProperty_type ().readProperty_string ())) ;
      }
      test_0 = test_1.boolEnum () ;
      if (kBoolTrue == test_0) {
        var_exists_7181 = GALGAS_bool (true) ;
      }
    }
    enumerator_7223.gotoNextObject () ;
  }
  enumGalgasBool test_2 = kBoolTrue ;
  if (kBoolTrue == test_2) {
    test_2 = var_exists_7181.operator_not (SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 245)).boolEnum () ;
    if (kBoolTrue == test_2) {
      object->mProperty_lElement.addAssign_operation (inArgument_mElement  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 246)) ;
    }
  }
}
//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionSetter_arxmlMetaClass_addElement (void) {
  enterExtensionSetter_addElement (kTypeDescriptor_GALGAS_arxmlMetaClass.mSlotID,
                                   extensionSetter_arxmlMetaClass_addElement) ;
}

//----------------------------------------------------------------------------------------------------------------------

static void freeExtensionModifier_arxmlMetaClass_addElement (void) {
  gExtensionModifierTable_arxmlMetaClass_addElement.free () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gSetter_arxmlMetaClass_addElement (defineExtensionSetter_arxmlMetaClass_addElement,
                                                      freeExtensionModifier_arxmlMetaClass_addElement) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension setter '@arxmlMetaClass addAttribute'
//
//----------------------------------------------------------------------------------------------------------------------

static TC_UniqueArray <extensionSetterSignature_arxmlMetaClass_addAttribute> gExtensionModifierTable_arxmlMetaClass_addAttribute ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionSetter_addAttribute (const int32_t inClassIndex,
                                        extensionSetterSignature_arxmlMetaClass_addAttribute inModifier) {
  gExtensionModifierTable_arxmlMetaClass_addAttribute.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionSetter_addAttribute (cPtr_arxmlMetaClass * inObject,
                                       GALGAS_arxmlMetaAttribute in_mAttribute,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_arxmlMetaClass) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_arxmlMetaClass_addAttribute f = NULL ;
    if (classIndex < gExtensionModifierTable_arxmlMetaClass_addAttribute.count ()) {
      f = gExtensionModifierTable_arxmlMetaClass_addAttribute (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_arxmlMetaClass_addAttribute.count ()) {
           f = gExtensionModifierTable_arxmlMetaClass_addAttribute (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_arxmlMetaClass_addAttribute.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, in_mAttribute, inCompiler COMMA_THERE) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void extensionSetter_arxmlMetaClass_addAttribute (cPtr_arxmlMetaClass * inObject,
                                                         GALGAS_arxmlMetaAttribute inArgument_mAttribute,
                                                         C_Compiler * /* inCompiler */
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_arxmlMetaClass * object = inObject ;
  macroValidSharedObject (object, cPtr_arxmlMetaClass) ;
  GALGAS_bool var_exists_7532 = GALGAS_bool (false) ;
  cEnumerator_arxmlMetaAttributeList enumerator_7578 (object->mProperty_lAttribute, kENUMERATION_UP) ;
  while (enumerator_7578.hasCurrentObject ()) {
    enumGalgasBool test_0 = kBoolTrue ;
    if (kBoolTrue == test_0) {
      GALGAS_bool test_1 = GALGAS_bool (kIsEqual, enumerator_7578.current_lAttribute (HERE).readProperty_name ().readProperty_string ().objectCompare (inArgument_mAttribute.readProperty_name ().readProperty_string ())) ;
      if (kBoolTrue == test_1.boolEnum ()) {
        test_1 = GALGAS_bool (kIsEqual, enumerator_7578.current_lAttribute (HERE).readProperty_type ().readProperty_string ().objectCompare (inArgument_mAttribute.readProperty_type ().readProperty_string ())) ;
      }
      test_0 = test_1.boolEnum () ;
      if (kBoolTrue == test_0) {
        var_exists_7532 = GALGAS_bool (true) ;
      }
    }
    enumerator_7578.gotoNextObject () ;
  }
  enumGalgasBool test_2 = kBoolTrue ;
  if (kBoolTrue == test_2) {
    test_2 = var_exists_7532.operator_not (SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 259)).boolEnum () ;
    if (kBoolTrue == test_2) {
      object->mProperty_lAttribute.addAssign_operation (inArgument_mAttribute  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 260)) ;
    }
  }
}
//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionSetter_arxmlMetaClass_addAttribute (void) {
  enterExtensionSetter_addAttribute (kTypeDescriptor_GALGAS_arxmlMetaClass.mSlotID,
                                     extensionSetter_arxmlMetaClass_addAttribute) ;
}

//----------------------------------------------------------------------------------------------------------------------

static void freeExtensionModifier_arxmlMetaClass_addAttribute (void) {
  gExtensionModifierTable_arxmlMetaClass_addAttribute.free () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gSetter_arxmlMetaClass_addAttribute (defineExtensionSetter_arxmlMetaClass_addAttribute,
                                                        freeExtensionModifier_arxmlMetaClass_addAttribute) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension setter '@arxmlMetaClass setDescription'
//
//----------------------------------------------------------------------------------------------------------------------

static TC_UniqueArray <extensionSetterSignature_arxmlMetaClass_setDescription> gExtensionModifierTable_arxmlMetaClass_setDescription ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionSetter_setDescription (const int32_t inClassIndex,
                                          extensionSetterSignature_arxmlMetaClass_setDescription inModifier) {
  gExtensionModifierTable_arxmlMetaClass_setDescription.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionSetter_setDescription (cPtr_arxmlMetaClass * inObject,
                                         GALGAS_lstring in_iDesc,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_arxmlMetaClass) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_arxmlMetaClass_setDescription f = NULL ;
    if (classIndex < gExtensionModifierTable_arxmlMetaClass_setDescription.count ()) {
      f = gExtensionModifierTable_arxmlMetaClass_setDescription (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_arxmlMetaClass_setDescription.count ()) {
           f = gExtensionModifierTable_arxmlMetaClass_setDescription (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_arxmlMetaClass_setDescription.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, in_iDesc, inCompiler COMMA_THERE) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void extensionSetter_arxmlMetaClass_setDescription (cPtr_arxmlMetaClass * inObject,
                                                           GALGAS_lstring inArgument_iDesc,
                                                           C_Compiler * /* inCompiler */
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_arxmlMetaClass * object = inObject ;
  macroValidSharedObject (object, cPtr_arxmlMetaClass) ;
  object->mProperty_desc = inArgument_iDesc ;
}
//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionSetter_arxmlMetaClass_setDescription (void) {
  enterExtensionSetter_setDescription (kTypeDescriptor_GALGAS_arxmlMetaClass.mSlotID,
                                       extensionSetter_arxmlMetaClass_setDescription) ;
}

//----------------------------------------------------------------------------------------------------------------------

static void freeExtensionModifier_arxmlMetaClass_setDescription (void) {
  gExtensionModifierTable_arxmlMetaClass_setDescription.free () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gSetter_arxmlMetaClass_setDescription (defineExtensionSetter_arxmlMetaClass_setDescription,
                                                          freeExtensionModifier_arxmlMetaClass_setDescription) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@arxmlMetaClass hasElement'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_arxmlMetaClass::getter_hasElement (GALGAS_string inArgument_eleName,
                                                    C_Compiler */* inCompiler */
                                                    COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_oFound ; // Returned variable
  GALGAS_bool var_found_7976 = GALGAS_bool (false) ;
  cEnumerator_arxmlMetaElementList enumerator_8025 (this->mProperty_lElementLegacy, kENUMERATION_UP) ;
  bool bool_0 = var_found_7976.operator_not (SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 275)).isValidAndTrue () ;
  if (enumerator_8025.hasCurrentObject () && bool_0) {
    while (enumerator_8025.hasCurrentObject () && bool_0) {
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = GALGAS_bool (kIsEqual, inArgument_eleName.objectCompare (enumerator_8025.current_lElement (HERE).readProperty_name ().readProperty_string ())).boolEnum () ;
        if (kBoolTrue == test_1) {
          var_found_7976 = GALGAS_bool (true) ;
        }
      }
      enumerator_8025.gotoNextObject () ;
      if (enumerator_8025.hasCurrentObject ()) {
        bool_0 = var_found_7976.operator_not (SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 275)).isValidAndTrue () ;
      }
    }
  }
  result_oFound = var_found_7976 ;
//---
  return result_oFound ;
}



//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool callExtensionGetter_hasElement (const cPtr_arxmlMetaClass * inObject,
                                            GALGAS_string in_eleName,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
  GALGAS_bool result ;
  if (nullptr != inObject) {
    result = inObject->getter_hasElement (in_eleName, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@arxmlMetaClass hasAttribute'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_arxmlMetaClass::getter_hasAttribute (GALGAS_string inArgument_attrName,
                                                      C_Compiler */* inCompiler */
                                                      COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_oFound ; // Returned variable
  GALGAS_bool var_found_8260 = GALGAS_bool (false) ;
  cEnumerator_arxmlMetaAttributeList enumerator_8313 (this->mProperty_lAttributeLegacy, kENUMERATION_UP) ;
  bool bool_0 = var_found_8260.operator_not (SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 290)).isValidAndTrue () ;
  if (enumerator_8313.hasCurrentObject () && bool_0) {
    while (enumerator_8313.hasCurrentObject () && bool_0) {
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = GALGAS_bool (kIsEqual, inArgument_attrName.objectCompare (enumerator_8313.current_lAttribute (HERE).readProperty_name ().readProperty_string ())).boolEnum () ;
        if (kBoolTrue == test_1) {
          var_found_8260 = GALGAS_bool (true) ;
        }
      }
      enumerator_8313.gotoNextObject () ;
      if (enumerator_8313.hasCurrentObject ()) {
        bool_0 = var_found_8260.operator_not (SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 290)).isValidAndTrue () ;
      }
    }
  }
  result_oFound = var_found_8260 ;
//---
  return result_oFound ;
}



//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool callExtensionGetter_hasAttribute (const cPtr_arxmlMetaClass * inObject,
                                              GALGAS_string in_attrName,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  GALGAS_bool result ;
  if (nullptr != inObject) {
    result = inObject->getter_hasAttribute (in_attrName, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_arxmlMetaElement::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_arxmlMetaElement * p = (const cPtr_arxmlMetaElement *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_arxmlMetaElement) ;
  if (kOperandEqual == result) {
    result = mProperty_name.objectCompare (p->mProperty_name) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_type.objectCompare (p->mProperty_type) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_minOccurs.objectCompare (p->mProperty_minOccurs) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_maxOccurs.objectCompare (p->mProperty_maxOccurs) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_prefix.objectCompare (p->mProperty_prefix) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_arxmlMetaElement::objectCompare (const GALGAS_arxmlMetaElement & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaElement::GALGAS_arxmlMetaElement (void) :
AC_GALGAS_value_class () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaElement GALGAS_arxmlMetaElement::constructor_default (LOCATION_ARGS) {
  return GALGAS_arxmlMetaElement::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                                   GALGAS_lstring::constructor_default (HERE),
                                                   GALGAS_lstring::constructor_default (HERE),
                                                   GALGAS_lstring::constructor_default (HERE),
                                                   GALGAS_lstring::constructor_default (HERE)
                                                   COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaElement::GALGAS_arxmlMetaElement (const cPtr_arxmlMetaElement * inSourcePtr) :
AC_GALGAS_value_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_arxmlMetaElement) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaElement GALGAS_arxmlMetaElement::constructor_new (const GALGAS_lstring & inAttribute_name,
                                                                  const GALGAS_lstring & inAttribute_type,
                                                                  const GALGAS_lstring & inAttribute_minOccurs,
                                                                  const GALGAS_lstring & inAttribute_maxOccurs,
                                                                  const GALGAS_lstring & inAttribute_prefix
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_arxmlMetaElement result ;
  if (inAttribute_name.isValid () && inAttribute_type.isValid () && inAttribute_minOccurs.isValid () && inAttribute_maxOccurs.isValid () && inAttribute_prefix.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_arxmlMetaElement (inAttribute_name, inAttribute_type, inAttribute_minOccurs, inAttribute_maxOccurs, inAttribute_prefix COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_arxmlMetaElement::readProperty_name (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_lstring () ;
  }else{
    const cPtr_arxmlMetaElement * p = (const cPtr_arxmlMetaElement *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlMetaElement) ;
    return p->mProperty_name ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_arxmlMetaElement::getter_name (UNUSED_LOCATION_ARGS) const {
  return mProperty_name ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_arxmlMetaElement::readProperty_type (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_lstring () ;
  }else{
    const cPtr_arxmlMetaElement * p = (const cPtr_arxmlMetaElement *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlMetaElement) ;
    return p->mProperty_type ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_arxmlMetaElement::getter_type (UNUSED_LOCATION_ARGS) const {
  return mProperty_type ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_arxmlMetaElement::readProperty_minOccurs (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_lstring () ;
  }else{
    const cPtr_arxmlMetaElement * p = (const cPtr_arxmlMetaElement *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlMetaElement) ;
    return p->mProperty_minOccurs ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_arxmlMetaElement::getter_minOccurs (UNUSED_LOCATION_ARGS) const {
  return mProperty_minOccurs ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_arxmlMetaElement::readProperty_maxOccurs (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_lstring () ;
  }else{
    const cPtr_arxmlMetaElement * p = (const cPtr_arxmlMetaElement *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlMetaElement) ;
    return p->mProperty_maxOccurs ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_arxmlMetaElement::getter_maxOccurs (UNUSED_LOCATION_ARGS) const {
  return mProperty_maxOccurs ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_arxmlMetaElement::readProperty_prefix (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_lstring () ;
  }else{
    const cPtr_arxmlMetaElement * p = (const cPtr_arxmlMetaElement *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlMetaElement) ;
    return p->mProperty_prefix ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_arxmlMetaElement::getter_prefix (UNUSED_LOCATION_ARGS) const {
  return mProperty_prefix ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaElement::setter_setName (GALGAS_lstring inValue
                                              COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_arxmlMetaElement * p = (cPtr_arxmlMetaElement *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlMetaElement) ;
    p->mProperty_name = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_arxmlMetaElement::setter_setName (GALGAS_lstring inValue
                                            COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_name = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaElement::setter_setType (GALGAS_lstring inValue
                                              COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_arxmlMetaElement * p = (cPtr_arxmlMetaElement *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlMetaElement) ;
    p->mProperty_type = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_arxmlMetaElement::setter_setType (GALGAS_lstring inValue
                                            COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_type = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaElement::setter_setMinOccurs (GALGAS_lstring inValue
                                                   COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_arxmlMetaElement * p = (cPtr_arxmlMetaElement *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlMetaElement) ;
    p->mProperty_minOccurs = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_arxmlMetaElement::setter_setMinOccurs (GALGAS_lstring inValue
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_minOccurs = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaElement::setter_setMaxOccurs (GALGAS_lstring inValue
                                                   COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_arxmlMetaElement * p = (cPtr_arxmlMetaElement *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlMetaElement) ;
    p->mProperty_maxOccurs = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_arxmlMetaElement::setter_setMaxOccurs (GALGAS_lstring inValue
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_maxOccurs = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaElement::setter_setPrefix (GALGAS_lstring inValue
                                                COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_arxmlMetaElement * p = (cPtr_arxmlMetaElement *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlMetaElement) ;
    p->mProperty_prefix = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_arxmlMetaElement::setter_setPrefix (GALGAS_lstring inValue
                                              COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_prefix = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @arxmlMetaElement class
//----------------------------------------------------------------------------------------------------------------------

cPtr_arxmlMetaElement::cPtr_arxmlMetaElement (const GALGAS_lstring & in_name,
                                              const GALGAS_lstring & in_type,
                                              const GALGAS_lstring & in_minOccurs,
                                              const GALGAS_lstring & in_maxOccurs,
                                              const GALGAS_lstring & in_prefix
                                              COMMA_LOCATION_ARGS) :
acPtr_class (THERE),
mProperty_name (in_name),
mProperty_type (in_type),
mProperty_minOccurs (in_minOccurs),
mProperty_maxOccurs (in_maxOccurs),
mProperty_prefix (in_prefix) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_arxmlMetaElement::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_arxmlMetaElement ;
}

void cPtr_arxmlMetaElement::description (C_String & ioString,
                                         const int32_t inIndentation) const {
  ioString << "[@arxmlMetaElement:" ;
  mProperty_name.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_type.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_minOccurs.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_maxOccurs.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_prefix.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_arxmlMetaElement::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_arxmlMetaElement (mProperty_name, mProperty_type, mProperty_minOccurs, mProperty_maxOccurs, mProperty_prefix COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//@arxmlMetaElement type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_arxmlMetaElement ("arxmlMetaElement",
                                         NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_arxmlMetaElement::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_arxmlMetaElement ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_arxmlMetaElement::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_arxmlMetaElement (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaElement GALGAS_arxmlMetaElement::extractObject (const GALGAS_object & inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) {
  GALGAS_arxmlMetaElement result ;
  const GALGAS_arxmlMetaElement * p = (const GALGAS_arxmlMetaElement *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_arxmlMetaElement *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("arxmlMetaElement", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_arxmlMetaAttribute::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_arxmlMetaAttribute * p = (const cPtr_arxmlMetaAttribute *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_arxmlMetaAttribute) ;
  if (kOperandEqual == result) {
    result = mProperty_name.objectCompare (p->mProperty_name) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_type.objectCompare (p->mProperty_type) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_prefix.objectCompare (p->mProperty_prefix) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_use.objectCompare (p->mProperty_use) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_arxmlMetaAttribute::objectCompare (const GALGAS_arxmlMetaAttribute & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaAttribute::GALGAS_arxmlMetaAttribute (void) :
AC_GALGAS_value_class () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaAttribute GALGAS_arxmlMetaAttribute::constructor_default (LOCATION_ARGS) {
  return GALGAS_arxmlMetaAttribute::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                                     GALGAS_lstring::constructor_default (HERE),
                                                     GALGAS_lstring::constructor_default (HERE),
                                                     GALGAS_lstring::constructor_default (HERE)
                                                     COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaAttribute::GALGAS_arxmlMetaAttribute (const cPtr_arxmlMetaAttribute * inSourcePtr) :
AC_GALGAS_value_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_arxmlMetaAttribute) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaAttribute GALGAS_arxmlMetaAttribute::constructor_new (const GALGAS_lstring & inAttribute_name,
                                                                      const GALGAS_lstring & inAttribute_type,
                                                                      const GALGAS_lstring & inAttribute_prefix,
                                                                      const GALGAS_lstring & inAttribute_use
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_arxmlMetaAttribute result ;
  if (inAttribute_name.isValid () && inAttribute_type.isValid () && inAttribute_prefix.isValid () && inAttribute_use.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_arxmlMetaAttribute (inAttribute_name, inAttribute_type, inAttribute_prefix, inAttribute_use COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_arxmlMetaAttribute::readProperty_name (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_lstring () ;
  }else{
    const cPtr_arxmlMetaAttribute * p = (const cPtr_arxmlMetaAttribute *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlMetaAttribute) ;
    return p->mProperty_name ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_arxmlMetaAttribute::getter_name (UNUSED_LOCATION_ARGS) const {
  return mProperty_name ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_arxmlMetaAttribute::readProperty_type (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_lstring () ;
  }else{
    const cPtr_arxmlMetaAttribute * p = (const cPtr_arxmlMetaAttribute *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlMetaAttribute) ;
    return p->mProperty_type ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_arxmlMetaAttribute::getter_type (UNUSED_LOCATION_ARGS) const {
  return mProperty_type ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_arxmlMetaAttribute::readProperty_prefix (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_lstring () ;
  }else{
    const cPtr_arxmlMetaAttribute * p = (const cPtr_arxmlMetaAttribute *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlMetaAttribute) ;
    return p->mProperty_prefix ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_arxmlMetaAttribute::getter_prefix (UNUSED_LOCATION_ARGS) const {
  return mProperty_prefix ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_arxmlMetaAttribute::readProperty_use (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_lstring () ;
  }else{
    const cPtr_arxmlMetaAttribute * p = (const cPtr_arxmlMetaAttribute *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlMetaAttribute) ;
    return p->mProperty_use ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_arxmlMetaAttribute::getter_use (UNUSED_LOCATION_ARGS) const {
  return mProperty_use ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaAttribute::setter_setName (GALGAS_lstring inValue
                                                COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_arxmlMetaAttribute * p = (cPtr_arxmlMetaAttribute *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlMetaAttribute) ;
    p->mProperty_name = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_arxmlMetaAttribute::setter_setName (GALGAS_lstring inValue
                                              COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_name = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaAttribute::setter_setType (GALGAS_lstring inValue
                                                COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_arxmlMetaAttribute * p = (cPtr_arxmlMetaAttribute *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlMetaAttribute) ;
    p->mProperty_type = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_arxmlMetaAttribute::setter_setType (GALGAS_lstring inValue
                                              COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_type = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaAttribute::setter_setPrefix (GALGAS_lstring inValue
                                                  COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_arxmlMetaAttribute * p = (cPtr_arxmlMetaAttribute *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlMetaAttribute) ;
    p->mProperty_prefix = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_arxmlMetaAttribute::setter_setPrefix (GALGAS_lstring inValue
                                                COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_prefix = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaAttribute::setter_setUse (GALGAS_lstring inValue
                                               COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_arxmlMetaAttribute * p = (cPtr_arxmlMetaAttribute *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlMetaAttribute) ;
    p->mProperty_use = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_arxmlMetaAttribute::setter_setUse (GALGAS_lstring inValue
                                             COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_use = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @arxmlMetaAttribute class
//----------------------------------------------------------------------------------------------------------------------

cPtr_arxmlMetaAttribute::cPtr_arxmlMetaAttribute (const GALGAS_lstring & in_name,
                                                  const GALGAS_lstring & in_type,
                                                  const GALGAS_lstring & in_prefix,
                                                  const GALGAS_lstring & in_use
                                                  COMMA_LOCATION_ARGS) :
acPtr_class (THERE),
mProperty_name (in_name),
mProperty_type (in_type),
mProperty_prefix (in_prefix),
mProperty_use (in_use) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_arxmlMetaAttribute::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_arxmlMetaAttribute ;
}

void cPtr_arxmlMetaAttribute::description (C_String & ioString,
                                           const int32_t inIndentation) const {
  ioString << "[@arxmlMetaAttribute:" ;
  mProperty_name.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_type.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_prefix.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_use.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_arxmlMetaAttribute::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_arxmlMetaAttribute (mProperty_name, mProperty_type, mProperty_prefix, mProperty_use COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//@arxmlMetaAttribute type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_arxmlMetaAttribute ("arxmlMetaAttribute",
                                           NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_arxmlMetaAttribute::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_arxmlMetaAttribute ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_arxmlMetaAttribute::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_arxmlMetaAttribute (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaAttribute GALGAS_arxmlMetaAttribute::extractObject (const GALGAS_object & inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_arxmlMetaAttribute result ;
  const GALGAS_arxmlMetaAttribute * p = (const GALGAS_arxmlMetaAttribute *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_arxmlMetaAttribute *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("arxmlMetaAttribute", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_arxmlMetaSimpletype::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_arxmlMetaSimpletype * p = (const cPtr_arxmlMetaSimpletype *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_arxmlMetaSimpletype) ;
  if (kOperandEqual == result) {
    result = mProperty_name.objectCompare (p->mProperty_name) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_type.objectCompare (p->mProperty_type) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_base.objectCompare (p->mProperty_base) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_values.objectCompare (p->mProperty_values) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_arxmlMetaSimpletype::objectCompare (const GALGAS_arxmlMetaSimpletype & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaSimpletype::GALGAS_arxmlMetaSimpletype (void) :
AC_GALGAS_value_class () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaSimpletype::GALGAS_arxmlMetaSimpletype (const cPtr_arxmlMetaSimpletype * inSourcePtr) :
AC_GALGAS_value_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_arxmlMetaSimpletype) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaSimpletype GALGAS_arxmlMetaSimpletype::constructor_new (const GALGAS_lstring & inAttribute_name,
                                                                        const GALGAS_restrictionType & inAttribute_type,
                                                                        const GALGAS_restrictionBaseType & inAttribute_base,
                                                                        const GALGAS_lstringlist & inAttribute_values
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_arxmlMetaSimpletype result ;
  if (inAttribute_name.isValid () && inAttribute_type.isValid () && inAttribute_base.isValid () && inAttribute_values.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_arxmlMetaSimpletype (inAttribute_name, inAttribute_type, inAttribute_base, inAttribute_values COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_arxmlMetaSimpletype::readProperty_name (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_lstring () ;
  }else{
    const cPtr_arxmlMetaSimpletype * p = (const cPtr_arxmlMetaSimpletype *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlMetaSimpletype) ;
    return p->mProperty_name ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_arxmlMetaSimpletype::getter_name (UNUSED_LOCATION_ARGS) const {
  return mProperty_name ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_restrictionType GALGAS_arxmlMetaSimpletype::readProperty_type (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_restrictionType () ;
  }else{
    const cPtr_arxmlMetaSimpletype * p = (const cPtr_arxmlMetaSimpletype *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlMetaSimpletype) ;
    return p->mProperty_type ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_restrictionType cPtr_arxmlMetaSimpletype::getter_type (UNUSED_LOCATION_ARGS) const {
  return mProperty_type ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_restrictionBaseType GALGAS_arxmlMetaSimpletype::readProperty_base (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_restrictionBaseType () ;
  }else{
    const cPtr_arxmlMetaSimpletype * p = (const cPtr_arxmlMetaSimpletype *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlMetaSimpletype) ;
    return p->mProperty_base ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_restrictionBaseType cPtr_arxmlMetaSimpletype::getter_base (UNUSED_LOCATION_ARGS) const {
  return mProperty_base ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstringlist GALGAS_arxmlMetaSimpletype::readProperty_values (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_lstringlist () ;
  }else{
    const cPtr_arxmlMetaSimpletype * p = (const cPtr_arxmlMetaSimpletype *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlMetaSimpletype) ;
    return p->mProperty_values ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstringlist cPtr_arxmlMetaSimpletype::getter_values (UNUSED_LOCATION_ARGS) const {
  return mProperty_values ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaSimpletype::setter_setName (GALGAS_lstring inValue
                                                 COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_arxmlMetaSimpletype * p = (cPtr_arxmlMetaSimpletype *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlMetaSimpletype) ;
    p->mProperty_name = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_arxmlMetaSimpletype::setter_setName (GALGAS_lstring inValue
                                               COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_name = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaSimpletype::setter_setType (GALGAS_restrictionType inValue
                                                 COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_arxmlMetaSimpletype * p = (cPtr_arxmlMetaSimpletype *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlMetaSimpletype) ;
    p->mProperty_type = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_arxmlMetaSimpletype::setter_setType (GALGAS_restrictionType inValue
                                               COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_type = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaSimpletype::setter_setBase (GALGAS_restrictionBaseType inValue
                                                 COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_arxmlMetaSimpletype * p = (cPtr_arxmlMetaSimpletype *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlMetaSimpletype) ;
    p->mProperty_base = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_arxmlMetaSimpletype::setter_setBase (GALGAS_restrictionBaseType inValue
                                               COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_base = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaSimpletype::setter_setValues (GALGAS_lstringlist inValue
                                                   COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_arxmlMetaSimpletype * p = (cPtr_arxmlMetaSimpletype *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlMetaSimpletype) ;
    p->mProperty_values = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_arxmlMetaSimpletype::setter_setValues (GALGAS_lstringlist inValue
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_values = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @arxmlMetaSimpletype class
//----------------------------------------------------------------------------------------------------------------------

cPtr_arxmlMetaSimpletype::cPtr_arxmlMetaSimpletype (const GALGAS_lstring & in_name,
                                                    const GALGAS_restrictionType & in_type,
                                                    const GALGAS_restrictionBaseType & in_base,
                                                    const GALGAS_lstringlist & in_values
                                                    COMMA_LOCATION_ARGS) :
acPtr_class (THERE),
mProperty_name (in_name),
mProperty_type (in_type),
mProperty_base (in_base),
mProperty_values (in_values) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_arxmlMetaSimpletype::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_arxmlMetaSimpletype ;
}

void cPtr_arxmlMetaSimpletype::description (C_String & ioString,
                                            const int32_t inIndentation) const {
  ioString << "[@arxmlMetaSimpletype:" ;
  mProperty_name.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_type.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_base.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_values.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_arxmlMetaSimpletype::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_arxmlMetaSimpletype (mProperty_name, mProperty_type, mProperty_base, mProperty_values COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//@arxmlMetaSimpletype type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_arxmlMetaSimpletype ("arxmlMetaSimpletype",
                                            NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_arxmlMetaSimpletype::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_arxmlMetaSimpletype ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_arxmlMetaSimpletype::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_arxmlMetaSimpletype (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaSimpletype GALGAS_arxmlMetaSimpletype::extractObject (const GALGAS_object & inObject,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_arxmlMetaSimpletype result ;
  const GALGAS_arxmlMetaSimpletype * p = (const GALGAS_arxmlMetaSimpletype *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_arxmlMetaSimpletype *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("arxmlMetaSimpletype", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Extension method '@arxmlMetaSimpletype display'
//
//----------------------------------------------------------------------------------------------------------------------

void cPtr_arxmlMetaSimpletype::method_display (GALGAS_arxmlMetaClassMap /* inArgument_classMap */,
                                               GALGAS_string & ioArgument_ioString,
                                               C_Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string var_svgString_9986 = GALGAS_string::makeEmptyString () ;
  GALGAS_string var_typeNameRepr_10018 = this->mProperty_name.readProperty_string () ;
  var_svgString_9986.plusAssign_operation(GALGAS_string ("############################################################\n"), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 373)) ;
  var_svgString_9986.plusAssign_operation(GALGAS_string ("# ").add_operation (this->mProperty_name.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 374)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 374)), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 374)) ;
  switch (this->mProperty_type.enumValue ()) {
  case GALGAS_restrictionType::kNotBuilt:
    break ;
  case GALGAS_restrictionType::kEnum_restrictionSimple:
    {
    }
    break ;
  case GALGAS_restrictionType::kEnum_restrictionEnum:
    {
      var_svgString_9986.plusAssign_operation(GALGAS_string ("list @").add_operation (var_typeNameRepr_10018, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 381)).add_operation (GALGAS_string ("list\n"
        "{\n"), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 381)), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 381)) ;
      var_svgString_9986.plusAssign_operation(GALGAS_string ("  @").add_operation (var_typeNameRepr_10018, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 382)).add_operation (GALGAS_string (" elem\n"), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 382)), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 382)) ;
      var_svgString_9986.plusAssign_operation(GALGAS_string ("}\n"), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 383)) ;
      var_svgString_9986.plusAssign_operation(GALGAS_string ("enum @").add_operation (var_typeNameRepr_10018, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 385)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 385)), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 385)) ;
      var_svgString_9986.plusAssign_operation(GALGAS_string ("{\n"), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 386)) ;
      cEnumerator_lstringlist enumerator_10671 (this->mProperty_values, kENUMERATION_UP) ;
      while (enumerator_10671.hasCurrentObject ()) {
        GALGAS_string var_valueRepr_10715 = enumerator_10671.current_mValue (HERE).readProperty_string () ;
        var_svgString_9986.plusAssign_operation(GALGAS_string ("  case case").add_operation (var_valueRepr_10715, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 390)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 390)), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 390)) ;
        enumerator_10671.gotoNextObject () ;
      }
      var_svgString_9986.plusAssign_operation(GALGAS_string ("}\n"), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 392)) ;
    }
    break ;
  case GALGAS_restrictionType::kEnum_restrictionOther:
    {
      TC_Array <C_FixItDescription> fixItArray0 ;
      inCompiler->emitSemanticError (this->mProperty_name.readProperty_location (), GALGAS_string ("TODO : Fall into restrictionOther statement"), fixItArray0  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 394)) ;
    }
    break ;
  case GALGAS_restrictionType::kEnum_restrictionUnused:
    {
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (this->mProperty_name.readProperty_location (), GALGAS_string ("TODO : Fall into restrictionUnused statement."), fixItArray1  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 396)) ;
    }
    break ;
  }
  ioArgument_ioString = ioArgument_ioString.add_operation (var_svgString_9986, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 399)) ;
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionMethod_display (cPtr_arxmlMetaSimpletype * inObject,
                                  GALGAS_arxmlMetaClassMap in_classMap,
                                  GALGAS_string & io_ioString,
                                  C_Compiler * inCompiler
                                  COMMA_LOCATION_ARGS) {
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_arxmlMetaSimpletype) ;
    inObject->method_display  (in_classMap, io_ioString, inCompiler COMMA_THERE) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------
//
//Extension setter '@arxmlMetaSimpletype addValue'
//
//----------------------------------------------------------------------------------------------------------------------

static TC_UniqueArray <extensionSetterSignature_arxmlMetaSimpletype_addValue> gExtensionModifierTable_arxmlMetaSimpletype_addValue ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionSetter_addValue (const int32_t inClassIndex,
                                    extensionSetterSignature_arxmlMetaSimpletype_addValue inModifier) {
  gExtensionModifierTable_arxmlMetaSimpletype_addValue.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionSetter_addValue (cPtr_arxmlMetaSimpletype * inObject,
                                   GALGAS_lstring in_value,
                                   C_Compiler * inCompiler
                                   COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_arxmlMetaSimpletype) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_arxmlMetaSimpletype_addValue f = NULL ;
    if (classIndex < gExtensionModifierTable_arxmlMetaSimpletype_addValue.count ()) {
      f = gExtensionModifierTable_arxmlMetaSimpletype_addValue (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_arxmlMetaSimpletype_addValue.count ()) {
           f = gExtensionModifierTable_arxmlMetaSimpletype_addValue (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_arxmlMetaSimpletype_addValue.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, in_value, inCompiler COMMA_THERE) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void extensionSetter_arxmlMetaSimpletype_addValue (cPtr_arxmlMetaSimpletype * inObject,
                                                          GALGAS_lstring inArgument_value,
                                                          C_Compiler * /* inCompiler */
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_arxmlMetaSimpletype * object = inObject ;
  macroValidSharedObject (object, cPtr_arxmlMetaSimpletype) ;
  object->mProperty_values.addAssign_operation (inArgument_value  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 414)) ;
}
//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionSetter_arxmlMetaSimpletype_addValue (void) {
  enterExtensionSetter_addValue (kTypeDescriptor_GALGAS_arxmlMetaSimpletype.mSlotID,
                                 extensionSetter_arxmlMetaSimpletype_addValue) ;
}

//----------------------------------------------------------------------------------------------------------------------

static void freeExtensionModifier_arxmlMetaSimpletype_addValue (void) {
  gExtensionModifierTable_arxmlMetaSimpletype_addValue.free () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gSetter_arxmlMetaSimpletype_addValue (defineExtensionSetter_arxmlMetaSimpletype_addValue,
                                                         freeExtensionModifier_arxmlMetaSimpletype_addValue) ;



//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_arxmlmetaparser_5F_start_5F_symbol_i0_ (GALGAS_arxmlMetaClassMap & outArgument_iClassMap,
                                                                                                               GALGAS_bool inArgument_create_5F_class_5F_file,
                                                                                                               C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  outArgument_iClassMap.drop () ; // Release 'out' argument
  GALGAS_arxmlMetaClassMap var_classMap_964 = GALGAS_arxmlMetaClassMap::constructor_emptyMap (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 35)) ;
  GALGAS_arxmlMetaClassGraph var_classGraph_1003 = GALGAS_arxmlMetaClassGraph::constructor_emptyGraph (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 36)) ;
  nt_xml_5F_header_ (inCompiler) ;
  nt_xsd_5F_schema_ (var_classMap_964, var_classGraph_1003, inCompiler) ;
  {
  routine_fillLegacy (var_classMap_964, var_classGraph_1003, inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 43)) ;
  }
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = inArgument_create_5F_class_5F_file.boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_string var_classString_1305 = GALGAS_string::makeEmptyString () ;
      extensionMethod_display (var_classMap_964, var_classString_1305, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 49)) ;
      var_classString_1305.method_writeToFile (GALGAS_string ("arxml_ecuc_classes.galgas"), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 50)) ;
      GALGAS_string var_graphString_1452 = var_classGraph_1003.getter_graphviz (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 53)) ;
      var_graphString_1452.method_writeToFile (GALGAS_string ("arxml_ecuc_graph.dot"), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 54)) ;
    }
  }
  outArgument_iClassMap = var_classMap_964 ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_arxmlmetaparser_5F_start_5F_symbol_i0_parse (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  nt_xml_5F_header_parse (inCompiler) ;
  nt_xsd_5F_schema_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xml_5F_header_i1_ (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__3F_xml COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 63)) ;
  nt_xsd_5F_ignore_5F_attributes_ (inCompiler) ;
  inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3F__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 65)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xml_5F_header_i1_parse (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__3F_xml COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 63)) ;
  nt_xsd_5F_ignore_5F_attributes_parse (inCompiler) ;
  inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3F__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 65)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_annotation_i2_ (GALGAS_arxmlMetaClassMap & ioArgument_classMap,
                                                                                              GALGAS_arxmlMetaClassGraph & ioArgument_classGraph,
                                                                                              GALGAS_lstring inArgument_parentClass,
                                                                                              C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  nt_xsd_5F_ignore_5F_attributes_ (inCompiler) ;
  switch (select_arxmlmetaparser_5F_syntax_0 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 81)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      switch (select_arxmlmetaparser_5F_syntax_1 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 83)) ;
        switch (select_arxmlmetaparser_5F_syntax_2 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_appinfo COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 84)) ;
          nt_xsd_5F_appinfo_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_documentation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 86)) ;
          nt_xsd_5F_documentation_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
        } break ;
        default:
          break ;
        }
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 91)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 92)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 93)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 94)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_annotation_i2_parse (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  nt_xsd_5F_ignore_5F_attributes_parse (inCompiler) ;
  switch (select_arxmlmetaparser_5F_syntax_0 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 81)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      switch (select_arxmlmetaparser_5F_syntax_1 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 83)) ;
        switch (select_arxmlmetaparser_5F_syntax_2 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_appinfo COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 84)) ;
          nt_xsd_5F_appinfo_parse (inCompiler) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_documentation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 86)) ;
          nt_xsd_5F_documentation_parse (inCompiler) ;
        } break ;
        default:
          break ;
        }
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 91)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 92)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 93)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 94)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_appinfo_i3_ (GALGAS_arxmlMetaClassMap & /* ioArgument_classMap */,
                                                                                           GALGAS_arxmlMetaClassGraph & /* ioArgument_classGraph */,
                                                                                           GALGAS_lstring /* inArgument_parentClass */,
                                                                                           C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  nt_xsd_5F_ignore_5F_attributes_ (inCompiler) ;
  switch (select_arxmlmetaparser_5F_syntax_3 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 107)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 109)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_appinfo COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 110)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 111)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 112)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_appinfo_i3_parse (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  nt_xsd_5F_ignore_5F_attributes_parse (inCompiler) ;
  switch (select_arxmlmetaparser_5F_syntax_3 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 107)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 109)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_appinfo COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 110)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 111)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 112)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_attribute_i4_ (GALGAS_arxmlMetaClassMap & ioArgument_classMap,
                                                                                             GALGAS_arxmlMetaClassGraph & ioArgument_classGraph,
                                                                                             GALGAS_lstring inArgument_parentClass,
                                                                                             C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  GALGAS_lstring var_attributeType_2973 ;
  {
  routine_lstringhere (var_attributeType_2973, GALGAS_string::makeEmptyString (), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 123)) ;
  }
  GALGAS_lstring var_attributeName_3016 ;
  {
  routine_lstringhere (var_attributeName_3016, GALGAS_string::makeEmptyString (), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 124)) ;
  }
  GALGAS_lstring var_attributeRef_3058 ;
  {
  routine_lstringhere (var_attributeRef_3058, GALGAS_string::makeEmptyString (), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 125)) ;
  }
  GALGAS_lstring var_attributePrefix_3104 ;
  {
  routine_lstringhere (var_attributePrefix_3104, GALGAS_string::makeEmptyString (), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 126)) ;
  }
  GALGAS_lstring var_attributeUse_3147 ;
  {
  routine_lstringhere (var_attributeUse_3147, GALGAS_string::makeEmptyString (), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 127)) ;
  }
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_arxmlmetaparser_5F_syntax_4 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_ref COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 130)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 132)) ;
      var_attributeRef_3058 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 133)) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_type COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 134)) ;
      GALGAS_lstring var_fullType_3323 ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 136)) ;
      var_fullType_3323 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 137)) ;
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = var_fullType_3323.readProperty_string ().getter_containsCharacter (GALGAS_char (TO_UNICODE (58)) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 139)).boolEnum () ;
        if (kBoolTrue == test_1) {
          GALGAS_stringlist var_parsed_3490 = var_fullType_3323.readProperty_string ().getter_componentsSeparatedByString (GALGAS_string (":") COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 140)) ;
          GALGAS_string var_parsedString_3570 ;
          var_parsed_3490.method_first (var_parsedString_3570, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 142)) ;
          var_attributePrefix_3104.setter_setString (var_parsedString_3570 COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 143)) ;
          var_attributePrefix_3104.setter_setLocation (var_fullType_3323.readProperty_location () COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 144)) ;
          var_parsed_3490.method_last (var_parsedString_3570, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 145)) ;
          var_attributeType_2973.setter_setString (var_parsedString_3570 COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 146)) ;
          var_attributeType_2973.setter_setLocation (var_fullType_3323.readProperty_location () COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 147)) ;
        }
      }
      if (kBoolFalse == test_1) {
        var_attributeType_2973 = var_fullType_3323 ;
      }
    } break ;
    case 4: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_name COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 151)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 152)) ;
      var_attributeName_3016 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 153)) ;
      var_attributeName_3016.setter_setString (var_attributeName_3016.readProperty_string ().getter_stringByReplacingStringByString (GALGAS_string ("<"), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 154)) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 154)) ;
      var_attributeName_3016.setter_setString (var_attributeName_3016.readProperty_string ().getter_stringByReplacingStringByString (GALGAS_string (">"), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 155)) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 155)) ;
    } break ;
    case 5: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_use COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 156)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 157)) ;
      var_attributeUse_3147 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 158)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  enumGalgasBool test_2 = kBoolTrue ;
  if (kBoolTrue == test_2) {
    test_2 = GALGAS_bool (kIsNotEqual, var_attributeName_3016.readProperty_string ().objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
    if (kBoolTrue == test_2) {
      GALGAS_arxmlMetaAttribute var_newAttribute_4250 = GALGAS_arxmlMetaAttribute::constructor_new (var_attributeName_3016, var_attributeType_2973, var_attributePrefix_3104, var_attributeUse_3147  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 162)) ;
      {
      extensionSetter_addClassAttribute (ioArgument_classMap, inArgument_parentClass, var_newAttribute_4250, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 168)) ;
      }
    }
  }
  switch (select_arxmlmetaparser_5F_syntax_5 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 171)) ;
    bool repeatFlag_3 = true ;
    while (repeatFlag_3) {
      switch (select_arxmlmetaparser_5F_syntax_6 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 173)) ;
        switch (select_arxmlmetaparser_5F_syntax_7 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 174)) ;
          nt_xsd_5F_annotation_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_simpleType COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 176)) ;
          nt_xsd_5F_simpleType_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
        } break ;
        default:
          break ;
        }
      } break ;
      default:
        repeatFlag_3 = false ;
        break ;
      }
    }
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 181)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attribute COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 182)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 183)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 184)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_attribute_i4_parse (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_arxmlmetaparser_5F_syntax_4 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_ref COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 130)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 132)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 133)) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_type COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 134)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 136)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 137)) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_name COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 151)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 152)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 153)) ;
    } break ;
    case 5: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_use COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 156)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 157)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 158)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  switch (select_arxmlmetaparser_5F_syntax_5 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 171)) ;
    bool repeatFlag_1 = true ;
    while (repeatFlag_1) {
      switch (select_arxmlmetaparser_5F_syntax_6 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 173)) ;
        switch (select_arxmlmetaparser_5F_syntax_7 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 174)) ;
          nt_xsd_5F_annotation_parse (inCompiler) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_simpleType COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 176)) ;
          nt_xsd_5F_simpleType_parse (inCompiler) ;
        } break ;
        default:
          break ;
        }
      } break ;
      default:
        repeatFlag_1 = false ;
        break ;
      }
    }
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 181)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attribute COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 182)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 183)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 184)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_attributeGroup_i5_ (GALGAS_arxmlMetaClassMap & ioArgument_classMap,
                                                                                                  GALGAS_arxmlMetaClassGraph & ioArgument_classGraph,
                                                                                                  GALGAS_lstring inArgument_parentClass,
                                                                                                  C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  GALGAS_lstring var_className_5308 ;
  GALGAS_lstring var_nextParentClass_5339 ;
  switch (select_arxmlmetaparser_5F_syntax_8 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_name COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 199)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 201)) ;
    var_className_5308 = inCompiler->synthetizedAttribute_tokenString () ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 202)) ;
    var_className_5308.setter_setString (var_className_5308.readProperty_string ().getter_stringByReplacingStringByString (GALGAS_string ("<"), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 203)) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 203)) ;
    var_className_5308.setter_setString (var_className_5308.readProperty_string ().getter_stringByReplacingStringByString (GALGAS_string (">"), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 204)) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 204)) ;
    GALGAS_lstring var_desc_5683 ;
    {
    routine_lstringhere (var_desc_5683, GALGAS_string::makeEmptyString (), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 205)) ;
    }
    enumGalgasBool test_0 = kBoolTrue ;
    if (kBoolTrue == test_0) {
      test_0 = ioArgument_classMap.getter_hasKey (var_className_5308.readProperty_string () COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 207)).operator_not (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 207)).boolEnum () ;
      if (kBoolTrue == test_0) {
        GALGAS_arxmlMetaClass var_newClass_5807 = GALGAS_arxmlMetaClass::constructor_new (var_className_5308, GALGAS_bool (true), GALGAS_arxmlMetaElementList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 211)), GALGAS_arxmlMetaElementList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 211)), GALGAS_arxmlMetaAttributeList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 212)), GALGAS_arxmlMetaAttributeList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 212)), var_desc_5683  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 208)) ;
        {
        ioArgument_classMap.setter_insertKey (var_className_5308, var_newClass_5807, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 215)) ;
        }
        {
        ioArgument_classGraph.setter_addNode (var_className_5308, var_className_5308, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 216)) ;
        }
      }
    }
    var_nextParentClass_5339 = var_className_5308 ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_ref COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 220)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 221)) ;
    GALGAS_lstring var_fullClassName_6406 = inCompiler->synthetizedAttribute_tokenString () ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 222)) ;
    var_className_5308 = var_fullClassName_6406 ;
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = var_fullClassName_6406.readProperty_string ().getter_containsCharacter (GALGAS_char (TO_UNICODE (58)) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 225)).boolEnum () ;
      if (kBoolTrue == test_1) {
        GALGAS_stringlist var_parsed_6572 = var_fullClassName_6406.readProperty_string ().getter_componentsSeparatedByString (GALGAS_string (":") COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 226)) ;
        GALGAS_string var_parsedString_6675 ;
        var_parsed_6572.method_last (var_parsedString_6675, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 227)) ;
        var_className_5308.setter_setString (var_parsedString_6675 COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 228)) ;
      }
    }
    enumGalgasBool test_2 = kBoolTrue ;
    if (kBoolTrue == test_2) {
      test_2 = GALGAS_bool (kIsNotEqual, inArgument_parentClass.readProperty_string ().objectCompare (var_className_5308.readProperty_string ())).boolEnum () ;
      if (kBoolTrue == test_2) {
        {
        ioArgument_classGraph.setter_addEdge (var_className_5308, inArgument_parentClass COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 233)) ;
        }
      }
    }
    var_nextParentClass_5339 = inArgument_parentClass ;
  } break ;
  default:
    break ;
  }
  switch (select_arxmlmetaparser_5F_syntax_9 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 239)) ;
    bool repeatFlag_3 = true ;
    while (repeatFlag_3) {
      switch (select_arxmlmetaparser_5F_syntax_10 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 241)) ;
        switch (select_arxmlmetaparser_5F_syntax_11 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 242)) ;
          nt_xsd_5F_annotation_ (ioArgument_classMap, ioArgument_classGraph, var_nextParentClass_5339, inCompiler) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attribute COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 244)) ;
          nt_xsd_5F_attribute_ (ioArgument_classMap, ioArgument_classGraph, var_nextParentClass_5339, inCompiler) ;
        } break ;
        case 3: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attributeGroup COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 246)) ;
          nt_xsd_5F_attributeGroup_ (ioArgument_classMap, ioArgument_classGraph, var_nextParentClass_5339, inCompiler) ;
        } break ;
        case 4: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_choice COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 248)) ;
          nt_xsd_5F_choice_ (ioArgument_classMap, ioArgument_classGraph, var_nextParentClass_5339, inCompiler) ;
        } break ;
        case 5: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_sequence COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 250)) ;
          nt_xsd_5F_sequence_ (ioArgument_classMap, ioArgument_classGraph, var_nextParentClass_5339, inCompiler) ;
        } break ;
        default:
          break ;
        }
      } break ;
      default:
        repeatFlag_3 = false ;
        break ;
      }
    }
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 255)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attributeGroup COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 256)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 257)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 258)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_attributeGroup_i5_parse (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  switch (select_arxmlmetaparser_5F_syntax_8 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_name COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 199)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 201)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 202)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_ref COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 220)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 221)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 222)) ;
  } break ;
  default:
    break ;
  }
  switch (select_arxmlmetaparser_5F_syntax_9 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 239)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      switch (select_arxmlmetaparser_5F_syntax_10 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 241)) ;
        switch (select_arxmlmetaparser_5F_syntax_11 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 242)) ;
          nt_xsd_5F_annotation_parse (inCompiler) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attribute COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 244)) ;
          nt_xsd_5F_attribute_parse (inCompiler) ;
        } break ;
        case 3: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attributeGroup COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 246)) ;
          nt_xsd_5F_attributeGroup_parse (inCompiler) ;
        } break ;
        case 4: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_choice COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 248)) ;
          nt_xsd_5F_choice_parse (inCompiler) ;
        } break ;
        case 5: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_sequence COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 250)) ;
          nt_xsd_5F_sequence_parse (inCompiler) ;
        } break ;
        default:
          break ;
        }
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 255)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attributeGroup COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 256)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 257)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 258)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_choice_i6_ (GALGAS_arxmlMetaClassMap & ioArgument_classMap,
                                                                                          GALGAS_arxmlMetaClassGraph & ioArgument_classGraph,
                                                                                          GALGAS_lstring inArgument_parentClass,
                                                                                          C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  nt_xsd_5F_ignore_5F_attributes_ (inCompiler) ;
  switch (select_arxmlmetaparser_5F_syntax_12 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 271)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      switch (select_arxmlmetaparser_5F_syntax_13 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 273)) ;
        switch (select_arxmlmetaparser_5F_syntax_14 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 274)) ;
          nt_xsd_5F_annotation_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_choice COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 276)) ;
          nt_xsd_5F_choice_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
        } break ;
        case 3: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_sequence COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 278)) ;
          nt_xsd_5F_sequence_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
        } break ;
        case 4: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_element COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 280)) ;
          nt_xsd_5F_element_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
        } break ;
        case 5: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_group COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 282)) ;
          nt_xsd_5F_group_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
        } break ;
        default:
          break ;
        }
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 287)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_choice COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 288)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 289)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 290)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_choice_i6_parse (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  nt_xsd_5F_ignore_5F_attributes_parse (inCompiler) ;
  switch (select_arxmlmetaparser_5F_syntax_12 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 271)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      switch (select_arxmlmetaparser_5F_syntax_13 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 273)) ;
        switch (select_arxmlmetaparser_5F_syntax_14 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 274)) ;
          nt_xsd_5F_annotation_parse (inCompiler) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_choice COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 276)) ;
          nt_xsd_5F_choice_parse (inCompiler) ;
        } break ;
        case 3: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_sequence COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 278)) ;
          nt_xsd_5F_sequence_parse (inCompiler) ;
        } break ;
        case 4: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_element COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 280)) ;
          nt_xsd_5F_element_parse (inCompiler) ;
        } break ;
        case 5: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_group COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 282)) ;
          nt_xsd_5F_group_parse (inCompiler) ;
        } break ;
        default:
          break ;
        }
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 287)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_choice COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 288)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 289)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 290)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_complexType_i7_ (GALGAS_arxmlMetaClassMap & ioArgument_classMap,
                                                                                               GALGAS_arxmlMetaClassGraph & ioArgument_classGraph,
                                                                                               GALGAS_lstring inArgument_parentClass,
                                                                                               C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  GALGAS_lstring var_complexAbstract_8496 ;
  {
  routine_lstringhere (var_complexAbstract_8496, GALGAS_string::makeEmptyString (), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 302)) ;
  }
  GALGAS_lstring var_complexMixed_8538 ;
  {
  routine_lstringhere (var_complexMixed_8538, GALGAS_string::makeEmptyString (), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 303)) ;
  }
  GALGAS_lstring var_complexName_8579 ;
  {
  routine_lstringhere (var_complexName_8579, GALGAS_string::makeEmptyString (), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 304)) ;
  }
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_arxmlmetaparser_5F_syntax_15 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_abstract COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 307)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 308)) ;
      var_complexAbstract_8496 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 309)) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_mixed COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 310)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 311)) ;
      var_complexMixed_8538 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 312)) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_name COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 313)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 314)) ;
      var_complexName_8579 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 315)) ;
      var_complexName_8579.setter_setString (var_complexName_8579.readProperty_string ().getter_stringByReplacingStringByString (GALGAS_string ("<"), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 316)) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 316)) ;
      var_complexName_8579.setter_setString (var_complexName_8579.readProperty_string ().getter_stringByReplacingStringByString (GALGAS_string (">"), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 317)) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 317)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  enumGalgasBool test_1 = kBoolTrue ;
  if (kBoolTrue == test_1) {
    test_1 = GALGAS_bool (kIsEqual, var_complexName_8579.readProperty_string ().objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
    if (kBoolTrue == test_1) {
      var_complexName_8579 = inArgument_parentClass ;
    }
  }
  enumGalgasBool test_2 = kBoolTrue ;
  if (kBoolTrue == test_2) {
    test_2 = ioArgument_classMap.getter_hasKey (var_complexName_8579.readProperty_string () COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 326)).operator_not (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 326)).boolEnum () ;
    if (kBoolTrue == test_2) {
      GALGAS_lstring var_desc_9200 ;
      {
      routine_lstringhere (var_desc_9200, GALGAS_string::makeEmptyString (), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 327)) ;
      }
      GALGAS_arxmlMetaClass var_newClass_9238 = GALGAS_arxmlMetaClass::constructor_new (var_complexName_8579, GALGAS_bool (false), GALGAS_arxmlMetaElementList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 331)), GALGAS_arxmlMetaElementList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 331)), GALGAS_arxmlMetaAttributeList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 332)), GALGAS_arxmlMetaAttributeList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 332)), var_desc_9200  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 328)) ;
      {
      ioArgument_classMap.setter_insertKey (var_complexName_8579, var_newClass_9238, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 335)) ;
      }
      {
      ioArgument_classGraph.setter_addNode (var_complexName_8579, var_complexName_8579, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 336)) ;
      }
    }
  }
  switch (select_arxmlmetaparser_5F_syntax_16 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 339)) ;
    bool repeatFlag_3 = true ;
    while (repeatFlag_3) {
      switch (select_arxmlmetaparser_5F_syntax_17 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 341)) ;
        switch (select_arxmlmetaparser_5F_syntax_18 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 342)) ;
          nt_xsd_5F_annotation_ (ioArgument_classMap, ioArgument_classGraph, var_complexName_8579, inCompiler) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attribute COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 344)) ;
          nt_xsd_5F_attribute_ (ioArgument_classMap, ioArgument_classGraph, var_complexName_8579, inCompiler) ;
        } break ;
        case 3: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attributeGroup COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 346)) ;
          nt_xsd_5F_attributeGroup_ (ioArgument_classMap, ioArgument_classGraph, var_complexName_8579, inCompiler) ;
        } break ;
        case 4: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_choice COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 348)) ;
          nt_xsd_5F_choice_ (ioArgument_classMap, ioArgument_classGraph, var_complexName_8579, inCompiler) ;
        } break ;
        case 5: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_sequence COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 350)) ;
          nt_xsd_5F_sequence_ (ioArgument_classMap, ioArgument_classGraph, var_complexName_8579, inCompiler) ;
        } break ;
        case 6: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_group COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 352)) ;
          nt_xsd_5F_group_ (ioArgument_classMap, ioArgument_classGraph, var_complexName_8579, inCompiler) ;
        } break ;
        case 7: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_simpleContent COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 354)) ;
          nt_xsd_5F_simpleContent_ (ioArgument_classMap, ioArgument_classGraph, var_complexName_8579, inCompiler) ;
        } break ;
        default:
          break ;
        }
      } break ;
      default:
        repeatFlag_3 = false ;
        break ;
      }
    }
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 359)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_complexType COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 360)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 361)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 362)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_complexType_i7_parse (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_arxmlmetaparser_5F_syntax_15 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_abstract COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 307)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 308)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 309)) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_mixed COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 310)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 311)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 312)) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_name COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 313)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 314)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 315)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  switch (select_arxmlmetaparser_5F_syntax_16 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 339)) ;
    bool repeatFlag_1 = true ;
    while (repeatFlag_1) {
      switch (select_arxmlmetaparser_5F_syntax_17 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 341)) ;
        switch (select_arxmlmetaparser_5F_syntax_18 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 342)) ;
          nt_xsd_5F_annotation_parse (inCompiler) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attribute COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 344)) ;
          nt_xsd_5F_attribute_parse (inCompiler) ;
        } break ;
        case 3: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attributeGroup COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 346)) ;
          nt_xsd_5F_attributeGroup_parse (inCompiler) ;
        } break ;
        case 4: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_choice COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 348)) ;
          nt_xsd_5F_choice_parse (inCompiler) ;
        } break ;
        case 5: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_sequence COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 350)) ;
          nt_xsd_5F_sequence_parse (inCompiler) ;
        } break ;
        case 6: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_group COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 352)) ;
          nt_xsd_5F_group_parse (inCompiler) ;
        } break ;
        case 7: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_simpleContent COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 354)) ;
          nt_xsd_5F_simpleContent_parse (inCompiler) ;
        } break ;
        default:
          break ;
        }
      } break ;
      default:
        repeatFlag_1 = false ;
        break ;
      }
    }
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 359)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_complexType COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 360)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 361)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 362)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_documentation_i8_ (GALGAS_arxmlMetaClassMap & /* ioArgument_classMap */,
                                                                                                 GALGAS_arxmlMetaClassGraph & /* ioArgument_classGraph */,
                                                                                                 GALGAS_lstring /* inArgument_parentClass */,
                                                                                                 C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  nt_xsd_5F_ignore_5F_attributes_ (inCompiler) ;
  switch (select_arxmlmetaparser_5F_syntax_19 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 375)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 378)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_documentation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 379)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 380)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 381)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_documentation_i8_parse (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  nt_xsd_5F_ignore_5F_attributes_parse (inCompiler) ;
  switch (select_arxmlmetaparser_5F_syntax_19 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 375)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 378)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_documentation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 379)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 380)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 381)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_element_i9_ (GALGAS_arxmlMetaClassMap & ioArgument_classMap,
                                                                                           GALGAS_arxmlMetaClassGraph & ioArgument_classGraph,
                                                                                           GALGAS_lstring inArgument_parentClass,
                                                                                           C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  GALGAS_arxmlMetaElement var_newElement_11107 ;
  GALGAS_lstring var_elementType_11143 ;
  {
  routine_lstringhere (var_elementType_11143, GALGAS_string::makeEmptyString (), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 394)) ;
  }
  GALGAS_lstring var_elementName_11184 ;
  {
  routine_lstringhere (var_elementName_11184, GALGAS_string::makeEmptyString (), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 395)) ;
  }
  GALGAS_lstring var_elementMin_11224 ;
  {
  routine_lstringhere (var_elementMin_11224, GALGAS_string::makeEmptyString (), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 396)) ;
  }
  GALGAS_lstring var_elementMax_11265 ;
  {
  routine_lstringhere (var_elementMax_11265, GALGAS_string::makeEmptyString (), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 397)) ;
  }
  GALGAS_lstring var_elementPrefix_11309 ;
  {
  routine_lstringhere (var_elementPrefix_11309, GALGAS_string::makeEmptyString (), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 398)) ;
  }
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_arxmlmetaparser_5F_syntax_20 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_maxOccurs COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 401)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 402)) ;
      var_elementMax_11265 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 403)) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_minOccurs COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 404)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 405)) ;
      var_elementMin_11224 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 406)) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_type COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 407)) ;
      GALGAS_lstring var_fullType_11482 ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 409)) ;
      var_fullType_11482 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 410)) ;
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = var_fullType_11482.readProperty_string ().getter_containsCharacter (GALGAS_char (TO_UNICODE (58)) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 412)).boolEnum () ;
        if (kBoolTrue == test_1) {
          GALGAS_stringlist var_parsed_11649 = var_fullType_11482.readProperty_string ().getter_componentsSeparatedByString (GALGAS_string (":") COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 413)) ;
          GALGAS_string var_parsedString_11729 ;
          var_parsed_11649.method_first (var_parsedString_11729, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 415)) ;
          var_elementPrefix_11309.setter_setString (var_parsedString_11729 COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 416)) ;
          var_elementPrefix_11309.setter_setLocation (var_fullType_11482.readProperty_location () COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 417)) ;
          var_parsed_11649.method_last (var_parsedString_11729, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 418)) ;
          var_elementType_11143.setter_setString (var_parsedString_11729 COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 419)) ;
          var_elementType_11143.setter_setLocation (var_fullType_11482.readProperty_location () COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 420)) ;
        }
      }
      if (kBoolFalse == test_1) {
        var_elementType_11143 = var_fullType_11482 ;
      }
    } break ;
    case 5: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_name COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 424)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 425)) ;
      var_elementName_11184 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 426)) ;
      var_elementName_11184.setter_setString (var_elementName_11184.readProperty_string ().getter_stringByReplacingStringByString (GALGAS_string ("<"), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 427)) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 427)) ;
      var_elementName_11184.setter_setString (var_elementName_11184.readProperty_string ().getter_stringByReplacingStringByString (GALGAS_string (">"), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 428)) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 428)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  enumGalgasBool test_2 = kBoolTrue ;
  if (kBoolTrue == test_2) {
    test_2 = GALGAS_bool (kIsEqual, var_elementName_11184.readProperty_string ().objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
    if (kBoolTrue == test_2) {
      TC_Array <C_FixItDescription> fixItArray3 ;
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 432)), GALGAS_string ("An xsd:element must have a name."), fixItArray3  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 432)) ;
    }
  }
  enumGalgasBool test_4 = kBoolTrue ;
  if (kBoolTrue == test_4) {
    test_4 = GALGAS_bool (kIsEqual, var_elementMax_11265.readProperty_string ().objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
    if (kBoolTrue == test_4) {
      {
      routine_lstringhere (var_elementMax_11265, GALGAS_string ("unbounded"), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 440)) ;
      }
    }
  }
  enumGalgasBool test_5 = kBoolTrue ;
  if (kBoolTrue == test_5) {
    test_5 = GALGAS_bool (kIsEqual, var_elementMin_11224.readProperty_string ().objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
    if (kBoolTrue == test_5) {
      {
      routine_lstringhere (var_elementMin_11224, GALGAS_string ("0"), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 443)) ;
      }
    }
  }
  enumGalgasBool test_6 = kBoolTrue ;
  if (kBoolTrue == test_6) {
    test_6 = GALGAS_bool (kIsEqual, var_elementType_11143.readProperty_string ().objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
    if (kBoolTrue == test_6) {
      var_elementType_11143 = var_elementName_11184 ;
    }
  }
  if (kBoolFalse == test_6) {
    {
    ioArgument_classGraph.setter_addEdge (var_elementType_11143, var_elementName_11184 COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 449)) ;
    }
  }
  enumGalgasBool test_7 = kBoolTrue ;
  if (kBoolTrue == test_7) {
    test_7 = ioArgument_classMap.getter_hasKey (var_elementName_11184.readProperty_string () COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 452)).operator_not (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 452)).boolEnum () ;
    if (kBoolTrue == test_7) {
      GALGAS_lstring var_desc_12968 ;
      {
      routine_lstringhere (var_desc_12968, GALGAS_string::makeEmptyString (), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 453)) ;
      }
      GALGAS_arxmlMetaClass var_newClass_13006 = GALGAS_arxmlMetaClass::constructor_new (var_elementName_11184, GALGAS_bool (false), GALGAS_arxmlMetaElementList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 457)), GALGAS_arxmlMetaElementList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 457)), GALGAS_arxmlMetaAttributeList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 458)), GALGAS_arxmlMetaAttributeList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 458)), var_desc_12968  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 454)) ;
      {
      ioArgument_classMap.setter_insertKey (var_elementName_11184, var_newClass_13006, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 461)) ;
      }
      {
      ioArgument_classGraph.setter_addNode (var_elementName_11184, var_elementName_11184, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 462)) ;
      }
    }
  }
  var_newElement_11107 = GALGAS_arxmlMetaElement::constructor_new (var_elementName_11184, var_elementType_11143, var_elementMin_11224, var_elementMax_11265, var_elementPrefix_11309  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 465)) ;
  {
  extensionSetter_addClassElement (ioArgument_classMap, inArgument_parentClass, var_newElement_11107, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 471)) ;
  }
  switch (select_arxmlmetaparser_5F_syntax_21 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 473)) ;
    bool repeatFlag_8 = true ;
    while (repeatFlag_8) {
      switch (select_arxmlmetaparser_5F_syntax_22 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 475)) ;
        switch (select_arxmlmetaparser_5F_syntax_23 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 476)) ;
          nt_xsd_5F_annotation_ (ioArgument_classMap, ioArgument_classGraph, var_elementName_11184, inCompiler) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_complexType COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 478)) ;
          nt_xsd_5F_complexType_ (ioArgument_classMap, ioArgument_classGraph, var_elementName_11184, inCompiler) ;
        } break ;
        case 3: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_simpleType COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 480)) ;
          nt_xsd_5F_simpleType_ (ioArgument_classMap, ioArgument_classGraph, var_elementName_11184, inCompiler) ;
        } break ;
        default:
          break ;
        }
      } break ;
      default:
        repeatFlag_8 = false ;
        break ;
      }
    }
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 485)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_element COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 486)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 487)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 488)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_element_i9_parse (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_arxmlmetaparser_5F_syntax_20 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_maxOccurs COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 401)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 402)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 403)) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_minOccurs COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 404)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 405)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 406)) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_type COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 407)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 409)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 410)) ;
    } break ;
    case 5: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_name COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 424)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 425)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 426)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  switch (select_arxmlmetaparser_5F_syntax_21 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 473)) ;
    bool repeatFlag_1 = true ;
    while (repeatFlag_1) {
      switch (select_arxmlmetaparser_5F_syntax_22 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 475)) ;
        switch (select_arxmlmetaparser_5F_syntax_23 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 476)) ;
          nt_xsd_5F_annotation_parse (inCompiler) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_complexType COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 478)) ;
          nt_xsd_5F_complexType_parse (inCompiler) ;
        } break ;
        case 3: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_simpleType COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 480)) ;
          nt_xsd_5F_simpleType_parse (inCompiler) ;
        } break ;
        default:
          break ;
        }
      } break ;
      default:
        repeatFlag_1 = false ;
        break ;
      }
    }
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 485)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_element COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 486)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 487)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 488)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_enumeration_i10_ (GALGAS_arxmlMetaClassMap & ioArgument_classMap,
                                                                                                GALGAS_arxmlMetaClassGraph & ioArgument_classGraph,
                                                                                                GALGAS_lstring inArgument_parentClass,
                                                                                                GALGAS_arxmlMetaSimpletype & ioArgument_restriction,
                                                                                                C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_value COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 501)) ;
  inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 502)) ;
  GALGAS_lstring var_enumValue_14514 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 503)) ;
  {
  ioArgument_restriction.insulate (HERE) ;
  cPtr_arxmlMetaSimpletype * ptr_14531 = (cPtr_arxmlMetaSimpletype *) ioArgument_restriction.ptr () ;
  callExtensionSetter_addValue ((cPtr_arxmlMetaSimpletype *) ptr_14531, var_enumValue_14514, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 504)) ;
  }
  switch (select_arxmlmetaparser_5F_syntax_24 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 506)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      switch (select_arxmlmetaparser_5F_syntax_25 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 508)) ;
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 509)) ;
        nt_xsd_5F_annotation_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 513)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_enumeration COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 514)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 515)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 516)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_enumeration_i10_parse (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_value COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 501)) ;
  inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 502)) ;
  inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 503)) ;
  switch (select_arxmlmetaparser_5F_syntax_24 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 506)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      switch (select_arxmlmetaparser_5F_syntax_25 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 508)) ;
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 509)) ;
        nt_xsd_5F_annotation_parse (inCompiler) ;
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 513)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_enumeration COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 514)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 515)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 516)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_extension_i11_ (GALGAS_arxmlMetaClassMap & ioArgument_classMap,
                                                                                              GALGAS_arxmlMetaClassGraph & ioArgument_classGraph,
                                                                                              GALGAS_lstring inArgument_parentClass,
                                                                                              C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  nt_xsd_5F_ignore_5F_attributes_ (inCompiler) ;
  switch (select_arxmlmetaparser_5F_syntax_26 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 530)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      switch (select_arxmlmetaparser_5F_syntax_27 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 532)) ;
        switch (select_arxmlmetaparser_5F_syntax_28 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 533)) ;
          nt_xsd_5F_annotation_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attribute COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 535)) ;
          nt_xsd_5F_attribute_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
        } break ;
        case 3: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attributeGroup COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 537)) ;
          nt_xsd_5F_attributeGroup_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
        } break ;
        case 4: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_choice COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 539)) ;
          nt_xsd_5F_choice_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
        } break ;
        case 5: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_sequence COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 541)) ;
          nt_xsd_5F_sequence_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
        } break ;
        case 6: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_group COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 543)) ;
          nt_xsd_5F_group_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
        } break ;
        default:
          break ;
        }
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 548)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_extension COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 549)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 550)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 551)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_extension_i11_parse (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  nt_xsd_5F_ignore_5F_attributes_parse (inCompiler) ;
  switch (select_arxmlmetaparser_5F_syntax_26 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 530)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      switch (select_arxmlmetaparser_5F_syntax_27 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 532)) ;
        switch (select_arxmlmetaparser_5F_syntax_28 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 533)) ;
          nt_xsd_5F_annotation_parse (inCompiler) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attribute COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 535)) ;
          nt_xsd_5F_attribute_parse (inCompiler) ;
        } break ;
        case 3: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attributeGroup COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 537)) ;
          nt_xsd_5F_attributeGroup_parse (inCompiler) ;
        } break ;
        case 4: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_choice COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 539)) ;
          nt_xsd_5F_choice_parse (inCompiler) ;
        } break ;
        case 5: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_sequence COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 541)) ;
          nt_xsd_5F_sequence_parse (inCompiler) ;
        } break ;
        case 6: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_group COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 543)) ;
          nt_xsd_5F_group_parse (inCompiler) ;
        } break ;
        default:
          break ;
        }
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 548)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_extension COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 549)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 550)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 551)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_group_i12_ (GALGAS_arxmlMetaClassMap & ioArgument_classMap,
                                                                                          GALGAS_arxmlMetaClassGraph & ioArgument_classGraph,
                                                                                          GALGAS_lstring inArgument_parentClass,
                                                                                          C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  GALGAS_lstring var_className_15877 ;
  GALGAS_lstring var_nextParentClass_15908 ;
  switch (select_arxmlmetaparser_5F_syntax_29 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_name COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 566)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 568)) ;
    var_className_15877 = inCompiler->synthetizedAttribute_tokenString () ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 569)) ;
    var_className_15877.setter_setString (var_className_15877.readProperty_string ().getter_stringByReplacingStringByString (GALGAS_string ("<"), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 570)) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 570)) ;
    var_className_15877.setter_setString (var_className_15877.readProperty_string ().getter_stringByReplacingStringByString (GALGAS_string (">"), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 571)) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 571)) ;
    GALGAS_lstring var_desc_16252 ;
    {
    routine_lstringhere (var_desc_16252, GALGAS_string::makeEmptyString (), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 572)) ;
    }
    enumGalgasBool test_0 = kBoolTrue ;
    if (kBoolTrue == test_0) {
      test_0 = ioArgument_classMap.getter_hasKey (var_className_15877.readProperty_string () COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 574)).operator_not (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 574)).boolEnum () ;
      if (kBoolTrue == test_0) {
        GALGAS_arxmlMetaClass var_newClass_16376 = GALGAS_arxmlMetaClass::constructor_new (var_className_15877, GALGAS_bool (false), GALGAS_arxmlMetaElementList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 578)), GALGAS_arxmlMetaElementList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 578)), GALGAS_arxmlMetaAttributeList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 579)), GALGAS_arxmlMetaAttributeList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 579)), var_desc_16252  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 575)) ;
        {
        ioArgument_classMap.setter_insertKey (var_className_15877, var_newClass_16376, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 582)) ;
        }
        {
        ioArgument_classGraph.setter_addNode (var_className_15877, var_className_15877, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 583)) ;
        }
      }
    }
    var_nextParentClass_15908 = var_className_15877 ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_ref COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 587)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 588)) ;
    GALGAS_lstring var_fullClassName_16965 = inCompiler->synthetizedAttribute_tokenString () ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 589)) ;
    var_className_15877 = var_fullClassName_16965 ;
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = var_fullClassName_16965.readProperty_string ().getter_containsCharacter (GALGAS_char (TO_UNICODE (58)) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 592)).boolEnum () ;
      if (kBoolTrue == test_1) {
        GALGAS_stringlist var_parsed_17131 = var_fullClassName_16965.readProperty_string ().getter_componentsSeparatedByString (GALGAS_string (":") COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 593)) ;
        GALGAS_string var_parsedString_17234 ;
        var_parsed_17131.method_last (var_parsedString_17234, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 594)) ;
        var_className_15877.setter_setString (var_parsedString_17234 COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 595)) ;
      }
    }
    enumGalgasBool test_2 = kBoolTrue ;
    if (kBoolTrue == test_2) {
      test_2 = GALGAS_bool (kIsNotEqual, inArgument_parentClass.readProperty_string ().objectCompare (var_className_15877.readProperty_string ())).boolEnum () ;
      if (kBoolTrue == test_2) {
        {
        ioArgument_classGraph.setter_addEdge (var_className_15877, inArgument_parentClass COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 600)) ;
        }
      }
    }
    var_nextParentClass_15908 = inArgument_parentClass ;
  } break ;
  default:
    break ;
  }
  switch (select_arxmlmetaparser_5F_syntax_30 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 607)) ;
    bool repeatFlag_3 = true ;
    while (repeatFlag_3) {
      switch (select_arxmlmetaparser_5F_syntax_31 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 609)) ;
        switch (select_arxmlmetaparser_5F_syntax_32 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 610)) ;
          nt_xsd_5F_annotation_ (ioArgument_classMap, ioArgument_classGraph, var_nextParentClass_15908, inCompiler) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_choice COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 612)) ;
          nt_xsd_5F_choice_ (ioArgument_classMap, ioArgument_classGraph, var_nextParentClass_15908, inCompiler) ;
        } break ;
        case 3: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_sequence COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 614)) ;
          nt_xsd_5F_sequence_ (ioArgument_classMap, ioArgument_classGraph, var_nextParentClass_15908, inCompiler) ;
        } break ;
        case 4: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_element COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 616)) ;
          nt_xsd_5F_element_ (ioArgument_classMap, ioArgument_classGraph, var_nextParentClass_15908, inCompiler) ;
        } break ;
        default:
          break ;
        }
      } break ;
      default:
        repeatFlag_3 = false ;
        break ;
      }
    }
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 621)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_group COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 622)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 623)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 624)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_group_i12_parse (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  switch (select_arxmlmetaparser_5F_syntax_29 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_name COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 566)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 568)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 569)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_ref COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 587)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 588)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 589)) ;
  } break ;
  default:
    break ;
  }
  switch (select_arxmlmetaparser_5F_syntax_30 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 607)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      switch (select_arxmlmetaparser_5F_syntax_31 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 609)) ;
        switch (select_arxmlmetaparser_5F_syntax_32 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 610)) ;
          nt_xsd_5F_annotation_parse (inCompiler) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_choice COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 612)) ;
          nt_xsd_5F_choice_parse (inCompiler) ;
        } break ;
        case 3: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_sequence COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 614)) ;
          nt_xsd_5F_sequence_parse (inCompiler) ;
        } break ;
        case 4: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_element COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 616)) ;
          nt_xsd_5F_element_parse (inCompiler) ;
        } break ;
        default:
          break ;
        }
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 621)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_group COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 622)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 623)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 624)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_import_i13_ (GALGAS_arxmlMetaClassMap & ioArgument_classMap,
                                                                                           GALGAS_arxmlMetaClassGraph & ioArgument_classGraph,
                                                                                           GALGAS_lstring inArgument_parentClass,
                                                                                           C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  nt_xsd_5F_ignore_5F_attributes_ (inCompiler) ;
  switch (select_arxmlmetaparser_5F_syntax_33 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 636)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      switch (select_arxmlmetaparser_5F_syntax_34 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 638)) ;
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 639)) ;
        nt_xsd_5F_annotation_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 643)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 644)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 645)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 646)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_import_i13_parse (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  nt_xsd_5F_ignore_5F_attributes_parse (inCompiler) ;
  switch (select_arxmlmetaparser_5F_syntax_33 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 636)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      switch (select_arxmlmetaparser_5F_syntax_34 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 638)) ;
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 639)) ;
        nt_xsd_5F_annotation_parse (inCompiler) ;
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 643)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 644)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 645)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 646)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_restriction_i14_ (GALGAS_arxmlMetaClassMap & ioArgument_classMap,
                                                                                                GALGAS_arxmlMetaClassGraph & ioArgument_classGraph,
                                                                                                GALGAS_lstring inArgument_parentClass,
                                                                                                GALGAS_arxmlMetaSimpletype & ioArgument_restriction,
                                                                                                C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_base COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 659)) ;
  inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 660)) ;
  GALGAS_lstring var_baseType_18699 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 661)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    GALGAS_bool test_1 = GALGAS_bool (kIsEqual, GALGAS_string ("xsd:string").objectCompare (var_baseType_18699.readProperty_string ())) ;
    if (kBoolTrue != test_1.boolEnum ()) {
      test_1 = GALGAS_bool (kIsEqual, GALGAS_string ("xsd:NMTOKEN").objectCompare (var_baseType_18699.readProperty_string ())) ;
    }
    GALGAS_bool test_2 = test_1 ;
    if (kBoolTrue != test_2.boolEnum ()) {
      test_2 = GALGAS_bool (kIsEqual, GALGAS_string ("xsd:NMTOKENS").objectCompare (var_baseType_18699.readProperty_string ())) ;
    }
    test_0 = test_2.boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      ioArgument_restriction.setter_setBase (GALGAS_restrictionBaseType::constructor_restrictionString (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 666)) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 666)) ;
      }
      {
      ioArgument_restriction.setter_setType (GALGAS_restrictionType::constructor_restrictionSimple (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 667)) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 667)) ;
      }
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_3 = kBoolTrue ;
    if (kBoolTrue == test_3) {
      test_3 = GALGAS_bool (kIsEqual, GALGAS_string ("xsd:unsignedInt").objectCompare (var_baseType_18699.readProperty_string ())).boolEnum () ;
      if (kBoolTrue == test_3) {
        {
        ioArgument_restriction.setter_setBase (GALGAS_restrictionBaseType::constructor_restrictionUint (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 669)) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 669)) ;
        }
        {
        ioArgument_restriction.setter_setType (GALGAS_restrictionType::constructor_restrictionSimple (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 670)) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 670)) ;
        }
      }
    }
    if (kBoolFalse == test_3) {
      enumGalgasBool test_4 = kBoolTrue ;
      if (kBoolTrue == test_4) {
        test_4 = GALGAS_bool (kIsEqual, GALGAS_string ("xsd:double").objectCompare (var_baseType_18699.readProperty_string ())).boolEnum () ;
        if (kBoolTrue == test_4) {
          {
          ioArgument_restriction.setter_setBase (GALGAS_restrictionBaseType::constructor_restrictionDouble (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 672)) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 672)) ;
          }
          {
          ioArgument_restriction.setter_setType (GALGAS_restrictionType::constructor_restrictionSimple (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 673)) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 673)) ;
          }
        }
      }
      if (kBoolFalse == test_4) {
        TC_Array <C_FixItDescription> fixItArray5 ;
        inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 675)), GALGAS_string ("Undefined/unimplemented base type ").add_operation (var_baseType_18699.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 675)), fixItArray5  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 675)) ;
      }
    }
  }
  switch (select_arxmlmetaparser_5F_syntax_35 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 678)) ;
    bool repeatFlag_6 = true ;
    while (repeatFlag_6) {
      switch (select_arxmlmetaparser_5F_syntax_36 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 680)) ;
        switch (select_arxmlmetaparser_5F_syntax_37 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 681)) ;
          nt_xsd_5F_annotation_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attribute COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 683)) ;
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_TODO COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 684)) ;
          nt_xsd_5F_attribute_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
          {
          ioArgument_restriction.setter_setType (GALGAS_restrictionType::constructor_restrictionUnused (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 686)) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 686)) ;
          }
        } break ;
        case 3: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attributeGroup COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 687)) ;
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_TODO COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 688)) ;
          nt_xsd_5F_attributeGroup_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
          {
          ioArgument_restriction.setter_setType (GALGAS_restrictionType::constructor_restrictionUnused (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 690)) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 690)) ;
          }
        } break ;
        case 4: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_choice COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 691)) ;
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_TODO COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 692)) ;
          nt_xsd_5F_choice_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
          {
          ioArgument_restriction.setter_setType (GALGAS_restrictionType::constructor_restrictionUnused (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 694)) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 694)) ;
          }
        } break ;
        case 5: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_sequence COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 695)) ;
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_TODO COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 696)) ;
          nt_xsd_5F_sequence_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
          {
          ioArgument_restriction.setter_setType (GALGAS_restrictionType::constructor_restrictionUnused (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 698)) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 698)) ;
          }
        } break ;
        case 6: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_group COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 699)) ;
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_TODO COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 700)) ;
          nt_xsd_5F_group_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
          {
          ioArgument_restriction.setter_setType (GALGAS_restrictionType::constructor_restrictionUnused (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 702)) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 702)) ;
          }
        } break ;
        case 7: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_simpleType COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 703)) ;
          nt_xsd_5F_simpleType_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
          {
          ioArgument_restriction.setter_setType (GALGAS_restrictionType::constructor_restrictionUnused (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 705)) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 705)) ;
          }
        } break ;
        case 8: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_whiteSpace COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 706)) ;
          enumGalgasBool test_7 = kBoolTrue ;
          if (kBoolTrue == test_7) {
            GALGAS_bool test_8 = ioArgument_restriction.readProperty_type ().getter_isRestrictionSimple (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 708)).operator_not (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 708)) ;
            if (kBoolTrue == test_8.boolEnum ()) {
              test_8 = ioArgument_restriction.readProperty_base ().getter_isRestrictionString (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 709)).operator_not (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 709)) ;
            }
            test_7 = test_8.boolEnum () ;
            if (kBoolTrue == test_7) {
              TC_Array <C_FixItDescription> fixItArray9 ;
              inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 710)), GALGAS_string ("Pattern condition to something not a string."), fixItArray9  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 710)) ;
            }
          }
          nt_xsd_5F_whiteSpace_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
        } break ;
        case 9: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_maxLength COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 713)) ;
          enumGalgasBool test_10 = kBoolTrue ;
          if (kBoolTrue == test_10) {
            GALGAS_bool test_11 = ioArgument_restriction.readProperty_type ().getter_isRestrictionSimple (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 715)).operator_not (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 715)) ;
            if (kBoolTrue == test_11.boolEnum ()) {
              test_11 = ioArgument_restriction.readProperty_base ().getter_isRestrictionString (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 716)).operator_not (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 716)) ;
            }
            test_10 = test_11.boolEnum () ;
            if (kBoolTrue == test_10) {
              TC_Array <C_FixItDescription> fixItArray12 ;
              inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 717)), GALGAS_string ("Pattern condition to something not a string."), fixItArray12  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 717)) ;
            }
          }
          nt_xsd_5F_maxLength_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
        } break ;
        case 10: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_pattern COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 720)) ;
          enumGalgasBool test_13 = kBoolTrue ;
          if (kBoolTrue == test_13) {
            GALGAS_bool test_14 = ioArgument_restriction.readProperty_type ().getter_isRestrictionSimple (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 722)).operator_not (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 722)) ;
            if (kBoolTrue == test_14.boolEnum ()) {
              test_14 = ioArgument_restriction.readProperty_base ().getter_isRestrictionString (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 723)).operator_not (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 723)) ;
            }
            test_13 = test_14.boolEnum () ;
            if (kBoolTrue == test_13) {
              TC_Array <C_FixItDescription> fixItArray15 ;
              inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 724)), GALGAS_string ("Pattern condition to something not a string."), fixItArray15  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 724)) ;
            }
          }
          nt_xsd_5F_pattern_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
        } break ;
        case 11: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_enumeration COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 727)) ;
          enumGalgasBool test_16 = kBoolTrue ;
          if (kBoolTrue == test_16) {
            GALGAS_bool test_17 = ioArgument_restriction.readProperty_type ().getter_isRestrictionEnum (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 728)).operator_not (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 728)) ;
            if (kBoolTrue == test_17.boolEnum ()) {
              test_17 = ioArgument_restriction.readProperty_type ().getter_isRestrictionSimple (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 729)).operator_not (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 729)) ;
            }
            test_16 = test_17.boolEnum () ;
            if (kBoolTrue == test_16) {
              TC_Array <C_FixItDescription> fixItArray18 ;
              inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 730)), GALGAS_string ("Multiple type in a same restriction."), fixItArray18  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 730)) ;
            }
          }
          enumGalgasBool test_19 = kBoolTrue ;
          if (kBoolTrue == test_19) {
            test_19 = ioArgument_restriction.readProperty_base ().getter_isRestrictionString (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 732)).operator_not (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 732)).boolEnum () ;
            if (kBoolTrue == test_19) {
              TC_Array <C_FixItDescription> fixItArray20 ;
              inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 733)), GALGAS_string ("Enumeration while restriction base not set to string."), fixItArray20  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 733)) ;
            }
          }
          nt_xsd_5F_enumeration_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, ioArgument_restriction, inCompiler) ;
          {
          ioArgument_restriction.setter_setType (GALGAS_restrictionType::constructor_restrictionEnum (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 736)) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 736)) ;
          }
        } break ;
        default:
          break ;
        }
      } break ;
      default:
        repeatFlag_6 = false ;
        break ;
      }
    }
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 740)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_restriction COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 741)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 742)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 743)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_restriction_i14_parse (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_base COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 659)) ;
  inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 660)) ;
  inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 661)) ;
  switch (select_arxmlmetaparser_5F_syntax_35 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 678)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      switch (select_arxmlmetaparser_5F_syntax_36 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 680)) ;
        switch (select_arxmlmetaparser_5F_syntax_37 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 681)) ;
          nt_xsd_5F_annotation_parse (inCompiler) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attribute COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 683)) ;
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_TODO COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 684)) ;
          nt_xsd_5F_attribute_parse (inCompiler) ;
        } break ;
        case 3: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attributeGroup COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 687)) ;
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_TODO COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 688)) ;
          nt_xsd_5F_attributeGroup_parse (inCompiler) ;
        } break ;
        case 4: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_choice COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 691)) ;
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_TODO COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 692)) ;
          nt_xsd_5F_choice_parse (inCompiler) ;
        } break ;
        case 5: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_sequence COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 695)) ;
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_TODO COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 696)) ;
          nt_xsd_5F_sequence_parse (inCompiler) ;
        } break ;
        case 6: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_group COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 699)) ;
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_TODO COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 700)) ;
          nt_xsd_5F_group_parse (inCompiler) ;
        } break ;
        case 7: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_simpleType COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 703)) ;
          nt_xsd_5F_simpleType_parse (inCompiler) ;
        } break ;
        case 8: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_whiteSpace COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 706)) ;
          nt_xsd_5F_whiteSpace_parse (inCompiler) ;
        } break ;
        case 9: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_maxLength COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 713)) ;
          nt_xsd_5F_maxLength_parse (inCompiler) ;
        } break ;
        case 10: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_pattern COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 720)) ;
          nt_xsd_5F_pattern_parse (inCompiler) ;
        } break ;
        case 11: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_enumeration COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 727)) ;
          nt_xsd_5F_enumeration_parse (inCompiler) ;
        } break ;
        default:
          break ;
        }
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 740)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_restriction COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 741)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 742)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 743)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_schema_i15_ (GALGAS_arxmlMetaClassMap & ioArgument_classMap,
                                                                                           GALGAS_arxmlMetaClassGraph & ioArgument_classGraph,
                                                                                           C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 754)) ;
  inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_schema COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 755)) ;
  nt_xsd_5F_ignore_5F_attributes_ (inCompiler) ;
  inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 757)) ;
  GALGAS_lstring var_rootClassName_22435 ;
  {
  routine_lstringhere (var_rootClassName_22435, GALGAS_string ("root"), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 763)) ;
  }
  GALGAS_lstring var_desc_22477 ;
  {
  routine_lstringhere (var_desc_22477, GALGAS_string ("Root class containing the main AUTOSAR node"), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 764)) ;
  }
  GALGAS_arxmlMetaClass var_rootClass_22558 = GALGAS_arxmlMetaClass::constructor_new (var_rootClassName_22435, GALGAS_bool (false), GALGAS_arxmlMetaElementList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 769)), GALGAS_arxmlMetaElementList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 769)), GALGAS_arxmlMetaAttributeList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 770)), GALGAS_arxmlMetaAttributeList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 770)), var_desc_22477  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 766)) ;
  {
  ioArgument_classMap.setter_insertKey (var_rootClassName_22435, var_rootClass_22558, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 773)) ;
  }
  {
  ioArgument_classGraph.setter_addNode (var_rootClassName_22435, var_rootClassName_22435, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 774)) ;
  }
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_arxmlmetaparser_5F_syntax_38 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 777)) ;
      switch (select_arxmlmetaparser_5F_syntax_39 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 778)) ;
        nt_xsd_5F_annotation_ (ioArgument_classMap, ioArgument_classGraph, var_rootClassName_22435, inCompiler) ;
      } break ;
      case 2: {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attribute COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 780)) ;
        nt_xsd_5F_attribute_ (ioArgument_classMap, ioArgument_classGraph, var_rootClassName_22435, inCompiler) ;
      } break ;
      case 3: {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attributeGroup COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 782)) ;
        nt_xsd_5F_attributeGroup_ (ioArgument_classMap, ioArgument_classGraph, var_rootClassName_22435, inCompiler) ;
      } break ;
      case 4: {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_complexType COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 784)) ;
        nt_xsd_5F_complexType_ (ioArgument_classMap, ioArgument_classGraph, var_rootClassName_22435, inCompiler) ;
      } break ;
      case 5: {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_element COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 786)) ;
        nt_xsd_5F_element_ (ioArgument_classMap, ioArgument_classGraph, var_rootClassName_22435, inCompiler) ;
      } break ;
      case 6: {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_group COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 788)) ;
        nt_xsd_5F_group_ (ioArgument_classMap, ioArgument_classGraph, var_rootClassName_22435, inCompiler) ;
      } break ;
      case 7: {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_import COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 790)) ;
        nt_xsd_5F_import_ (ioArgument_classMap, ioArgument_classGraph, var_rootClassName_22435, inCompiler) ;
      } break ;
      case 8: {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_simpleType COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 792)) ;
        nt_xsd_5F_simpleType_ (ioArgument_classMap, ioArgument_classGraph, var_rootClassName_22435, inCompiler) ;
      } break ;
      default:
        break ;
      }
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 798)) ;
  inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_schema COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 799)) ;
  inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 800)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_schema_i15_parse (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 754)) ;
  inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_schema COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 755)) ;
  nt_xsd_5F_ignore_5F_attributes_parse (inCompiler) ;
  inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 757)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_arxmlmetaparser_5F_syntax_38 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 777)) ;
      switch (select_arxmlmetaparser_5F_syntax_39 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 778)) ;
        nt_xsd_5F_annotation_parse (inCompiler) ;
      } break ;
      case 2: {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attribute COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 780)) ;
        nt_xsd_5F_attribute_parse (inCompiler) ;
      } break ;
      case 3: {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attributeGroup COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 782)) ;
        nt_xsd_5F_attributeGroup_parse (inCompiler) ;
      } break ;
      case 4: {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_complexType COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 784)) ;
        nt_xsd_5F_complexType_parse (inCompiler) ;
      } break ;
      case 5: {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_element COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 786)) ;
        nt_xsd_5F_element_parse (inCompiler) ;
      } break ;
      case 6: {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_group COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 788)) ;
        nt_xsd_5F_group_parse (inCompiler) ;
      } break ;
      case 7: {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_import COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 790)) ;
        nt_xsd_5F_import_parse (inCompiler) ;
      } break ;
      case 8: {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_simpleType COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 792)) ;
        nt_xsd_5F_simpleType_parse (inCompiler) ;
      } break ;
      default:
        break ;
      }
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 798)) ;
  inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_schema COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 799)) ;
  inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 800)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_sequence_i16_ (GALGAS_arxmlMetaClassMap & ioArgument_classMap,
                                                                                             GALGAS_arxmlMetaClassGraph & ioArgument_classGraph,
                                                                                             GALGAS_lstring inArgument_parentClass,
                                                                                             C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  switch (select_arxmlmetaparser_5F_syntax_40 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 812)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      switch (select_arxmlmetaparser_5F_syntax_41 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 814)) ;
        switch (select_arxmlmetaparser_5F_syntax_42 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 815)) ;
          nt_xsd_5F_annotation_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_choice COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 817)) ;
          nt_xsd_5F_choice_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
        } break ;
        case 3: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_sequence COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 819)) ;
          nt_xsd_5F_sequence_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
        } break ;
        case 4: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_element COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 821)) ;
          nt_xsd_5F_element_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
        } break ;
        case 5: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_group COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 823)) ;
          nt_xsd_5F_group_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
        } break ;
        default:
          break ;
        }
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 828)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_sequence COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 829)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 830)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 831)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_sequence_i16_parse (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  switch (select_arxmlmetaparser_5F_syntax_40 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 812)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      switch (select_arxmlmetaparser_5F_syntax_41 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 814)) ;
        switch (select_arxmlmetaparser_5F_syntax_42 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 815)) ;
          nt_xsd_5F_annotation_parse (inCompiler) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_choice COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 817)) ;
          nt_xsd_5F_choice_parse (inCompiler) ;
        } break ;
        case 3: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_sequence COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 819)) ;
          nt_xsd_5F_sequence_parse (inCompiler) ;
        } break ;
        case 4: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_element COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 821)) ;
          nt_xsd_5F_element_parse (inCompiler) ;
        } break ;
        case 5: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_group COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 823)) ;
          nt_xsd_5F_group_parse (inCompiler) ;
        } break ;
        default:
          break ;
        }
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 828)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_sequence COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 829)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 830)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 831)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_simpleContent_i17_ (GALGAS_arxmlMetaClassMap & ioArgument_classMap,
                                                                                                  GALGAS_arxmlMetaClassGraph & ioArgument_classGraph,
                                                                                                  GALGAS_lstring inArgument_parentClass,
                                                                                                  C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  switch (select_arxmlmetaparser_5F_syntax_43 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 851)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      switch (select_arxmlmetaparser_5F_syntax_44 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 853)) ;
        switch (select_arxmlmetaparser_5F_syntax_45 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 854)) ;
          nt_xsd_5F_annotation_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_extension COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 856)) ;
          nt_xsd_5F_extension_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
        } break ;
        default:
          break ;
        }
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 863)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_simpleContent COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 864)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 865)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 866)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_simpleContent_i17_parse (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  switch (select_arxmlmetaparser_5F_syntax_43 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 851)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      switch (select_arxmlmetaparser_5F_syntax_44 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 853)) ;
        switch (select_arxmlmetaparser_5F_syntax_45 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 854)) ;
          nt_xsd_5F_annotation_parse (inCompiler) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_extension COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 856)) ;
          nt_xsd_5F_extension_parse (inCompiler) ;
        } break ;
        default:
          break ;
        }
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 863)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_simpleContent COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 864)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 865)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 866)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_simpleType_i18_ (GALGAS_arxmlMetaClassMap & ioArgument_classMap,
                                                                                               GALGAS_arxmlMetaClassGraph & ioArgument_classGraph,
                                                                                               GALGAS_lstring inArgument_parentClass,
                                                                                               C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  GALGAS_lstring var_typeName_26078 ;
  {
  routine_lstringhere (var_typeName_26078, GALGAS_string::makeEmptyString (), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 880)) ;
  }
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_arxmlmetaparser_5F_syntax_46 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_name COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 883)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 884)) ;
      var_typeName_26078 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 885)) ;
      var_typeName_26078.setter_setString (var_typeName_26078.readProperty_string ().getter_stringByReplacingStringByString (GALGAS_string ("<"), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 886)) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 886)) ;
      var_typeName_26078.setter_setString (var_typeName_26078.readProperty_string ().getter_stringByReplacingStringByString (GALGAS_string (">"), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 887)) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 887)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  enumGalgasBool test_1 = kBoolTrue ;
  if (kBoolTrue == test_1) {
    GALGAS_bool test_2 = GALGAS_bool (kIsEqual, inArgument_parentClass.readProperty_string ().objectCompare (GALGAS_string ("root"))) ;
    if (kBoolTrue == test_2.boolEnum ()) {
      test_2 = GALGAS_bool (kIsEqual, var_typeName_26078.readProperty_string ().objectCompare (GALGAS_string::makeEmptyString ())) ;
    }
    test_1 = test_2.boolEnum () ;
    if (kBoolTrue == test_1) {
      TC_Array <C_FixItDescription> fixItArray3 ;
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 891)), GALGAS_string ("The name attribute is required if the simpleType element is").add_operation (GALGAS_string (" a child of the schema element"), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 891)), fixItArray3  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 891)) ;
    }
  }
  GALGAS_arxmlMetaSimpletype var_restriction_26550 = GALGAS_arxmlMetaSimpletype::constructor_new (var_typeName_26078, GALGAS_restrictionType::constructor_restrictionUnused (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 897)), GALGAS_restrictionBaseType::constructor_restrictionUndef (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 898)), GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 899))  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 895)) ;
  enumGalgasBool test_4 = kBoolTrue ;
  if (kBoolTrue == test_4) {
    test_4 = ioArgument_classMap.getter_hasKey (var_typeName_26078.readProperty_string () COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 902)).operator_not (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 902)).boolEnum () ;
    if (kBoolTrue == test_4) {
      GALGAS_lstring var_desc_26980 ;
      {
      routine_lstringhere (var_desc_26980, GALGAS_string::makeEmptyString (), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 903)) ;
      }
      GALGAS_arxmlMetaClass var_newClass_27018 = GALGAS_arxmlMetaClass::constructor_new (var_typeName_26078, GALGAS_bool (false), GALGAS_arxmlMetaElementList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 907)), GALGAS_arxmlMetaElementList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 907)), GALGAS_arxmlMetaAttributeList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 908)), GALGAS_arxmlMetaAttributeList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 908)), var_desc_26980  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 904)) ;
      {
      ioArgument_classMap.setter_insertKey (var_typeName_26078, var_newClass_27018, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 911)) ;
      }
      {
      ioArgument_classGraph.setter_addNode (var_typeName_26078, var_typeName_26078, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 912)) ;
      }
    }
  }
  switch (select_arxmlmetaparser_5F_syntax_47 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 915)) ;
    bool repeatFlag_5 = true ;
    while (repeatFlag_5) {
      switch (select_arxmlmetaparser_5F_syntax_48 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 917)) ;
        switch (select_arxmlmetaparser_5F_syntax_49 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 918)) ;
          nt_xsd_5F_annotation_ (ioArgument_classMap, ioArgument_classGraph, var_typeName_26078, inCompiler) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_restriction COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 920)) ;
          nt_xsd_5F_restriction_ (ioArgument_classMap, ioArgument_classGraph, var_typeName_26078, var_restriction_26550, inCompiler) ;
        } break ;
        default:
          break ;
        }
      } break ;
      default:
        repeatFlag_5 = false ;
        break ;
      }
    }
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 925)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_simpleType COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 926)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 927)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 928)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_simpleType_i18_parse (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_arxmlmetaparser_5F_syntax_46 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_name COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 883)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 884)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 885)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  switch (select_arxmlmetaparser_5F_syntax_47 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 915)) ;
    bool repeatFlag_1 = true ;
    while (repeatFlag_1) {
      switch (select_arxmlmetaparser_5F_syntax_48 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 917)) ;
        switch (select_arxmlmetaparser_5F_syntax_49 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 918)) ;
          nt_xsd_5F_annotation_parse (inCompiler) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_restriction COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 920)) ;
          nt_xsd_5F_restriction_parse (inCompiler) ;
        } break ;
        default:
          break ;
        }
      } break ;
      default:
        repeatFlag_1 = false ;
        break ;
      }
    }
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 925)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_simpleType COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 926)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 927)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 928)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_maxLength_i19_ (GALGAS_arxmlMetaClassMap & ioArgument_classMap,
                                                                                              GALGAS_arxmlMetaClassGraph & ioArgument_classGraph,
                                                                                              GALGAS_lstring inArgument_parentClass,
                                                                                              C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  nt_xsd_5F_ignore_5F_attributes_ (inCompiler) ;
  switch (select_arxmlmetaparser_5F_syntax_50 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 945)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      switch (select_arxmlmetaparser_5F_syntax_51 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 947)) ;
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 948)) ;
        nt_xsd_5F_annotation_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 952)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_maxLength COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 953)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 954)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 955)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_maxLength_i19_parse (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  nt_xsd_5F_ignore_5F_attributes_parse (inCompiler) ;
  switch (select_arxmlmetaparser_5F_syntax_50 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 945)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      switch (select_arxmlmetaparser_5F_syntax_51 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 947)) ;
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 948)) ;
        nt_xsd_5F_annotation_parse (inCompiler) ;
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 952)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_maxLength COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 953)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 954)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 955)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_pattern_i20_ (GALGAS_arxmlMetaClassMap & ioArgument_classMap,
                                                                                            GALGAS_arxmlMetaClassGraph & ioArgument_classGraph,
                                                                                            GALGAS_lstring inArgument_parentClass,
                                                                                            C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  nt_xsd_5F_ignore_5F_attributes_ (inCompiler) ;
  switch (select_arxmlmetaparser_5F_syntax_52 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 970)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      switch (select_arxmlmetaparser_5F_syntax_53 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 972)) ;
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 973)) ;
        nt_xsd_5F_annotation_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 977)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_pattern COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 978)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 979)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 980)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_pattern_i20_parse (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  nt_xsd_5F_ignore_5F_attributes_parse (inCompiler) ;
  switch (select_arxmlmetaparser_5F_syntax_52 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 970)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      switch (select_arxmlmetaparser_5F_syntax_53 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 972)) ;
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 973)) ;
        nt_xsd_5F_annotation_parse (inCompiler) ;
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 977)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_pattern COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 978)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 979)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 980)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_whiteSpace_i21_ (GALGAS_arxmlMetaClassMap & ioArgument_classMap,
                                                                                               GALGAS_arxmlMetaClassGraph & ioArgument_classGraph,
                                                                                               GALGAS_lstring inArgument_parentClass,
                                                                                               C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  nt_xsd_5F_ignore_5F_attributes_ (inCompiler) ;
  switch (select_arxmlmetaparser_5F_syntax_54 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 994)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      switch (select_arxmlmetaparser_5F_syntax_55 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 996)) ;
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 997)) ;
        nt_xsd_5F_annotation_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1001)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_whiteSpace COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1002)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1003)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1004)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_whiteSpace_i21_parse (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  nt_xsd_5F_ignore_5F_attributes_parse (inCompiler) ;
  switch (select_arxmlmetaparser_5F_syntax_54 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 994)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      switch (select_arxmlmetaparser_5F_syntax_55 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 996)) ;
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 997)) ;
        nt_xsd_5F_annotation_parse (inCompiler) ;
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1001)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_whiteSpace COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1002)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1003)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1004)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_ignore_5F_attributes_i22_ (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_arxmlmetaparser_5F_syntax_56 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_abstract COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1011)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1012)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1013)) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attributeFormDefault COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1014)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1015)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1016)) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attributeRef COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1017)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1018)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1019)) ;
    } break ;
    case 5: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_base COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1020)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1021)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1022)) ;
    } break ;
    case 6: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_category COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1023)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1024)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1025)) ;
    } break ;
    case 7: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_CATEGORY COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1026)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1027)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1028)) ;
    } break ;
    case 8: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_color COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1029)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1030)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1031)) ;
    } break ;
    case 9: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_customType COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1032)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1033)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1034)) ;
    } break ;
    case 10: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_elementFormDefault COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1035)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1036)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1037)) ;
    } break ;
    case 11: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_encoding COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1038)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1039)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1040)) ;
    } break ;
    case 12: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_enforceMinMultiplicity COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1041)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1042)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1043)) ;
    } break ;
    case 13: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_globalElement COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1044)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1045)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1046)) ;
    } break ;
    case 14: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_id COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1047)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1048)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1049)) ;
    } break ;
    case 15: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_latestBindingTime COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1050)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1051)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1052)) ;
    } break ;
    case 16: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_maxOccurs COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1053)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1054)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1055)) ;
    } break ;
    case 17: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_minOccurs COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1056)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1057)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1058)) ;
    } break ;
    case 18: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_mixed COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1059)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1060)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1061)) ;
    } break ;
    case 19: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_name COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1062)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1063)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1064)) ;
    } break ;
    case 20: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_namePlural COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1065)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1066)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1067)) ;
    } break ;
    case 21: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_namespace COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1068)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1069)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1070)) ;
    } break ;
    case 22: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_noteType COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1071)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1072)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1073)) ;
    } break ;
    case 23: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_nsPrefix COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1074)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1075)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1076)) ;
    } break ;
    case 24: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_qualifiedName COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1077)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1078)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1079)) ;
    } break ;
    case 25: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_recommendedPackage COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1080)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1081)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1082)) ;
    } break ;
    case 26: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_ref COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1083)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1084)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1085)) ;
    } break ;
    case 27: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_roleElement COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1086)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1087)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1088)) ;
    } break ;
    case 28: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_roleWrapperElement COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1089)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1090)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1091)) ;
    } break ;
    case 29: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_schemaLocation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1092)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1093)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1094)) ;
    } break ;
    case 30: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_sequenceOffset COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1095)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1096)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1097)) ;
    } break ;
    case 31: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_source COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1098)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1099)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1100)) ;
    } break ;
    case 32: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_Splitkey COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1101)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1102)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1103)) ;
    } break ;
    case 33: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_Status COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1104)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1105)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1106)) ;
    } break ;
    case 34: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_StatusRevisionBegin COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1107)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1108)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1109)) ;
    } break ;
    case 35: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_targetNamespace COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1110)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1111)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1112)) ;
    } break ;
    case 36: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_type COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1113)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1114)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1115)) ;
    } break ;
    case 37: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_typeElement COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1116)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1117)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1118)) ;
    } break ;
    case 38: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_typeWrapperElement COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1119)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1120)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1121)) ;
    } break ;
    case 39: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_use COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1122)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1123)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1124)) ;
    } break ;
    case 40: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_value COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1125)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1126)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1127)) ;
    } break ;
    case 41: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_version COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1128)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1129)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1130)) ;
    } break ;
    case 42: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlns_3A_AR COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1131)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1132)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1133)) ;
    } break ;
    case 43: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlns_3A_xsd COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1134)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1135)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1136)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_ignore_5F_attributes_i22_parse (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_arxmlmetaparser_5F_syntax_56 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_abstract COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1011)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1012)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1013)) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attributeFormDefault COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1014)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1015)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1016)) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attributeRef COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1017)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1018)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1019)) ;
    } break ;
    case 5: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_base COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1020)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1021)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1022)) ;
    } break ;
    case 6: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_category COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1023)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1024)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1025)) ;
    } break ;
    case 7: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_CATEGORY COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1026)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1027)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1028)) ;
    } break ;
    case 8: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_color COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1029)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1030)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1031)) ;
    } break ;
    case 9: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_customType COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1032)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1033)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1034)) ;
    } break ;
    case 10: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_elementFormDefault COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1035)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1036)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1037)) ;
    } break ;
    case 11: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_encoding COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1038)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1039)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1040)) ;
    } break ;
    case 12: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_enforceMinMultiplicity COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1041)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1042)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1043)) ;
    } break ;
    case 13: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_globalElement COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1044)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1045)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1046)) ;
    } break ;
    case 14: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_id COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1047)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1048)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1049)) ;
    } break ;
    case 15: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_latestBindingTime COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1050)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1051)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1052)) ;
    } break ;
    case 16: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_maxOccurs COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1053)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1054)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1055)) ;
    } break ;
    case 17: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_minOccurs COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1056)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1057)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1058)) ;
    } break ;
    case 18: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_mixed COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1059)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1060)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1061)) ;
    } break ;
    case 19: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_name COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1062)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1063)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1064)) ;
    } break ;
    case 20: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_namePlural COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1065)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1066)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1067)) ;
    } break ;
    case 21: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_namespace COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1068)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1069)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1070)) ;
    } break ;
    case 22: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_noteType COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1071)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1072)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1073)) ;
    } break ;
    case 23: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_nsPrefix COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1074)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1075)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1076)) ;
    } break ;
    case 24: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_qualifiedName COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1077)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1078)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1079)) ;
    } break ;
    case 25: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_recommendedPackage COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1080)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1081)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1082)) ;
    } break ;
    case 26: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_ref COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1083)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1084)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1085)) ;
    } break ;
    case 27: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_roleElement COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1086)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1087)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1088)) ;
    } break ;
    case 28: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_roleWrapperElement COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1089)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1090)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1091)) ;
    } break ;
    case 29: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_schemaLocation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1092)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1093)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1094)) ;
    } break ;
    case 30: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_sequenceOffset COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1095)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1096)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1097)) ;
    } break ;
    case 31: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_source COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1098)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1099)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1100)) ;
    } break ;
    case 32: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_Splitkey COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1101)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1102)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1103)) ;
    } break ;
    case 33: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_Status COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1104)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1105)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1106)) ;
    } break ;
    case 34: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_StatusRevisionBegin COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1107)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1108)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1109)) ;
    } break ;
    case 35: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_targetNamespace COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1110)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1111)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1112)) ;
    } break ;
    case 36: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_type COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1113)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1114)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1115)) ;
    } break ;
    case 37: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_typeElement COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1116)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1117)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1118)) ;
    } break ;
    case 38: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_typeWrapperElement COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1119)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1120)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1121)) ;
    } break ;
    case 39: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_use COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1122)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1123)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1124)) ;
    } break ;
    case 40: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_value COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1125)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1126)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1127)) ;
    } break ;
    case 41: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_version COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1128)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1129)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1130)) ;
    } break ;
    case 42: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlns_3A_AR COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1131)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1132)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1133)) ;
    } break ;
    case 43: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlns_3A_xsd COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1134)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1135)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1136)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->resetTemplateString () ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlDataList_2D_element::GALGAS_gtlDataList_2D_element (void) :
mProperty_data () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlDataList_2D_element::~ GALGAS_gtlDataList_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlDataList_2D_element::GALGAS_gtlDataList_2D_element (const GALGAS_gtlData & inOperand0) :
mProperty_data (inOperand0) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlDataList_2D_element GALGAS_gtlDataList_2D_element::constructor_new (const GALGAS_gtlData & inOperand0 
                                                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlDataList_2D_element result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_gtlDataList_2D_element (inOperand0) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_gtlDataList_2D_element::objectCompare (const GALGAS_gtlDataList_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_data.objectCompare (inOperand.mProperty_data) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_gtlDataList_2D_element::isValid (void) const {
  return mProperty_data.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlDataList_2D_element::drop (void) {
  mProperty_data.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlDataList_2D_element::description (C_String & ioString,
                                                 const int32_t inIndentation) const {
  ioString << "<struct @gtlDataList-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_data.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//@gtlDataList-element type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlDataList_2D_element ("gtlDataList-element",
                                               NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlDataList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlDataList_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlDataList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlDataList_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlDataList_2D_element GALGAS_gtlDataList_2D_element::extractObject (const GALGAS_object & inObject,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) {
  GALGAS_gtlDataList_2D_element result ;
  const GALGAS_gtlDataList_2D_element * p = (const GALGAS_gtlDataList_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlDataList_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlDataList-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlVarMap_2D_element::GALGAS_gtlVarMap_2D_element (void) :
mProperty_lkey (),
mProperty_value () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlVarMap_2D_element::~ GALGAS_gtlVarMap_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlVarMap_2D_element::GALGAS_gtlVarMap_2D_element (const GALGAS_lstring & inOperand0,
                                                          const GALGAS_gtlData & inOperand1) :
mProperty_lkey (inOperand0),
mProperty_value (inOperand1) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlVarMap_2D_element GALGAS_gtlVarMap_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                          const GALGAS_gtlData & inOperand1 
                                                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlVarMap_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_gtlVarMap_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_gtlVarMap_2D_element::objectCompare (const GALGAS_gtlVarMap_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_lkey.objectCompare (inOperand.mProperty_lkey) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_value.objectCompare (inOperand.mProperty_value) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_gtlVarMap_2D_element::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_value.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlVarMap_2D_element::drop (void) {
  mProperty_lkey.drop () ;
  mProperty_value.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlVarMap_2D_element::description (C_String & ioString,
                                               const int32_t inIndentation) const {
  ioString << "<struct @gtlVarMap-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_lkey.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_value.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//@gtlVarMap-element type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlVarMap_2D_element ("gtlVarMap-element",
                                             NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlVarMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlVarMap_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlVarMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlVarMap_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlVarMap_2D_element GALGAS_gtlVarMap_2D_element::extractObject (const GALGAS_object & inObject,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_gtlVarMap_2D_element result ;
  const GALGAS_gtlVarMap_2D_element * p = (const GALGAS_gtlVarMap_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlVarMap_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlVarMap-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExpressionMap_2D_element::GALGAS_gtlExpressionMap_2D_element (void) :
mProperty_lkey (),
mProperty_expression () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExpressionMap_2D_element::~ GALGAS_gtlExpressionMap_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExpressionMap_2D_element::GALGAS_gtlExpressionMap_2D_element (const GALGAS_lstring & inOperand0,
                                                                        const GALGAS_gtlExpression & inOperand1) :
mProperty_lkey (inOperand0),
mProperty_expression (inOperand1) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExpressionMap_2D_element GALGAS_gtlExpressionMap_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                        const GALGAS_gtlExpression & inOperand1 
                                                                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlExpressionMap_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_gtlExpressionMap_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_gtlExpressionMap_2D_element::objectCompare (const GALGAS_gtlExpressionMap_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_lkey.objectCompare (inOperand.mProperty_lkey) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_expression.objectCompare (inOperand.mProperty_expression) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_gtlExpressionMap_2D_element::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_expression.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlExpressionMap_2D_element::drop (void) {
  mProperty_lkey.drop () ;
  mProperty_expression.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlExpressionMap_2D_element::description (C_String & ioString,
                                                      const int32_t inIndentation) const {
  ioString << "<struct @gtlExpressionMap-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_lkey.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_expression.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//@gtlExpressionMap-element type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlExpressionMap_2D_element ("gtlExpressionMap-element",
                                                    NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlExpressionMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlExpressionMap_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlExpressionMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlExpressionMap_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExpressionMap_2D_element GALGAS_gtlExpressionMap_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_gtlExpressionMap_2D_element result ;
  const GALGAS_gtlExpressionMap_2D_element * p = (const GALGAS_gtlExpressionMap_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlExpressionMap_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlExpressionMap-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlTemplateMap_2D_element::GALGAS_gtlTemplateMap_2D_element (void) :
mProperty_lkey (),
mProperty_aTemplate () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlTemplateMap_2D_element::~ GALGAS_gtlTemplateMap_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlTemplateMap_2D_element::GALGAS_gtlTemplateMap_2D_element (const GALGAS_lstring & inOperand0,
                                                                    const GALGAS_gtlTemplate & inOperand1) :
mProperty_lkey (inOperand0),
mProperty_aTemplate (inOperand1) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlTemplateMap_2D_element GALGAS_gtlTemplateMap_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_gtlTemplateMap_2D_element (GALGAS_lstring::constructor_default (HERE),
                                           GALGAS_gtlTemplate::constructor_default (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlTemplateMap_2D_element GALGAS_gtlTemplateMap_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                    const GALGAS_gtlTemplate & inOperand1 
                                                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlTemplateMap_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_gtlTemplateMap_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_gtlTemplateMap_2D_element::objectCompare (const GALGAS_gtlTemplateMap_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_lkey.objectCompare (inOperand.mProperty_lkey) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_aTemplate.objectCompare (inOperand.mProperty_aTemplate) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_gtlTemplateMap_2D_element::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_aTemplate.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlTemplateMap_2D_element::drop (void) {
  mProperty_lkey.drop () ;
  mProperty_aTemplate.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlTemplateMap_2D_element::description (C_String & ioString,
                                                    const int32_t inIndentation) const {
  ioString << "<struct @gtlTemplateMap-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_lkey.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_aTemplate.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//@gtlTemplateMap-element type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlTemplateMap_2D_element ("gtlTemplateMap-element",
                                                  NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlTemplateMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlTemplateMap_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlTemplateMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlTemplateMap_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlTemplateMap_2D_element GALGAS_gtlTemplateMap_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                  C_Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_gtlTemplateMap_2D_element result ;
  const GALGAS_gtlTemplateMap_2D_element * p = (const GALGAS_gtlTemplateMap_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlTemplateMap_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlTemplateMap-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExpressionList_2D_element::GALGAS_gtlExpressionList_2D_element (void) :
mProperty_expression () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExpressionList_2D_element::~ GALGAS_gtlExpressionList_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExpressionList_2D_element::GALGAS_gtlExpressionList_2D_element (const GALGAS_gtlExpression & inOperand0) :
mProperty_expression (inOperand0) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExpressionList_2D_element GALGAS_gtlExpressionList_2D_element::constructor_new (const GALGAS_gtlExpression & inOperand0 
                                                                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlExpressionList_2D_element result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_gtlExpressionList_2D_element (inOperand0) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_gtlExpressionList_2D_element::objectCompare (const GALGAS_gtlExpressionList_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_expression.objectCompare (inOperand.mProperty_expression) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_gtlExpressionList_2D_element::isValid (void) const {
  return mProperty_expression.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlExpressionList_2D_element::drop (void) {
  mProperty_expression.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlExpressionList_2D_element::description (C_String & ioString,
                                                       const int32_t inIndentation) const {
  ioString << "<struct @gtlExpressionList-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_expression.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//@gtlExpressionList-element type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlExpressionList_2D_element ("gtlExpressionList-element",
                                                     NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlExpressionList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlExpressionList_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlExpressionList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlExpressionList_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlExpressionList_2D_element GALGAS_gtlExpressionList_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                        C_Compiler * inCompiler
                                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_gtlExpressionList_2D_element result ;
  const GALGAS_gtlExpressionList_2D_element * p = (const GALGAS_gtlExpressionList_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlExpressionList_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlExpressionList-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_list_2D_element::GALGAS_list_2D_element (void) :
mProperty_value () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_list_2D_element::~ GALGAS_list_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_list_2D_element::GALGAS_list_2D_element (const GALGAS_gtlData & inOperand0) :
mProperty_value (inOperand0) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_list_2D_element GALGAS_list_2D_element::constructor_new (const GALGAS_gtlData & inOperand0 
                                                                COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_list_2D_element result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_list_2D_element (inOperand0) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_list_2D_element::objectCompare (const GALGAS_list_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_value.objectCompare (inOperand.mProperty_value) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_list_2D_element::isValid (void) const {
  return mProperty_value.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_list_2D_element::drop (void) {
  mProperty_value.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_list_2D_element::description (C_String & ioString,
                                          const int32_t inIndentation) const {
  ioString << "<struct @list-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_value.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//@list-element type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_list_2D_element ("list-element",
                                        NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_list_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_list_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_list_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_list_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_list_2D_element GALGAS_list_2D_element::extractObject (const GALGAS_object & inObject,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) {
  GALGAS_list_2D_element result ;
  const GALGAS_list_2D_element * p = (const GALGAS_list_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_list_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("list-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstringset_2D_element::GALGAS_lstringset_2D_element (void) :
mProperty_lkey () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstringset_2D_element::~ GALGAS_lstringset_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstringset_2D_element::GALGAS_lstringset_2D_element (const GALGAS_lstring & inOperand0) :
mProperty_lkey (inOperand0) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstringset_2D_element GALGAS_lstringset_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_lstringset_2D_element (GALGAS_lstring::constructor_default (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstringset_2D_element GALGAS_lstringset_2D_element::constructor_new (const GALGAS_lstring & inOperand0 
                                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstringset_2D_element result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_lstringset_2D_element (inOperand0) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_lstringset_2D_element::objectCompare (const GALGAS_lstringset_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_lkey.objectCompare (inOperand.mProperty_lkey) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_lstringset_2D_element::isValid (void) const {
  return mProperty_lkey.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_lstringset_2D_element::drop (void) {
  mProperty_lkey.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_lstringset_2D_element::description (C_String & ioString,
                                                const int32_t inIndentation) const {
  ioString << "<struct @lstringset-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_lkey.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//@lstringset-element type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_lstringset_2D_element ("lstringset-element",
                                              NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_lstringset_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_lstringset_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_lstringset_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_lstringset_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstringset_2D_element GALGAS_lstringset_2D_element::extractObject (const GALGAS_object & inObject,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_lstringset_2D_element result ;
  const GALGAS_lstringset_2D_element * p = (const GALGAS_lstringset_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_lstringset_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("lstringset-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlArgumentList_2D_element::GALGAS_gtlArgumentList_2D_element (void) :
mProperty_typed (),
mProperty_type (),
mProperty_name () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlArgumentList_2D_element::~ GALGAS_gtlArgumentList_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlArgumentList_2D_element::GALGAS_gtlArgumentList_2D_element (const GALGAS_bool & inOperand0,
                                                                      const GALGAS_type & inOperand1,
                                                                      const GALGAS_lstring & inOperand2) :
mProperty_typed (inOperand0),
mProperty_type (inOperand1),
mProperty_name (inOperand2) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlArgumentList_2D_element GALGAS_gtlArgumentList_2D_element::constructor_new (const GALGAS_bool & inOperand0,
                                                                                      const GALGAS_type & inOperand1,
                                                                                      const GALGAS_lstring & inOperand2 
                                                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlArgumentList_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid ()) {
    result = GALGAS_gtlArgumentList_2D_element (inOperand0, inOperand1, inOperand2) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_gtlArgumentList_2D_element::objectCompare (const GALGAS_gtlArgumentList_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_typed.objectCompare (inOperand.mProperty_typed) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_type.objectCompare (inOperand.mProperty_type) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_name.objectCompare (inOperand.mProperty_name) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_gtlArgumentList_2D_element::isValid (void) const {
  return mProperty_typed.isValid () && mProperty_type.isValid () && mProperty_name.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlArgumentList_2D_element::drop (void) {
  mProperty_typed.drop () ;
  mProperty_type.drop () ;
  mProperty_name.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlArgumentList_2D_element::description (C_String & ioString,
                                                     const int32_t inIndentation) const {
  ioString << "<struct @gtlArgumentList-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_typed.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_type.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_name.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//@gtlArgumentList-element type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlArgumentList_2D_element ("gtlArgumentList-element",
                                                   NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlArgumentList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlArgumentList_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlArgumentList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlArgumentList_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlArgumentList_2D_element GALGAS_gtlArgumentList_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                    C_Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlArgumentList_2D_element result ;
  const GALGAS_gtlArgumentList_2D_element * p = (const GALGAS_gtlArgumentList_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlArgumentList_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlArgumentList-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlProcMap_2D_element::GALGAS_gtlProcMap_2D_element (void) :
mProperty_lkey (),
mProperty_procedure () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlProcMap_2D_element::~ GALGAS_gtlProcMap_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlProcMap_2D_element::GALGAS_gtlProcMap_2D_element (const GALGAS_lstring & inOperand0,
                                                            const GALGAS_gtlProcedure & inOperand1) :
mProperty_lkey (inOperand0),
mProperty_procedure (inOperand1) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlProcMap_2D_element GALGAS_gtlProcMap_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_gtlProcMap_2D_element (GALGAS_lstring::constructor_default (HERE),
                                       GALGAS_gtlProcedure::constructor_default (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlProcMap_2D_element GALGAS_gtlProcMap_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                            const GALGAS_gtlProcedure & inOperand1 
                                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlProcMap_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_gtlProcMap_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_gtlProcMap_2D_element::objectCompare (const GALGAS_gtlProcMap_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_lkey.objectCompare (inOperand.mProperty_lkey) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_procedure.objectCompare (inOperand.mProperty_procedure) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_gtlProcMap_2D_element::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_procedure.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlProcMap_2D_element::drop (void) {
  mProperty_lkey.drop () ;
  mProperty_procedure.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlProcMap_2D_element::description (C_String & ioString,
                                                const int32_t inIndentation) const {
  ioString << "<struct @gtlProcMap-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_lkey.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_procedure.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//@gtlProcMap-element type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlProcMap_2D_element ("gtlProcMap-element",
                                              NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlProcMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlProcMap_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlProcMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlProcMap_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlProcMap_2D_element GALGAS_gtlProcMap_2D_element::extractObject (const GALGAS_object & inObject,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_gtlProcMap_2D_element result ;
  const GALGAS_gtlProcMap_2D_element * p = (const GALGAS_gtlProcMap_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlProcMap_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlProcMap-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlFuncMap_2D_element::GALGAS_gtlFuncMap_2D_element (void) :
mProperty_lkey (),
mProperty_function () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlFuncMap_2D_element::~ GALGAS_gtlFuncMap_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlFuncMap_2D_element::GALGAS_gtlFuncMap_2D_element (const GALGAS_lstring & inOperand0,
                                                            const GALGAS_gtlFunction & inOperand1) :
mProperty_lkey (inOperand0),
mProperty_function (inOperand1) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlFuncMap_2D_element GALGAS_gtlFuncMap_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_gtlFuncMap_2D_element (GALGAS_lstring::constructor_default (HERE),
                                       GALGAS_gtlFunction::constructor_default (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlFuncMap_2D_element GALGAS_gtlFuncMap_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                            const GALGAS_gtlFunction & inOperand1 
                                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlFuncMap_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_gtlFuncMap_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_gtlFuncMap_2D_element::objectCompare (const GALGAS_gtlFuncMap_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_lkey.objectCompare (inOperand.mProperty_lkey) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_function.objectCompare (inOperand.mProperty_function) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_gtlFuncMap_2D_element::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_function.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlFuncMap_2D_element::drop (void) {
  mProperty_lkey.drop () ;
  mProperty_function.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlFuncMap_2D_element::description (C_String & ioString,
                                                const int32_t inIndentation) const {
  ioString << "<struct @gtlFuncMap-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_lkey.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_function.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//@gtlFuncMap-element type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlFuncMap_2D_element ("gtlFuncMap-element",
                                              NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlFuncMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlFuncMap_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlFuncMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlFuncMap_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlFuncMap_2D_element GALGAS_gtlFuncMap_2D_element::extractObject (const GALGAS_object & inObject,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_gtlFuncMap_2D_element result ;
  const GALGAS_gtlFuncMap_2D_element * p = (const GALGAS_gtlFuncMap_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlFuncMap_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlFuncMap-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlGetterMap_2D_element::GALGAS_gtlGetterMap_2D_element (void) :
mProperty_lkey (),
mProperty_theGetter () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlGetterMap_2D_element::~ GALGAS_gtlGetterMap_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlGetterMap_2D_element::GALGAS_gtlGetterMap_2D_element (const GALGAS_lstring & inOperand0,
                                                                const GALGAS_gtlGetter & inOperand1) :
mProperty_lkey (inOperand0),
mProperty_theGetter (inOperand1) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlGetterMap_2D_element GALGAS_gtlGetterMap_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                const GALGAS_gtlGetter & inOperand1 
                                                                                COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlGetterMap_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_gtlGetterMap_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_gtlGetterMap_2D_element::objectCompare (const GALGAS_gtlGetterMap_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_lkey.objectCompare (inOperand.mProperty_lkey) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_theGetter.objectCompare (inOperand.mProperty_theGetter) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_gtlGetterMap_2D_element::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_theGetter.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlGetterMap_2D_element::drop (void) {
  mProperty_lkey.drop () ;
  mProperty_theGetter.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlGetterMap_2D_element::description (C_String & ioString,
                                                  const int32_t inIndentation) const {
  ioString << "<struct @gtlGetterMap-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_lkey.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_theGetter.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//@gtlGetterMap-element type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlGetterMap_2D_element ("gtlGetterMap-element",
                                                NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlGetterMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlGetterMap_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlGetterMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlGetterMap_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlGetterMap_2D_element GALGAS_gtlGetterMap_2D_element::extractObject (const GALGAS_object & inObject,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_gtlGetterMap_2D_element result ;
  const GALGAS_gtlGetterMap_2D_element * p = (const GALGAS_gtlGetterMap_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlGetterMap_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlGetterMap-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlSetterMap_2D_element::GALGAS_gtlSetterMap_2D_element (void) :
mProperty_lkey (),
mProperty_theSetter () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlSetterMap_2D_element::~ GALGAS_gtlSetterMap_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlSetterMap_2D_element::GALGAS_gtlSetterMap_2D_element (const GALGAS_lstring & inOperand0,
                                                                const GALGAS_gtlSetter & inOperand1) :
mProperty_lkey (inOperand0),
mProperty_theSetter (inOperand1) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlSetterMap_2D_element GALGAS_gtlSetterMap_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                const GALGAS_gtlSetter & inOperand1 
                                                                                COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlSetterMap_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_gtlSetterMap_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_gtlSetterMap_2D_element::objectCompare (const GALGAS_gtlSetterMap_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_lkey.objectCompare (inOperand.mProperty_lkey) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_theSetter.objectCompare (inOperand.mProperty_theSetter) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_gtlSetterMap_2D_element::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_theSetter.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlSetterMap_2D_element::drop (void) {
  mProperty_lkey.drop () ;
  mProperty_theSetter.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlSetterMap_2D_element::description (C_String & ioString,
                                                  const int32_t inIndentation) const {
  ioString << "<struct @gtlSetterMap-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_lkey.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_theSetter.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//@gtlSetterMap-element type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlSetterMap_2D_element ("gtlSetterMap-element",
                                                NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlSetterMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlSetterMap_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlSetterMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlSetterMap_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlSetterMap_2D_element GALGAS_gtlSetterMap_2D_element::extractObject (const GALGAS_object & inObject,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_gtlSetterMap_2D_element result ;
  const GALGAS_gtlSetterMap_2D_element * p = (const GALGAS_gtlSetterMap_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlSetterMap_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlSetterMap-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlThenElsifStatementList_2D_element::GALGAS_gtlThenElsifStatementList_2D_element (void) :
mProperty_condition (),
mProperty_instructionList () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlThenElsifStatementList_2D_element::~ GALGAS_gtlThenElsifStatementList_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlThenElsifStatementList_2D_element::GALGAS_gtlThenElsifStatementList_2D_element (const GALGAS_gtlExpression & inOperand0,
                                                                                          const GALGAS_gtlInstructionList & inOperand1) :
mProperty_condition (inOperand0),
mProperty_instructionList (inOperand1) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlThenElsifStatementList_2D_element GALGAS_gtlThenElsifStatementList_2D_element::constructor_new (const GALGAS_gtlExpression & inOperand0,
                                                                                                          const GALGAS_gtlInstructionList & inOperand1 
                                                                                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlThenElsifStatementList_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_gtlThenElsifStatementList_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_gtlThenElsifStatementList_2D_element::objectCompare (const GALGAS_gtlThenElsifStatementList_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_condition.objectCompare (inOperand.mProperty_condition) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_instructionList.objectCompare (inOperand.mProperty_instructionList) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_gtlThenElsifStatementList_2D_element::isValid (void) const {
  return mProperty_condition.isValid () && mProperty_instructionList.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlThenElsifStatementList_2D_element::drop (void) {
  mProperty_condition.drop () ;
  mProperty_instructionList.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlThenElsifStatementList_2D_element::description (C_String & ioString,
                                                               const int32_t inIndentation) const {
  ioString << "<struct @gtlThenElsifStatementList-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_condition.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_instructionList.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//@gtlThenElsifStatementList-element type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlThenElsifStatementList_2D_element ("gtlThenElsifStatementList-element",
                                                             NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlThenElsifStatementList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlThenElsifStatementList_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlThenElsifStatementList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlThenElsifStatementList_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlThenElsifStatementList_2D_element GALGAS_gtlThenElsifStatementList_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                                        C_Compiler * inCompiler
                                                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_gtlThenElsifStatementList_2D_element result ;
  const GALGAS_gtlThenElsifStatementList_2D_element * p = (const GALGAS_gtlThenElsifStatementList_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlThenElsifStatementList_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlThenElsifStatementList-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sortingKeyList_2D_element::GALGAS_sortingKeyList_2D_element (void) :
mProperty_key (),
mProperty_order () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sortingKeyList_2D_element::~ GALGAS_sortingKeyList_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sortingKeyList_2D_element::GALGAS_sortingKeyList_2D_element (const GALGAS_lstring & inOperand0,
                                                                    const GALGAS_lsint & inOperand1) :
mProperty_key (inOperand0),
mProperty_order (inOperand1) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sortingKeyList_2D_element GALGAS_sortingKeyList_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_sortingKeyList_2D_element (GALGAS_lstring::constructor_default (HERE),
                                           GALGAS_lsint::constructor_default (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sortingKeyList_2D_element GALGAS_sortingKeyList_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                    const GALGAS_lsint & inOperand1 
                                                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_sortingKeyList_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_sortingKeyList_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_sortingKeyList_2D_element::objectCompare (const GALGAS_sortingKeyList_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_key.objectCompare (inOperand.mProperty_key) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_order.objectCompare (inOperand.mProperty_order) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_sortingKeyList_2D_element::isValid (void) const {
  return mProperty_key.isValid () && mProperty_order.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sortingKeyList_2D_element::drop (void) {
  mProperty_key.drop () ;
  mProperty_order.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_sortingKeyList_2D_element::description (C_String & ioString,
                                                    const int32_t inIndentation) const {
  ioString << "<struct @sortingKeyList-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_key.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_order.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//@sortingKeyList-element type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_sortingKeyList_2D_element ("sortingKeyList-element",
                                                  NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_sortingKeyList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_sortingKeyList_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_sortingKeyList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_sortingKeyList_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_sortingKeyList_2D_element GALGAS_sortingKeyList_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                  C_Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_sortingKeyList_2D_element result ;
  const GALGAS_sortingKeyList_2D_element * p = (const GALGAS_sortingKeyList_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_sortingKeyList_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("sortingKeyList-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_numberList_2D_element::GALGAS_numberList_2D_element (void) :
mProperty_location (),
mProperty_value () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_numberList_2D_element::~ GALGAS_numberList_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_numberList_2D_element::GALGAS_numberList_2D_element (const GALGAS_location & inOperand0,
                                                            const GALGAS_object_5F_t & inOperand1) :
mProperty_location (inOperand0),
mProperty_value (inOperand1) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_numberList_2D_element GALGAS_numberList_2D_element::constructor_new (const GALGAS_location & inOperand0,
                                                                            const GALGAS_object_5F_t & inOperand1 
                                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_numberList_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_numberList_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_numberList_2D_element::objectCompare (const GALGAS_numberList_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_location.objectCompare (inOperand.mProperty_location) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_value.objectCompare (inOperand.mProperty_value) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_numberList_2D_element::isValid (void) const {
  return mProperty_location.isValid () && mProperty_value.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_numberList_2D_element::drop (void) {
  mProperty_location.drop () ;
  mProperty_value.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_numberList_2D_element::description (C_String & ioString,
                                                const int32_t inIndentation) const {
  ioString << "<struct @numberList-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_location.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_value.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//@numberList-element type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_numberList_2D_element ("numberList-element",
                                              NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_numberList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_numberList_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_numberList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_numberList_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_numberList_2D_element GALGAS_numberList_2D_element::extractObject (const GALGAS_object & inObject,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_numberList_2D_element result ;
  const GALGAS_numberList_2D_element * p = (const GALGAS_numberList_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_numberList_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("numberList-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_implementationObjectMap_2D_element::GALGAS_implementationObjectMap_2D_element (void) :
mProperty_lkey (),
mProperty_type () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_implementationObjectMap_2D_element::~ GALGAS_implementationObjectMap_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_implementationObjectMap_2D_element::GALGAS_implementationObjectMap_2D_element (const GALGAS_lstring & inOperand0,
                                                                                      const GALGAS_impType & inOperand1) :
mProperty_lkey (inOperand0),
mProperty_type (inOperand1) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_implementationObjectMap_2D_element GALGAS_implementationObjectMap_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                                      const GALGAS_impType & inOperand1 
                                                                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_implementationObjectMap_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_implementationObjectMap_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_implementationObjectMap_2D_element::objectCompare (const GALGAS_implementationObjectMap_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_lkey.objectCompare (inOperand.mProperty_lkey) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_type.objectCompare (inOperand.mProperty_type) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_implementationObjectMap_2D_element::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_type.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_implementationObjectMap_2D_element::drop (void) {
  mProperty_lkey.drop () ;
  mProperty_type.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_implementationObjectMap_2D_element::description (C_String & ioString,
                                                             const int32_t inIndentation) const {
  ioString << "<struct @implementationObjectMap-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_lkey.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_type.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//@implementationObjectMap-element type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_implementationObjectMap_2D_element ("implementationObjectMap-element",
                                                           NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_implementationObjectMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_implementationObjectMap_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_implementationObjectMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_implementationObjectMap_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_implementationObjectMap_2D_element GALGAS_implementationObjectMap_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                                    C_Compiler * inCompiler
                                                                                                    COMMA_LOCATION_ARGS) {
  GALGAS_implementationObjectMap_2D_element result ;
  const GALGAS_implementationObjectMap_2D_element * p = (const GALGAS_implementationObjectMap_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_implementationObjectMap_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("implementationObjectMap-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_enumValues_2D_element::GALGAS_enumValues_2D_element (void) :
mProperty_lkey (),
mProperty_subAttributes () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_enumValues_2D_element::~ GALGAS_enumValues_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_enumValues_2D_element::GALGAS_enumValues_2D_element (const GALGAS_lstring & inOperand0,
                                                            const GALGAS_implementationObjectMap & inOperand1) :
mProperty_lkey (inOperand0),
mProperty_subAttributes (inOperand1) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_enumValues_2D_element GALGAS_enumValues_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_enumValues_2D_element (GALGAS_lstring::constructor_default (HERE),
                                       GALGAS_implementationObjectMap::constructor_emptyMap (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_enumValues_2D_element GALGAS_enumValues_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                            const GALGAS_implementationObjectMap & inOperand1 
                                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_enumValues_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_enumValues_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_enumValues_2D_element::objectCompare (const GALGAS_enumValues_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_lkey.objectCompare (inOperand.mProperty_lkey) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_subAttributes.objectCompare (inOperand.mProperty_subAttributes) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_enumValues_2D_element::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_subAttributes.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_enumValues_2D_element::drop (void) {
  mProperty_lkey.drop () ;
  mProperty_subAttributes.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_enumValues_2D_element::description (C_String & ioString,
                                                const int32_t inIndentation) const {
  ioString << "<struct @enumValues-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_lkey.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_subAttributes.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//@enumValues-element type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_enumValues_2D_element ("enumValues-element",
                                              NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_enumValues_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_enumValues_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_enumValues_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_enumValues_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_enumValues_2D_element GALGAS_enumValues_2D_element::extractObject (const GALGAS_object & inObject,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_enumValues_2D_element result ;
  const GALGAS_enumValues_2D_element * p = (const GALGAS_enumValues_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_enumValues_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("enumValues-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_implementationMap_2D_element::GALGAS_implementationMap_2D_element (void) :
mProperty_lkey (),
mProperty_obj () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_implementationMap_2D_element::~ GALGAS_implementationMap_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_implementationMap_2D_element::GALGAS_implementationMap_2D_element (const GALGAS_lstring & inOperand0,
                                                                          const GALGAS_implementationObject & inOperand1) :
mProperty_lkey (inOperand0),
mProperty_obj (inOperand1) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_implementationMap_2D_element GALGAS_implementationMap_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_implementationMap_2D_element (GALGAS_lstring::constructor_default (HERE),
                                              GALGAS_implementationObject::constructor_default (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_implementationMap_2D_element GALGAS_implementationMap_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                          const GALGAS_implementationObject & inOperand1 
                                                                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_implementationMap_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_implementationMap_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_implementationMap_2D_element::objectCompare (const GALGAS_implementationMap_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_lkey.objectCompare (inOperand.mProperty_lkey) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_obj.objectCompare (inOperand.mProperty_obj) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_implementationMap_2D_element::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_obj.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_implementationMap_2D_element::drop (void) {
  mProperty_lkey.drop () ;
  mProperty_obj.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_implementationMap_2D_element::description (C_String & ioString,
                                                       const int32_t inIndentation) const {
  ioString << "<struct @implementationMap-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_lkey.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_obj.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//@implementationMap-element type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_implementationMap_2D_element ("implementationMap-element",
                                                     NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_implementationMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_implementationMap_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_implementationMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_implementationMap_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_implementationMap_2D_element GALGAS_implementationMap_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                        C_Compiler * inCompiler
                                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_implementationMap_2D_element result ;
  const GALGAS_implementationMap_2D_element * p = (const GALGAS_implementationMap_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_implementationMap_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("implementationMap-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_identifierMap_2D_element::GALGAS_identifierMap_2D_element (void) :
mProperty_lkey (),
mProperty_value () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_identifierMap_2D_element::~ GALGAS_identifierMap_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_identifierMap_2D_element::GALGAS_identifierMap_2D_element (const GALGAS_lstring & inOperand0,
                                                                  const GALGAS_object_5F_t & inOperand1) :
mProperty_lkey (inOperand0),
mProperty_value (inOperand1) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_identifierMap_2D_element GALGAS_identifierMap_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                  const GALGAS_object_5F_t & inOperand1 
                                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_identifierMap_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_identifierMap_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_identifierMap_2D_element::objectCompare (const GALGAS_identifierMap_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_lkey.objectCompare (inOperand.mProperty_lkey) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_value.objectCompare (inOperand.mProperty_value) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_identifierMap_2D_element::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_value.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_identifierMap_2D_element::drop (void) {
  mProperty_lkey.drop () ;
  mProperty_value.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_identifierMap_2D_element::description (C_String & ioString,
                                                   const int32_t inIndentation) const {
  ioString << "<struct @identifierMap-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_lkey.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_value.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//@identifierMap-element type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_identifierMap_2D_element ("identifierMap-element",
                                                 NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_identifierMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_identifierMap_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_identifierMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_identifierMap_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_identifierMap_2D_element GALGAS_identifierMap_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_identifierMap_2D_element result ;
  const GALGAS_identifierMap_2D_element * p = (const GALGAS_identifierMap_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_identifierMap_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("identifierMap-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_identifierList_2D_element::GALGAS_identifierList_2D_element (void) :
mProperty_item () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_identifierList_2D_element::~ GALGAS_identifierList_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_identifierList_2D_element::GALGAS_identifierList_2D_element (const GALGAS_object_5F_t & inOperand0) :
mProperty_item (inOperand0) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_identifierList_2D_element GALGAS_identifierList_2D_element::constructor_new (const GALGAS_object_5F_t & inOperand0 
                                                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_identifierList_2D_element result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_identifierList_2D_element (inOperand0) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_identifierList_2D_element::objectCompare (const GALGAS_identifierList_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_item.objectCompare (inOperand.mProperty_item) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_identifierList_2D_element::isValid (void) const {
  return mProperty_item.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_identifierList_2D_element::drop (void) {
  mProperty_item.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_identifierList_2D_element::description (C_String & ioString,
                                                    const int32_t inIndentation) const {
  ioString << "<struct @identifierList-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_item.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//@identifierList-element type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_identifierList_2D_element ("identifierList-element",
                                                  NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_identifierList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_identifierList_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_identifierList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_identifierList_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_identifierList_2D_element GALGAS_identifierList_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                  C_Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_identifierList_2D_element result ;
  const GALGAS_identifierList_2D_element * p = (const GALGAS_identifierList_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_identifierList_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("identifierList-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringMap_2D_element::GALGAS_stringMap_2D_element (void) :
mProperty_lkey (),
mProperty_value () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringMap_2D_element::~ GALGAS_stringMap_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringMap_2D_element::GALGAS_stringMap_2D_element (const GALGAS_lstring & inOperand0,
                                                          const GALGAS_string & inOperand1) :
mProperty_lkey (inOperand0),
mProperty_value (inOperand1) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringMap_2D_element GALGAS_stringMap_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_stringMap_2D_element (GALGAS_lstring::constructor_default (HERE),
                                      GALGAS_string::constructor_default (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringMap_2D_element GALGAS_stringMap_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                          const GALGAS_string & inOperand1 
                                                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_stringMap_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_stringMap_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_stringMap_2D_element::objectCompare (const GALGAS_stringMap_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_lkey.objectCompare (inOperand.mProperty_lkey) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_value.objectCompare (inOperand.mProperty_value) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_stringMap_2D_element::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_value.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_stringMap_2D_element::drop (void) {
  mProperty_lkey.drop () ;
  mProperty_value.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_stringMap_2D_element::description (C_String & ioString,
                                               const int32_t inIndentation) const {
  ioString << "<struct @stringMap-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_lkey.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_value.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//@stringMap-element type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_stringMap_2D_element ("stringMap-element",
                                             NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_stringMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_stringMap_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_stringMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_stringMap_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringMap_2D_element GALGAS_stringMap_2D_element::extractObject (const GALGAS_object & inObject,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_stringMap_2D_element result ;
  const GALGAS_stringMap_2D_element * p = (const GALGAS_stringMap_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_stringMap_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("stringMap-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstringMap_2D_element::GALGAS_lstringMap_2D_element (void) :
mProperty_lkey (),
mProperty_value () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstringMap_2D_element::~ GALGAS_lstringMap_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstringMap_2D_element::GALGAS_lstringMap_2D_element (const GALGAS_lstring & inOperand0,
                                                            const GALGAS_lstring & inOperand1) :
mProperty_lkey (inOperand0),
mProperty_value (inOperand1) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstringMap_2D_element GALGAS_lstringMap_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_lstringMap_2D_element (GALGAS_lstring::constructor_default (HERE),
                                       GALGAS_lstring::constructor_default (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstringMap_2D_element GALGAS_lstringMap_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                            const GALGAS_lstring & inOperand1 
                                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstringMap_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_lstringMap_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_lstringMap_2D_element::objectCompare (const GALGAS_lstringMap_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_lkey.objectCompare (inOperand.mProperty_lkey) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_value.objectCompare (inOperand.mProperty_value) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_lstringMap_2D_element::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_value.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_lstringMap_2D_element::drop (void) {
  mProperty_lkey.drop () ;
  mProperty_value.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_lstringMap_2D_element::description (C_String & ioString,
                                                const int32_t inIndentation) const {
  ioString << "<struct @lstringMap-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_lkey.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_value.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//@lstringMap-element type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_lstringMap_2D_element ("lstringMap-element",
                                              NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_lstringMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_lstringMap_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_lstringMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_lstringMap_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstringMap_2D_element GALGAS_lstringMap_2D_element::extractObject (const GALGAS_object & inObject,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_lstringMap_2D_element result ;
  const GALGAS_lstringMap_2D_element * p = (const GALGAS_lstringMap_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_lstringMap_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("lstringMap-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_prefix_5F_map_2D_element::GALGAS_prefix_5F_map_2D_element (void) :
mProperty_lkey (),
mProperty_prefix (),
mProperty_tag_5F_to_5F_rep () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_prefix_5F_map_2D_element::~ GALGAS_prefix_5F_map_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_prefix_5F_map_2D_element::GALGAS_prefix_5F_map_2D_element (const GALGAS_lstring & inOperand0,
                                                                  const GALGAS_string & inOperand1,
                                                                  const GALGAS_string & inOperand2) :
mProperty_lkey (inOperand0),
mProperty_prefix (inOperand1),
mProperty_tag_5F_to_5F_rep (inOperand2) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_prefix_5F_map_2D_element GALGAS_prefix_5F_map_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_prefix_5F_map_2D_element (GALGAS_lstring::constructor_default (HERE),
                                          GALGAS_string::constructor_default (HERE),
                                          GALGAS_string::constructor_default (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_prefix_5F_map_2D_element GALGAS_prefix_5F_map_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                  const GALGAS_string & inOperand1,
                                                                                  const GALGAS_string & inOperand2 
                                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_prefix_5F_map_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid ()) {
    result = GALGAS_prefix_5F_map_2D_element (inOperand0, inOperand1, inOperand2) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_prefix_5F_map_2D_element::objectCompare (const GALGAS_prefix_5F_map_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_lkey.objectCompare (inOperand.mProperty_lkey) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_prefix.objectCompare (inOperand.mProperty_prefix) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_tag_5F_to_5F_rep.objectCompare (inOperand.mProperty_tag_5F_to_5F_rep) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_prefix_5F_map_2D_element::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_prefix.isValid () && mProperty_tag_5F_to_5F_rep.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_prefix_5F_map_2D_element::drop (void) {
  mProperty_lkey.drop () ;
  mProperty_prefix.drop () ;
  mProperty_tag_5F_to_5F_rep.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_prefix_5F_map_2D_element::description (C_String & ioString,
                                                   const int32_t inIndentation) const {
  ioString << "<struct @prefix_map-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_lkey.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_prefix.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_tag_5F_to_5F_rep.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//@prefix_map-element type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_prefix_5F_map_2D_element ("prefix_map-element",
                                                 NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_prefix_5F_map_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_prefix_5F_map_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_prefix_5F_map_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_prefix_5F_map_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_prefix_5F_map_2D_element GALGAS_prefix_5F_map_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_prefix_5F_map_2D_element result ;
  const GALGAS_prefix_5F_map_2D_element * p = (const GALGAS_prefix_5F_map_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_prefix_5F_map_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("prefix_map-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringset_5F_map_2D_element::GALGAS_stringset_5F_map_2D_element (void) :
mProperty_lkey (),
mProperty_ids () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringset_5F_map_2D_element::~ GALGAS_stringset_5F_map_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringset_5F_map_2D_element::GALGAS_stringset_5F_map_2D_element (const GALGAS_lstring & inOperand0,
                                                                        const GALGAS_stringset & inOperand1) :
mProperty_lkey (inOperand0),
mProperty_ids (inOperand1) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringset_5F_map_2D_element GALGAS_stringset_5F_map_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_stringset_5F_map_2D_element (GALGAS_lstring::constructor_default (HERE),
                                             GALGAS_stringset::constructor_emptySet (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringset_5F_map_2D_element GALGAS_stringset_5F_map_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                        const GALGAS_stringset & inOperand1 
                                                                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_stringset_5F_map_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_stringset_5F_map_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_stringset_5F_map_2D_element::objectCompare (const GALGAS_stringset_5F_map_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_lkey.objectCompare (inOperand.mProperty_lkey) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_ids.objectCompare (inOperand.mProperty_ids) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_stringset_5F_map_2D_element::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_ids.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_stringset_5F_map_2D_element::drop (void) {
  mProperty_lkey.drop () ;
  mProperty_ids.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_stringset_5F_map_2D_element::description (C_String & ioString,
                                                      const int32_t inIndentation) const {
  ioString << "<struct @stringset_map-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_lkey.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_ids.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//@stringset_map-element type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_stringset_5F_map_2D_element ("stringset_map-element",
                                                    NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_stringset_5F_map_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_stringset_5F_map_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_stringset_5F_map_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_stringset_5F_map_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringset_5F_map_2D_element GALGAS_stringset_5F_map_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_stringset_5F_map_2D_element result ;
  const GALGAS_stringset_5F_map_2D_element * p = (const GALGAS_stringset_5F_map_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_stringset_5F_map_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("stringset_map-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_ident_5F_list_2D_element::GALGAS_ident_5F_list_2D_element (void) :
mProperty_obj_5F_name () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_ident_5F_list_2D_element::~ GALGAS_ident_5F_list_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_ident_5F_list_2D_element::GALGAS_ident_5F_list_2D_element (const GALGAS_lstring & inOperand0) :
mProperty_obj_5F_name (inOperand0) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_ident_5F_list_2D_element GALGAS_ident_5F_list_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_ident_5F_list_2D_element (GALGAS_lstring::constructor_default (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_ident_5F_list_2D_element GALGAS_ident_5F_list_2D_element::constructor_new (const GALGAS_lstring & inOperand0 
                                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_ident_5F_list_2D_element result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_ident_5F_list_2D_element (inOperand0) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_ident_5F_list_2D_element::objectCompare (const GALGAS_ident_5F_list_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_obj_5F_name.objectCompare (inOperand.mProperty_obj_5F_name) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_ident_5F_list_2D_element::isValid (void) const {
  return mProperty_obj_5F_name.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_ident_5F_list_2D_element::drop (void) {
  mProperty_obj_5F_name.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_ident_5F_list_2D_element::description (C_String & ioString,
                                                   const int32_t inIndentation) const {
  ioString << "<struct @ident_list-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_obj_5F_name.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//@ident_list-element type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_ident_5F_list_2D_element ("ident_list-element",
                                                 NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_ident_5F_list_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_ident_5F_list_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_ident_5F_list_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_ident_5F_list_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_ident_5F_list_2D_element GALGAS_ident_5F_list_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_ident_5F_list_2D_element result ;
  const GALGAS_ident_5F_list_2D_element * p = (const GALGAS_ident_5F_list_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_ident_5F_list_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("ident_list-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_ident_5F_list_5F_map_2D_element::GALGAS_ident_5F_list_5F_map_2D_element (void) :
mProperty_lkey (),
mProperty_objs () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_ident_5F_list_5F_map_2D_element::~ GALGAS_ident_5F_list_5F_map_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_ident_5F_list_5F_map_2D_element::GALGAS_ident_5F_list_5F_map_2D_element (const GALGAS_lstring & inOperand0,
                                                                                const GALGAS_ident_5F_list & inOperand1) :
mProperty_lkey (inOperand0),
mProperty_objs (inOperand1) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_ident_5F_list_5F_map_2D_element GALGAS_ident_5F_list_5F_map_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_ident_5F_list_5F_map_2D_element (GALGAS_lstring::constructor_default (HERE),
                                                 GALGAS_ident_5F_list::constructor_emptyList (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_ident_5F_list_5F_map_2D_element GALGAS_ident_5F_list_5F_map_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                                const GALGAS_ident_5F_list & inOperand1 
                                                                                                COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_ident_5F_list_5F_map_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_ident_5F_list_5F_map_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_ident_5F_list_5F_map_2D_element::objectCompare (const GALGAS_ident_5F_list_5F_map_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_lkey.objectCompare (inOperand.mProperty_lkey) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_objs.objectCompare (inOperand.mProperty_objs) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_ident_5F_list_5F_map_2D_element::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_objs.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_ident_5F_list_5F_map_2D_element::drop (void) {
  mProperty_lkey.drop () ;
  mProperty_objs.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_ident_5F_list_5F_map_2D_element::description (C_String & ioString,
                                                          const int32_t inIndentation) const {
  ioString << "<struct @ident_list_map-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_lkey.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_objs.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//@ident_list_map-element type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_ident_5F_list_5F_map_2D_element ("ident_list_map-element",
                                                        NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_ident_5F_list_5F_map_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_ident_5F_list_5F_map_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_ident_5F_list_5F_map_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_ident_5F_list_5F_map_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_ident_5F_list_5F_map_2D_element GALGAS_ident_5F_list_5F_map_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                              C_Compiler * inCompiler
                                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_ident_5F_list_5F_map_2D_element result ;
  const GALGAS_ident_5F_list_5F_map_2D_element * p = (const GALGAS_ident_5F_list_5F_map_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_ident_5F_list_5F_map_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("ident_list_map-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectKindMap_2D_element::GALGAS_objectKindMap_2D_element (void) :
mProperty_lkey (),
mProperty_attributes () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectKindMap_2D_element::~ GALGAS_objectKindMap_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectKindMap_2D_element::GALGAS_objectKindMap_2D_element (const GALGAS_lstring & inOperand0,
                                                                  const GALGAS_objectAttributes & inOperand1) :
mProperty_lkey (inOperand0),
mProperty_attributes (inOperand1) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectKindMap_2D_element GALGAS_objectKindMap_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_objectKindMap_2D_element (GALGAS_lstring::constructor_default (HERE),
                                          GALGAS_objectAttributes::constructor_default (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectKindMap_2D_element GALGAS_objectKindMap_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                  const GALGAS_objectAttributes & inOperand1 
                                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_objectKindMap_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_objectKindMap_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_objectKindMap_2D_element::objectCompare (const GALGAS_objectKindMap_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_lkey.objectCompare (inOperand.mProperty_lkey) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_attributes.objectCompare (inOperand.mProperty_attributes) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_objectKindMap_2D_element::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_attributes.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_objectKindMap_2D_element::drop (void) {
  mProperty_lkey.drop () ;
  mProperty_attributes.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_objectKindMap_2D_element::description (C_String & ioString,
                                                   const int32_t inIndentation) const {
  ioString << "<struct @objectKindMap-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_lkey.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_attributes.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//@objectKindMap-element type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_objectKindMap_2D_element ("objectKindMap-element",
                                                 NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_objectKindMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_objectKindMap_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_objectKindMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_objectKindMap_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectKindMap_2D_element GALGAS_objectKindMap_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_objectKindMap_2D_element result ;
  const GALGAS_objectKindMap_2D_element * p = (const GALGAS_objectKindMap_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_objectKindMap_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("objectKindMap-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectsMap_2D_element::GALGAS_objectsMap_2D_element (void) :
mProperty_lkey (),
mProperty_objectsOfKind () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectsMap_2D_element::~ GALGAS_objectsMap_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectsMap_2D_element::GALGAS_objectsMap_2D_element (const GALGAS_lstring & inOperand0,
                                                            const GALGAS_objectKind & inOperand1) :
mProperty_lkey (inOperand0),
mProperty_objectsOfKind (inOperand1) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectsMap_2D_element GALGAS_objectsMap_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_objectsMap_2D_element (GALGAS_lstring::constructor_default (HERE),
                                       GALGAS_objectKind::constructor_default (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectsMap_2D_element GALGAS_objectsMap_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                            const GALGAS_objectKind & inOperand1 
                                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_objectsMap_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_objectsMap_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_objectsMap_2D_element::objectCompare (const GALGAS_objectsMap_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_lkey.objectCompare (inOperand.mProperty_lkey) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_objectsOfKind.objectCompare (inOperand.mProperty_objectsOfKind) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_objectsMap_2D_element::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_objectsOfKind.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_objectsMap_2D_element::drop (void) {
  mProperty_lkey.drop () ;
  mProperty_objectsOfKind.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_objectsMap_2D_element::description (C_String & ioString,
                                                const int32_t inIndentation) const {
  ioString << "<struct @objectsMap-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_lkey.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_objectsOfKind.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//@objectsMap-element type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_objectsMap_2D_element ("objectsMap-element",
                                              NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_objectsMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_objectsMap_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_objectsMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_objectsMap_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_objectsMap_2D_element GALGAS_objectsMap_2D_element::extractObject (const GALGAS_object & inObject,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_objectsMap_2D_element result ;
  const GALGAS_objectsMap_2D_element * p = (const GALGAS_objectsMap_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_objectsMap_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("objectsMap-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlAttributeMap_2D_element::GALGAS_arxmlAttributeMap_2D_element (void) :
mProperty_lkey (),
mProperty_value () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlAttributeMap_2D_element::~ GALGAS_arxmlAttributeMap_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlAttributeMap_2D_element::GALGAS_arxmlAttributeMap_2D_element (const GALGAS_lstring & inOperand0,
                                                                          const GALGAS_lstring & inOperand1) :
mProperty_lkey (inOperand0),
mProperty_value (inOperand1) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlAttributeMap_2D_element GALGAS_arxmlAttributeMap_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_arxmlAttributeMap_2D_element (GALGAS_lstring::constructor_default (HERE),
                                              GALGAS_lstring::constructor_default (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlAttributeMap_2D_element GALGAS_arxmlAttributeMap_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                          const GALGAS_lstring & inOperand1 
                                                                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_arxmlAttributeMap_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_arxmlAttributeMap_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_arxmlAttributeMap_2D_element::objectCompare (const GALGAS_arxmlAttributeMap_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_lkey.objectCompare (inOperand.mProperty_lkey) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_value.objectCompare (inOperand.mProperty_value) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_arxmlAttributeMap_2D_element::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_value.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlAttributeMap_2D_element::drop (void) {
  mProperty_lkey.drop () ;
  mProperty_value.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlAttributeMap_2D_element::description (C_String & ioString,
                                                       const int32_t inIndentation) const {
  ioString << "<struct @arxmlAttributeMap-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_lkey.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_value.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//@arxmlAttributeMap-element type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_arxmlAttributeMap_2D_element ("arxmlAttributeMap-element",
                                                     NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_arxmlAttributeMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_arxmlAttributeMap_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_arxmlAttributeMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_arxmlAttributeMap_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlAttributeMap_2D_element GALGAS_arxmlAttributeMap_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                        C_Compiler * inCompiler
                                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_arxmlAttributeMap_2D_element result ;
  const GALGAS_arxmlAttributeMap_2D_element * p = (const GALGAS_arxmlAttributeMap_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_arxmlAttributeMap_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("arxmlAttributeMap-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementList_2D_element::GALGAS_arxmlElementList_2D_element (void) :
mProperty_node () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementList_2D_element::~ GALGAS_arxmlElementList_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementList_2D_element::GALGAS_arxmlElementList_2D_element (const GALGAS_arxmlElementNode & inOperand0) :
mProperty_node (inOperand0) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementList_2D_element GALGAS_arxmlElementList_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_arxmlElementList_2D_element (GALGAS_arxmlElementNode::constructor_default (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementList_2D_element GALGAS_arxmlElementList_2D_element::constructor_new (const GALGAS_arxmlElementNode & inOperand0 
                                                                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_arxmlElementList_2D_element result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_arxmlElementList_2D_element (inOperand0) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_arxmlElementList_2D_element::objectCompare (const GALGAS_arxmlElementList_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_node.objectCompare (inOperand.mProperty_node) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_arxmlElementList_2D_element::isValid (void) const {
  return mProperty_node.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlElementList_2D_element::drop (void) {
  mProperty_node.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlElementList_2D_element::description (C_String & ioString,
                                                      const int32_t inIndentation) const {
  ioString << "<struct @arxmlElementList-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_node.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//@arxmlElementList-element type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_arxmlElementList_2D_element ("arxmlElementList-element",
                                                    NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_arxmlElementList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_arxmlElementList_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_arxmlElementList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_arxmlElementList_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementList_2D_element GALGAS_arxmlElementList_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_arxmlElementList_2D_element result ;
  const GALGAS_arxmlElementList_2D_element * p = (const GALGAS_arxmlElementList_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_arxmlElementList_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("arxmlElementList-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementValueMap_2D_element::GALGAS_arxmlElementValueMap_2D_element (void) :
mProperty_lkey (),
mProperty_values () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementValueMap_2D_element::~ GALGAS_arxmlElementValueMap_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementValueMap_2D_element::GALGAS_arxmlElementValueMap_2D_element (const GALGAS_lstring & inOperand0,
                                                                                const GALGAS_arxmlElementValueList & inOperand1) :
mProperty_lkey (inOperand0),
mProperty_values (inOperand1) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementValueMap_2D_element GALGAS_arxmlElementValueMap_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_arxmlElementValueMap_2D_element (GALGAS_lstring::constructor_default (HERE),
                                                 GALGAS_arxmlElementValueList::constructor_emptyList (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementValueMap_2D_element GALGAS_arxmlElementValueMap_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                                const GALGAS_arxmlElementValueList & inOperand1 
                                                                                                COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_arxmlElementValueMap_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_arxmlElementValueMap_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_arxmlElementValueMap_2D_element::objectCompare (const GALGAS_arxmlElementValueMap_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_lkey.objectCompare (inOperand.mProperty_lkey) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_values.objectCompare (inOperand.mProperty_values) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_arxmlElementValueMap_2D_element::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_values.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlElementValueMap_2D_element::drop (void) {
  mProperty_lkey.drop () ;
  mProperty_values.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlElementValueMap_2D_element::description (C_String & ioString,
                                                          const int32_t inIndentation) const {
  ioString << "<struct @arxmlElementValueMap-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_lkey.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_values.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//@arxmlElementValueMap-element type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_arxmlElementValueMap_2D_element ("arxmlElementValueMap-element",
                                                        NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_arxmlElementValueMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_arxmlElementValueMap_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_arxmlElementValueMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_arxmlElementValueMap_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementValueMap_2D_element GALGAS_arxmlElementValueMap_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                              C_Compiler * inCompiler
                                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_arxmlElementValueMap_2D_element result ;
  const GALGAS_arxmlElementValueMap_2D_element * p = (const GALGAS_arxmlElementValueMap_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_arxmlElementValueMap_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("arxmlElementValueMap-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementValueList_2D_element::GALGAS_arxmlElementValueList_2D_element (void) :
mProperty_value () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementValueList_2D_element::~ GALGAS_arxmlElementValueList_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementValueList_2D_element::GALGAS_arxmlElementValueList_2D_element (const GALGAS_arxmlElementValue & inOperand0) :
mProperty_value (inOperand0) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementValueList_2D_element GALGAS_arxmlElementValueList_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_arxmlElementValueList_2D_element (GALGAS_arxmlElementValue::constructor_default (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementValueList_2D_element GALGAS_arxmlElementValueList_2D_element::constructor_new (const GALGAS_arxmlElementValue & inOperand0 
                                                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_arxmlElementValueList_2D_element result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_arxmlElementValueList_2D_element (inOperand0) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_arxmlElementValueList_2D_element::objectCompare (const GALGAS_arxmlElementValueList_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_value.objectCompare (inOperand.mProperty_value) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_arxmlElementValueList_2D_element::isValid (void) const {
  return mProperty_value.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlElementValueList_2D_element::drop (void) {
  mProperty_value.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlElementValueList_2D_element::description (C_String & ioString,
                                                           const int32_t inIndentation) const {
  ioString << "<struct @arxmlElementValueList-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_value.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//@arxmlElementValueList-element type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_arxmlElementValueList_2D_element ("arxmlElementValueList-element",
                                                         NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_arxmlElementValueList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_arxmlElementValueList_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_arxmlElementValueList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_arxmlElementValueList_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlElementValueList_2D_element GALGAS_arxmlElementValueList_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                                C_Compiler * inCompiler
                                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_arxmlElementValueList_2D_element result ;
  const GALGAS_arxmlElementValueList_2D_element * p = (const GALGAS_arxmlElementValueList_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_arxmlElementValueList_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("arxmlElementValueList-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaClassMap_2D_element::GALGAS_arxmlMetaClassMap_2D_element (void) :
mProperty_lkey (),
mProperty_mType () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaClassMap_2D_element::~ GALGAS_arxmlMetaClassMap_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaClassMap_2D_element::GALGAS_arxmlMetaClassMap_2D_element (const GALGAS_lstring & inOperand0,
                                                                          const GALGAS_arxmlMetaClass & inOperand1) :
mProperty_lkey (inOperand0),
mProperty_mType (inOperand1) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaClassMap_2D_element GALGAS_arxmlMetaClassMap_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_arxmlMetaClassMap_2D_element (GALGAS_lstring::constructor_default (HERE),
                                              GALGAS_arxmlMetaClass::constructor_default (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaClassMap_2D_element GALGAS_arxmlMetaClassMap_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                          const GALGAS_arxmlMetaClass & inOperand1 
                                                                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_arxmlMetaClassMap_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_arxmlMetaClassMap_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_arxmlMetaClassMap_2D_element::objectCompare (const GALGAS_arxmlMetaClassMap_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_lkey.objectCompare (inOperand.mProperty_lkey) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_mType.objectCompare (inOperand.mProperty_mType) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_arxmlMetaClassMap_2D_element::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_mType.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaClassMap_2D_element::drop (void) {
  mProperty_lkey.drop () ;
  mProperty_mType.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaClassMap_2D_element::description (C_String & ioString,
                                                       const int32_t inIndentation) const {
  ioString << "<struct @arxmlMetaClassMap-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_lkey.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_mType.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//@arxmlMetaClassMap-element type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_arxmlMetaClassMap_2D_element ("arxmlMetaClassMap-element",
                                                     NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_arxmlMetaClassMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_arxmlMetaClassMap_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_arxmlMetaClassMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_arxmlMetaClassMap_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaClassMap_2D_element GALGAS_arxmlMetaClassMap_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                        C_Compiler * inCompiler
                                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_arxmlMetaClassMap_2D_element result ;
  const GALGAS_arxmlMetaClassMap_2D_element * p = (const GALGAS_arxmlMetaClassMap_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_arxmlMetaClassMap_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("arxmlMetaClassMap-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaClasslist_2D_element::GALGAS_arxmlMetaClasslist_2D_element (void) :
mProperty_lClass () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaClasslist_2D_element::~ GALGAS_arxmlMetaClasslist_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaClasslist_2D_element::GALGAS_arxmlMetaClasslist_2D_element (const GALGAS_arxmlMetaClass & inOperand0) :
mProperty_lClass (inOperand0) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaClasslist_2D_element GALGAS_arxmlMetaClasslist_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_arxmlMetaClasslist_2D_element (GALGAS_arxmlMetaClass::constructor_default (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaClasslist_2D_element GALGAS_arxmlMetaClasslist_2D_element::constructor_new (const GALGAS_arxmlMetaClass & inOperand0 
                                                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_arxmlMetaClasslist_2D_element result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_arxmlMetaClasslist_2D_element (inOperand0) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_arxmlMetaClasslist_2D_element::objectCompare (const GALGAS_arxmlMetaClasslist_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_lClass.objectCompare (inOperand.mProperty_lClass) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_arxmlMetaClasslist_2D_element::isValid (void) const {
  return mProperty_lClass.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaClasslist_2D_element::drop (void) {
  mProperty_lClass.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaClasslist_2D_element::description (C_String & ioString,
                                                        const int32_t inIndentation) const {
  ioString << "<struct @arxmlMetaClasslist-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_lClass.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//@arxmlMetaClasslist-element type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_arxmlMetaClasslist_2D_element ("arxmlMetaClasslist-element",
                                                      NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_arxmlMetaClasslist_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_arxmlMetaClasslist_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_arxmlMetaClasslist_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_arxmlMetaClasslist_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaClasslist_2D_element GALGAS_arxmlMetaClasslist_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                          C_Compiler * inCompiler
                                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_arxmlMetaClasslist_2D_element result ;
  const GALGAS_arxmlMetaClasslist_2D_element * p = (const GALGAS_arxmlMetaClasslist_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_arxmlMetaClasslist_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("arxmlMetaClasslist-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaElementList_2D_element::GALGAS_arxmlMetaElementList_2D_element (void) :
mProperty_lElement () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaElementList_2D_element::~ GALGAS_arxmlMetaElementList_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaElementList_2D_element::GALGAS_arxmlMetaElementList_2D_element (const GALGAS_arxmlMetaElement & inOperand0) :
mProperty_lElement (inOperand0) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaElementList_2D_element GALGAS_arxmlMetaElementList_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_arxmlMetaElementList_2D_element (GALGAS_arxmlMetaElement::constructor_default (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaElementList_2D_element GALGAS_arxmlMetaElementList_2D_element::constructor_new (const GALGAS_arxmlMetaElement & inOperand0 
                                                                                                COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_arxmlMetaElementList_2D_element result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_arxmlMetaElementList_2D_element (inOperand0) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_arxmlMetaElementList_2D_element::objectCompare (const GALGAS_arxmlMetaElementList_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_lElement.objectCompare (inOperand.mProperty_lElement) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_arxmlMetaElementList_2D_element::isValid (void) const {
  return mProperty_lElement.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaElementList_2D_element::drop (void) {
  mProperty_lElement.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaElementList_2D_element::description (C_String & ioString,
                                                          const int32_t inIndentation) const {
  ioString << "<struct @arxmlMetaElementList-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_lElement.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//@arxmlMetaElementList-element type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_arxmlMetaElementList_2D_element ("arxmlMetaElementList-element",
                                                        NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_arxmlMetaElementList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_arxmlMetaElementList_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_arxmlMetaElementList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_arxmlMetaElementList_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaElementList_2D_element GALGAS_arxmlMetaElementList_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                              C_Compiler * inCompiler
                                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_arxmlMetaElementList_2D_element result ;
  const GALGAS_arxmlMetaElementList_2D_element * p = (const GALGAS_arxmlMetaElementList_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_arxmlMetaElementList_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("arxmlMetaElementList-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaAttributeList_2D_element::GALGAS_arxmlMetaAttributeList_2D_element (void) :
mProperty_lAttribute () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaAttributeList_2D_element::~ GALGAS_arxmlMetaAttributeList_2D_element (void) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaAttributeList_2D_element::GALGAS_arxmlMetaAttributeList_2D_element (const GALGAS_arxmlMetaAttribute & inOperand0) :
mProperty_lAttribute (inOperand0) {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaAttributeList_2D_element GALGAS_arxmlMetaAttributeList_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_arxmlMetaAttributeList_2D_element (GALGAS_arxmlMetaAttribute::constructor_default (HERE)) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaAttributeList_2D_element GALGAS_arxmlMetaAttributeList_2D_element::constructor_new (const GALGAS_arxmlMetaAttribute & inOperand0 
                                                                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_arxmlMetaAttributeList_2D_element result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_arxmlMetaAttributeList_2D_element (inOperand0) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult GALGAS_arxmlMetaAttributeList_2D_element::objectCompare (const GALGAS_arxmlMetaAttributeList_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_lAttribute.objectCompare (inOperand.mProperty_lAttribute) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

bool GALGAS_arxmlMetaAttributeList_2D_element::isValid (void) const {
  return mProperty_lAttribute.isValid () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaAttributeList_2D_element::drop (void) {
  mProperty_lAttribute.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_arxmlMetaAttributeList_2D_element::description (C_String & ioString,
                                                            const int32_t inIndentation) const {
  ioString << "<struct @arxmlMetaAttributeList-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_lAttribute.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//@arxmlMetaAttributeList-element type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_arxmlMetaAttributeList_2D_element ("arxmlMetaAttributeList-element",
                                                          NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_arxmlMetaAttributeList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_arxmlMetaAttributeList_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_arxmlMetaAttributeList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_arxmlMetaAttributeList_2D_element (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_arxmlMetaAttributeList_2D_element GALGAS_arxmlMetaAttributeList_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                                  C_Compiler * inCompiler
                                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_arxmlMetaAttributeList_2D_element result ;
  const GALGAS_arxmlMetaAttributeList_2D_element * p = (const GALGAS_arxmlMetaAttributeList_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_arxmlMetaAttributeList_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("arxmlMetaAttributeList-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//   Object comparison                                                                           
//----------------------------------------------------------------------------------------------------------------------

typeComparisonResult cPtr_gtlContext::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlContext * p = (const cPtr_gtlContext *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlContext) ;
  if (kOperandEqual == result) {
    result = mProperty_prefix.objectCompare (p->mProperty_prefix) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_path.objectCompare (p->mProperty_path) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_templateDirectory.objectCompare (p->mProperty_templateDirectory) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_userTemplateDirectory.objectCompare (p->mProperty_userTemplateDirectory) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_templateExtension.objectCompare (p->mProperty_templateExtension) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_importPath.objectCompare (p->mProperty_importPath) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_inputVars.objectCompare (p->mProperty_inputVars) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_propagateError.objectCompare (p->mProperty_propagateError) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_debuggerContext.objectCompare (p->mProperty_debuggerContext) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------


typeComparisonResult GALGAS_gtlContext::objectCompare (const GALGAS_gtlContext & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlContext::GALGAS_gtlContext (void) :
AC_GALGAS_value_class () {
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlContext GALGAS_gtlContext::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlContext::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                             GALGAS_string::constructor_default (HERE),
                                             GALGAS_string::constructor_default (HERE),
                                             GALGAS_string::constructor_default (HERE),
                                             GALGAS_string::constructor_default (HERE),
                                             GALGAS_stringlist::constructor_emptyList (HERE),
                                             GALGAS_gtlDataList::constructor_emptyList (HERE),
                                             GALGAS_bool::constructor_default (HERE),
                                             GALGAS_debuggerContext::constructor_default (HERE)
                                             COMMA_THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlContext::GALGAS_gtlContext (const cPtr_gtlContext * inSourcePtr) :
AC_GALGAS_value_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlContext) ;
}
//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlContext GALGAS_gtlContext::constructor_new (const GALGAS_lstring & inAttribute_prefix,
                                                      const GALGAS_string & inAttribute_path,
                                                      const GALGAS_string & inAttribute_templateDirectory,
                                                      const GALGAS_string & inAttribute_userTemplateDirectory,
                                                      const GALGAS_string & inAttribute_templateExtension,
                                                      const GALGAS_stringlist & inAttribute_importPath,
                                                      const GALGAS_gtlDataList & inAttribute_inputVars,
                                                      const GALGAS_bool & inAttribute_propagateError,
                                                      const GALGAS_debuggerContext & inAttribute_debuggerContext
                                                      COMMA_LOCATION_ARGS) {
  GALGAS_gtlContext result ;
  if (inAttribute_prefix.isValid () && inAttribute_path.isValid () && inAttribute_templateDirectory.isValid () && inAttribute_userTemplateDirectory.isValid () && inAttribute_templateExtension.isValid () && inAttribute_importPath.isValid () && inAttribute_inputVars.isValid () && inAttribute_propagateError.isValid () && inAttribute_debuggerContext.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlContext (inAttribute_prefix, inAttribute_path, inAttribute_templateDirectory, inAttribute_userTemplateDirectory, inAttribute_templateExtension, inAttribute_importPath, inAttribute_inputVars, inAttribute_propagateError, inAttribute_debuggerContext COMMA_THERE)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring GALGAS_gtlContext::readProperty_prefix (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_lstring () ;
  }else{
    const cPtr_gtlContext * p = (const cPtr_gtlContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlContext) ;
    return p->mProperty_prefix ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_gtlContext::getter_prefix (UNUSED_LOCATION_ARGS) const {
  return mProperty_prefix ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_gtlContext::readProperty_path (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_string () ;
  }else{
    const cPtr_gtlContext * p = (const cPtr_gtlContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlContext) ;
    return p->mProperty_path ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlContext::getter_path (UNUSED_LOCATION_ARGS) const {
  return mProperty_path ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_gtlContext::readProperty_templateDirectory (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_string () ;
  }else{
    const cPtr_gtlContext * p = (const cPtr_gtlContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlContext) ;
    return p->mProperty_templateDirectory ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlContext::getter_templateDirectory (UNUSED_LOCATION_ARGS) const {
  return mProperty_templateDirectory ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_gtlContext::readProperty_userTemplateDirectory (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_string () ;
  }else{
    const cPtr_gtlContext * p = (const cPtr_gtlContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlContext) ;
    return p->mProperty_userTemplateDirectory ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlContext::getter_userTemplateDirectory (UNUSED_LOCATION_ARGS) const {
  return mProperty_userTemplateDirectory ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string GALGAS_gtlContext::readProperty_templateExtension (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_string () ;
  }else{
    const cPtr_gtlContext * p = (const cPtr_gtlContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlContext) ;
    return p->mProperty_templateExtension ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlContext::getter_templateExtension (UNUSED_LOCATION_ARGS) const {
  return mProperty_templateExtension ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringlist GALGAS_gtlContext::readProperty_importPath (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_stringlist () ;
  }else{
    const cPtr_gtlContext * p = (const cPtr_gtlContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlContext) ;
    return p->mProperty_importPath ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringlist cPtr_gtlContext::getter_importPath (UNUSED_LOCATION_ARGS) const {
  return mProperty_importPath ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlDataList GALGAS_gtlContext::readProperty_inputVars (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_gtlDataList () ;
  }else{
    const cPtr_gtlContext * p = (const cPtr_gtlContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlContext) ;
    return p->mProperty_inputVars ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlDataList cPtr_gtlContext::getter_inputVars (UNUSED_LOCATION_ARGS) const {
  return mProperty_inputVars ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool GALGAS_gtlContext::readProperty_propagateError (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_bool () ;
  }else{
    const cPtr_gtlContext * p = (const cPtr_gtlContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlContext) ;
    return p->mProperty_propagateError ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_gtlContext::getter_propagateError (UNUSED_LOCATION_ARGS) const {
  return mProperty_propagateError ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_debuggerContext GALGAS_gtlContext::readProperty_debuggerContext (void) const {
  if (NULL == mObjectPtr) {
    return GALGAS_debuggerContext () ;
  }else{
    const cPtr_gtlContext * p = (const cPtr_gtlContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlContext) ;
    return p->mProperty_debuggerContext ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_debuggerContext cPtr_gtlContext::getter_debuggerContext (UNUSED_LOCATION_ARGS) const {
  return mProperty_debuggerContext ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlContext::setter_setPrefix (GALGAS_lstring inValue
                                          COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlContext * p = (cPtr_gtlContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlContext) ;
    p->mProperty_prefix = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlContext::setter_setPrefix (GALGAS_lstring inValue
                                        COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_prefix = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlContext::setter_setPath (GALGAS_string inValue
                                        COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlContext * p = (cPtr_gtlContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlContext) ;
    p->mProperty_path = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlContext::setter_setPath (GALGAS_string inValue
                                      COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_path = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlContext::setter_setTemplateDirectory (GALGAS_string inValue
                                                     COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlContext * p = (cPtr_gtlContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlContext) ;
    p->mProperty_templateDirectory = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlContext::setter_setTemplateDirectory (GALGAS_string inValue
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_templateDirectory = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlContext::setter_setUserTemplateDirectory (GALGAS_string inValue
                                                         COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlContext * p = (cPtr_gtlContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlContext) ;
    p->mProperty_userTemplateDirectory = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlContext::setter_setUserTemplateDirectory (GALGAS_string inValue
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_userTemplateDirectory = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlContext::setter_setTemplateExtension (GALGAS_string inValue
                                                     COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlContext * p = (cPtr_gtlContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlContext) ;
    p->mProperty_templateExtension = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlContext::setter_setTemplateExtension (GALGAS_string inValue
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_templateExtension = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlContext::setter_setImportPath (GALGAS_stringlist inValue
                                              COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlContext * p = (cPtr_gtlContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlContext) ;
    p->mProperty_importPath = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlContext::setter_setImportPath (GALGAS_stringlist inValue
                                            COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_importPath = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlContext::setter_setInputVars (GALGAS_gtlDataList inValue
                                             COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlContext * p = (cPtr_gtlContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlContext) ;
    p->mProperty_inputVars = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlContext::setter_setInputVars (GALGAS_gtlDataList inValue
                                           COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_inputVars = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlContext::setter_setPropagateError (GALGAS_bool inValue
                                                  COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlContext * p = (cPtr_gtlContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlContext) ;
    p->mProperty_propagateError = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlContext::setter_setPropagateError (GALGAS_bool inValue
                                                COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_propagateError = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------

void GALGAS_gtlContext::setter_setDebuggerContext (GALGAS_debuggerContext inValue
                                                   COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlContext * p = (cPtr_gtlContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlContext) ;
    p->mProperty_debuggerContext = inValue ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cPtr_gtlContext::setter_setDebuggerContext (GALGAS_debuggerContext inValue
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_debuggerContext = inValue ;
}

//----------------------------------------------------------------------------------------------------------------------
//Pointer class for @gtlContext class
//----------------------------------------------------------------------------------------------------------------------

cPtr_gtlContext::cPtr_gtlContext (const GALGAS_lstring & in_prefix,
                                  const GALGAS_string & in_path,
                                  const GALGAS_string & in_templateDirectory,
                                  const GALGAS_string & in_userTemplateDirectory,
                                  const GALGAS_string & in_templateExtension,
                                  const GALGAS_stringlist & in_importPath,
                                  const GALGAS_gtlDataList & in_inputVars,
                                  const GALGAS_bool & in_propagateError,
                                  const GALGAS_debuggerContext & in_debuggerContext
                                  COMMA_LOCATION_ARGS) :
acPtr_class (THERE),
mProperty_prefix (in_prefix),
mProperty_path (in_path),
mProperty_templateDirectory (in_templateDirectory),
mProperty_userTemplateDirectory (in_userTemplateDirectory),
mProperty_templateExtension (in_templateExtension),
mProperty_importPath (in_importPath),
mProperty_inputVars (in_inputVars),
mProperty_propagateError (in_propagateError),
mProperty_debuggerContext (in_debuggerContext) {
}

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * cPtr_gtlContext::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlContext ;
}

void cPtr_gtlContext::description (C_String & ioString,
                                   const int32_t inIndentation) const {
  ioString << "[@gtlContext:" ;
  mProperty_prefix.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_path.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_templateDirectory.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_userTemplateDirectory.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_templateExtension.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_importPath.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_inputVars.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_propagateError.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_debuggerContext.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//----------------------------------------------------------------------------------------------------------------------

acPtr_class * cPtr_gtlContext::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlContext (mProperty_prefix, mProperty_path, mProperty_templateDirectory, mProperty_userTemplateDirectory, mProperty_templateExtension, mProperty_importPath, mProperty_inputVars, mProperty_propagateError, mProperty_debuggerContext COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//@gtlContext type
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlContext ("gtlContext",
                                   NULL) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlContext::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlContext ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlContext::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlContext (*this)) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------

GALGAS_gtlContext GALGAS_gtlContext::extractObject (const GALGAS_object & inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlContext result ;
  const GALGAS_gtlContext * p = (const GALGAS_gtlContext *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlContext *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlContext", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Extension setter '@gtlContext addModulePath'
//
//----------------------------------------------------------------------------------------------------------------------

static TC_UniqueArray <extensionSetterSignature_gtlContext_addModulePath> gExtensionModifierTable_gtlContext_addModulePath ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionSetter_addModulePath (const int32_t inClassIndex,
                                         extensionSetterSignature_gtlContext_addModulePath inModifier) {
  gExtensionModifierTable_gtlContext_addModulePath.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionSetter_addModulePath (cPtr_gtlContext * inObject,
                                        const GALGAS_string constin_rootPath,
                                        const GALGAS_string constin_modulePath,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_gtlContext_addModulePath f = NULL ;
    if (classIndex < gExtensionModifierTable_gtlContext_addModulePath.count ()) {
      f = gExtensionModifierTable_gtlContext_addModulePath (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_gtlContext_addModulePath.count ()) {
           f = gExtensionModifierTable_gtlContext_addModulePath (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_gtlContext_addModulePath.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, constin_rootPath, constin_modulePath, inCompiler COMMA_THERE) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void extensionSetter_gtlContext_addModulePath (cPtr_gtlContext * inObject,
                                                      const GALGAS_string constinArgument_rootPath,
                                                      const GALGAS_string constinArgument_modulePath,
                                                      C_Compiler * /* inCompiler */
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlContext * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlContext) ;
  GALGAS_string var_normalizedModulePath_1517 = constinArgument_modulePath.getter_absolutePathFromPath (constinArgument_rootPath COMMA_SOURCE_FILE ("gtl_types.galgas", 63)).getter_stringByStandardizingPath (SOURCE_FILE ("gtl_types.galgas", 63)) ;
  object->mProperty_importPath.addAssign_operation (var_normalizedModulePath_1517  COMMA_SOURCE_FILE ("gtl_types.galgas", 64)) ;
}
//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionSetter_gtlContext_addModulePath (void) {
  enterExtensionSetter_addModulePath (kTypeDescriptor_GALGAS_gtlContext.mSlotID,
                                      extensionSetter_gtlContext_addModulePath) ;
}

//----------------------------------------------------------------------------------------------------------------------

static void freeExtensionModifier_gtlContext_addModulePath (void) {
  gExtensionModifierTable_gtlContext_addModulePath.free () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gSetter_gtlContext_addModulePath (defineExtensionSetter_gtlContext_addModulePath,
                                                     freeExtensionModifier_gtlContext_addModulePath) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension setter '@gtlContext addInputVariable'
//
//----------------------------------------------------------------------------------------------------------------------

static TC_UniqueArray <extensionSetterSignature_gtlContext_addInputVariable> gExtensionModifierTable_gtlContext_addInputVariable ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionSetter_addInputVariable (const int32_t inClassIndex,
                                            extensionSetterSignature_gtlContext_addInputVariable inModifier) {
  gExtensionModifierTable_gtlContext_addInputVariable.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionSetter_addInputVariable (cPtr_gtlContext * inObject,
                                           GALGAS_gtlData in_inputVariable,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_gtlContext_addInputVariable f = NULL ;
    if (classIndex < gExtensionModifierTable_gtlContext_addInputVariable.count ()) {
      f = gExtensionModifierTable_gtlContext_addInputVariable (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_gtlContext_addInputVariable.count ()) {
           f = gExtensionModifierTable_gtlContext_addInputVariable (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_gtlContext_addInputVariable.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, in_inputVariable, inCompiler COMMA_THERE) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void extensionSetter_gtlContext_addInputVariable (cPtr_gtlContext * inObject,
                                                         GALGAS_gtlData inArgument_inputVariable,
                                                         C_Compiler * /* inCompiler */
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlContext * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlContext) ;
  object->mProperty_inputVars.addAssign_operation (inArgument_inputVariable  COMMA_SOURCE_FILE ("gtl_types.galgas", 70)) ;
}
//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionSetter_gtlContext_addInputVariable (void) {
  enterExtensionSetter_addInputVariable (kTypeDescriptor_GALGAS_gtlContext.mSlotID,
                                         extensionSetter_gtlContext_addInputVariable) ;
}

//----------------------------------------------------------------------------------------------------------------------

static void freeExtensionModifier_gtlContext_addInputVariable (void) {
  gExtensionModifierTable_gtlContext_addInputVariable.free () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gSetter_gtlContext_addInputVariable (defineExtensionSetter_gtlContext_addInputVariable,
                                                        freeExtensionModifier_gtlContext_addInputVariable) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension setter '@gtlContext popFirstInputArg'
//
//----------------------------------------------------------------------------------------------------------------------

static TC_UniqueArray <extensionSetterSignature_gtlContext_popFirstInputArg> gExtensionModifierTable_gtlContext_popFirstInputArg ;

//----------------------------------------------------------------------------------------------------------------------

void enterExtensionSetter_popFirstInputArg (const int32_t inClassIndex,
                                            extensionSetterSignature_gtlContext_popFirstInputArg inModifier) {
  gExtensionModifierTable_gtlContext_popFirstInputArg.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionSetter_popFirstInputArg (cPtr_gtlContext * inObject,
                                           GALGAS_location in_where,
                                           GALGAS_gtlData & out_result,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) {
//--- Drop output arguments
  out_result.drop () ;
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_gtlContext_popFirstInputArg f = NULL ;
    if (classIndex < gExtensionModifierTable_gtlContext_popFirstInputArg.count ()) {
      f = gExtensionModifierTable_gtlContext_popFirstInputArg (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_gtlContext_popFirstInputArg.count ()) {
           f = gExtensionModifierTable_gtlContext_popFirstInputArg (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_gtlContext_popFirstInputArg.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, in_where, out_result, inCompiler COMMA_THERE) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------

static void extensionSetter_gtlContext_popFirstInputArg (cPtr_gtlContext * inObject,
                                                         GALGAS_location inArgument_where,
                                                         GALGAS_gtlData & outArgument_result,
                                                         C_Compiler * inCompiler
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlContext * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlContext) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsStrictSup, object->mProperty_inputVars.getter_length (SOURCE_FILE ("gtl_types.galgas", 77)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      object->mProperty_inputVars.setter_popFirst (outArgument_result, inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 78)) ;
      }
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray1 ;
    inCompiler->emitSemanticError (inArgument_where, GALGAS_string ("No input argument available"), fixItArray1  COMMA_SOURCE_FILE ("gtl_types.galgas", 80)) ;
    outArgument_result.drop () ; // Release error dropped variable
  }
}
//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionSetter_gtlContext_popFirstInputArg (void) {
  enterExtensionSetter_popFirstInputArg (kTypeDescriptor_GALGAS_gtlContext.mSlotID,
                                         extensionSetter_gtlContext_popFirstInputArg) ;
}

//----------------------------------------------------------------------------------------------------------------------

static void freeExtensionModifier_gtlContext_popFirstInputArg (void) {
  gExtensionModifierTable_gtlContext_popFirstInputArg.free () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gSetter_gtlContext_popFirstInputArg (defineExtensionSetter_gtlContext_popFirstInputArg,
                                                        freeExtensionModifier_gtlContext_popFirstInputArg) ;

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@gtlContext fullPrefix'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_gtlContext::getter_fullPrefix (const GALGAS_gtlData /* constinArgument_vars */,
                                                   C_Compiler */* inCompiler */
                                                   COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result_full ; // Returned variable
  result_full = this->mProperty_prefix ;
//---
  return result_full ;
}



//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring callExtensionGetter_fullPrefix (const cPtr_gtlContext * inObject,
                                               const GALGAS_gtlData in_vars,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) {
  GALGAS_lstring result ;
  if (nullptr != inObject) {
    result = inObject->getter_fullPrefix (in_vars, inCompiler COMMA_THERE) ;
  }
  return result ;
}

//----------------------------------------------------------------------------------------------------------------------
//
//Extension getter '@gtlContext fullTemplateFileName'
//
//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_gtlContext::getter_fullTemplateFileName (GALGAS_gtlContext inArgument_context,
                                                             GALGAS_gtlData inArgument_vars,
                                                             GALGAS_lstring inArgument_simpleName,
                                                             C_Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result_fullName ; // Returned variable
  const GALGAS_gtlContext temp_0 = this ;
  GALGAS_lstring var_fullPref_2489 = callExtensionGetter_fullPrefix ((const cPtr_gtlContext *) temp_0.ptr (), inArgument_vars, inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 110)) ;
  GALGAS_bool var_found_2532 = GALGAS_bool (false) ;
  GALGAS_string var_prefixedTemplatePath_2571 ;
  GALGAS_string var_hierarchicalPath_2598 ;
  GALGAS_string var_rootPath_2617 ;
  var_prefixedTemplatePath_2571 = extensionGetter_stringByAppendingPath (this->mProperty_userTemplateDirectory, var_fullPref_2489.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 121)) ;
  var_hierarchicalPath_2598 = this->mProperty_path ;
  var_rootPath_2617 = function_pathWithExtension (inArgument_context, extensionGetter_stringByAppendingPath (var_prefixedTemplatePath_2571, inArgument_simpleName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 125)), inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 123)) ;
  if (var_hierarchicalPath_2598.getter_length (SOURCE_FILE ("gtl_types.galgas", 128)).isValid ()) {
    uint32_t variant_2914 = var_hierarchicalPath_2598.getter_length (SOURCE_FILE ("gtl_types.galgas", 128)).uintValue () ;
    bool loop_2914 = true ;
    while (loop_2914) {
        GALGAS_string var_fullPath_2969 = function_pathWithExtension (inArgument_context, extensionGetter_stringByAppendingPath (extensionGetter_stringByAppendingPath (var_prefixedTemplatePath_2571, var_hierarchicalPath_2598, inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 131)), inArgument_simpleName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 131)), inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 129)) ;
        enumGalgasBool test_1 = kBoolTrue ;
        if (kBoolTrue == test_1) {
          test_1 = var_fullPath_2969.getter_fileExists (SOURCE_FILE ("gtl_types.galgas", 136)).boolEnum () ;
          if (kBoolTrue == test_1) {
            var_rootPath_2617 = var_fullPath_2969 ;
            var_found_2532 = GALGAS_bool (true) ;
          }
        }
      GALGAS_bool test_2 = var_found_2532.operator_not (SOURCE_FILE ("gtl_types.galgas", 143)) ;
      if (kBoolTrue == test_2.boolEnum ()) {
        test_2 = GALGAS_bool (kIsStrictSup, var_hierarchicalPath_2598.getter_length (SOURCE_FILE ("gtl_types.galgas", 143)).objectCompare (GALGAS_uint (uint32_t (0U)))) ;
      }
      loop_2914 = test_2.isValid () ;
      if (loop_2914) {
        loop_2914 = test_2.boolValue () ;
      }
      if (loop_2914 && (0 == variant_2914)) {
        loop_2914 = false ;
        inCompiler->loopRunTimeVariantError (SOURCE_FILE ("gtl_types.galgas", 128)) ;
      }
      if (loop_2914) {
        variant_2914 -- ;
        var_hierarchicalPath_2598 = var_hierarchicalPath_2598.getter_stringByDeletingLastPathComponent (SOURCE_FILE ("gtl_types.galgas", 144)) ;
      }
    }
  }
  enumGalgasBool test_3 = kBoolTrue ;
  if (kBoolTrue == test_3) {
    test_3 = var_found_2532.operator_not (SOURCE_FILE ("gtl_types.galgas", 147)).boolEnum () ;
    if (kBoolTrue == test_3) {
      var_prefixedTemplatePath_2571 = extensionGetter_stringByAppendingPath (this->mProperty_templateDirectory, var_fullPref_2489.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 152)) ;
      var_hierarchicalPath_2598 = this->mProperty_path ;
      var_rootPath_2617 = function_pathWithExtension (inArgument_context, extensionGetter_stringByAppendingPath (var_prefixedTemplatePath_2571, inArgument_simpleName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 156)), inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 154)) ;
      if (var_hierarchicalPath_2598.getter_length (SOURCE_FILE ("gtl_types.galgas", 160)).isValid ()) {
        uint32_t variant_3799 = var_hierarchicalPath_2598.getter_length (SOURCE_FILE ("gtl_types.galgas", 160)).uintValue () ;
        bool loop_3799 = true ;
        while (loop_3799) {
            GALGAS_string var_fullPath_3856 = function_pathWithExtension (inArgument_context, extensionGetter_stringByAppendingPath (extensionGetter_stringByAppendingPath (var_prefixedTemplatePath_2571, var_hierarchicalPath_2598, inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 163)), inArgument_simpleName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 163)), inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 161)) ;
            enumGalgasBool test_4 = kBoolTrue ;
            if (kBoolTrue == test_4) {
              test_4 = var_fullPath_3856.getter_fileExists (SOURCE_FILE ("gtl_types.galgas", 168)).boolEnum () ;
              if (kBoolTrue == test_4) {
                var_rootPath_2617 = var_fullPath_3856 ;
                var_found_2532 = GALGAS_bool (true) ;
              }
            }
          GALGAS_bool test_5 = var_found_2532.operator_not (SOURCE_FILE ("gtl_types.galgas", 175)) ;
          if (kBoolTrue == test_5.boolEnum ()) {
            test_5 = GALGAS_bool (kIsStrictSup, var_hierarchicalPath_2598.getter_length (SOURCE_FILE ("gtl_types.galgas", 175)).objectCompare (GALGAS_uint (uint32_t (0U)))) ;
          }
          loop_3799 = test_5.isValid () ;
          if (loop_3799) {
            loop_3799 = test_5.boolValue () ;
          }
          if (loop_3799 && (0 == variant_3799)) {
            loop_3799 = false ;
            inCompiler->loopRunTimeVariantError (SOURCE_FILE ("gtl_types.galgas", 160)) ;
          }
          if (loop_3799) {
            variant_3799 -- ;
            var_hierarchicalPath_2598 = var_hierarchicalPath_2598.getter_stringByDeletingLastPathComponent (SOURCE_FILE ("gtl_types.galgas", 176)) ;
          }
        }
      }
    }
  }
  result_fullName = GALGAS_lstring::constructor_new (var_rootPath_2617, inArgument_simpleName.readProperty_location ()  COMMA_SOURCE_FILE ("gtl_types.galgas", 180)) ;
//---
  return result_fullName ;
}



//----------------------------------------------------------------------------------------------------------------------

GALGAS_lstring callExtensionGetter_fullTemplateFileName (const cPtr_gtlContext * inObject,
                                                         GALGAS_gtlContext in_context,
                                                         GALGAS_gtlData in_vars,
                                                         GALGAS_lstring in_simpleName,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) {
  GALGAS_lstring result ;
  if (nullptr != inObject) {
    result = inObject->getter_fullTemplateFileName (in_context, in_vars, in_simpleName, inCompiler COMMA_THERE) ;
  }
  return result ;
}



//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_module_5F_parser::rule_gtl_5F_module_5F_parser_gtl_5F_instruction_5F_list_i0_ (GALGAS_gtlInstructionList & outArgument_instructionList,
                                                                                                   C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instructionList.drop () ; // Release 'out' argument
  outArgument_instructionList = GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_module_parser.galgas", 48)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_gtl_5F_module_5F_parser_0 (inCompiler)) {
    case 2: {
      GALGAS_gtlInstruction var_instruction_1355 ;
      nt_gtl_5F_instruction_ (var_instruction_1355, inCompiler) ;
      outArgument_instructionList.addAssign_operation (var_instruction_1355  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 53)) ;
    } break ;
    case 3: {
      GALGAS_gtlInstruction var_instruction_1534 ;
      nt_gtl_5F_simple_5F_instruction_ (var_instruction_1534, inCompiler) ;
      outArgument_instructionList.addAssign_operation (var_instruction_1534  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 57)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_module_5F_parser::rule_gtl_5F_module_5F_parser_gtl_5F_instruction_5F_list_i0_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_gtl_5F_module_5F_parser_0 (inCompiler)) {
    case 2: {
      nt_gtl_5F_instruction_parse (inCompiler) ;
    } break ;
    case 3: {
      nt_gtl_5F_simple_5F_instruction_parse (inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_module_5F_parser::rule_gtl_5F_module_5F_parser_gtl_5F_module_5F_start_5F_symbol_i1_ (GALGAS_gtlContext inArgument_context,
                                                                                                         GALGAS_library & ioArgument_lib,
                                                                                                         C_Lexique_gtl_5F_scanner * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_gtl_5F_module_5F_parser_1 (inCompiler)) {
    case 2: {
      nt_gtl_5F_import_ (inArgument_context, ioArgument_lib, inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  bool repeatFlag_1 = true ;
  while (repeatFlag_1) {
    switch (select_gtl_5F_module_5F_parser_2 (inCompiler)) {
    case 2: {
      GALGAS_gtlFunction var_aFunction_2033 ;
      nt_gtl_5F_function_ (var_aFunction_2033, inCompiler) ;
      {
      ioArgument_lib.insulate (HERE) ;
      cPtr_library * ptr_2044 = (cPtr_library *) ioArgument_lib.ptr () ;
      callExtensionSetter_putFunction ((cPtr_library *) ptr_2044, var_aFunction_2033.readProperty_name (), var_aFunction_2033, inCompiler COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 77)) ;
      }
    } break ;
    case 3: {
      GALGAS_gtlGetter var_aGetter_2135 ;
      nt_gtl_5F_getter_ (var_aGetter_2135, inCompiler) ;
      {
      ioArgument_lib.insulate (HERE) ;
      cPtr_library * ptr_2146 = (cPtr_library *) ioArgument_lib.ptr () ;
      callExtensionSetter_putGetter ((cPtr_library *) ptr_2146, callExtensionGetter_typedName ((const cPtr_gtlGetter *) var_aGetter_2135.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 80)), var_aGetter_2135, inCompiler COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 80)) ;
      }
    } break ;
    case 4: {
      GALGAS_gtlSetter var_aSetter_2236 ;
      nt_gtl_5F_setter_ (var_aSetter_2236, inCompiler) ;
      {
      ioArgument_lib.insulate (HERE) ;
      cPtr_library * ptr_2247 = (cPtr_library *) ioArgument_lib.ptr () ;
      callExtensionSetter_putSetter ((cPtr_library *) ptr_2247, callExtensionGetter_typedName ((const cPtr_gtlSetter *) var_aSetter_2236.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 83)), var_aSetter_2236, inCompiler COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 83)) ;
      }
    } break ;
    default:
      repeatFlag_1 = false ;
      break ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_module_5F_parser::rule_gtl_5F_module_5F_parser_gtl_5F_module_5F_start_5F_symbol_i1_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_gtl_5F_module_5F_parser_1 (inCompiler)) {
    case 2: {
      nt_gtl_5F_import_parse (inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  bool repeatFlag_1 = true ;
  while (repeatFlag_1) {
    switch (select_gtl_5F_module_5F_parser_2 (inCompiler)) {
    case 2: {
      nt_gtl_5F_function_parse (inCompiler) ;
    } break ;
    case 3: {
      nt_gtl_5F_getter_parse (inCompiler) ;
    } break ;
    case 4: {
      nt_gtl_5F_setter_parse (inCompiler) ;
    } break ;
    default:
      repeatFlag_1 = false ;
      break ;
    }
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_module_5F_parser::rule_gtl_5F_module_5F_parser_gtl_5F_function_i2_ (GALGAS_gtlFunction & outArgument_function,
                                                                                        C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_function.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_func COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 93)) ;
  GALGAS_lstring var_functionName_2577 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 94)) ;
  GALGAS_location var_where_2599 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 95)) ;
  GALGAS_gtlArgumentList var_arguments_2661 ;
  nt_gtl_5F_argument_5F_list_ (var_arguments_2661, inCompiler) ;
  GALGAS_lstring var_returnVariable_2705 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 97)) ;
  GALGAS_gtlInstructionList var_instructionList_2771 ;
  nt_gtl_5F_instruction_5F_list_ (var_instructionList_2771, inCompiler) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_end COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 99)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_func COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 99)) ;
  outArgument_function = GALGAS_gtlFunction::constructor_new (var_where_2599, var_functionName_2577, var_arguments_2661, var_instructionList_2771, var_returnVariable_2705  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 101)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_module_5F_parser::rule_gtl_5F_module_5F_parser_gtl_5F_function_i2_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_func COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 93)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 94)) ;
  nt_gtl_5F_argument_5F_list_parse (inCompiler) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 97)) ;
  nt_gtl_5F_instruction_5F_list_parse (inCompiler) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_end COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 99)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_func COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 99)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_module_5F_parser::rule_gtl_5F_module_5F_parser_gtl_5F_getter_i3_ (GALGAS_gtlGetter & outArgument_aGetter,
                                                                                      C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_aGetter.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_getter COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 112)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__40_ COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 113)) ;
  GALGAS_lstring var_targetType_3162 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 113)) ;
  GALGAS_lstring var_getterName_3202 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 114)) ;
  GALGAS_location var_where_3224 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 115)) ;
  GALGAS_gtlArgumentList var_arguments_3286 ;
  nt_gtl_5F_argument_5F_list_ (var_arguments_3286, inCompiler) ;
  GALGAS_lstring var_returnVariable_3330 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 117)) ;
  GALGAS_gtlInstructionList var_instructionList_3396 ;
  nt_gtl_5F_instruction_5F_list_ (var_instructionList_3396, inCompiler) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_end COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 119)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_getter COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 119)) ;
  outArgument_aGetter = GALGAS_gtlGetter::constructor_new (var_where_3224, var_getterName_3202, var_arguments_3286, var_instructionList_3396, var_returnVariable_3330, extensionGetter_gtlType (var_targetType_3162, inCompiler COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 127))  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 121)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_module_5F_parser::rule_gtl_5F_module_5F_parser_gtl_5F_getter_i3_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_getter COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 112)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__40_ COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 113)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 113)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 114)) ;
  nt_gtl_5F_argument_5F_list_parse (inCompiler) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 117)) ;
  nt_gtl_5F_instruction_5F_list_parse (inCompiler) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_end COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 119)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_getter COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 119)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_module_5F_parser::rule_gtl_5F_module_5F_parser_gtl_5F_setter_i4_ (GALGAS_gtlSetter & outArgument_aSetter,
                                                                                      C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_aSetter.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_setter COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 137)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__40_ COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 138)) ;
  GALGAS_lstring var_targetType_3828 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 138)) ;
  GALGAS_lstring var_getterName_3868 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 139)) ;
  GALGAS_location var_where_3890 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 140)) ;
  GALGAS_gtlArgumentList var_arguments_3952 ;
  nt_gtl_5F_argument_5F_list_ (var_arguments_3952, inCompiler) ;
  GALGAS_gtlInstructionList var_instructionList_4018 ;
  nt_gtl_5F_instruction_5F_list_ (var_instructionList_4018, inCompiler) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_end COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 143)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_setter COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 143)) ;
  outArgument_aSetter = GALGAS_gtlSetter::constructor_new (var_where_3890, var_getterName_3868, var_arguments_3952, var_instructionList_4018, extensionGetter_gtlType (var_targetType_3828, inCompiler COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 150))  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 145)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_module_5F_parser::rule_gtl_5F_module_5F_parser_gtl_5F_setter_i4_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_setter COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 137)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__40_ COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 138)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 138)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 139)) ;
  nt_gtl_5F_argument_5F_list_parse (inCompiler) ;
  nt_gtl_5F_instruction_5F_list_parse (inCompiler) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_end COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 143)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_setter COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 143)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_module_5F_parser::rule_gtl_5F_module_5F_parser_gtl_5F_instruction_i5_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                           C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  GALGAS_gtlThenElsifStatementList var_thenElsifList_4471 = GALGAS_gtlThenElsifStatementList::constructor_emptyList (SOURCE_FILE ("gtl_module_parser.galgas", 160)) ;
  GALGAS_gtlInstructionList var_elseList_4515 = GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_module_parser.galgas", 161)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_if COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 163)) ;
  GALGAS_location var_where_4558 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 163)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    GALGAS_gtlExpression var_condition_4626 ;
    nt_gtl_5F_expression_ (var_condition_4626, inCompiler) ;
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_then COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 166)) ;
    GALGAS_gtlInstructionList var_instructionList_4705 ;
    nt_gtl_5F_instruction_5F_list_ (var_instructionList_4705, inCompiler) ;
    var_thenElsifList_4471.addAssign_operation (var_condition_4626, var_instructionList_4705  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 169)) ;
    switch (select_gtl_5F_module_5F_parser_3 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_elsif COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 171)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  switch (select_gtl_5F_module_5F_parser_4 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_else COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 175)) ;
    nt_gtl_5F_instruction_5F_list_ (var_elseList_4515, inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_end COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 179)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_if COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 180)) ;
  outArgument_instruction = GALGAS_gtlIfStatementInstruction::constructor_new (var_where_4558, function_signature (var_where_4558, inCompiler COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 183)), var_thenElsifList_4471, var_elseList_4515  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 182)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_module_5F_parser::rule_gtl_5F_module_5F_parser_gtl_5F_instruction_i5_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_if COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 163)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    nt_gtl_5F_expression_parse (inCompiler) ;
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_then COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 166)) ;
    nt_gtl_5F_instruction_5F_list_parse (inCompiler) ;
    switch (select_gtl_5F_module_5F_parser_3 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_elsif COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 171)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  switch (select_gtl_5F_module_5F_parser_4 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_else COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 175)) ;
    nt_gtl_5F_instruction_5F_list_parse (inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_end COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 179)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_if COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 180)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_module_5F_parser::rule_gtl_5F_module_5F_parser_gtl_5F_instruction_i6_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                           C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  GALGAS_gtlInstructionList var_beforeList_5278 = GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_module_parser.galgas", 193)) ;
  GALGAS_gtlInstructionList var_doList_5324 ;
  GALGAS_gtlInstructionList var_betweenList_5358 = GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_module_parser.galgas", 195)) ;
  GALGAS_gtlInstructionList var_afterList_5403 = GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_module_parser.galgas", 196)) ;
  GALGAS_lstring var_indexName_5441 ;
  GALGAS_lstring var_variableName_5469 ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_foreach COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 200)) ;
  GALGAS_location var_where_5502 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 200)) ;
  GALGAS_lstring var_keyName_5547 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 201)) ;
  switch (select_gtl_5F_module_5F_parser_5 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 203)) ;
    var_variableName_5469 = inCompiler->synthetizedAttribute_tokenString () ;
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 203)) ;
  } break ;
  case 2: {
    var_variableName_5469 = var_keyName_5547 ;
    var_keyName_5547 = GALGAS_lstring::constructor_new (GALGAS_string::makeEmptyString (), var_where_5502  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 206)) ;
  } break ;
  default:
    break ;
  }
  switch (select_gtl_5F_module_5F_parser_6 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__28_ COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 209)) ;
    var_indexName_5441 = inCompiler->synthetizedAttribute_tokenString () ;
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 209)) ;
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__29_ COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 209)) ;
  } break ;
  case 2: {
    var_indexName_5441 = GALGAS_lstring::constructor_new (GALGAS_string ("INDEX"), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 211))  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 211)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_in COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 213)) ;
  GALGAS_gtlExpression var_iterable_5815 ;
  nt_gtl_5F_expression_ (var_iterable_5815, inCompiler) ;
  switch (select_gtl_5F_module_5F_parser_7 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_before COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 217)) ;
    nt_gtl_5F_instruction_5F_list_ (var_beforeList_5278, inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_do COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 221)) ;
  nt_gtl_5F_instruction_5F_list_ (var_doList_5324, inCompiler) ;
  switch (select_gtl_5F_module_5F_parser_8 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_between COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 225)) ;
    nt_gtl_5F_instruction_5F_list_ (var_betweenList_5358, inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  switch (select_gtl_5F_module_5F_parser_9 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_after COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 230)) ;
    nt_gtl_5F_instruction_5F_list_ (var_afterList_5403, inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_end COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 234)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_foreach COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 235)) ;
  outArgument_instruction = GALGAS_gtlForeachStatementInstruction::constructor_new (var_where_5502, function_signature (var_where_5502, inCompiler COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 239)), var_keyName_5547, var_variableName_5469, var_indexName_5441, var_iterable_5815, var_beforeList_5278, var_betweenList_5358, var_afterList_5403, var_doList_5324  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 237)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_module_5F_parser::rule_gtl_5F_module_5F_parser_gtl_5F_instruction_i6_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_foreach COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 200)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 201)) ;
  switch (select_gtl_5F_module_5F_parser_5 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 203)) ;
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 203)) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  switch (select_gtl_5F_module_5F_parser_6 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__28_ COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 209)) ;
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 209)) ;
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__29_ COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 209)) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_in COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 213)) ;
  nt_gtl_5F_expression_parse (inCompiler) ;
  switch (select_gtl_5F_module_5F_parser_7 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_before COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 217)) ;
    nt_gtl_5F_instruction_5F_list_parse (inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_do COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 221)) ;
  nt_gtl_5F_instruction_5F_list_parse (inCompiler) ;
  switch (select_gtl_5F_module_5F_parser_8 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_between COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 225)) ;
    nt_gtl_5F_instruction_5F_list_parse (inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  switch (select_gtl_5F_module_5F_parser_9 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_after COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 230)) ;
    nt_gtl_5F_instruction_5F_list_parse (inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_end COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 234)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_foreach COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 235)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_module_5F_parser::rule_gtl_5F_module_5F_parser_gtl_5F_instruction_i7_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                           C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  GALGAS_gtlInstructionList var_doList_6660 ;
  GALGAS_gtlInstructionList var_betweenList_6694 = GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_module_parser.galgas", 258)) ;
  GALGAS_gtlExpressionList var_iterable_6738 = GALGAS_gtlExpressionList::constructor_emptyList (SOURCE_FILE ("gtl_module_parser.galgas", 259)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_for COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 261)) ;
  GALGAS_location var_where_6781 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 261)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (gOption_gtl_5F_options_warnDeprecated.readProperty_value ()).boolEnum () ;
    if (kBoolTrue == test_0) {
      TC_Array <C_FixItDescription> fixItArray1 ;
      appendFixItActions (fixItArray1, kFixItReplace, GALGAS_string ("foreach var in @( expression, ..., expression )")) ;
      inCompiler->emitSemanticWarning (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 263)), GALGAS_string ("for var in expression, ..., expression is deprecated"), fixItArray1  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 263)) ;
    }
  }
  GALGAS_lstring var_variableName_7038 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 266)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_in COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 267)) ;
  bool repeatFlag_2 = true ;
  while (repeatFlag_2) {
    GALGAS_gtlExpression var_expression_7106 ;
    nt_gtl_5F_expression_ (var_expression_7106, inCompiler) ;
    var_iterable_6738.addAssign_operation (var_expression_7106  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 270)) ;
    switch (select_gtl_5F_module_5F_parser_10 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 272)) ;
    } break ;
    default:
      repeatFlag_2 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_do COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 275)) ;
  nt_gtl_5F_instruction_5F_list_ (var_doList_6660, inCompiler) ;
  switch (select_gtl_5F_module_5F_parser_11 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_between COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 279)) ;
    nt_gtl_5F_instruction_5F_list_ (var_betweenList_6694, inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_end COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 283)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_for COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 284)) ;
  outArgument_instruction = GALGAS_gtlForStatementInstruction::constructor_new (var_where_6781, function_signature (var_where_6781, inCompiler COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 287)), var_variableName_7038, var_iterable_6738, var_betweenList_6694, var_doList_6660  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 286)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_module_5F_parser::rule_gtl_5F_module_5F_parser_gtl_5F_instruction_i7_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_for COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 261)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 266)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_in COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 267)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    nt_gtl_5F_expression_parse (inCompiler) ;
    switch (select_gtl_5F_module_5F_parser_10 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 272)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_do COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 275)) ;
  nt_gtl_5F_instruction_5F_list_parse (inCompiler) ;
  switch (select_gtl_5F_module_5F_parser_11 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_between COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 279)) ;
    nt_gtl_5F_instruction_5F_list_parse (inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_end COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 283)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_for COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 284)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_module_5F_parser::rule_gtl_5F_module_5F_parser_gtl_5F_instruction_i8_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                           C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  GALGAS_gtlInstructionList var_beforeList_7737 = GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_module_parser.galgas", 297)) ;
  GALGAS_gtlInstructionList var_betweenList_7784 = GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_module_parser.galgas", 298)) ;
  GALGAS_gtlInstructionList var_afterList_7829 = GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_module_parser.galgas", 299)) ;
  GALGAS_sint_36__34_ var_direction_7862 = GALGAS_sint_36__34_ (int64_t (1LL)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_loop COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 302)) ;
  GALGAS_location var_where_7898 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 302)) ;
  GALGAS_gtlExpression var_step_7929 = GALGAS_gtlTerminal::constructor_new (var_where_7898, GALGAS_gtlInt::constructor_new (var_where_7898, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 305)), GALGAS_bigint ("1", inCompiler  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 305))  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 305))  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 304)) ;
  GALGAS_lstring var_variableName_8051 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 308)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_from COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 309)) ;
  GALGAS_gtlExpression var_start_8105 ;
  nt_gtl_5F_expression_ (var_start_8105, inCompiler) ;
  switch (select_gtl_5F_module_5F_parser_12 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_up COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 313)) ;
  } break ;
  case 3: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_down COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 315)) ;
    var_direction_7862 = GALGAS_sint_36__34_ (int64_t (-1LL)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_to COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 317)) ;
  GALGAS_gtlExpression var_stop_8217 ;
  nt_gtl_5F_expression_ (var_stop_8217, inCompiler) ;
  switch (select_gtl_5F_module_5F_parser_13 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_step COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 320)) ;
    nt_gtl_5F_expression_ (var_step_7929, inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  switch (select_gtl_5F_module_5F_parser_14 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_before COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 325)) ;
    nt_gtl_5F_instruction_5F_list_ (var_beforeList_7737, inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_do COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 329)) ;
  GALGAS_gtlInstructionList var_doList_8439 ;
  nt_gtl_5F_instruction_5F_list_ (var_doList_8439, inCompiler) ;
  switch (select_gtl_5F_module_5F_parser_15 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_between COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 333)) ;
    nt_gtl_5F_instruction_5F_list_ (var_betweenList_7784, inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  switch (select_gtl_5F_module_5F_parser_16 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_after COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 338)) ;
    nt_gtl_5F_instruction_5F_list_ (var_afterList_7829, inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_end COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 342)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_loop COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 343)) ;
  outArgument_instruction = GALGAS_gtlLoopStatementInstruction::constructor_new (var_where_7898, function_signature (var_where_7898, inCompiler COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 346)), var_variableName_8051, var_start_8105, var_stop_8217, var_step_7929, var_direction_7862, var_beforeList_7737, var_betweenList_7784, var_afterList_7829, var_doList_8439  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 345)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_module_5F_parser::rule_gtl_5F_module_5F_parser_gtl_5F_instruction_i8_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_loop COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 302)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 308)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_from COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 309)) ;
  nt_gtl_5F_expression_parse (inCompiler) ;
  switch (select_gtl_5F_module_5F_parser_12 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_up COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 313)) ;
  } break ;
  case 3: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_down COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 315)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_to COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 317)) ;
  nt_gtl_5F_expression_parse (inCompiler) ;
  switch (select_gtl_5F_module_5F_parser_13 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_step COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 320)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  switch (select_gtl_5F_module_5F_parser_14 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_before COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 325)) ;
    nt_gtl_5F_instruction_5F_list_parse (inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_do COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 329)) ;
  nt_gtl_5F_instruction_5F_list_parse (inCompiler) ;
  switch (select_gtl_5F_module_5F_parser_15 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_between COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 333)) ;
    nt_gtl_5F_instruction_5F_list_parse (inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  switch (select_gtl_5F_module_5F_parser_16 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_after COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 338)) ;
    nt_gtl_5F_instruction_5F_list_parse (inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_end COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 342)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_loop COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 343)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_module_5F_parser::rule_gtl_5F_module_5F_parser_gtl_5F_instruction_i9_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                           C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  GALGAS_gtlExpression var_limit_9095 ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_repeat COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 359)) ;
  GALGAS_location var_where_9129 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 359)) ;
  switch (select_gtl_5F_module_5F_parser_17 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__28_ COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 361)) ;
    nt_gtl_5F_expression_ (var_limit_9095, inCompiler) ;
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__29_ COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 363)) ;
  } break ;
  case 2: {
    var_limit_9095 = GALGAS_gtlTerminal::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 366)), GALGAS_gtlInt::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 367)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 367)), GALGAS_uint::constructor_max (SOURCE_FILE ("gtl_module_parser.galgas", 367)).getter_bigint (SOURCE_FILE ("gtl_module_parser.galgas", 367))  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 367))  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 365)) ;
  } break ;
  default:
    break ;
  }
  GALGAS_gtlInstructionList var_continueList_9381 ;
  nt_gtl_5F_instruction_5F_list_ (var_continueList_9381, inCompiler) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_while COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 371)) ;
  GALGAS_gtlExpression var_condition_9440 ;
  nt_gtl_5F_expression_ (var_condition_9440, inCompiler) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_do COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 373)) ;
  GALGAS_gtlInstructionList var_doList_9504 ;
  nt_gtl_5F_instruction_5F_list_ (var_doList_9504, inCompiler) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_end COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 375)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_repeat COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 376)) ;
  outArgument_instruction = GALGAS_gtlRepeatStatementInstruction::constructor_new (var_where_9129, function_signature (var_where_9129, inCompiler COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 379)), var_limit_9095, var_condition_9440, var_continueList_9381, var_doList_9504  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 378)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_module_5F_parser::rule_gtl_5F_module_5F_parser_gtl_5F_instruction_i9_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_repeat COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 359)) ;
  switch (select_gtl_5F_module_5F_parser_17 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__28_ COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 361)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__29_ COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 363)) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  nt_gtl_5F_instruction_5F_list_parse (inCompiler) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_while COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 371)) ;
  nt_gtl_5F_expression_parse (inCompiler) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_do COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 373)) ;
  nt_gtl_5F_instruction_5F_list_parse (inCompiler) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_end COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 375)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_repeat COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 376)) ;
  inCompiler->resetTemplateString () ;
}



//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i0_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_let COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 43)) ;
  GALGAS_location var_where_1054 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 43)) ;
  GALGAS_gtlVarPath var_variable_1105 ;
  nt_gtl_5F_variable_ (var_variable_1105, inCompiler) ;
  switch (select_gtl_5F_instruction_5F_parser_0 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__3A__3D_ COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 46)) ;
    GALGAS_gtlExpression var_expression_1175 ;
    nt_gtl_5F_expression_ (var_expression_1175, inCompiler) ;
    outArgument_instruction = GALGAS_gtlLetInstruction::constructor_new (var_where_1054, function_signature (var_where_1054, inCompiler COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 50)), var_variable_1105, var_expression_1175  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 48)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__2B__3D_ COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 55)) ;
    GALGAS_gtlExpression var_expression_1364 ;
    nt_gtl_5F_expression_ (var_expression_1364, inCompiler) ;
    outArgument_instruction = GALGAS_gtlLetAddInstruction::constructor_new (var_where_1054, function_signature (var_where_1054, inCompiler COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 59)), var_variable_1105, var_expression_1364  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 57)) ;
  } break ;
  case 3: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__2D__3D_ COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 64)) ;
    GALGAS_gtlExpression var_expression_1555 ;
    nt_gtl_5F_expression_ (var_expression_1555, inCompiler) ;
    outArgument_instruction = GALGAS_gtlLetSubstractInstruction::constructor_new (var_where_1054, function_signature (var_where_1054, inCompiler COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 68)), var_variable_1105, var_expression_1555  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 66)) ;
  } break ;
  case 4: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__2A__3D_ COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 73)) ;
    GALGAS_gtlExpression var_expression_1752 ;
    nt_gtl_5F_expression_ (var_expression_1752, inCompiler) ;
    outArgument_instruction = GALGAS_gtlLetMultiplyInstruction::constructor_new (var_where_1054, function_signature (var_where_1054, inCompiler COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 77)), var_variable_1105, var_expression_1752  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 75)) ;
  } break ;
  case 5: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__2F__3D_ COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 82)) ;
    GALGAS_gtlExpression var_expression_1948 ;
    nt_gtl_5F_expression_ (var_expression_1948, inCompiler) ;
    outArgument_instruction = GALGAS_gtlLetDivideInstruction::constructor_new (var_where_1054, function_signature (var_where_1054, inCompiler COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 86)), var_variable_1105, var_expression_1948  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 84)) ;
  } break ;
  case 6: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_mod_3D_ COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 91)) ;
    GALGAS_gtlExpression var_expression_2144 ;
    nt_gtl_5F_expression_ (var_expression_2144, inCompiler) ;
    outArgument_instruction = GALGAS_gtlLetModuloInstruction::constructor_new (var_where_1054, function_signature (var_where_1054, inCompiler COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 95)), var_variable_1105, var_expression_2144  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 93)) ;
  } break ;
  case 7: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__3C__3C__3D_ COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 100)) ;
    GALGAS_gtlExpression var_expression_2339 ;
    nt_gtl_5F_expression_ (var_expression_2339, inCompiler) ;
    outArgument_instruction = GALGAS_gtlLetShiftLeftInstruction::constructor_new (var_where_1054, function_signature (var_where_1054, inCompiler COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 104)), var_variable_1105, var_expression_2339  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 102)) ;
  } break ;
  case 8: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__3E__3E__3D_ COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 109)) ;
    GALGAS_gtlExpression var_expression_2537 ;
    nt_gtl_5F_expression_ (var_expression_2537, inCompiler) ;
    outArgument_instruction = GALGAS_gtlLetShiftRightInstruction::constructor_new (var_where_1054, function_signature (var_where_1054, inCompiler COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 113)), var_variable_1105, var_expression_2537  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 111)) ;
  } break ;
  case 9: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__26__3D_ COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 118)) ;
    GALGAS_gtlExpression var_expression_2735 ;
    nt_gtl_5F_expression_ (var_expression_2735, inCompiler) ;
    outArgument_instruction = GALGAS_gtlLetAndInstruction::constructor_new (var_where_1054, function_signature (var_where_1054, inCompiler COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 122)), var_variable_1105, var_expression_2735  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 120)) ;
  } break ;
  case 10: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__7C__3D_ COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 127)) ;
    GALGAS_gtlExpression var_expression_2926 ;
    nt_gtl_5F_expression_ (var_expression_2926, inCompiler) ;
    outArgument_instruction = GALGAS_gtlLetOrInstruction::constructor_new (var_where_1054, function_signature (var_where_1054, inCompiler COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 131)), var_variable_1105, var_expression_2926  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 129)) ;
  } break ;
  case 11: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__5E__3D_ COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 136)) ;
    GALGAS_gtlExpression var_expression_3116 ;
    nt_gtl_5F_expression_ (var_expression_3116, inCompiler) ;
    outArgument_instruction = GALGAS_gtlLetXorInstruction::constructor_new (var_where_1054, function_signature (var_where_1054, inCompiler COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 140)), var_variable_1105, var_expression_3116  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 138)) ;
  } break ;
  case 12: {
    outArgument_instruction = GALGAS_gtlLetUnconstructedInstruction::constructor_new (var_where_1054, function_signature (var_where_1054, inCompiler COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 147)), var_variable_1105  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 145)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i0_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_let COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 43)) ;
  nt_gtl_5F_variable_parse (inCompiler) ;
  switch (select_gtl_5F_instruction_5F_parser_0 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__3A__3D_ COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 46)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__2B__3D_ COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 55)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
  } break ;
  case 3: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__2D__3D_ COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 64)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
  } break ;
  case 4: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__2A__3D_ COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 73)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
  } break ;
  case 5: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__2F__3D_ COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 82)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
  } break ;
  case 6: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_mod_3D_ COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 91)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
  } break ;
  case 7: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__3C__3C__3D_ COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 100)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
  } break ;
  case 8: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__3E__3E__3D_ COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 109)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
  } break ;
  case 9: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__26__3D_ COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 118)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
  } break ;
  case 10: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__7C__3D_ COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 127)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
  } break ;
  case 11: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__5E__3D_ COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 136)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
  } break ;
  case 12: {
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i1_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_unlet COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 157)) ;
  GALGAS_location var_where_3543 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 157)) ;
  GALGAS_gtlVarPath var_variable_3594 ;
  nt_gtl_5F_variable_ (var_variable_3594, inCompiler) ;
  outArgument_instruction = GALGAS_gtlUnletInstruction::constructor_new (var_where_3543, function_signature (var_where_3543, inCompiler COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 161)), var_variable_3594  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 159)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i1_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_unlet COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 157)) ;
  nt_gtl_5F_variable_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i2_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_error COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 170)) ;
  GALGAS_location var_where_3865 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 170)) ;
  GALGAS_gtlVarPath var_variable_3924 ;
  GALGAS_bool var_hereInstead_3947 ;
  nt_gtl_5F_variable_5F_or_5F_here_ (var_variable_3924, var_hereInstead_3947, inCompiler) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__3A_ COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 172)) ;
  GALGAS_gtlExpression var_expression_4003 ;
  nt_gtl_5F_expression_ (var_expression_4003, inCompiler) ;
  outArgument_instruction = GALGAS_gtlErrorStatementInstruction::constructor_new (var_where_3865, function_signature (var_where_3865, inCompiler COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 177)), var_variable_3924, var_hereInstead_3947, var_expression_4003  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 175)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i2_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_error COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 170)) ;
  nt_gtl_5F_variable_5F_or_5F_here_parse (inCompiler) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__3A_ COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 172)) ;
  nt_gtl_5F_expression_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i3_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_warning COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 188)) ;
  GALGAS_location var_where_4321 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 188)) ;
  GALGAS_gtlVarPath var_variable_4380 ;
  GALGAS_bool var_hereInstead_4403 ;
  nt_gtl_5F_variable_5F_or_5F_here_ (var_variable_4380, var_hereInstead_4403, inCompiler) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__3A_ COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 190)) ;
  GALGAS_gtlExpression var_expression_4459 ;
  nt_gtl_5F_expression_ (var_expression_4459, inCompiler) ;
  outArgument_instruction = GALGAS_gtlWarningStatementInstruction::constructor_new (var_where_4321, function_signature (var_where_4321, inCompiler COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 195)), var_variable_4380, var_hereInstead_4403, var_expression_4459  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 193)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i3_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_warning COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 188)) ;
  nt_gtl_5F_variable_5F_or_5F_here_parse (inCompiler) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__3A_ COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 190)) ;
  nt_gtl_5F_expression_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i4_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_print COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 206)) ;
  GALGAS_location var_where_4775 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 206)) ;
  GALGAS_gtlExpression var_expression_4833 ;
  nt_gtl_5F_expression_ (var_expression_4833, inCompiler) ;
  outArgument_instruction = GALGAS_gtlPrintStatementInstruction::constructor_new (var_where_4775, function_signature (var_where_4775, inCompiler COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 211)), GALGAS_bool (false), var_expression_4833  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 209)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i4_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_print COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 206)) ;
  nt_gtl_5F_expression_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i5_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_println COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 221)) ;
  GALGAS_location var_where_5129 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 221)) ;
  switch (select_gtl_5F_instruction_5F_parser_1 (inCompiler)) {
  case 1: {
    GALGAS_gtlExpression var_expression_5198 ;
    nt_gtl_5F_expression_ (var_expression_5198, inCompiler) ;
    outArgument_instruction = GALGAS_gtlPrintStatementInstruction::constructor_new (var_where_5129, function_signature (var_where_5129, inCompiler COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 226)), GALGAS_bool (true), var_expression_5198  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 224)) ;
  } break ;
  case 2: {
    outArgument_instruction = GALGAS_gtlPrintStatementInstruction::constructor_new (var_where_5129, function_signature (var_where_5129, inCompiler COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 233)), GALGAS_bool (true), GALGAS_gtlTerminal::constructor_new (var_where_5129, GALGAS_gtlString::constructor_new (var_where_5129, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 235)), GALGAS_string::makeEmptyString ()  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 235))  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 235))  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 231)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i5_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_println COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 221)) ;
  switch (select_gtl_5F_instruction_5F_parser_1 (inCompiler)) {
  case 1: {
    nt_gtl_5F_expression_parse (inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i6_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_display COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 244)) ;
  GALGAS_location var_where_5712 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 244)) ;
  GALGAS_gtlVarPath var_variable_5766 ;
  nt_gtl_5F_variable_ (var_variable_5766, inCompiler) ;
  outArgument_instruction = GALGAS_gtlDisplayStatementInstruction::constructor_new (var_where_5712, function_signature (var_where_5712, inCompiler COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 250)), var_variable_5766  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 248)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i6_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_display COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 244)) ;
  nt_gtl_5F_variable_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i7_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_sort COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 259)) ;
  GALGAS_location var_where_6048 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 259)) ;
  GALGAS_gtlVarPath var_variable_6099 ;
  nt_gtl_5F_variable_ (var_variable_6099, inCompiler) ;
  switch (select_gtl_5F_instruction_5F_parser_2 (inCompiler)) {
  case 1: {
    GALGAS_sortingKeyList var_sortList_6137 = GALGAS_sortingKeyList::constructor_emptyList (SOURCE_FILE ("gtl_instruction_parser.galgas", 262)) ;
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_by COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 263)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      GALGAS_lstring var_key_6207 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 265)) ;
      GALGAS_lsint var_order_6251 ;
      nt_gtl_5F_sorting_5F_order_ (var_order_6251, inCompiler) ;
      var_sortList_6137.addAssign_operation (var_key_6207, var_order_6251  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 267)) ;
      switch (select_gtl_5F_instruction_5F_parser_3 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 268)) ;
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
    outArgument_instruction = GALGAS_gtlSortStatementStructInstruction::constructor_new (var_where_6048, function_signature (var_where_6048, inCompiler COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 272)), var_variable_6099, var_sortList_6137  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 270)) ;
  } break ;
  case 2: {
    GALGAS_lsint var_order_6491 ;
    nt_gtl_5F_sorting_5F_order_ (var_order_6491, inCompiler) ;
    outArgument_instruction = GALGAS_gtlSortStatementInstruction::constructor_new (var_where_6048, function_signature (var_where_6048, inCompiler COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 281)), var_variable_6099, var_order_6491  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 279)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i7_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_sort COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 259)) ;
  nt_gtl_5F_variable_parse (inCompiler) ;
  switch (select_gtl_5F_instruction_5F_parser_2 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_by COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 263)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 265)) ;
      nt_gtl_5F_sorting_5F_order_parse (inCompiler) ;
      switch (select_gtl_5F_instruction_5F_parser_3 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 268)) ;
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
  } break ;
  case 2: {
    nt_gtl_5F_sorting_5F_order_parse (inCompiler) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i8_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_tab COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 292)) ;
  GALGAS_location var_where_6802 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 292)) ;
  GALGAS_gtlExpression var_expression_6860 ;
  nt_gtl_5F_expression_ (var_expression_6860, inCompiler) ;
  outArgument_instruction = GALGAS_gtlTabStatementInstruction::constructor_new (var_where_6802, function_signature (var_where_6802, inCompiler COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 297)), var_expression_6860  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 295)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i8_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_tab COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 292)) ;
  nt_gtl_5F_expression_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i9_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_variables COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 306)) ;
  GALGAS_location var_where_7149 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 306)) ;
  outArgument_instruction = GALGAS_gtlVariablesInstruction::constructor_new (var_where_7149, function_signature (var_where_7149, inCompiler COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 309)), GALGAS_bool (false)  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 307)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i9_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_variables COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 306)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i10_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                                                C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_libraries COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 318)) ;
  GALGAS_location var_where_7433 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 318)) ;
  outArgument_instruction = GALGAS_gtlLibrariesInstruction::constructor_new (var_where_7433, function_signature (var_where_7433, inCompiler COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 321))  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 319)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i10_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_libraries COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 318)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i11_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                                                C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__5B__21_ COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 329)) ;
  GALGAS_gtlVarPath var_target_7721 ;
  nt_gtl_5F_variable_ (var_target_7721, inCompiler) ;
  GALGAS_lstring var_setterName_7761 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 331)) ;
  GALGAS_location var_where_7783 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 332)) ;
  GALGAS_gtlExpressionList var_argumentList_7825 = GALGAS_gtlExpressionList::constructor_emptyList (SOURCE_FILE ("gtl_instruction_parser.galgas", 333)) ;
  switch (select_gtl_5F_instruction_5F_parser_4 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__3A_ COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 336)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      GALGAS_gtlExpression var_argument_7923 ;
      nt_gtl_5F_expression_ (var_argument_7923, inCompiler) ;
      var_argumentList_7825.addAssign_operation (var_argument_7923  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 339)) ;
      switch (select_gtl_5F_instruction_5F_parser_5 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 341)) ;
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__5D_ COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 344)) ;
  outArgument_instruction = GALGAS_gtlSetterCallInstruction::constructor_new (var_where_7783, function_signature (var_where_7783, inCompiler COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 347)), var_target_7721, var_setterName_7761, var_argumentList_7825  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 345)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i11_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__5B__21_ COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 329)) ;
  nt_gtl_5F_variable_parse (inCompiler) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 331)) ;
  switch (select_gtl_5F_instruction_5F_parser_4 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__3A_ COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 336)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      nt_gtl_5F_expression_parse (inCompiler) ;
      switch (select_gtl_5F_instruction_5F_parser_5 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 341)) ;
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__5D_ COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 344)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_sorting_5F_order_i12_ (GALGAS_lsint & outArgument_order,
                                                                                                           C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_order.drop () ; // Release 'out' argument
  switch (select_gtl_5F_instruction_5F_parser_6 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 359)) ;
    outArgument_order = GALGAS_lsint::constructor_new (GALGAS_sint (int32_t (-1L)), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 360))  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 360)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__3C_ COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 362)) ;
    outArgument_order = GALGAS_lsint::constructor_new (GALGAS_sint (int32_t (1L)), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 363))  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 363)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_sorting_5F_order_i12_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  switch (select_gtl_5F_instruction_5F_parser_6 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 359)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__3C_ COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 362)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_import_i13_ (GALGAS_gtlContext inArgument_context,
                                                                                                 GALGAS_library & ioArgument_lib,
                                                                                                 C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_import COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 372)) ;
  GALGAS_lstring var_fileName_8572 = inCompiler->synthetizedAttribute_a_5F_string () ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_string COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 372)) ;
  GALGAS_string var_fullName_8591 = var_fileName_8572.readProperty_string () ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsNotEqual, var_fullName_8591.getter_pathExtension (SOURCE_FILE ("gtl_instruction_parser.galgas", 374)).objectCompare (GALGAS_string ("gtm"))).boolEnum () ;
    if (kBoolTrue == test_0) {
      var_fullName_8591 = var_fileName_8572.readProperty_string ().add_operation (GALGAS_string (".gtm"), inCompiler COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 375)) ;
    }
  }
  GALGAS_bool var_found_8720 = GALGAS_bool (false) ;
  enumGalgasBool test_1 = kBoolTrue ;
  if (kBoolTrue == test_1) {
    test_1 = var_fullName_8591.getter_fileExists (SOURCE_FILE ("gtl_instruction_parser.galgas", 379)).operator_not (SOURCE_FILE ("gtl_instruction_parser.galgas", 379)).boolEnum () ;
    if (kBoolTrue == test_1) {
      cEnumerator_stringlist enumerator_8805 (inArgument_context.readProperty_importPath (), kENUMERATION_UP) ;
      while (enumerator_8805.hasCurrentObject ()) {
        enumGalgasBool test_2 = kBoolTrue ;
        if (kBoolTrue == test_2) {
          test_2 = var_found_8720.operator_not (SOURCE_FILE ("gtl_instruction_parser.galgas", 382)).boolEnum () ;
          if (kBoolTrue == test_2) {
            GALGAS_string var_name_8882 = extensionGetter_stringByAppendingPath (enumerator_8805.current_mValue (HERE), var_fullName_8591, inCompiler COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 383)) ;
            enumGalgasBool test_3 = kBoolTrue ;
            if (kBoolTrue == test_3) {
              test_3 = var_name_8882.getter_fileExists (SOURCE_FILE ("gtl_instruction_parser.galgas", 384)).boolEnum () ;
              if (kBoolTrue == test_3) {
                var_fullName_8591 = var_name_8882 ;
                var_found_8720 = GALGAS_bool (true) ;
              }
            }
          }
        }
        enumerator_8805.gotoNextObject () ;
      }
    }
  }
  if (kBoolFalse == test_1) {
    var_found_8720 = GALGAS_bool (true) ;
  }
  enumGalgasBool test_4 = kBoolTrue ;
  if (kBoolTrue == test_4) {
    test_4 = var_found_8720.boolEnum () ;
    if (kBoolTrue == test_4) {
      enumGalgasBool test_5 = kBoolTrue ;
      if (kBoolTrue == test_5) {
        test_5 = callExtensionGetter_hasImport ((const cPtr_library *) ioArgument_lib.ptr (), var_fullName_8591, inCompiler COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 395)).operator_not (SOURCE_FILE ("gtl_instruction_parser.galgas", 395)).boolEnum () ;
        if (kBoolTrue == test_5) {
          {
          ioArgument_lib.insulate (HERE) ;
          cPtr_library * ptr_9146 = (cPtr_library *) ioArgument_lib.ptr () ;
          callExtensionSetter_doImport ((cPtr_library *) ptr_9146, var_fullName_8591, inCompiler COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 396)) ;
          }
          cGrammar_gtl_5F_module_5F_grammar::_performSourceFileParsing_ (inCompiler, GALGAS_lstring::constructor_new (var_fullName_8591, var_fileName_8572.readProperty_location ()  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 398)), inArgument_context, ioArgument_lib  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 397)) ;
        }
      }
    }
  }
  if (kBoolFalse == test_4) {
    TC_Array <C_FixItDescription> fixItArray6 ;
    inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 401)), GALGAS_string ("module not found"), fixItArray6  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 401)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_import_i13_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_import COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 372)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_string COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 372)) ;
  inCompiler->resetTemplateString () ;
}



//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_start_5F_symbol_i0_ (GALGAS_gtlContext inArgument_context,
                                                                           GALGAS_library & ioArgument_lib,
                                                                           GALGAS_gtlInstructionList & outArgument_program,
                                                                           C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_program.drop () ; // Release 'out' argument
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_gtl_5F_parser_0 (inCompiler)) {
    case 2: {
      nt_gtl_5F_import_ (inArgument_context, ioArgument_lib, inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  nt_gtl_5F_template_5F_instruction_5F_list_ (outArgument_program, inCompiler) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_start_5F_symbol_i0_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_gtl_5F_parser_0 (inCompiler)) {
    case 2: {
      nt_gtl_5F_import_parse (inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  nt_gtl_5F_template_5F_instruction_5F_list_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_template_5F_instruction_5F_list_i1_ (GALGAS_gtlInstructionList & outArgument_instructionList,
                                                                                           C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instructionList.drop () ; // Release 'out' argument
  outArgument_instructionList = GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_parser.galgas", 65)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    GALGAS_string var_templateString_1565 = GALGAS_string::constructor_retrieveAndResetTemplateString (inCompiler  COMMA_SOURCE_FILE ("gtl_parser.galgas", 68)) ;
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = GALGAS_bool (kIsNotEqual, var_templateString_1565.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
      if (kBoolTrue == test_1) {
        outArgument_instructionList.addAssign_operation (GALGAS_gtlTemplateStringInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_parser.galgas", 72)), GALGAS_string::makeEmptyString (), var_templateString_1565  COMMA_SOURCE_FILE ("gtl_parser.galgas", 71))  COMMA_SOURCE_FILE ("gtl_parser.galgas", 70)) ;
      }
    }
    switch (select_gtl_5F_parser_1 (inCompiler)) {
    case 2: {
      GALGAS_gtlInstruction var_instruction_1856 ;
      nt_gtl_5F_template_5F_instruction_ (var_instruction_1856, inCompiler) ;
      outArgument_instructionList.addAssign_operation (var_instruction_1856  COMMA_SOURCE_FILE ("gtl_parser.galgas", 79)) ;
    } break ;
    case 3: {
      GALGAS_gtlInstruction var_instruction_1962 ;
      nt_gtl_5F_simple_5F_instruction_ (var_instruction_1962, inCompiler) ;
      outArgument_instructionList.addAssign_operation (var_instruction_1962  COMMA_SOURCE_FILE ("gtl_parser.galgas", 82)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_template_5F_instruction_5F_list_i1_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_gtl_5F_parser_1 (inCompiler)) {
    case 2: {
      nt_gtl_5F_template_5F_instruction_parse (inCompiler) ;
    } break ;
    case 3: {
      nt_gtl_5F_simple_5F_instruction_parse (inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i2_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                   C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__21_ COMMA_SOURCE_FILE ("gtl_parser.galgas", 92)) ;
  GALGAS_location var_where_2298 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_parser.galgas", 92)) ;
  GALGAS_gtlExpression var_expression_2356 ;
  nt_gtl_5F_expression_ (var_expression_2356, inCompiler) ;
  outArgument_instruction = GALGAS_gtlEmitInstruction::constructor_new (var_where_2298, function_signature (var_where_2298, inCompiler COMMA_SOURCE_FILE ("gtl_parser.galgas", 97)), var_expression_2356  COMMA_SOURCE_FILE ("gtl_parser.galgas", 95)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i2_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__21_ COMMA_SOURCE_FILE ("gtl_parser.galgas", 92)) ;
  nt_gtl_5F_expression_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i3_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                   C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  GALGAS_bool var_isExecutable_2790 = GALGAS_bool (false) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_write COMMA_SOURCE_FILE ("gtl_parser.galgas", 111)) ;
  GALGAS_location var_where_2828 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_parser.galgas", 111)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_to COMMA_SOURCE_FILE ("gtl_parser.galgas", 111)) ;
  switch (select_gtl_5F_parser_2 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_executable COMMA_SOURCE_FILE ("gtl_parser.galgas", 112)) ;
    var_isExecutable_2790 = GALGAS_bool (true) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  GALGAS_gtlExpression var_fileName_2938 ;
  nt_gtl_5F_expression_ (var_fileName_2938, inCompiler) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__3A_ COMMA_SOURCE_FILE ("gtl_parser.galgas", 114)) ;
  GALGAS_gtlInstructionList var_instructionList_3019 ;
  nt_gtl_5F_template_5F_instruction_5F_list_ (var_instructionList_3019, inCompiler) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_end COMMA_SOURCE_FILE ("gtl_parser.galgas", 116)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_write COMMA_SOURCE_FILE ("gtl_parser.galgas", 116)) ;
  outArgument_instruction = GALGAS_gtlWriteToInstruction::constructor_new (var_where_2828, function_signature (var_where_2828, inCompiler COMMA_SOURCE_FILE ("gtl_parser.galgas", 120)), var_fileName_2938, var_isExecutable_2790, var_instructionList_3019  COMMA_SOURCE_FILE ("gtl_parser.galgas", 118)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i3_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_write COMMA_SOURCE_FILE ("gtl_parser.galgas", 111)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_to COMMA_SOURCE_FILE ("gtl_parser.galgas", 111)) ;
  switch (select_gtl_5F_parser_2 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_executable COMMA_SOURCE_FILE ("gtl_parser.galgas", 112)) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  nt_gtl_5F_expression_parse (inCompiler) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__3A_ COMMA_SOURCE_FILE ("gtl_parser.galgas", 114)) ;
  nt_gtl_5F_template_5F_instruction_5F_list_parse (inCompiler) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_end COMMA_SOURCE_FILE ("gtl_parser.galgas", 116)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_write COMMA_SOURCE_FILE ("gtl_parser.galgas", 116)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i4_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                   C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  GALGAS_lstring var_prefix_3343 ;
  GALGAS_bool var_ifExists_3360 = GALGAS_bool (false) ;
  GALGAS_gtlInstructionList var_instructionList_3406 = GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_parser.galgas", 132)) ;
  GALGAS_gtlExpression var_fileName_3449 ;
  GALGAS_gtlExpressionList var_templateArguments_3488 = GALGAS_gtlExpressionList::constructor_emptyList (SOURCE_FILE ("gtl_parser.galgas", 134)) ;
  GALGAS_bool var_globalTemplate_3524 = GALGAS_bool (true) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_template COMMA_SOURCE_FILE ("gtl_parser.galgas", 137)) ;
  GALGAS_location var_where_3567 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_parser.galgas", 137)) ;
  switch (select_gtl_5F_parser_3 (inCompiler)) {
  case 1: {
    var_globalTemplate_3524 = GALGAS_bool (false) ;
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__28_ COMMA_SOURCE_FILE ("gtl_parser.galgas", 140)) ;
    switch (select_gtl_5F_parser_4 (inCompiler)) {
    case 1: {
      bool repeatFlag_0 = true ;
      while (repeatFlag_0) {
        GALGAS_gtlExpression var_expression_3699 ;
        nt_gtl_5F_expression_ (var_expression_3699, inCompiler) ;
        var_templateArguments_3488.addAssign_operation (var_expression_3699  COMMA_SOURCE_FILE ("gtl_parser.galgas", 144)) ;
        switch (select_gtl_5F_parser_5 (inCompiler)) {
        case 2: {
          inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("gtl_parser.galgas", 146)) ;
        } break ;
        default:
          repeatFlag_0 = false ;
          break ;
        }
      }
    } break ;
    case 2: {
    } break ;
    default:
      break ;
    }
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__29_ COMMA_SOURCE_FILE ("gtl_parser.galgas", 149)) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  switch (select_gtl_5F_parser_6 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_if COMMA_SOURCE_FILE ("gtl_parser.galgas", 153)) ;
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_exists COMMA_SOURCE_FILE ("gtl_parser.galgas", 153)) ;
    var_ifExists_3360 = GALGAS_bool (true) ;
    nt_gtl_5F_file_5F_name_ (var_fileName_3449, inCompiler) ;
    switch (select_gtl_5F_parser_7 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_in COMMA_SOURCE_FILE ("gtl_parser.galgas", 157)) ;
      var_prefix_3343 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_parser.galgas", 157)) ;
    } break ;
    case 2: {
      var_prefix_3343 = GALGAS_lstring::constructor_new (GALGAS_string::makeEmptyString (), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_parser.galgas", 158))  COMMA_SOURCE_FILE ("gtl_parser.galgas", 158)) ;
    } break ;
    default:
      break ;
    }
    switch (select_gtl_5F_parser_8 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_or COMMA_SOURCE_FILE ("gtl_parser.galgas", 160)) ;
      nt_gtl_5F_template_5F_instruction_5F_list_ (var_instructionList_3406, inCompiler) ;
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_end COMMA_SOURCE_FILE ("gtl_parser.galgas", 162)) ;
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_template COMMA_SOURCE_FILE ("gtl_parser.galgas", 162)) ;
    } break ;
    case 2: {
    } break ;
    default:
      break ;
    }
  } break ;
  case 2: {
    nt_gtl_5F_file_5F_name_ (var_fileName_3449, inCompiler) ;
    switch (select_gtl_5F_parser_9 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_in COMMA_SOURCE_FILE ("gtl_parser.galgas", 167)) ;
      var_prefix_3343 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_parser.galgas", 167)) ;
    } break ;
    case 2: {
      var_prefix_3343 = GALGAS_lstring::constructor_new (GALGAS_string::makeEmptyString (), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_parser.galgas", 168))  COMMA_SOURCE_FILE ("gtl_parser.galgas", 168)) ;
    } break ;
    default:
      break ;
    }
  } break ;
  default:
    break ;
  }
  outArgument_instruction = GALGAS_gtlTemplateInstruction::constructor_new (var_where_3567, function_signature (var_where_3567, inCompiler COMMA_SOURCE_FILE ("gtl_parser.galgas", 172)), var_prefix_3343, var_fileName_3449, var_ifExists_3360, var_globalTemplate_3524, var_templateArguments_3488, var_instructionList_3406  COMMA_SOURCE_FILE ("gtl_parser.galgas", 170)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i4_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_template COMMA_SOURCE_FILE ("gtl_parser.galgas", 137)) ;
  switch (select_gtl_5F_parser_3 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__28_ COMMA_SOURCE_FILE ("gtl_parser.galgas", 140)) ;
    switch (select_gtl_5F_parser_4 (inCompiler)) {
    case 1: {
      bool repeatFlag_0 = true ;
      while (repeatFlag_0) {
        nt_gtl_5F_expression_parse (inCompiler) ;
        switch (select_gtl_5F_parser_5 (inCompiler)) {
        case 2: {
          inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("gtl_parser.galgas", 146)) ;
        } break ;
        default:
          repeatFlag_0 = false ;
          break ;
        }
      }
    } break ;
    case 2: {
    } break ;
    default:
      break ;
    }
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__29_ COMMA_SOURCE_FILE ("gtl_parser.galgas", 149)) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  switch (select_gtl_5F_parser_6 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_if COMMA_SOURCE_FILE ("gtl_parser.galgas", 153)) ;
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_exists COMMA_SOURCE_FILE ("gtl_parser.galgas", 153)) ;
    nt_gtl_5F_file_5F_name_parse (inCompiler) ;
    switch (select_gtl_5F_parser_7 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_in COMMA_SOURCE_FILE ("gtl_parser.galgas", 157)) ;
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_parser.galgas", 157)) ;
    } break ;
    case 2: {
    } break ;
    default:
      break ;
    }
    switch (select_gtl_5F_parser_8 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_or COMMA_SOURCE_FILE ("gtl_parser.galgas", 160)) ;
      nt_gtl_5F_template_5F_instruction_5F_list_parse (inCompiler) ;
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_end COMMA_SOURCE_FILE ("gtl_parser.galgas", 162)) ;
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_template COMMA_SOURCE_FILE ("gtl_parser.galgas", 162)) ;
    } break ;
    case 2: {
    } break ;
    default:
      break ;
    }
  } break ;
  case 2: {
    nt_gtl_5F_file_5F_name_parse (inCompiler) ;
    switch (select_gtl_5F_parser_9 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_in COMMA_SOURCE_FILE ("gtl_parser.galgas", 167)) ;
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_parser.galgas", 167)) ;
    } break ;
    case 2: {
    } break ;
    default:
      break ;
    }
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i5_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                   C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__3F_ COMMA_SOURCE_FILE ("gtl_parser.galgas", 185)) ;
  GALGAS_location var_where_4577 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_parser.galgas", 185)) ;
  GALGAS_gtlVarPath var_columnConstantName_4638 ;
  nt_gtl_5F_variable_ (var_columnConstantName_4638, inCompiler) ;
  outArgument_instruction = GALGAS_gtlGetColumnInstruction::constructor_new (var_where_4577, function_signature (var_where_4577, inCompiler COMMA_SOURCE_FILE ("gtl_parser.galgas", 190)), var_columnConstantName_4638  COMMA_SOURCE_FILE ("gtl_parser.galgas", 188)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i5_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__3F_ COMMA_SOURCE_FILE ("gtl_parser.galgas", 185)) ;
  nt_gtl_5F_variable_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i6_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                   C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  GALGAS_gtlThenElsifStatementList var_thenElsifList_4939 = GALGAS_gtlThenElsifStatementList::constructor_emptyList (SOURCE_FILE ("gtl_parser.galgas", 198)) ;
  GALGAS_gtlInstructionList var_elseList_4983 = GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_parser.galgas", 199)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_if COMMA_SOURCE_FILE ("gtl_parser.galgas", 201)) ;
  GALGAS_location var_where_5026 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_parser.galgas", 201)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    GALGAS_gtlExpression var_condition_5094 ;
    nt_gtl_5F_expression_ (var_condition_5094, inCompiler) ;
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_then COMMA_SOURCE_FILE ("gtl_parser.galgas", 204)) ;
    GALGAS_gtlInstructionList var_instructionList_5182 ;
    nt_gtl_5F_template_5F_instruction_5F_list_ (var_instructionList_5182, inCompiler) ;
    var_thenElsifList_4939.addAssign_operation (var_condition_5094, var_instructionList_5182  COMMA_SOURCE_FILE ("gtl_parser.galgas", 207)) ;
    switch (select_gtl_5F_parser_10 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_elsif COMMA_SOURCE_FILE ("gtl_parser.galgas", 209)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  switch (select_gtl_5F_parser_11 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_else COMMA_SOURCE_FILE ("gtl_parser.galgas", 213)) ;
    nt_gtl_5F_template_5F_instruction_5F_list_ (var_elseList_4983, inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_end COMMA_SOURCE_FILE ("gtl_parser.galgas", 217)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_if COMMA_SOURCE_FILE ("gtl_parser.galgas", 218)) ;
  outArgument_instruction = GALGAS_gtlIfStatementInstruction::constructor_new (var_where_5026, function_signature (var_where_5026, inCompiler COMMA_SOURCE_FILE ("gtl_parser.galgas", 222)), var_thenElsifList_4939, var_elseList_4983  COMMA_SOURCE_FILE ("gtl_parser.galgas", 220)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i6_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_if COMMA_SOURCE_FILE ("gtl_parser.galgas", 201)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    nt_gtl_5F_expression_parse (inCompiler) ;
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_then COMMA_SOURCE_FILE ("gtl_parser.galgas", 204)) ;
    nt_gtl_5F_template_5F_instruction_5F_list_parse (inCompiler) ;
    switch (select_gtl_5F_parser_10 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_elsif COMMA_SOURCE_FILE ("gtl_parser.galgas", 209)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  switch (select_gtl_5F_parser_11 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_else COMMA_SOURCE_FILE ("gtl_parser.galgas", 213)) ;
    nt_gtl_5F_template_5F_instruction_5F_list_parse (inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_end COMMA_SOURCE_FILE ("gtl_parser.galgas", 217)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_if COMMA_SOURCE_FILE ("gtl_parser.galgas", 218)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i7_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                   C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  GALGAS_gtlInstructionList var_beforeList_5665 = GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_parser.galgas", 230)) ;
  GALGAS_gtlInstructionList var_doList_5711 ;
  GALGAS_gtlInstructionList var_betweenList_5745 = GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_parser.galgas", 232)) ;
  GALGAS_gtlInstructionList var_afterList_5790 = GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_parser.galgas", 233)) ;
  GALGAS_lstring var_indexName_5828 ;
  GALGAS_lstring var_variableName_5856 ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_foreach COMMA_SOURCE_FILE ("gtl_parser.galgas", 237)) ;
  GALGAS_location var_where_5891 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_parser.galgas", 237)) ;
  GALGAS_lstring var_keyName_5936 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_parser.galgas", 238)) ;
  switch (select_gtl_5F_parser_12 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("gtl_parser.galgas", 240)) ;
    var_variableName_5856 = inCompiler->synthetizedAttribute_tokenString () ;
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_parser.galgas", 240)) ;
  } break ;
  case 2: {
    var_variableName_5856 = var_keyName_5936 ;
    var_keyName_5936 = GALGAS_lstring::constructor_new (GALGAS_string::makeEmptyString (), var_where_5891  COMMA_SOURCE_FILE ("gtl_parser.galgas", 243)) ;
  } break ;
  default:
    break ;
  }
  switch (select_gtl_5F_parser_13 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__28_ COMMA_SOURCE_FILE ("gtl_parser.galgas", 246)) ;
    var_indexName_5828 = inCompiler->synthetizedAttribute_tokenString () ;
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_parser.galgas", 246)) ;
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__29_ COMMA_SOURCE_FILE ("gtl_parser.galgas", 246)) ;
  } break ;
  case 2: {
    var_indexName_5828 = GALGAS_lstring::constructor_new (GALGAS_string ("INDEX"), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_parser.galgas", 248))  COMMA_SOURCE_FILE ("gtl_parser.galgas", 248)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_in COMMA_SOURCE_FILE ("gtl_parser.galgas", 250)) ;
  GALGAS_gtlExpression var_iterable_6204 ;
  nt_gtl_5F_expression_ (var_iterable_6204, inCompiler) ;
  switch (select_gtl_5F_parser_14 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_before COMMA_SOURCE_FILE ("gtl_parser.galgas", 254)) ;
    nt_gtl_5F_template_5F_instruction_5F_list_ (var_beforeList_5665, inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_do COMMA_SOURCE_FILE ("gtl_parser.galgas", 258)) ;
  nt_gtl_5F_template_5F_instruction_5F_list_ (var_doList_5711, inCompiler) ;
  switch (select_gtl_5F_parser_15 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_between COMMA_SOURCE_FILE ("gtl_parser.galgas", 262)) ;
    nt_gtl_5F_template_5F_instruction_5F_list_ (var_betweenList_5745, inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  switch (select_gtl_5F_parser_16 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_after COMMA_SOURCE_FILE ("gtl_parser.galgas", 267)) ;
    nt_gtl_5F_template_5F_instruction_5F_list_ (var_afterList_5790, inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_end COMMA_SOURCE_FILE ("gtl_parser.galgas", 271)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_foreach COMMA_SOURCE_FILE ("gtl_parser.galgas", 272)) ;
  outArgument_instruction = GALGAS_gtlForeachStatementInstruction::constructor_new (var_where_5891, function_signature (var_where_5891, inCompiler COMMA_SOURCE_FILE ("gtl_parser.galgas", 276)), var_keyName_5936, var_variableName_5856, var_indexName_5828, var_iterable_6204, var_beforeList_5665, var_betweenList_5745, var_afterList_5790, var_doList_5711  COMMA_SOURCE_FILE ("gtl_parser.galgas", 274)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i7_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_foreach COMMA_SOURCE_FILE ("gtl_parser.galgas", 237)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_parser.galgas", 238)) ;
  switch (select_gtl_5F_parser_12 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("gtl_parser.galgas", 240)) ;
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_parser.galgas", 240)) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  switch (select_gtl_5F_parser_13 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__28_ COMMA_SOURCE_FILE ("gtl_parser.galgas", 246)) ;
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_parser.galgas", 246)) ;
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__29_ COMMA_SOURCE_FILE ("gtl_parser.galgas", 246)) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_in COMMA_SOURCE_FILE ("gtl_parser.galgas", 250)) ;
  nt_gtl_5F_expression_parse (inCompiler) ;
  switch (select_gtl_5F_parser_14 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_before COMMA_SOURCE_FILE ("gtl_parser.galgas", 254)) ;
    nt_gtl_5F_template_5F_instruction_5F_list_parse (inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_do COMMA_SOURCE_FILE ("gtl_parser.galgas", 258)) ;
  nt_gtl_5F_template_5F_instruction_5F_list_parse (inCompiler) ;
  switch (select_gtl_5F_parser_15 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_between COMMA_SOURCE_FILE ("gtl_parser.galgas", 262)) ;
    nt_gtl_5F_template_5F_instruction_5F_list_parse (inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  switch (select_gtl_5F_parser_16 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_after COMMA_SOURCE_FILE ("gtl_parser.galgas", 267)) ;
    nt_gtl_5F_template_5F_instruction_5F_list_parse (inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_end COMMA_SOURCE_FILE ("gtl_parser.galgas", 271)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_foreach COMMA_SOURCE_FILE ("gtl_parser.galgas", 272)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i8_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                   C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  GALGAS_gtlInstructionList var_doList_6981 ;
  GALGAS_gtlInstructionList var_betweenList_7015 = GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_parser.galgas", 292)) ;
  GALGAS_gtlExpressionList var_iterable_7059 = GALGAS_gtlExpressionList::constructor_emptyList (SOURCE_FILE ("gtl_parser.galgas", 293)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_for COMMA_SOURCE_FILE ("gtl_parser.galgas", 295)) ;
  GALGAS_location var_where_7102 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_parser.galgas", 295)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (gOption_gtl_5F_options_warnDeprecated.readProperty_value ()).boolEnum () ;
    if (kBoolTrue == test_0) {
      TC_Array <C_FixItDescription> fixItArray1 ;
      appendFixItActions (fixItArray1, kFixItReplace, GALGAS_string ("foreach var in @( expression, ..., expression )")) ;
      inCompiler->emitSemanticWarning (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_parser.galgas", 297)), GALGAS_string ("for var in expression, ..., expression is deprecated"), fixItArray1  COMMA_SOURCE_FILE ("gtl_parser.galgas", 297)) ;
    }
  }
  GALGAS_lstring var_variableName_7359 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_parser.galgas", 300)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_in COMMA_SOURCE_FILE ("gtl_parser.galgas", 301)) ;
  bool repeatFlag_2 = true ;
  while (repeatFlag_2) {
    GALGAS_gtlExpression var_expression_7427 ;
    nt_gtl_5F_expression_ (var_expression_7427, inCompiler) ;
    var_iterable_7059.addAssign_operation (var_expression_7427  COMMA_SOURCE_FILE ("gtl_parser.galgas", 304)) ;
    switch (select_gtl_5F_parser_17 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("gtl_parser.galgas", 306)) ;
    } break ;
    default:
      repeatFlag_2 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_do COMMA_SOURCE_FILE ("gtl_parser.galgas", 309)) ;
  nt_gtl_5F_template_5F_instruction_5F_list_ (var_doList_6981, inCompiler) ;
  switch (select_gtl_5F_parser_18 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_between COMMA_SOURCE_FILE ("gtl_parser.galgas", 313)) ;
    nt_gtl_5F_template_5F_instruction_5F_list_ (var_betweenList_7015, inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_end COMMA_SOURCE_FILE ("gtl_parser.galgas", 317)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_for COMMA_SOURCE_FILE ("gtl_parser.galgas", 318)) ;
  outArgument_instruction = GALGAS_gtlForStatementInstruction::constructor_new (var_where_7102, function_signature (var_where_7102, inCompiler COMMA_SOURCE_FILE ("gtl_parser.galgas", 322)), var_variableName_7359, var_iterable_7059, var_betweenList_7015, var_doList_6981  COMMA_SOURCE_FILE ("gtl_parser.galgas", 320)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i8_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_for COMMA_SOURCE_FILE ("gtl_parser.galgas", 295)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_parser.galgas", 300)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_in COMMA_SOURCE_FILE ("gtl_parser.galgas", 301)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    nt_gtl_5F_expression_parse (inCompiler) ;
    switch (select_gtl_5F_parser_17 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__2C_ COMMA_SOURCE_FILE ("gtl_parser.galgas", 306)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_do COMMA_SOURCE_FILE ("gtl_parser.galgas", 309)) ;
  nt_gtl_5F_template_5F_instruction_5F_list_parse (inCompiler) ;
  switch (select_gtl_5F_parser_18 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_between COMMA_SOURCE_FILE ("gtl_parser.galgas", 313)) ;
    nt_gtl_5F_template_5F_instruction_5F_list_parse (inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_end COMMA_SOURCE_FILE ("gtl_parser.galgas", 317)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_for COMMA_SOURCE_FILE ("gtl_parser.galgas", 318)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i9_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                   C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  GALGAS_gtlInstructionList var_beforeList_7992 = GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_parser.galgas", 333)) ;
  GALGAS_gtlInstructionList var_betweenList_8039 = GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_parser.galgas", 334)) ;
  GALGAS_gtlInstructionList var_afterList_8084 = GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_parser.galgas", 335)) ;
  GALGAS_sint_36__34_ var_direction_8117 = GALGAS_sint_36__34_ (int64_t (1LL)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_loop COMMA_SOURCE_FILE ("gtl_parser.galgas", 338)) ;
  GALGAS_location var_where_8153 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_parser.galgas", 338)) ;
  GALGAS_gtlExpression var_step_8184 = GALGAS_gtlTerminal::constructor_new (var_where_8153, GALGAS_gtlInt::constructor_new (var_where_8153, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_parser.galgas", 341)), GALGAS_bigint ("1", inCompiler  COMMA_SOURCE_FILE ("gtl_parser.galgas", 341))  COMMA_SOURCE_FILE ("gtl_parser.galgas", 341))  COMMA_SOURCE_FILE ("gtl_parser.galgas", 340)) ;
  GALGAS_lstring var_variableName_8306 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_parser.galgas", 344)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_from COMMA_SOURCE_FILE ("gtl_parser.galgas", 345)) ;
  GALGAS_gtlExpression var_start_8360 ;
  nt_gtl_5F_expression_ (var_start_8360, inCompiler) ;
  switch (select_gtl_5F_parser_19 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_up COMMA_SOURCE_FILE ("gtl_parser.galgas", 349)) ;
  } break ;
  case 3: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_down COMMA_SOURCE_FILE ("gtl_parser.galgas", 351)) ;
    var_direction_8117 = GALGAS_sint_36__34_ (int64_t (-1LL)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_to COMMA_SOURCE_FILE ("gtl_parser.galgas", 353)) ;
  GALGAS_gtlExpression var_stop_8472 ;
  nt_gtl_5F_expression_ (var_stop_8472, inCompiler) ;
  switch (select_gtl_5F_parser_20 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_step COMMA_SOURCE_FILE ("gtl_parser.galgas", 356)) ;
    nt_gtl_5F_expression_ (var_step_8184, inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  switch (select_gtl_5F_parser_21 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_before COMMA_SOURCE_FILE ("gtl_parser.galgas", 361)) ;
    nt_gtl_5F_template_5F_instruction_5F_list_ (var_beforeList_7992, inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_do COMMA_SOURCE_FILE ("gtl_parser.galgas", 365)) ;
  GALGAS_gtlInstructionList var_doList_8712 ;
  nt_gtl_5F_template_5F_instruction_5F_list_ (var_doList_8712, inCompiler) ;
  switch (select_gtl_5F_parser_22 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_between COMMA_SOURCE_FILE ("gtl_parser.galgas", 369)) ;
    nt_gtl_5F_template_5F_instruction_5F_list_ (var_betweenList_8039, inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  switch (select_gtl_5F_parser_23 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_after COMMA_SOURCE_FILE ("gtl_parser.galgas", 374)) ;
    nt_gtl_5F_template_5F_instruction_5F_list_ (var_afterList_8084, inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_end COMMA_SOURCE_FILE ("gtl_parser.galgas", 378)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_loop COMMA_SOURCE_FILE ("gtl_parser.galgas", 379)) ;
  outArgument_instruction = GALGAS_gtlLoopStatementInstruction::constructor_new (var_where_8153, function_signature (var_where_8153, inCompiler COMMA_SOURCE_FILE ("gtl_parser.galgas", 383)), var_variableName_8306, var_start_8360, var_stop_8472, var_step_8184, var_direction_8117, var_beforeList_7992, var_betweenList_8039, var_afterList_8084, var_doList_8712  COMMA_SOURCE_FILE ("gtl_parser.galgas", 381)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i9_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_loop COMMA_SOURCE_FILE ("gtl_parser.galgas", 338)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_parser.galgas", 344)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_from COMMA_SOURCE_FILE ("gtl_parser.galgas", 345)) ;
  nt_gtl_5F_expression_parse (inCompiler) ;
  switch (select_gtl_5F_parser_19 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_up COMMA_SOURCE_FILE ("gtl_parser.galgas", 349)) ;
  } break ;
  case 3: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_down COMMA_SOURCE_FILE ("gtl_parser.galgas", 351)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_to COMMA_SOURCE_FILE ("gtl_parser.galgas", 353)) ;
  nt_gtl_5F_expression_parse (inCompiler) ;
  switch (select_gtl_5F_parser_20 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_step COMMA_SOURCE_FILE ("gtl_parser.galgas", 356)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  switch (select_gtl_5F_parser_21 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_before COMMA_SOURCE_FILE ("gtl_parser.galgas", 361)) ;
    nt_gtl_5F_template_5F_instruction_5F_list_parse (inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_do COMMA_SOURCE_FILE ("gtl_parser.galgas", 365)) ;
  nt_gtl_5F_template_5F_instruction_5F_list_parse (inCompiler) ;
  switch (select_gtl_5F_parser_22 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_between COMMA_SOURCE_FILE ("gtl_parser.galgas", 369)) ;
    nt_gtl_5F_template_5F_instruction_5F_list_parse (inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  switch (select_gtl_5F_parser_23 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_after COMMA_SOURCE_FILE ("gtl_parser.galgas", 374)) ;
    nt_gtl_5F_template_5F_instruction_5F_list_parse (inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_end COMMA_SOURCE_FILE ("gtl_parser.galgas", 378)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_loop COMMA_SOURCE_FILE ("gtl_parser.galgas", 379)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i10_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                    C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  GALGAS_gtlExpression var_limit_9317 ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_repeat COMMA_SOURCE_FILE ("gtl_parser.galgas", 401)) ;
  GALGAS_location var_where_9351 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_parser.galgas", 401)) ;
  switch (select_gtl_5F_parser_24 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__28_ COMMA_SOURCE_FILE ("gtl_parser.galgas", 403)) ;
    nt_gtl_5F_expression_ (var_limit_9317, inCompiler) ;
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__29_ COMMA_SOURCE_FILE ("gtl_parser.galgas", 405)) ;
  } break ;
  case 2: {
    var_limit_9317 = GALGAS_gtlTerminal::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_parser.galgas", 408)), GALGAS_gtlInt::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_parser.galgas", 408)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_parser.galgas", 408)), GALGAS_uint::constructor_max (SOURCE_FILE ("gtl_parser.galgas", 408)).getter_bigint (SOURCE_FILE ("gtl_parser.galgas", 408))  COMMA_SOURCE_FILE ("gtl_parser.galgas", 408))  COMMA_SOURCE_FILE ("gtl_parser.galgas", 407)) ;
  } break ;
  default:
    break ;
  }
  GALGAS_gtlInstructionList var_continueList_9606 ;
  nt_gtl_5F_template_5F_instruction_5F_list_ (var_continueList_9606, inCompiler) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_while COMMA_SOURCE_FILE ("gtl_parser.galgas", 412)) ;
  GALGAS_gtlExpression var_condition_9665 ;
  nt_gtl_5F_expression_ (var_condition_9665, inCompiler) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_do COMMA_SOURCE_FILE ("gtl_parser.galgas", 414)) ;
  GALGAS_gtlInstructionList var_doList_9738 ;
  nt_gtl_5F_template_5F_instruction_5F_list_ (var_doList_9738, inCompiler) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_end COMMA_SOURCE_FILE ("gtl_parser.galgas", 416)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_repeat COMMA_SOURCE_FILE ("gtl_parser.galgas", 417)) ;
  outArgument_instruction = GALGAS_gtlRepeatStatementInstruction::constructor_new (var_where_9351, function_signature (var_where_9351, inCompiler COMMA_SOURCE_FILE ("gtl_parser.galgas", 421)), var_limit_9317, var_condition_9665, var_continueList_9606, var_doList_9738  COMMA_SOURCE_FILE ("gtl_parser.galgas", 419)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i10_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_repeat COMMA_SOURCE_FILE ("gtl_parser.galgas", 401)) ;
  switch (select_gtl_5F_parser_24 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__28_ COMMA_SOURCE_FILE ("gtl_parser.galgas", 403)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken__29_ COMMA_SOURCE_FILE ("gtl_parser.galgas", 405)) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  nt_gtl_5F_template_5F_instruction_5F_list_parse (inCompiler) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_while COMMA_SOURCE_FILE ("gtl_parser.galgas", 412)) ;
  nt_gtl_5F_expression_parse (inCompiler) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_do COMMA_SOURCE_FILE ("gtl_parser.galgas", 414)) ;
  nt_gtl_5F_template_5F_instruction_5F_list_parse (inCompiler) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_end COMMA_SOURCE_FILE ("gtl_parser.galgas", 416)) ;
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_repeat COMMA_SOURCE_FILE ("gtl_parser.galgas", 417)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i11_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                    C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_input COMMA_SOURCE_FILE ("gtl_parser.galgas", 432)) ;
  GALGAS_location var_where_10083 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_parser.galgas", 432)) ;
  GALGAS_gtlArgumentList var_arguments_10145 ;
  nt_gtl_5F_argument_5F_list_ (var_arguments_10145, inCompiler) ;
  outArgument_instruction = GALGAS_gtlInputStatementInstruction::constructor_new (var_where_10083, function_signature (var_where_10083, inCompiler COMMA_SOURCE_FILE ("gtl_parser.galgas", 437)), var_arguments_10145  COMMA_SOURCE_FILE ("gtl_parser.galgas", 435)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i11_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_input COMMA_SOURCE_FILE ("gtl_parser.galgas", 432)) ;
  nt_gtl_5F_argument_5F_list_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_file_5F_name_i12_ (GALGAS_gtlExpression & outArgument_expression,
                                                                         C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  switch (select_gtl_5F_parser_25 (inCompiler)) {
  case 1: {
    GALGAS_lstring var_fileName_10437 = inCompiler->synthetizedAttribute_tokenString () ;
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_parser.galgas", 447)) ;
    outArgument_expression = GALGAS_gtlTerminal::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_parser.galgas", 449)), GALGAS_gtlString::constructor_new (var_fileName_10437.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_parser.galgas", 450)), var_fileName_10437.readProperty_string ()  COMMA_SOURCE_FILE ("gtl_parser.galgas", 449))  COMMA_SOURCE_FILE ("gtl_parser.galgas", 448)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_from COMMA_SOURCE_FILE ("gtl_parser.galgas", 454)) ;
    nt_gtl_5F_expression_ (outArgument_expression, inCompiler) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_file_5F_name_i12_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  switch (select_gtl_5F_parser_25 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_identifier COMMA_SOURCE_FILE ("gtl_parser.galgas", 447)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_gtl_5F_scanner::kToken_from COMMA_SOURCE_FILE ("gtl_parser.galgas", 454)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

