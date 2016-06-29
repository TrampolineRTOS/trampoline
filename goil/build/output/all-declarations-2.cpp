#include "galgas2/C_Compiler.h"
#include "galgas2/C_galgas_io.h"
#include "galgas2/C_galgas_CLI_Options.h"
#include "utilities/C_PrologueEpilogue.h"

//----------------------------------------------------------------------------------------------------------------------

#include "all-declarations-2.h"


//----------------------------------------------------------------------------------------------------------------------

#include "utilities/MF_MemoryControl.h"
#include "galgas2/C_galgas_CLI_Options.h"

#include "files/C_FileManager.h"

//----------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                   L L ( 1 )    P R O D U C T I O N    R U L E S                                      
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

#define TERMINAL(t)     ((t)+1)
#define NONTERMINAL(nt) ((-nt)-1)
#define END_PRODUCTION  (0)

static const int16_t gProductions_goil_implementation_level_include [] = {
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
// At index 32 : <boolean>, in file 'goil_syntax.ggs', line 230
, NONTERMINAL (41) // <select_goil_5F_syntax_5>
, END_PRODUCTION
// At index 34 : <oil_declaration_list>, in file 'goil_syntax.ggs', line 240
, NONTERMINAL (42) // <select_goil_5F_syntax_6>
, END_PRODUCTION
// At index 36 : <oil_declaration>, in file 'goil_syntax.ggs', line 252
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (43) // <select_goil_5F_syntax_7>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, END_PRODUCTION
// At index 40 : <include_file_level>, in file 'goil_syntax.ggs', line 425
, NONTERMINAL (48) // <select_goil_5F_syntax_12>
, NONTERMINAL (49) // <select_goil_5F_syntax_13>
, END_PRODUCTION
// At index 43 : <include_cpu_level>, in file 'goil_syntax.ggs', line 449
, NONTERMINAL (50) // <select_goil_5F_syntax_14>
, NONTERMINAL (51) // <select_goil_5F_syntax_15>
, END_PRODUCTION
// At index 46 : <include_object_level>, in file 'goil_syntax.ggs', line 473
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
// At index 65 : <implementation_type>, in file 'implementation_parser.ggs', line 212
, NONTERMINAL (61) // <select_implementation_5F_parser_7>
, END_PRODUCTION
// At index 67 : <struct_options>, in file 'implementation_parser.ggs', line 240
, NONTERMINAL (62) // <select_implementation_5F_parser_8>
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (33) // <multiple>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 72 : <objref_option>, in file 'implementation_parser.ggs', line 257
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (33) // <multiple>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 76 : <string_options>, in file 'implementation_parser.ggs', line 275
, NONTERMINAL (28) // <with_auto>
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (33) // <multiple>
, NONTERMINAL (63) // <select_implementation_5F_parser_9>
, END_PRODUCTION
// At index 81 : <boolean_options>, in file 'implementation_parser.ggs', line 307
, NONTERMINAL (28) // <with_auto>
, NONTERMINAL (65) // <select_implementation_5F_parser_11>
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (33) // <multiple>
, NONTERMINAL (68) // <select_implementation_5F_parser_14>
, END_PRODUCTION
// At index 87 : <enum_item>, in file 'implementation_parser.ggs', line 352
, NONTERMINAL (35) // <identifier_or_enum_value>
, NONTERMINAL (69) // <select_implementation_5F_parser_15>
, END_PRODUCTION
// At index 90 : <enum_options>, in file 'implementation_parser.ggs', line 365
, NONTERMINAL (28) // <with_auto>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) // $[$
, NONTERMINAL (24) // <enum_item>
, NONTERMINAL (70) // <select_implementation_5F_parser_16>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) // $]$
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (33) // <multiple>
, NONTERMINAL (71) // <select_implementation_5F_parser_17>
, END_PRODUCTION
// At index 99 : <number_options>, in file 'implementation_parser.ggs', line 407
, NONTERMINAL (28) // <with_auto>
, NONTERMINAL (32) // <range>
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (33) // <multiple>
, NONTERMINAL (73) // <select_implementation_5F_parser_19>
, END_PRODUCTION
// At index 105 : <type_options>, in file 'implementation_parser.ggs', line 441
, NONTERMINAL (28) // <with_auto>
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (33) // <multiple>
, NONTERMINAL (75) // <select_implementation_5F_parser_21>
, END_PRODUCTION
// At index 110 : <with_auto>, in file 'implementation_parser.ggs', line 475
, NONTERMINAL (77) // <select_implementation_5F_parser_23>
, END_PRODUCTION
// At index 112 : <int_or_float>, in file 'implementation_parser.ggs', line 484
, NONTERMINAL (3) // <sign>
, NONTERMINAL (78) // <select_implementation_5F_parser_24>
, END_PRODUCTION
// At index 115 : <set_followup>, in file 'implementation_parser.ggs', line 502
, NONTERMINAL (79) // <select_implementation_5F_parser_25>
, END_PRODUCTION
// At index 117 : <range_content>, in file 'implementation_parser.ggs', line 514
, NONTERMINAL (3) // <sign>
, NONTERMINAL (80) // <select_implementation_5F_parser_26>
, END_PRODUCTION
// At index 120 : <range>, in file 'implementation_parser.ggs', line 554
, NONTERMINAL (83) // <select_implementation_5F_parser_29>
, END_PRODUCTION
// At index 122 : <multiple>, in file 'implementation_parser.ggs', line 564
, NONTERMINAL (84) // <select_implementation_5F_parser_30>
, END_PRODUCTION
// At index 124 : <identifier_or_attribute>, in file 'implementation_parser.ggs', line 574
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, END_PRODUCTION
// At index 126 : <identifier_or_enum_value>, in file 'implementation_parser.ggs', line 579
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
// At index 165 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 231
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_TRUE) // $TRUE$
, END_PRODUCTION
// At index 167 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 231
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_FALSE) // $FALSE$
, END_PRODUCTION
// At index 169 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 244
, END_PRODUCTION
// At index 170 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 244
, NONTERMINAL (10) // <oil_declaration>
, NONTERMINAL (42) // <select_goil_5F_syntax_6>
, END_PRODUCTION
// At index 173 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 244
, NONTERMINAL (13) // <include_object_level>
, NONTERMINAL (42) // <select_goil_5F_syntax_6>
, END_PRODUCTION
// At index 176 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 269
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (44) // <select_goil_5F_syntax_8>
, END_PRODUCTION
// At index 179 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 269
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (9) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 185 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (45) // <select_goil_5F_syntax_9>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 189 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
, NONTERMINAL (3) // <sign>
, NONTERMINAL (46) // <select_goil_5F_syntax_10>
, END_PRODUCTION
// At index 192 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
, NONTERMINAL (8) // <boolean>
, NONTERMINAL (47) // <select_goil_5F_syntax_11>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 196 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 199 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) // $AUTO$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 202 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 292
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (9) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 206 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 292
, END_PRODUCTION
// At index 207 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 309
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) // $uint_number$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 210 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 309
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_float_5F_number) // $float_number$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 213 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 340
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (9) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 217 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 340
, END_PRODUCTION
// At index 218 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 432
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) // $include$
, END_PRODUCTION
// At index 220 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 432
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) // $includeifexists$
, END_PRODUCTION
// At index 222 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 438
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) // $g_string$
, END_PRODUCTION
// At index 224 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 438
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, END_PRODUCTION
// At index 226 : <select_goil_5F_syntax_14>, in file 'goil_syntax.ggs', line 456
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) // $include$
, END_PRODUCTION
// At index 228 : <select_goil_5F_syntax_14>, in file 'goil_syntax.ggs', line 456
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) // $includeifexists$
, END_PRODUCTION
// At index 230 : <select_goil_5F_syntax_15>, in file 'goil_syntax.ggs', line 462
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) // $g_string$
, END_PRODUCTION
// At index 232 : <select_goil_5F_syntax_15>, in file 'goil_syntax.ggs', line 462
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, END_PRODUCTION
// At index 234 : <select_goil_5F_syntax_16>, in file 'goil_syntax.ggs', line 478
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) // $include$
, END_PRODUCTION
// At index 236 : <select_goil_5F_syntax_16>, in file 'goil_syntax.ggs', line 478
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) // $includeifexists$
, END_PRODUCTION
// At index 238 : <select_goil_5F_syntax_17>, in file 'goil_syntax.ggs', line 484
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) // $g_string$
, END_PRODUCTION
// At index 240 : <select_goil_5F_syntax_17>, in file 'goil_syntax.ggs', line 484
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
// At index 278 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_UINT_33__32_) // $UINT32$
, NONTERMINAL (26) // <number_options>
, END_PRODUCTION
// At index 281 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_INT_33__32_) // $INT32$
, NONTERMINAL (26) // <number_options>
, END_PRODUCTION
// At index 284 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_UINT_36__34_) // $UINT64$
, NONTERMINAL (26) // <number_options>
, END_PRODUCTION
// At index 287 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_INT_36__34_) // $INT64$
, NONTERMINAL (26) // <number_options>
, END_PRODUCTION
// At index 290 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_FLOAT) // $FLOAT$
, NONTERMINAL (26) // <number_options>
, END_PRODUCTION
// At index 293 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_ENUM) // $ENUM$
, NONTERMINAL (25) // <enum_options>
, END_PRODUCTION
// At index 296 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_BOOLEAN) // $BOOLEAN$
, NONTERMINAL (23) // <boolean_options>
, END_PRODUCTION
// At index 299 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_STRING) // $STRING$
, NONTERMINAL (22) // <string_options>
, END_PRODUCTION
// At index 302 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_IDENTIFIER) // $IDENTIFIER$
, NONTERMINAL (27) // <type_options>
, END_PRODUCTION
// At index 305 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_STRUCT) // $STRUCT$
, NONTERMINAL (20) // <struct_options>
, END_PRODUCTION
// At index 308 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (21) // <objref_option>
, END_PRODUCTION
// At index 311 : <select_implementation_5F_parser_8>, in file 'implementation_parser.ggs', line 244
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (18) // <implementation_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 315 : <select_implementation_5F_parser_8>, in file 'implementation_parser.ggs', line 244
, END_PRODUCTION
// At index 316 : <select_implementation_5F_parser_9>, in file 'implementation_parser.ggs', line 285
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (64) // <select_implementation_5F_parser_10>
, END_PRODUCTION
// At index 319 : <select_implementation_5F_parser_9>, in file 'implementation_parser.ggs', line 285
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 321 : <select_implementation_5F_parser_10>, in file 'implementation_parser.ggs', line 287
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 324 : <select_implementation_5F_parser_10>, in file 'implementation_parser.ggs', line 287
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) // $AUTO$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 327 : <select_implementation_5F_parser_10>, in file 'implementation_parser.ggs', line 287
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT) // $NO_DEFAULT$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 330 : <select_implementation_5F_parser_11>, in file 'implementation_parser.ggs', line 314
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) // $[$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_TRUE) // $TRUE$
, NONTERMINAL (66) // <select_implementation_5F_parser_12>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2C_) // $,$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_FALSE) // $FALSE$
, NONTERMINAL (67) // <select_implementation_5F_parser_13>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) // $]$
, END_PRODUCTION
// At index 338 : <select_implementation_5F_parser_11>, in file 'implementation_parser.ggs', line 314
, END_PRODUCTION
// At index 339 : <select_implementation_5F_parser_12>, in file 'implementation_parser.ggs', line 317
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (18) // <implementation_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 343 : <select_implementation_5F_parser_12>, in file 'implementation_parser.ggs', line 317
, END_PRODUCTION
// At index 344 : <select_implementation_5F_parser_13>, in file 'implementation_parser.ggs', line 326
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (18) // <implementation_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 348 : <select_implementation_5F_parser_13>, in file 'implementation_parser.ggs', line 326
, END_PRODUCTION
// At index 349 : <select_implementation_5F_parser_14>, in file 'implementation_parser.ggs', line 340
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (8) // <boolean>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 353 : <select_implementation_5F_parser_14>, in file 'implementation_parser.ggs', line 340
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 355 : <select_implementation_5F_parser_15>, in file 'implementation_parser.ggs', line 357
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (18) // <implementation_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 359 : <select_implementation_5F_parser_15>, in file 'implementation_parser.ggs', line 357
, END_PRODUCTION
// At index 360 : <select_implementation_5F_parser_16>, in file 'implementation_parser.ggs', line 373
, END_PRODUCTION
// At index 361 : <select_implementation_5F_parser_16>, in file 'implementation_parser.ggs', line 373
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2C_) // $,$
, NONTERMINAL (24) // <enum_item>
, NONTERMINAL (70) // <select_implementation_5F_parser_16>
, END_PRODUCTION
// At index 365 : <select_implementation_5F_parser_17>, in file 'implementation_parser.ggs', line 383
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (72) // <select_implementation_5F_parser_18>
, END_PRODUCTION
// At index 368 : <select_implementation_5F_parser_17>, in file 'implementation_parser.ggs', line 383
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 370 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 385
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 373 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 385
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) // $AUTO$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 376 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 385
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT) // $NO_DEFAULT$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 379 : <select_implementation_5F_parser_19>, in file 'implementation_parser.ggs', line 420
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (74) // <select_implementation_5F_parser_20>
, END_PRODUCTION
// At index 382 : <select_implementation_5F_parser_19>, in file 'implementation_parser.ggs', line 420
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 384 : <select_implementation_5F_parser_20>, in file 'implementation_parser.ggs', line 422
, NONTERMINAL (29) // <int_or_float>
, END_PRODUCTION
// At index 386 : <select_implementation_5F_parser_20>, in file 'implementation_parser.ggs', line 422
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT) // $NO_DEFAULT$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 389 : <select_implementation_5F_parser_20>, in file 'implementation_parser.ggs', line 422
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) // $AUTO$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 392 : <select_implementation_5F_parser_21>, in file 'implementation_parser.ggs', line 452
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (76) // <select_implementation_5F_parser_22>
, END_PRODUCTION
// At index 395 : <select_implementation_5F_parser_21>, in file 'implementation_parser.ggs', line 452
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 397 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 454
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 400 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 454
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT) // $NO_DEFAULT$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 403 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 454
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) // $AUTO$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 406 : <select_implementation_5F_parser_23>, in file 'implementation_parser.ggs', line 477
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_WITH_5F_AUTO) // $WITH_AUTO$
, END_PRODUCTION
// At index 408 : <select_implementation_5F_parser_23>, in file 'implementation_parser.ggs', line 477
, END_PRODUCTION
// At index 409 : <select_implementation_5F_parser_24>, in file 'implementation_parser.ggs', line 489
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) // $uint_number$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 412 : <select_implementation_5F_parser_24>, in file 'implementation_parser.ggs', line 489
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_float_5F_number) // $float_number$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 415 : <select_implementation_5F_parser_25>, in file 'implementation_parser.ggs', line 505
, END_PRODUCTION
// At index 416 : <select_implementation_5F_parser_25>, in file 'implementation_parser.ggs', line 505
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2C_) // $,$
, NONTERMINAL (29) // <int_or_float>
, NONTERMINAL (79) // <select_implementation_5F_parser_25>
, END_PRODUCTION
// At index 420 : <select_implementation_5F_parser_26>, in file 'implementation_parser.ggs', line 521
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_set_5F_start_5F_uint_5F_number) // $set_start_uint_number$
, NONTERMINAL (29) // <int_or_float>
, END_PRODUCTION
// At index 423 : <select_implementation_5F_parser_26>, in file 'implementation_parser.ggs', line 521
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) // $uint_number$
, NONTERMINAL (81) // <select_implementation_5F_parser_27>
, END_PRODUCTION
// At index 426 : <select_implementation_5F_parser_26>, in file 'implementation_parser.ggs', line 521
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_float_5F_number) // $float_number$
, NONTERMINAL (82) // <select_implementation_5F_parser_28>
, END_PRODUCTION
// At index 429 : <select_implementation_5F_parser_27>, in file 'implementation_parser.ggs', line 531
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2E__2E_) // $..$
, NONTERMINAL (29) // <int_or_float>
, END_PRODUCTION
// At index 432 : <select_implementation_5F_parser_27>, in file 'implementation_parser.ggs', line 531
, NONTERMINAL (30) // <set_followup>
, END_PRODUCTION
// At index 434 : <select_implementation_5F_parser_28>, in file 'implementation_parser.ggs', line 543
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2E__2E_) // $..$
, NONTERMINAL (29) // <int_or_float>
, END_PRODUCTION
// At index 437 : <select_implementation_5F_parser_28>, in file 'implementation_parser.ggs', line 543
, NONTERMINAL (30) // <set_followup>
, END_PRODUCTION
// At index 439 : <select_implementation_5F_parser_29>, in file 'implementation_parser.ggs', line 557
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) // $[$
, NONTERMINAL (31) // <range_content>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) // $]$
, END_PRODUCTION
// At index 443 : <select_implementation_5F_parser_29>, in file 'implementation_parser.ggs', line 557
, END_PRODUCTION
// At index 444 : <select_implementation_5F_parser_30>, in file 'implementation_parser.ggs', line 566
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) // $[$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) // $]$
, END_PRODUCTION
// At index 447 : <select_implementation_5F_parser_30>, in file 'implementation_parser.ggs', line 566
, END_PRODUCTION
// At index 448 : <>, in file '.ggs', line 0
, NONTERMINAL (14) // <implementation_object_list>
, END_PRODUCTION
} ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                          P R O D U C T I O N    N A M E S                                            
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

