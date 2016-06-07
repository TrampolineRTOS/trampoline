//----------------------------------------------------------------------------------------------------------------------
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
//----------------------------------------------------------------------------------------------------------------------

#import <Cocoa/Cocoa.h>

//----------------------------------------------------------------------------------------------------------------------

@interface PMFontButton : NSButton {

//--- Attributes for 'fontValue' binding
  @protected id mBoundObjectFor_fontValue ;
  @protected NSString * mKeyPathFor_fontValue ;

  @protected  BOOL mFontButtonBindingEnableState ;
  @protected  BOOL mInheritedEnableState ;

}

//--- Method for 'fontValue' binding
  - (void) applyNewFontValue: (id) inValue ;
  - (void) valueFor_fontValue_didChange_marker: (id) inMarker
           defaultPlaceholder: (id) inDefaultPlaceHolder ;
  - (void) valueFor_fontValue_didChange_NSFont: (NSFont *) inValue ;

@end

//----------------------------------------------------------------------------------------------------------------------

