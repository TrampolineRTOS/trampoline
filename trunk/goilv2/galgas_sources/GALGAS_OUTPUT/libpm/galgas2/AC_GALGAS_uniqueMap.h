//---------------------------------------------------------------------------*
//                                                                           *
//  AC_GALGAS_uniqueMap : Base class for GALGAS map                          *
//                                                                           *
//  This file is part of libpm library                                       *
//                                                                           *
//  Copyright (C) 2008, ..., 2010 Pierre Molinaro.                           *
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

#ifndef UNIQUE_MAP_BASE_CLASS_DEFINED
#define UNIQUE_MAP_BASE_CLASS_DEFINED

//---------------------------------------------------------------------------*

#include "AC_GALGAS_root.h"
#include "typeComparisonResult.h"

//---------------------------------------------------------------------------*

class cSharedUniqueMapRoot ;
class cMapElement ;
class GALGAS_lstring ;
class GALGAS_string ;
class GALGAS_stringset ;
class GALGAS_lstringlist ;
class GALGAS_stringlist ;
class GALGAS_bool ;
class GALGAS_uint ;
class GALGAS_location ;
class C_LocationInSource ;
class AC_GALGAS_uniqueMap ;
class capCollectionElement ;
class cCollectionElement ;
class C_Compiler ;
class C_galgas_type_descriptor ;
class capCollectionElementArray ;
class cUniqueMapNode ;
class cSharedProxy ;

//---------------------------------------------------------------------------*
//                                                                           *
//                    Data structures for map automaton                      *
//                                                                           *
//---------------------------------------------------------------------------*

typedef enum {
  kMapAutomatonNoIssue,
  kMapAutomatonIssueWarning,
  kMapAutomatonIssueError
} mapAutomatonIssueEnum ;

//---------------------------------------------------------------------------*

typedef struct {
  const mapAutomatonIssueEnum mIssue ;
  const char * mIssueMessage ;
} cMapAutomatonFinalIssue ;

//---------------------------------------------------------------------------*

typedef struct {
  const PMUInt32 mTargetStateIndex ;
  const mapAutomatonIssueEnum mIssue ;
  const char * mIssueMessage ;
} cMapAutomatonTransition ;

//---------------------------------------------------------------------------*

typedef struct {
  const PMUInt32 mFirstStateIndex ;
  const PMUInt32 mLastStateIndex ;
  const PMUInt32 mResultingStateIndex ;
  const mapAutomatonIssueEnum mIssue ;
  const char * mIssueMessage ;
}cBranchOverrideTransformationDescriptor ;

//---------------------------------------------------------------------------*

typedef struct {
  const PMUInt32 mFirstCandidateStateIndex ;
  const PMUInt32 mSecondCandidateStateIndex ;
  const PMUInt32 mResultingStateIndex ;
  const mapAutomatonIssueEnum mIssue ;
  const char * mIssueMessage ;
}cBranchOverrideCompatibilityDescriptor ;

//---------------------------------------------------------------------------*

typedef struct {
  PMUInt32 mInitialStateIndex ;
  PMUInt32 mResultingStateIndex ;
}cOverrideStateDescriptor ;

//---------------------------------------------------------------------------*
//                                                                           *
//     M A P    P R O X Y                                                    *
//                                                                           *
//---------------------------------------------------------------------------*