static const cProductionNameDescriptor gProductionNames_goil_implementation_level_include [159] = {
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

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                 L L ( 1 )    P R O D U C T I O N    I N D E X E S                                    
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

static const int16_t gProductionIndexes_goil_implementation_level_include [159] = {
0, // index 0 : <implementation_definition>, in file 'implementation_parser.ggs', line 55
7, // index 1 : <start>, in file 'goil_syntax.ggs', line 38
10, // index 2 : <file>, in file 'goil_syntax.ggs', line 110
12, // index 3 : <sign>, in file 'goil_syntax.ggs', line 126
14, // index 4 : <description>, in file 'goil_syntax.ggs', line 139
16, // index 5 : <OIL_version>, in file 'goil_syntax.ggs', line 163
22, // index 6 : <application_definition>, in file 'goil_syntax.ggs', line 170
30, // index 7 : <object_definition_list>, in file 'goil_syntax.ggs', line 184
32, // index 8 : <boolean>, in file 'goil_syntax.ggs', line 230
34, // index 9 : <oil_declaration_list>, in file 'goil_syntax.ggs', line 240
36, // index 10 : <oil_declaration>, in file 'goil_syntax.ggs', line 252
40, // index 11 : <include_file_level>, in file 'goil_syntax.ggs', line 425
43, // index 12 : <include_cpu_level>, in file 'goil_syntax.ggs', line 449
46, // index 13 : <include_object_level>, in file 'goil_syntax.ggs', line 473
49, // index 14 : <implementation_object_list>, in file 'implementation_parser.ggs', line 62
51, // index 15 : <include_implementation_level>, in file 'implementation_parser.ggs', line 71
54, // index 16 : <include_type_level>, in file 'implementation_parser.ggs', line 92
57, // index 17 : <implementation_objects>, in file 'implementation_parser.ggs', line 135
63, // index 18 : <implementation_list>, in file 'implementation_parser.ggs', line 183
65, // index 19 : <implementation_type>, in file 'implementation_parser.ggs', line 212
67, // index 20 : <struct_options>, in file 'implementation_parser.ggs', line 240
72, // index 21 : <objref_option>, in file 'implementation_parser.ggs', line 257
76, // index 22 : <string_options>, in file 'implementation_parser.ggs', line 275
81, // index 23 : <boolean_options>, in file 'implementation_parser.ggs', line 307
87, // index 24 : <enum_item>, in file 'implementation_parser.ggs', line 352
90, // index 25 : <enum_options>, in file 'implementation_parser.ggs', line 365
99, // index 26 : <number_options>, in file 'implementation_parser.ggs', line 407
105, // index 27 : <type_options>, in file 'implementation_parser.ggs', line 441
110, // index 28 : <with_auto>, in file 'implementation_parser.ggs', line 475
112, // index 29 : <int_or_float>, in file 'implementation_parser.ggs', line 484
115, // index 30 : <set_followup>, in file 'implementation_parser.ggs', line 502
117, // index 31 : <range_content>, in file 'implementation_parser.ggs', line 514
120, // index 32 : <range>, in file 'implementation_parser.ggs', line 554
122, // index 33 : <multiple>, in file 'implementation_parser.ggs', line 564
124, // index 34 : <identifier_or_attribute>, in file 'implementation_parser.ggs', line 574
126, // index 35 : <identifier_or_enum_value>, in file 'implementation_parser.ggs', line 579
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
165, // index 50 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 231
167, // index 51 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 231
169, // index 52 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 244
170, // index 53 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 244
173, // index 54 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 244
176, // index 55 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 269
179, // index 56 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 269
185, // index 57 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
189, // index 58 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
192, // index 59 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
196, // index 60 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
199, // index 61 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
202, // index 62 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 292
206, // index 63 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 292
207, // index 64 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 309
210, // index 65 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 309
213, // index 66 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 340
217, // index 67 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 340
218, // index 68 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 432
220, // index 69 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 432
222, // index 70 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 438
224, // index 71 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 438
226, // index 72 : <select_goil_5F_syntax_14>, in file 'goil_syntax.ggs', line 456
228, // index 73 : <select_goil_5F_syntax_14>, in file 'goil_syntax.ggs', line 456
230, // index 74 : <select_goil_5F_syntax_15>, in file 'goil_syntax.ggs', line 462
232, // index 75 : <select_goil_5F_syntax_15>, in file 'goil_syntax.ggs', line 462
234, // index 76 : <select_goil_5F_syntax_16>, in file 'goil_syntax.ggs', line 478
236, // index 77 : <select_goil_5F_syntax_16>, in file 'goil_syntax.ggs', line 478
238, // index 78 : <select_goil_5F_syntax_17>, in file 'goil_syntax.ggs', line 484
240, // index 79 : <select_goil_5F_syntax_17>, in file 'goil_syntax.ggs', line 484
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
278, // index 96 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
281, // index 97 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
284, // index 98 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
287, // index 99 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
290, // index 100 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
293, // index 101 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
296, // index 102 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
299, // index 103 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
302, // index 104 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
305, // index 105 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
308, // index 106 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
311, // index 107 : <select_implementation_5F_parser_8>, in file 'implementation_parser.ggs', line 244
315, // index 108 : <select_implementation_5F_parser_8>, in file 'implementation_parser.ggs', line 244
316, // index 109 : <select_implementation_5F_parser_9>, in file 'implementation_parser.ggs', line 285
319, // index 110 : <select_implementation_5F_parser_9>, in file 'implementation_parser.ggs', line 285
321, // index 111 : <select_implementation_5F_parser_10>, in file 'implementation_parser.ggs', line 287
324, // index 112 : <select_implementation_5F_parser_10>, in file 'implementation_parser.ggs', line 287
327, // index 113 : <select_implementation_5F_parser_10>, in file 'implementation_parser.ggs', line 287
330, // index 114 : <select_implementation_5F_parser_11>, in file 'implementation_parser.ggs', line 314
338, // index 115 : <select_implementation_5F_parser_11>, in file 'implementation_parser.ggs', line 314
339, // index 116 : <select_implementation_5F_parser_12>, in file 'implementation_parser.ggs', line 317
343, // index 117 : <select_implementation_5F_parser_12>, in file 'implementation_parser.ggs', line 317
344, // index 118 : <select_implementation_5F_parser_13>, in file 'implementation_parser.ggs', line 326
348, // index 119 : <select_implementation_5F_parser_13>, in file 'implementation_parser.ggs', line 326
349, // index 120 : <select_implementation_5F_parser_14>, in file 'implementation_parser.ggs', line 340
353, // index 121 : <select_implementation_5F_parser_14>, in file 'implementation_parser.ggs', line 340
355, // index 122 : <select_implementation_5F_parser_15>, in file 'implementation_parser.ggs', line 357
359, // index 123 : <select_implementation_5F_parser_15>, in file 'implementation_parser.ggs', line 357
360, // index 124 : <select_implementation_5F_parser_16>, in file 'implementation_parser.ggs', line 373
361, // index 125 : <select_implementation_5F_parser_16>, in file 'implementation_parser.ggs', line 373
365, // index 126 : <select_implementation_5F_parser_17>, in file 'implementation_parser.ggs', line 383
368, // index 127 : <select_implementation_5F_parser_17>, in file 'implementation_parser.ggs', line 383
370, // index 128 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 385
373, // index 129 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 385
376, // index 130 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 385
379, // index 131 : <select_implementation_5F_parser_19>, in file 'implementation_parser.ggs', line 420
382, // index 132 : <select_implementation_5F_parser_19>, in file 'implementation_parser.ggs', line 420
384, // index 133 : <select_implementation_5F_parser_20>, in file 'implementation_parser.ggs', line 422
386, // index 134 : <select_implementation_5F_parser_20>, in file 'implementation_parser.ggs', line 422
389, // index 135 : <select_implementation_5F_parser_20>, in file 'implementation_parser.ggs', line 422
392, // index 136 : <select_implementation_5F_parser_21>, in file 'implementation_parser.ggs', line 452
395, // index 137 : <select_implementation_5F_parser_21>, in file 'implementation_parser.ggs', line 452
397, // index 138 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 454
400, // index 139 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 454
403, // index 140 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 454
406, // index 141 : <select_implementation_5F_parser_23>, in file 'implementation_parser.ggs', line 477
408, // index 142 : <select_implementation_5F_parser_23>, in file 'implementation_parser.ggs', line 477
409, // index 143 : <select_implementation_5F_parser_24>, in file 'implementation_parser.ggs', line 489
412, // index 144 : <select_implementation_5F_parser_24>, in file 'implementation_parser.ggs', line 489
415, // index 145 : <select_implementation_5F_parser_25>, in file 'implementation_parser.ggs', line 505
416, // index 146 : <select_implementation_5F_parser_25>, in file 'implementation_parser.ggs', line 505
420, // index 147 : <select_implementation_5F_parser_26>, in file 'implementation_parser.ggs', line 521
423, // index 148 : <select_implementation_5F_parser_26>, in file 'implementation_parser.ggs', line 521
426, // index 149 : <select_implementation_5F_parser_26>, in file 'implementation_parser.ggs', line 521
429, // index 150 : <select_implementation_5F_parser_27>, in file 'implementation_parser.ggs', line 531
432, // index 151 : <select_implementation_5F_parser_27>, in file 'implementation_parser.ggs', line 531
434, // index 152 : <select_implementation_5F_parser_28>, in file 'implementation_parser.ggs', line 543
437, // index 153 : <select_implementation_5F_parser_28>, in file 'implementation_parser.ggs', line 543
439, // index 154 : <select_implementation_5F_parser_29>, in file 'implementation_parser.ggs', line 557
443, // index 155 : <select_implementation_5F_parser_29>, in file 'implementation_parser.ggs', line 557
444, // index 156 : <select_implementation_5F_parser_30>, in file 'implementation_parser.ggs', line 566
447, // index 157 : <select_implementation_5F_parser_30>, in file 'implementation_parser.ggs', line 566
448 // index 158 : <>, in file '.ggs', line 0
} ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                           L L ( 1 )    F I R S T    P R O D U C T I O N    I N D E X E S                             
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

static const int16_t gFirstProductionIndexes_goil_implementation_level_include [87] = {
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

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                    L L ( 1 )    D E C I S I O N    T A B L E S                                       
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

static const int16_t gDecision_goil_implementation_level_include [] = {
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
C_Lexique_goil_5F_lexique::kToken__7D_, C_Lexique_goil_5F_lexique::kToken_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_include, C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 3
  -1,
// At index 166 : <select_implementation_5F_parser_1>
C_Lexique_goil_5F_lexique::kToken_include, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
  -1,
// At index 171 : <select_implementation_5F_parser_2>
C_Lexique_goil_5F_lexique::kToken_g_5F_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 176 : <select_implementation_5F_parser_3>
C_Lexique_goil_5F_lexique::kToken_include, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
  -1,
// At index 181 : <select_implementation_5F_parser_4>
C_Lexique_goil_5F_lexique::kToken_g_5F_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 186 : <select_implementation_5F_parser_5>
C_Lexique_goil_5F_lexique::kToken__5B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 2
  -1,
// At index 191 : <select_implementation_5F_parser_6>
C_Lexique_goil_5F_lexique::kToken__7D_, -1, // Choice 1
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

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                            L L ( 1 )    D E C I S I O N    T A B L E S    I N D E X E S                              
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

static const int16_t gDecisionIndexes_goil_implementation_level_include [87] = {
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
166, // at 55 : <select_implementation_5F_parser_1>
171, // at 56 : <select_implementation_5F_parser_2>
176, // at 57 : <select_implementation_5F_parser_3>
181, // at 58 : <select_implementation_5F_parser_4>
186, // at 59 : <select_implementation_5F_parser_5>
191, // at 60 : <select_implementation_5F_parser_6>
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

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                              'implementation_definition' non terminal implementation                                 
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_implementation_5F_definition_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_definition_i0_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_implementation_5F_definition_ (GALGAS_implementation & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_definition_i0_(parameter_1, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                        'start' non terminal implementation                                           
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_start_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_start_i0_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_start_ (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_start_i0_(inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                         'file' non terminal implementation                                           
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_file_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_file_i1_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_file_ (GALGAS_implementation & parameter_1,
                                GALGAS_applicationDefinition & parameter_2,
                                GALGAS_string & parameter_3,
                                const GALGAS_bool parameter_4,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_file_i1_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                         'sign' non terminal implementation                                           
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_sign_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_sign_i2_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_sign_ (GALGAS_bool & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_sign_i2_(parameter_1, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                     'description' non terminal implementation                                        
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_description_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_description_i3_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_description_ (GALGAS_lstring & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_description_i3_(parameter_1, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                     'OIL_version' non terminal implementation                                        
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_OIL_5F_version_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_OIL_5F_version_i4_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_OIL_5F_version_ (GALGAS_lstring & parameter_1,
                                GALGAS_lstring & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_OIL_5F_version_i4_(parameter_1, parameter_2, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                'application_definition' non terminal implementation                                  
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_application_5F_definition_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_application_5F_definition_i5_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_application_5F_definition_ (const GALGAS_implementation parameter_1,
                                GALGAS_applicationDefinition & parameter_2,
                                GALGAS_string & parameter_3,
                                const GALGAS_bool parameter_4,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_application_5F_definition_i5_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                'object_definition_list' non terminal implementation                                  
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_object_5F_definition_5F_list_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_object_5F_definition_5F_list_i6_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_object_5F_definition_5F_list_ (const GALGAS_implementation parameter_1,
                                GALGAS_objectsMap & parameter_2,
                                GALGAS_string & parameter_3,
                                const GALGAS_bool parameter_4,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_object_5F_definition_5F_list_i6_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                       'boolean' non terminal implementation                                          
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_boolean_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_boolean_i7_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_boolean_ (GALGAS_lbool & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_boolean_i7_(parameter_1, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                 'oil_declaration_list' non terminal implementation                                   
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_oil_5F_declaration_5F_list_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_5F_list_i8_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_oil_5F_declaration_5F_list_ (const GALGAS_implementationObjectMap parameter_1,
                                GALGAS_objectAttributes & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_5F_list_i8_(parameter_1, parameter_2, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                   'oil_declaration' non terminal implementation                                      
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_oil_5F_declaration_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_i9_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_oil_5F_declaration_ (const GALGAS_implementationObjectMap parameter_1,
                                GALGAS_objectAttributes & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_i9_(parameter_1, parameter_2, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                  'include_file_level' non terminal implementation                                    
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_include_5F_file_5F_level_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_file_5F_level_i10_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_include_5F_file_5F_level_ (GALGAS_implementation & parameter_1,
                                GALGAS_applicationDefinition & parameter_2,
                                GALGAS_string & parameter_3,
                                const GALGAS_bool parameter_4,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_file_5F_level_i10_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                  'include_cpu_level' non terminal implementation                                     
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_include_5F_cpu_5F_level_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_cpu_5F_level_i11_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_include_5F_cpu_5F_level_ (const GALGAS_implementation parameter_1,
                                GALGAS_objectsMap & parameter_2,
                                GALGAS_string & parameter_3,
                                const GALGAS_bool parameter_4,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_cpu_5F_level_i11_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                 'include_object_level' non terminal implementation                                   
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_include_5F_object_5F_level_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_object_5F_level_i12_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_include_5F_object_5F_level_ (const GALGAS_implementationObjectMap parameter_1,
                                GALGAS_objectAttributes & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_object_5F_level_i12_(parameter_1, parameter_2, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                              'implementation_object_list' non terminal implementation                                
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_implementation_5F_object_5F_list_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_object_5F_list_i1_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_implementation_5F_object_5F_list_ (GALGAS_implementation & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_object_5F_list_i1_(parameter_1, inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::performIndexing (C_Compiler * /* inCompiler */,
             const C_String & /* inSourceFilePath */) {
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::performOnlyLexicalAnalysis (C_Compiler * inCompiler,
             const C_String & inSourceFilePath) {
  C_Lexique_goil_5F_lexique * scanner = NULL ;
  macroMyNew (scanner, C_Lexique_goil_5F_lexique (inCompiler, "", "", inSourceFilePath COMMA_HERE)) ;
  if (scanner->sourceText () != NULL) {
    scanner->performLexicalAnalysis () ;
  }
  macroDetachSharedObject (scanner) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::performOnlySyntaxAnalysis (C_Compiler * inCompiler,
             const C_String & inSourceFilePath) {
  C_Lexique_goil_5F_lexique * scanner = NULL ;
  macroMyNew (scanner, C_Lexique_goil_5F_lexique (inCompiler, "", "", inSourceFilePath COMMA_HERE)) ;
  if (scanner->sourceText () != NULL) {
    scanner->performTopDownParsing (gProductions_goil_implementation_level_include, gProductionNames_goil_implementation_level_include, gProductionIndexes_goil_implementation_level_include,
                                    gFirstProductionIndexes_goil_implementation_level_include, gDecision_goil_implementation_level_include, gDecisionIndexes_goil_implementation_level_include, 448) ;
  }
  macroDetachSharedObject (scanner) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                        Grammar start symbol implementation                                           
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_implementation_5F_level_5F_include::_performSourceFileParsing_ (C_Compiler * inCompiler,
                                GALGAS_lstring inFilePath,
                                GALGAS_implementation &  parameter_1
                                COMMA_LOCATION_ARGS) {
  if (inFilePath.isValid ()) {
    const GALGAS_string filePathAsString = inFilePath.getter_string (HERE) ;
    C_String filePath = filePathAsString.stringValue () ;
    if (! C_FileManager::isAbsolutePath (filePath)) {
      filePath = inCompiler->sourceFilePath ().stringByDeletingLastPathComponent ().stringByAppendingPathComponent (filePath) ;
    }
    if (C_FileManager::fileExistsAtPath (filePath)) {
    C_Lexique_goil_5F_lexique * scanner = NULL ;
    macroMyNew (scanner, C_Lexique_goil_5F_lexique (inCompiler, "", "", filePath COMMA_HERE)) ;
    if (scanner->sourceText () != NULL) {
      const bool ok = scanner->performTopDownParsing (gProductions_goil_implementation_level_include, gProductionNames_goil_implementation_level_include, gProductionIndexes_goil_implementation_level_include,
                                                      gFirstProductionIndexes_goil_implementation_level_include, gDecision_goil_implementation_level_include, gDecisionIndexes_goil_implementation_level_include, 448) ;
      if (ok && ! executionModeIsSyntaxAnalysisOnly ()) {
        cGrammar_goil_5F_implementation_5F_level_5F_include grammar ;
        grammar.nt_implementation_5F_object_5F_list_ (parameter_1, scanner) ;
        }
      }else{
        C_String message ;
        message << "the '" << filePath << "' file exists, but cannot be read" ;
        const GALGAS_location errorLocation (inFilePath.getter_location (THERE)) ;
        inCompiler->semanticErrorAtLocation (errorLocation, message COMMA_THERE) ;
      }
      macroDetachSharedObject (scanner) ;
    }else{
      C_String message ;
      message << "the '" << filePath << "' file does not exist" ;
      const GALGAS_location errorLocation (inFilePath.getter_location (THERE)) ;
      inCompiler->semanticErrorAtLocation (errorLocation, message COMMA_THERE) ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_implementation_5F_level_5F_include::_performSourceStringParsing_ (C_Compiler * inCompiler,
                                GALGAS_string inSourceString,
                                GALGAS_string inNameString,
                                GALGAS_implementation &  parameter_1
                                COMMA_UNUSED_LOCATION_ARGS) {
  if (inSourceString.isValid () && inNameString.isValid ()) {
    const C_String sourceString = inSourceString.stringValue () ;
    const C_String nameString = inNameString.stringValue () ;
    C_Lexique_goil_5F_lexique * scanner = NULL ;
    macroMyNew (scanner, C_Lexique_goil_5F_lexique (inCompiler, sourceString, nameString COMMA_HERE)) ;
    const bool ok = scanner->performTopDownParsing (gProductions_goil_implementation_level_include, gProductionNames_goil_implementation_level_include, gProductionIndexes_goil_implementation_level_include,
                                                    gFirstProductionIndexes_goil_implementation_level_include, gDecision_goil_implementation_level_include, gDecisionIndexes_goil_implementation_level_include, 448) ;
    if (ok && ! executionModeIsSyntaxAnalysisOnly ()) {
      cGrammar_goil_5F_implementation_5F_level_5F_include grammar ;
      grammar.nt_implementation_5F_object_5F_list_ (parameter_1, scanner) ;
    }
    macroDetachSharedObject (scanner) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                             'include_implementation_level' non terminal implementation                               
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_include_5F_implementation_5F_level_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_include_5F_implementation_5F_level_i2_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_include_5F_implementation_5F_level_ (GALGAS_implementation & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_include_5F_implementation_5F_level_i2_(parameter_1, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                  'include_type_level' non terminal implementation                                    
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_include_5F_type_5F_level_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_include_5F_type_5F_level_i3_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_include_5F_type_5F_level_ (GALGAS_implementationObjectMap & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_include_5F_type_5F_level_i3_(parameter_1, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                'implementation_objects' non terminal implementation                                  
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_implementation_5F_objects_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_objects_i4_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_implementation_5F_objects_ (GALGAS_implementation & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_objects_i4_(parameter_1, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                 'implementation_list' non terminal implementation                                    
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_implementation_5F_list_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_list_i5_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_implementation_5F_list_ (GALGAS_implementationObjectMap & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_list_i5_(parameter_1, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                 'implementation_type' non terminal implementation                                    
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_implementation_5F_type_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_type_i6_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_implementation_5F_type_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_type_i6_(parameter_1, parameter_2, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                    'struct_options' non terminal implementation                                      
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_struct_5F_options_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_struct_5F_options_i7_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_struct_5F_options_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_struct_5F_options_i7_(parameter_1, parameter_2, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                    'objref_option' non terminal implementation                                       
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_objref_5F_option_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_objref_5F_option_i8_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_objref_5F_option_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                GALGAS_lstring parameter_3,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_objref_5F_option_i8_(parameter_1, parameter_2, parameter_3, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                    'string_options' non terminal implementation                                      
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_string_5F_options_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_string_5F_options_i9_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_string_5F_options_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_string_5F_options_i9_(parameter_1, parameter_2, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                   'boolean_options' non terminal implementation                                      
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_boolean_5F_options_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_boolean_5F_options_i10_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_boolean_5F_options_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_boolean_5F_options_i10_(parameter_1, parameter_2, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                      'enum_item' non terminal implementation                                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_enum_5F_item_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_enum_5F_item_i11_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_enum_5F_item_ (GALGAS_enumValues & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_enum_5F_item_i11_(parameter_1, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                     'enum_options' non terminal implementation                                       
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_enum_5F_options_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_enum_5F_options_i12_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_enum_5F_options_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_enum_5F_options_i12_(parameter_1, parameter_2, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                    'number_options' non terminal implementation                                      
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_number_5F_options_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_number_5F_options_i13_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_number_5F_options_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                const GALGAS_dataType parameter_3,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_number_5F_options_i13_(parameter_1, parameter_2, parameter_3, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                     'type_options' non terminal implementation                                       
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_type_5F_options_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_type_5F_options_i14_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_type_5F_options_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                const GALGAS_dataType parameter_3,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_type_5F_options_i14_(parameter_1, parameter_2, parameter_3, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                      'with_auto' non terminal implementation                                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_with_5F_auto_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_with_5F_auto_i15_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_with_5F_auto_ (GALGAS_bool & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_with_5F_auto_i15_(parameter_1, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                     'int_or_float' non terminal implementation                                       
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_int_5F_or_5F_float_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_int_5F_or_5F_float_i16_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_int_5F_or_5F_float_ (GALGAS_object_5F_t & parameter_1,
                                const GALGAS_dataType parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_int_5F_or_5F_float_i16_(parameter_1, parameter_2, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                     'set_followup' non terminal implementation                                       
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_set_5F_followup_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_set_5F_followup_i17_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_set_5F_followup_ (GALGAS_numberList & parameter_1,
                                const GALGAS_dataType parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_set_5F_followup_i17_(parameter_1, parameter_2, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                    'range_content' non terminal implementation                                       
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_range_5F_content_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_range_5F_content_i18_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_range_5F_content_ (GALGAS_attributeRange & parameter_1,
                                const GALGAS_dataType parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_range_5F_content_i18_(parameter_1, parameter_2, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                        'range' non terminal implementation                                           
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_range_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_range_i19_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_range_ (GALGAS_attributeRange & parameter_1,
                                const GALGAS_dataType parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_range_i19_(parameter_1, parameter_2, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                       'multiple' non terminal implementation                                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_multiple_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_multiple_i20_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_multiple_ (GALGAS_bool & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_multiple_i20_(parameter_1, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                               'identifier_or_attribute' non terminal implementation                                  
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_identifier_5F_or_5F_attribute_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_identifier_5F_or_5F_attribute_i21_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_identifier_5F_or_5F_attribute_ (GALGAS_lstring & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_identifier_5F_or_5F_attribute_i21_(parameter_1, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                               'identifier_or_enum_value' non terminal implementation                                 
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_identifier_5F_or_5F_enum_5F_value_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_identifier_5F_or_5F_enum_5F_value_i22_parse(inLexique) ;
}

void cGrammar_goil_5F_implementation_5F_level_5F_include::nt_identifier_5F_or_5F_enum_5F_value_ (GALGAS_lstring & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_identifier_5F_or_5F_enum_5F_value_i22_(parameter_1, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                            'select_goil_5F_syntax_0' added non terminal implementation                               
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_goil_5F_syntax_0 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                            'select_goil_5F_syntax_1' added non terminal implementation                               
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_goil_5F_syntax_1 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                            'select_goil_5F_syntax_2' added non terminal implementation                               
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_goil_5F_syntax_2 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                            'select_goil_5F_syntax_3' added non terminal implementation                               
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_goil_5F_syntax_3 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                            'select_goil_5F_syntax_4' added non terminal implementation                               
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_goil_5F_syntax_4 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                            'select_goil_5F_syntax_5' added non terminal implementation                               
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_goil_5F_syntax_5 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                            'select_goil_5F_syntax_6' added non terminal implementation                               
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_goil_5F_syntax_6 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                            'select_goil_5F_syntax_7' added non terminal implementation                               
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_goil_5F_syntax_7 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                            'select_goil_5F_syntax_8' added non terminal implementation                               
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_goil_5F_syntax_8 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                            'select_goil_5F_syntax_9' added non terminal implementation                               
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_goil_5F_syntax_9 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                            'select_goil_5F_syntax_10' added non terminal implementation                              
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_goil_5F_syntax_10 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                            'select_goil_5F_syntax_11' added non terminal implementation                              
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_goil_5F_syntax_11 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                            'select_goil_5F_syntax_12' added non terminal implementation                              
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_goil_5F_syntax_12 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                            'select_goil_5F_syntax_13' added non terminal implementation                              
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_goil_5F_syntax_13 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                            'select_goil_5F_syntax_14' added non terminal implementation                              
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_goil_5F_syntax_14 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                            'select_goil_5F_syntax_15' added non terminal implementation                              
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_goil_5F_syntax_15 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                            'select_goil_5F_syntax_16' added non terminal implementation                              
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_goil_5F_syntax_16 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                            'select_goil_5F_syntax_17' added non terminal implementation                              
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_goil_5F_syntax_17 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_0' added non terminal implementation                          
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_implementation_5F_parser_0 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_1' added non terminal implementation                          
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_implementation_5F_parser_1 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_2' added non terminal implementation                          
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_implementation_5F_parser_2 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_3' added non terminal implementation                          
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_implementation_5F_parser_3 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_4' added non terminal implementation                          
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_implementation_5F_parser_4 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_5' added non terminal implementation                          
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_implementation_5F_parser_5 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_6' added non terminal implementation                          
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_implementation_5F_parser_6 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_7' added non terminal implementation                          
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_implementation_5F_parser_7 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_8' added non terminal implementation                          
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_implementation_5F_parser_8 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_9' added non terminal implementation                          
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_implementation_5F_parser_9 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_10' added non terminal implementation                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_implementation_5F_parser_10 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_11' added non terminal implementation                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_implementation_5F_parser_11 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_12' added non terminal implementation                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_implementation_5F_parser_12 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_13' added non terminal implementation                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_implementation_5F_parser_13 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_14' added non terminal implementation                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_implementation_5F_parser_14 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_15' added non terminal implementation                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_implementation_5F_parser_15 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_16' added non terminal implementation                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_implementation_5F_parser_16 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_17' added non terminal implementation                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_implementation_5F_parser_17 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_18' added non terminal implementation                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_implementation_5F_parser_18 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_19' added non terminal implementation                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_implementation_5F_parser_19 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_20' added non terminal implementation                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_implementation_5F_parser_20 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_21' added non terminal implementation                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_implementation_5F_parser_21 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_22' added non terminal implementation                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_implementation_5F_parser_22 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_23' added non terminal implementation                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_implementation_5F_parser_23 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_24' added non terminal implementation                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_implementation_5F_parser_24 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_25' added non terminal implementation                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_implementation_5F_parser_25 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_26' added non terminal implementation                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_implementation_5F_parser_26 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_27' added non terminal implementation                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_implementation_5F_parser_27 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_28' added non terminal implementation                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_implementation_5F_parser_28 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_29' added non terminal implementation                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_implementation_5F_parser_29 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_30' added non terminal implementation                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_implementation_5F_level_5F_include::select_implementation_5F_parser_30 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------

#include "utilities/MF_MemoryControl.h"
#include "galgas2/C_galgas_CLI_Options.h"

#include "files/C_FileManager.h"

//----------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                   L L ( 1 )    P R O D U C T I O N    R U L E S                                      
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

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
// At index 32 : <boolean>, in file 'goil_syntax.ggs', line 230
, NONTERMINAL (41) // <select_goil_5F_syntax_5>
, END_PRODUCTION
// At index 34 : <oil_declaration_list>, in file 'goil_syntax.ggs', line 240
, NONTERMINAL (42) // <select_goil_5F_syntax_6>
, END_PRODUCTION
// At index 36 : <oil_declaration>, in file 'goil_syntax.ggs', line 252
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (43) // <select_goil_5F_syntax_7>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, END_PRODUCTION
// At index 40 : <include_file_level>, in file 'goil_syntax.ggs', line 425
, NONTERMINAL (48) // <select_goil_5F_syntax_12>
, NONTERMINAL (49) // <select_goil_5F_syntax_13>
, END_PRODUCTION
// At index 43 : <include_cpu_level>, in file 'goil_syntax.ggs', line 449
, NONTERMINAL (50) // <select_goil_5F_syntax_14>
, NONTERMINAL (51) // <select_goil_5F_syntax_15>
, END_PRODUCTION
// At index 46 : <include_object_level>, in file 'goil_syntax.ggs', line 473
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
// At index 65 : <implementation_type>, in file 'implementation_parser.ggs', line 212
, NONTERMINAL (61) // <select_implementation_5F_parser_7>
, END_PRODUCTION
// At index 67 : <struct_options>, in file 'implementation_parser.ggs', line 240
, NONTERMINAL (62) // <select_implementation_5F_parser_8>
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (33) // <multiple>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 72 : <objref_option>, in file 'implementation_parser.ggs', line 257
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (33) // <multiple>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 76 : <string_options>, in file 'implementation_parser.ggs', line 275
, NONTERMINAL (28) // <with_auto>
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (33) // <multiple>
, NONTERMINAL (63) // <select_implementation_5F_parser_9>
, END_PRODUCTION
// At index 81 : <boolean_options>, in file 'implementation_parser.ggs', line 307
, NONTERMINAL (28) // <with_auto>
, NONTERMINAL (65) // <select_implementation_5F_parser_11>
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (33) // <multiple>
, NONTERMINAL (68) // <select_implementation_5F_parser_14>
, END_PRODUCTION
// At index 87 : <enum_item>, in file 'implementation_parser.ggs', line 352
, NONTERMINAL (35) // <identifier_or_enum_value>
, NONTERMINAL (69) // <select_implementation_5F_parser_15>
, END_PRODUCTION
// At index 90 : <enum_options>, in file 'implementation_parser.ggs', line 365
, NONTERMINAL (28) // <with_auto>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) // $[$
, NONTERMINAL (24) // <enum_item>
, NONTERMINAL (70) // <select_implementation_5F_parser_16>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) // $]$
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (33) // <multiple>
, NONTERMINAL (71) // <select_implementation_5F_parser_17>
, END_PRODUCTION
// At index 99 : <number_options>, in file 'implementation_parser.ggs', line 407
, NONTERMINAL (28) // <with_auto>
, NONTERMINAL (32) // <range>
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (33) // <multiple>
, NONTERMINAL (73) // <select_implementation_5F_parser_19>
, END_PRODUCTION
// At index 105 : <type_options>, in file 'implementation_parser.ggs', line 441
, NONTERMINAL (28) // <with_auto>
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (33) // <multiple>
, NONTERMINAL (75) // <select_implementation_5F_parser_21>
, END_PRODUCTION
// At index 110 : <with_auto>, in file 'implementation_parser.ggs', line 475
, NONTERMINAL (77) // <select_implementation_5F_parser_23>
, END_PRODUCTION
// At index 112 : <int_or_float>, in file 'implementation_parser.ggs', line 484
, NONTERMINAL (3) // <sign>
, NONTERMINAL (78) // <select_implementation_5F_parser_24>
, END_PRODUCTION
// At index 115 : <set_followup>, in file 'implementation_parser.ggs', line 502
, NONTERMINAL (79) // <select_implementation_5F_parser_25>
, END_PRODUCTION
// At index 117 : <range_content>, in file 'implementation_parser.ggs', line 514
, NONTERMINAL (3) // <sign>
, NONTERMINAL (80) // <select_implementation_5F_parser_26>
, END_PRODUCTION
// At index 120 : <range>, in file 'implementation_parser.ggs', line 554
, NONTERMINAL (83) // <select_implementation_5F_parser_29>
, END_PRODUCTION
// At index 122 : <multiple>, in file 'implementation_parser.ggs', line 564
, NONTERMINAL (84) // <select_implementation_5F_parser_30>
, END_PRODUCTION
// At index 124 : <identifier_or_attribute>, in file 'implementation_parser.ggs', line 574
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, END_PRODUCTION
// At index 126 : <identifier_or_enum_value>, in file 'implementation_parser.ggs', line 579
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
// At index 165 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 231
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_TRUE) // $TRUE$
, END_PRODUCTION
// At index 167 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 231
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_FALSE) // $FALSE$
, END_PRODUCTION
// At index 169 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 244
, END_PRODUCTION
// At index 170 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 244
, NONTERMINAL (10) // <oil_declaration>
, NONTERMINAL (42) // <select_goil_5F_syntax_6>
, END_PRODUCTION
// At index 173 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 244
, NONTERMINAL (13) // <include_object_level>
, NONTERMINAL (42) // <select_goil_5F_syntax_6>
, END_PRODUCTION
// At index 176 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 269
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (44) // <select_goil_5F_syntax_8>
, END_PRODUCTION
// At index 179 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 269
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (9) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 185 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (45) // <select_goil_5F_syntax_9>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 189 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
, NONTERMINAL (3) // <sign>
, NONTERMINAL (46) // <select_goil_5F_syntax_10>
, END_PRODUCTION
// At index 192 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
, NONTERMINAL (8) // <boolean>
, NONTERMINAL (47) // <select_goil_5F_syntax_11>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 196 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 199 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) // $AUTO$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 202 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 292
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (9) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 206 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 292
, END_PRODUCTION
// At index 207 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 309
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) // $uint_number$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 210 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 309
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_float_5F_number) // $float_number$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 213 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 340
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (9) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 217 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 340
, END_PRODUCTION
// At index 218 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 432
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) // $include$
, END_PRODUCTION
// At index 220 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 432
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) // $includeifexists$
, END_PRODUCTION
// At index 222 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 438
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) // $g_string$
, END_PRODUCTION
// At index 224 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 438
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, END_PRODUCTION
// At index 226 : <select_goil_5F_syntax_14>, in file 'goil_syntax.ggs', line 456
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) // $include$
, END_PRODUCTION
// At index 228 : <select_goil_5F_syntax_14>, in file 'goil_syntax.ggs', line 456
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) // $includeifexists$
, END_PRODUCTION
// At index 230 : <select_goil_5F_syntax_15>, in file 'goil_syntax.ggs', line 462
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) // $g_string$
, END_PRODUCTION
// At index 232 : <select_goil_5F_syntax_15>, in file 'goil_syntax.ggs', line 462
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, END_PRODUCTION
// At index 234 : <select_goil_5F_syntax_16>, in file 'goil_syntax.ggs', line 478
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) // $include$
, END_PRODUCTION
// At index 236 : <select_goil_5F_syntax_16>, in file 'goil_syntax.ggs', line 478
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) // $includeifexists$
, END_PRODUCTION
// At index 238 : <select_goil_5F_syntax_17>, in file 'goil_syntax.ggs', line 484
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) // $g_string$
, END_PRODUCTION
// At index 240 : <select_goil_5F_syntax_17>, in file 'goil_syntax.ggs', line 484
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
// At index 278 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_UINT_33__32_) // $UINT32$
, NONTERMINAL (26) // <number_options>
, END_PRODUCTION
// At index 281 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_INT_33__32_) // $INT32$
, NONTERMINAL (26) // <number_options>
, END_PRODUCTION
// At index 284 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_UINT_36__34_) // $UINT64$
, NONTERMINAL (26) // <number_options>
, END_PRODUCTION
// At index 287 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_INT_36__34_) // $INT64$
, NONTERMINAL (26) // <number_options>
, END_PRODUCTION
// At index 290 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_FLOAT) // $FLOAT$
, NONTERMINAL (26) // <number_options>
, END_PRODUCTION
// At index 293 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_ENUM) // $ENUM$
, NONTERMINAL (25) // <enum_options>
, END_PRODUCTION
// At index 296 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_BOOLEAN) // $BOOLEAN$
, NONTERMINAL (23) // <boolean_options>
, END_PRODUCTION
// At index 299 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_STRING) // $STRING$
, NONTERMINAL (22) // <string_options>
, END_PRODUCTION
// At index 302 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_IDENTIFIER) // $IDENTIFIER$
, NONTERMINAL (27) // <type_options>
, END_PRODUCTION
// At index 305 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_STRUCT) // $STRUCT$
, NONTERMINAL (20) // <struct_options>
, END_PRODUCTION
// At index 308 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (21) // <objref_option>
, END_PRODUCTION
// At index 311 : <select_implementation_5F_parser_8>, in file 'implementation_parser.ggs', line 244
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (18) // <implementation_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 315 : <select_implementation_5F_parser_8>, in file 'implementation_parser.ggs', line 244
, END_PRODUCTION
// At index 316 : <select_implementation_5F_parser_9>, in file 'implementation_parser.ggs', line 285
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (64) // <select_implementation_5F_parser_10>
, END_PRODUCTION
// At index 319 : <select_implementation_5F_parser_9>, in file 'implementation_parser.ggs', line 285
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 321 : <select_implementation_5F_parser_10>, in file 'implementation_parser.ggs', line 287
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 324 : <select_implementation_5F_parser_10>, in file 'implementation_parser.ggs', line 287
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) // $AUTO$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 327 : <select_implementation_5F_parser_10>, in file 'implementation_parser.ggs', line 287
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT) // $NO_DEFAULT$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 330 : <select_implementation_5F_parser_11>, in file 'implementation_parser.ggs', line 314
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) // $[$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_TRUE) // $TRUE$
, NONTERMINAL (66) // <select_implementation_5F_parser_12>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2C_) // $,$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_FALSE) // $FALSE$
, NONTERMINAL (67) // <select_implementation_5F_parser_13>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) // $]$
, END_PRODUCTION
// At index 338 : <select_implementation_5F_parser_11>, in file 'implementation_parser.ggs', line 314
, END_PRODUCTION
// At index 339 : <select_implementation_5F_parser_12>, in file 'implementation_parser.ggs', line 317
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (18) // <implementation_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 343 : <select_implementation_5F_parser_12>, in file 'implementation_parser.ggs', line 317
, END_PRODUCTION
// At index 344 : <select_implementation_5F_parser_13>, in file 'implementation_parser.ggs', line 326
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (18) // <implementation_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 348 : <select_implementation_5F_parser_13>, in file 'implementation_parser.ggs', line 326
, END_PRODUCTION
// At index 349 : <select_implementation_5F_parser_14>, in file 'implementation_parser.ggs', line 340
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (8) // <boolean>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 353 : <select_implementation_5F_parser_14>, in file 'implementation_parser.ggs', line 340
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 355 : <select_implementation_5F_parser_15>, in file 'implementation_parser.ggs', line 357
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (18) // <implementation_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 359 : <select_implementation_5F_parser_15>, in file 'implementation_parser.ggs', line 357
, END_PRODUCTION
// At index 360 : <select_implementation_5F_parser_16>, in file 'implementation_parser.ggs', line 373
, END_PRODUCTION
// At index 361 : <select_implementation_5F_parser_16>, in file 'implementation_parser.ggs', line 373
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2C_) // $,$
, NONTERMINAL (24) // <enum_item>
, NONTERMINAL (70) // <select_implementation_5F_parser_16>
, END_PRODUCTION
// At index 365 : <select_implementation_5F_parser_17>, in file 'implementation_parser.ggs', line 383
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (72) // <select_implementation_5F_parser_18>
, END_PRODUCTION
// At index 368 : <select_implementation_5F_parser_17>, in file 'implementation_parser.ggs', line 383
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 370 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 385
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 373 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 385
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) // $AUTO$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 376 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 385
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT) // $NO_DEFAULT$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 379 : <select_implementation_5F_parser_19>, in file 'implementation_parser.ggs', line 420
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (74) // <select_implementation_5F_parser_20>
, END_PRODUCTION
// At index 382 : <select_implementation_5F_parser_19>, in file 'implementation_parser.ggs', line 420
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 384 : <select_implementation_5F_parser_20>, in file 'implementation_parser.ggs', line 422
, NONTERMINAL (29) // <int_or_float>
, END_PRODUCTION
// At index 386 : <select_implementation_5F_parser_20>, in file 'implementation_parser.ggs', line 422
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT) // $NO_DEFAULT$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 389 : <select_implementation_5F_parser_20>, in file 'implementation_parser.ggs', line 422
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) // $AUTO$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 392 : <select_implementation_5F_parser_21>, in file 'implementation_parser.ggs', line 452
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (76) // <select_implementation_5F_parser_22>
, END_PRODUCTION
// At index 395 : <select_implementation_5F_parser_21>, in file 'implementation_parser.ggs', line 452
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 397 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 454
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 400 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 454
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT) // $NO_DEFAULT$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 403 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 454
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) // $AUTO$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 406 : <select_implementation_5F_parser_23>, in file 'implementation_parser.ggs', line 477
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_WITH_5F_AUTO) // $WITH_AUTO$
, END_PRODUCTION
// At index 408 : <select_implementation_5F_parser_23>, in file 'implementation_parser.ggs', line 477
, END_PRODUCTION
// At index 409 : <select_implementation_5F_parser_24>, in file 'implementation_parser.ggs', line 489
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) // $uint_number$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 412 : <select_implementation_5F_parser_24>, in file 'implementation_parser.ggs', line 489
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_float_5F_number) // $float_number$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 415 : <select_implementation_5F_parser_25>, in file 'implementation_parser.ggs', line 505
, END_PRODUCTION
// At index 416 : <select_implementation_5F_parser_25>, in file 'implementation_parser.ggs', line 505
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2C_) // $,$
, NONTERMINAL (29) // <int_or_float>
, NONTERMINAL (79) // <select_implementation_5F_parser_25>
, END_PRODUCTION
// At index 420 : <select_implementation_5F_parser_26>, in file 'implementation_parser.ggs', line 521
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_set_5F_start_5F_uint_5F_number) // $set_start_uint_number$
, NONTERMINAL (29) // <int_or_float>
, END_PRODUCTION
// At index 423 : <select_implementation_5F_parser_26>, in file 'implementation_parser.ggs', line 521
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) // $uint_number$
, NONTERMINAL (81) // <select_implementation_5F_parser_27>
, END_PRODUCTION
// At index 426 : <select_implementation_5F_parser_26>, in file 'implementation_parser.ggs', line 521
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_float_5F_number) // $float_number$
, NONTERMINAL (82) // <select_implementation_5F_parser_28>
, END_PRODUCTION
// At index 429 : <select_implementation_5F_parser_27>, in file 'implementation_parser.ggs', line 531
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2E__2E_) // $..$
, NONTERMINAL (29) // <int_or_float>
, END_PRODUCTION
// At index 432 : <select_implementation_5F_parser_27>, in file 'implementation_parser.ggs', line 531
, NONTERMINAL (30) // <set_followup>
, END_PRODUCTION
// At index 434 : <select_implementation_5F_parser_28>, in file 'implementation_parser.ggs', line 543
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2E__2E_) // $..$
, NONTERMINAL (29) // <int_or_float>
, END_PRODUCTION
// At index 437 : <select_implementation_5F_parser_28>, in file 'implementation_parser.ggs', line 543
, NONTERMINAL (30) // <set_followup>
, END_PRODUCTION
// At index 439 : <select_implementation_5F_parser_29>, in file 'implementation_parser.ggs', line 557
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) // $[$
, NONTERMINAL (31) // <range_content>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) // $]$
, END_PRODUCTION
// At index 443 : <select_implementation_5F_parser_29>, in file 'implementation_parser.ggs', line 557
, END_PRODUCTION
// At index 444 : <select_implementation_5F_parser_30>, in file 'implementation_parser.ggs', line 566
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) // $[$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) // $]$
, END_PRODUCTION
// At index 447 : <select_implementation_5F_parser_30>, in file 'implementation_parser.ggs', line 566
, END_PRODUCTION
// At index 448 : <>, in file '.ggs', line 0
, NONTERMINAL (18) // <implementation_list>
, END_PRODUCTION
} ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                          P R O D U C T I O N    N A M E S                                            
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                 L L ( 1 )    P R O D U C T I O N    I N D E X E S                                    
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

static const int16_t gProductionIndexes_goil_type_level_include [159] = {
0, // index 0 : <implementation_definition>, in file 'implementation_parser.ggs', line 55
7, // index 1 : <start>, in file 'goil_syntax.ggs', line 38
10, // index 2 : <file>, in file 'goil_syntax.ggs', line 110
12, // index 3 : <sign>, in file 'goil_syntax.ggs', line 126
14, // index 4 : <description>, in file 'goil_syntax.ggs', line 139
16, // index 5 : <OIL_version>, in file 'goil_syntax.ggs', line 163
22, // index 6 : <application_definition>, in file 'goil_syntax.ggs', line 170
30, // index 7 : <object_definition_list>, in file 'goil_syntax.ggs', line 184
32, // index 8 : <boolean>, in file 'goil_syntax.ggs', line 230
34, // index 9 : <oil_declaration_list>, in file 'goil_syntax.ggs', line 240
36, // index 10 : <oil_declaration>, in file 'goil_syntax.ggs', line 252
40, // index 11 : <include_file_level>, in file 'goil_syntax.ggs', line 425
43, // index 12 : <include_cpu_level>, in file 'goil_syntax.ggs', line 449
46, // index 13 : <include_object_level>, in file 'goil_syntax.ggs', line 473
49, // index 14 : <implementation_object_list>, in file 'implementation_parser.ggs', line 62
51, // index 15 : <include_implementation_level>, in file 'implementation_parser.ggs', line 71
54, // index 16 : <include_type_level>, in file 'implementation_parser.ggs', line 92
57, // index 17 : <implementation_objects>, in file 'implementation_parser.ggs', line 135
63, // index 18 : <implementation_list>, in file 'implementation_parser.ggs', line 183
65, // index 19 : <implementation_type>, in file 'implementation_parser.ggs', line 212
67, // index 20 : <struct_options>, in file 'implementation_parser.ggs', line 240
72, // index 21 : <objref_option>, in file 'implementation_parser.ggs', line 257
76, // index 22 : <string_options>, in file 'implementation_parser.ggs', line 275
81, // index 23 : <boolean_options>, in file 'implementation_parser.ggs', line 307
87, // index 24 : <enum_item>, in file 'implementation_parser.ggs', line 352
90, // index 25 : <enum_options>, in file 'implementation_parser.ggs', line 365
99, // index 26 : <number_options>, in file 'implementation_parser.ggs', line 407
105, // index 27 : <type_options>, in file 'implementation_parser.ggs', line 441
110, // index 28 : <with_auto>, in file 'implementation_parser.ggs', line 475
112, // index 29 : <int_or_float>, in file 'implementation_parser.ggs', line 484
115, // index 30 : <set_followup>, in file 'implementation_parser.ggs', line 502
117, // index 31 : <range_content>, in file 'implementation_parser.ggs', line 514
120, // index 32 : <range>, in file 'implementation_parser.ggs', line 554
122, // index 33 : <multiple>, in file 'implementation_parser.ggs', line 564
124, // index 34 : <identifier_or_attribute>, in file 'implementation_parser.ggs', line 574
126, // index 35 : <identifier_or_enum_value>, in file 'implementation_parser.ggs', line 579
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
165, // index 50 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 231
167, // index 51 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 231
169, // index 52 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 244
170, // index 53 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 244
173, // index 54 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 244
176, // index 55 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 269
179, // index 56 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 269
185, // index 57 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
189, // index 58 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
192, // index 59 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
196, // index 60 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
199, // index 61 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
202, // index 62 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 292
206, // index 63 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 292
207, // index 64 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 309
210, // index 65 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 309
213, // index 66 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 340
217, // index 67 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 340
218, // index 68 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 432
220, // index 69 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 432
222, // index 70 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 438
224, // index 71 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 438
226, // index 72 : <select_goil_5F_syntax_14>, in file 'goil_syntax.ggs', line 456
228, // index 73 : <select_goil_5F_syntax_14>, in file 'goil_syntax.ggs', line 456
230, // index 74 : <select_goil_5F_syntax_15>, in file 'goil_syntax.ggs', line 462
232, // index 75 : <select_goil_5F_syntax_15>, in file 'goil_syntax.ggs', line 462
234, // index 76 : <select_goil_5F_syntax_16>, in file 'goil_syntax.ggs', line 478
236, // index 77 : <select_goil_5F_syntax_16>, in file 'goil_syntax.ggs', line 478
238, // index 78 : <select_goil_5F_syntax_17>, in file 'goil_syntax.ggs', line 484
240, // index 79 : <select_goil_5F_syntax_17>, in file 'goil_syntax.ggs', line 484
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
278, // index 96 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
281, // index 97 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
284, // index 98 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
287, // index 99 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
290, // index 100 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
293, // index 101 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
296, // index 102 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
299, // index 103 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
302, // index 104 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
305, // index 105 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
308, // index 106 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
311, // index 107 : <select_implementation_5F_parser_8>, in file 'implementation_parser.ggs', line 244
315, // index 108 : <select_implementation_5F_parser_8>, in file 'implementation_parser.ggs', line 244
316, // index 109 : <select_implementation_5F_parser_9>, in file 'implementation_parser.ggs', line 285
319, // index 110 : <select_implementation_5F_parser_9>, in file 'implementation_parser.ggs', line 285
321, // index 111 : <select_implementation_5F_parser_10>, in file 'implementation_parser.ggs', line 287
324, // index 112 : <select_implementation_5F_parser_10>, in file 'implementation_parser.ggs', line 287
327, // index 113 : <select_implementation_5F_parser_10>, in file 'implementation_parser.ggs', line 287
330, // index 114 : <select_implementation_5F_parser_11>, in file 'implementation_parser.ggs', line 314
338, // index 115 : <select_implementation_5F_parser_11>, in file 'implementation_parser.ggs', line 314
339, // index 116 : <select_implementation_5F_parser_12>, in file 'implementation_parser.ggs', line 317
343, // index 117 : <select_implementation_5F_parser_12>, in file 'implementation_parser.ggs', line 317
344, // index 118 : <select_implementation_5F_parser_13>, in file 'implementation_parser.ggs', line 326
348, // index 119 : <select_implementation_5F_parser_13>, in file 'implementation_parser.ggs', line 326
349, // index 120 : <select_implementation_5F_parser_14>, in file 'implementation_parser.ggs', line 340
353, // index 121 : <select_implementation_5F_parser_14>, in file 'implementation_parser.ggs', line 340
355, // index 122 : <select_implementation_5F_parser_15>, in file 'implementation_parser.ggs', line 357
359, // index 123 : <select_implementation_5F_parser_15>, in file 'implementation_parser.ggs', line 357
360, // index 124 : <select_implementation_5F_parser_16>, in file 'implementation_parser.ggs', line 373
361, // index 125 : <select_implementation_5F_parser_16>, in file 'implementation_parser.ggs', line 373
365, // index 126 : <select_implementation_5F_parser_17>, in file 'implementation_parser.ggs', line 383
368, // index 127 : <select_implementation_5F_parser_17>, in file 'implementation_parser.ggs', line 383
370, // index 128 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 385
373, // index 129 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 385
376, // index 130 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 385
379, // index 131 : <select_implementation_5F_parser_19>, in file 'implementation_parser.ggs', line 420
382, // index 132 : <select_implementation_5F_parser_19>, in file 'implementation_parser.ggs', line 420
384, // index 133 : <select_implementation_5F_parser_20>, in file 'implementation_parser.ggs', line 422
386, // index 134 : <select_implementation_5F_parser_20>, in file 'implementation_parser.ggs', line 422
389, // index 135 : <select_implementation_5F_parser_20>, in file 'implementation_parser.ggs', line 422
392, // index 136 : <select_implementation_5F_parser_21>, in file 'implementation_parser.ggs', line 452
395, // index 137 : <select_implementation_5F_parser_21>, in file 'implementation_parser.ggs', line 452
397, // index 138 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 454
400, // index 139 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 454
403, // index 140 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 454
406, // index 141 : <select_implementation_5F_parser_23>, in file 'implementation_parser.ggs', line 477
408, // index 142 : <select_implementation_5F_parser_23>, in file 'implementation_parser.ggs', line 477
409, // index 143 : <select_implementation_5F_parser_24>, in file 'implementation_parser.ggs', line 489
412, // index 144 : <select_implementation_5F_parser_24>, in file 'implementation_parser.ggs', line 489
415, // index 145 : <select_implementation_5F_parser_25>, in file 'implementation_parser.ggs', line 505
416, // index 146 : <select_implementation_5F_parser_25>, in file 'implementation_parser.ggs', line 505
420, // index 147 : <select_implementation_5F_parser_26>, in file 'implementation_parser.ggs', line 521
423, // index 148 : <select_implementation_5F_parser_26>, in file 'implementation_parser.ggs', line 521
426, // index 149 : <select_implementation_5F_parser_26>, in file 'implementation_parser.ggs', line 521
429, // index 150 : <select_implementation_5F_parser_27>, in file 'implementation_parser.ggs', line 531
432, // index 151 : <select_implementation_5F_parser_27>, in file 'implementation_parser.ggs', line 531
434, // index 152 : <select_implementation_5F_parser_28>, in file 'implementation_parser.ggs', line 543
437, // index 153 : <select_implementation_5F_parser_28>, in file 'implementation_parser.ggs', line 543
439, // index 154 : <select_implementation_5F_parser_29>, in file 'implementation_parser.ggs', line 557
443, // index 155 : <select_implementation_5F_parser_29>, in file 'implementation_parser.ggs', line 557
444, // index 156 : <select_implementation_5F_parser_30>, in file 'implementation_parser.ggs', line 566
447, // index 157 : <select_implementation_5F_parser_30>, in file 'implementation_parser.ggs', line 566
448 // index 158 : <>, in file '.ggs', line 0
} ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                           L L ( 1 )    F I R S T    P R O D U C T I O N    I N D E X E S                             
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                    L L ( 1 )    D E C I S I O N    T A B L E S                                       
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                            L L ( 1 )    D E C I S I O N    T A B L E S    I N D E X E S                              
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                              'implementation_definition' non terminal implementation                                 
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_type_5F_level_5F_include::nt_implementation_5F_definition_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_definition_i0_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_implementation_5F_definition_ (GALGAS_implementation & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_definition_i0_(parameter_1, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                        'start' non terminal implementation                                           
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_type_5F_level_5F_include::nt_start_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_start_i0_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_start_ (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_start_i0_(inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                         'file' non terminal implementation                                           
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                         'sign' non terminal implementation                                           
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_type_5F_level_5F_include::nt_sign_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_sign_i2_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_sign_ (GALGAS_bool & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_sign_i2_(parameter_1, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                     'description' non terminal implementation                                        
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_type_5F_level_5F_include::nt_description_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_description_i3_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_description_ (GALGAS_lstring & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_description_i3_(parameter_1, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                     'OIL_version' non terminal implementation                                        
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_type_5F_level_5F_include::nt_OIL_5F_version_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_OIL_5F_version_i4_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_OIL_5F_version_ (GALGAS_lstring & parameter_1,
                                GALGAS_lstring & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_OIL_5F_version_i4_(parameter_1, parameter_2, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                'application_definition' non terminal implementation                                  
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                'object_definition_list' non terminal implementation                                  
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                       'boolean' non terminal implementation                                          
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_type_5F_level_5F_include::nt_boolean_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_boolean_i7_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_boolean_ (GALGAS_lbool & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_boolean_i7_(parameter_1, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                 'oil_declaration_list' non terminal implementation                                   
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_type_5F_level_5F_include::nt_oil_5F_declaration_5F_list_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_5F_list_i8_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_oil_5F_declaration_5F_list_ (const GALGAS_implementationObjectMap parameter_1,
                                GALGAS_objectAttributes & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_5F_list_i8_(parameter_1, parameter_2, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                   'oil_declaration' non terminal implementation                                      
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_type_5F_level_5F_include::nt_oil_5F_declaration_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_i9_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_oil_5F_declaration_ (const GALGAS_implementationObjectMap parameter_1,
                                GALGAS_objectAttributes & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_i9_(parameter_1, parameter_2, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                  'include_file_level' non terminal implementation                                    
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                  'include_cpu_level' non terminal implementation                                     
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                 'include_object_level' non terminal implementation                                   
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_type_5F_level_5F_include::nt_include_5F_object_5F_level_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_object_5F_level_i12_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_include_5F_object_5F_level_ (const GALGAS_implementationObjectMap parameter_1,
                                GALGAS_objectAttributes & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_object_5F_level_i12_(parameter_1, parameter_2, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                              'implementation_object_list' non terminal implementation                                
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_type_5F_level_5F_include::nt_implementation_5F_object_5F_list_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_object_5F_list_i1_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_implementation_5F_object_5F_list_ (GALGAS_implementation & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_object_5F_list_i1_(parameter_1, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                             'include_implementation_level' non terminal implementation                               
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_type_5F_level_5F_include::nt_include_5F_implementation_5F_level_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_include_5F_implementation_5F_level_i2_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_include_5F_implementation_5F_level_ (GALGAS_implementation & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_include_5F_implementation_5F_level_i2_(parameter_1, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                  'include_type_level' non terminal implementation                                    
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_type_5F_level_5F_include::nt_include_5F_type_5F_level_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_include_5F_type_5F_level_i3_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_include_5F_type_5F_level_ (GALGAS_implementationObjectMap & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_include_5F_type_5F_level_i3_(parameter_1, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                'implementation_objects' non terminal implementation                                  
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_type_5F_level_5F_include::nt_implementation_5F_objects_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_objects_i4_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_implementation_5F_objects_ (GALGAS_implementation & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_objects_i4_(parameter_1, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                 'implementation_list' non terminal implementation                                    
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

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
  macroMyNew (scanner, C_Lexique_goil_5F_lexique (inCompiler, "", "", inSourceFilePath COMMA_HERE)) ;
  if (scanner->sourceText () != NULL) {
    scanner->performLexicalAnalysis () ;
  }
  macroDetachSharedObject (scanner) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::performOnlySyntaxAnalysis (C_Compiler * inCompiler,
             const C_String & inSourceFilePath) {
  C_Lexique_goil_5F_lexique * scanner = NULL ;
  macroMyNew (scanner, C_Lexique_goil_5F_lexique (inCompiler, "", "", inSourceFilePath COMMA_HERE)) ;
  if (scanner->sourceText () != NULL) {
    scanner->performTopDownParsing (gProductions_goil_type_level_include, gProductionNames_goil_type_level_include, gProductionIndexes_goil_type_level_include,
                                    gFirstProductionIndexes_goil_type_level_include, gDecision_goil_type_level_include, gDecisionIndexes_goil_type_level_include, 448) ;
  }
  macroDetachSharedObject (scanner) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                        Grammar start symbol implementation                                           
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

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
    macroMyNew (scanner, C_Lexique_goil_5F_lexique (inCompiler, "", "", filePath COMMA_HERE)) ;
    if (scanner->sourceText () != NULL) {
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
        inCompiler->semanticErrorAtLocation (errorLocation, message COMMA_THERE) ;
      }
      macroDetachSharedObject (scanner) ;
    }else{
      C_String message ;
      message << "the '" << filePath << "' file does not exist" ;
      const GALGAS_location errorLocation (inFilePath.getter_location (THERE)) ;
      inCompiler->semanticErrorAtLocation (errorLocation, message COMMA_THERE) ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                 'implementation_type' non terminal implementation                                    
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_type_5F_level_5F_include::nt_implementation_5F_type_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_type_i6_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_implementation_5F_type_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_type_i6_(parameter_1, parameter_2, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                    'struct_options' non terminal implementation                                      
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_type_5F_level_5F_include::nt_struct_5F_options_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_struct_5F_options_i7_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_struct_5F_options_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_struct_5F_options_i7_(parameter_1, parameter_2, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                    'objref_option' non terminal implementation                                       
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_type_5F_level_5F_include::nt_objref_5F_option_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_objref_5F_option_i8_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_objref_5F_option_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                GALGAS_lstring parameter_3,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_objref_5F_option_i8_(parameter_1, parameter_2, parameter_3, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                    'string_options' non terminal implementation                                      
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_type_5F_level_5F_include::nt_string_5F_options_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_string_5F_options_i9_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_string_5F_options_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_string_5F_options_i9_(parameter_1, parameter_2, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                   'boolean_options' non terminal implementation                                      
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_type_5F_level_5F_include::nt_boolean_5F_options_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_boolean_5F_options_i10_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_boolean_5F_options_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_boolean_5F_options_i10_(parameter_1, parameter_2, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                      'enum_item' non terminal implementation                                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_type_5F_level_5F_include::nt_enum_5F_item_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_enum_5F_item_i11_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_enum_5F_item_ (GALGAS_enumValues & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_enum_5F_item_i11_(parameter_1, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                     'enum_options' non terminal implementation                                       
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_type_5F_level_5F_include::nt_enum_5F_options_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_enum_5F_options_i12_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_enum_5F_options_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_enum_5F_options_i12_(parameter_1, parameter_2, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                    'number_options' non terminal implementation                                      
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_type_5F_level_5F_include::nt_number_5F_options_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_number_5F_options_i13_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_number_5F_options_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                const GALGAS_dataType parameter_3,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_number_5F_options_i13_(parameter_1, parameter_2, parameter_3, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                     'type_options' non terminal implementation                                       
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_type_5F_level_5F_include::nt_type_5F_options_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_type_5F_options_i14_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_type_5F_options_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                const GALGAS_dataType parameter_3,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_type_5F_options_i14_(parameter_1, parameter_2, parameter_3, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                      'with_auto' non terminal implementation                                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_type_5F_level_5F_include::nt_with_5F_auto_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_with_5F_auto_i15_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_with_5F_auto_ (GALGAS_bool & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_with_5F_auto_i15_(parameter_1, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                     'int_or_float' non terminal implementation                                       
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_type_5F_level_5F_include::nt_int_5F_or_5F_float_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_int_5F_or_5F_float_i16_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_int_5F_or_5F_float_ (GALGAS_object_5F_t & parameter_1,
                                const GALGAS_dataType parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_int_5F_or_5F_float_i16_(parameter_1, parameter_2, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                     'set_followup' non terminal implementation                                       
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_type_5F_level_5F_include::nt_set_5F_followup_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_set_5F_followup_i17_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_set_5F_followup_ (GALGAS_numberList & parameter_1,
                                const GALGAS_dataType parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_set_5F_followup_i17_(parameter_1, parameter_2, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                    'range_content' non terminal implementation                                       
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_type_5F_level_5F_include::nt_range_5F_content_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_range_5F_content_i18_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_range_5F_content_ (GALGAS_attributeRange & parameter_1,
                                const GALGAS_dataType parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_range_5F_content_i18_(parameter_1, parameter_2, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                        'range' non terminal implementation                                           
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_type_5F_level_5F_include::nt_range_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_range_i19_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_range_ (GALGAS_attributeRange & parameter_1,
                                const GALGAS_dataType parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_range_i19_(parameter_1, parameter_2, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                       'multiple' non terminal implementation                                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_type_5F_level_5F_include::nt_multiple_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_multiple_i20_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_multiple_ (GALGAS_bool & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_multiple_i20_(parameter_1, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                               'identifier_or_attribute' non terminal implementation                                  
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_type_5F_level_5F_include::nt_identifier_5F_or_5F_attribute_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_identifier_5F_or_5F_attribute_i21_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_identifier_5F_or_5F_attribute_ (GALGAS_lstring & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_identifier_5F_or_5F_attribute_i21_(parameter_1, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                               'identifier_or_enum_value' non terminal implementation                                 
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_type_5F_level_5F_include::nt_identifier_5F_or_5F_enum_5F_value_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_identifier_5F_or_5F_enum_5F_value_i22_parse(inLexique) ;
}

void cGrammar_goil_5F_type_5F_level_5F_include::nt_identifier_5F_or_5F_enum_5F_value_ (GALGAS_lstring & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_identifier_5F_or_5F_enum_5F_value_i22_(parameter_1, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                            'select_goil_5F_syntax_0' added non terminal implementation                               
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_goil_5F_syntax_0 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                            'select_goil_5F_syntax_1' added non terminal implementation                               
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_goil_5F_syntax_1 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                            'select_goil_5F_syntax_2' added non terminal implementation                               
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_goil_5F_syntax_2 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                            'select_goil_5F_syntax_3' added non terminal implementation                               
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_goil_5F_syntax_3 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                            'select_goil_5F_syntax_4' added non terminal implementation                               
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_goil_5F_syntax_4 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                            'select_goil_5F_syntax_5' added non terminal implementation                               
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_goil_5F_syntax_5 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                            'select_goil_5F_syntax_6' added non terminal implementation                               
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_goil_5F_syntax_6 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                            'select_goil_5F_syntax_7' added non terminal implementation                               
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_goil_5F_syntax_7 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                            'select_goil_5F_syntax_8' added non terminal implementation                               
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_goil_5F_syntax_8 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                            'select_goil_5F_syntax_9' added non terminal implementation                               
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_goil_5F_syntax_9 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                            'select_goil_5F_syntax_10' added non terminal implementation                              
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_goil_5F_syntax_10 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                            'select_goil_5F_syntax_11' added non terminal implementation                              
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_goil_5F_syntax_11 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                            'select_goil_5F_syntax_12' added non terminal implementation                              
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_goil_5F_syntax_12 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                            'select_goil_5F_syntax_13' added non terminal implementation                              
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_goil_5F_syntax_13 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                            'select_goil_5F_syntax_14' added non terminal implementation                              
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_goil_5F_syntax_14 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                            'select_goil_5F_syntax_15' added non terminal implementation                              
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_goil_5F_syntax_15 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                            'select_goil_5F_syntax_16' added non terminal implementation                              
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_goil_5F_syntax_16 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                            'select_goil_5F_syntax_17' added non terminal implementation                              
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_goil_5F_syntax_17 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_0' added non terminal implementation                          
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_0 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_1' added non terminal implementation                          
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_1 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_2' added non terminal implementation                          
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_2 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_3' added non terminal implementation                          
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_3 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_4' added non terminal implementation                          
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_4 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_5' added non terminal implementation                          
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_5 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_6' added non terminal implementation                          
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_6 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_7' added non terminal implementation                          
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_7 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_8' added non terminal implementation                          
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_8 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_9' added non terminal implementation                          
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_9 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_10' added non terminal implementation                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_10 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_11' added non terminal implementation                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_11 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_12' added non terminal implementation                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_12 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_13' added non terminal implementation                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_13 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_14' added non terminal implementation                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_14 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_15' added non terminal implementation                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_15 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_16' added non terminal implementation                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_16 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_17' added non terminal implementation                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_17 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_18' added non terminal implementation                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_18 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_19' added non terminal implementation                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_19 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_20' added non terminal implementation                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_20 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_21' added non terminal implementation                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_21 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_22' added non terminal implementation                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_22 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_23' added non terminal implementation                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_23 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_24' added non terminal implementation                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_24 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_25' added non terminal implementation                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_25 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_26' added non terminal implementation                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_26 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_27' added non terminal implementation                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_27 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_28' added non terminal implementation                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_28 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_29' added non terminal implementation                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_29 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_30' added non terminal implementation                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_type_5F_level_5F_include::select_implementation_5F_parser_30 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------

#include "utilities/MF_MemoryControl.h"
#include "galgas2/C_galgas_CLI_Options.h"

#include "files/C_FileManager.h"

//----------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                   L L ( 1 )    P R O D U C T I O N    R U L E S                                      
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

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
// At index 7 : <option_value>, in file 'options_parser.ggs', line 54
, TERMINAL (C_Lexique_options_5F_scanner::kToken_string) // $string$
, END_PRODUCTION
// At index 9 : <option_value>, in file 'options_parser.ggs', line 63
, TERMINAL (C_Lexique_options_5F_scanner::kToken_idf) // $idf$
, END_PRODUCTION
// At index 11 : <option_value>, in file 'options_parser.ggs', line 72
, TERMINAL (C_Lexique_options_5F_scanner::kToken_uint_5F_number) // $uint_number$
, END_PRODUCTION
// At index 13 : <option_value>, in file 'options_parser.ggs', line 81
, TERMINAL (C_Lexique_options_5F_scanner::kToken_float_5F_number) // $float_number$
, END_PRODUCTION
// At index 15 : <option_value>, in file 'options_parser.ggs', line 90
, TERMINAL (C_Lexique_options_5F_scanner::kToken__2D_) // $-$
, NONTERMINAL (6) // <select_options_5F_parser_2>
, END_PRODUCTION
// At index 18 : <list_option_value>, in file 'options_parser.ggs', line 106
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
// At index 28 : <select_options_5F_parser_1>, in file 'options_parser.ggs', line 46
, NONTERMINAL (2) // <option_value>
, END_PRODUCTION
// At index 30 : <select_options_5F_parser_1>, in file 'options_parser.ggs', line 46
, NONTERMINAL (3) // <list_option_value>
, END_PRODUCTION
// At index 32 : <select_options_5F_parser_2>, in file 'options_parser.ggs', line 95
, TERMINAL (C_Lexique_options_5F_scanner::kToken_uint_5F_number) // $uint_number$
, END_PRODUCTION
// At index 34 : <select_options_5F_parser_2>, in file 'options_parser.ggs', line 95
, TERMINAL (C_Lexique_options_5F_scanner::kToken_float_5F_number) // $float_number$
, END_PRODUCTION
// At index 36 : <select_options_5F_parser_3>, in file 'options_parser.ggs', line 112
, END_PRODUCTION
// At index 37 : <select_options_5F_parser_3>, in file 'options_parser.ggs', line 112
, TERMINAL (C_Lexique_options_5F_scanner::kToken__2C_) // $,$
, NONTERMINAL (2) // <option_value>
, NONTERMINAL (7) // <select_options_5F_parser_3>
, END_PRODUCTION
// At index 41 : <>, in file '.ggs', line 0
, NONTERMINAL (0) // <option_parser_start>
, END_PRODUCTION
} ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                          P R O D U C T I O N    N A M E S                                            
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                 L L ( 1 )    P R O D U C T I O N    I N D E X E S                                    
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

static const int16_t gProductionIndexes_options_grammar [17] = {
0, // index 0 : <option_parser_start>, in file 'options_parser.ggs', line 29
3, // index 1 : <option_item>, in file 'options_parser.ggs', line 39
7, // index 2 : <option_value>, in file 'options_parser.ggs', line 54
9, // index 3 : <option_value>, in file 'options_parser.ggs', line 63
11, // index 4 : <option_value>, in file 'options_parser.ggs', line 72
13, // index 5 : <option_value>, in file 'options_parser.ggs', line 81
15, // index 6 : <option_value>, in file 'options_parser.ggs', line 90
18, // index 7 : <list_option_value>, in file 'options_parser.ggs', line 106
23, // index 8 : <select_options_5F_parser_0>, in file 'options_parser.ggs', line 33
24, // index 9 : <select_options_5F_parser_0>, in file 'options_parser.ggs', line 33
28, // index 10 : <select_options_5F_parser_1>, in file 'options_parser.ggs', line 46
30, // index 11 : <select_options_5F_parser_1>, in file 'options_parser.ggs', line 46
32, // index 12 : <select_options_5F_parser_2>, in file 'options_parser.ggs', line 95
34, // index 13 : <select_options_5F_parser_2>, in file 'options_parser.ggs', line 95
36, // index 14 : <select_options_5F_parser_3>, in file 'options_parser.ggs', line 112
37, // index 15 : <select_options_5F_parser_3>, in file 'options_parser.ggs', line 112
41 // index 16 : <>, in file '.ggs', line 0
} ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                           L L ( 1 )    F I R S T    P R O D U C T I O N    I N D E X E S                             
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                    L L ( 1 )    D E C I S I O N    T A B L E S                                       
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                            L L ( 1 )    D E C I S I O N    T A B L E S    I N D E X E S                              
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

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

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                 'option_parser_start' non terminal implementation                                    
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_options_5F_grammar::nt_option_5F_parser_5F_start_parse (C_Lexique_options_5F_scanner * inLexique) {
  rule_options_5F_parser_option_5F_parser_5F_start_i0_parse(inLexique) ;
}

void cGrammar_options_5F_grammar::nt_option_5F_parser_5F_start_ (GALGAS_TfieldMap & parameter_1,
                                C_Lexique_options_5F_scanner * inLexique) {
  rule_options_5F_parser_option_5F_parser_5F_start_i0_(parameter_1, inLexique) ;
}

void cGrammar_options_5F_grammar::performIndexing (C_Compiler * /* inCompiler */,
             const C_String & /* inSourceFilePath */) {
}

void cGrammar_options_5F_grammar::performOnlyLexicalAnalysis (C_Compiler * inCompiler,
             const C_String & inSourceFilePath) {
  C_Lexique_options_5F_scanner * scanner = NULL ;
  macroMyNew (scanner, C_Lexique_options_5F_scanner (inCompiler, "", "", inSourceFilePath COMMA_HERE)) ;
  if (scanner->sourceText () != NULL) {
    scanner->performLexicalAnalysis () ;
  }
  macroDetachSharedObject (scanner) ;
}

void cGrammar_options_5F_grammar::performOnlySyntaxAnalysis (C_Compiler * inCompiler,
             const C_String & inSourceFilePath) {
  C_Lexique_options_5F_scanner * scanner = NULL ;
  macroMyNew (scanner, C_Lexique_options_5F_scanner (inCompiler, "", "", inSourceFilePath COMMA_HERE)) ;
  if (scanner->sourceText () != NULL) {
    scanner->performTopDownParsing (gProductions_options_grammar, gProductionNames_options_grammar, gProductionIndexes_options_grammar,
                                    gFirstProductionIndexes_options_grammar, gDecision_options_grammar, gDecisionIndexes_options_grammar, 41) ;
  }
  macroDetachSharedObject (scanner) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                        Grammar start symbol implementation                                           
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_options_5F_grammar::_performSourceFileParsing_ (C_Compiler * inCompiler,
                                GALGAS_lstring inFilePath,
                                GALGAS_TfieldMap &  parameter_1
                                COMMA_LOCATION_ARGS) {
  if (inFilePath.isValid ()) {
    const GALGAS_string filePathAsString = inFilePath.getter_string (HERE) ;
    C_String filePath = filePathAsString.stringValue () ;
    if (! C_FileManager::isAbsolutePath (filePath)) {
      filePath = inCompiler->sourceFilePath ().stringByDeletingLastPathComponent ().stringByAppendingPathComponent (filePath) ;
    }
    if (C_FileManager::fileExistsAtPath (filePath)) {
    C_Lexique_options_5F_scanner * scanner = NULL ;
    macroMyNew (scanner, C_Lexique_options_5F_scanner (inCompiler, "", "", filePath COMMA_HERE)) ;
    if (scanner->sourceText () != NULL) {
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
        inCompiler->semanticErrorAtLocation (errorLocation, message COMMA_THERE) ;
      }
      macroDetachSharedObject (scanner) ;
    }else{
      C_String message ;
      message << "the '" << filePath << "' file does not exist" ;
      const GALGAS_location errorLocation (inFilePath.getter_location (THERE)) ;
      inCompiler->semanticErrorAtLocation (errorLocation, message COMMA_THERE) ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cGrammar_options_5F_grammar::_performSourceStringParsing_ (C_Compiler * inCompiler,
                                GALGAS_string inSourceString,
                                GALGAS_string inNameString,
                                GALGAS_TfieldMap &  parameter_1
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

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                     'option_item' non terminal implementation                                        
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_options_5F_grammar::nt_option_5F_item_parse (C_Lexique_options_5F_scanner * inLexique) {
  rule_options_5F_parser_option_5F_item_i1_parse(inLexique) ;
}

void cGrammar_options_5F_grammar::nt_option_5F_item_ (GALGAS_TfieldMap & parameter_1,
                                C_Lexique_options_5F_scanner * inLexique) {
  rule_options_5F_parser_option_5F_item_i1_(parameter_1, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                     'option_value' non terminal implementation                                       
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

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

void cGrammar_options_5F_grammar::nt_option_5F_value_ (GALGAS_Ttype & parameter_1,
                                GALGAS_Tvalue & parameter_2,
                                C_Lexique_options_5F_scanner * inLexique) {
  switch (inLexique->nextProductionIndex ()) {
  case 1 :
    rule_options_5F_parser_option_5F_value_i2_(parameter_1, parameter_2, inLexique) ;
    break ;
  case 2 :
    rule_options_5F_parser_option_5F_value_i3_(parameter_1, parameter_2, inLexique) ;
    break ;
  case 3 :
    rule_options_5F_parser_option_5F_value_i4_(parameter_1, parameter_2, inLexique) ;
    break ;
  case 4 :
    rule_options_5F_parser_option_5F_value_i5_(parameter_1, parameter_2, inLexique) ;
    break ;
  case 5 :
    rule_options_5F_parser_option_5F_value_i6_(parameter_1, parameter_2, inLexique) ;
    break ;
  default :
    break ;
  }
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                  'list_option_value' non terminal implementation                                     
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_options_5F_grammar::nt_list_5F_option_5F_value_parse (C_Lexique_options_5F_scanner * inLexique) {
  rule_options_5F_parser_list_5F_option_5F_value_i7_parse(inLexique) ;
}

void cGrammar_options_5F_grammar::nt_list_5F_option_5F_value_ (GALGAS_Ttype & parameter_1,
                                GALGAS_Tvalue & parameter_2,
                                C_Lexique_options_5F_scanner * inLexique) {
  rule_options_5F_parser_list_5F_option_5F_value_i7_(parameter_1, parameter_2, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                           'select_options_5F_parser_0' added non terminal implementation                             
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_options_5F_grammar::select_options_5F_parser_0 (C_Lexique_options_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                           'select_options_5F_parser_1' added non terminal implementation                             
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_options_5F_grammar::select_options_5F_parser_1 (C_Lexique_options_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                           'select_options_5F_parser_2' added non terminal implementation                             
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_options_5F_grammar::select_options_5F_parser_2 (C_Lexique_options_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                           'select_options_5F_parser_3' added non terminal implementation                             
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_options_5F_grammar::select_options_5F_parser_3 (C_Lexique_options_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------

#include "utilities/MF_MemoryControl.h"
#include "galgas2/C_galgas_CLI_Options.h"

#include "files/C_FileManager.h"

//----------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                   L L ( 1 )    P R O D U C T I O N    R U L E S                                      
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

#define TERMINAL(t)     ((t)+1)
#define NONTERMINAL(nt) ((-nt)-1)
#define END_PRODUCTION  (0)

static const int16_t gProductions_goil_grammar [] = {
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
// At index 32 : <boolean>, in file 'goil_syntax.ggs', line 230
, NONTERMINAL (41) // <select_goil_5F_syntax_5>
, END_PRODUCTION
// At index 34 : <oil_declaration_list>, in file 'goil_syntax.ggs', line 240
, NONTERMINAL (42) // <select_goil_5F_syntax_6>
, END_PRODUCTION
// At index 36 : <oil_declaration>, in file 'goil_syntax.ggs', line 252
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (43) // <select_goil_5F_syntax_7>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, END_PRODUCTION
// At index 40 : <include_file_level>, in file 'goil_syntax.ggs', line 425
, NONTERMINAL (48) // <select_goil_5F_syntax_12>
, NONTERMINAL (49) // <select_goil_5F_syntax_13>
, END_PRODUCTION
// At index 43 : <include_cpu_level>, in file 'goil_syntax.ggs', line 449
, NONTERMINAL (50) // <select_goil_5F_syntax_14>
, NONTERMINAL (51) // <select_goil_5F_syntax_15>
, END_PRODUCTION
// At index 46 : <include_object_level>, in file 'goil_syntax.ggs', line 473
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
// At index 65 : <implementation_type>, in file 'implementation_parser.ggs', line 212
, NONTERMINAL (61) // <select_implementation_5F_parser_7>
, END_PRODUCTION
// At index 67 : <struct_options>, in file 'implementation_parser.ggs', line 240
, NONTERMINAL (62) // <select_implementation_5F_parser_8>
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (33) // <multiple>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 72 : <objref_option>, in file 'implementation_parser.ggs', line 257
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (33) // <multiple>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 76 : <string_options>, in file 'implementation_parser.ggs', line 275
, NONTERMINAL (28) // <with_auto>
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (33) // <multiple>
, NONTERMINAL (63) // <select_implementation_5F_parser_9>
, END_PRODUCTION
// At index 81 : <boolean_options>, in file 'implementation_parser.ggs', line 307
, NONTERMINAL (28) // <with_auto>
, NONTERMINAL (65) // <select_implementation_5F_parser_11>
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (33) // <multiple>
, NONTERMINAL (68) // <select_implementation_5F_parser_14>
, END_PRODUCTION
// At index 87 : <enum_item>, in file 'implementation_parser.ggs', line 352
, NONTERMINAL (35) // <identifier_or_enum_value>
, NONTERMINAL (69) // <select_implementation_5F_parser_15>
, END_PRODUCTION
// At index 90 : <enum_options>, in file 'implementation_parser.ggs', line 365
, NONTERMINAL (28) // <with_auto>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) // $[$
, NONTERMINAL (24) // <enum_item>
, NONTERMINAL (70) // <select_implementation_5F_parser_16>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) // $]$
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (33) // <multiple>
, NONTERMINAL (71) // <select_implementation_5F_parser_17>
, END_PRODUCTION
// At index 99 : <number_options>, in file 'implementation_parser.ggs', line 407
, NONTERMINAL (28) // <with_auto>
, NONTERMINAL (32) // <range>
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (33) // <multiple>
, NONTERMINAL (73) // <select_implementation_5F_parser_19>
, END_PRODUCTION
// At index 105 : <type_options>, in file 'implementation_parser.ggs', line 441
, NONTERMINAL (28) // <with_auto>
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (33) // <multiple>
, NONTERMINAL (75) // <select_implementation_5F_parser_21>
, END_PRODUCTION
// At index 110 : <with_auto>, in file 'implementation_parser.ggs', line 475
, NONTERMINAL (77) // <select_implementation_5F_parser_23>
, END_PRODUCTION
// At index 112 : <int_or_float>, in file 'implementation_parser.ggs', line 484
, NONTERMINAL (3) // <sign>
, NONTERMINAL (78) // <select_implementation_5F_parser_24>
, END_PRODUCTION
// At index 115 : <set_followup>, in file 'implementation_parser.ggs', line 502
, NONTERMINAL (79) // <select_implementation_5F_parser_25>
, END_PRODUCTION
// At index 117 : <range_content>, in file 'implementation_parser.ggs', line 514
, NONTERMINAL (3) // <sign>
, NONTERMINAL (80) // <select_implementation_5F_parser_26>
, END_PRODUCTION
// At index 120 : <range>, in file 'implementation_parser.ggs', line 554
, NONTERMINAL (83) // <select_implementation_5F_parser_29>
, END_PRODUCTION
// At index 122 : <multiple>, in file 'implementation_parser.ggs', line 564
, NONTERMINAL (84) // <select_implementation_5F_parser_30>
, END_PRODUCTION
// At index 124 : <identifier_or_attribute>, in file 'implementation_parser.ggs', line 574
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, END_PRODUCTION
// At index 126 : <identifier_or_enum_value>, in file 'implementation_parser.ggs', line 579
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
// At index 165 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 231
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_TRUE) // $TRUE$
, END_PRODUCTION
// At index 167 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 231
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_FALSE) // $FALSE$
, END_PRODUCTION
// At index 169 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 244
, END_PRODUCTION
// At index 170 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 244
, NONTERMINAL (10) // <oil_declaration>
, NONTERMINAL (42) // <select_goil_5F_syntax_6>
, END_PRODUCTION
// At index 173 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 244
, NONTERMINAL (13) // <include_object_level>
, NONTERMINAL (42) // <select_goil_5F_syntax_6>
, END_PRODUCTION
// At index 176 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 269
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (44) // <select_goil_5F_syntax_8>
, END_PRODUCTION
// At index 179 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 269
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (9) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 185 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (45) // <select_goil_5F_syntax_9>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 189 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
, NONTERMINAL (3) // <sign>
, NONTERMINAL (46) // <select_goil_5F_syntax_10>
, END_PRODUCTION
// At index 192 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
, NONTERMINAL (8) // <boolean>
, NONTERMINAL (47) // <select_goil_5F_syntax_11>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 196 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 199 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) // $AUTO$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 202 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 292
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (9) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 206 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 292
, END_PRODUCTION
// At index 207 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 309
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) // $uint_number$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 210 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 309
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_float_5F_number) // $float_number$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 213 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 340
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (9) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 217 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 340
, END_PRODUCTION
// At index 218 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 432
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) // $include$
, END_PRODUCTION
// At index 220 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 432
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) // $includeifexists$
, END_PRODUCTION
// At index 222 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 438
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) // $g_string$
, END_PRODUCTION
// At index 224 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 438
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, END_PRODUCTION
// At index 226 : <select_goil_5F_syntax_14>, in file 'goil_syntax.ggs', line 456
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) // $include$
, END_PRODUCTION
// At index 228 : <select_goil_5F_syntax_14>, in file 'goil_syntax.ggs', line 456
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) // $includeifexists$
, END_PRODUCTION
// At index 230 : <select_goil_5F_syntax_15>, in file 'goil_syntax.ggs', line 462
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) // $g_string$
, END_PRODUCTION
// At index 232 : <select_goil_5F_syntax_15>, in file 'goil_syntax.ggs', line 462
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, END_PRODUCTION
// At index 234 : <select_goil_5F_syntax_16>, in file 'goil_syntax.ggs', line 478
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) // $include$
, END_PRODUCTION
// At index 236 : <select_goil_5F_syntax_16>, in file 'goil_syntax.ggs', line 478
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) // $includeifexists$
, END_PRODUCTION
// At index 238 : <select_goil_5F_syntax_17>, in file 'goil_syntax.ggs', line 484
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) // $g_string$
, END_PRODUCTION
// At index 240 : <select_goil_5F_syntax_17>, in file 'goil_syntax.ggs', line 484
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
// At index 278 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_UINT_33__32_) // $UINT32$
, NONTERMINAL (26) // <number_options>
, END_PRODUCTION
// At index 281 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_INT_33__32_) // $INT32$
, NONTERMINAL (26) // <number_options>
, END_PRODUCTION
// At index 284 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_UINT_36__34_) // $UINT64$
, NONTERMINAL (26) // <number_options>
, END_PRODUCTION
// At index 287 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_INT_36__34_) // $INT64$
, NONTERMINAL (26) // <number_options>
, END_PRODUCTION
// At index 290 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_FLOAT) // $FLOAT$
, NONTERMINAL (26) // <number_options>
, END_PRODUCTION
// At index 293 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_ENUM) // $ENUM$
, NONTERMINAL (25) // <enum_options>
, END_PRODUCTION
// At index 296 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_BOOLEAN) // $BOOLEAN$
, NONTERMINAL (23) // <boolean_options>
, END_PRODUCTION
// At index 299 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_STRING) // $STRING$
, NONTERMINAL (22) // <string_options>
, END_PRODUCTION
// At index 302 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_IDENTIFIER) // $IDENTIFIER$
, NONTERMINAL (27) // <type_options>
, END_PRODUCTION
// At index 305 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_STRUCT) // $STRUCT$
, NONTERMINAL (20) // <struct_options>
, END_PRODUCTION
// At index 308 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (21) // <objref_option>
, END_PRODUCTION
// At index 311 : <select_implementation_5F_parser_8>, in file 'implementation_parser.ggs', line 244
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (18) // <implementation_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 315 : <select_implementation_5F_parser_8>, in file 'implementation_parser.ggs', line 244
, END_PRODUCTION
// At index 316 : <select_implementation_5F_parser_9>, in file 'implementation_parser.ggs', line 285
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (64) // <select_implementation_5F_parser_10>
, END_PRODUCTION
// At index 319 : <select_implementation_5F_parser_9>, in file 'implementation_parser.ggs', line 285
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 321 : <select_implementation_5F_parser_10>, in file 'implementation_parser.ggs', line 287
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 324 : <select_implementation_5F_parser_10>, in file 'implementation_parser.ggs', line 287
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) // $AUTO$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 327 : <select_implementation_5F_parser_10>, in file 'implementation_parser.ggs', line 287
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT) // $NO_DEFAULT$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 330 : <select_implementation_5F_parser_11>, in file 'implementation_parser.ggs', line 314
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) // $[$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_TRUE) // $TRUE$
, NONTERMINAL (66) // <select_implementation_5F_parser_12>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2C_) // $,$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_FALSE) // $FALSE$
, NONTERMINAL (67) // <select_implementation_5F_parser_13>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) // $]$
, END_PRODUCTION
// At index 338 : <select_implementation_5F_parser_11>, in file 'implementation_parser.ggs', line 314
, END_PRODUCTION
// At index 339 : <select_implementation_5F_parser_12>, in file 'implementation_parser.ggs', line 317
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (18) // <implementation_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 343 : <select_implementation_5F_parser_12>, in file 'implementation_parser.ggs', line 317
, END_PRODUCTION
// At index 344 : <select_implementation_5F_parser_13>, in file 'implementation_parser.ggs', line 326
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (18) // <implementation_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 348 : <select_implementation_5F_parser_13>, in file 'implementation_parser.ggs', line 326
, END_PRODUCTION
// At index 349 : <select_implementation_5F_parser_14>, in file 'implementation_parser.ggs', line 340
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (8) // <boolean>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 353 : <select_implementation_5F_parser_14>, in file 'implementation_parser.ggs', line 340
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 355 : <select_implementation_5F_parser_15>, in file 'implementation_parser.ggs', line 357
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (18) // <implementation_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 359 : <select_implementation_5F_parser_15>, in file 'implementation_parser.ggs', line 357
, END_PRODUCTION
// At index 360 : <select_implementation_5F_parser_16>, in file 'implementation_parser.ggs', line 373
, END_PRODUCTION
// At index 361 : <select_implementation_5F_parser_16>, in file 'implementation_parser.ggs', line 373
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2C_) // $,$
, NONTERMINAL (24) // <enum_item>
, NONTERMINAL (70) // <select_implementation_5F_parser_16>
, END_PRODUCTION
// At index 365 : <select_implementation_5F_parser_17>, in file 'implementation_parser.ggs', line 383
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (72) // <select_implementation_5F_parser_18>
, END_PRODUCTION
// At index 368 : <select_implementation_5F_parser_17>, in file 'implementation_parser.ggs', line 383
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 370 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 385
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 373 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 385
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) // $AUTO$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 376 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 385
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT) // $NO_DEFAULT$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 379 : <select_implementation_5F_parser_19>, in file 'implementation_parser.ggs', line 420
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (74) // <select_implementation_5F_parser_20>
, END_PRODUCTION
// At index 382 : <select_implementation_5F_parser_19>, in file 'implementation_parser.ggs', line 420
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 384 : <select_implementation_5F_parser_20>, in file 'implementation_parser.ggs', line 422
, NONTERMINAL (29) // <int_or_float>
, END_PRODUCTION
// At index 386 : <select_implementation_5F_parser_20>, in file 'implementation_parser.ggs', line 422
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT) // $NO_DEFAULT$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 389 : <select_implementation_5F_parser_20>, in file 'implementation_parser.ggs', line 422
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) // $AUTO$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 392 : <select_implementation_5F_parser_21>, in file 'implementation_parser.ggs', line 452
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (76) // <select_implementation_5F_parser_22>
, END_PRODUCTION
// At index 395 : <select_implementation_5F_parser_21>, in file 'implementation_parser.ggs', line 452
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 397 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 454
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 400 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 454
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT) // $NO_DEFAULT$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 403 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 454
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) // $AUTO$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 406 : <select_implementation_5F_parser_23>, in file 'implementation_parser.ggs', line 477
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_WITH_5F_AUTO) // $WITH_AUTO$
, END_PRODUCTION
// At index 408 : <select_implementation_5F_parser_23>, in file 'implementation_parser.ggs', line 477
, END_PRODUCTION
// At index 409 : <select_implementation_5F_parser_24>, in file 'implementation_parser.ggs', line 489
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) // $uint_number$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 412 : <select_implementation_5F_parser_24>, in file 'implementation_parser.ggs', line 489
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_float_5F_number) // $float_number$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 415 : <select_implementation_5F_parser_25>, in file 'implementation_parser.ggs', line 505
, END_PRODUCTION
// At index 416 : <select_implementation_5F_parser_25>, in file 'implementation_parser.ggs', line 505
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2C_) // $,$
, NONTERMINAL (29) // <int_or_float>
, NONTERMINAL (79) // <select_implementation_5F_parser_25>
, END_PRODUCTION
// At index 420 : <select_implementation_5F_parser_26>, in file 'implementation_parser.ggs', line 521
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_set_5F_start_5F_uint_5F_number) // $set_start_uint_number$
, NONTERMINAL (29) // <int_or_float>
, END_PRODUCTION
// At index 423 : <select_implementation_5F_parser_26>, in file 'implementation_parser.ggs', line 521
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) // $uint_number$
, NONTERMINAL (81) // <select_implementation_5F_parser_27>
, END_PRODUCTION
// At index 426 : <select_implementation_5F_parser_26>, in file 'implementation_parser.ggs', line 521
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_float_5F_number) // $float_number$
, NONTERMINAL (82) // <select_implementation_5F_parser_28>
, END_PRODUCTION
// At index 429 : <select_implementation_5F_parser_27>, in file 'implementation_parser.ggs', line 531
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2E__2E_) // $..$
, NONTERMINAL (29) // <int_or_float>
, END_PRODUCTION
// At index 432 : <select_implementation_5F_parser_27>, in file 'implementation_parser.ggs', line 531
, NONTERMINAL (30) // <set_followup>
, END_PRODUCTION
// At index 434 : <select_implementation_5F_parser_28>, in file 'implementation_parser.ggs', line 543
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2E__2E_) // $..$
, NONTERMINAL (29) // <int_or_float>
, END_PRODUCTION
// At index 437 : <select_implementation_5F_parser_28>, in file 'implementation_parser.ggs', line 543
, NONTERMINAL (30) // <set_followup>
, END_PRODUCTION
// At index 439 : <select_implementation_5F_parser_29>, in file 'implementation_parser.ggs', line 557
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) // $[$
, NONTERMINAL (31) // <range_content>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) // $]$
, END_PRODUCTION
// At index 443 : <select_implementation_5F_parser_29>, in file 'implementation_parser.ggs', line 557
, END_PRODUCTION
// At index 444 : <select_implementation_5F_parser_30>, in file 'implementation_parser.ggs', line 566
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) // $[$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) // $]$
, END_PRODUCTION
// At index 447 : <select_implementation_5F_parser_30>, in file 'implementation_parser.ggs', line 566
, END_PRODUCTION
// At index 448 : <>, in file '.ggs', line 0
, NONTERMINAL (1) // <start>
, END_PRODUCTION
} ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                          P R O D U C T I O N    N A M E S                                            
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

static const cProductionNameDescriptor gProductionNames_goil_grammar [159] = {
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

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                 L L ( 1 )    P R O D U C T I O N    I N D E X E S                                    
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

static const int16_t gProductionIndexes_goil_grammar [159] = {
0, // index 0 : <implementation_definition>, in file 'implementation_parser.ggs', line 55
7, // index 1 : <start>, in file 'goil_syntax.ggs', line 38
10, // index 2 : <file>, in file 'goil_syntax.ggs', line 110
12, // index 3 : <sign>, in file 'goil_syntax.ggs', line 126
14, // index 4 : <description>, in file 'goil_syntax.ggs', line 139
16, // index 5 : <OIL_version>, in file 'goil_syntax.ggs', line 163
22, // index 6 : <application_definition>, in file 'goil_syntax.ggs', line 170
30, // index 7 : <object_definition_list>, in file 'goil_syntax.ggs', line 184
32, // index 8 : <boolean>, in file 'goil_syntax.ggs', line 230
34, // index 9 : <oil_declaration_list>, in file 'goil_syntax.ggs', line 240
36, // index 10 : <oil_declaration>, in file 'goil_syntax.ggs', line 252
40, // index 11 : <include_file_level>, in file 'goil_syntax.ggs', line 425
43, // index 12 : <include_cpu_level>, in file 'goil_syntax.ggs', line 449
46, // index 13 : <include_object_level>, in file 'goil_syntax.ggs', line 473
49, // index 14 : <implementation_object_list>, in file 'implementation_parser.ggs', line 62
51, // index 15 : <include_implementation_level>, in file 'implementation_parser.ggs', line 71
54, // index 16 : <include_type_level>, in file 'implementation_parser.ggs', line 92
57, // index 17 : <implementation_objects>, in file 'implementation_parser.ggs', line 135
63, // index 18 : <implementation_list>, in file 'implementation_parser.ggs', line 183
65, // index 19 : <implementation_type>, in file 'implementation_parser.ggs', line 212
67, // index 20 : <struct_options>, in file 'implementation_parser.ggs', line 240
72, // index 21 : <objref_option>, in file 'implementation_parser.ggs', line 257
76, // index 22 : <string_options>, in file 'implementation_parser.ggs', line 275
81, // index 23 : <boolean_options>, in file 'implementation_parser.ggs', line 307
87, // index 24 : <enum_item>, in file 'implementation_parser.ggs', line 352
90, // index 25 : <enum_options>, in file 'implementation_parser.ggs', line 365
99, // index 26 : <number_options>, in file 'implementation_parser.ggs', line 407
105, // index 27 : <type_options>, in file 'implementation_parser.ggs', line 441
110, // index 28 : <with_auto>, in file 'implementation_parser.ggs', line 475
112, // index 29 : <int_or_float>, in file 'implementation_parser.ggs', line 484
115, // index 30 : <set_followup>, in file 'implementation_parser.ggs', line 502
117, // index 31 : <range_content>, in file 'implementation_parser.ggs', line 514
120, // index 32 : <range>, in file 'implementation_parser.ggs', line 554
122, // index 33 : <multiple>, in file 'implementation_parser.ggs', line 564
124, // index 34 : <identifier_or_attribute>, in file 'implementation_parser.ggs', line 574
126, // index 35 : <identifier_or_enum_value>, in file 'implementation_parser.ggs', line 579
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
165, // index 50 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 231
167, // index 51 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 231
169, // index 52 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 244
170, // index 53 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 244
173, // index 54 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 244
176, // index 55 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 269
179, // index 56 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 269
185, // index 57 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
189, // index 58 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
192, // index 59 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
196, // index 60 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
199, // index 61 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 271
202, // index 62 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 292
206, // index 63 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 292
207, // index 64 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 309
210, // index 65 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 309
213, // index 66 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 340
217, // index 67 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 340
218, // index 68 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 432
220, // index 69 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 432
222, // index 70 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 438
224, // index 71 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 438
226, // index 72 : <select_goil_5F_syntax_14>, in file 'goil_syntax.ggs', line 456
228, // index 73 : <select_goil_5F_syntax_14>, in file 'goil_syntax.ggs', line 456
230, // index 74 : <select_goil_5F_syntax_15>, in file 'goil_syntax.ggs', line 462
232, // index 75 : <select_goil_5F_syntax_15>, in file 'goil_syntax.ggs', line 462
234, // index 76 : <select_goil_5F_syntax_16>, in file 'goil_syntax.ggs', line 478
236, // index 77 : <select_goil_5F_syntax_16>, in file 'goil_syntax.ggs', line 478
238, // index 78 : <select_goil_5F_syntax_17>, in file 'goil_syntax.ggs', line 484
240, // index 79 : <select_goil_5F_syntax_17>, in file 'goil_syntax.ggs', line 484
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
278, // index 96 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
281, // index 97 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
284, // index 98 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
287, // index 99 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
290, // index 100 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
293, // index 101 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
296, // index 102 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
299, // index 103 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
302, // index 104 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
305, // index 105 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
308, // index 106 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 215
311, // index 107 : <select_implementation_5F_parser_8>, in file 'implementation_parser.ggs', line 244
315, // index 108 : <select_implementation_5F_parser_8>, in file 'implementation_parser.ggs', line 244
316, // index 109 : <select_implementation_5F_parser_9>, in file 'implementation_parser.ggs', line 285
319, // index 110 : <select_implementation_5F_parser_9>, in file 'implementation_parser.ggs', line 285
321, // index 111 : <select_implementation_5F_parser_10>, in file 'implementation_parser.ggs', line 287
324, // index 112 : <select_implementation_5F_parser_10>, in file 'implementation_parser.ggs', line 287
327, // index 113 : <select_implementation_5F_parser_10>, in file 'implementation_parser.ggs', line 287
330, // index 114 : <select_implementation_5F_parser_11>, in file 'implementation_parser.ggs', line 314
338, // index 115 : <select_implementation_5F_parser_11>, in file 'implementation_parser.ggs', line 314
339, // index 116 : <select_implementation_5F_parser_12>, in file 'implementation_parser.ggs', line 317
343, // index 117 : <select_implementation_5F_parser_12>, in file 'implementation_parser.ggs', line 317
344, // index 118 : <select_implementation_5F_parser_13>, in file 'implementation_parser.ggs', line 326
348, // index 119 : <select_implementation_5F_parser_13>, in file 'implementation_parser.ggs', line 326
349, // index 120 : <select_implementation_5F_parser_14>, in file 'implementation_parser.ggs', line 340
353, // index 121 : <select_implementation_5F_parser_14>, in file 'implementation_parser.ggs', line 340
355, // index 122 : <select_implementation_5F_parser_15>, in file 'implementation_parser.ggs', line 357
359, // index 123 : <select_implementation_5F_parser_15>, in file 'implementation_parser.ggs', line 357
360, // index 124 : <select_implementation_5F_parser_16>, in file 'implementation_parser.ggs', line 373
361, // index 125 : <select_implementation_5F_parser_16>, in file 'implementation_parser.ggs', line 373
365, // index 126 : <select_implementation_5F_parser_17>, in file 'implementation_parser.ggs', line 383
368, // index 127 : <select_implementation_5F_parser_17>, in file 'implementation_parser.ggs', line 383
370, // index 128 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 385
373, // index 129 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 385
376, // index 130 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 385
379, // index 131 : <select_implementation_5F_parser_19>, in file 'implementation_parser.ggs', line 420
382, // index 132 : <select_implementation_5F_parser_19>, in file 'implementation_parser.ggs', line 420
384, // index 133 : <select_implementation_5F_parser_20>, in file 'implementation_parser.ggs', line 422
386, // index 134 : <select_implementation_5F_parser_20>, in file 'implementation_parser.ggs', line 422
389, // index 135 : <select_implementation_5F_parser_20>, in file 'implementation_parser.ggs', line 422
392, // index 136 : <select_implementation_5F_parser_21>, in file 'implementation_parser.ggs', line 452
395, // index 137 : <select_implementation_5F_parser_21>, in file 'implementation_parser.ggs', line 452
397, // index 138 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 454
400, // index 139 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 454
403, // index 140 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 454
406, // index 141 : <select_implementation_5F_parser_23>, in file 'implementation_parser.ggs', line 477
408, // index 142 : <select_implementation_5F_parser_23>, in file 'implementation_parser.ggs', line 477
409, // index 143 : <select_implementation_5F_parser_24>, in file 'implementation_parser.ggs', line 489
412, // index 144 : <select_implementation_5F_parser_24>, in file 'implementation_parser.ggs', line 489
415, // index 145 : <select_implementation_5F_parser_25>, in file 'implementation_parser.ggs', line 505
416, // index 146 : <select_implementation_5F_parser_25>, in file 'implementation_parser.ggs', line 505
420, // index 147 : <select_implementation_5F_parser_26>, in file 'implementation_parser.ggs', line 521
423, // index 148 : <select_implementation_5F_parser_26>, in file 'implementation_parser.ggs', line 521
426, // index 149 : <select_implementation_5F_parser_26>, in file 'implementation_parser.ggs', line 521
429, // index 150 : <select_implementation_5F_parser_27>, in file 'implementation_parser.ggs', line 531
432, // index 151 : <select_implementation_5F_parser_27>, in file 'implementation_parser.ggs', line 531
434, // index 152 : <select_implementation_5F_parser_28>, in file 'implementation_parser.ggs', line 543
437, // index 153 : <select_implementation_5F_parser_28>, in file 'implementation_parser.ggs', line 543
439, // index 154 : <select_implementation_5F_parser_29>, in file 'implementation_parser.ggs', line 557
443, // index 155 : <select_implementation_5F_parser_29>, in file 'implementation_parser.ggs', line 557
444, // index 156 : <select_implementation_5F_parser_30>, in file 'implementation_parser.ggs', line 566
447, // index 157 : <select_implementation_5F_parser_30>, in file 'implementation_parser.ggs', line 566
448 // index 158 : <>, in file '.ggs', line 0
} ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                           L L ( 1 )    F I R S T    P R O D U C T I O N    I N D E X E S                             
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

static const int16_t gFirstProductionIndexes_goil_grammar [87] = {
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

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                    L L ( 1 )    D E C I S I O N    T A B L E S                                       
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

static const int16_t gDecision_goil_grammar [] = {
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
C_Lexique_goil_5F_lexique::kToken_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_include, C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_IMPLEMENTATION, -1, // Choice 3
C_Lexique_goil_5F_lexique::kToken_CPU, -1, // Choice 4
  -1,
// At index 46 : <select_goil_5F_syntax_1>
C_Lexique_goil_5F_lexique::kToken__2D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__2B_, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_uint_5F_number, C_Lexique_goil_5F_lexique::kToken_float_5F_number, C_Lexique_goil_5F_lexique::kToken_set_5F_start_5F_uint_5F_number, -1, // Choice 3
  -1,
// At index 55 : <select_goil_5F_syntax_2>
C_Lexique_goil_5F_lexique::kToken__3B_, C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, -1, // Choice 2
  -1,
// At index 62 : <select_goil_5F_syntax_3>
C_Lexique_goil_5F_lexique::kToken__3B_, C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 69 : <select_goil_5F_syntax_4>
C_Lexique_goil_5F_lexique::kToken__7D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_include, C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 3
  -1,
// At index 77 : <select_goil_5F_syntax_5>
C_Lexique_goil_5F_lexique::kToken_TRUE, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_FALSE, -1, // Choice 2
  -1,
// At index 82 : <select_goil_5F_syntax_6>
C_Lexique_goil_5F_lexique::kToken__7D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_include, C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 3
  -1,
// At index 90 : <select_goil_5F_syntax_7>
C_Lexique_goil_5F_lexique::kToken__3D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
  -1,
// At index 95 : <select_goil_5F_syntax_8>
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__2D_, C_Lexique_goil_5F_lexique::kToken__2B_, C_Lexique_goil_5F_lexique::kToken_uint_5F_number, C_Lexique_goil_5F_lexique::kToken_float_5F_number, C_Lexique_goil_5F_lexique::kToken_set_5F_start_5F_uint_5F_number, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_TRUE, C_Lexique_goil_5F_lexique::kToken_FALSE, -1, // Choice 3
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 4
C_Lexique_goil_5F_lexique::kToken_AUTO, -1, // Choice 5
  -1,
// At index 111 : <select_goil_5F_syntax_9>
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, -1, // Choice 2
  -1,
// At index 117 : <select_goil_5F_syntax_10>
C_Lexique_goil_5F_lexique::kToken_uint_5F_number, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_float_5F_number, -1, // Choice 2
  -1,
// At index 122 : <select_goil_5F_syntax_11>
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, -1, // Choice 2
  -1,
// At index 128 : <select_goil_5F_syntax_12>
C_Lexique_goil_5F_lexique::kToken_include, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
  -1,
// At index 133 : <select_goil_5F_syntax_13>
C_Lexique_goil_5F_lexique::kToken_g_5F_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 138 : <select_goil_5F_syntax_14>
C_Lexique_goil_5F_lexique::kToken_include, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
  -1,
// At index 143 : <select_goil_5F_syntax_15>
C_Lexique_goil_5F_lexique::kToken_g_5F_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 148 : <select_goil_5F_syntax_16>
C_Lexique_goil_5F_lexique::kToken_include, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
  -1,
// At index 153 : <select_goil_5F_syntax_17>
C_Lexique_goil_5F_lexique::kToken_g_5F_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 158 : <select_implementation_5F_parser_0>
C_Lexique_goil_5F_lexique::kToken__7D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_include, C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 3
  -1,
// At index 166 : <select_implementation_5F_parser_1>
C_Lexique_goil_5F_lexique::kToken_include, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
  -1,
// At index 171 : <select_implementation_5F_parser_2>
C_Lexique_goil_5F_lexique::kToken_g_5F_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 176 : <select_implementation_5F_parser_3>
C_Lexique_goil_5F_lexique::kToken_include, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
  -1,
// At index 181 : <select_implementation_5F_parser_4>
C_Lexique_goil_5F_lexique::kToken_g_5F_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 186 : <select_implementation_5F_parser_5>
C_Lexique_goil_5F_lexique::kToken__5B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 2
  -1,
// At index 191 : <select_implementation_5F_parser_6>
C_Lexique_goil_5F_lexique::kToken__7D_, -1, // Choice 1
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

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                            L L ( 1 )    D E C I S I O N    T A B L E S    I N D E X E S                              
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

static const int16_t gDecisionIndexes_goil_grammar [87] = {
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
46, // at 37 : <select_goil_5F_syntax_1>
55, // at 38 : <select_goil_5F_syntax_2>
62, // at 39 : <select_goil_5F_syntax_3>
69, // at 40 : <select_goil_5F_syntax_4>
77, // at 41 : <select_goil_5F_syntax_5>
82, // at 42 : <select_goil_5F_syntax_6>
90, // at 43 : <select_goil_5F_syntax_7>
95, // at 44 : <select_goil_5F_syntax_8>
111, // at 45 : <select_goil_5F_syntax_9>
117, // at 46 : <select_goil_5F_syntax_10>
122, // at 47 : <select_goil_5F_syntax_11>
128, // at 48 : <select_goil_5F_syntax_12>
133, // at 49 : <select_goil_5F_syntax_13>
138, // at 50 : <select_goil_5F_syntax_14>
143, // at 51 : <select_goil_5F_syntax_15>
148, // at 52 : <select_goil_5F_syntax_16>
153, // at 53 : <select_goil_5F_syntax_17>
158, // at 54 : <select_implementation_5F_parser_0>
166, // at 55 : <select_implementation_5F_parser_1>
171, // at 56 : <select_implementation_5F_parser_2>
176, // at 57 : <select_implementation_5F_parser_3>
181, // at 58 : <select_implementation_5F_parser_4>
186, // at 59 : <select_implementation_5F_parser_5>
191, // at 60 : <select_implementation_5F_parser_6>
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

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                              'implementation_definition' non terminal implementation                                 
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_grammar::nt_implementation_5F_definition_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_definition_i0_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_implementation_5F_definition_ (GALGAS_implementation & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_definition_i0_(parameter_1, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                        'start' non terminal implementation                                           
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_grammar::nt_start_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_start_i0_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_start_ (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_start_i0_(inLexique) ;
}

void cGrammar_goil_5F_grammar::performIndexing (C_Compiler * /* inCompiler */,
             const C_String & /* inSourceFilePath */) {
}

void cGrammar_goil_5F_grammar::performOnlyLexicalAnalysis (C_Compiler * inCompiler,
             const C_String & inSourceFilePath) {
  C_Lexique_goil_5F_lexique * scanner = NULL ;
  macroMyNew (scanner, C_Lexique_goil_5F_lexique (inCompiler, "", "", inSourceFilePath COMMA_HERE)) ;
  if (scanner->sourceText () != NULL) {
    scanner->performLexicalAnalysis () ;
  }
  macroDetachSharedObject (scanner) ;
}

void cGrammar_goil_5F_grammar::performOnlySyntaxAnalysis (C_Compiler * inCompiler,
             const C_String & inSourceFilePath) {
  C_Lexique_goil_5F_lexique * scanner = NULL ;
  macroMyNew (scanner, C_Lexique_goil_5F_lexique (inCompiler, "", "", inSourceFilePath COMMA_HERE)) ;
  if (scanner->sourceText () != NULL) {
    scanner->performTopDownParsing (gProductions_goil_grammar, gProductionNames_goil_grammar, gProductionIndexes_goil_grammar,
                                    gFirstProductionIndexes_goil_grammar, gDecision_goil_grammar, gDecisionIndexes_goil_grammar, 448) ;
  }
  macroDetachSharedObject (scanner) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                        Grammar start symbol implementation                                           
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_grammar::_performSourceFileParsing_ (C_Compiler * inCompiler,
                                GALGAS_lstring inFilePath
                                COMMA_LOCATION_ARGS) {
  if (inFilePath.isValid ()) {
    const GALGAS_string filePathAsString = inFilePath.getter_string (HERE) ;
    C_String filePath = filePathAsString.stringValue () ;
    if (! C_FileManager::isAbsolutePath (filePath)) {
      filePath = inCompiler->sourceFilePath ().stringByDeletingLastPathComponent ().stringByAppendingPathComponent (filePath) ;
    }
    if (C_FileManager::fileExistsAtPath (filePath)) {
    C_Lexique_goil_5F_lexique * scanner = NULL ;
    macroMyNew (scanner, C_Lexique_goil_5F_lexique (inCompiler, "", "", filePath COMMA_HERE)) ;
    if (scanner->sourceText () != NULL) {
      const bool ok = scanner->performTopDownParsing (gProductions_goil_grammar, gProductionNames_goil_grammar, gProductionIndexes_goil_grammar,
                                                      gFirstProductionIndexes_goil_grammar, gDecision_goil_grammar, gDecisionIndexes_goil_grammar, 448) ;
      if (ok && ! executionModeIsSyntaxAnalysisOnly ()) {
        cGrammar_goil_5F_grammar grammar ;
        grammar.nt_start_ (scanner) ;
        }
      }else{
        C_String message ;
        message << "the '" << filePath << "' file exists, but cannot be read" ;
        const GALGAS_location errorLocation (inFilePath.getter_location (THERE)) ;
        inCompiler->semanticErrorAtLocation (errorLocation, message COMMA_THERE) ;
      }
      macroDetachSharedObject (scanner) ;
    }else{
      C_String message ;
      message << "the '" << filePath << "' file does not exist" ;
      const GALGAS_location errorLocation (inFilePath.getter_location (THERE)) ;
      inCompiler->semanticErrorAtLocation (errorLocation, message COMMA_THERE) ;
    }
  }
}

//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_grammar::_performSourceStringParsing_ (C_Compiler * inCompiler,
                                GALGAS_string inSourceString,
                                GALGAS_string inNameString
                                COMMA_UNUSED_LOCATION_ARGS) {
  if (inSourceString.isValid () && inNameString.isValid ()) {
    const C_String sourceString = inSourceString.stringValue () ;
    const C_String nameString = inNameString.stringValue () ;
    C_Lexique_goil_5F_lexique * scanner = NULL ;
    macroMyNew (scanner, C_Lexique_goil_5F_lexique (inCompiler, sourceString, nameString COMMA_HERE)) ;
    const bool ok = scanner->performTopDownParsing (gProductions_goil_grammar, gProductionNames_goil_grammar, gProductionIndexes_goil_grammar,
                                                    gFirstProductionIndexes_goil_grammar, gDecision_goil_grammar, gDecisionIndexes_goil_grammar, 448) ;
    if (ok && ! executionModeIsSyntaxAnalysisOnly ()) {
      cGrammar_goil_5F_grammar grammar ;
      grammar.nt_start_ (scanner) ;
    }
    macroDetachSharedObject (scanner) ;
  }
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                         'file' non terminal implementation                                           
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_grammar::nt_file_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_file_i1_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_file_ (GALGAS_implementation & parameter_1,
                                GALGAS_applicationDefinition & parameter_2,
                                GALGAS_string & parameter_3,
                                const GALGAS_bool parameter_4,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_file_i1_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                         'sign' non terminal implementation                                           
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_grammar::nt_sign_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_sign_i2_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_sign_ (GALGAS_bool & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_sign_i2_(parameter_1, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                     'description' non terminal implementation                                        
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_grammar::nt_description_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_description_i3_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_description_ (GALGAS_lstring & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_description_i3_(parameter_1, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                     'OIL_version' non terminal implementation                                        
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_grammar::nt_OIL_5F_version_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_OIL_5F_version_i4_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_OIL_5F_version_ (GALGAS_lstring & parameter_1,
                                GALGAS_lstring & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_OIL_5F_version_i4_(parameter_1, parameter_2, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                'application_definition' non terminal implementation                                  
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_grammar::nt_application_5F_definition_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_application_5F_definition_i5_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_application_5F_definition_ (const GALGAS_implementation parameter_1,
                                GALGAS_applicationDefinition & parameter_2,
                                GALGAS_string & parameter_3,
                                const GALGAS_bool parameter_4,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_application_5F_definition_i5_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                'object_definition_list' non terminal implementation                                  
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_grammar::nt_object_5F_definition_5F_list_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_object_5F_definition_5F_list_i6_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_object_5F_definition_5F_list_ (const GALGAS_implementation parameter_1,
                                GALGAS_objectsMap & parameter_2,
                                GALGAS_string & parameter_3,
                                const GALGAS_bool parameter_4,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_object_5F_definition_5F_list_i6_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                       'boolean' non terminal implementation                                          
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_grammar::nt_boolean_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_boolean_i7_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_boolean_ (GALGAS_lbool & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_boolean_i7_(parameter_1, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                 'oil_declaration_list' non terminal implementation                                   
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_grammar::nt_oil_5F_declaration_5F_list_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_5F_list_i8_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_oil_5F_declaration_5F_list_ (const GALGAS_implementationObjectMap parameter_1,
                                GALGAS_objectAttributes & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_5F_list_i8_(parameter_1, parameter_2, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                   'oil_declaration' non terminal implementation                                      
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_grammar::nt_oil_5F_declaration_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_i9_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_oil_5F_declaration_ (const GALGAS_implementationObjectMap parameter_1,
                                GALGAS_objectAttributes & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_i9_(parameter_1, parameter_2, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                  'include_file_level' non terminal implementation                                    
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_grammar::nt_include_5F_file_5F_level_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_file_5F_level_i10_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_include_5F_file_5F_level_ (GALGAS_implementation & parameter_1,
                                GALGAS_applicationDefinition & parameter_2,
                                GALGAS_string & parameter_3,
                                const GALGAS_bool parameter_4,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_file_5F_level_i10_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                  'include_cpu_level' non terminal implementation                                     
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_grammar::nt_include_5F_cpu_5F_level_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_cpu_5F_level_i11_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_include_5F_cpu_5F_level_ (const GALGAS_implementation parameter_1,
                                GALGAS_objectsMap & parameter_2,
                                GALGAS_string & parameter_3,
                                const GALGAS_bool parameter_4,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_cpu_5F_level_i11_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                 'include_object_level' non terminal implementation                                   
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_grammar::nt_include_5F_object_5F_level_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_object_5F_level_i12_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_include_5F_object_5F_level_ (const GALGAS_implementationObjectMap parameter_1,
                                GALGAS_objectAttributes & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_object_5F_level_i12_(parameter_1, parameter_2, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                              'implementation_object_list' non terminal implementation                                
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_grammar::nt_implementation_5F_object_5F_list_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_object_5F_list_i1_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_implementation_5F_object_5F_list_ (GALGAS_implementation & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_object_5F_list_i1_(parameter_1, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                             'include_implementation_level' non terminal implementation                               
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_grammar::nt_include_5F_implementation_5F_level_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_include_5F_implementation_5F_level_i2_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_include_5F_implementation_5F_level_ (GALGAS_implementation & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_include_5F_implementation_5F_level_i2_(parameter_1, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                  'include_type_level' non terminal implementation                                    
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_grammar::nt_include_5F_type_5F_level_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_include_5F_type_5F_level_i3_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_include_5F_type_5F_level_ (GALGAS_implementationObjectMap & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_include_5F_type_5F_level_i3_(parameter_1, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                'implementation_objects' non terminal implementation                                  
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_grammar::nt_implementation_5F_objects_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_objects_i4_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_implementation_5F_objects_ (GALGAS_implementation & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_objects_i4_(parameter_1, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                 'implementation_list' non terminal implementation                                    
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_grammar::nt_implementation_5F_list_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_list_i5_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_implementation_5F_list_ (GALGAS_implementationObjectMap & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_list_i5_(parameter_1, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                 'implementation_type' non terminal implementation                                    
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_grammar::nt_implementation_5F_type_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_type_i6_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_implementation_5F_type_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_type_i6_(parameter_1, parameter_2, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                    'struct_options' non terminal implementation                                      
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_grammar::nt_struct_5F_options_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_struct_5F_options_i7_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_struct_5F_options_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_struct_5F_options_i7_(parameter_1, parameter_2, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                    'objref_option' non terminal implementation                                       
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_grammar::nt_objref_5F_option_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_objref_5F_option_i8_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_objref_5F_option_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                GALGAS_lstring parameter_3,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_objref_5F_option_i8_(parameter_1, parameter_2, parameter_3, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                    'string_options' non terminal implementation                                      
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_grammar::nt_string_5F_options_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_string_5F_options_i9_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_string_5F_options_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_string_5F_options_i9_(parameter_1, parameter_2, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                   'boolean_options' non terminal implementation                                      
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_grammar::nt_boolean_5F_options_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_boolean_5F_options_i10_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_boolean_5F_options_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_boolean_5F_options_i10_(parameter_1, parameter_2, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                      'enum_item' non terminal implementation                                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_grammar::nt_enum_5F_item_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_enum_5F_item_i11_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_enum_5F_item_ (GALGAS_enumValues & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_enum_5F_item_i11_(parameter_1, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                     'enum_options' non terminal implementation                                       
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_grammar::nt_enum_5F_options_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_enum_5F_options_i12_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_enum_5F_options_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_enum_5F_options_i12_(parameter_1, parameter_2, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                    'number_options' non terminal implementation                                      
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_grammar::nt_number_5F_options_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_number_5F_options_i13_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_number_5F_options_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                const GALGAS_dataType parameter_3,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_number_5F_options_i13_(parameter_1, parameter_2, parameter_3, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                     'type_options' non terminal implementation                                       
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_grammar::nt_type_5F_options_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_type_5F_options_i14_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_type_5F_options_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                const GALGAS_dataType parameter_3,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_type_5F_options_i14_(parameter_1, parameter_2, parameter_3, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                      'with_auto' non terminal implementation                                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_grammar::nt_with_5F_auto_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_with_5F_auto_i15_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_with_5F_auto_ (GALGAS_bool & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_with_5F_auto_i15_(parameter_1, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                     'int_or_float' non terminal implementation                                       
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_grammar::nt_int_5F_or_5F_float_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_int_5F_or_5F_float_i16_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_int_5F_or_5F_float_ (GALGAS_object_5F_t & parameter_1,
                                const GALGAS_dataType parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_int_5F_or_5F_float_i16_(parameter_1, parameter_2, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                     'set_followup' non terminal implementation                                       
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_grammar::nt_set_5F_followup_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_set_5F_followup_i17_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_set_5F_followup_ (GALGAS_numberList & parameter_1,
                                const GALGAS_dataType parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_set_5F_followup_i17_(parameter_1, parameter_2, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                    'range_content' non terminal implementation                                       
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_grammar::nt_range_5F_content_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_range_5F_content_i18_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_range_5F_content_ (GALGAS_attributeRange & parameter_1,
                                const GALGAS_dataType parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_range_5F_content_i18_(parameter_1, parameter_2, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                        'range' non terminal implementation                                           
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_grammar::nt_range_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_range_i19_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_range_ (GALGAS_attributeRange & parameter_1,
                                const GALGAS_dataType parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_range_i19_(parameter_1, parameter_2, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                                       'multiple' non terminal implementation                                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_grammar::nt_multiple_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_multiple_i20_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_multiple_ (GALGAS_bool & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_multiple_i20_(parameter_1, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                               'identifier_or_attribute' non terminal implementation                                  
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_grammar::nt_identifier_5F_or_5F_attribute_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_identifier_5F_or_5F_attribute_i21_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_identifier_5F_or_5F_attribute_ (GALGAS_lstring & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_identifier_5F_or_5F_attribute_i21_(parameter_1, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                               'identifier_or_enum_value' non terminal implementation                                 
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

void cGrammar_goil_5F_grammar::nt_identifier_5F_or_5F_enum_5F_value_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_identifier_5F_or_5F_enum_5F_value_i22_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_identifier_5F_or_5F_enum_5F_value_ (GALGAS_lstring & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_identifier_5F_or_5F_enum_5F_value_i22_(parameter_1, inLexique) ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                            'select_goil_5F_syntax_0' added non terminal implementation                               
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_grammar::select_goil_5F_syntax_0 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                            'select_goil_5F_syntax_1' added non terminal implementation                               
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_grammar::select_goil_5F_syntax_1 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                            'select_goil_5F_syntax_2' added non terminal implementation                               
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_grammar::select_goil_5F_syntax_2 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                            'select_goil_5F_syntax_3' added non terminal implementation                               
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_grammar::select_goil_5F_syntax_3 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                            'select_goil_5F_syntax_4' added non terminal implementation                               
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_grammar::select_goil_5F_syntax_4 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                            'select_goil_5F_syntax_5' added non terminal implementation                               
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_grammar::select_goil_5F_syntax_5 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                            'select_goil_5F_syntax_6' added non terminal implementation                               
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_grammar::select_goil_5F_syntax_6 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                            'select_goil_5F_syntax_7' added non terminal implementation                               
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_grammar::select_goil_5F_syntax_7 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                            'select_goil_5F_syntax_8' added non terminal implementation                               
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_grammar::select_goil_5F_syntax_8 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                            'select_goil_5F_syntax_9' added non terminal implementation                               
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_grammar::select_goil_5F_syntax_9 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                            'select_goil_5F_syntax_10' added non terminal implementation                              
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_grammar::select_goil_5F_syntax_10 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                            'select_goil_5F_syntax_11' added non terminal implementation                              
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_grammar::select_goil_5F_syntax_11 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                            'select_goil_5F_syntax_12' added non terminal implementation                              
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_grammar::select_goil_5F_syntax_12 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                            'select_goil_5F_syntax_13' added non terminal implementation                              
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_grammar::select_goil_5F_syntax_13 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                            'select_goil_5F_syntax_14' added non terminal implementation                              
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_grammar::select_goil_5F_syntax_14 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                            'select_goil_5F_syntax_15' added non terminal implementation                              
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_grammar::select_goil_5F_syntax_15 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                            'select_goil_5F_syntax_16' added non terminal implementation                              
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_grammar::select_goil_5F_syntax_16 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                            'select_goil_5F_syntax_17' added non terminal implementation                              
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_grammar::select_goil_5F_syntax_17 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_0' added non terminal implementation                          
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_0 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_1' added non terminal implementation                          
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_1 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_2' added non terminal implementation                          
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_2 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_3' added non terminal implementation                          
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_3 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_4' added non terminal implementation                          
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_4 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_5' added non terminal implementation                          
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_5 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_6' added non terminal implementation                          
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_6 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_7' added non terminal implementation                          
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_7 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_8' added non terminal implementation                          
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_8 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_9' added non terminal implementation                          
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_9 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_10' added non terminal implementation                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_10 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_11' added non terminal implementation                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_11 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_12' added non terminal implementation                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_12 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_13' added non terminal implementation                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_13 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_14' added non terminal implementation                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_14 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_15' added non terminal implementation                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_15 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_16' added non terminal implementation                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_16 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_17' added non terminal implementation                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_17 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_18' added non terminal implementation                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_18 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_19' added non terminal implementation                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_19 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_20' added non terminal implementation                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_20 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_21' added non terminal implementation                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_21 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_22' added non terminal implementation                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_22 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_23' added non terminal implementation                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_23 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_24' added non terminal implementation                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_24 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_25' added non terminal implementation                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_25 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_26' added non terminal implementation                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_26 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_27' added non terminal implementation                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_27 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_28' added non terminal implementation                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_28 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_29' added non terminal implementation                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_29 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                      
//                       'select_implementation_5F_parser_30' added non terminal implementation                         
//                                                                                                                      
//----------------------------------------------------------------------------------------------------------------------

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_30 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                              Function 'dummyFunction'                                               *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

GALGAS_Tfunction function_dummyFunction (C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_Tfunction result_fct ; // Returned variable
  result_fct = GALGAS_Tfunction::constructor_new (GALGAS_lstring::constructor_new (GALGAS_string::makeEmptyString (), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("template_semantics.galgas", 81))  COMMA_SOURCE_FILE ("template_semantics.galgas", 81)), GALGAS_lstringlist::constructor_emptyList (SOURCE_FILE ("template_semantics.galgas", 81)), GALGAS_string::makeEmptyString ()  COMMA_SOURCE_FILE ("template_semantics.galgas", 81)) ;
//---
  return result_fct ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                                             *
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_dummyFunction [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_dummyFunction (C_Compiler * inCompiler,
                                                              const cObjectArray & /* inEffectiveParameterArray */,
                                                              const GALGAS_location & /* inErrorLocation */
                                                              COMMA_LOCATION_ARGS) {
  return function_dummyFunction (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_dummyFunction ("dummyFunction",
                                                               functionWithGenericHeader_dummyFunction,
                                                               & kTypeDescriptor_GALGAS_Tfunction,
                                                               0,
                                                               functionArgs_dummyFunction) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                              Function 'valueWithBool'                                               *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

GALGAS_Tvalue function_valueWithBool (const GALGAS_bool & constinArgument_inValue,
                                      const GALGAS_lstring & constinArgument_description,
                                      C_Compiler * inCompiler
                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_Tvalue result_outValue ; // Returned variable
  result_outValue = GALGAS_Tvalue::constructor_new (constinArgument_inValue.getter_uint (SOURCE_FILE ("template_semantics.galgas", 123)).getter_bigint (SOURCE_FILE ("template_semantics.galgas", 123)), GALGAS_double (0), GALGAS_string::makeEmptyString (), GALGAS_TfieldMapList::constructor_emptyList (SOURCE_FILE ("template_semantics.galgas", 126)), GALGAS_TfieldMap::constructor_emptyMap (SOURCE_FILE ("template_semantics.galgas", 127)), function_dummyFunction (inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 128)), constinArgument_description  COMMA_SOURCE_FILE ("template_semantics.galgas", 122)) ;
//---
  return result_outValue ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                                             *
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_valueWithBool [3] = {
  & kTypeDescriptor_GALGAS_bool,
  & kTypeDescriptor_GALGAS_lstring,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_valueWithBool (C_Compiler * inCompiler,
                                                              const cObjectArray & inEffectiveParameterArray,
                                                              const GALGAS_location & /* §§ inErrorLocation */
                                                              COMMA_LOCATION_ARGS) {
  const GALGAS_bool operand0 = GALGAS_bool::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                           inCompiler
                                                           COMMA_THERE) ;
  const GALGAS_lstring operand1 = GALGAS_lstring::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  return function_valueWithBool (operand0,
                                 operand1,
                                 inCompiler
                                 COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_valueWithBool ("valueWithBool",
                                                               functionWithGenericHeader_valueWithBool,
                                                               & kTypeDescriptor_GALGAS_Tvalue,
                                                               2,
                                                               functionArgs_valueWithBool) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                            Function 'valueWithUnsigned'                                             *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

GALGAS_Tvalue function_valueWithUnsigned (const GALGAS_bigint & constinArgument_inValue,
                                          const GALGAS_lstring & constinArgument_description,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_Tvalue result_outValue ; // Returned variable
  result_outValue = GALGAS_Tvalue::constructor_new (constinArgument_inValue, GALGAS_double (0), GALGAS_string::makeEmptyString (), GALGAS_TfieldMapList::constructor_emptyList (SOURCE_FILE ("template_semantics.galgas", 142)), GALGAS_TfieldMap::constructor_emptyMap (SOURCE_FILE ("template_semantics.galgas", 143)), function_dummyFunction (inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 144)), constinArgument_description  COMMA_SOURCE_FILE ("template_semantics.galgas", 138)) ;
//---
  return result_outValue ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                                             *
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_valueWithUnsigned [3] = {
  & kTypeDescriptor_GALGAS_bigint,
  & kTypeDescriptor_GALGAS_lstring,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_valueWithUnsigned (C_Compiler * inCompiler,
                                                                  const cObjectArray & inEffectiveParameterArray,
                                                                  const GALGAS_location & /* §§ inErrorLocation */
                                                                  COMMA_LOCATION_ARGS) {
  const GALGAS_bigint operand0 = GALGAS_bigint::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  const GALGAS_lstring operand1 = GALGAS_lstring::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  return function_valueWithUnsigned (operand0,
                                     operand1,
                                     inCompiler
                                     COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_valueWithUnsigned ("valueWithUnsigned",
                                                                   functionWithGenericHeader_valueWithUnsigned,
                                                                   & kTypeDescriptor_GALGAS_Tvalue,
                                                                   2,
                                                                   functionArgs_valueWithUnsigned) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                             Function 'valueWithSigned'                                              *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

GALGAS_Tvalue function_valueWithSigned (const GALGAS_bigint & constinArgument_inValue,
                                        const GALGAS_lstring & constinArgument_description,
                                        C_Compiler * inCompiler
                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_Tvalue result_outValue ; // Returned variable
  result_outValue = GALGAS_Tvalue::constructor_new (constinArgument_inValue, GALGAS_double (0), GALGAS_string::makeEmptyString (), GALGAS_TfieldMapList::constructor_emptyList (SOURCE_FILE ("template_semantics.galgas", 158)), GALGAS_TfieldMap::constructor_emptyMap (SOURCE_FILE ("template_semantics.galgas", 159)), function_dummyFunction (inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 160)), constinArgument_description  COMMA_SOURCE_FILE ("template_semantics.galgas", 154)) ;
//---
  return result_outValue ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                                             *
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_valueWithSigned [3] = {
  & kTypeDescriptor_GALGAS_bigint,
  & kTypeDescriptor_GALGAS_lstring,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_valueWithSigned (C_Compiler * inCompiler,
                                                                const cObjectArray & inEffectiveParameterArray,
                                                                const GALGAS_location & /* §§ inErrorLocation */
                                                                COMMA_LOCATION_ARGS) {
  const GALGAS_bigint operand0 = GALGAS_bigint::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  const GALGAS_lstring operand1 = GALGAS_lstring::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  return function_valueWithSigned (operand0,
                                   operand1,
                                   inCompiler
                                   COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_valueWithSigned ("valueWithSigned",
                                                                 functionWithGenericHeader_valueWithSigned,
                                                                 & kTypeDescriptor_GALGAS_Tvalue,
                                                                 2,
                                                                 functionArgs_valueWithSigned) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                              Function 'valueWithFloat'                                              *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

GALGAS_Tvalue function_valueWithFloat (const GALGAS_double & constinArgument_inValue,
                                       const GALGAS_lstring & constinArgument_description,
                                       C_Compiler * inCompiler
                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_Tvalue result_outValue ; // Returned variable
  result_outValue = GALGAS_Tvalue::constructor_new (GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("template_semantics.galgas", 171)), constinArgument_inValue, GALGAS_string::makeEmptyString (), GALGAS_TfieldMapList::constructor_emptyList (SOURCE_FILE ("template_semantics.galgas", 174)), GALGAS_TfieldMap::constructor_emptyMap (SOURCE_FILE ("template_semantics.galgas", 175)), function_dummyFunction (inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 176)), constinArgument_description  COMMA_SOURCE_FILE ("template_semantics.galgas", 170)) ;
//---
  return result_outValue ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                                             *
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_valueWithFloat [3] = {
  & kTypeDescriptor_GALGAS_double,
  & kTypeDescriptor_GALGAS_lstring,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_valueWithFloat (C_Compiler * inCompiler,
                                                               const cObjectArray & inEffectiveParameterArray,
                                                               const GALGAS_location & /* §§ inErrorLocation */
                                                               COMMA_LOCATION_ARGS) {
  const GALGAS_double operand0 = GALGAS_double::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  const GALGAS_lstring operand1 = GALGAS_lstring::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  return function_valueWithFloat (operand0,
                                  operand1,
                                  inCompiler
                                  COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_valueWithFloat ("valueWithFloat",
                                                                functionWithGenericHeader_valueWithFloat,
                                                                & kTypeDescriptor_GALGAS_Tvalue,
                                                                2,
                                                                functionArgs_valueWithFloat) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                             Function 'valueWithString'                                              *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

GALGAS_Tvalue function_valueWithString (const GALGAS_string & constinArgument_inValue,
                                        const GALGAS_lstring & constinArgument_description,
                                        C_Compiler * inCompiler
                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_Tvalue result_outValue ; // Returned variable
  result_outValue = GALGAS_Tvalue::constructor_new (GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("template_semantics.galgas", 187)), GALGAS_double (0), constinArgument_inValue, GALGAS_TfieldMapList::constructor_emptyList (SOURCE_FILE ("template_semantics.galgas", 190)), GALGAS_TfieldMap::constructor_emptyMap (SOURCE_FILE ("template_semantics.galgas", 191)), function_dummyFunction (inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 192)), constinArgument_description  COMMA_SOURCE_FILE ("template_semantics.galgas", 186)) ;
//---
  return result_outValue ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                                             *
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_valueWithString [3] = {
  & kTypeDescriptor_GALGAS_string,
  & kTypeDescriptor_GALGAS_lstring,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_valueWithString (C_Compiler * inCompiler,
                                                                const cObjectArray & inEffectiveParameterArray,
                                                                const GALGAS_location & /* §§ inErrorLocation */
                                                                COMMA_LOCATION_ARGS) {
  const GALGAS_string operand0 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  const GALGAS_lstring operand1 = GALGAS_lstring::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  return function_valueWithString (operand0,
                                   operand1,
                                   inCompiler
                                   COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_valueWithString ("valueWithString",
                                                                 functionWithGenericHeader_valueWithString,
                                                                 & kTypeDescriptor_GALGAS_Tvalue,
                                                                 2,
                                                                 functionArgs_valueWithString) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                             Function 'valueWithStruct'                                              *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

GALGAS_Tvalue function_valueWithStruct (const GALGAS_TfieldMap & constinArgument_inValue,
                                        const GALGAS_lstring & constinArgument_description,
                                        C_Compiler * inCompiler
                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_Tvalue result_outValue ; // Returned variable
  result_outValue = GALGAS_Tvalue::constructor_new (GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("template_semantics.galgas", 203)), GALGAS_double (0), GALGAS_string::makeEmptyString (), GALGAS_TfieldMapList::constructor_emptyList (SOURCE_FILE ("template_semantics.galgas", 206)), constinArgument_inValue, function_dummyFunction (inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 208)), constinArgument_description  COMMA_SOURCE_FILE ("template_semantics.galgas", 202)) ;
//---
  return result_outValue ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                                             *
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_valueWithStruct [3] = {
  & kTypeDescriptor_GALGAS_TfieldMap,
  & kTypeDescriptor_GALGAS_lstring,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_valueWithStruct (C_Compiler * inCompiler,
                                                                const cObjectArray & inEffectiveParameterArray,
                                                                const GALGAS_location & /* §§ inErrorLocation */
                                                                COMMA_LOCATION_ARGS) {
  const GALGAS_TfieldMap operand0 = GALGAS_TfieldMap::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                     inCompiler
                                                                     COMMA_THERE) ;
  const GALGAS_lstring operand1 = GALGAS_lstring::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  return function_valueWithStruct (operand0,
                                   operand1,
                                   inCompiler
                                   COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_valueWithStruct ("valueWithStruct",
                                                                 functionWithGenericHeader_valueWithStruct,
                                                                 & kTypeDescriptor_GALGAS_Tvalue,
                                                                 2,
                                                                 functionArgs_valueWithStruct) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                               Function 'valueWithMap'                                               *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

GALGAS_Tvalue function_valueWithMap (const GALGAS_TfieldMap & constinArgument_inValue,
                                     const GALGAS_lstring & constinArgument_description,
                                     C_Compiler * inCompiler
                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_Tvalue result_outValue ; // Returned variable
  result_outValue = GALGAS_Tvalue::constructor_new (GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("template_semantics.galgas", 219)), GALGAS_double (0), GALGAS_string::makeEmptyString (), GALGAS_TfieldMapList::constructor_emptyList (SOURCE_FILE ("template_semantics.galgas", 222)), constinArgument_inValue, function_dummyFunction (inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 224)), constinArgument_description  COMMA_SOURCE_FILE ("template_semantics.galgas", 218)) ;
//---
  return result_outValue ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                                             *
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_valueWithMap [3] = {
  & kTypeDescriptor_GALGAS_TfieldMap,
  & kTypeDescriptor_GALGAS_lstring,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_valueWithMap (C_Compiler * inCompiler,
                                                             const cObjectArray & inEffectiveParameterArray,
                                                             const GALGAS_location & /* §§ inErrorLocation */
                                                             COMMA_LOCATION_ARGS) {
  const GALGAS_TfieldMap operand0 = GALGAS_TfieldMap::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                     inCompiler
                                                                     COMMA_THERE) ;
  const GALGAS_lstring operand1 = GALGAS_lstring::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  return function_valueWithMap (operand0,
                                operand1,
                                inCompiler
                                COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_valueWithMap ("valueWithMap",
                                                              functionWithGenericHeader_valueWithMap,
                                                              & kTypeDescriptor_GALGAS_Tvalue,
                                                              2,
                                                              functionArgs_valueWithMap) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                              Function 'valueWithList'                                               *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

GALGAS_Tvalue function_valueWithList (const GALGAS_TfieldMapList & constinArgument_inValue,
                                      const GALGAS_lstring & constinArgument_description,
                                      C_Compiler * inCompiler
                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_Tvalue result_outValue ; // Returned variable
  result_outValue = GALGAS_Tvalue::constructor_new (GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("template_semantics.galgas", 235)), GALGAS_double (0), GALGAS_string::makeEmptyString (), constinArgument_inValue, GALGAS_TfieldMap::constructor_emptyMap (SOURCE_FILE ("template_semantics.galgas", 239)), function_dummyFunction (inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 240)), constinArgument_description  COMMA_SOURCE_FILE ("template_semantics.galgas", 234)) ;
//---
  return result_outValue ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                                             *
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_valueWithList [3] = {
  & kTypeDescriptor_GALGAS_TfieldMapList,
  & kTypeDescriptor_GALGAS_lstring,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_valueWithList (C_Compiler * inCompiler,
                                                              const cObjectArray & inEffectiveParameterArray,
                                                              const GALGAS_location & /* §§ inErrorLocation */
                                                              COMMA_LOCATION_ARGS) {
  const GALGAS_TfieldMapList operand0 = GALGAS_TfieldMapList::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                             inCompiler
                                                                             COMMA_THERE) ;
  const GALGAS_lstring operand1 = GALGAS_lstring::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  return function_valueWithList (operand0,
                                 operand1,
                                 inCompiler
                                 COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_valueWithList ("valueWithList",
                                                               functionWithGenericHeader_valueWithList,
                                                               & kTypeDescriptor_GALGAS_Tvalue,
                                                               2,
                                                               functionArgs_valueWithList) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                              Function 'valueWithVoid'                                               *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

GALGAS_Tvalue function_valueWithVoid (C_Compiler * inCompiler
                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_Tvalue result_outValue ; // Returned variable
  result_outValue = GALGAS_Tvalue::constructor_new (GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("template_semantics.galgas", 249)), GALGAS_double (0), GALGAS_string::makeEmptyString (), GALGAS_TfieldMapList::constructor_emptyList (SOURCE_FILE ("template_semantics.galgas", 252)), GALGAS_TfieldMap::constructor_emptyMap (SOURCE_FILE ("template_semantics.galgas", 253)), function_dummyFunction (inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 254)), GALGAS_lstring::constructor_new (GALGAS_string::makeEmptyString (), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("template_semantics.galgas", 255))  COMMA_SOURCE_FILE ("template_semantics.galgas", 255))  COMMA_SOURCE_FILE ("template_semantics.galgas", 248)) ;
//---
  return result_outValue ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                                             *
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_valueWithVoid [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_valueWithVoid (C_Compiler * inCompiler,
                                                              const cObjectArray & /* inEffectiveParameterArray */,
                                                              const GALGAS_location & /* inErrorLocation */
                                                              COMMA_LOCATION_ARGS) {
  return function_valueWithVoid (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_valueWithVoid ("valueWithVoid",
                                                               functionWithGenericHeader_valueWithVoid,
                                                               & kTypeDescriptor_GALGAS_Tvalue,
                                                               0,
                                                               functionArgs_valueWithVoid) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                               Routine 'addBoolValue'                                                *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

void routine_addBoolValue (GALGAS_TfieldMap & ioArgument_ioTemplateVariableMap,
                           const GALGAS_lstring constinArgument_inVariableName,
                           const GALGAS_bool constinArgument_inValue,
                           const GALGAS_lstring constinArgument_description,
                           C_Compiler * inCompiler
                           COMMA_UNUSED_LOCATION_ARGS) {
  {
  ioArgument_ioTemplateVariableMap.setter_insertKey (constinArgument_inVariableName, GALGAS_Ttype::constructor_boolType (SOURCE_FILE ("template_semantics.galgas", 267)), function_valueWithBool (constinArgument_inValue, constinArgument_description, inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 268)), inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 265)) ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                             Routine 'addUnsignedValue'                                              *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

void routine_addUnsignedValue (GALGAS_TfieldMap & ioArgument_ioTemplateVariableMap,
                               const GALGAS_lstring constinArgument_inVariableName,
                               const GALGAS_bigint constinArgument_inValue,
                               const GALGAS_lstring constinArgument_description,
                               C_Compiler * inCompiler
                               COMMA_UNUSED_LOCATION_ARGS) {
  {
  ioArgument_ioTemplateVariableMap.setter_insertKey (constinArgument_inVariableName, GALGAS_Ttype::constructor_intType (SOURCE_FILE ("template_semantics.galgas", 281)), function_valueWithUnsigned (constinArgument_inValue, constinArgument_description, inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 282)), inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 279)) ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                              Routine 'addSignedValue'                                               *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

void routine_addSignedValue (GALGAS_TfieldMap & ioArgument_ioTemplateVariableMap,
                             const GALGAS_lstring constinArgument_inVariableName,
                             const GALGAS_bigint constinArgument_inValue,
                             const GALGAS_lstring constinArgument_description,
                             C_Compiler * inCompiler
                             COMMA_UNUSED_LOCATION_ARGS) {
  {
  ioArgument_ioTemplateVariableMap.setter_insertKey (constinArgument_inVariableName, GALGAS_Ttype::constructor_intType (SOURCE_FILE ("template_semantics.galgas", 296)), function_valueWithSigned (constinArgument_inValue, constinArgument_description, inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 297)), inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 294)) ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                               Routine 'addFloatValue'                                               *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

void routine_addFloatValue (GALGAS_TfieldMap & ioArgument_ioTemplateVariableMap,
                            const GALGAS_lstring constinArgument_inVariableName,
                            const GALGAS_double constinArgument_inValue,
                            const GALGAS_lstring constinArgument_description,
                            C_Compiler * inCompiler
                            COMMA_UNUSED_LOCATION_ARGS) {
  {
  ioArgument_ioTemplateVariableMap.setter_insertKey (constinArgument_inVariableName, GALGAS_Ttype::constructor_floatType (SOURCE_FILE ("template_semantics.galgas", 311)), function_valueWithFloat (constinArgument_inValue, constinArgument_description, inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 312)), inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 309)) ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                             Routine 'addLUnsignedValue'                                             *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

void routine_addLUnsignedValue (GALGAS_TfieldMap & ioArgument_ioTemplateVariableMap,
                                const GALGAS_string constinArgument_inVariableName,
                                const GALGAS_luint_36__34_ constinArgument_inValue,
                                const GALGAS_lstring constinArgument_description,
                                C_Compiler * inCompiler
                                COMMA_UNUSED_LOCATION_ARGS) {
  {
  routine_addUnsignedValue (ioArgument_ioTemplateVariableMap, GALGAS_lstring::constructor_new (constinArgument_inVariableName, constinArgument_inValue.getter_location (SOURCE_FILE ("template_semantics.galgas", 324))  COMMA_SOURCE_FILE ("template_semantics.galgas", 324)), constinArgument_inValue.mAttribute_uint_36__34_.getter_bigint (SOURCE_FILE ("template_semantics.galgas", 324)), constinArgument_description, inCompiler  COMMA_SOURCE_FILE ("template_semantics.galgas", 324)) ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                              Routine 'addStringValue'                                               *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

void routine_addStringValue (GALGAS_TfieldMap & ioArgument_ioTemplateVariableMap,
                             const GALGAS_lstring constinArgument_inVariableName,
                             const GALGAS_string constinArgument_inValue,
                             const GALGAS_lstring constinArgument_description,
                             C_Compiler * inCompiler
                             COMMA_UNUSED_LOCATION_ARGS) {
  {
  ioArgument_ioTemplateVariableMap.setter_insertKey (constinArgument_inVariableName, GALGAS_Ttype::constructor_stringType (SOURCE_FILE ("template_semantics.galgas", 336)), function_valueWithString (constinArgument_inValue, constinArgument_description, inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 337)), inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 334)) ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                              Routine 'addLStringValue'                                              *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

void routine_addLStringValue (GALGAS_TfieldMap & ioArgument_ioTemplateVariableMap,
                              const GALGAS_string constinArgument_inVariableName,
                              const GALGAS_lstring constinArgument_inValue,
                              const GALGAS_lstring constinArgument_description,
                              C_Compiler * inCompiler
                              COMMA_UNUSED_LOCATION_ARGS) {
  {
  routine_addStringValue (ioArgument_ioTemplateVariableMap, GALGAS_lstring::constructor_new (constinArgument_inVariableName, constinArgument_inValue.getter_location (SOURCE_FILE ("template_semantics.galgas", 349))  COMMA_SOURCE_FILE ("template_semantics.galgas", 349)), constinArgument_inValue.getter_string (SOURCE_FILE ("template_semantics.galgas", 349)), constinArgument_description, inCompiler  COMMA_SOURCE_FILE ("template_semantics.galgas", 349)) ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                               Routine 'addListValue'                                                *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

void routine_addListValue (GALGAS_TfieldMap & ioArgument_ioTemplateVariableMap,
                           const GALGAS_lstring constinArgument_inVariableName,
                           const GALGAS_TfieldMapList constinArgument_inValue,
                           const GALGAS_lstring constinArgument_description,
                           C_Compiler * inCompiler
                           COMMA_UNUSED_LOCATION_ARGS) {
  {
  ioArgument_ioTemplateVariableMap.setter_insertKey (constinArgument_inVariableName, GALGAS_Ttype::constructor_listType (SOURCE_FILE ("template_semantics.galgas", 361)), GALGAS_Tvalue::constructor_new (GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("template_semantics.galgas", 362)), GALGAS_double (0), GALGAS_string::makeEmptyString (), constinArgument_inValue, GALGAS_TfieldMap::constructor_emptyMap (SOURCE_FILE ("template_semantics.galgas", 362)), function_dummyFunction (inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 362)), constinArgument_description  COMMA_SOURCE_FILE ("template_semantics.galgas", 362)), inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 359)) ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                              Routine 'addStructValue'                                               *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

void routine_addStructValue (GALGAS_TfieldMap & ioArgument_ioTemplateVariableMap,
                             const GALGAS_lstring constinArgument_inVariableName,
                             const GALGAS_TfieldMap constinArgument_inValue,
                             const GALGAS_lstring constinArgument_description,
                             C_Compiler * inCompiler
                             COMMA_UNUSED_LOCATION_ARGS) {
  {
  ioArgument_ioTemplateVariableMap.setter_insertKey (constinArgument_inVariableName, GALGAS_Ttype::constructor_structType (SOURCE_FILE ("template_semantics.galgas", 376)), GALGAS_Tvalue::constructor_new (GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("template_semantics.galgas", 377)), GALGAS_double (0), GALGAS_string::makeEmptyString (), GALGAS_TfieldMapList::constructor_emptyList (SOURCE_FILE ("template_semantics.galgas", 377)), constinArgument_inValue, function_dummyFunction (inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 377)), constinArgument_description  COMMA_SOURCE_FILE ("template_semantics.galgas", 377)), inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 374)) ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                               Routine 'addEnumValue'                                                *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

void routine_addEnumValue (GALGAS_TfieldMap & ioArgument_ioTemplateVariableMap,
                           const GALGAS_lstring constinArgument_inVariableName,
                           const GALGAS_string constinArgument_inValue,
                           const GALGAS_lstring constinArgument_description,
                           C_Compiler * inCompiler
                           COMMA_UNUSED_LOCATION_ARGS) {
  {
  ioArgument_ioTemplateVariableMap.setter_insertKey (constinArgument_inVariableName, GALGAS_Ttype::constructor_enumType (SOURCE_FILE ("template_semantics.galgas", 390)), function_valueWithString (constinArgument_inValue, constinArgument_description, inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 391)), inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 388)) ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                                 Routine 'printPath'                                                 *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

void routine_printPath (const GALGAS_TvarPath constinArgument_path,
                        C_Compiler * inCompiler
                        COMMA_UNUSED_LOCATION_ARGS) {
  cEnumerator_TvarPath enumerator_10135 (constinArgument_path, kEnumeration_up) ;
  while (enumerator_10135.hasCurrentObject ()) {
    inCompiler->printMessage (enumerator_10135.current_item (HERE).getter_string (SOURCE_FILE ("template_semantics.galgas", 409))  COMMA_SOURCE_FILE ("template_semantics.galgas", 409)) ;
    const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, enumerator_10135.current_key (HERE).getter_string (SOURCE_FILE ("template_semantics.galgas", 410)).objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      inCompiler->printMessage (GALGAS_string ("[\"").add_operation (enumerator_10135.current_key (HERE).getter_string (SOURCE_FILE ("template_semantics.galgas", 411)), inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 411)).add_operation (GALGAS_string ("\"]"), inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 411))  COMMA_SOURCE_FILE ("template_semantics.galgas", 411)) ;
    }
    const enumGalgasBool test_1 = GALGAS_bool (kIsNotEqual, enumerator_10135.current_idx (HERE).getter_sint (SOURCE_FILE ("template_semantics.galgas", 413)).objectCompare (GALGAS_sint ((int32_t) 1L).operator_unary_minus (inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 413)))).boolEnum () ;
    if (kBoolTrue == test_1) {
      inCompiler->printMessage (GALGAS_string ("[").add_operation (enumerator_10135.current_idx (HERE).mAttribute_sint.getter_string (SOURCE_FILE ("template_semantics.galgas", 414)), inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 414)).add_operation (GALGAS_string ("]"), inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 414))  COMMA_SOURCE_FILE ("template_semantics.galgas", 414)) ;
    }
    if (enumerator_10135.hasNextObject ()) {
      inCompiler->printMessage (GALGAS_string ("::")  COMMA_SOURCE_FILE ("template_semantics.galgas", 416)) ;
    }
    enumerator_10135.gotoNextObject () ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                                Routine 'searchField'                                                *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

void routine_searchField (GALGAS_TvarPath inArgument_variable,
                          const GALGAS_TfieldMap constinArgument_inTemplateFieldMap,
                          GALGAS_Ttype & outArgument_variableType,
                          GALGAS_Tvalue & outArgument_variableValue,
                          GALGAS_location & outArgument_variableLocation,
                          C_Compiler * inCompiler
                          COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_variableType.drop () ; // Release 'out' argument
  outArgument_variableValue.drop () ; // Release 'out' argument
  outArgument_variableLocation.drop () ; // Release 'out' argument
  GALGAS_lstring var_field_10593 ;
  GALGAS_lstring var_key_10608 ;
  GALGAS_lsint var_idx_10621 ;
  outArgument_variableLocation = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("template_semantics.galgas", 431)) ;
  {
  inArgument_variable.setter_popFirst (var_field_10593, var_key_10608, var_idx_10621, inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 432)) ;
  }
  constinArgument_inTemplateFieldMap.method_searchKey (var_field_10593, outArgument_variableType, outArgument_variableValue, inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 433)) ;
  const enumGalgasBool test_0 = constinArgument_inTemplateFieldMap.getter_hasKey (var_field_10593.getter_string (SOURCE_FILE ("template_semantics.galgas", 434)) COMMA_SOURCE_FILE ("template_semantics.galgas", 434)).boolEnum () ;
  if (kBoolTrue == test_0) {
    outArgument_variableLocation = constinArgument_inTemplateFieldMap.getter_locationForKey (var_field_10593.getter_string (SOURCE_FILE ("template_semantics.galgas", 435)), inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 435)) ;
  }
  const enumGalgasBool test_1 = GALGAS_bool (kIsNotEqual, var_key_10608.getter_string (SOURCE_FILE ("template_semantics.galgas", 437)).objectCompare (GALGAS_string::makeEmptyString ())).operator_and (GALGAS_bool (kIsEqual, outArgument_variableType.objectCompare (GALGAS_Ttype::constructor_mapType (SOURCE_FILE ("template_semantics.galgas", 437)))) COMMA_SOURCE_FILE ("template_semantics.galgas", 437)).boolEnum () ;
  if (kBoolTrue == test_1) {
    GALGAS_TfieldMap var_mapMap_10987 = outArgument_variableValue.getter_mStructValue (SOURCE_FILE ("template_semantics.galgas", 438)) ;
    var_mapMap_10987.method_searchKey (var_key_10608, outArgument_variableType, outArgument_variableValue, inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 439)) ;
    const enumGalgasBool test_2 = var_mapMap_10987.getter_hasKey (var_key_10608.getter_string (SOURCE_FILE ("template_semantics.galgas", 440)) COMMA_SOURCE_FILE ("template_semantics.galgas", 440)).boolEnum () ;
    if (kBoolTrue == test_2) {
      outArgument_variableLocation = var_mapMap_10987.getter_locationForKey (var_key_10608.getter_string (SOURCE_FILE ("template_semantics.galgas", 441)), inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 441)) ;
    }
  }else if (kBoolFalse == test_1) {
    const enumGalgasBool test_3 = GALGAS_bool (kIsNotEqual, var_idx_10621.getter_sint (SOURCE_FILE ("template_semantics.galgas", 443)).objectCompare (GALGAS_sint ((int32_t) 1L).operator_unary_minus (inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 443)))).operator_and (GALGAS_bool (kIsEqual, outArgument_variableType.objectCompare (GALGAS_Ttype::constructor_listType (SOURCE_FILE ("template_semantics.galgas", 443)))) COMMA_SOURCE_FILE ("template_semantics.galgas", 443)).boolEnum () ;
    if (kBoolTrue == test_3) {
      GALGAS_TfieldMapList var_mapList_11281 = outArgument_variableValue.getter_mMapListValue (SOURCE_FILE ("template_semantics.galgas", 444)) ;
      const enumGalgasBool test_4 = GALGAS_bool (kIsStrictInf, var_idx_10621.mAttribute_sint.getter_uint (inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 445)).objectCompare (var_mapList_11281.getter_length (SOURCE_FILE ("template_semantics.galgas", 445)))).boolEnum () ;
      if (kBoolTrue == test_4) {
        outArgument_variableValue.mAttribute_mStructValue = var_mapList_11281.getter_mMapAtIndex (var_idx_10621.mAttribute_sint.getter_uint (inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 446)), inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 446)) ;
        outArgument_variableType = GALGAS_Ttype::constructor_structType (SOURCE_FILE ("template_semantics.galgas", 447)) ;
      }else if (kBoolFalse == test_4) {
        inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("template_semantics.galgas", 449)), GALGAS_string ("index: ").add_operation (var_idx_10621.getter_sint (SOURCE_FILE ("template_semantics.galgas", 449)).getter_string (SOURCE_FILE ("template_semantics.galgas", 449)), inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 449)).add_operation (GALGAS_string (" >= length:"), inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 449)).add_operation (var_mapList_11281.getter_length (SOURCE_FILE ("template_semantics.galgas", 449)).getter_string (SOURCE_FILE ("template_semantics.galgas", 449)), inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 449))  COMMA_SOURCE_FILE ("template_semantics.galgas", 449)) ;
        outArgument_variableValue.drop () ; // Release error dropped variable
        outArgument_variableType.drop () ; // Release error dropped variable
      }
    }
  }
  const enumGalgasBool test_5 = GALGAS_bool (kIsStrictSup, inArgument_variable.getter_length (SOURCE_FILE ("template_semantics.galgas", 452)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
  if (kBoolTrue == test_5) {
    const enumGalgasBool test_6 = GALGAS_bool (kIsEqual, outArgument_variableType.objectCompare (GALGAS_Ttype::constructor_structType (SOURCE_FILE ("template_semantics.galgas", 453)))).boolEnum () ;
    if (kBoolTrue == test_6) {
      {
      routine_searchField (inArgument_variable, outArgument_variableValue.getter_mStructValue (SOURCE_FILE ("template_semantics.galgas", 454)), outArgument_variableType, outArgument_variableValue, outArgument_variableLocation, inCompiler  COMMA_SOURCE_FILE ("template_semantics.galgas", 454)) ;
      }
    }else if (kBoolFalse == test_6) {
      outArgument_variableLocation = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("template_semantics.galgas", 456)) ;
      GALGAS_location location_7 (var_field_10593.getter_location (HERE)) ; // Implicit use of 'location' getter
      inCompiler->emitSemanticError (location_7, GALGAS_string ("struct variable expected")  COMMA_SOURCE_FILE ("template_semantics.galgas", 457)) ;
      outArgument_variableValue.drop () ; // Release error dropped variable
    }
  }
}


//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                            Routine 'searchFieldIfExists'                                            *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

void routine_searchFieldIfExists (GALGAS_TvarPath inArgument_variable,
                                  const GALGAS_TfieldMap constinArgument_inTemplateFieldMap,
                                  GALGAS_Ttype & outArgument_variableType,
                                  GALGAS_Tvalue & outArgument_variableValue,
                                  GALGAS_bool & outArgument_found,
                                  C_Compiler * inCompiler
                                  COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_variableType.drop () ; // Release 'out' argument
  outArgument_variableValue.drop () ; // Release 'out' argument
  outArgument_found.drop () ; // Release 'out' argument
  GALGAS_lstring var_field_12160 ;
  GALGAS_lstring var_key_12175 ;
  GALGAS_lsint var_idx_12188 ;
  {
  inArgument_variable.setter_popFirst (var_field_12160, var_key_12175, var_idx_12188, inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 473)) ;
  }
  const enumGalgasBool test_0 = constinArgument_inTemplateFieldMap.getter_hasKey (var_field_12160.getter_string (SOURCE_FILE ("template_semantics.galgas", 475)) COMMA_SOURCE_FILE ("template_semantics.galgas", 475)).boolEnum () ;
  if (kBoolTrue == test_0) {
    constinArgument_inTemplateFieldMap.method_searchKey (var_field_12160, outArgument_variableType, outArgument_variableValue, inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 476)) ;
    const enumGalgasBool test_1 = GALGAS_bool (kIsNotEqual, var_key_12175.getter_string (SOURCE_FILE ("template_semantics.galgas", 477)).objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
    if (kBoolTrue == test_1) {
      const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, outArgument_variableType.objectCompare (GALGAS_Ttype::constructor_mapType (SOURCE_FILE ("template_semantics.galgas", 478)))).boolEnum () ;
      if (kBoolTrue == test_2) {
        const enumGalgasBool test_3 = outArgument_variableValue.getter_mStructValue (SOURCE_FILE ("template_semantics.galgas", 479)).getter_hasKey (var_key_12175.getter_string (SOURCE_FILE ("template_semantics.galgas", 479)) COMMA_SOURCE_FILE ("template_semantics.galgas", 479)).boolEnum () ;
        if (kBoolTrue == test_3) {
          outArgument_variableValue.getter_mStructValue (SOURCE_FILE ("template_semantics.galgas", 480)).method_searchKey (var_key_12175, outArgument_variableType, outArgument_variableValue, inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 480)) ;
          outArgument_found = GALGAS_bool (true) ;
        }else if (kBoolFalse == test_3) {
          outArgument_found = GALGAS_bool (false) ;
        }
      }else if (kBoolFalse == test_2) {
        GALGAS_location location_4 (var_key_12175.getter_location (HERE)) ; // Implicit use of 'location' getter
        inCompiler->emitSemanticError (location_4, GALGAS_string ("a key is only used in a map")  COMMA_SOURCE_FILE ("template_semantics.galgas", 486)) ;
        outArgument_found.drop () ; // Release error dropped variable
      }
    }else if (kBoolFalse == test_1) {
      const enumGalgasBool test_5 = GALGAS_bool (kIsNotEqual, var_idx_12188.getter_sint (SOURCE_FILE ("template_semantics.galgas", 488)).objectCompare (GALGAS_sint ((int32_t) 1L).operator_unary_minus (inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 488)))).boolEnum () ;
      if (kBoolTrue == test_5) {
        const enumGalgasBool test_6 = GALGAS_bool (kIsEqual, outArgument_variableType.objectCompare (GALGAS_Ttype::constructor_listType (SOURCE_FILE ("template_semantics.galgas", 489)))).boolEnum () ;
        if (kBoolTrue == test_6) {
          const enumGalgasBool test_7 = GALGAS_bool (kIsStrictInf, var_idx_12188.mAttribute_sint.getter_uint (inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 490)).objectCompare (outArgument_variableValue.getter_mMapListValue (SOURCE_FILE ("template_semantics.galgas", 490)).getter_length (SOURCE_FILE ("template_semantics.galgas", 490)))).boolEnum () ;
          if (kBoolTrue == test_7) {
            GALGAS_TfieldMapList var_mapList_12918 = outArgument_variableValue.getter_mMapListValue (SOURCE_FILE ("template_semantics.galgas", 491)) ;
            outArgument_variableValue.mAttribute_mStructValue = var_mapList_12918.getter_mMapAtIndex (var_idx_12188.mAttribute_sint.getter_uint (inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 492)), inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 492)) ;
            outArgument_variableType = GALGAS_Ttype::constructor_structType (SOURCE_FILE ("template_semantics.galgas", 493)) ;
            outArgument_found = GALGAS_bool (true) ;
          }else if (kBoolFalse == test_7) {
            outArgument_found = GALGAS_bool (false) ;
          }
        }else if (kBoolFalse == test_6) {
          GALGAS_location location_8 (var_idx_12188.getter_location (HERE)) ; // Implicit use of 'location' getter
          inCompiler->emitSemanticError (location_8, GALGAS_string ("an index is only used in a list")  COMMA_SOURCE_FILE ("template_semantics.galgas", 499)) ;
          outArgument_found.drop () ; // Release error dropped variable
        }
      }else if (kBoolFalse == test_5) {
        outArgument_found = GALGAS_bool (true) ;
      }
    }
  }else if (kBoolFalse == test_0) {
    outArgument_variableType = GALGAS_Ttype::constructor_unconstructedType (SOURCE_FILE ("template_semantics.galgas", 505)) ;
    outArgument_variableValue = function_valueWithVoid (inCompiler COMMA_SOURCE_FILE ("template_semantics.galgas", 506)) ;
    outArgument_found = GALGAS_bool (false) ;
  }
  const enumGalgasBool test_9 = GALGAS_bool (kIsStrictSup, inArgument_variable.getter_length (SOURCE_FILE ("template_semantics.galgas", 509)).objectCompare (GALGAS_uint ((uint32_t) 0U))).operator_and (outArgument_found COMMA_SOURCE_FILE ("template_semantics.galgas", 509)).boolEnum () ;
  if (kBoolTrue == test_9) {
    const enumGalgasBool test_10 = GALGAS_bool (kIsEqual, outArgument_variableType.objectCompare (GALGAS_Ttype::constructor_structType (SOURCE_FILE ("template_semantics.galgas", 510)))).boolEnum () ;
    if (kBoolTrue == test_10) {
      {
      routine_searchFieldIfExists (inArgument_variable, outArgument_variableValue.getter_mStructValue (SOURCE_FILE ("template_semantics.galgas", 511)), outArgument_variableType, outArgument_variableValue, outArgument_found, inCompiler  COMMA_SOURCE_FILE ("template_semantics.galgas", 511)) ;
      }
    }else if (kBoolFalse == test_10) {
      outArgument_found = GALGAS_bool (false) ;
    }
  }
}


//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                        Routine 'matchAndOperatorForTemplate'                                        *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

void routine_matchAndOperatorForTemplate (const GALGAS_Ttype constinArgument_inLeftExpressionType,
                                          const GALGAS_Ttype constinArgument_inRightExpressionType,
                                          GALGAS_Ttype & outArgument_outResultType,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_outResultType.drop () ; // Release 'out' argument
  if (constinArgument_inLeftExpressionType.isValid () && constinArgument_inRightExpressionType.isValid ()) {
    if ((constinArgument_inLeftExpressionType.enumValue () == GALGAS_Ttype::kEnum_boolType) && (constinArgument_inRightExpressionType.enumValue () == GALGAS_Ttype::kEnum_boolType)) {
      outArgument_outResultType = constinArgument_inLeftExpressionType ;
    }else if ((constinArgument_inLeftExpressionType.enumValue () == GALGAS_Ttype::kEnum_intType) && (constinArgument_inRightExpressionType.enumValue () == GALGAS_Ttype::kEnum_intType)) {
      outArgument_outResultType = constinArgument_inLeftExpressionType ;
    }else{
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1313)), GALGAS_string ("operand type error : (").add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inLeftExpressionType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1313)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1313)).add_operation (GALGAS_string (" & "), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1313)).add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inRightExpressionType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1314)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1314)).add_operation (GALGAS_string (") is not valid"), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1314))  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1313)) ;
      outArgument_outResultType.drop () ; // Release error dropped variable
    }
  }
}


//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                        Routine 'matchOrOperatorForTemplate'                                         *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

void routine_matchOrOperatorForTemplate (const GALGAS_Ttype constinArgument_inLeftExpressionType,
                                         const GALGAS_Ttype constinArgument_inRightExpressionType,
                                         GALGAS_Ttype & outArgument_outResultType,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_outResultType.drop () ; // Release 'out' argument
  if (constinArgument_inLeftExpressionType.isValid () && constinArgument_inRightExpressionType.isValid ()) {
    if ((constinArgument_inLeftExpressionType.enumValue () == GALGAS_Ttype::kEnum_boolType) && (constinArgument_inRightExpressionType.enumValue () == GALGAS_Ttype::kEnum_boolType)) {
      outArgument_outResultType = constinArgument_inLeftExpressionType ;
    }else if ((constinArgument_inLeftExpressionType.enumValue () == GALGAS_Ttype::kEnum_intType) && (constinArgument_inRightExpressionType.enumValue () == GALGAS_Ttype::kEnum_intType)) {
      outArgument_outResultType = constinArgument_inLeftExpressionType ;
    }else{
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1335)), GALGAS_string ("operand type error : (").add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inLeftExpressionType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1335)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1335)).add_operation (GALGAS_string (" | "), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1335)).add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inRightExpressionType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1336)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1336)).add_operation (GALGAS_string (") is not valid"), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1336))  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1335)) ;
      outArgument_outResultType.drop () ; // Release error dropped variable
    }
  }
}


//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                        Routine 'matchXorOperatorForTemplate'                                        *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

void routine_matchXorOperatorForTemplate (const GALGAS_Ttype constinArgument_inLeftExpressionType,
                                          const GALGAS_Ttype constinArgument_inRightExpressionType,
                                          GALGAS_Ttype & outArgument_outResultType,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_outResultType.drop () ; // Release 'out' argument
  if (constinArgument_inLeftExpressionType.isValid () && constinArgument_inRightExpressionType.isValid ()) {
    if ((constinArgument_inLeftExpressionType.enumValue () == GALGAS_Ttype::kEnum_boolType) && (constinArgument_inRightExpressionType.enumValue () == GALGAS_Ttype::kEnum_boolType)) {
      outArgument_outResultType = constinArgument_inLeftExpressionType ;
    }else if ((constinArgument_inLeftExpressionType.enumValue () == GALGAS_Ttype::kEnum_intType) && (constinArgument_inRightExpressionType.enumValue () == GALGAS_Ttype::kEnum_intType)) {
      outArgument_outResultType = constinArgument_inLeftExpressionType ;
    }else{
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1357)), GALGAS_string ("operand type error : (").add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inLeftExpressionType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1357)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1357)).add_operation (GALGAS_string (" | "), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1357)).add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inRightExpressionType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1358)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1358)).add_operation (GALGAS_string (") is not valid"), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1358))  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1357)) ;
      outArgument_outResultType.drop () ; // Release error dropped variable
    }
  }
}


//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                        Routine 'checkNotOperatorForTemplate'                                        *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

void routine_checkNotOperatorForTemplate (const GALGAS_Ttype constinArgument_inOperandType,
                                          GALGAS_Ttype & outArgument_outResultType,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_outResultType.drop () ; // Release 'out' argument
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, constinArgument_inOperandType.objectCompare (GALGAS_Ttype::constructor_boolType (SOURCE_FILE ("template_expression_parser.galgas", 1372)))).boolEnum () ;
  if (kBoolTrue == test_0) {
    inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1373)), GALGAS_string ("the 'not' operator is not defined for an ").add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inOperandType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1374)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1373)).add_operation (GALGAS_string (" type"), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1374))  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1373)) ;
  }
  outArgument_outResultType = constinArgument_inOperandType ;
}


//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                   Routine 'checkBitComplementOperatorForTemplate'                                   *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

void routine_checkBitComplementOperatorForTemplate (const GALGAS_Ttype constinArgument_inOperandType,
                                                    GALGAS_Ttype & outArgument_outResultType,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_outResultType.drop () ; // Release 'out' argument
  outArgument_outResultType = constinArgument_inOperandType ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, constinArgument_inOperandType.objectCompare (GALGAS_Ttype::constructor_intType (SOURCE_FILE ("template_expression_parser.galgas", 1389)))).boolEnum () ;
  if (kBoolTrue == test_0) {
    inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1390)), GALGAS_string ("the ~ operator is not defined for an ").add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inOperandType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1391)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1390)).add_operation (GALGAS_string (" type"), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1391))  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1390)) ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                     Routine 'comparison_types_checkForTemplate'                                     *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

void routine_comparison_5F_types_5F_checkForTemplate (const GALGAS_Ttype constinArgument_inLeftExpressionType,
                                                      const GALGAS_Ttype constinArgument_inRightExpressionType,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  if (constinArgument_inLeftExpressionType.isValid () && constinArgument_inRightExpressionType.isValid ()) {
    if ((constinArgument_inLeftExpressionType.enumValue () == GALGAS_Ttype::kEnum_boolType) && (constinArgument_inRightExpressionType.enumValue () == GALGAS_Ttype::kEnum_boolType)) {
    }else if ((constinArgument_inLeftExpressionType.enumValue () == GALGAS_Ttype::kEnum_intType) && (constinArgument_inRightExpressionType.enumValue () == GALGAS_Ttype::kEnum_intType)) {
    }else if ((constinArgument_inLeftExpressionType.enumValue () == GALGAS_Ttype::kEnum_stringType) && (constinArgument_inRightExpressionType.enumValue () == GALGAS_Ttype::kEnum_stringType)) {
    }else if ((constinArgument_inLeftExpressionType.enumValue () == GALGAS_Ttype::kEnum_enumType) && (constinArgument_inRightExpressionType.enumValue () == GALGAS_Ttype::kEnum_enumType)) {
    }else{
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1410)), GALGAS_string ("comparison between ").add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inLeftExpressionType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1410)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1410)).add_operation (GALGAS_string (" and "), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1410)).add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inRightExpressionType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1411)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1411)).add_operation (GALGAS_string (" is not valid"), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1411))  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1410)) ;
    }
  }
}


//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                Routine 'magnitude_comparison_types_checkForTemplate'                                *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

void routine_magnitude_5F_comparison_5F_types_5F_checkForTemplate (const GALGAS_Ttype constinArgument_inLeftExpressionType,
                                                                   const GALGAS_Ttype constinArgument_inRightExpressionType,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_UNUSED_LOCATION_ARGS) {
  if (constinArgument_inLeftExpressionType.isValid () && constinArgument_inRightExpressionType.isValid ()) {
    if ((constinArgument_inLeftExpressionType.enumValue () == GALGAS_Ttype::kEnum_boolType) && (constinArgument_inRightExpressionType.enumValue () == GALGAS_Ttype::kEnum_boolType)) {
    }else if ((constinArgument_inLeftExpressionType.enumValue () == GALGAS_Ttype::kEnum_intType) && (constinArgument_inRightExpressionType.enumValue () == GALGAS_Ttype::kEnum_intType)) {
    }else if ((constinArgument_inLeftExpressionType.enumValue () == GALGAS_Ttype::kEnum_stringType) && (constinArgument_inRightExpressionType.enumValue () == GALGAS_Ttype::kEnum_stringType)) {
    }else{
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1429)), GALGAS_string ("comparison between ").add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inLeftExpressionType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1429)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1429)).add_operation (GALGAS_string (" and "), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1429)).add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inRightExpressionType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1430)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1430)).add_operation (GALGAS_string (" is not valid"), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1430))  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1429)) ;
    }
  }
}


//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                     Routine 'left_shift_types_checkForTemplate'                                     *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

void routine_left_5F_shift_5F_types_5F_checkForTemplate (const GALGAS_Ttype constinArgument_inLeftExpressionType,
                                                         const GALGAS_Ttype constinArgument_inRightExpressionType,
                                                         GALGAS_Ttype & outArgument_outResultType,
                                                         C_Compiler * inCompiler
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_outResultType.drop () ; // Release 'out' argument
  if (constinArgument_inLeftExpressionType.isValid () && constinArgument_inRightExpressionType.isValid ()) {
    if ((constinArgument_inLeftExpressionType.enumValue () == GALGAS_Ttype::kEnum_intType) && (constinArgument_inRightExpressionType.enumValue () == GALGAS_Ttype::kEnum_intType)) {
      outArgument_outResultType = constinArgument_inLeftExpressionType ;
    }else{
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1448)), GALGAS_string ("shift between ").add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inLeftExpressionType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1448)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1448)).add_operation (GALGAS_string (" and "), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1448)).add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inRightExpressionType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1449)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1449)).add_operation (GALGAS_string (" is not valid"), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1449))  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1448)) ;
      outArgument_outResultType.drop () ; // Release error dropped variable
    }
  }
}


//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                    Routine 'right_shift_types_checkForTemplate'                                     *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

void routine_right_5F_shift_5F_types_5F_checkForTemplate (const GALGAS_Ttype constinArgument_inLeftExpressionType,
                                                          const GALGAS_Ttype constinArgument_inRightExpressionType,
                                                          GALGAS_Ttype & outArgument_outResultType,
                                                          C_Compiler * inCompiler
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_outResultType.drop () ; // Release 'out' argument
  if (constinArgument_inLeftExpressionType.isValid () && constinArgument_inRightExpressionType.isValid ()) {
    if ((constinArgument_inLeftExpressionType.enumValue () == GALGAS_Ttype::kEnum_intType) && (constinArgument_inRightExpressionType.enumValue () == GALGAS_Ttype::kEnum_intType)) {
      outArgument_outResultType = constinArgument_inLeftExpressionType ;
    }else{
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1464)), GALGAS_string ("shift between ").add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inLeftExpressionType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1464)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1464)).add_operation (GALGAS_string (" and "), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1464)).add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inRightExpressionType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1465)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1465)).add_operation (GALGAS_string (" is not valid"), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1465))  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1464)) ;
      outArgument_outResultType.drop () ; // Release error dropped variable
    }
  }
}


//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                      Routine 'addition_types_checkForTemplate'                                      *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

void routine_addition_5F_types_5F_checkForTemplate (const GALGAS_Ttype constinArgument_inLeftExpressionType,
                                                    const GALGAS_Ttype constinArgument_inRightExpressionType,
                                                    GALGAS_Ttype & outArgument_outResultType,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_outResultType.drop () ; // Release 'out' argument
  if (constinArgument_inLeftExpressionType.isValid () && constinArgument_inRightExpressionType.isValid ()) {
    if ((constinArgument_inLeftExpressionType.enumValue () == GALGAS_Ttype::kEnum_intType) && (constinArgument_inRightExpressionType.enumValue () == GALGAS_Ttype::kEnum_intType)) {
      outArgument_outResultType = constinArgument_inLeftExpressionType ;
    }else{
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1484)), GALGAS_string ("addition between ").add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inLeftExpressionType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1484)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1484)).add_operation (GALGAS_string (" and "), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1484)).add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inRightExpressionType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1485)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1485)).add_operation (GALGAS_string (" is not valid"), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1485))  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1484)) ;
      outArgument_outResultType.drop () ; // Release error dropped variable
    }
  }
}


//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                   Routine 'concatenation_types_checkForTemplate'                                    *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

void routine_concatenation_5F_types_5F_checkForTemplate (const GALGAS_Ttype constinArgument_inLeftExpressionType,
                                                         const GALGAS_Ttype constinArgument_inRightExpressionType,
                                                         GALGAS_Ttype & outArgument_outResultType,
                                                         C_Compiler * inCompiler
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_outResultType.drop () ; // Release 'out' argument
  if (constinArgument_inLeftExpressionType.isValid () && constinArgument_inRightExpressionType.isValid ()) {
    if ((constinArgument_inLeftExpressionType.enumValue () == GALGAS_Ttype::kEnum_stringType) && (constinArgument_inRightExpressionType.enumValue () == GALGAS_Ttype::kEnum_stringType)) {
      outArgument_outResultType = constinArgument_inLeftExpressionType ;
    }else if ((constinArgument_inLeftExpressionType.enumValue () == GALGAS_Ttype::kEnum_listType) && (constinArgument_inRightExpressionType.enumValue () == GALGAS_Ttype::kEnum_listType)) {
      outArgument_outResultType = constinArgument_inLeftExpressionType ;
    }else{
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1506)), GALGAS_string ("addition between ").add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inLeftExpressionType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1506)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1506)).add_operation (GALGAS_string (" and "), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1506)).add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inRightExpressionType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1507)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1507)).add_operation (GALGAS_string (" is not valid"), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1507))  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1506)) ;
      outArgument_outResultType.drop () ; // Release error dropped variable
    }
  }
}


