//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#import "OC_Lexique.h"

//----------------------------------------------------------------------------------------------------------------------
//
//                    E X T E R N    R O U T I N E S
//
//----------------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------------------------------
//
//                    E X T E R N    F U N C T I O N S
//
//----------------------------------------------------------------------------------------------------------------------


//----------------------------------------------------------------------------------------------------------------------
//
//         T E R M I N A L    S Y M B O L    E N U M E R A T I O N
//
//----------------------------------------------------------------------------------------------------------------------

enum {gtl_scanner_1_,
  gtl_scanner_1_identifier,
  gtl_scanner_1_literal_5F_enum,
  gtl_scanner_1_literal_5F_double,
  gtl_scanner_1_signed_5F_literal_5F_integer_5F_bigint,
  gtl_scanner_1__2D_,
  gtl_scanner_1__2E_,
  gtl_scanner_1__2E__3D_,
  gtl_scanner_1__2E__2E__2E_,
  gtl_scanner_1_literal_5F_char,
  gtl_scanner_1_string,
  gtl_scanner_1_comment,
  gtl_scanner_1_after,
  gtl_scanner_1_before,
  gtl_scanner_1_between,
  gtl_scanner_1_by,
  gtl_scanner_1_default,
  gtl_scanner_1_display,
  gtl_scanner_1_do,
  gtl_scanner_1_down,
  gtl_scanner_1_else,
  gtl_scanner_1_elsif,
  gtl_scanner_1_emptylist,
  gtl_scanner_1_emptymap,
  gtl_scanner_1_end,
  gtl_scanner_1_error,
  gtl_scanner_1_exists,
  gtl_scanner_1_false,
  gtl_scanner_1_for,
  gtl_scanner_1_foreach,
  gtl_scanner_1_from,
  gtl_scanner_1_func,
  gtl_scanner_1_here,
  gtl_scanner_1_if,
  gtl_scanner_1_in,
  gtl_scanner_1_import,
  gtl_scanner_1_listof,
  gtl_scanner_1_let,
  gtl_scanner_1_loop,
  gtl_scanner_1_mapof,
  gtl_scanner_1_mod,
  gtl_scanner_1_no,
  gtl_scanner_1_not,
  gtl_scanner_1_or,
  gtl_scanner_1_print,
  gtl_scanner_1_println,
  gtl_scanner_1_seed,
  gtl_scanner_1_repeat,
  gtl_scanner_1_sort,
  gtl_scanner_1_step,
  gtl_scanner_1_tab,
  gtl_scanner_1_template,
  gtl_scanner_1_then,
  gtl_scanner_1_to,
  gtl_scanner_1_true,
  gtl_scanner_1_typeof,
  gtl_scanner_1_up,
  gtl_scanner_1_yes,
  gtl_scanner_1_warning,
  gtl_scanner_1_while,
  gtl_scanner_1_write,
  gtl_scanner_1_executable,
  gtl_scanner_1_variables,
  gtl_scanner_1_getter,
  gtl_scanner_1_unlet,
  gtl_scanner_1_setter,
  gtl_scanner_1_libraries,
  gtl_scanner_1_input,
  gtl_scanner_1_break,
  gtl_scanner_1__5F__5F_VARS_5F__5F_,
  gtl_scanner_1__2A_,
  gtl_scanner_1__7C_,
  gtl_scanner_1__2C_,
  gtl_scanner_1__2B_,
  gtl_scanner_1__3A__3A_,
  gtl_scanner_1__3E_,
  gtl_scanner_1__3A_,
  gtl_scanner_1__28_,
  gtl_scanner_1__29_,
  gtl_scanner_1__2D__3E_,
  gtl_scanner_1__3F_,
  gtl_scanner_1__3D__3D_,
  gtl_scanner_1__21_,
  gtl_scanner_1__3A__3D_,
  gtl_scanner_1__5B_,
  gtl_scanner_1__5D_,
  gtl_scanner_1__2B__3D_,
  gtl_scanner_1__2D__3D_,
  gtl_scanner_1__2F_,
  gtl_scanner_1__21__3D_,
  gtl_scanner_1__3E__3D_,
  gtl_scanner_1__26_,
  gtl_scanner_1__3C__3D_,
  gtl_scanner_1__7B_,
  gtl_scanner_1__7D_,
  gtl_scanner_1__3C_,
  gtl_scanner_1__5E_,
  gtl_scanner_1__3E__3E_,
  gtl_scanner_1__7E_,
  gtl_scanner_1__3C__2D_,
  gtl_scanner_1__3C__3C_,
  gtl_scanner_1__40_,
  gtl_scanner_1__2A__3D_,
  gtl_scanner_1__2F__3D_,
  gtl_scanner_1__26__3D_,
  gtl_scanner_1__7C__3D_,
  gtl_scanner_1__3C__3C__3D_,
  gtl_scanner_1__3E__3E__3D_,
  gtl_scanner_1_mod_3D_,
  gtl_scanner_1__5E__3D_,
  gtl_scanner_1__40__5B_,
  gtl_scanner_1__40__28_,
  gtl_scanner_1__40__7B_,
  gtl_scanner_1__5B__21_,
  gtl_scanner_1__40__21_,
  gtl_scanner_1__40__3F_
} ;

//----------------------------------------------------------------------------------------------------------------------
//
//                     S C A N N E R    C L A S S
//
//----------------------------------------------------------------------------------------------------------------------

@interface OC_Lexique_gtl_scanner : OC_Lexique {
//--- Attributes
  @protected NSMutableString * mLexicalAttribute_a_string ;
  @protected UInt32 mLexicalAttribute_charValue ;
  @protected double mLexicalAttribute_floatValue ;
  @protected NSMutableString * mLexicalAttribute_functionContent ;
  @protected NSMutableString * mLexicalAttribute_identifierString ;
  @protected NSMutableString * mLexicalAttribute_intValue ;
  @protected NSMutableString * mLexicalAttribute_tokenString ;
  @protected UInt32 mLexicalAttribute_uint32value ;

}

- (NSUInteger) terminalVocabularyCount ;

- (NSUInteger) styleIndexForTerminal: (NSInteger) inTerminal ;

- (BOOL) internalParseLexicalTokenForLexicalColoring ;

- (void) parseLexicalTokenForLexicalColoring ;

- (NSUInteger) styleCount ;

- (NSString *) styleNameForStyleIndex: (NSInteger) inIndex ;

- (NSString *) styleIdentifierForStyleIndex: (NSInteger) inIndex ;

- (NSArray *) indexingTitles ; // Array of NSString

- (BOOL) isTemplateLexique ;

- (BOOL) atomicSelectionForToken: (NSUInteger) inTokenIndex ;

@end

//----------------------------------------------------------------------------------------------------------------------
//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

