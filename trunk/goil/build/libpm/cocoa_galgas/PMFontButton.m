//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 2011, ..., 2014 Pierre Molinaro.                                                                     *
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
//---------------------------------------------------------------------------------------------------------------------*

//#define DEBUG_MESSAGES

#import "PMFontButton.h"

//---------------------------------------------------------------------------------------------------------------------*

@implementation PMFontButton

//---------------------------------------------------------------------------------------------------------------------*

#pragma mark awakeFromNib

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               awakeFromNib                                                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

- (void) awakeFromNib {
  #ifdef DEBUG_MESSAGES
    NSLog (@"  PMFontButton <awakeFromNib:> for %p", self) ;
  #endif
  mInheritedEnableState = [super isEnabled] ;
  mFontButtonBindingEnableState = YES ;
}

//---------------------------------------------------------------------------------------------------------------------*

#pragma mark General Binding Methods

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                initialize                                                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

+ (void) initialize {
  [PMFontButton exposeBinding:@"fontValue"] ;
  [PMFontButton
    setDefaultPlaceholder:NSLocalizedString (@"Null Value", @"")
    forMarker:nil
    withBinding:@"fontValue"
  ] ;
  [PMFontButton
    setDefaultPlaceholder:NSLocalizedString (@"No Selection", @"")
    forMarker:NSNoSelectionMarker
    withBinding:@"fontValue"
  ] ;
  [PMFontButton
    setDefaultPlaceholder:NSLocalizedString (@"Multiple Values", @"")
    forMarker:NSMultipleValuesMarker
    withBinding:@"fontValue"
  ] ;
  [PMFontButton
    setDefaultPlaceholder:NSLocalizedString (@"Not Applicable", @"")
    forMarker:NSNotApplicableMarker
    withBinding:@"fontValue"
  ] ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                    bind:toObject:withKeyPath:options:                                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

- (void) bind:(NSString *) inBindingName
         toObject:(id) inObservableObject
         withKeyPath:(NSString *) inObservableKeyPath
         options:(NSDictionary *) inOptions {
  if ([inBindingName isEqualToString:@"fontValue"]) {
    mBoundObjectFor_fontValue = inObservableObject ;
    mKeyPathFor_fontValue = [inObservableKeyPath copy] ; 
    [inObservableObject
      addObserver:self
      forKeyPath:inObservableKeyPath
      options:NSKeyValueObservingOptionNew
      context:nil
    ] ;
    id value = [inObservableObject valueForKeyPath:inObservableKeyPath] ;
    [self applyNewFontValue:value] ;
  }else{
    [super bind:inBindingName toObject:inObservableObject withKeyPath:inObservableKeyPath options:inOptions] ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 unbind:                                                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

- (void) unbind:(NSString *) inBindingName {
  if ([inBindingName isEqualToString:@"fontValue"]) {
    [mBoundObjectFor_fontValue removeObserver:self forKeyPath:mKeyPathFor_fontValue] ;
    mBoundObjectFor_fontValue = nil ;
    mKeyPathFor_fontValue = nil ;
  }else{
    [super unbind:inBindingName] ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//             observeValueForKeyPath:ofObject:change:context:                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

- (void) observeValueForKeyPath:(NSString *) inKeyPath
         ofObject:(id) inObject
         change:(NSDictionary *) inChangeDictionary
         context:(void *) inContext {
  if ((mBoundObjectFor_fontValue == inObject) && [inKeyPath isEqualToString:mKeyPathFor_fontValue]) {
    id value = [inObject valueForKeyPath:inKeyPath] ;
    [self applyNewFontValue:value] ;
  }else{
    [super
      observeValueForKeyPath:inKeyPath
      ofObject:inObject
      change:inChangeDictionary
      context:inContext
    ] ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

#pragma mark Specific Binding Methods

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                      Method for 'fontValue' binding                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

- (void) applyNewFontValue: (id) inValue {
  #ifdef DEBUG_MESSAGES
    NSLog (@"PMFontButton <applyNewFontValue:>") ;
  #endif
  if (NSIsControllerMarker (inValue)) {
    id dph = [PMFontButton defaultPlaceholderForMarker:inValue withBinding:@"fontValue"] ;
    [self valueFor_fontValue_didChange_marker:inValue defaultPlaceholder:dph] ;
  }else if (inValue == nil) {
    [self valueFor_fontValue_didChange_NSFont:nil] ;
  }else if ([inValue isKindOfClass:[NSData class]]) {
    NSFont * font = [NSUnarchiver unarchiveObjectWithData:inValue] ;
    [self valueFor_fontValue_didChange_NSFont:font] ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

- (void) setValueFor_fontValue_Binding: (id) inValue {
  if ([inValue isKindOfClass:[NSFont class]]) {
    NSData * data = [NSArchiver archivedDataWithRootObject:inValue] ;
    [mBoundObjectFor_fontValue setValue:data forKeyPath:mKeyPathFor_fontValue] ;
  }else{
    [mBoundObjectFor_fontValue setValue:nil forKeyPath:mKeyPathFor_fontValue] ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

#pragma mark Methods for 'fontValue' Binding

//---------------------------------------------------------------------------------------------------------------------*

- (instancetype) init {
  #ifdef DEBUG_MESSAGES
    NSLog (@"PMFontButton <init>") ;
  #endif
  self = [super init] ;
  if (self) {
    mInheritedEnableState = [super isEnabled] ;
    mFontButtonBindingEnableState = YES ;
    [self setTitle:nil] ;
  }
  return self ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (id) initWithCoder: (NSCoder *) inCoder {
  #ifdef DEBUG_MESSAGES
    NSLog (@"PMFontButton <initWithCoder:>") ;
  #endif
  self = [super initWithCoder:inCoder] ;
  if (self) {
    mInheritedEnableState = [super isEnabled] ;
    mFontButtonBindingEnableState = YES ;
    [self setTitle:nil] ;
  }
  return self ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (id) initWithFrame: (NSRect) inRect {
  #ifdef DEBUG_MESSAGES
    NSLog (@"PMFontButton <initWithFrame:>") ;
  #endif
  self = [super initWithFrame:inRect] ;
  if (self) {
    mInheritedEnableState = [super isEnabled] ;
    mFontButtonBindingEnableState = YES ;
    [self setTitle:nil] ;
  }
  return self ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (void) setEnabled: (BOOL) flag {
  #ifdef DEBUG_MESSAGES
    NSLog (@"PMFontButton <setEnabled:>") ;
  #endif
  mInheritedEnableState = flag ;
//  NSLog (@"setEnabled mInheritedEnableState %d, mFontButtonBindingEnableState %d", mInheritedEnableState, mFontButtonBindingEnableState) ;
  [super setEnabled:mInheritedEnableState && mFontButtonBindingEnableState] ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (void) valueFor_fontValue_didChange_marker: (id) inMarker 
         defaultPlaceholder: (id) inDefaultPlaceholder {
  #ifdef DEBUG_MESSAGES
    NSLog (@"PMFontButton <valueFor_fontValue_didChange_marker:defaultPlaceholder:>") ;
  #endif
  [self setTitle:inDefaultPlaceholder] ;
  mFontButtonBindingEnableState = NO ;
  [super setEnabled:NO] ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (void) valueFor_fontValue_didChange_NSFont: (NSFont *) inNewValue {
  #ifdef DEBUG_MESSAGES
    NSLog (@"PMFontButton <valueFor_fontValue_didChange_NSFont:>") ;
  #endif
  NSString * displayNameWithSize = [NSString stringWithFormat: @"%@ - %3.1f pt.", [inNewValue displayName], [inNewValue pointSize]] ;
  [self setTitle:displayNameWithSize] ;
  mFontButtonBindingEnableState = YES ;
//  NSLog (@"Font '%@', mInheritedEnableState %d, mFontButtonBindingEnableState %d", displayNameWithSize, mInheritedEnableState, mFontButtonBindingEnableState) ;
  [super setEnabled:mInheritedEnableState && mFontButtonBindingEnableState] ;
/*  NSFontManager * fontManager = [NSFontManager sharedFontManager] ;
   if ([fontManager delegate] == self) {
    [fontManager setSelectedFont:inNewValue isMultiple:NO] ;
  }
   */
}

//---------------------------------------------------------------------------------------------------------------------*

- (void) buttonAction {
  #ifdef DEBUG_MESSAGES
    NSLog (@"PMFontButton <buttonAction>") ;
  #endif
  [[self window] makeFirstResponder:self] ;
  NSFontManager * fontManager = [NSFontManager sharedFontManager] ;
  NSData * data = [mBoundObjectFor_fontValue valueForKeyPath:mKeyPathFor_fontValue] ;
  NSFont * f = nil ;
  if (data != nil) {
    f = [NSUnarchiver unarchiveObjectWithData:data] ;
  }
  if (f == nil) {
    f = [NSFont systemFontOfSize:0.0] ;
  }
  [fontManager setSelectedFont:f isMultiple:NO] ;
  [fontManager setAction:@selector (changeFont:)] ;
  [fontManager setTarget:self] ;
  [fontManager orderFrontFontPanel:self] ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (void) changeFont: (id) inSender {
  #ifdef DEBUG_MESSAGES
    NSLog (@"PMFontButton <changeFont:>") ;
  #endif
  NSData * data = [mBoundObjectFor_fontValue valueForKeyPath:mKeyPathFor_fontValue] ;
  NSFont * newFont = nil ;
  if (data != nil) {
    newFont = [NSUnarchiver unarchiveObjectWithData:data] ;
  }
  newFont = [inSender convertFont:newFont] ;
  [self applyNewFontValue:newFont] ;
  [self setValueFor_fontValue_Binding:newFont] ;
}

//---------------------------------------------------------------------------------------------------------------------*

- (BOOL) sendAction:(SEL) theAction to: (id) theTarget {
  #ifdef DEBUG_MESSAGES
    NSLog (@"PMFontButton <sendAction:>") ;
  #endif
  [self buttonAction] ;
  return [super sendAction:theAction to:theTarget] ;
}


//---------------------------------------------------------------------------------------------------------------------*
// http://www.cocoabuilder.com/archive/cocoa/103479-nsfontpanel-shadow-color-underline-rotation.html

- (void) changeAttributes: (id) inFontEffectBox {
//  NSLog (@"inFontEffectBox %@", inFontEffectBox) ;
//  NSFontManager * fm = [NSFontManager sharedFontManager] ;
//  NSDictionary * d = [inFontEffectBox convertAttributes:inAttributes] ;
//  NSLog (@"d %@", d) ;
}

//---------------------------------------------------------------------------------------------------------------------*

@end
