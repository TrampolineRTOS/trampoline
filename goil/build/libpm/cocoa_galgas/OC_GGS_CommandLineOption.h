//----------------------------------------------------------------------------------------------------------------------
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 2009, ..., 2014 Pierre Molinaro.                                                                     *
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

@interface OC_GGS_CommandLineOption : NSObject {
  @private NSString * mDomainName ;
  @private NSString * mIdentifier ;
  @private char mCommandChar ;
  @private NSString * mCommandString ;
  @private NSString * mComment ;
  @private NSString * mDefaultValue ;
  
}

- (id) initWithDomainName: (NSString *) inDomainName
       identifier: (NSString *) inIdentifier
       commandChar: (char) inCommandChar
       commandString: (NSString *) inCommandString
       comment: (NSString *) inComment
       defaultValue: (NSString *) inDefaultValue ;

- (NSString *) identifier ;

- (char) commandChar ;

- (NSString *) commandString ;

- (NSString *) title ;

@end

//----------------------------------------------------------------------------------------------------------------------
