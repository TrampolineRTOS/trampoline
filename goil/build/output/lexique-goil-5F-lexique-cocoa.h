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

enum {goil_lexique_1_,
  goil_lexique_1_comment,
  goil_lexique_1_idf,
  goil_lexique_1_string,
  goil_lexique_1_g_5F_string,
  goil_lexique_1_uint_5F_number,
  goil_lexique_1_float_5F_number,
  goil_lexique_1_set_5F_start_5F_uint_5F_number,
  goil_lexique_1_command,
  goil_lexique_1_OIL_5F_VERSION,
  goil_lexique_1_IMPLEMENTATION,
  goil_lexique_1_CPU,
  goil_lexique_1_UINT_33__32_,
  goil_lexique_1_INT_33__32_,
  goil_lexique_1_UINT_36__34_,
  goil_lexique_1_INT_36__34_,
  goil_lexique_1_FLOAT,
  goil_lexique_1_ENUM,
  goil_lexique_1_STRING,
  goil_lexique_1_BOOLEAN,
  goil_lexique_1_IDENTIFIER,
  goil_lexique_1_STRUCT,
  goil_lexique_1_WITH_5F_AUTO,
  goil_lexique_1_NO_5F_DEFAULT,
  goil_lexique_1_AUTO,
  goil_lexique_1_FALSE,
  goil_lexique_1_TRUE,
  goil_lexique_1__3B_,
  goil_lexique_1__3A_,
  goil_lexique_1__3D_,
  goil_lexique_1__7B_,
  goil_lexique_1__7D_,
  goil_lexique_1__2E__2E_,
  goil_lexique_1__5B_,
  goil_lexique_1__5D_,
  goil_lexique_1__2C_,
  goil_lexique_1__2E_,
  goil_lexique_1__2B_,
  goil_lexique_1__2D_,
  goil_lexique_1_include,
  goil_lexique_1_includeifexists
} ;

//----------------------------------------------------------------------------------------------------------------------
//
//                     S C A N N E R    C L A S S
//
//----------------------------------------------------------------------------------------------------------------------

@interface OC_Lexique_goil_lexique : OC_Lexique {
//--- Attributes
  @protected NSMutableString * mLexicalAttribute_a_string ;
  @protected NSMutableString * mLexicalAttribute_att_token ;
  @protected double mLexicalAttribute_floatNumber ;
  @protected UInt64 mLexicalAttribute_integerNumber ;
  @protected NSMutableString * mLexicalAttribute_number ;

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