//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                    Routine 'substraction_types_checkForTemplate'                                    *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

void routine_substraction_5F_types_5F_checkForTemplate (const GALGAS_Ttype constinArgument_inLeftExpressionType,
                                                        const GALGAS_Ttype constinArgument_inRightExpressionType,
                                                        GALGAS_Ttype & outArgument_outResultType,
                                                        C_Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_outResultType.drop () ; // Release 'out' argument
  if (constinArgument_inLeftExpressionType.isValid () && constinArgument_inRightExpressionType.isValid ()) {
    if ((constinArgument_inLeftExpressionType.enumValue () == GALGAS_Ttype::kEnum_intType) && (constinArgument_inRightExpressionType.enumValue () == GALGAS_Ttype::kEnum_intType)) {
      outArgument_outResultType = constinArgument_inLeftExpressionType ;
    }else{
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1526)), GALGAS_string ("substraction between ").add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inLeftExpressionType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1526)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1526)).add_operation (GALGAS_string (" and "), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1526)).add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inRightExpressionType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1527)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1527)).add_operation (GALGAS_string (" is not valid"), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1527))  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1526)) ;
      outArgument_outResultType.drop () ; // Release error dropped variable
    }
  }
}


//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                      Routine 'multiply_types_checkForTemplate'                                      *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

