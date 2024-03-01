//----------------------------------------------------------------------------------------------------------------------
//
//  This file is part of libpm library                                                           
//
//  Copyright (C) 2003, ..., 2009 Pierre Molinaro.
//
//  e-mail : pierre@pcmolinaro.name
//
//  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General
//  Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option)
//  any later version.
//
//  This program is distributed in the hope it will be useful, but WITHOUT ANY WARRANTY; without even the implied
//  warranty of MERCHANDIBILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
//  more details.
//
//----------------------------------------------------------------------------------------------------------------------

void enterOptions (NSMutableArray * ioBoolOptionArray,
                   NSMutableArray * ioUIntOptionArray,
                   NSMutableArray * ioStringOptionArray,
                   NSMutableArray * ioStringListOptionArray) ;

//--- Nibs
NSArray * nibsAndClasses (void) ;

//--- Lexique interface
@class OC_Lexique ;

OC_Lexique * tokenizerForExtension (const NSString * inExtension) ;

NSArray * tokenizers (void) ;

NSDictionary * indexingDescriptorDictionary (void) ;

NSString * buildRunOption (void) ;

//----------------------------------------------------------------------------------------------------------------------