class AC_GALGAS_uniqueMapProxy : public AC_GALGAS_root {
  private : typedef enum {kNotValid, kIsNull, kIsRegular} enumMapProxyState ;

//--------------------------------- Attributes
  private : enumMapProxyState mState ;
  private : cSharedProxy * mSharedProxy ; // refers to map node if kIsRegular
  
//--------------------------------- Constructor
  protected : AC_GALGAS_uniqueMapProxy (void) ;
  
//--------------------------------- Destructor
  protected : virtual ~ AC_GALGAS_uniqueMapProxy (void) ;
  
//--------------------------------- isValid
  public : virtual bool isValid (void) const ;
  
//--------------------------------- drop
  public : virtual void drop (void) ;
  
//--------------------------------- Handle copy
  protected : AC_GALGAS_uniqueMapProxy (const AC_GALGAS_uniqueMapProxy & inSource) ;
  protected : AC_GALGAS_uniqueMapProxy & operator = (const AC_GALGAS_uniqueMapProxy & inSource) ;

//--------------------------------- Attachment management
  private : VIRTUAL_IN_DEBUG void attachProxyToMapNode (cUniqueMapNode * inMapNode) ;

//--------------------------------- Internal make regular proxy
  protected : VIRTUAL_IN_DEBUG void internalMakeRegularProxy (AC_GALGAS_uniqueMap & ioMap,
                                                              const GALGAS_string & inKey
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Internal search key
  protected : VIRTUAL_IN_DEBUG void internalMakeRegularProxyBySearchingKey (const AC_GALGAS_uniqueMap & inMap,
                                                                            const GALGAS_lstring & inKey,
                                                                            const char * inSearchErrorMessage,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- Make null proxy
  protected : VIRTUAL_IN_DEBUG void makeNullProxy (LOCATION_ARGS) ;

//--------------------------------- Reader invocation declaration
  public : VIRTUAL_IN_DEBUG GALGAS_bool reader_isRegular (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGAS_bool reader_isNull (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGAS_bool reader_isSolved (C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGAS_string reader_identifierRepresentation (C_Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGAS_lstring reader_lkey (C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGAS_string reader_key (C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) const ;

//--------------------------------- Get attribute list
  protected : const cMapElement * getAttributeListPointer (C_Compiler * inCompiler,
                                                           const char * inReaderName
                                                           COMMA_LOCATION_ARGS) const ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const PMSInt32 inIndentation) const ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const AC_GALGAS_uniqueMapProxy & inOperand) const ;

} ;

//---------------------------------------------------------------------------*
//                                                                           *
//     M A P                                                                 *
//                                                                           *
//---------------------------------------------------------------------------*

class AC_GALGAS_uniqueMap : public AC_GALGAS_root {
//--------------------------------- Constructor
  protected : AC_GALGAS_uniqueMap (void) ;

//--------------------------------- Virtual destructor
  public : virtual ~ AC_GALGAS_uniqueMap (void) ;

//--------------------------------- Handle copy
  public : AC_GALGAS_uniqueMap (const AC_GALGAS_uniqueMap & inSource) ;
  public : AC_GALGAS_uniqueMap & operator = (const AC_GALGAS_uniqueMap & inSource) ;

//--- count
  public : VIRTUAL_IN_DEBUG PMUInt32 count (void) const ;

//--- isValid
  public : VIRTUAL_IN_DEBUG inline bool isValid (void) const { return mSharedMap != NULL ; }

//--- drop
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--- Create a new map
  protected : VIRTUAL_IN_DEBUG void makeNewEmptyMap (LOCATION_ARGS) ;

//--------------------------------- Insert
  protected : VIRTUAL_IN_DEBUG void performInsert (capCollectionElement & inAttributes,
                                                   C_Compiler * inCompiler,
                                                   const PMUInt32 inInitialState,
                                                   const char * inInitialStateName,
                                                   const char * inInsertErrorMessage,
                                                   const char * inShadowErrorMessage
                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- Search for 'with' read only instruction
  public : VIRTUAL_IN_DEBUG const cCollectionElement * readAccessForWithInstruction_hasKey (const GALGAS_string & inKey) const ;

//--------------------------------- Search
  protected : VIRTUAL_IN_DEBUG cUniqueMapNode * searchEntryInMap (const C_String & inKey) const ;

  public : VIRTUAL_IN_DEBUG void findNearestKey (const C_String & inKey,
                                                 TC_UniqueArray <C_String> & ioNearestKeyArray) const ;

  protected : VIRTUAL_IN_DEBUG const cCollectionElement * performSearch (const GALGAS_lstring & inKey,
                                                                         C_Compiler * inCompiler,
                                                                         const char * inSearchErrorMessage
                                                                         COMMA_LOCATION_ARGS) const ;

  protected : VIRTUAL_IN_DEBUG const cCollectionElement * performSearch (const GALGAS_lstring & inKey,
                                                                         C_Compiler * inCompiler,
                                                                         const PMUInt32 inActionIndex,
                                                                         const cMapAutomatonTransition inTransitionArray [],
                                                                         const PMUInt32 inAutomatonActionCount,
                                                                         const char * inAutomatonStateNames [],
                                                                         const char * inAutomatonActionNames [],
                                                                         #ifndef DO_NOT_GENERATE_CHECKINGS
                                                                           const PMUInt32 inAutomatonStateCount,
                                                                         #endif
                                                                         const char * inSearchErrorMessage
                                                                         COMMA_LOCATION_ARGS) ;

  protected : VIRTUAL_IN_DEBUG const cMapElement * searchForReadingAttribute (const GALGAS_string & inKey,
                                                                              C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) const ;

  protected : VIRTUAL_IN_DEBUG cMapElement * searchForReadWriteAttribute (const GALGAS_string & inKey,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) ;

  protected : VIRTUAL_IN_DEBUG cMapElement * searchForReadWriteAttribute (const GALGAS_lstring & inKey,
                                                                          C_Compiler * inCompiler,
                                                                          const char * inSearchErrorMessage
                                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- Readers
  public : VIRTUAL_IN_DEBUG GALGAS_bool reader_hasKey (const GALGAS_string & inKey
                                                       COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGAS_location reader_locationForKey (const GALGAS_string & inKey,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGAS_stringset reader_allKeys (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGAS_lstringlist reader_allKeyList (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGAS_uint reader_count (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGAS_uint reader_unsolvedProxyCount (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGAS_stringlist reader_unsolvedProxyKeyList (LOCATION_ARGS) const ;

//--------------------------------- Introspection
  public : virtual const C_galgas_type_descriptor * staticTypeDescriptor (void) const = 0 ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const PMSInt32 inIndentation) const ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const AC_GALGAS_uniqueMap & inOperand) const ;

//--------------------------------- Internal methods for enumeration
  protected : VIRTUAL_IN_DEBUG void populateEnumerationArray (capCollectionElementArray & inEnumerationArray,
                                                              const typeEnumerationOrder inEnumerationOrder) const ;

//--------------------------------- Internal methods for inserting proxy
  protected : VIRTUAL_IN_DEBUG cUniqueMapNode * performInsertProxy (const C_String & inKey
                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- Check Map Automatons state
  public : VIRTUAL_IN_DEBUG void checkAutomatonStates (const GALGAS_location & inErrorLocation,
                                                       const cMapAutomatonFinalIssue inAutomatonFinalIssueArray [],
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) const ;

//--------------------------------- Open override for block
  public : VIRTUAL_IN_DEBUG void openOverride (const cBranchOverrideTransformationDescriptor inBranchBehaviourArray [],
                                               const PMUInt32 inBranchBehaviourSize,
                                               const cBranchOverrideCompatibilityDescriptor inBranchCombinationArray [],
                                               const PMUInt32 inBranchCombinationSize,
                                               const char * inBlockName,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- Close override for block
  public : VIRTUAL_IN_DEBUG void modifier_closeOverride (const GALGAS_location & inErrorLocation,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- Branch Handling
  public : VIRTUAL_IN_DEBUG void modifier_openBranch (C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void closeBranch (const GALGAS_location & inErrorLocation,
                                              const cMapAutomatonFinalIssue inAutomatonFinalIssueArray [],
                                              #ifndef DO_NOT_GENERATE_CHECKINGS
                                                const PMUInt32 inAutomatonStateCount,
                                              #endif
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Attributes
  private : cSharedUniqueMapRoot * mSharedMap ;
  
//--------------------------------- Attributes
  friend class AC_GALGAS_uniqueMapProxy ;
} ;

//---------------------------------------------------------------------------*

#endif
