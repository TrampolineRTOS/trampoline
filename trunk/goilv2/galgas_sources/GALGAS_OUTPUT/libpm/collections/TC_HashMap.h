//-----------------------------------------------------------------------------*
//                                                                             *
//     C++ template class for implementing a map using hashing               *
//                                                                             *
//  Copyright (C) 2001 Pierre Molinaro.                                      *
//  e-mail : pierre.molinaro@irccyn.ec-nantes.fr                               *
//  IRCCyN, Institut de Recherche en Communications et Cybernétique de Nantes  *
//  ECN, Ecole Centrale de Nantes                                            *
//                                                                             *
//  This file is part of libpm library                                         *
//                                                                             *
//  This library is free software; you can redistribute it and/or modify it    *
//  under the terms of the GNU Lesser General Public License as published      *
//  by the Free Software Foundation; either version 2 of the License, or       *
//  (at your option) any later version.                                        *
//                                                                             *
//  This program is distributed in the hope it will be useful, but WITHOUT     *
//  ANY WARRANTY; without even the implied warranty of MERCHANDIBILITY or      *
//  FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for   *
//  more details.                                                              *
//                                                                             *
//-----------------------------------------------------------------------------*

#ifndef TEMPLATE_CALL_HASH_MAP_DEFINED
#define TEMPLATE_CALL_HASH_MAP_DEFINED

//-----------------------------------------------------------------------------*

#include "utilities/F_GetPrime.h"

//-----------------------------------------------------------------------------*
//                                                                             *
//  This template can be used in the following way :                         *
//    - MAP_TYPE is a class that defines the way collisions are handled ;    *
//    - INFO is a class that defines element information.                    *
//                                                                             *
//  Class INFO must define the following public method :                     *
//                     PMUInt32 getHashCodeForMap (void) const ;               *
//      this method is used for getting the element hash code.               *
//                                                                             *
//  Class MAP_TYPE must defines the following public methods :               *
//            INFO * search_or_insert (const INFO & inInfo,                  *
//                                     bool & outInsertionPerformed) ;       *
//            void sweepUnmarkedObjects (void) ;                             *
//                                                                             *
//  For class INFO, you can use a map template class, such as :              *
//     - TC_LinearListForCollision ;                                         *
//     - TC_AVL_TreeForCollision ;                                           *
//     - TC_Block_AVL_TreeForCollision.                                      *
//                                                                             *
//  Example :                                                                *
// //--- Declaration of map type used for collisions resolution              *
//   typedef TC_AVL_TreeForCollision <myInfoType> cMapType ;                 *
// //--- Allocation variable declaration                                     *
//   cMapType::cAllocInfo cMapType::smAllocInfo ;                            *
// //--- Hash map declaration                                                *
//   TC_HashMap <cMapType, myInfoType> gMap (66029) ;                        *
//                                                                             *
//  See also 'C_VDD.cpp' for an other example.                               *
//                                                                             *
//-----------------------------------------------------------------------------*

template <class MAP_TYPE, class INFO>
class TC_HashMap {
//--- Constructor
  public : TC_HashMap (void) ;

//--- Destructor
  public : virtual ~TC_HashMap (void) ;

//--- Search or insert
  public : inline INFO * search_or_insert (const INFO & inInfo,
                                           bool & outInsertionPerformed) ;

//--- Search or insert
  public : inline INFO * search (const INFO & inInfo) ;

//--- Change size
  public : void reallocMap (const PMSInt32 inNewSize) ;

//--- Get map size (in bytes)
  public : PMUInt32 getMapSizeInBytes (void) const ;

//--- Get marked nodes count
  public : PMSInt32 getMarkedNodesCount (void) const ;

//--- Sweep unmarked objects
  public : PMUInt32 sweepUnmarkedObjects (void) ;

//--- Unmarked all objects
  public : void unmarkAllObjects (void) ;

//--- Current size
  protected : PMSInt32 mCurrentEntriesCount ;
  public : inline PMSInt32 getHashMapEntriesCount (void) const { return mCurrentEntriesCount ; }

//--- Minimum map array (1 entry)
  protected : MAP_TYPE mMinimumMapArray ;

//--- map array
  protected : MAP_TYPE * mMapArray ;

//--- No copy
  private : TC_HashMap (const TC_HashMap <MAP_TYPE, INFO> &) ;
  private : TC_HashMap <MAP_TYPE, INFO> & operator = (const TC_HashMap <MAP_TYPE, INFO> &) ;
} ;