void routine_multiply_5F_types_5F_checkForTemplate (const GALGAS_Ttype constinArgument_inLeftExpressionType,
                                                    const GALGAS_Ttype constinArgument_inRightExpressionType,
                                                    GALGAS_Ttype & outArgument_outResultType,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_outResultType.drop () ; // Release 'out' argument
  if (constinArgument_inLeftExpressionType.isValid () && constinArgument_inRightExpressionType.isValid ()) {
    if ((constinArgument_inLeftExpressionType.enumValue () == GALGAS_Ttype::kEnum_intType) && (constinArgument_inRightExpressionType.enumValue () == GALGAS_Ttype::kEnum_intType)) {
      outArgument_outResultType = constinArgument_inLeftExpressionType ;
    }else{
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1546)), GALGAS_string ("multiplication between ").add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inLeftExpressionType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1546)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1546)).add_operation (GALGAS_string (" and "), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1546)).add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inRightExpressionType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1547)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1547)).add_operation (GALGAS_string (" is not valid"), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1547))  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1546)) ;
      outArgument_outResultType.drop () ; // Release error dropped variable
    }
  }
}


//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                       Routine 'divide_types_checkForTemplate'                                       *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

void routine_divide_5F_types_5F_checkForTemplate (const GALGAS_Ttype constinArgument_inLeftExpressionType,
                                                  const GALGAS_Ttype constinArgument_inRightExpressionType,
                                                  GALGAS_Ttype & outArgument_outResultType,
                                                  C_Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_outResultType.drop () ; // Release 'out' argument
  if (constinArgument_inLeftExpressionType.isValid () && constinArgument_inRightExpressionType.isValid ()) {
    if ((constinArgument_inLeftExpressionType.enumValue () == GALGAS_Ttype::kEnum_intType) && (constinArgument_inRightExpressionType.enumValue () == GALGAS_Ttype::kEnum_intType)) {
      outArgument_outResultType = constinArgument_inLeftExpressionType ;
    }else{
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1566)), GALGAS_string ("division between ").add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inLeftExpressionType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1566)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1566)).add_operation (GALGAS_string (" and "), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1566)).add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inRightExpressionType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1567)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1567)).add_operation (GALGAS_string (" is not valid"), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1567))  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1566)) ;
      outArgument_outResultType.drop () ; // Release error dropped variable
    }
  }
}


