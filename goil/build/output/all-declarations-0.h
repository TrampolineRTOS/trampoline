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

//--------------------------------- Implementation of getter 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_Ttype & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_isBoolType (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_isEnumType (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_isFloatType (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_isFunctionType (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_isIntType (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_isListType (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_isMapType (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_isStringType (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_isStructType (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_isUnconstructedType (LOCATION_ARGS) const ;


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
  public : VIRTUAL_IN_DEBUG class GALGAS_Ttype getter_mTypeAtIndex (const class GALGAS_uint & constinOperand0,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_TtypeList getter_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_TtypeList getter_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
//--------------------------------- Friend

  friend class cEnumerator_TtypeList ;
 
} ; // End of GALGAS_TtypeList class

//---------------------------------------------------------------------------------------------------------------------*
//   Enumerator declaration                                                                                            *
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

//--------------------------------- Implementation of getter 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_TtypeList_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_Ttype getter_mType (LOCATION_ARGS) const ;


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
  public : VIRTUAL_IN_DEBUG class GALGAS_Ttype getter_mTypeForKey (const class GALGAS_string & constinOperand0,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_Tvalue getter_mValueForKey (const class GALGAS_string & constinOperand0,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_TfieldMap getter_overriddenMap (C_Compiler * inCompiler
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
//   Enumerator declaration                                                                                            *
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
  public : VIRTUAL_IN_DEBUG class GALGAS_TfieldMap getter_mMapAtIndex (const class GALGAS_uint & constinOperand0,
                                                                       C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_TfieldMapList getter_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_TfieldMapList getter_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
//--------------------------------- Friend

  friend class cEnumerator_TfieldMapList ;
 
} ; // End of GALGAS_TfieldMapList class

//---------------------------------------------------------------------------------------------------------------------*
//   Enumerator declaration                                                                                            *
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

//--------------------------------- Implementation of getter 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_Tfunction & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_lstringlist getter_args (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_content (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstring getter_name (LOCATION_ARGS) const ;


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

//--------------------------------- Implementation of getter 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_Tvalue & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_lstring getter_mDescription (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_double getter_mFloatValue (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_Tfunction getter_mFunctionValue (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_sint_36__34_ getter_mInt_36__34_Value (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_TfieldMapList getter_mMapListValue (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_mStringValue (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_TfieldMap getter_mStructValue (LOCATION_ARGS) const ;


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

//--------------------------------- Implementation of getter 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_TfieldMap_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_lstring getter_lkey (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_Ttype getter_mType (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_Tvalue getter_mValue (LOCATION_ARGS) const ;


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

//--------------------------------- Implementation of getter 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_TfieldMapList_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_TfieldMap getter_mMap (LOCATION_ARGS) const ;


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
  public : VIRTUAL_IN_DEBUG class GALGAS_Ttype getter_mTypeAtIndex (const class GALGAS_uint & constinOperand0,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_Tvalue getter_mValueAtIndex (const class GALGAS_uint & constinOperand0,
                                                                      C_Compiler * inCompiler
                                                                      COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_TexpressionList getter_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                                  C_Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_TexpressionList getter_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                                  C_Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
//--------------------------------- Friend

  friend class cEnumerator_TexpressionList ;
 
} ; // End of GALGAS_TexpressionList class

//---------------------------------------------------------------------------------------------------------------------*
//   Enumerator declaration                                                                                            *
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

//--------------------------------- Implementation of getter 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_TexpressionList_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_Ttype getter_mType (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_Tvalue getter_mValue (LOCATION_ARGS) const ;


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
  public : VIRTUAL_IN_DEBUG class GALGAS_Tvalue getter_mEnumeratedValueAtIndex (const class GALGAS_uint & constinOperand0,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_mPrefixAtIndex (const class GALGAS_uint & constinOperand0,
                                                                       C_Compiler * inCompiler
                                                                       COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_TenumationList getter_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                                 C_Compiler * inCompiler
                                                                                 COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_TenumationList getter_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                                 C_Compiler * inCompiler
                                                                                 COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
//--------------------------------- Friend

  friend class cEnumerator_TenumationList ;
 
} ; // End of GALGAS_TenumationList class

//---------------------------------------------------------------------------------------------------------------------*
//   Enumerator declaration                                                                                            *
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

//--------------------------------- Implementation of getter 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_TenumationList_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_Tvalue getter_mEnumeratedValue (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_string getter_mPrefix (LOCATION_ARGS) const ;


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
  public : VIRTUAL_IN_DEBUG class GALGAS_lsint getter_idxAtIndex (const class GALGAS_uint & constinOperand0,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstring getter_itemAtIndex (const class GALGAS_uint & constinOperand0,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstring getter_keyAtIndex (const class GALGAS_uint & constinOperand0,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_TvarPath getter_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                           C_Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_TvarPath getter_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                           C_Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
//--------------------------------- Friend

  friend class cEnumerator_TvarPath ;
 
} ; // End of GALGAS_TvarPath class

//---------------------------------------------------------------------------------------------------------------------*
//   Enumerator declaration                                                                                            *
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

//--------------------------------- Implementation of getter 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_TvarPath_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_lsint getter_idx (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstring getter_item (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstring getter_key (LOCATION_ARGS) const ;


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
   kToken_executable,
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
  public : virtual int16_t terminalVocabularyCount (void) const { return 95 ; }

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
  public : VIRTUAL_IN_DEBUG class GALGAS_lstring getter_keyAtIndex (const class GALGAS_uint & constinOperand0,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lsint getter_orderAtIndex (const class GALGAS_uint & constinOperand0,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_sortingKeyList getter_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                                 C_Compiler * inCompiler
                                                                                 COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_sortingKeyList getter_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                                 C_Compiler * inCompiler
                                                                                 COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
//--------------------------------- Friend

  friend class cEnumerator_sortingKeyList ;
 
} ; // End of GALGAS_sortingKeyList class

//---------------------------------------------------------------------------------------------------------------------*
//   Enumerator declaration                                                                                            *
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

//--------------------------------- Implementation of getter 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_sortingKeyList_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_lstring getter_key (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lsint getter_order (LOCATION_ARGS) const ;


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

  protected : virtual int32_t select_template_5F_parser_28 (C_Lexique_template_5F_scanner *) = 0 ;


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
//                           Category getter '@Ttype messageGoilTemplateType' (as function)                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

class GALGAS_string extensionGetter_messageGoilTemplateType (const class GALGAS_Ttype & inObject,
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
                                                     GALGAS_string inNameString,
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

  public : virtual int32_t select_template_5F_parser_28 (C_Lexique_template_5F_scanner *) ;

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
   kToken_include,
   kToken_includeifexists} ;

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
  public : virtual int16_t terminalVocabularyCount (void) const { return 40 ; }

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

//--------------------------------- Implementation of getter 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_dataType & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_isBoolean (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_isEnumeration (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_isFloatNumber (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_isIdentifier (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_isObjectType (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_isSint_33__32_Number (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_isSint_36__34_Number (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_isString (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_isStructType (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_isUint_33__32_Number (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_isUint_36__34_Number (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_bool getter_isVoid (LOCATION_ARGS) const ;


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
  public : VIRTUAL_IN_DEBUG class GALGAS_location getter_locationAtIndex (const class GALGAS_uint & constinOperand0,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint_33__32_List getter_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                                   C_Compiler * inCompiler
                                                                                   COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint_33__32_List getter_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                                   C_Compiler * inCompiler
                                                                                   COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint getter_valueAtIndex (const class GALGAS_uint & constinOperand0,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
//--------------------------------- Friend

  friend class cEnumerator_uint_33__32_List ;
 
} ; // End of GALGAS_uint_33__32_List class

//---------------------------------------------------------------------------------------------------------------------*
//   Enumerator declaration                                                                                            *
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

//--------------------------------- Implementation of getter 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_uint_33__32_List_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_location getter_location (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint getter_value (LOCATION_ARGS) const ;


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
  public : VIRTUAL_IN_DEBUG class GALGAS_location getter_locationAtIndex (const class GALGAS_uint & constinOperand0,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint_36__34_List getter_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                                   C_Compiler * inCompiler
                                                                                   COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint_36__34_List getter_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                                   C_Compiler * inCompiler
                                                                                   COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint_36__34_ getter_valueAtIndex (const class GALGAS_uint & constinOperand0,
                                                                           C_Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
//--------------------------------- Friend

  friend class cEnumerator_uint_36__34_List ;
 
} ; // End of GALGAS_uint_36__34_List class

//---------------------------------------------------------------------------------------------------------------------*
//   Enumerator declaration                                                                                            *
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

//--------------------------------- Implementation of getter 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_uint_36__34_List_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_location getter_location (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_uint_36__34_ getter_value (LOCATION_ARGS) const ;


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
  public : VIRTUAL_IN_DEBUG class GALGAS_location getter_locationAtIndex (const class GALGAS_uint & constinOperand0,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_sint_33__32_List getter_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                                   C_Compiler * inCompiler
                                                                                   COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_sint_33__32_List getter_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                                   C_Compiler * inCompiler
                                                                                   COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_sint getter_valueAtIndex (const class GALGAS_uint & constinOperand0,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
//--------------------------------- Friend

  friend class cEnumerator_sint_33__32_List ;
 
} ; // End of GALGAS_sint_33__32_List class

//---------------------------------------------------------------------------------------------------------------------*
//   Enumerator declaration                                                                                            *
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

//--------------------------------- Implementation of getter 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_sint_33__32_List_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_location getter_location (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_sint getter_value (LOCATION_ARGS) const ;


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
  public : VIRTUAL_IN_DEBUG class GALGAS_location getter_locationAtIndex (const class GALGAS_uint & constinOperand0,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_sint_36__34_List getter_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                                   C_Compiler * inCompiler
                                                                                   COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_sint_36__34_List getter_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                                   C_Compiler * inCompiler
                                                                                   COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_sint_36__34_ getter_valueAtIndex (const class GALGAS_uint & constinOperand0,
                                                                           C_Compiler * inCompiler
                                                                           COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
//--------------------------------- Friend

  friend class cEnumerator_sint_36__34_List ;
 
} ; // End of GALGAS_sint_36__34_List class

//---------------------------------------------------------------------------------------------------------------------*
//   Enumerator declaration                                                                                            *
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

//--------------------------------- Implementation of getter 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_sint_36__34_List_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_location getter_location (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_sint_36__34_ getter_value (LOCATION_ARGS) const ;


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
  public : VIRTUAL_IN_DEBUG class GALGAS_location getter_locationAtIndex (const class GALGAS_uint & constinOperand0,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_floatList getter_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_floatList getter_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                            C_Compiler * inCompiler
                                                                            COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_double getter_valueAtIndex (const class GALGAS_uint & constinOperand0,
                                                                     C_Compiler * inCompiler
                                                                     COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
//--------------------------------- Friend

  friend class cEnumerator_floatList ;
 
} ; // End of GALGAS_floatList class

//---------------------------------------------------------------------------------------------------------------------*
//   Enumerator declaration                                                                                            *
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

//--------------------------------- Implementation of getter 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_floatList_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_location getter_location (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_double getter_value (LOCATION_ARGS) const ;


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
  public : VIRTUAL_IN_DEBUG class GALGAS_location getter_locationAtIndex (const class GALGAS_uint & constinOperand0,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_numberList getter_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                             C_Compiler * inCompiler
                                                                             COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_numberList getter_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                             C_Compiler * inCompiler
                                                                             COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_object_5F_t getter_valueAtIndex (const class GALGAS_uint & constinOperand0,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
//--------------------------------- Friend

  friend class cEnumerator_numberList ;
 
} ; // End of GALGAS_numberList class

//---------------------------------------------------------------------------------------------------------------------*
//   Enumerator declaration                                                                                            *
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
  public : VIRTUAL_IN_DEBUG class GALGAS_location getter_location (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_lstring getter_oil_5F_desc (LOCATION_ARGS) const ;


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
  public : VIRTUAL_IN_DEBUG GALGAS_lstring getter_oil_5F_desc (LOCATION_ARGS) const ;
  public : VIRTUAL_IN_DEBUG GALGAS_location getter_location (LOCATION_ARGS) const ;
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

//--------------------------------- Implementation of getter 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_numberList_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_location getter_location (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_object_5F_t getter_value (LOCATION_ARGS) const ;


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
  public : VIRTUAL_IN_DEBUG class GALGAS_location getter_locationAtIndex (const class GALGAS_uint & constinOperand0,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_locationList getter_subListFromIndex (const class GALGAS_uint & constinOperand0,
                                                                               C_Compiler * inCompiler
                                                                               COMMA_LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG class GALGAS_locationList getter_subListWithRange (const class GALGAS_range & constinOperand0,
                                                                               C_Compiler * inCompiler
                                                                               COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
//--------------------------------- Friend

  friend class cEnumerator_locationList ;
 
} ; // End of GALGAS_locationList class

//---------------------------------------------------------------------------------------------------------------------*
//   Enumerator declaration                                                                                            *
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

//--------------------------------- Implementation of getter 'description'
  public : VIRTUAL_IN_DEBUG void description (C_String & ioString,
                                              const int32_t inIndentation) const ;
//--------------------------------- Comparison
  public : typeComparisonResult objectCompare (const GALGAS_locationList_2D_element & inOperand) const ;

//--------------------------------- Setters

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Getters
  public : VIRTUAL_IN_DEBUG class GALGAS_location getter_location (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_locationList_2D_element class


//---------------------------------------------------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_locationList_2D_element ;

#endif
