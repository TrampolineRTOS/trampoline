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

static const int32_t gProductions_goil_type_level_include [] = {
// At index 0 : <implementation_definition>, in file 'implementation_parser.ggs', line 36
  TERMINAL (C_Lexique_goil_5F_lexique::kToken_IMPLEMENTATION) // $IMPLEMENTATION$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (15) // <implementation_object_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, END_PRODUCTION
// At index 7 : <start>, in file 'goil_syntax.ggs', line 38
, NONTERMINAL (6) // <OIL_version>
, NONTERMINAL (2) // <file>
, END_PRODUCTION
// At index 10 : <file>, in file 'goil_syntax.ggs', line 119
, NONTERMINAL (37) // <select_goil_5F_syntax_0>
, END_PRODUCTION
// At index 12 : <file_without_include>, in file 'goil_syntax.ggs', line 135
, NONTERMINAL (38) // <select_goil_5F_syntax_1>
, END_PRODUCTION
// At index 14 : <sign>, in file 'goil_syntax.ggs', line 146
, NONTERMINAL (39) // <select_goil_5F_syntax_2>
, END_PRODUCTION
// At index 16 : <description>, in file 'goil_syntax.ggs', line 159
, NONTERMINAL (40) // <select_goil_5F_syntax_3>
, END_PRODUCTION
// At index 18 : <OIL_version>, in file 'goil_syntax.ggs', line 183
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_OIL_5F_VERSION) // $OIL_VERSION$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (5) // <description>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, END_PRODUCTION
// At index 24 : <application_definition>, in file 'goil_syntax.ggs', line 190
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_CPU) // $CPU$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (8) // <object_definition_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, NONTERMINAL (5) // <description>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, END_PRODUCTION
// At index 32 : <object_definition_list>, in file 'goil_syntax.ggs', line 204
, NONTERMINAL (42) // <select_goil_5F_syntax_5>
, END_PRODUCTION
// At index 34 : <boolean>, in file 'goil_syntax.ggs', line 254
, NONTERMINAL (43) // <select_goil_5F_syntax_6>
, END_PRODUCTION
// At index 36 : <oil_declaration_list>, in file 'goil_syntax.ggs', line 264
, NONTERMINAL (44) // <select_goil_5F_syntax_7>
, END_PRODUCTION
// At index 38 : <oil_declaration>, in file 'goil_syntax.ggs', line 276
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (45) // <select_goil_5F_syntax_8>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, END_PRODUCTION
// At index 42 : <include_file_level>, in file 'goil_syntax.ggs', line 483
, NONTERMINAL (50) // <select_goil_5F_syntax_13>
, NONTERMINAL (51) // <select_goil_5F_syntax_14>
, END_PRODUCTION
// At index 45 : <include_cpu_level>, in file 'goil_syntax.ggs', line 507
, NONTERMINAL (52) // <select_goil_5F_syntax_15>
, NONTERMINAL (53) // <select_goil_5F_syntax_16>
, END_PRODUCTION
// At index 48 : <include_object_level>, in file 'goil_syntax.ggs', line 531
, NONTERMINAL (54) // <select_goil_5F_syntax_17>
, NONTERMINAL (55) // <select_goil_5F_syntax_18>
, END_PRODUCTION
// At index 51 : <implementation_object_list>, in file 'implementation_parser.ggs', line 44
, NONTERMINAL (56) // <select_implementation_5F_parser_0>
, END_PRODUCTION
// At index 53 : <include_implementation_level>, in file 'implementation_parser.ggs', line 53
, NONTERMINAL (57) // <select_implementation_5F_parser_1>
, NONTERMINAL (58) // <select_implementation_5F_parser_2>
, END_PRODUCTION
// At index 56 : <include_type_level>, in file 'implementation_parser.ggs', line 74
, NONTERMINAL (59) // <select_implementation_5F_parser_3>
, NONTERMINAL (60) // <select_implementation_5F_parser_4>
, END_PRODUCTION
// At index 59 : <implementation_objects>, in file 'implementation_parser.ggs', line 95
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (61) // <select_implementation_5F_parser_5>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (19) // <implementation_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 65 : <implementation_list>, in file 'implementation_parser.ggs', line 132
, NONTERMINAL (62) // <select_implementation_5F_parser_6>
, END_PRODUCTION
// At index 67 : <implementation_type>, in file 'implementation_parser.ggs', line 210
, NONTERMINAL (63) // <select_implementation_5F_parser_7>
, END_PRODUCTION
// At index 69 : <struct_options>, in file 'implementation_parser.ggs', line 238
, NONTERMINAL (64) // <select_implementation_5F_parser_8>
, NONTERMINAL (35) // <identifier_or_attribute>
, NONTERMINAL (34) // <multiple>
, NONTERMINAL (5) // <description>
, END_PRODUCTION
// At index 74 : <objref_option>, in file 'implementation_parser.ggs', line 255
, NONTERMINAL (35) // <identifier_or_attribute>
, NONTERMINAL (34) // <multiple>
, NONTERMINAL (5) // <description>
, END_PRODUCTION
// At index 78 : <string_options>, in file 'implementation_parser.ggs', line 273
, NONTERMINAL (29) // <with_auto>
, NONTERMINAL (35) // <identifier_or_attribute>
, NONTERMINAL (34) // <multiple>
, NONTERMINAL (65) // <select_implementation_5F_parser_9>
, END_PRODUCTION
// At index 83 : <boolean_options>, in file 'implementation_parser.ggs', line 310
, NONTERMINAL (29) // <with_auto>
, NONTERMINAL (67) // <select_implementation_5F_parser_11>
, NONTERMINAL (35) // <identifier_or_attribute>
, NONTERMINAL (34) // <multiple>
, NONTERMINAL (70) // <select_implementation_5F_parser_14>
, END_PRODUCTION
// At index 89 : <enum_item>, in file 'implementation_parser.ggs', line 355
, NONTERMINAL (36) // <identifier_or_enum_value>
, NONTERMINAL (71) // <select_implementation_5F_parser_15>
, END_PRODUCTION
// At index 92 : <enum_options>, in file 'implementation_parser.ggs', line 368
, NONTERMINAL (29) // <with_auto>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) // $[$
, NONTERMINAL (25) // <enum_item>
, NONTERMINAL (72) // <select_implementation_5F_parser_16>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) // $]$
, NONTERMINAL (35) // <identifier_or_attribute>
, NONTERMINAL (34) // <multiple>
, NONTERMINAL (73) // <select_implementation_5F_parser_17>
, END_PRODUCTION
// At index 101 : <number_options>, in file 'implementation_parser.ggs', line 415
, NONTERMINAL (29) // <with_auto>
, NONTERMINAL (33) // <range>
, NONTERMINAL (35) // <identifier_or_attribute>
, NONTERMINAL (34) // <multiple>
, NONTERMINAL (75) // <select_implementation_5F_parser_19>
, END_PRODUCTION
// At index 107 : <type_options>, in file 'implementation_parser.ggs', line 454
, NONTERMINAL (29) // <with_auto>
, NONTERMINAL (35) // <identifier_or_attribute>
, NONTERMINAL (34) // <multiple>
, NONTERMINAL (77) // <select_implementation_5F_parser_21>
, END_PRODUCTION
// At index 112 : <with_auto>, in file 'implementation_parser.ggs', line 493
, NONTERMINAL (79) // <select_implementation_5F_parser_23>
, END_PRODUCTION
// At index 114 : <int_or_float>, in file 'implementation_parser.ggs', line 502
, NONTERMINAL (4) // <sign>
, NONTERMINAL (80) // <select_implementation_5F_parser_24>
, END_PRODUCTION
// At index 117 : <set_followup>, in file 'implementation_parser.ggs', line 520
, NONTERMINAL (81) // <select_implementation_5F_parser_25>
, END_PRODUCTION
// At index 119 : <range_content>, in file 'implementation_parser.ggs', line 532
, NONTERMINAL (4) // <sign>
, NONTERMINAL (82) // <select_implementation_5F_parser_26>
, END_PRODUCTION
// At index 122 : <range>, in file 'implementation_parser.ggs', line 572
, NONTERMINAL (85) // <select_implementation_5F_parser_29>
, END_PRODUCTION
// At index 124 : <multiple>, in file 'implementation_parser.ggs', line 582
, NONTERMINAL (86) // <select_implementation_5F_parser_30>
, END_PRODUCTION
// At index 126 : <identifier_or_attribute>, in file 'implementation_parser.ggs', line 592
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, END_PRODUCTION
// At index 128 : <identifier_or_enum_value>, in file 'implementation_parser.ggs', line 597
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, END_PRODUCTION
//---- Added productions from 'select' and 'repeat' instructions
// At index 130 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 128
, END_PRODUCTION
// At index 131 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 128
, NONTERMINAL (12) // <include_file_level>
, NONTERMINAL (37) // <select_goil_5F_syntax_0>
, END_PRODUCTION
// At index 134 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 128
, NONTERMINAL (0) // <implementation_definition>
, NONTERMINAL (37) // <select_goil_5F_syntax_0>
, END_PRODUCTION
// At index 137 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 128
, NONTERMINAL (7) // <application_definition>
, NONTERMINAL (37) // <select_goil_5F_syntax_0>
, END_PRODUCTION
// At index 140 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 140
, END_PRODUCTION
// At index 141 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 140
, NONTERMINAL (0) // <implementation_definition>
, NONTERMINAL (38) // <select_goil_5F_syntax_1>
, END_PRODUCTION
// At index 144 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 140
, NONTERMINAL (7) // <application_definition>
, NONTERMINAL (38) // <select_goil_5F_syntax_1>
, END_PRODUCTION
// At index 147 : <select_goil_5F_syntax_2>, in file 'goil_syntax.ggs', line 147
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2D_) // $-$
, END_PRODUCTION
// At index 149 : <select_goil_5F_syntax_2>, in file 'goil_syntax.ggs', line 147
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2B_) // $+$
, END_PRODUCTION
// At index 151 : <select_goil_5F_syntax_2>, in file 'goil_syntax.ggs', line 147
, END_PRODUCTION
// At index 152 : <select_goil_5F_syntax_3>, in file 'goil_syntax.ggs', line 160
, END_PRODUCTION
// At index 153 : <select_goil_5F_syntax_3>, in file 'goil_syntax.ggs', line 160
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3A_) // $:$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (41) // <select_goil_5F_syntax_4>
, END_PRODUCTION
// At index 157 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 167
, END_PRODUCTION
// At index 158 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 167
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (41) // <select_goil_5F_syntax_4>
, END_PRODUCTION
// At index 161 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 210
, END_PRODUCTION
// At index 162 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 210
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (10) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, NONTERMINAL (5) // <description>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, NONTERMINAL (42) // <select_goil_5F_syntax_5>
, END_PRODUCTION
// At index 171 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 210
, NONTERMINAL (13) // <include_cpu_level>
, NONTERMINAL (42) // <select_goil_5F_syntax_5>
, END_PRODUCTION
// At index 174 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 255
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_TRUE) // $TRUE$
, END_PRODUCTION
// At index 176 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 255
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_FALSE) // $FALSE$
, END_PRODUCTION
// At index 178 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 268
, END_PRODUCTION
// At index 179 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 268
, NONTERMINAL (11) // <oil_declaration>
, NONTERMINAL (44) // <select_goil_5F_syntax_7>
, END_PRODUCTION
// At index 182 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 268
, NONTERMINAL (14) // <include_object_level>
, NONTERMINAL (44) // <select_goil_5F_syntax_7>
, END_PRODUCTION
// At index 185 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 293
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (46) // <select_goil_5F_syntax_9>
, END_PRODUCTION
// At index 188 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 293
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (10) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, NONTERMINAL (5) // <description>
, END_PRODUCTION
// At index 194 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 295
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (47) // <select_goil_5F_syntax_10>
, NONTERMINAL (5) // <description>
, END_PRODUCTION
// At index 198 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 295
, NONTERMINAL (4) // <sign>
, NONTERMINAL (48) // <select_goil_5F_syntax_11>
, END_PRODUCTION
// At index 201 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 295
, NONTERMINAL (9) // <boolean>
, NONTERMINAL (49) // <select_goil_5F_syntax_12>
, NONTERMINAL (5) // <description>
, END_PRODUCTION
// At index 205 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 295
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (5) // <description>
, END_PRODUCTION
// At index 208 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 295
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) // $AUTO$
, NONTERMINAL (5) // <description>
, END_PRODUCTION
// At index 211 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 316
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (10) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 215 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 316
, END_PRODUCTION
// At index 216 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 333
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) // $uint_number$
, NONTERMINAL (5) // <description>
, END_PRODUCTION
// At index 219 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 333
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_float_5F_number) // $float_number$
, NONTERMINAL (5) // <description>
, END_PRODUCTION
// At index 222 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 376
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (10) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 226 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 376
, END_PRODUCTION
// At index 227 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 490
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) // $include$
, END_PRODUCTION
// At index 229 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 490
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) // $includeifexists$
, END_PRODUCTION
// At index 231 : <select_goil_5F_syntax_14>, in file 'goil_syntax.ggs', line 496
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) // $g_string$
, END_PRODUCTION
// At index 233 : <select_goil_5F_syntax_14>, in file 'goil_syntax.ggs', line 496
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, END_PRODUCTION
// At index 235 : <select_goil_5F_syntax_15>, in file 'goil_syntax.ggs', line 514
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) // $include$
, END_PRODUCTION
// At index 237 : <select_goil_5F_syntax_15>, in file 'goil_syntax.ggs', line 514
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) // $includeifexists$
, END_PRODUCTION
// At index 239 : <select_goil_5F_syntax_16>, in file 'goil_syntax.ggs', line 520
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) // $g_string$
, END_PRODUCTION
// At index 241 : <select_goil_5F_syntax_16>, in file 'goil_syntax.ggs', line 520
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, END_PRODUCTION
// At index 243 : <select_goil_5F_syntax_17>, in file 'goil_syntax.ggs', line 536
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) // $include$
, END_PRODUCTION
// At index 245 : <select_goil_5F_syntax_17>, in file 'goil_syntax.ggs', line 536
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) // $includeifexists$
, END_PRODUCTION
// At index 247 : <select_goil_5F_syntax_18>, in file 'goil_syntax.ggs', line 542
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) // $g_string$
, END_PRODUCTION
// At index 249 : <select_goil_5F_syntax_18>, in file 'goil_syntax.ggs', line 542
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, END_PRODUCTION
// At index 251 : <select_implementation_5F_parser_0>, in file 'implementation_parser.ggs', line 47
, END_PRODUCTION
// At index 252 : <select_implementation_5F_parser_0>, in file 'implementation_parser.ggs', line 47
, NONTERMINAL (18) // <implementation_objects>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, NONTERMINAL (56) // <select_implementation_5F_parser_0>
, END_PRODUCTION
// At index 256 : <select_implementation_5F_parser_0>, in file 'implementation_parser.ggs', line 47
, NONTERMINAL (16) // <include_implementation_level>
, NONTERMINAL (56) // <select_implementation_5F_parser_0>
, END_PRODUCTION
// At index 259 : <select_implementation_5F_parser_1>, in file 'implementation_parser.ggs', line 57
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) // $include$
, END_PRODUCTION
// At index 261 : <select_implementation_5F_parser_1>, in file 'implementation_parser.ggs', line 57
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) // $includeifexists$
, END_PRODUCTION
// At index 263 : <select_implementation_5F_parser_2>, in file 'implementation_parser.ggs', line 63
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) // $g_string$
, END_PRODUCTION
// At index 265 : <select_implementation_5F_parser_2>, in file 'implementation_parser.ggs', line 63
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, END_PRODUCTION
// At index 267 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 78
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) // $include$
, END_PRODUCTION
// At index 269 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 78
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) // $includeifexists$
, END_PRODUCTION
// At index 271 : <select_implementation_5F_parser_4>, in file 'implementation_parser.ggs', line 84
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) // $g_string$
, END_PRODUCTION
// At index 273 : <select_implementation_5F_parser_4>, in file 'implementation_parser.ggs', line 84
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, END_PRODUCTION
// At index 275 : <select_implementation_5F_parser_5>, in file 'implementation_parser.ggs', line 102
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) // $[$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) // $]$
, END_PRODUCTION
// At index 278 : <select_implementation_5F_parser_5>, in file 'implementation_parser.ggs', line 102
, END_PRODUCTION
// At index 279 : <select_implementation_5F_parser_6>, in file 'implementation_parser.ggs', line 135
, END_PRODUCTION
// At index 280 : <select_implementation_5F_parser_6>, in file 'implementation_parser.ggs', line 135
, NONTERMINAL (20) // <implementation_type>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, NONTERMINAL (62) // <select_implementation_5F_parser_6>
, END_PRODUCTION
// At index 284 : <select_implementation_5F_parser_6>, in file 'implementation_parser.ggs', line 135
, NONTERMINAL (17) // <include_type_level>
, NONTERMINAL (62) // <select_implementation_5F_parser_6>
, END_PRODUCTION
// At index 287 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_UINT_33__32_) // $UINT32$
, NONTERMINAL (27) // <number_options>
, END_PRODUCTION
// At index 290 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_INT_33__32_) // $INT32$
, NONTERMINAL (27) // <number_options>
, END_PRODUCTION
// At index 293 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_UINT_36__34_) // $UINT64$
, NONTERMINAL (27) // <number_options>
, END_PRODUCTION
// At index 296 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_INT_36__34_) // $INT64$
, NONTERMINAL (27) // <number_options>
, END_PRODUCTION
// At index 299 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_FLOAT) // $FLOAT$
, NONTERMINAL (27) // <number_options>
, END_PRODUCTION
// At index 302 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_ENUM) // $ENUM$
, NONTERMINAL (26) // <enum_options>
, END_PRODUCTION
// At index 305 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_BOOLEAN) // $BOOLEAN$
, NONTERMINAL (24) // <boolean_options>
, END_PRODUCTION
// At index 308 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_STRING) // $STRING$
, NONTERMINAL (23) // <string_options>
, END_PRODUCTION
// At index 311 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_IDENTIFIER) // $IDENTIFIER$
, NONTERMINAL (28) // <type_options>
, END_PRODUCTION
// At index 314 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_STRUCT) // $STRUCT$
, NONTERMINAL (21) // <struct_options>
, END_PRODUCTION
// At index 317 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (22) // <objref_option>
, END_PRODUCTION
// At index 320 : <select_implementation_5F_parser_8>, in file 'implementation_parser.ggs', line 242
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (19) // <implementation_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 324 : <select_implementation_5F_parser_8>, in file 'implementation_parser.ggs', line 242
, END_PRODUCTION
// At index 325 : <select_implementation_5F_parser_9>, in file 'implementation_parser.ggs', line 283
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (66) // <select_implementation_5F_parser_10>
, END_PRODUCTION
// At index 328 : <select_implementation_5F_parser_9>, in file 'implementation_parser.ggs', line 283
, NONTERMINAL (5) // <description>
, END_PRODUCTION
// At index 330 : <select_implementation_5F_parser_10>, in file 'implementation_parser.ggs', line 285
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (5) // <description>
, END_PRODUCTION
// At index 333 : <select_implementation_5F_parser_10>, in file 'implementation_parser.ggs', line 285
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) // $AUTO$
, NONTERMINAL (5) // <description>
, END_PRODUCTION
// At index 336 : <select_implementation_5F_parser_10>, in file 'implementation_parser.ggs', line 285
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT) // $NO_DEFAULT$
, NONTERMINAL (5) // <description>
, END_PRODUCTION
// At index 339 : <select_implementation_5F_parser_11>, in file 'implementation_parser.ggs', line 317
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) // $[$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_TRUE) // $TRUE$
, NONTERMINAL (68) // <select_implementation_5F_parser_12>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2C_) // $,$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_FALSE) // $FALSE$
, NONTERMINAL (69) // <select_implementation_5F_parser_13>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) // $]$
, END_PRODUCTION
// At index 347 : <select_implementation_5F_parser_11>, in file 'implementation_parser.ggs', line 317
, END_PRODUCTION
// At index 348 : <select_implementation_5F_parser_12>, in file 'implementation_parser.ggs', line 320
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (19) // <implementation_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 352 : <select_implementation_5F_parser_12>, in file 'implementation_parser.ggs', line 320
, END_PRODUCTION
// At index 353 : <select_implementation_5F_parser_13>, in file 'implementation_parser.ggs', line 329
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (19) // <implementation_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 357 : <select_implementation_5F_parser_13>, in file 'implementation_parser.ggs', line 329
, END_PRODUCTION
// At index 358 : <select_implementation_5F_parser_14>, in file 'implementation_parser.ggs', line 343
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (9) // <boolean>
, NONTERMINAL (5) // <description>
, END_PRODUCTION
// At index 362 : <select_implementation_5F_parser_14>, in file 'implementation_parser.ggs', line 343
, NONTERMINAL (5) // <description>
, END_PRODUCTION
// At index 364 : <select_implementation_5F_parser_15>, in file 'implementation_parser.ggs', line 360
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (19) // <implementation_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 368 : <select_implementation_5F_parser_15>, in file 'implementation_parser.ggs', line 360
, END_PRODUCTION
// At index 369 : <select_implementation_5F_parser_16>, in file 'implementation_parser.ggs', line 376
, END_PRODUCTION
// At index 370 : <select_implementation_5F_parser_16>, in file 'implementation_parser.ggs', line 376
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2C_) // $,$
, NONTERMINAL (25) // <enum_item>
, NONTERMINAL (72) // <select_implementation_5F_parser_16>
, END_PRODUCTION
// At index 374 : <select_implementation_5F_parser_17>, in file 'implementation_parser.ggs', line 386
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (74) // <select_implementation_5F_parser_18>
, END_PRODUCTION
// At index 377 : <select_implementation_5F_parser_17>, in file 'implementation_parser.ggs', line 386
, NONTERMINAL (5) // <description>
, END_PRODUCTION
// At index 379 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 388
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (5) // <description>
, END_PRODUCTION
// At index 382 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 388
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) // $AUTO$
, NONTERMINAL (5) // <description>
, END_PRODUCTION
// At index 385 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 388
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT) // $NO_DEFAULT$
, NONTERMINAL (5) // <description>
, END_PRODUCTION
// At index 388 : <select_implementation_5F_parser_19>, in file 'implementation_parser.ggs', line 428
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (76) // <select_implementation_5F_parser_20>
, END_PRODUCTION
// At index 391 : <select_implementation_5F_parser_19>, in file 'implementation_parser.ggs', line 428
, NONTERMINAL (5) // <description>
, END_PRODUCTION
// At index 393 : <select_implementation_5F_parser_20>, in file 'implementation_parser.ggs', line 430
, NONTERMINAL (30) // <int_or_float>
, END_PRODUCTION
// At index 395 : <select_implementation_5F_parser_20>, in file 'implementation_parser.ggs', line 430
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT) // $NO_DEFAULT$
, NONTERMINAL (5) // <description>
, END_PRODUCTION
// At index 398 : <select_implementation_5F_parser_20>, in file 'implementation_parser.ggs', line 430
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) // $AUTO$
, NONTERMINAL (5) // <description>
, END_PRODUCTION
// At index 401 : <select_implementation_5F_parser_21>, in file 'implementation_parser.ggs', line 465
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (78) // <select_implementation_5F_parser_22>
, END_PRODUCTION
// At index 404 : <select_implementation_5F_parser_21>, in file 'implementation_parser.ggs', line 465
, NONTERMINAL (5) // <description>
, END_PRODUCTION
// At index 406 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 467
, NONTERMINAL (35) // <identifier_or_attribute>
, NONTERMINAL (5) // <description>
, END_PRODUCTION
// At index 409 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 467
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT) // $NO_DEFAULT$
, NONTERMINAL (5) // <description>
, END_PRODUCTION
// At index 412 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 467
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) // $AUTO$
, NONTERMINAL (5) // <description>
, END_PRODUCTION
// At index 415 : <select_implementation_5F_parser_23>, in file 'implementation_parser.ggs', line 495
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_WITH_5F_AUTO) // $WITH_AUTO$
, END_PRODUCTION
// At index 417 : <select_implementation_5F_parser_23>, in file 'implementation_parser.ggs', line 495
, END_PRODUCTION
// At index 418 : <select_implementation_5F_parser_24>, in file 'implementation_parser.ggs', line 507
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) // $uint_number$
, NONTERMINAL (5) // <description>
, END_PRODUCTION
// At index 421 : <select_implementation_5F_parser_24>, in file 'implementation_parser.ggs', line 507
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_float_5F_number) // $float_number$
, NONTERMINAL (5) // <description>
, END_PRODUCTION
// At index 424 : <select_implementation_5F_parser_25>, in file 'implementation_parser.ggs', line 523
, END_PRODUCTION
// At index 425 : <select_implementation_5F_parser_25>, in file 'implementation_parser.ggs', line 523
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2C_) // $,$
, NONTERMINAL (30) // <int_or_float>
, NONTERMINAL (81) // <select_implementation_5F_parser_25>
, END_PRODUCTION
// At index 429 : <select_implementation_5F_parser_26>, in file 'implementation_parser.ggs', line 539
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_set_5F_start_5F_uint_5F_number) // $set_start_uint_number$
, NONTERMINAL (30) // <int_or_float>
, END_PRODUCTION
// At index 432 : <select_implementation_5F_parser_26>, in file 'implementation_parser.ggs', line 539
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) // $uint_number$
, NONTERMINAL (83) // <select_implementation_5F_parser_27>
, END_PRODUCTION
// At index 435 : <select_implementation_5F_parser_26>, in file 'implementation_parser.ggs', line 539
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_float_5F_number) // $float_number$
, NONTERMINAL (84) // <select_implementation_5F_parser_28>
, END_PRODUCTION
// At index 438 : <select_implementation_5F_parser_27>, in file 'implementation_parser.ggs', line 549
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2E__2E_) // $..$
, NONTERMINAL (30) // <int_or_float>
, END_PRODUCTION
// At index 441 : <select_implementation_5F_parser_27>, in file 'implementation_parser.ggs', line 549
, NONTERMINAL (31) // <set_followup>
, END_PRODUCTION
// At index 443 : <select_implementation_5F_parser_28>, in file 'implementation_parser.ggs', line 561
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2E__2E_) // $..$
, NONTERMINAL (30) // <int_or_float>
, END_PRODUCTION
// At index 446 : <select_implementation_5F_parser_28>, in file 'implementation_parser.ggs', line 561
, NONTERMINAL (31) // <set_followup>
, END_PRODUCTION
// At index 448 : <select_implementation_5F_parser_29>, in file 'implementation_parser.ggs', line 575
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) // $[$
, NONTERMINAL (32) // <range_content>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) // $]$
, END_PRODUCTION
// At index 452 : <select_implementation_5F_parser_29>, in file 'implementation_parser.ggs', line 575
, END_PRODUCTION
// At index 453 : <select_implementation_5F_parser_30>, in file 'implementation_parser.ggs', line 584
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) // $[$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) // $]$
, END_PRODUCTION
// At index 456 : <select_implementation_5F_parser_30>, in file 'implementation_parser.ggs', line 584
, END_PRODUCTION
// At index 457 : <>, in file '.ggs', line 0
, NONTERMINAL (19) // <implementation_list>
, END_PRODUCTION
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                          P R O D U C T I O N    N A M E S                                            
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const cProductionNameDescriptor gProductionNames_goil_type_level_include [163] = {
 {"<implementation_definition>", "implementation_parser", 0}, // at index 0
 {"<start>", "goil_syntax", 7}, // at index 1
 {"<file>", "goil_syntax", 10}, // at index 2
 {"<file_without_include>", "goil_syntax", 12}, // at index 3
 {"<sign>", "goil_syntax", 14}, // at index 4
 {"<description>", "goil_syntax", 16}, // at index 5
 {"<OIL_version>", "goil_syntax", 18}, // at index 6
 {"<application_definition>", "goil_syntax", 24}, // at index 7
 {"<object_definition_list>", "goil_syntax", 32}, // at index 8
 {"<boolean>", "goil_syntax", 34}, // at index 9
 {"<oil_declaration_list>", "goil_syntax", 36}, // at index 10
 {"<oil_declaration>", "goil_syntax", 38}, // at index 11
 {"<include_file_level>", "goil_syntax", 42}, // at index 12
 {"<include_cpu_level>", "goil_syntax", 45}, // at index 13
 {"<include_object_level>", "goil_syntax", 48}, // at index 14
 {"<implementation_object_list>", "implementation_parser", 51}, // at index 15
 {"<include_implementation_level>", "implementation_parser", 53}, // at index 16
 {"<include_type_level>", "implementation_parser", 56}, // at index 17
 {"<implementation_objects>", "implementation_parser", 59}, // at index 18
 {"<implementation_list>", "implementation_parser", 65}, // at index 19
 {"<implementation_type>", "implementation_parser", 67}, // at index 20
 {"<struct_options>", "implementation_parser", 69}, // at index 21
 {"<objref_option>", "implementation_parser", 74}, // at index 22
 {"<string_options>", "implementation_parser", 78}, // at index 23
 {"<boolean_options>", "implementation_parser", 83}, // at index 24
 {"<enum_item>", "implementation_parser", 89}, // at index 25
 {"<enum_options>", "implementation_parser", 92}, // at index 26
 {"<number_options>", "implementation_parser", 101}, // at index 27
 {"<type_options>", "implementation_parser", 107}, // at index 28
 {"<with_auto>", "implementation_parser", 112}, // at index 29
 {"<int_or_float>", "implementation_parser", 114}, // at index 30
 {"<set_followup>", "implementation_parser", 117}, // at index 31
 {"<range_content>", "implementation_parser", 119}, // at index 32
 {"<range>", "implementation_parser", 122}, // at index 33
 {"<multiple>", "implementation_parser", 124}, // at index 34
 {"<identifier_or_attribute>", "implementation_parser", 126}, // at index 35
 {"<identifier_or_enum_value>", "implementation_parser", 128}, // at index 36
 {"<select_goil_5F_syntax_0>", "goil_syntax", 130}, // at index 37
 {"<select_goil_5F_syntax_0>", "goil_syntax", 131}, // at index 38
 {"<select_goil_5F_syntax_0>", "goil_syntax", 134}, // at index 39
 {"<select_goil_5F_syntax_0>", "goil_syntax", 137}, // at index 40
 {"<select_goil_5F_syntax_1>", "goil_syntax", 140}, // at index 41
 {"<select_goil_5F_syntax_1>", "goil_syntax", 141}, // at index 42
 {"<select_goil_5F_syntax_1>", "goil_syntax", 144}, // at index 43
 {"<select_goil_5F_syntax_2>", "goil_syntax", 147}, // at index 44
 {"<select_goil_5F_syntax_2>", "goil_syntax", 149}, // at index 45
 {"<select_goil_5F_syntax_2>", "goil_syntax", 151}, // at index 46
 {"<select_goil_5F_syntax_3>", "goil_syntax", 152}, // at index 47
 {"<select_goil_5F_syntax_3>", "goil_syntax", 153}, // at index 48
 {"<select_goil_5F_syntax_4>", "goil_syntax", 157}, // at index 49
 {"<select_goil_5F_syntax_4>", "goil_syntax", 158}, // at index 50
 {"<select_goil_5F_syntax_5>", "goil_syntax", 161}, // at index 51
 {"<select_goil_5F_syntax_5>", "goil_syntax", 162}, // at index 52
 {"<select_goil_5F_syntax_5>", "goil_syntax", 171}, // at index 53
 {"<select_goil_5F_syntax_6>", "goil_syntax", 174}, // at index 54
 {"<select_goil_5F_syntax_6>", "goil_syntax", 176}, // at index 55
 {"<select_goil_5F_syntax_7>", "goil_syntax", 178}, // at index 56
 {"<select_goil_5F_syntax_7>", "goil_syntax", 179}, // at index 57
 {"<select_goil_5F_syntax_7>", "goil_syntax", 182}, // at index 58
 {"<select_goil_5F_syntax_8>", "goil_syntax", 185}, // at index 59
 {"<select_goil_5F_syntax_8>", "goil_syntax", 188}, // at index 60
 {"<select_goil_5F_syntax_9>", "goil_syntax", 194}, // at index 61
 {"<select_goil_5F_syntax_9>", "goil_syntax", 198}, // at index 62
 {"<select_goil_5F_syntax_9>", "goil_syntax", 201}, // at index 63
 {"<select_goil_5F_syntax_9>", "goil_syntax", 205}, // at index 64
 {"<select_goil_5F_syntax_9>", "goil_syntax", 208}, // at index 65
 {"<select_goil_5F_syntax_10>", "goil_syntax", 211}, // at index 66
 {"<select_goil_5F_syntax_10>", "goil_syntax", 215}, // at index 67
 {"<select_goil_5F_syntax_11>", "goil_syntax", 216}, // at index 68
 {"<select_goil_5F_syntax_11>", "goil_syntax", 219}, // at index 69
 {"<select_goil_5F_syntax_12>", "goil_syntax", 222}, // at index 70
 {"<select_goil_5F_syntax_12>", "goil_syntax", 226}, // at index 71
 {"<select_goil_5F_syntax_13>", "goil_syntax", 227}, // at index 72
 {"<select_goil_5F_syntax_13>", "goil_syntax", 229}, // at index 73
 {"<select_goil_5F_syntax_14>", "goil_syntax", 231}, // at index 74
 {"<select_goil_5F_syntax_14>", "goil_syntax", 233}, // at index 75
 {"<select_goil_5F_syntax_15>", "goil_syntax", 235}, // at index 76
 {"<select_goil_5F_syntax_15>", "goil_syntax", 237}, // at index 77
 {"<select_goil_5F_syntax_16>", "goil_syntax", 239}, // at index 78
 {"<select_goil_5F_syntax_16>", "goil_syntax", 241}, // at index 79
 {"<select_goil_5F_syntax_17>", "goil_syntax", 243}, // at index 80
 {"<select_goil_5F_syntax_17>", "goil_syntax", 245}, // at index 81
 {"<select_goil_5F_syntax_18>", "goil_syntax", 247}, // at index 82
 {"<select_goil_5F_syntax_18>", "goil_syntax", 249}, // at index 83
 {"<select_implementation_5F_parser_0>", "implementation_parser", 251}, // at index 84
 {"<select_implementation_5F_parser_0>", "implementation_parser", 252}, // at index 85
 {"<select_implementation_5F_parser_0>", "implementation_parser", 256}, // at index 86
 {"<select_implementation_5F_parser_1>", "implementation_parser", 259}, // at index 87
 {"<select_implementation_5F_parser_1>", "implementation_parser", 261}, // at index 88
 {"<select_implementation_5F_parser_2>", "implementation_parser", 263}, // at index 89
 {"<select_implementation_5F_parser_2>", "implementation_parser", 265}, // at index 90
 {"<select_implementation_5F_parser_3>", "implementation_parser", 267}, // at index 91
 {"<select_implementation_5F_parser_3>", "implementation_parser", 269}, // at index 92
 {"<select_implementation_5F_parser_4>", "implementation_parser", 271}, // at index 93
 {"<select_implementation_5F_parser_4>", "implementation_parser", 273}, // at index 94
 {"<select_implementation_5F_parser_5>", "implementation_parser", 275}, // at index 95
 {"<select_implementation_5F_parser_5>", "implementation_parser", 278}, // at index 96
 {"<select_implementation_5F_parser_6>", "implementation_parser", 279}, // at index 97
 {"<select_implementation_5F_parser_6>", "implementation_parser", 280}, // at index 98
 {"<select_implementation_5F_parser_6>", "implementation_parser", 284}, // at index 99
 {"<select_implementation_5F_parser_7>", "implementation_parser", 287}, // at index 100
 {"<select_implementation_5F_parser_7>", "implementation_parser", 290}, // at index 101
 {"<select_implementation_5F_parser_7>", "implementation_parser", 293}, // at index 102
 {"<select_implementation_5F_parser_7>", "implementation_parser", 296}, // at index 103
 {"<select_implementation_5F_parser_7>", "implementation_parser", 299}, // at index 104
 {"<select_implementation_5F_parser_7>", "implementation_parser", 302}, // at index 105
 {"<select_implementation_5F_parser_7>", "implementation_parser", 305}, // at index 106
 {"<select_implementation_5F_parser_7>", "implementation_parser", 308}, // at index 107
 {"<select_implementation_5F_parser_7>", "implementation_parser", 311}, // at index 108
 {"<select_implementation_5F_parser_7>", "implementation_parser", 314}, // at index 109
 {"<select_implementation_5F_parser_7>", "implementation_parser", 317}, // at index 110
 {"<select_implementation_5F_parser_8>", "implementation_parser", 320}, // at index 111
 {"<select_implementation_5F_parser_8>", "implementation_parser", 324}, // at index 112
 {"<select_implementation_5F_parser_9>", "implementation_parser", 325}, // at index 113
 {"<select_implementation_5F_parser_9>", "implementation_parser", 328}, // at index 114
 {"<select_implementation_5F_parser_10>", "implementation_parser", 330}, // at index 115
 {"<select_implementation_5F_parser_10>", "implementation_parser", 333}, // at index 116
 {"<select_implementation_5F_parser_10>", "implementation_parser", 336}, // at index 117
 {"<select_implementation_5F_parser_11>", "implementation_parser", 339}, // at index 118
 {"<select_implementation_5F_parser_11>", "implementation_parser", 347}, // at index 119
 {"<select_implementation_5F_parser_12>", "implementation_parser", 348}, // at index 120
 {"<select_implementation_5F_parser_12>", "implementation_parser", 352}, // at index 121
 {"<select_implementation_5F_parser_13>", "implementation_parser", 353}, // at index 122
 {"<select_implementation_5F_parser_13>", "implementation_parser", 357}, // at index 123
 {"<select_implementation_5F_parser_14>", "implementation_parser", 358}, // at index 124
 {"<select_implementation_5F_parser_14>", "implementation_parser", 362}, // at index 125
 {"<select_implementation_5F_parser_15>", "implementation_parser", 364}, // at index 126
 {"<select_implementation_5F_parser_15>", "implementation_parser", 368}, // at index 127
 {"<select_implementation_5F_parser_16>", "implementation_parser", 369}, // at index 128
 {"<select_implementation_5F_parser_16>", "implementation_parser", 370}, // at index 129
 {"<select_implementation_5F_parser_17>", "implementation_parser", 374}, // at index 130
 {"<select_implementation_5F_parser_17>", "implementation_parser", 377}, // at index 131
 {"<select_implementation_5F_parser_18>", "implementation_parser", 379}, // at index 132
 {"<select_implementation_5F_parser_18>", "implementation_parser", 382}, // at index 133
 {"<select_implementation_5F_parser_18>", "implementation_parser", 385}, // at index 134
 {"<select_implementation_5F_parser_19>", "implementation_parser", 388}, // at index 135
 {"<select_implementation_5F_parser_19>", "implementation_parser", 391}, // at index 136
 {"<select_implementation_5F_parser_20>", "implementation_parser", 393}, // at index 137
 {"<select_implementation_5F_parser_20>", "implementation_parser", 395}, // at index 138
 {"<select_implementation_5F_parser_20>", "implementation_parser", 398}, // at index 139
 {"<select_implementation_5F_parser_21>", "implementation_parser", 401}, // at index 140
 {"<select_implementation_5F_parser_21>", "implementation_parser", 404}, // at index 141
 {"<select_implementation_5F_parser_22>", "implementation_parser", 406}, // at index 142
 {"<select_implementation_5F_parser_22>", "implementation_parser", 409}, // at index 143
 {"<select_implementation_5F_parser_22>", "implementation_parser", 412}, // at index 144
 {"<select_implementation_5F_parser_23>", "implementation_parser", 415}, // at index 145
 {"<select_implementation_5F_parser_23>", "implementation_parser", 417}, // at index 146
 {"<select_implementation_5F_parser_24>", "implementation_parser", 418}, // at index 147
 {"<select_implementation_5F_parser_24>", "implementation_parser", 421}, // at index 148
 {"<select_implementation_5F_parser_25>", "implementation_parser", 424}, // at index 149
 {"<select_implementation_5F_parser_25>", "implementation_parser", 425}, // at index 150
 {"<select_implementation_5F_parser_26>", "implementation_parser", 429}, // at index 151
 {"<select_implementation_5F_parser_26>", "implementation_parser", 432}, // at index 152
 {"<select_implementation_5F_parser_26>", "implementation_parser", 435}, // at index 153
 {"<select_implementation_5F_parser_27>", "implementation_parser", 438}, // at index 154
 {"<select_implementation_5F_parser_27>", "implementation_parser", 441}, // at index 155
 {"<select_implementation_5F_parser_28>", "implementation_parser", 443}, // at index 156
 {"<select_implementation_5F_parser_28>", "implementation_parser", 446}, // at index 157
 {"<select_implementation_5F_parser_29>", "implementation_parser", 448}, // at index 158
 {"<select_implementation_5F_parser_29>", "implementation_parser", 452}, // at index 159
 {"<select_implementation_5F_parser_30>", "implementation_parser", 453}, // at index 160
 {"<select_implementation_5F_parser_30>", "implementation_parser", 456}, // at index 161
 {"<>", "", 457} // at index 162
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                 L L ( 1 )    P R O D U C T I O N    I N D E X E S                                    
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int32_t gProductionIndexes_goil_type_level_include [163] = {
0, // index 0 : <implementation_definition>, in file 'implementation_parser.ggs', line 36
7, // index 1 : <start>, in file 'goil_syntax.ggs', line 38
10, // index 2 : <file>, in file 'goil_syntax.ggs', line 119
12, // index 3 : <file_without_include>, in file 'goil_syntax.ggs', line 135
14, // index 4 : <sign>, in file 'goil_syntax.ggs', line 146
16, // index 5 : <description>, in file 'goil_syntax.ggs', line 159
18, // index 6 : <OIL_version>, in file 'goil_syntax.ggs', line 183
24, // index 7 : <application_definition>, in file 'goil_syntax.ggs', line 190
32, // index 8 : <object_definition_list>, in file 'goil_syntax.ggs', line 204
34, // index 9 : <boolean>, in file 'goil_syntax.ggs', line 254
36, // index 10 : <oil_declaration_list>, in file 'goil_syntax.ggs', line 264
38, // index 11 : <oil_declaration>, in file 'goil_syntax.ggs', line 276
42, // index 12 : <include_file_level>, in file 'goil_syntax.ggs', line 483
45, // index 13 : <include_cpu_level>, in file 'goil_syntax.ggs', line 507
48, // index 14 : <include_object_level>, in file 'goil_syntax.ggs', line 531
51, // index 15 : <implementation_object_list>, in file 'implementation_parser.ggs', line 44
53, // index 16 : <include_implementation_level>, in file 'implementation_parser.ggs', line 53
56, // index 17 : <include_type_level>, in file 'implementation_parser.ggs', line 74
59, // index 18 : <implementation_objects>, in file 'implementation_parser.ggs', line 95
65, // index 19 : <implementation_list>, in file 'implementation_parser.ggs', line 132
67, // index 20 : <implementation_type>, in file 'implementation_parser.ggs', line 210
69, // index 21 : <struct_options>, in file 'implementation_parser.ggs', line 238
74, // index 22 : <objref_option>, in file 'implementation_parser.ggs', line 255
78, // index 23 : <string_options>, in file 'implementation_parser.ggs', line 273
83, // index 24 : <boolean_options>, in file 'implementation_parser.ggs', line 310
89, // index 25 : <enum_item>, in file 'implementation_parser.ggs', line 355
92, // index 26 : <enum_options>, in file 'implementation_parser.ggs', line 368
101, // index 27 : <number_options>, in file 'implementation_parser.ggs', line 415
107, // index 28 : <type_options>, in file 'implementation_parser.ggs', line 454
112, // index 29 : <with_auto>, in file 'implementation_parser.ggs', line 493
114, // index 30 : <int_or_float>, in file 'implementation_parser.ggs', line 502
117, // index 31 : <set_followup>, in file 'implementation_parser.ggs', line 520
119, // index 32 : <range_content>, in file 'implementation_parser.ggs', line 532
122, // index 33 : <range>, in file 'implementation_parser.ggs', line 572
124, // index 34 : <multiple>, in file 'implementation_parser.ggs', line 582
126, // index 35 : <identifier_or_attribute>, in file 'implementation_parser.ggs', line 592
128, // index 36 : <identifier_or_enum_value>, in file 'implementation_parser.ggs', line 597
130, // index 37 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 128
131, // index 38 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 128
134, // index 39 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 128
137, // index 40 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 128
140, // index 41 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 140
141, // index 42 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 140
144, // index 43 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 140
147, // index 44 : <select_goil_5F_syntax_2>, in file 'goil_syntax.ggs', line 147
149, // index 45 : <select_goil_5F_syntax_2>, in file 'goil_syntax.ggs', line 147
151, // index 46 : <select_goil_5F_syntax_2>, in file 'goil_syntax.ggs', line 147
152, // index 47 : <select_goil_5F_syntax_3>, in file 'goil_syntax.ggs', line 160
153, // index 48 : <select_goil_5F_syntax_3>, in file 'goil_syntax.ggs', line 160
157, // index 49 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 167
158, // index 50 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 167
161, // index 51 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 210
162, // index 52 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 210
171, // index 53 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 210
174, // index 54 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 255
176, // index 55 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 255
178, // index 56 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 268
179, // index 57 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 268
182, // index 58 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 268
185, // index 59 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 293
188, // index 60 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 293
194, // index 61 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 295
198, // index 62 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 295
201, // index 63 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 295
205, // index 64 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 295
208, // index 65 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 295
211, // index 66 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 316
215, // index 67 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 316
216, // index 68 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 333
219, // index 69 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 333
222, // index 70 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 376
226, // index 71 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 376
227, // index 72 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 490
229, // index 73 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 490
231, // index 74 : <select_goil_5F_syntax_14>, in file 'goil_syntax.ggs', line 496
233, // index 75 : <select_goil_5F_syntax_14>, in file 'goil_syntax.ggs', line 496
235, // index 76 : <select_goil_5F_syntax_15>, in file 'goil_syntax.ggs', line 514
237, // index 77 : <select_goil_5F_syntax_15>, in file 'goil_syntax.ggs', line 514
239, // index 78 : <select_goil_5F_syntax_16>, in file 'goil_syntax.ggs', line 520
241, // index 79 : <select_goil_5F_syntax_16>, in file 'goil_syntax.ggs', line 520
243, // index 80 : <select_goil_5F_syntax_17>, in file 'goil_syntax.ggs', line 536
245, // index 81 : <select_goil_5F_syntax_17>, in file 'goil_syntax.ggs', line 536
247, // index 82 : <select_goil_5F_syntax_18>, in file 'goil_syntax.ggs', line 542
249, // index 83 : <select_goil_5F_syntax_18>, in file 'goil_syntax.ggs', line 542
251, // index 84 : <select_implementation_5F_parser_0>, in file 'implementation_parser.ggs', line 47
252, // index 85 : <select_implementation_5F_parser_0>, in file 'implementation_parser.ggs', line 47
256, // index 86 : <select_implementation_5F_parser_0>, in file 'implementation_parser.ggs', line 47
259, // index 87 : <select_implementation_5F_parser_1>, in file 'implementation_parser.ggs', line 57
261, // index 88 : <select_implementation_5F_parser_1>, in file 'implementation_parser.ggs', line 57
263, // index 89 : <select_implementation_5F_parser_2>, in file 'implementation_parser.ggs', line 63
265, // index 90 : <select_implementation_5F_parser_2>, in file 'implementation_parser.ggs', line 63
267, // index 91 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 78
269, // index 92 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 78
271, // index 93 : <select_implementation_5F_parser_4>, in file 'implementation_parser.ggs', line 84
273, // index 94 : <select_implementation_5F_parser_4>, in file 'implementation_parser.ggs', line 84
275, // index 95 : <select_implementation_5F_parser_5>, in file 'implementation_parser.ggs', line 102
278, // index 96 : <select_implementation_5F_parser_5>, in file 'implementation_parser.ggs', line 102
279, // index 97 : <select_implementation_5F_parser_6>, in file 'implementation_parser.ggs', line 135
280, // index 98 : <select_implementation_5F_parser_6>, in file 'implementation_parser.ggs', line 135
284, // index 99 : <select_implementation_5F_parser_6>, in file 'implementation_parser.ggs', line 135
287, // index 100 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
290, // index 101 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
293, // index 102 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
296, // index 103 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
299, // index 104 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
302, // index 105 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
305, // index 106 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
308, // index 107 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
311, // index 108 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
314, // index 109 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
317, // index 110 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 213
320, // index 111 : <select_implementation_5F_parser_8>, in file 'implementation_parser.ggs', line 242
324, // index 112 : <select_implementation_5F_parser_8>, in file 'implementation_parser.ggs', line 242
325, // index 113 : <select_implementation_5F_parser_9>, in file 'implementation_parser.ggs', line 283
328, // index 114 : <select_implementation_5F_parser_9>, in file 'implementation_parser.ggs', line 283
330, // index 115 : <select_implementation_5F_parser_10>, in file 'implementation_parser.ggs', line 285
333, // index 116 : <select_implementation_5F_parser_10>, in file 'implementation_parser.ggs', line 285
336, // index 117 : <select_implementation_5F_parser_10>, in file 'implementation_parser.ggs', line 285
339, // index 118 : <select_implementation_5F_parser_11>, in file 'implementation_parser.ggs', line 317
347, // index 119 : <select_implementation_5F_parser_11>, in file 'implementation_parser.ggs', line 317
348, // index 120 : <select_implementation_5F_parser_12>, in file 'implementation_parser.ggs', line 320
352, // index 121 : <select_implementation_5F_parser_12>, in file 'implementation_parser.ggs', line 320
353, // index 122 : <select_implementation_5F_parser_13>, in file 'implementation_parser.ggs', line 329
357, // index 123 : <select_implementation_5F_parser_13>, in file 'implementation_parser.ggs', line 329
358, // index 124 : <select_implementation_5F_parser_14>, in file 'implementation_parser.ggs', line 343
362, // index 125 : <select_implementation_5F_parser_14>, in file 'implementation_parser.ggs', line 343
364, // index 126 : <select_implementation_5F_parser_15>, in file 'implementation_parser.ggs', line 360
368, // index 127 : <select_implementation_5F_parser_15>, in file 'implementation_parser.ggs', line 360
369, // index 128 : <select_implementation_5F_parser_16>, in file 'implementation_parser.ggs', line 376
370, // index 129 : <select_implementation_5F_parser_16>, in file 'implementation_parser.ggs', line 376
374, // index 130 : <select_implementation_5F_parser_17>, in file 'implementation_parser.ggs', line 386
377, // index 131 : <select_implementation_5F_parser_17>, in file 'implementation_parser.ggs', line 386
379, // index 132 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 388
382, // index 133 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 388
385, // index 134 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 388
388, // index 135 : <select_implementation_5F_parser_19>, in file 'implementation_parser.ggs', line 428
391, // index 136 : <select_implementation_5F_parser_19>, in file 'implementation_parser.ggs', line 428
393, // index 137 : <select_implementation_5F_parser_20>, in file 'implementation_parser.ggs', line 430
395, // index 138 : <select_implementation_5F_parser_20>, in file 'implementation_parser.ggs', line 430
398, // index 139 : <select_implementation_5F_parser_20>, in file 'implementation_parser.ggs', line 430
401, // index 140 : <select_implementation_5F_parser_21>, in file 'implementation_parser.ggs', line 465
404, // index 141 : <select_implementation_5F_parser_21>, in file 'implementation_parser.ggs', line 465
406, // index 142 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 467
409, // index 143 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 467
412, // index 144 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 467
415, // index 145 : <select_implementation_5F_parser_23>, in file 'implementation_parser.ggs', line 495
417, // index 146 : <select_implementation_5F_parser_23>, in file 'implementation_parser.ggs', line 495
418, // index 147 : <select_implementation_5F_parser_24>, in file 'implementation_parser.ggs', line 507
421, // index 148 : <select_implementation_5F_parser_24>, in file 'implementation_parser.ggs', line 507
424, // index 149 : <select_implementation_5F_parser_25>, in file 'implementation_parser.ggs', line 523
425, // index 150 : <select_implementation_5F_parser_25>, in file 'implementation_parser.ggs', line 523
429, // index 151 : <select_implementation_5F_parser_26>, in file 'implementation_parser.ggs', line 539
432, // index 152 : <select_implementation_5F_parser_26>, in file 'implementation_parser.ggs', line 539
435, // index 153 : <select_implementation_5F_parser_26>, in file 'implementation_parser.ggs', line 539
438, // index 154 : <select_implementation_5F_parser_27>, in file 'implementation_parser.ggs', line 549
441, // index 155 : <select_implementation_5F_parser_27>, in file 'implementation_parser.ggs', line 549
443, // index 156 : <select_implementation_5F_parser_28>, in file 'implementation_parser.ggs', line 561
446, // index 157 : <select_implementation_5F_parser_28>, in file 'implementation_parser.ggs', line 561
448, // index 158 : <select_implementation_5F_parser_29>, in file 'implementation_parser.ggs', line 575
452, // index 159 : <select_implementation_5F_parser_29>, in file 'implementation_parser.ggs', line 575
453, // index 160 : <select_implementation_5F_parser_30>, in file 'implementation_parser.ggs', line 584
456, // index 161 : <select_implementation_5F_parser_30>, in file 'implementation_parser.ggs', line 584
457 // index 162 : <>, in file '.ggs', line 0
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                           L L ( 1 )    F I R S T    P R O D U C T I O N    I N D E X E S                             
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int32_t gFirstProductionIndexes_goil_type_level_include [89] = {
0, // at 0 : <implementation_definition>
1, // at 1 : <start>
2, // at 2 : <file>
3, // at 3 : <file_without_include>
4, // at 4 : <sign>
5, // at 5 : <description>
6, // at 6 : <OIL_version>
7, // at 7 : <application_definition>
8, // at 8 : <object_definition_list>
9, // at 9 : <boolean>
10, // at 10 : <oil_declaration_list>
11, // at 11 : <oil_declaration>
12, // at 12 : <include_file_level>
13, // at 13 : <include_cpu_level>
14, // at 14 : <include_object_level>
15, // at 15 : <implementation_object_list>
16, // at 16 : <include_implementation_level>
17, // at 17 : <include_type_level>
18, // at 18 : <implementation_objects>
19, // at 19 : <implementation_list>
20, // at 20 : <implementation_type>
21, // at 21 : <struct_options>
22, // at 22 : <objref_option>
23, // at 23 : <string_options>
24, // at 24 : <boolean_options>
25, // at 25 : <enum_item>
26, // at 26 : <enum_options>
27, // at 27 : <number_options>
28, // at 28 : <type_options>
29, // at 29 : <with_auto>
30, // at 30 : <int_or_float>
31, // at 31 : <set_followup>
32, // at 32 : <range_content>
33, // at 33 : <range>
34, // at 34 : <multiple>
35, // at 35 : <identifier_or_attribute>
36, // at 36 : <identifier_or_enum_value>
37, // at 37 : <select_goil_5F_syntax_0>
41, // at 38 : <select_goil_5F_syntax_1>
44, // at 39 : <select_goil_5F_syntax_2>
47, // at 40 : <select_goil_5F_syntax_3>
49, // at 41 : <select_goil_5F_syntax_4>
51, // at 42 : <select_goil_5F_syntax_5>
54, // at 43 : <select_goil_5F_syntax_6>
56, // at 44 : <select_goil_5F_syntax_7>
59, // at 45 : <select_goil_5F_syntax_8>
61, // at 46 : <select_goil_5F_syntax_9>
66, // at 47 : <select_goil_5F_syntax_10>
68, // at 48 : <select_goil_5F_syntax_11>
70, // at 49 : <select_goil_5F_syntax_12>
72, // at 50 : <select_goil_5F_syntax_13>
74, // at 51 : <select_goil_5F_syntax_14>
76, // at 52 : <select_goil_5F_syntax_15>
78, // at 53 : <select_goil_5F_syntax_16>
80, // at 54 : <select_goil_5F_syntax_17>
82, // at 55 : <select_goil_5F_syntax_18>
84, // at 56 : <select_implementation_5F_parser_0>
87, // at 57 : <select_implementation_5F_parser_1>
89, // at 58 : <select_implementation_5F_parser_2>
91, // at 59 : <select_implementation_5F_parser_3>
93, // at 60 : <select_implementation_5F_parser_4>
95, // at 61 : <select_implementation_5F_parser_5>
97, // at 62 : <select_implementation_5F_parser_6>
100, // at 63 : <select_implementation_5F_parser_7>
111, // at 64 : <select_implementation_5F_parser_8>
113, // at 65 : <select_implementation_5F_parser_9>
115, // at 66 : <select_implementation_5F_parser_10>
118, // at 67 : <select_implementation_5F_parser_11>
120, // at 68 : <select_implementation_5F_parser_12>
122, // at 69 : <select_implementation_5F_parser_13>
124, // at 70 : <select_implementation_5F_parser_14>
126, // at 71 : <select_implementation_5F_parser_15>
128, // at 72 : <select_implementation_5F_parser_16>
130, // at 73 : <select_implementation_5F_parser_17>
132, // at 74 : <select_implementation_5F_parser_18>
135, // at 75 : <select_implementation_5F_parser_19>
137, // at 76 : <select_implementation_5F_parser_20>
140, // at 77 : <select_implementation_5F_parser_21>
142, // at 78 : <select_implementation_5F_parser_22>
145, // at 79 : <select_implementation_5F_parser_23>
147, // at 80 : <select_implementation_5F_parser_24>
149, // at 81 : <select_implementation_5F_parser_25>
151, // at 82 : <select_implementation_5F_parser_26>
154, // at 83 : <select_implementation_5F_parser_27>
156, // at 84 : <select_implementation_5F_parser_28>
158, // at 85 : <select_implementation_5F_parser_29>
160, // at 86 : <select_implementation_5F_parser_30>
162, // at 87 : <>
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                    L L ( 1 )    D E C I S I O N    T A B L E S                                       
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int32_t gDecision_goil_type_level_include [] = {
// At index 0 : <implementation_definition> only one production, no choice
  -1,
// At index 1 : <start> only one production, no choice
  -1,
// At index 2 : <file> only one production, no choice
  -1,
// At index 3 : <file_without_include> only one production, no choice
  -1,
// At index 4 : <sign> only one production, no choice
  -1,
// At index 5 : <description> only one production, no choice
  -1,
// At index 6 : <OIL_version> only one production, no choice
  -1,
// At index 7 : <application_definition> only one production, no choice
  -1,
// At index 8 : <object_definition_list> only one production, no choice
  -1,
// At index 9 : <boolean> only one production, no choice
  -1,
// At index 10 : <oil_declaration_list> only one production, no choice
  -1,
// At index 11 : <oil_declaration> only one production, no choice
  -1,
// At index 12 : <include_file_level> only one production, no choice
  -1,
// At index 13 : <include_cpu_level> only one production, no choice
  -1,
// At index 14 : <include_object_level> only one production, no choice
  -1,
// At index 15 : <implementation_object_list> only one production, no choice
  -1,
// At index 16 : <include_implementation_level> only one production, no choice
  -1,
// At index 17 : <include_type_level> only one production, no choice
  -1,
// At index 18 : <implementation_objects> only one production, no choice
  -1,
// At index 19 : <implementation_list> only one production, no choice
  -1,
// At index 20 : <implementation_type> only one production, no choice
  -1,
// At index 21 : <struct_options> only one production, no choice
  -1,
// At index 22 : <objref_option> only one production, no choice
  -1,
// At index 23 : <string_options> only one production, no choice
  -1,
// At index 24 : <boolean_options> only one production, no choice
  -1,
// At index 25 : <enum_item> only one production, no choice
  -1,
// At index 26 : <enum_options> only one production, no choice
  -1,
// At index 27 : <number_options> only one production, no choice
  -1,
// At index 28 : <type_options> only one production, no choice
  -1,
// At index 29 : <with_auto> only one production, no choice
  -1,
// At index 30 : <int_or_float> only one production, no choice
  -1,
// At index 31 : <set_followup> only one production, no choice
  -1,
// At index 32 : <range_content> only one production, no choice
  -1,
// At index 33 : <range> only one production, no choice
  -1,
// At index 34 : <multiple> only one production, no choice
  -1,
// At index 35 : <identifier_or_attribute> only one production, no choice
  -1,
// At index 36 : <identifier_or_enum_value> only one production, no choice
  -1,
//---- Added non terminal symbols from 'select' and 'repeat' instructions
// At index 37 : <select_goil_5F_syntax_0>
-1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_include, C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_IMPLEMENTATION, -1, // Choice 3
C_Lexique_goil_5F_lexique::kToken_CPU, -1, // Choice 4
  -1,
// At index 46 : <select_goil_5F_syntax_1>
-1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_IMPLEMENTATION, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_CPU, -1, // Choice 3
  -1,
// At index 52 : <select_goil_5F_syntax_2>
C_Lexique_goil_5F_lexique::kToken__2D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__2B_, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_uint_5F_number, C_Lexique_goil_5F_lexique::kToken_float_5F_number, C_Lexique_goil_5F_lexique::kToken_set_5F_start_5F_uint_5F_number, -1, // Choice 3
  -1,
// At index 61 : <select_goil_5F_syntax_3>
C_Lexique_goil_5F_lexique::kToken__3B_, C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, -1, // Choice 2
  -1,
// At index 68 : <select_goil_5F_syntax_4>
C_Lexique_goil_5F_lexique::kToken__3B_, C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 75 : <select_goil_5F_syntax_5>
C_Lexique_goil_5F_lexique::kToken__7D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_include, C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 3
  -1,
// At index 83 : <select_goil_5F_syntax_6>
C_Lexique_goil_5F_lexique::kToken_TRUE, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_FALSE, -1, // Choice 2
  -1,
// At index 88 : <select_goil_5F_syntax_7>
C_Lexique_goil_5F_lexique::kToken__7D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_include, C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 3
  -1,
// At index 96 : <select_goil_5F_syntax_8>
C_Lexique_goil_5F_lexique::kToken__3D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
  -1,
// At index 101 : <select_goil_5F_syntax_9>
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__2D_, C_Lexique_goil_5F_lexique::kToken__2B_, C_Lexique_goil_5F_lexique::kToken_uint_5F_number, C_Lexique_goil_5F_lexique::kToken_float_5F_number, C_Lexique_goil_5F_lexique::kToken_set_5F_start_5F_uint_5F_number, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_TRUE, C_Lexique_goil_5F_lexique::kToken_FALSE, -1, // Choice 3
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 4
C_Lexique_goil_5F_lexique::kToken_AUTO, -1, // Choice 5
  -1,
// At index 117 : <select_goil_5F_syntax_10>
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, -1, // Choice 2
  -1,
// At index 123 : <select_goil_5F_syntax_11>
C_Lexique_goil_5F_lexique::kToken_uint_5F_number, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_float_5F_number, -1, // Choice 2
  -1,
// At index 128 : <select_goil_5F_syntax_12>
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, -1, // Choice 2
  -1,
// At index 134 : <select_goil_5F_syntax_13>
C_Lexique_goil_5F_lexique::kToken_include, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
  -1,
// At index 139 : <select_goil_5F_syntax_14>
C_Lexique_goil_5F_lexique::kToken_g_5F_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 144 : <select_goil_5F_syntax_15>
C_Lexique_goil_5F_lexique::kToken_include, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
  -1,
// At index 149 : <select_goil_5F_syntax_16>
C_Lexique_goil_5F_lexique::kToken_g_5F_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 154 : <select_goil_5F_syntax_17>
C_Lexique_goil_5F_lexique::kToken_include, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
  -1,
// At index 159 : <select_goil_5F_syntax_18>
C_Lexique_goil_5F_lexique::kToken_g_5F_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 164 : <select_implementation_5F_parser_0>
C_Lexique_goil_5F_lexique::kToken__7D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_include, C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 3
  -1,
// At index 172 : <select_implementation_5F_parser_1>
C_Lexique_goil_5F_lexique::kToken_include, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
  -1,
// At index 177 : <select_implementation_5F_parser_2>
C_Lexique_goil_5F_lexique::kToken_g_5F_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 182 : <select_implementation_5F_parser_3>
C_Lexique_goil_5F_lexique::kToken_include, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
  -1,
// At index 187 : <select_implementation_5F_parser_4>
C_Lexique_goil_5F_lexique::kToken_g_5F_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 192 : <select_implementation_5F_parser_5>
C_Lexique_goil_5F_lexique::kToken__5B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 2
  -1,
// At index 197 : <select_implementation_5F_parser_6>
C_Lexique_goil_5F_lexique::kToken__7D_, C_Lexique_goil_5F_lexique::kToken_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, C_Lexique_goil_5F_lexique::kToken_UINT_33__32_, C_Lexique_goil_5F_lexique::kToken_INT_33__32_, C_Lexique_goil_5F_lexique::kToken_UINT_36__34_, C_Lexique_goil_5F_lexique::kToken_INT_36__34_, C_Lexique_goil_5F_lexique::kToken_FLOAT, C_Lexique_goil_5F_lexique::kToken_ENUM, C_Lexique_goil_5F_lexique::kToken_BOOLEAN, C_Lexique_goil_5F_lexique::kToken_STRING, C_Lexique_goil_5F_lexique::kToken_IDENTIFIER, C_Lexique_goil_5F_lexique::kToken_STRUCT, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_include, C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 3
  -1,
// At index 216 : <select_implementation_5F_parser_7>
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
// At index 239 : <select_implementation_5F_parser_8>
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
  -1,
// At index 244 : <select_implementation_5F_parser_9>
C_Lexique_goil_5F_lexique::kToken__3D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 252 : <select_implementation_5F_parser_10>
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_AUTO, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT, -1, // Choice 3
  -1,
// At index 259 : <select_implementation_5F_parser_11>
C_Lexique_goil_5F_lexique::kToken__5B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
  -1,
// At index 264 : <select_implementation_5F_parser_12>
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 269 : <select_implementation_5F_parser_13>
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__5D_, -1, // Choice 2
  -1,
// At index 274 : <select_implementation_5F_parser_14>
C_Lexique_goil_5F_lexique::kToken__3D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 282 : <select_implementation_5F_parser_15>
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 288 : <select_implementation_5F_parser_16>
C_Lexique_goil_5F_lexique::kToken__5D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 293 : <select_implementation_5F_parser_17>
C_Lexique_goil_5F_lexique::kToken__3D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 301 : <select_implementation_5F_parser_18>
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_AUTO, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT, -1, // Choice 3
  -1,
// At index 308 : <select_implementation_5F_parser_19>
C_Lexique_goil_5F_lexique::kToken__3D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 316 : <select_implementation_5F_parser_20>
C_Lexique_goil_5F_lexique::kToken__2D_, C_Lexique_goil_5F_lexique::kToken__2B_, C_Lexique_goil_5F_lexique::kToken_uint_5F_number, C_Lexique_goil_5F_lexique::kToken_float_5F_number, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_AUTO, -1, // Choice 3
  -1,
// At index 326 : <select_implementation_5F_parser_21>
C_Lexique_goil_5F_lexique::kToken__3D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 334 : <select_implementation_5F_parser_22>
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_AUTO, -1, // Choice 3
  -1,
// At index 341 : <select_implementation_5F_parser_23>
C_Lexique_goil_5F_lexique::kToken_WITH_5F_AUTO, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, C_Lexique_goil_5F_lexique::kToken__5B_, -1, // Choice 2
  -1,
// At index 347 : <select_implementation_5F_parser_24>
C_Lexique_goil_5F_lexique::kToken_uint_5F_number, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_float_5F_number, -1, // Choice 2
  -1,
// At index 352 : <select_implementation_5F_parser_25>
C_Lexique_goil_5F_lexique::kToken__5D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 357 : <select_implementation_5F_parser_26>
C_Lexique_goil_5F_lexique::kToken_set_5F_start_5F_uint_5F_number, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_uint_5F_number, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_float_5F_number, -1, // Choice 3
  -1,
// At index 364 : <select_implementation_5F_parser_27>
C_Lexique_goil_5F_lexique::kToken__2E__2E_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 370 : <select_implementation_5F_parser_28>
C_Lexique_goil_5F_lexique::kToken__2E__2E_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 376 : <select_implementation_5F_parser_29>
C_Lexique_goil_5F_lexique::kToken__5B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
  -1,
// At index 381 : <select_implementation_5F_parser_30>
C_Lexique_goil_5F_lexique::kToken__5B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3D_, C_Lexique_goil_5F_lexique::kToken__3B_, -1, // Choice 2
  -1,
// At index 388 : <> only one production, no choice
  -1,
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            L L ( 1 )    D E C I S I O N    T A B L E S    I N D E X E S                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int32_t gDecisionIndexes_goil_type_level_include [89] = {
0, // at 0 : <implementation_definition>
1, // at 1 : <start>
2, // at 2 : <file>
3, // at 3 : <file_without_include>
4, // at 4 : <sign>
5, // at 5 : <description>
6, // at 6 : <OIL_version>
7, // at 7 : <application_definition>
8, // at 8 : <object_definition_list>
9, // at 9 : <boolean>
10, // at 10 : <oil_declaration_list>
11, // at 11 : <oil_declaration>
12, // at 12 : <include_file_level>
13, // at 13 : <include_cpu_level>
14, // at 14 : <include_object_level>
15, // at 15 : <implementation_object_list>
16, // at 16 : <include_implementation_level>
17, // at 17 : <include_type_level>
18, // at 18 : <implementation_objects>
19, // at 19 : <implementation_list>
20, // at 20 : <implementation_type>
21, // at 21 : <struct_options>
22, // at 22 : <objref_option>
23, // at 23 : <string_options>
24, // at 24 : <boolean_options>
25, // at 25 : <enum_item>
26, // at 26 : <enum_options>
27, // at 27 : <number_options>
28, // at 28 : <type_options>
29, // at 29 : <with_auto>
30, // at 30 : <int_or_float>
31, // at 31 : <set_followup>
32, // at 32 : <range_content>
33, // at 33 : <range>
34, // at 34 : <multiple>
35, // at 35 : <identifier_or_attribute>
36, // at 36 : <identifier_or_enum_value>
37, // at 37 : <select_goil_5F_syntax_0>
46, // at 38 : <select_goil_5F_syntax_1>
52, // at 39 : <select_goil_5F_syntax_2>
61, // at 40 : <select_goil_5F_syntax_3>
68, // at 41 : <select_goil_5F_syntax_4>
75, // at 42 : <select_goil_5F_syntax_5>
83, // at 43 : <select_goil_5F_syntax_6>
88, // at 44 : <select_goil_5F_syntax_7>
96, // at 45 : <select_goil_5F_syntax_8>
101, // at 46 : <select_goil_5F_syntax_9>
117, // at 47 : <select_goil_5F_syntax_10>
123, // at 48 : <select_goil_5F_syntax_11>
128, // at 49 : <select_goil_5F_syntax_12>
134, // at 50 : <select_goil_5F_syntax_13>
139, // at 51 : <select_goil_5F_syntax_14>
144, // at 52 : <select_goil_5F_syntax_15>
149, // at 53 : <select_goil_5F_syntax_16>
154, // at 54 : <select_goil_5F_syntax_17>
159, // at 55 : <select_goil_5F_syntax_18>
164, // at 56 : <select_implementation_5F_parser_0>
172, // at 57 : <select_implementation_5F_parser_1>
177, // at 58 : <select_implementation_5F_parser_2>
182, // at 59 : <select_implementation_5F_parser_3>
187, // at 60 : <select_implementation_5F_parser_4>
192, // at 61 : <select_implementation_5F_parser_5>
197, // at 62 : <select_implementation_5F_parser_6>
216, // at 63 : <select_implementation_5F_parser_7>
239, // at 64 : <select_implementation_5F_parser_8>
244, // at 65 : <select_implementation_5F_parser_9>
252, // at 66 : <select_implementation_5F_parser_10>
259, // at 67 : <select_implementation_5F_parser_11>
264, // at 68 : <select_implementation_5F_parser_12>
269, // at 69 : <select_implementation_5F_parser_13>
274, // at 70 : <select_implementation_5F_parser_14>
282, // at 71 : <select_implementation_5F_parser_15>
288, // at 72 : <select_implementation_5F_parser_16>
293, // at 73 : <select_implementation_5F_parser_17>
301, // at 74 : <select_implementation_5F_parser_18>
308, // at 75 : <select_implementation_5F_parser_19>
316, // at 76 : <select_implementation_5F_parser_20>
326, // at 77 : <select_implementation_5F_parser_21>
334, // at 78 : <select_implementation_5F_parser_22>
341, // at 79 : <select_implementation_5F_parser_23>
347, // at 80 : <select_implementation_5F_parser_24>
352, // at 81 : <select_implementation_5F_parser_25>
357, // at 82 : <select_implementation_5F_parser_26>
364, // at 83 : <select_implementation_5F_parser_27>
370, // at 84 : <select_implementation_5F_parser_28>
376, // at 85 : <select_implementation_5F_parser_29>
381, // at 86 : <select_implementation_5F_parser_30>
388, // at 87 : <>
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                              'implementation_definition' non terminal implementation                                 
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_implementation_5F_definition_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_definition_i0_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_implementation_5F_definition_indexing (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_definition_i0_indexing(inLexique) ;
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

void cGrammar_goil_5F_type_5F_level_5F_include::nt_start_indexing (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_start_i0_indexing(inLexique) ;
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

void cGrammar_goil_5F_type_5F_level_5F_include::nt_file_indexing (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_file_i1_indexing(inLexique) ;
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
//                                 'file_without_include' non terminal implementation                                   
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_file_5F_without_5F_include_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_file_5F_without_5F_include_i2_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_file_5F_without_5F_include_indexing (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_file_5F_without_5F_include_i2_indexing(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_file_5F_without_5F_include_ (GALGAS_implementation & parameter_1,
                                GALGAS_applicationDefinition & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_file_5F_without_5F_include_i2_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                         'sign' non terminal implementation                                           
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_sign_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_sign_i3_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_sign_indexing (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_sign_i3_indexing(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_sign_ (GALGAS_bool & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_sign_i3_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                     'description' non terminal implementation                                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_description_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_description_i4_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_description_indexing (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_description_i4_indexing(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_description_ (GALGAS_lstring & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_description_i4_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                     'OIL_version' non terminal implementation                                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_OIL_5F_version_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_OIL_5F_version_i5_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_OIL_5F_version_indexing (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_OIL_5F_version_i5_indexing(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_OIL_5F_version_ (GALGAS_lstring & parameter_1,
                                GALGAS_lstring & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_OIL_5F_version_i5_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                'application_definition' non terminal implementation                                  
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_application_5F_definition_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_application_5F_definition_i6_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_application_5F_definition_indexing (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_application_5F_definition_i6_indexing(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_application_5F_definition_ (const GALGAS_implementation parameter_1,
                                GALGAS_applicationDefinition & parameter_2,
                                GALGAS_string & parameter_3,
                                const GALGAS_bool parameter_4,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_application_5F_definition_i6_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                'object_definition_list' non terminal implementation                                  
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_object_5F_definition_5F_list_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_object_5F_definition_5F_list_i7_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_object_5F_definition_5F_list_indexing (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_object_5F_definition_5F_list_i7_indexing(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_object_5F_definition_5F_list_ (const GALGAS_implementation parameter_1,
                                GALGAS_objectsMap & parameter_2,
                                GALGAS_string & parameter_3,
                                const GALGAS_bool parameter_4,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_object_5F_definition_5F_list_i7_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                       'boolean' non terminal implementation                                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_boolean_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_boolean_i8_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_boolean_indexing (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_boolean_i8_indexing(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_boolean_ (GALGAS_lbool & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_boolean_i8_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                 'oil_declaration_list' non terminal implementation                                   
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_oil_5F_declaration_5F_list_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_5F_list_i9_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_oil_5F_declaration_5F_list_indexing (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_5F_list_i9_indexing(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_oil_5F_declaration_5F_list_ (const GALGAS_implementationObjectMap parameter_1,
                                GALGAS_objectAttributes & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_5F_list_i9_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                   'oil_declaration' non terminal implementation                                      
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_oil_5F_declaration_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_i10_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_oil_5F_declaration_indexing (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_i10_indexing(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_oil_5F_declaration_ (const GALGAS_implementationObjectMap parameter_1,
                                GALGAS_objectAttributes & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_i10_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                  'include_file_level' non terminal implementation                                    
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_include_5F_file_5F_level_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_file_5F_level_i11_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_include_5F_file_5F_level_indexing (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_file_5F_level_i11_indexing(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_include_5F_file_5F_level_ (GALGAS_implementation & parameter_1,
                                GALGAS_applicationDefinition & parameter_2,
                                GALGAS_string & parameter_3,
                                const GALGAS_bool parameter_4,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_file_5F_level_i11_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                  'include_cpu_level' non terminal implementation                                     
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_include_5F_cpu_5F_level_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_cpu_5F_level_i12_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_include_5F_cpu_5F_level_indexing (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_cpu_5F_level_i12_indexing(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_include_5F_cpu_5F_level_ (const GALGAS_implementation parameter_1,
                                GALGAS_objectsMap & parameter_2,
                                GALGAS_string & parameter_3,
                                const GALGAS_bool parameter_4,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_cpu_5F_level_i12_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                 'include_object_level' non terminal implementation                                   
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_include_5F_object_5F_level_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_object_5F_level_i13_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_include_5F_object_5F_level_indexing (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_object_5F_level_i13_indexing(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_include_5F_object_5F_level_ (const GALGAS_implementationObjectMap parameter_1,
                                GALGAS_objectAttributes & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_object_5F_level_i13_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                              'implementation_object_list' non terminal implementation                                
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_type_5F_level_5F_include::nt_implementation_5F_object_5F_list_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_object_5F_list_i1_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_implementation_5F_object_5F_list_indexing (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_object_5F_list_i1_indexing(inLexique) ;
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

void cGrammar_goil_5F_type_5F_level_5F_include::nt_include_5F_implementation_5F_level_indexing (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_include_5F_implementation_5F_level_i2_indexing(inLexique) ;
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

void cGrammar_goil_5F_type_5F_level_5F_include::nt_include_5F_type_5F_level_indexing (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_include_5F_type_5F_level_i3_indexing(inLexique) ;
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

void cGrammar_goil_5F_type_5F_level_5F_include::nt_implementation_5F_objects_indexing (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_objects_i4_indexing(inLexique) ;
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

void cGrammar_goil_5F_type_5F_level_5F_include::nt_implementation_5F_list_indexing (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_list_i5_indexing(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_implementation_5F_list_ (GALGAS_implementationObjectMap & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_list_i5_(parameter_1, inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::performIndexing (C_Compiler * inCompiler,
             const C_String & inSourceFilePath) {
  C_Lexique_goil_5F_lexique * scanner = NULL ;
  macroMyNew (scanner, C_Lexique_goil_5F_lexique (inCompiler, inSourceFilePath COMMA_HERE)) ;
  scanner->enableIndexing () ;
  if (scanner->sourceText ().isValid ()) {
    const bool ok = scanner->performTopDownParsing (gProductions_goil_type_level_include, gProductionNames_goil_type_level_include, gProductionIndexes_goil_type_level_include,
                                                    gFirstProductionIndexes_goil_type_level_include, gDecision_goil_type_level_include, gDecisionIndexes_goil_type_level_include, 457) ;
    if (ok) {
      cGrammar_goil_5F_type_5F_level_5F_include grammar ;
      grammar.nt_implementation_5F_list_indexing (scanner) ;
    }
    scanner->generateIndexFile () ;
  }
  macroDetachSharedObject (scanner) ;
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
                                    gFirstProductionIndexes_goil_type_level_include, gDecision_goil_type_level_include, gDecisionIndexes_goil_type_level_include, 457) ;
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
    const GALGAS_string filePathAsString = inFilePath.readProperty_string () ;
    C_String filePath = filePathAsString.stringValue () ;
    if (! C_FileManager::isAbsolutePath (filePath)) {
      filePath = inCompiler->sourceFilePath ().stringByDeletingLastPathComponent ().stringByAppendingPathComponent (filePath) ;
    }
    if (C_FileManager::fileExistsAtPath (filePath)) {
    C_Lexique_goil_5F_lexique * scanner = NULL ;
    macroMyNew (scanner, C_Lexique_goil_5F_lexique (inCompiler, filePath COMMA_HERE)) ;
    if (scanner->sourceText ().isValid ()) {
      const bool ok = scanner->performTopDownParsing (gProductions_goil_type_level_include, gProductionNames_goil_type_level_include, gProductionIndexes_goil_type_level_include,
                                                      gFirstProductionIndexes_goil_type_level_include, gDecision_goil_type_level_include, gDecisionIndexes_goil_type_level_include, 457) ;
      if (ok && ! executionModeIsSyntaxAnalysisOnly ()) {
        cGrammar_goil_5F_type_5F_level_5F_include grammar ;
        grammar.nt_implementation_5F_list_ (parameter_1, scanner) ;
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
                                                    gFirstProductionIndexes_goil_type_level_include, gDecision_goil_type_level_include, gDecisionIndexes_goil_type_level_include, 457) ;
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

void cGrammar_goil_5F_type_5F_level_5F_include::nt_implementation_5F_type_indexing (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_type_i6_indexing(inLexique) ;
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

void cGrammar_goil_5F_type_5F_level_5F_include::nt_struct_5F_options_indexing (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_struct_5F_options_i7_indexing(inLexique) ;
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

void cGrammar_goil_5F_type_5F_level_5F_include::nt_objref_5F_option_indexing (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_objref_5F_option_i8_indexing(inLexique) ;
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

void cGrammar_goil_5F_type_5F_level_5F_include::nt_string_5F_options_indexing (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_string_5F_options_i9_indexing(inLexique) ;
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

void cGrammar_goil_5F_type_5F_level_5F_include::nt_boolean_5F_options_indexing (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_boolean_5F_options_i10_indexing(inLexique) ;
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

void cGrammar_goil_5F_type_5F_level_5F_include::nt_enum_5F_item_indexing (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_enum_5F_item_i11_indexing(inLexique) ;
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

void cGrammar_goil_5F_type_5F_level_5F_include::nt_enum_5F_options_indexing (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_enum_5F_options_i12_indexing(inLexique) ;
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

void cGrammar_goil_5F_type_5F_level_5F_include::nt_number_5F_options_indexing (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_number_5F_options_i13_indexing(inLexique) ;
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

void cGrammar_goil_5F_type_5F_level_5F_include::nt_type_5F_options_indexing (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_type_5F_options_i14_indexing(inLexique) ;
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

void cGrammar_goil_5F_type_5F_level_5F_include::nt_with_5F_auto_indexing (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_with_5F_auto_i15_indexing(inLexique) ;
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

void cGrammar_goil_5F_type_5F_level_5F_include::nt_int_5F_or_5F_float_indexing (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_int_5F_or_5F_float_i16_indexing(inLexique) ;
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

void cGrammar_goil_5F_type_5F_level_5F_include::nt_set_5F_followup_indexing (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_set_5F_followup_i17_indexing(inLexique) ;
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

void cGrammar_goil_5F_type_5F_level_5F_include::nt_range_5F_content_indexing (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_range_5F_content_i18_indexing(inLexique) ;
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

void cGrammar_goil_5F_type_5F_level_5F_include::nt_range_indexing (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_range_i19_indexing(inLexique) ;
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

void cGrammar_goil_5F_type_5F_level_5F_include::nt_multiple_indexing (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_multiple_i20_indexing(inLexique) ;
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

void cGrammar_goil_5F_type_5F_level_5F_include::nt_identifier_5F_or_5F_attribute_indexing (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_identifier_5F_or_5F_attribute_i21_indexing(inLexique) ;
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

void cGrammar_goil_5F_type_5F_level_5F_include::nt_identifier_5F_or_5F_enum_5F_value_indexing (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_identifier_5F_or_5F_enum_5F_value_i22_indexing(inLexique) ;
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
//                            'select_goil_5F_syntax_18' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_goil_5F_syntax_18 (C_Lexique_goil_5F_lexique * inLexique) {
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

static const int32_t gProductions_options_grammar [] = {
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

static const int32_t gProductionIndexes_options_grammar [17] = {
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

static const int32_t gFirstProductionIndexes_options_grammar [10] = {
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

static const int32_t gDecision_options_grammar [] = {
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

static const int32_t gDecisionIndexes_options_grammar [10] = {
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

void cGrammar_options_5F_grammar::nt_option_5F_parser_5F_start_indexing (C_Lexique_options_5F_scanner * inLexique) {
  rule_options_5F_parser_option_5F_parser_5F_start_i0_indexing(inLexique) ;
}

void cGrammar_options_5F_grammar::nt_option_5F_parser_5F_start_ (GALGAS_gtlData & parameter_1,
                                C_Lexique_options_5F_scanner * inLexique) {
  rule_options_5F_parser_option_5F_parser_5F_start_i0_(parameter_1, inLexique) ;
}

void cGrammar_options_5F_grammar::performIndexing (C_Compiler * inCompiler,
             const C_String & inSourceFilePath) {
  C_Lexique_options_5F_scanner * scanner = NULL ;
  macroMyNew (scanner, C_Lexique_options_5F_scanner (inCompiler, inSourceFilePath COMMA_HERE)) ;
  scanner->enableIndexing () ;
  if (scanner->sourceText ().isValid ()) {
    const bool ok = scanner->performTopDownParsing (gProductions_options_grammar, gProductionNames_options_grammar, gProductionIndexes_options_grammar,
                                                    gFirstProductionIndexes_options_grammar, gDecision_options_grammar, gDecisionIndexes_options_grammar, 41) ;
    if (ok) {
      cGrammar_options_5F_grammar grammar ;
      grammar.nt_option_5F_parser_5F_start_indexing (scanner) ;
    }
    scanner->generateIndexFile () ;
  }
  macroDetachSharedObject (scanner) ;
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

void cGrammar_options_5F_grammar::nt_option_5F_item_indexing (C_Lexique_options_5F_scanner * inLexique) {
  rule_options_5F_parser_option_5F_item_i1_indexing(inLexique) ;
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

void cGrammar_options_5F_grammar::nt_option_5F_value_indexing (C_Lexique_options_5F_scanner * inLexique) {
  switch (inLexique->nextProductionIndex ()) {
  case 1 :
    rule_options_5F_parser_option_5F_value_i2_indexing(inLexique) ;
    break ;
  case 2 :
    rule_options_5F_parser_option_5F_value_i3_indexing(inLexique) ;
    break ;
  case 3 :
    rule_options_5F_parser_option_5F_value_i4_indexing(inLexique) ;
    break ;
  case 4 :
    rule_options_5F_parser_option_5F_value_i5_indexing(inLexique) ;
    break ;
  case 5 :
    rule_options_5F_parser_option_5F_value_i6_indexing(inLexique) ;
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

void cGrammar_options_5F_grammar::nt_list_5F_option_5F_value_indexing (C_Lexique_options_5F_scanner * inLexique) {
  rule_options_5F_parser_list_5F_option_5F_value_i7_indexing(inLexique) ;
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
  GALGAS_implementation var_imp_928 = GALGAS_implementation::constructor_new (GALGAS_implementationMap::constructor_emptyMap (SOURCE_FILE ("arxml_parser.galgas", 36))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 36)) ;
  GALGAS_applicationDefinition var_application_1014 = function_emptyApplicationDefinition (inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 37)) ;
  GALGAS_string var_fileIncludeList_1067 = GALGAS_string::makeEmptyString () ;
  GALGAS_bool var_debug_1100 = GALGAS_bool (false) ;
  GALGAS_string var_s_1234 = GALGAS_string::constructor_retrieveAndResetTemplateString (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 44)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsStrictSup, var_s_1234.getter_count (SOURCE_FILE ("arxml_parser.galgas", 45)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 46)), GALGAS_string ("No character is allowed before XML header"), fixItArray1  COMMA_SOURCE_FILE ("arxml_parser.galgas", 46)) ;
    }
  }
  inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken__3C__3F_ COMMA_SOURCE_FILE ("arxml_parser.galgas", 49)) ;
  GALGAS_lstring var_name_1409 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken_name COMMA_SOURCE_FILE ("arxml_parser.galgas", 50)) ;
  GALGAS_arxmlAttributeMap var_attributes_1436 = GALGAS_arxmlAttributeMap::constructor_emptyMap (SOURCE_FILE ("arxml_parser.galgas", 52)) ;
  bool repeatFlag_2 = true ;
  while (repeatFlag_2) {
    if (select_arxml_5F_parser_0 (inCompiler) == 2) {
      GALGAS_lstring var_attributeName_1501 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken_name COMMA_SOURCE_FILE ("arxml_parser.galgas", 55)) ;
      inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxml_parser.galgas", 56)) ;
      GALGAS_lstring var_attributeValue_1549 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken_value COMMA_SOURCE_FILE ("arxml_parser.galgas", 57)) ;
      {
      var_attributes_1436.setter_insertKey (var_attributeName_1501, var_attributeValue_1549, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 58)) ;
      }
    }else{
      repeatFlag_2 = false ;
    }
  }
  inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken__3F__3E_ COMMA_SOURCE_FILE ("arxml_parser.galgas", 60)) ;
  GALGAS_arxmlNodeList var_nodes_1672 = GALGAS_arxmlNodeList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 62)) ;
  nt_element_5F_list_ (var_nodes_1672, constinArgument_includeComments, constinArgument_doNotCondenseWhiteSpaces, inCompiler) ;
  outArgument_rootNode = GALGAS_arxmlElementNode::constructor_new (var_name_1409, var_attributes_1436, var_nodes_1672  COMMA_SOURCE_FILE ("arxml_parser.galgas", 68)) ;
  GALGAS_lstring var_autosarVersion_1991 ;
  GALGAS_lstring var_autosarDescription_2021 ;
  {
  routine_getAutosarVersion (outArgument_rootNode, var_autosarVersion_1991, var_autosarDescription_2021, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 81)) ;
  }
  enumGalgasBool test_3 = kBoolTrue ;
  if (kBoolTrue == test_3) {
    test_3 = GALGAS_bool (kIsEqual, var_autosarVersion_1991.readProperty_string ().objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
    if (kBoolTrue == test_3) {
      TC_Array <C_FixItDescription> fixItArray4 ;
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 84)), GALGAS_string ("[TPS_ECUC_06005][TPS_ECUC_08053] : Missing AUTOSAR version"), fixItArray4  COMMA_SOURCE_FILE ("arxml_parser.galgas", 84)) ;
    }
  }
  GALGAS_stringlist var_autosarVlist_2316 = var_autosarVersion_1991.readProperty_string ().getter_componentsSeparatedByString (GALGAS_string (".") COMMA_SOURCE_FILE ("arxml_parser.galgas", 88)) ;
  GALGAS_string var_versionFirst_2421 ;
  {
  var_autosarVlist_2316.setter_popFirst (var_versionFirst_2421, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 89)) ;
  }
  GALGAS_string var_versionSecond_2475 ;
  {
  var_autosarVlist_2316.setter_popFirst (var_versionSecond_2475, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 90)) ;
  }
  GALGAS_lstring var_autosarShortVersion_2505 = GALGAS_lstring::constructor_new (var_versionFirst_2421.add_operation (GALGAS_string ("."), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 91)).add_operation (var_versionSecond_2475, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 91)), var_autosarVersion_1991.readProperty_location ()  COMMA_SOURCE_FILE ("arxml_parser.galgas", 91)) ;
  {
  routine_displayOil (GALGAS_string ("\nOIL_VERSION = \"").add_operation (var_autosarShortVersion_2505.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 93)).add_operation (GALGAS_string ("\";\n\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 93)), inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 93)) ;
  }
  {
  var_application_1014.setter_setVersion (var_autosarShortVersion_2505 COMMA_SOURCE_FILE ("arxml_parser.galgas", 95)) ;
  }
  {
  var_application_1014.setter_setVersionDescription (var_autosarDescription_2021 COMMA_SOURCE_FILE ("arxml_parser.galgas", 96)) ;
  }
  GALGAS_string var_autosarVersionNoDot_3010 = var_autosarVersion_1991.readProperty_string ().getter_stringByReplacingStringByString (GALGAS_string ("."), GALGAS_string ("-"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 105)) ;
  GALGAS_string var_autosarMetaFile_3169 = GALGAS_string ("AUTOSAR_").add_operation (var_autosarVersionNoDot_3010, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 107)).add_operation (GALGAS_string (".xsd"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 107)) ;
  GALGAS_string var_filePath_3243 = function_templates_5F_directory (GALGAS_string ("arxmlMeta"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 108)).add_operation (var_autosarMetaFile_3169, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 108)) ;
  GALGAS_arxmlMetaClassMap var_classMap_3327 ;
  enumGalgasBool test_5 = kBoolTrue ;
  if (kBoolTrue == test_5) {
    test_5 = var_filePath_3243.getter_fileExists (SOURCE_FILE ("arxml_parser.galgas", 111)).operator_not (SOURCE_FILE ("arxml_parser.galgas", 111)).boolEnum () ;
    if (kBoolTrue == test_5) {
      TC_Array <C_FixItDescription> fixItArray6 ;
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 112)), GALGAS_string ("The corresponding metafile ").add_operation (var_filePath_3243, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 112)).add_operation (GALGAS_string (" does not"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 112)).add_operation (GALGAS_string (" exists. The Metamodel can be found here : "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 112)).add_operation (GALGAS_string ("http://www.autosar.org/specification -> Methodology and Templates -> "), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 113)).add_operation (GALGAS_string ("Templates -> AUTOSAR_MMOD_XMLSchema.zip."), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 114)), fixItArray6  COMMA_SOURCE_FILE ("arxml_parser.galgas", 112)) ;
    }
  }
  var_classMap_3327.drop () ;
  cGrammar_arxmlmetaparser_5F_grammar::_performSourceFileParsing_ (inCompiler, function_lstringWith (var_filePath_3243, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 118)), var_classMap_3327, var_debug_1100  COMMA_SOURCE_FILE ("arxml_parser.galgas", 118)) ;
  GALGAS_arxmlElementValue var_rootValue_3900 ;
  {
  routine_nodeToClass (outArgument_rootNode, var_classMap_3327, var_rootValue_3900, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 124)) ;
  }
  {
  routine_includeConfigs (var_imp_928, var_application_1014, var_fileIncludeList_1067, var_autosarShortVersion_2505, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 136)) ;
  }
  {
  routine_convertToOil (var_imp_928, var_application_1014, var_rootValue_3900, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 143)) ;
  }
  callExtensionMethod_checkObjectReferences ((cPtr_implementation *) var_imp_928.ptr (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 154)) ;
  enumGalgasBool test_7 = kBoolTrue ;
  if (kBoolTrue == test_7) {
    test_7 = GALGAS_bool (kIsEqual, GALGAS_uint::constructor_errorCount (SOURCE_FILE ("arxml_parser.galgas", 156)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
    if (kBoolTrue == test_7) {
      {
      routine_setDefaults (var_imp_928, var_application_1014, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 157)) ;
      }
    }
  }
  enumGalgasBool test_8 = kBoolTrue ;
  if (kBoolTrue == test_8) {
    test_8 = GALGAS_bool (kIsEqual, GALGAS_uint::constructor_errorCount (SOURCE_FILE ("arxml_parser.galgas", 164)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
    if (kBoolTrue == test_8) {
      {
      routine_verifyAll (var_imp_928, var_application_1014, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 165)) ;
      }
    }
  }
  enumGalgasBool test_9 = kBoolTrue ;
  if (kBoolTrue == test_9) {
    test_9 = GALGAS_bool (kIsEqual, GALGAS_uint::constructor_errorCount (SOURCE_FILE ("arxml_parser.galgas", 167)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
    if (kBoolTrue == test_9) {
      GALGAS_gtlData var_templateData_5216 = callExtensionGetter_templateData ((const cPtr_applicationDefinition *) var_application_1014.ptr (), var_imp_928, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 168)) ;
      {
      routine_generate_5F_all (var_templateData_5216, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 171)) ;
      }
    }
  }
  var_fileIncludeList_1067 = GALGAS_string::constructor_stringWithSourceFilePath (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 174)).getter_lastPathComponent (SOURCE_FILE ("arxml_parser.galgas", 174)).add_operation (GALGAS_string (":"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 174)).add_operation (var_fileIncludeList_1067, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 174)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 174)) ;
  GALGAS_string var_oilDepFileName_5529 = GALGAS_string::constructor_stringWithSourceFilePath (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 175)).getter_stringByDeletingLastPathComponent (SOURCE_FILE ("arxml_parser.galgas", 175)).add_operation (GALGAS_string ("/build/"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 175)).add_operation (GALGAS_string::constructor_stringWithSourceFilePath (inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 176)).getter_lastPathComponent (SOURCE_FILE ("arxml_parser.galgas", 176)), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 176)).add_operation (GALGAS_string (".dep"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 176)) ;
  var_fileIncludeList_1067.method_writeToFile (var_oilDepFileName_5529, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 178)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxml_5F_parser::rule_arxml_5F_parser_arxml_5F_start_5F_symbol_i0_parse (C_Lexique_arxml_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken__3C__3F_ COMMA_SOURCE_FILE ("arxml_parser.galgas", 49)) ;
  inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken_name COMMA_SOURCE_FILE ("arxml_parser.galgas", 50)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    if (select_arxml_5F_parser_0 (inCompiler) == 2) {
      inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken_name COMMA_SOURCE_FILE ("arxml_parser.galgas", 55)) ;
      inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxml_parser.galgas", 56)) ;
      inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken_value COMMA_SOURCE_FILE ("arxml_parser.galgas", 57)) ;
    }else{
      repeatFlag_0 = false ;
    }
  }
  inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken__3F__3E_ COMMA_SOURCE_FILE ("arxml_parser.galgas", 60)) ;
  nt_element_5F_list_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxml_5F_parser::rule_arxml_5F_parser_arxml_5F_start_5F_symbol_i0_indexing (C_Lexique_arxml_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken__3C__3F_ COMMA_SOURCE_FILE ("arxml_parser.galgas", 49)) ;
  inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken_name COMMA_SOURCE_FILE ("arxml_parser.galgas", 50)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    if (select_arxml_5F_parser_0 (inCompiler) == 2) {
      inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken_name COMMA_SOURCE_FILE ("arxml_parser.galgas", 55)) ;
      inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxml_parser.galgas", 56)) ;
      inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken_value COMMA_SOURCE_FILE ("arxml_parser.galgas", 57)) ;
    }else{
      repeatFlag_0 = false ;
    }
  }
  inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken__3F__3E_ COMMA_SOURCE_FILE ("arxml_parser.galgas", 60)) ;
  nt_element_5F_list_indexing (inCompiler) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxml_5F_parser::rule_arxml_5F_parser_element_5F_list_i1_ (GALGAS_arxmlNodeList & ioArgument_nodes,
                                                                        const GALGAS_bool constinArgument_includeComments,
                                                                        const GALGAS_bool constinArgument_doNotCondenseWhiteSpaces,
                                                                        C_Lexique_arxml_5F_scanner * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    if (select_arxml_5F_parser_1 (inCompiler) == 2) {
      {
      routine_addText (ioArgument_nodes, constinArgument_doNotCondenseWhiteSpaces, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 193)) ;
      }
      nt_element_ (ioArgument_nodes, constinArgument_includeComments, constinArgument_doNotCondenseWhiteSpaces, inCompiler) ;
    }else{
      repeatFlag_0 = false ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxml_5F_parser::rule_arxml_5F_parser_element_5F_list_i1_parse (C_Lexique_arxml_5F_scanner * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    if (select_arxml_5F_parser_1 (inCompiler) == 2) {
      nt_element_parse (inCompiler) ;
    }else{
      repeatFlag_0 = false ;
    }
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxml_5F_parser::rule_arxml_5F_parser_element_5F_list_i1_indexing (C_Lexique_arxml_5F_scanner * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    if (select_arxml_5F_parser_1 (inCompiler) == 2) {
      nt_element_indexing (inCompiler) ;
    }else{
      repeatFlag_0 = false ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxml_5F_parser::rule_arxml_5F_parser_element_i2_ (GALGAS_arxmlNodeList & ioArgument_nodes,
                                                                const GALGAS_bool constinArgument_includeComments,
                                                                const GALGAS_bool /* constinArgument_doNotCondenseWhiteSpaces */,
                                                                C_Lexique_arxml_5F_scanner * inCompiler) {
  GALGAS_lstring var_commentString_6445 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken_comment COMMA_SOURCE_FILE ("arxml_parser.galgas", 210)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = constinArgument_includeComments.boolEnum () ;
    if (kBoolTrue == test_0) {
      ioArgument_nodes.addAssign_operation (GALGAS_arxmlCommentNode::constructor_new (var_commentString_6445  COMMA_SOURCE_FILE ("arxml_parser.galgas", 212))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 212)) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxml_5F_parser::rule_arxml_5F_parser_element_i2_parse (C_Lexique_arxml_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken_comment COMMA_SOURCE_FILE ("arxml_parser.galgas", 210)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxml_5F_parser::rule_arxml_5F_parser_element_i2_indexing (C_Lexique_arxml_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken_comment COMMA_SOURCE_FILE ("arxml_parser.galgas", 210)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxml_5F_parser::rule_arxml_5F_parser_element_i3_ (GALGAS_arxmlNodeList & ioArgument_nodes,
                                                                const GALGAS_bool constinArgument_includeComments,
                                                                const GALGAS_bool constinArgument_doNotCondenseWhiteSpaces,
                                                                C_Lexique_arxml_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken__3C_ COMMA_SOURCE_FILE ("arxml_parser.galgas", 223)) ;
  GALGAS_lstring var_name_6779 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken_name COMMA_SOURCE_FILE ("arxml_parser.galgas", 224)) ;
  GALGAS_arxmlAttributeMap var_attributeMap_6805 = GALGAS_arxmlAttributeMap::constructor_emptyMap (SOURCE_FILE ("arxml_parser.galgas", 225)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    if (select_arxml_5F_parser_2 (inCompiler) == 2) {
      GALGAS_lstring var_attributeName_6872 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken_name COMMA_SOURCE_FILE ("arxml_parser.galgas", 228)) ;
      inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxml_parser.galgas", 229)) ;
      GALGAS_lstring var_attributeValue_6920 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken_value COMMA_SOURCE_FILE ("arxml_parser.galgas", 230)) ;
      {
      var_attributeMap_6805.setter_insertKey (var_attributeName_6872, var_attributeValue_6920, inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 231)) ;
      }
    }else{
      repeatFlag_0 = false ;
    }
  }
  GALGAS_arxmlNodeList var_nodeList_7021 = GALGAS_arxmlNodeList::constructor_emptyList (SOURCE_FILE ("arxml_parser.galgas", 234)) ;
  switch (select_arxml_5F_parser_3 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken__2F__3E_ COMMA_SOURCE_FILE ("arxml_parser.galgas", 236)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxml_parser.galgas", 238)) ;
    nt_element_5F_list_ (var_nodeList_7021, constinArgument_includeComments, constinArgument_doNotCondenseWhiteSpaces, inCompiler) ;
    {
    routine_addText (var_nodeList_7021, constinArgument_doNotCondenseWhiteSpaces, inCompiler  COMMA_SOURCE_FILE ("arxml_parser.galgas", 244)) ;
    }
    inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken__3C__2F_ COMMA_SOURCE_FILE ("arxml_parser.galgas", 246)) ;
    GALGAS_lstring var_closingName_7257 = inCompiler->synthetizedAttribute_tokenString () ;
    inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken_name COMMA_SOURCE_FILE ("arxml_parser.galgas", 247)) ;
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = GALGAS_bool (kIsNotEqual, var_closingName_7257.readProperty_string ().objectCompare (var_name_6779.readProperty_string ())).boolEnum () ;
      if (kBoolTrue == test_1) {
        TC_Array <C_FixItDescription> fixItArray2 ;
        inCompiler->emitSemanticError (var_closingName_7257.readProperty_location (), GALGAS_string ("incorrect closing tag </").add_operation (var_closingName_7257.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 249)).add_operation (GALGAS_string ("> instead of </"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 250)).add_operation (var_name_6779.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 250)).add_operation (GALGAS_string (">"), inCompiler COMMA_SOURCE_FILE ("arxml_parser.galgas", 250)), fixItArray2  COMMA_SOURCE_FILE ("arxml_parser.galgas", 249)) ;
      }
    }
    inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxml_parser.galgas", 252)) ;
  } break ;
  default:
    break ;
  }
  ioArgument_nodes.addAssign_operation (GALGAS_arxmlElementNode::constructor_new (var_name_6779, var_attributeMap_6805, var_nodeList_7021  COMMA_SOURCE_FILE ("arxml_parser.galgas", 255))  COMMA_SOURCE_FILE ("arxml_parser.galgas", 255)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxml_5F_parser::rule_arxml_5F_parser_element_i3_parse (C_Lexique_arxml_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken__3C_ COMMA_SOURCE_FILE ("arxml_parser.galgas", 223)) ;
  inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken_name COMMA_SOURCE_FILE ("arxml_parser.galgas", 224)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    if (select_arxml_5F_parser_2 (inCompiler) == 2) {
      inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken_name COMMA_SOURCE_FILE ("arxml_parser.galgas", 228)) ;
      inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxml_parser.galgas", 229)) ;
      inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken_value COMMA_SOURCE_FILE ("arxml_parser.galgas", 230)) ;
    }else{
      repeatFlag_0 = false ;
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

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxml_5F_parser::rule_arxml_5F_parser_element_i3_indexing (C_Lexique_arxml_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken__3C_ COMMA_SOURCE_FILE ("arxml_parser.galgas", 223)) ;
  inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken_name COMMA_SOURCE_FILE ("arxml_parser.galgas", 224)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    if (select_arxml_5F_parser_2 (inCompiler) == 2) {
      inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken_name COMMA_SOURCE_FILE ("arxml_parser.galgas", 228)) ;
      inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxml_parser.galgas", 229)) ;
      inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken_value COMMA_SOURCE_FILE ("arxml_parser.galgas", 230)) ;
    }else{
      repeatFlag_0 = false ;
    }
  }
  switch (select_arxml_5F_parser_3 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken__2F__3E_ COMMA_SOURCE_FILE ("arxml_parser.galgas", 236)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxml_parser.galgas", 238)) ;
    nt_element_5F_list_indexing (inCompiler) ;
    inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken__3C__2F_ COMMA_SOURCE_FILE ("arxml_parser.galgas", 246)) ;
    inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken_name COMMA_SOURCE_FILE ("arxml_parser.galgas", 247)) ;
    inCompiler->acceptTerminal (C_Lexique_arxml_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxml_parser.galgas", 252)) ;
  } break ;
  default:
    break ;
  }
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
  if (nullptr == mObjectPtr) {
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
  if (nullptr == mObjectPtr) {
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
  if (nullptr == mObjectPtr) {
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
  if (nullptr != mObjectPtr) {
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
  if (nullptr != mObjectPtr) {
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
  if (nullptr != mObjectPtr) {
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
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_arxmlElementNode (mProperty_name, mProperty_attributes, mProperty_enclosedNodes COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @arxmlElementNode generic code implementation
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
  AC_GALGAS_root * result = nullptr ;
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
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_arxmlElementNode *> (p)) {
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
  cEnumerator_arxmlNodeList enumerator_4562 (this->mProperty_enclosedNodes, kENUMERATION_UP) ;
  while (enumerator_4562.hasCurrentObject ()) {
    enumGalgasBool test_0 = kBoolTrue ;
    if (kBoolTrue == test_0) {
      test_0 = GALGAS_bool (enumerator_4562.current_node (HERE).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_arxmlElementNode).boolEnum () ;
      if (kBoolTrue == test_0) {
        GALGAS_arxmlElementNode temp_1 ;
        if (enumerator_4562.current_node (HERE).isValid ()) {
          if (nullptr != dynamic_cast <const cPtr_arxmlElementNode *> (enumerator_4562.current_node (HERE).ptr ())) {
            temp_1 = (cPtr_arxmlElementNode *) enumerator_4562.current_node (HERE).ptr () ;
          }else{
            inCompiler->castError ("arxmlElementNode", enumerator_4562.current_node (HERE).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("arxml_types.galgas", 212)) ;
          }
        }
        GALGAS_arxmlElementNode var_currentElement_4671 = temp_1 ;
        outArgument_nodeList.addAssign_operation (var_currentElement_4671  COMMA_SOURCE_FILE ("arxml_types.galgas", 213)) ;
      }
    }
    enumerator_4562.gotoNextObject () ;
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
  cEnumerator_arxmlNodeList enumerator_5178 (this->mProperty_enclosedNodes, kENUMERATION_UP) ;
  bool bool_0 = ioArgument_found.operator_not (SOURCE_FILE ("arxml_types.galgas", 241)).isValidAndTrue () ;
  if (enumerator_5178.hasCurrentObject () && bool_0) {
    while (enumerator_5178.hasCurrentObject () && bool_0) {
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = GALGAS_bool (enumerator_5178.current_node (HERE).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_arxmlTextNode).boolEnum () ;
        if (kBoolTrue == test_1) {
          GALGAS_arxmlTextNode temp_2 ;
          if (enumerator_5178.current_node (HERE).isValid ()) {
            if (nullptr != dynamic_cast <const cPtr_arxmlTextNode *> (enumerator_5178.current_node (HERE).ptr ())) {
              temp_2 = (cPtr_arxmlTextNode *) enumerator_5178.current_node (HERE).ptr () ;
            }else{
              inCompiler->castError ("arxmlTextNode", enumerator_5178.current_node (HERE).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("arxml_types.galgas", 244)) ;
            }
          }
          GALGAS_arxmlTextNode var_textnode_5293 = temp_2 ;
          callExtensionMethod_getText ((cPtr_arxmlTextNode *) var_textnode_5293.ptr (), ioArgument_value, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 245)) ;
          ioArgument_found = GALGAS_bool (true) ;
        }
      }
      enumerator_5178.gotoNextObject () ;
      if (enumerator_5178.hasCurrentObject ()) {
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
  if (nullptr == mObjectPtr) {
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
  if (nullptr != mObjectPtr) {
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
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_arxmlCommentNode (mProperty_comment COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @arxmlCommentNode generic code implementation
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
  AC_GALGAS_root * result = nullptr ;
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
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_arxmlCommentNode *> (p)) {
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
  if (nullptr == mObjectPtr) {
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
  if (nullptr != mObjectPtr) {
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
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_arxmlTextNode (mProperty_text COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @arxmlTextNode generic code implementation
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
  AC_GALGAS_root * result = nullptr ;
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
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_arxmlTextNode *> (p)) {
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
  if (nullptr == mObjectPtr) {
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
  if (nullptr == mObjectPtr) {
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
  if (nullptr == mObjectPtr) {
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
  if (nullptr == mObjectPtr) {
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
  if (nullptr != mObjectPtr) {
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
  if (nullptr != mObjectPtr) {
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
  if (nullptr != mObjectPtr) {
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
  if (nullptr != mObjectPtr) {
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
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_arxmlElementValue (mProperty_type, mProperty_text, mProperty_elements, mProperty_attributes COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @arxmlElementValue generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_arxmlElementValue ("arxmlElementValue",
                                          nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_arxmlElementValue::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_arxmlElementValue ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_arxmlElementValue::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
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
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_arxmlElementValue *> (p)) {
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
  gExtensionModifierTable_arxmlElementValue_insertElement.forceObjectAtIndex (inClassIndex, inModifier, nullptr COMMA_HERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionSetter_insertElement (cPtr_arxmlElementValue * inObject,
                                        GALGAS_lstring in_key,
                                        GALGAS_arxmlElementValue in_element,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_arxmlElementValue) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_arxmlElementValue_insertElement f = nullptr ;
    if (classIndex < gExtensionModifierTable_arxmlElementValue_insertElement.count ()) {
      f = gExtensionModifierTable_arxmlElementValue_insertElement (classIndex COMMA_HERE) ;
    }
    if (nullptr == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((nullptr == f) && (nullptr != p)) {
         if (p->mSlotID < gExtensionModifierTable_arxmlElementValue_insertElement.count ()) {
           f = gExtensionModifierTable_arxmlElementValue_insertElement (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_arxmlElementValue_insertElement.forceObjectAtIndex (classIndex, f, nullptr COMMA_HERE) ;
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
  GALGAS_arxmlElementValueList var_keyList_8394 ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = object->mProperty_elements.getter_hasKey (inArgument_key.readProperty_string () COMMA_SOURCE_FILE ("arxml_types.galgas", 385)).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      object->mProperty_elements.setter_removeKey (inArgument_key, var_keyList_8394, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 386)) ;
      }
    }
  }
  if (kBoolFalse == test_0) {
    var_keyList_8394 = GALGAS_arxmlElementValueList::constructor_emptyList (SOURCE_FILE ("arxml_types.galgas", 388)) ;
  }
  var_keyList_8394.addAssign_operation (inArgument_element  COMMA_SOURCE_FILE ("arxml_types.galgas", 390)) ;
  {
  object->mProperty_elements.setter_insertKey (inArgument_key, var_keyList_8394, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 391)) ;
  }
}
//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionSetter_arxmlElementValue_insertElement (void) {
  enterExtensionSetter_insertElement (kTypeDescriptor_GALGAS_arxmlElementValue.mSlotID,
                                      extensionSetter_arxmlElementValue_insertElement) ;
}

//----------------------------------------------------------------------------------------------------------------------

static void freeExtensionModifier_arxmlElementValue_insertElement (void) {
  gExtensionModifierTable_arxmlElementValue_insertElement.removeAll () ;
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
    test_0 = GALGAS_bool (kIsEqual, inArgument_path.getter_count (SOURCE_FILE ("arxml_types.galgas", 398)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      const GALGAS_arxmlElementValue temp_1 = this ;
      ioArgument_outElements.addAssign_operation (temp_1  COMMA_SOURCE_FILE ("arxml_types.galgas", 399)) ;
    }
  }
  if (kBoolFalse == test_0) {
    GALGAS_stringlist var_pathCopy_8752 = inArgument_path ;
    GALGAS_string var_nextInPathName_8784 ;
    GALGAS_arxmlElementValueList var_nextInPathElems_8830 ;
    {
    var_pathCopy_8752.setter_popFirst (var_nextInPathName_8784, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 404)) ;
    }
    const GALGAS_arxmlElementValue temp_2 = this ;
    callExtensionMethod_getElements ((cPtr_arxmlElementValue *) temp_2.ptr (), var_nextInPathName_8784, var_nextInPathElems_8830, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 405)) ;
    cEnumerator_arxmlElementValueList enumerator_8971 (var_nextInPathElems_8830, kENUMERATION_UP) ;
    while (enumerator_8971.hasCurrentObject ()) {
      callExtensionMethod_getElementsByPath ((cPtr_arxmlElementValue *) enumerator_8971.current_value (HERE).ptr (), var_pathCopy_8752, ioArgument_outElements, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 407)) ;
      enumerator_8971.gotoNextObject () ;
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
  GALGAS_lstring var_key_9195 = GALGAS_lstring::constructor_new (inArgument_elementName, GALGAS_location::constructor_nowhere (SOURCE_FILE ("arxml_types.galgas", 416))  COMMA_SOURCE_FILE ("arxml_types.galgas", 416)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = this->mProperty_elements.getter_hasKey (var_key_9195.readProperty_string () COMMA_SOURCE_FILE ("arxml_types.galgas", 417)).boolEnum () ;
    if (kBoolTrue == test_0) {
      this->mProperty_elements.method_searchKey (var_key_9195, outArgument_outElements, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 418)) ;
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
  GALGAS_arxmlElementValueList var_foundElements_9467 ;
  const GALGAS_arxmlElementValue temp_0 = this ;
  callExtensionMethod_getElements ((cPtr_arxmlElementValue *) temp_0.ptr (), inArgument_elementName, var_foundElements_9467, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 429)) ;
  enumGalgasBool test_1 = kBoolTrue ;
  if (kBoolTrue == test_1) {
    test_1 = GALGAS_bool (kIsNotEqual, var_foundElements_9467.getter_count (SOURCE_FILE ("arxml_types.galgas", 430)).objectCompare (GALGAS_uint (uint32_t (1U)))).boolEnum () ;
    if (kBoolTrue == test_1) {
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxml_types.galgas", 431)), GALGAS_string ("Found ").add_operation (var_foundElements_9467.getter_count (SOURCE_FILE ("arxml_types.galgas", 431)).getter_string (SOURCE_FILE ("arxml_types.galgas", 431)), inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 431)).add_operation (GALGAS_string (" elements"), inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 431)).add_operation (GALGAS_string (" while searching for exactly one "), inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 431)).add_operation (inArgument_elementName, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 432)).add_operation (GALGAS_string (" in "), inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 432)).add_operation (this->mProperty_type.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 433)), fixItArray2  COMMA_SOURCE_FILE ("arxml_types.galgas", 431)) ;
      outArgument_outElement.drop () ; // Release error dropped variable
    }
  }
  if (kBoolFalse == test_1) {
    var_foundElements_9467.method_first (outArgument_outElement, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 435)) ;
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
  GALGAS_arxmlElementValueList var_foundElements_9920 ;
  const GALGAS_arxmlElementValue temp_0 = this ;
  callExtensionMethod_getElements ((cPtr_arxmlElementValue *) temp_0.ptr (), inArgument_elementName, var_foundElements_9920, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 444)) ;
  enumGalgasBool test_1 = kBoolTrue ;
  if (kBoolTrue == test_1) {
    test_1 = GALGAS_bool (kIsNotEqual, var_foundElements_9920.getter_count (SOURCE_FILE ("arxml_types.galgas", 445)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
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
  GALGAS_arxmlElementValue var_textElement_10193 ;
  const GALGAS_arxmlElementValue temp_0 = this ;
  callExtensionMethod_getElement ((cPtr_arxmlElementValue *) temp_0.ptr (), inArgument_elementName, var_textElement_10193, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 457)) ;
  result_outText = var_textElement_10193.readProperty_text () ;
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
  cEnumerator_arxmlElementValueMap enumerator_10633 (this->mProperty_elements, kENUMERATION_UP) ;
  while (enumerator_10633.hasCurrentObject ()) {
    cEnumerator_arxmlElementValueList enumerator_10659 (enumerator_10633.current_values (HERE), kENUMERATION_UP) ;
    while (enumerator_10659.hasCurrentObject ()) {
      callExtensionMethod_getAllTextsInSelf ((cPtr_arxmlElementValue *) enumerator_10659.current_value (HERE).ptr (), inArgument_separator, ioArgument_outString, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 477)) ;
      enumerator_10659.gotoNextObject () ;
    }
    enumerator_10633.gotoNextObject () ;
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
  GALGAS_arxmlElementValue var_textElement_10899 ;
  const GALGAS_arxmlElementValue temp_0 = this ;
  callExtensionMethod_getElement ((cPtr_arxmlElementValue *) temp_0.ptr (), inArgument_elementName, var_textElement_10899, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 488)) ;
  GALGAS_lstring var_attributeNamelString_10972 = GALGAS_lstring::constructor_new (inArgument_attributeName, GALGAS_location::constructor_nowhere (SOURCE_FILE ("arxml_types.galgas", 489))  COMMA_SOURCE_FILE ("arxml_types.galgas", 489)) ;
  var_textElement_10899.readProperty_attributes ().method_searchKey (var_attributeNamelString_10972, result_outText, inCompiler COMMA_SOURCE_FILE ("arxml_types.galgas", 490)) ;
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
  if (nullptr == mObjectPtr) {
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
  if (nullptr == mObjectPtr) {
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
  if (nullptr == mObjectPtr) {
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
  if (nullptr == mObjectPtr) {
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
  if (nullptr == mObjectPtr) {
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
  if (nullptr == mObjectPtr) {
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
  if (nullptr == mObjectPtr) {
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
  if (nullptr != mObjectPtr) {
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
  if (nullptr != mObjectPtr) {
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
  if (nullptr != mObjectPtr) {
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
  if (nullptr != mObjectPtr) {
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
  if (nullptr != mObjectPtr) {
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
  if (nullptr != mObjectPtr) {
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
  if (nullptr != mObjectPtr) {
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
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_arxmlMetaClass (mProperty_name, mProperty_isAbstract, mProperty_lElement, mProperty_lElementLegacy, mProperty_lAttribute, mProperty_lAttributeLegacy, mProperty_desc COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @arxmlMetaClass generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_arxmlMetaClass ("arxmlMetaClass",
                                       nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_arxmlMetaClass::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_arxmlMetaClass ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_arxmlMetaClass::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
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
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_arxmlMetaClass *> (p)) {
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
  gExtensionModifierTable_arxmlMetaClass_legacyAddParameters.forceObjectAtIndex (inClassIndex, inModifier, nullptr COMMA_HERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionSetter_legacyAddParameters (cPtr_arxmlMetaClass * inObject,
                                              GALGAS_arxmlMetaClassMap & io_classMap,
                                              GALGAS_lstringlist in_successors,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_arxmlMetaClass) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_arxmlMetaClass_legacyAddParameters f = nullptr ;
    if (classIndex < gExtensionModifierTable_arxmlMetaClass_legacyAddParameters.count ()) {
      f = gExtensionModifierTable_arxmlMetaClass_legacyAddParameters (classIndex COMMA_HERE) ;
    }
    if (nullptr == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((nullptr == f) && (nullptr != p)) {
         if (p->mSlotID < gExtensionModifierTable_arxmlMetaClass_legacyAddParameters.count ()) {
           f = gExtensionModifierTable_arxmlMetaClass_legacyAddParameters (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_arxmlMetaClass_legacyAddParameters.forceObjectAtIndex (classIndex, f, nullptr COMMA_HERE) ;
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
  cEnumerator_lstringlist enumerator_2549 (inArgument_successors, kENUMERATION_UP) ;
  while (enumerator_2549.hasCurrentObject ()) {
    {
    extensionSetter_updateLegacyParameters (ioArgument_classMap, enumerator_2549.current_mValue (HERE), object->mProperty_lElement, object->mProperty_lAttribute, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 95)) ;
    }
    enumerator_2549.gotoNextObject () ;
  }
}
//----------------------------------------------------------------------------------------------------------------------

static void defineExtensionSetter_arxmlMetaClass_legacyAddParameters (void) {
  enterExtensionSetter_legacyAddParameters (kTypeDescriptor_GALGAS_arxmlMetaClass.mSlotID,
                                            extensionSetter_arxmlMetaClass_legacyAddParameters) ;
}

//----------------------------------------------------------------------------------------------------------------------

static void freeExtensionModifier_arxmlMetaClass_legacyAddParameters (void) {
  gExtensionModifierTable_arxmlMetaClass_legacyAddParameters.removeAll () ;
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
  gExtensionModifierTable_arxmlMetaClass_legacyUpdate.forceObjectAtIndex (inClassIndex, inModifier, nullptr COMMA_HERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionSetter_legacyUpdate (cPtr_arxmlMetaClass * inObject,
                                       GALGAS_arxmlMetaElementList in_iElement,
                                       GALGAS_arxmlMetaAttributeList in_iAttribute,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_arxmlMetaClass) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_arxmlMetaClass_legacyUpdate f = nullptr ;
    if (classIndex < gExtensionModifierTable_arxmlMetaClass_legacyUpdate.count ()) {
      f = gExtensionModifierTable_arxmlMetaClass_legacyUpdate (classIndex COMMA_HERE) ;
    }
    if (nullptr == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((nullptr == f) && (nullptr != p)) {
         if (p->mSlotID < gExtensionModifierTable_arxmlMetaClass_legacyUpdate.count ()) {
           f = gExtensionModifierTable_arxmlMetaClass_legacyUpdate (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_arxmlMetaClass_legacyUpdate.forceObjectAtIndex (classIndex, f, nullptr COMMA_HERE) ;
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
  gExtensionModifierTable_arxmlMetaClass_legacyUpdate.removeAll () ;
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
  GALGAS_string var_svgString_2952 = GALGAS_string::makeEmptyString () ;
  GALGAS_string var_classNameRepr_2981 = this->mProperty_name.readProperty_string () ;
  var_svgString_2952.plusAssign_operation(GALGAS_string ("############################################################\n"), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 116)) ;
  var_svgString_2952.plusAssign_operation(GALGAS_string ("# ").add_operation (this->mProperty_name.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 117)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 117)), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 117)) ;
  var_svgString_2952.plusAssign_operation(GALGAS_string ("# <").add_operation (this->mProperty_desc.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 118)).add_operation (GALGAS_string (">\n"), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 118)), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 118)) ;
  var_svgString_2952.plusAssign_operation(GALGAS_string ("#\n"), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 119)) ;
  var_svgString_2952.plusAssign_operation(GALGAS_string ("list @").add_operation (var_classNameRepr_2981, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 122)).add_operation (GALGAS_string ("list\n{\n"), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 122)), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 122)) ;
  var_svgString_2952.plusAssign_operation(GALGAS_string ("  @").add_operation (var_classNameRepr_2981, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 123)).add_operation (GALGAS_string (" elem\n"), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 123)), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 123)) ;
  var_svgString_2952.plusAssign_operation(GALGAS_string ("}\n"), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 124)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = this->mProperty_isAbstract.boolEnum () ;
    if (kBoolTrue == test_0) {
      var_svgString_2952.plusAssign_operation(GALGAS_string ("abstract "), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 128)) ;
    }
  }
  var_svgString_2952.plusAssign_operation(GALGAS_string ("class @").add_operation (var_classNameRepr_2981, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 132)).add_operation (GALGAS_string ("\n{\n"), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 132)), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 132)) ;
  cEnumerator_arxmlMetaElementList enumerator_3686 (this->mProperty_lElementLegacy, kENUMERATION_UP) ;
  while (enumerator_3686.hasCurrentObject ()) {
    GALGAS_string var_elemTypeRepr_3733 = enumerator_3686.current_lElement (HERE).readProperty_type ().readProperty_string () ;
    GALGAS_string var_elemNameRepr_3787 = enumerator_3686.current_lElement (HERE).readProperty_name ().readProperty_string () ;
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = GALGAS_bool (kIsEqual, enumerator_3686.current_lElement (HERE).readProperty_type ().readProperty_string ().objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
      if (kBoolTrue == test_1) {
        TC_Array <C_FixItDescription> fixItArray2 ;
        inCompiler->emitSemanticWarning (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 142)), GALGAS_string ("Missing element's type : ").add_operation (var_elemNameRepr_3787, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 142)), fixItArray2  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 142)) ;
      }
    }
    var_svgString_2952.plusAssign_operation(GALGAS_string ("  @").add_operation (var_elemTypeRepr_3733, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 168)), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 168)) ;
    enumGalgasBool test_3 = kBoolTrue ;
    if (kBoolTrue == test_3) {
      GALGAS_bool test_4 = GALGAS_bool (kIsNotEqual, enumerator_3686.current_lElement (HERE).readProperty_minOccurs ().readProperty_string ().objectCompare (enumerator_3686.current_lElement (HERE).readProperty_maxOccurs ().readProperty_string ())) ;
      if (kBoolTrue != test_4.boolEnum ()) {
        test_4 = GALGAS_bool (kIsNotEqual, enumerator_3686.current_lElement (HERE).readProperty_minOccurs ().readProperty_string ().objectCompare (GALGAS_string ("1"))) ;
      }
      test_3 = test_4.boolEnum () ;
      if (kBoolTrue == test_3) {
        var_svgString_2952.plusAssign_operation(GALGAS_string ("list"), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 175)) ;
      }
    }
    var_svgString_2952.plusAssign_operation(GALGAS_string (" elem").add_operation (var_elemNameRepr_3787, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 179)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 179)), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 179)) ;
    enumerator_3686.gotoNextObject () ;
  }
  cEnumerator_arxmlMetaAttributeList enumerator_5316 (this->mProperty_lAttributeLegacy, kENUMERATION_UP) ;
  while (enumerator_5316.hasCurrentObject ()) {
    GALGAS_string var_attrTypeRepr_5367 = enumerator_5316.current_lAttribute (HERE).readProperty_type ().readProperty_string () ;
    GALGAS_string var_attrNameRepr_5423 = enumerator_5316.current_lAttribute (HERE).readProperty_name ().readProperty_string () ;
    enumGalgasBool test_5 = kBoolTrue ;
    if (kBoolTrue == test_5) {
      test_5 = GALGAS_bool (kIsNotEqual, enumerator_5316.current_lAttribute (HERE).readProperty_type ().readProperty_string ().objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
      if (kBoolTrue == test_5) {
      }
    }
    var_svgString_2952.plusAssign_operation(GALGAS_string ("  @").add_operation (var_attrTypeRepr_5367, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 218)).add_operation (GALGAS_string (" "), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 218)).add_operation (var_attrNameRepr_5423, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 218)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 218)), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 218)) ;
    enumGalgasBool test_6 = kBoolTrue ;
    if (kBoolTrue == test_6) {
      GALGAS_bool test_7 = GALGAS_bool (kIsEqual, enumerator_5316.current_lAttribute (HERE).readProperty_use ().readProperty_string ().objectCompare (GALGAS_string::makeEmptyString ())) ;
      if (kBoolTrue != test_7.boolEnum ()) {
        test_7 = GALGAS_bool (kIsEqual, enumerator_5316.current_lAttribute (HERE).readProperty_use ().readProperty_string ().objectCompare (GALGAS_string ("optional"))) ;
      }
      test_6 = test_7.boolEnum () ;
      if (kBoolTrue == test_6) {
        var_svgString_2952.plusAssign_operation(GALGAS_string ("list"), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 225)) ;
      }
    }
    var_svgString_2952.plusAssign_operation(GALGAS_string (" attr").add_operation (var_attrNameRepr_5423, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 229)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 229)), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 229)) ;
    enumerator_5316.gotoNextObject () ;
  }
  var_svgString_2952.plusAssign_operation(GALGAS_string ("}\n\n"), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 232)) ;
  ioArgument_ioString = ioArgument_ioString.add_operation (var_svgString_2952, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 233)) ;
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
  gExtensionModifierTable_arxmlMetaClass_addElement.forceObjectAtIndex (inClassIndex, inModifier, nullptr COMMA_HERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionSetter_addElement (cPtr_arxmlMetaClass * inObject,
                                     GALGAS_arxmlMetaElement in_mElement,
                                     C_Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_arxmlMetaClass) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_arxmlMetaClass_addElement f = nullptr ;
    if (classIndex < gExtensionModifierTable_arxmlMetaClass_addElement.count ()) {
      f = gExtensionModifierTable_arxmlMetaClass_addElement (classIndex COMMA_HERE) ;
    }
    if (nullptr == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((nullptr == f) && (nullptr != p)) {
         if (p->mSlotID < gExtensionModifierTable_arxmlMetaClass_addElement.count ()) {
           f = gExtensionModifierTable_arxmlMetaClass_addElement (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_arxmlMetaClass_addElement.forceObjectAtIndex (classIndex, f, nullptr COMMA_HERE) ;
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
  GALGAS_bool var_exists_7176 = GALGAS_bool (false) ;
  cEnumerator_arxmlMetaElementList enumerator_7216 (object->mProperty_lElement, kENUMERATION_UP) ;
  while (enumerator_7216.hasCurrentObject ()) {
    enumGalgasBool test_0 = kBoolTrue ;
    if (kBoolTrue == test_0) {
      GALGAS_bool test_1 = GALGAS_bool (kIsEqual, enumerator_7216.current_lElement (HERE).readProperty_name ().readProperty_string ().objectCompare (inArgument_mElement.readProperty_name ().readProperty_string ())) ;
      if (kBoolTrue == test_1.boolEnum ()) {
        test_1 = GALGAS_bool (kIsEqual, enumerator_7216.current_lElement (HERE).readProperty_type ().readProperty_string ().objectCompare (inArgument_mElement.readProperty_type ().readProperty_string ())) ;
      }
      test_0 = test_1.boolEnum () ;
      if (kBoolTrue == test_0) {
        var_exists_7176 = GALGAS_bool (true) ;
      }
    }
    enumerator_7216.gotoNextObject () ;
  }
  enumGalgasBool test_2 = kBoolTrue ;
  if (kBoolTrue == test_2) {
    test_2 = var_exists_7176.operator_not (SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 245)).boolEnum () ;
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
  gExtensionModifierTable_arxmlMetaClass_addElement.removeAll () ;
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
  gExtensionModifierTable_arxmlMetaClass_addAttribute.forceObjectAtIndex (inClassIndex, inModifier, nullptr COMMA_HERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionSetter_addAttribute (cPtr_arxmlMetaClass * inObject,
                                       GALGAS_arxmlMetaAttribute in_mAttribute,
                                       C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_arxmlMetaClass) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_arxmlMetaClass_addAttribute f = nullptr ;
    if (classIndex < gExtensionModifierTable_arxmlMetaClass_addAttribute.count ()) {
      f = gExtensionModifierTable_arxmlMetaClass_addAttribute (classIndex COMMA_HERE) ;
    }
    if (nullptr == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((nullptr == f) && (nullptr != p)) {
         if (p->mSlotID < gExtensionModifierTable_arxmlMetaClass_addAttribute.count ()) {
           f = gExtensionModifierTable_arxmlMetaClass_addAttribute (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_arxmlMetaClass_addAttribute.forceObjectAtIndex (classIndex, f, nullptr COMMA_HERE) ;
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
  GALGAS_bool var_exists_7527 = GALGAS_bool (false) ;
  cEnumerator_arxmlMetaAttributeList enumerator_7569 (object->mProperty_lAttribute, kENUMERATION_UP) ;
  while (enumerator_7569.hasCurrentObject ()) {
    enumGalgasBool test_0 = kBoolTrue ;
    if (kBoolTrue == test_0) {
      GALGAS_bool test_1 = GALGAS_bool (kIsEqual, enumerator_7569.current_lAttribute (HERE).readProperty_name ().readProperty_string ().objectCompare (inArgument_mAttribute.readProperty_name ().readProperty_string ())) ;
      if (kBoolTrue == test_1.boolEnum ()) {
        test_1 = GALGAS_bool (kIsEqual, enumerator_7569.current_lAttribute (HERE).readProperty_type ().readProperty_string ().objectCompare (inArgument_mAttribute.readProperty_type ().readProperty_string ())) ;
      }
      test_0 = test_1.boolEnum () ;
      if (kBoolTrue == test_0) {
        var_exists_7527 = GALGAS_bool (true) ;
      }
    }
    enumerator_7569.gotoNextObject () ;
  }
  enumGalgasBool test_2 = kBoolTrue ;
  if (kBoolTrue == test_2) {
    test_2 = var_exists_7527.operator_not (SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 259)).boolEnum () ;
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
  gExtensionModifierTable_arxmlMetaClass_addAttribute.removeAll () ;
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
  gExtensionModifierTable_arxmlMetaClass_setDescription.forceObjectAtIndex (inClassIndex, inModifier, nullptr COMMA_HERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionSetter_setDescription (cPtr_arxmlMetaClass * inObject,
                                         GALGAS_lstring in_iDesc,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_arxmlMetaClass) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_arxmlMetaClass_setDescription f = nullptr ;
    if (classIndex < gExtensionModifierTable_arxmlMetaClass_setDescription.count ()) {
      f = gExtensionModifierTable_arxmlMetaClass_setDescription (classIndex COMMA_HERE) ;
    }
    if (nullptr == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((nullptr == f) && (nullptr != p)) {
         if (p->mSlotID < gExtensionModifierTable_arxmlMetaClass_setDescription.count ()) {
           f = gExtensionModifierTable_arxmlMetaClass_setDescription (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_arxmlMetaClass_setDescription.forceObjectAtIndex (classIndex, f, nullptr COMMA_HERE) ;
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
  gExtensionModifierTable_arxmlMetaClass_setDescription.removeAll () ;
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
  GALGAS_bool var_found_7972 = GALGAS_bool (false) ;
  cEnumerator_arxmlMetaElementList enumerator_8012 (this->mProperty_lElementLegacy, kENUMERATION_UP) ;
  bool bool_0 = var_found_7972.operator_not (SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 275)).isValidAndTrue () ;
  if (enumerator_8012.hasCurrentObject () && bool_0) {
    while (enumerator_8012.hasCurrentObject () && bool_0) {
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = GALGAS_bool (kIsEqual, inArgument_eleName.objectCompare (enumerator_8012.current_lElement (HERE).readProperty_name ().readProperty_string ())).boolEnum () ;
        if (kBoolTrue == test_1) {
          var_found_7972 = GALGAS_bool (true) ;
        }
      }
      enumerator_8012.gotoNextObject () ;
      if (enumerator_8012.hasCurrentObject ()) {
        bool_0 = var_found_7972.operator_not (SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 275)).isValidAndTrue () ;
      }
    }
  }
  result_oFound = var_found_7972 ;
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
  GALGAS_bool var_found_8256 = GALGAS_bool (false) ;
  cEnumerator_arxmlMetaAttributeList enumerator_8298 (this->mProperty_lAttributeLegacy, kENUMERATION_UP) ;
  bool bool_0 = var_found_8256.operator_not (SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 290)).isValidAndTrue () ;
  if (enumerator_8298.hasCurrentObject () && bool_0) {
    while (enumerator_8298.hasCurrentObject () && bool_0) {
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = GALGAS_bool (kIsEqual, inArgument_attrName.objectCompare (enumerator_8298.current_lAttribute (HERE).readProperty_name ().readProperty_string ())).boolEnum () ;
        if (kBoolTrue == test_1) {
          var_found_8256 = GALGAS_bool (true) ;
        }
      }
      enumerator_8298.gotoNextObject () ;
      if (enumerator_8298.hasCurrentObject ()) {
        bool_0 = var_found_8256.operator_not (SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 290)).isValidAndTrue () ;
      }
    }
  }
  result_oFound = var_found_8256 ;
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
  if (nullptr == mObjectPtr) {
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
  if (nullptr == mObjectPtr) {
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
  if (nullptr == mObjectPtr) {
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
  if (nullptr == mObjectPtr) {
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
  if (nullptr == mObjectPtr) {
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
  if (nullptr != mObjectPtr) {
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
  if (nullptr != mObjectPtr) {
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
  if (nullptr != mObjectPtr) {
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
  if (nullptr != mObjectPtr) {
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
  if (nullptr != mObjectPtr) {
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
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_arxmlMetaElement (mProperty_name, mProperty_type, mProperty_minOccurs, mProperty_maxOccurs, mProperty_prefix COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @arxmlMetaElement generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_arxmlMetaElement ("arxmlMetaElement",
                                         nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_arxmlMetaElement::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_arxmlMetaElement ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_arxmlMetaElement::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
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
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_arxmlMetaElement *> (p)) {
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
  if (nullptr == mObjectPtr) {
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
  if (nullptr == mObjectPtr) {
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
  if (nullptr == mObjectPtr) {
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
  if (nullptr == mObjectPtr) {
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
  if (nullptr != mObjectPtr) {
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
  if (nullptr != mObjectPtr) {
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
  if (nullptr != mObjectPtr) {
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
  if (nullptr != mObjectPtr) {
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
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_arxmlMetaAttribute (mProperty_name, mProperty_type, mProperty_prefix, mProperty_use COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @arxmlMetaAttribute generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_arxmlMetaAttribute ("arxmlMetaAttribute",
                                           nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_arxmlMetaAttribute::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_arxmlMetaAttribute ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_arxmlMetaAttribute::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
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
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_arxmlMetaAttribute *> (p)) {
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
  if (nullptr == mObjectPtr) {
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
  if (nullptr == mObjectPtr) {
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
  if (nullptr == mObjectPtr) {
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
  if (nullptr == mObjectPtr) {
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
  if (nullptr != mObjectPtr) {
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
  if (nullptr != mObjectPtr) {
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
  if (nullptr != mObjectPtr) {
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
  if (nullptr != mObjectPtr) {
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
  acPtr_class * ptr = nullptr ;
  macroMyNew (ptr, cPtr_arxmlMetaSimpletype (mProperty_name, mProperty_type, mProperty_base, mProperty_values COMMA_THERE)) ;
  return ptr ;
}


//----------------------------------------------------------------------------------------------------------------------
//
//     @arxmlMetaSimpletype generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_arxmlMetaSimpletype ("arxmlMetaSimpletype",
                                            nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_arxmlMetaSimpletype::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_arxmlMetaSimpletype ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_arxmlMetaSimpletype::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
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
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_arxmlMetaSimpletype *> (p)) {
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
  GALGAS_string var_svgString_9978 = GALGAS_string::makeEmptyString () ;
  GALGAS_string var_typeNameRepr_10007 = this->mProperty_name.readProperty_string () ;
  var_svgString_9978.plusAssign_operation(GALGAS_string ("############################################################\n"), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 373)) ;
  var_svgString_9978.plusAssign_operation(GALGAS_string ("# ").add_operation (this->mProperty_name.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 374)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 374)), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 374)) ;
  switch (this->mProperty_type.enumValue ()) {
  case GALGAS_restrictionType::kNotBuilt:
    break ;
  case GALGAS_restrictionType::kEnum_restrictionSimple:
    {
    }
    break ;
  case GALGAS_restrictionType::kEnum_restrictionEnum:
    {
      var_svgString_9978.plusAssign_operation(GALGAS_string ("list @").add_operation (var_typeNameRepr_10007, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 381)).add_operation (GALGAS_string ("list\n{\n"), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 381)), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 381)) ;
      var_svgString_9978.plusAssign_operation(GALGAS_string ("  @").add_operation (var_typeNameRepr_10007, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 382)).add_operation (GALGAS_string (" elem\n"), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 382)), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 382)) ;
      var_svgString_9978.plusAssign_operation(GALGAS_string ("}\n"), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 383)) ;
      var_svgString_9978.plusAssign_operation(GALGAS_string ("enum @").add_operation (var_typeNameRepr_10007, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 385)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 385)), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 385)) ;
      var_svgString_9978.plusAssign_operation(GALGAS_string ("{\n"), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 386)) ;
      cEnumerator_lstringlist enumerator_10667 (this->mProperty_values, kENUMERATION_UP) ;
      while (enumerator_10667.hasCurrentObject ()) {
        GALGAS_string var_valueRepr_10707 = enumerator_10667.current_mValue (HERE).readProperty_string () ;
        var_svgString_9978.plusAssign_operation(GALGAS_string ("  case case").add_operation (var_valueRepr_10707, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 390)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 390)), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 390)) ;
        enumerator_10667.gotoNextObject () ;
      }
      var_svgString_9978.plusAssign_operation(GALGAS_string ("}\n"), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 392)) ;
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
  ioArgument_ioString = ioArgument_ioString.add_operation (var_svgString_9978, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_semantics.galgas", 399)) ;
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
  gExtensionModifierTable_arxmlMetaSimpletype_addValue.forceObjectAtIndex (inClassIndex, inModifier, nullptr COMMA_HERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

void callExtensionSetter_addValue (cPtr_arxmlMetaSimpletype * inObject,
                                   GALGAS_lstring in_value,
                                   C_Compiler * inCompiler
                                   COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (nullptr != inObject) {
    macroValidSharedObject (inObject, cPtr_arxmlMetaSimpletype) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_arxmlMetaSimpletype_addValue f = nullptr ;
    if (classIndex < gExtensionModifierTable_arxmlMetaSimpletype_addValue.count ()) {
      f = gExtensionModifierTable_arxmlMetaSimpletype_addValue (classIndex COMMA_HERE) ;
    }
    if (nullptr == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((nullptr == f) && (nullptr != p)) {
         if (p->mSlotID < gExtensionModifierTable_arxmlMetaSimpletype_addValue.count ()) {
           f = gExtensionModifierTable_arxmlMetaSimpletype_addValue (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_arxmlMetaSimpletype_addValue.forceObjectAtIndex (classIndex, f, nullptr COMMA_HERE) ;
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
  gExtensionModifierTable_arxmlMetaSimpletype_addValue.removeAll () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gSetter_arxmlMetaSimpletype_addValue (defineExtensionSetter_arxmlMetaSimpletype_addValue,
                                                         freeExtensionModifier_arxmlMetaSimpletype_addValue) ;



//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_arxmlmetaparser_5F_start_5F_symbol_i0_ (GALGAS_arxmlMetaClassMap & outArgument_iClassMap,
                                                                                                               GALGAS_bool inArgument_create_5F_class_5F_file,
                                                                                                               C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  outArgument_iClassMap.drop () ; // Release 'out' argument
  GALGAS_arxmlMetaClassMap var_classMap_957 = GALGAS_arxmlMetaClassMap::constructor_emptyMap (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 35)) ;
  GALGAS_arxmlMetaClassGraph var_classGraph_994 = GALGAS_arxmlMetaClassGraph::constructor_emptyGraph (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 36)) ;
  nt_xml_5F_header_ (inCompiler) ;
  nt_xsd_5F_schema_ (var_classMap_957, var_classGraph_994, inCompiler) ;
  {
  routine_fillLegacy (var_classMap_957, var_classGraph_994, inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 43)) ;
  }
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = inArgument_create_5F_class_5F_file.boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_string var_classString_1295 = GALGAS_string::makeEmptyString () ;
      extensionMethod_display (var_classMap_957, var_classString_1295, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 49)) ;
      var_classString_1295.method_writeToFile (GALGAS_string ("arxml_ecuc_classes.galgas"), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 50)) ;
      GALGAS_string var_graphString_1442 = var_classGraph_994.getter_graphviz (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 53)) ;
      var_graphString_1442.method_writeToFile (GALGAS_string ("arxml_ecuc_graph.dot"), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 54)) ;
    }
  }
  outArgument_iClassMap = var_classMap_957 ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_arxmlmetaparser_5F_start_5F_symbol_i0_parse (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  nt_xml_5F_header_parse (inCompiler) ;
  nt_xsd_5F_schema_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_arxmlmetaparser_5F_start_5F_symbol_i0_indexing (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  nt_xml_5F_header_indexing (inCompiler) ;
  nt_xsd_5F_schema_indexing (inCompiler) ;
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

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xml_5F_header_i1_indexing (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__3F_xml COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 63)) ;
  nt_xsd_5F_ignore_5F_attributes_indexing (inCompiler) ;
  inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3F__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 65)) ;
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
      if (select_arxmlmetaparser_5F_syntax_1 (inCompiler) == 2) {
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
      }else{
        repeatFlag_0 = false ;
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
      if (select_arxmlmetaparser_5F_syntax_1 (inCompiler) == 2) {
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
      }else{
        repeatFlag_0 = false ;
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

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_annotation_i2_indexing (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  nt_xsd_5F_ignore_5F_attributes_indexing (inCompiler) ;
  switch (select_arxmlmetaparser_5F_syntax_0 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 81)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      if (select_arxmlmetaparser_5F_syntax_1 (inCompiler) == 2) {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 83)) ;
        switch (select_arxmlmetaparser_5F_syntax_2 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_appinfo COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 84)) ;
          nt_xsd_5F_appinfo_indexing (inCompiler) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_documentation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 86)) ;
          nt_xsd_5F_documentation_indexing (inCompiler) ;
        } break ;
        default:
          break ;
        }
      }else{
        repeatFlag_0 = false ;
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

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_appinfo_i3_indexing (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  nt_xsd_5F_ignore_5F_attributes_indexing (inCompiler) ;
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

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_attribute_i4_ (GALGAS_arxmlMetaClassMap & ioArgument_classMap,
                                                                                             GALGAS_arxmlMetaClassGraph & ioArgument_classGraph,
                                                                                             GALGAS_lstring inArgument_parentClass,
                                                                                             C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  GALGAS_lstring var_attributeType_2961 ;
  {
  routine_lstringhere (var_attributeType_2961, GALGAS_string::makeEmptyString (), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 123)) ;
  }
  GALGAS_lstring var_attributeName_3004 ;
  {
  routine_lstringhere (var_attributeName_3004, GALGAS_string::makeEmptyString (), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 124)) ;
  }
  GALGAS_lstring var_attributeRef_3047 ;
  {
  routine_lstringhere (var_attributeRef_3047, GALGAS_string::makeEmptyString (), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 125)) ;
  }
  GALGAS_lstring var_attributePrefix_3090 ;
  {
  routine_lstringhere (var_attributePrefix_3090, GALGAS_string::makeEmptyString (), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 126)) ;
  }
  GALGAS_lstring var_attributeUse_3136 ;
  {
  routine_lstringhere (var_attributeUse_3136, GALGAS_string::makeEmptyString (), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 127)) ;
  }
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_arxmlmetaparser_5F_syntax_4 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_ref COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 130)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 132)) ;
      var_attributeRef_3047 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 133)) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_type COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 134)) ;
      GALGAS_lstring var_fullType_3316 ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 136)) ;
      var_fullType_3316 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 137)) ;
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = var_fullType_3316.readProperty_string ().getter_containsCharacter (GALGAS_char (TO_UNICODE (58)) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 139)).boolEnum () ;
        if (kBoolTrue == test_1) {
          GALGAS_stringlist var_parsed_3485 = var_fullType_3316.readProperty_string ().getter_componentsSeparatedByString (GALGAS_string (":") COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 140)) ;
          GALGAS_string var_parsedString_3559 ;
          var_parsed_3485.method_first (var_parsedString_3559, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 142)) ;
          var_attributePrefix_3090.setter_setString (var_parsedString_3559 COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 143)) ;
          var_attributePrefix_3090.setter_setLocation (var_fullType_3316.readProperty_location () COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 144)) ;
          var_parsed_3485.method_last (var_parsedString_3559, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 145)) ;
          var_attributeType_2961.setter_setString (var_parsedString_3559 COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 146)) ;
          var_attributeType_2961.setter_setLocation (var_fullType_3316.readProperty_location () COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 147)) ;
        }
      }
      if (kBoolFalse == test_1) {
        var_attributeType_2961 = var_fullType_3316 ;
      }
    } break ;
    case 4: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_name COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 151)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 152)) ;
      var_attributeName_3004 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 153)) ;
      var_attributeName_3004.setter_setString (var_attributeName_3004.readProperty_string ().getter_stringByReplacingStringByString (GALGAS_string ("<"), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 154)) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 154)) ;
      var_attributeName_3004.setter_setString (var_attributeName_3004.readProperty_string ().getter_stringByReplacingStringByString (GALGAS_string (">"), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 155)) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 155)) ;
    } break ;
    case 5: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_use COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 156)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 157)) ;
      var_attributeUse_3136 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 158)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  enumGalgasBool test_2 = kBoolTrue ;
  if (kBoolTrue == test_2) {
    test_2 = GALGAS_bool (kIsNotEqual, var_attributeName_3004.readProperty_string ().objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
    if (kBoolTrue == test_2) {
      GALGAS_arxmlMetaAttribute var_newAttribute_4239 = GALGAS_arxmlMetaAttribute::constructor_new (var_attributeName_3004, var_attributeType_2961, var_attributePrefix_3090, var_attributeUse_3136  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 162)) ;
      {
      extensionSetter_addClassAttribute (ioArgument_classMap, inArgument_parentClass, var_newAttribute_4239, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 168)) ;
      }
    }
  }
  switch (select_arxmlmetaparser_5F_syntax_5 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 171)) ;
    bool repeatFlag_3 = true ;
    while (repeatFlag_3) {
      if (select_arxmlmetaparser_5F_syntax_6 (inCompiler) == 2) {
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
      }else{
        repeatFlag_3 = false ;
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
      if (select_arxmlmetaparser_5F_syntax_6 (inCompiler) == 2) {
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
      }else{
        repeatFlag_1 = false ;
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

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_attribute_i4_indexing (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
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
      if (select_arxmlmetaparser_5F_syntax_6 (inCompiler) == 2) {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 173)) ;
        switch (select_arxmlmetaparser_5F_syntax_7 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 174)) ;
          nt_xsd_5F_annotation_indexing (inCompiler) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_simpleType COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 176)) ;
          nt_xsd_5F_simpleType_indexing (inCompiler) ;
        } break ;
        default:
          break ;
        }
      }else{
        repeatFlag_1 = false ;
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

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_attributeGroup_i5_ (GALGAS_arxmlMetaClassMap & ioArgument_classMap,
                                                                                                  GALGAS_arxmlMetaClassGraph & ioArgument_classGraph,
                                                                                                  GALGAS_lstring inArgument_parentClass,
                                                                                                  C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  GALGAS_lstring var_className_5300 ;
  GALGAS_lstring var_nextParentClass_5325 ;
  switch (select_arxmlmetaparser_5F_syntax_8 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_name COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 199)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 201)) ;
    var_className_5300 = inCompiler->synthetizedAttribute_tokenString () ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 202)) ;
    var_className_5300.setter_setString (var_className_5300.readProperty_string ().getter_stringByReplacingStringByString (GALGAS_string ("<"), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 203)) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 203)) ;
    var_className_5300.setter_setString (var_className_5300.readProperty_string ().getter_stringByReplacingStringByString (GALGAS_string (">"), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 204)) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 204)) ;
    GALGAS_lstring var_desc_5680 ;
    {
    routine_lstringhere (var_desc_5680, GALGAS_string::makeEmptyString (), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 205)) ;
    }
    enumGalgasBool test_0 = kBoolTrue ;
    if (kBoolTrue == test_0) {
      test_0 = ioArgument_classMap.getter_hasKey (var_className_5300.readProperty_string () COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 207)).operator_not (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 207)).boolEnum () ;
      if (kBoolTrue == test_0) {
        GALGAS_arxmlMetaClass var_newClass_5800 = GALGAS_arxmlMetaClass::constructor_new (var_className_5300, GALGAS_bool (true), GALGAS_arxmlMetaElementList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 211)), GALGAS_arxmlMetaElementList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 211)), GALGAS_arxmlMetaAttributeList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 212)), GALGAS_arxmlMetaAttributeList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 212)), var_desc_5680  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 208)) ;
        {
        ioArgument_classMap.setter_insertKey (var_className_5300, var_newClass_5800, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 215)) ;
        }
        {
        ioArgument_classGraph.setter_addNode (var_className_5300, var_className_5300, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 216)) ;
        }
      }
    }
    var_nextParentClass_5325 = var_className_5300 ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_ref COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 220)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 221)) ;
    GALGAS_lstring var_fullClassName_6394 = inCompiler->synthetizedAttribute_tokenString () ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 222)) ;
    var_className_5300 = var_fullClassName_6394 ;
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = var_fullClassName_6394.readProperty_string ().getter_containsCharacter (GALGAS_char (TO_UNICODE (58)) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 225)).boolEnum () ;
      if (kBoolTrue == test_1) {
        GALGAS_stringlist var_parsed_6567 = var_fullClassName_6394.readProperty_string ().getter_componentsSeparatedByString (GALGAS_string (":") COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 226)) ;
        GALGAS_string var_parsedString_6664 ;
        var_parsed_6567.method_last (var_parsedString_6664, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 227)) ;
        var_className_5300.setter_setString (var_parsedString_6664 COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 228)) ;
      }
    }
    enumGalgasBool test_2 = kBoolTrue ;
    if (kBoolTrue == test_2) {
      test_2 = GALGAS_bool (kIsNotEqual, inArgument_parentClass.readProperty_string ().objectCompare (var_className_5300.readProperty_string ())).boolEnum () ;
      if (kBoolTrue == test_2) {
        {
        ioArgument_classGraph.setter_addEdge (var_className_5300, inArgument_parentClass COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 233)) ;
        }
      }
    }
    var_nextParentClass_5325 = inArgument_parentClass ;
  } break ;
  default:
    break ;
  }
  switch (select_arxmlmetaparser_5F_syntax_9 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 239)) ;
    bool repeatFlag_3 = true ;
    while (repeatFlag_3) {
      if (select_arxmlmetaparser_5F_syntax_10 (inCompiler) == 2) {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 241)) ;
        switch (select_arxmlmetaparser_5F_syntax_11 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 242)) ;
          nt_xsd_5F_annotation_ (ioArgument_classMap, ioArgument_classGraph, var_nextParentClass_5325, inCompiler) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attribute COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 244)) ;
          nt_xsd_5F_attribute_ (ioArgument_classMap, ioArgument_classGraph, var_nextParentClass_5325, inCompiler) ;
        } break ;
        case 3: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attributeGroup COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 246)) ;
          nt_xsd_5F_attributeGroup_ (ioArgument_classMap, ioArgument_classGraph, var_nextParentClass_5325, inCompiler) ;
        } break ;
        case 4: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_choice COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 248)) ;
          nt_xsd_5F_choice_ (ioArgument_classMap, ioArgument_classGraph, var_nextParentClass_5325, inCompiler) ;
        } break ;
        case 5: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_sequence COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 250)) ;
          nt_xsd_5F_sequence_ (ioArgument_classMap, ioArgument_classGraph, var_nextParentClass_5325, inCompiler) ;
        } break ;
        default:
          break ;
        }
      }else{
        repeatFlag_3 = false ;
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
      if (select_arxmlmetaparser_5F_syntax_10 (inCompiler) == 2) {
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
      }else{
        repeatFlag_0 = false ;
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

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_attributeGroup_i5_indexing (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
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
      if (select_arxmlmetaparser_5F_syntax_10 (inCompiler) == 2) {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 241)) ;
        switch (select_arxmlmetaparser_5F_syntax_11 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 242)) ;
          nt_xsd_5F_annotation_indexing (inCompiler) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attribute COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 244)) ;
          nt_xsd_5F_attribute_indexing (inCompiler) ;
        } break ;
        case 3: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attributeGroup COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 246)) ;
          nt_xsd_5F_attributeGroup_indexing (inCompiler) ;
        } break ;
        case 4: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_choice COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 248)) ;
          nt_xsd_5F_choice_indexing (inCompiler) ;
        } break ;
        case 5: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_sequence COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 250)) ;
          nt_xsd_5F_sequence_indexing (inCompiler) ;
        } break ;
        default:
          break ;
        }
      }else{
        repeatFlag_0 = false ;
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
      if (select_arxmlmetaparser_5F_syntax_13 (inCompiler) == 2) {
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
      }else{
        repeatFlag_0 = false ;
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
      if (select_arxmlmetaparser_5F_syntax_13 (inCompiler) == 2) {
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
      }else{
        repeatFlag_0 = false ;
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

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_choice_i6_indexing (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  nt_xsd_5F_ignore_5F_attributes_indexing (inCompiler) ;
  switch (select_arxmlmetaparser_5F_syntax_12 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 271)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      if (select_arxmlmetaparser_5F_syntax_13 (inCompiler) == 2) {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 273)) ;
        switch (select_arxmlmetaparser_5F_syntax_14 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 274)) ;
          nt_xsd_5F_annotation_indexing (inCompiler) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_choice COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 276)) ;
          nt_xsd_5F_choice_indexing (inCompiler) ;
        } break ;
        case 3: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_sequence COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 278)) ;
          nt_xsd_5F_sequence_indexing (inCompiler) ;
        } break ;
        case 4: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_element COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 280)) ;
          nt_xsd_5F_element_indexing (inCompiler) ;
        } break ;
        case 5: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_group COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 282)) ;
          nt_xsd_5F_group_indexing (inCompiler) ;
        } break ;
        default:
          break ;
        }
      }else{
        repeatFlag_0 = false ;
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

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_complexType_i7_ (GALGAS_arxmlMetaClassMap & ioArgument_classMap,
                                                                                               GALGAS_arxmlMetaClassGraph & ioArgument_classGraph,
                                                                                               GALGAS_lstring inArgument_parentClass,
                                                                                               C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  GALGAS_lstring var_complexAbstract_8482 ;
  {
  routine_lstringhere (var_complexAbstract_8482, GALGAS_string::makeEmptyString (), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 302)) ;
  }
  GALGAS_lstring var_complexMixed_8527 ;
  {
  routine_lstringhere (var_complexMixed_8527, GALGAS_string::makeEmptyString (), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 303)) ;
  }
  GALGAS_lstring var_complexName_8569 ;
  {
  routine_lstringhere (var_complexName_8569, GALGAS_string::makeEmptyString (), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 304)) ;
  }
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_arxmlmetaparser_5F_syntax_15 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_abstract COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 307)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 308)) ;
      var_complexAbstract_8482 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 309)) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_mixed COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 310)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 311)) ;
      var_complexMixed_8527 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 312)) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_name COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 313)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 314)) ;
      var_complexName_8569 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 315)) ;
      var_complexName_8569.setter_setString (var_complexName_8569.readProperty_string ().getter_stringByReplacingStringByString (GALGAS_string ("<"), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 316)) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 316)) ;
      var_complexName_8569.setter_setString (var_complexName_8569.readProperty_string ().getter_stringByReplacingStringByString (GALGAS_string (">"), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 317)) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 317)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  enumGalgasBool test_1 = kBoolTrue ;
  if (kBoolTrue == test_1) {
    test_1 = GALGAS_bool (kIsEqual, var_complexName_8569.readProperty_string ().objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
    if (kBoolTrue == test_1) {
      var_complexName_8569 = inArgument_parentClass ;
    }
  }
  enumGalgasBool test_2 = kBoolTrue ;
  if (kBoolTrue == test_2) {
    test_2 = ioArgument_classMap.getter_hasKey (var_complexName_8569.readProperty_string () COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 326)).operator_not (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 326)).boolEnum () ;
    if (kBoolTrue == test_2) {
      GALGAS_lstring var_desc_9197 ;
      {
      routine_lstringhere (var_desc_9197, GALGAS_string::makeEmptyString (), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 327)) ;
      }
      GALGAS_arxmlMetaClass var_newClass_9231 = GALGAS_arxmlMetaClass::constructor_new (var_complexName_8569, GALGAS_bool (false), GALGAS_arxmlMetaElementList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 331)), GALGAS_arxmlMetaElementList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 331)), GALGAS_arxmlMetaAttributeList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 332)), GALGAS_arxmlMetaAttributeList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 332)), var_desc_9197  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 328)) ;
      {
      ioArgument_classMap.setter_insertKey (var_complexName_8569, var_newClass_9231, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 335)) ;
      }
      {
      ioArgument_classGraph.setter_addNode (var_complexName_8569, var_complexName_8569, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 336)) ;
      }
    }
  }
  switch (select_arxmlmetaparser_5F_syntax_16 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 339)) ;
    bool repeatFlag_3 = true ;
    while (repeatFlag_3) {
      if (select_arxmlmetaparser_5F_syntax_17 (inCompiler) == 2) {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 341)) ;
        switch (select_arxmlmetaparser_5F_syntax_18 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 342)) ;
          nt_xsd_5F_annotation_ (ioArgument_classMap, ioArgument_classGraph, var_complexName_8569, inCompiler) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attribute COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 344)) ;
          nt_xsd_5F_attribute_ (ioArgument_classMap, ioArgument_classGraph, var_complexName_8569, inCompiler) ;
        } break ;
        case 3: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attributeGroup COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 346)) ;
          nt_xsd_5F_attributeGroup_ (ioArgument_classMap, ioArgument_classGraph, var_complexName_8569, inCompiler) ;
        } break ;
        case 4: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_choice COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 348)) ;
          nt_xsd_5F_choice_ (ioArgument_classMap, ioArgument_classGraph, var_complexName_8569, inCompiler) ;
        } break ;
        case 5: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_sequence COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 350)) ;
          nt_xsd_5F_sequence_ (ioArgument_classMap, ioArgument_classGraph, var_complexName_8569, inCompiler) ;
        } break ;
        case 6: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_group COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 352)) ;
          nt_xsd_5F_group_ (ioArgument_classMap, ioArgument_classGraph, var_complexName_8569, inCompiler) ;
        } break ;
        case 7: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_simpleContent COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 354)) ;
          nt_xsd_5F_simpleContent_ (ioArgument_classMap, ioArgument_classGraph, var_complexName_8569, inCompiler) ;
        } break ;
        default:
          break ;
        }
      }else{
        repeatFlag_3 = false ;
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
      if (select_arxmlmetaparser_5F_syntax_17 (inCompiler) == 2) {
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
      }else{
        repeatFlag_1 = false ;
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

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_complexType_i7_indexing (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
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
      if (select_arxmlmetaparser_5F_syntax_17 (inCompiler) == 2) {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 341)) ;
        switch (select_arxmlmetaparser_5F_syntax_18 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 342)) ;
          nt_xsd_5F_annotation_indexing (inCompiler) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attribute COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 344)) ;
          nt_xsd_5F_attribute_indexing (inCompiler) ;
        } break ;
        case 3: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attributeGroup COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 346)) ;
          nt_xsd_5F_attributeGroup_indexing (inCompiler) ;
        } break ;
        case 4: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_choice COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 348)) ;
          nt_xsd_5F_choice_indexing (inCompiler) ;
        } break ;
        case 5: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_sequence COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 350)) ;
          nt_xsd_5F_sequence_indexing (inCompiler) ;
        } break ;
        case 6: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_group COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 352)) ;
          nt_xsd_5F_group_indexing (inCompiler) ;
        } break ;
        case 7: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_simpleContent COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 354)) ;
          nt_xsd_5F_simpleContent_indexing (inCompiler) ;
        } break ;
        default:
          break ;
        }
      }else{
        repeatFlag_1 = false ;
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

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_documentation_i8_indexing (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  nt_xsd_5F_ignore_5F_attributes_indexing (inCompiler) ;
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

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_element_i9_ (GALGAS_arxmlMetaClassMap & ioArgument_classMap,
                                                                                           GALGAS_arxmlMetaClassGraph & ioArgument_classGraph,
                                                                                           GALGAS_lstring inArgument_parentClass,
                                                                                           C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  GALGAS_arxmlMetaElement var_newElement_11098 ;
  GALGAS_lstring var_elementType_11133 ;
  {
  routine_lstringhere (var_elementType_11133, GALGAS_string::makeEmptyString (), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 394)) ;
  }
  GALGAS_lstring var_elementName_11174 ;
  {
  routine_lstringhere (var_elementName_11174, GALGAS_string::makeEmptyString (), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 395)) ;
  }
  GALGAS_lstring var_elementMin_11215 ;
  {
  routine_lstringhere (var_elementMin_11215, GALGAS_string::makeEmptyString (), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 396)) ;
  }
  GALGAS_lstring var_elementMax_11256 ;
  {
  routine_lstringhere (var_elementMax_11256, GALGAS_string::makeEmptyString (), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 397)) ;
  }
  GALGAS_lstring var_elementPrefix_11297 ;
  {
  routine_lstringhere (var_elementPrefix_11297, GALGAS_string::makeEmptyString (), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 398)) ;
  }
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_arxmlmetaparser_5F_syntax_20 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_maxOccurs COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 401)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 402)) ;
      var_elementMax_11256 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 403)) ;
    } break ;
    case 3: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_minOccurs COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 404)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 405)) ;
      var_elementMin_11215 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 406)) ;
    } break ;
    case 4: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_type COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 407)) ;
      GALGAS_lstring var_fullType_11475 ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 409)) ;
      var_fullType_11475 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 410)) ;
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = var_fullType_11475.readProperty_string ().getter_containsCharacter (GALGAS_char (TO_UNICODE (58)) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 412)).boolEnum () ;
        if (kBoolTrue == test_1) {
          GALGAS_stringlist var_parsed_11644 = var_fullType_11475.readProperty_string ().getter_componentsSeparatedByString (GALGAS_string (":") COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 413)) ;
          GALGAS_string var_parsedString_11718 ;
          var_parsed_11644.method_first (var_parsedString_11718, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 415)) ;
          var_elementPrefix_11297.setter_setString (var_parsedString_11718 COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 416)) ;
          var_elementPrefix_11297.setter_setLocation (var_fullType_11475.readProperty_location () COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 417)) ;
          var_parsed_11644.method_last (var_parsedString_11718, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 418)) ;
          var_elementType_11133.setter_setString (var_parsedString_11718 COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 419)) ;
          var_elementType_11133.setter_setLocation (var_fullType_11475.readProperty_location () COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 420)) ;
        }
      }
      if (kBoolFalse == test_1) {
        var_elementType_11133 = var_fullType_11475 ;
      }
    } break ;
    case 5: {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_name COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 424)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 425)) ;
      var_elementName_11174 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 426)) ;
      var_elementName_11174.setter_setString (var_elementName_11174.readProperty_string ().getter_stringByReplacingStringByString (GALGAS_string ("<"), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 427)) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 427)) ;
      var_elementName_11174.setter_setString (var_elementName_11174.readProperty_string ().getter_stringByReplacingStringByString (GALGAS_string (">"), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 428)) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 428)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  enumGalgasBool test_2 = kBoolTrue ;
  if (kBoolTrue == test_2) {
    test_2 = GALGAS_bool (kIsEqual, var_elementName_11174.readProperty_string ().objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
    if (kBoolTrue == test_2) {
      TC_Array <C_FixItDescription> fixItArray3 ;
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 432)), GALGAS_string ("An xsd:element must have a name."), fixItArray3  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 432)) ;
    }
  }
  enumGalgasBool test_4 = kBoolTrue ;
  if (kBoolTrue == test_4) {
    test_4 = GALGAS_bool (kIsEqual, var_elementMax_11256.readProperty_string ().objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
    if (kBoolTrue == test_4) {
      {
      routine_lstringhere (var_elementMax_11256, GALGAS_string ("unbounded"), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 440)) ;
      }
    }
  }
  enumGalgasBool test_5 = kBoolTrue ;
  if (kBoolTrue == test_5) {
    test_5 = GALGAS_bool (kIsEqual, var_elementMin_11215.readProperty_string ().objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
    if (kBoolTrue == test_5) {
      {
      routine_lstringhere (var_elementMin_11215, GALGAS_string ("0"), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 443)) ;
      }
    }
  }
  enumGalgasBool test_6 = kBoolTrue ;
  if (kBoolTrue == test_6) {
    test_6 = GALGAS_bool (kIsEqual, var_elementType_11133.readProperty_string ().objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
    if (kBoolTrue == test_6) {
      var_elementType_11133 = var_elementName_11174 ;
    }
  }
  if (kBoolFalse == test_6) {
    {
    ioArgument_classGraph.setter_addEdge (var_elementType_11133, var_elementName_11174 COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 449)) ;
    }
  }
  enumGalgasBool test_7 = kBoolTrue ;
  if (kBoolTrue == test_7) {
    test_7 = ioArgument_classMap.getter_hasKey (var_elementName_11174.readProperty_string () COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 452)).operator_not (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 452)).boolEnum () ;
    if (kBoolTrue == test_7) {
      GALGAS_lstring var_desc_12965 ;
      {
      routine_lstringhere (var_desc_12965, GALGAS_string::makeEmptyString (), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 453)) ;
      }
      GALGAS_arxmlMetaClass var_newClass_12999 = GALGAS_arxmlMetaClass::constructor_new (var_elementName_11174, GALGAS_bool (false), GALGAS_arxmlMetaElementList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 457)), GALGAS_arxmlMetaElementList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 457)), GALGAS_arxmlMetaAttributeList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 458)), GALGAS_arxmlMetaAttributeList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 458)), var_desc_12965  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 454)) ;
      {
      ioArgument_classMap.setter_insertKey (var_elementName_11174, var_newClass_12999, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 461)) ;
      }
      {
      ioArgument_classGraph.setter_addNode (var_elementName_11174, var_elementName_11174, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 462)) ;
      }
    }
  }
  var_newElement_11098 = GALGAS_arxmlMetaElement::constructor_new (var_elementName_11174, var_elementType_11133, var_elementMin_11215, var_elementMax_11256, var_elementPrefix_11297  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 465)) ;
  {
  extensionSetter_addClassElement (ioArgument_classMap, inArgument_parentClass, var_newElement_11098, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 471)) ;
  }
  switch (select_arxmlmetaparser_5F_syntax_21 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 473)) ;
    bool repeatFlag_8 = true ;
    while (repeatFlag_8) {
      if (select_arxmlmetaparser_5F_syntax_22 (inCompiler) == 2) {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 475)) ;
        switch (select_arxmlmetaparser_5F_syntax_23 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 476)) ;
          nt_xsd_5F_annotation_ (ioArgument_classMap, ioArgument_classGraph, var_elementName_11174, inCompiler) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_complexType COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 478)) ;
          nt_xsd_5F_complexType_ (ioArgument_classMap, ioArgument_classGraph, var_elementName_11174, inCompiler) ;
        } break ;
        case 3: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_simpleType COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 480)) ;
          nt_xsd_5F_simpleType_ (ioArgument_classMap, ioArgument_classGraph, var_elementName_11174, inCompiler) ;
        } break ;
        default:
          break ;
        }
      }else{
        repeatFlag_8 = false ;
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
      if (select_arxmlmetaparser_5F_syntax_22 (inCompiler) == 2) {
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
      }else{
        repeatFlag_1 = false ;
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

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_element_i9_indexing (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
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
      if (select_arxmlmetaparser_5F_syntax_22 (inCompiler) == 2) {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 475)) ;
        switch (select_arxmlmetaparser_5F_syntax_23 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 476)) ;
          nt_xsd_5F_annotation_indexing (inCompiler) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_complexType COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 478)) ;
          nt_xsd_5F_complexType_indexing (inCompiler) ;
        } break ;
        case 3: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_simpleType COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 480)) ;
          nt_xsd_5F_simpleType_indexing (inCompiler) ;
        } break ;
        default:
          break ;
        }
      }else{
        repeatFlag_1 = false ;
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

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_enumeration_i10_ (GALGAS_arxmlMetaClassMap & ioArgument_classMap,
                                                                                                GALGAS_arxmlMetaClassGraph & ioArgument_classGraph,
                                                                                                GALGAS_lstring inArgument_parentClass,
                                                                                                GALGAS_arxmlMetaSimpletype & ioArgument_restriction,
                                                                                                C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_value COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 501)) ;
  inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 502)) ;
  GALGAS_lstring var_enumValue_14506 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 503)) ;
  {
  ioArgument_restriction.insulate (HERE) ;
  cPtr_arxmlMetaSimpletype * ptr_14521 = (cPtr_arxmlMetaSimpletype *) ioArgument_restriction.ptr () ;
  callExtensionSetter_addValue ((cPtr_arxmlMetaSimpletype *) ptr_14521, var_enumValue_14506, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 504)) ;
  }
  switch (select_arxmlmetaparser_5F_syntax_24 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 506)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      if (select_arxmlmetaparser_5F_syntax_25 (inCompiler) == 2) {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 508)) ;
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 509)) ;
        nt_xsd_5F_annotation_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
      }else{
        repeatFlag_0 = false ;
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
      if (select_arxmlmetaparser_5F_syntax_25 (inCompiler) == 2) {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 508)) ;
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 509)) ;
        nt_xsd_5F_annotation_parse (inCompiler) ;
      }else{
        repeatFlag_0 = false ;
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

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_enumeration_i10_indexing (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_value COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 501)) ;
  inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 502)) ;
  inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 503)) ;
  switch (select_arxmlmetaparser_5F_syntax_24 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 506)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      if (select_arxmlmetaparser_5F_syntax_25 (inCompiler) == 2) {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 508)) ;
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 509)) ;
        nt_xsd_5F_annotation_indexing (inCompiler) ;
      }else{
        repeatFlag_0 = false ;
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
      if (select_arxmlmetaparser_5F_syntax_27 (inCompiler) == 2) {
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
      }else{
        repeatFlag_0 = false ;
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
      if (select_arxmlmetaparser_5F_syntax_27 (inCompiler) == 2) {
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
      }else{
        repeatFlag_0 = false ;
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

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_extension_i11_indexing (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  nt_xsd_5F_ignore_5F_attributes_indexing (inCompiler) ;
  switch (select_arxmlmetaparser_5F_syntax_26 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 530)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      if (select_arxmlmetaparser_5F_syntax_27 (inCompiler) == 2) {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 532)) ;
        switch (select_arxmlmetaparser_5F_syntax_28 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 533)) ;
          nt_xsd_5F_annotation_indexing (inCompiler) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attribute COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 535)) ;
          nt_xsd_5F_attribute_indexing (inCompiler) ;
        } break ;
        case 3: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attributeGroup COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 537)) ;
          nt_xsd_5F_attributeGroup_indexing (inCompiler) ;
        } break ;
        case 4: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_choice COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 539)) ;
          nt_xsd_5F_choice_indexing (inCompiler) ;
        } break ;
        case 5: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_sequence COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 541)) ;
          nt_xsd_5F_sequence_indexing (inCompiler) ;
        } break ;
        case 6: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_group COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 543)) ;
          nt_xsd_5F_group_indexing (inCompiler) ;
        } break ;
        default:
          break ;
        }
      }else{
        repeatFlag_0 = false ;
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

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_group_i12_ (GALGAS_arxmlMetaClassMap & ioArgument_classMap,
                                                                                          GALGAS_arxmlMetaClassGraph & ioArgument_classGraph,
                                                                                          GALGAS_lstring inArgument_parentClass,
                                                                                          C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  GALGAS_lstring var_className_15869 ;
  GALGAS_lstring var_nextParentClass_15894 ;
  switch (select_arxmlmetaparser_5F_syntax_29 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_name COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 566)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 568)) ;
    var_className_15869 = inCompiler->synthetizedAttribute_tokenString () ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 569)) ;
    var_className_15869.setter_setString (var_className_15869.readProperty_string ().getter_stringByReplacingStringByString (GALGAS_string ("<"), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 570)) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 570)) ;
    var_className_15869.setter_setString (var_className_15869.readProperty_string ().getter_stringByReplacingStringByString (GALGAS_string (">"), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 571)) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 571)) ;
    GALGAS_lstring var_desc_16249 ;
    {
    routine_lstringhere (var_desc_16249, GALGAS_string::makeEmptyString (), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 572)) ;
    }
    enumGalgasBool test_0 = kBoolTrue ;
    if (kBoolTrue == test_0) {
      test_0 = ioArgument_classMap.getter_hasKey (var_className_15869.readProperty_string () COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 574)).operator_not (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 574)).boolEnum () ;
      if (kBoolTrue == test_0) {
        GALGAS_arxmlMetaClass var_newClass_16369 = GALGAS_arxmlMetaClass::constructor_new (var_className_15869, GALGAS_bool (false), GALGAS_arxmlMetaElementList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 578)), GALGAS_arxmlMetaElementList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 578)), GALGAS_arxmlMetaAttributeList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 579)), GALGAS_arxmlMetaAttributeList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 579)), var_desc_16249  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 575)) ;
        {
        ioArgument_classMap.setter_insertKey (var_className_15869, var_newClass_16369, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 582)) ;
        }
        {
        ioArgument_classGraph.setter_addNode (var_className_15869, var_className_15869, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 583)) ;
        }
      }
    }
    var_nextParentClass_15894 = var_className_15869 ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_ref COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 587)) ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 588)) ;
    GALGAS_lstring var_fullClassName_16953 = inCompiler->synthetizedAttribute_tokenString () ;
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 589)) ;
    var_className_15869 = var_fullClassName_16953 ;
    enumGalgasBool test_1 = kBoolTrue ;
    if (kBoolTrue == test_1) {
      test_1 = var_fullClassName_16953.readProperty_string ().getter_containsCharacter (GALGAS_char (TO_UNICODE (58)) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 592)).boolEnum () ;
      if (kBoolTrue == test_1) {
        GALGAS_stringlist var_parsed_17126 = var_fullClassName_16953.readProperty_string ().getter_componentsSeparatedByString (GALGAS_string (":") COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 593)) ;
        GALGAS_string var_parsedString_17223 ;
        var_parsed_17126.method_last (var_parsedString_17223, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 594)) ;
        var_className_15869.setter_setString (var_parsedString_17223 COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 595)) ;
      }
    }
    enumGalgasBool test_2 = kBoolTrue ;
    if (kBoolTrue == test_2) {
      test_2 = GALGAS_bool (kIsNotEqual, inArgument_parentClass.readProperty_string ().objectCompare (var_className_15869.readProperty_string ())).boolEnum () ;
      if (kBoolTrue == test_2) {
        {
        ioArgument_classGraph.setter_addEdge (var_className_15869, inArgument_parentClass COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 600)) ;
        }
      }
    }
    var_nextParentClass_15894 = inArgument_parentClass ;
  } break ;
  default:
    break ;
  }
  switch (select_arxmlmetaparser_5F_syntax_30 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 607)) ;
    bool repeatFlag_3 = true ;
    while (repeatFlag_3) {
      if (select_arxmlmetaparser_5F_syntax_31 (inCompiler) == 2) {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 609)) ;
        switch (select_arxmlmetaparser_5F_syntax_32 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 610)) ;
          nt_xsd_5F_annotation_ (ioArgument_classMap, ioArgument_classGraph, var_nextParentClass_15894, inCompiler) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_choice COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 612)) ;
          nt_xsd_5F_choice_ (ioArgument_classMap, ioArgument_classGraph, var_nextParentClass_15894, inCompiler) ;
        } break ;
        case 3: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_sequence COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 614)) ;
          nt_xsd_5F_sequence_ (ioArgument_classMap, ioArgument_classGraph, var_nextParentClass_15894, inCompiler) ;
        } break ;
        case 4: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_element COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 616)) ;
          nt_xsd_5F_element_ (ioArgument_classMap, ioArgument_classGraph, var_nextParentClass_15894, inCompiler) ;
        } break ;
        default:
          break ;
        }
      }else{
        repeatFlag_3 = false ;
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
      if (select_arxmlmetaparser_5F_syntax_31 (inCompiler) == 2) {
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
      }else{
        repeatFlag_0 = false ;
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

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_group_i12_indexing (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
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
      if (select_arxmlmetaparser_5F_syntax_31 (inCompiler) == 2) {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 609)) ;
        switch (select_arxmlmetaparser_5F_syntax_32 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 610)) ;
          nt_xsd_5F_annotation_indexing (inCompiler) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_choice COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 612)) ;
          nt_xsd_5F_choice_indexing (inCompiler) ;
        } break ;
        case 3: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_sequence COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 614)) ;
          nt_xsd_5F_sequence_indexing (inCompiler) ;
        } break ;
        case 4: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_element COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 616)) ;
          nt_xsd_5F_element_indexing (inCompiler) ;
        } break ;
        default:
          break ;
        }
      }else{
        repeatFlag_0 = false ;
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
      if (select_arxmlmetaparser_5F_syntax_34 (inCompiler) == 2) {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 638)) ;
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 639)) ;
        nt_xsd_5F_annotation_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
      }else{
        repeatFlag_0 = false ;
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
      if (select_arxmlmetaparser_5F_syntax_34 (inCompiler) == 2) {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 638)) ;
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 639)) ;
        nt_xsd_5F_annotation_parse (inCompiler) ;
      }else{
        repeatFlag_0 = false ;
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

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_import_i13_indexing (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  nt_xsd_5F_ignore_5F_attributes_indexing (inCompiler) ;
  switch (select_arxmlmetaparser_5F_syntax_33 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 636)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      if (select_arxmlmetaparser_5F_syntax_34 (inCompiler) == 2) {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 638)) ;
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 639)) ;
        nt_xsd_5F_annotation_indexing (inCompiler) ;
      }else{
        repeatFlag_0 = false ;
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

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_restriction_i14_ (GALGAS_arxmlMetaClassMap & ioArgument_classMap,
                                                                                                GALGAS_arxmlMetaClassGraph & ioArgument_classGraph,
                                                                                                GALGAS_lstring inArgument_parentClass,
                                                                                                GALGAS_arxmlMetaSimpletype & ioArgument_restriction,
                                                                                                C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_base COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 659)) ;
  inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 660)) ;
  GALGAS_lstring var_baseType_18692 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 661)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    GALGAS_bool test_1 = GALGAS_bool (kIsEqual, GALGAS_string ("xsd:string").objectCompare (var_baseType_18692.readProperty_string ())) ;
    if (kBoolTrue != test_1.boolEnum ()) {
      test_1 = GALGAS_bool (kIsEqual, GALGAS_string ("xsd:NMTOKEN").objectCompare (var_baseType_18692.readProperty_string ())) ;
    }
    GALGAS_bool test_2 = test_1 ;
    if (kBoolTrue != test_2.boolEnum ()) {
      test_2 = GALGAS_bool (kIsEqual, GALGAS_string ("xsd:NMTOKENS").objectCompare (var_baseType_18692.readProperty_string ())) ;
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
      test_3 = GALGAS_bool (kIsEqual, GALGAS_string ("xsd:unsignedInt").objectCompare (var_baseType_18692.readProperty_string ())).boolEnum () ;
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
        test_4 = GALGAS_bool (kIsEqual, GALGAS_string ("xsd:double").objectCompare (var_baseType_18692.readProperty_string ())).boolEnum () ;
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
        inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 675)), GALGAS_string ("Undefined/unimplemented base type ").add_operation (var_baseType_18692.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 675)), fixItArray5  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 675)) ;
      }
    }
  }
  switch (select_arxmlmetaparser_5F_syntax_35 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 678)) ;
    bool repeatFlag_6 = true ;
    while (repeatFlag_6) {
      if (select_arxmlmetaparser_5F_syntax_36 (inCompiler) == 2) {
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
      }else{
        repeatFlag_6 = false ;
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
      if (select_arxmlmetaparser_5F_syntax_36 (inCompiler) == 2) {
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
      }else{
        repeatFlag_0 = false ;
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

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_restriction_i14_indexing (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_base COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 659)) ;
  inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 660)) ;
  inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 661)) ;
  switch (select_arxmlmetaparser_5F_syntax_35 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 678)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      if (select_arxmlmetaparser_5F_syntax_36 (inCompiler) == 2) {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 680)) ;
        switch (select_arxmlmetaparser_5F_syntax_37 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 681)) ;
          nt_xsd_5F_annotation_indexing (inCompiler) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attribute COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 683)) ;
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_TODO COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 684)) ;
          nt_xsd_5F_attribute_indexing (inCompiler) ;
        } break ;
        case 3: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attributeGroup COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 687)) ;
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_TODO COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 688)) ;
          nt_xsd_5F_attributeGroup_indexing (inCompiler) ;
        } break ;
        case 4: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_choice COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 691)) ;
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_TODO COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 692)) ;
          nt_xsd_5F_choice_indexing (inCompiler) ;
        } break ;
        case 5: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_sequence COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 695)) ;
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_TODO COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 696)) ;
          nt_xsd_5F_sequence_indexing (inCompiler) ;
        } break ;
        case 6: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_group COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 699)) ;
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_TODO COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 700)) ;
          nt_xsd_5F_group_indexing (inCompiler) ;
        } break ;
        case 7: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_simpleType COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 703)) ;
          nt_xsd_5F_simpleType_indexing (inCompiler) ;
        } break ;
        case 8: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_whiteSpace COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 706)) ;
          nt_xsd_5F_whiteSpace_indexing (inCompiler) ;
        } break ;
        case 9: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_maxLength COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 713)) ;
          nt_xsd_5F_maxLength_indexing (inCompiler) ;
        } break ;
        case 10: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_pattern COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 720)) ;
          nt_xsd_5F_pattern_indexing (inCompiler) ;
        } break ;
        case 11: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_enumeration COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 727)) ;
          nt_xsd_5F_enumeration_indexing (inCompiler) ;
        } break ;
        default:
          break ;
        }
      }else{
        repeatFlag_0 = false ;
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

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_schema_i15_ (GALGAS_arxmlMetaClassMap & ioArgument_classMap,
                                                                                           GALGAS_arxmlMetaClassGraph & ioArgument_classGraph,
                                                                                           C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 754)) ;
  inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_schema COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 755)) ;
  nt_xsd_5F_ignore_5F_attributes_ (inCompiler) ;
  inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 757)) ;
  GALGAS_lstring var_rootClassName_22423 ;
  {
  routine_lstringhere (var_rootClassName_22423, GALGAS_string ("root"), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 763)) ;
  }
  GALGAS_lstring var_desc_22474 ;
  {
  routine_lstringhere (var_desc_22474, GALGAS_string ("Root class containing the main AUTOSAR node"), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 764)) ;
  }
  GALGAS_arxmlMetaClass var_rootClass_22550 = GALGAS_arxmlMetaClass::constructor_new (var_rootClassName_22423, GALGAS_bool (false), GALGAS_arxmlMetaElementList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 769)), GALGAS_arxmlMetaElementList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 769)), GALGAS_arxmlMetaAttributeList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 770)), GALGAS_arxmlMetaAttributeList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 770)), var_desc_22474  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 766)) ;
  {
  ioArgument_classMap.setter_insertKey (var_rootClassName_22423, var_rootClass_22550, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 773)) ;
  }
  {
  ioArgument_classGraph.setter_addNode (var_rootClassName_22423, var_rootClassName_22423, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 774)) ;
  }
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    if (select_arxmlmetaparser_5F_syntax_38 (inCompiler) == 2) {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 777)) ;
      switch (select_arxmlmetaparser_5F_syntax_39 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 778)) ;
        nt_xsd_5F_annotation_ (ioArgument_classMap, ioArgument_classGraph, var_rootClassName_22423, inCompiler) ;
      } break ;
      case 2: {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attribute COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 780)) ;
        nt_xsd_5F_attribute_ (ioArgument_classMap, ioArgument_classGraph, var_rootClassName_22423, inCompiler) ;
      } break ;
      case 3: {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attributeGroup COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 782)) ;
        nt_xsd_5F_attributeGroup_ (ioArgument_classMap, ioArgument_classGraph, var_rootClassName_22423, inCompiler) ;
      } break ;
      case 4: {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_complexType COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 784)) ;
        nt_xsd_5F_complexType_ (ioArgument_classMap, ioArgument_classGraph, var_rootClassName_22423, inCompiler) ;
      } break ;
      case 5: {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_element COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 786)) ;
        nt_xsd_5F_element_ (ioArgument_classMap, ioArgument_classGraph, var_rootClassName_22423, inCompiler) ;
      } break ;
      case 6: {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_group COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 788)) ;
        nt_xsd_5F_group_ (ioArgument_classMap, ioArgument_classGraph, var_rootClassName_22423, inCompiler) ;
      } break ;
      case 7: {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_import COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 790)) ;
        nt_xsd_5F_import_ (ioArgument_classMap, ioArgument_classGraph, var_rootClassName_22423, inCompiler) ;
      } break ;
      case 8: {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_simpleType COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 792)) ;
        nt_xsd_5F_simpleType_ (ioArgument_classMap, ioArgument_classGraph, var_rootClassName_22423, inCompiler) ;
      } break ;
      default:
        break ;
      }
    }else{
      repeatFlag_0 = false ;
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
    if (select_arxmlmetaparser_5F_syntax_38 (inCompiler) == 2) {
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
    }else{
      repeatFlag_0 = false ;
    }
  }
  inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 798)) ;
  inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_schema COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 799)) ;
  inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 800)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_schema_i15_indexing (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 754)) ;
  inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_schema COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 755)) ;
  nt_xsd_5F_ignore_5F_attributes_indexing (inCompiler) ;
  inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 757)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    if (select_arxmlmetaparser_5F_syntax_38 (inCompiler) == 2) {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 777)) ;
      switch (select_arxmlmetaparser_5F_syntax_39 (inCompiler)) {
      case 1: {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 778)) ;
        nt_xsd_5F_annotation_indexing (inCompiler) ;
      } break ;
      case 2: {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attribute COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 780)) ;
        nt_xsd_5F_attribute_indexing (inCompiler) ;
      } break ;
      case 3: {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attributeGroup COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 782)) ;
        nt_xsd_5F_attributeGroup_indexing (inCompiler) ;
      } break ;
      case 4: {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_complexType COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 784)) ;
        nt_xsd_5F_complexType_indexing (inCompiler) ;
      } break ;
      case 5: {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_element COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 786)) ;
        nt_xsd_5F_element_indexing (inCompiler) ;
      } break ;
      case 6: {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_group COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 788)) ;
        nt_xsd_5F_group_indexing (inCompiler) ;
      } break ;
      case 7: {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_import COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 790)) ;
        nt_xsd_5F_import_indexing (inCompiler) ;
      } break ;
      case 8: {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_simpleType COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 792)) ;
        nt_xsd_5F_simpleType_indexing (inCompiler) ;
      } break ;
      default:
        break ;
      }
    }else{
      repeatFlag_0 = false ;
    }
  }
  inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 798)) ;
  inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_schema COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 799)) ;
  inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 800)) ;
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
      if (select_arxmlmetaparser_5F_syntax_41 (inCompiler) == 2) {
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
      }else{
        repeatFlag_0 = false ;
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
      if (select_arxmlmetaparser_5F_syntax_41 (inCompiler) == 2) {
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
      }else{
        repeatFlag_0 = false ;
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

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_sequence_i16_indexing (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  switch (select_arxmlmetaparser_5F_syntax_40 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 812)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      if (select_arxmlmetaparser_5F_syntax_41 (inCompiler) == 2) {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 814)) ;
        switch (select_arxmlmetaparser_5F_syntax_42 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 815)) ;
          nt_xsd_5F_annotation_indexing (inCompiler) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_choice COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 817)) ;
          nt_xsd_5F_choice_indexing (inCompiler) ;
        } break ;
        case 3: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_sequence COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 819)) ;
          nt_xsd_5F_sequence_indexing (inCompiler) ;
        } break ;
        case 4: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_element COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 821)) ;
          nt_xsd_5F_element_indexing (inCompiler) ;
        } break ;
        case 5: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_group COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 823)) ;
          nt_xsd_5F_group_indexing (inCompiler) ;
        } break ;
        default:
          break ;
        }
      }else{
        repeatFlag_0 = false ;
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

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_simpleContent_i17_ (GALGAS_arxmlMetaClassMap & ioArgument_classMap,
                                                                                                  GALGAS_arxmlMetaClassGraph & ioArgument_classGraph,
                                                                                                  GALGAS_lstring inArgument_parentClass,
                                                                                                  C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  switch (select_arxmlmetaparser_5F_syntax_43 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 851)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      if (select_arxmlmetaparser_5F_syntax_44 (inCompiler) == 2) {
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
      }else{
        repeatFlag_0 = false ;
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
      if (select_arxmlmetaparser_5F_syntax_44 (inCompiler) == 2) {
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
      }else{
        repeatFlag_0 = false ;
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

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_simpleContent_i17_indexing (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  switch (select_arxmlmetaparser_5F_syntax_43 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 851)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      if (select_arxmlmetaparser_5F_syntax_44 (inCompiler) == 2) {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 853)) ;
        switch (select_arxmlmetaparser_5F_syntax_45 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 854)) ;
          nt_xsd_5F_annotation_indexing (inCompiler) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_extension COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 856)) ;
          nt_xsd_5F_extension_indexing (inCompiler) ;
        } break ;
        default:
          break ;
        }
      }else{
        repeatFlag_0 = false ;
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

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_simpleType_i18_ (GALGAS_arxmlMetaClassMap & ioArgument_classMap,
                                                                                               GALGAS_arxmlMetaClassGraph & ioArgument_classGraph,
                                                                                               GALGAS_lstring inArgument_parentClass,
                                                                                               C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  GALGAS_lstring var_typeName_26071 ;
  {
  routine_lstringhere (var_typeName_26071, GALGAS_string::makeEmptyString (), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 880)) ;
  }
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    if (select_arxmlmetaparser_5F_syntax_46 (inCompiler) == 2) {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_name COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 883)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 884)) ;
      var_typeName_26071 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 885)) ;
      var_typeName_26071.setter_setString (var_typeName_26071.readProperty_string ().getter_stringByReplacingStringByString (GALGAS_string ("<"), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 886)) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 886)) ;
      var_typeName_26071.setter_setString (var_typeName_26071.readProperty_string ().getter_stringByReplacingStringByString (GALGAS_string (">"), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 887)) COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 887)) ;
    }else{
      repeatFlag_0 = false ;
    }
  }
  enumGalgasBool test_1 = kBoolTrue ;
  if (kBoolTrue == test_1) {
    GALGAS_bool test_2 = GALGAS_bool (kIsEqual, inArgument_parentClass.readProperty_string ().objectCompare (GALGAS_string ("root"))) ;
    if (kBoolTrue == test_2.boolEnum ()) {
      test_2 = GALGAS_bool (kIsEqual, var_typeName_26071.readProperty_string ().objectCompare (GALGAS_string::makeEmptyString ())) ;
    }
    test_1 = test_2.boolEnum () ;
    if (kBoolTrue == test_1) {
      TC_Array <C_FixItDescription> fixItArray3 ;
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 891)), GALGAS_string ("The name attribute is required if the simpleType element is").add_operation (GALGAS_string (" a child of the schema element"), inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 891)), fixItArray3  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 891)) ;
    }
  }
  GALGAS_arxmlMetaSimpletype var_restriction_26540 = GALGAS_arxmlMetaSimpletype::constructor_new (var_typeName_26071, GALGAS_restrictionType::constructor_restrictionUnused (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 897)), GALGAS_restrictionBaseType::constructor_restrictionUndef (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 898)), GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 899))  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 895)) ;
  enumGalgasBool test_4 = kBoolTrue ;
  if (kBoolTrue == test_4) {
    test_4 = ioArgument_classMap.getter_hasKey (var_typeName_26071.readProperty_string () COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 902)).operator_not (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 902)).boolEnum () ;
    if (kBoolTrue == test_4) {
      GALGAS_lstring var_desc_26977 ;
      {
      routine_lstringhere (var_desc_26977, GALGAS_string::makeEmptyString (), inCompiler  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 903)) ;
      }
      GALGAS_arxmlMetaClass var_newClass_27011 = GALGAS_arxmlMetaClass::constructor_new (var_typeName_26071, GALGAS_bool (false), GALGAS_arxmlMetaElementList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 907)), GALGAS_arxmlMetaElementList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 907)), GALGAS_arxmlMetaAttributeList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 908)), GALGAS_arxmlMetaAttributeList::constructor_emptyList (SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 908)), var_desc_26977  COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 904)) ;
      {
      ioArgument_classMap.setter_insertKey (var_typeName_26071, var_newClass_27011, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 911)) ;
      }
      {
      ioArgument_classGraph.setter_addNode (var_typeName_26071, var_typeName_26071, inCompiler COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 912)) ;
      }
    }
  }
  switch (select_arxmlmetaparser_5F_syntax_47 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 915)) ;
    bool repeatFlag_5 = true ;
    while (repeatFlag_5) {
      if (select_arxmlmetaparser_5F_syntax_48 (inCompiler) == 2) {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 917)) ;
        switch (select_arxmlmetaparser_5F_syntax_49 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 918)) ;
          nt_xsd_5F_annotation_ (ioArgument_classMap, ioArgument_classGraph, var_typeName_26071, inCompiler) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_restriction COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 920)) ;
          nt_xsd_5F_restriction_ (ioArgument_classMap, ioArgument_classGraph, var_typeName_26071, var_restriction_26540, inCompiler) ;
        } break ;
        default:
          break ;
        }
      }else{
        repeatFlag_5 = false ;
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
    if (select_arxmlmetaparser_5F_syntax_46 (inCompiler) == 2) {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_name COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 883)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 884)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 885)) ;
    }else{
      repeatFlag_0 = false ;
    }
  }
  switch (select_arxmlmetaparser_5F_syntax_47 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 915)) ;
    bool repeatFlag_1 = true ;
    while (repeatFlag_1) {
      if (select_arxmlmetaparser_5F_syntax_48 (inCompiler) == 2) {
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
      }else{
        repeatFlag_1 = false ;
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

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_simpleType_i18_indexing (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    if (select_arxmlmetaparser_5F_syntax_46 (inCompiler) == 2) {
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_name COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 883)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 884)) ;
      inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 885)) ;
    }else{
      repeatFlag_0 = false ;
    }
  }
  switch (select_arxmlmetaparser_5F_syntax_47 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 915)) ;
    bool repeatFlag_1 = true ;
    while (repeatFlag_1) {
      if (select_arxmlmetaparser_5F_syntax_48 (inCompiler) == 2) {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 917)) ;
        switch (select_arxmlmetaparser_5F_syntax_49 (inCompiler)) {
        case 1: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 918)) ;
          nt_xsd_5F_annotation_indexing (inCompiler) ;
        } break ;
        case 2: {
          inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_restriction COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 920)) ;
          nt_xsd_5F_restriction_indexing (inCompiler) ;
        } break ;
        default:
          break ;
        }
      }else{
        repeatFlag_1 = false ;
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
      if (select_arxmlmetaparser_5F_syntax_51 (inCompiler) == 2) {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 947)) ;
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 948)) ;
        nt_xsd_5F_annotation_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
      }else{
        repeatFlag_0 = false ;
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
      if (select_arxmlmetaparser_5F_syntax_51 (inCompiler) == 2) {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 947)) ;
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 948)) ;
        nt_xsd_5F_annotation_parse (inCompiler) ;
      }else{
        repeatFlag_0 = false ;
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

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_maxLength_i19_indexing (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  nt_xsd_5F_ignore_5F_attributes_indexing (inCompiler) ;
  switch (select_arxmlmetaparser_5F_syntax_50 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 945)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      if (select_arxmlmetaparser_5F_syntax_51 (inCompiler) == 2) {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 947)) ;
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 948)) ;
        nt_xsd_5F_annotation_indexing (inCompiler) ;
      }else{
        repeatFlag_0 = false ;
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
      if (select_arxmlmetaparser_5F_syntax_53 (inCompiler) == 2) {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 972)) ;
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 973)) ;
        nt_xsd_5F_annotation_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
      }else{
        repeatFlag_0 = false ;
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
      if (select_arxmlmetaparser_5F_syntax_53 (inCompiler) == 2) {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 972)) ;
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 973)) ;
        nt_xsd_5F_annotation_parse (inCompiler) ;
      }else{
        repeatFlag_0 = false ;
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

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_pattern_i20_indexing (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  nt_xsd_5F_ignore_5F_attributes_indexing (inCompiler) ;
  switch (select_arxmlmetaparser_5F_syntax_52 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 970)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      if (select_arxmlmetaparser_5F_syntax_53 (inCompiler) == 2) {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 972)) ;
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 973)) ;
        nt_xsd_5F_annotation_indexing (inCompiler) ;
      }else{
        repeatFlag_0 = false ;
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
      if (select_arxmlmetaparser_5F_syntax_55 (inCompiler) == 2) {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 996)) ;
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 997)) ;
        nt_xsd_5F_annotation_ (ioArgument_classMap, ioArgument_classGraph, inArgument_parentClass, inCompiler) ;
      }else{
        repeatFlag_0 = false ;
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
      if (select_arxmlmetaparser_5F_syntax_55 (inCompiler) == 2) {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 996)) ;
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 997)) ;
        nt_xsd_5F_annotation_parse (inCompiler) ;
      }else{
        repeatFlag_0 = false ;
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

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_whiteSpace_i21_indexing (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
  nt_xsd_5F_ignore_5F_attributes_indexing (inCompiler) ;
  switch (select_arxmlmetaparser_5F_syntax_54 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 994)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      if (select_arxmlmetaparser_5F_syntax_55 (inCompiler) == 2) {
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_ COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 996)) ;
        inCompiler->acceptTerminal (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation COMMA_SOURCE_FILE ("arxmlmetaparser_syntax.galgas", 997)) ;
        nt_xsd_5F_annotation_indexing (inCompiler) ;
      }else{
        repeatFlag_0 = false ;
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

//---------------------------------------------------------------------------------------------------------------------*

void cParser_arxmlmetaparser_5F_syntax::rule_arxmlmetaparser_5F_syntax_xsd_5F_ignore_5F_attributes_i22_indexing (C_Lexique_arxmlmetaparser_5F_scanner * inCompiler) {
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

GALGAS_gtlDataList_2D_element GALGAS_gtlDataList_2D_element::constructor_new (const GALGAS_gtlData & in_data 
                                                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlDataList_2D_element result ;
  if (in_data.isValid ()) {
    result = GALGAS_gtlDataList_2D_element (in_data) ;
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
//     @gtlDataList-element generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlDataList_2D_element ("gtlDataList-element",
                                               nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlDataList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlDataList_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlDataList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
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
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlDataList_2D_element *> (p)) {
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

GALGAS_gtlVarMap_2D_element GALGAS_gtlVarMap_2D_element::constructor_new (const GALGAS_lstring & in_lkey,
                                                                          const GALGAS_gtlData & in_value 
                                                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlVarMap_2D_element result ;
  if (in_lkey.isValid () && in_value.isValid ()) {
    result = GALGAS_gtlVarMap_2D_element (in_lkey, in_value) ;
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
//     @gtlVarMap-element generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlVarMap_2D_element ("gtlVarMap-element",
                                             nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlVarMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlVarMap_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlVarMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
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
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlVarMap_2D_element *> (p)) {
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

GALGAS_gtlExpressionMap_2D_element GALGAS_gtlExpressionMap_2D_element::constructor_new (const GALGAS_lstring & in_lkey,
                                                                                        const GALGAS_gtlExpression & in_expression 
                                                                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlExpressionMap_2D_element result ;
  if (in_lkey.isValid () && in_expression.isValid ()) {
    result = GALGAS_gtlExpressionMap_2D_element (in_lkey, in_expression) ;
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
//     @gtlExpressionMap-element generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlExpressionMap_2D_element ("gtlExpressionMap-element",
                                                    nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlExpressionMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlExpressionMap_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlExpressionMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
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
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlExpressionMap_2D_element *> (p)) {
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

GALGAS_gtlTemplateMap_2D_element GALGAS_gtlTemplateMap_2D_element::constructor_new (const GALGAS_lstring & in_lkey,
                                                                                    const GALGAS_gtlTemplate & in_aTemplate 
                                                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlTemplateMap_2D_element result ;
  if (in_lkey.isValid () && in_aTemplate.isValid ()) {
    result = GALGAS_gtlTemplateMap_2D_element (in_lkey, in_aTemplate) ;
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
//     @gtlTemplateMap-element generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlTemplateMap_2D_element ("gtlTemplateMap-element",
                                                  nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlTemplateMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlTemplateMap_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlTemplateMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
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
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlTemplateMap_2D_element *> (p)) {
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

GALGAS_gtlExpressionList_2D_element GALGAS_gtlExpressionList_2D_element::constructor_new (const GALGAS_gtlExpression & in_expression 
                                                                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlExpressionList_2D_element result ;
  if (in_expression.isValid ()) {
    result = GALGAS_gtlExpressionList_2D_element (in_expression) ;
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
//     @gtlExpressionList-element generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlExpressionList_2D_element ("gtlExpressionList-element",
                                                     nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlExpressionList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlExpressionList_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlExpressionList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
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
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlExpressionList_2D_element *> (p)) {
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

GALGAS_list_2D_element GALGAS_list_2D_element::constructor_new (const GALGAS_gtlData & in_value 
                                                                COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_list_2D_element result ;
  if (in_value.isValid ()) {
    result = GALGAS_list_2D_element (in_value) ;
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
//     @list-element generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_list_2D_element ("list-element",
                                        nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_list_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_list_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_list_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
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
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_list_2D_element *> (p)) {
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

GALGAS_lstringset_2D_element GALGAS_lstringset_2D_element::constructor_new (const GALGAS_lstring & in_lkey 
                                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstringset_2D_element result ;
  if (in_lkey.isValid ()) {
    result = GALGAS_lstringset_2D_element (in_lkey) ;
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
//     @lstringset-element generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_lstringset_2D_element ("lstringset-element",
                                              nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_lstringset_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_lstringset_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_lstringset_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
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
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_lstringset_2D_element *> (p)) {
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

GALGAS_gtlArgumentList_2D_element GALGAS_gtlArgumentList_2D_element::constructor_new (const GALGAS_bool & in_typed,
                                                                                      const GALGAS_type & in_type,
                                                                                      const GALGAS_lstring & in_name 
                                                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlArgumentList_2D_element result ;
  if (in_typed.isValid () && in_type.isValid () && in_name.isValid ()) {
    result = GALGAS_gtlArgumentList_2D_element (in_typed, in_type, in_name) ;
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
//     @gtlArgumentList-element generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlArgumentList_2D_element ("gtlArgumentList-element",
                                                   nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlArgumentList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlArgumentList_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlArgumentList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
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
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlArgumentList_2D_element *> (p)) {
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

GALGAS_gtlProcMap_2D_element GALGAS_gtlProcMap_2D_element::constructor_new (const GALGAS_lstring & in_lkey,
                                                                            const GALGAS_gtlProcedure & in_procedure 
                                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlProcMap_2D_element result ;
  if (in_lkey.isValid () && in_procedure.isValid ()) {
    result = GALGAS_gtlProcMap_2D_element (in_lkey, in_procedure) ;
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
//     @gtlProcMap-element generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlProcMap_2D_element ("gtlProcMap-element",
                                              nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlProcMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlProcMap_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlProcMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
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
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlProcMap_2D_element *> (p)) {
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

GALGAS_gtlFuncMap_2D_element GALGAS_gtlFuncMap_2D_element::constructor_new (const GALGAS_lstring & in_lkey,
                                                                            const GALGAS_gtlFunction & in_function 
                                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlFuncMap_2D_element result ;
  if (in_lkey.isValid () && in_function.isValid ()) {
    result = GALGAS_gtlFuncMap_2D_element (in_lkey, in_function) ;
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
//     @gtlFuncMap-element generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlFuncMap_2D_element ("gtlFuncMap-element",
                                              nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlFuncMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlFuncMap_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlFuncMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
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
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlFuncMap_2D_element *> (p)) {
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

GALGAS_gtlGetterMap_2D_element GALGAS_gtlGetterMap_2D_element::constructor_new (const GALGAS_lstring & in_lkey,
                                                                                const GALGAS_gtlGetter & in_theGetter 
                                                                                COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlGetterMap_2D_element result ;
  if (in_lkey.isValid () && in_theGetter.isValid ()) {
    result = GALGAS_gtlGetterMap_2D_element (in_lkey, in_theGetter) ;
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
//     @gtlGetterMap-element generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlGetterMap_2D_element ("gtlGetterMap-element",
                                                nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlGetterMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlGetterMap_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlGetterMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
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
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlGetterMap_2D_element *> (p)) {
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

GALGAS_gtlSetterMap_2D_element GALGAS_gtlSetterMap_2D_element::constructor_new (const GALGAS_lstring & in_lkey,
                                                                                const GALGAS_gtlSetter & in_theSetter 
                                                                                COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlSetterMap_2D_element result ;
  if (in_lkey.isValid () && in_theSetter.isValid ()) {
    result = GALGAS_gtlSetterMap_2D_element (in_lkey, in_theSetter) ;
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
//     @gtlSetterMap-element generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlSetterMap_2D_element ("gtlSetterMap-element",
                                                nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlSetterMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlSetterMap_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlSetterMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
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
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlSetterMap_2D_element *> (p)) {
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

GALGAS_gtlThenElsifStatementList_2D_element GALGAS_gtlThenElsifStatementList_2D_element::constructor_new (const GALGAS_gtlExpression & in_condition,
                                                                                                          const GALGAS_gtlInstructionList & in_instructionList 
                                                                                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlThenElsifStatementList_2D_element result ;
  if (in_condition.isValid () && in_instructionList.isValid ()) {
    result = GALGAS_gtlThenElsifStatementList_2D_element (in_condition, in_instructionList) ;
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
//     @gtlThenElsifStatementList-element generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlThenElsifStatementList_2D_element ("gtlThenElsifStatementList-element",
                                                             nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_gtlThenElsifStatementList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlThenElsifStatementList_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_gtlThenElsifStatementList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
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
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_gtlThenElsifStatementList_2D_element *> (p)) {
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

GALGAS_sortingKeyList_2D_element GALGAS_sortingKeyList_2D_element::constructor_new (const GALGAS_lstring & in_key,
                                                                                    const GALGAS_lsint & in_order 
                                                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_sortingKeyList_2D_element result ;
  if (in_key.isValid () && in_order.isValid ()) {
    result = GALGAS_sortingKeyList_2D_element (in_key, in_order) ;
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
//     @sortingKeyList-element generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_sortingKeyList_2D_element ("sortingKeyList-element",
                                                  nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_sortingKeyList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_sortingKeyList_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_sortingKeyList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
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
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_sortingKeyList_2D_element *> (p)) {
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

GALGAS_numberList_2D_element GALGAS_numberList_2D_element::constructor_new (const GALGAS_location & in_location,
                                                                            const GALGAS_object_5F_t & in_value 
                                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_numberList_2D_element result ;
  if (in_location.isValid () && in_value.isValid ()) {
    result = GALGAS_numberList_2D_element (in_location, in_value) ;
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
//     @numberList-element generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_numberList_2D_element ("numberList-element",
                                              nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_numberList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_numberList_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_numberList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
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
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_numberList_2D_element *> (p)) {
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

GALGAS_implementationObjectMap_2D_element GALGAS_implementationObjectMap_2D_element::constructor_new (const GALGAS_lstring & in_lkey,
                                                                                                      const GALGAS_impType & in_type 
                                                                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_implementationObjectMap_2D_element result ;
  if (in_lkey.isValid () && in_type.isValid ()) {
    result = GALGAS_implementationObjectMap_2D_element (in_lkey, in_type) ;
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
//     @implementationObjectMap-element generic code implementation
//
//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_implementationObjectMap_2D_element ("implementationObjectMap-element",
                                                           nullptr) ;

//----------------------------------------------------------------------------------------------------------------------

const C_galgas_type_descriptor * GALGAS_implementationObjectMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_implementationObjectMap_2D_element ;
}

//----------------------------------------------------------------------------------------------------------------------

AC_GALGAS_root * GALGAS_implementationObjectMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = nullptr ;
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
  if (nullptr != p) {
    if (nullptr != dynamic_cast <const GALGAS_implementationObjectMap_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("implementationObjectMap-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

