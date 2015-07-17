//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//  This file is part of libpm library                                                                                 *
//                                                                                                                     *
//  Copyright (C) 2014, ..., 2014 Pierre Molinaro.                                                                     *
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

#import "NSString+identifierRepresentation.h"

//---------------------------------------------------------------------------------------------------------------------*

@implementation NSString (IdentifierRepresentation)

//---------------------------------------------------------------------------------------------------------------------*

- (NSString *) identifierRepresentation {
  NSMutableString * result = [NSMutableString new] ;
  for (NSUInteger i=0 ; i<self.length ; i++) {
    const unichar c = [self characterAtIndex:i] ;
    if ((c >= 'A') && (c <= 'Z')) {
      [result appendFormat:@"%c", c] ;
    }else if ((c >= 'a') && (c <= 'z')) {
      [result appendFormat:@"%c", c] ;
    }else{
      [result appendFormat:@"_%u_", c] ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

@end
