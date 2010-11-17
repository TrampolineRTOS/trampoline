//---------------------------------------------------------------------------*
//                                                                           *
//                     File 'goil_types_timing_prot.h'                       *
//             Generated by version version GALGAS_BETA_VERSION              *
//                    november 17th, 2010, at 19h29'53"                      *
//                                                                           *
//---------------------------------------------------------------------------*

//--- START OF USER ZONE 1


//--- END OF USER ZONE 1

#ifndef goil_types_timing_prot_ENTITIES_DEFINED
#define goil_types_timing_prot_ENTITIES_DEFINED

//---------------------------------------------------------------------------*

#include "galgas2/predefined-types.h"

//---------------------------------------------------------------------------*

#include "goil_basic_types.h"
#include "goil_types_resource.h"
#include "goil_routines.h"
#include "cfg_types.h"

//---------------------------------------------------------------------------*

class GALGAS__32_stringlist ;
class GALGAS_application ;
class GALGAS_attrs ;
class GALGAS_auto_5F_bool_5F_class ;
class GALGAS_auto_5F_sint_33__32__5F_class ;
class GALGAS_auto_5F_sint_36__34__5F_class ;
class GALGAS_auto_5F_string_5F_class ;
class GALGAS_auto_5F_uint_33__32__5F_class ;
class GALGAS_auto_5F_uint_36__34__5F_class ;
class GALGAS_autostart_5F_false ;
class GALGAS_autostart_5F_obj ;
class GALGAS_autostart_5F_void ;
class GALGAS_basic_5F_type ;
class GALGAS_binaryset ;
class GALGAS_bool ;
class GALGAS_bool_5F_class ;
class GALGAS_cfg_5F_attrs ;
class GALGAS_char ;
class GALGAS_config ;
class GALGAS_data ;
class GALGAS_double ;
class GALGAS_false_5F_timing_5F_prot ;
class GALGAS_filewrapper ;
class GALGAS_float_5F_class ;
class GALGAS_float_5F_empty_5F_set ;
class GALGAS_float_5F_set ;
class GALGAS_function ;
class GALGAS_functionlist ;
class GALGAS_ident_5F_list ;
class GALGAS_ident_5F_list_5F_map ;
class GALGAS_ident_5F_map ;
class GALGAS_imp_5F_obj_5F_ref ;
class GALGAS_imp_5F_sca_5F_type ;
class GALGAS_imp_5F_type ;
class GALGAS_interrupts ;
class GALGAS_lbool ;
class GALGAS_lchar ;
class GALGAS_ldouble ;
class GALGAS_linked_5F_resources ;
class GALGAS_list_5F_sint_33__32_ ;
class GALGAS_list_5F_sint_36__34_ ;
class GALGAS_list_5F_uint_33__32_ ;
class GALGAS_list_5F_uint_36__34_ ;
class GALGAS_location ;
class GALGAS_lsint ;
class GALGAS_lsint_36__34_ ;
class GALGAS_lstring ;
class GALGAS_lstringMap ;
class GALGAS_lstringlist ;
class GALGAS_luint ;
class GALGAS_luint_36__34_ ;
class GALGAS_luintlist ;
class GALGAS_number_5F_set ;
class GALGAS_object ;
class GALGAS_objectlist ;
class GALGAS_oil_5F_obj ;
class GALGAS_prefix_5F_map ;
class GALGAS_resource_5F_map ;
class GALGAS_resource_5F_obj ;
class GALGAS_resource_5F_property_5F_internal_5F_obj ;
class GALGAS_resource_5F_property_5F_linked_5F_obj ;
class GALGAS_resource_5F_property_5F_obj ;
class GALGAS_resource_5F_property_5F_standard_5F_obj ;
class GALGAS_resource_5F_property_5F_void_5F_obj ;
class GALGAS_rezlock_5F_map ;
class GALGAS_sint ;
class GALGAS_sint_33__32__5F_class ;
class GALGAS_sint_33__32__5F_empty_5F_set ;
class GALGAS_sint_33__32__5F_list ;
class GALGAS_sint_33__32__5F_range ;
class GALGAS_sint_33__32__5F_set ;
class GALGAS_sint_33__32__5F_type ;
class GALGAS_sint_36__34_ ;
class GALGAS_sint_36__34__5F_class ;
class GALGAS_sint_36__34__5F_empty_5F_set ;
class GALGAS_sint_36__34__5F_list ;
class GALGAS_sint_36__34__5F_range ;
class GALGAS_sint_36__34__5F_set ;
class GALGAS_sint_36__34__5F_type ;
class GALGAS_string ;
class GALGAS_stringMap ;
class GALGAS_string_5F_class ;
class GALGAS_stringlist ;
class GALGAS_stringset ;
class GALGAS_stringset_5F_map ;
class GALGAS_timing_5F_prot ;
class GALGAS_timing_5F_prot_5F_isr ;
class GALGAS_timing_5F_prot_5F_task ;
class GALGAS_type ;
class GALGAS_typelist ;
class GALGAS_uint ;
class GALGAS_uint_33__32__5F_class ;
class GALGAS_uint_33__32__5F_empty_5F_set ;
class GALGAS_uint_33__32__5F_list ;
class GALGAS_uint_33__32__5F_range ;
class GALGAS_uint_33__32__5F_set ;
class GALGAS_uint_33__32__5F_type ;
class GALGAS_uint_36__34_ ;
class GALGAS_uint_36__34__5F_class ;
class GALGAS_uint_36__34__5F_empty_5F_set ;
class GALGAS_uint_36__34__5F_list ;
class GALGAS_uint_36__34__5F_range ;
class GALGAS_uint_36__34__5F_set ;
class GALGAS_uint_36__34__5F_type ;
class GALGAS_uint_36__34_list ;
class GALGAS_uintlist ;
class GALGAS_void ;
class GALGAS_void_5F_bool_5F_class ;
class GALGAS_void_5F_float_5F_class ;
class GALGAS_void_5F_sint_33__32__5F_class ;
class GALGAS_void_5F_sint_36__34__5F_class ;
class GALGAS_void_5F_string_5F_class ;
class GALGAS_void_5F_timing_5F_prot ;
class GALGAS_void_5F_type ;
class GALGAS_void_5F_uint_33__32__5F_class ;
class GALGAS_void_5F_uint_36__34__5F_class ;

