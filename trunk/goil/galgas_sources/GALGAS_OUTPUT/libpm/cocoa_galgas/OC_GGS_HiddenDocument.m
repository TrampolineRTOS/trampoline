//
//  OC_GGS_HiddenDocument.m
//  galgas
//
//  Created by Pierre Molinaro on 11/07/09.
//  Copyright 2009 __MyCompanyName__. All rights reserved.
//

#import "OC_GGS_HiddenDocument.h"
#import "OC_GGS_DelegateForSyntaxColoring.h"
#import "OC_Lexique.h"
#import "F_CocoaWrapperForGalgas.h"
#import "OC_GGS_TextView.h"

//---------------------------------------------------------------------------*

//#define DEBUG_MESSAGES

//---------------------------------------------------------------------------*

static NSMutableArray * gHiddenDocumentArray ;

//---------------------------------------------------------------------------*

@implementation OC_GGS_HiddenDocument

//---------------------------------------------------------------------------*

- (void) refreshShowInvisibleCharacters {
  const BOOL show = [[NSUserDefaults standardUserDefaults] boolForKey:@"PMShowInvisibleCharacters"] ;
  NSArray * layoutManagers = [mTextStorage layoutManagers] ;
  UInt32 n ;
  for (n=0 ; n<[layoutManagers count] ; n++) {
    NSLayoutManager * lm = [layoutManagers objectAtIndex:n] ;
    [lm setShowsInvisibleCharacters:show] ;
  }
}

//---------------------------------------------------------------------------*

- (id) init {
  self = [super init] ;
  if (self) {
    mUndoManager = [[NSUndoManager alloc] init] ;
    mTextStorage = [[NSTextStorage alloc] init] ;
    if (gHiddenDocumentArray == nil) {
      gHiddenDocumentArray = [[NSMutableArray alloc] init] ;
    }
    [gHiddenDocumentArray addObject:self] ;
  //--- Add editing observer
    NSUserDefaultsController * udc = [NSUserDefaultsController sharedUserDefaultsController] ;
    [udc
      addObserver:self
      forKeyPath:@"values.PMShowInvisibleCharacters"
      options:0
      context:NULL
    ] ;
    [self refreshShowInvisibleCharacters] ;
  }
  return self ;
}

//---------------------------------------------------------------------------*

- (void) dealloc {
  [mActualDocument release] ;
  [mDocumentURLForNonOpenedDocument release] ;
  [mTokenizer release] ;
  [mUndoManager release] ;
  [mTextStorage release] ;
  NSUserDefaultsController * udc = [NSUserDefaultsController sharedUserDefaultsController] ;
  [udc
    removeObserver:self
    forKeyPath:@"values.PMShowInvisibleCharacters"
  ] ;
  [super dealloc] ;
}

//---------------------------------------------------------------------------*

- (void) observeValueForKeyPath: (NSString *) inKeyPath
         ofObject: (id) inObject
         change: (NSDictionary *) inChangeDictionary
         context: (void *) inContext {
  #ifdef DEBUG_MESSAGES
    NSLog (@"OC_GGS_DelegateForSyntaxColoring <observeValueForKeyPath:>") ;
  #endif
  if ([inKeyPath isEqualToString:@"values.PMShowInvisibleCharacters"]) {
    [self refreshShowInvisibleCharacters] ;
  }
}

//---------------------------------------------------------------------------*

- (OC_GGS_Document *) actualDocument {
  return mActualDocument ;
}

//---------------------------------------------------------------------------*

- (NSURL *) documentURL {
  NSURL * url = mDocumentURLForNonOpenedDocument ;
  if (url == nil) {
    url = [mActualDocument fileURL] ;
  }
  return url ;
}

//---------------------------------------------------------------------------*

- (OC_Lexique *) tokenizer {
  return mTokenizer ;
}

//---------------------------------------------------------------------------*

- (NSTextStorage *) textStorage {
  return mTextStorage ;
}

//---------------------------------------------------------------------------*

- (BOOL) actualDocumentWillClose {
  const unsigned lmCount = [[mTextStorage layoutManagers] count] ;
  NSLog (@"%u layout managers", lmCount) ;
  return lmCount == 0 ;
}

//---------------------------------------------------------------------------*
//                                                                           *
//   P E R F O R M    S T R I N G    C O N V E R S I O N                     *
//                                                                           *
//---------------------------------------------------------------------------*

