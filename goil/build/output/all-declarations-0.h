#ifndef all_2D_declarations_2D__30__ENTITIES_DEFINED
#define all_2D_declarations_2D__30__ENTITIES_DEFINED

//---------------------------------------------------------------------------------------------------------------------*

#include "galgas2/predefined-types.h"

//---------------------------------------------------------------------------------------------------------------------*


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                     @Ttype enum                                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_Ttype : public AC_GALGAS_root {
//--------------------------------- Default constructor
  public : GALGAS_Ttype (void) ;

//--------------------------------- Enumeration
  public : typedef enum {
    kNotBuilt,
    kEnum_boolType,
    kEnum_intType,
    kEnum_floatType,
    kEnum_stringType,
    kEnum_listType,
    kEnum_mapType,
    kEnum_structType,
    kEnum_enumType,
    kEnum_functionType,
    kEnum_unconstructedType
  } enumeration ;
  
//--------------------------------- Private data member
  private : enumeration mEnum ;

//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG inline bool isValid (void) const { return kNotBuilt != mEnum ; }
  public : VIRTUAL_IN_DEBUG inline void drop (void) { mEnum = kNotBuilt ; }
  public : inline enumeration enumValue (void) const { return mEnum ; }

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_Ttype extractObject (const GALGAS_object & inObject,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_Ttype constructor_boolType (LOCATION_ARGS) ;

  public : static GALGAS_Ttype constructor_enumType (LOCATION_ARGS) ;

  public : static GALGAS_Ttype constructor_floatType (LOCATION_ARGS) ;

  public : static GALGAS_Ttype constructor_functionType (LOCATION_ARGS) ;

  public : static GALGAS_Ttype constructor_intType (LOCATION_ARGS) ;

  public : static GALGAS_Ttype constructor_listType (LOCATION_ARGS) ;

  public : static GALGAS_Ttype constructor_mapType (LOCATION_ARGS) ;

  public : static GALGAS_Ttype constructor_stringType (LOCATION_ARGS) ;

  public : static GALGAS_Ttype constructor_structType (LOCATION_ARGS) ;

  public : static GALGAS_Ttype constructor_unconstructedType (LOCATION_ARGS) ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_Ttype & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isBoolType (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isEnumType (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isFloatType (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isFunctionType (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isIntType (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isListType (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isMapType (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isStringType (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isStructType (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isUnconstructedType (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_Ttype class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_Ttype ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                   @TtypeList list                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_TtypeList : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public : GALGAS_TtypeList (void) ;

//--------------------------------- List constructor used by listmap
  public : GALGAS_TtypeList (cSharedList * inSharedListPtr) ;

//--------------------------------- Element constructor used by listmap
  public : static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                  const class GALGAS_Ttype & in_mType
                                                  COMMA_LOCATION_ARGS) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_TtypeList extractObject (const GALGAS_object & inObject,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_TtypeList constructor_emptyList (LOCATION_ARGS) ;

  public : static GALGAS_TtypeList constructor_listWithValue (const class GALGAS_Ttype & inOperand0
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public : VIRTUAL_IN_DEBUG void dotAssign_operation (const GALGAS_TtypeList inOperand
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public : VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_Ttype & inOperand0
                                                      COMMA_LOCATION_ARGS) ;
//--------------------------------- . (concat) operator
  public : VIRTUAL_IN_DEBUG GALGAS_TtypeList operator_concat (const GALGAS_TtypeList & inOperand
                                                              COMMA_LOCATION_ARGS) const ;

//--------------------------------- + operator
  public : VIRTUAL_IN_DEBUG GALGAS_TtypeList add_operation (const GALGAS_TtypeList & inOperand,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void modifier_insertAtIndex (class GALGAS_Ttype constinArgument0,
                                                         class GALGAS_uint constinArgument1,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_popFirst (class GALGAS_Ttype & outArgument0,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_popLast (class GALGAS_Ttype & outArgument0,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_removeAtIndex (class GALGAS_Ttype & outArgument0,
                                                         class GALGAS_uint constinArgument1,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_first (class GALGAS_Ttype & outArgument0,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_last (class GALGAS_Ttype & outArgument0,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_Ttype reader_mTypeAtIndex (const class GALGAS_uint & constinOperand0,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_TtypeList reader_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_TtypeList reader_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
//--------------------------------- Friend

  friend class cEnumerator_TtypeList ;
 
} ; // End of GALGAS_TtypeList class

//---------------------------------------------------------------------------------------------------------------------*
//   Enumerator declaration                                                    *
//---------------------------------------------------------------------------------------------------------------------*

class cEnumerator_TtypeList : public cGenericAbstractEnumerator {
  public : cEnumerator_TtypeList (const GALGAS_TtypeList & inEnumeratedObject,
                                  const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_Ttype current_mType (LOCATION_ARGS) const ;
//--- Current element access
  public : class GALGAS_TtypeList_2D_element current (LOCATION_ARGS) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_TtypeList ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            @TtypeList_2D_element struct                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_TtypeList_2D_element : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_Ttype mAttribute_mType ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default constructor
  public : GALGAS_TtypeList_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_TtypeList_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS_TtypeList_2D_element (const GALGAS_Ttype & in_mType) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_TtypeList_2D_element extractObject (const GALGAS_object & inObject,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_TtypeList_2D_element constructor_new (const class GALGAS_Ttype & inOperand0
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_TtypeList_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_Ttype reader_mType (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_TtypeList_2D_element class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_TtypeList_2D_element ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                   @TfieldMap map                                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cMapElement_TfieldMap ;

//---------------------------------------------------------------------------------------------------------------------*

extern const char * kSearchErrorMessage_TfieldMap_searchKey ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_TfieldMap : public AC_GALGAS_map {
//--------------------------------- Default constructor
  public : GALGAS_TfieldMap (void) ;

//--------------------------------- Handle copy
  public : GALGAS_TfieldMap (const GALGAS_TfieldMap & inSource) ;
  public : GALGAS_TfieldMap & operator = (const GALGAS_TfieldMap & inSource) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_TfieldMap extractObject (const GALGAS_object & inObject,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_TfieldMap constructor_emptyMap (LOCATION_ARGS) ;

  public : static GALGAS_TfieldMap constructor_mapWithMapToOverride (const class GALGAS_TfieldMap & inOperand0
                                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public : VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0,
                                                      const class GALGAS_Ttype & inOperand1,
                                                      const class GALGAS_Tvalue & inOperand2,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void modifier_insertKey (class GALGAS_lstring constinArgument0,
                                                     class GALGAS_Ttype constinArgument1,
                                                     class GALGAS_Tvalue constinArgument2,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_removeKey (class GALGAS_lstring constinArgument0,
                                                     class GALGAS_Ttype & outArgument1,
                                                     class GALGAS_Tvalue & outArgument2,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setMTypeForKey (class GALGAS_Ttype constinArgument0,
                                                          class GALGAS_string constinArgument1,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setMValueForKey (class GALGAS_Tvalue constinArgument0,
                                                           class GALGAS_string constinArgument1,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_searchKey (class GALGAS_lstring constinArgument0,
                                                   class GALGAS_Ttype & outArgument1,
                                                   class GALGAS_Tvalue & outArgument2,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_Ttype reader_mTypeForKey (const class GALGAS_string & constinOperand0,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_Tvalue reader_mValueForKey (const class GALGAS_string & constinOperand0,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_TfieldMap reader_overriddenMap (C_Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
  public : VIRTUAL_IN_DEBUG cMapElement_TfieldMap * readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                       const GALGAS_string & inKey
                                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend

  friend class cEnumerator_TfieldMap ;
 
} ; // End of GALGAS_TfieldMap class

//---------------------------------------------------------------------------------------------------------------------*
//   Enumerator declaration                                                    *
//---------------------------------------------------------------------------------------------------------------------*

class cEnumerator_TfieldMap : public cGenericAbstractEnumerator {
  public : cEnumerator_TfieldMap (const GALGAS_TfieldMap & inEnumeratedObject,
                                  const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_lstring current_lkey (LOCATION_ARGS) const ;
  public : class GALGAS_Ttype current_mType (LOCATION_ARGS) const ;
  public : class GALGAS_Tvalue current_mValue (LOCATION_ARGS) const ;
//--- Current element access
  public : class GALGAS_TfieldMap_2D_element current (LOCATION_ARGS) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_TfieldMap ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 @TfieldMapList list                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_TfieldMapList : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public : GALGAS_TfieldMapList (void) ;

//--------------------------------- List constructor used by listmap
  public : GALGAS_TfieldMapList (cSharedList * inSharedListPtr) ;

//--------------------------------- Element constructor used by listmap
  public : static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                  const class GALGAS_TfieldMap & in_mMap
                                                  COMMA_LOCATION_ARGS) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_TfieldMapList extractObject (const GALGAS_object & inObject,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_TfieldMapList constructor_emptyList (LOCATION_ARGS) ;

  public : static GALGAS_TfieldMapList constructor_listWithValue (const class GALGAS_TfieldMap & inOperand0
                                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public : VIRTUAL_IN_DEBUG void dotAssign_operation (const GALGAS_TfieldMapList inOperand
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public : VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_TfieldMap & inOperand0
                                                      COMMA_LOCATION_ARGS) ;
//--------------------------------- . (concat) operator
  public : VIRTUAL_IN_DEBUG GALGAS_TfieldMapList operator_concat (const GALGAS_TfieldMapList & inOperand
                                                                  COMMA_LOCATION_ARGS) const ;

//--------------------------------- + operator
  public : VIRTUAL_IN_DEBUG GALGAS_TfieldMapList add_operation (const GALGAS_TfieldMapList & inOperand,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void modifier_insertAtIndex (class GALGAS_TfieldMap constinArgument0,
                                                         class GALGAS_uint constinArgument1,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_popFirst (class GALGAS_TfieldMap & outArgument0,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_popLast (class GALGAS_TfieldMap & outArgument0,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_removeAtIndex (class GALGAS_TfieldMap & outArgument0,
                                                         class GALGAS_uint constinArgument1,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setMMapAtIndex (class GALGAS_TfieldMap constinArgument0,
                                                          class GALGAS_uint constinArgument1,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_first (class GALGAS_TfieldMap & outArgument0,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_last (class GALGAS_TfieldMap & outArgument0,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_TfieldMap reader_mMapAtIndex (const class GALGAS_uint & constinOperand0,
                                                                       C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_TfieldMapList reader_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_TfieldMapList reader_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
//--------------------------------- Friend

  friend class cEnumerator_TfieldMapList ;
 
} ; // End of GALGAS_TfieldMapList class

//---------------------------------------------------------------------------------------------------------------------*
//   Enumerator declaration                                                    *
//---------------------------------------------------------------------------------------------------------------------*

class cEnumerator_TfieldMapList : public cGenericAbstractEnumerator {
  public : cEnumerator_TfieldMapList (const GALGAS_TfieldMapList & inEnumeratedObject,
                                      const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_TfieldMap current_mMap (LOCATION_ARGS) const ;
//--- Current element access
  public : class GALGAS_TfieldMapList_2D_element current (LOCATION_ARGS) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_TfieldMapList ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  @Tfunction struct                                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_Tfunction : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_lstring mAttribute_name ;
  public : GALGAS_lstringlist mAttribute_args ;
  public : GALGAS_string mAttribute_content ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_Tfunction constructor_default (LOCATION_ARGS) ;

//--------------------------------- Default constructor
  public : GALGAS_Tfunction (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_Tfunction (void) ;

//--------------------------------- Native constructor
  public : GALGAS_Tfunction (const GALGAS_lstring & in_name,
                             const GALGAS_lstringlist & in_args,
                             const GALGAS_string & in_content) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_Tfunction extractObject (const GALGAS_object & inObject,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_Tfunction constructor_new (const class GALGAS_lstring & inOperand0,
                                                    const class GALGAS_lstringlist & inOperand1,
                                                    const class GALGAS_string & inOperand2
                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_Tfunction & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_lstringlist reader_args (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string reader_content (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstring reader_name (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_Tfunction class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_Tfunction ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                   @Tvalue struct                                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_Tvalue : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_sint_36__34_ mAttribute_mInt_36__34_Value ;
  public : GALGAS_double mAttribute_mFloatValue ;
  public : GALGAS_string mAttribute_mStringValue ;
  public : GALGAS_TfieldMapList mAttribute_mMapListValue ;
  public : GALGAS_TfieldMap mAttribute_mStructValue ;
  public : GALGAS_Tfunction mAttribute_mFunctionValue ;
  public : GALGAS_lstring mAttribute_mDescription ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_Tvalue constructor_default (LOCATION_ARGS) ;

//--------------------------------- Default constructor
  public : GALGAS_Tvalue (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_Tvalue (void) ;

//--------------------------------- Native constructor
  public : GALGAS_Tvalue (const GALGAS_sint_36__34_ & in_mInt_36__34_Value,
                          const GALGAS_double & in_mFloatValue,
                          const GALGAS_string & in_mStringValue,
                          const GALGAS_TfieldMapList & in_mMapListValue,
                          const GALGAS_TfieldMap & in_mStructValue,
                          const GALGAS_Tfunction & in_mFunctionValue,
                          const GALGAS_lstring & in_mDescription) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_Tvalue extractObject (const GALGAS_object & inObject,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_Tvalue constructor_new (const class GALGAS_sint_36__34_ & inOperand0,
                                                 const class GALGAS_double & inOperand1,
                                                 const class GALGAS_string & inOperand2,
                                                 const class GALGAS_TfieldMapList & inOperand3,
                                                 const class GALGAS_TfieldMap & inOperand4,
                                                 const class GALGAS_Tfunction & inOperand5,
                                                 const class GALGAS_lstring & inOperand6
                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_Tvalue & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_lstring reader_mDescription (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_double reader_mFloatValue (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_Tfunction reader_mFunctionValue (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_sint_36__34_ reader_mInt_36__34_Value (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_TfieldMapList reader_mMapListValue (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string reader_mStringValue (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_TfieldMap reader_mStructValue (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_Tvalue class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_Tvalue ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Class for element of '@TfieldMap' map                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cMapElement_TfieldMap : public cMapElement {
//--- Map attributes
  public : GALGAS_Ttype mAttribute_mType ;
  public : GALGAS_Tvalue mAttribute_mValue ;

//--- Constructor
  public : cMapElement_TfieldMap (const GALGAS_lstring & inKey,
                                  const GALGAS_Ttype & in_mType,
                                  const GALGAS_Tvalue & in_mValue
                                  COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public : virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public : virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public : virtual cMapElement * copy (void) ;

//--- Description
 public : virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            @TfieldMap_2D_element struct                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_TfieldMap_2D_element : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_lstring mAttribute_lkey ;
  public : GALGAS_Ttype mAttribute_mType ;
  public : GALGAS_Tvalue mAttribute_mValue ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default constructor
  public : GALGAS_TfieldMap_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_TfieldMap_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS_TfieldMap_2D_element (const GALGAS_lstring & in_lkey,
                                        const GALGAS_Ttype & in_mType,
                                        const GALGAS_Tvalue & in_mValue) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_TfieldMap_2D_element extractObject (const GALGAS_object & inObject,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_TfieldMap_2D_element constructor_new (const class GALGAS_lstring & inOperand0,
                                                               const class GALGAS_Ttype & inOperand1,
                                                               const class GALGAS_Tvalue & inOperand2
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_TfieldMap_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_lstring reader_lkey (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_Ttype reader_mType (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_Tvalue reader_mValue (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_TfieldMap_2D_element class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_TfieldMap_2D_element ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          @TfieldMapList_2D_element struct                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_TfieldMapList_2D_element : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_TfieldMap mAttribute_mMap ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_TfieldMapList_2D_element constructor_default (LOCATION_ARGS) ;

//--------------------------------- Default constructor
  public : GALGAS_TfieldMapList_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_TfieldMapList_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS_TfieldMapList_2D_element (const GALGAS_TfieldMap & in_mMap) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_TfieldMapList_2D_element extractObject (const GALGAS_object & inObject,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_TfieldMapList_2D_element constructor_new (const class GALGAS_TfieldMap & inOperand0
                                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_TfieldMapList_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_TfieldMap reader_mMap (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_TfieldMapList_2D_element class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_TfieldMapList_2D_element ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                @TexpressionList list                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_TexpressionList : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public : GALGAS_TexpressionList (void) ;

//--------------------------------- List constructor used by listmap
  public : GALGAS_TexpressionList (cSharedList * inSharedListPtr) ;

//--------------------------------- Element constructor used by listmap
  public : static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                  const class GALGAS_Tvalue & in_mValue,
                                                  const class GALGAS_Ttype & in_mType
                                                  COMMA_LOCATION_ARGS) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_TexpressionList extractObject (const GALGAS_object & inObject,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_TexpressionList constructor_emptyList (LOCATION_ARGS) ;

  public : static GALGAS_TexpressionList constructor_listWithValue (const class GALGAS_Tvalue & inOperand0,
                                                                    const class GALGAS_Ttype & inOperand1
                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public : VIRTUAL_IN_DEBUG void dotAssign_operation (const GALGAS_TexpressionList inOperand
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public : VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_Tvalue & inOperand0,
                                                      const class GALGAS_Ttype & inOperand1
                                                      COMMA_LOCATION_ARGS) ;
//--------------------------------- . (concat) operator
  public : VIRTUAL_IN_DEBUG GALGAS_TexpressionList operator_concat (const GALGAS_TexpressionList & inOperand
                                                                    COMMA_LOCATION_ARGS) const ;

//--------------------------------- + operator
  public : VIRTUAL_IN_DEBUG GALGAS_TexpressionList add_operation (const GALGAS_TexpressionList & inOperand,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void modifier_insertAtIndex (class GALGAS_Tvalue constinArgument0,
                                                         class GALGAS_Ttype constinArgument1,
                                                         class GALGAS_uint constinArgument2,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_popFirst (class GALGAS_Tvalue & outArgument0,
                                                    class GALGAS_Ttype & outArgument1,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_popLast (class GALGAS_Tvalue & outArgument0,
                                                   class GALGAS_Ttype & outArgument1,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_removeAtIndex (class GALGAS_Tvalue & outArgument0,
                                                         class GALGAS_Ttype & outArgument1,
                                                         class GALGAS_uint constinArgument2,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_first (class GALGAS_Tvalue & outArgument0,
                                               class GALGAS_Ttype & outArgument1,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_last (class GALGAS_Tvalue & outArgument0,
                                              class GALGAS_Ttype & outArgument1,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_Ttype reader_mTypeAtIndex (const class GALGAS_uint & constinOperand0,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_Tvalue reader_mValueAtIndex (const class GALGAS_uint & constinOperand0,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_TexpressionList reader_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                                  C_Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_TexpressionList reader_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                                  C_Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
//--------------------------------- Friend

  friend class cEnumerator_TexpressionList ;
 
} ; // End of GALGAS_TexpressionList class

//---------------------------------------------------------------------------------------------------------------------*
//   Enumerator declaration                                                    *
//---------------------------------------------------------------------------------------------------------------------*

class cEnumerator_TexpressionList : public cGenericAbstractEnumerator {
  public : cEnumerator_TexpressionList (const GALGAS_TexpressionList & inEnumeratedObject,
                                        const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_Tvalue current_mValue (LOCATION_ARGS) const ;
  public : class GALGAS_Ttype current_mType (LOCATION_ARGS) const ;
//--- Current element access
  public : class GALGAS_TexpressionList_2D_element current (LOCATION_ARGS) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_TexpressionList ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         @TexpressionList_2D_element struct                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_TexpressionList_2D_element : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_Tvalue mAttribute_mValue ;
  public : GALGAS_Ttype mAttribute_mType ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default constructor
  public : GALGAS_TexpressionList_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_TexpressionList_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS_TexpressionList_2D_element (const GALGAS_Tvalue & in_mValue,
                                              const GALGAS_Ttype & in_mType) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_TexpressionList_2D_element extractObject (const GALGAS_object & inObject,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_TexpressionList_2D_element constructor_new (const class GALGAS_Tvalue & inOperand0,
                                                                     const class GALGAS_Ttype & inOperand1
                                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_TexpressionList_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_Ttype reader_mType (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_Tvalue reader_mValue (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_TexpressionList_2D_element class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_TexpressionList_2D_element ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                @TenumationList list                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_TenumationList : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public : GALGAS_TenumationList (void) ;

//--------------------------------- List constructor used by listmap
  public : GALGAS_TenumationList (cSharedList * inSharedListPtr) ;

//--------------------------------- Element constructor used by listmap
  public : static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                  const class GALGAS_Tvalue & in_mEnumeratedValue,
                                                  const class GALGAS_string & in_mPrefix
                                                  COMMA_LOCATION_ARGS) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_TenumationList extractObject (const GALGAS_object & inObject,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_TenumationList constructor_emptyList (LOCATION_ARGS) ;

  public : static GALGAS_TenumationList constructor_listWithValue (const class GALGAS_Tvalue & inOperand0,
                                                                   const class GALGAS_string & inOperand1
                                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public : VIRTUAL_IN_DEBUG void dotAssign_operation (const GALGAS_TenumationList inOperand
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public : VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_Tvalue & inOperand0,
                                                      const class GALGAS_string & inOperand1
                                                      COMMA_LOCATION_ARGS) ;
//--------------------------------- . (concat) operator
  public : VIRTUAL_IN_DEBUG GALGAS_TenumationList operator_concat (const GALGAS_TenumationList & inOperand
                                                                   COMMA_LOCATION_ARGS) const ;

//--------------------------------- + operator
  public : VIRTUAL_IN_DEBUG GALGAS_TenumationList add_operation (const GALGAS_TenumationList & inOperand,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void modifier_insertAtIndex (class GALGAS_Tvalue constinArgument0,
                                                         class GALGAS_string constinArgument1,
                                                         class GALGAS_uint constinArgument2,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_popFirst (class GALGAS_Tvalue & outArgument0,
                                                    class GALGAS_string & outArgument1,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_popLast (class GALGAS_Tvalue & outArgument0,
                                                   class GALGAS_string & outArgument1,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_removeAtIndex (class GALGAS_Tvalue & outArgument0,
                                                         class GALGAS_string & outArgument1,
                                                         class GALGAS_uint constinArgument2,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_first (class GALGAS_Tvalue & outArgument0,
                                               class GALGAS_string & outArgument1,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_last (class GALGAS_Tvalue & outArgument0,
                                              class GALGAS_string & outArgument1,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_Tvalue reader_mEnumeratedValueAtIndex (const class GALGAS_uint & constinOperand0,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string reader_mPrefixAtIndex (const class GALGAS_uint & constinOperand0,
                                                                       C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_TenumationList reader_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                                 C_Compiler * inCompiler
                                                                                 COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_TenumationList reader_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                                 C_Compiler * inCompiler
                                                                                 COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
//--------------------------------- Friend

  friend class cEnumerator_TenumationList ;
 
} ; // End of GALGAS_TenumationList class

//---------------------------------------------------------------------------------------------------------------------*
//   Enumerator declaration                                                    *
//---------------------------------------------------------------------------------------------------------------------*

class cEnumerator_TenumationList : public cGenericAbstractEnumerator {
  public : cEnumerator_TenumationList (const GALGAS_TenumationList & inEnumeratedObject,
                                       const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_Tvalue current_mEnumeratedValue (LOCATION_ARGS) const ;
  public : class GALGAS_string current_mPrefix (LOCATION_ARGS) const ;
//--- Current element access
  public : class GALGAS_TenumationList_2D_element current (LOCATION_ARGS) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_TenumationList ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          @TenumationList_2D_element struct                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_TenumationList_2D_element : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_Tvalue mAttribute_mEnumeratedValue ;
  public : GALGAS_string mAttribute_mPrefix ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_TenumationList_2D_element constructor_default (LOCATION_ARGS) ;

//--------------------------------- Default constructor
  public : GALGAS_TenumationList_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_TenumationList_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS_TenumationList_2D_element (const GALGAS_Tvalue & in_mEnumeratedValue,
                                             const GALGAS_string & in_mPrefix) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_TenumationList_2D_element extractObject (const GALGAS_object & inObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_TenumationList_2D_element constructor_new (const class GALGAS_Tvalue & inOperand0,
                                                                    const class GALGAS_string & inOperand1
                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_TenumationList_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_Tvalue reader_mEnumeratedValue (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string reader_mPrefix (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_TenumationList_2D_element class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_TenumationList_2D_element ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                   @TvarPath list                                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_TvarPath : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public : GALGAS_TvarPath (void) ;

//--------------------------------- List constructor used by listmap
  public : GALGAS_TvarPath (cSharedList * inSharedListPtr) ;

//--------------------------------- Element constructor used by listmap
  public : static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                  const class GALGAS_lstring & in_item,
                                                  const class GALGAS_lstring & in_key,
                                                  const class GALGAS_lsint & in_idx
                                                  COMMA_LOCATION_ARGS) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_TvarPath extractObject (const GALGAS_object & inObject,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_TvarPath constructor_emptyList (LOCATION_ARGS) ;

  public : static GALGAS_TvarPath constructor_listWithValue (const class GALGAS_lstring & inOperand0,
                                                             const class GALGAS_lstring & inOperand1,
                                                             const class GALGAS_lsint & inOperand2
                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public : VIRTUAL_IN_DEBUG void dotAssign_operation (const GALGAS_TvarPath inOperand
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public : VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0,
                                                      const class GALGAS_lstring & inOperand1,
                                                      const class GALGAS_lsint & inOperand2
                                                      COMMA_LOCATION_ARGS) ;
//--------------------------------- . (concat) operator
  public : VIRTUAL_IN_DEBUG GALGAS_TvarPath operator_concat (const GALGAS_TvarPath & inOperand
                                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- + operator
  public : VIRTUAL_IN_DEBUG GALGAS_TvarPath add_operation (const GALGAS_TvarPath & inOperand,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void modifier_insertAtIndex (class GALGAS_lstring constinArgument0,
                                                         class GALGAS_lstring constinArgument1,
                                                         class GALGAS_lsint constinArgument2,
                                                         class GALGAS_uint constinArgument3,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_popFirst (class GALGAS_lstring & outArgument0,
                                                    class GALGAS_lstring & outArgument1,
                                                    class GALGAS_lsint & outArgument2,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_popLast (class GALGAS_lstring & outArgument0,
                                                   class GALGAS_lstring & outArgument1,
                                                   class GALGAS_lsint & outArgument2,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_removeAtIndex (class GALGAS_lstring & outArgument0,
                                                         class GALGAS_lstring & outArgument1,
                                                         class GALGAS_lsint & outArgument2,
                                                         class GALGAS_uint constinArgument3,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_first (class GALGAS_lstring & outArgument0,
                                               class GALGAS_lstring & outArgument1,
                                               class GALGAS_lsint & outArgument2,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_last (class GALGAS_lstring & outArgument0,
                                              class GALGAS_lstring & outArgument1,
                                              class GALGAS_lsint & outArgument2,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_lsint reader_idxAtIndex (const class GALGAS_uint & constinOperand0,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstring reader_itemAtIndex (const class GALGAS_uint & constinOperand0,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstring reader_keyAtIndex (const class GALGAS_uint & constinOperand0,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_TvarPath reader_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                           C_Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_TvarPath reader_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                           C_Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
//--------------------------------- Friend

  friend class cEnumerator_TvarPath ;
 
} ; // End of GALGAS_TvarPath class

//---------------------------------------------------------------------------------------------------------------------*
//   Enumerator declaration                                                    *
//---------------------------------------------------------------------------------------------------------------------*

class cEnumerator_TvarPath : public cGenericAbstractEnumerator {
  public : cEnumerator_TvarPath (const GALGAS_TvarPath & inEnumeratedObject,
                                 const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_lstring current_item (LOCATION_ARGS) const ;
  public : class GALGAS_lstring current_key (LOCATION_ARGS) const ;
  public : class GALGAS_lsint current_idx (LOCATION_ARGS) const ;
//--- Current element access
  public : class GALGAS_TvarPath_2D_element current (LOCATION_ARGS) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_TvarPath ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             @TvarPath_2D_element struct                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_TvarPath_2D_element : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_lstring mAttribute_item ;
  public : GALGAS_lstring mAttribute_key ;
  public : GALGAS_lsint mAttribute_idx ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_TvarPath_2D_element constructor_default (LOCATION_ARGS) ;

//--------------------------------- Default constructor
  public : GALGAS_TvarPath_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_TvarPath_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS_TvarPath_2D_element (const GALGAS_lstring & in_item,
                                       const GALGAS_lstring & in_key,
                                       const GALGAS_lsint & in_idx) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_TvarPath_2D_element extractObject (const GALGAS_object & inObject,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_TvarPath_2D_element constructor_new (const class GALGAS_lstring & inOperand0,
                                                              const class GALGAS_lstring & inOperand1,
                                                              const class GALGAS_lsint & inOperand2
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_TvarPath_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_lsint reader_idx (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstring reader_item (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstring reader_key (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_TvarPath_2D_element class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_TvarPath_2D_element ;


#ifndef template_5F_scanner_CLASS_DEFINED
#define template_5F_scanner_CLASS_DEFINED

//---------------------------------------------------------------------------------------------------------------------*

#include "galgas2/C_Lexique.h"
#include "galgas2/predefined-types.h"

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                    E X T E R N    R O U T I N E S                                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                    E X T E R N    F U N C T I O N S                                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       T O K E N    C L A S S                                                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cTokenFor_template_5F_scanner : public cToken {
  public : C_String mLexicalAttribute_a_5F_string ;
  public : double mLexicalAttribute_floatValue ;
  public : C_String mLexicalAttribute_functionContent ;
  public : C_String mLexicalAttribute_identifierString ;
  public : int64_t mLexicalAttribute_sint_36__34_value ;
  public : C_String mLexicalAttribute_tokenString ;

  public : cTokenFor_template_5F_scanner (void) ;
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                     S C A N N E R    C L A S S                                                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class C_Lexique_template_5F_scanner : public C_Lexique {
//--- Constructors
  public : C_Lexique_template_5F_scanner (C_Compiler * inCallerCompiler,
                       const C_String & inDependencyFileExtension,
                       const C_String & inDependencyFilePath,
                       const C_String & inSourceFileName
                       COMMA_LOCATION_ARGS) ;

  public : C_Lexique_template_5F_scanner (C_Compiler * inCallerCompiler,
                       const C_String & inSourceString,
                       const C_String & inStringForError
                       COMMA_LOCATION_ARGS) ;

//--- Instrospection
  public : static GALGAS_stringlist symbols (LOCATION_ARGS) ;

//--- Declaring a protected virtual destructor enables the compiler to raise
//    an error if a direct delete is performed; only the static method
//    C_SharedObject::detachPointer may invoke delete.
  #ifndef DO_NOT_GENERATE_CHECKINGS
    protected : virtual ~ C_Lexique_template_5F_scanner (void) {}
  #endif

//--- Scanner mode for template scanner
  private : int32_t mMatchedTemplateDelimiterIndex ;



//--- Terminal symbols enumeration
  public : enum {kToken_,
   kToken_identifier,
   kToken_functionContent,
   kToken_literal_5F_double,
   kToken_signed_5F_literal_5F_integer_36__34_,
   kToken__2E_,
   kToken__2E__3D_,
   kToken__2E__2E__2E_,
   kToken__3C_,
   kToken__3C__3D_,
   kToken__3C__3C_,
   kToken_string,
   kToken_comment,
   kToken_after,
   kToken_before,
   kToken_between,
   kToken_block,
   kToken_by,
   kToken_call,
   kToken_default,
   kToken_display,
   kToken_do,
   kToken_else,
   kToken_elsif,
   kToken_emptylist,
   kToken_emptymap,
   kToken_end,
   kToken_error,
   kToken_exists,
   kToken_false,
   kToken_for,
   kToken_foreach,
   kToken_from,
   kToken_function,
   kToken_here,
   kToken_if,
   kToken_in,
   kToken_list,
   kToken_listof,
   kToken_let,
   kToken_loop,
   kToken_mapof,
   kToken_mod,
   kToken_no,
   kToken_not,
   kToken_or,
   kToken_prefixedby,
   kToken_return,
   kToken_sort,
   kToken_template,
   kToken_then,
   kToken_to,
   kToken_true,
   kToken_typeof,
   kToken_yes,
   kToken_warning,
   kToken_while,
   kToken_write,
   kToken__2A_,
   kToken__7C_,
   kToken__2C_,
   kToken__2B_,
   kToken__2D__2D_,
   kToken__3A__3A_,
   kToken__3E_,
   kToken__3B_,
   kToken__3A_,
   kToken__2D_,
   kToken__28_,
   kToken__29_,
   kToken__2D__3E_,
   kToken__3F_,
   kToken__3D__3D_,
   kToken__3F__3F_,
   kToken__21_,
   kToken__3A__3D_,
   kToken__2B__2B_,
   kToken__5B_,
   kToken__5D_,
   kToken__2B__3D_,
   kToken__3F__21_,
   kToken__21__3F_,
   kToken__2F_,
   kToken__21__3D_,
   kToken__3E__3D_,
   kToken__26_,
   kToken__7B_,
   kToken__7D_,
   kToken__2B__3E_,
   kToken__2D__3D_,
   kToken__5E_,
   kToken__3E__3E_,
   kToken__7E_,
   kToken__3C__2D_,
   kToken__40_} ;

//--- Key words table 'goilTemplateKeyWordList'
  public : static int16_t search_into_goilTemplateKeyWordList (const C_String & inSearchedString) ;

//--- Key words table 'galgasDelimitorsList'
  public : static int16_t search_into_galgasDelimitorsList (const C_String & inSearchedString) ;
  

//--- Assign from attribute
  public : GALGAS_lstring synthetizedAttribute_a_5F_string (void) const ;
  public : GALGAS_ldouble synthetizedAttribute_floatValue (void) const ;
  public : GALGAS_lstring synthetizedAttribute_functionContent (void) const ;
  public : GALGAS_lstring synthetizedAttribute_identifierString (void) const ;
  public : GALGAS_lsint_36__34_ synthetizedAttribute_sint_36__34_value (void) const ;
  public : GALGAS_lstring synthetizedAttribute_tokenString (void) const ;


//--- Attribute access
  public : C_String attributeValue_a_5F_string (void) const ;
  public : double attributeValue_floatValue (void) const ;
  public : C_String attributeValue_functionContent (void) const ;
  public : C_String attributeValue_identifierString (void) const ;
  public : int64_t attributeValue_sint_36__34_value (void) const ;
  public : C_String attributeValue_tokenString (void) const ;


//--- Indexing keys

//--- Indexing directory
  protected : virtual C_String indexingDirectory (void) const ;

//--- Parse lexical token
  protected : virtual bool parseLexicalToken (void) ;

//--- Get terminal message
  protected : virtual C_String getMessageForTerminal (const int16_t inTerminalSymbol) const ;

//--- Get terminal count
  public : virtual int16_t terminalVocabularyCount (void) const { return 94 ; }

//--- Get Token String
  public : virtual C_String getCurrentTokenString (const cToken * inTokenPtr) const ;

//--- Enter Token
  protected : void enterToken (const cTokenFor_template_5F_scanner & inToken) ;

//--- Style name for Latex
  protected : virtual C_String styleNameForIndex (const uint32_t inStyleIndex) const ;
  protected : virtual uint32_t styleIndexForTerminal (const int32_t inTerminalIndex) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

#endif
//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                @sortingKeyList list                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_sortingKeyList : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public : GALGAS_sortingKeyList (void) ;

//--------------------------------- List constructor used by listmap
  public : GALGAS_sortingKeyList (cSharedList * inSharedListPtr) ;

//--------------------------------- Element constructor used by listmap
  public : static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                  const class GALGAS_lstring & in_key,
                                                  const class GALGAS_lsint & in_order
                                                  COMMA_LOCATION_ARGS) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_sortingKeyList extractObject (const GALGAS_object & inObject,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_sortingKeyList constructor_emptyList (LOCATION_ARGS) ;

  public : static GALGAS_sortingKeyList constructor_listWithValue (const class GALGAS_lstring & inOperand0,
                                                                   const class GALGAS_lsint & inOperand1
                                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public : VIRTUAL_IN_DEBUG void dotAssign_operation (const GALGAS_sortingKeyList inOperand
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public : VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0,
                                                      const class GALGAS_lsint & inOperand1
                                                      COMMA_LOCATION_ARGS) ;
//--------------------------------- . (concat) operator
  public : VIRTUAL_IN_DEBUG GALGAS_sortingKeyList operator_concat (const GALGAS_sortingKeyList & inOperand
                                                                   COMMA_LOCATION_ARGS) const ;

//--------------------------------- + operator
  public : VIRTUAL_IN_DEBUG GALGAS_sortingKeyList add_operation (const GALGAS_sortingKeyList & inOperand,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void modifier_insertAtIndex (class GALGAS_lstring constinArgument0,
                                                         class GALGAS_lsint constinArgument1,
                                                         class GALGAS_uint constinArgument2,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_popFirst (class GALGAS_lstring & outArgument0,
                                                    class GALGAS_lsint & outArgument1,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_popLast (class GALGAS_lstring & outArgument0,
                                                   class GALGAS_lsint & outArgument1,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_removeAtIndex (class GALGAS_lstring & outArgument0,
                                                         class GALGAS_lsint & outArgument1,
                                                         class GALGAS_uint constinArgument2,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_first (class GALGAS_lstring & outArgument0,
                                               class GALGAS_lsint & outArgument1,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_last (class GALGAS_lstring & outArgument0,
                                              class GALGAS_lsint & outArgument1,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_lstring reader_keyAtIndex (const class GALGAS_uint & constinOperand0,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lsint reader_orderAtIndex (const class GALGAS_uint & constinOperand0,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_sortingKeyList reader_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                                 C_Compiler * inCompiler
                                                                                 COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_sortingKeyList reader_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                                 C_Compiler * inCompiler
                                                                                 COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
//--------------------------------- Friend

  friend class cEnumerator_sortingKeyList ;
 
} ; // End of GALGAS_sortingKeyList class

//---------------------------------------------------------------------------------------------------------------------*
//   Enumerator declaration                                                    *
//---------------------------------------------------------------------------------------------------------------------*

class cEnumerator_sortingKeyList : public cGenericAbstractEnumerator {
  public : cEnumerator_sortingKeyList (const GALGAS_sortingKeyList & inEnumeratedObject,
                                       const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_lstring current_key (LOCATION_ARGS) const ;
  public : class GALGAS_lsint current_order (LOCATION_ARGS) const ;
//--- Current element access
  public : class GALGAS_sortingKeyList_2D_element current (LOCATION_ARGS) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_sortingKeyList ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          @sortingKeyList_2D_element struct                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_sortingKeyList_2D_element : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_lstring mAttribute_key ;
  public : GALGAS_lsint mAttribute_order ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_sortingKeyList_2D_element constructor_default (LOCATION_ARGS) ;

//--------------------------------- Default constructor
  public : GALGAS_sortingKeyList_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_sortingKeyList_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS_sortingKeyList_2D_element (const GALGAS_lstring & in_key,
                                             const GALGAS_lsint & in_order) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_sortingKeyList_2D_element extractObject (const GALGAS_object & inObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_sortingKeyList_2D_element constructor_new (const class GALGAS_lstring & inOperand0,
                                                                    const class GALGAS_lsint & inOperand1
                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_sortingKeyList_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_lstring reader_key (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lsint reader_order (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_sortingKeyList_2D_element class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_sortingKeyList_2D_element ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Parser class 'template_parser' declaration                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cParser_template_5F_parser {
//--- Virtual destructor
  public : virtual ~ cParser_template_5F_parser (void) {}

//--- Non terminal declarations
  protected : virtual void nt_expression_ (const class GALGAS_string constinArgument0,
                                           const class GALGAS_string constinArgument1,
                                           const class GALGAS_string constinArgument2,
                                           const class GALGAS_TfieldMap constinArgument3,
                                           class GALGAS_Tvalue & outArgument4,
                                           class GALGAS_Ttype & outArgument5,
                                           class C_Lexique_template_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_expression_parse (class C_Lexique_template_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_goil_5F_template_5F_start_5F_symbol_ (const class GALGAS_string constinArgument0,
                                                                    const class GALGAS_string constinArgument1,
                                                                    const class GALGAS_string constinArgument2,
                                                                    class GALGAS_TfieldMap inArgument3,
                                                                    class GALGAS_string & ioArgument4,
                                                                    class GALGAS_Tvalue & outArgument5,
                                                                    class GALGAS_Ttype & outArgument6,
                                                                    class C_Lexique_template_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_goil_5F_template_5F_start_5F_symbol_parse (class C_Lexique_template_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_sorting_5F_order_ (class GALGAS_lsint & outArgument0,
                                                 class C_Lexique_template_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_sorting_5F_order_parse (class C_Lexique_template_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_template_5F_file_5F_name_ (const class GALGAS_string constinArgument0,
                                                         const class GALGAS_string constinArgument1,
                                                         const class GALGAS_string constinArgument2,
                                                         const class GALGAS_TfieldMap constinArgument3,
                                                         class GALGAS_lstring & outArgument4,
                                                         class C_Lexique_template_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_template_5F_file_5F_name_parse (class C_Lexique_template_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_template_5F_instruction_ (const class GALGAS_string constinArgument0,
                                                        const class GALGAS_string constinArgument1,
                                                        const class GALGAS_string constinArgument2,
                                                        class GALGAS_TfieldMap & ioArgument3,
                                                        class GALGAS_string & ioArgument4,
                                                        class GALGAS_Tvalue & outArgument5,
                                                        class GALGAS_Ttype & outArgument6,
                                                        class C_Lexique_template_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_template_5F_instruction_parse (class C_Lexique_template_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_template_5F_instruction_5F_list_ (const class GALGAS_string constinArgument0,
                                                                const class GALGAS_string constinArgument1,
                                                                const class GALGAS_string constinArgument2,
                                                                class GALGAS_TfieldMap & ioArgument3,
                                                                class GALGAS_string & ioArgument4,
                                                                class GALGAS_Tvalue & outArgument5,
                                                                class GALGAS_Ttype & outArgument6,
                                                                class C_Lexique_template_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_template_5F_instruction_5F_list_parse (class C_Lexique_template_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_variable_ (const class GALGAS_string constinArgument0,
                                         const class GALGAS_string constinArgument1,
                                         const class GALGAS_string constinArgument2,
                                         const class GALGAS_TfieldMap constinArgument3,
                                         class GALGAS_TvarPath & outArgument4,
                                         class C_Lexique_template_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_variable_parse (class C_Lexique_template_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_variable_5F_or_5F_here_ (const class GALGAS_string constinArgument0,
                                                       const class GALGAS_string constinArgument1,
                                                       const class GALGAS_string constinArgument2,
                                                       const class GALGAS_TfieldMap constinArgument3,
                                                       class GALGAS_location & outArgument4,
                                                       class C_Lexique_template_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_variable_5F_or_5F_here_parse (class C_Lexique_template_5F_scanner * inLexique) = 0 ;


//--- Rule declarations
  protected : void rule_template_5F_parser_template_5F_instruction_i0_ (const GALGAS_string constinArgument0,
                                                                        const GALGAS_string constinArgument1,
                                                                        const GALGAS_string constinArgument2,
                                                                        GALGAS_TfieldMap & ioArgument3,
                                                                        GALGAS_string & ioArgument4,
                                                                        GALGAS_Tvalue & outArgument5,
                                                                        GALGAS_Ttype & outArgument6,
                                                                        C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_parser_template_5F_instruction_i0_parse (C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_parser_template_5F_instruction_i1_ (const GALGAS_string constinArgument0,
                                                                        const GALGAS_string constinArgument1,
                                                                        const GALGAS_string constinArgument2,
                                                                        GALGAS_TfieldMap & ioArgument3,
                                                                        GALGAS_string & ioArgument4,
                                                                        GALGAS_Tvalue & outArgument5,
                                                                        GALGAS_Ttype & outArgument6,
                                                                        C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_parser_template_5F_instruction_i1_parse (C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_parser_template_5F_file_5F_name_i2_ (const GALGAS_string constinArgument0,
                                                                         const GALGAS_string constinArgument1,
                                                                         const GALGAS_string constinArgument2,
                                                                         const GALGAS_TfieldMap constinArgument3,
                                                                         GALGAS_lstring & outArgument4,
                                                                         C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_parser_template_5F_file_5F_name_i2_parse (C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_parser_template_5F_instruction_i3_ (const GALGAS_string constinArgument0,
                                                                        const GALGAS_string constinArgument1,
                                                                        const GALGAS_string constinArgument2,
                                                                        GALGAS_TfieldMap & ioArgument3,
                                                                        GALGAS_string & ioArgument4,
                                                                        GALGAS_Tvalue & outArgument5,
                                                                        GALGAS_Ttype & outArgument6,
                                                                        C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_parser_template_5F_instruction_i3_parse (C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_parser_template_5F_instruction_i4_ (const GALGAS_string constinArgument0,
                                                                        const GALGAS_string constinArgument1,
                                                                        const GALGAS_string constinArgument2,
                                                                        GALGAS_TfieldMap & ioArgument3,
                                                                        GALGAS_string & ioArgument4,
                                                                        GALGAS_Tvalue & outArgument5,
                                                                        GALGAS_Ttype & outArgument6,
                                                                        C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_parser_template_5F_instruction_i4_parse (C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_parser_template_5F_instruction_i5_ (const GALGAS_string constinArgument0,
                                                                        const GALGAS_string constinArgument1,
                                                                        const GALGAS_string constinArgument2,
                                                                        GALGAS_TfieldMap & ioArgument3,
                                                                        GALGAS_string & ioArgument4,
                                                                        GALGAS_Tvalue & outArgument5,
                                                                        GALGAS_Ttype & outArgument6,
                                                                        C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_parser_template_5F_instruction_i5_parse (C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_parser_template_5F_instruction_i6_ (const GALGAS_string constinArgument0,
                                                                        const GALGAS_string constinArgument1,
                                                                        const GALGAS_string constinArgument2,
                                                                        GALGAS_TfieldMap & ioArgument3,
                                                                        GALGAS_string & ioArgument4,
                                                                        GALGAS_Tvalue & outArgument5,
                                                                        GALGAS_Ttype & outArgument6,
                                                                        C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_parser_template_5F_instruction_i6_parse (C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_parser_template_5F_instruction_i7_ (const GALGAS_string constinArgument0,
                                                                        const GALGAS_string constinArgument1,
                                                                        const GALGAS_string constinArgument2,
                                                                        GALGAS_TfieldMap & ioArgument3,
                                                                        GALGAS_string & ioArgument4,
                                                                        GALGAS_Tvalue & outArgument5,
                                                                        GALGAS_Ttype & outArgument6,
                                                                        C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_parser_template_5F_instruction_i7_parse (C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_parser_template_5F_instruction_i8_ (const GALGAS_string constinArgument0,
                                                                        const GALGAS_string constinArgument1,
                                                                        const GALGAS_string constinArgument2,
                                                                        GALGAS_TfieldMap & ioArgument3,
                                                                        GALGAS_string & ioArgument4,
                                                                        GALGAS_Tvalue & outArgument5,
                                                                        GALGAS_Ttype & outArgument6,
                                                                        C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_parser_template_5F_instruction_i8_parse (C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_parser_template_5F_instruction_5F_list_i9_ (const GALGAS_string constinArgument0,
                                                                                const GALGAS_string constinArgument1,
                                                                                const GALGAS_string constinArgument2,
                                                                                GALGAS_TfieldMap & ioArgument3,
                                                                                GALGAS_string & ioArgument4,
                                                                                GALGAS_Tvalue & outArgument5,
                                                                                GALGAS_Ttype & outArgument6,
                                                                                C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_parser_template_5F_instruction_5F_list_i9_parse (C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_parser_goil_5F_template_5F_start_5F_symbol_i10_ (const GALGAS_string constinArgument0,
                                                                                     const GALGAS_string constinArgument1,
                                                                                     const GALGAS_string constinArgument2,
                                                                                     GALGAS_TfieldMap inArgument3,
                                                                                     GALGAS_string & ioArgument4,
                                                                                     GALGAS_Tvalue & outArgument5,
                                                                                     GALGAS_Ttype & outArgument6,
                                                                                     C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_parser_goil_5F_template_5F_start_5F_symbol_i10_parse (C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_parser_template_5F_instruction_i11_ (const GALGAS_string constinArgument0,
                                                                         const GALGAS_string constinArgument1,
                                                                         const GALGAS_string constinArgument2,
                                                                         GALGAS_TfieldMap & ioArgument3,
                                                                         GALGAS_string & ioArgument4,
                                                                         GALGAS_Tvalue & outArgument5,
                                                                         GALGAS_Ttype & outArgument6,
                                                                         C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_parser_template_5F_instruction_i11_parse (C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_parser_template_5F_instruction_i12_ (const GALGAS_string constinArgument0,
                                                                         const GALGAS_string constinArgument1,
                                                                         const GALGAS_string constinArgument2,
                                                                         GALGAS_TfieldMap & ioArgument3,
                                                                         GALGAS_string & ioArgument4,
                                                                         GALGAS_Tvalue & outArgument5,
                                                                         GALGAS_Ttype & outArgument6,
                                                                         C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_parser_template_5F_instruction_i12_parse (C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_parser_template_5F_instruction_i13_ (const GALGAS_string constinArgument0,
                                                                         const GALGAS_string constinArgument1,
                                                                         const GALGAS_string constinArgument2,
                                                                         GALGAS_TfieldMap & ioArgument3,
                                                                         GALGAS_string & ioArgument4,
                                                                         GALGAS_Tvalue & outArgument5,
                                                                         GALGAS_Ttype & outArgument6,
                                                                         C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_parser_template_5F_instruction_i13_parse (C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_parser_template_5F_instruction_i14_ (const GALGAS_string constinArgument0,
                                                                         const GALGAS_string constinArgument1,
                                                                         const GALGAS_string constinArgument2,
                                                                         GALGAS_TfieldMap & ioArgument3,
                                                                         GALGAS_string & ioArgument4,
                                                                         GALGAS_Tvalue & outArgument5,
                                                                         GALGAS_Ttype & outArgument6,
                                                                         C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_parser_template_5F_instruction_i14_parse (C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_parser_variable_5F_or_5F_here_i15_ (const GALGAS_string constinArgument0,
                                                                        const GALGAS_string constinArgument1,
                                                                        const GALGAS_string constinArgument2,
                                                                        const GALGAS_TfieldMap constinArgument3,
                                                                        GALGAS_location & outArgument4,
                                                                        C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_parser_variable_5F_or_5F_here_i15_parse (C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_parser_template_5F_instruction_i16_ (const GALGAS_string constinArgument0,
                                                                         const GALGAS_string constinArgument1,
                                                                         const GALGAS_string constinArgument2,
                                                                         GALGAS_TfieldMap & ioArgument3,
                                                                         GALGAS_string & ioArgument4,
                                                                         GALGAS_Tvalue & outArgument5,
                                                                         GALGAS_Ttype & outArgument6,
                                                                         C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_parser_template_5F_instruction_i16_parse (C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_parser_template_5F_instruction_i17_ (const GALGAS_string constinArgument0,
                                                                         const GALGAS_string constinArgument1,
                                                                         const GALGAS_string constinArgument2,
                                                                         GALGAS_TfieldMap & ioArgument3,
                                                                         GALGAS_string & ioArgument4,
                                                                         GALGAS_Tvalue & outArgument5,
                                                                         GALGAS_Ttype & outArgument6,
                                                                         C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_parser_template_5F_instruction_i17_parse (C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_parser_template_5F_instruction_i18_ (const GALGAS_string constinArgument0,
                                                                         const GALGAS_string constinArgument1,
                                                                         const GALGAS_string constinArgument2,
                                                                         GALGAS_TfieldMap & ioArgument3,
                                                                         GALGAS_string & ioArgument4,
                                                                         GALGAS_Tvalue & outArgument5,
                                                                         GALGAS_Ttype & outArgument6,
                                                                         C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_parser_template_5F_instruction_i18_parse (C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_parser_sorting_5F_order_i19_ (GALGAS_lsint & outArgument0,
                                                                  C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_parser_sorting_5F_order_i19_parse (C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_parser_template_5F_instruction_i20_ (const GALGAS_string constinArgument0,
                                                                         const GALGAS_string constinArgument1,
                                                                         const GALGAS_string constinArgument2,
                                                                         GALGAS_TfieldMap & ioArgument3,
                                                                         GALGAS_string & ioArgument4,
                                                                         GALGAS_Tvalue & outArgument5,
                                                                         GALGAS_Ttype & outArgument6,
                                                                         C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_parser_template_5F_instruction_i20_parse (C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_parser_variable_i21_ (const GALGAS_string constinArgument0,
                                                          const GALGAS_string constinArgument1,
                                                          const GALGAS_string constinArgument2,
                                                          const GALGAS_TfieldMap constinArgument3,
                                                          GALGAS_TvarPath & outArgument4,
                                                          C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_parser_variable_i21_parse (C_Lexique_template_5F_scanner * inLexique) ;



//--- Select methods
  protected : virtual int32_t select_template_5F_parser_0 (C_Lexique_template_5F_scanner *) = 0 ;

  protected : virtual int32_t select_template_5F_parser_1 (C_Lexique_template_5F_scanner *) = 0 ;

  protected : virtual int32_t select_template_5F_parser_2 (C_Lexique_template_5F_scanner *) = 0 ;

  protected : virtual int32_t select_template_5F_parser_3 (C_Lexique_template_5F_scanner *) = 0 ;

  protected : virtual int32_t select_template_5F_parser_4 (C_Lexique_template_5F_scanner *) = 0 ;

  protected : virtual int32_t select_template_5F_parser_5 (C_Lexique_template_5F_scanner *) = 0 ;

  protected : virtual int32_t select_template_5F_parser_6 (C_Lexique_template_5F_scanner *) = 0 ;

  protected : virtual int32_t select_template_5F_parser_7 (C_Lexique_template_5F_scanner *) = 0 ;

  protected : virtual int32_t select_template_5F_parser_8 (C_Lexique_template_5F_scanner *) = 0 ;

  protected : virtual int32_t select_template_5F_parser_9 (C_Lexique_template_5F_scanner *) = 0 ;

  protected : virtual int32_t select_template_5F_parser_10 (C_Lexique_template_5F_scanner *) = 0 ;

  protected : virtual int32_t select_template_5F_parser_11 (C_Lexique_template_5F_scanner *) = 0 ;

  protected : virtual int32_t select_template_5F_parser_12 (C_Lexique_template_5F_scanner *) = 0 ;

  protected : virtual int32_t select_template_5F_parser_13 (C_Lexique_template_5F_scanner *) = 0 ;

  protected : virtual int32_t select_template_5F_parser_14 (C_Lexique_template_5F_scanner *) = 0 ;

  protected : virtual int32_t select_template_5F_parser_15 (C_Lexique_template_5F_scanner *) = 0 ;

  protected : virtual int32_t select_template_5F_parser_16 (C_Lexique_template_5F_scanner *) = 0 ;

  protected : virtual int32_t select_template_5F_parser_17 (C_Lexique_template_5F_scanner *) = 0 ;

  protected : virtual int32_t select_template_5F_parser_18 (C_Lexique_template_5F_scanner *) = 0 ;

  protected : virtual int32_t select_template_5F_parser_19 (C_Lexique_template_5F_scanner *) = 0 ;

  protected : virtual int32_t select_template_5F_parser_20 (C_Lexique_template_5F_scanner *) = 0 ;

  protected : virtual int32_t select_template_5F_parser_21 (C_Lexique_template_5F_scanner *) = 0 ;

  protected : virtual int32_t select_template_5F_parser_22 (C_Lexique_template_5F_scanner *) = 0 ;

  protected : virtual int32_t select_template_5F_parser_23 (C_Lexique_template_5F_scanner *) = 0 ;

  protected : virtual int32_t select_template_5F_parser_24 (C_Lexique_template_5F_scanner *) = 0 ;

  protected : virtual int32_t select_template_5F_parser_25 (C_Lexique_template_5F_scanner *) = 0 ;

  protected : virtual int32_t select_template_5F_parser_26 (C_Lexique_template_5F_scanner *) = 0 ;

  protected : virtual int32_t select_template_5F_parser_27 (C_Lexique_template_5F_scanner *) = 0 ;


} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Function 'dummyFunction'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_Tfunction function_dummyFunction (class C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Function 'emptyLString'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_lstring function_emptyLString (class C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                Function 'fullPrefix'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_string function_fullPrefix (const class GALGAS_TfieldMap & constinArgument0,
                                         const class GALGAS_lstring & constinArgument1,
                                         class C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Function 'lstringWith'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_lstring function_lstringWith (class GALGAS_string inArgument0,
                                           class C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             Function 'valueWithString'                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_Tvalue function_valueWithString (const class GALGAS_string & constinArgument0,
                                              const class GALGAS_lstring & constinArgument1,
                                              class C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Function 'valueWithVoid'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_Tvalue function_valueWithVoid (class C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                  Category Reader '@Ttype messageGoilTemplateType'                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_string categoryReader_messageGoilTemplateType (const class GALGAS_Ttype & inObject,
                                                            class C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Parser class 'template_expression_parser' declaration                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cParser_template_5F_expression_5F_parser {
//--- Virtual destructor
  public : virtual ~ cParser_template_5F_expression_5F_parser (void) {}

//--- Non terminal declarations
  protected : virtual void nt_expression_ (const class GALGAS_string constinArgument0,
                                           const class GALGAS_string constinArgument1,
                                           const class GALGAS_string constinArgument2,
                                           const class GALGAS_TfieldMap constinArgument3,
                                           class GALGAS_Tvalue & outArgument4,
                                           class GALGAS_Ttype & outArgument5,
                                           class C_Lexique_template_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_expression_parse (class C_Lexique_template_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_factor_ (const class GALGAS_string constinArgument0,
                                       const class GALGAS_string constinArgument1,
                                       const class GALGAS_string constinArgument2,
                                       const class GALGAS_TfieldMap constinArgument3,
                                       class GALGAS_Tvalue & outArgument4,
                                       class GALGAS_Ttype & outArgument5,
                                       class C_Lexique_template_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_factor_parse (class C_Lexique_template_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_relation_5F_factor_ (const class GALGAS_string constinArgument0,
                                                   const class GALGAS_string constinArgument1,
                                                   const class GALGAS_string constinArgument2,
                                                   const class GALGAS_TfieldMap constinArgument3,
                                                   class GALGAS_Tvalue & outArgument4,
                                                   class GALGAS_Ttype & outArgument5,
                                                   class C_Lexique_template_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_relation_5F_factor_parse (class C_Lexique_template_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_relation_5F_term_ (const class GALGAS_string constinArgument0,
                                                 const class GALGAS_string constinArgument1,
                                                 const class GALGAS_string constinArgument2,
                                                 const class GALGAS_TfieldMap constinArgument3,
                                                 class GALGAS_Tvalue & outArgument4,
                                                 class GALGAS_Ttype & outArgument5,
                                                 class C_Lexique_template_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_relation_5F_term_parse (class C_Lexique_template_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_simple_5F_expression_ (const class GALGAS_string constinArgument0,
                                                     const class GALGAS_string constinArgument1,
                                                     const class GALGAS_string constinArgument2,
                                                     const class GALGAS_TfieldMap constinArgument3,
                                                     class GALGAS_Tvalue & outArgument4,
                                                     class GALGAS_Ttype & outArgument5,
                                                     class C_Lexique_template_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_simple_5F_expression_parse (class C_Lexique_template_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_term_ (const class GALGAS_string constinArgument0,
                                     const class GALGAS_string constinArgument1,
                                     const class GALGAS_string constinArgument2,
                                     const class GALGAS_TfieldMap constinArgument3,
                                     class GALGAS_Tvalue & outArgument4,
                                     class GALGAS_Ttype & outArgument5,
                                     class C_Lexique_template_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_term_parse (class C_Lexique_template_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_variable_ (const class GALGAS_string constinArgument0,
                                         const class GALGAS_string constinArgument1,
                                         const class GALGAS_string constinArgument2,
                                         const class GALGAS_TfieldMap constinArgument3,
                                         class GALGAS_TvarPath & outArgument4,
                                         class C_Lexique_template_5F_scanner * inLexique) = 0 ;

  protected : virtual void nt_variable_parse (class C_Lexique_template_5F_scanner * inLexique) = 0 ;


//--- Rule declarations
  protected : void rule_template_5F_expression_5F_parser_expression_i0_ (const GALGAS_string constinArgument0,
                                                                         const GALGAS_string constinArgument1,
                                                                         const GALGAS_string constinArgument2,
                                                                         const GALGAS_TfieldMap constinArgument3,
                                                                         GALGAS_Tvalue & outArgument4,
                                                                         GALGAS_Ttype & outArgument5,
                                                                         C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_expression_5F_parser_expression_i0_parse (C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_expression_5F_parser_relation_5F_term_i1_ (const GALGAS_string constinArgument0,
                                                                               const GALGAS_string constinArgument1,
                                                                               const GALGAS_string constinArgument2,
                                                                               const GALGAS_TfieldMap constinArgument3,
                                                                               GALGAS_Tvalue & outArgument4,
                                                                               GALGAS_Ttype & outArgument5,
                                                                               C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_expression_5F_parser_relation_5F_term_i1_parse (C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_expression_5F_parser_relation_5F_factor_i2_ (const GALGAS_string constinArgument0,
                                                                                 const GALGAS_string constinArgument1,
                                                                                 const GALGAS_string constinArgument2,
                                                                                 const GALGAS_TfieldMap constinArgument3,
                                                                                 GALGAS_Tvalue & outArgument4,
                                                                                 GALGAS_Ttype & outArgument5,
                                                                                 C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_expression_5F_parser_relation_5F_factor_i2_parse (C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_expression_5F_parser_simple_5F_expression_i3_ (const GALGAS_string constinArgument0,
                                                                                   const GALGAS_string constinArgument1,
                                                                                   const GALGAS_string constinArgument2,
                                                                                   const GALGAS_TfieldMap constinArgument3,
                                                                                   GALGAS_Tvalue & outArgument4,
                                                                                   GALGAS_Ttype & outArgument5,
                                                                                   C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_expression_5F_parser_simple_5F_expression_i3_parse (C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_expression_5F_parser_term_i4_ (const GALGAS_string constinArgument0,
                                                                   const GALGAS_string constinArgument1,
                                                                   const GALGAS_string constinArgument2,
                                                                   const GALGAS_TfieldMap constinArgument3,
                                                                   GALGAS_Tvalue & outArgument4,
                                                                   GALGAS_Ttype & outArgument5,
                                                                   C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_expression_5F_parser_term_i4_parse (C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_expression_5F_parser_factor_i5_ (const GALGAS_string constinArgument0,
                                                                     const GALGAS_string constinArgument1,
                                                                     const GALGAS_string constinArgument2,
                                                                     const GALGAS_TfieldMap constinArgument3,
                                                                     GALGAS_Tvalue & outArgument4,
                                                                     GALGAS_Ttype & outArgument5,
                                                                     C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_expression_5F_parser_factor_i5_parse (C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_expression_5F_parser_factor_i6_ (const GALGAS_string constinArgument0,
                                                                     const GALGAS_string constinArgument1,
                                                                     const GALGAS_string constinArgument2,
                                                                     const GALGAS_TfieldMap constinArgument3,
                                                                     GALGAS_Tvalue & outArgument4,
                                                                     GALGAS_Ttype & outArgument5,
                                                                     C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_expression_5F_parser_factor_i6_parse (C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_expression_5F_parser_factor_i7_ (const GALGAS_string constinArgument0,
                                                                     const GALGAS_string constinArgument1,
                                                                     const GALGAS_string constinArgument2,
                                                                     const GALGAS_TfieldMap constinArgument3,
                                                                     GALGAS_Tvalue & outArgument4,
                                                                     GALGAS_Ttype & outArgument5,
                                                                     C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_expression_5F_parser_factor_i7_parse (C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_expression_5F_parser_factor_i8_ (const GALGAS_string constinArgument0,
                                                                     const GALGAS_string constinArgument1,
                                                                     const GALGAS_string constinArgument2,
                                                                     const GALGAS_TfieldMap constinArgument3,
                                                                     GALGAS_Tvalue & outArgument4,
                                                                     GALGAS_Ttype & outArgument5,
                                                                     C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_expression_5F_parser_factor_i8_parse (C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_expression_5F_parser_factor_i9_ (const GALGAS_string constinArgument0,
                                                                     const GALGAS_string constinArgument1,
                                                                     const GALGAS_string constinArgument2,
                                                                     const GALGAS_TfieldMap constinArgument3,
                                                                     GALGAS_Tvalue & outArgument4,
                                                                     GALGAS_Ttype & outArgument5,
                                                                     C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_expression_5F_parser_factor_i9_parse (C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_expression_5F_parser_factor_i10_ (const GALGAS_string constinArgument0,
                                                                      const GALGAS_string constinArgument1,
                                                                      const GALGAS_string constinArgument2,
                                                                      const GALGAS_TfieldMap constinArgument3,
                                                                      GALGAS_Tvalue & outArgument4,
                                                                      GALGAS_Ttype & outArgument5,
                                                                      C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_expression_5F_parser_factor_i10_parse (C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_expression_5F_parser_factor_i11_ (const GALGAS_string constinArgument0,
                                                                      const GALGAS_string constinArgument1,
                                                                      const GALGAS_string constinArgument2,
                                                                      const GALGAS_TfieldMap constinArgument3,
                                                                      GALGAS_Tvalue & outArgument4,
                                                                      GALGAS_Ttype & outArgument5,
                                                                      C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_expression_5F_parser_factor_i11_parse (C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_expression_5F_parser_factor_i12_ (const GALGAS_string constinArgument0,
                                                                      const GALGAS_string constinArgument1,
                                                                      const GALGAS_string constinArgument2,
                                                                      const GALGAS_TfieldMap constinArgument3,
                                                                      GALGAS_Tvalue & outArgument4,
                                                                      GALGAS_Ttype & outArgument5,
                                                                      C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_expression_5F_parser_factor_i12_parse (C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_expression_5F_parser_factor_i13_ (const GALGAS_string constinArgument0,
                                                                      const GALGAS_string constinArgument1,
                                                                      const GALGAS_string constinArgument2,
                                                                      const GALGAS_TfieldMap constinArgument3,
                                                                      GALGAS_Tvalue & outArgument4,
                                                                      GALGAS_Ttype & outArgument5,
                                                                      C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_expression_5F_parser_factor_i13_parse (C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_expression_5F_parser_factor_i14_ (const GALGAS_string constinArgument0,
                                                                      const GALGAS_string constinArgument1,
                                                                      const GALGAS_string constinArgument2,
                                                                      const GALGAS_TfieldMap constinArgument3,
                                                                      GALGAS_Tvalue & outArgument4,
                                                                      GALGAS_Ttype & outArgument5,
                                                                      C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_expression_5F_parser_factor_i14_parse (C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_expression_5F_parser_factor_i15_ (const GALGAS_string constinArgument0,
                                                                      const GALGAS_string constinArgument1,
                                                                      const GALGAS_string constinArgument2,
                                                                      const GALGAS_TfieldMap constinArgument3,
                                                                      GALGAS_Tvalue & outArgument4,
                                                                      GALGAS_Ttype & outArgument5,
                                                                      C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_expression_5F_parser_factor_i15_parse (C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_expression_5F_parser_factor_i16_ (const GALGAS_string constinArgument0,
                                                                      const GALGAS_string constinArgument1,
                                                                      const GALGAS_string constinArgument2,
                                                                      const GALGAS_TfieldMap constinArgument3,
                                                                      GALGAS_Tvalue & outArgument4,
                                                                      GALGAS_Ttype & outArgument5,
                                                                      C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_expression_5F_parser_factor_i16_parse (C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_expression_5F_parser_factor_i17_ (const GALGAS_string constinArgument0,
                                                                      const GALGAS_string constinArgument1,
                                                                      const GALGAS_string constinArgument2,
                                                                      const GALGAS_TfieldMap constinArgument3,
                                                                      GALGAS_Tvalue & outArgument4,
                                                                      GALGAS_Ttype & outArgument5,
                                                                      C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_expression_5F_parser_factor_i17_parse (C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_expression_5F_parser_factor_i18_ (const GALGAS_string constinArgument0,
                                                                      const GALGAS_string constinArgument1,
                                                                      const GALGAS_string constinArgument2,
                                                                      const GALGAS_TfieldMap constinArgument3,
                                                                      GALGAS_Tvalue & outArgument4,
                                                                      GALGAS_Ttype & outArgument5,
                                                                      C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_expression_5F_parser_factor_i18_parse (C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_expression_5F_parser_factor_i19_ (const GALGAS_string constinArgument0,
                                                                      const GALGAS_string constinArgument1,
                                                                      const GALGAS_string constinArgument2,
                                                                      const GALGAS_TfieldMap constinArgument3,
                                                                      GALGAS_Tvalue & outArgument4,
                                                                      GALGAS_Ttype & outArgument5,
                                                                      C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_expression_5F_parser_factor_i19_parse (C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_expression_5F_parser_factor_i20_ (const GALGAS_string constinArgument0,
                                                                      const GALGAS_string constinArgument1,
                                                                      const GALGAS_string constinArgument2,
                                                                      const GALGAS_TfieldMap constinArgument3,
                                                                      GALGAS_Tvalue & outArgument4,
                                                                      GALGAS_Ttype & outArgument5,
                                                                      C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_expression_5F_parser_factor_i20_parse (C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_expression_5F_parser_factor_i21_ (const GALGAS_string constinArgument0,
                                                                      const GALGAS_string constinArgument1,
                                                                      const GALGAS_string constinArgument2,
                                                                      const GALGAS_TfieldMap constinArgument3,
                                                                      GALGAS_Tvalue & outArgument4,
                                                                      GALGAS_Ttype & outArgument5,
                                                                      C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_expression_5F_parser_factor_i21_parse (C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_expression_5F_parser_factor_i22_ (const GALGAS_string constinArgument0,
                                                                      const GALGAS_string constinArgument1,
                                                                      const GALGAS_string constinArgument2,
                                                                      const GALGAS_TfieldMap constinArgument3,
                                                                      GALGAS_Tvalue & outArgument4,
                                                                      GALGAS_Ttype & outArgument5,
                                                                      C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_expression_5F_parser_factor_i22_parse (C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_expression_5F_parser_factor_i23_ (const GALGAS_string constinArgument0,
                                                                      const GALGAS_string constinArgument1,
                                                                      const GALGAS_string constinArgument2,
                                                                      const GALGAS_TfieldMap constinArgument3,
                                                                      GALGAS_Tvalue & outArgument4,
                                                                      GALGAS_Ttype & outArgument5,
                                                                      C_Lexique_template_5F_scanner * inLexique) ;

  protected : void rule_template_5F_expression_5F_parser_factor_i23_parse (C_Lexique_template_5F_scanner * inLexique) ;



//--- Select methods
  protected : virtual int32_t select_template_5F_expression_5F_parser_0 (C_Lexique_template_5F_scanner *) = 0 ;

  protected : virtual int32_t select_template_5F_expression_5F_parser_1 (C_Lexique_template_5F_scanner *) = 0 ;

  protected : virtual int32_t select_template_5F_expression_5F_parser_2 (C_Lexique_template_5F_scanner *) = 0 ;

  protected : virtual int32_t select_template_5F_expression_5F_parser_3 (C_Lexique_template_5F_scanner *) = 0 ;

  protected : virtual int32_t select_template_5F_expression_5F_parser_4 (C_Lexique_template_5F_scanner *) = 0 ;

  protected : virtual int32_t select_template_5F_expression_5F_parser_5 (C_Lexique_template_5F_scanner *) = 0 ;

  protected : virtual int32_t select_template_5F_expression_5F_parser_6 (C_Lexique_template_5F_scanner *) = 0 ;

  protected : virtual int32_t select_template_5F_expression_5F_parser_7 (C_Lexique_template_5F_scanner *) = 0 ;

  protected : virtual int32_t select_template_5F_expression_5F_parser_8 (C_Lexique_template_5F_scanner *) = 0 ;

  protected : virtual int32_t select_template_5F_expression_5F_parser_9 (C_Lexique_template_5F_scanner *) = 0 ;

  protected : virtual int32_t select_template_5F_expression_5F_parser_10 (C_Lexique_template_5F_scanner *) = 0 ;


} ;

//---------------------------------------------------------------------------------------------------------------------*
//  GRAMMAR template_grammar
//---------------------------------------------------------------------------------------------------------------------*

class cGrammar_template_5F_grammar : public cParser_template_5F_parser,
                                     public cParser_template_5F_expression_5F_parser {
//------------------------------------- 'expression' non terminal
//--- 'parse' label
  public : virtual void nt_expression_parse (C_Lexique_template_5F_scanner * inCompiler) ;

//----------- '' label
  public : virtual void nt_expression_ (const GALGAS_string inArgument0,
                                        const GALGAS_string inArgument1,
                                        const GALGAS_string inArgument2,
                                        const GALGAS_TfieldMap inArgument3,
                                        GALGAS_Tvalue & outArgument4,
                                        GALGAS_Ttype & outArgument5,
                                        C_Lexique_template_5F_scanner * inCompiler) ;

//------------------------------------- 'factor' non terminal
//--- 'parse' label
  public : virtual void nt_factor_parse (C_Lexique_template_5F_scanner * inCompiler) ;

//----------- '' label
  public : virtual void nt_factor_ (const GALGAS_string inArgument0,
                                    const GALGAS_string inArgument1,
                                    const GALGAS_string inArgument2,
                                    const GALGAS_TfieldMap inArgument3,
                                    GALGAS_Tvalue & outArgument4,
                                    GALGAS_Ttype & outArgument5,
                                    C_Lexique_template_5F_scanner * inCompiler) ;

//------------------------------------- 'goil_template_start_symbol' non terminal
//--- 'parse' label
  public : virtual void nt_goil_5F_template_5F_start_5F_symbol_parse (C_Lexique_template_5F_scanner * inCompiler) ;

//----------- '' label
  public : virtual void nt_goil_5F_template_5F_start_5F_symbol_ (const GALGAS_string inArgument0,
                                                                 const GALGAS_string inArgument1,
                                                                 const GALGAS_string inArgument2,
                                                                 GALGAS_TfieldMap inArgument3,
                                                                 GALGAS_string & ioArgument4,
                                                                 GALGAS_Tvalue & outArgument5,
                                                                 GALGAS_Ttype & outArgument6,
                                                                 C_Lexique_template_5F_scanner * inCompiler) ;

//--- Start symbol
  public : static void _performSourceFileParsing_ (C_Compiler * inCompiler,
                                                   GALGAS_lstring inFileName,
                                                   const GALGAS_string inArgument0,
                                                   const GALGAS_string inArgument1,
                                                   const GALGAS_string inArgument2,
                                                   GALGAS_TfieldMap inArgument3,
                                                   GALGAS_string & ioArgument4,
                                                   GALGAS_Tvalue & outArgument5,
                                                   GALGAS_Ttype & outArgument6
                                                   COMMA_LOCATION_ARGS) ;

  public : static void _performSourceStringParsing_ (C_Compiler * inCompiler,
                                                     GALGAS_string inSourceString,
                                                     const GALGAS_string inArgument0,
                                                     const GALGAS_string inArgument1,
                                                     const GALGAS_string inArgument2,
                                                     GALGAS_TfieldMap inArgument3,
                                                     GALGAS_string & ioArgument4,
                                                     GALGAS_Tvalue & outArgument5,
                                                     GALGAS_Ttype & outArgument6
                                                     COMMA_LOCATION_ARGS) ;

//--- Indexing
  public : static void performIndexing (C_Compiler * inCompiler,
                                        const C_String & inSourceFilePath) ;

//--- Only lexical analysis
  public : static void performOnlyLexicalAnalysis (C_Compiler * inCompiler,
                                                   const C_String & inSourceFilePath) ;

//--- Only syntax analysis
  public : static void performOnlySyntaxAnalysis (C_Compiler * inCompiler,
                                                  const C_String & inSourceFilePath) ;

//------------------------------------- 'relation_factor' non terminal
//--- 'parse' label
  public : virtual void nt_relation_5F_factor_parse (C_Lexique_template_5F_scanner * inCompiler) ;

//----------- '' label
  public : virtual void nt_relation_5F_factor_ (const GALGAS_string inArgument0,
                                                const GALGAS_string inArgument1,
                                                const GALGAS_string inArgument2,
                                                const GALGAS_TfieldMap inArgument3,
                                                GALGAS_Tvalue & outArgument4,
                                                GALGAS_Ttype & outArgument5,
                                                C_Lexique_template_5F_scanner * inCompiler) ;

//------------------------------------- 'relation_term' non terminal
//--- 'parse' label
  public : virtual void nt_relation_5F_term_parse (C_Lexique_template_5F_scanner * inCompiler) ;

//----------- '' label
  public : virtual void nt_relation_5F_term_ (const GALGAS_string inArgument0,
                                              const GALGAS_string inArgument1,
                                              const GALGAS_string inArgument2,
                                              const GALGAS_TfieldMap inArgument3,
                                              GALGAS_Tvalue & outArgument4,
                                              GALGAS_Ttype & outArgument5,
                                              C_Lexique_template_5F_scanner * inCompiler) ;

//------------------------------------- 'simple_expression' non terminal
//--- 'parse' label
  public : virtual void nt_simple_5F_expression_parse (C_Lexique_template_5F_scanner * inCompiler) ;

//----------- '' label
  public : virtual void nt_simple_5F_expression_ (const GALGAS_string inArgument0,
                                                  const GALGAS_string inArgument1,
                                                  const GALGAS_string inArgument2,
                                                  const GALGAS_TfieldMap inArgument3,
                                                  GALGAS_Tvalue & outArgument4,
                                                  GALGAS_Ttype & outArgument5,
                                                  C_Lexique_template_5F_scanner * inCompiler) ;

//------------------------------------- 'sorting_order' non terminal
//--- 'parse' label
  public : virtual void nt_sorting_5F_order_parse (C_Lexique_template_5F_scanner * inCompiler) ;

//----------- '' label
  public : virtual void nt_sorting_5F_order_ (GALGAS_lsint & outArgument0,
                                              C_Lexique_template_5F_scanner * inCompiler) ;

//------------------------------------- 'template_file_name' non terminal
//--- 'parse' label
  public : virtual void nt_template_5F_file_5F_name_parse (C_Lexique_template_5F_scanner * inCompiler) ;

//----------- '' label
  public : virtual void nt_template_5F_file_5F_name_ (const GALGAS_string inArgument0,
                                                      const GALGAS_string inArgument1,
                                                      const GALGAS_string inArgument2,
                                                      const GALGAS_TfieldMap inArgument3,
                                                      GALGAS_lstring & outArgument4,
                                                      C_Lexique_template_5F_scanner * inCompiler) ;

//------------------------------------- 'template_instruction' non terminal
//--- 'parse' label
  public : virtual void nt_template_5F_instruction_parse (C_Lexique_template_5F_scanner * inCompiler) ;

//----------- '' label
  public : virtual void nt_template_5F_instruction_ (const GALGAS_string inArgument0,
                                                     const GALGAS_string inArgument1,
                                                     const GALGAS_string inArgument2,
                                                     GALGAS_TfieldMap & ioArgument3,
                                                     GALGAS_string & ioArgument4,
                                                     GALGAS_Tvalue & outArgument5,
                                                     GALGAS_Ttype & outArgument6,
                                                     C_Lexique_template_5F_scanner * inCompiler) ;

//------------------------------------- 'template_instruction_list' non terminal
//--- 'parse' label
  public : virtual void nt_template_5F_instruction_5F_list_parse (C_Lexique_template_5F_scanner * inCompiler) ;

//----------- '' label
  public : virtual void nt_template_5F_instruction_5F_list_ (const GALGAS_string inArgument0,
                                                             const GALGAS_string inArgument1,
                                                             const GALGAS_string inArgument2,
                                                             GALGAS_TfieldMap & ioArgument3,
                                                             GALGAS_string & ioArgument4,
                                                             GALGAS_Tvalue & outArgument5,
                                                             GALGAS_Ttype & outArgument6,
                                                             C_Lexique_template_5F_scanner * inCompiler) ;

//------------------------------------- 'term' non terminal
//--- 'parse' label
  public : virtual void nt_term_parse (C_Lexique_template_5F_scanner * inCompiler) ;

//----------- '' label
  public : virtual void nt_term_ (const GALGAS_string inArgument0,
                                  const GALGAS_string inArgument1,
                                  const GALGAS_string inArgument2,
                                  const GALGAS_TfieldMap inArgument3,
                                  GALGAS_Tvalue & outArgument4,
                                  GALGAS_Ttype & outArgument5,
                                  C_Lexique_template_5F_scanner * inCompiler) ;

//------------------------------------- 'variable' non terminal
//--- 'parse' label
  public : virtual void nt_variable_parse (C_Lexique_template_5F_scanner * inCompiler) ;

//----------- '' label
  public : virtual void nt_variable_ (const GALGAS_string inArgument0,
                                      const GALGAS_string inArgument1,
                                      const GALGAS_string inArgument2,
                                      const GALGAS_TfieldMap inArgument3,
                                      GALGAS_TvarPath & outArgument4,
                                      C_Lexique_template_5F_scanner * inCompiler) ;

//------------------------------------- 'variable_or_here' non terminal
//--- 'parse' label
  public : virtual void nt_variable_5F_or_5F_here_parse (C_Lexique_template_5F_scanner * inCompiler) ;

//----------- '' label
  public : virtual void nt_variable_5F_or_5F_here_ (const GALGAS_string inArgument0,
                                                    const GALGAS_string inArgument1,
                                                    const GALGAS_string inArgument2,
                                                    const GALGAS_TfieldMap inArgument3,
                                                    GALGAS_location & outArgument4,
                                                    C_Lexique_template_5F_scanner * inCompiler) ;

  public : virtual int32_t select_template_5F_parser_0 (C_Lexique_template_5F_scanner *) ;

  public : virtual int32_t select_template_5F_parser_1 (C_Lexique_template_5F_scanner *) ;

  public : virtual int32_t select_template_5F_parser_2 (C_Lexique_template_5F_scanner *) ;

  public : virtual int32_t select_template_5F_parser_3 (C_Lexique_template_5F_scanner *) ;

  public : virtual int32_t select_template_5F_parser_4 (C_Lexique_template_5F_scanner *) ;

  public : virtual int32_t select_template_5F_parser_5 (C_Lexique_template_5F_scanner *) ;

  public : virtual int32_t select_template_5F_parser_6 (C_Lexique_template_5F_scanner *) ;

  public : virtual int32_t select_template_5F_parser_7 (C_Lexique_template_5F_scanner *) ;

  public : virtual int32_t select_template_5F_parser_8 (C_Lexique_template_5F_scanner *) ;

  public : virtual int32_t select_template_5F_parser_9 (C_Lexique_template_5F_scanner *) ;

  public : virtual int32_t select_template_5F_parser_10 (C_Lexique_template_5F_scanner *) ;

  public : virtual int32_t select_template_5F_parser_11 (C_Lexique_template_5F_scanner *) ;

  public : virtual int32_t select_template_5F_parser_12 (C_Lexique_template_5F_scanner *) ;

  public : virtual int32_t select_template_5F_parser_13 (C_Lexique_template_5F_scanner *) ;

  public : virtual int32_t select_template_5F_parser_14 (C_Lexique_template_5F_scanner *) ;

  public : virtual int32_t select_template_5F_parser_15 (C_Lexique_template_5F_scanner *) ;

  public : virtual int32_t select_template_5F_parser_16 (C_Lexique_template_5F_scanner *) ;

  public : virtual int32_t select_template_5F_parser_17 (C_Lexique_template_5F_scanner *) ;

  public : virtual int32_t select_template_5F_parser_18 (C_Lexique_template_5F_scanner *) ;

  public : virtual int32_t select_template_5F_parser_19 (C_Lexique_template_5F_scanner *) ;

  public : virtual int32_t select_template_5F_parser_20 (C_Lexique_template_5F_scanner *) ;

  public : virtual int32_t select_template_5F_parser_21 (C_Lexique_template_5F_scanner *) ;

  public : virtual int32_t select_template_5F_parser_22 (C_Lexique_template_5F_scanner *) ;

  public : virtual int32_t select_template_5F_parser_23 (C_Lexique_template_5F_scanner *) ;

  public : virtual int32_t select_template_5F_parser_24 (C_Lexique_template_5F_scanner *) ;

  public : virtual int32_t select_template_5F_parser_25 (C_Lexique_template_5F_scanner *) ;

  public : virtual int32_t select_template_5F_parser_26 (C_Lexique_template_5F_scanner *) ;

  public : virtual int32_t select_template_5F_parser_27 (C_Lexique_template_5F_scanner *) ;

  public : virtual int32_t select_template_5F_expression_5F_parser_0 (C_Lexique_template_5F_scanner *) ;

  public : virtual int32_t select_template_5F_expression_5F_parser_1 (C_Lexique_template_5F_scanner *) ;

  public : virtual int32_t select_template_5F_expression_5F_parser_2 (C_Lexique_template_5F_scanner *) ;

  public : virtual int32_t select_template_5F_expression_5F_parser_3 (C_Lexique_template_5F_scanner *) ;

  public : virtual int32_t select_template_5F_expression_5F_parser_4 (C_Lexique_template_5F_scanner *) ;

  public : virtual int32_t select_template_5F_expression_5F_parser_5 (C_Lexique_template_5F_scanner *) ;

  public : virtual int32_t select_template_5F_expression_5F_parser_6 (C_Lexique_template_5F_scanner *) ;

  public : virtual int32_t select_template_5F_expression_5F_parser_7 (C_Lexique_template_5F_scanner *) ;

  public : virtual int32_t select_template_5F_expression_5F_parser_8 (C_Lexique_template_5F_scanner *) ;

  public : virtual int32_t select_template_5F_expression_5F_parser_9 (C_Lexique_template_5F_scanner *) ;

  public : virtual int32_t select_template_5F_expression_5F_parser_10 (C_Lexique_template_5F_scanner *) ;
} ;

//---------------------------------------------------------------------------------------------------------------------*
//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Routine 'addLStringValue'                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_addLStringValue (class GALGAS_TfieldMap & ioArgument0,
                              const class GALGAS_string constinArgument1,
                              const class GALGAS_lstring constinArgument2,
                              const class GALGAS_lstring constinArgument3,
                              class C_Compiler * inCompiler
                              COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             Routine 'addUnsignedValue'                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_addUnsignedValue (class GALGAS_TfieldMap & ioArgument0,
                               const class GALGAS_lstring constinArgument1,
                               const class GALGAS_uint_36__34_ constinArgument2,
                               const class GALGAS_lstring constinArgument3,
                               class C_Compiler * inCompiler
                               COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 Routine 'printPath'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_printPath (const class GALGAS_TvarPath constinArgument0,
                        class C_Compiler * inCompiler
                        COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Routine 'printVariable'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_printVariable (class GALGAS_uint inArgument0,
                            const class GALGAS_Ttype constinArgument1,
                            const class GALGAS_Tvalue constinArgument2,
                            class C_Compiler * inCompiler
                            COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 Routine 'quickSort'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_quickSort (class GALGAS_TfieldMapList & ioArgument0,
                        const class GALGAS_uint constinArgument1,
                        const class GALGAS_uint constinArgument2,
                        const class GALGAS_sortingKeyList constinArgument3,
                        class C_Compiler * inCompiler
                        COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                Routine 'searchField'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_searchField (class GALGAS_TvarPath inArgument0,
                          const class GALGAS_TfieldMap constinArgument1,
                          class GALGAS_Ttype & outArgument2,
                          class GALGAS_Tvalue & outArgument3,
                          class GALGAS_location & outArgument4,
                          class C_Compiler * inCompiler
                          COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Routine 'searchFieldIfExists'                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_searchFieldIfExists (class GALGAS_TvarPath inArgument0,
                                  const class GALGAS_TfieldMap constinArgument1,
                                  class GALGAS_Ttype & outArgument2,
                                  class GALGAS_Tvalue & outArgument3,
                                  class GALGAS_bool & outArgument4,
                                  class C_Compiler * inCompiler
                                  COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             Routine 'setVariableInPath'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_setVariableInPath (class GALGAS_TvarPath inArgument0,
                                class GALGAS_TfieldMap & ioArgument1,
                                const class GALGAS_Ttype constinArgument2,
                                const class GALGAS_Tvalue constinArgument3,
                                class C_Compiler * inCompiler
                                COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Routine 'templateInvocation'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_templateInvocation (const class GALGAS_lstring constinArgument0,
                                 const class GALGAS_string constinArgument1,
                                 const class GALGAS_string constinArgument2,
                                 const class GALGAS_string constinArgument3,
                                 const class GALGAS_bool constinArgument4,
                                 const class GALGAS_TfieldMap constinArgument5,
                                 class GALGAS_string & ioArgument6,
                                 class GALGAS_bool & outArgument7,
                                 class C_Compiler * inCompiler
                                 COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              Function 'valueWithList'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_Tvalue function_valueWithList (const class GALGAS_TfieldMapList & constinArgument0,
                                            const class GALGAS_lstring & constinArgument1,
                                            class C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Function 'valueWithMap'                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_Tvalue function_valueWithMap (const class GALGAS_TfieldMap & constinArgument0,
                                           const class GALGAS_lstring & constinArgument1,
                                           class C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             Function 'valueWithSigned'                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_Tvalue function_valueWithSigned (const class GALGAS_sint_36__34_ & constinArgument0,
                                              const class GALGAS_lstring & constinArgument1,
                                              class C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Function 'valueWithUnsigned'                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_Tvalue function_valueWithUnsigned (const class GALGAS_uint_36__34_ & constinArgument0,
                                                const class GALGAS_lstring & constinArgument1,
                                                class C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Routine 'addition_types_checkForTemplate'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_addition_5F_types_5F_checkForTemplate (const class GALGAS_Ttype constinArgument0,
                                                    const class GALGAS_Ttype constinArgument1,
                                                    class GALGAS_Ttype & outArgument2,
                                                    class C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Routine 'checkBitComplementOperatorForTemplate'                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_checkBitComplementOperatorForTemplate (const class GALGAS_Ttype constinArgument0,
                                                    class GALGAS_Ttype & outArgument1,
                                                    class C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Routine 'checkNotOperatorForTemplate'                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_checkNotOperatorForTemplate (const class GALGAS_Ttype constinArgument0,
                                          class GALGAS_Ttype & outArgument1,
                                          class C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Routine 'comparison_types_checkForTemplate'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_comparison_5F_types_5F_checkForTemplate (const class GALGAS_Ttype constinArgument0,
                                                      const class GALGAS_Ttype constinArgument1,
                                                      class C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Routine 'concatenation_types_checkForTemplate'                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_concatenation_5F_types_5F_checkForTemplate (const class GALGAS_Ttype constinArgument0,
                                                         const class GALGAS_Ttype constinArgument1,
                                                         class GALGAS_Ttype & outArgument2,
                                                         class C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Routine 'divide_types_checkForTemplate'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_divide_5F_types_5F_checkForTemplate (const class GALGAS_Ttype constinArgument0,
                                                  const class GALGAS_Ttype constinArgument1,
                                                  class GALGAS_Ttype & outArgument2,
                                                  class C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Routine 'left_shift_types_checkForTemplate'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_left_5F_shift_5F_types_5F_checkForTemplate (const class GALGAS_Ttype constinArgument0,
                                                         const class GALGAS_Ttype constinArgument1,
                                                         class GALGAS_Ttype & outArgument2,
                                                         class C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Routine 'magnitude_comparison_types_checkForTemplate'                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_magnitude_5F_comparison_5F_types_5F_checkForTemplate (const class GALGAS_Ttype constinArgument0,
                                                                   const class GALGAS_Ttype constinArgument1,
                                                                   class C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Routine 'matchAndOperatorForTemplate'                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_matchAndOperatorForTemplate (const class GALGAS_Ttype constinArgument0,
                                          const class GALGAS_Ttype constinArgument1,
                                          class GALGAS_Ttype & outArgument2,
                                          class C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Routine 'matchOrOperatorForTemplate'                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_matchOrOperatorForTemplate (const class GALGAS_Ttype constinArgument0,
                                         const class GALGAS_Ttype constinArgument1,
                                         class GALGAS_Ttype & outArgument2,
                                         class C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Routine 'matchXorOperatorForTemplate'                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_matchXorOperatorForTemplate (const class GALGAS_Ttype constinArgument0,
                                          const class GALGAS_Ttype constinArgument1,
                                          class GALGAS_Ttype & outArgument2,
                                          class C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Routine 'modulo_types_checkForTemplate'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_modulo_5F_types_5F_checkForTemplate (const class GALGAS_Ttype constinArgument0,
                                                  const class GALGAS_Ttype constinArgument1,
                                                  class GALGAS_Ttype & outArgument2,
                                                  class C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Routine 'multiply_types_checkForTemplate'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_multiply_5F_types_5F_checkForTemplate (const class GALGAS_Ttype constinArgument0,
                                                    const class GALGAS_Ttype constinArgument1,
                                                    class GALGAS_Ttype & outArgument2,
                                                    class C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Routine 'right_shift_types_checkForTemplate'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_right_5F_shift_5F_types_5F_checkForTemplate (const class GALGAS_Ttype constinArgument0,
                                                          const class GALGAS_Ttype constinArgument1,
                                                          class GALGAS_Ttype & outArgument2,
                                                          class C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         Routine 'templateMethodInvocation'                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_templateMethodInvocation (const class GALGAS_Ttype constinArgument0,
                                       const class GALGAS_Tvalue constinArgument1,
                                       const class GALGAS_lstring constinArgument2,
                                       class GALGAS_TexpressionList inArgument3,
                                       class GALGAS_Ttype & outArgument4,
                                       class GALGAS_Tvalue & outArgument5,
                                       class C_Compiler * inCompiler
                                       COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 Routine 'typeError'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_typeError (const class GALGAS_lstring constinArgument0,
                        const class GALGAS_type constinArgument1,
                        const class GALGAS_string constinArgument2,
                        const class GALGAS_uint constinArgument3,
                        class C_Compiler * inCompiler
                        COMMA_LOCATION_ARGS) ;


#ifndef goil_5F_lexique_CLASS_DEFINED
#define goil_5F_lexique_CLASS_DEFINED

//---------------------------------------------------------------------------------------------------------------------*

#include "galgas2/C_Lexique.h"
#include "galgas2/predefined-types.h"

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                    E X T E R N    R O U T I N E S                                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                    E X T E R N    F U N C T I O N S                                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                       T O K E N    C L A S S                                                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cTokenFor_goil_5F_lexique : public cToken {
  public : C_String mLexicalAttribute_a_5F_string ;
  public : C_String mLexicalAttribute_att_5F_token ;
  public : double mLexicalAttribute_floatNumber ;
  public : uint64_t mLexicalAttribute_integerNumber ;
  public : C_String mLexicalAttribute_number ;

  public : cTokenFor_goil_5F_lexique (void) ;
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                     S C A N N E R    C L A S S                                                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class C_Lexique_goil_5F_lexique : public C_Lexique {
//--- Constructors
  public : C_Lexique_goil_5F_lexique (C_Compiler * inCallerCompiler,
                       const C_String & inDependencyFileExtension,
                       const C_String & inDependencyFilePath,
                       const C_String & inSourceFileName
                       COMMA_LOCATION_ARGS) ;

  public : C_Lexique_goil_5F_lexique (C_Compiler * inCallerCompiler,
                       const C_String & inSourceString,
                       const C_String & inStringForError
                       COMMA_LOCATION_ARGS) ;

//--- Instrospection
  public : static GALGAS_stringlist symbols (LOCATION_ARGS) ;

//--- Declaring a protected virtual destructor enables the compiler to raise
//    an error if a direct delete is performed; only the static method
//    C_SharedObject::detachPointer may invoke delete.
  #ifndef DO_NOT_GENERATE_CHECKINGS
    protected : virtual ~ C_Lexique_goil_5F_lexique (void) {}
  #endif



//--- Terminal symbols enumeration
  public : enum {kToken_,
   kToken_comment,
   kToken_idf,
   kToken_string,
   kToken_g_5F_string,
   kToken_uint_5F_number,
   kToken_float_5F_number,
   kToken_set_5F_start_5F_uint_5F_number,
   kToken_command,
   kToken_OIL_5F_VERSION,
   kToken_IMPLEMENTATION,
   kToken_CPU,
   kToken_UINT_33__32_,
   kToken_INT_33__32_,
   kToken_UINT_36__34_,
   kToken_INT_36__34_,
   kToken_FLOAT,
   kToken_ENUM,
   kToken_STRING,
   kToken_BOOLEAN,
   kToken_IDENTIFIER,
   kToken_STRUCT,
   kToken_WITH_5F_AUTO,
   kToken_NO_5F_DEFAULT,
   kToken_AUTO,
   kToken_FALSE,
   kToken_TRUE,
   kToken__3B_,
   kToken__3A_,
   kToken__3D_,
   kToken__7B_,
   kToken__7D_,
   kToken__2E__2E_,
   kToken__5B_,
   kToken__5D_,
   kToken__2C_,
   kToken__2E_,
   kToken__2B_,
   kToken__2D_,
   kToken_include} ;

//--- Key words table 'oilVersion'
  public : static int16_t search_into_oilVersion (const C_String & inSearchedString) ;

//--- Key words table 'oilDefinitions'
  public : static int16_t search_into_oilDefinitions (const C_String & inSearchedString) ;

//--- Key words table 'dataTypes'
  public : static int16_t search_into_dataTypes (const C_String & inSearchedString) ;

//--- Key words table 'miscSpecifiers'
  public : static int16_t search_into_miscSpecifiers (const C_String & inSearchedString) ;

//--- Key words table 'boolean'
  public : static int16_t search_into_boolean (const C_String & inSearchedString) ;

//--- Key words table 'OILDelimiters'
  public : static int16_t search_into_OILDelimiters (const C_String & inSearchedString) ;

//--- Key words table 'commands'
  public : static int16_t search_into_commands (const C_String & inSearchedString) ;
  

//--- Assign from attribute
  public : GALGAS_lstring synthetizedAttribute_a_5F_string (void) const ;
  public : GALGAS_lstring synthetizedAttribute_att_5F_token (void) const ;
  public : GALGAS_ldouble synthetizedAttribute_floatNumber (void) const ;
  public : GALGAS_luint_36__34_ synthetizedAttribute_integerNumber (void) const ;
  public : GALGAS_lstring synthetizedAttribute_number (void) const ;


//--- Attribute access
  public : C_String attributeValue_a_5F_string (void) const ;
  public : C_String attributeValue_att_5F_token (void) const ;
  public : double attributeValue_floatNumber (void) const ;
  public : uint64_t attributeValue_integerNumber (void) const ;
  public : C_String attributeValue_number (void) const ;


//--- Indexing keys

//--- Indexing directory
  protected : virtual C_String indexingDirectory (void) const ;

//--- Parse lexical token
  protected : virtual bool parseLexicalToken (void) ;

//--- Get terminal message
  protected : virtual C_String getMessageForTerminal (const int16_t inTerminalSymbol) const ;

//--- Get terminal count
  public : virtual int16_t terminalVocabularyCount (void) const { return 39 ; }

//--- Get Token String
  public : virtual C_String getCurrentTokenString (const cToken * inTokenPtr) const ;

//--- Enter Token
  protected : void enterToken (const cTokenFor_goil_5F_lexique & inToken) ;

//--- Style name for Latex
  protected : virtual C_String styleNameForIndex (const uint32_t inStyleIndex) const ;
  protected : virtual uint32_t styleIndexForTerminal (const int32_t inTerminalIndex) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

#endif
//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                   @dataType enum                                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_dataType : public AC_GALGAS_root {
//--------------------------------- Default constructor
  public : GALGAS_dataType (void) ;

//--------------------------------- Enumeration
  public : typedef enum {
    kNotBuilt,
    kEnum_void,
    kEnum_uint_33__32_Number,
    kEnum_sint_33__32_Number,
    kEnum_uint_36__34_Number,
    kEnum_sint_36__34_Number,
    kEnum_floatNumber,
    kEnum_string,
    kEnum_enumeration,
    kEnum_boolean,
    kEnum_identifier,
    kEnum_objectType,
    kEnum_structType
  } enumeration ;
  
//--------------------------------- Private data member
  private : enumeration mEnum ;

//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG inline bool isValid (void) const { return kNotBuilt != mEnum ; }
  public : VIRTUAL_IN_DEBUG inline void drop (void) { mEnum = kNotBuilt ; }
  public : inline enumeration enumValue (void) const { return mEnum ; }

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_dataType extractObject (const GALGAS_object & inObject,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_dataType constructor_boolean (LOCATION_ARGS) ;

  public : static GALGAS_dataType constructor_enumeration (LOCATION_ARGS) ;

  public : static GALGAS_dataType constructor_floatNumber (LOCATION_ARGS) ;

  public : static GALGAS_dataType constructor_identifier (LOCATION_ARGS) ;

  public : static GALGAS_dataType constructor_objectType (LOCATION_ARGS) ;

  public : static GALGAS_dataType constructor_sint_33__32_Number (LOCATION_ARGS) ;

  public : static GALGAS_dataType constructor_sint_36__34_Number (LOCATION_ARGS) ;

  public : static GALGAS_dataType constructor_string (LOCATION_ARGS) ;

  public : static GALGAS_dataType constructor_structType (LOCATION_ARGS) ;

  public : static GALGAS_dataType constructor_uint_33__32_Number (LOCATION_ARGS) ;

  public : static GALGAS_dataType constructor_uint_36__34_Number (LOCATION_ARGS) ;

  public : static GALGAS_dataType constructor_void (LOCATION_ARGS) ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_dataType & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isBoolean (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isEnumeration (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isFloatNumber (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isIdentifier (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isObjectType (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isSint_33__32_Number (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isSint_36__34_Number (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isString (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isStructType (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isUint_33__32_Number (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isUint_36__34_Number (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_isVoid (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_dataType class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_dataType ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  @uint32List list                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_uint_33__32_List : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public : GALGAS_uint_33__32_List (void) ;

//--------------------------------- List constructor used by listmap
  public : GALGAS_uint_33__32_List (cSharedList * inSharedListPtr) ;

//--------------------------------- Element constructor used by listmap
  public : static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                  const class GALGAS_location & in_location,
                                                  const class GALGAS_uint & in_value
                                                  COMMA_LOCATION_ARGS) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_uint_33__32_List extractObject (const GALGAS_object & inObject,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_uint_33__32_List constructor_emptyList (LOCATION_ARGS) ;

  public : static GALGAS_uint_33__32_List constructor_listWithValue (const class GALGAS_location & inOperand0,
                                                                     const class GALGAS_uint & inOperand1
                                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public : VIRTUAL_IN_DEBUG void dotAssign_operation (const GALGAS_uint_33__32_List inOperand
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public : VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_location & inOperand0,
                                                      const class GALGAS_uint & inOperand1
                                                      COMMA_LOCATION_ARGS) ;
//--------------------------------- . (concat) operator
  public : VIRTUAL_IN_DEBUG GALGAS_uint_33__32_List operator_concat (const GALGAS_uint_33__32_List & inOperand
                                                                     COMMA_LOCATION_ARGS) const ;

//--------------------------------- + operator
  public : VIRTUAL_IN_DEBUG GALGAS_uint_33__32_List add_operation (const GALGAS_uint_33__32_List & inOperand,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void modifier_insertAtIndex (class GALGAS_location constinArgument0,
                                                         class GALGAS_uint constinArgument1,
                                                         class GALGAS_uint constinArgument2,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_popFirst (class GALGAS_location & outArgument0,
                                                    class GALGAS_uint & outArgument1,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_popLast (class GALGAS_location & outArgument0,
                                                   class GALGAS_uint & outArgument1,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_removeAtIndex (class GALGAS_location & outArgument0,
                                                         class GALGAS_uint & outArgument1,
                                                         class GALGAS_uint constinArgument2,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_first (class GALGAS_location & outArgument0,
                                               class GALGAS_uint & outArgument1,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_last (class GALGAS_location & outArgument0,
                                              class GALGAS_uint & outArgument1,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_location reader_locationAtIndex (const class GALGAS_uint & constinOperand0,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint_33__32_List reader_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                                   C_Compiler * inCompiler
                                                                                   COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint_33__32_List reader_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                                   C_Compiler * inCompiler
                                                                                   COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint reader_valueAtIndex (const class GALGAS_uint & constinOperand0,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
//--------------------------------- Friend

  friend class cEnumerator_uint_33__32_List ;
 
} ; // End of GALGAS_uint_33__32_List class

//---------------------------------------------------------------------------------------------------------------------*
//   Enumerator declaration                                                    *
//---------------------------------------------------------------------------------------------------------------------*

class cEnumerator_uint_33__32_List : public cGenericAbstractEnumerator {
  public : cEnumerator_uint_33__32_List (const GALGAS_uint_33__32_List & inEnumeratedObject,
                                         const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_location current_location (LOCATION_ARGS) const ;
  public : class GALGAS_uint current_value (LOCATION_ARGS) const ;
//--- Current element access
  public : class GALGAS_uint_33__32_List_2D_element current (LOCATION_ARGS) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_uint_33__32_List ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         @uint_33__32_List_2D_element struct                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_uint_33__32_List_2D_element : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_location mAttribute_location ;
  public : GALGAS_uint mAttribute_value ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_uint_33__32_List_2D_element constructor_default (LOCATION_ARGS) ;

//--------------------------------- Default constructor
  public : GALGAS_uint_33__32_List_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_uint_33__32_List_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS_uint_33__32_List_2D_element (const GALGAS_location & in_location,
                                               const GALGAS_uint & in_value) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_uint_33__32_List_2D_element extractObject (const GALGAS_object & inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_uint_33__32_List_2D_element constructor_new (const class GALGAS_location & inOperand0,
                                                                      const class GALGAS_uint & inOperand1
                                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_uint_33__32_List_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_location reader_location (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint reader_value (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_uint_33__32_List_2D_element class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_uint_33__32_List_2D_element ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  @uint64List list                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_uint_36__34_List : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public : GALGAS_uint_36__34_List (void) ;

//--------------------------------- List constructor used by listmap
  public : GALGAS_uint_36__34_List (cSharedList * inSharedListPtr) ;

//--------------------------------- Element constructor used by listmap
  public : static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                  const class GALGAS_location & in_location,
                                                  const class GALGAS_uint_36__34_ & in_value
                                                  COMMA_LOCATION_ARGS) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_uint_36__34_List extractObject (const GALGAS_object & inObject,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_uint_36__34_List constructor_emptyList (LOCATION_ARGS) ;

  public : static GALGAS_uint_36__34_List constructor_listWithValue (const class GALGAS_location & inOperand0,
                                                                     const class GALGAS_uint_36__34_ & inOperand1
                                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public : VIRTUAL_IN_DEBUG void dotAssign_operation (const GALGAS_uint_36__34_List inOperand
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public : VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_location & inOperand0,
                                                      const class GALGAS_uint_36__34_ & inOperand1
                                                      COMMA_LOCATION_ARGS) ;
//--------------------------------- . (concat) operator
  public : VIRTUAL_IN_DEBUG GALGAS_uint_36__34_List operator_concat (const GALGAS_uint_36__34_List & inOperand
                                                                     COMMA_LOCATION_ARGS) const ;

//--------------------------------- + operator
  public : VIRTUAL_IN_DEBUG GALGAS_uint_36__34_List add_operation (const GALGAS_uint_36__34_List & inOperand,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void modifier_insertAtIndex (class GALGAS_location constinArgument0,
                                                         class GALGAS_uint_36__34_ constinArgument1,
                                                         class GALGAS_uint constinArgument2,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_popFirst (class GALGAS_location & outArgument0,
                                                    class GALGAS_uint_36__34_ & outArgument1,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_popLast (class GALGAS_location & outArgument0,
                                                   class GALGAS_uint_36__34_ & outArgument1,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_removeAtIndex (class GALGAS_location & outArgument0,
                                                         class GALGAS_uint_36__34_ & outArgument1,
                                                         class GALGAS_uint constinArgument2,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_first (class GALGAS_location & outArgument0,
                                               class GALGAS_uint_36__34_ & outArgument1,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_last (class GALGAS_location & outArgument0,
                                              class GALGAS_uint_36__34_ & outArgument1,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_location reader_locationAtIndex (const class GALGAS_uint & constinOperand0,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint_36__34_List reader_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                                   C_Compiler * inCompiler
                                                                                   COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint_36__34_List reader_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                                   C_Compiler * inCompiler
                                                                                   COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint_36__34_ reader_valueAtIndex (const class GALGAS_uint & constinOperand0,
                                                                           C_Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
//--------------------------------- Friend

  friend class cEnumerator_uint_36__34_List ;
 
} ; // End of GALGAS_uint_36__34_List class

//---------------------------------------------------------------------------------------------------------------------*
//   Enumerator declaration                                                    *
//---------------------------------------------------------------------------------------------------------------------*

class cEnumerator_uint_36__34_List : public cGenericAbstractEnumerator {
  public : cEnumerator_uint_36__34_List (const GALGAS_uint_36__34_List & inEnumeratedObject,
                                         const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_location current_location (LOCATION_ARGS) const ;
  public : class GALGAS_uint_36__34_ current_value (LOCATION_ARGS) const ;
//--- Current element access
  public : class GALGAS_uint_36__34_List_2D_element current (LOCATION_ARGS) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_uint_36__34_List ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         @uint_36__34_List_2D_element struct                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_uint_36__34_List_2D_element : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_location mAttribute_location ;
  public : GALGAS_uint_36__34_ mAttribute_value ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_uint_36__34_List_2D_element constructor_default (LOCATION_ARGS) ;

//--------------------------------- Default constructor
  public : GALGAS_uint_36__34_List_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_uint_36__34_List_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS_uint_36__34_List_2D_element (const GALGAS_location & in_location,
                                               const GALGAS_uint_36__34_ & in_value) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_uint_36__34_List_2D_element extractObject (const GALGAS_object & inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_uint_36__34_List_2D_element constructor_new (const class GALGAS_location & inOperand0,
                                                                      const class GALGAS_uint_36__34_ & inOperand1
                                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_uint_36__34_List_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_location reader_location (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint_36__34_ reader_value (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_uint_36__34_List_2D_element class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_uint_36__34_List_2D_element ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  @sint32List list                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_sint_33__32_List : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public : GALGAS_sint_33__32_List (void) ;

//--------------------------------- List constructor used by listmap
  public : GALGAS_sint_33__32_List (cSharedList * inSharedListPtr) ;

//--------------------------------- Element constructor used by listmap
  public : static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                  const class GALGAS_location & in_location,
                                                  const class GALGAS_sint & in_value
                                                  COMMA_LOCATION_ARGS) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_sint_33__32_List extractObject (const GALGAS_object & inObject,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_sint_33__32_List constructor_emptyList (LOCATION_ARGS) ;

  public : static GALGAS_sint_33__32_List constructor_listWithValue (const class GALGAS_location & inOperand0,
                                                                     const class GALGAS_sint & inOperand1
                                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public : VIRTUAL_IN_DEBUG void dotAssign_operation (const GALGAS_sint_33__32_List inOperand
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public : VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_location & inOperand0,
                                                      const class GALGAS_sint & inOperand1
                                                      COMMA_LOCATION_ARGS) ;
//--------------------------------- . (concat) operator
  public : VIRTUAL_IN_DEBUG GALGAS_sint_33__32_List operator_concat (const GALGAS_sint_33__32_List & inOperand
                                                                     COMMA_LOCATION_ARGS) const ;

//--------------------------------- + operator
  public : VIRTUAL_IN_DEBUG GALGAS_sint_33__32_List add_operation (const GALGAS_sint_33__32_List & inOperand,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void modifier_insertAtIndex (class GALGAS_location constinArgument0,
                                                         class GALGAS_sint constinArgument1,
                                                         class GALGAS_uint constinArgument2,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_popFirst (class GALGAS_location & outArgument0,
                                                    class GALGAS_sint & outArgument1,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_popLast (class GALGAS_location & outArgument0,
                                                   class GALGAS_sint & outArgument1,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_removeAtIndex (class GALGAS_location & outArgument0,
                                                         class GALGAS_sint & outArgument1,
                                                         class GALGAS_uint constinArgument2,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_first (class GALGAS_location & outArgument0,
                                               class GALGAS_sint & outArgument1,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_last (class GALGAS_location & outArgument0,
                                              class GALGAS_sint & outArgument1,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_location reader_locationAtIndex (const class GALGAS_uint & constinOperand0,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_sint_33__32_List reader_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                                   C_Compiler * inCompiler
                                                                                   COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_sint_33__32_List reader_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                                   C_Compiler * inCompiler
                                                                                   COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_sint reader_valueAtIndex (const class GALGAS_uint & constinOperand0,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
//--------------------------------- Friend

  friend class cEnumerator_sint_33__32_List ;
 
} ; // End of GALGAS_sint_33__32_List class

//---------------------------------------------------------------------------------------------------------------------*
//   Enumerator declaration                                                    *
//---------------------------------------------------------------------------------------------------------------------*

class cEnumerator_sint_33__32_List : public cGenericAbstractEnumerator {
  public : cEnumerator_sint_33__32_List (const GALGAS_sint_33__32_List & inEnumeratedObject,
                                         const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_location current_location (LOCATION_ARGS) const ;
  public : class GALGAS_sint current_value (LOCATION_ARGS) const ;
//--- Current element access
  public : class GALGAS_sint_33__32_List_2D_element current (LOCATION_ARGS) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_sint_33__32_List ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         @sint_33__32_List_2D_element struct                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_sint_33__32_List_2D_element : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_location mAttribute_location ;
  public : GALGAS_sint mAttribute_value ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_sint_33__32_List_2D_element constructor_default (LOCATION_ARGS) ;

//--------------------------------- Default constructor
  public : GALGAS_sint_33__32_List_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_sint_33__32_List_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS_sint_33__32_List_2D_element (const GALGAS_location & in_location,
                                               const GALGAS_sint & in_value) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_sint_33__32_List_2D_element extractObject (const GALGAS_object & inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_sint_33__32_List_2D_element constructor_new (const class GALGAS_location & inOperand0,
                                                                      const class GALGAS_sint & inOperand1
                                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_sint_33__32_List_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_location reader_location (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_sint reader_value (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_sint_33__32_List_2D_element class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_sint_33__32_List_2D_element ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  @sint64List list                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_sint_36__34_List : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public : GALGAS_sint_36__34_List (void) ;

//--------------------------------- List constructor used by listmap
  public : GALGAS_sint_36__34_List (cSharedList * inSharedListPtr) ;

//--------------------------------- Element constructor used by listmap
  public : static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                  const class GALGAS_location & in_location,
                                                  const class GALGAS_sint_36__34_ & in_value
                                                  COMMA_LOCATION_ARGS) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_sint_36__34_List extractObject (const GALGAS_object & inObject,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_sint_36__34_List constructor_emptyList (LOCATION_ARGS) ;

  public : static GALGAS_sint_36__34_List constructor_listWithValue (const class GALGAS_location & inOperand0,
                                                                     const class GALGAS_sint_36__34_ & inOperand1
                                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public : VIRTUAL_IN_DEBUG void dotAssign_operation (const GALGAS_sint_36__34_List inOperand
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public : VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_location & inOperand0,
                                                      const class GALGAS_sint_36__34_ & inOperand1
                                                      COMMA_LOCATION_ARGS) ;
//--------------------------------- . (concat) operator
  public : VIRTUAL_IN_DEBUG GALGAS_sint_36__34_List operator_concat (const GALGAS_sint_36__34_List & inOperand
                                                                     COMMA_LOCATION_ARGS) const ;

//--------------------------------- + operator
  public : VIRTUAL_IN_DEBUG GALGAS_sint_36__34_List add_operation (const GALGAS_sint_36__34_List & inOperand,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void modifier_insertAtIndex (class GALGAS_location constinArgument0,
                                                         class GALGAS_sint_36__34_ constinArgument1,
                                                         class GALGAS_uint constinArgument2,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_popFirst (class GALGAS_location & outArgument0,
                                                    class GALGAS_sint_36__34_ & outArgument1,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_popLast (class GALGAS_location & outArgument0,
                                                   class GALGAS_sint_36__34_ & outArgument1,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_removeAtIndex (class GALGAS_location & outArgument0,
                                                         class GALGAS_sint_36__34_ & outArgument1,
                                                         class GALGAS_uint constinArgument2,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_first (class GALGAS_location & outArgument0,
                                               class GALGAS_sint_36__34_ & outArgument1,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_last (class GALGAS_location & outArgument0,
                                              class GALGAS_sint_36__34_ & outArgument1,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_location reader_locationAtIndex (const class GALGAS_uint & constinOperand0,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_sint_36__34_List reader_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                                   C_Compiler * inCompiler
                                                                                   COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_sint_36__34_List reader_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                                   C_Compiler * inCompiler
                                                                                   COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_sint_36__34_ reader_valueAtIndex (const class GALGAS_uint & constinOperand0,
                                                                           C_Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
//--------------------------------- Friend

  friend class cEnumerator_sint_36__34_List ;
 
} ; // End of GALGAS_sint_36__34_List class

//---------------------------------------------------------------------------------------------------------------------*
//   Enumerator declaration                                                    *
//---------------------------------------------------------------------------------------------------------------------*

class cEnumerator_sint_36__34_List : public cGenericAbstractEnumerator {
  public : cEnumerator_sint_36__34_List (const GALGAS_sint_36__34_List & inEnumeratedObject,
                                         const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_location current_location (LOCATION_ARGS) const ;
  public : class GALGAS_sint_36__34_ current_value (LOCATION_ARGS) const ;
//--- Current element access
  public : class GALGAS_sint_36__34_List_2D_element current (LOCATION_ARGS) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_sint_36__34_List ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         @sint_36__34_List_2D_element struct                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_sint_36__34_List_2D_element : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_location mAttribute_location ;
  public : GALGAS_sint_36__34_ mAttribute_value ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_sint_36__34_List_2D_element constructor_default (LOCATION_ARGS) ;

//--------------------------------- Default constructor
  public : GALGAS_sint_36__34_List_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_sint_36__34_List_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS_sint_36__34_List_2D_element (const GALGAS_location & in_location,
                                               const GALGAS_sint_36__34_ & in_value) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_sint_36__34_List_2D_element extractObject (const GALGAS_object & inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_sint_36__34_List_2D_element constructor_new (const class GALGAS_location & inOperand0,
                                                                      const class GALGAS_sint_36__34_ & inOperand1
                                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_sint_36__34_List_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_location reader_location (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_sint_36__34_ reader_value (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_sint_36__34_List_2D_element class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_sint_36__34_List_2D_element ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                   @floatList list                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_floatList : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public : GALGAS_floatList (void) ;

//--------------------------------- List constructor used by listmap
  public : GALGAS_floatList (cSharedList * inSharedListPtr) ;

//--------------------------------- Element constructor used by listmap
  public : static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                  const class GALGAS_location & in_location,
                                                  const class GALGAS_double & in_value
                                                  COMMA_LOCATION_ARGS) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_floatList extractObject (const GALGAS_object & inObject,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_floatList constructor_emptyList (LOCATION_ARGS) ;

  public : static GALGAS_floatList constructor_listWithValue (const class GALGAS_location & inOperand0,
                                                              const class GALGAS_double & inOperand1
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public : VIRTUAL_IN_DEBUG void dotAssign_operation (const GALGAS_floatList inOperand
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public : VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_location & inOperand0,
                                                      const class GALGAS_double & inOperand1
                                                      COMMA_LOCATION_ARGS) ;
//--------------------------------- . (concat) operator
  public : VIRTUAL_IN_DEBUG GALGAS_floatList operator_concat (const GALGAS_floatList & inOperand
                                                              COMMA_LOCATION_ARGS) const ;

//--------------------------------- + operator
  public : VIRTUAL_IN_DEBUG GALGAS_floatList add_operation (const GALGAS_floatList & inOperand,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void modifier_insertAtIndex (class GALGAS_location constinArgument0,
                                                         class GALGAS_double constinArgument1,
                                                         class GALGAS_uint constinArgument2,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_popFirst (class GALGAS_location & outArgument0,
                                                    class GALGAS_double & outArgument1,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_popLast (class GALGAS_location & outArgument0,
                                                   class GALGAS_double & outArgument1,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_removeAtIndex (class GALGAS_location & outArgument0,
                                                         class GALGAS_double & outArgument1,
                                                         class GALGAS_uint constinArgument2,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_first (class GALGAS_location & outArgument0,
                                               class GALGAS_double & outArgument1,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_last (class GALGAS_location & outArgument0,
                                              class GALGAS_double & outArgument1,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_location reader_locationAtIndex (const class GALGAS_uint & constinOperand0,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_floatList reader_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_floatList reader_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_double reader_valueAtIndex (const class GALGAS_uint & constinOperand0,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
//--------------------------------- Friend

  friend class cEnumerator_floatList ;
 
} ; // End of GALGAS_floatList class

//---------------------------------------------------------------------------------------------------------------------*
//   Enumerator declaration                                                    *
//---------------------------------------------------------------------------------------------------------------------*

class cEnumerator_floatList : public cGenericAbstractEnumerator {
  public : cEnumerator_floatList (const GALGAS_floatList & inEnumeratedObject,
                                  const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_location current_location (LOCATION_ARGS) const ;
  public : class GALGAS_double current_value (LOCATION_ARGS) const ;
//--- Current element access
  public : class GALGAS_floatList_2D_element current (LOCATION_ARGS) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_floatList ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            @floatList_2D_element struct                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_floatList_2D_element : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_location mAttribute_location ;
  public : GALGAS_double mAttribute_value ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_floatList_2D_element constructor_default (LOCATION_ARGS) ;

//--------------------------------- Default constructor
  public : GALGAS_floatList_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_floatList_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS_floatList_2D_element (const GALGAS_location & in_location,
                                        const GALGAS_double & in_value) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_floatList_2D_element extractObject (const GALGAS_object & inObject,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_floatList_2D_element constructor_new (const class GALGAS_location & inOperand0,
                                                               const class GALGAS_double & inOperand1
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_floatList_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_location reader_location (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_double reader_value (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_floatList_2D_element class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_floatList_2D_element ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  @numberList list                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_numberList : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public : GALGAS_numberList (void) ;

//--------------------------------- List constructor used by listmap
  public : GALGAS_numberList (cSharedList * inSharedListPtr) ;

//--------------------------------- Element constructor used by listmap
  public : static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                  const class GALGAS_location & in_location,
                                                  const class GALGAS_object_5F_t & in_value
                                                  COMMA_LOCATION_ARGS) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_numberList extractObject (const GALGAS_object & inObject,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_numberList constructor_emptyList (LOCATION_ARGS) ;

  public : static GALGAS_numberList constructor_listWithValue (const class GALGAS_location & inOperand0,
                                                               const class GALGAS_object_5F_t & inOperand1
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public : VIRTUAL_IN_DEBUG void dotAssign_operation (const GALGAS_numberList inOperand
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public : VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_location & inOperand0,
                                                      const class GALGAS_object_5F_t & inOperand1
                                                      COMMA_LOCATION_ARGS) ;
//--------------------------------- . (concat) operator
  public : VIRTUAL_IN_DEBUG GALGAS_numberList operator_concat (const GALGAS_numberList & inOperand
                                                               COMMA_LOCATION_ARGS) const ;

//--------------------------------- + operator
  public : VIRTUAL_IN_DEBUG GALGAS_numberList add_operation (const GALGAS_numberList & inOperand,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void modifier_insertAtIndex (class GALGAS_location constinArgument0,
                                                         class GALGAS_object_5F_t constinArgument1,
                                                         class GALGAS_uint constinArgument2,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_popFirst (class GALGAS_location & outArgument0,
                                                    class GALGAS_object_5F_t & outArgument1,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_popLast (class GALGAS_location & outArgument0,
                                                   class GALGAS_object_5F_t & outArgument1,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_removeAtIndex (class GALGAS_location & outArgument0,
                                                         class GALGAS_object_5F_t & outArgument1,
                                                         class GALGAS_uint constinArgument2,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_first (class GALGAS_location & outArgument0,
                                               class GALGAS_object_5F_t & outArgument1,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_last (class GALGAS_location & outArgument0,
                                              class GALGAS_object_5F_t & outArgument1,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_location reader_locationAtIndex (const class GALGAS_uint & constinOperand0,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_numberList reader_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                             C_Compiler * inCompiler
                                                                             COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_numberList reader_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                             C_Compiler * inCompiler
                                                                             COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_object_5F_t reader_valueAtIndex (const class GALGAS_uint & constinOperand0,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
//--------------------------------- Friend

  friend class cEnumerator_numberList ;
 
} ; // End of GALGAS_numberList class

//---------------------------------------------------------------------------------------------------------------------*
//   Enumerator declaration                                                    *
//---------------------------------------------------------------------------------------------------------------------*

class cEnumerator_numberList : public cGenericAbstractEnumerator {
  public : cEnumerator_numberList (const GALGAS_numberList & inEnumeratedObject,
                                   const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_location current_location (LOCATION_ARGS) const ;
  public : class GALGAS_object_5F_t current_value (LOCATION_ARGS) const ;
//--- Current element access
  public : class GALGAS_numberList_2D_element current (LOCATION_ARGS) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_numberList ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 @object_5F_t class                                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_object_5F_t : public AC_GALGAS_class {
//--- Constructor
  public : GALGAS_object_5F_t (void) ;

//---
  public : inline const class cPtr_object_5F_t * ptr (void) const { return (const cPtr_object_5F_t *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_object_5F_t (const cPtr_object_5F_t * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_object_5F_t extractObject (const GALGAS_object & inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_object_5F_t & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_location reader_location (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstring reader_oil_5F_desc (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_object_5F_t class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_object_5F_t ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          Pointer class for @object_t class                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_object_5F_t : public acPtr_class {
//--- Attributes
  public : GALGAS_lstring mAttribute_oil_5F_desc ;
  public : GALGAS_location mAttribute_location ;

//--- Constructor
  public : cPtr_object_5F_t (const GALGAS_lstring & in_oil_5F_desc,
                             const GALGAS_location & in_location
                             COMMA_LOCATION_ARGS) ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_lstring reader_oil_5F_desc (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_location reader_location (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const = 0 ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const = 0 ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const = 0 ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            @numberList_2D_element struct                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_numberList_2D_element : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_location mAttribute_location ;
  public : GALGAS_object_5F_t mAttribute_value ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default constructor
  public : GALGAS_numberList_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_numberList_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS_numberList_2D_element (const GALGAS_location & in_location,
                                         const GALGAS_object_5F_t & in_value) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_numberList_2D_element extractObject (const GALGAS_object & inObject,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_numberList_2D_element constructor_new (const class GALGAS_location & inOperand0,
                                                                const class GALGAS_object_5F_t & inOperand1
                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_numberList_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_location reader_location (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_object_5F_t reader_value (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_numberList_2D_element class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_numberList_2D_element ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 @locationList list                                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_locationList : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public : GALGAS_locationList (void) ;

//--------------------------------- List constructor used by listmap
  public : GALGAS_locationList (cSharedList * inSharedListPtr) ;

//--------------------------------- Element constructor used by listmap
  public : static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                  const class GALGAS_location & in_location
                                                  COMMA_LOCATION_ARGS) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_locationList extractObject (const GALGAS_object & inObject,
                                                     C_Compiler * inCompiler
                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_locationList constructor_emptyList (LOCATION_ARGS) ;

  public : static GALGAS_locationList constructor_listWithValue (const class GALGAS_location & inOperand0
                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public : VIRTUAL_IN_DEBUG void dotAssign_operation (const GALGAS_locationList inOperand
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public : VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_location & inOperand0
                                                      COMMA_LOCATION_ARGS) ;
//--------------------------------- . (concat) operator
  public : VIRTUAL_IN_DEBUG GALGAS_locationList operator_concat (const GALGAS_locationList & inOperand
                                                                 COMMA_LOCATION_ARGS) const ;

//--------------------------------- + operator
  public : VIRTUAL_IN_DEBUG GALGAS_locationList add_operation (const GALGAS_locationList & inOperand,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void modifier_insertAtIndex (class GALGAS_location constinArgument0,
                                                         class GALGAS_uint constinArgument1,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_popFirst (class GALGAS_location & outArgument0,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_popLast (class GALGAS_location & outArgument0,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_removeAtIndex (class GALGAS_location & outArgument0,
                                                         class GALGAS_uint constinArgument1,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_first (class GALGAS_location & outArgument0,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_last (class GALGAS_location & outArgument0,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_location reader_locationAtIndex (const class GALGAS_uint & constinOperand0,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_locationList reader_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                               C_Compiler * inCompiler
                                                                               COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_locationList reader_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                               C_Compiler * inCompiler
                                                                               COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
//--------------------------------- Friend

  friend class cEnumerator_locationList ;
 
} ; // End of GALGAS_locationList class

//---------------------------------------------------------------------------------------------------------------------*
//   Enumerator declaration                                                    *
//---------------------------------------------------------------------------------------------------------------------*

class cEnumerator_locationList : public cGenericAbstractEnumerator {
  public : cEnumerator_locationList (const GALGAS_locationList & inEnumeratedObject,
                                     const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_location current_location (LOCATION_ARGS) const ;
//--- Current element access
  public : class GALGAS_locationList_2D_element current (LOCATION_ARGS) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_locationList ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           @locationList_2D_element struct                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_locationList_2D_element : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_location mAttribute_location ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_locationList_2D_element constructor_default (LOCATION_ARGS) ;

//--------------------------------- Default constructor
  public : GALGAS_locationList_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_locationList_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS_locationList_2D_element (const GALGAS_location & in_location) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_locationList_2D_element extractObject (const GALGAS_object & inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_locationList_2D_element constructor_new (const class GALGAS_location & inOperand0
                                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_locationList_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_location reader_location (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_locationList_2D_element class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_locationList_2D_element ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            @implementationObjectMap map                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cMapElement_implementationObjectMap ;

//---------------------------------------------------------------------------------------------------------------------*

extern const char * kSearchErrorMessage_implementationObjectMap_get ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_implementationObjectMap : public AC_GALGAS_map {
//--------------------------------- Default constructor
  public : GALGAS_implementationObjectMap (void) ;

//--------------------------------- Handle copy
  public : GALGAS_implementationObjectMap (const GALGAS_implementationObjectMap & inSource) ;
  public : GALGAS_implementationObjectMap & operator = (const GALGAS_implementationObjectMap & inSource) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_implementationObjectMap extractObject (const GALGAS_object & inObject,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_implementationObjectMap constructor_emptyMap (LOCATION_ARGS) ;

  public : static GALGAS_implementationObjectMap constructor_mapWithMapToOverride (const class GALGAS_implementationObjectMap & inOperand0
                                                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public : VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0,
                                                      const class GALGAS_impType & inOperand1,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void modifier_del (class GALGAS_lstring constinArgument0,
                                               class GALGAS_impType & outArgument1,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_put (class GALGAS_lstring constinArgument0,
                                               class GALGAS_impType constinArgument1,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setTypeForKey (class GALGAS_impType constinArgument0,
                                                         class GALGAS_string constinArgument1,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_get (class GALGAS_lstring constinArgument0,
                                             class GALGAS_impType & outArgument1,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_implementationObjectMap reader_overriddenMap (C_Compiler * inCompiler
                                                                                       COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_impType reader_typeForKey (const class GALGAS_string & constinOperand0,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
  public : VIRTUAL_IN_DEBUG cMapElement_implementationObjectMap * readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                                     const GALGAS_string & inKey
                                                                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend

  friend class cEnumerator_implementationObjectMap ;
 
} ; // End of GALGAS_implementationObjectMap class

//---------------------------------------------------------------------------------------------------------------------*
//   Enumerator declaration                                                    *
//---------------------------------------------------------------------------------------------------------------------*

class cEnumerator_implementationObjectMap : public cGenericAbstractEnumerator {
  public : cEnumerator_implementationObjectMap (const GALGAS_implementationObjectMap & inEnumeratedObject,
                                                const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_lstring current_lkey (LOCATION_ARGS) const ;
  public : class GALGAS_impType current_type (LOCATION_ARGS) const ;
//--- Current element access
  public : class GALGAS_implementationObjectMap_2D_element current (LOCATION_ARGS) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_implementationObjectMap ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                   @impType class                                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_impType : public AC_GALGAS_class {
//--- Constructor
  public : GALGAS_impType (void) ;

//---
  public : inline const class cPtr_impType * ptr (void) const { return (const cPtr_impType *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_impType (const cPtr_impType * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_impType extractObject (const GALGAS_object & inObject,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_impType & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_lstringlist reader_descs (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_locationList reader_locations (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_multiple (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstring reader_name (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_dataType reader_type (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_impType class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_impType ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Class for element of '@implementationObjectMap' map                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cMapElement_implementationObjectMap : public cMapElement {
//--- Map attributes
  public : GALGAS_impType mAttribute_type ;

//--- Constructor
  public : cMapElement_implementationObjectMap (const GALGAS_lstring & inKey,
                                                const GALGAS_impType & in_type
                                                COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public : virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public : virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public : virtual cMapElement * copy (void) ;

//--- Description
 public : virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     @implementationObjectMap_2D_element struct                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_implementationObjectMap_2D_element : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_lstring mAttribute_lkey ;
  public : GALGAS_impType mAttribute_type ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default constructor
  public : GALGAS_implementationObjectMap_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_implementationObjectMap_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS_implementationObjectMap_2D_element (const GALGAS_lstring & in_lkey,
                                                      const GALGAS_impType & in_type) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_implementationObjectMap_2D_element extractObject (const GALGAS_object & inObject,
                                                                           C_Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_implementationObjectMap_2D_element constructor_new (const class GALGAS_lstring & inOperand0,
                                                                             const class GALGAS_impType & inOperand1
                                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_implementationObjectMap_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_lstring reader_lkey (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_impType reader_type (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_implementationObjectMap_2D_element class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_implementationObjectMap_2D_element ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                   @enumValues map                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cMapElement_enumValues ;

//---------------------------------------------------------------------------------------------------------------------*

extern const char * kSearchErrorMessage_enumValues_get ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_enumValues : public AC_GALGAS_map {
//--------------------------------- Default constructor
  public : GALGAS_enumValues (void) ;

//--------------------------------- Handle copy
  public : GALGAS_enumValues (const GALGAS_enumValues & inSource) ;
  public : GALGAS_enumValues & operator = (const GALGAS_enumValues & inSource) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_enumValues extractObject (const GALGAS_object & inObject,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_enumValues constructor_emptyMap (LOCATION_ARGS) ;

  public : static GALGAS_enumValues constructor_mapWithMapToOverride (const class GALGAS_enumValues & inOperand0
                                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public : VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0,
                                                      const class GALGAS_implementationObjectMap & inOperand1,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void modifier_del (class GALGAS_lstring constinArgument0,
                                               class GALGAS_implementationObjectMap & outArgument1,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_put (class GALGAS_lstring constinArgument0,
                                               class GALGAS_implementationObjectMap constinArgument1,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setSubAttributesForKey (class GALGAS_implementationObjectMap constinArgument0,
                                                                  class GALGAS_string constinArgument1,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_get (class GALGAS_lstring constinArgument0,
                                             class GALGAS_implementationObjectMap & outArgument1,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_enumValues reader_overriddenMap (C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_implementationObjectMap reader_subAttributesForKey (const class GALGAS_string & constinOperand0,
                                                                                             C_Compiler * inCompiler
                                                                                             COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
  public : VIRTUAL_IN_DEBUG cMapElement_enumValues * readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                        const GALGAS_string & inKey
                                                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend

  friend class cEnumerator_enumValues ;
 
} ; // End of GALGAS_enumValues class

//---------------------------------------------------------------------------------------------------------------------*
//   Enumerator declaration                                                    *
//---------------------------------------------------------------------------------------------------------------------*

class cEnumerator_enumValues : public cGenericAbstractEnumerator {
  public : cEnumerator_enumValues (const GALGAS_enumValues & inEnumeratedObject,
                                   const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_lstring current_lkey (LOCATION_ARGS) const ;
  public : class GALGAS_implementationObjectMap current_subAttributes (LOCATION_ARGS) const ;
//--- Current element access
  public : class GALGAS_enumValues_2D_element current (LOCATION_ARGS) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_enumValues ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Class for element of '@enumValues' map                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cMapElement_enumValues : public cMapElement {
//--- Map attributes
  public : GALGAS_implementationObjectMap mAttribute_subAttributes ;

//--- Constructor
  public : cMapElement_enumValues (const GALGAS_lstring & inKey,
                                   const GALGAS_implementationObjectMap & in_subAttributes
                                   COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public : virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public : virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public : virtual cMapElement * copy (void) ;

//--- Description
 public : virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            @enumValues_2D_element struct                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_enumValues_2D_element : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_lstring mAttribute_lkey ;
  public : GALGAS_implementationObjectMap mAttribute_subAttributes ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_enumValues_2D_element constructor_default (LOCATION_ARGS) ;

//--------------------------------- Default constructor
  public : GALGAS_enumValues_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_enumValues_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS_enumValues_2D_element (const GALGAS_lstring & in_lkey,
                                         const GALGAS_implementationObjectMap & in_subAttributes) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_enumValues_2D_element extractObject (const GALGAS_object & inObject,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_enumValues_2D_element constructor_new (const class GALGAS_lstring & inOperand0,
                                                                const class GALGAS_implementationObjectMap & inOperand1
                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_enumValues_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_lstring reader_lkey (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_implementationObjectMap reader_subAttributes (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_enumValues_2D_element class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_enumValues_2D_element ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               @implementationMap map                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cMapElement_implementationMap ;

//---------------------------------------------------------------------------------------------------------------------*

extern const char * kSearchErrorMessage_implementationMap_get ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_implementationMap : public AC_GALGAS_map {
//--------------------------------- Default constructor
  public : GALGAS_implementationMap (void) ;

//--------------------------------- Handle copy
  public : GALGAS_implementationMap (const GALGAS_implementationMap & inSource) ;
  public : GALGAS_implementationMap & operator = (const GALGAS_implementationMap & inSource) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_implementationMap extractObject (const GALGAS_object & inObject,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_implementationMap constructor_emptyMap (LOCATION_ARGS) ;

  public : static GALGAS_implementationMap constructor_mapWithMapToOverride (const class GALGAS_implementationMap & inOperand0
                                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public : VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0,
                                                      const class GALGAS_implementationObject & inOperand1,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void modifier_del (class GALGAS_lstring constinArgument0,
                                               class GALGAS_implementationObject & outArgument1,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_put (class GALGAS_lstring constinArgument0,
                                               class GALGAS_implementationObject constinArgument1,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setObjForKey (class GALGAS_implementationObject constinArgument0,
                                                        class GALGAS_string constinArgument1,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_get (class GALGAS_lstring constinArgument0,
                                             class GALGAS_implementationObject & outArgument1,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_implementationObject reader_objForKey (const class GALGAS_string & constinOperand0,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_implementationMap reader_overriddenMap (C_Compiler * inCompiler
                                                                                 COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
  public : VIRTUAL_IN_DEBUG cMapElement_implementationMap * readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                               const GALGAS_string & inKey
                                                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend

  friend class cEnumerator_implementationMap ;
 
} ; // End of GALGAS_implementationMap class

//---------------------------------------------------------------------------------------------------------------------*
//   Enumerator declaration                                                    *
//---------------------------------------------------------------------------------------------------------------------*

class cEnumerator_implementationMap : public cGenericAbstractEnumerator {
  public : cEnumerator_implementationMap (const GALGAS_implementationMap & inEnumeratedObject,
                                          const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_lstring current_lkey (LOCATION_ARGS) const ;
  public : class GALGAS_implementationObject current_obj (LOCATION_ARGS) const ;
//--- Current element access
  public : class GALGAS_implementationMap_2D_element current (LOCATION_ARGS) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_implementationMap ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             @implementationObject class                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_implementationObject : public AC_GALGAS_class {
//--- Constructor
  public : GALGAS_implementationObject (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_implementationObject constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_implementationObject * ptr (void) const { return (const cPtr_implementationObject *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_implementationObject (const cPtr_implementationObject * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_implementationObject extractObject (const GALGAS_object & inObject,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_implementationObject constructor_new (const class GALGAS_lbool & inOperand0,
                                                               const class GALGAS_implementationObjectMap & inOperand1
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_implementationObject & inOperand) const ;

//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void modifier_setAttributes (class GALGAS_implementationObjectMap inArgument0
                                                         COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setMultiple (class GALGAS_lbool inArgument0
                                                       COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_implementationObjectMap reader_attributes (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lbool reader_multiple (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_implementationObject class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_implementationObject ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Class for element of '@implementationMap' map                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cMapElement_implementationMap : public cMapElement {
//--- Map attributes
  public : GALGAS_implementationObject mAttribute_obj ;

//--- Constructor
  public : cMapElement_implementationMap (const GALGAS_lstring & inKey,
                                          const GALGAS_implementationObject & in_obj
                                          COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public : virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public : virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public : virtual cMapElement * copy (void) ;

//--- Description
 public : virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        @implementationMap_2D_element struct                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_implementationMap_2D_element : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_lstring mAttribute_lkey ;
  public : GALGAS_implementationObject mAttribute_obj ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_implementationMap_2D_element constructor_default (LOCATION_ARGS) ;

//--------------------------------- Default constructor
  public : GALGAS_implementationMap_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_implementationMap_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS_implementationMap_2D_element (const GALGAS_lstring & in_lkey,
                                                const GALGAS_implementationObject & in_obj) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_implementationMap_2D_element extractObject (const GALGAS_object & inObject,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_implementationMap_2D_element constructor_new (const class GALGAS_lstring & inOperand0,
                                                                       const class GALGAS_implementationObject & inOperand1
                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_implementationMap_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_lstring reader_lkey (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_implementationObject reader_obj (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_implementationMap_2D_element class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_implementationMap_2D_element ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 @identifierMap map                                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cMapElement_identifierMap ;

//---------------------------------------------------------------------------------------------------------------------*

extern const char * kSearchErrorMessage_identifierMap_get ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_identifierMap : public AC_GALGAS_map {
//--------------------------------- Default constructor
  public : GALGAS_identifierMap (void) ;

//--------------------------------- Handle copy
  public : GALGAS_identifierMap (const GALGAS_identifierMap & inSource) ;
  public : GALGAS_identifierMap & operator = (const GALGAS_identifierMap & inSource) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_identifierMap extractObject (const GALGAS_object & inObject,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_identifierMap constructor_emptyMap (LOCATION_ARGS) ;

  public : static GALGAS_identifierMap constructor_mapWithMapToOverride (const class GALGAS_identifierMap & inOperand0
                                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public : VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0,
                                                      const class GALGAS_object_5F_t & inOperand1,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void modifier_del (class GALGAS_lstring constinArgument0,
                                               class GALGAS_object_5F_t & outArgument1,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_put (class GALGAS_lstring constinArgument0,
                                               class GALGAS_object_5F_t constinArgument1,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setValueForKey (class GALGAS_object_5F_t constinArgument0,
                                                          class GALGAS_string constinArgument1,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_get (class GALGAS_lstring constinArgument0,
                                             class GALGAS_object_5F_t & outArgument1,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_identifierMap reader_overriddenMap (C_Compiler * inCompiler
                                                                             COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_object_5F_t reader_valueForKey (const class GALGAS_string & constinOperand0,
                                                                         C_Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
  public : VIRTUAL_IN_DEBUG cMapElement_identifierMap * readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                           const GALGAS_string & inKey
                                                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend

  friend class cEnumerator_identifierMap ;
 
} ; // End of GALGAS_identifierMap class

//---------------------------------------------------------------------------------------------------------------------*
//   Enumerator declaration                                                    *
//---------------------------------------------------------------------------------------------------------------------*

class cEnumerator_identifierMap : public cGenericAbstractEnumerator {
  public : cEnumerator_identifierMap (const GALGAS_identifierMap & inEnumeratedObject,
                                      const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_lstring current_lkey (LOCATION_ARGS) const ;
  public : class GALGAS_object_5F_t current_value (LOCATION_ARGS) const ;
//--- Current element access
  public : class GALGAS_identifierMap_2D_element current (LOCATION_ARGS) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_identifierMap ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Class for element of '@identifierMap' map                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cMapElement_identifierMap : public cMapElement {
//--- Map attributes
  public : GALGAS_object_5F_t mAttribute_value ;

//--- Constructor
  public : cMapElement_identifierMap (const GALGAS_lstring & inKey,
                                      const GALGAS_object_5F_t & in_value
                                      COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public : virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public : virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public : virtual cMapElement * copy (void) ;

//--- Description
 public : virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          @identifierMap_2D_element struct                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_identifierMap_2D_element : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_lstring mAttribute_lkey ;
  public : GALGAS_object_5F_t mAttribute_value ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default constructor
  public : GALGAS_identifierMap_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_identifierMap_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS_identifierMap_2D_element (const GALGAS_lstring & in_lkey,
                                            const GALGAS_object_5F_t & in_value) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_identifierMap_2D_element extractObject (const GALGAS_object & inObject,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_identifierMap_2D_element constructor_new (const class GALGAS_lstring & inOperand0,
                                                                   const class GALGAS_object_5F_t & inOperand1
                                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_identifierMap_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_lstring reader_lkey (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_object_5F_t reader_value (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_identifierMap_2D_element class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_identifierMap_2D_element ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                @identifierList list                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_identifierList : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public : GALGAS_identifierList (void) ;

//--------------------------------- List constructor used by listmap
  public : GALGAS_identifierList (cSharedList * inSharedListPtr) ;

//--------------------------------- Element constructor used by listmap
  public : static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                  const class GALGAS_object_5F_t & in_item
                                                  COMMA_LOCATION_ARGS) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_identifierList extractObject (const GALGAS_object & inObject,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_identifierList constructor_emptyList (LOCATION_ARGS) ;

  public : static GALGAS_identifierList constructor_listWithValue (const class GALGAS_object_5F_t & inOperand0
                                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public : VIRTUAL_IN_DEBUG void dotAssign_operation (const GALGAS_identifierList inOperand
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public : VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_object_5F_t & inOperand0
                                                      COMMA_LOCATION_ARGS) ;
//--------------------------------- . (concat) operator
  public : VIRTUAL_IN_DEBUG GALGAS_identifierList operator_concat (const GALGAS_identifierList & inOperand
                                                                   COMMA_LOCATION_ARGS) const ;

//--------------------------------- + operator
  public : VIRTUAL_IN_DEBUG GALGAS_identifierList add_operation (const GALGAS_identifierList & inOperand,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void modifier_insertAtIndex (class GALGAS_object_5F_t constinArgument0,
                                                         class GALGAS_uint constinArgument1,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_popFirst (class GALGAS_object_5F_t & outArgument0,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_popLast (class GALGAS_object_5F_t & outArgument0,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_removeAtIndex (class GALGAS_object_5F_t & outArgument0,
                                                         class GALGAS_uint constinArgument1,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_first (class GALGAS_object_5F_t & outArgument0,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_last (class GALGAS_object_5F_t & outArgument0,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_object_5F_t reader_itemAtIndex (const class GALGAS_uint & constinOperand0,
                                                                         C_Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_identifierList reader_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                                 C_Compiler * inCompiler
                                                                                 COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_identifierList reader_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                                 C_Compiler * inCompiler
                                                                                 COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
//--------------------------------- Friend

  friend class cEnumerator_identifierList ;
 
} ; // End of GALGAS_identifierList class

//---------------------------------------------------------------------------------------------------------------------*
//   Enumerator declaration                                                    *
//---------------------------------------------------------------------------------------------------------------------*

class cEnumerator_identifierList : public cGenericAbstractEnumerator {
  public : cEnumerator_identifierList (const GALGAS_identifierList & inEnumeratedObject,
                                       const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_object_5F_t current_item (LOCATION_ARGS) const ;
//--- Current element access
  public : class GALGAS_identifierList_2D_element current (LOCATION_ARGS) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_identifierList ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          @identifierList_2D_element struct                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_identifierList_2D_element : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_object_5F_t mAttribute_item ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default constructor
  public : GALGAS_identifierList_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_identifierList_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS_identifierList_2D_element (const GALGAS_object_5F_t & in_item) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_identifierList_2D_element extractObject (const GALGAS_object & inObject,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_identifierList_2D_element constructor_new (const class GALGAS_object_5F_t & inOperand0
                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_identifierList_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_object_5F_t reader_item (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_identifierList_2D_element class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_identifierList_2D_element ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                   @stringMap map                                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cMapElement_stringMap ;

//---------------------------------------------------------------------------------------------------------------------*

extern const char * kSearchErrorMessage_stringMap_get ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_stringMap : public AC_GALGAS_map {
//--------------------------------- Default constructor
  public : GALGAS_stringMap (void) ;

//--------------------------------- Handle copy
  public : GALGAS_stringMap (const GALGAS_stringMap & inSource) ;
  public : GALGAS_stringMap & operator = (const GALGAS_stringMap & inSource) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_stringMap extractObject (const GALGAS_object & inObject,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_stringMap constructor_emptyMap (LOCATION_ARGS) ;

  public : static GALGAS_stringMap constructor_mapWithMapToOverride (const class GALGAS_stringMap & inOperand0
                                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public : VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0,
                                                      const class GALGAS_string & inOperand1,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void modifier_put (class GALGAS_lstring constinArgument0,
                                               class GALGAS_string constinArgument1,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setValueForKey (class GALGAS_string constinArgument0,
                                                          class GALGAS_string constinArgument1,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_get (class GALGAS_lstring constinArgument0,
                                             class GALGAS_string & outArgument1,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_stringMap reader_overriddenMap (C_Compiler * inCompiler
                                                                         COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string reader_valueForKey (const class GALGAS_string & constinOperand0,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
  public : VIRTUAL_IN_DEBUG cMapElement_stringMap * readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                       const GALGAS_string & inKey
                                                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend

  friend class cEnumerator_stringMap ;
 
} ; // End of GALGAS_stringMap class

//---------------------------------------------------------------------------------------------------------------------*
//   Enumerator declaration                                                    *
//---------------------------------------------------------------------------------------------------------------------*

class cEnumerator_stringMap : public cGenericAbstractEnumerator {
  public : cEnumerator_stringMap (const GALGAS_stringMap & inEnumeratedObject,
                                  const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_lstring current_lkey (LOCATION_ARGS) const ;
  public : class GALGAS_string current_value (LOCATION_ARGS) const ;
//--- Current element access
  public : class GALGAS_stringMap_2D_element current (LOCATION_ARGS) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_stringMap ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Class for element of '@stringMap' map                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cMapElement_stringMap : public cMapElement {
//--- Map attributes
  public : GALGAS_string mAttribute_value ;

//--- Constructor
  public : cMapElement_stringMap (const GALGAS_lstring & inKey,
                                  const GALGAS_string & in_value
                                  COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public : virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public : virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public : virtual cMapElement * copy (void) ;

//--- Description
 public : virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            @stringMap_2D_element struct                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_stringMap_2D_element : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_lstring mAttribute_lkey ;
  public : GALGAS_string mAttribute_value ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_stringMap_2D_element constructor_default (LOCATION_ARGS) ;

//--------------------------------- Default constructor
  public : GALGAS_stringMap_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_stringMap_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS_stringMap_2D_element (const GALGAS_lstring & in_lkey,
                                        const GALGAS_string & in_value) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_stringMap_2D_element extractObject (const GALGAS_object & inObject,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_stringMap_2D_element constructor_new (const class GALGAS_lstring & inOperand0,
                                                               const class GALGAS_string & inOperand1
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_stringMap_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_lstring reader_lkey (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string reader_value (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_stringMap_2D_element class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_stringMap_2D_element ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                   @lstringMap map                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cMapElement_lstringMap ;

//---------------------------------------------------------------------------------------------------------------------*

extern const char * kSearchErrorMessage_lstringMap_get ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_lstringMap : public AC_GALGAS_map {
//--------------------------------- Default constructor
  public : GALGAS_lstringMap (void) ;

//--------------------------------- Handle copy
  public : GALGAS_lstringMap (const GALGAS_lstringMap & inSource) ;
  public : GALGAS_lstringMap & operator = (const GALGAS_lstringMap & inSource) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_lstringMap extractObject (const GALGAS_object & inObject,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_lstringMap constructor_emptyMap (LOCATION_ARGS) ;

  public : static GALGAS_lstringMap constructor_mapWithMapToOverride (const class GALGAS_lstringMap & inOperand0
                                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public : VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0,
                                                      const class GALGAS_lstring & inOperand1,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void modifier_put (class GALGAS_lstring constinArgument0,
                                               class GALGAS_lstring constinArgument1,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setValueForKey (class GALGAS_lstring constinArgument0,
                                                          class GALGAS_string constinArgument1,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_get (class GALGAS_lstring constinArgument0,
                                             class GALGAS_lstring & outArgument1,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_lstringMap reader_overriddenMap (C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstring reader_valueForKey (const class GALGAS_string & constinOperand0,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
  public : VIRTUAL_IN_DEBUG cMapElement_lstringMap * readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                        const GALGAS_string & inKey
                                                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend

  friend class cEnumerator_lstringMap ;
 
} ; // End of GALGAS_lstringMap class

//---------------------------------------------------------------------------------------------------------------------*
//   Enumerator declaration                                                    *
//---------------------------------------------------------------------------------------------------------------------*

class cEnumerator_lstringMap : public cGenericAbstractEnumerator {
  public : cEnumerator_lstringMap (const GALGAS_lstringMap & inEnumeratedObject,
                                   const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_lstring current_lkey (LOCATION_ARGS) const ;
  public : class GALGAS_lstring current_value (LOCATION_ARGS) const ;
//--- Current element access
  public : class GALGAS_lstringMap_2D_element current (LOCATION_ARGS) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_lstringMap ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Class for element of '@lstringMap' map                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cMapElement_lstringMap : public cMapElement {
//--- Map attributes
  public : GALGAS_lstring mAttribute_value ;

//--- Constructor
  public : cMapElement_lstringMap (const GALGAS_lstring & inKey,
                                   const GALGAS_lstring & in_value
                                   COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public : virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public : virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public : virtual cMapElement * copy (void) ;

//--- Description
 public : virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            @lstringMap_2D_element struct                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_lstringMap_2D_element : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_lstring mAttribute_lkey ;
  public : GALGAS_lstring mAttribute_value ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_lstringMap_2D_element constructor_default (LOCATION_ARGS) ;

//--------------------------------- Default constructor
  public : GALGAS_lstringMap_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_lstringMap_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS_lstringMap_2D_element (const GALGAS_lstring & in_lkey,
                                         const GALGAS_lstring & in_value) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_lstringMap_2D_element extractObject (const GALGAS_object & inObject,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_lstringMap_2D_element constructor_new (const class GALGAS_lstring & inOperand0,
                                                                const class GALGAS_lstring & inOperand1
                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_lstringMap_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_lstring reader_lkey (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstring reader_value (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_lstringMap_2D_element class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_lstringMap_2D_element ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                   @prefix_map map                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cMapElement_prefix_5F_map ;

//---------------------------------------------------------------------------------------------------------------------*

extern const char * kSearchErrorMessage_prefix_5F_map_prefix ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_prefix_5F_map : public AC_GALGAS_map {
//--------------------------------- Default constructor
  public : GALGAS_prefix_5F_map (void) ;

//--------------------------------- Handle copy
  public : GALGAS_prefix_5F_map (const GALGAS_prefix_5F_map & inSource) ;
  public : GALGAS_prefix_5F_map & operator = (const GALGAS_prefix_5F_map & inSource) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_prefix_5F_map extractObject (const GALGAS_object & inObject,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_prefix_5F_map constructor_emptyMap (LOCATION_ARGS) ;

  public : static GALGAS_prefix_5F_map constructor_mapWithMapToOverride (const class GALGAS_prefix_5F_map & inOperand0
                                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public : VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0,
                                                      const class GALGAS_string & inOperand1,
                                                      const class GALGAS_string & inOperand2,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void modifier_add (class GALGAS_lstring constinArgument0,
                                               class GALGAS_string constinArgument1,
                                               class GALGAS_string constinArgument2,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_insert_5F_prefix (class GALGAS_lstring constinArgument0,
                                                            class GALGAS_string constinArgument1,
                                                            class GALGAS_string constinArgument2,
                                                            C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setPrefixForKey (class GALGAS_string constinArgument0,
                                                           class GALGAS_string constinArgument1,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setTag_5F_to_5F_repForKey (class GALGAS_string constinArgument0,
                                                                     class GALGAS_string constinArgument1,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_prefix (class GALGAS_lstring constinArgument0,
                                                class GALGAS_string & outArgument1,
                                                class GALGAS_string & outArgument2,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_prefix_5F_map reader_overriddenMap (C_Compiler * inCompiler
                                                                             COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string reader_prefixForKey (const class GALGAS_string & constinOperand0,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string reader_tag_5F_to_5F_repForKey (const class GALGAS_string & constinOperand0,
                                                                               C_Compiler * inCompiler
                                                                               COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
  public : VIRTUAL_IN_DEBUG cMapElement_prefix_5F_map * readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                           const GALGAS_string & inKey
                                                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend

  friend class cEnumerator_prefix_5F_map ;
 
} ; // End of GALGAS_prefix_5F_map class

//---------------------------------------------------------------------------------------------------------------------*
//   Enumerator declaration                                                    *
//---------------------------------------------------------------------------------------------------------------------*

class cEnumerator_prefix_5F_map : public cGenericAbstractEnumerator {
  public : cEnumerator_prefix_5F_map (const GALGAS_prefix_5F_map & inEnumeratedObject,
                                      const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_lstring current_lkey (LOCATION_ARGS) const ;
  public : class GALGAS_string current_prefix (LOCATION_ARGS) const ;
  public : class GALGAS_string current_tag_5F_to_5F_rep (LOCATION_ARGS) const ;
//--- Current element access
  public : class GALGAS_prefix_5F_map_2D_element current (LOCATION_ARGS) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_prefix_5F_map ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Class for element of '@prefix_map' map                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cMapElement_prefix_5F_map : public cMapElement {
//--- Map attributes
  public : GALGAS_string mAttribute_prefix ;
  public : GALGAS_string mAttribute_tag_5F_to_5F_rep ;

//--- Constructor
  public : cMapElement_prefix_5F_map (const GALGAS_lstring & inKey,
                                      const GALGAS_string & in_prefix,
                                      const GALGAS_string & in_tag_5F_to_5F_rep
                                      COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public : virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public : virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public : virtual cMapElement * copy (void) ;

//--- Description
 public : virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          @prefix_5F_map_2D_element struct                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_prefix_5F_map_2D_element : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_lstring mAttribute_lkey ;
  public : GALGAS_string mAttribute_prefix ;
  public : GALGAS_string mAttribute_tag_5F_to_5F_rep ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_prefix_5F_map_2D_element constructor_default (LOCATION_ARGS) ;

//--------------------------------- Default constructor
  public : GALGAS_prefix_5F_map_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_prefix_5F_map_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS_prefix_5F_map_2D_element (const GALGAS_lstring & in_lkey,
                                            const GALGAS_string & in_prefix,
                                            const GALGAS_string & in_tag_5F_to_5F_rep) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_prefix_5F_map_2D_element extractObject (const GALGAS_object & inObject,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_prefix_5F_map_2D_element constructor_new (const class GALGAS_lstring & inOperand0,
                                                                   const class GALGAS_string & inOperand1,
                                                                   const class GALGAS_string & inOperand2
                                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_prefix_5F_map_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_lstring reader_lkey (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string reader_prefix (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string reader_tag_5F_to_5F_rep (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_prefix_5F_map_2D_element class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_prefix_5F_map_2D_element ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 @stringset_map map                                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cMapElement_stringset_5F_map ;

//---------------------------------------------------------------------------------------------------------------------*

extern const char * kSearchErrorMessage_stringset_5F_map_get ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_stringset_5F_map : public AC_GALGAS_map {
//--------------------------------- Default constructor
  public : GALGAS_stringset_5F_map (void) ;

//--------------------------------- Handle copy
  public : GALGAS_stringset_5F_map (const GALGAS_stringset_5F_map & inSource) ;
  public : GALGAS_stringset_5F_map & operator = (const GALGAS_stringset_5F_map & inSource) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_stringset_5F_map extractObject (const GALGAS_object & inObject,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_stringset_5F_map constructor_emptyMap (LOCATION_ARGS) ;

  public : static GALGAS_stringset_5F_map constructor_mapWithMapToOverride (const class GALGAS_stringset_5F_map & inOperand0
                                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public : VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0,
                                                      const class GALGAS_stringset & inOperand1,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void modifier_add (class GALGAS_lstring constinArgument0,
                                               class GALGAS_stringset constinArgument1,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_delete (class GALGAS_lstring constinArgument0,
                                                  class GALGAS_stringset & outArgument1,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setIdsForKey (class GALGAS_stringset constinArgument0,
                                                        class GALGAS_string constinArgument1,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_get (class GALGAS_lstring constinArgument0,
                                             class GALGAS_stringset & outArgument1,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_stringset reader_idsForKey (const class GALGAS_string & constinOperand0,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_stringset_5F_map reader_overriddenMap (C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
  public : VIRTUAL_IN_DEBUG cMapElement_stringset_5F_map * readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                              const GALGAS_string & inKey
                                                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend

  friend class cEnumerator_stringset_5F_map ;
 
} ; // End of GALGAS_stringset_5F_map class

//---------------------------------------------------------------------------------------------------------------------*
//   Enumerator declaration                                                    *
//---------------------------------------------------------------------------------------------------------------------*

class cEnumerator_stringset_5F_map : public cGenericAbstractEnumerator {
  public : cEnumerator_stringset_5F_map (const GALGAS_stringset_5F_map & inEnumeratedObject,
                                         const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_lstring current_lkey (LOCATION_ARGS) const ;
  public : class GALGAS_stringset current_ids (LOCATION_ARGS) const ;
//--- Current element access
  public : class GALGAS_stringset_5F_map_2D_element current (LOCATION_ARGS) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_stringset_5F_map ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Class for element of '@stringset_map' map                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cMapElement_stringset_5F_map : public cMapElement {
//--- Map attributes
  public : GALGAS_stringset mAttribute_ids ;

//--- Constructor
  public : cMapElement_stringset_5F_map (const GALGAS_lstring & inKey,
                                         const GALGAS_stringset & in_ids
                                         COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public : virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public : virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public : virtual cMapElement * copy (void) ;

//--- Description
 public : virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         @stringset_5F_map_2D_element struct                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_stringset_5F_map_2D_element : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_lstring mAttribute_lkey ;
  public : GALGAS_stringset mAttribute_ids ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_stringset_5F_map_2D_element constructor_default (LOCATION_ARGS) ;

//--------------------------------- Default constructor
  public : GALGAS_stringset_5F_map_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_stringset_5F_map_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS_stringset_5F_map_2D_element (const GALGAS_lstring & in_lkey,
                                               const GALGAS_stringset & in_ids) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_stringset_5F_map_2D_element extractObject (const GALGAS_object & inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_stringset_5F_map_2D_element constructor_new (const class GALGAS_lstring & inOperand0,
                                                                      const class GALGAS_stringset & inOperand1
                                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_stringset_5F_map_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_stringset reader_ids (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstring reader_lkey (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_stringset_5F_map_2D_element class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_stringset_5F_map_2D_element ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  @ident_list list                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_ident_5F_list : public AC_GALGAS_list {
//--------------------------------- Default constructor
  public : GALGAS_ident_5F_list (void) ;

//--------------------------------- List constructor used by listmap
  public : GALGAS_ident_5F_list (cSharedList * inSharedListPtr) ;

//--------------------------------- Element constructor used by listmap
  public : static void makeAttributesFromObjects (capCollectionElement & outAttributes,
                                                  const class GALGAS_lstring & in_obj_5F_name
                                                  COMMA_LOCATION_ARGS) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_ident_5F_list extractObject (const GALGAS_object & inObject,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_ident_5F_list constructor_emptyList (LOCATION_ARGS) ;

  public : static GALGAS_ident_5F_list constructor_listWithValue (const class GALGAS_lstring & inOperand0
                                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with expression)
  public : VIRTUAL_IN_DEBUG void dotAssign_operation (const GALGAS_ident_5F_list inOperand
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public : VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0
                                                      COMMA_LOCATION_ARGS) ;
//--------------------------------- . (concat) operator
  public : VIRTUAL_IN_DEBUG GALGAS_ident_5F_list operator_concat (const GALGAS_ident_5F_list & inOperand
                                                                  COMMA_LOCATION_ARGS) const ;

//--------------------------------- + operator
  public : VIRTUAL_IN_DEBUG GALGAS_ident_5F_list add_operation (const GALGAS_ident_5F_list & inOperand,
                                                                C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) const ;


//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void modifier_insertAtIndex (class GALGAS_lstring constinArgument0,
                                                         class GALGAS_uint constinArgument1,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_popFirst (class GALGAS_lstring & outArgument0,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_popLast (class GALGAS_lstring & outArgument0,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_removeAtIndex (class GALGAS_lstring & outArgument0,
                                                         class GALGAS_uint constinArgument1,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_first (class GALGAS_lstring & outArgument0,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG void method_last (class GALGAS_lstring & outArgument0,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_lstring reader_obj_5F_nameAtIndex (const class GALGAS_uint & constinOperand0,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_ident_5F_list reader_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_ident_5F_list reader_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
//--------------------------------- Friend

  friend class cEnumerator_ident_5F_list ;
 
} ; // End of GALGAS_ident_5F_list class

//---------------------------------------------------------------------------------------------------------------------*
//   Enumerator declaration                                                    *
//---------------------------------------------------------------------------------------------------------------------*

class cEnumerator_ident_5F_list : public cGenericAbstractEnumerator {
  public : cEnumerator_ident_5F_list (const GALGAS_ident_5F_list & inEnumeratedObject,
                                      const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_lstring current_obj_5F_name (LOCATION_ARGS) const ;
//--- Current element access
  public : class GALGAS_ident_5F_list_2D_element current (LOCATION_ARGS) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_ident_5F_list ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          @ident_5F_list_2D_element struct                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_ident_5F_list_2D_element : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_lstring mAttribute_obj_5F_name ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_ident_5F_list_2D_element constructor_default (LOCATION_ARGS) ;

//--------------------------------- Default constructor
  public : GALGAS_ident_5F_list_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_ident_5F_list_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS_ident_5F_list_2D_element (const GALGAS_lstring & in_obj_5F_name) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_ident_5F_list_2D_element extractObject (const GALGAS_object & inObject,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_ident_5F_list_2D_element constructor_new (const class GALGAS_lstring & inOperand0
                                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_ident_5F_list_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_lstring reader_obj_5F_name (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_ident_5F_list_2D_element class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_ident_5F_list_2D_element ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 @ident_list_map map                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cMapElement_ident_5F_list_5F_map ;

//---------------------------------------------------------------------------------------------------------------------*

extern const char * kSearchErrorMessage_ident_5F_list_5F_map_get ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_ident_5F_list_5F_map : public AC_GALGAS_map {
//--------------------------------- Default constructor
  public : GALGAS_ident_5F_list_5F_map (void) ;

//--------------------------------- Handle copy
  public : GALGAS_ident_5F_list_5F_map (const GALGAS_ident_5F_list_5F_map & inSource) ;
  public : GALGAS_ident_5F_list_5F_map & operator = (const GALGAS_ident_5F_list_5F_map & inSource) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_ident_5F_list_5F_map extractObject (const GALGAS_object & inObject,
                                                             C_Compiler * inCompiler
                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_ident_5F_list_5F_map constructor_emptyMap (LOCATION_ARGS) ;

  public : static GALGAS_ident_5F_list_5F_map constructor_mapWithMapToOverride (const class GALGAS_ident_5F_list_5F_map & inOperand0
                                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public : VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0,
                                                      const class GALGAS_ident_5F_list & inOperand1,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void modifier_add (class GALGAS_lstring constinArgument0,
                                               class GALGAS_ident_5F_list constinArgument1,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_delete (class GALGAS_lstring constinArgument0,
                                                  class GALGAS_ident_5F_list & outArgument1,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setObjsForKey (class GALGAS_ident_5F_list constinArgument0,
                                                         class GALGAS_string constinArgument1,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_get (class GALGAS_lstring constinArgument0,
                                             class GALGAS_ident_5F_list & outArgument1,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_ident_5F_list reader_objsForKey (const class GALGAS_string & constinOperand0,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_ident_5F_list_5F_map reader_overriddenMap (C_Compiler * inCompiler
                                                                                    COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
  public : VIRTUAL_IN_DEBUG cMapElement_ident_5F_list_5F_map * readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                                  const GALGAS_string & inKey
                                                                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend

  friend class cEnumerator_ident_5F_list_5F_map ;
 
} ; // End of GALGAS_ident_5F_list_5F_map class

//---------------------------------------------------------------------------------------------------------------------*
//   Enumerator declaration                                                    *
//---------------------------------------------------------------------------------------------------------------------*

class cEnumerator_ident_5F_list_5F_map : public cGenericAbstractEnumerator {
  public : cEnumerator_ident_5F_list_5F_map (const GALGAS_ident_5F_list_5F_map & inEnumeratedObject,
                                             const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_lstring current_lkey (LOCATION_ARGS) const ;
  public : class GALGAS_ident_5F_list current_objs (LOCATION_ARGS) const ;
//--- Current element access
  public : class GALGAS_ident_5F_list_5F_map_2D_element current (LOCATION_ARGS) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_ident_5F_list_5F_map ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Class for element of '@ident_list_map' map                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cMapElement_ident_5F_list_5F_map : public cMapElement {
//--- Map attributes
  public : GALGAS_ident_5F_list mAttribute_objs ;

//--- Constructor
  public : cMapElement_ident_5F_list_5F_map (const GALGAS_lstring & inKey,
                                             const GALGAS_ident_5F_list & in_objs
                                             COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public : virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public : virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public : virtual cMapElement * copy (void) ;

//--- Description
 public : virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       @ident_5F_list_5F_map_2D_element struct                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_ident_5F_list_5F_map_2D_element : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_lstring mAttribute_lkey ;
  public : GALGAS_ident_5F_list mAttribute_objs ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_ident_5F_list_5F_map_2D_element constructor_default (LOCATION_ARGS) ;

//--------------------------------- Default constructor
  public : GALGAS_ident_5F_list_5F_map_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_ident_5F_list_5F_map_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS_ident_5F_list_5F_map_2D_element (const GALGAS_lstring & in_lkey,
                                                   const GALGAS_ident_5F_list & in_objs) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_ident_5F_list_5F_map_2D_element extractObject (const GALGAS_object & inObject,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_ident_5F_list_5F_map_2D_element constructor_new (const class GALGAS_lstring & inOperand0,
                                                                          const class GALGAS_ident_5F_list & inOperand1
                                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_ident_5F_list_5F_map_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_lstring reader_lkey (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_ident_5F_list reader_objs (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_ident_5F_list_5F_map_2D_element class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_ident_5F_list_5F_map_2D_element ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                   @objectsMap map                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cMapElement_objectsMap ;

//---------------------------------------------------------------------------------------------------------------------*

extern const char * kSearchErrorMessage_objectsMap_get ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_objectsMap : public AC_GALGAS_map {
//--------------------------------- Default constructor
  public : GALGAS_objectsMap (void) ;

//--------------------------------- Handle copy
  public : GALGAS_objectsMap (const GALGAS_objectsMap & inSource) ;
  public : GALGAS_objectsMap & operator = (const GALGAS_objectsMap & inSource) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_objectsMap extractObject (const GALGAS_object & inObject,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_objectsMap constructor_emptyMap (LOCATION_ARGS) ;

  public : static GALGAS_objectsMap constructor_mapWithMapToOverride (const class GALGAS_objectsMap & inOperand0
                                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public : VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0,
                                                      const class GALGAS_objectKind & inOperand1,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void modifier_del (class GALGAS_lstring constinArgument0,
                                               class GALGAS_objectKind & outArgument1,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_put (class GALGAS_lstring constinArgument0,
                                               class GALGAS_objectKind constinArgument1,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setObjectsOfKindForKey (class GALGAS_objectKind constinArgument0,
                                                                  class GALGAS_string constinArgument1,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_get (class GALGAS_lstring constinArgument0,
                                             class GALGAS_objectKind & outArgument1,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_objectKind reader_objectsOfKindForKey (const class GALGAS_string & constinOperand0,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_objectsMap reader_overriddenMap (C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
  public : VIRTUAL_IN_DEBUG cMapElement_objectsMap * readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                        const GALGAS_string & inKey
                                                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend

  friend class cEnumerator_objectsMap ;
 
} ; // End of GALGAS_objectsMap class

//---------------------------------------------------------------------------------------------------------------------*
//   Enumerator declaration                                                    *
//---------------------------------------------------------------------------------------------------------------------*

class cEnumerator_objectsMap : public cGenericAbstractEnumerator {
  public : cEnumerator_objectsMap (const GALGAS_objectsMap & inEnumeratedObject,
                                   const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_lstring current_lkey (LOCATION_ARGS) const ;
  public : class GALGAS_objectKind current_objectsOfKind (LOCATION_ARGS) const ;
//--- Current element access
  public : class GALGAS_objectsMap_2D_element current (LOCATION_ARGS) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_objectsMap ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  @objectKind class                                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_objectKind : public AC_GALGAS_class {
//--- Constructor
  public : GALGAS_objectKind (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_objectKind constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_objectKind * ptr (void) const { return (const cPtr_objectKind *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_objectKind (const cPtr_objectKind * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_objectKind extractObject (const GALGAS_object & inObject,
                                                   C_Compiler * inCompiler
                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_objectKind constructor_new (const class GALGAS_objectKindMap & inOperand0
                                                     COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_objectKind & inOperand) const ;

//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void modifier_setObjects (class GALGAS_objectKindMap inArgument0
                                                      COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_objectKindMap reader_objects (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_objectKind class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_objectKind ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Class for element of '@objectsMap' map                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cMapElement_objectsMap : public cMapElement {
//--- Map attributes
  public : GALGAS_objectKind mAttribute_objectsOfKind ;

//--- Constructor
  public : cMapElement_objectsMap (const GALGAS_lstring & inKey,
                                   const GALGAS_objectKind & in_objectsOfKind
                                   COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public : virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public : virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public : virtual cMapElement * copy (void) ;

//--- Description
 public : virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            @objectsMap_2D_element struct                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_objectsMap_2D_element : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_lstring mAttribute_lkey ;
  public : GALGAS_objectKind mAttribute_objectsOfKind ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_objectsMap_2D_element constructor_default (LOCATION_ARGS) ;

//--------------------------------- Default constructor
  public : GALGAS_objectsMap_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_objectsMap_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS_objectsMap_2D_element (const GALGAS_lstring & in_lkey,
                                         const GALGAS_objectKind & in_objectsOfKind) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_objectsMap_2D_element extractObject (const GALGAS_object & inObject,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_objectsMap_2D_element constructor_new (const class GALGAS_lstring & inOperand0,
                                                                const class GALGAS_objectKind & inOperand1
                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_objectsMap_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_lstring reader_lkey (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_objectKind reader_objectsOfKind (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_objectsMap_2D_element class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_objectsMap_2D_element ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 @objectKindMap map                                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cMapElement_objectKindMap ;

//---------------------------------------------------------------------------------------------------------------------*

extern const char * kSearchErrorMessage_objectKindMap_get ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_objectKindMap : public AC_GALGAS_map {
//--------------------------------- Default constructor
  public : GALGAS_objectKindMap (void) ;

//--------------------------------- Handle copy
  public : GALGAS_objectKindMap (const GALGAS_objectKindMap & inSource) ;
  public : GALGAS_objectKindMap & operator = (const GALGAS_objectKindMap & inSource) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_objectKindMap extractObject (const GALGAS_object & inObject,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_objectKindMap constructor_emptyMap (LOCATION_ARGS) ;

  public : static GALGAS_objectKindMap constructor_mapWithMapToOverride (const class GALGAS_objectKindMap & inOperand0
                                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- += operator (with list of field expressions)
  public : VIRTUAL_IN_DEBUG void addAssign_operation (const class GALGAS_lstring & inOperand0,
                                                      const class GALGAS_objectAttributes & inOperand1,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void modifier_del (class GALGAS_lstring constinArgument0,
                                               class GALGAS_objectAttributes & outArgument1,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_put (class GALGAS_lstring constinArgument0,
                                               class GALGAS_objectAttributes constinArgument1,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setAttributesForKey (class GALGAS_objectAttributes constinArgument0,
                                                               class GALGAS_string constinArgument1,
                                                               C_Compiler * inCompiler
                                                               COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_get (class GALGAS_lstring constinArgument0,
                                             class GALGAS_objectAttributes & outArgument1,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_objectAttributes reader_attributesForKey (const class GALGAS_string & constinOperand0,
                                                                                   C_Compiler * inCompiler
                                                                                   COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_objectKindMap reader_overriddenMap (C_Compiler * inCompiler
                                                                             COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
  public : VIRTUAL_IN_DEBUG cMapElement_objectKindMap * readWriteAccessForWithInstruction (C_Compiler * inCompiler,
                                                                                           const GALGAS_string & inKey
                                                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend

  friend class cEnumerator_objectKindMap ;
 
} ; // End of GALGAS_objectKindMap class

//---------------------------------------------------------------------------------------------------------------------*
//   Enumerator declaration                                                    *
//---------------------------------------------------------------------------------------------------------------------*

class cEnumerator_objectKindMap : public cGenericAbstractEnumerator {
  public : cEnumerator_objectKindMap (const GALGAS_objectKindMap & inEnumeratedObject,
                                      const typeEnumerationOrder inOrder) ;

//--- Current element access
  public : class GALGAS_lstring current_lkey (LOCATION_ARGS) const ;
  public : class GALGAS_objectAttributes current_attributes (LOCATION_ARGS) const ;
//--- Current element access
  public : class GALGAS_objectKindMap_2D_element current (LOCATION_ARGS) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_objectKindMap ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               @objectAttributes class                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_objectAttributes : public AC_GALGAS_class {
//--- Constructor
  public : GALGAS_objectAttributes (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_objectAttributes constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_objectAttributes * ptr (void) const { return (const cPtr_objectAttributes *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_objectAttributes (const cPtr_objectAttributes * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_objectAttributes extractObject (const GALGAS_object & inObject,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_objectAttributes constructor_new (const class GALGAS_identifierMap & inOperand0
                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_objectAttributes & inOperand) const ;

//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void modifier_setObjectParams (class GALGAS_identifierMap inArgument0
                                                           COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_identifierMap reader_objectParams (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_objectAttributes class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_objectAttributes ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Class for element of '@objectKindMap' map                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cMapElement_objectKindMap : public cMapElement {
//--- Map attributes
  public : GALGAS_objectAttributes mAttribute_attributes ;

//--- Constructor
  public : cMapElement_objectKindMap (const GALGAS_lstring & inKey,
                                      const GALGAS_objectAttributes & in_attributes
                                      COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public : virtual typeComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public : virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public : virtual cMapElement * copy (void) ;

//--- Description
 public : virtual void description (C_String & ioString, const int32_t inIndentation) const ;
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          @objectKindMap_2D_element struct                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_objectKindMap_2D_element : public AC_GALGAS_root {
//--------------------------------- Public data members
  public : GALGAS_lstring mAttribute_lkey ;
  public : GALGAS_objectAttributes mAttribute_attributes ;


//--------------------------------- Accessors
  public : VIRTUAL_IN_DEBUG bool isValid (void) const ;
  public : VIRTUAL_IN_DEBUG void drop (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_objectKindMap_2D_element constructor_default (LOCATION_ARGS) ;

//--------------------------------- Default constructor
  public : GALGAS_objectKindMap_2D_element (void) ;

//--------------------------------- Virtual destructor (in debug mode)
  public : VIRTUAL_IN_DEBUG ~ GALGAS_objectKindMap_2D_element (void) ;

//--------------------------------- Native constructor
  public : GALGAS_objectKindMap_2D_element (const GALGAS_lstring & in_lkey,
                                            const GALGAS_objectAttributes & in_attributes) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_objectKindMap_2D_element extractObject (const GALGAS_object & inObject,
                                                                 C_Compiler * inCompiler
                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_objectKindMap_2D_element constructor_new (const class GALGAS_lstring & inOperand0,
                                                                   const class GALGAS_objectAttributes & inOperand1
                                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- Implementation of reader 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_objectKindMap_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_objectAttributes reader_attributes (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstring reader_lkey (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_objectKindMap_2D_element class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_objectKindMap_2D_element ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Parser class 'goil_syntax' declaration                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cParser_goil_5F_syntax {
//--- Virtual destructor
  public : virtual ~ cParser_goil_5F_syntax (void) {}

//--- Non terminal declarations
  protected : virtual void nt_OIL_5F_version_ (class GALGAS_lstring & outArgument0,
                                               class GALGAS_lstring & outArgument1,
                                               class C_Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected : virtual void nt_OIL_5F_version_parse (class C_Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected : virtual void nt_application_5F_definition_ (const class GALGAS_implementation constinArgument0,
                                                          class GALGAS_applicationDefinition & ioArgument1,
                                                          class C_Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected : virtual void nt_application_5F_definition_parse (class C_Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected : virtual void nt_boolean_ (class GALGAS_lbool & outArgument0,
                                        class C_Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected : virtual void nt_boolean_parse (class C_Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected : virtual void nt_description_ (class GALGAS_lstring & outArgument0,
                                            class C_Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected : virtual void nt_description_parse (class C_Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected : virtual void nt_file_ (class GALGAS_implementation & ioArgument0,
                                     class GALGAS_applicationDefinition & ioArgument1,
                                     class C_Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected : virtual void nt_file_parse (class C_Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected : virtual void nt_implementation_5F_definition_ (class GALGAS_implementation & ioArgument0,
                                                             class C_Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected : virtual void nt_implementation_5F_definition_parse (class C_Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected : virtual void nt_include_5F_cpu_5F_level_ (const class GALGAS_implementation constinArgument0,
                                                        class GALGAS_objectsMap & ioArgument1,
                                                        class C_Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected : virtual void nt_include_5F_cpu_5F_level_parse (class C_Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected : virtual void nt_include_5F_file_5F_level_ (class GALGAS_implementation & ioArgument0,
                                                         class GALGAS_applicationDefinition & ioArgument1,
                                                         class C_Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected : virtual void nt_include_5F_file_5F_level_parse (class C_Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected : virtual void nt_object_5F_definition_5F_list_ (const class GALGAS_implementation constinArgument0,
                                                             class GALGAS_objectsMap & ioArgument1,
                                                             class C_Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected : virtual void nt_object_5F_definition_5F_list_parse (class C_Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected : virtual void nt_oil_5F_declaration_ (const class GALGAS_implementationObjectMap constinArgument0,
                                                   class GALGAS_objectAttributes & ioArgument1,
                                                   class C_Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected : virtual void nt_oil_5F_declaration_parse (class C_Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected : virtual void nt_oil_5F_declaration_5F_list_ (const class GALGAS_implementationObjectMap constinArgument0,
                                                           class GALGAS_objectAttributes & ioArgument1,
                                                           class C_Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected : virtual void nt_oil_5F_declaration_5F_list_parse (class C_Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected : virtual void nt_sign_ (class GALGAS_bool & outArgument0,
                                     class C_Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected : virtual void nt_sign_parse (class C_Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected : virtual void nt_start_ (class C_Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected : virtual void nt_start_parse (class C_Lexique_goil_5F_lexique * inLexique) = 0 ;


//--- Rule declarations
  protected : void rule_goil_5F_syntax_start_i0_ (C_Lexique_goil_5F_lexique * inLexique) ;

  protected : void rule_goil_5F_syntax_start_i0_parse (C_Lexique_goil_5F_lexique * inLexique) ;

  protected : void rule_goil_5F_syntax_file_i1_ (GALGAS_implementation & ioArgument0,
                                                 GALGAS_applicationDefinition & ioArgument1,
                                                 C_Lexique_goil_5F_lexique * inLexique) ;

  protected : void rule_goil_5F_syntax_file_i1_parse (C_Lexique_goil_5F_lexique * inLexique) ;

  protected : void rule_goil_5F_syntax_sign_i2_ (GALGAS_bool & outArgument0,
                                                 C_Lexique_goil_5F_lexique * inLexique) ;

  protected : void rule_goil_5F_syntax_sign_i2_parse (C_Lexique_goil_5F_lexique * inLexique) ;

  protected : void rule_goil_5F_syntax_description_i3_ (GALGAS_lstring & outArgument0,
                                                        C_Lexique_goil_5F_lexique * inLexique) ;

  protected : void rule_goil_5F_syntax_description_i3_parse (C_Lexique_goil_5F_lexique * inLexique) ;

  protected : void rule_goil_5F_syntax_OIL_5F_version_i4_ (GALGAS_lstring & outArgument0,
                                                           GALGAS_lstring & outArgument1,
                                                           C_Lexique_goil_5F_lexique * inLexique) ;

  protected : void rule_goil_5F_syntax_OIL_5F_version_i4_parse (C_Lexique_goil_5F_lexique * inLexique) ;

  protected : void rule_goil_5F_syntax_application_5F_definition_i5_ (const GALGAS_implementation constinArgument0,
                                                                      GALGAS_applicationDefinition & ioArgument1,
                                                                      C_Lexique_goil_5F_lexique * inLexique) ;

  protected : void rule_goil_5F_syntax_application_5F_definition_i5_parse (C_Lexique_goil_5F_lexique * inLexique) ;

  protected : void rule_goil_5F_syntax_object_5F_definition_5F_list_i6_ (const GALGAS_implementation constinArgument0,
                                                                         GALGAS_objectsMap & ioArgument1,
                                                                         C_Lexique_goil_5F_lexique * inLexique) ;

  protected : void rule_goil_5F_syntax_object_5F_definition_5F_list_i6_parse (C_Lexique_goil_5F_lexique * inLexique) ;

  protected : void rule_goil_5F_syntax_boolean_i7_ (GALGAS_lbool & outArgument0,
                                                    C_Lexique_goil_5F_lexique * inLexique) ;

  protected : void rule_goil_5F_syntax_boolean_i7_parse (C_Lexique_goil_5F_lexique * inLexique) ;

  protected : void rule_goil_5F_syntax_oil_5F_declaration_5F_list_i8_ (const GALGAS_implementationObjectMap constinArgument0,
                                                                       GALGAS_objectAttributes & ioArgument1,
                                                                       C_Lexique_goil_5F_lexique * inLexique) ;

  protected : void rule_goil_5F_syntax_oil_5F_declaration_5F_list_i8_parse (C_Lexique_goil_5F_lexique * inLexique) ;

  protected : void rule_goil_5F_syntax_oil_5F_declaration_i9_ (const GALGAS_implementationObjectMap constinArgument0,
                                                               GALGAS_objectAttributes & ioArgument1,
                                                               C_Lexique_goil_5F_lexique * inLexique) ;

  protected : void rule_goil_5F_syntax_oil_5F_declaration_i9_parse (C_Lexique_goil_5F_lexique * inLexique) ;

  protected : void rule_goil_5F_syntax_include_5F_file_5F_level_i10_ (GALGAS_implementation & ioArgument0,
                                                                      GALGAS_applicationDefinition & ioArgument1,
                                                                      C_Lexique_goil_5F_lexique * inLexique) ;

  protected : void rule_goil_5F_syntax_include_5F_file_5F_level_i10_parse (C_Lexique_goil_5F_lexique * inLexique) ;

  protected : void rule_goil_5F_syntax_include_5F_cpu_5F_level_i11_ (const GALGAS_implementation constinArgument0,
                                                                     GALGAS_objectsMap & ioArgument1,
                                                                     C_Lexique_goil_5F_lexique * inLexique) ;

  protected : void rule_goil_5F_syntax_include_5F_cpu_5F_level_i11_parse (C_Lexique_goil_5F_lexique * inLexique) ;



//--- Select methods
  protected : virtual int32_t select_goil_5F_syntax_0 (C_Lexique_goil_5F_lexique *) = 0 ;

  protected : virtual int32_t select_goil_5F_syntax_1 (C_Lexique_goil_5F_lexique *) = 0 ;

  protected : virtual int32_t select_goil_5F_syntax_2 (C_Lexique_goil_5F_lexique *) = 0 ;

  protected : virtual int32_t select_goil_5F_syntax_3 (C_Lexique_goil_5F_lexique *) = 0 ;

  protected : virtual int32_t select_goil_5F_syntax_4 (C_Lexique_goil_5F_lexique *) = 0 ;

  protected : virtual int32_t select_goil_5F_syntax_5 (C_Lexique_goil_5F_lexique *) = 0 ;

  protected : virtual int32_t select_goil_5F_syntax_6 (C_Lexique_goil_5F_lexique *) = 0 ;

  protected : virtual int32_t select_goil_5F_syntax_7 (C_Lexique_goil_5F_lexique *) = 0 ;

  protected : virtual int32_t select_goil_5F_syntax_8 (C_Lexique_goil_5F_lexique *) = 0 ;

  protected : virtual int32_t select_goil_5F_syntax_9 (C_Lexique_goil_5F_lexique *) = 0 ;

  protected : virtual int32_t select_goil_5F_syntax_10 (C_Lexique_goil_5F_lexique *) = 0 ;

  protected : virtual int32_t select_goil_5F_syntax_11 (C_Lexique_goil_5F_lexique *) = 0 ;

  protected : virtual int32_t select_goil_5F_syntax_12 (C_Lexique_goil_5F_lexique *) = 0 ;

  protected : virtual int32_t select_goil_5F_syntax_13 (C_Lexique_goil_5F_lexique *) = 0 ;


} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            @applicationDefinition class                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_applicationDefinition : public AC_GALGAS_class {
//--- Constructor
  public : GALGAS_applicationDefinition (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_applicationDefinition constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_applicationDefinition * ptr (void) const { return (const cPtr_applicationDefinition *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_applicationDefinition (const cPtr_applicationDefinition * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_applicationDefinition extractObject (const GALGAS_object & inObject,
                                                              C_Compiler * inCompiler
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_applicationDefinition constructor_new (const class GALGAS_lstring & inOperand0,
                                                                const class GALGAS_lstring & inOperand1,
                                                                const class GALGAS_lstring & inOperand2,
                                                                const class GALGAS_lstring & inOperand3,
                                                                const class GALGAS_objectsMap & inOperand4
                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_applicationDefinition & inOperand) const ;

//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void modifier_setCpuDescription (class GALGAS_lstring inArgument0
                                                             COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setName (class GALGAS_lstring inArgument0
                                                   COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setObjects (class GALGAS_objectsMap inArgument0
                                                      COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setVersion (class GALGAS_lstring inArgument0
                                                      COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setVersionDescription (class GALGAS_lstring inArgument0
                                                                 COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_lstring reader_cpuDescription (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstring reader_name (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_objectsMap reader_objects (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstring reader_version (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstring reader_versionDescription (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_applicationDefinition class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_applicationDefinition ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Pointer class for @applicationDefinition class                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_applicationDefinition : public acPtr_class {
//--- Attributes
  public : GALGAS_lstring mAttribute_name ;
  public : GALGAS_lstring mAttribute_cpuDescription ;
  public : GALGAS_lstring mAttribute_version ;
  public : GALGAS_lstring mAttribute_versionDescription ;
  public : GALGAS_objectsMap mAttribute_objects ;

//--- Constructor
  public : cPtr_applicationDefinition (const GALGAS_lstring & in_name,
                                       const GALGAS_lstring & in_cpuDescription,
                                       const GALGAS_lstring & in_version,
                                       const GALGAS_lstring & in_versionDescription,
                                       const GALGAS_objectsMap & in_objects
                                       COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_lstring reader_name (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG void modifier_setName (GALGAS_lstring inValue COMMA_LOCATION_ARGS) ;
  public : VIRTUAL_IN_DEBUG GALGAS_lstring reader_cpuDescription (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG void modifier_setCpuDescription (GALGAS_lstring inValue COMMA_LOCATION_ARGS) ;
  public : VIRTUAL_IN_DEBUG GALGAS_lstring reader_version (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG void modifier_setVersion (GALGAS_lstring inValue COMMA_LOCATION_ARGS) ;
  public : VIRTUAL_IN_DEBUG GALGAS_lstring reader_versionDescription (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG void modifier_setVersionDescription (GALGAS_lstring inValue COMMA_LOCATION_ARGS) ;
  public : VIRTUAL_IN_DEBUG GALGAS_objectsMap reader_objects (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG void modifier_setObjects (GALGAS_objectsMap inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                     @auto class                                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_auto : public GALGAS_object_5F_t {
//--- Constructor
  public : GALGAS_auto (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_auto constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_auto * ptr (void) const { return (const cPtr_auto *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_auto (const cPtr_auto * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_auto extractObject (const GALGAS_object & inObject,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_auto constructor_new (const class GALGAS_lstring & inOperand0,
                                               const class GALGAS_location & inOperand1
                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_auto & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_auto class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_auto ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            Pointer class for @auto class                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_auto : public cPtr_object_5F_t {
//--- Attributes

//--- Constructor
  public : cPtr_auto (const GALGAS_lstring & in_oil_5F_desc,
                      const GALGAS_location & in_location
                      COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                @boolAttribute class                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_boolAttribute : public GALGAS_object_5F_t {
//--- Constructor
  public : GALGAS_boolAttribute (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_boolAttribute constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_boolAttribute * ptr (void) const { return (const cPtr_boolAttribute *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_boolAttribute (const cPtr_boolAttribute * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_boolAttribute extractObject (const GALGAS_object & inObject,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_boolAttribute constructor_new (const class GALGAS_lstring & inOperand0,
                                                        const class GALGAS_location & inOperand1,
                                                        const class GALGAS_bool & inOperand2,
                                                        const class GALGAS_objectAttributes & inOperand3
                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_boolAttribute & inOperand) const ;

//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void modifier_setSubAttributes (class GALGAS_objectAttributes inArgument0
                                                            COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_objectAttributes reader_subAttributes (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_value (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_boolAttribute class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_boolAttribute ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Pointer class for @objectAttributes class                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_objectAttributes : public acPtr_class {
//--- Attributes
  public : GALGAS_identifierMap mAttribute_objectParams ;

//--- Constructor
  public : cPtr_objectAttributes (const GALGAS_identifierMap & in_objectParams
                                  COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_identifierMap reader_objectParams (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG void modifier_setObjectParams (GALGAS_identifierMap inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Pointer class for @boolAttribute class                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_boolAttribute : public cPtr_object_5F_t {
//--- Attributes
  public : GALGAS_bool mAttribute_value ;
  public : GALGAS_objectAttributes mAttribute_subAttributes ;

//--- Constructor
  public : cPtr_boolAttribute (const GALGAS_lstring & in_oil_5F_desc,
                               const GALGAS_location & in_location,
                               const GALGAS_bool & in_value,
                               const GALGAS_objectAttributes & in_subAttributes
                               COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_bool reader_value (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_objectAttributes reader_subAttributes (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG void modifier_setSubAttributes (GALGAS_objectAttributes inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                @enumAttribute class                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_enumAttribute : public GALGAS_object_5F_t {
//--- Constructor
  public : GALGAS_enumAttribute (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_enumAttribute constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_enumAttribute * ptr (void) const { return (const cPtr_enumAttribute *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_enumAttribute (const cPtr_enumAttribute * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_enumAttribute extractObject (const GALGAS_object & inObject,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_enumAttribute constructor_new (const class GALGAS_lstring & inOperand0,
                                                        const class GALGAS_location & inOperand1,
                                                        const class GALGAS_string & inOperand2,
                                                        const class GALGAS_objectAttributes & inOperand3
                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_enumAttribute & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_objectAttributes reader_subAttributes (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string reader_value (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_enumAttribute class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_enumAttribute ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Pointer class for @enumAttribute class                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_enumAttribute : public cPtr_object_5F_t {
//--- Attributes
  public : GALGAS_string mAttribute_value ;
  public : GALGAS_objectAttributes mAttribute_subAttributes ;

//--- Constructor
  public : cPtr_enumAttribute (const GALGAS_lstring & in_oil_5F_desc,
                               const GALGAS_location & in_location,
                               const GALGAS_string & in_value,
                               const GALGAS_objectAttributes & in_subAttributes
                               COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_string reader_value (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_objectAttributes reader_subAttributes (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          Pointer class for @impType class                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_impType : public acPtr_class {
//--- Attributes
  public : GALGAS_locationList mAttribute_locations ;
  public : GALGAS_dataType mAttribute_type ;
  public : GALGAS_lstring mAttribute_name ;
  public : GALGAS_bool mAttribute_multiple ;
  public : GALGAS_lstringlist mAttribute_descs ;

//--- Constructor
  public : cPtr_impType (const GALGAS_locationList & in_locations,
                         const GALGAS_dataType & in_type,
                         const GALGAS_lstring & in_name,
                         const GALGAS_bool & in_multiple,
                         const GALGAS_lstringlist & in_descs
                         COMMA_LOCATION_ARGS) ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_locationList reader_locations (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_dataType reader_type (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_lstring reader_name (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_bool reader_multiple (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_lstringlist reader_descs (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const = 0 ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const = 0 ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const = 0 ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @impAutoDefaultType class                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_impAutoDefaultType : public GALGAS_impType {
//--- Constructor
  public : GALGAS_impAutoDefaultType (void) ;

//---
  public : inline const class cPtr_impAutoDefaultType * ptr (void) const { return (const cPtr_impAutoDefaultType *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_impAutoDefaultType (const cPtr_impAutoDefaultType * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_impAutoDefaultType extractObject (const GALGAS_object & inObject,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_impAutoDefaultType constructor_new (const class GALGAS_locationList & inOperand0,
                                                             const class GALGAS_dataType & inOperand1,
                                                             const class GALGAS_lstring & inOperand2,
                                                             const class GALGAS_bool & inOperand3,
                                                             const class GALGAS_lstringlist & inOperand4,
                                                             const class GALGAS_bool & inOperand5,
                                                             const class GALGAS_object_5F_t & inOperand6
                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_impAutoDefaultType & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_object_5F_t reader_defaultValue (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool reader_withAuto (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_impAutoDefaultType class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_impAutoDefaultType ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Pointer class for @impAutoDefaultType class                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_impAutoDefaultType : public cPtr_impType {
//--- Attributes
  public : GALGAS_bool mAttribute_withAuto ;
  public : GALGAS_object_5F_t mAttribute_defaultValue ;

//--- Constructor
  public : cPtr_impAutoDefaultType (const GALGAS_locationList & in_locations,
                                    const GALGAS_dataType & in_type,
                                    const GALGAS_lstring & in_name,
                                    const GALGAS_bool & in_multiple,
                                    const GALGAS_lstringlist & in_descs,
                                    const GALGAS_bool & in_withAuto,
                                    const GALGAS_object_5F_t & in_defaultValue
                                    COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_bool reader_withAuto (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_object_5F_t reader_defaultValue (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 @impBoolType class                                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_impBoolType : public GALGAS_impAutoDefaultType {
//--- Constructor
  public : GALGAS_impBoolType (void) ;

//---
  public : inline const class cPtr_impBoolType * ptr (void) const { return (const cPtr_impBoolType *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_impBoolType (const cPtr_impBoolType * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_impBoolType extractObject (const GALGAS_object & inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_impBoolType constructor_new (const class GALGAS_locationList & inOperand0,
                                                      const class GALGAS_dataType & inOperand1,
                                                      const class GALGAS_lstring & inOperand2,
                                                      const class GALGAS_bool & inOperand3,
                                                      const class GALGAS_lstringlist & inOperand4,
                                                      const class GALGAS_bool & inOperand5,
                                                      const class GALGAS_object_5F_t & inOperand6,
                                                      const class GALGAS_implementationObjectMap & inOperand7,
                                                      const class GALGAS_implementationObjectMap & inOperand8
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_impBoolType & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_implementationObjectMap reader_falseSubAttributes (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_implementationObjectMap reader_trueSubAttributes (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_impBoolType class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_impBoolType ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Pointer class for @impBoolType class                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_impBoolType : public cPtr_impAutoDefaultType {
//--- Attributes
  public : GALGAS_implementationObjectMap mAttribute_trueSubAttributes ;
  public : GALGAS_implementationObjectMap mAttribute_falseSubAttributes ;

//--- Constructor
  public : cPtr_impBoolType (const GALGAS_locationList & in_locations,
                             const GALGAS_dataType & in_type,
                             const GALGAS_lstring & in_name,
                             const GALGAS_bool & in_multiple,
                             const GALGAS_lstringlist & in_descs,
                             const GALGAS_bool & in_withAuto,
                             const GALGAS_object_5F_t & in_defaultValue,
                             const GALGAS_implementationObjectMap & in_trueSubAttributes,
                             const GALGAS_implementationObjectMap & in_falseSubAttributes
                             COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_implementationObjectMap reader_trueSubAttributes (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_implementationObjectMap reader_falseSubAttributes (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 @impEnumType class                                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_impEnumType : public GALGAS_impAutoDefaultType {
//--- Constructor
  public : GALGAS_impEnumType (void) ;

//---
  public : inline const class cPtr_impEnumType * ptr (void) const { return (const cPtr_impEnumType *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_impEnumType (const cPtr_impEnumType * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_impEnumType extractObject (const GALGAS_object & inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_impEnumType constructor_new (const class GALGAS_locationList & inOperand0,
                                                      const class GALGAS_dataType & inOperand1,
                                                      const class GALGAS_lstring & inOperand2,
                                                      const class GALGAS_bool & inOperand3,
                                                      const class GALGAS_lstringlist & inOperand4,
                                                      const class GALGAS_bool & inOperand5,
                                                      const class GALGAS_object_5F_t & inOperand6,
                                                      const class GALGAS_enumValues & inOperand7
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_impEnumType & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_enumValues reader_valuesMap (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_impEnumType class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_impEnumType ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Pointer class for @impEnumType class                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_impEnumType : public cPtr_impAutoDefaultType {
//--- Attributes
  public : GALGAS_enumValues mAttribute_valuesMap ;

//--- Constructor
  public : cPtr_impEnumType (const GALGAS_locationList & in_locations,
                             const GALGAS_dataType & in_type,
                             const GALGAS_lstring & in_name,
                             const GALGAS_bool & in_multiple,
                             const GALGAS_lstringlist & in_descs,
                             const GALGAS_bool & in_withAuto,
                             const GALGAS_object_5F_t & in_defaultValue,
                             const GALGAS_enumValues & in_valuesMap
                             COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_enumValues reader_valuesMap (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                @impStructType class                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_impStructType : public GALGAS_impType {
//--- Constructor
  public : GALGAS_impStructType (void) ;

//---
  public : inline const class cPtr_impStructType * ptr (void) const { return (const cPtr_impStructType *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_impStructType (const cPtr_impStructType * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_impStructType extractObject (const GALGAS_object & inObject,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_impStructType constructor_new (const class GALGAS_locationList & inOperand0,
                                                        const class GALGAS_dataType & inOperand1,
                                                        const class GALGAS_lstring & inOperand2,
                                                        const class GALGAS_bool & inOperand3,
                                                        const class GALGAS_lstringlist & inOperand4,
                                                        const class GALGAS_implementationObjectMap & inOperand5
                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_impStructType & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_implementationObjectMap reader_structAttributes (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_impStructType class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_impStructType ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Pointer class for @impStructType class                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_impStructType : public cPtr_impType {
//--- Attributes
  public : GALGAS_implementationObjectMap mAttribute_structAttributes ;

//--- Constructor
  public : cPtr_impStructType (const GALGAS_locationList & in_locations,
                               const GALGAS_dataType & in_type,
                               const GALGAS_lstring & in_name,
                               const GALGAS_bool & in_multiple,
                               const GALGAS_lstringlist & in_descs,
                               const GALGAS_implementationObjectMap & in_structAttributes
                               COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_implementationObjectMap reader_structAttributes (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                   @impVoid class                                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_impVoid : public GALGAS_impType {
//--- Constructor
  public : GALGAS_impVoid (void) ;

//---
  public : inline const class cPtr_impVoid * ptr (void) const { return (const cPtr_impVoid *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_impVoid (const cPtr_impVoid * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_impVoid extractObject (const GALGAS_object & inObject,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_impVoid constructor_new (const class GALGAS_locationList & inOperand0,
                                                  const class GALGAS_dataType & inOperand1,
                                                  const class GALGAS_lstring & inOperand2,
                                                  const class GALGAS_bool & inOperand3,
                                                  const class GALGAS_lstringlist & inOperand4
                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_impVoid & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters

//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_impVoid class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_impVoid ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          Pointer class for @impVoid class                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_impVoid : public cPtr_impType {
//--- Attributes

//--- Constructor
  public : cPtr_impVoid (const GALGAS_locationList & in_locations,
                         const GALGAS_dataType & in_type,
                         const GALGAS_lstring & in_name,
                         const GALGAS_bool & in_multiple,
                         const GALGAS_lstringlist & in_descs
                         COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                @implementation class                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_implementation : public AC_GALGAS_class {
//--- Constructor
  public : GALGAS_implementation (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_implementation constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_implementation * ptr (void) const { return (const cPtr_implementation *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_implementation (const cPtr_implementation * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_implementation extractObject (const GALGAS_object & inObject,
                                                       C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_implementation constructor_new (const class GALGAS_implementationMap & inOperand0
                                                         COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_implementation & inOperand) const ;

//--------------------------------- Setters
  public : VIRTUAL_IN_DEBUG void modifier_setImp (class GALGAS_implementationMap inArgument0
                                                  COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_implementationMap reader_imp (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_implementation class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_implementation ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Pointer class for @implementation class                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_implementation : public acPtr_class {
//--- Attributes
  public : GALGAS_implementationMap mAttribute_imp ;

//--- Constructor
  public : cPtr_implementation (const GALGAS_implementationMap & in_imp
                                COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_implementationMap reader_imp (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG void modifier_setImp (GALGAS_implementationMap inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Pointer class for @implementationObject class                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_implementationObject : public acPtr_class {
//--- Attributes
  public : GALGAS_lbool mAttribute_multiple ;
  public : GALGAS_implementationObjectMap mAttribute_attributes ;

//--- Constructor
  public : cPtr_implementationObject (const GALGAS_lbool & in_multiple,
                                      const GALGAS_implementationObjectMap & in_attributes
                                      COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_lbool reader_multiple (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG void modifier_setMultiple (GALGAS_lbool inValue COMMA_LOCATION_ARGS) ;
  public : VIRTUAL_IN_DEBUG GALGAS_implementationObjectMap reader_attributes (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG void modifier_setAttributes (GALGAS_implementationObjectMap inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @multipleAttribute class                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_multipleAttribute : public GALGAS_object_5F_t {
//--- Constructor
  public : GALGAS_multipleAttribute (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_multipleAttribute constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_multipleAttribute * ptr (void) const { return (const cPtr_multipleAttribute *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_multipleAttribute (const cPtr_multipleAttribute * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_multipleAttribute extractObject (const GALGAS_object & inObject,
                                                          C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_multipleAttribute constructor_new (const class GALGAS_lstring & inOperand0,
                                                            const class GALGAS_location & inOperand1,
                                                            const class GALGAS_identifierList & inOperand2
                                                            COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_multipleAttribute & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_identifierList reader_items (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_multipleAttribute class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_multipleAttribute ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Pointer class for @multipleAttribute class                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_multipleAttribute : public cPtr_object_5F_t {
//--- Attributes
  public : GALGAS_identifierList mAttribute_items ;

//--- Constructor
  public : cPtr_multipleAttribute (const GALGAS_lstring & in_oil_5F_desc,
                                   const GALGAS_location & in_location,
                                   const GALGAS_identifierList & in_items
                                   COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_identifierList reader_items (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         Pointer class for @objectKind class                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_objectKind : public acPtr_class {
//--- Attributes
  public : GALGAS_objectKindMap mAttribute_objects ;

//--- Constructor
  public : cPtr_objectKind (const GALGAS_objectKindMap & in_objects
                            COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_objectKindMap reader_objects (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG void modifier_setObjects (GALGAS_objectKindMap inValue COMMA_LOCATION_ARGS) ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @objectRefAttribute class                                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_objectRefAttribute : public GALGAS_object_5F_t {
//--- Constructor
  public : GALGAS_objectRefAttribute (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_objectRefAttribute constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_objectRefAttribute * ptr (void) const { return (const cPtr_objectRefAttribute *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_objectRefAttribute (const cPtr_objectRefAttribute * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_objectRefAttribute extractObject (const GALGAS_object & inObject,
                                                           C_Compiler * inCompiler
                                                           COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_objectRefAttribute constructor_new (const class GALGAS_lstring & inOperand0,
                                                             const class GALGAS_location & inOperand1,
                                                             const class GALGAS_lstring & inOperand2
                                                             COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_objectRefAttribute & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_lstring reader_value (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_objectRefAttribute class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_objectRefAttribute ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Pointer class for @objectRefAttribute class                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_objectRefAttribute : public cPtr_object_5F_t {
//--- Attributes
  public : GALGAS_lstring mAttribute_value ;

//--- Constructor
  public : cPtr_objectRefAttribute (const GALGAS_lstring & in_oil_5F_desc,
                                    const GALGAS_location & in_location,
                                    const GALGAS_lstring & in_value
                                    COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_lstring reader_value (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               @stringAttribute class                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_stringAttribute : public GALGAS_object_5F_t {
//--- Constructor
  public : GALGAS_stringAttribute (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_stringAttribute constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_stringAttribute * ptr (void) const { return (const cPtr_stringAttribute *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_stringAttribute (const cPtr_stringAttribute * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_stringAttribute extractObject (const GALGAS_object & inObject,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_stringAttribute constructor_new (const class GALGAS_lstring & inOperand0,
                                                          const class GALGAS_location & inOperand1,
                                                          const class GALGAS_string & inOperand2
                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_stringAttribute & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_string reader_value (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_stringAttribute class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_stringAttribute ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Pointer class for @stringAttribute class                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_stringAttribute : public cPtr_object_5F_t {
//--- Attributes
  public : GALGAS_string mAttribute_value ;

//--- Constructor
  public : cPtr_stringAttribute (const GALGAS_lstring & in_oil_5F_desc,
                                 const GALGAS_location & in_location,
                                 const GALGAS_string & in_value
                                 COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_string reader_value (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               @string_5F_class class                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_string_5F_class : public GALGAS_object_5F_t {
//--- Constructor
  public : GALGAS_string_5F_class (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_string_5F_class constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_string_5F_class * ptr (void) const { return (const cPtr_string_5F_class *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_string_5F_class (const cPtr_string_5F_class * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_string_5F_class extractObject (const GALGAS_object & inObject,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_string_5F_class constructor_new (const class GALGAS_lstring & inOperand0,
                                                          const class GALGAS_location & inOperand1,
                                                          const class GALGAS_string & inOperand2
                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_string_5F_class & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_string reader_value (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_string_5F_class class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_string_5F_class ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Pointer class for @string_class class                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_string_5F_class : public cPtr_object_5F_t {
//--- Attributes
  public : GALGAS_string mAttribute_value ;

//--- Constructor
  public : cPtr_string_5F_class (const GALGAS_lstring & in_oil_5F_desc,
                                 const GALGAS_location & in_location,
                                 const GALGAS_string & in_value
                                 COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_string reader_value (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               @structAttribute class                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_structAttribute : public GALGAS_object_5F_t {
//--- Constructor
  public : GALGAS_structAttribute (void) ;

//--------------------------------- Default GALGAS constructor
  public : static GALGAS_structAttribute constructor_default (LOCATION_ARGS) ;

//---
  public : inline const class cPtr_structAttribute * ptr (void) const { return (const cPtr_structAttribute *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_structAttribute (const cPtr_structAttribute * inSourcePtr) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_structAttribute extractObject (const GALGAS_object & inObject,
                                                        C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_structAttribute constructor_new (const class GALGAS_lstring & inOperand0,
                                                          const class GALGAS_location & inOperand1,
                                                          const class GALGAS_lstring & inOperand2,
                                                          const class GALGAS_objectAttributes & inOperand3
                                                          COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_structAttribute & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_lstring reader_structName (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_objectAttributes reader_subAttributes (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_structAttribute class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_structAttribute ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Pointer class for @structAttribute class                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cPtr_structAttribute : public cPtr_object_5F_t {
//--- Attributes
  public : GALGAS_lstring mAttribute_structName ;
  public : GALGAS_objectAttributes mAttribute_subAttributes ;

//--- Constructor
  public : cPtr_structAttribute (const GALGAS_lstring & in_oil_5F_desc,
                                 const GALGAS_location & in_location,
                                 const GALGAS_lstring & in_structName,
                                 const GALGAS_objectAttributes & in_subAttributes
                                 COMMA_LOCATION_ARGS) ;

//--- Duplication
  public : virtual acPtr_class * duplicate (LOCATION_ARGS) const ;

//--- Attribute accessors
  public : VIRTUAL_IN_DEBUG GALGAS_lstring reader_structName (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_objectAttributes reader_subAttributes (LOCATION_ARGS) const ;
//--- Description
  public : virtual void description (C_String & ioString,
                                     const int32_t inIndentation) const ;

  public : virtual typeComparisonResult dynamicObjectCompare (const acPtr_class * inOperandPtr) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           Function 'allTemplateFilePaths'                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_stringlist function_allTemplateFilePaths (const class GALGAS_string & constinArgument0,
                                                       const class GALGAS_string & constinArgument1,
                                                       class C_Compiler * inCompiler
                                                       COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          Function 'checkAndGetFloatNumber'                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_object_5F_t function_checkAndGetFloatNumber (const class GALGAS_lstring & constinArgument0,
                                                          const class GALGAS_dataType & constinArgument1,
                                                          const class GALGAS_ldouble & constinArgument2,
                                                          const class GALGAS_bool & constinArgument3,
                                                          class C_Compiler * inCompiler
                                                          COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         Function 'checkAndGetIntegerNumber'                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_object_5F_t function_checkAndGetIntegerNumber (const class GALGAS_lstring & constinArgument0,
                                                            const class GALGAS_dataType & constinArgument1,
                                                            const class GALGAS_luint_36__34_ & constinArgument2,
                                                            const class GALGAS_bool & constinArgument3,
                                                            class C_Compiler * inCompiler
                                                            COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        Function 'emptyApplicationDefinition'                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_applicationDefinition function_emptyApplicationDefinition (class C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Function 'emptyObject'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_objectAttributes function_emptyObject (class C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Function 'stringLBool'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_string function_stringLBool (const class GALGAS_lbool & constinArgument0,
                                          class C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                Function 'valueList'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_string function_valueList (const class GALGAS_enumValues & constinArgument0,
                                        class C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Category reader '@applicationDefinition templateData'                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_TfieldMap (*categoryReaderSignature_applicationDefinition_templateData) (const class cPtr_applicationDefinition * inObject,
                                                                                              const class GALGAS_implementation & constinArgument0,
                                                                                              C_Compiler * inCompiler
                                                                                              COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterCategoryReader_templateData (const int32_t inClassIndex,
                                       categoryReaderSignature_applicationDefinition_templateData inReader) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_TfieldMap callCategoryReader_templateData (const cPtr_applicationDefinition * inObject,
                                                        const GALGAS_implementation & constin_imp,
                                                        class C_Compiler * inCompiler
                                                        COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         Category Reader '@dataType oilType'                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_string categoryReader_oilType (const class GALGAS_dataType & inObject,
                                            class C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Category reader '@impType autoAllowed'                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_bool (*categoryReaderSignature_impType_autoAllowed) (const class cPtr_impType * inObject,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterCategoryReader_autoAllowed (const int32_t inClassIndex,
                                      categoryReaderSignature_impType_autoAllowed inReader) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_bool callCategoryReader_autoAllowed (const cPtr_impType * inObject,
                                                  class C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Category reader '@implementation impObject'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef class GALGAS_implementationObject (*categoryReaderSignature_implementation_impObject) (const class cPtr_implementation * inObject,
                                                                                               const class GALGAS_string & constinArgument0,
                                                                                               C_Compiler * inCompiler
                                                                                               COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterCategoryReader_impObject (const int32_t inClassIndex,
                                    categoryReaderSignature_implementation_impObject inReader) ;

//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_implementationObject callCategoryReader_impObject (const cPtr_implementation * inObject,
                                                                const GALGAS_string & constin_objKind,
                                                                class C_Compiler * inCompiler
                                                                COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//  GRAMMAR goil_cpu_level_include
//---------------------------------------------------------------------------------------------------------------------*

class cGrammar_goil_5F_cpu_5F_level_5F_include : public cParser_goil_5F_syntax {
//------------------------------------- 'OIL_version' non terminal
//--- 'parse' label
  public : virtual void nt_OIL_5F_version_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_OIL_5F_version_ (GALGAS_lstring & outArgument0,
                                            GALGAS_lstring & outArgument1,
                                            C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'application_definition' non terminal
//--- 'parse' label
  public : virtual void nt_application_5F_definition_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_application_5F_definition_ (const GALGAS_implementation inArgument0,
                                                       GALGAS_applicationDefinition & ioArgument1,
                                                       C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'boolean' non terminal
//--- 'parse' label
  public : virtual void nt_boolean_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_boolean_ (GALGAS_lbool & outArgument0,
                                     C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'description' non terminal
//--- 'parse' label
  public : virtual void nt_description_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_description_ (GALGAS_lstring & outArgument0,
                                         C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'file' non terminal
//--- 'parse' label
  public : virtual void nt_file_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_file_ (GALGAS_implementation & ioArgument0,
                                  GALGAS_applicationDefinition & ioArgument1,
                                  C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'implementation_definition' non terminal
//--- 'parse' label
  public : virtual void nt_implementation_5F_definition_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_implementation_5F_definition_ (GALGAS_implementation & ioArgument0,
                                                          C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'include_cpu_level' non terminal
//--- 'parse' label
  public : virtual void nt_include_5F_cpu_5F_level_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_include_5F_cpu_5F_level_ (const GALGAS_implementation inArgument0,
                                                     GALGAS_objectsMap & ioArgument1,
                                                     C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'include_file_level' non terminal
//--- 'parse' label
  public : virtual void nt_include_5F_file_5F_level_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_include_5F_file_5F_level_ (GALGAS_implementation & ioArgument0,
                                                      GALGAS_applicationDefinition & ioArgument1,
                                                      C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'object_definition_list' non terminal
//--- 'parse' label
  public : virtual void nt_object_5F_definition_5F_list_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_object_5F_definition_5F_list_ (const GALGAS_implementation inArgument0,
                                                          GALGAS_objectsMap & ioArgument1,
                                                          C_Lexique_goil_5F_lexique * inCompiler) ;

//--- Start symbol
  public : static void _performSourceFileParsing_ (C_Compiler * inCompiler,
                                                   GALGAS_lstring inFileName,
                                                   const GALGAS_implementation inArgument0,
                                                   GALGAS_objectsMap & ioArgument1
                                                   COMMA_LOCATION_ARGS) ;

  public : static void _performSourceStringParsing_ (C_Compiler * inCompiler,
                                                     GALGAS_string inSourceString,
                                                     const GALGAS_implementation inArgument0,
                                                     GALGAS_objectsMap & ioArgument1
                                                     COMMA_LOCATION_ARGS) ;

//--- Indexing
  public : static void performIndexing (C_Compiler * inCompiler,
                                        const C_String & inSourceFilePath) ;

//--- Only lexical analysis
  public : static void performOnlyLexicalAnalysis (C_Compiler * inCompiler,
                                                   const C_String & inSourceFilePath) ;

//--- Only syntax analysis
  public : static void performOnlySyntaxAnalysis (C_Compiler * inCompiler,
                                                  const C_String & inSourceFilePath) ;

//------------------------------------- 'oil_declaration' non terminal
//--- 'parse' label
  public : virtual void nt_oil_5F_declaration_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_oil_5F_declaration_ (const GALGAS_implementationObjectMap inArgument0,
                                                GALGAS_objectAttributes & ioArgument1,
                                                C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'oil_declaration_list' non terminal
//--- 'parse' label
  public : virtual void nt_oil_5F_declaration_5F_list_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_oil_5F_declaration_5F_list_ (const GALGAS_implementationObjectMap inArgument0,
                                                        GALGAS_objectAttributes & ioArgument1,
                                                        C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'sign' non terminal
//--- 'parse' label
  public : virtual void nt_sign_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_sign_ (GALGAS_bool & outArgument0,
                                  C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'start' non terminal
//--- 'parse' label
  public : virtual void nt_start_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_start_ (C_Lexique_goil_5F_lexique * inCompiler) ;

  public : virtual int32_t select_goil_5F_syntax_0 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_1 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_2 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_3 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_4 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_5 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_6 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_7 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_8 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_9 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_10 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_11 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_12 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_13 (C_Lexique_goil_5F_lexique *) ;
} ;

//---------------------------------------------------------------------------------------------------------------------*
//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                  Parser class 'implementation_parser' declaration                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class cParser_implementation_5F_parser {
//--- Virtual destructor
  public : virtual ~ cParser_implementation_5F_parser (void) {}

//--- Non terminal declarations
  protected : virtual void nt_boolean_ (class GALGAS_lbool & outArgument0,
                                        class C_Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected : virtual void nt_boolean_parse (class C_Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected : virtual void nt_boolean_5F_options_ (class GALGAS_lstring & outArgument0,
                                                   class GALGAS_impType & outArgument1,
                                                   class C_Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected : virtual void nt_boolean_5F_options_parse (class C_Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected : virtual void nt_description_ (class GALGAS_lstring & outArgument0,
                                            class C_Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected : virtual void nt_description_parse (class C_Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected : virtual void nt_enum_5F_item_ (class GALGAS_enumValues & ioArgument0,
                                             class C_Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected : virtual void nt_enum_5F_item_parse (class C_Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected : virtual void nt_enum_5F_options_ (class GALGAS_lstring & outArgument0,
                                                class GALGAS_impType & outArgument1,
                                                class C_Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected : virtual void nt_enum_5F_options_parse (class C_Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected : virtual void nt_identifier_5F_or_5F_attribute_ (class GALGAS_lstring & outArgument0,
                                                              class C_Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected : virtual void nt_identifier_5F_or_5F_attribute_parse (class C_Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected : virtual void nt_identifier_5F_or_5F_enum_5F_value_ (class GALGAS_lstring & outArgument0,
                                                                  class C_Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected : virtual void nt_identifier_5F_or_5F_enum_5F_value_parse (class C_Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected : virtual void nt_implementation_5F_definition_ (class GALGAS_implementation & ioArgument0,
                                                             class C_Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected : virtual void nt_implementation_5F_definition_parse (class C_Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected : virtual void nt_implementation_5F_list_ (class GALGAS_implementationObjectMap & ioArgument0,
                                                       class C_Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected : virtual void nt_implementation_5F_list_parse (class C_Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected : virtual void nt_implementation_5F_objects_ (class GALGAS_implementation & ioArgument0,
                                                          class C_Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected : virtual void nt_implementation_5F_objects_parse (class C_Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected : virtual void nt_implementation_5F_type_ (class GALGAS_lstring & outArgument0,
                                                       class GALGAS_impType & outArgument1,
                                                       class C_Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected : virtual void nt_implementation_5F_type_parse (class C_Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected : virtual void nt_int_5F_or_5F_float_ (class GALGAS_object_5F_t & outArgument0,
                                                   const class GALGAS_dataType constinArgument1,
                                                   class C_Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected : virtual void nt_int_5F_or_5F_float_parse (class C_Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected : virtual void nt_multiple_ (class GALGAS_bool & outArgument0,
                                         class C_Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected : virtual void nt_multiple_parse (class C_Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected : virtual void nt_number_5F_options_ (class GALGAS_lstring & outArgument0,
                                                  class GALGAS_impType & outArgument1,
                                                  const class GALGAS_dataType constinArgument2,
                                                  class C_Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected : virtual void nt_number_5F_options_parse (class C_Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected : virtual void nt_objref_5F_option_ (class GALGAS_lstring & outArgument0,
                                                 class GALGAS_impType & outArgument1,
                                                 class GALGAS_lstring inArgument2,
                                                 class C_Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected : virtual void nt_objref_5F_option_parse (class C_Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected : virtual void nt_range_ (class GALGAS_attributeRange & outArgument0,
                                      const class GALGAS_dataType constinArgument1,
                                      class C_Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected : virtual void nt_range_parse (class C_Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected : virtual void nt_range_5F_content_ (class GALGAS_attributeRange & outArgument0,
                                                 const class GALGAS_dataType constinArgument1,
                                                 class C_Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected : virtual void nt_range_5F_content_parse (class C_Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected : virtual void nt_set_5F_followup_ (class GALGAS_numberList & ioArgument0,
                                                const class GALGAS_dataType constinArgument1,
                                                class C_Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected : virtual void nt_set_5F_followup_parse (class C_Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected : virtual void nt_sign_ (class GALGAS_bool & outArgument0,
                                     class C_Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected : virtual void nt_sign_parse (class C_Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected : virtual void nt_string_5F_options_ (class GALGAS_lstring & outArgument0,
                                                  class GALGAS_impType & outArgument1,
                                                  class C_Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected : virtual void nt_string_5F_options_parse (class C_Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected : virtual void nt_struct_5F_options_ (class GALGAS_lstring & outArgument0,
                                                  class GALGAS_impType & outArgument1,
                                                  class C_Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected : virtual void nt_struct_5F_options_parse (class C_Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected : virtual void nt_type_5F_options_ (class GALGAS_lstring & outArgument0,
                                                class GALGAS_impType & outArgument1,
                                                const class GALGAS_dataType constinArgument2,
                                                class C_Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected : virtual void nt_type_5F_options_parse (class C_Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected : virtual void nt_with_5F_auto_ (class GALGAS_bool & outArgument0,
                                             class C_Lexique_goil_5F_lexique * inLexique) = 0 ;

  protected : virtual void nt_with_5F_auto_parse (class C_Lexique_goil_5F_lexique * inLexique) = 0 ;


//--- Rule declarations
  protected : void rule_implementation_5F_parser_implementation_5F_definition_i0_ (GALGAS_implementation & ioArgument0,
                                                                                   C_Lexique_goil_5F_lexique * inLexique) ;

  protected : void rule_implementation_5F_parser_implementation_5F_definition_i0_parse (C_Lexique_goil_5F_lexique * inLexique) ;

  protected : void rule_implementation_5F_parser_implementation_5F_objects_i1_ (GALGAS_implementation & ioArgument0,
                                                                                C_Lexique_goil_5F_lexique * inLexique) ;

  protected : void rule_implementation_5F_parser_implementation_5F_objects_i1_parse (C_Lexique_goil_5F_lexique * inLexique) ;

  protected : void rule_implementation_5F_parser_implementation_5F_list_i2_ (GALGAS_implementationObjectMap & ioArgument0,
                                                                             C_Lexique_goil_5F_lexique * inLexique) ;

  protected : void rule_implementation_5F_parser_implementation_5F_list_i2_parse (C_Lexique_goil_5F_lexique * inLexique) ;

  protected : void rule_implementation_5F_parser_implementation_5F_type_i3_ (GALGAS_lstring & outArgument0,
                                                                             GALGAS_impType & outArgument1,
                                                                             C_Lexique_goil_5F_lexique * inLexique) ;

  protected : void rule_implementation_5F_parser_implementation_5F_type_i3_parse (C_Lexique_goil_5F_lexique * inLexique) ;

  protected : void rule_implementation_5F_parser_struct_5F_options_i4_ (GALGAS_lstring & outArgument0,
                                                                        GALGAS_impType & outArgument1,
                                                                        C_Lexique_goil_5F_lexique * inLexique) ;

  protected : void rule_implementation_5F_parser_struct_5F_options_i4_parse (C_Lexique_goil_5F_lexique * inLexique) ;

  protected : void rule_implementation_5F_parser_objref_5F_option_i5_ (GALGAS_lstring & outArgument0,
                                                                       GALGAS_impType & outArgument1,
                                                                       GALGAS_lstring inArgument2,
                                                                       C_Lexique_goil_5F_lexique * inLexique) ;

  protected : void rule_implementation_5F_parser_objref_5F_option_i5_parse (C_Lexique_goil_5F_lexique * inLexique) ;

  protected : void rule_implementation_5F_parser_string_5F_options_i6_ (GALGAS_lstring & outArgument0,
                                                                        GALGAS_impType & outArgument1,
                                                                        C_Lexique_goil_5F_lexique * inLexique) ;

  protected : void rule_implementation_5F_parser_string_5F_options_i6_parse (C_Lexique_goil_5F_lexique * inLexique) ;

  protected : void rule_implementation_5F_parser_boolean_5F_options_i7_ (GALGAS_lstring & outArgument0,
                                                                         GALGAS_impType & outArgument1,
                                                                         C_Lexique_goil_5F_lexique * inLexique) ;

  protected : void rule_implementation_5F_parser_boolean_5F_options_i7_parse (C_Lexique_goil_5F_lexique * inLexique) ;

  protected : void rule_implementation_5F_parser_enum_5F_item_i8_ (GALGAS_enumValues & ioArgument0,
                                                                   C_Lexique_goil_5F_lexique * inLexique) ;

  protected : void rule_implementation_5F_parser_enum_5F_item_i8_parse (C_Lexique_goil_5F_lexique * inLexique) ;

  protected : void rule_implementation_5F_parser_enum_5F_options_i9_ (GALGAS_lstring & outArgument0,
                                                                      GALGAS_impType & outArgument1,
                                                                      C_Lexique_goil_5F_lexique * inLexique) ;

  protected : void rule_implementation_5F_parser_enum_5F_options_i9_parse (C_Lexique_goil_5F_lexique * inLexique) ;

  protected : void rule_implementation_5F_parser_number_5F_options_i10_ (GALGAS_lstring & outArgument0,
                                                                         GALGAS_impType & outArgument1,
                                                                         const GALGAS_dataType constinArgument2,
                                                                         C_Lexique_goil_5F_lexique * inLexique) ;

  protected : void rule_implementation_5F_parser_number_5F_options_i10_parse (C_Lexique_goil_5F_lexique * inLexique) ;

  protected : void rule_implementation_5F_parser_type_5F_options_i11_ (GALGAS_lstring & outArgument0,
                                                                       GALGAS_impType & outArgument1,
                                                                       const GALGAS_dataType constinArgument2,
                                                                       C_Lexique_goil_5F_lexique * inLexique) ;

  protected : void rule_implementation_5F_parser_type_5F_options_i11_parse (C_Lexique_goil_5F_lexique * inLexique) ;

  protected : void rule_implementation_5F_parser_with_5F_auto_i12_ (GALGAS_bool & outArgument0,
                                                                    C_Lexique_goil_5F_lexique * inLexique) ;

  protected : void rule_implementation_5F_parser_with_5F_auto_i12_parse (C_Lexique_goil_5F_lexique * inLexique) ;

  protected : void rule_implementation_5F_parser_int_5F_or_5F_float_i13_ (GALGAS_object_5F_t & outArgument0,
                                                                          const GALGAS_dataType constinArgument1,
                                                                          C_Lexique_goil_5F_lexique * inLexique) ;

  protected : void rule_implementation_5F_parser_int_5F_or_5F_float_i13_parse (C_Lexique_goil_5F_lexique * inLexique) ;

  protected : void rule_implementation_5F_parser_set_5F_followup_i14_ (GALGAS_numberList & ioArgument0,
                                                                       const GALGAS_dataType constinArgument1,
                                                                       C_Lexique_goil_5F_lexique * inLexique) ;

  protected : void rule_implementation_5F_parser_set_5F_followup_i14_parse (C_Lexique_goil_5F_lexique * inLexique) ;

  protected : void rule_implementation_5F_parser_range_5F_content_i15_ (GALGAS_attributeRange & outArgument0,
                                                                        const GALGAS_dataType constinArgument1,
                                                                        C_Lexique_goil_5F_lexique * inLexique) ;

  protected : void rule_implementation_5F_parser_range_5F_content_i15_parse (C_Lexique_goil_5F_lexique * inLexique) ;

  protected : void rule_implementation_5F_parser_range_i16_ (GALGAS_attributeRange & outArgument0,
                                                             const GALGAS_dataType constinArgument1,
                                                             C_Lexique_goil_5F_lexique * inLexique) ;

  protected : void rule_implementation_5F_parser_range_i16_parse (C_Lexique_goil_5F_lexique * inLexique) ;

  protected : void rule_implementation_5F_parser_multiple_i17_ (GALGAS_bool & outArgument0,
                                                                C_Lexique_goil_5F_lexique * inLexique) ;

  protected : void rule_implementation_5F_parser_multiple_i17_parse (C_Lexique_goil_5F_lexique * inLexique) ;

  protected : void rule_implementation_5F_parser_identifier_5F_or_5F_attribute_i18_ (GALGAS_lstring & outArgument0,
                                                                                     C_Lexique_goil_5F_lexique * inLexique) ;

  protected : void rule_implementation_5F_parser_identifier_5F_or_5F_attribute_i18_parse (C_Lexique_goil_5F_lexique * inLexique) ;

  protected : void rule_implementation_5F_parser_identifier_5F_or_5F_enum_5F_value_i19_ (GALGAS_lstring & outArgument0,
                                                                                         C_Lexique_goil_5F_lexique * inLexique) ;

  protected : void rule_implementation_5F_parser_identifier_5F_or_5F_enum_5F_value_i19_parse (C_Lexique_goil_5F_lexique * inLexique) ;



//--- Select methods
  protected : virtual int32_t select_implementation_5F_parser_0 (C_Lexique_goil_5F_lexique *) = 0 ;

  protected : virtual int32_t select_implementation_5F_parser_1 (C_Lexique_goil_5F_lexique *) = 0 ;

  protected : virtual int32_t select_implementation_5F_parser_2 (C_Lexique_goil_5F_lexique *) = 0 ;

  protected : virtual int32_t select_implementation_5F_parser_3 (C_Lexique_goil_5F_lexique *) = 0 ;

  protected : virtual int32_t select_implementation_5F_parser_4 (C_Lexique_goil_5F_lexique *) = 0 ;

  protected : virtual int32_t select_implementation_5F_parser_5 (C_Lexique_goil_5F_lexique *) = 0 ;

  protected : virtual int32_t select_implementation_5F_parser_6 (C_Lexique_goil_5F_lexique *) = 0 ;

  protected : virtual int32_t select_implementation_5F_parser_7 (C_Lexique_goil_5F_lexique *) = 0 ;

  protected : virtual int32_t select_implementation_5F_parser_8 (C_Lexique_goil_5F_lexique *) = 0 ;

  protected : virtual int32_t select_implementation_5F_parser_9 (C_Lexique_goil_5F_lexique *) = 0 ;

  protected : virtual int32_t select_implementation_5F_parser_10 (C_Lexique_goil_5F_lexique *) = 0 ;

  protected : virtual int32_t select_implementation_5F_parser_11 (C_Lexique_goil_5F_lexique *) = 0 ;

  protected : virtual int32_t select_implementation_5F_parser_12 (C_Lexique_goil_5F_lexique *) = 0 ;

  protected : virtual int32_t select_implementation_5F_parser_13 (C_Lexique_goil_5F_lexique *) = 0 ;

  protected : virtual int32_t select_implementation_5F_parser_14 (C_Lexique_goil_5F_lexique *) = 0 ;

  protected : virtual int32_t select_implementation_5F_parser_15 (C_Lexique_goil_5F_lexique *) = 0 ;

  protected : virtual int32_t select_implementation_5F_parser_16 (C_Lexique_goil_5F_lexique *) = 0 ;

  protected : virtual int32_t select_implementation_5F_parser_17 (C_Lexique_goil_5F_lexique *) = 0 ;

  protected : virtual int32_t select_implementation_5F_parser_18 (C_Lexique_goil_5F_lexique *) = 0 ;

  protected : virtual int32_t select_implementation_5F_parser_19 (C_Lexique_goil_5F_lexique *) = 0 ;

  protected : virtual int32_t select_implementation_5F_parser_20 (C_Lexique_goil_5F_lexique *) = 0 ;

  protected : virtual int32_t select_implementation_5F_parser_21 (C_Lexique_goil_5F_lexique *) = 0 ;

  protected : virtual int32_t select_implementation_5F_parser_22 (C_Lexique_goil_5F_lexique *) = 0 ;

  protected : virtual int32_t select_implementation_5F_parser_23 (C_Lexique_goil_5F_lexique *) = 0 ;

  protected : virtual int32_t select_implementation_5F_parser_24 (C_Lexique_goil_5F_lexique *) = 0 ;

  protected : virtual int32_t select_implementation_5F_parser_25 (C_Lexique_goil_5F_lexique *) = 0 ;

  protected : virtual int32_t select_implementation_5F_parser_26 (C_Lexique_goil_5F_lexique *) = 0 ;


} ;

//---------------------------------------------------------------------------------------------------------------------*
//  GRAMMAR goil_file_level_include
//---------------------------------------------------------------------------------------------------------------------*

class cGrammar_goil_5F_file_5F_level_5F_include : public cParser_goil_5F_syntax,
                                                  public cParser_implementation_5F_parser {
//------------------------------------- 'OIL_version' non terminal
//--- 'parse' label
  public : virtual void nt_OIL_5F_version_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_OIL_5F_version_ (GALGAS_lstring & outArgument0,
                                            GALGAS_lstring & outArgument1,
                                            C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'application_definition' non terminal
//--- 'parse' label
  public : virtual void nt_application_5F_definition_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_application_5F_definition_ (const GALGAS_implementation inArgument0,
                                                       GALGAS_applicationDefinition & ioArgument1,
                                                       C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'boolean' non terminal
//--- 'parse' label
  public : virtual void nt_boolean_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_boolean_ (GALGAS_lbool & outArgument0,
                                     C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'boolean_options' non terminal
//--- 'parse' label
  public : virtual void nt_boolean_5F_options_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_boolean_5F_options_ (GALGAS_lstring & outArgument0,
                                                GALGAS_impType & outArgument1,
                                                C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'description' non terminal
//--- 'parse' label
  public : virtual void nt_description_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_description_ (GALGAS_lstring & outArgument0,
                                         C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'enum_item' non terminal
//--- 'parse' label
  public : virtual void nt_enum_5F_item_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_enum_5F_item_ (GALGAS_enumValues & ioArgument0,
                                          C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'enum_options' non terminal
//--- 'parse' label
  public : virtual void nt_enum_5F_options_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_enum_5F_options_ (GALGAS_lstring & outArgument0,
                                             GALGAS_impType & outArgument1,
                                             C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'file' non terminal
//--- 'parse' label
  public : virtual void nt_file_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_file_ (GALGAS_implementation & ioArgument0,
                                  GALGAS_applicationDefinition & ioArgument1,
                                  C_Lexique_goil_5F_lexique * inCompiler) ;

//--- Start symbol
  public : static void _performSourceFileParsing_ (C_Compiler * inCompiler,
                                                   GALGAS_lstring inFileName,
                                                   GALGAS_implementation & ioArgument0,
                                                   GALGAS_applicationDefinition & ioArgument1
                                                   COMMA_LOCATION_ARGS) ;

  public : static void _performSourceStringParsing_ (C_Compiler * inCompiler,
                                                     GALGAS_string inSourceString,
                                                     GALGAS_implementation & ioArgument0,
                                                     GALGAS_applicationDefinition & ioArgument1
                                                     COMMA_LOCATION_ARGS) ;

//--- Indexing
  public : static void performIndexing (C_Compiler * inCompiler,
                                        const C_String & inSourceFilePath) ;

//--- Only lexical analysis
  public : static void performOnlyLexicalAnalysis (C_Compiler * inCompiler,
                                                   const C_String & inSourceFilePath) ;

//--- Only syntax analysis
  public : static void performOnlySyntaxAnalysis (C_Compiler * inCompiler,
                                                  const C_String & inSourceFilePath) ;

//------------------------------------- 'identifier_or_attribute' non terminal
//--- 'parse' label
  public : virtual void nt_identifier_5F_or_5F_attribute_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_identifier_5F_or_5F_attribute_ (GALGAS_lstring & outArgument0,
                                                           C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'identifier_or_enum_value' non terminal
//--- 'parse' label
  public : virtual void nt_identifier_5F_or_5F_enum_5F_value_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_identifier_5F_or_5F_enum_5F_value_ (GALGAS_lstring & outArgument0,
                                                               C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'implementation_definition' non terminal
//--- 'parse' label
  public : virtual void nt_implementation_5F_definition_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_implementation_5F_definition_ (GALGAS_implementation & ioArgument0,
                                                          C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'implementation_list' non terminal
//--- 'parse' label
  public : virtual void nt_implementation_5F_list_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_implementation_5F_list_ (GALGAS_implementationObjectMap & ioArgument0,
                                                    C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'implementation_objects' non terminal
//--- 'parse' label
  public : virtual void nt_implementation_5F_objects_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_implementation_5F_objects_ (GALGAS_implementation & ioArgument0,
                                                       C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'implementation_type' non terminal
//--- 'parse' label
  public : virtual void nt_implementation_5F_type_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_implementation_5F_type_ (GALGAS_lstring & outArgument0,
                                                    GALGAS_impType & outArgument1,
                                                    C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'include_cpu_level' non terminal
//--- 'parse' label
  public : virtual void nt_include_5F_cpu_5F_level_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_include_5F_cpu_5F_level_ (const GALGAS_implementation inArgument0,
                                                     GALGAS_objectsMap & ioArgument1,
                                                     C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'include_file_level' non terminal
//--- 'parse' label
  public : virtual void nt_include_5F_file_5F_level_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_include_5F_file_5F_level_ (GALGAS_implementation & ioArgument0,
                                                      GALGAS_applicationDefinition & ioArgument1,
                                                      C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'int_or_float' non terminal
//--- 'parse' label
  public : virtual void nt_int_5F_or_5F_float_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_int_5F_or_5F_float_ (GALGAS_object_5F_t & outArgument0,
                                                const GALGAS_dataType inArgument1,
                                                C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'multiple' non terminal
//--- 'parse' label
  public : virtual void nt_multiple_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_multiple_ (GALGAS_bool & outArgument0,
                                      C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'number_options' non terminal
//--- 'parse' label
  public : virtual void nt_number_5F_options_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_number_5F_options_ (GALGAS_lstring & outArgument0,
                                               GALGAS_impType & outArgument1,
                                               const GALGAS_dataType inArgument2,
                                               C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'object_definition_list' non terminal
//--- 'parse' label
  public : virtual void nt_object_5F_definition_5F_list_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_object_5F_definition_5F_list_ (const GALGAS_implementation inArgument0,
                                                          GALGAS_objectsMap & ioArgument1,
                                                          C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'objref_option' non terminal
//--- 'parse' label
  public : virtual void nt_objref_5F_option_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_objref_5F_option_ (GALGAS_lstring & outArgument0,
                                              GALGAS_impType & outArgument1,
                                              GALGAS_lstring inArgument2,
                                              C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'oil_declaration' non terminal
//--- 'parse' label
  public : virtual void nt_oil_5F_declaration_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_oil_5F_declaration_ (const GALGAS_implementationObjectMap inArgument0,
                                                GALGAS_objectAttributes & ioArgument1,
                                                C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'oil_declaration_list' non terminal
//--- 'parse' label
  public : virtual void nt_oil_5F_declaration_5F_list_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_oil_5F_declaration_5F_list_ (const GALGAS_implementationObjectMap inArgument0,
                                                        GALGAS_objectAttributes & ioArgument1,
                                                        C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'range' non terminal
//--- 'parse' label
  public : virtual void nt_range_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_range_ (GALGAS_attributeRange & outArgument0,
                                   const GALGAS_dataType inArgument1,
                                   C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'range_content' non terminal
//--- 'parse' label
  public : virtual void nt_range_5F_content_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_range_5F_content_ (GALGAS_attributeRange & outArgument0,
                                              const GALGAS_dataType inArgument1,
                                              C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'set_followup' non terminal
//--- 'parse' label
  public : virtual void nt_set_5F_followup_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_set_5F_followup_ (GALGAS_numberList & ioArgument0,
                                             const GALGAS_dataType inArgument1,
                                             C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'sign' non terminal
//--- 'parse' label
  public : virtual void nt_sign_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_sign_ (GALGAS_bool & outArgument0,
                                  C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'start' non terminal
//--- 'parse' label
  public : virtual void nt_start_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_start_ (C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'string_options' non terminal
//--- 'parse' label
  public : virtual void nt_string_5F_options_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_string_5F_options_ (GALGAS_lstring & outArgument0,
                                               GALGAS_impType & outArgument1,
                                               C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'struct_options' non terminal
//--- 'parse' label
  public : virtual void nt_struct_5F_options_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_struct_5F_options_ (GALGAS_lstring & outArgument0,
                                               GALGAS_impType & outArgument1,
                                               C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'type_options' non terminal
//--- 'parse' label
  public : virtual void nt_type_5F_options_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_type_5F_options_ (GALGAS_lstring & outArgument0,
                                             GALGAS_impType & outArgument1,
                                             const GALGAS_dataType inArgument2,
                                             C_Lexique_goil_5F_lexique * inCompiler) ;

//------------------------------------- 'with_auto' non terminal
//--- 'parse' label
  public : virtual void nt_with_5F_auto_parse (C_Lexique_goil_5F_lexique * inCompiler) ;

//----------- '' label
  public : virtual void nt_with_5F_auto_ (GALGAS_bool & outArgument0,
                                          C_Lexique_goil_5F_lexique * inCompiler) ;

  public : virtual int32_t select_goil_5F_syntax_0 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_1 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_2 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_3 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_4 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_5 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_6 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_7 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_8 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_9 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_10 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_11 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_12 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_goil_5F_syntax_13 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_0 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_1 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_2 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_3 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_4 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_5 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_6 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_7 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_8 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_9 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_10 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_11 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_12 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_13 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_14 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_15 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_16 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_17 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_18 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_19 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_20 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_21 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_22 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_23 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_24 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_25 (C_Lexique_goil_5F_lexique *) ;

  public : virtual int32_t select_implementation_5F_parser_26 (C_Lexique_goil_5F_lexique *) ;
} ;

//---------------------------------------------------------------------------------------------------------------------*
//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               Category method '@implementation checkObjectReferences'                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

typedef void (*categoryMethodSignature_implementation_checkObjectReferences) (const class cPtr_implementation * inObject,
                                                                              class C_Compiler * inCompiler
                                                                              COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*

void enterCategoryMethod_checkObjectReferences (const int32_t inClassIndex,
                                                categoryMethodSignature_implementation_checkObjectReferences inMethod) ;

//---------------------------------------------------------------------------------------------------------------------*

void callCategoryMethod_checkObjectReferences (const class cPtr_implementation * inObject,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               Bool options                                                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

extern C_BoolCommandLineOption gOption_goil_5F_options_generate_5F_log ;

extern C_BoolCommandLineOption gOption_goil_5F_options_warnMultiple ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               UInt options                                                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              String options                                                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

extern C_StringCommandLineOption gOption_goil_5F_options_config ;

extern C_StringCommandLineOption gOption_goil_5F_options_project_5F_dir ;

extern C_StringCommandLineOption gOption_goil_5F_options_target_5F_platform ;

extern C_StringCommandLineOption gOption_goil_5F_options_template_5F_dir ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              String List options                                                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

//---------------------------------------------------------------------------------------------------------------------*

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Routine 'file_in_path'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_file_5F_in_5F_path (class GALGAS_lstring & ioArgument0,
                                 class C_Compiler * inCompiler
                                 COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               Routine 'generate_all'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_generate_5F_all (const class GALGAS_TfieldMap constinArgument0,
                              class C_Compiler * inCompiler
                              COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                Routine 'setDefaults'                                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_setDefaults (const class GALGAS_implementation constinArgument0,
                          class GALGAS_applicationDefinition & ioArgument1,
                          class C_Compiler * inCompiler
                          COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                 Routine 'verifyAll'                                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

void routine_verifyAll (const class GALGAS_implementation constinArgument0,
                        const class GALGAS_applicationDefinition constinArgument1,
                        class C_Compiler * inCompiler
                        COMMA_LOCATION_ARGS) ;

#endif