//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                       Routine 'modulo_types_checkForTemplate'                                       *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

void routine_modulo_5F_types_5F_checkForTemplate (const GALGAS_Ttype constinArgument_inLeftExpressionType,
                                                  const GALGAS_Ttype constinArgument_inRightExpressionType,
                                                  GALGAS_Ttype & outArgument_outResultType,
                                                  C_Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_outResultType.drop () ; // Release 'out' argument
  if (constinArgument_inLeftExpressionType.isValid () && constinArgument_inRightExpressionType.isValid ()) {
    if ((constinArgument_inLeftExpressionType.enumValue () == GALGAS_Ttype::kEnum_intType) && (constinArgument_inRightExpressionType.enumValue () == GALGAS_Ttype::kEnum_intType)) {
      outArgument_outResultType = constinArgument_inLeftExpressionType ;
    }else{
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1586)), GALGAS_string ("modulo between ").add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inLeftExpressionType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1586)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1586)).add_operation (GALGAS_string (" and "), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1586)).add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inRightExpressionType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1587)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1587)).add_operation (GALGAS_string (" is not valid"), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1587))  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1586)) ;
      outArgument_outResultType.drop () ; // Release error dropped variable
    }
  }
}


//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                          Function 'argumentListSignature'                                           *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string function_argumentListSignature (const GALGAS_TexpressionList & constinArgument_inParameterTypeList,
                                              C_Compiler * inCompiler
                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_outResult ; // Returned variable
  result_outResult = GALGAS_string (" this method call has ") ;
  result_outResult.plusAssign_operation(constinArgument_inParameterTypeList.getter_length (SOURCE_FILE ("template_expression_parser.galgas", 1602)).getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1602)).add_operation (GALGAS_string (" argument"), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1602)), inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1602)) ;
  GALGAS_string temp_0 ;
  const enumGalgasBool test_1 = GALGAS_bool (kIsStrictSup, constinArgument_inParameterTypeList.getter_length (SOURCE_FILE ("template_expression_parser.galgas", 1603)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
  if (kBoolTrue == test_1) {
    temp_0 = GALGAS_string ("s") ;
  }else if (kBoolFalse == test_1) {
    temp_0 = GALGAS_string::makeEmptyString () ;
  }
  result_outResult.plusAssign_operation(temp_0, inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1603)) ;
  cEnumerator_TexpressionList enumerator_54206 (constinArgument_inParameterTypeList, kEnumeration_up) ;
  const bool bool_2 = true ;
  if (enumerator_54206.hasCurrentObject () && bool_2) {
    result_outResult.plusAssign_operation(GALGAS_string (": "), inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1605)) ;
    while (enumerator_54206.hasCurrentObject () && bool_2) {
      result_outResult.plusAssign_operation(extensionGetter_messageGoilTemplateType (enumerator_54206.current_mType (HERE), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1606)), inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1606)) ;
      enumerator_54206.gotoNextObject () ;
      if (enumerator_54206.hasCurrentObject () && bool_2) {
        result_outResult.plusAssign_operation(GALGAS_string (", "), inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1607)) ;
      }
    }
  }