//-----------------------------------------------------------------------------*

template <class MAP_TYPE, class INFO>
TC_HashMap <MAP_TYPE, INFO>
::TC_HashMap (void) {
  mMapArray = & mMinimumMapArray ;
  mCurrentEntriesCount = 1 ;
}

//-----------------------------------------------------------------------------*

template <class MAP_TYPE, class INFO>
TC_HashMap<MAP_TYPE, INFO>::~TC_HashMap (void) {
  if (mCurrentEntriesCount > 1) {
    delete [] mMapArray ;
  }
}

//-----------------------------------------------------------------------------*

template <class MAP_TYPE, class INFO>
INFO * TC_HashMap<MAP_TYPE, INFO>::
search_or_insert (const INFO & inInfo,
                  bool & outInsertionPerformed) {
  PMUInt32 hashCode = inInfo.getHashCodeForMap () ;
  hashCode %= (PMUInt32) mCurrentEntriesCount ;
  return mMapArray [hashCode].search_or_insert (inInfo, outInsertionPerformed) ;
}

//-----------------------------------------------------------------------------*

template <class MAP_TYPE, class INFO>
INFO * TC_HashMap<MAP_TYPE, INFO>::
search (const INFO & inInfo) {
  PMUInt32 hashCode = inInfo.getHashCodeForMap () ;
  hashCode %= (PMUInt32) mCurrentEntriesCount ;
  return mMapArray [hashCode].search (inInfo) ;
}

//-----------------------------------------------------------------------------*

template <class MAP_TYPE, class INFO>
PMUInt32 TC_HashMap<MAP_TYPE, INFO>::sweepUnmarkedObjects (void) {
  PMUInt32 sweepedNodes = 0 ;
  for (PMSInt32 i=0 ; i<mCurrentEntriesCount ; i++) {
    sweepedNodes += mMapArray [i].sweepUnmarkedObjects () ;
  }
  return sweepedNodes ;
}

//-----------------------------------------------------------------------------*

template <class MAP_TYPE, class INFO>
PMUInt32 TC_HashMap<MAP_TYPE, INFO>
::getMapSizeInBytes (void) const {
  return ((PMUInt32) mCurrentEntriesCount) * sizeof (MAP_TYPE) ;
}

//-----------------------------------------------------------------------------*

template <class MAP_TYPE, class INFO>
void TC_HashMap<MAP_TYPE, INFO>
::reallocMap (const PMSInt32 inNewSize) {
  const PMSInt32 newSize = (inNewSize < 1) ? 1 : getPrimeGreaterThan (inNewSize) ;
  if (newSize != mCurrentEntriesCount) {
    MAP_TYPE * newMapArray = (newSize > 1) ? new MAP_TYPE [newSize] : (& mMinimumMapArray) ;
    for (PMSInt32 i=0 ; i<mCurrentEntriesCount ; i++) {
      mMapArray [i].transfertElementsInNewMapArray (newMapArray, (PMUInt32) newSize) ;
    }
    if (mCurrentEntriesCount > 1) {
      delete [] mMapArray ;
    }
    mMapArray = newMapArray ;
    mCurrentEntriesCount = newSize ;
  }
}

//-----------------------------------------------------------------------------*

template <class MAP_TYPE, class INFO>
void TC_HashMap<MAP_TYPE, INFO>::unmarkAllObjects (void) {
  for (PMSInt32 i=0 ; i<mCurrentEntriesCount ; i++) {
    mMapArray [i].unmarkAllObjects () ;
  }
}

//-----------------------------------------------------------------------------*

template <class MAP_TYPE, class INFO>
PMSInt32 TC_HashMap<MAP_TYPE, INFO>::getMarkedNodesCount (void) const {
  PMSInt32 count = 0 ;
  for (PMSInt32 i=0 ; i<mCurrentEntriesCount ; i++) {
    count += mMapArray [i].getMarkedNodesCount () ;
  }
  return count ;
}

//-----------------------------------------------------------------------------*

#endif