- (void) checkForCharacterConversion: (NSWindow *) inWindow {
  // NSLog (@"checkForCharacterConversion") ;
  NSString * source = [mTextStorage string] ;
//--- Search for "\r" ?
  BOOL needsConversionForCR = NO ;
  if ([[NSUserDefaults standardUserDefaults] boolForKey:@"PMConvert_CRLF_And_CR_To_LF_AtStartUp"]) {
    // NSLog (@"Convert CRLF and CR to LF") ;
    needsConversionForCR = [source rangeOfString:@"\r"].location != NSNotFound ;
  }
  BOOL needsConversionForHTAB = NO ;
  if ([[NSUserDefaults standardUserDefaults] boolForKey:@"PMConvert_HTAB_To_SPACE_AtStartUp"]) {
    // NSLog (@"Convert HTAB to SPACE") ;
    needsConversionForHTAB = [source rangeOfString:@"\x09"].location != NSNotFound ;
  }
  if (needsConversionForCR || needsConversionForHTAB) {
    NSMutableString * s = [NSMutableString stringWithCapacity:100] ;
    if (needsConversionForCR) {
    //--- Convert CR LF to LF
      NSArray * a = [source componentsSeparatedByString:@"\r\n"] ;
      const UInt32 CRLFcount = [a count] - 1 ;
      if (CRLFcount > 0) {
        [source release] ;
        source = [a componentsJoinedByString:@"\n"] ;
        [source retain] ;
        if (CRLFcount == 1) {
          [s appendFormat:@"1 CRLF has been converted to LF."] ;
        }else if (CRLFcount > 1) {
          [s appendFormat:@"%u CRLF have been converted to LF.", CRLFcount] ;
        }
      }
    //--- Convert CR to LF
      a = [source componentsSeparatedByString:@"\r"] ;
      const UInt32 CRcount = [a count] - 1 ;
      if (CRcount > 0) {
        [source release] ;
        source = [a componentsJoinedByString:@"\n"] ;
        [source retain] ;
        if ([s length] > 0) {
          [s appendString:@"\n"] ;
        }
        if (CRcount == 1) {
          [s appendFormat:@"1 CR has been converted to LF."] ;
        }else if (CRcount > 1) {
          [s appendFormat:@"%u CR have been converted to LF.", CRcount] ;
        }
      }
    }
    if (needsConversionForHTAB) {
      NSArray * a = [source componentsSeparatedByString:@"\x09"] ;
      const UInt32 HTABcount = [a count] - 1 ;
      if (HTABcount > 0) {
        [source release] ;
        source = [a componentsJoinedByString:@" "] ;
        [source retain] ;
        if ([s length] > 0) {
          [s appendString:@"\n"] ;
        }
        if (HTABcount == 1) {
          [s appendFormat:@"1 HTAB has been converted to SPACE."] ;
        }else if (HTABcount > 1) {
          [s appendFormat:@"%u HTAB have been converted to SPACE.", HTABcount] ;
        }
      }
    }
  //--- Display sheet if conversion done
    if ([s length] > 0) {
      [mTextStorage beginEditing] ;
      [mTextStorage replaceCharactersInRange:NSMakeRange (0, [mTextStorage length]) withString:source] ;
      [mTextStorage endEditing] ;
      NSAlert * alert = [NSAlert 
        alertWithMessageText:@"Source String Conversion"
        defaultButton:@"Ok"
        alternateButton:nil
        otherButton:nil
        informativeTextWithFormat:@"%@", s
      ] ;
      [[NSRunLoop currentRunLoop]
        performSelector:@selector (displayAlertOnDocumentOpening:)
        target:self
        argument:alert
        order:0
        modes:[NSArray arrayWithObject:NSDefaultRunLoopMode]
      ] ;
    }
  }
}

//---------------------------------------------------------------------------*

- (void) displayAlertOnDocumentOpening: (NSAlert *) inAlert {
  [inAlert
    beginSheetModalForWindow:[mActualDocument windowForSheet]
    modalDelegate:nil
    didEndSelector:NULL
    contextInfo:NULL
  ] ;
  NSBeep () ;
}

//---------------------------------------------------------------------------*

- (void) loadFileWithWindow: (NSWindow *) inWindow {
  NSData * data = [NSData dataWithContentsOfURL:[self documentURL]] ;
  NSString * source = [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding] ;
  [mTextStorage beginEditing] ;
  [mTextStorage replaceCharactersInRange:NSMakeRange (0, [mTextStorage length]) withString:source] ;
  [mTextStorage endEditing] ;
  [[NSRunLoop currentRunLoop]
    performSelector:@selector (checkForCharacterConversion:)
    target:self
    argument:inWindow
    order:0
    modes:[NSArray arrayWithObject:NSDefaultRunLoopMode]
  ] ;
}

//---------------------------------------------------------------------------*