//---
  return result_outResult ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                                             *
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_argumentListSignature [2] = {
  & kTypeDescriptor_GALGAS_TexpressionList,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_argumentListSignature (C_Compiler * inCompiler,
                                                                      const cObjectArray & inEffectiveParameterArray,
                                                                      const GALGAS_location & /* §§ inErrorLocation */
                                                                      COMMA_LOCATION_ARGS) {
  const GALGAS_TexpressionList operand0 = GALGAS_TexpressionList::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                                 inCompiler
                                                                                 COMMA_THERE) ;
  return function_argumentListSignature (operand0,
                                         inCompiler
                                         COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_argumentListSignature ("argumentListSignature",
                                                                       functionWithGenericHeader_argumentListSignature,
                                                                       & kTypeDescriptor_GALGAS_string,
                                                                       1,
                                                                       functionArgs_argumentListSignature) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                       Routine 'checkInvocationHasNoArgument'                                        *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

void routine_checkInvocationHasNoArgument (const GALGAS_Ttype constinArgument_inType,
                                           const GALGAS_lstring constinArgument_inMethodName,
                                           const GALGAS_TexpressionList constinArgument_inParameterTypeList,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) {
  const enumGalgasBool test_0 = GALGAS_bool (kIsStrictSup, constinArgument_inParameterTypeList.getter_length (SOURCE_FILE ("template_expression_parser.galgas", 1621)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_location location_1 (constinArgument_inMethodName.getter_location (HERE)) ; // Implicit use of 'location' getter
    inCompiler->emitSemanticError (location_1, GALGAS_string ("calling '").add_operation (constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1622)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1622)).add_operation (GALGAS_string ("' on a "), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1622)).add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1623)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1622)).add_operation (GALGAS_string (" type requires no argument; "), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1623)).add_operation (function_argumentListSignature (constinArgument_inParameterTypeList, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1624)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1623))  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1622)) ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                        Routine 'checkInvocationHasArguments'                                        *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

void routine_checkInvocationHasArguments (const GALGAS_Ttype constinArgument_inType,
                                          const GALGAS_lstring constinArgument_inMethodName,
                                          const GALGAS_TexpressionList constinArgument_inParameterTypeList,
                                          const GALGAS_Ttype constinArgument_inExpectedType,
                                          const GALGAS_uint constinArgument_argsNumber,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_Ttype var_parameterType_55298 ;
  GALGAS_Tvalue joker_55329 ; // Joker input parameter
  constinArgument_inParameterTypeList.method_first (joker_55329, var_parameterType_55298, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1635)) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, constinArgument_inParameterTypeList.getter_length (SOURCE_FILE ("template_expression_parser.galgas", 1636)).objectCompare (constinArgument_argsNumber)).operator_or (GALGAS_bool (kIsNotEqual, var_parameterType_55298.objectCompare (constinArgument_inExpectedType)) COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1636)).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_location location_1 (constinArgument_inMethodName.getter_location (HERE)) ; // Implicit use of 'location' getter
    inCompiler->emitSemanticError (location_1, GALGAS_string ("calling '").add_operation (constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1637)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1637)).add_operation (GALGAS_string ("' on a "), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1637)).add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1638)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1637)).add_operation (GALGAS_string (" type requires "), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1638)).add_operation (constinArgument_argsNumber.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1638)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1638)).add_operation (GALGAS_string (" unsigned argument(s); "), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1638)).add_operation (function_argumentListSignature (constinArgument_inParameterTypeList, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1639)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1638))  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1637)) ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                         Routine 'templateMethodInvocation'                                          *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

