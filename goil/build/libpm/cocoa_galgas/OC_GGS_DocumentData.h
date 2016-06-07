//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 2012, ..., 2014 Pierre Molinaro.                                                                     *
//                                                                                                                     *
//  e-mail : pierre.molinaro@irccyn.ec-nantes.fr                                                                       *
//                                                                                                                     *
//  IRCCyN, Institut de Recherche en Communications et Cybernétique de Nantes, ECN, École Centrale de Nantes (France)  *
//                                                                                                                     *
//  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General  *
//  Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option)  *
//  any later version.                                                                                                 *
//                                                                                                                     *
//  This program is distributed in the hope it will be useful, but WITHOUT ANY WARRANTY; without even the implied      *
//  warranty of MERCHANDIBILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for            *
//  more details.                                                                                                      *
//                                                                                                                     *
//----------------------------------------------------------------------------------------------------------------------

#import "CocoaGalgasPrefix.h"

//----------------------------------------------------------------------------------------------------------------------

@class OC_GGS_TextSyntaxColoring ;
@class OC_GGS_TextDisplayDescriptor ;
@class OC_GGS_Document ;

//----------------------------------------------------------------------------------------------------------------------

@interface OC_GGS_DocumentData : NSObject {
  @private NSMutableArray * mIssueArray ; // Of PMIssueDescriptor
  @private OC_GGS_TextSyntaxColoring * mTextSyntaxColoring ;
//--- Document encoding
  @private NSStringEncoding mFileEncoding ;
}

@property (assign, readonly PROPERTY_COMMA_ATOMIC) OC_GGS_Document * document ; // May be nil
@property (copy, readonly PROPERTY_COMMA_ATOMIC) NSURL * fileURL ;

+ (void) saveAllDocuments ;

+ (void) cocoaDocumentWillClose: (OC_GGS_DocumentData *) inDocumentData ;

+ (OC_GGS_DocumentData *) findOrAddDataForDocumentURL: (NSURL *) inDocumentURL
                          forCocoaDocument: (OC_GGS_Document *) inDocument ;

+ (OC_GGS_DocumentData *) findDocumentDataForFilePath: (NSString *) inFilePath ;

- (OC_GGS_TextDisplayDescriptor *) newSourceDisplayDescriptorForDocument: (OC_GGS_Document *) inDocumentUsedForDisplaying ;

- (NSString *) sourceString ;

- (OC_GGS_TextSyntaxColoring *) textSyntaxColoring ;

- (void) replaceCharactersInRange: (NSRange) inRange withString: (NSString *) inReplaceString ;

- (BOOL) performSaveToURL: (NSURL *) inAbsoluteURL ;

- (NSUInteger) locationForLineInSource: (NSUInteger) inLine ;

+ (void) broadcastIssueArray: (NSArray *) inIssueArray ;

- (void) save ;

- (void) fileDidChangeInFileSystem ;

@end

//----------------------------------------------------------------------------------------------------------------------
