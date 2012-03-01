//---------------------------------------------------------------------------*
//                                                                           *
//  OC_GGS_DelegateForSyntaxColoring.h (started march 7th, 2007)             *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 2007, ..., 2011 Pierre Molinaro.                           *
//                                                                           *
//  e-mail : molinaro@irccyn.ec-nantes.fr                                    *
//  IRCCyN, Institut de Recherche en Communications et Cybernetique de Nantes*
//  ECN, Ecole Centrale de Nantes (France)                                   *
//                                                                           *
//  This library is free software; you can redistribute it and/or modify it  *
//  under the terms of the GNU Lesser General Public License as published    *
//  by the Free Software Foundation; either version 2 of the License, or     *
//  (at your option) any later version.                                      *
//                                                                           *
//  This program is distributed in the hope it will be useful, but WITHOUT   *
//  ANY WARRANTY; without even the implied warranty of MERCHANDIBILITY or    *
//  FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for *
//  more details.                                                            *
//                                                                           *
//---------------------------------------------------------------------------*

#import <Cocoa/Cocoa.h>

//---------------------------------------------------------------------------*

@class OC_GGS_Document ;
@class OC_GGS_TextView ;

//---------------------------------------------------------------------------*

@interface OC_GGS_DelegateForSyntaxColoring : NSObject
#ifdef MAC_OS_X_VERSION_10_6
 <NSTextViewDelegate>
#endif
{
  @private NSMutableArray * mFontAttributesDictionaryArray ; // Array of OC_Token
  @private NSMutableArray * mStyledRangeArray ;
  @private NSTextStorage * mTextStorage ;
  @private OC_GGS_Document * mDocument ;
  @private NSMutableDictionary * mTemplateTextAttributeDictionary ;
  @private NSUndoManager * mUndoManager ;
  
  @private CGFloat mMaxAscender ; // Only mMaxAscender is observable
  @private CGFloat mMaxLeadingMinusDescender ; // leading - descender (because descender is < 0)
}

- (id) initWithDocument: (OC_GGS_Document *) inDocument
       withSourceString: (NSString *) inSource ;

- (void) breakUndoCoalescing ;

- (NSString *) sourceString ;

- (void) setSourceString: (NSString *) inSource ;

- (NSTextStorage *) textStorage ;

- (NSArray *) tokenArray ; // Array of OC_Token

- (BOOL) selectionByWordSelectsAllCharactersForTokenIndex: (NSUInteger) inTokenIndex ;
@end

//---------------------------------------------------------------------------*