//---------------------------------------------------------------------------*
//                                                                           *
//                             @rezlock_map map                              *
//                                                                           *
//---------------------------------------------------------------------------*

class cMapElement_rezlock_5F_map ;

//---------------------------------------------------------------------------*

extern const char * kSearchErrorMessage_rezlock_5F_map_get ;

//---------------------------------------------------------------------------*

class GALGAS_rezlock_5F_map : public AC_GALGAS_map {
//--------------------------------- Default constructor
  public : GALGAS_rezlock_5F_map (void) ;

//--------------------------------- Handle copy
  public : GALGAS_rezlock_5F_map (const GALGAS_rezlock_5F_map & inSource) ;
  public : GALGAS_rezlock_5F_map & operator = (const GALGAS_rezlock_5F_map & inSource) ;

//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_rezlock_5F_map extractObject (const GALGAS_object & inObject,
                                                       C_Compiler * inCompiler,
                                                       const GALGAS_location & inErrorLocation
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_rezlock_5F_map constructor_emptyMap (LOCATION_ARGS) ;

  public : static GALGAS_rezlock_5F_map constructor_mapWithMapToOverride (const GALGAS_rezlock_5F_map & inOperand0
                                                                          COMMA_LOCATION_ARGS) ;


//--------------------------------- Modifiers
  public : VIRTUAL_IN_DEBUG void modifier_del (GALGAS_lstring constinArgument0,
                                               GALGAS_uint_36__34_ & outArgument1,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_put (GALGAS_lstring constinArgument0,
                                               GALGAS_uint_36__34_ constinArgument1,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG void modifier_setTimeForKey (GALGAS_uint_36__34_ constinArgument0,
                                                         GALGAS_string constinArgument1,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) ;


//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_get (GALGAS_lstring constinArgument0,
                                             GALGAS_uint_36__34_ & outArgument1,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Readers
  public : VIRTUAL_IN_DEBUG GALGAS_rezlock_5F_map reader_overriddenMap (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGAS_uint_36__34_ reader_timeForKey (const GALGAS_string & constinOperand0,
                                                                   C_Compiler * inCompiler
                                                                   COMMA_LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
//--------------------------------- 'with' accessors
  public : VIRTUAL_IN_DEBUG cMapElement_rezlock_5F_map * readWriteAccessForWithInstruction_get (C_Compiler * inCompiler,
                                                                                                const GALGAS_lstring & inKey
                                                                                                COMMA_LOCATION_ARGS) ;

  public : VIRTUAL_IN_DEBUG cMapElement_rezlock_5F_map * readWriteAccessForWithInstruction_hasKey (C_Compiler * inCompiler,
                                                                                                   const GALGAS_string & inKey
                                                                                                   COMMA_LOCATION_ARGS) ;

//--------------------------------- Friend

  friend class cEnumerator_rezlock_5F_map ;
 
} ; // End of GALGAS_rezlock_5F_map class

//---------------------------------------------------------------------------*
//   Enumerator declaration                                                  *
//---------------------------------------------------------------------------*

class cEnumerator_rezlock_5F_map : public cGenericAbstractEnumerator {
  public : cEnumerator_rezlock_5F_map (const GALGAS_rezlock_5F_map & inEnumeratedObject,
                                       const bool inAscending) ;

//--- Current element access
  public : GALGAS_lstring current_lkey (LOCATION_ARGS) const ;
  public : GALGAS_uint_36__34_ current_time (LOCATION_ARGS) const ;
} ;

//---------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_rezlock_5F_map ;

//--------------------------------- 'with' accessors
cCollectionElement * readWriteAccessForWithInstruction_get (C_Compiler * inCompiler,
                                                            GALGAS_rezlock_5F_map & ioMap,
                                                            GALGAS_lstring & inKey
                                                            COMMA_LOCATION_ARGS) ;

cCollectionElement * readWriteAccessForWithInstruction_hasKey (C_Compiler * inCompiler,
                                                               GALGAS_rezlock_5F_map & ioMap,
                                                               GALGAS_string & inKey
                                                               COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                          Routine 'gen_rez_table'                          *
//                                                                           *
//---------------------------------------------------------------------------*

void routine_gen_5F_rez_5F_table (GALGAS_rezlock_5F_map inArgument0,
                                  GALGAS_resource_5F_map inArgument1,
                                  GALGAS_uint_36__34_ inArgument2,
                                  GALGAS_string & outArgument3,
                                  C_Compiler * inCompiler
                                  COMMA_LOCATION_ARGS) ;

//---------------------------------------------------------------------------*
//                                                                           *
//                           @timing_5F_prot class                           *
//                                                                           *
//---------------------------------------------------------------------------*

class cPtr_timing_5F_prot ;

//---------------------------------------------------------------------------*

class GALGAS_timing_5F_prot : public AC_GALGAS_class {
//--- Constructor
  public : GALGAS_timing_5F_prot (void) ;

//---
  public : inline const cPtr_timing_5F_prot * ptr (void) const { return (const cPtr_timing_5F_prot *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_timing_5F_prot (const cPtr_timing_5F_prot * inSourcePtr) ;



//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_timing_5F_prot extractObject (const GALGAS_object & inObject,
                                                       C_Compiler * inCompiler,
                                                       const GALGAS_location & inErrorLocation
                                                       COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : enumComparisonResult objectCompare (const GALGAS_timing_5F_prot & inOperand) const ;

//--------------------------------- Modifiers

//--------------------------------- Instance Methods
  public : VIRTUAL_IN_DEBUG void method_generate (GALGAS_config inArgument0,
                                                  GALGAS_string & outArgument1,
                                                  GALGAS_string & outArgument2,
                                                  GALGAS_string inArgument3,
                                                  GALGAS_resource_5F_map inArgument4,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) const ;

//--------------------------------- Class Methods

//--------------------------------- Readers
  public : VIRTUAL_IN_DEBUG GALGAS_location reader_location (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_timing_5F_prot class


//---------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_timing_5F_prot ;

//---------------------------------------------------------------------------*
//                                                                           *
//                      @false_5F_timing_5F_prot class                       *
//                                                                           *
//---------------------------------------------------------------------------*

class cPtr_false_5F_timing_5F_prot ;

//---------------------------------------------------------------------------*

class GALGAS_false_5F_timing_5F_prot : public GALGAS_timing_5F_prot {
//--- Constructor
  public : GALGAS_false_5F_timing_5F_prot (void) ;

//---
  public : inline const cPtr_false_5F_timing_5F_prot * ptr (void) const { return (const cPtr_false_5F_timing_5F_prot *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_false_5F_timing_5F_prot (const cPtr_false_5F_timing_5F_prot * inSourcePtr) ;

//--- Insulate
  private : VIRTUAL_IN_DEBUG void insulate (LOCATION_ARGS) ;


//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_false_5F_timing_5F_prot extractObject (const GALGAS_object & inObject,
                                                                C_Compiler * inCompiler,
                                                                const GALGAS_location & inErrorLocation
                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_false_5F_timing_5F_prot constructor_new (const GALGAS_location & inOperand0
                                                                  COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : enumComparisonResult objectCompare (const GALGAS_false_5F_timing_5F_prot & inOperand) const ;

//--------------------------------- Modifiers

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Readers

//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_false_5F_timing_5F_prot class


//---------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_false_5F_timing_5F_prot ;

//---------------------------------------------------------------------------*
//                                                                           *
//                       @timing_5F_prot_5F_isr class                        *
//                                                                           *
//---------------------------------------------------------------------------*

class cPtr_timing_5F_prot_5F_isr ;

//---------------------------------------------------------------------------*

class GALGAS_timing_5F_prot_5F_isr : public GALGAS_timing_5F_prot {
//--- Constructor
  public : GALGAS_timing_5F_prot_5F_isr (void) ;

//---
  public : inline const cPtr_timing_5F_prot_5F_isr * ptr (void) const { return (const cPtr_timing_5F_prot_5F_isr *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_timing_5F_prot_5F_isr (const cPtr_timing_5F_prot_5F_isr * inSourcePtr) ;

//--- Insulate
  private : VIRTUAL_IN_DEBUG void insulate (LOCATION_ARGS) ;


//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_timing_5F_prot_5F_isr extractObject (const GALGAS_object & inObject,
                                                              C_Compiler * inCompiler,
                                                              const GALGAS_location & inErrorLocation
                                                              COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_timing_5F_prot_5F_isr constructor_new (const GALGAS_location & inOperand0,
                                                                const GALGAS_basic_5F_type & inOperand1,
                                                                const GALGAS_basic_5F_type & inOperand2,
                                                                const GALGAS_basic_5F_type & inOperand3,
                                                                const GALGAS_basic_5F_type & inOperand4,
                                                                const GALGAS_rezlock_5F_map & inOperand5
                                                                COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : enumComparisonResult objectCompare (const GALGAS_timing_5F_prot_5F_isr & inOperand) const ;

//--------------------------------- Modifiers

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Readers
  public : VIRTUAL_IN_DEBUG GALGAS_basic_5F_type reader_all_5F_it_5F_lock (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGAS_basic_5F_type reader_exe_5F_time (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGAS_basic_5F_type reader_os_5F_it_5F_lock (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGAS_rezlock_5F_map reader_rezlocks (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGAS_basic_5F_type reader_time_5F_frame (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_timing_5F_prot_5F_isr class


//---------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_timing_5F_prot_5F_isr ;

//---------------------------------------------------------------------------*
//                                                                           *
//                       @timing_5F_prot_5F_task class                       *
//                                                                           *
//---------------------------------------------------------------------------*

class cPtr_timing_5F_prot_5F_task ;

//---------------------------------------------------------------------------*

class GALGAS_timing_5F_prot_5F_task : public GALGAS_timing_5F_prot {
//--- Constructor
  public : GALGAS_timing_5F_prot_5F_task (void) ;

//---
  public : inline const cPtr_timing_5F_prot_5F_task * ptr (void) const { return (const cPtr_timing_5F_prot_5F_task *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_timing_5F_prot_5F_task (const cPtr_timing_5F_prot_5F_task * inSourcePtr) ;

//--- Insulate
  private : VIRTUAL_IN_DEBUG void insulate (LOCATION_ARGS) ;


//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_timing_5F_prot_5F_task extractObject (const GALGAS_object & inObject,
                                                               C_Compiler * inCompiler,
                                                               const GALGAS_location & inErrorLocation
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_timing_5F_prot_5F_task constructor_new (const GALGAS_location & inOperand0,
                                                                 const GALGAS_basic_5F_type & inOperand1,
                                                                 const GALGAS_basic_5F_type & inOperand2,
                                                                 const GALGAS_basic_5F_type & inOperand3,
                                                                 const GALGAS_basic_5F_type & inOperand4,
                                                                 const GALGAS_rezlock_5F_map & inOperand5
                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : enumComparisonResult objectCompare (const GALGAS_timing_5F_prot_5F_task & inOperand) const ;

//--------------------------------- Modifiers

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Readers
  public : VIRTUAL_IN_DEBUG GALGAS_basic_5F_type reader_all_5F_it_5F_lock (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGAS_basic_5F_type reader_exe_5F_budget (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGAS_basic_5F_type reader_os_5F_it_5F_lock (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGAS_rezlock_5F_map reader_rezlocks (LOCATION_ARGS) const ;

  public : VIRTUAL_IN_DEBUG GALGAS_basic_5F_type reader_time_5F_frame (LOCATION_ARGS) const ;


//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_timing_5F_prot_5F_task class


//---------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_timing_5F_prot_5F_task ;

//---------------------------------------------------------------------------*
//                                                                           *
//                       @void_5F_timing_5F_prot class                       *
//                                                                           *
//---------------------------------------------------------------------------*

class cPtr_void_5F_timing_5F_prot ;

//---------------------------------------------------------------------------*

class GALGAS_void_5F_timing_5F_prot : public GALGAS_timing_5F_prot {
//--- Constructor
  public : GALGAS_void_5F_timing_5F_prot (void) ;

//---
  public : inline const cPtr_void_5F_timing_5F_prot * ptr (void) const { return (const cPtr_void_5F_timing_5F_prot *) mObjectPtr ; }

//--------------------------------- Constructor from pointer
  public : GALGAS_void_5F_timing_5F_prot (const cPtr_void_5F_timing_5F_prot * inSourcePtr) ;

//--- Insulate
  private : VIRTUAL_IN_DEBUG void insulate (LOCATION_ARGS) ;


//-- Start of generic part --*

//--------------------------------- Object cloning
  protected : virtual AC_GALGAS_root * clonedObject (void) const ;

//--------------------------------- Object extraction
  public : static GALGAS_void_5F_timing_5F_prot extractObject (const GALGAS_object & inObject,
                                                               C_Compiler * inCompiler,
                                                               const GALGAS_location & inErrorLocation
                                                               COMMA_LOCATION_ARGS) ;

//--------------------------------- GALGAS constructors
  public : static GALGAS_void_5F_timing_5F_prot constructor_new (const GALGAS_location & inOperand0
                                                                 COMMA_LOCATION_ARGS) ;

//--------------------------------- Comparison
  public : enumComparisonResult objectCompare (const GALGAS_void_5F_timing_5F_prot & inOperand) const ;

//--------------------------------- Modifiers

//--------------------------------- Instance Methods
//--------------------------------- Class Methods

//--------------------------------- Readers

//--------------------------------- Introspection
  public : VIRTUAL_IN_DEBUG const C_galgas_type_descriptor * staticTypeDescriptor (void) const ;
 
} ; // End of GALGAS_void_5F_timing_5F_prot class


//---------------------------------------------------------------------------*

extern const C_galgas_type_descriptor kTypeDescriptor_GALGAS_void_5F_timing_5F_prot ;

//---------------------------------------------------------------------------*
//                                                                           *
//                  Class for element of '@rezlock_map' map                  *
//                                                                           *
//---------------------------------------------------------------------------*

class cMapElement_rezlock_5F_map : public cMapElement {
//--- Map attributes
  public : GALGAS_uint_36__34_ mAttribute_time ;

//--- Constructor
  public : cMapElement_rezlock_5F_map (const GALGAS_lstring & inKey,
                                       const GALGAS_uint_36__34_ & in_time
                                       COMMA_LOCATION_ARGS) ;

//--- Virtual method for comparing elements
  public : virtual enumComparisonResult compare (const cCollectionElement * inOperand) const ;

//--- Virtual method that checks that all attributes are valid
  public : virtual bool isValid (void) const ;

//--- Virtual method that returns a copy of current object
  public : virtual cMapElement * copy (void) ;

//--- Description
 public : virtual void description (C_String & ioString, const PMSInt32 inIndentation) const ;
} ;

//---------------------------------------------------------------------------*
//                                                                           *
//                   Pointer class for @timing_prot class                    *
//                                                                           *
//---------------------------------------------------------------------------*

class cPtr_timing_5F_prot : public acPtr_class {

//--- Attributes
  public : GALGAS_location mAttribute_location ;

//--- Constructor
  public : cPtr_timing_5F_prot (const GALGAS_location & in_location
                                COMMA_LOCATION_ARGS) ;
//--- Abstract method generate
  public : virtual void method_generate (GALGAS_config cfg,
                                         GALGAS_string & result,
                                         GALGAS_string & table_name,
                                         GALGAS_string name,
                                         GALGAS_resource_5F_map rez,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) const = 0 ;


} ;

//---------------------------------------------------------------------------*
//                                                                           *
//                Pointer class for @false_timing_prot class                 *
//                                                                           *
//---------------------------------------------------------------------------*

class cPtr_false_5F_timing_5F_prot : public cPtr_timing_5F_prot {

//--- Attributes

//--- Constructor
  public : cPtr_false_5F_timing_5F_prot (const GALGAS_location & in_location
                                         COMMA_LOCATION_ARGS) ;
//--- Concrete method generate
  public : virtual void method_generate (GALGAS_config inArgument_cfg,
                                         GALGAS_string & outArgument_result,
                                         GALGAS_string & outArgument_st_5F_name,
                                         GALGAS_string inArgument_name,
                                         GALGAS_resource_5F_map inArgument_rez,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) const ;

//--- Description
  public : virtual void description (C_String & ioString,
                                     const PMSInt32 inIndentation) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------*
//                                                                           *
//                 Pointer class for @timing_prot_isr class                  *
//                                                                           *
//---------------------------------------------------------------------------*

class cPtr_timing_5F_prot_5F_isr : public cPtr_timing_5F_prot {

//--- Attributes
  public : GALGAS_basic_5F_type mAttribute_exe_5F_time ;
  public : GALGAS_basic_5F_type mAttribute_time_5F_frame ;
  public : GALGAS_basic_5F_type mAttribute_os_5F_it_5F_lock ;
  public : GALGAS_basic_5F_type mAttribute_all_5F_it_5F_lock ;
  public : GALGAS_rezlock_5F_map mAttribute_rezlocks ;

//--- Constructor
  public : cPtr_timing_5F_prot_5F_isr (const GALGAS_location & in_location,
                                       const GALGAS_basic_5F_type & in_exe_5F_time,
                                       const GALGAS_basic_5F_type & in_time_5F_frame,
                                       const GALGAS_basic_5F_type & in_os_5F_it_5F_lock,
                                       const GALGAS_basic_5F_type & in_all_5F_it_5F_lock,
                                       const GALGAS_rezlock_5F_map & in_rezlocks
                                       COMMA_LOCATION_ARGS) ;
//--- Concrete method generate
  public : virtual void method_generate (GALGAS_config inArgument_cfg,
                                         GALGAS_string & outArgument_result,
                                         GALGAS_string & outArgument_st_5F_name,
                                         GALGAS_string inArgument_name,
                                         GALGAS_resource_5F_map inArgument_rez,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) const ;

//--- Description
  public : virtual void description (C_String & ioString,
                                     const PMSInt32 inIndentation) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------*
//                                                                           *
//                 Pointer class for @timing_prot_task class                 *
//                                                                           *
//---------------------------------------------------------------------------*

class cPtr_timing_5F_prot_5F_task : public cPtr_timing_5F_prot {

//--- Attributes
  public : GALGAS_basic_5F_type mAttribute_exe_5F_budget ;
  public : GALGAS_basic_5F_type mAttribute_time_5F_frame ;
  public : GALGAS_basic_5F_type mAttribute_os_5F_it_5F_lock ;
  public : GALGAS_basic_5F_type mAttribute_all_5F_it_5F_lock ;
  public : GALGAS_rezlock_5F_map mAttribute_rezlocks ;

//--- Constructor
  public : cPtr_timing_5F_prot_5F_task (const GALGAS_location & in_location,
                                        const GALGAS_basic_5F_type & in_exe_5F_budget,
                                        const GALGAS_basic_5F_type & in_time_5F_frame,
                                        const GALGAS_basic_5F_type & in_os_5F_it_5F_lock,
                                        const GALGAS_basic_5F_type & in_all_5F_it_5F_lock,
                                        const GALGAS_rezlock_5F_map & in_rezlocks
                                        COMMA_LOCATION_ARGS) ;
//--- Concrete method generate
  public : virtual void method_generate (GALGAS_config inArgument_cfg,
                                         GALGAS_string & outArgument_result,
                                         GALGAS_string & outArgument_st_5F_name,
                                         GALGAS_string inArgument_name,
                                         GALGAS_resource_5F_map inArgument_rez,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) const ;

//--- Description
  public : virtual void description (C_String & ioString,
                                     const PMSInt32 inIndentation) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//---------------------------------------------------------------------------*
//                                                                           *
//                 Pointer class for @void_timing_prot class                 *
//                                                                           *
//---------------------------------------------------------------------------*

class cPtr_void_5F_timing_5F_prot : public cPtr_timing_5F_prot {

//--- Attributes

//--- Constructor
  public : cPtr_void_5F_timing_5F_prot (const GALGAS_location & in_location
                                        COMMA_LOCATION_ARGS) ;
//--- Concrete method generate
  public : virtual void method_generate (GALGAS_config inArgument_cfg,
                                         GALGAS_string & outArgument_result,
                                         GALGAS_string & outArgument_st_5F_name,
                                         GALGAS_string inArgument_name,
                                         GALGAS_resource_5F_map inArgument_rez,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) const ;

//--- Description
  public : virtual void description (C_String & ioString,
                                     const PMSInt32 inIndentation) const ;

  public : virtual const C_galgas_type_descriptor * classDescriptor (void) const ;

} ;

//--- START OF USER ZONE 2


//--- END OF USER ZONE 2

#endif