- (void) configureIfNeeded {
  if (mTokenizer == nil) {
    NSString * extension = [[[self documentURL] absoluteString] pathExtension] ;
    mTokenizer = tokenizerForExtension (extension) ;
    mDelegateForSyntaxColoring = [[OC_GGS_DelegateForSyntaxColoring alloc]
      initHiddenDocument:self
    ] ;
    [self loadFileWithWindow:[mActualDocument windowForSheet]] ;
  }
}

//---------------------------------------------------------------------------*

- (void) setDocument: (OC_GGS_Document *) inDocument {
  mActualDocument = inDocument ;
  [mDocumentURLForNonOpenedDocument release] ;
  mDocumentURLForNonOpenedDocument = nil ;
  [self configureIfNeeded] ;
  [mActualDocument setUndoManager:mUndoManager] ;
}


//---------------------------------------------------------------------------*

- (void) saveToURL: (NSURL *) inURL {
  NSString * s = [mTextStorage string] ;
  NSData * data = [s dataUsingEncoding:NSUTF8StringEncoding] ;
  [data writeToURL:inURL atomically:YES] ;
}

//---------------------------------------------------------------------------*

#pragma mark NSTextView Delegate methods

//---------------------------------------------------------------------------*

- (NSUndoManager *) undoManagerForTextView:(NSTextView *)aTextView {
  return mUndoManager ;
}

//---------------------------------------------------------------------------*

- (void) textViewDidChangeSelection: (NSNotification *) inNotification {
  #ifdef DEBUG_MESSAGES
    NSLog (@"OC_GGS_HiddenDocument <textViewDidChangeSelection:>") ;
  #endif
  // NSLog (@"inNotification %@", inNotification) ;
  OC_GGS_TextView * textView = [inNotification object] ;
  // NSLog (@"textView %@", textView) ;
  [textView updateTextLineAndColumnSelectionLocation:nil] ;
}

//---------------------------------------------------------------------------*

@end

//---------------------------------------------------------------------------*

static OC_GGS_HiddenDocument * hiddenDocumentForURL (NSURL * inDocumentURL) {
  OC_GGS_HiddenDocument * result = nil ;
  UInt32 i ;
  for (i=0 ; (i<[gHiddenDocumentArray count]) && (result == nil) ; i++) {
    OC_GGS_HiddenDocument * hd = [gHiddenDocumentArray objectAtIndex:i] ;
    if ([inDocumentURL isEqualTo:[hd documentURL]]) {
      result = hd ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*

static OC_GGS_HiddenDocument * hiddenDocumentForDocument (OC_GGS_Document * inDocument) {
  OC_GGS_HiddenDocument * result = nil ;
  UInt32 i ;
  for (i=0 ; (i<[gHiddenDocumentArray count]) && (result == nil) ; i++) {
    OC_GGS_HiddenDocument * hd = [gHiddenDocumentArray objectAtIndex:i] ;
    if (inDocument == [hd actualDocument]) {
      result = hd ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------*

void associateDocumentWithURL (OC_GGS_Document * inDocument, NSURL * inDocumentURL) {
  OC_GGS_HiddenDocument * hd = hiddenDocumentForURL (inDocumentURL) ;
  if (hd == nil) {
    hd = [[OC_GGS_HiddenDocument alloc] init] ;
  }
  #ifdef DEBUG_MESSAGES
    NSLog (@"associateDocumentWithURL %@, inDocumentURL %@, hd %@", inDocument, inDocumentURL, hd) ;
  #endif
  [hd setDocument:inDocument] ;
}

//---------------------------------------------------------------------------*

void associateTextViewWithURL (OC_GGS_TextView * inTextView, NSURL * inDocumentURL) {
  OC_GGS_HiddenDocument * hd = hiddenDocumentForURL (inDocumentURL) ;
  #ifdef DEBUG_MESSAGES
    NSLog (@"associateDocumentWithURL %@, inDocumentURL %@, hd %@", inDocument, inDocumentURL, hd) ;
  #endif
  [inTextView setHiddenDocument:hd] ;
}

//---------------------------------------------------------------------------*

void saveActualDocumentToURL (OC_GGS_Document * inDocument, NSURL * inDocumentURL) {
  OC_GGS_HiddenDocument * hd = hiddenDocumentForDocument (inDocument) ;
  [hd saveToURL:inDocumentURL] ;
}

//---------------------------------------------------------------------------*

void noteDocumentWillClose (OC_GGS_Document * inDocument) {
  OC_GGS_HiddenDocument * hd = hiddenDocumentForDocument (inDocument) ;
  const BOOL removeHiddenDocument = [hd actualDocumentWillClose] ;
  if (removeHiddenDocument) {
    NSLog (@"remove %@", hd) ;
    [gHiddenDocumentArray removeObject:hd] ;
  }
}

//---------------------------------------------------------------------------*

