#include "galgas2/C_Compiler.h"
#include "galgas2/C_galgas_io.h"
#include "galgas2/C_galgas_CLI_Options.h"
#include "utilities/C_PrologueEpilogue.h"

//---------------------------------------------------------------------------------------------------------------------*

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

static const int16_t gProductions_goil_type_level_include [] = {
// At index 0 : <implementation_definition>, in file 'implementation_parser.ggs', line 55
  TERMINAL (C_Lexique_goil_5F_lexique::kToken_IMPLEMENTATION) // $IMPLEMENTATION$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (14) // <implementation_object_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, END_PRODUCTION
// At index 7 : <start>, in file 'goil_syntax.ggs', line 38
, NONTERMINAL (5) // <OIL_version>
, NONTERMINAL (2) // <file>
, END_PRODUCTION
// At index 10 : <file>, in file 'goil_syntax.ggs', line 110
, NONTERMINAL (36) // <select_goil_5F_syntax_0>
, END_PRODUCTION
// At index 12 : <sign>, in file 'goil_syntax.ggs', line 126
, NONTERMINAL (37) // <select_goil_5F_syntax_1>
, END_PRODUCTION
// At index 14 : <description>, in file 'goil_syntax.ggs', line 139
, NONTERMINAL (38) // <select_goil_5F_syntax_2>
, END_PRODUCTION
// At index 16 : <OIL_version>, in file 'goil_syntax.ggs', line 163
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_OIL_5F_VERSION) // $OIL_VERSION$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (4) // <description>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, END_PRODUCTION
// At index 22 : <application_definition>, in file 'goil_syntax.ggs', line 170
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_CPU) // $CPU$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (7) // <object_definition_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, NONTERMINAL (4) // <description>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, END_PRODUCTION
// At index 30 : <object_definition_list>, in file 'goil_syntax.ggs', line 184
, NONTERMINAL (40) // <select_goil_5F_syntax_4>
, END_PRODUCTION
// At index 32 : <boolean>, in file 'goil_syntax.ggs', line 234
, NONTERMINAL (41) // <select_goil_5F_syntax_5>
, END_PRODUCTION
// At index 34 : <oil_declaration_list>, in file 'goil_syntax.ggs', line 244
, NONTERMINAL (42) // <select_goil_5F_syntax_6>
, END_PRODUCTION
// At index 36 : <oil_declaration>, in file 'goil_syntax.ggs', line 256
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (43) // <select_goil_5F_syntax_7>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, END_PRODUCTION
// At index 40 : <include_file_level>, in file 'goil_syntax.ggs', line 451
, NONTERMINAL (48) // <select_goil_5F_syntax_12>
, NONTERMINAL (49) // <select_goil_5F_syntax_13>
, END_PRODUCTION
// At index 43 : <include_cpu_level>, in file 'goil_syntax.ggs', line 475
, NONTERMINAL (50) // <select_goil_5F_syntax_14>
, NONTERMINAL (51) // <select_goil_5F_syntax_15>
, END_PRODUCTION
// At index 46 : <include_object_level>, in file 'goil_syntax.ggs', line 499
, NONTERMINAL (52) // <select_goil_5F_syntax_16>
, NONTERMINAL (53) // <select_goil_5F_syntax_17>
, END_PRODUCTION
// At index 49 : <implementation_object_list>, in file 'implementation_parser.ggs', line 62
, NONTERMINAL (54) // <select_implementation_5F_parser_0>
, END_PRODUCTION
// At index 51 : <include_implementation_level>, in file 'implementation_parser.ggs', line 71
, NONTERMINAL (55) // <select_implementation_5F_parser_1>
, NONTERMINAL (56) // <select_implementation_5F_parser_2>
, END_PRODUCTION
// At index 54 : <include_type_level>, in file 'implementation_parser.ggs', line 92
, NONTERMINAL (57) // <select_implementation_5F_parser_3>
, NONTERMINAL (58) // <select_implementation_5F_parser_4>
, END_PRODUCTION
// At index 57 : <implementation_objects>, in file 'implementation_parser.ggs', line 135
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (59) // <select_implementation_5F_parser_5>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (18) // <implementation_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 63 : <implementation_list>, in file 'implementation_parser.ggs', line 183
, NONTERMINAL (60) // <select_implementation_5F_parser_6>
, END_PRODUCTION
// At index 65 : <implementation_type>, in file 'implementation_parser.ggs', line 261
, NONTERMINAL (61) // <select_implementation_5F_parser_7>
, END_PRODUCTION
// At index 67 : <struct_options>, in file 'implementation_parser.ggs', line 289
, NONTERMINAL (62) // <select_implementation_5F_parser_8>
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (33) // <multiple>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 72 : <objref_option>, in file 'implementation_parser.ggs', line 306
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (33) // <multiple>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 76 : <string_options>, in file 'implementation_parser.ggs', line 324
, NONTERMINAL (28) // <with_auto>
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (33) // <multiple>
, NONTERMINAL (63) // <select_implementation_5F_parser_9>
, END_PRODUCTION
// At index 81 : <boolean_options>, in file 'implementation_parser.ggs', line 361
, NONTERMINAL (28) // <with_auto>
, NONTERMINAL (65) // <select_implementation_5F_parser_11>
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (33) // <multiple>
, NONTERMINAL (68) // <select_implementation_5F_parser_14>
, END_PRODUCTION
// At index 87 : <enum_item>, in file 'implementation_parser.ggs', line 406
, NONTERMINAL (35) // <identifier_or_enum_value>
, NONTERMINAL (69) // <select_implementation_5F_parser_15>
, END_PRODUCTION
// At index 90 : <enum_options>, in file 'implementation_parser.ggs', line 419
, NONTERMINAL (28) // <with_auto>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) // $[$
, NONTERMINAL (24) // <enum_item>
, NONTERMINAL (70) // <select_implementation_5F_parser_16>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) // $]$
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (33) // <multiple>
, NONTERMINAL (71) // <select_implementation_5F_parser_17>
, END_PRODUCTION
// At index 99 : <number_options>, in file 'implementation_parser.ggs', line 466
, NONTERMINAL (28) // <with_auto>
, NONTERMINAL (32) // <range>
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (33) // <multiple>
, NONTERMINAL (73) // <select_implementation_5F_parser_19>
, END_PRODUCTION
// At index 105 : <type_options>, in file 'implementation_parser.ggs', line 505
, NONTERMINAL (28) // <with_auto>
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (33) // <multiple>
, NONTERMINAL (75) // <select_implementation_5F_parser_21>
, END_PRODUCTION
// At index 110 : <with_auto>, in file 'implementation_parser.ggs', line 544
, NONTERMINAL (77) // <select_implementation_5F_parser_23>
, END_PRODUCTION
// At index 112 : <int_or_float>, in file 'implementation_parser.ggs', line 553
, NONTERMINAL (3) // <sign>
, NONTERMINAL (78) // <select_implementation_5F_parser_24>
, END_PRODUCTION
// At index 115 : <set_followup>, in file 'implementation_parser.ggs', line 571
, NONTERMINAL (79) // <select_implementation_5F_parser_25>
, END_PRODUCTION
// At index 117 : <range_content>, in file 'implementation_parser.ggs', line 583
, NONTERMINAL (3) // <sign>
, NONTERMINAL (80) // <select_implementation_5F_parser_26>
, END_PRODUCTION
// At index 120 : <range>, in file 'implementation_parser.ggs', line 623
, NONTERMINAL (83) // <select_implementation_5F_parser_29>
, END_PRODUCTION
// At index 122 : <multiple>, in file 'implementation_parser.ggs', line 633
, NONTERMINAL (84) // <select_implementation_5F_parser_30>
, END_PRODUCTION
// At index 124 : <identifier_or_attribute>, in file 'implementation_parser.ggs', line 643
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, END_PRODUCTION
// At index 126 : <identifier_or_enum_value>, in file 'implementation_parser.ggs', line 648
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, END_PRODUCTION
//---- Added productions from 'select' and 'repeat' instructions
// At index 128 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
, END_PRODUCTION
// At index 129 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
, NONTERMINAL (11) // <include_file_level>
, NONTERMINAL (36) // <select_goil_5F_syntax_0>
, END_PRODUCTION
// At index 132 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
, NONTERMINAL (0) // <implementation_definition>
, NONTERMINAL (36) // <select_goil_5F_syntax_0>
, END_PRODUCTION
// At index 135 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
, NONTERMINAL (6) // <application_definition>
, NONTERMINAL (36) // <select_goil_5F_syntax_0>
, END_PRODUCTION
// At index 138 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2D_) // $-$
, END_PRODUCTION
// At index 140 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2B_) // $+$
, END_PRODUCTION
// At index 142 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
, END_PRODUCTION
// At index 143 : <select_goil_5F_syntax_2>, in file 'goil_syntax.ggs', line 140
, END_PRODUCTION
// At index 144 : <select_goil_5F_syntax_2>, in file 'goil_syntax.ggs', line 140
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3A_) // $:$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (39) // <select_goil_5F_syntax_3>
, END_PRODUCTION
// At index 148 : <select_goil_5F_syntax_3>, in file 'goil_syntax.ggs', line 147
, END_PRODUCTION
// At index 149 : <select_goil_5F_syntax_3>, in file 'goil_syntax.ggs', line 147
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (39) // <select_goil_5F_syntax_3>
, END_PRODUCTION
// At index 152 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
, END_PRODUCTION
// At index 153 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (9) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, NONTERMINAL (4) // <description>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, NONTERMINAL (40) // <select_goil_5F_syntax_4>
, END_PRODUCTION
// At index 162 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
, NONTERMINAL (12) // <include_cpu_level>
, NONTERMINAL (40) // <select_goil_5F_syntax_4>
, END_PRODUCTION
// At index 165 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 235
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_TRUE) // $TRUE$
, END_PRODUCTION
// At index 167 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 235
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_FALSE) // $FALSE$
, END_PRODUCTION
// At index 169 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 248
, END_PRODUCTION
// At index 170 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 248
, NONTERMINAL (10) // <oil_declaration>
, NONTERMINAL (42) // <select_goil_5F_syntax_6>
, END_PRODUCTION
// At index 173 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 248
, NONTERMINAL (13) // <include_object_level>
, NONTERMINAL (42) // <select_goil_5F_syntax_6>
, END_PRODUCTION
// At index 176 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 273
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (44) // <select_goil_5F_syntax_8>
, END_PRODUCTION
// At index 179 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 273
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (9) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 185 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 275
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (45) // <select_goil_5F_syntax_9>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 189 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 275
, NONTERMINAL (3) // <sign>
, NONTERMINAL (46) // <select_goil_5F_syntax_10>
, END_PRODUCTION
// At index 192 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 275
, NONTERMINAL (8) // <boolean>
, NONTERMINAL (47) // <select_goil_5F_syntax_11>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 196 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 275
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 199 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 275
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) // $AUTO$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 202 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 296
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (9) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 206 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 296
, END_PRODUCTION
// At index 207 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 313
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) // $uint_number$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 210 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 313
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_float_5F_number) // $float_number$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 213 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 344
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (9) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 217 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 344
, END_PRODUCTION
// At index 218 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 458
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) // $include$
, END_PRODUCTION
// At index 220 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 458
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) // $includeifexists$
, END_PRODUCTION
// At index 222 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 464
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) // $g_string$
, END_PRODUCTION
// At index 224 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 464
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, END_PRODUCTION
// At index 226 : <select_goil_5F_syntax_14>, in file 'goil_syntax.ggs', line 482
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) // $include$
, END_PRODUCTION
// At index 228 : <select_goil_5F_syntax_14>, in file 'goil_syntax.ggs', line 482
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) // $includeifexists$
, END_PRODUCTION
// At index 230 : <select_goil_5F_syntax_15>, in file 'goil_syntax.ggs', line 488
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) // $g_string$
, END_PRODUCTION
// At index 232 : <select_goil_5F_syntax_15>, in file 'goil_syntax.ggs', line 488
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, END_PRODUCTION
// At index 234 : <select_goil_5F_syntax_16>, in file 'goil_syntax.ggs', line 504
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) // $include$
, END_PRODUCTION
// At index 236 : <select_goil_5F_syntax_16>, in file 'goil_syntax.ggs', line 504
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) // $includeifexists$
, END_PRODUCTION
// At index 238 : <select_goil_5F_syntax_17>, in file 'goil_syntax.ggs', line 510
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) // $g_string$
, END_PRODUCTION
// At index 240 : <select_goil_5F_syntax_17>, in file 'goil_syntax.ggs', line 510
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, END_PRODUCTION
// At index 242 : <select_implementation_5F_parser_0>, in file 'implementation_parser.ggs', line 65
, END_PRODUCTION
// At index 243 : <select_implementation_5F_parser_0>, in file 'implementation_parser.ggs', line 65
, NONTERMINAL (17) // <implementation_objects>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, NONTERMINAL (54) // <select_implementation_5F_parser_0>
, END_PRODUCTION
// At index 247 : <select_implementation_5F_parser_0>, in file 'implementation_parser.ggs', line 65
, NONTERMINAL (15) // <include_implementation_level>
, NONTERMINAL (54) // <select_implementation_5F_parser_0>
, END_PRODUCTION
// At index 250 : <select_implementation_5F_parser_1>, in file 'implementation_parser.ggs', line 75
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) // $include$
, END_PRODUCTION
// At index 252 : <select_implementation_5F_parser_1>, in file 'implementation_parser.ggs', line 75
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) // $includeifexists$
, END_PRODUCTION
// At index 254 : <select_implementation_5F_parser_2>, in file 'implementation_parser.ggs', line 81
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) // $g_string$
, END_PRODUCTION
// At index 256 : <select_implementation_5F_parser_2>, in file 'implementation_parser.ggs', line 81
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, END_PRODUCTION
// At index 258 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 96
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) // $include$
, END_PRODUCTION
// At index 260 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 96
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) // $includeifexists$
, END_PRODUCTION
// At index 262 : <select_implementation_5F_parser_4>, in file 'implementation_parser.ggs', line 102
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) // $g_string$
, END_PRODUCTION
// At index 264 : <select_implementation_5F_parser_4>, in file 'implementation_parser.ggs', line 102
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, END_PRODUCTION
// At index 266 : <select_implementation_5F_parser_5>, in file 'implementation_parser.ggs', line 142
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) // $[$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) // $]$
, END_PRODUCTION
// At index 269 : <select_implementation_5F_parser_5>, in file 'implementation_parser.ggs', line 142
, END_PRODUCTION
// At index 270 : <select_implementation_5F_parser_6>, in file 'implementation_parser.ggs', line 186
, END_PRODUCTION
// At index 271 : <select_implementation_5F_parser_6>, in file 'implementation_parser.ggs', line 186
, NONTERMINAL (19) // <implementation_type>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, NONTERMINAL (60) // <select_implementation_5F_parser_6>
, END_PRODUCTION
// At index 275 : <select_implementation_5F_parser_6>, in file 'implementation_parser.ggs', line 186
, NONTERMINAL (16) // <include_type_level>
, NONTERMINAL (60) // <select_implementation_5F_parser_6>
, END_PRODUCTION
// At index 278 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 264
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_UINT_33__32_) // $UINT32$
, NONTERMINAL (26) // <number_options>
, END_PRODUCTION
// At index 281 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 264
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_INT_33__32_) // $INT32$
, NONTERMINAL (26) // <number_options>
, END_PRODUCTION
// At index 284 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 264
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_UINT_36__34_) // $UINT64$
, NONTERMINAL (26) // <number_options>
, END_PRODUCTION
// At index 287 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 264
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_INT_36__34_) // $INT64$
, NONTERMINAL (26) // <number_options>
, END_PRODUCTION
// At index 290 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 264
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_FLOAT) // $FLOAT$
, NONTERMINAL (26) // <number_options>
, END_PRODUCTION
// At index 293 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 264
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_ENUM) // $ENUM$
, NONTERMINAL (25) // <enum_options>
, END_PRODUCTION
// At index 296 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 264
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_BOOLEAN) // $BOOLEAN$
, NONTERMINAL (23) // <boolean_options>
, END_PRODUCTION
// At index 299 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 264
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_STRING) // $STRING$
, NONTERMINAL (22) // <string_options>
, END_PRODUCTION
// At index 302 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 264
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_IDENTIFIER) // $IDENTIFIER$
, NONTERMINAL (27) // <type_options>
, END_PRODUCTION
// At index 305 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 264
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_STRUCT) // $STRUCT$
, NONTERMINAL (20) // <struct_options>
, END_PRODUCTION
// At index 308 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 264
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (21) // <objref_option>
, END_PRODUCTION
// At index 311 : <select_implementation_5F_parser_8>, in file 'implementation_parser.ggs', line 293
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (18) // <implementation_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 315 : <select_implementation_5F_parser_8>, in file 'implementation_parser.ggs', line 293
, END_PRODUCTION
// At index 316 : <select_implementation_5F_parser_9>, in file 'implementation_parser.ggs', line 334
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (64) // <select_implementation_5F_parser_10>
, END_PRODUCTION
// At index 319 : <select_implementation_5F_parser_9>, in file 'implementation_parser.ggs', line 334
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 321 : <select_implementation_5F_parser_10>, in file 'implementation_parser.ggs', line 336
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 324 : <select_implementation_5F_parser_10>, in file 'implementation_parser.ggs', line 336
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) // $AUTO$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 327 : <select_implementation_5F_parser_10>, in file 'implementation_parser.ggs', line 336
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT) // $NO_DEFAULT$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 330 : <select_implementation_5F_parser_11>, in file 'implementation_parser.ggs', line 368
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) // $[$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_TRUE) // $TRUE$
, NONTERMINAL (66) // <select_implementation_5F_parser_12>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2C_) // $,$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_FALSE) // $FALSE$
, NONTERMINAL (67) // <select_implementation_5F_parser_13>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) // $]$
, END_PRODUCTION
// At index 338 : <select_implementation_5F_parser_11>, in file 'implementation_parser.ggs', line 368
, END_PRODUCTION
// At index 339 : <select_implementation_5F_parser_12>, in file 'implementation_parser.ggs', line 371
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (18) // <implementation_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 343 : <select_implementation_5F_parser_12>, in file 'implementation_parser.ggs', line 371
, END_PRODUCTION
// At index 344 : <select_implementation_5F_parser_13>, in file 'implementation_parser.ggs', line 380
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (18) // <implementation_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 348 : <select_implementation_5F_parser_13>, in file 'implementation_parser.ggs', line 380
, END_PRODUCTION
// At index 349 : <select_implementation_5F_parser_14>, in file 'implementation_parser.ggs', line 394
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (8) // <boolean>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 353 : <select_implementation_5F_parser_14>, in file 'implementation_parser.ggs', line 394
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 355 : <select_implementation_5F_parser_15>, in file 'implementation_parser.ggs', line 411
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (18) // <implementation_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 359 : <select_implementation_5F_parser_15>, in file 'implementation_parser.ggs', line 411
, END_PRODUCTION
// At index 360 : <select_implementation_5F_parser_16>, in file 'implementation_parser.ggs', line 427
, END_PRODUCTION
// At index 361 : <select_implementation_5F_parser_16>, in file 'implementation_parser.ggs', line 427
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2C_) // $,$
, NONTERMINAL (24) // <enum_item>
, NONTERMINAL (70) // <select_implementation_5F_parser_16>
, END_PRODUCTION
// At index 365 : <select_implementation_5F_parser_17>, in file 'implementation_parser.ggs', line 437
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (72) // <select_implementation_5F_parser_18>
, END_PRODUCTION
// At index 368 : <select_implementation_5F_parser_17>, in file 'implementation_parser.ggs', line 437
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 370 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 439
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 373 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 439
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) // $AUTO$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 376 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 439
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT) // $NO_DEFAULT$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 379 : <select_implementation_5F_parser_19>, in file 'implementation_parser.ggs', line 479
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (74) // <select_implementation_5F_parser_20>
, END_PRODUCTION
// At index 382 : <select_implementation_5F_parser_19>, in file 'implementation_parser.ggs', line 479
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 384 : <select_implementation_5F_parser_20>, in file 'implementation_parser.ggs', line 481
, NONTERMINAL (29) // <int_or_float>
, END_PRODUCTION
// At index 386 : <select_implementation_5F_parser_20>, in file 'implementation_parser.ggs', line 481
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT) // $NO_DEFAULT$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 389 : <select_implementation_5F_parser_20>, in file 'implementation_parser.ggs', line 481
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) // $AUTO$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 392 : <select_implementation_5F_parser_21>, in file 'implementation_parser.ggs', line 516
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (76) // <select_implementation_5F_parser_22>
, END_PRODUCTION
// At index 395 : <select_implementation_5F_parser_21>, in file 'implementation_parser.ggs', line 516
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 397 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 518
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 400 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 518
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT) // $NO_DEFAULT$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 403 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 518
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) // $AUTO$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 406 : <select_implementation_5F_parser_23>, in file 'implementation_parser.ggs', line 546
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_WITH_5F_AUTO) // $WITH_AUTO$
, END_PRODUCTION
// At index 408 : <select_implementation_5F_parser_23>, in file 'implementation_parser.ggs', line 546
, END_PRODUCTION
// At index 409 : <select_implementation_5F_parser_24>, in file 'implementation_parser.ggs', line 558
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) // $uint_number$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 412 : <select_implementation_5F_parser_24>, in file 'implementation_parser.ggs', line 558
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_float_5F_number) // $float_number$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 415 : <select_implementation_5F_parser_25>, in file 'implementation_parser.ggs', line 574
, END_PRODUCTION
// At index 416 : <select_implementation_5F_parser_25>, in file 'implementation_parser.ggs', line 574
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2C_) // $,$
, NONTERMINAL (29) // <int_or_float>
, NONTERMINAL (79) // <select_implementation_5F_parser_25>
, END_PRODUCTION
// At index 420 : <select_implementation_5F_parser_26>, in file 'implementation_parser.ggs', line 590
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_set_5F_start_5F_uint_5F_number) // $set_start_uint_number$
, NONTERMINAL (29) // <int_or_float>
, END_PRODUCTION
// At index 423 : <select_implementation_5F_parser_26>, in file 'implementation_parser.ggs', line 590
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) // $uint_number$
, NONTERMINAL (81) // <select_implementation_5F_parser_27>
, END_PRODUCTION
// At index 426 : <select_implementation_5F_parser_26>, in file 'implementation_parser.ggs', line 590
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_float_5F_number) // $float_number$
, NONTERMINAL (82) // <select_implementation_5F_parser_28>
, END_PRODUCTION
// At index 429 : <select_implementation_5F_parser_27>, in file 'implementation_parser.ggs', line 600
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2E__2E_) // $..$
, NONTERMINAL (29) // <int_or_float>
, END_PRODUCTION
// At index 432 : <select_implementation_5F_parser_27>, in file 'implementation_parser.ggs', line 600
, NONTERMINAL (30) // <set_followup>
, END_PRODUCTION
// At index 434 : <select_implementation_5F_parser_28>, in file 'implementation_parser.ggs', line 612
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2E__2E_) // $..$
, NONTERMINAL (29) // <int_or_float>
, END_PRODUCTION
// At index 437 : <select_implementation_5F_parser_28>, in file 'implementation_parser.ggs', line 612
, NONTERMINAL (30) // <set_followup>
, END_PRODUCTION
// At index 439 : <select_implementation_5F_parser_29>, in file 'implementation_parser.ggs', line 626
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) // $[$
, NONTERMINAL (31) // <range_content>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) // $]$
, END_PRODUCTION
// At index 443 : <select_implementation_5F_parser_29>, in file 'implementation_parser.ggs', line 626
, END_PRODUCTION
// At index 444 : <select_implementation_5F_parser_30>, in file 'implementation_parser.ggs', line 635
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) // $[$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) // $]$
, END_PRODUCTION
// At index 447 : <select_implementation_5F_parser_30>, in file 'implementation_parser.ggs', line 635
, END_PRODUCTION
// At index 448 : <>, in file '.ggs', line 0
, NONTERMINAL (18) // <implementation_list>
, END_PRODUCTION
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                          P R O D U C T I O N    N A M E S                                            
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const cProductionNameDescriptor gProductionNames_goil_type_level_include [159] = {
 {"<implementation_definition>", "implementation_parser", 0}, // at index 0
 {"<start>", "goil_syntax", 7}, // at index 1
 {"<file>", "goil_syntax", 10}, // at index 2
 {"<sign>", "goil_syntax", 12}, // at index 3
 {"<description>", "goil_syntax", 14}, // at index 4
 {"<OIL_version>", "goil_syntax", 16}, // at index 5
 {"<application_definition>", "goil_syntax", 22}, // at index 6
 {"<object_definition_list>", "goil_syntax", 30}, // at index 7
 {"<boolean>", "goil_syntax", 32}, // at index 8
 {"<oil_declaration_list>", "goil_syntax", 34}, // at index 9
 {"<oil_declaration>", "goil_syntax", 36}, // at index 10
 {"<include_file_level>", "goil_syntax", 40}, // at index 11
 {"<include_cpu_level>", "goil_syntax", 43}, // at index 12
 {"<include_object_level>", "goil_syntax", 46}, // at index 13
 {"<implementation_object_list>", "implementation_parser", 49}, // at index 14
 {"<include_implementation_level>", "implementation_parser", 51}, // at index 15
 {"<include_type_level>", "implementation_parser", 54}, // at index 16
 {"<implementation_objects>", "implementation_parser", 57}, // at index 17
 {"<implementation_list>", "implementation_parser", 63}, // at index 18
 {"<implementation_type>", "implementation_parser", 65}, // at index 19
 {"<struct_options>", "implementation_parser", 67}, // at index 20
 {"<objref_option>", "implementation_parser", 72}, // at index 21
 {"<string_options>", "implementation_parser", 76}, // at index 22
 {"<boolean_options>", "implementation_parser", 81}, // at index 23
 {"<enum_item>", "implementation_parser", 87}, // at index 24
 {"<enum_options>", "implementation_parser", 90}, // at index 25
 {"<number_options>", "implementation_parser", 99}, // at index 26
 {"<type_options>", "implementation_parser", 105}, // at index 27
 {"<with_auto>", "implementation_parser", 110}, // at index 28
 {"<int_or_float>", "implementation_parser", 112}, // at index 29
 {"<set_followup>", "implementation_parser", 115}, // at index 30
 {"<range_content>", "implementation_parser", 117}, // at index 31
 {"<range>", "implementation_parser", 120}, // at index 32
 {"<multiple>", "implementation_parser", 122}, // at index 33
 {"<identifier_or_attribute>", "implementation_parser", 124}, // at index 34
 {"<identifier_or_enum_value>", "implementation_parser", 126}, // at index 35
 {"<select_goil_5F_syntax_0>", "goil_syntax", 128}, // at index 36
 {"<select_goil_5F_syntax_0>", "goil_syntax", 129}, // at index 37
 {"<select_goil_5F_syntax_0>", "goil_syntax", 132}, // at index 38
 {"<select_goil_5F_syntax_0>", "goil_syntax", 135}, // at index 39
 {"<select_goil_5F_syntax_1>", "goil_syntax", 138}, // at index 40
 {"<select_goil_5F_syntax_1>", "goil_syntax", 140}, // at index 41
 {"<select_goil_5F_syntax_1>", "goil_syntax", 142}, // at index 42
 {"<select_goil_5F_syntax_2>", "goil_syntax", 143}, // at index 43
 {"<select_goil_5F_syntax_2>", "goil_syntax", 144}, // at index 44
 {"<select_goil_5F_syntax_3>", "goil_syntax", 148}, // at index 45
 {"<select_goil_5F_syntax_3>", "goil_syntax", 149}, // at index 46
 {"<select_goil_5F_syntax_4>", "goil_syntax", 152}, // at index 47
 {"<select_goil_5F_syntax_4>", "goil_syntax", 153}, // at index 48
 {"<select_goil_5F_syntax_4>", "goil_syntax", 162}, // at index 49
 {"<select_goil_5F_syntax_5>", "goil_syntax", 165}, // at index 50
 {"<select_goil_5F_syntax_5>", "goil_syntax", 167}, // at index 51
 {"<select_goil_5F_syntax_6>", "goil_syntax", 169}, // at index 52
 {"<select_goil_5F_syntax_6>", "goil_syntax", 170}, // at index 53
 {"<select_goil_5F_syntax_6>", "goil_syntax", 173}, // at index 54
 {"<select_goil_5F_syntax_7>", "goil_syntax", 176}, // at index 55
 {"<select_goil_5F_syntax_7>", "goil_syntax", 179}, // at index 56
 {"<select_goil_5F_syntax_8>", "goil_syntax", 185}, // at index 57
 {"<select_goil_5F_syntax_8>", "goil_syntax", 189}, // at index 58
 {"<select_goil_5F_syntax_8>", "goil_syntax", 192}, // at index 59
 {"<select_goil_5F_syntax_8>", "goil_syntax", 196}, // at index 60
 {"<select_goil_5F_syntax_8>", "goil_syntax", 199}, // at index 61
 {"<select_goil_5F_syntax_9>", "goil_syntax", 202}, // at index 62
 {"<select_goil_5F_syntax_9>", "goil_syntax", 206}, // at index 63
 {"<select_goil_5F_syntax_10>", "goil_syntax", 207}, // at index 64
 {"<select_goil_5F_syntax_10>", "goil_syntax", 210}, // at index 65
 {"<select_goil_5F_syntax_11>", "goil_syntax", 213}, // at index 66
 {"<select_goil_5F_syntax_11>", "goil_syntax", 217}, // at index 67
 {"<select_goil_5F_syntax_12>", "goil_syntax", 218}, // at index 68
 {"<select_goil_5F_syntax_12>", "goil_syntax", 220}, // at index 69
 {"<select_goil_5F_syntax_13>", "goil_syntax", 222}, // at index 70
 {"<select_goil_5F_syntax_13>", "goil_syntax", 224}, // at index 71
 {"<select_goil_5F_syntax_14>", "goil_syntax", 226}, // at index 72
 {"<select_goil_5F_syntax_14>", "goil_syntax", 228}, // at index 73
 {"<select_goil_5F_syntax_15>", "goil_syntax", 230}, // at index 74
 {"<select_goil_5F_syntax_15>", "goil_syntax", 232}, // at index 75
 {"<select_goil_5F_syntax_16>", "goil_syntax", 234}, // at index 76
 {"<select_goil_5F_syntax_16>", "goil_syntax", 236}, // at index 77
 {"<select_goil_5F_syntax_17>", "goil_syntax", 238}, // at index 78
 {"<select_goil_5F_syntax_17>", "goil_syntax", 240}, // at index 79
 {"<select_implementation_5F_parser_0>", "implementation_parser", 242}, // at index 80
 {"<select_implementation_5F_parser_0>", "implementation_parser", 243}, // at index 81
 {"<select_implementation_5F_parser_0>", "implementation_parser", 247}, // at index 82
 {"<select_implementation_5F_parser_1>", "implementation_parser", 250}, // at index 83
 {"<select_implementation_5F_parser_1>", "implementation_parser", 252}, // at index 84
 {"<select_implementation_5F_parser_2>", "implementation_parser", 254}, // at index 85
 {"<select_implementation_5F_parser_2>", "implementation_parser", 256}, // at index 86
 {"<select_implementation_5F_parser_3>", "implementation_parser", 258}, // at index 87
 {"<select_implementation_5F_parser_3>", "implementation_parser", 260}, // at index 88
 {"<select_implementation_5F_parser_4>", "implementation_parser", 262}, // at index 89
 {"<select_implementation_5F_parser_4>", "implementation_parser", 264}, // at index 90
 {"<select_implementation_5F_parser_5>", "implementation_parser", 266}, // at index 91
 {"<select_implementation_5F_parser_5>", "implementation_parser", 269}, // at index 92
 {"<select_implementation_5F_parser_6>", "implementation_parser", 270}, // at index 93
 {"<select_implementation_5F_parser_6>", "implementation_parser", 271}, // at index 94
 {"<select_implementation_5F_parser_6>", "implementation_parser", 275}, // at index 95
 {"<select_implementation_5F_parser_7>", "implementation_parser", 278}, // at index 96
 {"<select_implementation_5F_parser_7>", "implementation_parser", 281}, // at index 97
 {"<select_implementation_5F_parser_7>", "implementation_parser", 284}, // at index 98
 {"<select_implementation_5F_parser_7>", "implementation_parser", 287}, // at index 99
 {"<select_implementation_5F_parser_7>", "implementation_parser", 290}, // at index 100
 {"<select_implementation_5F_parser_7>", "implementation_parser", 293}, // at index 101
 {"<select_implementation_5F_parser_7>", "implementation_parser", 296}, // at index 102
 {"<select_implementation_5F_parser_7>", "implementation_parser", 299}, // at index 103
 {"<select_implementation_5F_parser_7>", "implementation_parser", 302}, // at index 104
 {"<select_implementation_5F_parser_7>", "implementation_parser", 305}, // at index 105
 {"<select_implementation_5F_parser_7>", "implementation_parser", 308}, // at index 106
 {"<select_implementation_5F_parser_8>", "implementation_parser", 311}, // at index 107
 {"<select_implementation_5F_parser_8>", "implementation_parser", 315}, // at index 108
 {"<select_implementation_5F_parser_9>", "implementation_parser", 316}, // at index 109
 {"<select_implementation_5F_parser_9>", "implementation_parser", 319}, // at index 110
 {"<select_implementation_5F_parser_10>", "implementation_parser", 321}, // at index 111
 {"<select_implementation_5F_parser_10>", "implementation_parser", 324}, // at index 112
 {"<select_implementation_5F_parser_10>", "implementation_parser", 327}, // at index 113
 {"<select_implementation_5F_parser_11>", "implementation_parser", 330}, // at index 114
 {"<select_implementation_5F_parser_11>", "implementation_parser", 338}, // at index 115
 {"<select_implementation_5F_parser_12>", "implementation_parser", 339}, // at index 116
 {"<select_implementation_5F_parser_12>", "implementation_parser", 343}, // at index 117
 {"<select_implementation_5F_parser_13>", "implementation_parser", 344}, // at index 118
 {"<select_implementation_5F_parser_13>", "implementation_parser", 348}, // at index 119
 {"<select_implementation_5F_parser_14>", "implementation_parser", 349}, // at index 120
 {"<select_implementation_5F_parser_14>", "implementation_parser", 353}, // at index 121
 {"<select_implementation_5F_parser_15>", "implementation_parser", 355}, // at index 122
 {"<select_implementation_5F_parser_15>", "implementation_parser", 359}, // at index 123
 {"<select_implementation_5F_parser_16>", "implementation_parser", 360}, // at index 124
 {"<select_implementation_5F_parser_16>", "implementation_parser", 361}, // at index 125
 {"<select_implementation_5F_parser_17>", "implementation_parser", 365}, // at index 126
 {"<select_implementation_5F_parser_17>", "implementation_parser", 368}, // at index 127
 {"<select_implementation_5F_parser_18>", "implementation_parser", 370}, // at index 128
 {"<select_implementation_5F_parser_18>", "implementation_parser", 373}, // at index 129
 {"<select_implementation_5F_parser_18>", "implementation_parser", 376}, // at index 130
 {"<select_implementation_5F_parser_19>", "implementation_parser", 379}, // at index 131
 {"<select_implementation_5F_parser_19>", "implementation_parser", 382}, // at index 132
 {"<select_implementation_5F_parser_20>", "implementation_parser", 384}, // at index 133
 {"<select_implementation_5F_parser_20>", "implementation_parser", 386}, // at index 134
 {"<select_implementation_5F_parser_20>", "implementation_parser", 389}, // at index 135
 {"<select_implementation_5F_parser_21>", "implementation_parser", 392}, // at index 136
 {"<select_implementation_5F_parser_21>", "implementation_parser", 395}, // at index 137
 {"<select_implementation_5F_parser_22>", "implementation_parser", 397}, // at index 138
 {"<select_implementation_5F_parser_22>", "implementation_parser", 400}, // at index 139
 {"<select_implementation_5F_parser_22>", "implementation_parser", 403}, // at index 140
 {"<select_implementation_5F_parser_23>", "implementation_parser", 406}, // at index 141
 {"<select_implementation_5F_parser_23>", "implementation_parser", 408}, // at index 142
 {"<select_implementation_5F_parser_24>", "implementation_parser", 409}, // at index 143
 {"<select_implementation_5F_parser_24>", "implementation_parser", 412}, // at index 144
 {"<select_implementation_5F_parser_25>", "implementation_parser", 415}, // at index 145
 {"<select_implementation_5F_parser_25>", "implementation_parser", 416}, // at index 146
 {"<select_implementation_5F_parser_26>", "implementation_parser", 420}, // at index 147
 {"<select_implementation_5F_parser_26>", "implementation_parser", 423}, // at index 148
 {"<select_implementation_5F_parser_26>", "implementation_parser", 426}, // at index 149
 {"<select_implementation_5F_parser_27>", "implementation_parser", 429}, // at index 150
 {"<select_implementation_5F_parser_27>", "implementation_parser", 432}, // at index 151
 {"<select_implementation_5F_parser_28>", "implementation_parser", 434}, // at index 152
 {"<select_implementation_5F_parser_28>", "implementation_parser", 437}, // at index 153
 {"<select_implementation_5F_parser_29>", "implementation_parser", 439}, // at index 154
 {"<select_implementation_5F_parser_29>", "implementation_parser", 443}, // at index 155
 {"<select_implementation_5F_parser_30>", "implementation_parser", 444}, // at index 156
 {"<select_implementation_5F_parser_30>", "implementation_parser", 447}, // at index 157
 {"<>", "", 448} // at index 158
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                 L L ( 1 )    P R O D U C T I O N    I N D E X E S                                    
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gProductionIndexes_goil_type_level_include [159] = {
0, // index 0 : <implementation_definition>, in file 'implementation_parser.ggs', line 55
7, // index 1 : <start>, in file 'goil_syntax.ggs', line 38
10, // index 2 : <file>, in file 'goil_syntax.ggs', line 110
12, // index 3 : <sign>, in file 'goil_syntax.ggs', line 126
14, // index 4 : <description>, in file 'goil_syntax.ggs', line 139
16, // index 5 : <OIL_version>, in file 'goil_syntax.ggs', line 163
22, // index 6 : <application_definition>, in file 'goil_syntax.ggs', line 170
30, // index 7 : <object_definition_list>, in file 'goil_syntax.ggs', line 184
32, // index 8 : <boolean>, in file 'goil_syntax.ggs', line 234
34, // index 9 : <oil_declaration_list>, in file 'goil_syntax.ggs', line 244
36, // index 10 : <oil_declaration>, in file 'goil_syntax.ggs', line 256
40, // index 11 : <include_file_level>, in file 'goil_syntax.ggs', line 451
43, // index 12 : <include_cpu_level>, in file 'goil_syntax.ggs', line 475
46, // index 13 : <include_object_level>, in file 'goil_syntax.ggs', line 499
49, // index 14 : <implementation_object_list>, in file 'implementation_parser.ggs', line 62
51, // index 15 : <include_implementation_level>, in file 'implementation_parser.ggs', line 71
54, // index 16 : <include_type_level>, in file 'implementation_parser.ggs', line 92
57, // index 17 : <implementation_objects>, in file 'implementation_parser.ggs', line 135
63, // index 18 : <implementation_list>, in file 'implementation_parser.ggs', line 183
65, // index 19 : <implementation_type>, in file 'implementation_parser.ggs', line 261
67, // index 20 : <struct_options>, in file 'implementation_parser.ggs', line 289
72, // index 21 : <objref_option>, in file 'implementation_parser.ggs', line 306
76, // index 22 : <string_options>, in file 'implementation_parser.ggs', line 324
81, // index 23 : <boolean_options>, in file 'implementation_parser.ggs', line 361
87, // index 24 : <enum_item>, in file 'implementation_parser.ggs', line 406
90, // index 25 : <enum_options>, in file 'implementation_parser.ggs', line 419
99, // index 26 : <number_options>, in file 'implementation_parser.ggs', line 466
105, // index 27 : <type_options>, in file 'implementation_parser.ggs', line 505
110, // index 28 : <with_auto>, in file 'implementation_parser.ggs', line 544
112, // index 29 : <int_or_float>, in file 'implementation_parser.ggs', line 553
115, // index 30 : <set_followup>, in file 'implementation_parser.ggs', line 571
117, // index 31 : <range_content>, in file 'implementation_parser.ggs', line 583
120, // index 32 : <range>, in file 'implementation_parser.ggs', line 623
122, // index 33 : <multiple>, in file 'implementation_parser.ggs', line 633
124, // index 34 : <identifier_or_attribute>, in file 'implementation_parser.ggs', line 643
126, // index 35 : <identifier_or_enum_value>, in file 'implementation_parser.ggs', line 648
128, // index 36 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
129, // index 37 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
132, // index 38 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
135, // index 39 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
138, // index 40 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
140, // index 41 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
142, // index 42 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
143, // index 43 : <select_goil_5F_syntax_2>, in file 'goil_syntax.ggs', line 140
144, // index 44 : <select_goil_5F_syntax_2>, in file 'goil_syntax.ggs', line 140
148, // index 45 : <select_goil_5F_syntax_3>, in file 'goil_syntax.ggs', line 147
149, // index 46 : <select_goil_5F_syntax_3>, in file 'goil_syntax.ggs', line 147
152, // index 47 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
153, // index 48 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
162, // index 49 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
165, // index 50 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 235
167, // index 51 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 235
169, // index 52 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 248
170, // index 53 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 248
173, // index 54 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 248
176, // index 55 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 273
179, // index 56 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 273
185, // index 57 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 275
189, // index 58 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 275
192, // index 59 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 275
196, // index 60 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 275
199, // index 61 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 275
202, // index 62 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 296
206, // index 63 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 296
207, // index 64 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 313
210, // index 65 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 313
213, // index 66 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 344
217, // index 67 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 344
218, // index 68 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 458
220, // index 69 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 458
222, // index 70 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 464
224, // index 71 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 464
226, // index 72 : <select_goil_5F_syntax_14>, in file 'goil_syntax.ggs', line 482
228, // index 73 : <select_goil_5F_syntax_14>, in file 'goil_syntax.ggs', line 482
230, // index 74 : <select_goil_5F_syntax_15>, in file 'goil_syntax.ggs', line 488
232, // index 75 : <select_goil_5F_syntax_15>, in file 'goil_syntax.ggs', line 488
234, // index 76 : <select_goil_5F_syntax_16>, in file 'goil_syntax.ggs', line 504
236, // index 77 : <select_goil_5F_syntax_16>, in file 'goil_syntax.ggs', line 504
238, // index 78 : <select_goil_5F_syntax_17>, in file 'goil_syntax.ggs', line 510
240, // index 79 : <select_goil_5F_syntax_17>, in file 'goil_syntax.ggs', line 510
242, // index 80 : <select_implementation_5F_parser_0>, in file 'implementation_parser.ggs', line 65
243, // index 81 : <select_implementation_5F_parser_0>, in file 'implementation_parser.ggs', line 65
247, // index 82 : <select_implementation_5F_parser_0>, in file 'implementation_parser.ggs', line 65
250, // index 83 : <select_implementation_5F_parser_1>, in file 'implementation_parser.ggs', line 75
252, // index 84 : <select_implementation_5F_parser_1>, in file 'implementation_parser.ggs', line 75
254, // index 85 : <select_implementation_5F_parser_2>, in file 'implementation_parser.ggs', line 81
256, // index 86 : <select_implementation_5F_parser_2>, in file 'implementation_parser.ggs', line 81
258, // index 87 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 96
260, // index 88 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 96
262, // index 89 : <select_implementation_5F_parser_4>, in file 'implementation_parser.ggs', line 102
264, // index 90 : <select_implementation_5F_parser_4>, in file 'implementation_parser.ggs', line 102
266, // index 91 : <select_implementation_5F_parser_5>, in file 'implementation_parser.ggs', line 142
269, // index 92 : <select_implementation_5F_parser_5>, in file 'implementation_parser.ggs', line 142
270, // index 93 : <select_implementation_5F_parser_6>, in file 'implementation_parser.ggs', line 186
271, // index 94 : <select_implementation_5F_parser_6>, in file 'implementation_parser.ggs', line 186
275, // index 95 : <select_implementation_5F_parser_6>, in file 'implementation_parser.ggs', line 186
278, // index 96 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 264
281, // index 97 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 264
284, // index 98 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 264
287, // index 99 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 264
290, // index 100 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 264
293, // index 101 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 264
296, // index 102 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 264
299, // index 103 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 264
302, // index 104 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 264
305, // index 105 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 264
308, // index 106 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 264
311, // index 107 : <select_implementation_5F_parser_8>, in file 'implementation_parser.ggs', line 293
315, // index 108 : <select_implementation_5F_parser_8>, in file 'implementation_parser.ggs', line 293
316, // index 109 : <select_implementation_5F_parser_9>, in file 'implementation_parser.ggs', line 334
319, // index 110 : <select_implementation_5F_parser_9>, in file 'implementation_parser.ggs', line 334
321, // index 111 : <select_implementation_5F_parser_10>, in file 'implementation_parser.ggs', line 336
324, // index 112 : <select_implementation_5F_parser_10>, in file 'implementation_parser.ggs', line 336
327, // index 113 : <select_implementation_5F_parser_10>, in file 'implementation_parser.ggs', line 336
330, // index 114 : <select_implementation_5F_parser_11>, in file 'implementation_parser.ggs', line 368
338, // index 115 : <select_implementation_5F_parser_11>, in file 'implementation_parser.ggs', line 368
339, // index 116 : <select_implementation_5F_parser_12>, in file 'implementation_parser.ggs', line 371
343, // index 117 : <select_implementation_5F_parser_12>, in file 'implementation_parser.ggs', line 371
344, // index 118 : <select_implementation_5F_parser_13>, in file 'implementation_parser.ggs', line 380
348, // index 119 : <select_implementation_5F_parser_13>, in file 'implementation_parser.ggs', line 380
349, // index 120 : <select_implementation_5F_parser_14>, in file 'implementation_parser.ggs', line 394
353, // index 121 : <select_implementation_5F_parser_14>, in file 'implementation_parser.ggs', line 394
355, // index 122 : <select_implementation_5F_parser_15>, in file 'implementation_parser.ggs', line 411
359, // index 123 : <select_implementation_5F_parser_15>, in file 'implementation_parser.ggs', line 411
360, // index 124 : <select_implementation_5F_parser_16>, in file 'implementation_parser.ggs', line 427
361, // index 125 : <select_implementation_5F_parser_16>, in file 'implementation_parser.ggs', line 427
365, // index 126 : <select_implementation_5F_parser_17>, in file 'implementation_parser.ggs', line 437
368, // index 127 : <select_implementation_5F_parser_17>, in file 'implementation_parser.ggs', line 437
370, // index 128 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 439
373, // index 129 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 439
376, // index 130 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 439
379, // index 131 : <select_implementation_5F_parser_19>, in file 'implementation_parser.ggs', line 479
382, // index 132 : <select_implementation_5F_parser_19>, in file 'implementation_parser.ggs', line 479
384, // index 133 : <select_implementation_5F_parser_20>, in file 'implementation_parser.ggs', line 481
386, // index 134 : <select_implementation_5F_parser_20>, in file 'implementation_parser.ggs', line 481
389, // index 135 : <select_implementation_5F_parser_20>, in file 'implementation_parser.ggs', line 481
392, // index 136 : <select_implementation_5F_parser_21>, in file 'implementation_parser.ggs', line 516
395, // index 137 : <select_implementation_5F_parser_21>, in file 'implementation_parser.ggs', line 516
397, // index 138 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 518
400, // index 139 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 518
403, // index 140 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 518
406, // index 141 : <select_implementation_5F_parser_23>, in file 'implementation_parser.ggs', line 546
408, // index 142 : <select_implementation_5F_parser_23>, in file 'implementation_parser.ggs', line 546
409, // index 143 : <select_implementation_5F_parser_24>, in file 'implementation_parser.ggs', line 558
412, // index 144 : <select_implementation_5F_parser_24>, in file 'implementation_parser.ggs', line 558
415, // index 145 : <select_implementation_5F_parser_25>, in file 'implementation_parser.ggs', line 574
416, // index 146 : <select_implementation_5F_parser_25>, in file 'implementation_parser.ggs', line 574
420, // index 147 : <select_implementation_5F_parser_26>, in file 'implementation_parser.ggs', line 590
423, // index 148 : <select_implementation_5F_parser_26>, in file 'implementation_parser.ggs', line 590
426, // index 149 : <select_implementation_5F_parser_26>, in file 'implementation_parser.ggs', line 590
429, // index 150 : <select_implementation_5F_parser_27>, in file 'implementation_parser.ggs', line 600
432, // index 151 : <select_implementation_5F_parser_27>, in file 'implementation_parser.ggs', line 600
434, // index 152 : <select_implementation_5F_parser_28>, in file 'implementation_parser.ggs', line 612
437, // index 153 : <select_implementation_5F_parser_28>, in file 'implementation_parser.ggs', line 612
439, // index 154 : <select_implementation_5F_parser_29>, in file 'implementation_parser.ggs', line 626
443, // index 155 : <select_implementation_5F_parser_29>, in file 'implementation_parser.ggs', line 626
444, // index 156 : <select_implementation_5F_parser_30>, in file 'implementation_parser.ggs', line 635
447, // index 157 : <select_implementation_5F_parser_30>, in file 'implementation_parser.ggs', line 635
448 // index 158 : <>, in file '.ggs', line 0
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                           L L ( 1 )    F I R S T    P R O D U C T I O N    I N D E X E S                             
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gFirstProductionIndexes_goil_type_level_include [87] = {
0, // at 0 : <implementation_definition>
1, // at 1 : <start>
2, // at 2 : <file>
3, // at 3 : <sign>
4, // at 4 : <description>
5, // at 5 : <OIL_version>
6, // at 6 : <application_definition>
7, // at 7 : <object_definition_list>
8, // at 8 : <boolean>
9, // at 9 : <oil_declaration_list>
10, // at 10 : <oil_declaration>
11, // at 11 : <include_file_level>
12, // at 12 : <include_cpu_level>
13, // at 13 : <include_object_level>
14, // at 14 : <implementation_object_list>
15, // at 15 : <include_implementation_level>
16, // at 16 : <include_type_level>
17, // at 17 : <implementation_objects>
18, // at 18 : <implementation_list>
19, // at 19 : <implementation_type>
20, // at 20 : <struct_options>
21, // at 21 : <objref_option>
22, // at 22 : <string_options>
23, // at 23 : <boolean_options>
24, // at 24 : <enum_item>
25, // at 25 : <enum_options>
26, // at 26 : <number_options>
27, // at 27 : <type_options>
28, // at 28 : <with_auto>
29, // at 29 : <int_or_float>
30, // at 30 : <set_followup>
31, // at 31 : <range_content>
32, // at 32 : <range>
33, // at 33 : <multiple>
34, // at 34 : <identifier_or_attribute>
35, // at 35 : <identifier_or_enum_value>
36, // at 36 : <select_goil_5F_syntax_0>
40, // at 37 : <select_goil_5F_syntax_1>
43, // at 38 : <select_goil_5F_syntax_2>
45, // at 39 : <select_goil_5F_syntax_3>
47, // at 40 : <select_goil_5F_syntax_4>
50, // at 41 : <select_goil_5F_syntax_5>
52, // at 42 : <select_goil_5F_syntax_6>
55, // at 43 : <select_goil_5F_syntax_7>
57, // at 44 : <select_goil_5F_syntax_8>
62, // at 45 : <select_goil_5F_syntax_9>
64, // at 46 : <select_goil_5F_syntax_10>
66, // at 47 : <select_goil_5F_syntax_11>
68, // at 48 : <select_goil_5F_syntax_12>
70, // at 49 : <select_goil_5F_syntax_13>
72, // at 50 : <select_goil_5F_syntax_14>
74, // at 51 : <select_goil_5F_syntax_15>
76, // at 52 : <select_goil_5F_syntax_16>
78, // at 53 : <select_goil_5F_syntax_17>
80, // at 54 : <select_implementation_5F_parser_0>
83, // at 55 : <select_implementation_5F_parser_1>
85, // at 56 : <select_implementation_5F_parser_2>
87, // at 57 : <select_implementation_5F_parser_3>
89, // at 58 : <select_implementation_5F_parser_4>
91, // at 59 : <select_implementation_5F_parser_5>
93, // at 60 : <select_implementation_5F_parser_6>
96, // at 61 : <select_implementation_5F_parser_7>
107, // at 62 : <select_implementation_5F_parser_8>
109, // at 63 : <select_implementation_5F_parser_9>
111, // at 64 : <select_implementation_5F_parser_10>
114, // at 65 : <select_implementation_5F_parser_11>
116, // at 66 : <select_implementation_5F_parser_12>
118, // at 67 : <select_implementation_5F_parser_13>
120, // at 68 : <select_implementation_5F_parser_14>
122, // at 69 : <select_implementation_5F_parser_15>
124, // at 70 : <select_implementation_5F_parser_16>
126, // at 71 : <select_implementation_5F_parser_17>
128, // at 72 : <select_implementation_5F_parser_18>
131, // at 73 : <select_implementation_5F_parser_19>
133, // at 74 : <select_implementation_5F_parser_20>
136, // at 75 : <select_implementation_5F_parser_21>
138, // at 76 : <select_implementation_5F_parser_22>
141, // at 77 : <select_implementation_5F_parser_23>
143, // at 78 : <select_implementation_5F_parser_24>
145, // at 79 : <select_implementation_5F_parser_25>
147, // at 80 : <select_implementation_5F_parser_26>
150, // at 81 : <select_implementation_5F_parser_27>
152, // at 82 : <select_implementation_5F_parser_28>
154, // at 83 : <select_implementation_5F_parser_29>
156, // at 84 : <select_implementation_5F_parser_30>
158, // at 85 : <>
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                    L L ( 1 )    D E C I S I O N    T A B L E S                                       
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gDecision_goil_type_level_include [] = {
// At index 0 : <implementation_definition> only one production, no choice
  -1,
// At index 1 : <start> only one production, no choice
  -1,
// At index 2 : <file> only one production, no choice
  -1,
// At index 3 : <sign> only one production, no choice
  -1,
// At index 4 : <description> only one production, no choice
  -1,
// At index 5 : <OIL_version> only one production, no choice
  -1,
// At index 6 : <application_definition> only one production, no choice
  -1,
// At index 7 : <object_definition_list> only one production, no choice
  -1,
// At index 8 : <boolean> only one production, no choice
  -1,
// At index 9 : <oil_declaration_list> only one production, no choice
  -1,
// At index 10 : <oil_declaration> only one production, no choice
  -1,
// At index 11 : <include_file_level> only one production, no choice
  -1,
// At index 12 : <include_cpu_level> only one production, no choice
  -1,
// At index 13 : <include_object_level> only one production, no choice
  -1,
// At index 14 : <implementation_object_list> only one production, no choice
  -1,
// At index 15 : <include_implementation_level> only one production, no choice
  -1,
// At index 16 : <include_type_level> only one production, no choice
  -1,
// At index 17 : <implementation_objects> only one production, no choice
  -1,
// At index 18 : <implementation_list> only one production, no choice
  -1,
// At index 19 : <implementation_type> only one production, no choice
  -1,
// At index 20 : <struct_options> only one production, no choice
  -1,
// At index 21 : <objref_option> only one production, no choice
  -1,
// At index 22 : <string_options> only one production, no choice
  -1,
// At index 23 : <boolean_options> only one production, no choice
  -1,
// At index 24 : <enum_item> only one production, no choice
  -1,
// At index 25 : <enum_options> only one production, no choice
  -1,
// At index 26 : <number_options> only one production, no choice
  -1,
// At index 27 : <type_options> only one production, no choice
  -1,
// At index 28 : <with_auto> only one production, no choice
  -1,
// At index 29 : <int_or_float> only one production, no choice
  -1,
// At index 30 : <set_followup> only one production, no choice
  -1,
// At index 31 : <range_content> only one production, no choice
  -1,
// At index 32 : <range> only one production, no choice
  -1,
// At index 33 : <multiple> only one production, no choice
  -1,
// At index 34 : <identifier_or_attribute> only one production, no choice
  -1,
// At index 35 : <identifier_or_enum_value> only one production, no choice
  -1,
//---- Added non terminal symbols from 'select' and 'repeat' instructions
// At index 36 : <select_goil_5F_syntax_0>
-1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_include, C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_IMPLEMENTATION, -1, // Choice 3
C_Lexique_goil_5F_lexique::kToken_CPU, -1, // Choice 4
  -1,
// At index 45 : <select_goil_5F_syntax_1>
C_Lexique_goil_5F_lexique::kToken__2D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__2B_, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_uint_5F_number, C_Lexique_goil_5F_lexique::kToken_float_5F_number, C_Lexique_goil_5F_lexique::kToken_set_5F_start_5F_uint_5F_number, -1, // Choice 3
  -1,
// At index 54 : <select_goil_5F_syntax_2>
C_Lexique_goil_5F_lexique::kToken__3B_, C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, -1, // Choice 2
  -1,
// At index 61 : <select_goil_5F_syntax_3>
C_Lexique_goil_5F_lexique::kToken__3B_, C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 68 : <select_goil_5F_syntax_4>
C_Lexique_goil_5F_lexique::kToken__7D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_include, C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 3
  -1,
// At index 76 : <select_goil_5F_syntax_5>
C_Lexique_goil_5F_lexique::kToken_TRUE, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_FALSE, -1, // Choice 2
  -1,
// At index 81 : <select_goil_5F_syntax_6>
C_Lexique_goil_5F_lexique::kToken__7D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_include, C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 3
  -1,
// At index 89 : <select_goil_5F_syntax_7>
C_Lexique_goil_5F_lexique::kToken__3D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
  -1,
// At index 94 : <select_goil_5F_syntax_8>
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__2D_, C_Lexique_goil_5F_lexique::kToken__2B_, C_Lexique_goil_5F_lexique::kToken_uint_5F_number, C_Lexique_goil_5F_lexique::kToken_float_5F_number, C_Lexique_goil_5F_lexique::kToken_set_5F_start_5F_uint_5F_number, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_TRUE, C_Lexique_goil_5F_lexique::kToken_FALSE, -1, // Choice 3
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 4
C_Lexique_goil_5F_lexique::kToken_AUTO, -1, // Choice 5
  -1,
// At index 110 : <select_goil_5F_syntax_9>
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, -1, // Choice 2
  -1,
// At index 116 : <select_goil_5F_syntax_10>
C_Lexique_goil_5F_lexique::kToken_uint_5F_number, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_float_5F_number, -1, // Choice 2
  -1,
// At index 121 : <select_goil_5F_syntax_11>
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, -1, // Choice 2
  -1,
// At index 127 : <select_goil_5F_syntax_12>
C_Lexique_goil_5F_lexique::kToken_include, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
  -1,
// At index 132 : <select_goil_5F_syntax_13>
C_Lexique_goil_5F_lexique::kToken_g_5F_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 137 : <select_goil_5F_syntax_14>
C_Lexique_goil_5F_lexique::kToken_include, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
  -1,
// At index 142 : <select_goil_5F_syntax_15>
C_Lexique_goil_5F_lexique::kToken_g_5F_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 147 : <select_goil_5F_syntax_16>
C_Lexique_goil_5F_lexique::kToken_include, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
  -1,
// At index 152 : <select_goil_5F_syntax_17>
C_Lexique_goil_5F_lexique::kToken_g_5F_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 157 : <select_implementation_5F_parser_0>
C_Lexique_goil_5F_lexique::kToken__7D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_include, C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 3
  -1,
// At index 165 : <select_implementation_5F_parser_1>
C_Lexique_goil_5F_lexique::kToken_include, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
  -1,
// At index 170 : <select_implementation_5F_parser_2>
C_Lexique_goil_5F_lexique::kToken_g_5F_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 175 : <select_implementation_5F_parser_3>
C_Lexique_goil_5F_lexique::kToken_include, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
  -1,
// At index 180 : <select_implementation_5F_parser_4>
C_Lexique_goil_5F_lexique::kToken_g_5F_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 185 : <select_implementation_5F_parser_5>
C_Lexique_goil_5F_lexique::kToken__5B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 2
  -1,
// At index 190 : <select_implementation_5F_parser_6>
C_Lexique_goil_5F_lexique::kToken__7D_, C_Lexique_goil_5F_lexique::kToken_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, C_Lexique_goil_5F_lexique::kToken_UINT_33__32_, C_Lexique_goil_5F_lexique::kToken_INT_33__32_, C_Lexique_goil_5F_lexique::kToken_UINT_36__34_, C_Lexique_goil_5F_lexique::kToken_INT_36__34_, C_Lexique_goil_5F_lexique::kToken_FLOAT, C_Lexique_goil_5F_lexique::kToken_ENUM, C_Lexique_goil_5F_lexique::kToken_BOOLEAN, C_Lexique_goil_5F_lexique::kToken_STRING, C_Lexique_goil_5F_lexique::kToken_IDENTIFIER, C_Lexique_goil_5F_lexique::kToken_STRUCT, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_include, C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 3
  -1,
// At index 209 : <select_implementation_5F_parser_7>
C_Lexique_goil_5F_lexique::kToken_UINT_33__32_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_INT_33__32_, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_UINT_36__34_, -1, // Choice 3
C_Lexique_goil_5F_lexique::kToken_INT_36__34_, -1, // Choice 4
C_Lexique_goil_5F_lexique::kToken_FLOAT, -1, // Choice 5
C_Lexique_goil_5F_lexique::kToken_ENUM, -1, // Choice 6
C_Lexique_goil_5F_lexique::kToken_BOOLEAN, -1, // Choice 7
C_Lexique_goil_5F_lexique::kToken_STRING, -1, // Choice 8
C_Lexique_goil_5F_lexique::kToken_IDENTIFIER, -1, // Choice 9
C_Lexique_goil_5F_lexique::kToken_STRUCT, -1, // Choice 10
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 11
  -1,
// At index 232 : <select_implementation_5F_parser_8>
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
  -1,
// At index 237 : <select_implementation_5F_parser_9>
C_Lexique_goil_5F_lexique::kToken__3D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 245 : <select_implementation_5F_parser_10>
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_AUTO, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT, -1, // Choice 3
  -1,
// At index 252 : <select_implementation_5F_parser_11>
C_Lexique_goil_5F_lexique::kToken__5B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
  -1,
// At index 257 : <select_implementation_5F_parser_12>
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 262 : <select_implementation_5F_parser_13>
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__5D_, -1, // Choice 2
  -1,
// At index 267 : <select_implementation_5F_parser_14>
C_Lexique_goil_5F_lexique::kToken__3D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 275 : <select_implementation_5F_parser_15>
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 281 : <select_implementation_5F_parser_16>
C_Lexique_goil_5F_lexique::kToken__5D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 286 : <select_implementation_5F_parser_17>
C_Lexique_goil_5F_lexique::kToken__3D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 294 : <select_implementation_5F_parser_18>
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_AUTO, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT, -1, // Choice 3
  -1,
// At index 301 : <select_implementation_5F_parser_19>
C_Lexique_goil_5F_lexique::kToken__3D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 309 : <select_implementation_5F_parser_20>
C_Lexique_goil_5F_lexique::kToken__2D_, C_Lexique_goil_5F_lexique::kToken__2B_, C_Lexique_goil_5F_lexique::kToken_uint_5F_number, C_Lexique_goil_5F_lexique::kToken_float_5F_number, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_AUTO, -1, // Choice 3
  -1,
// At index 319 : <select_implementation_5F_parser_21>
C_Lexique_goil_5F_lexique::kToken__3D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 327 : <select_implementation_5F_parser_22>
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_AUTO, -1, // Choice 3
  -1,
// At index 334 : <select_implementation_5F_parser_23>
C_Lexique_goil_5F_lexique::kToken_WITH_5F_AUTO, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, C_Lexique_goil_5F_lexique::kToken__5B_, -1, // Choice 2
  -1,
// At index 340 : <select_implementation_5F_parser_24>
C_Lexique_goil_5F_lexique::kToken_uint_5F_number, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_float_5F_number, -1, // Choice 2
  -1,
// At index 345 : <select_implementation_5F_parser_25>
C_Lexique_goil_5F_lexique::kToken__5D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 350 : <select_implementation_5F_parser_26>
C_Lexique_goil_5F_lexique::kToken_set_5F_start_5F_uint_5F_number, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_uint_5F_number, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_float_5F_number, -1, // Choice 3
  -1,
// At index 357 : <select_implementation_5F_parser_27>
C_Lexique_goil_5F_lexique::kToken__2E__2E_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 363 : <select_implementation_5F_parser_28>
C_Lexique_goil_5F_lexique::kToken__2E__2E_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 369 : <select_implementation_5F_parser_29>
C_Lexique_goil_5F_lexique::kToken__5B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
  -1,
// At index 374 : <select_implementation_5F_parser_30>
C_Lexique_goil_5F_lexique::kToken__5B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3D_, C_Lexique_goil_5F_lexique::kToken__3B_, -1, // Choice 2
  -1,
// At index 381 : <> only one production, no choice
  -1,
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            L L ( 1 )    D E C I S I O N    T A B L E S    I N D E X E S                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gDecisionIndexes_goil_type_level_include [87] = {
0, // at 0 : <implementation_definition>
1, // at 1 : <start>
2, // at 2 : <file>
3, // at 3 : <sign>
4, // at 4 : <description>
5, // at 5 : <OIL_version>
6, // at 6 : <application_definition>
7, // at 7 : <object_definition_list>
8, // at 8 : <boolean>
9, // at 9 : <oil_declaration_list>
10, // at 10 : <oil_declaration>
11, // at 11 : <include_file_level>
12, // at 12 : <include_cpu_level>
13, // at 13 : <include_object_level>
14, // at 14 : <implementation_object_list>
15, // at 15 : <include_implementation_level>
16, // at 16 : <include_type_level>
17, // at 17 : <implementation_objects>
18, // at 18 : <implementation_list>
19, // at 19 : <implementation_type>
20, // at 20 : <struct_options>
21, // at 21 : <objref_option>
22, // at 22 : <string_options>
23, // at 23 : <boolean_options>
24, // at 24 : <enum_item>
25, // at 25 : <enum_options>
26, // at 26 : <number_options>
27, // at 27 : <type_options>
28, // at 28 : <with_auto>
29, // at 29 : <int_or_float>
30, // at 30 : <set_followup>
31, // at 31 : <range_content>
32, // at 32 : <range>
33, // at 33 : <multiple>
34, // at 34 : <identifier_or_attribute>
35, // at 35 : <identifier_or_enum_value>
36, // at 36 : <select_goil_5F_syntax_0>
45, // at 37 : <select_goil_5F_syntax_1>
54, // at 38 : <select_goil_5F_syntax_2>
61, // at 39 : <select_goil_5F_syntax_3>
68, // at 40 : <select_goil_5F_syntax_4>
76, // at 41 : <select_goil_5F_syntax_5>
81, // at 42 : <select_goil_5F_syntax_6>
89, // at 43 : <select_goil_5F_syntax_7>
94, // at 44 : <select_goil_5F_syntax_8>
110, // at 45 : <select_goil_5F_syntax_9>
116, // at 46 : <select_goil_5F_syntax_10>
121, // at 47 : <select_goil_5F_syntax_11>
127, // at 48 : <select_goil_5F_syntax_12>
132, // at 49 : <select_goil_5F_syntax_13>
137, // at 50 : <select_goil_5F_syntax_14>
142, // at 51 : <select_goil_5F_syntax_15>
147, // at 52 : <select_goil_5F_syntax_16>
152, // at 53 : <select_goil_5F_syntax_17>
157, // at 54 : <select_implementation_5F_parser_0>
165, // at 55 : <select_implementation_5F_parser_1>
170, // at 56 : <select_implementation_5F_parser_2>
175, // at 57 : <select_implementation_5F_parser_3>
180, // at 58 : <select_implementation_5F_parser_4>
185, // at 59 : <select_implementation_5F_parser_5>
190, // at 60 : <select_implementation_5F_parser_6>
209, // at 61 : <select_implementation_5F_parser_7>
232, // at 62 : <select_implementation_5F_parser_8>
237, // at 63 : <select_implementation_5F_parser_9>
245, // at 64 : <select_implementation_5F_parser_10>
252, // at 65 : <select_implementation_5F_parser_11>
257, // at 66 : <select_implementation_5F_parser_12>
262, // at 67 : <select_implementation_5F_parser_13>
267, // at 68 : <select_implementation_5F_parser_14>
275, // at 69 : <select_implementation_5F_parser_15>
281, // at 70 : <select_implementation_5F_parser_16>
286, // at 71 : <select_implementation_5F_parser_17>
294, // at 72 : <select_implementation_5F_parser_18>
301, // at 73 : <select_implementation_5F_parser_19>
309, // at 74 : <select_implementation_5F_parser_20>
319, // at 75 : <select_implementation_5F_parser_21>
327, // at 76 : <select_implementation_5F_parser_22>
334, // at 77 : <select_implementation_5F_parser_23>
340, // at 78 : <select_implementation_5F_parser_24>
345, // at 79 : <select_implementation_5F_parser_25>
350, // at 80 : <select_implementation_5F_parser_26>
357, // at 81 : <select_implementation_5F_parser_27>
363, // at 82 : <select_implementation_5F_parser_28>
369, // at 83 : <select_implementation_5F_parser_29>
374, // at 84 : <select_implementation_5F_parser_30>
381, // at 85 : <>
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                              'implementation_definition' non terminal implementation                                 
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_implementation_5F_definition_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_definition_i0_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_implementation_5F_definition_ (GALGAS_implementation & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_definition_i0_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                        'start' non terminal implementation                                           
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_start_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_start_i0_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_start_ (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_start_i0_(inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                         'file' non terminal implementation                                           
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_file_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_file_i1_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_file_ (GALGAS_implementation & parameter_1,
                                GALGAS_applicationDefinition & parameter_2,
                                GALGAS_string & parameter_3,
                                const GALGAS_bool parameter_4,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_file_i1_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                         'sign' non terminal implementation                                           
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_sign_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_sign_i2_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_sign_ (GALGAS_bool & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_sign_i2_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                     'description' non terminal implementation                                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_description_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_description_i3_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_description_ (GALGAS_lstring & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_description_i3_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                     'OIL_version' non terminal implementation                                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_OIL_5F_version_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_OIL_5F_version_i4_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_OIL_5F_version_ (GALGAS_lstring & parameter_1,
                                GALGAS_lstring & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_OIL_5F_version_i4_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                'application_definition' non terminal implementation                                  
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_application_5F_definition_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_application_5F_definition_i5_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_application_5F_definition_ (const GALGAS_implementation parameter_1,
                                GALGAS_applicationDefinition & parameter_2,
                                GALGAS_string & parameter_3,
                                const GALGAS_bool parameter_4,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_application_5F_definition_i5_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                'object_definition_list' non terminal implementation                                  
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_object_5F_definition_5F_list_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_object_5F_definition_5F_list_i6_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_object_5F_definition_5F_list_ (const GALGAS_implementation parameter_1,
                                GALGAS_objectsMap & parameter_2,
                                GALGAS_string & parameter_3,
                                const GALGAS_bool parameter_4,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_object_5F_definition_5F_list_i6_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                       'boolean' non terminal implementation                                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_boolean_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_boolean_i7_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_boolean_ (GALGAS_lbool & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_boolean_i7_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                 'oil_declaration_list' non terminal implementation                                   
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_oil_5F_declaration_5F_list_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_5F_list_i8_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_oil_5F_declaration_5F_list_ (const GALGAS_implementationObjectMap parameter_1,
                                GALGAS_objectAttributes & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_5F_list_i8_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                   'oil_declaration' non terminal implementation                                      
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_oil_5F_declaration_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_i9_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_oil_5F_declaration_ (const GALGAS_implementationObjectMap parameter_1,
                                GALGAS_objectAttributes & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_i9_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                  'include_file_level' non terminal implementation                                    
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_include_5F_file_5F_level_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_file_5F_level_i10_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_include_5F_file_5F_level_ (GALGAS_implementation & parameter_1,
                                GALGAS_applicationDefinition & parameter_2,
                                GALGAS_string & parameter_3,
                                const GALGAS_bool parameter_4,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_file_5F_level_i10_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                  'include_cpu_level' non terminal implementation                                     
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_include_5F_cpu_5F_level_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_cpu_5F_level_i11_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_include_5F_cpu_5F_level_ (const GALGAS_implementation parameter_1,
                                GALGAS_objectsMap & parameter_2,
                                GALGAS_string & parameter_3,
                                const GALGAS_bool parameter_4,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_cpu_5F_level_i11_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                 'include_object_level' non terminal implementation                                   
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_include_5F_object_5F_level_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_object_5F_level_i12_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_include_5F_object_5F_level_ (const GALGAS_implementationObjectMap parameter_1,
                                GALGAS_objectAttributes & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_object_5F_level_i12_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                              'implementation_object_list' non terminal implementation                                
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_implementation_5F_object_5F_list_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_object_5F_list_i1_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_implementation_5F_object_5F_list_ (GALGAS_implementation & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_object_5F_list_i1_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                             'include_implementation_level' non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_include_5F_implementation_5F_level_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_include_5F_implementation_5F_level_i2_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_include_5F_implementation_5F_level_ (GALGAS_implementation & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_include_5F_implementation_5F_level_i2_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                  'include_type_level' non terminal implementation                                    
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_include_5F_type_5F_level_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_include_5F_type_5F_level_i3_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_include_5F_type_5F_level_ (GALGAS_implementationObjectMap & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_include_5F_type_5F_level_i3_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                'implementation_objects' non terminal implementation                                  
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_implementation_5F_objects_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_objects_i4_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_implementation_5F_objects_ (GALGAS_implementation & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_objects_i4_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                 'implementation_list' non terminal implementation                                    
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_implementation_5F_list_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_list_i5_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_implementation_5F_list_ (GALGAS_implementationObjectMap & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_list_i5_(parameter_1, inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::performIndexing (C_Compiler * /* inCompiler */,
             const C_String & /* inSourceFilePath */) {
}

void cGrammar_goil_5F_type_5F_level_5F_include::performOnlyLexicalAnalysis (C_Compiler * inCompiler,
             const C_String & inSourceFilePath) {
  C_Lexique_goil_5F_lexique * scanner = NULL ;
  macroMyNew (scanner, C_Lexique_goil_5F_lexique (inCompiler, inSourceFilePath COMMA_HERE)) ;
  if (scanner->sourceText ().isValid ()) {
    scanner->performLexicalAnalysis () ;
  }
  macroDetachSharedObject (scanner) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::performOnlySyntaxAnalysis (C_Compiler * inCompiler,
             const C_String & inSourceFilePath) {
  C_Lexique_goil_5F_lexique * scanner = NULL ;
  macroMyNew (scanner, C_Lexique_goil_5F_lexique (inCompiler, inSourceFilePath COMMA_HERE)) ;
  if (scanner->sourceText ().isValid ()) {
    scanner->performTopDownParsing (gProductions_goil_type_level_include, gProductionNames_goil_type_level_include, gProductionIndexes_goil_type_level_include,
                                    gFirstProductionIndexes_goil_type_level_include, gDecision_goil_type_level_include, gDecisionIndexes_goil_type_level_include, 448) ;
  }
  macroDetachSharedObject (scanner) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                        Grammar start symbol implementation                                           
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::_performSourceFileParsing_ (C_Compiler * inCompiler,
                                GALGAS_lstring inFilePath,
                                GALGAS_implementationObjectMap &  parameter_1
                                COMMA_LOCATION_ARGS) {
  if (inFilePath.isValid ()) {
    const GALGAS_string filePathAsString = inFilePath.getter_string (HERE) ;
    C_String filePath = filePathAsString.stringValue () ;
    if (! C_FileManager::isAbsolutePath (filePath)) {
      filePath = inCompiler->sourceFilePath ().stringByDeletingLastPathComponent ().stringByAppendingPathComponent (filePath) ;
    }
    if (C_FileManager::fileExistsAtPath (filePath)) {
    C_Lexique_goil_5F_lexique * scanner = NULL ;
    macroMyNew (scanner, C_Lexique_goil_5F_lexique (inCompiler, filePath COMMA_HERE)) ;
    if (scanner->sourceText ().isValid ()) {
      const bool ok = scanner->performTopDownParsing (gProductions_goil_type_level_include, gProductionNames_goil_type_level_include, gProductionIndexes_goil_type_level_include,
                                                      gFirstProductionIndexes_goil_type_level_include, gDecision_goil_type_level_include, gDecisionIndexes_goil_type_level_include, 448) ;
      if (ok && ! executionModeIsSyntaxAnalysisOnly ()) {
        cGrammar_goil_5F_type_5F_level_5F_include grammar ;
        grammar.nt_implementation_5F_list_ (parameter_1, scanner) ;
        }
      }else{
        C_String message ;
        message << "the '" << filePath << "' file exists, but cannot be read" ;
        const GALGAS_location errorLocation (inFilePath.getter_location (THERE)) ;
        inCompiler->semanticErrorAtLocation (errorLocation, message, TC_Array <C_FixItDescription> () COMMA_THERE) ;
      }
      macroDetachSharedObject (scanner) ;
    }else{
      C_String message ;
      message << "the '" << filePath << "' file does not exist" ;
      const GALGAS_location errorLocation (inFilePath.getter_location (THERE)) ;
      inCompiler->semanticErrorAtLocation (errorLocation, message, TC_Array <C_FixItDescription> () COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::_performSourceStringParsing_ (C_Compiler * inCompiler,
                                GALGAS_string inSourceString,
                                GALGAS_string inNameString,
                                GALGAS_implementationObjectMap &  parameter_1
                                COMMA_UNUSED_LOCATION_ARGS) {
  if (inSourceString.isValid () && inNameString.isValid ()) {
    const C_String sourceString = inSourceString.stringValue () ;
    const C_String nameString = inNameString.stringValue () ;
    C_Lexique_goil_5F_lexique * scanner = NULL ;
    macroMyNew (scanner, C_Lexique_goil_5F_lexique (inCompiler, sourceString, nameString COMMA_HERE)) ;
    const bool ok = scanner->performTopDownParsing (gProductions_goil_type_level_include, gProductionNames_goil_type_level_include, gProductionIndexes_goil_type_level_include,
                                                    gFirstProductionIndexes_goil_type_level_include, gDecision_goil_type_level_include, gDecisionIndexes_goil_type_level_include, 448) ;
    if (ok && ! executionModeIsSyntaxAnalysisOnly ()) {
      cGrammar_goil_5F_type_5F_level_5F_include grammar ;
      grammar.nt_implementation_5F_list_ (parameter_1, scanner) ;
    }
    macroDetachSharedObject (scanner) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                 'implementation_type' non terminal implementation                                    
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_implementation_5F_type_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_type_i6_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_implementation_5F_type_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_type_i6_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                    'struct_options' non terminal implementation                                      
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_struct_5F_options_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_struct_5F_options_i7_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_struct_5F_options_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_struct_5F_options_i7_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                    'objref_option' non terminal implementation                                       
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_objref_5F_option_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_objref_5F_option_i8_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_objref_5F_option_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                GALGAS_lstring parameter_3,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_objref_5F_option_i8_(parameter_1, parameter_2, parameter_3, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                    'string_options' non terminal implementation                                      
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_string_5F_options_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_string_5F_options_i9_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_string_5F_options_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_string_5F_options_i9_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                   'boolean_options' non terminal implementation                                      
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_boolean_5F_options_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_boolean_5F_options_i10_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_boolean_5F_options_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_boolean_5F_options_i10_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                      'enum_item' non terminal implementation                                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_enum_5F_item_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_enum_5F_item_i11_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_enum_5F_item_ (GALGAS_enumValues & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_enum_5F_item_i11_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                     'enum_options' non terminal implementation                                       
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_enum_5F_options_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_enum_5F_options_i12_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_enum_5F_options_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_enum_5F_options_i12_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                    'number_options' non terminal implementation                                      
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_number_5F_options_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_number_5F_options_i13_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_number_5F_options_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                const GALGAS_dataType parameter_3,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_number_5F_options_i13_(parameter_1, parameter_2, parameter_3, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                     'type_options' non terminal implementation                                       
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_type_5F_options_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_type_5F_options_i14_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_type_5F_options_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                const GALGAS_dataType parameter_3,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_type_5F_options_i14_(parameter_1, parameter_2, parameter_3, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                      'with_auto' non terminal implementation                                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_with_5F_auto_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_with_5F_auto_i15_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_with_5F_auto_ (GALGAS_bool & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_with_5F_auto_i15_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                     'int_or_float' non terminal implementation                                       
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_int_5F_or_5F_float_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_int_5F_or_5F_float_i16_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_int_5F_or_5F_float_ (GALGAS_object_5F_t & parameter_1,
                                const GALGAS_dataType parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_int_5F_or_5F_float_i16_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                     'set_followup' non terminal implementation                                       
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_set_5F_followup_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_set_5F_followup_i17_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_set_5F_followup_ (GALGAS_numberList & parameter_1,
                                const GALGAS_dataType parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_set_5F_followup_i17_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                    'range_content' non terminal implementation                                       
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_range_5F_content_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_range_5F_content_i18_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_range_5F_content_ (GALGAS_attributeRange & parameter_1,
                                const GALGAS_dataType parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_range_5F_content_i18_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                        'range' non terminal implementation                                           
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_range_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_range_i19_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_range_ (GALGAS_attributeRange & parameter_1,
                                const GALGAS_dataType parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_range_i19_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                       'multiple' non terminal implementation                                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_multiple_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_multiple_i20_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_multiple_ (GALGAS_bool & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_multiple_i20_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                               'identifier_or_attribute' non terminal implementation                                  
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_identifier_5F_or_5F_attribute_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_identifier_5F_or_5F_attribute_i21_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_identifier_5F_or_5F_attribute_ (GALGAS_lstring & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_identifier_5F_or_5F_attribute_i21_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                               'identifier_or_enum_value' non terminal implementation                                 
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_identifier_5F_or_5F_enum_5F_value_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_identifier_5F_or_5F_enum_5F_value_i22_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_identifier_5F_or_5F_enum_5F_value_ (GALGAS_lstring & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_identifier_5F_or_5F_enum_5F_value_i22_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_0' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_goil_5F_syntax_0 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_1' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_goil_5F_syntax_1 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_2' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_goil_5F_syntax_2 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_3' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_goil_5F_syntax_3 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_4' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_goil_5F_syntax_4 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_5' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_goil_5F_syntax_5 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_6' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_goil_5F_syntax_6 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_7' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_goil_5F_syntax_7 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_8' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_goil_5F_syntax_8 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_9' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_goil_5F_syntax_9 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_10' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_goil_5F_syntax_10 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_11' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_goil_5F_syntax_11 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_12' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_goil_5F_syntax_12 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_13' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_goil_5F_syntax_13 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_14' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_goil_5F_syntax_14 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_15' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_goil_5F_syntax_15 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_16' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_goil_5F_syntax_16 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_17' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_goil_5F_syntax_17 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_0' added non terminal implementation                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_0 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_1' added non terminal implementation                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_1 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_2' added non terminal implementation                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_2 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_3' added non terminal implementation                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_3 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_4' added non terminal implementation                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_4 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_5' added non terminal implementation                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_5 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_6' added non terminal implementation                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_6 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_7' added non terminal implementation                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_7 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_8' added non terminal implementation                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_8 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_9' added non terminal implementation                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_9 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_10' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_10 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_11' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_11 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_12' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_12 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_13' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_13 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_14' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_14 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_15' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_15 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_16' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_16 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_17' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_17 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_18' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_18 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_19' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_19 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_20' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_20 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_21' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_21 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_22' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_22 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_23' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_23 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_24' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_24 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_25' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_25 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_26' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_26 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_27' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_27 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_28' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_28 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_29' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_29 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_30' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_30 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*

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
    const GALGAS_string filePathAsString = inFilePath.getter_string (HERE) ;
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
        const GALGAS_location errorLocation (inFilePath.getter_location (THERE)) ;
        inCompiler->semanticErrorAtLocation (errorLocation, message, TC_Array <C_FixItDescription> () COMMA_THERE) ;
      }
      macroDetachSharedObject (scanner) ;
    }else{
      C_String message ;
      message << "the '" << filePath << "' file does not exist" ;
      const GALGAS_location errorLocation (inFilePath.getter_location (THERE)) ;
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
  GALGAS_bool var_debug_1100 = GALGAS_bool (false) ;
  GALGAS_string var_s_1226 = GALGAS_string::constructor_retrieveAndResetTemplateString (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 44)) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsStrictSup, var_s_1226.getter_length (SOURCE_FILE ("arxml_parser.galgas", 45)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
  if (kBoolTrue == test_0) {
    TC_Array <C_FixItDescription> fixItArray1 ;
    inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 46)), GALGAS_string ("No character is allowed before XML header"), fixItArray1  COMMA_SOURCE_FILE ("arxml_parser.galgas", 46)) ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxml_5F_scanner::kToken__3C__3F_) COMMA_SOURCE_FILE ("arxml_parser.galgas", 49)) ;
  GALGAS_lstring var_name_1404 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxml_5F_scanner::kToken_name) COMMA_SOURCE_FILE ("arxml_parser.galgas", 50)) ;
  GALGAS_arxmlAttributeMap var_attributes_1437 = GALGAS_arxmlAttributeMap::constructor_emptyMap (SOURCE_FILE ("arxml_parser.galgas", 52)) ;
  bool repeatFlag_2 = true ;
  while (repeatFlag_2) {
    switch (select_arxml_5F_parser_0 (inCompiler)) {
    case 2: {
      GALGAS_lstring var_attributeName_1505 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxml_5F_scanner::kToken_name) COMMA_SOURCE_FILE ("arxml_parser.galgas", 55)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxml_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxml_parser.galgas", 56)) ;
      GALGAS_lstring var_attributeValue_1554 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxml_5F_scanner::kToken_value) COMMA_SOURCE_FILE ("arxml_parser.galgas", 57)) ;
      {
      var_attributes_1437.setter_insertKey (var_attributeName_1505, var_attributeValue_1554, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 58)) ;
      }
    } break ;
    default:
      repeatFlag_2 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxml_5F_scanner::kToken__3F__3E_) COMMA_SOURCE_FILE ("arxml_parser.galgas", 60)) ;
  GALGAS_arxmlNodeList var_nodes_1668 = GALGAS_arxmlNodeList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 62)) ;
  nt_element_5F_list_ (var_nodes_1668, constinArgument_includeComments, constinArgument_doNotCondenseWhiteSpaces, inCompiler) ;
  outArgument_rootNode = GALGAS_arxmlElementNode::constructor_new (var_name_1404, var_attributes_1437, var_nodes_1668  COMMA_SOURCE_FILE ("arxml_parser.galgas", 68)) ;
  GALGAS_lstring var_autosarVersion_1992 = function_lstringWith (GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 79)) ;
  GALGAS_lstring var_autosarDescription_2041 = function_lstringWith (GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 80)) ;
  {
  routine_getAutosarVersion (outArgument_rootNode, var_autosarVersion_1992, var_autosarDescription_2041, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 81)) ;
  }
  const enumGalgasBool test_3 = GALGAS_bool (kIsEqual, var_autosarVersion_1992.mProperty_string.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
  if (kBoolTrue == test_3) {
    TC_Array <C_FixItDescription> fixItArray4 ;
    inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 84)), GALGAS_string ("[TPS_ECUC_06005][TPS_ECUC_08053] : Missing AUTOSAR version"), fixItArray4  COMMA_SOURCE_FILE ("arxml_parser.galgas", 84)) ;
  }
  GALGAS_stringlist var_autosarVlist_2349 = var_autosarVersion_1992.mProperty_string.getter_componentsSeparatedByString (GALGAS_string (".") COMMA_SOURCE_FILE ("arxml_parser.galgas", 88)) ;
  GALGAS_string var_versionFirst_2450 ;
  {
  var_autosarVlist_2349.setter_popFirst (var_versionFirst_2450, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 89)) ;
  }
  GALGAS_string var_versionSecond_2501 ;
  {
  var_autosarVlist_2349.setter_popFirst (var_versionSecond_2501, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 90)) ;
  }
  GALGAS_lstring var_autosarShortVersion_2533 = GALGAS_lstring::constructor_new (var_versionFirst_2450.add_operation (GALGAS_string ("."), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 91)).add_operation (var_versionSecond_2501, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 91)), var_autosarVersion_1992.getter_location (SOURCE_FILE ("arxml_parser.galgas", 92))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 91)) ;
  {
  routine_displayOil (GALGAS_string ("\n"
    "OIL_VERSION = \"").add_operation (var_autosarShortVersion_2533.getter_string (SOURCE_FILE ("arxml_parser.galgas", 93)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 93)).add_operation (GALGAS_string ("\";\n"
    "\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 93)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 93)) ;
  }
  {
  var_application_1024.setter_setVersion (var_autosarShortVersion_2533 COMMA_SOURCE_FILE ("arxml_parser.galgas", 95)) ;
  }
  {
  var_application_1024.setter_setVersionDescription (var_autosarDescription_2041 COMMA_SOURCE_FILE ("arxml_parser.galgas", 96)) ;
  }
  GALGAS_string var_autosarVersionNoDot_3034 = var_autosarVersion_1992.mProperty_string.getter_stringByReplacingStringByString (GALGAS_string ("."), GALGAS_string ("-"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 105)) ;
  GALGAS_string var_autosarMetaFile_3185 = GALGAS_string ("AUTOSAR_").add_operation (var_autosarVersionNoDot_3034, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 107)).add_operation (GALGAS_string (".xsd"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 107)) ;
  GALGAS_string var_filePath_3248 = function_templates_5F_directory (GALGAS_string ("arxmlMeta"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 108)).add_operation (var_autosarMetaFile_3185, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 108)) ;
  GALGAS_arxmlMetaClassMap var_classMap_3332 ;
  const enumGalgasBool test_5 = var_filePath_3248.getter_fileExists (SOURCE_FILE ("arxml_parser.galgas", 111)).operator_not (SOURCE_FILE ("arxml_parser.galgas", 111)).boolEnum () ;
  if (kBoolTrue == test_5) {
    TC_Array <C_FixItDescription> fixItArray6 ;
    inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 112)), GALGAS_string ("The corresponding metafile ").add_operation (var_filePath_3248, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 112)).add_operation (GALGAS_string (" does not"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 112)).add_operation (GALGAS_string (" exists. The Metamodel can be found here : "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 112)).add_operation (GALGAS_string ("http://www.autosar.org/specification -> Methodology and Templates -> "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 113)).add_operation (GALGAS_string ("Templates -> AUTOSAR_MMOD_XMLSchema.zip."), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 114)), fixItArray6  COMMA_SOURCE_FILE ("arxml_parser.galgas", 112)) ;
  }
  var_classMap_3332.drop () ;
  cGrammar_arxmlmetaparser_5F_grammar::_performSourceFileParsing_ (inCompiler, function_lstringWith (var_filePath_3248, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 118)), var_classMap_3332, var_debug_1100  COMMA_SOURCE_FILE ("arxml_parser.galgas", 118)) ;
  GALGAS_arxmlElementValue var_rootValue_3902 ;
  {
  routine_nodeToClass (outArgument_rootNode, var_classMap_3332, var_rootValue_3902, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 124)) ;
  }
  {
  routine_includeConfigs (var_imp_930, var_application_1024, var_fileIncludeList_1081, var_autosarShortVersion_2533, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 136)) ;
  }
  {
  routine_convertToOil (var_imp_930, var_application_1024, var_rootValue_3902, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 143)) ;
  }
  callExtensionMethod_checkObjectReferences ((const cPtr_implementation *) var_imp_930.ptr (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 154)) ;
  const enumGalgasBool test_7 = GALGAS_bool (kIsEqual, GALGAS_uint::constructor_errorCount (SOURCE_FILE ("arxml_parser.galgas", 156)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
  if (kBoolTrue == test_7) {
    {
    routine_setDefaults (var_imp_930, var_application_1024, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 157)) ;
    }
  }
  const enumGalgasBool test_8 = GALGAS_bool (kIsEqual, GALGAS_uint::constructor_errorCount (SOURCE_FILE ("arxml_parser.galgas", 164)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
  if (kBoolTrue == test_8) {
    {
    routine_verifyAll (var_imp_930, var_application_1024, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 165)) ;
    }
  }
  const enumGalgasBool test_9 = GALGAS_bool (kIsEqual, GALGAS_uint::constructor_errorCount (SOURCE_FILE ("arxml_parser.galgas", 167)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
  if (kBoolTrue == test_9) {
    GALGAS_gtlData var_templateData_5217 = callExtensionGetter_templateData ((const cPtr_applicationDefinition *) var_application_1024.ptr (), var_imp_930, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 168)) ;
    {
    routine_generate_5F_all (var_templateData_5217, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 171)) ;
    }
  }
  var_fileIncludeList_1081 = GALGAS_string::constructor_stringWithSourceFilePath (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 174)).getter_lastPathComponent (SOURCE_FILE ("arxml_parser.galgas", 174)).add_operation (GALGAS_string (":"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 174)).add_operation (var_fileIncludeList_1081, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 174)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 174)) ;
  GALGAS_string var_oilDepFileName_5528 = GALGAS_string::constructor_stringWithSourceFilePath (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 175)).getter_stringByDeletingLastPathComponent (SOURCE_FILE ("arxml_parser.galgas", 175)).add_operation (GALGAS_string ("/build/"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 175)).add_operation (GALGAS_string::constructor_stringWithSourceFilePath (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 176)).getter_lastPathComponent (SOURCE_FILE ("arxml_parser.galgas", 176)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 176)).add_operation (GALGAS_string (".dep"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 176)) ;
  var_fileIncludeList_1081.method_writeToFile (var_oilDepFileName_5528, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 178)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxml_5F_parser::rule_arxml_5F_parser_arxml_5F_start_5F_symbol_i0_parse (C_Lexique_arxml_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxml_5F_scanner::kToken__3C__3F_) COMMA_SOURCE_FILE ("arxml_parser.galgas", 49)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxml_5F_scanner::kToken_name) COMMA_SOURCE_FILE ("arxml_parser.galgas", 50)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_arxml_5F_parser_0 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxml_5F_scanner::kToken_name) COMMA_SOURCE_FILE ("arxml_parser.galgas", 55)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxml_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxml_parser.galgas", 56)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxml_5F_scanner::kToken_value) COMMA_SOURCE_FILE ("arxml_parser.galgas", 57)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxml_5F_scanner::kToken__3F__3E_) COMMA_SOURCE_FILE ("arxml_parser.galgas", 60)) ;
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
  GALGAS_lstring var_commentString_6443 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxml_5F_scanner::kToken_comment) COMMA_SOURCE_FILE ("arxml_parser.galgas", 210)) ;
  const enumGalgasBool test_0 = constinArgument_includeComments.boolEnum () ;
  if (kBoolTrue == test_0) {
    ioArgument_nodes.addAssign_operation (GALGAS_arxmlCommentNode::constructor_new (var_commentString_6443  COMMA_SOURCE_FILE ("arxml_parser.galgas", 212))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 212)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxml_5F_parser::rule_arxml_5F_parser_element_i2_parse (C_Lexique_arxml_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxml_5F_scanner::kToken_comment) COMMA_SOURCE_FILE ("arxml_parser.galgas", 210)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxml_5F_parser::rule_arxml_5F_parser_element_i3_ (GALGAS_arxmlNodeList & ioArgument_nodes,
                                                                const GALGAS_bool constinArgument_includeComments,
                                                                const GALGAS_bool constinArgument_doNotCondenseWhiteSpaces,
                                                                C_Lexique_arxml_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxml_5F_scanner::kToken__3C_) COMMA_SOURCE_FILE ("arxml_parser.galgas", 223)) ;
  GALGAS_lstring var_name_6768 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxml_5F_scanner::kToken_name) COMMA_SOURCE_FILE ("arxml_parser.galgas", 224)) ;
  GALGAS_arxmlAttributeMap var_attributeMap_6802 = GALGAS_arxmlAttributeMap::constructor_emptyMap (SOURCE_FILE ("arxml_parser.galgas", 225)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_arxml_5F_parser_2 (inCompiler)) {
    case 2: {
      GALGAS_lstring var_attributeName_6870 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxml_5F_scanner::kToken_name) COMMA_SOURCE_FILE ("arxml_parser.galgas", 228)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxml_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxml_parser.galgas", 229)) ;
      GALGAS_lstring var_attributeValue_6919 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxml_5F_scanner::kToken_value) COMMA_SOURCE_FILE ("arxml_parser.galgas", 230)) ;
      {
      var_attributeMap_6802.setter_insertKey (var_attributeName_6870, var_attributeValue_6919, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 231)) ;
      }
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  GALGAS_arxmlNodeList var_nodeList_7014 = GALGAS_arxmlNodeList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 234)) ;
  switch (select_arxml_5F_parser_3 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxml_5F_scanner::kToken__2F__3E_) COMMA_SOURCE_FILE ("arxml_parser.galgas", 236)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxml_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxml_parser.galgas", 238)) ;
    nt_element_5F_list_ (var_nodeList_7014, constinArgument_includeComments, constinArgument_doNotCondenseWhiteSpaces, inCompiler) ;
    {
    routine_addText (var_nodeList_7014, constinArgument_doNotCondenseWhiteSpaces, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 244)) ;
    }
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxml_5F_scanner::kToken__3C__2F_) COMMA_SOURCE_FILE ("arxml_parser.galgas", 246)) ;
    GALGAS_lstring var_closingName_7253 = inCompiler->synthetizedAttribute_tokenString () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxml_5F_scanner::kToken_name) COMMA_SOURCE_FILE ("arxml_parser.galgas", 247)) ;
    const enumGalgasBool test_1 = GALGAS_bool (kIsNotEqual, var_closingName_7253.getter_string (SOURCE_FILE ("arxml_parser.galgas", 248)).objectCompare (var_name_6768.getter_string (SOURCE_FILE ("arxml_parser.galgas", 248)))).boolEnum () ;
    if (kBoolTrue == test_1) {
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (var_closingName_7253.getter_location (SOURCE_FILE ("arxml_parser.galgas", 249)), GALGAS_string ("incorrect closing tag </").add_operation (var_closingName_7253.getter_string (SOURCE_FILE ("arxml_parser.galgas", 249)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 249)).add_operation (GALGAS_string ("> instead of </"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 250)).add_operation (var_name_6768.getter_string (SOURCE_FILE ("arxml_parser.galgas", 250)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 250)).add_operation (GALGAS_string (">"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 250)), fixItArray2  COMMA_SOURCE_FILE ("arxml_parser.galgas", 249)) ;
    }
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxml_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxml_parser.galgas", 252)) ;
  } break ;
  default:
    break ;
  }
  ioArgument_nodes.addAssign_operation (GALGAS_arxmlElementNode::constructor_new (var_name_6768, var_attributeMap_6802, var_nodeList_7014  COMMA_SOURCE_FILE ("arxml_parser.galgas", 255))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 255)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxml_5F_parser::rule_arxml_5F_parser_element_i3_parse (C_Lexique_arxml_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxml_5F_scanner::kToken__3C_) COMMA_SOURCE_FILE ("arxml_parser.galgas", 223)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxml_5F_scanner::kToken_name) COMMA_SOURCE_FILE ("arxml_parser.galgas", 224)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_arxml_5F_parser_2 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxml_5F_scanner::kToken_name) COMMA_SOURCE_FILE ("arxml_parser.galgas", 228)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxml_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxml_parser.galgas", 229)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxml_5F_scanner::kToken_value) COMMA_SOURCE_FILE ("arxml_parser.galgas", 230)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  switch (select_arxml_5F_parser_3 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxml_5F_scanner::kToken__2F__3E_) COMMA_SOURCE_FILE ("arxml_parser.galgas", 236)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxml_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxml_parser.galgas", 238)) ;
    nt_element_5F_list_parse (inCompiler) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxml_5F_scanner::kToken__3C__2F_) COMMA_SOURCE_FILE ("arxml_parser.galgas", 246)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxml_5F_scanner::kToken_name) COMMA_SOURCE_FILE ("arxml_parser.galgas", 247)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxml_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxml_parser.galgas", 252)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*


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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlElementNode::GALGAS_arxmlElementNode (void) :
GALGAS_arxmlNode () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlElementNode GALGAS_arxmlElementNode::constructor_default (LOCATION_ARGS) {
  return GALGAS_arxmlElementNode::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                                   GALGAS_arxmlAttributeMap::constructor_emptyMap (HERE),
                                                   GALGAS_arxmlNodeList::constructor_emptyList (HERE)
                                                   COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlElementNode::GALGAS_arxmlElementNode (const cPtr_arxmlElementNode * inSourcePtr) :
GALGAS_arxmlNode (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_arxmlElementNode) ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_arxmlElementNode::getter_name (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (NULL != mObjectPtr) {
    const cPtr_arxmlElementNode * p = (const cPtr_arxmlElementNode *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlElementNode) ;
    result = p->mProperty_name ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cPtr_arxmlElementNode::getter_name (UNUSED_LOCATION_ARGS) const {
  return mProperty_name ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlAttributeMap GALGAS_arxmlElementNode::getter_attributes (UNUSED_LOCATION_ARGS) const {
  GALGAS_arxmlAttributeMap result ;
  if (NULL != mObjectPtr) {
    const cPtr_arxmlElementNode * p = (const cPtr_arxmlElementNode *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlElementNode) ;
    result = p->mProperty_attributes ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlAttributeMap cPtr_arxmlElementNode::getter_attributes (UNUSED_LOCATION_ARGS) const {
  return mProperty_attributes ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlNodeList GALGAS_arxmlElementNode::getter_enclosedNodes (UNUSED_LOCATION_ARGS) const {
  GALGAS_arxmlNodeList result ;
  if (NULL != mObjectPtr) {
    const cPtr_arxmlElementNode * p = (const cPtr_arxmlElementNode *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlElementNode) ;
    result = p->mProperty_enclosedNodes ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlNodeList cPtr_arxmlElementNode::getter_enclosedNodes (UNUSED_LOCATION_ARGS) const {
  return mProperty_enclosedNodes ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                      Pointer class for @arxmlElementNode class                                      *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_arxmlElementNode::cPtr_arxmlElementNode (const GALGAS_lstring & in_name,
                                              const GALGAS_arxmlAttributeMap & in_attributes,
                                              const GALGAS_arxmlNodeList & in_enclosedNodes
                                              COMMA_LOCATION_ARGS) :
cPtr_arxmlNode (THERE),
mProperty_name (in_name),
mProperty_attributes (in_attributes),
mProperty_enclosedNodes (in_enclosedNodes) {
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_arxmlElementNode::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_arxmlElementNode (mProperty_name, mProperty_attributes, mProperty_enclosedNodes COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               @arxmlElementNode type                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_arxmlElementNode ("arxmlElementNode",
                                         & kTypeDescriptor_GALGAS_arxmlNode) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_arxmlElementNode::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_arxmlElementNode ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_arxmlElementNode::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_arxmlElementNode (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Extension method '@arxmlElementNode getSubElements'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionMethodSignature_arxmlElementNode_getSubElements> gExtensionMethodTable_arxmlElementNode_getSubElements ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_getSubElements (const int32_t inClassIndex,
                                          extensionMethodSignature_arxmlElementNode_getSubElements inMethod) {
  gExtensionMethodTable_arxmlElementNode_getSubElements.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_getSubElements (const cPtr_arxmlElementNode * inObject,
                                         GALGAS_arxmlElementList & out_nodeList,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
  out_nodeList.drop () ;
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_arxmlElementNode) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_arxmlElementNode_getSubElements f = NULL ;
    if (classIndex < gExtensionMethodTable_arxmlElementNode_getSubElements.count ()) {
      f = gExtensionMethodTable_arxmlElementNode_getSubElements (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_arxmlElementNode_getSubElements.count ()) {
           f = gExtensionMethodTable_arxmlElementNode_getSubElements (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_arxmlElementNode_getSubElements.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, out_nodeList, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_arxmlElementNode_getSubElements (const cPtr_arxmlElementNode * inObject,
                                                             GALGAS_arxmlElementList & outArgument_nodeList,
                                                             C_Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_arxmlElementNode * object = inObject ;
  macroValidSharedObject (object, cPtr_arxmlElementNode) ;
  outArgument_nodeList = GALGAS_arxmlElementList::constructor_emptyList (SOURCE_FILE ("arxml_types.galgas", 208)) ;
  cEnumerator_arxmlNodeList enumerator_4586 (object->mProperty_enclosedNodes, kENUMERATION_UP) ;
  while (enumerator_4586.hasCurrentObject ()) {
    const enumGalgasBool test_0 = GALGAS_bool (enumerator_4586.current_node (HERE).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_arxmlElementNode).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_arxmlElementNode temp_1 ;
      if (enumerator_4586.current_node (HERE).isValid ()) {
        if (NULL != dynamic_cast <const cPtr_arxmlElementNode *> (enumerator_4586.current_node (HERE).ptr ())) {
          temp_1 = (cPtr_arxmlElementNode *) enumerator_4586.current_node (HERE).ptr () ;
        }else{
          inCompiler->castError ("arxmlElementNode", enumerator_4586.current_node (HERE).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("arxml_types.galgas", 212)) ;
        }
      }
      GALGAS_arxmlElementNode var_currentElement_4676 = temp_1 ;
      outArgument_nodeList.addAssign_operation (var_currentElement_4676  COMMA_SOURCE_FILE ("arxml_types.galgas", 213)) ;
    }
    enumerator_4586.gotoNextObject () ;
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_arxmlElementNode_getSubElements (void) {
  enterExtensionMethod_getSubElements (kTypeDescriptor_GALGAS_arxmlElementNode.mSlotID,
                                       extensionMethod_arxmlElementNode_getSubElements) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionMethod_arxmlElementNode_getSubElements (void) {
  gExtensionMethodTable_arxmlElementNode_getSubElements.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_arxmlElementNode_getSubElements (defineExtensionMethod_arxmlElementNode_getSubElements,
                                                            freeExtensionMethod_arxmlElementNode_getSubElements) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Extension method '@arxmlElementNode getText'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionMethodSignature_arxmlElementNode_getText> gExtensionMethodTable_arxmlElementNode_getText ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_getText (const int32_t inClassIndex,
                                   extensionMethodSignature_arxmlElementNode_getText inMethod) {
  gExtensionMethodTable_arxmlElementNode_getText.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_getText (const cPtr_arxmlElementNode * inObject,
                                  GALGAS_lstring & io_value,
                                  GALGAS_bool & io_found,
                                  C_Compiler * inCompiler
                                  COMMA_LOCATION_ARGS) {
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_arxmlElementNode) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_arxmlElementNode_getText f = NULL ;
    if (classIndex < gExtensionMethodTable_arxmlElementNode_getText.count ()) {
      f = gExtensionMethodTable_arxmlElementNode_getText (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_arxmlElementNode_getText.count ()) {
           f = gExtensionMethodTable_arxmlElementNode_getText (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_arxmlElementNode_getText.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, io_value, io_found, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_arxmlElementNode_getText (const cPtr_arxmlElementNode * inObject,
                                                      GALGAS_lstring & ioArgument_value,
                                                      GALGAS_bool & ioArgument_found,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_arxmlElementNode * object = inObject ;
  macroValidSharedObject (object, cPtr_arxmlElementNode) ;
  cEnumerator_arxmlNodeList enumerator_5194 (object->mProperty_enclosedNodes, kENUMERATION_UP) ;
  bool bool_0 = ioArgument_found.operator_not (SOURCE_FILE ("arxml_types.galgas", 241)).isValidAndTrue () ;
  if (enumerator_5194.hasCurrentObject () && bool_0) {
    while (enumerator_5194.hasCurrentObject () && bool_0) {
      const enumGalgasBool test_1 = GALGAS_bool (enumerator_5194.current_node (HERE).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_arxmlTextNode).boolEnum () ;
      if (kBoolTrue == test_1) {
        GALGAS_arxmlTextNode temp_2 ;
        if (enumerator_5194.current_node (HERE).isValid ()) {
          if (NULL != dynamic_cast <const cPtr_arxmlTextNode *> (enumerator_5194.current_node (HERE).ptr ())) {
            temp_2 = (cPtr_arxmlTextNode *) enumerator_5194.current_node (HERE).ptr () ;
          }else{
            inCompiler->castError ("arxmlTextNode", enumerator_5194.current_node (HERE).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("arxml_types.galgas", 244)) ;
          }
        }
        GALGAS_arxmlTextNode var_textnode_5288 = temp_2 ;
        callExtensionMethod_getText ((const cPtr_arxmlTextNode *) var_textnode_5288.ptr (), ioArgument_value, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 245)) ;
        ioArgument_found = GALGAS_bool (true) ;
      }
      enumerator_5194.gotoNextObject () ;
      if (enumerator_5194.hasCurrentObject ()) {
        bool_0 = ioArgument_found.operator_not (SOURCE_FILE ("arxml_types.galgas", 241)).isValidAndTrue () ;
      }
    }
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_arxmlElementNode_getText (void) {
  enterExtensionMethod_getText (kTypeDescriptor_GALGAS_arxmlElementNode.mSlotID,
                                extensionMethod_arxmlElementNode_getText) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionMethod_arxmlElementNode_getText (void) {
  gExtensionMethodTable_arxmlElementNode_getText.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_arxmlElementNode_getText (defineExtensionMethod_arxmlElementNode_getText,
                                                     freeExtensionMethod_arxmlElementNode_getText) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Extension method '@arxmlElementNode getAttributes'                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionMethodSignature_arxmlElementNode_getAttributes> gExtensionMethodTable_arxmlElementNode_getAttributes ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_getAttributes (const int32_t inClassIndex,
                                         extensionMethodSignature_arxmlElementNode_getAttributes inMethod) {
  gExtensionMethodTable_arxmlElementNode_getAttributes.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_getAttributes (const cPtr_arxmlElementNode * inObject,
                                        GALGAS_arxmlAttributeMap & io_outAttributes,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) {
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_arxmlElementNode) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_arxmlElementNode_getAttributes f = NULL ;
    if (classIndex < gExtensionMethodTable_arxmlElementNode_getAttributes.count ()) {
      f = gExtensionMethodTable_arxmlElementNode_getAttributes (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_arxmlElementNode_getAttributes.count ()) {
           f = gExtensionMethodTable_arxmlElementNode_getAttributes (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_arxmlElementNode_getAttributes.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, io_outAttributes, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_arxmlElementNode_getAttributes (const cPtr_arxmlElementNode * inObject,
                                                            GALGAS_arxmlAttributeMap & ioArgument_outAttributes,
                                                            C_Compiler * /* inCompiler */
                                                            COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_arxmlElementNode * object = inObject ;
  macroValidSharedObject (object, cPtr_arxmlElementNode) ;
  ioArgument_outAttributes = object->mProperty_attributes ;
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_arxmlElementNode_getAttributes (void) {
  enterExtensionMethod_getAttributes (kTypeDescriptor_GALGAS_arxmlElementNode.mSlotID,
                                      extensionMethod_arxmlElementNode_getAttributes) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionMethod_arxmlElementNode_getAttributes (void) {
  gExtensionMethodTable_arxmlElementNode_getAttributes.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_arxmlElementNode_getAttributes (defineExtensionMethod_arxmlElementNode_getAttributes,
                                                           freeExtensionMethod_arxmlElementNode_getAttributes) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                  Extension method '@arxmlElementNode getAttribute'                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionMethodSignature_arxmlElementNode_getAttribute> gExtensionMethodTable_arxmlElementNode_getAttribute ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_getAttribute (const int32_t inClassIndex,
                                        extensionMethodSignature_arxmlElementNode_getAttribute inMethod) {
  gExtensionMethodTable_arxmlElementNode_getAttribute.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_getAttribute (const cPtr_arxmlElementNode * inObject,
                                       GALGAS_string in_attributeName,
                                       GALGAS_lstring & out_outAttribute,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) {
  out_outAttribute.drop () ;
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_arxmlElementNode) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_arxmlElementNode_getAttribute f = NULL ;
    if (classIndex < gExtensionMethodTable_arxmlElementNode_getAttribute.count ()) {
      f = gExtensionMethodTable_arxmlElementNode_getAttribute (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_arxmlElementNode_getAttribute.count ()) {
           f = gExtensionMethodTable_arxmlElementNode_getAttribute (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_arxmlElementNode_getAttribute.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, in_attributeName, out_outAttribute, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_arxmlElementNode_getAttribute (const cPtr_arxmlElementNode * inObject,
                                                           GALGAS_string inArgument_attributeName,
                                                           GALGAS_lstring & outArgument_outAttribute,
                                                           C_Compiler * inCompiler
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_arxmlElementNode * object = inObject ;
  macroValidSharedObject (object, cPtr_arxmlElementNode) ;
  object->mProperty_attributes.method_searchKey (function_lstringWith (inArgument_attributeName, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 261)), outArgument_outAttribute, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 261)) ;
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_arxmlElementNode_getAttribute (void) {
  enterExtensionMethod_getAttribute (kTypeDescriptor_GALGAS_arxmlElementNode.mSlotID,
                                     extensionMethod_arxmlElementNode_getAttribute) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionMethod_arxmlElementNode_getAttribute (void) {
  gExtensionMethodTable_arxmlElementNode_getAttribute.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_arxmlElementNode_getAttribute (defineExtensionMethod_arxmlElementNode_getAttribute,
                                                          freeExtensionMethod_arxmlElementNode_getAttribute) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Extension method '@arxmlElementNode getName'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionMethodSignature_arxmlElementNode_getName> gExtensionMethodTable_arxmlElementNode_getName ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_getName (const int32_t inClassIndex,
                                   extensionMethodSignature_arxmlElementNode_getName inMethod) {
  gExtensionMethodTable_arxmlElementNode_getName.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_getName (const cPtr_arxmlElementNode * inObject,
                                  GALGAS_lstring & out_outName,
                                  C_Compiler * inCompiler
                                  COMMA_LOCATION_ARGS) {
  out_outName.drop () ;
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_arxmlElementNode) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_arxmlElementNode_getName f = NULL ;
    if (classIndex < gExtensionMethodTable_arxmlElementNode_getName.count ()) {
      f = gExtensionMethodTable_arxmlElementNode_getName (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_arxmlElementNode_getName.count ()) {
           f = gExtensionMethodTable_arxmlElementNode_getName (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_arxmlElementNode_getName.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, out_outName, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_arxmlElementNode_getName (const cPtr_arxmlElementNode * inObject,
                                                      GALGAS_lstring & outArgument_outName,
                                                      C_Compiler * /* inCompiler */
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_arxmlElementNode * object = inObject ;
  macroValidSharedObject (object, cPtr_arxmlElementNode) ;
  outArgument_outName = object->mProperty_name ;
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_arxmlElementNode_getName (void) {
  enterExtensionMethod_getName (kTypeDescriptor_GALGAS_arxmlElementNode.mSlotID,
                                extensionMethod_arxmlElementNode_getName) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionMethod_arxmlElementNode_getName (void) {
  gExtensionMethodTable_arxmlElementNode_getName.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_arxmlElementNode_getName (defineExtensionMethod_arxmlElementNode_getName,
                                                     freeExtensionMethod_arxmlElementNode_getName) ;

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_arxmlCommentNode::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_arxmlCommentNode * p = (const cPtr_arxmlCommentNode *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_arxmlCommentNode) ;
  if (kOperandEqual == result) {
    result = mProperty_comment.objectCompare (p->mProperty_comment) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlCommentNode::GALGAS_arxmlCommentNode (void) :
GALGAS_arxmlNode () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlCommentNode GALGAS_arxmlCommentNode::constructor_default (LOCATION_ARGS) {
  return GALGAS_arxmlCommentNode::constructor_new (GALGAS_lstring::constructor_default (HERE)
                                                   COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlCommentNode::GALGAS_arxmlCommentNode (const cPtr_arxmlCommentNode * inSourcePtr) :
GALGAS_arxmlNode (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_arxmlCommentNode) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlCommentNode GALGAS_arxmlCommentNode::constructor_new (const GALGAS_lstring & inAttribute_comment
                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_arxmlCommentNode result ;
  if (inAttribute_comment.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_arxmlCommentNode (inAttribute_comment COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_arxmlCommentNode::getter_comment (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (NULL != mObjectPtr) {
    const cPtr_arxmlCommentNode * p = (const cPtr_arxmlCommentNode *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlCommentNode) ;
    result = p->mProperty_comment ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cPtr_arxmlCommentNode::getter_comment (UNUSED_LOCATION_ARGS) const {
  return mProperty_comment ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                      Pointer class for @arxmlCommentNode class                                      *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_arxmlCommentNode::cPtr_arxmlCommentNode (const GALGAS_lstring & in_comment
                                              COMMA_LOCATION_ARGS) :
cPtr_arxmlNode (THERE),
mProperty_comment (in_comment) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_arxmlCommentNode::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_arxmlCommentNode ;
}

void cPtr_arxmlCommentNode::description (C_String & ioString,
                                         const int32_t inIndentation) const {
  ioString << "[@arxmlCommentNode:" ;
  mProperty_comment.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_arxmlCommentNode::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_arxmlCommentNode (mProperty_comment COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               @arxmlCommentNode type                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_arxmlCommentNode ("arxmlCommentNode",
                                         & kTypeDescriptor_GALGAS_arxmlNode) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_arxmlCommentNode::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_arxmlCommentNode ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_arxmlCommentNode::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_arxmlCommentNode (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_arxmlTextNode::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_arxmlTextNode * p = (const cPtr_arxmlTextNode *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_arxmlTextNode) ;
  if (kOperandEqual == result) {
    result = mProperty_text.objectCompare (p->mProperty_text) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlTextNode::GALGAS_arxmlTextNode (void) :
GALGAS_arxmlNode () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlTextNode GALGAS_arxmlTextNode::constructor_default (LOCATION_ARGS) {
  return GALGAS_arxmlTextNode::constructor_new (GALGAS_lstring::constructor_default (HERE)
                                                COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlTextNode::GALGAS_arxmlTextNode (const cPtr_arxmlTextNode * inSourcePtr) :
GALGAS_arxmlNode (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_arxmlTextNode) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlTextNode GALGAS_arxmlTextNode::constructor_new (const GALGAS_lstring & inAttribute_text
                                                            COMMA_LOCATION_ARGS) {
  GALGAS_arxmlTextNode result ;
  if (inAttribute_text.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_arxmlTextNode (inAttribute_text COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_arxmlTextNode::getter_text (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (NULL != mObjectPtr) {
    const cPtr_arxmlTextNode * p = (const cPtr_arxmlTextNode *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlTextNode) ;
    result = p->mProperty_text ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cPtr_arxmlTextNode::getter_text (UNUSED_LOCATION_ARGS) const {
  return mProperty_text ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                       Pointer class for @arxmlTextNode class                                        *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_arxmlTextNode::cPtr_arxmlTextNode (const GALGAS_lstring & in_text
                                        COMMA_LOCATION_ARGS) :
cPtr_arxmlNode (THERE),
mProperty_text (in_text) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_arxmlTextNode::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_arxmlTextNode ;
}

void cPtr_arxmlTextNode::description (C_String & ioString,
                                      const int32_t inIndentation) const {
  ioString << "[@arxmlTextNode:" ;
  mProperty_text.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_arxmlTextNode::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_arxmlTextNode (mProperty_text COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 @arxmlTextNode type                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_arxmlTextNode ("arxmlTextNode",
                                      & kTypeDescriptor_GALGAS_arxmlNode) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_arxmlTextNode::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_arxmlTextNode ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_arxmlTextNode::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_arxmlTextNode (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Extension method '@arxmlTextNode getText'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionMethodSignature_arxmlTextNode_getText> gExtensionMethodTable_arxmlTextNode_getText ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_getText (const int32_t inClassIndex,
                                   extensionMethodSignature_arxmlTextNode_getText inMethod) {
  gExtensionMethodTable_arxmlTextNode_getText.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_getText (const cPtr_arxmlTextNode * inObject,
                                  GALGAS_lstring & out_outText,
                                  C_Compiler * inCompiler
                                  COMMA_LOCATION_ARGS) {
  out_outText.drop () ;
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_arxmlTextNode) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_arxmlTextNode_getText f = NULL ;
    if (classIndex < gExtensionMethodTable_arxmlTextNode_getText.count ()) {
      f = gExtensionMethodTable_arxmlTextNode_getText (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_arxmlTextNode_getText.count ()) {
           f = gExtensionMethodTable_arxmlTextNode_getText (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_arxmlTextNode_getText.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, out_outText, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_arxmlTextNode_getText (const cPtr_arxmlTextNode * inObject,
                                                   GALGAS_lstring & outArgument_outText,
                                                   C_Compiler * /* inCompiler */
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_arxmlTextNode * object = inObject ;
  macroValidSharedObject (object, cPtr_arxmlTextNode) ;
  outArgument_outText = object->mProperty_text ;
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_arxmlTextNode_getText (void) {
  enterExtensionMethod_getText (kTypeDescriptor_GALGAS_arxmlTextNode.mSlotID,
                                extensionMethod_arxmlTextNode_getText) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionMethod_arxmlTextNode_getText (void) {
  gExtensionMethodTable_arxmlTextNode_getText.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_arxmlTextNode_getText (defineExtensionMethod_arxmlTextNode_getText,
                                                  freeExtensionMethod_arxmlTextNode_getText) ;

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*


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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlElementValue::GALGAS_arxmlElementValue (void) :
AC_GALGAS_class () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlElementValue GALGAS_arxmlElementValue::constructor_default (LOCATION_ARGS) {
  return GALGAS_arxmlElementValue::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                                    GALGAS_lstring::constructor_default (HERE),
                                                    GALGAS_arxmlElementValueMap::constructor_emptyMap (HERE),
                                                    GALGAS_arxmlAttributeMap::constructor_emptyMap (HERE)
                                                    COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlElementValue::GALGAS_arxmlElementValue (const cPtr_arxmlElementValue * inSourcePtr) :
AC_GALGAS_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_arxmlElementValue) ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_arxmlElementValue::getter_type (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (NULL != mObjectPtr) {
    const cPtr_arxmlElementValue * p = (const cPtr_arxmlElementValue *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlElementValue) ;
    result = p->mProperty_type ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cPtr_arxmlElementValue::getter_type (UNUSED_LOCATION_ARGS) const {
  return mProperty_type ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_arxmlElementValue::getter_text (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (NULL != mObjectPtr) {
    const cPtr_arxmlElementValue * p = (const cPtr_arxmlElementValue *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlElementValue) ;
    result = p->mProperty_text ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cPtr_arxmlElementValue::getter_text (UNUSED_LOCATION_ARGS) const {
  return mProperty_text ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlElementValueMap GALGAS_arxmlElementValue::getter_elements (UNUSED_LOCATION_ARGS) const {
  GALGAS_arxmlElementValueMap result ;
  if (NULL != mObjectPtr) {
    const cPtr_arxmlElementValue * p = (const cPtr_arxmlElementValue *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlElementValue) ;
    result = p->mProperty_elements ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlElementValueMap cPtr_arxmlElementValue::getter_elements (UNUSED_LOCATION_ARGS) const {
  return mProperty_elements ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlAttributeMap GALGAS_arxmlElementValue::getter_attributes (UNUSED_LOCATION_ARGS) const {
  GALGAS_arxmlAttributeMap result ;
  if (NULL != mObjectPtr) {
    const cPtr_arxmlElementValue * p = (const cPtr_arxmlElementValue *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlElementValue) ;
    result = p->mProperty_attributes ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlAttributeMap cPtr_arxmlElementValue::getter_attributes (UNUSED_LOCATION_ARGS) const {
  return mProperty_attributes ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                     Pointer class for @arxmlElementValue class                                      *
//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_arxmlElementValue::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_arxmlElementValue (mProperty_type, mProperty_text, mProperty_elements, mProperty_attributes COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               @arxmlElementValue type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_arxmlElementValue ("arxmlElementValue",
                                          NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_arxmlElementValue::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_arxmlElementValue ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_arxmlElementValue::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_arxmlElementValue (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Extension setter '@arxmlElementValue insertElement'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionSetterSignature_arxmlElementValue_insertElement> gExtensionModifierTable_arxmlElementValue_insertElement ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_insertElement (const int32_t inClassIndex,
                                         extensionSetterSignature_arxmlElementValue_insertElement inModifier) {
  gExtensionModifierTable_arxmlElementValue_insertElement.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_arxmlElementValue_insertElement (cPtr_arxmlElementValue * inObject,
                                                             GALGAS_lstring inArgument_key,
                                                             GALGAS_arxmlElementValue inArgument_element,
                                                             C_Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_arxmlElementValue * object = inObject ;
  macroValidSharedObject (object, cPtr_arxmlElementValue) ;
  GALGAS_arxmlElementValueList var_keyList_8388 ;
  const enumGalgasBool test_0 = object->mProperty_elements.getter_hasKey (inArgument_key.getter_string (SOURCE_FILE ("arxml_types.galgas", 385)) COMMA_SOURCE_FILE ("arxml_types.galgas", 385)).boolEnum () ;
  if (kBoolTrue == test_0) {
    {
    object->mProperty_elements.setter_removeKey (inArgument_key, var_keyList_8388, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 386)) ;
    }
  }else if (kBoolFalse == test_0) {
    var_keyList_8388 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_types.galgas", 388)) ;
  }
  var_keyList_8388.addAssign_operation (inArgument_element  COMMA_SOURCE_FILE ("arxml_types.galgas", 390)) ;
  {
  object->mProperty_elements.setter_insertKey (inArgument_key, var_keyList_8388, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 391)) ;
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_arxmlElementValue_insertElement (void) {
  enterExtensionSetter_insertElement (kTypeDescriptor_GALGAS_arxmlElementValue.mSlotID,
                                      extensionSetter_arxmlElementValue_insertElement) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionModifier_arxmlElementValue_insertElement (void) {
  gExtensionModifierTable_arxmlElementValue_insertElement.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_arxmlElementValue_insertElement (defineExtensionSetter_arxmlElementValue_insertElement,
                                                            freeExtensionModifier_arxmlElementValue_insertElement) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               Extension method '@arxmlElementValue getElementsByPath'                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionMethodSignature_arxmlElementValue_getElementsByPath> gExtensionMethodTable_arxmlElementValue_getElementsByPath ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_getElementsByPath (const int32_t inClassIndex,
                                             extensionMethodSignature_arxmlElementValue_getElementsByPath inMethod) {
  gExtensionMethodTable_arxmlElementValue_getElementsByPath.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_getElementsByPath (const cPtr_arxmlElementValue * inObject,
                                            GALGAS_stringlist in_path,
                                            GALGAS_arxmlElementValueList & io_outElements,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_arxmlElementValue) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_arxmlElementValue_getElementsByPath f = NULL ;
    if (classIndex < gExtensionMethodTable_arxmlElementValue_getElementsByPath.count ()) {
      f = gExtensionMethodTable_arxmlElementValue_getElementsByPath (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_arxmlElementValue_getElementsByPath.count ()) {
           f = gExtensionMethodTable_arxmlElementValue_getElementsByPath (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_arxmlElementValue_getElementsByPath.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, in_path, io_outElements, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_arxmlElementValue_getElementsByPath (const cPtr_arxmlElementValue * inObject,
                                                                 GALGAS_stringlist inArgument_path,
                                                                 GALGAS_arxmlElementValueList & ioArgument_outElements,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_arxmlElementValue * object = inObject ;
  macroValidSharedObject (object, cPtr_arxmlElementValue) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, inArgument_path.getter_length (SOURCE_FILE ("arxml_types.galgas", 398)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
  if (kBoolTrue == test_0) {
    const GALGAS_arxmlElementValue temp_1 = object ;
    ioArgument_outElements.addAssign_operation (temp_1  COMMA_SOURCE_FILE ("arxml_types.galgas", 399)) ;
  }else if (kBoolFalse == test_0) {
    GALGAS_stringlist var_pathCopy_8747 = inArgument_path ;
    GALGAS_string var_nextInPathName_8781 ;
    GALGAS_arxmlElementValueList var_nextInPathElems_8824 ;
    {
    var_pathCopy_8747.setter_popFirst (var_nextInPathName_8781, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 404)) ;
    }
    const GALGAS_arxmlElementValue temp_2 = object ;
    callExtensionMethod_getElements ((const cPtr_arxmlElementValue *) temp_2.ptr (), var_nextInPathName_8781, var_nextInPathElems_8824, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 405)) ;
    cEnumerator_arxmlElementValueList enumerator_8978 (var_nextInPathElems_8824, kENUMERATION_UP) ;
    while (enumerator_8978.hasCurrentObject ()) {
      callExtensionMethod_getElementsByPath ((const cPtr_arxmlElementValue *) enumerator_8978.current_value (HERE).ptr (), var_pathCopy_8747, ioArgument_outElements, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 407)) ;
      enumerator_8978.gotoNextObject () ;
    }
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_arxmlElementValue_getElementsByPath (void) {
  enterExtensionMethod_getElementsByPath (kTypeDescriptor_GALGAS_arxmlElementValue.mSlotID,
                                          extensionMethod_arxmlElementValue_getElementsByPath) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionMethod_arxmlElementValue_getElementsByPath (void) {
  gExtensionMethodTable_arxmlElementValue_getElementsByPath.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_arxmlElementValue_getElementsByPath (defineExtensionMethod_arxmlElementValue_getElementsByPath,
                                                                freeExtensionMethod_arxmlElementValue_getElementsByPath) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                  Extension method '@arxmlElementValue getElements'                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionMethodSignature_arxmlElementValue_getElements> gExtensionMethodTable_arxmlElementValue_getElements ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_getElements (const int32_t inClassIndex,
                                       extensionMethodSignature_arxmlElementValue_getElements inMethod) {
  gExtensionMethodTable_arxmlElementValue_getElements.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_getElements (const cPtr_arxmlElementValue * inObject,
                                      GALGAS_string in_elementName,
                                      GALGAS_arxmlElementValueList & out_outElements,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) {
  out_outElements.drop () ;
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_arxmlElementValue) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_arxmlElementValue_getElements f = NULL ;
    if (classIndex < gExtensionMethodTable_arxmlElementValue_getElements.count ()) {
      f = gExtensionMethodTable_arxmlElementValue_getElements (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_arxmlElementValue_getElements.count ()) {
           f = gExtensionMethodTable_arxmlElementValue_getElements (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_arxmlElementValue_getElements.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, in_elementName, out_outElements, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_arxmlElementValue_getElements (const cPtr_arxmlElementValue * inObject,
                                                           GALGAS_string inArgument_elementName,
                                                           GALGAS_arxmlElementValueList & outArgument_outElements,
                                                           C_Compiler * inCompiler
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_arxmlElementValue * object = inObject ;
  macroValidSharedObject (object, cPtr_arxmlElementValue) ;
  GALGAS_lstring var_key_9173 = GALGAS_lstring::constructor_new (inArgument_elementName, GALGAS_location::constructor_nowhere (SOURCE_FILE ("arxml_types.galgas", 416))  COMMA_SOURCE_FILE ("arxml_types.galgas", 416)) ;
  const enumGalgasBool test_0 = object->mProperty_elements.getter_hasKey (var_key_9173.getter_string (SOURCE_FILE ("arxml_types.galgas", 417)) COMMA_SOURCE_FILE ("arxml_types.galgas", 417)).boolEnum () ;
  if (kBoolTrue == test_0) {
    object->mProperty_elements.method_searchKey (var_key_9173, outArgument_outElements, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 418)) ;
  }else if (kBoolFalse == test_0) {
    outArgument_outElements = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_types.galgas", 420)) ;
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_arxmlElementValue_getElements (void) {
  enterExtensionMethod_getElements (kTypeDescriptor_GALGAS_arxmlElementValue.mSlotID,
                                    extensionMethod_arxmlElementValue_getElements) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionMethod_arxmlElementValue_getElements (void) {
  gExtensionMethodTable_arxmlElementValue_getElements.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_arxmlElementValue_getElements (defineExtensionMethod_arxmlElementValue_getElements,
                                                          freeExtensionMethod_arxmlElementValue_getElements) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                  Extension method '@arxmlElementValue getElement'                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionMethodSignature_arxmlElementValue_getElement> gExtensionMethodTable_arxmlElementValue_getElement ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_getElement (const int32_t inClassIndex,
                                      extensionMethodSignature_arxmlElementValue_getElement inMethod) {
  gExtensionMethodTable_arxmlElementValue_getElement.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_getElement (const cPtr_arxmlElementValue * inObject,
                                     GALGAS_string in_elementName,
                                     GALGAS_arxmlElementValue & out_outElement,
                                     C_Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) {
  out_outElement.drop () ;
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_arxmlElementValue) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_arxmlElementValue_getElement f = NULL ;
    if (classIndex < gExtensionMethodTable_arxmlElementValue_getElement.count ()) {
      f = gExtensionMethodTable_arxmlElementValue_getElement (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_arxmlElementValue_getElement.count ()) {
           f = gExtensionMethodTable_arxmlElementValue_getElement (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_arxmlElementValue_getElement.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, in_elementName, out_outElement, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_arxmlElementValue_getElement (const cPtr_arxmlElementValue * inObject,
                                                          GALGAS_string inArgument_elementName,
                                                          GALGAS_arxmlElementValue & outArgument_outElement,
                                                          C_Compiler * inCompiler
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_arxmlElementValue * object = inObject ;
  macroValidSharedObject (object, cPtr_arxmlElementValue) ;
  GALGAS_arxmlElementValueList var_foundElements_9451 ;
  const GALGAS_arxmlElementValue temp_0 = object ;
  callExtensionMethod_getElements ((const cPtr_arxmlElementValue *) temp_0.ptr (), inArgument_elementName, var_foundElements_9451, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 429)) ;
  const enumGalgasBool test_1 = GALGAS_bool (kIsNotEqual, var_foundElements_9451.getter_length (SOURCE_FILE ("arxml_types.galgas", 430)).objectCompare (GALGAS_uint ((uint32_t) 1U))).boolEnum () ;
  if (kBoolTrue == test_1) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxml_types.galgas", 431)), GALGAS_string ("Found ").add_operation (var_foundElements_9451.getter_length (SOURCE_FILE ("arxml_types.galgas", 431)).getter_string (SOURCE_FILE ("arxml_types.galgas", 431)), inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 431)).add_operation (GALGAS_string (" elements"), inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 431)).add_operation (GALGAS_string (" while searching for exactly one "), inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 431)).add_operation (inArgument_elementName, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 432)).add_operation (GALGAS_string (" in "), inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 432)).add_operation (object->mProperty_type.getter_string (SOURCE_FILE ("arxml_types.galgas", 433)), inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 433)), fixItArray2  COMMA_SOURCE_FILE ("arxml_types.galgas", 431)) ;
    outArgument_outElement.drop () ; // Release error dropped variable
  }else if (kBoolFalse == test_1) {
    var_foundElements_9451.method_first (outArgument_outElement, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 435)) ;
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_arxmlElementValue_getElement (void) {
  enterExtensionMethod_getElement (kTypeDescriptor_GALGAS_arxmlElementValue.mSlotID,
                                   extensionMethod_arxmlElementValue_getElement) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionMethod_arxmlElementValue_getElement (void) {
  gExtensionMethodTable_arxmlElementValue_getElement.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_arxmlElementValue_getElement (defineExtensionMethod_arxmlElementValue_getElement,
                                                         freeExtensionMethod_arxmlElementValue_getElement) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                  Extension getter '@arxmlElementValue hasElement'                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_arxmlElementValue_hasElement> gExtensionGetterTable_arxmlElementValue_hasElement ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_hasElement (const int32_t inClassIndex,
                                      enterExtensionGetter_arxmlElementValue_hasElement inGetter) {
  gExtensionGetterTable_arxmlElementValue_hasElement.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool callExtensionGetter_hasElement (const cPtr_arxmlElementValue * inObject,
                                            GALGAS_string in_elementName,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
  GALGAS_bool result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_arxmlElementValue) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_arxmlElementValue_hasElement f = NULL ;
    if (classIndex < gExtensionGetterTable_arxmlElementValue_hasElement.count ()) {
      f = gExtensionGetterTable_arxmlElementValue_hasElement (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_arxmlElementValue_hasElement.count ()) {
           f = gExtensionGetterTable_arxmlElementValue_hasElement (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_arxmlElementValue_hasElement.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_elementName, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_bool extensionGetter_arxmlElementValue_hasElement (const cPtr_arxmlElementValue * inObject,
                                                                 GALGAS_string inArgument_elementName,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_outBool ; // Returned variable
  const cPtr_arxmlElementValue * object = inObject ;
  macroValidSharedObject (object, cPtr_arxmlElementValue) ;
  GALGAS_arxmlElementValueList var_foundElements_9900 ;
  const GALGAS_arxmlElementValue temp_0 = object ;
  callExtensionMethod_getElements ((const cPtr_arxmlElementValue *) temp_0.ptr (), inArgument_elementName, var_foundElements_9900, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 444)) ;
  const enumGalgasBool test_1 = GALGAS_bool (kIsNotEqual, var_foundElements_9900.getter_length (SOURCE_FILE ("arxml_types.galgas", 445)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
  if (kBoolTrue == test_1) {
    result_outBool = GALGAS_bool (true) ;
  }else if (kBoolFalse == test_1) {
    result_outBool = GALGAS_bool (false) ;
  }
//---
  return result_outBool ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_arxmlElementValue_hasElement (void) {
  enterExtensionGetter_hasElement (kTypeDescriptor_GALGAS_arxmlElementValue.mSlotID,
                                   extensionGetter_arxmlElementValue_hasElement) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_arxmlElementValue_hasElement (void) {
  gExtensionGetterTable_arxmlElementValue_hasElement.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_arxmlElementValue_hasElement (defineExtensionGetter_arxmlElementValue_hasElement,
                                                         freeExtensionGetter_arxmlElementValue_hasElement) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              Extension getter '@arxmlElementValue getTextFromElement'                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_arxmlElementValue_getTextFromElement> gExtensionGetterTable_arxmlElementValue_getTextFromElement ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_getTextFromElement (const int32_t inClassIndex,
                                              enterExtensionGetter_arxmlElementValue_getTextFromElement inGetter) {
  gExtensionGetterTable_arxmlElementValue_getTextFromElement.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring callExtensionGetter_getTextFromElement (const cPtr_arxmlElementValue * inObject,
                                                       GALGAS_string in_elementName,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) {
  GALGAS_lstring result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_arxmlElementValue) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_arxmlElementValue_getTextFromElement f = NULL ;
    if (classIndex < gExtensionGetterTable_arxmlElementValue_getTextFromElement.count ()) {
      f = gExtensionGetterTable_arxmlElementValue_getTextFromElement (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_arxmlElementValue_getTextFromElement.count ()) {
           f = gExtensionGetterTable_arxmlElementValue_getTextFromElement (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_arxmlElementValue_getTextFromElement.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_elementName, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_lstring extensionGetter_arxmlElementValue_getTextFromElement (const cPtr_arxmlElementValue * inObject,
                                                                            GALGAS_string inArgument_elementName,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring result_outText ; // Returned variable
  const cPtr_arxmlElementValue * object = inObject ;
  macroValidSharedObject (object, cPtr_arxmlElementValue) ;
  GALGAS_arxmlElementValue var_textElement_10167 ;
  const GALGAS_arxmlElementValue temp_0 = object ;
  callExtensionMethod_getElement ((const cPtr_arxmlElementValue *) temp_0.ptr (), inArgument_elementName, var_textElement_10167, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 457)) ;
  result_outText = var_textElement_10167.getter_text (SOURCE_FILE ("arxml_types.galgas", 458)) ;
//---
  return result_outText ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_arxmlElementValue_getTextFromElement (void) {
  enterExtensionGetter_getTextFromElement (kTypeDescriptor_GALGAS_arxmlElementValue.mSlotID,
                                           extensionGetter_arxmlElementValue_getTextFromElement) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_arxmlElementValue_getTextFromElement (void) {
  gExtensionGetterTable_arxmlElementValue_getTextFromElement.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_arxmlElementValue_getTextFromElement (defineExtensionGetter_arxmlElementValue_getTextFromElement,
                                                                 freeExtensionGetter_arxmlElementValue_getTextFromElement) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               Extension method '@arxmlElementValue getAllTextsInSelf'                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionMethodSignature_arxmlElementValue_getAllTextsInSelf> gExtensionMethodTable_arxmlElementValue_getAllTextsInSelf ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_getAllTextsInSelf (const int32_t inClassIndex,
                                             extensionMethodSignature_arxmlElementValue_getAllTextsInSelf inMethod) {
  gExtensionMethodTable_arxmlElementValue_getAllTextsInSelf.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_getAllTextsInSelf (const cPtr_arxmlElementValue * inObject,
                                            GALGAS_string in_separator,
                                            GALGAS_lstring & io_outString,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_arxmlElementValue) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_arxmlElementValue_getAllTextsInSelf f = NULL ;
    if (classIndex < gExtensionMethodTable_arxmlElementValue_getAllTextsInSelf.count ()) {
      f = gExtensionMethodTable_arxmlElementValue_getAllTextsInSelf (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_arxmlElementValue_getAllTextsInSelf.count ()) {
           f = gExtensionMethodTable_arxmlElementValue_getAllTextsInSelf (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_arxmlElementValue_getAllTextsInSelf.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, in_separator, io_outString, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_arxmlElementValue_getAllTextsInSelf (const cPtr_arxmlElementValue * inObject,
                                                                 GALGAS_string inArgument_separator,
                                                                 GALGAS_lstring & ioArgument_outString,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_arxmlElementValue * object = inObject ;
  macroValidSharedObject (object, cPtr_arxmlElementValue) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, object->mProperty_text.getter_string (SOURCE_FILE ("arxml_types.galgas", 465)).objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
  if (kBoolTrue == test_0) {
    const enumGalgasBool test_1 = GALGAS_bool (kIsNotEqual, ioArgument_outString.getter_string (SOURCE_FILE ("arxml_types.galgas", 466)).objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
    if (kBoolTrue == test_1) {
      ioArgument_outString.mProperty_string.plusAssign_operation(inArgument_separator, inCompiler  COMMA_SOURCE_FILE ("arxml_types.galgas", 467)) ;
    }
    const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, ioArgument_outString.getter_location (SOURCE_FILE ("arxml_types.galgas", 469)).objectCompare (GALGAS_location::constructor_nowhere (SOURCE_FILE ("arxml_types.galgas", 469)))).boolEnum () ;
    if (kBoolTrue == test_2) {
      ioArgument_outString.mProperty_location = object->mProperty_text.getter_location (SOURCE_FILE ("arxml_types.galgas", 470)) ;
    }
    ioArgument_outString.mProperty_string.plusAssign_operation(object->mProperty_text.getter_string (SOURCE_FILE ("arxml_types.galgas", 472)), inCompiler  COMMA_SOURCE_FILE ("arxml_types.galgas", 472)) ;
  }
  cEnumerator_arxmlElementValueMap enumerator_10610 (object->mProperty_elements, kENUMERATION_UP) ;
  while (enumerator_10610.hasCurrentObject ()) {
    cEnumerator_arxmlElementValueList enumerator_10634 (enumerator_10610.current_values (HERE), kENUMERATION_UP) ;
    while (enumerator_10634.hasCurrentObject ()) {
      callExtensionMethod_getAllTextsInSelf ((const cPtr_arxmlElementValue *) enumerator_10634.current_value (HERE).ptr (), inArgument_separator, ioArgument_outString, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 477)) ;
      enumerator_10634.gotoNextObject () ;
    }
    enumerator_10610.gotoNextObject () ;
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_arxmlElementValue_getAllTextsInSelf (void) {
  enterExtensionMethod_getAllTextsInSelf (kTypeDescriptor_GALGAS_arxmlElementValue.mSlotID,
                                          extensionMethod_arxmlElementValue_getAllTextsInSelf) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionMethod_arxmlElementValue_getAllTextsInSelf (void) {
  gExtensionMethodTable_arxmlElementValue_getAllTextsInSelf.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_arxmlElementValue_getAllTextsInSelf (defineExtensionMethod_arxmlElementValue_getAllTextsInSelf,
                                                                freeExtensionMethod_arxmlElementValue_getAllTextsInSelf) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                         Extension getter '@arxmlElementValue getAttributeValueFromElement'                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_arxmlElementValue_getAttributeValueFromElement> gExtensionGetterTable_arxmlElementValue_getAttributeValueFromElement ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_getAttributeValueFromElement (const int32_t inClassIndex,
                                                        enterExtensionGetter_arxmlElementValue_getAttributeValueFromElement inGetter) {
  gExtensionGetterTable_arxmlElementValue_getAttributeValueFromElement.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring callExtensionGetter_getAttributeValueFromElement (const cPtr_arxmlElementValue * inObject,
                                                                 GALGAS_string in_elementName,
                                                                 GALGAS_string in_attributeName,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) {
  GALGAS_lstring result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_arxmlElementValue) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_arxmlElementValue_getAttributeValueFromElement f = NULL ;
    if (classIndex < gExtensionGetterTable_arxmlElementValue_getAttributeValueFromElement.count ()) {
      f = gExtensionGetterTable_arxmlElementValue_getAttributeValueFromElement (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_arxmlElementValue_getAttributeValueFromElement.count ()) {
           f = gExtensionGetterTable_arxmlElementValue_getAttributeValueFromElement (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_arxmlElementValue_getAttributeValueFromElement.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_elementName, in_attributeName, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_lstring extensionGetter_arxmlElementValue_getAttributeValueFromElement (const cPtr_arxmlElementValue * inObject,
                                                                                      GALGAS_string inArgument_elementName,
                                                                                      GALGAS_string inArgument_attributeName,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring result_outText ; // Returned variable
  const cPtr_arxmlElementValue * object = inObject ;
  macroValidSharedObject (object, cPtr_arxmlElementValue) ;
  GALGAS_arxmlElementValue var_textElement_10869 ;
  const GALGAS_arxmlElementValue temp_0 = object ;
  callExtensionMethod_getElement ((const cPtr_arxmlElementValue *) temp_0.ptr (), inArgument_elementName, var_textElement_10869, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 488)) ;
  GALGAS_lstring var_attributeNamelString_10947 = GALGAS_lstring::constructor_new (inArgument_attributeName, GALGAS_location::constructor_nowhere (SOURCE_FILE ("arxml_types.galgas", 489))  COMMA_SOURCE_FILE ("arxml_types.galgas", 489)) ;
  var_textElement_10869.getter_attributes (SOURCE_FILE ("arxml_types.galgas", 490)).method_searchKey (var_attributeNamelString_10947, result_outText, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 490)) ;
//---
  return result_outText ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_arxmlElementValue_getAttributeValueFromElement (void) {
  enterExtensionGetter_getAttributeValueFromElement (kTypeDescriptor_GALGAS_arxmlElementValue.mSlotID,
                                                     extensionGetter_arxmlElementValue_getAttributeValueFromElement) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_arxmlElementValue_getAttributeValueFromElement (void) {
  gExtensionGetterTable_arxmlElementValue_getAttributeValueFromElement.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_arxmlElementValue_getAttributeValueFromElement (defineExtensionGetter_arxmlElementValue_getAttributeValueFromElement,
                                                                           freeExtensionGetter_arxmlElementValue_getAttributeValueFromElement) ;

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*


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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlMetaClass::GALGAS_arxmlMetaClass (void) :
AC_GALGAS_class () {
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlMetaClass::GALGAS_arxmlMetaClass (const cPtr_arxmlMetaClass * inSourcePtr) :
AC_GALGAS_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_arxmlMetaClass) ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_arxmlMetaClass::getter_name (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (NULL != mObjectPtr) {
    const cPtr_arxmlMetaClass * p = (const cPtr_arxmlMetaClass *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlMetaClass) ;
    result = p->mProperty_name ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cPtr_arxmlMetaClass::getter_name (UNUSED_LOCATION_ARGS) const {
  return mProperty_name ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_arxmlMetaClass::getter_isAbstract (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (NULL != mObjectPtr) {
    const cPtr_arxmlMetaClass * p = (const cPtr_arxmlMetaClass *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlMetaClass) ;
    result = p->mProperty_isAbstract ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool cPtr_arxmlMetaClass::getter_isAbstract (UNUSED_LOCATION_ARGS) const {
  return mProperty_isAbstract ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlMetaElementList GALGAS_arxmlMetaClass::getter_lElement (UNUSED_LOCATION_ARGS) const {
  GALGAS_arxmlMetaElementList result ;
  if (NULL != mObjectPtr) {
    const cPtr_arxmlMetaClass * p = (const cPtr_arxmlMetaClass *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlMetaClass) ;
    result = p->mProperty_lElement ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlMetaElementList cPtr_arxmlMetaClass::getter_lElement (UNUSED_LOCATION_ARGS) const {
  return mProperty_lElement ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlMetaElementList GALGAS_arxmlMetaClass::getter_lElementLegacy (UNUSED_LOCATION_ARGS) const {
  GALGAS_arxmlMetaElementList result ;
  if (NULL != mObjectPtr) {
    const cPtr_arxmlMetaClass * p = (const cPtr_arxmlMetaClass *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlMetaClass) ;
    result = p->mProperty_lElementLegacy ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlMetaElementList cPtr_arxmlMetaClass::getter_lElementLegacy (UNUSED_LOCATION_ARGS) const {
  return mProperty_lElementLegacy ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlMetaAttributeList GALGAS_arxmlMetaClass::getter_lAttribute (UNUSED_LOCATION_ARGS) const {
  GALGAS_arxmlMetaAttributeList result ;
  if (NULL != mObjectPtr) {
    const cPtr_arxmlMetaClass * p = (const cPtr_arxmlMetaClass *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlMetaClass) ;
    result = p->mProperty_lAttribute ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlMetaAttributeList cPtr_arxmlMetaClass::getter_lAttribute (UNUSED_LOCATION_ARGS) const {
  return mProperty_lAttribute ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlMetaAttributeList GALGAS_arxmlMetaClass::getter_lAttributeLegacy (UNUSED_LOCATION_ARGS) const {
  GALGAS_arxmlMetaAttributeList result ;
  if (NULL != mObjectPtr) {
    const cPtr_arxmlMetaClass * p = (const cPtr_arxmlMetaClass *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlMetaClass) ;
    result = p->mProperty_lAttributeLegacy ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlMetaAttributeList cPtr_arxmlMetaClass::getter_lAttributeLegacy (UNUSED_LOCATION_ARGS) const {
  return mProperty_lAttributeLegacy ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_arxmlMetaClass::getter_desc (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (NULL != mObjectPtr) {
    const cPtr_arxmlMetaClass * p = (const cPtr_arxmlMetaClass *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlMetaClass) ;
    result = p->mProperty_desc ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cPtr_arxmlMetaClass::getter_desc (UNUSED_LOCATION_ARGS) const {
  return mProperty_desc ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                       Pointer class for @arxmlMetaClass class                                       *
//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_arxmlMetaClass::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_arxmlMetaClass (mProperty_name, mProperty_isAbstract, mProperty_lElement, mProperty_lElementLegacy, mProperty_lAttribute, mProperty_lAttributeLegacy, mProperty_desc COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                @arxmlMetaClass type                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_arxmlMetaClass ("arxmlMetaClass",
                                       NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_arxmlMetaClass::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_arxmlMetaClass ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_arxmlMetaClass::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_arxmlMetaClass (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               Extension setter '@arxmlMetaClass legacyAddParameters'                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionSetterSignature_arxmlMetaClass_legacyAddParameters> gExtensionModifierTable_arxmlMetaClass_legacyAddParameters ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_legacyAddParameters (const int32_t inClassIndex,
                                               extensionSetterSignature_arxmlMetaClass_legacyAddParameters inModifier) {
  gExtensionModifierTable_arxmlMetaClass_legacyAddParameters.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_arxmlMetaClass_legacyAddParameters (cPtr_arxmlMetaClass * inObject,
                                                                GALGAS_arxmlMetaClassMap & ioArgument_classMap,
                                                                GALGAS_lstringlist inArgument_successors,
                                                                C_Compiler * inCompiler
                                                                COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_arxmlMetaClass * object = inObject ;
  macroValidSharedObject (object, cPtr_arxmlMetaClass) ;
  cEnumerator_lstringlist enumerator_2572 (inArgument_successors, kENUMERATION_UP) ;
  while (enumerator_2572.hasCurrentObject ()) {
    {
    extensionSetter_updateLegacyParameters (ioArgument_classMap, enumerator_2572.current_mValue (HERE), object->mProperty_lElement, object->mProperty_lAttribute, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 95)) ;
    }
    enumerator_2572.gotoNextObject () ;
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_arxmlMetaClass_legacyAddParameters (void) {
  enterExtensionSetter_legacyAddParameters (kTypeDescriptor_GALGAS_arxmlMetaClass.mSlotID,
                                            extensionSetter_arxmlMetaClass_legacyAddParameters) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionModifier_arxmlMetaClass_legacyAddParameters (void) {
  gExtensionModifierTable_arxmlMetaClass_legacyAddParameters.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_arxmlMetaClass_legacyAddParameters (defineExtensionSetter_arxmlMetaClass_legacyAddParameters,
                                                               freeExtensionModifier_arxmlMetaClass_legacyAddParameters) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Extension setter '@arxmlMetaClass legacyUpdate'                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionSetterSignature_arxmlMetaClass_legacyUpdate> gExtensionModifierTable_arxmlMetaClass_legacyUpdate ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_legacyUpdate (const int32_t inClassIndex,
                                        extensionSetterSignature_arxmlMetaClass_legacyUpdate inModifier) {
  gExtensionModifierTable_arxmlMetaClass_legacyUpdate.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

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
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_arxmlMetaClass_legacyUpdate (void) {
  enterExtensionSetter_legacyUpdate (kTypeDescriptor_GALGAS_arxmlMetaClass.mSlotID,
                                     extensionSetter_arxmlMetaClass_legacyUpdate) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionModifier_arxmlMetaClass_legacyUpdate (void) {
  gExtensionModifierTable_arxmlMetaClass_legacyUpdate.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_arxmlMetaClass_legacyUpdate (defineExtensionSetter_arxmlMetaClass_legacyUpdate,
                                                        freeExtensionModifier_arxmlMetaClass_legacyUpdate) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Extension method '@arxmlMetaClass display'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionMethodSignature_arxmlMetaClass_display> gExtensionMethodTable_arxmlMetaClass_display ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_display (const int32_t inClassIndex,
                                   extensionMethodSignature_arxmlMetaClass_display inMethod) {
  gExtensionMethodTable_arxmlMetaClass_display.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_display (const cPtr_arxmlMetaClass * inObject,
                                  GALGAS_arxmlMetaClassMap in_classMap,
                                  GALGAS_string & io_ioString,
                                  C_Compiler * inCompiler
                                  COMMA_LOCATION_ARGS) {
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_arxmlMetaClass) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_arxmlMetaClass_display f = NULL ;
    if (classIndex < gExtensionMethodTable_arxmlMetaClass_display.count ()) {
      f = gExtensionMethodTable_arxmlMetaClass_display (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_arxmlMetaClass_display.count ()) {
           f = gExtensionMethodTable_arxmlMetaClass_display (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_arxmlMetaClass_display.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, in_classMap, io_ioString, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_arxmlMetaClass_display (const cPtr_arxmlMetaClass * inObject,
                                                    GALGAS_arxmlMetaClassMap inArgument_classMap,
                                                    GALGAS_string & ioArgument_ioString,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_arxmlMetaClass * object = inObject ;
  macroValidSharedObject (object, cPtr_arxmlMetaClass) ;
  GALGAS_string var_svgString_2953 = GALGAS_string::makeEmptyString () ;
  GALGAS_string var_classNameRepr_2986 = object->mProperty_name.mProperty_string ;
  var_svgString_2953.plusAssign_operation(GALGAS_string ("############################################################\n"), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 116)) ;
  var_svgString_2953.plusAssign_operation(GALGAS_string ("# ").add_operation (object->mProperty_name.getter_string (SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 117)), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 117)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 117)), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 117)) ;
  var_svgString_2953.plusAssign_operation(GALGAS_string ("# <").add_operation (object->mProperty_desc.getter_string (SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 118)), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 118)).add_operation (GALGAS_string (">\n"), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 118)), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 118)) ;
  var_svgString_2953.plusAssign_operation(GALGAS_string ("#\n"), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 119)) ;
  var_svgString_2953.plusAssign_operation(GALGAS_string ("list @").add_operation (var_classNameRepr_2986, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 122)).add_operation (GALGAS_string ("list\n"
    "{\n"), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 122)), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 122)) ;
  var_svgString_2953.plusAssign_operation(GALGAS_string ("  @").add_operation (var_classNameRepr_2986, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 123)).add_operation (GALGAS_string (" elem\n"), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 123)), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 123)) ;
  var_svgString_2953.plusAssign_operation(GALGAS_string ("}\n"), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 124)) ;
  const enumGalgasBool test_0 = object->mProperty_isAbstract.boolEnum () ;
  if (kBoolTrue == test_0) {
    var_svgString_2953.plusAssign_operation(GALGAS_string ("abstract "), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 128)) ;
  }
  var_svgString_2953.plusAssign_operation(GALGAS_string ("class @").add_operation (var_classNameRepr_2986, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 132)).add_operation (GALGAS_string ("\n"
    "{\n"), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 132)), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 132)) ;
  cEnumerator_arxmlMetaElementList enumerator_3705 (object->mProperty_lElementLegacy, kENUMERATION_UP) ;
  while (enumerator_3705.hasCurrentObject ()) {
    GALGAS_string var_elemTypeRepr_3737 = enumerator_3705.current_lElement (HERE).getter_type (SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 136)).mProperty_string ;
    GALGAS_string var_elemNameRepr_3791 = enumerator_3705.current_lElement (HERE).getter_name (SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 137)).mProperty_string ;
    const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, enumerator_3705.current_lElement (HERE).getter_type (SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 141)).mProperty_string.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
    if (kBoolTrue == test_1) {
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticWarning (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 142)), GALGAS_string ("Missing element's type : ").add_operation (var_elemNameRepr_3791, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 142)), fixItArray2  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 142)) ;
    }
    GALGAS_arxmlMetaClass var_elemKey_4198 ;
    inArgument_classMap.method_searchKey (enumerator_3705.current_lElement (HERE).getter_type (SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 146)), var_elemKey_4198, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 146)) ;
    var_svgString_2953.plusAssign_operation(GALGAS_string ("  @").add_operation (var_elemTypeRepr_3737, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 168)), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 168)) ;
    GALGAS_bool test_3 = GALGAS_bool (kIsNotEqual, enumerator_3705.current_lElement (HERE).getter_minOccurs (SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 172)).mProperty_string.objectCompare (enumerator_3705.current_lElement (HERE).getter_maxOccurs (SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 172)).mProperty_string)) ;
    if (kBoolTrue != test_3.boolEnum ()) {
      test_3 = GALGAS_bool (kIsNotEqual, enumerator_3705.current_lElement (HERE).getter_minOccurs (SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 173)).mProperty_string.objectCompare (GALGAS_string ("1"))) ;
    }
    const enumGalgasBool test_4 = test_3.boolEnum () ;
    if (kBoolTrue == test_4) {
      var_svgString_2953.plusAssign_operation(GALGAS_string ("list"), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 175)) ;
    }
    var_svgString_2953.plusAssign_operation(GALGAS_string (" elem").add_operation (var_elemNameRepr_3791, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 179)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 179)), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 179)) ;
    enumerator_3705.gotoNextObject () ;
  }
  cEnumerator_arxmlMetaAttributeList enumerator_5338 (object->mProperty_lAttributeLegacy, kENUMERATION_UP) ;
  while (enumerator_5338.hasCurrentObject ()) {
    GALGAS_string var_attrTypeRepr_5370 = enumerator_5338.current_lAttribute (HERE).getter_type (SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 184)).mProperty_string ;
    GALGAS_string var_attrNameRepr_5426 = enumerator_5338.current_lAttribute (HERE).getter_name (SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 185)).mProperty_string ;
    const enumGalgasBool test_5 = GALGAS_bool (kIsNotEqual, enumerator_5338.current_lAttribute (HERE).getter_type (SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 189)).mProperty_string.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
    if (kBoolTrue == test_5) {
    }
    GALGAS_arxmlMetaClass var_attrKey_5802 ;
    inArgument_classMap.method_searchKey (enumerator_5338.current_lAttribute (HERE).getter_type (SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 193)), var_attrKey_5802, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 193)) ;
    var_svgString_2953.plusAssign_operation(GALGAS_string ("  @").add_operation (var_attrTypeRepr_5370, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 218)).add_operation (GALGAS_string (" "), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 218)).add_operation (var_attrNameRepr_5426, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 218)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 218)), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 218)) ;
    GALGAS_bool test_6 = GALGAS_bool (kIsEqual, enumerator_5338.current_lAttribute (HERE).getter_use (SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 223)).mProperty_string.objectCompare (GALGAS_string::makeEmptyString ())) ;
    if (kBoolTrue != test_6.boolEnum ()) {
      test_6 = GALGAS_bool (kIsEqual, enumerator_5338.current_lAttribute (HERE).getter_use (SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 224)).mProperty_string.objectCompare (GALGAS_string ("optional"))) ;
    }
    const enumGalgasBool test_7 = test_6.boolEnum () ;
    if (kBoolTrue == test_7) {
      var_svgString_2953.plusAssign_operation(GALGAS_string ("list"), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 225)) ;
    }
    var_svgString_2953.plusAssign_operation(GALGAS_string (" attr").add_operation (var_attrNameRepr_5426, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 229)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 229)), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 229)) ;
    enumerator_5338.gotoNextObject () ;
  }
  var_svgString_2953.plusAssign_operation(GALGAS_string ("}\n"
    "\n"), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 232)) ;
  ioArgument_ioString = ioArgument_ioString.add_operation (var_svgString_2953, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 233)) ;
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_arxmlMetaClass_display (void) {
  enterExtensionMethod_display (kTypeDescriptor_GALGAS_arxmlMetaClass.mSlotID,
                                extensionMethod_arxmlMetaClass_display) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionMethod_arxmlMetaClass_display (void) {
  gExtensionMethodTable_arxmlMetaClass_display.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_arxmlMetaClass_display (defineExtensionMethod_arxmlMetaClass_display,
                                                   freeExtensionMethod_arxmlMetaClass_display) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Extension setter '@arxmlMetaClass addElement'                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionSetterSignature_arxmlMetaClass_addElement> gExtensionModifierTable_arxmlMetaClass_addElement ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_addElement (const int32_t inClassIndex,
                                      extensionSetterSignature_arxmlMetaClass_addElement inModifier) {
  gExtensionModifierTable_arxmlMetaClass_addElement.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_arxmlMetaClass_addElement (cPtr_arxmlMetaClass * inObject,
                                                       GALGAS_arxmlMetaElement inArgument_mElement,
                                                       C_Compiler * /* inCompiler */
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_arxmlMetaClass * object = inObject ;
  macroValidSharedObject (object, cPtr_arxmlMetaClass) ;
  GALGAS_bool var_exists_7172 = GALGAS_bool (false) ;
  cEnumerator_arxmlMetaElementList enumerator_7227 (object->mProperty_lElement, kENUMERATION_UP) ;
  while (enumerator_7227.hasCurrentObject ()) {
    GALGAS_bool test_0 = GALGAS_bool (kIsEqual, enumerator_7227.current_lElement (HERE).getter_name (SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 240)).mProperty_string.objectCompare (inArgument_mElement.getter_name (SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 240)).mProperty_string)) ;
    if (kBoolTrue == test_0.boolEnum ()) {
      test_0 = GALGAS_bool (kIsEqual, enumerator_7227.current_lElement (HERE).getter_type (SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 241)).mProperty_string.objectCompare (inArgument_mElement.getter_type (SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 241)).mProperty_string)) ;
    }
    const enumGalgasBool test_1 = test_0.boolEnum () ;
    if (kBoolTrue == test_1) {
      var_exists_7172 = GALGAS_bool (true) ;
    }
    enumerator_7227.gotoNextObject () ;
  }
  const enumGalgasBool test_2 = var_exists_7172.operator_not (SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 245)).boolEnum () ;
  if (kBoolTrue == test_2) {
    object->mProperty_lElement.addAssign_operation (inArgument_mElement  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 246)) ;
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_arxmlMetaClass_addElement (void) {
  enterExtensionSetter_addElement (kTypeDescriptor_GALGAS_arxmlMetaClass.mSlotID,
                                   extensionSetter_arxmlMetaClass_addElement) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionModifier_arxmlMetaClass_addElement (void) {
  gExtensionModifierTable_arxmlMetaClass_addElement.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_arxmlMetaClass_addElement (defineExtensionSetter_arxmlMetaClass_addElement,
                                                      freeExtensionModifier_arxmlMetaClass_addElement) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Extension setter '@arxmlMetaClass addAttribute'                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionSetterSignature_arxmlMetaClass_addAttribute> gExtensionModifierTable_arxmlMetaClass_addAttribute ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_addAttribute (const int32_t inClassIndex,
                                        extensionSetterSignature_arxmlMetaClass_addAttribute inModifier) {
  gExtensionModifierTable_arxmlMetaClass_addAttribute.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_arxmlMetaClass_addAttribute (cPtr_arxmlMetaClass * inObject,
                                                         GALGAS_arxmlMetaAttribute inArgument_mAttribute,
                                                         C_Compiler * /* inCompiler */
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_arxmlMetaClass * object = inObject ;
  macroValidSharedObject (object, cPtr_arxmlMetaClass) ;
  GALGAS_bool var_exists_7523 = GALGAS_bool (false) ;
  cEnumerator_arxmlMetaAttributeList enumerator_7584 (object->mProperty_lAttribute, kENUMERATION_UP) ;
  while (enumerator_7584.hasCurrentObject ()) {
    GALGAS_bool test_0 = GALGAS_bool (kIsEqual, enumerator_7584.current_lAttribute (HERE).getter_name (SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 254)).mProperty_string.objectCompare (inArgument_mAttribute.getter_name (SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 254)).mProperty_string)) ;
    if (kBoolTrue == test_0.boolEnum ()) {
      test_0 = GALGAS_bool (kIsEqual, enumerator_7584.current_lAttribute (HERE).getter_type (SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 255)).mProperty_string.objectCompare (inArgument_mAttribute.getter_type (SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 255)).mProperty_string)) ;
    }
    const enumGalgasBool test_1 = test_0.boolEnum () ;
    if (kBoolTrue == test_1) {
      var_exists_7523 = GALGAS_bool (true) ;
    }
    enumerator_7584.gotoNextObject () ;
  }
  const enumGalgasBool test_2 = var_exists_7523.operator_not (SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 259)).boolEnum () ;
  if (kBoolTrue == test_2) {
    object->mProperty_lAttribute.addAssign_operation (inArgument_mAttribute  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 260)) ;
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_arxmlMetaClass_addAttribute (void) {
  enterExtensionSetter_addAttribute (kTypeDescriptor_GALGAS_arxmlMetaClass.mSlotID,
                                     extensionSetter_arxmlMetaClass_addAttribute) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionModifier_arxmlMetaClass_addAttribute (void) {
  gExtensionModifierTable_arxmlMetaClass_addAttribute.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_arxmlMetaClass_addAttribute (defineExtensionSetter_arxmlMetaClass_addAttribute,
                                                        freeExtensionModifier_arxmlMetaClass_addAttribute) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                  Extension setter '@arxmlMetaClass setDescription'                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionSetterSignature_arxmlMetaClass_setDescription> gExtensionModifierTable_arxmlMetaClass_setDescription ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_setDescription (const int32_t inClassIndex,
                                          extensionSetterSignature_arxmlMetaClass_setDescription inModifier) {
  gExtensionModifierTable_arxmlMetaClass_setDescription.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_arxmlMetaClass_setDescription (cPtr_arxmlMetaClass * inObject,
                                                           GALGAS_lstring inArgument_iDesc,
                                                           C_Compiler * /* inCompiler */
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_arxmlMetaClass * object = inObject ;
  macroValidSharedObject (object, cPtr_arxmlMetaClass) ;
  object->mProperty_desc = inArgument_iDesc ;
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_arxmlMetaClass_setDescription (void) {
  enterExtensionSetter_setDescription (kTypeDescriptor_GALGAS_arxmlMetaClass.mSlotID,
                                       extensionSetter_arxmlMetaClass_setDescription) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionModifier_arxmlMetaClass_setDescription (void) {
  gExtensionModifierTable_arxmlMetaClass_setDescription.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_arxmlMetaClass_setDescription (defineExtensionSetter_arxmlMetaClass_setDescription,
                                                          freeExtensionModifier_arxmlMetaClass_setDescription) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Extension getter '@arxmlMetaClass hasElement'                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_arxmlMetaClass_hasElement> gExtensionGetterTable_arxmlMetaClass_hasElement ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_hasElement (const int32_t inClassIndex,
                                      enterExtensionGetter_arxmlMetaClass_hasElement inGetter) {
  gExtensionGetterTable_arxmlMetaClass_hasElement.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool callExtensionGetter_hasElement (const cPtr_arxmlMetaClass * inObject,
                                            GALGAS_string in_eleName,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
  GALGAS_bool result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_arxmlMetaClass) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_arxmlMetaClass_hasElement f = NULL ;
    if (classIndex < gExtensionGetterTable_arxmlMetaClass_hasElement.count ()) {
      f = gExtensionGetterTable_arxmlMetaClass_hasElement (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_arxmlMetaClass_hasElement.count ()) {
           f = gExtensionGetterTable_arxmlMetaClass_hasElement (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_arxmlMetaClass_hasElement.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_eleName, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_bool extensionGetter_arxmlMetaClass_hasElement (const cPtr_arxmlMetaClass * inObject,
                                                              GALGAS_string inArgument_eleName,
                                                              C_Compiler * /* inCompiler */
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_oFound ; // Returned variable
  const cPtr_arxmlMetaClass * object = inObject ;
  macroValidSharedObject (object, cPtr_arxmlMetaClass) ;
  GALGAS_bool var_found_7967 = GALGAS_bool (false) ;
  cEnumerator_arxmlMetaElementList enumerator_8035 (object->mProperty_lElementLegacy, kENUMERATION_UP) ;
  bool bool_0 = var_found_7967.operator_not (SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 275)).isValidAndTrue () ;
  if (enumerator_8035.hasCurrentObject () && bool_0) {
    while (enumerator_8035.hasCurrentObject () && bool_0) {
      const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, inArgument_eleName.objectCompare (enumerator_8035.current_lElement (HERE).getter_name (SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 276)).mProperty_string)).boolEnum () ;
      if (kBoolTrue == test_1) {
        var_found_7967 = GALGAS_bool (true) ;
      }
      enumerator_8035.gotoNextObject () ;
      if (enumerator_8035.hasCurrentObject ()) {
        bool_0 = var_found_7967.operator_not (SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 275)).isValidAndTrue () ;
      }
    }
  }
  result_oFound = var_found_7967 ;
//---
  return result_oFound ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_arxmlMetaClass_hasElement (void) {
  enterExtensionGetter_hasElement (kTypeDescriptor_GALGAS_arxmlMetaClass.mSlotID,
                                   extensionGetter_arxmlMetaClass_hasElement) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_arxmlMetaClass_hasElement (void) {
  gExtensionGetterTable_arxmlMetaClass_hasElement.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_arxmlMetaClass_hasElement (defineExtensionGetter_arxmlMetaClass_hasElement,
                                                      freeExtensionGetter_arxmlMetaClass_hasElement) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Extension getter '@arxmlMetaClass hasAttribute'                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_arxmlMetaClass_hasAttribute> gExtensionGetterTable_arxmlMetaClass_hasAttribute ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_hasAttribute (const int32_t inClassIndex,
                                        enterExtensionGetter_arxmlMetaClass_hasAttribute inGetter) {
  gExtensionGetterTable_arxmlMetaClass_hasAttribute.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool callExtensionGetter_hasAttribute (const cPtr_arxmlMetaClass * inObject,
                                              GALGAS_string in_attrName,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
  GALGAS_bool result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_arxmlMetaClass) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_arxmlMetaClass_hasAttribute f = NULL ;
    if (classIndex < gExtensionGetterTable_arxmlMetaClass_hasAttribute.count ()) {
      f = gExtensionGetterTable_arxmlMetaClass_hasAttribute (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_arxmlMetaClass_hasAttribute.count ()) {
           f = gExtensionGetterTable_arxmlMetaClass_hasAttribute (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_arxmlMetaClass_hasAttribute.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_attrName, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_bool extensionGetter_arxmlMetaClass_hasAttribute (const cPtr_arxmlMetaClass * inObject,
                                                                GALGAS_string inArgument_attrName,
                                                                C_Compiler * /* inCompiler */
                                                                COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_oFound ; // Returned variable
  const cPtr_arxmlMetaClass * object = inObject ;
  macroValidSharedObject (object, cPtr_arxmlMetaClass) ;
  GALGAS_bool var_found_8251 = GALGAS_bool (false) ;
  cEnumerator_arxmlMetaAttributeList enumerator_8325 (object->mProperty_lAttributeLegacy, kENUMERATION_UP) ;
  bool bool_0 = var_found_8251.operator_not (SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 290)).isValidAndTrue () ;
  if (enumerator_8325.hasCurrentObject () && bool_0) {
    while (enumerator_8325.hasCurrentObject () && bool_0) {
      const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, inArgument_attrName.objectCompare (enumerator_8325.current_lAttribute (HERE).getter_name (SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 291)).mProperty_string)).boolEnum () ;
      if (kBoolTrue == test_1) {
        var_found_8251 = GALGAS_bool (true) ;
      }
      enumerator_8325.gotoNextObject () ;
      if (enumerator_8325.hasCurrentObject ()) {
        bool_0 = var_found_8251.operator_not (SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 290)).isValidAndTrue () ;
      }
    }
  }
  result_oFound = var_found_8251 ;
//---
  return result_oFound ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_arxmlMetaClass_hasAttribute (void) {
  enterExtensionGetter_hasAttribute (kTypeDescriptor_GALGAS_arxmlMetaClass.mSlotID,
                                     extensionGetter_arxmlMetaClass_hasAttribute) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_arxmlMetaClass_hasAttribute (void) {
  gExtensionGetterTable_arxmlMetaClass_hasAttribute.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_arxmlMetaClass_hasAttribute (defineExtensionGetter_arxmlMetaClass_hasAttribute,
                                                        freeExtensionGetter_arxmlMetaClass_hasAttribute) ;

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*


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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlMetaElement::GALGAS_arxmlMetaElement (void) :
AC_GALGAS_class () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlMetaElement GALGAS_arxmlMetaElement::constructor_default (LOCATION_ARGS) {
  return GALGAS_arxmlMetaElement::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                                   GALGAS_lstring::constructor_default (HERE),
                                                   GALGAS_lstring::constructor_default (HERE),
                                                   GALGAS_lstring::constructor_default (HERE),
                                                   GALGAS_lstring::constructor_default (HERE)
                                                   COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlMetaElement::GALGAS_arxmlMetaElement (const cPtr_arxmlMetaElement * inSourcePtr) :
AC_GALGAS_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_arxmlMetaElement) ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_arxmlMetaElement::getter_name (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (NULL != mObjectPtr) {
    const cPtr_arxmlMetaElement * p = (const cPtr_arxmlMetaElement *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlMetaElement) ;
    result = p->mProperty_name ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cPtr_arxmlMetaElement::getter_name (UNUSED_LOCATION_ARGS) const {
  return mProperty_name ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_arxmlMetaElement::getter_type (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (NULL != mObjectPtr) {
    const cPtr_arxmlMetaElement * p = (const cPtr_arxmlMetaElement *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlMetaElement) ;
    result = p->mProperty_type ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cPtr_arxmlMetaElement::getter_type (UNUSED_LOCATION_ARGS) const {
  return mProperty_type ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_arxmlMetaElement::getter_minOccurs (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (NULL != mObjectPtr) {
    const cPtr_arxmlMetaElement * p = (const cPtr_arxmlMetaElement *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlMetaElement) ;
    result = p->mProperty_minOccurs ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cPtr_arxmlMetaElement::getter_minOccurs (UNUSED_LOCATION_ARGS) const {
  return mProperty_minOccurs ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_arxmlMetaElement::getter_maxOccurs (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (NULL != mObjectPtr) {
    const cPtr_arxmlMetaElement * p = (const cPtr_arxmlMetaElement *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlMetaElement) ;
    result = p->mProperty_maxOccurs ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cPtr_arxmlMetaElement::getter_maxOccurs (UNUSED_LOCATION_ARGS) const {
  return mProperty_maxOccurs ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_arxmlMetaElement::getter_prefix (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (NULL != mObjectPtr) {
    const cPtr_arxmlMetaElement * p = (const cPtr_arxmlMetaElement *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlMetaElement) ;
    result = p->mProperty_prefix ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cPtr_arxmlMetaElement::getter_prefix (UNUSED_LOCATION_ARGS) const {
  return mProperty_prefix ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                      Pointer class for @arxmlMetaElement class                                      *
//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_arxmlMetaElement::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_arxmlMetaElement (mProperty_name, mProperty_type, mProperty_minOccurs, mProperty_maxOccurs, mProperty_prefix COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               @arxmlMetaElement type                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_arxmlMetaElement ("arxmlMetaElement",
                                         NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_arxmlMetaElement::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_arxmlMetaElement ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_arxmlMetaElement::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_arxmlMetaElement (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*


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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlMetaAttribute::GALGAS_arxmlMetaAttribute (void) :
AC_GALGAS_class () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlMetaAttribute GALGAS_arxmlMetaAttribute::constructor_default (LOCATION_ARGS) {
  return GALGAS_arxmlMetaAttribute::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                                     GALGAS_lstring::constructor_default (HERE),
                                                     GALGAS_lstring::constructor_default (HERE),
                                                     GALGAS_lstring::constructor_default (HERE)
                                                     COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlMetaAttribute::GALGAS_arxmlMetaAttribute (const cPtr_arxmlMetaAttribute * inSourcePtr) :
AC_GALGAS_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_arxmlMetaAttribute) ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_arxmlMetaAttribute::getter_name (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (NULL != mObjectPtr) {
    const cPtr_arxmlMetaAttribute * p = (const cPtr_arxmlMetaAttribute *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlMetaAttribute) ;
    result = p->mProperty_name ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cPtr_arxmlMetaAttribute::getter_name (UNUSED_LOCATION_ARGS) const {
  return mProperty_name ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_arxmlMetaAttribute::getter_type (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (NULL != mObjectPtr) {
    const cPtr_arxmlMetaAttribute * p = (const cPtr_arxmlMetaAttribute *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlMetaAttribute) ;
    result = p->mProperty_type ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cPtr_arxmlMetaAttribute::getter_type (UNUSED_LOCATION_ARGS) const {
  return mProperty_type ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_arxmlMetaAttribute::getter_prefix (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (NULL != mObjectPtr) {
    const cPtr_arxmlMetaAttribute * p = (const cPtr_arxmlMetaAttribute *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlMetaAttribute) ;
    result = p->mProperty_prefix ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cPtr_arxmlMetaAttribute::getter_prefix (UNUSED_LOCATION_ARGS) const {
  return mProperty_prefix ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_arxmlMetaAttribute::getter_use (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (NULL != mObjectPtr) {
    const cPtr_arxmlMetaAttribute * p = (const cPtr_arxmlMetaAttribute *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlMetaAttribute) ;
    result = p->mProperty_use ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cPtr_arxmlMetaAttribute::getter_use (UNUSED_LOCATION_ARGS) const {
  return mProperty_use ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                     Pointer class for @arxmlMetaAttribute class                                     *
//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_arxmlMetaAttribute::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_arxmlMetaAttribute (mProperty_name, mProperty_type, mProperty_prefix, mProperty_use COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @arxmlMetaAttribute type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_arxmlMetaAttribute ("arxmlMetaAttribute",
                                           NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_arxmlMetaAttribute::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_arxmlMetaAttribute ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_arxmlMetaAttribute::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_arxmlMetaAttribute (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*


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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlMetaSimpletype::GALGAS_arxmlMetaSimpletype (void) :
AC_GALGAS_class () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlMetaSimpletype::GALGAS_arxmlMetaSimpletype (const cPtr_arxmlMetaSimpletype * inSourcePtr) :
AC_GALGAS_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_arxmlMetaSimpletype) ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_arxmlMetaSimpletype::getter_name (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (NULL != mObjectPtr) {
    const cPtr_arxmlMetaSimpletype * p = (const cPtr_arxmlMetaSimpletype *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlMetaSimpletype) ;
    result = p->mProperty_name ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cPtr_arxmlMetaSimpletype::getter_name (UNUSED_LOCATION_ARGS) const {
  return mProperty_name ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_restrictionType GALGAS_arxmlMetaSimpletype::getter_type (UNUSED_LOCATION_ARGS) const {
  GALGAS_restrictionType result ;
  if (NULL != mObjectPtr) {
    const cPtr_arxmlMetaSimpletype * p = (const cPtr_arxmlMetaSimpletype *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlMetaSimpletype) ;
    result = p->mProperty_type ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_restrictionType cPtr_arxmlMetaSimpletype::getter_type (UNUSED_LOCATION_ARGS) const {
  return mProperty_type ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_restrictionBaseType GALGAS_arxmlMetaSimpletype::getter_base (UNUSED_LOCATION_ARGS) const {
  GALGAS_restrictionBaseType result ;
  if (NULL != mObjectPtr) {
    const cPtr_arxmlMetaSimpletype * p = (const cPtr_arxmlMetaSimpletype *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlMetaSimpletype) ;
    result = p->mProperty_base ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_restrictionBaseType cPtr_arxmlMetaSimpletype::getter_base (UNUSED_LOCATION_ARGS) const {
  return mProperty_base ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringlist GALGAS_arxmlMetaSimpletype::getter_values (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstringlist result ;
  if (NULL != mObjectPtr) {
    const cPtr_arxmlMetaSimpletype * p = (const cPtr_arxmlMetaSimpletype *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_arxmlMetaSimpletype) ;
    result = p->mProperty_values ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringlist cPtr_arxmlMetaSimpletype::getter_values (UNUSED_LOCATION_ARGS) const {
  return mProperty_values ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                    Pointer class for @arxmlMetaSimpletype class                                     *
//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_arxmlMetaSimpletype::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_arxmlMetaSimpletype (mProperty_name, mProperty_type, mProperty_base, mProperty_values COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @arxmlMetaSimpletype type                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_arxmlMetaSimpletype ("arxmlMetaSimpletype",
                                            NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_arxmlMetaSimpletype::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_arxmlMetaSimpletype ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_arxmlMetaSimpletype::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_arxmlMetaSimpletype (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Extension method '@arxmlMetaSimpletype display'                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionMethodSignature_arxmlMetaSimpletype_display> gExtensionMethodTable_arxmlMetaSimpletype_display ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_display (const int32_t inClassIndex,
                                   extensionMethodSignature_arxmlMetaSimpletype_display inMethod) {
  gExtensionMethodTable_arxmlMetaSimpletype_display.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_display (const cPtr_arxmlMetaSimpletype * inObject,
                                  GALGAS_arxmlMetaClassMap in_classMap,
                                  GALGAS_string & io_ioString,
                                  C_Compiler * inCompiler
                                  COMMA_LOCATION_ARGS) {
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_arxmlMetaSimpletype) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_arxmlMetaSimpletype_display f = NULL ;
    if (classIndex < gExtensionMethodTable_arxmlMetaSimpletype_display.count ()) {
      f = gExtensionMethodTable_arxmlMetaSimpletype_display (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_arxmlMetaSimpletype_display.count ()) {
           f = gExtensionMethodTable_arxmlMetaSimpletype_display (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_arxmlMetaSimpletype_display.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, in_classMap, io_ioString, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_arxmlMetaSimpletype_display (const cPtr_arxmlMetaSimpletype * inObject,
                                                         GALGAS_arxmlMetaClassMap /* inArgument_classMap */,
                                                         GALGAS_string & ioArgument_ioString,
                                                         C_Compiler * inCompiler
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_arxmlMetaSimpletype * object = inObject ;
  macroValidSharedObject (object, cPtr_arxmlMetaSimpletype) ;
  GALGAS_string var_svgString_9977 = GALGAS_string::makeEmptyString () ;
  GALGAS_string var_typeNameRepr_10009 = object->mProperty_name.mProperty_string ;
  var_svgString_9977.plusAssign_operation(GALGAS_string ("############################################################\n"), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 373)) ;
  var_svgString_9977.plusAssign_operation(GALGAS_string ("# ").add_operation (object->mProperty_name.getter_string (SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 374)), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 374)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 374)), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 374)) ;
  switch (object->mProperty_type.enumValue ()) {
  case GALGAS_restrictionType::kNotBuilt:
    break ;
  case GALGAS_restrictionType::kEnum_restrictionSimple:
    {
    }
    break ;
  case GALGAS_restrictionType::kEnum_restrictionEnum:
    {
      var_svgString_9977.plusAssign_operation(GALGAS_string ("list @").add_operation (var_typeNameRepr_10009, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 381)).add_operation (GALGAS_string ("list\n"
        "{\n"), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 381)), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 381)) ;
      var_svgString_9977.plusAssign_operation(GALGAS_string ("  @").add_operation (var_typeNameRepr_10009, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 382)).add_operation (GALGAS_string (" elem\n"), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 382)), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 382)) ;
      var_svgString_9977.plusAssign_operation(GALGAS_string ("}\n"), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 383)) ;
      var_svgString_9977.plusAssign_operation(GALGAS_string ("enum @").add_operation (var_typeNameRepr_10009, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 385)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 385)), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 385)) ;
      var_svgString_9977.plusAssign_operation(GALGAS_string ("{\n"), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 386)) ;
      cEnumerator_lstringlist enumerator_10673 (object->mProperty_values, kENUMERATION_UP) ;
      while (enumerator_10673.hasCurrentObject ()) {
        GALGAS_string var_valueRepr_10706 = enumerator_10673.current_mValue (HERE).mProperty_string ;
        var_svgString_9977.plusAssign_operation(GALGAS_string ("  case case").add_operation (var_valueRepr_10706, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 390)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 390)), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 390)) ;
        enumerator_10673.gotoNextObject () ;
      }
      var_svgString_9977.plusAssign_operation(GALGAS_string ("}\n"), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 392)) ;
    }
    break ;
  case GALGAS_restrictionType::kEnum_restrictionOther:
    {
      TC_Array <C_FixItDescription> fixItArray0 ;
      inCompiler->emitSemanticError (object->mProperty_name.getter_location (SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 394)), GALGAS_string ("TODO : Fall into restrictionOther statement"), fixItArray0  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 394)) ;
    }
    break ;
  case GALGAS_restrictionType::kEnum_restrictionUnused:
    {
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (object->mProperty_name.getter_location (SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 396)), GALGAS_string ("TODO : Fall into restrictionUnused statement."), fixItArray1  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 396)) ;
    }
    break ;
  }
  ioArgument_ioString = ioArgument_ioString.add_operation (var_svgString_9977, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 399)) ;
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_arxmlMetaSimpletype_display (void) {
  enterExtensionMethod_display (kTypeDescriptor_GALGAS_arxmlMetaSimpletype.mSlotID,
                                extensionMethod_arxmlMetaSimpletype_display) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionMethod_arxmlMetaSimpletype_display (void) {
  gExtensionMethodTable_arxmlMetaSimpletype_display.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_arxmlMetaSimpletype_display (defineExtensionMethod_arxmlMetaSimpletype_display,
                                                        freeExtensionMethod_arxmlMetaSimpletype_display) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Extension setter '@arxmlMetaSimpletype setType'                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionSetterSignature_arxmlMetaSimpletype_setType> gExtensionModifierTable_arxmlMetaSimpletype_setType ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_setType (const int32_t inClassIndex,
                                   extensionSetterSignature_arxmlMetaSimpletype_setType inModifier) {
  gExtensionModifierTable_arxmlMetaSimpletype_setType.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_setType (cPtr_arxmlMetaSimpletype * inObject,
                                  GALGAS_restrictionType in_iType,
                                  C_Compiler * inCompiler
                                  COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_arxmlMetaSimpletype) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_arxmlMetaSimpletype_setType f = NULL ;
    if (classIndex < gExtensionModifierTable_arxmlMetaSimpletype_setType.count ()) {
      f = gExtensionModifierTable_arxmlMetaSimpletype_setType (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_arxmlMetaSimpletype_setType.count ()) {
           f = gExtensionModifierTable_arxmlMetaSimpletype_setType (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_arxmlMetaSimpletype_setType.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, in_iType, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_arxmlMetaSimpletype_setType (cPtr_arxmlMetaSimpletype * inObject,
                                                         GALGAS_restrictionType inArgument_iType,
                                                         C_Compiler * /* inCompiler */
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_arxmlMetaSimpletype * object = inObject ;
  macroValidSharedObject (object, cPtr_arxmlMetaSimpletype) ;
  object->mProperty_type = inArgument_iType ;
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_arxmlMetaSimpletype_setType (void) {
  enterExtensionSetter_setType (kTypeDescriptor_GALGAS_arxmlMetaSimpletype.mSlotID,
                                extensionSetter_arxmlMetaSimpletype_setType) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionModifier_arxmlMetaSimpletype_setType (void) {
  gExtensionModifierTable_arxmlMetaSimpletype_setType.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_arxmlMetaSimpletype_setType (defineExtensionSetter_arxmlMetaSimpletype_setType,
                                                        freeExtensionModifier_arxmlMetaSimpletype_setType) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Extension setter '@arxmlMetaSimpletype setBase'                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionSetterSignature_arxmlMetaSimpletype_setBase> gExtensionModifierTable_arxmlMetaSimpletype_setBase ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_setBase (const int32_t inClassIndex,
                                   extensionSetterSignature_arxmlMetaSimpletype_setBase inModifier) {
  gExtensionModifierTable_arxmlMetaSimpletype_setBase.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_setBase (cPtr_arxmlMetaSimpletype * inObject,
                                  GALGAS_restrictionBaseType in_iBase,
                                  C_Compiler * inCompiler
                                  COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_arxmlMetaSimpletype) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_arxmlMetaSimpletype_setBase f = NULL ;
    if (classIndex < gExtensionModifierTable_arxmlMetaSimpletype_setBase.count ()) {
      f = gExtensionModifierTable_arxmlMetaSimpletype_setBase (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_arxmlMetaSimpletype_setBase.count ()) {
           f = gExtensionModifierTable_arxmlMetaSimpletype_setBase (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_arxmlMetaSimpletype_setBase.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, in_iBase, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_arxmlMetaSimpletype_setBase (cPtr_arxmlMetaSimpletype * inObject,
                                                         GALGAS_restrictionBaseType inArgument_iBase,
                                                         C_Compiler * /* inCompiler */
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_arxmlMetaSimpletype * object = inObject ;
  macroValidSharedObject (object, cPtr_arxmlMetaSimpletype) ;
  object->mProperty_base = inArgument_iBase ;
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_arxmlMetaSimpletype_setBase (void) {
  enterExtensionSetter_setBase (kTypeDescriptor_GALGAS_arxmlMetaSimpletype.mSlotID,
                                extensionSetter_arxmlMetaSimpletype_setBase) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionModifier_arxmlMetaSimpletype_setBase (void) {
  gExtensionModifierTable_arxmlMetaSimpletype_setBase.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_arxmlMetaSimpletype_setBase (defineExtensionSetter_arxmlMetaSimpletype_setBase,
                                                        freeExtensionModifier_arxmlMetaSimpletype_setBase) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                  Extension setter '@arxmlMetaSimpletype addValue'                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionSetterSignature_arxmlMetaSimpletype_addValue> gExtensionModifierTable_arxmlMetaSimpletype_addValue ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_addValue (const int32_t inClassIndex,
                                    extensionSetterSignature_arxmlMetaSimpletype_addValue inModifier) {
  gExtensionModifierTable_arxmlMetaSimpletype_addValue.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_arxmlMetaSimpletype_addValue (cPtr_arxmlMetaSimpletype * inObject,
                                                          GALGAS_lstring inArgument_value,
                                                          C_Compiler * /* inCompiler */
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_arxmlMetaSimpletype * object = inObject ;
  macroValidSharedObject (object, cPtr_arxmlMetaSimpletype) ;
  object->mProperty_values.addAssign_operation (inArgument_value  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 414)) ;
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_arxmlMetaSimpletype_addValue (void) {
  enterExtensionSetter_addValue (kTypeDescriptor_GALGAS_arxmlMetaSimpletype.mSlotID,
                                 extensionSetter_arxmlMetaSimpletype_addValue) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionModifier_arxmlMetaSimpletype_addValue (void) {
  gExtensionModifierTable_arxmlMetaSimpletype_addValue.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

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
  const enumGalgasBool test_0 = inArgument_create_5F_class_5F_file.boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_string var_classString_1305 = GALGAS_string::makeEmptyString () ;
    extensionMethod_display (var_classMap_964, var_classString_1305, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 49)) ;
    var_classString_1305.method_writeToFile (GALGAS_string ("arxml_ecuc_classes.galgas"), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 50)) ;
    GALGAS_string var_graphString_1448 = var_classGraph_1003.getter_graphviz (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 53)) ;
    var_graphString_1448.method_writeToFile (GALGAS_string ("arxml_ecuc_graph.dot"), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 54)) ;
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
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__3F_xml) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 63)) ;
  nt_xsd_5F_ignore_5F_attributes_ (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3F__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 65)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xml_5F_header_i1_parse (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__3F_xml) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 63)) ;
  nt_xsd_5F_ignore_5F_attributes_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3F__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 65)) ;
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
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 81)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      switch (select_arxmlmetaparser_5F_syntax_1 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 83)) ;
        switch (select_arxmlmetaparser_5F_syntax_2 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_appinfo) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 84)) ;
          nt_xsd_5F_appinfo_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_documentation) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 86)) ;
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
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 91)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 92)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 93)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 94)) ;
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
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 81)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      switch (select_arxmlmetaparser_5F_syntax_1 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 83)) ;
        switch (select_arxmlmetaparser_5F_syntax_2 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_appinfo) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 84)) ;
          nt_xsd_5F_appinfo_parse (inCompiler) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_documentation) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 86)) ;
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
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 91)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 92)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 93)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 94)) ;
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
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 107)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 109)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_appinfo) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 110)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 111)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 112)) ;
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
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 107)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 109)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_appinfo) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 110)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 111)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 112)) ;
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
  GALGAS_lstring var_attributeType_2969 ;
  {
  routine_lstringhere (var_attributeType_2969, GALGAS_string::makeEmptyString (), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 123)) ;
  }
  GALGAS_lstring var_attributeName_3012 ;
  {
  routine_lstringhere (var_attributeName_3012, GALGAS_string::makeEmptyString (), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 124)) ;
  }
  GALGAS_lstring var_attributeRef_3054 ;
  {
  routine_lstringhere (var_attributeRef_3054, GALGAS_string::makeEmptyString (), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 125)) ;
  }
  GALGAS_lstring var_attributePrefix_3100 ;
  {
  routine_lstringhere (var_attributePrefix_3100, GALGAS_string::makeEmptyString (), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 126)) ;
  }
  GALGAS_lstring var_attributeUse_3143 ;
  {
  routine_lstringhere (var_attributeUse_3143, GALGAS_string::makeEmptyString (), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 127)) ;
  }
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_arxmlmetaparser_5F_syntax_4 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_ref) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 130)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 132)) ;
      var_attributeRef_3054 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 133)) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_type) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 134)) ;
      GALGAS_lstring var_fullType_3315 ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 136)) ;
      var_fullType_3315 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 137)) ;
      const enumGalgasBool test_1 = var_fullType_3315.mProperty_string.getter_containsCharacter (GALGAS_char (TO_UNICODE (58)) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 139)).boolEnum () ;
      if (kBoolTrue == test_1) {
        GALGAS_stringlist var_parsed_3478 = var_fullType_3315.mProperty_string.getter_componentsSeparatedByString (GALGAS_string (":") COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 140)) ;
        GALGAS_string var_parsedString_3558 ;
        var_parsed_3478.method_first (var_parsedString_3558, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 142)) ;
        var_attributePrefix_3100.mProperty_string = var_parsedString_3558 ;
        var_attributePrefix_3100.mProperty_location = var_fullType_3315.mProperty_location ;
        var_parsed_3478.method_last (var_parsedString_3558, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 145)) ;
        var_attributeType_2969.mProperty_string = var_parsedString_3558 ;
        var_attributeType_2969.mProperty_location = var_fullType_3315.mProperty_location ;
      }else if (kBoolFalse == test_1) {
        var_attributeType_2969 = var_fullType_3315 ;
      }
    } break ;
    case 4: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_name) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 151)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 152)) ;
      var_attributeName_3012 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 153)) ;
      var_attributeName_3012.mProperty_string = var_attributeName_3012.mProperty_string.getter_stringByReplacingStringByString (GALGAS_string ("<"), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 154)) ;
      var_attributeName_3012.mProperty_string = var_attributeName_3012.mProperty_string.getter_stringByReplacingStringByString (GALGAS_string (">"), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 155)) ;
    } break ;
    case 5: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_use) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 156)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 157)) ;
      var_attributeUse_3143 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 158)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  const enumGalgasBool test_2 = GALGAS_bool (kIsNotEqual, var_attributeName_3012.mProperty_string.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
  if (kBoolTrue == test_2) {
    GALGAS_arxmlMetaAttribute var_newAttribute_4234 = GALGAS_arxmlMetaAttribute::constructor_new (var_attributeName_3012, var_attributeType_2969, var_attributePrefix_3100, var_attributeUse_3143  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 162)) ;
    {
    extensionSetter_addClassAttribute (ioArgument_classMap, inArgument_parentClass, var_newAttribute_4234, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 168)) ;
    }
  }
  switch (select_arxmlmetaparser_5F_syntax_5 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 171)) ;
    bool repeatFlag_3 = true ;
    while (repeatFlag_3) {
      switch (select_arxmlmetaparser_5F_syntax_6 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 173)) ;
        switch (select_arxmlmetaparser_5F_syntax_7 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 174)) ;
          nt_xsd_5F_annotation_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_simpleType) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 176)) ;
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
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 181)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attribute) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 182)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 183)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 184)) ;
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
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_ref) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 130)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 132)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 133)) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_type) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 134)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 136)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 137)) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_name) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 151)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 152)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 153)) ;
    } break ;
    case 5: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_use) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 156)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 157)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 158)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  switch (select_arxmlmetaparser_5F_syntax_5 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 171)) ;
    bool repeatFlag_1 = true ;
    while (repeatFlag_1) {
      switch (select_arxmlmetaparser_5F_syntax_6 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 173)) ;
        switch (select_arxmlmetaparser_5F_syntax_7 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 174)) ;
          nt_xsd_5F_annotation_parse (inCompiler) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_simpleType) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 176)) ;
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
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 181)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attribute) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 182)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 183)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 184)) ;
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
  GALGAS_lstring var_className_5243 ;
  GALGAS_lstring var_nextParentClass_5270 ;
  switch (select_arxmlmetaparser_5F_syntax_8 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_name) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 199)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 201)) ;
    var_className_5243 = inCompiler->synthetizedAttribute_tokenString () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 202)) ;
    var_className_5243.mProperty_string = var_className_5243.mProperty_string.getter_stringByReplacingStringByString (GALGAS_string ("<"), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 203)) ;
    var_className_5243.mProperty_string = var_className_5243.mProperty_string.getter_stringByReplacingStringByString (GALGAS_string (">"), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 204)) ;
    GALGAS_lstring var_desc_5610 ;
    {
    routine_lstringhere (var_desc_5610, GALGAS_string::makeEmptyString (), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 205)) ;
    }
    const enumGalgasBool test_0 = ioArgument_classMap.getter_hasKey (var_className_5243.getter_string (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 207)) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 207)).operator_not (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 207)).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_arxmlMetaClass var_newClass_5730 = GALGAS_arxmlMetaClass::constructor_new (var_className_5243, GALGAS_bool (true), GALGAS_arxmlMetaElementList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 211)), GALGAS_arxmlMetaElementList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 211)), GALGAS_arxmlMetaAttributeList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 212)), GALGAS_arxmlMetaAttributeList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 212)), var_desc_5610  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 208)) ;
      {
      ioArgument_classMap.setter_insertKey (var_className_5243, var_newClass_5730, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 215)) ;
      }
      {
      ioArgument_classGraph.setter_addNode (var_className_5243, var_className_5243, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 216)) ;
      }
    }
    var_nextParentClass_5270 = var_className_5243 ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_ref) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 220)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 221)) ;
    GALGAS_lstring var_fullClassName_6318 = inCompiler->synthetizedAttribute_tokenString () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 222)) ;
    var_className_5243 = var_fullClassName_6318 ;
    const enumGalgasBool test_1 = var_fullClassName_6318.mProperty_string.getter_containsCharacter (GALGAS_char (TO_UNICODE (58)) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 225)).boolEnum () ;
    if (kBoolTrue == test_1) {
      GALGAS_stringlist var_parsed_6480 = var_fullClassName_6318.mProperty_string.getter_componentsSeparatedByString (GALGAS_string (":") COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 226)) ;
      GALGAS_string var_parsedString_6583 ;
      var_parsed_6480.method_last (var_parsedString_6583, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 227)) ;
      var_className_5243.mProperty_string = var_parsedString_6583 ;
    }
    const enumGalgasBool test_2 = GALGAS_bool (kIsNotEqual, inArgument_parentClass.mProperty_string.objectCompare (var_className_5243.mProperty_string)).boolEnum () ;
    if (kBoolTrue == test_2) {
      {
      ioArgument_classGraph.setter_addEdge (var_className_5243, inArgument_parentClass COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 233)) ;
      }
    }
    var_nextParentClass_5270 = inArgument_parentClass ;
  } break ;
  default:
    break ;
  }
  switch (select_arxmlmetaparser_5F_syntax_9 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 239)) ;
    bool repeatFlag_3 = true ;
    while (repeatFlag_3) {
      switch (select_arxmlmetaparser_5F_syntax_10 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 241)) ;
        switch (select_arxmlmetaparser_5F_syntax_11 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 242)) ;
          nt_xsd_5F_annotation_ (ioArgument_classMap, ioArgument_classGraph, var_nextParentClass_5270, inCompiler) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attribute) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 244)) ;
          nt_xsd_5F_attribute_ (ioArgument_classMap, ioArgument_classGraph, var_nextParentClass_5270, inCompiler) ;
        } break ;
        case 3: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attributeGroup) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 246)) ;
          nt_xsd_5F_attributeGroup_ (ioArgument_classMap, ioArgument_classGraph, var_nextParentClass_5270, inCompiler) ;
        } break ;
        case 4: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_choice) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 248)) ;
          nt_xsd_5F_choice_ (ioArgument_classMap, ioArgument_classGraph, var_nextParentClass_5270, inCompiler) ;
        } break ;
        case 5: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_sequence) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 250)) ;
          nt_xsd_5F_sequence_ (ioArgument_classMap, ioArgument_classGraph, var_nextParentClass_5270, inCompiler) ;
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
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 255)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attributeGroup) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 256)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 257)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 258)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_attributeGroup_i5_parse (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  switch (select_arxmlmetaparser_5F_syntax_8 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_name) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 199)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 201)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 202)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_ref) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 220)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 221)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 222)) ;
  } break ;
  default:
    break ;
  }
  switch (select_arxmlmetaparser_5F_syntax_9 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 239)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      switch (select_arxmlmetaparser_5F_syntax_10 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 241)) ;
        switch (select_arxmlmetaparser_5F_syntax_11 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 242)) ;
          nt_xsd_5F_annotation_parse (inCompiler) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attribute) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 244)) ;
          nt_xsd_5F_attribute_parse (inCompiler) ;
        } break ;
        case 3: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attributeGroup) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 246)) ;
          nt_xsd_5F_attributeGroup_parse (inCompiler) ;
        } break ;
        case 4: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_choice) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 248)) ;
          nt_xsd_5F_choice_parse (inCompiler) ;
        } break ;
        case 5: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_sequence) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 250)) ;
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
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 255)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attributeGroup) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 256)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 257)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 258)) ;
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
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 271)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      switch (select_arxmlmetaparser_5F_syntax_13 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 273)) ;
        switch (select_arxmlmetaparser_5F_syntax_14 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 274)) ;
          nt_xsd_5F_annotation_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_choice) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 276)) ;
          nt_xsd_5F_choice_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
        } break ;
        case 3: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_sequence) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 278)) ;
          nt_xsd_5F_sequence_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
        } break ;
        case 4: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_element) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 280)) ;
          nt_xsd_5F_element_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
        } break ;
        case 5: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_group) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 282)) ;
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
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 287)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_choice) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 288)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 289)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 290)) ;
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
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 271)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      switch (select_arxmlmetaparser_5F_syntax_13 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 273)) ;
        switch (select_arxmlmetaparser_5F_syntax_14 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 274)) ;
          nt_xsd_5F_annotation_parse (inCompiler) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_choice) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 276)) ;
          nt_xsd_5F_choice_parse (inCompiler) ;
        } break ;
        case 3: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_sequence) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 278)) ;
          nt_xsd_5F_sequence_parse (inCompiler) ;
        } break ;
        case 4: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_element) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 280)) ;
          nt_xsd_5F_element_parse (inCompiler) ;
        } break ;
        case 5: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_group) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 282)) ;
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
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 287)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_choice) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 288)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 289)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 290)) ;
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
  GALGAS_lstring var_complexAbstract_8404 ;
  {
  routine_lstringhere (var_complexAbstract_8404, GALGAS_string::makeEmptyString (), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 302)) ;
  }
  GALGAS_lstring var_complexMixed_8446 ;
  {
  routine_lstringhere (var_complexMixed_8446, GALGAS_string::makeEmptyString (), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 303)) ;
  }
  GALGAS_lstring var_complexName_8487 ;
  {
  routine_lstringhere (var_complexName_8487, GALGAS_string::makeEmptyString (), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 304)) ;
  }
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_arxmlmetaparser_5F_syntax_15 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_abstract) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 307)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 308)) ;
      var_complexAbstract_8404 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 309)) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_mixed) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 310)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 311)) ;
      var_complexMixed_8446 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 312)) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_name) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 313)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 314)) ;
      var_complexName_8487 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 315)) ;
      var_complexName_8487.mProperty_string = var_complexName_8487.mProperty_string.getter_stringByReplacingStringByString (GALGAS_string ("<"), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 316)) ;
      var_complexName_8487.mProperty_string = var_complexName_8487.mProperty_string.getter_stringByReplacingStringByString (GALGAS_string (">"), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 317)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, var_complexName_8487.mProperty_string.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
  if (kBoolTrue == test_1) {
    var_complexName_8487 = inArgument_parentClass ;
  }
  const enumGalgasBool test_2 = ioArgument_classMap.getter_hasKey (var_complexName_8487.getter_string (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 326)) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 326)).operator_not (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 326)).boolEnum () ;
  if (kBoolTrue == test_2) {
    GALGAS_lstring var_desc_9104 ;
    {
    routine_lstringhere (var_desc_9104, GALGAS_string::makeEmptyString (), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 327)) ;
    }
    GALGAS_arxmlMetaClass var_newClass_9138 = GALGAS_arxmlMetaClass::constructor_new (var_complexName_8487, GALGAS_bool (false), GALGAS_arxmlMetaElementList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 331)), GALGAS_arxmlMetaElementList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 331)), GALGAS_arxmlMetaAttributeList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 332)), GALGAS_arxmlMetaAttributeList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 332)), var_desc_9104  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 328)) ;
    {
    ioArgument_classMap.setter_insertKey (var_complexName_8487, var_newClass_9138, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 335)) ;
    }
    {
    ioArgument_classGraph.setter_addNode (var_complexName_8487, var_complexName_8487, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 336)) ;
    }
  }
  switch (select_arxmlmetaparser_5F_syntax_16 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 339)) ;
    bool repeatFlag_3 = true ;
    while (repeatFlag_3) {
      switch (select_arxmlmetaparser_5F_syntax_17 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 341)) ;
        switch (select_arxmlmetaparser_5F_syntax_18 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 342)) ;
          nt_xsd_5F_annotation_ (ioArgument_classMap, ioArgument_classGraph, var_complexName_8487, inCompiler) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attribute) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 344)) ;
          nt_xsd_5F_attribute_ (ioArgument_classMap, ioArgument_classGraph, var_complexName_8487, inCompiler) ;
        } break ;
        case 3: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attributeGroup) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 346)) ;
          nt_xsd_5F_attributeGroup_ (ioArgument_classMap, ioArgument_classGraph, var_complexName_8487, inCompiler) ;
        } break ;
        case 4: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_choice) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 348)) ;
          nt_xsd_5F_choice_ (ioArgument_classMap, ioArgument_classGraph, var_complexName_8487, inCompiler) ;
        } break ;
        case 5: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_sequence) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 350)) ;
          nt_xsd_5F_sequence_ (ioArgument_classMap, ioArgument_classGraph, var_complexName_8487, inCompiler) ;
        } break ;
        case 6: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_group) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 352)) ;
          nt_xsd_5F_group_ (ioArgument_classMap, ioArgument_classGraph, var_complexName_8487, inCompiler) ;
        } break ;
        case 7: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_simpleContent) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 354)) ;
          nt_xsd_5F_simpleContent_ (ioArgument_classMap, ioArgument_classGraph, var_complexName_8487, inCompiler) ;
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
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 359)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_complexType) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 360)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 361)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 362)) ;
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
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_abstract) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 307)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 308)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 309)) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_mixed) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 310)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 311)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 312)) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_name) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 313)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 314)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 315)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  switch (select_arxmlmetaparser_5F_syntax_16 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 339)) ;
    bool repeatFlag_1 = true ;
    while (repeatFlag_1) {
      switch (select_arxmlmetaparser_5F_syntax_17 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 341)) ;
        switch (select_arxmlmetaparser_5F_syntax_18 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 342)) ;
          nt_xsd_5F_annotation_parse (inCompiler) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attribute) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 344)) ;
          nt_xsd_5F_attribute_parse (inCompiler) ;
        } break ;
        case 3: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attributeGroup) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 346)) ;
          nt_xsd_5F_attributeGroup_parse (inCompiler) ;
        } break ;
        case 4: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_choice) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 348)) ;
          nt_xsd_5F_choice_parse (inCompiler) ;
        } break ;
        case 5: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_sequence) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 350)) ;
          nt_xsd_5F_sequence_parse (inCompiler) ;
        } break ;
        case 6: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_group) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 352)) ;
          nt_xsd_5F_group_parse (inCompiler) ;
        } break ;
        case 7: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_simpleContent) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 354)) ;
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
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 359)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_complexType) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 360)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 361)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 362)) ;
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
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 375)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 378)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_documentation) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 379)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 380)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 381)) ;
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
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 375)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 378)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_documentation) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 379)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 380)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 381)) ;
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
  GALGAS_arxmlMetaElement var_newElement_10992 ;
  GALGAS_lstring var_elementType_11028 ;
  {
  routine_lstringhere (var_elementType_11028, GALGAS_string::makeEmptyString (), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 394)) ;
  }
  GALGAS_lstring var_elementName_11069 ;
  {
  routine_lstringhere (var_elementName_11069, GALGAS_string::makeEmptyString (), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 395)) ;
  }
  GALGAS_lstring var_elementMin_11109 ;
  {
  routine_lstringhere (var_elementMin_11109, GALGAS_string::makeEmptyString (), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 396)) ;
  }
  GALGAS_lstring var_elementMax_11150 ;
  {
  routine_lstringhere (var_elementMax_11150, GALGAS_string::makeEmptyString (), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 397)) ;
  }
  GALGAS_lstring var_elementPrefix_11194 ;
  {
  routine_lstringhere (var_elementPrefix_11194, GALGAS_string::makeEmptyString (), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 398)) ;
  }
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_arxmlmetaparser_5F_syntax_20 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_maxOccurs) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 401)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 402)) ;
      var_elementMax_11150 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 403)) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_minOccurs) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 404)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 405)) ;
      var_elementMin_11109 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 406)) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_type) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 407)) ;
      GALGAS_lstring var_fullType_11363 ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 409)) ;
      var_fullType_11363 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 410)) ;
      const enumGalgasBool test_1 = var_fullType_11363.mProperty_string.getter_containsCharacter (GALGAS_char (TO_UNICODE (58)) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 412)).boolEnum () ;
      if (kBoolTrue == test_1) {
        GALGAS_stringlist var_parsed_11526 = var_fullType_11363.mProperty_string.getter_componentsSeparatedByString (GALGAS_string (":") COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 413)) ;
        GALGAS_string var_parsedString_11606 ;
        var_parsed_11526.method_first (var_parsedString_11606, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 415)) ;
        var_elementPrefix_11194.mProperty_string = var_parsedString_11606 ;
        var_elementPrefix_11194.mProperty_location = var_fullType_11363.mProperty_location ;
        var_parsed_11526.method_last (var_parsedString_11606, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 418)) ;
        var_elementType_11028.mProperty_string = var_parsedString_11606 ;
        var_elementType_11028.mProperty_location = var_fullType_11363.mProperty_location ;
      }else if (kBoolFalse == test_1) {
        var_elementType_11028 = var_fullType_11363 ;
      }
    } break ;
    case 5: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_name) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 424)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 425)) ;
      var_elementName_11069 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 426)) ;
      var_elementName_11069.mProperty_string = var_elementName_11069.mProperty_string.getter_stringByReplacingStringByString (GALGAS_string ("<"), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 427)) ;
      var_elementName_11069.mProperty_string = var_elementName_11069.mProperty_string.getter_stringByReplacingStringByString (GALGAS_string (">"), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 428)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, var_elementName_11069.mProperty_string.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
  if (kBoolTrue == test_2) {
    TC_Array <C_FixItDescription> fixItArray3 ;
    inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 432)), GALGAS_string ("An xsd:element must have a name."), fixItArray3  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 432)) ;
  }
  const enumGalgasBool test_4 = GALGAS_bool (kIsEqual, var_elementMax_11150.mProperty_string.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
  if (kBoolTrue == test_4) {
    {
    routine_lstringhere (var_elementMax_11150, GALGAS_string ("unbounded"), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 440)) ;
    }
  }
  const enumGalgasBool test_5 = GALGAS_bool (kIsEqual, var_elementMin_11109.mProperty_string.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
  if (kBoolTrue == test_5) {
    {
    routine_lstringhere (var_elementMin_11109, GALGAS_string ("0"), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 443)) ;
    }
  }
  const enumGalgasBool test_6 = GALGAS_bool (kIsEqual, var_elementType_11028.mProperty_string.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
  if (kBoolTrue == test_6) {
    var_elementType_11028 = var_elementName_11069 ;
  }else if (kBoolFalse == test_6) {
    {
    ioArgument_classGraph.setter_addEdge (var_elementType_11028, var_elementName_11069 COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 449)) ;
    }
  }
  const enumGalgasBool test_7 = ioArgument_classMap.getter_hasKey (var_elementName_11069.getter_string (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 452)) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 452)).operator_not (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 452)).boolEnum () ;
  if (kBoolTrue == test_7) {
    GALGAS_lstring var_desc_12841 ;
    {
    routine_lstringhere (var_desc_12841, GALGAS_string::makeEmptyString (), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 453)) ;
    }
    GALGAS_arxmlMetaClass var_newClass_12875 = GALGAS_arxmlMetaClass::constructor_new (var_elementName_11069, GALGAS_bool (false), GALGAS_arxmlMetaElementList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 457)), GALGAS_arxmlMetaElementList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 457)), GALGAS_arxmlMetaAttributeList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 458)), GALGAS_arxmlMetaAttributeList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 458)), var_desc_12841  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 454)) ;
    {
    ioArgument_classMap.setter_insertKey (var_elementName_11069, var_newClass_12875, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 461)) ;
    }
    {
    ioArgument_classGraph.setter_addNode (var_elementName_11069, var_elementName_11069, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 462)) ;
    }
  }
  var_newElement_10992 = GALGAS_arxmlMetaElement::constructor_new (var_elementName_11069, var_elementType_11028, var_elementMin_11109, var_elementMax_11150, var_elementPrefix_11194  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 465)) ;
  {
  extensionSetter_addClassElement (ioArgument_classMap, inArgument_parentClass, var_newElement_10992, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 471)) ;
  }
  switch (select_arxmlmetaparser_5F_syntax_21 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 473)) ;
    bool repeatFlag_8 = true ;
    while (repeatFlag_8) {
      switch (select_arxmlmetaparser_5F_syntax_22 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 475)) ;
        switch (select_arxmlmetaparser_5F_syntax_23 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 476)) ;
          nt_xsd_5F_annotation_ (ioArgument_classMap, ioArgument_classGraph, var_elementName_11069, inCompiler) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_complexType) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 478)) ;
          nt_xsd_5F_complexType_ (ioArgument_classMap, ioArgument_classGraph, var_elementName_11069, inCompiler) ;
        } break ;
        case 3: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_simpleType) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 480)) ;
          nt_xsd_5F_simpleType_ (ioArgument_classMap, ioArgument_classGraph, var_elementName_11069, inCompiler) ;
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
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 485)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_element) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 486)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 487)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 488)) ;
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
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_maxOccurs) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 401)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 402)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 403)) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_minOccurs) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 404)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 405)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 406)) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_type) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 407)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 409)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 410)) ;
    } break ;
    case 5: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_name) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 424)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 425)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 426)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  switch (select_arxmlmetaparser_5F_syntax_21 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 473)) ;
    bool repeatFlag_1 = true ;
    while (repeatFlag_1) {
      switch (select_arxmlmetaparser_5F_syntax_22 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 475)) ;
        switch (select_arxmlmetaparser_5F_syntax_23 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 476)) ;
          nt_xsd_5F_annotation_parse (inCompiler) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_complexType) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 478)) ;
          nt_xsd_5F_complexType_parse (inCompiler) ;
        } break ;
        case 3: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_simpleType) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 480)) ;
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
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 485)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_element) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 486)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 487)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 488)) ;
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
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_value) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 501)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 502)) ;
  GALGAS_lstring var_enumValue_14383 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 503)) ;
  {
  ioArgument_restriction.insulate (HERE) ;
  cPtr_arxmlMetaSimpletype * ptr_14400 = (cPtr_arxmlMetaSimpletype *) ioArgument_restriction.ptr () ;
  callExtensionSetter_addValue ((cPtr_arxmlMetaSimpletype *) ptr_14400, var_enumValue_14383, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 504)) ;
  }
  switch (select_arxmlmetaparser_5F_syntax_24 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 506)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      switch (select_arxmlmetaparser_5F_syntax_25 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 508)) ;
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 509)) ;
        nt_xsd_5F_annotation_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 513)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_enumeration) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 514)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 515)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 516)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_enumeration_i10_parse (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_value) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 501)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 502)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 503)) ;
  switch (select_arxmlmetaparser_5F_syntax_24 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 506)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      switch (select_arxmlmetaparser_5F_syntax_25 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 508)) ;
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 509)) ;
        nt_xsd_5F_annotation_parse (inCompiler) ;
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 513)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_enumeration) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 514)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 515)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 516)) ;
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
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 530)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      switch (select_arxmlmetaparser_5F_syntax_27 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 532)) ;
        switch (select_arxmlmetaparser_5F_syntax_28 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 533)) ;
          nt_xsd_5F_annotation_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attribute) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 535)) ;
          nt_xsd_5F_attribute_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
        } break ;
        case 3: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attributeGroup) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 537)) ;
          nt_xsd_5F_attributeGroup_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
        } break ;
        case 4: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_choice) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 539)) ;
          nt_xsd_5F_choice_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
        } break ;
        case 5: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_sequence) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 541)) ;
          nt_xsd_5F_sequence_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
        } break ;
        case 6: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_group) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 543)) ;
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
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 548)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_extension) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 549)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 550)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 551)) ;
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
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 530)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      switch (select_arxmlmetaparser_5F_syntax_27 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 532)) ;
        switch (select_arxmlmetaparser_5F_syntax_28 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 533)) ;
          nt_xsd_5F_annotation_parse (inCompiler) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attribute) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 535)) ;
          nt_xsd_5F_attribute_parse (inCompiler) ;
        } break ;
        case 3: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attributeGroup) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 537)) ;
          nt_xsd_5F_attributeGroup_parse (inCompiler) ;
        } break ;
        case 4: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_choice) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 539)) ;
          nt_xsd_5F_choice_parse (inCompiler) ;
        } break ;
        case 5: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_sequence) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 541)) ;
          nt_xsd_5F_sequence_parse (inCompiler) ;
        } break ;
        case 6: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_group) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 543)) ;
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
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 548)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_extension) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 549)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 550)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 551)) ;
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
  GALGAS_lstring var_className_15746 ;
  GALGAS_lstring var_nextParentClass_15773 ;
  switch (select_arxmlmetaparser_5F_syntax_29 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_name) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 566)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 568)) ;
    var_className_15746 = inCompiler->synthetizedAttribute_tokenString () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 569)) ;
    var_className_15746.mProperty_string = var_className_15746.mProperty_string.getter_stringByReplacingStringByString (GALGAS_string ("<"), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 570)) ;
    var_className_15746.mProperty_string = var_className_15746.mProperty_string.getter_stringByReplacingStringByString (GALGAS_string (">"), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 571)) ;
    GALGAS_lstring var_desc_16113 ;
    {
    routine_lstringhere (var_desc_16113, GALGAS_string::makeEmptyString (), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 572)) ;
    }
    const enumGalgasBool test_0 = ioArgument_classMap.getter_hasKey (var_className_15746.getter_string (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 574)) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 574)).operator_not (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 574)).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_arxmlMetaClass var_newClass_16233 = GALGAS_arxmlMetaClass::constructor_new (var_className_15746, GALGAS_bool (false), GALGAS_arxmlMetaElementList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 578)), GALGAS_arxmlMetaElementList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 578)), GALGAS_arxmlMetaAttributeList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 579)), GALGAS_arxmlMetaAttributeList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 579)), var_desc_16113  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 575)) ;
      {
      ioArgument_classMap.setter_insertKey (var_className_15746, var_newClass_16233, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 582)) ;
      }
      {
      ioArgument_classGraph.setter_addNode (var_className_15746, var_className_15746, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 583)) ;
      }
    }
    var_nextParentClass_15773 = var_className_15746 ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_ref) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 587)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 588)) ;
    GALGAS_lstring var_fullClassName_16822 = inCompiler->synthetizedAttribute_tokenString () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 589)) ;
    var_className_15746 = var_fullClassName_16822 ;
    const enumGalgasBool test_1 = var_fullClassName_16822.mProperty_string.getter_containsCharacter (GALGAS_char (TO_UNICODE (58)) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 592)).boolEnum () ;
    if (kBoolTrue == test_1) {
      GALGAS_stringlist var_parsed_16984 = var_fullClassName_16822.mProperty_string.getter_componentsSeparatedByString (GALGAS_string (":") COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 593)) ;
      GALGAS_string var_parsedString_17087 ;
      var_parsed_16984.method_last (var_parsedString_17087, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 594)) ;
      var_className_15746.mProperty_string = var_parsedString_17087 ;
    }
    const enumGalgasBool test_2 = GALGAS_bool (kIsNotEqual, inArgument_parentClass.mProperty_string.objectCompare (var_className_15746.mProperty_string)).boolEnum () ;
    if (kBoolTrue == test_2) {
      {
      ioArgument_classGraph.setter_addEdge (var_className_15746, inArgument_parentClass COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 600)) ;
      }
    }
    var_nextParentClass_15773 = inArgument_parentClass ;
  } break ;
  default:
    break ;
  }
  switch (select_arxmlmetaparser_5F_syntax_30 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 607)) ;
    bool repeatFlag_3 = true ;
    while (repeatFlag_3) {
      switch (select_arxmlmetaparser_5F_syntax_31 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 609)) ;
        switch (select_arxmlmetaparser_5F_syntax_32 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 610)) ;
          nt_xsd_5F_annotation_ (ioArgument_classMap, ioArgument_classGraph, var_nextParentClass_15773, inCompiler) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_choice) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 612)) ;
          nt_xsd_5F_choice_ (ioArgument_classMap, ioArgument_classGraph, var_nextParentClass_15773, inCompiler) ;
        } break ;
        case 3: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_sequence) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 614)) ;
          nt_xsd_5F_sequence_ (ioArgument_classMap, ioArgument_classGraph, var_nextParentClass_15773, inCompiler) ;
        } break ;
        case 4: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_element) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 616)) ;
          nt_xsd_5F_element_ (ioArgument_classMap, ioArgument_classGraph, var_nextParentClass_15773, inCompiler) ;
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
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 621)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_group) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 622)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 623)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 624)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_group_i12_parse (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  switch (select_arxmlmetaparser_5F_syntax_29 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_name) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 566)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 568)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 569)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_ref) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 587)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 588)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 589)) ;
  } break ;
  default:
    break ;
  }
  switch (select_arxmlmetaparser_5F_syntax_30 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 607)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      switch (select_arxmlmetaparser_5F_syntax_31 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 609)) ;
        switch (select_arxmlmetaparser_5F_syntax_32 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 610)) ;
          nt_xsd_5F_annotation_parse (inCompiler) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_choice) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 612)) ;
          nt_xsd_5F_choice_parse (inCompiler) ;
        } break ;
        case 3: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_sequence) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 614)) ;
          nt_xsd_5F_sequence_parse (inCompiler) ;
        } break ;
        case 4: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_element) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 616)) ;
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
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 621)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_group) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 622)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 623)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 624)) ;
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
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 636)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      switch (select_arxmlmetaparser_5F_syntax_34 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 638)) ;
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 639)) ;
        nt_xsd_5F_annotation_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 643)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 644)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 645)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 646)) ;
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
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 636)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      switch (select_arxmlmetaparser_5F_syntax_34 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 638)) ;
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 639)) ;
        nt_xsd_5F_annotation_parse (inCompiler) ;
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 643)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 644)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 645)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 646)) ;
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
  GALGAS_lstring var_baseType_18531 ;
  {
  routine_lstringhere (var_baseType_18531, GALGAS_string::makeEmptyString (), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 659)) ;
  }
  GALGAS_lstringlist var_valuesifenum_18564 = GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 660)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_base) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 662)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 663)) ;
  var_baseType_18531 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 664)) ;
  GALGAS_bool test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("xsd:string").objectCompare (var_baseType_18531.mProperty_string)) ;
  if (kBoolTrue != test_0.boolEnum ()) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("xsd:NMTOKEN").objectCompare (var_baseType_18531.mProperty_string)) ;
  }
  GALGAS_bool test_1 = test_0 ;
  if (kBoolTrue != test_1.boolEnum ()) {
    test_1 = GALGAS_bool (kIsEqual, GALGAS_string ("xsd:NMTOKENS").objectCompare (var_baseType_18531.mProperty_string)) ;
  }
  const enumGalgasBool test_2 = test_1.boolEnum () ;
  if (kBoolTrue == test_2) {
    {
    ioArgument_restriction.insulate (HERE) ;
    cPtr_arxmlMetaSimpletype * ptr_18751 = (cPtr_arxmlMetaSimpletype *) ioArgument_restriction.ptr () ;
    callExtensionSetter_setBase ((cPtr_arxmlMetaSimpletype *) ptr_18751, GALGAS_restrictionBaseType::constructor_restrictionString (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 669)), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 669)) ;
    }
    {
    ioArgument_restriction.insulate (HERE) ;
    cPtr_arxmlMetaSimpletype * ptr_18799 = (cPtr_arxmlMetaSimpletype *) ioArgument_restriction.ptr () ;
    callExtensionSetter_setType ((cPtr_arxmlMetaSimpletype *) ptr_18799, GALGAS_restrictionType::constructor_restrictionSimple (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 670)), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 670)) ;
    }
  }else if (kBoolFalse == test_2) {
    const enumGalgasBool test_3 = GALGAS_bool (kIsEqual, GALGAS_string ("xsd:unsignedInt").objectCompare (var_baseType_18531.mProperty_string)).boolEnum () ;
    if (kBoolTrue == test_3) {
      {
      ioArgument_restriction.insulate (HERE) ;
      cPtr_arxmlMetaSimpletype * ptr_18897 = (cPtr_arxmlMetaSimpletype *) ioArgument_restriction.ptr () ;
      callExtensionSetter_setBase ((cPtr_arxmlMetaSimpletype *) ptr_18897, GALGAS_restrictionBaseType::constructor_restrictionUint (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 672)), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 672)) ;
      }
      {
      ioArgument_restriction.insulate (HERE) ;
      cPtr_arxmlMetaSimpletype * ptr_18943 = (cPtr_arxmlMetaSimpletype *) ioArgument_restriction.ptr () ;
      callExtensionSetter_setType ((cPtr_arxmlMetaSimpletype *) ptr_18943, GALGAS_restrictionType::constructor_restrictionSimple (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 673)), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 673)) ;
      }
    }else if (kBoolFalse == test_3) {
      const enumGalgasBool test_4 = GALGAS_bool (kIsEqual, GALGAS_string ("xsd:double").objectCompare (var_baseType_18531.mProperty_string)).boolEnum () ;
      if (kBoolTrue == test_4) {
        {
        ioArgument_restriction.insulate (HERE) ;
        cPtr_arxmlMetaSimpletype * ptr_19036 = (cPtr_arxmlMetaSimpletype *) ioArgument_restriction.ptr () ;
        callExtensionSetter_setBase ((cPtr_arxmlMetaSimpletype *) ptr_19036, GALGAS_restrictionBaseType::constructor_restrictionDouble (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 675)), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 675)) ;
        }
        {
        ioArgument_restriction.insulate (HERE) ;
        cPtr_arxmlMetaSimpletype * ptr_19084 = (cPtr_arxmlMetaSimpletype *) ioArgument_restriction.ptr () ;
        callExtensionSetter_setType ((cPtr_arxmlMetaSimpletype *) ptr_19084, GALGAS_restrictionType::constructor_restrictionSimple (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 676)), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 676)) ;
        }
      }else if (kBoolFalse == test_4) {
        TC_Array <C_FixItDescription> fixItArray5 ;
        inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 678)), GALGAS_string ("Undefined/unimplemented base type ").add_operation (var_baseType_18531.mProperty_string, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 678)), fixItArray5  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 678)) ;
      }
    }
  }
  switch (select_arxmlmetaparser_5F_syntax_35 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 681)) ;
    bool repeatFlag_6 = true ;
    while (repeatFlag_6) {
      switch (select_arxmlmetaparser_5F_syntax_36 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 683)) ;
        switch (select_arxmlmetaparser_5F_syntax_37 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 684)) ;
          nt_xsd_5F_annotation_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attribute) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 686)) ;
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_TODO) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 687)) ;
          nt_xsd_5F_attribute_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
          {
          ioArgument_restriction.insulate (HERE) ;
          cPtr_arxmlMetaSimpletype * ptr_19450 = (cPtr_arxmlMetaSimpletype *) ioArgument_restriction.ptr () ;
          callExtensionSetter_setType ((cPtr_arxmlMetaSimpletype *) ptr_19450, GALGAS_restrictionType::constructor_restrictionUnused (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 689)), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 689)) ;
          }
        } break ;
        case 3: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attributeGroup) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 690)) ;
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_TODO) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 691)) ;
          nt_xsd_5F_attributeGroup_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
          {
          ioArgument_restriction.insulate (HERE) ;
          cPtr_arxmlMetaSimpletype * ptr_19609 = (cPtr_arxmlMetaSimpletype *) ioArgument_restriction.ptr () ;
          callExtensionSetter_setType ((cPtr_arxmlMetaSimpletype *) ptr_19609, GALGAS_restrictionType::constructor_restrictionUnused (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 693)), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 693)) ;
          }
        } break ;
        case 4: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_choice) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 694)) ;
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_TODO) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 695)) ;
          nt_xsd_5F_choice_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
          {
          ioArgument_restriction.insulate (HERE) ;
          cPtr_arxmlMetaSimpletype * ptr_19752 = (cPtr_arxmlMetaSimpletype *) ioArgument_restriction.ptr () ;
          callExtensionSetter_setType ((cPtr_arxmlMetaSimpletype *) ptr_19752, GALGAS_restrictionType::constructor_restrictionUnused (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 697)), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 697)) ;
          }
        } break ;
        case 5: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_sequence) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 698)) ;
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_TODO) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 699)) ;
          nt_xsd_5F_sequence_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
          {
          ioArgument_restriction.insulate (HERE) ;
          cPtr_arxmlMetaSimpletype * ptr_19899 = (cPtr_arxmlMetaSimpletype *) ioArgument_restriction.ptr () ;
          callExtensionSetter_setType ((cPtr_arxmlMetaSimpletype *) ptr_19899, GALGAS_restrictionType::constructor_restrictionUnused (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 701)), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 701)) ;
          }
        } break ;
        case 6: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_group) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 702)) ;
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_TODO) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 703)) ;
          nt_xsd_5F_group_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
          {
          ioArgument_restriction.insulate (HERE) ;
          cPtr_arxmlMetaSimpletype * ptr_20040 = (cPtr_arxmlMetaSimpletype *) ioArgument_restriction.ptr () ;
          callExtensionSetter_setType ((cPtr_arxmlMetaSimpletype *) ptr_20040, GALGAS_restrictionType::constructor_restrictionUnused (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 705)), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 705)) ;
          }
        } break ;
        case 7: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_simpleType) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 706)) ;
          nt_xsd_5F_simpleType_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
          {
          ioArgument_restriction.insulate (HERE) ;
          cPtr_arxmlMetaSimpletype * ptr_20176 = (cPtr_arxmlMetaSimpletype *) ioArgument_restriction.ptr () ;
          callExtensionSetter_setType ((cPtr_arxmlMetaSimpletype *) ptr_20176, GALGAS_restrictionType::constructor_restrictionUnused (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 708)), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 708)) ;
          }
        } break ;
        case 8: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_whiteSpace) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 709)) ;
          GALGAS_bool test_7 = ioArgument_restriction.getter_type (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 711)).getter_isRestrictionSimple (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 711)).operator_not (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 711)) ;
          if (kBoolTrue == test_7.boolEnum ()) {
            test_7 = ioArgument_restriction.getter_base (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 712)).getter_isRestrictionString (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 712)).operator_not (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 712)) ;
          }
          const enumGalgasBool test_8 = test_7.boolEnum () ;
          if (kBoolTrue == test_8) {
            TC_Array <C_FixItDescription> fixItArray9 ;
            inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 713)), GALGAS_string ("Pattern condition to something not a string."), fixItArray9  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 713)) ;
          }
          nt_xsd_5F_whiteSpace_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
        } break ;
        case 9: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_maxLength) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 716)) ;
          GALGAS_bool test_10 = ioArgument_restriction.getter_type (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 718)).getter_isRestrictionSimple (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 718)).operator_not (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 718)) ;
          if (kBoolTrue == test_10.boolEnum ()) {
            test_10 = ioArgument_restriction.getter_base (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 719)).getter_isRestrictionString (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 719)).operator_not (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 719)) ;
          }
          const enumGalgasBool test_11 = test_10.boolEnum () ;
          if (kBoolTrue == test_11) {
            TC_Array <C_FixItDescription> fixItArray12 ;
            inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 720)), GALGAS_string ("Pattern condition to something not a string."), fixItArray12  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 720)) ;
          }
          nt_xsd_5F_maxLength_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
        } break ;
        case 10: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_pattern) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 723)) ;
          GALGAS_bool test_13 = ioArgument_restriction.getter_type (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 725)).getter_isRestrictionSimple (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 725)).operator_not (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 725)) ;
          if (kBoolTrue == test_13.boolEnum ()) {
            test_13 = ioArgument_restriction.getter_base (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 726)).getter_isRestrictionString (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 726)).operator_not (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 726)) ;
          }
          const enumGalgasBool test_14 = test_13.boolEnum () ;
          if (kBoolTrue == test_14) {
            TC_Array <C_FixItDescription> fixItArray15 ;
            inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 727)), GALGAS_string ("Pattern condition to something not a string."), fixItArray15  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 727)) ;
          }
          nt_xsd_5F_pattern_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
        } break ;
        case 11: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_enumeration) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 730)) ;
          GALGAS_bool test_16 = ioArgument_restriction.getter_type (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 731)).getter_isRestrictionEnum (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 731)).operator_not (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 731)) ;
          if (kBoolTrue == test_16.boolEnum ()) {
            test_16 = ioArgument_restriction.getter_type (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 732)).getter_isRestrictionSimple (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 732)).operator_not (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 732)) ;
          }
          const enumGalgasBool test_17 = test_16.boolEnum () ;
          if (kBoolTrue == test_17) {
            TC_Array <C_FixItDescription> fixItArray18 ;
            inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 733)), GALGAS_string ("Multiple type in a same restriction."), fixItArray18  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 733)) ;
          }
          const enumGalgasBool test_19 = ioArgument_restriction.getter_base (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 735)).getter_isRestrictionString (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 735)).operator_not (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 735)).boolEnum () ;
          if (kBoolTrue == test_19) {
            TC_Array <C_FixItDescription> fixItArray20 ;
            inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 736)), GALGAS_string ("Enumeration while restriction base not set to string."), fixItArray20  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 736)) ;
          }
          nt_xsd_5F_enumeration_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, ioArgument_restriction, inCompiler) ;
          {
          ioArgument_restriction.insulate (HERE) ;
          cPtr_arxmlMetaSimpletype * ptr_21668 = (cPtr_arxmlMetaSimpletype *) ioArgument_restriction.ptr () ;
          callExtensionSetter_setType ((cPtr_arxmlMetaSimpletype *) ptr_21668, GALGAS_restrictionType::constructor_restrictionEnum (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 739)), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 739)) ;
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
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 743)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_restriction) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 744)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 745)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 746)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_restriction_i14_parse (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_base) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 662)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 663)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 664)) ;
  switch (select_arxmlmetaparser_5F_syntax_35 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 681)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      switch (select_arxmlmetaparser_5F_syntax_36 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 683)) ;
        switch (select_arxmlmetaparser_5F_syntax_37 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 684)) ;
          nt_xsd_5F_annotation_parse (inCompiler) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attribute) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 686)) ;
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_TODO) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 687)) ;
          nt_xsd_5F_attribute_parse (inCompiler) ;
        } break ;
        case 3: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attributeGroup) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 690)) ;
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_TODO) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 691)) ;
          nt_xsd_5F_attributeGroup_parse (inCompiler) ;
        } break ;
        case 4: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_choice) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 694)) ;
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_TODO) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 695)) ;
          nt_xsd_5F_choice_parse (inCompiler) ;
        } break ;
        case 5: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_sequence) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 698)) ;
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_TODO) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 699)) ;
          nt_xsd_5F_sequence_parse (inCompiler) ;
        } break ;
        case 6: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_group) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 702)) ;
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_TODO) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 703)) ;
          nt_xsd_5F_group_parse (inCompiler) ;
        } break ;
        case 7: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_simpleType) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 706)) ;
          nt_xsd_5F_simpleType_parse (inCompiler) ;
        } break ;
        case 8: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_whiteSpace) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 709)) ;
          nt_xsd_5F_whiteSpace_parse (inCompiler) ;
        } break ;
        case 9: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_maxLength) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 716)) ;
          nt_xsd_5F_maxLength_parse (inCompiler) ;
        } break ;
        case 10: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_pattern) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 723)) ;
          nt_xsd_5F_pattern_parse (inCompiler) ;
        } break ;
        case 11: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_enumeration) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 730)) ;
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
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 743)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_restriction) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 744)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 745)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 746)) ;
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
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 757)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_schema) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 758)) ;
  nt_xsd_5F_ignore_5F_attributes_ (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 760)) ;
  GALGAS_lstring var_rootClassName_22343 ;
  {
  routine_lstringhere (var_rootClassName_22343, GALGAS_string ("root"), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 766)) ;
  }
  GALGAS_lstring var_desc_22381 ;
  {
  routine_lstringhere (var_desc_22381, GALGAS_string ("Root class containing the main AUTOSAR node"), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 767)) ;
  }
  GALGAS_arxmlMetaClass var_rootClass_22458 = GALGAS_arxmlMetaClass::constructor_new (var_rootClassName_22343, GALGAS_bool (false), GALGAS_arxmlMetaElementList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 772)), GALGAS_arxmlMetaElementList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 772)), GALGAS_arxmlMetaAttributeList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 773)), GALGAS_arxmlMetaAttributeList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 773)), var_desc_22381  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 769)) ;
  {
  ioArgument_classMap.setter_insertKey (var_rootClassName_22343, var_rootClass_22458, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 776)) ;
  }
  {
  ioArgument_classGraph.setter_addNode (var_rootClassName_22343, var_rootClassName_22343, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 777)) ;
  }
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_arxmlmetaparser_5F_syntax_38 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 780)) ;
      switch (select_arxmlmetaparser_5F_syntax_39 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 781)) ;
        nt_xsd_5F_annotation_ (ioArgument_classMap, ioArgument_classGraph, var_rootClassName_22343, inCompiler) ;
      } break ;
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attribute) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 783)) ;
        nt_xsd_5F_attribute_ (ioArgument_classMap, ioArgument_classGraph, var_rootClassName_22343, inCompiler) ;
      } break ;
      case 3: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attributeGroup) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 785)) ;
        nt_xsd_5F_attributeGroup_ (ioArgument_classMap, ioArgument_classGraph, var_rootClassName_22343, inCompiler) ;
      } break ;
      case 4: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_complexType) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 787)) ;
        nt_xsd_5F_complexType_ (ioArgument_classMap, ioArgument_classGraph, var_rootClassName_22343, inCompiler) ;
      } break ;
      case 5: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_element) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 789)) ;
        nt_xsd_5F_element_ (ioArgument_classMap, ioArgument_classGraph, var_rootClassName_22343, inCompiler) ;
      } break ;
      case 6: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_group) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 791)) ;
        nt_xsd_5F_group_ (ioArgument_classMap, ioArgument_classGraph, var_rootClassName_22343, inCompiler) ;
      } break ;
      case 7: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_import) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 793)) ;
        nt_xsd_5F_import_ (ioArgument_classMap, ioArgument_classGraph, var_rootClassName_22343, inCompiler) ;
      } break ;
      case 8: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_simpleType) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 795)) ;
        nt_xsd_5F_simpleType_ (ioArgument_classMap, ioArgument_classGraph, var_rootClassName_22343, inCompiler) ;
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
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 801)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_schema) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 802)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 803)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_schema_i15_parse (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 757)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_schema) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 758)) ;
  nt_xsd_5F_ignore_5F_attributes_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 760)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_arxmlmetaparser_5F_syntax_38 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 780)) ;
      switch (select_arxmlmetaparser_5F_syntax_39 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 781)) ;
        nt_xsd_5F_annotation_parse (inCompiler) ;
      } break ;
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attribute) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 783)) ;
        nt_xsd_5F_attribute_parse (inCompiler) ;
      } break ;
      case 3: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attributeGroup) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 785)) ;
        nt_xsd_5F_attributeGroup_parse (inCompiler) ;
      } break ;
      case 4: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_complexType) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 787)) ;
        nt_xsd_5F_complexType_parse (inCompiler) ;
      } break ;
      case 5: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_element) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 789)) ;
        nt_xsd_5F_element_parse (inCompiler) ;
      } break ;
      case 6: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_group) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 791)) ;
        nt_xsd_5F_group_parse (inCompiler) ;
      } break ;
      case 7: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_import) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 793)) ;
        nt_xsd_5F_import_parse (inCompiler) ;
      } break ;
      case 8: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_simpleType) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 795)) ;
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
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 801)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_schema) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 802)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 803)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_sequence_i16_ (GALGAS_arxmlMetaClassMap & ioArgument_classMap,
                                                                                             GALGAS_arxmlMetaClassGraph & ioArgument_classGraph,
                                                                                             GALGAS_lstring inArgument_parentClass,
                                                                                             C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  switch (select_arxmlmetaparser_5F_syntax_40 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 815)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      switch (select_arxmlmetaparser_5F_syntax_41 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 817)) ;
        switch (select_arxmlmetaparser_5F_syntax_42 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 818)) ;
          nt_xsd_5F_annotation_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_choice) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 820)) ;
          nt_xsd_5F_choice_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
        } break ;
        case 3: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_sequence) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 822)) ;
          nt_xsd_5F_sequence_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
        } break ;
        case 4: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_element) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 824)) ;
          nt_xsd_5F_element_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
        } break ;
        case 5: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_group) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 826)) ;
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
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 831)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_sequence) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 832)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 833)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 834)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_sequence_i16_parse (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  switch (select_arxmlmetaparser_5F_syntax_40 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 815)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      switch (select_arxmlmetaparser_5F_syntax_41 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 817)) ;
        switch (select_arxmlmetaparser_5F_syntax_42 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 818)) ;
          nt_xsd_5F_annotation_parse (inCompiler) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_choice) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 820)) ;
          nt_xsd_5F_choice_parse (inCompiler) ;
        } break ;
        case 3: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_sequence) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 822)) ;
          nt_xsd_5F_sequence_parse (inCompiler) ;
        } break ;
        case 4: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_element) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 824)) ;
          nt_xsd_5F_element_parse (inCompiler) ;
        } break ;
        case 5: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_group) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 826)) ;
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
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 831)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_sequence) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 832)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 833)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 834)) ;
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
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 854)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      switch (select_arxmlmetaparser_5F_syntax_44 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 856)) ;
        switch (select_arxmlmetaparser_5F_syntax_45 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 857)) ;
          nt_xsd_5F_annotation_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_extension) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 859)) ;
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
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 866)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_simpleContent) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 867)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 868)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 869)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_simpleContent_i17_parse (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  switch (select_arxmlmetaparser_5F_syntax_43 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 854)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      switch (select_arxmlmetaparser_5F_syntax_44 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 856)) ;
        switch (select_arxmlmetaparser_5F_syntax_45 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 857)) ;
          nt_xsd_5F_annotation_parse (inCompiler) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_extension) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 859)) ;
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
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 866)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_simpleContent) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 867)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 868)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 869)) ;
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
  GALGAS_lstring var_typeName_25954 ;
  {
  routine_lstringhere (var_typeName_25954, GALGAS_string::makeEmptyString (), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 883)) ;
  }
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_arxmlmetaparser_5F_syntax_46 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_name) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 886)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 887)) ;
      var_typeName_25954 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 888)) ;
      var_typeName_25954.mProperty_string = var_typeName_25954.mProperty_string.getter_stringByReplacingStringByString (GALGAS_string ("<"), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 889)) ;
      var_typeName_25954.mProperty_string = var_typeName_25954.mProperty_string.getter_stringByReplacingStringByString (GALGAS_string (">"), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 890)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  GALGAS_bool test_1 = GALGAS_bool (kIsEqual, inArgument_parentClass.mProperty_string.objectCompare (GALGAS_string ("root"))) ;
  if (kBoolTrue == test_1.boolEnum ()) {
    test_1 = GALGAS_bool (kIsEqual, var_typeName_25954.mProperty_string.objectCompare (GALGAS_string::makeEmptyString ())) ;
  }
  const enumGalgasBool test_2 = test_1.boolEnum () ;
  if (kBoolTrue == test_2) {
    TC_Array <C_FixItDescription> fixItArray3 ;
    inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 894)), GALGAS_string ("The name attribute is required if the simpleType element is").add_operation (GALGAS_string (" a child of the schema element"), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 894)), fixItArray3  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 894)) ;
  }
  GALGAS_arxmlMetaSimpletype var_restriction_26426 = GALGAS_arxmlMetaSimpletype::constructor_new (var_typeName_25954, GALGAS_restrictionType::constructor_restrictionUnused (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 900)), GALGAS_restrictionBaseType::constructor_restrictionUndef (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 901)), GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 902))  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 898)) ;
  const enumGalgasBool test_4 = ioArgument_classMap.getter_hasKey (var_typeName_25954.getter_string (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 905)) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 905)).operator_not (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 905)).boolEnum () ;
  if (kBoolTrue == test_4) {
    GALGAS_lstring var_desc_26852 ;
    {
    routine_lstringhere (var_desc_26852, GALGAS_string::makeEmptyString (), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 906)) ;
    }
    GALGAS_arxmlMetaClass var_newClass_26886 = GALGAS_arxmlMetaClass::constructor_new (var_typeName_25954, GALGAS_bool (false), GALGAS_arxmlMetaElementList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 910)), GALGAS_arxmlMetaElementList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 910)), GALGAS_arxmlMetaAttributeList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 911)), GALGAS_arxmlMetaAttributeList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 911)), var_desc_26852  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 907)) ;
    {
    ioArgument_classMap.setter_insertKey (var_typeName_25954, var_newClass_26886, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 914)) ;
    }
    {
    ioArgument_classGraph.setter_addNode (var_typeName_25954, var_typeName_25954, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 915)) ;
    }
  }
  switch (select_arxmlmetaparser_5F_syntax_47 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 918)) ;
    bool repeatFlag_5 = true ;
    while (repeatFlag_5) {
      switch (select_arxmlmetaparser_5F_syntax_48 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 920)) ;
        switch (select_arxmlmetaparser_5F_syntax_49 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 921)) ;
          nt_xsd_5F_annotation_ (ioArgument_classMap, ioArgument_classGraph, var_typeName_25954, inCompiler) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_restriction) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 923)) ;
          nt_xsd_5F_restriction_ (ioArgument_classMap, ioArgument_classGraph, var_typeName_25954, var_restriction_26426, inCompiler) ;
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
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 928)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_simpleType) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 929)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 930)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 931)) ;
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
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_name) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 886)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 887)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 888)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  switch (select_arxmlmetaparser_5F_syntax_47 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 918)) ;
    bool repeatFlag_1 = true ;
    while (repeatFlag_1) {
      switch (select_arxmlmetaparser_5F_syntax_48 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 920)) ;
        switch (select_arxmlmetaparser_5F_syntax_49 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 921)) ;
          nt_xsd_5F_annotation_parse (inCompiler) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_restriction) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 923)) ;
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
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 928)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_simpleType) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 929)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 930)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 931)) ;
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
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 948)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      switch (select_arxmlmetaparser_5F_syntax_51 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 950)) ;
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 951)) ;
        nt_xsd_5F_annotation_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 955)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_maxLength) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 956)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 957)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 958)) ;
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
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 948)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      switch (select_arxmlmetaparser_5F_syntax_51 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 950)) ;
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 951)) ;
        nt_xsd_5F_annotation_parse (inCompiler) ;
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 955)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_maxLength) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 956)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 957)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 958)) ;
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
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 973)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      switch (select_arxmlmetaparser_5F_syntax_53 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 975)) ;
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 976)) ;
        nt_xsd_5F_annotation_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 980)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_pattern) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 981)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 982)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 983)) ;
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
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 973)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      switch (select_arxmlmetaparser_5F_syntax_53 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 975)) ;
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 976)) ;
        nt_xsd_5F_annotation_parse (inCompiler) ;
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 980)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_pattern) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 981)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 982)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 983)) ;
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
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 997)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      switch (select_arxmlmetaparser_5F_syntax_55 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 999)) ;
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1000)) ;
        nt_xsd_5F_annotation_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1004)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_whiteSpace) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1005)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1006)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1007)) ;
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
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 997)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      switch (select_arxmlmetaparser_5F_syntax_55 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 999)) ;
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1000)) ;
        nt_xsd_5F_annotation_parse (inCompiler) ;
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1004)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_whiteSpace) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1005)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1006)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1007)) ;
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
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_abstract) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1014)) ;
      GALGAS_lstring var_attributeValue_29529 ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1016)) ;
      var_attributeValue_29529 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1017)) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attributeFormDefault) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1018)) ;
      GALGAS_lstring var_attributeValue_29630 ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1020)) ;
      var_attributeValue_29630 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1021)) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attributeRef) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1022)) ;
      GALGAS_lstring var_attributeValue_29723 ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1024)) ;
      var_attributeValue_29723 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1025)) ;
    } break ;
    case 5: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_base) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1026)) ;
      GALGAS_lstring var_attributeValue_29808 ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1028)) ;
      var_attributeValue_29808 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1029)) ;
    } break ;
    case 6: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_category) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1030)) ;
      GALGAS_lstring var_attributeValue_29897 ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1032)) ;
      var_attributeValue_29897 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1033)) ;
    } break ;
    case 7: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_CATEGORY) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1034)) ;
      GALGAS_lstring var_attributeValue_29986 ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1036)) ;
      var_attributeValue_29986 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1037)) ;
    } break ;
    case 8: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_color) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1038)) ;
      GALGAS_lstring var_attributeValue_30072 ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1040)) ;
      var_attributeValue_30072 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1041)) ;
    } break ;
    case 9: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_customType) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1042)) ;
      GALGAS_lstring var_attributeValue_30163 ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1044)) ;
      var_attributeValue_30163 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1045)) ;
    } break ;
    case 10: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_elementFormDefault) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1046)) ;
      GALGAS_lstring var_attributeValue_30262 ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1048)) ;
      var_attributeValue_30262 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1049)) ;
    } break ;
    case 11: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_encoding) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1050)) ;
      GALGAS_lstring var_attributeValue_30351 ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1052)) ;
      var_attributeValue_30351 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1053)) ;
    } break ;
    case 12: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_enforceMinMultiplicity) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1054)) ;
      GALGAS_lstring var_attributeValue_30454 ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1056)) ;
      var_attributeValue_30454 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1057)) ;
    } break ;
    case 13: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_globalElement) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1058)) ;
      GALGAS_lstring var_attributeValue_30548 ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1060)) ;
      var_attributeValue_30548 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1061)) ;
    } break ;
    case 14: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_id) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1062)) ;
      GALGAS_lstring var_attributeValue_30631 ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1064)) ;
      var_attributeValue_30631 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1065)) ;
    } break ;
    case 15: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_latestBindingTime) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1066)) ;
      GALGAS_lstring var_attributeValue_30729 ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1068)) ;
      var_attributeValue_30729 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1069)) ;
    } break ;
    case 16: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_maxOccurs) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1070)) ;
      GALGAS_lstring var_attributeValue_30819 ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1072)) ;
      var_attributeValue_30819 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1073)) ;
    } break ;
    case 17: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_minOccurs) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1074)) ;
      GALGAS_lstring var_attributeValue_30909 ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1076)) ;
      var_attributeValue_30909 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1077)) ;
    } break ;
    case 18: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_mixed) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1078)) ;
      GALGAS_lstring var_attributeValue_30995 ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1080)) ;
      var_attributeValue_30995 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1081)) ;
    } break ;
    case 19: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_name) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1082)) ;
      GALGAS_lstring var_attributeValue_31080 ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1084)) ;
      var_attributeValue_31080 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1085)) ;
    } break ;
    case 20: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_namePlural) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1086)) ;
      GALGAS_lstring var_attributeValue_31171 ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1088)) ;
      var_attributeValue_31171 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1089)) ;
    } break ;
    case 21: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_namespace) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1090)) ;
      GALGAS_lstring var_attributeValue_31261 ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1092)) ;
      var_attributeValue_31261 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1093)) ;
    } break ;
    case 22: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_noteType) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1094)) ;
      GALGAS_lstring var_attributeValue_31350 ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1096)) ;
      var_attributeValue_31350 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1097)) ;
    } break ;
    case 23: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_nsPrefix) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1098)) ;
      GALGAS_lstring var_attributeValue_31439 ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1100)) ;
      var_attributeValue_31439 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1101)) ;
    } break ;
    case 24: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_qualifiedName) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1102)) ;
      GALGAS_lstring var_attributeValue_31533 ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1104)) ;
      var_attributeValue_31533 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1105)) ;
    } break ;
    case 25: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_recommendedPackage) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1106)) ;
      GALGAS_lstring var_attributeValue_31632 ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1108)) ;
      var_attributeValue_31632 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1109)) ;
    } break ;
    case 26: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_ref) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1110)) ;
      GALGAS_lstring var_attributeValue_31716 ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1112)) ;
      var_attributeValue_31716 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1113)) ;
    } break ;
    case 27: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_roleElement) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1114)) ;
      GALGAS_lstring var_attributeValue_31808 ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1116)) ;
      var_attributeValue_31808 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1117)) ;
    } break ;
    case 28: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_roleWrapperElement) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1118)) ;
      GALGAS_lstring var_attributeValue_31907 ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1120)) ;
      var_attributeValue_31907 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1121)) ;
    } break ;
    case 29: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_schemaLocation) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1122)) ;
      GALGAS_lstring var_attributeValue_32002 ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1124)) ;
      var_attributeValue_32002 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1125)) ;
    } break ;
    case 30: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_sequenceOffset) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1126)) ;
      GALGAS_lstring var_attributeValue_32097 ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1128)) ;
      var_attributeValue_32097 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1129)) ;
    } break ;
    case 31: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_source) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1130)) ;
      GALGAS_lstring var_attributeValue_32184 ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1132)) ;
      var_attributeValue_32184 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1133)) ;
    } break ;
    case 32: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_Splitkey) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1134)) ;
      GALGAS_lstring var_attributeValue_32273 ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1136)) ;
      var_attributeValue_32273 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1137)) ;
    } break ;
    case 33: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_Status) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1138)) ;
      GALGAS_lstring var_attributeValue_32360 ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1140)) ;
      var_attributeValue_32360 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1141)) ;
    } break ;
    case 34: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_StatusRevisionBegin) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1142)) ;
      GALGAS_lstring var_attributeValue_32460 ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1144)) ;
      var_attributeValue_32460 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1145)) ;
    } break ;
    case 35: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_targetNamespace) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1146)) ;
      GALGAS_lstring var_attributeValue_32556 ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1148)) ;
      var_attributeValue_32556 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1149)) ;
    } break ;
    case 36: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_type) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1150)) ;
      GALGAS_lstring var_attributeValue_32641 ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1152)) ;
      var_attributeValue_32641 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1153)) ;
    } break ;
    case 37: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_typeElement) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1154)) ;
      GALGAS_lstring var_attributeValue_32733 ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1156)) ;
      var_attributeValue_32733 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1157)) ;
    } break ;
    case 38: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_typeWrapperElement) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1158)) ;
      GALGAS_lstring var_attributeValue_32832 ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1160)) ;
      var_attributeValue_32832 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1161)) ;
    } break ;
    case 39: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_use) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1162)) ;
      GALGAS_lstring var_attributeValue_32916 ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1164)) ;
      var_attributeValue_32916 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1165)) ;
    } break ;
    case 40: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_value) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1166)) ;
      GALGAS_lstring var_attributeValue_33002 ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1168)) ;
      var_attributeValue_33002 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1169)) ;
    } break ;
    case 41: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_version) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1170)) ;
      GALGAS_lstring var_attributeValue_33090 ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1172)) ;
      var_attributeValue_33090 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1173)) ;
    } break ;
    case 42: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlns_3A_AR) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1174)) ;
      GALGAS_lstring var_attributeValue_33179 ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1176)) ;
      var_attributeValue_33179 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1177)) ;
    } break ;
    case 43: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlns_3A_xsd) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1178)) ;
      GALGAS_lstring var_attributeValue_33269 ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1180)) ;
      var_attributeValue_33269 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1181)) ;
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
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_abstract) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1014)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1016)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1017)) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attributeFormDefault) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1018)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1020)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1021)) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attributeRef) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1022)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1024)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1025)) ;
    } break ;
    case 5: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_base) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1026)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1028)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1029)) ;
    } break ;
    case 6: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_category) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1030)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1032)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1033)) ;
    } break ;
    case 7: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_CATEGORY) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1034)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1036)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1037)) ;
    } break ;
    case 8: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_color) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1038)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1040)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1041)) ;
    } break ;
    case 9: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_customType) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1042)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1044)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1045)) ;
    } break ;
    case 10: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_elementFormDefault) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1046)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1048)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1049)) ;
    } break ;
    case 11: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_encoding) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1050)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1052)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1053)) ;
    } break ;
    case 12: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_enforceMinMultiplicity) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1054)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1056)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1057)) ;
    } break ;
    case 13: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_globalElement) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1058)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1060)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1061)) ;
    } break ;
    case 14: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_id) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1062)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1064)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1065)) ;
    } break ;
    case 15: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_latestBindingTime) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1066)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1068)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1069)) ;
    } break ;
    case 16: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_maxOccurs) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1070)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1072)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1073)) ;
    } break ;
    case 17: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_minOccurs) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1074)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1076)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1077)) ;
    } break ;
    case 18: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_mixed) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1078)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1080)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1081)) ;
    } break ;
    case 19: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_name) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1082)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1084)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1085)) ;
    } break ;
    case 20: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_namePlural) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1086)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1088)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1089)) ;
    } break ;
    case 21: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_namespace) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1090)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1092)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1093)) ;
    } break ;
    case 22: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_noteType) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1094)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1096)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1097)) ;
    } break ;
    case 23: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_nsPrefix) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1098)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1100)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1101)) ;
    } break ;
    case 24: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_qualifiedName) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1102)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1104)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1105)) ;
    } break ;
    case 25: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_recommendedPackage) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1106)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1108)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1109)) ;
    } break ;
    case 26: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_ref) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1110)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1112)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1113)) ;
    } break ;
    case 27: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_roleElement) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1114)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1116)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1117)) ;
    } break ;
    case 28: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_roleWrapperElement) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1118)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1120)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1121)) ;
    } break ;
    case 29: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_schemaLocation) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1122)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1124)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1125)) ;
    } break ;
    case 30: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_sequenceOffset) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1126)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1128)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1129)) ;
    } break ;
    case 31: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_source) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1130)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1132)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1133)) ;
    } break ;
    case 32: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_Splitkey) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1134)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1136)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1137)) ;
    } break ;
    case 33: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_Status) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1138)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1140)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1141)) ;
    } break ;
    case 34: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_StatusRevisionBegin) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1142)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1144)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1145)) ;
    } break ;
    case 35: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_targetNamespace) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1146)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1148)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1149)) ;
    } break ;
    case 36: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_type) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1150)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1152)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1153)) ;
    } break ;
    case 37: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_typeElement) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1154)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1156)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1157)) ;
    } break ;
    case 38: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_typeWrapperElement) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1158)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1160)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1161)) ;
    } break ;
    case 39: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_use) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1162)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1164)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1165)) ;
    } break ;
    case 40: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_value) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1166)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1168)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1169)) ;
    } break ;
    case 41: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_version) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1170)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1172)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1173)) ;
    } break ;
    case 42: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlns_3A_AR) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1174)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1176)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1177)) ;
    } break ;
    case 43: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlns_3A_xsd) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1178)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1180)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 1181)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlDataList_2D_element::GALGAS_gtlDataList_2D_element (void) :