void routine_templateMethodInvocation (const GALGAS_Ttype constinArgument_inType,
                                       const GALGAS_Tvalue constinArgument_inValue,
                                       const GALGAS_lstring constinArgument_inMethodName,
                                       GALGAS_TexpressionList inArgument_inParameterTypeList,
                                       GALGAS_Ttype & outArgument_outResultType,
                                       GALGAS_Tvalue & outArgument_outResultValue,
                                       C_Compiler * inCompiler
                                       COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_outResultType.drop () ; // Release 'out' argument
  outArgument_outResultValue.drop () ; // Release 'out' argument
  const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1656)).objectCompare (GALGAS_string ("description"))).boolEnum () ;
  if (kBoolTrue == test_0) {
    {
    routine_checkInvocationHasNoArgument (constinArgument_inType, constinArgument_inMethodName, inArgument_inParameterTypeList, inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1657)) ;
    }
    outArgument_outResultType = GALGAS_Ttype::constructor_stringType (SOURCE_FILE ("template_expression_parser.galgas", 1658)) ;
    outArgument_outResultValue = function_valueWithString (constinArgument_inValue.getter_mDescription (SOURCE_FILE ("template_expression_parser.galgas", 1659)).getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1659)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1659)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1659)) ;
  }else if (kBoolFalse == test_0) {
    switch (constinArgument_inType.enumValue ()) {
    case GALGAS_Ttype::kNotBuilt:
      break ;
    case GALGAS_Ttype::kEnum_boolType:
      {
        const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1663)).objectCompare (GALGAS_string ("trueOrFalse"))).boolEnum () ;
        if (kBoolTrue == test_1) {
          {
          routine_checkInvocationHasNoArgument (constinArgument_inType, constinArgument_inMethodName, inArgument_inParameterTypeList, inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1664)) ;
          }
          outArgument_outResultType = GALGAS_Ttype::constructor_stringType (SOURCE_FILE ("template_expression_parser.galgas", 1665)) ;
          GALGAS_string temp_2 ;
          const enumGalgasBool test_3 = GALGAS_bool (kIsStrictSup, constinArgument_inValue.getter_mBigIntValue (SOURCE_FILE ("template_expression_parser.galgas", 1667)).objectCompare (GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1667)))).boolEnum () ;
          if (kBoolTrue == test_3) {
            temp_2 = GALGAS_string ("true") ;
          }else if (kBoolFalse == test_3) {
            temp_2 = GALGAS_string ("false") ;
          }
          outArgument_outResultValue = function_valueWithString (temp_2, function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1668)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1666)) ;
        }else if (kBoolFalse == test_1) {
          const enumGalgasBool test_4 = GALGAS_bool (kIsEqual, constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1670)).objectCompare (GALGAS_string ("yesOrNo"))).boolEnum () ;
          if (kBoolTrue == test_4) {
            {
            routine_checkInvocationHasNoArgument (constinArgument_inType, constinArgument_inMethodName, inArgument_inParameterTypeList, inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1671)) ;
            }
            outArgument_outResultType = GALGAS_Ttype::constructor_stringType (SOURCE_FILE ("template_expression_parser.galgas", 1672)) ;
            GALGAS_string temp_5 ;
            const enumGalgasBool test_6 = GALGAS_bool (kIsStrictSup, constinArgument_inValue.getter_mBigIntValue (SOURCE_FILE ("template_expression_parser.galgas", 1674)).objectCompare (GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1674)))).boolEnum () ;
            if (kBoolTrue == test_6) {
              temp_5 = GALGAS_string ("yes") ;
            }else if (kBoolFalse == test_6) {
              temp_5 = GALGAS_string ("no") ;
            }
            outArgument_outResultValue = function_valueWithString (temp_5, function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1675)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1673)) ;
          }else if (kBoolFalse == test_4) {
            const enumGalgasBool test_7 = GALGAS_bool (kIsEqual, constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1677)).objectCompare (GALGAS_string ("unsigned"))).boolEnum () ;
            if (kBoolTrue == test_7) {
              {
              routine_checkInvocationHasNoArgument (constinArgument_inType, constinArgument_inMethodName, inArgument_inParameterTypeList, inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1678)) ;
              }
              outArgument_outResultType = GALGAS_Ttype::constructor_intType (SOURCE_FILE ("template_expression_parser.galgas", 1679)) ;
              outArgument_outResultValue = constinArgument_inValue ;
            }else if (kBoolFalse == test_7) {
              GALGAS_location location_8 (constinArgument_inMethodName.getter_location (HERE)) ; // Implicit use of 'location' getter
              inCompiler->emitSemanticError (location_8, GALGAS_string ("the ").add_operation (constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1682)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1682)).add_operation (GALGAS_string (" template method is not defined"), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1682))  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1682)) ;
              outArgument_outResultValue.drop () ; // Release error dropped variable
              outArgument_outResultType.drop () ; // Release error dropped variable
            }
          }
        }
      }
      break ;
    case GALGAS_Ttype::kEnum_intType:
      {
        const enumGalgasBool test_9 = GALGAS_bool (kIsEqual, constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1685)).objectCompare (GALGAS_string ("string"))).boolEnum () ;
        if (kBoolTrue == test_9) {
          {
          routine_checkInvocationHasNoArgument (constinArgument_inType, constinArgument_inMethodName, inArgument_inParameterTypeList, inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1686)) ;
          }
          outArgument_outResultType = GALGAS_Ttype::constructor_stringType (SOURCE_FILE ("template_expression_parser.galgas", 1687)) ;
          outArgument_outResultValue = function_valueWithString (constinArgument_inValue.getter_mBigIntValue (SOURCE_FILE ("template_expression_parser.galgas", 1688)).getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1688)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1688)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1688)) ;
        }else if (kBoolFalse == test_9) {
          const enumGalgasBool test_10 = GALGAS_bool (kIsEqual, constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1689)).objectCompare (GALGAS_string ("setBitAtIndex"))).boolEnum () ;
          if (kBoolTrue == test_10) {
            {
            routine_checkInvocationHasArguments (constinArgument_inType, constinArgument_inMethodName, inArgument_inParameterTypeList, GALGAS_Ttype::constructor_boolType (SOURCE_FILE ("template_expression_parser.galgas", 1690)), GALGAS_uint ((uint32_t) 2U), inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1690)) ;
            }
            GALGAS_Tvalue var_value_58052 ;
            GALGAS_Ttype var_valueType_58070 ;
            {
            inArgument_inParameterTypeList.setter_popFirst (var_value_58052, var_valueType_58070, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1691)) ;
            }
            const enumGalgasBool test_11 = GALGAS_bool (kIsNotEqual, var_valueType_58070.objectCompare (GALGAS_Ttype::constructor_boolType (SOURCE_FILE ("template_expression_parser.galgas", 1692)))).boolEnum () ;
            if (kBoolTrue == test_11) {
              inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1692)), GALGAS_string ("bool expected")  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1692)) ;
            }
            GALGAS_Tvalue var_index_58214 ;
            GALGAS_Ttype var_indexType_58232 ;
            {
            inArgument_inParameterTypeList.setter_popFirst (var_index_58214, var_indexType_58232, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1693)) ;
            }
            const enumGalgasBool test_12 = GALGAS_bool (kIsNotEqual, var_indexType_58232.objectCompare (GALGAS_Ttype::constructor_intType (SOURCE_FILE ("template_expression_parser.galgas", 1694)))).boolEnum () ;
            if (kBoolTrue == test_12) {
              inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1694)), GALGAS_string ("int expected")  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1694)) ;
            }
            outArgument_outResultType = GALGAS_Ttype::constructor_intType (SOURCE_FILE ("template_expression_parser.galgas", 1695)) ;
            GALGAS_bigint var_inInt_58380 = constinArgument_inValue.getter_mBigIntValue (SOURCE_FILE ("template_expression_parser.galgas", 1696)) ;
            {
            GALGAS_bool temp_13 ;
            const enumGalgasBool test_14 = GALGAS_bool (kIsEqual, var_value_58052.getter_mBigIntValue (SOURCE_FILE ("template_expression_parser.galgas", 1697)).objectCompare (GALGAS_bigint ("1", inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1697)))).boolEnum () ;
            if (kBoolTrue == test_14) {
              temp_13 = GALGAS_bool (true) ;
            }else if (kBoolFalse == test_14) {
              temp_13 = GALGAS_bool (false) ;
            }
            var_inInt_58380.setter_setBitAtIndex (temp_13, var_index_58214.getter_mBigIntValue (SOURCE_FILE ("template_expression_parser.galgas", 1697)).getter_uint (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1697)) COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1697)) ;
            }
            outArgument_outResultValue = function_valueWithSigned (var_inInt_58380, function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1698)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1698)) ;
          }else if (kBoolFalse == test_10) {
            const enumGalgasBool test_15 = GALGAS_bool (kIsEqual, constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1699)).objectCompare (GALGAS_string ("bitAtIndex"))).boolEnum () ;
            if (kBoolTrue == test_15) {
              {
              routine_checkInvocationHasArguments (constinArgument_inType, constinArgument_inMethodName, inArgument_inParameterTypeList, GALGAS_Ttype::constructor_intType (SOURCE_FILE ("template_expression_parser.galgas", 1700)), GALGAS_uint ((uint32_t) 1U), inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1700)) ;
              }
              GALGAS_Tvalue var_index_58806 ;
              GALGAS_Ttype var_indexType_58824 ;
              {
              inArgument_inParameterTypeList.setter_popFirst (var_index_58806, var_indexType_58824, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1701)) ;
              }
              const enumGalgasBool test_16 = GALGAS_bool (kIsNotEqual, var_indexType_58824.objectCompare (GALGAS_Ttype::constructor_intType (SOURCE_FILE ("template_expression_parser.galgas", 1702)))).boolEnum () ;
              if (kBoolTrue == test_16) {
                inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1702)), GALGAS_string ("int expected")  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1702)) ;
              }
              outArgument_outResultType = GALGAS_Ttype::constructor_boolType (SOURCE_FILE ("template_expression_parser.galgas", 1703)) ;
              outArgument_outResultValue = function_valueWithBool (constinArgument_inValue.getter_mBigIntValue (SOURCE_FILE ("template_expression_parser.galgas", 1704)).getter_bitAtIndex (var_index_58806.getter_mBigIntValue (SOURCE_FILE ("template_expression_parser.galgas", 1704)).getter_uint (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1704)) COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1704)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1704)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1704)) ;
            }else if (kBoolFalse == test_15) {
              const enumGalgasBool test_17 = GALGAS_bool (kIsEqual, constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1705)).objectCompare (GALGAS_string ("hexString"))).boolEnum () ;
              if (kBoolTrue == test_17) {
                {
                routine_checkInvocationHasNoArgument (constinArgument_inType, constinArgument_inMethodName, inArgument_inParameterTypeList, inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1706)) ;
                }
                outArgument_outResultType = GALGAS_Ttype::constructor_stringType (SOURCE_FILE ("template_expression_parser.galgas", 1707)) ;
                outArgument_outResultValue = function_valueWithString (constinArgument_inValue.getter_mBigIntValue (SOURCE_FILE ("template_expression_parser.galgas", 1708)).getter_uint_36__34_ (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1708)).getter_hexString (SOURCE_FILE ("template_expression_parser.galgas", 1708)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1708)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1708)) ;
              }else if (kBoolFalse == test_17) {
                const enumGalgasBool test_18 = GALGAS_bool (kIsEqual, constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1709)).objectCompare (GALGAS_string ("numberOfBytes"))).operator_or (GALGAS_bool (kIsEqual, constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1709)).objectCompare (GALGAS_string ("signedNumberOfBytes"))) COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1709)).boolEnum () ;
                if (kBoolTrue == test_18) {
                  {
                  routine_checkInvocationHasNoArgument (constinArgument_inType, constinArgument_inMethodName, inArgument_inParameterTypeList, inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1710)) ;
                  }
                  outArgument_outResultType = GALGAS_Ttype::constructor_intType (SOURCE_FILE ("template_expression_parser.galgas", 1711)) ;
                  GALGAS_bigint var_value_59617 = constinArgument_inValue.getter_mBigIntValue (SOURCE_FILE ("template_expression_parser.galgas", 1712)) ;
                  GALGAS_uint var_numberOfBytes_59715 = GALGAS_uint ((uint32_t) 1U) ;
                  const enumGalgasBool test_19 = GALGAS_bool (kIsEqual, constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1715)).objectCompare (GALGAS_string ("signedNumberOfBytes"))).boolEnum () ;
                  if (kBoolTrue == test_19) {
                    var_value_59617 = var_value_59617.multiply_operation (GALGAS_uint ((uint32_t) 2U).getter_bigint (SOURCE_FILE ("template_expression_parser.galgas", 1716)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1716)) ;
                  }
                  GALGAS_uint var_count_59842 = GALGAS_uint ((uint32_t) 0U) ;
                  if (GALGAS_uint ((uint32_t) 4U).isValid ()) {
                    uint32_t variant_59859 = GALGAS_uint ((uint32_t) 4U).uintValue () ;
                    bool loop_59859 = true ;
                    while (loop_59859) {
                      loop_59859 = GALGAS_bool (kIsStrictInf, var_count_59842.objectCompare (GALGAS_uint ((uint32_t) 4U))).isValid () ;
                      if (loop_59859) {
                        loop_59859 = GALGAS_bool (kIsStrictInf, var_count_59842.objectCompare (GALGAS_uint ((uint32_t) 4U))).boolValue () ;
                      }
                      if (loop_59859 && (0 == variant_59859)) {
                        loop_59859 = false ;
                        inCompiler->loopRunTimeVariantError (SOURCE_FILE ("template_expression_parser.galgas", 1719)) ;
                      }
                      if (loop_59859) {
                        variant_59859 -- ;
                        GALGAS_bigint var_maxValue_59917 = GALGAS_bigint ("1", inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1721)).left_shift_operation (var_numberOfBytes_59715.multiply_operation (GALGAS_uint ((uint32_t) 8U), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1721)) COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1721)).substract_operation (GALGAS_bigint ("1", inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1721)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1721)) ;
                        const enumGalgasBool test_20 = GALGAS_bool (kIsStrictInf, var_maxValue_59917.objectCompare (var_value_59617)).boolEnum () ;
                        if (kBoolTrue == test_20) {
                          var_numberOfBytes_59715 = var_numberOfBytes_59715.multiply_operation (GALGAS_uint ((uint32_t) 2U), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1723)) ;
                        }
                        var_count_59842.increment_operation (inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1725)) ;
                      }
                    }
                  }
                  outArgument_outResultValue = function_valueWithUnsigned (var_numberOfBytes_59715.getter_bigint (SOURCE_FILE ("template_expression_parser.galgas", 1727)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1727)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1727)) ;
                }else if (kBoolFalse == test_18) {
                  const enumGalgasBool test_21 = GALGAS_bool (kIsEqual, constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1728)).objectCompare (GALGAS_string ("numberOfBits"))).operator_or (GALGAS_bool (kIsEqual, constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1728)).objectCompare (GALGAS_string ("signedNumberOfBits"))) COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1728)).boolEnum () ;
                  if (kBoolTrue == test_21) {
                    {
                    routine_checkInvocationHasNoArgument (constinArgument_inType, constinArgument_inMethodName, inArgument_inParameterTypeList, inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1729)) ;
                    }
                    outArgument_outResultType = GALGAS_Ttype::constructor_intType (SOURCE_FILE ("template_expression_parser.galgas", 1730)) ;
                    GALGAS_bigint var_value_60414 = constinArgument_inValue.getter_mBigIntValue (SOURCE_FILE ("template_expression_parser.galgas", 1731)) ;
                    const enumGalgasBool test_22 = GALGAS_bool (kIsEqual, constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1732)).objectCompare (GALGAS_string ("signedNumberOfBits"))).boolEnum () ;
                    if (kBoolTrue == test_22) {
                      var_value_60414 = var_value_60414.multiply_operation (GALGAS_uint ((uint32_t) 2U).getter_bigint (SOURCE_FILE ("template_expression_parser.galgas", 1733)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1733)) ;
                    }
                    GALGAS_sint_36__34_ var_numberOfBits_60614 = GALGAS_sint_36__34_ ((int64_t) 0LL) ;
                    if (GALGAS_uint ((uint32_t) 64U).isValid ()) {
                      uint32_t variant_60633 = GALGAS_uint ((uint32_t) 64U).uintValue () ;
                      bool loop_60633 = true ;
                      while (loop_60633) {
                        loop_60633 = GALGAS_bool (kIsNotEqual, var_value_60414.objectCompare (GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1738)))).isValid () ;
                        if (loop_60633) {
                          loop_60633 = GALGAS_bool (kIsNotEqual, var_value_60414.objectCompare (GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1738)))).boolValue () ;
                        }
                        if (loop_60633 && (0 == variant_60633)) {
                          loop_60633 = false ;
                          inCompiler->loopRunTimeVariantError (SOURCE_FILE ("template_expression_parser.galgas", 1737)) ;
                        }
                        if (loop_60633) {
                          variant_60633 -- ;
                          var_numberOfBits_60614.increment_operation (inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1739)) ;
                          var_value_60414 = var_value_60414.right_shift_operation (GALGAS_uint ((uint32_t) 1U) COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1740)) ;
                        }
                      }
                    }
                    outArgument_outResultValue = function_valueWithSigned (var_numberOfBits_60614.getter_bigint (SOURCE_FILE ("template_expression_parser.galgas", 1742)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1742)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1742)) ;
                  }else if (kBoolFalse == test_21) {
                    GALGAS_location location_23 (constinArgument_inMethodName.getter_location (HERE)) ; // Implicit use of 'location' getter
                    inCompiler->emitSemanticError (location_23, GALGAS_string ("the ").add_operation (constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1744)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1744)).add_operation (GALGAS_string (" template method is not defined for "), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1744)).add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1744)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1744))  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1744)) ;
                    outArgument_outResultValue.drop () ; // Release error dropped variable
                    outArgument_outResultType.drop () ; // Release error dropped variable
                  }
                }
              }
            }
          }
        }
      }
      break ;
    case GALGAS_Ttype::kEnum_stringType:
      {
        const enumGalgasBool test_24 = GALGAS_bool (kIsEqual, constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1747)).objectCompare (GALGAS_string ("HTMLRepresentation"))).boolEnum () ;
        if (kBoolTrue == test_24) {
          {
          routine_checkInvocationHasNoArgument (constinArgument_inType, constinArgument_inMethodName, inArgument_inParameterTypeList, inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1748)) ;
          }
          outArgument_outResultType = GALGAS_Ttype::constructor_stringType (SOURCE_FILE ("template_expression_parser.galgas", 1749)) ;
          outArgument_outResultValue = function_valueWithString (constinArgument_inValue.getter_mStringValue (SOURCE_FILE ("template_expression_parser.galgas", 1750)).getter_HTMLRepresentation (SOURCE_FILE ("template_expression_parser.galgas", 1750)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1750)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1750)) ;
        }else if (kBoolFalse == test_24) {
          const enumGalgasBool test_25 = GALGAS_bool (kIsEqual, constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1751)).objectCompare (GALGAS_string ("identifierRepresentation"))).boolEnum () ;
          if (kBoolTrue == test_25) {
            {
            routine_checkInvocationHasNoArgument (constinArgument_inType, constinArgument_inMethodName, inArgument_inParameterTypeList, inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1752)) ;
            }
            outArgument_outResultType = GALGAS_Ttype::constructor_stringType (SOURCE_FILE ("template_expression_parser.galgas", 1753)) ;
            outArgument_outResultValue = function_valueWithString (constinArgument_inValue.getter_mStringValue (SOURCE_FILE ("template_expression_parser.galgas", 1754)).getter_identifierRepresentation (SOURCE_FILE ("template_expression_parser.galgas", 1754)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1754)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1754)) ;
          }else if (kBoolFalse == test_25) {
            const enumGalgasBool test_26 = GALGAS_bool (kIsEqual, constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1755)).objectCompare (GALGAS_string ("fileExists"))).boolEnum () ;
            if (kBoolTrue == test_26) {
              {
              routine_checkInvocationHasNoArgument (constinArgument_inType, constinArgument_inMethodName, inArgument_inParameterTypeList, inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1756)) ;
              }
              outArgument_outResultType = GALGAS_Ttype::constructor_boolType (SOURCE_FILE ("template_expression_parser.galgas", 1757)) ;
              outArgument_outResultValue = function_valueWithBool (constinArgument_inValue.getter_mStringValue (SOURCE_FILE ("template_expression_parser.galgas", 1758)).getter_fileExists (SOURCE_FILE ("template_expression_parser.galgas", 1758)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1758)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1758)) ;
            }else if (kBoolFalse == test_26) {
              const enumGalgasBool test_27 = GALGAS_bool (kIsEqual, constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1759)).objectCompare (GALGAS_string ("lowercaseString"))).boolEnum () ;
              if (kBoolTrue == test_27) {
                {
                routine_checkInvocationHasNoArgument (constinArgument_inType, constinArgument_inMethodName, inArgument_inParameterTypeList, inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1760)) ;
                }
                outArgument_outResultType = GALGAS_Ttype::constructor_stringType (SOURCE_FILE ("template_expression_parser.galgas", 1761)) ;
                outArgument_outResultValue = function_valueWithString (constinArgument_inValue.getter_mStringValue (SOURCE_FILE ("template_expression_parser.galgas", 1762)).getter_lowercaseString (SOURCE_FILE ("template_expression_parser.galgas", 1762)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1762)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1762)) ;
              }else if (kBoolFalse == test_27) {
                const enumGalgasBool test_28 = GALGAS_bool (kIsEqual, constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1763)).objectCompare (GALGAS_string ("length"))).boolEnum () ;
                if (kBoolTrue == test_28) {
                  {
                  routine_checkInvocationHasNoArgument (constinArgument_inType, constinArgument_inMethodName, inArgument_inParameterTypeList, inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1764)) ;
                  }
                  outArgument_outResultType = GALGAS_Ttype::constructor_intType (SOURCE_FILE ("template_expression_parser.galgas", 1765)) ;
                  outArgument_outResultValue = function_valueWithUnsigned (constinArgument_inValue.getter_mStringValue (SOURCE_FILE ("template_expression_parser.galgas", 1766)).getter_length (SOURCE_FILE ("template_expression_parser.galgas", 1766)).getter_bigint (SOURCE_FILE ("template_expression_parser.galgas", 1766)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1766)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1766)) ;
                }else if (kBoolFalse == test_28) {
                  const enumGalgasBool test_29 = GALGAS_bool (kIsEqual, constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1767)).objectCompare (GALGAS_string ("stringByCapitalizingFirstCharacter"))).boolEnum () ;
                  if (kBoolTrue == test_29) {
                    {
                    routine_checkInvocationHasNoArgument (constinArgument_inType, constinArgument_inMethodName, inArgument_inParameterTypeList, inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1768)) ;
                    }
                    outArgument_outResultType = GALGAS_Ttype::constructor_stringType (SOURCE_FILE ("template_expression_parser.galgas", 1769)) ;
                    outArgument_outResultValue = function_valueWithString (constinArgument_inValue.getter_mStringValue (SOURCE_FILE ("template_expression_parser.galgas", 1770)).getter_stringByCapitalizingFirstCharacter (SOURCE_FILE ("template_expression_parser.galgas", 1770)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1770)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1770)) ;
                  }else if (kBoolFalse == test_29) {
                    const enumGalgasBool test_30 = GALGAS_bool (kIsEqual, constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1771)).objectCompare (GALGAS_string ("uppercaseString"))).boolEnum () ;
                    if (kBoolTrue == test_30) {
                      {
                      routine_checkInvocationHasNoArgument (constinArgument_inType, constinArgument_inMethodName, inArgument_inParameterTypeList, inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1772)) ;
                      }
                      outArgument_outResultType = GALGAS_Ttype::constructor_stringType (SOURCE_FILE ("template_expression_parser.galgas", 1773)) ;
                      outArgument_outResultValue = function_valueWithString (constinArgument_inValue.getter_mStringValue (SOURCE_FILE ("template_expression_parser.galgas", 1774)).getter_uppercaseString (SOURCE_FILE ("template_expression_parser.galgas", 1774)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1774)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1774)) ;
                    }else if (kBoolFalse == test_30) {
                      const enumGalgasBool test_31 = GALGAS_bool (kIsEqual, constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1775)).objectCompare (GALGAS_string ("unsigned"))).boolEnum () ;
                      if (kBoolTrue == test_31) {
                        {
                        routine_checkInvocationHasNoArgument (constinArgument_inType, constinArgument_inMethodName, inArgument_inParameterTypeList, inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1776)) ;
                        }
                        outArgument_outResultType = GALGAS_Ttype::constructor_intType (SOURCE_FILE ("template_expression_parser.galgas", 1777)) ;
                        outArgument_outResultValue = function_valueWithUnsigned (constinArgument_inValue.getter_mStringValue (SOURCE_FILE ("template_expression_parser.galgas", 1778)).getter_decimalUnsignedNumber (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1778)).getter_bigint (SOURCE_FILE ("template_expression_parser.galgas", 1778)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1778)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1778)) ;
                      }else if (kBoolFalse == test_31) {
                        const enumGalgasBool test_32 = GALGAS_bool (kIsEqual, constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1779)).objectCompare (GALGAS_string ("leftSubString"))).boolEnum () ;
                        if (kBoolTrue == test_32) {
                          {
                          routine_checkInvocationHasArguments (constinArgument_inType, constinArgument_inMethodName, inArgument_inParameterTypeList, GALGAS_Ttype::constructor_intType (SOURCE_FILE ("template_expression_parser.galgas", 1780)), GALGAS_uint ((uint32_t) 1U), inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1780)) ;
                          }
                          GALGAS_Tvalue var_parameter_63534 ;
                          GALGAS_Ttype joker_63582 ; // Joker input parameter
                          inArgument_inParameterTypeList.method_first (var_parameter_63534, joker_63582, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1782)) ;
                          outArgument_outResultType = GALGAS_Ttype::constructor_stringType (SOURCE_FILE ("template_expression_parser.galgas", 1783)) ;
                          outArgument_outResultValue = function_valueWithString (constinArgument_inValue.getter_mStringValue (SOURCE_FILE ("template_expression_parser.galgas", 1784)).getter_leftSubString (var_parameter_63534.getter_mBigIntValue (SOURCE_FILE ("template_expression_parser.galgas", 1784)).getter_uint (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1784)) COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1784)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1784)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1784)) ;
                        }else if (kBoolFalse == test_32) {
                          const enumGalgasBool test_33 = GALGAS_bool (kIsEqual, constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1785)).objectCompare (GALGAS_string ("rightSubString"))).boolEnum () ;
                          if (kBoolTrue == test_33) {
                            {
                            routine_checkInvocationHasArguments (constinArgument_inType, constinArgument_inMethodName, inArgument_inParameterTypeList, GALGAS_Ttype::constructor_intType (SOURCE_FILE ("template_expression_parser.galgas", 1786)), GALGAS_uint ((uint32_t) 1U), inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1786)) ;
                            }
                            GALGAS_Tvalue var_parameter_63946 ;
                            GALGAS_Ttype joker_63994 ; // Joker input parameter
                            inArgument_inParameterTypeList.method_first (var_parameter_63946, joker_63994, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1788)) ;
                            outArgument_outResultType = GALGAS_Ttype::constructor_stringType (SOURCE_FILE ("template_expression_parser.galgas", 1789)) ;
                            outArgument_outResultValue = function_valueWithString (constinArgument_inValue.getter_mStringValue (SOURCE_FILE ("template_expression_parser.galgas", 1790)).getter_rightSubString (var_parameter_63946.getter_mBigIntValue (SOURCE_FILE ("template_expression_parser.galgas", 1790)).getter_uint (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1790)) COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1790)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1790)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1790)) ;
                          }else if (kBoolFalse == test_33) {
                            const enumGalgasBool test_34 = GALGAS_bool (kIsEqual, constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1791)).objectCompare (GALGAS_string ("subString"))).boolEnum () ;
                            if (kBoolTrue == test_34) {
                              {
                              routine_checkInvocationHasArguments (constinArgument_inType, constinArgument_inMethodName, inArgument_inParameterTypeList, GALGAS_Ttype::constructor_intType (SOURCE_FILE ("template_expression_parser.galgas", 1792)), GALGAS_uint ((uint32_t) 2U), inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1792)) ;
                              }
                              GALGAS_Tvalue var_start_64350 = inArgument_inParameterTypeList.getter_mValueAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1793)) ;
                              GALGAS_Tvalue var_length_64414 = inArgument_inParameterTypeList.getter_mValueAtIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1794)) ;
                              outArgument_outResultType = GALGAS_Ttype::constructor_stringType (SOURCE_FILE ("template_expression_parser.galgas", 1797)) ;
                              outArgument_outResultValue = function_valueWithString (constinArgument_inValue.getter_mStringValue (SOURCE_FILE ("template_expression_parser.galgas", 1798)).getter_subString (var_start_64350.getter_mBigIntValue (SOURCE_FILE ("template_expression_parser.galgas", 1798)).getter_uint (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1798)), var_length_64414.getter_mBigIntValue (SOURCE_FILE ("template_expression_parser.galgas", 1798)).getter_uint (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1798)) COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1798)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1798)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1798)) ;
                            }else if (kBoolFalse == test_34) {
                              const enumGalgasBool test_35 = GALGAS_bool (kIsEqual, constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1799)).objectCompare (GALGAS_string ("reversedString"))).boolEnum () ;
                              if (kBoolTrue == test_35) {
                                {
                                routine_checkInvocationHasNoArgument (constinArgument_inType, constinArgument_inMethodName, inArgument_inParameterTypeList, inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1800)) ;
                                }
                                outArgument_outResultType = GALGAS_Ttype::constructor_stringType (SOURCE_FILE ("template_expression_parser.galgas", 1801)) ;
                                outArgument_outResultValue = function_valueWithString (constinArgument_inValue.getter_mStringValue (SOURCE_FILE ("template_expression_parser.galgas", 1802)).getter_reversedString (SOURCE_FILE ("template_expression_parser.galgas", 1802)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1802)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1802)) ;
                              }else if (kBoolFalse == test_35) {
                                const enumGalgasBool test_36 = GALGAS_bool (kIsEqual, constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1803)).objectCompare (GALGAS_string ("componentsSeparatedByString"))).boolEnum () ;
                                if (kBoolTrue == test_36) {
                                  {
                                  routine_checkInvocationHasArguments (constinArgument_inType, constinArgument_inMethodName, inArgument_inParameterTypeList, GALGAS_Ttype::constructor_stringType (SOURCE_FILE ("template_expression_parser.galgas", 1804)), GALGAS_uint ((uint32_t) 1U), inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1804)) ;
                                  }
                                  GALGAS_Tvalue var_separator_65181 ;
                                  GALGAS_Ttype joker_65229 ; // Joker input parameter
                                  inArgument_inParameterTypeList.method_first (var_separator_65181, joker_65229, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1806)) ;
                                  GALGAS_stringlist var_stringlist_65262 = constinArgument_inValue.getter_mStringValue (SOURCE_FILE ("template_expression_parser.galgas", 1807)).getter_componentsSeparatedByString (var_separator_65181.getter_mStringValue (SOURCE_FILE ("template_expression_parser.galgas", 1807)) COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1807)) ;
                                  GALGAS_TfieldMapList var_result_65362 = GALGAS_TfieldMapList::constructor_emptyList (SOURCE_FILE ("template_expression_parser.galgas", 1808)) ;
                                  cEnumerator_stringlist enumerator_65420 (var_stringlist_65262, kEnumeration_up) ;
                                  while (enumerator_65420.hasCurrentObject ()) {
                                    GALGAS_TfieldMap var_item_65442 = GALGAS_TfieldMap::constructor_emptyMap (SOURCE_FILE ("template_expression_parser.galgas", 1810)) ;
                                    {
                                    routine_addStringValue (var_item_65442, function_lstringWith (GALGAS_string ("VALUE"), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1811)), enumerator_65420.current_mValue (HERE), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1811)), inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1811)) ;
                                    }
                                    var_result_65362.addAssign_operation (var_item_65442  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1812)) ;
                                    enumerator_65420.gotoNextObject () ;
                                  }
                                  outArgument_outResultType = GALGAS_Ttype::constructor_listType (SOURCE_FILE ("template_expression_parser.galgas", 1814)) ;
                                  outArgument_outResultValue = function_valueWithList (var_result_65362, function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1815)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1815)) ;
                                }else if (kBoolFalse == test_36) {
                                  const enumGalgasBool test_37 = GALGAS_bool (kIsEqual, constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1816)).objectCompare (GALGAS_string ("interpretEscape"))).boolEnum () ;
                                  if (kBoolTrue == test_37) {
                                    {
                                    routine_checkInvocationHasNoArgument (constinArgument_inType, constinArgument_inMethodName, inArgument_inParameterTypeList, inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1817)) ;
                                    }
                                    outArgument_outResultType = GALGAS_Ttype::constructor_stringType (SOURCE_FILE ("template_expression_parser.galgas", 1818)) ;
                                    outArgument_outResultValue = constinArgument_inValue ;
                                  }else if (kBoolFalse == test_37) {
                                    const enumGalgasBool test_38 = GALGAS_bool (kIsEqual, constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1821)).objectCompare (GALGAS_string ("columnPrefixedBy"))).boolEnum () ;
                                    if (kBoolTrue == test_38) {
                                      {
                                      routine_checkInvocationHasArguments (constinArgument_inType, constinArgument_inMethodName, inArgument_inParameterTypeList, GALGAS_Ttype::constructor_stringType (SOURCE_FILE ("template_expression_parser.galgas", 1822)), GALGAS_uint ((uint32_t) 1U), inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1822)) ;
                                      }
                                      GALGAS_Tvalue var_separator_66232 ;
                                      GALGAS_Ttype joker_66280 ; // Joker input parameter
                                      inArgument_inParameterTypeList.method_first (var_separator_66232, joker_66280, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1824)) ;
                                      outArgument_outResultType = GALGAS_Ttype::constructor_stringType (SOURCE_FILE ("template_expression_parser.galgas", 1825)) ;
                                      outArgument_outResultValue = function_valueWithString (var_separator_66232.getter_mStringValue (SOURCE_FILE ("template_expression_parser.galgas", 1826)).add_operation (constinArgument_inValue.getter_mStringValue (SOURCE_FILE ("template_expression_parser.galgas", 1826)).getter_stringByReplacingStringByString (GALGAS_string ("\n"), GALGAS_string ("\n").add_operation (var_separator_66232.getter_mStringValue (SOURCE_FILE ("template_expression_parser.galgas", 1826)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1826)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1826)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1826)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1826)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1826)) ;
                                    }else if (kBoolFalse == test_38) {
                                      const enumGalgasBool test_39 = GALGAS_bool (kIsEqual, constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1827)).objectCompare (GALGAS_string ("wrap"))).boolEnum () ;
                                      if (kBoolTrue == test_39) {
                                        {
                                        routine_checkInvocationHasArguments (constinArgument_inType, constinArgument_inMethodName, inArgument_inParameterTypeList, GALGAS_Ttype::constructor_intType (SOURCE_FILE ("template_expression_parser.galgas", 1828)), GALGAS_uint ((uint32_t) 2U), inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1828)) ;
                                        }
                                        GALGAS_Tvalue var_width_66782 ;
                                        {
                                        GALGAS_Ttype joker_66831 ; // Joker input parameter
                                        inArgument_inParameterTypeList.setter_popFirst (var_width_66782, joker_66831, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1831)) ;
                                        }
                                        GALGAS_Tvalue var_shift_66855 ;
                                        {
                                        GALGAS_Ttype joker_66904 ; // Joker input parameter
                                        inArgument_inParameterTypeList.setter_popFirst (var_shift_66855, joker_66904, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1833)) ;
                                        }
                                        GALGAS_string var_stringshift_66934 = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), var_shift_66855.getter_mBigIntValue (SOURCE_FILE ("template_expression_parser.galgas", 1834)).getter_uint (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1834))  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1834)) ;
                                        GALGAS_string var_result_67036 = constinArgument_inValue.getter_mStringValue (SOURCE_FILE ("template_expression_parser.galgas", 1835)) ;
                                        GALGAS_stringlist var_paragraph_67437 = var_result_67036.getter_componentsSeparatedByString (GALGAS_string ("\n") COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1844)) ;
                                        GALGAS_stringlist var_resultParagraph_67510 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("template_expression_parser.galgas", 1845)) ;
                                        cEnumerator_stringlist enumerator_67570 (var_paragraph_67437, kEnumeration_up) ;
                                        while (enumerator_67570.hasCurrentObject ()) {
                                          GALGAS_stringlist var_parts_67601 = enumerator_67570.current_mValue (HERE).getter_componentsSeparatedByString (GALGAS_string (" ") COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1847)) ;
                                          GALGAS_bigint var_linewidth_67678 = GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1848)) ;
                                          var_result_67036 = GALGAS_string::makeEmptyString () ;
                                          cEnumerator_stringlist enumerator_67739 (var_parts_67601, kEnumeration_up) ;
                                          while (enumerator_67739.hasCurrentObject ()) {
                                            const enumGalgasBool test_40 = GALGAS_bool (kIsNotEqual, enumerator_67739.current_mValue (HERE).objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
                                            if (kBoolTrue == test_40) {
                                              const enumGalgasBool test_41 = GALGAS_bool (kIsStrictSup, var_linewidth_67678.add_operation (enumerator_67739.current_mValue (HERE).getter_length (SOURCE_FILE ("template_expression_parser.galgas", 1852)).getter_bigint (SOURCE_FILE ("template_expression_parser.galgas", 1852)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1852)).objectCompare (var_width_66782.getter_mBigIntValue (SOURCE_FILE ("template_expression_parser.galgas", 1852)))).boolEnum () ;
                                              if (kBoolTrue == test_41) {
                                                var_result_67036.plusAssign_operation(GALGAS_string ("\n").add_operation (var_stringshift_66934, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1853)), inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1853)) ;
                                                var_linewidth_67678 = var_shift_66855.getter_mBigIntValue (SOURCE_FILE ("template_expression_parser.galgas", 1854)) ;
                                              }
                                              var_linewidth_67678 = var_linewidth_67678.add_operation (enumerator_67739.current_mValue (HERE).getter_length (SOURCE_FILE ("template_expression_parser.galgas", 1856)).getter_bigint (SOURCE_FILE ("template_expression_parser.galgas", 1856)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1856)).add_operation (GALGAS_sint_36__34_ ((int64_t) 1LL).getter_bigint (SOURCE_FILE ("template_expression_parser.galgas", 1856)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1856)) ;
                                              var_result_67036.plusAssign_operation(enumerator_67739.current_mValue (HERE).add_operation (GALGAS_string (" "), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1857)), inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1857)) ;
                                            }
                                            enumerator_67739.gotoNextObject () ;
                                          }
                                          var_resultParagraph_67510.addAssign_operation (var_result_67036  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1860)) ;
                                          enumerator_67570.gotoNextObject () ;
                                        }
                                        outArgument_outResultType = GALGAS_Ttype::constructor_stringType (SOURCE_FILE ("template_expression_parser.galgas", 1862)) ;
                                        outArgument_outResultValue = function_valueWithString (GALGAS_string::constructor_componentsJoinedByString (var_resultParagraph_67510, GALGAS_string ("\n")  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1863)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1863)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1863)) ;
                                      }else if (kBoolFalse == test_39) {
                                        const enumGalgasBool test_42 = GALGAS_bool (kIsEqual, constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1864)).objectCompare (GALGAS_string ("substringExists"))).boolEnum () ;
                                        if (kBoolTrue == test_42) {
                                          {
                                          routine_checkInvocationHasArguments (constinArgument_inType, constinArgument_inMethodName, inArgument_inParameterTypeList, GALGAS_Ttype::constructor_stringType (SOURCE_FILE ("template_expression_parser.galgas", 1865)), GALGAS_uint ((uint32_t) 1U), inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1865)) ;
                                          }
                                          GALGAS_Tvalue var_subString_68547 ;
                                          {
                                          GALGAS_Ttype joker_68549 ; // Joker input parameter
                                          inArgument_inParameterTypeList.setter_popFirst (var_subString_68547, joker_68549, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1866)) ;
                                          }
                                          GALGAS_uint var_start_68571 = GALGAS_uint ((uint32_t) 0U) ;
                                          GALGAS_uint var_stop_68594 = constinArgument_inValue.getter_mStringValue (SOURCE_FILE ("template_expression_parser.galgas", 1868)).getter_length (SOURCE_FILE ("template_expression_parser.galgas", 1868)).substract_operation (var_subString_68547.getter_mStringValue (SOURCE_FILE ("template_expression_parser.galgas", 1868)).getter_length (SOURCE_FILE ("template_expression_parser.galgas", 1868)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1868)) ;
                                          GALGAS_bool var_exists_68685 = GALGAS_bool (false) ;
                                          if (constinArgument_inValue.getter_mStringValue (SOURCE_FILE ("template_expression_parser.galgas", 1870)).getter_length (SOURCE_FILE ("template_expression_parser.galgas", 1870)).isValid ()) {
                                            uint32_t variant_68707 = constinArgument_inValue.getter_mStringValue (SOURCE_FILE ("template_expression_parser.galgas", 1870)).getter_length (SOURCE_FILE ("template_expression_parser.galgas", 1870)).uintValue () ;
                                            bool loop_68707 = true ;
                                            while (loop_68707) {
                                              loop_68707 = GALGAS_bool (kIsInfOrEqual, var_start_68571.objectCompare (var_stop_68594)).isValid () ;
                                              if (loop_68707) {
                                                loop_68707 = GALGAS_bool (kIsInfOrEqual, var_start_68571.objectCompare (var_stop_68594)).boolValue () ;
                                              }
                                              if (loop_68707 && (0 == variant_68707)) {
                                                loop_68707 = false ;
                                                inCompiler->loopRunTimeVariantError (SOURCE_FILE ("template_expression_parser.galgas", 1870)) ;
                                              }
                                              if (loop_68707) {
                                                variant_68707 -- ;
                                                const enumGalgasBool test_43 = GALGAS_bool (kIsEqual, constinArgument_inValue.getter_mStringValue (SOURCE_FILE ("template_expression_parser.galgas", 1872)).getter_subString (var_start_68571, var_subString_68547.getter_mStringValue (SOURCE_FILE ("template_expression_parser.galgas", 1872)).getter_length (SOURCE_FILE ("template_expression_parser.galgas", 1872)) COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1872)).objectCompare (var_subString_68547.getter_mStringValue (SOURCE_FILE ("template_expression_parser.galgas", 1872)))).boolEnum () ;
                                                if (kBoolTrue == test_43) {
                                                  var_exists_68685 = GALGAS_bool (true) ;
                                                }
                                                var_start_68571.increment_operation (inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1875)) ;
                                              }
                                            }
                                          }
                                          outArgument_outResultType = GALGAS_Ttype::constructor_boolType (SOURCE_FILE ("template_expression_parser.galgas", 1877)) ;
                                          outArgument_outResultValue = function_valueWithBool (var_exists_68685, function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1878)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1878)) ;
                                        }else if (kBoolFalse == test_42) {
                                          GALGAS_location location_44 (constinArgument_inMethodName.getter_location (HERE)) ; // Implicit use of 'location' getter
                                          inCompiler->emitSemanticError (location_44, GALGAS_string ("the ").add_operation (constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1880)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1880)).add_operation (GALGAS_string (" template method is not defined for "), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1880)).add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1880)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1880))  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1880)) ;
                                          outArgument_outResultValue.drop () ; // Release error dropped variable
                                          outArgument_outResultType.drop () ; // Release error dropped variable
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      break ;
    case GALGAS_Ttype::kEnum_floatType:
      {
        GALGAS_location location_45 (constinArgument_inMethodName.getter_location (HERE)) ; // Implicit use of 'location' getter
        inCompiler->emitSemanticError (location_45, GALGAS_string ("the ").add_operation (constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1883)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1883)).add_operation (GALGAS_string (" template method is not defined for "), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1883)).add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1883)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1883))  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1883)) ;
        outArgument_outResultValue.drop () ; // Release error dropped variable
        outArgument_outResultType.drop () ; // Release error dropped variable
      }
      break ;
    case GALGAS_Ttype::kEnum_listType:
      {
        const enumGalgasBool test_46 = GALGAS_bool (kIsEqual, constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1885)).objectCompare (GALGAS_string ("length"))).boolEnum () ;
        if (kBoolTrue == test_46) {
          {
          routine_checkInvocationHasNoArgument (constinArgument_inType, constinArgument_inMethodName, inArgument_inParameterTypeList, inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1886)) ;
          }
          outArgument_outResultType = GALGAS_Ttype::constructor_intType (SOURCE_FILE ("template_expression_parser.galgas", 1887)) ;
          outArgument_outResultValue = function_valueWithUnsigned (constinArgument_inValue.getter_mMapListValue (SOURCE_FILE ("template_expression_parser.galgas", 1888)).getter_length (SOURCE_FILE ("template_expression_parser.galgas", 1888)).getter_bigint (SOURCE_FILE ("template_expression_parser.galgas", 1888)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1888)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1888)) ;
        }else if (kBoolFalse == test_46) {
          const enumGalgasBool test_47 = GALGAS_bool (kIsEqual, constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1889)).objectCompare (GALGAS_string ("first"))).boolEnum () ;
          if (kBoolTrue == test_47) {
            {
            routine_checkInvocationHasNoArgument (constinArgument_inType, constinArgument_inMethodName, inArgument_inParameterTypeList, inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1890)) ;
            }
            outArgument_outResultType = GALGAS_Ttype::constructor_structType (SOURCE_FILE ("template_expression_parser.galgas", 1891)) ;
            GALGAS_TfieldMap var_firstElement_69926 ;
            constinArgument_inValue.getter_mMapListValue (SOURCE_FILE ("template_expression_parser.galgas", 1893)).method_first (var_firstElement_69926, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1893)) ;
            outArgument_outResultValue = function_valueWithStruct (var_firstElement_69926, function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1894)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1894)) ;
          }else if (kBoolFalse == test_47) {
            const enumGalgasBool test_48 = GALGAS_bool (kIsEqual, constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1895)).objectCompare (GALGAS_string ("last"))).boolEnum () ;
            if (kBoolTrue == test_48) {
              {
              routine_checkInvocationHasNoArgument (constinArgument_inType, constinArgument_inMethodName, inArgument_inParameterTypeList, inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1896)) ;
              }
              outArgument_outResultType = GALGAS_Ttype::constructor_structType (SOURCE_FILE ("template_expression_parser.galgas", 1897)) ;
              GALGAS_TfieldMap var_lastElement_70259 ;
              constinArgument_inValue.getter_mMapListValue (SOURCE_FILE ("template_expression_parser.galgas", 1899)).method_last (var_lastElement_70259, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1899)) ;
              outArgument_outResultValue = function_valueWithStruct (var_lastElement_70259, function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1900)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1900)) ;
            }else if (kBoolFalse == test_48) {
              GALGAS_location location_49 (constinArgument_inMethodName.getter_location (HERE)) ; // Implicit use of 'location' getter
              inCompiler->emitSemanticError (location_49, GALGAS_string ("the ").add_operation (constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1902)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1902)).add_operation (GALGAS_string (" template method is not defined for "), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1902)).add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1902)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1902))  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1902)) ;
              outArgument_outResultValue.drop () ; // Release error dropped variable
              outArgument_outResultType.drop () ; // Release error dropped variable
            }
          }
        }
      }
      break ;
    case GALGAS_Ttype::kEnum_mapType:
      {
        const enumGalgasBool test_50 = GALGAS_bool (kIsEqual, constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1905)).objectCompare (GALGAS_string ("length"))).boolEnum () ;
        if (kBoolTrue == test_50) {
          {
          routine_checkInvocationHasNoArgument (constinArgument_inType, constinArgument_inMethodName, inArgument_inParameterTypeList, inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1906)) ;
          }
          outArgument_outResultType = GALGAS_Ttype::constructor_intType (SOURCE_FILE ("template_expression_parser.galgas", 1907)) ;
          outArgument_outResultValue = function_valueWithUnsigned (constinArgument_inValue.getter_mStructValue (SOURCE_FILE ("template_expression_parser.galgas", 1908)).getter_count (SOURCE_FILE ("template_expression_parser.galgas", 1908)).getter_bigint (SOURCE_FILE ("template_expression_parser.galgas", 1908)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1908)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1908)) ;
        }else if (kBoolFalse == test_50) {
          GALGAS_location location_51 (constinArgument_inMethodName.getter_location (HERE)) ; // Implicit use of 'location' getter
          inCompiler->emitSemanticError (location_51, GALGAS_string ("the ").add_operation (constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1910)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1910)).add_operation (GALGAS_string (" template method is not defined for "), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1910)).add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1910)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1910))  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1910)) ;
          outArgument_outResultValue.drop () ; // Release error dropped variable
          outArgument_outResultType.drop () ; // Release error dropped variable
        }
      }
      break ;
    case GALGAS_Ttype::kEnum_enumType:
    case GALGAS_Ttype::kEnum_structType:
      {
        GALGAS_location location_52 (constinArgument_inMethodName.getter_location (HERE)) ; // Implicit use of 'location' getter
        inCompiler->emitSemanticError (location_52, GALGAS_string ("the ").add_operation (constinArgument_inMethodName.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1913)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1913)).add_operation (GALGAS_string (" template method is not defined for "), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1913)).add_operation (extensionGetter_messageGoilTemplateType (constinArgument_inType, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1913)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1913))  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1913)) ;
        outArgument_outResultValue.drop () ; // Release error dropped variable
        outArgument_outResultType.drop () ; // Release error dropped variable
      }
      break ;
    case GALGAS_Ttype::kEnum_unconstructedType:
    case GALGAS_Ttype::kEnum_functionType:
      {
        inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1915)), GALGAS_string ("internal error, unconstructed type found")  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1915)) ;
        outArgument_outResultValue.drop () ; // Release error dropped variable
        outArgument_outResultType.drop () ; // Release error dropped variable
      }
      break ;
    }
  }
}


//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                                 Routine 'typeError'                                                 *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

void routine_typeError (const GALGAS_lstring constinArgument_inFunctionName,
                        const GALGAS_type constinArgument_inActualType,
                        const GALGAS_string constinArgument_inExpectedTypeName,
                        const GALGAS_uint constinArgument_inParameterIndex,
                        C_Compiler * inCompiler
                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string var_m_72083 = GALGAS_string ("the function requires the parameter ").add_operation (constinArgument_inParameterIndex.getter_string (SOURCE_FILE ("template_expression_parser.galgas", 1933)), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1933)).add_operation (GALGAS_string (" to be "), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1933)).add_operation (constinArgument_inExpectedTypeName, inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1934)).add_operation (GALGAS_string ("; its type is "), inCompiler COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1934)) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, constinArgument_inActualType.objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_bool))).boolEnum () ;
  if (kBoolTrue == test_0) {
    var_m_72083.plusAssign_operation(GALGAS_string ("boolean"), inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1936)) ;
  }else if (kBoolFalse == test_0) {
    const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, constinArgument_inActualType.objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_uint_36__34_))).boolEnum () ;
    if (kBoolTrue == test_1) {
      var_m_72083.plusAssign_operation(GALGAS_string ("unsigned"), inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1938)) ;
    }else if (kBoolFalse == test_1) {
      const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, constinArgument_inActualType.objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_string))).boolEnum () ;
      if (kBoolTrue == test_2) {
        var_m_72083.plusAssign_operation(GALGAS_string ("string"), inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1940)) ;
      }else if (kBoolFalse == test_2) {
        var_m_72083.plusAssign_operation(GALGAS_string ("a not allowed type"), inCompiler  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1942)) ;
      }
    }
  }
  GALGAS_location location_3 (constinArgument_inFunctionName.getter_location (HERE)) ; // Implicit use of 'location' getter
  inCompiler->emitSemanticError (location_3, var_m_72083  COMMA_SOURCE_FILE ("template_expression_parser.galgas", 1944)) ;
}


//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                             Routine 'setVariableInPath'                                             *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

