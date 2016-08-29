#include "galgas2/C_Compiler.h"
#include "galgas2/C_galgas_io.h"
#include "galgas2/C_galgas_CLI_Options.h"
#include "utilities/C_PrologueEpilogue.h"

//---------------------------------------------------------------------------------------------------------------------*

#include "all-declarations-3.h"


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

static const int16_t gProductions_gtl_grammar [] = {
// At index 0 : <gtl_expression>, in file 'gtl_expression_parser.ggs', line 33
  NONTERMINAL (10) // <gtl_relation_term>
, NONTERMINAL (42) // <select_gtl_5F_expression_5F_parser_0>
, END_PRODUCTION
// At index 3 : <gtl_variable>, in file 'gtl_expression_parser.ggs', line 667
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, NONTERMINAL (63) // <select_gtl_5F_expression_5F_parser_21>
, NONTERMINAL (62) // <select_gtl_5F_expression_5F_parser_20>
, END_PRODUCTION
// At index 7 : <gtl_variable_or_here>, in file 'gtl_expression_parser.ggs', line 702
, NONTERMINAL (66) // <select_gtl_5F_expression_5F_parser_24>
, END_PRODUCTION
// At index 9 : <gtl_import>, in file 'gtl_instruction_parser.ggs', line 367
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_import) // $import$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_string) // $string$
, END_PRODUCTION
// At index 12 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 40
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_let) // $let$
, NONTERMINAL (1) // <gtl_variable>
, NONTERMINAL (70) // <select_gtl_5F_instruction_5F_parser_0>
, END_PRODUCTION
// At index 16 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 154
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_unlet) // $unlet$
, NONTERMINAL (1) // <gtl_variable>
, END_PRODUCTION
// At index 19 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 167
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_error) // $error$
, NONTERMINAL (2) // <gtl_variable_or_here>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A_) // $:$
, NONTERMINAL (0) // <gtl_expression>
, END_PRODUCTION
// At index 24 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 185
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_warning) // $warning$
, NONTERMINAL (2) // <gtl_variable_or_here>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A_) // $:$
, NONTERMINAL (0) // <gtl_expression>
, END_PRODUCTION
// At index 29 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 203
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_print) // $print$
, NONTERMINAL (0) // <gtl_expression>
, END_PRODUCTION
// At index 32 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 218
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_println) // $println$
, NONTERMINAL (71) // <select_gtl_5F_instruction_5F_parser_1>
, END_PRODUCTION
// At index 35 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 241
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_display) // $display$
, NONTERMINAL (1) // <gtl_variable>
, END_PRODUCTION
// At index 38 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 255
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_sort) // $sort$
, NONTERMINAL (1) // <gtl_variable>
, NONTERMINAL (72) // <select_gtl_5F_instruction_5F_parser_2>
, END_PRODUCTION
// At index 42 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 288
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_tab) // $tab$
, NONTERMINAL (0) // <gtl_expression>
, END_PRODUCTION
// At index 45 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 302
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_variables) // $variables$
, END_PRODUCTION
// At index 47 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 314
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_libraries) // $libraries$
, END_PRODUCTION
// At index 49 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 325
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5B__21_) // $[!$
, NONTERMINAL (1) // <gtl_variable>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, NONTERMINAL (74) // <select_gtl_5F_instruction_5F_parser_4>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5D_) // $]$
, END_PRODUCTION
// At index 55 : <gtl_argument_list>, in file 'gtl_expression_parser.ggs', line 716
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__28_) // $($
, NONTERMINAL (67) // <select_gtl_5F_expression_5F_parser_25>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__29_) // $)$
, END_PRODUCTION
// At index 59 : <gtl_start_symbol>, in file 'gtl_parser.ggs', line 50
, NONTERMINAL (16) // <select_gtl_5F_parser_0>
, NONTERMINAL (7) // <gtl_template_instruction_list>
, END_PRODUCTION
// At index 62 : <gtl_template_instruction_list>, in file 'gtl_parser.ggs', line 63
, NONTERMINAL (17) // <select_gtl_5F_parser_1>
, END_PRODUCTION
// At index 64 : <gtl_template_instruction>, in file 'gtl_parser.ggs', line 90
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__21_) // $!$
, NONTERMINAL (0) // <gtl_expression>
, END_PRODUCTION
// At index 67 : <gtl_template_instruction>, in file 'gtl_parser.ggs', line 108
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_write) // $write$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_to) // $to$
, NONTERMINAL (18) // <select_gtl_5F_parser_2>
, NONTERMINAL (0) // <gtl_expression>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A_) // $:$
, NONTERMINAL (7) // <gtl_template_instruction_list>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) // $end$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_write) // $write$
, END_PRODUCTION
// At index 76 : <gtl_template_instruction>, in file 'gtl_parser.ggs', line 128
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_template) // $template$
, NONTERMINAL (19) // <select_gtl_5F_parser_3>
, NONTERMINAL (22) // <select_gtl_5F_parser_6>
, END_PRODUCTION
// At index 80 : <gtl_template_instruction>, in file 'gtl_parser.ggs', line 183
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3F_) // $?$
, NONTERMINAL (1) // <gtl_variable>
, END_PRODUCTION
// At index 83 : <gtl_template_instruction>, in file 'gtl_parser.ggs', line 196
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_if) // $if$
, NONTERMINAL (0) // <gtl_expression>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_then) // $then$
, NONTERMINAL (7) // <gtl_template_instruction_list>
, NONTERMINAL (26) // <select_gtl_5F_parser_10>
, NONTERMINAL (27) // <select_gtl_5F_parser_11>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) // $end$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_if) // $if$
, END_PRODUCTION
// At index 92 : <gtl_template_instruction>, in file 'gtl_parser.ggs', line 228
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_foreach) // $foreach$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, NONTERMINAL (28) // <select_gtl_5F_parser_12>
, NONTERMINAL (29) // <select_gtl_5F_parser_13>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_in) // $in$
, NONTERMINAL (0) // <gtl_expression>
, NONTERMINAL (30) // <select_gtl_5F_parser_14>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_do) // $do$
, NONTERMINAL (7) // <gtl_template_instruction_list>
, NONTERMINAL (31) // <select_gtl_5F_parser_15>
, NONTERMINAL (32) // <select_gtl_5F_parser_16>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) // $end$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_foreach) // $foreach$
, END_PRODUCTION
// At index 106 : <gtl_template_instruction>, in file 'gtl_parser.ggs', line 289
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_for) // $for$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_in) // $in$
, NONTERMINAL (0) // <gtl_expression>
, NONTERMINAL (33) // <select_gtl_5F_parser_17>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_do) // $do$
, NONTERMINAL (7) // <gtl_template_instruction_list>
, NONTERMINAL (34) // <select_gtl_5F_parser_18>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) // $end$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_for) // $for$
, END_PRODUCTION
// At index 117 : <gtl_template_instruction>, in file 'gtl_parser.ggs', line 331
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_loop) // $loop$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_from) // $from$
, NONTERMINAL (0) // <gtl_expression>
, NONTERMINAL (35) // <select_gtl_5F_parser_19>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_to) // $to$
, NONTERMINAL (0) // <gtl_expression>
, NONTERMINAL (36) // <select_gtl_5F_parser_20>
, NONTERMINAL (37) // <select_gtl_5F_parser_21>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_do) // $do$
, NONTERMINAL (7) // <gtl_template_instruction_list>
, NONTERMINAL (38) // <select_gtl_5F_parser_22>
, NONTERMINAL (39) // <select_gtl_5F_parser_23>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) // $end$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_loop) // $loop$
, END_PRODUCTION
// At index 133 : <gtl_template_instruction>, in file 'gtl_parser.ggs', line 397
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_repeat) // $repeat$
, NONTERMINAL (40) // <select_gtl_5F_parser_24>
, NONTERMINAL (7) // <gtl_template_instruction_list>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_while) // $while$
, NONTERMINAL (0) // <gtl_expression>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_do) // $do$
, NONTERMINAL (7) // <gtl_template_instruction_list>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) // $end$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_repeat) // $repeat$
, END_PRODUCTION
// At index 143 : <gtl_template_instruction>, in file 'gtl_parser.ggs', line 430
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_input) // $input$
, NONTERMINAL (5) // <gtl_argument_list>
, END_PRODUCTION
// At index 146 : <gtl_file_name>, in file 'gtl_parser.ggs', line 443
, NONTERMINAL (41) // <select_gtl_5F_parser_25>
, END_PRODUCTION
// At index 148 : <gtl_relation_term>, in file 'gtl_expression_parser.ggs', line 53
, NONTERMINAL (11) // <gtl_relation_factor>
, NONTERMINAL (43) // <select_gtl_5F_expression_5F_parser_1>
, END_PRODUCTION
// At index 151 : <gtl_relation_factor>, in file 'gtl_expression_parser.ggs', line 69
, NONTERMINAL (12) // <gtl_simple_expression>
, NONTERMINAL (44) // <select_gtl_5F_expression_5F_parser_2>
, END_PRODUCTION
// At index 154 : <gtl_simple_expression>, in file 'gtl_expression_parser.ggs', line 117
, NONTERMINAL (13) // <gtl_term>
, NONTERMINAL (45) // <select_gtl_5F_expression_5F_parser_3>
, END_PRODUCTION
// At index 157 : <gtl_term>, in file 'gtl_expression_parser.ggs', line 162
, NONTERMINAL (14) // <gtl_factor>
, NONTERMINAL (46) // <select_gtl_5F_expression_5F_parser_4>
, END_PRODUCTION
// At index 160 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 192
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__28_) // $($
, NONTERMINAL (0) // <gtl_expression>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__29_) // $)$
, END_PRODUCTION
// At index 164 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 208
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_not) // $not$
, NONTERMINAL (14) // <gtl_factor>
, END_PRODUCTION
// At index 167 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 220
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__7E_) // $~$
, NONTERMINAL (14) // <gtl_factor>
, END_PRODUCTION
// At index 170 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 232
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2D_) // $-$
, NONTERMINAL (14) // <gtl_factor>
, END_PRODUCTION
// At index 173 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 244
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2B_) // $+$
, NONTERMINAL (14) // <gtl_factor>
, END_PRODUCTION
// At index 176 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 256
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_yes) // $yes$
, END_PRODUCTION
// At index 178 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 269
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_no) // $no$
, END_PRODUCTION
// At index 180 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 282
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint) // $signed_literal_integer_bigint$
, END_PRODUCTION
// At index 182 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 295
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_literal_5F_double) // $literal_double$
, END_PRODUCTION
// At index 184 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 308
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_string) // $string$
, END_PRODUCTION
// At index 186 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 321
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_literal_5F_char) // $literal_char$
, END_PRODUCTION
// At index 188 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 335
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5B_) // $[$
, NONTERMINAL (0) // <gtl_expression>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, NONTERMINAL (47) // <select_gtl_5F_expression_5F_parser_5>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5D_) // $]$
, END_PRODUCTION
// At index 194 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 369
, NONTERMINAL (1) // <gtl_variable>
, NONTERMINAL (49) // <select_gtl_5F_expression_5F_parser_7>
, END_PRODUCTION
// At index 197 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 401
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_exists) // $exists$
, NONTERMINAL (1) // <gtl_variable>
, NONTERMINAL (52) // <select_gtl_5F_expression_5F_parser_10>
, END_PRODUCTION
// At index 201 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 420
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_typeof) // $typeof$
, NONTERMINAL (1) // <gtl_variable>
, END_PRODUCTION
// At index 204 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 429
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_true) // $true$
, END_PRODUCTION
// At index 206 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 445
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_false) // $false$
, END_PRODUCTION
// At index 208 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 461
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_literal_5F_enum) // $literal_enum$
, END_PRODUCTION
// At index 210 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 477
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__40_) // $@$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, END_PRODUCTION
// At index 213 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 514
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_emptylist) // $emptylist$
, END_PRODUCTION
// At index 215 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 533
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_emptymap) // $emptymap$
, END_PRODUCTION
// At index 217 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 552
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_mapof) // $mapof$
, NONTERMINAL (0) // <gtl_expression>
, NONTERMINAL (53) // <select_gtl_5F_expression_5F_parser_11>
, END_PRODUCTION
// At index 221 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 576
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_listof) // $listof$
, NONTERMINAL (0) // <gtl_expression>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) // $end$
, END_PRODUCTION
// At index 225 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 587
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__40__28_) // $@($
, NONTERMINAL (54) // <select_gtl_5F_expression_5F_parser_12>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__29_) // $)$
, END_PRODUCTION
// At index 229 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 606
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__40__5B_) // $@[$
, NONTERMINAL (56) // <select_gtl_5F_expression_5F_parser_14>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5D_) // $]$
, END_PRODUCTION
// At index 233 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 627
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__40__7B_) // $@{$
, NONTERMINAL (58) // <select_gtl_5F_expression_5F_parser_16>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__7D_) // $}$
, END_PRODUCTION
// At index 237 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 648
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__40__21_) // $@!$
, NONTERMINAL (60) // <select_gtl_5F_expression_5F_parser_18>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__21_) // $!$
, END_PRODUCTION
// At index 241 : <gtl_sorting_order>, in file 'gtl_instruction_parser.ggs', line 354
, NONTERMINAL (76) // <select_gtl_5F_instruction_5F_parser_6>
, END_PRODUCTION
//---- Added productions from 'select' and 'repeat' instructions
// At index 243 : <select_gtl_5F_parser_0>, in file 'gtl_parser.ggs', line 55
, END_PRODUCTION
// At index 244 : <select_gtl_5F_parser_0>, in file 'gtl_parser.ggs', line 55
, NONTERMINAL (3) // <gtl_import>
, NONTERMINAL (16) // <select_gtl_5F_parser_0>
, END_PRODUCTION
// At index 247 : <select_gtl_5F_parser_1>, in file 'gtl_parser.ggs', line 67
, END_PRODUCTION
// At index 248 : <select_gtl_5F_parser_1>, in file 'gtl_parser.ggs', line 67
, NONTERMINAL (8) // <gtl_template_instruction>
, NONTERMINAL (17) // <select_gtl_5F_parser_1>
, END_PRODUCTION
// At index 251 : <select_gtl_5F_parser_1>, in file 'gtl_parser.ggs', line 67
, NONTERMINAL (4) // <gtl_simple_instruction>
, NONTERMINAL (17) // <select_gtl_5F_parser_1>
, END_PRODUCTION
// At index 254 : <select_gtl_5F_parser_2>, in file 'gtl_parser.ggs', line 112
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_executable) // $executable$
, END_PRODUCTION
// At index 256 : <select_gtl_5F_parser_2>, in file 'gtl_parser.ggs', line 112
, END_PRODUCTION
// At index 257 : <select_gtl_5F_parser_3>, in file 'gtl_parser.ggs', line 138
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__28_) // $($
, NONTERMINAL (20) // <select_gtl_5F_parser_4>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__29_) // $)$
, END_PRODUCTION
// At index 261 : <select_gtl_5F_parser_3>, in file 'gtl_parser.ggs', line 138
, END_PRODUCTION
// At index 262 : <select_gtl_5F_parser_4>, in file 'gtl_parser.ggs', line 141
, NONTERMINAL (0) // <gtl_expression>
, NONTERMINAL (21) // <select_gtl_5F_parser_5>
, END_PRODUCTION
// At index 265 : <select_gtl_5F_parser_4>, in file 'gtl_parser.ggs', line 141
, END_PRODUCTION
// At index 266 : <select_gtl_5F_parser_5>, in file 'gtl_parser.ggs', line 142
, END_PRODUCTION
// At index 267 : <select_gtl_5F_parser_5>, in file 'gtl_parser.ggs', line 142
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) // $,$
, NONTERMINAL (0) // <gtl_expression>
, NONTERMINAL (21) // <select_gtl_5F_parser_5>
, END_PRODUCTION
// At index 271 : <select_gtl_5F_parser_6>, in file 'gtl_parser.ggs', line 152
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_if) // $if$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_exists) // $exists$
, NONTERMINAL (9) // <gtl_file_name>
, NONTERMINAL (23) // <select_gtl_5F_parser_7>
, NONTERMINAL (24) // <select_gtl_5F_parser_8>
, END_PRODUCTION
// At index 277 : <select_gtl_5F_parser_6>, in file 'gtl_parser.ggs', line 152
, NONTERMINAL (9) // <gtl_file_name>
, NONTERMINAL (25) // <select_gtl_5F_parser_9>
, END_PRODUCTION
// At index 280 : <select_gtl_5F_parser_7>, in file 'gtl_parser.ggs', line 156
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_in) // $in$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, END_PRODUCTION
// At index 283 : <select_gtl_5F_parser_7>, in file 'gtl_parser.ggs', line 156
, END_PRODUCTION
// At index 284 : <select_gtl_5F_parser_8>, in file 'gtl_parser.ggs', line 159
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_or) // $or$
, NONTERMINAL (7) // <gtl_template_instruction_list>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) // $end$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_template) // $template$
, END_PRODUCTION
// At index 289 : <select_gtl_5F_parser_8>, in file 'gtl_parser.ggs', line 159
, END_PRODUCTION
// At index 290 : <select_gtl_5F_parser_9>, in file 'gtl_parser.ggs', line 166
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_in) // $in$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, END_PRODUCTION
// At index 293 : <select_gtl_5F_parser_9>, in file 'gtl_parser.ggs', line 166
, END_PRODUCTION
// At index 294 : <select_gtl_5F_parser_10>, in file 'gtl_parser.ggs', line 202
, END_PRODUCTION
// At index 295 : <select_gtl_5F_parser_10>, in file 'gtl_parser.ggs', line 202
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_elsif) // $elsif$
, NONTERMINAL (0) // <gtl_expression>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_then) // $then$
, NONTERMINAL (7) // <gtl_template_instruction_list>
, NONTERMINAL (26) // <select_gtl_5F_parser_10>
, END_PRODUCTION
// At index 301 : <select_gtl_5F_parser_11>, in file 'gtl_parser.ggs', line 212
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_else) // $else$
, NONTERMINAL (7) // <gtl_template_instruction_list>
, END_PRODUCTION
// At index 304 : <select_gtl_5F_parser_11>, in file 'gtl_parser.ggs', line 212
, END_PRODUCTION
// At index 305 : <select_gtl_5F_parser_12>, in file 'gtl_parser.ggs', line 239
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) // $,$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, END_PRODUCTION
// At index 308 : <select_gtl_5F_parser_12>, in file 'gtl_parser.ggs', line 239
, END_PRODUCTION
// At index 309 : <select_gtl_5F_parser_13>, in file 'gtl_parser.ggs', line 245
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__28_) // $($
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__29_) // $)$
, END_PRODUCTION
// At index 313 : <select_gtl_5F_parser_13>, in file 'gtl_parser.ggs', line 245
, END_PRODUCTION
// At index 314 : <select_gtl_5F_parser_14>, in file 'gtl_parser.ggs', line 253
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_before) // $before$
, NONTERMINAL (7) // <gtl_template_instruction_list>
, END_PRODUCTION
// At index 317 : <select_gtl_5F_parser_14>, in file 'gtl_parser.ggs', line 253
, END_PRODUCTION
// At index 318 : <select_gtl_5F_parser_15>, in file 'gtl_parser.ggs', line 261
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_between) // $between$
, NONTERMINAL (7) // <gtl_template_instruction_list>
, END_PRODUCTION
// At index 321 : <select_gtl_5F_parser_15>, in file 'gtl_parser.ggs', line 261
, END_PRODUCTION
// At index 322 : <select_gtl_5F_parser_16>, in file 'gtl_parser.ggs', line 266
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_after) // $after$
, NONTERMINAL (7) // <gtl_template_instruction_list>
, END_PRODUCTION
// At index 325 : <select_gtl_5F_parser_16>, in file 'gtl_parser.ggs', line 266
, END_PRODUCTION
// At index 326 : <select_gtl_5F_parser_17>, in file 'gtl_parser.ggs', line 302
, END_PRODUCTION
// At index 327 : <select_gtl_5F_parser_17>, in file 'gtl_parser.ggs', line 302
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) // $,$
, NONTERMINAL (0) // <gtl_expression>
, NONTERMINAL (33) // <select_gtl_5F_parser_17>
, END_PRODUCTION
// At index 331 : <select_gtl_5F_parser_18>, in file 'gtl_parser.ggs', line 312
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_between) // $between$
, NONTERMINAL (7) // <gtl_template_instruction_list>
, END_PRODUCTION
// At index 334 : <select_gtl_5F_parser_18>, in file 'gtl_parser.ggs', line 312
, END_PRODUCTION
// At index 335 : <select_gtl_5F_parser_19>, in file 'gtl_parser.ggs', line 347
, END_PRODUCTION
// At index 336 : <select_gtl_5F_parser_19>, in file 'gtl_parser.ggs', line 347
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_up) // $up$
, END_PRODUCTION
// At index 338 : <select_gtl_5F_parser_19>, in file 'gtl_parser.ggs', line 347
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_down) // $down$
, END_PRODUCTION
// At index 340 : <select_gtl_5F_parser_20>, in file 'gtl_parser.ggs', line 355
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_step) // $step$
, NONTERMINAL (0) // <gtl_expression>
, END_PRODUCTION
// At index 343 : <select_gtl_5F_parser_20>, in file 'gtl_parser.ggs', line 355
, END_PRODUCTION
// At index 344 : <select_gtl_5F_parser_21>, in file 'gtl_parser.ggs', line 360
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_before) // $before$
, NONTERMINAL (7) // <gtl_template_instruction_list>
, END_PRODUCTION
// At index 347 : <select_gtl_5F_parser_21>, in file 'gtl_parser.ggs', line 360
, END_PRODUCTION
// At index 348 : <select_gtl_5F_parser_22>, in file 'gtl_parser.ggs', line 368
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_between) // $between$
, NONTERMINAL (7) // <gtl_template_instruction_list>
, END_PRODUCTION
// At index 351 : <select_gtl_5F_parser_22>, in file 'gtl_parser.ggs', line 368
, END_PRODUCTION
// At index 352 : <select_gtl_5F_parser_23>, in file 'gtl_parser.ggs', line 373
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_after) // $after$
, NONTERMINAL (7) // <gtl_template_instruction_list>
, END_PRODUCTION
// At index 355 : <select_gtl_5F_parser_23>, in file 'gtl_parser.ggs', line 373
, END_PRODUCTION
// At index 356 : <select_gtl_5F_parser_24>, in file 'gtl_parser.ggs', line 402
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__28_) // $($
, NONTERMINAL (0) // <gtl_expression>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__29_) // $)$
, END_PRODUCTION
// At index 360 : <select_gtl_5F_parser_24>, in file 'gtl_parser.ggs', line 402
, END_PRODUCTION
// At index 361 : <select_gtl_5F_parser_25>, in file 'gtl_parser.ggs', line 446
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, END_PRODUCTION
// At index 363 : <select_gtl_5F_parser_25>, in file 'gtl_parser.ggs', line 446
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_from) // $from$
, NONTERMINAL (0) // <gtl_expression>
, END_PRODUCTION
// At index 366 : <select_gtl_5F_expression_5F_parser_0>, in file 'gtl_expression_parser.ggs', line 37
, END_PRODUCTION
// At index 367 : <select_gtl_5F_expression_5F_parser_0>, in file 'gtl_expression_parser.ggs', line 37
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__7C_) // $|$
, NONTERMINAL (10) // <gtl_relation_term>
, NONTERMINAL (42) // <select_gtl_5F_expression_5F_parser_0>
, END_PRODUCTION
// At index 371 : <select_gtl_5F_expression_5F_parser_0>, in file 'gtl_expression_parser.ggs', line 37
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5E_) // $^$
, NONTERMINAL (10) // <gtl_relation_term>
, NONTERMINAL (42) // <select_gtl_5F_expression_5F_parser_0>
, END_PRODUCTION
// At index 375 : <select_gtl_5F_expression_5F_parser_1>, in file 'gtl_expression_parser.ggs', line 57
, END_PRODUCTION
// At index 376 : <select_gtl_5F_expression_5F_parser_1>, in file 'gtl_expression_parser.ggs', line 57
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__26_) // $&$
, NONTERMINAL (11) // <gtl_relation_factor>
, NONTERMINAL (43) // <select_gtl_5F_expression_5F_parser_1>
, END_PRODUCTION
// At index 380 : <select_gtl_5F_expression_5F_parser_2>, in file 'gtl_expression_parser.ggs', line 73
, END_PRODUCTION
// At index 381 : <select_gtl_5F_expression_5F_parser_2>, in file 'gtl_expression_parser.ggs', line 73
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3D__3D_) // $==$
, NONTERMINAL (12) // <gtl_simple_expression>
, END_PRODUCTION
// At index 384 : <select_gtl_5F_expression_5F_parser_2>, in file 'gtl_expression_parser.ggs', line 73
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__21__3D_) // $!=$
, NONTERMINAL (12) // <gtl_simple_expression>
, END_PRODUCTION
// At index 387 : <select_gtl_5F_expression_5F_parser_2>, in file 'gtl_expression_parser.ggs', line 73
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3C__3D_) // $<=$
, NONTERMINAL (12) // <gtl_simple_expression>
, END_PRODUCTION
// At index 390 : <select_gtl_5F_expression_5F_parser_2>, in file 'gtl_expression_parser.ggs', line 73
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3E__3D_) // $>=$
, NONTERMINAL (12) // <gtl_simple_expression>
, END_PRODUCTION
// At index 393 : <select_gtl_5F_expression_5F_parser_2>, in file 'gtl_expression_parser.ggs', line 73
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3E_) // $>$
, NONTERMINAL (12) // <gtl_simple_expression>
, END_PRODUCTION
// At index 396 : <select_gtl_5F_expression_5F_parser_2>, in file 'gtl_expression_parser.ggs', line 73
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3C_) // $<$
, NONTERMINAL (12) // <gtl_simple_expression>
, END_PRODUCTION
// At index 399 : <select_gtl_5F_expression_5F_parser_3>, in file 'gtl_expression_parser.ggs', line 121
, END_PRODUCTION
// At index 400 : <select_gtl_5F_expression_5F_parser_3>, in file 'gtl_expression_parser.ggs', line 121
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3C__3C_) // $<<$
, NONTERMINAL (13) // <gtl_term>
, NONTERMINAL (45) // <select_gtl_5F_expression_5F_parser_3>
, END_PRODUCTION
// At index 404 : <select_gtl_5F_expression_5F_parser_3>, in file 'gtl_expression_parser.ggs', line 121
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3E__3E_) // $>>$
, NONTERMINAL (13) // <gtl_term>
, NONTERMINAL (45) // <select_gtl_5F_expression_5F_parser_3>
, END_PRODUCTION
// At index 408 : <select_gtl_5F_expression_5F_parser_3>, in file 'gtl_expression_parser.ggs', line 121
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2B_) // $+$
, NONTERMINAL (13) // <gtl_term>
, NONTERMINAL (45) // <select_gtl_5F_expression_5F_parser_3>
, END_PRODUCTION
// At index 412 : <select_gtl_5F_expression_5F_parser_3>, in file 'gtl_expression_parser.ggs', line 121
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2E_) // $.$
, NONTERMINAL (13) // <gtl_term>
, NONTERMINAL (45) // <select_gtl_5F_expression_5F_parser_3>
, END_PRODUCTION
// At index 416 : <select_gtl_5F_expression_5F_parser_3>, in file 'gtl_expression_parser.ggs', line 121
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2D_) // $-$
, NONTERMINAL (13) // <gtl_term>
, NONTERMINAL (45) // <select_gtl_5F_expression_5F_parser_3>
, END_PRODUCTION
// At index 420 : <select_gtl_5F_expression_5F_parser_4>, in file 'gtl_expression_parser.ggs', line 166
, END_PRODUCTION
// At index 421 : <select_gtl_5F_expression_5F_parser_4>, in file 'gtl_expression_parser.ggs', line 166
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2A_) // $*$
, NONTERMINAL (14) // <gtl_factor>
, NONTERMINAL (46) // <select_gtl_5F_expression_5F_parser_4>
, END_PRODUCTION
// At index 425 : <select_gtl_5F_expression_5F_parser_4>, in file 'gtl_expression_parser.ggs', line 166
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2F_) // $/$
, NONTERMINAL (14) // <gtl_factor>
, NONTERMINAL (46) // <select_gtl_5F_expression_5F_parser_4>
, END_PRODUCTION
// At index 429 : <select_gtl_5F_expression_5F_parser_4>, in file 'gtl_expression_parser.ggs', line 166
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_mod) // $mod$
, NONTERMINAL (14) // <gtl_factor>
, NONTERMINAL (46) // <select_gtl_5F_expression_5F_parser_4>
, END_PRODUCTION
// At index 433 : <select_gtl_5F_expression_5F_parser_5>, in file 'gtl_expression_parser.ggs', line 348
, END_PRODUCTION
// At index 434 : <select_gtl_5F_expression_5F_parser_5>, in file 'gtl_expression_parser.ggs', line 348
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A_) // $:$
, NONTERMINAL (0) // <gtl_expression>
, NONTERMINAL (48) // <select_gtl_5F_expression_5F_parser_6>
, END_PRODUCTION
// At index 438 : <select_gtl_5F_expression_5F_parser_6>, in file 'gtl_expression_parser.ggs', line 351
, END_PRODUCTION
// At index 439 : <select_gtl_5F_expression_5F_parser_6>, in file 'gtl_expression_parser.ggs', line 351
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) // $,$
, NONTERMINAL (0) // <gtl_expression>
, NONTERMINAL (48) // <select_gtl_5F_expression_5F_parser_6>
, END_PRODUCTION
// At index 443 : <select_gtl_5F_expression_5F_parser_7>, in file 'gtl_expression_parser.ggs', line 373
, END_PRODUCTION
// At index 444 : <select_gtl_5F_expression_5F_parser_7>, in file 'gtl_expression_parser.ggs', line 373
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__28_) // $($
, NONTERMINAL (50) // <select_gtl_5F_expression_5F_parser_8>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__29_) // $)$
, END_PRODUCTION
// At index 448 : <select_gtl_5F_expression_5F_parser_8>, in file 'gtl_expression_parser.ggs', line 381
, NONTERMINAL (0) // <gtl_expression>
, NONTERMINAL (51) // <select_gtl_5F_expression_5F_parser_9>
, END_PRODUCTION
// At index 451 : <select_gtl_5F_expression_5F_parser_8>, in file 'gtl_expression_parser.ggs', line 381
, END_PRODUCTION
// At index 452 : <select_gtl_5F_expression_5F_parser_9>, in file 'gtl_expression_parser.ggs', line 382
, END_PRODUCTION
// At index 453 : <select_gtl_5F_expression_5F_parser_9>, in file 'gtl_expression_parser.ggs', line 382
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) // $,$
, NONTERMINAL (0) // <gtl_expression>
, NONTERMINAL (51) // <select_gtl_5F_expression_5F_parser_9>
, END_PRODUCTION
// At index 457 : <select_gtl_5F_expression_5F_parser_10>, in file 'gtl_expression_parser.ggs', line 405
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_default) // $default$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__28_) // $($
, NONTERMINAL (0) // <gtl_expression>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__29_) // $)$
, END_PRODUCTION
// At index 462 : <select_gtl_5F_expression_5F_parser_10>, in file 'gtl_expression_parser.ggs', line 405
, END_PRODUCTION
// At index 463 : <select_gtl_5F_expression_5F_parser_11>, in file 'gtl_expression_parser.ggs', line 557
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_by) // $by$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, END_PRODUCTION
// At index 466 : <select_gtl_5F_expression_5F_parser_11>, in file 'gtl_expression_parser.ggs', line 557
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) // $end$
, END_PRODUCTION
// At index 468 : <select_gtl_5F_expression_5F_parser_12>, in file 'gtl_expression_parser.ggs', line 592
, NONTERMINAL (0) // <gtl_expression>
, NONTERMINAL (55) // <select_gtl_5F_expression_5F_parser_13>
, END_PRODUCTION
// At index 471 : <select_gtl_5F_expression_5F_parser_12>, in file 'gtl_expression_parser.ggs', line 592
, END_PRODUCTION
// At index 472 : <select_gtl_5F_expression_5F_parser_13>, in file 'gtl_expression_parser.ggs', line 593
, END_PRODUCTION
// At index 473 : <select_gtl_5F_expression_5F_parser_13>, in file 'gtl_expression_parser.ggs', line 593
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) // $,$
, NONTERMINAL (0) // <gtl_expression>
, NONTERMINAL (55) // <select_gtl_5F_expression_5F_parser_13>
, END_PRODUCTION
// At index 477 : <select_gtl_5F_expression_5F_parser_14>, in file 'gtl_expression_parser.ggs', line 611
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_string) // $string$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A_) // $:$
, NONTERMINAL (0) // <gtl_expression>
, NONTERMINAL (57) // <select_gtl_5F_expression_5F_parser_15>
, END_PRODUCTION
// At index 482 : <select_gtl_5F_expression_5F_parser_14>, in file 'gtl_expression_parser.ggs', line 611
, END_PRODUCTION
// At index 483 : <select_gtl_5F_expression_5F_parser_15>, in file 'gtl_expression_parser.ggs', line 612
, END_PRODUCTION
// At index 484 : <select_gtl_5F_expression_5F_parser_15>, in file 'gtl_expression_parser.ggs', line 612
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) // $,$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_string) // $string$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A_) // $:$
, NONTERMINAL (0) // <gtl_expression>
, NONTERMINAL (57) // <select_gtl_5F_expression_5F_parser_15>
, END_PRODUCTION
// At index 490 : <select_gtl_5F_expression_5F_parser_16>, in file 'gtl_expression_parser.ggs', line 632
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A_) // $:$
, NONTERMINAL (0) // <gtl_expression>
, NONTERMINAL (59) // <select_gtl_5F_expression_5F_parser_17>
, END_PRODUCTION
// At index 495 : <select_gtl_5F_expression_5F_parser_16>, in file 'gtl_expression_parser.ggs', line 632
, END_PRODUCTION
// At index 496 : <select_gtl_5F_expression_5F_parser_17>, in file 'gtl_expression_parser.ggs', line 633
, END_PRODUCTION
// At index 497 : <select_gtl_5F_expression_5F_parser_17>, in file 'gtl_expression_parser.ggs', line 633
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) // $,$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A_) // $:$
, NONTERMINAL (0) // <gtl_expression>
, NONTERMINAL (59) // <select_gtl_5F_expression_5F_parser_17>
, END_PRODUCTION
// At index 503 : <select_gtl_5F_expression_5F_parser_18>, in file 'gtl_expression_parser.ggs', line 653
, NONTERMINAL (0) // <gtl_expression>
, NONTERMINAL (61) // <select_gtl_5F_expression_5F_parser_19>
, END_PRODUCTION
// At index 506 : <select_gtl_5F_expression_5F_parser_18>, in file 'gtl_expression_parser.ggs', line 653
, END_PRODUCTION
// At index 507 : <select_gtl_5F_expression_5F_parser_19>, in file 'gtl_expression_parser.ggs', line 654
, END_PRODUCTION
// At index 508 : <select_gtl_5F_expression_5F_parser_19>, in file 'gtl_expression_parser.ggs', line 654
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) // $,$
, NONTERMINAL (0) // <gtl_expression>
, NONTERMINAL (61) // <select_gtl_5F_expression_5F_parser_19>
, END_PRODUCTION
// At index 512 : <select_gtl_5F_expression_5F_parser_20>, in file 'gtl_expression_parser.ggs', line 671
, END_PRODUCTION
// At index 513 : <select_gtl_5F_expression_5F_parser_20>, in file 'gtl_expression_parser.ggs', line 671
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A__3A_) // $::$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, NONTERMINAL (63) // <select_gtl_5F_expression_5F_parser_21>
, NONTERMINAL (62) // <select_gtl_5F_expression_5F_parser_20>
, END_PRODUCTION
// At index 518 : <select_gtl_5F_expression_5F_parser_21>, in file 'gtl_expression_parser.ggs', line 673
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5B_) // $[$
, NONTERMINAL (0) // <gtl_expression>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5D_) // $]$
, NONTERMINAL (64) // <select_gtl_5F_expression_5F_parser_22>
, END_PRODUCTION
// At index 523 : <select_gtl_5F_expression_5F_parser_21>, in file 'gtl_expression_parser.ggs', line 673
, END_PRODUCTION
// At index 524 : <select_gtl_5F_expression_5F_parser_22>, in file 'gtl_expression_parser.ggs', line 678
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5B_) // $[$
, NONTERMINAL (0) // <gtl_expression>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5D_) // $]$
, NONTERMINAL (65) // <select_gtl_5F_expression_5F_parser_23>
, END_PRODUCTION
// At index 529 : <select_gtl_5F_expression_5F_parser_22>, in file 'gtl_expression_parser.ggs', line 678
, END_PRODUCTION
// At index 530 : <select_gtl_5F_expression_5F_parser_23>, in file 'gtl_expression_parser.ggs', line 683
, END_PRODUCTION
// At index 531 : <select_gtl_5F_expression_5F_parser_23>, in file 'gtl_expression_parser.ggs', line 683
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5B_) // $[$
, NONTERMINAL (0) // <gtl_expression>
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5D_) // $]$
, NONTERMINAL (65) // <select_gtl_5F_expression_5F_parser_23>
, END_PRODUCTION
// At index 536 : <select_gtl_5F_expression_5F_parser_24>, in file 'gtl_expression_parser.ggs', line 706
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_here) // $here$
, END_PRODUCTION
// At index 538 : <select_gtl_5F_expression_5F_parser_24>, in file 'gtl_expression_parser.ggs', line 706
, NONTERMINAL (1) // <gtl_variable>
, END_PRODUCTION
// At index 540 : <select_gtl_5F_expression_5F_parser_25>, in file 'gtl_expression_parser.ggs', line 721
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, NONTERMINAL (69) // <select_gtl_5F_expression_5F_parser_27>
, NONTERMINAL (68) // <select_gtl_5F_expression_5F_parser_26>
, END_PRODUCTION
// At index 544 : <select_gtl_5F_expression_5F_parser_25>, in file 'gtl_expression_parser.ggs', line 721
, END_PRODUCTION
// At index 545 : <select_gtl_5F_expression_5F_parser_26>, in file 'gtl_expression_parser.ggs', line 722
, END_PRODUCTION
// At index 546 : <select_gtl_5F_expression_5F_parser_26>, in file 'gtl_expression_parser.ggs', line 722
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) // $,$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, NONTERMINAL (69) // <select_gtl_5F_expression_5F_parser_27>
, NONTERMINAL (68) // <select_gtl_5F_expression_5F_parser_26>
, END_PRODUCTION
// At index 551 : <select_gtl_5F_expression_5F_parser_27>, in file 'gtl_expression_parser.ggs', line 724
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A_) // $:$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__40_) // $@$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, END_PRODUCTION
// At index 555 : <select_gtl_5F_expression_5F_parser_27>, in file 'gtl_expression_parser.ggs', line 724
, END_PRODUCTION
// At index 556 : <select_gtl_5F_instruction_5F_parser_0>, in file 'gtl_instruction_parser.ggs', line 45
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A__3D_) // $:=$
, NONTERMINAL (0) // <gtl_expression>
, END_PRODUCTION
// At index 559 : <select_gtl_5F_instruction_5F_parser_0>, in file 'gtl_instruction_parser.ggs', line 45
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2B__3D_) // $+=$
, NONTERMINAL (0) // <gtl_expression>
, END_PRODUCTION
// At index 562 : <select_gtl_5F_instruction_5F_parser_0>, in file 'gtl_instruction_parser.ggs', line 45
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2D__3D_) // $-=$
, NONTERMINAL (0) // <gtl_expression>
, END_PRODUCTION
// At index 565 : <select_gtl_5F_instruction_5F_parser_0>, in file 'gtl_instruction_parser.ggs', line 45
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2A__3D_) // $*=$
, NONTERMINAL (0) // <gtl_expression>
, END_PRODUCTION
// At index 568 : <select_gtl_5F_instruction_5F_parser_0>, in file 'gtl_instruction_parser.ggs', line 45
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2F__3D_) // $/=$
, NONTERMINAL (0) // <gtl_expression>
, END_PRODUCTION
// At index 571 : <select_gtl_5F_instruction_5F_parser_0>, in file 'gtl_instruction_parser.ggs', line 45
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_mod_3D_) // $mod=$
, NONTERMINAL (0) // <gtl_expression>
, END_PRODUCTION
// At index 574 : <select_gtl_5F_instruction_5F_parser_0>, in file 'gtl_instruction_parser.ggs', line 45
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3C__3C__3D_) // $<<=$
, NONTERMINAL (0) // <gtl_expression>
, END_PRODUCTION
// At index 577 : <select_gtl_5F_instruction_5F_parser_0>, in file 'gtl_instruction_parser.ggs', line 45
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3E__3E__3D_) // $>>=$
, NONTERMINAL (0) // <gtl_expression>
, END_PRODUCTION
// At index 580 : <select_gtl_5F_instruction_5F_parser_0>, in file 'gtl_instruction_parser.ggs', line 45
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__26__3D_) // $&=$
, NONTERMINAL (0) // <gtl_expression>
, END_PRODUCTION
// At index 583 : <select_gtl_5F_instruction_5F_parser_0>, in file 'gtl_instruction_parser.ggs', line 45
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__7C__3D_) // $|=$
, NONTERMINAL (0) // <gtl_expression>
, END_PRODUCTION
// At index 586 : <select_gtl_5F_instruction_5F_parser_0>, in file 'gtl_instruction_parser.ggs', line 45
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5E__3D_) // $^=$
, NONTERMINAL (0) // <gtl_expression>
, END_PRODUCTION
// At index 589 : <select_gtl_5F_instruction_5F_parser_0>, in file 'gtl_instruction_parser.ggs', line 45
, END_PRODUCTION
// At index 590 : <select_gtl_5F_instruction_5F_parser_1>, in file 'gtl_instruction_parser.ggs', line 222
, NONTERMINAL (0) // <gtl_expression>
, END_PRODUCTION
// At index 592 : <select_gtl_5F_instruction_5F_parser_1>, in file 'gtl_instruction_parser.ggs', line 222
, END_PRODUCTION
// At index 593 : <select_gtl_5F_instruction_5F_parser_2>, in file 'gtl_instruction_parser.ggs', line 260
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_by) // $by$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, NONTERMINAL (15) // <gtl_sorting_order>
, NONTERMINAL (73) // <select_gtl_5F_instruction_5F_parser_3>
, END_PRODUCTION
// At index 598 : <select_gtl_5F_instruction_5F_parser_2>, in file 'gtl_instruction_parser.ggs', line 260
, NONTERMINAL (15) // <gtl_sorting_order>
, END_PRODUCTION
// At index 600 : <select_gtl_5F_instruction_5F_parser_3>, in file 'gtl_instruction_parser.ggs', line 263
, END_PRODUCTION
// At index 601 : <select_gtl_5F_instruction_5F_parser_3>, in file 'gtl_instruction_parser.ggs', line 263
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) // $,$
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, NONTERMINAL (15) // <gtl_sorting_order>
, NONTERMINAL (73) // <select_gtl_5F_instruction_5F_parser_3>
, END_PRODUCTION
// At index 606 : <select_gtl_5F_instruction_5F_parser_4>, in file 'gtl_instruction_parser.ggs', line 333
, END_PRODUCTION
// At index 607 : <select_gtl_5F_instruction_5F_parser_4>, in file 'gtl_instruction_parser.ggs', line 333
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A_) // $:$
, NONTERMINAL (0) // <gtl_expression>
, NONTERMINAL (75) // <select_gtl_5F_instruction_5F_parser_5>
, END_PRODUCTION
// At index 611 : <select_gtl_5F_instruction_5F_parser_5>, in file 'gtl_instruction_parser.ggs', line 336
, END_PRODUCTION
// At index 612 : <select_gtl_5F_instruction_5F_parser_5>, in file 'gtl_instruction_parser.ggs', line 336
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) // $,$
, NONTERMINAL (0) // <gtl_expression>
, NONTERMINAL (75) // <select_gtl_5F_instruction_5F_parser_5>
, END_PRODUCTION
// At index 616 : <select_gtl_5F_instruction_5F_parser_6>, in file 'gtl_instruction_parser.ggs', line 357
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3E_) // $>$
, END_PRODUCTION
// At index 618 : <select_gtl_5F_instruction_5F_parser_6>, in file 'gtl_instruction_parser.ggs', line 357
, TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3C_) // $<$
, END_PRODUCTION
// At index 620 : <>, in file '.ggs', line 0
, NONTERMINAL (6) // <gtl_start_symbol>
, END_PRODUCTION
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                          P R O D U C T I O N    N A M E S                                            
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const cProductionNameDescriptor gProductionNames_gtl_grammar [209] = {
 {"<gtl_expression>", "gtl_expression_parser", 0}, // at index 0
 {"<gtl_variable>", "gtl_expression_parser", 3}, // at index 1
 {"<gtl_variable_or_here>", "gtl_expression_parser", 7}, // at index 2
 {"<gtl_import>", "gtl_instruction_parser", 9}, // at index 3
 {"<gtl_simple_instruction>", "gtl_instruction_parser", 12}, // at index 4
 {"<gtl_simple_instruction>", "gtl_instruction_parser", 16}, // at index 5
 {"<gtl_simple_instruction>", "gtl_instruction_parser", 19}, // at index 6
 {"<gtl_simple_instruction>", "gtl_instruction_parser", 24}, // at index 7
 {"<gtl_simple_instruction>", "gtl_instruction_parser", 29}, // at index 8
 {"<gtl_simple_instruction>", "gtl_instruction_parser", 32}, // at index 9
 {"<gtl_simple_instruction>", "gtl_instruction_parser", 35}, // at index 10
 {"<gtl_simple_instruction>", "gtl_instruction_parser", 38}, // at index 11
 {"<gtl_simple_instruction>", "gtl_instruction_parser", 42}, // at index 12
 {"<gtl_simple_instruction>", "gtl_instruction_parser", 45}, // at index 13
 {"<gtl_simple_instruction>", "gtl_instruction_parser", 47}, // at index 14
 {"<gtl_simple_instruction>", "gtl_instruction_parser", 49}, // at index 15
 {"<gtl_argument_list>", "gtl_expression_parser", 55}, // at index 16
 {"<gtl_start_symbol>", "gtl_parser", 59}, // at index 17
 {"<gtl_template_instruction_list>", "gtl_parser", 62}, // at index 18
 {"<gtl_template_instruction>", "gtl_parser", 64}, // at index 19
 {"<gtl_template_instruction>", "gtl_parser", 67}, // at index 20
 {"<gtl_template_instruction>", "gtl_parser", 76}, // at index 21
 {"<gtl_template_instruction>", "gtl_parser", 80}, // at index 22
 {"<gtl_template_instruction>", "gtl_parser", 83}, // at index 23
 {"<gtl_template_instruction>", "gtl_parser", 92}, // at index 24
 {"<gtl_template_instruction>", "gtl_parser", 106}, // at index 25
 {"<gtl_template_instruction>", "gtl_parser", 117}, // at index 26
 {"<gtl_template_instruction>", "gtl_parser", 133}, // at index 27
 {"<gtl_template_instruction>", "gtl_parser", 143}, // at index 28
 {"<gtl_file_name>", "gtl_parser", 146}, // at index 29
 {"<gtl_relation_term>", "gtl_expression_parser", 148}, // at index 30
 {"<gtl_relation_factor>", "gtl_expression_parser", 151}, // at index 31
 {"<gtl_simple_expression>", "gtl_expression_parser", 154}, // at index 32
 {"<gtl_term>", "gtl_expression_parser", 157}, // at index 33
 {"<gtl_factor>", "gtl_expression_parser", 160}, // at index 34
 {"<gtl_factor>", "gtl_expression_parser", 164}, // at index 35
 {"<gtl_factor>", "gtl_expression_parser", 167}, // at index 36
 {"<gtl_factor>", "gtl_expression_parser", 170}, // at index 37
 {"<gtl_factor>", "gtl_expression_parser", 173}, // at index 38
 {"<gtl_factor>", "gtl_expression_parser", 176}, // at index 39
 {"<gtl_factor>", "gtl_expression_parser", 178}, // at index 40
 {"<gtl_factor>", "gtl_expression_parser", 180}, // at index 41
 {"<gtl_factor>", "gtl_expression_parser", 182}, // at index 42
 {"<gtl_factor>", "gtl_expression_parser", 184}, // at index 43
 {"<gtl_factor>", "gtl_expression_parser", 186}, // at index 44
 {"<gtl_factor>", "gtl_expression_parser", 188}, // at index 45
 {"<gtl_factor>", "gtl_expression_parser", 194}, // at index 46
 {"<gtl_factor>", "gtl_expression_parser", 197}, // at index 47
 {"<gtl_factor>", "gtl_expression_parser", 201}, // at index 48
 {"<gtl_factor>", "gtl_expression_parser", 204}, // at index 49
 {"<gtl_factor>", "gtl_expression_parser", 206}, // at index 50
 {"<gtl_factor>", "gtl_expression_parser", 208}, // at index 51
 {"<gtl_factor>", "gtl_expression_parser", 210}, // at index 52
 {"<gtl_factor>", "gtl_expression_parser", 213}, // at index 53
 {"<gtl_factor>", "gtl_expression_parser", 215}, // at index 54
 {"<gtl_factor>", "gtl_expression_parser", 217}, // at index 55
 {"<gtl_factor>", "gtl_expression_parser", 221}, // at index 56
 {"<gtl_factor>", "gtl_expression_parser", 225}, // at index 57
 {"<gtl_factor>", "gtl_expression_parser", 229}, // at index 58
 {"<gtl_factor>", "gtl_expression_parser", 233}, // at index 59
 {"<gtl_factor>", "gtl_expression_parser", 237}, // at index 60
 {"<gtl_sorting_order>", "gtl_instruction_parser", 241}, // at index 61
 {"<select_gtl_5F_parser_0>", "gtl_parser", 243}, // at index 62
 {"<select_gtl_5F_parser_0>", "gtl_parser", 244}, // at index 63
 {"<select_gtl_5F_parser_1>", "gtl_parser", 247}, // at index 64
 {"<select_gtl_5F_parser_1>", "gtl_parser", 248}, // at index 65
 {"<select_gtl_5F_parser_1>", "gtl_parser", 251}, // at index 66
 {"<select_gtl_5F_parser_2>", "gtl_parser", 254}, // at index 67
 {"<select_gtl_5F_parser_2>", "gtl_parser", 256}, // at index 68
 {"<select_gtl_5F_parser_3>", "gtl_parser", 257}, // at index 69
 {"<select_gtl_5F_parser_3>", "gtl_parser", 261}, // at index 70
 {"<select_gtl_5F_parser_4>", "gtl_parser", 262}, // at index 71
 {"<select_gtl_5F_parser_4>", "gtl_parser", 265}, // at index 72
 {"<select_gtl_5F_parser_5>", "gtl_parser", 266}, // at index 73
 {"<select_gtl_5F_parser_5>", "gtl_parser", 267}, // at index 74
 {"<select_gtl_5F_parser_6>", "gtl_parser", 271}, // at index 75
 {"<select_gtl_5F_parser_6>", "gtl_parser", 277}, // at index 76
 {"<select_gtl_5F_parser_7>", "gtl_parser", 280}, // at index 77
 {"<select_gtl_5F_parser_7>", "gtl_parser", 283}, // at index 78
 {"<select_gtl_5F_parser_8>", "gtl_parser", 284}, // at index 79
 {"<select_gtl_5F_parser_8>", "gtl_parser", 289}, // at index 80
 {"<select_gtl_5F_parser_9>", "gtl_parser", 290}, // at index 81
 {"<select_gtl_5F_parser_9>", "gtl_parser", 293}, // at index 82
 {"<select_gtl_5F_parser_10>", "gtl_parser", 294}, // at index 83
 {"<select_gtl_5F_parser_10>", "gtl_parser", 295}, // at index 84
 {"<select_gtl_5F_parser_11>", "gtl_parser", 301}, // at index 85
 {"<select_gtl_5F_parser_11>", "gtl_parser", 304}, // at index 86
 {"<select_gtl_5F_parser_12>", "gtl_parser", 305}, // at index 87
 {"<select_gtl_5F_parser_12>", "gtl_parser", 308}, // at index 88
 {"<select_gtl_5F_parser_13>", "gtl_parser", 309}, // at index 89
 {"<select_gtl_5F_parser_13>", "gtl_parser", 313}, // at index 90
 {"<select_gtl_5F_parser_14>", "gtl_parser", 314}, // at index 91
 {"<select_gtl_5F_parser_14>", "gtl_parser", 317}, // at index 92
 {"<select_gtl_5F_parser_15>", "gtl_parser", 318}, // at index 93
 {"<select_gtl_5F_parser_15>", "gtl_parser", 321}, // at index 94
 {"<select_gtl_5F_parser_16>", "gtl_parser", 322}, // at index 95
 {"<select_gtl_5F_parser_16>", "gtl_parser", 325}, // at index 96
 {"<select_gtl_5F_parser_17>", "gtl_parser", 326}, // at index 97
 {"<select_gtl_5F_parser_17>", "gtl_parser", 327}, // at index 98
 {"<select_gtl_5F_parser_18>", "gtl_parser", 331}, // at index 99
 {"<select_gtl_5F_parser_18>", "gtl_parser", 334}, // at index 100
 {"<select_gtl_5F_parser_19>", "gtl_parser", 335}, // at index 101
 {"<select_gtl_5F_parser_19>", "gtl_parser", 336}, // at index 102
 {"<select_gtl_5F_parser_19>", "gtl_parser", 338}, // at index 103
 {"<select_gtl_5F_parser_20>", "gtl_parser", 340}, // at index 104
 {"<select_gtl_5F_parser_20>", "gtl_parser", 343}, // at index 105
 {"<select_gtl_5F_parser_21>", "gtl_parser", 344}, // at index 106
 {"<select_gtl_5F_parser_21>", "gtl_parser", 347}, // at index 107
 {"<select_gtl_5F_parser_22>", "gtl_parser", 348}, // at index 108
 {"<select_gtl_5F_parser_22>", "gtl_parser", 351}, // at index 109
 {"<select_gtl_5F_parser_23>", "gtl_parser", 352}, // at index 110
 {"<select_gtl_5F_parser_23>", "gtl_parser", 355}, // at index 111
 {"<select_gtl_5F_parser_24>", "gtl_parser", 356}, // at index 112
 {"<select_gtl_5F_parser_24>", "gtl_parser", 360}, // at index 113
 {"<select_gtl_5F_parser_25>", "gtl_parser", 361}, // at index 114
 {"<select_gtl_5F_parser_25>", "gtl_parser", 363}, // at index 115
 {"<select_gtl_5F_expression_5F_parser_0>", "gtl_expression_parser", 366}, // at index 116
 {"<select_gtl_5F_expression_5F_parser_0>", "gtl_expression_parser", 367}, // at index 117
 {"<select_gtl_5F_expression_5F_parser_0>", "gtl_expression_parser", 371}, // at index 118
 {"<select_gtl_5F_expression_5F_parser_1>", "gtl_expression_parser", 375}, // at index 119
 {"<select_gtl_5F_expression_5F_parser_1>", "gtl_expression_parser", 376}, // at index 120
 {"<select_gtl_5F_expression_5F_parser_2>", "gtl_expression_parser", 380}, // at index 121
 {"<select_gtl_5F_expression_5F_parser_2>", "gtl_expression_parser", 381}, // at index 122
 {"<select_gtl_5F_expression_5F_parser_2>", "gtl_expression_parser", 384}, // at index 123
 {"<select_gtl_5F_expression_5F_parser_2>", "gtl_expression_parser", 387}, // at index 124
 {"<select_gtl_5F_expression_5F_parser_2>", "gtl_expression_parser", 390}, // at index 125
 {"<select_gtl_5F_expression_5F_parser_2>", "gtl_expression_parser", 393}, // at index 126
 {"<select_gtl_5F_expression_5F_parser_2>", "gtl_expression_parser", 396}, // at index 127
 {"<select_gtl_5F_expression_5F_parser_3>", "gtl_expression_parser", 399}, // at index 128
 {"<select_gtl_5F_expression_5F_parser_3>", "gtl_expression_parser", 400}, // at index 129
 {"<select_gtl_5F_expression_5F_parser_3>", "gtl_expression_parser", 404}, // at index 130
 {"<select_gtl_5F_expression_5F_parser_3>", "gtl_expression_parser", 408}, // at index 131
 {"<select_gtl_5F_expression_5F_parser_3>", "gtl_expression_parser", 412}, // at index 132
 {"<select_gtl_5F_expression_5F_parser_3>", "gtl_expression_parser", 416}, // at index 133
 {"<select_gtl_5F_expression_5F_parser_4>", "gtl_expression_parser", 420}, // at index 134
 {"<select_gtl_5F_expression_5F_parser_4>", "gtl_expression_parser", 421}, // at index 135
 {"<select_gtl_5F_expression_5F_parser_4>", "gtl_expression_parser", 425}, // at index 136
 {"<select_gtl_5F_expression_5F_parser_4>", "gtl_expression_parser", 429}, // at index 137
 {"<select_gtl_5F_expression_5F_parser_5>", "gtl_expression_parser", 433}, // at index 138
 {"<select_gtl_5F_expression_5F_parser_5>", "gtl_expression_parser", 434}, // at index 139
 {"<select_gtl_5F_expression_5F_parser_6>", "gtl_expression_parser", 438}, // at index 140
 {"<select_gtl_5F_expression_5F_parser_6>", "gtl_expression_parser", 439}, // at index 141
 {"<select_gtl_5F_expression_5F_parser_7>", "gtl_expression_parser", 443}, // at index 142
 {"<select_gtl_5F_expression_5F_parser_7>", "gtl_expression_parser", 444}, // at index 143
 {"<select_gtl_5F_expression_5F_parser_8>", "gtl_expression_parser", 448}, // at index 144
 {"<select_gtl_5F_expression_5F_parser_8>", "gtl_expression_parser", 451}, // at index 145
 {"<select_gtl_5F_expression_5F_parser_9>", "gtl_expression_parser", 452}, // at index 146
 {"<select_gtl_5F_expression_5F_parser_9>", "gtl_expression_parser", 453}, // at index 147
 {"<select_gtl_5F_expression_5F_parser_10>", "gtl_expression_parser", 457}, // at index 148
 {"<select_gtl_5F_expression_5F_parser_10>", "gtl_expression_parser", 462}, // at index 149
 {"<select_gtl_5F_expression_5F_parser_11>", "gtl_expression_parser", 463}, // at index 150
 {"<select_gtl_5F_expression_5F_parser_11>", "gtl_expression_parser", 466}, // at index 151
 {"<select_gtl_5F_expression_5F_parser_12>", "gtl_expression_parser", 468}, // at index 152
 {"<select_gtl_5F_expression_5F_parser_12>", "gtl_expression_parser", 471}, // at index 153
 {"<select_gtl_5F_expression_5F_parser_13>", "gtl_expression_parser", 472}, // at index 154
 {"<select_gtl_5F_expression_5F_parser_13>", "gtl_expression_parser", 473}, // at index 155
 {"<select_gtl_5F_expression_5F_parser_14>", "gtl_expression_parser", 477}, // at index 156
 {"<select_gtl_5F_expression_5F_parser_14>", "gtl_expression_parser", 482}, // at index 157
 {"<select_gtl_5F_expression_5F_parser_15>", "gtl_expression_parser", 483}, // at index 158
 {"<select_gtl_5F_expression_5F_parser_15>", "gtl_expression_parser", 484}, // at index 159
 {"<select_gtl_5F_expression_5F_parser_16>", "gtl_expression_parser", 490}, // at index 160
 {"<select_gtl_5F_expression_5F_parser_16>", "gtl_expression_parser", 495}, // at index 161
 {"<select_gtl_5F_expression_5F_parser_17>", "gtl_expression_parser", 496}, // at index 162
 {"<select_gtl_5F_expression_5F_parser_17>", "gtl_expression_parser", 497}, // at index 163
 {"<select_gtl_5F_expression_5F_parser_18>", "gtl_expression_parser", 503}, // at index 164
 {"<select_gtl_5F_expression_5F_parser_18>", "gtl_expression_parser", 506}, // at index 165
 {"<select_gtl_5F_expression_5F_parser_19>", "gtl_expression_parser", 507}, // at index 166
 {"<select_gtl_5F_expression_5F_parser_19>", "gtl_expression_parser", 508}, // at index 167
 {"<select_gtl_5F_expression_5F_parser_20>", "gtl_expression_parser", 512}, // at index 168
 {"<select_gtl_5F_expression_5F_parser_20>", "gtl_expression_parser", 513}, // at index 169
 {"<select_gtl_5F_expression_5F_parser_21>", "gtl_expression_parser", 518}, // at index 170
 {"<select_gtl_5F_expression_5F_parser_21>", "gtl_expression_parser", 523}, // at index 171
 {"<select_gtl_5F_expression_5F_parser_22>", "gtl_expression_parser", 524}, // at index 172
 {"<select_gtl_5F_expression_5F_parser_22>", "gtl_expression_parser", 529}, // at index 173
 {"<select_gtl_5F_expression_5F_parser_23>", "gtl_expression_parser", 530}, // at index 174
 {"<select_gtl_5F_expression_5F_parser_23>", "gtl_expression_parser", 531}, // at index 175
 {"<select_gtl_5F_expression_5F_parser_24>", "gtl_expression_parser", 536}, // at index 176
 {"<select_gtl_5F_expression_5F_parser_24>", "gtl_expression_parser", 538}, // at index 177
 {"<select_gtl_5F_expression_5F_parser_25>", "gtl_expression_parser", 540}, // at index 178
 {"<select_gtl_5F_expression_5F_parser_25>", "gtl_expression_parser", 544}, // at index 179
 {"<select_gtl_5F_expression_5F_parser_26>", "gtl_expression_parser", 545}, // at index 180
 {"<select_gtl_5F_expression_5F_parser_26>", "gtl_expression_parser", 546}, // at index 181
 {"<select_gtl_5F_expression_5F_parser_27>", "gtl_expression_parser", 551}, // at index 182
 {"<select_gtl_5F_expression_5F_parser_27>", "gtl_expression_parser", 555}, // at index 183
 {"<select_gtl_5F_instruction_5F_parser_0>", "gtl_instruction_parser", 556}, // at index 184
 {"<select_gtl_5F_instruction_5F_parser_0>", "gtl_instruction_parser", 559}, // at index 185
 {"<select_gtl_5F_instruction_5F_parser_0>", "gtl_instruction_parser", 562}, // at index 186
 {"<select_gtl_5F_instruction_5F_parser_0>", "gtl_instruction_parser", 565}, // at index 187
 {"<select_gtl_5F_instruction_5F_parser_0>", "gtl_instruction_parser", 568}, // at index 188
 {"<select_gtl_5F_instruction_5F_parser_0>", "gtl_instruction_parser", 571}, // at index 189
 {"<select_gtl_5F_instruction_5F_parser_0>", "gtl_instruction_parser", 574}, // at index 190
 {"<select_gtl_5F_instruction_5F_parser_0>", "gtl_instruction_parser", 577}, // at index 191
 {"<select_gtl_5F_instruction_5F_parser_0>", "gtl_instruction_parser", 580}, // at index 192
 {"<select_gtl_5F_instruction_5F_parser_0>", "gtl_instruction_parser", 583}, // at index 193
 {"<select_gtl_5F_instruction_5F_parser_0>", "gtl_instruction_parser", 586}, // at index 194
 {"<select_gtl_5F_instruction_5F_parser_0>", "gtl_instruction_parser", 589}, // at index 195
 {"<select_gtl_5F_instruction_5F_parser_1>", "gtl_instruction_parser", 590}, // at index 196
 {"<select_gtl_5F_instruction_5F_parser_1>", "gtl_instruction_parser", 592}, // at index 197
 {"<select_gtl_5F_instruction_5F_parser_2>", "gtl_instruction_parser", 593}, // at index 198
 {"<select_gtl_5F_instruction_5F_parser_2>", "gtl_instruction_parser", 598}, // at index 199
 {"<select_gtl_5F_instruction_5F_parser_3>", "gtl_instruction_parser", 600}, // at index 200
 {"<select_gtl_5F_instruction_5F_parser_3>", "gtl_instruction_parser", 601}, // at index 201
 {"<select_gtl_5F_instruction_5F_parser_4>", "gtl_instruction_parser", 606}, // at index 202
 {"<select_gtl_5F_instruction_5F_parser_4>", "gtl_instruction_parser", 607}, // at index 203
 {"<select_gtl_5F_instruction_5F_parser_5>", "gtl_instruction_parser", 611}, // at index 204
 {"<select_gtl_5F_instruction_5F_parser_5>", "gtl_instruction_parser", 612}, // at index 205
 {"<select_gtl_5F_instruction_5F_parser_6>", "gtl_instruction_parser", 616}, // at index 206
 {"<select_gtl_5F_instruction_5F_parser_6>", "gtl_instruction_parser", 618}, // at index 207
 {"<>", "", 620} // at index 208
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                 L L ( 1 )    P R O D U C T I O N    I N D E X E S                                    
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gProductionIndexes_gtl_grammar [209] = {
0, // index 0 : <gtl_expression>, in file 'gtl_expression_parser.ggs', line 33
3, // index 1 : <gtl_variable>, in file 'gtl_expression_parser.ggs', line 667
7, // index 2 : <gtl_variable_or_here>, in file 'gtl_expression_parser.ggs', line 702
9, // index 3 : <gtl_import>, in file 'gtl_instruction_parser.ggs', line 367
12, // index 4 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 40
16, // index 5 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 154
19, // index 6 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 167
24, // index 7 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 185
29, // index 8 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 203
32, // index 9 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 218
35, // index 10 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 241
38, // index 11 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 255
42, // index 12 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 288
45, // index 13 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 302
47, // index 14 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 314
49, // index 15 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 325
55, // index 16 : <gtl_argument_list>, in file 'gtl_expression_parser.ggs', line 716
59, // index 17 : <gtl_start_symbol>, in file 'gtl_parser.ggs', line 50
62, // index 18 : <gtl_template_instruction_list>, in file 'gtl_parser.ggs', line 63
64, // index 19 : <gtl_template_instruction>, in file 'gtl_parser.ggs', line 90
67, // index 20 : <gtl_template_instruction>, in file 'gtl_parser.ggs', line 108
76, // index 21 : <gtl_template_instruction>, in file 'gtl_parser.ggs', line 128
80, // index 22 : <gtl_template_instruction>, in file 'gtl_parser.ggs', line 183
83, // index 23 : <gtl_template_instruction>, in file 'gtl_parser.ggs', line 196
92, // index 24 : <gtl_template_instruction>, in file 'gtl_parser.ggs', line 228
106, // index 25 : <gtl_template_instruction>, in file 'gtl_parser.ggs', line 289
117, // index 26 : <gtl_template_instruction>, in file 'gtl_parser.ggs', line 331
133, // index 27 : <gtl_template_instruction>, in file 'gtl_parser.ggs', line 397
143, // index 28 : <gtl_template_instruction>, in file 'gtl_parser.ggs', line 430
146, // index 29 : <gtl_file_name>, in file 'gtl_parser.ggs', line 443
148, // index 30 : <gtl_relation_term>, in file 'gtl_expression_parser.ggs', line 53
151, // index 31 : <gtl_relation_factor>, in file 'gtl_expression_parser.ggs', line 69
154, // index 32 : <gtl_simple_expression>, in file 'gtl_expression_parser.ggs', line 117
157, // index 33 : <gtl_term>, in file 'gtl_expression_parser.ggs', line 162
160, // index 34 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 192
164, // index 35 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 208
167, // index 36 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 220
170, // index 37 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 232
173, // index 38 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 244
176, // index 39 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 256
178, // index 40 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 269
180, // index 41 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 282
182, // index 42 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 295
184, // index 43 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 308
186, // index 44 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 321
188, // index 45 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 335
194, // index 46 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 369
197, // index 47 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 401
201, // index 48 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 420
204, // index 49 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 429
206, // index 50 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 445
208, // index 51 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 461
210, // index 52 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 477
213, // index 53 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 514
215, // index 54 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 533
217, // index 55 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 552
221, // index 56 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 576
225, // index 57 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 587
229, // index 58 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 606
233, // index 59 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 627
237, // index 60 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 648
241, // index 61 : <gtl_sorting_order>, in file 'gtl_instruction_parser.ggs', line 354
243, // index 62 : <select_gtl_5F_parser_0>, in file 'gtl_parser.ggs', line 55
244, // index 63 : <select_gtl_5F_parser_0>, in file 'gtl_parser.ggs', line 55
247, // index 64 : <select_gtl_5F_parser_1>, in file 'gtl_parser.ggs', line 67
248, // index 65 : <select_gtl_5F_parser_1>, in file 'gtl_parser.ggs', line 67
251, // index 66 : <select_gtl_5F_parser_1>, in file 'gtl_parser.ggs', line 67
254, // index 67 : <select_gtl_5F_parser_2>, in file 'gtl_parser.ggs', line 112
256, // index 68 : <select_gtl_5F_parser_2>, in file 'gtl_parser.ggs', line 112
257, // index 69 : <select_gtl_5F_parser_3>, in file 'gtl_parser.ggs', line 138
261, // index 70 : <select_gtl_5F_parser_3>, in file 'gtl_parser.ggs', line 138
262, // index 71 : <select_gtl_5F_parser_4>, in file 'gtl_parser.ggs', line 141
265, // index 72 : <select_gtl_5F_parser_4>, in file 'gtl_parser.ggs', line 141
266, // index 73 : <select_gtl_5F_parser_5>, in file 'gtl_parser.ggs', line 142
267, // index 74 : <select_gtl_5F_parser_5>, in file 'gtl_parser.ggs', line 142
271, // index 75 : <select_gtl_5F_parser_6>, in file 'gtl_parser.ggs', line 152
277, // index 76 : <select_gtl_5F_parser_6>, in file 'gtl_parser.ggs', line 152
280, // index 77 : <select_gtl_5F_parser_7>, in file 'gtl_parser.ggs', line 156
283, // index 78 : <select_gtl_5F_parser_7>, in file 'gtl_parser.ggs', line 156
284, // index 79 : <select_gtl_5F_parser_8>, in file 'gtl_parser.ggs', line 159
289, // index 80 : <select_gtl_5F_parser_8>, in file 'gtl_parser.ggs', line 159
290, // index 81 : <select_gtl_5F_parser_9>, in file 'gtl_parser.ggs', line 166
293, // index 82 : <select_gtl_5F_parser_9>, in file 'gtl_parser.ggs', line 166
294, // index 83 : <select_gtl_5F_parser_10>, in file 'gtl_parser.ggs', line 202
295, // index 84 : <select_gtl_5F_parser_10>, in file 'gtl_parser.ggs', line 202
301, // index 85 : <select_gtl_5F_parser_11>, in file 'gtl_parser.ggs', line 212
304, // index 86 : <select_gtl_5F_parser_11>, in file 'gtl_parser.ggs', line 212
305, // index 87 : <select_gtl_5F_parser_12>, in file 'gtl_parser.ggs', line 239
308, // index 88 : <select_gtl_5F_parser_12>, in file 'gtl_parser.ggs', line 239
309, // index 89 : <select_gtl_5F_parser_13>, in file 'gtl_parser.ggs', line 245
313, // index 90 : <select_gtl_5F_parser_13>, in file 'gtl_parser.ggs', line 245
314, // index 91 : <select_gtl_5F_parser_14>, in file 'gtl_parser.ggs', line 253
317, // index 92 : <select_gtl_5F_parser_14>, in file 'gtl_parser.ggs', line 253
318, // index 93 : <select_gtl_5F_parser_15>, in file 'gtl_parser.ggs', line 261
321, // index 94 : <select_gtl_5F_parser_15>, in file 'gtl_parser.ggs', line 261
322, // index 95 : <select_gtl_5F_parser_16>, in file 'gtl_parser.ggs', line 266
325, // index 96 : <select_gtl_5F_parser_16>, in file 'gtl_parser.ggs', line 266
326, // index 97 : <select_gtl_5F_parser_17>, in file 'gtl_parser.ggs', line 302
327, // index 98 : <select_gtl_5F_parser_17>, in file 'gtl_parser.ggs', line 302
331, // index 99 : <select_gtl_5F_parser_18>, in file 'gtl_parser.ggs', line 312
334, // index 100 : <select_gtl_5F_parser_18>, in file 'gtl_parser.ggs', line 312
335, // index 101 : <select_gtl_5F_parser_19>, in file 'gtl_parser.ggs', line 347
336, // index 102 : <select_gtl_5F_parser_19>, in file 'gtl_parser.ggs', line 347
338, // index 103 : <select_gtl_5F_parser_19>, in file 'gtl_parser.ggs', line 347
340, // index 104 : <select_gtl_5F_parser_20>, in file 'gtl_parser.ggs', line 355
343, // index 105 : <select_gtl_5F_parser_20>, in file 'gtl_parser.ggs', line 355
344, // index 106 : <select_gtl_5F_parser_21>, in file 'gtl_parser.ggs', line 360
347, // index 107 : <select_gtl_5F_parser_21>, in file 'gtl_parser.ggs', line 360
348, // index 108 : <select_gtl_5F_parser_22>, in file 'gtl_parser.ggs', line 368
351, // index 109 : <select_gtl_5F_parser_22>, in file 'gtl_parser.ggs', line 368
352, // index 110 : <select_gtl_5F_parser_23>, in file 'gtl_parser.ggs', line 373
355, // index 111 : <select_gtl_5F_parser_23>, in file 'gtl_parser.ggs', line 373
356, // index 112 : <select_gtl_5F_parser_24>, in file 'gtl_parser.ggs', line 402
360, // index 113 : <select_gtl_5F_parser_24>, in file 'gtl_parser.ggs', line 402
361, // index 114 : <select_gtl_5F_parser_25>, in file 'gtl_parser.ggs', line 446
363, // index 115 : <select_gtl_5F_parser_25>, in file 'gtl_parser.ggs', line 446
366, // index 116 : <select_gtl_5F_expression_5F_parser_0>, in file 'gtl_expression_parser.ggs', line 37
367, // index 117 : <select_gtl_5F_expression_5F_parser_0>, in file 'gtl_expression_parser.ggs', line 37
371, // index 118 : <select_gtl_5F_expression_5F_parser_0>, in file 'gtl_expression_parser.ggs', line 37
375, // index 119 : <select_gtl_5F_expression_5F_parser_1>, in file 'gtl_expression_parser.ggs', line 57
376, // index 120 : <select_gtl_5F_expression_5F_parser_1>, in file 'gtl_expression_parser.ggs', line 57
380, // index 121 : <select_gtl_5F_expression_5F_parser_2>, in file 'gtl_expression_parser.ggs', line 73
381, // index 122 : <select_gtl_5F_expression_5F_parser_2>, in file 'gtl_expression_parser.ggs', line 73
384, // index 123 : <select_gtl_5F_expression_5F_parser_2>, in file 'gtl_expression_parser.ggs', line 73
387, // index 124 : <select_gtl_5F_expression_5F_parser_2>, in file 'gtl_expression_parser.ggs', line 73
390, // index 125 : <select_gtl_5F_expression_5F_parser_2>, in file 'gtl_expression_parser.ggs', line 73
393, // index 126 : <select_gtl_5F_expression_5F_parser_2>, in file 'gtl_expression_parser.ggs', line 73
396, // index 127 : <select_gtl_5F_expression_5F_parser_2>, in file 'gtl_expression_parser.ggs', line 73
399, // index 128 : <select_gtl_5F_expression_5F_parser_3>, in file 'gtl_expression_parser.ggs', line 121
400, // index 129 : <select_gtl_5F_expression_5F_parser_3>, in file 'gtl_expression_parser.ggs', line 121
404, // index 130 : <select_gtl_5F_expression_5F_parser_3>, in file 'gtl_expression_parser.ggs', line 121
408, // index 131 : <select_gtl_5F_expression_5F_parser_3>, in file 'gtl_expression_parser.ggs', line 121
412, // index 132 : <select_gtl_5F_expression_5F_parser_3>, in file 'gtl_expression_parser.ggs', line 121
416, // index 133 : <select_gtl_5F_expression_5F_parser_3>, in file 'gtl_expression_parser.ggs', line 121
420, // index 134 : <select_gtl_5F_expression_5F_parser_4>, in file 'gtl_expression_parser.ggs', line 166
421, // index 135 : <select_gtl_5F_expression_5F_parser_4>, in file 'gtl_expression_parser.ggs', line 166
425, // index 136 : <select_gtl_5F_expression_5F_parser_4>, in file 'gtl_expression_parser.ggs', line 166
429, // index 137 : <select_gtl_5F_expression_5F_parser_4>, in file 'gtl_expression_parser.ggs', line 166
433, // index 138 : <select_gtl_5F_expression_5F_parser_5>, in file 'gtl_expression_parser.ggs', line 348
434, // index 139 : <select_gtl_5F_expression_5F_parser_5>, in file 'gtl_expression_parser.ggs', line 348
438, // index 140 : <select_gtl_5F_expression_5F_parser_6>, in file 'gtl_expression_parser.ggs', line 351
439, // index 141 : <select_gtl_5F_expression_5F_parser_6>, in file 'gtl_expression_parser.ggs', line 351
443, // index 142 : <select_gtl_5F_expression_5F_parser_7>, in file 'gtl_expression_parser.ggs', line 373
444, // index 143 : <select_gtl_5F_expression_5F_parser_7>, in file 'gtl_expression_parser.ggs', line 373
448, // index 144 : <select_gtl_5F_expression_5F_parser_8>, in file 'gtl_expression_parser.ggs', line 381
451, // index 145 : <select_gtl_5F_expression_5F_parser_8>, in file 'gtl_expression_parser.ggs', line 381
452, // index 146 : <select_gtl_5F_expression_5F_parser_9>, in file 'gtl_expression_parser.ggs', line 382
453, // index 147 : <select_gtl_5F_expression_5F_parser_9>, in file 'gtl_expression_parser.ggs', line 382
457, // index 148 : <select_gtl_5F_expression_5F_parser_10>, in file 'gtl_expression_parser.ggs', line 405
462, // index 149 : <select_gtl_5F_expression_5F_parser_10>, in file 'gtl_expression_parser.ggs', line 405
463, // index 150 : <select_gtl_5F_expression_5F_parser_11>, in file 'gtl_expression_parser.ggs', line 557
466, // index 151 : <select_gtl_5F_expression_5F_parser_11>, in file 'gtl_expression_parser.ggs', line 557
468, // index 152 : <select_gtl_5F_expression_5F_parser_12>, in file 'gtl_expression_parser.ggs', line 592
471, // index 153 : <select_gtl_5F_expression_5F_parser_12>, in file 'gtl_expression_parser.ggs', line 592
472, // index 154 : <select_gtl_5F_expression_5F_parser_13>, in file 'gtl_expression_parser.ggs', line 593
473, // index 155 : <select_gtl_5F_expression_5F_parser_13>, in file 'gtl_expression_parser.ggs', line 593
477, // index 156 : <select_gtl_5F_expression_5F_parser_14>, in file 'gtl_expression_parser.ggs', line 611
482, // index 157 : <select_gtl_5F_expression_5F_parser_14>, in file 'gtl_expression_parser.ggs', line 611
483, // index 158 : <select_gtl_5F_expression_5F_parser_15>, in file 'gtl_expression_parser.ggs', line 612
484, // index 159 : <select_gtl_5F_expression_5F_parser_15>, in file 'gtl_expression_parser.ggs', line 612
490, // index 160 : <select_gtl_5F_expression_5F_parser_16>, in file 'gtl_expression_parser.ggs', line 632
495, // index 161 : <select_gtl_5F_expression_5F_parser_16>, in file 'gtl_expression_parser.ggs', line 632
496, // index 162 : <select_gtl_5F_expression_5F_parser_17>, in file 'gtl_expression_parser.ggs', line 633
497, // index 163 : <select_gtl_5F_expression_5F_parser_17>, in file 'gtl_expression_parser.ggs', line 633
503, // index 164 : <select_gtl_5F_expression_5F_parser_18>, in file 'gtl_expression_parser.ggs', line 653
506, // index 165 : <select_gtl_5F_expression_5F_parser_18>, in file 'gtl_expression_parser.ggs', line 653
507, // index 166 : <select_gtl_5F_expression_5F_parser_19>, in file 'gtl_expression_parser.ggs', line 654
508, // index 167 : <select_gtl_5F_expression_5F_parser_19>, in file 'gtl_expression_parser.ggs', line 654
512, // index 168 : <select_gtl_5F_expression_5F_parser_20>, in file 'gtl_expression_parser.ggs', line 671
513, // index 169 : <select_gtl_5F_expression_5F_parser_20>, in file 'gtl_expression_parser.ggs', line 671
518, // index 170 : <select_gtl_5F_expression_5F_parser_21>, in file 'gtl_expression_parser.ggs', line 673
523, // index 171 : <select_gtl_5F_expression_5F_parser_21>, in file 'gtl_expression_parser.ggs', line 673
524, // index 172 : <select_gtl_5F_expression_5F_parser_22>, in file 'gtl_expression_parser.ggs', line 678
529, // index 173 : <select_gtl_5F_expression_5F_parser_22>, in file 'gtl_expression_parser.ggs', line 678
530, // index 174 : <select_gtl_5F_expression_5F_parser_23>, in file 'gtl_expression_parser.ggs', line 683
531, // index 175 : <select_gtl_5F_expression_5F_parser_23>, in file 'gtl_expression_parser.ggs', line 683
536, // index 176 : <select_gtl_5F_expression_5F_parser_24>, in file 'gtl_expression_parser.ggs', line 706
538, // index 177 : <select_gtl_5F_expression_5F_parser_24>, in file 'gtl_expression_parser.ggs', line 706
540, // index 178 : <select_gtl_5F_expression_5F_parser_25>, in file 'gtl_expression_parser.ggs', line 721
544, // index 179 : <select_gtl_5F_expression_5F_parser_25>, in file 'gtl_expression_parser.ggs', line 721
545, // index 180 : <select_gtl_5F_expression_5F_parser_26>, in file 'gtl_expression_parser.ggs', line 722
546, // index 181 : <select_gtl_5F_expression_5F_parser_26>, in file 'gtl_expression_parser.ggs', line 722
551, // index 182 : <select_gtl_5F_expression_5F_parser_27>, in file 'gtl_expression_parser.ggs', line 724
555, // index 183 : <select_gtl_5F_expression_5F_parser_27>, in file 'gtl_expression_parser.ggs', line 724
556, // index 184 : <select_gtl_5F_instruction_5F_parser_0>, in file 'gtl_instruction_parser.ggs', line 45
559, // index 185 : <select_gtl_5F_instruction_5F_parser_0>, in file 'gtl_instruction_parser.ggs', line 45
562, // index 186 : <select_gtl_5F_instruction_5F_parser_0>, in file 'gtl_instruction_parser.ggs', line 45
565, // index 187 : <select_gtl_5F_instruction_5F_parser_0>, in file 'gtl_instruction_parser.ggs', line 45
568, // index 188 : <select_gtl_5F_instruction_5F_parser_0>, in file 'gtl_instruction_parser.ggs', line 45
571, // index 189 : <select_gtl_5F_instruction_5F_parser_0>, in file 'gtl_instruction_parser.ggs', line 45
574, // index 190 : <select_gtl_5F_instruction_5F_parser_0>, in file 'gtl_instruction_parser.ggs', line 45
577, // index 191 : <select_gtl_5F_instruction_5F_parser_0>, in file 'gtl_instruction_parser.ggs', line 45
580, // index 192 : <select_gtl_5F_instruction_5F_parser_0>, in file 'gtl_instruction_parser.ggs', line 45
583, // index 193 : <select_gtl_5F_instruction_5F_parser_0>, in file 'gtl_instruction_parser.ggs', line 45
586, // index 194 : <select_gtl_5F_instruction_5F_parser_0>, in file 'gtl_instruction_parser.ggs', line 45
589, // index 195 : <select_gtl_5F_instruction_5F_parser_0>, in file 'gtl_instruction_parser.ggs', line 45
590, // index 196 : <select_gtl_5F_instruction_5F_parser_1>, in file 'gtl_instruction_parser.ggs', line 222
592, // index 197 : <select_gtl_5F_instruction_5F_parser_1>, in file 'gtl_instruction_parser.ggs', line 222
593, // index 198 : <select_gtl_5F_instruction_5F_parser_2>, in file 'gtl_instruction_parser.ggs', line 260
598, // index 199 : <select_gtl_5F_instruction_5F_parser_2>, in file 'gtl_instruction_parser.ggs', line 260
600, // index 200 : <select_gtl_5F_instruction_5F_parser_3>, in file 'gtl_instruction_parser.ggs', line 263
601, // index 201 : <select_gtl_5F_instruction_5F_parser_3>, in file 'gtl_instruction_parser.ggs', line 263
606, // index 202 : <select_gtl_5F_instruction_5F_parser_4>, in file 'gtl_instruction_parser.ggs', line 333
607, // index 203 : <select_gtl_5F_instruction_5F_parser_4>, in file 'gtl_instruction_parser.ggs', line 333
611, // index 204 : <select_gtl_5F_instruction_5F_parser_5>, in file 'gtl_instruction_parser.ggs', line 336
612, // index 205 : <select_gtl_5F_instruction_5F_parser_5>, in file 'gtl_instruction_parser.ggs', line 336
616, // index 206 : <select_gtl_5F_instruction_5F_parser_6>, in file 'gtl_instruction_parser.ggs', line 357
618, // index 207 : <select_gtl_5F_instruction_5F_parser_6>, in file 'gtl_instruction_parser.ggs', line 357
620 // index 208 : <>, in file '.ggs', line 0
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                           L L ( 1 )    F I R S T    P R O D U C T I O N    I N D E X E S                             
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gFirstProductionIndexes_gtl_grammar [79] = {
0, // at 0 : <gtl_expression>
1, // at 1 : <gtl_variable>
2, // at 2 : <gtl_variable_or_here>
3, // at 3 : <gtl_import>
4, // at 4 : <gtl_simple_instruction>
16, // at 5 : <gtl_argument_list>
17, // at 6 : <gtl_start_symbol>
18, // at 7 : <gtl_template_instruction_list>
19, // at 8 : <gtl_template_instruction>
29, // at 9 : <gtl_file_name>
30, // at 10 : <gtl_relation_term>
31, // at 11 : <gtl_relation_factor>
32, // at 12 : <gtl_simple_expression>
33, // at 13 : <gtl_term>
34, // at 14 : <gtl_factor>
61, // at 15 : <gtl_sorting_order>
62, // at 16 : <select_gtl_5F_parser_0>
64, // at 17 : <select_gtl_5F_parser_1>
67, // at 18 : <select_gtl_5F_parser_2>
69, // at 19 : <select_gtl_5F_parser_3>
71, // at 20 : <select_gtl_5F_parser_4>
73, // at 21 : <select_gtl_5F_parser_5>
75, // at 22 : <select_gtl_5F_parser_6>
77, // at 23 : <select_gtl_5F_parser_7>
79, // at 24 : <select_gtl_5F_parser_8>
81, // at 25 : <select_gtl_5F_parser_9>
83, // at 26 : <select_gtl_5F_parser_10>
85, // at 27 : <select_gtl_5F_parser_11>
87, // at 28 : <select_gtl_5F_parser_12>
89, // at 29 : <select_gtl_5F_parser_13>
91, // at 30 : <select_gtl_5F_parser_14>
93, // at 31 : <select_gtl_5F_parser_15>
95, // at 32 : <select_gtl_5F_parser_16>
97, // at 33 : <select_gtl_5F_parser_17>
99, // at 34 : <select_gtl_5F_parser_18>
101, // at 35 : <select_gtl_5F_parser_19>
104, // at 36 : <select_gtl_5F_parser_20>
106, // at 37 : <select_gtl_5F_parser_21>
108, // at 38 : <select_gtl_5F_parser_22>
110, // at 39 : <select_gtl_5F_parser_23>
112, // at 40 : <select_gtl_5F_parser_24>
114, // at 41 : <select_gtl_5F_parser_25>
116, // at 42 : <select_gtl_5F_expression_5F_parser_0>
119, // at 43 : <select_gtl_5F_expression_5F_parser_1>
121, // at 44 : <select_gtl_5F_expression_5F_parser_2>
128, // at 45 : <select_gtl_5F_expression_5F_parser_3>
134, // at 46 : <select_gtl_5F_expression_5F_parser_4>
138, // at 47 : <select_gtl_5F_expression_5F_parser_5>
140, // at 48 : <select_gtl_5F_expression_5F_parser_6>
142, // at 49 : <select_gtl_5F_expression_5F_parser_7>
144, // at 50 : <select_gtl_5F_expression_5F_parser_8>
146, // at 51 : <select_gtl_5F_expression_5F_parser_9>
148, // at 52 : <select_gtl_5F_expression_5F_parser_10>
150, // at 53 : <select_gtl_5F_expression_5F_parser_11>
152, // at 54 : <select_gtl_5F_expression_5F_parser_12>
154, // at 55 : <select_gtl_5F_expression_5F_parser_13>
156, // at 56 : <select_gtl_5F_expression_5F_parser_14>
158, // at 57 : <select_gtl_5F_expression_5F_parser_15>
160, // at 58 : <select_gtl_5F_expression_5F_parser_16>
162, // at 59 : <select_gtl_5F_expression_5F_parser_17>
164, // at 60 : <select_gtl_5F_expression_5F_parser_18>
166, // at 61 : <select_gtl_5F_expression_5F_parser_19>
168, // at 62 : <select_gtl_5F_expression_5F_parser_20>
170, // at 63 : <select_gtl_5F_expression_5F_parser_21>
172, // at 64 : <select_gtl_5F_expression_5F_parser_22>
174, // at 65 : <select_gtl_5F_expression_5F_parser_23>
176, // at 66 : <select_gtl_5F_expression_5F_parser_24>
178, // at 67 : <select_gtl_5F_expression_5F_parser_25>
180, // at 68 : <select_gtl_5F_expression_5F_parser_26>
182, // at 69 : <select_gtl_5F_expression_5F_parser_27>
184, // at 70 : <select_gtl_5F_instruction_5F_parser_0>
196, // at 71 : <select_gtl_5F_instruction_5F_parser_1>
198, // at 72 : <select_gtl_5F_instruction_5F_parser_2>
200, // at 73 : <select_gtl_5F_instruction_5F_parser_3>
202, // at 74 : <select_gtl_5F_instruction_5F_parser_4>
204, // at 75 : <select_gtl_5F_instruction_5F_parser_5>
206, // at 76 : <select_gtl_5F_instruction_5F_parser_6>
208, // at 77 : <>
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                    L L ( 1 )    D E C I S I O N    T A B L E S                                       
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gDecision_gtl_grammar [] = {
// At index 0 : <gtl_expression> only one production, no choice
  -1,
// At index 1 : <gtl_variable> only one production, no choice
  -1,
// At index 2 : <gtl_variable_or_here> only one production, no choice
  -1,
// At index 3 : <gtl_import> only one production, no choice
  -1,
// At index 4 : <gtl_simple_instruction>
C_Lexique_gtl_5F_scanner::kToken_let, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken_unlet, -1, // Choice 2
C_Lexique_gtl_5F_scanner::kToken_error, -1, // Choice 3
C_Lexique_gtl_5F_scanner::kToken_warning, -1, // Choice 4
C_Lexique_gtl_5F_scanner::kToken_print, -1, // Choice 5
C_Lexique_gtl_5F_scanner::kToken_println, -1, // Choice 6
C_Lexique_gtl_5F_scanner::kToken_display, -1, // Choice 7
C_Lexique_gtl_5F_scanner::kToken_sort, -1, // Choice 8
C_Lexique_gtl_5F_scanner::kToken_tab, -1, // Choice 9
C_Lexique_gtl_5F_scanner::kToken_variables, -1, // Choice 10
C_Lexique_gtl_5F_scanner::kToken_libraries, -1, // Choice 11
C_Lexique_gtl_5F_scanner::kToken__5B__21_, -1, // Choice 12
  -1,
// At index 29 : <gtl_argument_list> only one production, no choice
  -1,
// At index 30 : <gtl_start_symbol> only one production, no choice
  -1,
// At index 31 : <gtl_template_instruction_list> only one production, no choice
  -1,
// At index 32 : <gtl_template_instruction>
C_Lexique_gtl_5F_scanner::kToken__21_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken_write, -1, // Choice 2
C_Lexique_gtl_5F_scanner::kToken_template, -1, // Choice 3
C_Lexique_gtl_5F_scanner::kToken__3F_, -1, // Choice 4
C_Lexique_gtl_5F_scanner::kToken_if, -1, // Choice 5
C_Lexique_gtl_5F_scanner::kToken_foreach, -1, // Choice 6
C_Lexique_gtl_5F_scanner::kToken_for, -1, // Choice 7
C_Lexique_gtl_5F_scanner::kToken_loop, -1, // Choice 8
C_Lexique_gtl_5F_scanner::kToken_repeat, -1, // Choice 9
C_Lexique_gtl_5F_scanner::kToken_input, -1, // Choice 10
  -1,
// At index 53 : <gtl_file_name> only one production, no choice
  -1,
// At index 54 : <gtl_relation_term> only one production, no choice
  -1,
// At index 55 : <gtl_relation_factor> only one production, no choice
  -1,
// At index 56 : <gtl_simple_expression> only one production, no choice
  -1,
// At index 57 : <gtl_term> only one production, no choice
  -1,
// At index 58 : <gtl_factor>
C_Lexique_gtl_5F_scanner::kToken__28_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken_not, -1, // Choice 2
C_Lexique_gtl_5F_scanner::kToken__7E_, -1, // Choice 3
C_Lexique_gtl_5F_scanner::kToken__2D_, -1, // Choice 4
C_Lexique_gtl_5F_scanner::kToken__2B_, -1, // Choice 5
C_Lexique_gtl_5F_scanner::kToken_yes, -1, // Choice 6
C_Lexique_gtl_5F_scanner::kToken_no, -1, // Choice 7
C_Lexique_gtl_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint, -1, // Choice 8
C_Lexique_gtl_5F_scanner::kToken_literal_5F_double, -1, // Choice 9
C_Lexique_gtl_5F_scanner::kToken_string, -1, // Choice 10
C_Lexique_gtl_5F_scanner::kToken_literal_5F_char, -1, // Choice 11
C_Lexique_gtl_5F_scanner::kToken__5B_, -1, // Choice 12
C_Lexique_gtl_5F_scanner::kToken_identifier, -1, // Choice 13
C_Lexique_gtl_5F_scanner::kToken_exists, -1, // Choice 14
C_Lexique_gtl_5F_scanner::kToken_typeof, -1, // Choice 15
C_Lexique_gtl_5F_scanner::kToken_true, -1, // Choice 16
C_Lexique_gtl_5F_scanner::kToken_false, -1, // Choice 17
C_Lexique_gtl_5F_scanner::kToken_literal_5F_enum, -1, // Choice 18
C_Lexique_gtl_5F_scanner::kToken__40_, -1, // Choice 19
C_Lexique_gtl_5F_scanner::kToken_emptylist, -1, // Choice 20
C_Lexique_gtl_5F_scanner::kToken_emptymap, -1, // Choice 21
C_Lexique_gtl_5F_scanner::kToken_mapof, -1, // Choice 22
C_Lexique_gtl_5F_scanner::kToken_listof, -1, // Choice 23
C_Lexique_gtl_5F_scanner::kToken__40__28_, -1, // Choice 24
C_Lexique_gtl_5F_scanner::kToken__40__5B_, -1, // Choice 25
C_Lexique_gtl_5F_scanner::kToken__40__7B_, -1, // Choice 26
C_Lexique_gtl_5F_scanner::kToken__40__21_, -1, // Choice 27
  -1,
// At index 113 : <gtl_sorting_order> only one production, no choice
  -1,
//---- Added non terminal symbols from 'select' and 'repeat' instructions
// At index 114 : <select_gtl_5F_parser_0>
C_Lexique_gtl_5F_scanner::kToken__21_, C_Lexique_gtl_5F_scanner::kToken_write, C_Lexique_gtl_5F_scanner::kToken_template, C_Lexique_gtl_5F_scanner::kToken_if, C_Lexique_gtl_5F_scanner::kToken__3F_, C_Lexique_gtl_5F_scanner::kToken_foreach, C_Lexique_gtl_5F_scanner::kToken_for, C_Lexique_gtl_5F_scanner::kToken_loop, C_Lexique_gtl_5F_scanner::kToken_repeat, C_Lexique_gtl_5F_scanner::kToken_input, C_Lexique_gtl_5F_scanner::kToken_let, C_Lexique_gtl_5F_scanner::kToken_unlet, C_Lexique_gtl_5F_scanner::kToken_error, C_Lexique_gtl_5F_scanner::kToken_warning, C_Lexique_gtl_5F_scanner::kToken_print, C_Lexique_gtl_5F_scanner::kToken_println, C_Lexique_gtl_5F_scanner::kToken_display, C_Lexique_gtl_5F_scanner::kToken_sort, C_Lexique_gtl_5F_scanner::kToken_tab, C_Lexique_gtl_5F_scanner::kToken_variables, C_Lexique_gtl_5F_scanner::kToken_libraries, C_Lexique_gtl_5F_scanner::kToken__5B__21_, C_Lexique_gtl_5F_scanner::kToken_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken_import, -1, // Choice 2
  -1,
// At index 141 : <select_gtl_5F_parser_1>
C_Lexique_gtl_5F_scanner::kToken_end, C_Lexique_gtl_5F_scanner::kToken_elsif, C_Lexique_gtl_5F_scanner::kToken_else, C_Lexique_gtl_5F_scanner::kToken_do, C_Lexique_gtl_5F_scanner::kToken_between, C_Lexique_gtl_5F_scanner::kToken_after, C_Lexique_gtl_5F_scanner::kToken_while, C_Lexique_gtl_5F_scanner::kToken_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__21_, C_Lexique_gtl_5F_scanner::kToken_write, C_Lexique_gtl_5F_scanner::kToken_template, C_Lexique_gtl_5F_scanner::kToken_if, C_Lexique_gtl_5F_scanner::kToken__3F_, C_Lexique_gtl_5F_scanner::kToken_foreach, C_Lexique_gtl_5F_scanner::kToken_for, C_Lexique_gtl_5F_scanner::kToken_loop, C_Lexique_gtl_5F_scanner::kToken_repeat, C_Lexique_gtl_5F_scanner::kToken_input, -1, // Choice 2
C_Lexique_gtl_5F_scanner::kToken_let, C_Lexique_gtl_5F_scanner::kToken_unlet, C_Lexique_gtl_5F_scanner::kToken_error, C_Lexique_gtl_5F_scanner::kToken_warning, C_Lexique_gtl_5F_scanner::kToken_print, C_Lexique_gtl_5F_scanner::kToken_println, C_Lexique_gtl_5F_scanner::kToken_display, C_Lexique_gtl_5F_scanner::kToken_sort, C_Lexique_gtl_5F_scanner::kToken_tab, C_Lexique_gtl_5F_scanner::kToken_variables, C_Lexique_gtl_5F_scanner::kToken_libraries, C_Lexique_gtl_5F_scanner::kToken__5B__21_, -1, // Choice 3
  -1,
// At index 175 : <select_gtl_5F_parser_2>
C_Lexique_gtl_5F_scanner::kToken_executable, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__28_, C_Lexique_gtl_5F_scanner::kToken_exists, C_Lexique_gtl_5F_scanner::kToken_identifier, C_Lexique_gtl_5F_scanner::kToken__2B_, C_Lexique_gtl_5F_scanner::kToken__2D_, C_Lexique_gtl_5F_scanner::kToken_not, C_Lexique_gtl_5F_scanner::kToken__7E_, C_Lexique_gtl_5F_scanner::kToken_yes, C_Lexique_gtl_5F_scanner::kToken_no, C_Lexique_gtl_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint, C_Lexique_gtl_5F_scanner::kToken_literal_5F_double, C_Lexique_gtl_5F_scanner::kToken_string, C_Lexique_gtl_5F_scanner::kToken_literal_5F_char, C_Lexique_gtl_5F_scanner::kToken__5B_, C_Lexique_gtl_5F_scanner::kToken_typeof, C_Lexique_gtl_5F_scanner::kToken_true, C_Lexique_gtl_5F_scanner::kToken_false, C_Lexique_gtl_5F_scanner::kToken_literal_5F_enum, C_Lexique_gtl_5F_scanner::kToken__40_, C_Lexique_gtl_5F_scanner::kToken_emptylist, C_Lexique_gtl_5F_scanner::kToken_emptymap, C_Lexique_gtl_5F_scanner::kToken_mapof, C_Lexique_gtl_5F_scanner::kToken_listof, C_Lexique_gtl_5F_scanner::kToken__40__28_, C_Lexique_gtl_5F_scanner::kToken__40__5B_, C_Lexique_gtl_5F_scanner::kToken__40__7B_, C_Lexique_gtl_5F_scanner::kToken__40__21_, -1, // Choice 2
  -1,
// At index 206 : <select_gtl_5F_parser_3>
C_Lexique_gtl_5F_scanner::kToken__28_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken_if, C_Lexique_gtl_5F_scanner::kToken_identifier, C_Lexique_gtl_5F_scanner::kToken_from, -1, // Choice 2
  -1,
// At index 213 : <select_gtl_5F_parser_4>
C_Lexique_gtl_5F_scanner::kToken__28_, C_Lexique_gtl_5F_scanner::kToken_exists, C_Lexique_gtl_5F_scanner::kToken_identifier, C_Lexique_gtl_5F_scanner::kToken__2B_, C_Lexique_gtl_5F_scanner::kToken__2D_, C_Lexique_gtl_5F_scanner::kToken_not, C_Lexique_gtl_5F_scanner::kToken__7E_, C_Lexique_gtl_5F_scanner::kToken_yes, C_Lexique_gtl_5F_scanner::kToken_no, C_Lexique_gtl_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint, C_Lexique_gtl_5F_scanner::kToken_literal_5F_double, C_Lexique_gtl_5F_scanner::kToken_string, C_Lexique_gtl_5F_scanner::kToken_literal_5F_char, C_Lexique_gtl_5F_scanner::kToken__5B_, C_Lexique_gtl_5F_scanner::kToken_typeof, C_Lexique_gtl_5F_scanner::kToken_true, C_Lexique_gtl_5F_scanner::kToken_false, C_Lexique_gtl_5F_scanner::kToken_literal_5F_enum, C_Lexique_gtl_5F_scanner::kToken__40_, C_Lexique_gtl_5F_scanner::kToken_emptylist, C_Lexique_gtl_5F_scanner::kToken_emptymap, C_Lexique_gtl_5F_scanner::kToken_mapof, C_Lexique_gtl_5F_scanner::kToken_listof, C_Lexique_gtl_5F_scanner::kToken__40__28_, C_Lexique_gtl_5F_scanner::kToken__40__5B_, C_Lexique_gtl_5F_scanner::kToken__40__7B_, C_Lexique_gtl_5F_scanner::kToken__40__21_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__29_, -1, // Choice 2
  -1,
// At index 244 : <select_gtl_5F_parser_5>
C_Lexique_gtl_5F_scanner::kToken__29_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__2C_, -1, // Choice 2
  -1,
// At index 249 : <select_gtl_5F_parser_6>
C_Lexique_gtl_5F_scanner::kToken_if, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken_identifier, C_Lexique_gtl_5F_scanner::kToken_from, -1, // Choice 2
  -1,
// At index 255 : <select_gtl_5F_parser_7>
C_Lexique_gtl_5F_scanner::kToken_in, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__21_, C_Lexique_gtl_5F_scanner::kToken_write, C_Lexique_gtl_5F_scanner::kToken_end, C_Lexique_gtl_5F_scanner::kToken_template, C_Lexique_gtl_5F_scanner::kToken_if, C_Lexique_gtl_5F_scanner::kToken_or, C_Lexique_gtl_5F_scanner::kToken__3F_, C_Lexique_gtl_5F_scanner::kToken_elsif, C_Lexique_gtl_5F_scanner::kToken_else, C_Lexique_gtl_5F_scanner::kToken_foreach, C_Lexique_gtl_5F_scanner::kToken_do, C_Lexique_gtl_5F_scanner::kToken_between, C_Lexique_gtl_5F_scanner::kToken_after, C_Lexique_gtl_5F_scanner::kToken_for, C_Lexique_gtl_5F_scanner::kToken_loop, C_Lexique_gtl_5F_scanner::kToken_repeat, C_Lexique_gtl_5F_scanner::kToken_while, C_Lexique_gtl_5F_scanner::kToken_input, C_Lexique_gtl_5F_scanner::kToken_let, C_Lexique_gtl_5F_scanner::kToken_unlet, C_Lexique_gtl_5F_scanner::kToken_error, C_Lexique_gtl_5F_scanner::kToken_warning, C_Lexique_gtl_5F_scanner::kToken_print, C_Lexique_gtl_5F_scanner::kToken_println, C_Lexique_gtl_5F_scanner::kToken_display, C_Lexique_gtl_5F_scanner::kToken_sort, C_Lexique_gtl_5F_scanner::kToken_tab, C_Lexique_gtl_5F_scanner::kToken_variables, C_Lexique_gtl_5F_scanner::kToken_libraries, C_Lexique_gtl_5F_scanner::kToken__5B__21_, C_Lexique_gtl_5F_scanner::kToken_, -1, // Choice 2
  -1,
// At index 290 : <select_gtl_5F_parser_8>
C_Lexique_gtl_5F_scanner::kToken_or, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__21_, C_Lexique_gtl_5F_scanner::kToken_write, C_Lexique_gtl_5F_scanner::kToken_end, C_Lexique_gtl_5F_scanner::kToken_template, C_Lexique_gtl_5F_scanner::kToken_if, C_Lexique_gtl_5F_scanner::kToken__3F_, C_Lexique_gtl_5F_scanner::kToken_elsif, C_Lexique_gtl_5F_scanner::kToken_else, C_Lexique_gtl_5F_scanner::kToken_foreach, C_Lexique_gtl_5F_scanner::kToken_do, C_Lexique_gtl_5F_scanner::kToken_between, C_Lexique_gtl_5F_scanner::kToken_after, C_Lexique_gtl_5F_scanner::kToken_for, C_Lexique_gtl_5F_scanner::kToken_loop, C_Lexique_gtl_5F_scanner::kToken_repeat, C_Lexique_gtl_5F_scanner::kToken_while, C_Lexique_gtl_5F_scanner::kToken_input, C_Lexique_gtl_5F_scanner::kToken_let, C_Lexique_gtl_5F_scanner::kToken_unlet, C_Lexique_gtl_5F_scanner::kToken_error, C_Lexique_gtl_5F_scanner::kToken_warning, C_Lexique_gtl_5F_scanner::kToken_print, C_Lexique_gtl_5F_scanner::kToken_println, C_Lexique_gtl_5F_scanner::kToken_display, C_Lexique_gtl_5F_scanner::kToken_sort, C_Lexique_gtl_5F_scanner::kToken_tab, C_Lexique_gtl_5F_scanner::kToken_variables, C_Lexique_gtl_5F_scanner::kToken_libraries, C_Lexique_gtl_5F_scanner::kToken__5B__21_, C_Lexique_gtl_5F_scanner::kToken_, -1, // Choice 2
  -1,
// At index 324 : <select_gtl_5F_parser_9>
C_Lexique_gtl_5F_scanner::kToken_in, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__21_, C_Lexique_gtl_5F_scanner::kToken_write, C_Lexique_gtl_5F_scanner::kToken_end, C_Lexique_gtl_5F_scanner::kToken_template, C_Lexique_gtl_5F_scanner::kToken_if, C_Lexique_gtl_5F_scanner::kToken__3F_, C_Lexique_gtl_5F_scanner::kToken_elsif, C_Lexique_gtl_5F_scanner::kToken_else, C_Lexique_gtl_5F_scanner::kToken_foreach, C_Lexique_gtl_5F_scanner::kToken_do, C_Lexique_gtl_5F_scanner::kToken_between, C_Lexique_gtl_5F_scanner::kToken_after, C_Lexique_gtl_5F_scanner::kToken_for, C_Lexique_gtl_5F_scanner::kToken_loop, C_Lexique_gtl_5F_scanner::kToken_repeat, C_Lexique_gtl_5F_scanner::kToken_while, C_Lexique_gtl_5F_scanner::kToken_input, C_Lexique_gtl_5F_scanner::kToken_let, C_Lexique_gtl_5F_scanner::kToken_unlet, C_Lexique_gtl_5F_scanner::kToken_error, C_Lexique_gtl_5F_scanner::kToken_warning, C_Lexique_gtl_5F_scanner::kToken_print, C_Lexique_gtl_5F_scanner::kToken_println, C_Lexique_gtl_5F_scanner::kToken_display, C_Lexique_gtl_5F_scanner::kToken_sort, C_Lexique_gtl_5F_scanner::kToken_tab, C_Lexique_gtl_5F_scanner::kToken_variables, C_Lexique_gtl_5F_scanner::kToken_libraries, C_Lexique_gtl_5F_scanner::kToken__5B__21_, C_Lexique_gtl_5F_scanner::kToken_, -1, // Choice 2
  -1,
// At index 358 : <select_gtl_5F_parser_10>
C_Lexique_gtl_5F_scanner::kToken_end, C_Lexique_gtl_5F_scanner::kToken_else, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken_elsif, -1, // Choice 2
  -1,
// At index 364 : <select_gtl_5F_parser_11>
C_Lexique_gtl_5F_scanner::kToken_else, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken_end, -1, // Choice 2
  -1,
// At index 369 : <select_gtl_5F_parser_12>
C_Lexique_gtl_5F_scanner::kToken__2C_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__28_, C_Lexique_gtl_5F_scanner::kToken_in, -1, // Choice 2
  -1,
// At index 375 : <select_gtl_5F_parser_13>
C_Lexique_gtl_5F_scanner::kToken__28_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken_in, -1, // Choice 2
  -1,
// At index 380 : <select_gtl_5F_parser_14>
C_Lexique_gtl_5F_scanner::kToken_before, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken_do, -1, // Choice 2
  -1,
// At index 385 : <select_gtl_5F_parser_15>
C_Lexique_gtl_5F_scanner::kToken_between, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken_end, C_Lexique_gtl_5F_scanner::kToken_after, -1, // Choice 2
  -1,
// At index 391 : <select_gtl_5F_parser_16>
C_Lexique_gtl_5F_scanner::kToken_after, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken_end, -1, // Choice 2
  -1,
// At index 396 : <select_gtl_5F_parser_17>
C_Lexique_gtl_5F_scanner::kToken_do, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__2C_, -1, // Choice 2
  -1,
// At index 401 : <select_gtl_5F_parser_18>
C_Lexique_gtl_5F_scanner::kToken_between, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken_end, -1, // Choice 2
  -1,
// At index 406 : <select_gtl_5F_parser_19>
C_Lexique_gtl_5F_scanner::kToken_to, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken_up, -1, // Choice 2
C_Lexique_gtl_5F_scanner::kToken_down, -1, // Choice 3
  -1,
// At index 413 : <select_gtl_5F_parser_20>
C_Lexique_gtl_5F_scanner::kToken_step, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken_before, C_Lexique_gtl_5F_scanner::kToken_do, -1, // Choice 2
  -1,
// At index 419 : <select_gtl_5F_parser_21>
C_Lexique_gtl_5F_scanner::kToken_before, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken_do, -1, // Choice 2
  -1,
// At index 424 : <select_gtl_5F_parser_22>
C_Lexique_gtl_5F_scanner::kToken_between, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken_end, C_Lexique_gtl_5F_scanner::kToken_after, -1, // Choice 2
  -1,
// At index 430 : <select_gtl_5F_parser_23>
C_Lexique_gtl_5F_scanner::kToken_after, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken_end, -1, // Choice 2
  -1,
// At index 435 : <select_gtl_5F_parser_24>
C_Lexique_gtl_5F_scanner::kToken__28_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__21_, C_Lexique_gtl_5F_scanner::kToken_write, C_Lexique_gtl_5F_scanner::kToken_template, C_Lexique_gtl_5F_scanner::kToken_if, C_Lexique_gtl_5F_scanner::kToken__3F_, C_Lexique_gtl_5F_scanner::kToken_foreach, C_Lexique_gtl_5F_scanner::kToken_for, C_Lexique_gtl_5F_scanner::kToken_loop, C_Lexique_gtl_5F_scanner::kToken_repeat, C_Lexique_gtl_5F_scanner::kToken_while, C_Lexique_gtl_5F_scanner::kToken_input, C_Lexique_gtl_5F_scanner::kToken_let, C_Lexique_gtl_5F_scanner::kToken_unlet, C_Lexique_gtl_5F_scanner::kToken_error, C_Lexique_gtl_5F_scanner::kToken_warning, C_Lexique_gtl_5F_scanner::kToken_print, C_Lexique_gtl_5F_scanner::kToken_println, C_Lexique_gtl_5F_scanner::kToken_display, C_Lexique_gtl_5F_scanner::kToken_sort, C_Lexique_gtl_5F_scanner::kToken_tab, C_Lexique_gtl_5F_scanner::kToken_variables, C_Lexique_gtl_5F_scanner::kToken_libraries, C_Lexique_gtl_5F_scanner::kToken__5B__21_, -1, // Choice 2
  -1,
// At index 462 : <select_gtl_5F_parser_25>
C_Lexique_gtl_5F_scanner::kToken_identifier, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken_from, -1, // Choice 2
  -1,
// At index 467 : <select_gtl_5F_expression_5F_parser_0>
C_Lexique_gtl_5F_scanner::kToken__21_, C_Lexique_gtl_5F_scanner::kToken_write, C_Lexique_gtl_5F_scanner::kToken_to, C_Lexique_gtl_5F_scanner::kToken__3A_, C_Lexique_gtl_5F_scanner::kToken_end, C_Lexique_gtl_5F_scanner::kToken_template, C_Lexique_gtl_5F_scanner::kToken__2C_, C_Lexique_gtl_5F_scanner::kToken__29_, C_Lexique_gtl_5F_scanner::kToken_if, C_Lexique_gtl_5F_scanner::kToken_in, C_Lexique_gtl_5F_scanner::kToken_identifier, C_Lexique_gtl_5F_scanner::kToken_or, C_Lexique_gtl_5F_scanner::kToken__3F_, C_Lexique_gtl_5F_scanner::kToken_then, C_Lexique_gtl_5F_scanner::kToken_elsif, C_Lexique_gtl_5F_scanner::kToken_else, C_Lexique_gtl_5F_scanner::kToken_foreach, C_Lexique_gtl_5F_scanner::kToken_before, C_Lexique_gtl_5F_scanner::kToken_do, C_Lexique_gtl_5F_scanner::kToken_between, C_Lexique_gtl_5F_scanner::kToken_after, C_Lexique_gtl_5F_scanner::kToken_for, C_Lexique_gtl_5F_scanner::kToken_loop, C_Lexique_gtl_5F_scanner::kToken_up, C_Lexique_gtl_5F_scanner::kToken_down, C_Lexique_gtl_5F_scanner::kToken_step, C_Lexique_gtl_5F_scanner::kToken_repeat, C_Lexique_gtl_5F_scanner::kToken_while, C_Lexique_gtl_5F_scanner::kToken_input, C_Lexique_gtl_5F_scanner::kToken__5D_, C_Lexique_gtl_5F_scanner::kToken_by, C_Lexique_gtl_5F_scanner::kToken__7D_, C_Lexique_gtl_5F_scanner::kToken_let, C_Lexique_gtl_5F_scanner::kToken_unlet, C_Lexique_gtl_5F_scanner::kToken_error, C_Lexique_gtl_5F_scanner::kToken_warning, C_Lexique_gtl_5F_scanner::kToken_print, C_Lexique_gtl_5F_scanner::kToken_println, C_Lexique_gtl_5F_scanner::kToken_display, C_Lexique_gtl_5F_scanner::kToken_sort, C_Lexique_gtl_5F_scanner::kToken_tab, C_Lexique_gtl_5F_scanner::kToken_variables, C_Lexique_gtl_5F_scanner::kToken_libraries, C_Lexique_gtl_5F_scanner::kToken__5B__21_, C_Lexique_gtl_5F_scanner::kToken_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__7C_, -1, // Choice 2
C_Lexique_gtl_5F_scanner::kToken__5E_, -1, // Choice 3
  -1,
// At index 518 : <select_gtl_5F_expression_5F_parser_1>
C_Lexique_gtl_5F_scanner::kToken__21_, C_Lexique_gtl_5F_scanner::kToken_write, C_Lexique_gtl_5F_scanner::kToken_to, C_Lexique_gtl_5F_scanner::kToken__3A_, C_Lexique_gtl_5F_scanner::kToken_end, C_Lexique_gtl_5F_scanner::kToken_template, C_Lexique_gtl_5F_scanner::kToken__2C_, C_Lexique_gtl_5F_scanner::kToken__29_, C_Lexique_gtl_5F_scanner::kToken_if, C_Lexique_gtl_5F_scanner::kToken_in, C_Lexique_gtl_5F_scanner::kToken_identifier, C_Lexique_gtl_5F_scanner::kToken_or, C_Lexique_gtl_5F_scanner::kToken__3F_, C_Lexique_gtl_5F_scanner::kToken_then, C_Lexique_gtl_5F_scanner::kToken_elsif, C_Lexique_gtl_5F_scanner::kToken_else, C_Lexique_gtl_5F_scanner::kToken_foreach, C_Lexique_gtl_5F_scanner::kToken_before, C_Lexique_gtl_5F_scanner::kToken_do, C_Lexique_gtl_5F_scanner::kToken_between, C_Lexique_gtl_5F_scanner::kToken_after, C_Lexique_gtl_5F_scanner::kToken_for, C_Lexique_gtl_5F_scanner::kToken_loop, C_Lexique_gtl_5F_scanner::kToken_up, C_Lexique_gtl_5F_scanner::kToken_down, C_Lexique_gtl_5F_scanner::kToken_step, C_Lexique_gtl_5F_scanner::kToken_repeat, C_Lexique_gtl_5F_scanner::kToken_while, C_Lexique_gtl_5F_scanner::kToken_input, C_Lexique_gtl_5F_scanner::kToken__7C_, C_Lexique_gtl_5F_scanner::kToken__5E_, C_Lexique_gtl_5F_scanner::kToken__5D_, C_Lexique_gtl_5F_scanner::kToken_by, C_Lexique_gtl_5F_scanner::kToken__7D_, C_Lexique_gtl_5F_scanner::kToken_let, C_Lexique_gtl_5F_scanner::kToken_unlet, C_Lexique_gtl_5F_scanner::kToken_error, C_Lexique_gtl_5F_scanner::kToken_warning, C_Lexique_gtl_5F_scanner::kToken_print, C_Lexique_gtl_5F_scanner::kToken_println, C_Lexique_gtl_5F_scanner::kToken_display, C_Lexique_gtl_5F_scanner::kToken_sort, C_Lexique_gtl_5F_scanner::kToken_tab, C_Lexique_gtl_5F_scanner::kToken_variables, C_Lexique_gtl_5F_scanner::kToken_libraries, C_Lexique_gtl_5F_scanner::kToken__5B__21_, C_Lexique_gtl_5F_scanner::kToken_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__26_, -1, // Choice 2
  -1,
// At index 569 : <select_gtl_5F_expression_5F_parser_2>
C_Lexique_gtl_5F_scanner::kToken__21_, C_Lexique_gtl_5F_scanner::kToken_write, C_Lexique_gtl_5F_scanner::kToken_to, C_Lexique_gtl_5F_scanner::kToken__3A_, C_Lexique_gtl_5F_scanner::kToken_end, C_Lexique_gtl_5F_scanner::kToken_template, C_Lexique_gtl_5F_scanner::kToken__2C_, C_Lexique_gtl_5F_scanner::kToken__29_, C_Lexique_gtl_5F_scanner::kToken_if, C_Lexique_gtl_5F_scanner::kToken_in, C_Lexique_gtl_5F_scanner::kToken_identifier, C_Lexique_gtl_5F_scanner::kToken_or, C_Lexique_gtl_5F_scanner::kToken__3F_, C_Lexique_gtl_5F_scanner::kToken_then, C_Lexique_gtl_5F_scanner::kToken_elsif, C_Lexique_gtl_5F_scanner::kToken_else, C_Lexique_gtl_5F_scanner::kToken_foreach, C_Lexique_gtl_5F_scanner::kToken_before, C_Lexique_gtl_5F_scanner::kToken_do, C_Lexique_gtl_5F_scanner::kToken_between, C_Lexique_gtl_5F_scanner::kToken_after, C_Lexique_gtl_5F_scanner::kToken_for, C_Lexique_gtl_5F_scanner::kToken_loop, C_Lexique_gtl_5F_scanner::kToken_up, C_Lexique_gtl_5F_scanner::kToken_down, C_Lexique_gtl_5F_scanner::kToken_step, C_Lexique_gtl_5F_scanner::kToken_repeat, C_Lexique_gtl_5F_scanner::kToken_while, C_Lexique_gtl_5F_scanner::kToken_input, C_Lexique_gtl_5F_scanner::kToken__7C_, C_Lexique_gtl_5F_scanner::kToken__5E_, C_Lexique_gtl_5F_scanner::kToken__26_, C_Lexique_gtl_5F_scanner::kToken__5D_, C_Lexique_gtl_5F_scanner::kToken_by, C_Lexique_gtl_5F_scanner::kToken__7D_, C_Lexique_gtl_5F_scanner::kToken_let, C_Lexique_gtl_5F_scanner::kToken_unlet, C_Lexique_gtl_5F_scanner::kToken_error, C_Lexique_gtl_5F_scanner::kToken_warning, C_Lexique_gtl_5F_scanner::kToken_print, C_Lexique_gtl_5F_scanner::kToken_println, C_Lexique_gtl_5F_scanner::kToken_display, C_Lexique_gtl_5F_scanner::kToken_sort, C_Lexique_gtl_5F_scanner::kToken_tab, C_Lexique_gtl_5F_scanner::kToken_variables, C_Lexique_gtl_5F_scanner::kToken_libraries, C_Lexique_gtl_5F_scanner::kToken__5B__21_, C_Lexique_gtl_5F_scanner::kToken_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__3D__3D_, -1, // Choice 2
C_Lexique_gtl_5F_scanner::kToken__21__3D_, -1, // Choice 3
C_Lexique_gtl_5F_scanner::kToken__3C__3D_, -1, // Choice 4
C_Lexique_gtl_5F_scanner::kToken__3E__3D_, -1, // Choice 5
C_Lexique_gtl_5F_scanner::kToken__3E_, -1, // Choice 6
C_Lexique_gtl_5F_scanner::kToken__3C_, -1, // Choice 7
  -1,
// At index 631 : <select_gtl_5F_expression_5F_parser_3>
C_Lexique_gtl_5F_scanner::kToken__21_, C_Lexique_gtl_5F_scanner::kToken_write, C_Lexique_gtl_5F_scanner::kToken_to, C_Lexique_gtl_5F_scanner::kToken__3A_, C_Lexique_gtl_5F_scanner::kToken_end, C_Lexique_gtl_5F_scanner::kToken_template, C_Lexique_gtl_5F_scanner::kToken__2C_, C_Lexique_gtl_5F_scanner::kToken__29_, C_Lexique_gtl_5F_scanner::kToken_if, C_Lexique_gtl_5F_scanner::kToken_in, C_Lexique_gtl_5F_scanner::kToken_identifier, C_Lexique_gtl_5F_scanner::kToken_or, C_Lexique_gtl_5F_scanner::kToken__3F_, C_Lexique_gtl_5F_scanner::kToken_then, C_Lexique_gtl_5F_scanner::kToken_elsif, C_Lexique_gtl_5F_scanner::kToken_else, C_Lexique_gtl_5F_scanner::kToken_foreach, C_Lexique_gtl_5F_scanner::kToken_before, C_Lexique_gtl_5F_scanner::kToken_do, C_Lexique_gtl_5F_scanner::kToken_between, C_Lexique_gtl_5F_scanner::kToken_after, C_Lexique_gtl_5F_scanner::kToken_for, C_Lexique_gtl_5F_scanner::kToken_loop, C_Lexique_gtl_5F_scanner::kToken_up, C_Lexique_gtl_5F_scanner::kToken_down, C_Lexique_gtl_5F_scanner::kToken_step, C_Lexique_gtl_5F_scanner::kToken_repeat, C_Lexique_gtl_5F_scanner::kToken_while, C_Lexique_gtl_5F_scanner::kToken_input, C_Lexique_gtl_5F_scanner::kToken__7C_, C_Lexique_gtl_5F_scanner::kToken__5E_, C_Lexique_gtl_5F_scanner::kToken__26_, C_Lexique_gtl_5F_scanner::kToken__3D__3D_, C_Lexique_gtl_5F_scanner::kToken__21__3D_, C_Lexique_gtl_5F_scanner::kToken__3C__3D_, C_Lexique_gtl_5F_scanner::kToken__3E__3D_, C_Lexique_gtl_5F_scanner::kToken__3E_, C_Lexique_gtl_5F_scanner::kToken__3C_, C_Lexique_gtl_5F_scanner::kToken__5D_, C_Lexique_gtl_5F_scanner::kToken_by, C_Lexique_gtl_5F_scanner::kToken__7D_, C_Lexique_gtl_5F_scanner::kToken_let, C_Lexique_gtl_5F_scanner::kToken_unlet, C_Lexique_gtl_5F_scanner::kToken_error, C_Lexique_gtl_5F_scanner::kToken_warning, C_Lexique_gtl_5F_scanner::kToken_print, C_Lexique_gtl_5F_scanner::kToken_println, C_Lexique_gtl_5F_scanner::kToken_display, C_Lexique_gtl_5F_scanner::kToken_sort, C_Lexique_gtl_5F_scanner::kToken_tab, C_Lexique_gtl_5F_scanner::kToken_variables, C_Lexique_gtl_5F_scanner::kToken_libraries, C_Lexique_gtl_5F_scanner::kToken__5B__21_, C_Lexique_gtl_5F_scanner::kToken_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__3C__3C_, -1, // Choice 2
C_Lexique_gtl_5F_scanner::kToken__3E__3E_, -1, // Choice 3
C_Lexique_gtl_5F_scanner::kToken__2B_, -1, // Choice 4
C_Lexique_gtl_5F_scanner::kToken__2E_, -1, // Choice 5
C_Lexique_gtl_5F_scanner::kToken__2D_, -1, // Choice 6
  -1,
// At index 697 : <select_gtl_5F_expression_5F_parser_4>
C_Lexique_gtl_5F_scanner::kToken__21_, C_Lexique_gtl_5F_scanner::kToken_write, C_Lexique_gtl_5F_scanner::kToken_to, C_Lexique_gtl_5F_scanner::kToken__3A_, C_Lexique_gtl_5F_scanner::kToken_end, C_Lexique_gtl_5F_scanner::kToken_template, C_Lexique_gtl_5F_scanner::kToken__2C_, C_Lexique_gtl_5F_scanner::kToken__29_, C_Lexique_gtl_5F_scanner::kToken_if, C_Lexique_gtl_5F_scanner::kToken_in, C_Lexique_gtl_5F_scanner::kToken_identifier, C_Lexique_gtl_5F_scanner::kToken_or, C_Lexique_gtl_5F_scanner::kToken__3F_, C_Lexique_gtl_5F_scanner::kToken_then, C_Lexique_gtl_5F_scanner::kToken_elsif, C_Lexique_gtl_5F_scanner::kToken_else, C_Lexique_gtl_5F_scanner::kToken_foreach, C_Lexique_gtl_5F_scanner::kToken_before, C_Lexique_gtl_5F_scanner::kToken_do, C_Lexique_gtl_5F_scanner::kToken_between, C_Lexique_gtl_5F_scanner::kToken_after, C_Lexique_gtl_5F_scanner::kToken_for, C_Lexique_gtl_5F_scanner::kToken_loop, C_Lexique_gtl_5F_scanner::kToken_up, C_Lexique_gtl_5F_scanner::kToken_down, C_Lexique_gtl_5F_scanner::kToken_step, C_Lexique_gtl_5F_scanner::kToken_repeat, C_Lexique_gtl_5F_scanner::kToken_while, C_Lexique_gtl_5F_scanner::kToken_input, C_Lexique_gtl_5F_scanner::kToken__7C_, C_Lexique_gtl_5F_scanner::kToken__5E_, C_Lexique_gtl_5F_scanner::kToken__26_, C_Lexique_gtl_5F_scanner::kToken__3D__3D_, C_Lexique_gtl_5F_scanner::kToken__21__3D_, C_Lexique_gtl_5F_scanner::kToken__3C__3D_, C_Lexique_gtl_5F_scanner::kToken__3E__3D_, C_Lexique_gtl_5F_scanner::kToken__3E_, C_Lexique_gtl_5F_scanner::kToken__3C_, C_Lexique_gtl_5F_scanner::kToken__3C__3C_, C_Lexique_gtl_5F_scanner::kToken__3E__3E_, C_Lexique_gtl_5F_scanner::kToken__2B_, C_Lexique_gtl_5F_scanner::kToken__2E_, C_Lexique_gtl_5F_scanner::kToken__2D_, C_Lexique_gtl_5F_scanner::kToken__5D_, C_Lexique_gtl_5F_scanner::kToken_by, C_Lexique_gtl_5F_scanner::kToken__7D_, C_Lexique_gtl_5F_scanner::kToken_let, C_Lexique_gtl_5F_scanner::kToken_unlet, C_Lexique_gtl_5F_scanner::kToken_error, C_Lexique_gtl_5F_scanner::kToken_warning, C_Lexique_gtl_5F_scanner::kToken_print, C_Lexique_gtl_5F_scanner::kToken_println, C_Lexique_gtl_5F_scanner::kToken_display, C_Lexique_gtl_5F_scanner::kToken_sort, C_Lexique_gtl_5F_scanner::kToken_tab, C_Lexique_gtl_5F_scanner::kToken_variables, C_Lexique_gtl_5F_scanner::kToken_libraries, C_Lexique_gtl_5F_scanner::kToken__5B__21_, C_Lexique_gtl_5F_scanner::kToken_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__2A_, -1, // Choice 2
C_Lexique_gtl_5F_scanner::kToken__2F_, -1, // Choice 3
C_Lexique_gtl_5F_scanner::kToken_mod, -1, // Choice 4
  -1,
// At index 764 : <select_gtl_5F_expression_5F_parser_5>
C_Lexique_gtl_5F_scanner::kToken__5D_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__3A_, -1, // Choice 2
  -1,
// At index 769 : <select_gtl_5F_expression_5F_parser_6>
C_Lexique_gtl_5F_scanner::kToken__5D_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__2C_, -1, // Choice 2
  -1,
// At index 774 : <select_gtl_5F_expression_5F_parser_7>
C_Lexique_gtl_5F_scanner::kToken__21_, C_Lexique_gtl_5F_scanner::kToken_write, C_Lexique_gtl_5F_scanner::kToken_to, C_Lexique_gtl_5F_scanner::kToken__3A_, C_Lexique_gtl_5F_scanner::kToken_end, C_Lexique_gtl_5F_scanner::kToken_template, C_Lexique_gtl_5F_scanner::kToken__2C_, C_Lexique_gtl_5F_scanner::kToken__29_, C_Lexique_gtl_5F_scanner::kToken_if, C_Lexique_gtl_5F_scanner::kToken_in, C_Lexique_gtl_5F_scanner::kToken_identifier, C_Lexique_gtl_5F_scanner::kToken_or, C_Lexique_gtl_5F_scanner::kToken__3F_, C_Lexique_gtl_5F_scanner::kToken_then, C_Lexique_gtl_5F_scanner::kToken_elsif, C_Lexique_gtl_5F_scanner::kToken_else, C_Lexique_gtl_5F_scanner::kToken_foreach, C_Lexique_gtl_5F_scanner::kToken_before, C_Lexique_gtl_5F_scanner::kToken_do, C_Lexique_gtl_5F_scanner::kToken_between, C_Lexique_gtl_5F_scanner::kToken_after, C_Lexique_gtl_5F_scanner::kToken_for, C_Lexique_gtl_5F_scanner::kToken_loop, C_Lexique_gtl_5F_scanner::kToken_up, C_Lexique_gtl_5F_scanner::kToken_down, C_Lexique_gtl_5F_scanner::kToken_step, C_Lexique_gtl_5F_scanner::kToken_repeat, C_Lexique_gtl_5F_scanner::kToken_while, C_Lexique_gtl_5F_scanner::kToken_input, C_Lexique_gtl_5F_scanner::kToken__7C_, C_Lexique_gtl_5F_scanner::kToken__5E_, C_Lexique_gtl_5F_scanner::kToken__26_, C_Lexique_gtl_5F_scanner::kToken__3D__3D_, C_Lexique_gtl_5F_scanner::kToken__21__3D_, C_Lexique_gtl_5F_scanner::kToken__3C__3D_, C_Lexique_gtl_5F_scanner::kToken__3E__3D_, C_Lexique_gtl_5F_scanner::kToken__3E_, C_Lexique_gtl_5F_scanner::kToken__3C_, C_Lexique_gtl_5F_scanner::kToken__3C__3C_, C_Lexique_gtl_5F_scanner::kToken__3E__3E_, C_Lexique_gtl_5F_scanner::kToken__2B_, C_Lexique_gtl_5F_scanner::kToken__2E_, C_Lexique_gtl_5F_scanner::kToken__2D_, C_Lexique_gtl_5F_scanner::kToken__2A_, C_Lexique_gtl_5F_scanner::kToken__2F_, C_Lexique_gtl_5F_scanner::kToken_mod, C_Lexique_gtl_5F_scanner::kToken__5D_, C_Lexique_gtl_5F_scanner::kToken_by, C_Lexique_gtl_5F_scanner::kToken__7D_, C_Lexique_gtl_5F_scanner::kToken_let, C_Lexique_gtl_5F_scanner::kToken_unlet, C_Lexique_gtl_5F_scanner::kToken_error, C_Lexique_gtl_5F_scanner::kToken_warning, C_Lexique_gtl_5F_scanner::kToken_print, C_Lexique_gtl_5F_scanner::kToken_println, C_Lexique_gtl_5F_scanner::kToken_display, C_Lexique_gtl_5F_scanner::kToken_sort, C_Lexique_gtl_5F_scanner::kToken_tab, C_Lexique_gtl_5F_scanner::kToken_variables, C_Lexique_gtl_5F_scanner::kToken_libraries, C_Lexique_gtl_5F_scanner::kToken__5B__21_, C_Lexique_gtl_5F_scanner::kToken_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__28_, -1, // Choice 2
  -1,
// At index 840 : <select_gtl_5F_expression_5F_parser_8>
C_Lexique_gtl_5F_scanner::kToken__28_, C_Lexique_gtl_5F_scanner::kToken_exists, C_Lexique_gtl_5F_scanner::kToken_identifier, C_Lexique_gtl_5F_scanner::kToken__2B_, C_Lexique_gtl_5F_scanner::kToken__2D_, C_Lexique_gtl_5F_scanner::kToken_not, C_Lexique_gtl_5F_scanner::kToken__7E_, C_Lexique_gtl_5F_scanner::kToken_yes, C_Lexique_gtl_5F_scanner::kToken_no, C_Lexique_gtl_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint, C_Lexique_gtl_5F_scanner::kToken_literal_5F_double, C_Lexique_gtl_5F_scanner::kToken_string, C_Lexique_gtl_5F_scanner::kToken_literal_5F_char, C_Lexique_gtl_5F_scanner::kToken__5B_, C_Lexique_gtl_5F_scanner::kToken_typeof, C_Lexique_gtl_5F_scanner::kToken_true, C_Lexique_gtl_5F_scanner::kToken_false, C_Lexique_gtl_5F_scanner::kToken_literal_5F_enum, C_Lexique_gtl_5F_scanner::kToken__40_, C_Lexique_gtl_5F_scanner::kToken_emptylist, C_Lexique_gtl_5F_scanner::kToken_emptymap, C_Lexique_gtl_5F_scanner::kToken_mapof, C_Lexique_gtl_5F_scanner::kToken_listof, C_Lexique_gtl_5F_scanner::kToken__40__28_, C_Lexique_gtl_5F_scanner::kToken__40__5B_, C_Lexique_gtl_5F_scanner::kToken__40__7B_, C_Lexique_gtl_5F_scanner::kToken__40__21_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__29_, -1, // Choice 2
  -1,
// At index 871 : <select_gtl_5F_expression_5F_parser_9>
C_Lexique_gtl_5F_scanner::kToken__29_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__2C_, -1, // Choice 2
  -1,
// At index 876 : <select_gtl_5F_expression_5F_parser_10>
C_Lexique_gtl_5F_scanner::kToken_default, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__21_, C_Lexique_gtl_5F_scanner::kToken_write, C_Lexique_gtl_5F_scanner::kToken_to, C_Lexique_gtl_5F_scanner::kToken__3A_, C_Lexique_gtl_5F_scanner::kToken_end, C_Lexique_gtl_5F_scanner::kToken_template, C_Lexique_gtl_5F_scanner::kToken__2C_, C_Lexique_gtl_5F_scanner::kToken__29_, C_Lexique_gtl_5F_scanner::kToken_if, C_Lexique_gtl_5F_scanner::kToken_in, C_Lexique_gtl_5F_scanner::kToken_identifier, C_Lexique_gtl_5F_scanner::kToken_or, C_Lexique_gtl_5F_scanner::kToken__3F_, C_Lexique_gtl_5F_scanner::kToken_then, C_Lexique_gtl_5F_scanner::kToken_elsif, C_Lexique_gtl_5F_scanner::kToken_else, C_Lexique_gtl_5F_scanner::kToken_foreach, C_Lexique_gtl_5F_scanner::kToken_before, C_Lexique_gtl_5F_scanner::kToken_do, C_Lexique_gtl_5F_scanner::kToken_between, C_Lexique_gtl_5F_scanner::kToken_after, C_Lexique_gtl_5F_scanner::kToken_for, C_Lexique_gtl_5F_scanner::kToken_loop, C_Lexique_gtl_5F_scanner::kToken_up, C_Lexique_gtl_5F_scanner::kToken_down, C_Lexique_gtl_5F_scanner::kToken_step, C_Lexique_gtl_5F_scanner::kToken_repeat, C_Lexique_gtl_5F_scanner::kToken_while, C_Lexique_gtl_5F_scanner::kToken_input, C_Lexique_gtl_5F_scanner::kToken__7C_, C_Lexique_gtl_5F_scanner::kToken__5E_, C_Lexique_gtl_5F_scanner::kToken__26_, C_Lexique_gtl_5F_scanner::kToken__3D__3D_, C_Lexique_gtl_5F_scanner::kToken__21__3D_, C_Lexique_gtl_5F_scanner::kToken__3C__3D_, C_Lexique_gtl_5F_scanner::kToken__3E__3D_, C_Lexique_gtl_5F_scanner::kToken__3E_, C_Lexique_gtl_5F_scanner::kToken__3C_, C_Lexique_gtl_5F_scanner::kToken__3C__3C_, C_Lexique_gtl_5F_scanner::kToken__3E__3E_, C_Lexique_gtl_5F_scanner::kToken__2B_, C_Lexique_gtl_5F_scanner::kToken__2E_, C_Lexique_gtl_5F_scanner::kToken__2D_, C_Lexique_gtl_5F_scanner::kToken__2A_, C_Lexique_gtl_5F_scanner::kToken__2F_, C_Lexique_gtl_5F_scanner::kToken_mod, C_Lexique_gtl_5F_scanner::kToken__5D_, C_Lexique_gtl_5F_scanner::kToken_by, C_Lexique_gtl_5F_scanner::kToken__7D_, C_Lexique_gtl_5F_scanner::kToken_let, C_Lexique_gtl_5F_scanner::kToken_unlet, C_Lexique_gtl_5F_scanner::kToken_error, C_Lexique_gtl_5F_scanner::kToken_warning, C_Lexique_gtl_5F_scanner::kToken_print, C_Lexique_gtl_5F_scanner::kToken_println, C_Lexique_gtl_5F_scanner::kToken_display, C_Lexique_gtl_5F_scanner::kToken_sort, C_Lexique_gtl_5F_scanner::kToken_tab, C_Lexique_gtl_5F_scanner::kToken_variables, C_Lexique_gtl_5F_scanner::kToken_libraries, C_Lexique_gtl_5F_scanner::kToken__5B__21_, C_Lexique_gtl_5F_scanner::kToken_, -1, // Choice 2
  -1,
// At index 942 : <select_gtl_5F_expression_5F_parser_11>
C_Lexique_gtl_5F_scanner::kToken_by, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken_end, -1, // Choice 2
  -1,
// At index 947 : <select_gtl_5F_expression_5F_parser_12>
C_Lexique_gtl_5F_scanner::kToken__28_, C_Lexique_gtl_5F_scanner::kToken_exists, C_Lexique_gtl_5F_scanner::kToken_identifier, C_Lexique_gtl_5F_scanner::kToken__2B_, C_Lexique_gtl_5F_scanner::kToken__2D_, C_Lexique_gtl_5F_scanner::kToken_not, C_Lexique_gtl_5F_scanner::kToken__7E_, C_Lexique_gtl_5F_scanner::kToken_yes, C_Lexique_gtl_5F_scanner::kToken_no, C_Lexique_gtl_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint, C_Lexique_gtl_5F_scanner::kToken_literal_5F_double, C_Lexique_gtl_5F_scanner::kToken_string, C_Lexique_gtl_5F_scanner::kToken_literal_5F_char, C_Lexique_gtl_5F_scanner::kToken__5B_, C_Lexique_gtl_5F_scanner::kToken_typeof, C_Lexique_gtl_5F_scanner::kToken_true, C_Lexique_gtl_5F_scanner::kToken_false, C_Lexique_gtl_5F_scanner::kToken_literal_5F_enum, C_Lexique_gtl_5F_scanner::kToken__40_, C_Lexique_gtl_5F_scanner::kToken_emptylist, C_Lexique_gtl_5F_scanner::kToken_emptymap, C_Lexique_gtl_5F_scanner::kToken_mapof, C_Lexique_gtl_5F_scanner::kToken_listof, C_Lexique_gtl_5F_scanner::kToken__40__28_, C_Lexique_gtl_5F_scanner::kToken__40__5B_, C_Lexique_gtl_5F_scanner::kToken__40__7B_, C_Lexique_gtl_5F_scanner::kToken__40__21_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__29_, -1, // Choice 2
  -1,
// At index 978 : <select_gtl_5F_expression_5F_parser_13>
C_Lexique_gtl_5F_scanner::kToken__29_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__2C_, -1, // Choice 2
  -1,
// At index 983 : <select_gtl_5F_expression_5F_parser_14>
C_Lexique_gtl_5F_scanner::kToken_string, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__5D_, -1, // Choice 2
  -1,
// At index 988 : <select_gtl_5F_expression_5F_parser_15>
C_Lexique_gtl_5F_scanner::kToken__5D_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__2C_, -1, // Choice 2
  -1,
// At index 993 : <select_gtl_5F_expression_5F_parser_16>
C_Lexique_gtl_5F_scanner::kToken_identifier, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__7D_, -1, // Choice 2
  -1,
// At index 998 : <select_gtl_5F_expression_5F_parser_17>
C_Lexique_gtl_5F_scanner::kToken__7D_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__2C_, -1, // Choice 2
  -1,
// At index 1003 : <select_gtl_5F_expression_5F_parser_18>
C_Lexique_gtl_5F_scanner::kToken__28_, C_Lexique_gtl_5F_scanner::kToken_exists, C_Lexique_gtl_5F_scanner::kToken_identifier, C_Lexique_gtl_5F_scanner::kToken__2B_, C_Lexique_gtl_5F_scanner::kToken__2D_, C_Lexique_gtl_5F_scanner::kToken_not, C_Lexique_gtl_5F_scanner::kToken__7E_, C_Lexique_gtl_5F_scanner::kToken_yes, C_Lexique_gtl_5F_scanner::kToken_no, C_Lexique_gtl_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint, C_Lexique_gtl_5F_scanner::kToken_literal_5F_double, C_Lexique_gtl_5F_scanner::kToken_string, C_Lexique_gtl_5F_scanner::kToken_literal_5F_char, C_Lexique_gtl_5F_scanner::kToken__5B_, C_Lexique_gtl_5F_scanner::kToken_typeof, C_Lexique_gtl_5F_scanner::kToken_true, C_Lexique_gtl_5F_scanner::kToken_false, C_Lexique_gtl_5F_scanner::kToken_literal_5F_enum, C_Lexique_gtl_5F_scanner::kToken__40_, C_Lexique_gtl_5F_scanner::kToken_emptylist, C_Lexique_gtl_5F_scanner::kToken_emptymap, C_Lexique_gtl_5F_scanner::kToken_mapof, C_Lexique_gtl_5F_scanner::kToken_listof, C_Lexique_gtl_5F_scanner::kToken__40__28_, C_Lexique_gtl_5F_scanner::kToken__40__5B_, C_Lexique_gtl_5F_scanner::kToken__40__7B_, C_Lexique_gtl_5F_scanner::kToken__40__21_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__21_, -1, // Choice 2
  -1,
// At index 1034 : <select_gtl_5F_expression_5F_parser_19>
C_Lexique_gtl_5F_scanner::kToken__21_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__2C_, -1, // Choice 2
  -1,
// At index 1039 : <select_gtl_5F_expression_5F_parser_20>
C_Lexique_gtl_5F_scanner::kToken__21_, C_Lexique_gtl_5F_scanner::kToken_write, C_Lexique_gtl_5F_scanner::kToken_to, C_Lexique_gtl_5F_scanner::kToken__3A_, C_Lexique_gtl_5F_scanner::kToken_end, C_Lexique_gtl_5F_scanner::kToken_template, C_Lexique_gtl_5F_scanner::kToken__28_, C_Lexique_gtl_5F_scanner::kToken__2C_, C_Lexique_gtl_5F_scanner::kToken__29_, C_Lexique_gtl_5F_scanner::kToken_if, C_Lexique_gtl_5F_scanner::kToken_in, C_Lexique_gtl_5F_scanner::kToken_identifier, C_Lexique_gtl_5F_scanner::kToken_or, C_Lexique_gtl_5F_scanner::kToken__3F_, C_Lexique_gtl_5F_scanner::kToken_then, C_Lexique_gtl_5F_scanner::kToken_elsif, C_Lexique_gtl_5F_scanner::kToken_else, C_Lexique_gtl_5F_scanner::kToken_foreach, C_Lexique_gtl_5F_scanner::kToken_before, C_Lexique_gtl_5F_scanner::kToken_do, C_Lexique_gtl_5F_scanner::kToken_between, C_Lexique_gtl_5F_scanner::kToken_after, C_Lexique_gtl_5F_scanner::kToken_for, C_Lexique_gtl_5F_scanner::kToken_loop, C_Lexique_gtl_5F_scanner::kToken_up, C_Lexique_gtl_5F_scanner::kToken_down, C_Lexique_gtl_5F_scanner::kToken_step, C_Lexique_gtl_5F_scanner::kToken_repeat, C_Lexique_gtl_5F_scanner::kToken_while, C_Lexique_gtl_5F_scanner::kToken_input, C_Lexique_gtl_5F_scanner::kToken__7C_, C_Lexique_gtl_5F_scanner::kToken__5E_, C_Lexique_gtl_5F_scanner::kToken__26_, C_Lexique_gtl_5F_scanner::kToken__3D__3D_, C_Lexique_gtl_5F_scanner::kToken__21__3D_, C_Lexique_gtl_5F_scanner::kToken__3C__3D_, C_Lexique_gtl_5F_scanner::kToken__3E__3D_, C_Lexique_gtl_5F_scanner::kToken__3E_, C_Lexique_gtl_5F_scanner::kToken__3C_, C_Lexique_gtl_5F_scanner::kToken__3C__3C_, C_Lexique_gtl_5F_scanner::kToken__3E__3E_, C_Lexique_gtl_5F_scanner::kToken__2B_, C_Lexique_gtl_5F_scanner::kToken__2E_, C_Lexique_gtl_5F_scanner::kToken__2D_, C_Lexique_gtl_5F_scanner::kToken__2A_, C_Lexique_gtl_5F_scanner::kToken__2F_, C_Lexique_gtl_5F_scanner::kToken_mod, C_Lexique_gtl_5F_scanner::kToken__5D_, C_Lexique_gtl_5F_scanner::kToken_default, C_Lexique_gtl_5F_scanner::kToken_by, C_Lexique_gtl_5F_scanner::kToken__7D_, C_Lexique_gtl_5F_scanner::kToken_let, C_Lexique_gtl_5F_scanner::kToken__3A__3D_, C_Lexique_gtl_5F_scanner::kToken__2B__3D_, C_Lexique_gtl_5F_scanner::kToken__2D__3D_, C_Lexique_gtl_5F_scanner::kToken__2A__3D_, C_Lexique_gtl_5F_scanner::kToken__2F__3D_, C_Lexique_gtl_5F_scanner::kToken_mod_3D_, C_Lexique_gtl_5F_scanner::kToken__3C__3C__3D_, C_Lexique_gtl_5F_scanner::kToken__3E__3E__3D_, C_Lexique_gtl_5F_scanner::kToken__26__3D_, C_Lexique_gtl_5F_scanner::kToken__7C__3D_, C_Lexique_gtl_5F_scanner::kToken__5E__3D_, C_Lexique_gtl_5F_scanner::kToken_unlet, C_Lexique_gtl_5F_scanner::kToken_error, C_Lexique_gtl_5F_scanner::kToken_warning, C_Lexique_gtl_5F_scanner::kToken_print, C_Lexique_gtl_5F_scanner::kToken_println, C_Lexique_gtl_5F_scanner::kToken_display, C_Lexique_gtl_5F_scanner::kToken_sort, C_Lexique_gtl_5F_scanner::kToken_tab, C_Lexique_gtl_5F_scanner::kToken_variables, C_Lexique_gtl_5F_scanner::kToken_libraries, C_Lexique_gtl_5F_scanner::kToken__5B__21_, C_Lexique_gtl_5F_scanner::kToken_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__3A__3A_, -1, // Choice 2
  -1,
// At index 1118 : <select_gtl_5F_expression_5F_parser_21>
C_Lexique_gtl_5F_scanner::kToken__5B_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__21_, C_Lexique_gtl_5F_scanner::kToken_write, C_Lexique_gtl_5F_scanner::kToken_to, C_Lexique_gtl_5F_scanner::kToken__3A_, C_Lexique_gtl_5F_scanner::kToken_end, C_Lexique_gtl_5F_scanner::kToken_template, C_Lexique_gtl_5F_scanner::kToken__28_, C_Lexique_gtl_5F_scanner::kToken__2C_, C_Lexique_gtl_5F_scanner::kToken__29_, C_Lexique_gtl_5F_scanner::kToken_if, C_Lexique_gtl_5F_scanner::kToken_in, C_Lexique_gtl_5F_scanner::kToken_identifier, C_Lexique_gtl_5F_scanner::kToken_or, C_Lexique_gtl_5F_scanner::kToken__3F_, C_Lexique_gtl_5F_scanner::kToken_then, C_Lexique_gtl_5F_scanner::kToken_elsif, C_Lexique_gtl_5F_scanner::kToken_else, C_Lexique_gtl_5F_scanner::kToken_foreach, C_Lexique_gtl_5F_scanner::kToken_before, C_Lexique_gtl_5F_scanner::kToken_do, C_Lexique_gtl_5F_scanner::kToken_between, C_Lexique_gtl_5F_scanner::kToken_after, C_Lexique_gtl_5F_scanner::kToken_for, C_Lexique_gtl_5F_scanner::kToken_loop, C_Lexique_gtl_5F_scanner::kToken_up, C_Lexique_gtl_5F_scanner::kToken_down, C_Lexique_gtl_5F_scanner::kToken_step, C_Lexique_gtl_5F_scanner::kToken_repeat, C_Lexique_gtl_5F_scanner::kToken_while, C_Lexique_gtl_5F_scanner::kToken_input, C_Lexique_gtl_5F_scanner::kToken__7C_, C_Lexique_gtl_5F_scanner::kToken__5E_, C_Lexique_gtl_5F_scanner::kToken__26_, C_Lexique_gtl_5F_scanner::kToken__3D__3D_, C_Lexique_gtl_5F_scanner::kToken__21__3D_, C_Lexique_gtl_5F_scanner::kToken__3C__3D_, C_Lexique_gtl_5F_scanner::kToken__3E__3D_, C_Lexique_gtl_5F_scanner::kToken__3E_, C_Lexique_gtl_5F_scanner::kToken__3C_, C_Lexique_gtl_5F_scanner::kToken__3C__3C_, C_Lexique_gtl_5F_scanner::kToken__3E__3E_, C_Lexique_gtl_5F_scanner::kToken__2B_, C_Lexique_gtl_5F_scanner::kToken__2E_, C_Lexique_gtl_5F_scanner::kToken__2D_, C_Lexique_gtl_5F_scanner::kToken__2A_, C_Lexique_gtl_5F_scanner::kToken__2F_, C_Lexique_gtl_5F_scanner::kToken_mod, C_Lexique_gtl_5F_scanner::kToken__5D_, C_Lexique_gtl_5F_scanner::kToken_default, C_Lexique_gtl_5F_scanner::kToken_by, C_Lexique_gtl_5F_scanner::kToken__7D_, C_Lexique_gtl_5F_scanner::kToken__3A__3A_, C_Lexique_gtl_5F_scanner::kToken_let, C_Lexique_gtl_5F_scanner::kToken__3A__3D_, C_Lexique_gtl_5F_scanner::kToken__2B__3D_, C_Lexique_gtl_5F_scanner::kToken__2D__3D_, C_Lexique_gtl_5F_scanner::kToken__2A__3D_, C_Lexique_gtl_5F_scanner::kToken__2F__3D_, C_Lexique_gtl_5F_scanner::kToken_mod_3D_, C_Lexique_gtl_5F_scanner::kToken__3C__3C__3D_, C_Lexique_gtl_5F_scanner::kToken__3E__3E__3D_, C_Lexique_gtl_5F_scanner::kToken__26__3D_, C_Lexique_gtl_5F_scanner::kToken__7C__3D_, C_Lexique_gtl_5F_scanner::kToken__5E__3D_, C_Lexique_gtl_5F_scanner::kToken_unlet, C_Lexique_gtl_5F_scanner::kToken_error, C_Lexique_gtl_5F_scanner::kToken_warning, C_Lexique_gtl_5F_scanner::kToken_print, C_Lexique_gtl_5F_scanner::kToken_println, C_Lexique_gtl_5F_scanner::kToken_display, C_Lexique_gtl_5F_scanner::kToken_sort, C_Lexique_gtl_5F_scanner::kToken_tab, C_Lexique_gtl_5F_scanner::kToken_variables, C_Lexique_gtl_5F_scanner::kToken_libraries, C_Lexique_gtl_5F_scanner::kToken__5B__21_, C_Lexique_gtl_5F_scanner::kToken_, -1, // Choice 2
  -1,
// At index 1198 : <select_gtl_5F_expression_5F_parser_22>
C_Lexique_gtl_5F_scanner::kToken__5B_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__21_, C_Lexique_gtl_5F_scanner::kToken_write, C_Lexique_gtl_5F_scanner::kToken_to, C_Lexique_gtl_5F_scanner::kToken__3A_, C_Lexique_gtl_5F_scanner::kToken_end, C_Lexique_gtl_5F_scanner::kToken_template, C_Lexique_gtl_5F_scanner::kToken__28_, C_Lexique_gtl_5F_scanner::kToken__2C_, C_Lexique_gtl_5F_scanner::kToken__29_, C_Lexique_gtl_5F_scanner::kToken_if, C_Lexique_gtl_5F_scanner::kToken_in, C_Lexique_gtl_5F_scanner::kToken_identifier, C_Lexique_gtl_5F_scanner::kToken_or, C_Lexique_gtl_5F_scanner::kToken__3F_, C_Lexique_gtl_5F_scanner::kToken_then, C_Lexique_gtl_5F_scanner::kToken_elsif, C_Lexique_gtl_5F_scanner::kToken_else, C_Lexique_gtl_5F_scanner::kToken_foreach, C_Lexique_gtl_5F_scanner::kToken_before, C_Lexique_gtl_5F_scanner::kToken_do, C_Lexique_gtl_5F_scanner::kToken_between, C_Lexique_gtl_5F_scanner::kToken_after, C_Lexique_gtl_5F_scanner::kToken_for, C_Lexique_gtl_5F_scanner::kToken_loop, C_Lexique_gtl_5F_scanner::kToken_up, C_Lexique_gtl_5F_scanner::kToken_down, C_Lexique_gtl_5F_scanner::kToken_step, C_Lexique_gtl_5F_scanner::kToken_repeat, C_Lexique_gtl_5F_scanner::kToken_while, C_Lexique_gtl_5F_scanner::kToken_input, C_Lexique_gtl_5F_scanner::kToken__7C_, C_Lexique_gtl_5F_scanner::kToken__5E_, C_Lexique_gtl_5F_scanner::kToken__26_, C_Lexique_gtl_5F_scanner::kToken__3D__3D_, C_Lexique_gtl_5F_scanner::kToken__21__3D_, C_Lexique_gtl_5F_scanner::kToken__3C__3D_, C_Lexique_gtl_5F_scanner::kToken__3E__3D_, C_Lexique_gtl_5F_scanner::kToken__3E_, C_Lexique_gtl_5F_scanner::kToken__3C_, C_Lexique_gtl_5F_scanner::kToken__3C__3C_, C_Lexique_gtl_5F_scanner::kToken__3E__3E_, C_Lexique_gtl_5F_scanner::kToken__2B_, C_Lexique_gtl_5F_scanner::kToken__2E_, C_Lexique_gtl_5F_scanner::kToken__2D_, C_Lexique_gtl_5F_scanner::kToken__2A_, C_Lexique_gtl_5F_scanner::kToken__2F_, C_Lexique_gtl_5F_scanner::kToken_mod, C_Lexique_gtl_5F_scanner::kToken__5D_, C_Lexique_gtl_5F_scanner::kToken_default, C_Lexique_gtl_5F_scanner::kToken_by, C_Lexique_gtl_5F_scanner::kToken__7D_, C_Lexique_gtl_5F_scanner::kToken__3A__3A_, C_Lexique_gtl_5F_scanner::kToken_let, C_Lexique_gtl_5F_scanner::kToken__3A__3D_, C_Lexique_gtl_5F_scanner::kToken__2B__3D_, C_Lexique_gtl_5F_scanner::kToken__2D__3D_, C_Lexique_gtl_5F_scanner::kToken__2A__3D_, C_Lexique_gtl_5F_scanner::kToken__2F__3D_, C_Lexique_gtl_5F_scanner::kToken_mod_3D_, C_Lexique_gtl_5F_scanner::kToken__3C__3C__3D_, C_Lexique_gtl_5F_scanner::kToken__3E__3E__3D_, C_Lexique_gtl_5F_scanner::kToken__26__3D_, C_Lexique_gtl_5F_scanner::kToken__7C__3D_, C_Lexique_gtl_5F_scanner::kToken__5E__3D_, C_Lexique_gtl_5F_scanner::kToken_unlet, C_Lexique_gtl_5F_scanner::kToken_error, C_Lexique_gtl_5F_scanner::kToken_warning, C_Lexique_gtl_5F_scanner::kToken_print, C_Lexique_gtl_5F_scanner::kToken_println, C_Lexique_gtl_5F_scanner::kToken_display, C_Lexique_gtl_5F_scanner::kToken_sort, C_Lexique_gtl_5F_scanner::kToken_tab, C_Lexique_gtl_5F_scanner::kToken_variables, C_Lexique_gtl_5F_scanner::kToken_libraries, C_Lexique_gtl_5F_scanner::kToken__5B__21_, C_Lexique_gtl_5F_scanner::kToken_, -1, // Choice 2
  -1,
// At index 1278 : <select_gtl_5F_expression_5F_parser_23>
C_Lexique_gtl_5F_scanner::kToken__21_, C_Lexique_gtl_5F_scanner::kToken_write, C_Lexique_gtl_5F_scanner::kToken_to, C_Lexique_gtl_5F_scanner::kToken__3A_, C_Lexique_gtl_5F_scanner::kToken_end, C_Lexique_gtl_5F_scanner::kToken_template, C_Lexique_gtl_5F_scanner::kToken__28_, C_Lexique_gtl_5F_scanner::kToken__2C_, C_Lexique_gtl_5F_scanner::kToken__29_, C_Lexique_gtl_5F_scanner::kToken_if, C_Lexique_gtl_5F_scanner::kToken_in, C_Lexique_gtl_5F_scanner::kToken_identifier, C_Lexique_gtl_5F_scanner::kToken_or, C_Lexique_gtl_5F_scanner::kToken__3F_, C_Lexique_gtl_5F_scanner::kToken_then, C_Lexique_gtl_5F_scanner::kToken_elsif, C_Lexique_gtl_5F_scanner::kToken_else, C_Lexique_gtl_5F_scanner::kToken_foreach, C_Lexique_gtl_5F_scanner::kToken_before, C_Lexique_gtl_5F_scanner::kToken_do, C_Lexique_gtl_5F_scanner::kToken_between, C_Lexique_gtl_5F_scanner::kToken_after, C_Lexique_gtl_5F_scanner::kToken_for, C_Lexique_gtl_5F_scanner::kToken_loop, C_Lexique_gtl_5F_scanner::kToken_up, C_Lexique_gtl_5F_scanner::kToken_down, C_Lexique_gtl_5F_scanner::kToken_step, C_Lexique_gtl_5F_scanner::kToken_repeat, C_Lexique_gtl_5F_scanner::kToken_while, C_Lexique_gtl_5F_scanner::kToken_input, C_Lexique_gtl_5F_scanner::kToken__7C_, C_Lexique_gtl_5F_scanner::kToken__5E_, C_Lexique_gtl_5F_scanner::kToken__26_, C_Lexique_gtl_5F_scanner::kToken__3D__3D_, C_Lexique_gtl_5F_scanner::kToken__21__3D_, C_Lexique_gtl_5F_scanner::kToken__3C__3D_, C_Lexique_gtl_5F_scanner::kToken__3E__3D_, C_Lexique_gtl_5F_scanner::kToken__3E_, C_Lexique_gtl_5F_scanner::kToken__3C_, C_Lexique_gtl_5F_scanner::kToken__3C__3C_, C_Lexique_gtl_5F_scanner::kToken__3E__3E_, C_Lexique_gtl_5F_scanner::kToken__2B_, C_Lexique_gtl_5F_scanner::kToken__2E_, C_Lexique_gtl_5F_scanner::kToken__2D_, C_Lexique_gtl_5F_scanner::kToken__2A_, C_Lexique_gtl_5F_scanner::kToken__2F_, C_Lexique_gtl_5F_scanner::kToken_mod, C_Lexique_gtl_5F_scanner::kToken__5D_, C_Lexique_gtl_5F_scanner::kToken_default, C_Lexique_gtl_5F_scanner::kToken_by, C_Lexique_gtl_5F_scanner::kToken__7D_, C_Lexique_gtl_5F_scanner::kToken__3A__3A_, C_Lexique_gtl_5F_scanner::kToken_let, C_Lexique_gtl_5F_scanner::kToken__3A__3D_, C_Lexique_gtl_5F_scanner::kToken__2B__3D_, C_Lexique_gtl_5F_scanner::kToken__2D__3D_, C_Lexique_gtl_5F_scanner::kToken__2A__3D_, C_Lexique_gtl_5F_scanner::kToken__2F__3D_, C_Lexique_gtl_5F_scanner::kToken_mod_3D_, C_Lexique_gtl_5F_scanner::kToken__3C__3C__3D_, C_Lexique_gtl_5F_scanner::kToken__3E__3E__3D_, C_Lexique_gtl_5F_scanner::kToken__26__3D_, C_Lexique_gtl_5F_scanner::kToken__7C__3D_, C_Lexique_gtl_5F_scanner::kToken__5E__3D_, C_Lexique_gtl_5F_scanner::kToken_unlet, C_Lexique_gtl_5F_scanner::kToken_error, C_Lexique_gtl_5F_scanner::kToken_warning, C_Lexique_gtl_5F_scanner::kToken_print, C_Lexique_gtl_5F_scanner::kToken_println, C_Lexique_gtl_5F_scanner::kToken_display, C_Lexique_gtl_5F_scanner::kToken_sort, C_Lexique_gtl_5F_scanner::kToken_tab, C_Lexique_gtl_5F_scanner::kToken_variables, C_Lexique_gtl_5F_scanner::kToken_libraries, C_Lexique_gtl_5F_scanner::kToken__5B__21_, C_Lexique_gtl_5F_scanner::kToken_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__5B_, -1, // Choice 2
  -1,
// At index 1358 : <select_gtl_5F_expression_5F_parser_24>
C_Lexique_gtl_5F_scanner::kToken_here, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken_identifier, -1, // Choice 2
  -1,
// At index 1363 : <select_gtl_5F_expression_5F_parser_25>
C_Lexique_gtl_5F_scanner::kToken_identifier, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__29_, -1, // Choice 2
  -1,
// At index 1368 : <select_gtl_5F_expression_5F_parser_26>
C_Lexique_gtl_5F_scanner::kToken__29_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__2C_, -1, // Choice 2
  -1,
// At index 1373 : <select_gtl_5F_expression_5F_parser_27>
C_Lexique_gtl_5F_scanner::kToken__3A_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__2C_, C_Lexique_gtl_5F_scanner::kToken__29_, -1, // Choice 2
  -1,
// At index 1379 : <select_gtl_5F_instruction_5F_parser_0>
C_Lexique_gtl_5F_scanner::kToken__3A__3D_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__2B__3D_, -1, // Choice 2
C_Lexique_gtl_5F_scanner::kToken__2D__3D_, -1, // Choice 3
C_Lexique_gtl_5F_scanner::kToken__2A__3D_, -1, // Choice 4
C_Lexique_gtl_5F_scanner::kToken__2F__3D_, -1, // Choice 5
C_Lexique_gtl_5F_scanner::kToken_mod_3D_, -1, // Choice 6
C_Lexique_gtl_5F_scanner::kToken__3C__3C__3D_, -1, // Choice 7
C_Lexique_gtl_5F_scanner::kToken__3E__3E__3D_, -1, // Choice 8
C_Lexique_gtl_5F_scanner::kToken__26__3D_, -1, // Choice 9
C_Lexique_gtl_5F_scanner::kToken__7C__3D_, -1, // Choice 10
C_Lexique_gtl_5F_scanner::kToken__5E__3D_, -1, // Choice 11
C_Lexique_gtl_5F_scanner::kToken__21_, C_Lexique_gtl_5F_scanner::kToken_write, C_Lexique_gtl_5F_scanner::kToken_end, C_Lexique_gtl_5F_scanner::kToken_template, C_Lexique_gtl_5F_scanner::kToken_if, C_Lexique_gtl_5F_scanner::kToken__3F_, C_Lexique_gtl_5F_scanner::kToken_elsif, C_Lexique_gtl_5F_scanner::kToken_else, C_Lexique_gtl_5F_scanner::kToken_foreach, C_Lexique_gtl_5F_scanner::kToken_do, C_Lexique_gtl_5F_scanner::kToken_between, C_Lexique_gtl_5F_scanner::kToken_after, C_Lexique_gtl_5F_scanner::kToken_for, C_Lexique_gtl_5F_scanner::kToken_loop, C_Lexique_gtl_5F_scanner::kToken_repeat, C_Lexique_gtl_5F_scanner::kToken_while, C_Lexique_gtl_5F_scanner::kToken_input, C_Lexique_gtl_5F_scanner::kToken_let, C_Lexique_gtl_5F_scanner::kToken_unlet, C_Lexique_gtl_5F_scanner::kToken_error, C_Lexique_gtl_5F_scanner::kToken_warning, C_Lexique_gtl_5F_scanner::kToken_print, C_Lexique_gtl_5F_scanner::kToken_println, C_Lexique_gtl_5F_scanner::kToken_display, C_Lexique_gtl_5F_scanner::kToken_sort, C_Lexique_gtl_5F_scanner::kToken_tab, C_Lexique_gtl_5F_scanner::kToken_variables, C_Lexique_gtl_5F_scanner::kToken_libraries, C_Lexique_gtl_5F_scanner::kToken__5B__21_, C_Lexique_gtl_5F_scanner::kToken_, -1, // Choice 12
  -1,
// At index 1433 : <select_gtl_5F_instruction_5F_parser_1>
C_Lexique_gtl_5F_scanner::kToken__28_, C_Lexique_gtl_5F_scanner::kToken_exists, C_Lexique_gtl_5F_scanner::kToken_identifier, C_Lexique_gtl_5F_scanner::kToken__2B_, C_Lexique_gtl_5F_scanner::kToken__2D_, C_Lexique_gtl_5F_scanner::kToken_not, C_Lexique_gtl_5F_scanner::kToken__7E_, C_Lexique_gtl_5F_scanner::kToken_yes, C_Lexique_gtl_5F_scanner::kToken_no, C_Lexique_gtl_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint, C_Lexique_gtl_5F_scanner::kToken_literal_5F_double, C_Lexique_gtl_5F_scanner::kToken_string, C_Lexique_gtl_5F_scanner::kToken_literal_5F_char, C_Lexique_gtl_5F_scanner::kToken__5B_, C_Lexique_gtl_5F_scanner::kToken_typeof, C_Lexique_gtl_5F_scanner::kToken_true, C_Lexique_gtl_5F_scanner::kToken_false, C_Lexique_gtl_5F_scanner::kToken_literal_5F_enum, C_Lexique_gtl_5F_scanner::kToken__40_, C_Lexique_gtl_5F_scanner::kToken_emptylist, C_Lexique_gtl_5F_scanner::kToken_emptymap, C_Lexique_gtl_5F_scanner::kToken_mapof, C_Lexique_gtl_5F_scanner::kToken_listof, C_Lexique_gtl_5F_scanner::kToken__40__28_, C_Lexique_gtl_5F_scanner::kToken__40__5B_, C_Lexique_gtl_5F_scanner::kToken__40__7B_, C_Lexique_gtl_5F_scanner::kToken__40__21_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__21_, C_Lexique_gtl_5F_scanner::kToken_write, C_Lexique_gtl_5F_scanner::kToken_end, C_Lexique_gtl_5F_scanner::kToken_template, C_Lexique_gtl_5F_scanner::kToken_if, C_Lexique_gtl_5F_scanner::kToken__3F_, C_Lexique_gtl_5F_scanner::kToken_elsif, C_Lexique_gtl_5F_scanner::kToken_else, C_Lexique_gtl_5F_scanner::kToken_foreach, C_Lexique_gtl_5F_scanner::kToken_do, C_Lexique_gtl_5F_scanner::kToken_between, C_Lexique_gtl_5F_scanner::kToken_after, C_Lexique_gtl_5F_scanner::kToken_for, C_Lexique_gtl_5F_scanner::kToken_loop, C_Lexique_gtl_5F_scanner::kToken_repeat, C_Lexique_gtl_5F_scanner::kToken_while, C_Lexique_gtl_5F_scanner::kToken_input, C_Lexique_gtl_5F_scanner::kToken_let, C_Lexique_gtl_5F_scanner::kToken_unlet, C_Lexique_gtl_5F_scanner::kToken_error, C_Lexique_gtl_5F_scanner::kToken_warning, C_Lexique_gtl_5F_scanner::kToken_print, C_Lexique_gtl_5F_scanner::kToken_println, C_Lexique_gtl_5F_scanner::kToken_display, C_Lexique_gtl_5F_scanner::kToken_sort, C_Lexique_gtl_5F_scanner::kToken_tab, C_Lexique_gtl_5F_scanner::kToken_variables, C_Lexique_gtl_5F_scanner::kToken_libraries, C_Lexique_gtl_5F_scanner::kToken__5B__21_, C_Lexique_gtl_5F_scanner::kToken_, -1, // Choice 2
  -1,
// At index 1493 : <select_gtl_5F_instruction_5F_parser_2>
C_Lexique_gtl_5F_scanner::kToken_by, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__3E_, C_Lexique_gtl_5F_scanner::kToken__3C_, -1, // Choice 2
  -1,
// At index 1499 : <select_gtl_5F_instruction_5F_parser_3>
C_Lexique_gtl_5F_scanner::kToken__21_, C_Lexique_gtl_5F_scanner::kToken_write, C_Lexique_gtl_5F_scanner::kToken_end, C_Lexique_gtl_5F_scanner::kToken_template, C_Lexique_gtl_5F_scanner::kToken_if, C_Lexique_gtl_5F_scanner::kToken__3F_, C_Lexique_gtl_5F_scanner::kToken_elsif, C_Lexique_gtl_5F_scanner::kToken_else, C_Lexique_gtl_5F_scanner::kToken_foreach, C_Lexique_gtl_5F_scanner::kToken_do, C_Lexique_gtl_5F_scanner::kToken_between, C_Lexique_gtl_5F_scanner::kToken_after, C_Lexique_gtl_5F_scanner::kToken_for, C_Lexique_gtl_5F_scanner::kToken_loop, C_Lexique_gtl_5F_scanner::kToken_repeat, C_Lexique_gtl_5F_scanner::kToken_while, C_Lexique_gtl_5F_scanner::kToken_input, C_Lexique_gtl_5F_scanner::kToken_let, C_Lexique_gtl_5F_scanner::kToken_unlet, C_Lexique_gtl_5F_scanner::kToken_error, C_Lexique_gtl_5F_scanner::kToken_warning, C_Lexique_gtl_5F_scanner::kToken_print, C_Lexique_gtl_5F_scanner::kToken_println, C_Lexique_gtl_5F_scanner::kToken_display, C_Lexique_gtl_5F_scanner::kToken_sort, C_Lexique_gtl_5F_scanner::kToken_tab, C_Lexique_gtl_5F_scanner::kToken_variables, C_Lexique_gtl_5F_scanner::kToken_libraries, C_Lexique_gtl_5F_scanner::kToken__5B__21_, C_Lexique_gtl_5F_scanner::kToken_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__2C_, -1, // Choice 2
  -1,
// At index 1533 : <select_gtl_5F_instruction_5F_parser_4>
C_Lexique_gtl_5F_scanner::kToken__5D_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__3A_, -1, // Choice 2
  -1,
// At index 1538 : <select_gtl_5F_instruction_5F_parser_5>
C_Lexique_gtl_5F_scanner::kToken__5D_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__2C_, -1, // Choice 2
  -1,
// At index 1543 : <select_gtl_5F_instruction_5F_parser_6>
C_Lexique_gtl_5F_scanner::kToken__3E_, -1, // Choice 1
C_Lexique_gtl_5F_scanner::kToken__3C_, -1, // Choice 2
  -1,
// At index 1548 : <> only one production, no choice
  -1,
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            L L ( 1 )    D E C I S I O N    T A B L E S    I N D E X E S                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gDecisionIndexes_gtl_grammar [79] = {
0, // at 0 : <gtl_expression>
1, // at 1 : <gtl_variable>
2, // at 2 : <gtl_variable_or_here>
3, // at 3 : <gtl_import>
4, // at 4 : <gtl_simple_instruction>
29, // at 5 : <gtl_argument_list>
30, // at 6 : <gtl_start_symbol>
31, // at 7 : <gtl_template_instruction_list>
32, // at 8 : <gtl_template_instruction>
53, // at 9 : <gtl_file_name>
54, // at 10 : <gtl_relation_term>
55, // at 11 : <gtl_relation_factor>
56, // at 12 : <gtl_simple_expression>
57, // at 13 : <gtl_term>
58, // at 14 : <gtl_factor>
113, // at 15 : <gtl_sorting_order>
114, // at 16 : <select_gtl_5F_parser_0>
141, // at 17 : <select_gtl_5F_parser_1>
175, // at 18 : <select_gtl_5F_parser_2>
206, // at 19 : <select_gtl_5F_parser_3>
213, // at 20 : <select_gtl_5F_parser_4>
244, // at 21 : <select_gtl_5F_parser_5>
249, // at 22 : <select_gtl_5F_parser_6>
255, // at 23 : <select_gtl_5F_parser_7>
290, // at 24 : <select_gtl_5F_parser_8>
324, // at 25 : <select_gtl_5F_parser_9>
358, // at 26 : <select_gtl_5F_parser_10>
364, // at 27 : <select_gtl_5F_parser_11>
369, // at 28 : <select_gtl_5F_parser_12>
375, // at 29 : <select_gtl_5F_parser_13>
380, // at 30 : <select_gtl_5F_parser_14>
385, // at 31 : <select_gtl_5F_parser_15>
391, // at 32 : <select_gtl_5F_parser_16>
396, // at 33 : <select_gtl_5F_parser_17>
401, // at 34 : <select_gtl_5F_parser_18>
406, // at 35 : <select_gtl_5F_parser_19>
413, // at 36 : <select_gtl_5F_parser_20>
419, // at 37 : <select_gtl_5F_parser_21>
424, // at 38 : <select_gtl_5F_parser_22>
430, // at 39 : <select_gtl_5F_parser_23>
435, // at 40 : <select_gtl_5F_parser_24>
462, // at 41 : <select_gtl_5F_parser_25>
467, // at 42 : <select_gtl_5F_expression_5F_parser_0>
518, // at 43 : <select_gtl_5F_expression_5F_parser_1>
569, // at 44 : <select_gtl_5F_expression_5F_parser_2>
631, // at 45 : <select_gtl_5F_expression_5F_parser_3>
697, // at 46 : <select_gtl_5F_expression_5F_parser_4>
764, // at 47 : <select_gtl_5F_expression_5F_parser_5>
769, // at 48 : <select_gtl_5F_expression_5F_parser_6>
774, // at 49 : <select_gtl_5F_expression_5F_parser_7>
840, // at 50 : <select_gtl_5F_expression_5F_parser_8>
871, // at 51 : <select_gtl_5F_expression_5F_parser_9>
876, // at 52 : <select_gtl_5F_expression_5F_parser_10>
942, // at 53 : <select_gtl_5F_expression_5F_parser_11>
947, // at 54 : <select_gtl_5F_expression_5F_parser_12>
978, // at 55 : <select_gtl_5F_expression_5F_parser_13>
983, // at 56 : <select_gtl_5F_expression_5F_parser_14>
988, // at 57 : <select_gtl_5F_expression_5F_parser_15>
993, // at 58 : <select_gtl_5F_expression_5F_parser_16>
998, // at 59 : <select_gtl_5F_expression_5F_parser_17>
1003, // at 60 : <select_gtl_5F_expression_5F_parser_18>
1034, // at 61 : <select_gtl_5F_expression_5F_parser_19>
1039, // at 62 : <select_gtl_5F_expression_5F_parser_20>
1118, // at 63 : <select_gtl_5F_expression_5F_parser_21>
1198, // at 64 : <select_gtl_5F_expression_5F_parser_22>
1278, // at 65 : <select_gtl_5F_expression_5F_parser_23>
1358, // at 66 : <select_gtl_5F_expression_5F_parser_24>
1363, // at 67 : <select_gtl_5F_expression_5F_parser_25>
1368, // at 68 : <select_gtl_5F_expression_5F_parser_26>
1373, // at 69 : <select_gtl_5F_expression_5F_parser_27>
1379, // at 70 : <select_gtl_5F_instruction_5F_parser_0>
1433, // at 71 : <select_gtl_5F_instruction_5F_parser_1>
1493, // at 72 : <select_gtl_5F_instruction_5F_parser_2>
1499, // at 73 : <select_gtl_5F_instruction_5F_parser_3>
1533, // at 74 : <select_gtl_5F_instruction_5F_parser_4>
1538, // at 75 : <select_gtl_5F_instruction_5F_parser_5>
1543, // at 76 : <select_gtl_5F_instruction_5F_parser_6>
1548, // at 77 : <>
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                    'gtl_expression' non terminal implementation                                      
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_gtl_5F_grammar::nt_gtl_5F_expression_parse (C_Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_expression_i0_parse(inLexique) ;
}

void cGrammar_gtl_5F_grammar::nt_gtl_5F_expression_ (GALGAS_gtlExpression & parameter_1,
                                C_Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_expression_i0_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                     'gtl_variable' non terminal implementation                                       
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_gtl_5F_grammar::nt_gtl_5F_variable_parse (C_Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_variable_i32_parse(inLexique) ;
}

void cGrammar_gtl_5F_grammar::nt_gtl_5F_variable_ (GALGAS_gtlVarPath & parameter_1,
                                C_Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_variable_i32_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                 'gtl_variable_or_here' non terminal implementation                                   
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_gtl_5F_grammar::nt_gtl_5F_variable_5F_or_5F_here_parse (C_Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_variable_5F_or_5F_here_i33_parse(inLexique) ;
}

void cGrammar_gtl_5F_grammar::nt_gtl_5F_variable_5F_or_5F_here_ (GALGAS_gtlVarPath & parameter_1,
                                GALGAS_bool & parameter_2,
                                C_Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_variable_5F_or_5F_here_i33_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                      'gtl_import' non terminal implementation                                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_gtl_5F_grammar::nt_gtl_5F_import_parse (C_Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_instruction_5F_parser_gtl_5F_import_i13_parse(inLexique) ;
}

void cGrammar_gtl_5F_grammar::nt_gtl_5F_import_ (GALGAS_gtlContext parameter_1,
                                GALGAS_library & parameter_2,
                                C_Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_instruction_5F_parser_gtl_5F_import_i13_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                'gtl_simple_instruction' non terminal implementation                                  
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_gtl_5F_grammar::nt_gtl_5F_simple_5F_instruction_parse (C_Lexique_gtl_5F_scanner * inLexique) {
  switch (inLexique->nextProductionIndex ()) {
  case 1 :
    rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i0_parse(inLexique) ;
    break ;
  case 2 :
    rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i1_parse(inLexique) ;
    break ;
  case 3 :
    rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i2_parse(inLexique) ;
    break ;
  case 4 :
    rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i3_parse(inLexique) ;
    break ;
  case 5 :
    rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i4_parse(inLexique) ;
    break ;
  case 6 :
    rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i5_parse(inLexique) ;
    break ;
  case 7 :
    rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i6_parse(inLexique) ;
    break ;
  case 8 :
    rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i7_parse(inLexique) ;
    break ;
  case 9 :
    rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i8_parse(inLexique) ;
    break ;
  case 10 :
    rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i9_parse(inLexique) ;
    break ;
  case 11 :
    rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i10_parse(inLexique) ;
    break ;
  case 12 :
    rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i11_parse(inLexique) ;
    break ;
  default :
    break ;
  }
}

void cGrammar_gtl_5F_grammar::nt_gtl_5F_simple_5F_instruction_ (GALGAS_gtlInstruction & parameter_1,
                                C_Lexique_gtl_5F_scanner * inLexique) {
  switch (inLexique->nextProductionIndex ()) {
  case 1 :
    rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i0_(parameter_1, inLexique) ;
    break ;
  case 2 :
    rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i1_(parameter_1, inLexique) ;
    break ;
  case 3 :
    rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i2_(parameter_1, inLexique) ;
    break ;
  case 4 :
    rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i3_(parameter_1, inLexique) ;
    break ;
  case 5 :
    rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i4_(parameter_1, inLexique) ;
    break ;
  case 6 :
    rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i5_(parameter_1, inLexique) ;
    break ;
  case 7 :
    rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i6_(parameter_1, inLexique) ;
    break ;
  case 8 :
    rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i7_(parameter_1, inLexique) ;
    break ;
  case 9 :
    rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i8_(parameter_1, inLexique) ;
    break ;
  case 10 :
    rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i9_(parameter_1, inLexique) ;
    break ;
  case 11 :
    rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i10_(parameter_1, inLexique) ;
    break ;
  case 12 :
    rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i11_(parameter_1, inLexique) ;
    break ;
  default :
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                  'gtl_argument_list' non terminal implementation                                     
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_gtl_5F_grammar::nt_gtl_5F_argument_5F_list_parse (C_Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_argument_5F_list_i34_parse(inLexique) ;
}

void cGrammar_gtl_5F_grammar::nt_gtl_5F_argument_5F_list_ (GALGAS_gtlArgumentList & parameter_1,
                                C_Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_argument_5F_list_i34_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                   'gtl_start_symbol' non terminal implementation                                     
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_gtl_5F_grammar::nt_gtl_5F_start_5F_symbol_parse (C_Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_parser_gtl_5F_start_5F_symbol_i0_parse(inLexique) ;
}

void cGrammar_gtl_5F_grammar::nt_gtl_5F_start_5F_symbol_ (GALGAS_gtlContext parameter_1,
                                GALGAS_library & parameter_2,
                                GALGAS_gtlInstructionList & parameter_3,
                                C_Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_parser_gtl_5F_start_5F_symbol_i0_(parameter_1, parameter_2, parameter_3, inLexique) ;
}

void cGrammar_gtl_5F_grammar::performIndexing (C_Compiler * /* inCompiler */,
             const C_String & /* inSourceFilePath */) {
}

void cGrammar_gtl_5F_grammar::performOnlyLexicalAnalysis (C_Compiler * inCompiler,
             const C_String & inSourceFilePath) {
  C_Lexique_gtl_5F_scanner * scanner = NULL ;
  macroMyNew (scanner, C_Lexique_gtl_5F_scanner (inCompiler, "", "", inSourceFilePath COMMA_HERE)) ;
  if (scanner->sourceText () != NULL) {
    scanner->performLexicalAnalysis () ;
  }
  macroDetachSharedObject (scanner) ;
}

void cGrammar_gtl_5F_grammar::performOnlySyntaxAnalysis (C_Compiler * inCompiler,
             const C_String & inSourceFilePath) {
  C_Lexique_gtl_5F_scanner * scanner = NULL ;
  macroMyNew (scanner, C_Lexique_gtl_5F_scanner (inCompiler, "", "", inSourceFilePath COMMA_HERE)) ;
  if (scanner->sourceText () != NULL) {
    scanner->performTopDownParsing (gProductions_gtl_grammar, gProductionNames_gtl_grammar, gProductionIndexes_gtl_grammar,
                                    gFirstProductionIndexes_gtl_grammar, gDecision_gtl_grammar, gDecisionIndexes_gtl_grammar, 620) ;
  }
  macroDetachSharedObject (scanner) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                        Grammar start symbol implementation                                           
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_gtl_5F_grammar::_performSourceFileParsing_ (C_Compiler * inCompiler,
                                GALGAS_lstring inFilePath,
                                GALGAS_gtlContext  parameter_1,
                                GALGAS_library &  parameter_2,
                                GALGAS_gtlInstructionList &  parameter_3
                                COMMA_LOCATION_ARGS) {
  if (inFilePath.isValid ()) {
    const GALGAS_string filePathAsString = inFilePath.getter_string (HERE) ;
    C_String filePath = filePathAsString.stringValue () ;
    if (! C_FileManager::isAbsolutePath (filePath)) {
      filePath = inCompiler->sourceFilePath ().stringByDeletingLastPathComponent ().stringByAppendingPathComponent (filePath) ;
    }
    if (C_FileManager::fileExistsAtPath (filePath)) {
    C_Lexique_gtl_5F_scanner * scanner = NULL ;
    macroMyNew (scanner, C_Lexique_gtl_5F_scanner (inCompiler, "", "", filePath COMMA_HERE)) ;
    if (scanner->sourceText () != NULL) {
      const bool ok = scanner->performTopDownParsing (gProductions_gtl_grammar, gProductionNames_gtl_grammar, gProductionIndexes_gtl_grammar,
                                                      gFirstProductionIndexes_gtl_grammar, gDecision_gtl_grammar, gDecisionIndexes_gtl_grammar, 620) ;
      if (ok && ! executionModeIsSyntaxAnalysisOnly ()) {
        cGrammar_gtl_5F_grammar grammar ;
        grammar.nt_gtl_5F_start_5F_symbol_ (parameter_1, parameter_2, parameter_3, scanner) ;
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

void cGrammar_gtl_5F_grammar::_performSourceStringParsing_ (C_Compiler * inCompiler,
                                GALGAS_string inSourceString,
                                GALGAS_string inNameString,
                                GALGAS_gtlContext  parameter_1,
                                GALGAS_library &  parameter_2,
                                GALGAS_gtlInstructionList &  parameter_3
                                COMMA_UNUSED_LOCATION_ARGS) {
  if (inSourceString.isValid () && inNameString.isValid ()) {
    const C_String sourceString = inSourceString.stringValue () ;
    const C_String nameString = inNameString.stringValue () ;
    C_Lexique_gtl_5F_scanner * scanner = NULL ;
    macroMyNew (scanner, C_Lexique_gtl_5F_scanner (inCompiler, sourceString, nameString COMMA_HERE)) ;
    const bool ok = scanner->performTopDownParsing (gProductions_gtl_grammar, gProductionNames_gtl_grammar, gProductionIndexes_gtl_grammar,
                                                    gFirstProductionIndexes_gtl_grammar, gDecision_gtl_grammar, gDecisionIndexes_gtl_grammar, 620) ;
    if (ok && ! executionModeIsSyntaxAnalysisOnly ()) {
      cGrammar_gtl_5F_grammar grammar ;
      grammar.nt_gtl_5F_start_5F_symbol_ (parameter_1, parameter_2, parameter_3, scanner) ;
    }
    macroDetachSharedObject (scanner) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'gtl_template_instruction_list' non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_gtl_5F_grammar::nt_gtl_5F_template_5F_instruction_5F_list_parse (C_Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_parser_gtl_5F_template_5F_instruction_5F_list_i1_parse(inLexique) ;
}

void cGrammar_gtl_5F_grammar::nt_gtl_5F_template_5F_instruction_5F_list_ (GALGAS_gtlInstructionList & parameter_1,
                                C_Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_parser_gtl_5F_template_5F_instruction_5F_list_i1_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                               'gtl_template_instruction' non terminal implementation                                 
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_gtl_5F_grammar::nt_gtl_5F_template_5F_instruction_parse (C_Lexique_gtl_5F_scanner * inLexique) {
  switch (inLexique->nextProductionIndex ()) {
  case 1 :
    rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i2_parse(inLexique) ;
    break ;
  case 2 :
    rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i3_parse(inLexique) ;
    break ;
  case 3 :
    rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i4_parse(inLexique) ;
    break ;
  case 4 :
    rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i5_parse(inLexique) ;
    break ;
  case 5 :
    rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i6_parse(inLexique) ;
    break ;
  case 6 :
    rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i7_parse(inLexique) ;
    break ;
  case 7 :
    rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i8_parse(inLexique) ;
    break ;
  case 8 :
    rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i9_parse(inLexique) ;
    break ;
  case 9 :
    rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i10_parse(inLexique) ;
    break ;
  case 10 :
    rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i11_parse(inLexique) ;
    break ;
  default :
    break ;
  }
}

void cGrammar_gtl_5F_grammar::nt_gtl_5F_template_5F_instruction_ (GALGAS_gtlInstruction & parameter_1,
                                C_Lexique_gtl_5F_scanner * inLexique) {
  switch (inLexique->nextProductionIndex ()) {
  case 1 :
    rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i2_(parameter_1, inLexique) ;
    break ;
  case 2 :
    rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i3_(parameter_1, inLexique) ;
    break ;
  case 3 :
    rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i4_(parameter_1, inLexique) ;
    break ;
  case 4 :
    rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i5_(parameter_1, inLexique) ;
    break ;
  case 5 :
    rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i6_(parameter_1, inLexique) ;
    break ;
  case 6 :
    rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i7_(parameter_1, inLexique) ;
    break ;
  case 7 :
    rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i8_(parameter_1, inLexique) ;
    break ;
  case 8 :
    rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i9_(parameter_1, inLexique) ;
    break ;
  case 9 :
    rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i10_(parameter_1, inLexique) ;
    break ;
  case 10 :
    rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i11_(parameter_1, inLexique) ;
    break ;
  default :
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                    'gtl_file_name' non terminal implementation                                       
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_gtl_5F_grammar::nt_gtl_5F_file_5F_name_parse (C_Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_parser_gtl_5F_file_5F_name_i12_parse(inLexique) ;
}

void cGrammar_gtl_5F_grammar::nt_gtl_5F_file_5F_name_ (GALGAS_gtlExpression & parameter_1,
                                C_Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_parser_gtl_5F_file_5F_name_i12_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                  'gtl_relation_term' non terminal implementation                                     
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_gtl_5F_grammar::nt_gtl_5F_relation_5F_term_parse (C_Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_relation_5F_term_i1_parse(inLexique) ;
}

void cGrammar_gtl_5F_grammar::nt_gtl_5F_relation_5F_term_ (GALGAS_gtlExpression & parameter_1,
                                C_Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_relation_5F_term_i1_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                 'gtl_relation_factor' non terminal implementation                                    
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_gtl_5F_grammar::nt_gtl_5F_relation_5F_factor_parse (C_Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_relation_5F_factor_i2_parse(inLexique) ;
}

void cGrammar_gtl_5F_grammar::nt_gtl_5F_relation_5F_factor_ (GALGAS_gtlExpression & parameter_1,
                                C_Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_relation_5F_factor_i2_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                'gtl_simple_expression' non terminal implementation                                   
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_gtl_5F_grammar::nt_gtl_5F_simple_5F_expression_parse (C_Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_simple_5F_expression_i3_parse(inLexique) ;
}

void cGrammar_gtl_5F_grammar::nt_gtl_5F_simple_5F_expression_ (GALGAS_gtlExpression & parameter_1,
                                C_Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_simple_5F_expression_i3_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                       'gtl_term' non terminal implementation                                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_gtl_5F_grammar::nt_gtl_5F_term_parse (C_Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_term_i4_parse(inLexique) ;
}

void cGrammar_gtl_5F_grammar::nt_gtl_5F_term_ (GALGAS_gtlExpression & parameter_1,
                                C_Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_term_i4_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                      'gtl_factor' non terminal implementation                                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_gtl_5F_grammar::nt_gtl_5F_factor_parse (C_Lexique_gtl_5F_scanner * inLexique) {
  switch (inLexique->nextProductionIndex ()) {
  case 1 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i5_parse(inLexique) ;
    break ;
  case 2 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i6_parse(inLexique) ;
    break ;
  case 3 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i7_parse(inLexique) ;
    break ;
  case 4 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i8_parse(inLexique) ;
    break ;
  case 5 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i9_parse(inLexique) ;
    break ;
  case 6 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i10_parse(inLexique) ;
    break ;
  case 7 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i11_parse(inLexique) ;
    break ;
  case 8 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i12_parse(inLexique) ;
    break ;
  case 9 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i13_parse(inLexique) ;
    break ;
  case 10 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i14_parse(inLexique) ;
    break ;
  case 11 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i15_parse(inLexique) ;
    break ;
  case 12 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i16_parse(inLexique) ;
    break ;
  case 13 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i17_parse(inLexique) ;
    break ;
  case 14 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i18_parse(inLexique) ;
    break ;
  case 15 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i19_parse(inLexique) ;
    break ;
  case 16 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i20_parse(inLexique) ;
    break ;
  case 17 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i21_parse(inLexique) ;
    break ;
  case 18 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i22_parse(inLexique) ;
    break ;
  case 19 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i23_parse(inLexique) ;
    break ;
  case 20 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i24_parse(inLexique) ;
    break ;
  case 21 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i25_parse(inLexique) ;
    break ;
  case 22 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i26_parse(inLexique) ;
    break ;
  case 23 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i27_parse(inLexique) ;
    break ;
  case 24 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i28_parse(inLexique) ;
    break ;
  case 25 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i29_parse(inLexique) ;
    break ;
  case 26 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i30_parse(inLexique) ;
    break ;
  case 27 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i31_parse(inLexique) ;
    break ;
  default :
    break ;
  }
}

void cGrammar_gtl_5F_grammar::nt_gtl_5F_factor_ (GALGAS_gtlExpression & parameter_1,
                                C_Lexique_gtl_5F_scanner * inLexique) {
  switch (inLexique->nextProductionIndex ()) {
  case 1 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i5_(parameter_1, inLexique) ;
    break ;
  case 2 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i6_(parameter_1, inLexique) ;
    break ;
  case 3 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i7_(parameter_1, inLexique) ;
    break ;
  case 4 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i8_(parameter_1, inLexique) ;
    break ;
  case 5 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i9_(parameter_1, inLexique) ;
    break ;
  case 6 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i10_(parameter_1, inLexique) ;
    break ;
  case 7 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i11_(parameter_1, inLexique) ;
    break ;
  case 8 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i12_(parameter_1, inLexique) ;
    break ;
  case 9 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i13_(parameter_1, inLexique) ;
    break ;
  case 10 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i14_(parameter_1, inLexique) ;
    break ;
  case 11 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i15_(parameter_1, inLexique) ;
    break ;
  case 12 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i16_(parameter_1, inLexique) ;
    break ;
  case 13 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i17_(parameter_1, inLexique) ;
    break ;
  case 14 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i18_(parameter_1, inLexique) ;
    break ;
  case 15 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i19_(parameter_1, inLexique) ;
    break ;
  case 16 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i20_(parameter_1, inLexique) ;
    break ;
  case 17 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i21_(parameter_1, inLexique) ;
    break ;
  case 18 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i22_(parameter_1, inLexique) ;
    break ;
  case 19 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i23_(parameter_1, inLexique) ;
    break ;
  case 20 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i24_(parameter_1, inLexique) ;
    break ;
  case 21 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i25_(parameter_1, inLexique) ;
    break ;
  case 22 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i26_(parameter_1, inLexique) ;
    break ;
  case 23 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i27_(parameter_1, inLexique) ;
    break ;
  case 24 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i28_(parameter_1, inLexique) ;
    break ;
  case 25 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i29_(parameter_1, inLexique) ;
    break ;
  case 26 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i30_(parameter_1, inLexique) ;
    break ;
  case 27 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i31_(parameter_1, inLexique) ;
    break ;
  default :
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                  'gtl_sorting_order' non terminal implementation                                     
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_gtl_5F_grammar::nt_gtl_5F_sorting_5F_order_parse (C_Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_instruction_5F_parser_gtl_5F_sorting_5F_order_i12_parse(inLexique) ;
}

void cGrammar_gtl_5F_grammar::nt_gtl_5F_sorting_5F_order_ (GALGAS_lsint & parameter_1,
                                C_Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_instruction_5F_parser_gtl_5F_sorting_5F_order_i12_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                             'select_gtl_5F_parser_0' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_0 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                             'select_gtl_5F_parser_1' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_1 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                             'select_gtl_5F_parser_2' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_2 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                             'select_gtl_5F_parser_3' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_3 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                             'select_gtl_5F_parser_4' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_4 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                             'select_gtl_5F_parser_5' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_5 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                             'select_gtl_5F_parser_6' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_6 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                             'select_gtl_5F_parser_7' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_7 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                             'select_gtl_5F_parser_8' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_8 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                             'select_gtl_5F_parser_9' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_9 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_gtl_5F_parser_10' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_10 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_gtl_5F_parser_11' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_11 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_gtl_5F_parser_12' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_12 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_gtl_5F_parser_13' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_13 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_gtl_5F_parser_14' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_14 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_gtl_5F_parser_15' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_15 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_gtl_5F_parser_16' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_16 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_gtl_5F_parser_17' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_17 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_gtl_5F_parser_18' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_18 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_gtl_5F_parser_19' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_19 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_gtl_5F_parser_20' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_20 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_gtl_5F_parser_21' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_21 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_gtl_5F_parser_22' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_22 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_gtl_5F_parser_23' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_23 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_gtl_5F_parser_24' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_24 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_gtl_5F_parser_25' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_25 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_gtl_5F_expression_5F_parser_0' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_0 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_gtl_5F_expression_5F_parser_1' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_1 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_gtl_5F_expression_5F_parser_2' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_2 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_gtl_5F_expression_5F_parser_3' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_3 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_gtl_5F_expression_5F_parser_4' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_4 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_gtl_5F_expression_5F_parser_5' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_5 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_gtl_5F_expression_5F_parser_6' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_6 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_gtl_5F_expression_5F_parser_7' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_7 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_gtl_5F_expression_5F_parser_8' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_8 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_gtl_5F_expression_5F_parser_9' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_9 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                     'select_gtl_5F_expression_5F_parser_10' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_10 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                     'select_gtl_5F_expression_5F_parser_11' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_11 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                     'select_gtl_5F_expression_5F_parser_12' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_12 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                     'select_gtl_5F_expression_5F_parser_13' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_13 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                     'select_gtl_5F_expression_5F_parser_14' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_14 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                     'select_gtl_5F_expression_5F_parser_15' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_15 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                     'select_gtl_5F_expression_5F_parser_16' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_16 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                     'select_gtl_5F_expression_5F_parser_17' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_17 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                     'select_gtl_5F_expression_5F_parser_18' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_18 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                     'select_gtl_5F_expression_5F_parser_19' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_19 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                     'select_gtl_5F_expression_5F_parser_20' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_20 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                     'select_gtl_5F_expression_5F_parser_21' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_21 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                     'select_gtl_5F_expression_5F_parser_22' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_22 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                     'select_gtl_5F_expression_5F_parser_23' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_23 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                     'select_gtl_5F_expression_5F_parser_24' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_24 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                     'select_gtl_5F_expression_5F_parser_25' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_25 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                     'select_gtl_5F_expression_5F_parser_26' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_26 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                     'select_gtl_5F_expression_5F_parser_27' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_27 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                     'select_gtl_5F_instruction_5F_parser_0' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_instruction_5F_parser_0 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                     'select_gtl_5F_instruction_5F_parser_1' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_instruction_5F_parser_1 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                     'select_gtl_5F_instruction_5F_parser_2' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_instruction_5F_parser_2 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                     'select_gtl_5F_instruction_5F_parser_3' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_instruction_5F_parser_3 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                     'select_gtl_5F_instruction_5F_parser_4' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_instruction_5F_parser_4 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                     'select_gtl_5F_instruction_5F_parser_5' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_instruction_5F_parser_5 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                     'select_gtl_5F_instruction_5F_parser_6' added non terminal implementation                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_instruction_5F_parser_6 (C_Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Function 'emptyContext'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlContext function_emptyContext (C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlContext result_context ; // Returned variable
  result_context = GALGAS_gtlContext::constructor_new (function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 44)), GALGAS_string::makeEmptyString (), GALGAS_string::makeEmptyString (), GALGAS_string ("gtl"), GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("gtl_types.galgas", 48)), GALGAS_gtlDataList::constructor_emptyList (SOURCE_FILE ("gtl_types.galgas", 49)), function_defaultDebugSettings (inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 50))  COMMA_SOURCE_FILE ("gtl_types.galgas", 43)) ;
//---
  return result_context ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_emptyContext [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_emptyContext (C_Compiler * inCompiler,
                                                             const cObjectArray & /* inEffectiveParameterArray */,
                                                             const GALGAS_location & /* inErrorLocation */
                                                             COMMA_LOCATION_ARGS) {
  return function_emptyContext (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_emptyContext ("emptyContext",
                                                              functionWithGenericHeader_emptyContext,
                                                              & kTypeDescriptor_GALGAS_gtlContext,
                                                              0,
                                                              functionArgs_emptyContext) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Function 'pathWithExtension'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_pathWithExtension (GALGAS_gtlContext inArgument_context,
                                          GALGAS_string inArgument_path,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_extendedPath ; // Returned variable
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, inArgument_path.getter_pathExtension (SOURCE_FILE ("gtl_types.galgas", 92)).objectCompare (inArgument_context.getter_templateExtension (SOURCE_FILE ("gtl_types.galgas", 92)))).boolEnum () ;
  if (kBoolTrue == test_0) {
    result_extendedPath = inArgument_path.add_operation (GALGAS_string ("."), inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 93)).add_operation (inArgument_context.getter_templateExtension (SOURCE_FILE ("gtl_types.galgas", 93)), inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 93)) ;
  }else if (kBoolFalse == test_0) {
    result_extendedPath = inArgument_path ;
  }
//---
  return result_extendedPath ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_pathWithExtension [3] = {
  & kTypeDescriptor_GALGAS_gtlContext,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_pathWithExtension (C_Compiler * inCompiler,
                                                                  const cObjectArray & inEffectiveParameterArray,
                                                                  const GALGAS_location & /* inErrorLocation */
                                                                  COMMA_LOCATION_ARGS) {
  const GALGAS_gtlContext operand0 = GALGAS_gtlContext::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                       inCompiler
                                                                       COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_pathWithExtension (operand0,
                                     operand1,
                                     inCompiler
                                     COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_pathWithExtension ("pathWithExtension",
                                                                   functionWithGenericHeader_pathWithExtension,
                                                                   & kTypeDescriptor_GALGAS_string,
                                                                   2,
                                                                   functionArgs_pathWithExtension) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 Function 'emptyLib'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_library function_emptyLib (C_Compiler * /* inCompiler */
                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_library result_result ; // Returned variable
  result_result = GALGAS_library::constructor_new (GALGAS_gtlFuncMap::constructor_emptyMap (SOURCE_FILE ("gtl_types.galgas", 279)), GALGAS_gtlGetterMap::constructor_emptyMap (SOURCE_FILE ("gtl_types.galgas", 279)), GALGAS_gtlSetterMap::constructor_emptyMap (SOURCE_FILE ("gtl_types.galgas", 279)), GALGAS_gtlTemplateMap::constructor_emptyMap (SOURCE_FILE ("gtl_types.galgas", 279)), GALGAS_stringset::constructor_emptySet (SOURCE_FILE ("gtl_types.galgas", 279))  COMMA_SOURCE_FILE ("gtl_types.galgas", 279)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_emptyLib [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_emptyLib (C_Compiler * inCompiler,
                                                         const cObjectArray & /* inEffectiveParameterArray */,
                                                         const GALGAS_location & /* inErrorLocation */
                                                         COMMA_LOCATION_ARGS) {
  return function_emptyLib (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_emptyLib ("emptyLib",
                                                          functionWithGenericHeader_emptyLib,
                                                          & kTypeDescriptor_GALGAS_library,
                                                          0,
                                                          functionArgs_emptyLib) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Function 'wantGtlStruct'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData function_wantGtlStruct (GALGAS_gtlData inArgument_inData,
                                       C_Compiler * inCompiler
                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_outData ; // Returned variable
  if (inArgument_inData.isValid ()) {
    if (inArgument_inData.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlStruct) {
      GALGAS_gtlStruct cast_1500_inDataStruct ((cPtr_gtlStruct *) inArgument_inData.ptr ()) ;
      result_outData = cast_1500_inDataStruct ;
    }else{
      result_outData = GALGAS_gtlStruct::constructor_new (callExtensionGetter_location ((const cPtr_gtlData *) inArgument_inData.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 56)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 56)), GALGAS_gtlVarMap::constructor_emptyMap (SOURCE_FILE ("gtl_expressions.galgas", 56))  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 56)) ;
    }
  }
//---
  return result_outData ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_wantGtlStruct [2] = {
  & kTypeDescriptor_GALGAS_gtlData,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_wantGtlStruct (C_Compiler * inCompiler,
                                                              const cObjectArray & inEffectiveParameterArray,
                                                              const GALGAS_location & /* inErrorLocation */
                                                              COMMA_LOCATION_ARGS) {
  const GALGAS_gtlData operand0 = GALGAS_gtlData::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  return function_wantGtlStruct (operand0,
                                 inCompiler
                                 COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_wantGtlStruct ("wantGtlStruct",
                                                               functionWithGenericHeader_wantGtlStruct,
                                                               & kTypeDescriptor_GALGAS_gtlData,
                                                               1,
                                                               functionArgs_wantGtlStruct) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                Function 'wantGtlMap'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData function_wantGtlMap (GALGAS_gtlData inArgument_inData,
                                    C_Compiler * inCompiler
                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_outData ; // Returned variable
  if (inArgument_inData.isValid ()) {
    if (inArgument_inData.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlMap) {
      GALGAS_gtlMap cast_1793_inDataMap ((cPtr_gtlMap *) inArgument_inData.ptr ()) ;
      result_outData = cast_1793_inDataMap ;
    }else{
      result_outData = GALGAS_gtlMap::constructor_new (callExtensionGetter_location ((const cPtr_gtlData *) inArgument_inData.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 69)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 69)), GALGAS_gtlVarMap::constructor_emptyMap (SOURCE_FILE ("gtl_expressions.galgas", 69))  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 69)) ;
    }
  }
//---
  return result_outData ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_wantGtlMap [2] = {
  & kTypeDescriptor_GALGAS_gtlData,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_wantGtlMap (C_Compiler * inCompiler,
                                                           const cObjectArray & inEffectiveParameterArray,
                                                           const GALGAS_location & /* inErrorLocation */
                                                           COMMA_LOCATION_ARGS) {
  const GALGAS_gtlData operand0 = GALGAS_gtlData::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  return function_wantGtlMap (operand0,
                              inCompiler
                              COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_wantGtlMap ("wantGtlMap",
                                                            functionWithGenericHeader_wantGtlMap,
                                                            & kTypeDescriptor_GALGAS_gtlData,
                                                            1,
                                                            functionArgs_wantGtlMap) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Function 'wantGtlList'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData function_wantGtlList (GALGAS_gtlData inArgument_inData,
                                     C_Compiler * inCompiler
                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_outData ; // Returned variable
  if (inArgument_inData.isValid ()) {
    if (inArgument_inData.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlList) {
      GALGAS_gtlList cast_2083_inDataList ((cPtr_gtlList *) inArgument_inData.ptr ()) ;
      result_outData = cast_2083_inDataList ;
    }else{
      result_outData = GALGAS_gtlList::constructor_new (callExtensionGetter_location ((const cPtr_gtlData *) inArgument_inData.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 82)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 82)), GALGAS_list::constructor_emptyList (SOURCE_FILE ("gtl_expressions.galgas", 82))  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 82)) ;
    }
  }
//---
  return result_outData ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_wantGtlList [2] = {
  & kTypeDescriptor_GALGAS_gtlData,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_wantGtlList (C_Compiler * inCompiler,
                                                            const cObjectArray & inEffectiveParameterArray,
                                                            const GALGAS_location & /* inErrorLocation */
                                                            COMMA_LOCATION_ARGS) {
  const GALGAS_gtlData operand0 = GALGAS_gtlData::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  return function_wantGtlList (operand0,
                               inCompiler
                               COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_wantGtlList ("wantGtlList",
                                                             functionWithGenericHeader_wantGtlList,
                                                             & kTypeDescriptor_GALGAS_gtlData,
                                                             1,
                                                             functionArgs_wantGtlList) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Routine 'checkArgumentError'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_checkArgumentError (const GALGAS_lstring constinArgument_name,
                                 const GALGAS_type constinArgument_formalType,
                                 const GALGAS_gtlData constinArgument_actualArgument,
                                 const GALGAS_uint constinArgument_argumentNum,
                                 C_Compiler * inCompiler
                                 COMMA_UNUSED_LOCATION_ARGS) {
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, constinArgument_formalType.objectCompare (callExtensionGetter_embeddedType ((const cPtr_gtlData *) constinArgument_actualArgument.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1191)))).boolEnum () ;
  if (kBoolTrue == test_0) {
    TC_Array <C_FixItDescription> fixItArray1 ;
    inCompiler->emitSemanticError (constinArgument_name.getter_location (SOURCE_FILE ("gtl_expressions.galgas", 1192)), extensionGetter_typeName (constinArgument_formalType, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1192)).add_operation (GALGAS_string (" expected for argument "), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1192)).add_operation (constinArgument_argumentNum.getter_string (SOURCE_FILE ("gtl_expressions.galgas", 1192)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1192)).add_operation (GALGAS_string (", "), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1193)).add_operation (extensionGetter_typeName (constinArgument_actualArgument.getter_dynamicType (SOURCE_FILE ("gtl_expressions.galgas", 1193)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1193)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1193)).add_operation (GALGAS_string (" provided"), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1193)), fixItArray1  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1192)) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Function 'validateReturnValue'                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData function_validateReturnValue (const GALGAS_lstring & constinArgument_functionName,
                                             const GALGAS_object & constinArgument_returnedValue,
                                             C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  GALGAS_type var_returnedType_36172 = constinArgument_returnedValue.getter_objectDynamicType (SOURCE_FILE ("gtl_expressions.galgas", 1203)) ;
  GALGAS_location var_loc_36224 = constinArgument_functionName.getter_location (SOURCE_FILE ("gtl_expressions.galgas", 1204)) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, var_returnedType_36172.objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_bigint))).boolEnum () ;
  if (kBoolTrue == test_0) {
    result_result = GALGAS_gtlInt::constructor_new (var_loc_36224, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1206)), GALGAS_bigint::extractObject (constinArgument_returnedValue, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1206))  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1206)) ;
  }else if (kBoolFalse == test_0) {
    const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, var_returnedType_36172.objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_double))).boolEnum () ;
    if (kBoolTrue == test_2) {
      result_result = GALGAS_gtlFloat::constructor_new (var_loc_36224, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1208)), GALGAS_double::extractObject (constinArgument_returnedValue, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1208))  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1208)) ;
    }else if (kBoolFalse == test_2) {
      const enumGalgasBool test_4 = GALGAS_bool (kIsEqual, var_returnedType_36172.objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_string))).boolEnum () ;
      if (kBoolTrue == test_4) {
        result_result = GALGAS_gtlString::constructor_new (var_loc_36224, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1210)), GALGAS_string::extractObject (constinArgument_returnedValue, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1210))  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1210)) ;
      }else if (kBoolFalse == test_4) {
        const enumGalgasBool test_6 = GALGAS_bool (kIsEqual, var_returnedType_36172.objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_bool))).boolEnum () ;
        if (kBoolTrue == test_6) {
          result_result = GALGAS_gtlBool::constructor_new (var_loc_36224, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1212)), GALGAS_bool::extractObject (constinArgument_returnedValue, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1212))  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1212)) ;
        }else if (kBoolFalse == test_6) {
          const enumGalgasBool test_8 = GALGAS_bool (kIsEqual, var_returnedType_36172.objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_list))).boolEnum () ;
          if (kBoolTrue == test_8) {
            result_result = GALGAS_gtlList::constructor_new (var_loc_36224, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1214)), GALGAS_list::extractObject (constinArgument_returnedValue, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1214))  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1214)) ;
          }else if (kBoolFalse == test_8) {
            TC_Array <C_FixItDescription> fixItArray10 ;
            inCompiler->emitSemanticError (constinArgument_functionName.getter_location (SOURCE_FILE ("gtl_expressions.galgas", 1216)), GALGAS_string ("this function does not return a compatible type"), fixItArray10  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1216)) ;
            result_result.drop () ; // Release error dropped variable
          }
        }
      }
    }
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_validateReturnValue [3] = {
  & kTypeDescriptor_GALGAS_lstring,
  & kTypeDescriptor_GALGAS_object,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_validateReturnValue (C_Compiler * inCompiler,
                                                                    const cObjectArray & inEffectiveParameterArray,
                                                                    const GALGAS_location & /* inErrorLocation */
                                                                    COMMA_LOCATION_ARGS) {
  const GALGAS_lstring operand0 = GALGAS_lstring::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  const GALGAS_object operand1 = GALGAS_object::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_validateReturnValue (operand0,
                                       operand1,
                                       inCompiler
                                       COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_validateReturnValue ("validateReturnValue",
                                                                     functionWithGenericHeader_validateReturnValue,
                                                                     & kTypeDescriptor_GALGAS_gtlData,
                                                                     2,
                                                                     functionArgs_validateReturnValue) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             Once function 'noArgument'                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlTypedArgumentList onceFunction_noArgument (C_Compiler * /* inCompiler */
                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlTypedArgumentList result_result ; // Returned variable
  result_result = GALGAS_gtlTypedArgumentList::constructor_emptyList (SOURCE_FILE ("gtl_data_types.galgas", 85)) ;
//---
  return result_result ;
}



//---------------------------------------------------------------------------------------------------------------------*
//  Function implementation                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

static bool gOnceFunctionResultAvailable_noArgument = false ;
static GALGAS_gtlTypedArgumentList gOnceFunctionResult_noArgument ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTypedArgumentList function_noArgument (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_noArgument) {
    gOnceFunctionResult_noArgument = onceFunction_noArgument (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_noArgument = true ;
  }
  return gOnceFunctionResult_noArgument ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void releaseOnceFunctionResult_noArgument (void) {
  gOnceFunctionResult_noArgument.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gEpilogueForOnceFunction_noArgument (NULL,
                                                        releaseOnceFunctionResult_noArgument) ;

//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_noArgument [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_noArgument (C_Compiler * inCompiler,
                                                           const cObjectArray & /* inEffectiveParameterArray */,
                                                           const GALGAS_location & /* inErrorLocation */
                                                           COMMA_LOCATION_ARGS) {
  return function_noArgument (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_noArgument ("noArgument",
                                                            functionWithGenericHeader_noArgument,
                                                            & kTypeDescriptor_GALGAS_gtlTypedArgumentList,
                                                            0,
                                                            functionArgs_noArgument) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             Once function 'intArgument'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlTypedArgumentList onceFunction_intArgument (C_Compiler * /* inCompiler */
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlTypedArgumentList result_result ; // Returned variable
  result_result = GALGAS_gtlTypedArgumentList::constructor_listWithValue (GALGAS_type (& kTypeDescriptor_GALGAS_gtlInt)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 90)) ;
//---
  return result_result ;
}



//---------------------------------------------------------------------------------------------------------------------*
//  Function implementation                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

static bool gOnceFunctionResultAvailable_intArgument = false ;
static GALGAS_gtlTypedArgumentList gOnceFunctionResult_intArgument ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTypedArgumentList function_intArgument (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_intArgument) {
    gOnceFunctionResult_intArgument = onceFunction_intArgument (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_intArgument = true ;
  }
  return gOnceFunctionResult_intArgument ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void releaseOnceFunctionResult_intArgument (void) {
  gOnceFunctionResult_intArgument.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gEpilogueForOnceFunction_intArgument (NULL,
                                                         releaseOnceFunctionResult_intArgument) ;

//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_intArgument [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_intArgument (C_Compiler * inCompiler,
                                                            const cObjectArray & /* inEffectiveParameterArray */,
                                                            const GALGAS_location & /* inErrorLocation */
                                                            COMMA_LOCATION_ARGS) {
  return function_intArgument (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_intArgument ("intArgument",
                                                             functionWithGenericHeader_intArgument,
                                                             & kTypeDescriptor_GALGAS_gtlTypedArgumentList,
                                                             0,
                                                             functionArgs_intArgument) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Once function 'charArgument'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlTypedArgumentList onceFunction_charArgument (C_Compiler * /* inCompiler */
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlTypedArgumentList result_result ; // Returned variable
  result_result = GALGAS_gtlTypedArgumentList::constructor_listWithValue (GALGAS_type (& kTypeDescriptor_GALGAS_gtlChar)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 95)) ;
//---
  return result_result ;
}



//---------------------------------------------------------------------------------------------------------------------*
//  Function implementation                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

static bool gOnceFunctionResultAvailable_charArgument = false ;
static GALGAS_gtlTypedArgumentList gOnceFunctionResult_charArgument ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTypedArgumentList function_charArgument (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_charArgument) {
    gOnceFunctionResult_charArgument = onceFunction_charArgument (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_charArgument = true ;
  }
  return gOnceFunctionResult_charArgument ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void releaseOnceFunctionResult_charArgument (void) {
  gOnceFunctionResult_charArgument.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gEpilogueForOnceFunction_charArgument (NULL,
                                                          releaseOnceFunctionResult_charArgument) ;

//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_charArgument [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_charArgument (C_Compiler * inCompiler,
                                                             const cObjectArray & /* inEffectiveParameterArray */,
                                                             const GALGAS_location & /* inErrorLocation */
                                                             COMMA_LOCATION_ARGS) {
  return function_charArgument (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_charArgument ("charArgument",
                                                              functionWithGenericHeader_charArgument,
                                                              & kTypeDescriptor_GALGAS_gtlTypedArgumentList,
                                                              0,
                                                              functionArgs_charArgument) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          Once function 'charCharArguments'                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlTypedArgumentList onceFunction_charCharArguments (C_Compiler * /* inCompiler */
                                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlTypedArgumentList result_result ; // Returned variable
  result_result = GALGAS_gtlTypedArgumentList::constructor_listWithValue (GALGAS_type (& kTypeDescriptor_GALGAS_gtlChar)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 100)) ;
  result_result.addAssign_operation (GALGAS_type (& kTypeDescriptor_GALGAS_gtlChar)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 101)) ;
//---
  return result_result ;
}



//---------------------------------------------------------------------------------------------------------------------*
//  Function implementation                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

static bool gOnceFunctionResultAvailable_charCharArguments = false ;
static GALGAS_gtlTypedArgumentList gOnceFunctionResult_charCharArguments ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTypedArgumentList function_charCharArguments (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_charCharArguments) {
    gOnceFunctionResult_charCharArguments = onceFunction_charCharArguments (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_charCharArguments = true ;
  }
  return gOnceFunctionResult_charCharArguments ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void releaseOnceFunctionResult_charCharArguments (void) {
  gOnceFunctionResult_charCharArguments.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gEpilogueForOnceFunction_charCharArguments (NULL,
                                                               releaseOnceFunctionResult_charCharArguments) ;

//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_charCharArguments [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_charCharArguments (C_Compiler * inCompiler,
                                                                  const cObjectArray & /* inEffectiveParameterArray */,
                                                                  const GALGAS_location & /* inErrorLocation */
                                                                  COMMA_LOCATION_ARGS) {
  return function_charCharArguments (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_charCharArguments ("charCharArguments",
                                                                   functionWithGenericHeader_charCharArguments,
                                                                   & kTypeDescriptor_GALGAS_gtlTypedArgumentList,
                                                                   0,
                                                                   functionArgs_charCharArguments) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          Once function 'charIntArguments'                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlTypedArgumentList onceFunction_charIntArguments (C_Compiler * /* inCompiler */
                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlTypedArgumentList result_result ; // Returned variable
  result_result = GALGAS_gtlTypedArgumentList::constructor_listWithValue (GALGAS_type (& kTypeDescriptor_GALGAS_gtlChar)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 106)) ;
  result_result.addAssign_operation (GALGAS_type (& kTypeDescriptor_GALGAS_gtlInt)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 107)) ;
//---
  return result_result ;
}



//---------------------------------------------------------------------------------------------------------------------*
//  Function implementation                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

static bool gOnceFunctionResultAvailable_charIntArguments = false ;
static GALGAS_gtlTypedArgumentList gOnceFunctionResult_charIntArguments ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTypedArgumentList function_charIntArguments (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_charIntArguments) {
    gOnceFunctionResult_charIntArguments = onceFunction_charIntArguments (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_charIntArguments = true ;
  }
  return gOnceFunctionResult_charIntArguments ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void releaseOnceFunctionResult_charIntArguments (void) {
  gOnceFunctionResult_charIntArguments.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gEpilogueForOnceFunction_charIntArguments (NULL,
                                                              releaseOnceFunctionResult_charIntArguments) ;

//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_charIntArguments [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_charIntArguments (C_Compiler * inCompiler,
                                                                 const cObjectArray & /* inEffectiveParameterArray */,
                                                                 const GALGAS_location & /* inErrorLocation */
                                                                 COMMA_LOCATION_ARGS) {
  return function_charIntArguments (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_charIntArguments ("charIntArguments",
                                                                  functionWithGenericHeader_charIntArguments,
                                                                  & kTypeDescriptor_GALGAS_gtlTypedArgumentList,
                                                                  0,
                                                                  functionArgs_charIntArguments) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Once function 'floatArgument'                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlTypedArgumentList onceFunction_floatArgument (C_Compiler * /* inCompiler */
                                                               COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlTypedArgumentList result_result ; // Returned variable
  result_result = GALGAS_gtlTypedArgumentList::constructor_listWithValue (GALGAS_type (& kTypeDescriptor_GALGAS_gtlFloat)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 112)) ;
//---
  return result_result ;
}



//---------------------------------------------------------------------------------------------------------------------*
//  Function implementation                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

static bool gOnceFunctionResultAvailable_floatArgument = false ;
static GALGAS_gtlTypedArgumentList gOnceFunctionResult_floatArgument ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTypedArgumentList function_floatArgument (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_floatArgument) {
    gOnceFunctionResult_floatArgument = onceFunction_floatArgument (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_floatArgument = true ;
  }
  return gOnceFunctionResult_floatArgument ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void releaseOnceFunctionResult_floatArgument (void) {
  gOnceFunctionResult_floatArgument.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gEpilogueForOnceFunction_floatArgument (NULL,
                                                           releaseOnceFunctionResult_floatArgument) ;

//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_floatArgument [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_floatArgument (C_Compiler * inCompiler,
                                                              const cObjectArray & /* inEffectiveParameterArray */,
                                                              const GALGAS_location & /* inErrorLocation */
                                                              COMMA_LOCATION_ARGS) {
  return function_floatArgument (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_floatArgument ("floatArgument",
                                                               functionWithGenericHeader_floatArgument,
                                                               & kTypeDescriptor_GALGAS_gtlTypedArgumentList,
                                                               0,
                                                               functionArgs_floatArgument) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Once function 'stringArgument'                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlTypedArgumentList onceFunction_stringArgument (C_Compiler * /* inCompiler */
                                                                COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlTypedArgumentList result_result ; // Returned variable
  result_result = GALGAS_gtlTypedArgumentList::constructor_listWithValue (GALGAS_type (& kTypeDescriptor_GALGAS_gtlString)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 117)) ;
//---
  return result_result ;
}



//---------------------------------------------------------------------------------------------------------------------*
//  Function implementation                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

static bool gOnceFunctionResultAvailable_stringArgument = false ;
static GALGAS_gtlTypedArgumentList gOnceFunctionResult_stringArgument ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTypedArgumentList function_stringArgument (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_stringArgument) {
    gOnceFunctionResult_stringArgument = onceFunction_stringArgument (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_stringArgument = true ;
  }
  return gOnceFunctionResult_stringArgument ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void releaseOnceFunctionResult_stringArgument (void) {
  gOnceFunctionResult_stringArgument.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gEpilogueForOnceFunction_stringArgument (NULL,
                                                            releaseOnceFunctionResult_stringArgument) ;

//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_stringArgument [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_stringArgument (C_Compiler * inCompiler,
                                                               const cObjectArray & /* inEffectiveParameterArray */,
                                                               const GALGAS_location & /* inErrorLocation */
                                                               COMMA_LOCATION_ARGS) {
  return function_stringArgument (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_stringArgument ("stringArgument",
                                                                functionWithGenericHeader_stringArgument,
                                                                & kTypeDescriptor_GALGAS_gtlTypedArgumentList,
                                                                0,
                                                                functionArgs_stringArgument) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Once function 'stringStringArgument'                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlTypedArgumentList onceFunction_stringStringArgument (C_Compiler * /* inCompiler */
                                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlTypedArgumentList result_result ; // Returned variable
  result_result = GALGAS_gtlTypedArgumentList::constructor_listWithValue (GALGAS_type (& kTypeDescriptor_GALGAS_gtlString)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 122)) ;
  result_result.addAssign_operation (GALGAS_type (& kTypeDescriptor_GALGAS_gtlString)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 123)) ;
//---
  return result_result ;
}



//---------------------------------------------------------------------------------------------------------------------*
//  Function implementation                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

static bool gOnceFunctionResultAvailable_stringStringArgument = false ;
static GALGAS_gtlTypedArgumentList gOnceFunctionResult_stringStringArgument ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTypedArgumentList function_stringStringArgument (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_stringStringArgument) {
    gOnceFunctionResult_stringStringArgument = onceFunction_stringStringArgument (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_stringStringArgument = true ;
  }
  return gOnceFunctionResult_stringStringArgument ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void releaseOnceFunctionResult_stringStringArgument (void) {
  gOnceFunctionResult_stringStringArgument.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gEpilogueForOnceFunction_stringStringArgument (NULL,
                                                                  releaseOnceFunctionResult_stringStringArgument) ;

//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_stringStringArgument [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_stringStringArgument (C_Compiler * inCompiler,
                                                                     const cObjectArray & /* inEffectiveParameterArray */,
                                                                     const GALGAS_location & /* inErrorLocation */
                                                                     COMMA_LOCATION_ARGS) {
  return function_stringStringArgument (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_stringStringArgument ("stringStringArgument",
                                                                      functionWithGenericHeader_stringStringArgument,
                                                                      & kTypeDescriptor_GALGAS_gtlTypedArgumentList,
                                                                      0,
                                                                      functionArgs_stringStringArgument) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          Once function 'boolIntArguments'                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlTypedArgumentList onceFunction_boolIntArguments (C_Compiler * /* inCompiler */
                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlTypedArgumentList result_result ; // Returned variable
  result_result = GALGAS_gtlTypedArgumentList::constructor_listWithValue (GALGAS_type (& kTypeDescriptor_GALGAS_gtlBool)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 128)) ;
  result_result.addAssign_operation (GALGAS_type (& kTypeDescriptor_GALGAS_gtlInt)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 129)) ;
//---
  return result_result ;
}



//---------------------------------------------------------------------------------------------------------------------*
//  Function implementation                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

static bool gOnceFunctionResultAvailable_boolIntArguments = false ;
static GALGAS_gtlTypedArgumentList gOnceFunctionResult_boolIntArguments ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTypedArgumentList function_boolIntArguments (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_boolIntArguments) {
    gOnceFunctionResult_boolIntArguments = onceFunction_boolIntArguments (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_boolIntArguments = true ;
  }
  return gOnceFunctionResult_boolIntArguments ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void releaseOnceFunctionResult_boolIntArguments (void) {
  gOnceFunctionResult_boolIntArguments.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gEpilogueForOnceFunction_boolIntArguments (NULL,
                                                              releaseOnceFunctionResult_boolIntArguments) ;

//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_boolIntArguments [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_boolIntArguments (C_Compiler * inCompiler,
                                                                 const cObjectArray & /* inEffectiveParameterArray */,
                                                                 const GALGAS_location & /* inErrorLocation */
                                                                 COMMA_LOCATION_ARGS) {
  return function_boolIntArguments (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_boolIntArguments ("boolIntArguments",
                                                                  functionWithGenericHeader_boolIntArguments,
                                                                  & kTypeDescriptor_GALGAS_gtlTypedArgumentList,
                                                                  0,
                                                                  functionArgs_boolIntArguments) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Once function 'intIntArguments'                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlTypedArgumentList onceFunction_intIntArguments (C_Compiler * /* inCompiler */
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlTypedArgumentList result_result ; // Returned variable
  result_result = GALGAS_gtlTypedArgumentList::constructor_listWithValue (GALGAS_type (& kTypeDescriptor_GALGAS_gtlInt)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 134)) ;
  result_result.addAssign_operation (GALGAS_type (& kTypeDescriptor_GALGAS_gtlInt)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 135)) ;
//---
  return result_result ;
}



//---------------------------------------------------------------------------------------------------------------------*
//  Function implementation                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

static bool gOnceFunctionResultAvailable_intIntArguments = false ;
static GALGAS_gtlTypedArgumentList gOnceFunctionResult_intIntArguments ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTypedArgumentList function_intIntArguments (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_intIntArguments) {
    gOnceFunctionResult_intIntArguments = onceFunction_intIntArguments (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_intIntArguments = true ;
  }
  return gOnceFunctionResult_intIntArguments ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void releaseOnceFunctionResult_intIntArguments (void) {
  gOnceFunctionResult_intIntArguments.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gEpilogueForOnceFunction_intIntArguments (NULL,
                                                             releaseOnceFunctionResult_intIntArguments) ;

//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_intIntArguments [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_intIntArguments (C_Compiler * inCompiler,
                                                                const cObjectArray & /* inEffectiveParameterArray */,
                                                                const GALGAS_location & /* inErrorLocation */
                                                                COMMA_LOCATION_ARGS) {
  return function_intIntArguments (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_intIntArguments ("intIntArguments",
                                                                 functionWithGenericHeader_intIntArguments,
                                                                 & kTypeDescriptor_GALGAS_gtlTypedArgumentList,
                                                                 0,
                                                                 functionArgs_intIntArguments) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Once function 'intAnyArguments'                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlTypedArgumentList onceFunction_intAnyArguments (C_Compiler * /* inCompiler */
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlTypedArgumentList result_result ; // Returned variable
  result_result = GALGAS_gtlTypedArgumentList::constructor_listWithValue (GALGAS_type (& kTypeDescriptor_GALGAS_gtlInt)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 140)) ;
  result_result.addAssign_operation (GALGAS_type (& kTypeDescriptor_GALGAS_gtlData)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 141)) ;
//---
  return result_result ;
}



//---------------------------------------------------------------------------------------------------------------------*
//  Function implementation                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

static bool gOnceFunctionResultAvailable_intAnyArguments = false ;
static GALGAS_gtlTypedArgumentList gOnceFunctionResult_intAnyArguments ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTypedArgumentList function_intAnyArguments (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_intAnyArguments) {
    gOnceFunctionResult_intAnyArguments = onceFunction_intAnyArguments (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_intAnyArguments = true ;
  }
  return gOnceFunctionResult_intAnyArguments ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void releaseOnceFunctionResult_intAnyArguments (void) {
  gOnceFunctionResult_intAnyArguments.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gEpilogueForOnceFunction_intAnyArguments (NULL,
                                                             releaseOnceFunctionResult_intAnyArguments) ;

//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_intAnyArguments [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_intAnyArguments (C_Compiler * inCompiler,
                                                                const cObjectArray & /* inEffectiveParameterArray */,
                                                                const GALGAS_location & /* inErrorLocation */
                                                                COMMA_LOCATION_ARGS) {
  return function_intAnyArguments (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_intAnyArguments ("intAnyArguments",
                                                                 functionWithGenericHeader_intAnyArguments,
                                                                 & kTypeDescriptor_GALGAS_gtlTypedArgumentList,
                                                                 0,
                                                                 functionArgs_intAnyArguments) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             Once function 'anyArgument'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlTypedArgumentList onceFunction_anyArgument (C_Compiler * /* inCompiler */
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlTypedArgumentList result_result ; // Returned variable
  result_result = GALGAS_gtlTypedArgumentList::constructor_listWithValue (GALGAS_type (& kTypeDescriptor_GALGAS_gtlData)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 146)) ;
//---
  return result_result ;
}



//---------------------------------------------------------------------------------------------------------------------*
//  Function implementation                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

static bool gOnceFunctionResultAvailable_anyArgument = false ;
static GALGAS_gtlTypedArgumentList gOnceFunctionResult_anyArgument ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlTypedArgumentList function_anyArgument (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_anyArgument) {
    gOnceFunctionResult_anyArgument = onceFunction_anyArgument (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_anyArgument = true ;
  }
  return gOnceFunctionResult_anyArgument ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void releaseOnceFunctionResult_anyArgument (void) {
  gOnceFunctionResult_anyArgument.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gEpilogueForOnceFunction_anyArgument (NULL,
                                                         releaseOnceFunctionResult_anyArgument) ;

//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_anyArgument [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_anyArgument (C_Compiler * inCompiler,
                                                            const cObjectArray & /* inEffectiveParameterArray */,
                                                            const GALGAS_location & /* inErrorLocation */
                                                            COMMA_LOCATION_ARGS) {
  return function_anyArgument (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_anyArgument ("anyArgument",
                                                             functionWithGenericHeader_anyArgument,
                                                             & kTypeDescriptor_GALGAS_gtlTypedArgumentList,
                                                             0,
                                                             functionArgs_anyArgument) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Routine 'argumentsCheck'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_argumentsCheck (const GALGAS_lstring constinArgument_methodName,
                             GALGAS_gtlTypedArgumentList inArgument_abstractArgumentList,
                             GALGAS_gtlDataList inArgument_concreteArgumentList,
                             C_Compiler * inCompiler
                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_uint var_concreteLength_4711 = inArgument_concreteArgumentList.getter_length (SOURCE_FILE ("gtl_data_types.galgas", 154)) ;
  GALGAS_uint var_abstractLength_4766 = inArgument_abstractArgumentList.getter_length (SOURCE_FILE ("gtl_data_types.galgas", 155)) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, inArgument_abstractArgumentList.getter_length (SOURCE_FILE ("gtl_data_types.galgas", 156)).objectCompare (inArgument_concreteArgumentList.getter_length (SOURCE_FILE ("gtl_data_types.galgas", 156)))).boolEnum () ;
  if (kBoolTrue == test_0) {
    TC_Array <C_FixItDescription> fixItArray1 ;
    inCompiler->emitSemanticError (constinArgument_methodName.getter_location (SOURCE_FILE ("gtl_data_types.galgas", 157)), constinArgument_methodName.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 157)).add_operation (GALGAS_string (" expects "), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 157)).add_operation (var_abstractLength_4766.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 157)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 157)).add_operation (GALGAS_string (" arguments. "), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 157)).add_operation (var_concreteLength_4711.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 158)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 158)).add_operation (GALGAS_string (" arguments provided."), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 158)), fixItArray1  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 157)) ;
  }else if (kBoolFalse == test_0) {
    cEnumerator_gtlDataList enumerator_5069 (inArgument_concreteArgumentList, kEnumeration_up) ;
    cEnumerator_gtlTypedArgumentList enumerator_5097 (inArgument_abstractArgumentList, kEnumeration_up) ;
    GALGAS_uint index_5042 ((uint32_t) 0) ;
    while (enumerator_5069.hasCurrentObject () && enumerator_5097.hasCurrentObject ()) {
      const enumGalgasBool test_2 = GALGAS_bool (kIsNotEqual, enumerator_5069.current_data (HERE).getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 161)).objectCompare (enumerator_5097.current_type (HERE))).operator_and (GALGAS_bool (kIsNotEqual, enumerator_5097.current_type (HERE).objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_gtlData))) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 161)).boolEnum () ;
      if (kBoolTrue == test_2) {
        TC_Array <C_FixItDescription> fixItArray3 ;
        inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) enumerator_5069.current_data (HERE).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 162)), extensionGetter_typeName (enumerator_5097.current_type (HERE), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 162)).add_operation (GALGAS_string (" expected for argument "), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 162)).add_operation (index_5042.add_operation (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 164)).getter_string (SOURCE_FILE ("gtl_data_types.galgas", 163)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 163)), fixItArray3  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 162)) ;
      }
      enumerator_5069.gotoNextObject () ;
      enumerator_5097.gotoNextObject () ;
      index_5042.increment_operation (inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 160)) ;
    }
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Once function 'emptylstring'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_lstring onceFunction_emptylstring (C_Compiler * /* inCompiler */
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring result_result ; // Returned variable
  result_result = GALGAS_lstring::constructor_new (GALGAS_string::makeEmptyString (), GALGAS_location::constructor_nowhere (SOURCE_FILE ("gtl_data_types.galgas", 172))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 172)) ;
//---
  return result_result ;
}



//---------------------------------------------------------------------------------------------------------------------*
//  Function implementation                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

static bool gOnceFunctionResultAvailable_emptylstring = false ;
static GALGAS_lstring gOnceFunctionResult_emptylstring ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring function_emptylstring (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_emptylstring) {
    gOnceFunctionResult_emptylstring = onceFunction_emptylstring (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_emptylstring = true ;
  }
  return gOnceFunctionResult_emptylstring ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void releaseOnceFunctionResult_emptylstring (void) {
  gOnceFunctionResult_emptylstring.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gEpilogueForOnceFunction_emptylstring (NULL,
                                                          releaseOnceFunctionResult_emptylstring) ;

//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_emptylstring [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_emptylstring (C_Compiler * inCompiler,
                                                             const cObjectArray & /* inEffectiveParameterArray */,
                                                             const GALGAS_location & /* inErrorLocation */
                                                             COMMA_LOCATION_ARGS) {
  return function_emptylstring (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_emptylstring ("emptylstring",
                                                              functionWithGenericHeader_emptylstring,
                                                              & kTypeDescriptor_GALGAS_lstring,
                                                              0,
                                                              functionArgs_emptylstring) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 Function 'lstring'                                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring function_lstring (GALGAS_string inArgument_string,
                                 C_Compiler * /* inCompiler */
                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring result_result ; // Returned variable
  result_result = GALGAS_lstring::constructor_new (inArgument_string, GALGAS_location::constructor_nowhere (SOURCE_FILE ("gtl_data_types.galgas", 177))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 177)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_lstring [2] = {
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_lstring (C_Compiler * inCompiler,
                                                        const cObjectArray & inEffectiveParameterArray,
                                                        const GALGAS_location & /* inErrorLocation */
                                                        COMMA_LOCATION_ARGS) {
  const GALGAS_string operand0 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_lstring (operand0,
                           inCompiler
                           COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_lstring ("lstring",
                                                         functionWithGenericHeader_lstring,
                                                         & kTypeDescriptor_GALGAS_lstring,
                                                         1,
                                                         functionArgs_lstring) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                Function 'trueFalse'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_trueFalse (const GALGAS_bool & constinArgument_inBool,
                                  C_Compiler * /* inCompiler */
                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const enumGalgasBool test_0 = constinArgument_inBool.boolEnum () ;
  if (kBoolTrue == test_0) {
    result_result = GALGAS_string ("true") ;
  }else if (kBoolFalse == test_0) {
    result_result = GALGAS_string ("false") ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_trueFalse [2] = {
  & kTypeDescriptor_GALGAS_bool,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_trueFalse (C_Compiler * inCompiler,
                                                          const cObjectArray & inEffectiveParameterArray,
                                                          const GALGAS_location & /* inErrorLocation */
                                                          COMMA_LOCATION_ARGS) {
  const GALGAS_bool operand0 = GALGAS_bool::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                           inCompiler
                                                           COMMA_THERE) ;
  return function_trueFalse (operand0,
                             inCompiler
                             COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_trueFalse ("trueFalse",
                                                           functionWithGenericHeader_trueFalse,
                                                           & kTypeDescriptor_GALGAS_string,
                                                           1,
                                                           functionArgs_trueFalse) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                Function 'TrueFalse'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_TrueFalse (const GALGAS_bool & constinArgument_inBool,
                                  C_Compiler * /* inCompiler */
                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const enumGalgasBool test_0 = constinArgument_inBool.boolEnum () ;
  if (kBoolTrue == test_0) {
    result_result = GALGAS_string ("True") ;
  }else if (kBoolFalse == test_0) {
    result_result = GALGAS_string ("False") ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_TrueFalse [2] = {
  & kTypeDescriptor_GALGAS_bool,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_TrueFalse (C_Compiler * inCompiler,
                                                          const cObjectArray & inEffectiveParameterArray,
                                                          const GALGAS_location & /* inErrorLocation */
                                                          COMMA_LOCATION_ARGS) {
  const GALGAS_bool operand0 = GALGAS_bool::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                           inCompiler
                                                           COMMA_THERE) ;
  return function_TrueFalse (operand0,
                             inCompiler
                             COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_TrueFalse ("TrueFalse",
                                                           functionWithGenericHeader_TrueFalse,
                                                           & kTypeDescriptor_GALGAS_string,
                                                           1,
                                                           functionArgs_TrueFalse) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  Function 'yesNo'                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_yesNo (const GALGAS_bool & constinArgument_inBool,
                              C_Compiler * /* inCompiler */
                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const enumGalgasBool test_0 = constinArgument_inBool.boolEnum () ;
  if (kBoolTrue == test_0) {
    result_result = GALGAS_string ("YES") ;
  }else if (kBoolFalse == test_0) {
    result_result = GALGAS_string ("NO") ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_yesNo [2] = {
  & kTypeDescriptor_GALGAS_bool,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_yesNo (C_Compiler * inCompiler,
                                                      const cObjectArray & inEffectiveParameterArray,
                                                      const GALGAS_location & /* inErrorLocation */
                                                      COMMA_LOCATION_ARGS) {
  const GALGAS_bool operand0 = GALGAS_bool::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                           inCompiler
                                                           COMMA_THERE) ;
  return function_yesNo (operand0,
                         inCompiler
                         COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_yesNo ("yesNo",
                                                       functionWithGenericHeader_yesNo,
                                                       & kTypeDescriptor_GALGAS_string,
                                                       1,
                                                       functionArgs_yesNo) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                Function 'TRUEFALSE'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_TRUEFALSE (const GALGAS_bool & constinArgument_inBool,
                                  C_Compiler * /* inCompiler */
                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const enumGalgasBool test_0 = constinArgument_inBool.boolEnum () ;
  if (kBoolTrue == test_0) {
    result_result = GALGAS_string ("TRUE") ;
  }else if (kBoolFalse == test_0) {
    result_result = GALGAS_string ("FALSE") ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_TRUEFALSE [2] = {
  & kTypeDescriptor_GALGAS_bool,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_TRUEFALSE (C_Compiler * inCompiler,
                                                          const cObjectArray & inEffectiveParameterArray,
                                                          const GALGAS_location & /* inErrorLocation */
                                                          COMMA_LOCATION_ARGS) {
  const GALGAS_bool operand0 = GALGAS_bool::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                           inCompiler
                                                           COMMA_THERE) ;
  return function_TRUEFALSE (operand0,
                             inCompiler
                             COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_TRUEFALSE ("TRUEFALSE",
                                                           functionWithGenericHeader_TRUEFALSE,
                                                           & kTypeDescriptor_GALGAS_string,
                                                           1,
                                                           functionArgs_TRUEFALSE) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                Function 'listOfSize'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_list function_listOfSize (GALGAS_bigint inArgument_inSize,
                                 C_Compiler * inCompiler
                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_list result_result ; // Returned variable
  result_result = GALGAS_list::constructor_emptyList (SOURCE_FILE ("gtl_functions.galgas", 84)) ;
  if (inArgument_inSize.getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_functions.galgas", 85)).isValid ()) {
    uint32_t variant_2589 = inArgument_inSize.getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_functions.galgas", 85)).uintValue () ;
    bool loop_2589 = true ;
    while (loop_2589) {
      loop_2589 = GALGAS_bool (kIsStrictSup, inArgument_inSize.objectCompare (GALGAS_uint ((uint32_t) 0U).getter_bigint (SOURCE_FILE ("gtl_functions.galgas", 86)))).isValid () ;
      if (loop_2589) {
        loop_2589 = GALGAS_bool (kIsStrictSup, inArgument_inSize.objectCompare (GALGAS_uint ((uint32_t) 0U).getter_bigint (SOURCE_FILE ("gtl_functions.galgas", 86)))).boolValue () ;
      }
      if (loop_2589 && (0 == variant_2589)) {
        loop_2589 = false ;
        inCompiler->loopRunTimeVariantError (SOURCE_FILE ("gtl_functions.galgas", 85)) ;
      }
      if (loop_2589) {
        variant_2589 -- ;
        result_result.addAssign_operation (GALGAS_gtlUnconstructed::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_functions.galgas", 87)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_functions.galgas", 87))  COMMA_SOURCE_FILE ("gtl_functions.galgas", 87))  COMMA_SOURCE_FILE ("gtl_functions.galgas", 87)) ;
        inArgument_inSize.decrement_operation (inCompiler  COMMA_SOURCE_FILE ("gtl_functions.galgas", 88)) ;
      }
    }
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_listOfSize [2] = {
  & kTypeDescriptor_GALGAS_bigint,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_listOfSize (C_Compiler * inCompiler,
                                                           const cObjectArray & inEffectiveParameterArray,
                                                           const GALGAS_location & /* inErrorLocation */
                                                           COMMA_LOCATION_ARGS) {
  const GALGAS_bigint operand0 = GALGAS_bigint::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_listOfSize (operand0,
                              inCompiler
                              COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_listOfSize ("listOfSize",
                                                            functionWithGenericHeader_listOfSize,
                                                            & kTypeDescriptor_GALGAS_list,
                                                            1,
                                                            functionArgs_listOfSize) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 Function 'version'                                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_version (C_Compiler * /* inCompiler */
                                COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_application::constructor_projectVersionString (SOURCE_FILE ("gtl_functions.galgas", 97)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_version [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_version (C_Compiler * inCompiler,
                                                        const cObjectArray & /* inEffectiveParameterArray */,
                                                        const GALGAS_location & /* inErrorLocation */
                                                        COMMA_LOCATION_ARGS) {
  return function_version (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_version ("version",
                                                         functionWithGenericHeader_version,
                                                         & kTypeDescriptor_GALGAS_string,
                                                         0,
                                                         functionArgs_version) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Function 'majorVersion'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bigint function_majorVersion (C_Compiler * inCompiler
                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bigint result_result ; // Returned variable
  GALGAS_string var_version_3236 = GALGAS_application::constructor_projectVersionString (SOURCE_FILE ("gtl_functions.galgas", 105)) ;
  GALGAS_stringlist var_versionComponents_3304 = var_version_3236.getter_componentsSeparatedByString (GALGAS_string (".") COMMA_SOURCE_FILE ("gtl_functions.galgas", 106)) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsStrictSup, var_versionComponents_3304.getter_length (SOURCE_FILE ("gtl_functions.galgas", 107)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
  if (kBoolTrue == test_0) {
    result_result = var_versionComponents_3304.getter_mValueAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("gtl_functions.galgas", 109)).getter_decimalUnsignedNumber (inCompiler COMMA_SOURCE_FILE ("gtl_functions.galgas", 109)).getter_bigint (SOURCE_FILE ("gtl_functions.galgas", 109)) ;
  }else if (kBoolFalse == test_0) {
    result_result = GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("gtl_functions.galgas", 111)) ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_majorVersion [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_majorVersion (C_Compiler * inCompiler,
                                                             const cObjectArray & /* inEffectiveParameterArray */,
                                                             const GALGAS_location & /* inErrorLocation */
                                                             COMMA_LOCATION_ARGS) {
  return function_majorVersion (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_majorVersion ("majorVersion",
                                                              functionWithGenericHeader_majorVersion,
                                                              & kTypeDescriptor_GALGAS_bigint,
                                                              0,
                                                              functionArgs_majorVersion) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Function 'minorVersion'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bigint function_minorVersion (C_Compiler * inCompiler
                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bigint result_result ; // Returned variable
  GALGAS_string var_version_3764 = GALGAS_application::constructor_projectVersionString (SOURCE_FILE ("gtl_functions.galgas", 120)) ;
  GALGAS_stringlist var_versionComponents_3832 = var_version_3764.getter_componentsSeparatedByString (GALGAS_string (".") COMMA_SOURCE_FILE ("gtl_functions.galgas", 121)) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsStrictSup, var_versionComponents_3832.getter_length (SOURCE_FILE ("gtl_functions.galgas", 122)).objectCompare (GALGAS_uint ((uint32_t) 1U))).boolEnum () ;
  if (kBoolTrue == test_0) {
    result_result = var_versionComponents_3832.getter_mValueAtIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("gtl_functions.galgas", 124)).getter_decimalUnsignedNumber (inCompiler COMMA_SOURCE_FILE ("gtl_functions.galgas", 124)).getter_bigint (SOURCE_FILE ("gtl_functions.galgas", 124)) ;
  }else if (kBoolFalse == test_0) {
    result_result = GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("gtl_functions.galgas", 126)) ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_minorVersion [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_minorVersion (C_Compiler * inCompiler,
                                                             const cObjectArray & /* inEffectiveParameterArray */,
                                                             const GALGAS_location & /* inErrorLocation */
                                                             COMMA_LOCATION_ARGS) {
  return function_minorVersion (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_minorVersion ("minorVersion",
                                                              functionWithGenericHeader_minorVersion,
                                                              & kTypeDescriptor_GALGAS_bigint,
                                                              0,
                                                              functionArgs_minorVersion) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 Function 'revision'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bigint function_revision (C_Compiler * inCompiler
                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bigint result_result ; // Returned variable
  GALGAS_string var_version_4283 = GALGAS_application::constructor_projectVersionString (SOURCE_FILE ("gtl_functions.galgas", 135)) ;
  GALGAS_stringlist var_versionComponents_4351 = var_version_4283.getter_componentsSeparatedByString (GALGAS_string (".") COMMA_SOURCE_FILE ("gtl_functions.galgas", 136)) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsStrictSup, var_versionComponents_4351.getter_length (SOURCE_FILE ("gtl_functions.galgas", 137)).objectCompare (GALGAS_uint ((uint32_t) 2U))).boolEnum () ;
  if (kBoolTrue == test_0) {
    result_result = var_versionComponents_4351.getter_mValueAtIndex (GALGAS_uint ((uint32_t) 2U), inCompiler COMMA_SOURCE_FILE ("gtl_functions.galgas", 139)).getter_decimalUnsignedNumber (inCompiler COMMA_SOURCE_FILE ("gtl_functions.galgas", 139)).getter_bigint (SOURCE_FILE ("gtl_functions.galgas", 139)) ;
  }else if (kBoolFalse == test_0) {
    result_result = GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("gtl_functions.galgas", 141)) ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_revision [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_revision (C_Compiler * inCompiler,
                                                         const cObjectArray & /* inEffectiveParameterArray */,
                                                         const GALGAS_location & /* inErrorLocation */
                                                         COMMA_LOCATION_ARGS) {
  return function_revision (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_revision ("revision",
                                                          functionWithGenericHeader_revision,
                                                          & kTypeDescriptor_GALGAS_bigint,
                                                          0,
                                                          functionArgs_revision) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                Function 'currentDir'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_currentDir (C_Compiler * /* inCompiler */
                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::constructor_stringWithCurrentDirectory (SOURCE_FILE ("gtl_functions.galgas", 150)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_currentDir [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_currentDir (C_Compiler * inCompiler,
                                                           const cObjectArray & /* inEffectiveParameterArray */,
                                                           const GALGAS_location & /* inErrorLocation */
                                                           COMMA_LOCATION_ARGS) {
  return function_currentDir (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_currentDir ("currentDir",
                                                            functionWithGenericHeader_currentDir,
                                                            & kTypeDescriptor_GALGAS_string,
                                                            0,
                                                            functionArgs_currentDir) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 Function 'homeDir'                                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_homeDir (C_Compiler * /* inCompiler */
                                COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::constructor_homeDirectory (SOURCE_FILE ("gtl_functions.galgas", 158)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_homeDir [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_homeDir (C_Compiler * inCompiler,
                                                        const cObjectArray & /* inEffectiveParameterArray */,
                                                        const GALGAS_location & /* inErrorLocation */
                                                        COMMA_LOCATION_ARGS) {
  return function_homeDir (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_homeDir ("homeDir",
                                                         functionWithGenericHeader_homeDir,
                                                         & kTypeDescriptor_GALGAS_string,
                                                         0,
                                                         functionArgs_homeDir) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             Function 'currentDateTime'                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_currentDateTime (C_Compiler * /* inCompiler */
                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::constructor_stringWithCurrentDateTime (SOURCE_FILE ("gtl_functions.galgas", 166)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_currentDateTime [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_currentDateTime (C_Compiler * inCompiler,
                                                                const cObjectArray & /* inEffectiveParameterArray */,
                                                                const GALGAS_location & /* inErrorLocation */
                                                                COMMA_LOCATION_ARGS) {
  return function_currentDateTime (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_currentDateTime ("currentDateTime",
                                                                 functionWithGenericHeader_currentDateTime,
                                                                 & kTypeDescriptor_GALGAS_string,
                                                                 0,
                                                                 functionArgs_currentDateTime) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Function 'max8bitsUnsignedInt'                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bigint function_max_38_bitsUnsignedInt (C_Compiler * /* inCompiler */
                                               COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bigint result_result ; // Returned variable
  result_result = GALGAS_uint ((uint32_t) 255U).getter_bigint (SOURCE_FILE ("gtl_functions.galgas", 174)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_max_38_bitsUnsignedInt [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_max_38_bitsUnsignedInt (C_Compiler * inCompiler,
                                                                       const cObjectArray & /* inEffectiveParameterArray */,
                                                                       const GALGAS_location & /* inErrorLocation */
                                                                       COMMA_LOCATION_ARGS) {
  return function_max_38_bitsUnsignedInt (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_max_38_bitsUnsignedInt ("max8bitsUnsignedInt",
                                                                        functionWithGenericHeader_max_38_bitsUnsignedInt,
                                                                        & kTypeDescriptor_GALGAS_bigint,
                                                                        0,
                                                                        functionArgs_max_38_bitsUnsignedInt) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Function 'max8bitsSignedInt'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bigint function_max_38_bitsSignedInt (C_Compiler * /* inCompiler */
                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bigint result_result ; // Returned variable
  result_result = GALGAS_uint ((uint32_t) 127U).getter_bigint (SOURCE_FILE ("gtl_functions.galgas", 182)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_max_38_bitsSignedInt [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_max_38_bitsSignedInt (C_Compiler * inCompiler,
                                                                     const cObjectArray & /* inEffectiveParameterArray */,
                                                                     const GALGAS_location & /* inErrorLocation */
                                                                     COMMA_LOCATION_ARGS) {
  return function_max_38_bitsSignedInt (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_max_38_bitsSignedInt ("max8bitsSignedInt",
                                                                      functionWithGenericHeader_max_38_bitsSignedInt,
                                                                      & kTypeDescriptor_GALGAS_bigint,
                                                                      0,
                                                                      functionArgs_max_38_bitsSignedInt) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Function 'min8bitsSignedInt'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bigint function_min_38_bitsSignedInt (C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bigint result_result ; // Returned variable
  result_result = GALGAS_sint ((int32_t) 128L).operator_unary_minus (inCompiler COMMA_SOURCE_FILE ("gtl_functions.galgas", 190)).getter_bigint (SOURCE_FILE ("gtl_functions.galgas", 190)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_min_38_bitsSignedInt [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_min_38_bitsSignedInt (C_Compiler * inCompiler,
                                                                     const cObjectArray & /* inEffectiveParameterArray */,
                                                                     const GALGAS_location & /* inErrorLocation */
                                                                     COMMA_LOCATION_ARGS) {
  return function_min_38_bitsSignedInt (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_min_38_bitsSignedInt ("min8bitsSignedInt",
                                                                      functionWithGenericHeader_min_38_bitsSignedInt,
                                                                      & kTypeDescriptor_GALGAS_bigint,
                                                                      0,
                                                                      functionArgs_min_38_bitsSignedInt) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Function 'max16bitsUnsignedInt'                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bigint function_max_31__36_bitsUnsignedInt (C_Compiler * /* inCompiler */
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bigint result_result ; // Returned variable
  result_result = GALGAS_uint ((uint32_t) 65535U).getter_bigint (SOURCE_FILE ("gtl_functions.galgas", 198)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_max_31__36_bitsUnsignedInt [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_max_31__36_bitsUnsignedInt (C_Compiler * inCompiler,
                                                                           const cObjectArray & /* inEffectiveParameterArray */,
                                                                           const GALGAS_location & /* inErrorLocation */
                                                                           COMMA_LOCATION_ARGS) {
  return function_max_31__36_bitsUnsignedInt (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_max_31__36_bitsUnsignedInt ("max16bitsUnsignedInt",
                                                                            functionWithGenericHeader_max_31__36_bitsUnsignedInt,
                                                                            & kTypeDescriptor_GALGAS_bigint,
                                                                            0,
                                                                            functionArgs_max_31__36_bitsUnsignedInt) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Function 'max16bitsSignedInt'                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bigint function_max_31__36_bitsSignedInt (C_Compiler * /* inCompiler */
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bigint result_result ; // Returned variable
  result_result = GALGAS_uint ((uint32_t) 32767U).getter_bigint (SOURCE_FILE ("gtl_functions.galgas", 206)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_max_31__36_bitsSignedInt [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_max_31__36_bitsSignedInt (C_Compiler * inCompiler,
                                                                         const cObjectArray & /* inEffectiveParameterArray */,
                                                                         const GALGAS_location & /* inErrorLocation */
                                                                         COMMA_LOCATION_ARGS) {
  return function_max_31__36_bitsSignedInt (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_max_31__36_bitsSignedInt ("max16bitsSignedInt",
                                                                          functionWithGenericHeader_max_31__36_bitsSignedInt,
                                                                          & kTypeDescriptor_GALGAS_bigint,
                                                                          0,
                                                                          functionArgs_max_31__36_bitsSignedInt) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Function 'min16bitsSignedInt'                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bigint function_min_31__36_bitsSignedInt (C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bigint result_result ; // Returned variable
  result_result = GALGAS_sint ((int32_t) 32768L).operator_unary_minus (inCompiler COMMA_SOURCE_FILE ("gtl_functions.galgas", 214)).getter_bigint (SOURCE_FILE ("gtl_functions.galgas", 214)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_min_31__36_bitsSignedInt [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_min_31__36_bitsSignedInt (C_Compiler * inCompiler,
                                                                         const cObjectArray & /* inEffectiveParameterArray */,
                                                                         const GALGAS_location & /* inErrorLocation */
                                                                         COMMA_LOCATION_ARGS) {
  return function_min_31__36_bitsSignedInt (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_min_31__36_bitsSignedInt ("min16bitsSignedInt",
                                                                          functionWithGenericHeader_min_31__36_bitsSignedInt,
                                                                          & kTypeDescriptor_GALGAS_bigint,
                                                                          0,
                                                                          functionArgs_min_31__36_bitsSignedInt) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Function 'max32bitsUnsignedInt'                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bigint function_max_33__32_bitsUnsignedInt (C_Compiler * /* inCompiler */
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bigint result_result ; // Returned variable
  result_result = GALGAS_uint::constructor_max (SOURCE_FILE ("gtl_functions.galgas", 222)).getter_bigint (SOURCE_FILE ("gtl_functions.galgas", 222)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_max_33__32_bitsUnsignedInt [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_max_33__32_bitsUnsignedInt (C_Compiler * inCompiler,
                                                                           const cObjectArray & /* inEffectiveParameterArray */,
                                                                           const GALGAS_location & /* inErrorLocation */
                                                                           COMMA_LOCATION_ARGS) {
  return function_max_33__32_bitsUnsignedInt (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_max_33__32_bitsUnsignedInt ("max32bitsUnsignedInt",
                                                                            functionWithGenericHeader_max_33__32_bitsUnsignedInt,
                                                                            & kTypeDescriptor_GALGAS_bigint,
                                                                            0,
                                                                            functionArgs_max_33__32_bitsUnsignedInt) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Function 'max32bitsSignedInt'                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bigint function_max_33__32_bitsSignedInt (C_Compiler * /* inCompiler */
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bigint result_result ; // Returned variable
  result_result = GALGAS_sint::constructor_max (SOURCE_FILE ("gtl_functions.galgas", 230)).getter_bigint (SOURCE_FILE ("gtl_functions.galgas", 230)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_max_33__32_bitsSignedInt [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_max_33__32_bitsSignedInt (C_Compiler * inCompiler,
                                                                         const cObjectArray & /* inEffectiveParameterArray */,
                                                                         const GALGAS_location & /* inErrorLocation */
                                                                         COMMA_LOCATION_ARGS) {
  return function_max_33__32_bitsSignedInt (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_max_33__32_bitsSignedInt ("max32bitsSignedInt",
                                                                          functionWithGenericHeader_max_33__32_bitsSignedInt,
                                                                          & kTypeDescriptor_GALGAS_bigint,
                                                                          0,
                                                                          functionArgs_max_33__32_bitsSignedInt) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Function 'min32bitsSignedInt'                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bigint function_min_33__32_bitsSignedInt (C_Compiler * /* inCompiler */
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bigint result_result ; // Returned variable
  result_result = GALGAS_sint::constructor_min (SOURCE_FILE ("gtl_functions.galgas", 238)).getter_bigint (SOURCE_FILE ("gtl_functions.galgas", 238)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_min_33__32_bitsSignedInt [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_min_33__32_bitsSignedInt (C_Compiler * inCompiler,
                                                                         const cObjectArray & /* inEffectiveParameterArray */,
                                                                         const GALGAS_location & /* inErrorLocation */
                                                                         COMMA_LOCATION_ARGS) {
  return function_min_33__32_bitsSignedInt (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_min_33__32_bitsSignedInt ("min32bitsSignedInt",
                                                                          functionWithGenericHeader_min_33__32_bitsSignedInt,
                                                                          & kTypeDescriptor_GALGAS_bigint,
                                                                          0,
                                                                          functionArgs_min_33__32_bitsSignedInt) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Function 'max64bitsUnsignedInt'                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bigint function_max_36__34_bitsUnsignedInt (C_Compiler * /* inCompiler */
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bigint result_result ; // Returned variable
  result_result = GALGAS_uint_36__34_::constructor_max (SOURCE_FILE ("gtl_functions.galgas", 246)).getter_bigint (SOURCE_FILE ("gtl_functions.galgas", 246)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_max_36__34_bitsUnsignedInt [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_max_36__34_bitsUnsignedInt (C_Compiler * inCompiler,
                                                                           const cObjectArray & /* inEffectiveParameterArray */,
                                                                           const GALGAS_location & /* inErrorLocation */
                                                                           COMMA_LOCATION_ARGS) {
  return function_max_36__34_bitsUnsignedInt (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_max_36__34_bitsUnsignedInt ("max64bitsUnsignedInt",
                                                                            functionWithGenericHeader_max_36__34_bitsUnsignedInt,
                                                                            & kTypeDescriptor_GALGAS_bigint,
                                                                            0,
                                                                            functionArgs_max_36__34_bitsUnsignedInt) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Function 'max64bitsSignedInt'                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bigint function_max_36__34_bitsSignedInt (C_Compiler * /* inCompiler */
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bigint result_result ; // Returned variable
  result_result = GALGAS_sint_36__34_::constructor_max (SOURCE_FILE ("gtl_functions.galgas", 254)).getter_bigint (SOURCE_FILE ("gtl_functions.galgas", 254)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_max_36__34_bitsSignedInt [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_max_36__34_bitsSignedInt (C_Compiler * inCompiler,
                                                                         const cObjectArray & /* inEffectiveParameterArray */,
                                                                         const GALGAS_location & /* inErrorLocation */
                                                                         COMMA_LOCATION_ARGS) {
  return function_max_36__34_bitsSignedInt (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_max_36__34_bitsSignedInt ("max64bitsSignedInt",
                                                                          functionWithGenericHeader_max_36__34_bitsSignedInt,
                                                                          & kTypeDescriptor_GALGAS_bigint,
                                                                          0,
                                                                          functionArgs_max_36__34_bitsSignedInt) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Function 'min64bitsSignedInt'                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bigint function_min_36__34_bitsSignedInt (C_Compiler * /* inCompiler */
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bigint result_result ; // Returned variable
  result_result = GALGAS_sint_36__34_::constructor_min (SOURCE_FILE ("gtl_functions.galgas", 262)).getter_bigint (SOURCE_FILE ("gtl_functions.galgas", 262)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_min_36__34_bitsSignedInt [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_min_36__34_bitsSignedInt (C_Compiler * inCompiler,
                                                                         const cObjectArray & /* inEffectiveParameterArray */,
                                                                         const GALGAS_location & /* inErrorLocation */
                                                                         COMMA_LOCATION_ARGS) {
  return function_min_36__34_bitsSignedInt (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_min_36__34_bitsSignedInt ("min64bitsSignedInt",
                                                                          functionWithGenericHeader_min_36__34_bitsSignedInt,
                                                                          & kTypeDescriptor_GALGAS_bigint,
                                                                          0,
                                                                          functionArgs_min_36__34_bitsSignedInt) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                    Function 'pi'                                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_double function_pi (C_Compiler * /* inCompiler */
                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_double result_result ; // Returned variable
  result_result = GALGAS_double::constructor_pi (SOURCE_FILE ("gtl_functions.galgas", 270)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_pi [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_pi (C_Compiler * inCompiler,
                                                   const cObjectArray & /* inEffectiveParameterArray */,
                                                   const GALGAS_location & /* inErrorLocation */
                                                   COMMA_LOCATION_ARGS) {
  return function_pi (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_pi ("pi",
                                                    functionWithGenericHeader_pi,
                                                    & kTypeDescriptor_GALGAS_double,
                                                    0,
                                                    functionArgs_pi) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               Bool options                                                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

C_BoolCommandLineOption gOption_gtl_5F_options_debug ("gtl_options",
                                         "debug",
                                         0,
                                         "debug",
                                         "Execute the GTL templates in debug mode") ;

C_BoolCommandLineOption gOption_gtl_5F_options_warnDeprecated ("gtl_options",
                                         "warnDeprecated",
                                         0,
                                         "warn-deprecated",
                                         "Warns about deprecated constructs in the GTL template language") ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               UInt options                                                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              String options                                                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              String List options                                                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

//---------------------------------------------------------------------------------------------------------------------*


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                Function 'signature'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_signature (GALGAS_location inArgument_loc,
                                  C_Compiler * inCompiler
                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const enumGalgasBool test_0 = GALGAS_bool (gOption_gtl_5F_options_debug.getter_value ()).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_string var_signatureString_789 = inArgument_loc.getter_file (inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 33)).getter_lastPathComponent (SOURCE_FILE ("gtl_debugger.galgas", 33)).add_operation (GALGAS_string (":"), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 33)).add_operation (inArgument_loc.getter_line (inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 35)).getter_string (SOURCE_FILE ("gtl_debugger.galgas", 34)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 34)) ;
    result_result = var_signatureString_789.getter_md_35_ (SOURCE_FILE ("gtl_debugger.galgas", 37)) ;
  }else if (kBoolFalse == test_0) {
    result_result = GALGAS_string::makeEmptyString () ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_signature [2] = {
  & kTypeDescriptor_GALGAS_location,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_signature (C_Compiler * inCompiler,
                                                          const cObjectArray & inEffectiveParameterArray,
                                                          const GALGAS_location & /* inErrorLocation */
                                                          COMMA_LOCATION_ARGS) {
  const GALGAS_location operand0 = GALGAS_location::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                   inCompiler
                                                                   COMMA_THERE) ;
  return function_signature (operand0,
                             inCompiler
                             COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_signature ("signature",
                                                           functionWithGenericHeader_signature,
                                                           & kTypeDescriptor_GALGAS_string,
                                                           1,
                                                           functionArgs_signature) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                Once function 'bold'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string onceFunction_bold (C_Compiler * /* inCompiler */
                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_bold ; // Returned variable
  result_bold = GALGAS_string ("\x1B""[1m") ;
//---
  return result_bold ;
}



//---------------------------------------------------------------------------------------------------------------------*
//  Function implementation                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

static bool gOnceFunctionResultAvailable_bold = false ;
static GALGAS_string gOnceFunctionResult_bold ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_bold (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_bold) {
    gOnceFunctionResult_bold = onceFunction_bold (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_bold = true ;
  }
  return gOnceFunctionResult_bold ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void releaseOnceFunctionResult_bold (void) {
  gOnceFunctionResult_bold.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gEpilogueForOnceFunction_bold (NULL,
                                                  releaseOnceFunctionResult_bold) ;

//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_bold [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_bold (C_Compiler * inCompiler,
                                                     const cObjectArray & /* inEffectiveParameterArray */,
                                                     const GALGAS_location & /* inErrorLocation */
                                                     COMMA_LOCATION_ARGS) {
  return function_bold (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_bold ("bold",
                                                      functionWithGenericHeader_bold,
                                                      & kTypeDescriptor_GALGAS_string,
                                                      0,
                                                      functionArgs_bold) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Once function 'underline'                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string onceFunction_underline (C_Compiler * /* inCompiler */
                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_underline ; // Returned variable
  result_underline = GALGAS_string ("\x1B""[4m") ;
//---
  return result_underline ;
}



//---------------------------------------------------------------------------------------------------------------------*
//  Function implementation                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

static bool gOnceFunctionResultAvailable_underline = false ;
static GALGAS_string gOnceFunctionResult_underline ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_underline (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_underline) {
    gOnceFunctionResult_underline = onceFunction_underline (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_underline = true ;
  }
  return gOnceFunctionResult_underline ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void releaseOnceFunctionResult_underline (void) {
  gOnceFunctionResult_underline.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gEpilogueForOnceFunction_underline (NULL,
                                                       releaseOnceFunctionResult_underline) ;

//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_underline [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_underline (C_Compiler * inCompiler,
                                                          const cObjectArray & /* inEffectiveParameterArray */,
                                                          const GALGAS_location & /* inErrorLocation */
                                                          COMMA_LOCATION_ARGS) {
  return function_underline (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_underline ("underline",
                                                           functionWithGenericHeader_underline,
                                                           & kTypeDescriptor_GALGAS_string,
                                                           0,
                                                           functionArgs_underline) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                Once function 'blink'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string onceFunction_blink (C_Compiler * /* inCompiler */
                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_blink ; // Returned variable
  result_blink = GALGAS_string ("\x1B""[5m") ;
//---
  return result_blink ;
}



//---------------------------------------------------------------------------------------------------------------------*
//  Function implementation                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

static bool gOnceFunctionResultAvailable_blink = false ;
static GALGAS_string gOnceFunctionResult_blink ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_blink (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_blink) {
    gOnceFunctionResult_blink = onceFunction_blink (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_blink = true ;
  }
  return gOnceFunctionResult_blink ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void releaseOnceFunctionResult_blink (void) {
  gOnceFunctionResult_blink.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gEpilogueForOnceFunction_blink (NULL,
                                                   releaseOnceFunctionResult_blink) ;

//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_blink [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_blink (C_Compiler * inCompiler,
                                                      const cObjectArray & /* inEffectiveParameterArray */,
                                                      const GALGAS_location & /* inErrorLocation */
                                                      COMMA_LOCATION_ARGS) {
  return function_blink (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_blink ("blink",
                                                       functionWithGenericHeader_blink,
                                                       & kTypeDescriptor_GALGAS_string,
                                                       0,
                                                       functionArgs_blink) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                Once function 'black'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string onceFunction_black (C_Compiler * /* inCompiler */
                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_black ; // Returned variable
  result_black = GALGAS_string ("\x1B""[90m") ;
//---
  return result_black ;
}



//---------------------------------------------------------------------------------------------------------------------*
//  Function implementation                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

static bool gOnceFunctionResultAvailable_black = false ;
static GALGAS_string gOnceFunctionResult_black ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_black (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_black) {
    gOnceFunctionResult_black = onceFunction_black (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_black = true ;
  }
  return gOnceFunctionResult_black ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void releaseOnceFunctionResult_black (void) {
  gOnceFunctionResult_black.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gEpilogueForOnceFunction_black (NULL,
                                                   releaseOnceFunctionResult_black) ;

//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_black [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_black (C_Compiler * inCompiler,
                                                      const cObjectArray & /* inEffectiveParameterArray */,
                                                      const GALGAS_location & /* inErrorLocation */
                                                      COMMA_LOCATION_ARGS) {
  return function_black (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_black ("black",
                                                       functionWithGenericHeader_black,
                                                       & kTypeDescriptor_GALGAS_string,
                                                       0,
                                                       functionArgs_black) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 Once function 'red'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string onceFunction_red (C_Compiler * /* inCompiler */
                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_red ; // Returned variable
  result_red = GALGAS_string ("\x1B""[91m") ;
//---
  return result_red ;
}



//---------------------------------------------------------------------------------------------------------------------*
//  Function implementation                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

static bool gOnceFunctionResultAvailable_red = false ;
static GALGAS_string gOnceFunctionResult_red ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_red (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_red) {
    gOnceFunctionResult_red = onceFunction_red (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_red = true ;
  }
  return gOnceFunctionResult_red ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void releaseOnceFunctionResult_red (void) {
  gOnceFunctionResult_red.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gEpilogueForOnceFunction_red (NULL,
                                                 releaseOnceFunctionResult_red) ;

//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_red [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_red (C_Compiler * inCompiler,
                                                    const cObjectArray & /* inEffectiveParameterArray */,
                                                    const GALGAS_location & /* inErrorLocation */
                                                    COMMA_LOCATION_ARGS) {
  return function_red (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_red ("red",
                                                     functionWithGenericHeader_red,
                                                     & kTypeDescriptor_GALGAS_string,
                                                     0,
                                                     functionArgs_red) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                Once function 'green'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string onceFunction_green (C_Compiler * /* inCompiler */
                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_green ; // Returned variable
  result_green = GALGAS_string ("\x1B""[92m") ;
//---
  return result_green ;
}



//---------------------------------------------------------------------------------------------------------------------*
//  Function implementation                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

static bool gOnceFunctionResultAvailable_green = false ;
static GALGAS_string gOnceFunctionResult_green ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_green (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_green) {
    gOnceFunctionResult_green = onceFunction_green (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_green = true ;
  }
  return gOnceFunctionResult_green ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void releaseOnceFunctionResult_green (void) {
  gOnceFunctionResult_green.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gEpilogueForOnceFunction_green (NULL,
                                                   releaseOnceFunctionResult_green) ;

//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_green [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_green (C_Compiler * inCompiler,
                                                      const cObjectArray & /* inEffectiveParameterArray */,
                                                      const GALGAS_location & /* inErrorLocation */
                                                      COMMA_LOCATION_ARGS) {
  return function_green (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_green ("green",
                                                       functionWithGenericHeader_green,
                                                       & kTypeDescriptor_GALGAS_string,
                                                       0,
                                                       functionArgs_green) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Once function 'yellow'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string onceFunction_yellow (C_Compiler * /* inCompiler */
                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_yellow ; // Returned variable
  result_yellow = GALGAS_string ("\x1B""[93m") ;
//---
  return result_yellow ;
}



//---------------------------------------------------------------------------------------------------------------------*
//  Function implementation                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

static bool gOnceFunctionResultAvailable_yellow = false ;
static GALGAS_string gOnceFunctionResult_yellow ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_yellow (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_yellow) {
    gOnceFunctionResult_yellow = onceFunction_yellow (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_yellow = true ;
  }
  return gOnceFunctionResult_yellow ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void releaseOnceFunctionResult_yellow (void) {
  gOnceFunctionResult_yellow.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gEpilogueForOnceFunction_yellow (NULL,
                                                    releaseOnceFunctionResult_yellow) ;

//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_yellow [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_yellow (C_Compiler * inCompiler,
                                                       const cObjectArray & /* inEffectiveParameterArray */,
                                                       const GALGAS_location & /* inErrorLocation */
                                                       COMMA_LOCATION_ARGS) {
  return function_yellow (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_yellow ("yellow",
                                                        functionWithGenericHeader_yellow,
                                                        & kTypeDescriptor_GALGAS_string,
                                                        0,
                                                        functionArgs_yellow) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                Once function 'blue'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string onceFunction_blue (C_Compiler * /* inCompiler */
                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_blue ; // Returned variable
  result_blue = GALGAS_string ("\x1B""[94m") ;
//---
  return result_blue ;
}



//---------------------------------------------------------------------------------------------------------------------*
//  Function implementation                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

static bool gOnceFunctionResultAvailable_blue = false ;
static GALGAS_string gOnceFunctionResult_blue ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_blue (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_blue) {
    gOnceFunctionResult_blue = onceFunction_blue (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_blue = true ;
  }
  return gOnceFunctionResult_blue ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void releaseOnceFunctionResult_blue (void) {
  gOnceFunctionResult_blue.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gEpilogueForOnceFunction_blue (NULL,
                                                  releaseOnceFunctionResult_blue) ;

//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_blue [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_blue (C_Compiler * inCompiler,
                                                     const cObjectArray & /* inEffectiveParameterArray */,
                                                     const GALGAS_location & /* inErrorLocation */
                                                     COMMA_LOCATION_ARGS) {
  return function_blue (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_blue ("blue",
                                                      functionWithGenericHeader_blue,
                                                      & kTypeDescriptor_GALGAS_string,
                                                      0,
                                                      functionArgs_blue) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Once function 'magenta'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string onceFunction_magenta (C_Compiler * /* inCompiler */
                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_magenta ; // Returned variable
  result_magenta = GALGAS_string ("\x1B""[95m") ;
//---
  return result_magenta ;
}



//---------------------------------------------------------------------------------------------------------------------*
//  Function implementation                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

static bool gOnceFunctionResultAvailable_magenta = false ;
static GALGAS_string gOnceFunctionResult_magenta ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_magenta (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_magenta) {
    gOnceFunctionResult_magenta = onceFunction_magenta (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_magenta = true ;
  }
  return gOnceFunctionResult_magenta ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void releaseOnceFunctionResult_magenta (void) {
  gOnceFunctionResult_magenta.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gEpilogueForOnceFunction_magenta (NULL,
                                                     releaseOnceFunctionResult_magenta) ;

//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_magenta [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_magenta (C_Compiler * inCompiler,
                                                        const cObjectArray & /* inEffectiveParameterArray */,
                                                        const GALGAS_location & /* inErrorLocation */
                                                        COMMA_LOCATION_ARGS) {
  return function_magenta (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_magenta ("magenta",
                                                         functionWithGenericHeader_magenta,
                                                         & kTypeDescriptor_GALGAS_string,
                                                         0,
                                                         functionArgs_magenta) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                Once function 'cyan'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string onceFunction_cyan (C_Compiler * /* inCompiler */
                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_cyan ; // Returned variable
  result_cyan = GALGAS_string ("\x1B""[96m") ;
//---
  return result_cyan ;
}



//---------------------------------------------------------------------------------------------------------------------*
//  Function implementation                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

static bool gOnceFunctionResultAvailable_cyan = false ;
static GALGAS_string gOnceFunctionResult_cyan ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_cyan (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_cyan) {
    gOnceFunctionResult_cyan = onceFunction_cyan (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_cyan = true ;
  }
  return gOnceFunctionResult_cyan ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void releaseOnceFunctionResult_cyan (void) {
  gOnceFunctionResult_cyan.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gEpilogueForOnceFunction_cyan (NULL,
                                                  releaseOnceFunctionResult_cyan) ;

//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_cyan [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_cyan (C_Compiler * inCompiler,
                                                     const cObjectArray & /* inEffectiveParameterArray */,
                                                     const GALGAS_location & /* inErrorLocation */
                                                     COMMA_LOCATION_ARGS) {
  return function_cyan (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_cyan ("cyan",
                                                      functionWithGenericHeader_cyan,
                                                      & kTypeDescriptor_GALGAS_string,
                                                      0,
                                                      functionArgs_cyan) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Once function 'darkred'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string onceFunction_darkred (C_Compiler * /* inCompiler */
                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_red ; // Returned variable
  result_red = GALGAS_string ("\x1B""[31m") ;
//---
  return result_red ;
}



//---------------------------------------------------------------------------------------------------------------------*
//  Function implementation                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

static bool gOnceFunctionResultAvailable_darkred = false ;
static GALGAS_string gOnceFunctionResult_darkred ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_darkred (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_darkred) {
    gOnceFunctionResult_darkred = onceFunction_darkred (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_darkred = true ;
  }
  return gOnceFunctionResult_darkred ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void releaseOnceFunctionResult_darkred (void) {
  gOnceFunctionResult_darkred.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gEpilogueForOnceFunction_darkred (NULL,
                                                     releaseOnceFunctionResult_darkred) ;

//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_darkred [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_darkred (C_Compiler * inCompiler,
                                                        const cObjectArray & /* inEffectiveParameterArray */,
                                                        const GALGAS_location & /* inErrorLocation */
                                                        COMMA_LOCATION_ARGS) {
  return function_darkred (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_darkred ("darkred",
                                                         functionWithGenericHeader_darkred,
                                                         & kTypeDescriptor_GALGAS_string,
                                                         0,
                                                         functionArgs_darkred) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Once function 'darkgreen'                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string onceFunction_darkgreen (C_Compiler * /* inCompiler */
                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_green ; // Returned variable
  result_green = GALGAS_string ("\x1B""[32m") ;
//---
  return result_green ;
}



//---------------------------------------------------------------------------------------------------------------------*
//  Function implementation                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

static bool gOnceFunctionResultAvailable_darkgreen = false ;
static GALGAS_string gOnceFunctionResult_darkgreen ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_darkgreen (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_darkgreen) {
    gOnceFunctionResult_darkgreen = onceFunction_darkgreen (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_darkgreen = true ;
  }
  return gOnceFunctionResult_darkgreen ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void releaseOnceFunctionResult_darkgreen (void) {
  gOnceFunctionResult_darkgreen.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gEpilogueForOnceFunction_darkgreen (NULL,
                                                       releaseOnceFunctionResult_darkgreen) ;

//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_darkgreen [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_darkgreen (C_Compiler * inCompiler,
                                                          const cObjectArray & /* inEffectiveParameterArray */,
                                                          const GALGAS_location & /* inErrorLocation */
                                                          COMMA_LOCATION_ARGS) {
  return function_darkgreen (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_darkgreen ("darkgreen",
                                                           functionWithGenericHeader_darkgreen,
                                                           & kTypeDescriptor_GALGAS_string,
                                                           0,
                                                           functionArgs_darkgreen) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             Once function 'darkyellow'                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string onceFunction_darkyellow (C_Compiler * /* inCompiler */
                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_yellow ; // Returned variable
  result_yellow = GALGAS_string ("\x1B""[33m") ;
//---
  return result_yellow ;
}



//---------------------------------------------------------------------------------------------------------------------*
//  Function implementation                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

static bool gOnceFunctionResultAvailable_darkyellow = false ;
static GALGAS_string gOnceFunctionResult_darkyellow ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_darkyellow (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_darkyellow) {
    gOnceFunctionResult_darkyellow = onceFunction_darkyellow (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_darkyellow = true ;
  }
  return gOnceFunctionResult_darkyellow ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void releaseOnceFunctionResult_darkyellow (void) {
  gOnceFunctionResult_darkyellow.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gEpilogueForOnceFunction_darkyellow (NULL,
                                                        releaseOnceFunctionResult_darkyellow) ;

//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_darkyellow [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_darkyellow (C_Compiler * inCompiler,
                                                           const cObjectArray & /* inEffectiveParameterArray */,
                                                           const GALGAS_location & /* inErrorLocation */
                                                           COMMA_LOCATION_ARGS) {
  return function_darkyellow (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_darkyellow ("darkyellow",
                                                            functionWithGenericHeader_darkyellow,
                                                            & kTypeDescriptor_GALGAS_string,
                                                            0,
                                                            functionArgs_darkyellow) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Once function 'darkblue'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string onceFunction_darkblue (C_Compiler * /* inCompiler */
                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_blue ; // Returned variable
  result_blue = GALGAS_string ("\x1B""[34m") ;
//---
  return result_blue ;
}



//---------------------------------------------------------------------------------------------------------------------*
//  Function implementation                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

static bool gOnceFunctionResultAvailable_darkblue = false ;
static GALGAS_string gOnceFunctionResult_darkblue ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_darkblue (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_darkblue) {
    gOnceFunctionResult_darkblue = onceFunction_darkblue (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_darkblue = true ;
  }
  return gOnceFunctionResult_darkblue ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void releaseOnceFunctionResult_darkblue (void) {
  gOnceFunctionResult_darkblue.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gEpilogueForOnceFunction_darkblue (NULL,
                                                      releaseOnceFunctionResult_darkblue) ;

//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_darkblue [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_darkblue (C_Compiler * inCompiler,
                                                         const cObjectArray & /* inEffectiveParameterArray */,
                                                         const GALGAS_location & /* inErrorLocation */
                                                         COMMA_LOCATION_ARGS) {
  return function_darkblue (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_darkblue ("darkblue",
                                                          functionWithGenericHeader_darkblue,
                                                          & kTypeDescriptor_GALGAS_string,
                                                          0,
                                                          functionArgs_darkblue) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             Once function 'darkmagenta'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string onceFunction_darkmagenta (C_Compiler * /* inCompiler */
                                               COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_magenta ; // Returned variable
  result_magenta = GALGAS_string ("\x1B""[35m") ;
//---
  return result_magenta ;
}



//---------------------------------------------------------------------------------------------------------------------*
//  Function implementation                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

static bool gOnceFunctionResultAvailable_darkmagenta = false ;
static GALGAS_string gOnceFunctionResult_darkmagenta ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_darkmagenta (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_darkmagenta) {
    gOnceFunctionResult_darkmagenta = onceFunction_darkmagenta (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_darkmagenta = true ;
  }
  return gOnceFunctionResult_darkmagenta ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void releaseOnceFunctionResult_darkmagenta (void) {
  gOnceFunctionResult_darkmagenta.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gEpilogueForOnceFunction_darkmagenta (NULL,
                                                         releaseOnceFunctionResult_darkmagenta) ;

//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_darkmagenta [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_darkmagenta (C_Compiler * inCompiler,
                                                            const cObjectArray & /* inEffectiveParameterArray */,
                                                            const GALGAS_location & /* inErrorLocation */
                                                            COMMA_LOCATION_ARGS) {
  return function_darkmagenta (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_darkmagenta ("darkmagenta",
                                                             functionWithGenericHeader_darkmagenta,
                                                             & kTypeDescriptor_GALGAS_string,
                                                             0,
                                                             functionArgs_darkmagenta) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Once function 'darkcyan'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string onceFunction_darkcyan (C_Compiler * /* inCompiler */
                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_cyan ; // Returned variable
  result_cyan = GALGAS_string ("\x1B""[36m") ;
//---
  return result_cyan ;
}



//---------------------------------------------------------------------------------------------------------------------*
//  Function implementation                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

static bool gOnceFunctionResultAvailable_darkcyan = false ;
static GALGAS_string gOnceFunctionResult_darkcyan ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_darkcyan (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_darkcyan) {
    gOnceFunctionResult_darkcyan = onceFunction_darkcyan (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_darkcyan = true ;
  }
  return gOnceFunctionResult_darkcyan ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void releaseOnceFunctionResult_darkcyan (void) {
  gOnceFunctionResult_darkcyan.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gEpilogueForOnceFunction_darkcyan (NULL,
                                                      releaseOnceFunctionResult_darkcyan) ;

//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_darkcyan [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_darkcyan (C_Compiler * inCompiler,
                                                         const cObjectArray & /* inEffectiveParameterArray */,
                                                         const GALGAS_location & /* inErrorLocation */
                                                         COMMA_LOCATION_ARGS) {
  return function_darkcyan (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_darkcyan ("darkcyan",
                                                          functionWithGenericHeader_darkcyan,
                                                          & kTypeDescriptor_GALGAS_string,
                                                          0,
                                                          functionArgs_darkcyan) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                Once function 'white'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string onceFunction_white (C_Compiler * /* inCompiler */
                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_white ; // Returned variable
  result_white = GALGAS_string ("\x1B""[97m") ;
//---
  return result_white ;
}



//---------------------------------------------------------------------------------------------------------------------*
//  Function implementation                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

static bool gOnceFunctionResultAvailable_white = false ;
static GALGAS_string gOnceFunctionResult_white ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_white (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_white) {
    gOnceFunctionResult_white = onceFunction_white (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_white = true ;
  }
  return gOnceFunctionResult_white ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void releaseOnceFunctionResult_white (void) {
  gOnceFunctionResult_white.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gEpilogueForOnceFunction_white (NULL,
                                                   releaseOnceFunctionResult_white) ;

//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_white [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_white (C_Compiler * inCompiler,
                                                      const cObjectArray & /* inEffectiveParameterArray */,
                                                      const GALGAS_location & /* inErrorLocation */
                                                      COMMA_LOCATION_ARGS) {
  return function_white (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_white ("white",
                                                       functionWithGenericHeader_white,
                                                       & kTypeDescriptor_GALGAS_string,
                                                       0,
                                                       functionArgs_white) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                Once function 'endc'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string onceFunction_endc (C_Compiler * /* inCompiler */
                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_endc ; // Returned variable
  result_endc = GALGAS_string ("\x1B""[0m") ;
//---
  return result_endc ;
}



//---------------------------------------------------------------------------------------------------------------------*
//  Function implementation                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

static bool gOnceFunctionResultAvailable_endc = false ;
static GALGAS_string gOnceFunctionResult_endc ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_endc (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_endc) {
    gOnceFunctionResult_endc = onceFunction_endc (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_endc = true ;
  }
  return gOnceFunctionResult_endc ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void releaseOnceFunctionResult_endc (void) {
  gOnceFunctionResult_endc.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gEpilogueForOnceFunction_endc (NULL,
                                                  releaseOnceFunctionResult_endc) ;

//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_endc [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_endc (C_Compiler * inCompiler,
                                                     const cObjectArray & /* inEffectiveParameterArray */,
                                                     const GALGAS_location & /* inErrorLocation */
                                                     COMMA_LOCATION_ARGS) {
  return function_endc (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_endc ("endc",
                                                      functionWithGenericHeader_endc,
                                                      & kTypeDescriptor_GALGAS_string,
                                                      0,
                                                      functionArgs_endc) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Function 'defaultDebugSettings'                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_debuggerContext function_defaultDebugSettings (C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_debuggerContext result_debugSettings ; // Returned variable
  result_debugSettings = GALGAS_debuggerContext::constructor_new (GALGAS_bool (gOption_gtl_5F_options_debug.getter_value ()), GALGAS_bool (gOption_gtl_5F_options_debug.getter_value ()), GALGAS_bool (false), function_red (inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 136)), GALGAS_string::makeEmptyString (), function_blue (inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 138)), function_bold (inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 139)), function_darkgreen (inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 140)), GALGAS_string::makeEmptyString (), function_darkyellow (inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 142)), function_bold (inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 143)), GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_debugger.galgas", 144))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 132)) ;
//---
  return result_debugSettings ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_defaultDebugSettings [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_defaultDebugSettings (C_Compiler * inCompiler,
                                                                     const cObjectArray & /* inEffectiveParameterArray */,
                                                                     const GALGAS_location & /* inErrorLocation */
                                                                     COMMA_LOCATION_ARGS) {
  return function_defaultDebugSettings (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_defaultDebugSettings ("defaultDebugSettings",
                                                                      functionWithGenericHeader_defaultDebugSettings,
                                                                      & kTypeDescriptor_GALGAS_debuggerContext,
                                                                      0,
                                                                      functionArgs_defaultDebugSettings) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               Bool options                                                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

C_BoolCommandLineOption gOption_goil_5F_options_generate_5F_log ("goil_options",
                                         "generate_log",
                                         108,
                                         "logfile",
                                         "generate a goil.log file containing the a log of the compilation") ;

C_BoolCommandLineOption gOption_goil_5F_options_pierreOption ("goil_options",
                                         "pierreOption",
                                         0,
                                         "pierre",
                                         "Special option to pass a galgas bug to Pierre") ;

C_BoolCommandLineOption gOption_goil_5F_options_warnMultiple ("goil_options",
                                         "warnMultiple",
                                         0,
                                         "warn-multiple",
                                         "Emit a warning if an object not defined for the first time in the implementation does not have the same multiple attribute as in the first definition") ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               UInt options                                                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              String options                                                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

C_StringCommandLineOption gOption_goil_5F_options_config ("goil_options",
                                         "config",
                                         99,
                                         "config",
                                         "Specifies the OIL config file used by goil",
                                         "config") ;

C_StringCommandLineOption gOption_goil_5F_options_passOption ("goil_options",
                                         "passOption",
                                         111,
                                         "option",
                                         "Pass options to the template root script",
                                         "") ;

C_StringCommandLineOption gOption_goil_5F_options_project_5F_dir ("goil_options",
                                         "project_dir",
                                         112,
                                         "project",
                                         "Specifies project directory (by default, the project directory is the name of the oil file, without the .oil extension)",
                                         "") ;

C_StringCommandLineOption gOption_goil_5F_options_root ("goil_options",
                                         "root",
                                         114,
                                         "root",
                                         "Specifies the root template file to use to generate the output files",
                                         "root") ;

C_StringCommandLineOption gOption_goil_5F_options_target_5F_platform ("goil_options",
                                         "target_platform",
                                         116,
                                         "target",
                                         "Specifies target platform. Available target platform are located in machines/ directory. Targets are specified using a path like avr/arduino.",
                                         "") ;

C_StringCommandLineOption gOption_goil_5F_options_template_5F_dir ("goil_options",
                                         "template_dir",
                                         0,
                                         "templates",
                                         "Specifies template directory (used by goil for code generation)",
                                         "") ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              String List options                                                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

//---------------------------------------------------------------------------------------------------------------------*


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                Function 'checkEnums'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool function_checkEnums (const GALGAS_impEnumType & constinArgument_previousEnum,
                                 const GALGAS_impEnumType & constinArgument_newEnum,
                                 C_Compiler * inCompiler
                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_inside ; // Returned variable
  GALGAS_stringset var_newValues_15823 = constinArgument_newEnum.getter_valuesMap (SOURCE_FILE ("implementation_parser.galgas", 596)).getter_keySet (SOURCE_FILE ("implementation_parser.galgas", 596)) ;
  GALGAS_stringset var_previousValues_15882 = constinArgument_previousEnum.getter_valuesMap (SOURCE_FILE ("implementation_parser.galgas", 597)).getter_keySet (SOURCE_FILE ("implementation_parser.galgas", 597)) ;
  result_inside = GALGAS_bool (kIsEqual, var_newValues_15823.operator_and (var_previousValues_15882 COMMA_SOURCE_FILE ("implementation_parser.galgas", 598)).objectCompare (var_newValues_15823)) ;
  const enumGalgasBool test_0 = result_inside.operator_not (SOURCE_FILE ("implementation_parser.galgas", 599)).boolEnum () ;
  if (kBoolTrue == test_0) {
    cEnumerator_locationList enumerator_16026 (constinArgument_newEnum.getter_locations (SOURCE_FILE ("implementation_parser.galgas", 600)), kEnumeration_up) ;
    while (enumerator_16026.hasCurrentObject ()) {
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (enumerator_16026.current_location (HERE), GALGAS_string ("ENUM is not within previous enum declaration"), fixItArray1  COMMA_SOURCE_FILE ("implementation_parser.galgas", 601)) ;
      enumerator_16026.gotoNextObject () ;
    }
    cEnumerator_locationList enumerator_16145 (constinArgument_previousEnum.getter_locations (SOURCE_FILE ("implementation_parser.galgas", 603)), kEnumeration_up) ;
    while (enumerator_16145.hasCurrentObject ()) {
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (enumerator_16145.current_location (HERE), GALGAS_string ("previous ENUM declaration was here"), fixItArray2  COMMA_SOURCE_FILE ("implementation_parser.galgas", 604)) ;
      enumerator_16145.gotoNextObject () ;
    }
  }
//---
  return result_inside ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_checkEnums [3] = {
  & kTypeDescriptor_GALGAS_impEnumType,
  & kTypeDescriptor_GALGAS_impEnumType,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_checkEnums (C_Compiler * inCompiler,
                                                           const cObjectArray & inEffectiveParameterArray,
                                                           const GALGAS_location & /* inErrorLocation */
                                                           COMMA_LOCATION_ARGS) {
  const GALGAS_impEnumType operand0 = GALGAS_impEnumType::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  const GALGAS_impEnumType operand1 = GALGAS_impEnumType::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  return function_checkEnums (operand0,
                              operand1,
                              inCompiler
                              COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_checkEnums ("checkEnums",
                                                            functionWithGenericHeader_checkEnums,
                                                            & kTypeDescriptor_GALGAS_bool,
                                                            2,
                                                            functionArgs_checkEnums) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Function 'checkRanged'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool function_checkRanged (const GALGAS_impRangedType & constinArgument_previousRanged,
                                  const GALGAS_impRangedType & constinArgument_newRanged,
                                  C_Compiler * inCompiler
                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_inside ; // Returned variable
  callExtensionMethod_enclose ((const cPtr_attributeRange *) constinArgument_previousRanged.getter_setOrRange (SOURCE_FILE ("implementation_parser.galgas", 617)).ptr (), result_inside, constinArgument_newRanged.getter_setOrRange (SOURCE_FILE ("implementation_parser.galgas", 617)), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 617)) ;
  const enumGalgasBool test_0 = result_inside.operator_not (SOURCE_FILE ("implementation_parser.galgas", 618)).boolEnum () ;
  if (kBoolTrue == test_0) {
    cEnumerator_locationList enumerator_16508 (constinArgument_newRanged.getter_locations (SOURCE_FILE ("implementation_parser.galgas", 619)), kEnumeration_up) ;
    while (enumerator_16508.hasCurrentObject ()) {
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (enumerator_16508.current_location (HERE), GALGAS_string ("new range or set is not within previous range or set declaration"), fixItArray1  COMMA_SOURCE_FILE ("implementation_parser.galgas", 620)) ;
      enumerator_16508.gotoNextObject () ;
    }
    cEnumerator_locationList enumerator_16649 (constinArgument_previousRanged.getter_locations (SOURCE_FILE ("implementation_parser.galgas", 622)), kEnumeration_up) ;
    while (enumerator_16649.hasCurrentObject ()) {
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (enumerator_16649.current_location (HERE), GALGAS_string ("previous range or set declaration was here"), fixItArray2  COMMA_SOURCE_FILE ("implementation_parser.galgas", 623)) ;
      enumerator_16649.gotoNextObject () ;
    }
  }
//---
  return result_inside ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_checkRanged [3] = {
  & kTypeDescriptor_GALGAS_impRangedType,
  & kTypeDescriptor_GALGAS_impRangedType,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_checkRanged (C_Compiler * inCompiler,
                                                            const cObjectArray & inEffectiveParameterArray,
                                                            const GALGAS_location & /* inErrorLocation */
                                                            COMMA_LOCATION_ARGS) {
  const GALGAS_impRangedType operand0 = GALGAS_impRangedType::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                             inCompiler
                                                                             COMMA_THERE) ;
  const GALGAS_impRangedType operand1 = GALGAS_impRangedType::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                                             inCompiler
                                                                             COMMA_THERE) ;
  return function_checkRanged (operand0,
                               operand1,
                               inCompiler
                               COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_checkRanged ("checkRanged",
                                                             functionWithGenericHeader_checkRanged,
                                                             & kTypeDescriptor_GALGAS_bool,
                                                             2,
                                                             functionArgs_checkRanged) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Function 'checkNewTypeWithinPreviousType'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool function_checkNewTypeWithinPreviousType (const GALGAS_lstring & constinArgument_name,
                                                     const GALGAS_impType & constinArgument_previousType,
                                                     const GALGAS_impType & constinArgument_newType,
                                                     C_Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_result ; // Returned variable
  result_result = GALGAS_bool (false) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, constinArgument_newType.getter_type (SOURCE_FILE ("implementation_parser.galgas", 634)).objectCompare (constinArgument_previousType.getter_type (SOURCE_FILE ("implementation_parser.galgas", 634)))).boolEnum () ;
  if (kBoolTrue == test_0) {
    cEnumerator_locationList enumerator_16964 (constinArgument_newType.getter_locations (SOURCE_FILE ("implementation_parser.galgas", 635)), kEnumeration_up) ;
    while (enumerator_16964.hasCurrentObject ()) {
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (enumerator_16964.current_location (HERE), constinArgument_name.getter_string (SOURCE_FILE ("implementation_parser.galgas", 636)).add_operation (GALGAS_string (" should be a "), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 636)).add_operation (extensionGetter_oilType (constinArgument_previousType.getter_type (SOURCE_FILE ("implementation_parser.galgas", 636)), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 636)), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 636)), fixItArray1  COMMA_SOURCE_FILE ("implementation_parser.galgas", 636)) ;
      enumerator_16964.gotoNextObject () ;
    }
    cEnumerator_locationList enumerator_17096 (constinArgument_previousType.getter_locations (SOURCE_FILE ("implementation_parser.galgas", 638)), kEnumeration_up) ;
    while (enumerator_17096.hasCurrentObject ()) {
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (enumerator_17096.current_location (HERE), constinArgument_name.getter_string (SOURCE_FILE ("implementation_parser.galgas", 639)).add_operation (GALGAS_string (" was previouly defined here"), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 639)), fixItArray2  COMMA_SOURCE_FILE ("implementation_parser.galgas", 639)) ;
      enumerator_17096.gotoNextObject () ;
    }
    result_result = GALGAS_bool (false) ;
  }else if (kBoolFalse == test_0) {
    if (constinArgument_previousType.isValid ()) {
      if (constinArgument_previousType.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_impEnumType) {
        GALGAS_impEnumType cast_17259_previousEnum ((cPtr_impEnumType *) constinArgument_previousType.ptr ()) ;
        if (constinArgument_newType.isValid ()) {
          if (constinArgument_newType.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_impEnumType) {
            GALGAS_impEnumType cast_17315_newEnum ((cPtr_impEnumType *) constinArgument_newType.ptr ()) ;
            result_result = function_checkEnums (cast_17259_previousEnum, cast_17315_newEnum, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 647)) ;
          }
        }
      }else if (constinArgument_previousType.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_impRangedType) {
        GALGAS_impRangedType cast_17426_previousRanged ((cPtr_impRangedType *) constinArgument_previousType.ptr ()) ;
        if (constinArgument_newType.isValid ()) {
          if (constinArgument_newType.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_impRangedType) {
            GALGAS_impRangedType cast_17486_newRanged ((cPtr_impRangedType *) constinArgument_newType.ptr ()) ;
            result_result = function_checkRanged (cast_17426_previousRanged, cast_17486_newRanged, inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 652)) ;
          }
        }
      }else{
        result_result = GALGAS_bool (true) ;
      }
    }
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_checkNewTypeWithinPreviousType [4] = {
  & kTypeDescriptor_GALGAS_lstring,
  & kTypeDescriptor_GALGAS_impType,
  & kTypeDescriptor_GALGAS_impType,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_checkNewTypeWithinPreviousType (C_Compiler * inCompiler,
                                                                               const cObjectArray & inEffectiveParameterArray,
                                                                               const GALGAS_location & /* inErrorLocation */
                                                                               COMMA_LOCATION_ARGS) {
  const GALGAS_lstring operand0 = GALGAS_lstring::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  const GALGAS_impType operand1 = GALGAS_impType::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  const GALGAS_impType operand2 = GALGAS_impType::extractObject (inEffectiveParameterArray.objectAtIndex (2 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  return function_checkNewTypeWithinPreviousType (operand0,
                                                  operand1,
                                                  operand2,
                                                  inCompiler
                                                  COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_checkNewTypeWithinPreviousType ("checkNewTypeWithinPreviousType",
                                                                                functionWithGenericHeader_checkNewTypeWithinPreviousType,
                                                                                & kTypeDescriptor_GALGAS_bool,
                                                                                3,
                                                                                functionArgs_checkNewTypeWithinPreviousType) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                Function 'buildRange'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_attributeRange function_buildRange (const GALGAS_dataType & constinArgument_type,
                                           const GALGAS_object_5F_t & constinArgument_start,
                                           const GALGAS_object_5F_t & constinArgument_stop,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_attributeRange result_range ; // Returned variable
  const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_uint_33__32_Number (SOURCE_FILE ("implementation_parser.galgas", 665)))).boolEnum () ;
  if (kBoolTrue == test_0) {
    result_range = GALGAS_uint_33__32_AttributeMinMax::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 666)), function_uint_33__32_OrError (constinArgument_start, GALGAS_string ("UINT32 Range start"), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 666)), function_uint_33__32_OrError (constinArgument_stop, GALGAS_string ("UINT32 Range stop"), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 666))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 666)) ;
  }else if (kBoolFalse == test_0) {
    const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_sint_33__32_Number (SOURCE_FILE ("implementation_parser.galgas", 667)))).boolEnum () ;
    if (kBoolTrue == test_1) {
      result_range = GALGAS_sint_33__32_AttributeMinMax::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 668)), function_sint_33__32_OrError (constinArgument_start, GALGAS_string ("SINT32 Range start"), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 668)), function_sint_33__32_OrError (constinArgument_stop, GALGAS_string ("SINT32 Range stop"), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 668))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 668)) ;
    }else if (kBoolFalse == test_1) {
      const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_parser.galgas", 669)))).boolEnum () ;
      if (kBoolTrue == test_2) {
        result_range = GALGAS_uint_36__34_AttributeMinMax::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 670)), function_uint_36__34_OrError (constinArgument_start, GALGAS_string ("UINT64 Range start"), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 670)), function_uint_36__34_OrError (constinArgument_stop, GALGAS_string ("UINT64 Range stop"), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 670))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 670)) ;
      }else if (kBoolFalse == test_2) {
        const enumGalgasBool test_3 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_sint_36__34_Number (SOURCE_FILE ("implementation_parser.galgas", 671)))).boolEnum () ;
        if (kBoolTrue == test_3) {
          result_range = GALGAS_sint_36__34_AttributeMinMax::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 672)), function_sint_36__34_OrError (constinArgument_start, GALGAS_string ("SINT64 Range start"), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 672)), function_sint_36__34_OrError (constinArgument_stop, GALGAS_string ("SINT64 Range stop"), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 672))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 672)) ;
        }else if (kBoolFalse == test_3) {
          const enumGalgasBool test_4 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_floatNumber (SOURCE_FILE ("implementation_parser.galgas", 673)))).boolEnum () ;
          if (kBoolTrue == test_4) {
            result_range = GALGAS_floatAttributeMinMax::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 674)), function_floatOrError (constinArgument_start, GALGAS_string ("FLOAT Range start"), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 674)), function_floatOrError (constinArgument_stop, GALGAS_string ("FLOAT Range stop"), inCompiler COMMA_SOURCE_FILE ("implementation_parser.galgas", 674))  COMMA_SOURCE_FILE ("implementation_parser.galgas", 674)) ;
          }else if (kBoolFalse == test_4) {
            TC_Array <C_FixItDescription> fixItArray5 ;
            inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_parser.galgas", 676)), GALGAS_string ("internal. Unknown number type"), fixItArray5  COMMA_SOURCE_FILE ("implementation_parser.galgas", 676)) ;
            result_range.drop () ; // Release error dropped variable
          }
        }
      }
    }
  }
//---
  return result_range ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_buildRange [4] = {
  & kTypeDescriptor_GALGAS_dataType,
  & kTypeDescriptor_GALGAS_object_5F_t,
  & kTypeDescriptor_GALGAS_object_5F_t,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_buildRange (C_Compiler * inCompiler,
                                                           const cObjectArray & inEffectiveParameterArray,
                                                           const GALGAS_location & /* inErrorLocation */
                                                           COMMA_LOCATION_ARGS) {
  const GALGAS_dataType operand0 = GALGAS_dataType::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                   inCompiler
                                                                   COMMA_THERE) ;
  const GALGAS_object_5F_t operand1 = GALGAS_object_5F_t::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  const GALGAS_object_5F_t operand2 = GALGAS_object_5F_t::extractObject (inEffectiveParameterArray.objectAtIndex (2 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  return function_buildRange (operand0,
                              operand1,
                              operand2,
                              inCompiler
                              COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_buildRange ("buildRange",
                                                            functionWithGenericHeader_buildRange,
                                                            & kTypeDescriptor_GALGAS_attributeRange,
                                                            3,
                                                            functionArgs_buildRange) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Function 'stringWithUInt32List'                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_stringWithUInt_33__32_List (const GALGAS_uint_33__32_List & constinArgument_values,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::makeEmptyString () ;
  cEnumerator_uint_33__32_List enumerator_1878 (constinArgument_values, kEnumeration_up) ;
  while (enumerator_1878.hasCurrentObject ()) {
    result_result.plusAssign_operation(enumerator_1878.current_value (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 68)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 68)) ;
    if (enumerator_1878.hasNextObject ()) {
      result_result.plusAssign_operation(GALGAS_string (", "), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 68)) ;
    }
    enumerator_1878.gotoNextObject () ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_stringWithUInt_33__32_List [2] = {
  & kTypeDescriptor_GALGAS_uint_33__32_List,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_stringWithUInt_33__32_List (C_Compiler * inCompiler,
                                                                           const cObjectArray & inEffectiveParameterArray,
                                                                           const GALGAS_location & /* inErrorLocation */
                                                                           COMMA_LOCATION_ARGS) {
  const GALGAS_uint_33__32_List operand0 = GALGAS_uint_33__32_List::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                                   inCompiler
                                                                                   COMMA_THERE) ;
  return function_stringWithUInt_33__32_List (operand0,
                                              inCompiler
                                              COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_stringWithUInt_33__32_List ("stringWithUInt32List",
                                                                            functionWithGenericHeader_stringWithUInt_33__32_List,
                                                                            & kTypeDescriptor_GALGAS_string,
                                                                            1,
                                                                            functionArgs_stringWithUInt_33__32_List) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Function 'stringWithUInt64List'                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_stringWithUInt_36__34_List (const GALGAS_uint_36__34_List & constinArgument_values,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::makeEmptyString () ;
  cEnumerator_uint_36__34_List enumerator_2040 (constinArgument_values, kEnumeration_up) ;
  while (enumerator_2040.hasCurrentObject ()) {
    result_result.plusAssign_operation(enumerator_2040.current_value (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 73)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 73)) ;
    if (enumerator_2040.hasNextObject ()) {
      result_result.plusAssign_operation(GALGAS_string (", "), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 73)) ;
    }
    enumerator_2040.gotoNextObject () ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_stringWithUInt_36__34_List [2] = {
  & kTypeDescriptor_GALGAS_uint_36__34_List,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_stringWithUInt_36__34_List (C_Compiler * inCompiler,
                                                                           const cObjectArray & inEffectiveParameterArray,
                                                                           const GALGAS_location & /* inErrorLocation */
                                                                           COMMA_LOCATION_ARGS) {
  const GALGAS_uint_36__34_List operand0 = GALGAS_uint_36__34_List::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                                   inCompiler
                                                                                   COMMA_THERE) ;
  return function_stringWithUInt_36__34_List (operand0,
                                              inCompiler
                                              COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_stringWithUInt_36__34_List ("stringWithUInt64List",
                                                                            functionWithGenericHeader_stringWithUInt_36__34_List,
                                                                            & kTypeDescriptor_GALGAS_string,
                                                                            1,
                                                                            functionArgs_stringWithUInt_36__34_List) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Function 'stringWithSInt32List'                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_stringWithSInt_33__32_List (const GALGAS_sint_33__32_List & constinArgument_values,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::makeEmptyString () ;
  cEnumerator_sint_33__32_List enumerator_2202 (constinArgument_values, kEnumeration_up) ;
  while (enumerator_2202.hasCurrentObject ()) {
    result_result.plusAssign_operation(enumerator_2202.current_value (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 78)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 78)) ;
    if (enumerator_2202.hasNextObject ()) {
      result_result.plusAssign_operation(GALGAS_string (", "), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 78)) ;
    }
    enumerator_2202.gotoNextObject () ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_stringWithSInt_33__32_List [2] = {
  & kTypeDescriptor_GALGAS_sint_33__32_List,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_stringWithSInt_33__32_List (C_Compiler * inCompiler,
                                                                           const cObjectArray & inEffectiveParameterArray,
                                                                           const GALGAS_location & /* inErrorLocation */
                                                                           COMMA_LOCATION_ARGS) {
  const GALGAS_sint_33__32_List operand0 = GALGAS_sint_33__32_List::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                                   inCompiler
                                                                                   COMMA_THERE) ;
  return function_stringWithSInt_33__32_List (operand0,
                                              inCompiler
                                              COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_stringWithSInt_33__32_List ("stringWithSInt32List",
                                                                            functionWithGenericHeader_stringWithSInt_33__32_List,
                                                                            & kTypeDescriptor_GALGAS_string,
                                                                            1,
                                                                            functionArgs_stringWithSInt_33__32_List) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Function 'stringWithSInt64List'                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_stringWithSInt_36__34_List (const GALGAS_sint_36__34_List & constinArgument_values,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::makeEmptyString () ;
  cEnumerator_sint_36__34_List enumerator_2364 (constinArgument_values, kEnumeration_up) ;
  while (enumerator_2364.hasCurrentObject ()) {
    result_result.plusAssign_operation(enumerator_2364.current_value (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 83)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 83)) ;
    if (enumerator_2364.hasNextObject ()) {
      result_result.plusAssign_operation(GALGAS_string (", "), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 83)) ;
    }
    enumerator_2364.gotoNextObject () ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_stringWithSInt_36__34_List [2] = {
  & kTypeDescriptor_GALGAS_sint_36__34_List,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_stringWithSInt_36__34_List (C_Compiler * inCompiler,
                                                                           const cObjectArray & inEffectiveParameterArray,
                                                                           const GALGAS_location & /* inErrorLocation */
                                                                           COMMA_LOCATION_ARGS) {
  const GALGAS_sint_36__34_List operand0 = GALGAS_sint_36__34_List::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                                   inCompiler
                                                                                   COMMA_THERE) ;
  return function_stringWithSInt_36__34_List (operand0,
                                              inCompiler
                                              COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_stringWithSInt_36__34_List ("stringWithSInt64List",
                                                                            functionWithGenericHeader_stringWithSInt_36__34_List,
                                                                            & kTypeDescriptor_GALGAS_string,
                                                                            1,
                                                                            functionArgs_stringWithSInt_36__34_List) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Function 'stringWithFloatList'                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_stringWithFloatList (const GALGAS_floatList & constinArgument_values,
                                            C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::makeEmptyString () ;
  cEnumerator_floatList enumerator_2524 (constinArgument_values, kEnumeration_up) ;
  while (enumerator_2524.hasCurrentObject ()) {
    result_result.plusAssign_operation(enumerator_2524.current_value (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 88)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 88)) ;
    if (enumerator_2524.hasNextObject ()) {
      result_result.plusAssign_operation(GALGAS_string (", "), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 88)) ;
    }
    enumerator_2524.gotoNextObject () ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_stringWithFloatList [2] = {
  & kTypeDescriptor_GALGAS_floatList,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_stringWithFloatList (C_Compiler * inCompiler,
                                                                    const cObjectArray & inEffectiveParameterArray,
                                                                    const GALGAS_location & /* inErrorLocation */
                                                                    COMMA_LOCATION_ARGS) {
  const GALGAS_floatList operand0 = GALGAS_floatList::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                     inCompiler
                                                                     COMMA_THERE) ;
  return function_stringWithFloatList (operand0,
                                       inCompiler
                                       COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_stringWithFloatList ("stringWithFloatList",
                                                                     functionWithGenericHeader_stringWithFloatList,
                                                                     & kTypeDescriptor_GALGAS_string,
                                                                     1,
                                                                     functionArgs_stringWithFloatList) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         Function 'uint32ListWithNumberList'                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_33__32_List function_uint_33__32_ListWithNumberList (const GALGAS_numberList & constinArgument_numbers,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_uint_33__32_List result_result ; // Returned variable
  result_result = GALGAS_uint_33__32_List::constructor_emptyList (SOURCE_FILE ("implementation_types.galgas", 92)) ;
  cEnumerator_numberList enumerator_2716 (constinArgument_numbers, kEnumeration_up) ;
  while (enumerator_2716.hasCurrentObject ()) {
    result_result.addAssign_operation (enumerator_2716.current_location (HERE), function_uint_33__32_OrError (enumerator_2716.current_value (HERE), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 94))  COMMA_SOURCE_FILE ("implementation_types.galgas", 94)) ;
    enumerator_2716.gotoNextObject () ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_uint_33__32_ListWithNumberList [2] = {
  & kTypeDescriptor_GALGAS_numberList,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_uint_33__32_ListWithNumberList (C_Compiler * inCompiler,
                                                                               const cObjectArray & inEffectiveParameterArray,
                                                                               const GALGAS_location & /* inErrorLocation */
                                                                               COMMA_LOCATION_ARGS) {
  const GALGAS_numberList operand0 = GALGAS_numberList::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                       inCompiler
                                                                       COMMA_THERE) ;
  return function_uint_33__32_ListWithNumberList (operand0,
                                                  inCompiler
                                                  COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_uint_33__32_ListWithNumberList ("uint32ListWithNumberList",
                                                                                functionWithGenericHeader_uint_33__32_ListWithNumberList,
                                                                                & kTypeDescriptor_GALGAS_uint_33__32_List,
                                                                                1,
                                                                                functionArgs_uint_33__32_ListWithNumberList) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         Function 'sint32ListWithNumberList'                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_33__32_List function_sint_33__32_ListWithNumberList (const GALGAS_numberList & constinArgument_numbers,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_sint_33__32_List result_result ; // Returned variable
  result_result = GALGAS_sint_33__32_List::constructor_emptyList (SOURCE_FILE ("implementation_types.galgas", 99)) ;
  cEnumerator_numberList enumerator_2914 (constinArgument_numbers, kEnumeration_up) ;
  while (enumerator_2914.hasCurrentObject ()) {
    result_result.addAssign_operation (enumerator_2914.current_location (HERE), function_sint_33__32_OrError (enumerator_2914.current_value (HERE), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 101))  COMMA_SOURCE_FILE ("implementation_types.galgas", 101)) ;
    enumerator_2914.gotoNextObject () ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_sint_33__32_ListWithNumberList [2] = {
  & kTypeDescriptor_GALGAS_numberList,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_sint_33__32_ListWithNumberList (C_Compiler * inCompiler,
                                                                               const cObjectArray & inEffectiveParameterArray,
                                                                               const GALGAS_location & /* inErrorLocation */
                                                                               COMMA_LOCATION_ARGS) {
  const GALGAS_numberList operand0 = GALGAS_numberList::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                       inCompiler
                                                                       COMMA_THERE) ;
  return function_sint_33__32_ListWithNumberList (operand0,
                                                  inCompiler
                                                  COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_sint_33__32_ListWithNumberList ("sint32ListWithNumberList",
                                                                                functionWithGenericHeader_sint_33__32_ListWithNumberList,
                                                                                & kTypeDescriptor_GALGAS_sint_33__32_List,
                                                                                1,
                                                                                functionArgs_sint_33__32_ListWithNumberList) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         Function 'uint64ListWithNumberList'                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_List function_uint_36__34_ListWithNumberList (const GALGAS_numberList & constinArgument_numbers,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_uint_36__34_List result_result ; // Returned variable
  result_result = GALGAS_uint_36__34_List::constructor_emptyList (SOURCE_FILE ("implementation_types.galgas", 106)) ;
  cEnumerator_numberList enumerator_3112 (constinArgument_numbers, kEnumeration_up) ;
  while (enumerator_3112.hasCurrentObject ()) {
    result_result.addAssign_operation (enumerator_3112.current_location (HERE), function_uint_36__34_OrError (enumerator_3112.current_value (HERE), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 108))  COMMA_SOURCE_FILE ("implementation_types.galgas", 108)) ;
    enumerator_3112.gotoNextObject () ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_uint_36__34_ListWithNumberList [2] = {
  & kTypeDescriptor_GALGAS_numberList,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_uint_36__34_ListWithNumberList (C_Compiler * inCompiler,
                                                                               const cObjectArray & inEffectiveParameterArray,
                                                                               const GALGAS_location & /* inErrorLocation */
                                                                               COMMA_LOCATION_ARGS) {
  const GALGAS_numberList operand0 = GALGAS_numberList::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                       inCompiler
                                                                       COMMA_THERE) ;
  return function_uint_36__34_ListWithNumberList (operand0,
                                                  inCompiler
                                                  COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_uint_36__34_ListWithNumberList ("uint64ListWithNumberList",
                                                                                functionWithGenericHeader_uint_36__34_ListWithNumberList,
                                                                                & kTypeDescriptor_GALGAS_uint_36__34_List,
                                                                                1,
                                                                                functionArgs_uint_36__34_ListWithNumberList) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         Function 'sint64ListWithNumberList'                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_List function_sint_36__34_ListWithNumberList (const GALGAS_numberList & constinArgument_numbers,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_sint_36__34_List result_result ; // Returned variable
  result_result = GALGAS_sint_36__34_List::constructor_emptyList (SOURCE_FILE ("implementation_types.galgas", 113)) ;
  cEnumerator_numberList enumerator_3310 (constinArgument_numbers, kEnumeration_up) ;
  while (enumerator_3310.hasCurrentObject ()) {
    result_result.addAssign_operation (enumerator_3310.current_location (HERE), function_sint_36__34_OrError (enumerator_3310.current_value (HERE), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 115))  COMMA_SOURCE_FILE ("implementation_types.galgas", 115)) ;
    enumerator_3310.gotoNextObject () ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_sint_36__34_ListWithNumberList [2] = {
  & kTypeDescriptor_GALGAS_numberList,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_sint_36__34_ListWithNumberList (C_Compiler * inCompiler,
                                                                               const cObjectArray & inEffectiveParameterArray,
                                                                               const GALGAS_location & /* inErrorLocation */
                                                                               COMMA_LOCATION_ARGS) {
  const GALGAS_numberList operand0 = GALGAS_numberList::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                       inCompiler
                                                                       COMMA_THERE) ;
  return function_sint_36__34_ListWithNumberList (operand0,
                                                  inCompiler
                                                  COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_sint_36__34_ListWithNumberList ("sint64ListWithNumberList",
                                                                                functionWithGenericHeader_sint_36__34_ListWithNumberList,
                                                                                & kTypeDescriptor_GALGAS_sint_36__34_List,
                                                                                1,
                                                                                functionArgs_sint_36__34_ListWithNumberList) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         Function 'floatListWithNumberList'                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_floatList function_floatListWithNumberList (const GALGAS_numberList & constinArgument_numbers,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_floatList result_result ; // Returned variable
  result_result = GALGAS_floatList::constructor_emptyList (SOURCE_FILE ("implementation_types.galgas", 120)) ;
  cEnumerator_numberList enumerator_3505 (constinArgument_numbers, kEnumeration_up) ;
  while (enumerator_3505.hasCurrentObject ()) {
    result_result.addAssign_operation (enumerator_3505.current_location (HERE), function_floatOrError (enumerator_3505.current_value (HERE), GALGAS_string::makeEmptyString (), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 122))  COMMA_SOURCE_FILE ("implementation_types.galgas", 122)) ;
    enumerator_3505.gotoNextObject () ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_floatListWithNumberList [2] = {
  & kTypeDescriptor_GALGAS_numberList,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_floatListWithNumberList (C_Compiler * inCompiler,
                                                                        const cObjectArray & inEffectiveParameterArray,
                                                                        const GALGAS_location & /* inErrorLocation */
                                                                        COMMA_LOCATION_ARGS) {
  const GALGAS_numberList operand0 = GALGAS_numberList::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                       inCompiler
                                                                       COMMA_THERE) ;
  return function_floatListWithNumberList (operand0,
                                           inCompiler
                                           COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_floatListWithNumberList ("floatListWithNumberList",
                                                                         functionWithGenericHeader_floatListWithNumberList,
                                                                         & kTypeDescriptor_GALGAS_floatList,
                                                                         1,
                                                                         functionArgs_floatListWithNumberList) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Function 'attributeRangeWithNumberList'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_attributeRange function_attributeRangeWithNumberList (const GALGAS_numberList & constinArgument_numbers,
                                                             const GALGAS_dataType & constinArgument_type,
                                                             C_Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_attributeRange result_range ; // Returned variable
  const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_uint_33__32_Number (SOURCE_FILE ("implementation_types.galgas", 397)))).boolEnum () ;
  if (kBoolTrue == test_0) {
    result_range = GALGAS_uint_33__32_AttributeSet::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 398)), function_uint_33__32_ListWithNumberList (constinArgument_numbers, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 398))  COMMA_SOURCE_FILE ("implementation_types.galgas", 398)) ;
  }else if (kBoolFalse == test_0) {
    const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_sint_33__32_Number (SOURCE_FILE ("implementation_types.galgas", 399)))).boolEnum () ;
    if (kBoolTrue == test_1) {
      result_range = GALGAS_sint_33__32_AttributeSet::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 400)), function_sint_33__32_ListWithNumberList (constinArgument_numbers, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 400))  COMMA_SOURCE_FILE ("implementation_types.galgas", 400)) ;
    }else if (kBoolFalse == test_1) {
      const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 401)))).boolEnum () ;
      if (kBoolTrue == test_2) {
        result_range = GALGAS_uint_36__34_AttributeSet::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 402)), function_uint_36__34_ListWithNumberList (constinArgument_numbers, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 402))  COMMA_SOURCE_FILE ("implementation_types.galgas", 402)) ;
      }else if (kBoolFalse == test_2) {
        const enumGalgasBool test_3 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_sint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 403)))).boolEnum () ;
        if (kBoolTrue == test_3) {
          result_range = GALGAS_sint_36__34_AttributeSet::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 404)), function_sint_36__34_ListWithNumberList (constinArgument_numbers, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 404))  COMMA_SOURCE_FILE ("implementation_types.galgas", 404)) ;
        }else if (kBoolFalse == test_3) {
          const enumGalgasBool test_4 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_floatNumber (SOURCE_FILE ("implementation_types.galgas", 405)))).boolEnum () ;
          if (kBoolTrue == test_4) {
            result_range = GALGAS_floatAttributeSet::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 406)), function_floatListWithNumberList (constinArgument_numbers, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 406))  COMMA_SOURCE_FILE ("implementation_types.galgas", 406)) ;
          }else if (kBoolFalse == test_4) {
            TC_Array <C_FixItDescription> fixItArray5 ;
            inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 408)), GALGAS_string ("internal. Unknown number type"), fixItArray5  COMMA_SOURCE_FILE ("implementation_types.galgas", 408)) ;
            result_range.drop () ; // Release error dropped variable
          }
        }
      }
    }
  }
//---
  return result_range ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_attributeRangeWithNumberList [3] = {
  & kTypeDescriptor_GALGAS_numberList,
  & kTypeDescriptor_GALGAS_dataType,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_attributeRangeWithNumberList (C_Compiler * inCompiler,
                                                                             const cObjectArray & inEffectiveParameterArray,
                                                                             const GALGAS_location & /* inErrorLocation */
                                                                             COMMA_LOCATION_ARGS) {
  const GALGAS_numberList operand0 = GALGAS_numberList::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                       inCompiler
                                                                       COMMA_THERE) ;
  const GALGAS_dataType operand1 = GALGAS_dataType::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                                   inCompiler
                                                                   COMMA_THERE) ;
  return function_attributeRangeWithNumberList (operand0,
                                                operand1,
                                                inCompiler
                                                COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_attributeRangeWithNumberList ("attributeRangeWithNumberList",
                                                                              functionWithGenericHeader_attributeRangeWithNumberList,
                                                                              & kTypeDescriptor_GALGAS_attributeRange,
                                                                              2,
                                                                              functionArgs_attributeRangeWithNumberList) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                Routine 'multiError'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_multiError (GALGAS_locationList inArgument_locations,
                         GALGAS_string inArgument_errorMessage,
                         C_Compiler * inCompiler
                         COMMA_UNUSED_LOCATION_ARGS) {
  cEnumerator_locationList enumerator_13729 (inArgument_locations, kEnumeration_up) ;
  while (enumerator_13729.hasCurrentObject ()) {
    TC_Array <C_FixItDescription> fixItArray0 ;
    inCompiler->emitSemanticError (enumerator_13729.current_location (HERE), inArgument_errorMessage, fixItArray0  COMMA_SOURCE_FILE ("implementation_types.galgas", 508)) ;
    enumerator_13729.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                Function 'valueList'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_valueList (const GALGAS_enumValues & constinArgument_values,
                                  C_Compiler * inCompiler
                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::makeEmptyString () ;
  cEnumerator_enumValues enumerator_15054 (constinArgument_values, kEnumeration_up) ;
  while (enumerator_15054.hasCurrentObject ()) {
    result_result.plusAssign_operation(enumerator_15054.current_lkey (HERE).getter_string (SOURCE_FILE ("implementation_types.galgas", 562)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 562)) ;
    if (enumerator_15054.hasNextObject ()) {
      result_result.plusAssign_operation(GALGAS_string (", "), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 564)) ;
    }
    enumerator_15054.gotoNextObject () ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_valueList [2] = {
  & kTypeDescriptor_GALGAS_enumValues,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_valueList (C_Compiler * inCompiler,
                                                          const cObjectArray & inEffectiveParameterArray,
                                                          const GALGAS_location & /* inErrorLocation */
                                                          COMMA_LOCATION_ARGS) {
  const GALGAS_enumValues operand0 = GALGAS_enumValues::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                       inCompiler
                                                                       COMMA_THERE) ;
  return function_valueList (operand0,
                             inCompiler
                             COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_valueList ("valueList",
                                                           functionWithGenericHeader_valueList,
                                                           & kTypeDescriptor_GALGAS_string,
                                                           1,
                                                           functionArgs_valueList) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                Routine 'verifyEnum'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_verifyEnum (const GALGAS_impType constinArgument_anEnum,
                         C_Compiler * inCompiler
                         COMMA_UNUSED_LOCATION_ARGS) {
  if (constinArgument_anEnum.isValid ()) {
    if (constinArgument_anEnum.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_impEnumType) {
      GALGAS_impEnumType cast_20350_realEnum ((cPtr_impEnumType *) constinArgument_anEnum.ptr ()) ;
      if (cast_20350_realEnum.getter_defaultValue (SOURCE_FILE ("implementation_types.galgas", 737)).isValid ()) {
        if (cast_20350_realEnum.getter_defaultValue (SOURCE_FILE ("implementation_types.galgas", 737)).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_string_5F_class) {
          GALGAS_string_5F_class cast_20424_defaultValue ((cPtr_string_5F_class *) cast_20350_realEnum.getter_defaultValue (SOURCE_FILE ("implementation_types.galgas", 737)).ptr ()) ;
          const enumGalgasBool test_0 = cast_20350_realEnum.getter_valuesMap (SOURCE_FILE ("implementation_types.galgas", 739)).getter_hasKey (cast_20424_defaultValue.getter_value (SOURCE_FILE ("implementation_types.galgas", 739)) COMMA_SOURCE_FILE ("implementation_types.galgas", 739)).operator_not (SOURCE_FILE ("implementation_types.galgas", 739)).boolEnum () ;
          if (kBoolTrue == test_0) {
            TC_Array <C_FixItDescription> fixItArray1 ;
            inCompiler->emitSemanticError (cast_20424_defaultValue.getter_location (SOURCE_FILE ("implementation_types.galgas", 740)), GALGAS_string ("Default enum value does not match any enum value"), fixItArray1  COMMA_SOURCE_FILE ("implementation_types.galgas", 740)) ;
          }
        }
      }
    }else{
      cEnumerator_locationList enumerator_20649 (constinArgument_anEnum.getter_locations (SOURCE_FILE ("implementation_types.galgas", 744)), kEnumeration_up) ;
      while (enumerator_20649.hasCurrentObject ()) {
        TC_Array <C_FixItDescription> fixItArray2 ;
        inCompiler->emitSemanticError (enumerator_20649.current_location (HERE), GALGAS_string ("Internal, not an @impEnumType"), fixItArray2  COMMA_SOURCE_FILE ("implementation_types.galgas", 745)) ;
        enumerator_20649.gotoNextObject () ;
      }
    }
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         Function 'checkAndGetIntegerNumber'                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_object_5F_t function_checkAndGetIntegerNumber (const GALGAS_lstring & constinArgument_oil_5F_desc,
                                                      const GALGAS_dataType & constinArgument_type,
                                                      const GALGAS_luint_36__34_ & constinArgument_number,
                                                      const GALGAS_bool & constinArgument_signed,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_object_5F_t result_value ; // Returned variable
  const enumGalgasBool test_0 = constinArgument_signed.boolEnum () ;
  if (kBoolTrue == test_0) {
    const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_sint_33__32_Number (SOURCE_FILE ("implementation_types.galgas", 806)))).boolEnum () ;
    if (kBoolTrue == test_1) {
      result_value = GALGAS_sint_33__32__5F_class::constructor_new (constinArgument_oil_5F_desc, constinArgument_number.getter_location (SOURCE_FILE ("implementation_types.galgas", 807)), constinArgument_number.getter_uint_36__34_ (SOURCE_FILE ("implementation_types.galgas", 807)).getter_sint (inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 807)).multiply_operation (GALGAS_sint ((int32_t) 1L).operator_unary_minus (inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 807)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 807))  COMMA_SOURCE_FILE ("implementation_types.galgas", 807)) ;
    }else if (kBoolFalse == test_1) {
      const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_sint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 808)))).boolEnum () ;
      if (kBoolTrue == test_2) {
        result_value = GALGAS_sint_36__34__5F_class::constructor_new (constinArgument_oil_5F_desc, constinArgument_number.getter_location (SOURCE_FILE ("implementation_types.galgas", 809)), constinArgument_number.getter_uint_36__34_ (SOURCE_FILE ("implementation_types.galgas", 809)).getter_sint_36__34_ (inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 809)).multiply_operation (GALGAS_sint_36__34_ ((int64_t) 1LL).operator_unary_minus (inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 809)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 809))  COMMA_SOURCE_FILE ("implementation_types.galgas", 809)) ;
      }else if (kBoolFalse == test_2) {
        result_value = GALGAS_void::constructor_new (constinArgument_oil_5F_desc, constinArgument_number.getter_location (SOURCE_FILE ("implementation_types.galgas", 811))  COMMA_SOURCE_FILE ("implementation_types.galgas", 811)) ;
        TC_Array <C_FixItDescription> fixItArray3 ;
        inCompiler->emitSemanticError (constinArgument_number.getter_location (SOURCE_FILE ("implementation_types.galgas", 812)), extensionGetter_oilType (constinArgument_type, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 812)).add_operation (GALGAS_string (" expected, got a SINT"), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 812)), fixItArray3  COMMA_SOURCE_FILE ("implementation_types.galgas", 812)) ;
      }
    }
  }else if (kBoolFalse == test_0) {
    const enumGalgasBool test_4 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_sint_33__32_Number (SOURCE_FILE ("implementation_types.galgas", 815)))).boolEnum () ;
    if (kBoolTrue == test_4) {
      result_value = GALGAS_sint_33__32__5F_class::constructor_new (constinArgument_oil_5F_desc, constinArgument_number.getter_location (SOURCE_FILE ("implementation_types.galgas", 816)), constinArgument_number.getter_uint_36__34_ (SOURCE_FILE ("implementation_types.galgas", 816)).getter_sint (inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 816))  COMMA_SOURCE_FILE ("implementation_types.galgas", 816)) ;
    }else if (kBoolFalse == test_4) {
      const enumGalgasBool test_5 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_sint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 817)))).boolEnum () ;
      if (kBoolTrue == test_5) {
        result_value = GALGAS_sint_36__34__5F_class::constructor_new (constinArgument_oil_5F_desc, constinArgument_number.getter_location (SOURCE_FILE ("implementation_types.galgas", 818)), constinArgument_number.getter_uint_36__34_ (SOURCE_FILE ("implementation_types.galgas", 818)).getter_sint_36__34_ (inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 818))  COMMA_SOURCE_FILE ("implementation_types.galgas", 818)) ;
      }else if (kBoolFalse == test_5) {
        const enumGalgasBool test_6 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_uint_33__32_Number (SOURCE_FILE ("implementation_types.galgas", 819)))).boolEnum () ;
        if (kBoolTrue == test_6) {
          result_value = GALGAS_uint_33__32__5F_class::constructor_new (constinArgument_oil_5F_desc, constinArgument_number.getter_location (SOURCE_FILE ("implementation_types.galgas", 820)), constinArgument_number.getter_uint_36__34_ (SOURCE_FILE ("implementation_types.galgas", 820)).getter_uint (inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 820))  COMMA_SOURCE_FILE ("implementation_types.galgas", 820)) ;
        }else if (kBoolFalse == test_6) {
          const enumGalgasBool test_7 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 821)))).boolEnum () ;
          if (kBoolTrue == test_7) {
            result_value = GALGAS_uint_36__34__5F_class::constructor_new (constinArgument_oil_5F_desc, constinArgument_number.getter_location (SOURCE_FILE ("implementation_types.galgas", 822)), constinArgument_number.getter_uint_36__34_ (SOURCE_FILE ("implementation_types.galgas", 822))  COMMA_SOURCE_FILE ("implementation_types.galgas", 822)) ;
          }else if (kBoolFalse == test_7) {
            result_value = GALGAS_void::constructor_new (constinArgument_oil_5F_desc, constinArgument_number.getter_location (SOURCE_FILE ("implementation_types.galgas", 824))  COMMA_SOURCE_FILE ("implementation_types.galgas", 824)) ;
            TC_Array <C_FixItDescription> fixItArray8 ;
            inCompiler->emitSemanticError (constinArgument_number.getter_location (SOURCE_FILE ("implementation_types.galgas", 825)), extensionGetter_oilType (constinArgument_type, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 825)).add_operation (GALGAS_string (" expected, got a UINT"), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 825)), fixItArray8  COMMA_SOURCE_FILE ("implementation_types.galgas", 825)) ;
          }
        }
      }
    }
  }
//---
  return result_value ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_checkAndGetIntegerNumber [5] = {
  & kTypeDescriptor_GALGAS_lstring,
  & kTypeDescriptor_GALGAS_dataType,
  & kTypeDescriptor_GALGAS_luint_36__34_,
  & kTypeDescriptor_GALGAS_bool,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_checkAndGetIntegerNumber (C_Compiler * inCompiler,
                                                                         const cObjectArray & inEffectiveParameterArray,
                                                                         const GALGAS_location & /* inErrorLocation */
                                                                         COMMA_LOCATION_ARGS) {
  const GALGAS_lstring operand0 = GALGAS_lstring::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  const GALGAS_dataType operand1 = GALGAS_dataType::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                                   inCompiler
                                                                   COMMA_THERE) ;
  const GALGAS_luint_36__34_ operand2 = GALGAS_luint_36__34_::extractObject (inEffectiveParameterArray.objectAtIndex (2 COMMA_HERE),
                                                                             inCompiler
                                                                             COMMA_THERE) ;
  const GALGAS_bool operand3 = GALGAS_bool::extractObject (inEffectiveParameterArray.objectAtIndex (3 COMMA_HERE),
                                                           inCompiler
                                                           COMMA_THERE) ;
  return function_checkAndGetIntegerNumber (operand0,
                                            operand1,
                                            operand2,
                                            operand3,
                                            inCompiler
                                            COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_checkAndGetIntegerNumber ("checkAndGetIntegerNumber",
                                                                          functionWithGenericHeader_checkAndGetIntegerNumber,
                                                                          & kTypeDescriptor_GALGAS_object_5F_t,
                                                                          4,
                                                                          functionArgs_checkAndGetIntegerNumber) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          Function 'checkAndGetFloatNumber'                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_object_5F_t function_checkAndGetFloatNumber (const GALGAS_lstring & constinArgument_oil_5F_desc,
                                                    const GALGAS_dataType & constinArgument_type,
                                                    const GALGAS_ldouble & constinArgument_number,
                                                    const GALGAS_bool & constinArgument_signed,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_object_5F_t result_value ; // Returned variable
  const enumGalgasBool test_0 = constinArgument_signed.boolEnum () ;
  if (kBoolTrue == test_0) {
    const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_floatNumber (SOURCE_FILE ("implementation_types.galgas", 837)))).boolEnum () ;
    if (kBoolTrue == test_1) {
      result_value = GALGAS_float_5F_class::constructor_new (constinArgument_oil_5F_desc, constinArgument_number.getter_location (SOURCE_FILE ("implementation_types.galgas", 838)), constinArgument_number.getter_double (SOURCE_FILE ("implementation_types.galgas", 838)).multiply_operation (GALGAS_double (1).operator_unary_minus (inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 838)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 838))  COMMA_SOURCE_FILE ("implementation_types.galgas", 838)) ;
    }else if (kBoolFalse == test_1) {
      result_value = GALGAS_void::constructor_new (constinArgument_oil_5F_desc, constinArgument_number.getter_location (SOURCE_FILE ("implementation_types.galgas", 840))  COMMA_SOURCE_FILE ("implementation_types.galgas", 840)) ;
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (constinArgument_number.getter_location (SOURCE_FILE ("implementation_types.galgas", 841)), extensionGetter_oilType (constinArgument_type, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 841)).add_operation (GALGAS_string (" expected, got a FLOAT"), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 841)), fixItArray2  COMMA_SOURCE_FILE ("implementation_types.galgas", 841)) ;
    }
  }else if (kBoolFalse == test_0) {
    const enumGalgasBool test_3 = GALGAS_bool (kIsEqual, constinArgument_type.objectCompare (GALGAS_dataType::constructor_floatNumber (SOURCE_FILE ("implementation_types.galgas", 844)))).boolEnum () ;
    if (kBoolTrue == test_3) {
      result_value = GALGAS_float_5F_class::constructor_new (constinArgument_oil_5F_desc, constinArgument_number.getter_location (SOURCE_FILE ("implementation_types.galgas", 845)), constinArgument_number.getter_double (SOURCE_FILE ("implementation_types.galgas", 845))  COMMA_SOURCE_FILE ("implementation_types.galgas", 845)) ;
    }else if (kBoolFalse == test_3) {
      result_value = GALGAS_void::constructor_new (constinArgument_oil_5F_desc, constinArgument_number.getter_location (SOURCE_FILE ("implementation_types.galgas", 847))  COMMA_SOURCE_FILE ("implementation_types.galgas", 847)) ;
      TC_Array <C_FixItDescription> fixItArray4 ;
      inCompiler->emitSemanticError (constinArgument_number.getter_location (SOURCE_FILE ("implementation_types.galgas", 848)), extensionGetter_oilType (constinArgument_type, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 848)).add_operation (GALGAS_string (" expected, got a FLOAT"), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 848)), fixItArray4  COMMA_SOURCE_FILE ("implementation_types.galgas", 848)) ;
    }
  }
//---
  return result_value ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_checkAndGetFloatNumber [5] = {
  & kTypeDescriptor_GALGAS_lstring,
  & kTypeDescriptor_GALGAS_dataType,
  & kTypeDescriptor_GALGAS_ldouble,
  & kTypeDescriptor_GALGAS_bool,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_checkAndGetFloatNumber (C_Compiler * inCompiler,
                                                                       const cObjectArray & inEffectiveParameterArray,
                                                                       const GALGAS_location & /* inErrorLocation */
                                                                       COMMA_LOCATION_ARGS) {
  const GALGAS_lstring operand0 = GALGAS_lstring::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  const GALGAS_dataType operand1 = GALGAS_dataType::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                                   inCompiler
                                                                   COMMA_THERE) ;
  const GALGAS_ldouble operand2 = GALGAS_ldouble::extractObject (inEffectiveParameterArray.objectAtIndex (2 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  const GALGAS_bool operand3 = GALGAS_bool::extractObject (inEffectiveParameterArray.objectAtIndex (3 COMMA_HERE),
                                                           inCompiler
                                                           COMMA_THERE) ;
  return function_checkAndGetFloatNumber (operand0,
                                          operand1,
                                          operand2,
                                          operand3,
                                          inCompiler
                                          COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_checkAndGetFloatNumber ("checkAndGetFloatNumber",
                                                                        functionWithGenericHeader_checkAndGetFloatNumber,
                                                                        & kTypeDescriptor_GALGAS_object_5F_t,
                                                                        4,
                                                                        functionArgs_checkAndGetFloatNumber) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Routine 'checkTypeForAttribute'                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_checkTypeForAttribute (const GALGAS_implementationObjectMap constinArgument_obj,
                                    const GALGAS_string constinArgument_attributeName,
                                    const GALGAS_dataType constinArgument_expectedType,
                                    C_Compiler * inCompiler
                                    COMMA_UNUSED_LOCATION_ARGS) {
  const enumGalgasBool test_0 = constinArgument_obj.getter_hasKey (constinArgument_attributeName COMMA_SOURCE_FILE ("implementation_types.galgas", 857)).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_impType var_type_24042 ;
    constinArgument_obj.method_get (function_lstringWith (constinArgument_attributeName, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 859)), var_type_24042, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 859)) ;
    const enumGalgasBool test_1 = GALGAS_bool (kIsNotEqual, var_type_24042.getter_type (SOURCE_FILE ("implementation_types.galgas", 860)).objectCompare (constinArgument_expectedType)).boolEnum () ;
    if (kBoolTrue == test_1) {
      cEnumerator_locationList enumerator_24164 (var_type_24042.getter_locations (SOURCE_FILE ("implementation_types.galgas", 861)), kEnumeration_up) ;
      while (enumerator_24164.hasCurrentObject ()) {
        TC_Array <C_FixItDescription> fixItArray2 ;
        inCompiler->emitSemanticError (enumerator_24164.current_location (HERE), constinArgument_attributeName.add_operation (GALGAS_string (" is a "), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 862)).add_operation (extensionGetter_oilType (var_type_24042.getter_type (SOURCE_FILE ("implementation_types.galgas", 862)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 862)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 862)), fixItArray2  COMMA_SOURCE_FILE ("implementation_types.galgas", 862)) ;
        TC_Array <C_FixItDescription> fixItArray3 ;
        inCompiler->emitSemanticError (enumerator_24164.current_location (HERE), constinArgument_attributeName.add_operation (GALGAS_string (" should be a "), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 863)).add_operation (extensionGetter_oilType (constinArgument_expectedType, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 863)), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 863)), fixItArray3  COMMA_SOURCE_FILE ("implementation_types.galgas", 863)) ;
        enumerator_24164.gotoNextObject () ;
      }
    }
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Function 'boolSubAttributes'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementationObjectMap function_boolSubAttributes (const GALGAS_implementationObject & constinArgument_obj,
                                                           const GALGAS_string & constinArgument_attributeName,
                                                           const GALGAS_bool & constinArgument_boolValue,
                                                           C_Compiler * inCompiler
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_implementationObjectMap result_subImplementation ; // Returned variable
  result_subImplementation = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("implementation_types.galgas", 874)) ;
  const enumGalgasBool test_0 = constinArgument_obj.getter_attributes (SOURCE_FILE ("implementation_types.galgas", 875)).getter_hasKey (constinArgument_attributeName COMMA_SOURCE_FILE ("implementation_types.galgas", 875)).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_impType var_type_24623 ;
    constinArgument_obj.getter_attributes (SOURCE_FILE ("implementation_types.galgas", 877)).method_get (function_lstringWith (constinArgument_attributeName, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 877)), var_type_24623, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 877)) ;
    if (var_type_24623.isValid ()) {
      if (var_type_24623.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_impBoolType) {
        GALGAS_impBoolType cast_24733_boolType ((cPtr_impBoolType *) var_type_24623.ptr ()) ;
        const enumGalgasBool test_1 = constinArgument_boolValue.boolEnum () ;
        if (kBoolTrue == test_1) {
          result_subImplementation = cast_24733_boolType.getter_trueSubAttributes (SOURCE_FILE ("implementation_types.galgas", 881)) ;
        }else if (kBoolFalse == test_1) {
          result_subImplementation = cast_24733_boolType.getter_falseSubAttributes (SOURCE_FILE ("implementation_types.galgas", 883)) ;
        }
      }
    }
  }
//---
  return result_subImplementation ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_boolSubAttributes [4] = {
  & kTypeDescriptor_GALGAS_implementationObject,
  & kTypeDescriptor_GALGAS_string,
  & kTypeDescriptor_GALGAS_bool,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_boolSubAttributes (C_Compiler * inCompiler,
                                                                  const cObjectArray & inEffectiveParameterArray,
                                                                  const GALGAS_location & /* inErrorLocation */
                                                                  COMMA_LOCATION_ARGS) {
  const GALGAS_implementationObject operand0 = GALGAS_implementationObject::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                                           inCompiler
                                                                                           COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  const GALGAS_bool operand2 = GALGAS_bool::extractObject (inEffectiveParameterArray.objectAtIndex (2 COMMA_HERE),
                                                           inCompiler
                                                           COMMA_THERE) ;
  return function_boolSubAttributes (operand0,
                                     operand1,
                                     operand2,
                                     inCompiler
                                     COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_boolSubAttributes ("boolSubAttributes",
                                                                   functionWithGenericHeader_boolSubAttributes,
                                                                   & kTypeDescriptor_GALGAS_implementationObjectMap,
                                                                   3,
                                                                   functionArgs_boolSubAttributes) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Function 'enumSubAttributes'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_implementationObjectMap function_enumSubAttributes (const GALGAS_implementationObject & constinArgument_obj,
                                                           const GALGAS_string & constinArgument_attributeName,
                                                           const GALGAS_string & constinArgument_enumValue,
                                                           C_Compiler * inCompiler
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_implementationObjectMap result_subImplementation ; // Returned variable
  result_subImplementation = GALGAS_implementationObjectMap::constructor_emptyMap (SOURCE_FILE ("implementation_types.galgas", 894)) ;
  const enumGalgasBool test_0 = constinArgument_obj.getter_attributes (SOURCE_FILE ("implementation_types.galgas", 895)).getter_hasKey (constinArgument_attributeName COMMA_SOURCE_FILE ("implementation_types.galgas", 895)).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_impType var_type_25202 ;
    constinArgument_obj.getter_attributes (SOURCE_FILE ("implementation_types.galgas", 897)).method_get (function_lstringWith (constinArgument_attributeName, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 897)), var_type_25202, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 897)) ;
    if (var_type_25202.isValid ()) {
      if (var_type_25202.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_impEnumType) {
        GALGAS_impEnumType cast_25312_enumType ((cPtr_impEnumType *) var_type_25202.ptr ()) ;
        const enumGalgasBool test_1 = cast_25312_enumType.getter_valuesMap (SOURCE_FILE ("implementation_types.galgas", 900)).getter_hasKey (constinArgument_enumValue COMMA_SOURCE_FILE ("implementation_types.galgas", 900)).boolEnum () ;
        if (kBoolTrue == test_1) {
          cast_25312_enumType.getter_valuesMap (SOURCE_FILE ("implementation_types.galgas", 901)).method_get (function_lstringWith (constinArgument_enumValue, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 901)), result_subImplementation, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 901)) ;
        }
      }
    }
  }
//---
  return result_subImplementation ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_enumSubAttributes [4] = {
  & kTypeDescriptor_GALGAS_implementationObject,
  & kTypeDescriptor_GALGAS_string,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_enumSubAttributes (C_Compiler * inCompiler,
                                                                  const cObjectArray & inEffectiveParameterArray,
                                                                  const GALGAS_location & /* inErrorLocation */
                                                                  COMMA_LOCATION_ARGS) {
  const GALGAS_implementationObject operand0 = GALGAS_implementationObject::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                                           inCompiler
                                                                                           COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  const GALGAS_string operand2 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (2 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_enumSubAttributes (operand0,
                                     operand1,
                                     operand2,
                                     inCompiler
                                     COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_enumSubAttributes ("enumSubAttributes",
                                                                   functionWithGenericHeader_enumSubAttributes,
                                                                   & kTypeDescriptor_GALGAS_implementationObjectMap,
                                                                   3,
                                                                   functionArgs_enumSubAttributes) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Routine 'checkFilters'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_checkFilters (const GALGAS_implementationObject constinArgument_messageProperty,
                           C_Compiler * inCompiler
                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_implementationObjectMap var_filter_25598 = function_enumSubAttributes (constinArgument_messageProperty, GALGAS_string ("FILTER"), GALGAS_string ("MASKEDNEWEQUALSX"), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 912)) ;
  {
  routine_checkTypeForAttribute (var_filter_25598, GALGAS_string ("MASK"), GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 913)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 913)) ;
  }
  {
  routine_checkTypeForAttribute (var_filter_25598, GALGAS_string ("X"), GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 914)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 914)) ;
  }
  var_filter_25598 = function_enumSubAttributes (constinArgument_messageProperty, GALGAS_string ("FILTER"), GALGAS_string ("MASKEDNEWDIFFERSX"), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 915)) ;
  {
  routine_checkTypeForAttribute (var_filter_25598, GALGAS_string ("MASK"), GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 916)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 916)) ;
  }
  {
  routine_checkTypeForAttribute (var_filter_25598, GALGAS_string ("X"), GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 917)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 917)) ;
  }
  var_filter_25598 = function_enumSubAttributes (constinArgument_messageProperty, GALGAS_string ("FILTER"), GALGAS_string ("MASKEDNEWEQUALSMASKEDOLD"), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 918)) ;
  {
  routine_checkTypeForAttribute (var_filter_25598, GALGAS_string ("MASK"), GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 919)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 919)) ;
  }
  var_filter_25598 = function_enumSubAttributes (constinArgument_messageProperty, GALGAS_string ("FILTER"), GALGAS_string ("NEWISWITHIN"), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 920)) ;
  {
  routine_checkTypeForAttribute (var_filter_25598, GALGAS_string ("MIN"), GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 921)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 921)) ;
  }
  {
  routine_checkTypeForAttribute (var_filter_25598, GALGAS_string ("MAX"), GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 922)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 922)) ;
  }
  var_filter_25598 = function_enumSubAttributes (constinArgument_messageProperty, GALGAS_string ("FILTER"), GALGAS_string ("NEWISOUTSIDE"), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 923)) ;
  {
  routine_checkTypeForAttribute (var_filter_25598, GALGAS_string ("MIN"), GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 924)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 924)) ;
  }
  {
  routine_checkTypeForAttribute (var_filter_25598, GALGAS_string ("MAX"), GALGAS_dataType::constructor_uint_36__34_Number (SOURCE_FILE ("implementation_types.galgas", 925)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 925)) ;
  }
  var_filter_25598 = function_enumSubAttributes (constinArgument_messageProperty, GALGAS_string ("FILTER"), GALGAS_string ("ONEEVERYN"), inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 926)) ;
  {
  routine_checkTypeForAttribute (var_filter_25598, GALGAS_string ("PERIOD"), GALGAS_dataType::constructor_uint_33__32_Number (SOURCE_FILE ("implementation_types.galgas", 927)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 927)) ;
  }
  {
  routine_checkTypeForAttribute (var_filter_25598, GALGAS_string ("OFFSET"), GALGAS_dataType::constructor_uint_33__32_Number (SOURCE_FILE ("implementation_types.galgas", 928)), inCompiler  COMMA_SOURCE_FILE ("implementation_types.galgas", 928)) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Routine 'setDefaultsForType'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_setDefaultsForType (const GALGAS_implementationObjectMap constinArgument_impObject,
                                 GALGAS_objectAttributes & ioArgument_objectParams,
                                 C_Compiler * inCompiler
                                 COMMA_UNUSED_LOCATION_ARGS) {
  cEnumerator_implementationObjectMap enumerator_27955 (constinArgument_impObject, kEnumeration_up) ;
  while (enumerator_27955.hasCurrentObject ()) {
    if (enumerator_27955.current_type (HERE).isValid ()) {
      if (NULL != dynamic_cast <const cPtr_impAutoDefaultType *> (enumerator_27955.current_type (HERE).ptr ())) {
        GALGAS_impAutoDefaultType cast_28016_defaultType ((cPtr_impAutoDefaultType *) enumerator_27955.current_type (HERE).ptr ()) ;
        callExtensionMethod_setDefault ((const cPtr_impAutoDefaultType *) cast_28016_defaultType.ptr (), ioArgument_objectParams, inCompiler COMMA_SOURCE_FILE ("implementation_types.galgas", 976)) ;
      }
    }
    enumerator_27955.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Once function 'emptyLString'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_lstring onceFunction_emptyLString (C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring result_ls ; // Returned variable
  result_ls = GALGAS_lstring::constructor_new (GALGAS_string::makeEmptyString (), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 29))  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 29)) ;
//---
  return result_ls ;
}



//---------------------------------------------------------------------------------------------------------------------*
//  Function implementation                                                                                            *
//---------------------------------------------------------------------------------------------------------------------*

static bool gOnceFunctionResultAvailable_emptyLString = false ;
static GALGAS_lstring gOnceFunctionResult_emptyLString ;

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring function_emptyLString (class C_Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_emptyLString) {
    gOnceFunctionResult_emptyLString = onceFunction_emptyLString (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_emptyLString = true ;
  }
  return gOnceFunctionResult_emptyLString ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void releaseOnceFunctionResult_emptyLString (void) {
  gOnceFunctionResult_emptyLString.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gEpilogueForOnceFunction_emptyLString (NULL,
                                                          releaseOnceFunctionResult_emptyLString) ;

//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_emptyLString [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_emptyLString (C_Compiler * inCompiler,
                                                             const cObjectArray & /* inEffectiveParameterArray */,
                                                             const GALGAS_location & /* inErrorLocation */
                                                             COMMA_LOCATION_ARGS) {
  return function_emptyLString (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_emptyLString ("emptyLString",
                                                              functionWithGenericHeader_emptyLString,
                                                              & kTypeDescriptor_GALGAS_lstring,
                                                              0,
                                                              functionArgs_emptyLString) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Function 'emptyObject'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectAttributes function_emptyObject (C_Compiler * /* inCompiler */
                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_objectAttributes result_result ; // Returned variable
  result_result = GALGAS_objectAttributes::constructor_new (GALGAS_identifierMap::constructor_emptyMap (SOURCE_FILE ("goil_basic_types.galgas", 52))  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 52)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_emptyObject [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_emptyObject (C_Compiler * inCompiler,
                                                            const cObjectArray & /* inEffectiveParameterArray */,
                                                            const GALGAS_location & /* inErrorLocation */
                                                            COMMA_LOCATION_ARGS) {
  return function_emptyObject (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_emptyObject ("emptyObject",
                                                             functionWithGenericHeader_emptyObject,
                                                             & kTypeDescriptor_GALGAS_objectAttributes,
                                                             0,
                                                             functionArgs_emptyObject) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         Function 'multipleAttributeOrError'                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_identifierList function_multipleAttributeOrError (const GALGAS_object_5F_t & constinArgument_t,
                                                         const GALGAS_string & constinArgument_att,
                                                         C_Compiler * inCompiler
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_identifierList result_v ; // Returned variable
  result_v = GALGAS_identifierList::constructor_emptyList (SOURCE_FILE ("goil_basic_types.galgas", 71)) ;
  if (constinArgument_t.isValid ()) {
    if (constinArgument_t.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_multipleAttribute) {
      GALGAS_multipleAttribute cast_1710_l ((cPtr_multipleAttribute *) constinArgument_t.ptr ()) ;
      result_v = cast_1710_l.getter_items (SOURCE_FILE ("goil_basic_types.galgas", 74)) ;
    }else{
      TC_Array <C_FixItDescription> fixItArray0 ;
      inCompiler->emitSemanticError (constinArgument_t.getter_location (SOURCE_FILE ("goil_basic_types.galgas", 76)), GALGAS_string ("Internal error, ").add_operation (constinArgument_att, inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 76)).add_operation (GALGAS_string (" has a wrong datatype"), inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 76)), fixItArray0  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 76)) ;
    }
  }
//---
  return result_v ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_multipleAttributeOrError [3] = {
  & kTypeDescriptor_GALGAS_object_5F_t,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_multipleAttributeOrError (C_Compiler * inCompiler,
                                                                         const cObjectArray & inEffectiveParameterArray,
                                                                         const GALGAS_location & /* inErrorLocation */
                                                                         COMMA_LOCATION_ARGS) {
  const GALGAS_object_5F_t operand0 = GALGAS_object_5F_t::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_multipleAttributeOrError (operand0,
                                            operand1,
                                            inCompiler
                                            COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_multipleAttributeOrError ("multipleAttributeOrError",
                                                                          functionWithGenericHeader_multipleAttributeOrError,
                                                                          & kTypeDescriptor_GALGAS_identifierList,
                                                                          2,
                                                                          functionArgs_multipleAttributeOrError) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Function 'boolAttributeOrError'                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool function_boolAttributeOrError (GALGAS_object_5F_t inArgument_t,
                                           GALGAS_string inArgument_att,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_v ; // Returned variable
  result_v = GALGAS_bool (false) ;
  if (inArgument_t.isValid ()) {
    if (inArgument_t.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_boolAttribute) {
      GALGAS_boolAttribute cast_2046_attribute ((cPtr_boolAttribute *) inArgument_t.ptr ()) ;
      result_v = cast_2046_attribute.getter_value (SOURCE_FILE ("goil_basic_types.galgas", 92)) ;
    }else{
      TC_Array <C_FixItDescription> fixItArray0 ;
      inCompiler->emitSemanticError (inArgument_t.getter_location (SOURCE_FILE ("goil_basic_types.galgas", 94)), GALGAS_string ("Internal error, ").add_operation (inArgument_att, inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 94)).add_operation (GALGAS_string (" has a wrong datatype"), inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 94)), fixItArray0  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 94)) ;
    }
  }
//---
  return result_v ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_boolAttributeOrError [3] = {
  & kTypeDescriptor_GALGAS_object_5F_t,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_boolAttributeOrError (C_Compiler * inCompiler,
                                                                     const cObjectArray & inEffectiveParameterArray,
                                                                     const GALGAS_location & /* inErrorLocation */
                                                                     COMMA_LOCATION_ARGS) {
  const GALGAS_object_5F_t operand0 = GALGAS_object_5F_t::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_boolAttributeOrError (operand0,
                                        operand1,
                                        inCompiler
                                        COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_boolAttributeOrError ("boolAttributeOrError",
                                                                      functionWithGenericHeader_boolAttributeOrError,
                                                                      & kTypeDescriptor_GALGAS_bool,
                                                                      2,
                                                                      functionArgs_boolAttributeOrError) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             Function 'uint32_or_error'                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint function_uint_33__32__5F_or_5F_error (GALGAS_object_5F_t inArgument_t,
                                                  GALGAS_string inArgument_att,
                                                  C_Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_uint result_v ; // Returned variable
  result_v = GALGAS_uint ((uint32_t) 0U) ;
  if (inArgument_t.isValid ()) {
    if (inArgument_t.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_33__32__5F_class) {
      GALGAS_uint_33__32__5F_class cast_2567_ui ((cPtr_uint_33__32__5F_class *) inArgument_t.ptr ()) ;
      result_v = cast_2567_ui.getter_value (SOURCE_FILE ("goil_basic_types.galgas", 123)) ;
    }else{
      TC_Array <C_FixItDescription> fixItArray0 ;
      inCompiler->emitSemanticError (inArgument_t.getter_location (SOURCE_FILE ("goil_basic_types.galgas", 125)), inArgument_att.add_operation (GALGAS_string (" is not defined"), inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 125)), fixItArray0  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 125)) ;
    }
  }
//---
  return result_v ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_uint_33__32__5F_or_5F_error [3] = {
  & kTypeDescriptor_GALGAS_object_5F_t,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_uint_33__32__5F_or_5F_error (C_Compiler * inCompiler,
                                                                            const cObjectArray & inEffectiveParameterArray,
                                                                            const GALGAS_location & /* inErrorLocation */
                                                                            COMMA_LOCATION_ARGS) {
  const GALGAS_object_5F_t operand0 = GALGAS_object_5F_t::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_uint_33__32__5F_or_5F_error (operand0,
                                               operand1,
                                               inCompiler
                                               COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_uint_33__32__5F_or_5F_error ("uint32_or_error",
                                                                             functionWithGenericHeader_uint_33__32__5F_or_5F_error,
                                                                             & kTypeDescriptor_GALGAS_uint,
                                                                             2,
                                                                             functionArgs_uint_33__32__5F_or_5F_error) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Function 'uint32OrError'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint function_uint_33__32_OrError (GALGAS_object_5F_t inArgument_t,
                                          GALGAS_string inArgument_att,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_uint result_v ; // Returned variable
  result_v = GALGAS_uint ((uint32_t) 0U) ;
  if (inArgument_t.isValid ()) {
    if (inArgument_t.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_33__32__5F_class) {
      GALGAS_uint_33__32__5F_class cast_2766_ui ((cPtr_uint_33__32__5F_class *) inArgument_t.ptr ()) ;
      result_v = cast_2766_ui.getter_value (SOURCE_FILE ("goil_basic_types.galgas", 136)) ;
    }else{
      TC_Array <C_FixItDescription> fixItArray0 ;
      inCompiler->emitSemanticError (inArgument_t.getter_location (SOURCE_FILE ("goil_basic_types.galgas", 138)), inArgument_att.add_operation (GALGAS_string (" is not defined"), inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 138)), fixItArray0  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 138)) ;
    }
  }
//---
  return result_v ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_uint_33__32_OrError [3] = {
  & kTypeDescriptor_GALGAS_object_5F_t,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_uint_33__32_OrError (C_Compiler * inCompiler,
                                                                    const cObjectArray & inEffectiveParameterArray,
                                                                    const GALGAS_location & /* inErrorLocation */
                                                                    COMMA_LOCATION_ARGS) {
  const GALGAS_object_5F_t operand0 = GALGAS_object_5F_t::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_uint_33__32_OrError (operand0,
                                       operand1,
                                       inCompiler
                                       COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_uint_33__32_OrError ("uint32OrError",
                                                                     functionWithGenericHeader_uint_33__32_OrError,
                                                                     & kTypeDescriptor_GALGAS_uint,
                                                                     2,
                                                                     functionArgs_uint_33__32_OrError) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Function 'sint32OrError'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint function_sint_33__32_OrError (GALGAS_object_5F_t inArgument_t,
                                          GALGAS_string inArgument_att,
                                          C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_sint result_v ; // Returned variable
  result_v = GALGAS_sint ((int32_t) 0L) ;
  if (inArgument_t.isValid ()) {
    if (inArgument_t.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_sint_33__32__5F_class) {
      GALGAS_sint_33__32__5F_class cast_3104_ui ((cPtr_sint_33__32__5F_class *) inArgument_t.ptr ()) ;
      result_v = cast_3104_ui.getter_value (SOURCE_FILE ("goil_basic_types.galgas", 156)) ;
    }else{
      TC_Array <C_FixItDescription> fixItArray0 ;
      inCompiler->emitSemanticError (inArgument_t.getter_location (SOURCE_FILE ("goil_basic_types.galgas", 158)), inArgument_att.add_operation (GALGAS_string (" is not defined"), inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 158)), fixItArray0  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 158)) ;
    }
  }
//---
  return result_v ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_sint_33__32_OrError [3] = {
  & kTypeDescriptor_GALGAS_object_5F_t,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_sint_33__32_OrError (C_Compiler * inCompiler,
                                                                    const cObjectArray & inEffectiveParameterArray,
                                                                    const GALGAS_location & /* inErrorLocation */
                                                                    COMMA_LOCATION_ARGS) {
  const GALGAS_object_5F_t operand0 = GALGAS_object_5F_t::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_sint_33__32_OrError (operand0,
                                       operand1,
                                       inCompiler
                                       COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_sint_33__32_OrError ("sint32OrError",
                                                                     functionWithGenericHeader_sint_33__32_OrError,
                                                                     & kTypeDescriptor_GALGAS_sint,
                                                                     2,
                                                                     functionArgs_sint_33__32_OrError) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Function 'uint64OrError'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_uint_36__34_ function_uint_36__34_OrError (GALGAS_object_5F_t inArgument_t,
                                                  GALGAS_string inArgument_att,
                                                  C_Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_uint_36__34_ result_v ; // Returned variable
  result_v = GALGAS_uint_36__34_ ((uint64_t) 0ULL) ;
  if (inArgument_t.isValid ()) {
    if (inArgument_t.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_36__34__5F_class) {
      GALGAS_uint_36__34__5F_class cast_3442_ui ((cPtr_uint_36__34__5F_class *) inArgument_t.ptr ()) ;
      result_v = cast_3442_ui.getter_value (SOURCE_FILE ("goil_basic_types.galgas", 176)) ;
    }else{
      TC_Array <C_FixItDescription> fixItArray0 ;
      inCompiler->emitSemanticError (inArgument_t.getter_location (SOURCE_FILE ("goil_basic_types.galgas", 178)), GALGAS_string ("Internal error, ").add_operation (inArgument_att, inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 178)).add_operation (GALGAS_string (" has a wrong datatype"), inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 178)), fixItArray0  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 178)) ;
    }
  }
//---
  return result_v ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_uint_36__34_OrError [3] = {
  & kTypeDescriptor_GALGAS_object_5F_t,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_uint_36__34_OrError (C_Compiler * inCompiler,
                                                                    const cObjectArray & inEffectiveParameterArray,
                                                                    const GALGAS_location & /* inErrorLocation */
                                                                    COMMA_LOCATION_ARGS) {
  const GALGAS_object_5F_t operand0 = GALGAS_object_5F_t::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_uint_36__34_OrError (operand0,
                                       operand1,
                                       inCompiler
                                       COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_uint_36__34_OrError ("uint64OrError",
                                                                     functionWithGenericHeader_uint_36__34_OrError,
                                                                     & kTypeDescriptor_GALGAS_uint_36__34_,
                                                                     2,
                                                                     functionArgs_uint_36__34_OrError) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Function 'luint64OrError'                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_luint_36__34_ function_luint_36__34_OrError (GALGAS_object_5F_t inArgument_t,
                                                    GALGAS_string inArgument_att,
                                                    C_Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_luint_36__34_ result_v ; // Returned variable
  if (inArgument_t.isValid ()) {
    if (inArgument_t.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_uint_36__34__5F_class) {
      GALGAS_uint_36__34__5F_class cast_3660_ui ((cPtr_uint_36__34__5F_class *) inArgument_t.ptr ()) ;
      result_v = GALGAS_luint_36__34_::constructor_new (cast_3660_ui.getter_value (SOURCE_FILE ("goil_basic_types.galgas", 188)), cast_3660_ui.getter_location (SOURCE_FILE ("goil_basic_types.galgas", 188))  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 188)) ;
    }else{
      result_v = GALGAS_luint_36__34_::constructor_new (GALGAS_uint_36__34_ ((uint64_t) 0ULL), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 190))  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 190)) ;
      TC_Array <C_FixItDescription> fixItArray0 ;
      inCompiler->emitSemanticError (inArgument_t.getter_location (SOURCE_FILE ("goil_basic_types.galgas", 191)), GALGAS_string ("Internal error, ").add_operation (inArgument_att, inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 191)).add_operation (GALGAS_string (" has a wrong datatype"), inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 191)), fixItArray0  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 191)) ;
    }
  }
//---
  return result_v ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_luint_36__34_OrError [3] = {
  & kTypeDescriptor_GALGAS_object_5F_t,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_luint_36__34_OrError (C_Compiler * inCompiler,
                                                                     const cObjectArray & inEffectiveParameterArray,
                                                                     const GALGAS_location & /* inErrorLocation */
                                                                     COMMA_LOCATION_ARGS) {
  const GALGAS_object_5F_t operand0 = GALGAS_object_5F_t::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_luint_36__34_OrError (operand0,
                                        operand1,
                                        inCompiler
                                        COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_luint_36__34_OrError ("luint64OrError",
                                                                      functionWithGenericHeader_luint_36__34_OrError,
                                                                      & kTypeDescriptor_GALGAS_luint_36__34_,
                                                                      2,
                                                                      functionArgs_luint_36__34_OrError) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Function 'sint64OrError'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_sint_36__34_ function_sint_36__34_OrError (GALGAS_object_5F_t inArgument_t,
                                                  GALGAS_string inArgument_att,
                                                  C_Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_sint_36__34_ result_v ; // Returned variable
  result_v = GALGAS_sint_36__34_ ((int64_t) 0LL) ;
  if (inArgument_t.isValid ()) {
    if (inArgument_t.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_sint_36__34__5F_class) {
      GALGAS_sint_36__34__5F_class cast_4102_ui ((cPtr_sint_36__34__5F_class *) inArgument_t.ptr ()) ;
      result_v = cast_4102_ui.getter_value (SOURCE_FILE ("goil_basic_types.galgas", 209)) ;
    }else{
      TC_Array <C_FixItDescription> fixItArray0 ;
      inCompiler->emitSemanticError (inArgument_t.getter_location (SOURCE_FILE ("goil_basic_types.galgas", 211)), GALGAS_string ("Internal error, ").add_operation (inArgument_att, inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 211)).add_operation (GALGAS_string (" has a wrong datatype"), inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 211)), fixItArray0  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 211)) ;
    }
  }
//---
  return result_v ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_sint_36__34_OrError [3] = {
  & kTypeDescriptor_GALGAS_object_5F_t,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_sint_36__34_OrError (C_Compiler * inCompiler,
                                                                    const cObjectArray & inEffectiveParameterArray,
                                                                    const GALGAS_location & /* inErrorLocation */
                                                                    COMMA_LOCATION_ARGS) {
  const GALGAS_object_5F_t operand0 = GALGAS_object_5F_t::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_sint_36__34_OrError (operand0,
                                       operand1,
                                       inCompiler
                                       COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_sint_36__34_OrError ("sint64OrError",
                                                                     functionWithGenericHeader_sint_36__34_OrError,
                                                                     & kTypeDescriptor_GALGAS_sint_36__34_,
                                                                     2,
                                                                     functionArgs_sint_36__34_OrError) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Function 'floatOrError'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_double function_floatOrError (GALGAS_object_5F_t inArgument_t,
                                     GALGAS_string inArgument_att,
                                     C_Compiler * inCompiler
                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_double result_v ; // Returned variable
  result_v = GALGAS_double (0) ;
  if (inArgument_t.isValid ()) {
    if (inArgument_t.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_float_5F_class) {
      GALGAS_float_5F_class cast_4452_ui ((cPtr_float_5F_class *) inArgument_t.ptr ()) ;
      result_v = cast_4452_ui.getter_value (SOURCE_FILE ("goil_basic_types.galgas", 229)) ;
    }else{
      TC_Array <C_FixItDescription> fixItArray0 ;
      inCompiler->emitSemanticError (inArgument_t.getter_location (SOURCE_FILE ("goil_basic_types.galgas", 231)), GALGAS_string ("Internal error, ").add_operation (inArgument_att, inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 231)).add_operation (GALGAS_string (" has a wrong datatype"), inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 231)), fixItArray0  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 231)) ;
    }
  }
//---
  return result_v ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_floatOrError [3] = {
  & kTypeDescriptor_GALGAS_object_5F_t,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_floatOrError (C_Compiler * inCompiler,
                                                             const cObjectArray & inEffectiveParameterArray,
                                                             const GALGAS_location & /* inErrorLocation */
                                                             COMMA_LOCATION_ARGS) {
  const GALGAS_object_5F_t operand0 = GALGAS_object_5F_t::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_floatOrError (operand0,
                                operand1,
                                inCompiler
                                COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_floatOrError ("floatOrError",
                                                              functionWithGenericHeader_floatOrError,
                                                              & kTypeDescriptor_GALGAS_double,
                                                              2,
                                                              functionArgs_floatOrError) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          Function 'stringAttributeOrError'                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring function_stringAttributeOrError (const GALGAS_object_5F_t & constinArgument_attribute,
                                                const GALGAS_string & constinArgument_attributeName,
                                                C_Compiler * inCompiler
                                                COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring result_result ; // Returned variable
  result_result = function_emptyLString (inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 253)) ;
  if (constinArgument_attribute.isValid ()) {
    if (constinArgument_attribute.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_stringAttribute) {
      GALGAS_stringAttribute cast_5004_attribute ((cPtr_stringAttribute *) constinArgument_attribute.ptr ()) ;
      result_result = GALGAS_lstring::constructor_new (cast_5004_attribute.getter_value (SOURCE_FILE ("goil_basic_types.galgas", 256)), cast_5004_attribute.getter_location (SOURCE_FILE ("goil_basic_types.galgas", 256))  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 256)) ;
    }else{
      TC_Array <C_FixItDescription> fixItArray0 ;
      inCompiler->emitSemanticError (constinArgument_attribute.getter_location (SOURCE_FILE ("goil_basic_types.galgas", 258)), GALGAS_string ("Internal error ").add_operation (constinArgument_attributeName, inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 258)).add_operation (GALGAS_string (" has a wrong datatype"), inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 258)), fixItArray0  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 258)) ;
    }
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_stringAttributeOrError [3] = {
  & kTypeDescriptor_GALGAS_object_5F_t,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_stringAttributeOrError (C_Compiler * inCompiler,
                                                                       const cObjectArray & inEffectiveParameterArray,
                                                                       const GALGAS_location & /* inErrorLocation */
                                                                       COMMA_LOCATION_ARGS) {
  const GALGAS_object_5F_t operand0 = GALGAS_object_5F_t::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_stringAttributeOrError (operand0,
                                          operand1,
                                          inCompiler
                                          COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_stringAttributeOrError ("stringAttributeOrError",
                                                                        functionWithGenericHeader_stringAttributeOrError,
                                                                        & kTypeDescriptor_GALGAS_lstring,
                                                                        2,
                                                                        functionArgs_stringAttributeOrError) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Function 'empty_lstring'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring function_empty_5F_lstring (C_Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring result_ls ; // Returned variable
  result_ls = GALGAS_lstring::constructor_new (GALGAS_string::makeEmptyString (), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 428))  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 428)) ;
//---
  return result_ls ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_empty_5F_lstring [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_empty_5F_lstring (C_Compiler * inCompiler,
                                                                 const cObjectArray & /* inEffectiveParameterArray */,
                                                                 const GALGAS_location & /* inErrorLocation */
                                                                 COMMA_LOCATION_ARGS) {
  return function_empty_5F_lstring (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_empty_5F_lstring ("empty_lstring",
                                                                  functionWithGenericHeader_empty_5F_lstring,
                                                                  & kTypeDescriptor_GALGAS_lstring,
                                                                  0,
                                                                  functionArgs_empty_5F_lstring) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 Function 'void_obj'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_object_5F_t function_void_5F_obj (C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_object_5F_t result_v ; // Returned variable
  result_v = GALGAS_void::constructor_new (function_emptyLString (inCompiler COMMA_SOURCE_FILE ("goil_basic_types.galgas", 433)), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 433))  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 433)) ;
//---
  return result_v ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_void_5F_obj [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_void_5F_obj (C_Compiler * inCompiler,
                                                            const cObjectArray & /* inEffectiveParameterArray */,
                                                            const GALGAS_location & /* inErrorLocation */
                                                            COMMA_LOCATION_ARGS) {
  return function_void_5F_obj (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_void_5F_obj ("void_obj",
                                                             functionWithGenericHeader_void_5F_obj,
                                                             & kTypeDescriptor_GALGAS_object_5F_t,
                                                             0,
                                                             functionArgs_void_5F_obj) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Function 'luint64_value'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_luint_36__34_ function_luint_36__34__5F_value (const GALGAS_uint_36__34__5F_class & constinArgument_c,
                                                      C_Compiler * /* inCompiler */
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_luint_36__34_ result_v ; // Returned variable
  result_v = GALGAS_luint_36__34_::constructor_new (constinArgument_c.getter_value (SOURCE_FILE ("goil_basic_types.galgas", 627)), constinArgument_c.getter_location (SOURCE_FILE ("goil_basic_types.galgas", 627))  COMMA_SOURCE_FILE ("goil_basic_types.galgas", 627)) ;
//---
  return result_v ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_luint_36__34__5F_value [2] = {
  & kTypeDescriptor_GALGAS_uint_36__34__5F_class,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_luint_36__34__5F_value (C_Compiler * inCompiler,
                                                                       const cObjectArray & inEffectiveParameterArray,
                                                                       const GALGAS_location & /* inErrorLocation */
                                                                       COMMA_LOCATION_ARGS) {
  const GALGAS_uint_36__34__5F_class operand0 = GALGAS_uint_36__34__5F_class::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                                             inCompiler
                                                                                             COMMA_THERE) ;
  return function_luint_36__34__5F_value (operand0,
                                          inCompiler
                                          COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_luint_36__34__5F_value ("luint64_value",
                                                                        functionWithGenericHeader_luint_36__34__5F_value,
                                                                        & kTypeDescriptor_GALGAS_luint_36__34_,
                                                                        1,
                                                                        functionArgs_luint_36__34__5F_value) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Function 'projectName'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_projectName (C_Compiler * inCompiler
                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_directory ; // Returned variable
  result_directory = GALGAS_string::constructor_stringWithSourceFilePath (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 30)).getter_stringByDeletingPathExtension (SOURCE_FILE ("goil_routines.galgas", 30)) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, GALGAS_string (gOption_goil_5F_options_project_5F_dir.getter_value ()).objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
  if (kBoolTrue == test_0) {
    result_directory = GALGAS_string (gOption_goil_5F_options_project_5F_dir.getter_value ()) ;
  }
//---
  return result_directory ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_projectName [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_projectName (C_Compiler * inCompiler,
                                                            const cObjectArray & /* inEffectiveParameterArray */,
                                                            const GALGAS_location & /* inErrorLocation */
                                                            COMMA_LOCATION_ARGS) {
  return function_projectName (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_projectName ("projectName",
                                                             functionWithGenericHeader_projectName,
                                                             & kTypeDescriptor_GALGAS_string,
                                                             0,
                                                             functionArgs_projectName) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 Function 'oil_dir'                                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_oil_5F_dir (C_Compiler * inCompiler
                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_dir ; // Returned variable
  result_dir = GALGAS_string::constructor_stringWithSourceFilePath (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 37)).getter_stringByDeletingLastPathComponent (SOURCE_FILE ("goil_routines.galgas", 37)) ;
//---
  return result_dir ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_oil_5F_dir [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_oil_5F_dir (C_Compiler * inCompiler,
                                                           const cObjectArray & /* inEffectiveParameterArray */,
                                                           const GALGAS_location & /* inErrorLocation */
                                                           COMMA_LOCATION_ARGS) {
  return function_oil_5F_dir (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_oil_5F_dir ("oil_dir",
                                                            functionWithGenericHeader_oil_5F_dir,
                                                            & kTypeDescriptor_GALGAS_string,
                                                            0,
                                                            functionArgs_oil_5F_dir) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                   Function 'arch'                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_arch (C_Compiler * inCompiler
                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_arch_5F_name ; // Returned variable
  GALGAS_stringlist var_components_1211 = GALGAS_string (gOption_goil_5F_options_target_5F_platform.getter_value ()).getter_componentsSeparatedByString (GALGAS_string ("/") COMMA_SOURCE_FILE ("goil_routines.galgas", 45)) ;
  var_components_1211.method_first (result_arch_5F_name, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 46)) ;
//---
  return result_arch_5F_name ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_arch [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_arch (C_Compiler * inCompiler,
                                                     const cObjectArray & /* inEffectiveParameterArray */,
                                                     const GALGAS_location & /* inErrorLocation */
                                                     COMMA_LOCATION_ARGS) {
  return function_arch (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_arch ("arch",
                                                      functionWithGenericHeader_arch,
                                                      & kTypeDescriptor_GALGAS_string,
                                                      0,
                                                      functionArgs_arch) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                   Function 'chip'                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_chip (C_Compiler * inCompiler
                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_chip_5F_name ; // Returned variable
  GALGAS_stringlist var_components_1528 = GALGAS_string (gOption_goil_5F_options_target_5F_platform.getter_value ()).getter_componentsSeparatedByString (GALGAS_string ("/") COMMA_SOURCE_FILE ("goil_routines.galgas", 54)) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsStrictSup, var_components_1528.getter_length (SOURCE_FILE ("goil_routines.galgas", 55)).objectCompare (GALGAS_uint ((uint32_t) 1U))).boolEnum () ;
  if (kBoolTrue == test_0) {
    result_chip_5F_name = var_components_1528.getter_mValueAtIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 56)) ;
  }else if (kBoolFalse == test_0) {
    result_chip_5F_name = GALGAS_string::makeEmptyString () ;
  }
//---
  return result_chip_5F_name ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_chip [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_chip (C_Compiler * inCompiler,
                                                     const cObjectArray & /* inEffectiveParameterArray */,
                                                     const GALGAS_location & /* inErrorLocation */
                                                     COMMA_LOCATION_ARGS) {
  return function_chip (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_chip ("chip",
                                                      functionWithGenericHeader_chip,
                                                      & kTypeDescriptor_GALGAS_string,
                                                      0,
                                                      functionArgs_chip) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  Function 'board'                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_board (C_Compiler * inCompiler
                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_board_5F_name ; // Returned variable
  GALGAS_stringlist var_components_1946 = GALGAS_string (gOption_goil_5F_options_target_5F_platform.getter_value ()).getter_componentsSeparatedByString (GALGAS_string ("/") COMMA_SOURCE_FILE ("goil_routines.galgas", 68)) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsStrictSup, var_components_1946.getter_length (SOURCE_FILE ("goil_routines.galgas", 69)).objectCompare (GALGAS_uint ((uint32_t) 2U))).boolEnum () ;
  if (kBoolTrue == test_0) {
    {
    GALGAS_string joker_2090 ; // Joker input parameter
    var_components_1946.setter_popFirst (joker_2090, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 70)) ;
    }
    {
    GALGAS_string joker_2121 ; // Joker input parameter
    var_components_1946.setter_popFirst (joker_2121, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 71)) ;
    }
    result_board_5F_name = GALGAS_string::constructor_componentsJoinedByString (var_components_1946, GALGAS_string ("/")  COMMA_SOURCE_FILE ("goil_routines.galgas", 72)) ;
  }else if (kBoolFalse == test_0) {
    result_board_5F_name = GALGAS_string::makeEmptyString () ;
  }
//---
  return result_board_5F_name ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_board [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_board (C_Compiler * inCompiler,
                                                      const cObjectArray & /* inEffectiveParameterArray */,
                                                      const GALGAS_location & /* inErrorLocation */
                                                      COMMA_LOCATION_ARGS) {
  return function_board (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_board ("board",
                                                       functionWithGenericHeader_board,
                                                       & kTypeDescriptor_GALGAS_string,
                                                       0,
                                                       functionArgs_board) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Function 'targetPathList'                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_list function_targetPathList (C_Compiler * inCompiler
                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_list result_pathList ; // Returned variable
  GALGAS_stringlist var_components_2360 = GALGAS_string (gOption_goil_5F_options_target_5F_platform.getter_value ()).getter_componentsSeparatedByString (GALGAS_string ("/") COMMA_SOURCE_FILE ("goil_routines.galgas", 82)) ;
  result_pathList = GALGAS_list::constructor_emptyList (SOURCE_FILE ("goil_routines.galgas", 83)) ;
  cEnumerator_stringlist enumerator_2500 (var_components_2360, kEnumeration_up) ;
  while (enumerator_2500.hasCurrentObject ()) {
    GALGAS_gtlData var_cont_2521 = GALGAS_gtlString::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 85)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 85)), enumerator_2500.current_mValue (HERE)  COMMA_SOURCE_FILE ("goil_routines.galgas", 85)) ;
    result_pathList.addAssign_operation (var_cont_2521  COMMA_SOURCE_FILE ("goil_routines.galgas", 86)) ;
    enumerator_2500.gotoNextObject () ;
  }
//---
  return result_pathList ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_targetPathList [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_targetPathList (C_Compiler * inCompiler,
                                                               const cObjectArray & /* inEffectiveParameterArray */,
                                                               const GALGAS_location & /* inErrorLocation */
                                                               COMMA_LOCATION_ARGS) {
  return function_targetPathList (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_targetPathList ("targetPathList",
                                                                functionWithGenericHeader_targetPathList,
                                                                & kTypeDescriptor_GALGAS_list,
                                                                0,
                                                                functionArgs_targetPathList) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Function 'add_path_component'                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_add_5F_path_5F_component (GALGAS_string inArgument_path,
                                                 GALGAS_string inArgument_component,
                                                 C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_new_5F_path ; // Returned variable
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, inArgument_path.getter_characterAtIndex (inArgument_path.getter_length (SOURCE_FILE ("goil_routines.galgas", 97)).substract_operation (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 97)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 97)).objectCompare (GALGAS_char (TO_UNICODE (47)))).boolEnum () ;
  if (kBoolTrue == test_0) {
    result_new_5F_path = inArgument_path.add_operation (GALGAS_string ("/"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 98)).add_operation (inArgument_component, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 98)) ;
  }else if (kBoolFalse == test_0) {
    result_new_5F_path = inArgument_path.add_operation (inArgument_component, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 100)) ;
  }
//---
  return result_new_5F_path ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_add_5F_path_5F_component [3] = {
  & kTypeDescriptor_GALGAS_string,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_add_5F_path_5F_component (C_Compiler * inCompiler,
                                                                         const cObjectArray & inEffectiveParameterArray,
                                                                         const GALGAS_location & /* inErrorLocation */
                                                                         COMMA_LOCATION_ARGS) {
  const GALGAS_string operand0 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_add_5F_path_5F_component (operand0,
                                            operand1,
                                            inCompiler
                                            COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_add_5F_path_5F_component ("add_path_component",
                                                                          functionWithGenericHeader_add_5F_path_5F_component,
                                                                          & kTypeDescriptor_GALGAS_string,
                                                                          2,
                                                                          functionArgs_add_5F_path_5F_component) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          Function 'rootTemplatesDirectory'                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_rootTemplatesDirectory (C_Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_templateDirectory ; // Returned variable
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, GALGAS_string (gOption_goil_5F_options_template_5F_dir.getter_value ()).objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
  if (kBoolTrue == test_0) {
    result_templateDirectory = GALGAS_string (gOption_goil_5F_options_template_5F_dir.getter_value ()) ;
  }else if (kBoolFalse == test_0) {
    GALGAS_string var_env_3086 = GALGAS_string::constructor_stringWithEnvironmentVariableOrEmpty (GALGAS_string ("GOIL_TEMPLATES")  COMMA_SOURCE_FILE ("goil_routines.galgas", 110)) ;
    const enumGalgasBool test_1 = GALGAS_bool (kIsNotEqual, var_env_3086.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
    if (kBoolTrue == test_1) {
      result_templateDirectory = var_env_3086 ;
    }else if (kBoolFalse == test_1) {
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 114)), GALGAS_string ("The templates path is not set. Use --templates option or set the GOIL_TEMPLATES environment variable"), fixItArray2  COMMA_SOURCE_FILE ("goil_routines.galgas", 114)) ;
      result_templateDirectory.drop () ; // Release error dropped variable
    }
  }
  result_templateDirectory = result_templateDirectory.getter_unixPathWithNativePath (SOURCE_FILE ("goil_routines.galgas", 118)) ;
  result_templateDirectory = result_templateDirectory.getter_stringByStandardizingPath (SOURCE_FILE ("goil_routines.galgas", 119)) ;
  const enumGalgasBool test_3 = GALGAS_bool (kIsNotEqual, result_templateDirectory.getter_characterAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 121)).objectCompare (GALGAS_char (TO_UNICODE (47)))).boolEnum () ;
  if (kBoolTrue == test_3) {
    const enumGalgasBool test_4 = GALGAS_bool (kIsEqual, result_templateDirectory.getter_characterAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 122)).objectCompare (GALGAS_char (TO_UNICODE (126)))).boolEnum () ;
    if (kBoolTrue == test_4) {
      GALGAS_string var_home_3651 = GALGAS_string::constructor_stringWithEnvironmentVariableOrEmpty (GALGAS_string ("HOME")  COMMA_SOURCE_FILE ("goil_routines.galgas", 123)) ;
      GALGAS_string var_relativeToHome_3738 = result_templateDirectory.getter_rightSubString (result_templateDirectory.getter_length (SOURCE_FILE ("goil_routines.galgas", 124)).substract_operation (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 124)) COMMA_SOURCE_FILE ("goil_routines.galgas", 124)) ;
      result_templateDirectory = var_home_3651.add_operation (var_relativeToHome_3738, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 125)) ;
    }else if (kBoolFalse == test_4) {
      GALGAS_string var_currentDirectory_3895 = GALGAS_string::constructor_stringWithCurrentDirectory (SOURCE_FILE ("goil_routines.galgas", 127)) ;
      result_templateDirectory = var_currentDirectory_3895.add_operation (GALGAS_string ("/"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 128)).add_operation (result_templateDirectory, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 128)) ;
    }
    result_templateDirectory = result_templateDirectory.getter_stringByStandardizingPath (SOURCE_FILE ("goil_routines.galgas", 130)) ;
  }
//---
  return result_templateDirectory ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_rootTemplatesDirectory [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_rootTemplatesDirectory (C_Compiler * inCompiler,
                                                                       const cObjectArray & /* inEffectiveParameterArray */,
                                                                       const GALGAS_location & /* inErrorLocation */
                                                                       COMMA_LOCATION_ARGS) {
  return function_rootTemplatesDirectory (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_rootTemplatesDirectory ("rootTemplatesDirectory",
                                                                        functionWithGenericHeader_rootTemplatesDirectory,
                                                                        & kTypeDescriptor_GALGAS_string,
                                                                        0,
                                                                        functionArgs_rootTemplatesDirectory) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Function 'templates_directory'                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_templates_5F_directory (GALGAS_string inArgument_prefix,
                                               C_Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_temp_5F_dir ; // Returned variable
  result_temp_5F_dir = function_rootTemplatesDirectory (inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 135)) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, result_temp_5F_dir.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
  if (kBoolTrue == test_0) {
    result_temp_5F_dir = function_add_5F_path_5F_component (result_temp_5F_dir, inArgument_prefix, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 137)) ;
    const enumGalgasBool test_1 = GALGAS_bool (kIsNotEqual, result_temp_5F_dir.getter_characterAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 139)).objectCompare (GALGAS_char (TO_UNICODE (47)))).boolEnum () ;
    if (kBoolTrue == test_1) {
      GALGAS_string var_curdir_4402 = GALGAS_string::constructor_stringWithCurrentDirectory (SOURCE_FILE ("goil_routines.galgas", 140)) ;
      const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, result_temp_5F_dir.getter_characterAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 141)).objectCompare (GALGAS_char (TO_UNICODE (46)))).operator_and (GALGAS_bool (kIsEqual, result_temp_5F_dir.getter_characterAtIndex (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 141)).objectCompare (GALGAS_char (TO_UNICODE (47)))) COMMA_SOURCE_FILE ("goil_routines.galgas", 141)).boolEnum () ;
      if (kBoolTrue == test_2) {
        result_temp_5F_dir = result_temp_5F_dir.getter_stringByRemovingCharacterAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 142)).getter_stringByRemovingCharacterAtIndex (GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 142)) ;
      }
      result_temp_5F_dir = var_curdir_4402.add_operation (GALGAS_string ("/"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 144)).add_operation (result_temp_5F_dir, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 144)) ;
    }
    const enumGalgasBool test_3 = GALGAS_bool (kIsNotEqual, result_temp_5F_dir.getter_characterAtIndex (result_temp_5F_dir.getter_length (SOURCE_FILE ("goil_routines.galgas", 146)).substract_operation (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 146)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 146)).objectCompare (GALGAS_char (TO_UNICODE (47)))).boolEnum () ;
    if (kBoolTrue == test_3) {
      result_temp_5F_dir.plusAssign_operation(GALGAS_string ("/"), inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 147)) ;
    }
  }
//---
  return result_temp_5F_dir ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_templates_5F_directory [2] = {
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_templates_5F_directory (C_Compiler * inCompiler,
                                                                       const cObjectArray & inEffectiveParameterArray,
                                                                       const GALGAS_location & /* inErrorLocation */
                                                                       COMMA_LOCATION_ARGS) {
  const GALGAS_string operand0 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_templates_5F_directory (operand0,
                                          inCompiler
                                          COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_templates_5F_directory ("templates_directory",
                                                                        functionWithGenericHeader_templates_5F_directory,
                                                                        & kTypeDescriptor_GALGAS_string,
                                                                        1,
                                                                        functionArgs_templates_5F_directory) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             Function 'templateFilePath'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_templateFilePath (const GALGAS_string & constinArgument_prefix,
                                         const GALGAS_string & constinArgument_file,
                                         C_Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_path ; // Returned variable
  GALGAS_stringlist var_components_5004 = GALGAS_string (gOption_goil_5F_options_target_5F_platform.getter_value ()).getter_componentsSeparatedByString (GALGAS_string ("/") COMMA_SOURCE_FILE ("goil_routines.galgas", 158)) ;
  GALGAS_string var_templateDir_5107 = function_templates_5F_directory (constinArgument_prefix, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 159)) ;
  GALGAS_bool var_notFound_5155 = GALGAS_bool (true) ;
  GALGAS_bool var_notOver_5178 = GALGAS_bool (true) ;
  result_path = GALGAS_string::makeEmptyString () ;
  if (var_components_5004.getter_length (SOURCE_FILE ("goil_routines.galgas", 164)).add_operation (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 164)).isValid ()) {
    uint32_t variant_5207 = var_components_5004.getter_length (SOURCE_FILE ("goil_routines.galgas", 164)).add_operation (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 164)).uintValue () ;
    bool loop_5207 = true ;
    while (loop_5207) {
      loop_5207 = var_notFound_5155.operator_and (var_notOver_5178 COMMA_SOURCE_FILE ("goil_routines.galgas", 165)).isValid () ;
      if (loop_5207) {
        loop_5207 = var_notFound_5155.operator_and (var_notOver_5178 COMMA_SOURCE_FILE ("goil_routines.galgas", 165)).boolValue () ;
      }
      if (loop_5207 && (0 == variant_5207)) {
        loop_5207 = false ;
        inCompiler->loopRunTimeVariantError (SOURCE_FILE ("goil_routines.galgas", 164)) ;
      }
      if (loop_5207) {
        variant_5207 -- ;
        GALGAS_string var_targetPath_5284 = var_templateDir_5107.add_operation (GALGAS_string::constructor_componentsJoinedByString (var_components_5004, GALGAS_string ("/")  COMMA_SOURCE_FILE ("goil_routines.galgas", 166)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 166)).add_operation (GALGAS_string ("/"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 166)).add_operation (constinArgument_file, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 166)) ;
        const enumGalgasBool test_0 = var_targetPath_5284.getter_fileExists (SOURCE_FILE ("goil_routines.galgas", 168)).boolEnum () ;
        if (kBoolTrue == test_0) {
          var_notFound_5155 = GALGAS_bool (false) ;
          result_path = var_targetPath_5284 ;
        }
        const enumGalgasBool test_1 = GALGAS_bool (kIsStrictSup, var_components_5004.getter_length (SOURCE_FILE ("goil_routines.galgas", 172)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
        if (kBoolTrue == test_1) {
          {
          GALGAS_string joker_5560 ; // Joker input parameter
          var_components_5004.setter_popLast (joker_5560, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 173)) ;
          }
        }else if (kBoolFalse == test_1) {
          var_notOver_5178 = GALGAS_bool (false) ;
        }
      }
    }
  }
//---
  return result_path ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_templateFilePath [3] = {
  & kTypeDescriptor_GALGAS_string,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_templateFilePath (C_Compiler * inCompiler,
                                                                 const cObjectArray & inEffectiveParameterArray,
                                                                 const GALGAS_location & /* inErrorLocation */
                                                                 COMMA_LOCATION_ARGS) {
  const GALGAS_string operand0 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_templateFilePath (operand0,
                                    operand1,
                                    inCompiler
                                    COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_templateFilePath ("templateFilePath",
                                                                  functionWithGenericHeader_templateFilePath,
                                                                  & kTypeDescriptor_GALGAS_string,
                                                                  2,
                                                                  functionArgs_templateFilePath) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             Function 'allTemplatePaths'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringlist function_allTemplatePaths (const GALGAS_string & constinArgument_prefix,
                                             C_Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_stringlist result_paths ; // Returned variable
  GALGAS_stringlist var_components_5703 = GALGAS_string (gOption_goil_5F_options_target_5F_platform.getter_value ()).getter_componentsSeparatedByString (GALGAS_string ("/") COMMA_SOURCE_FILE ("goil_routines.galgas", 184)) ;
  GALGAS_string var_partialPath_5806 = function_templates_5F_directory (constinArgument_prefix, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 185)) ;
  result_paths = GALGAS_stringlist::constructor_listWithValue (var_partialPath_5806  COMMA_SOURCE_FILE ("goil_routines.galgas", 187)) ;
  cEnumerator_stringlist enumerator_5938 (var_components_5703, kEnumeration_up) ;
  while (enumerator_5938.hasCurrentObject ()) {
    var_partialPath_5806 = function_add_5F_path_5F_component (var_partialPath_5806, enumerator_5938.current_mValue (HERE), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 190)) ;
    {
    result_paths.setter_insertAtIndex (var_partialPath_5806, GALGAS_uint ((uint32_t) 0U), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 191)) ;
    }
    enumerator_5938.gotoNextObject () ;
  }
//---
  return result_paths ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_allTemplatePaths [2] = {
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_allTemplatePaths (C_Compiler * inCompiler,
                                                                 const cObjectArray & inEffectiveParameterArray,
                                                                 const GALGAS_location & /* inErrorLocation */
                                                                 COMMA_LOCATION_ARGS) {
  const GALGAS_string operand0 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_allTemplatePaths (operand0,
                                    inCompiler
                                    COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_allTemplatePaths ("allTemplatePaths",
                                                                  functionWithGenericHeader_allTemplatePaths,
                                                                  & kTypeDescriptor_GALGAS_stringlist,
                                                                  1,
                                                                  functionArgs_allTemplatePaths) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Routine 'checkTemplatesPath'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_checkTemplatesPath (C_Compiler * inCompiler
                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string var_configDir_6102 = function_rootTemplatesDirectory (inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 197)).add_operation (GALGAS_string ("/config"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 197)) ;
  const enumGalgasBool test_0 = var_configDir_6102.getter_directoryExists (SOURCE_FILE ("goil_routines.galgas", 198)).operator_not (SOURCE_FILE ("goil_routines.galgas", 198)).boolEnum () ;
  if (kBoolTrue == test_0) {
    TC_Array <C_FixItDescription> fixItArray1 ;
    inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 199)), GALGAS_string ("The templates path '").add_operation (var_configDir_6102, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 199)).add_operation (GALGAS_string ("' is not set to the templates directory"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 199)), fixItArray1  COMMA_SOURCE_FILE ("goil_routines.galgas", 199)) ;
  }else if (kBoolFalse == test_0) {
    GALGAS_string var_partialPath_6319 = var_configDir_6102 ;
    GALGAS_bool var_continueIt_6352 = GALGAS_bool (true) ;
    GALGAS_stringlist var_components_6386 = GALGAS_string (gOption_goil_5F_options_target_5F_platform.getter_value ()).getter_componentsSeparatedByString (GALGAS_string ("/") COMMA_SOURCE_FILE ("goil_routines.galgas", 203)) ;
    cEnumerator_stringlist enumerator_6504 (var_components_6386, kEnumeration_up) ;
    while (enumerator_6504.hasCurrentObject ()) {
      var_partialPath_6319 = var_partialPath_6319.add_operation (GALGAS_string ("/"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 205)).add_operation (enumerator_6504.current_mValue (HERE), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 205)) ;
      GALGAS_bool test_2 = var_continueIt_6352 ;
      if (kBoolTrue == test_2.boolEnum ()) {
        test_2 = var_partialPath_6319.getter_directoryExists (SOURCE_FILE ("goil_routines.galgas", 206)).operator_not (SOURCE_FILE ("goil_routines.galgas", 206)) ;
      }
      const enumGalgasBool test_3 = test_2.boolEnum () ;
      if (kBoolTrue == test_3) {
        TC_Array <C_FixItDescription> fixItArray4 ;
        inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 207)), GALGAS_string ("The templates path '").add_operation (var_partialPath_6319, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 207)).add_operation (GALGAS_string ("' does not exist in the templates directory"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 207)), fixItArray4  COMMA_SOURCE_FILE ("goil_routines.galgas", 207)) ;
        var_continueIt_6352 = GALGAS_bool (false) ;
      }
      enumerator_6504.gotoNextObject () ;
    }
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Function 'allTemplateFilePaths'                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringlist function_allTemplateFilePaths (const GALGAS_string & constinArgument_prefix,
                                                 const GALGAS_string & constinArgument_file,
                                                 C_Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_stringlist result_paths ; // Returned variable
  GALGAS_stringlist var_components_6901 = GALGAS_string (gOption_goil_5F_options_target_5F_platform.getter_value ()).getter_componentsSeparatedByString (GALGAS_string ("/") COMMA_SOURCE_FILE ("goil_routines.galgas", 220)) ;
  GALGAS_string var_templateDir_7004 = function_templates_5F_directory (constinArgument_prefix, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 221)) ;
  GALGAS_bool var_notOver_7051 = GALGAS_bool (true) ;
  result_paths = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("goil_routines.galgas", 223)) ;
  if (var_components_6901.getter_length (SOURCE_FILE ("goil_routines.galgas", 225)).add_operation (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 225)).isValid ()) {
    uint32_t variant_7101 = var_components_6901.getter_length (SOURCE_FILE ("goil_routines.galgas", 225)).add_operation (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 225)).uintValue () ;
    bool loop_7101 = true ;
    while (loop_7101) {
      loop_7101 = var_notOver_7051.isValid () ;
      if (loop_7101) {
        loop_7101 = var_notOver_7051.boolValue () ;
      }
      if (loop_7101 && (0 == variant_7101)) {
        loop_7101 = false ;
        inCompiler->loopRunTimeVariantError (SOURCE_FILE ("goil_routines.galgas", 225)) ;
      }
      if (loop_7101) {
        variant_7101 -- ;
        GALGAS_string var_intermediatePath_7173 = GALGAS_string::constructor_componentsJoinedByString (var_components_6901, GALGAS_string ("/")  COMMA_SOURCE_FILE ("goil_routines.galgas", 227)) ;
        const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, var_intermediatePath_7173.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
        if (kBoolTrue == test_0) {
          var_intermediatePath_7173.plusAssign_operation(GALGAS_string ("/"), inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 228)) ;
        }
        GALGAS_string var_targetPath_7315 = var_templateDir_7004.add_operation (var_intermediatePath_7173, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 229)).add_operation (constinArgument_file, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 229)) ;
        const enumGalgasBool test_1 = var_targetPath_7315.getter_fileExists (SOURCE_FILE ("goil_routines.galgas", 231)).boolEnum () ;
        if (kBoolTrue == test_1) {
          result_paths.addAssign_operation (var_targetPath_7315  COMMA_SOURCE_FILE ("goil_routines.galgas", 232)) ;
        }
        const enumGalgasBool test_2 = GALGAS_bool (kIsStrictSup, var_components_6901.getter_length (SOURCE_FILE ("goil_routines.galgas", 234)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
        if (kBoolTrue == test_2) {
          {
          GALGAS_string joker_7530 ; // Joker input parameter
          var_components_6901.setter_popLast (joker_7530, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 235)) ;
          }
        }else if (kBoolFalse == test_2) {
          var_notOver_7051 = GALGAS_bool (false) ;
        }
      }
    }
  }
//---
  return result_paths ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_allTemplateFilePaths [3] = {
  & kTypeDescriptor_GALGAS_string,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_allTemplateFilePaths (C_Compiler * inCompiler,
                                                                     const cObjectArray & inEffectiveParameterArray,
                                                                     const GALGAS_location & /* inErrorLocation */
                                                                     COMMA_LOCATION_ARGS) {
  const GALGAS_string operand0 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_allTemplateFilePaths (operand0,
                                        operand1,
                                        inCompiler
                                        COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_allTemplateFilePaths ("allTemplateFilePaths",
                                                                      functionWithGenericHeader_allTemplateFilePaths,
                                                                      & kTypeDescriptor_GALGAS_stringlist,
                                                                      2,
                                                                      functionArgs_allTemplateFilePaths) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  Routine 'prefix'                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_prefix (GALGAS_prefix_5F_map inArgument_p,
                     GALGAS_string inArgument_key,
                     GALGAS_string & outArgument_val,
                     C_Compiler * inCompiler
                     COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_val.drop () ; // Release 'out' argument
  GALGAS_lstring var_lkey_7653 = GALGAS_lstring::constructor_new (inArgument_key, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 243))  COMMA_SOURCE_FILE ("goil_routines.galgas", 243)) ;
  GALGAS_string joker_7720 ; // Joker input parameter
  inArgument_p.method_prefix (var_lkey_7653, outArgument_val, joker_7720, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 244)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Routine 'performReplace'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_performReplace (GALGAS_prefix_5F_map inArgument_p,
                             GALGAS_string inArgument_key,
                             GALGAS_string inArgument_name,
                             GALGAS_string & ioArgument_res,
                             C_Compiler * inCompiler
                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring var_lkey_7821 = GALGAS_lstring::constructor_new (inArgument_key, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 248))  COMMA_SOURCE_FILE ("goil_routines.galgas", 248)) ;
  GALGAS_string var_prefix_7880 ;
  GALGAS_string var_tag_5F_to_5F_rep_7903 ;
  inArgument_p.method_prefix (var_lkey_7821, var_prefix_7880, var_tag_5F_to_5F_rep_7903, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 251)) ;
  ioArgument_res = ioArgument_res.getter_stringByReplacingStringByString (var_tag_5F_to_5F_rep_7903, var_prefix_7880.add_operation (inArgument_name, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 252)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 252)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 Routine 'doReplace'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_doReplace (GALGAS_string & ioArgument_s,
                        GALGAS_string inArgument_o,
                        GALGAS_string inArgument_n,
                        C_Compiler * inCompiler
                        COMMA_UNUSED_LOCATION_ARGS) {
  ioArgument_s = ioArgument_s.getter_stringByReplacingStringByString (inArgument_o, inArgument_n, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 256)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Routine 'do_replace_default'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_do_5F_replace_5F_default (GALGAS_string & ioArgument_s,
                                       GALGAS_string inArgument_o,
                                       GALGAS_string inArgument_n,
                                       GALGAS_string inArgument_d,
                                       C_Compiler * inCompiler
                                       COMMA_UNUSED_LOCATION_ARGS) {
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, inArgument_n.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
  if (kBoolTrue == test_0) {
    ioArgument_s = ioArgument_s.getter_stringByReplacingStringByString (inArgument_o, inArgument_n, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 261)) ;
  }else if (kBoolFalse == test_0) {
    ioArgument_s = ioArgument_s.getter_stringByReplacingStringByString (inArgument_o, inArgument_d, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 263)) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             Routine 'replace_no_prefix'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_replace_5F_no_5F_prefix (GALGAS_prefix_5F_map inArgument_p,
                                      GALGAS_string inArgument_key,
                                      GALGAS_string inArgument_name,
                                      GALGAS_string & ioArgument_res,
                                      C_Compiler * inCompiler
                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring var_lkey_8426 = GALGAS_lstring::constructor_new (inArgument_key, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 268))  COMMA_SOURCE_FILE ("goil_routines.galgas", 268)) ;
  GALGAS_string var_tag_5F_to_5F_rep_8511 ;
  GALGAS_string joker_8533 ; // Joker input parameter
  inArgument_p.method_prefix (var_lkey_8426, joker_8533, var_tag_5F_to_5F_rep_8511, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 271)) ;
  ioArgument_res = ioArgument_res.getter_stringByReplacingStringByString (var_tag_5F_to_5F_rep_8511, inArgument_name, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 272)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                Routine 'table_core'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_table_5F_core (GALGAS_string inArgument_typename,
                            GALGAS_string inArgument_varname,
                            GALGAS_string inArgument_obj_5F_prefix,
                            GALGAS_stringset inArgument_names,
                            GALGAS_string & ioArgument_header,
                            GALGAS_string & ioArgument_implementation,
                            C_Compiler * inCompiler
                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_uint var_n_8962 = GALGAS_uint ((uint32_t) 0U) ;
  cEnumerator_stringset enumerator_8999 (inArgument_names, kEnumeration_up) ;
  while (enumerator_8999.hasCurrentObject ()) {
    ioArgument_header = ioArgument_header.add_operation (GALGAS_string ("#define "), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 291)).add_operation (inArgument_varname, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 291)).add_operation (GALGAS_string ("_id_of_"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 291)).add_operation (enumerator_8999.current_key (HERE), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 291)).add_operation (GALGAS_string ("  "), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 291)).add_operation (var_n_8962.getter_string (SOURCE_FILE ("goil_routines.galgas", 291)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 291)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 291)) ;
    ioArgument_header = ioArgument_header.add_operation (GALGAS_string ("#define "), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 299)).add_operation (enumerator_8999.current_key (HERE), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 299)).add_operation (GALGAS_string ("  "), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 299)).add_operation (inArgument_varname, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 299)).add_operation (GALGAS_string ("_id_of_"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 299)).add_operation (enumerator_8999.current_key (HERE), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 299)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 299)) ;
    ioArgument_implementation = ioArgument_implementation.add_operation (GALGAS_string ("    (tpl_"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 300)).add_operation (inArgument_typename, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 300)).add_operation (GALGAS_string (" *)&"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 300)).add_operation (inArgument_obj_5F_prefix, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 300)).add_operation (enumerator_8999.current_key (HERE), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 300)) ;
    var_n_8962.increment_operation (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 301)) ;
    const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, var_n_8962.objectCompare (inArgument_names.getter_count (SOURCE_FILE ("goil_routines.galgas", 302)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      ioArgument_implementation = ioArgument_implementation.add_operation (GALGAS_string (",\n"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 303)) ;
    }else if (kBoolFalse == test_0) {
      ioArgument_implementation = ioArgument_implementation.add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 304)) ;
    }
    enumerator_8999.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             Routine 'add_to_stringset'                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_add_5F_to_5F_stringset (GALGAS_stringset & ioArgument_ss,
                                     GALGAS_string inArgument_new,
                                     C_Compiler * inCompiler
                                     COMMA_UNUSED_LOCATION_ARGS) {
  const enumGalgasBool test_0 = ioArgument_ss.getter_hasKey (inArgument_new COMMA_SOURCE_FILE ("goil_routines.galgas", 409)).boolEnum () ;
  if (kBoolTrue == test_0) {
    TC_Array <C_FixItDescription> fixItArray1 ;
    inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 410)), GALGAS_string ("'").add_operation (inArgument_new, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 410)).add_operation (GALGAS_string ("' is already declared before"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 410)), fixItArray1  COMMA_SOURCE_FILE ("goil_routines.galgas", 410)) ;
  }else if (kBoolFalse == test_0) {
    ioArgument_ss.addAssign_operation (inArgument_new  COMMA_SOURCE_FILE ("goil_routines.galgas", 412)) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Routine 'file_in_path'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_file_5F_in_5F_path (GALGAS_lstring & ioArgument_file_5F_name,
                                 C_Compiler * inCompiler
                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string var_include_5F_path_12819 = GALGAS_string::constructor_stringWithEnvironmentVariableOrEmpty (GALGAS_string ("GOIL_INCLUDE_PATH")  COMMA_SOURCE_FILE ("goil_routines.galgas", 418)) ;
  GALGAS_stringlist var_systemPaths_13034 = function_allTemplatePaths (GALGAS_string ("config"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 422)) ;
  GALGAS_stringlist var_includePathList_13096 ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, var_include_5F_path_12819.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
  if (kBoolTrue == test_0) {
    var_includePathList_13096 = var_include_5F_path_12819.getter_componentsSeparatedByString (GALGAS_string (":") COMMA_SOURCE_FILE ("goil_routines.galgas", 425)) ;
  }else if (kBoolFalse == test_0) {
    var_includePathList_13096 = GALGAS_stringlist::constructor_emptyList (SOURCE_FILE ("goil_routines.galgas", 427)) ;
  }
  GALGAS_stringlist var_path_5F_list_13290 = var_includePathList_13096.add_operation (var_systemPaths_13034, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 429)) ;
  GALGAS_bool var_not_5F_found_13343 = GALGAS_bool (true) ;
  cEnumerator_stringlist enumerator_13387 (var_path_5F_list_13290, kEnumeration_up) ;
  while (enumerator_13387.hasCurrentObject ()) {
    GALGAS_string var_full_5F_file_5F_path_13421 = enumerator_13387.current_mValue (HERE) ;
    const enumGalgasBool test_1 = GALGAS_bool (kIsNotEqual, var_full_5F_file_5F_path_13421.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
    if (kBoolTrue == test_1) {
      const enumGalgasBool test_2 = GALGAS_bool (kIsNotEqual, var_full_5F_file_5F_path_13421.getter_characterAtIndex (var_full_5F_file_5F_path_13421.getter_length (SOURCE_FILE ("goil_routines.galgas", 435)).substract_operation (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 435)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 435)).objectCompare (GALGAS_char (TO_UNICODE (47)))).boolEnum () ;
      if (kBoolTrue == test_2) {
        var_full_5F_file_5F_path_13421.plusAssign_operation(GALGAS_string ("/"), inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 436)) ;
      }
    }
    var_full_5F_file_5F_path_13421.plusAssign_operation(ioArgument_file_5F_name.getter_string (SOURCE_FILE ("goil_routines.galgas", 439)), inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 439)) ;
    const enumGalgasBool test_3 = var_full_5F_file_5F_path_13421.getter_fileExists (SOURCE_FILE ("goil_routines.galgas", 440)).operator_and (var_not_5F_found_13343 COMMA_SOURCE_FILE ("goil_routines.galgas", 440)).boolEnum () ;
    if (kBoolTrue == test_3) {
      ioArgument_file_5F_name = GALGAS_lstring::constructor_new (var_full_5F_file_5F_path_13421, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 441))  COMMA_SOURCE_FILE ("goil_routines.galgas", 441)) ;
      var_not_5F_found_13343 = GALGAS_bool (false) ;
    }
    enumerator_13387.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             Routine 'is_in_lstringlist'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_is_5F_in_5F_lstringlist (GALGAS_lstringlist inArgument_l,
                                      GALGAS_lstring inArgument_e,
                                      GALGAS_lstring & outArgument_f,
                                      GALGAS_bool & outArgument_p,
                                      C_Compiler * inCompiler
                                      COMMA_UNUSED_LOCATION_ARGS) {
  outArgument_f.drop () ; // Release 'out' argument
  outArgument_p.drop () ; // Release 'out' argument
  outArgument_p = GALGAS_bool (false) ;
  outArgument_f = GALGAS_lstring::constructor_new (GALGAS_string::makeEmptyString (), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 453))  COMMA_SOURCE_FILE ("goil_routines.galgas", 453)) ;
  cEnumerator_lstringlist enumerator_14030 (inArgument_l, kEnumeration_up) ;
  while (enumerator_14030.hasCurrentObject ()) {
    const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, enumerator_14030.current_mValue (HERE).getter_string (SOURCE_FILE ("goil_routines.galgas", 455)).objectCompare (inArgument_e.getter_string (SOURCE_FILE ("goil_routines.galgas", 455)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      outArgument_p = GALGAS_bool (true) ;
      outArgument_f = enumerator_14030.current_mValue (HERE) ;
    }
    enumerator_14030.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             Function 'isInLstringlist'                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool function_isInLstringlist (GALGAS_lstringlist inArgument_l,
                                      GALGAS_lstring inArgument_e,
                                      C_Compiler * /* inCompiler */
                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_p ; // Returned variable
  result_p = GALGAS_bool (false) ;
  cEnumerator_lstringlist enumerator_14228 (inArgument_l, kEnumeration_up) ;
  while (enumerator_14228.hasCurrentObject ()) {
    const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, enumerator_14228.current_mValue (HERE).getter_string (SOURCE_FILE ("goil_routines.galgas", 468)).objectCompare (inArgument_e.getter_string (SOURCE_FILE ("goil_routines.galgas", 468)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      result_p = GALGAS_bool (true) ;
    }
    enumerator_14228.gotoNextObject () ;
  }
//---
  return result_p ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_isInLstringlist [3] = {
  & kTypeDescriptor_GALGAS_lstringlist,
  & kTypeDescriptor_GALGAS_lstring,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_isInLstringlist (C_Compiler * inCompiler,
                                                                const cObjectArray & inEffectiveParameterArray,
                                                                const GALGAS_location & /* inErrorLocation */
                                                                COMMA_LOCATION_ARGS) {
  const GALGAS_lstringlist operand0 = GALGAS_lstringlist::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                         inCompiler
                                                                         COMMA_THERE) ;
  const GALGAS_lstring operand1 = GALGAS_lstring::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  return function_isInLstringlist (operand0,
                                   operand1,
                                   inCompiler
                                   COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_isInLstringlist ("isInLstringlist",
                                                                 functionWithGenericHeader_isInLstringlist,
                                                                 & kTypeDescriptor_GALGAS_bool,
                                                                 2,
                                                                 functionArgs_isInLstringlist) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Routine 'add_lstring_unique'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_add_5F_lstring_5F_unique (GALGAS_lstringlist & ioArgument_l,
                                       GALGAS_lstring inArgument_e,
                                       GALGAS_string inArgument_att,
                                       C_Compiler * inCompiler
                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool var_found_14388 ;
  GALGAS_lstring var_res_14403 ;
  {
  routine_is_5F_in_5F_lstringlist (ioArgument_l, inArgument_e, var_res_14403, var_found_14388, inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 480)) ;
  }
  const enumGalgasBool test_0 = var_found_14388.boolEnum () ;
  if (kBoolTrue == test_0) {
    TC_Array <C_FixItDescription> fixItArray1 ;
    inCompiler->emitSemanticError (inArgument_e.getter_location (SOURCE_FILE ("goil_routines.galgas", 482)), inArgument_att.add_operation (GALGAS_string (" "), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 482)).add_operation (inArgument_e.getter_string (SOURCE_FILE ("goil_routines.galgas", 482)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 482)).add_operation (GALGAS_string (" has already be listed"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 482)), fixItArray1  COMMA_SOURCE_FILE ("goil_routines.galgas", 482)) ;
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (var_res_14403.getter_location (SOURCE_FILE ("goil_routines.galgas", 483)), GALGAS_string ("was listed here"), fixItArray2  COMMA_SOURCE_FILE ("goil_routines.galgas", 483)) ;
  }else if (kBoolFalse == test_0) {
    ioArgument_l.addAssign_operation (inArgument_e  COMMA_SOURCE_FILE ("goil_routines.galgas", 485)) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Routine 'set_lstring_if_empty'                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_set_5F_lstring_5F_if_5F_empty (GALGAS_lstring & ioArgument_s,
                                            GALGAS_lstring inArgument_ns,
                                            GALGAS_string inArgument_att,
                                            C_Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) {
  const enumGalgasBool test_0 = GALGAS_bool (kIsEqual, ioArgument_s.getter_string (SOURCE_FILE ("goil_routines.galgas", 493)).objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
  if (kBoolTrue == test_0) {
    ioArgument_s = inArgument_ns ;
  }else if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray1 ;
    inCompiler->emitSemanticError (inArgument_ns.getter_location (SOURCE_FILE ("goil_routines.galgas", 496)), inArgument_att.add_operation (GALGAS_string (" Redefinition"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 496)), fixItArray1  COMMA_SOURCE_FILE ("goil_routines.galgas", 496)) ;
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (ioArgument_s.getter_location (SOURCE_FILE ("goil_routines.galgas", 497)), GALGAS_string ("was defined here"), fixItArray2  COMMA_SOURCE_FILE ("goil_routines.galgas", 497)) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Routine 'add_makefile_flag_if_not_empty'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_add_5F_makefile_5F_flag_5F_if_5F_not_5F_empty (GALGAS_string & ioArgument_receiver,
                                                            GALGAS_string inArgument_flag_5F_name,
                                                            GALGAS_string inArgument_flag_5F_value,
                                                            C_Compiler * inCompiler
                                                            COMMA_UNUSED_LOCATION_ARGS) {
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, inArgument_flag_5F_value.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
  if (kBoolTrue == test_0) {
    ioArgument_receiver.plusAssign_operation(inArgument_flag_5F_name.add_operation (GALGAS_string ("="), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 506)).add_operation (inArgument_flag_5F_value, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 506)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 506)), inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 506)) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Function 'lstringWith'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring function_lstringWith (GALGAS_string inArgument_s,
                                     C_Compiler * inCompiler
                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring result_r ; // Returned variable
  result_r = GALGAS_lstring::constructor_new (inArgument_s, GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 511))  COMMA_SOURCE_FILE ("goil_routines.galgas", 511)) ;
//---
  return result_r ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_lstringWith [2] = {
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_lstringWith (C_Compiler * inCompiler,
                                                            const cObjectArray & inEffectiveParameterArray,
                                                            const GALGAS_location & /* inErrorLocation */
                                                            COMMA_LOCATION_ARGS) {
  const GALGAS_string operand0 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_lstringWith (operand0,
                               inCompiler
                               COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_lstringWith ("lstringWith",
                                                             functionWithGenericHeader_lstringWith,
                                                             & kTypeDescriptor_GALGAS_lstring,
                                                             1,
                                                             functionArgs_lstringWith) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Function 'stripString'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_stripString (GALGAS_string inArgument_s,
                                    C_Compiler * inCompiler
                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_r ; // Returned variable
  const enumGalgasBool test_0 = GALGAS_bool (kIsStrictSup, inArgument_s.getter_length (SOURCE_FILE ("goil_routines.galgas", 515)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_uint var_first_15136 = GALGAS_uint ((uint32_t) 0U) ;
    GALGAS_uint var_last_15155 = inArgument_s.getter_length (SOURCE_FILE ("goil_routines.galgas", 517)) ;
    GALGAS_bool var_finished_15243 = GALGAS_bool (false) ;
    if (inArgument_s.getter_length (SOURCE_FILE ("goil_routines.galgas", 520)).isValid ()) {
      uint32_t variant_15260 = inArgument_s.getter_length (SOURCE_FILE ("goil_routines.galgas", 520)).uintValue () ;
      bool loop_15260 = true ;
      while (loop_15260) {
        loop_15260 = var_finished_15243.operator_not (SOURCE_FILE ("goil_routines.galgas", 521)).isValid () ;
        if (loop_15260) {
          loop_15260 = var_finished_15243.operator_not (SOURCE_FILE ("goil_routines.galgas", 521)).boolValue () ;
        }
        if (loop_15260 && (0 == variant_15260)) {
          loop_15260 = false ;
          inCompiler->loopRunTimeVariantError (SOURCE_FILE ("goil_routines.galgas", 520)) ;
        }
        if (loop_15260) {
          variant_15260 -- ;
          const enumGalgasBool test_1 = GALGAS_bool (kIsEqual, inArgument_s.getter_characterAtIndex (var_first_15136, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 522)).objectCompare (GALGAS_char (TO_UNICODE (32)))).boolEnum () ;
          if (kBoolTrue == test_1) {
            var_first_15136.increment_operation (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 523)) ;
            const enumGalgasBool test_2 = GALGAS_bool (kIsEqual, var_first_15136.objectCompare (inArgument_s.getter_length (SOURCE_FILE ("goil_routines.galgas", 524)))).boolEnum () ;
            if (kBoolTrue == test_2) {
              var_finished_15243 = GALGAS_bool (true) ;
            }
          }else if (kBoolFalse == test_1) {
            var_finished_15243 = GALGAS_bool (true) ;
          }
        }
      }
    }
    var_finished_15243 = GALGAS_bool (false) ;
    if (inArgument_s.getter_length (SOURCE_FILE ("goil_routines.galgas", 529)).isValid ()) {
      uint32_t variant_15545 = inArgument_s.getter_length (SOURCE_FILE ("goil_routines.galgas", 529)).uintValue () ;
      bool loop_15545 = true ;
      while (loop_15545) {
        loop_15545 = var_finished_15243.operator_not (SOURCE_FILE ("goil_routines.galgas", 530)).isValid () ;
        if (loop_15545) {
          loop_15545 = var_finished_15243.operator_not (SOURCE_FILE ("goil_routines.galgas", 530)).boolValue () ;
        }
        if (loop_15545 && (0 == variant_15545)) {
          loop_15545 = false ;
          inCompiler->loopRunTimeVariantError (SOURCE_FILE ("goil_routines.galgas", 529)) ;
        }
        if (loop_15545) {
          variant_15545 -- ;
          const enumGalgasBool test_3 = GALGAS_bool (kIsEqual, inArgument_s.getter_characterAtIndex (var_last_15155.substract_operation (GALGAS_uint ((uint32_t) 1U), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 531)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 531)).objectCompare (GALGAS_char (TO_UNICODE (32)))).boolEnum () ;
          if (kBoolTrue == test_3) {
            var_last_15155.decrement_operation (inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 532)) ;
            const enumGalgasBool test_4 = GALGAS_bool (kIsEqual, var_last_15155.objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
            if (kBoolTrue == test_4) {
              var_finished_15243 = GALGAS_bool (true) ;
            }
          }else if (kBoolFalse == test_3) {
            var_finished_15243 = GALGAS_bool (true) ;
          }
        }
      }
    }
    const enumGalgasBool test_5 = GALGAS_bool (kIsStrictInf, var_first_15136.objectCompare (var_last_15155)).boolEnum () ;
    if (kBoolTrue == test_5) {
      result_r = inArgument_s.getter_subString (var_first_15136, var_last_15155.substract_operation (var_first_15136, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 538)) COMMA_SOURCE_FILE ("goil_routines.galgas", 538)) ;
    }else if (kBoolFalse == test_5) {
      result_r = GALGAS_string::makeEmptyString () ;
    }
  }else if (kBoolFalse == test_0) {
    result_r = GALGAS_string::makeEmptyString () ;
  }
//---
  return result_r ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_stripString [2] = {
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_stripString (C_Compiler * inCompiler,
                                                            const cObjectArray & inEffectiveParameterArray,
                                                            const GALGAS_location & /* inErrorLocation */
                                                            COMMA_LOCATION_ARGS) {
  const GALGAS_string operand0 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_stripString (operand0,
                               inCompiler
                               COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_stripString ("stripString",
                                                             functionWithGenericHeader_stripString,
                                                             & kTypeDescriptor_GALGAS_string,
                                                             1,
                                                             functionArgs_stripString) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             Routine 'errorNoFileFound'                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_errorNoFileFound (const GALGAS_stringlist constinArgument_searchedPaths,
                               const GALGAS_string constinArgument_kind,
                               const GALGAS_lstring constinArgument_file,
                               C_Compiler * inCompiler
                               COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string var_m_16011 = GALGAS_string ("cannot find a valid path for the '").add_operation (constinArgument_file.getter_string (SOURCE_FILE ("goil_routines.galgas", 551)), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 551)).add_operation (GALGAS_string ("' "), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 551)).add_operation (constinArgument_kind, inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 551)).add_operation (GALGAS_string (" file. I have tried:"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 551)) ;
  cEnumerator_stringlist enumerator_16123 (constinArgument_searchedPaths, kEnumeration_up) ;
  while (enumerator_16123.hasCurrentObject ()) {
    var_m_16011.plusAssign_operation(GALGAS_string ("\n"
      "  - '").add_operation (enumerator_16123.current_mValue (HERE), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 553)).add_operation (GALGAS_string ("'"), inCompiler COMMA_SOURCE_FILE ("goil_routines.galgas", 553)), inCompiler  COMMA_SOURCE_FILE ("goil_routines.galgas", 553)) ;
    enumerator_16123.gotoNextObject () ;
  }
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (constinArgument_file.getter_location (SOURCE_FILE ("goil_routines.galgas", 555)), var_m_16011, fixItArray0  COMMA_SOURCE_FILE ("goil_routines.galgas", 555)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Function 'stringLBool'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string function_stringLBool (const GALGAS_lbool & constinArgument_boolValue,
                                    C_Compiler * /* inCompiler */
                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const enumGalgasBool test_0 = constinArgument_boolValue.getter_bool (SOURCE_FILE ("goil_routines.galgas", 561)).boolEnum () ;
  if (kBoolTrue == test_0) {
    result_result = GALGAS_string ("TRUE") ;
  }else if (kBoolFalse == test_0) {
    result_result = GALGAS_string ("FALSE") ;
  }
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_stringLBool [2] = {
  & kTypeDescriptor_GALGAS_lbool,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_stringLBool (C_Compiler * inCompiler,
                                                            const cObjectArray & inEffectiveParameterArray,
                                                            const GALGAS_location & /* inErrorLocation */
                                                            COMMA_LOCATION_ARGS) {
  const GALGAS_lbool operand0 = GALGAS_lbool::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                             inCompiler
                                                             COMMA_THERE) ;
  return function_stringLBool (operand0,
                               inCompiler
                               COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_stringLBool ("stringLBool",
                                                             functionWithGenericHeader_stringLBool,
                                                             & kTypeDescriptor_GALGAS_string,
                                                             1,
                                                             functionArgs_stringLBool) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                Routine 'setDefaults'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_setDefaults (const GALGAS_implementation constinArgument_imp,
                          GALGAS_applicationDefinition & ioArgument_application,
                          C_Compiler * inCompiler
                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_objectsMap var_objects_876 = ioArgument_application.getter_objects (SOURCE_FILE ("defaults.galgas", 32)) ;
  cEnumerator_lstringlist enumerator_980 (var_objects_876.getter_keyList (SOURCE_FILE ("defaults.galgas", 35)), kEnumeration_up) ;
  while (enumerator_980.hasCurrentObject ()) {
    cMapElement_objectsMap * objectArray_992 = (cMapElement_objectsMap *) var_objects_876.readWriteAccessForWithInstructionWithErrorMessage (inCompiler, enumerator_980.current_mValue (HERE), kSearchErrorMessage_objectsMap_get  COMMA_SOURCE_FILE ("defaults.galgas", 36)) ;
    if (NULL != objectArray_992) {
        macroValidSharedObject (objectArray_992, cMapElement_objectsMap) ;
      GALGAS_objectKindMap var_objOfKind_1069 = objectArray_992->mAttribute_objectsOfKind.getter_objects (SOURCE_FILE ("defaults.galgas", 37)) ;
      cEnumerator_lstringlist enumerator_1151 (var_objOfKind_1069.getter_keyList (SOURCE_FILE ("defaults.galgas", 38)), kEnumeration_up) ;
      while (enumerator_1151.hasCurrentObject ()) {
        cMapElement_objectKindMap * objectArray_1167 = (cMapElement_objectKindMap *) var_objOfKind_1069.readWriteAccessForWithInstructionWithErrorMessage (inCompiler, enumerator_1151.current_mValue (HERE), kSearchErrorMessage_objectKindMap_get  COMMA_SOURCE_FILE ("defaults.galgas", 39)) ;
        if (NULL != objectArray_1167) {
            macroValidSharedObject (objectArray_1167, cMapElement_objectKindMap) ;
          GALGAS_implementationObject var_impObject_1257 = callExtensionGetter_impObject ((const cPtr_implementation *) constinArgument_imp.ptr (), enumerator_980.current_mValue (HERE).getter_string (SOURCE_FILE ("defaults.galgas", 40)), inCompiler COMMA_SOURCE_FILE ("defaults.galgas", 40)) ;
          {
          routine_setDefaultsForType (var_impObject_1257.getter_attributes (SOURCE_FILE ("defaults.galgas", 41)), objectArray_1167->mAttribute_attributes, inCompiler  COMMA_SOURCE_FILE ("defaults.galgas", 41)) ;
          }
        }
        enumerator_1151.gotoNextObject () ;
      }
      {
      objectArray_992->mAttribute_objectsOfKind.setter_setObjects (var_objOfKind_1069 COMMA_SOURCE_FILE ("defaults.galgas", 44)) ;
      }
    }
    enumerator_980.gotoNextObject () ;
  }
  {
  ioArgument_application.setter_setObjects (var_objects_876 COMMA_SOURCE_FILE ("defaults.galgas", 48)) ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Function 'attributeAllowsAuto'                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool function_attributeAllowsAuto (const GALGAS_impType & constinArgument_type,
                                          C_Compiler * /* inCompiler */
                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_allowsAuto ; // Returned variable
  result_allowsAuto = GALGAS_bool (true) ;
  if (constinArgument_type.isValid ()) {
    if (NULL != dynamic_cast <const cPtr_impAutoDefaultType *> (constinArgument_type.ptr ())) {
      GALGAS_impAutoDefaultType cast_6562_autoType ((cPtr_impAutoDefaultType *) constinArgument_type.ptr ()) ;
      const enumGalgasBool test_0 = cast_6562_autoType.getter_withAuto (SOURCE_FILE ("semantic_verification.galgas", 225)).operator_not (SOURCE_FILE ("semantic_verification.galgas", 225)).boolEnum () ;
      if (kBoolTrue == test_0) {
        result_allowsAuto = GALGAS_bool (false) ;
      }
    }else{
      result_allowsAuto = GALGAS_bool (false) ;
    }
  }
//---
  return result_allowsAuto ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_attributeAllowsAuto [2] = {
  & kTypeDescriptor_GALGAS_impType,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_attributeAllowsAuto (C_Compiler * inCompiler,
                                                                    const cObjectArray & inEffectiveParameterArray,
                                                                    const GALGAS_location & /* inErrorLocation */
                                                                    COMMA_LOCATION_ARGS) {
  const GALGAS_impType operand0 = GALGAS_impType::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  return function_attributeAllowsAuto (operand0,
                                       inCompiler
                                       COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_attributeAllowsAuto ("attributeAllowsAuto",
                                                                     functionWithGenericHeader_attributeAllowsAuto,
                                                                     & kTypeDescriptor_GALGAS_bool,
                                                                     1,
                                                                     functionArgs_attributeAllowsAuto) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Routine 'verifyAllAttributes'                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_verifyAllAttributes (const GALGAS_implementation constinArgument_imp,
                                  const GALGAS_objectsMap constinArgument_objects,
                                  C_Compiler * inCompiler
                                  COMMA_UNUSED_LOCATION_ARGS) {
  cEnumerator_objectsMap enumerator_6874 (constinArgument_objects, kEnumeration_up) ;
  while (enumerator_6874.hasCurrentObject ()) {
    GALGAS_implementationObject var_impObj_6910 = callExtensionGetter_impObject ((const cPtr_implementation *) constinArgument_imp.ptr (), enumerator_6874.current_lkey (HERE).getter_string (SOURCE_FILE ("semantic_verification.galgas", 242)), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 242)) ;
    cEnumerator_objectKindMap enumerator_7042 (enumerator_6874.current_objectsOfKind (HERE).getter_objects (SOURCE_FILE ("semantic_verification.galgas", 244)), kEnumeration_up) ;
    while (enumerator_7042.hasCurrentObject ()) {
      cEnumerator_implementationObjectMap enumerator_7087 (var_impObj_6910.getter_attributes (SOURCE_FILE ("semantic_verification.galgas", 245)), kEnumeration_up) ;
      while (enumerator_7087.hasCurrentObject ()) {
        const enumGalgasBool test_0 = enumerator_7042.current_attributes (HERE).getter_objectParams (SOURCE_FILE ("semantic_verification.galgas", 246)).getter_hasKey (enumerator_7087.current_lkey (HERE).getter_string (SOURCE_FILE ("semantic_verification.galgas", 246)) COMMA_SOURCE_FILE ("semantic_verification.galgas", 246)).boolEnum () ;
        if (kBoolTrue == test_0) {
          GALGAS_object_5F_t var_value_7288 ;
          enumerator_7042.current_attributes (HERE).getter_objectParams (SOURCE_FILE ("semantic_verification.galgas", 250)).method_get (enumerator_7087.current_lkey (HERE), var_value_7288, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 250)) ;
          if (var_value_7288.isValid ()) {
            if (var_value_7288.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_auto) {
              const enumGalgasBool test_1 = function_attributeAllowsAuto (enumerator_7087.current_type (HERE), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 254)).operator_not (SOURCE_FILE ("semantic_verification.galgas", 254)).boolEnum () ;
              if (kBoolTrue == test_1) {
                TC_Array <C_FixItDescription> fixItArray2 ;
                inCompiler->emitSemanticError (var_value_7288.getter_location (SOURCE_FILE ("semantic_verification.galgas", 255)), GALGAS_string ("AUTO value is not allowed for the ").add_operation (enumerator_6874.current_lkey (HERE).getter_string (SOURCE_FILE ("semantic_verification.galgas", 255)), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 255)).add_operation (GALGAS_string (" attribute"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 255)), fixItArray2  COMMA_SOURCE_FILE ("semantic_verification.galgas", 255)) ;
              }
            }
          }
        }else if (kBoolFalse == test_0) {
          const enumGalgasBool test_3 = function_attributeAllowsAuto (enumerator_7087.current_type (HERE), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 260)).operator_not (SOURCE_FILE ("semantic_verification.galgas", 260)).operator_and (enumerator_7087.current_type (HERE).getter_multiple (SOURCE_FILE ("semantic_verification.galgas", 260)).operator_not (SOURCE_FILE ("semantic_verification.galgas", 260)) COMMA_SOURCE_FILE ("semantic_verification.galgas", 260)).boolEnum () ;
          if (kBoolTrue == test_3) {
            TC_Array <C_FixItDescription> fixItArray4 ;
            inCompiler->emitSemanticError (enumerator_7042.current_lkey (HERE).getter_location (SOURCE_FILE ("semantic_verification.galgas", 261)), GALGAS_string ("In ").add_operation (enumerator_6874.current_lkey (HERE).getter_string (SOURCE_FILE ("semantic_verification.galgas", 261)), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 261)).add_operation (GALGAS_string (" "), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 261)).add_operation (enumerator_7042.current_lkey (HERE).getter_string (SOURCE_FILE ("semantic_verification.galgas", 261)), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 261)).add_operation (GALGAS_string (", attribute "), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 261)).add_operation (enumerator_7087.current_lkey (HERE).getter_string (SOURCE_FILE ("semantic_verification.galgas", 261)), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 261)).add_operation (GALGAS_string (" is not defined and is not AUTO"), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 261)), fixItArray4  COMMA_SOURCE_FILE ("semantic_verification.galgas", 261)) ;
          }
        }
        if (enumerator_7087.current_type (HERE).isValid ()) {
          if (enumerator_7087.current_type (HERE).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_impAutoDefaultType) {
          }
        }
        enumerator_7087.gotoNextObject () ;
      }
      enumerator_7042.gotoNextObject () ;
    }
    enumerator_6874.gotoNextObject () ;
  }
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 Routine 'verifyAll'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_verifyAll (const GALGAS_implementation constinArgument_imp,
                        const GALGAS_applicationDefinition constinArgument_application,
                        C_Compiler * inCompiler
                        COMMA_UNUSED_LOCATION_ARGS) {
  {
  routine_verifyAllAttributes (constinArgument_imp, constinArgument_application.getter_objects (SOURCE_FILE ("semantic_verification.galgas", 681)), inCompiler  COMMA_SOURCE_FILE ("semantic_verification.galgas", 681)) ;
  }
  callExtensionMethod_verifyApplication ((const cPtr_implementation *) constinArgument_imp.ptr (), constinArgument_application, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 682)) ;
  callExtensionMethod_verifyCrossReferences ((const cPtr_applicationDefinition *) constinArgument_application.ptr (), constinArgument_imp, inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 685)) ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Function 'emptyApplicationDefinition'                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_applicationDefinition function_emptyApplicationDefinition (C_Compiler * inCompiler
                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_applicationDefinition result_result ; // Returned variable
  result_result = GALGAS_applicationDefinition::constructor_new (function_emptyLString (inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 56)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 57)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 58)), function_emptyLString (inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 59)), GALGAS_objectsMap::constructor_emptyMap (SOURCE_FILE ("goil_types_root.galgas", 60))  COMMA_SOURCE_FILE ("goil_types_root.galgas", 55)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_emptyApplicationDefinition [1] = {
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_emptyApplicationDefinition (C_Compiler * inCompiler,
                                                                           const cObjectArray & /* inEffectiveParameterArray */,
                                                                           const GALGAS_location & /* inErrorLocation */
                                                                           COMMA_LOCATION_ARGS) {
  return function_emptyApplicationDefinition (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_emptyApplicationDefinition ("emptyApplicationDefinition",
                                                                            functionWithGenericHeader_emptyApplicationDefinition,
                                                                            & kTypeDescriptor_GALGAS_applicationDefinition,
                                                                            0,
                                                                            functionArgs_emptyApplicationDefinition) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 Function 'osObject'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectAttributes function_osObject (const GALGAS_objectsMap & constinArgument_objects,
                                           C_Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_objectAttributes result_os ; // Returned variable
  GALGAS_objectKind var_objectsForKind_1623 ;
  constinArgument_objects.method_get (function_lstringWith (GALGAS_string ("OS"), inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 67)), var_objectsForKind_1623, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 67)) ;
  GALGAS_lstringlist var_names_1696 = var_objectsForKind_1623.getter_objects (SOURCE_FILE ("goil_types_root.galgas", 68)).getter_keyList (SOURCE_FILE ("goil_types_root.galgas", 68)) ;
  GALGAS_lstring var_name_1749 ;
  var_names_1696.method_first (var_name_1749, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 70)) ;
  var_objectsForKind_1623.getter_objects (SOURCE_FILE ("goil_types_root.galgas", 71)).method_get (var_name_1749, result_os, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 71)) ;
//---
  return result_os ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_osObject [2] = {
  & kTypeDescriptor_GALGAS_objectsMap,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_osObject (C_Compiler * inCompiler,
                                                         const cObjectArray & inEffectiveParameterArray,
                                                         const GALGAS_location & /* inErrorLocation */
                                                         COMMA_LOCATION_ARGS) {
  const GALGAS_objectsMap operand0 = GALGAS_objectsMap::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                       inCompiler
                                                                       COMMA_THERE) ;
  return function_osObject (operand0,
                            inCompiler
                            COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_osObject ("osObject",
                                                          functionWithGenericHeader_osObject,
                                                          & kTypeDescriptor_GALGAS_objectAttributes,
                                                          1,
                                                          functionArgs_osObject) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Function 'objectForKindAndName'                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectAttributes function_objectForKindAndName (const GALGAS_objectsMap & constinArgument_objects,
                                                       const GALGAS_string & constinArgument_kind,
                                                       const GALGAS_string & constinArgument_name,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_objectAttributes result_object ; // Returned variable
  const enumGalgasBool test_0 = constinArgument_objects.getter_hasKey (constinArgument_kind COMMA_SOURCE_FILE ("goil_types_root.galgas", 79)).boolEnum () ;
  if (kBoolTrue == test_0) {
    GALGAS_objectKind var_kindObj_1998 ;
    constinArgument_objects.method_get (function_lstringWith (constinArgument_kind, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 81)), var_kindObj_1998, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 81)) ;
    const enumGalgasBool test_1 = var_kindObj_1998.getter_objects (SOURCE_FILE ("goil_types_root.galgas", 82)).getter_hasKey (constinArgument_name COMMA_SOURCE_FILE ("goil_types_root.galgas", 82)).boolEnum () ;
    if (kBoolTrue == test_1) {
      var_kindObj_1998.getter_objects (SOURCE_FILE ("goil_types_root.galgas", 83)).method_get (function_lstringWith (constinArgument_name, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 83)), result_object, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 83)) ;
    }else if (kBoolFalse == test_1) {
      result_object = GALGAS_objectAttributes::constructor_new (GALGAS_identifierMap::constructor_emptyMap (SOURCE_FILE ("goil_types_root.galgas", 85))  COMMA_SOURCE_FILE ("goil_types_root.galgas", 85)) ;
    }
  }else if (kBoolFalse == test_0) {
    result_object = GALGAS_objectAttributes::constructor_new (GALGAS_identifierMap::constructor_emptyMap (SOURCE_FILE ("goil_types_root.galgas", 88))  COMMA_SOURCE_FILE ("goil_types_root.galgas", 88)) ;
  }
//---
  return result_object ;
}


//---------------------------------------------------------------------------------------------------------------------*
//  Function introspection                                                                                             *
//---------------------------------------------------------------------------------------------------------------------*

static const C_galgas_type_descriptor * functionArgs_objectForKindAndName [4] = {
  & kTypeDescriptor_GALGAS_objectsMap,
  & kTypeDescriptor_GALGAS_string,
  & kTypeDescriptor_GALGAS_string,
  NULL
} ;

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_object functionWithGenericHeader_objectForKindAndName (C_Compiler * inCompiler,
                                                                     const cObjectArray & inEffectiveParameterArray,
                                                                     const GALGAS_location & /* inErrorLocation */
                                                                     COMMA_LOCATION_ARGS) {
  const GALGAS_objectsMap operand0 = GALGAS_objectsMap::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                       inCompiler
                                                                       COMMA_THERE) ;
  const GALGAS_string operand1 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  const GALGAS_string operand2 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (2 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_objectForKindAndName (operand0,
                                        operand1,
                                        operand2,
                                        inCompiler
                                        COMMA_THERE).getter_object (THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_galgas_function_descriptor functionDescriptor_objectForKindAndName ("objectForKindAndName",
                                                                      functionWithGenericHeader_objectForKindAndName,
                                                                      & kTypeDescriptor_GALGAS_objectAttributes,
                                                                      3,
                                                                      functionArgs_objectForKindAndName) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          Routine 'setObjectForKindAndName'                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_setObjectForKindAndName (GALGAS_objectsMap & ioArgument_objects,
                                      const GALGAS_string constinArgument_kind,
                                      const GALGAS_string constinArgument_name,
                                      const GALGAS_objectAttributes constinArgument_object,
                                      C_Compiler * inCompiler
                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring var_lkind_2457 = function_lstringWith (constinArgument_kind, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 97)) ;
  GALGAS_lstring var_lname_2495 = function_lstringWith (constinArgument_name, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 98)) ;
  GALGAS_objectKind var_kindObj_2538 = GALGAS_objectKind::constructor_new (GALGAS_objectKindMap::constructor_emptyMap (SOURCE_FILE ("goil_types_root.galgas", 99))  COMMA_SOURCE_FILE ("goil_types_root.galgas", 99)) ;
  const enumGalgasBool test_0 = ioArgument_objects.getter_hasKey (constinArgument_kind COMMA_SOURCE_FILE ("goil_types_root.galgas", 100)).boolEnum () ;
  if (kBoolTrue == test_0) {
    {
    ioArgument_objects.setter_del (var_lkind_2457, var_kindObj_2538, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 101)) ;
    }
  }
  GALGAS_objectKindMap var_kindMap_2686 = var_kindObj_2538.getter_objects (SOURCE_FILE ("goil_types_root.galgas", 103)) ;
  const enumGalgasBool test_1 = var_kindMap_2686.getter_hasKey (constinArgument_name COMMA_SOURCE_FILE ("goil_types_root.galgas", 104)).boolEnum () ;
  if (kBoolTrue == test_1) {
    {
    GALGAS_objectAttributes joker_2767 ; // Joker input parameter
    var_kindMap_2686.setter_del (var_lname_2495, joker_2767, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 105)) ;
    }
  }
  {
  var_kindMap_2686.setter_put (var_lname_2495, constinArgument_object, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 107)) ;
  }
  {
  var_kindObj_2538.setter_setObjects (var_kindMap_2686 COMMA_SOURCE_FILE ("goil_types_root.galgas", 108)) ;
  }
  {
  ioArgument_objects.setter_put (var_lkind_2457, var_kindObj_2538, inCompiler COMMA_SOURCE_FILE ("goil_types_root.galgas", 109)) ;
  }
}


