//---------------------------------------------------------------------------*
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 2006, ..., 2009 Pierre Molinaro.                           *
//                                                                           *
//  e-mail : molinaro@irccyn.ec-nantes.fr                                    *
//                                                                           *
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

#import "OC_GGS_Document.h"
#import "OC_GGS_BuildResultTextView.h"
#import "OC_GGS_PreferencesController.h"

//---------------------------------------------------------------------------*

@implementation OC_GGS_BuildResultTextView

//---------------------------------------------------------------------------*

- (void) applyFontChange {
  NSUserDefaults * ud = [NSUserDefaults standardUserDefaults] ;
  NSData * data = [ud dataForKey:GGS_build_text_font] ;
  NSFont * font = [NSUnarchiver unarchiveObjectWithData:data] ;
  [self setFont:font] ;
}

//---------------------------------------------------------------------------*

- (void) awakeFromNib {
  NSUserDefaultsController * udc = [NSUserDefaultsController sharedUserDefaultsController] ;
  [udc
    addObserver:self
    forKeyPath:[NSString stringWithFormat:@"values.%@", GGS_build_text_font]
    options:0
    context:NULL
  ] ;
  [self applyFontChange] ;
}

//---------------------------------------------------------------------------*

- (void) observeValueForKeyPath: (NSString *) inKeyPath
         ofObject: (id) inObject
         change: (NSDictionary *) inChangeDictionary
         context: (void *) inContext {
  [self applyFontChange] ;
}

//---------------------------------------------------------------------------*

/* - (void) mouseDown: (NSEvent *) inEvent {
  if ([inEvent clickCount] > 1) {
 //   [myDocument handlesDoubleClickOnBuildResultTextView] ;
  }else{
    [super mouseDown:inEvent] ;
  }
}
 */
//---------------------------------------------------------------------------*

@end
