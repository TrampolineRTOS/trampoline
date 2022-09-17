//----------------------------------------------------------------------------------------------------------------------
//
//  This file is part of libpm library
//
//  Copyright (C) 2021, ..., 2021 Pierre Molinaro.
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

#import "OC_GGS_ColorTransformer.h"

//----------------------------------------------------------------------------------------------------------------------

@implementation OC_GGS_ColorTransformer

+ (Class) transformedValueClass {
    return [NSColor class] ;
}

+ (BOOL) allowsReverseTransformation {
    return YES ;
}

- (NSData *) reverseTransformedValue: (NSColor *) inValue {
    NSData * archiveData = [NSKeyedArchiver archivedDataWithRootObject: inValue] ;
    return archiveData ;
}

- (NSColor *) transformedValue: (NSData *) inValue {
    NSColor * color = [NSKeyedUnarchiver unarchiveObjectWithData: inValue] ;
    return color ;
}

@end

//----------------------------------------------------------------------------------------------------------------------