void routine_setVariableInPath (GALGAS_TvarPath inArgument_path,
                                GALGAS_TfieldMap & ioArgument_ioFieldMap,
                                const GALGAS_Ttype constinArgument_expressionType,
                                const GALGAS_Tvalue constinArgument_enumeratedValue,
                                C_Compiler * inCompiler
                                COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring var_varName_41522 ;
  GALGAS_lstring var_key_41537 ;
  GALGAS_lsint var_idx_41550 ;
  {
  inArgument_path.setter_popFirst (var_varName_41522, var_key_41537, var_idx_41550, inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1514)) ;
  }
  const enumGalgasBool test_0 = ioArgument_ioFieldMap.getter_hasKey (var_varName_41522.getter_string (SOURCE_FILE ("template_parser.galgas", 1516)) COMMA_SOURCE_FILE ("template_parser.galgas", 1516)).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_Ttype var_fieldType_41661 ;
    GALGAS_Tvalue var_fieldValue_41684 ;
    ioArgument_ioFieldMap.method_searchKey (var_varName_41522, var_fieldType_41661, var_fieldValue_41684, inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1519)) ;
    const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, var_fieldType_41661.objectCompare (GALGAS_Ttype::constructor_mapType (SOURCE_FILE ("template_parser.galgas", 1520)))).boolEnum () ;
    if (kBoolTrue == test_1) {
      const enumGalgasBool test_2 = GALGAS_bool (kIsNotEqual, var_key_41537.getter_string (SOURCE_FILE ("template_parser.galgas", 1522)).objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
      if (kBoolTrue == test_2) {
        GALGAS_TfieldMap var_items_41927 = var_fieldValue_41684.getter_mStructValue (SOURCE_FILE ("template_parser.galgas", 1524)) ;
        const enumGalgasBool test_3 = var_items_41927.getter_hasKey (var_key_41537.getter_string (SOURCE_FILE ("template_parser.galgas", 1525)) COMMA_SOURCE_FILE ("template_parser.galgas", 1525)).boolEnum () ;
        if (kBoolTrue == test_3) {
          const enumGalgasBool test_4 = GALGAS_bool (kIsEqual, inArgument_path.getter_length (SOURCE_FILE ("template_parser.galgas", 1526)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
          if (kBoolTrue == test_4) {
            {
            var_items_41927.setter_setMTypeForKey (constinArgument_expressionType, var_key_41537.getter_string (SOURCE_FILE ("template_parser.galgas", 1527)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1527)) ;
            }
            {
            var_items_41927.setter_setMValueForKey (constinArgument_enumeratedValue, var_key_41537.getter_string (SOURCE_FILE ("template_parser.galgas", 1528)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1528)) ;
            }
          }else if (kBoolFalse == test_4) {
            GALGAS_Ttype var_itemType_42216 ;
            GALGAS_Tvalue var_itemValue_42246 ;
            var_items_41927.method_searchKey (var_key_41537, var_itemType_42216, var_itemValue_42246, inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1532)) ;
            GALGAS_TfieldMap var_nextFieldMap_42338 = var_itemValue_42246.getter_mStructValue (SOURCE_FILE ("template_parser.galgas", 1533)) ;
            {
            routine_setVariableInPath (inArgument_path, var_nextFieldMap_42338, constinArgument_expressionType, constinArgument_enumeratedValue, inCompiler  COMMA_SOURCE_FILE ("template_parser.galgas", 1534)) ;
            }
            var_itemValue_42246.mAttribute_mStructValue = var_nextFieldMap_42338 ;
            var_itemType_42216 = GALGAS_Ttype::constructor_structType (SOURCE_FILE ("template_parser.galgas", 1536)) ;
            {
            var_items_41927.setter_setMTypeForKey (var_itemType_42216, var_key_41537.getter_string (SOURCE_FILE ("template_parser.galgas", 1537)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1537)) ;
            }
            {
            var_items_41927.setter_setMValueForKey (var_itemValue_42246, var_key_41537.getter_string (SOURCE_FILE ("template_parser.galgas", 1538)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1538)) ;
            }
          }
        }else if (kBoolFalse == test_3) {
          const enumGalgasBool test_5 = GALGAS_bool (kIsEqual, inArgument_path.getter_length (SOURCE_FILE ("template_parser.galgas", 1541)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
          if (kBoolTrue == test_5) {
            {
            var_items_41927.setter_insertKey (var_key_41537, constinArgument_expressionType, constinArgument_enumeratedValue, inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1542)) ;
            }
          }else if (kBoolFalse == test_5) {
            GALGAS_TfieldMap var_nextFieldMap_42846 = GALGAS_TfieldMap::constructor_emptyMap (SOURCE_FILE ("template_parser.galgas", 1544)) ;
            {
            routine_setVariableInPath (inArgument_path, var_nextFieldMap_42846, constinArgument_expressionType, constinArgument_enumeratedValue, inCompiler  COMMA_SOURCE_FILE ("template_parser.galgas", 1545)) ;
            }
            {
            var_items_41927.setter_insertKey (var_key_41537, GALGAS_Ttype::constructor_structType (SOURCE_FILE ("template_parser.galgas", 1546)), function_valueWithStruct (var_nextFieldMap_42846, function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1546)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1546)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1546)) ;
            }
          }
        }
        var_fieldValue_41684.mAttribute_mStructValue = var_items_41927 ;
        {
        ioArgument_ioFieldMap.setter_setMTypeForKey (var_fieldType_41661, var_varName_41522.getter_string (SOURCE_FILE ("template_parser.galgas", 1550)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1550)) ;
        }
        {
        ioArgument_ioFieldMap.setter_setMValueForKey (var_fieldValue_41684, var_varName_41522.getter_string (SOURCE_FILE ("template_parser.galgas", 1551)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1551)) ;
        }
      }else if (kBoolFalse == test_2) {
        const enumGalgasBool test_6 = GALGAS_bool (kIsEqual, inArgument_path.getter_length (SOURCE_FILE ("template_parser.galgas", 1553)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
        if (kBoolTrue == test_6) {
          {
          ioArgument_ioFieldMap.setter_setMTypeForKey (constinArgument_expressionType, var_varName_41522.getter_string (SOURCE_FILE ("template_parser.galgas", 1555)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1555)) ;
          }
          {
          ioArgument_ioFieldMap.setter_setMValueForKey (constinArgument_enumeratedValue, var_varName_41522.getter_string (SOURCE_FILE ("template_parser.galgas", 1556)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1556)) ;
          }
        }else if (kBoolFalse == test_6) {
          GALGAS_TfieldMap var_nextFieldMap_43603 = GALGAS_TfieldMap::constructor_emptyMap (SOURCE_FILE ("template_parser.galgas", 1559)) ;
          {
          routine_setVariableInPath (inArgument_path, var_nextFieldMap_43603, constinArgument_expressionType, constinArgument_enumeratedValue, inCompiler  COMMA_SOURCE_FILE ("template_parser.galgas", 1560)) ;
          }
          {
          ioArgument_ioFieldMap.setter_setMTypeForKey (GALGAS_Ttype::constructor_structType (SOURCE_FILE ("template_parser.galgas", 1561)), var_varName_41522.getter_string (SOURCE_FILE ("template_parser.galgas", 1561)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1561)) ;
          }
          {
          ioArgument_ioFieldMap.setter_setMValueForKey (function_valueWithStruct (var_nextFieldMap_43603, function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1562)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1562)), var_varName_41522.getter_string (SOURCE_FILE ("template_parser.galgas", 1562)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1562)) ;
          }
        }
      }
    }else if (kBoolFalse == test_1) {
      const enumGalgasBool test_7 = GALGAS_bool (kIsEqual, var_fieldType_41661.objectCompare (GALGAS_Ttype::constructor_listType (SOURCE_FILE ("template_parser.galgas", 1565)))).boolEnum () ;
      if (kBoolTrue == test_7) {
        const enumGalgasBool test_8 = GALGAS_bool (kIsNotEqual, var_idx_41550.getter_sint (SOURCE_FILE ("template_parser.galgas", 1567)).objectCompare (GALGAS_sint ((int32_t) 1L).operator_unary_minus (inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1567)))).boolEnum () ;
        if (kBoolTrue == test_8) {
          const enumGalgasBool test_9 = GALGAS_bool (kIsEqual, inArgument_path.getter_length (SOURCE_FILE ("template_parser.galgas", 1568)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
          if (kBoolTrue == test_9) {
            const enumGalgasBool test_10 = GALGAS_bool (kIsEqual, constinArgument_expressionType.objectCompare (GALGAS_Ttype::constructor_structType (SOURCE_FILE ("template_parser.galgas", 1569)))).boolEnum () ;
            if (kBoolTrue == test_10) {
              GALGAS_TfieldMapList var_theList_44216 = var_fieldValue_41684.getter_mMapListValue (SOURCE_FILE ("template_parser.galgas", 1571)) ;
              {
              var_theList_44216.setter_setMMapAtIndex (constinArgument_enumeratedValue.getter_mStructValue (SOURCE_FILE ("template_parser.galgas", 1572)), var_idx_41550.mAttribute_sint.getter_uint (inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1572)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1572)) ;
              }
              var_fieldValue_41684.mAttribute_mMapListValue = var_theList_44216 ;
            }else if (kBoolFalse == test_10) {
              GALGAS_location location_11 (var_varName_41522.getter_location (HERE)) ; // Implicit use of 'location' getter
              inCompiler->emitSemanticError (location_11, GALGAS_string ("struct expression expected")  COMMA_SOURCE_FILE ("template_parser.galgas", 1576)) ;
            }
          }else if (kBoolFalse == test_9) {
            GALGAS_TfieldMapList var_theList_44640 = var_fieldValue_41684.getter_mMapListValue (SOURCE_FILE ("template_parser.galgas", 1580)) ;
            GALGAS_TfieldMap var_nextFieldMap_44703 = var_theList_44640.getter_mMapAtIndex (var_idx_41550.mAttribute_sint.getter_uint (inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1581)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1581)) ;
            {
            routine_setVariableInPath (inArgument_path, var_nextFieldMap_44703, constinArgument_expressionType, constinArgument_enumeratedValue, inCompiler  COMMA_SOURCE_FILE ("template_parser.galgas", 1582)) ;
            }
            {
            var_theList_44640.setter_setMMapAtIndex (var_nextFieldMap_44703, var_idx_41550.mAttribute_sint.getter_uint (inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1583)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1583)) ;
            }
            var_fieldValue_41684.mAttribute_mMapListValue = var_theList_44640 ;
          }
          {
          ioArgument_ioFieldMap.setter_setMTypeForKey (var_fieldType_41661, var_varName_41522.getter_string (SOURCE_FILE ("template_parser.galgas", 1586)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1586)) ;
          }
          {
          ioArgument_ioFieldMap.setter_setMValueForKey (var_fieldValue_41684, var_varName_41522.getter_string (SOURCE_FILE ("template_parser.galgas", 1587)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1587)) ;
          }
        }else if (kBoolFalse == test_8) {
          const enumGalgasBool test_12 = GALGAS_bool (kIsEqual, inArgument_path.getter_length (SOURCE_FILE ("template_parser.galgas", 1590)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
          if (kBoolTrue == test_12) {
            {
            ioArgument_ioFieldMap.setter_setMTypeForKey (constinArgument_expressionType, var_varName_41522.getter_string (SOURCE_FILE ("template_parser.galgas", 1592)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1592)) ;
            }
            {
            ioArgument_ioFieldMap.setter_setMValueForKey (constinArgument_enumeratedValue, var_varName_41522.getter_string (SOURCE_FILE ("template_parser.galgas", 1593)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1593)) ;
            }
          }else if (kBoolFalse == test_12) {
            GALGAS_TfieldMap var_nextFieldMap_45403 = GALGAS_TfieldMap::constructor_emptyMap (SOURCE_FILE ("template_parser.galgas", 1596)) ;
            {
            routine_setVariableInPath (inArgument_path, var_nextFieldMap_45403, constinArgument_expressionType, constinArgument_enumeratedValue, inCompiler  COMMA_SOURCE_FILE ("template_parser.galgas", 1597)) ;
            }
            {
            ioArgument_ioFieldMap.setter_setMTypeForKey (GALGAS_Ttype::constructor_structType (SOURCE_FILE ("template_parser.galgas", 1598)), var_varName_41522.getter_string (SOURCE_FILE ("template_parser.galgas", 1598)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1598)) ;
            }
            {
            ioArgument_ioFieldMap.setter_setMValueForKey (function_valueWithStruct (var_nextFieldMap_45403, function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1599)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1599)), var_varName_41522.getter_string (SOURCE_FILE ("template_parser.galgas", 1599)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1599)) ;
            }
          }
        }
      }else if (kBoolFalse == test_7) {
        const enumGalgasBool test_13 = GALGAS_bool (kIsEqual, var_fieldType_41661.objectCompare (GALGAS_Ttype::constructor_structType (SOURCE_FILE ("template_parser.galgas", 1602)))).boolEnum () ;
        if (kBoolTrue == test_13) {
          const enumGalgasBool test_14 = GALGAS_bool (kIsEqual, inArgument_path.getter_length (SOURCE_FILE ("template_parser.galgas", 1603)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
          if (kBoolTrue == test_14) {
            {
            ioArgument_ioFieldMap.setter_setMTypeForKey (constinArgument_expressionType, var_varName_41522.getter_string (SOURCE_FILE ("template_parser.galgas", 1605)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1605)) ;
            }
            {
            ioArgument_ioFieldMap.setter_setMValueForKey (constinArgument_enumeratedValue, var_varName_41522.getter_string (SOURCE_FILE ("template_parser.galgas", 1606)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1606)) ;
            }
          }else if (kBoolFalse == test_14) {
            GALGAS_TfieldMap var_nextFieldMap_46073 = var_fieldValue_41684.getter_mStructValue (SOURCE_FILE ("template_parser.galgas", 1609)) ;
            {
            routine_setVariableInPath (inArgument_path, var_nextFieldMap_46073, constinArgument_expressionType, constinArgument_enumeratedValue, inCompiler  COMMA_SOURCE_FILE ("template_parser.galgas", 1610)) ;
            }
            var_fieldValue_41684.mAttribute_mStructValue = var_nextFieldMap_46073 ;
            {
            ioArgument_ioFieldMap.setter_setMValueForKey (var_fieldValue_41684, var_varName_41522.getter_string (SOURCE_FILE ("template_parser.galgas", 1613)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1613)) ;
            }
          }
        }else if (kBoolFalse == test_13) {
          const enumGalgasBool test_15 = GALGAS_bool (kIsEqual, var_key_41537.getter_string (SOURCE_FILE ("template_parser.galgas", 1616)).objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
          if (kBoolTrue == test_15) {
            const enumGalgasBool test_16 = GALGAS_bool (kIsEqual, var_idx_41550.getter_sint (SOURCE_FILE ("template_parser.galgas", 1617)).objectCompare (GALGAS_sint ((int32_t) 1L).operator_unary_minus (inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1617)))).boolEnum () ;
            if (kBoolTrue == test_16) {
              const enumGalgasBool test_17 = GALGAS_bool (kIsEqual, inArgument_path.getter_length (SOURCE_FILE ("template_parser.galgas", 1618)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
              if (kBoolTrue == test_17) {
                {
                ioArgument_ioFieldMap.setter_setMTypeForKey (constinArgument_expressionType, var_varName_41522.getter_string (SOURCE_FILE ("template_parser.galgas", 1620)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1620)) ;
                }
                {
                ioArgument_ioFieldMap.setter_setMValueForKey (constinArgument_enumeratedValue, var_varName_41522.getter_string (SOURCE_FILE ("template_parser.galgas", 1621)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1621)) ;
                }
              }else if (kBoolFalse == test_17) {
                GALGAS_TfieldMap var_nextFieldMap_46696 = GALGAS_TfieldMap::constructor_emptyMap (SOURCE_FILE ("template_parser.galgas", 1623)) ;
                {
                routine_setVariableInPath (inArgument_path, var_nextFieldMap_46696, constinArgument_expressionType, constinArgument_enumeratedValue, inCompiler  COMMA_SOURCE_FILE ("template_parser.galgas", 1624)) ;
                }
                {
                ioArgument_ioFieldMap.setter_setMTypeForKey (GALGAS_Ttype::constructor_structType (SOURCE_FILE ("template_parser.galgas", 1625)), var_varName_41522.getter_string (SOURCE_FILE ("template_parser.galgas", 1625)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1625)) ;
                }
                {
                ioArgument_ioFieldMap.setter_setMValueForKey (function_valueWithStruct (var_nextFieldMap_46696, function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1626)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1626)), var_varName_41522.getter_string (SOURCE_FILE ("template_parser.galgas", 1626)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1626)) ;
                }
              }
            }else if (kBoolFalse == test_16) {
              GALGAS_location location_18 (var_varName_41522.getter_location (HERE)) ; // Implicit use of 'location' getter
              inCompiler->emitSemanticError (location_18, GALGAS_string ("A list must exist before setting one of its item")  COMMA_SOURCE_FILE ("template_parser.galgas", 1630)) ;
            }
          }else if (kBoolFalse == test_15) {
            GALGAS_TfieldMap var_newMap_47242 = GALGAS_TfieldMap::constructor_emptyMap (SOURCE_FILE ("template_parser.galgas", 1634)) ;
            const enumGalgasBool test_19 = GALGAS_bool (kIsEqual, inArgument_path.getter_length (SOURCE_FILE ("template_parser.galgas", 1635)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
            if (kBoolTrue == test_19) {
              {
              var_newMap_47242.setter_insertKey (var_key_41537, constinArgument_expressionType, constinArgument_enumeratedValue, inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1636)) ;
              }
            }else if (kBoolFalse == test_19) {
              GALGAS_TfieldMap var_nextFieldMap_47409 = GALGAS_TfieldMap::constructor_emptyMap (SOURCE_FILE ("template_parser.galgas", 1638)) ;
              {
              routine_setVariableInPath (inArgument_path, var_nextFieldMap_47409, constinArgument_expressionType, constinArgument_enumeratedValue, inCompiler  COMMA_SOURCE_FILE ("template_parser.galgas", 1639)) ;
              }
              {
              var_newMap_47242.setter_insertKey (var_key_41537, GALGAS_Ttype::constructor_structType (SOURCE_FILE ("template_parser.galgas", 1640)), function_valueWithStruct (var_nextFieldMap_47409, function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1640)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1640)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1640)) ;
              }
            }
            {
            ioArgument_ioFieldMap.setter_setMTypeForKey (GALGAS_Ttype::constructor_mapType (SOURCE_FILE ("template_parser.galgas", 1642)), var_varName_41522.getter_string (SOURCE_FILE ("template_parser.galgas", 1642)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1642)) ;
            }
            {
            ioArgument_ioFieldMap.setter_setMValueForKey (function_valueWithMap (var_newMap_47242, function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1643)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1643)), var_varName_41522.getter_string (SOURCE_FILE ("template_parser.galgas", 1643)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1643)) ;
            }
          }
        }
      }
    }
  }else if (kBoolFalse == test_0) {
    const enumGalgasBool test_20 = GALGAS_bool (kIsEqual, inArgument_path.getter_length (SOURCE_FILE ("template_parser.galgas", 1648)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
    if (kBoolTrue == test_20) {
      const enumGalgasBool test_21 = GALGAS_bool (kIsEqual, var_key_41537.getter_string (SOURCE_FILE ("template_parser.galgas", 1649)).objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
      if (kBoolTrue == test_21) {
        const enumGalgasBool test_22 = GALGAS_bool (kIsEqual, var_idx_41550.getter_sint (SOURCE_FILE ("template_parser.galgas", 1650)).objectCompare (GALGAS_sint ((int32_t) 1L).operator_unary_minus (inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1650)))).boolEnum () ;
        if (kBoolTrue == test_22) {
          {
          ioArgument_ioFieldMap.setter_insertKey (var_varName_41522, constinArgument_expressionType, constinArgument_enumeratedValue, inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1651)) ;
          }
        }else if (kBoolFalse == test_22) {
          GALGAS_location location_23 (var_varName_41522.getter_location (HERE)) ; // Implicit use of 'location' getter
          inCompiler->emitSemanticError (location_23, GALGAS_string ("A list must exist before setting one of its item")  COMMA_SOURCE_FILE ("template_parser.galgas", 1654)) ;
        }
      }else if (kBoolFalse == test_21) {
        GALGAS_TfieldMap var_newMap_48246 = GALGAS_TfieldMap::constructor_emptyMap (SOURCE_FILE ("template_parser.galgas", 1657)) ;
        {
        var_newMap_48246.setter_insertKey (var_key_41537, constinArgument_expressionType, constinArgument_enumeratedValue, inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1658)) ;
        }
        {
        ioArgument_ioFieldMap.setter_insertKey (var_varName_41522, GALGAS_Ttype::constructor_mapType (SOURCE_FILE ("template_parser.galgas", 1659)), function_valueWithMap (var_newMap_48246, function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1659)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1659)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1659)) ;
        }
      }
    }else if (kBoolFalse == test_20) {
      const enumGalgasBool test_24 = GALGAS_bool (kIsEqual, var_key_41537.getter_string (SOURCE_FILE ("template_parser.galgas", 1662)).objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
      if (kBoolTrue == test_24) {
        const enumGalgasBool test_25 = GALGAS_bool (kIsEqual, var_idx_41550.getter_sint (SOURCE_FILE ("template_parser.galgas", 1663)).objectCompare (GALGAS_sint ((int32_t) 1L).operator_unary_minus (inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1663)))).boolEnum () ;
        if (kBoolTrue == test_25) {
          GALGAS_TfieldMap var_nextFieldMap_48547 = GALGAS_TfieldMap::constructor_emptyMap (SOURCE_FILE ("template_parser.galgas", 1664)) ;
          {
          routine_setVariableInPath (inArgument_path, var_nextFieldMap_48547, constinArgument_expressionType, constinArgument_enumeratedValue, inCompiler  COMMA_SOURCE_FILE ("template_parser.galgas", 1665)) ;
          }
          {
          ioArgument_ioFieldMap.setter_insertKey (var_varName_41522, GALGAS_Ttype::constructor_structType (SOURCE_FILE ("template_parser.galgas", 1666)), function_valueWithStruct (var_nextFieldMap_48547, function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1666)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1666)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1666)) ;
          }
        }else if (kBoolFalse == test_25) {
          GALGAS_location location_26 (var_varName_41522.getter_location (HERE)) ; // Implicit use of 'location' getter
          inCompiler->emitSemanticError (location_26, GALGAS_string ("A list must exist before setting one of its item")  COMMA_SOURCE_FILE ("template_parser.galgas", 1669)) ;
        }
      }else if (kBoolFalse == test_24) {
        GALGAS_TfieldMap var_newMap_48977 = GALGAS_TfieldMap::constructor_emptyMap (SOURCE_FILE ("template_parser.galgas", 1672)) ;
        GALGAS_TfieldMap var_nextFieldMap_49025 = GALGAS_TfieldMap::constructor_emptyMap (SOURCE_FILE ("template_parser.galgas", 1673)) ;
        {
        routine_setVariableInPath (inArgument_path, var_nextFieldMap_49025, constinArgument_expressionType, constinArgument_enumeratedValue, inCompiler  COMMA_SOURCE_FILE ("template_parser.galgas", 1674)) ;
        }
        {
        var_newMap_48977.setter_insertKey (var_key_41537, GALGAS_Ttype::constructor_structType (SOURCE_FILE ("template_parser.galgas", 1675)), function_valueWithStruct (var_nextFieldMap_49025, function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1675)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1675)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1675)) ;
        }
        {
        ioArgument_ioFieldMap.setter_insertKey (var_varName_41522, GALGAS_Ttype::constructor_mapType (SOURCE_FILE ("template_parser.galgas", 1676)), function_valueWithMap (var_newMap_48977, function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1676)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1676)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1676)) ;
        }
      }
    }
  }
}


//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                               Routine 'printVariable'                                               *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

void routine_printVariable (GALGAS_uint inArgument_indent,
                            const GALGAS_Ttype constinArgument_variableType,
                            const GALGAS_Tvalue constinArgument_variableValue,
                            C_Compiler * inCompiler
                            COMMA_UNUSED_LOCATION_ARGS) {
  inArgument_indent = inArgument_indent.add_operation (GALGAS_uint ((uint32_t) 4U), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1687)) ;
  GALGAS_string var_offset_49568 = GALGAS_string::constructor_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), inArgument_indent  COMMA_SOURCE_FILE ("template_parser.galgas", 1688)) ;
  switch (constinArgument_variableType.enumValue ()) {
  case GALGAS_Ttype::kNotBuilt:
    break ;
  case GALGAS_Ttype::kEnum_boolType:
    {
      const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, constinArgument_variableValue.getter_mBigIntValue (SOURCE_FILE ("template_parser.galgas", 1691)).objectCompare (GALGAS_bigint ("1", inCompiler  COMMA_SOURCE_FILE ("template_parser.galgas", 1691)))).boolEnum () ;
      if (kBoolTrue == test_0) {
        inCompiler->printMessage (var_offset_49568.add_operation (GALGAS_string ("true\n"), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1692))  COMMA_SOURCE_FILE ("template_parser.galgas", 1692)) ;
      }else if (kBoolFalse == test_0) {
        inCompiler->printMessage (var_offset_49568.add_operation (GALGAS_string ("false\n"), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1694))  COMMA_SOURCE_FILE ("template_parser.galgas", 1694)) ;
      }
    }
    break ;
  case GALGAS_Ttype::kEnum_intType:
    {
      inCompiler->printMessage (var_offset_49568.add_operation (constinArgument_variableValue.getter_mBigIntValue (SOURCE_FILE ("template_parser.galgas", 1697)).getter_string (SOURCE_FILE ("template_parser.galgas", 1697)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1697)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1697))  COMMA_SOURCE_FILE ("template_parser.galgas", 1697)) ;
    }
    break ;
  case GALGAS_Ttype::kEnum_floatType:
    {
      inCompiler->printMessage (var_offset_49568.add_operation (constinArgument_variableValue.getter_mFloatValue (SOURCE_FILE ("template_parser.galgas", 1699)).getter_string (SOURCE_FILE ("template_parser.galgas", 1699)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1699)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1699))  COMMA_SOURCE_FILE ("template_parser.galgas", 1699)) ;
    }
    break ;
  case GALGAS_Ttype::kEnum_stringType:
    {
      inCompiler->printMessage (var_offset_49568.add_operation (GALGAS_string ("\""), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1701)).add_operation (constinArgument_variableValue.getter_mStringValue (SOURCE_FILE ("template_parser.galgas", 1701)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1701)).add_operation (GALGAS_string ("\"\n"), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1701))  COMMA_SOURCE_FILE ("template_parser.galgas", 1701)) ;
    }
    break ;
  case GALGAS_Ttype::kEnum_enumType:
    {
      inCompiler->printMessage (var_offset_49568.add_operation (constinArgument_variableValue.getter_mStringValue (SOURCE_FILE ("template_parser.galgas", 1703)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1703)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1703))  COMMA_SOURCE_FILE ("template_parser.galgas", 1703)) ;
    }
    break ;
  case GALGAS_Ttype::kEnum_listType:
    {
      cEnumerator_TfieldMapList enumerator_50141 (constinArgument_variableValue.getter_mMapListValue (SOURCE_FILE ("template_parser.galgas", 1705)), kEnumeration_up) ;
      GALGAS_uint index_50104 ((uint32_t) 0) ;
      while (enumerator_50141.hasCurrentObject ()) {
        inCompiler->printMessage (var_offset_49568.add_operation (GALGAS_string ("item at "), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1706)).add_operation (index_50104.getter_string (SOURCE_FILE ("template_parser.galgas", 1706)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1706)).add_operation (GALGAS_string (":\n"), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1706))  COMMA_SOURCE_FILE ("template_parser.galgas", 1706)) ;
        {
        routine_printVariable (inArgument_indent, GALGAS_Ttype::constructor_structType (SOURCE_FILE ("template_parser.galgas", 1707)), GALGAS_Tvalue::constructor_new (GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("template_parser.galgas", 1707)), GALGAS_double (0), GALGAS_string::makeEmptyString (), GALGAS_TfieldMapList::constructor_emptyList (SOURCE_FILE ("template_parser.galgas", 1707)), enumerator_50141.current_mMap (HERE), function_dummyFunction (inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1707)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1707))  COMMA_SOURCE_FILE ("template_parser.galgas", 1707)), inCompiler  COMMA_SOURCE_FILE ("template_parser.galgas", 1707)) ;
        }
        enumerator_50141.gotoNextObject () ;
        index_50104.increment_operation (inCompiler  COMMA_SOURCE_FILE ("template_parser.galgas", 1705)) ;
      }
    }
    break ;
  case GALGAS_Ttype::kEnum_mapType:
    {
      cEnumerator_TfieldMap enumerator_50407 (constinArgument_variableValue.getter_mStructValue (SOURCE_FILE ("template_parser.galgas", 1710)), kEnumeration_up) ;
      while (enumerator_50407.hasCurrentObject ()) {
        inCompiler->printMessage (var_offset_49568.add_operation (enumerator_50407.current_lkey (HERE).getter_string (SOURCE_FILE ("template_parser.galgas", 1711)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1711)).add_operation (GALGAS_string (":\n"), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1711))  COMMA_SOURCE_FILE ("template_parser.galgas", 1711)) ;
        {
        routine_printVariable (inArgument_indent, enumerator_50407.current_mType (HERE), enumerator_50407.current_mValue (HERE), inCompiler  COMMA_SOURCE_FILE ("template_parser.galgas", 1712)) ;
        }
        enumerator_50407.gotoNextObject () ;
      }
    }
    break ;
  case GALGAS_Ttype::kEnum_structType:
    {
      cEnumerator_TfieldMap enumerator_50559 (constinArgument_variableValue.getter_mStructValue (SOURCE_FILE ("template_parser.galgas", 1715)), kEnumeration_up) ;
      while (enumerator_50559.hasCurrentObject ()) {
        inCompiler->printMessage (var_offset_49568.add_operation (enumerator_50559.current_lkey (HERE).getter_string (SOURCE_FILE ("template_parser.galgas", 1716)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1716)).add_operation (GALGAS_string (":\n"), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1716))  COMMA_SOURCE_FILE ("template_parser.galgas", 1716)) ;
        {
        routine_printVariable (inArgument_indent, enumerator_50559.current_mType (HERE), enumerator_50559.current_mValue (HERE), inCompiler  COMMA_SOURCE_FILE ("template_parser.galgas", 1717)) ;
        }
        enumerator_50559.gotoNextObject () ;
      }
    }
    break ;
  case GALGAS_Ttype::kEnum_unconstructedType:
  case GALGAS_Ttype::kEnum_functionType:
    {
    }
    break ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                              Function 'structCompare'                                               *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

GALGAS_sint function_structCompare (const GALGAS_TfieldMap & constinArgument_s_31_,
                                    const GALGAS_TfieldMap & constinArgument_s_32_,
                                    GALGAS_sortingKeyList inArgument_fieldList,
                                    C_Compiler * inCompiler
                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_sint result_result ; // Returned variable
  const enumGalgasBool test_0 = GALGAS_bool (kIsStrictSup, inArgument_fieldList.getter_length (SOURCE_FILE ("template_parser.galgas", 1735)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_lstring var_field_50993 ;
    GALGAS_lsint var_order_51010 ;
    {
    inArgument_fieldList.setter_popFirst (var_field_50993, var_order_51010, inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1738)) ;
    }
    GALGAS_Ttype var_s_31_Type_51069 ;
    GALGAS_Tvalue var_s_31_Value_51089 ;
    constinArgument_s_31_.method_searchKey (var_field_50993, var_s_31_Type_51069, var_s_31_Value_51089, inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1741)) ;
    GALGAS_Ttype var_s_32_Type_51150 ;
    GALGAS_Tvalue var_s_32_Value_51170 ;
    constinArgument_s_32_.method_searchKey (var_field_50993, var_s_32_Type_51150, var_s_32_Value_51170, inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1744)) ;
    const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, var_s_31_Type_51069.objectCompare (var_s_32_Type_51150)).operator_and (GALGAS_bool (kIsEqual, var_s_31_Type_51069.objectCompare (GALGAS_Ttype::constructor_intType (SOURCE_FILE ("template_parser.galgas", 1745)))) COMMA_SOURCE_FILE ("template_parser.galgas", 1745)).boolEnum () ;
    if (kBoolTrue == test_1) {
      const enumGalgasBool test_2 = GALGAS_bool (kIsStrictInf, var_s_31_Value_51089.getter_mBigIntValue (SOURCE_FILE ("template_parser.galgas", 1747)).objectCompare (var_s_32_Value_51170.getter_mBigIntValue (SOURCE_FILE ("template_parser.galgas", 1747)))).boolEnum () ;
      if (kBoolTrue == test_2) {
        result_result = GALGAS_sint ((int32_t) 1L).operator_unary_minus (inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1749)).multiply_operation (var_order_51010.getter_sint (SOURCE_FILE ("template_parser.galgas", 1749)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1749)) ;
      }else if (kBoolFalse == test_2) {
        const enumGalgasBool test_3 = GALGAS_bool (kIsStrictSup, var_s_31_Value_51089.getter_mBigIntValue (SOURCE_FILE ("template_parser.galgas", 1751)).objectCompare (var_s_32_Value_51170.getter_mBigIntValue (SOURCE_FILE ("template_parser.galgas", 1751)))).boolEnum () ;
        if (kBoolTrue == test_3) {
          result_result = GALGAS_sint ((int32_t) 1L).multiply_operation (var_order_51010.getter_sint (SOURCE_FILE ("template_parser.galgas", 1753)), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1753)) ;
        }else if (kBoolFalse == test_3) {
          result_result = function_structCompare (constinArgument_s_31_, constinArgument_s_32_, inArgument_fieldList, inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1756)) ;
        }
      }
    }else if (kBoolFalse == test_1) {
      GALGAS_location location_4 (var_field_50993.getter_location (HERE)) ; // Implicit use of 'location' getter
      inCompiler->emitSemanticError (location_4, GALGAS_string ("unsigned sort key required")  COMMA_SOURCE_FILE ("template_parser.galgas", 1760)) ;
      result_result.drop () ; // Release error dropped variable
    }
  }else if (kBoolFalse == test_0) {
    result_result = GALGAS_sint ((int32_t) 0L) ;
  }
//---
  return result_result ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                                             *
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_structCompare [4] = {
  & kTypeDescriptor_GALGAS_TfieldMap,
  & kTypeDescriptor_GALGAS_TfieldMap,
  & kTypeDescriptor_GALGAS_sortingKeyList,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_structCompare (C_Compiler * inCompiler,
                                                              const cObjectArray & inEffectiveParameterArray,
                                                              const GALGAS_location & /* §§ inErrorLocation */
                                                              COMMA_LOCATION_ARGS) {
  const GALGAS_TfieldMap operand0 = GALGAS_TfieldMap::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                     inCompiler
                                                                     COMMA_THERE) ;
  const GALGAS_TfieldMap operand1 = GALGAS_TfieldMap::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                                     inCompiler
                                                                     COMMA_THERE) ;
  const GALGAS_sortingKeyList operand2 = GALGAS_sortingKeyList::extractObject (inEffectiveParameterArray.objectAtIndex (2 COMMA_HERE),
                                                                               inCompiler
                                                                               COMMA_THERE) ;
  return function_structCompare (operand0,
                                 operand1,
                                 operand2,
                                 inCompiler
                                 COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_structCompare ("structCompare",
                                                               functionWithGenericHeader_structCompare,
                                                               & kTypeDescriptor_GALGAS_sint,
                                                               3,
                                                               functionArgs_structCompare) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                                   Routine 'swap'                                                    *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

void routine_swap (GALGAS_TfieldMapList & ioArgument_t,
                   const GALGAS_uint constinArgument_index_31_,
                   const GALGAS_uint constinArgument_index_32_,
                   C_Compiler * inCompiler
                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_TfieldMap var_temp_51943 = ioArgument_t.getter_mMapAtIndex (constinArgument_index_31_, inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1772)) ;
  {
  ioArgument_t.setter_setMMapAtIndex (ioArgument_t.getter_mMapAtIndex (constinArgument_index_32_, inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1773)), constinArgument_index_31_, inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1773)) ;
  }
  {
  ioArgument_t.setter_setMMapAtIndex (var_temp_51943, constinArgument_index_32_, inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1774)) ;
  }
}


//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                                 Routine 'partition'                                                 *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

void routine_partition (GALGAS_TfieldMapList & ioArgument_t,
                        GALGAS_uint inArgument_min,
                        GALGAS_uint inArgument_max,
                        const GALGAS_sortingKeyList constinArgument_fieldList,
                        GALGAS_uint & ioArgument_pivotIndex,
                        C_Compiler * inCompiler
                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_TfieldMap var_pivot_52203 = ioArgument_t.getter_mMapAtIndex (ioArgument_pivotIndex, inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1783)) ;
  {
  routine_swap (ioArgument_t, ioArgument_pivotIndex, inArgument_max, inCompiler  COMMA_SOURCE_FILE ("template_parser.galgas", 1784)) ;
  }
  GALGAS_uint var_storeIndex_52283 = inArgument_min ;
  GALGAS_uint var_i_52299 = inArgument_min ;
  if (inArgument_max.substract_operation (inArgument_min, inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1787)).isValid ()) {
    uint32_t variant_52312 = inArgument_max.substract_operation (inArgument_min, inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1787)).uintValue () ;
    bool loop_52312 = true ;
    while (loop_52312) {
      loop_52312 = GALGAS_bool (kIsStrictInf, var_i_52299.objectCompare (inArgument_max)).isValid () ;
      if (loop_52312) {
        loop_52312 = GALGAS_bool (kIsStrictInf, var_i_52299.objectCompare (inArgument_max)).boolValue () ;
      }
      if (loop_52312 && (0 == variant_52312)) {
        loop_52312 = false ;
        inCompiler->loopRunTimeVariantError (SOURCE_FILE ("template_parser.galgas", 1787)) ;
      }
      if (loop_52312) {
        variant_52312 -- ;
        const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, function_structCompare (ioArgument_t.getter_mMapAtIndex (var_i_52299, inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1789)), var_pivot_52203, constinArgument_fieldList, inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1789)).objectCompare (GALGAS_sint ((int32_t) 1L).operator_unary_minus (inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1789)))).boolEnum () ;
        if (kBoolTrue == test_0) {
          {
          routine_swap (ioArgument_t, var_i_52299, var_storeIndex_52283, inCompiler  COMMA_SOURCE_FILE ("template_parser.galgas", 1790)) ;
          }
          var_storeIndex_52283.increment_operation (inCompiler  COMMA_SOURCE_FILE ("template_parser.galgas", 1791)) ;
        }
        var_i_52299.increment_operation (inCompiler  COMMA_SOURCE_FILE ("template_parser.galgas", 1793)) ;
      }
    }
  }
  {
  routine_swap (ioArgument_t, var_storeIndex_52283, inArgument_max, inCompiler  COMMA_SOURCE_FILE ("template_parser.galgas", 1795)) ;
  }
  ioArgument_pivotIndex = var_storeIndex_52283 ;
}


//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                                 Routine 'quickSort'                                                 *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

void routine_quickSort (GALGAS_TfieldMapList & ioArgument_t,
                        const GALGAS_uint constinArgument_min,
                        const GALGAS_uint constinArgument_max,
                        const GALGAS_sortingKeyList constinArgument_fieldList,
                        C_Compiler * inCompiler
                        COMMA_UNUSED_LOCATION_ARGS) {
  const enumGalgasBool test_0 = GALGAS_bool (kIsStrictInf, constinArgument_min.objectCompare (constinArgument_max)).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_uint var_pivotIndex_52740 = constinArgument_max.add_operation (constinArgument_min, inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1806)).divide_operation (GALGAS_uint ((uint32_t) 2U), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1806)) ;
    {
    routine_partition (ioArgument_t, constinArgument_min, constinArgument_max, constinArgument_fieldList, var_pivotIndex_52740, inCompiler  COMMA_SOURCE_FILE ("template_parser.galgas", 1808)) ;
    }
    {
    routine_quickSort (ioArgument_t, constinArgument_min, var_pivotIndex_52740, constinArgument_fieldList, inCompiler  COMMA_SOURCE_FILE ("template_parser.galgas", 1809)) ;
    }
    {
    routine_quickSort (ioArgument_t, var_pivotIndex_52740.add_operation (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("template_parser.galgas", 1810)), constinArgument_max, constinArgument_fieldList, inCompiler  COMMA_SOURCE_FILE ("template_parser.galgas", 1810)) ;
    }
  }
}


//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                          Once function 'allowedFunctions'                                           *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

static GALGAS_stringset onceFunction_allowedFunctions (C_Compiler * /* inCompiler */
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_stringset result_outAllowedFunctionSet ; // Returned variable
  result_outAllowedFunctionSet = GALGAS_stringset::constructor_emptySet (SOURCE_FILE ("template_invocation.galgas", 28)) ;
  result_outAllowedFunctionSet.addAssign_operation (GALGAS_string ("testFunction")  COMMA_SOURCE_FILE ("template_invocation.galgas", 29)) ;
  result_outAllowedFunctionSet.addAssign_operation (GALGAS_string ("tasks")  COMMA_SOURCE_FILE ("template_invocation.galgas", 30)) ;
  result_outAllowedFunctionSet.addAssign_operation (GALGAS_string ("trueFalse")  COMMA_SOURCE_FILE ("template_invocation.galgas", 31)) ;
  result_outAllowedFunctionSet.addAssign_operation (GALGAS_string ("yesNo")  COMMA_SOURCE_FILE ("template_invocation.galgas", 32)) ;
//---
  return result_outAllowedFunctionSet ;
}



//----------------------------------------------------------------------------------------------------------------------
//  Function implementation                                                                                            *
//----------------------------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_allowedFunctions = false ;
static GALGAS_stringset gOnceFunctionResult_allowedFunctions ;

//----------------------------------------------------------------------------------------------------------------------

GALGAS_stringset function_allowedFunctions (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_allowedFunctions) {
    gOnceFunctionResult_allowedFunctions = onceFunction_allowedFunctions (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_allowedFunctions = true ;
  }
  return gOnceFunctionResult_allowedFunctions ;
}

//----------------------------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_allowedFunctions (void) {
  gOnceFunctionResult_allowedFunctions.drop () ;
}

//----------------------------------------------------------------------------------------------------------------------

C_PrologueEpilogue gEpilogueForOnceFunction_allowedFunctions (NULL,
                                                              releaseOnceFunctionResult_allowedFunctions) ;

//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                                             *
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_allowedFunctions [1] = {
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_allowedFunctions (C_Compiler * inCompiler,
                                                                 const cObjectArray & /* inEffectiveParameterArray */,
                                                                 const GALGAS_location & /* inErrorLocation */
                                                                 COMMA_LOCATION_ARGS) {
  return function_allowedFunctions (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_allowedFunctions ("allowedFunctions",
                                                                  functionWithGenericHeader_allowedFunctions,
                                                                  & kTypeDescriptor_GALGAS_stringset,
                                                                  0,
                                                                  functionArgs_allowedFunctions) ;

//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//                                                Function 'fullPrefix'                                                *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

GALGAS_string function_fullPrefix (const GALGAS_TfieldMap & constinArgument_vars,
                                   const GALGAS_lstring & constinArgument_prefix,
                                   C_Compiler * inCompiler
                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_full ; // Returned variable
  GALGAS_string var_stringPrefix_1038 = constinArgument_prefix.getter_string (SOURCE_FILE ("template_invocation.galgas", 40)) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, var_stringPrefix_1038.objectCompare (GALGAS_string ("compiler"))).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_Ttype var_type_1109 ;
    GALGAS_Tvalue var_value_1127 ;
    constinArgument_vars.method_searchKey (function_lstringWith (GALGAS_string ("COMPILER"), inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 44)), var_type_1109, var_value_1127, inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 44)) ;
    var_stringPrefix_1038.plusAssign_operation(GALGAS_string ("/").add_operation (var_value_1127.getter_mStringValue (SOURCE_FILE ("template_invocation.galgas", 45)), inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 45)), inCompiler  COMMA_SOURCE_FILE ("template_invocation.galgas", 45)) ;
  }else if (kBoolFalse == test_0) {
    const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, var_stringPrefix_1038.objectCompare (GALGAS_string ("linker"))).boolEnum () ;
    if (kBoolTrue == test_1) {
      GALGAS_Ttype var_type_1288 ;
      GALGAS_Tvalue var_value_1306 ;
      constinArgument_vars.method_searchKey (function_lstringWith (GALGAS_string ("LINKER"), inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 49)), var_type_1288, var_value_1306, inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 49)) ;
      var_stringPrefix_1038.plusAssign_operation(GALGAS_string ("/").add_operation (var_value_1306.getter_mStringValue (SOURCE_FILE ("template_invocation.galgas", 50)), inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 50)), inCompiler  COMMA_SOURCE_FILE ("template_invocation.galgas", 50)) ;
    }else if (kBoolFalse == test_1) {
      const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, var_stringPrefix_1038.objectCompare (GALGAS_string ("assembler"))).boolEnum () ;
      if (kBoolTrue == test_2) {
        GALGAS_Ttype var_type_1468 ;
        GALGAS_Tvalue var_value_1486 ;
        constinArgument_vars.method_searchKey (function_lstringWith (GALGAS_string ("ASSEMBLER"), inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 54)), var_type_1468, var_value_1486, inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 54)) ;
        var_stringPrefix_1038.plusAssign_operation(GALGAS_string ("/").add_operation (var_value_1486.getter_mStringValue (SOURCE_FILE ("template_invocation.galgas", 55)), inCompiler COMMA_SOURCE_FILE ("template_invocation.galgas", 55)), inCompiler  COMMA_SOURCE_FILE ("template_invocation.galgas", 55)) ;
      }else if (kBoolFalse == test_2) {
        const enumGalgasBool test_3 = GALGAS_bool (kIsEqual, var_stringPrefix_1038.objectCompare (GALGAS_string ("ROOT"))).boolEnum () ;
        if (kBoolTrue == test_3) {
          var_stringPrefix_1038 = GALGAS_string::makeEmptyString () ;
        }
      }
    }
  }
  result_full = var_stringPrefix_1038 ;
//---
  return result_full ;
}


//----------------------------------------------------------------------------------------------------------------------
//  Function introspection                                                                                             *
//----------------------------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_fullPrefix [3] = {
  & kTypeDescriptor_GALGAS_TfieldMap,
  & kTypeDescriptor_GALGAS_lstring,
  NULL
} ;

//----------------------------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_fullPrefix (C_Compiler * inCompiler,
                                                           const cObjectArray & inEffectiveParameterArray,
                                                           const GALGAS_location & /* §§ inErrorLocation */
                                                           COMMA_LOCATION_ARGS) {
  const GALGAS_TfieldMap operand0 = GALGAS_TfieldMap::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                     inCompiler
                                                                     COMMA_THERE) ;
  const GALGAS_lstring operand1 = GALGAS_lstring::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  return function_fullPrefix (operand0,
                              operand1,
                              inCompiler
                              COMMA_THERE).getter_object (THERE) ;
}

//----------------------------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_fullPrefix ("fullPrefix",
                                                            functionWithGenericHeader_fullPrefix,
                                                            & kTypeDescriptor_GALGAS_string,
                                                            2,
                                                            functionArgs_fullPrefix) ;

