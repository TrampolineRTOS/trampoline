//--------------------------------------------------------------------------------------------------
//
//  'BinaryFileWrite' : a class for stream writing text files
//
//  This file is part of libpm library
//
//  Copyright (C) 1999, ..., 2023 Pierre Molinaro.
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
//--------------------------------------------------------------------------------------------------

#include "BinaryFileWrite.h"
#include "DateTime.h"
#include "FileManager.h"

//--------------------------------------------------------------------------------------------------

BinaryFileWrite::BinaryFileWrite (const String & inFileName) :
AbstractFileHandle (inFileName, "wb") {
}

//--------------------------------------------------------------------------------------------------

void BinaryFileWrite::appendData (const U8Data & inData) {
  appendBinaryData (size_t (inData.count ()), inData.unsafeDataPointer ()) ;
}

//--------------------------------------------------------------------------------------------------