mProperty_data () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlDataList_2D_element::~ GALGAS_gtlDataList_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlDataList_2D_element::GALGAS_gtlDataList_2D_element (const GALGAS_gtlData & inOperand0) :
mProperty_data (inOperand0) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlDataList_2D_element GALGAS_gtlDataList_2D_element::constructor_new (const GALGAS_gtlData & inOperand0 
                                                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlDataList_2D_element result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_gtlDataList_2D_element (inOperand0) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_gtlDataList_2D_element::objectCompare (const GALGAS_gtlDataList_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_data.objectCompare (inOperand.mProperty_data) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_gtlDataList_2D_element::isValid (void) const {
  return mProperty_data.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlDataList_2D_element::drop (void) {
  mProperty_data.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData GALGAS_gtlDataList_2D_element::getter_data (UNUSED_LOCATION_ARGS) const {
  return mProperty_data ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @gtlDataList-element type                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlDataList_2D_element ("gtlDataList-element",
                                               NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlDataList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlDataList_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlDataList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlDataList_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarMap_2D_element::GALGAS_gtlVarMap_2D_element (void) :
mProperty_lkey (),
mProperty_value () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarMap_2D_element::~ GALGAS_gtlVarMap_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarMap_2D_element::GALGAS_gtlVarMap_2D_element (const GALGAS_lstring & inOperand0,
                                                          const GALGAS_gtlData & inOperand1) :
mProperty_lkey (inOperand0),
mProperty_value (inOperand1) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlVarMap_2D_element GALGAS_gtlVarMap_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                          const GALGAS_gtlData & inOperand1 
                                                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlVarMap_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_gtlVarMap_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_gtlVarMap_2D_element::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_value.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlVarMap_2D_element::drop (void) {
  mProperty_lkey.drop () ;
  mProperty_value.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_gtlVarMap_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mProperty_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData GALGAS_gtlVarMap_2D_element::getter_value (UNUSED_LOCATION_ARGS) const {
  return mProperty_value ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               @gtlVarMap-element type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlVarMap_2D_element ("gtlVarMap-element",
                                             NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlVarMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlVarMap_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlVarMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlVarMap_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpressionMap_2D_element::GALGAS_gtlExpressionMap_2D_element (void) :
mProperty_lkey (),
mProperty_expression () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpressionMap_2D_element::~ GALGAS_gtlExpressionMap_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpressionMap_2D_element::GALGAS_gtlExpressionMap_2D_element (const GALGAS_lstring & inOperand0,
                                                                        const GALGAS_gtlExpression & inOperand1) :
mProperty_lkey (inOperand0),
mProperty_expression (inOperand1) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpressionMap_2D_element GALGAS_gtlExpressionMap_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                        const GALGAS_gtlExpression & inOperand1 
                                                                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlExpressionMap_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_gtlExpressionMap_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_gtlExpressionMap_2D_element::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_expression.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlExpressionMap_2D_element::drop (void) {
  mProperty_lkey.drop () ;
  mProperty_expression.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_gtlExpressionMap_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mProperty_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpression GALGAS_gtlExpressionMap_2D_element::getter_expression (UNUSED_LOCATION_ARGS) const {
  return mProperty_expression ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           @gtlExpressionMap-element type                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlExpressionMap_2D_element ("gtlExpressionMap-element",
                                                    NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlExpressionMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlExpressionMap_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlExpressionMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlExpressionMap_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTemplateMap_2D_element::GALGAS_gtlTemplateMap_2D_element (void) :
mProperty_lkey (),
mProperty_aTemplate () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTemplateMap_2D_element::~ GALGAS_gtlTemplateMap_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTemplateMap_2D_element::GALGAS_gtlTemplateMap_2D_element (const GALGAS_lstring & inOperand0,
                                                                    const GALGAS_gtlTemplate & inOperand1) :
mProperty_lkey (inOperand0),
mProperty_aTemplate (inOperand1) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTemplateMap_2D_element GALGAS_gtlTemplateMap_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_gtlTemplateMap_2D_element (GALGAS_lstring::constructor_default (HERE),
                                           GALGAS_gtlTemplate::constructor_default (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTemplateMap_2D_element GALGAS_gtlTemplateMap_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                    const GALGAS_gtlTemplate & inOperand1 
                                                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlTemplateMap_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_gtlTemplateMap_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_gtlTemplateMap_2D_element::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_aTemplate.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlTemplateMap_2D_element::drop (void) {
  mProperty_lkey.drop () ;
  mProperty_aTemplate.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_gtlTemplateMap_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mProperty_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTemplate GALGAS_gtlTemplateMap_2D_element::getter_aTemplate (UNUSED_LOCATION_ARGS) const {
  return mProperty_aTemplate ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            @gtlTemplateMap-element type                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlTemplateMap_2D_element ("gtlTemplateMap-element",
                                                  NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlTemplateMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlTemplateMap_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlTemplateMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlTemplateMap_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpressionList_2D_element::GALGAS_gtlExpressionList_2D_element (void) :
mProperty_expression () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpressionList_2D_element::~ GALGAS_gtlExpressionList_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpressionList_2D_element::GALGAS_gtlExpressionList_2D_element (const GALGAS_gtlExpression & inOperand0) :
mProperty_expression (inOperand0) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpressionList_2D_element GALGAS_gtlExpressionList_2D_element::constructor_new (const GALGAS_gtlExpression & inOperand0 
                                                                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlExpressionList_2D_element result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_gtlExpressionList_2D_element (inOperand0) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_gtlExpressionList_2D_element::objectCompare (const GALGAS_gtlExpressionList_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_expression.objectCompare (inOperand.mProperty_expression) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_gtlExpressionList_2D_element::isValid (void) const {
  return mProperty_expression.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlExpressionList_2D_element::drop (void) {
  mProperty_expression.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpression GALGAS_gtlExpressionList_2D_element::getter_expression (UNUSED_LOCATION_ARGS) const {
  return mProperty_expression ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           @gtlExpressionList-element type                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlExpressionList_2D_element ("gtlExpressionList-element",
                                                     NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlExpressionList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlExpressionList_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlExpressionList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlExpressionList_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_list_2D_element::GALGAS_list_2D_element (void) :
mProperty_value () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_list_2D_element::~ GALGAS_list_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_list_2D_element::GALGAS_list_2D_element (const GALGAS_gtlData & inOperand0) :
mProperty_value (inOperand0) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_list_2D_element GALGAS_list_2D_element::constructor_new (const GALGAS_gtlData & inOperand0 
                                                                COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_list_2D_element result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_list_2D_element (inOperand0) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_list_2D_element::objectCompare (const GALGAS_list_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_value.objectCompare (inOperand.mProperty_value) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_list_2D_element::isValid (void) const {
  return mProperty_value.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_list_2D_element::drop (void) {
  mProperty_value.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData GALGAS_list_2D_element::getter_value (UNUSED_LOCATION_ARGS) const {
  return mProperty_value ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 @list-element type                                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_list_2D_element ("list-element",
                                        NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_list_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_list_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_list_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_list_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringset_2D_element::GALGAS_lstringset_2D_element (void) :
mProperty_lkey () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringset_2D_element::~ GALGAS_lstringset_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringset_2D_element::GALGAS_lstringset_2D_element (const GALGAS_lstring & inOperand0) :
mProperty_lkey (inOperand0) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringset_2D_element GALGAS_lstringset_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_lstringset_2D_element (GALGAS_lstring::constructor_default (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringset_2D_element GALGAS_lstringset_2D_element::constructor_new (const GALGAS_lstring & inOperand0 
                                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstringset_2D_element result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_lstringset_2D_element (inOperand0) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_lstringset_2D_element::objectCompare (const GALGAS_lstringset_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_lkey.objectCompare (inOperand.mProperty_lkey) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_lstringset_2D_element::isValid (void) const {
  return mProperty_lkey.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_lstringset_2D_element::drop (void) {
  mProperty_lkey.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_lstringset_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mProperty_lkey ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @lstringset-element type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_lstringset_2D_element ("lstringset-element",
                                              NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_lstringset_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_lstringset_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_lstringset_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_lstringset_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlArgumentList_2D_element::GALGAS_gtlArgumentList_2D_element (void) :
mProperty_typed (),
mProperty_type (),
mProperty_name () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlArgumentList_2D_element::~ GALGAS_gtlArgumentList_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlArgumentList_2D_element::GALGAS_gtlArgumentList_2D_element (const GALGAS_bool & inOperand0,
                                                                      const GALGAS_type & inOperand1,
                                                                      const GALGAS_lstring & inOperand2) :
mProperty_typed (inOperand0),
mProperty_type (inOperand1),
mProperty_name (inOperand2) {
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_gtlArgumentList_2D_element::isValid (void) const {
  return mProperty_typed.isValid () && mProperty_type.isValid () && mProperty_name.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlArgumentList_2D_element::drop (void) {
  mProperty_typed.drop () ;
  mProperty_type.drop () ;
  mProperty_name.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_gtlArgumentList_2D_element::getter_typed (UNUSED_LOCATION_ARGS) const {
  return mProperty_typed ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_type GALGAS_gtlArgumentList_2D_element::getter_type (UNUSED_LOCATION_ARGS) const {
  return mProperty_type ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_gtlArgumentList_2D_element::getter_name (UNUSED_LOCATION_ARGS) const {
  return mProperty_name ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            @gtlArgumentList-element type                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlArgumentList_2D_element ("gtlArgumentList-element",
                                                   NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlArgumentList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlArgumentList_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlArgumentList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlArgumentList_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlProcMap_2D_element::GALGAS_gtlProcMap_2D_element (void) :
mProperty_lkey (),
mProperty_procedure () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlProcMap_2D_element::~ GALGAS_gtlProcMap_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlProcMap_2D_element::GALGAS_gtlProcMap_2D_element (const GALGAS_lstring & inOperand0,
                                                            const GALGAS_gtlProcedure & inOperand1) :
mProperty_lkey (inOperand0),
mProperty_procedure (inOperand1) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlProcMap_2D_element GALGAS_gtlProcMap_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_gtlProcMap_2D_element (GALGAS_lstring::constructor_default (HERE),
                                       GALGAS_gtlProcedure::constructor_default (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlProcMap_2D_element GALGAS_gtlProcMap_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                            const GALGAS_gtlProcedure & inOperand1 
                                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlProcMap_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_gtlProcMap_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_gtlProcMap_2D_element::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_procedure.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlProcMap_2D_element::drop (void) {
  mProperty_lkey.drop () ;
  mProperty_procedure.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_gtlProcMap_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mProperty_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlProcedure GALGAS_gtlProcMap_2D_element::getter_procedure (UNUSED_LOCATION_ARGS) const {
  return mProperty_procedure ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @gtlProcMap-element type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlProcMap_2D_element ("gtlProcMap-element",
                                              NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlProcMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlProcMap_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlProcMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlProcMap_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlFuncMap_2D_element::GALGAS_gtlFuncMap_2D_element (void) :
mProperty_lkey (),
mProperty_function () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlFuncMap_2D_element::~ GALGAS_gtlFuncMap_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlFuncMap_2D_element::GALGAS_gtlFuncMap_2D_element (const GALGAS_lstring & inOperand0,
                                                            const GALGAS_gtlFunction & inOperand1) :
mProperty_lkey (inOperand0),
mProperty_function (inOperand1) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlFuncMap_2D_element GALGAS_gtlFuncMap_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_gtlFuncMap_2D_element (GALGAS_lstring::constructor_default (HERE),
                                       GALGAS_gtlFunction::constructor_default (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlFuncMap_2D_element GALGAS_gtlFuncMap_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                            const GALGAS_gtlFunction & inOperand1 
                                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlFuncMap_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_gtlFuncMap_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_gtlFuncMap_2D_element::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_function.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlFuncMap_2D_element::drop (void) {
  mProperty_lkey.drop () ;
  mProperty_function.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_gtlFuncMap_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mProperty_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlFunction GALGAS_gtlFuncMap_2D_element::getter_function (UNUSED_LOCATION_ARGS) const {
  return mProperty_function ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @gtlFuncMap-element type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlFuncMap_2D_element ("gtlFuncMap-element",
                                              NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlFuncMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlFuncMap_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlFuncMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlFuncMap_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlGetterMap_2D_element::GALGAS_gtlGetterMap_2D_element (void) :
mProperty_lkey (),
mProperty_theGetter () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlGetterMap_2D_element::~ GALGAS_gtlGetterMap_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlGetterMap_2D_element::GALGAS_gtlGetterMap_2D_element (const GALGAS_lstring & inOperand0,
                                                                const GALGAS_gtlGetter & inOperand1) :
mProperty_lkey (inOperand0),
mProperty_theGetter (inOperand1) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlGetterMap_2D_element GALGAS_gtlGetterMap_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                const GALGAS_gtlGetter & inOperand1 
                                                                                COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlGetterMap_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_gtlGetterMap_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_gtlGetterMap_2D_element::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_theGetter.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlGetterMap_2D_element::drop (void) {
  mProperty_lkey.drop () ;
  mProperty_theGetter.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_gtlGetterMap_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mProperty_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlGetter GALGAS_gtlGetterMap_2D_element::getter_theGetter (UNUSED_LOCATION_ARGS) const {
  return mProperty_theGetter ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             @gtlGetterMap-element type                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlGetterMap_2D_element ("gtlGetterMap-element",
                                                NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlGetterMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlGetterMap_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlGetterMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlGetterMap_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlSetterMap_2D_element::GALGAS_gtlSetterMap_2D_element (void) :
mProperty_lkey (),
mProperty_theSetter () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlSetterMap_2D_element::~ GALGAS_gtlSetterMap_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlSetterMap_2D_element::GALGAS_gtlSetterMap_2D_element (const GALGAS_lstring & inOperand0,
                                                                const GALGAS_gtlSetter & inOperand1) :
mProperty_lkey (inOperand0),
mProperty_theSetter (inOperand1) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlSetterMap_2D_element GALGAS_gtlSetterMap_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                const GALGAS_gtlSetter & inOperand1 
                                                                                COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlSetterMap_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_gtlSetterMap_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_gtlSetterMap_2D_element::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_theSetter.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlSetterMap_2D_element::drop (void) {
  mProperty_lkey.drop () ;
  mProperty_theSetter.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_gtlSetterMap_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mProperty_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlSetter GALGAS_gtlSetterMap_2D_element::getter_theSetter (UNUSED_LOCATION_ARGS) const {
  return mProperty_theSetter ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             @gtlSetterMap-element type                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlSetterMap_2D_element ("gtlSetterMap-element",
                                                NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlSetterMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlSetterMap_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlSetterMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlSetterMap_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlThenElsifStatementList_2D_element::GALGAS_gtlThenElsifStatementList_2D_element (void) :
mProperty_condition (),
mProperty_instructionList () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlThenElsifStatementList_2D_element::~ GALGAS_gtlThenElsifStatementList_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlThenElsifStatementList_2D_element::GALGAS_gtlThenElsifStatementList_2D_element (const GALGAS_gtlExpression & inOperand0,
                                                                                          const GALGAS_gtlInstructionList & inOperand1) :
mProperty_condition (inOperand0),
mProperty_instructionList (inOperand1) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlThenElsifStatementList_2D_element GALGAS_gtlThenElsifStatementList_2D_element::constructor_new (const GALGAS_gtlExpression & inOperand0,
                                                                                                          const GALGAS_gtlInstructionList & inOperand1 
                                                                                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlThenElsifStatementList_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_gtlThenElsifStatementList_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_gtlThenElsifStatementList_2D_element::isValid (void) const {
  return mProperty_condition.isValid () && mProperty_instructionList.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlThenElsifStatementList_2D_element::drop (void) {
  mProperty_condition.drop () ;
  mProperty_instructionList.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlExpression GALGAS_gtlThenElsifStatementList_2D_element::getter_condition (UNUSED_LOCATION_ARGS) const {
  return mProperty_condition ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlInstructionList GALGAS_gtlThenElsifStatementList_2D_element::getter_instructionList (UNUSED_LOCATION_ARGS) const {
  return mProperty_instructionList ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       @gtlThenElsifStatementList-element type                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlThenElsifStatementList_2D_element ("gtlThenElsifStatementList-element",
                                                             NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlThenElsifStatementList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlThenElsifStatementList_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlThenElsifStatementList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlThenElsifStatementList_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sortingKeyList_2D_element::GALGAS_sortingKeyList_2D_element (void) :
mProperty_key (),
mProperty_order () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sortingKeyList_2D_element::~ GALGAS_sortingKeyList_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sortingKeyList_2D_element::GALGAS_sortingKeyList_2D_element (const GALGAS_lstring & inOperand0,
                                                                    const GALGAS_lsint & inOperand1) :
mProperty_key (inOperand0),
mProperty_order (inOperand1) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sortingKeyList_2D_element GALGAS_sortingKeyList_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_sortingKeyList_2D_element (GALGAS_lstring::constructor_default (HERE),
                                           GALGAS_lsint::constructor_default (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sortingKeyList_2D_element GALGAS_sortingKeyList_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                    const GALGAS_lsint & inOperand1 
                                                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_sortingKeyList_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_sortingKeyList_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_sortingKeyList_2D_element::isValid (void) const {
  return mProperty_key.isValid () && mProperty_order.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_sortingKeyList_2D_element::drop (void) {
  mProperty_key.drop () ;
  mProperty_order.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_sortingKeyList_2D_element::getter_key (UNUSED_LOCATION_ARGS) const {
  return mProperty_key ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lsint GALGAS_sortingKeyList_2D_element::getter_order (UNUSED_LOCATION_ARGS) const {
  return mProperty_order ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            @sortingKeyList-element type                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_sortingKeyList_2D_element ("sortingKeyList-element",
                                                  NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_sortingKeyList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_sortingKeyList_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_sortingKeyList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_sortingKeyList_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_numberList_2D_element::GALGAS_numberList_2D_element (void) :
mProperty_location (),
mProperty_value () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_numberList_2D_element::~ GALGAS_numberList_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_numberList_2D_element::GALGAS_numberList_2D_element (const GALGAS_location & inOperand0,
                                                            const GALGAS_object_5F_t & inOperand1) :
mProperty_location (inOperand0),
mProperty_value (inOperand1) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_numberList_2D_element GALGAS_numberList_2D_element::constructor_new (const GALGAS_location & inOperand0,
                                                                            const GALGAS_object_5F_t & inOperand1 
                                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_numberList_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_numberList_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_numberList_2D_element::isValid (void) const {
  return mProperty_location.isValid () && mProperty_value.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_numberList_2D_element::drop (void) {
  mProperty_location.drop () ;
  mProperty_value.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_location GALGAS_numberList_2D_element::getter_location (UNUSED_LOCATION_ARGS) const {
  return mProperty_location ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_object_5F_t GALGAS_numberList_2D_element::getter_value (UNUSED_LOCATION_ARGS) const {
  return mProperty_value ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @numberList-element type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_numberList_2D_element ("numberList-element",
                                              NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_numberList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_numberList_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_numberList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_numberList_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementationObjectMap_2D_element::GALGAS_implementationObjectMap_2D_element (void) :
mProperty_lkey (),
mProperty_type () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementationObjectMap_2D_element::~ GALGAS_implementationObjectMap_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementationObjectMap_2D_element::GALGAS_implementationObjectMap_2D_element (const GALGAS_lstring & inOperand0,
                                                                                      const GALGAS_impType & inOperand1) :
mProperty_lkey (inOperand0),
mProperty_type (inOperand1) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementationObjectMap_2D_element GALGAS_implementationObjectMap_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                                      const GALGAS_impType & inOperand1 
                                                                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_implementationObjectMap_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_implementationObjectMap_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_implementationObjectMap_2D_element::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_type.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_implementationObjectMap_2D_element::drop (void) {
  mProperty_lkey.drop () ;
  mProperty_type.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_implementationObjectMap_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mProperty_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_impType GALGAS_implementationObjectMap_2D_element::getter_type (UNUSED_LOCATION_ARGS) const {
  return mProperty_type ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        @implementationObjectMap-element type                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_implementationObjectMap_2D_element ("implementationObjectMap-element",
                                                           NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_implementationObjectMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_implementationObjectMap_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_implementationObjectMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_implementationObjectMap_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_enumValues_2D_element::GALGAS_enumValues_2D_element (void) :
mProperty_lkey (),
mProperty_subAttributes () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_enumValues_2D_element::~ GALGAS_enumValues_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_enumValues_2D_element::GALGAS_enumValues_2D_element (const GALGAS_lstring & inOperand0,
                                                            const GALGAS_implementationObjectMap & inOperand1) :
mProperty_lkey (inOperand0),
mProperty_subAttributes (inOperand1) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_enumValues_2D_element GALGAS_enumValues_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_enumValues_2D_element (GALGAS_lstring::constructor_default (HERE),
                                       GALGAS_implementationObjectMap::constructor_emptyMap (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_enumValues_2D_element GALGAS_enumValues_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                            const GALGAS_implementationObjectMap & inOperand1 
                                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_enumValues_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_enumValues_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_enumValues_2D_element::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_subAttributes.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_enumValues_2D_element::drop (void) {
  mProperty_lkey.drop () ;
  mProperty_subAttributes.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_enumValues_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mProperty_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementationObjectMap GALGAS_enumValues_2D_element::getter_subAttributes (UNUSED_LOCATION_ARGS) const {
  return mProperty_subAttributes ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @enumValues-element type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_enumValues_2D_element ("enumValues-element",
                                              NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_enumValues_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_enumValues_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_enumValues_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_enumValues_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementationMap_2D_element::GALGAS_implementationMap_2D_element (void) :
mProperty_lkey (),
mProperty_obj () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementationMap_2D_element::~ GALGAS_implementationMap_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementationMap_2D_element::GALGAS_implementationMap_2D_element (const GALGAS_lstring & inOperand0,
                                                                          const GALGAS_implementationObject & inOperand1) :
mProperty_lkey (inOperand0),
mProperty_obj (inOperand1) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementationMap_2D_element GALGAS_implementationMap_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_implementationMap_2D_element (GALGAS_lstring::constructor_default (HERE),
                                              GALGAS_implementationObject::constructor_default (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementationMap_2D_element GALGAS_implementationMap_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                          const GALGAS_implementationObject & inOperand1 
                                                                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_implementationMap_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_implementationMap_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_implementationMap_2D_element::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_obj.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_implementationMap_2D_element::drop (void) {
  mProperty_lkey.drop () ;
  mProperty_obj.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_implementationMap_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mProperty_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementationObject GALGAS_implementationMap_2D_element::getter_obj (UNUSED_LOCATION_ARGS) const {
  return mProperty_obj ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           @implementationMap-element type                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_implementationMap_2D_element ("implementationMap-element",
                                                     NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_implementationMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_implementationMap_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_implementationMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_implementationMap_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_identifierMap_2D_element::GALGAS_identifierMap_2D_element (void) :
mProperty_lkey (),
mProperty_value () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_identifierMap_2D_element::~ GALGAS_identifierMap_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_identifierMap_2D_element::GALGAS_identifierMap_2D_element (const GALGAS_lstring & inOperand0,
                                                                  const GALGAS_object_5F_t & inOperand1) :
mProperty_lkey (inOperand0),
mProperty_value (inOperand1) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_identifierMap_2D_element GALGAS_identifierMap_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                  const GALGAS_object_5F_t & inOperand1 
                                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_identifierMap_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_identifierMap_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_identifierMap_2D_element::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_value.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_identifierMap_2D_element::drop (void) {
  mProperty_lkey.drop () ;
  mProperty_value.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_identifierMap_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mProperty_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_object_5F_t GALGAS_identifierMap_2D_element::getter_value (UNUSED_LOCATION_ARGS) const {
  return mProperty_value ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             @identifierMap-element type                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_identifierMap_2D_element ("identifierMap-element",
                                                 NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_identifierMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_identifierMap_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_identifierMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_identifierMap_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

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

