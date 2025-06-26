#include "Compiler.h"
#include "C_galgas_io.h"
#include "C_galgas_CLI_Options.h"
#include "PrologueEpilogue.h"

//--------------------------------------------------------------------------------------------------

#include "all-declarations-8.h"

//--------------------------------------------------------------------------------------------------

#include "MF_MemoryControl.h"
#include "C_galgas_CLI_Options.h"

#include "FileManager.h"

//--------------------------------------------------------------------------------------------------


//--------------------------------------------------------------------------------------------------
//
//                                     LL(1) PRODUCTION RULES                                       
//
//--------------------------------------------------------------------------------------------------

static const int32_t gProductions_gtl_grammar [] = {
// At index 0 : <gtl_expression>, in file 'gtl_expression_parser.ggs', line 33
  TOP_DOWN_NONTERMINAL (10) // <gtl_relation_term>
, TOP_DOWN_NONTERMINAL (42) // <select_gtl_5F_expression_5F_parser_0>
, TOP_DOWN_END_PRODUCTION ()
// At index 3 : <gtl_variable>, in file 'gtl_expression_parser.ggs', line 687
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, TOP_DOWN_NONTERMINAL (63) // <select_gtl_5F_expression_5F_parser_21>
, TOP_DOWN_NONTERMINAL (62) // <select_gtl_5F_expression_5F_parser_20>
, TOP_DOWN_END_PRODUCTION ()
// At index 7 : <gtl_variable_or_here>, in file 'gtl_expression_parser.ggs', line 722
, TOP_DOWN_NONTERMINAL (66) // <select_gtl_5F_expression_5F_parser_24>
, TOP_DOWN_END_PRODUCTION ()
// At index 9 : <gtl_import>, in file 'gtl_instruction_parser.ggs', line 368
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_import) // $import$
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_string) // $string$
, TOP_DOWN_END_PRODUCTION ()
// At index 12 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 40
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_let) // $let$
, TOP_DOWN_NONTERMINAL (1) // <gtl_variable>
, TOP_DOWN_NONTERMINAL (70) // <select_gtl_5F_instruction_5F_parser_0>
, TOP_DOWN_END_PRODUCTION ()
// At index 16 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 154
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_unlet) // $unlet$
, TOP_DOWN_NONTERMINAL (1) // <gtl_variable>
, TOP_DOWN_END_PRODUCTION ()
// At index 19 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 167
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_error) // $error$
, TOP_DOWN_NONTERMINAL (2) // <gtl_variable_or_here>
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__3A_) // $:$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_END_PRODUCTION ()
// At index 24 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 185
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_warning) // $warning$
, TOP_DOWN_NONTERMINAL (2) // <gtl_variable_or_here>
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__3A_) // $:$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_END_PRODUCTION ()
// At index 29 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 203
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_print) // $print$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_END_PRODUCTION ()
// At index 32 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 218
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_println) // $println$
, TOP_DOWN_NONTERMINAL (71) // <select_gtl_5F_instruction_5F_parser_1>
, TOP_DOWN_END_PRODUCTION ()
// At index 35 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 241
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_display) // $display$
, TOP_DOWN_NONTERMINAL (1) // <gtl_variable>
, TOP_DOWN_END_PRODUCTION ()
// At index 38 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 256
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_sort) // $sort$
, TOP_DOWN_NONTERMINAL (1) // <gtl_variable>
, TOP_DOWN_NONTERMINAL (72) // <select_gtl_5F_instruction_5F_parser_2>
, TOP_DOWN_END_PRODUCTION ()
// At index 42 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 289
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_tab) // $tab$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_END_PRODUCTION ()
// At index 45 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 303
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_variables) // $variables$
, TOP_DOWN_END_PRODUCTION ()
// At index 47 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 315
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_libraries) // $libraries$
, TOP_DOWN_END_PRODUCTION ()
// At index 49 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 326
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__5B__21_) // $[!$
, TOP_DOWN_NONTERMINAL (1) // <gtl_variable>
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, TOP_DOWN_NONTERMINAL (74) // <select_gtl_5F_instruction_5F_parser_4>
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__5D_) // $]$
, TOP_DOWN_END_PRODUCTION ()
// At index 55 : <gtl_argument_list>, in file 'gtl_expression_parser.ggs', line 736
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__28_) // $($
, TOP_DOWN_NONTERMINAL (67) // <select_gtl_5F_expression_5F_parser_25>
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__29_) // $)$
, TOP_DOWN_END_PRODUCTION ()
// At index 59 : <gtl_start_symbol>, in file 'gtl_parser.ggs', line 50
, TOP_DOWN_NONTERMINAL (16) // <select_gtl_5F_parser_0>
, TOP_DOWN_NONTERMINAL (7) // <gtl_template_instruction_list>
, TOP_DOWN_END_PRODUCTION ()
// At index 62 : <gtl_template_instruction_list>, in file 'gtl_parser.ggs', line 63
, TOP_DOWN_NONTERMINAL (17) // <select_gtl_5F_parser_1>
, TOP_DOWN_END_PRODUCTION ()
// At index 64 : <gtl_template_instruction>, in file 'gtl_parser.ggs', line 90
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__21_) // $!$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_END_PRODUCTION ()
// At index 67 : <gtl_template_instruction>, in file 'gtl_parser.ggs', line 108
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_write) // $write$
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_to) // $to$
, TOP_DOWN_NONTERMINAL (18) // <select_gtl_5F_parser_2>
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__3A_) // $:$
, TOP_DOWN_NONTERMINAL (7) // <gtl_template_instruction_list>
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_end) // $end$
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_write) // $write$
, TOP_DOWN_END_PRODUCTION ()
// At index 76 : <gtl_template_instruction>, in file 'gtl_parser.ggs', line 128
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_template) // $template$
, TOP_DOWN_NONTERMINAL (19) // <select_gtl_5F_parser_3>
, TOP_DOWN_NONTERMINAL (22) // <select_gtl_5F_parser_6>
, TOP_DOWN_END_PRODUCTION ()
// At index 80 : <gtl_template_instruction>, in file 'gtl_parser.ggs', line 183
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__3F_) // $?$
, TOP_DOWN_NONTERMINAL (1) // <gtl_variable>
, TOP_DOWN_END_PRODUCTION ()
// At index 83 : <gtl_template_instruction>, in file 'gtl_parser.ggs', line 196
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_if) // $if$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_then) // $then$
, TOP_DOWN_NONTERMINAL (7) // <gtl_template_instruction_list>
, TOP_DOWN_NONTERMINAL (26) // <select_gtl_5F_parser_10>
, TOP_DOWN_NONTERMINAL (27) // <select_gtl_5F_parser_11>
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_end) // $end$
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_if) // $if$
, TOP_DOWN_END_PRODUCTION ()
// At index 92 : <gtl_template_instruction>, in file 'gtl_parser.ggs', line 228
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_foreach) // $foreach$
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, TOP_DOWN_NONTERMINAL (28) // <select_gtl_5F_parser_12>
, TOP_DOWN_NONTERMINAL (29) // <select_gtl_5F_parser_13>
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_in) // $in$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_NONTERMINAL (30) // <select_gtl_5F_parser_14>
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_do) // $do$
, TOP_DOWN_NONTERMINAL (7) // <gtl_template_instruction_list>
, TOP_DOWN_NONTERMINAL (31) // <select_gtl_5F_parser_15>
, TOP_DOWN_NONTERMINAL (32) // <select_gtl_5F_parser_16>
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_end) // $end$
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_foreach) // $foreach$
, TOP_DOWN_END_PRODUCTION ()
// At index 106 : <gtl_template_instruction>, in file 'gtl_parser.ggs', line 289
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_for) // $for$
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_in) // $in$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_NONTERMINAL (33) // <select_gtl_5F_parser_17>
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_do) // $do$
, TOP_DOWN_NONTERMINAL (7) // <gtl_template_instruction_list>
, TOP_DOWN_NONTERMINAL (34) // <select_gtl_5F_parser_18>
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_end) // $end$
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_for) // $for$
, TOP_DOWN_END_PRODUCTION ()
// At index 117 : <gtl_template_instruction>, in file 'gtl_parser.ggs', line 331
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_loop) // $loop$
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_from) // $from$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_NONTERMINAL (35) // <select_gtl_5F_parser_19>
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_to) // $to$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_NONTERMINAL (36) // <select_gtl_5F_parser_20>
, TOP_DOWN_NONTERMINAL (37) // <select_gtl_5F_parser_21>
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_do) // $do$
, TOP_DOWN_NONTERMINAL (7) // <gtl_template_instruction_list>
, TOP_DOWN_NONTERMINAL (38) // <select_gtl_5F_parser_22>
, TOP_DOWN_NONTERMINAL (39) // <select_gtl_5F_parser_23>
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_end) // $end$
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_loop) // $loop$
, TOP_DOWN_END_PRODUCTION ()
// At index 133 : <gtl_template_instruction>, in file 'gtl_parser.ggs', line 397
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_repeat) // $repeat$
, TOP_DOWN_NONTERMINAL (40) // <select_gtl_5F_parser_24>
, TOP_DOWN_NONTERMINAL (7) // <gtl_template_instruction_list>
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_while) // $while$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_do) // $do$
, TOP_DOWN_NONTERMINAL (7) // <gtl_template_instruction_list>
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_end) // $end$
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_repeat) // $repeat$
, TOP_DOWN_END_PRODUCTION ()
// At index 143 : <gtl_template_instruction>, in file 'gtl_parser.ggs', line 430
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_input) // $input$
, TOP_DOWN_NONTERMINAL (5) // <gtl_argument_list>
, TOP_DOWN_END_PRODUCTION ()
// At index 146 : <gtl_file_name>, in file 'gtl_parser.ggs', line 443
, TOP_DOWN_NONTERMINAL (41) // <select_gtl_5F_parser_25>
, TOP_DOWN_END_PRODUCTION ()
// At index 148 : <gtl_relation_term>, in file 'gtl_expression_parser.ggs', line 53
, TOP_DOWN_NONTERMINAL (11) // <gtl_relation_factor>
, TOP_DOWN_NONTERMINAL (43) // <select_gtl_5F_expression_5F_parser_1>
, TOP_DOWN_END_PRODUCTION ()
// At index 151 : <gtl_relation_factor>, in file 'gtl_expression_parser.ggs', line 69
, TOP_DOWN_NONTERMINAL (12) // <gtl_simple_expression>
, TOP_DOWN_NONTERMINAL (44) // <select_gtl_5F_expression_5F_parser_2>
, TOP_DOWN_END_PRODUCTION ()
// At index 154 : <gtl_simple_expression>, in file 'gtl_expression_parser.ggs', line 117
, TOP_DOWN_NONTERMINAL (13) // <gtl_term>
, TOP_DOWN_NONTERMINAL (45) // <select_gtl_5F_expression_5F_parser_3>
, TOP_DOWN_END_PRODUCTION ()
// At index 157 : <gtl_term>, in file 'gtl_expression_parser.ggs', line 162
, TOP_DOWN_NONTERMINAL (14) // <gtl_factor>
, TOP_DOWN_NONTERMINAL (46) // <select_gtl_5F_expression_5F_parser_4>
, TOP_DOWN_END_PRODUCTION ()
// At index 160 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 192
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__28_) // $($
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__29_) // $)$
, TOP_DOWN_END_PRODUCTION ()
// At index 164 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 208
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_not) // $not$
, TOP_DOWN_NONTERMINAL (14) // <gtl_factor>
, TOP_DOWN_END_PRODUCTION ()
// At index 167 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 220
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__7E_) // $~$
, TOP_DOWN_NONTERMINAL (14) // <gtl_factor>
, TOP_DOWN_END_PRODUCTION ()
// At index 170 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 232
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__2D_) // $-$
, TOP_DOWN_NONTERMINAL (14) // <gtl_factor>
, TOP_DOWN_END_PRODUCTION ()
// At index 173 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 244
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__2B_) // $+$
, TOP_DOWN_NONTERMINAL (14) // <gtl_factor>
, TOP_DOWN_END_PRODUCTION ()
// At index 176 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 256
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_yes) // $yes$
, TOP_DOWN_END_PRODUCTION ()
// At index 178 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 269
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_no) // $no$
, TOP_DOWN_END_PRODUCTION ()
// At index 180 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 282
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint) // $signed_literal_integer_bigint$
, TOP_DOWN_END_PRODUCTION ()
// At index 182 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 295
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_literal_5F_double) // $literal_double$
, TOP_DOWN_END_PRODUCTION ()
// At index 184 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 308
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_string) // $string$
, TOP_DOWN_END_PRODUCTION ()
// At index 186 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 321
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_literal_5F_char) // $literal_char$
, TOP_DOWN_END_PRODUCTION ()
// At index 188 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 335
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__5B_) // $[$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, TOP_DOWN_NONTERMINAL (47) // <select_gtl_5F_expression_5F_parser_5>
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__5D_) // $]$
, TOP_DOWN_END_PRODUCTION ()
// At index 194 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 369
, TOP_DOWN_NONTERMINAL (1) // <gtl_variable>
, TOP_DOWN_NONTERMINAL (49) // <select_gtl_5F_expression_5F_parser_7>
, TOP_DOWN_END_PRODUCTION ()
// At index 197 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 401
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_exists) // $exists$
, TOP_DOWN_NONTERMINAL (1) // <gtl_variable>
, TOP_DOWN_NONTERMINAL (52) // <select_gtl_5F_expression_5F_parser_10>
, TOP_DOWN_END_PRODUCTION ()
// At index 201 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 420
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_typeof) // $typeof$
, TOP_DOWN_NONTERMINAL (1) // <gtl_variable>
, TOP_DOWN_END_PRODUCTION ()
// At index 204 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 429
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_true) // $true$
, TOP_DOWN_END_PRODUCTION ()
// At index 206 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 445
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_false) // $false$
, TOP_DOWN_END_PRODUCTION ()
// At index 208 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 461
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_literal_5F_enum) // $literal_enum$
, TOP_DOWN_END_PRODUCTION ()
// At index 210 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 477
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__40_) // $@$
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, TOP_DOWN_END_PRODUCTION ()
// At index 213 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 514
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_emptylist) // $emptylist$
, TOP_DOWN_END_PRODUCTION ()
// At index 215 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 533
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_emptymap) // $emptymap$
, TOP_DOWN_END_PRODUCTION ()
// At index 217 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 552
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_mapof) // $mapof$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_NONTERMINAL (53) // <select_gtl_5F_expression_5F_parser_11>
, TOP_DOWN_END_PRODUCTION ()
// At index 221 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 576
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_listof) // $listof$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_end) // $end$
, TOP_DOWN_END_PRODUCTION ()
// At index 225 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 587
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__40__28_) // $@($
, TOP_DOWN_NONTERMINAL (54) // <select_gtl_5F_expression_5F_parser_12>
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__29_) // $)$
, TOP_DOWN_END_PRODUCTION ()
// At index 229 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 606
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__40__5B_) // $@[$
, TOP_DOWN_NONTERMINAL (56) // <select_gtl_5F_expression_5F_parser_14>
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__5D_) // $]$
, TOP_DOWN_END_PRODUCTION ()
// At index 233 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 627
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__40__7B_) // $@{$
, TOP_DOWN_NONTERMINAL (58) // <select_gtl_5F_expression_5F_parser_16>
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__7D_) // $}$
, TOP_DOWN_END_PRODUCTION ()
// At index 237 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 648
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__40__21_) // $@!$
, TOP_DOWN_NONTERMINAL (60) // <select_gtl_5F_expression_5F_parser_18>
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__21_) // $!$
, TOP_DOWN_END_PRODUCTION ()
// At index 241 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 667
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__40__3F_) // $@?$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__3F_) // $?$
, TOP_DOWN_END_PRODUCTION ()
// At index 245 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 678
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__5F__5F_VARS_5F__5F_) // $__VARS__$
, TOP_DOWN_END_PRODUCTION ()
// At index 247 : <gtl_sorting_order>, in file 'gtl_instruction_parser.ggs', line 355
, TOP_DOWN_NONTERMINAL (76) // <select_gtl_5F_instruction_5F_parser_6>
, TOP_DOWN_END_PRODUCTION ()
//---- Added productions from 'select' and 'repeat' instructions
// At index 249 : <select_gtl_5F_parser_0>, in file 'gtl_parser.ggs', line 55
, TOP_DOWN_END_PRODUCTION ()
// At index 250 : <select_gtl_5F_parser_0>, in file 'gtl_parser.ggs', line 55
, TOP_DOWN_NONTERMINAL (3) // <gtl_import>
, TOP_DOWN_NONTERMINAL (16) // <select_gtl_5F_parser_0>
, TOP_DOWN_END_PRODUCTION ()
// At index 253 : <select_gtl_5F_parser_1>, in file 'gtl_parser.ggs', line 67
, TOP_DOWN_END_PRODUCTION ()
// At index 254 : <select_gtl_5F_parser_1>, in file 'gtl_parser.ggs', line 67
, TOP_DOWN_NONTERMINAL (8) // <gtl_template_instruction>
, TOP_DOWN_NONTERMINAL (17) // <select_gtl_5F_parser_1>
, TOP_DOWN_END_PRODUCTION ()
// At index 257 : <select_gtl_5F_parser_1>, in file 'gtl_parser.ggs', line 67
, TOP_DOWN_NONTERMINAL (4) // <gtl_simple_instruction>
, TOP_DOWN_NONTERMINAL (17) // <select_gtl_5F_parser_1>
, TOP_DOWN_END_PRODUCTION ()
// At index 260 : <select_gtl_5F_parser_2>, in file 'gtl_parser.ggs', line 112
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_executable) // $executable$
, TOP_DOWN_END_PRODUCTION ()
// At index 262 : <select_gtl_5F_parser_2>, in file 'gtl_parser.ggs', line 112
, TOP_DOWN_END_PRODUCTION ()
// At index 263 : <select_gtl_5F_parser_3>, in file 'gtl_parser.ggs', line 138
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__28_) // $($
, TOP_DOWN_NONTERMINAL (20) // <select_gtl_5F_parser_4>
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__29_) // $)$
, TOP_DOWN_END_PRODUCTION ()
// At index 267 : <select_gtl_5F_parser_3>, in file 'gtl_parser.ggs', line 138
, TOP_DOWN_END_PRODUCTION ()
// At index 268 : <select_gtl_5F_parser_4>, in file 'gtl_parser.ggs', line 141
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_NONTERMINAL (21) // <select_gtl_5F_parser_5>
, TOP_DOWN_END_PRODUCTION ()
// At index 271 : <select_gtl_5F_parser_4>, in file 'gtl_parser.ggs', line 141
, TOP_DOWN_END_PRODUCTION ()
// At index 272 : <select_gtl_5F_parser_5>, in file 'gtl_parser.ggs', line 142
, TOP_DOWN_END_PRODUCTION ()
// At index 273 : <select_gtl_5F_parser_5>, in file 'gtl_parser.ggs', line 142
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__2C_) // $,$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_NONTERMINAL (21) // <select_gtl_5F_parser_5>
, TOP_DOWN_END_PRODUCTION ()
// At index 277 : <select_gtl_5F_parser_6>, in file 'gtl_parser.ggs', line 152
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_if) // $if$
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_exists) // $exists$
, TOP_DOWN_NONTERMINAL (9) // <gtl_file_name>
, TOP_DOWN_NONTERMINAL (23) // <select_gtl_5F_parser_7>
, TOP_DOWN_NONTERMINAL (24) // <select_gtl_5F_parser_8>
, TOP_DOWN_END_PRODUCTION ()
// At index 283 : <select_gtl_5F_parser_6>, in file 'gtl_parser.ggs', line 152
, TOP_DOWN_NONTERMINAL (9) // <gtl_file_name>
, TOP_DOWN_NONTERMINAL (25) // <select_gtl_5F_parser_9>
, TOP_DOWN_END_PRODUCTION ()
// At index 286 : <select_gtl_5F_parser_7>, in file 'gtl_parser.ggs', line 156
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_in) // $in$
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, TOP_DOWN_END_PRODUCTION ()
// At index 289 : <select_gtl_5F_parser_7>, in file 'gtl_parser.ggs', line 156
, TOP_DOWN_END_PRODUCTION ()
// At index 290 : <select_gtl_5F_parser_8>, in file 'gtl_parser.ggs', line 159
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_or) // $or$
, TOP_DOWN_NONTERMINAL (7) // <gtl_template_instruction_list>
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_end) // $end$
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_template) // $template$
, TOP_DOWN_END_PRODUCTION ()
// At index 295 : <select_gtl_5F_parser_8>, in file 'gtl_parser.ggs', line 159
, TOP_DOWN_END_PRODUCTION ()
// At index 296 : <select_gtl_5F_parser_9>, in file 'gtl_parser.ggs', line 166
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_in) // $in$
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, TOP_DOWN_END_PRODUCTION ()
// At index 299 : <select_gtl_5F_parser_9>, in file 'gtl_parser.ggs', line 166
, TOP_DOWN_END_PRODUCTION ()
// At index 300 : <select_gtl_5F_parser_10>, in file 'gtl_parser.ggs', line 202
, TOP_DOWN_END_PRODUCTION ()
// At index 301 : <select_gtl_5F_parser_10>, in file 'gtl_parser.ggs', line 202
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_elsif) // $elsif$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_then) // $then$
, TOP_DOWN_NONTERMINAL (7) // <gtl_template_instruction_list>
, TOP_DOWN_NONTERMINAL (26) // <select_gtl_5F_parser_10>
, TOP_DOWN_END_PRODUCTION ()
// At index 307 : <select_gtl_5F_parser_11>, in file 'gtl_parser.ggs', line 212
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_else) // $else$
, TOP_DOWN_NONTERMINAL (7) // <gtl_template_instruction_list>
, TOP_DOWN_END_PRODUCTION ()
// At index 310 : <select_gtl_5F_parser_11>, in file 'gtl_parser.ggs', line 212
, TOP_DOWN_END_PRODUCTION ()
// At index 311 : <select_gtl_5F_parser_12>, in file 'gtl_parser.ggs', line 239
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__2C_) // $,$
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, TOP_DOWN_END_PRODUCTION ()
// At index 314 : <select_gtl_5F_parser_12>, in file 'gtl_parser.ggs', line 239
, TOP_DOWN_END_PRODUCTION ()
// At index 315 : <select_gtl_5F_parser_13>, in file 'gtl_parser.ggs', line 245
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__28_) // $($
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__29_) // $)$
, TOP_DOWN_END_PRODUCTION ()
// At index 319 : <select_gtl_5F_parser_13>, in file 'gtl_parser.ggs', line 245
, TOP_DOWN_END_PRODUCTION ()
// At index 320 : <select_gtl_5F_parser_14>, in file 'gtl_parser.ggs', line 253
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_before) // $before$
, TOP_DOWN_NONTERMINAL (7) // <gtl_template_instruction_list>
, TOP_DOWN_END_PRODUCTION ()
// At index 323 : <select_gtl_5F_parser_14>, in file 'gtl_parser.ggs', line 253
, TOP_DOWN_END_PRODUCTION ()
// At index 324 : <select_gtl_5F_parser_15>, in file 'gtl_parser.ggs', line 261
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_between) // $between$
, TOP_DOWN_NONTERMINAL (7) // <gtl_template_instruction_list>
, TOP_DOWN_END_PRODUCTION ()
// At index 327 : <select_gtl_5F_parser_15>, in file 'gtl_parser.ggs', line 261
, TOP_DOWN_END_PRODUCTION ()
// At index 328 : <select_gtl_5F_parser_16>, in file 'gtl_parser.ggs', line 266
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_after) // $after$
, TOP_DOWN_NONTERMINAL (7) // <gtl_template_instruction_list>
, TOP_DOWN_END_PRODUCTION ()
// At index 331 : <select_gtl_5F_parser_16>, in file 'gtl_parser.ggs', line 266
, TOP_DOWN_END_PRODUCTION ()
// At index 332 : <select_gtl_5F_parser_17>, in file 'gtl_parser.ggs', line 302
, TOP_DOWN_END_PRODUCTION ()
// At index 333 : <select_gtl_5F_parser_17>, in file 'gtl_parser.ggs', line 302
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__2C_) // $,$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_NONTERMINAL (33) // <select_gtl_5F_parser_17>
, TOP_DOWN_END_PRODUCTION ()
// At index 337 : <select_gtl_5F_parser_18>, in file 'gtl_parser.ggs', line 312
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_between) // $between$
, TOP_DOWN_NONTERMINAL (7) // <gtl_template_instruction_list>
, TOP_DOWN_END_PRODUCTION ()
// At index 340 : <select_gtl_5F_parser_18>, in file 'gtl_parser.ggs', line 312
, TOP_DOWN_END_PRODUCTION ()
// At index 341 : <select_gtl_5F_parser_19>, in file 'gtl_parser.ggs', line 347
, TOP_DOWN_END_PRODUCTION ()
// At index 342 : <select_gtl_5F_parser_19>, in file 'gtl_parser.ggs', line 347
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_up) // $up$
, TOP_DOWN_END_PRODUCTION ()
// At index 344 : <select_gtl_5F_parser_19>, in file 'gtl_parser.ggs', line 347
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_down) // $down$
, TOP_DOWN_END_PRODUCTION ()
// At index 346 : <select_gtl_5F_parser_20>, in file 'gtl_parser.ggs', line 355
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_step) // $step$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_END_PRODUCTION ()
// At index 349 : <select_gtl_5F_parser_20>, in file 'gtl_parser.ggs', line 355
, TOP_DOWN_END_PRODUCTION ()
// At index 350 : <select_gtl_5F_parser_21>, in file 'gtl_parser.ggs', line 360
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_before) // $before$
, TOP_DOWN_NONTERMINAL (7) // <gtl_template_instruction_list>
, TOP_DOWN_END_PRODUCTION ()
// At index 353 : <select_gtl_5F_parser_21>, in file 'gtl_parser.ggs', line 360
, TOP_DOWN_END_PRODUCTION ()
// At index 354 : <select_gtl_5F_parser_22>, in file 'gtl_parser.ggs', line 368
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_between) // $between$
, TOP_DOWN_NONTERMINAL (7) // <gtl_template_instruction_list>
, TOP_DOWN_END_PRODUCTION ()
// At index 357 : <select_gtl_5F_parser_22>, in file 'gtl_parser.ggs', line 368
, TOP_DOWN_END_PRODUCTION ()
// At index 358 : <select_gtl_5F_parser_23>, in file 'gtl_parser.ggs', line 373
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_after) // $after$
, TOP_DOWN_NONTERMINAL (7) // <gtl_template_instruction_list>
, TOP_DOWN_END_PRODUCTION ()
// At index 361 : <select_gtl_5F_parser_23>, in file 'gtl_parser.ggs', line 373
, TOP_DOWN_END_PRODUCTION ()
// At index 362 : <select_gtl_5F_parser_24>, in file 'gtl_parser.ggs', line 402
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__28_) // $($
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__29_) // $)$
, TOP_DOWN_END_PRODUCTION ()
// At index 366 : <select_gtl_5F_parser_24>, in file 'gtl_parser.ggs', line 402
, TOP_DOWN_END_PRODUCTION ()
// At index 367 : <select_gtl_5F_parser_25>, in file 'gtl_parser.ggs', line 446
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, TOP_DOWN_END_PRODUCTION ()
// At index 369 : <select_gtl_5F_parser_25>, in file 'gtl_parser.ggs', line 446
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_from) // $from$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_END_PRODUCTION ()
// At index 372 : <select_gtl_5F_expression_5F_parser_0>, in file 'gtl_expression_parser.ggs', line 37
, TOP_DOWN_END_PRODUCTION ()
// At index 373 : <select_gtl_5F_expression_5F_parser_0>, in file 'gtl_expression_parser.ggs', line 37
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__7C_) // $|$
, TOP_DOWN_NONTERMINAL (10) // <gtl_relation_term>
, TOP_DOWN_NONTERMINAL (42) // <select_gtl_5F_expression_5F_parser_0>
, TOP_DOWN_END_PRODUCTION ()
// At index 377 : <select_gtl_5F_expression_5F_parser_0>, in file 'gtl_expression_parser.ggs', line 37
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__5E_) // $^$
, TOP_DOWN_NONTERMINAL (10) // <gtl_relation_term>
, TOP_DOWN_NONTERMINAL (42) // <select_gtl_5F_expression_5F_parser_0>
, TOP_DOWN_END_PRODUCTION ()
// At index 381 : <select_gtl_5F_expression_5F_parser_1>, in file 'gtl_expression_parser.ggs', line 57
, TOP_DOWN_END_PRODUCTION ()
// At index 382 : <select_gtl_5F_expression_5F_parser_1>, in file 'gtl_expression_parser.ggs', line 57
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__26_) // $&$
, TOP_DOWN_NONTERMINAL (11) // <gtl_relation_factor>
, TOP_DOWN_NONTERMINAL (43) // <select_gtl_5F_expression_5F_parser_1>
, TOP_DOWN_END_PRODUCTION ()
// At index 386 : <select_gtl_5F_expression_5F_parser_2>, in file 'gtl_expression_parser.ggs', line 73
, TOP_DOWN_END_PRODUCTION ()
// At index 387 : <select_gtl_5F_expression_5F_parser_2>, in file 'gtl_expression_parser.ggs', line 73
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__3D__3D_) // $==$
, TOP_DOWN_NONTERMINAL (12) // <gtl_simple_expression>
, TOP_DOWN_END_PRODUCTION ()
// At index 390 : <select_gtl_5F_expression_5F_parser_2>, in file 'gtl_expression_parser.ggs', line 73
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__21__3D_) // $!=$
, TOP_DOWN_NONTERMINAL (12) // <gtl_simple_expression>
, TOP_DOWN_END_PRODUCTION ()
// At index 393 : <select_gtl_5F_expression_5F_parser_2>, in file 'gtl_expression_parser.ggs', line 73
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__3C__3D_) // $<=$
, TOP_DOWN_NONTERMINAL (12) // <gtl_simple_expression>
, TOP_DOWN_END_PRODUCTION ()
// At index 396 : <select_gtl_5F_expression_5F_parser_2>, in file 'gtl_expression_parser.ggs', line 73
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__3E__3D_) // $>=$
, TOP_DOWN_NONTERMINAL (12) // <gtl_simple_expression>
, TOP_DOWN_END_PRODUCTION ()
// At index 399 : <select_gtl_5F_expression_5F_parser_2>, in file 'gtl_expression_parser.ggs', line 73
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__3E_) // $>$
, TOP_DOWN_NONTERMINAL (12) // <gtl_simple_expression>
, TOP_DOWN_END_PRODUCTION ()
// At index 402 : <select_gtl_5F_expression_5F_parser_2>, in file 'gtl_expression_parser.ggs', line 73
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__3C_) // $<$
, TOP_DOWN_NONTERMINAL (12) // <gtl_simple_expression>
, TOP_DOWN_END_PRODUCTION ()
// At index 405 : <select_gtl_5F_expression_5F_parser_3>, in file 'gtl_expression_parser.ggs', line 121
, TOP_DOWN_END_PRODUCTION ()
// At index 406 : <select_gtl_5F_expression_5F_parser_3>, in file 'gtl_expression_parser.ggs', line 121
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__3C__3C_) // $<<$
, TOP_DOWN_NONTERMINAL (13) // <gtl_term>
, TOP_DOWN_NONTERMINAL (45) // <select_gtl_5F_expression_5F_parser_3>
, TOP_DOWN_END_PRODUCTION ()
// At index 410 : <select_gtl_5F_expression_5F_parser_3>, in file 'gtl_expression_parser.ggs', line 121
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__3E__3E_) // $>>$
, TOP_DOWN_NONTERMINAL (13) // <gtl_term>
, TOP_DOWN_NONTERMINAL (45) // <select_gtl_5F_expression_5F_parser_3>
, TOP_DOWN_END_PRODUCTION ()
// At index 414 : <select_gtl_5F_expression_5F_parser_3>, in file 'gtl_expression_parser.ggs', line 121
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__2B_) // $+$
, TOP_DOWN_NONTERMINAL (13) // <gtl_term>
, TOP_DOWN_NONTERMINAL (45) // <select_gtl_5F_expression_5F_parser_3>
, TOP_DOWN_END_PRODUCTION ()
// At index 418 : <select_gtl_5F_expression_5F_parser_3>, in file 'gtl_expression_parser.ggs', line 121
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__2E_) // $.$
, TOP_DOWN_NONTERMINAL (13) // <gtl_term>
, TOP_DOWN_NONTERMINAL (45) // <select_gtl_5F_expression_5F_parser_3>
, TOP_DOWN_END_PRODUCTION ()
// At index 422 : <select_gtl_5F_expression_5F_parser_3>, in file 'gtl_expression_parser.ggs', line 121
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__2D_) // $-$
, TOP_DOWN_NONTERMINAL (13) // <gtl_term>
, TOP_DOWN_NONTERMINAL (45) // <select_gtl_5F_expression_5F_parser_3>
, TOP_DOWN_END_PRODUCTION ()
// At index 426 : <select_gtl_5F_expression_5F_parser_4>, in file 'gtl_expression_parser.ggs', line 166
, TOP_DOWN_END_PRODUCTION ()
// At index 427 : <select_gtl_5F_expression_5F_parser_4>, in file 'gtl_expression_parser.ggs', line 166
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__2A_) // $*$
, TOP_DOWN_NONTERMINAL (14) // <gtl_factor>
, TOP_DOWN_NONTERMINAL (46) // <select_gtl_5F_expression_5F_parser_4>
, TOP_DOWN_END_PRODUCTION ()
// At index 431 : <select_gtl_5F_expression_5F_parser_4>, in file 'gtl_expression_parser.ggs', line 166
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__2F_) // $/$
, TOP_DOWN_NONTERMINAL (14) // <gtl_factor>
, TOP_DOWN_NONTERMINAL (46) // <select_gtl_5F_expression_5F_parser_4>
, TOP_DOWN_END_PRODUCTION ()
// At index 435 : <select_gtl_5F_expression_5F_parser_4>, in file 'gtl_expression_parser.ggs', line 166
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_mod) // $mod$
, TOP_DOWN_NONTERMINAL (14) // <gtl_factor>
, TOP_DOWN_NONTERMINAL (46) // <select_gtl_5F_expression_5F_parser_4>
, TOP_DOWN_END_PRODUCTION ()
// At index 439 : <select_gtl_5F_expression_5F_parser_5>, in file 'gtl_expression_parser.ggs', line 348
, TOP_DOWN_END_PRODUCTION ()
// At index 440 : <select_gtl_5F_expression_5F_parser_5>, in file 'gtl_expression_parser.ggs', line 348
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__3A_) // $:$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_NONTERMINAL (48) // <select_gtl_5F_expression_5F_parser_6>
, TOP_DOWN_END_PRODUCTION ()
// At index 444 : <select_gtl_5F_expression_5F_parser_6>, in file 'gtl_expression_parser.ggs', line 351
, TOP_DOWN_END_PRODUCTION ()
// At index 445 : <select_gtl_5F_expression_5F_parser_6>, in file 'gtl_expression_parser.ggs', line 351
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__2C_) // $,$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_NONTERMINAL (48) // <select_gtl_5F_expression_5F_parser_6>
, TOP_DOWN_END_PRODUCTION ()
// At index 449 : <select_gtl_5F_expression_5F_parser_7>, in file 'gtl_expression_parser.ggs', line 373
, TOP_DOWN_END_PRODUCTION ()
// At index 450 : <select_gtl_5F_expression_5F_parser_7>, in file 'gtl_expression_parser.ggs', line 373
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__28_) // $($
, TOP_DOWN_NONTERMINAL (50) // <select_gtl_5F_expression_5F_parser_8>
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__29_) // $)$
, TOP_DOWN_END_PRODUCTION ()
// At index 454 : <select_gtl_5F_expression_5F_parser_8>, in file 'gtl_expression_parser.ggs', line 381
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_NONTERMINAL (51) // <select_gtl_5F_expression_5F_parser_9>
, TOP_DOWN_END_PRODUCTION ()
// At index 457 : <select_gtl_5F_expression_5F_parser_8>, in file 'gtl_expression_parser.ggs', line 381
, TOP_DOWN_END_PRODUCTION ()
// At index 458 : <select_gtl_5F_expression_5F_parser_9>, in file 'gtl_expression_parser.ggs', line 382
, TOP_DOWN_END_PRODUCTION ()
// At index 459 : <select_gtl_5F_expression_5F_parser_9>, in file 'gtl_expression_parser.ggs', line 382
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__2C_) // $,$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_NONTERMINAL (51) // <select_gtl_5F_expression_5F_parser_9>
, TOP_DOWN_END_PRODUCTION ()
// At index 463 : <select_gtl_5F_expression_5F_parser_10>, in file 'gtl_expression_parser.ggs', line 405
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_default) // $default$
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__28_) // $($
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__29_) // $)$
, TOP_DOWN_END_PRODUCTION ()
// At index 468 : <select_gtl_5F_expression_5F_parser_10>, in file 'gtl_expression_parser.ggs', line 405
, TOP_DOWN_END_PRODUCTION ()
// At index 469 : <select_gtl_5F_expression_5F_parser_11>, in file 'gtl_expression_parser.ggs', line 557
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_by) // $by$
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, TOP_DOWN_END_PRODUCTION ()
// At index 472 : <select_gtl_5F_expression_5F_parser_11>, in file 'gtl_expression_parser.ggs', line 557
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_end) // $end$
, TOP_DOWN_END_PRODUCTION ()
// At index 474 : <select_gtl_5F_expression_5F_parser_12>, in file 'gtl_expression_parser.ggs', line 592
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_NONTERMINAL (55) // <select_gtl_5F_expression_5F_parser_13>
, TOP_DOWN_END_PRODUCTION ()
// At index 477 : <select_gtl_5F_expression_5F_parser_12>, in file 'gtl_expression_parser.ggs', line 592
, TOP_DOWN_END_PRODUCTION ()
// At index 478 : <select_gtl_5F_expression_5F_parser_13>, in file 'gtl_expression_parser.ggs', line 593
, TOP_DOWN_END_PRODUCTION ()
// At index 479 : <select_gtl_5F_expression_5F_parser_13>, in file 'gtl_expression_parser.ggs', line 593
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__2C_) // $,$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_NONTERMINAL (55) // <select_gtl_5F_expression_5F_parser_13>
, TOP_DOWN_END_PRODUCTION ()
// At index 483 : <select_gtl_5F_expression_5F_parser_14>, in file 'gtl_expression_parser.ggs', line 611
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_string) // $string$
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__3A_) // $:$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_NONTERMINAL (57) // <select_gtl_5F_expression_5F_parser_15>
, TOP_DOWN_END_PRODUCTION ()
// At index 488 : <select_gtl_5F_expression_5F_parser_14>, in file 'gtl_expression_parser.ggs', line 611
, TOP_DOWN_END_PRODUCTION ()
// At index 489 : <select_gtl_5F_expression_5F_parser_15>, in file 'gtl_expression_parser.ggs', line 612
, TOP_DOWN_END_PRODUCTION ()
// At index 490 : <select_gtl_5F_expression_5F_parser_15>, in file 'gtl_expression_parser.ggs', line 612
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__2C_) // $,$
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_string) // $string$
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__3A_) // $:$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_NONTERMINAL (57) // <select_gtl_5F_expression_5F_parser_15>
, TOP_DOWN_END_PRODUCTION ()
// At index 496 : <select_gtl_5F_expression_5F_parser_16>, in file 'gtl_expression_parser.ggs', line 632
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__3A_) // $:$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_NONTERMINAL (59) // <select_gtl_5F_expression_5F_parser_17>
, TOP_DOWN_END_PRODUCTION ()
// At index 501 : <select_gtl_5F_expression_5F_parser_16>, in file 'gtl_expression_parser.ggs', line 632
, TOP_DOWN_END_PRODUCTION ()
// At index 502 : <select_gtl_5F_expression_5F_parser_17>, in file 'gtl_expression_parser.ggs', line 633
, TOP_DOWN_END_PRODUCTION ()
// At index 503 : <select_gtl_5F_expression_5F_parser_17>, in file 'gtl_expression_parser.ggs', line 633
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__2C_) // $,$
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__3A_) // $:$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_NONTERMINAL (59) // <select_gtl_5F_expression_5F_parser_17>
, TOP_DOWN_END_PRODUCTION ()
// At index 509 : <select_gtl_5F_expression_5F_parser_18>, in file 'gtl_expression_parser.ggs', line 653
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_NONTERMINAL (61) // <select_gtl_5F_expression_5F_parser_19>
, TOP_DOWN_END_PRODUCTION ()
// At index 512 : <select_gtl_5F_expression_5F_parser_18>, in file 'gtl_expression_parser.ggs', line 653
, TOP_DOWN_END_PRODUCTION ()
// At index 513 : <select_gtl_5F_expression_5F_parser_19>, in file 'gtl_expression_parser.ggs', line 654
, TOP_DOWN_END_PRODUCTION ()
// At index 514 : <select_gtl_5F_expression_5F_parser_19>, in file 'gtl_expression_parser.ggs', line 654
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__2C_) // $,$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_NONTERMINAL (61) // <select_gtl_5F_expression_5F_parser_19>
, TOP_DOWN_END_PRODUCTION ()
// At index 518 : <select_gtl_5F_expression_5F_parser_20>, in file 'gtl_expression_parser.ggs', line 691
, TOP_DOWN_END_PRODUCTION ()
// At index 519 : <select_gtl_5F_expression_5F_parser_20>, in file 'gtl_expression_parser.ggs', line 691
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__3A__3A_) // $::$
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, TOP_DOWN_NONTERMINAL (63) // <select_gtl_5F_expression_5F_parser_21>
, TOP_DOWN_NONTERMINAL (62) // <select_gtl_5F_expression_5F_parser_20>
, TOP_DOWN_END_PRODUCTION ()
// At index 524 : <select_gtl_5F_expression_5F_parser_21>, in file 'gtl_expression_parser.ggs', line 693
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__5B_) // $[$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__5D_) // $]$
, TOP_DOWN_NONTERMINAL (64) // <select_gtl_5F_expression_5F_parser_22>
, TOP_DOWN_END_PRODUCTION ()
// At index 529 : <select_gtl_5F_expression_5F_parser_21>, in file 'gtl_expression_parser.ggs', line 693
, TOP_DOWN_END_PRODUCTION ()
// At index 530 : <select_gtl_5F_expression_5F_parser_22>, in file 'gtl_expression_parser.ggs', line 698
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__5B_) // $[$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__5D_) // $]$
, TOP_DOWN_NONTERMINAL (65) // <select_gtl_5F_expression_5F_parser_23>
, TOP_DOWN_END_PRODUCTION ()
// At index 535 : <select_gtl_5F_expression_5F_parser_22>, in file 'gtl_expression_parser.ggs', line 698
, TOP_DOWN_END_PRODUCTION ()
// At index 536 : <select_gtl_5F_expression_5F_parser_23>, in file 'gtl_expression_parser.ggs', line 703
, TOP_DOWN_END_PRODUCTION ()
// At index 537 : <select_gtl_5F_expression_5F_parser_23>, in file 'gtl_expression_parser.ggs', line 703
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__5B_) // $[$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__5D_) // $]$
, TOP_DOWN_NONTERMINAL (65) // <select_gtl_5F_expression_5F_parser_23>
, TOP_DOWN_END_PRODUCTION ()
// At index 542 : <select_gtl_5F_expression_5F_parser_24>, in file 'gtl_expression_parser.ggs', line 726
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_here) // $here$
, TOP_DOWN_END_PRODUCTION ()
// At index 544 : <select_gtl_5F_expression_5F_parser_24>, in file 'gtl_expression_parser.ggs', line 726
, TOP_DOWN_NONTERMINAL (1) // <gtl_variable>
, TOP_DOWN_END_PRODUCTION ()
// At index 546 : <select_gtl_5F_expression_5F_parser_25>, in file 'gtl_expression_parser.ggs', line 741
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, TOP_DOWN_NONTERMINAL (69) // <select_gtl_5F_expression_5F_parser_27>
, TOP_DOWN_NONTERMINAL (68) // <select_gtl_5F_expression_5F_parser_26>
, TOP_DOWN_END_PRODUCTION ()
// At index 550 : <select_gtl_5F_expression_5F_parser_25>, in file 'gtl_expression_parser.ggs', line 741
, TOP_DOWN_END_PRODUCTION ()
// At index 551 : <select_gtl_5F_expression_5F_parser_26>, in file 'gtl_expression_parser.ggs', line 742
, TOP_DOWN_END_PRODUCTION ()
// At index 552 : <select_gtl_5F_expression_5F_parser_26>, in file 'gtl_expression_parser.ggs', line 742
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__2C_) // $,$
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, TOP_DOWN_NONTERMINAL (69) // <select_gtl_5F_expression_5F_parser_27>
, TOP_DOWN_NONTERMINAL (68) // <select_gtl_5F_expression_5F_parser_26>
, TOP_DOWN_END_PRODUCTION ()
// At index 557 : <select_gtl_5F_expression_5F_parser_27>, in file 'gtl_expression_parser.ggs', line 744
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__3A_) // $:$
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__40_) // $@$
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, TOP_DOWN_END_PRODUCTION ()
// At index 561 : <select_gtl_5F_expression_5F_parser_27>, in file 'gtl_expression_parser.ggs', line 744
, TOP_DOWN_END_PRODUCTION ()
// At index 562 : <select_gtl_5F_instruction_5F_parser_0>, in file 'gtl_instruction_parser.ggs', line 45
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__3A__3D_) // $:=$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_END_PRODUCTION ()
// At index 565 : <select_gtl_5F_instruction_5F_parser_0>, in file 'gtl_instruction_parser.ggs', line 45
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__2B__3D_) // $+=$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_END_PRODUCTION ()
// At index 568 : <select_gtl_5F_instruction_5F_parser_0>, in file 'gtl_instruction_parser.ggs', line 45
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__2D__3D_) // $-=$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_END_PRODUCTION ()
// At index 571 : <select_gtl_5F_instruction_5F_parser_0>, in file 'gtl_instruction_parser.ggs', line 45
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__2A__3D_) // $*=$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_END_PRODUCTION ()
// At index 574 : <select_gtl_5F_instruction_5F_parser_0>, in file 'gtl_instruction_parser.ggs', line 45
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__2F__3D_) // $/=$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_END_PRODUCTION ()
// At index 577 : <select_gtl_5F_instruction_5F_parser_0>, in file 'gtl_instruction_parser.ggs', line 45
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_mod_3D_) // $mod=$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_END_PRODUCTION ()
// At index 580 : <select_gtl_5F_instruction_5F_parser_0>, in file 'gtl_instruction_parser.ggs', line 45
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__3C__3C__3D_) // $<<=$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_END_PRODUCTION ()
// At index 583 : <select_gtl_5F_instruction_5F_parser_0>, in file 'gtl_instruction_parser.ggs', line 45
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__3E__3E__3D_) // $>>=$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_END_PRODUCTION ()
// At index 586 : <select_gtl_5F_instruction_5F_parser_0>, in file 'gtl_instruction_parser.ggs', line 45
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__26__3D_) // $&=$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_END_PRODUCTION ()
// At index 589 : <select_gtl_5F_instruction_5F_parser_0>, in file 'gtl_instruction_parser.ggs', line 45
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__7C__3D_) // $|=$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_END_PRODUCTION ()
// At index 592 : <select_gtl_5F_instruction_5F_parser_0>, in file 'gtl_instruction_parser.ggs', line 45
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__5E__3D_) // $^=$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_END_PRODUCTION ()
// At index 595 : <select_gtl_5F_instruction_5F_parser_0>, in file 'gtl_instruction_parser.ggs', line 45
, TOP_DOWN_END_PRODUCTION ()
// At index 596 : <select_gtl_5F_instruction_5F_parser_1>, in file 'gtl_instruction_parser.ggs', line 222
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_END_PRODUCTION ()
// At index 598 : <select_gtl_5F_instruction_5F_parser_1>, in file 'gtl_instruction_parser.ggs', line 222
, TOP_DOWN_END_PRODUCTION ()
// At index 599 : <select_gtl_5F_instruction_5F_parser_2>, in file 'gtl_instruction_parser.ggs', line 261
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_by) // $by$
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, TOP_DOWN_NONTERMINAL (15) // <gtl_sorting_order>
, TOP_DOWN_NONTERMINAL (73) // <select_gtl_5F_instruction_5F_parser_3>
, TOP_DOWN_END_PRODUCTION ()
// At index 604 : <select_gtl_5F_instruction_5F_parser_2>, in file 'gtl_instruction_parser.ggs', line 261
, TOP_DOWN_NONTERMINAL (15) // <gtl_sorting_order>
, TOP_DOWN_END_PRODUCTION ()
// At index 606 : <select_gtl_5F_instruction_5F_parser_3>, in file 'gtl_instruction_parser.ggs', line 264
, TOP_DOWN_END_PRODUCTION ()
// At index 607 : <select_gtl_5F_instruction_5F_parser_3>, in file 'gtl_instruction_parser.ggs', line 264
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__2C_) // $,$
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken_identifier) // $identifier$
, TOP_DOWN_NONTERMINAL (15) // <gtl_sorting_order>
, TOP_DOWN_NONTERMINAL (73) // <select_gtl_5F_instruction_5F_parser_3>
, TOP_DOWN_END_PRODUCTION ()
// At index 612 : <select_gtl_5F_instruction_5F_parser_4>, in file 'gtl_instruction_parser.ggs', line 334
, TOP_DOWN_END_PRODUCTION ()
// At index 613 : <select_gtl_5F_instruction_5F_parser_4>, in file 'gtl_instruction_parser.ggs', line 334
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__3A_) // $:$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_NONTERMINAL (75) // <select_gtl_5F_instruction_5F_parser_5>
, TOP_DOWN_END_PRODUCTION ()
// At index 617 : <select_gtl_5F_instruction_5F_parser_5>, in file 'gtl_instruction_parser.ggs', line 337
, TOP_DOWN_END_PRODUCTION ()
// At index 618 : <select_gtl_5F_instruction_5F_parser_5>, in file 'gtl_instruction_parser.ggs', line 337
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__2C_) // $,$
, TOP_DOWN_NONTERMINAL (0) // <gtl_expression>
, TOP_DOWN_NONTERMINAL (75) // <select_gtl_5F_instruction_5F_parser_5>
, TOP_DOWN_END_PRODUCTION ()
// At index 622 : <select_gtl_5F_instruction_5F_parser_6>, in file 'gtl_instruction_parser.ggs', line 358
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__3E_) // $>$
, TOP_DOWN_END_PRODUCTION ()
// At index 624 : <select_gtl_5F_instruction_5F_parser_6>, in file 'gtl_instruction_parser.ggs', line 358
, TOP_DOWN_TERMINAL (Lexique_gtl_5F_scanner::kToken__3C_) // $<$
, TOP_DOWN_END_PRODUCTION ()
// At index 626 : <>, in file '.ggs', line 0
, TOP_DOWN_NONTERMINAL (6) // <gtl_start_symbol>
, TOP_DOWN_END_PRODUCTION ()
} ;

//--------------------------------------------------------------------------------------------------
//
//                                P R O D U C T I O N    N A M E S                                  
//
//--------------------------------------------------------------------------------------------------

static const cProductionNameDescriptor gProductionNames_gtl_grammar [211] = {
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
 {"<gtl_factor>", "gtl_expression_parser", 241}, // at index 61
 {"<gtl_factor>", "gtl_expression_parser", 245}, // at index 62
 {"<gtl_sorting_order>", "gtl_instruction_parser", 247}, // at index 63
 {"<select_gtl_5F_parser_0>", "gtl_parser", 249}, // at index 64
 {"<select_gtl_5F_parser_0>", "gtl_parser", 250}, // at index 65
 {"<select_gtl_5F_parser_1>", "gtl_parser", 253}, // at index 66
 {"<select_gtl_5F_parser_1>", "gtl_parser", 254}, // at index 67
 {"<select_gtl_5F_parser_1>", "gtl_parser", 257}, // at index 68
 {"<select_gtl_5F_parser_2>", "gtl_parser", 260}, // at index 69
 {"<select_gtl_5F_parser_2>", "gtl_parser", 262}, // at index 70
 {"<select_gtl_5F_parser_3>", "gtl_parser", 263}, // at index 71
 {"<select_gtl_5F_parser_3>", "gtl_parser", 267}, // at index 72
 {"<select_gtl_5F_parser_4>", "gtl_parser", 268}, // at index 73
 {"<select_gtl_5F_parser_4>", "gtl_parser", 271}, // at index 74
 {"<select_gtl_5F_parser_5>", "gtl_parser", 272}, // at index 75
 {"<select_gtl_5F_parser_5>", "gtl_parser", 273}, // at index 76
 {"<select_gtl_5F_parser_6>", "gtl_parser", 277}, // at index 77
 {"<select_gtl_5F_parser_6>", "gtl_parser", 283}, // at index 78
 {"<select_gtl_5F_parser_7>", "gtl_parser", 286}, // at index 79
 {"<select_gtl_5F_parser_7>", "gtl_parser", 289}, // at index 80
 {"<select_gtl_5F_parser_8>", "gtl_parser", 290}, // at index 81
 {"<select_gtl_5F_parser_8>", "gtl_parser", 295}, // at index 82
 {"<select_gtl_5F_parser_9>", "gtl_parser", 296}, // at index 83
 {"<select_gtl_5F_parser_9>", "gtl_parser", 299}, // at index 84
 {"<select_gtl_5F_parser_10>", "gtl_parser", 300}, // at index 85
 {"<select_gtl_5F_parser_10>", "gtl_parser", 301}, // at index 86
 {"<select_gtl_5F_parser_11>", "gtl_parser", 307}, // at index 87
 {"<select_gtl_5F_parser_11>", "gtl_parser", 310}, // at index 88
 {"<select_gtl_5F_parser_12>", "gtl_parser", 311}, // at index 89
 {"<select_gtl_5F_parser_12>", "gtl_parser", 314}, // at index 90
 {"<select_gtl_5F_parser_13>", "gtl_parser", 315}, // at index 91
 {"<select_gtl_5F_parser_13>", "gtl_parser", 319}, // at index 92
 {"<select_gtl_5F_parser_14>", "gtl_parser", 320}, // at index 93
 {"<select_gtl_5F_parser_14>", "gtl_parser", 323}, // at index 94
 {"<select_gtl_5F_parser_15>", "gtl_parser", 324}, // at index 95
 {"<select_gtl_5F_parser_15>", "gtl_parser", 327}, // at index 96
 {"<select_gtl_5F_parser_16>", "gtl_parser", 328}, // at index 97
 {"<select_gtl_5F_parser_16>", "gtl_parser", 331}, // at index 98
 {"<select_gtl_5F_parser_17>", "gtl_parser", 332}, // at index 99
 {"<select_gtl_5F_parser_17>", "gtl_parser", 333}, // at index 100
 {"<select_gtl_5F_parser_18>", "gtl_parser", 337}, // at index 101
 {"<select_gtl_5F_parser_18>", "gtl_parser", 340}, // at index 102
 {"<select_gtl_5F_parser_19>", "gtl_parser", 341}, // at index 103
 {"<select_gtl_5F_parser_19>", "gtl_parser", 342}, // at index 104
 {"<select_gtl_5F_parser_19>", "gtl_parser", 344}, // at index 105
 {"<select_gtl_5F_parser_20>", "gtl_parser", 346}, // at index 106
 {"<select_gtl_5F_parser_20>", "gtl_parser", 349}, // at index 107
 {"<select_gtl_5F_parser_21>", "gtl_parser", 350}, // at index 108
 {"<select_gtl_5F_parser_21>", "gtl_parser", 353}, // at index 109
 {"<select_gtl_5F_parser_22>", "gtl_parser", 354}, // at index 110
 {"<select_gtl_5F_parser_22>", "gtl_parser", 357}, // at index 111
 {"<select_gtl_5F_parser_23>", "gtl_parser", 358}, // at index 112
 {"<select_gtl_5F_parser_23>", "gtl_parser", 361}, // at index 113
 {"<select_gtl_5F_parser_24>", "gtl_parser", 362}, // at index 114
 {"<select_gtl_5F_parser_24>", "gtl_parser", 366}, // at index 115
 {"<select_gtl_5F_parser_25>", "gtl_parser", 367}, // at index 116
 {"<select_gtl_5F_parser_25>", "gtl_parser", 369}, // at index 117
 {"<select_gtl_5F_expression_5F_parser_0>", "gtl_expression_parser", 372}, // at index 118
 {"<select_gtl_5F_expression_5F_parser_0>", "gtl_expression_parser", 373}, // at index 119
 {"<select_gtl_5F_expression_5F_parser_0>", "gtl_expression_parser", 377}, // at index 120
 {"<select_gtl_5F_expression_5F_parser_1>", "gtl_expression_parser", 381}, // at index 121
 {"<select_gtl_5F_expression_5F_parser_1>", "gtl_expression_parser", 382}, // at index 122
 {"<select_gtl_5F_expression_5F_parser_2>", "gtl_expression_parser", 386}, // at index 123
 {"<select_gtl_5F_expression_5F_parser_2>", "gtl_expression_parser", 387}, // at index 124
 {"<select_gtl_5F_expression_5F_parser_2>", "gtl_expression_parser", 390}, // at index 125
 {"<select_gtl_5F_expression_5F_parser_2>", "gtl_expression_parser", 393}, // at index 126
 {"<select_gtl_5F_expression_5F_parser_2>", "gtl_expression_parser", 396}, // at index 127
 {"<select_gtl_5F_expression_5F_parser_2>", "gtl_expression_parser", 399}, // at index 128
 {"<select_gtl_5F_expression_5F_parser_2>", "gtl_expression_parser", 402}, // at index 129
 {"<select_gtl_5F_expression_5F_parser_3>", "gtl_expression_parser", 405}, // at index 130
 {"<select_gtl_5F_expression_5F_parser_3>", "gtl_expression_parser", 406}, // at index 131
 {"<select_gtl_5F_expression_5F_parser_3>", "gtl_expression_parser", 410}, // at index 132
 {"<select_gtl_5F_expression_5F_parser_3>", "gtl_expression_parser", 414}, // at index 133
 {"<select_gtl_5F_expression_5F_parser_3>", "gtl_expression_parser", 418}, // at index 134
 {"<select_gtl_5F_expression_5F_parser_3>", "gtl_expression_parser", 422}, // at index 135
 {"<select_gtl_5F_expression_5F_parser_4>", "gtl_expression_parser", 426}, // at index 136
 {"<select_gtl_5F_expression_5F_parser_4>", "gtl_expression_parser", 427}, // at index 137
 {"<select_gtl_5F_expression_5F_parser_4>", "gtl_expression_parser", 431}, // at index 138
 {"<select_gtl_5F_expression_5F_parser_4>", "gtl_expression_parser", 435}, // at index 139
 {"<select_gtl_5F_expression_5F_parser_5>", "gtl_expression_parser", 439}, // at index 140
 {"<select_gtl_5F_expression_5F_parser_5>", "gtl_expression_parser", 440}, // at index 141
 {"<select_gtl_5F_expression_5F_parser_6>", "gtl_expression_parser", 444}, // at index 142
 {"<select_gtl_5F_expression_5F_parser_6>", "gtl_expression_parser", 445}, // at index 143
 {"<select_gtl_5F_expression_5F_parser_7>", "gtl_expression_parser", 449}, // at index 144
 {"<select_gtl_5F_expression_5F_parser_7>", "gtl_expression_parser", 450}, // at index 145
 {"<select_gtl_5F_expression_5F_parser_8>", "gtl_expression_parser", 454}, // at index 146
 {"<select_gtl_5F_expression_5F_parser_8>", "gtl_expression_parser", 457}, // at index 147
 {"<select_gtl_5F_expression_5F_parser_9>", "gtl_expression_parser", 458}, // at index 148
 {"<select_gtl_5F_expression_5F_parser_9>", "gtl_expression_parser", 459}, // at index 149
 {"<select_gtl_5F_expression_5F_parser_10>", "gtl_expression_parser", 463}, // at index 150
 {"<select_gtl_5F_expression_5F_parser_10>", "gtl_expression_parser", 468}, // at index 151
 {"<select_gtl_5F_expression_5F_parser_11>", "gtl_expression_parser", 469}, // at index 152
 {"<select_gtl_5F_expression_5F_parser_11>", "gtl_expression_parser", 472}, // at index 153
 {"<select_gtl_5F_expression_5F_parser_12>", "gtl_expression_parser", 474}, // at index 154
 {"<select_gtl_5F_expression_5F_parser_12>", "gtl_expression_parser", 477}, // at index 155
 {"<select_gtl_5F_expression_5F_parser_13>", "gtl_expression_parser", 478}, // at index 156
 {"<select_gtl_5F_expression_5F_parser_13>", "gtl_expression_parser", 479}, // at index 157
 {"<select_gtl_5F_expression_5F_parser_14>", "gtl_expression_parser", 483}, // at index 158
 {"<select_gtl_5F_expression_5F_parser_14>", "gtl_expression_parser", 488}, // at index 159
 {"<select_gtl_5F_expression_5F_parser_15>", "gtl_expression_parser", 489}, // at index 160
 {"<select_gtl_5F_expression_5F_parser_15>", "gtl_expression_parser", 490}, // at index 161
 {"<select_gtl_5F_expression_5F_parser_16>", "gtl_expression_parser", 496}, // at index 162
 {"<select_gtl_5F_expression_5F_parser_16>", "gtl_expression_parser", 501}, // at index 163
 {"<select_gtl_5F_expression_5F_parser_17>", "gtl_expression_parser", 502}, // at index 164
 {"<select_gtl_5F_expression_5F_parser_17>", "gtl_expression_parser", 503}, // at index 165
 {"<select_gtl_5F_expression_5F_parser_18>", "gtl_expression_parser", 509}, // at index 166
 {"<select_gtl_5F_expression_5F_parser_18>", "gtl_expression_parser", 512}, // at index 167
 {"<select_gtl_5F_expression_5F_parser_19>", "gtl_expression_parser", 513}, // at index 168
 {"<select_gtl_5F_expression_5F_parser_19>", "gtl_expression_parser", 514}, // at index 169
 {"<select_gtl_5F_expression_5F_parser_20>", "gtl_expression_parser", 518}, // at index 170
 {"<select_gtl_5F_expression_5F_parser_20>", "gtl_expression_parser", 519}, // at index 171
 {"<select_gtl_5F_expression_5F_parser_21>", "gtl_expression_parser", 524}, // at index 172
 {"<select_gtl_5F_expression_5F_parser_21>", "gtl_expression_parser", 529}, // at index 173
 {"<select_gtl_5F_expression_5F_parser_22>", "gtl_expression_parser", 530}, // at index 174
 {"<select_gtl_5F_expression_5F_parser_22>", "gtl_expression_parser", 535}, // at index 175
 {"<select_gtl_5F_expression_5F_parser_23>", "gtl_expression_parser", 536}, // at index 176
 {"<select_gtl_5F_expression_5F_parser_23>", "gtl_expression_parser", 537}, // at index 177
 {"<select_gtl_5F_expression_5F_parser_24>", "gtl_expression_parser", 542}, // at index 178
 {"<select_gtl_5F_expression_5F_parser_24>", "gtl_expression_parser", 544}, // at index 179
 {"<select_gtl_5F_expression_5F_parser_25>", "gtl_expression_parser", 546}, // at index 180
 {"<select_gtl_5F_expression_5F_parser_25>", "gtl_expression_parser", 550}, // at index 181
 {"<select_gtl_5F_expression_5F_parser_26>", "gtl_expression_parser", 551}, // at index 182
 {"<select_gtl_5F_expression_5F_parser_26>", "gtl_expression_parser", 552}, // at index 183
 {"<select_gtl_5F_expression_5F_parser_27>", "gtl_expression_parser", 557}, // at index 184
 {"<select_gtl_5F_expression_5F_parser_27>", "gtl_expression_parser", 561}, // at index 185
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
 {"<select_gtl_5F_instruction_5F_parser_0>", "gtl_instruction_parser", 592}, // at index 196
 {"<select_gtl_5F_instruction_5F_parser_0>", "gtl_instruction_parser", 595}, // at index 197
 {"<select_gtl_5F_instruction_5F_parser_1>", "gtl_instruction_parser", 596}, // at index 198
 {"<select_gtl_5F_instruction_5F_parser_1>", "gtl_instruction_parser", 598}, // at index 199
 {"<select_gtl_5F_instruction_5F_parser_2>", "gtl_instruction_parser", 599}, // at index 200
 {"<select_gtl_5F_instruction_5F_parser_2>", "gtl_instruction_parser", 604}, // at index 201
 {"<select_gtl_5F_instruction_5F_parser_3>", "gtl_instruction_parser", 606}, // at index 202
 {"<select_gtl_5F_instruction_5F_parser_3>", "gtl_instruction_parser", 607}, // at index 203
 {"<select_gtl_5F_instruction_5F_parser_4>", "gtl_instruction_parser", 612}, // at index 204
 {"<select_gtl_5F_instruction_5F_parser_4>", "gtl_instruction_parser", 613}, // at index 205
 {"<select_gtl_5F_instruction_5F_parser_5>", "gtl_instruction_parser", 617}, // at index 206
 {"<select_gtl_5F_instruction_5F_parser_5>", "gtl_instruction_parser", 618}, // at index 207
 {"<select_gtl_5F_instruction_5F_parser_6>", "gtl_instruction_parser", 622}, // at index 208
 {"<select_gtl_5F_instruction_5F_parser_6>", "gtl_instruction_parser", 624}, // at index 209
 {"<>", "", 626} // at index 210
} ;

//--------------------------------------------------------------------------------------------------
//
//                       L L ( 1 )    P R O D U C T I O N    I N D E X E S                          
//
//--------------------------------------------------------------------------------------------------

static const int32_t gProductionIndexes_gtl_grammar [211] = {
0, // index 0 : <gtl_expression>, in file 'gtl_expression_parser.ggs', line 33
3, // index 1 : <gtl_variable>, in file 'gtl_expression_parser.ggs', line 687
7, // index 2 : <gtl_variable_or_here>, in file 'gtl_expression_parser.ggs', line 722
9, // index 3 : <gtl_import>, in file 'gtl_instruction_parser.ggs', line 368
12, // index 4 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 40
16, // index 5 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 154
19, // index 6 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 167
24, // index 7 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 185
29, // index 8 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 203
32, // index 9 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 218
35, // index 10 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 241
38, // index 11 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 256
42, // index 12 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 289
45, // index 13 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 303
47, // index 14 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 315
49, // index 15 : <gtl_simple_instruction>, in file 'gtl_instruction_parser.ggs', line 326
55, // index 16 : <gtl_argument_list>, in file 'gtl_expression_parser.ggs', line 736
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
241, // index 61 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 667
245, // index 62 : <gtl_factor>, in file 'gtl_expression_parser.ggs', line 678
247, // index 63 : <gtl_sorting_order>, in file 'gtl_instruction_parser.ggs', line 355
249, // index 64 : <select_gtl_5F_parser_0>, in file 'gtl_parser.ggs', line 55
250, // index 65 : <select_gtl_5F_parser_0>, in file 'gtl_parser.ggs', line 55
253, // index 66 : <select_gtl_5F_parser_1>, in file 'gtl_parser.ggs', line 67
254, // index 67 : <select_gtl_5F_parser_1>, in file 'gtl_parser.ggs', line 67
257, // index 68 : <select_gtl_5F_parser_1>, in file 'gtl_parser.ggs', line 67
260, // index 69 : <select_gtl_5F_parser_2>, in file 'gtl_parser.ggs', line 112
262, // index 70 : <select_gtl_5F_parser_2>, in file 'gtl_parser.ggs', line 112
263, // index 71 : <select_gtl_5F_parser_3>, in file 'gtl_parser.ggs', line 138
267, // index 72 : <select_gtl_5F_parser_3>, in file 'gtl_parser.ggs', line 138
268, // index 73 : <select_gtl_5F_parser_4>, in file 'gtl_parser.ggs', line 141
271, // index 74 : <select_gtl_5F_parser_4>, in file 'gtl_parser.ggs', line 141
272, // index 75 : <select_gtl_5F_parser_5>, in file 'gtl_parser.ggs', line 142
273, // index 76 : <select_gtl_5F_parser_5>, in file 'gtl_parser.ggs', line 142
277, // index 77 : <select_gtl_5F_parser_6>, in file 'gtl_parser.ggs', line 152
283, // index 78 : <select_gtl_5F_parser_6>, in file 'gtl_parser.ggs', line 152
286, // index 79 : <select_gtl_5F_parser_7>, in file 'gtl_parser.ggs', line 156
289, // index 80 : <select_gtl_5F_parser_7>, in file 'gtl_parser.ggs', line 156
290, // index 81 : <select_gtl_5F_parser_8>, in file 'gtl_parser.ggs', line 159
295, // index 82 : <select_gtl_5F_parser_8>, in file 'gtl_parser.ggs', line 159
296, // index 83 : <select_gtl_5F_parser_9>, in file 'gtl_parser.ggs', line 166
299, // index 84 : <select_gtl_5F_parser_9>, in file 'gtl_parser.ggs', line 166
300, // index 85 : <select_gtl_5F_parser_10>, in file 'gtl_parser.ggs', line 202
301, // index 86 : <select_gtl_5F_parser_10>, in file 'gtl_parser.ggs', line 202
307, // index 87 : <select_gtl_5F_parser_11>, in file 'gtl_parser.ggs', line 212
310, // index 88 : <select_gtl_5F_parser_11>, in file 'gtl_parser.ggs', line 212
311, // index 89 : <select_gtl_5F_parser_12>, in file 'gtl_parser.ggs', line 239
314, // index 90 : <select_gtl_5F_parser_12>, in file 'gtl_parser.ggs', line 239
315, // index 91 : <select_gtl_5F_parser_13>, in file 'gtl_parser.ggs', line 245
319, // index 92 : <select_gtl_5F_parser_13>, in file 'gtl_parser.ggs', line 245
320, // index 93 : <select_gtl_5F_parser_14>, in file 'gtl_parser.ggs', line 253
323, // index 94 : <select_gtl_5F_parser_14>, in file 'gtl_parser.ggs', line 253
324, // index 95 : <select_gtl_5F_parser_15>, in file 'gtl_parser.ggs', line 261
327, // index 96 : <select_gtl_5F_parser_15>, in file 'gtl_parser.ggs', line 261
328, // index 97 : <select_gtl_5F_parser_16>, in file 'gtl_parser.ggs', line 266
331, // index 98 : <select_gtl_5F_parser_16>, in file 'gtl_parser.ggs', line 266
332, // index 99 : <select_gtl_5F_parser_17>, in file 'gtl_parser.ggs', line 302
333, // index 100 : <select_gtl_5F_parser_17>, in file 'gtl_parser.ggs', line 302
337, // index 101 : <select_gtl_5F_parser_18>, in file 'gtl_parser.ggs', line 312
340, // index 102 : <select_gtl_5F_parser_18>, in file 'gtl_parser.ggs', line 312
341, // index 103 : <select_gtl_5F_parser_19>, in file 'gtl_parser.ggs', line 347
342, // index 104 : <select_gtl_5F_parser_19>, in file 'gtl_parser.ggs', line 347
344, // index 105 : <select_gtl_5F_parser_19>, in file 'gtl_parser.ggs', line 347
346, // index 106 : <select_gtl_5F_parser_20>, in file 'gtl_parser.ggs', line 355
349, // index 107 : <select_gtl_5F_parser_20>, in file 'gtl_parser.ggs', line 355
350, // index 108 : <select_gtl_5F_parser_21>, in file 'gtl_parser.ggs', line 360
353, // index 109 : <select_gtl_5F_parser_21>, in file 'gtl_parser.ggs', line 360
354, // index 110 : <select_gtl_5F_parser_22>, in file 'gtl_parser.ggs', line 368
357, // index 111 : <select_gtl_5F_parser_22>, in file 'gtl_parser.ggs', line 368
358, // index 112 : <select_gtl_5F_parser_23>, in file 'gtl_parser.ggs', line 373
361, // index 113 : <select_gtl_5F_parser_23>, in file 'gtl_parser.ggs', line 373
362, // index 114 : <select_gtl_5F_parser_24>, in file 'gtl_parser.ggs', line 402
366, // index 115 : <select_gtl_5F_parser_24>, in file 'gtl_parser.ggs', line 402
367, // index 116 : <select_gtl_5F_parser_25>, in file 'gtl_parser.ggs', line 446
369, // index 117 : <select_gtl_5F_parser_25>, in file 'gtl_parser.ggs', line 446
372, // index 118 : <select_gtl_5F_expression_5F_parser_0>, in file 'gtl_expression_parser.ggs', line 37
373, // index 119 : <select_gtl_5F_expression_5F_parser_0>, in file 'gtl_expression_parser.ggs', line 37
377, // index 120 : <select_gtl_5F_expression_5F_parser_0>, in file 'gtl_expression_parser.ggs', line 37
381, // index 121 : <select_gtl_5F_expression_5F_parser_1>, in file 'gtl_expression_parser.ggs', line 57
382, // index 122 : <select_gtl_5F_expression_5F_parser_1>, in file 'gtl_expression_parser.ggs', line 57
386, // index 123 : <select_gtl_5F_expression_5F_parser_2>, in file 'gtl_expression_parser.ggs', line 73
387, // index 124 : <select_gtl_5F_expression_5F_parser_2>, in file 'gtl_expression_parser.ggs', line 73
390, // index 125 : <select_gtl_5F_expression_5F_parser_2>, in file 'gtl_expression_parser.ggs', line 73
393, // index 126 : <select_gtl_5F_expression_5F_parser_2>, in file 'gtl_expression_parser.ggs', line 73
396, // index 127 : <select_gtl_5F_expression_5F_parser_2>, in file 'gtl_expression_parser.ggs', line 73
399, // index 128 : <select_gtl_5F_expression_5F_parser_2>, in file 'gtl_expression_parser.ggs', line 73
402, // index 129 : <select_gtl_5F_expression_5F_parser_2>, in file 'gtl_expression_parser.ggs', line 73
405, // index 130 : <select_gtl_5F_expression_5F_parser_3>, in file 'gtl_expression_parser.ggs', line 121
406, // index 131 : <select_gtl_5F_expression_5F_parser_3>, in file 'gtl_expression_parser.ggs', line 121
410, // index 132 : <select_gtl_5F_expression_5F_parser_3>, in file 'gtl_expression_parser.ggs', line 121
414, // index 133 : <select_gtl_5F_expression_5F_parser_3>, in file 'gtl_expression_parser.ggs', line 121
418, // index 134 : <select_gtl_5F_expression_5F_parser_3>, in file 'gtl_expression_parser.ggs', line 121
422, // index 135 : <select_gtl_5F_expression_5F_parser_3>, in file 'gtl_expression_parser.ggs', line 121
426, // index 136 : <select_gtl_5F_expression_5F_parser_4>, in file 'gtl_expression_parser.ggs', line 166
427, // index 137 : <select_gtl_5F_expression_5F_parser_4>, in file 'gtl_expression_parser.ggs', line 166
431, // index 138 : <select_gtl_5F_expression_5F_parser_4>, in file 'gtl_expression_parser.ggs', line 166
435, // index 139 : <select_gtl_5F_expression_5F_parser_4>, in file 'gtl_expression_parser.ggs', line 166
439, // index 140 : <select_gtl_5F_expression_5F_parser_5>, in file 'gtl_expression_parser.ggs', line 348
440, // index 141 : <select_gtl_5F_expression_5F_parser_5>, in file 'gtl_expression_parser.ggs', line 348
444, // index 142 : <select_gtl_5F_expression_5F_parser_6>, in file 'gtl_expression_parser.ggs', line 351
445, // index 143 : <select_gtl_5F_expression_5F_parser_6>, in file 'gtl_expression_parser.ggs', line 351
449, // index 144 : <select_gtl_5F_expression_5F_parser_7>, in file 'gtl_expression_parser.ggs', line 373
450, // index 145 : <select_gtl_5F_expression_5F_parser_7>, in file 'gtl_expression_parser.ggs', line 373
454, // index 146 : <select_gtl_5F_expression_5F_parser_8>, in file 'gtl_expression_parser.ggs', line 381
457, // index 147 : <select_gtl_5F_expression_5F_parser_8>, in file 'gtl_expression_parser.ggs', line 381
458, // index 148 : <select_gtl_5F_expression_5F_parser_9>, in file 'gtl_expression_parser.ggs', line 382
459, // index 149 : <select_gtl_5F_expression_5F_parser_9>, in file 'gtl_expression_parser.ggs', line 382
463, // index 150 : <select_gtl_5F_expression_5F_parser_10>, in file 'gtl_expression_parser.ggs', line 405
468, // index 151 : <select_gtl_5F_expression_5F_parser_10>, in file 'gtl_expression_parser.ggs', line 405
469, // index 152 : <select_gtl_5F_expression_5F_parser_11>, in file 'gtl_expression_parser.ggs', line 557
472, // index 153 : <select_gtl_5F_expression_5F_parser_11>, in file 'gtl_expression_parser.ggs', line 557
474, // index 154 : <select_gtl_5F_expression_5F_parser_12>, in file 'gtl_expression_parser.ggs', line 592
477, // index 155 : <select_gtl_5F_expression_5F_parser_12>, in file 'gtl_expression_parser.ggs', line 592
478, // index 156 : <select_gtl_5F_expression_5F_parser_13>, in file 'gtl_expression_parser.ggs', line 593
479, // index 157 : <select_gtl_5F_expression_5F_parser_13>, in file 'gtl_expression_parser.ggs', line 593
483, // index 158 : <select_gtl_5F_expression_5F_parser_14>, in file 'gtl_expression_parser.ggs', line 611
488, // index 159 : <select_gtl_5F_expression_5F_parser_14>, in file 'gtl_expression_parser.ggs', line 611
489, // index 160 : <select_gtl_5F_expression_5F_parser_15>, in file 'gtl_expression_parser.ggs', line 612
490, // index 161 : <select_gtl_5F_expression_5F_parser_15>, in file 'gtl_expression_parser.ggs', line 612
496, // index 162 : <select_gtl_5F_expression_5F_parser_16>, in file 'gtl_expression_parser.ggs', line 632
501, // index 163 : <select_gtl_5F_expression_5F_parser_16>, in file 'gtl_expression_parser.ggs', line 632
502, // index 164 : <select_gtl_5F_expression_5F_parser_17>, in file 'gtl_expression_parser.ggs', line 633
503, // index 165 : <select_gtl_5F_expression_5F_parser_17>, in file 'gtl_expression_parser.ggs', line 633
509, // index 166 : <select_gtl_5F_expression_5F_parser_18>, in file 'gtl_expression_parser.ggs', line 653
512, // index 167 : <select_gtl_5F_expression_5F_parser_18>, in file 'gtl_expression_parser.ggs', line 653
513, // index 168 : <select_gtl_5F_expression_5F_parser_19>, in file 'gtl_expression_parser.ggs', line 654
514, // index 169 : <select_gtl_5F_expression_5F_parser_19>, in file 'gtl_expression_parser.ggs', line 654
518, // index 170 : <select_gtl_5F_expression_5F_parser_20>, in file 'gtl_expression_parser.ggs', line 691
519, // index 171 : <select_gtl_5F_expression_5F_parser_20>, in file 'gtl_expression_parser.ggs', line 691
524, // index 172 : <select_gtl_5F_expression_5F_parser_21>, in file 'gtl_expression_parser.ggs', line 693
529, // index 173 : <select_gtl_5F_expression_5F_parser_21>, in file 'gtl_expression_parser.ggs', line 693
530, // index 174 : <select_gtl_5F_expression_5F_parser_22>, in file 'gtl_expression_parser.ggs', line 698
535, // index 175 : <select_gtl_5F_expression_5F_parser_22>, in file 'gtl_expression_parser.ggs', line 698
536, // index 176 : <select_gtl_5F_expression_5F_parser_23>, in file 'gtl_expression_parser.ggs', line 703
537, // index 177 : <select_gtl_5F_expression_5F_parser_23>, in file 'gtl_expression_parser.ggs', line 703
542, // index 178 : <select_gtl_5F_expression_5F_parser_24>, in file 'gtl_expression_parser.ggs', line 726
544, // index 179 : <select_gtl_5F_expression_5F_parser_24>, in file 'gtl_expression_parser.ggs', line 726
546, // index 180 : <select_gtl_5F_expression_5F_parser_25>, in file 'gtl_expression_parser.ggs', line 741
550, // index 181 : <select_gtl_5F_expression_5F_parser_25>, in file 'gtl_expression_parser.ggs', line 741
551, // index 182 : <select_gtl_5F_expression_5F_parser_26>, in file 'gtl_expression_parser.ggs', line 742
552, // index 183 : <select_gtl_5F_expression_5F_parser_26>, in file 'gtl_expression_parser.ggs', line 742
557, // index 184 : <select_gtl_5F_expression_5F_parser_27>, in file 'gtl_expression_parser.ggs', line 744
561, // index 185 : <select_gtl_5F_expression_5F_parser_27>, in file 'gtl_expression_parser.ggs', line 744
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
592, // index 196 : <select_gtl_5F_instruction_5F_parser_0>, in file 'gtl_instruction_parser.ggs', line 45
595, // index 197 : <select_gtl_5F_instruction_5F_parser_0>, in file 'gtl_instruction_parser.ggs', line 45
596, // index 198 : <select_gtl_5F_instruction_5F_parser_1>, in file 'gtl_instruction_parser.ggs', line 222
598, // index 199 : <select_gtl_5F_instruction_5F_parser_1>, in file 'gtl_instruction_parser.ggs', line 222
599, // index 200 : <select_gtl_5F_instruction_5F_parser_2>, in file 'gtl_instruction_parser.ggs', line 261
604, // index 201 : <select_gtl_5F_instruction_5F_parser_2>, in file 'gtl_instruction_parser.ggs', line 261
606, // index 202 : <select_gtl_5F_instruction_5F_parser_3>, in file 'gtl_instruction_parser.ggs', line 264
607, // index 203 : <select_gtl_5F_instruction_5F_parser_3>, in file 'gtl_instruction_parser.ggs', line 264
612, // index 204 : <select_gtl_5F_instruction_5F_parser_4>, in file 'gtl_instruction_parser.ggs', line 334
613, // index 205 : <select_gtl_5F_instruction_5F_parser_4>, in file 'gtl_instruction_parser.ggs', line 334
617, // index 206 : <select_gtl_5F_instruction_5F_parser_5>, in file 'gtl_instruction_parser.ggs', line 337
618, // index 207 : <select_gtl_5F_instruction_5F_parser_5>, in file 'gtl_instruction_parser.ggs', line 337
622, // index 208 : <select_gtl_5F_instruction_5F_parser_6>, in file 'gtl_instruction_parser.ggs', line 358
624, // index 209 : <select_gtl_5F_instruction_5F_parser_6>, in file 'gtl_instruction_parser.ggs', line 358
626 // index 210 : <>, in file '.ggs', line 0
} ;

//--------------------------------------------------------------------------------------------------
//
//                 L L ( 1 )    F I R S T    P R O D U C T I O N    I N D E X E S                   
//
//--------------------------------------------------------------------------------------------------

static const int32_t gFirstProductionIndexes_gtl_grammar [79] = {
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
63, // at 15 : <gtl_sorting_order>
64, // at 16 : <select_gtl_5F_parser_0>
66, // at 17 : <select_gtl_5F_parser_1>
69, // at 18 : <select_gtl_5F_parser_2>
71, // at 19 : <select_gtl_5F_parser_3>
73, // at 20 : <select_gtl_5F_parser_4>
75, // at 21 : <select_gtl_5F_parser_5>
77, // at 22 : <select_gtl_5F_parser_6>
79, // at 23 : <select_gtl_5F_parser_7>
81, // at 24 : <select_gtl_5F_parser_8>
83, // at 25 : <select_gtl_5F_parser_9>
85, // at 26 : <select_gtl_5F_parser_10>
87, // at 27 : <select_gtl_5F_parser_11>
89, // at 28 : <select_gtl_5F_parser_12>
91, // at 29 : <select_gtl_5F_parser_13>
93, // at 30 : <select_gtl_5F_parser_14>
95, // at 31 : <select_gtl_5F_parser_15>
97, // at 32 : <select_gtl_5F_parser_16>
99, // at 33 : <select_gtl_5F_parser_17>
101, // at 34 : <select_gtl_5F_parser_18>
103, // at 35 : <select_gtl_5F_parser_19>
106, // at 36 : <select_gtl_5F_parser_20>
108, // at 37 : <select_gtl_5F_parser_21>
110, // at 38 : <select_gtl_5F_parser_22>
112, // at 39 : <select_gtl_5F_parser_23>
114, // at 40 : <select_gtl_5F_parser_24>
116, // at 41 : <select_gtl_5F_parser_25>
118, // at 42 : <select_gtl_5F_expression_5F_parser_0>
121, // at 43 : <select_gtl_5F_expression_5F_parser_1>
123, // at 44 : <select_gtl_5F_expression_5F_parser_2>
130, // at 45 : <select_gtl_5F_expression_5F_parser_3>
136, // at 46 : <select_gtl_5F_expression_5F_parser_4>
140, // at 47 : <select_gtl_5F_expression_5F_parser_5>
142, // at 48 : <select_gtl_5F_expression_5F_parser_6>
144, // at 49 : <select_gtl_5F_expression_5F_parser_7>
146, // at 50 : <select_gtl_5F_expression_5F_parser_8>
148, // at 51 : <select_gtl_5F_expression_5F_parser_9>
150, // at 52 : <select_gtl_5F_expression_5F_parser_10>
152, // at 53 : <select_gtl_5F_expression_5F_parser_11>
154, // at 54 : <select_gtl_5F_expression_5F_parser_12>
156, // at 55 : <select_gtl_5F_expression_5F_parser_13>
158, // at 56 : <select_gtl_5F_expression_5F_parser_14>
160, // at 57 : <select_gtl_5F_expression_5F_parser_15>
162, // at 58 : <select_gtl_5F_expression_5F_parser_16>
164, // at 59 : <select_gtl_5F_expression_5F_parser_17>
166, // at 60 : <select_gtl_5F_expression_5F_parser_18>
168, // at 61 : <select_gtl_5F_expression_5F_parser_19>
170, // at 62 : <select_gtl_5F_expression_5F_parser_20>
172, // at 63 : <select_gtl_5F_expression_5F_parser_21>
174, // at 64 : <select_gtl_5F_expression_5F_parser_22>
176, // at 65 : <select_gtl_5F_expression_5F_parser_23>
178, // at 66 : <select_gtl_5F_expression_5F_parser_24>
180, // at 67 : <select_gtl_5F_expression_5F_parser_25>
182, // at 68 : <select_gtl_5F_expression_5F_parser_26>
184, // at 69 : <select_gtl_5F_expression_5F_parser_27>
186, // at 70 : <select_gtl_5F_instruction_5F_parser_0>
198, // at 71 : <select_gtl_5F_instruction_5F_parser_1>
200, // at 72 : <select_gtl_5F_instruction_5F_parser_2>
202, // at 73 : <select_gtl_5F_instruction_5F_parser_3>
204, // at 74 : <select_gtl_5F_instruction_5F_parser_4>
206, // at 75 : <select_gtl_5F_instruction_5F_parser_5>
208, // at 76 : <select_gtl_5F_instruction_5F_parser_6>
210, // at 77 : <>
0} ;

//--------------------------------------------------------------------------------------------------
//
//                          L L ( 1 )    D E C I S I O N    T A B L E S                             
//
//--------------------------------------------------------------------------------------------------

static const int32_t gDecision_gtl_grammar [] = {
// At index 0 : <gtl_expression> only one production, no choice
  -1,
// At index 1 : <gtl_variable> only one production, no choice
  -1,
// At index 2 : <gtl_variable_or_here> only one production, no choice
  -1,
// At index 3 : <gtl_import> only one production, no choice
  -1,
// At index 4 : <gtl_simple_instruction>
Lexique_gtl_5F_scanner::kToken_let, -1, // Choice 1
Lexique_gtl_5F_scanner::kToken_unlet, -1, // Choice 2
Lexique_gtl_5F_scanner::kToken_error, -1, // Choice 3
Lexique_gtl_5F_scanner::kToken_warning, -1, // Choice 4
Lexique_gtl_5F_scanner::kToken_print, -1, // Choice 5
Lexique_gtl_5F_scanner::kToken_println, -1, // Choice 6
Lexique_gtl_5F_scanner::kToken_display, -1, // Choice 7
Lexique_gtl_5F_scanner::kToken_sort, -1, // Choice 8
Lexique_gtl_5F_scanner::kToken_tab, -1, // Choice 9
Lexique_gtl_5F_scanner::kToken_variables, -1, // Choice 10
Lexique_gtl_5F_scanner::kToken_libraries, -1, // Choice 11
Lexique_gtl_5F_scanner::kToken__5B__21_, -1, // Choice 12
  -1,
// At index 29 : <gtl_argument_list> only one production, no choice
  -1,
// At index 30 : <gtl_start_symbol> only one production, no choice
  -1,
// At index 31 : <gtl_template_instruction_list> only one production, no choice
  -1,
// At index 32 : <gtl_template_instruction>
Lexique_gtl_5F_scanner::kToken__21_, -1, // Choice 1
Lexique_gtl_5F_scanner::kToken_write, -1, // Choice 2
Lexique_gtl_5F_scanner::kToken_template, -1, // Choice 3
Lexique_gtl_5F_scanner::kToken__3F_, -1, // Choice 4
Lexique_gtl_5F_scanner::kToken_if, -1, // Choice 5
Lexique_gtl_5F_scanner::kToken_foreach, -1, // Choice 6
Lexique_gtl_5F_scanner::kToken_for, -1, // Choice 7
Lexique_gtl_5F_scanner::kToken_loop, -1, // Choice 8
Lexique_gtl_5F_scanner::kToken_repeat, -1, // Choice 9
Lexique_gtl_5F_scanner::kToken_input, -1, // Choice 10
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
Lexique_gtl_5F_scanner::kToken__28_, -1, // Choice 1
Lexique_gtl_5F_scanner::kToken_not, -1, // Choice 2
Lexique_gtl_5F_scanner::kToken__7E_, -1, // Choice 3
Lexique_gtl_5F_scanner::kToken__2D_, -1, // Choice 4
Lexique_gtl_5F_scanner::kToken__2B_, -1, // Choice 5
Lexique_gtl_5F_scanner::kToken_yes, -1, // Choice 6
Lexique_gtl_5F_scanner::kToken_no, -1, // Choice 7
Lexique_gtl_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint, -1, // Choice 8
Lexique_gtl_5F_scanner::kToken_literal_5F_double, -1, // Choice 9
Lexique_gtl_5F_scanner::kToken_string, -1, // Choice 10
Lexique_gtl_5F_scanner::kToken_literal_5F_char, -1, // Choice 11
Lexique_gtl_5F_scanner::kToken__5B_, -1, // Choice 12
Lexique_gtl_5F_scanner::kToken_identifier, -1, // Choice 13
Lexique_gtl_5F_scanner::kToken_exists, -1, // Choice 14
Lexique_gtl_5F_scanner::kToken_typeof, -1, // Choice 15
Lexique_gtl_5F_scanner::kToken_true, -1, // Choice 16
Lexique_gtl_5F_scanner::kToken_false, -1, // Choice 17
Lexique_gtl_5F_scanner::kToken_literal_5F_enum, -1, // Choice 18
Lexique_gtl_5F_scanner::kToken__40_, -1, // Choice 19
Lexique_gtl_5F_scanner::kToken_emptylist, -1, // Choice 20
Lexique_gtl_5F_scanner::kToken_emptymap, -1, // Choice 21
Lexique_gtl_5F_scanner::kToken_mapof, -1, // Choice 22
Lexique_gtl_5F_scanner::kToken_listof, -1, // Choice 23
Lexique_gtl_5F_scanner::kToken__40__28_, -1, // Choice 24
Lexique_gtl_5F_scanner::kToken__40__5B_, -1, // Choice 25
Lexique_gtl_5F_scanner::kToken__40__7B_, -1, // Choice 26
Lexique_gtl_5F_scanner::kToken__40__21_, -1, // Choice 27
Lexique_gtl_5F_scanner::kToken__40__3F_, -1, // Choice 28
Lexique_gtl_5F_scanner::kToken__5F__5F_VARS_5F__5F_, -1, // Choice 29
  -1,
// At index 117 : <gtl_sorting_order> only one production, no choice
  -1,
//---- Added non terminal symbols from 'select' and 'repeat' instructions
// At index 118 : <select_gtl_5F_parser_0>
Lexique_gtl_5F_scanner::kToken__21_, Lexique_gtl_5F_scanner::kToken_write, Lexique_gtl_5F_scanner::kToken_template, Lexique_gtl_5F_scanner::kToken_if, Lexique_gtl_5F_scanner::kToken__3F_, Lexique_gtl_5F_scanner::kToken_foreach, Lexique_gtl_5F_scanner::kToken_for, Lexique_gtl_5F_scanner::kToken_loop, Lexique_gtl_5F_scanner::kToken_repeat, Lexique_gtl_5F_scanner::kToken_input, Lexique_gtl_5F_scanner::kToken_let, Lexique_gtl_5F_scanner::kToken_unlet, Lexique_gtl_5F_scanner::kToken_error, Lexique_gtl_5F_scanner::kToken_warning, Lexique_gtl_5F_scanner::kToken_print, Lexique_gtl_5F_scanner::kToken_println, Lexique_gtl_5F_scanner::kToken_display, Lexique_gtl_5F_scanner::kToken_sort, Lexique_gtl_5F_scanner::kToken_tab, Lexique_gtl_5F_scanner::kToken_variables, Lexique_gtl_5F_scanner::kToken_libraries, Lexique_gtl_5F_scanner::kToken__5B__21_, Lexique_gtl_5F_scanner::kToken_, -1, // Choice 1
Lexique_gtl_5F_scanner::kToken_import, -1, // Choice 2
  -1,
// At index 145 : <select_gtl_5F_parser_1>
Lexique_gtl_5F_scanner::kToken_end, Lexique_gtl_5F_scanner::kToken_elsif, Lexique_gtl_5F_scanner::kToken_else, Lexique_gtl_5F_scanner::kToken_do, Lexique_gtl_5F_scanner::kToken_between, Lexique_gtl_5F_scanner::kToken_after, Lexique_gtl_5F_scanner::kToken_while, Lexique_gtl_5F_scanner::kToken_, -1, // Choice 1
Lexique_gtl_5F_scanner::kToken__21_, Lexique_gtl_5F_scanner::kToken_write, Lexique_gtl_5F_scanner::kToken_template, Lexique_gtl_5F_scanner::kToken_if, Lexique_gtl_5F_scanner::kToken__3F_, Lexique_gtl_5F_scanner::kToken_foreach, Lexique_gtl_5F_scanner::kToken_for, Lexique_gtl_5F_scanner::kToken_loop, Lexique_gtl_5F_scanner::kToken_repeat, Lexique_gtl_5F_scanner::kToken_input, -1, // Choice 2
Lexique_gtl_5F_scanner::kToken_let, Lexique_gtl_5F_scanner::kToken_unlet, Lexique_gtl_5F_scanner::kToken_error, Lexique_gtl_5F_scanner::kToken_warning, Lexique_gtl_5F_scanner::kToken_print, Lexique_gtl_5F_scanner::kToken_println, Lexique_gtl_5F_scanner::kToken_display, Lexique_gtl_5F_scanner::kToken_sort, Lexique_gtl_5F_scanner::kToken_tab, Lexique_gtl_5F_scanner::kToken_variables, Lexique_gtl_5F_scanner::kToken_libraries, Lexique_gtl_5F_scanner::kToken__5B__21_, -1, // Choice 3
  -1,
// At index 179 : <select_gtl_5F_parser_2>
Lexique_gtl_5F_scanner::kToken_executable, -1, // Choice 1
Lexique_gtl_5F_scanner::kToken__28_, Lexique_gtl_5F_scanner::kToken_exists, Lexique_gtl_5F_scanner::kToken_identifier, Lexique_gtl_5F_scanner::kToken__2B_, Lexique_gtl_5F_scanner::kToken__2D_, Lexique_gtl_5F_scanner::kToken_not, Lexique_gtl_5F_scanner::kToken__7E_, Lexique_gtl_5F_scanner::kToken_yes, Lexique_gtl_5F_scanner::kToken_no, Lexique_gtl_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint, Lexique_gtl_5F_scanner::kToken_literal_5F_double, Lexique_gtl_5F_scanner::kToken_string, Lexique_gtl_5F_scanner::kToken_literal_5F_char, Lexique_gtl_5F_scanner::kToken__5B_, Lexique_gtl_5F_scanner::kToken_typeof, Lexique_gtl_5F_scanner::kToken_true, Lexique_gtl_5F_scanner::kToken_false, Lexique_gtl_5F_scanner::kToken_literal_5F_enum, Lexique_gtl_5F_scanner::kToken__40_, Lexique_gtl_5F_scanner::kToken_emptylist, Lexique_gtl_5F_scanner::kToken_emptymap, Lexique_gtl_5F_scanner::kToken_mapof, Lexique_gtl_5F_scanner::kToken_listof, Lexique_gtl_5F_scanner::kToken__40__28_, Lexique_gtl_5F_scanner::kToken__40__5B_, Lexique_gtl_5F_scanner::kToken__40__7B_, Lexique_gtl_5F_scanner::kToken__40__21_, Lexique_gtl_5F_scanner::kToken__40__3F_, Lexique_gtl_5F_scanner::kToken__5F__5F_VARS_5F__5F_, -1, // Choice 2
  -1,
// At index 212 : <select_gtl_5F_parser_3>
Lexique_gtl_5F_scanner::kToken__28_, -1, // Choice 1
Lexique_gtl_5F_scanner::kToken_if, Lexique_gtl_5F_scanner::kToken_identifier, Lexique_gtl_5F_scanner::kToken_from, -1, // Choice 2
  -1,
// At index 219 : <select_gtl_5F_parser_4>
Lexique_gtl_5F_scanner::kToken__28_, Lexique_gtl_5F_scanner::kToken_exists, Lexique_gtl_5F_scanner::kToken_identifier, Lexique_gtl_5F_scanner::kToken__2B_, Lexique_gtl_5F_scanner::kToken__2D_, Lexique_gtl_5F_scanner::kToken_not, Lexique_gtl_5F_scanner::kToken__7E_, Lexique_gtl_5F_scanner::kToken_yes, Lexique_gtl_5F_scanner::kToken_no, Lexique_gtl_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint, Lexique_gtl_5F_scanner::kToken_literal_5F_double, Lexique_gtl_5F_scanner::kToken_string, Lexique_gtl_5F_scanner::kToken_literal_5F_char, Lexique_gtl_5F_scanner::kToken__5B_, Lexique_gtl_5F_scanner::kToken_typeof, Lexique_gtl_5F_scanner::kToken_true, Lexique_gtl_5F_scanner::kToken_false, Lexique_gtl_5F_scanner::kToken_literal_5F_enum, Lexique_gtl_5F_scanner::kToken__40_, Lexique_gtl_5F_scanner::kToken_emptylist, Lexique_gtl_5F_scanner::kToken_emptymap, Lexique_gtl_5F_scanner::kToken_mapof, Lexique_gtl_5F_scanner::kToken_listof, Lexique_gtl_5F_scanner::kToken__40__28_, Lexique_gtl_5F_scanner::kToken__40__5B_, Lexique_gtl_5F_scanner::kToken__40__7B_, Lexique_gtl_5F_scanner::kToken__40__21_, Lexique_gtl_5F_scanner::kToken__40__3F_, Lexique_gtl_5F_scanner::kToken__5F__5F_VARS_5F__5F_, -1, // Choice 1
Lexique_gtl_5F_scanner::kToken__29_, -1, // Choice 2
  -1,
// At index 252 : <select_gtl_5F_parser_5>
Lexique_gtl_5F_scanner::kToken__29_, -1, // Choice 1
Lexique_gtl_5F_scanner::kToken__2C_, -1, // Choice 2
  -1,
// At index 257 : <select_gtl_5F_parser_6>
Lexique_gtl_5F_scanner::kToken_if, -1, // Choice 1
Lexique_gtl_5F_scanner::kToken_identifier, Lexique_gtl_5F_scanner::kToken_from, -1, // Choice 2
  -1,
// At index 263 : <select_gtl_5F_parser_7>
Lexique_gtl_5F_scanner::kToken_in, -1, // Choice 1
Lexique_gtl_5F_scanner::kToken__21_, Lexique_gtl_5F_scanner::kToken_write, Lexique_gtl_5F_scanner::kToken_end, Lexique_gtl_5F_scanner::kToken_template, Lexique_gtl_5F_scanner::kToken_if, Lexique_gtl_5F_scanner::kToken_or, Lexique_gtl_5F_scanner::kToken__3F_, Lexique_gtl_5F_scanner::kToken_elsif, Lexique_gtl_5F_scanner::kToken_else, Lexique_gtl_5F_scanner::kToken_foreach, Lexique_gtl_5F_scanner::kToken_do, Lexique_gtl_5F_scanner::kToken_between, Lexique_gtl_5F_scanner::kToken_after, Lexique_gtl_5F_scanner::kToken_for, Lexique_gtl_5F_scanner::kToken_loop, Lexique_gtl_5F_scanner::kToken_repeat, Lexique_gtl_5F_scanner::kToken_while, Lexique_gtl_5F_scanner::kToken_input, Lexique_gtl_5F_scanner::kToken_let, Lexique_gtl_5F_scanner::kToken_unlet, Lexique_gtl_5F_scanner::kToken_error, Lexique_gtl_5F_scanner::kToken_warning, Lexique_gtl_5F_scanner::kToken_print, Lexique_gtl_5F_scanner::kToken_println, Lexique_gtl_5F_scanner::kToken_display, Lexique_gtl_5F_scanner::kToken_sort, Lexique_gtl_5F_scanner::kToken_tab, Lexique_gtl_5F_scanner::kToken_variables, Lexique_gtl_5F_scanner::kToken_libraries, Lexique_gtl_5F_scanner::kToken__5B__21_, Lexique_gtl_5F_scanner::kToken_, -1, // Choice 2
  -1,
// At index 298 : <select_gtl_5F_parser_8>
Lexique_gtl_5F_scanner::kToken_or, -1, // Choice 1
Lexique_gtl_5F_scanner::kToken__21_, Lexique_gtl_5F_scanner::kToken_write, Lexique_gtl_5F_scanner::kToken_end, Lexique_gtl_5F_scanner::kToken_template, Lexique_gtl_5F_scanner::kToken_if, Lexique_gtl_5F_scanner::kToken__3F_, Lexique_gtl_5F_scanner::kToken_elsif, Lexique_gtl_5F_scanner::kToken_else, Lexique_gtl_5F_scanner::kToken_foreach, Lexique_gtl_5F_scanner::kToken_do, Lexique_gtl_5F_scanner::kToken_between, Lexique_gtl_5F_scanner::kToken_after, Lexique_gtl_5F_scanner::kToken_for, Lexique_gtl_5F_scanner::kToken_loop, Lexique_gtl_5F_scanner::kToken_repeat, Lexique_gtl_5F_scanner::kToken_while, Lexique_gtl_5F_scanner::kToken_input, Lexique_gtl_5F_scanner::kToken_let, Lexique_gtl_5F_scanner::kToken_unlet, Lexique_gtl_5F_scanner::kToken_error, Lexique_gtl_5F_scanner::kToken_warning, Lexique_gtl_5F_scanner::kToken_print, Lexique_gtl_5F_scanner::kToken_println, Lexique_gtl_5F_scanner::kToken_display, Lexique_gtl_5F_scanner::kToken_sort, Lexique_gtl_5F_scanner::kToken_tab, Lexique_gtl_5F_scanner::kToken_variables, Lexique_gtl_5F_scanner::kToken_libraries, Lexique_gtl_5F_scanner::kToken__5B__21_, Lexique_gtl_5F_scanner::kToken_, -1, // Choice 2
  -1,
// At index 332 : <select_gtl_5F_parser_9>
Lexique_gtl_5F_scanner::kToken_in, -1, // Choice 1
Lexique_gtl_5F_scanner::kToken__21_, Lexique_gtl_5F_scanner::kToken_write, Lexique_gtl_5F_scanner::kToken_end, Lexique_gtl_5F_scanner::kToken_template, Lexique_gtl_5F_scanner::kToken_if, Lexique_gtl_5F_scanner::kToken__3F_, Lexique_gtl_5F_scanner::kToken_elsif, Lexique_gtl_5F_scanner::kToken_else, Lexique_gtl_5F_scanner::kToken_foreach, Lexique_gtl_5F_scanner::kToken_do, Lexique_gtl_5F_scanner::kToken_between, Lexique_gtl_5F_scanner::kToken_after, Lexique_gtl_5F_scanner::kToken_for, Lexique_gtl_5F_scanner::kToken_loop, Lexique_gtl_5F_scanner::kToken_repeat, Lexique_gtl_5F_scanner::kToken_while, Lexique_gtl_5F_scanner::kToken_input, Lexique_gtl_5F_scanner::kToken_let, Lexique_gtl_5F_scanner::kToken_unlet, Lexique_gtl_5F_scanner::kToken_error, Lexique_gtl_5F_scanner::kToken_warning, Lexique_gtl_5F_scanner::kToken_print, Lexique_gtl_5F_scanner::kToken_println, Lexique_gtl_5F_scanner::kToken_display, Lexique_gtl_5F_scanner::kToken_sort, Lexique_gtl_5F_scanner::kToken_tab, Lexique_gtl_5F_scanner::kToken_variables, Lexique_gtl_5F_scanner::kToken_libraries, Lexique_gtl_5F_scanner::kToken__5B__21_, Lexique_gtl_5F_scanner::kToken_, -1, // Choice 2
  -1,
// At index 366 : <select_gtl_5F_parser_10>
Lexique_gtl_5F_scanner::kToken_end, Lexique_gtl_5F_scanner::kToken_else, -1, // Choice 1
Lexique_gtl_5F_scanner::kToken_elsif, -1, // Choice 2
  -1,
// At index 372 : <select_gtl_5F_parser_11>
Lexique_gtl_5F_scanner::kToken_else, -1, // Choice 1
Lexique_gtl_5F_scanner::kToken_end, -1, // Choice 2
  -1,
// At index 377 : <select_gtl_5F_parser_12>
Lexique_gtl_5F_scanner::kToken__2C_, -1, // Choice 1
Lexique_gtl_5F_scanner::kToken__28_, Lexique_gtl_5F_scanner::kToken_in, -1, // Choice 2
  -1,
// At index 383 : <select_gtl_5F_parser_13>
Lexique_gtl_5F_scanner::kToken__28_, -1, // Choice 1
Lexique_gtl_5F_scanner::kToken_in, -1, // Choice 2
  -1,
// At index 388 : <select_gtl_5F_parser_14>
Lexique_gtl_5F_scanner::kToken_before, -1, // Choice 1
Lexique_gtl_5F_scanner::kToken_do, -1, // Choice 2
  -1,
// At index 393 : <select_gtl_5F_parser_15>
Lexique_gtl_5F_scanner::kToken_between, -1, // Choice 1
Lexique_gtl_5F_scanner::kToken_end, Lexique_gtl_5F_scanner::kToken_after, -1, // Choice 2
  -1,
// At index 399 : <select_gtl_5F_parser_16>
Lexique_gtl_5F_scanner::kToken_after, -1, // Choice 1
Lexique_gtl_5F_scanner::kToken_end, -1, // Choice 2
  -1,
// At index 404 : <select_gtl_5F_parser_17>
Lexique_gtl_5F_scanner::kToken_do, -1, // Choice 1
Lexique_gtl_5F_scanner::kToken__2C_, -1, // Choice 2
  -1,
// At index 409 : <select_gtl_5F_parser_18>
Lexique_gtl_5F_scanner::kToken_between, -1, // Choice 1
Lexique_gtl_5F_scanner::kToken_end, -1, // Choice 2
  -1,
// At index 414 : <select_gtl_5F_parser_19>
Lexique_gtl_5F_scanner::kToken_to, -1, // Choice 1
Lexique_gtl_5F_scanner::kToken_up, -1, // Choice 2
Lexique_gtl_5F_scanner::kToken_down, -1, // Choice 3
  -1,
// At index 421 : <select_gtl_5F_parser_20>
Lexique_gtl_5F_scanner::kToken_step, -1, // Choice 1
Lexique_gtl_5F_scanner::kToken_before, Lexique_gtl_5F_scanner::kToken_do, -1, // Choice 2
  -1,
// At index 427 : <select_gtl_5F_parser_21>
Lexique_gtl_5F_scanner::kToken_before, -1, // Choice 1
Lexique_gtl_5F_scanner::kToken_do, -1, // Choice 2
  -1,
// At index 432 : <select_gtl_5F_parser_22>
Lexique_gtl_5F_scanner::kToken_between, -1, // Choice 1
Lexique_gtl_5F_scanner::kToken_end, Lexique_gtl_5F_scanner::kToken_after, -1, // Choice 2
  -1,
// At index 438 : <select_gtl_5F_parser_23>
Lexique_gtl_5F_scanner::kToken_after, -1, // Choice 1
Lexique_gtl_5F_scanner::kToken_end, -1, // Choice 2
  -1,
// At index 443 : <select_gtl_5F_parser_24>
Lexique_gtl_5F_scanner::kToken__28_, -1, // Choice 1
Lexique_gtl_5F_scanner::kToken__21_, Lexique_gtl_5F_scanner::kToken_write, Lexique_gtl_5F_scanner::kToken_template, Lexique_gtl_5F_scanner::kToken_if, Lexique_gtl_5F_scanner::kToken__3F_, Lexique_gtl_5F_scanner::kToken_foreach, Lexique_gtl_5F_scanner::kToken_for, Lexique_gtl_5F_scanner::kToken_loop, Lexique_gtl_5F_scanner::kToken_repeat, Lexique_gtl_5F_scanner::kToken_while, Lexique_gtl_5F_scanner::kToken_input, Lexique_gtl_5F_scanner::kToken_let, Lexique_gtl_5F_scanner::kToken_unlet, Lexique_gtl_5F_scanner::kToken_error, Lexique_gtl_5F_scanner::kToken_warning, Lexique_gtl_5F_scanner::kToken_print, Lexique_gtl_5F_scanner::kToken_println, Lexique_gtl_5F_scanner::kToken_display, Lexique_gtl_5F_scanner::kToken_sort, Lexique_gtl_5F_scanner::kToken_tab, Lexique_gtl_5F_scanner::kToken_variables, Lexique_gtl_5F_scanner::kToken_libraries, Lexique_gtl_5F_scanner::kToken__5B__21_, -1, // Choice 2
  -1,
// At index 470 : <select_gtl_5F_parser_25>
Lexique_gtl_5F_scanner::kToken_identifier, -1, // Choice 1
Lexique_gtl_5F_scanner::kToken_from, -1, // Choice 2
  -1,
// At index 475 : <select_gtl_5F_expression_5F_parser_0>
Lexique_gtl_5F_scanner::kToken__21_, Lexique_gtl_5F_scanner::kToken_write, Lexique_gtl_5F_scanner::kToken_to, Lexique_gtl_5F_scanner::kToken__3A_, Lexique_gtl_5F_scanner::kToken_end, Lexique_gtl_5F_scanner::kToken_template, Lexique_gtl_5F_scanner::kToken__2C_, Lexique_gtl_5F_scanner::kToken__29_, Lexique_gtl_5F_scanner::kToken_if, Lexique_gtl_5F_scanner::kToken_in, Lexique_gtl_5F_scanner::kToken_identifier, Lexique_gtl_5F_scanner::kToken_or, Lexique_gtl_5F_scanner::kToken__3F_, Lexique_gtl_5F_scanner::kToken_then, Lexique_gtl_5F_scanner::kToken_elsif, Lexique_gtl_5F_scanner::kToken_else, Lexique_gtl_5F_scanner::kToken_foreach, Lexique_gtl_5F_scanner::kToken_before, Lexique_gtl_5F_scanner::kToken_do, Lexique_gtl_5F_scanner::kToken_between, Lexique_gtl_5F_scanner::kToken_after, Lexique_gtl_5F_scanner::kToken_for, Lexique_gtl_5F_scanner::kToken_loop, Lexique_gtl_5F_scanner::kToken_up, Lexique_gtl_5F_scanner::kToken_down, Lexique_gtl_5F_scanner::kToken_step, Lexique_gtl_5F_scanner::kToken_repeat, Lexique_gtl_5F_scanner::kToken_while, Lexique_gtl_5F_scanner::kToken_input, Lexique_gtl_5F_scanner::kToken__5D_, Lexique_gtl_5F_scanner::kToken_by, Lexique_gtl_5F_scanner::kToken__7D_, Lexique_gtl_5F_scanner::kToken_let, Lexique_gtl_5F_scanner::kToken_unlet, Lexique_gtl_5F_scanner::kToken_error, Lexique_gtl_5F_scanner::kToken_warning, Lexique_gtl_5F_scanner::kToken_print, Lexique_gtl_5F_scanner::kToken_println, Lexique_gtl_5F_scanner::kToken_display, Lexique_gtl_5F_scanner::kToken_sort, Lexique_gtl_5F_scanner::kToken_tab, Lexique_gtl_5F_scanner::kToken_variables, Lexique_gtl_5F_scanner::kToken_libraries, Lexique_gtl_5F_scanner::kToken__5B__21_, Lexique_gtl_5F_scanner::kToken_, -1, // Choice 1
Lexique_gtl_5F_scanner::kToken__7C_, -1, // Choice 2
Lexique_gtl_5F_scanner::kToken__5E_, -1, // Choice 3
  -1,
// At index 526 : <select_gtl_5F_expression_5F_parser_1>
Lexique_gtl_5F_scanner::kToken__21_, Lexique_gtl_5F_scanner::kToken_write, Lexique_gtl_5F_scanner::kToken_to, Lexique_gtl_5F_scanner::kToken__3A_, Lexique_gtl_5F_scanner::kToken_end, Lexique_gtl_5F_scanner::kToken_template, Lexique_gtl_5F_scanner::kToken__2C_, Lexique_gtl_5F_scanner::kToken__29_, Lexique_gtl_5F_scanner::kToken_if, Lexique_gtl_5F_scanner::kToken_in, Lexique_gtl_5F_scanner::kToken_identifier, Lexique_gtl_5F_scanner::kToken_or, Lexique_gtl_5F_scanner::kToken__3F_, Lexique_gtl_5F_scanner::kToken_then, Lexique_gtl_5F_scanner::kToken_elsif, Lexique_gtl_5F_scanner::kToken_else, Lexique_gtl_5F_scanner::kToken_foreach, Lexique_gtl_5F_scanner::kToken_before, Lexique_gtl_5F_scanner::kToken_do, Lexique_gtl_5F_scanner::kToken_between, Lexique_gtl_5F_scanner::kToken_after, Lexique_gtl_5F_scanner::kToken_for, Lexique_gtl_5F_scanner::kToken_loop, Lexique_gtl_5F_scanner::kToken_up, Lexique_gtl_5F_scanner::kToken_down, Lexique_gtl_5F_scanner::kToken_step, Lexique_gtl_5F_scanner::kToken_repeat, Lexique_gtl_5F_scanner::kToken_while, Lexique_gtl_5F_scanner::kToken_input, Lexique_gtl_5F_scanner::kToken__7C_, Lexique_gtl_5F_scanner::kToken__5E_, Lexique_gtl_5F_scanner::kToken__5D_, Lexique_gtl_5F_scanner::kToken_by, Lexique_gtl_5F_scanner::kToken__7D_, Lexique_gtl_5F_scanner::kToken_let, Lexique_gtl_5F_scanner::kToken_unlet, Lexique_gtl_5F_scanner::kToken_error, Lexique_gtl_5F_scanner::kToken_warning, Lexique_gtl_5F_scanner::kToken_print, Lexique_gtl_5F_scanner::kToken_println, Lexique_gtl_5F_scanner::kToken_display, Lexique_gtl_5F_scanner::kToken_sort, Lexique_gtl_5F_scanner::kToken_tab, Lexique_gtl_5F_scanner::kToken_variables, Lexique_gtl_5F_scanner::kToken_libraries, Lexique_gtl_5F_scanner::kToken__5B__21_, Lexique_gtl_5F_scanner::kToken_, -1, // Choice 1
Lexique_gtl_5F_scanner::kToken__26_, -1, // Choice 2
  -1,
// At index 577 : <select_gtl_5F_expression_5F_parser_2>
Lexique_gtl_5F_scanner::kToken__21_, Lexique_gtl_5F_scanner::kToken_write, Lexique_gtl_5F_scanner::kToken_to, Lexique_gtl_5F_scanner::kToken__3A_, Lexique_gtl_5F_scanner::kToken_end, Lexique_gtl_5F_scanner::kToken_template, Lexique_gtl_5F_scanner::kToken__2C_, Lexique_gtl_5F_scanner::kToken__29_, Lexique_gtl_5F_scanner::kToken_if, Lexique_gtl_5F_scanner::kToken_in, Lexique_gtl_5F_scanner::kToken_identifier, Lexique_gtl_5F_scanner::kToken_or, Lexique_gtl_5F_scanner::kToken__3F_, Lexique_gtl_5F_scanner::kToken_then, Lexique_gtl_5F_scanner::kToken_elsif, Lexique_gtl_5F_scanner::kToken_else, Lexique_gtl_5F_scanner::kToken_foreach, Lexique_gtl_5F_scanner::kToken_before, Lexique_gtl_5F_scanner::kToken_do, Lexique_gtl_5F_scanner::kToken_between, Lexique_gtl_5F_scanner::kToken_after, Lexique_gtl_5F_scanner::kToken_for, Lexique_gtl_5F_scanner::kToken_loop, Lexique_gtl_5F_scanner::kToken_up, Lexique_gtl_5F_scanner::kToken_down, Lexique_gtl_5F_scanner::kToken_step, Lexique_gtl_5F_scanner::kToken_repeat, Lexique_gtl_5F_scanner::kToken_while, Lexique_gtl_5F_scanner::kToken_input, Lexique_gtl_5F_scanner::kToken__7C_, Lexique_gtl_5F_scanner::kToken__5E_, Lexique_gtl_5F_scanner::kToken__26_, Lexique_gtl_5F_scanner::kToken__5D_, Lexique_gtl_5F_scanner::kToken_by, Lexique_gtl_5F_scanner::kToken__7D_, Lexique_gtl_5F_scanner::kToken_let, Lexique_gtl_5F_scanner::kToken_unlet, Lexique_gtl_5F_scanner::kToken_error, Lexique_gtl_5F_scanner::kToken_warning, Lexique_gtl_5F_scanner::kToken_print, Lexique_gtl_5F_scanner::kToken_println, Lexique_gtl_5F_scanner::kToken_display, Lexique_gtl_5F_scanner::kToken_sort, Lexique_gtl_5F_scanner::kToken_tab, Lexique_gtl_5F_scanner::kToken_variables, Lexique_gtl_5F_scanner::kToken_libraries, Lexique_gtl_5F_scanner::kToken__5B__21_, Lexique_gtl_5F_scanner::kToken_, -1, // Choice 1
Lexique_gtl_5F_scanner::kToken__3D__3D_, -1, // Choice 2
Lexique_gtl_5F_scanner::kToken__21__3D_, -1, // Choice 3
Lexique_gtl_5F_scanner::kToken__3C__3D_, -1, // Choice 4
Lexique_gtl_5F_scanner::kToken__3E__3D_, -1, // Choice 5
Lexique_gtl_5F_scanner::kToken__3E_, -1, // Choice 6
Lexique_gtl_5F_scanner::kToken__3C_, -1, // Choice 7
  -1,
// At index 639 : <select_gtl_5F_expression_5F_parser_3>
Lexique_gtl_5F_scanner::kToken__21_, Lexique_gtl_5F_scanner::kToken_write, Lexique_gtl_5F_scanner::kToken_to, Lexique_gtl_5F_scanner::kToken__3A_, Lexique_gtl_5F_scanner::kToken_end, Lexique_gtl_5F_scanner::kToken_template, Lexique_gtl_5F_scanner::kToken__2C_, Lexique_gtl_5F_scanner::kToken__29_, Lexique_gtl_5F_scanner::kToken_if, Lexique_gtl_5F_scanner::kToken_in, Lexique_gtl_5F_scanner::kToken_identifier, Lexique_gtl_5F_scanner::kToken_or, Lexique_gtl_5F_scanner::kToken__3F_, Lexique_gtl_5F_scanner::kToken_then, Lexique_gtl_5F_scanner::kToken_elsif, Lexique_gtl_5F_scanner::kToken_else, Lexique_gtl_5F_scanner::kToken_foreach, Lexique_gtl_5F_scanner::kToken_before, Lexique_gtl_5F_scanner::kToken_do, Lexique_gtl_5F_scanner::kToken_between, Lexique_gtl_5F_scanner::kToken_after, Lexique_gtl_5F_scanner::kToken_for, Lexique_gtl_5F_scanner::kToken_loop, Lexique_gtl_5F_scanner::kToken_up, Lexique_gtl_5F_scanner::kToken_down, Lexique_gtl_5F_scanner::kToken_step, Lexique_gtl_5F_scanner::kToken_repeat, Lexique_gtl_5F_scanner::kToken_while, Lexique_gtl_5F_scanner::kToken_input, Lexique_gtl_5F_scanner::kToken__7C_, Lexique_gtl_5F_scanner::kToken__5E_, Lexique_gtl_5F_scanner::kToken__26_, Lexique_gtl_5F_scanner::kToken__3D__3D_, Lexique_gtl_5F_scanner::kToken__21__3D_, Lexique_gtl_5F_scanner::kToken__3C__3D_, Lexique_gtl_5F_scanner::kToken__3E__3D_, Lexique_gtl_5F_scanner::kToken__3E_, Lexique_gtl_5F_scanner::kToken__3C_, Lexique_gtl_5F_scanner::kToken__5D_, Lexique_gtl_5F_scanner::kToken_by, Lexique_gtl_5F_scanner::kToken__7D_, Lexique_gtl_5F_scanner::kToken_let, Lexique_gtl_5F_scanner::kToken_unlet, Lexique_gtl_5F_scanner::kToken_error, Lexique_gtl_5F_scanner::kToken_warning, Lexique_gtl_5F_scanner::kToken_print, Lexique_gtl_5F_scanner::kToken_println, Lexique_gtl_5F_scanner::kToken_display, Lexique_gtl_5F_scanner::kToken_sort, Lexique_gtl_5F_scanner::kToken_tab, Lexique_gtl_5F_scanner::kToken_variables, Lexique_gtl_5F_scanner::kToken_libraries, Lexique_gtl_5F_scanner::kToken__5B__21_, Lexique_gtl_5F_scanner::kToken_, -1, // Choice 1
Lexique_gtl_5F_scanner::kToken__3C__3C_, -1, // Choice 2
Lexique_gtl_5F_scanner::kToken__3E__3E_, -1, // Choice 3
Lexique_gtl_5F_scanner::kToken__2B_, -1, // Choice 4
Lexique_gtl_5F_scanner::kToken__2E_, -1, // Choice 5
Lexique_gtl_5F_scanner::kToken__2D_, -1, // Choice 6
  -1,
// At index 705 : <select_gtl_5F_expression_5F_parser_4>
Lexique_gtl_5F_scanner::kToken__21_, Lexique_gtl_5F_scanner::kToken_write, Lexique_gtl_5F_scanner::kToken_to, Lexique_gtl_5F_scanner::kToken__3A_, Lexique_gtl_5F_scanner::kToken_end, Lexique_gtl_5F_scanner::kToken_template, Lexique_gtl_5F_scanner::kToken__2C_, Lexique_gtl_5F_scanner::kToken__29_, Lexique_gtl_5F_scanner::kToken_if, Lexique_gtl_5F_scanner::kToken_in, Lexique_gtl_5F_scanner::kToken_identifier, Lexique_gtl_5F_scanner::kToken_or, Lexique_gtl_5F_scanner::kToken__3F_, Lexique_gtl_5F_scanner::kToken_then, Lexique_gtl_5F_scanner::kToken_elsif, Lexique_gtl_5F_scanner::kToken_else, Lexique_gtl_5F_scanner::kToken_foreach, Lexique_gtl_5F_scanner::kToken_before, Lexique_gtl_5F_scanner::kToken_do, Lexique_gtl_5F_scanner::kToken_between, Lexique_gtl_5F_scanner::kToken_after, Lexique_gtl_5F_scanner::kToken_for, Lexique_gtl_5F_scanner::kToken_loop, Lexique_gtl_5F_scanner::kToken_up, Lexique_gtl_5F_scanner::kToken_down, Lexique_gtl_5F_scanner::kToken_step, Lexique_gtl_5F_scanner::kToken_repeat, Lexique_gtl_5F_scanner::kToken_while, Lexique_gtl_5F_scanner::kToken_input, Lexique_gtl_5F_scanner::kToken__7C_, Lexique_gtl_5F_scanner::kToken__5E_, Lexique_gtl_5F_scanner::kToken__26_, Lexique_gtl_5F_scanner::kToken__3D__3D_, Lexique_gtl_5F_scanner::kToken__21__3D_, Lexique_gtl_5F_scanner::kToken__3C__3D_, Lexique_gtl_5F_scanner::kToken__3E__3D_, Lexique_gtl_5F_scanner::kToken__3E_, Lexique_gtl_5F_scanner::kToken__3C_, Lexique_gtl_5F_scanner::kToken__3C__3C_, Lexique_gtl_5F_scanner::kToken__3E__3E_, Lexique_gtl_5F_scanner::kToken__2B_, Lexique_gtl_5F_scanner::kToken__2E_, Lexique_gtl_5F_scanner::kToken__2D_, Lexique_gtl_5F_scanner::kToken__5D_, Lexique_gtl_5F_scanner::kToken_by, Lexique_gtl_5F_scanner::kToken__7D_, Lexique_gtl_5F_scanner::kToken_let, Lexique_gtl_5F_scanner::kToken_unlet, Lexique_gtl_5F_scanner::kToken_error, Lexique_gtl_5F_scanner::kToken_warning, Lexique_gtl_5F_scanner::kToken_print, Lexique_gtl_5F_scanner::kToken_println, Lexique_gtl_5F_scanner::kToken_display, Lexique_gtl_5F_scanner::kToken_sort, Lexique_gtl_5F_scanner::kToken_tab, Lexique_gtl_5F_scanner::kToken_variables, Lexique_gtl_5F_scanner::kToken_libraries, Lexique_gtl_5F_scanner::kToken__5B__21_, Lexique_gtl_5F_scanner::kToken_, -1, // Choice 1
Lexique_gtl_5F_scanner::kToken__2A_, -1, // Choice 2
Lexique_gtl_5F_scanner::kToken__2F_, -1, // Choice 3
Lexique_gtl_5F_scanner::kToken_mod, -1, // Choice 4
  -1,
// At index 772 : <select_gtl_5F_expression_5F_parser_5>
Lexique_gtl_5F_scanner::kToken__5D_, -1, // Choice 1
Lexique_gtl_5F_scanner::kToken__3A_, -1, // Choice 2
  -1,
// At index 777 : <select_gtl_5F_expression_5F_parser_6>
Lexique_gtl_5F_scanner::kToken__5D_, -1, // Choice 1
Lexique_gtl_5F_scanner::kToken__2C_, -1, // Choice 2
  -1,
// At index 782 : <select_gtl_5F_expression_5F_parser_7>
Lexique_gtl_5F_scanner::kToken__21_, Lexique_gtl_5F_scanner::kToken_write, Lexique_gtl_5F_scanner::kToken_to, Lexique_gtl_5F_scanner::kToken__3A_, Lexique_gtl_5F_scanner::kToken_end, Lexique_gtl_5F_scanner::kToken_template, Lexique_gtl_5F_scanner::kToken__2C_, Lexique_gtl_5F_scanner::kToken__29_, Lexique_gtl_5F_scanner::kToken_if, Lexique_gtl_5F_scanner::kToken_in, Lexique_gtl_5F_scanner::kToken_identifier, Lexique_gtl_5F_scanner::kToken_or, Lexique_gtl_5F_scanner::kToken__3F_, Lexique_gtl_5F_scanner::kToken_then, Lexique_gtl_5F_scanner::kToken_elsif, Lexique_gtl_5F_scanner::kToken_else, Lexique_gtl_5F_scanner::kToken_foreach, Lexique_gtl_5F_scanner::kToken_before, Lexique_gtl_5F_scanner::kToken_do, Lexique_gtl_5F_scanner::kToken_between, Lexique_gtl_5F_scanner::kToken_after, Lexique_gtl_5F_scanner::kToken_for, Lexique_gtl_5F_scanner::kToken_loop, Lexique_gtl_5F_scanner::kToken_up, Lexique_gtl_5F_scanner::kToken_down, Lexique_gtl_5F_scanner::kToken_step, Lexique_gtl_5F_scanner::kToken_repeat, Lexique_gtl_5F_scanner::kToken_while, Lexique_gtl_5F_scanner::kToken_input, Lexique_gtl_5F_scanner::kToken__7C_, Lexique_gtl_5F_scanner::kToken__5E_, Lexique_gtl_5F_scanner::kToken__26_, Lexique_gtl_5F_scanner::kToken__3D__3D_, Lexique_gtl_5F_scanner::kToken__21__3D_, Lexique_gtl_5F_scanner::kToken__3C__3D_, Lexique_gtl_5F_scanner::kToken__3E__3D_, Lexique_gtl_5F_scanner::kToken__3E_, Lexique_gtl_5F_scanner::kToken__3C_, Lexique_gtl_5F_scanner::kToken__3C__3C_, Lexique_gtl_5F_scanner::kToken__3E__3E_, Lexique_gtl_5F_scanner::kToken__2B_, Lexique_gtl_5F_scanner::kToken__2E_, Lexique_gtl_5F_scanner::kToken__2D_, Lexique_gtl_5F_scanner::kToken__2A_, Lexique_gtl_5F_scanner::kToken__2F_, Lexique_gtl_5F_scanner::kToken_mod, Lexique_gtl_5F_scanner::kToken__5D_, Lexique_gtl_5F_scanner::kToken_by, Lexique_gtl_5F_scanner::kToken__7D_, Lexique_gtl_5F_scanner::kToken_let, Lexique_gtl_5F_scanner::kToken_unlet, Lexique_gtl_5F_scanner::kToken_error, Lexique_gtl_5F_scanner::kToken_warning, Lexique_gtl_5F_scanner::kToken_print, Lexique_gtl_5F_scanner::kToken_println, Lexique_gtl_5F_scanner::kToken_display, Lexique_gtl_5F_scanner::kToken_sort, Lexique_gtl_5F_scanner::kToken_tab, Lexique_gtl_5F_scanner::kToken_variables, Lexique_gtl_5F_scanner::kToken_libraries, Lexique_gtl_5F_scanner::kToken__5B__21_, Lexique_gtl_5F_scanner::kToken_, -1, // Choice 1
Lexique_gtl_5F_scanner::kToken__28_, -1, // Choice 2
  -1,
// At index 848 : <select_gtl_5F_expression_5F_parser_8>
Lexique_gtl_5F_scanner::kToken__28_, Lexique_gtl_5F_scanner::kToken_exists, Lexique_gtl_5F_scanner::kToken_identifier, Lexique_gtl_5F_scanner::kToken__2B_, Lexique_gtl_5F_scanner::kToken__2D_, Lexique_gtl_5F_scanner::kToken_not, Lexique_gtl_5F_scanner::kToken__7E_, Lexique_gtl_5F_scanner::kToken_yes, Lexique_gtl_5F_scanner::kToken_no, Lexique_gtl_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint, Lexique_gtl_5F_scanner::kToken_literal_5F_double, Lexique_gtl_5F_scanner::kToken_string, Lexique_gtl_5F_scanner::kToken_literal_5F_char, Lexique_gtl_5F_scanner::kToken__5B_, Lexique_gtl_5F_scanner::kToken_typeof, Lexique_gtl_5F_scanner::kToken_true, Lexique_gtl_5F_scanner::kToken_false, Lexique_gtl_5F_scanner::kToken_literal_5F_enum, Lexique_gtl_5F_scanner::kToken__40_, Lexique_gtl_5F_scanner::kToken_emptylist, Lexique_gtl_5F_scanner::kToken_emptymap, Lexique_gtl_5F_scanner::kToken_mapof, Lexique_gtl_5F_scanner::kToken_listof, Lexique_gtl_5F_scanner::kToken__40__28_, Lexique_gtl_5F_scanner::kToken__40__5B_, Lexique_gtl_5F_scanner::kToken__40__7B_, Lexique_gtl_5F_scanner::kToken__40__21_, Lexique_gtl_5F_scanner::kToken__40__3F_, Lexique_gtl_5F_scanner::kToken__5F__5F_VARS_5F__5F_, -1, // Choice 1
Lexique_gtl_5F_scanner::kToken__29_, -1, // Choice 2
  -1,
// At index 881 : <select_gtl_5F_expression_5F_parser_9>
Lexique_gtl_5F_scanner::kToken__29_, -1, // Choice 1
Lexique_gtl_5F_scanner::kToken__2C_, -1, // Choice 2
  -1,
// At index 886 : <select_gtl_5F_expression_5F_parser_10>
Lexique_gtl_5F_scanner::kToken_default, -1, // Choice 1
Lexique_gtl_5F_scanner::kToken__21_, Lexique_gtl_5F_scanner::kToken_write, Lexique_gtl_5F_scanner::kToken_to, Lexique_gtl_5F_scanner::kToken__3A_, Lexique_gtl_5F_scanner::kToken_end, Lexique_gtl_5F_scanner::kToken_template, Lexique_gtl_5F_scanner::kToken__2C_, Lexique_gtl_5F_scanner::kToken__29_, Lexique_gtl_5F_scanner::kToken_if, Lexique_gtl_5F_scanner::kToken_in, Lexique_gtl_5F_scanner::kToken_identifier, Lexique_gtl_5F_scanner::kToken_or, Lexique_gtl_5F_scanner::kToken__3F_, Lexique_gtl_5F_scanner::kToken_then, Lexique_gtl_5F_scanner::kToken_elsif, Lexique_gtl_5F_scanner::kToken_else, Lexique_gtl_5F_scanner::kToken_foreach, Lexique_gtl_5F_scanner::kToken_before, Lexique_gtl_5F_scanner::kToken_do, Lexique_gtl_5F_scanner::kToken_between, Lexique_gtl_5F_scanner::kToken_after, Lexique_gtl_5F_scanner::kToken_for, Lexique_gtl_5F_scanner::kToken_loop, Lexique_gtl_5F_scanner::kToken_up, Lexique_gtl_5F_scanner::kToken_down, Lexique_gtl_5F_scanner::kToken_step, Lexique_gtl_5F_scanner::kToken_repeat, Lexique_gtl_5F_scanner::kToken_while, Lexique_gtl_5F_scanner::kToken_input, Lexique_gtl_5F_scanner::kToken__7C_, Lexique_gtl_5F_scanner::kToken__5E_, Lexique_gtl_5F_scanner::kToken__26_, Lexique_gtl_5F_scanner::kToken__3D__3D_, Lexique_gtl_5F_scanner::kToken__21__3D_, Lexique_gtl_5F_scanner::kToken__3C__3D_, Lexique_gtl_5F_scanner::kToken__3E__3D_, Lexique_gtl_5F_scanner::kToken__3E_, Lexique_gtl_5F_scanner::kToken__3C_, Lexique_gtl_5F_scanner::kToken__3C__3C_, Lexique_gtl_5F_scanner::kToken__3E__3E_, Lexique_gtl_5F_scanner::kToken__2B_, Lexique_gtl_5F_scanner::kToken__2E_, Lexique_gtl_5F_scanner::kToken__2D_, Lexique_gtl_5F_scanner::kToken__2A_, Lexique_gtl_5F_scanner::kToken__2F_, Lexique_gtl_5F_scanner::kToken_mod, Lexique_gtl_5F_scanner::kToken__5D_, Lexique_gtl_5F_scanner::kToken_by, Lexique_gtl_5F_scanner::kToken__7D_, Lexique_gtl_5F_scanner::kToken_let, Lexique_gtl_5F_scanner::kToken_unlet, Lexique_gtl_5F_scanner::kToken_error, Lexique_gtl_5F_scanner::kToken_warning, Lexique_gtl_5F_scanner::kToken_print, Lexique_gtl_5F_scanner::kToken_println, Lexique_gtl_5F_scanner::kToken_display, Lexique_gtl_5F_scanner::kToken_sort, Lexique_gtl_5F_scanner::kToken_tab, Lexique_gtl_5F_scanner::kToken_variables, Lexique_gtl_5F_scanner::kToken_libraries, Lexique_gtl_5F_scanner::kToken__5B__21_, Lexique_gtl_5F_scanner::kToken_, -1, // Choice 2
  -1,
// At index 952 : <select_gtl_5F_expression_5F_parser_11>
Lexique_gtl_5F_scanner::kToken_by, -1, // Choice 1
Lexique_gtl_5F_scanner::kToken_end, -1, // Choice 2
  -1,
// At index 957 : <select_gtl_5F_expression_5F_parser_12>
Lexique_gtl_5F_scanner::kToken__28_, Lexique_gtl_5F_scanner::kToken_exists, Lexique_gtl_5F_scanner::kToken_identifier, Lexique_gtl_5F_scanner::kToken__2B_, Lexique_gtl_5F_scanner::kToken__2D_, Lexique_gtl_5F_scanner::kToken_not, Lexique_gtl_5F_scanner::kToken__7E_, Lexique_gtl_5F_scanner::kToken_yes, Lexique_gtl_5F_scanner::kToken_no, Lexique_gtl_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint, Lexique_gtl_5F_scanner::kToken_literal_5F_double, Lexique_gtl_5F_scanner::kToken_string, Lexique_gtl_5F_scanner::kToken_literal_5F_char, Lexique_gtl_5F_scanner::kToken__5B_, Lexique_gtl_5F_scanner::kToken_typeof, Lexique_gtl_5F_scanner::kToken_true, Lexique_gtl_5F_scanner::kToken_false, Lexique_gtl_5F_scanner::kToken_literal_5F_enum, Lexique_gtl_5F_scanner::kToken__40_, Lexique_gtl_5F_scanner::kToken_emptylist, Lexique_gtl_5F_scanner::kToken_emptymap, Lexique_gtl_5F_scanner::kToken_mapof, Lexique_gtl_5F_scanner::kToken_listof, Lexique_gtl_5F_scanner::kToken__40__28_, Lexique_gtl_5F_scanner::kToken__40__5B_, Lexique_gtl_5F_scanner::kToken__40__7B_, Lexique_gtl_5F_scanner::kToken__40__21_, Lexique_gtl_5F_scanner::kToken__40__3F_, Lexique_gtl_5F_scanner::kToken__5F__5F_VARS_5F__5F_, -1, // Choice 1
Lexique_gtl_5F_scanner::kToken__29_, -1, // Choice 2
  -1,
// At index 990 : <select_gtl_5F_expression_5F_parser_13>
Lexique_gtl_5F_scanner::kToken__29_, -1, // Choice 1
Lexique_gtl_5F_scanner::kToken__2C_, -1, // Choice 2
  -1,
// At index 995 : <select_gtl_5F_expression_5F_parser_14>
Lexique_gtl_5F_scanner::kToken_string, -1, // Choice 1
Lexique_gtl_5F_scanner::kToken__5D_, -1, // Choice 2
  -1,
// At index 1000 : <select_gtl_5F_expression_5F_parser_15>
Lexique_gtl_5F_scanner::kToken__5D_, -1, // Choice 1
Lexique_gtl_5F_scanner::kToken__2C_, -1, // Choice 2
  -1,
// At index 1005 : <select_gtl_5F_expression_5F_parser_16>
Lexique_gtl_5F_scanner::kToken_identifier, -1, // Choice 1
Lexique_gtl_5F_scanner::kToken__7D_, -1, // Choice 2
  -1,
// At index 1010 : <select_gtl_5F_expression_5F_parser_17>
Lexique_gtl_5F_scanner::kToken__7D_, -1, // Choice 1
Lexique_gtl_5F_scanner::kToken__2C_, -1, // Choice 2
  -1,
// At index 1015 : <select_gtl_5F_expression_5F_parser_18>
Lexique_gtl_5F_scanner::kToken__28_, Lexique_gtl_5F_scanner::kToken_exists, Lexique_gtl_5F_scanner::kToken_identifier, Lexique_gtl_5F_scanner::kToken__2B_, Lexique_gtl_5F_scanner::kToken__2D_, Lexique_gtl_5F_scanner::kToken_not, Lexique_gtl_5F_scanner::kToken__7E_, Lexique_gtl_5F_scanner::kToken_yes, Lexique_gtl_5F_scanner::kToken_no, Lexique_gtl_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint, Lexique_gtl_5F_scanner::kToken_literal_5F_double, Lexique_gtl_5F_scanner::kToken_string, Lexique_gtl_5F_scanner::kToken_literal_5F_char, Lexique_gtl_5F_scanner::kToken__5B_, Lexique_gtl_5F_scanner::kToken_typeof, Lexique_gtl_5F_scanner::kToken_true, Lexique_gtl_5F_scanner::kToken_false, Lexique_gtl_5F_scanner::kToken_literal_5F_enum, Lexique_gtl_5F_scanner::kToken__40_, Lexique_gtl_5F_scanner::kToken_emptylist, Lexique_gtl_5F_scanner::kToken_emptymap, Lexique_gtl_5F_scanner::kToken_mapof, Lexique_gtl_5F_scanner::kToken_listof, Lexique_gtl_5F_scanner::kToken__40__28_, Lexique_gtl_5F_scanner::kToken__40__5B_, Lexique_gtl_5F_scanner::kToken__40__7B_, Lexique_gtl_5F_scanner::kToken__40__21_, Lexique_gtl_5F_scanner::kToken__40__3F_, Lexique_gtl_5F_scanner::kToken__5F__5F_VARS_5F__5F_, -1, // Choice 1
Lexique_gtl_5F_scanner::kToken__21_, -1, // Choice 2
  -1,
// At index 1048 : <select_gtl_5F_expression_5F_parser_19>
Lexique_gtl_5F_scanner::kToken__21_, -1, // Choice 1
Lexique_gtl_5F_scanner::kToken__2C_, -1, // Choice 2
  -1,
// At index 1053 : <select_gtl_5F_expression_5F_parser_20>
Lexique_gtl_5F_scanner::kToken__21_, Lexique_gtl_5F_scanner::kToken_write, Lexique_gtl_5F_scanner::kToken_to, Lexique_gtl_5F_scanner::kToken__3A_, Lexique_gtl_5F_scanner::kToken_end, Lexique_gtl_5F_scanner::kToken_template, Lexique_gtl_5F_scanner::kToken__28_, Lexique_gtl_5F_scanner::kToken__2C_, Lexique_gtl_5F_scanner::kToken__29_, Lexique_gtl_5F_scanner::kToken_if, Lexique_gtl_5F_scanner::kToken_in, Lexique_gtl_5F_scanner::kToken_identifier, Lexique_gtl_5F_scanner::kToken_or, Lexique_gtl_5F_scanner::kToken__3F_, Lexique_gtl_5F_scanner::kToken_then, Lexique_gtl_5F_scanner::kToken_elsif, Lexique_gtl_5F_scanner::kToken_else, Lexique_gtl_5F_scanner::kToken_foreach, Lexique_gtl_5F_scanner::kToken_before, Lexique_gtl_5F_scanner::kToken_do, Lexique_gtl_5F_scanner::kToken_between, Lexique_gtl_5F_scanner::kToken_after, Lexique_gtl_5F_scanner::kToken_for, Lexique_gtl_5F_scanner::kToken_loop, Lexique_gtl_5F_scanner::kToken_up, Lexique_gtl_5F_scanner::kToken_down, Lexique_gtl_5F_scanner::kToken_step, Lexique_gtl_5F_scanner::kToken_repeat, Lexique_gtl_5F_scanner::kToken_while, Lexique_gtl_5F_scanner::kToken_input, Lexique_gtl_5F_scanner::kToken__7C_, Lexique_gtl_5F_scanner::kToken__5E_, Lexique_gtl_5F_scanner::kToken__26_, Lexique_gtl_5F_scanner::kToken__3D__3D_, Lexique_gtl_5F_scanner::kToken__21__3D_, Lexique_gtl_5F_scanner::kToken__3C__3D_, Lexique_gtl_5F_scanner::kToken__3E__3D_, Lexique_gtl_5F_scanner::kToken__3E_, Lexique_gtl_5F_scanner::kToken__3C_, Lexique_gtl_5F_scanner::kToken__3C__3C_, Lexique_gtl_5F_scanner::kToken__3E__3E_, Lexique_gtl_5F_scanner::kToken__2B_, Lexique_gtl_5F_scanner::kToken__2E_, Lexique_gtl_5F_scanner::kToken__2D_, Lexique_gtl_5F_scanner::kToken__2A_, Lexique_gtl_5F_scanner::kToken__2F_, Lexique_gtl_5F_scanner::kToken_mod, Lexique_gtl_5F_scanner::kToken__5D_, Lexique_gtl_5F_scanner::kToken_default, Lexique_gtl_5F_scanner::kToken_by, Lexique_gtl_5F_scanner::kToken__7D_, Lexique_gtl_5F_scanner::kToken_let, Lexique_gtl_5F_scanner::kToken__3A__3D_, Lexique_gtl_5F_scanner::kToken__2B__3D_, Lexique_gtl_5F_scanner::kToken__2D__3D_, Lexique_gtl_5F_scanner::kToken__2A__3D_, Lexique_gtl_5F_scanner::kToken__2F__3D_, Lexique_gtl_5F_scanner::kToken_mod_3D_, Lexique_gtl_5F_scanner::kToken__3C__3C__3D_, Lexique_gtl_5F_scanner::kToken__3E__3E__3D_, Lexique_gtl_5F_scanner::kToken__26__3D_, Lexique_gtl_5F_scanner::kToken__7C__3D_, Lexique_gtl_5F_scanner::kToken__5E__3D_, Lexique_gtl_5F_scanner::kToken_unlet, Lexique_gtl_5F_scanner::kToken_error, Lexique_gtl_5F_scanner::kToken_warning, Lexique_gtl_5F_scanner::kToken_print, Lexique_gtl_5F_scanner::kToken_println, Lexique_gtl_5F_scanner::kToken_display, Lexique_gtl_5F_scanner::kToken_sort, Lexique_gtl_5F_scanner::kToken_tab, Lexique_gtl_5F_scanner::kToken_variables, Lexique_gtl_5F_scanner::kToken_libraries, Lexique_gtl_5F_scanner::kToken__5B__21_, Lexique_gtl_5F_scanner::kToken_, -1, // Choice 1
Lexique_gtl_5F_scanner::kToken__3A__3A_, -1, // Choice 2
  -1,
// At index 1132 : <select_gtl_5F_expression_5F_parser_21>
Lexique_gtl_5F_scanner::kToken__5B_, -1, // Choice 1
Lexique_gtl_5F_scanner::kToken__21_, Lexique_gtl_5F_scanner::kToken_write, Lexique_gtl_5F_scanner::kToken_to, Lexique_gtl_5F_scanner::kToken__3A_, Lexique_gtl_5F_scanner::kToken_end, Lexique_gtl_5F_scanner::kToken_template, Lexique_gtl_5F_scanner::kToken__28_, Lexique_gtl_5F_scanner::kToken__2C_, Lexique_gtl_5F_scanner::kToken__29_, Lexique_gtl_5F_scanner::kToken_if, Lexique_gtl_5F_scanner::kToken_in, Lexique_gtl_5F_scanner::kToken_identifier, Lexique_gtl_5F_scanner::kToken_or, Lexique_gtl_5F_scanner::kToken__3F_, Lexique_gtl_5F_scanner::kToken_then, Lexique_gtl_5F_scanner::kToken_elsif, Lexique_gtl_5F_scanner::kToken_else, Lexique_gtl_5F_scanner::kToken_foreach, Lexique_gtl_5F_scanner::kToken_before, Lexique_gtl_5F_scanner::kToken_do, Lexique_gtl_5F_scanner::kToken_between, Lexique_gtl_5F_scanner::kToken_after, Lexique_gtl_5F_scanner::kToken_for, Lexique_gtl_5F_scanner::kToken_loop, Lexique_gtl_5F_scanner::kToken_up, Lexique_gtl_5F_scanner::kToken_down, Lexique_gtl_5F_scanner::kToken_step, Lexique_gtl_5F_scanner::kToken_repeat, Lexique_gtl_5F_scanner::kToken_while, Lexique_gtl_5F_scanner::kToken_input, Lexique_gtl_5F_scanner::kToken__7C_, Lexique_gtl_5F_scanner::kToken__5E_, Lexique_gtl_5F_scanner::kToken__26_, Lexique_gtl_5F_scanner::kToken__3D__3D_, Lexique_gtl_5F_scanner::kToken__21__3D_, Lexique_gtl_5F_scanner::kToken__3C__3D_, Lexique_gtl_5F_scanner::kToken__3E__3D_, Lexique_gtl_5F_scanner::kToken__3E_, Lexique_gtl_5F_scanner::kToken__3C_, Lexique_gtl_5F_scanner::kToken__3C__3C_, Lexique_gtl_5F_scanner::kToken__3E__3E_, Lexique_gtl_5F_scanner::kToken__2B_, Lexique_gtl_5F_scanner::kToken__2E_, Lexique_gtl_5F_scanner::kToken__2D_, Lexique_gtl_5F_scanner::kToken__2A_, Lexique_gtl_5F_scanner::kToken__2F_, Lexique_gtl_5F_scanner::kToken_mod, Lexique_gtl_5F_scanner::kToken__5D_, Lexique_gtl_5F_scanner::kToken_default, Lexique_gtl_5F_scanner::kToken_by, Lexique_gtl_5F_scanner::kToken__7D_, Lexique_gtl_5F_scanner::kToken__3A__3A_, Lexique_gtl_5F_scanner::kToken_let, Lexique_gtl_5F_scanner::kToken__3A__3D_, Lexique_gtl_5F_scanner::kToken__2B__3D_, Lexique_gtl_5F_scanner::kToken__2D__3D_, Lexique_gtl_5F_scanner::kToken__2A__3D_, Lexique_gtl_5F_scanner::kToken__2F__3D_, Lexique_gtl_5F_scanner::kToken_mod_3D_, Lexique_gtl_5F_scanner::kToken__3C__3C__3D_, Lexique_gtl_5F_scanner::kToken__3E__3E__3D_, Lexique_gtl_5F_scanner::kToken__26__3D_, Lexique_gtl_5F_scanner::kToken__7C__3D_, Lexique_gtl_5F_scanner::kToken__5E__3D_, Lexique_gtl_5F_scanner::kToken_unlet, Lexique_gtl_5F_scanner::kToken_error, Lexique_gtl_5F_scanner::kToken_warning, Lexique_gtl_5F_scanner::kToken_print, Lexique_gtl_5F_scanner::kToken_println, Lexique_gtl_5F_scanner::kToken_display, Lexique_gtl_5F_scanner::kToken_sort, Lexique_gtl_5F_scanner::kToken_tab, Lexique_gtl_5F_scanner::kToken_variables, Lexique_gtl_5F_scanner::kToken_libraries, Lexique_gtl_5F_scanner::kToken__5B__21_, Lexique_gtl_5F_scanner::kToken_, -1, // Choice 2
  -1,
// At index 1212 : <select_gtl_5F_expression_5F_parser_22>
Lexique_gtl_5F_scanner::kToken__5B_, -1, // Choice 1
Lexique_gtl_5F_scanner::kToken__21_, Lexique_gtl_5F_scanner::kToken_write, Lexique_gtl_5F_scanner::kToken_to, Lexique_gtl_5F_scanner::kToken__3A_, Lexique_gtl_5F_scanner::kToken_end, Lexique_gtl_5F_scanner::kToken_template, Lexique_gtl_5F_scanner::kToken__28_, Lexique_gtl_5F_scanner::kToken__2C_, Lexique_gtl_5F_scanner::kToken__29_, Lexique_gtl_5F_scanner::kToken_if, Lexique_gtl_5F_scanner::kToken_in, Lexique_gtl_5F_scanner::kToken_identifier, Lexique_gtl_5F_scanner::kToken_or, Lexique_gtl_5F_scanner::kToken__3F_, Lexique_gtl_5F_scanner::kToken_then, Lexique_gtl_5F_scanner::kToken_elsif, Lexique_gtl_5F_scanner::kToken_else, Lexique_gtl_5F_scanner::kToken_foreach, Lexique_gtl_5F_scanner::kToken_before, Lexique_gtl_5F_scanner::kToken_do, Lexique_gtl_5F_scanner::kToken_between, Lexique_gtl_5F_scanner::kToken_after, Lexique_gtl_5F_scanner::kToken_for, Lexique_gtl_5F_scanner::kToken_loop, Lexique_gtl_5F_scanner::kToken_up, Lexique_gtl_5F_scanner::kToken_down, Lexique_gtl_5F_scanner::kToken_step, Lexique_gtl_5F_scanner::kToken_repeat, Lexique_gtl_5F_scanner::kToken_while, Lexique_gtl_5F_scanner::kToken_input, Lexique_gtl_5F_scanner::kToken__7C_, Lexique_gtl_5F_scanner::kToken__5E_, Lexique_gtl_5F_scanner::kToken__26_, Lexique_gtl_5F_scanner::kToken__3D__3D_, Lexique_gtl_5F_scanner::kToken__21__3D_, Lexique_gtl_5F_scanner::kToken__3C__3D_, Lexique_gtl_5F_scanner::kToken__3E__3D_, Lexique_gtl_5F_scanner::kToken__3E_, Lexique_gtl_5F_scanner::kToken__3C_, Lexique_gtl_5F_scanner::kToken__3C__3C_, Lexique_gtl_5F_scanner::kToken__3E__3E_, Lexique_gtl_5F_scanner::kToken__2B_, Lexique_gtl_5F_scanner::kToken__2E_, Lexique_gtl_5F_scanner::kToken__2D_, Lexique_gtl_5F_scanner::kToken__2A_, Lexique_gtl_5F_scanner::kToken__2F_, Lexique_gtl_5F_scanner::kToken_mod, Lexique_gtl_5F_scanner::kToken__5D_, Lexique_gtl_5F_scanner::kToken_default, Lexique_gtl_5F_scanner::kToken_by, Lexique_gtl_5F_scanner::kToken__7D_, Lexique_gtl_5F_scanner::kToken__3A__3A_, Lexique_gtl_5F_scanner::kToken_let, Lexique_gtl_5F_scanner::kToken__3A__3D_, Lexique_gtl_5F_scanner::kToken__2B__3D_, Lexique_gtl_5F_scanner::kToken__2D__3D_, Lexique_gtl_5F_scanner::kToken__2A__3D_, Lexique_gtl_5F_scanner::kToken__2F__3D_, Lexique_gtl_5F_scanner::kToken_mod_3D_, Lexique_gtl_5F_scanner::kToken__3C__3C__3D_, Lexique_gtl_5F_scanner::kToken__3E__3E__3D_, Lexique_gtl_5F_scanner::kToken__26__3D_, Lexique_gtl_5F_scanner::kToken__7C__3D_, Lexique_gtl_5F_scanner::kToken__5E__3D_, Lexique_gtl_5F_scanner::kToken_unlet, Lexique_gtl_5F_scanner::kToken_error, Lexique_gtl_5F_scanner::kToken_warning, Lexique_gtl_5F_scanner::kToken_print, Lexique_gtl_5F_scanner::kToken_println, Lexique_gtl_5F_scanner::kToken_display, Lexique_gtl_5F_scanner::kToken_sort, Lexique_gtl_5F_scanner::kToken_tab, Lexique_gtl_5F_scanner::kToken_variables, Lexique_gtl_5F_scanner::kToken_libraries, Lexique_gtl_5F_scanner::kToken__5B__21_, Lexique_gtl_5F_scanner::kToken_, -1, // Choice 2
  -1,
// At index 1292 : <select_gtl_5F_expression_5F_parser_23>
Lexique_gtl_5F_scanner::kToken__21_, Lexique_gtl_5F_scanner::kToken_write, Lexique_gtl_5F_scanner::kToken_to, Lexique_gtl_5F_scanner::kToken__3A_, Lexique_gtl_5F_scanner::kToken_end, Lexique_gtl_5F_scanner::kToken_template, Lexique_gtl_5F_scanner::kToken__28_, Lexique_gtl_5F_scanner::kToken__2C_, Lexique_gtl_5F_scanner::kToken__29_, Lexique_gtl_5F_scanner::kToken_if, Lexique_gtl_5F_scanner::kToken_in, Lexique_gtl_5F_scanner::kToken_identifier, Lexique_gtl_5F_scanner::kToken_or, Lexique_gtl_5F_scanner::kToken__3F_, Lexique_gtl_5F_scanner::kToken_then, Lexique_gtl_5F_scanner::kToken_elsif, Lexique_gtl_5F_scanner::kToken_else, Lexique_gtl_5F_scanner::kToken_foreach, Lexique_gtl_5F_scanner::kToken_before, Lexique_gtl_5F_scanner::kToken_do, Lexique_gtl_5F_scanner::kToken_between, Lexique_gtl_5F_scanner::kToken_after, Lexique_gtl_5F_scanner::kToken_for, Lexique_gtl_5F_scanner::kToken_loop, Lexique_gtl_5F_scanner::kToken_up, Lexique_gtl_5F_scanner::kToken_down, Lexique_gtl_5F_scanner::kToken_step, Lexique_gtl_5F_scanner::kToken_repeat, Lexique_gtl_5F_scanner::kToken_while, Lexique_gtl_5F_scanner::kToken_input, Lexique_gtl_5F_scanner::kToken__7C_, Lexique_gtl_5F_scanner::kToken__5E_, Lexique_gtl_5F_scanner::kToken__26_, Lexique_gtl_5F_scanner::kToken__3D__3D_, Lexique_gtl_5F_scanner::kToken__21__3D_, Lexique_gtl_5F_scanner::kToken__3C__3D_, Lexique_gtl_5F_scanner::kToken__3E__3D_, Lexique_gtl_5F_scanner::kToken__3E_, Lexique_gtl_5F_scanner::kToken__3C_, Lexique_gtl_5F_scanner::kToken__3C__3C_, Lexique_gtl_5F_scanner::kToken__3E__3E_, Lexique_gtl_5F_scanner::kToken__2B_, Lexique_gtl_5F_scanner::kToken__2E_, Lexique_gtl_5F_scanner::kToken__2D_, Lexique_gtl_5F_scanner::kToken__2A_, Lexique_gtl_5F_scanner::kToken__2F_, Lexique_gtl_5F_scanner::kToken_mod, Lexique_gtl_5F_scanner::kToken__5D_, Lexique_gtl_5F_scanner::kToken_default, Lexique_gtl_5F_scanner::kToken_by, Lexique_gtl_5F_scanner::kToken__7D_, Lexique_gtl_5F_scanner::kToken__3A__3A_, Lexique_gtl_5F_scanner::kToken_let, Lexique_gtl_5F_scanner::kToken__3A__3D_, Lexique_gtl_5F_scanner::kToken__2B__3D_, Lexique_gtl_5F_scanner::kToken__2D__3D_, Lexique_gtl_5F_scanner::kToken__2A__3D_, Lexique_gtl_5F_scanner::kToken__2F__3D_, Lexique_gtl_5F_scanner::kToken_mod_3D_, Lexique_gtl_5F_scanner::kToken__3C__3C__3D_, Lexique_gtl_5F_scanner::kToken__3E__3E__3D_, Lexique_gtl_5F_scanner::kToken__26__3D_, Lexique_gtl_5F_scanner::kToken__7C__3D_, Lexique_gtl_5F_scanner::kToken__5E__3D_, Lexique_gtl_5F_scanner::kToken_unlet, Lexique_gtl_5F_scanner::kToken_error, Lexique_gtl_5F_scanner::kToken_warning, Lexique_gtl_5F_scanner::kToken_print, Lexique_gtl_5F_scanner::kToken_println, Lexique_gtl_5F_scanner::kToken_display, Lexique_gtl_5F_scanner::kToken_sort, Lexique_gtl_5F_scanner::kToken_tab, Lexique_gtl_5F_scanner::kToken_variables, Lexique_gtl_5F_scanner::kToken_libraries, Lexique_gtl_5F_scanner::kToken__5B__21_, Lexique_gtl_5F_scanner::kToken_, -1, // Choice 1
Lexique_gtl_5F_scanner::kToken__5B_, -1, // Choice 2
  -1,
// At index 1372 : <select_gtl_5F_expression_5F_parser_24>
Lexique_gtl_5F_scanner::kToken_here, -1, // Choice 1
Lexique_gtl_5F_scanner::kToken_identifier, -1, // Choice 2
  -1,
// At index 1377 : <select_gtl_5F_expression_5F_parser_25>
Lexique_gtl_5F_scanner::kToken_identifier, -1, // Choice 1
Lexique_gtl_5F_scanner::kToken__29_, -1, // Choice 2
  -1,
// At index 1382 : <select_gtl_5F_expression_5F_parser_26>
Lexique_gtl_5F_scanner::kToken__29_, -1, // Choice 1
Lexique_gtl_5F_scanner::kToken__2C_, -1, // Choice 2
  -1,
// At index 1387 : <select_gtl_5F_expression_5F_parser_27>
Lexique_gtl_5F_scanner::kToken__3A_, -1, // Choice 1
Lexique_gtl_5F_scanner::kToken__2C_, Lexique_gtl_5F_scanner::kToken__29_, -1, // Choice 2
  -1,
// At index 1393 : <select_gtl_5F_instruction_5F_parser_0>
Lexique_gtl_5F_scanner::kToken__3A__3D_, -1, // Choice 1
Lexique_gtl_5F_scanner::kToken__2B__3D_, -1, // Choice 2
Lexique_gtl_5F_scanner::kToken__2D__3D_, -1, // Choice 3
Lexique_gtl_5F_scanner::kToken__2A__3D_, -1, // Choice 4
Lexique_gtl_5F_scanner::kToken__2F__3D_, -1, // Choice 5
Lexique_gtl_5F_scanner::kToken_mod_3D_, -1, // Choice 6
Lexique_gtl_5F_scanner::kToken__3C__3C__3D_, -1, // Choice 7
Lexique_gtl_5F_scanner::kToken__3E__3E__3D_, -1, // Choice 8
Lexique_gtl_5F_scanner::kToken__26__3D_, -1, // Choice 9
Lexique_gtl_5F_scanner::kToken__7C__3D_, -1, // Choice 10
Lexique_gtl_5F_scanner::kToken__5E__3D_, -1, // Choice 11
Lexique_gtl_5F_scanner::kToken__21_, Lexique_gtl_5F_scanner::kToken_write, Lexique_gtl_5F_scanner::kToken_end, Lexique_gtl_5F_scanner::kToken_template, Lexique_gtl_5F_scanner::kToken_if, Lexique_gtl_5F_scanner::kToken__3F_, Lexique_gtl_5F_scanner::kToken_elsif, Lexique_gtl_5F_scanner::kToken_else, Lexique_gtl_5F_scanner::kToken_foreach, Lexique_gtl_5F_scanner::kToken_do, Lexique_gtl_5F_scanner::kToken_between, Lexique_gtl_5F_scanner::kToken_after, Lexique_gtl_5F_scanner::kToken_for, Lexique_gtl_5F_scanner::kToken_loop, Lexique_gtl_5F_scanner::kToken_repeat, Lexique_gtl_5F_scanner::kToken_while, Lexique_gtl_5F_scanner::kToken_input, Lexique_gtl_5F_scanner::kToken_let, Lexique_gtl_5F_scanner::kToken_unlet, Lexique_gtl_5F_scanner::kToken_error, Lexique_gtl_5F_scanner::kToken_warning, Lexique_gtl_5F_scanner::kToken_print, Lexique_gtl_5F_scanner::kToken_println, Lexique_gtl_5F_scanner::kToken_display, Lexique_gtl_5F_scanner::kToken_sort, Lexique_gtl_5F_scanner::kToken_tab, Lexique_gtl_5F_scanner::kToken_variables, Lexique_gtl_5F_scanner::kToken_libraries, Lexique_gtl_5F_scanner::kToken__5B__21_, Lexique_gtl_5F_scanner::kToken_, -1, // Choice 12
  -1,
// At index 1447 : <select_gtl_5F_instruction_5F_parser_1>
Lexique_gtl_5F_scanner::kToken__28_, Lexique_gtl_5F_scanner::kToken_exists, Lexique_gtl_5F_scanner::kToken_identifier, Lexique_gtl_5F_scanner::kToken__2B_, Lexique_gtl_5F_scanner::kToken__2D_, Lexique_gtl_5F_scanner::kToken_not, Lexique_gtl_5F_scanner::kToken__7E_, Lexique_gtl_5F_scanner::kToken_yes, Lexique_gtl_5F_scanner::kToken_no, Lexique_gtl_5F_scanner::kToken_signed_5F_literal_5F_integer_5F_bigint, Lexique_gtl_5F_scanner::kToken_literal_5F_double, Lexique_gtl_5F_scanner::kToken_string, Lexique_gtl_5F_scanner::kToken_literal_5F_char, Lexique_gtl_5F_scanner::kToken__5B_, Lexique_gtl_5F_scanner::kToken_typeof, Lexique_gtl_5F_scanner::kToken_true, Lexique_gtl_5F_scanner::kToken_false, Lexique_gtl_5F_scanner::kToken_literal_5F_enum, Lexique_gtl_5F_scanner::kToken__40_, Lexique_gtl_5F_scanner::kToken_emptylist, Lexique_gtl_5F_scanner::kToken_emptymap, Lexique_gtl_5F_scanner::kToken_mapof, Lexique_gtl_5F_scanner::kToken_listof, Lexique_gtl_5F_scanner::kToken__40__28_, Lexique_gtl_5F_scanner::kToken__40__5B_, Lexique_gtl_5F_scanner::kToken__40__7B_, Lexique_gtl_5F_scanner::kToken__40__21_, Lexique_gtl_5F_scanner::kToken__40__3F_, Lexique_gtl_5F_scanner::kToken__5F__5F_VARS_5F__5F_, -1, // Choice 1
Lexique_gtl_5F_scanner::kToken__21_, Lexique_gtl_5F_scanner::kToken_write, Lexique_gtl_5F_scanner::kToken_end, Lexique_gtl_5F_scanner::kToken_template, Lexique_gtl_5F_scanner::kToken_if, Lexique_gtl_5F_scanner::kToken__3F_, Lexique_gtl_5F_scanner::kToken_elsif, Lexique_gtl_5F_scanner::kToken_else, Lexique_gtl_5F_scanner::kToken_foreach, Lexique_gtl_5F_scanner::kToken_do, Lexique_gtl_5F_scanner::kToken_between, Lexique_gtl_5F_scanner::kToken_after, Lexique_gtl_5F_scanner::kToken_for, Lexique_gtl_5F_scanner::kToken_loop, Lexique_gtl_5F_scanner::kToken_repeat, Lexique_gtl_5F_scanner::kToken_while, Lexique_gtl_5F_scanner::kToken_input, Lexique_gtl_5F_scanner::kToken_let, Lexique_gtl_5F_scanner::kToken_unlet, Lexique_gtl_5F_scanner::kToken_error, Lexique_gtl_5F_scanner::kToken_warning, Lexique_gtl_5F_scanner::kToken_print, Lexique_gtl_5F_scanner::kToken_println, Lexique_gtl_5F_scanner::kToken_display, Lexique_gtl_5F_scanner::kToken_sort, Lexique_gtl_5F_scanner::kToken_tab, Lexique_gtl_5F_scanner::kToken_variables, Lexique_gtl_5F_scanner::kToken_libraries, Lexique_gtl_5F_scanner::kToken__5B__21_, Lexique_gtl_5F_scanner::kToken_, -1, // Choice 2
  -1,
// At index 1509 : <select_gtl_5F_instruction_5F_parser_2>
Lexique_gtl_5F_scanner::kToken_by, -1, // Choice 1
Lexique_gtl_5F_scanner::kToken__3E_, Lexique_gtl_5F_scanner::kToken__3C_, -1, // Choice 2
  -1,
// At index 1515 : <select_gtl_5F_instruction_5F_parser_3>
Lexique_gtl_5F_scanner::kToken__21_, Lexique_gtl_5F_scanner::kToken_write, Lexique_gtl_5F_scanner::kToken_end, Lexique_gtl_5F_scanner::kToken_template, Lexique_gtl_5F_scanner::kToken_if, Lexique_gtl_5F_scanner::kToken__3F_, Lexique_gtl_5F_scanner::kToken_elsif, Lexique_gtl_5F_scanner::kToken_else, Lexique_gtl_5F_scanner::kToken_foreach, Lexique_gtl_5F_scanner::kToken_do, Lexique_gtl_5F_scanner::kToken_between, Lexique_gtl_5F_scanner::kToken_after, Lexique_gtl_5F_scanner::kToken_for, Lexique_gtl_5F_scanner::kToken_loop, Lexique_gtl_5F_scanner::kToken_repeat, Lexique_gtl_5F_scanner::kToken_while, Lexique_gtl_5F_scanner::kToken_input, Lexique_gtl_5F_scanner::kToken_let, Lexique_gtl_5F_scanner::kToken_unlet, Lexique_gtl_5F_scanner::kToken_error, Lexique_gtl_5F_scanner::kToken_warning, Lexique_gtl_5F_scanner::kToken_print, Lexique_gtl_5F_scanner::kToken_println, Lexique_gtl_5F_scanner::kToken_display, Lexique_gtl_5F_scanner::kToken_sort, Lexique_gtl_5F_scanner::kToken_tab, Lexique_gtl_5F_scanner::kToken_variables, Lexique_gtl_5F_scanner::kToken_libraries, Lexique_gtl_5F_scanner::kToken__5B__21_, Lexique_gtl_5F_scanner::kToken_, -1, // Choice 1
Lexique_gtl_5F_scanner::kToken__2C_, -1, // Choice 2
  -1,
// At index 1549 : <select_gtl_5F_instruction_5F_parser_4>
Lexique_gtl_5F_scanner::kToken__5D_, -1, // Choice 1
Lexique_gtl_5F_scanner::kToken__3A_, -1, // Choice 2
  -1,
// At index 1554 : <select_gtl_5F_instruction_5F_parser_5>
Lexique_gtl_5F_scanner::kToken__5D_, -1, // Choice 1
Lexique_gtl_5F_scanner::kToken__2C_, -1, // Choice 2
  -1,
// At index 1559 : <select_gtl_5F_instruction_5F_parser_6>
Lexique_gtl_5F_scanner::kToken__3E_, -1, // Choice 1
Lexique_gtl_5F_scanner::kToken__3C_, -1, // Choice 2
  -1,
// At index 1564 : <> only one production, no choice
  -1,
0} ;

//--------------------------------------------------------------------------------------------------
//
//                  L L ( 1 )    D E C I S I O N    T A B L E S    I N D E X E S                    
//
//--------------------------------------------------------------------------------------------------

static const int32_t gDecisionIndexes_gtl_grammar [79] = {
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
117, // at 15 : <gtl_sorting_order>
118, // at 16 : <select_gtl_5F_parser_0>
145, // at 17 : <select_gtl_5F_parser_1>
179, // at 18 : <select_gtl_5F_parser_2>
212, // at 19 : <select_gtl_5F_parser_3>
219, // at 20 : <select_gtl_5F_parser_4>
252, // at 21 : <select_gtl_5F_parser_5>
257, // at 22 : <select_gtl_5F_parser_6>
263, // at 23 : <select_gtl_5F_parser_7>
298, // at 24 : <select_gtl_5F_parser_8>
332, // at 25 : <select_gtl_5F_parser_9>
366, // at 26 : <select_gtl_5F_parser_10>
372, // at 27 : <select_gtl_5F_parser_11>
377, // at 28 : <select_gtl_5F_parser_12>
383, // at 29 : <select_gtl_5F_parser_13>
388, // at 30 : <select_gtl_5F_parser_14>
393, // at 31 : <select_gtl_5F_parser_15>
399, // at 32 : <select_gtl_5F_parser_16>
404, // at 33 : <select_gtl_5F_parser_17>
409, // at 34 : <select_gtl_5F_parser_18>
414, // at 35 : <select_gtl_5F_parser_19>
421, // at 36 : <select_gtl_5F_parser_20>
427, // at 37 : <select_gtl_5F_parser_21>
432, // at 38 : <select_gtl_5F_parser_22>
438, // at 39 : <select_gtl_5F_parser_23>
443, // at 40 : <select_gtl_5F_parser_24>
470, // at 41 : <select_gtl_5F_parser_25>
475, // at 42 : <select_gtl_5F_expression_5F_parser_0>
526, // at 43 : <select_gtl_5F_expression_5F_parser_1>
577, // at 44 : <select_gtl_5F_expression_5F_parser_2>
639, // at 45 : <select_gtl_5F_expression_5F_parser_3>
705, // at 46 : <select_gtl_5F_expression_5F_parser_4>
772, // at 47 : <select_gtl_5F_expression_5F_parser_5>
777, // at 48 : <select_gtl_5F_expression_5F_parser_6>
782, // at 49 : <select_gtl_5F_expression_5F_parser_7>
848, // at 50 : <select_gtl_5F_expression_5F_parser_8>
881, // at 51 : <select_gtl_5F_expression_5F_parser_9>
886, // at 52 : <select_gtl_5F_expression_5F_parser_10>
952, // at 53 : <select_gtl_5F_expression_5F_parser_11>
957, // at 54 : <select_gtl_5F_expression_5F_parser_12>
990, // at 55 : <select_gtl_5F_expression_5F_parser_13>
995, // at 56 : <select_gtl_5F_expression_5F_parser_14>
1000, // at 57 : <select_gtl_5F_expression_5F_parser_15>
1005, // at 58 : <select_gtl_5F_expression_5F_parser_16>
1010, // at 59 : <select_gtl_5F_expression_5F_parser_17>
1015, // at 60 : <select_gtl_5F_expression_5F_parser_18>
1048, // at 61 : <select_gtl_5F_expression_5F_parser_19>
1053, // at 62 : <select_gtl_5F_expression_5F_parser_20>
1132, // at 63 : <select_gtl_5F_expression_5F_parser_21>
1212, // at 64 : <select_gtl_5F_expression_5F_parser_22>
1292, // at 65 : <select_gtl_5F_expression_5F_parser_23>
1372, // at 66 : <select_gtl_5F_expression_5F_parser_24>
1377, // at 67 : <select_gtl_5F_expression_5F_parser_25>
1382, // at 68 : <select_gtl_5F_expression_5F_parser_26>
1387, // at 69 : <select_gtl_5F_expression_5F_parser_27>
1393, // at 70 : <select_gtl_5F_instruction_5F_parser_0>
1447, // at 71 : <select_gtl_5F_instruction_5F_parser_1>
1509, // at 72 : <select_gtl_5F_instruction_5F_parser_2>
1515, // at 73 : <select_gtl_5F_instruction_5F_parser_3>
1549, // at 74 : <select_gtl_5F_instruction_5F_parser_4>
1554, // at 75 : <select_gtl_5F_instruction_5F_parser_5>
1559, // at 76 : <select_gtl_5F_instruction_5F_parser_6>
1564, // at 77 : <>
0} ;

//--------------------------------------------------------------------------------------------------
//
//                          'gtl_expression' non terminal implementation                            
//
//--------------------------------------------------------------------------------------------------

void cGrammar_gtl_5F_grammar::nt_gtl_5F_expression_parse (Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_expression_i0_parse(inLexique) ;
}

void cGrammar_gtl_5F_grammar::nt_gtl_5F_expression_indexing (Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_expression_i0_indexing(inLexique) ;
}

void cGrammar_gtl_5F_grammar::nt_gtl_5F_expression_ (GALGAS_gtlExpression & parameter_1,
                                Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_expression_i0_(parameter_1, inLexique) ;
}

//--------------------------------------------------------------------------------------------------
//
//                           'gtl_variable' non terminal implementation                             
//
//--------------------------------------------------------------------------------------------------

void cGrammar_gtl_5F_grammar::nt_gtl_5F_variable_parse (Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_variable_i34_parse(inLexique) ;
}

void cGrammar_gtl_5F_grammar::nt_gtl_5F_variable_indexing (Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_variable_i34_indexing(inLexique) ;
}

void cGrammar_gtl_5F_grammar::nt_gtl_5F_variable_ (GALGAS_gtlVarPath & parameter_1,
                                Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_variable_i34_(parameter_1, inLexique) ;
}

//--------------------------------------------------------------------------------------------------
//
//                       'gtl_variable_or_here' non terminal implementation                         
//
//--------------------------------------------------------------------------------------------------

void cGrammar_gtl_5F_grammar::nt_gtl_5F_variable_5F_or_5F_here_parse (Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_variable_5F_or_5F_here_i35_parse(inLexique) ;
}

void cGrammar_gtl_5F_grammar::nt_gtl_5F_variable_5F_or_5F_here_indexing (Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_variable_5F_or_5F_here_i35_indexing(inLexique) ;
}

void cGrammar_gtl_5F_grammar::nt_gtl_5F_variable_5F_or_5F_here_ (GALGAS_gtlVarPath & parameter_1,
                                GALGAS_bool & parameter_2,
                                Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_variable_5F_or_5F_here_i35_(parameter_1, parameter_2, inLexique) ;
}

//--------------------------------------------------------------------------------------------------
//
//                            'gtl_import' non terminal implementation                              
//
//--------------------------------------------------------------------------------------------------

void cGrammar_gtl_5F_grammar::nt_gtl_5F_import_parse (Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_instruction_5F_parser_gtl_5F_import_i13_parse(inLexique) ;
}

void cGrammar_gtl_5F_grammar::nt_gtl_5F_import_indexing (Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_instruction_5F_parser_gtl_5F_import_i13_indexing(inLexique) ;
}

void cGrammar_gtl_5F_grammar::nt_gtl_5F_import_ (GALGAS_gtlContext parameter_1,
                                GALGAS_library & parameter_2,
                                Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_instruction_5F_parser_gtl_5F_import_i13_(parameter_1, parameter_2, inLexique) ;
}

//--------------------------------------------------------------------------------------------------
//
//                      'gtl_simple_instruction' non terminal implementation                        
//
//--------------------------------------------------------------------------------------------------

void cGrammar_gtl_5F_grammar::nt_gtl_5F_simple_5F_instruction_parse (Lexique_gtl_5F_scanner * inLexique) {
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

void cGrammar_gtl_5F_grammar::nt_gtl_5F_simple_5F_instruction_indexing (Lexique_gtl_5F_scanner * inLexique) {
  switch (inLexique->nextProductionIndex ()) {
  case 1 :
    rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i0_indexing(inLexique) ;
    break ;
  case 2 :
    rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i1_indexing(inLexique) ;
    break ;
  case 3 :
    rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i2_indexing(inLexique) ;
    break ;
  case 4 :
    rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i3_indexing(inLexique) ;
    break ;
  case 5 :
    rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i4_indexing(inLexique) ;
    break ;
  case 6 :
    rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i5_indexing(inLexique) ;
    break ;
  case 7 :
    rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i6_indexing(inLexique) ;
    break ;
  case 8 :
    rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i7_indexing(inLexique) ;
    break ;
  case 9 :
    rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i8_indexing(inLexique) ;
    break ;
  case 10 :
    rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i9_indexing(inLexique) ;
    break ;
  case 11 :
    rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i10_indexing(inLexique) ;
    break ;
  case 12 :
    rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i11_indexing(inLexique) ;
    break ;
  default :
    break ;
  }
}

void cGrammar_gtl_5F_grammar::nt_gtl_5F_simple_5F_instruction_ (GALGAS_gtlInstruction & parameter_1,
                                Lexique_gtl_5F_scanner * inLexique) {
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

//--------------------------------------------------------------------------------------------------
//
//                        'gtl_argument_list' non terminal implementation                           
//
//--------------------------------------------------------------------------------------------------

void cGrammar_gtl_5F_grammar::nt_gtl_5F_argument_5F_list_parse (Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_argument_5F_list_i36_parse(inLexique) ;
}

void cGrammar_gtl_5F_grammar::nt_gtl_5F_argument_5F_list_indexing (Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_argument_5F_list_i36_indexing(inLexique) ;
}

void cGrammar_gtl_5F_grammar::nt_gtl_5F_argument_5F_list_ (GALGAS_gtlArgumentList & parameter_1,
                                Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_argument_5F_list_i36_(parameter_1, inLexique) ;
}

//--------------------------------------------------------------------------------------------------
//
//                         'gtl_start_symbol' non terminal implementation                           
//
//--------------------------------------------------------------------------------------------------

void cGrammar_gtl_5F_grammar::nt_gtl_5F_start_5F_symbol_parse (Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_parser_gtl_5F_start_5F_symbol_i0_parse(inLexique) ;
}

void cGrammar_gtl_5F_grammar::nt_gtl_5F_start_5F_symbol_indexing (Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_parser_gtl_5F_start_5F_symbol_i0_indexing(inLexique) ;
}

void cGrammar_gtl_5F_grammar::nt_gtl_5F_start_5F_symbol_ (GALGAS_gtlContext parameter_1,
                                GALGAS_library & parameter_2,
                                GALGAS_gtlInstructionList & parameter_3,
                                Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_parser_gtl_5F_start_5F_symbol_i0_(parameter_1, parameter_2, parameter_3, inLexique) ;
}

void cGrammar_gtl_5F_grammar::performIndexing (Compiler * inCompiler,
             const String & inSourceFilePath) {
  Lexique_gtl_5F_scanner * scanner = nullptr ;
  macroMyNew (scanner, Lexique_gtl_5F_scanner (inCompiler, inSourceFilePath COMMA_HERE)) ;
  scanner->enableIndexing () ;
  if (scanner->sourceText ().isValid ()) {
    const bool ok = scanner->performTopDownParsing (gProductions_gtl_grammar, gProductionNames_gtl_grammar, gProductionIndexes_gtl_grammar,
                                                    gFirstProductionIndexes_gtl_grammar, gDecision_gtl_grammar, gDecisionIndexes_gtl_grammar, 626) ;
    if (ok) {
      cGrammar_gtl_5F_grammar grammar ;
      grammar.nt_gtl_5F_start_5F_symbol_indexing (scanner) ;
    }
    scanner->generateIndexFile () ;
  }
  macroDetachSharedObject (scanner) ;
}

void cGrammar_gtl_5F_grammar::performOnlyLexicalAnalysis (Compiler * inCompiler,
             const String & inSourceFilePath) {
  Lexique_gtl_5F_scanner * scanner = nullptr ;
  macroMyNew (scanner, Lexique_gtl_5F_scanner (inCompiler, inSourceFilePath COMMA_HERE)) ;
  if (scanner->sourceText ().isValid ()) {
    scanner->performLexicalAnalysis () ;
  }
  macroDetachSharedObject (scanner) ;
}

void cGrammar_gtl_5F_grammar::performOnlySyntaxAnalysis (Compiler * inCompiler,
             const String & inSourceFilePath) {
  Lexique_gtl_5F_scanner * scanner = nullptr ;
  macroMyNew (scanner, Lexique_gtl_5F_scanner (inCompiler, inSourceFilePath COMMA_HERE)) ;
  if (scanner->sourceText ().isValid ()) {
    scanner->performTopDownParsing (gProductions_gtl_grammar, gProductionNames_gtl_grammar, gProductionIndexes_gtl_grammar,
                                    gFirstProductionIndexes_gtl_grammar, gDecision_gtl_grammar, gDecisionIndexes_gtl_grammar, 626) ;
  }
  macroDetachSharedObject (scanner) ;
}

//--------------------------------------------------------------------------------------------------
//
//                              Grammar start symbol implementation                                 
//
//--------------------------------------------------------------------------------------------------

void cGrammar_gtl_5F_grammar::_performSourceFileParsing_ (Compiler * inCompiler,
                                GALGAS_lstring inFilePath,
                                GALGAS_gtlContext  parameter_1,
                                GALGAS_library &  parameter_2,
                                GALGAS_gtlInstructionList &  parameter_3
                                COMMA_LOCATION_ARGS) {
  if (inFilePath.isValid ()) {
    const GALGAS_string filePathAsString = inFilePath.readProperty_string () ;
    String filePath = filePathAsString.stringValue () ;
    if (! FileManager::isAbsolutePath (filePath)) {
      filePath = inCompiler->sourceFilePath ().stringByDeletingLastPathComponent ().stringByAppendingPathComponent (filePath) ;
    }
    if (FileManager::fileExistsAtPath (filePath)) {
    Lexique_gtl_5F_scanner * scanner = nullptr ;
    macroMyNew (scanner, Lexique_gtl_5F_scanner (inCompiler, filePath COMMA_HERE)) ;
    if (scanner->sourceText ().isValid ()) {
      const bool ok = scanner->performTopDownParsing (gProductions_gtl_grammar, gProductionNames_gtl_grammar, gProductionIndexes_gtl_grammar,
                                                      gFirstProductionIndexes_gtl_grammar, gDecision_gtl_grammar, gDecisionIndexes_gtl_grammar, 626) ;
      if (ok && ! executionModeIsSyntaxAnalysisOnly ()) {
        cGrammar_gtl_5F_grammar grammar ;
        grammar.nt_gtl_5F_start_5F_symbol_ (parameter_1, parameter_2, parameter_3, scanner) ;
        }
      }else{
        String message ;
        message.appendString ("the '") ;
        message.appendString (filePath) ;
        message.appendString ("' file exists, but cannot be read") ;
        const GALGAS_location errorLocation (inFilePath.readProperty_location ()) ;
        inCompiler->semanticErrorAtLocation (errorLocation, message, TC_Array <C_FixItDescription> () COMMA_THERE) ;
      }
      macroDetachSharedObject (scanner) ;
    }else{
      String message ;
      message.appendString ("the '") ;
      message.appendString (filePath) ;
      message.appendString ("' file does not exist") ;
      const GALGAS_location errorLocation (inFilePath.readProperty_location ()) ;
      inCompiler->semanticErrorAtLocation (errorLocation, message, TC_Array <C_FixItDescription> () COMMA_THERE) ;
    }
  }
}

//--------------------------------------------------------------------------------------------------

void cGrammar_gtl_5F_grammar::_performSourceStringParsing_ (Compiler * inCompiler,
                                GALGAS_string inSourceString,
                                GALGAS_string inNameString,
                                GALGAS_gtlContext  parameter_1,
                                GALGAS_library &  parameter_2,
                                GALGAS_gtlInstructionList &  parameter_3
                                COMMA_UNUSED_LOCATION_ARGS) {
  if (inSourceString.isValid () && inNameString.isValid ()) {
    const String sourceString = inSourceString.stringValue () ;
    const String nameString = inNameString.stringValue () ;
    Lexique_gtl_5F_scanner * scanner = nullptr ;
    macroMyNew (scanner, Lexique_gtl_5F_scanner (inCompiler, sourceString, nameString COMMA_HERE)) ;
    const bool ok = scanner->performTopDownParsing (gProductions_gtl_grammar, gProductionNames_gtl_grammar, gProductionIndexes_gtl_grammar,
                                                    gFirstProductionIndexes_gtl_grammar, gDecision_gtl_grammar, gDecisionIndexes_gtl_grammar, 626) ;
    if (ok && ! executionModeIsSyntaxAnalysisOnly ()) {
      cGrammar_gtl_5F_grammar grammar ;
      grammar.nt_gtl_5F_start_5F_symbol_ (parameter_1, parameter_2, parameter_3, scanner) ;
    }
    macroDetachSharedObject (scanner) ;
  }
}

//--------------------------------------------------------------------------------------------------
//
//                  'gtl_template_instruction_list' non terminal implementation                     
//
//--------------------------------------------------------------------------------------------------

void cGrammar_gtl_5F_grammar::nt_gtl_5F_template_5F_instruction_5F_list_parse (Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_parser_gtl_5F_template_5F_instruction_5F_list_i1_parse(inLexique) ;
}

void cGrammar_gtl_5F_grammar::nt_gtl_5F_template_5F_instruction_5F_list_indexing (Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_parser_gtl_5F_template_5F_instruction_5F_list_i1_indexing(inLexique) ;
}

void cGrammar_gtl_5F_grammar::nt_gtl_5F_template_5F_instruction_5F_list_ (GALGAS_gtlInstructionList & parameter_1,
                                Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_parser_gtl_5F_template_5F_instruction_5F_list_i1_(parameter_1, inLexique) ;
}

//--------------------------------------------------------------------------------------------------
//
//                     'gtl_template_instruction' non terminal implementation                       
//
//--------------------------------------------------------------------------------------------------

void cGrammar_gtl_5F_grammar::nt_gtl_5F_template_5F_instruction_parse (Lexique_gtl_5F_scanner * inLexique) {
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

void cGrammar_gtl_5F_grammar::nt_gtl_5F_template_5F_instruction_indexing (Lexique_gtl_5F_scanner * inLexique) {
  switch (inLexique->nextProductionIndex ()) {
  case 1 :
    rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i2_indexing(inLexique) ;
    break ;
  case 2 :
    rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i3_indexing(inLexique) ;
    break ;
  case 3 :
    rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i4_indexing(inLexique) ;
    break ;
  case 4 :
    rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i5_indexing(inLexique) ;
    break ;
  case 5 :
    rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i6_indexing(inLexique) ;
    break ;
  case 6 :
    rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i7_indexing(inLexique) ;
    break ;
  case 7 :
    rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i8_indexing(inLexique) ;
    break ;
  case 8 :
    rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i9_indexing(inLexique) ;
    break ;
  case 9 :
    rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i10_indexing(inLexique) ;
    break ;
  case 10 :
    rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i11_indexing(inLexique) ;
    break ;
  default :
    break ;
  }
}

void cGrammar_gtl_5F_grammar::nt_gtl_5F_template_5F_instruction_ (GALGAS_gtlInstruction & parameter_1,
                                Lexique_gtl_5F_scanner * inLexique) {
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

//--------------------------------------------------------------------------------------------------
//
//                          'gtl_file_name' non terminal implementation                             
//
//--------------------------------------------------------------------------------------------------

void cGrammar_gtl_5F_grammar::nt_gtl_5F_file_5F_name_parse (Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_parser_gtl_5F_file_5F_name_i12_parse(inLexique) ;
}

void cGrammar_gtl_5F_grammar::nt_gtl_5F_file_5F_name_indexing (Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_parser_gtl_5F_file_5F_name_i12_indexing(inLexique) ;
}

void cGrammar_gtl_5F_grammar::nt_gtl_5F_file_5F_name_ (GALGAS_gtlExpression & parameter_1,
                                Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_parser_gtl_5F_file_5F_name_i12_(parameter_1, inLexique) ;
}

//--------------------------------------------------------------------------------------------------
//
//                        'gtl_relation_term' non terminal implementation                           
//
//--------------------------------------------------------------------------------------------------

void cGrammar_gtl_5F_grammar::nt_gtl_5F_relation_5F_term_parse (Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_relation_5F_term_i1_parse(inLexique) ;
}

void cGrammar_gtl_5F_grammar::nt_gtl_5F_relation_5F_term_indexing (Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_relation_5F_term_i1_indexing(inLexique) ;
}

void cGrammar_gtl_5F_grammar::nt_gtl_5F_relation_5F_term_ (GALGAS_gtlExpression & parameter_1,
                                Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_relation_5F_term_i1_(parameter_1, inLexique) ;
}

//--------------------------------------------------------------------------------------------------
//
//                       'gtl_relation_factor' non terminal implementation                          
//
//--------------------------------------------------------------------------------------------------

void cGrammar_gtl_5F_grammar::nt_gtl_5F_relation_5F_factor_parse (Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_relation_5F_factor_i2_parse(inLexique) ;
}

void cGrammar_gtl_5F_grammar::nt_gtl_5F_relation_5F_factor_indexing (Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_relation_5F_factor_i2_indexing(inLexique) ;
}

void cGrammar_gtl_5F_grammar::nt_gtl_5F_relation_5F_factor_ (GALGAS_gtlExpression & parameter_1,
                                Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_relation_5F_factor_i2_(parameter_1, inLexique) ;
}

//--------------------------------------------------------------------------------------------------
//
//                      'gtl_simple_expression' non terminal implementation                         
//
//--------------------------------------------------------------------------------------------------

void cGrammar_gtl_5F_grammar::nt_gtl_5F_simple_5F_expression_parse (Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_simple_5F_expression_i3_parse(inLexique) ;
}

void cGrammar_gtl_5F_grammar::nt_gtl_5F_simple_5F_expression_indexing (Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_simple_5F_expression_i3_indexing(inLexique) ;
}

void cGrammar_gtl_5F_grammar::nt_gtl_5F_simple_5F_expression_ (GALGAS_gtlExpression & parameter_1,
                                Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_simple_5F_expression_i3_(parameter_1, inLexique) ;
}

//--------------------------------------------------------------------------------------------------
//
//                             'gtl_term' non terminal implementation                               
//
//--------------------------------------------------------------------------------------------------

void cGrammar_gtl_5F_grammar::nt_gtl_5F_term_parse (Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_term_i4_parse(inLexique) ;
}

void cGrammar_gtl_5F_grammar::nt_gtl_5F_term_indexing (Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_term_i4_indexing(inLexique) ;
}

void cGrammar_gtl_5F_grammar::nt_gtl_5F_term_ (GALGAS_gtlExpression & parameter_1,
                                Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_expression_5F_parser_gtl_5F_term_i4_(parameter_1, inLexique) ;
}

//--------------------------------------------------------------------------------------------------
//
//                            'gtl_factor' non terminal implementation                              
//
//--------------------------------------------------------------------------------------------------

void cGrammar_gtl_5F_grammar::nt_gtl_5F_factor_parse (Lexique_gtl_5F_scanner * inLexique) {
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
  case 28 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i32_parse(inLexique) ;
    break ;
  case 29 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i33_parse(inLexique) ;
    break ;
  default :
    break ;
  }
}

void cGrammar_gtl_5F_grammar::nt_gtl_5F_factor_indexing (Lexique_gtl_5F_scanner * inLexique) {
  switch (inLexique->nextProductionIndex ()) {
  case 1 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i5_indexing(inLexique) ;
    break ;
  case 2 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i6_indexing(inLexique) ;
    break ;
  case 3 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i7_indexing(inLexique) ;
    break ;
  case 4 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i8_indexing(inLexique) ;
    break ;
  case 5 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i9_indexing(inLexique) ;
    break ;
  case 6 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i10_indexing(inLexique) ;
    break ;
  case 7 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i11_indexing(inLexique) ;
    break ;
  case 8 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i12_indexing(inLexique) ;
    break ;
  case 9 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i13_indexing(inLexique) ;
    break ;
  case 10 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i14_indexing(inLexique) ;
    break ;
  case 11 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i15_indexing(inLexique) ;
    break ;
  case 12 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i16_indexing(inLexique) ;
    break ;
  case 13 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i17_indexing(inLexique) ;
    break ;
  case 14 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i18_indexing(inLexique) ;
    break ;
  case 15 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i19_indexing(inLexique) ;
    break ;
  case 16 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i20_indexing(inLexique) ;
    break ;
  case 17 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i21_indexing(inLexique) ;
    break ;
  case 18 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i22_indexing(inLexique) ;
    break ;
  case 19 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i23_indexing(inLexique) ;
    break ;
  case 20 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i24_indexing(inLexique) ;
    break ;
  case 21 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i25_indexing(inLexique) ;
    break ;
  case 22 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i26_indexing(inLexique) ;
    break ;
  case 23 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i27_indexing(inLexique) ;
    break ;
  case 24 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i28_indexing(inLexique) ;
    break ;
  case 25 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i29_indexing(inLexique) ;
    break ;
  case 26 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i30_indexing(inLexique) ;
    break ;
  case 27 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i31_indexing(inLexique) ;
    break ;
  case 28 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i32_indexing(inLexique) ;
    break ;
  case 29 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i33_indexing(inLexique) ;
    break ;
  default :
    break ;
  }
}

void cGrammar_gtl_5F_grammar::nt_gtl_5F_factor_ (GALGAS_gtlExpression & parameter_1,
                                Lexique_gtl_5F_scanner * inLexique) {
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
  case 28 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i32_(parameter_1, inLexique) ;
    break ;
  case 29 :
    rule_gtl_5F_expression_5F_parser_gtl_5F_factor_i33_(parameter_1, inLexique) ;
    break ;
  default :
    break ;
  }
}

//--------------------------------------------------------------------------------------------------
//
//                        'gtl_sorting_order' non terminal implementation                           
//
//--------------------------------------------------------------------------------------------------

void cGrammar_gtl_5F_grammar::nt_gtl_5F_sorting_5F_order_parse (Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_instruction_5F_parser_gtl_5F_sorting_5F_order_i12_parse(inLexique) ;
}

void cGrammar_gtl_5F_grammar::nt_gtl_5F_sorting_5F_order_indexing (Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_instruction_5F_parser_gtl_5F_sorting_5F_order_i12_indexing(inLexique) ;
}

void cGrammar_gtl_5F_grammar::nt_gtl_5F_sorting_5F_order_ (GALGAS_lsint & parameter_1,
                                Lexique_gtl_5F_scanner * inLexique) {
  rule_gtl_5F_instruction_5F_parser_gtl_5F_sorting_5F_order_i12_(parameter_1, inLexique) ;
}

//--------------------------------------------------------------------------------------------------
//
//                   'select_gtl_5F_parser_0' added non terminal implementation                     
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_0 (Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//                   'select_gtl_5F_parser_1' added non terminal implementation                     
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_1 (Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//                   'select_gtl_5F_parser_2' added non terminal implementation                     
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_2 (Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//                   'select_gtl_5F_parser_3' added non terminal implementation                     
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_3 (Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//                   'select_gtl_5F_parser_4' added non terminal implementation                     
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_4 (Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//                   'select_gtl_5F_parser_5' added non terminal implementation                     
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_5 (Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//                   'select_gtl_5F_parser_6' added non terminal implementation                     
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_6 (Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//                   'select_gtl_5F_parser_7' added non terminal implementation                     
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_7 (Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//                   'select_gtl_5F_parser_8' added non terminal implementation                     
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_8 (Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//                   'select_gtl_5F_parser_9' added non terminal implementation                     
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_9 (Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//                  'select_gtl_5F_parser_10' added non terminal implementation                     
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_10 (Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//                  'select_gtl_5F_parser_11' added non terminal implementation                     
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_11 (Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//                  'select_gtl_5F_parser_12' added non terminal implementation                     
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_12 (Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//                  'select_gtl_5F_parser_13' added non terminal implementation                     
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_13 (Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//                  'select_gtl_5F_parser_14' added non terminal implementation                     
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_14 (Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//                  'select_gtl_5F_parser_15' added non terminal implementation                     
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_15 (Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//                  'select_gtl_5F_parser_16' added non terminal implementation                     
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_16 (Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//                  'select_gtl_5F_parser_17' added non terminal implementation                     
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_17 (Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//                  'select_gtl_5F_parser_18' added non terminal implementation                     
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_18 (Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//                  'select_gtl_5F_parser_19' added non terminal implementation                     
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_19 (Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//                  'select_gtl_5F_parser_20' added non terminal implementation                     
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_20 (Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//                  'select_gtl_5F_parser_21' added non terminal implementation                     
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_21 (Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//                  'select_gtl_5F_parser_22' added non terminal implementation                     
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_22 (Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//                  'select_gtl_5F_parser_23' added non terminal implementation                     
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_23 (Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//                  'select_gtl_5F_parser_24' added non terminal implementation                     
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_24 (Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//                  'select_gtl_5F_parser_25' added non terminal implementation                     
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_parser_25 (Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//            'select_gtl_5F_expression_5F_parser_0' added non terminal implementation              
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_0 (Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//            'select_gtl_5F_expression_5F_parser_1' added non terminal implementation              
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_1 (Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//            'select_gtl_5F_expression_5F_parser_2' added non terminal implementation              
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_2 (Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//            'select_gtl_5F_expression_5F_parser_3' added non terminal implementation              
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_3 (Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//            'select_gtl_5F_expression_5F_parser_4' added non terminal implementation              
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_4 (Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//            'select_gtl_5F_expression_5F_parser_5' added non terminal implementation              
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_5 (Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//            'select_gtl_5F_expression_5F_parser_6' added non terminal implementation              
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_6 (Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//            'select_gtl_5F_expression_5F_parser_7' added non terminal implementation              
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_7 (Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//            'select_gtl_5F_expression_5F_parser_8' added non terminal implementation              
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_8 (Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//            'select_gtl_5F_expression_5F_parser_9' added non terminal implementation              
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_9 (Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//           'select_gtl_5F_expression_5F_parser_10' added non terminal implementation              
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_10 (Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//           'select_gtl_5F_expression_5F_parser_11' added non terminal implementation              
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_11 (Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//           'select_gtl_5F_expression_5F_parser_12' added non terminal implementation              
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_12 (Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//           'select_gtl_5F_expression_5F_parser_13' added non terminal implementation              
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_13 (Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//           'select_gtl_5F_expression_5F_parser_14' added non terminal implementation              
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_14 (Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//           'select_gtl_5F_expression_5F_parser_15' added non terminal implementation              
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_15 (Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//           'select_gtl_5F_expression_5F_parser_16' added non terminal implementation              
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_16 (Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//           'select_gtl_5F_expression_5F_parser_17' added non terminal implementation              
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_17 (Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//           'select_gtl_5F_expression_5F_parser_18' added non terminal implementation              
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_18 (Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//           'select_gtl_5F_expression_5F_parser_19' added non terminal implementation              
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_19 (Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//           'select_gtl_5F_expression_5F_parser_20' added non terminal implementation              
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_20 (Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//           'select_gtl_5F_expression_5F_parser_21' added non terminal implementation              
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_21 (Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//           'select_gtl_5F_expression_5F_parser_22' added non terminal implementation              
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_22 (Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//           'select_gtl_5F_expression_5F_parser_23' added non terminal implementation              
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_23 (Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//           'select_gtl_5F_expression_5F_parser_24' added non terminal implementation              
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_24 (Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//           'select_gtl_5F_expression_5F_parser_25' added non terminal implementation              
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_25 (Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//           'select_gtl_5F_expression_5F_parser_26' added non terminal implementation              
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_26 (Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//           'select_gtl_5F_expression_5F_parser_27' added non terminal implementation              
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_expression_5F_parser_27 (Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//           'select_gtl_5F_instruction_5F_parser_0' added non terminal implementation              
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_instruction_5F_parser_0 (Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//           'select_gtl_5F_instruction_5F_parser_1' added non terminal implementation              
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_instruction_5F_parser_1 (Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//           'select_gtl_5F_instruction_5F_parser_2' added non terminal implementation              
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_instruction_5F_parser_2 (Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//           'select_gtl_5F_instruction_5F_parser_3' added non terminal implementation              
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_instruction_5F_parser_3 (Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//           'select_gtl_5F_instruction_5F_parser_4' added non terminal implementation              
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_instruction_5F_parser_4 (Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//           'select_gtl_5F_instruction_5F_parser_5' added non terminal implementation              
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_instruction_5F_parser_5 (Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------
//
//           'select_gtl_5F_instruction_5F_parser_6' added non terminal implementation              
//
//--------------------------------------------------------------------------------------------------

int32_t cGrammar_gtl_5F_grammar::select_gtl_5F_instruction_5F_parser_6 (Lexique_gtl_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//--------------------------------------------------------------------------------------------------

//--------------------------------------------------------------------------------------------------
//
//Function 'invokeGTL'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string function_invokeGTL (GALGAS_gtlString inArgument_rootTemplateFileName,
                                  GALGAS_gtlContext inArgument_context,
                                  GALGAS_gtlData inArgument_vars,
                                  Compiler * inCompiler
                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::makeEmptyString () ;
  GALGAS_library var_lib_1096 = function_emptyLib (inCompiler COMMA_SOURCE_FILE ("gtl_interface.galgas", 36)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (gOption_gtl_5F_options_debug.readProperty_value ()).boolEnum () ;
    if (kBoolTrue == test_0) {
      inCompiler->printMessage (GALGAS_string ("Starting debugger, type help for command list\n")  COMMA_SOURCE_FILE ("gtl_interface.galgas", 39)) ;
      extensionMethod_loadCommandFile (GALGAS_string (".gtlinit"), inArgument_context, inArgument_vars, var_lib_1096, inCompiler COMMA_SOURCE_FILE ("gtl_interface.galgas", 40)) ;
    }
  }
  GALGAS_gtlTemplateInstruction var_rootTemplateInstruction_1349 = GALGAS_gtlTemplateInstruction::class_func_new (GALGAS_location::class_func_here (inCompiler  COMMA_SOURCE_FILE ("gtl_interface.galgas", 45)), GALGAS_string::makeEmptyString (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_interface.galgas", 47)), GALGAS_gtlTerminal::class_func_new (GALGAS_location::class_func_here (inCompiler  COMMA_SOURCE_FILE ("gtl_interface.galgas", 49)), inArgument_rootTemplateFileName  COMMA_SOURCE_FILE ("gtl_interface.galgas", 48)), GALGAS_bool (false), GALGAS_bool (true), GALGAS_gtlExpressionList::class_func_emptyList (SOURCE_FILE ("gtl_interface.galgas", 54)), GALGAS_gtlInstructionList::class_func_emptyList (SOURCE_FILE ("gtl_interface.galgas", 55))  COMMA_SOURCE_FILE ("gtl_interface.galgas", 44)) ;
  callExtensionMethod_execute ((cPtr_gtlTemplateInstruction *) var_rootTemplateInstruction_1349.ptr (), inArgument_context, inArgument_vars, var_lib_1096, result_result, inCompiler COMMA_SOURCE_FILE ("gtl_interface.galgas", 59)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_invokeGTL [4] = {
  & kTypeDescriptor_GALGAS_gtlString,
  & kTypeDescriptor_GALGAS_gtlContext,
  & kTypeDescriptor_GALGAS_gtlData,
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_invokeGTL (Compiler * inCompiler,
                                                          const cObjectArray & inEffectiveParameterArray,
                                                          const GALGAS_location & /* inErrorLocation */
                                                          COMMA_LOCATION_ARGS) {
  const GALGAS_gtlString operand0 = GALGAS_gtlString::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                     inCompiler
                                                                     COMMA_THERE) ;
  const GALGAS_gtlContext operand1 = GALGAS_gtlContext::extractObject (inEffectiveParameterArray.objectAtIndex (1 COMMA_HERE),
                                                                       inCompiler
                                                                       COMMA_THERE) ;
  const GALGAS_gtlData operand2 = GALGAS_gtlData::extractObject (inEffectiveParameterArray.objectAtIndex (2 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  return function_invokeGTL (operand0,
                             operand1,
                             operand2,
                             inCompiler
                             COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_invokeGTL ("invokeGTL",
                                                           functionWithGenericHeader_invokeGTL,
                                                           & kTypeDescriptor_GALGAS_string,
                                                           3,
                                                           functionArgs_invokeGTL) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'emptyVarContainer'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData function_emptyVarContainer (Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  result_result = GALGAS_gtlStruct::class_func_new (GALGAS_location::class_func_nowhere (SOURCE_FILE ("gtl_interface.galgas", 73)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_interface.galgas", 73)), GALGAS_gtlVarMap::class_func_emptyMap (SOURCE_FILE ("gtl_interface.galgas", 73))  COMMA_SOURCE_FILE ("gtl_interface.galgas", 73)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_emptyVarContainer [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_emptyVarContainer (Compiler * inCompiler,
                                                                  const cObjectArray & /* inEffectiveParameterArray */,
                                                                  const GALGAS_location & /* inErrorLocation */
                                                                  COMMA_LOCATION_ARGS) {
  return function_emptyVarContainer (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_emptyVarContainer ("emptyVarContainer",
                                                                   functionWithGenericHeader_emptyVarContainer,
                                                                   & kTypeDescriptor_GALGAS_gtlData,
                                                                   0,
                                                                   functionArgs_emptyVarContainer) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'lstringToGtlString'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlString function_lstringToGtlString (GALGAS_lstring inArgument_input,
                                              Compiler * inCompiler
                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlString result_output ; // Returned variable
  result_output = GALGAS_gtlString::class_func_new (inArgument_input.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_interface.galgas", 83)), inArgument_input.readProperty_string ()  COMMA_SOURCE_FILE ("gtl_interface.galgas", 83)) ;
//---
  return result_output ;
}


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_lstringToGtlString [2] = {
  & kTypeDescriptor_GALGAS_lstring,
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_lstringToGtlString (Compiler * inCompiler,
                                                                   const cObjectArray & inEffectiveParameterArray,
                                                                   const GALGAS_location & /* inErrorLocation */
                                                                   COMMA_LOCATION_ARGS) {
  const GALGAS_lstring operand0 = GALGAS_lstring::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                                 inCompiler
                                                                 COMMA_THERE) ;
  return function_lstringToGtlString (operand0,
                                      inCompiler
                                      COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_lstringToGtlString ("lstringToGtlString",
                                                                    functionWithGenericHeader_lstringToGtlString,
                                                                    & kTypeDescriptor_GALGAS_gtlString,
                                                                    1,
                                                                    functionArgs_lstringToGtlString) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'stringToGtlString'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlString function_stringToGtlString (GALGAS_string inArgument_input,
                                             Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlString result_output ; // Returned variable
  result_output = GALGAS_gtlString::class_func_new (GALGAS_location::class_func_nowhere (SOURCE_FILE ("gtl_interface.galgas", 93)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_interface.galgas", 93)), inArgument_input  COMMA_SOURCE_FILE ("gtl_interface.galgas", 93)) ;
//---
  return result_output ;
}


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_stringToGtlString [2] = {
  & kTypeDescriptor_GALGAS_string,
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_stringToGtlString (Compiler * inCompiler,
                                                                  const cObjectArray & inEffectiveParameterArray,
                                                                  const GALGAS_location & /* inErrorLocation */
                                                                  COMMA_LOCATION_ARGS) {
  const GALGAS_string operand0 = GALGAS_string::extractObject (inEffectiveParameterArray.objectAtIndex (0 COMMA_HERE),
                                                               inCompiler
                                                               COMMA_THERE) ;
  return function_stringToGtlString (operand0,
                                     inCompiler
                                     COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_stringToGtlString ("stringToGtlString",
                                                                   functionWithGenericHeader_stringToGtlString,
                                                                   & kTypeDescriptor_GALGAS_gtlString,
                                                                   1,
                                                                   functionArgs_stringToGtlString) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'emptyContext'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlContext function_emptyContext (Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlContext result_context ; // Returned variable
  result_context = GALGAS_gtlContext::class_func_new (function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 46)), GALGAS_string::makeEmptyString (), GALGAS_string::makeEmptyString (), GALGAS_string::makeEmptyString (), GALGAS_string ("gtl"), GALGAS_stringlist::class_func_emptyList (SOURCE_FILE ("gtl_types.galgas", 51)), GALGAS_gtlDataList::class_func_emptyList (SOURCE_FILE ("gtl_types.galgas", 52)), GALGAS_bool (true), function_defaultDebugSettings (inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 54))  COMMA_SOURCE_FILE ("gtl_types.galgas", 45)) ;
//---
  return result_context ;
}


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_emptyContext [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_emptyContext (Compiler * inCompiler,
                                                             const cObjectArray & /* inEffectiveParameterArray */,
                                                             const GALGAS_location & /* inErrorLocation */
                                                             COMMA_LOCATION_ARGS) {
  return function_emptyContext (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_emptyContext ("emptyContext",
                                                              functionWithGenericHeader_emptyContext,
                                                              & kTypeDescriptor_GALGAS_gtlContext,
                                                              0,
                                                              functionArgs_emptyContext) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'pathWithExtension'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string function_pathWithExtension (GALGAS_gtlContext inArgument_context,
                                          GALGAS_string inArgument_path,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_extendedPath ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsNotEqual, inArgument_path.getter_pathExtension (SOURCE_FILE ("gtl_types.galgas", 96)).objectCompare (inArgument_context.readProperty_templateExtension ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      result_extendedPath = inArgument_path.add_operation (GALGAS_string ("."), inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 97)).add_operation (inArgument_context.readProperty_templateExtension (), inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 97)) ;
    }
  }
  if (kBoolFalse == test_0) {
    result_extendedPath = inArgument_path ;
  }
//---
  return result_extendedPath ;
}


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_pathWithExtension [3] = {
  & kTypeDescriptor_GALGAS_gtlContext,
  & kTypeDescriptor_GALGAS_string,
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_pathWithExtension (Compiler * inCompiler,
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

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_pathWithExtension ("pathWithExtension",
                                                                   functionWithGenericHeader_pathWithExtension,
                                                                   & kTypeDescriptor_GALGAS_string,
                                                                   2,
                                                                   functionArgs_pathWithExtension) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'emptyLib'
//
//--------------------------------------------------------------------------------------------------

GALGAS_library function_emptyLib (Compiler *
                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_library result_result ; // Returned variable
  result_result = GALGAS_library::class_func_new (GALGAS_gtlFuncMap::class_func_emptyMap (SOURCE_FILE ("gtl_types.galgas", 323)), GALGAS_gtlGetterMap::class_func_emptyMap (SOURCE_FILE ("gtl_types.galgas", 323)), GALGAS_gtlSetterMap::class_func_emptyMap (SOURCE_FILE ("gtl_types.galgas", 323)), GALGAS_gtlTemplateMap::class_func_emptyMap (SOURCE_FILE ("gtl_types.galgas", 323)), GALGAS_stringset::class_func_emptySet (SOURCE_FILE ("gtl_types.galgas", 323))  COMMA_SOURCE_FILE ("gtl_types.galgas", 323)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_emptyLib [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_emptyLib (Compiler * inCompiler,
                                                         const cObjectArray & /* inEffectiveParameterArray */,
                                                         const GALGAS_location & /* inErrorLocation */
                                                         COMMA_LOCATION_ARGS) {
  return function_emptyLib (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_emptyLib ("emptyLib",
                                                          functionWithGenericHeader_emptyLib,
                                                          & kTypeDescriptor_GALGAS_library,
                                                          0,
                                                          functionArgs_emptyLib) ;

//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlStruct overrideMap'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlStruct cPtr_gtlStruct::getter_overrideMap (Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlStruct result_mapOverriden ; // Returned variable
  result_mapOverriden = GALGAS_gtlStruct::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 35)), GALGAS_gtlVarMap::class_func_mapWithMapToOverride (this->mProperty_value  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 36))  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 33)) ;
//---
  return result_mapOverriden ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlStruct overriddenMap'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlStruct cPtr_gtlStruct::getter_overriddenMap (Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlStruct result_overriddenMap ; // Returned variable
  result_overriddenMap = GALGAS_gtlStruct::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 44)), this->mProperty_value.getter_overriddenMap (inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 44))  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 44)) ;
//---
  return result_overriddenMap ;
}


//--------------------------------------------------------------------------------------------------
//
//Function 'wantGtlStruct'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData function_wantGtlStruct (GALGAS_gtlData inArgument_inData,
                                       Compiler * inCompiler
                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_outData ; // Returned variable
  if (inArgument_inData.isValid ()) {
    if (inArgument_inData.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlStruct) {
      GALGAS_gtlStruct cast_1489_inDataStruct ((cPtr_gtlStruct *) inArgument_inData.ptr ()) ;
      result_outData = cast_1489_inDataStruct ;
    }else{
      result_outData = GALGAS_gtlStruct::class_func_new (callExtensionGetter_location ((const cPtr_gtlData *) inArgument_inData.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 56)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 56)), GALGAS_gtlVarMap::class_func_emptyMap (SOURCE_FILE ("gtl_expressions.galgas", 56))  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 56)) ;
    }
  }
//---
  return result_outData ;
}


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_wantGtlStruct [2] = {
  & kTypeDescriptor_GALGAS_gtlData,
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_wantGtlStruct (Compiler * inCompiler,
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

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_wantGtlStruct ("wantGtlStruct",
                                                               functionWithGenericHeader_wantGtlStruct,
                                                               & kTypeDescriptor_GALGAS_gtlData,
                                                               1,
                                                               functionArgs_wantGtlStruct) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'wantGtlMap'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData function_wantGtlMap (GALGAS_gtlData inArgument_inData,
                                    Compiler * inCompiler
                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_outData ; // Returned variable
  if (inArgument_inData.isValid ()) {
    if (inArgument_inData.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlMap) {
      GALGAS_gtlMap cast_1785_inDataMap ((cPtr_gtlMap *) inArgument_inData.ptr ()) ;
      result_outData = cast_1785_inDataMap ;
    }else{
      result_outData = GALGAS_gtlMap::class_func_new (callExtensionGetter_location ((const cPtr_gtlData *) inArgument_inData.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 69)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 69)), GALGAS_gtlVarMap::class_func_emptyMap (SOURCE_FILE ("gtl_expressions.galgas", 69))  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 69)) ;
    }
  }
//---
  return result_outData ;
}


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_wantGtlMap [2] = {
  & kTypeDescriptor_GALGAS_gtlData,
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_wantGtlMap (Compiler * inCompiler,
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

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_wantGtlMap ("wantGtlMap",
                                                            functionWithGenericHeader_wantGtlMap,
                                                            & kTypeDescriptor_GALGAS_gtlData,
                                                            1,
                                                            functionArgs_wantGtlMap) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'wantGtlList'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData function_wantGtlList (GALGAS_gtlData inArgument_inData,
                                     Compiler * inCompiler
                                     COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_outData ; // Returned variable
  if (inArgument_inData.isValid ()) {
    if (inArgument_inData.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlList) {
      GALGAS_gtlList cast_2074_inDataList ((cPtr_gtlList *) inArgument_inData.ptr ()) ;
      result_outData = cast_2074_inDataList ;
    }else{
      result_outData = GALGAS_gtlList::class_func_new (callExtensionGetter_location ((const cPtr_gtlData *) inArgument_inData.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 82)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 82)), GALGAS_list::class_func_emptyList (SOURCE_FILE ("gtl_expressions.galgas", 82))  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 82)) ;
    }
  }
//---
  return result_outData ;
}


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_wantGtlList [2] = {
  & kTypeDescriptor_GALGAS_gtlData,
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_wantGtlList (Compiler * inCompiler,
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

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_wantGtlList ("wantGtlList",
                                                             functionWithGenericHeader_wantGtlList,
                                                             & kTypeDescriptor_GALGAS_gtlData,
                                                             1,
                                                             functionArgs_wantGtlList) ;

//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlVarItemField location'
//
//--------------------------------------------------------------------------------------------------

GALGAS_location cPtr_gtlVarItemField::getter_location (Compiler */* inCompiler */
                                                       COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_location result_loc ; // Returned variable
  result_loc = this->mProperty_field.readProperty_location () ;
//---
  return result_loc ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlVarItemField stringPath'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlVarItemField::getter_stringPath (const GALGAS_gtlContext /* constinArgument_exeContext */,
                                                       const GALGAS_gtlData /* constinArgument_vars */,
                                                       const GALGAS_library /* constinArgument_lib */,
                                                       Compiler */* inCompiler */
                                                       COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = this->mProperty_field.readProperty_string () ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlVarItemField setInContext'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlVarItemField::method_setInContext (const GALGAS_gtlContext constinArgument_exeContext,
                                                GALGAS_gtlData & ioArgument_context,
                                                const GALGAS_gtlData constinArgument_vars,
                                                const GALGAS_library constinArgument_lib,
                                                const GALGAS_gtlVarPath constinArgument_path,
                                                const GALGAS_gtlData constinArgument_newData,
                                                Compiler * inCompiler
                                                COMMA_UNUSED_LOCATION_ARGS) {
  ioArgument_context = function_wantGtlStruct (ioArgument_context, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 184)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, constinArgument_path.getter_count (SOURCE_FILE ("gtl_expressions.galgas", 185)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      ioArgument_context.insulate (HERE) ;
      cPtr_gtlData * ptr_5570 = (cPtr_gtlData *) ioArgument_context.ptr () ;
      callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_5570, this->mProperty_field, constinArgument_newData, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 186)) ;
      }
    }
  }
  if (kBoolFalse == test_0) {
    GALGAS_gtlData var_data_5659 ;
    GALGAS_bool joker_5664 ; // Joker input parameter
    callExtensionMethod_structField ((cPtr_gtlData *) ioArgument_context.ptr (), this->mProperty_field, var_data_5659, joker_5664, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 188)) ;
    callExtensionMethod_setInContext ((cPtr_gtlVarItem *) constinArgument_path.getter_itemAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 189)).ptr (), constinArgument_exeContext, var_data_5659, constinArgument_vars, constinArgument_lib, constinArgument_path.getter_subListFromIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 194)), constinArgument_newData, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 189)) ;
    {
    ioArgument_context.insulate (HERE) ;
    cPtr_gtlData * ptr_5824 = (cPtr_gtlData *) ioArgument_context.ptr () ;
    callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_5824, this->mProperty_field, var_data_5659, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 197)) ;
    }
  }
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlVarItemField getInContext'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlVarItemField::getter_getInContext (const GALGAS_gtlContext constinArgument_exeContext,
                                                          const GALGAS_gtlData constinArgument_context,
                                                          const GALGAS_gtlData constinArgument_vars,
                                                          const GALGAS_library constinArgument_lib,
                                                          const GALGAS_gtlVarPath constinArgument_path,
                                                          Compiler * inCompiler
                                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  GALGAS_gtlData var_data_6318 ;
  GALGAS_bool var_found_6334 ;
  callExtensionMethod_structField ((cPtr_gtlData *) constinArgument_context.ptr (), this->mProperty_field, var_data_6318, var_found_6334, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 212)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, constinArgument_path.getter_count (SOURCE_FILE ("gtl_expressions.galgas", 213)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = var_found_6334.boolEnum () ;
        if (kBoolTrue == test_1) {
          result_result = var_data_6318 ;
        }
      }
      if (kBoolFalse == test_1) {
        TC_Array <C_FixItDescription> fixItArray2 ;
        inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) var_data_6318.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 217)), GALGAS_string ("Variable or field does not exist"), fixItArray2  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 217)) ;
        result_result.drop () ; // Release error dropped variable
      }
    }
  }
  if (kBoolFalse == test_0) {
    result_result = callExtensionGetter_getInContext ((const cPtr_gtlVarItem *) constinArgument_path.getter_itemAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 220)).ptr (), constinArgument_exeContext, var_data_6318, constinArgument_vars, constinArgument_lib, constinArgument_path.getter_subListFromIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 225)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 220)) ;
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlVarItemField existsInContext'
//
//--------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_gtlVarItemField::getter_existsInContext (const GALGAS_gtlContext constinArgument_exeContext,
                                                          const GALGAS_gtlData constinArgument_context,
                                                          const GALGAS_gtlData constinArgument_vars,
                                                          const GALGAS_library constinArgument_lib,
                                                          const GALGAS_gtlVarPath constinArgument_path,
                                                          Compiler * inCompiler
                                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = callExtensionGetter_hasStructField ((const cPtr_gtlData *) constinArgument_context.ptr (), this->mProperty_field, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 241)).boolEnum () ;
    if (kBoolTrue == test_0) {
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = GALGAS_bool (kIsEqual, constinArgument_path.getter_count (SOURCE_FILE ("gtl_expressions.galgas", 242)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
        if (kBoolTrue == test_1) {
          result_result = GALGAS_bool (true) ;
        }
      }
      if (kBoolFalse == test_1) {
        GALGAS_gtlData var_subContext_7196 ;
        GALGAS_bool joker_7207 ; // Joker input parameter
        callExtensionMethod_structField ((cPtr_gtlData *) constinArgument_context.ptr (), this->mProperty_field, var_subContext_7196, joker_7207, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 245)) ;
        result_result = callExtensionGetter_existsInContext ((const cPtr_gtlVarItem *) constinArgument_path.getter_itemAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 246)).ptr (), constinArgument_exeContext, var_subContext_7196, constinArgument_vars, constinArgument_lib, constinArgument_path.getter_subListFromIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 251)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 246)) ;
      }
    }
  }
  if (kBoolFalse == test_0) {
    result_result = GALGAS_bool (false) ;
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlVarItemField deleteInContext'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlVarItemField::method_deleteInContext (const GALGAS_gtlContext constinArgument_exeContext,
                                                   GALGAS_gtlData & ioArgument_context,
                                                   const GALGAS_gtlData constinArgument_vars,
                                                   const GALGAS_library constinArgument_lib,
                                                   const GALGAS_gtlVarPath constinArgument_path,
                                                   Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = callExtensionGetter_hasStructField ((const cPtr_gtlData *) ioArgument_context.ptr (), this->mProperty_field, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 269)).boolEnum () ;
    if (kBoolTrue == test_0) {
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = GALGAS_bool (kIsEqual, constinArgument_path.getter_count (SOURCE_FILE ("gtl_expressions.galgas", 270)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
        if (kBoolTrue == test_1) {
          {
          ioArgument_context.insulate (HERE) ;
          cPtr_gtlData * ptr_7888 = (cPtr_gtlData *) ioArgument_context.ptr () ;
          callExtensionSetter_deleteStructField ((cPtr_gtlData *) ptr_7888, this->mProperty_field, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 271)) ;
          }
        }
      }
      if (kBoolFalse == test_1) {
        GALGAS_gtlData var_data_7975 ;
        GALGAS_bool joker_7980 ; // Joker input parameter
        callExtensionMethod_structField ((cPtr_gtlData *) ioArgument_context.ptr (), this->mProperty_field, var_data_7975, joker_7980, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 273)) ;
        callExtensionMethod_deleteInContext ((cPtr_gtlVarItem *) constinArgument_path.getter_itemAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 274)).ptr (), constinArgument_exeContext, var_data_7975, constinArgument_vars, constinArgument_lib, constinArgument_path.getter_subListFromIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 279)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 274)) ;
        {
        ioArgument_context.insulate (HERE) ;
        cPtr_gtlData * ptr_8144 = (cPtr_gtlData *) ioArgument_context.ptr () ;
        callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_8144, this->mProperty_field, var_data_7975, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 281)) ;
        }
      }
    }
  }
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlVarItemCollection stringPath'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlVarItemCollection::getter_stringPath (const GALGAS_gtlContext constinArgument_exeContext,
                                                            const GALGAS_gtlData constinArgument_vars,
                                                            const GALGAS_library constinArgument_lib,
                                                            Compiler * inCompiler
                                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = this->mProperty_field.readProperty_string ().add_operation (GALGAS_string ("["), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 297)) ;
  GALGAS_gtlData var_keyValue_8679 = callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 298)) ;
  if (var_keyValue_8679.isValid ()) {
    if (var_keyValue_8679.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlString) {
      GALGAS_gtlString cast_8761_keyString ((cPtr_gtlString *) var_keyValue_8679.ptr ()) ;
      result_result.plusAssign_operation(GALGAS_string ("\"").add_operation (callExtensionGetter_string ((const cPtr_gtlString *) cast_8761_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 301)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 301)).add_operation (GALGAS_string ("\""), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 301)), inCompiler  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 301)) ;
    }else if (var_keyValue_8679.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt) {
      GALGAS_gtlInt cast_8828_keyInt ((cPtr_gtlInt *) var_keyValue_8679.ptr ()) ;
      result_result.plusAssign_operation(callExtensionGetter_string ((const cPtr_gtlInt *) cast_8828_keyInt.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 303)), inCompiler  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 303)) ;
    }
  }
  result_result.plusAssign_operation(GALGAS_string ("]"), inCompiler  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 305)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlVarItemCollection setInContext'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlVarItemCollection::method_setInContext (const GALGAS_gtlContext constinArgument_exeContext,
                                                     GALGAS_gtlData & ioArgument_context,
                                                     const GALGAS_gtlData constinArgument_vars,
                                                     const GALGAS_library constinArgument_lib,
                                                     const GALGAS_gtlVarPath constinArgument_path,
                                                     const GALGAS_gtlData constinArgument_newData,
                                                     Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) {
  if (callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 319)).isValid ()) {
    if (callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 319)).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlString) {
      GALGAS_gtlString cast_9362_keyString ((cPtr_gtlString *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 319)).ptr ()) ;
      ioArgument_context = function_wantGtlStruct (ioArgument_context, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 321)) ;
      GALGAS_gtlData var_data_9453 ;
      GALGAS_bool joker_9458 ; // Joker input parameter
      callExtensionMethod_structField ((cPtr_gtlData *) ioArgument_context.ptr (), this->mProperty_field, var_data_9453, joker_9458, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 322)) ;
      var_data_9453 = function_wantGtlMap (var_data_9453, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 323)) ;
      enumGalgasBool test_0 = kBoolTrue ;
      if (kBoolTrue == test_0) {
        test_0 = GALGAS_bool (kIsEqual, constinArgument_path.getter_count (SOURCE_FILE ("gtl_expressions.galgas", 324)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
        if (kBoolTrue == test_0) {
          {
          var_data_9453.insulate (HERE) ;
          cPtr_gtlData * ptr_9531 = (cPtr_gtlData *) var_data_9453.ptr () ;
          callExtensionSetter_setMapItem ((cPtr_gtlData *) ptr_9531, callExtensionGetter_lstring ((const cPtr_gtlString *) cast_9362_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 325)), constinArgument_newData, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 325)) ;
          }
        }
      }
      if (kBoolFalse == test_0) {
        GALGAS_gtlData var_subContext_9618 ;
        callExtensionMethod_mapItem ((cPtr_gtlData *) var_data_9453.ptr (), callExtensionGetter_lstring ((const cPtr_gtlString *) cast_9362_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 327)), var_subContext_9618, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 327)) ;
        callExtensionMethod_setInContext ((cPtr_gtlVarItem *) constinArgument_path.getter_itemAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 328)).ptr (), constinArgument_exeContext, var_subContext_9618, constinArgument_vars, constinArgument_lib, constinArgument_path.getter_subListFromIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 333)), constinArgument_newData, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 328)) ;
        {
        var_data_9453.insulate (HERE) ;
        cPtr_gtlData * ptr_9810 = (cPtr_gtlData *) var_data_9453.ptr () ;
        callExtensionSetter_setMapItem ((cPtr_gtlData *) ptr_9810, callExtensionGetter_lstring ((const cPtr_gtlString *) cast_9362_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 336)), var_subContext_9618, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 336)) ;
        }
      }
      {
      ioArgument_context.insulate (HERE) ;
      cPtr_gtlData * ptr_9865 = (cPtr_gtlData *) ioArgument_context.ptr () ;
      callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_9865, this->mProperty_field, var_data_9453, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 338)) ;
      }
    }else if (callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 319)).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt) {
      GALGAS_gtlInt cast_9920_keyInt ((cPtr_gtlInt *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 319)).ptr ()) ;
      ioArgument_context = function_wantGtlStruct (ioArgument_context, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 340)) ;
      GALGAS_gtlData var_data_10008 ;
      GALGAS_bool joker_10013 ; // Joker input parameter
      callExtensionMethod_structField ((cPtr_gtlData *) ioArgument_context.ptr (), this->mProperty_field, var_data_10008, joker_10013, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 341)) ;
      var_data_10008 = function_wantGtlList (var_data_10008, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 342)) ;
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = GALGAS_bool (kIsEqual, constinArgument_path.getter_count (SOURCE_FILE ("gtl_expressions.galgas", 343)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
        if (kBoolTrue == test_1) {
          {
          var_data_10008.insulate (HERE) ;
          cPtr_gtlData * ptr_10087 = (cPtr_gtlData *) var_data_10008.ptr () ;
          callExtensionSetter_setItemAtIndex ((cPtr_gtlData *) ptr_10087, constinArgument_newData, cast_9920_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 344)) ;
          }
        }
      }
      if (kBoolFalse == test_1) {
        GALGAS_gtlData var_subContext_10168 ;
        callExtensionMethod_itemAtIndex ((cPtr_gtlData *) var_data_10008.ptr (), var_subContext_10168, cast_9920_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 346)) ;
        callExtensionMethod_setInContext ((cPtr_gtlVarItem *) constinArgument_path.getter_itemAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 347)).ptr (), constinArgument_exeContext, var_subContext_10168, constinArgument_vars, constinArgument_lib, constinArgument_path.getter_subListFromIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 352)), constinArgument_newData, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 347)) ;
        {
        var_data_10008.insulate (HERE) ;
        cPtr_gtlData * ptr_10368 = (cPtr_gtlData *) var_data_10008.ptr () ;
        callExtensionSetter_setItemAtIndex ((cPtr_gtlData *) ptr_10368, var_subContext_10168, cast_9920_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 355)) ;
        }
      }
      {
      ioArgument_context.insulate (HERE) ;
      cPtr_gtlData * ptr_10424 = (cPtr_gtlData *) ioArgument_context.ptr () ;
      callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_10424, this->mProperty_field, var_data_10008, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 357)) ;
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 359)), GALGAS_string ("string ot int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 359)) ;
    }
  }
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlVarItemCollection getInContext'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlVarItemCollection::getter_getInContext (const GALGAS_gtlContext constinArgument_exeContext,
                                                               const GALGAS_gtlData constinArgument_context,
                                                               const GALGAS_gtlData constinArgument_vars,
                                                               const GALGAS_library constinArgument_lib,
                                                               const GALGAS_gtlVarPath constinArgument_path,
                                                               Compiler * inCompiler
                                                               COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  GALGAS_gtlData var_collection_10972 ;
  GALGAS_bool joker_10983 ; // Joker input parameter
  callExtensionMethod_structField ((cPtr_gtlData *) constinArgument_context.ptr (), this->mProperty_field, var_collection_10972, joker_10983, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 374)) ;
  if (callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 375)).isValid ()) {
    if (callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 375)).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlString) {
      GALGAS_gtlString cast_11049_keyString ((cPtr_gtlString *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 375)).ptr ()) ;
      enumGalgasBool test_0 = kBoolTrue ;
      if (kBoolTrue == test_0) {
        test_0 = GALGAS_bool (kIsEqual, constinArgument_path.getter_count (SOURCE_FILE ("gtl_expressions.galgas", 377)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
        if (kBoolTrue == test_0) {
          callExtensionMethod_mapItem ((cPtr_gtlData *) var_collection_10972.ptr (), callExtensionGetter_lstring ((const cPtr_gtlString *) cast_11049_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 378)), result_result, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 378)) ;
        }
      }
      if (kBoolFalse == test_0) {
        GALGAS_gtlData var_subContext_11197 ;
        callExtensionMethod_mapItem ((cPtr_gtlData *) var_collection_10972.ptr (), callExtensionGetter_lstring ((const cPtr_gtlString *) cast_11049_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 380)), var_subContext_11197, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 380)) ;
        result_result = callExtensionGetter_getInContext ((const cPtr_gtlVarItem *) constinArgument_path.getter_itemAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 381)).ptr (), constinArgument_exeContext, var_subContext_11197, constinArgument_vars, constinArgument_lib, constinArgument_path.getter_subListFromIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 386)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 381)) ;
      }
    }else if (callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 375)).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt) {
      GALGAS_gtlInt cast_11397_keyInt ((cPtr_gtlInt *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 375)).ptr ()) ;
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = GALGAS_bool (kIsEqual, constinArgument_path.getter_count (SOURCE_FILE ("gtl_expressions.galgas", 390)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
        if (kBoolTrue == test_1) {
          callExtensionMethod_itemAtIndex ((cPtr_gtlData *) var_collection_10972.ptr (), result_result, cast_11397_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 391)) ;
        }
      }
      if (kBoolFalse == test_1) {
        GALGAS_gtlData var_subContext_11536 ;
        callExtensionMethod_itemAtIndex ((cPtr_gtlData *) var_collection_10972.ptr (), var_subContext_11536, cast_11397_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 393)) ;
        result_result = callExtensionGetter_getInContext ((const cPtr_gtlVarItem *) constinArgument_path.getter_itemAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 394)).ptr (), constinArgument_exeContext, var_subContext_11536, constinArgument_vars, constinArgument_lib, constinArgument_path.getter_subListFromIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 399)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 394)) ;
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 403)), GALGAS_string ("string ot int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 403)) ;
      result_result.drop () ; // Release error dropped variable
    }
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlVarItemCollection existsInContext'
//
//--------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_gtlVarItemCollection::getter_existsInContext (const GALGAS_gtlContext constinArgument_exeContext,
                                                               const GALGAS_gtlData constinArgument_context,
                                                               const GALGAS_gtlData constinArgument_vars,
                                                               const GALGAS_library constinArgument_lib,
                                                               const GALGAS_gtlVarPath constinArgument_path,
                                                               Compiler * inCompiler
                                                               COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = callExtensionGetter_hasStructField ((const cPtr_gtlData *) constinArgument_context.ptr (), this->mProperty_field, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 419)).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlData var_collection_12308 ;
      GALGAS_bool joker_12319 ; // Joker input parameter
      callExtensionMethod_structField ((cPtr_gtlData *) constinArgument_context.ptr (), this->mProperty_field, var_collection_12308, joker_12319, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 420)) ;
      if (callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 421)).isValid ()) {
        if (callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 421)).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlString) {
          GALGAS_gtlString cast_12389_keyString ((cPtr_gtlString *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 421)).ptr ()) ;
          enumGalgasBool test_1 = kBoolTrue ;
          if (kBoolTrue == test_1) {
            test_1 = GALGAS_bool (kIsEqual, constinArgument_path.getter_count (SOURCE_FILE ("gtl_expressions.galgas", 423)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
            if (kBoolTrue == test_1) {
              result_result = callExtensionGetter_hasMapItem ((const cPtr_gtlData *) var_collection_12308.ptr (), callExtensionGetter_lstring ((const cPtr_gtlString *) cast_12389_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 424)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 424)) ;
            }
          }
          if (kBoolFalse == test_1) {
            enumGalgasBool test_2 = kBoolTrue ;
            if (kBoolTrue == test_2) {
              test_2 = callExtensionGetter_hasMapItem ((const cPtr_gtlData *) var_collection_12308.ptr (), callExtensionGetter_lstring ((const cPtr_gtlString *) cast_12389_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 426)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 426)).boolEnum () ;
              if (kBoolTrue == test_2) {
                GALGAS_gtlData var_subContext_12602 ;
                callExtensionMethod_mapItem ((cPtr_gtlData *) var_collection_12308.ptr (), callExtensionGetter_lstring ((const cPtr_gtlString *) cast_12389_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 427)), var_subContext_12602, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 427)) ;
                result_result = callExtensionGetter_existsInContext ((const cPtr_gtlVarItem *) constinArgument_path.getter_itemAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 428)).ptr (), constinArgument_exeContext, var_subContext_12602, constinArgument_vars, constinArgument_lib, constinArgument_path.getter_subListFromIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 433)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 428)) ;
              }
            }
            if (kBoolFalse == test_2) {
              result_result = GALGAS_bool (false) ;
            }
          }
        }else if (callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 421)).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt) {
          GALGAS_gtlInt cast_12887_keyInt ((cPtr_gtlInt *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 421)).ptr ()) ;
          enumGalgasBool test_3 = kBoolTrue ;
          if (kBoolTrue == test_3) {
            test_3 = GALGAS_bool (kIsEqual, constinArgument_path.getter_count (SOURCE_FILE ("gtl_expressions.galgas", 440)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
            if (kBoolTrue == test_3) {
              result_result = callExtensionGetter_hasItemAtIndex ((const cPtr_gtlData *) var_collection_12308.ptr (), cast_12887_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 441)) ;
            }
          }
          if (kBoolFalse == test_3) {
            enumGalgasBool test_4 = kBoolTrue ;
            if (kBoolTrue == test_4) {
              test_4 = callExtensionGetter_hasItemAtIndex ((const cPtr_gtlData *) var_collection_12308.ptr (), cast_12887_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 443)).boolEnum () ;
              if (kBoolTrue == test_4) {
                GALGAS_gtlData var_subContext_13092 ;
                callExtensionMethod_itemAtIndex ((cPtr_gtlData *) var_collection_12308.ptr (), var_subContext_13092, cast_12887_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 444)) ;
                result_result = callExtensionGetter_existsInContext ((const cPtr_gtlVarItem *) constinArgument_path.getter_itemAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 445)).ptr (), constinArgument_exeContext, var_subContext_13092, constinArgument_vars, constinArgument_lib, constinArgument_path.getter_subListFromIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 450)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 445)) ;
              }
            }
            if (kBoolFalse == test_4) {
              result_result = GALGAS_bool (false) ;
            }
          }
        }else{
          TC_Array <C_FixItDescription> fixItArray5 ;
          inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 457)), GALGAS_string ("string ot int expected"), fixItArray5  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 457)) ;
          result_result.drop () ; // Release error dropped variable
        }
      }
    }
  }
  if (kBoolFalse == test_0) {
    result_result = GALGAS_bool (false) ;
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlVarItemCollection deleteInContext'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlVarItemCollection::method_deleteInContext (const GALGAS_gtlContext constinArgument_exeContext,
                                                        GALGAS_gtlData & ioArgument_context,
                                                        const GALGAS_gtlData constinArgument_vars,
                                                        const GALGAS_library constinArgument_lib,
                                                        const GALGAS_gtlVarPath constinArgument_path,
                                                        Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  if (callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 474)).isValid ()) {
    if (callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 474)).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlString) {
      GALGAS_gtlString cast_13925_keyString ((cPtr_gtlString *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 474)).ptr ()) ;
      enumGalgasBool test_0 = kBoolTrue ;
      if (kBoolTrue == test_0) {
        test_0 = callExtensionGetter_hasStructField ((const cPtr_gtlData *) ioArgument_context.ptr (), this->mProperty_field, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 476)).boolEnum () ;
        if (kBoolTrue == test_0) {
          GALGAS_gtlData var_data_14024 ;
          GALGAS_bool joker_14029 ; // Joker input parameter
          callExtensionMethod_structField ((cPtr_gtlData *) ioArgument_context.ptr (), this->mProperty_field, var_data_14024, joker_14029, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 477)) ;
          enumGalgasBool test_1 = kBoolTrue ;
          if (kBoolTrue == test_1) {
            test_1 = GALGAS_bool (kIsEqual, constinArgument_path.getter_count (SOURCE_FILE ("gtl_expressions.galgas", 478)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
            if (kBoolTrue == test_1) {
              enumGalgasBool test_2 = kBoolTrue ;
              if (kBoolTrue == test_2) {
                test_2 = callExtensionGetter_hasMapItem ((const cPtr_gtlData *) var_data_14024.ptr (), callExtensionGetter_lstring ((const cPtr_gtlString *) cast_13925_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 479)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 479)).boolEnum () ;
                if (kBoolTrue == test_2) {
                  {
                  var_data_14024.insulate (HERE) ;
                  cPtr_gtlData * ptr_14124 = (cPtr_gtlData *) var_data_14024.ptr () ;
                  callExtensionSetter_deleteMapItem ((cPtr_gtlData *) ptr_14124, callExtensionGetter_lstring ((const cPtr_gtlString *) cast_13925_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 480)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 480)) ;
                  }
                }
              }
            }
          }
          if (kBoolFalse == test_1) {
            GALGAS_gtlData var_subContext_14221 ;
            callExtensionMethod_mapItem ((cPtr_gtlData *) var_data_14024.ptr (), callExtensionGetter_lstring ((const cPtr_gtlString *) cast_13925_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 483)), var_subContext_14221, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 483)) ;
            callExtensionMethod_deleteInContext ((cPtr_gtlVarItem *) constinArgument_path.getter_itemAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 484)).ptr (), constinArgument_exeContext, var_subContext_14221, constinArgument_vars, constinArgument_lib, constinArgument_path.getter_subListFromIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 489)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 484)) ;
            {
            var_data_14024.insulate (HERE) ;
            cPtr_gtlData * ptr_14415 = (cPtr_gtlData *) var_data_14024.ptr () ;
            callExtensionSetter_setMapItem ((cPtr_gtlData *) ptr_14415, callExtensionGetter_lstring ((const cPtr_gtlString *) cast_13925_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 491)), var_subContext_14221, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 491)) ;
            }
          }
          {
          ioArgument_context.insulate (HERE) ;
          cPtr_gtlData * ptr_14474 = (cPtr_gtlData *) ioArgument_context.ptr () ;
          callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_14474, this->mProperty_field, var_data_14024, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 493)) ;
          }
        }
      }
    }else if (callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 474)).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt) {
      GALGAS_gtlInt cast_14537_keyInt ((cPtr_gtlInt *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 474)).ptr ()) ;
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = callExtensionGetter_hasStructField ((const cPtr_gtlData *) ioArgument_context.ptr (), this->mProperty_field, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 496)).boolEnum () ;
        if (kBoolTrue == test_3) {
          GALGAS_gtlData var_data_14633 ;
          GALGAS_bool joker_14638 ; // Joker input parameter
          callExtensionMethod_structField ((cPtr_gtlData *) ioArgument_context.ptr (), this->mProperty_field, var_data_14633, joker_14638, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 497)) ;
          enumGalgasBool test_4 = kBoolTrue ;
          if (kBoolTrue == test_4) {
            test_4 = GALGAS_bool (kIsEqual, constinArgument_path.getter_count (SOURCE_FILE ("gtl_expressions.galgas", 498)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
            if (kBoolTrue == test_4) {
              enumGalgasBool test_5 = kBoolTrue ;
              if (kBoolTrue == test_5) {
                test_5 = callExtensionGetter_hasItemAtIndex ((const cPtr_gtlData *) var_data_14633.ptr (), cast_14537_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 499)).boolEnum () ;
                if (kBoolTrue == test_5) {
                  {
                  var_data_14633.insulate (HERE) ;
                  cPtr_gtlData * ptr_14734 = (cPtr_gtlData *) var_data_14633.ptr () ;
                  callExtensionSetter_deleteItemAtIndex ((cPtr_gtlData *) ptr_14734, cast_14537_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 500)) ;
                  }
                }
              }
            }
          }
          if (kBoolFalse == test_4) {
            GALGAS_gtlData var_subContext_14825 ;
            callExtensionMethod_itemAtIndex ((cPtr_gtlData *) var_data_14633.ptr (), var_subContext_14825, cast_14537_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 503)) ;
            callExtensionMethod_deleteInContext ((cPtr_gtlVarItem *) constinArgument_path.getter_itemAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 504)).ptr (), constinArgument_exeContext, var_subContext_14825, constinArgument_vars, constinArgument_lib, constinArgument_path.getter_subListFromIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 509)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 504)) ;
            {
            var_data_14633.insulate (HERE) ;
            cPtr_gtlData * ptr_15027 = (cPtr_gtlData *) var_data_14633.ptr () ;
            callExtensionSetter_setItemAtIndex ((cPtr_gtlData *) ptr_15027, var_subContext_14825, cast_14537_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 511)) ;
            }
          }
          {
          ioArgument_context.insulate (HERE) ;
          cPtr_gtlData * ptr_15087 = (cPtr_gtlData *) ioArgument_context.ptr () ;
          callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_15087, this->mProperty_field, var_data_14633, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 513)) ;
          }
        }
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray6 ;
      inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 516)), GALGAS_string ("string ot int expected"), fixItArray6  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 516)) ;
    }
  }
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlVarItemSubCollection location'
//
//--------------------------------------------------------------------------------------------------

GALGAS_location cPtr_gtlVarItemSubCollection::getter_location (Compiler */* inCompiler */
                                                               COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_location result_loc ; // Returned variable
  result_loc = this->mProperty_subCollectionlocation ;
//---
  return result_loc ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlVarItemSubCollection stringPath'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlVarItemSubCollection::getter_stringPath (const GALGAS_gtlContext constinArgument_exeContext,
                                                               const GALGAS_gtlData constinArgument_vars,
                                                               const GALGAS_library constinArgument_lib,
                                                               Compiler * inCompiler
                                                               COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string ("[") ;
  GALGAS_gtlData var_keyValue_15853 = callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 544)) ;
  if (var_keyValue_15853.isValid ()) {
    if (var_keyValue_15853.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlString) {
      GALGAS_gtlString cast_15935_keyString ((cPtr_gtlString *) var_keyValue_15853.ptr ()) ;
      result_result.plusAssign_operation(GALGAS_string ("\"").add_operation (callExtensionGetter_string ((const cPtr_gtlString *) cast_15935_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 547)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 547)).add_operation (GALGAS_string ("\""), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 547)), inCompiler  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 547)) ;
    }else if (var_keyValue_15853.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt) {
      GALGAS_gtlInt cast_16002_keyInt ((cPtr_gtlInt *) var_keyValue_15853.ptr ()) ;
      result_result.plusAssign_operation(callExtensionGetter_string ((const cPtr_gtlInt *) cast_16002_keyInt.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 549)), inCompiler  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 549)) ;
    }
  }
  result_result.plusAssign_operation(GALGAS_string ("]"), inCompiler  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 551)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlVarItemSubCollection setInContext'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlVarItemSubCollection::method_setInContext (const GALGAS_gtlContext constinArgument_exeContext,
                                                        GALGAS_gtlData & ioArgument_context,
                                                        const GALGAS_gtlData constinArgument_vars,
                                                        const GALGAS_library constinArgument_lib,
                                                        const GALGAS_gtlVarPath constinArgument_path,
                                                        const GALGAS_gtlData constinArgument_newData,
                                                        Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  if (callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 565)).isValid ()) {
    if (callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 565)).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlString) {
      GALGAS_gtlString cast_16542_keyString ((cPtr_gtlString *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 565)).ptr ()) ;
      ioArgument_context = function_wantGtlMap (ioArgument_context, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 567)) ;
      enumGalgasBool test_0 = kBoolTrue ;
      if (kBoolTrue == test_0) {
        test_0 = GALGAS_bool (kIsEqual, constinArgument_path.getter_count (SOURCE_FILE ("gtl_expressions.galgas", 568)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
        if (kBoolTrue == test_0) {
          {
          ioArgument_context.insulate (HERE) ;
          cPtr_gtlData * ptr_16628 = (cPtr_gtlData *) ioArgument_context.ptr () ;
          callExtensionSetter_setMapItem ((cPtr_gtlData *) ptr_16628, callExtensionGetter_lstring ((const cPtr_gtlString *) cast_16542_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 569)), constinArgument_newData, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 569)) ;
          }
        }
      }
      if (kBoolFalse == test_0) {
        GALGAS_gtlData var_subContext_16721 ;
        callExtensionMethod_mapItem ((cPtr_gtlData *) ioArgument_context.ptr (), callExtensionGetter_lstring ((const cPtr_gtlString *) cast_16542_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 571)), var_subContext_16721, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 571)) ;
        callExtensionMethod_setInContext ((cPtr_gtlVarItem *) constinArgument_path.getter_itemAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 572)).ptr (), constinArgument_exeContext, var_subContext_16721, constinArgument_vars, constinArgument_lib, constinArgument_path.getter_subListFromIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 577)), constinArgument_newData, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 572)) ;
        {
        ioArgument_context.insulate (HERE) ;
        cPtr_gtlData * ptr_16913 = (cPtr_gtlData *) ioArgument_context.ptr () ;
        callExtensionSetter_setMapItem ((cPtr_gtlData *) ptr_16913, callExtensionGetter_lstring ((const cPtr_gtlString *) cast_16542_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 580)), var_subContext_16721, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 580)) ;
        }
      }
    }else if (callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 565)).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt) {
      GALGAS_gtlInt cast_16982_keyInt ((cPtr_gtlInt *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 565)).ptr ()) ;
      ioArgument_context = function_wantGtlList (ioArgument_context, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 583)) ;
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = GALGAS_bool (kIsEqual, constinArgument_path.getter_count (SOURCE_FILE ("gtl_expressions.galgas", 584)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
        if (kBoolTrue == test_1) {
          {
          ioArgument_context.insulate (HERE) ;
          cPtr_gtlData * ptr_17066 = (cPtr_gtlData *) ioArgument_context.ptr () ;
          callExtensionSetter_setItemAtIndex ((cPtr_gtlData *) ptr_17066, constinArgument_newData, cast_16982_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 585)) ;
          }
        }
      }
      if (kBoolFalse == test_1) {
        GALGAS_gtlData var_subContext_17153 ;
        callExtensionMethod_itemAtIndex ((cPtr_gtlData *) ioArgument_context.ptr (), var_subContext_17153, cast_16982_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 587)) ;
        callExtensionMethod_setInContext ((cPtr_gtlVarItem *) constinArgument_path.getter_itemAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 588)).ptr (), constinArgument_exeContext, var_subContext_17153, constinArgument_vars, constinArgument_lib, constinArgument_path.getter_subListFromIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 593)), constinArgument_newData, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 588)) ;
        {
        ioArgument_context.insulate (HERE) ;
        cPtr_gtlData * ptr_17353 = (cPtr_gtlData *) ioArgument_context.ptr () ;
        callExtensionSetter_setItemAtIndex ((cPtr_gtlData *) ptr_17353, var_subContext_17153, cast_16982_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 596)) ;
        }
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 599)), GALGAS_string ("string ot int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 599)) ;
    }
  }
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlVarItemSubCollection getInContext'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlVarItemSubCollection::getter_getInContext (const GALGAS_gtlContext constinArgument_exeContext,
                                                                  const GALGAS_gtlData constinArgument_context,
                                                                  const GALGAS_gtlData constinArgument_vars,
                                                                  const GALGAS_library constinArgument_lib,
                                                                  const GALGAS_gtlVarPath constinArgument_path,
                                                                  Compiler * inCompiler
                                                                  COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  if (callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 614)).isValid ()) {
    if (callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 614)).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlString) {
      GALGAS_gtlString cast_17937_keyString ((cPtr_gtlString *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 614)).ptr ()) ;
      enumGalgasBool test_0 = kBoolTrue ;
      if (kBoolTrue == test_0) {
        test_0 = GALGAS_bool (kIsEqual, constinArgument_path.getter_count (SOURCE_FILE ("gtl_expressions.galgas", 616)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
        if (kBoolTrue == test_0) {
          callExtensionMethod_mapItem ((cPtr_gtlData *) constinArgument_context.ptr (), callExtensionGetter_lstring ((const cPtr_gtlString *) cast_17937_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 617)), result_result, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 617)) ;
        }
      }
      if (kBoolFalse == test_0) {
        GALGAS_gtlData var_subContext_18079 ;
        callExtensionMethod_mapItem ((cPtr_gtlData *) constinArgument_context.ptr (), callExtensionGetter_lstring ((const cPtr_gtlString *) cast_17937_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 619)), var_subContext_18079, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 619)) ;
        result_result = callExtensionGetter_getInContext ((const cPtr_gtlVarItem *) constinArgument_path.getter_itemAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 620)).ptr (), constinArgument_exeContext, var_subContext_18079, constinArgument_vars, constinArgument_lib, constinArgument_path.getter_subListFromIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 625)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 620)) ;
      }
    }else if (callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 614)).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt) {
      GALGAS_gtlInt cast_18279_keyInt ((cPtr_gtlInt *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 614)).ptr ()) ;
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = GALGAS_bool (kIsEqual, constinArgument_path.getter_count (SOURCE_FILE ("gtl_expressions.galgas", 629)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
        if (kBoolTrue == test_1) {
          callExtensionMethod_itemAtIndex ((cPtr_gtlData *) constinArgument_context.ptr (), result_result, cast_18279_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 630)) ;
        }
      }
      if (kBoolFalse == test_1) {
        GALGAS_gtlData var_subContext_18412 ;
        callExtensionMethod_itemAtIndex ((cPtr_gtlData *) constinArgument_context.ptr (), var_subContext_18412, cast_18279_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 632)) ;
        result_result = callExtensionGetter_getInContext ((const cPtr_gtlVarItem *) constinArgument_path.getter_itemAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 633)).ptr (), constinArgument_exeContext, var_subContext_18412, constinArgument_vars, constinArgument_lib, constinArgument_path.getter_subListFromIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 638)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 633)) ;
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray2 ;
      inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 642)), GALGAS_string ("string ot int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 642)) ;
      result_result.drop () ; // Release error dropped variable
    }
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlVarItemSubCollection existsInContext'
//
//--------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_gtlVarItemSubCollection::getter_existsInContext (const GALGAS_gtlContext constinArgument_exeContext,
                                                                  const GALGAS_gtlData constinArgument_context,
                                                                  const GALGAS_gtlData constinArgument_vars,
                                                                  const GALGAS_library constinArgument_lib,
                                                                  const GALGAS_gtlVarPath constinArgument_path,
                                                                  Compiler * inCompiler
                                                                  COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_result ; // Returned variable
  if (callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 657)).isValid ()) {
    if (callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 657)).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlString) {
      GALGAS_gtlString cast_19163_keyString ((cPtr_gtlString *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 657)).ptr ()) ;
      enumGalgasBool test_0 = kBoolTrue ;
      if (kBoolTrue == test_0) {
        test_0 = GALGAS_bool (kIsEqual, constinArgument_path.getter_count (SOURCE_FILE ("gtl_expressions.galgas", 659)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
        if (kBoolTrue == test_0) {
          result_result = callExtensionGetter_hasMapItem ((const cPtr_gtlData *) constinArgument_context.ptr (), callExtensionGetter_lstring ((const cPtr_gtlString *) cast_19163_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 660)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 660)) ;
        }
      }
      if (kBoolFalse == test_0) {
        enumGalgasBool test_1 = kBoolTrue ;
        if (kBoolTrue == test_1) {
          test_1 = callExtensionGetter_hasMapItem ((const cPtr_gtlData *) constinArgument_context.ptr (), callExtensionGetter_lstring ((const cPtr_gtlString *) cast_19163_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 662)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 662)).boolEnum () ;
          if (kBoolTrue == test_1) {
            GALGAS_gtlData var_subContext_19357 ;
            callExtensionMethod_mapItem ((cPtr_gtlData *) constinArgument_context.ptr (), callExtensionGetter_lstring ((const cPtr_gtlString *) cast_19163_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 663)), var_subContext_19357, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 663)) ;
            result_result = callExtensionGetter_existsInContext ((const cPtr_gtlVarItem *) constinArgument_path.getter_itemAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 664)).ptr (), constinArgument_exeContext, var_subContext_19357, constinArgument_vars, constinArgument_lib, constinArgument_path.getter_subListFromIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 669)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 664)) ;
          }
        }
        if (kBoolFalse == test_1) {
          result_result = GALGAS_bool (false) ;
        }
      }
    }else if (callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 657)).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt) {
      GALGAS_gtlInt cast_19618_keyInt ((cPtr_gtlInt *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 657)).ptr ()) ;
      enumGalgasBool test_2 = kBoolTrue ;
      if (kBoolTrue == test_2) {
        test_2 = GALGAS_bool (kIsEqual, constinArgument_path.getter_count (SOURCE_FILE ("gtl_expressions.galgas", 676)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
        if (kBoolTrue == test_2) {
          result_result = callExtensionGetter_hasItemAtIndex ((const cPtr_gtlData *) constinArgument_context.ptr (), cast_19618_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 677)) ;
        }
      }
      if (kBoolFalse == test_2) {
        enumGalgasBool test_3 = kBoolTrue ;
        if (kBoolTrue == test_3) {
          test_3 = callExtensionGetter_hasItemAtIndex ((const cPtr_gtlData *) constinArgument_context.ptr (), cast_19618_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 679)).boolEnum () ;
          if (kBoolTrue == test_3) {
            GALGAS_gtlData var_subContext_19804 ;
            callExtensionMethod_itemAtIndex ((cPtr_gtlData *) constinArgument_context.ptr (), var_subContext_19804, cast_19618_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 680)) ;
            result_result = callExtensionGetter_existsInContext ((const cPtr_gtlVarItem *) constinArgument_path.getter_itemAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 681)).ptr (), constinArgument_exeContext, var_subContext_19804, constinArgument_vars, constinArgument_lib, constinArgument_path.getter_subListFromIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 686)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 681)) ;
          }
        }
        if (kBoolFalse == test_3) {
          result_result = GALGAS_bool (false) ;
        }
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray4 ;
      inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 693)), GALGAS_string ("string ot int expected"), fixItArray4  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 693)) ;
      result_result.drop () ; // Release error dropped variable
    }
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlVarItemSubCollection deleteInContext'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlVarItemSubCollection::method_deleteInContext (const GALGAS_gtlContext constinArgument_exeContext,
                                                           GALGAS_gtlData & ioArgument_context,
                                                           const GALGAS_gtlData constinArgument_vars,
                                                           const GALGAS_library constinArgument_lib,
                                                           const GALGAS_gtlVarPath constinArgument_path,
                                                           Compiler * inCompiler
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  if (callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 707)).isValid ()) {
    if (callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 707)).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlString) {
      GALGAS_gtlString cast_20583_keyString ((cPtr_gtlString *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 707)).ptr ()) ;
      enumGalgasBool test_0 = kBoolTrue ;
      if (kBoolTrue == test_0) {
        test_0 = callExtensionGetter_hasMapItem ((const cPtr_gtlData *) ioArgument_context.ptr (), callExtensionGetter_lstring ((const cPtr_gtlString *) cast_20583_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 709)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 709)).boolEnum () ;
        if (kBoolTrue == test_0) {
          enumGalgasBool test_1 = kBoolTrue ;
          if (kBoolTrue == test_1) {
            test_1 = GALGAS_bool (kIsEqual, constinArgument_path.getter_count (SOURCE_FILE ("gtl_expressions.galgas", 710)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
            if (kBoolTrue == test_1) {
              {
              ioArgument_context.insulate (HERE) ;
              cPtr_gtlData * ptr_20682 = (cPtr_gtlData *) ioArgument_context.ptr () ;
              callExtensionSetter_deleteMapItem ((cPtr_gtlData *) ptr_20682, callExtensionGetter_lstring ((const cPtr_gtlString *) cast_20583_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 711)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 711)) ;
              }
            }
          }
          if (kBoolFalse == test_1) {
            GALGAS_gtlData var_subContext_20773 ;
            callExtensionMethod_mapItem ((cPtr_gtlData *) ioArgument_context.ptr (), callExtensionGetter_lstring ((const cPtr_gtlString *) cast_20583_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 713)), var_subContext_20773, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 713)) ;
            callExtensionMethod_deleteInContext ((cPtr_gtlVarItem *) constinArgument_path.getter_itemAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 714)).ptr (), constinArgument_exeContext, var_subContext_20773, constinArgument_vars, constinArgument_lib, constinArgument_path.getter_subListFromIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 719)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 714)) ;
            {
            ioArgument_context.insulate (HERE) ;
            cPtr_gtlData * ptr_20967 = (cPtr_gtlData *) ioArgument_context.ptr () ;
            callExtensionSetter_setMapItem ((cPtr_gtlData *) ptr_20967, callExtensionGetter_lstring ((const cPtr_gtlString *) cast_20583_keyString.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 721)), var_subContext_20773, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 721)) ;
            }
          }
        }
      }
    }else if (callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 707)).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt) {
      GALGAS_gtlInt cast_21046_keyInt ((cPtr_gtlInt *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), constinArgument_exeContext, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 707)).ptr ()) ;
      enumGalgasBool test_2 = kBoolTrue ;
      if (kBoolTrue == test_2) {
        test_2 = callExtensionGetter_hasItemAtIndex ((const cPtr_gtlData *) ioArgument_context.ptr (), cast_21046_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 725)).boolEnum () ;
        if (kBoolTrue == test_2) {
          enumGalgasBool test_3 = kBoolTrue ;
          if (kBoolTrue == test_3) {
            test_3 = GALGAS_bool (kIsEqual, constinArgument_path.getter_count (SOURCE_FILE ("gtl_expressions.galgas", 726)).objectCompare (GALGAS_uint (uint32_t (0U)))).boolEnum () ;
            if (kBoolTrue == test_3) {
              {
              ioArgument_context.insulate (HERE) ;
              cPtr_gtlData * ptr_21143 = (cPtr_gtlData *) ioArgument_context.ptr () ;
              callExtensionSetter_deleteItemAtIndex ((cPtr_gtlData *) ptr_21143, cast_21046_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 727)) ;
              }
            }
          }
          if (kBoolFalse == test_3) {
            GALGAS_gtlData var_subContext_21228 ;
            callExtensionMethod_itemAtIndex ((cPtr_gtlData *) ioArgument_context.ptr (), var_subContext_21228, cast_21046_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 729)) ;
            callExtensionMethod_deleteInContext ((cPtr_gtlVarItem *) constinArgument_path.getter_itemAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 730)).ptr (), constinArgument_exeContext, var_subContext_21228, constinArgument_vars, constinArgument_lib, constinArgument_path.getter_subListFromIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 735)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 730)) ;
            {
            ioArgument_context.insulate (HERE) ;
            cPtr_gtlData * ptr_21430 = (cPtr_gtlData *) ioArgument_context.ptr () ;
            callExtensionSetter_setItemAtIndex ((cPtr_gtlData *) ptr_21430, var_subContext_21228, cast_21046_keyInt, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 737)) ;
            }
          }
        }
      }
    }else{
      TC_Array <C_FixItDescription> fixItArray4 ;
      inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlExpression *) this->mProperty_key.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 741)), GALGAS_string ("string ot int expected"), fixItArray4  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 741)) ;
    }
  }
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlTerminal eval'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlTerminal::getter_eval (const GALGAS_gtlContext /* constinArgument_context */,
                                              const GALGAS_gtlData /* constinArgument_vars */,
                                              const GALGAS_library /* constinArgument_lib */,
                                              Compiler */* inCompiler */
                                              COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  result_result = this->mProperty_value ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlVarRef eval'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlVarRef::getter_eval (const GALGAS_gtlContext constinArgument_context,
                                            const GALGAS_gtlData constinArgument_vars,
                                            const GALGAS_library constinArgument_lib,
                                            Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  result_result = extensionGetter_get (this->mProperty_variableName, constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 931)) ;
  {
  result_result.setter_setWhere (this->mProperty_where COMMA_SOURCE_FILE ("gtl_expressions.galgas", 932)) ;
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlAllVarsRef eval'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlAllVarsRef::getter_eval (const GALGAS_gtlContext /* constinArgument_context */,
                                                const GALGAS_gtlData constinArgument_vars,
                                                const GALGAS_library /* constinArgument_lib */,
                                                Compiler */* inCompiler */
                                                COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  result_result = constinArgument_vars ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlParenthesizedExpression eval'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlParenthesizedExpression::getter_eval (const GALGAS_gtlContext constinArgument_context,
                                                             const GALGAS_gtlData constinArgument_vars,
                                                             const GALGAS_library constinArgument_lib,
                                                             Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  result_result = callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_son.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 962)) ;
  {
  result_result.setter_setWhere (this->mProperty_where COMMA_SOURCE_FILE ("gtl_expressions.galgas", 963)) ;
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMinusExpression eval'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlMinusExpression::getter_eval (const GALGAS_gtlContext constinArgument_context,
                                                     const GALGAS_gtlData constinArgument_vars,
                                                     const GALGAS_library constinArgument_lib,
                                                     Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  result_result = callExtensionGetter_minusOp ((const cPtr_gtlData *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_son.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 977)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 977)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlPlusExpression eval'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlPlusExpression::getter_eval (const GALGAS_gtlContext constinArgument_context,
                                                    const GALGAS_gtlData constinArgument_vars,
                                                    const GALGAS_library constinArgument_lib,
                                                    Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  result_result = callExtensionGetter_plusOp ((const cPtr_gtlData *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_son.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 991)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 991)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlNotExpression eval'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlNotExpression::getter_eval (const GALGAS_gtlContext constinArgument_context,
                                                   const GALGAS_gtlData constinArgument_vars,
                                                   const GALGAS_library constinArgument_lib,
                                                   Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  result_result = callExtensionGetter_notOp ((const cPtr_gtlData *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_son.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1005)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1005)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlAddExpression eval'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlAddExpression::getter_eval (const GALGAS_gtlContext constinArgument_context,
                                                   const GALGAS_gtlData constinArgument_vars,
                                                   const GALGAS_library constinArgument_lib,
                                                   Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  result_result = callExtensionGetter_addOp ((const cPtr_gtlData *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_lSon.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1021)).ptr (), callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_rSon.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1022)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1021)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlSubstractExpression eval'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlSubstractExpression::getter_eval (const GALGAS_gtlContext constinArgument_context,
                                                         const GALGAS_gtlData constinArgument_vars,
                                                         const GALGAS_library constinArgument_lib,
                                                         Compiler * inCompiler
                                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  result_result = callExtensionGetter_subOp ((const cPtr_gtlData *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_lSon.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1036)).ptr (), callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_rSon.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1037)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1036)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMultiplyExpression eval'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlMultiplyExpression::getter_eval (const GALGAS_gtlContext constinArgument_context,
                                                        const GALGAS_gtlData constinArgument_vars,
                                                        const GALGAS_library constinArgument_lib,
                                                        Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  result_result = callExtensionGetter_mulOp ((const cPtr_gtlData *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_lSon.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1051)).ptr (), callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_rSon.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1052)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1051)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlDivideExpression eval'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlDivideExpression::getter_eval (const GALGAS_gtlContext constinArgument_context,
                                                      const GALGAS_gtlData constinArgument_vars,
                                                      const GALGAS_library constinArgument_lib,
                                                      Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  result_result = callExtensionGetter_divOp ((const cPtr_gtlData *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_lSon.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1066)).ptr (), callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_rSon.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1067)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1066)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlModulusExpression eval'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlModulusExpression::getter_eval (const GALGAS_gtlContext constinArgument_context,
                                                       const GALGAS_gtlData constinArgument_vars,
                                                       const GALGAS_library constinArgument_lib,
                                                       Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  result_result = callExtensionGetter_modOp ((const cPtr_gtlData *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_lSon.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1081)).ptr (), callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_rSon.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1082)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1081)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlAndExpression eval'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlAndExpression::getter_eval (const GALGAS_gtlContext constinArgument_context,
                                                   const GALGAS_gtlData constinArgument_vars,
                                                   const GALGAS_library constinArgument_lib,
                                                   Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  result_result = callExtensionGetter_andOp ((const cPtr_gtlData *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_lSon.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1096)).ptr (), callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_rSon.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1097)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1096)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlOrExpression eval'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlOrExpression::getter_eval (const GALGAS_gtlContext constinArgument_context,
                                                  const GALGAS_gtlData constinArgument_vars,
                                                  const GALGAS_library constinArgument_lib,
                                                  Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  result_result = callExtensionGetter_orOp ((const cPtr_gtlData *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_lSon.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1111)).ptr (), callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_rSon.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1112)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1111)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlXorExpression eval'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlXorExpression::getter_eval (const GALGAS_gtlContext constinArgument_context,
                                                   const GALGAS_gtlData constinArgument_vars,
                                                   const GALGAS_library constinArgument_lib,
                                                   Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  result_result = callExtensionGetter_xorOp ((const cPtr_gtlData *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_lSon.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1126)).ptr (), callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_rSon.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1127)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1126)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlShiftLeftExpression eval'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlShiftLeftExpression::getter_eval (const GALGAS_gtlContext constinArgument_context,
                                                         const GALGAS_gtlData constinArgument_vars,
                                                         const GALGAS_library constinArgument_lib,
                                                         Compiler * inCompiler
                                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  result_result = callExtensionGetter_slOp ((const cPtr_gtlData *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_lSon.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1141)).ptr (), callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_rSon.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1142)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1141)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlShiftRightExpression eval'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlShiftRightExpression::getter_eval (const GALGAS_gtlContext constinArgument_context,
                                                          const GALGAS_gtlData constinArgument_vars,
                                                          const GALGAS_library constinArgument_lib,
                                                          Compiler * inCompiler
                                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  result_result = callExtensionGetter_srOp ((const cPtr_gtlData *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_lSon.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1156)).ptr (), callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_rSon.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1157)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1156)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlNotEqualExpression eval'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlNotEqualExpression::getter_eval (const GALGAS_gtlContext constinArgument_context,
                                                        const GALGAS_gtlData constinArgument_vars,
                                                        const GALGAS_library constinArgument_lib,
                                                        Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  result_result = callExtensionGetter_neqOp ((const cPtr_gtlData *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_lSon.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1171)).ptr (), callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_rSon.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1172)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1171)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEqualExpression eval'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlEqualExpression::getter_eval (const GALGAS_gtlContext constinArgument_context,
                                                     const GALGAS_gtlData constinArgument_vars,
                                                     const GALGAS_library constinArgument_lib,
                                                     Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  result_result = callExtensionGetter_eqOp ((const cPtr_gtlData *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_lSon.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1186)).ptr (), callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_rSon.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1187)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1186)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlLowerThanExpression eval'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlLowerThanExpression::getter_eval (const GALGAS_gtlContext constinArgument_context,
                                                         const GALGAS_gtlData constinArgument_vars,
                                                         const GALGAS_library constinArgument_lib,
                                                         Compiler * inCompiler
                                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  result_result = callExtensionGetter_ltOp ((const cPtr_gtlData *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_lSon.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1201)).ptr (), callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_rSon.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1202)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1201)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlLowerOrEqualExpression eval'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlLowerOrEqualExpression::getter_eval (const GALGAS_gtlContext constinArgument_context,
                                                            const GALGAS_gtlData constinArgument_vars,
                                                            const GALGAS_library constinArgument_lib,
                                                            Compiler * inCompiler
                                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  result_result = callExtensionGetter_leOp ((const cPtr_gtlData *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_lSon.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1216)).ptr (), callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_rSon.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1217)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1216)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlGreaterThanExpression eval'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlGreaterThanExpression::getter_eval (const GALGAS_gtlContext constinArgument_context,
                                                           const GALGAS_gtlData constinArgument_vars,
                                                           const GALGAS_library constinArgument_lib,
                                                           Compiler * inCompiler
                                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  result_result = callExtensionGetter_gtOp ((const cPtr_gtlData *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_lSon.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1231)).ptr (), callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_rSon.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1232)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1231)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlGreaterOrEqualExpression eval'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlGreaterOrEqualExpression::getter_eval (const GALGAS_gtlContext constinArgument_context,
                                                              const GALGAS_gtlData constinArgument_vars,
                                                              const GALGAS_library constinArgument_lib,
                                                              Compiler * inCompiler
                                                              COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  result_result = callExtensionGetter_geOp ((const cPtr_gtlData *) callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_lSon.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1246)).ptr (), callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_rSon.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1247)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1246)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlGetterCallExpression eval'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlGetterCallExpression::getter_eval (const GALGAS_gtlContext constinArgument_context,
                                                          const GALGAS_gtlData constinArgument_vars,
                                                          const GALGAS_library constinArgument_lib,
                                                          Compiler * inCompiler
                                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  GALGAS_gtlDataList var_dataArguments_38525 = GALGAS_gtlDataList::class_func_emptyList (SOURCE_FILE ("gtl_expressions.galgas", 1265)) ;
  cEnumerator_gtlExpressionList enumerator_38558 (this->mProperty_arguments, kENUMERATION_UP) ;
  while (enumerator_38558.hasCurrentObject ()) {
    var_dataArguments_38525.addAssign_operation (callExtensionGetter_eval ((const cPtr_gtlExpression *) enumerator_38558.current_expression (HERE).ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1267))  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1267)) ;
    enumerator_38558.gotoNextObject () ;
  }
  GALGAS_gtlData var_targetData_38658 = callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_target.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1269)) ;
  result_result = callExtensionGetter_performGetter ((const cPtr_gtlData *) var_targetData_38658.ptr (), this->mProperty_getterName, var_dataArguments_38525, constinArgument_context, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1270)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Routine 'checkArgumentError????'
//
//--------------------------------------------------------------------------------------------------

void routine_checkArgumentError_3F__3F__3F__3F_ (const GALGAS_lstring constinArgument_name,
                                                 const GALGAS_type constinArgument_formalType,
                                                 const GALGAS_gtlData constinArgument_actualArgument,
                                                 const GALGAS_uint constinArgument_argumentNum,
                                                 Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsNotEqual, constinArgument_formalType.objectCompare (callExtensionGetter_embeddedType ((const cPtr_gtlData *) constinArgument_actualArgument.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1280)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (constinArgument_name.readProperty_location (), extensionGetter_typeName (constinArgument_formalType, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1281)).add_operation (GALGAS_string (" expected for argument "), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1281)).add_operation (constinArgument_argumentNum.getter_string (SOURCE_FILE ("gtl_expressions.galgas", 1281)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1281)).add_operation (GALGAS_string (", "), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1282)).add_operation (extensionGetter_typeName (constinArgument_actualArgument.getter_dynamicType (SOURCE_FILE ("gtl_expressions.galgas", 1282)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1282)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1282)).add_operation (GALGAS_string (" provided"), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1282)), fixItArray1  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1281)) ;
    }
  }
}


//--------------------------------------------------------------------------------------------------
//
//Function 'validateReturnValue'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData function_validateReturnValue (const GALGAS_lstring & constinArgument_functionName,
                                             const GALGAS_object & constinArgument_returnedValue,
                                             Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_result ; // Returned variable
  GALGAS_type var_returnedType_39261 = constinArgument_returnedValue.getter_objectDynamicType (SOURCE_FILE ("gtl_expressions.galgas", 1292)) ;
  GALGAS_location var_loc_39326 = constinArgument_functionName.readProperty_location () ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, var_returnedType_39261.objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_bigint))).boolEnum () ;
    if (kBoolTrue == test_0) {
      result_result = GALGAS_gtlInt::class_func_new (var_loc_39326, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1295)), GALGAS_bigint::extractObject (constinArgument_returnedValue, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1295))  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1295)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_2 = kBoolTrue ;
    if (kBoolTrue == test_2) {
      test_2 = GALGAS_bool (kIsEqual, var_returnedType_39261.objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_double))).boolEnum () ;
      if (kBoolTrue == test_2) {
        result_result = GALGAS_gtlFloat::class_func_new (var_loc_39326, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1297)), GALGAS_double::extractObject (constinArgument_returnedValue, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1297))  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1297)) ;
      }
    }
    if (kBoolFalse == test_2) {
      enumGalgasBool test_4 = kBoolTrue ;
      if (kBoolTrue == test_4) {
        test_4 = GALGAS_bool (kIsEqual, var_returnedType_39261.objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_string))).boolEnum () ;
        if (kBoolTrue == test_4) {
          result_result = GALGAS_gtlString::class_func_new (var_loc_39326, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1299)), GALGAS_string::extractObject (constinArgument_returnedValue, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1299))  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1299)) ;
        }
      }
      if (kBoolFalse == test_4) {
        enumGalgasBool test_6 = kBoolTrue ;
        if (kBoolTrue == test_6) {
          test_6 = GALGAS_bool (kIsEqual, var_returnedType_39261.objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_bool))).boolEnum () ;
          if (kBoolTrue == test_6) {
            result_result = GALGAS_gtlBool::class_func_new (var_loc_39326, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1301)), GALGAS_bool::extractObject (constinArgument_returnedValue, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1301))  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1301)) ;
          }
        }
        if (kBoolFalse == test_6) {
          enumGalgasBool test_8 = kBoolTrue ;
          if (kBoolTrue == test_8) {
            test_8 = GALGAS_bool (kIsEqual, var_returnedType_39261.objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_list))).boolEnum () ;
            if (kBoolTrue == test_8) {
              result_result = GALGAS_gtlList::class_func_new (var_loc_39326, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1303)), GALGAS_list::extractObject (constinArgument_returnedValue, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1303))  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1303)) ;
            }
          }
          if (kBoolFalse == test_8) {
            TC_Array <C_FixItDescription> fixItArray10 ;
            inCompiler->emitSemanticError (constinArgument_functionName.readProperty_location (), GALGAS_string ("this function does not return a compatible type"), fixItArray10  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1305)) ;
            result_result.drop () ; // Release error dropped variable
          }
        }
      }
    }
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_validateReturnValue [3] = {
  & kTypeDescriptor_GALGAS_lstring,
  & kTypeDescriptor_GALGAS_object,
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_validateReturnValue (Compiler * inCompiler,
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

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_validateReturnValue ("validateReturnValue",
                                                                     functionWithGenericHeader_validateReturnValue,
                                                                     & kTypeDescriptor_GALGAS_gtlData,
                                                                     2,
                                                                     functionArgs_validateReturnValue) ;

//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFunctionCallExpression eval'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlFunctionCallExpression::getter_eval (const GALGAS_gtlContext constinArgument_context,
                                                            const GALGAS_gtlData constinArgument_vars,
                                                            const GALGAS_library constinArgument_lib,
                                                            Compiler * inCompiler
                                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  GALGAS_uint var_currentErrorCount_40544 = GALGAS_uint::class_func_errorCount (SOURCE_FILE ("gtl_expressions.galgas", 1324)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_function::class_func_isFunctionDefined (this->mProperty_functionName.readProperty_string ()  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1326)).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_objectlist var_arguments_40689 = GALGAS_objectlist::class_func_emptyList (SOURCE_FILE ("gtl_expressions.galgas", 1328)) ;
      GALGAS_gtlDataList var_dataArguments_40729 = GALGAS_gtlDataList::class_func_emptyList (SOURCE_FILE ("gtl_expressions.galgas", 1329)) ;
      cEnumerator_gtlExpressionList enumerator_40765 (this->mProperty_functionArguments, kENUMERATION_UP) ;
      while (enumerator_40765.hasCurrentObject ()) {
        GALGAS_gtlData var_arg_40811 = callExtensionGetter_eval ((const cPtr_gtlExpression *) enumerator_40765.current_expression (HERE).ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1332)) ;
        var_dataArguments_40729.addAssign_operation (var_arg_40811  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1333)) ;
        callExtensionMethod_addMyValue ((cPtr_gtlData *) var_arg_40811.ptr (), var_arguments_40689, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1334)) ;
        enumerator_40765.gotoNextObject () ;
      }
      GALGAS_function var_function_40949 = GALGAS_function::class_func_functionWithName (this->mProperty_functionName.readProperty_string ()  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1337)) ;
      GALGAS_typelist var_formalParameterList_41024 = var_function_40949.getter_formalParameterTypeList (SOURCE_FILE ("gtl_expressions.galgas", 1339)) ;
      enumGalgasBool test_1 = kBoolTrue ;
      if (kBoolTrue == test_1) {
        test_1 = GALGAS_bool (kIsNotEqual, var_formalParameterList_41024.getter_count (SOURCE_FILE ("gtl_expressions.galgas", 1340)).objectCompare (var_arguments_40689.getter_count (SOURCE_FILE ("gtl_expressions.galgas", 1340)))).boolEnum () ;
        if (kBoolTrue == test_1) {
          GALGAS_string temp_2 ;
          const enumGalgasBool test_3 = GALGAS_bool (kIsStrictSup, var_arguments_40689.getter_count (SOURCE_FILE ("gtl_expressions.galgas", 1343)).objectCompare (GALGAS_uint (uint32_t (1U)))).boolEnum () ;
          if (kBoolTrue == test_3) {
            temp_2 = GALGAS_string ("s") ;
          }else if (kBoolFalse == test_3) {
            temp_2 = GALGAS_string::makeEmptyString () ;
          }
          GALGAS_string temp_4 ;
          const enumGalgasBool test_5 = GALGAS_bool (kIsStrictSup, var_formalParameterList_41024.getter_count (SOURCE_FILE ("gtl_expressions.galgas", 1345)).objectCompare (GALGAS_uint (uint32_t (1U)))).boolEnum () ;
          if (kBoolTrue == test_5) {
            temp_4 = GALGAS_string ("s") ;
          }else if (kBoolFalse == test_5) {
            temp_4 = GALGAS_string::makeEmptyString () ;
          }
          TC_Array <C_FixItDescription> fixItArray6 ;
          inCompiler->emitSemanticError (this->mProperty_functionName.readProperty_location (), GALGAS_string ("this function is invoked with ").add_operation (var_arguments_40689.getter_count (SOURCE_FILE ("gtl_expressions.galgas", 1342)).getter_string (SOURCE_FILE ("gtl_expressions.galgas", 1341)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1341)).add_operation (GALGAS_string (" argument"), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1342)).add_operation (temp_2, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1342)).add_operation (GALGAS_string (", but requires "), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1343)).add_operation (var_formalParameterList_41024.getter_count (SOURCE_FILE ("gtl_expressions.galgas", 1344)).getter_string (SOURCE_FILE ("gtl_expressions.galgas", 1344)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1344)).add_operation (GALGAS_string (" argument"), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1344)).add_operation (temp_4, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1344)), fixItArray6  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1341)) ;
          result_result.drop () ; // Release error dropped variable
        }
      }
      if (kBoolFalse == test_1) {
        cEnumerator_typelist enumerator_41480 (var_formalParameterList_41024, kENUMERATION_UP) ;
        cEnumerator_gtlDataList enumerator_41513 (var_dataArguments_40729, kENUMERATION_UP) ;
        GALGAS_uint index_41475 ((uint32_t) 0) ;
        while (enumerator_41480.hasCurrentObject () && enumerator_41513.hasCurrentObject ()) {
          {
          routine_checkArgumentError_3F__3F__3F__3F_ (this->mProperty_functionName, enumerator_41480.current_mValue (HERE), enumerator_41513.current_data (HERE), index_41475, inCompiler  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1349)) ;
          }
          enumerator_41480.gotoNextObject () ;
          enumerator_41513.gotoNextObject () ;
          index_41475.increment_operation (inCompiler  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1348)) ;
        }
        enumGalgasBool test_7 = kBoolTrue ;
        if (kBoolTrue == test_7) {
          test_7 = GALGAS_bool (kIsEqual, var_currentErrorCount_40544.objectCompare (GALGAS_uint::class_func_errorCount (SOURCE_FILE ("gtl_expressions.galgas", 1351)))).boolEnum () ;
          if (kBoolTrue == test_7) {
            GALGAS_object var_returnedValue_41696 = var_function_40949.getter_invoke (var_arguments_40689, this->mProperty_functionName.readProperty_location (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1353)) ;
            result_result = function_validateReturnValue (this->mProperty_functionName, var_returnedValue_41696, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1354)) ;
          }
        }
        if (kBoolFalse == test_7) {
          result_result = GALGAS_gtlUnconstructed::class_func_new (this->mProperty_functionName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1358))  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1356)) ;
        }
      }
    }
  }
  if (kBoolFalse == test_0) {
    GALGAS_gtlFunction var_function_42013 = callExtensionGetter_getFunction ((const cPtr_library *) constinArgument_lib.ptr (), this->mProperty_functionName, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1363)) ;
    GALGAS_gtlDataList var_arguments_42073 = GALGAS_gtlDataList::class_func_emptyList (SOURCE_FILE ("gtl_expressions.galgas", 1364)) ;
    cEnumerator_gtlExpressionList enumerator_42104 (this->mProperty_functionArguments, kENUMERATION_UP) ;
    while (enumerator_42104.hasCurrentObject ()) {
      var_arguments_42073.addAssign_operation (callExtensionGetter_eval ((const cPtr_gtlExpression *) enumerator_42104.current_expression (HERE).ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1366))  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1366)) ;
      enumerator_42104.gotoNextObject () ;
    }
    result_result = callExtensionGetter_call ((const cPtr_gtlFunction *) var_function_42013.ptr (), this->mProperty_functionName.readProperty_location (), constinArgument_context, constinArgument_lib, var_arguments_42073, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1368)) ;
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlExistsExpression eval'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlExistsExpression::getter_eval (const GALGAS_gtlContext constinArgument_context,
                                                      const GALGAS_gtlData constinArgument_vars,
                                                      const GALGAS_library constinArgument_lib,
                                                      Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  result_result = GALGAS_gtlBool::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1386)), extensionGetter_exists (this->mProperty_variable, constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1386))  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1385)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlExistsDefaultExpression eval'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlExistsDefaultExpression::getter_eval (const GALGAS_gtlContext constinArgument_context,
                                                             const GALGAS_gtlData constinArgument_vars,
                                                             const GALGAS_library constinArgument_lib,
                                                             Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = extensionGetter_exists (this->mProperty_variable, constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1404)).boolEnum () ;
    if (kBoolTrue == test_0) {
      result_result = extensionGetter_get (this->mProperty_variable, constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1405)) ;
    }
  }
  if (kBoolFalse == test_0) {
    result_result = callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_defaultValue.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1407)) ;
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlTypeOfExpression eval'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlTypeOfExpression::getter_eval (const GALGAS_gtlContext constinArgument_context,
                                                      const GALGAS_gtlData constinArgument_vars,
                                                      const GALGAS_library constinArgument_lib,
                                                      Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  GALGAS_gtlData var_variableValue_43969 = extensionGetter_get (this->mProperty_variable, constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1424)) ;
  result_result = GALGAS_gtlType::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1425)), var_variableValue_43969.getter_dynamicType (SOURCE_FILE ("gtl_expressions.galgas", 1425))  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1425)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMapOfStructExpression eval'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlMapOfStructExpression::getter_eval (const GALGAS_gtlContext constinArgument_context,
                                                           const GALGAS_gtlData constinArgument_vars,
                                                           const GALGAS_library constinArgument_lib,
                                                           Compiler * inCompiler
                                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  GALGAS_gtlData var_expressionValue_44563 = callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_expression.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1441)) ;
  if (var_expressionValue_44563.isValid ()) {
    if (var_expressionValue_44563.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlStruct) {
      GALGAS_gtlStruct cast_44663_expressionValueStruct ((cPtr_gtlStruct *) var_expressionValue_44563.ptr ()) ;
      result_result = GALGAS_gtlMap::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1446)), cast_44663_expressionValueStruct.readProperty_value ()  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1444)) ;
    }else{
      TC_Array <C_FixItDescription> fixItArray0 ;
      inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("struct expected"), fixItArray0  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1450)) ;
      result_result.drop () ; // Release error dropped variable
    }
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlMapOfListExpression eval'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlMapOfListExpression::getter_eval (const GALGAS_gtlContext constinArgument_context,
                                                         const GALGAS_gtlData constinArgument_vars,
                                                         const GALGAS_library constinArgument_lib,
                                                         Compiler * inCompiler
                                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  GALGAS_gtlData var_expressionValue_45313 = callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_expression.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1467)) ;
  if (var_expressionValue_45313.isValid ()) {
    if (var_expressionValue_45313.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlList) {
      GALGAS_gtlList cast_45411_expressionValueList ((cPtr_gtlList *) var_expressionValue_45313.ptr ()) ;
      GALGAS_gtlVarMap var_resultMap_45447 = GALGAS_gtlVarMap::class_func_emptyMap (SOURCE_FILE ("gtl_expressions.galgas", 1470)) ;
      cEnumerator_list enumerator_45478 (cast_45411_expressionValueList.readProperty_value (), kENUMERATION_UP) ;
      GALGAS_uint index_45473 ((uint32_t) 0) ;
      while (enumerator_45478.hasCurrentObject ()) {
        if (enumerator_45478.current_value (HERE).isValid ()) {
          if (enumerator_45478.current_value (HERE).dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlStruct) {
            GALGAS_gtlStruct cast_45567_itemStruct ((cPtr_gtlStruct *) enumerator_45478.current_value (HERE).ptr ()) ;
            enumGalgasBool test_0 = kBoolTrue ;
            if (kBoolTrue == test_0) {
              test_0 = cast_45567_itemStruct.readProperty_value ().getter_hasKey (this->mProperty_key.readProperty_string () COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1474)).boolEnum () ;
              if (kBoolTrue == test_0) {
                GALGAS_gtlData var_keyValue_45690 ;
                cast_45567_itemStruct.readProperty_value ().method_get (this->mProperty_key, var_keyValue_45690, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1475)) ;
                {
                var_resultMap_45447.setter_put (callExtensionGetter_lstring ((const cPtr_gtlData *) var_keyValue_45690.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1477)), enumerator_45478.current_value (HERE), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1476)) ;
                }
              }
            }
            if (kBoolFalse == test_0) {
              TC_Array <C_FixItDescription> fixItArray1 ;
              inCompiler->emitSemanticError (var_expressionValue_45313.readProperty_where (), GALGAS_string ("item at index ").add_operation (index_45473.getter_string (SOURCE_FILE ("gtl_expressions.galgas", 1481)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1481)).add_operation (GALGAS_string (" does not have field named "), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1481)).add_operation (this->mProperty_key.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1482)), fixItArray1  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1481)) ;
            }
          }else{
            TC_Array <C_FixItDescription> fixItArray2 ;
            inCompiler->emitSemanticError (var_expressionValue_45313.readProperty_where (), GALGAS_string ("list of struct expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1485)) ;
          }
        }
        enumerator_45478.gotoNextObject () ;
        index_45473.increment_operation (inCompiler  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1471)) ;
      }
      result_result = GALGAS_gtlMap::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1488)), var_resultMap_45447  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1488)) ;
    }else{
      TC_Array <C_FixItDescription> fixItArray3 ;
      inCompiler->emitSemanticError (var_expressionValue_45313.readProperty_where (), GALGAS_string ("list expected"), fixItArray3  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1490)) ;
      result_result.drop () ; // Release error dropped variable
    }
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlListOfExpression eval'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlListOfExpression::getter_eval (const GALGAS_gtlContext constinArgument_context,
                                                      const GALGAS_gtlData constinArgument_vars,
                                                      const GALGAS_library constinArgument_lib,
                                                      Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  GALGAS_gtlData var_expressionValue_46606 = callExtensionGetter_eval ((const cPtr_gtlExpression *) this->mProperty_expression.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1507)) ;
  if (var_expressionValue_46606.isValid ()) {
    if (var_expressionValue_46606.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlMap) {
      GALGAS_gtlMap cast_46703_expressionValueMap ((cPtr_gtlMap *) var_expressionValue_46606.ptr ()) ;
      GALGAS_list var_resultList_46733 = GALGAS_list::class_func_emptyList (SOURCE_FILE ("gtl_expressions.galgas", 1510)) ;
      cEnumerator_gtlVarMap enumerator_46777 (cast_46703_expressionValueMap.readProperty_value (), kENUMERATION_UP) ;
      while (enumerator_46777.hasCurrentObject ()) {
        var_resultList_46733.addAssign_operation (enumerator_46777.current_value (HERE)  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1512)) ;
        enumerator_46777.gotoNextObject () ;
      }
      result_result = GALGAS_gtlList::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1514)), var_resultList_46733  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1514)) ;
    }else{
      TC_Array <C_FixItDescription> fixItArray0 ;
      inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("map expected"), fixItArray0  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1516)) ;
      result_result.drop () ; // Release error dropped variable
    }
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlLiteralStructExpression eval'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlLiteralStructExpression::getter_eval (const GALGAS_gtlContext constinArgument_context,
                                                             const GALGAS_gtlData constinArgument_vars,
                                                             const GALGAS_library constinArgument_lib,
                                                             Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  GALGAS_gtlVarMap var_resultStruct_47404 = GALGAS_gtlVarMap::class_func_emptyMap (SOURCE_FILE ("gtl_expressions.galgas", 1533)) ;
  cEnumerator_gtlExpressionMap enumerator_47440 (this->mProperty_value, kENUMERATION_UP) ;
  while (enumerator_47440.hasCurrentObject ()) {
    {
    var_resultStruct_47404.setter_put (enumerator_47440.current_lkey (HERE), callExtensionGetter_eval ((const cPtr_gtlExpression *) enumerator_47440.current_expression (HERE).ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1535)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1535)) ;
    }
    enumerator_47440.gotoNextObject () ;
  }
  result_result = GALGAS_gtlStruct::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1537)), var_resultStruct_47404  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1537)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlLiteralMapExpression eval'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlLiteralMapExpression::getter_eval (const GALGAS_gtlContext constinArgument_context,
                                                          const GALGAS_gtlData constinArgument_vars,
                                                          const GALGAS_library constinArgument_lib,
                                                          Compiler * inCompiler
                                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  GALGAS_gtlVarMap var_resultStruct_48019 = GALGAS_gtlVarMap::class_func_emptyMap (SOURCE_FILE ("gtl_expressions.galgas", 1553)) ;
  cEnumerator_gtlExpressionMap enumerator_48055 (this->mProperty_value, kENUMERATION_UP) ;
  while (enumerator_48055.hasCurrentObject ()) {
    {
    var_resultStruct_48019.setter_put (enumerator_48055.current_lkey (HERE), callExtensionGetter_eval ((const cPtr_gtlExpression *) enumerator_48055.current_expression (HERE).ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1555)), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1555)) ;
    }
    enumerator_48055.gotoNextObject () ;
  }
  result_result = GALGAS_gtlMap::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1557)), var_resultStruct_48019  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1557)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlLiteralListExpression eval'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlLiteralListExpression::getter_eval (const GALGAS_gtlContext constinArgument_context,
                                                           const GALGAS_gtlData constinArgument_vars,
                                                           const GALGAS_library constinArgument_lib,
                                                           Compiler * inCompiler
                                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  GALGAS_list var_resultList_48630 = GALGAS_list::class_func_emptyList (SOURCE_FILE ("gtl_expressions.galgas", 1573)) ;
  cEnumerator_gtlExpressionList enumerator_48661 (this->mProperty_value, kENUMERATION_UP) ;
  while (enumerator_48661.hasCurrentObject ()) {
    var_resultList_48630.addAssign_operation (callExtensionGetter_eval ((const cPtr_gtlExpression *) enumerator_48661.current_expression (HERE).ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1575))  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1575)) ;
    enumerator_48661.gotoNextObject () ;
  }
  result_result = GALGAS_gtlList::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1577)), var_resultList_48630  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1577)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlLiteralSetExpression eval'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlLiteralSetExpression::getter_eval (const GALGAS_gtlContext constinArgument_context,
                                                          const GALGAS_gtlData constinArgument_vars,
                                                          const GALGAS_library constinArgument_lib,
                                                          Compiler * inCompiler
                                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  GALGAS_lstringset var_resultSet_49226 = GALGAS_lstringset::class_func_emptyMap (SOURCE_FILE ("gtl_expressions.galgas", 1593)) ;
  cEnumerator_gtlExpressionList enumerator_49255 (this->mProperty_value, kENUMERATION_UP) ;
  while (enumerator_49255.hasCurrentObject ()) {
    GALGAS_lstring var_itemValue_49290 = callExtensionGetter_lstring ((const cPtr_gtlData *) callExtensionGetter_eval ((const cPtr_gtlExpression *) enumerator_49255.current_expression (HERE).ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1595)).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1595)) ;
    enumGalgasBool test_0 = kBoolTrue ;
    if (kBoolTrue == test_0) {
      test_0 = var_resultSet_49226.getter_hasKey (var_itemValue_49290.readProperty_string () COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1596)).boolEnum () ;
      if (kBoolTrue == test_0) {
        {
        var_resultSet_49226.setter_del (var_itemValue_49290, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1597)) ;
        }
      }
    }
    {
    var_resultSet_49226.setter_put (var_itemValue_49290, inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1599)) ;
    }
    enumerator_49255.gotoNextObject () ;
  }
  result_result = GALGAS_gtlSet::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1601)), var_resultSet_49226  COMMA_SOURCE_FILE ("gtl_expressions.galgas", 1601)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Once function 'noArgument'
//
//--------------------------------------------------------------------------------------------------

static GALGAS_gtlTypedArgumentList onceFunction_noArgument (Compiler *
                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlTypedArgumentList result_result ; // Returned variable
  result_result = GALGAS_gtlTypedArgumentList::class_func_emptyList (SOURCE_FILE ("gtl_data_types.galgas", 85)) ;
//---
  return result_result ;
}



//--------------------------------------------------------------------------------------------------
//  Function implementation                                                                      
//--------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_noArgument = false ;
static GALGAS_gtlTypedArgumentList gOnceFunctionResult_noArgument ;

//--------------------------------------------------------------------------------------------------

GALGAS_gtlTypedArgumentList function_noArgument (class Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_noArgument) {
    gOnceFunctionResult_noArgument = onceFunction_noArgument (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_noArgument = true ;
  }
  return gOnceFunctionResult_noArgument ;
}

//--------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_noArgument (void) {
  gOnceFunctionResult_noArgument.drop () ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gEpilogueForOnceFunction_noArgument (nullptr,
                                                      releaseOnceFunctionResult_noArgument) ;

//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_noArgument [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_noArgument (Compiler * inCompiler,
                                                           const cObjectArray & /* inEffectiveParameterArray */,
                                                           const GALGAS_location & /* inErrorLocation */
                                                           COMMA_LOCATION_ARGS) {
  return function_noArgument (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_noArgument ("noArgument",
                                                            functionWithGenericHeader_noArgument,
                                                            & kTypeDescriptor_GALGAS_gtlTypedArgumentList,
                                                            0,
                                                            functionArgs_noArgument) ;

//--------------------------------------------------------------------------------------------------
//
//Once function 'intArgument'
//
//--------------------------------------------------------------------------------------------------

static GALGAS_gtlTypedArgumentList onceFunction_intArgument (Compiler *
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlTypedArgumentList result_result ; // Returned variable
  result_result = GALGAS_gtlTypedArgumentList::class_func_listWithValue (GALGAS_type (& kTypeDescriptor_GALGAS_gtlInt)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 90)) ;
//---
  return result_result ;
}



//--------------------------------------------------------------------------------------------------
//  Function implementation                                                                      
//--------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_intArgument = false ;
static GALGAS_gtlTypedArgumentList gOnceFunctionResult_intArgument ;

//--------------------------------------------------------------------------------------------------

GALGAS_gtlTypedArgumentList function_intArgument (class Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_intArgument) {
    gOnceFunctionResult_intArgument = onceFunction_intArgument (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_intArgument = true ;
  }
  return gOnceFunctionResult_intArgument ;
}

//--------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_intArgument (void) {
  gOnceFunctionResult_intArgument.drop () ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gEpilogueForOnceFunction_intArgument (nullptr,
                                                       releaseOnceFunctionResult_intArgument) ;

//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_intArgument [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_intArgument (Compiler * inCompiler,
                                                            const cObjectArray & /* inEffectiveParameterArray */,
                                                            const GALGAS_location & /* inErrorLocation */
                                                            COMMA_LOCATION_ARGS) {
  return function_intArgument (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_intArgument ("intArgument",
                                                             functionWithGenericHeader_intArgument,
                                                             & kTypeDescriptor_GALGAS_gtlTypedArgumentList,
                                                             0,
                                                             functionArgs_intArgument) ;

//--------------------------------------------------------------------------------------------------
//
//Once function 'charArgument'
//
//--------------------------------------------------------------------------------------------------

static GALGAS_gtlTypedArgumentList onceFunction_charArgument (Compiler *
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlTypedArgumentList result_result ; // Returned variable
  result_result = GALGAS_gtlTypedArgumentList::class_func_listWithValue (GALGAS_type (& kTypeDescriptor_GALGAS_gtlChar)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 95)) ;
//---
  return result_result ;
}



//--------------------------------------------------------------------------------------------------
//  Function implementation                                                                      
//--------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_charArgument = false ;
static GALGAS_gtlTypedArgumentList gOnceFunctionResult_charArgument ;

//--------------------------------------------------------------------------------------------------

GALGAS_gtlTypedArgumentList function_charArgument (class Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_charArgument) {
    gOnceFunctionResult_charArgument = onceFunction_charArgument (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_charArgument = true ;
  }
  return gOnceFunctionResult_charArgument ;
}

//--------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_charArgument (void) {
  gOnceFunctionResult_charArgument.drop () ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gEpilogueForOnceFunction_charArgument (nullptr,
                                                        releaseOnceFunctionResult_charArgument) ;

//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_charArgument [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_charArgument (Compiler * inCompiler,
                                                             const cObjectArray & /* inEffectiveParameterArray */,
                                                             const GALGAS_location & /* inErrorLocation */
                                                             COMMA_LOCATION_ARGS) {
  return function_charArgument (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_charArgument ("charArgument",
                                                              functionWithGenericHeader_charArgument,
                                                              & kTypeDescriptor_GALGAS_gtlTypedArgumentList,
                                                              0,
                                                              functionArgs_charArgument) ;

//--------------------------------------------------------------------------------------------------
//
//Once function 'charCharArguments'
//
//--------------------------------------------------------------------------------------------------

static GALGAS_gtlTypedArgumentList onceFunction_charCharArguments (Compiler *
                                                                   COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlTypedArgumentList result_result ; // Returned variable
  result_result = GALGAS_gtlTypedArgumentList::class_func_listWithValue (GALGAS_type (& kTypeDescriptor_GALGAS_gtlChar)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 100)) ;
  result_result.addAssign_operation (GALGAS_type (& kTypeDescriptor_GALGAS_gtlChar)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 101)) ;
//---
  return result_result ;
}



//--------------------------------------------------------------------------------------------------
//  Function implementation                                                                      
//--------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_charCharArguments = false ;
static GALGAS_gtlTypedArgumentList gOnceFunctionResult_charCharArguments ;

//--------------------------------------------------------------------------------------------------

GALGAS_gtlTypedArgumentList function_charCharArguments (class Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_charCharArguments) {
    gOnceFunctionResult_charCharArguments = onceFunction_charCharArguments (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_charCharArguments = true ;
  }
  return gOnceFunctionResult_charCharArguments ;
}

//--------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_charCharArguments (void) {
  gOnceFunctionResult_charCharArguments.drop () ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gEpilogueForOnceFunction_charCharArguments (nullptr,
                                                             releaseOnceFunctionResult_charCharArguments) ;

//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_charCharArguments [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_charCharArguments (Compiler * inCompiler,
                                                                  const cObjectArray & /* inEffectiveParameterArray */,
                                                                  const GALGAS_location & /* inErrorLocation */
                                                                  COMMA_LOCATION_ARGS) {
  return function_charCharArguments (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_charCharArguments ("charCharArguments",
                                                                   functionWithGenericHeader_charCharArguments,
                                                                   & kTypeDescriptor_GALGAS_gtlTypedArgumentList,
                                                                   0,
                                                                   functionArgs_charCharArguments) ;

//--------------------------------------------------------------------------------------------------
//
//Once function 'charIntArguments'
//
//--------------------------------------------------------------------------------------------------

static GALGAS_gtlTypedArgumentList onceFunction_charIntArguments (Compiler *
                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlTypedArgumentList result_result ; // Returned variable
  result_result = GALGAS_gtlTypedArgumentList::class_func_listWithValue (GALGAS_type (& kTypeDescriptor_GALGAS_gtlChar)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 106)) ;
  result_result.addAssign_operation (GALGAS_type (& kTypeDescriptor_GALGAS_gtlInt)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 107)) ;
//---
  return result_result ;
}



//--------------------------------------------------------------------------------------------------
//  Function implementation                                                                      
//--------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_charIntArguments = false ;
static GALGAS_gtlTypedArgumentList gOnceFunctionResult_charIntArguments ;

//--------------------------------------------------------------------------------------------------

GALGAS_gtlTypedArgumentList function_charIntArguments (class Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_charIntArguments) {
    gOnceFunctionResult_charIntArguments = onceFunction_charIntArguments (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_charIntArguments = true ;
  }
  return gOnceFunctionResult_charIntArguments ;
}

//--------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_charIntArguments (void) {
  gOnceFunctionResult_charIntArguments.drop () ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gEpilogueForOnceFunction_charIntArguments (nullptr,
                                                            releaseOnceFunctionResult_charIntArguments) ;

//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_charIntArguments [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_charIntArguments (Compiler * inCompiler,
                                                                 const cObjectArray & /* inEffectiveParameterArray */,
                                                                 const GALGAS_location & /* inErrorLocation */
                                                                 COMMA_LOCATION_ARGS) {
  return function_charIntArguments (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_charIntArguments ("charIntArguments",
                                                                  functionWithGenericHeader_charIntArguments,
                                                                  & kTypeDescriptor_GALGAS_gtlTypedArgumentList,
                                                                  0,
                                                                  functionArgs_charIntArguments) ;

//--------------------------------------------------------------------------------------------------
//
//Once function 'floatArgument'
//
//--------------------------------------------------------------------------------------------------

static GALGAS_gtlTypedArgumentList onceFunction_floatArgument (Compiler *
                                                               COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlTypedArgumentList result_result ; // Returned variable
  result_result = GALGAS_gtlTypedArgumentList::class_func_listWithValue (GALGAS_type (& kTypeDescriptor_GALGAS_gtlFloat)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 112)) ;
//---
  return result_result ;
}



//--------------------------------------------------------------------------------------------------
//  Function implementation                                                                      
//--------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_floatArgument = false ;
static GALGAS_gtlTypedArgumentList gOnceFunctionResult_floatArgument ;

//--------------------------------------------------------------------------------------------------

GALGAS_gtlTypedArgumentList function_floatArgument (class Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_floatArgument) {
    gOnceFunctionResult_floatArgument = onceFunction_floatArgument (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_floatArgument = true ;
  }
  return gOnceFunctionResult_floatArgument ;
}

//--------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_floatArgument (void) {
  gOnceFunctionResult_floatArgument.drop () ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gEpilogueForOnceFunction_floatArgument (nullptr,
                                                         releaseOnceFunctionResult_floatArgument) ;

//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_floatArgument [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_floatArgument (Compiler * inCompiler,
                                                              const cObjectArray & /* inEffectiveParameterArray */,
                                                              const GALGAS_location & /* inErrorLocation */
                                                              COMMA_LOCATION_ARGS) {
  return function_floatArgument (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_floatArgument ("floatArgument",
                                                               functionWithGenericHeader_floatArgument,
                                                               & kTypeDescriptor_GALGAS_gtlTypedArgumentList,
                                                               0,
                                                               functionArgs_floatArgument) ;

//--------------------------------------------------------------------------------------------------
//
//Once function 'stringArgument'
//
//--------------------------------------------------------------------------------------------------

static GALGAS_gtlTypedArgumentList onceFunction_stringArgument (Compiler *
                                                                COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlTypedArgumentList result_result ; // Returned variable
  result_result = GALGAS_gtlTypedArgumentList::class_func_listWithValue (GALGAS_type (& kTypeDescriptor_GALGAS_gtlString)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 117)) ;
//---
  return result_result ;
}



//--------------------------------------------------------------------------------------------------
//  Function implementation                                                                      
//--------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_stringArgument = false ;
static GALGAS_gtlTypedArgumentList gOnceFunctionResult_stringArgument ;

//--------------------------------------------------------------------------------------------------

GALGAS_gtlTypedArgumentList function_stringArgument (class Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_stringArgument) {
    gOnceFunctionResult_stringArgument = onceFunction_stringArgument (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_stringArgument = true ;
  }
  return gOnceFunctionResult_stringArgument ;
}

//--------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_stringArgument (void) {
  gOnceFunctionResult_stringArgument.drop () ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gEpilogueForOnceFunction_stringArgument (nullptr,
                                                          releaseOnceFunctionResult_stringArgument) ;

//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_stringArgument [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_stringArgument (Compiler * inCompiler,
                                                               const cObjectArray & /* inEffectiveParameterArray */,
                                                               const GALGAS_location & /* inErrorLocation */
                                                               COMMA_LOCATION_ARGS) {
  return function_stringArgument (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_stringArgument ("stringArgument",
                                                                functionWithGenericHeader_stringArgument,
                                                                & kTypeDescriptor_GALGAS_gtlTypedArgumentList,
                                                                0,
                                                                functionArgs_stringArgument) ;

//--------------------------------------------------------------------------------------------------
//
//Once function 'stringStringArgument'
//
//--------------------------------------------------------------------------------------------------

static GALGAS_gtlTypedArgumentList onceFunction_stringStringArgument (Compiler *
                                                                      COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlTypedArgumentList result_result ; // Returned variable
  result_result = GALGAS_gtlTypedArgumentList::class_func_listWithValue (GALGAS_type (& kTypeDescriptor_GALGAS_gtlString)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 122)) ;
  result_result.addAssign_operation (GALGAS_type (& kTypeDescriptor_GALGAS_gtlString)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 123)) ;
//---
  return result_result ;
}



//--------------------------------------------------------------------------------------------------
//  Function implementation                                                                      
//--------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_stringStringArgument = false ;
static GALGAS_gtlTypedArgumentList gOnceFunctionResult_stringStringArgument ;

//--------------------------------------------------------------------------------------------------

GALGAS_gtlTypedArgumentList function_stringStringArgument (class Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_stringStringArgument) {
    gOnceFunctionResult_stringStringArgument = onceFunction_stringStringArgument (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_stringStringArgument = true ;
  }
  return gOnceFunctionResult_stringStringArgument ;
}

//--------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_stringStringArgument (void) {
  gOnceFunctionResult_stringStringArgument.drop () ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gEpilogueForOnceFunction_stringStringArgument (nullptr,
                                                                releaseOnceFunctionResult_stringStringArgument) ;

//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_stringStringArgument [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_stringStringArgument (Compiler * inCompiler,
                                                                     const cObjectArray & /* inEffectiveParameterArray */,
                                                                     const GALGAS_location & /* inErrorLocation */
                                                                     COMMA_LOCATION_ARGS) {
  return function_stringStringArgument (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_stringStringArgument ("stringStringArgument",
                                                                      functionWithGenericHeader_stringStringArgument,
                                                                      & kTypeDescriptor_GALGAS_gtlTypedArgumentList,
                                                                      0,
                                                                      functionArgs_stringStringArgument) ;

//--------------------------------------------------------------------------------------------------
//
//Once function 'boolIntArguments'
//
//--------------------------------------------------------------------------------------------------

static GALGAS_gtlTypedArgumentList onceFunction_boolIntArguments (Compiler *
                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlTypedArgumentList result_result ; // Returned variable
  result_result = GALGAS_gtlTypedArgumentList::class_func_listWithValue (GALGAS_type (& kTypeDescriptor_GALGAS_gtlBool)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 128)) ;
  result_result.addAssign_operation (GALGAS_type (& kTypeDescriptor_GALGAS_gtlInt)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 129)) ;
//---
  return result_result ;
}



//--------------------------------------------------------------------------------------------------
//  Function implementation                                                                      
//--------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_boolIntArguments = false ;
static GALGAS_gtlTypedArgumentList gOnceFunctionResult_boolIntArguments ;

//--------------------------------------------------------------------------------------------------

GALGAS_gtlTypedArgumentList function_boolIntArguments (class Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_boolIntArguments) {
    gOnceFunctionResult_boolIntArguments = onceFunction_boolIntArguments (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_boolIntArguments = true ;
  }
  return gOnceFunctionResult_boolIntArguments ;
}

//--------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_boolIntArguments (void) {
  gOnceFunctionResult_boolIntArguments.drop () ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gEpilogueForOnceFunction_boolIntArguments (nullptr,
                                                            releaseOnceFunctionResult_boolIntArguments) ;

//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_boolIntArguments [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_boolIntArguments (Compiler * inCompiler,
                                                                 const cObjectArray & /* inEffectiveParameterArray */,
                                                                 const GALGAS_location & /* inErrorLocation */
                                                                 COMMA_LOCATION_ARGS) {
  return function_boolIntArguments (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_boolIntArguments ("boolIntArguments",
                                                                  functionWithGenericHeader_boolIntArguments,
                                                                  & kTypeDescriptor_GALGAS_gtlTypedArgumentList,
                                                                  0,
                                                                  functionArgs_boolIntArguments) ;

//--------------------------------------------------------------------------------------------------
//
//Once function 'intIntArguments'
//
//--------------------------------------------------------------------------------------------------

static GALGAS_gtlTypedArgumentList onceFunction_intIntArguments (Compiler *
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlTypedArgumentList result_result ; // Returned variable
  result_result = GALGAS_gtlTypedArgumentList::class_func_listWithValue (GALGAS_type (& kTypeDescriptor_GALGAS_gtlInt)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 134)) ;
  result_result.addAssign_operation (GALGAS_type (& kTypeDescriptor_GALGAS_gtlInt)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 135)) ;
//---
  return result_result ;
}



//--------------------------------------------------------------------------------------------------
//  Function implementation                                                                      
//--------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_intIntArguments = false ;
static GALGAS_gtlTypedArgumentList gOnceFunctionResult_intIntArguments ;

//--------------------------------------------------------------------------------------------------

GALGAS_gtlTypedArgumentList function_intIntArguments (class Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_intIntArguments) {
    gOnceFunctionResult_intIntArguments = onceFunction_intIntArguments (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_intIntArguments = true ;
  }
  return gOnceFunctionResult_intIntArguments ;
}

//--------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_intIntArguments (void) {
  gOnceFunctionResult_intIntArguments.drop () ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gEpilogueForOnceFunction_intIntArguments (nullptr,
                                                           releaseOnceFunctionResult_intIntArguments) ;

//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_intIntArguments [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_intIntArguments (Compiler * inCompiler,
                                                                const cObjectArray & /* inEffectiveParameterArray */,
                                                                const GALGAS_location & /* inErrorLocation */
                                                                COMMA_LOCATION_ARGS) {
  return function_intIntArguments (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_intIntArguments ("intIntArguments",
                                                                 functionWithGenericHeader_intIntArguments,
                                                                 & kTypeDescriptor_GALGAS_gtlTypedArgumentList,
                                                                 0,
                                                                 functionArgs_intIntArguments) ;

//--------------------------------------------------------------------------------------------------
//
//Once function 'intAnyArguments'
//
//--------------------------------------------------------------------------------------------------

static GALGAS_gtlTypedArgumentList onceFunction_intAnyArguments (Compiler *
                                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlTypedArgumentList result_result ; // Returned variable
  result_result = GALGAS_gtlTypedArgumentList::class_func_listWithValue (GALGAS_type (& kTypeDescriptor_GALGAS_gtlInt)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 140)) ;
  result_result.addAssign_operation (GALGAS_type (& kTypeDescriptor_GALGAS_gtlData)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 141)) ;
//---
  return result_result ;
}



//--------------------------------------------------------------------------------------------------
//  Function implementation                                                                      
//--------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_intAnyArguments = false ;
static GALGAS_gtlTypedArgumentList gOnceFunctionResult_intAnyArguments ;

//--------------------------------------------------------------------------------------------------

GALGAS_gtlTypedArgumentList function_intAnyArguments (class Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_intAnyArguments) {
    gOnceFunctionResult_intAnyArguments = onceFunction_intAnyArguments (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_intAnyArguments = true ;
  }
  return gOnceFunctionResult_intAnyArguments ;
}

//--------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_intAnyArguments (void) {
  gOnceFunctionResult_intAnyArguments.drop () ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gEpilogueForOnceFunction_intAnyArguments (nullptr,
                                                           releaseOnceFunctionResult_intAnyArguments) ;

//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_intAnyArguments [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_intAnyArguments (Compiler * inCompiler,
                                                                const cObjectArray & /* inEffectiveParameterArray */,
                                                                const GALGAS_location & /* inErrorLocation */
                                                                COMMA_LOCATION_ARGS) {
  return function_intAnyArguments (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_intAnyArguments ("intAnyArguments",
                                                                 functionWithGenericHeader_intAnyArguments,
                                                                 & kTypeDescriptor_GALGAS_gtlTypedArgumentList,
                                                                 0,
                                                                 functionArgs_intAnyArguments) ;

//--------------------------------------------------------------------------------------------------
//
//Once function 'anyArgument'
//
//--------------------------------------------------------------------------------------------------

static GALGAS_gtlTypedArgumentList onceFunction_anyArgument (Compiler *
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlTypedArgumentList result_result ; // Returned variable
  result_result = GALGAS_gtlTypedArgumentList::class_func_listWithValue (GALGAS_type (& kTypeDescriptor_GALGAS_gtlData)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 146)) ;
//---
  return result_result ;
}



//--------------------------------------------------------------------------------------------------
//  Function implementation                                                                      
//--------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_anyArgument = false ;
static GALGAS_gtlTypedArgumentList gOnceFunctionResult_anyArgument ;

//--------------------------------------------------------------------------------------------------

GALGAS_gtlTypedArgumentList function_anyArgument (class Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_anyArgument) {
    gOnceFunctionResult_anyArgument = onceFunction_anyArgument (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_anyArgument = true ;
  }
  return gOnceFunctionResult_anyArgument ;
}

//--------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_anyArgument (void) {
  gOnceFunctionResult_anyArgument.drop () ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gEpilogueForOnceFunction_anyArgument (nullptr,
                                                       releaseOnceFunctionResult_anyArgument) ;

//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_anyArgument [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_anyArgument (Compiler * inCompiler,
                                                            const cObjectArray & /* inEffectiveParameterArray */,
                                                            const GALGAS_location & /* inErrorLocation */
                                                            COMMA_LOCATION_ARGS) {
  return function_anyArgument (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_anyArgument ("anyArgument",
                                                             functionWithGenericHeader_anyArgument,
                                                             & kTypeDescriptor_GALGAS_gtlTypedArgumentList,
                                                             0,
                                                             functionArgs_anyArgument) ;

//--------------------------------------------------------------------------------------------------
//
//Once function 'structArgument'
//
//--------------------------------------------------------------------------------------------------

static GALGAS_gtlTypedArgumentList onceFunction_structArgument (Compiler *
                                                                COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlTypedArgumentList result_result ; // Returned variable
  result_result = GALGAS_gtlTypedArgumentList::class_func_listWithValue (GALGAS_type (& kTypeDescriptor_GALGAS_gtlStruct)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 151)) ;
//---
  return result_result ;
}



//--------------------------------------------------------------------------------------------------
//  Function implementation                                                                      
//--------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_structArgument = false ;
static GALGAS_gtlTypedArgumentList gOnceFunctionResult_structArgument ;

//--------------------------------------------------------------------------------------------------

GALGAS_gtlTypedArgumentList function_structArgument (class Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_structArgument) {
    gOnceFunctionResult_structArgument = onceFunction_structArgument (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_structArgument = true ;
  }
  return gOnceFunctionResult_structArgument ;
}

//--------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_structArgument (void) {
  gOnceFunctionResult_structArgument.drop () ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gEpilogueForOnceFunction_structArgument (nullptr,
                                                          releaseOnceFunctionResult_structArgument) ;

//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_structArgument [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_structArgument (Compiler * inCompiler,
                                                               const cObjectArray & /* inEffectiveParameterArray */,
                                                               const GALGAS_location & /* inErrorLocation */
                                                               COMMA_LOCATION_ARGS) {
  return function_structArgument (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_structArgument ("structArgument",
                                                                functionWithGenericHeader_structArgument,
                                                                & kTypeDescriptor_GALGAS_gtlTypedArgumentList,
                                                                0,
                                                                functionArgs_structArgument) ;

//--------------------------------------------------------------------------------------------------
//
//Once function 'expressionArgument'
//
//--------------------------------------------------------------------------------------------------

static GALGAS_gtlTypedArgumentList onceFunction_expressionArgument (Compiler *
                                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlTypedArgumentList result_result ; // Returned variable
  result_result = GALGAS_gtlTypedArgumentList::class_func_listWithValue (GALGAS_type (& kTypeDescriptor_GALGAS_gtlExpr)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 156)) ;
//---
  return result_result ;
}



//--------------------------------------------------------------------------------------------------
//  Function implementation                                                                      
//--------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_expressionArgument = false ;
static GALGAS_gtlTypedArgumentList gOnceFunctionResult_expressionArgument ;

//--------------------------------------------------------------------------------------------------

GALGAS_gtlTypedArgumentList function_expressionArgument (class Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_expressionArgument) {
    gOnceFunctionResult_expressionArgument = onceFunction_expressionArgument (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_expressionArgument = true ;
  }
  return gOnceFunctionResult_expressionArgument ;
}

//--------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_expressionArgument (void) {
  gOnceFunctionResult_expressionArgument.drop () ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gEpilogueForOnceFunction_expressionArgument (nullptr,
                                                              releaseOnceFunctionResult_expressionArgument) ;

//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_expressionArgument [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_expressionArgument (Compiler * inCompiler,
                                                                   const cObjectArray & /* inEffectiveParameterArray */,
                                                                   const GALGAS_location & /* inErrorLocation */
                                                                   COMMA_LOCATION_ARGS) {
  return function_expressionArgument (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_expressionArgument ("expressionArgument",
                                                                    functionWithGenericHeader_expressionArgument,
                                                                    & kTypeDescriptor_GALGAS_gtlTypedArgumentList,
                                                                    0,
                                                                    functionArgs_expressionArgument) ;

//--------------------------------------------------------------------------------------------------
//
//Once function 'setArgument'
//
//--------------------------------------------------------------------------------------------------

static GALGAS_gtlTypedArgumentList onceFunction_setArgument (Compiler *
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlTypedArgumentList result_result ; // Returned variable
  result_result = GALGAS_gtlTypedArgumentList::class_func_listWithValue (GALGAS_type (& kTypeDescriptor_GALGAS_gtlSet)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 161)) ;
//---
  return result_result ;
}



//--------------------------------------------------------------------------------------------------
//  Function implementation                                                                      
//--------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_setArgument = false ;
static GALGAS_gtlTypedArgumentList gOnceFunctionResult_setArgument ;

//--------------------------------------------------------------------------------------------------

GALGAS_gtlTypedArgumentList function_setArgument (class Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_setArgument) {
    gOnceFunctionResult_setArgument = onceFunction_setArgument (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_setArgument = true ;
  }
  return gOnceFunctionResult_setArgument ;
}

//--------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_setArgument (void) {
  gOnceFunctionResult_setArgument.drop () ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gEpilogueForOnceFunction_setArgument (nullptr,
                                                       releaseOnceFunctionResult_setArgument) ;

//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_setArgument [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_setArgument (Compiler * inCompiler,
                                                            const cObjectArray & /* inEffectiveParameterArray */,
                                                            const GALGAS_location & /* inErrorLocation */
                                                            COMMA_LOCATION_ARGS) {
  return function_setArgument (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_setArgument ("setArgument",
                                                             functionWithGenericHeader_setArgument,
                                                             & kTypeDescriptor_GALGAS_gtlTypedArgumentList,
                                                             0,
                                                             functionArgs_setArgument) ;

//--------------------------------------------------------------------------------------------------
//
//Routine 'argumentsCheck???'
//
//--------------------------------------------------------------------------------------------------

void routine_argumentsCheck_3F__3F__3F_ (const GALGAS_lstring constinArgument_methodName,
                                         GALGAS_gtlTypedArgumentList inArgument_abstractArgumentList,
                                         GALGAS_gtlDataList inArgument_concreteArgumentList,
                                         Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_uint var_concreteLength_5034 = inArgument_concreteArgumentList.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 169)) ;
  GALGAS_uint var_abstractLength_5093 = inArgument_abstractArgumentList.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 170)) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsNotEqual, inArgument_abstractArgumentList.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 171)).objectCompare (inArgument_concreteArgumentList.getter_count (SOURCE_FILE ("gtl_data_types.galgas", 171)))).boolEnum () ;
    if (kBoolTrue == test_0) {
      TC_Array <C_FixItDescription> fixItArray1 ;
      inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), constinArgument_methodName.readProperty_string ().add_operation (GALGAS_string (" expects "), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 172)).add_operation (var_abstractLength_5093.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 172)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 172)).add_operation (GALGAS_string (" arguments. "), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 172)).add_operation (var_concreteLength_5034.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 173)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 173)).add_operation (GALGAS_string (" arguments provided."), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 173)), fixItArray1  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 172)) ;
    }
  }
  if (kBoolFalse == test_0) {
    cEnumerator_gtlDataList enumerator_5384 (inArgument_concreteArgumentList, kENUMERATION_UP) ;
    cEnumerator_gtlTypedArgumentList enumerator_5412 (inArgument_abstractArgumentList, kENUMERATION_UP) ;
    GALGAS_uint index_5380 ((uint32_t) 0) ;
    while (enumerator_5384.hasCurrentObject () && enumerator_5412.hasCurrentObject ()) {
      enumGalgasBool test_2 = kBoolTrue ;
      if (kBoolTrue == test_2) {
        test_2 = GALGAS_bool (kIsNotEqual, enumerator_5384.current_data (HERE).getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 176)).objectCompare (enumerator_5412.current_type (HERE))).operator_and (GALGAS_bool (kIsNotEqual, enumerator_5412.current_type (HERE).objectCompare (GALGAS_type (& kTypeDescriptor_GALGAS_gtlData))) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 176)).boolEnum () ;
        if (kBoolTrue == test_2) {
          TC_Array <C_FixItDescription> fixItArray3 ;
          inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) enumerator_5384.current_data (HERE).ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 177)), extensionGetter_typeName (enumerator_5412.current_type (HERE), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 177)).add_operation (GALGAS_string (" expected for argument "), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 177)).add_operation (index_5380.add_operation (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 179)).getter_string (SOURCE_FILE ("gtl_data_types.galgas", 178)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 178)), fixItArray3  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 177)) ;
        }
      }
      enumerator_5384.gotoNextObject () ;
      enumerator_5412.gotoNextObject () ;
      index_5380.increment_operation (inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 175)) ;
    }
  }
}


//--------------------------------------------------------------------------------------------------
//
//Once function 'emptylstring'
//
//--------------------------------------------------------------------------------------------------

static GALGAS_lstring onceFunction_emptylstring (Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring result_result ; // Returned variable
  result_result = GALGAS_lstring::class_func_new (GALGAS_string::makeEmptyString (), GALGAS_location::class_func_nowhere (SOURCE_FILE ("gtl_data_types.galgas", 187)), inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 187)) ;
//---
  return result_result ;
}



//--------------------------------------------------------------------------------------------------
//  Function implementation                                                                      
//--------------------------------------------------------------------------------------------------

static bool gOnceFunctionResultAvailable_emptylstring = false ;
static GALGAS_lstring gOnceFunctionResult_emptylstring ;

//--------------------------------------------------------------------------------------------------

GALGAS_lstring function_emptylstring (class Compiler * inCompiler
              COMMA_LOCATION_ARGS) {
  if (! gOnceFunctionResultAvailable_emptylstring) {
    gOnceFunctionResult_emptylstring = onceFunction_emptylstring (inCompiler COMMA_THERE) ;
    gOnceFunctionResultAvailable_emptylstring = true ;
  }
  return gOnceFunctionResult_emptylstring ;
}

//--------------------------------------------------------------------------------------------------

static void releaseOnceFunctionResult_emptylstring (void) {
  gOnceFunctionResult_emptylstring.drop () ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gEpilogueForOnceFunction_emptylstring (nullptr,
                                                        releaseOnceFunctionResult_emptylstring) ;

//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_emptylstring [1] = {
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_emptylstring (Compiler * inCompiler,
                                                             const cObjectArray & /* inEffectiveParameterArray */,
                                                             const GALGAS_location & /* inErrorLocation */
                                                             COMMA_LOCATION_ARGS) {
  return function_emptylstring (inCompiler COMMA_THERE).getter_object (THERE) ;
}

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_emptylstring ("emptylstring",
                                                              functionWithGenericHeader_emptylstring,
                                                              & kTypeDescriptor_GALGAS_lstring,
                                                              0,
                                                              functionArgs_emptylstring) ;

//--------------------------------------------------------------------------------------------------
//
//Function 'lstring'
//
//--------------------------------------------------------------------------------------------------

GALGAS_lstring function_lstring (GALGAS_string inArgument_string,
                                 Compiler * inCompiler
                                 COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring result_result ; // Returned variable
  result_result = GALGAS_lstring::class_func_new (inArgument_string, GALGAS_location::class_func_nowhere (SOURCE_FILE ("gtl_data_types.galgas", 192)), inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 192)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//  Function introspection                                                                       
//--------------------------------------------------------------------------------------------------

static const C_galgas_type_descriptor * functionArgs_lstring [2] = {
  & kTypeDescriptor_GALGAS_string,
  nullptr
} ;

//--------------------------------------------------------------------------------------------------

static GALGAS_object functionWithGenericHeader_lstring (Compiler * inCompiler,
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

//--------------------------------------------------------------------------------------------------

C_galgas_function_descriptor functionDescriptor_lstring ("lstring",
                                                         functionWithGenericHeader_lstring,
                                                         & kTypeDescriptor_GALGAS_lstring,
                                                         1,
                                                         functionArgs_lstring) ;

//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlUnconstructed desc'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlUnconstructed::getter_desc (const GALGAS_uint constinArgument_tab,
                                                  Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::class_func_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 377)).add_operation (GALGAS_string ("unconstructed\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 377)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlUnconstructed string'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlUnconstructed::getter_string (Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast an unconstructed to a string"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 382)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlUnconstructed lstring'
//
//--------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_gtlUnconstructed::getter_lstring (Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast an unconstructed to a lstring"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 386)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlUnconstructed bool'
//
//--------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_gtlUnconstructed::getter_bool (Compiler * inCompiler
                                                COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast an unconstructed to a bool"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 390)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlUnconstructed int'
//
//--------------------------------------------------------------------------------------------------

GALGAS_bigint cPtr_gtlUnconstructed::getter_int (Compiler * inCompiler
                                                 COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bigint result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast an unconstructed to an int"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 394)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlUnconstructed float'
//
//--------------------------------------------------------------------------------------------------

GALGAS_double cPtr_gtlUnconstructed::getter_float (Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_double result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast an unconstructed to a float"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 398)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlUnconstructed plusOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlUnconstructed::getter_plusOp (Compiler * inCompiler
                                                     COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 402)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlUnconstructed minusOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlUnconstructed::getter_minusOp (Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 405)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlUnconstructed notOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlUnconstructed::getter_notOp (Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 408)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlUnconstructed addOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlUnconstructed::getter_addOp (const GALGAS_gtlData /* constinArgument_right */,
                                                    Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 411)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlUnconstructed subOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlUnconstructed::getter_subOp (const GALGAS_gtlData /* constinArgument_right */,
                                                    Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 414)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlUnconstructed mulOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlUnconstructed::getter_mulOp (const GALGAS_gtlData /* constinArgument_right */,
                                                    Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 417)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlUnconstructed divOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlUnconstructed::getter_divOp (const GALGAS_gtlData /* constinArgument_right */,
                                                    Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 420)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlUnconstructed modOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlUnconstructed::getter_modOp (const GALGAS_gtlData /* constinArgument_right */,
                                                    Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 423)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlUnconstructed andOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlUnconstructed::getter_andOp (const GALGAS_gtlData /* constinArgument_right */,
                                                    Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 426)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlUnconstructed orOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlUnconstructed::getter_orOp (const GALGAS_gtlData /* constinArgument_right */,
                                                   Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 429)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlUnconstructed xorOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlUnconstructed::getter_xorOp (const GALGAS_gtlData /* constinArgument_right */,
                                                    Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 432)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlUnconstructed slOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlUnconstructed::getter_slOp (const GALGAS_gtlData /* constinArgument_right */,
                                                   Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 435)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlUnconstructed srOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlUnconstructed::getter_srOp (const GALGAS_gtlData /* constinArgument_right */,
                                                   Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 438)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlUnconstructed neqOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlUnconstructed::getter_neqOp (const GALGAS_gtlData /* constinArgument_right */,
                                                    Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 441)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlUnconstructed eqOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlUnconstructed::getter_eqOp (const GALGAS_gtlData /* constinArgument_right */,
                                                   Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 444)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlUnconstructed gtOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlUnconstructed::getter_gtOp (const GALGAS_gtlData /* constinArgument_right */,
                                                   Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 447)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlUnconstructed geOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlUnconstructed::getter_geOp (const GALGAS_gtlData /* constinArgument_right */,
                                                   Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 450)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlUnconstructed ltOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlUnconstructed::getter_ltOp (const GALGAS_gtlData /* constinArgument_right */,
                                                   Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 453)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlUnconstructed leOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlUnconstructed::getter_leOp (const GALGAS_gtlData /* constinArgument_right */,
                                                   Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("unconstructed forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 456)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlUnconstructed embeddedType'
//
//--------------------------------------------------------------------------------------------------

GALGAS_type cPtr_gtlUnconstructed::getter_embeddedType (Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_type result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("unconstructed data provided as argument"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 461)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlUnconstructed addMyValue'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlUnconstructed::method_addMyValue (GALGAS_objectlist & /* ioArgument_objectList */,
                                               Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) {
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("Attempting to pass an unconstructed data to a function"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 466)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlUnconstructed performGetter'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlUnconstructed::getter_performGetter (const GALGAS_lstring constinArgument_methodName,
                                                            const GALGAS_gtlDataList constinArgument_arguments,
                                                            const GALGAS_gtlContext constinArgument_context,
                                                            const GALGAS_library constinArgument_lib,
                                                            Compiler * inCompiler
                                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("type").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 480)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 480)) ;
      }
      const GALGAS_gtlUnconstructed temp_1 = this ;
      result_result = GALGAS_gtlType::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 482)), temp_1.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 482))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 481)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_2 = kBoolTrue ;
    if (kBoolTrue == test_2) {
      test_2 = GALGAS_bool (kIsEqual, GALGAS_string ("isANumber").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
      if (kBoolTrue == test_2) {
        {
        routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 485)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 485)) ;
        }
        result_result = GALGAS_gtlBool::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 487)), GALGAS_bool (false)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 486)) ;
      }
    }
    if (kBoolFalse == test_2) {
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = GALGAS_bool (kIsEqual, GALGAS_string ("description").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
        if (kBoolTrue == test_3) {
          {
          routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 490)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 490)) ;
          }
          result_result = GALGAS_gtlString::class_func_new (this->mProperty_meta.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 492)), this->mProperty_meta.readProperty_string ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 491)) ;
        }
      }
      if (kBoolFalse == test_3) {
        enumGalgasBool test_4 = kBoolTrue ;
        if (kBoolTrue == test_4) {
          test_4 = GALGAS_bool (kIsEqual, GALGAS_string ("location").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
          if (kBoolTrue == test_4) {
            {
            routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 495)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 495)) ;
            }
            result_result = GALGAS_gtlString::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 497)), this->mProperty_where.getter_endLocationString (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 497))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 496)) ;
          }
        }
        if (kBoolFalse == test_4) {
          enumGalgasBool test_5 = kBoolTrue ;
          if (kBoolTrue == test_5) {
            test_5 = callExtensionGetter_getterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("unconstructed"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 499)).boolEnum () ;
            if (kBoolTrue == test_5) {
              const GALGAS_gtlUnconstructed temp_6 = this ;
              result_result = callExtensionGetter_callGetter ((const cPtr_gtlGetter *) callExtensionGetter_getGetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("unconstructed"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 500)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, temp_6, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 500)) ;
            }
          }
          if (kBoolFalse == test_5) {
            TC_Array <C_FixItDescription> fixItArray7 ;
            inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown getter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 508)).add_operation (GALGAS_string ("' for unconstructed target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 508)), fixItArray7  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 508)) ;
            result_result.drop () ; // Release error dropped variable
          }
        }
      }
    }
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension setter '@gtlUnconstructed performSetter'
//
//--------------------------------------------------------------------------------------------------

static void extensionSetter_gtlUnconstructed_performSetter (cPtr_gtlData * inObject,
                                                            const GALGAS_lstring constinArgument_methodName,
                                                            const GALGAS_gtlDataList constinArgument_arguments,
                                                            const GALGAS_gtlContext constinArgument_context,
                                                            const GALGAS_library constinArgument_lib,
                                                            Compiler * inCompiler
                                                            COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlUnconstructed * object = (cPtr_gtlUnconstructed *) inObject ;
  macroValidSharedObject (object, cPtr_gtlUnconstructed) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("setDescription").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 522)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 522)) ;
      }
      GALGAS_gtlString temp_1 ;
      if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 523)).isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 523)).ptr ())) {
          temp_1 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 523)).ptr () ;
        }else{
          inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 523)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 523)) ;
        }
      }
      GALGAS_gtlString var_descriptionToSet_16262 = temp_1 ;
      {
      object->setter_setMeta (callExtensionGetter_lstring ((const cPtr_gtlString *) var_descriptionToSet_16262.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 524)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 524)) ;
      }
      object->mProperty_where = constinArgument_methodName.readProperty_location () ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_2 = kBoolTrue ;
    if (kBoolTrue == test_2) {
      test_2 = GALGAS_bool (kIsEqual, GALGAS_string ("touch").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
      if (kBoolTrue == test_2) {
        {
        routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 527)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 527)) ;
        }
        object->mProperty_where = constinArgument_methodName.readProperty_location () ;
      }
    }
    if (kBoolFalse == test_2) {
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = callExtensionGetter_setterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("unconstructed"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 529)).boolEnum () ;
        if (kBoolTrue == test_3) {
          const GALGAS_gtlUnconstructed temp_4 = object ;
          GALGAS_gtlData var_copy_16579 = temp_4 ;
          callExtensionMethod_callSetter ((cPtr_gtlSetter *) callExtensionGetter_getSetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("unconstructed"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 531)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, var_copy_16579, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 531)) ;
          object->mProperty_where = var_copy_16579.readProperty_where () ;
          object->mProperty_meta = var_copy_16579.readProperty_meta () ;
        }
      }
      if (kBoolFalse == test_3) {
        TC_Array <C_FixItDescription> fixItArray5 ;
        inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown setter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 541)).add_operation (GALGAS_string ("' for unconstructed target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 541)), fixItArray5  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 541)) ;
      }
    }
  }
}
//--------------------------------------------------------------------------------------------------

static void defineExtensionSetter_gtlUnconstructed_performSetter (void) {
  enterExtensionSetter_performSetter (kTypeDescriptor_GALGAS_gtlUnconstructed.mSlotID,
                                      extensionSetter_gtlUnconstructed_performSetter) ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gSetter_gtlUnconstructed_performSetter (defineExtensionSetter_gtlUnconstructed_performSetter, nullptr) ;

//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlType desc'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlType::getter_desc (const GALGAS_uint constinArgument_tab,
                                         Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::class_func_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 555)).add_operation (GALGAS_string ("type: "), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 555)).add_operation (extensionGetter_typeName (this->mProperty_type, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 556)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 556)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 556)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlType string'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlType::getter_string (Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = extensionGetter_typeName (this->mProperty_type, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 559)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlType lstring'
//
//--------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_gtlType::getter_lstring (Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result_result ; // Returned variable
  result_result = GALGAS_lstring::class_func_new (extensionGetter_typeName (this->mProperty_type, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 562)), this->mProperty_where, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 562)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlType bool'
//
//--------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_gtlType::getter_bool (Compiler * inCompiler
                                       COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast a type to a bool"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 566)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlType int'
//
//--------------------------------------------------------------------------------------------------

GALGAS_bigint cPtr_gtlType::getter_int (Compiler * inCompiler
                                        COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bigint result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast a type to an int"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 570)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlType float'
//
//--------------------------------------------------------------------------------------------------

GALGAS_double cPtr_gtlType::getter_float (Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_double result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast a type to a float"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 574)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlType plusOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlType::getter_plusOp (Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("type forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 578)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlType minusOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlType::getter_minusOp (Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("type forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 581)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlType notOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlType::getter_notOp (Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("type forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 584)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlType addOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlType::getter_addOp (const GALGAS_gtlData /* constinArgument_right */,
                                           Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("type forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 587)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlType subOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlType::getter_subOp (const GALGAS_gtlData /* constinArgument_right */,
                                           Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("type forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 590)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlType mulOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlType::getter_mulOp (const GALGAS_gtlData /* constinArgument_right */,
                                           Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("type forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 593)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlType divOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlType::getter_divOp (const GALGAS_gtlData /* constinArgument_right */,
                                           Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("type forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 596)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlType modOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlType::getter_modOp (const GALGAS_gtlData /* constinArgument_right */,
                                           Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("type forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 599)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlType andOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlType::getter_andOp (const GALGAS_gtlData /* constinArgument_right */,
                                           Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("type forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 602)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlType orOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlType::getter_orOp (const GALGAS_gtlData /* constinArgument_right */,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("type forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 605)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlType xorOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlType::getter_xorOp (const GALGAS_gtlData /* constinArgument_right */,
                                           Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("type forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 608)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlType slOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlType::getter_slOp (const GALGAS_gtlData /* constinArgument_right */,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("type forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 611)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlType srOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlType::getter_srOp (const GALGAS_gtlData /* constinArgument_right */,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("type forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 614)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlType neqOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlType::getter_neqOp (const GALGAS_gtlData constinArgument_right,
                                           Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlType).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlType temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlType *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlType *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlType", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 618)) ;
        }
      }
      result_result = GALGAS_gtlBool::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 618)), GALGAS_bool (kIsNotEqual, this->mProperty_type.objectCompare (temp_1.readProperty_type ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 618)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("type expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 620)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlType eqOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlType::getter_eqOp (const GALGAS_gtlData constinArgument_right,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlType).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlType temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlType *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlType *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlType", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 625)) ;
        }
      }
      result_result = GALGAS_gtlBool::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 625)), GALGAS_bool (kIsEqual, this->mProperty_type.objectCompare (temp_1.readProperty_type ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 625)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("type expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 627)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlType gtOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlType::getter_gtOp (const GALGAS_gtlData /* constinArgument_right */,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("type forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 631)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlType geOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlType::getter_geOp (const GALGAS_gtlData /* constinArgument_right */,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("type forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 634)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlType ltOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlType::getter_ltOp (const GALGAS_gtlData /* constinArgument_right */,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("type forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 637)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlType leOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlType::getter_leOp (const GALGAS_gtlData /* constinArgument_right */,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("type forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 640)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlType embeddedType'
//
//--------------------------------------------------------------------------------------------------

GALGAS_type cPtr_gtlType::getter_embeddedType (Compiler */* inCompiler */
                                               COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_type result_result ; // Returned variable
  result_result = GALGAS_type (& kTypeDescriptor_GALGAS_type) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlType addMyValue'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlType::method_addMyValue (GALGAS_objectlist & ioArgument_objectList,
                                      Compiler * /* inCompiler */
                                      COMMA_UNUSED_LOCATION_ARGS) {
  ioArgument_objectList.addAssign_operation (this->mProperty_type.getter_object (SOURCE_FILE ("gtl_data_types.galgas", 650))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 650)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlType performGetter'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlType::getter_performGetter (const GALGAS_lstring constinArgument_methodName,
                                                   const GALGAS_gtlDataList constinArgument_arguments,
                                                   const GALGAS_gtlContext constinArgument_context,
                                                   const GALGAS_library constinArgument_lib,
                                                   Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("string").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 664)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 664)) ;
      }
      const GALGAS_gtlType temp_1 = this ;
      result_result = GALGAS_gtlString::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 666)), callExtensionGetter_string ((const cPtr_gtlType *) temp_1.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 666))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 665)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_2 = kBoolTrue ;
    if (kBoolTrue == test_2) {
      test_2 = GALGAS_bool (kIsEqual, GALGAS_string ("type").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
      if (kBoolTrue == test_2) {
        {
        routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 669)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 669)) ;
        }
        const GALGAS_gtlType temp_3 = this ;
        result_result = GALGAS_gtlType::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 671)), temp_3.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 671))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 670)) ;
      }
    }
    if (kBoolFalse == test_2) {
      enumGalgasBool test_4 = kBoolTrue ;
      if (kBoolTrue == test_4) {
        test_4 = GALGAS_bool (kIsEqual, GALGAS_string ("isANumber").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
        if (kBoolTrue == test_4) {
          {
          routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 674)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 674)) ;
          }
          result_result = GALGAS_gtlBool::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 676)), GALGAS_bool (false)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 675)) ;
        }
      }
      if (kBoolFalse == test_4) {
        enumGalgasBool test_5 = kBoolTrue ;
        if (kBoolTrue == test_5) {
          test_5 = GALGAS_bool (kIsEqual, GALGAS_string ("description").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
          if (kBoolTrue == test_5) {
            {
            routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 679)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 679)) ;
            }
            result_result = GALGAS_gtlString::class_func_new (this->mProperty_meta.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 681)), this->mProperty_meta.readProperty_string ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 680)) ;
          }
        }
        if (kBoolFalse == test_5) {
          enumGalgasBool test_6 = kBoolTrue ;
          if (kBoolTrue == test_6) {
            test_6 = GALGAS_bool (kIsEqual, GALGAS_string ("location").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
            if (kBoolTrue == test_6) {
              {
              routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 684)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 684)) ;
              }
              result_result = GALGAS_gtlString::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 686)), this->mProperty_where.getter_endLocationString (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 686))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 685)) ;
            }
          }
          if (kBoolFalse == test_6) {
            enumGalgasBool test_7 = kBoolTrue ;
            if (kBoolTrue == test_7) {
              test_7 = callExtensionGetter_getterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("type"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 688)).boolEnum () ;
              if (kBoolTrue == test_7) {
                const GALGAS_gtlType temp_8 = this ;
                result_result = callExtensionGetter_callGetter ((const cPtr_gtlGetter *) callExtensionGetter_getGetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("type"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 689)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, temp_8, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 689)) ;
              }
            }
            if (kBoolFalse == test_7) {
              TC_Array <C_FixItDescription> fixItArray9 ;
              inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown getter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 697)).add_operation (GALGAS_string ("' for type target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 697)), fixItArray9  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 697)) ;
              result_result.drop () ; // Release error dropped variable
            }
          }
        }
      }
    }
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension setter '@gtlType performSetter'
//
//--------------------------------------------------------------------------------------------------

static void extensionSetter_gtlType_performSetter (cPtr_gtlData * inObject,
                                                   const GALGAS_lstring constinArgument_methodName,
                                                   const GALGAS_gtlDataList constinArgument_arguments,
                                                   const GALGAS_gtlContext constinArgument_context,
                                                   const GALGAS_library constinArgument_lib,
                                                   Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlType * object = (cPtr_gtlType *) inObject ;
  macroValidSharedObject (object, cPtr_gtlType) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("setDescription").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 711)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 711)) ;
      }
      GALGAS_gtlString temp_1 ;
      if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 712)).isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 712)).ptr ())) {
          temp_1 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 712)).ptr () ;
        }else{
          inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 712)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 712)) ;
        }
      }
      GALGAS_gtlString var_descriptionToSet_22615 = temp_1 ;
      {
      object->setter_setMeta (callExtensionGetter_lstring ((const cPtr_gtlString *) var_descriptionToSet_22615.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 713)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 713)) ;
      }
      object->mProperty_where = constinArgument_methodName.readProperty_location () ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_2 = kBoolTrue ;
    if (kBoolTrue == test_2) {
      test_2 = GALGAS_bool (kIsEqual, GALGAS_string ("touch").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
      if (kBoolTrue == test_2) {
        {
        routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 716)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 716)) ;
        }
        object->mProperty_where = constinArgument_methodName.readProperty_location () ;
      }
    }
    if (kBoolFalse == test_2) {
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = callExtensionGetter_setterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("type"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 718)).boolEnum () ;
        if (kBoolTrue == test_3) {
          const GALGAS_gtlType temp_4 = object ;
          GALGAS_gtlData var_copy_22923 = temp_4 ;
          callExtensionMethod_callSetter ((cPtr_gtlSetter *) callExtensionGetter_getSetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("type"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 720)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, var_copy_22923, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 720)) ;
          GALGAS_gtlType temp_5 ;
          if (var_copy_22923.isValid ()) {
            if (nullptr != dynamic_cast <const cPtr_gtlType *> (var_copy_22923.ptr ())) {
              temp_5 = (cPtr_gtlType *) var_copy_22923.ptr () ;
            }else{
              inCompiler->castError ("gtlType", var_copy_22923.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 727)) ;
            }
          }
          object->mProperty_type = temp_5.readProperty_type () ;
          object->mProperty_where = var_copy_22923.readProperty_where () ;
          object->mProperty_meta = var_copy_22923.readProperty_meta () ;
        }
      }
      if (kBoolFalse == test_3) {
        TC_Array <C_FixItDescription> fixItArray6 ;
        inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown setter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 731)).add_operation (GALGAS_string ("' for type target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 731)), fixItArray6  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 731)) ;
      }
    }
  }
}
//--------------------------------------------------------------------------------------------------

static void defineExtensionSetter_gtlType_performSetter (void) {
  enterExtensionSetter_performSetter (kTypeDescriptor_GALGAS_gtlType.mSlotID,
                                      extensionSetter_gtlType_performSetter) ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gSetter_gtlType_performSetter (defineExtensionSetter_gtlType_performSetter, nullptr) ;

//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum desc'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlEnum::getter_desc (const GALGAS_uint constinArgument_tab,
                                         Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::class_func_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 744)).add_operation (GALGAS_string ("enum: "), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 744)).add_operation (this->mProperty_value, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 745)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 745)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum string'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlEnum::getter_string (Compiler */* inCompiler */
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = this->mProperty_value ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum lstring'
//
//--------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_gtlEnum::getter_lstring (Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result_result ; // Returned variable
  result_result = GALGAS_lstring::class_func_new (this->mProperty_value, this->mProperty_where, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 751)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum bool'
//
//--------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_gtlEnum::getter_bool (Compiler * inCompiler
                                       COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast an enum to a bool"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 755)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum int'
//
//--------------------------------------------------------------------------------------------------

GALGAS_bigint cPtr_gtlEnum::getter_int (Compiler * inCompiler
                                        COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bigint result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast an enum to an int"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 759)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum float'
//
//--------------------------------------------------------------------------------------------------

GALGAS_double cPtr_gtlEnum::getter_float (Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_double result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast an enum to a float"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 763)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum plusOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlEnum::getter_plusOp (Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 767)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum minusOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlEnum::getter_minusOp (Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 770)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum notOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlEnum::getter_notOp (Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 773)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum addOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlEnum::getter_addOp (const GALGAS_gtlData /* constinArgument_right */,
                                           Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 776)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum subOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlEnum::getter_subOp (const GALGAS_gtlData /* constinArgument_right */,
                                           Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 779)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum mulOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlEnum::getter_mulOp (const GALGAS_gtlData /* constinArgument_right */,
                                           Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 782)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum divOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlEnum::getter_divOp (const GALGAS_gtlData /* constinArgument_right */,
                                           Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 785)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum modOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlEnum::getter_modOp (const GALGAS_gtlData /* constinArgument_right */,
                                           Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 788)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum andOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlEnum::getter_andOp (const GALGAS_gtlData /* constinArgument_right */,
                                           Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 791)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum orOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlEnum::getter_orOp (const GALGAS_gtlData /* constinArgument_right */,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 794)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum xorOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlEnum::getter_xorOp (const GALGAS_gtlData /* constinArgument_right */,
                                           Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 797)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum slOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlEnum::getter_slOp (const GALGAS_gtlData /* constinArgument_right */,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 800)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum srOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlEnum::getter_srOp (const GALGAS_gtlData /* constinArgument_right */,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 803)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum neqOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlEnum::getter_neqOp (const GALGAS_gtlData constinArgument_right,
                                           Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlEnum).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlEnum temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlEnum *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlEnum *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlEnum", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 810)) ;
        }
      }
      result_result = GALGAS_gtlBool::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 809)), GALGAS_bool (kIsNotEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 807)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("enum expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 813)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum eqOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlEnum::getter_eqOp (const GALGAS_gtlData constinArgument_right,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlEnum).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlEnum temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlEnum *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlEnum *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlEnum", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 821)) ;
        }
      }
      result_result = GALGAS_gtlBool::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 820)), GALGAS_bool (kIsEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 818)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("enum expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 824)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum gtOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlEnum::getter_gtOp (const GALGAS_gtlData /* constinArgument_right */,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 828)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum geOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlEnum::getter_geOp (const GALGAS_gtlData /* constinArgument_right */,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 831)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum ltOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlEnum::getter_ltOp (const GALGAS_gtlData /* constinArgument_right */,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 834)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum leOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlEnum::getter_leOp (const GALGAS_gtlData /* constinArgument_right */,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("enum forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 837)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum embeddedType'
//
//--------------------------------------------------------------------------------------------------

GALGAS_type cPtr_gtlEnum::getter_embeddedType (Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_type result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("enum forbidden as built in function argument"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 842)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlEnum addMyValue'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlEnum::method_addMyValue (GALGAS_objectlist & /* ioArgument_objectList */,
                                      Compiler * inCompiler
                                      COMMA_UNUSED_LOCATION_ARGS) {
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("enum forbidden as built in function argument"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 847)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlEnum performGetter'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlEnum::getter_performGetter (const GALGAS_lstring constinArgument_methodName,
                                                   const GALGAS_gtlDataList constinArgument_arguments,
                                                   const GALGAS_gtlContext constinArgument_context,
                                                   const GALGAS_library constinArgument_lib,
                                                   Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("string").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 861)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 861)) ;
      }
      const GALGAS_gtlEnum temp_1 = this ;
      result_result = GALGAS_gtlString::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 863)), callExtensionGetter_string ((const cPtr_gtlEnum *) temp_1.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 863))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 862)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_2 = kBoolTrue ;
    if (kBoolTrue == test_2) {
      test_2 = GALGAS_bool (kIsEqual, GALGAS_string ("type").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
      if (kBoolTrue == test_2) {
        {
        routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 866)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 866)) ;
        }
        const GALGAS_gtlEnum temp_3 = this ;
        result_result = GALGAS_gtlType::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 868)), temp_3.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 868))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 867)) ;
      }
    }
    if (kBoolFalse == test_2) {
      enumGalgasBool test_4 = kBoolTrue ;
      if (kBoolTrue == test_4) {
        test_4 = GALGAS_bool (kIsEqual, GALGAS_string ("isANumber").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
        if (kBoolTrue == test_4) {
          {
          routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 871)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 871)) ;
          }
          result_result = GALGAS_gtlBool::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 873)), GALGAS_bool (false)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 872)) ;
        }
      }
      if (kBoolFalse == test_4) {
        enumGalgasBool test_5 = kBoolTrue ;
        if (kBoolTrue == test_5) {
          test_5 = GALGAS_bool (kIsEqual, GALGAS_string ("description").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
          if (kBoolTrue == test_5) {
            {
            routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 876)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 876)) ;
            }
            result_result = GALGAS_gtlString::class_func_new (this->mProperty_meta.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 878)), this->mProperty_meta.readProperty_string ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 877)) ;
          }
        }
        if (kBoolFalse == test_5) {
          enumGalgasBool test_6 = kBoolTrue ;
          if (kBoolTrue == test_6) {
            test_6 = callExtensionGetter_getterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("enum"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 880)).boolEnum () ;
            if (kBoolTrue == test_6) {
              const GALGAS_gtlEnum temp_7 = this ;
              result_result = callExtensionGetter_callGetter ((const cPtr_gtlGetter *) callExtensionGetter_getGetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("enum"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 881)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, temp_7, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 881)) ;
            }
          }
          if (kBoolFalse == test_6) {
            enumGalgasBool test_8 = kBoolTrue ;
            if (kBoolTrue == test_8) {
              test_8 = GALGAS_bool (kIsEqual, GALGAS_string ("location").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
              if (kBoolTrue == test_8) {
                {
                routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 889)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 889)) ;
                }
                result_result = GALGAS_gtlString::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 891)), this->mProperty_where.getter_endLocationString (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 891))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 890)) ;
              }
            }
            if (kBoolFalse == test_8) {
              TC_Array <C_FixItDescription> fixItArray9 ;
              inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown getter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 894)).add_operation (GALGAS_string ("' for enum target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 894)), fixItArray9  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 894)) ;
              result_result.drop () ; // Release error dropped variable
            }
          }
        }
      }
    }
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension setter '@gtlEnum performSetter'
//
//--------------------------------------------------------------------------------------------------

static void extensionSetter_gtlEnum_performSetter (cPtr_gtlData * inObject,
                                                   const GALGAS_lstring constinArgument_methodName,
                                                   const GALGAS_gtlDataList constinArgument_arguments,
                                                   const GALGAS_gtlContext constinArgument_context,
                                                   const GALGAS_library constinArgument_lib,
                                                   Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlEnum * object = (cPtr_gtlEnum *) inObject ;
  macroValidSharedObject (object, cPtr_gtlEnum) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("setDescription").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 908)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 908)) ;
      }
      GALGAS_gtlString temp_1 ;
      if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 909)).isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 909)).ptr ())) {
          temp_1 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 909)).ptr () ;
        }else{
          inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 909)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 909)) ;
        }
      }
      GALGAS_gtlString var_descriptionToSet_29098 = temp_1 ;
      {
      object->setter_setMeta (callExtensionGetter_lstring ((const cPtr_gtlString *) var_descriptionToSet_29098.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 910)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 910)) ;
      }
      object->mProperty_where = constinArgument_methodName.readProperty_location () ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_2 = kBoolTrue ;
    if (kBoolTrue == test_2) {
      test_2 = GALGAS_bool (kIsEqual, GALGAS_string ("touch").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
      if (kBoolTrue == test_2) {
        {
        routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 913)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 913)) ;
        }
        object->mProperty_where = constinArgument_methodName.readProperty_location () ;
      }
    }
    if (kBoolFalse == test_2) {
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = callExtensionGetter_setterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("enum"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 915)).boolEnum () ;
        if (kBoolTrue == test_3) {
          const GALGAS_gtlEnum temp_4 = object ;
          GALGAS_gtlData var_copy_29406 = temp_4 ;
          callExtensionMethod_callSetter ((cPtr_gtlSetter *) callExtensionGetter_getSetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("enum"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 917)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, var_copy_29406, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 917)) ;
          GALGAS_gtlEnum temp_5 ;
          if (var_copy_29406.isValid ()) {
            if (nullptr != dynamic_cast <const cPtr_gtlEnum *> (var_copy_29406.ptr ())) {
              temp_5 = (cPtr_gtlEnum *) var_copy_29406.ptr () ;
            }else{
              inCompiler->castError ("gtlEnum", var_copy_29406.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 924)) ;
            }
          }
          object->mProperty_value = temp_5.readProperty_value () ;
          object->mProperty_where = var_copy_29406.readProperty_where () ;
          object->mProperty_meta = var_copy_29406.readProperty_meta () ;
        }
      }
      if (kBoolFalse == test_3) {
        TC_Array <C_FixItDescription> fixItArray6 ;
        inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown setter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 928)).add_operation (GALGAS_string ("' for enum target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 928)), fixItArray6  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 928)) ;
      }
    }
  }
}
//--------------------------------------------------------------------------------------------------

static void defineExtensionSetter_gtlEnum_performSetter (void) {
  enterExtensionSetter_performSetter (kTypeDescriptor_GALGAS_gtlEnum.mSlotID,
                                      extensionSetter_gtlEnum_performSetter) ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gSetter_gtlEnum_performSetter (defineExtensionSetter_gtlEnum_performSetter, nullptr) ;

//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar desc'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlChar::getter_desc (const GALGAS_uint constinArgument_tab,
                                         Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::class_func_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 941)).add_operation (GALGAS_string ("char: "), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 941)).add_operation (this->mProperty_value.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 942)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 942)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 942)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar string'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlChar::getter_string (Compiler */* inCompiler */
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = this->mProperty_value.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 945)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar lstring'
//
//--------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_gtlChar::getter_lstring (Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result_result ; // Returned variable
  result_result = GALGAS_lstring::class_func_new (this->mProperty_value.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 948)), this->mProperty_where, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 948)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar bool'
//
//--------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_gtlChar::getter_bool (Compiler * inCompiler
                                       COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast a char to a bool"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 952)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar int'
//
//--------------------------------------------------------------------------------------------------

GALGAS_bigint cPtr_gtlChar::getter_int (Compiler */* inCompiler */
                                        COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bigint result_result ; // Returned variable
  result_result = this->mProperty_value.getter_uint (SOURCE_FILE ("gtl_data_types.galgas", 956)).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 956)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar float'
//
//--------------------------------------------------------------------------------------------------

GALGAS_double cPtr_gtlChar::getter_float (Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_double result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast a char to a float"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 960)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar plusOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlChar::getter_plusOp (Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("char forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 964)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar minusOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlChar::getter_minusOp (Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("char forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 968)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar notOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlChar::getter_notOp (Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("char forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 972)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar addOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlChar::getter_addOp (const GALGAS_gtlData /* constinArgument_right */,
                                           Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("char forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 976)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar subOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlChar::getter_subOp (const GALGAS_gtlData /* constinArgument_right */,
                                           Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("char forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 980)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar mulOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlChar::getter_mulOp (const GALGAS_gtlData /* constinArgument_right */,
                                           Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("char forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 984)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar divOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlChar::getter_divOp (const GALGAS_gtlData /* constinArgument_right */,
                                           Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("char forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 988)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar modOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlChar::getter_modOp (const GALGAS_gtlData /* constinArgument_right */,
                                           Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("char forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 992)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar andOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlChar::getter_andOp (const GALGAS_gtlData /* constinArgument_right */,
                                           Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("char forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 996)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar orOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlChar::getter_orOp (const GALGAS_gtlData /* constinArgument_right */,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("char forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1000)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar xorOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlChar::getter_xorOp (const GALGAS_gtlData /* constinArgument_right */,
                                           Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("char forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1004)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar slOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlChar::getter_slOp (const GALGAS_gtlData /* constinArgument_right */,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("char forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1008)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar srOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlChar::getter_srOp (const GALGAS_gtlData /* constinArgument_right */,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("char forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1012)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar neqOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlChar::getter_neqOp (const GALGAS_gtlData constinArgument_right,
                                           Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlChar).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlChar temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlChar *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlChar *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlChar", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1020)) ;
        }
      }
      result_result = GALGAS_gtlBool::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1019)), GALGAS_bool (kIsNotEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1017)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) constinArgument_right.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1023)), GALGAS_string ("char expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1023)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar eqOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlChar::getter_eqOp (const GALGAS_gtlData constinArgument_right,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlChar).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlChar temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlChar *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlChar *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlChar", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1032)) ;
        }
      }
      result_result = GALGAS_gtlBool::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1031)), GALGAS_bool (kIsEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1029)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) constinArgument_right.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1035)), GALGAS_string ("char expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1035)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar gtOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlChar::getter_gtOp (const GALGAS_gtlData constinArgument_right,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlChar).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlChar temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlChar *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlChar *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlChar", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1044)) ;
        }
      }
      result_result = GALGAS_gtlBool::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1043)), GALGAS_bool (kIsStrictSup, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1041)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (callExtensionGetter_location ((const cPtr_gtlData *) constinArgument_right.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1047)), GALGAS_string ("char expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1047)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar geOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlChar::getter_geOp (const GALGAS_gtlData constinArgument_right,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlChar).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlChar temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlChar *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlChar *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlChar", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1056)) ;
        }
      }
      result_result = GALGAS_gtlBool::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1055)), GALGAS_bool (kIsSupOrEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1053)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("char expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1059)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar ltOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlChar::getter_ltOp (const GALGAS_gtlData constinArgument_right,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlChar).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlChar temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlChar *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlChar *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlChar", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1068)) ;
        }
      }
      result_result = GALGAS_gtlBool::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1067)), GALGAS_bool (kIsStrictInf, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1065)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1071)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar leOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlChar::getter_leOp (const GALGAS_gtlData constinArgument_right,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlChar).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlChar temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlChar *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlChar *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlChar", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1080)) ;
        }
      }
      result_result = GALGAS_gtlBool::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1079)), GALGAS_bool (kIsInfOrEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1077)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1083)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar embeddedType'
//
//--------------------------------------------------------------------------------------------------

GALGAS_type cPtr_gtlChar::getter_embeddedType (Compiler */* inCompiler */
                                               COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_type result_result ; // Returned variable
  result_result = GALGAS_type (& kTypeDescriptor_GALGAS_char) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlChar addMyValue'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlChar::method_addMyValue (GALGAS_objectlist & ioArgument_objectList,
                                      Compiler * /* inCompiler */
                                      COMMA_UNUSED_LOCATION_ARGS) {
  ioArgument_objectList.addAssign_operation (this->mProperty_value.getter_object (SOURCE_FILE ("gtl_data_types.galgas", 1094))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1094)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlChar performGetter'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlChar::getter_performGetter (const GALGAS_lstring constinArgument_methodName,
                                                   const GALGAS_gtlDataList constinArgument_arguments,
                                                   const GALGAS_gtlContext constinArgument_context,
                                                   const GALGAS_library constinArgument_lib,
                                                   Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("string").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1108)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1108)) ;
      }
      const GALGAS_gtlChar temp_1 = this ;
      result_result = GALGAS_gtlString::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1110)), callExtensionGetter_string ((const cPtr_gtlChar *) temp_1.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1110))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1109)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_2 = kBoolTrue ;
    if (kBoolTrue == test_2) {
      test_2 = GALGAS_bool (kIsEqual, GALGAS_string ("isAlnum").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
      if (kBoolTrue == test_2) {
        {
        routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1113)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1113)) ;
        }
        result_result = GALGAS_gtlBool::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1115)), this->mProperty_value.getter_isalnum (SOURCE_FILE ("gtl_data_types.galgas", 1115))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1114)) ;
      }
    }
    if (kBoolFalse == test_2) {
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = GALGAS_bool (kIsEqual, GALGAS_string ("isCntrl").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
        if (kBoolTrue == test_3) {
          {
          routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1118)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1118)) ;
          }
          result_result = GALGAS_gtlBool::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1120)), this->mProperty_value.getter_iscntrl (SOURCE_FILE ("gtl_data_types.galgas", 1120))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1119)) ;
        }
      }
      if (kBoolFalse == test_3) {
        enumGalgasBool test_4 = kBoolTrue ;
        if (kBoolTrue == test_4) {
          test_4 = GALGAS_bool (kIsEqual, GALGAS_string ("isDigit").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
          if (kBoolTrue == test_4) {
            {
            routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1123)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1123)) ;
            }
            result_result = GALGAS_gtlBool::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1125)), this->mProperty_value.getter_isdigit (SOURCE_FILE ("gtl_data_types.galgas", 1125))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1124)) ;
          }
        }
        if (kBoolFalse == test_4) {
          enumGalgasBool test_5 = kBoolTrue ;
          if (kBoolTrue == test_5) {
            test_5 = GALGAS_bool (kIsEqual, GALGAS_string ("isAlpha").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
            if (kBoolTrue == test_5) {
              {
              routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1128)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1128)) ;
              }
              result_result = GALGAS_gtlBool::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1130)), this->mProperty_value.getter_isalpha (SOURCE_FILE ("gtl_data_types.galgas", 1130))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1129)) ;
            }
          }
          if (kBoolFalse == test_5) {
            enumGalgasBool test_6 = kBoolTrue ;
            if (kBoolTrue == test_6) {
              test_6 = GALGAS_bool (kIsEqual, GALGAS_string ("isLower").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
              if (kBoolTrue == test_6) {
                {
                routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1133)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1133)) ;
                }
                result_result = GALGAS_gtlBool::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1135)), this->mProperty_value.getter_islower (SOURCE_FILE ("gtl_data_types.galgas", 1135))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1134)) ;
              }
            }
            if (kBoolFalse == test_6) {
              enumGalgasBool test_7 = kBoolTrue ;
              if (kBoolTrue == test_7) {
                test_7 = GALGAS_bool (kIsEqual, GALGAS_string ("isUpper").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                if (kBoolTrue == test_7) {
                  {
                  routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1138)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1138)) ;
                  }
                  result_result = GALGAS_gtlBool::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1140)), this->mProperty_value.getter_isupper (SOURCE_FILE ("gtl_data_types.galgas", 1140))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1139)) ;
                }
              }
              if (kBoolFalse == test_7) {
                enumGalgasBool test_8 = kBoolTrue ;
                if (kBoolTrue == test_8) {
                  test_8 = GALGAS_bool (kIsEqual, GALGAS_string ("isXDigit").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                  if (kBoolTrue == test_8) {
                    {
                    routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1143)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1143)) ;
                    }
                    result_result = GALGAS_gtlBool::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1145)), this->mProperty_value.getter_isxdigit (SOURCE_FILE ("gtl_data_types.galgas", 1145))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1144)) ;
                  }
                }
                if (kBoolFalse == test_8) {
                  enumGalgasBool test_9 = kBoolTrue ;
                  if (kBoolTrue == test_9) {
                    test_9 = GALGAS_bool (kIsEqual, GALGAS_string ("type").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                    if (kBoolTrue == test_9) {
                      {
                      routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1148)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1148)) ;
                      }
                      const GALGAS_gtlChar temp_10 = this ;
                      result_result = GALGAS_gtlType::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1150)), temp_10.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 1150))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1149)) ;
                    }
                  }
                  if (kBoolFalse == test_9) {
                    enumGalgasBool test_11 = kBoolTrue ;
                    if (kBoolTrue == test_11) {
                      test_11 = GALGAS_bool (kIsEqual, GALGAS_string ("isANumber").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                      if (kBoolTrue == test_11) {
                        {
                        routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1153)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1153)) ;
                        }
                        result_result = GALGAS_gtlBool::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1155)), GALGAS_bool (false)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1154)) ;
                      }
                    }
                    if (kBoolFalse == test_11) {
                      enumGalgasBool test_12 = kBoolTrue ;
                      if (kBoolTrue == test_12) {
                        test_12 = GALGAS_bool (kIsEqual, GALGAS_string ("description").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                        if (kBoolTrue == test_12) {
                          {
                          routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1158)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1158)) ;
                          }
                          result_result = GALGAS_gtlString::class_func_new (this->mProperty_meta.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1160)), this->mProperty_meta.readProperty_string ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1159)) ;
                        }
                      }
                      if (kBoolFalse == test_12) {
                        enumGalgasBool test_13 = kBoolTrue ;
                        if (kBoolTrue == test_13) {
                          test_13 = callExtensionGetter_getterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("char"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1162)).boolEnum () ;
                          if (kBoolTrue == test_13) {
                            const GALGAS_gtlChar temp_14 = this ;
                            result_result = callExtensionGetter_callGetter ((const cPtr_gtlGetter *) callExtensionGetter_getGetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("char"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1163)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, temp_14, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1163)) ;
                          }
                        }
                        if (kBoolFalse == test_13) {
                          enumGalgasBool test_15 = kBoolTrue ;
                          if (kBoolTrue == test_15) {
                            test_15 = GALGAS_bool (kIsEqual, GALGAS_string ("location").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                            if (kBoolTrue == test_15) {
                              {
                              routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1171)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1171)) ;
                              }
                              result_result = GALGAS_gtlString::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1173)), this->mProperty_where.getter_endLocationString (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1173))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1172)) ;
                            }
                          }
                          if (kBoolFalse == test_15) {
                            TC_Array <C_FixItDescription> fixItArray16 ;
                            inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown getter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1176)).add_operation (GALGAS_string ("' for char target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1176)), fixItArray16  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1176)) ;
                            result_result.drop () ; // Release error dropped variable
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
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension setter '@gtlChar performSetter'
//
//--------------------------------------------------------------------------------------------------

static void extensionSetter_gtlChar_performSetter (cPtr_gtlData * inObject,
                                                   const GALGAS_lstring constinArgument_methodName,
                                                   const GALGAS_gtlDataList constinArgument_arguments,
                                                   const GALGAS_gtlContext constinArgument_context,
                                                   const GALGAS_library constinArgument_lib,
                                                   Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlChar * object = (cPtr_gtlChar *) inObject ;
  macroValidSharedObject (object, cPtr_gtlChar) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("setDescription").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1190)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1190)) ;
      }
      GALGAS_gtlString temp_1 ;
      if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1191)).isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1191)).ptr ())) {
          temp_1 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1191)).ptr () ;
        }else{
          inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1191)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1191)) ;
        }
      }
      GALGAS_gtlString var_descriptionToSet_37564 = temp_1 ;
      {
      object->setter_setMeta (callExtensionGetter_lstring ((const cPtr_gtlString *) var_descriptionToSet_37564.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1192)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1192)) ;
      }
      object->mProperty_where = constinArgument_methodName.readProperty_location () ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_2 = kBoolTrue ;
    if (kBoolTrue == test_2) {
      test_2 = GALGAS_bool (kIsEqual, GALGAS_string ("touch").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
      if (kBoolTrue == test_2) {
        {
        routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1195)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1195)) ;
        }
        object->mProperty_where = constinArgument_methodName.readProperty_location () ;
      }
    }
    if (kBoolFalse == test_2) {
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = callExtensionGetter_setterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("char"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1197)).boolEnum () ;
        if (kBoolTrue == test_3) {
          const GALGAS_gtlChar temp_4 = object ;
          GALGAS_gtlData var_copy_37872 = temp_4 ;
          callExtensionMethod_callSetter ((cPtr_gtlSetter *) callExtensionGetter_getSetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("char"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1199)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, var_copy_37872, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1199)) ;
          GALGAS_gtlChar temp_5 ;
          if (var_copy_37872.isValid ()) {
            if (nullptr != dynamic_cast <const cPtr_gtlChar *> (var_copy_37872.ptr ())) {
              temp_5 = (cPtr_gtlChar *) var_copy_37872.ptr () ;
            }else{
              inCompiler->castError ("gtlChar", var_copy_37872.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1206)) ;
            }
          }
          object->mProperty_value = temp_5.readProperty_value () ;
          object->mProperty_where = var_copy_37872.readProperty_where () ;
          object->mProperty_meta = var_copy_37872.readProperty_meta () ;
        }
      }
      if (kBoolFalse == test_3) {
        TC_Array <C_FixItDescription> fixItArray6 ;
        inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown setter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1210)).add_operation (GALGAS_string ("' for char target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1210)), fixItArray6  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1210)) ;
      }
    }
  }
}
//--------------------------------------------------------------------------------------------------

static void defineExtensionSetter_gtlChar_performSetter (void) {
  enterExtensionSetter_performSetter (kTypeDescriptor_GALGAS_gtlChar.mSlotID,
                                      extensionSetter_gtlChar_performSetter) ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gSetter_gtlChar_performSetter (defineExtensionSetter_gtlChar_performSetter, nullptr) ;

//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt desc'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlInt::getter_desc (const GALGAS_uint constinArgument_tab,
                                        Compiler * inCompiler
                                        COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::class_func_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1223)).add_operation (GALGAS_string ("integer: "), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1223)).add_operation (this->mProperty_value.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1224)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1224)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1224)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt string'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlInt::getter_string (Compiler */* inCompiler */
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = this->mProperty_value.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1227)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt lstring'
//
//--------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_gtlInt::getter_lstring (Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result_result ; // Returned variable
  result_result = GALGAS_lstring::class_func_new (this->mProperty_value.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1230)), this->mProperty_where, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1230)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt bool'
//
//--------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_gtlInt::getter_bool (Compiler * inCompiler
                                      COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast an int to a bool"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1234)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt int'
//
//--------------------------------------------------------------------------------------------------

GALGAS_bigint cPtr_gtlInt::getter_int (Compiler */* inCompiler */
                                       COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bigint result_result ; // Returned variable
  result_result = this->mProperty_value ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt float'
//
//--------------------------------------------------------------------------------------------------

GALGAS_double cPtr_gtlInt::getter_float (Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_double result_result ; // Returned variable
  result_result = this->mProperty_value.getter_sint_36__34_ (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1242)).getter_double (SOURCE_FILE ("gtl_data_types.galgas", 1242)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt plusOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlInt::getter_plusOp (Compiler */* inCompiler */
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  const GALGAS_gtlInt temp_0 = this ;
  result_result = temp_0 ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt minusOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlInt::getter_minusOp (Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  result_result = GALGAS_gtlInt::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1248)), this->mProperty_value.operator_unary_minus (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1248))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1248)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt notOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlInt::getter_notOp (Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  result_result = GALGAS_gtlInt::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1252)), this->mProperty_value.operator_tilde (SOURCE_FILE ("gtl_data_types.galgas", 1252))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1252)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt addOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlInt::getter_addOp (const GALGAS_gtlData constinArgument_right,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlInt temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1260)) ;
        }
      }
      result_result = GALGAS_gtlInt::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1259)), this->mProperty_value.add_operation (temp_1.readProperty_value (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1260))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1257)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("*int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1263)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt subOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlInt::getter_subOp (const GALGAS_gtlData constinArgument_right,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlInt temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1272)) ;
        }
      }
      result_result = GALGAS_gtlInt::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1271)), this->mProperty_value.substract_operation (temp_1.readProperty_value (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1272))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1269)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1275)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt mulOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlInt::getter_mulOp (const GALGAS_gtlData constinArgument_right,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlInt temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1284)) ;
        }
      }
      result_result = GALGAS_gtlInt::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1283)), this->mProperty_value.multiply_operation (temp_1.readProperty_value (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1284))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1281)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1287)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt divOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlInt::getter_divOp (const GALGAS_gtlData constinArgument_right,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlInt temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1296)) ;
        }
      }
      result_result = GALGAS_gtlInt::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1295)), this->mProperty_value.divide_operation (temp_1.readProperty_value (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1296))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1293)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1299)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt modOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlInt::getter_modOp (const GALGAS_gtlData constinArgument_right,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlInt temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1308)) ;
        }
      }
      result_result = GALGAS_gtlInt::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1307)), this->mProperty_value.modulo_operation (temp_1.readProperty_value (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1308))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1305)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1311)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt andOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlInt::getter_andOp (const GALGAS_gtlData constinArgument_right,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlInt temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1320)) ;
        }
      }
      result_result = GALGAS_gtlInt::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1319)), this->mProperty_value.operator_and (temp_1.readProperty_value () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1320))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1317)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1323)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt orOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlInt::getter_orOp (const GALGAS_gtlData constinArgument_right,
                                         Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlInt temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1332)) ;
        }
      }
      result_result = GALGAS_gtlInt::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1331)), this->mProperty_value.operator_or (temp_1.readProperty_value () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1332))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1329)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1335)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt xorOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlInt::getter_xorOp (const GALGAS_gtlData constinArgument_right,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlInt temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1344)) ;
        }
      }
      result_result = GALGAS_gtlInt::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1343)), this->mProperty_value.operator_xor (temp_1.readProperty_value () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1344))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1341)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1347)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt slOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlInt::getter_slOp (const GALGAS_gtlData constinArgument_right,
                                         Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlInt temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1353)) ;
        }
      }
      GALGAS_bigint var_r_41711 = temp_1.readProperty_value () ;
      enumGalgasBool test_2 = kBoolTrue ;
      if (kBoolTrue == test_2) {
        test_2 = GALGAS_bool (kIsSupOrEqual, var_r_41711.objectCompare (GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1354)))).boolEnum () ;
        if (kBoolTrue == test_2) {
          GALGAS_gtlInt temp_3 ;
          if (constinArgument_right.isValid ()) {
            if (nullptr != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
              temp_3 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
            }else{
              inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1358)) ;
            }
          }
          result_result = GALGAS_gtlInt::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1357)), this->mProperty_value.left_shift_operation (temp_3.readProperty_value ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1358)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1358))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1355)) ;
        }
      }
      if (kBoolFalse == test_2) {
        TC_Array <C_FixItDescription> fixItArray4 ;
        inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("positive int expected"), fixItArray4  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1361)) ;
        result_result.drop () ; // Release error dropped variable
      }
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray5 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("int expected"), fixItArray5  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1364)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt srOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlInt::getter_srOp (const GALGAS_gtlData constinArgument_right,
                                         Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlInt temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1370)) ;
        }
      }
      GALGAS_bigint var_r_42147 = temp_1.readProperty_value () ;
      enumGalgasBool test_2 = kBoolTrue ;
      if (kBoolTrue == test_2) {
        test_2 = GALGAS_bool (kIsSupOrEqual, var_r_42147.objectCompare (GALGAS_bigint ("0", inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1371)))).boolEnum () ;
        if (kBoolTrue == test_2) {
          result_result = GALGAS_gtlInt::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1372)), this->mProperty_value.right_shift_operation (var_r_42147.getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1372)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1372))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1372)) ;
        }
      }
      if (kBoolFalse == test_2) {
        TC_Array <C_FixItDescription> fixItArray3 ;
        inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("positive int expected"), fixItArray3  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1374)) ;
        result_result.drop () ; // Release error dropped variable
      }
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray4 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("int expected"), fixItArray4  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1377)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt neqOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlInt::getter_neqOp (const GALGAS_gtlData constinArgument_right,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlInt temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1386)) ;
        }
      }
      result_result = GALGAS_gtlBool::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1385)), GALGAS_bool (kIsNotEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1383)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1389)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt eqOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlInt::getter_eqOp (const GALGAS_gtlData constinArgument_right,
                                         Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlInt temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1398)) ;
        }
      }
      result_result = GALGAS_gtlBool::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1397)), GALGAS_bool (kIsEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1395)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1401)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt gtOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlInt::getter_gtOp (const GALGAS_gtlData constinArgument_right,
                                         Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlInt temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1410)) ;
        }
      }
      result_result = GALGAS_gtlBool::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1409)), GALGAS_bool (kIsStrictSup, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1407)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1413)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt geOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlInt::getter_geOp (const GALGAS_gtlData constinArgument_right,
                                         Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlInt temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1422)) ;
        }
      }
      result_result = GALGAS_gtlBool::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1421)), GALGAS_bool (kIsSupOrEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1419)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1425)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt ltOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlInt::getter_ltOp (const GALGAS_gtlData constinArgument_right,
                                         Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlInt temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1434)) ;
        }
      }
      result_result = GALGAS_gtlBool::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1433)), GALGAS_bool (kIsStrictInf, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1431)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1437)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt leOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlInt::getter_leOp (const GALGAS_gtlData constinArgument_right,
                                         Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlInt).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlInt temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlInt *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlInt *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1446)) ;
        }
      }
      result_result = GALGAS_gtlBool::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1445)), GALGAS_bool (kIsInfOrEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1443)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("int expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1449)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt embeddedType'
//
//--------------------------------------------------------------------------------------------------

GALGAS_type cPtr_gtlInt::getter_embeddedType (Compiler */* inCompiler */
                                              COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_type result_result ; // Returned variable
  result_result = GALGAS_type (& kTypeDescriptor_GALGAS_bigint) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlInt addMyValue'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlInt::method_addMyValue (GALGAS_objectlist & ioArgument_objectList,
                                     Compiler * /* inCompiler */
                                     COMMA_UNUSED_LOCATION_ARGS) {
  ioArgument_objectList.addAssign_operation (this->mProperty_value.getter_object (SOURCE_FILE ("gtl_data_types.galgas", 1460))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1460)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlInt performGetter'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlInt::getter_performGetter (const GALGAS_lstring constinArgument_methodName,
                                                  const GALGAS_gtlDataList constinArgument_arguments,
                                                  const GALGAS_gtlContext constinArgument_context,
                                                  const GALGAS_library constinArgument_lib,
                                                  Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("string").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1474)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1474)) ;
      }
      const GALGAS_gtlInt temp_1 = this ;
      result_result = GALGAS_gtlString::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1476)), callExtensionGetter_string ((const cPtr_gtlInt *) temp_1.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1476))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1475)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_2 = kBoolTrue ;
    if (kBoolTrue == test_2) {
      test_2 = GALGAS_bool (kIsEqual, GALGAS_string ("padded").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
      if (kBoolTrue == test_2) {
        {
        routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_intArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1479)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1479)) ;
        }
        GALGAS_gtlInt temp_3 ;
        if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1480)).isValid ()) {
          if (nullptr != dynamic_cast <const cPtr_gtlInt *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1480)).ptr ())) {
            temp_3 = (cPtr_gtlInt *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1480)).ptr () ;
          }else{
            inCompiler->castError ("gtlInt", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1480)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1480)) ;
          }
        }
        GALGAS_uint var_fieldSize_44961 = temp_3.readProperty_value ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1480)) ;
        const GALGAS_gtlInt temp_4 = this ;
        result_result = GALGAS_gtlString::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1483)), callExtensionGetter_string ((const cPtr_gtlInt *) temp_4.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1484)).getter_stringByLeftAndRightPadding (var_fieldSize_44961, GALGAS_char (TO_UNICODE (32)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1484))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1481)) ;
      }
    }
    if (kBoolFalse == test_2) {
      enumGalgasBool test_5 = kBoolTrue ;
      if (kBoolTrue == test_5) {
        test_5 = GALGAS_bool (kIsEqual, GALGAS_string ("leftPadded").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
        if (kBoolTrue == test_5) {
          {
          routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_intArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1487)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1487)) ;
          }
          GALGAS_gtlInt temp_6 ;
          if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1488)).isValid ()) {
            if (nullptr != dynamic_cast <const cPtr_gtlInt *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1488)).ptr ())) {
              temp_6 = (cPtr_gtlInt *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1488)).ptr () ;
            }else{
              inCompiler->castError ("gtlInt", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1488)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1488)) ;
            }
          }
          GALGAS_uint var_fieldSize_45304 = temp_6.readProperty_value ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1488)) ;
          const GALGAS_gtlInt temp_7 = this ;
          result_result = GALGAS_gtlString::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1491)), callExtensionGetter_string ((const cPtr_gtlInt *) temp_7.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1492)).getter_stringByLeftPadding (var_fieldSize_45304, GALGAS_char (TO_UNICODE (32)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1492))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1489)) ;
        }
      }
      if (kBoolFalse == test_5) {
        enumGalgasBool test_8 = kBoolTrue ;
        if (kBoolTrue == test_8) {
          test_8 = GALGAS_bool (kIsEqual, GALGAS_string ("rightPadded").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
          if (kBoolTrue == test_8) {
            {
            routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_intArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1495)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1495)) ;
            }
            GALGAS_gtlInt temp_9 ;
            if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1496)).isValid ()) {
              if (nullptr != dynamic_cast <const cPtr_gtlInt *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1496)).ptr ())) {
                temp_9 = (cPtr_gtlInt *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1496)).ptr () ;
              }else{
                inCompiler->castError ("gtlInt", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1496)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1496)) ;
              }
            }
            GALGAS_uint var_fieldSize_45641 = temp_9.readProperty_value ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1496)) ;
            const GALGAS_gtlInt temp_10 = this ;
            result_result = GALGAS_gtlString::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1499)), callExtensionGetter_string ((const cPtr_gtlInt *) temp_10.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1500)).getter_stringByRightPadding (var_fieldSize_45641, GALGAS_char (TO_UNICODE (32)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1500))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1497)) ;
          }
        }
        if (kBoolFalse == test_8) {
          enumGalgasBool test_11 = kBoolTrue ;
          if (kBoolTrue == test_11) {
            test_11 = GALGAS_bool (kIsEqual, GALGAS_string ("hexString").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
            if (kBoolTrue == test_11) {
              {
              routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1503)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1503)) ;
              }
              result_result = GALGAS_gtlString::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1505)), this->mProperty_value.getter_hexString (SOURCE_FILE ("gtl_data_types.galgas", 1505))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1504)) ;
            }
          }
          if (kBoolFalse == test_11) {
            enumGalgasBool test_12 = kBoolTrue ;
            if (kBoolTrue == test_12) {
              test_12 = GALGAS_bool (kIsEqual, GALGAS_string ("xString").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
              if (kBoolTrue == test_12) {
                {
                routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1508)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1508)) ;
                }
                result_result = GALGAS_gtlString::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1510)), this->mProperty_value.getter_xString (SOURCE_FILE ("gtl_data_types.galgas", 1510))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1509)) ;
              }
            }
            if (kBoolFalse == test_12) {
              enumGalgasBool test_13 = kBoolTrue ;
              if (kBoolTrue == test_13) {
                test_13 = GALGAS_bool (kIsEqual, GALGAS_string ("numberOfBytes").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                if (kBoolTrue == test_13) {
                  {
                  routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1513)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1513)) ;
                  }
                  result_result = GALGAS_gtlInt::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1516)), this->mProperty_value.getter_bitCountForUnsignedRepresentation (SOURCE_FILE ("gtl_data_types.galgas", 1517)).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 1517)).substract_operation (GALGAS_bigint ("1", inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1517)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1517)).divide_operation (GALGAS_bigint ("8", inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1517)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1517)).add_operation (GALGAS_bigint ("1", inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1517)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1517))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1514)) ;
                }
              }
              if (kBoolFalse == test_13) {
                enumGalgasBool test_14 = kBoolTrue ;
                if (kBoolTrue == test_14) {
                  test_14 = GALGAS_bool (kIsEqual, GALGAS_string ("signedNumberOfBytes").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                  if (kBoolTrue == test_14) {
                    {
                    routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1520)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1520)) ;
                    }
                    result_result = GALGAS_gtlInt::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1523)), this->mProperty_value.getter_bitCountForSignedRepresentation (SOURCE_FILE ("gtl_data_types.galgas", 1524)).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 1524)).substract_operation (GALGAS_bigint ("1", inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1524)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1524)).divide_operation (GALGAS_bigint ("8", inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1524)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1524)).add_operation (GALGAS_bigint ("1", inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1524)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1524))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1521)) ;
                  }
                }
                if (kBoolFalse == test_14) {
                  enumGalgasBool test_15 = kBoolTrue ;
                  if (kBoolTrue == test_15) {
                    test_15 = GALGAS_bool (kIsEqual, GALGAS_string ("numberOfBits").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                    if (kBoolTrue == test_15) {
                      {
                      routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1527)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1527)) ;
                      }
                      result_result = GALGAS_gtlInt::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1530)), this->mProperty_value.getter_bitCountForUnsignedRepresentation (SOURCE_FILE ("gtl_data_types.galgas", 1531)).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 1531))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1528)) ;
                    }
                  }
                  if (kBoolFalse == test_15) {
                    enumGalgasBool test_16 = kBoolTrue ;
                    if (kBoolTrue == test_16) {
                      test_16 = GALGAS_bool (kIsEqual, GALGAS_string ("signedNumberOfBits").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                      if (kBoolTrue == test_16) {
                        {
                        routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1534)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1534)) ;
                        }
                        result_result = GALGAS_gtlInt::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1537)), this->mProperty_value.getter_bitCountForSignedRepresentation (SOURCE_FILE ("gtl_data_types.galgas", 1538)).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 1538))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1535)) ;
                      }
                    }
                    if (kBoolFalse == test_16) {
                      enumGalgasBool test_17 = kBoolTrue ;
                      if (kBoolTrue == test_17) {
                        test_17 = GALGAS_bool (kIsEqual, GALGAS_string ("sign").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                        if (kBoolTrue == test_17) {
                          {
                          routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1541)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1541)) ;
                          }
                          result_result = GALGAS_gtlInt::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1544)), this->mProperty_value.getter_sign (SOURCE_FILE ("gtl_data_types.galgas", 1545)).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 1545))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1542)) ;
                        }
                      }
                      if (kBoolFalse == test_17) {
                        enumGalgasBool test_18 = kBoolTrue ;
                        if (kBoolTrue == test_18) {
                          test_18 = GALGAS_bool (kIsEqual, GALGAS_string ("fitsUnsignedInByte").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                          if (kBoolTrue == test_18) {
                            {
                            routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1548)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1548)) ;
                            }
                            result_result = GALGAS_gtlBool::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1551)), GALGAS_bool (kIsInfOrEqual, this->mProperty_value.getter_bitCountForUnsignedRepresentation (SOURCE_FILE ("gtl_data_types.galgas", 1552)).objectCompare (GALGAS_uint (uint32_t (8U))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1549)) ;
                          }
                        }
                        if (kBoolFalse == test_18) {
                          enumGalgasBool test_19 = kBoolTrue ;
                          if (kBoolTrue == test_19) {
                            test_19 = GALGAS_bool (kIsEqual, GALGAS_string ("fitsSignedInByte").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                            if (kBoolTrue == test_19) {
                              {
                              routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1555)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1555)) ;
                              }
                              result_result = GALGAS_gtlBool::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1558)), GALGAS_bool (kIsInfOrEqual, this->mProperty_value.getter_bitCountForSignedRepresentation (SOURCE_FILE ("gtl_data_types.galgas", 1559)).objectCompare (GALGAS_uint (uint32_t (8U))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1556)) ;
                            }
                          }
                          if (kBoolFalse == test_19) {
                            enumGalgasBool test_20 = kBoolTrue ;
                            if (kBoolTrue == test_20) {
                              test_20 = GALGAS_bool (kIsEqual, GALGAS_string ("fitsUnsignedInShort").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                              if (kBoolTrue == test_20) {
                                {
                                routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1562)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1562)) ;
                                }
                                result_result = GALGAS_gtlBool::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1565)), GALGAS_bool (kIsInfOrEqual, this->mProperty_value.getter_bitCountForUnsignedRepresentation (SOURCE_FILE ("gtl_data_types.galgas", 1566)).objectCompare (GALGAS_uint (uint32_t (16U))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1563)) ;
                              }
                            }
                            if (kBoolFalse == test_20) {
                              enumGalgasBool test_21 = kBoolTrue ;
                              if (kBoolTrue == test_21) {
                                test_21 = GALGAS_bool (kIsEqual, GALGAS_string ("fitsSignedInShort").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                                if (kBoolTrue == test_21) {
                                  {
                                  routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1569)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1569)) ;
                                  }
                                  result_result = GALGAS_gtlBool::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1572)), GALGAS_bool (kIsInfOrEqual, this->mProperty_value.getter_bitCountForSignedRepresentation (SOURCE_FILE ("gtl_data_types.galgas", 1573)).objectCompare (GALGAS_uint (uint32_t (16U))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1570)) ;
                                }
                              }
                              if (kBoolFalse == test_21) {
                                enumGalgasBool test_22 = kBoolTrue ;
                                if (kBoolTrue == test_22) {
                                  test_22 = GALGAS_bool (kIsEqual, GALGAS_string ("fitsUnsignedInLong").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                                  if (kBoolTrue == test_22) {
                                    {
                                    routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1576)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1576)) ;
                                    }
                                    result_result = GALGAS_gtlBool::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1579)), GALGAS_bool (kIsInfOrEqual, this->mProperty_value.getter_bitCountForUnsignedRepresentation (SOURCE_FILE ("gtl_data_types.galgas", 1580)).objectCompare (GALGAS_uint (uint32_t (32U))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1577)) ;
                                  }
                                }
                                if (kBoolFalse == test_22) {
                                  enumGalgasBool test_23 = kBoolTrue ;
                                  if (kBoolTrue == test_23) {
                                    test_23 = GALGAS_bool (kIsEqual, GALGAS_string ("fitsSignedInLong").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                                    if (kBoolTrue == test_23) {
                                      {
                                      routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1583)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1583)) ;
                                      }
                                      result_result = GALGAS_gtlBool::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1586)), GALGAS_bool (kIsInfOrEqual, this->mProperty_value.getter_bitCountForSignedRepresentation (SOURCE_FILE ("gtl_data_types.galgas", 1587)).objectCompare (GALGAS_uint (uint32_t (32U))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1584)) ;
                                    }
                                  }
                                  if (kBoolFalse == test_23) {
                                    enumGalgasBool test_24 = kBoolTrue ;
                                    if (kBoolTrue == test_24) {
                                      test_24 = GALGAS_bool (kIsEqual, GALGAS_string ("fitsUnsignedInLongLong").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                                      if (kBoolTrue == test_24) {
                                        {
                                        routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1590)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1590)) ;
                                        }
                                        result_result = GALGAS_gtlBool::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1593)), GALGAS_bool (kIsInfOrEqual, this->mProperty_value.getter_bitCountForUnsignedRepresentation (SOURCE_FILE ("gtl_data_types.galgas", 1594)).objectCompare (GALGAS_uint (uint32_t (64U))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1591)) ;
                                      }
                                    }
                                    if (kBoolFalse == test_24) {
                                      enumGalgasBool test_25 = kBoolTrue ;
                                      if (kBoolTrue == test_25) {
                                        test_25 = GALGAS_bool (kIsEqual, GALGAS_string ("fitsSignedInLongLong").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                                        if (kBoolTrue == test_25) {
                                          {
                                          routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1597)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1597)) ;
                                          }
                                          result_result = GALGAS_gtlBool::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1600)), GALGAS_bool (kIsInfOrEqual, this->mProperty_value.getter_bitCountForSignedRepresentation (SOURCE_FILE ("gtl_data_types.galgas", 1601)).objectCompare (GALGAS_uint (uint32_t (64U))))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1598)) ;
                                        }
                                      }
                                      if (kBoolFalse == test_25) {
                                        enumGalgasBool test_26 = kBoolTrue ;
                                        if (kBoolTrue == test_26) {
                                          test_26 = GALGAS_bool (kIsEqual, GALGAS_string ("abs").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                                          if (kBoolTrue == test_26) {
                                            {
                                            routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1604)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1604)) ;
                                            }
                                            result_result = GALGAS_gtlInt::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1607)), this->mProperty_value.getter_abs (SOURCE_FILE ("gtl_data_types.galgas", 1608))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1605)) ;
                                          }
                                        }
                                        if (kBoolFalse == test_26) {
                                          enumGalgasBool test_27 = kBoolTrue ;
                                          if (kBoolTrue == test_27) {
                                            test_27 = GALGAS_bool (kIsEqual, GALGAS_string ("bitAtIndex").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                                            if (kBoolTrue == test_27) {
                                              {
                                              routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_intArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1611)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1611)) ;
                                              }
                                              GALGAS_gtlInt temp_28 ;
                                              if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1612)).isValid ()) {
                                                if (nullptr != dynamic_cast <const cPtr_gtlInt *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1612)).ptr ())) {
                                                  temp_28 = (cPtr_gtlInt *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1612)).ptr () ;
                                                }else{
                                                  inCompiler->castError ("gtlInt", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1612)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1612)) ;
                                                }
                                              }
                                              GALGAS_uint var_index_49845 = temp_28.readProperty_value ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1612)) ;
                                              result_result = GALGAS_gtlBool::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1615)), this->mProperty_value.getter_bitAtIndex (var_index_49845 COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1616))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1613)) ;
                                            }
                                          }
                                          if (kBoolFalse == test_27) {
                                            enumGalgasBool test_29 = kBoolTrue ;
                                            if (kBoolTrue == test_29) {
                                              test_29 = GALGAS_bool (kIsEqual, GALGAS_string ("type").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                                              if (kBoolTrue == test_29) {
                                                {
                                                routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1619)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1619)) ;
                                                }
                                                const GALGAS_gtlInt temp_30 = this ;
                                                result_result = GALGAS_gtlType::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1621)), temp_30.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 1621))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1620)) ;
                                              }
                                            }
                                            if (kBoolFalse == test_29) {
                                              enumGalgasBool test_31 = kBoolTrue ;
                                              if (kBoolTrue == test_31) {
                                                test_31 = GALGAS_bool (kIsEqual, GALGAS_string ("isANumber").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                                                if (kBoolTrue == test_31) {
                                                  {
                                                  routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1624)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1624)) ;
                                                  }
                                                  result_result = GALGAS_gtlBool::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1626)), GALGAS_bool (true)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1625)) ;
                                                }
                                              }
                                              if (kBoolFalse == test_31) {
                                                enumGalgasBool test_32 = kBoolTrue ;
                                                if (kBoolTrue == test_32) {
                                                  test_32 = GALGAS_bool (kIsEqual, GALGAS_string ("description").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                                                  if (kBoolTrue == test_32) {
                                                    {
                                                    routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1629)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1629)) ;
                                                    }
                                                    result_result = GALGAS_gtlString::class_func_new (this->mProperty_meta.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1631)), this->mProperty_meta.readProperty_string ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1630)) ;
                                                  }
                                                }
                                                if (kBoolFalse == test_32) {
                                                  enumGalgasBool test_33 = kBoolTrue ;
                                                  if (kBoolTrue == test_33) {
                                                    test_33 = callExtensionGetter_getterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("int"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1633)).boolEnum () ;
                                                    if (kBoolTrue == test_33) {
                                                      const GALGAS_gtlInt temp_34 = this ;
                                                      result_result = callExtensionGetter_callGetter ((const cPtr_gtlGetter *) callExtensionGetter_getGetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("int"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1634)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, temp_34, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1634)) ;
                                                    }
                                                  }
                                                  if (kBoolFalse == test_33) {
                                                    enumGalgasBool test_35 = kBoolTrue ;
                                                    if (kBoolTrue == test_35) {
                                                      test_35 = GALGAS_bool (kIsEqual, GALGAS_string ("location").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                                                      if (kBoolTrue == test_35) {
                                                        {
                                                        routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1642)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1642)) ;
                                                        }
                                                        result_result = GALGAS_gtlString::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1644)), this->mProperty_where.getter_endLocationString (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1644))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1643)) ;
                                                      }
                                                    }
                                                    if (kBoolFalse == test_35) {
                                                      TC_Array <C_FixItDescription> fixItArray36 ;
                                                      inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown getter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1647)).add_operation (GALGAS_string ("' for int target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1647)), fixItArray36  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1647)) ;
                                                      result_result.drop () ; // Release error dropped variable
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
                }
              }
            }
          }
        }
      }
    }
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension setter '@gtlInt performSetter'
//
//--------------------------------------------------------------------------------------------------

static void extensionSetter_gtlInt_performSetter (cPtr_gtlData * inObject,
                                                  const GALGAS_lstring constinArgument_methodName,
                                                  const GALGAS_gtlDataList constinArgument_arguments,
                                                  const GALGAS_gtlContext constinArgument_context,
                                                  const GALGAS_library constinArgument_lib,
                                                  Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlInt * object = (cPtr_gtlInt *) inObject ;
  macroValidSharedObject (object, cPtr_gtlInt) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("setBitAtIndex"))).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_boolIntArguments (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1661)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1661)) ;
      }
      GALGAS_gtlBool temp_1 ;
      if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1662)).isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlBool *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1662)).ptr ())) {
          temp_1 = (cPtr_gtlBool *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1662)).ptr () ;
        }else{
          inCompiler->castError ("gtlBool", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1662)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1662)) ;
        }
      }
      GALGAS_bool var_bit_51557 = temp_1.readProperty_value () ;
      GALGAS_gtlInt temp_2 ;
      if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1663)).isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlInt *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1663)).ptr ())) {
          temp_2 = (cPtr_gtlInt *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1663)).ptr () ;
        }else{
          inCompiler->castError ("gtlInt", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (1U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1663)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1663)) ;
        }
      }
      GALGAS_uint var_index_51624 = temp_2.readProperty_value ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1663)) ;
      {
      object->mProperty_value.setter_setBitAtIndex (var_bit_51557, var_index_51624 COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1664)) ;
      }
      object->mProperty_where = constinArgument_methodName.readProperty_location () ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_3 = kBoolTrue ;
    if (kBoolTrue == test_3) {
      test_3 = GALGAS_bool (kIsEqual, constinArgument_methodName.readProperty_string ().objectCompare (GALGAS_string ("complementBitAtIndex"))).boolEnum () ;
      if (kBoolTrue == test_3) {
        {
        routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_intArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1667)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1667)) ;
        }
        GALGAS_gtlInt temp_4 ;
        if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1668)).isValid ()) {
          if (nullptr != dynamic_cast <const cPtr_gtlInt *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1668)).ptr ())) {
            temp_4 = (cPtr_gtlInt *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1668)).ptr () ;
          }else{
            inCompiler->castError ("gtlInt", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1668)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1668)) ;
          }
        }
        GALGAS_uint var_index_51879 = temp_4.readProperty_value ().getter_uint (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1668)) ;
        {
        object->mProperty_value.setter_complementBitAtIndex (var_index_51879 COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1669)) ;
        }
        object->mProperty_where = constinArgument_methodName.readProperty_location () ;
      }
    }
    if (kBoolFalse == test_3) {
      enumGalgasBool test_5 = kBoolTrue ;
      if (kBoolTrue == test_5) {
        test_5 = GALGAS_bool (kIsEqual, GALGAS_string ("setDescription").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
        if (kBoolTrue == test_5) {
          {
          routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1672)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1672)) ;
          }
          GALGAS_gtlString temp_6 ;
          if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1673)).isValid ()) {
            if (nullptr != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1673)).ptr ())) {
              temp_6 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1673)).ptr () ;
            }else{
              inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1673)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1673)) ;
            }
          }
          GALGAS_gtlString var_descriptionToSet_52129 = temp_6 ;
          {
          object->setter_setMeta (callExtensionGetter_lstring ((const cPtr_gtlString *) var_descriptionToSet_52129.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1674)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1674)) ;
          }
          object->mProperty_where = constinArgument_methodName.readProperty_location () ;
        }
      }
      if (kBoolFalse == test_5) {
        enumGalgasBool test_7 = kBoolTrue ;
        if (kBoolTrue == test_7) {
          test_7 = GALGAS_bool (kIsEqual, GALGAS_string ("touch").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
          if (kBoolTrue == test_7) {
            {
            routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1677)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1677)) ;
            }
            object->mProperty_where = constinArgument_methodName.readProperty_location () ;
          }
        }
        if (kBoolFalse == test_7) {
          enumGalgasBool test_8 = kBoolTrue ;
          if (kBoolTrue == test_8) {
            test_8 = callExtensionGetter_setterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("int"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1679)).boolEnum () ;
            if (kBoolTrue == test_8) {
              const GALGAS_gtlInt temp_9 = object ;
              GALGAS_gtlData var_copy_52436 = temp_9 ;
              callExtensionMethod_callSetter ((cPtr_gtlSetter *) callExtensionGetter_getSetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("int"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1681)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, var_copy_52436, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1681)) ;
              GALGAS_gtlInt temp_10 ;
              if (var_copy_52436.isValid ()) {
                if (nullptr != dynamic_cast <const cPtr_gtlInt *> (var_copy_52436.ptr ())) {
                  temp_10 = (cPtr_gtlInt *) var_copy_52436.ptr () ;
                }else{
                  inCompiler->castError ("gtlInt", var_copy_52436.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1688)) ;
                }
              }
              object->mProperty_value = temp_10.readProperty_value () ;
              object->mProperty_where = var_copy_52436.readProperty_where () ;
              object->mProperty_meta = var_copy_52436.readProperty_meta () ;
            }
          }
          if (kBoolFalse == test_8) {
            TC_Array <C_FixItDescription> fixItArray11 ;
            inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown setter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1692)).add_operation (GALGAS_string ("' for int target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1692)), fixItArray11  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1692)) ;
          }
        }
      }
    }
  }
}
//--------------------------------------------------------------------------------------------------

static void defineExtensionSetter_gtlInt_performSetter (void) {
  enterExtensionSetter_performSetter (kTypeDescriptor_GALGAS_gtlInt.mSlotID,
                                      extensionSetter_gtlInt_performSetter) ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gSetter_gtlInt_performSetter (defineExtensionSetter_gtlInt_performSetter, nullptr) ;

//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat desc'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlFloat::getter_desc (const GALGAS_uint constinArgument_tab,
                                          Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::class_func_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1705)).add_operation (GALGAS_string ("float: "), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1705)).add_operation (this->mProperty_value.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1706)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1706)).add_operation (GALGAS_string ("\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1706)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat string'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlFloat::getter_string (Compiler */* inCompiler */
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = this->mProperty_value.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1709)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat lstring'
//
//--------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_gtlFloat::getter_lstring (Compiler * inCompiler
                                              COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result_result ; // Returned variable
  result_result = GALGAS_lstring::class_func_new (this->mProperty_value.getter_string (SOURCE_FILE ("gtl_data_types.galgas", 1712)), this->mProperty_where, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1712)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat bool'
//
//--------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_gtlFloat::getter_bool (Compiler * inCompiler
                                        COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast a float to a bool"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1716)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat int'
//
//--------------------------------------------------------------------------------------------------

GALGAS_bigint cPtr_gtlFloat::getter_int (Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bigint result_result ; // Returned variable
  result_result = this->mProperty_value.getter_sint_36__34_ (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1720)).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 1720)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat float'
//
//--------------------------------------------------------------------------------------------------

GALGAS_double cPtr_gtlFloat::getter_float (Compiler */* inCompiler */
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_double result_result ; // Returned variable
  result_result = this->mProperty_value ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat plusOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlFloat::getter_plusOp (Compiler */* inCompiler */
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  const GALGAS_gtlFloat temp_0 = this ;
  result_result = temp_0 ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat minusOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlFloat::getter_minusOp (Compiler * inCompiler
                                              COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  result_result = GALGAS_gtlFloat::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1730)), this->mProperty_value.operator_unary_minus (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1730))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1730)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat notOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlFloat::getter_notOp (Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("float forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1734)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat addOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlFloat::getter_addOp (const GALGAS_gtlData constinArgument_right,
                                            Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlFloat).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlFloat temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlFloat *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlFloat *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlFloat", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1742)) ;
        }
      }
      result_result = GALGAS_gtlFloat::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1741)), this->mProperty_value.add_operation (temp_1.readProperty_value (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1742))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1739)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("float expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1745)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat subOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlFloat::getter_subOp (const GALGAS_gtlData constinArgument_right,
                                            Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlFloat).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlFloat temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlFloat *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlFloat *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlFloat", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1754)) ;
        }
      }
      result_result = GALGAS_gtlFloat::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1753)), this->mProperty_value.substract_operation (temp_1.readProperty_value (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1754))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1751)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("float expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1757)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat mulOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlFloat::getter_mulOp (const GALGAS_gtlData constinArgument_right,
                                            Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlFloat).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlFloat temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlFloat *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlFloat *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlFloat", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1766)) ;
        }
      }
      result_result = GALGAS_gtlFloat::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1765)), this->mProperty_value.multiply_operation (temp_1.readProperty_value (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1766))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1763)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("float expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1769)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat divOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlFloat::getter_divOp (const GALGAS_gtlData constinArgument_right,
                                            Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlFloat).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlFloat temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlFloat *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlFloat *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlFloat", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1778)) ;
        }
      }
      result_result = GALGAS_gtlFloat::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1777)), this->mProperty_value.divide_operation (temp_1.readProperty_value (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1778))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1775)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("float expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1781)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat modOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlFloat::getter_modOp (const GALGAS_gtlData /* constinArgument_right */,
                                            Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("float forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1786)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat andOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlFloat::getter_andOp (const GALGAS_gtlData /* constinArgument_right */,
                                            Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("float forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1790)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat orOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlFloat::getter_orOp (const GALGAS_gtlData /* constinArgument_right */,
                                           Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("float forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1794)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat xorOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlFloat::getter_xorOp (const GALGAS_gtlData /* constinArgument_right */,
                                            Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("float forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1798)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat slOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlFloat::getter_slOp (const GALGAS_gtlData /* constinArgument_right */,
                                           Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("float forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1802)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat srOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlFloat::getter_srOp (const GALGAS_gtlData /* constinArgument_right */,
                                           Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("float forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1806)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat neqOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlFloat::getter_neqOp (const GALGAS_gtlData constinArgument_right,
                                            Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlFloat).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlFloat temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlFloat *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlFloat *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlFloat", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1814)) ;
        }
      }
      result_result = GALGAS_gtlBool::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1813)), GALGAS_bool (kIsNotEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1811)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("float expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1817)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat eqOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlFloat::getter_eqOp (const GALGAS_gtlData constinArgument_right,
                                           Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlFloat).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlFloat temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlFloat *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlFloat *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlFloat", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1826)) ;
        }
      }
      result_result = GALGAS_gtlBool::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1825)), GALGAS_bool (kIsEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1823)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("float expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1829)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat gtOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlFloat::getter_gtOp (const GALGAS_gtlData constinArgument_right,
                                           Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlFloat).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlFloat temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlFloat *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlFloat *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlFloat", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1838)) ;
        }
      }
      result_result = GALGAS_gtlBool::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1837)), GALGAS_bool (kIsStrictSup, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1835)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("float expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1841)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat geOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlFloat::getter_geOp (const GALGAS_gtlData constinArgument_right,
                                           Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlFloat).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlFloat temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlFloat *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlFloat *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlFloat", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1850)) ;
        }
      }
      result_result = GALGAS_gtlBool::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1849)), GALGAS_bool (kIsSupOrEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1847)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("float expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1853)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat ltOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlFloat::getter_ltOp (const GALGAS_gtlData constinArgument_right,
                                           Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlFloat).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlFloat temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlFloat *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlFloat *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlFloat", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1862)) ;
        }
      }
      result_result = GALGAS_gtlBool::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1861)), GALGAS_bool (kIsStrictInf, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1859)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("float expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1865)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat leOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlFloat::getter_leOp (const GALGAS_gtlData constinArgument_right,
                                           Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlFloat).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlFloat temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlFloat *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlFloat *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlFloat", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1874)) ;
        }
      }
      result_result = GALGAS_gtlBool::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1873)), GALGAS_bool (kIsInfOrEqual, this->mProperty_value.objectCompare (temp_1.readProperty_value ()))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1871)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("float expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1877)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat embeddedType'
//
//--------------------------------------------------------------------------------------------------

GALGAS_type cPtr_gtlFloat::getter_embeddedType (Compiler */* inCompiler */
                                                COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_type result_result ; // Returned variable
  result_result = GALGAS_type (& kTypeDescriptor_GALGAS_double) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension method '@gtlFloat addMyValue'
//
//--------------------------------------------------------------------------------------------------

void cPtr_gtlFloat::method_addMyValue (GALGAS_objectlist & ioArgument_objectList,
                                       Compiler * /* inCompiler */
                                       COMMA_UNUSED_LOCATION_ARGS) {
  ioArgument_objectList.addAssign_operation (this->mProperty_value.getter_object (SOURCE_FILE ("gtl_data_types.galgas", 1888))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1888)) ;
}
//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlFloat performGetter'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlFloat::getter_performGetter (const GALGAS_lstring constinArgument_methodName,
                                                    const GALGAS_gtlDataList constinArgument_arguments,
                                                    const GALGAS_gtlContext constinArgument_context,
                                                    const GALGAS_library constinArgument_lib,
                                                    Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("string").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1902)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1902)) ;
      }
      const GALGAS_gtlFloat temp_1 = this ;
      result_result = GALGAS_gtlString::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1904)), callExtensionGetter_string ((const cPtr_gtlFloat *) temp_1.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1904))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1903)) ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_2 = kBoolTrue ;
    if (kBoolTrue == test_2) {
      test_2 = GALGAS_bool (kIsEqual, GALGAS_string ("cos").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
      if (kBoolTrue == test_2) {
        {
        routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1907)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1907)) ;
        }
        result_result = GALGAS_gtlFloat::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1909)), this->mProperty_value.getter_cos (SOURCE_FILE ("gtl_data_types.galgas", 1909))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1908)) ;
      }
    }
    if (kBoolFalse == test_2) {
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = GALGAS_bool (kIsEqual, GALGAS_string ("sin").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
        if (kBoolTrue == test_3) {
          {
          routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1912)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1912)) ;
          }
          result_result = GALGAS_gtlFloat::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1914)), this->mProperty_value.getter_sin (SOURCE_FILE ("gtl_data_types.galgas", 1914))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1913)) ;
        }
      }
      if (kBoolFalse == test_3) {
        enumGalgasBool test_4 = kBoolTrue ;
        if (kBoolTrue == test_4) {
          test_4 = GALGAS_bool (kIsEqual, GALGAS_string ("tan").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
          if (kBoolTrue == test_4) {
            {
            routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1917)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1917)) ;
            }
            result_result = GALGAS_gtlFloat::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1919)), this->mProperty_value.getter_tan (SOURCE_FILE ("gtl_data_types.galgas", 1919))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1918)) ;
          }
        }
        if (kBoolFalse == test_4) {
          enumGalgasBool test_5 = kBoolTrue ;
          if (kBoolTrue == test_5) {
            test_5 = GALGAS_bool (kIsEqual, GALGAS_string ("cosDegree").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
            if (kBoolTrue == test_5) {
              {
              routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1922)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1922)) ;
              }
              result_result = GALGAS_gtlFloat::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1924)), this->mProperty_value.getter_cosDegree (SOURCE_FILE ("gtl_data_types.galgas", 1924))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1923)) ;
            }
          }
          if (kBoolFalse == test_5) {
            enumGalgasBool test_6 = kBoolTrue ;
            if (kBoolTrue == test_6) {
              test_6 = GALGAS_bool (kIsEqual, GALGAS_string ("sinDegree").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
              if (kBoolTrue == test_6) {
                {
                routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1927)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1927)) ;
                }
                result_result = GALGAS_gtlFloat::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1929)), this->mProperty_value.getter_sinDegree (SOURCE_FILE ("gtl_data_types.galgas", 1929))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1928)) ;
              }
            }
            if (kBoolFalse == test_6) {
              enumGalgasBool test_7 = kBoolTrue ;
              if (kBoolTrue == test_7) {
                test_7 = GALGAS_bool (kIsEqual, GALGAS_string ("tanDegree").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                if (kBoolTrue == test_7) {
                  {
                  routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1932)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1932)) ;
                  }
                  result_result = GALGAS_gtlFloat::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1934)), this->mProperty_value.getter_tanDegree (SOURCE_FILE ("gtl_data_types.galgas", 1934))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1933)) ;
                }
              }
              if (kBoolFalse == test_7) {
                enumGalgasBool test_8 = kBoolTrue ;
                if (kBoolTrue == test_8) {
                  test_8 = GALGAS_bool (kIsEqual, GALGAS_string ("exp").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                  if (kBoolTrue == test_8) {
                    {
                    routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1937)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1937)) ;
                    }
                    result_result = GALGAS_gtlFloat::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1939)), this->mProperty_value.getter_exp (SOURCE_FILE ("gtl_data_types.galgas", 1939))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1938)) ;
                  }
                }
                if (kBoolFalse == test_8) {
                  enumGalgasBool test_9 = kBoolTrue ;
                  if (kBoolTrue == test_9) {
                    test_9 = GALGAS_bool (kIsEqual, GALGAS_string ("logn").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                    if (kBoolTrue == test_9) {
                      {
                      routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1942)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1942)) ;
                      }
                      result_result = GALGAS_gtlFloat::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1944)), this->mProperty_value.getter_logn (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1944))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1943)) ;
                    }
                  }
                  if (kBoolFalse == test_9) {
                    enumGalgasBool test_10 = kBoolTrue ;
                    if (kBoolTrue == test_10) {
                      test_10 = GALGAS_bool (kIsEqual, GALGAS_string ("log2").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                      if (kBoolTrue == test_10) {
                        {
                        routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1947)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1947)) ;
                        }
                        result_result = GALGAS_gtlFloat::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1949)), this->mProperty_value.getter_log_32_ (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1949))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1948)) ;
                      }
                    }
                    if (kBoolFalse == test_10) {
                      enumGalgasBool test_11 = kBoolTrue ;
                      if (kBoolTrue == test_11) {
                        test_11 = GALGAS_bool (kIsEqual, GALGAS_string ("log10").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                        if (kBoolTrue == test_11) {
                          {
                          routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1952)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1952)) ;
                          }
                          result_result = GALGAS_gtlFloat::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1954)), this->mProperty_value.getter_log_31__30_ (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1954))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1953)) ;
                        }
                      }
                      if (kBoolFalse == test_11) {
                        enumGalgasBool test_12 = kBoolTrue ;
                        if (kBoolTrue == test_12) {
                          test_12 = GALGAS_bool (kIsEqual, GALGAS_string ("sqrt").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                          if (kBoolTrue == test_12) {
                            {
                            routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1957)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1957)) ;
                            }
                            result_result = GALGAS_gtlFloat::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1959)), this->mProperty_value.getter_sqrt (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1959))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1958)) ;
                          }
                        }
                        if (kBoolFalse == test_12) {
                          enumGalgasBool test_13 = kBoolTrue ;
                          if (kBoolTrue == test_13) {
                            test_13 = GALGAS_bool (kIsEqual, GALGAS_string ("power").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                            if (kBoolTrue == test_13) {
                              {
                              routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_floatArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1962)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1962)) ;
                              }
                              GALGAS_gtlFloat temp_14 ;
                              if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1963)).isValid ()) {
                                if (nullptr != dynamic_cast <const cPtr_gtlFloat *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1963)).ptr ())) {
                                  temp_14 = (cPtr_gtlFloat *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1963)).ptr () ;
                                }else{
                                  inCompiler->castError ("gtlFloat", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1963)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1963)) ;
                                }
                              }
                              GALGAS_double var_power_60685 = temp_14.readProperty_value () ;
                              result_result = GALGAS_gtlFloat::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1965)), this->mProperty_value.getter_power (var_power_60685, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1965))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1964)) ;
                            }
                          }
                          if (kBoolFalse == test_13) {
                            enumGalgasBool test_15 = kBoolTrue ;
                            if (kBoolTrue == test_15) {
                              test_15 = GALGAS_bool (kIsEqual, GALGAS_string ("type").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                              if (kBoolTrue == test_15) {
                                {
                                routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1968)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1968)) ;
                                }
                                const GALGAS_gtlFloat temp_16 = this ;
                                result_result = GALGAS_gtlType::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1970)), temp_16.getter_dynamicType (SOURCE_FILE ("gtl_data_types.galgas", 1970))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1969)) ;
                              }
                            }
                            if (kBoolFalse == test_15) {
                              enumGalgasBool test_17 = kBoolTrue ;
                              if (kBoolTrue == test_17) {
                                test_17 = GALGAS_bool (kIsEqual, GALGAS_string ("isANumber").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                                if (kBoolTrue == test_17) {
                                  {
                                  routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1973)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1973)) ;
                                  }
                                  result_result = GALGAS_gtlBool::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1975)), GALGAS_bool (true)  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1974)) ;
                                }
                              }
                              if (kBoolFalse == test_17) {
                                enumGalgasBool test_18 = kBoolTrue ;
                                if (kBoolTrue == test_18) {
                                  test_18 = GALGAS_bool (kIsEqual, GALGAS_string ("int").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                                  if (kBoolTrue == test_18) {
                                    {
                                    routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1978)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1978)) ;
                                    }
                                    result_result = GALGAS_gtlInt::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1980)), this->mProperty_value.getter_sint_36__34_ (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1980)).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 1980))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1979)) ;
                                  }
                                }
                                if (kBoolFalse == test_18) {
                                  enumGalgasBool test_19 = kBoolTrue ;
                                  if (kBoolTrue == test_19) {
                                    test_19 = GALGAS_bool (kIsEqual, GALGAS_string ("description").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                                    if (kBoolTrue == test_19) {
                                      {
                                      routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1983)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1983)) ;
                                      }
                                      result_result = GALGAS_gtlString::class_func_new (this->mProperty_meta.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1985)), this->mProperty_meta.readProperty_string ()  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1984)) ;
                                    }
                                  }
                                  if (kBoolFalse == test_19) {
                                    enumGalgasBool test_20 = kBoolTrue ;
                                    if (kBoolTrue == test_20) {
                                      test_20 = callExtensionGetter_getterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("float"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1987)).boolEnum () ;
                                      if (kBoolTrue == test_20) {
                                        const GALGAS_gtlFloat temp_21 = this ;
                                        result_result = callExtensionGetter_callGetter ((const cPtr_gtlGetter *) callExtensionGetter_getGetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("float"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1988)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, temp_21, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1988)) ;
                                      }
                                    }
                                    if (kBoolFalse == test_20) {
                                      enumGalgasBool test_22 = kBoolTrue ;
                                      if (kBoolTrue == test_22) {
                                        test_22 = GALGAS_bool (kIsEqual, GALGAS_string ("location").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
                                        if (kBoolTrue == test_22) {
                                          {
                                          routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1996)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1996)) ;
                                          }
                                          result_result = GALGAS_gtlString::class_func_new (constinArgument_methodName.readProperty_location (), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1998)), this->mProperty_where.getter_endLocationString (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1998))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 1997)) ;
                                        }
                                      }
                                      if (kBoolFalse == test_22) {
                                        TC_Array <C_FixItDescription> fixItArray23 ;
                                        inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown getter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2001)).add_operation (GALGAS_string ("' for float target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2001)), fixItArray23  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2001)) ;
                                        result_result.drop () ; // Release error dropped variable
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
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension setter '@gtlFloat performSetter'
//
//--------------------------------------------------------------------------------------------------

static void extensionSetter_gtlFloat_performSetter (cPtr_gtlData * inObject,
                                                    const GALGAS_lstring constinArgument_methodName,
                                                    const GALGAS_gtlDataList constinArgument_arguments,
                                                    const GALGAS_gtlContext constinArgument_context,
                                                    const GALGAS_library constinArgument_lib,
                                                    Compiler * inCompiler
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlFloat * object = (cPtr_gtlFloat *) inObject ;
  macroValidSharedObject (object, cPtr_gtlFloat) ;
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (kIsEqual, GALGAS_string ("setDescription").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
    if (kBoolTrue == test_0) {
      {
      routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_stringArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2015)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2015)) ;
      }
      GALGAS_gtlString temp_1 ;
      if (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2016)).isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlString *> (constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2016)).ptr ())) {
          temp_1 = (cPtr_gtlString *) constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2016)).ptr () ;
        }else{
          inCompiler->castError ("gtlString", constinArgument_arguments.getter_dataAtIndex (GALGAS_uint (uint32_t (0U)), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2016)).ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2016)) ;
        }
      }
      GALGAS_gtlString var_descriptionToSet_62571 = temp_1 ;
      {
      object->setter_setMeta (callExtensionGetter_lstring ((const cPtr_gtlString *) var_descriptionToSet_62571.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2017)) COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2017)) ;
      }
      object->mProperty_where = constinArgument_methodName.readProperty_location () ;
    }
  }
  if (kBoolFalse == test_0) {
    enumGalgasBool test_2 = kBoolTrue ;
    if (kBoolTrue == test_2) {
      test_2 = GALGAS_bool (kIsEqual, GALGAS_string ("touch").objectCompare (constinArgument_methodName.readProperty_string ())).boolEnum () ;
      if (kBoolTrue == test_2) {
        {
        routine_argumentsCheck_3F__3F__3F_ (constinArgument_methodName, function_noArgument (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2020)), constinArgument_arguments, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2020)) ;
        }
        object->mProperty_where = constinArgument_methodName.readProperty_location () ;
      }
    }
    if (kBoolFalse == test_2) {
      enumGalgasBool test_3 = kBoolTrue ;
      if (kBoolTrue == test_3) {
        test_3 = callExtensionGetter_setterExists ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("float"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2022)).boolEnum () ;
        if (kBoolTrue == test_3) {
          const GALGAS_gtlFloat temp_4 = object ;
          GALGAS_gtlData var_copy_62880 = temp_4 ;
          callExtensionMethod_callSetter ((cPtr_gtlSetter *) callExtensionGetter_getSetter ((const cPtr_library *) constinArgument_lib.ptr (), GALGAS_string ("float"), constinArgument_methodName, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2024)).ptr (), constinArgument_methodName.readProperty_location (), constinArgument_context, constinArgument_lib, var_copy_62880, constinArgument_arguments, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2024)) ;
          GALGAS_gtlFloat temp_5 ;
          if (var_copy_62880.isValid ()) {
            if (nullptr != dynamic_cast <const cPtr_gtlFloat *> (var_copy_62880.ptr ())) {
              temp_5 = (cPtr_gtlFloat *) var_copy_62880.ptr () ;
            }else{
              inCompiler->castError ("gtlFloat", var_copy_62880.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2031)) ;
            }
          }
          object->mProperty_value = temp_5.readProperty_value () ;
          object->mProperty_where = var_copy_62880.readProperty_where () ;
          object->mProperty_meta = var_copy_62880.readProperty_meta () ;
        }
      }
      if (kBoolFalse == test_3) {
        TC_Array <C_FixItDescription> fixItArray6 ;
        inCompiler->emitSemanticError (constinArgument_methodName.readProperty_location (), GALGAS_string ("unknown setter '").add_operation (constinArgument_methodName.readProperty_string (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2035)).add_operation (GALGAS_string ("' for float target"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2035)), fixItArray6  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2035)) ;
      }
    }
  }
}
//--------------------------------------------------------------------------------------------------

static void defineExtensionSetter_gtlFloat_performSetter (void) {
  enterExtensionSetter_performSetter (kTypeDescriptor_GALGAS_gtlFloat.mSlotID,
                                      extensionSetter_gtlFloat_performSetter) ;
}

//--------------------------------------------------------------------------------------------------

PrologueEpilogue gSetter_gtlFloat_performSetter (defineExtensionSetter_gtlFloat_performSetter, nullptr) ;

//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString desc'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlString::getter_desc (const GALGAS_uint constinArgument_tab,
                                           Compiler * inCompiler
                                           COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = GALGAS_string::class_func_stringWithSequenceOfCharacters (GALGAS_char (TO_UNICODE (32)), constinArgument_tab  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2048)).add_operation (GALGAS_string ("string: \""), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2048)).add_operation (this->mProperty_value, inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2049)).add_operation (GALGAS_string ("\"\n"), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2049)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString string'
//
//--------------------------------------------------------------------------------------------------

GALGAS_string cPtr_gtlString::getter_string (Compiler */* inCompiler */
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_string result_result ; // Returned variable
  result_result = this->mProperty_value ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString lstring'
//
//--------------------------------------------------------------------------------------------------

GALGAS_lstring cPtr_gtlString::getter_lstring (Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result_result ; // Returned variable
  result_result = GALGAS_lstring::class_func_new (this->mProperty_value, this->mProperty_where, inCompiler  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2054)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString bool'
//
//--------------------------------------------------------------------------------------------------

GALGAS_bool cPtr_gtlString::getter_bool (Compiler * inCompiler
                                         COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("cannot cast a string to a bool"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2057)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString int'
//
//--------------------------------------------------------------------------------------------------

GALGAS_bigint cPtr_gtlString::getter_int (Compiler * inCompiler
                                          COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_bigint result_result ; // Returned variable
  result_result = this->mProperty_value.getter_decimalUnsignedNumber (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2061)).getter_bigint (SOURCE_FILE ("gtl_data_types.galgas", 2061)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString float'
//
//--------------------------------------------------------------------------------------------------

GALGAS_double cPtr_gtlString::getter_float (Compiler * inCompiler
                                            COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_double result_result ; // Returned variable
  result_result = this->mProperty_value.getter_decimalUnsignedNumber (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2065)).getter_double (SOURCE_FILE ("gtl_data_types.galgas", 2065)) ;
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString plusOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlString::getter_plusOp (Compiler * inCompiler
                                              COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("string forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2069)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString minusOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlString::getter_minusOp (Compiler * inCompiler
                                               COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("string forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2073)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString notOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlString::getter_notOp (Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("string forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2077)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString addOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlString::getter_addOp (const GALGAS_gtlData constinArgument_right,
                                             Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  enumGalgasBool test_0 = kBoolTrue ;
  if (kBoolTrue == test_0) {
    test_0 = GALGAS_bool (constinArgument_right.dynamicTypeDescriptor () == & kTypeDescriptor_GALGAS_gtlString).boolEnum () ;
    if (kBoolTrue == test_0) {
      GALGAS_gtlString temp_1 ;
      if (constinArgument_right.isValid ()) {
        if (nullptr != dynamic_cast <const cPtr_gtlString *> (constinArgument_right.ptr ())) {
          temp_1 = (cPtr_gtlString *) constinArgument_right.ptr () ;
        }else{
          inCompiler->castError ("gtlString", constinArgument_right.ptr ()->classDescriptor () COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2085)) ;
        }
      }
      result_result = GALGAS_gtlString::class_func_new (this->mProperty_where, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2084)), this->mProperty_value.add_operation (temp_1.readProperty_value (), inCompiler COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2085))  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2082)) ;
    }
  }
  if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray2 ;
    inCompiler->emitSemanticError (constinArgument_right.readProperty_where (), GALGAS_string ("string expected"), fixItArray2  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2088)) ;
    result_result.drop () ; // Release error dropped variable
  }
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString subOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlString::getter_subOp (const GALGAS_gtlData /* constinArgument_right */,
                                             Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("string forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2093)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString mulOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlString::getter_mulOp (const GALGAS_gtlData /* constinArgument_right */,
                                             Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("string forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2097)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString divOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlString::getter_divOp (const GALGAS_gtlData /* constinArgument_right */,
                                             Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("string forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2101)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


//--------------------------------------------------------------------------------------------------
//
//Overriding extension getter '@gtlString modOp'
//
//--------------------------------------------------------------------------------------------------

GALGAS_gtlData cPtr_gtlString::getter_modOp (const GALGAS_gtlData /* constinArgument_right */,
                                             Compiler * inCompiler
                                             COMMA_UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlData result_result ; // Returned variable
  TC_Array <C_FixItDescription> fixItArray0 ;
  inCompiler->emitSemanticError (this->mProperty_where, GALGAS_string ("string forbidden"), fixItArray0  COMMA_SOURCE_FILE ("gtl_data_types.galgas", 2105)) ;
  result_result.drop () ; // Release error dropped variable
//---
  return result_result ;
}


