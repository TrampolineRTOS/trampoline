#include "galgas2/C_Compiler.h"
#include "galgas2/C_galgas_io.h"
#include "galgas2/C_galgas_CLI_Options.h"
#include "utilities/C_PrologueEpilogue.h"

//---------------------------------------------------------------------------------------------------------------------*

#include "all-declarations-7.h"


//---------------------------------------------------------------------------------------------------------------------*

GALGAS_identifierList_2D_element::GALGAS_identifierList_2D_element (void) :
mProperty_item () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_identifierList_2D_element::~ GALGAS_identifierList_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_identifierList_2D_element::GALGAS_identifierList_2D_element (const GALGAS_object_5F_t & inOperand0) :
mProperty_item (inOperand0) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_identifierList_2D_element GALGAS_identifierList_2D_element::constructor_new (const GALGAS_object_5F_t & inOperand0 
                                                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_identifierList_2D_element result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_identifierList_2D_element (inOperand0) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_identifierList_2D_element::objectCompare (const GALGAS_identifierList_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_item.objectCompare (inOperand.mProperty_item) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_identifierList_2D_element::isValid (void) const {
  return mProperty_item.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_identifierList_2D_element::drop (void) {
  mProperty_item.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_identifierList_2D_element::description (C_String & ioString,
                                                    const int32_t inIndentation) const {
  ioString << "<struct @identifierList-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_item.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_object_5F_t GALGAS_identifierList_2D_element::getter_item (UNUSED_LOCATION_ARGS) const {
  return mProperty_item ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            @identifierList-element type                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_identifierList_2D_element ("identifierList-element",
                                                  NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_identifierList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_identifierList_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_identifierList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_identifierList_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_identifierList_2D_element GALGAS_identifierList_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                  C_Compiler * inCompiler
                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_identifierList_2D_element result ;
  const GALGAS_identifierList_2D_element * p = (const GALGAS_identifierList_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_identifierList_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("identifierList-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringMap_2D_element::GALGAS_stringMap_2D_element (void) :
mProperty_lkey (),
mProperty_value () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringMap_2D_element::~ GALGAS_stringMap_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringMap_2D_element::GALGAS_stringMap_2D_element (const GALGAS_lstring & inOperand0,
                                                          const GALGAS_string & inOperand1) :
mProperty_lkey (inOperand0),
mProperty_value (inOperand1) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringMap_2D_element GALGAS_stringMap_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_stringMap_2D_element (GALGAS_lstring::constructor_default (HERE),
                                      GALGAS_string::constructor_default (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringMap_2D_element GALGAS_stringMap_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                          const GALGAS_string & inOperand1 
                                                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_stringMap_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_stringMap_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_stringMap_2D_element::objectCompare (const GALGAS_stringMap_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_lkey.objectCompare (inOperand.mProperty_lkey) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_value.objectCompare (inOperand.mProperty_value) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_stringMap_2D_element::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_value.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_stringMap_2D_element::drop (void) {
  mProperty_lkey.drop () ;
  mProperty_value.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_stringMap_2D_element::description (C_String & ioString,
                                               const int32_t inIndentation) const {
  ioString << "<struct @stringMap-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_lkey.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_value.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_stringMap_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mProperty_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_stringMap_2D_element::getter_value (UNUSED_LOCATION_ARGS) const {
  return mProperty_value ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                               @stringMap-element type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_stringMap_2D_element ("stringMap-element",
                                             NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_stringMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_stringMap_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_stringMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_stringMap_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringMap_2D_element GALGAS_stringMap_2D_element::extractObject (const GALGAS_object & inObject,
                                                                        C_Compiler * inCompiler
                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_stringMap_2D_element result ;
  const GALGAS_stringMap_2D_element * p = (const GALGAS_stringMap_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_stringMap_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("stringMap-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringMap_2D_element::GALGAS_lstringMap_2D_element (void) :
mProperty_lkey (),
mProperty_value () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringMap_2D_element::~ GALGAS_lstringMap_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringMap_2D_element::GALGAS_lstringMap_2D_element (const GALGAS_lstring & inOperand0,
                                                            const GALGAS_lstring & inOperand1) :
mProperty_lkey (inOperand0),
mProperty_value (inOperand1) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringMap_2D_element GALGAS_lstringMap_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_lstringMap_2D_element (GALGAS_lstring::constructor_default (HERE),
                                       GALGAS_lstring::constructor_default (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringMap_2D_element GALGAS_lstringMap_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                            const GALGAS_lstring & inOperand1 
                                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstringMap_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_lstringMap_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_lstringMap_2D_element::objectCompare (const GALGAS_lstringMap_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_lkey.objectCompare (inOperand.mProperty_lkey) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_value.objectCompare (inOperand.mProperty_value) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_lstringMap_2D_element::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_value.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_lstringMap_2D_element::drop (void) {
  mProperty_lkey.drop () ;
  mProperty_value.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_lstringMap_2D_element::description (C_String & ioString,
                                                const int32_t inIndentation) const {
  ioString << "<struct @lstringMap-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_lkey.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_value.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_lstringMap_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mProperty_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_lstringMap_2D_element::getter_value (UNUSED_LOCATION_ARGS) const {
  return mProperty_value ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @lstringMap-element type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_lstringMap_2D_element ("lstringMap-element",
                                              NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_lstringMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_lstringMap_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_lstringMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_lstringMap_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstringMap_2D_element GALGAS_lstringMap_2D_element::extractObject (const GALGAS_object & inObject,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_lstringMap_2D_element result ;
  const GALGAS_lstringMap_2D_element * p = (const GALGAS_lstringMap_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_lstringMap_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("lstringMap-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_prefix_5F_map_2D_element::GALGAS_prefix_5F_map_2D_element (void) :
mProperty_lkey (),
mProperty_prefix (),
mProperty_tag_5F_to_5F_rep () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_prefix_5F_map_2D_element::~ GALGAS_prefix_5F_map_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_prefix_5F_map_2D_element::GALGAS_prefix_5F_map_2D_element (const GALGAS_lstring & inOperand0,
                                                                  const GALGAS_string & inOperand1,
                                                                  const GALGAS_string & inOperand2) :
mProperty_lkey (inOperand0),
mProperty_prefix (inOperand1),
mProperty_tag_5F_to_5F_rep (inOperand2) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_prefix_5F_map_2D_element GALGAS_prefix_5F_map_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_prefix_5F_map_2D_element (GALGAS_lstring::constructor_default (HERE),
                                          GALGAS_string::constructor_default (HERE),
                                          GALGAS_string::constructor_default (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_prefix_5F_map_2D_element GALGAS_prefix_5F_map_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                  const GALGAS_string & inOperand1,
                                                                                  const GALGAS_string & inOperand2 
                                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_prefix_5F_map_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid () && inOperand2.isValid ()) {
    result = GALGAS_prefix_5F_map_2D_element (inOperand0, inOperand1, inOperand2) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_prefix_5F_map_2D_element::objectCompare (const GALGAS_prefix_5F_map_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_lkey.objectCompare (inOperand.mProperty_lkey) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_prefix.objectCompare (inOperand.mProperty_prefix) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_tag_5F_to_5F_rep.objectCompare (inOperand.mProperty_tag_5F_to_5F_rep) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_prefix_5F_map_2D_element::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_prefix.isValid () && mProperty_tag_5F_to_5F_rep.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_prefix_5F_map_2D_element::drop (void) {
  mProperty_lkey.drop () ;
  mProperty_prefix.drop () ;
  mProperty_tag_5F_to_5F_rep.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_prefix_5F_map_2D_element::description (C_String & ioString,
                                                   const int32_t inIndentation) const {
  ioString << "<struct @prefix_map-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_lkey.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_prefix.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_tag_5F_to_5F_rep.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_prefix_5F_map_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mProperty_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_prefix_5F_map_2D_element::getter_prefix (UNUSED_LOCATION_ARGS) const {
  return mProperty_prefix ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_prefix_5F_map_2D_element::getter_tag_5F_to_5F_rep (UNUSED_LOCATION_ARGS) const {
  return mProperty_tag_5F_to_5F_rep ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @prefix_map-element type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_prefix_5F_map_2D_element ("prefix_map-element",
                                                 NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_prefix_5F_map_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_prefix_5F_map_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_prefix_5F_map_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_prefix_5F_map_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_prefix_5F_map_2D_element GALGAS_prefix_5F_map_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_prefix_5F_map_2D_element result ;
  const GALGAS_prefix_5F_map_2D_element * p = (const GALGAS_prefix_5F_map_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_prefix_5F_map_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("prefix_map-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringset_5F_map_2D_element::GALGAS_stringset_5F_map_2D_element (void) :
mProperty_lkey (),
mProperty_ids () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringset_5F_map_2D_element::~ GALGAS_stringset_5F_map_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringset_5F_map_2D_element::GALGAS_stringset_5F_map_2D_element (const GALGAS_lstring & inOperand0,
                                                                        const GALGAS_stringset & inOperand1) :
mProperty_lkey (inOperand0),
mProperty_ids (inOperand1) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringset_5F_map_2D_element GALGAS_stringset_5F_map_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_stringset_5F_map_2D_element (GALGAS_lstring::constructor_default (HERE),
                                             GALGAS_stringset::constructor_emptySet (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringset_5F_map_2D_element GALGAS_stringset_5F_map_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                        const GALGAS_stringset & inOperand1 
                                                                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_stringset_5F_map_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_stringset_5F_map_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_stringset_5F_map_2D_element::objectCompare (const GALGAS_stringset_5F_map_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_lkey.objectCompare (inOperand.mProperty_lkey) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_ids.objectCompare (inOperand.mProperty_ids) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_stringset_5F_map_2D_element::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_ids.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_stringset_5F_map_2D_element::drop (void) {
  mProperty_lkey.drop () ;
  mProperty_ids.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_stringset_5F_map_2D_element::description (C_String & ioString,
                                                      const int32_t inIndentation) const {
  ioString << "<struct @stringset_map-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_lkey.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_ids.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_stringset_5F_map_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mProperty_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringset GALGAS_stringset_5F_map_2D_element::getter_ids (UNUSED_LOCATION_ARGS) const {
  return mProperty_ids ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             @stringset_map-element type                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_stringset_5F_map_2D_element ("stringset_map-element",
                                                    NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_stringset_5F_map_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_stringset_5F_map_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_stringset_5F_map_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_stringset_5F_map_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringset_5F_map_2D_element GALGAS_stringset_5F_map_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_stringset_5F_map_2D_element result ;
  const GALGAS_stringset_5F_map_2D_element * p = (const GALGAS_stringset_5F_map_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_stringset_5F_map_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("stringset_map-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ident_5F_list_2D_element::GALGAS_ident_5F_list_2D_element (void) :
mProperty_obj_5F_name () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ident_5F_list_2D_element::~ GALGAS_ident_5F_list_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ident_5F_list_2D_element::GALGAS_ident_5F_list_2D_element (const GALGAS_lstring & inOperand0) :
mProperty_obj_5F_name (inOperand0) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ident_5F_list_2D_element GALGAS_ident_5F_list_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_ident_5F_list_2D_element (GALGAS_lstring::constructor_default (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ident_5F_list_2D_element GALGAS_ident_5F_list_2D_element::constructor_new (const GALGAS_lstring & inOperand0 
                                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_ident_5F_list_2D_element result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_ident_5F_list_2D_element (inOperand0) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_ident_5F_list_2D_element::objectCompare (const GALGAS_ident_5F_list_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_obj_5F_name.objectCompare (inOperand.mProperty_obj_5F_name) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_ident_5F_list_2D_element::isValid (void) const {
  return mProperty_obj_5F_name.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_ident_5F_list_2D_element::drop (void) {
  mProperty_obj_5F_name.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_ident_5F_list_2D_element::description (C_String & ioString,
                                                   const int32_t inIndentation) const {
  ioString << "<struct @ident_list-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_obj_5F_name.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_ident_5F_list_2D_element::getter_obj_5F_name (UNUSED_LOCATION_ARGS) const {
  return mProperty_obj_5F_name ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @ident_list-element type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_ident_5F_list_2D_element ("ident_list-element",
                                                 NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_ident_5F_list_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_ident_5F_list_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_ident_5F_list_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_ident_5F_list_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ident_5F_list_2D_element GALGAS_ident_5F_list_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_ident_5F_list_2D_element result ;
  const GALGAS_ident_5F_list_2D_element * p = (const GALGAS_ident_5F_list_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_ident_5F_list_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("ident_list-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ident_5F_list_5F_map_2D_element::GALGAS_ident_5F_list_5F_map_2D_element (void) :
mProperty_lkey (),
mProperty_objs () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ident_5F_list_5F_map_2D_element::~ GALGAS_ident_5F_list_5F_map_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ident_5F_list_5F_map_2D_element::GALGAS_ident_5F_list_5F_map_2D_element (const GALGAS_lstring & inOperand0,
                                                                                const GALGAS_ident_5F_list & inOperand1) :
mProperty_lkey (inOperand0),
mProperty_objs (inOperand1) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ident_5F_list_5F_map_2D_element GALGAS_ident_5F_list_5F_map_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_ident_5F_list_5F_map_2D_element (GALGAS_lstring::constructor_default (HERE),
                                                 GALGAS_ident_5F_list::constructor_emptyList (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ident_5F_list_5F_map_2D_element GALGAS_ident_5F_list_5F_map_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                                const GALGAS_ident_5F_list & inOperand1 
                                                                                                COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_ident_5F_list_5F_map_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_ident_5F_list_5F_map_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_ident_5F_list_5F_map_2D_element::objectCompare (const GALGAS_ident_5F_list_5F_map_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_lkey.objectCompare (inOperand.mProperty_lkey) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_objs.objectCompare (inOperand.mProperty_objs) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_ident_5F_list_5F_map_2D_element::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_objs.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_ident_5F_list_5F_map_2D_element::drop (void) {
  mProperty_lkey.drop () ;
  mProperty_objs.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_ident_5F_list_5F_map_2D_element::description (C_String & ioString,
                                                          const int32_t inIndentation) const {
  ioString << "<struct @ident_list_map-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_lkey.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_objs.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_ident_5F_list_5F_map_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mProperty_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ident_5F_list GALGAS_ident_5F_list_5F_map_2D_element::getter_objs (UNUSED_LOCATION_ARGS) const {
  return mProperty_objs ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                            @ident_list_map-element type                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_ident_5F_list_5F_map_2D_element ("ident_list_map-element",
                                                        NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_ident_5F_list_5F_map_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_ident_5F_list_5F_map_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_ident_5F_list_5F_map_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_ident_5F_list_5F_map_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_ident_5F_list_5F_map_2D_element GALGAS_ident_5F_list_5F_map_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                              C_Compiler * inCompiler
                                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_ident_5F_list_5F_map_2D_element result ;
  const GALGAS_ident_5F_list_5F_map_2D_element * p = (const GALGAS_ident_5F_list_5F_map_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_ident_5F_list_5F_map_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("ident_list_map-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectKindMap_2D_element::GALGAS_objectKindMap_2D_element (void) :
mProperty_lkey (),
mProperty_attributes () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectKindMap_2D_element::~ GALGAS_objectKindMap_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectKindMap_2D_element::GALGAS_objectKindMap_2D_element (const GALGAS_lstring & inOperand0,
                                                                  const GALGAS_objectAttributes & inOperand1) :
mProperty_lkey (inOperand0),
mProperty_attributes (inOperand1) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectKindMap_2D_element GALGAS_objectKindMap_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_objectKindMap_2D_element (GALGAS_lstring::constructor_default (HERE),
                                          GALGAS_objectAttributes::constructor_default (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectKindMap_2D_element GALGAS_objectKindMap_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                  const GALGAS_objectAttributes & inOperand1 
                                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_objectKindMap_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_objectKindMap_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_objectKindMap_2D_element::objectCompare (const GALGAS_objectKindMap_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_lkey.objectCompare (inOperand.mProperty_lkey) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_attributes.objectCompare (inOperand.mProperty_attributes) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_objectKindMap_2D_element::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_attributes.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_objectKindMap_2D_element::drop (void) {
  mProperty_lkey.drop () ;
  mProperty_attributes.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_objectKindMap_2D_element::description (C_String & ioString,
                                                   const int32_t inIndentation) const {
  ioString << "<struct @objectKindMap-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_lkey.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_attributes.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_objectKindMap_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mProperty_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectAttributes GALGAS_objectKindMap_2D_element::getter_attributes (UNUSED_LOCATION_ARGS) const {
  return mProperty_attributes ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                             @objectKindMap-element type                                             *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_objectKindMap_2D_element ("objectKindMap-element",
                                                 NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_objectKindMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_objectKindMap_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_objectKindMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_objectKindMap_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectKindMap_2D_element GALGAS_objectKindMap_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                C_Compiler * inCompiler
                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_objectKindMap_2D_element result ;
  const GALGAS_objectKindMap_2D_element * p = (const GALGAS_objectKindMap_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_objectKindMap_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("objectKindMap-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectsMap_2D_element::GALGAS_objectsMap_2D_element (void) :
mProperty_lkey (),
mProperty_objectsOfKind () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectsMap_2D_element::~ GALGAS_objectsMap_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectsMap_2D_element::GALGAS_objectsMap_2D_element (const GALGAS_lstring & inOperand0,
                                                            const GALGAS_objectKind & inOperand1) :
mProperty_lkey (inOperand0),
mProperty_objectsOfKind (inOperand1) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectsMap_2D_element GALGAS_objectsMap_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_objectsMap_2D_element (GALGAS_lstring::constructor_default (HERE),
                                       GALGAS_objectKind::constructor_default (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectsMap_2D_element GALGAS_objectsMap_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                            const GALGAS_objectKind & inOperand1 
                                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_objectsMap_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_objectsMap_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_objectsMap_2D_element::objectCompare (const GALGAS_objectsMap_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_lkey.objectCompare (inOperand.mProperty_lkey) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_objectsOfKind.objectCompare (inOperand.mProperty_objectsOfKind) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_objectsMap_2D_element::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_objectsOfKind.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_objectsMap_2D_element::drop (void) {
  mProperty_lkey.drop () ;
  mProperty_objectsOfKind.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_objectsMap_2D_element::description (C_String & ioString,
                                                const int32_t inIndentation) const {
  ioString << "<struct @objectsMap-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_lkey.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_objectsOfKind.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_objectsMap_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mProperty_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectKind GALGAS_objectsMap_2D_element::getter_objectsOfKind (UNUSED_LOCATION_ARGS) const {
  return mProperty_objectsOfKind ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                              @objectsMap-element type                                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_objectsMap_2D_element ("objectsMap-element",
                                              NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_objectsMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_objectsMap_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_objectsMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_objectsMap_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_objectsMap_2D_element GALGAS_objectsMap_2D_element::extractObject (const GALGAS_object & inObject,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_objectsMap_2D_element result ;
  const GALGAS_objectsMap_2D_element * p = (const GALGAS_objectsMap_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_objectsMap_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("objectsMap-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlAttributeMap_2D_element::GALGAS_arxmlAttributeMap_2D_element (void) :
mProperty_lkey (),
mProperty_value () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlAttributeMap_2D_element::~ GALGAS_arxmlAttributeMap_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlAttributeMap_2D_element::GALGAS_arxmlAttributeMap_2D_element (const GALGAS_lstring & inOperand0,
                                                                          const GALGAS_lstring & inOperand1) :
mProperty_lkey (inOperand0),
mProperty_value (inOperand1) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlAttributeMap_2D_element GALGAS_arxmlAttributeMap_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_arxmlAttributeMap_2D_element (GALGAS_lstring::constructor_default (HERE),
                                              GALGAS_lstring::constructor_default (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlAttributeMap_2D_element GALGAS_arxmlAttributeMap_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                          const GALGAS_lstring & inOperand1 
                                                                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_arxmlAttributeMap_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_arxmlAttributeMap_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_arxmlAttributeMap_2D_element::objectCompare (const GALGAS_arxmlAttributeMap_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_lkey.objectCompare (inOperand.mProperty_lkey) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_value.objectCompare (inOperand.mProperty_value) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_arxmlAttributeMap_2D_element::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_value.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_arxmlAttributeMap_2D_element::drop (void) {
  mProperty_lkey.drop () ;
  mProperty_value.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_arxmlAttributeMap_2D_element::description (C_String & ioString,
                                                       const int32_t inIndentation) const {
  ioString << "<struct @arxmlAttributeMap-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_lkey.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_value.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_arxmlAttributeMap_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mProperty_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_arxmlAttributeMap_2D_element::getter_value (UNUSED_LOCATION_ARGS) const {
  return mProperty_value ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           @arxmlAttributeMap-element type                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_arxmlAttributeMap_2D_element ("arxmlAttributeMap-element",
                                                     NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_arxmlAttributeMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_arxmlAttributeMap_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_arxmlAttributeMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_arxmlAttributeMap_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlAttributeMap_2D_element GALGAS_arxmlAttributeMap_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                        C_Compiler * inCompiler
                                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_arxmlAttributeMap_2D_element result ;
  const GALGAS_arxmlAttributeMap_2D_element * p = (const GALGAS_arxmlAttributeMap_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_arxmlAttributeMap_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("arxmlAttributeMap-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlElementList_2D_element::GALGAS_arxmlElementList_2D_element (void) :
mProperty_node () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlElementList_2D_element::~ GALGAS_arxmlElementList_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlElementList_2D_element::GALGAS_arxmlElementList_2D_element (const GALGAS_arxmlElementNode & inOperand0) :
mProperty_node (inOperand0) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlElementList_2D_element GALGAS_arxmlElementList_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_arxmlElementList_2D_element (GALGAS_arxmlElementNode::constructor_default (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlElementList_2D_element GALGAS_arxmlElementList_2D_element::constructor_new (const GALGAS_arxmlElementNode & inOperand0 
                                                                                        COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_arxmlElementList_2D_element result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_arxmlElementList_2D_element (inOperand0) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_arxmlElementList_2D_element::objectCompare (const GALGAS_arxmlElementList_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_node.objectCompare (inOperand.mProperty_node) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_arxmlElementList_2D_element::isValid (void) const {
  return mProperty_node.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_arxmlElementList_2D_element::drop (void) {
  mProperty_node.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_arxmlElementList_2D_element::description (C_String & ioString,
                                                      const int32_t inIndentation) const {
  ioString << "<struct @arxmlElementList-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_node.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlElementNode GALGAS_arxmlElementList_2D_element::getter_node (UNUSED_LOCATION_ARGS) const {
  return mProperty_node ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           @arxmlElementList-element type                                            *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_arxmlElementList_2D_element ("arxmlElementList-element",
                                                    NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_arxmlElementList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_arxmlElementList_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_arxmlElementList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_arxmlElementList_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlElementList_2D_element GALGAS_arxmlElementList_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                      C_Compiler * inCompiler
                                                                                      COMMA_LOCATION_ARGS) {
  GALGAS_arxmlElementList_2D_element result ;
  const GALGAS_arxmlElementList_2D_element * p = (const GALGAS_arxmlElementList_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_arxmlElementList_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("arxmlElementList-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlElementValueMap_2D_element::GALGAS_arxmlElementValueMap_2D_element (void) :
mProperty_lkey (),
mProperty_values () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlElementValueMap_2D_element::~ GALGAS_arxmlElementValueMap_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlElementValueMap_2D_element::GALGAS_arxmlElementValueMap_2D_element (const GALGAS_lstring & inOperand0,
                                                                                const GALGAS_arxmlElementValueList & inOperand1) :
mProperty_lkey (inOperand0),
mProperty_values (inOperand1) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlElementValueMap_2D_element GALGAS_arxmlElementValueMap_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_arxmlElementValueMap_2D_element (GALGAS_lstring::constructor_default (HERE),
                                                 GALGAS_arxmlElementValueList::constructor_emptyList (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlElementValueMap_2D_element GALGAS_arxmlElementValueMap_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                                const GALGAS_arxmlElementValueList & inOperand1 
                                                                                                COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_arxmlElementValueMap_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_arxmlElementValueMap_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_arxmlElementValueMap_2D_element::objectCompare (const GALGAS_arxmlElementValueMap_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_lkey.objectCompare (inOperand.mProperty_lkey) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_values.objectCompare (inOperand.mProperty_values) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_arxmlElementValueMap_2D_element::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_values.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_arxmlElementValueMap_2D_element::drop (void) {
  mProperty_lkey.drop () ;
  mProperty_values.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_arxmlElementValueMap_2D_element::description (C_String & ioString,
                                                          const int32_t inIndentation) const {
  ioString << "<struct @arxmlElementValueMap-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_lkey.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_values.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_arxmlElementValueMap_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mProperty_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlElementValueList GALGAS_arxmlElementValueMap_2D_element::getter_values (UNUSED_LOCATION_ARGS) const {
  return mProperty_values ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         @arxmlElementValueMap-element type                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_arxmlElementValueMap_2D_element ("arxmlElementValueMap-element",
                                                        NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_arxmlElementValueMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_arxmlElementValueMap_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_arxmlElementValueMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_arxmlElementValueMap_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlElementValueMap_2D_element GALGAS_arxmlElementValueMap_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                              C_Compiler * inCompiler
                                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_arxmlElementValueMap_2D_element result ;
  const GALGAS_arxmlElementValueMap_2D_element * p = (const GALGAS_arxmlElementValueMap_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_arxmlElementValueMap_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("arxmlElementValueMap-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlElementValueList_2D_element::GALGAS_arxmlElementValueList_2D_element (void) :
mProperty_value () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlElementValueList_2D_element::~ GALGAS_arxmlElementValueList_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlElementValueList_2D_element::GALGAS_arxmlElementValueList_2D_element (const GALGAS_arxmlElementValue & inOperand0) :
mProperty_value (inOperand0) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlElementValueList_2D_element GALGAS_arxmlElementValueList_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_arxmlElementValueList_2D_element (GALGAS_arxmlElementValue::constructor_default (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlElementValueList_2D_element GALGAS_arxmlElementValueList_2D_element::constructor_new (const GALGAS_arxmlElementValue & inOperand0 
                                                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_arxmlElementValueList_2D_element result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_arxmlElementValueList_2D_element (inOperand0) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_arxmlElementValueList_2D_element::objectCompare (const GALGAS_arxmlElementValueList_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_value.objectCompare (inOperand.mProperty_value) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_arxmlElementValueList_2D_element::isValid (void) const {
  return mProperty_value.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_arxmlElementValueList_2D_element::drop (void) {
  mProperty_value.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_arxmlElementValueList_2D_element::description (C_String & ioString,
                                                           const int32_t inIndentation) const {
  ioString << "<struct @arxmlElementValueList-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_value.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlElementValue GALGAS_arxmlElementValueList_2D_element::getter_value (UNUSED_LOCATION_ARGS) const {
  return mProperty_value ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         @arxmlElementValueList-element type                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_arxmlElementValueList_2D_element ("arxmlElementValueList-element",
                                                         NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_arxmlElementValueList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_arxmlElementValueList_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_arxmlElementValueList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_arxmlElementValueList_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlElementValueList_2D_element GALGAS_arxmlElementValueList_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                                C_Compiler * inCompiler
                                                                                                COMMA_LOCATION_ARGS) {
  GALGAS_arxmlElementValueList_2D_element result ;
  const GALGAS_arxmlElementValueList_2D_element * p = (const GALGAS_arxmlElementValueList_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_arxmlElementValueList_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("arxmlElementValueList-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlMetaClassMap_2D_element::GALGAS_arxmlMetaClassMap_2D_element (void) :
mProperty_lkey (),
mProperty_mType () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlMetaClassMap_2D_element::~ GALGAS_arxmlMetaClassMap_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlMetaClassMap_2D_element::GALGAS_arxmlMetaClassMap_2D_element (const GALGAS_lstring & inOperand0,
                                                                          const GALGAS_arxmlMetaClass & inOperand1) :
mProperty_lkey (inOperand0),
mProperty_mType (inOperand1) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlMetaClassMap_2D_element GALGAS_arxmlMetaClassMap_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_arxmlMetaClassMap_2D_element (GALGAS_lstring::constructor_default (HERE),
                                              GALGAS_arxmlMetaClass::constructor_default (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlMetaClassMap_2D_element GALGAS_arxmlMetaClassMap_2D_element::constructor_new (const GALGAS_lstring & inOperand0,
                                                                                          const GALGAS_arxmlMetaClass & inOperand1 
                                                                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_arxmlMetaClassMap_2D_element result ;
  if (inOperand0.isValid () && inOperand1.isValid ()) {
    result = GALGAS_arxmlMetaClassMap_2D_element (inOperand0, inOperand1) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_arxmlMetaClassMap_2D_element::objectCompare (const GALGAS_arxmlMetaClassMap_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_lkey.objectCompare (inOperand.mProperty_lkey) ;
  }
  if (result == kOperandEqual) {
    result = mProperty_mType.objectCompare (inOperand.mProperty_mType) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_arxmlMetaClassMap_2D_element::isValid (void) const {
  return mProperty_lkey.isValid () && mProperty_mType.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_arxmlMetaClassMap_2D_element::drop (void) {
  mProperty_lkey.drop () ;
  mProperty_mType.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_arxmlMetaClassMap_2D_element::description (C_String & ioString,
                                                       const int32_t inIndentation) const {
  ioString << "<struct @arxmlMetaClassMap-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_lkey.description (ioString, inIndentation+1) ;
    ioString << ", " ;
    mProperty_mType.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_arxmlMetaClassMap_2D_element::getter_lkey (UNUSED_LOCATION_ARGS) const {
  return mProperty_lkey ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlMetaClass GALGAS_arxmlMetaClassMap_2D_element::getter_mType (UNUSED_LOCATION_ARGS) const {
  return mProperty_mType ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                           @arxmlMetaClassMap-element type                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_arxmlMetaClassMap_2D_element ("arxmlMetaClassMap-element",
                                                     NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_arxmlMetaClassMap_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_arxmlMetaClassMap_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_arxmlMetaClassMap_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_arxmlMetaClassMap_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlMetaClassMap_2D_element GALGAS_arxmlMetaClassMap_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                        C_Compiler * inCompiler
                                                                                        COMMA_LOCATION_ARGS) {
  GALGAS_arxmlMetaClassMap_2D_element result ;
  const GALGAS_arxmlMetaClassMap_2D_element * p = (const GALGAS_arxmlMetaClassMap_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_arxmlMetaClassMap_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("arxmlMetaClassMap-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlMetaClasslist_2D_element::GALGAS_arxmlMetaClasslist_2D_element (void) :
mProperty_lClass () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlMetaClasslist_2D_element::~ GALGAS_arxmlMetaClasslist_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlMetaClasslist_2D_element::GALGAS_arxmlMetaClasslist_2D_element (const GALGAS_arxmlMetaClass & inOperand0) :
mProperty_lClass (inOperand0) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlMetaClasslist_2D_element GALGAS_arxmlMetaClasslist_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_arxmlMetaClasslist_2D_element (GALGAS_arxmlMetaClass::constructor_default (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlMetaClasslist_2D_element GALGAS_arxmlMetaClasslist_2D_element::constructor_new (const GALGAS_arxmlMetaClass & inOperand0 
                                                                                            COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_arxmlMetaClasslist_2D_element result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_arxmlMetaClasslist_2D_element (inOperand0) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_arxmlMetaClasslist_2D_element::objectCompare (const GALGAS_arxmlMetaClasslist_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_lClass.objectCompare (inOperand.mProperty_lClass) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_arxmlMetaClasslist_2D_element::isValid (void) const {
  return mProperty_lClass.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_arxmlMetaClasslist_2D_element::drop (void) {
  mProperty_lClass.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_arxmlMetaClasslist_2D_element::description (C_String & ioString,
                                                        const int32_t inIndentation) const {
  ioString << "<struct @arxmlMetaClasslist-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_lClass.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlMetaClass GALGAS_arxmlMetaClasslist_2D_element::getter_lClass (UNUSED_LOCATION_ARGS) const {
  return mProperty_lClass ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                          @arxmlMetaClasslist-element type                                           *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_arxmlMetaClasslist_2D_element ("arxmlMetaClasslist-element",
                                                      NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_arxmlMetaClasslist_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_arxmlMetaClasslist_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_arxmlMetaClasslist_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_arxmlMetaClasslist_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlMetaClasslist_2D_element GALGAS_arxmlMetaClasslist_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                          C_Compiler * inCompiler
                                                                                          COMMA_LOCATION_ARGS) {
  GALGAS_arxmlMetaClasslist_2D_element result ;
  const GALGAS_arxmlMetaClasslist_2D_element * p = (const GALGAS_arxmlMetaClasslist_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_arxmlMetaClasslist_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("arxmlMetaClasslist-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlMetaElementList_2D_element::GALGAS_arxmlMetaElementList_2D_element (void) :
mProperty_lElement () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlMetaElementList_2D_element::~ GALGAS_arxmlMetaElementList_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlMetaElementList_2D_element::GALGAS_arxmlMetaElementList_2D_element (const GALGAS_arxmlMetaElement & inOperand0) :
mProperty_lElement (inOperand0) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlMetaElementList_2D_element GALGAS_arxmlMetaElementList_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_arxmlMetaElementList_2D_element (GALGAS_arxmlMetaElement::constructor_default (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlMetaElementList_2D_element GALGAS_arxmlMetaElementList_2D_element::constructor_new (const GALGAS_arxmlMetaElement & inOperand0 
                                                                                                COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_arxmlMetaElementList_2D_element result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_arxmlMetaElementList_2D_element (inOperand0) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_arxmlMetaElementList_2D_element::objectCompare (const GALGAS_arxmlMetaElementList_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_lElement.objectCompare (inOperand.mProperty_lElement) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_arxmlMetaElementList_2D_element::isValid (void) const {
  return mProperty_lElement.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_arxmlMetaElementList_2D_element::drop (void) {
  mProperty_lElement.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_arxmlMetaElementList_2D_element::description (C_String & ioString,
                                                          const int32_t inIndentation) const {
  ioString << "<struct @arxmlMetaElementList-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_lElement.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlMetaElement GALGAS_arxmlMetaElementList_2D_element::getter_lElement (UNUSED_LOCATION_ARGS) const {
  return mProperty_lElement ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                         @arxmlMetaElementList-element type                                          *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_arxmlMetaElementList_2D_element ("arxmlMetaElementList-element",
                                                        NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_arxmlMetaElementList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_arxmlMetaElementList_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_arxmlMetaElementList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_arxmlMetaElementList_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlMetaElementList_2D_element GALGAS_arxmlMetaElementList_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                              C_Compiler * inCompiler
                                                                                              COMMA_LOCATION_ARGS) {
  GALGAS_arxmlMetaElementList_2D_element result ;
  const GALGAS_arxmlMetaElementList_2D_element * p = (const GALGAS_arxmlMetaElementList_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_arxmlMetaElementList_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("arxmlMetaElementList-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlMetaAttributeList_2D_element::GALGAS_arxmlMetaAttributeList_2D_element (void) :
mProperty_lAttribute () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlMetaAttributeList_2D_element::~ GALGAS_arxmlMetaAttributeList_2D_element (void) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlMetaAttributeList_2D_element::GALGAS_arxmlMetaAttributeList_2D_element (const GALGAS_arxmlMetaAttribute & inOperand0) :
mProperty_lAttribute (inOperand0) {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlMetaAttributeList_2D_element GALGAS_arxmlMetaAttributeList_2D_element::constructor_default (UNUSED_LOCATION_ARGS) {
  return GALGAS_arxmlMetaAttributeList_2D_element (GALGAS_arxmlMetaAttribute::constructor_default (HERE)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlMetaAttributeList_2D_element GALGAS_arxmlMetaAttributeList_2D_element::constructor_new (const GALGAS_arxmlMetaAttribute & inOperand0 
                                                                                                    COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_arxmlMetaAttributeList_2D_element result ;
  if (inOperand0.isValid ()) {
    result = GALGAS_arxmlMetaAttributeList_2D_element (inOperand0) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult GALGAS_arxmlMetaAttributeList_2D_element::objectCompare (const GALGAS_arxmlMetaAttributeList_2D_element & inOperand) const {
   typeComparisonResult result = kOperandEqual ;
  if (result == kOperandEqual) {
    result = mProperty_lAttribute.objectCompare (inOperand.mProperty_lAttribute) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

bool GALGAS_arxmlMetaAttributeList_2D_element::isValid (void) const {
  return mProperty_lAttribute.isValid () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_arxmlMetaAttributeList_2D_element::drop (void) {
  mProperty_lAttribute.drop () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_arxmlMetaAttributeList_2D_element::description (C_String & ioString,
                                                            const int32_t inIndentation) const {
  ioString << "<struct @arxmlMetaAttributeList-element:" ;
  if (! isValid ()) {
    ioString << " not built" ;
  }else{
    mProperty_lAttribute.description (ioString, inIndentation+1) ;
  }
  ioString << ">" ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlMetaAttribute GALGAS_arxmlMetaAttributeList_2D_element::getter_lAttribute (UNUSED_LOCATION_ARGS) const {
  return mProperty_lAttribute ;
}



//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                        @arxmlMetaAttributeList-element type                                         *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_arxmlMetaAttributeList_2D_element ("arxmlMetaAttributeList-element",
                                                          NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_arxmlMetaAttributeList_2D_element::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_arxmlMetaAttributeList_2D_element ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_arxmlMetaAttributeList_2D_element::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_arxmlMetaAttributeList_2D_element (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_arxmlMetaAttributeList_2D_element GALGAS_arxmlMetaAttributeList_2D_element::extractObject (const GALGAS_object & inObject,
                                                                                                  C_Compiler * inCompiler
                                                                                                  COMMA_LOCATION_ARGS) {
  GALGAS_arxmlMetaAttributeList_2D_element result ;
  const GALGAS_arxmlMetaAttributeList_2D_element * p = (const GALGAS_arxmlMetaAttributeList_2D_element *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_arxmlMetaAttributeList_2D_element *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("arxmlMetaAttributeList-element", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_gtlContext::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_gtlContext * p = (const cPtr_gtlContext *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_gtlContext) ;
  if (kOperandEqual == result) {
    result = mProperty_prefix.objectCompare (p->mProperty_prefix) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_path.objectCompare (p->mProperty_path) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_templateDirectory.objectCompare (p->mProperty_templateDirectory) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_templateExtension.objectCompare (p->mProperty_templateExtension) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_importPath.objectCompare (p->mProperty_importPath) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_inputVars.objectCompare (p->mProperty_inputVars) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_propagateError.objectCompare (p->mProperty_propagateError) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_debuggerContext.objectCompare (p->mProperty_debuggerContext) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_gtlContext::objectCompare (const GALGAS_gtlContext & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlContext::GALGAS_gtlContext (void) :
AC_GALGAS_class () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlContext GALGAS_gtlContext::constructor_default (LOCATION_ARGS) {
  return GALGAS_gtlContext::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                             GALGAS_string::constructor_default (HERE),
                                             GALGAS_string::constructor_default (HERE),
                                             GALGAS_string::constructor_default (HERE),
                                             GALGAS_stringlist::constructor_emptyList (HERE),
                                             GALGAS_gtlDataList::constructor_emptyList (HERE),
                                             GALGAS_bool::constructor_default (HERE),
                                             GALGAS_debuggerContext::constructor_default (HERE)
                                             COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlContext::GALGAS_gtlContext (const cPtr_gtlContext * inSourcePtr) :
AC_GALGAS_class (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_gtlContext) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlContext GALGAS_gtlContext::constructor_new (const GALGAS_lstring & inAttribute_prefix,
                                                      const GALGAS_string & inAttribute_path,
                                                      const GALGAS_string & inAttribute_templateDirectory,
                                                      const GALGAS_string & inAttribute_templateExtension,
                                                      const GALGAS_stringlist & inAttribute_importPath,
                                                      const GALGAS_gtlDataList & inAttribute_inputVars,
                                                      const GALGAS_bool & inAttribute_propagateError,
                                                      const GALGAS_debuggerContext & inAttribute_debuggerContext
                                                      COMMA_LOCATION_ARGS) {
  GALGAS_gtlContext result ;
  if (inAttribute_prefix.isValid () && inAttribute_path.isValid () && inAttribute_templateDirectory.isValid () && inAttribute_templateExtension.isValid () && inAttribute_importPath.isValid () && inAttribute_inputVars.isValid () && inAttribute_propagateError.isValid () && inAttribute_debuggerContext.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_gtlContext (inAttribute_prefix, inAttribute_path, inAttribute_templateDirectory, inAttribute_templateExtension, inAttribute_importPath, inAttribute_inputVars, inAttribute_propagateError, inAttribute_debuggerContext COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring GALGAS_gtlContext::getter_prefix (UNUSED_LOCATION_ARGS) const {
  GALGAS_lstring result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlContext * p = (const cPtr_gtlContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlContext) ;
    result = p->mProperty_prefix ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring cPtr_gtlContext::getter_prefix (UNUSED_LOCATION_ARGS) const {
  return mProperty_prefix ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_gtlContext::getter_path (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlContext * p = (const cPtr_gtlContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlContext) ;
    result = p->mProperty_path ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string cPtr_gtlContext::getter_path (UNUSED_LOCATION_ARGS) const {
  return mProperty_path ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_gtlContext::getter_templateDirectory (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlContext * p = (const cPtr_gtlContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlContext) ;
    result = p->mProperty_templateDirectory ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string cPtr_gtlContext::getter_templateDirectory (UNUSED_LOCATION_ARGS) const {
  return mProperty_templateDirectory ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string GALGAS_gtlContext::getter_templateExtension (UNUSED_LOCATION_ARGS) const {
  GALGAS_string result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlContext * p = (const cPtr_gtlContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlContext) ;
    result = p->mProperty_templateExtension ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string cPtr_gtlContext::getter_templateExtension (UNUSED_LOCATION_ARGS) const {
  return mProperty_templateExtension ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringlist GALGAS_gtlContext::getter_importPath (UNUSED_LOCATION_ARGS) const {
  GALGAS_stringlist result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlContext * p = (const cPtr_gtlContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlContext) ;
    result = p->mProperty_importPath ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_stringlist cPtr_gtlContext::getter_importPath (UNUSED_LOCATION_ARGS) const {
  return mProperty_importPath ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlDataList GALGAS_gtlContext::getter_inputVars (UNUSED_LOCATION_ARGS) const {
  GALGAS_gtlDataList result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlContext * p = (const cPtr_gtlContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlContext) ;
    result = p->mProperty_inputVars ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlDataList cPtr_gtlContext::getter_inputVars (UNUSED_LOCATION_ARGS) const {
  return mProperty_inputVars ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool GALGAS_gtlContext::getter_propagateError (UNUSED_LOCATION_ARGS) const {
  GALGAS_bool result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlContext * p = (const cPtr_gtlContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlContext) ;
    result = p->mProperty_propagateError ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool cPtr_gtlContext::getter_propagateError (UNUSED_LOCATION_ARGS) const {
  return mProperty_propagateError ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_debuggerContext GALGAS_gtlContext::getter_debuggerContext (UNUSED_LOCATION_ARGS) const {
  GALGAS_debuggerContext result ;
  if (NULL != mObjectPtr) {
    const cPtr_gtlContext * p = (const cPtr_gtlContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlContext) ;
    result = p->mProperty_debuggerContext ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_debuggerContext cPtr_gtlContext::getter_debuggerContext (UNUSED_LOCATION_ARGS) const {
  return mProperty_debuggerContext ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlContext::setter_setPrefix (GALGAS_lstring inValue
                                          COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlContext * p = (cPtr_gtlContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlContext) ;
    p->mProperty_prefix = inValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cPtr_gtlContext::setter_setPrefix (GALGAS_lstring inValue
                                        COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_prefix = inValue ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlContext::setter_setPath (GALGAS_string inValue
                                        COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlContext * p = (cPtr_gtlContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlContext) ;
    p->mProperty_path = inValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cPtr_gtlContext::setter_setPath (GALGAS_string inValue
                                      COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_path = inValue ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlContext::setter_setTemplateDirectory (GALGAS_string inValue
                                                     COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlContext * p = (cPtr_gtlContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlContext) ;
    p->mProperty_templateDirectory = inValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cPtr_gtlContext::setter_setTemplateDirectory (GALGAS_string inValue
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_templateDirectory = inValue ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlContext::setter_setTemplateExtension (GALGAS_string inValue
                                                     COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlContext * p = (cPtr_gtlContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlContext) ;
    p->mProperty_templateExtension = inValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cPtr_gtlContext::setter_setTemplateExtension (GALGAS_string inValue
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_templateExtension = inValue ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlContext::setter_setInputVars (GALGAS_gtlDataList inValue
                                             COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlContext * p = (cPtr_gtlContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlContext) ;
    p->mProperty_inputVars = inValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cPtr_gtlContext::setter_setInputVars (GALGAS_gtlDataList inValue
                                           COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_inputVars = inValue ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlContext::setter_setPropagateError (GALGAS_bool inValue
                                                  COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlContext * p = (cPtr_gtlContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlContext) ;
    p->mProperty_propagateError = inValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cPtr_gtlContext::setter_setPropagateError (GALGAS_bool inValue
                                                COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_propagateError = inValue ;
}

//---------------------------------------------------------------------------------------------------------------------*

void GALGAS_gtlContext::setter_setDebuggerContext (GALGAS_debuggerContext inValue
                                                   COMMA_LOCATION_ARGS) {
  if (NULL != mObjectPtr) {
    insulate (THERE) ;
    cPtr_gtlContext * p = (cPtr_gtlContext *) mObjectPtr ;
    macroValidSharedObject (p, cPtr_gtlContext) ;
    p->mProperty_debuggerContext = inValue ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cPtr_gtlContext::setter_setDebuggerContext (GALGAS_debuggerContext inValue
                                                 COMMA_UNUSED_LOCATION_ARGS) {
  mProperty_debuggerContext = inValue ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                         Pointer class for @gtlContext class                                         *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_gtlContext::cPtr_gtlContext (const GALGAS_lstring & in_prefix,
                                  const GALGAS_string & in_path,
                                  const GALGAS_string & in_templateDirectory,
                                  const GALGAS_string & in_templateExtension,
                                  const GALGAS_stringlist & in_importPath,
                                  const GALGAS_gtlDataList & in_inputVars,
                                  const GALGAS_bool & in_propagateError,
                                  const GALGAS_debuggerContext & in_debuggerContext
                                  COMMA_LOCATION_ARGS) :
acPtr_class (THERE),
mProperty_prefix (in_prefix),
mProperty_path (in_path),
mProperty_templateDirectory (in_templateDirectory),
mProperty_templateExtension (in_templateExtension),
mProperty_importPath (in_importPath),
mProperty_inputVars (in_inputVars),
mProperty_propagateError (in_propagateError),
mProperty_debuggerContext (in_debuggerContext) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_gtlContext::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlContext ;
}

void cPtr_gtlContext::description (C_String & ioString,
                                   const int32_t inIndentation) const {
  ioString << "[@gtlContext:" ;
  mProperty_prefix.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_path.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_templateDirectory.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_templateExtension.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_importPath.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_inputVars.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_propagateError.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_debuggerContext.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_gtlContext::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_gtlContext (mProperty_prefix, mProperty_path, mProperty_templateDirectory, mProperty_templateExtension, mProperty_importPath, mProperty_inputVars, mProperty_propagateError, mProperty_debuggerContext COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  @gtlContext type                                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_gtlContext ("gtlContext",
                                   NULL) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_gtlContext::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_gtlContext ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_gtlContext::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_gtlContext (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlContext GALGAS_gtlContext::extractObject (const GALGAS_object & inObject,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
  GALGAS_gtlContext result ;
  const GALGAS_gtlContext * p = (const GALGAS_gtlContext *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_gtlContext *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("gtlContext", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Extension setter '@gtlContext addModulePath'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionSetterSignature_gtlContext_addModulePath> gExtensionModifierTable_gtlContext_addModulePath ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_addModulePath (const int32_t inClassIndex,
                                         extensionSetterSignature_gtlContext_addModulePath inModifier) {
  gExtensionModifierTable_gtlContext_addModulePath.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_addModulePath (cPtr_gtlContext * inObject,
                                        const GALGAS_string constin_rootPath,
                                        const GALGAS_string constin_modulePath,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_gtlContext_addModulePath f = NULL ;
    if (classIndex < gExtensionModifierTable_gtlContext_addModulePath.count ()) {
      f = gExtensionModifierTable_gtlContext_addModulePath (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_gtlContext_addModulePath.count ()) {
           f = gExtensionModifierTable_gtlContext_addModulePath (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_gtlContext_addModulePath.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, constin_rootPath, constin_modulePath, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_gtlContext_addModulePath (cPtr_gtlContext * inObject,
                                                      const GALGAS_string constinArgument_rootPath,
                                                      const GALGAS_string constinArgument_modulePath,
                                                      C_Compiler * /* inCompiler */
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlContext * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlContext) ;
  GALGAS_string var_normalizedModulePath_1564 = constinArgument_modulePath.getter_absolutePathFromPath (constinArgument_rootPath COMMA_SOURCE_FILE ("gtl_types.galgas", 61)).getter_stringByStandardizingPath (SOURCE_FILE ("gtl_types.galgas", 61)) ;
  object->mProperty_importPath.addAssign_operation (var_normalizedModulePath_1564  COMMA_SOURCE_FILE ("gtl_types.galgas", 62)) ;
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_gtlContext_addModulePath (void) {
  enterExtensionSetter_addModulePath (kTypeDescriptor_GALGAS_gtlContext.mSlotID,
                                      extensionSetter_gtlContext_addModulePath) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionModifier_gtlContext_addModulePath (void) {
  gExtensionModifierTable_gtlContext_addModulePath.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_gtlContext_addModulePath (defineExtensionSetter_gtlContext_addModulePath,
                                                     freeExtensionModifier_gtlContext_addModulePath) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Extension setter '@gtlContext addInputVariable'                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionSetterSignature_gtlContext_addInputVariable> gExtensionModifierTable_gtlContext_addInputVariable ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_addInputVariable (const int32_t inClassIndex,
                                            extensionSetterSignature_gtlContext_addInputVariable inModifier) {
  gExtensionModifierTable_gtlContext_addInputVariable.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_addInputVariable (cPtr_gtlContext * inObject,
                                           GALGAS_gtlData in_inputVariable,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_gtlContext_addInputVariable f = NULL ;
    if (classIndex < gExtensionModifierTable_gtlContext_addInputVariable.count ()) {
      f = gExtensionModifierTable_gtlContext_addInputVariable (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_gtlContext_addInputVariable.count ()) {
           f = gExtensionModifierTable_gtlContext_addInputVariable (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_gtlContext_addInputVariable.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, in_inputVariable, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_gtlContext_addInputVariable (cPtr_gtlContext * inObject,
                                                         GALGAS_gtlData inArgument_inputVariable,
                                                         C_Compiler * /* inCompiler */
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlContext * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlContext) ;
  object->mProperty_inputVars.addAssign_operation (inArgument_inputVariable  COMMA_SOURCE_FILE ("gtl_types.galgas", 68)) ;
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_gtlContext_addInputVariable (void) {
  enterExtensionSetter_addInputVariable (kTypeDescriptor_GALGAS_gtlContext.mSlotID,
                                         extensionSetter_gtlContext_addInputVariable) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionModifier_gtlContext_addInputVariable (void) {
  gExtensionModifierTable_gtlContext_addInputVariable.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_gtlContext_addInputVariable (defineExtensionSetter_gtlContext_addInputVariable,
                                                        freeExtensionModifier_gtlContext_addInputVariable) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Extension setter '@gtlContext popFirstInputArg'                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionSetterSignature_gtlContext_popFirstInputArg> gExtensionModifierTable_gtlContext_popFirstInputArg ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_popFirstInputArg (const int32_t inClassIndex,
                                            extensionSetterSignature_gtlContext_popFirstInputArg inModifier) {
  gExtensionModifierTable_gtlContext_popFirstInputArg.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_popFirstInputArg (cPtr_gtlContext * inObject,
                                           GALGAS_location in_where,
                                           GALGAS_gtlData & out_result,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) {
//--- Drop output arguments
  out_result.drop () ;
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_gtlContext_popFirstInputArg f = NULL ;
    if (classIndex < gExtensionModifierTable_gtlContext_popFirstInputArg.count ()) {
      f = gExtensionModifierTable_gtlContext_popFirstInputArg (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_gtlContext_popFirstInputArg.count ()) {
           f = gExtensionModifierTable_gtlContext_popFirstInputArg (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_gtlContext_popFirstInputArg.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, in_where, out_result, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_gtlContext_popFirstInputArg (cPtr_gtlContext * inObject,
                                                         GALGAS_location inArgument_where,
                                                         GALGAS_gtlData & outArgument_result,
                                                         C_Compiler * inCompiler
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlContext * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlContext) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsStrictSup, object->mProperty_inputVars.getter_length (SOURCE_FILE ("gtl_types.galgas", 75)).objectCompare (GALGAS_uint ((uint32_t) 0U))).boolEnum () ;
  if (kBoolTrue == test_0) {
    {
    object->mProperty_inputVars.setter_popFirst (outArgument_result, inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 76)) ;
    }
  }else if (kBoolFalse == test_0) {
    TC_Array <C_FixItDescription> fixItArray1 ;
    inCompiler->emitSemanticError (inArgument_where, GALGAS_string ("No input argument available"), fixItArray1  COMMA_SOURCE_FILE ("gtl_types.galgas", 78)) ;
    outArgument_result.drop () ; // Release error dropped variable
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_gtlContext_popFirstInputArg (void) {
  enterExtensionSetter_popFirstInputArg (kTypeDescriptor_GALGAS_gtlContext.mSlotID,
                                         extensionSetter_gtlContext_popFirstInputArg) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionModifier_gtlContext_popFirstInputArg (void) {
  gExtensionModifierTable_gtlContext_popFirstInputArg.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_gtlContext_popFirstInputArg (defineExtensionSetter_gtlContext_popFirstInputArg,
                                                        freeExtensionModifier_gtlContext_popFirstInputArg) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Extension getter '@gtlContext fullPrefix'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlContext_fullPrefix> gExtensionGetterTable_gtlContext_fullPrefix ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_fullPrefix (const int32_t inClassIndex,
                                      enterExtensionGetter_gtlContext_fullPrefix inGetter) {
  gExtensionGetterTable_gtlContext_fullPrefix.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring callExtensionGetter_fullPrefix (const cPtr_gtlContext * inObject,
                                               const GALGAS_gtlData in_vars,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) {
  GALGAS_lstring result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlContext_fullPrefix f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlContext_fullPrefix.count ()) {
      f = gExtensionGetterTable_gtlContext_fullPrefix (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlContext_fullPrefix.count ()) {
           f = gExtensionGetterTable_gtlContext_fullPrefix (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlContext_fullPrefix.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_vars, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_lstring extensionGetter_gtlContext_fullPrefix (const cPtr_gtlContext * inObject,
                                                             const GALGAS_gtlData /* constinArgument_vars */,
                                                             C_Compiler * /* inCompiler */
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring result_full ; // Returned variable
  const cPtr_gtlContext * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlContext) ;
  result_full = object->mProperty_prefix ;
//---
  return result_full ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlContext_fullPrefix (void) {
  enterExtensionGetter_fullPrefix (kTypeDescriptor_GALGAS_gtlContext.mSlotID,
                                   extensionGetter_gtlContext_fullPrefix) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlContext_fullPrefix (void) {
  gExtensionGetterTable_gtlContext_fullPrefix.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlContext_fullPrefix (defineExtensionGetter_gtlContext_fullPrefix,
                                                  freeExtensionGetter_gtlContext_fullPrefix) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Extension getter '@gtlContext fullTemplateFileName'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlContext_fullTemplateFileName> gExtensionGetterTable_gtlContext_fullTemplateFileName ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_fullTemplateFileName (const int32_t inClassIndex,
                                                enterExtensionGetter_gtlContext_fullTemplateFileName inGetter) {
  gExtensionGetterTable_gtlContext_fullTemplateFileName.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_lstring callExtensionGetter_fullTemplateFileName (const cPtr_gtlContext * inObject,
                                                         GALGAS_gtlContext in_context,
                                                         GALGAS_gtlData in_vars,
                                                         GALGAS_lstring in_simpleName,
                                                         C_Compiler * inCompiler
                                                         COMMA_LOCATION_ARGS) {
  GALGAS_lstring result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlContext_fullTemplateFileName f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlContext_fullTemplateFileName.count ()) {
      f = gExtensionGetterTable_gtlContext_fullTemplateFileName (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlContext_fullTemplateFileName.count ()) {
           f = gExtensionGetterTable_gtlContext_fullTemplateFileName (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlContext_fullTemplateFileName.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_context, in_vars, in_simpleName, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_lstring extensionGetter_gtlContext_fullTemplateFileName (const cPtr_gtlContext * inObject,
                                                                       GALGAS_gtlContext inArgument_context,
                                                                       GALGAS_gtlData inArgument_vars,
                                                                       GALGAS_lstring inArgument_simpleName,
                                                                       C_Compiler * inCompiler
                                                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_lstring result_fullName ; // Returned variable
  const cPtr_gtlContext * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlContext) ;
  const GALGAS_gtlContext temp_0 = object ;
  GALGAS_gtlContext var_copy_2504 = temp_0 ;
  const GALGAS_gtlContext temp_1 = object ;
  GALGAS_lstring var_fullPref_2531 = callExtensionGetter_fullPrefix ((const cPtr_gtlContext *) temp_1.ptr (), inArgument_vars, inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 108)) ;
  GALGAS_string var_prefixedTemplatePath_2588 = extensionGetter_stringByAppendingPath (object->mProperty_templateDirectory, var_fullPref_2531.getter_string (SOURCE_FILE ("gtl_types.galgas", 110)), inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 110)) ;
  GALGAS_string var_hierarchicalPath_2676 = object->mProperty_path ;
  GALGAS_string var_rootPath_2702 = function_pathWithExtension (inArgument_context, extensionGetter_stringByAppendingPath (var_prefixedTemplatePath_2588, inArgument_simpleName.getter_string (SOURCE_FILE ("gtl_types.galgas", 114)), inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 114)), inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 112)) ;
  GALGAS_bool var_found_2828 = GALGAS_bool (false) ;
  if (var_hierarchicalPath_2676.getter_length (SOURCE_FILE ("gtl_types.galgas", 119)).isValid ()) {
    uint32_t variant_2844 = var_hierarchicalPath_2676.getter_length (SOURCE_FILE ("gtl_types.galgas", 119)).uintValue () ;
    bool loop_2844 = true ;
    while (loop_2844) {
      GALGAS_bool test_2 = var_found_2828.operator_not (SOURCE_FILE ("gtl_types.galgas", 120)) ;
      if (kBoolTrue == test_2.boolEnum ()) {
        test_2 = GALGAS_bool (kIsStrictSup, var_hierarchicalPath_2676.getter_length (SOURCE_FILE ("gtl_types.galgas", 120)).objectCompare (GALGAS_uint ((uint32_t) 0U))) ;
      }
      loop_2844 = test_2.isValid () ;
      if (loop_2844) {
        loop_2844 = test_2.boolValue () ;
      }
      if (loop_2844 && (0 == variant_2844)) {
        loop_2844 = false ;
        inCompiler->loopRunTimeVariantError (SOURCE_FILE ("gtl_types.galgas", 119)) ;
      }
      if (loop_2844) {
        variant_2844 -- ;
        GALGAS_string var_fullPath_2949 = function_pathWithExtension (inArgument_context, extensionGetter_stringByAppendingPath (extensionGetter_stringByAppendingPath (var_prefixedTemplatePath_2588, var_hierarchicalPath_2676, inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 123)), inArgument_simpleName.getter_string (SOURCE_FILE ("gtl_types.galgas", 124)), inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 123)), inCompiler COMMA_SOURCE_FILE ("gtl_types.galgas", 121)) ;
        const enumGalgasBool test_3 = var_fullPath_2949.getter_fileExists (SOURCE_FILE ("gtl_types.galgas", 128)).boolEnum () ;
        if (kBoolTrue == test_3) {
          var_rootPath_2702 = var_fullPath_2949 ;
          var_found_2828 = GALGAS_bool (true) ;
        }
        var_hierarchicalPath_2676 = var_hierarchicalPath_2676.getter_stringByDeletingLastPathComponent (SOURCE_FILE ("gtl_types.galgas", 135)) ;
      }
    }
  }
  result_fullName = GALGAS_lstring::constructor_new (var_rootPath_2702, inArgument_simpleName.getter_location (SOURCE_FILE ("gtl_types.galgas", 140))  COMMA_SOURCE_FILE ("gtl_types.galgas", 138)) ;
//---
  return result_fullName ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlContext_fullTemplateFileName (void) {
  enterExtensionGetter_fullTemplateFileName (kTypeDescriptor_GALGAS_gtlContext.mSlotID,
                                             extensionGetter_gtlContext_fullTemplateFileName) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlContext_fullTemplateFileName (void) {
  gExtensionGetterTable_gtlContext_fullTemplateFileName.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlContext_fullTemplateFileName (defineExtensionGetter_gtlContext_fullTemplateFileName,
                                                            freeExtensionGetter_gtlContext_fullTemplateFileName) ;



//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_module_5F_parser::rule_gtl_5F_module_5F_parser_gtl_5F_instruction_5F_list_i0_ (GALGAS_gtlInstructionList & outArgument_instructionList,
                                                                                                   C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instructionList.drop () ; // Release 'out' argument
  outArgument_instructionList = GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_module_parser.galgas", 48)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_gtl_5F_module_5F_parser_0 (inCompiler)) {
    case 2: {
      GALGAS_gtlInstruction var_instruction_1351 ;
      nt_gtl_5F_instruction_ (var_instruction_1351, inCompiler) ;
      outArgument_instructionList.addAssign_operation (var_instruction_1351  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 53)) ;
      GALGAS_string var_templateString_1414 = GALGAS_string::constructor_retrieveAndResetTemplateString (inCompiler  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 54)) ;
    } break ;
    case 3: {
      GALGAS_gtlInstruction var_instruction_1521 ;
      nt_gtl_5F_simple_5F_instruction_ (var_instruction_1521, inCompiler) ;
      outArgument_instructionList.addAssign_operation (var_instruction_1521  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 57)) ;
      GALGAS_string var_templateString_1584 = GALGAS_string::constructor_retrieveAndResetTemplateString (inCompiler  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 58)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_module_5F_parser::rule_gtl_5F_module_5F_parser_gtl_5F_instruction_5F_list_i0_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_gtl_5F_module_5F_parser_0 (inCompiler)) {
    case 2: {
      nt_gtl_5F_instruction_parse (inCompiler) ;
    } break ;
    case 3: {
      nt_gtl_5F_simple_5F_instruction_parse (inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_module_5F_parser::rule_gtl_5F_module_5F_parser_gtl_5F_module_5F_start_5F_symbol_i1_ (GALGAS_gtlContext inArgument_context,
                                                                                                         GALGAS_library & ioArgument_lib,
                                                                                                         C_Lexique_gtl_5F_scanner * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_gtl_5F_module_5F_parser_1 (inCompiler)) {
    case 2: {
      nt_gtl_5F_import_ (inArgument_context, ioArgument_lib, inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  bool repeatFlag_1 = true ;
  while (repeatFlag_1) {
    switch (select_gtl_5F_module_5F_parser_2 (inCompiler)) {
    case 2: {
      GALGAS_gtlFunction var_aFunction_2010 ;
      nt_gtl_5F_function_ (var_aFunction_2010, inCompiler) ;
      {
      ioArgument_lib.insulate (HERE) ;
      cPtr_library * ptr_2021 = (cPtr_library *) ioArgument_lib.ptr () ;
      callExtensionSetter_putFunction ((cPtr_library *) ptr_2021, var_aFunction_2010.getter_name (SOURCE_FILE ("gtl_module_parser.galgas", 77)), var_aFunction_2010, inCompiler COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 77)) ;
      }
    } break ;
    case 3: {
      GALGAS_gtlGetter var_aGetter_2108 ;
      nt_gtl_5F_getter_ (var_aGetter_2108, inCompiler) ;
      {
      ioArgument_lib.insulate (HERE) ;
      cPtr_library * ptr_2119 = (cPtr_library *) ioArgument_lib.ptr () ;
      callExtensionSetter_putGetter ((cPtr_library *) ptr_2119, callExtensionGetter_typedName ((const cPtr_gtlGetter *) var_aGetter_2108.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 80)), var_aGetter_2108, inCompiler COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 80)) ;
      }
    } break ;
    case 4: {
      GALGAS_gtlSetter var_aSetter_2205 ;
      nt_gtl_5F_setter_ (var_aSetter_2205, inCompiler) ;
      {
      ioArgument_lib.insulate (HERE) ;
      cPtr_library * ptr_2216 = (cPtr_library *) ioArgument_lib.ptr () ;
      callExtensionSetter_putSetter ((cPtr_library *) ptr_2216, callExtensionGetter_typedName ((const cPtr_gtlSetter *) var_aSetter_2205.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 83)), var_aSetter_2205, inCompiler COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 83)) ;
      }
    } break ;
    default:
      repeatFlag_1 = false ;
      break ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_module_5F_parser::rule_gtl_5F_module_5F_parser_gtl_5F_module_5F_start_5F_symbol_i1_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_gtl_5F_module_5F_parser_1 (inCompiler)) {
    case 2: {
      nt_gtl_5F_import_parse (inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  bool repeatFlag_1 = true ;
  while (repeatFlag_1) {
    switch (select_gtl_5F_module_5F_parser_2 (inCompiler)) {
    case 2: {
      nt_gtl_5F_function_parse (inCompiler) ;
    } break ;
    case 3: {
      nt_gtl_5F_getter_parse (inCompiler) ;
    } break ;
    case 4: {
      nt_gtl_5F_setter_parse (inCompiler) ;
    } break ;
    default:
      repeatFlag_1 = false ;
      break ;
    }
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_module_5F_parser::rule_gtl_5F_module_5F_parser_gtl_5F_function_i2_ (GALGAS_gtlFunction & outArgument_function,
                                                                                        C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_function.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_func) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 93)) ;
  GALGAS_lstring var_functionName_2546 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 94)) ;
  GALGAS_location var_where_2564 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 95)) ;
  GALGAS_gtlArgumentList var_arguments_2622 ;
  nt_gtl_5F_argument_5F_list_ (var_arguments_2622, inCompiler) ;
  GALGAS_lstring var_returnVariable_2666 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 97)) ;
  GALGAS_gtlInstructionList var_instructionList_2732 ;
  nt_gtl_5F_instruction_5F_list_ (var_instructionList_2732, inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 99)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_func) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 99)) ;
  outArgument_function = GALGAS_gtlFunction::constructor_new (var_where_2564, var_functionName_2546, var_arguments_2622, var_instructionList_2732, var_returnVariable_2666  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 101)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_module_5F_parser::rule_gtl_5F_module_5F_parser_gtl_5F_function_i2_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_func) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 93)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 94)) ;
  nt_gtl_5F_argument_5F_list_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 97)) ;
  nt_gtl_5F_instruction_5F_list_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 99)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_func) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 99)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_module_5F_parser::rule_gtl_5F_module_5F_parser_gtl_5F_getter_i3_ (GALGAS_gtlGetter & outArgument_aGetter,
                                                                                      C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_aGetter.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_getter) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 112)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__40_) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 113)) ;
  GALGAS_lstring var_targetType_3123 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 113)) ;
  GALGAS_lstring var_getterName_3163 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 114)) ;
  GALGAS_location var_where_3181 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 115)) ;
  GALGAS_gtlArgumentList var_arguments_3239 ;
  nt_gtl_5F_argument_5F_list_ (var_arguments_3239, inCompiler) ;
  GALGAS_lstring var_returnVariable_3283 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 117)) ;
  GALGAS_gtlInstructionList var_instructionList_3349 ;
  nt_gtl_5F_instruction_5F_list_ (var_instructionList_3349, inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 119)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_getter) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 119)) ;
  outArgument_aGetter = GALGAS_gtlGetter::constructor_new (var_where_3181, var_getterName_3163, var_arguments_3239, var_instructionList_3349, var_returnVariable_3283, extensionGetter_gtlType (var_targetType_3123, inCompiler COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 127))  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 121)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_module_5F_parser::rule_gtl_5F_module_5F_parser_gtl_5F_getter_i3_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_getter) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 112)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__40_) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 113)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 113)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 114)) ;
  nt_gtl_5F_argument_5F_list_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 117)) ;
  nt_gtl_5F_instruction_5F_list_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 119)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_getter) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 119)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_module_5F_parser::rule_gtl_5F_module_5F_parser_gtl_5F_setter_i4_ (GALGAS_gtlSetter & outArgument_aSetter,
                                                                                      C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_aSetter.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_setter) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 137)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__40_) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 138)) ;
  GALGAS_lstring var_targetType_3781 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 138)) ;
  GALGAS_lstring var_getterName_3821 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 139)) ;
  GALGAS_location var_where_3839 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 140)) ;
  GALGAS_gtlArgumentList var_arguments_3897 ;
  nt_gtl_5F_argument_5F_list_ (var_arguments_3897, inCompiler) ;
  GALGAS_gtlInstructionList var_instructionList_3963 ;
  nt_gtl_5F_instruction_5F_list_ (var_instructionList_3963, inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 143)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_setter) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 143)) ;
  outArgument_aSetter = GALGAS_gtlSetter::constructor_new (var_where_3839, var_getterName_3821, var_arguments_3897, var_instructionList_3963, extensionGetter_gtlType (var_targetType_3781, inCompiler COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 150))  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 145)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_module_5F_parser::rule_gtl_5F_module_5F_parser_gtl_5F_setter_i4_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_setter) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 137)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__40_) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 138)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 138)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 139)) ;
  nt_gtl_5F_argument_5F_list_parse (inCompiler) ;
  nt_gtl_5F_instruction_5F_list_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 143)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_setter) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 143)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_module_5F_parser::rule_gtl_5F_module_5F_parser_gtl_5F_instruction_i5_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                           C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  GALGAS_gtlThenElsifStatementList var_thenElsifList_4416 = GALGAS_gtlThenElsifStatementList::constructor_emptyList (SOURCE_FILE ("gtl_module_parser.galgas", 160)) ;
  GALGAS_gtlInstructionList var_elseList_4460 = GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_module_parser.galgas", 161)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_if) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 163)) ;
  GALGAS_location var_where_4499 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 163)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    GALGAS_gtlExpression var_condition_4563 ;
    nt_gtl_5F_expression_ (var_condition_4563, inCompiler) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_then) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 166)) ;
    GALGAS_gtlInstructionList var_instructionList_4638 ;
    nt_gtl_5F_instruction_5F_list_ (var_instructionList_4638, inCompiler) ;
    var_thenElsifList_4416.addAssign_operation (var_condition_4563, var_instructionList_4638  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 169)) ;
    switch (select_gtl_5F_module_5F_parser_3 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_elsif) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 171)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  switch (select_gtl_5F_module_5F_parser_4 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_else) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 175)) ;
    nt_gtl_5F_instruction_5F_list_ (var_elseList_4460, inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 179)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_if) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 180)) ;
  outArgument_instruction = GALGAS_gtlIfStatementInstruction::constructor_new (var_where_4499, function_signature (var_where_4499, inCompiler COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 183)), var_thenElsifList_4416, var_elseList_4460  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 182)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_module_5F_parser::rule_gtl_5F_module_5F_parser_gtl_5F_instruction_i5_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_if) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 163)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    nt_gtl_5F_expression_parse (inCompiler) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_then) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 166)) ;
    nt_gtl_5F_instruction_5F_list_parse (inCompiler) ;
    switch (select_gtl_5F_module_5F_parser_3 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_elsif) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 171)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  switch (select_gtl_5F_module_5F_parser_4 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_else) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 175)) ;
    nt_gtl_5F_instruction_5F_list_parse (inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 179)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_if) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 180)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_module_5F_parser::rule_gtl_5F_module_5F_parser_gtl_5F_instruction_i6_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                           C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  GALGAS_gtlInstructionList var_beforeList_5211 = GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_module_parser.galgas", 193)) ;
  GALGAS_gtlInstructionList var_doList_5253 = GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_module_parser.galgas", 194)) ;
  GALGAS_gtlInstructionList var_betweenList_5300 = GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_module_parser.galgas", 195)) ;
  GALGAS_gtlInstructionList var_afterList_5345 = GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_module_parser.galgas", 196)) ;
  GALGAS_lstring var_indexName_5379 ;
  GALGAS_lstring var_variableName_5403 ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_foreach) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 200)) ;
  GALGAS_location var_where_5432 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 200)) ;
  GALGAS_lstring var_keyName_5477 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 201)) ;
  switch (select_gtl_5F_module_5F_parser_5 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 203)) ;
    var_variableName_5403 = inCompiler->synthetizedAttribute_tokenString () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 203)) ;
  } break ;
  case 2: {
    var_variableName_5403 = var_keyName_5477 ;
    var_keyName_5477 = GALGAS_lstring::constructor_new (GALGAS_string::makeEmptyString (), var_where_5432  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 206)) ;
  } break ;
  default:
    break ;
  }
  switch (select_gtl_5F_module_5F_parser_6 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__28_) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 209)) ;
    var_indexName_5379 = inCompiler->synthetizedAttribute_tokenString () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 209)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__29_) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 209)) ;
  } break ;
  case 2: {
    var_indexName_5379 = GALGAS_lstring::constructor_new (GALGAS_string ("INDEX"), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 211))  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 211)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_in) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 213)) ;
  GALGAS_gtlExpression var_iterable_5741 ;
  nt_gtl_5F_expression_ (var_iterable_5741, inCompiler) ;
  switch (select_gtl_5F_module_5F_parser_7 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_before) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 217)) ;
    nt_gtl_5F_instruction_5F_list_ (var_beforeList_5211, inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_do) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 221)) ;
  nt_gtl_5F_instruction_5F_list_ (var_doList_5253, inCompiler) ;
  switch (select_gtl_5F_module_5F_parser_8 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_between) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 225)) ;
    nt_gtl_5F_instruction_5F_list_ (var_betweenList_5300, inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  switch (select_gtl_5F_module_5F_parser_9 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_after) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 230)) ;
    nt_gtl_5F_instruction_5F_list_ (var_afterList_5345, inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 234)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_foreach) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 235)) ;
  outArgument_instruction = GALGAS_gtlForeachStatementInstruction::constructor_new (var_where_5432, function_signature (var_where_5432, inCompiler COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 239)), var_keyName_5477, var_variableName_5403, var_indexName_5379, var_iterable_5741, var_beforeList_5211, var_betweenList_5300, var_afterList_5345, var_doList_5253  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 237)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_module_5F_parser::rule_gtl_5F_module_5F_parser_gtl_5F_instruction_i6_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_foreach) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 200)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 201)) ;
  switch (select_gtl_5F_module_5F_parser_5 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 203)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 203)) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  switch (select_gtl_5F_module_5F_parser_6 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__28_) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 209)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 209)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__29_) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 209)) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_in) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 213)) ;
  nt_gtl_5F_expression_parse (inCompiler) ;
  switch (select_gtl_5F_module_5F_parser_7 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_before) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 217)) ;
    nt_gtl_5F_instruction_5F_list_parse (inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_do) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 221)) ;
  nt_gtl_5F_instruction_5F_list_parse (inCompiler) ;
  switch (select_gtl_5F_module_5F_parser_8 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_between) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 225)) ;
    nt_gtl_5F_instruction_5F_list_parse (inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  switch (select_gtl_5F_module_5F_parser_9 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_after) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 230)) ;
    nt_gtl_5F_instruction_5F_list_parse (inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 234)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_foreach) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 235)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_module_5F_parser::rule_gtl_5F_module_5F_parser_gtl_5F_instruction_i7_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                           C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  GALGAS_gtlInstructionList var_doList_6582 = GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_module_parser.galgas", 257)) ;
  GALGAS_gtlInstructionList var_betweenList_6629 = GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_module_parser.galgas", 258)) ;
  GALGAS_gtlExpressionList var_iterable_6673 = GALGAS_gtlExpressionList::constructor_emptyList (SOURCE_FILE ("gtl_module_parser.galgas", 259)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_for) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 261)) ;
  GALGAS_location var_where_6712 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 261)) ;
  const enumGalgasBool test_0 = GALGAS_bool (gOption_gtl_5F_options_warnDeprecated.getter_value ()).boolEnum () ;
  if (kBoolTrue == test_0) {
    TC_Array <C_FixItDescription> fixItArray1 ;
    appendFixItActions (fixItArray1, kFixItReplace, GALGAS_string ("foreach var in @( expression, ..., expression )")) ;
    inCompiler->emitSemanticWarning (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 263)), GALGAS_string ("for var in expression, ..., expression is deprecated"), fixItArray1  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 263)) ;
  }
  GALGAS_lstring var_variableName_6969 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 266)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_in) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 267)) ;
  bool repeatFlag_2 = true ;
  while (repeatFlag_2) {
    GALGAS_gtlExpression var_expression_7033 ;
    nt_gtl_5F_expression_ (var_expression_7033, inCompiler) ;
    var_iterable_6673.addAssign_operation (var_expression_7033  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 270)) ;
    switch (select_gtl_5F_module_5F_parser_10 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 272)) ;
    } break ;
    default:
      repeatFlag_2 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_do) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 275)) ;
  nt_gtl_5F_instruction_5F_list_ (var_doList_6582, inCompiler) ;
  switch (select_gtl_5F_module_5F_parser_11 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_between) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 279)) ;
    nt_gtl_5F_instruction_5F_list_ (var_betweenList_6629, inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 283)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_for) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 284)) ;
  outArgument_instruction = GALGAS_gtlForStatementInstruction::constructor_new (var_where_6712, function_signature (var_where_6712, inCompiler COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 287)), var_variableName_6969, var_iterable_6673, var_betweenList_6629, var_doList_6582  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 286)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_module_5F_parser::rule_gtl_5F_module_5F_parser_gtl_5F_instruction_i7_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_for) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 261)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 266)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_in) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 267)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    nt_gtl_5F_expression_parse (inCompiler) ;
    switch (select_gtl_5F_module_5F_parser_10 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 272)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_do) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 275)) ;
  nt_gtl_5F_instruction_5F_list_parse (inCompiler) ;
  switch (select_gtl_5F_module_5F_parser_11 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_between) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 279)) ;
    nt_gtl_5F_instruction_5F_list_parse (inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 283)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_for) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 284)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_module_5F_parser::rule_gtl_5F_module_5F_parser_gtl_5F_instruction_i8_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                           C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  GALGAS_gtlInstructionList var_beforeList_7664 = GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_module_parser.galgas", 297)) ;
  GALGAS_gtlInstructionList var_betweenList_7711 = GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_module_parser.galgas", 298)) ;
  GALGAS_gtlInstructionList var_afterList_7756 = GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_module_parser.galgas", 299)) ;
  GALGAS_sint_36__34_ var_direction_7789 = GALGAS_sint_36__34_ ((int64_t) 1LL) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_loop) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 302)) ;
  GALGAS_location var_where_7823 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 302)) ;
  GALGAS_gtlExpression var_step_7854 = GALGAS_gtlTerminal::constructor_new (var_where_7823, GALGAS_gtlInt::constructor_new (var_where_7823, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 305)), GALGAS_bigint ("1", inCompiler  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 305))  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 305))  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 304)) ;
  GALGAS_lstring var_variableName_7979 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 308)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_from) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 309)) ;
  GALGAS_gtlExpression var_start_8029 ;
  nt_gtl_5F_expression_ (var_start_8029, inCompiler) ;
  switch (select_gtl_5F_module_5F_parser_12 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_up) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 313)) ;
  } break ;
  case 3: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_down) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 315)) ;
    var_direction_7789 = GALGAS_sint_36__34_ ((int64_t) 1LL).operator_unary_minus (inCompiler COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 315)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_to) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 317)) ;
  GALGAS_gtlExpression var_stop_8139 ;
  nt_gtl_5F_expression_ (var_stop_8139, inCompiler) ;
  switch (select_gtl_5F_module_5F_parser_13 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_step) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 320)) ;
    nt_gtl_5F_expression_ (var_step_7854, inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  switch (select_gtl_5F_module_5F_parser_14 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_before) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 325)) ;
    nt_gtl_5F_instruction_5F_list_ (var_beforeList_7664, inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_do) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 329)) ;
  GALGAS_gtlInstructionList var_doList_8357 ;
  nt_gtl_5F_instruction_5F_list_ (var_doList_8357, inCompiler) ;
  switch (select_gtl_5F_module_5F_parser_15 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_between) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 333)) ;
    nt_gtl_5F_instruction_5F_list_ (var_betweenList_7711, inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  switch (select_gtl_5F_module_5F_parser_16 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_after) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 338)) ;
    nt_gtl_5F_instruction_5F_list_ (var_afterList_7756, inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 342)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_loop) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 343)) ;
  outArgument_instruction = GALGAS_gtlLoopStatementInstruction::constructor_new (var_where_7823, function_signature (var_where_7823, inCompiler COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 346)), var_variableName_7979, var_start_8029, var_stop_8139, var_step_7854, var_direction_7789, var_beforeList_7664, var_betweenList_7711, var_afterList_7756, var_doList_8357  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 345)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_module_5F_parser::rule_gtl_5F_module_5F_parser_gtl_5F_instruction_i8_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_loop) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 302)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 308)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_from) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 309)) ;
  nt_gtl_5F_expression_parse (inCompiler) ;
  switch (select_gtl_5F_module_5F_parser_12 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_up) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 313)) ;
  } break ;
  case 3: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_down) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 315)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_to) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 317)) ;
  nt_gtl_5F_expression_parse (inCompiler) ;
  switch (select_gtl_5F_module_5F_parser_13 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_step) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 320)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  switch (select_gtl_5F_module_5F_parser_14 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_before) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 325)) ;
    nt_gtl_5F_instruction_5F_list_parse (inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_do) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 329)) ;
  nt_gtl_5F_instruction_5F_list_parse (inCompiler) ;
  switch (select_gtl_5F_module_5F_parser_15 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_between) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 333)) ;
    nt_gtl_5F_instruction_5F_list_parse (inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  switch (select_gtl_5F_module_5F_parser_16 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_after) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 338)) ;
    nt_gtl_5F_instruction_5F_list_parse (inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 342)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_loop) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 343)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_module_5F_parser::rule_gtl_5F_module_5F_parser_gtl_5F_instruction_i9_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                           C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  GALGAS_gtlExpression var_limit_9009 ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_repeat) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 359)) ;
  GALGAS_location var_where_9039 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 359)) ;
  switch (select_gtl_5F_module_5F_parser_17 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__28_) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 361)) ;
    nt_gtl_5F_expression_ (var_limit_9009, inCompiler) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__29_) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 363)) ;
  } break ;
  case 2: {
    var_limit_9009 = GALGAS_gtlTerminal::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 366)), GALGAS_gtlInt::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 367)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 367)), GALGAS_uint::constructor_max (SOURCE_FILE ("gtl_module_parser.galgas", 367)).getter_bigint (SOURCE_FILE ("gtl_module_parser.galgas", 367))  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 367))  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 365)) ;
  } break ;
  default:
    break ;
  }
  GALGAS_gtlInstructionList var_continueList_9287 ;
  nt_gtl_5F_instruction_5F_list_ (var_continueList_9287, inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_while) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 371)) ;
  GALGAS_gtlExpression var_condition_9342 ;
  nt_gtl_5F_expression_ (var_condition_9342, inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_do) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 373)) ;
  GALGAS_gtlInstructionList var_doList_9402 ;
  nt_gtl_5F_instruction_5F_list_ (var_doList_9402, inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 375)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_repeat) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 376)) ;
  outArgument_instruction = GALGAS_gtlRepeatStatementInstruction::constructor_new (var_where_9039, function_signature (var_where_9039, inCompiler COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 379)), var_limit_9009, var_condition_9342, var_continueList_9287, var_doList_9402  COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 378)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_module_5F_parser::rule_gtl_5F_module_5F_parser_gtl_5F_instruction_i9_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_repeat) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 359)) ;
  switch (select_gtl_5F_module_5F_parser_17 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__28_) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 361)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__29_) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 363)) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  nt_gtl_5F_instruction_5F_list_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_while) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 371)) ;
  nt_gtl_5F_expression_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_do) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 373)) ;
  nt_gtl_5F_instruction_5F_list_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 375)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_repeat) COMMA_SOURCE_FILE ("gtl_module_parser.galgas", 376)) ;
  inCompiler->resetTemplateString () ;
}



//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i0_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_let) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 43)) ;
  GALGAS_location var_where_1050 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 43)) ;
  GALGAS_gtlVarPath var_variable_1097 ;
  nt_gtl_5F_variable_ (var_variable_1097, inCompiler) ;
  switch (select_gtl_5F_instruction_5F_parser_0 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A__3D_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 46)) ;
    GALGAS_gtlExpression var_expression_1163 ;
    nt_gtl_5F_expression_ (var_expression_1163, inCompiler) ;
    outArgument_instruction = GALGAS_gtlLetInstruction::constructor_new (var_where_1050, function_signature (var_where_1050, inCompiler COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 50)), var_variable_1097, var_expression_1163  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 48)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2B__3D_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 55)) ;
    GALGAS_gtlExpression var_expression_1348 ;
    nt_gtl_5F_expression_ (var_expression_1348, inCompiler) ;
    outArgument_instruction = GALGAS_gtlLetAddInstruction::constructor_new (var_where_1050, function_signature (var_where_1050, inCompiler COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 59)), var_variable_1097, var_expression_1348  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 57)) ;
  } break ;
  case 3: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2D__3D_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 64)) ;
    GALGAS_gtlExpression var_expression_1535 ;
    nt_gtl_5F_expression_ (var_expression_1535, inCompiler) ;
    outArgument_instruction = GALGAS_gtlLetSubstractInstruction::constructor_new (var_where_1050, function_signature (var_where_1050, inCompiler COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 68)), var_variable_1097, var_expression_1535  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 66)) ;
  } break ;
  case 4: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2A__3D_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 73)) ;
    GALGAS_gtlExpression var_expression_1728 ;
    nt_gtl_5F_expression_ (var_expression_1728, inCompiler) ;
    outArgument_instruction = GALGAS_gtlLetMultiplyInstruction::constructor_new (var_where_1050, function_signature (var_where_1050, inCompiler COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 77)), var_variable_1097, var_expression_1728  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 75)) ;
  } break ;
  case 5: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2F__3D_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 82)) ;
    GALGAS_gtlExpression var_expression_1920 ;
    nt_gtl_5F_expression_ (var_expression_1920, inCompiler) ;
    outArgument_instruction = GALGAS_gtlLetDivideInstruction::constructor_new (var_where_1050, function_signature (var_where_1050, inCompiler COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 86)), var_variable_1097, var_expression_1920  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 84)) ;
  } break ;
  case 6: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_mod_3D_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 91)) ;
    GALGAS_gtlExpression var_expression_2112 ;
    nt_gtl_5F_expression_ (var_expression_2112, inCompiler) ;
    outArgument_instruction = GALGAS_gtlLetModuloInstruction::constructor_new (var_where_1050, function_signature (var_where_1050, inCompiler COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 95)), var_variable_1097, var_expression_2112  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 93)) ;
  } break ;
  case 7: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3C__3C__3D_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 100)) ;
    GALGAS_gtlExpression var_expression_2303 ;
    nt_gtl_5F_expression_ (var_expression_2303, inCompiler) ;
    outArgument_instruction = GALGAS_gtlLetShiftLeftInstruction::constructor_new (var_where_1050, function_signature (var_where_1050, inCompiler COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 104)), var_variable_1097, var_expression_2303  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 102)) ;
  } break ;
  case 8: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3E__3E__3D_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 109)) ;
    GALGAS_gtlExpression var_expression_2497 ;
    nt_gtl_5F_expression_ (var_expression_2497, inCompiler) ;
    outArgument_instruction = GALGAS_gtlLetShiftRightInstruction::constructor_new (var_where_1050, function_signature (var_where_1050, inCompiler COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 113)), var_variable_1097, var_expression_2497  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 111)) ;
  } break ;
  case 9: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__26__3D_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 118)) ;
    GALGAS_gtlExpression var_expression_2691 ;
    nt_gtl_5F_expression_ (var_expression_2691, inCompiler) ;
    outArgument_instruction = GALGAS_gtlLetAndInstruction::constructor_new (var_where_1050, function_signature (var_where_1050, inCompiler COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 122)), var_variable_1097, var_expression_2691  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 120)) ;
  } break ;
  case 10: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__7C__3D_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 127)) ;
    GALGAS_gtlExpression var_expression_2878 ;
    nt_gtl_5F_expression_ (var_expression_2878, inCompiler) ;
    outArgument_instruction = GALGAS_gtlLetOrInstruction::constructor_new (var_where_1050, function_signature (var_where_1050, inCompiler COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 131)), var_variable_1097, var_expression_2878  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 129)) ;
  } break ;
  case 11: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5E__3D_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 136)) ;
    GALGAS_gtlExpression var_expression_3064 ;
    nt_gtl_5F_expression_ (var_expression_3064, inCompiler) ;
    outArgument_instruction = GALGAS_gtlLetXorInstruction::constructor_new (var_where_1050, function_signature (var_where_1050, inCompiler COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 140)), var_variable_1097, var_expression_3064  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 138)) ;
  } break ;
  case 12: {
    outArgument_instruction = GALGAS_gtlLetUnconstructedInstruction::constructor_new (var_where_1050, function_signature (var_where_1050, inCompiler COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 147)), var_variable_1097  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 145)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i0_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_let) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 43)) ;
  nt_gtl_5F_variable_parse (inCompiler) ;
  switch (select_gtl_5F_instruction_5F_parser_0 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A__3D_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 46)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2B__3D_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 55)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
  } break ;
  case 3: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2D__3D_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 64)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
  } break ;
  case 4: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2A__3D_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 73)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
  } break ;
  case 5: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2F__3D_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 82)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
  } break ;
  case 6: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_mod_3D_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 91)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
  } break ;
  case 7: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3C__3C__3D_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 100)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
  } break ;
  case 8: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3E__3E__3D_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 109)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
  } break ;
  case 9: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__26__3D_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 118)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
  } break ;
  case 10: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__7C__3D_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 127)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
  } break ;
  case 11: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5E__3D_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 136)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
  } break ;
  case 12: {
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i1_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_unlet) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 157)) ;
  GALGAS_location var_where_3487 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 157)) ;
  GALGAS_gtlVarPath var_variable_3534 ;
  nt_gtl_5F_variable_ (var_variable_3534, inCompiler) ;
  outArgument_instruction = GALGAS_gtlUnletInstruction::constructor_new (var_where_3487, function_signature (var_where_3487, inCompiler COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 161)), var_variable_3534  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 159)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i1_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_unlet) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 157)) ;
  nt_gtl_5F_variable_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i2_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_error) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 170)) ;
  GALGAS_location var_where_3801 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 170)) ;
  GALGAS_gtlVarPath var_variable_3856 ;
  GALGAS_bool var_hereInstead_3875 ;
  nt_gtl_5F_variable_5F_or_5F_here_ (var_variable_3856, var_hereInstead_3875, inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 172)) ;
  GALGAS_gtlExpression var_expression_3927 ;
  nt_gtl_5F_expression_ (var_expression_3927, inCompiler) ;
  outArgument_instruction = GALGAS_gtlErrorStatementInstruction::constructor_new (var_where_3801, function_signature (var_where_3801, inCompiler COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 177)), var_variable_3856, var_hereInstead_3875, var_expression_3927  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 175)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i2_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_error) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 170)) ;
  nt_gtl_5F_variable_5F_or_5F_here_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 172)) ;
  nt_gtl_5F_expression_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i3_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_warning) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 188)) ;
  GALGAS_location var_where_4241 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 188)) ;
  GALGAS_gtlVarPath var_variable_4296 ;
  GALGAS_bool var_hereInstead_4315 ;
  nt_gtl_5F_variable_5F_or_5F_here_ (var_variable_4296, var_hereInstead_4315, inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 190)) ;
  GALGAS_gtlExpression var_expression_4367 ;
  nt_gtl_5F_expression_ (var_expression_4367, inCompiler) ;
  outArgument_instruction = GALGAS_gtlWarningStatementInstruction::constructor_new (var_where_4241, function_signature (var_where_4241, inCompiler COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 195)), var_variable_4296, var_hereInstead_4315, var_expression_4367  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 193)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i3_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_warning) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 188)) ;
  nt_gtl_5F_variable_5F_or_5F_here_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 190)) ;
  nt_gtl_5F_expression_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i4_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_print) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 206)) ;
  GALGAS_location var_where_4679 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 206)) ;
  GALGAS_gtlExpression var_expression_4733 ;
  nt_gtl_5F_expression_ (var_expression_4733, inCompiler) ;
  outArgument_instruction = GALGAS_gtlPrintStatementInstruction::constructor_new (var_where_4679, function_signature (var_where_4679, inCompiler COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 211)), GALGAS_bool (false), var_expression_4733  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 209)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i4_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_print) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 206)) ;
  nt_gtl_5F_expression_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i5_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_println) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 221)) ;
  GALGAS_location var_where_5025 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 221)) ;
  switch (select_gtl_5F_instruction_5F_parser_1 (inCompiler)) {
  case 1: {
    GALGAS_gtlExpression var_expression_5090 ;
    nt_gtl_5F_expression_ (var_expression_5090, inCompiler) ;
    outArgument_instruction = GALGAS_gtlPrintStatementInstruction::constructor_new (var_where_5025, function_signature (var_where_5025, inCompiler COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 226)), GALGAS_bool (true), var_expression_5090  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 224)) ;
  } break ;
  case 2: {
    outArgument_instruction = GALGAS_gtlPrintStatementInstruction::constructor_new (var_where_5025, function_signature (var_where_5025, inCompiler COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 233)), GALGAS_bool (true), GALGAS_gtlTerminal::constructor_new (var_where_5025, GALGAS_gtlString::constructor_new (var_where_5025, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 235)), GALGAS_string::makeEmptyString ()  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 235))  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 235))  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 231)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i5_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_println) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 221)) ;
  switch (select_gtl_5F_instruction_5F_parser_1 (inCompiler)) {
  case 1: {
    nt_gtl_5F_expression_parse (inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i6_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_display) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 244)) ;
  GALGAS_location var_where_5600 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 244)) ;
  GALGAS_gtlVarPath var_variable_5647 ;
  nt_gtl_5F_variable_ (var_variable_5647, inCompiler) ;
  outArgument_instruction = GALGAS_gtlDisplayStatementInstruction::constructor_new (var_where_5600, function_signature (var_where_5600, inCompiler COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 249)), var_variable_5647  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 247)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i6_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_display) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 244)) ;
  nt_gtl_5F_variable_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i7_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_sort) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 258)) ;
  GALGAS_location var_where_5925 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 258)) ;
  GALGAS_gtlVarPath var_variable_5972 ;
  nt_gtl_5F_variable_ (var_variable_5972, inCompiler) ;
  switch (select_gtl_5F_instruction_5F_parser_2 (inCompiler)) {
  case 1: {
    GALGAS_sortingKeyList var_sortList_6010 = GALGAS_sortingKeyList::constructor_emptyList (SOURCE_FILE ("gtl_instruction_parser.galgas", 261)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_by) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 262)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      GALGAS_lstring var_key_6080 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 264)) ;
      GALGAS_lsint var_order_6120 ;
      nt_gtl_5F_sorting_5F_order_ (var_order_6120, inCompiler) ;
      var_sortList_6010.addAssign_operation (var_key_6080, var_order_6120  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 266)) ;
      switch (select_gtl_5F_instruction_5F_parser_3 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 267)) ;
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
    outArgument_instruction = GALGAS_gtlSortStatementStructInstruction::constructor_new (var_where_5925, function_signature (var_where_5925, inCompiler COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 271)), var_variable_5972, var_sortList_6010  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 269)) ;
  } break ;
  case 2: {
    GALGAS_lsint var_order_6356 ;
    nt_gtl_5F_sorting_5F_order_ (var_order_6356, inCompiler) ;
    outArgument_instruction = GALGAS_gtlSortStatementInstruction::constructor_new (var_where_5925, function_signature (var_where_5925, inCompiler COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 280)), var_variable_5972, var_order_6356  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 278)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i7_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_sort) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 258)) ;
  nt_gtl_5F_variable_parse (inCompiler) ;
  switch (select_gtl_5F_instruction_5F_parser_2 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_by) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 262)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 264)) ;
      nt_gtl_5F_sorting_5F_order_parse (inCompiler) ;
      switch (select_gtl_5F_instruction_5F_parser_3 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 267)) ;
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
  } break ;
  case 2: {
    nt_gtl_5F_sorting_5F_order_parse (inCompiler) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i8_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_tab) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 291)) ;
  GALGAS_location var_where_6663 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 291)) ;
  GALGAS_gtlExpression var_expression_6717 ;
  nt_gtl_5F_expression_ (var_expression_6717, inCompiler) ;
  outArgument_instruction = GALGAS_gtlTabStatementInstruction::constructor_new (var_where_6663, function_signature (var_where_6663, inCompiler COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 296)), var_expression_6717  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 294)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i8_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_tab) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 291)) ;
  nt_gtl_5F_expression_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i9_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                                               C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_variables) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 305)) ;
  GALGAS_location var_where_7002 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 305)) ;
  outArgument_instruction = GALGAS_gtlVariablesInstruction::constructor_new (var_where_7002, function_signature (var_where_7002, inCompiler COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 308)), GALGAS_bool (false)  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 306)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i9_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_variables) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 305)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i10_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                                                C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_libraries) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 317)) ;
  GALGAS_location var_where_7282 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 317)) ;
  outArgument_instruction = GALGAS_gtlLibrariesInstruction::constructor_new (var_where_7282, function_signature (var_where_7282, inCompiler COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 320))  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 318)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i10_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_libraries) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 317)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i11_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                                                C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5B__21_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 328)) ;
  GALGAS_gtlVarPath var_target_7566 ;
  nt_gtl_5F_variable_ (var_target_7566, inCompiler) ;
  GALGAS_lstring var_setterName_7606 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 330)) ;
  GALGAS_location var_where_7624 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 331)) ;
  GALGAS_gtlExpressionList var_argumentList_7666 = GALGAS_gtlExpressionList::constructor_emptyList (SOURCE_FILE ("gtl_instruction_parser.galgas", 332)) ;
  switch (select_gtl_5F_instruction_5F_parser_4 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 335)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      GALGAS_gtlExpression var_argument_7760 ;
      nt_gtl_5F_expression_ (var_argument_7760, inCompiler) ;
      var_argumentList_7666.addAssign_operation (var_argument_7760  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 338)) ;
      switch (select_gtl_5F_instruction_5F_parser_5 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 340)) ;
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5D_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 343)) ;
  outArgument_instruction = GALGAS_gtlSetterCallInstruction::constructor_new (var_where_7624, function_signature (var_where_7624, inCompiler COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 346)), var_target_7566, var_setterName_7606, var_argumentList_7666  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 344)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_simple_5F_instruction_i11_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5B__21_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 328)) ;
  nt_gtl_5F_variable_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 330)) ;
  switch (select_gtl_5F_instruction_5F_parser_4 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 335)) ;
    bool repeatFlag_0 = true ;
    while (repeatFlag_0) {
      nt_gtl_5F_expression_parse (inCompiler) ;
      switch (select_gtl_5F_instruction_5F_parser_5 (inCompiler)) {
      case 2: {
        inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 340)) ;
      } break ;
      default:
        repeatFlag_0 = false ;
        break ;
      }
    }
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__5D_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 343)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_sorting_5F_order_i12_ (GALGAS_lsint & outArgument_order,
                                                                                                           C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_order.drop () ; // Release 'out' argument
  switch (select_gtl_5F_instruction_5F_parser_6 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 358)) ;
    outArgument_order = GALGAS_lsint::constructor_new (GALGAS_sint ((int32_t) 1L).operator_unary_minus (inCompiler COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 359)), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 359))  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 359)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3C_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 361)) ;
    outArgument_order = GALGAS_lsint::constructor_new (GALGAS_sint ((int32_t) 1L), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 362))  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 362)) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_sorting_5F_order_i12_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  switch (select_gtl_5F_instruction_5F_parser_6 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3E_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 358)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3C_) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 361)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_import_i13_ (GALGAS_gtlContext inArgument_context,
                                                                                                 GALGAS_library & ioArgument_lib,
                                                                                                 C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_import) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 371)) ;
  GALGAS_lstring var_fileName_8411 = inCompiler->synthetizedAttribute_a_5F_string () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_string) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 371)) ;
  GALGAS_string var_fullName_8430 = var_fileName_8411.getter_string (SOURCE_FILE ("gtl_instruction_parser.galgas", 372)) ;
  const enumGalgasBool test_0 = GALGAS_bool (kIsNotEqual, var_fullName_8430.getter_pathExtension (SOURCE_FILE ("gtl_instruction_parser.galgas", 373)).objectCompare (GALGAS_string ("gtm"))).boolEnum () ;
  if (kBoolTrue == test_0) {
    var_fullName_8430 = var_fileName_8411.getter_string (SOURCE_FILE ("gtl_instruction_parser.galgas", 374)).add_operation (GALGAS_string (".gtm"), inCompiler COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 374)) ;
  }
  GALGAS_bool var_found_8559 = GALGAS_bool (false) ;
  const enumGalgasBool test_1 = var_fullName_8430.getter_fileExists (SOURCE_FILE ("gtl_instruction_parser.galgas", 378)).operator_not (SOURCE_FILE ("gtl_instruction_parser.galgas", 378)).boolEnum () ;
  if (kBoolTrue == test_1) {
    cEnumerator_stringlist enumerator_8669 (inArgument_context.getter_importPath (SOURCE_FILE ("gtl_instruction_parser.galgas", 380)), kENUMERATION_UP) ;
    while (enumerator_8669.hasCurrentObject ()) {
      const enumGalgasBool test_2 = var_found_8559.operator_not (SOURCE_FILE ("gtl_instruction_parser.galgas", 381)).boolEnum () ;
      if (kBoolTrue == test_2) {
        GALGAS_string var_name_8717 = extensionGetter_stringByAppendingPath (enumerator_8669.current_mValue (HERE), var_fullName_8430, inCompiler COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 382)) ;
        const enumGalgasBool test_3 = var_name_8717.getter_fileExists (SOURCE_FILE ("gtl_instruction_parser.galgas", 383)).boolEnum () ;
        if (kBoolTrue == test_3) {
          var_fullName_8430 = var_name_8717 ;
          var_found_8559 = GALGAS_bool (true) ;
        }
      }
      enumerator_8669.gotoNextObject () ;
    }
  }else if (kBoolFalse == test_1) {
    var_found_8559 = GALGAS_bool (true) ;
  }
  const enumGalgasBool test_4 = var_found_8559.boolEnum () ;
  if (kBoolTrue == test_4) {
    const enumGalgasBool test_5 = callExtensionGetter_hasImport ((const cPtr_library *) ioArgument_lib.ptr (), var_fullName_8430, inCompiler COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 394)).operator_not (SOURCE_FILE ("gtl_instruction_parser.galgas", 394)).boolEnum () ;
    if (kBoolTrue == test_5) {
      {
      ioArgument_lib.insulate (HERE) ;
      cPtr_library * ptr_8981 = (cPtr_library *) ioArgument_lib.ptr () ;
      callExtensionSetter_doImport ((cPtr_library *) ptr_8981, var_fullName_8430, inCompiler COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 395)) ;
      }
      cGrammar_gtl_5F_module_5F_grammar::_performSourceFileParsing_ (inCompiler, GALGAS_lstring::constructor_new (var_fullName_8430, var_fileName_8411.getter_location (SOURCE_FILE ("gtl_instruction_parser.galgas", 397))  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 397)), inArgument_context, ioArgument_lib  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 396)) ;
    }
  }else if (kBoolFalse == test_4) {
    TC_Array <C_FixItDescription> fixItArray6 ;
    inCompiler->emitSemanticError (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 400)), GALGAS_string ("module not found"), fixItArray6  COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 400)) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_instruction_5F_parser::rule_gtl_5F_instruction_5F_parser_gtl_5F_import_i13_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_import) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 371)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_string) COMMA_SOURCE_FILE ("gtl_instruction_parser.galgas", 371)) ;
  inCompiler->resetTemplateString () ;
}



//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_start_5F_symbol_i0_ (GALGAS_gtlContext inArgument_context,
                                                                           GALGAS_library & ioArgument_lib,
                                                                           GALGAS_gtlInstructionList & outArgument_program,
                                                                           C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_program.drop () ; // Release 'out' argument
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_gtl_5F_parser_0 (inCompiler)) {
    case 2: {
      nt_gtl_5F_import_ (inArgument_context, ioArgument_lib, inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  nt_gtl_5F_template_5F_instruction_5F_list_ (outArgument_program, inCompiler) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_start_5F_symbol_i0_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_gtl_5F_parser_0 (inCompiler)) {
    case 2: {
      nt_gtl_5F_import_parse (inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  nt_gtl_5F_template_5F_instruction_5F_list_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_template_5F_instruction_5F_list_i1_ (GALGAS_gtlInstructionList & outArgument_instructionList,
                                                                                           C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instructionList.drop () ; // Release 'out' argument
  outArgument_instructionList = GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_parser.galgas", 65)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    GALGAS_string var_templateString_1561 = GALGAS_string::constructor_retrieveAndResetTemplateString (inCompiler  COMMA_SOURCE_FILE ("gtl_parser.galgas", 68)) ;
    const enumGalgasBool test_1 = GALGAS_bool (kIsNotEqual, var_templateString_1561.objectCompare (GALGAS_string::makeEmptyString ())).boolEnum () ;
    if (kBoolTrue == test_1) {
      outArgument_instructionList.addAssign_operation (GALGAS_gtlTemplateStringInstruction::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_parser.galgas", 72)), GALGAS_string::makeEmptyString (), var_templateString_1561  COMMA_SOURCE_FILE ("gtl_parser.galgas", 71))  COMMA_SOURCE_FILE ("gtl_parser.galgas", 70)) ;
    }
    switch (select_gtl_5F_parser_1 (inCompiler)) {
    case 2: {
      GALGAS_gtlInstruction var_instruction_1848 ;
      nt_gtl_5F_template_5F_instruction_ (var_instruction_1848, inCompiler) ;
      outArgument_instructionList.addAssign_operation (var_instruction_1848  COMMA_SOURCE_FILE ("gtl_parser.galgas", 79)) ;
    } break ;
    case 3: {
      GALGAS_gtlInstruction var_instruction_1950 ;
      nt_gtl_5F_simple_5F_instruction_ (var_instruction_1950, inCompiler) ;
      outArgument_instructionList.addAssign_operation (var_instruction_1950  COMMA_SOURCE_FILE ("gtl_parser.galgas", 82)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_template_5F_instruction_5F_list_i1_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    switch (select_gtl_5F_parser_1 (inCompiler)) {
    case 2: {
      nt_gtl_5F_template_5F_instruction_parse (inCompiler) ;
    } break ;
    case 3: {
      nt_gtl_5F_simple_5F_instruction_parse (inCompiler) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i2_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                   C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__21_) COMMA_SOURCE_FILE ("gtl_parser.galgas", 92)) ;
  GALGAS_location var_where_2282 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_parser.galgas", 92)) ;
  GALGAS_gtlExpression var_expression_2336 ;
  nt_gtl_5F_expression_ (var_expression_2336, inCompiler) ;
  outArgument_instruction = GALGAS_gtlEmitInstruction::constructor_new (var_where_2282, function_signature (var_where_2282, inCompiler COMMA_SOURCE_FILE ("gtl_parser.galgas", 97)), var_expression_2336  COMMA_SOURCE_FILE ("gtl_parser.galgas", 95)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i2_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__21_) COMMA_SOURCE_FILE ("gtl_parser.galgas", 92)) ;
  nt_gtl_5F_expression_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i3_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                   C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  GALGAS_bool var_isExecutable_2770 = GALGAS_bool (false) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_write) COMMA_SOURCE_FILE ("gtl_parser.galgas", 111)) ;
  GALGAS_location var_where_2804 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_parser.galgas", 111)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_to) COMMA_SOURCE_FILE ("gtl_parser.galgas", 111)) ;
  switch (select_gtl_5F_parser_2 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_executable) COMMA_SOURCE_FILE ("gtl_parser.galgas", 112)) ;
    var_isExecutable_2770 = GALGAS_bool (true) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  GALGAS_gtlExpression var_fileName_2910 ;
  nt_gtl_5F_expression_ (var_fileName_2910, inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A_) COMMA_SOURCE_FILE ("gtl_parser.galgas", 114)) ;
  GALGAS_gtlInstructionList var_instructionList_2987 ;
  nt_gtl_5F_template_5F_instruction_5F_list_ (var_instructionList_2987, inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) COMMA_SOURCE_FILE ("gtl_parser.galgas", 116)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_write) COMMA_SOURCE_FILE ("gtl_parser.galgas", 116)) ;
  outArgument_instruction = GALGAS_gtlWriteToInstruction::constructor_new (var_where_2804, function_signature (var_where_2804, inCompiler COMMA_SOURCE_FILE ("gtl_parser.galgas", 120)), var_fileName_2910, var_isExecutable_2770, var_instructionList_2987  COMMA_SOURCE_FILE ("gtl_parser.galgas", 118)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i3_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_write) COMMA_SOURCE_FILE ("gtl_parser.galgas", 111)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_to) COMMA_SOURCE_FILE ("gtl_parser.galgas", 111)) ;
  switch (select_gtl_5F_parser_2 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_executable) COMMA_SOURCE_FILE ("gtl_parser.galgas", 112)) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  nt_gtl_5F_expression_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3A_) COMMA_SOURCE_FILE ("gtl_parser.galgas", 114)) ;
  nt_gtl_5F_template_5F_instruction_5F_list_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) COMMA_SOURCE_FILE ("gtl_parser.galgas", 116)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_write) COMMA_SOURCE_FILE ("gtl_parser.galgas", 116)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i4_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                   C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  GALGAS_lstring var_prefix_3307 ;
  GALGAS_bool var_ifExists_3324 = GALGAS_bool (false) ;
  GALGAS_gtlInstructionList var_instructionList_3370 = GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_parser.galgas", 132)) ;
  GALGAS_gtlExpression var_fileName_3409 ;
  GALGAS_gtlExpressionList var_templateArguments_3448 = GALGAS_gtlExpressionList::constructor_emptyList (SOURCE_FILE ("gtl_parser.galgas", 134)) ;
  GALGAS_bool var_globalTemplate_3484 = GALGAS_bool (true) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_template) COMMA_SOURCE_FILE ("gtl_parser.galgas", 137)) ;
  GALGAS_location var_where_3523 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_parser.galgas", 137)) ;
  switch (select_gtl_5F_parser_3 (inCompiler)) {
  case 1: {
    var_globalTemplate_3484 = GALGAS_bool (false) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__28_) COMMA_SOURCE_FILE ("gtl_parser.galgas", 140)) ;
    switch (select_gtl_5F_parser_4 (inCompiler)) {
    case 1: {
      bool repeatFlag_0 = true ;
      while (repeatFlag_0) {
        GALGAS_gtlExpression var_expression_3651 ;
        nt_gtl_5F_expression_ (var_expression_3651, inCompiler) ;
        var_templateArguments_3448.addAssign_operation (var_expression_3651  COMMA_SOURCE_FILE ("gtl_parser.galgas", 144)) ;
        switch (select_gtl_5F_parser_5 (inCompiler)) {
        case 2: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) COMMA_SOURCE_FILE ("gtl_parser.galgas", 146)) ;
        } break ;
        default:
          repeatFlag_0 = false ;
          break ;
        }
      }
    } break ;
    case 2: {
    } break ;
    default:
      break ;
    }
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__29_) COMMA_SOURCE_FILE ("gtl_parser.galgas", 149)) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  switch (select_gtl_5F_parser_6 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_if) COMMA_SOURCE_FILE ("gtl_parser.galgas", 153)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_exists) COMMA_SOURCE_FILE ("gtl_parser.galgas", 153)) ;
    var_ifExists_3324 = GALGAS_bool (true) ;
    nt_gtl_5F_file_5F_name_ (var_fileName_3409, inCompiler) ;
    switch (select_gtl_5F_parser_7 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_in) COMMA_SOURCE_FILE ("gtl_parser.galgas", 157)) ;
      var_prefix_3307 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_parser.galgas", 157)) ;
    } break ;
    case 2: {
      var_prefix_3307 = GALGAS_lstring::constructor_new (GALGAS_string::makeEmptyString (), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_parser.galgas", 158))  COMMA_SOURCE_FILE ("gtl_parser.galgas", 158)) ;
    } break ;
    default:
      break ;
    }
    switch (select_gtl_5F_parser_8 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_or) COMMA_SOURCE_FILE ("gtl_parser.galgas", 160)) ;
      nt_gtl_5F_template_5F_instruction_5F_list_ (var_instructionList_3370, inCompiler) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) COMMA_SOURCE_FILE ("gtl_parser.galgas", 162)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_template) COMMA_SOURCE_FILE ("gtl_parser.galgas", 162)) ;
    } break ;
    case 2: {
    } break ;
    default:
      break ;
    }
  } break ;
  case 2: {
    nt_gtl_5F_file_5F_name_ (var_fileName_3409, inCompiler) ;
    switch (select_gtl_5F_parser_9 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_in) COMMA_SOURCE_FILE ("gtl_parser.galgas", 167)) ;
      var_prefix_3307 = inCompiler->synthetizedAttribute_tokenString () ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_parser.galgas", 167)) ;
    } break ;
    case 2: {
      var_prefix_3307 = GALGAS_lstring::constructor_new (GALGAS_string::makeEmptyString (), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_parser.galgas", 168))  COMMA_SOURCE_FILE ("gtl_parser.galgas", 168)) ;
    } break ;
    default:
      break ;
    }
  } break ;
  default:
    break ;
  }
  outArgument_instruction = GALGAS_gtlTemplateInstruction::constructor_new (var_where_3523, function_signature (var_where_3523, inCompiler COMMA_SOURCE_FILE ("gtl_parser.galgas", 172)), var_prefix_3307, var_fileName_3409, var_ifExists_3324, var_globalTemplate_3484, var_templateArguments_3448, var_instructionList_3370  COMMA_SOURCE_FILE ("gtl_parser.galgas", 170)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i4_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_template) COMMA_SOURCE_FILE ("gtl_parser.galgas", 137)) ;
  switch (select_gtl_5F_parser_3 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__28_) COMMA_SOURCE_FILE ("gtl_parser.galgas", 140)) ;
    switch (select_gtl_5F_parser_4 (inCompiler)) {
    case 1: {
      bool repeatFlag_0 = true ;
      while (repeatFlag_0) {
        nt_gtl_5F_expression_parse (inCompiler) ;
        switch (select_gtl_5F_parser_5 (inCompiler)) {
        case 2: {
          inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) COMMA_SOURCE_FILE ("gtl_parser.galgas", 146)) ;
        } break ;
        default:
          repeatFlag_0 = false ;
          break ;
        }
      }
    } break ;
    case 2: {
    } break ;
    default:
      break ;
    }
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__29_) COMMA_SOURCE_FILE ("gtl_parser.galgas", 149)) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  switch (select_gtl_5F_parser_6 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_if) COMMA_SOURCE_FILE ("gtl_parser.galgas", 153)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_exists) COMMA_SOURCE_FILE ("gtl_parser.galgas", 153)) ;
    nt_gtl_5F_file_5F_name_parse (inCompiler) ;
    switch (select_gtl_5F_parser_7 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_in) COMMA_SOURCE_FILE ("gtl_parser.galgas", 157)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_parser.galgas", 157)) ;
    } break ;
    case 2: {
    } break ;
    default:
      break ;
    }
    switch (select_gtl_5F_parser_8 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_or) COMMA_SOURCE_FILE ("gtl_parser.galgas", 160)) ;
      nt_gtl_5F_template_5F_instruction_5F_list_parse (inCompiler) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) COMMA_SOURCE_FILE ("gtl_parser.galgas", 162)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_template) COMMA_SOURCE_FILE ("gtl_parser.galgas", 162)) ;
    } break ;
    case 2: {
    } break ;
    default:
      break ;
    }
  } break ;
  case 2: {
    nt_gtl_5F_file_5F_name_parse (inCompiler) ;
    switch (select_gtl_5F_parser_9 (inCompiler)) {
    case 1: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_in) COMMA_SOURCE_FILE ("gtl_parser.galgas", 167)) ;
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_parser.galgas", 167)) ;
    } break ;
    case 2: {
    } break ;
    default:
      break ;
    }
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i5_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                   C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3F_) COMMA_SOURCE_FILE ("gtl_parser.galgas", 185)) ;
  GALGAS_location var_where_4525 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_parser.galgas", 185)) ;
  GALGAS_gtlVarPath var_columnConstantName_4586 ;
  nt_gtl_5F_variable_ (var_columnConstantName_4586, inCompiler) ;
  outArgument_instruction = GALGAS_gtlGetColumnInstruction::constructor_new (var_where_4525, function_signature (var_where_4525, inCompiler COMMA_SOURCE_FILE ("gtl_parser.galgas", 190)), var_columnConstantName_4586  COMMA_SOURCE_FILE ("gtl_parser.galgas", 188)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i5_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__3F_) COMMA_SOURCE_FILE ("gtl_parser.galgas", 185)) ;
  nt_gtl_5F_variable_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i6_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                   C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  GALGAS_gtlThenElsifStatementList var_thenElsifList_4887 = GALGAS_gtlThenElsifStatementList::constructor_emptyList (SOURCE_FILE ("gtl_parser.galgas", 198)) ;
  GALGAS_gtlInstructionList var_elseList_4931 = GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_parser.galgas", 199)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_if) COMMA_SOURCE_FILE ("gtl_parser.galgas", 201)) ;
  GALGAS_location var_where_4970 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_parser.galgas", 201)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    GALGAS_gtlExpression var_condition_5034 ;
    nt_gtl_5F_expression_ (var_condition_5034, inCompiler) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_then) COMMA_SOURCE_FILE ("gtl_parser.galgas", 204)) ;
    GALGAS_gtlInstructionList var_instructionList_5118 ;
    nt_gtl_5F_template_5F_instruction_5F_list_ (var_instructionList_5118, inCompiler) ;
    var_thenElsifList_4887.addAssign_operation (var_condition_5034, var_instructionList_5118  COMMA_SOURCE_FILE ("gtl_parser.galgas", 207)) ;
    switch (select_gtl_5F_parser_10 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_elsif) COMMA_SOURCE_FILE ("gtl_parser.galgas", 209)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  switch (select_gtl_5F_parser_11 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_else) COMMA_SOURCE_FILE ("gtl_parser.galgas", 213)) ;
    nt_gtl_5F_template_5F_instruction_5F_list_ (var_elseList_4931, inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) COMMA_SOURCE_FILE ("gtl_parser.galgas", 217)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_if) COMMA_SOURCE_FILE ("gtl_parser.galgas", 218)) ;
  outArgument_instruction = GALGAS_gtlIfStatementInstruction::constructor_new (var_where_4970, function_signature (var_where_4970, inCompiler COMMA_SOURCE_FILE ("gtl_parser.galgas", 222)), var_thenElsifList_4887, var_elseList_4931  COMMA_SOURCE_FILE ("gtl_parser.galgas", 220)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i6_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_if) COMMA_SOURCE_FILE ("gtl_parser.galgas", 201)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    nt_gtl_5F_expression_parse (inCompiler) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_then) COMMA_SOURCE_FILE ("gtl_parser.galgas", 204)) ;
    nt_gtl_5F_template_5F_instruction_5F_list_parse (inCompiler) ;
    switch (select_gtl_5F_parser_10 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_elsif) COMMA_SOURCE_FILE ("gtl_parser.galgas", 209)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  switch (select_gtl_5F_parser_11 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_else) COMMA_SOURCE_FILE ("gtl_parser.galgas", 213)) ;
    nt_gtl_5F_template_5F_instruction_5F_list_parse (inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) COMMA_SOURCE_FILE ("gtl_parser.galgas", 217)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_if) COMMA_SOURCE_FILE ("gtl_parser.galgas", 218)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i7_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                   C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  GALGAS_gtlInstructionList var_beforeList_5601 = GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_parser.galgas", 230)) ;
  GALGAS_gtlInstructionList var_doList_5643 = GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_parser.galgas", 231)) ;
  GALGAS_gtlInstructionList var_betweenList_5690 = GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_parser.galgas", 232)) ;
  GALGAS_gtlInstructionList var_afterList_5735 = GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_parser.galgas", 233)) ;
  GALGAS_lstring var_indexName_5769 ;
  GALGAS_lstring var_variableName_5793 ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_foreach) COMMA_SOURCE_FILE ("gtl_parser.galgas", 237)) ;
  GALGAS_location var_where_5824 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_parser.galgas", 237)) ;
  GALGAS_lstring var_keyName_5869 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_parser.galgas", 238)) ;
  switch (select_gtl_5F_parser_12 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) COMMA_SOURCE_FILE ("gtl_parser.galgas", 240)) ;
    var_variableName_5793 = inCompiler->synthetizedAttribute_tokenString () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_parser.galgas", 240)) ;
  } break ;
  case 2: {
    var_variableName_5793 = var_keyName_5869 ;
    var_keyName_5869 = GALGAS_lstring::constructor_new (GALGAS_string::makeEmptyString (), var_where_5824  COMMA_SOURCE_FILE ("gtl_parser.galgas", 243)) ;
  } break ;
  default:
    break ;
  }
  switch (select_gtl_5F_parser_13 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__28_) COMMA_SOURCE_FILE ("gtl_parser.galgas", 246)) ;
    var_indexName_5769 = inCompiler->synthetizedAttribute_tokenString () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_parser.galgas", 246)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__29_) COMMA_SOURCE_FILE ("gtl_parser.galgas", 246)) ;
  } break ;
  case 2: {
    var_indexName_5769 = GALGAS_lstring::constructor_new (GALGAS_string ("INDEX"), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_parser.galgas", 248))  COMMA_SOURCE_FILE ("gtl_parser.galgas", 248)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_in) COMMA_SOURCE_FILE ("gtl_parser.galgas", 250)) ;
  GALGAS_gtlExpression var_iterable_6133 ;
  nt_gtl_5F_expression_ (var_iterable_6133, inCompiler) ;
  switch (select_gtl_5F_parser_14 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_before) COMMA_SOURCE_FILE ("gtl_parser.galgas", 254)) ;
    nt_gtl_5F_template_5F_instruction_5F_list_ (var_beforeList_5601, inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_do) COMMA_SOURCE_FILE ("gtl_parser.galgas", 258)) ;
  nt_gtl_5F_template_5F_instruction_5F_list_ (var_doList_5643, inCompiler) ;
  switch (select_gtl_5F_parser_15 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_between) COMMA_SOURCE_FILE ("gtl_parser.galgas", 262)) ;
    nt_gtl_5F_template_5F_instruction_5F_list_ (var_betweenList_5690, inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  switch (select_gtl_5F_parser_16 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_after) COMMA_SOURCE_FILE ("gtl_parser.galgas", 267)) ;
    nt_gtl_5F_template_5F_instruction_5F_list_ (var_afterList_5735, inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) COMMA_SOURCE_FILE ("gtl_parser.galgas", 271)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_foreach) COMMA_SOURCE_FILE ("gtl_parser.galgas", 272)) ;
  outArgument_instruction = GALGAS_gtlForeachStatementInstruction::constructor_new (var_where_5824, function_signature (var_where_5824, inCompiler COMMA_SOURCE_FILE ("gtl_parser.galgas", 276)), var_keyName_5869, var_variableName_5793, var_indexName_5769, var_iterable_6133, var_beforeList_5601, var_betweenList_5690, var_afterList_5735, var_doList_5643  COMMA_SOURCE_FILE ("gtl_parser.galgas", 274)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i7_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_foreach) COMMA_SOURCE_FILE ("gtl_parser.galgas", 237)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_parser.galgas", 238)) ;
  switch (select_gtl_5F_parser_12 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) COMMA_SOURCE_FILE ("gtl_parser.galgas", 240)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_parser.galgas", 240)) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  switch (select_gtl_5F_parser_13 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__28_) COMMA_SOURCE_FILE ("gtl_parser.galgas", 246)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_parser.galgas", 246)) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__29_) COMMA_SOURCE_FILE ("gtl_parser.galgas", 246)) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_in) COMMA_SOURCE_FILE ("gtl_parser.galgas", 250)) ;
  nt_gtl_5F_expression_parse (inCompiler) ;
  switch (select_gtl_5F_parser_14 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_before) COMMA_SOURCE_FILE ("gtl_parser.galgas", 254)) ;
    nt_gtl_5F_template_5F_instruction_5F_list_parse (inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_do) COMMA_SOURCE_FILE ("gtl_parser.galgas", 258)) ;
  nt_gtl_5F_template_5F_instruction_5F_list_parse (inCompiler) ;
  switch (select_gtl_5F_parser_15 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_between) COMMA_SOURCE_FILE ("gtl_parser.galgas", 262)) ;
    nt_gtl_5F_template_5F_instruction_5F_list_parse (inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  switch (select_gtl_5F_parser_16 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_after) COMMA_SOURCE_FILE ("gtl_parser.galgas", 267)) ;
    nt_gtl_5F_template_5F_instruction_5F_list_parse (inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) COMMA_SOURCE_FILE ("gtl_parser.galgas", 271)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_foreach) COMMA_SOURCE_FILE ("gtl_parser.galgas", 272)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i8_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                   C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  GALGAS_gtlInstructionList var_doList_6906 = GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_parser.galgas", 291)) ;
  GALGAS_gtlInstructionList var_betweenList_6953 = GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_parser.galgas", 292)) ;
  GALGAS_gtlExpressionList var_iterable_6997 = GALGAS_gtlExpressionList::constructor_emptyList (SOURCE_FILE ("gtl_parser.galgas", 293)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_for) COMMA_SOURCE_FILE ("gtl_parser.galgas", 295)) ;
  GALGAS_location var_where_7036 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_parser.galgas", 295)) ;
  const enumGalgasBool test_0 = GALGAS_bool (gOption_gtl_5F_options_warnDeprecated.getter_value ()).boolEnum () ;
  if (kBoolTrue == test_0) {
    TC_Array <C_FixItDescription> fixItArray1 ;
    appendFixItActions (fixItArray1, kFixItReplace, GALGAS_string ("foreach var in @( expression, ..., expression )")) ;
    inCompiler->emitSemanticWarning (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_parser.galgas", 297)), GALGAS_string ("for var in expression, ..., expression is deprecated"), fixItArray1  COMMA_SOURCE_FILE ("gtl_parser.galgas", 297)) ;
  }
  GALGAS_lstring var_variableName_7293 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_parser.galgas", 300)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_in) COMMA_SOURCE_FILE ("gtl_parser.galgas", 301)) ;
  bool repeatFlag_2 = true ;
  while (repeatFlag_2) {
    GALGAS_gtlExpression var_expression_7357 ;
    nt_gtl_5F_expression_ (var_expression_7357, inCompiler) ;
    var_iterable_6997.addAssign_operation (var_expression_7357  COMMA_SOURCE_FILE ("gtl_parser.galgas", 304)) ;
    switch (select_gtl_5F_parser_17 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) COMMA_SOURCE_FILE ("gtl_parser.galgas", 306)) ;
    } break ;
    default:
      repeatFlag_2 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_do) COMMA_SOURCE_FILE ("gtl_parser.galgas", 309)) ;
  nt_gtl_5F_template_5F_instruction_5F_list_ (var_doList_6906, inCompiler) ;
  switch (select_gtl_5F_parser_18 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_between) COMMA_SOURCE_FILE ("gtl_parser.galgas", 313)) ;
    nt_gtl_5F_template_5F_instruction_5F_list_ (var_betweenList_6953, inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) COMMA_SOURCE_FILE ("gtl_parser.galgas", 317)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_for) COMMA_SOURCE_FILE ("gtl_parser.galgas", 318)) ;
  outArgument_instruction = GALGAS_gtlForStatementInstruction::constructor_new (var_where_7036, function_signature (var_where_7036, inCompiler COMMA_SOURCE_FILE ("gtl_parser.galgas", 322)), var_variableName_7293, var_iterable_6997, var_betweenList_6953, var_doList_6906  COMMA_SOURCE_FILE ("gtl_parser.galgas", 320)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i8_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_for) COMMA_SOURCE_FILE ("gtl_parser.galgas", 295)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_parser.galgas", 300)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_in) COMMA_SOURCE_FILE ("gtl_parser.galgas", 301)) ;
  bool repeatFlag_0 = true ;
  while (repeatFlag_0) {
    nt_gtl_5F_expression_parse (inCompiler) ;
    switch (select_gtl_5F_parser_17 (inCompiler)) {
    case 2: {
      inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__2C_) COMMA_SOURCE_FILE ("gtl_parser.galgas", 306)) ;
    } break ;
    default:
      repeatFlag_0 = false ;
      break ;
    }
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_do) COMMA_SOURCE_FILE ("gtl_parser.galgas", 309)) ;
  nt_gtl_5F_template_5F_instruction_5F_list_parse (inCompiler) ;
  switch (select_gtl_5F_parser_18 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_between) COMMA_SOURCE_FILE ("gtl_parser.galgas", 313)) ;
    nt_gtl_5F_template_5F_instruction_5F_list_parse (inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) COMMA_SOURCE_FILE ("gtl_parser.galgas", 317)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_for) COMMA_SOURCE_FILE ("gtl_parser.galgas", 318)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i9_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                   C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  GALGAS_gtlInstructionList var_beforeList_7922 = GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_parser.galgas", 333)) ;
  GALGAS_gtlInstructionList var_betweenList_7969 = GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_parser.galgas", 334)) ;
  GALGAS_gtlInstructionList var_afterList_8014 = GALGAS_gtlInstructionList::constructor_emptyList (SOURCE_FILE ("gtl_parser.galgas", 335)) ;
  GALGAS_sint_36__34_ var_direction_8047 = GALGAS_sint_36__34_ ((int64_t) 1LL) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_loop) COMMA_SOURCE_FILE ("gtl_parser.galgas", 338)) ;
  GALGAS_location var_where_8081 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_parser.galgas", 338)) ;
  GALGAS_gtlExpression var_step_8112 = GALGAS_gtlTerminal::constructor_new (var_where_8081, GALGAS_gtlInt::constructor_new (var_where_8081, function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_parser.galgas", 341)), GALGAS_bigint ("1", inCompiler  COMMA_SOURCE_FILE ("gtl_parser.galgas", 341))  COMMA_SOURCE_FILE ("gtl_parser.galgas", 341))  COMMA_SOURCE_FILE ("gtl_parser.galgas", 340)) ;
  GALGAS_lstring var_variableName_8237 = inCompiler->synthetizedAttribute_tokenString () ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_parser.galgas", 344)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_from) COMMA_SOURCE_FILE ("gtl_parser.galgas", 345)) ;
  GALGAS_gtlExpression var_start_8287 ;
  nt_gtl_5F_expression_ (var_start_8287, inCompiler) ;
  switch (select_gtl_5F_parser_19 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_up) COMMA_SOURCE_FILE ("gtl_parser.galgas", 349)) ;
  } break ;
  case 3: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_down) COMMA_SOURCE_FILE ("gtl_parser.galgas", 351)) ;
    var_direction_8047 = GALGAS_sint_36__34_ ((int64_t) 1LL).operator_unary_minus (inCompiler COMMA_SOURCE_FILE ("gtl_parser.galgas", 351)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_to) COMMA_SOURCE_FILE ("gtl_parser.galgas", 353)) ;
  GALGAS_gtlExpression var_stop_8397 ;
  nt_gtl_5F_expression_ (var_stop_8397, inCompiler) ;
  switch (select_gtl_5F_parser_20 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_step) COMMA_SOURCE_FILE ("gtl_parser.galgas", 356)) ;
    nt_gtl_5F_expression_ (var_step_8112, inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  switch (select_gtl_5F_parser_21 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_before) COMMA_SOURCE_FILE ("gtl_parser.galgas", 361)) ;
    nt_gtl_5F_template_5F_instruction_5F_list_ (var_beforeList_7922, inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_do) COMMA_SOURCE_FILE ("gtl_parser.galgas", 365)) ;
  GALGAS_gtlInstructionList var_doList_8633 ;
  nt_gtl_5F_template_5F_instruction_5F_list_ (var_doList_8633, inCompiler) ;
  switch (select_gtl_5F_parser_22 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_between) COMMA_SOURCE_FILE ("gtl_parser.galgas", 369)) ;
    nt_gtl_5F_template_5F_instruction_5F_list_ (var_betweenList_7969, inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  switch (select_gtl_5F_parser_23 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_after) COMMA_SOURCE_FILE ("gtl_parser.galgas", 374)) ;
    nt_gtl_5F_template_5F_instruction_5F_list_ (var_afterList_8014, inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) COMMA_SOURCE_FILE ("gtl_parser.galgas", 378)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_loop) COMMA_SOURCE_FILE ("gtl_parser.galgas", 379)) ;
  outArgument_instruction = GALGAS_gtlLoopStatementInstruction::constructor_new (var_where_8081, function_signature (var_where_8081, inCompiler COMMA_SOURCE_FILE ("gtl_parser.galgas", 383)), var_variableName_8237, var_start_8287, var_stop_8397, var_step_8112, var_direction_8047, var_beforeList_7922, var_betweenList_7969, var_afterList_8014, var_doList_8633  COMMA_SOURCE_FILE ("gtl_parser.galgas", 381)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i9_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_loop) COMMA_SOURCE_FILE ("gtl_parser.galgas", 338)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_parser.galgas", 344)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_from) COMMA_SOURCE_FILE ("gtl_parser.galgas", 345)) ;
  nt_gtl_5F_expression_parse (inCompiler) ;
  switch (select_gtl_5F_parser_19 (inCompiler)) {
  case 1: {
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_up) COMMA_SOURCE_FILE ("gtl_parser.galgas", 349)) ;
  } break ;
  case 3: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_down) COMMA_SOURCE_FILE ("gtl_parser.galgas", 351)) ;
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_to) COMMA_SOURCE_FILE ("gtl_parser.galgas", 353)) ;
  nt_gtl_5F_expression_parse (inCompiler) ;
  switch (select_gtl_5F_parser_20 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_step) COMMA_SOURCE_FILE ("gtl_parser.galgas", 356)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  switch (select_gtl_5F_parser_21 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_before) COMMA_SOURCE_FILE ("gtl_parser.galgas", 361)) ;
    nt_gtl_5F_template_5F_instruction_5F_list_parse (inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_do) COMMA_SOURCE_FILE ("gtl_parser.galgas", 365)) ;
  nt_gtl_5F_template_5F_instruction_5F_list_parse (inCompiler) ;
  switch (select_gtl_5F_parser_22 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_between) COMMA_SOURCE_FILE ("gtl_parser.galgas", 369)) ;
    nt_gtl_5F_template_5F_instruction_5F_list_parse (inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  switch (select_gtl_5F_parser_23 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_after) COMMA_SOURCE_FILE ("gtl_parser.galgas", 374)) ;
    nt_gtl_5F_template_5F_instruction_5F_list_parse (inCompiler) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) COMMA_SOURCE_FILE ("gtl_parser.galgas", 378)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_loop) COMMA_SOURCE_FILE ("gtl_parser.galgas", 379)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i10_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                    C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  GALGAS_gtlExpression var_limit_9234 ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_repeat) COMMA_SOURCE_FILE ("gtl_parser.galgas", 401)) ;
  GALGAS_location var_where_9264 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_parser.galgas", 401)) ;
  switch (select_gtl_5F_parser_24 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__28_) COMMA_SOURCE_FILE ("gtl_parser.galgas", 403)) ;
    nt_gtl_5F_expression_ (var_limit_9234, inCompiler) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__29_) COMMA_SOURCE_FILE ("gtl_parser.galgas", 405)) ;
  } break ;
  case 2: {
    var_limit_9234 = GALGAS_gtlTerminal::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_parser.galgas", 408)), GALGAS_gtlInt::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_parser.galgas", 408)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_parser.galgas", 408)), GALGAS_uint::constructor_max (SOURCE_FILE ("gtl_parser.galgas", 408)).getter_bigint (SOURCE_FILE ("gtl_parser.galgas", 408))  COMMA_SOURCE_FILE ("gtl_parser.galgas", 408))  COMMA_SOURCE_FILE ("gtl_parser.galgas", 407)) ;
  } break ;
  default:
    break ;
  }
  GALGAS_gtlInstructionList var_continueList_9515 ;
  nt_gtl_5F_template_5F_instruction_5F_list_ (var_continueList_9515, inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_while) COMMA_SOURCE_FILE ("gtl_parser.galgas", 412)) ;
  GALGAS_gtlExpression var_condition_9570 ;
  nt_gtl_5F_expression_ (var_condition_9570, inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_do) COMMA_SOURCE_FILE ("gtl_parser.galgas", 414)) ;
  GALGAS_gtlInstructionList var_doList_9639 ;
  nt_gtl_5F_template_5F_instruction_5F_list_ (var_doList_9639, inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) COMMA_SOURCE_FILE ("gtl_parser.galgas", 416)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_repeat) COMMA_SOURCE_FILE ("gtl_parser.galgas", 417)) ;
  outArgument_instruction = GALGAS_gtlRepeatStatementInstruction::constructor_new (var_where_9264, function_signature (var_where_9264, inCompiler COMMA_SOURCE_FILE ("gtl_parser.galgas", 421)), var_limit_9234, var_condition_9570, var_continueList_9515, var_doList_9639  COMMA_SOURCE_FILE ("gtl_parser.galgas", 419)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i10_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_repeat) COMMA_SOURCE_FILE ("gtl_parser.galgas", 401)) ;
  switch (select_gtl_5F_parser_24 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__28_) COMMA_SOURCE_FILE ("gtl_parser.galgas", 403)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken__29_) COMMA_SOURCE_FILE ("gtl_parser.galgas", 405)) ;
  } break ;
  case 2: {
  } break ;
  default:
    break ;
  }
  nt_gtl_5F_template_5F_instruction_5F_list_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_while) COMMA_SOURCE_FILE ("gtl_parser.galgas", 412)) ;
  nt_gtl_5F_expression_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_do) COMMA_SOURCE_FILE ("gtl_parser.galgas", 414)) ;
  nt_gtl_5F_template_5F_instruction_5F_list_parse (inCompiler) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_end) COMMA_SOURCE_FILE ("gtl_parser.galgas", 416)) ;
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_repeat) COMMA_SOURCE_FILE ("gtl_parser.galgas", 417)) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i11_ (GALGAS_gtlInstruction & outArgument_instruction,
                                                                                    C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_instruction.drop () ; // Release 'out' argument
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_input) COMMA_SOURCE_FILE ("gtl_parser.galgas", 432)) ;
  GALGAS_location var_where_9980 = GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_parser.galgas", 432)) ;
  GALGAS_gtlArgumentList var_arguments_10038 ;
  nt_gtl_5F_argument_5F_list_ (var_arguments_10038, inCompiler) ;
  outArgument_instruction = GALGAS_gtlInputStatementInstruction::constructor_new (var_where_9980, function_signature (var_where_9980, inCompiler COMMA_SOURCE_FILE ("gtl_parser.galgas", 437)), var_arguments_10038  COMMA_SOURCE_FILE ("gtl_parser.galgas", 435)) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_template_5F_instruction_i11_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_input) COMMA_SOURCE_FILE ("gtl_parser.galgas", 432)) ;
  nt_gtl_5F_argument_5F_list_parse (inCompiler) ;
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_file_5F_name_i12_ (GALGAS_gtlExpression & outArgument_expression,
                                                                         C_Lexique_gtl_5F_scanner * inCompiler) {
  outArgument_expression.drop () ; // Release 'out' argument
  switch (select_gtl_5F_parser_25 (inCompiler)) {
  case 1: {
    GALGAS_lstring var_fileName_10330 = inCompiler->synthetizedAttribute_tokenString () ;
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_parser.galgas", 447)) ;
    outArgument_expression = GALGAS_gtlTerminal::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("gtl_parser.galgas", 449)), GALGAS_gtlString::constructor_new (var_fileName_10330.getter_location (SOURCE_FILE ("gtl_parser.galgas", 450)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("gtl_parser.galgas", 450)), var_fileName_10330.getter_string (SOURCE_FILE ("gtl_parser.galgas", 450))  COMMA_SOURCE_FILE ("gtl_parser.galgas", 449))  COMMA_SOURCE_FILE ("gtl_parser.galgas", 448)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_from) COMMA_SOURCE_FILE ("gtl_parser.galgas", 454)) ;
    nt_gtl_5F_expression_ (outArgument_expression, inCompiler) ;
  } break ;
  default:
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cParser_gtl_5F_parser::rule_gtl_5F_parser_gtl_5F_file_5F_name_i12_parse (C_Lexique_gtl_5F_scanner * inCompiler) {
  switch (select_gtl_5F_parser_25 (inCompiler)) {
  case 1: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_identifier) COMMA_SOURCE_FILE ("gtl_parser.galgas", 447)) ;
  } break ;
  case 2: {
    inCompiler->acceptTerminal (ACCEPT_TERMINAL (C_Lexique_gtl_5F_scanner::kToken_from) COMMA_SOURCE_FILE ("gtl_parser.galgas", 454)) ;
    nt_gtl_5F_expression_parse (inCompiler) ;
  } break ;
  default:
    break ;
  }
  inCompiler->resetTemplateString () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Extension setter '@gtlContext setDebugger'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionSetterSignature_gtlContext_setDebugger> gExtensionModifierTable_gtlContext_setDebugger ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_setDebugger (const int32_t inClassIndex,
                                       extensionSetterSignature_gtlContext_setDebugger inModifier) {
  gExtensionModifierTable_gtlContext_setDebugger.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_setDebugger (cPtr_gtlContext * inObject,
                                      GALGAS_bool in_debugOn,
                                      C_Compiler * inCompiler
                                      COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_gtlContext_setDebugger f = NULL ;
    if (classIndex < gExtensionModifierTable_gtlContext_setDebugger.count ()) {
      f = gExtensionModifierTable_gtlContext_setDebugger (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_gtlContext_setDebugger.count ()) {
           f = gExtensionModifierTable_gtlContext_setDebugger (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_gtlContext_setDebugger.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, in_debugOn, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_gtlContext_setDebugger (cPtr_gtlContext * inObject,
                                                    GALGAS_bool inArgument_debugOn,
                                                    C_Compiler * /* inCompiler */
                                                    COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlContext * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlContext) ;
  {
  object->mProperty_debuggerContext.setter_setDebugActive (inArgument_debugOn COMMA_SOURCE_FILE ("gtl_debugger.galgas", 427)) ;
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_gtlContext_setDebugger (void) {
  enterExtensionSetter_setDebugger (kTypeDescriptor_GALGAS_gtlContext.mSlotID,
                                    extensionSetter_gtlContext_setDebugger) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionModifier_gtlContext_setDebugger (void) {
  gExtensionModifierTable_gtlContext_setDebugger.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_gtlContext_setDebugger (defineExtensionSetter_gtlContext_setDebugger,
                                                   freeExtensionModifier_gtlContext_setDebugger) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Extension setter '@gtlContext setBreakOnNext'                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionSetterSignature_gtlContext_setBreakOnNext> gExtensionModifierTable_gtlContext_setBreakOnNext ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_setBreakOnNext (const int32_t inClassIndex,
                                          extensionSetterSignature_gtlContext_setBreakOnNext inModifier) {
  gExtensionModifierTable_gtlContext_setBreakOnNext.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_setBreakOnNext (cPtr_gtlContext * inObject,
                                         GALGAS_bool in_break,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_gtlContext_setBreakOnNext f = NULL ;
    if (classIndex < gExtensionModifierTable_gtlContext_setBreakOnNext.count ()) {
      f = gExtensionModifierTable_gtlContext_setBreakOnNext (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_gtlContext_setBreakOnNext.count ()) {
           f = gExtensionModifierTable_gtlContext_setBreakOnNext (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_gtlContext_setBreakOnNext.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, in_break, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_gtlContext_setBreakOnNext (cPtr_gtlContext * inObject,
                                                       GALGAS_bool inArgument_break,
                                                       C_Compiler * /* inCompiler */
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlContext * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlContext) ;
  {
  object->mProperty_debuggerContext.setter_setBreakOnNext (inArgument_break COMMA_SOURCE_FILE ("gtl_debugger.galgas", 434)) ;
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_gtlContext_setBreakOnNext (void) {
  enterExtensionSetter_setBreakOnNext (kTypeDescriptor_GALGAS_gtlContext.mSlotID,
                                       extensionSetter_gtlContext_setBreakOnNext) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionModifier_gtlContext_setBreakOnNext (void) {
  gExtensionModifierTable_gtlContext_setBreakOnNext.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_gtlContext_setBreakOnNext (defineExtensionSetter_gtlContext_setBreakOnNext,
                                                      freeExtensionModifier_gtlContext_setBreakOnNext) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Extension getter '@gtlContext debugActive'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlContext_debugActive> gExtensionGetterTable_gtlContext_debugActive ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_debugActive (const int32_t inClassIndex,
                                       enterExtensionGetter_gtlContext_debugActive inGetter) {
  gExtensionGetterTable_gtlContext_debugActive.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool callExtensionGetter_debugActive (const cPtr_gtlContext * inObject,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
  GALGAS_bool result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlContext_debugActive f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlContext_debugActive.count ()) {
      f = gExtensionGetterTable_gtlContext_debugActive (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlContext_debugActive.count ()) {
           f = gExtensionGetterTable_gtlContext_debugActive (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlContext_debugActive.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_bool extensionGetter_gtlContext_debugActive (const cPtr_gtlContext * inObject,
                                                           C_Compiler * /* inCompiler */
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_debugOn ; // Returned variable
  const cPtr_gtlContext * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlContext) ;
  result_debugOn = object->mProperty_debuggerContext.getter_debugActive (SOURCE_FILE ("gtl_debugger.galgas", 441)) ;
//---
  return result_debugOn ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlContext_debugActive (void) {
  enterExtensionGetter_debugActive (kTypeDescriptor_GALGAS_gtlContext.mSlotID,
                                    extensionGetter_gtlContext_debugActive) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlContext_debugActive (void) {
  gExtensionGetterTable_gtlContext_debugActive.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlContext_debugActive (defineExtensionGetter_gtlContext_debugActive,
                                                   freeExtensionGetter_gtlContext_debugActive) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Extension getter '@gtlContext breakOnNext'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlContext_breakOnNext> gExtensionGetterTable_gtlContext_breakOnNext ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_breakOnNext (const int32_t inClassIndex,
                                       enterExtensionGetter_gtlContext_breakOnNext inGetter) {
  gExtensionGetterTable_gtlContext_breakOnNext.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool callExtensionGetter_breakOnNext (const cPtr_gtlContext * inObject,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
  GALGAS_bool result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlContext_breakOnNext f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlContext_breakOnNext.count ()) {
      f = gExtensionGetterTable_gtlContext_breakOnNext (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlContext_breakOnNext.count ()) {
           f = gExtensionGetterTable_gtlContext_breakOnNext (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlContext_breakOnNext.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_bool extensionGetter_gtlContext_breakOnNext (const cPtr_gtlContext * inObject,
                                                           C_Compiler * /* inCompiler */
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_breakOnNext ; // Returned variable
  const cPtr_gtlContext * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlContext) ;
  result_breakOnNext = object->mProperty_debuggerContext.getter_breakOnNext (SOURCE_FILE ("gtl_debugger.galgas", 448)) ;
//---
  return result_breakOnNext ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlContext_breakOnNext (void) {
  enterExtensionGetter_breakOnNext (kTypeDescriptor_GALGAS_gtlContext.mSlotID,
                                    extensionGetter_gtlContext_breakOnNext) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlContext_breakOnNext (void) {
  gExtensionGetterTable_gtlContext_breakOnNext.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlContext_breakOnNext (defineExtensionGetter_gtlContext_breakOnNext,
                                                   freeExtensionGetter_gtlContext_breakOnNext) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Extension getter '@gtlContext breakOn'                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlContext_breakOn> gExtensionGetterTable_gtlContext_breakOn ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_breakOn (const int32_t inClassIndex,
                                   enterExtensionGetter_gtlContext_breakOn inGetter) {
  gExtensionGetterTable_gtlContext_breakOn.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool callExtensionGetter_breakOn (const cPtr_gtlContext * inObject,
                                         GALGAS_gtlInstruction in_instruction,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
  GALGAS_bool result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlContext_breakOn f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlContext_breakOn.count ()) {
      f = gExtensionGetterTable_gtlContext_breakOn (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlContext_breakOn.count ()) {
           f = gExtensionGetterTable_gtlContext_breakOn (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlContext_breakOn.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_instruction, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_bool extensionGetter_gtlContext_breakOn (const cPtr_gtlContext * inObject,
                                                       GALGAS_gtlInstruction inArgument_instruction,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_breakOn ; // Returned variable
  const cPtr_gtlContext * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlContext) ;
  result_breakOn = callExtensionGetter_breakOn ((const cPtr_debuggerContext *) object->mProperty_debuggerContext.ptr (), inArgument_instruction, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 456)) ;
//---
  return result_breakOn ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlContext_breakOn (void) {
  enterExtensionGetter_breakOn (kTypeDescriptor_GALGAS_gtlContext.mSlotID,
                                extensionGetter_gtlContext_breakOn) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlContext_breakOn (void) {
  gExtensionGetterTable_gtlContext_breakOn.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlContext_breakOn (defineExtensionGetter_gtlContext_breakOn,
                                               freeExtensionGetter_gtlContext_breakOn) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                       Extension getter '@gtlContext watchOn'                                        *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlContext_watchOn> gExtensionGetterTable_gtlContext_watchOn ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_watchOn (const int32_t inClassIndex,
                                   enterExtensionGetter_gtlContext_watchOn inGetter) {
  gExtensionGetterTable_gtlContext_watchOn.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool callExtensionGetter_watchOn (const cPtr_gtlContext * inObject,
                                         const GALGAS_gtlContext in_context,
                                         const GALGAS_gtlData in_vars,
                                         const GALGAS_library in_lib,
                                         C_Compiler * inCompiler
                                         COMMA_LOCATION_ARGS) {
  GALGAS_bool result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlContext_watchOn f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlContext_watchOn.count ()) {
      f = gExtensionGetterTable_gtlContext_watchOn (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlContext_watchOn.count ()) {
           f = gExtensionGetterTable_gtlContext_watchOn (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlContext_watchOn.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_context, in_vars, in_lib, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_bool extensionGetter_gtlContext_watchOn (const cPtr_gtlContext * inObject,
                                                       const GALGAS_gtlContext constinArgument_context,
                                                       const GALGAS_gtlData constinArgument_vars,
                                                       const GALGAS_library constinArgument_lib,
                                                       C_Compiler * inCompiler
                                                       COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_watchOn ; // Returned variable
  const cPtr_gtlContext * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlContext) ;
  result_watchOn = callExtensionGetter_watchOn ((const cPtr_debuggerContext *) object->mProperty_debuggerContext.ptr (), constinArgument_context, constinArgument_vars, constinArgument_lib, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 466)) ;
//---
  return result_watchOn ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlContext_watchOn (void) {
  enterExtensionGetter_watchOn (kTypeDescriptor_GALGAS_gtlContext.mSlotID,
                                extensionGetter_gtlContext_watchOn) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlContext_watchOn (void) {
  gExtensionGetterTable_gtlContext_watchOn.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlContext_watchOn (defineExtensionGetter_gtlContext_watchOn,
                                               freeExtensionGetter_gtlContext_watchOn) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Extension getter '@gtlContext promptStyle'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlContext_promptStyle> gExtensionGetterTable_gtlContext_promptStyle ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_promptStyle (const int32_t inClassIndex,
                                       enterExtensionGetter_gtlContext_promptStyle inGetter) {
  gExtensionGetterTable_gtlContext_promptStyle.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string callExtensionGetter_promptStyle (const cPtr_gtlContext * inObject,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) {
  GALGAS_string result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlContext_promptStyle f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlContext_promptStyle.count ()) {
      f = gExtensionGetterTable_gtlContext_promptStyle (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlContext_promptStyle.count ()) {
           f = gExtensionGetterTable_gtlContext_promptStyle (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlContext_promptStyle.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_gtlContext_promptStyle (const cPtr_gtlContext * inObject,
                                                             C_Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlContext * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlContext) ;
  result_result = object->mProperty_debuggerContext.getter_promptColor (SOURCE_FILE ("gtl_debugger.galgas", 473)).add_operation (object->mProperty_debuggerContext.getter_promptFace (SOURCE_FILE ("gtl_debugger.galgas", 473)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 473)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlContext_promptStyle (void) {
  enterExtensionGetter_promptStyle (kTypeDescriptor_GALGAS_gtlContext.mSlotID,
                                    extensionGetter_gtlContext_promptStyle) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlContext_promptStyle (void) {
  gExtensionGetterTable_gtlContext_promptStyle.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlContext_promptStyle (defineExtensionGetter_gtlContext_promptStyle,
                                                   freeExtensionGetter_gtlContext_promptStyle) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                     Extension getter '@gtlContext outputStyle'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlContext_outputStyle> gExtensionGetterTable_gtlContext_outputStyle ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_outputStyle (const int32_t inClassIndex,
                                       enterExtensionGetter_gtlContext_outputStyle inGetter) {
  gExtensionGetterTable_gtlContext_outputStyle.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_string callExtensionGetter_outputStyle (const cPtr_gtlContext * inObject,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) {
  GALGAS_string result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlContext_outputStyle f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlContext_outputStyle.count ()) {
      f = gExtensionGetterTable_gtlContext_outputStyle (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlContext_outputStyle.count ()) {
           f = gExtensionGetterTable_gtlContext_outputStyle (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlContext_outputStyle.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_string extensionGetter_gtlContext_outputStyle (const cPtr_gtlContext * inObject,
                                                             C_Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_string result_result ; // Returned variable
  const cPtr_gtlContext * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlContext) ;
  result_result = object->mProperty_debuggerContext.getter_outputColor (SOURCE_FILE ("gtl_debugger.galgas", 480)).add_operation (object->mProperty_debuggerContext.getter_outputFace (SOURCE_FILE ("gtl_debugger.galgas", 480)), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 480)) ;
//---
  return result_result ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlContext_outputStyle (void) {
  enterExtensionGetter_outputStyle (kTypeDescriptor_GALGAS_gtlContext.mSlotID,
                                    extensionGetter_gtlContext_outputStyle) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlContext_outputStyle (void) {
  gExtensionGetterTable_gtlContext_outputStyle.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlContext_outputStyle (defineExtensionGetter_gtlContext_outputStyle,
                                                   freeExtensionGetter_gtlContext_outputStyle) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              Extension setter '@gtlContext appendInstructionToStepDo'                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionSetterSignature_gtlContext_appendInstructionToStepDo> gExtensionModifierTable_gtlContext_appendInstructionToStepDo ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_appendInstructionToStepDo (const int32_t inClassIndex,
                                                     extensionSetterSignature_gtlContext_appendInstructionToStepDo inModifier) {
  gExtensionModifierTable_gtlContext_appendInstructionToStepDo.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_appendInstructionToStepDo (cPtr_gtlContext * inObject,
                                                    GALGAS_gtlInstruction in_instruction,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_gtlContext_appendInstructionToStepDo f = NULL ;
    if (classIndex < gExtensionModifierTable_gtlContext_appendInstructionToStepDo.count ()) {
      f = gExtensionModifierTable_gtlContext_appendInstructionToStepDo (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_gtlContext_appendInstructionToStepDo.count ()) {
           f = gExtensionModifierTable_gtlContext_appendInstructionToStepDo (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_gtlContext_appendInstructionToStepDo.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, in_instruction, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_gtlContext_appendInstructionToStepDo (cPtr_gtlContext * inObject,
                                                                  GALGAS_gtlInstruction inArgument_instruction,
                                                                  C_Compiler * inCompiler
                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlContext * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlContext) ;
  {
  object->mProperty_debuggerContext.insulate (HERE) ;
  cPtr_debuggerContext * ptr_15249 = (cPtr_debuggerContext *) object->mProperty_debuggerContext.ptr () ;
  callExtensionSetter_appendInstructionToStepDo ((cPtr_debuggerContext *) ptr_15249, inArgument_instruction, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 487)) ;
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_gtlContext_appendInstructionToStepDo (void) {
  enterExtensionSetter_appendInstructionToStepDo (kTypeDescriptor_GALGAS_gtlContext.mSlotID,
                                                  extensionSetter_gtlContext_appendInstructionToStepDo) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionModifier_gtlContext_appendInstructionToStepDo (void) {
  gExtensionModifierTable_gtlContext_appendInstructionToStepDo.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_gtlContext_appendInstructionToStepDo (defineExtensionSetter_gtlContext_appendInstructionToStepDo,
                                                                 freeExtensionModifier_gtlContext_appendInstructionToStepDo) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               Extension setter '@gtlContext deleteStepDoInstruction'                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionSetterSignature_gtlContext_deleteStepDoInstruction> gExtensionModifierTable_gtlContext_deleteStepDoInstruction ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_deleteStepDoInstruction (const int32_t inClassIndex,
                                                   extensionSetterSignature_gtlContext_deleteStepDoInstruction inModifier) {
  gExtensionModifierTable_gtlContext_deleteStepDoInstruction.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_deleteStepDoInstruction (cPtr_gtlContext * inObject,
                                                  const GALGAS_lbigint constin_numToDelete,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_gtlContext_deleteStepDoInstruction f = NULL ;
    if (classIndex < gExtensionModifierTable_gtlContext_deleteStepDoInstruction.count ()) {
      f = gExtensionModifierTable_gtlContext_deleteStepDoInstruction (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_gtlContext_deleteStepDoInstruction.count ()) {
           f = gExtensionModifierTable_gtlContext_deleteStepDoInstruction (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_gtlContext_deleteStepDoInstruction.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, constin_numToDelete, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_gtlContext_deleteStepDoInstruction (cPtr_gtlContext * inObject,
                                                                const GALGAS_lbigint constinArgument_numToDelete,
                                                                C_Compiler * inCompiler
                                                                COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlContext * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlContext) ;
  {
  object->mProperty_debuggerContext.insulate (HERE) ;
  cPtr_debuggerContext * ptr_15466 = (cPtr_debuggerContext *) object->mProperty_debuggerContext.ptr () ;
  callExtensionSetter_deleteStepDoInstruction ((cPtr_debuggerContext *) ptr_15466, constinArgument_numToDelete, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 494)) ;
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_gtlContext_deleteStepDoInstruction (void) {
  enterExtensionSetter_deleteStepDoInstruction (kTypeDescriptor_GALGAS_gtlContext.mSlotID,
                                                extensionSetter_gtlContext_deleteStepDoInstruction) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionModifier_gtlContext_deleteStepDoInstruction (void) {
  gExtensionModifierTable_gtlContext_deleteStepDoInstruction.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_gtlContext_deleteStepDoInstruction (defineExtensionSetter_gtlContext_deleteStepDoInstruction,
                                                               freeExtensionModifier_gtlContext_deleteStepDoInstruction) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                             Extension setter '@gtlContext deleteAllStepDoInstructions'                              *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionSetterSignature_gtlContext_deleteAllStepDoInstructions> gExtensionModifierTable_gtlContext_deleteAllStepDoInstructions ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_deleteAllStepDoInstructions (const int32_t inClassIndex,
                                                       extensionSetterSignature_gtlContext_deleteAllStepDoInstructions inModifier) {
  gExtensionModifierTable_gtlContext_deleteAllStepDoInstructions.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_deleteAllStepDoInstructions (cPtr_gtlContext * inObject,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_gtlContext_deleteAllStepDoInstructions f = NULL ;
    if (classIndex < gExtensionModifierTable_gtlContext_deleteAllStepDoInstructions.count ()) {
      f = gExtensionModifierTable_gtlContext_deleteAllStepDoInstructions (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_gtlContext_deleteAllStepDoInstructions.count ()) {
           f = gExtensionModifierTable_gtlContext_deleteAllStepDoInstructions (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_gtlContext_deleteAllStepDoInstructions.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_gtlContext_deleteAllStepDoInstructions (cPtr_gtlContext * inObject,
                                                                    C_Compiler * inCompiler
                                                                    COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlContext * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlContext) ;
  {
  object->mProperty_debuggerContext.insulate (HERE) ;
  cPtr_debuggerContext * ptr_15657 = (cPtr_debuggerContext *) object->mProperty_debuggerContext.ptr () ;
  callExtensionSetter_deleteAllStepDoInstructions ((cPtr_debuggerContext *) ptr_15657, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 500)) ;
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_gtlContext_deleteAllStepDoInstructions (void) {
  enterExtensionSetter_deleteAllStepDoInstructions (kTypeDescriptor_GALGAS_gtlContext.mSlotID,
                                                    extensionSetter_gtlContext_deleteAllStepDoInstructions) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionModifier_gtlContext_deleteAllStepDoInstructions (void) {
  gExtensionModifierTable_gtlContext_deleteAllStepDoInstructions.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_gtlContext_deleteAllStepDoInstructions (defineExtensionSetter_gtlContext_deleteAllStepDoInstructions,
                                                                   freeExtensionModifier_gtlContext_deleteAllStepDoInstructions) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Extension method '@gtlContext listStepDoInstructions'                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionMethodSignature_gtlContext_listStepDoInstructions> gExtensionMethodTable_gtlContext_listStepDoInstructions ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_listStepDoInstructions (const int32_t inClassIndex,
                                                  extensionMethodSignature_gtlContext_listStepDoInstructions inMethod) {
  gExtensionMethodTable_gtlContext_listStepDoInstructions.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_listStepDoInstructions (const cPtr_gtlContext * inObject,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) {
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_gtlContext_listStepDoInstructions f = NULL ;
    if (classIndex < gExtensionMethodTable_gtlContext_listStepDoInstructions.count ()) {
      f = gExtensionMethodTable_gtlContext_listStepDoInstructions (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_gtlContext_listStepDoInstructions.count ()) {
           f = gExtensionMethodTable_gtlContext_listStepDoInstructions (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_gtlContext_listStepDoInstructions.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlContext_listStepDoInstructions (const cPtr_gtlContext * inObject,
                                                               C_Compiler * inCompiler
                                                               COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlContext * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlContext) ;
  callExtensionMethod_listStepDoInstructions ((const cPtr_debuggerContext *) object->mProperty_debuggerContext.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 506)) ;
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlContext_listStepDoInstructions (void) {
  enterExtensionMethod_listStepDoInstructions (kTypeDescriptor_GALGAS_gtlContext.mSlotID,
                                               extensionMethod_gtlContext_listStepDoInstructions) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionMethod_gtlContext_listStepDoInstructions (void) {
  gExtensionMethodTable_gtlContext_listStepDoInstructions.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlContext_listStepDoInstructions (defineExtensionMethod_gtlContext_listStepDoInstructions,
                                                              freeExtensionMethod_gtlContext_listStepDoInstructions) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                  Extension setter '@gtlContext executeStepDoList'                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionSetterSignature_gtlContext_executeStepDoList> gExtensionModifierTable_gtlContext_executeStepDoList ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_executeStepDoList (const int32_t inClassIndex,
                                             extensionSetterSignature_gtlContext_executeStepDoList inModifier) {
  gExtensionModifierTable_gtlContext_executeStepDoList.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_executeStepDoList (cPtr_gtlContext * inObject,
                                            GALGAS_gtlContext & io_context,
                                            GALGAS_gtlData & io_vars,
                                            GALGAS_library & io_lib,
                                            GALGAS_string & io_outputString,
                                            C_Compiler * inCompiler
                                            COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_gtlContext_executeStepDoList f = NULL ;
    if (classIndex < gExtensionModifierTable_gtlContext_executeStepDoList.count ()) {
      f = gExtensionModifierTable_gtlContext_executeStepDoList (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_gtlContext_executeStepDoList.count ()) {
           f = gExtensionModifierTable_gtlContext_executeStepDoList (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_gtlContext_executeStepDoList.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, io_context, io_vars, io_lib, io_outputString, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_gtlContext_executeStepDoList (cPtr_gtlContext * inObject,
                                                          GALGAS_gtlContext & ioArgument_context,
                                                          GALGAS_gtlData & ioArgument_vars,
                                                          GALGAS_library & ioArgument_lib,
                                                          GALGAS_string & ioArgument_outputString,
                                                          C_Compiler * inCompiler
                                                          COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlContext * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlContext) ;
  inCompiler->printMessage (callExtensionGetter_outputStyle ((const cPtr_gtlContext *) ioArgument_context.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 516))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 516)) ;
  cEnumerator_gtlInstructionList enumerator_16152 (object->mProperty_debuggerContext.getter_doList (SOURCE_FILE ("gtl_debugger.galgas", 517)), kENUMERATION_UP) ;
  while (enumerator_16152.hasCurrentObject ()) {
    callExtensionMethod_execute ((const cPtr_gtlInstruction *) enumerator_16152.current_instruction (HERE).ptr (), ioArgument_context, ioArgument_vars, ioArgument_lib, ioArgument_outputString, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 518)) ;
    enumerator_16152.gotoNextObject () ;
  }
  inCompiler->printMessage (function_endc (inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 520))  COMMA_SOURCE_FILE ("gtl_debugger.galgas", 520)) ;
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_gtlContext_executeStepDoList (void) {
  enterExtensionSetter_executeStepDoList (kTypeDescriptor_GALGAS_gtlContext.mSlotID,
                                          extensionSetter_gtlContext_executeStepDoList) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionModifier_gtlContext_executeStepDoList (void) {
  gExtensionModifierTable_gtlContext_executeStepDoList.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_gtlContext_executeStepDoList (defineExtensionSetter_gtlContext_executeStepDoList,
                                                         freeExtensionModifier_gtlContext_executeStepDoList) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Extension setter '@gtlContext setBreakpoint'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionSetterSignature_gtlContext_setBreakpoint> gExtensionModifierTable_gtlContext_setBreakpoint ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_setBreakpoint (const int32_t inClassIndex,
                                         extensionSetterSignature_gtlContext_setBreakpoint inModifier) {
  gExtensionModifierTable_gtlContext_setBreakpoint.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_setBreakpoint (cPtr_gtlContext * inObject,
                                        const GALGAS_string constin_fileName,
                                        const GALGAS_uint constin_lineNum,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_gtlContext_setBreakpoint f = NULL ;
    if (classIndex < gExtensionModifierTable_gtlContext_setBreakpoint.count ()) {
      f = gExtensionModifierTable_gtlContext_setBreakpoint (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_gtlContext_setBreakpoint.count ()) {
           f = gExtensionModifierTable_gtlContext_setBreakpoint (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_gtlContext_setBreakpoint.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, constin_fileName, constin_lineNum, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_gtlContext_setBreakpoint (cPtr_gtlContext * inObject,
                                                      const GALGAS_string constinArgument_fileName,
                                                      const GALGAS_uint constinArgument_lineNum,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlContext * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlContext) ;
  {
  object->mProperty_debuggerContext.insulate (HERE) ;
  cPtr_debuggerContext * ptr_16429 = (cPtr_debuggerContext *) object->mProperty_debuggerContext.ptr () ;
  callExtensionSetter_setBreakpoint ((cPtr_debuggerContext *) ptr_16429, constinArgument_fileName, constinArgument_lineNum, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 528)) ;
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_gtlContext_setBreakpoint (void) {
  enterExtensionSetter_setBreakpoint (kTypeDescriptor_GALGAS_gtlContext.mSlotID,
                                      extensionSetter_gtlContext_setBreakpoint) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionModifier_gtlContext_setBreakpoint (void) {
  gExtensionModifierTable_gtlContext_setBreakpoint.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_gtlContext_setBreakpoint (defineExtensionSetter_gtlContext_setBreakpoint,
                                                     freeExtensionModifier_gtlContext_setBreakpoint) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Extension method '@gtlContext listBreakpoints'                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionMethodSignature_gtlContext_listBreakpoints> gExtensionMethodTable_gtlContext_listBreakpoints ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_listBreakpoints (const int32_t inClassIndex,
                                           extensionMethodSignature_gtlContext_listBreakpoints inMethod) {
  gExtensionMethodTable_gtlContext_listBreakpoints.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_listBreakpoints (const cPtr_gtlContext * inObject,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_gtlContext_listBreakpoints f = NULL ;
    if (classIndex < gExtensionMethodTable_gtlContext_listBreakpoints.count ()) {
      f = gExtensionMethodTable_gtlContext_listBreakpoints (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_gtlContext_listBreakpoints.count ()) {
           f = gExtensionMethodTable_gtlContext_listBreakpoints (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_gtlContext_listBreakpoints.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlContext_listBreakpoints (const cPtr_gtlContext * inObject,
                                                        C_Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlContext * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlContext) ;
  callExtensionMethod_listBreakpoints ((const cPtr_debuggerContext *) object->mProperty_debuggerContext.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 534)) ;
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlContext_listBreakpoints (void) {
  enterExtensionMethod_listBreakpoints (kTypeDescriptor_GALGAS_gtlContext.mSlotID,
                                        extensionMethod_gtlContext_listBreakpoints) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionMethod_gtlContext_listBreakpoints (void) {
  gExtensionMethodTable_gtlContext_listBreakpoints.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlContext_listBreakpoints (defineExtensionMethod_gtlContext_listBreakpoints,
                                                       freeExtensionMethod_gtlContext_listBreakpoints) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Extension setter '@gtlContext deleteBreakpoint'                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionSetterSignature_gtlContext_deleteBreakpoint> gExtensionModifierTable_gtlContext_deleteBreakpoint ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_deleteBreakpoint (const int32_t inClassIndex,
                                            extensionSetterSignature_gtlContext_deleteBreakpoint inModifier) {
  gExtensionModifierTable_gtlContext_deleteBreakpoint.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_deleteBreakpoint (cPtr_gtlContext * inObject,
                                           const GALGAS_lbigint constin_numToDelete,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_gtlContext_deleteBreakpoint f = NULL ;
    if (classIndex < gExtensionModifierTable_gtlContext_deleteBreakpoint.count ()) {
      f = gExtensionModifierTable_gtlContext_deleteBreakpoint (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_gtlContext_deleteBreakpoint.count ()) {
           f = gExtensionModifierTable_gtlContext_deleteBreakpoint (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_gtlContext_deleteBreakpoint.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, constin_numToDelete, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_gtlContext_deleteBreakpoint (cPtr_gtlContext * inObject,
                                                         const GALGAS_lbigint constinArgument_numToDelete,
                                                         C_Compiler * inCompiler
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlContext * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlContext) ;
  {
  object->mProperty_debuggerContext.insulate (HERE) ;
  cPtr_debuggerContext * ptr_16790 = (cPtr_debuggerContext *) object->mProperty_debuggerContext.ptr () ;
  callExtensionSetter_deleteBreakpoint ((cPtr_debuggerContext *) ptr_16790, constinArgument_numToDelete, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 541)) ;
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_gtlContext_deleteBreakpoint (void) {
  enterExtensionSetter_deleteBreakpoint (kTypeDescriptor_GALGAS_gtlContext.mSlotID,
                                         extensionSetter_gtlContext_deleteBreakpoint) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionModifier_gtlContext_deleteBreakpoint (void) {
  gExtensionModifierTable_gtlContext_deleteBreakpoint.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_gtlContext_deleteBreakpoint (defineExtensionSetter_gtlContext_deleteBreakpoint,
                                                        freeExtensionModifier_gtlContext_deleteBreakpoint) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Extension setter '@gtlContext deleteAllBreakpoints'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionSetterSignature_gtlContext_deleteAllBreakpoints> gExtensionModifierTable_gtlContext_deleteAllBreakpoints ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_deleteAllBreakpoints (const int32_t inClassIndex,
                                                extensionSetterSignature_gtlContext_deleteAllBreakpoints inModifier) {
  gExtensionModifierTable_gtlContext_deleteAllBreakpoints.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_deleteAllBreakpoints (cPtr_gtlContext * inObject,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_gtlContext_deleteAllBreakpoints f = NULL ;
    if (classIndex < gExtensionModifierTable_gtlContext_deleteAllBreakpoints.count ()) {
      f = gExtensionModifierTable_gtlContext_deleteAllBreakpoints (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_gtlContext_deleteAllBreakpoints.count ()) {
           f = gExtensionModifierTable_gtlContext_deleteAllBreakpoints (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_gtlContext_deleteAllBreakpoints.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_gtlContext_deleteAllBreakpoints (cPtr_gtlContext * inObject,
                                                             C_Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlContext * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlContext) ;
  {
  object->mProperty_debuggerContext.insulate (HERE) ;
  cPtr_debuggerContext * ptr_16967 = (cPtr_debuggerContext *) object->mProperty_debuggerContext.ptr () ;
  callExtensionSetter_deleteAllBreakpoints ((cPtr_debuggerContext *) ptr_16967, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 547)) ;
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_gtlContext_deleteAllBreakpoints (void) {
  enterExtensionSetter_deleteAllBreakpoints (kTypeDescriptor_GALGAS_gtlContext.mSlotID,
                                             extensionSetter_gtlContext_deleteAllBreakpoints) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionModifier_gtlContext_deleteAllBreakpoints (void) {
  gExtensionModifierTable_gtlContext_deleteAllBreakpoints.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_gtlContext_deleteAllBreakpoints (defineExtensionSetter_gtlContext_deleteAllBreakpoints,
                                                            freeExtensionModifier_gtlContext_deleteAllBreakpoints) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Extension setter '@gtlContext setWatchpoint'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionSetterSignature_gtlContext_setWatchpoint> gExtensionModifierTable_gtlContext_setWatchpoint ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_setWatchpoint (const int32_t inClassIndex,
                                         extensionSetterSignature_gtlContext_setWatchpoint inModifier) {
  gExtensionModifierTable_gtlContext_setWatchpoint.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_setWatchpoint (cPtr_gtlContext * inObject,
                                        const GALGAS_gtlExpression constin_watchExpression,
                                        C_Compiler * inCompiler
                                        COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_gtlContext_setWatchpoint f = NULL ;
    if (classIndex < gExtensionModifierTable_gtlContext_setWatchpoint.count ()) {
      f = gExtensionModifierTable_gtlContext_setWatchpoint (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_gtlContext_setWatchpoint.count ()) {
           f = gExtensionModifierTable_gtlContext_setWatchpoint (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_gtlContext_setWatchpoint.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, constin_watchExpression, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_gtlContext_setWatchpoint (cPtr_gtlContext * inObject,
                                                      const GALGAS_gtlExpression constinArgument_watchExpression,
                                                      C_Compiler * inCompiler
                                                      COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlContext * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlContext) ;
  {
  object->mProperty_debuggerContext.insulate (HERE) ;
  cPtr_debuggerContext * ptr_17166 = (cPtr_debuggerContext *) object->mProperty_debuggerContext.ptr () ;
  callExtensionSetter_setWatchpoint ((cPtr_debuggerContext *) ptr_17166, constinArgument_watchExpression, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 554)) ;
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_gtlContext_setWatchpoint (void) {
  enterExtensionSetter_setWatchpoint (kTypeDescriptor_GALGAS_gtlContext.mSlotID,
                                      extensionSetter_gtlContext_setWatchpoint) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionModifier_gtlContext_setWatchpoint (void) {
  gExtensionModifierTable_gtlContext_setWatchpoint.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_gtlContext_setWatchpoint (defineExtensionSetter_gtlContext_setWatchpoint,
                                                     freeExtensionModifier_gtlContext_setWatchpoint) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Extension method '@gtlContext listWatchpoints'                                    *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionMethodSignature_gtlContext_listWatchpoints> gExtensionMethodTable_gtlContext_listWatchpoints ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_listWatchpoints (const int32_t inClassIndex,
                                           extensionMethodSignature_gtlContext_listWatchpoints inMethod) {
  gExtensionMethodTable_gtlContext_listWatchpoints.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_listWatchpoints (const cPtr_gtlContext * inObject,
                                          C_Compiler * inCompiler
                                          COMMA_LOCATION_ARGS) {
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_gtlContext_listWatchpoints f = NULL ;
    if (classIndex < gExtensionMethodTable_gtlContext_listWatchpoints.count ()) {
      f = gExtensionMethodTable_gtlContext_listWatchpoints (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_gtlContext_listWatchpoints.count ()) {
           f = gExtensionMethodTable_gtlContext_listWatchpoints (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_gtlContext_listWatchpoints.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlContext_listWatchpoints (const cPtr_gtlContext * inObject,
                                                        C_Compiler * inCompiler
                                                        COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlContext * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlContext) ;
  callExtensionMethod_listWatchpoints ((const cPtr_debuggerContext *) object->mProperty_debuggerContext.ptr (), inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 560)) ;
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlContext_listWatchpoints (void) {
  enterExtensionMethod_listWatchpoints (kTypeDescriptor_GALGAS_gtlContext.mSlotID,
                                        extensionMethod_gtlContext_listWatchpoints) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionMethod_gtlContext_listWatchpoints (void) {
  gExtensionMethodTable_gtlContext_listWatchpoints.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlContext_listWatchpoints (defineExtensionMethod_gtlContext_listWatchpoints,
                                                       freeExtensionMethod_gtlContext_listWatchpoints) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Extension setter '@gtlContext deleteWatchpoint'                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionSetterSignature_gtlContext_deleteWatchpoint> gExtensionModifierTable_gtlContext_deleteWatchpoint ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_deleteWatchpoint (const int32_t inClassIndex,
                                            extensionSetterSignature_gtlContext_deleteWatchpoint inModifier) {
  gExtensionModifierTable_gtlContext_deleteWatchpoint.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_deleteWatchpoint (cPtr_gtlContext * inObject,
                                           const GALGAS_lbigint constin_numToDelete,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_gtlContext_deleteWatchpoint f = NULL ;
    if (classIndex < gExtensionModifierTable_gtlContext_deleteWatchpoint.count ()) {
      f = gExtensionModifierTable_gtlContext_deleteWatchpoint (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_gtlContext_deleteWatchpoint.count ()) {
           f = gExtensionModifierTable_gtlContext_deleteWatchpoint (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_gtlContext_deleteWatchpoint.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, constin_numToDelete, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_gtlContext_deleteWatchpoint (cPtr_gtlContext * inObject,
                                                         const GALGAS_lbigint constinArgument_numToDelete,
                                                         C_Compiler * inCompiler
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlContext * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlContext) ;
  {
  object->mProperty_debuggerContext.insulate (HERE) ;
  cPtr_debuggerContext * ptr_17525 = (cPtr_debuggerContext *) object->mProperty_debuggerContext.ptr () ;
  callExtensionSetter_deleteWatchpoint ((cPtr_debuggerContext *) ptr_17525, constinArgument_numToDelete, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 567)) ;
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_gtlContext_deleteWatchpoint (void) {
  enterExtensionSetter_deleteWatchpoint (kTypeDescriptor_GALGAS_gtlContext.mSlotID,
                                         extensionSetter_gtlContext_deleteWatchpoint) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionModifier_gtlContext_deleteWatchpoint (void) {
  gExtensionModifierTable_gtlContext_deleteWatchpoint.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_gtlContext_deleteWatchpoint (defineExtensionSetter_gtlContext_deleteWatchpoint,
                                                        freeExtensionModifier_gtlContext_deleteWatchpoint) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Extension setter '@gtlContext deleteAllWatchpoints'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionSetterSignature_gtlContext_deleteAllWatchpoints> gExtensionModifierTable_gtlContext_deleteAllWatchpoints ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_deleteAllWatchpoints (const int32_t inClassIndex,
                                                extensionSetterSignature_gtlContext_deleteAllWatchpoints inModifier) {
  gExtensionModifierTable_gtlContext_deleteAllWatchpoints.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_deleteAllWatchpoints (cPtr_gtlContext * inObject,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_gtlContext_deleteAllWatchpoints f = NULL ;
    if (classIndex < gExtensionModifierTable_gtlContext_deleteAllWatchpoints.count ()) {
      f = gExtensionModifierTable_gtlContext_deleteAllWatchpoints (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_gtlContext_deleteAllWatchpoints.count ()) {
           f = gExtensionModifierTable_gtlContext_deleteAllWatchpoints (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_gtlContext_deleteAllWatchpoints.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_gtlContext_deleteAllWatchpoints (cPtr_gtlContext * inObject,
                                                             C_Compiler * inCompiler
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlContext * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlContext) ;
  {
  object->mProperty_debuggerContext.insulate (HERE) ;
  cPtr_debuggerContext * ptr_17702 = (cPtr_debuggerContext *) object->mProperty_debuggerContext.ptr () ;
  callExtensionSetter_deleteAllWatchpoints ((cPtr_debuggerContext *) ptr_17702, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 573)) ;
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_gtlContext_deleteAllWatchpoints (void) {
  enterExtensionSetter_deleteAllWatchpoints (kTypeDescriptor_GALGAS_gtlContext.mSlotID,
                                             extensionSetter_gtlContext_deleteAllWatchpoints) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionModifier_gtlContext_deleteAllWatchpoints (void) {
  gExtensionModifierTable_gtlContext_deleteAllWatchpoints.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_gtlContext_deleteAllWatchpoints (defineExtensionSetter_gtlContext_deleteAllWatchpoints,
                                                            freeExtensionModifier_gtlContext_deleteAllWatchpoints) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                   Extension setter '@gtlContext setLoopOnCommand'                                   *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionSetterSignature_gtlContext_setLoopOnCommand> gExtensionModifierTable_gtlContext_setLoopOnCommand ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_setLoopOnCommand (const int32_t inClassIndex,
                                            extensionSetterSignature_gtlContext_setLoopOnCommand inModifier) {
  gExtensionModifierTable_gtlContext_setLoopOnCommand.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_setLoopOnCommand (cPtr_gtlContext * inObject,
                                           GALGAS_bool in_loopOnCommand,
                                           C_Compiler * inCompiler
                                           COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_gtlContext_setLoopOnCommand f = NULL ;
    if (classIndex < gExtensionModifierTable_gtlContext_setLoopOnCommand.count ()) {
      f = gExtensionModifierTable_gtlContext_setLoopOnCommand (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_gtlContext_setLoopOnCommand.count ()) {
           f = gExtensionModifierTable_gtlContext_setLoopOnCommand (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_gtlContext_setLoopOnCommand.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, in_loopOnCommand, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_gtlContext_setLoopOnCommand (cPtr_gtlContext * inObject,
                                                         GALGAS_bool inArgument_loopOnCommand,
                                                         C_Compiler * /* inCompiler */
                                                         COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlContext * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlContext) ;
  {
  object->mProperty_debuggerContext.setter_setLoopOnCommand (inArgument_loopOnCommand COMMA_SOURCE_FILE ("gtl_debugger.galgas", 580)) ;
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_gtlContext_setLoopOnCommand (void) {
  enterExtensionSetter_setLoopOnCommand (kTypeDescriptor_GALGAS_gtlContext.mSlotID,
                                         extensionSetter_gtlContext_setLoopOnCommand) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionModifier_gtlContext_setLoopOnCommand (void) {
  gExtensionModifierTable_gtlContext_setLoopOnCommand.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_gtlContext_setLoopOnCommand (defineExtensionSetter_gtlContext_setLoopOnCommand,
                                                        freeExtensionModifier_gtlContext_setLoopOnCommand) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                    Extension getter '@gtlContext loopOnCommand'                                     *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_gtlContext_loopOnCommand> gExtensionGetterTable_gtlContext_loopOnCommand ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_loopOnCommand (const int32_t inClassIndex,
                                         enterExtensionGetter_gtlContext_loopOnCommand inGetter) {
  gExtensionGetterTable_gtlContext_loopOnCommand.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_bool callExtensionGetter_loopOnCommand (const cPtr_gtlContext * inObject,
                                               C_Compiler * inCompiler
                                               COMMA_LOCATION_ARGS) {
  GALGAS_bool result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_gtlContext_loopOnCommand f = NULL ;
    if (classIndex < gExtensionGetterTable_gtlContext_loopOnCommand.count ()) {
      f = gExtensionGetterTable_gtlContext_loopOnCommand (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_gtlContext_loopOnCommand.count ()) {
           f = gExtensionGetterTable_gtlContext_loopOnCommand (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_gtlContext_loopOnCommand.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_bool extensionGetter_gtlContext_loopOnCommand (const cPtr_gtlContext * inObject,
                                                             C_Compiler * /* inCompiler */
                                                             COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_bool result_loopOnCommand ; // Returned variable
  const cPtr_gtlContext * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlContext) ;
  result_loopOnCommand = object->mProperty_debuggerContext.getter_loopOnCommand (SOURCE_FILE ("gtl_debugger.galgas", 587)) ;
//---
  return result_loopOnCommand ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_gtlContext_loopOnCommand (void) {
  enterExtensionGetter_loopOnCommand (kTypeDescriptor_GALGAS_gtlContext.mSlotID,
                                      extensionGetter_gtlContext_loopOnCommand) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_gtlContext_loopOnCommand (void) {
  gExtensionGetterTable_gtlContext_loopOnCommand.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_gtlContext_loopOnCommand (defineExtensionGetter_gtlContext_loopOnCommand,
                                                     freeExtensionGetter_gtlContext_loopOnCommand) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Extension method '@gtlContext hereWeAre'                                       *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionMethodSignature_gtlContext_hereWeAre> gExtensionMethodTable_gtlContext_hereWeAre ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_hereWeAre (const int32_t inClassIndex,
                                     extensionMethodSignature_gtlContext_hereWeAre inMethod) {
  gExtensionMethodTable_gtlContext_hereWeAre.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_hereWeAre (const cPtr_gtlContext * inObject,
                                    const GALGAS_uint constin_window,
                                    C_Compiler * inCompiler
                                    COMMA_LOCATION_ARGS) {
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_gtlContext_hereWeAre f = NULL ;
    if (classIndex < gExtensionMethodTable_gtlContext_hereWeAre.count ()) {
      f = gExtensionMethodTable_gtlContext_hereWeAre (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_gtlContext_hereWeAre.count ()) {
           f = gExtensionMethodTable_gtlContext_hereWeAre (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_gtlContext_hereWeAre.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, constin_window, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_gtlContext_hereWeAre (const cPtr_gtlContext * inObject,
                                                  const GALGAS_uint constinArgument_window,
                                                  C_Compiler * inCompiler
                                                  COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_gtlContext * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlContext) ;
  callExtensionMethod_hereWeAre ((const cPtr_debuggerContext *) object->mProperty_debuggerContext.ptr (), constinArgument_window, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 594)) ;
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_gtlContext_hereWeAre (void) {
  enterExtensionMethod_hereWeAre (kTypeDescriptor_GALGAS_gtlContext.mSlotID,
                                  extensionMethod_gtlContext_hereWeAre) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionMethod_gtlContext_hereWeAre (void) {
  gExtensionMethodTable_gtlContext_hereWeAre.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_gtlContext_hereWeAre (defineExtensionMethod_gtlContext_hereWeAre,
                                                 freeExtensionMethod_gtlContext_hereWeAre) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                 Extension setter '@gtlContext pushInstructionList'                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionSetterSignature_gtlContext_pushInstructionList> gExtensionModifierTable_gtlContext_pushInstructionList ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_pushInstructionList (const int32_t inClassIndex,
                                               extensionSetterSignature_gtlContext_pushInstructionList inModifier) {
  gExtensionModifierTable_gtlContext_pushInstructionList.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_pushInstructionList (cPtr_gtlContext * inObject,
                                              const GALGAS_gtlInstructionList constin_instructionList,
                                              C_Compiler * inCompiler
                                              COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_gtlContext_pushInstructionList f = NULL ;
    if (classIndex < gExtensionModifierTable_gtlContext_pushInstructionList.count ()) {
      f = gExtensionModifierTable_gtlContext_pushInstructionList (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_gtlContext_pushInstructionList.count ()) {
           f = gExtensionModifierTable_gtlContext_pushInstructionList (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_gtlContext_pushInstructionList.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, constin_instructionList, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_gtlContext_pushInstructionList (cPtr_gtlContext * inObject,
                                                            const GALGAS_gtlInstructionList constinArgument_instructionList,
                                                            C_Compiler * inCompiler
                                                            COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlContext * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlContext) ;
  {
  object->mProperty_debuggerContext.insulate (HERE) ;
  cPtr_debuggerContext * ptr_18474 = (cPtr_debuggerContext *) object->mProperty_debuggerContext.ptr () ;
  callExtensionSetter_pushInstructionList ((cPtr_debuggerContext *) ptr_18474, constinArgument_instructionList, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 601)) ;
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_gtlContext_pushInstructionList (void) {
  enterExtensionSetter_pushInstructionList (kTypeDescriptor_GALGAS_gtlContext.mSlotID,
                                            extensionSetter_gtlContext_pushInstructionList) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionModifier_gtlContext_pushInstructionList (void) {
  gExtensionModifierTable_gtlContext_pushInstructionList.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_gtlContext_pushInstructionList (defineExtensionSetter_gtlContext_pushInstructionList,
                                                           freeExtensionModifier_gtlContext_pushInstructionList) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                  Extension setter '@gtlContext popInstructionList'                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionSetterSignature_gtlContext_popInstructionList> gExtensionModifierTable_gtlContext_popInstructionList ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_popInstructionList (const int32_t inClassIndex,
                                              extensionSetterSignature_gtlContext_popInstructionList inModifier) {
  gExtensionModifierTable_gtlContext_popInstructionList.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_popInstructionList (cPtr_gtlContext * inObject,
                                             C_Compiler * inCompiler
                                             COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_gtlContext_popInstructionList f = NULL ;
    if (classIndex < gExtensionModifierTable_gtlContext_popInstructionList.count ()) {
      f = gExtensionModifierTable_gtlContext_popInstructionList (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_gtlContext_popInstructionList.count ()) {
           f = gExtensionModifierTable_gtlContext_popInstructionList (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_gtlContext_popInstructionList.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_gtlContext_popInstructionList (cPtr_gtlContext * inObject,
                                                           C_Compiler * inCompiler
                                                           COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlContext * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlContext) ;
  {
  object->mProperty_debuggerContext.insulate (HERE) ;
  cPtr_debuggerContext * ptr_18656 = (cPtr_debuggerContext *) object->mProperty_debuggerContext.ptr () ;
  callExtensionSetter_popInstructionList ((cPtr_debuggerContext *) ptr_18656, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 607)) ;
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_gtlContext_popInstructionList (void) {
  enterExtensionSetter_popInstructionList (kTypeDescriptor_GALGAS_gtlContext.mSlotID,
                                           extensionSetter_gtlContext_popInstructionList) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionModifier_gtlContext_popInstructionList (void) {
  gExtensionModifierTable_gtlContext_popInstructionList.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_gtlContext_popInstructionList (defineExtensionSetter_gtlContext_popInstructionList,
                                                          freeExtensionModifier_gtlContext_popInstructionList) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               Extension setter '@gtlContext setNextInstructionIndex'                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionSetterSignature_gtlContext_setNextInstructionIndex> gExtensionModifierTable_gtlContext_setNextInstructionIndex ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_setNextInstructionIndex (const int32_t inClassIndex,
                                                   extensionSetterSignature_gtlContext_setNextInstructionIndex inModifier) {
  gExtensionModifierTable_gtlContext_setNextInstructionIndex.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_setNextInstructionIndex (cPtr_gtlContext * inObject,
                                                  GALGAS_uint in_index,
                                                  C_Compiler * inCompiler
                                                  COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_gtlContext_setNextInstructionIndex f = NULL ;
    if (classIndex < gExtensionModifierTable_gtlContext_setNextInstructionIndex.count ()) {
      f = gExtensionModifierTable_gtlContext_setNextInstructionIndex (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_gtlContext_setNextInstructionIndex.count ()) {
           f = gExtensionModifierTable_gtlContext_setNextInstructionIndex (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_gtlContext_setNextInstructionIndex.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, in_index, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_gtlContext_setNextInstructionIndex (cPtr_gtlContext * inObject,
                                                                GALGAS_uint inArgument_index,
                                                                C_Compiler * /* inCompiler */
                                                                COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlContext * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlContext) ;
  {
  object->mProperty_debuggerContext.setter_setNextInstructionIndex (inArgument_index COMMA_SOURCE_FILE ("gtl_debugger.galgas", 614)) ;
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_gtlContext_setNextInstructionIndex (void) {
  enterExtensionSetter_setNextInstructionIndex (kTypeDescriptor_GALGAS_gtlContext.mSlotID,
                                                extensionSetter_gtlContext_setNextInstructionIndex) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionModifier_gtlContext_setNextInstructionIndex (void) {
  gExtensionModifierTable_gtlContext_setNextInstructionIndex.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_gtlContext_setNextInstructionIndex (defineExtensionSetter_gtlContext_setNextInstructionIndex,
                                                               freeExtensionModifier_gtlContext_setNextInstructionIndex) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                              Extension setter '@gtlContext setExecuteDebuggerCommand'                               *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionSetterSignature_gtlContext_setExecuteDebuggerCommand> gExtensionModifierTable_gtlContext_setExecuteDebuggerCommand ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_setExecuteDebuggerCommand (const int32_t inClassIndex,
                                                     extensionSetterSignature_gtlContext_setExecuteDebuggerCommand inModifier) {
  gExtensionModifierTable_gtlContext_setExecuteDebuggerCommand.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_setExecuteDebuggerCommand (cPtr_gtlContext * inObject,
                                                    GALGAS_bool in_debuggerCommand,
                                                    C_Compiler * inCompiler
                                                    COMMA_LOCATION_ARGS) {
//--- Drop output arguments
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_gtlContext_setExecuteDebuggerCommand f = NULL ;
    if (classIndex < gExtensionModifierTable_gtlContext_setExecuteDebuggerCommand.count ()) {
      f = gExtensionModifierTable_gtlContext_setExecuteDebuggerCommand (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_gtlContext_setExecuteDebuggerCommand.count ()) {
           f = gExtensionModifierTable_gtlContext_setExecuteDebuggerCommand (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_gtlContext_setExecuteDebuggerCommand.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, in_debuggerCommand, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_gtlContext_setExecuteDebuggerCommand (cPtr_gtlContext * inObject,
                                                                  GALGAS_bool inArgument_debuggerCommand,
                                                                  C_Compiler * /* inCompiler */
                                                                  COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlContext * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlContext) ;
  {
  object->mProperty_debuggerContext.setter_setExecuteDebuggerCommand (inArgument_debuggerCommand COMMA_SOURCE_FILE ("gtl_debugger.galgas", 621)) ;
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_gtlContext_setExecuteDebuggerCommand (void) {
  enterExtensionSetter_setExecuteDebuggerCommand (kTypeDescriptor_GALGAS_gtlContext.mSlotID,
                                                  extensionSetter_gtlContext_setExecuteDebuggerCommand) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionModifier_gtlContext_setExecuteDebuggerCommand (void) {
  gExtensionModifierTable_gtlContext_setExecuteDebuggerCommand.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_gtlContext_setExecuteDebuggerCommand (defineExtensionSetter_gtlContext_setExecuteDebuggerCommand,
                                                                 freeExtensionModifier_gtlContext_setExecuteDebuggerCommand) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                      Extension setter '@gtlContext getCommand'                                      *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionSetterSignature_gtlContext_getCommand> gExtensionModifierTable_gtlContext_getCommand ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionSetter_getCommand (const int32_t inClassIndex,
                                      extensionSetterSignature_gtlContext_getCommand inModifier) {
  gExtensionModifierTable_gtlContext_getCommand.forceObjectAtIndex (inClassIndex, inModifier, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionSetter_getCommand (cPtr_gtlContext * inObject,
                                     GALGAS_string & out_command,
                                     C_Compiler * inCompiler
                                     COMMA_LOCATION_ARGS) {
//--- Drop output arguments
  out_command.drop () ;
//--- Find setter
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_gtlContext) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionSetterSignature_gtlContext_getCommand f = NULL ;
    if (classIndex < gExtensionModifierTable_gtlContext_getCommand.count ()) {
      f = gExtensionModifierTable_gtlContext_getCommand (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionModifierTable_gtlContext_getCommand.count ()) {
           f = gExtensionModifierTable_gtlContext_getCommand (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionModifierTable_gtlContext_getCommand.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    f (inObject, out_command, inCompiler COMMA_THERE) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionSetter_gtlContext_getCommand (cPtr_gtlContext * inObject,
                                                   GALGAS_string & outArgument_command,
                                                   C_Compiler * inCompiler
                                                   COMMA_UNUSED_LOCATION_ARGS) {
  cPtr_gtlContext * object = inObject ;
  macroValidSharedObject (object, cPtr_gtlContext) ;
  {
  object->mProperty_debuggerContext.insulate (HERE) ;
  cPtr_debuggerContext * ptr_19247 = (cPtr_debuggerContext *) object->mProperty_debuggerContext.ptr () ;
  callExtensionSetter_getCommand ((cPtr_debuggerContext *) ptr_19247, outArgument_command, inCompiler COMMA_SOURCE_FILE ("gtl_debugger.galgas", 628)) ;
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionSetter_gtlContext_getCommand (void) {
  enterExtensionSetter_getCommand (kTypeDescriptor_GALGAS_gtlContext.mSlotID,
                                   extensionSetter_gtlContext_getCommand) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionModifier_gtlContext_getCommand (void) {
  gExtensionModifierTable_gtlContext_getCommand.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gSetter_gtlContext_getCommand (defineExtensionSetter_gtlContext_getCommand,
                                                  freeExtensionModifier_gtlContext_getCommand) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                               Extension getter '@applicationDefinition templateData'                                *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <enterExtensionGetter_applicationDefinition_templateData> gExtensionGetterTable_applicationDefinition_templateData ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionGetter_templateData (const int32_t inClassIndex,
                                        enterExtensionGetter_applicationDefinition_templateData inGetter) {
  gExtensionGetterTable_applicationDefinition_templateData.forceObjectAtIndex (inClassIndex, inGetter, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_gtlData callExtensionGetter_templateData (const cPtr_applicationDefinition * inObject,
                                                 const GALGAS_implementation in_imp,
                                                 C_Compiler * inCompiler
                                                 COMMA_LOCATION_ARGS) {
  GALGAS_gtlData result ;
//--- Find Reader
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_applicationDefinition) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    enterExtensionGetter_applicationDefinition_templateData f = NULL ;
    if (classIndex < gExtensionGetterTable_applicationDefinition_templateData.count ()) {
      f = gExtensionGetterTable_applicationDefinition_templateData (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionGetterTable_applicationDefinition_templateData.count ()) {
           f = gExtensionGetterTable_applicationDefinition_templateData (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionGetterTable_applicationDefinition_templateData.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY READER CALL ERROR", __FILE__, __LINE__) ;
    }else{
      result = f (inObject, in_imp, inCompiler COMMA_THERE) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

static GALGAS_gtlData extensionGetter_applicationDefinition_templateData (const cPtr_applicationDefinition * inObject,
                                                                          const GALGAS_implementation constinArgument_imp,
                                                                          C_Compiler * inCompiler
                                                                          COMMA_UNUSED_LOCATION_ARGS) {
  GALGAS_gtlData result_cfg ; // Returned variable
  const cPtr_applicationDefinition * object = inObject ;
  macroValidSharedObject (object, cPtr_applicationDefinition) ;
  result_cfg = GALGAS_gtlStruct::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 190)), function_emptylstring (inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 190)), GALGAS_gtlVarMap::constructor_emptyMap (SOURCE_FILE ("systemConfig.galgas", 190))  COMMA_SOURCE_FILE ("systemConfig.galgas", 190)) ;
  {
  result_cfg.insulate (HERE) ;
  cPtr_gtlData * ptr_5806 = (cPtr_gtlData *) result_cfg.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_5806, GALGAS_lstring::constructor_new (GALGAS_string ("OILFILENAME"), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 196))  COMMA_SOURCE_FILE ("systemConfig.galgas", 196)), GALGAS_gtlString::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 198)), function_lstring (GALGAS_string::constructor_stringWithSourceFilePath (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 199)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 199)), GALGAS_string::constructor_stringWithSourceFilePath (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 200)).getter_lastPathComponent (SOURCE_FILE ("systemConfig.galgas", 200))  COMMA_SOURCE_FILE ("systemConfig.galgas", 197)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 195)) ;
  }
  {
  result_cfg.insulate (HERE) ;
  cPtr_gtlData * ptr_6031 = (cPtr_gtlData *) result_cfg.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_6031, GALGAS_lstring::constructor_new (GALGAS_string ("CPUNAME"), object->mProperty_name.getter_location (SOURCE_FILE ("systemConfig.galgas", 205))  COMMA_SOURCE_FILE ("systemConfig.galgas", 205)), GALGAS_gtlString::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 206)), function_lstring (GALGAS_string ("name of the CPU object"), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 206)), object->mProperty_name.getter_string (SOURCE_FILE ("systemConfig.galgas", 206))  COMMA_SOURCE_FILE ("systemConfig.galgas", 206)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 204)) ;
  }
  {
  result_cfg.insulate (HERE) ;
  cPtr_gtlData * ptr_6185 = (cPtr_gtlData *) result_cfg.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_6185, GALGAS_lstring::constructor_new (GALGAS_string ("CPUDESCRIPTION"), object->mProperty_cpuDescription.getter_location (SOURCE_FILE ("systemConfig.galgas", 210))  COMMA_SOURCE_FILE ("systemConfig.galgas", 210)), GALGAS_gtlString::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 211)), function_lstring (GALGAS_string ("description of the CPU object"), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 211)), object->mProperty_cpuDescription.getter_string (SOURCE_FILE ("systemConfig.galgas", 211))  COMMA_SOURCE_FILE ("systemConfig.galgas", 211)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 209)) ;
  }
  {
  result_cfg.insulate (HERE) ;
  cPtr_gtlData * ptr_6373 = (cPtr_gtlData *) result_cfg.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_6373, GALGAS_lstring::constructor_new (GALGAS_string ("OILVERSION"), object->mProperty_version.getter_location (SOURCE_FILE ("systemConfig.galgas", 215))  COMMA_SOURCE_FILE ("systemConfig.galgas", 215)), GALGAS_gtlString::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 216)), object->mProperty_versionDescription, object->mProperty_version.getter_string (SOURCE_FILE ("systemConfig.galgas", 216))  COMMA_SOURCE_FILE ("systemConfig.galgas", 216)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 214)) ;
  }
  {
  result_cfg.insulate (HERE) ;
  cPtr_gtlData * ptr_6519 = (cPtr_gtlData *) result_cfg.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_6519, GALGAS_lstring::constructor_new (GALGAS_string ("OILDESCRIPTION"), object->mProperty_versionDescription.getter_location (SOURCE_FILE ("systemConfig.galgas", 220))  COMMA_SOURCE_FILE ("systemConfig.galgas", 220)), GALGAS_gtlString::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 221)), object->mProperty_versionDescription, object->mProperty_versionDescription.getter_string (SOURCE_FILE ("systemConfig.galgas", 221))  COMMA_SOURCE_FILE ("systemConfig.galgas", 221)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 219)) ;
  }
  {
  result_cfg.insulate (HERE) ;
  cPtr_gtlData * ptr_6691 = (cPtr_gtlData *) result_cfg.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_6691, GALGAS_lstring::constructor_new (GALGAS_string ("TIMESTAMP"), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 225))  COMMA_SOURCE_FILE ("systemConfig.galgas", 225)), GALGAS_gtlString::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 227)), function_lstring (GALGAS_string ("timestamp of OIL compiling"), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 228)), GALGAS_string::constructor_stringWithCurrentDateTime (SOURCE_FILE ("systemConfig.galgas", 229))  COMMA_SOURCE_FILE ("systemConfig.galgas", 226)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 224)) ;
  }
  {
  result_cfg.insulate (HERE) ;
  cPtr_gtlData * ptr_6896 = (cPtr_gtlData *) result_cfg.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_6896, GALGAS_lstring::constructor_new (GALGAS_string ("PROJECT"), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 234))  COMMA_SOURCE_FILE ("systemConfig.galgas", 234)), GALGAS_gtlString::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 236)), function_lstring (GALGAS_string ("project name"), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 237)), function_projectName (inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 238)).getter_lastPathComponent (SOURCE_FILE ("systemConfig.galgas", 238))  COMMA_SOURCE_FILE ("systemConfig.galgas", 235)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 233)) ;
  }
  {
  result_cfg.insulate (HERE) ;
  cPtr_gtlData * ptr_7086 = (cPtr_gtlData *) result_cfg.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_7086, GALGAS_lstring::constructor_new (GALGAS_string ("TARGET"), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 243))  COMMA_SOURCE_FILE ("systemConfig.galgas", 243)), GALGAS_gtlString::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 245)), function_lstring (GALGAS_string ("target architecture/chip/board"), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 246)), GALGAS_string (gOption_goil_5F_options_target_5F_platform.getter_value ())  COMMA_SOURCE_FILE ("systemConfig.galgas", 244)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 242)) ;
  }
  {
  result_cfg.insulate (HERE) ;
  cPtr_gtlData * ptr_7300 = (cPtr_gtlData *) result_cfg.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_7300, GALGAS_lstring::constructor_new (GALGAS_string ("TEMPLATEPATH"), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 252))  COMMA_SOURCE_FILE ("systemConfig.galgas", 252)), GALGAS_gtlString::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 254)), function_lstring (GALGAS_string ("path of the templates used"), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 255)), GALGAS_string (gOption_goil_5F_options_template_5F_dir.getter_value ())  COMMA_SOURCE_FILE ("systemConfig.galgas", 253)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 251)) ;
  }
  {
  result_cfg.insulate (HERE) ;
  cPtr_gtlData * ptr_7515 = (cPtr_gtlData *) result_cfg.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_7515, GALGAS_lstring::constructor_new (GALGAS_string ("ARCH"), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 261))  COMMA_SOURCE_FILE ("systemConfig.galgas", 261)), GALGAS_gtlString::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 262)), function_lstring (GALGAS_string ("target architecture"), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 262)), function_arch (inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 262))  COMMA_SOURCE_FILE ("systemConfig.galgas", 262)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 260)) ;
  }
  {
  result_cfg.insulate (HERE) ;
  cPtr_gtlData * ptr_7656 = (cPtr_gtlData *) result_cfg.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_7656, GALGAS_lstring::constructor_new (GALGAS_string ("CHIP"), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 266))  COMMA_SOURCE_FILE ("systemConfig.galgas", 266)), GALGAS_gtlString::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 267)), function_lstring (GALGAS_string ("target chip"), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 267)), function_chip (inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 267))  COMMA_SOURCE_FILE ("systemConfig.galgas", 267)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 265)) ;
  }
  {
  result_cfg.insulate (HERE) ;
  cPtr_gtlData * ptr_7788 = (cPtr_gtlData *) result_cfg.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_7788, GALGAS_lstring::constructor_new (GALGAS_string ("BOARD"), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 271))  COMMA_SOURCE_FILE ("systemConfig.galgas", 271)), GALGAS_gtlString::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 272)), function_lstring (GALGAS_string ("target board"), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 272)), function_board (inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 272))  COMMA_SOURCE_FILE ("systemConfig.galgas", 272)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 270)) ;
  }
  {
  result_cfg.insulate (HERE) ;
  cPtr_gtlData * ptr_7923 = (cPtr_gtlData *) result_cfg.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_7923, GALGAS_lstring::constructor_new (GALGAS_string ("TARGETPATHLIST"), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 276))  COMMA_SOURCE_FILE ("systemConfig.galgas", 276)), GALGAS_gtlList::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 277)), function_lstring (GALGAS_string ("target path list"), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 277)), function_targetPathList (inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 277))  COMMA_SOURCE_FILE ("systemConfig.galgas", 277)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 275)) ;
  }
  {
  result_cfg.insulate (HERE) ;
  cPtr_gtlData * ptr_8079 = (cPtr_gtlData *) result_cfg.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_8079, GALGAS_lstring::constructor_new (GALGAS_string ("LOGFILE"), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 281))  COMMA_SOURCE_FILE ("systemConfig.galgas", 281)), GALGAS_gtlBool::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 283)), function_lstring (GALGAS_string ("Generated a logfile"), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 284)), GALGAS_bool (gOption_goil_5F_options_generate_5F_log.getter_value ())  COMMA_SOURCE_FILE ("systemConfig.galgas", 282)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 280)) ;
  }
  GALGAS_gtlData var_opts_8311 = GALGAS_gtlStruct::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 291)), function_lstring (GALGAS_string ("Passed options"), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 292)), GALGAS_gtlVarMap::constructor_emptyMap (SOURCE_FILE ("systemConfig.galgas", 293))  COMMA_SOURCE_FILE ("systemConfig.galgas", 290)) ;
  GALGAS_string var_optionString_8416 = extensionGetter_trimRight (extensionGetter_trimLeft (GALGAS_string (gOption_goil_5F_options_passOption.getter_value ()), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 295)), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 295)) ;
  GALGAS_bool test_0 = GALGAS_bool (kIsStrictSup, var_optionString_8416.getter_length (SOURCE_FILE ("systemConfig.galgas", 296)).objectCompare (GALGAS_uint ((uint32_t) 0U))) ;
  if (kBoolTrue != test_0.boolEnum ()) {
    test_0 = GALGAS_bool (gOption_goil_5F_options_pierreOption.getter_value ()) ;
  }
  const enumGalgasBool test_1 = test_0.boolEnum () ;
  if (kBoolTrue == test_1) {
    var_opts_8311.drop () ;
    cGrammar_options_5F_grammar::_performSourceStringParsing_ (inCompiler, GALGAS_string (gOption_goil_5F_options_passOption.getter_value ()), GALGAS_string ("Passed options"), var_opts_8311  COMMA_SOURCE_FILE ("systemConfig.galgas", 297)) ;
  }
  {
  result_cfg.insulate (HERE) ;
  cPtr_gtlData * ptr_8673 = (cPtr_gtlData *) result_cfg.ptr () ;
  callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_8673, GALGAS_lstring::constructor_new (GALGAS_string ("PASSEDOPTIONS"), GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 301))  COMMA_SOURCE_FILE ("systemConfig.galgas", 301)), var_opts_8311, inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 300)) ;
  }
  cEnumerator_objectsMap enumerator_8770 (object->mProperty_objects, kENUMERATION_UP) ;
  while (enumerator_8770.hasCurrentObject ()) {
    GALGAS_implementationObject var_implementationObject_9010 ;
    constinArgument_imp.getter_imp (SOURCE_FILE ("systemConfig.galgas", 309)).method_get (enumerator_8770.current_lkey (HERE), var_implementationObject_9010, inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 309)) ;
    const enumGalgasBool test_2 = var_implementationObject_9010.getter_multiple (SOURCE_FILE ("systemConfig.galgas", 310)).getter_bool (SOURCE_FILE ("systemConfig.galgas", 310)).boolEnum () ;
    if (kBoolTrue == test_2) {
      GALGAS_gtlList var_objs_9082 = GALGAS_gtlList::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 311)), enumerator_8770.current_lkey (HERE), GALGAS_list::constructor_emptyList (SOURCE_FILE ("systemConfig.galgas", 311))  COMMA_SOURCE_FILE ("systemConfig.galgas", 311)) ;
      cEnumerator_objectKindMap enumerator_9159 (enumerator_8770.current_objectsOfKind (HERE).getter_objects (SOURCE_FILE ("systemConfig.galgas", 312)), kENUMERATION_UP) ;
      while (enumerator_9159.hasCurrentObject ()) {
        GALGAS_gtlData var_attrs_9185 = callExtensionGetter_fieldMap ((const cPtr_objectAttributes *) enumerator_9159.current_attributes (HERE).ptr (), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 313)) ;
        {
        var_objs_9082.insulate (HERE) ;
        cPtr_gtlList * ptr_9225 = (cPtr_gtlList *) var_objs_9082.ptr () ;
        callExtensionSetter_appendItem ((cPtr_gtlList *) ptr_9225, var_attrs_9185, inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 314)) ;
        }
        enumerator_9159.gotoNextObject () ;
      }
      {
      result_cfg.insulate (HERE) ;
      cPtr_gtlData * ptr_9267 = (cPtr_gtlData *) result_cfg.ptr () ;
      callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_9267, enumerator_8770.current_lkey (HERE), var_objs_9082, inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 316)) ;
      }
    }else if (kBoolFalse == test_2) {
      const enumGalgasBool test_3 = GALGAS_bool (kIsEqual, enumerator_8770.current_objectsOfKind (HERE).getter_objects (SOURCE_FILE ("systemConfig.galgas", 322)).getter_count (SOURCE_FILE ("systemConfig.galgas", 322)).objectCompare (GALGAS_uint ((uint32_t) 1U))).boolEnum () ;
      if (kBoolTrue == test_3) {
        GALGAS_gtlData var_attrs_9432 = GALGAS_gtlStruct::constructor_new (GALGAS_location::constructor_here (inCompiler  COMMA_SOURCE_FILE ("systemConfig.galgas", 323)), enumerator_8770.current_lkey (HERE), GALGAS_gtlVarMap::constructor_emptyMap (SOURCE_FILE ("systemConfig.galgas", 323))  COMMA_SOURCE_FILE ("systemConfig.galgas", 323)) ;
        cEnumerator_objectKindMap enumerator_9520 (enumerator_8770.current_objectsOfKind (HERE).getter_objects (SOURCE_FILE ("systemConfig.galgas", 324)), kENUMERATION_UP) ;
        while (enumerator_9520.hasCurrentObject ()) {
          var_attrs_9432 = callExtensionGetter_fieldMap ((const cPtr_objectAttributes *) enumerator_9520.current_attributes (HERE).ptr (), inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 325)) ;
          enumerator_9520.gotoNextObject () ;
        }
        {
        result_cfg.insulate (HERE) ;
        cPtr_gtlData * ptr_9590 = (cPtr_gtlData *) result_cfg.ptr () ;
        callExtensionSetter_setStructField ((cPtr_gtlData *) ptr_9590, enumerator_8770.current_lkey (HERE), var_attrs_9432, inCompiler COMMA_SOURCE_FILE ("systemConfig.galgas", 327)) ;
        }
      }
    }
    enumerator_8770.gotoNextObject () ;
  }
//---
  return result_cfg ;
}


//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionGetter_applicationDefinition_templateData (void) {
  enterExtensionGetter_templateData (kTypeDescriptor_GALGAS_applicationDefinition.mSlotID,
                                     extensionGetter_applicationDefinition_templateData) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionGetter_applicationDefinition_templateData (void) {
  gExtensionGetterTable_applicationDefinition_templateData.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gGetter_applicationDefinition_templateData (defineExtensionGetter_applicationDefinition_templateData,
                                                               freeExtensionGetter_applicationDefinition_templateData) ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                Extension method '@objectKind verifyCrossReferences'                                 *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

static TC_UniqueArray <extensionMethodSignature_objectKind_verifyCrossReferences> gExtensionMethodTable_objectKind_verifyCrossReferences ;

//---------------------------------------------------------------------------------------------------------------------*

void enterExtensionMethod_verifyCrossReferences (const int32_t inClassIndex,
                                                 extensionMethodSignature_objectKind_verifyCrossReferences inMethod) {
  gExtensionMethodTable_objectKind_verifyCrossReferences.forceObjectAtIndex (inClassIndex, inMethod, NULL COMMA_HERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

void callExtensionMethod_verifyCrossReferences (const cPtr_objectKind * inObject,
                                                const GALGAS_objectsMap constin_allObjects,
                                                const GALGAS_implementationObject constin_obj,
                                                C_Compiler * inCompiler
                                                COMMA_LOCATION_ARGS) {
  if (NULL != inObject) {
    macroValidSharedObject (inObject, cPtr_objectKind) ;
    const C_galgas_type_descriptor * info = inObject->classDescriptor () ;
    const int32_t classIndex = info->mSlotID ;
    extensionMethodSignature_objectKind_verifyCrossReferences f = NULL ;
    if (classIndex < gExtensionMethodTable_objectKind_verifyCrossReferences.count ()) {
      f = gExtensionMethodTable_objectKind_verifyCrossReferences (classIndex COMMA_HERE) ;
    }
    if (NULL == f) {
       const C_galgas_type_descriptor * p = info->mSuperclassDescriptor ;
       while ((NULL == f) && (NULL != p)) {
         if (p->mSlotID < gExtensionMethodTable_objectKind_verifyCrossReferences.count ()) {
           f = gExtensionMethodTable_objectKind_verifyCrossReferences (p->mSlotID COMMA_HERE) ;
         }
         p = p->mSuperclassDescriptor ;
       }
       gExtensionMethodTable_objectKind_verifyCrossReferences.forceObjectAtIndex (classIndex, f, NULL COMMA_HERE) ;
    }
    if (NULL == f) {
      fatalError ("FATAL CATEGORY METHOD CALL ERROR", __FILE__, __LINE__) ;
    }else{
      f (inObject, constin_allObjects, constin_obj, inCompiler COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

static void extensionMethod_objectKind_verifyCrossReferences (const cPtr_objectKind * inObject,
                                                              const GALGAS_objectsMap constinArgument_allObjects,
                                                              const GALGAS_implementationObject constinArgument_obj,
                                                              C_Compiler * inCompiler
                                                              COMMA_UNUSED_LOCATION_ARGS) {
  const cPtr_objectKind * object = inObject ;
  macroValidSharedObject (object, cPtr_objectKind) ;
  cEnumerator_objectKindMap enumerator_18395 (object->mProperty_objects, kENUMERATION_UP) ;
  while (enumerator_18395.hasCurrentObject ()) {
    callExtensionMethod_verifyCrossReferences ((const cPtr_objectAttributes *) enumerator_18395.current_attributes (HERE).ptr (), constinArgument_allObjects, constinArgument_obj.getter_attributes (SOURCE_FILE ("semantic_verification.galgas", 590)), inCompiler COMMA_SOURCE_FILE ("semantic_verification.galgas", 590)) ;
    enumerator_18395.gotoNextObject () ;
  }
}
//---------------------------------------------------------------------------------------------------------------------*

static void defineExtensionMethod_objectKind_verifyCrossReferences (void) {
  enterExtensionMethod_verifyCrossReferences (kTypeDescriptor_GALGAS_objectKind.mSlotID,
                                              extensionMethod_objectKind_verifyCrossReferences) ;
}

//---------------------------------------------------------------------------------------------------------------------*

static void freeExtensionMethod_objectKind_verifyCrossReferences (void) {
  gExtensionMethodTable_objectKind_verifyCrossReferences.free () ;
}

//---------------------------------------------------------------------------------------------------------------------*

C_PrologueEpilogue gMethod_objectKind_verifyCrossReferences (defineExtensionMethod_objectKind_verifyCrossReferences,
                                                             freeExtensionMethod_objectKind_verifyCrossReferences) ;

//---------------------------------------------------------------------------------------------------------------------*
//   Object comparison                                                                                                 *
//---------------------------------------------------------------------------------------------------------------------*

typeComparisonResult cPtr_goilContext::dynamicObjectCompare (const acPtr_class * inOperandPtr) const {
  typeComparisonResult result = kOperandEqual ;
  const cPtr_goilContext * p = (const cPtr_goilContext *) inOperandPtr ;
  macroValidSharedObject (p, cPtr_goilContext) ;
  if (kOperandEqual == result) {
    result = mProperty_prefix.objectCompare (p->mProperty_prefix) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_path.objectCompare (p->mProperty_path) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_templateDirectory.objectCompare (p->mProperty_templateDirectory) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_templateExtension.objectCompare (p->mProperty_templateExtension) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_importPath.objectCompare (p->mProperty_importPath) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_inputVars.objectCompare (p->mProperty_inputVars) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_propagateError.objectCompare (p->mProperty_propagateError) ;
  }
  if (kOperandEqual == result) {
    result = mProperty_debuggerContext.objectCompare (p->mProperty_debuggerContext) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*


typeComparisonResult GALGAS_goilContext::objectCompare (const GALGAS_goilContext & inOperand) const {
  typeComparisonResult result = kOperandNotValid ;
  if (isValid () && inOperand.isValid ()) {
    const int32_t mySlot = mObjectPtr->classDescriptor ()->mSlotID ;
    const int32_t operandSlot = inOperand.mObjectPtr->classDescriptor ()->mSlotID ;
    if (mySlot < operandSlot) {
      result = kFirstOperandLowerThanSecond ;
    }else if (mySlot > operandSlot) {
      result = kFirstOperandGreaterThanSecond ;
    }else{
      result = mObjectPtr->dynamicObjectCompare (inOperand.mObjectPtr) ;
    }
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_goilContext::GALGAS_goilContext (void) :
GALGAS_gtlContext () {
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_goilContext GALGAS_goilContext::constructor_default (LOCATION_ARGS) {
  return GALGAS_goilContext::constructor_new (GALGAS_lstring::constructor_default (HERE),
                                              GALGAS_string::constructor_default (HERE),
                                              GALGAS_string::constructor_default (HERE),
                                              GALGAS_string::constructor_default (HERE),
                                              GALGAS_stringlist::constructor_emptyList (HERE),
                                              GALGAS_gtlDataList::constructor_emptyList (HERE),
                                              GALGAS_bool::constructor_default (HERE),
                                              GALGAS_debuggerContext::constructor_default (HERE)
                                              COMMA_THERE) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_goilContext::GALGAS_goilContext (const cPtr_goilContext * inSourcePtr) :
GALGAS_gtlContext (inSourcePtr) {
  macroNullOrValidSharedObject (inSourcePtr, cPtr_goilContext) ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_goilContext GALGAS_goilContext::constructor_new (const GALGAS_lstring & inAttribute_prefix,
                                                        const GALGAS_string & inAttribute_path,
                                                        const GALGAS_string & inAttribute_templateDirectory,
                                                        const GALGAS_string & inAttribute_templateExtension,
                                                        const GALGAS_stringlist & inAttribute_importPath,
                                                        const GALGAS_gtlDataList & inAttribute_inputVars,
                                                        const GALGAS_bool & inAttribute_propagateError,
                                                        const GALGAS_debuggerContext & inAttribute_debuggerContext
                                                        COMMA_LOCATION_ARGS) {
  GALGAS_goilContext result ;
  if (inAttribute_prefix.isValid () && inAttribute_path.isValid () && inAttribute_templateDirectory.isValid () && inAttribute_templateExtension.isValid () && inAttribute_importPath.isValid () && inAttribute_inputVars.isValid () && inAttribute_propagateError.isValid () && inAttribute_debuggerContext.isValid ()) {
    macroMyNew (result.mObjectPtr, cPtr_goilContext (inAttribute_prefix, inAttribute_path, inAttribute_templateDirectory, inAttribute_templateExtension, inAttribute_importPath, inAttribute_inputVars, inAttribute_propagateError, inAttribute_debuggerContext COMMA_THERE)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                        Pointer class for @goilContext class                                         *
//---------------------------------------------------------------------------------------------------------------------*

cPtr_goilContext::cPtr_goilContext (const GALGAS_lstring & in_prefix,
                                    const GALGAS_string & in_path,
                                    const GALGAS_string & in_templateDirectory,
                                    const GALGAS_string & in_templateExtension,
                                    const GALGAS_stringlist & in_importPath,
                                    const GALGAS_gtlDataList & in_inputVars,
                                    const GALGAS_bool & in_propagateError,
                                    const GALGAS_debuggerContext & in_debuggerContext
                                    COMMA_LOCATION_ARGS) :
cPtr_gtlContext (in_prefix, in_path, in_templateDirectory, in_templateExtension, in_importPath, in_inputVars, in_propagateError, in_debuggerContext COMMA_THERE) {
}

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * cPtr_goilContext::classDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_goilContext ;
}

void cPtr_goilContext::description (C_String & ioString,
                                    const int32_t inIndentation) const {
  ioString << "[@goilContext:" ;
  mProperty_prefix.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_path.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_templateDirectory.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_templateExtension.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_importPath.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_inputVars.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_propagateError.description (ioString, inIndentation+1) ;
  ioString << ", " ;
  mProperty_debuggerContext.description (ioString, inIndentation+1) ;
  ioString << "]" ;
}

//---------------------------------------------------------------------------------------------------------------------*

acPtr_class * cPtr_goilContext::duplicate (LOCATION_ARGS) const {
  acPtr_class * ptr = NULL ;
  macroMyNew (ptr, cPtr_goilContext (mProperty_prefix, mProperty_path, mProperty_templateDirectory, mProperty_templateExtension, mProperty_importPath, mProperty_inputVars, mProperty_propagateError, mProperty_debuggerContext COMMA_THERE)) ;
  return ptr ;
}


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                     *
//                                                  @goilContext type                                                  *
//                                                                                                                     *
//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor
kTypeDescriptor_GALGAS_goilContext ("goilContext",
                                    & kTypeDescriptor_GALGAS_gtlContext) ;

//---------------------------------------------------------------------------------------------------------------------*

const C_galgas_type_descriptor * GALGAS_goilContext::staticTypeDescriptor (void) const {
  return & kTypeDescriptor_GALGAS_goilContext ;
}

//---------------------------------------------------------------------------------------------------------------------*

AC_GALGAS_root * GALGAS_goilContext::clonedObject (void) const {
  AC_GALGAS_root * result = NULL ;
  if (isValid ()) {
    macroMyNew (result, GALGAS_goilContext (*this)) ;
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

GALGAS_goilContext GALGAS_goilContext::extractObject (const GALGAS_object & inObject,
                                                      C_Compiler * inCompiler
                                                      COMMA_LOCATION_ARGS) {
  GALGAS_goilContext result ;
  const GALGAS_goilContext * p = (const GALGAS_goilContext *) inObject.embeddedObject () ;
  if (NULL != p) {
    if (NULL != dynamic_cast <const GALGAS_goilContext *> (p)) {
      result = *p ;
    }else{
      inCompiler->castError ("goilContext", p->dynamicTypeDescriptor () COMMA_THERE) ;
    }  
  }
  return result ;
}

//---------------------------------------------------------------------------------------------------------------------*

#include "utilities/MF_MemoryControl.h"
#include "galgas2/C_galgas_CLI_Options.h"

#include "files/C_FileManager.h"

//---------------------------------------------------------------------------------------------------------------------*


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                   L L ( 1 )    P R O D U C T I O N    R U L E S                                      
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

#define TERMINAL(t)     ((t)+1)
#define NONTERMINAL(nt) ((-nt)-1)
#define END_PRODUCTION  (0)

static const int16_t gProductions_goil_grammar [] = {
// At index 0 : <implementation_definition>, in file 'implementation_parser.ggs', line 55
  TERMINAL (C_Lexique_goil_5F_lexique::kToken_IMPLEMENTATION) // $IMPLEMENTATION$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (14) // <implementation_object_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, END_PRODUCTION
// At index 7 : <start>, in file 'goil_syntax.ggs', line 38
, NONTERMINAL (5) // <OIL_version>
, NONTERMINAL (2) // <file>
, END_PRODUCTION
// At index 10 : <file>, in file 'goil_syntax.ggs', line 110
, NONTERMINAL (36) // <select_goil_5F_syntax_0>
, END_PRODUCTION
// At index 12 : <sign>, in file 'goil_syntax.ggs', line 126
, NONTERMINAL (37) // <select_goil_5F_syntax_1>
, END_PRODUCTION
// At index 14 : <description>, in file 'goil_syntax.ggs', line 139
, NONTERMINAL (38) // <select_goil_5F_syntax_2>
, END_PRODUCTION
// At index 16 : <OIL_version>, in file 'goil_syntax.ggs', line 163
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_OIL_5F_VERSION) // $OIL_VERSION$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (4) // <description>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, END_PRODUCTION
// At index 22 : <application_definition>, in file 'goil_syntax.ggs', line 170
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_CPU) // $CPU$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (7) // <object_definition_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, NONTERMINAL (4) // <description>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, END_PRODUCTION
// At index 30 : <object_definition_list>, in file 'goil_syntax.ggs', line 184
, NONTERMINAL (40) // <select_goil_5F_syntax_4>
, END_PRODUCTION
// At index 32 : <boolean>, in file 'goil_syntax.ggs', line 234
, NONTERMINAL (41) // <select_goil_5F_syntax_5>
, END_PRODUCTION
// At index 34 : <oil_declaration_list>, in file 'goil_syntax.ggs', line 244
, NONTERMINAL (42) // <select_goil_5F_syntax_6>
, END_PRODUCTION
// At index 36 : <oil_declaration>, in file 'goil_syntax.ggs', line 256
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (43) // <select_goil_5F_syntax_7>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, END_PRODUCTION
// At index 40 : <include_file_level>, in file 'goil_syntax.ggs', line 451
, NONTERMINAL (48) // <select_goil_5F_syntax_12>
, NONTERMINAL (49) // <select_goil_5F_syntax_13>
, END_PRODUCTION
// At index 43 : <include_cpu_level>, in file 'goil_syntax.ggs', line 475
, NONTERMINAL (50) // <select_goil_5F_syntax_14>
, NONTERMINAL (51) // <select_goil_5F_syntax_15>
, END_PRODUCTION
// At index 46 : <include_object_level>, in file 'goil_syntax.ggs', line 499
, NONTERMINAL (52) // <select_goil_5F_syntax_16>
, NONTERMINAL (53) // <select_goil_5F_syntax_17>
, END_PRODUCTION
// At index 49 : <implementation_object_list>, in file 'implementation_parser.ggs', line 62
, NONTERMINAL (54) // <select_implementation_5F_parser_0>
, END_PRODUCTION
// At index 51 : <include_implementation_level>, in file 'implementation_parser.ggs', line 71
, NONTERMINAL (55) // <select_implementation_5F_parser_1>
, NONTERMINAL (56) // <select_implementation_5F_parser_2>
, END_PRODUCTION
// At index 54 : <include_type_level>, in file 'implementation_parser.ggs', line 92
, NONTERMINAL (57) // <select_implementation_5F_parser_3>
, NONTERMINAL (58) // <select_implementation_5F_parser_4>
, END_PRODUCTION
// At index 57 : <implementation_objects>, in file 'implementation_parser.ggs', line 135
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (59) // <select_implementation_5F_parser_5>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (18) // <implementation_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 63 : <implementation_list>, in file 'implementation_parser.ggs', line 183
, NONTERMINAL (60) // <select_implementation_5F_parser_6>
, END_PRODUCTION
// At index 65 : <implementation_type>, in file 'implementation_parser.ggs', line 261
, NONTERMINAL (61) // <select_implementation_5F_parser_7>
, END_PRODUCTION
// At index 67 : <struct_options>, in file 'implementation_parser.ggs', line 289
, NONTERMINAL (62) // <select_implementation_5F_parser_8>
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (33) // <multiple>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 72 : <objref_option>, in file 'implementation_parser.ggs', line 306
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (33) // <multiple>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 76 : <string_options>, in file 'implementation_parser.ggs', line 324
, NONTERMINAL (28) // <with_auto>
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (33) // <multiple>
, NONTERMINAL (63) // <select_implementation_5F_parser_9>
, END_PRODUCTION
// At index 81 : <boolean_options>, in file 'implementation_parser.ggs', line 361
, NONTERMINAL (28) // <with_auto>
, NONTERMINAL (65) // <select_implementation_5F_parser_11>
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (33) // <multiple>
, NONTERMINAL (68) // <select_implementation_5F_parser_14>
, END_PRODUCTION
// At index 87 : <enum_item>, in file 'implementation_parser.ggs', line 406
, NONTERMINAL (35) // <identifier_or_enum_value>
, NONTERMINAL (69) // <select_implementation_5F_parser_15>
, END_PRODUCTION
// At index 90 : <enum_options>, in file 'implementation_parser.ggs', line 419
, NONTERMINAL (28) // <with_auto>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) // $[$
, NONTERMINAL (24) // <enum_item>
, NONTERMINAL (70) // <select_implementation_5F_parser_16>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) // $]$
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (33) // <multiple>
, NONTERMINAL (71) // <select_implementation_5F_parser_17>
, END_PRODUCTION
// At index 99 : <number_options>, in file 'implementation_parser.ggs', line 466
, NONTERMINAL (28) // <with_auto>
, NONTERMINAL (32) // <range>
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (33) // <multiple>
, NONTERMINAL (73) // <select_implementation_5F_parser_19>
, END_PRODUCTION
// At index 105 : <type_options>, in file 'implementation_parser.ggs', line 505
, NONTERMINAL (28) // <with_auto>
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (33) // <multiple>
, NONTERMINAL (75) // <select_implementation_5F_parser_21>
, END_PRODUCTION
// At index 110 : <with_auto>, in file 'implementation_parser.ggs', line 544
, NONTERMINAL (77) // <select_implementation_5F_parser_23>
, END_PRODUCTION
// At index 112 : <int_or_float>, in file 'implementation_parser.ggs', line 553
, NONTERMINAL (3) // <sign>
, NONTERMINAL (78) // <select_implementation_5F_parser_24>
, END_PRODUCTION
// At index 115 : <set_followup>, in file 'implementation_parser.ggs', line 571
, NONTERMINAL (79) // <select_implementation_5F_parser_25>
, END_PRODUCTION
// At index 117 : <range_content>, in file 'implementation_parser.ggs', line 583
, NONTERMINAL (3) // <sign>
, NONTERMINAL (80) // <select_implementation_5F_parser_26>
, END_PRODUCTION
// At index 120 : <range>, in file 'implementation_parser.ggs', line 623
, NONTERMINAL (83) // <select_implementation_5F_parser_29>
, END_PRODUCTION
// At index 122 : <multiple>, in file 'implementation_parser.ggs', line 633
, NONTERMINAL (84) // <select_implementation_5F_parser_30>
, END_PRODUCTION
// At index 124 : <identifier_or_attribute>, in file 'implementation_parser.ggs', line 643
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, END_PRODUCTION
// At index 126 : <identifier_or_enum_value>, in file 'implementation_parser.ggs', line 648
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, END_PRODUCTION
//---- Added productions from 'select' and 'repeat' instructions
// At index 128 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
, END_PRODUCTION
// At index 129 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
, NONTERMINAL (11) // <include_file_level>
, NONTERMINAL (36) // <select_goil_5F_syntax_0>
, END_PRODUCTION
// At index 132 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
, NONTERMINAL (0) // <implementation_definition>
, NONTERMINAL (36) // <select_goil_5F_syntax_0>
, END_PRODUCTION
// At index 135 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
, NONTERMINAL (6) // <application_definition>
, NONTERMINAL (36) // <select_goil_5F_syntax_0>
, END_PRODUCTION
// At index 138 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2D_) // $-$
, END_PRODUCTION
// At index 140 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2B_) // $+$
, END_PRODUCTION
// At index 142 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
, END_PRODUCTION
// At index 143 : <select_goil_5F_syntax_2>, in file 'goil_syntax.ggs', line 140
, END_PRODUCTION
// At index 144 : <select_goil_5F_syntax_2>, in file 'goil_syntax.ggs', line 140
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3A_) // $:$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (39) // <select_goil_5F_syntax_3>
, END_PRODUCTION
// At index 148 : <select_goil_5F_syntax_3>, in file 'goil_syntax.ggs', line 147
, END_PRODUCTION
// At index 149 : <select_goil_5F_syntax_3>, in file 'goil_syntax.ggs', line 147
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (39) // <select_goil_5F_syntax_3>
, END_PRODUCTION
// At index 152 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
, END_PRODUCTION
// At index 153 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (9) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, NONTERMINAL (4) // <description>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, NONTERMINAL (40) // <select_goil_5F_syntax_4>
, END_PRODUCTION
// At index 162 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
, NONTERMINAL (12) // <include_cpu_level>
, NONTERMINAL (40) // <select_goil_5F_syntax_4>
, END_PRODUCTION
// At index 165 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 235
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_TRUE) // $TRUE$
, END_PRODUCTION
// At index 167 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 235
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_FALSE) // $FALSE$
, END_PRODUCTION
// At index 169 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 248
, END_PRODUCTION
// At index 170 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 248
, NONTERMINAL (10) // <oil_declaration>
, NONTERMINAL (42) // <select_goil_5F_syntax_6>
, END_PRODUCTION
// At index 173 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 248
, NONTERMINAL (13) // <include_object_level>
, NONTERMINAL (42) // <select_goil_5F_syntax_6>
, END_PRODUCTION
// At index 176 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 273
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (44) // <select_goil_5F_syntax_8>
, END_PRODUCTION
// At index 179 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 273
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (9) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 185 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 275
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (45) // <select_goil_5F_syntax_9>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 189 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 275
, NONTERMINAL (3) // <sign>
, NONTERMINAL (46) // <select_goil_5F_syntax_10>
, END_PRODUCTION
// At index 192 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 275
, NONTERMINAL (8) // <boolean>
, NONTERMINAL (47) // <select_goil_5F_syntax_11>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 196 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 275
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 199 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 275
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) // $AUTO$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 202 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 296
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (9) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 206 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 296
, END_PRODUCTION
// At index 207 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 313
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) // $uint_number$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 210 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 313
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_float_5F_number) // $float_number$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 213 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 344
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (9) // <oil_declaration_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 217 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 344
, END_PRODUCTION
// At index 218 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 458
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) // $include$
, END_PRODUCTION
// At index 220 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 458
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) // $includeifexists$
, END_PRODUCTION
// At index 222 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 464
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) // $g_string$
, END_PRODUCTION
// At index 224 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 464
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, END_PRODUCTION
// At index 226 : <select_goil_5F_syntax_14>, in file 'goil_syntax.ggs', line 482
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) // $include$
, END_PRODUCTION
// At index 228 : <select_goil_5F_syntax_14>, in file 'goil_syntax.ggs', line 482
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) // $includeifexists$
, END_PRODUCTION
// At index 230 : <select_goil_5F_syntax_15>, in file 'goil_syntax.ggs', line 488
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) // $g_string$
, END_PRODUCTION
// At index 232 : <select_goil_5F_syntax_15>, in file 'goil_syntax.ggs', line 488
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, END_PRODUCTION
// At index 234 : <select_goil_5F_syntax_16>, in file 'goil_syntax.ggs', line 504
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) // $include$
, END_PRODUCTION
// At index 236 : <select_goil_5F_syntax_16>, in file 'goil_syntax.ggs', line 504
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) // $includeifexists$
, END_PRODUCTION
// At index 238 : <select_goil_5F_syntax_17>, in file 'goil_syntax.ggs', line 510
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) // $g_string$
, END_PRODUCTION
// At index 240 : <select_goil_5F_syntax_17>, in file 'goil_syntax.ggs', line 510
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, END_PRODUCTION
// At index 242 : <select_implementation_5F_parser_0>, in file 'implementation_parser.ggs', line 65
, END_PRODUCTION
// At index 243 : <select_implementation_5F_parser_0>, in file 'implementation_parser.ggs', line 65
, NONTERMINAL (17) // <implementation_objects>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, NONTERMINAL (54) // <select_implementation_5F_parser_0>
, END_PRODUCTION
// At index 247 : <select_implementation_5F_parser_0>, in file 'implementation_parser.ggs', line 65
, NONTERMINAL (15) // <include_implementation_level>
, NONTERMINAL (54) // <select_implementation_5F_parser_0>
, END_PRODUCTION
// At index 250 : <select_implementation_5F_parser_1>, in file 'implementation_parser.ggs', line 75
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) // $include$
, END_PRODUCTION
// At index 252 : <select_implementation_5F_parser_1>, in file 'implementation_parser.ggs', line 75
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) // $includeifexists$
, END_PRODUCTION
// At index 254 : <select_implementation_5F_parser_2>, in file 'implementation_parser.ggs', line 81
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) // $g_string$
, END_PRODUCTION
// At index 256 : <select_implementation_5F_parser_2>, in file 'implementation_parser.ggs', line 81
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, END_PRODUCTION
// At index 258 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 96
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_include) // $include$
, END_PRODUCTION
// At index 260 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 96
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_includeifexists) // $includeifexists$
, END_PRODUCTION
// At index 262 : <select_implementation_5F_parser_4>, in file 'implementation_parser.ggs', line 102
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_g_5F_string) // $g_string$
, END_PRODUCTION
// At index 264 : <select_implementation_5F_parser_4>, in file 'implementation_parser.ggs', line 102
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, END_PRODUCTION
// At index 266 : <select_implementation_5F_parser_5>, in file 'implementation_parser.ggs', line 142
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) // $[$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) // $]$
, END_PRODUCTION
// At index 269 : <select_implementation_5F_parser_5>, in file 'implementation_parser.ggs', line 142
, END_PRODUCTION
// At index 270 : <select_implementation_5F_parser_6>, in file 'implementation_parser.ggs', line 186
, END_PRODUCTION
// At index 271 : <select_implementation_5F_parser_6>, in file 'implementation_parser.ggs', line 186
, NONTERMINAL (19) // <implementation_type>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3B_) // $;$
, NONTERMINAL (60) // <select_implementation_5F_parser_6>
, END_PRODUCTION
// At index 275 : <select_implementation_5F_parser_6>, in file 'implementation_parser.ggs', line 186
, NONTERMINAL (16) // <include_type_level>
, NONTERMINAL (60) // <select_implementation_5F_parser_6>
, END_PRODUCTION
// At index 278 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 264
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_UINT_33__32_) // $UINT32$
, NONTERMINAL (26) // <number_options>
, END_PRODUCTION
// At index 281 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 264
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_INT_33__32_) // $INT32$
, NONTERMINAL (26) // <number_options>
, END_PRODUCTION
// At index 284 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 264
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_UINT_36__34_) // $UINT64$
, NONTERMINAL (26) // <number_options>
, END_PRODUCTION
// At index 287 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 264
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_INT_36__34_) // $INT64$
, NONTERMINAL (26) // <number_options>
, END_PRODUCTION
// At index 290 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 264
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_FLOAT) // $FLOAT$
, NONTERMINAL (26) // <number_options>
, END_PRODUCTION
// At index 293 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 264
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_ENUM) // $ENUM$
, NONTERMINAL (25) // <enum_options>
, END_PRODUCTION
// At index 296 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 264
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_BOOLEAN) // $BOOLEAN$
, NONTERMINAL (23) // <boolean_options>
, END_PRODUCTION
// At index 299 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 264
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_STRING) // $STRING$
, NONTERMINAL (22) // <string_options>
, END_PRODUCTION
// At index 302 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 264
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_IDENTIFIER) // $IDENTIFIER$
, NONTERMINAL (27) // <type_options>
, END_PRODUCTION
// At index 305 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 264
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_STRUCT) // $STRUCT$
, NONTERMINAL (20) // <struct_options>
, END_PRODUCTION
// At index 308 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 264
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (21) // <objref_option>
, END_PRODUCTION
// At index 311 : <select_implementation_5F_parser_8>, in file 'implementation_parser.ggs', line 293
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (18) // <implementation_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 315 : <select_implementation_5F_parser_8>, in file 'implementation_parser.ggs', line 293
, END_PRODUCTION
// At index 316 : <select_implementation_5F_parser_9>, in file 'implementation_parser.ggs', line 334
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (64) // <select_implementation_5F_parser_10>
, END_PRODUCTION
// At index 319 : <select_implementation_5F_parser_9>, in file 'implementation_parser.ggs', line 334
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 321 : <select_implementation_5F_parser_10>, in file 'implementation_parser.ggs', line 336
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_string) // $string$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 324 : <select_implementation_5F_parser_10>, in file 'implementation_parser.ggs', line 336
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) // $AUTO$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 327 : <select_implementation_5F_parser_10>, in file 'implementation_parser.ggs', line 336
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT) // $NO_DEFAULT$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 330 : <select_implementation_5F_parser_11>, in file 'implementation_parser.ggs', line 368
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) // $[$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_TRUE) // $TRUE$
, NONTERMINAL (66) // <select_implementation_5F_parser_12>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2C_) // $,$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_FALSE) // $FALSE$
, NONTERMINAL (67) // <select_implementation_5F_parser_13>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) // $]$
, END_PRODUCTION
// At index 338 : <select_implementation_5F_parser_11>, in file 'implementation_parser.ggs', line 368
, END_PRODUCTION
// At index 339 : <select_implementation_5F_parser_12>, in file 'implementation_parser.ggs', line 371
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (18) // <implementation_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 343 : <select_implementation_5F_parser_12>, in file 'implementation_parser.ggs', line 371
, END_PRODUCTION
// At index 344 : <select_implementation_5F_parser_13>, in file 'implementation_parser.ggs', line 380
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (18) // <implementation_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 348 : <select_implementation_5F_parser_13>, in file 'implementation_parser.ggs', line 380
, END_PRODUCTION
// At index 349 : <select_implementation_5F_parser_14>, in file 'implementation_parser.ggs', line 394
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (8) // <boolean>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 353 : <select_implementation_5F_parser_14>, in file 'implementation_parser.ggs', line 394
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 355 : <select_implementation_5F_parser_15>, in file 'implementation_parser.ggs', line 411
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7B_) // ${$
, NONTERMINAL (18) // <implementation_list>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__7D_) // $}$
, END_PRODUCTION
// At index 359 : <select_implementation_5F_parser_15>, in file 'implementation_parser.ggs', line 411
, END_PRODUCTION
// At index 360 : <select_implementation_5F_parser_16>, in file 'implementation_parser.ggs', line 427
, END_PRODUCTION
// At index 361 : <select_implementation_5F_parser_16>, in file 'implementation_parser.ggs', line 427
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2C_) // $,$
, NONTERMINAL (24) // <enum_item>
, NONTERMINAL (70) // <select_implementation_5F_parser_16>
, END_PRODUCTION
// At index 365 : <select_implementation_5F_parser_17>, in file 'implementation_parser.ggs', line 437
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (72) // <select_implementation_5F_parser_18>
, END_PRODUCTION
// At index 368 : <select_implementation_5F_parser_17>, in file 'implementation_parser.ggs', line 437
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 370 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 439
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_idf) // $idf$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 373 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 439
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) // $AUTO$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 376 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 439
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT) // $NO_DEFAULT$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 379 : <select_implementation_5F_parser_19>, in file 'implementation_parser.ggs', line 479
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (74) // <select_implementation_5F_parser_20>
, END_PRODUCTION
// At index 382 : <select_implementation_5F_parser_19>, in file 'implementation_parser.ggs', line 479
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 384 : <select_implementation_5F_parser_20>, in file 'implementation_parser.ggs', line 481
, NONTERMINAL (29) // <int_or_float>
, END_PRODUCTION
// At index 386 : <select_implementation_5F_parser_20>, in file 'implementation_parser.ggs', line 481
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT) // $NO_DEFAULT$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 389 : <select_implementation_5F_parser_20>, in file 'implementation_parser.ggs', line 481
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) // $AUTO$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 392 : <select_implementation_5F_parser_21>, in file 'implementation_parser.ggs', line 516
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__3D_) // $=$
, NONTERMINAL (76) // <select_implementation_5F_parser_22>
, END_PRODUCTION
// At index 395 : <select_implementation_5F_parser_21>, in file 'implementation_parser.ggs', line 516
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 397 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 518
, NONTERMINAL (34) // <identifier_or_attribute>
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 400 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 518
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT) // $NO_DEFAULT$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 403 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 518
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_AUTO) // $AUTO$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 406 : <select_implementation_5F_parser_23>, in file 'implementation_parser.ggs', line 546
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_WITH_5F_AUTO) // $WITH_AUTO$
, END_PRODUCTION
// At index 408 : <select_implementation_5F_parser_23>, in file 'implementation_parser.ggs', line 546
, END_PRODUCTION
// At index 409 : <select_implementation_5F_parser_24>, in file 'implementation_parser.ggs', line 558
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) // $uint_number$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 412 : <select_implementation_5F_parser_24>, in file 'implementation_parser.ggs', line 558
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_float_5F_number) // $float_number$
, NONTERMINAL (4) // <description>
, END_PRODUCTION
// At index 415 : <select_implementation_5F_parser_25>, in file 'implementation_parser.ggs', line 574
, END_PRODUCTION
// At index 416 : <select_implementation_5F_parser_25>, in file 'implementation_parser.ggs', line 574
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2C_) // $,$
, NONTERMINAL (29) // <int_or_float>
, NONTERMINAL (79) // <select_implementation_5F_parser_25>
, END_PRODUCTION
// At index 420 : <select_implementation_5F_parser_26>, in file 'implementation_parser.ggs', line 590
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_set_5F_start_5F_uint_5F_number) // $set_start_uint_number$
, NONTERMINAL (29) // <int_or_float>
, END_PRODUCTION
// At index 423 : <select_implementation_5F_parser_26>, in file 'implementation_parser.ggs', line 590
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_uint_5F_number) // $uint_number$
, NONTERMINAL (81) // <select_implementation_5F_parser_27>
, END_PRODUCTION
// At index 426 : <select_implementation_5F_parser_26>, in file 'implementation_parser.ggs', line 590
, TERMINAL (C_Lexique_goil_5F_lexique::kToken_float_5F_number) // $float_number$
, NONTERMINAL (82) // <select_implementation_5F_parser_28>
, END_PRODUCTION
// At index 429 : <select_implementation_5F_parser_27>, in file 'implementation_parser.ggs', line 600
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2E__2E_) // $..$
, NONTERMINAL (29) // <int_or_float>
, END_PRODUCTION
// At index 432 : <select_implementation_5F_parser_27>, in file 'implementation_parser.ggs', line 600
, NONTERMINAL (30) // <set_followup>
, END_PRODUCTION
// At index 434 : <select_implementation_5F_parser_28>, in file 'implementation_parser.ggs', line 612
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__2E__2E_) // $..$
, NONTERMINAL (29) // <int_or_float>
, END_PRODUCTION
// At index 437 : <select_implementation_5F_parser_28>, in file 'implementation_parser.ggs', line 612
, NONTERMINAL (30) // <set_followup>
, END_PRODUCTION
// At index 439 : <select_implementation_5F_parser_29>, in file 'implementation_parser.ggs', line 626
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) // $[$
, NONTERMINAL (31) // <range_content>
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) // $]$
, END_PRODUCTION
// At index 443 : <select_implementation_5F_parser_29>, in file 'implementation_parser.ggs', line 626
, END_PRODUCTION
// At index 444 : <select_implementation_5F_parser_30>, in file 'implementation_parser.ggs', line 635
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5B_) // $[$
, TERMINAL (C_Lexique_goil_5F_lexique::kToken__5D_) // $]$
, END_PRODUCTION
// At index 447 : <select_implementation_5F_parser_30>, in file 'implementation_parser.ggs', line 635
, END_PRODUCTION
// At index 448 : <>, in file '.ggs', line 0
, NONTERMINAL (1) // <start>
, END_PRODUCTION
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                          P R O D U C T I O N    N A M E S                                            
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const cProductionNameDescriptor gProductionNames_goil_grammar [159] = {
 {"<implementation_definition>", "implementation_parser", 0}, // at index 0
 {"<start>", "goil_syntax", 7}, // at index 1
 {"<file>", "goil_syntax", 10}, // at index 2
 {"<sign>", "goil_syntax", 12}, // at index 3
 {"<description>", "goil_syntax", 14}, // at index 4
 {"<OIL_version>", "goil_syntax", 16}, // at index 5
 {"<application_definition>", "goil_syntax", 22}, // at index 6
 {"<object_definition_list>", "goil_syntax", 30}, // at index 7
 {"<boolean>", "goil_syntax", 32}, // at index 8
 {"<oil_declaration_list>", "goil_syntax", 34}, // at index 9
 {"<oil_declaration>", "goil_syntax", 36}, // at index 10
 {"<include_file_level>", "goil_syntax", 40}, // at index 11
 {"<include_cpu_level>", "goil_syntax", 43}, // at index 12
 {"<include_object_level>", "goil_syntax", 46}, // at index 13
 {"<implementation_object_list>", "implementation_parser", 49}, // at index 14
 {"<include_implementation_level>", "implementation_parser", 51}, // at index 15
 {"<include_type_level>", "implementation_parser", 54}, // at index 16
 {"<implementation_objects>", "implementation_parser", 57}, // at index 17
 {"<implementation_list>", "implementation_parser", 63}, // at index 18
 {"<implementation_type>", "implementation_parser", 65}, // at index 19
 {"<struct_options>", "implementation_parser", 67}, // at index 20
 {"<objref_option>", "implementation_parser", 72}, // at index 21
 {"<string_options>", "implementation_parser", 76}, // at index 22
 {"<boolean_options>", "implementation_parser", 81}, // at index 23
 {"<enum_item>", "implementation_parser", 87}, // at index 24
 {"<enum_options>", "implementation_parser", 90}, // at index 25
 {"<number_options>", "implementation_parser", 99}, // at index 26
 {"<type_options>", "implementation_parser", 105}, // at index 27
 {"<with_auto>", "implementation_parser", 110}, // at index 28
 {"<int_or_float>", "implementation_parser", 112}, // at index 29
 {"<set_followup>", "implementation_parser", 115}, // at index 30
 {"<range_content>", "implementation_parser", 117}, // at index 31
 {"<range>", "implementation_parser", 120}, // at index 32
 {"<multiple>", "implementation_parser", 122}, // at index 33
 {"<identifier_or_attribute>", "implementation_parser", 124}, // at index 34
 {"<identifier_or_enum_value>", "implementation_parser", 126}, // at index 35
 {"<select_goil_5F_syntax_0>", "goil_syntax", 128}, // at index 36
 {"<select_goil_5F_syntax_0>", "goil_syntax", 129}, // at index 37
 {"<select_goil_5F_syntax_0>", "goil_syntax", 132}, // at index 38
 {"<select_goil_5F_syntax_0>", "goil_syntax", 135}, // at index 39
 {"<select_goil_5F_syntax_1>", "goil_syntax", 138}, // at index 40
 {"<select_goil_5F_syntax_1>", "goil_syntax", 140}, // at index 41
 {"<select_goil_5F_syntax_1>", "goil_syntax", 142}, // at index 42
 {"<select_goil_5F_syntax_2>", "goil_syntax", 143}, // at index 43
 {"<select_goil_5F_syntax_2>", "goil_syntax", 144}, // at index 44
 {"<select_goil_5F_syntax_3>", "goil_syntax", 148}, // at index 45
 {"<select_goil_5F_syntax_3>", "goil_syntax", 149}, // at index 46
 {"<select_goil_5F_syntax_4>", "goil_syntax", 152}, // at index 47
 {"<select_goil_5F_syntax_4>", "goil_syntax", 153}, // at index 48
 {"<select_goil_5F_syntax_4>", "goil_syntax", 162}, // at index 49
 {"<select_goil_5F_syntax_5>", "goil_syntax", 165}, // at index 50
 {"<select_goil_5F_syntax_5>", "goil_syntax", 167}, // at index 51
 {"<select_goil_5F_syntax_6>", "goil_syntax", 169}, // at index 52
 {"<select_goil_5F_syntax_6>", "goil_syntax", 170}, // at index 53
 {"<select_goil_5F_syntax_6>", "goil_syntax", 173}, // at index 54
 {"<select_goil_5F_syntax_7>", "goil_syntax", 176}, // at index 55
 {"<select_goil_5F_syntax_7>", "goil_syntax", 179}, // at index 56
 {"<select_goil_5F_syntax_8>", "goil_syntax", 185}, // at index 57
 {"<select_goil_5F_syntax_8>", "goil_syntax", 189}, // at index 58
 {"<select_goil_5F_syntax_8>", "goil_syntax", 192}, // at index 59
 {"<select_goil_5F_syntax_8>", "goil_syntax", 196}, // at index 60
 {"<select_goil_5F_syntax_8>", "goil_syntax", 199}, // at index 61
 {"<select_goil_5F_syntax_9>", "goil_syntax", 202}, // at index 62
 {"<select_goil_5F_syntax_9>", "goil_syntax", 206}, // at index 63
 {"<select_goil_5F_syntax_10>", "goil_syntax", 207}, // at index 64
 {"<select_goil_5F_syntax_10>", "goil_syntax", 210}, // at index 65
 {"<select_goil_5F_syntax_11>", "goil_syntax", 213}, // at index 66
 {"<select_goil_5F_syntax_11>", "goil_syntax", 217}, // at index 67
 {"<select_goil_5F_syntax_12>", "goil_syntax", 218}, // at index 68
 {"<select_goil_5F_syntax_12>", "goil_syntax", 220}, // at index 69
 {"<select_goil_5F_syntax_13>", "goil_syntax", 222}, // at index 70
 {"<select_goil_5F_syntax_13>", "goil_syntax", 224}, // at index 71
 {"<select_goil_5F_syntax_14>", "goil_syntax", 226}, // at index 72
 {"<select_goil_5F_syntax_14>", "goil_syntax", 228}, // at index 73
 {"<select_goil_5F_syntax_15>", "goil_syntax", 230}, // at index 74
 {"<select_goil_5F_syntax_15>", "goil_syntax", 232}, // at index 75
 {"<select_goil_5F_syntax_16>", "goil_syntax", 234}, // at index 76
 {"<select_goil_5F_syntax_16>", "goil_syntax", 236}, // at index 77
 {"<select_goil_5F_syntax_17>", "goil_syntax", 238}, // at index 78
 {"<select_goil_5F_syntax_17>", "goil_syntax", 240}, // at index 79
 {"<select_implementation_5F_parser_0>", "implementation_parser", 242}, // at index 80
 {"<select_implementation_5F_parser_0>", "implementation_parser", 243}, // at index 81
 {"<select_implementation_5F_parser_0>", "implementation_parser", 247}, // at index 82
 {"<select_implementation_5F_parser_1>", "implementation_parser", 250}, // at index 83
 {"<select_implementation_5F_parser_1>", "implementation_parser", 252}, // at index 84
 {"<select_implementation_5F_parser_2>", "implementation_parser", 254}, // at index 85
 {"<select_implementation_5F_parser_2>", "implementation_parser", 256}, // at index 86
 {"<select_implementation_5F_parser_3>", "implementation_parser", 258}, // at index 87
 {"<select_implementation_5F_parser_3>", "implementation_parser", 260}, // at index 88
 {"<select_implementation_5F_parser_4>", "implementation_parser", 262}, // at index 89
 {"<select_implementation_5F_parser_4>", "implementation_parser", 264}, // at index 90
 {"<select_implementation_5F_parser_5>", "implementation_parser", 266}, // at index 91
 {"<select_implementation_5F_parser_5>", "implementation_parser", 269}, // at index 92
 {"<select_implementation_5F_parser_6>", "implementation_parser", 270}, // at index 93
 {"<select_implementation_5F_parser_6>", "implementation_parser", 271}, // at index 94
 {"<select_implementation_5F_parser_6>", "implementation_parser", 275}, // at index 95
 {"<select_implementation_5F_parser_7>", "implementation_parser", 278}, // at index 96
 {"<select_implementation_5F_parser_7>", "implementation_parser", 281}, // at index 97
 {"<select_implementation_5F_parser_7>", "implementation_parser", 284}, // at index 98
 {"<select_implementation_5F_parser_7>", "implementation_parser", 287}, // at index 99
 {"<select_implementation_5F_parser_7>", "implementation_parser", 290}, // at index 100
 {"<select_implementation_5F_parser_7>", "implementation_parser", 293}, // at index 101
 {"<select_implementation_5F_parser_7>", "implementation_parser", 296}, // at index 102
 {"<select_implementation_5F_parser_7>", "implementation_parser", 299}, // at index 103
 {"<select_implementation_5F_parser_7>", "implementation_parser", 302}, // at index 104
 {"<select_implementation_5F_parser_7>", "implementation_parser", 305}, // at index 105
 {"<select_implementation_5F_parser_7>", "implementation_parser", 308}, // at index 106
 {"<select_implementation_5F_parser_8>", "implementation_parser", 311}, // at index 107
 {"<select_implementation_5F_parser_8>", "implementation_parser", 315}, // at index 108
 {"<select_implementation_5F_parser_9>", "implementation_parser", 316}, // at index 109
 {"<select_implementation_5F_parser_9>", "implementation_parser", 319}, // at index 110
 {"<select_implementation_5F_parser_10>", "implementation_parser", 321}, // at index 111
 {"<select_implementation_5F_parser_10>", "implementation_parser", 324}, // at index 112
 {"<select_implementation_5F_parser_10>", "implementation_parser", 327}, // at index 113
 {"<select_implementation_5F_parser_11>", "implementation_parser", 330}, // at index 114
 {"<select_implementation_5F_parser_11>", "implementation_parser", 338}, // at index 115
 {"<select_implementation_5F_parser_12>", "implementation_parser", 339}, // at index 116
 {"<select_implementation_5F_parser_12>", "implementation_parser", 343}, // at index 117
 {"<select_implementation_5F_parser_13>", "implementation_parser", 344}, // at index 118
 {"<select_implementation_5F_parser_13>", "implementation_parser", 348}, // at index 119
 {"<select_implementation_5F_parser_14>", "implementation_parser", 349}, // at index 120
 {"<select_implementation_5F_parser_14>", "implementation_parser", 353}, // at index 121
 {"<select_implementation_5F_parser_15>", "implementation_parser", 355}, // at index 122
 {"<select_implementation_5F_parser_15>", "implementation_parser", 359}, // at index 123
 {"<select_implementation_5F_parser_16>", "implementation_parser", 360}, // at index 124
 {"<select_implementation_5F_parser_16>", "implementation_parser", 361}, // at index 125
 {"<select_implementation_5F_parser_17>", "implementation_parser", 365}, // at index 126
 {"<select_implementation_5F_parser_17>", "implementation_parser", 368}, // at index 127
 {"<select_implementation_5F_parser_18>", "implementation_parser", 370}, // at index 128
 {"<select_implementation_5F_parser_18>", "implementation_parser", 373}, // at index 129
 {"<select_implementation_5F_parser_18>", "implementation_parser", 376}, // at index 130
 {"<select_implementation_5F_parser_19>", "implementation_parser", 379}, // at index 131
 {"<select_implementation_5F_parser_19>", "implementation_parser", 382}, // at index 132
 {"<select_implementation_5F_parser_20>", "implementation_parser", 384}, // at index 133
 {"<select_implementation_5F_parser_20>", "implementation_parser", 386}, // at index 134
 {"<select_implementation_5F_parser_20>", "implementation_parser", 389}, // at index 135
 {"<select_implementation_5F_parser_21>", "implementation_parser", 392}, // at index 136
 {"<select_implementation_5F_parser_21>", "implementation_parser", 395}, // at index 137
 {"<select_implementation_5F_parser_22>", "implementation_parser", 397}, // at index 138
 {"<select_implementation_5F_parser_22>", "implementation_parser", 400}, // at index 139
 {"<select_implementation_5F_parser_22>", "implementation_parser", 403}, // at index 140
 {"<select_implementation_5F_parser_23>", "implementation_parser", 406}, // at index 141
 {"<select_implementation_5F_parser_23>", "implementation_parser", 408}, // at index 142
 {"<select_implementation_5F_parser_24>", "implementation_parser", 409}, // at index 143
 {"<select_implementation_5F_parser_24>", "implementation_parser", 412}, // at index 144
 {"<select_implementation_5F_parser_25>", "implementation_parser", 415}, // at index 145
 {"<select_implementation_5F_parser_25>", "implementation_parser", 416}, // at index 146
 {"<select_implementation_5F_parser_26>", "implementation_parser", 420}, // at index 147
 {"<select_implementation_5F_parser_26>", "implementation_parser", 423}, // at index 148
 {"<select_implementation_5F_parser_26>", "implementation_parser", 426}, // at index 149
 {"<select_implementation_5F_parser_27>", "implementation_parser", 429}, // at index 150
 {"<select_implementation_5F_parser_27>", "implementation_parser", 432}, // at index 151
 {"<select_implementation_5F_parser_28>", "implementation_parser", 434}, // at index 152
 {"<select_implementation_5F_parser_28>", "implementation_parser", 437}, // at index 153
 {"<select_implementation_5F_parser_29>", "implementation_parser", 439}, // at index 154
 {"<select_implementation_5F_parser_29>", "implementation_parser", 443}, // at index 155
 {"<select_implementation_5F_parser_30>", "implementation_parser", 444}, // at index 156
 {"<select_implementation_5F_parser_30>", "implementation_parser", 447}, // at index 157
 {"<>", "", 448} // at index 158
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                 L L ( 1 )    P R O D U C T I O N    I N D E X E S                                    
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gProductionIndexes_goil_grammar [159] = {
0, // index 0 : <implementation_definition>, in file 'implementation_parser.ggs', line 55
7, // index 1 : <start>, in file 'goil_syntax.ggs', line 38
10, // index 2 : <file>, in file 'goil_syntax.ggs', line 110
12, // index 3 : <sign>, in file 'goil_syntax.ggs', line 126
14, // index 4 : <description>, in file 'goil_syntax.ggs', line 139
16, // index 5 : <OIL_version>, in file 'goil_syntax.ggs', line 163
22, // index 6 : <application_definition>, in file 'goil_syntax.ggs', line 170
30, // index 7 : <object_definition_list>, in file 'goil_syntax.ggs', line 184
32, // index 8 : <boolean>, in file 'goil_syntax.ggs', line 234
34, // index 9 : <oil_declaration_list>, in file 'goil_syntax.ggs', line 244
36, // index 10 : <oil_declaration>, in file 'goil_syntax.ggs', line 256
40, // index 11 : <include_file_level>, in file 'goil_syntax.ggs', line 451
43, // index 12 : <include_cpu_level>, in file 'goil_syntax.ggs', line 475
46, // index 13 : <include_object_level>, in file 'goil_syntax.ggs', line 499
49, // index 14 : <implementation_object_list>, in file 'implementation_parser.ggs', line 62
51, // index 15 : <include_implementation_level>, in file 'implementation_parser.ggs', line 71
54, // index 16 : <include_type_level>, in file 'implementation_parser.ggs', line 92
57, // index 17 : <implementation_objects>, in file 'implementation_parser.ggs', line 135
63, // index 18 : <implementation_list>, in file 'implementation_parser.ggs', line 183
65, // index 19 : <implementation_type>, in file 'implementation_parser.ggs', line 261
67, // index 20 : <struct_options>, in file 'implementation_parser.ggs', line 289
72, // index 21 : <objref_option>, in file 'implementation_parser.ggs', line 306
76, // index 22 : <string_options>, in file 'implementation_parser.ggs', line 324
81, // index 23 : <boolean_options>, in file 'implementation_parser.ggs', line 361
87, // index 24 : <enum_item>, in file 'implementation_parser.ggs', line 406
90, // index 25 : <enum_options>, in file 'implementation_parser.ggs', line 419
99, // index 26 : <number_options>, in file 'implementation_parser.ggs', line 466
105, // index 27 : <type_options>, in file 'implementation_parser.ggs', line 505
110, // index 28 : <with_auto>, in file 'implementation_parser.ggs', line 544
112, // index 29 : <int_or_float>, in file 'implementation_parser.ggs', line 553
115, // index 30 : <set_followup>, in file 'implementation_parser.ggs', line 571
117, // index 31 : <range_content>, in file 'implementation_parser.ggs', line 583
120, // index 32 : <range>, in file 'implementation_parser.ggs', line 623
122, // index 33 : <multiple>, in file 'implementation_parser.ggs', line 633
124, // index 34 : <identifier_or_attribute>, in file 'implementation_parser.ggs', line 643
126, // index 35 : <identifier_or_enum_value>, in file 'implementation_parser.ggs', line 648
128, // index 36 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
129, // index 37 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
132, // index 38 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
135, // index 39 : <select_goil_5F_syntax_0>, in file 'goil_syntax.ggs', line 119
138, // index 40 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
140, // index 41 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
142, // index 42 : <select_goil_5F_syntax_1>, in file 'goil_syntax.ggs', line 127
143, // index 43 : <select_goil_5F_syntax_2>, in file 'goil_syntax.ggs', line 140
144, // index 44 : <select_goil_5F_syntax_2>, in file 'goil_syntax.ggs', line 140
148, // index 45 : <select_goil_5F_syntax_3>, in file 'goil_syntax.ggs', line 147
149, // index 46 : <select_goil_5F_syntax_3>, in file 'goil_syntax.ggs', line 147
152, // index 47 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
153, // index 48 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
162, // index 49 : <select_goil_5F_syntax_4>, in file 'goil_syntax.ggs', line 190
165, // index 50 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 235
167, // index 51 : <select_goil_5F_syntax_5>, in file 'goil_syntax.ggs', line 235
169, // index 52 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 248
170, // index 53 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 248
173, // index 54 : <select_goil_5F_syntax_6>, in file 'goil_syntax.ggs', line 248
176, // index 55 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 273
179, // index 56 : <select_goil_5F_syntax_7>, in file 'goil_syntax.ggs', line 273
185, // index 57 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 275
189, // index 58 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 275
192, // index 59 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 275
196, // index 60 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 275
199, // index 61 : <select_goil_5F_syntax_8>, in file 'goil_syntax.ggs', line 275
202, // index 62 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 296
206, // index 63 : <select_goil_5F_syntax_9>, in file 'goil_syntax.ggs', line 296
207, // index 64 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 313
210, // index 65 : <select_goil_5F_syntax_10>, in file 'goil_syntax.ggs', line 313
213, // index 66 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 344
217, // index 67 : <select_goil_5F_syntax_11>, in file 'goil_syntax.ggs', line 344
218, // index 68 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 458
220, // index 69 : <select_goil_5F_syntax_12>, in file 'goil_syntax.ggs', line 458
222, // index 70 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 464
224, // index 71 : <select_goil_5F_syntax_13>, in file 'goil_syntax.ggs', line 464
226, // index 72 : <select_goil_5F_syntax_14>, in file 'goil_syntax.ggs', line 482
228, // index 73 : <select_goil_5F_syntax_14>, in file 'goil_syntax.ggs', line 482
230, // index 74 : <select_goil_5F_syntax_15>, in file 'goil_syntax.ggs', line 488
232, // index 75 : <select_goil_5F_syntax_15>, in file 'goil_syntax.ggs', line 488
234, // index 76 : <select_goil_5F_syntax_16>, in file 'goil_syntax.ggs', line 504
236, // index 77 : <select_goil_5F_syntax_16>, in file 'goil_syntax.ggs', line 504
238, // index 78 : <select_goil_5F_syntax_17>, in file 'goil_syntax.ggs', line 510
240, // index 79 : <select_goil_5F_syntax_17>, in file 'goil_syntax.ggs', line 510
242, // index 80 : <select_implementation_5F_parser_0>, in file 'implementation_parser.ggs', line 65
243, // index 81 : <select_implementation_5F_parser_0>, in file 'implementation_parser.ggs', line 65
247, // index 82 : <select_implementation_5F_parser_0>, in file 'implementation_parser.ggs', line 65
250, // index 83 : <select_implementation_5F_parser_1>, in file 'implementation_parser.ggs', line 75
252, // index 84 : <select_implementation_5F_parser_1>, in file 'implementation_parser.ggs', line 75
254, // index 85 : <select_implementation_5F_parser_2>, in file 'implementation_parser.ggs', line 81
256, // index 86 : <select_implementation_5F_parser_2>, in file 'implementation_parser.ggs', line 81
258, // index 87 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 96
260, // index 88 : <select_implementation_5F_parser_3>, in file 'implementation_parser.ggs', line 96
262, // index 89 : <select_implementation_5F_parser_4>, in file 'implementation_parser.ggs', line 102
264, // index 90 : <select_implementation_5F_parser_4>, in file 'implementation_parser.ggs', line 102
266, // index 91 : <select_implementation_5F_parser_5>, in file 'implementation_parser.ggs', line 142
269, // index 92 : <select_implementation_5F_parser_5>, in file 'implementation_parser.ggs', line 142
270, // index 93 : <select_implementation_5F_parser_6>, in file 'implementation_parser.ggs', line 186
271, // index 94 : <select_implementation_5F_parser_6>, in file 'implementation_parser.ggs', line 186
275, // index 95 : <select_implementation_5F_parser_6>, in file 'implementation_parser.ggs', line 186
278, // index 96 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 264
281, // index 97 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 264
284, // index 98 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 264
287, // index 99 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 264
290, // index 100 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 264
293, // index 101 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 264
296, // index 102 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 264
299, // index 103 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 264
302, // index 104 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 264
305, // index 105 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 264
308, // index 106 : <select_implementation_5F_parser_7>, in file 'implementation_parser.ggs', line 264
311, // index 107 : <select_implementation_5F_parser_8>, in file 'implementation_parser.ggs', line 293
315, // index 108 : <select_implementation_5F_parser_8>, in file 'implementation_parser.ggs', line 293
316, // index 109 : <select_implementation_5F_parser_9>, in file 'implementation_parser.ggs', line 334
319, // index 110 : <select_implementation_5F_parser_9>, in file 'implementation_parser.ggs', line 334
321, // index 111 : <select_implementation_5F_parser_10>, in file 'implementation_parser.ggs', line 336
324, // index 112 : <select_implementation_5F_parser_10>, in file 'implementation_parser.ggs', line 336
327, // index 113 : <select_implementation_5F_parser_10>, in file 'implementation_parser.ggs', line 336
330, // index 114 : <select_implementation_5F_parser_11>, in file 'implementation_parser.ggs', line 368
338, // index 115 : <select_implementation_5F_parser_11>, in file 'implementation_parser.ggs', line 368
339, // index 116 : <select_implementation_5F_parser_12>, in file 'implementation_parser.ggs', line 371
343, // index 117 : <select_implementation_5F_parser_12>, in file 'implementation_parser.ggs', line 371
344, // index 118 : <select_implementation_5F_parser_13>, in file 'implementation_parser.ggs', line 380
348, // index 119 : <select_implementation_5F_parser_13>, in file 'implementation_parser.ggs', line 380
349, // index 120 : <select_implementation_5F_parser_14>, in file 'implementation_parser.ggs', line 394
353, // index 121 : <select_implementation_5F_parser_14>, in file 'implementation_parser.ggs', line 394
355, // index 122 : <select_implementation_5F_parser_15>, in file 'implementation_parser.ggs', line 411
359, // index 123 : <select_implementation_5F_parser_15>, in file 'implementation_parser.ggs', line 411
360, // index 124 : <select_implementation_5F_parser_16>, in file 'implementation_parser.ggs', line 427
361, // index 125 : <select_implementation_5F_parser_16>, in file 'implementation_parser.ggs', line 427
365, // index 126 : <select_implementation_5F_parser_17>, in file 'implementation_parser.ggs', line 437
368, // index 127 : <select_implementation_5F_parser_17>, in file 'implementation_parser.ggs', line 437
370, // index 128 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 439
373, // index 129 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 439
376, // index 130 : <select_implementation_5F_parser_18>, in file 'implementation_parser.ggs', line 439
379, // index 131 : <select_implementation_5F_parser_19>, in file 'implementation_parser.ggs', line 479
382, // index 132 : <select_implementation_5F_parser_19>, in file 'implementation_parser.ggs', line 479
384, // index 133 : <select_implementation_5F_parser_20>, in file 'implementation_parser.ggs', line 481
386, // index 134 : <select_implementation_5F_parser_20>, in file 'implementation_parser.ggs', line 481
389, // index 135 : <select_implementation_5F_parser_20>, in file 'implementation_parser.ggs', line 481
392, // index 136 : <select_implementation_5F_parser_21>, in file 'implementation_parser.ggs', line 516
395, // index 137 : <select_implementation_5F_parser_21>, in file 'implementation_parser.ggs', line 516
397, // index 138 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 518
400, // index 139 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 518
403, // index 140 : <select_implementation_5F_parser_22>, in file 'implementation_parser.ggs', line 518
406, // index 141 : <select_implementation_5F_parser_23>, in file 'implementation_parser.ggs', line 546
408, // index 142 : <select_implementation_5F_parser_23>, in file 'implementation_parser.ggs', line 546
409, // index 143 : <select_implementation_5F_parser_24>, in file 'implementation_parser.ggs', line 558
412, // index 144 : <select_implementation_5F_parser_24>, in file 'implementation_parser.ggs', line 558
415, // index 145 : <select_implementation_5F_parser_25>, in file 'implementation_parser.ggs', line 574
416, // index 146 : <select_implementation_5F_parser_25>, in file 'implementation_parser.ggs', line 574
420, // index 147 : <select_implementation_5F_parser_26>, in file 'implementation_parser.ggs', line 590
423, // index 148 : <select_implementation_5F_parser_26>, in file 'implementation_parser.ggs', line 590
426, // index 149 : <select_implementation_5F_parser_26>, in file 'implementation_parser.ggs', line 590
429, // index 150 : <select_implementation_5F_parser_27>, in file 'implementation_parser.ggs', line 600
432, // index 151 : <select_implementation_5F_parser_27>, in file 'implementation_parser.ggs', line 600
434, // index 152 : <select_implementation_5F_parser_28>, in file 'implementation_parser.ggs', line 612
437, // index 153 : <select_implementation_5F_parser_28>, in file 'implementation_parser.ggs', line 612
439, // index 154 : <select_implementation_5F_parser_29>, in file 'implementation_parser.ggs', line 626
443, // index 155 : <select_implementation_5F_parser_29>, in file 'implementation_parser.ggs', line 626
444, // index 156 : <select_implementation_5F_parser_30>, in file 'implementation_parser.ggs', line 635
447, // index 157 : <select_implementation_5F_parser_30>, in file 'implementation_parser.ggs', line 635
448 // index 158 : <>, in file '.ggs', line 0
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                           L L ( 1 )    F I R S T    P R O D U C T I O N    I N D E X E S                             
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gFirstProductionIndexes_goil_grammar [87] = {
0, // at 0 : <implementation_definition>
1, // at 1 : <start>
2, // at 2 : <file>
3, // at 3 : <sign>
4, // at 4 : <description>
5, // at 5 : <OIL_version>
6, // at 6 : <application_definition>
7, // at 7 : <object_definition_list>
8, // at 8 : <boolean>
9, // at 9 : <oil_declaration_list>
10, // at 10 : <oil_declaration>
11, // at 11 : <include_file_level>
12, // at 12 : <include_cpu_level>
13, // at 13 : <include_object_level>
14, // at 14 : <implementation_object_list>
15, // at 15 : <include_implementation_level>
16, // at 16 : <include_type_level>
17, // at 17 : <implementation_objects>
18, // at 18 : <implementation_list>
19, // at 19 : <implementation_type>
20, // at 20 : <struct_options>
21, // at 21 : <objref_option>
22, // at 22 : <string_options>
23, // at 23 : <boolean_options>
24, // at 24 : <enum_item>
25, // at 25 : <enum_options>
26, // at 26 : <number_options>
27, // at 27 : <type_options>
28, // at 28 : <with_auto>
29, // at 29 : <int_or_float>
30, // at 30 : <set_followup>
31, // at 31 : <range_content>
32, // at 32 : <range>
33, // at 33 : <multiple>
34, // at 34 : <identifier_or_attribute>
35, // at 35 : <identifier_or_enum_value>
36, // at 36 : <select_goil_5F_syntax_0>
40, // at 37 : <select_goil_5F_syntax_1>
43, // at 38 : <select_goil_5F_syntax_2>
45, // at 39 : <select_goil_5F_syntax_3>
47, // at 40 : <select_goil_5F_syntax_4>
50, // at 41 : <select_goil_5F_syntax_5>
52, // at 42 : <select_goil_5F_syntax_6>
55, // at 43 : <select_goil_5F_syntax_7>
57, // at 44 : <select_goil_5F_syntax_8>
62, // at 45 : <select_goil_5F_syntax_9>
64, // at 46 : <select_goil_5F_syntax_10>
66, // at 47 : <select_goil_5F_syntax_11>
68, // at 48 : <select_goil_5F_syntax_12>
70, // at 49 : <select_goil_5F_syntax_13>
72, // at 50 : <select_goil_5F_syntax_14>
74, // at 51 : <select_goil_5F_syntax_15>
76, // at 52 : <select_goil_5F_syntax_16>
78, // at 53 : <select_goil_5F_syntax_17>
80, // at 54 : <select_implementation_5F_parser_0>
83, // at 55 : <select_implementation_5F_parser_1>
85, // at 56 : <select_implementation_5F_parser_2>
87, // at 57 : <select_implementation_5F_parser_3>
89, // at 58 : <select_implementation_5F_parser_4>
91, // at 59 : <select_implementation_5F_parser_5>
93, // at 60 : <select_implementation_5F_parser_6>
96, // at 61 : <select_implementation_5F_parser_7>
107, // at 62 : <select_implementation_5F_parser_8>
109, // at 63 : <select_implementation_5F_parser_9>
111, // at 64 : <select_implementation_5F_parser_10>
114, // at 65 : <select_implementation_5F_parser_11>
116, // at 66 : <select_implementation_5F_parser_12>
118, // at 67 : <select_implementation_5F_parser_13>
120, // at 68 : <select_implementation_5F_parser_14>
122, // at 69 : <select_implementation_5F_parser_15>
124, // at 70 : <select_implementation_5F_parser_16>
126, // at 71 : <select_implementation_5F_parser_17>
128, // at 72 : <select_implementation_5F_parser_18>
131, // at 73 : <select_implementation_5F_parser_19>
133, // at 74 : <select_implementation_5F_parser_20>
136, // at 75 : <select_implementation_5F_parser_21>
138, // at 76 : <select_implementation_5F_parser_22>
141, // at 77 : <select_implementation_5F_parser_23>
143, // at 78 : <select_implementation_5F_parser_24>
145, // at 79 : <select_implementation_5F_parser_25>
147, // at 80 : <select_implementation_5F_parser_26>
150, // at 81 : <select_implementation_5F_parser_27>
152, // at 82 : <select_implementation_5F_parser_28>
154, // at 83 : <select_implementation_5F_parser_29>
156, // at 84 : <select_implementation_5F_parser_30>
158, // at 85 : <>
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                    L L ( 1 )    D E C I S I O N    T A B L E S                                       
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gDecision_goil_grammar [] = {
// At index 0 : <implementation_definition> only one production, no choice
  -1,
// At index 1 : <start> only one production, no choice
  -1,
// At index 2 : <file> only one production, no choice
  -1,
// At index 3 : <sign> only one production, no choice
  -1,
// At index 4 : <description> only one production, no choice
  -1,
// At index 5 : <OIL_version> only one production, no choice
  -1,
// At index 6 : <application_definition> only one production, no choice
  -1,
// At index 7 : <object_definition_list> only one production, no choice
  -1,
// At index 8 : <boolean> only one production, no choice
  -1,
// At index 9 : <oil_declaration_list> only one production, no choice
  -1,
// At index 10 : <oil_declaration> only one production, no choice
  -1,
// At index 11 : <include_file_level> only one production, no choice
  -1,
// At index 12 : <include_cpu_level> only one production, no choice
  -1,
// At index 13 : <include_object_level> only one production, no choice
  -1,
// At index 14 : <implementation_object_list> only one production, no choice
  -1,
// At index 15 : <include_implementation_level> only one production, no choice
  -1,
// At index 16 : <include_type_level> only one production, no choice
  -1,
// At index 17 : <implementation_objects> only one production, no choice
  -1,
// At index 18 : <implementation_list> only one production, no choice
  -1,
// At index 19 : <implementation_type> only one production, no choice
  -1,
// At index 20 : <struct_options> only one production, no choice
  -1,
// At index 21 : <objref_option> only one production, no choice
  -1,
// At index 22 : <string_options> only one production, no choice
  -1,
// At index 23 : <boolean_options> only one production, no choice
  -1,
// At index 24 : <enum_item> only one production, no choice
  -1,
// At index 25 : <enum_options> only one production, no choice
  -1,
// At index 26 : <number_options> only one production, no choice
  -1,
// At index 27 : <type_options> only one production, no choice
  -1,
// At index 28 : <with_auto> only one production, no choice
  -1,
// At index 29 : <int_or_float> only one production, no choice
  -1,
// At index 30 : <set_followup> only one production, no choice
  -1,
// At index 31 : <range_content> only one production, no choice
  -1,
// At index 32 : <range> only one production, no choice
  -1,
// At index 33 : <multiple> only one production, no choice
  -1,
// At index 34 : <identifier_or_attribute> only one production, no choice
  -1,
// At index 35 : <identifier_or_enum_value> only one production, no choice
  -1,
//---- Added non terminal symbols from 'select' and 'repeat' instructions
// At index 36 : <select_goil_5F_syntax_0>
C_Lexique_goil_5F_lexique::kToken_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_include, C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_IMPLEMENTATION, -1, // Choice 3
C_Lexique_goil_5F_lexique::kToken_CPU, -1, // Choice 4
  -1,
// At index 46 : <select_goil_5F_syntax_1>
C_Lexique_goil_5F_lexique::kToken__2D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__2B_, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_uint_5F_number, C_Lexique_goil_5F_lexique::kToken_float_5F_number, C_Lexique_goil_5F_lexique::kToken_set_5F_start_5F_uint_5F_number, -1, // Choice 3
  -1,
// At index 55 : <select_goil_5F_syntax_2>
C_Lexique_goil_5F_lexique::kToken__3B_, C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, -1, // Choice 2
  -1,
// At index 62 : <select_goil_5F_syntax_3>
C_Lexique_goil_5F_lexique::kToken__3B_, C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 69 : <select_goil_5F_syntax_4>
C_Lexique_goil_5F_lexique::kToken__7D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_include, C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 3
  -1,
// At index 77 : <select_goil_5F_syntax_5>
C_Lexique_goil_5F_lexique::kToken_TRUE, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_FALSE, -1, // Choice 2
  -1,
// At index 82 : <select_goil_5F_syntax_6>
C_Lexique_goil_5F_lexique::kToken__7D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_include, C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 3
  -1,
// At index 90 : <select_goil_5F_syntax_7>
C_Lexique_goil_5F_lexique::kToken__3D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
  -1,
// At index 95 : <select_goil_5F_syntax_8>
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__2D_, C_Lexique_goil_5F_lexique::kToken__2B_, C_Lexique_goil_5F_lexique::kToken_uint_5F_number, C_Lexique_goil_5F_lexique::kToken_float_5F_number, C_Lexique_goil_5F_lexique::kToken_set_5F_start_5F_uint_5F_number, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_TRUE, C_Lexique_goil_5F_lexique::kToken_FALSE, -1, // Choice 3
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 4
C_Lexique_goil_5F_lexique::kToken_AUTO, -1, // Choice 5
  -1,
// At index 111 : <select_goil_5F_syntax_9>
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, -1, // Choice 2
  -1,
// At index 117 : <select_goil_5F_syntax_10>
C_Lexique_goil_5F_lexique::kToken_uint_5F_number, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_float_5F_number, -1, // Choice 2
  -1,
// At index 122 : <select_goil_5F_syntax_11>
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, -1, // Choice 2
  -1,
// At index 128 : <select_goil_5F_syntax_12>
C_Lexique_goil_5F_lexique::kToken_include, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
  -1,
// At index 133 : <select_goil_5F_syntax_13>
C_Lexique_goil_5F_lexique::kToken_g_5F_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 138 : <select_goil_5F_syntax_14>
C_Lexique_goil_5F_lexique::kToken_include, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
  -1,
// At index 143 : <select_goil_5F_syntax_15>
C_Lexique_goil_5F_lexique::kToken_g_5F_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 148 : <select_goil_5F_syntax_16>
C_Lexique_goil_5F_lexique::kToken_include, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
  -1,
// At index 153 : <select_goil_5F_syntax_17>
C_Lexique_goil_5F_lexique::kToken_g_5F_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 158 : <select_implementation_5F_parser_0>
C_Lexique_goil_5F_lexique::kToken__7D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_include, C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 3
  -1,
// At index 166 : <select_implementation_5F_parser_1>
C_Lexique_goil_5F_lexique::kToken_include, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
  -1,
// At index 171 : <select_implementation_5F_parser_2>
C_Lexique_goil_5F_lexique::kToken_g_5F_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 176 : <select_implementation_5F_parser_3>
C_Lexique_goil_5F_lexique::kToken_include, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 2
  -1,
// At index 181 : <select_implementation_5F_parser_4>
C_Lexique_goil_5F_lexique::kToken_g_5F_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 2
  -1,
// At index 186 : <select_implementation_5F_parser_5>
C_Lexique_goil_5F_lexique::kToken__5B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 2
  -1,
// At index 191 : <select_implementation_5F_parser_6>
C_Lexique_goil_5F_lexique::kToken__7D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, C_Lexique_goil_5F_lexique::kToken_UINT_33__32_, C_Lexique_goil_5F_lexique::kToken_INT_33__32_, C_Lexique_goil_5F_lexique::kToken_UINT_36__34_, C_Lexique_goil_5F_lexique::kToken_INT_36__34_, C_Lexique_goil_5F_lexique::kToken_FLOAT, C_Lexique_goil_5F_lexique::kToken_ENUM, C_Lexique_goil_5F_lexique::kToken_BOOLEAN, C_Lexique_goil_5F_lexique::kToken_STRING, C_Lexique_goil_5F_lexique::kToken_IDENTIFIER, C_Lexique_goil_5F_lexique::kToken_STRUCT, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_include, C_Lexique_goil_5F_lexique::kToken_includeifexists, -1, // Choice 3
  -1,
// At index 209 : <select_implementation_5F_parser_7>
C_Lexique_goil_5F_lexique::kToken_UINT_33__32_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_INT_33__32_, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_UINT_36__34_, -1, // Choice 3
C_Lexique_goil_5F_lexique::kToken_INT_36__34_, -1, // Choice 4
C_Lexique_goil_5F_lexique::kToken_FLOAT, -1, // Choice 5
C_Lexique_goil_5F_lexique::kToken_ENUM, -1, // Choice 6
C_Lexique_goil_5F_lexique::kToken_BOOLEAN, -1, // Choice 7
C_Lexique_goil_5F_lexique::kToken_STRING, -1, // Choice 8
C_Lexique_goil_5F_lexique::kToken_IDENTIFIER, -1, // Choice 9
C_Lexique_goil_5F_lexique::kToken_STRUCT, -1, // Choice 10
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 11
  -1,
// At index 232 : <select_implementation_5F_parser_8>
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
  -1,
// At index 237 : <select_implementation_5F_parser_9>
C_Lexique_goil_5F_lexique::kToken__3D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 245 : <select_implementation_5F_parser_10>
C_Lexique_goil_5F_lexique::kToken_string, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_AUTO, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT, -1, // Choice 3
  -1,
// At index 252 : <select_implementation_5F_parser_11>
C_Lexique_goil_5F_lexique::kToken__5B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
  -1,
// At index 257 : <select_implementation_5F_parser_12>
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 262 : <select_implementation_5F_parser_13>
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__5D_, -1, // Choice 2
  -1,
// At index 267 : <select_implementation_5F_parser_14>
C_Lexique_goil_5F_lexique::kToken__3D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 275 : <select_implementation_5F_parser_15>
C_Lexique_goil_5F_lexique::kToken__7B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 281 : <select_implementation_5F_parser_16>
C_Lexique_goil_5F_lexique::kToken__5D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 286 : <select_implementation_5F_parser_17>
C_Lexique_goil_5F_lexique::kToken__3D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 294 : <select_implementation_5F_parser_18>
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_AUTO, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT, -1, // Choice 3
  -1,
// At index 301 : <select_implementation_5F_parser_19>
C_Lexique_goil_5F_lexique::kToken__3D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 309 : <select_implementation_5F_parser_20>
C_Lexique_goil_5F_lexique::kToken__2D_, C_Lexique_goil_5F_lexique::kToken__2B_, C_Lexique_goil_5F_lexique::kToken_uint_5F_number, C_Lexique_goil_5F_lexique::kToken_float_5F_number, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_AUTO, -1, // Choice 3
  -1,
// At index 319 : <select_implementation_5F_parser_21>
C_Lexique_goil_5F_lexique::kToken__3D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3B_, C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 327 : <select_implementation_5F_parser_22>
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_NO_5F_DEFAULT, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_AUTO, -1, // Choice 3
  -1,
// At index 334 : <select_implementation_5F_parser_23>
C_Lexique_goil_5F_lexique::kToken_WITH_5F_AUTO, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, C_Lexique_goil_5F_lexique::kToken__5B_, -1, // Choice 2
  -1,
// At index 340 : <select_implementation_5F_parser_24>
C_Lexique_goil_5F_lexique::kToken_uint_5F_number, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_float_5F_number, -1, // Choice 2
  -1,
// At index 345 : <select_implementation_5F_parser_25>
C_Lexique_goil_5F_lexique::kToken__5D_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 350 : <select_implementation_5F_parser_26>
C_Lexique_goil_5F_lexique::kToken_set_5F_start_5F_uint_5F_number, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_uint_5F_number, -1, // Choice 2
C_Lexique_goil_5F_lexique::kToken_float_5F_number, -1, // Choice 3
  -1,
// At index 357 : <select_implementation_5F_parser_27>
C_Lexique_goil_5F_lexique::kToken__2E__2E_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 363 : <select_implementation_5F_parser_28>
C_Lexique_goil_5F_lexique::kToken__2E__2E_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__5D_, C_Lexique_goil_5F_lexique::kToken__2C_, -1, // Choice 2
  -1,
// At index 369 : <select_implementation_5F_parser_29>
C_Lexique_goil_5F_lexique::kToken__5B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken_idf, -1, // Choice 2
  -1,
// At index 374 : <select_implementation_5F_parser_30>
C_Lexique_goil_5F_lexique::kToken__5B_, -1, // Choice 1
C_Lexique_goil_5F_lexique::kToken__3A_, C_Lexique_goil_5F_lexique::kToken__3D_, C_Lexique_goil_5F_lexique::kToken__3B_, -1, // Choice 2
  -1,
// At index 381 : <> only one production, no choice
  -1,
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            L L ( 1 )    D E C I S I O N    T A B L E S    I N D E X E S                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gDecisionIndexes_goil_grammar [87] = {
0, // at 0 : <implementation_definition>
1, // at 1 : <start>
2, // at 2 : <file>
3, // at 3 : <sign>
4, // at 4 : <description>
5, // at 5 : <OIL_version>
6, // at 6 : <application_definition>
7, // at 7 : <object_definition_list>
8, // at 8 : <boolean>
9, // at 9 : <oil_declaration_list>
10, // at 10 : <oil_declaration>
11, // at 11 : <include_file_level>
12, // at 12 : <include_cpu_level>
13, // at 13 : <include_object_level>
14, // at 14 : <implementation_object_list>
15, // at 15 : <include_implementation_level>
16, // at 16 : <include_type_level>
17, // at 17 : <implementation_objects>
18, // at 18 : <implementation_list>
19, // at 19 : <implementation_type>
20, // at 20 : <struct_options>
21, // at 21 : <objref_option>
22, // at 22 : <string_options>
23, // at 23 : <boolean_options>
24, // at 24 : <enum_item>
25, // at 25 : <enum_options>
26, // at 26 : <number_options>
27, // at 27 : <type_options>
28, // at 28 : <with_auto>
29, // at 29 : <int_or_float>
30, // at 30 : <set_followup>
31, // at 31 : <range_content>
32, // at 32 : <range>
33, // at 33 : <multiple>
34, // at 34 : <identifier_or_attribute>
35, // at 35 : <identifier_or_enum_value>
36, // at 36 : <select_goil_5F_syntax_0>
46, // at 37 : <select_goil_5F_syntax_1>
55, // at 38 : <select_goil_5F_syntax_2>
62, // at 39 : <select_goil_5F_syntax_3>
69, // at 40 : <select_goil_5F_syntax_4>
77, // at 41 : <select_goil_5F_syntax_5>
82, // at 42 : <select_goil_5F_syntax_6>
90, // at 43 : <select_goil_5F_syntax_7>
95, // at 44 : <select_goil_5F_syntax_8>
111, // at 45 : <select_goil_5F_syntax_9>
117, // at 46 : <select_goil_5F_syntax_10>
122, // at 47 : <select_goil_5F_syntax_11>
128, // at 48 : <select_goil_5F_syntax_12>
133, // at 49 : <select_goil_5F_syntax_13>
138, // at 50 : <select_goil_5F_syntax_14>
143, // at 51 : <select_goil_5F_syntax_15>
148, // at 52 : <select_goil_5F_syntax_16>
153, // at 53 : <select_goil_5F_syntax_17>
158, // at 54 : <select_implementation_5F_parser_0>
166, // at 55 : <select_implementation_5F_parser_1>
171, // at 56 : <select_implementation_5F_parser_2>
176, // at 57 : <select_implementation_5F_parser_3>
181, // at 58 : <select_implementation_5F_parser_4>
186, // at 59 : <select_implementation_5F_parser_5>
191, // at 60 : <select_implementation_5F_parser_6>
209, // at 61 : <select_implementation_5F_parser_7>
232, // at 62 : <select_implementation_5F_parser_8>
237, // at 63 : <select_implementation_5F_parser_9>
245, // at 64 : <select_implementation_5F_parser_10>
252, // at 65 : <select_implementation_5F_parser_11>
257, // at 66 : <select_implementation_5F_parser_12>
262, // at 67 : <select_implementation_5F_parser_13>
267, // at 68 : <select_implementation_5F_parser_14>
275, // at 69 : <select_implementation_5F_parser_15>
281, // at 70 : <select_implementation_5F_parser_16>
286, // at 71 : <select_implementation_5F_parser_17>
294, // at 72 : <select_implementation_5F_parser_18>
301, // at 73 : <select_implementation_5F_parser_19>
309, // at 74 : <select_implementation_5F_parser_20>
319, // at 75 : <select_implementation_5F_parser_21>
327, // at 76 : <select_implementation_5F_parser_22>
334, // at 77 : <select_implementation_5F_parser_23>
340, // at 78 : <select_implementation_5F_parser_24>
345, // at 79 : <select_implementation_5F_parser_25>
350, // at 80 : <select_implementation_5F_parser_26>
357, // at 81 : <select_implementation_5F_parser_27>
363, // at 82 : <select_implementation_5F_parser_28>
369, // at 83 : <select_implementation_5F_parser_29>
374, // at 84 : <select_implementation_5F_parser_30>
381, // at 85 : <>
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                              'implementation_definition' non terminal implementation                                 
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::nt_implementation_5F_definition_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_definition_i0_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_implementation_5F_definition_ (GALGAS_implementation & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_definition_i0_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                        'start' non terminal implementation                                           
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::nt_start_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_start_i0_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_start_ (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_start_i0_(inLexique) ;
}

void cGrammar_goil_5F_grammar::performIndexing (C_Compiler * /* inCompiler */,
             const C_String & /* inSourceFilePath */) {
}

void cGrammar_goil_5F_grammar::performOnlyLexicalAnalysis (C_Compiler * inCompiler,
             const C_String & inSourceFilePath) {
  C_Lexique_goil_5F_lexique * scanner = NULL ;
  macroMyNew (scanner, C_Lexique_goil_5F_lexique (inCompiler, inSourceFilePath COMMA_HERE)) ;
  if (scanner->sourceText ().isValid ()) {
    scanner->performLexicalAnalysis () ;
  }
  macroDetachSharedObject (scanner) ;
}

void cGrammar_goil_5F_grammar::performOnlySyntaxAnalysis (C_Compiler * inCompiler,
             const C_String & inSourceFilePath) {
  C_Lexique_goil_5F_lexique * scanner = NULL ;
  macroMyNew (scanner, C_Lexique_goil_5F_lexique (inCompiler, inSourceFilePath COMMA_HERE)) ;
  if (scanner->sourceText ().isValid ()) {
    scanner->performTopDownParsing (gProductions_goil_grammar, gProductionNames_goil_grammar, gProductionIndexes_goil_grammar,
                                    gFirstProductionIndexes_goil_grammar, gDecision_goil_grammar, gDecisionIndexes_goil_grammar, 448) ;
  }
  macroDetachSharedObject (scanner) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                        Grammar start symbol implementation                                           
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::_performSourceFileParsing_ (C_Compiler * inCompiler,
                                GALGAS_lstring inFilePath
                                COMMA_LOCATION_ARGS) {
  if (inFilePath.isValid ()) {
    const GALGAS_string filePathAsString = inFilePath.getter_string (HERE) ;
    C_String filePath = filePathAsString.stringValue () ;
    if (! C_FileManager::isAbsolutePath (filePath)) {
      filePath = inCompiler->sourceFilePath ().stringByDeletingLastPathComponent ().stringByAppendingPathComponent (filePath) ;
    }
    if (C_FileManager::fileExistsAtPath (filePath)) {
    C_Lexique_goil_5F_lexique * scanner = NULL ;
    macroMyNew (scanner, C_Lexique_goil_5F_lexique (inCompiler, filePath COMMA_HERE)) ;
    if (scanner->sourceText ().isValid ()) {
      const bool ok = scanner->performTopDownParsing (gProductions_goil_grammar, gProductionNames_goil_grammar, gProductionIndexes_goil_grammar,
                                                      gFirstProductionIndexes_goil_grammar, gDecision_goil_grammar, gDecisionIndexes_goil_grammar, 448) ;
      if (ok && ! executionModeIsSyntaxAnalysisOnly ()) {
        cGrammar_goil_5F_grammar grammar ;
        grammar.nt_start_ (scanner) ;
        }
      }else{
        C_String message ;
        message << "the '" << filePath << "' file exists, but cannot be read" ;
        const GALGAS_location errorLocation (inFilePath.getter_location (THERE)) ;
        inCompiler->semanticErrorAtLocation (errorLocation, message, TC_Array <C_FixItDescription> () COMMA_THERE) ;
      }
      macroDetachSharedObject (scanner) ;
    }else{
      C_String message ;
      message << "the '" << filePath << "' file does not exist" ;
      const GALGAS_location errorLocation (inFilePath.getter_location (THERE)) ;
      inCompiler->semanticErrorAtLocation (errorLocation, message, TC_Array <C_FixItDescription> () COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::_performSourceStringParsing_ (C_Compiler * inCompiler,
                                GALGAS_string inSourceString,
                                GALGAS_string inNameString
                                COMMA_UNUSED_LOCATION_ARGS) {
  if (inSourceString.isValid () && inNameString.isValid ()) {
    const C_String sourceString = inSourceString.stringValue () ;
    const C_String nameString = inNameString.stringValue () ;
    C_Lexique_goil_5F_lexique * scanner = NULL ;
    macroMyNew (scanner, C_Lexique_goil_5F_lexique (inCompiler, sourceString, nameString COMMA_HERE)) ;
    const bool ok = scanner->performTopDownParsing (gProductions_goil_grammar, gProductionNames_goil_grammar, gProductionIndexes_goil_grammar,
                                                    gFirstProductionIndexes_goil_grammar, gDecision_goil_grammar, gDecisionIndexes_goil_grammar, 448) ;
    if (ok && ! executionModeIsSyntaxAnalysisOnly ()) {
      cGrammar_goil_5F_grammar grammar ;
      grammar.nt_start_ (scanner) ;
    }
    macroDetachSharedObject (scanner) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                         'file' non terminal implementation                                           
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::nt_file_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_file_i1_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_file_ (GALGAS_implementation & parameter_1,
                                GALGAS_applicationDefinition & parameter_2,
                                GALGAS_string & parameter_3,
                                const GALGAS_bool parameter_4,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_file_i1_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                         'sign' non terminal implementation                                           
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::nt_sign_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_sign_i2_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_sign_ (GALGAS_bool & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_sign_i2_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                     'description' non terminal implementation                                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::nt_description_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_description_i3_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_description_ (GALGAS_lstring & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_description_i3_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                     'OIL_version' non terminal implementation                                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::nt_OIL_5F_version_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_OIL_5F_version_i4_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_OIL_5F_version_ (GALGAS_lstring & parameter_1,
                                GALGAS_lstring & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_OIL_5F_version_i4_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                'application_definition' non terminal implementation                                  
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::nt_application_5F_definition_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_application_5F_definition_i5_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_application_5F_definition_ (const GALGAS_implementation parameter_1,
                                GALGAS_applicationDefinition & parameter_2,
                                GALGAS_string & parameter_3,
                                const GALGAS_bool parameter_4,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_application_5F_definition_i5_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                'object_definition_list' non terminal implementation                                  
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::nt_object_5F_definition_5F_list_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_object_5F_definition_5F_list_i6_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_object_5F_definition_5F_list_ (const GALGAS_implementation parameter_1,
                                GALGAS_objectsMap & parameter_2,
                                GALGAS_string & parameter_3,
                                const GALGAS_bool parameter_4,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_object_5F_definition_5F_list_i6_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                       'boolean' non terminal implementation                                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::nt_boolean_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_boolean_i7_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_boolean_ (GALGAS_lbool & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_boolean_i7_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                 'oil_declaration_list' non terminal implementation                                   
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::nt_oil_5F_declaration_5F_list_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_5F_list_i8_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_oil_5F_declaration_5F_list_ (const GALGAS_implementationObjectMap parameter_1,
                                GALGAS_objectAttributes & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_5F_list_i8_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                   'oil_declaration' non terminal implementation                                      
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::nt_oil_5F_declaration_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_i9_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_oil_5F_declaration_ (const GALGAS_implementationObjectMap parameter_1,
                                GALGAS_objectAttributes & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_oil_5F_declaration_i9_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                  'include_file_level' non terminal implementation                                    
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::nt_include_5F_file_5F_level_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_file_5F_level_i10_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_include_5F_file_5F_level_ (GALGAS_implementation & parameter_1,
                                GALGAS_applicationDefinition & parameter_2,
                                GALGAS_string & parameter_3,
                                const GALGAS_bool parameter_4,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_file_5F_level_i10_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                  'include_cpu_level' non terminal implementation                                     
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::nt_include_5F_cpu_5F_level_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_cpu_5F_level_i11_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_include_5F_cpu_5F_level_ (const GALGAS_implementation parameter_1,
                                GALGAS_objectsMap & parameter_2,
                                GALGAS_string & parameter_3,
                                const GALGAS_bool parameter_4,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_cpu_5F_level_i11_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                 'include_object_level' non terminal implementation                                   
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::nt_include_5F_object_5F_level_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_object_5F_level_i12_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_include_5F_object_5F_level_ (const GALGAS_implementationObjectMap parameter_1,
                                GALGAS_objectAttributes & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_goil_5F_syntax_include_5F_object_5F_level_i12_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                              'implementation_object_list' non terminal implementation                                
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::nt_implementation_5F_object_5F_list_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_object_5F_list_i1_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_implementation_5F_object_5F_list_ (GALGAS_implementation & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_object_5F_list_i1_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                             'include_implementation_level' non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::nt_include_5F_implementation_5F_level_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_include_5F_implementation_5F_level_i2_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_include_5F_implementation_5F_level_ (GALGAS_implementation & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_include_5F_implementation_5F_level_i2_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                  'include_type_level' non terminal implementation                                    
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::nt_include_5F_type_5F_level_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_include_5F_type_5F_level_i3_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_include_5F_type_5F_level_ (GALGAS_implementationObjectMap & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_include_5F_type_5F_level_i3_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                'implementation_objects' non terminal implementation                                  
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::nt_implementation_5F_objects_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_objects_i4_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_implementation_5F_objects_ (GALGAS_implementation & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_objects_i4_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                 'implementation_list' non terminal implementation                                    
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::nt_implementation_5F_list_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_list_i5_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_implementation_5F_list_ (GALGAS_implementationObjectMap & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_list_i5_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                 'implementation_type' non terminal implementation                                    
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::nt_implementation_5F_type_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_type_i6_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_implementation_5F_type_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_implementation_5F_type_i6_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                    'struct_options' non terminal implementation                                      
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::nt_struct_5F_options_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_struct_5F_options_i7_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_struct_5F_options_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_struct_5F_options_i7_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                    'objref_option' non terminal implementation                                       
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::nt_objref_5F_option_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_objref_5F_option_i8_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_objref_5F_option_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                GALGAS_lstring parameter_3,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_objref_5F_option_i8_(parameter_1, parameter_2, parameter_3, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                    'string_options' non terminal implementation                                      
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::nt_string_5F_options_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_string_5F_options_i9_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_string_5F_options_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_string_5F_options_i9_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                   'boolean_options' non terminal implementation                                      
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::nt_boolean_5F_options_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_boolean_5F_options_i10_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_boolean_5F_options_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_boolean_5F_options_i10_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                      'enum_item' non terminal implementation                                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::nt_enum_5F_item_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_enum_5F_item_i11_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_enum_5F_item_ (GALGAS_enumValues & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_enum_5F_item_i11_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                     'enum_options' non terminal implementation                                       
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::nt_enum_5F_options_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_enum_5F_options_i12_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_enum_5F_options_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_enum_5F_options_i12_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                    'number_options' non terminal implementation                                      
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::nt_number_5F_options_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_number_5F_options_i13_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_number_5F_options_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                const GALGAS_dataType parameter_3,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_number_5F_options_i13_(parameter_1, parameter_2, parameter_3, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                     'type_options' non terminal implementation                                       
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::nt_type_5F_options_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_type_5F_options_i14_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_type_5F_options_ (GALGAS_lstring & parameter_1,
                                GALGAS_impType & parameter_2,
                                const GALGAS_dataType parameter_3,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_type_5F_options_i14_(parameter_1, parameter_2, parameter_3, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                      'with_auto' non terminal implementation                                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::nt_with_5F_auto_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_with_5F_auto_i15_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_with_5F_auto_ (GALGAS_bool & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_with_5F_auto_i15_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                     'int_or_float' non terminal implementation                                       
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::nt_int_5F_or_5F_float_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_int_5F_or_5F_float_i16_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_int_5F_or_5F_float_ (GALGAS_object_5F_t & parameter_1,
                                const GALGAS_dataType parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_int_5F_or_5F_float_i16_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                     'set_followup' non terminal implementation                                       
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::nt_set_5F_followup_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_set_5F_followup_i17_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_set_5F_followup_ (GALGAS_numberList & parameter_1,
                                const GALGAS_dataType parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_set_5F_followup_i17_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                    'range_content' non terminal implementation                                       
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::nt_range_5F_content_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_range_5F_content_i18_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_range_5F_content_ (GALGAS_attributeRange & parameter_1,
                                const GALGAS_dataType parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_range_5F_content_i18_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                        'range' non terminal implementation                                           
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::nt_range_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_range_i19_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_range_ (GALGAS_attributeRange & parameter_1,
                                const GALGAS_dataType parameter_2,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_range_i19_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                       'multiple' non terminal implementation                                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::nt_multiple_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_multiple_i20_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_multiple_ (GALGAS_bool & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_multiple_i20_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                               'identifier_or_attribute' non terminal implementation                                  
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::nt_identifier_5F_or_5F_attribute_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_identifier_5F_or_5F_attribute_i21_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_identifier_5F_or_5F_attribute_ (GALGAS_lstring & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_identifier_5F_or_5F_attribute_i21_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                               'identifier_or_enum_value' non terminal implementation                                 
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_goil_5F_grammar::nt_identifier_5F_or_5F_enum_5F_value_parse (C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_identifier_5F_or_5F_enum_5F_value_i22_parse(inLexique) ;
}

void cGrammar_goil_5F_grammar::nt_identifier_5F_or_5F_enum_5F_value_ (GALGAS_lstring & parameter_1,
                                C_Lexique_goil_5F_lexique * inLexique) {
  rule_implementation_5F_parser_identifier_5F_or_5F_enum_5F_value_i22_(parameter_1, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_0' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_goil_5F_syntax_0 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_1' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_goil_5F_syntax_1 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_2' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_goil_5F_syntax_2 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_3' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_goil_5F_syntax_3 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_4' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_goil_5F_syntax_4 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_5' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_goil_5F_syntax_5 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_6' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_goil_5F_syntax_6 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_7' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_goil_5F_syntax_7 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_8' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_goil_5F_syntax_8 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_9' added non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_goil_5F_syntax_9 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_10' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_goil_5F_syntax_10 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_11' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_goil_5F_syntax_11 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_12' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_goil_5F_syntax_12 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_13' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_goil_5F_syntax_13 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_14' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_goil_5F_syntax_14 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_15' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_goil_5F_syntax_15 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_16' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_goil_5F_syntax_16 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_goil_5F_syntax_17' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_goil_5F_syntax_17 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_0' added non terminal implementation                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_0 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_1' added non terminal implementation                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_1 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_2' added non terminal implementation                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_2 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_3' added non terminal implementation                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_3 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_4' added non terminal implementation                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_4 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_5' added non terminal implementation                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_5 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_6' added non terminal implementation                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_6 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_7' added non terminal implementation                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_7 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_8' added non terminal implementation                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_8 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_9' added non terminal implementation                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_9 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_10' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_10 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_11' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_11 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_12' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_12 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_13' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_13 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_14' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_14 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_15' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_15 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_16' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_16 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_17' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_17 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_18' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_18 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_19' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_19 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_20' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_20 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_21' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_21 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_22' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_22 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_23' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_23 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_24' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_24 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_25' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_25 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_26' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_26 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_27' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_27 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_28' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_28 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_29' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_29 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_implementation_5F_parser_30' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_goil_5F_grammar::select_implementation_5F_parser_30 (C_Lexique_goil_5F_lexique * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*

//---------------------------------------------------------------------------------------------------------------------*

#include "utilities/MF_MemoryControl.h"
#include "galgas2/C_galgas_CLI_Options.h"

#include "files/C_FileManager.h"

//---------------------------------------------------------------------------------------------------------------------*


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                   L L ( 1 )    P R O D U C T I O N    R U L E S                                      
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

#define TERMINAL(t)     ((t)+1)
#define NONTERMINAL(nt) ((-nt)-1)
#define END_PRODUCTION  (0)

static const int16_t gProductions_arxml_grammar [] = {
// At index 0 : <arxml_start_symbol>, in file 'arxml_parser.ggs', line 31
  TERMINAL (C_Lexique_arxml_5F_scanner::kToken__3C__3F_) // $<?$
, TERMINAL (C_Lexique_arxml_5F_scanner::kToken_name) // $name$
, NONTERMINAL (3) // <select_arxml_5F_parser_0>
, TERMINAL (C_Lexique_arxml_5F_scanner::kToken__3F__3E_) // $?>$
, NONTERMINAL (1) // <element_list>
, END_PRODUCTION
// At index 6 : <element_list>, in file 'arxml_parser.ggs', line 185
, NONTERMINAL (4) // <select_arxml_5F_parser_1>
, END_PRODUCTION
// At index 8 : <element>, in file 'arxml_parser.ggs', line 205
, TERMINAL (C_Lexique_arxml_5F_scanner::kToken_comment) // $comment$
, END_PRODUCTION
// At index 10 : <element>, in file 'arxml_parser.ggs', line 218
, TERMINAL (C_Lexique_arxml_5F_scanner::kToken__3C_) // $<$
, TERMINAL (C_Lexique_arxml_5F_scanner::kToken_name) // $name$
, NONTERMINAL (5) // <select_arxml_5F_parser_2>
, NONTERMINAL (6) // <select_arxml_5F_parser_3>
, END_PRODUCTION
//---- Added productions from 'select' and 'repeat' instructions
// At index 15 : <select_arxml_5F_parser_0>, in file 'arxml_parser.ggs', line 53
, END_PRODUCTION
// At index 16 : <select_arxml_5F_parser_0>, in file 'arxml_parser.ggs', line 53
, TERMINAL (C_Lexique_arxml_5F_scanner::kToken_name) // $name$
, TERMINAL (C_Lexique_arxml_5F_scanner::kToken__3D_) // $=$
, TERMINAL (C_Lexique_arxml_5F_scanner::kToken_value) // $value$
, NONTERMINAL (3) // <select_arxml_5F_parser_0>
, END_PRODUCTION
// At index 21 : <select_arxml_5F_parser_1>, in file 'arxml_parser.ggs', line 190
, END_PRODUCTION
// At index 22 : <select_arxml_5F_parser_1>, in file 'arxml_parser.ggs', line 190
, NONTERMINAL (2) // <element>
, NONTERMINAL (4) // <select_arxml_5F_parser_1>
, END_PRODUCTION
// At index 25 : <select_arxml_5F_parser_2>, in file 'arxml_parser.ggs', line 226
, END_PRODUCTION
// At index 26 : <select_arxml_5F_parser_2>, in file 'arxml_parser.ggs', line 226
, TERMINAL (C_Lexique_arxml_5F_scanner::kToken_name) // $name$
, TERMINAL (C_Lexique_arxml_5F_scanner::kToken__3D_) // $=$
, TERMINAL (C_Lexique_arxml_5F_scanner::kToken_value) // $value$
, NONTERMINAL (5) // <select_arxml_5F_parser_2>
, END_PRODUCTION
// At index 31 : <select_arxml_5F_parser_3>, in file 'arxml_parser.ggs', line 235
, TERMINAL (C_Lexique_arxml_5F_scanner::kToken__2F__3E_) // $/>$
, END_PRODUCTION
// At index 33 : <select_arxml_5F_parser_3>, in file 'arxml_parser.ggs', line 235
, TERMINAL (C_Lexique_arxml_5F_scanner::kToken__3E_) // $>$
, NONTERMINAL (1) // <element_list>
, TERMINAL (C_Lexique_arxml_5F_scanner::kToken__3C__2F_) // $</$
, TERMINAL (C_Lexique_arxml_5F_scanner::kToken_name) // $name$
, TERMINAL (C_Lexique_arxml_5F_scanner::kToken__3E_) // $>$
, END_PRODUCTION
// At index 39 : <>, in file '.ggs', line 0
, NONTERMINAL (0) // <arxml_start_symbol>
, END_PRODUCTION
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                          P R O D U C T I O N    N A M E S                                            
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const cProductionNameDescriptor gProductionNames_arxml_grammar [13] = {
 {"<arxml_start_symbol>", "arxml_parser", 0}, // at index 0
 {"<element_list>", "arxml_parser", 6}, // at index 1
 {"<element>", "arxml_parser", 8}, // at index 2
 {"<element>", "arxml_parser", 10}, // at index 3
 {"<select_arxml_5F_parser_0>", "arxml_parser", 15}, // at index 4
 {"<select_arxml_5F_parser_0>", "arxml_parser", 16}, // at index 5
 {"<select_arxml_5F_parser_1>", "arxml_parser", 21}, // at index 6
 {"<select_arxml_5F_parser_1>", "arxml_parser", 22}, // at index 7
 {"<select_arxml_5F_parser_2>", "arxml_parser", 25}, // at index 8
 {"<select_arxml_5F_parser_2>", "arxml_parser", 26}, // at index 9
 {"<select_arxml_5F_parser_3>", "arxml_parser", 31}, // at index 10
 {"<select_arxml_5F_parser_3>", "arxml_parser", 33}, // at index 11
 {"<>", "", 39} // at index 12
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                 L L ( 1 )    P R O D U C T I O N    I N D E X E S                                    
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gProductionIndexes_arxml_grammar [13] = {
0, // index 0 : <arxml_start_symbol>, in file 'arxml_parser.ggs', line 31
6, // index 1 : <element_list>, in file 'arxml_parser.ggs', line 185
8, // index 2 : <element>, in file 'arxml_parser.ggs', line 205
10, // index 3 : <element>, in file 'arxml_parser.ggs', line 218
15, // index 4 : <select_arxml_5F_parser_0>, in file 'arxml_parser.ggs', line 53
16, // index 5 : <select_arxml_5F_parser_0>, in file 'arxml_parser.ggs', line 53
21, // index 6 : <select_arxml_5F_parser_1>, in file 'arxml_parser.ggs', line 190
22, // index 7 : <select_arxml_5F_parser_1>, in file 'arxml_parser.ggs', line 190
25, // index 8 : <select_arxml_5F_parser_2>, in file 'arxml_parser.ggs', line 226
26, // index 9 : <select_arxml_5F_parser_2>, in file 'arxml_parser.ggs', line 226
31, // index 10 : <select_arxml_5F_parser_3>, in file 'arxml_parser.ggs', line 235
33, // index 11 : <select_arxml_5F_parser_3>, in file 'arxml_parser.ggs', line 235
39 // index 12 : <>, in file '.ggs', line 0
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                           L L ( 1 )    F I R S T    P R O D U C T I O N    I N D E X E S                             
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gFirstProductionIndexes_arxml_grammar [9] = {
0, // at 0 : <arxml_start_symbol>
1, // at 1 : <element_list>
2, // at 2 : <element>
4, // at 3 : <select_arxml_5F_parser_0>
6, // at 4 : <select_arxml_5F_parser_1>
8, // at 5 : <select_arxml_5F_parser_2>
10, // at 6 : <select_arxml_5F_parser_3>
12, // at 7 : <>
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                    L L ( 1 )    D E C I S I O N    T A B L E S                                       
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gDecision_arxml_grammar [] = {
// At index 0 : <arxml_start_symbol> only one production, no choice
  -1,
// At index 1 : <element_list> only one production, no choice
  -1,
// At index 2 : <element>
C_Lexique_arxml_5F_scanner::kToken_comment, -1, // Choice 1
C_Lexique_arxml_5F_scanner::kToken__3C_, -1, // Choice 2
  -1,
//---- Added non terminal symbols from 'select' and 'repeat' instructions
// At index 7 : <select_arxml_5F_parser_0>
C_Lexique_arxml_5F_scanner::kToken__3F__3E_, -1, // Choice 1
C_Lexique_arxml_5F_scanner::kToken_name, -1, // Choice 2
  -1,
// At index 12 : <select_arxml_5F_parser_1>
C_Lexique_arxml_5F_scanner::kToken__3C__2F_, C_Lexique_arxml_5F_scanner::kToken_, -1, // Choice 1
C_Lexique_arxml_5F_scanner::kToken_comment, C_Lexique_arxml_5F_scanner::kToken__3C_, -1, // Choice 2
  -1,
// At index 19 : <select_arxml_5F_parser_2>
C_Lexique_arxml_5F_scanner::kToken__2F__3E_, C_Lexique_arxml_5F_scanner::kToken__3E_, -1, // Choice 1
C_Lexique_arxml_5F_scanner::kToken_name, -1, // Choice 2
  -1,
// At index 25 : <select_arxml_5F_parser_3>
C_Lexique_arxml_5F_scanner::kToken__2F__3E_, -1, // Choice 1
C_Lexique_arxml_5F_scanner::kToken__3E_, -1, // Choice 2
  -1,
// At index 30 : <> only one production, no choice
  -1,
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            L L ( 1 )    D E C I S I O N    T A B L E S    I N D E X E S                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gDecisionIndexes_arxml_grammar [9] = {
0, // at 0 : <arxml_start_symbol>
1, // at 1 : <element_list>
2, // at 2 : <element>
7, // at 3 : <select_arxml_5F_parser_0>
12, // at 4 : <select_arxml_5F_parser_1>
19, // at 5 : <select_arxml_5F_parser_2>
25, // at 6 : <select_arxml_5F_parser_3>
30, // at 7 : <>
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                  'arxml_start_symbol' non terminal implementation                                    
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_arxml_5F_grammar::nt_arxml_5F_start_5F_symbol_parse (C_Lexique_arxml_5F_scanner * inLexique) {
  rule_arxml_5F_parser_arxml_5F_start_5F_symbol_i0_parse(inLexique) ;
}

void cGrammar_arxml_5F_grammar::nt_arxml_5F_start_5F_symbol_ (GALGAS_arxmlNode & parameter_1,
                                const GALGAS_bool parameter_2,
                                const GALGAS_bool parameter_3,
                                C_Lexique_arxml_5F_scanner * inLexique) {
  rule_arxml_5F_parser_arxml_5F_start_5F_symbol_i0_(parameter_1, parameter_2, parameter_3, inLexique) ;
}

void cGrammar_arxml_5F_grammar::performIndexing (C_Compiler * /* inCompiler */,
             const C_String & /* inSourceFilePath */) {
}

void cGrammar_arxml_5F_grammar::performOnlyLexicalAnalysis (C_Compiler * inCompiler,
             const C_String & inSourceFilePath) {
  C_Lexique_arxml_5F_scanner * scanner = NULL ;
  macroMyNew (scanner, C_Lexique_arxml_5F_scanner (inCompiler, inSourceFilePath COMMA_HERE)) ;
  if (scanner->sourceText ().isValid ()) {
    scanner->performLexicalAnalysis () ;
  }
  macroDetachSharedObject (scanner) ;
}

void cGrammar_arxml_5F_grammar::performOnlySyntaxAnalysis (C_Compiler * inCompiler,
             const C_String & inSourceFilePath) {
  C_Lexique_arxml_5F_scanner * scanner = NULL ;
  macroMyNew (scanner, C_Lexique_arxml_5F_scanner (inCompiler, inSourceFilePath COMMA_HERE)) ;
  if (scanner->sourceText ().isValid ()) {
    scanner->performTopDownParsing (gProductions_arxml_grammar, gProductionNames_arxml_grammar, gProductionIndexes_arxml_grammar,
                                    gFirstProductionIndexes_arxml_grammar, gDecision_arxml_grammar, gDecisionIndexes_arxml_grammar, 39) ;
  }
  macroDetachSharedObject (scanner) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                        Grammar start symbol implementation                                           
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_arxml_5F_grammar::_performSourceFileParsing_ (C_Compiler * inCompiler,
                                GALGAS_lstring inFilePath,
                                GALGAS_arxmlNode &  parameter_1,
                                const GALGAS_bool  parameter_2,
                                const GALGAS_bool  parameter_3
                                COMMA_LOCATION_ARGS) {
  if (inFilePath.isValid ()) {
    const GALGAS_string filePathAsString = inFilePath.getter_string (HERE) ;
    C_String filePath = filePathAsString.stringValue () ;
    if (! C_FileManager::isAbsolutePath (filePath)) {
      filePath = inCompiler->sourceFilePath ().stringByDeletingLastPathComponent ().stringByAppendingPathComponent (filePath) ;
    }
    if (C_FileManager::fileExistsAtPath (filePath)) {
    C_Lexique_arxml_5F_scanner * scanner = NULL ;
    macroMyNew (scanner, C_Lexique_arxml_5F_scanner (inCompiler, filePath COMMA_HERE)) ;
    if (scanner->sourceText ().isValid ()) {
      const bool ok = scanner->performTopDownParsing (gProductions_arxml_grammar, gProductionNames_arxml_grammar, gProductionIndexes_arxml_grammar,
                                                      gFirstProductionIndexes_arxml_grammar, gDecision_arxml_grammar, gDecisionIndexes_arxml_grammar, 39) ;
      if (ok && ! executionModeIsSyntaxAnalysisOnly ()) {
        cGrammar_arxml_5F_grammar grammar ;
        grammar.nt_arxml_5F_start_5F_symbol_ (parameter_1, parameter_2, parameter_3, scanner) ;
        }
      }else{
        C_String message ;
        message << "the '" << filePath << "' file exists, but cannot be read" ;
        const GALGAS_location errorLocation (inFilePath.getter_location (THERE)) ;
        inCompiler->semanticErrorAtLocation (errorLocation, message, TC_Array <C_FixItDescription> () COMMA_THERE) ;
      }
      macroDetachSharedObject (scanner) ;
    }else{
      C_String message ;
      message << "the '" << filePath << "' file does not exist" ;
      const GALGAS_location errorLocation (inFilePath.getter_location (THERE)) ;
      inCompiler->semanticErrorAtLocation (errorLocation, message, TC_Array <C_FixItDescription> () COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_arxml_5F_grammar::_performSourceStringParsing_ (C_Compiler * inCompiler,
                                GALGAS_string inSourceString,
                                GALGAS_string inNameString,
                                GALGAS_arxmlNode &  parameter_1,
                                const GALGAS_bool  parameter_2,
                                const GALGAS_bool  parameter_3
                                COMMA_UNUSED_LOCATION_ARGS) {
  if (inSourceString.isValid () && inNameString.isValid ()) {
    const C_String sourceString = inSourceString.stringValue () ;
    const C_String nameString = inNameString.stringValue () ;
    C_Lexique_arxml_5F_scanner * scanner = NULL ;
    macroMyNew (scanner, C_Lexique_arxml_5F_scanner (inCompiler, sourceString, nameString COMMA_HERE)) ;
    const bool ok = scanner->performTopDownParsing (gProductions_arxml_grammar, gProductionNames_arxml_grammar, gProductionIndexes_arxml_grammar,
                                                    gFirstProductionIndexes_arxml_grammar, gDecision_arxml_grammar, gDecisionIndexes_arxml_grammar, 39) ;
    if (ok && ! executionModeIsSyntaxAnalysisOnly ()) {
      cGrammar_arxml_5F_grammar grammar ;
      grammar.nt_arxml_5F_start_5F_symbol_ (parameter_1, parameter_2, parameter_3, scanner) ;
    }
    macroDetachSharedObject (scanner) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                     'element_list' non terminal implementation                                       
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_arxml_5F_grammar::nt_element_5F_list_parse (C_Lexique_arxml_5F_scanner * inLexique) {
  rule_arxml_5F_parser_element_5F_list_i1_parse(inLexique) ;
}

void cGrammar_arxml_5F_grammar::nt_element_5F_list_ (GALGAS_arxmlNodeList & parameter_1,
                                const GALGAS_bool parameter_2,
                                const GALGAS_bool parameter_3,
                                C_Lexique_arxml_5F_scanner * inLexique) {
  rule_arxml_5F_parser_element_5F_list_i1_(parameter_1, parameter_2, parameter_3, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                       'element' non terminal implementation                                          
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_arxml_5F_grammar::nt_element_parse (C_Lexique_arxml_5F_scanner * inLexique) {
  switch (inLexique->nextProductionIndex ()) {
  case 1 :
    rule_arxml_5F_parser_element_i2_parse(inLexique) ;
    break ;
  case 2 :
    rule_arxml_5F_parser_element_i3_parse(inLexique) ;
    break ;
  default :
    break ;
  }
}

void cGrammar_arxml_5F_grammar::nt_element_ (GALGAS_arxmlNodeList & parameter_1,
                                const GALGAS_bool parameter_2,
                                const GALGAS_bool parameter_3,
                                C_Lexique_arxml_5F_scanner * inLexique) {
  switch (inLexique->nextProductionIndex ()) {
  case 1 :
    rule_arxml_5F_parser_element_i2_(parameter_1, parameter_2, parameter_3, inLexique) ;
    break ;
  case 2 :
    rule_arxml_5F_parser_element_i3_(parameter_1, parameter_2, parameter_3, inLexique) ;
    break ;
  default :
    break ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_arxml_5F_parser_0' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_arxml_5F_grammar::select_arxml_5F_parser_0 (C_Lexique_arxml_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_arxml_5F_parser_1' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_arxml_5F_grammar::select_arxml_5F_parser_1 (C_Lexique_arxml_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_arxml_5F_parser_2' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_arxml_5F_grammar::select_arxml_5F_parser_2 (C_Lexique_arxml_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            'select_arxml_5F_parser_3' added non terminal implementation                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_arxml_5F_grammar::select_arxml_5F_parser_3 (C_Lexique_arxml_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*

//---------------------------------------------------------------------------------------------------------------------*

#include "utilities/MF_MemoryControl.h"
#include "galgas2/C_galgas_CLI_Options.h"

#include "files/C_FileManager.h"

//---------------------------------------------------------------------------------------------------------------------*


//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                   L L ( 1 )    P R O D U C T I O N    R U L E S                                      
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

#define TERMINAL(t)     ((t)+1)
#define NONTERMINAL(nt) ((-nt)-1)
#define END_PRODUCTION  (0)

static const int16_t gProductions_arxmlmetaparser_grammar [] = {
// At index 0 : <arxmlmetaparser_start_symbol>, in file 'arxmlmetaparser_syntax.ggs', line 31
  NONTERMINAL (1) // <xml_header>
, NONTERMINAL (15) // <xsd_schema>
, END_PRODUCTION
// At index 3 : <xml_header>, in file 'arxmlmetaparser_syntax.ggs', line 61
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__3F_xml) // $<?xml$
, NONTERMINAL (22) // <xsd_ignore_attributes>
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3F__3E_) // $?>$
, END_PRODUCTION
// At index 7 : <xsd_annotation>, in file 'arxmlmetaparser_syntax.ggs', line 75
, NONTERMINAL (22) // <xsd_ignore_attributes>
, NONTERMINAL (23) // <select_arxmlmetaparser_5F_syntax_0>
, END_PRODUCTION
// At index 10 : <xsd_appinfo>, in file 'arxmlmetaparser_syntax.ggs', line 101
, NONTERMINAL (22) // <xsd_ignore_attributes>
, NONTERMINAL (26) // <select_arxmlmetaparser_5F_syntax_3>
, END_PRODUCTION
// At index 13 : <xsd_attribute>, in file 'arxmlmetaparser_syntax.ggs', line 118
, NONTERMINAL (27) // <select_arxmlmetaparser_5F_syntax_4>
, NONTERMINAL (28) // <select_arxmlmetaparser_5F_syntax_5>
, END_PRODUCTION
// At index 16 : <xsd_attributeGroup>, in file 'arxmlmetaparser_syntax.ggs', line 191
, NONTERMINAL (31) // <select_arxmlmetaparser_5F_syntax_8>
, NONTERMINAL (32) // <select_arxmlmetaparser_5F_syntax_9>
, END_PRODUCTION
// At index 19 : <xsd_choice>, in file 'arxmlmetaparser_syntax.ggs', line 265
, NONTERMINAL (22) // <xsd_ignore_attributes>
, NONTERMINAL (35) // <select_arxmlmetaparser_5F_syntax_12>
, END_PRODUCTION
// At index 22 : <xsd_complexType>, in file 'arxmlmetaparser_syntax.ggs', line 297
, NONTERMINAL (38) // <select_arxmlmetaparser_5F_syntax_15>
, NONTERMINAL (39) // <select_arxmlmetaparser_5F_syntax_16>
, END_PRODUCTION
// At index 25 : <xsd_documentation>, in file 'arxmlmetaparser_syntax.ggs', line 369
, NONTERMINAL (22) // <xsd_ignore_attributes>
, NONTERMINAL (42) // <select_arxmlmetaparser_5F_syntax_19>
, END_PRODUCTION
// At index 28 : <xsd_element>, in file 'arxmlmetaparser_syntax.ggs', line 388
, NONTERMINAL (43) // <select_arxmlmetaparser_5F_syntax_20>
, NONTERMINAL (44) // <select_arxmlmetaparser_5F_syntax_21>
, END_PRODUCTION
// At index 31 : <xsd_enumeration>, in file 'arxmlmetaparser_syntax.ggs', line 495
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_value) // $value$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) // $=$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) // $xmlTagValue$
, NONTERMINAL (47) // <select_arxmlmetaparser_5F_syntax_24>
, END_PRODUCTION
// At index 36 : <xsd_extension>, in file 'arxmlmetaparser_syntax.ggs', line 523
, NONTERMINAL (22) // <xsd_ignore_attributes>
, NONTERMINAL (49) // <select_arxmlmetaparser_5F_syntax_26>
, END_PRODUCTION
// At index 39 : <xsd_group>, in file 'arxmlmetaparser_syntax.ggs', line 558
, NONTERMINAL (52) // <select_arxmlmetaparser_5F_syntax_29>
, NONTERMINAL (53) // <select_arxmlmetaparser_5F_syntax_30>
, END_PRODUCTION
// At index 42 : <xsd_import>, in file 'arxmlmetaparser_syntax.ggs', line 630
, NONTERMINAL (22) // <xsd_ignore_attributes>
, NONTERMINAL (56) // <select_arxmlmetaparser_5F_syntax_33>
, END_PRODUCTION
// At index 45 : <xsd_restriction>, in file 'arxmlmetaparser_syntax.ggs', line 653
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_base) // $base$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) // $=$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) // $xmlTagValue$
, NONTERMINAL (58) // <select_arxmlmetaparser_5F_syntax_35>
, END_PRODUCTION
// At index 50 : <xsd_schema>, in file 'arxmlmetaparser_syntax.ggs', line 753
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_) // $<xsd:$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_schema) // $schema$
, NONTERMINAL (22) // <xsd_ignore_attributes>
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) // $>$
, NONTERMINAL (61) // <select_arxmlmetaparser_5F_syntax_38>
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_) // $</xsd:$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_schema) // $schema$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) // $>$
, END_PRODUCTION
// At index 59 : <xsd_sequence>, in file 'arxmlmetaparser_syntax.ggs', line 810
, NONTERMINAL (63) // <select_arxmlmetaparser_5F_syntax_40>
, END_PRODUCTION
// At index 61 : <xsd_simpleContent>, in file 'arxmlmetaparser_syntax.ggs', line 841
, NONTERMINAL (66) // <select_arxmlmetaparser_5F_syntax_43>
, END_PRODUCTION
// At index 63 : <xsd_simpleType>, in file 'arxmlmetaparser_syntax.ggs', line 876
, NONTERMINAL (69) // <select_arxmlmetaparser_5F_syntax_46>
, NONTERMINAL (70) // <select_arxmlmetaparser_5F_syntax_47>
, END_PRODUCTION
// At index 66 : <xsd_maxLength>, in file 'arxmlmetaparser_syntax.ggs', line 942
, NONTERMINAL (22) // <xsd_ignore_attributes>
, NONTERMINAL (73) // <select_arxmlmetaparser_5F_syntax_50>
, END_PRODUCTION
// At index 69 : <xsd_pattern>, in file 'arxmlmetaparser_syntax.ggs', line 967
, NONTERMINAL (22) // <xsd_ignore_attributes>
, NONTERMINAL (75) // <select_arxmlmetaparser_5F_syntax_52>
, END_PRODUCTION
// At index 72 : <xsd_whiteSpace>, in file 'arxmlmetaparser_syntax.ggs', line 991
, NONTERMINAL (22) // <xsd_ignore_attributes>
, NONTERMINAL (77) // <select_arxmlmetaparser_5F_syntax_54>
, END_PRODUCTION
// At index 75 : <xsd_ignore_attributes>, in file 'arxmlmetaparser_syntax.ggs', line 1011
, NONTERMINAL (79) // <select_arxmlmetaparser_5F_syntax_56>
, END_PRODUCTION
//---- Added productions from 'select' and 'repeat' instructions
// At index 77 : <select_arxmlmetaparser_5F_syntax_0>, in file 'arxmlmetaparser_syntax.ggs', line 81
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) // $>$
, NONTERMINAL (24) // <select_arxmlmetaparser_5F_syntax_1>
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_) // $</xsd:$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation) // $annotation$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) // $>$
, END_PRODUCTION
// At index 83 : <select_arxmlmetaparser_5F_syntax_0>, in file 'arxmlmetaparser_syntax.ggs', line 81
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_) // $/>$
, END_PRODUCTION
// At index 85 : <select_arxmlmetaparser_5F_syntax_1>, in file 'arxmlmetaparser_syntax.ggs', line 82
, END_PRODUCTION
// At index 86 : <select_arxmlmetaparser_5F_syntax_1>, in file 'arxmlmetaparser_syntax.ggs', line 82
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_) // $<xsd:$
, NONTERMINAL (25) // <select_arxmlmetaparser_5F_syntax_2>
, NONTERMINAL (24) // <select_arxmlmetaparser_5F_syntax_1>
, END_PRODUCTION
// At index 90 : <select_arxmlmetaparser_5F_syntax_2>, in file 'arxmlmetaparser_syntax.ggs', line 84
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_appinfo) // $appinfo$
, NONTERMINAL (3) // <xsd_appinfo>
, END_PRODUCTION
// At index 93 : <select_arxmlmetaparser_5F_syntax_2>, in file 'arxmlmetaparser_syntax.ggs', line 84
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_documentation) // $documentation$
, NONTERMINAL (8) // <xsd_documentation>
, END_PRODUCTION
// At index 96 : <select_arxmlmetaparser_5F_syntax_3>, in file 'arxmlmetaparser_syntax.ggs', line 107
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) // $>$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_) // $</xsd:$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_appinfo) // $appinfo$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) // $>$
, END_PRODUCTION
// At index 101 : <select_arxmlmetaparser_5F_syntax_3>, in file 'arxmlmetaparser_syntax.ggs', line 107
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_) // $/>$
, END_PRODUCTION
// At index 103 : <select_arxmlmetaparser_5F_syntax_4>, in file 'arxmlmetaparser_syntax.ggs', line 129
, END_PRODUCTION
// At index 104 : <select_arxmlmetaparser_5F_syntax_4>, in file 'arxmlmetaparser_syntax.ggs', line 129
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_ref) // $ref$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) // $=$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) // $xmlTagValue$
, NONTERMINAL (27) // <select_arxmlmetaparser_5F_syntax_4>
, END_PRODUCTION
// At index 109 : <select_arxmlmetaparser_5F_syntax_4>, in file 'arxmlmetaparser_syntax.ggs', line 129
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_type) // $type$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) // $=$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) // $xmlTagValue$
, NONTERMINAL (27) // <select_arxmlmetaparser_5F_syntax_4>
, END_PRODUCTION
// At index 114 : <select_arxmlmetaparser_5F_syntax_4>, in file 'arxmlmetaparser_syntax.ggs', line 129
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_name) // $name$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) // $=$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) // $xmlTagValue$
, NONTERMINAL (27) // <select_arxmlmetaparser_5F_syntax_4>
, END_PRODUCTION
// At index 119 : <select_arxmlmetaparser_5F_syntax_4>, in file 'arxmlmetaparser_syntax.ggs', line 129
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_use) // $use$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) // $=$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) // $xmlTagValue$
, NONTERMINAL (27) // <select_arxmlmetaparser_5F_syntax_4>
, END_PRODUCTION
// At index 124 : <select_arxmlmetaparser_5F_syntax_5>, in file 'arxmlmetaparser_syntax.ggs', line 171
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) // $>$
, NONTERMINAL (29) // <select_arxmlmetaparser_5F_syntax_6>
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_) // $</xsd:$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attribute) // $attribute$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) // $>$
, END_PRODUCTION
// At index 130 : <select_arxmlmetaparser_5F_syntax_5>, in file 'arxmlmetaparser_syntax.ggs', line 171
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_) // $/>$
, END_PRODUCTION
// At index 132 : <select_arxmlmetaparser_5F_syntax_6>, in file 'arxmlmetaparser_syntax.ggs', line 172
, END_PRODUCTION
// At index 133 : <select_arxmlmetaparser_5F_syntax_6>, in file 'arxmlmetaparser_syntax.ggs', line 172
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_) // $<xsd:$
, NONTERMINAL (30) // <select_arxmlmetaparser_5F_syntax_7>
, NONTERMINAL (29) // <select_arxmlmetaparser_5F_syntax_6>
, END_PRODUCTION
// At index 137 : <select_arxmlmetaparser_5F_syntax_7>, in file 'arxmlmetaparser_syntax.ggs', line 174
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation) // $annotation$
, NONTERMINAL (2) // <xsd_annotation>
, END_PRODUCTION
// At index 140 : <select_arxmlmetaparser_5F_syntax_7>, in file 'arxmlmetaparser_syntax.ggs', line 174
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_simpleType) // $simpleType$
, NONTERMINAL (18) // <xsd_simpleType>
, END_PRODUCTION
// At index 143 : <select_arxmlmetaparser_5F_syntax_8>, in file 'arxmlmetaparser_syntax.ggs', line 199
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_name) // $name$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) // $=$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) // $xmlTagValue$
, END_PRODUCTION
// At index 147 : <select_arxmlmetaparser_5F_syntax_8>, in file 'arxmlmetaparser_syntax.ggs', line 199
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_ref) // $ref$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) // $=$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) // $xmlTagValue$
, END_PRODUCTION
// At index 151 : <select_arxmlmetaparser_5F_syntax_9>, in file 'arxmlmetaparser_syntax.ggs', line 239
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) // $>$
, NONTERMINAL (33) // <select_arxmlmetaparser_5F_syntax_10>
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_) // $</xsd:$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attributeGroup) // $attributeGroup$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) // $>$
, END_PRODUCTION
// At index 157 : <select_arxmlmetaparser_5F_syntax_9>, in file 'arxmlmetaparser_syntax.ggs', line 239
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_) // $/>$
, END_PRODUCTION
// At index 159 : <select_arxmlmetaparser_5F_syntax_10>, in file 'arxmlmetaparser_syntax.ggs', line 240
, END_PRODUCTION
// At index 160 : <select_arxmlmetaparser_5F_syntax_10>, in file 'arxmlmetaparser_syntax.ggs', line 240
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_) // $<xsd:$
, NONTERMINAL (34) // <select_arxmlmetaparser_5F_syntax_11>
, NONTERMINAL (33) // <select_arxmlmetaparser_5F_syntax_10>
, END_PRODUCTION
// At index 164 : <select_arxmlmetaparser_5F_syntax_11>, in file 'arxmlmetaparser_syntax.ggs', line 242
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation) // $annotation$
, NONTERMINAL (2) // <xsd_annotation>
, END_PRODUCTION
// At index 167 : <select_arxmlmetaparser_5F_syntax_11>, in file 'arxmlmetaparser_syntax.ggs', line 242
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attribute) // $attribute$
, NONTERMINAL (4) // <xsd_attribute>
, END_PRODUCTION
// At index 170 : <select_arxmlmetaparser_5F_syntax_11>, in file 'arxmlmetaparser_syntax.ggs', line 242
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attributeGroup) // $attributeGroup$
, NONTERMINAL (5) // <xsd_attributeGroup>
, END_PRODUCTION
// At index 173 : <select_arxmlmetaparser_5F_syntax_11>, in file 'arxmlmetaparser_syntax.ggs', line 242
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_choice) // $choice$
, NONTERMINAL (6) // <xsd_choice>
, END_PRODUCTION
// At index 176 : <select_arxmlmetaparser_5F_syntax_11>, in file 'arxmlmetaparser_syntax.ggs', line 242
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_sequence) // $sequence$
, NONTERMINAL (16) // <xsd_sequence>
, END_PRODUCTION
// At index 179 : <select_arxmlmetaparser_5F_syntax_12>, in file 'arxmlmetaparser_syntax.ggs', line 271
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) // $>$
, NONTERMINAL (36) // <select_arxmlmetaparser_5F_syntax_13>
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_) // $</xsd:$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_choice) // $choice$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) // $>$
, END_PRODUCTION
// At index 185 : <select_arxmlmetaparser_5F_syntax_12>, in file 'arxmlmetaparser_syntax.ggs', line 271
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_) // $/>$
, END_PRODUCTION
// At index 187 : <select_arxmlmetaparser_5F_syntax_13>, in file 'arxmlmetaparser_syntax.ggs', line 272
, END_PRODUCTION
// At index 188 : <select_arxmlmetaparser_5F_syntax_13>, in file 'arxmlmetaparser_syntax.ggs', line 272
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_) // $<xsd:$
, NONTERMINAL (37) // <select_arxmlmetaparser_5F_syntax_14>
, NONTERMINAL (36) // <select_arxmlmetaparser_5F_syntax_13>
, END_PRODUCTION
// At index 192 : <select_arxmlmetaparser_5F_syntax_14>, in file 'arxmlmetaparser_syntax.ggs', line 274
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation) // $annotation$
, NONTERMINAL (2) // <xsd_annotation>
, END_PRODUCTION
// At index 195 : <select_arxmlmetaparser_5F_syntax_14>, in file 'arxmlmetaparser_syntax.ggs', line 274
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_choice) // $choice$
, NONTERMINAL (6) // <xsd_choice>
, END_PRODUCTION
// At index 198 : <select_arxmlmetaparser_5F_syntax_14>, in file 'arxmlmetaparser_syntax.ggs', line 274
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_sequence) // $sequence$
, NONTERMINAL (16) // <xsd_sequence>
, END_PRODUCTION
// At index 201 : <select_arxmlmetaparser_5F_syntax_14>, in file 'arxmlmetaparser_syntax.ggs', line 274
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_element) // $element$
, NONTERMINAL (9) // <xsd_element>
, END_PRODUCTION
// At index 204 : <select_arxmlmetaparser_5F_syntax_14>, in file 'arxmlmetaparser_syntax.ggs', line 274
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_group) // $group$
, NONTERMINAL (12) // <xsd_group>
, END_PRODUCTION
// At index 207 : <select_arxmlmetaparser_5F_syntax_15>, in file 'arxmlmetaparser_syntax.ggs', line 306
, END_PRODUCTION
// At index 208 : <select_arxmlmetaparser_5F_syntax_15>, in file 'arxmlmetaparser_syntax.ggs', line 306
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_abstract) // $abstract$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) // $=$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) // $xmlTagValue$
, NONTERMINAL (38) // <select_arxmlmetaparser_5F_syntax_15>
, END_PRODUCTION
// At index 213 : <select_arxmlmetaparser_5F_syntax_15>, in file 'arxmlmetaparser_syntax.ggs', line 306
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_mixed) // $mixed$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) // $=$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) // $xmlTagValue$
, NONTERMINAL (38) // <select_arxmlmetaparser_5F_syntax_15>
, END_PRODUCTION
// At index 218 : <select_arxmlmetaparser_5F_syntax_15>, in file 'arxmlmetaparser_syntax.ggs', line 306
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_name) // $name$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) // $=$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) // $xmlTagValue$
, NONTERMINAL (38) // <select_arxmlmetaparser_5F_syntax_15>
, END_PRODUCTION
// At index 223 : <select_arxmlmetaparser_5F_syntax_16>, in file 'arxmlmetaparser_syntax.ggs', line 339
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) // $>$
, NONTERMINAL (40) // <select_arxmlmetaparser_5F_syntax_17>
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_) // $</xsd:$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_complexType) // $complexType$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) // $>$
, END_PRODUCTION
// At index 229 : <select_arxmlmetaparser_5F_syntax_16>, in file 'arxmlmetaparser_syntax.ggs', line 339
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_) // $/>$
, END_PRODUCTION
// At index 231 : <select_arxmlmetaparser_5F_syntax_17>, in file 'arxmlmetaparser_syntax.ggs', line 340
, END_PRODUCTION
// At index 232 : <select_arxmlmetaparser_5F_syntax_17>, in file 'arxmlmetaparser_syntax.ggs', line 340
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_) // $<xsd:$
, NONTERMINAL (41) // <select_arxmlmetaparser_5F_syntax_18>
, NONTERMINAL (40) // <select_arxmlmetaparser_5F_syntax_17>
, END_PRODUCTION
// At index 236 : <select_arxmlmetaparser_5F_syntax_18>, in file 'arxmlmetaparser_syntax.ggs', line 342
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation) // $annotation$
, NONTERMINAL (2) // <xsd_annotation>
, END_PRODUCTION
// At index 239 : <select_arxmlmetaparser_5F_syntax_18>, in file 'arxmlmetaparser_syntax.ggs', line 342
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attribute) // $attribute$
, NONTERMINAL (4) // <xsd_attribute>
, END_PRODUCTION
// At index 242 : <select_arxmlmetaparser_5F_syntax_18>, in file 'arxmlmetaparser_syntax.ggs', line 342
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attributeGroup) // $attributeGroup$
, NONTERMINAL (5) // <xsd_attributeGroup>
, END_PRODUCTION
// At index 245 : <select_arxmlmetaparser_5F_syntax_18>, in file 'arxmlmetaparser_syntax.ggs', line 342
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_choice) // $choice$
, NONTERMINAL (6) // <xsd_choice>
, END_PRODUCTION
// At index 248 : <select_arxmlmetaparser_5F_syntax_18>, in file 'arxmlmetaparser_syntax.ggs', line 342
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_sequence) // $sequence$
, NONTERMINAL (16) // <xsd_sequence>
, END_PRODUCTION
// At index 251 : <select_arxmlmetaparser_5F_syntax_18>, in file 'arxmlmetaparser_syntax.ggs', line 342
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_group) // $group$
, NONTERMINAL (12) // <xsd_group>
, END_PRODUCTION
// At index 254 : <select_arxmlmetaparser_5F_syntax_18>, in file 'arxmlmetaparser_syntax.ggs', line 342
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_simpleContent) // $simpleContent$
, NONTERMINAL (17) // <xsd_simpleContent>
, END_PRODUCTION
// At index 257 : <select_arxmlmetaparser_5F_syntax_19>, in file 'arxmlmetaparser_syntax.ggs', line 375
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) // $>$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_) // $</xsd:$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_documentation) // $documentation$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) // $>$
, END_PRODUCTION
// At index 262 : <select_arxmlmetaparser_5F_syntax_19>, in file 'arxmlmetaparser_syntax.ggs', line 375
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_) // $/>$
, END_PRODUCTION
// At index 264 : <select_arxmlmetaparser_5F_syntax_20>, in file 'arxmlmetaparser_syntax.ggs', line 400
, END_PRODUCTION
// At index 265 : <select_arxmlmetaparser_5F_syntax_20>, in file 'arxmlmetaparser_syntax.ggs', line 400
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_maxOccurs) // $maxOccurs$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) // $=$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) // $xmlTagValue$
, NONTERMINAL (43) // <select_arxmlmetaparser_5F_syntax_20>
, END_PRODUCTION
// At index 270 : <select_arxmlmetaparser_5F_syntax_20>, in file 'arxmlmetaparser_syntax.ggs', line 400
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_minOccurs) // $minOccurs$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) // $=$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) // $xmlTagValue$
, NONTERMINAL (43) // <select_arxmlmetaparser_5F_syntax_20>
, END_PRODUCTION
// At index 275 : <select_arxmlmetaparser_5F_syntax_20>, in file 'arxmlmetaparser_syntax.ggs', line 400
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_type) // $type$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) // $=$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) // $xmlTagValue$
, NONTERMINAL (43) // <select_arxmlmetaparser_5F_syntax_20>
, END_PRODUCTION
// At index 280 : <select_arxmlmetaparser_5F_syntax_20>, in file 'arxmlmetaparser_syntax.ggs', line 400
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_name) // $name$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) // $=$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) // $xmlTagValue$
, NONTERMINAL (43) // <select_arxmlmetaparser_5F_syntax_20>
, END_PRODUCTION
// At index 285 : <select_arxmlmetaparser_5F_syntax_21>, in file 'arxmlmetaparser_syntax.ggs', line 473
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) // $>$
, NONTERMINAL (45) // <select_arxmlmetaparser_5F_syntax_22>
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_) // $</xsd:$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_element) // $element$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) // $>$
, END_PRODUCTION
// At index 291 : <select_arxmlmetaparser_5F_syntax_21>, in file 'arxmlmetaparser_syntax.ggs', line 473
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_) // $/>$
, END_PRODUCTION
// At index 293 : <select_arxmlmetaparser_5F_syntax_22>, in file 'arxmlmetaparser_syntax.ggs', line 474
, END_PRODUCTION
// At index 294 : <select_arxmlmetaparser_5F_syntax_22>, in file 'arxmlmetaparser_syntax.ggs', line 474
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_) // $<xsd:$
, NONTERMINAL (46) // <select_arxmlmetaparser_5F_syntax_23>
, NONTERMINAL (45) // <select_arxmlmetaparser_5F_syntax_22>
, END_PRODUCTION
// At index 298 : <select_arxmlmetaparser_5F_syntax_23>, in file 'arxmlmetaparser_syntax.ggs', line 476
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation) // $annotation$
, NONTERMINAL (2) // <xsd_annotation>
, END_PRODUCTION
// At index 301 : <select_arxmlmetaparser_5F_syntax_23>, in file 'arxmlmetaparser_syntax.ggs', line 476
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_complexType) // $complexType$
, NONTERMINAL (7) // <xsd_complexType>
, END_PRODUCTION
// At index 304 : <select_arxmlmetaparser_5F_syntax_23>, in file 'arxmlmetaparser_syntax.ggs', line 476
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_simpleType) // $simpleType$
, NONTERMINAL (18) // <xsd_simpleType>
, END_PRODUCTION
// At index 307 : <select_arxmlmetaparser_5F_syntax_24>, in file 'arxmlmetaparser_syntax.ggs', line 506
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) // $>$
, NONTERMINAL (48) // <select_arxmlmetaparser_5F_syntax_25>
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_) // $</xsd:$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_enumeration) // $enumeration$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) // $>$
, END_PRODUCTION
// At index 313 : <select_arxmlmetaparser_5F_syntax_24>, in file 'arxmlmetaparser_syntax.ggs', line 506
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_) // $/>$
, END_PRODUCTION
// At index 315 : <select_arxmlmetaparser_5F_syntax_25>, in file 'arxmlmetaparser_syntax.ggs', line 507
, END_PRODUCTION
// At index 316 : <select_arxmlmetaparser_5F_syntax_25>, in file 'arxmlmetaparser_syntax.ggs', line 507
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_) // $<xsd:$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation) // $annotation$
, NONTERMINAL (2) // <xsd_annotation>
, NONTERMINAL (48) // <select_arxmlmetaparser_5F_syntax_25>
, END_PRODUCTION
// At index 321 : <select_arxmlmetaparser_5F_syntax_26>, in file 'arxmlmetaparser_syntax.ggs', line 530
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) // $>$
, NONTERMINAL (50) // <select_arxmlmetaparser_5F_syntax_27>
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_) // $</xsd:$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_extension) // $extension$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) // $>$
, END_PRODUCTION
// At index 327 : <select_arxmlmetaparser_5F_syntax_26>, in file 'arxmlmetaparser_syntax.ggs', line 530
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_) // $/>$
, END_PRODUCTION
// At index 329 : <select_arxmlmetaparser_5F_syntax_27>, in file 'arxmlmetaparser_syntax.ggs', line 531
, END_PRODUCTION
// At index 330 : <select_arxmlmetaparser_5F_syntax_27>, in file 'arxmlmetaparser_syntax.ggs', line 531
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_) // $<xsd:$
, NONTERMINAL (51) // <select_arxmlmetaparser_5F_syntax_28>
, NONTERMINAL (50) // <select_arxmlmetaparser_5F_syntax_27>
, END_PRODUCTION
// At index 334 : <select_arxmlmetaparser_5F_syntax_28>, in file 'arxmlmetaparser_syntax.ggs', line 533
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation) // $annotation$
, NONTERMINAL (2) // <xsd_annotation>
, END_PRODUCTION
// At index 337 : <select_arxmlmetaparser_5F_syntax_28>, in file 'arxmlmetaparser_syntax.ggs', line 533
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attribute) // $attribute$
, NONTERMINAL (4) // <xsd_attribute>
, END_PRODUCTION
// At index 340 : <select_arxmlmetaparser_5F_syntax_28>, in file 'arxmlmetaparser_syntax.ggs', line 533
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attributeGroup) // $attributeGroup$
, NONTERMINAL (5) // <xsd_attributeGroup>
, END_PRODUCTION
// At index 343 : <select_arxmlmetaparser_5F_syntax_28>, in file 'arxmlmetaparser_syntax.ggs', line 533
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_choice) // $choice$
, NONTERMINAL (6) // <xsd_choice>
, END_PRODUCTION
// At index 346 : <select_arxmlmetaparser_5F_syntax_28>, in file 'arxmlmetaparser_syntax.ggs', line 533
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_sequence) // $sequence$
, NONTERMINAL (16) // <xsd_sequence>
, END_PRODUCTION
// At index 349 : <select_arxmlmetaparser_5F_syntax_28>, in file 'arxmlmetaparser_syntax.ggs', line 533
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_group) // $group$
, NONTERMINAL (12) // <xsd_group>
, END_PRODUCTION
// At index 352 : <select_arxmlmetaparser_5F_syntax_29>, in file 'arxmlmetaparser_syntax.ggs', line 566
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_name) // $name$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) // $=$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) // $xmlTagValue$
, END_PRODUCTION
// At index 356 : <select_arxmlmetaparser_5F_syntax_29>, in file 'arxmlmetaparser_syntax.ggs', line 566
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_ref) // $ref$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) // $=$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) // $xmlTagValue$
, END_PRODUCTION
// At index 360 : <select_arxmlmetaparser_5F_syntax_30>, in file 'arxmlmetaparser_syntax.ggs', line 607
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) // $>$
, NONTERMINAL (54) // <select_arxmlmetaparser_5F_syntax_31>
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_) // $</xsd:$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_group) // $group$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) // $>$
, END_PRODUCTION
// At index 366 : <select_arxmlmetaparser_5F_syntax_30>, in file 'arxmlmetaparser_syntax.ggs', line 607
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_) // $/>$
, END_PRODUCTION
// At index 368 : <select_arxmlmetaparser_5F_syntax_31>, in file 'arxmlmetaparser_syntax.ggs', line 608
, END_PRODUCTION
// At index 369 : <select_arxmlmetaparser_5F_syntax_31>, in file 'arxmlmetaparser_syntax.ggs', line 608
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_) // $<xsd:$
, NONTERMINAL (55) // <select_arxmlmetaparser_5F_syntax_32>
, NONTERMINAL (54) // <select_arxmlmetaparser_5F_syntax_31>
, END_PRODUCTION
// At index 373 : <select_arxmlmetaparser_5F_syntax_32>, in file 'arxmlmetaparser_syntax.ggs', line 610
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation) // $annotation$
, NONTERMINAL (2) // <xsd_annotation>
, END_PRODUCTION
// At index 376 : <select_arxmlmetaparser_5F_syntax_32>, in file 'arxmlmetaparser_syntax.ggs', line 610
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_choice) // $choice$
, NONTERMINAL (6) // <xsd_choice>
, END_PRODUCTION
// At index 379 : <select_arxmlmetaparser_5F_syntax_32>, in file 'arxmlmetaparser_syntax.ggs', line 610
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_sequence) // $sequence$
, NONTERMINAL (16) // <xsd_sequence>
, END_PRODUCTION
// At index 382 : <select_arxmlmetaparser_5F_syntax_32>, in file 'arxmlmetaparser_syntax.ggs', line 610
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_element) // $element$
, NONTERMINAL (9) // <xsd_element>
, END_PRODUCTION
// At index 385 : <select_arxmlmetaparser_5F_syntax_33>, in file 'arxmlmetaparser_syntax.ggs', line 636
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) // $>$
, NONTERMINAL (57) // <select_arxmlmetaparser_5F_syntax_34>
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_) // $</xsd:$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation) // $annotation$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) // $>$
, END_PRODUCTION
// At index 391 : <select_arxmlmetaparser_5F_syntax_33>, in file 'arxmlmetaparser_syntax.ggs', line 636
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_) // $/>$
, END_PRODUCTION
// At index 393 : <select_arxmlmetaparser_5F_syntax_34>, in file 'arxmlmetaparser_syntax.ggs', line 637
, END_PRODUCTION
// At index 394 : <select_arxmlmetaparser_5F_syntax_34>, in file 'arxmlmetaparser_syntax.ggs', line 637
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_) // $<xsd:$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation) // $annotation$
, NONTERMINAL (2) // <xsd_annotation>
, NONTERMINAL (57) // <select_arxmlmetaparser_5F_syntax_34>
, END_PRODUCTION
// At index 399 : <select_arxmlmetaparser_5F_syntax_35>, in file 'arxmlmetaparser_syntax.ggs', line 681
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) // $>$
, NONTERMINAL (59) // <select_arxmlmetaparser_5F_syntax_36>
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_) // $</xsd:$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_restriction) // $restriction$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) // $>$
, END_PRODUCTION
// At index 405 : <select_arxmlmetaparser_5F_syntax_35>, in file 'arxmlmetaparser_syntax.ggs', line 681
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_) // $/>$
, END_PRODUCTION
// At index 407 : <select_arxmlmetaparser_5F_syntax_36>, in file 'arxmlmetaparser_syntax.ggs', line 682
, END_PRODUCTION
// At index 408 : <select_arxmlmetaparser_5F_syntax_36>, in file 'arxmlmetaparser_syntax.ggs', line 682
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_) // $<xsd:$
, NONTERMINAL (60) // <select_arxmlmetaparser_5F_syntax_37>
, NONTERMINAL (59) // <select_arxmlmetaparser_5F_syntax_36>
, END_PRODUCTION
// At index 412 : <select_arxmlmetaparser_5F_syntax_37>, in file 'arxmlmetaparser_syntax.ggs', line 684
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation) // $annotation$
, NONTERMINAL (2) // <xsd_annotation>
, END_PRODUCTION
// At index 415 : <select_arxmlmetaparser_5F_syntax_37>, in file 'arxmlmetaparser_syntax.ggs', line 684
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attribute) // $attribute$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_TODO) // $TODO$
, NONTERMINAL (4) // <xsd_attribute>
, END_PRODUCTION
// At index 419 : <select_arxmlmetaparser_5F_syntax_37>, in file 'arxmlmetaparser_syntax.ggs', line 684
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attributeGroup) // $attributeGroup$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_TODO) // $TODO$
, NONTERMINAL (5) // <xsd_attributeGroup>
, END_PRODUCTION
// At index 423 : <select_arxmlmetaparser_5F_syntax_37>, in file 'arxmlmetaparser_syntax.ggs', line 684
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_choice) // $choice$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_TODO) // $TODO$
, NONTERMINAL (6) // <xsd_choice>
, END_PRODUCTION
// At index 427 : <select_arxmlmetaparser_5F_syntax_37>, in file 'arxmlmetaparser_syntax.ggs', line 684
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_sequence) // $sequence$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_TODO) // $TODO$
, NONTERMINAL (16) // <xsd_sequence>
, END_PRODUCTION
// At index 431 : <select_arxmlmetaparser_5F_syntax_37>, in file 'arxmlmetaparser_syntax.ggs', line 684
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_group) // $group$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_TODO) // $TODO$
, NONTERMINAL (12) // <xsd_group>
, END_PRODUCTION
// At index 435 : <select_arxmlmetaparser_5F_syntax_37>, in file 'arxmlmetaparser_syntax.ggs', line 684
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_simpleType) // $simpleType$
, NONTERMINAL (18) // <xsd_simpleType>
, END_PRODUCTION
// At index 438 : <select_arxmlmetaparser_5F_syntax_37>, in file 'arxmlmetaparser_syntax.ggs', line 684
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_whiteSpace) // $whiteSpace$
, NONTERMINAL (21) // <xsd_whiteSpace>
, END_PRODUCTION
// At index 441 : <select_arxmlmetaparser_5F_syntax_37>, in file 'arxmlmetaparser_syntax.ggs', line 684
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_maxLength) // $maxLength$
, NONTERMINAL (19) // <xsd_maxLength>
, END_PRODUCTION
// At index 444 : <select_arxmlmetaparser_5F_syntax_37>, in file 'arxmlmetaparser_syntax.ggs', line 684
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_pattern) // $pattern$
, NONTERMINAL (20) // <xsd_pattern>
, END_PRODUCTION
// At index 447 : <select_arxmlmetaparser_5F_syntax_37>, in file 'arxmlmetaparser_syntax.ggs', line 684
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_enumeration) // $enumeration$
, NONTERMINAL (10) // <xsd_enumeration>
, END_PRODUCTION
// At index 450 : <select_arxmlmetaparser_5F_syntax_38>, in file 'arxmlmetaparser_syntax.ggs', line 779
, END_PRODUCTION
// At index 451 : <select_arxmlmetaparser_5F_syntax_38>, in file 'arxmlmetaparser_syntax.ggs', line 779
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_) // $<xsd:$
, NONTERMINAL (62) // <select_arxmlmetaparser_5F_syntax_39>
, NONTERMINAL (61) // <select_arxmlmetaparser_5F_syntax_38>
, END_PRODUCTION
// At index 455 : <select_arxmlmetaparser_5F_syntax_39>, in file 'arxmlmetaparser_syntax.ggs', line 781
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation) // $annotation$
, NONTERMINAL (2) // <xsd_annotation>
, END_PRODUCTION
// At index 458 : <select_arxmlmetaparser_5F_syntax_39>, in file 'arxmlmetaparser_syntax.ggs', line 781
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attribute) // $attribute$
, NONTERMINAL (4) // <xsd_attribute>
, END_PRODUCTION
// At index 461 : <select_arxmlmetaparser_5F_syntax_39>, in file 'arxmlmetaparser_syntax.ggs', line 781
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attributeGroup) // $attributeGroup$
, NONTERMINAL (5) // <xsd_attributeGroup>
, END_PRODUCTION
// At index 464 : <select_arxmlmetaparser_5F_syntax_39>, in file 'arxmlmetaparser_syntax.ggs', line 781
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_complexType) // $complexType$
, NONTERMINAL (7) // <xsd_complexType>
, END_PRODUCTION
// At index 467 : <select_arxmlmetaparser_5F_syntax_39>, in file 'arxmlmetaparser_syntax.ggs', line 781
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_element) // $element$
, NONTERMINAL (9) // <xsd_element>
, END_PRODUCTION
// At index 470 : <select_arxmlmetaparser_5F_syntax_39>, in file 'arxmlmetaparser_syntax.ggs', line 781
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_group) // $group$
, NONTERMINAL (12) // <xsd_group>
, END_PRODUCTION
// At index 473 : <select_arxmlmetaparser_5F_syntax_39>, in file 'arxmlmetaparser_syntax.ggs', line 781
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_import) // $import$
, NONTERMINAL (13) // <xsd_import>
, END_PRODUCTION
// At index 476 : <select_arxmlmetaparser_5F_syntax_39>, in file 'arxmlmetaparser_syntax.ggs', line 781
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_simpleType) // $simpleType$
, NONTERMINAL (18) // <xsd_simpleType>
, END_PRODUCTION
// At index 479 : <select_arxmlmetaparser_5F_syntax_40>, in file 'arxmlmetaparser_syntax.ggs', line 815
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) // $>$
, NONTERMINAL (64) // <select_arxmlmetaparser_5F_syntax_41>
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_) // $</xsd:$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_sequence) // $sequence$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) // $>$
, END_PRODUCTION
// At index 485 : <select_arxmlmetaparser_5F_syntax_40>, in file 'arxmlmetaparser_syntax.ggs', line 815
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_) // $/>$
, END_PRODUCTION
// At index 487 : <select_arxmlmetaparser_5F_syntax_41>, in file 'arxmlmetaparser_syntax.ggs', line 816
, END_PRODUCTION
// At index 488 : <select_arxmlmetaparser_5F_syntax_41>, in file 'arxmlmetaparser_syntax.ggs', line 816
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_) // $<xsd:$
, NONTERMINAL (65) // <select_arxmlmetaparser_5F_syntax_42>
, NONTERMINAL (64) // <select_arxmlmetaparser_5F_syntax_41>
, END_PRODUCTION
// At index 492 : <select_arxmlmetaparser_5F_syntax_42>, in file 'arxmlmetaparser_syntax.ggs', line 818
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation) // $annotation$
, NONTERMINAL (2) // <xsd_annotation>
, END_PRODUCTION
// At index 495 : <select_arxmlmetaparser_5F_syntax_42>, in file 'arxmlmetaparser_syntax.ggs', line 818
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_choice) // $choice$
, NONTERMINAL (6) // <xsd_choice>
, END_PRODUCTION
// At index 498 : <select_arxmlmetaparser_5F_syntax_42>, in file 'arxmlmetaparser_syntax.ggs', line 818
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_sequence) // $sequence$
, NONTERMINAL (16) // <xsd_sequence>
, END_PRODUCTION
// At index 501 : <select_arxmlmetaparser_5F_syntax_42>, in file 'arxmlmetaparser_syntax.ggs', line 818
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_element) // $element$
, NONTERMINAL (9) // <xsd_element>
, END_PRODUCTION
// At index 504 : <select_arxmlmetaparser_5F_syntax_42>, in file 'arxmlmetaparser_syntax.ggs', line 818
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_group) // $group$
, NONTERMINAL (12) // <xsd_group>
, END_PRODUCTION
// At index 507 : <select_arxmlmetaparser_5F_syntax_43>, in file 'arxmlmetaparser_syntax.ggs', line 854
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) // $>$
, NONTERMINAL (67) // <select_arxmlmetaparser_5F_syntax_44>
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_) // $</xsd:$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_simpleContent) // $simpleContent$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) // $>$
, END_PRODUCTION
// At index 513 : <select_arxmlmetaparser_5F_syntax_43>, in file 'arxmlmetaparser_syntax.ggs', line 854
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_) // $/>$
, END_PRODUCTION
// At index 515 : <select_arxmlmetaparser_5F_syntax_44>, in file 'arxmlmetaparser_syntax.ggs', line 855
, END_PRODUCTION
// At index 516 : <select_arxmlmetaparser_5F_syntax_44>, in file 'arxmlmetaparser_syntax.ggs', line 855
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_) // $<xsd:$
, NONTERMINAL (68) // <select_arxmlmetaparser_5F_syntax_45>
, NONTERMINAL (67) // <select_arxmlmetaparser_5F_syntax_44>
, END_PRODUCTION
// At index 520 : <select_arxmlmetaparser_5F_syntax_45>, in file 'arxmlmetaparser_syntax.ggs', line 857
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation) // $annotation$
, NONTERMINAL (2) // <xsd_annotation>
, END_PRODUCTION
// At index 523 : <select_arxmlmetaparser_5F_syntax_45>, in file 'arxmlmetaparser_syntax.ggs', line 857
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_extension) // $extension$
, NONTERMINAL (11) // <xsd_extension>
, END_PRODUCTION
// At index 526 : <select_arxmlmetaparser_5F_syntax_46>, in file 'arxmlmetaparser_syntax.ggs', line 885
, END_PRODUCTION
// At index 527 : <select_arxmlmetaparser_5F_syntax_46>, in file 'arxmlmetaparser_syntax.ggs', line 885
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_name) // $name$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) // $=$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) // $xmlTagValue$
, NONTERMINAL (69) // <select_arxmlmetaparser_5F_syntax_46>
, END_PRODUCTION
// At index 532 : <select_arxmlmetaparser_5F_syntax_47>, in file 'arxmlmetaparser_syntax.ggs', line 918
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) // $>$
, NONTERMINAL (71) // <select_arxmlmetaparser_5F_syntax_48>
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_) // $</xsd:$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_simpleType) // $simpleType$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) // $>$
, END_PRODUCTION
// At index 538 : <select_arxmlmetaparser_5F_syntax_47>, in file 'arxmlmetaparser_syntax.ggs', line 918
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_) // $/>$
, END_PRODUCTION
// At index 540 : <select_arxmlmetaparser_5F_syntax_48>, in file 'arxmlmetaparser_syntax.ggs', line 919
, END_PRODUCTION
// At index 541 : <select_arxmlmetaparser_5F_syntax_48>, in file 'arxmlmetaparser_syntax.ggs', line 919
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_) // $<xsd:$
, NONTERMINAL (72) // <select_arxmlmetaparser_5F_syntax_49>
, NONTERMINAL (71) // <select_arxmlmetaparser_5F_syntax_48>
, END_PRODUCTION
// At index 545 : <select_arxmlmetaparser_5F_syntax_49>, in file 'arxmlmetaparser_syntax.ggs', line 921
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation) // $annotation$
, NONTERMINAL (2) // <xsd_annotation>
, END_PRODUCTION
// At index 548 : <select_arxmlmetaparser_5F_syntax_49>, in file 'arxmlmetaparser_syntax.ggs', line 921
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_restriction) // $restriction$
, NONTERMINAL (14) // <xsd_restriction>
, END_PRODUCTION
// At index 551 : <select_arxmlmetaparser_5F_syntax_50>, in file 'arxmlmetaparser_syntax.ggs', line 948
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) // $>$
, NONTERMINAL (74) // <select_arxmlmetaparser_5F_syntax_51>
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_) // $</xsd:$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_maxLength) // $maxLength$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) // $>$
, END_PRODUCTION
// At index 557 : <select_arxmlmetaparser_5F_syntax_50>, in file 'arxmlmetaparser_syntax.ggs', line 948
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_) // $/>$
, END_PRODUCTION
// At index 559 : <select_arxmlmetaparser_5F_syntax_51>, in file 'arxmlmetaparser_syntax.ggs', line 949
, END_PRODUCTION
// At index 560 : <select_arxmlmetaparser_5F_syntax_51>, in file 'arxmlmetaparser_syntax.ggs', line 949
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_) // $<xsd:$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation) // $annotation$
, NONTERMINAL (2) // <xsd_annotation>
, NONTERMINAL (74) // <select_arxmlmetaparser_5F_syntax_51>
, END_PRODUCTION
// At index 565 : <select_arxmlmetaparser_5F_syntax_52>, in file 'arxmlmetaparser_syntax.ggs', line 973
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) // $>$
, NONTERMINAL (76) // <select_arxmlmetaparser_5F_syntax_53>
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_) // $</xsd:$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_pattern) // $pattern$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) // $>$
, END_PRODUCTION
// At index 571 : <select_arxmlmetaparser_5F_syntax_52>, in file 'arxmlmetaparser_syntax.ggs', line 973
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_) // $/>$
, END_PRODUCTION
// At index 573 : <select_arxmlmetaparser_5F_syntax_53>, in file 'arxmlmetaparser_syntax.ggs', line 974
, END_PRODUCTION
// At index 574 : <select_arxmlmetaparser_5F_syntax_53>, in file 'arxmlmetaparser_syntax.ggs', line 974
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_) // $<xsd:$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation) // $annotation$
, NONTERMINAL (2) // <xsd_annotation>
, NONTERMINAL (76) // <select_arxmlmetaparser_5F_syntax_53>
, END_PRODUCTION
// At index 579 : <select_arxmlmetaparser_5F_syntax_54>, in file 'arxmlmetaparser_syntax.ggs', line 997
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) // $>$
, NONTERMINAL (78) // <select_arxmlmetaparser_5F_syntax_55>
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_) // $</xsd:$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_whiteSpace) // $whiteSpace$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_) // $>$
, END_PRODUCTION
// At index 585 : <select_arxmlmetaparser_5F_syntax_54>, in file 'arxmlmetaparser_syntax.ggs', line 997
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_) // $/>$
, END_PRODUCTION
// At index 587 : <select_arxmlmetaparser_5F_syntax_55>, in file 'arxmlmetaparser_syntax.ggs', line 998
, END_PRODUCTION
// At index 588 : <select_arxmlmetaparser_5F_syntax_55>, in file 'arxmlmetaparser_syntax.ggs', line 998
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_) // $<xsd:$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation) // $annotation$
, NONTERMINAL (2) // <xsd_annotation>
, NONTERMINAL (78) // <select_arxmlmetaparser_5F_syntax_55>
, END_PRODUCTION
// At index 593 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
, END_PRODUCTION
// At index 594 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_abstract) // $abstract$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) // $=$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) // $xmlTagValue$
, NONTERMINAL (79) // <select_arxmlmetaparser_5F_syntax_56>
, END_PRODUCTION
// At index 599 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attributeFormDefault) // $attributeFormDefault$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) // $=$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) // $xmlTagValue$
, NONTERMINAL (79) // <select_arxmlmetaparser_5F_syntax_56>
, END_PRODUCTION
// At index 604 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_attributeRef) // $attributeRef$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) // $=$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) // $xmlTagValue$
, NONTERMINAL (79) // <select_arxmlmetaparser_5F_syntax_56>
, END_PRODUCTION
// At index 609 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_base) // $base$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) // $=$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) // $xmlTagValue$
, NONTERMINAL (79) // <select_arxmlmetaparser_5F_syntax_56>
, END_PRODUCTION
// At index 614 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_category) // $category$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) // $=$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) // $xmlTagValue$
, NONTERMINAL (79) // <select_arxmlmetaparser_5F_syntax_56>
, END_PRODUCTION
// At index 619 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_CATEGORY) // $CATEGORY$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) // $=$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) // $xmlTagValue$
, NONTERMINAL (79) // <select_arxmlmetaparser_5F_syntax_56>
, END_PRODUCTION
// At index 624 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_color) // $color$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) // $=$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) // $xmlTagValue$
, NONTERMINAL (79) // <select_arxmlmetaparser_5F_syntax_56>
, END_PRODUCTION
// At index 629 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_customType) // $customType$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) // $=$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) // $xmlTagValue$
, NONTERMINAL (79) // <select_arxmlmetaparser_5F_syntax_56>
, END_PRODUCTION
// At index 634 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_elementFormDefault) // $elementFormDefault$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) // $=$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) // $xmlTagValue$
, NONTERMINAL (79) // <select_arxmlmetaparser_5F_syntax_56>
, END_PRODUCTION
// At index 639 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_encoding) // $encoding$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) // $=$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) // $xmlTagValue$
, NONTERMINAL (79) // <select_arxmlmetaparser_5F_syntax_56>
, END_PRODUCTION
// At index 644 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_enforceMinMultiplicity) // $enforceMinMultiplicity$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) // $=$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) // $xmlTagValue$
, NONTERMINAL (79) // <select_arxmlmetaparser_5F_syntax_56>
, END_PRODUCTION
// At index 649 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_globalElement) // $globalElement$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) // $=$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) // $xmlTagValue$
, NONTERMINAL (79) // <select_arxmlmetaparser_5F_syntax_56>
, END_PRODUCTION
// At index 654 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_id) // $id$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) // $=$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) // $xmlTagValue$
, NONTERMINAL (79) // <select_arxmlmetaparser_5F_syntax_56>
, END_PRODUCTION
// At index 659 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_latestBindingTime) // $latestBindingTime$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) // $=$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) // $xmlTagValue$
, NONTERMINAL (79) // <select_arxmlmetaparser_5F_syntax_56>
, END_PRODUCTION
// At index 664 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_maxOccurs) // $maxOccurs$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) // $=$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) // $xmlTagValue$
, NONTERMINAL (79) // <select_arxmlmetaparser_5F_syntax_56>
, END_PRODUCTION
// At index 669 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_minOccurs) // $minOccurs$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) // $=$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) // $xmlTagValue$
, NONTERMINAL (79) // <select_arxmlmetaparser_5F_syntax_56>
, END_PRODUCTION
// At index 674 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_mixed) // $mixed$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) // $=$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) // $xmlTagValue$
, NONTERMINAL (79) // <select_arxmlmetaparser_5F_syntax_56>
, END_PRODUCTION
// At index 679 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_name) // $name$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) // $=$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) // $xmlTagValue$
, NONTERMINAL (79) // <select_arxmlmetaparser_5F_syntax_56>
, END_PRODUCTION
// At index 684 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_namePlural) // $namePlural$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) // $=$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) // $xmlTagValue$
, NONTERMINAL (79) // <select_arxmlmetaparser_5F_syntax_56>
, END_PRODUCTION
// At index 689 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_namespace) // $namespace$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) // $=$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) // $xmlTagValue$
, NONTERMINAL (79) // <select_arxmlmetaparser_5F_syntax_56>
, END_PRODUCTION
// At index 694 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_noteType) // $noteType$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) // $=$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) // $xmlTagValue$
, NONTERMINAL (79) // <select_arxmlmetaparser_5F_syntax_56>
, END_PRODUCTION
// At index 699 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_nsPrefix) // $nsPrefix$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) // $=$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) // $xmlTagValue$
, NONTERMINAL (79) // <select_arxmlmetaparser_5F_syntax_56>
, END_PRODUCTION
// At index 704 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_qualifiedName) // $qualifiedName$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) // $=$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) // $xmlTagValue$
, NONTERMINAL (79) // <select_arxmlmetaparser_5F_syntax_56>
, END_PRODUCTION
// At index 709 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_recommendedPackage) // $recommendedPackage$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) // $=$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) // $xmlTagValue$
, NONTERMINAL (79) // <select_arxmlmetaparser_5F_syntax_56>
, END_PRODUCTION
// At index 714 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_ref) // $ref$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) // $=$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) // $xmlTagValue$
, NONTERMINAL (79) // <select_arxmlmetaparser_5F_syntax_56>
, END_PRODUCTION
// At index 719 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_roleElement) // $roleElement$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) // $=$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) // $xmlTagValue$
, NONTERMINAL (79) // <select_arxmlmetaparser_5F_syntax_56>
, END_PRODUCTION
// At index 724 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_roleWrapperElement) // $roleWrapperElement$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) // $=$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) // $xmlTagValue$
, NONTERMINAL (79) // <select_arxmlmetaparser_5F_syntax_56>
, END_PRODUCTION
// At index 729 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_schemaLocation) // $schemaLocation$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) // $=$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) // $xmlTagValue$
, NONTERMINAL (79) // <select_arxmlmetaparser_5F_syntax_56>
, END_PRODUCTION
// At index 734 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_sequenceOffset) // $sequenceOffset$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) // $=$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) // $xmlTagValue$
, NONTERMINAL (79) // <select_arxmlmetaparser_5F_syntax_56>
, END_PRODUCTION
// At index 739 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_source) // $source$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) // $=$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) // $xmlTagValue$
, NONTERMINAL (79) // <select_arxmlmetaparser_5F_syntax_56>
, END_PRODUCTION
// At index 744 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_Splitkey) // $Splitkey$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) // $=$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) // $xmlTagValue$
, NONTERMINAL (79) // <select_arxmlmetaparser_5F_syntax_56>
, END_PRODUCTION
// At index 749 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_Status) // $Status$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) // $=$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) // $xmlTagValue$
, NONTERMINAL (79) // <select_arxmlmetaparser_5F_syntax_56>
, END_PRODUCTION
// At index 754 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_StatusRevisionBegin) // $StatusRevisionBegin$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) // $=$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) // $xmlTagValue$
, NONTERMINAL (79) // <select_arxmlmetaparser_5F_syntax_56>
, END_PRODUCTION
// At index 759 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_targetNamespace) // $targetNamespace$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) // $=$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) // $xmlTagValue$
, NONTERMINAL (79) // <select_arxmlmetaparser_5F_syntax_56>
, END_PRODUCTION
// At index 764 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_type) // $type$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) // $=$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) // $xmlTagValue$
, NONTERMINAL (79) // <select_arxmlmetaparser_5F_syntax_56>
, END_PRODUCTION
// At index 769 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_typeElement) // $typeElement$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) // $=$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) // $xmlTagValue$
, NONTERMINAL (79) // <select_arxmlmetaparser_5F_syntax_56>
, END_PRODUCTION
// At index 774 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_typeWrapperElement) // $typeWrapperElement$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) // $=$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) // $xmlTagValue$
, NONTERMINAL (79) // <select_arxmlmetaparser_5F_syntax_56>
, END_PRODUCTION
// At index 779 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_use) // $use$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) // $=$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) // $xmlTagValue$
, NONTERMINAL (79) // <select_arxmlmetaparser_5F_syntax_56>
, END_PRODUCTION
// At index 784 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_value) // $value$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) // $=$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) // $xmlTagValue$
, NONTERMINAL (79) // <select_arxmlmetaparser_5F_syntax_56>
, END_PRODUCTION
// At index 789 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_version) // $version$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) // $=$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) // $xmlTagValue$
, NONTERMINAL (79) // <select_arxmlmetaparser_5F_syntax_56>
, END_PRODUCTION
// At index 794 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlns_3A_AR) // $xmlns:AR$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) // $=$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) // $xmlTagValue$
, NONTERMINAL (79) // <select_arxmlmetaparser_5F_syntax_56>
, END_PRODUCTION
// At index 799 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlns_3A_xsd) // $xmlns:xsd$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken__3D_) // $=$
, TERMINAL (C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlTagValue) // $xmlTagValue$
, NONTERMINAL (79) // <select_arxmlmetaparser_5F_syntax_56>
, END_PRODUCTION
// At index 804 : <>, in file '.ggs', line 0
, NONTERMINAL (0) // <arxmlmetaparser_start_symbol>
, END_PRODUCTION
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                          P R O D U C T I O N    N A M E S                                            
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const cProductionNameDescriptor gProductionNames_arxmlmetaparser_grammar [223] = {
 {"<arxmlmetaparser_start_symbol>", "arxmlmetaparser_syntax", 0}, // at index 0
 {"<xml_header>", "arxmlmetaparser_syntax", 3}, // at index 1
 {"<xsd_annotation>", "arxmlmetaparser_syntax", 7}, // at index 2
 {"<xsd_appinfo>", "arxmlmetaparser_syntax", 10}, // at index 3
 {"<xsd_attribute>", "arxmlmetaparser_syntax", 13}, // at index 4
 {"<xsd_attributeGroup>", "arxmlmetaparser_syntax", 16}, // at index 5
 {"<xsd_choice>", "arxmlmetaparser_syntax", 19}, // at index 6
 {"<xsd_complexType>", "arxmlmetaparser_syntax", 22}, // at index 7
 {"<xsd_documentation>", "arxmlmetaparser_syntax", 25}, // at index 8
 {"<xsd_element>", "arxmlmetaparser_syntax", 28}, // at index 9
 {"<xsd_enumeration>", "arxmlmetaparser_syntax", 31}, // at index 10
 {"<xsd_extension>", "arxmlmetaparser_syntax", 36}, // at index 11
 {"<xsd_group>", "arxmlmetaparser_syntax", 39}, // at index 12
 {"<xsd_import>", "arxmlmetaparser_syntax", 42}, // at index 13
 {"<xsd_restriction>", "arxmlmetaparser_syntax", 45}, // at index 14
 {"<xsd_schema>", "arxmlmetaparser_syntax", 50}, // at index 15
 {"<xsd_sequence>", "arxmlmetaparser_syntax", 59}, // at index 16
 {"<xsd_simpleContent>", "arxmlmetaparser_syntax", 61}, // at index 17
 {"<xsd_simpleType>", "arxmlmetaparser_syntax", 63}, // at index 18
 {"<xsd_maxLength>", "arxmlmetaparser_syntax", 66}, // at index 19
 {"<xsd_pattern>", "arxmlmetaparser_syntax", 69}, // at index 20
 {"<xsd_whiteSpace>", "arxmlmetaparser_syntax", 72}, // at index 21
 {"<xsd_ignore_attributes>", "arxmlmetaparser_syntax", 75}, // at index 22
 {"<select_arxmlmetaparser_5F_syntax_0>", "arxmlmetaparser_syntax", 77}, // at index 23
 {"<select_arxmlmetaparser_5F_syntax_0>", "arxmlmetaparser_syntax", 83}, // at index 24
 {"<select_arxmlmetaparser_5F_syntax_1>", "arxmlmetaparser_syntax", 85}, // at index 25
 {"<select_arxmlmetaparser_5F_syntax_1>", "arxmlmetaparser_syntax", 86}, // at index 26
 {"<select_arxmlmetaparser_5F_syntax_2>", "arxmlmetaparser_syntax", 90}, // at index 27
 {"<select_arxmlmetaparser_5F_syntax_2>", "arxmlmetaparser_syntax", 93}, // at index 28
 {"<select_arxmlmetaparser_5F_syntax_3>", "arxmlmetaparser_syntax", 96}, // at index 29
 {"<select_arxmlmetaparser_5F_syntax_3>", "arxmlmetaparser_syntax", 101}, // at index 30
 {"<select_arxmlmetaparser_5F_syntax_4>", "arxmlmetaparser_syntax", 103}, // at index 31
 {"<select_arxmlmetaparser_5F_syntax_4>", "arxmlmetaparser_syntax", 104}, // at index 32
 {"<select_arxmlmetaparser_5F_syntax_4>", "arxmlmetaparser_syntax", 109}, // at index 33
 {"<select_arxmlmetaparser_5F_syntax_4>", "arxmlmetaparser_syntax", 114}, // at index 34
 {"<select_arxmlmetaparser_5F_syntax_4>", "arxmlmetaparser_syntax", 119}, // at index 35
 {"<select_arxmlmetaparser_5F_syntax_5>", "arxmlmetaparser_syntax", 124}, // at index 36
 {"<select_arxmlmetaparser_5F_syntax_5>", "arxmlmetaparser_syntax", 130}, // at index 37
 {"<select_arxmlmetaparser_5F_syntax_6>", "arxmlmetaparser_syntax", 132}, // at index 38
 {"<select_arxmlmetaparser_5F_syntax_6>", "arxmlmetaparser_syntax", 133}, // at index 39
 {"<select_arxmlmetaparser_5F_syntax_7>", "arxmlmetaparser_syntax", 137}, // at index 40
 {"<select_arxmlmetaparser_5F_syntax_7>", "arxmlmetaparser_syntax", 140}, // at index 41
 {"<select_arxmlmetaparser_5F_syntax_8>", "arxmlmetaparser_syntax", 143}, // at index 42
 {"<select_arxmlmetaparser_5F_syntax_8>", "arxmlmetaparser_syntax", 147}, // at index 43
 {"<select_arxmlmetaparser_5F_syntax_9>", "arxmlmetaparser_syntax", 151}, // at index 44
 {"<select_arxmlmetaparser_5F_syntax_9>", "arxmlmetaparser_syntax", 157}, // at index 45
 {"<select_arxmlmetaparser_5F_syntax_10>", "arxmlmetaparser_syntax", 159}, // at index 46
 {"<select_arxmlmetaparser_5F_syntax_10>", "arxmlmetaparser_syntax", 160}, // at index 47
 {"<select_arxmlmetaparser_5F_syntax_11>", "arxmlmetaparser_syntax", 164}, // at index 48
 {"<select_arxmlmetaparser_5F_syntax_11>", "arxmlmetaparser_syntax", 167}, // at index 49
 {"<select_arxmlmetaparser_5F_syntax_11>", "arxmlmetaparser_syntax", 170}, // at index 50
 {"<select_arxmlmetaparser_5F_syntax_11>", "arxmlmetaparser_syntax", 173}, // at index 51
 {"<select_arxmlmetaparser_5F_syntax_11>", "arxmlmetaparser_syntax", 176}, // at index 52
 {"<select_arxmlmetaparser_5F_syntax_12>", "arxmlmetaparser_syntax", 179}, // at index 53
 {"<select_arxmlmetaparser_5F_syntax_12>", "arxmlmetaparser_syntax", 185}, // at index 54
 {"<select_arxmlmetaparser_5F_syntax_13>", "arxmlmetaparser_syntax", 187}, // at index 55
 {"<select_arxmlmetaparser_5F_syntax_13>", "arxmlmetaparser_syntax", 188}, // at index 56
 {"<select_arxmlmetaparser_5F_syntax_14>", "arxmlmetaparser_syntax", 192}, // at index 57
 {"<select_arxmlmetaparser_5F_syntax_14>", "arxmlmetaparser_syntax", 195}, // at index 58
 {"<select_arxmlmetaparser_5F_syntax_14>", "arxmlmetaparser_syntax", 198}, // at index 59
 {"<select_arxmlmetaparser_5F_syntax_14>", "arxmlmetaparser_syntax", 201}, // at index 60
 {"<select_arxmlmetaparser_5F_syntax_14>", "arxmlmetaparser_syntax", 204}, // at index 61
 {"<select_arxmlmetaparser_5F_syntax_15>", "arxmlmetaparser_syntax", 207}, // at index 62
 {"<select_arxmlmetaparser_5F_syntax_15>", "arxmlmetaparser_syntax", 208}, // at index 63
 {"<select_arxmlmetaparser_5F_syntax_15>", "arxmlmetaparser_syntax", 213}, // at index 64
 {"<select_arxmlmetaparser_5F_syntax_15>", "arxmlmetaparser_syntax", 218}, // at index 65
 {"<select_arxmlmetaparser_5F_syntax_16>", "arxmlmetaparser_syntax", 223}, // at index 66
 {"<select_arxmlmetaparser_5F_syntax_16>", "arxmlmetaparser_syntax", 229}, // at index 67
 {"<select_arxmlmetaparser_5F_syntax_17>", "arxmlmetaparser_syntax", 231}, // at index 68
 {"<select_arxmlmetaparser_5F_syntax_17>", "arxmlmetaparser_syntax", 232}, // at index 69
 {"<select_arxmlmetaparser_5F_syntax_18>", "arxmlmetaparser_syntax", 236}, // at index 70
 {"<select_arxmlmetaparser_5F_syntax_18>", "arxmlmetaparser_syntax", 239}, // at index 71
 {"<select_arxmlmetaparser_5F_syntax_18>", "arxmlmetaparser_syntax", 242}, // at index 72
 {"<select_arxmlmetaparser_5F_syntax_18>", "arxmlmetaparser_syntax", 245}, // at index 73
 {"<select_arxmlmetaparser_5F_syntax_18>", "arxmlmetaparser_syntax", 248}, // at index 74
 {"<select_arxmlmetaparser_5F_syntax_18>", "arxmlmetaparser_syntax", 251}, // at index 75
 {"<select_arxmlmetaparser_5F_syntax_18>", "arxmlmetaparser_syntax", 254}, // at index 76
 {"<select_arxmlmetaparser_5F_syntax_19>", "arxmlmetaparser_syntax", 257}, // at index 77
 {"<select_arxmlmetaparser_5F_syntax_19>", "arxmlmetaparser_syntax", 262}, // at index 78
 {"<select_arxmlmetaparser_5F_syntax_20>", "arxmlmetaparser_syntax", 264}, // at index 79
 {"<select_arxmlmetaparser_5F_syntax_20>", "arxmlmetaparser_syntax", 265}, // at index 80
 {"<select_arxmlmetaparser_5F_syntax_20>", "arxmlmetaparser_syntax", 270}, // at index 81
 {"<select_arxmlmetaparser_5F_syntax_20>", "arxmlmetaparser_syntax", 275}, // at index 82
 {"<select_arxmlmetaparser_5F_syntax_20>", "arxmlmetaparser_syntax", 280}, // at index 83
 {"<select_arxmlmetaparser_5F_syntax_21>", "arxmlmetaparser_syntax", 285}, // at index 84
 {"<select_arxmlmetaparser_5F_syntax_21>", "arxmlmetaparser_syntax", 291}, // at index 85
 {"<select_arxmlmetaparser_5F_syntax_22>", "arxmlmetaparser_syntax", 293}, // at index 86
 {"<select_arxmlmetaparser_5F_syntax_22>", "arxmlmetaparser_syntax", 294}, // at index 87
 {"<select_arxmlmetaparser_5F_syntax_23>", "arxmlmetaparser_syntax", 298}, // at index 88
 {"<select_arxmlmetaparser_5F_syntax_23>", "arxmlmetaparser_syntax", 301}, // at index 89
 {"<select_arxmlmetaparser_5F_syntax_23>", "arxmlmetaparser_syntax", 304}, // at index 90
 {"<select_arxmlmetaparser_5F_syntax_24>", "arxmlmetaparser_syntax", 307}, // at index 91
 {"<select_arxmlmetaparser_5F_syntax_24>", "arxmlmetaparser_syntax", 313}, // at index 92
 {"<select_arxmlmetaparser_5F_syntax_25>", "arxmlmetaparser_syntax", 315}, // at index 93
 {"<select_arxmlmetaparser_5F_syntax_25>", "arxmlmetaparser_syntax", 316}, // at index 94
 {"<select_arxmlmetaparser_5F_syntax_26>", "arxmlmetaparser_syntax", 321}, // at index 95
 {"<select_arxmlmetaparser_5F_syntax_26>", "arxmlmetaparser_syntax", 327}, // at index 96
 {"<select_arxmlmetaparser_5F_syntax_27>", "arxmlmetaparser_syntax", 329}, // at index 97
 {"<select_arxmlmetaparser_5F_syntax_27>", "arxmlmetaparser_syntax", 330}, // at index 98
 {"<select_arxmlmetaparser_5F_syntax_28>", "arxmlmetaparser_syntax", 334}, // at index 99
 {"<select_arxmlmetaparser_5F_syntax_28>", "arxmlmetaparser_syntax", 337}, // at index 100
 {"<select_arxmlmetaparser_5F_syntax_28>", "arxmlmetaparser_syntax", 340}, // at index 101
 {"<select_arxmlmetaparser_5F_syntax_28>", "arxmlmetaparser_syntax", 343}, // at index 102
 {"<select_arxmlmetaparser_5F_syntax_28>", "arxmlmetaparser_syntax", 346}, // at index 103
 {"<select_arxmlmetaparser_5F_syntax_28>", "arxmlmetaparser_syntax", 349}, // at index 104
 {"<select_arxmlmetaparser_5F_syntax_29>", "arxmlmetaparser_syntax", 352}, // at index 105
 {"<select_arxmlmetaparser_5F_syntax_29>", "arxmlmetaparser_syntax", 356}, // at index 106
 {"<select_arxmlmetaparser_5F_syntax_30>", "arxmlmetaparser_syntax", 360}, // at index 107
 {"<select_arxmlmetaparser_5F_syntax_30>", "arxmlmetaparser_syntax", 366}, // at index 108
 {"<select_arxmlmetaparser_5F_syntax_31>", "arxmlmetaparser_syntax", 368}, // at index 109
 {"<select_arxmlmetaparser_5F_syntax_31>", "arxmlmetaparser_syntax", 369}, // at index 110
 {"<select_arxmlmetaparser_5F_syntax_32>", "arxmlmetaparser_syntax", 373}, // at index 111
 {"<select_arxmlmetaparser_5F_syntax_32>", "arxmlmetaparser_syntax", 376}, // at index 112
 {"<select_arxmlmetaparser_5F_syntax_32>", "arxmlmetaparser_syntax", 379}, // at index 113
 {"<select_arxmlmetaparser_5F_syntax_32>", "arxmlmetaparser_syntax", 382}, // at index 114
 {"<select_arxmlmetaparser_5F_syntax_33>", "arxmlmetaparser_syntax", 385}, // at index 115
 {"<select_arxmlmetaparser_5F_syntax_33>", "arxmlmetaparser_syntax", 391}, // at index 116
 {"<select_arxmlmetaparser_5F_syntax_34>", "arxmlmetaparser_syntax", 393}, // at index 117
 {"<select_arxmlmetaparser_5F_syntax_34>", "arxmlmetaparser_syntax", 394}, // at index 118
 {"<select_arxmlmetaparser_5F_syntax_35>", "arxmlmetaparser_syntax", 399}, // at index 119
 {"<select_arxmlmetaparser_5F_syntax_35>", "arxmlmetaparser_syntax", 405}, // at index 120
 {"<select_arxmlmetaparser_5F_syntax_36>", "arxmlmetaparser_syntax", 407}, // at index 121
 {"<select_arxmlmetaparser_5F_syntax_36>", "arxmlmetaparser_syntax", 408}, // at index 122
 {"<select_arxmlmetaparser_5F_syntax_37>", "arxmlmetaparser_syntax", 412}, // at index 123
 {"<select_arxmlmetaparser_5F_syntax_37>", "arxmlmetaparser_syntax", 415}, // at index 124
 {"<select_arxmlmetaparser_5F_syntax_37>", "arxmlmetaparser_syntax", 419}, // at index 125
 {"<select_arxmlmetaparser_5F_syntax_37>", "arxmlmetaparser_syntax", 423}, // at index 126
 {"<select_arxmlmetaparser_5F_syntax_37>", "arxmlmetaparser_syntax", 427}, // at index 127
 {"<select_arxmlmetaparser_5F_syntax_37>", "arxmlmetaparser_syntax", 431}, // at index 128
 {"<select_arxmlmetaparser_5F_syntax_37>", "arxmlmetaparser_syntax", 435}, // at index 129
 {"<select_arxmlmetaparser_5F_syntax_37>", "arxmlmetaparser_syntax", 438}, // at index 130
 {"<select_arxmlmetaparser_5F_syntax_37>", "arxmlmetaparser_syntax", 441}, // at index 131
 {"<select_arxmlmetaparser_5F_syntax_37>", "arxmlmetaparser_syntax", 444}, // at index 132
 {"<select_arxmlmetaparser_5F_syntax_37>", "arxmlmetaparser_syntax", 447}, // at index 133
 {"<select_arxmlmetaparser_5F_syntax_38>", "arxmlmetaparser_syntax", 450}, // at index 134
 {"<select_arxmlmetaparser_5F_syntax_38>", "arxmlmetaparser_syntax", 451}, // at index 135
 {"<select_arxmlmetaparser_5F_syntax_39>", "arxmlmetaparser_syntax", 455}, // at index 136
 {"<select_arxmlmetaparser_5F_syntax_39>", "arxmlmetaparser_syntax", 458}, // at index 137
 {"<select_arxmlmetaparser_5F_syntax_39>", "arxmlmetaparser_syntax", 461}, // at index 138
 {"<select_arxmlmetaparser_5F_syntax_39>", "arxmlmetaparser_syntax", 464}, // at index 139
 {"<select_arxmlmetaparser_5F_syntax_39>", "arxmlmetaparser_syntax", 467}, // at index 140
 {"<select_arxmlmetaparser_5F_syntax_39>", "arxmlmetaparser_syntax", 470}, // at index 141
 {"<select_arxmlmetaparser_5F_syntax_39>", "arxmlmetaparser_syntax", 473}, // at index 142
 {"<select_arxmlmetaparser_5F_syntax_39>", "arxmlmetaparser_syntax", 476}, // at index 143
 {"<select_arxmlmetaparser_5F_syntax_40>", "arxmlmetaparser_syntax", 479}, // at index 144
 {"<select_arxmlmetaparser_5F_syntax_40>", "arxmlmetaparser_syntax", 485}, // at index 145
 {"<select_arxmlmetaparser_5F_syntax_41>", "arxmlmetaparser_syntax", 487}, // at index 146
 {"<select_arxmlmetaparser_5F_syntax_41>", "arxmlmetaparser_syntax", 488}, // at index 147
 {"<select_arxmlmetaparser_5F_syntax_42>", "arxmlmetaparser_syntax", 492}, // at index 148
 {"<select_arxmlmetaparser_5F_syntax_42>", "arxmlmetaparser_syntax", 495}, // at index 149
 {"<select_arxmlmetaparser_5F_syntax_42>", "arxmlmetaparser_syntax", 498}, // at index 150
 {"<select_arxmlmetaparser_5F_syntax_42>", "arxmlmetaparser_syntax", 501}, // at index 151
 {"<select_arxmlmetaparser_5F_syntax_42>", "arxmlmetaparser_syntax", 504}, // at index 152
 {"<select_arxmlmetaparser_5F_syntax_43>", "arxmlmetaparser_syntax", 507}, // at index 153
 {"<select_arxmlmetaparser_5F_syntax_43>", "arxmlmetaparser_syntax", 513}, // at index 154
 {"<select_arxmlmetaparser_5F_syntax_44>", "arxmlmetaparser_syntax", 515}, // at index 155
 {"<select_arxmlmetaparser_5F_syntax_44>", "arxmlmetaparser_syntax", 516}, // at index 156
 {"<select_arxmlmetaparser_5F_syntax_45>", "arxmlmetaparser_syntax", 520}, // at index 157
 {"<select_arxmlmetaparser_5F_syntax_45>", "arxmlmetaparser_syntax", 523}, // at index 158
 {"<select_arxmlmetaparser_5F_syntax_46>", "arxmlmetaparser_syntax", 526}, // at index 159
 {"<select_arxmlmetaparser_5F_syntax_46>", "arxmlmetaparser_syntax", 527}, // at index 160
 {"<select_arxmlmetaparser_5F_syntax_47>", "arxmlmetaparser_syntax", 532}, // at index 161
 {"<select_arxmlmetaparser_5F_syntax_47>", "arxmlmetaparser_syntax", 538}, // at index 162
 {"<select_arxmlmetaparser_5F_syntax_48>", "arxmlmetaparser_syntax", 540}, // at index 163
 {"<select_arxmlmetaparser_5F_syntax_48>", "arxmlmetaparser_syntax", 541}, // at index 164
 {"<select_arxmlmetaparser_5F_syntax_49>", "arxmlmetaparser_syntax", 545}, // at index 165
 {"<select_arxmlmetaparser_5F_syntax_49>", "arxmlmetaparser_syntax", 548}, // at index 166
 {"<select_arxmlmetaparser_5F_syntax_50>", "arxmlmetaparser_syntax", 551}, // at index 167
 {"<select_arxmlmetaparser_5F_syntax_50>", "arxmlmetaparser_syntax", 557}, // at index 168
 {"<select_arxmlmetaparser_5F_syntax_51>", "arxmlmetaparser_syntax", 559}, // at index 169
 {"<select_arxmlmetaparser_5F_syntax_51>", "arxmlmetaparser_syntax", 560}, // at index 170
 {"<select_arxmlmetaparser_5F_syntax_52>", "arxmlmetaparser_syntax", 565}, // at index 171
 {"<select_arxmlmetaparser_5F_syntax_52>", "arxmlmetaparser_syntax", 571}, // at index 172
 {"<select_arxmlmetaparser_5F_syntax_53>", "arxmlmetaparser_syntax", 573}, // at index 173
 {"<select_arxmlmetaparser_5F_syntax_53>", "arxmlmetaparser_syntax", 574}, // at index 174
 {"<select_arxmlmetaparser_5F_syntax_54>", "arxmlmetaparser_syntax", 579}, // at index 175
 {"<select_arxmlmetaparser_5F_syntax_54>", "arxmlmetaparser_syntax", 585}, // at index 176
 {"<select_arxmlmetaparser_5F_syntax_55>", "arxmlmetaparser_syntax", 587}, // at index 177
 {"<select_arxmlmetaparser_5F_syntax_55>", "arxmlmetaparser_syntax", 588}, // at index 178
 {"<select_arxmlmetaparser_5F_syntax_56>", "arxmlmetaparser_syntax", 593}, // at index 179
 {"<select_arxmlmetaparser_5F_syntax_56>", "arxmlmetaparser_syntax", 594}, // at index 180
 {"<select_arxmlmetaparser_5F_syntax_56>", "arxmlmetaparser_syntax", 599}, // at index 181
 {"<select_arxmlmetaparser_5F_syntax_56>", "arxmlmetaparser_syntax", 604}, // at index 182
 {"<select_arxmlmetaparser_5F_syntax_56>", "arxmlmetaparser_syntax", 609}, // at index 183
 {"<select_arxmlmetaparser_5F_syntax_56>", "arxmlmetaparser_syntax", 614}, // at index 184
 {"<select_arxmlmetaparser_5F_syntax_56>", "arxmlmetaparser_syntax", 619}, // at index 185
 {"<select_arxmlmetaparser_5F_syntax_56>", "arxmlmetaparser_syntax", 624}, // at index 186
 {"<select_arxmlmetaparser_5F_syntax_56>", "arxmlmetaparser_syntax", 629}, // at index 187
 {"<select_arxmlmetaparser_5F_syntax_56>", "arxmlmetaparser_syntax", 634}, // at index 188
 {"<select_arxmlmetaparser_5F_syntax_56>", "arxmlmetaparser_syntax", 639}, // at index 189
 {"<select_arxmlmetaparser_5F_syntax_56>", "arxmlmetaparser_syntax", 644}, // at index 190
 {"<select_arxmlmetaparser_5F_syntax_56>", "arxmlmetaparser_syntax", 649}, // at index 191
 {"<select_arxmlmetaparser_5F_syntax_56>", "arxmlmetaparser_syntax", 654}, // at index 192
 {"<select_arxmlmetaparser_5F_syntax_56>", "arxmlmetaparser_syntax", 659}, // at index 193
 {"<select_arxmlmetaparser_5F_syntax_56>", "arxmlmetaparser_syntax", 664}, // at index 194
 {"<select_arxmlmetaparser_5F_syntax_56>", "arxmlmetaparser_syntax", 669}, // at index 195
 {"<select_arxmlmetaparser_5F_syntax_56>", "arxmlmetaparser_syntax", 674}, // at index 196
 {"<select_arxmlmetaparser_5F_syntax_56>", "arxmlmetaparser_syntax", 679}, // at index 197
 {"<select_arxmlmetaparser_5F_syntax_56>", "arxmlmetaparser_syntax", 684}, // at index 198
 {"<select_arxmlmetaparser_5F_syntax_56>", "arxmlmetaparser_syntax", 689}, // at index 199
 {"<select_arxmlmetaparser_5F_syntax_56>", "arxmlmetaparser_syntax", 694}, // at index 200
 {"<select_arxmlmetaparser_5F_syntax_56>", "arxmlmetaparser_syntax", 699}, // at index 201
 {"<select_arxmlmetaparser_5F_syntax_56>", "arxmlmetaparser_syntax", 704}, // at index 202
 {"<select_arxmlmetaparser_5F_syntax_56>", "arxmlmetaparser_syntax", 709}, // at index 203
 {"<select_arxmlmetaparser_5F_syntax_56>", "arxmlmetaparser_syntax", 714}, // at index 204
 {"<select_arxmlmetaparser_5F_syntax_56>", "arxmlmetaparser_syntax", 719}, // at index 205
 {"<select_arxmlmetaparser_5F_syntax_56>", "arxmlmetaparser_syntax", 724}, // at index 206
 {"<select_arxmlmetaparser_5F_syntax_56>", "arxmlmetaparser_syntax", 729}, // at index 207
 {"<select_arxmlmetaparser_5F_syntax_56>", "arxmlmetaparser_syntax", 734}, // at index 208
 {"<select_arxmlmetaparser_5F_syntax_56>", "arxmlmetaparser_syntax", 739}, // at index 209
 {"<select_arxmlmetaparser_5F_syntax_56>", "arxmlmetaparser_syntax", 744}, // at index 210
 {"<select_arxmlmetaparser_5F_syntax_56>", "arxmlmetaparser_syntax", 749}, // at index 211
 {"<select_arxmlmetaparser_5F_syntax_56>", "arxmlmetaparser_syntax", 754}, // at index 212
 {"<select_arxmlmetaparser_5F_syntax_56>", "arxmlmetaparser_syntax", 759}, // at index 213
 {"<select_arxmlmetaparser_5F_syntax_56>", "arxmlmetaparser_syntax", 764}, // at index 214
 {"<select_arxmlmetaparser_5F_syntax_56>", "arxmlmetaparser_syntax", 769}, // at index 215
 {"<select_arxmlmetaparser_5F_syntax_56>", "arxmlmetaparser_syntax", 774}, // at index 216
 {"<select_arxmlmetaparser_5F_syntax_56>", "arxmlmetaparser_syntax", 779}, // at index 217
 {"<select_arxmlmetaparser_5F_syntax_56>", "arxmlmetaparser_syntax", 784}, // at index 218
 {"<select_arxmlmetaparser_5F_syntax_56>", "arxmlmetaparser_syntax", 789}, // at index 219
 {"<select_arxmlmetaparser_5F_syntax_56>", "arxmlmetaparser_syntax", 794}, // at index 220
 {"<select_arxmlmetaparser_5F_syntax_56>", "arxmlmetaparser_syntax", 799}, // at index 221
 {"<>", "", 804} // at index 222
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                 L L ( 1 )    P R O D U C T I O N    I N D E X E S                                    
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gProductionIndexes_arxmlmetaparser_grammar [223] = {
0, // index 0 : <arxmlmetaparser_start_symbol>, in file 'arxmlmetaparser_syntax.ggs', line 31
3, // index 1 : <xml_header>, in file 'arxmlmetaparser_syntax.ggs', line 61
7, // index 2 : <xsd_annotation>, in file 'arxmlmetaparser_syntax.ggs', line 75
10, // index 3 : <xsd_appinfo>, in file 'arxmlmetaparser_syntax.ggs', line 101
13, // index 4 : <xsd_attribute>, in file 'arxmlmetaparser_syntax.ggs', line 118
16, // index 5 : <xsd_attributeGroup>, in file 'arxmlmetaparser_syntax.ggs', line 191
19, // index 6 : <xsd_choice>, in file 'arxmlmetaparser_syntax.ggs', line 265
22, // index 7 : <xsd_complexType>, in file 'arxmlmetaparser_syntax.ggs', line 297
25, // index 8 : <xsd_documentation>, in file 'arxmlmetaparser_syntax.ggs', line 369
28, // index 9 : <xsd_element>, in file 'arxmlmetaparser_syntax.ggs', line 388
31, // index 10 : <xsd_enumeration>, in file 'arxmlmetaparser_syntax.ggs', line 495
36, // index 11 : <xsd_extension>, in file 'arxmlmetaparser_syntax.ggs', line 523
39, // index 12 : <xsd_group>, in file 'arxmlmetaparser_syntax.ggs', line 558
42, // index 13 : <xsd_import>, in file 'arxmlmetaparser_syntax.ggs', line 630
45, // index 14 : <xsd_restriction>, in file 'arxmlmetaparser_syntax.ggs', line 653
50, // index 15 : <xsd_schema>, in file 'arxmlmetaparser_syntax.ggs', line 753
59, // index 16 : <xsd_sequence>, in file 'arxmlmetaparser_syntax.ggs', line 810
61, // index 17 : <xsd_simpleContent>, in file 'arxmlmetaparser_syntax.ggs', line 841
63, // index 18 : <xsd_simpleType>, in file 'arxmlmetaparser_syntax.ggs', line 876
66, // index 19 : <xsd_maxLength>, in file 'arxmlmetaparser_syntax.ggs', line 942
69, // index 20 : <xsd_pattern>, in file 'arxmlmetaparser_syntax.ggs', line 967
72, // index 21 : <xsd_whiteSpace>, in file 'arxmlmetaparser_syntax.ggs', line 991
75, // index 22 : <xsd_ignore_attributes>, in file 'arxmlmetaparser_syntax.ggs', line 1011
77, // index 23 : <select_arxmlmetaparser_5F_syntax_0>, in file 'arxmlmetaparser_syntax.ggs', line 81
83, // index 24 : <select_arxmlmetaparser_5F_syntax_0>, in file 'arxmlmetaparser_syntax.ggs', line 81
85, // index 25 : <select_arxmlmetaparser_5F_syntax_1>, in file 'arxmlmetaparser_syntax.ggs', line 82
86, // index 26 : <select_arxmlmetaparser_5F_syntax_1>, in file 'arxmlmetaparser_syntax.ggs', line 82
90, // index 27 : <select_arxmlmetaparser_5F_syntax_2>, in file 'arxmlmetaparser_syntax.ggs', line 84
93, // index 28 : <select_arxmlmetaparser_5F_syntax_2>, in file 'arxmlmetaparser_syntax.ggs', line 84
96, // index 29 : <select_arxmlmetaparser_5F_syntax_3>, in file 'arxmlmetaparser_syntax.ggs', line 107
101, // index 30 : <select_arxmlmetaparser_5F_syntax_3>, in file 'arxmlmetaparser_syntax.ggs', line 107
103, // index 31 : <select_arxmlmetaparser_5F_syntax_4>, in file 'arxmlmetaparser_syntax.ggs', line 129
104, // index 32 : <select_arxmlmetaparser_5F_syntax_4>, in file 'arxmlmetaparser_syntax.ggs', line 129
109, // index 33 : <select_arxmlmetaparser_5F_syntax_4>, in file 'arxmlmetaparser_syntax.ggs', line 129
114, // index 34 : <select_arxmlmetaparser_5F_syntax_4>, in file 'arxmlmetaparser_syntax.ggs', line 129
119, // index 35 : <select_arxmlmetaparser_5F_syntax_4>, in file 'arxmlmetaparser_syntax.ggs', line 129
124, // index 36 : <select_arxmlmetaparser_5F_syntax_5>, in file 'arxmlmetaparser_syntax.ggs', line 171
130, // index 37 : <select_arxmlmetaparser_5F_syntax_5>, in file 'arxmlmetaparser_syntax.ggs', line 171
132, // index 38 : <select_arxmlmetaparser_5F_syntax_6>, in file 'arxmlmetaparser_syntax.ggs', line 172
133, // index 39 : <select_arxmlmetaparser_5F_syntax_6>, in file 'arxmlmetaparser_syntax.ggs', line 172
137, // index 40 : <select_arxmlmetaparser_5F_syntax_7>, in file 'arxmlmetaparser_syntax.ggs', line 174
140, // index 41 : <select_arxmlmetaparser_5F_syntax_7>, in file 'arxmlmetaparser_syntax.ggs', line 174
143, // index 42 : <select_arxmlmetaparser_5F_syntax_8>, in file 'arxmlmetaparser_syntax.ggs', line 199
147, // index 43 : <select_arxmlmetaparser_5F_syntax_8>, in file 'arxmlmetaparser_syntax.ggs', line 199
151, // index 44 : <select_arxmlmetaparser_5F_syntax_9>, in file 'arxmlmetaparser_syntax.ggs', line 239
157, // index 45 : <select_arxmlmetaparser_5F_syntax_9>, in file 'arxmlmetaparser_syntax.ggs', line 239
159, // index 46 : <select_arxmlmetaparser_5F_syntax_10>, in file 'arxmlmetaparser_syntax.ggs', line 240
160, // index 47 : <select_arxmlmetaparser_5F_syntax_10>, in file 'arxmlmetaparser_syntax.ggs', line 240
164, // index 48 : <select_arxmlmetaparser_5F_syntax_11>, in file 'arxmlmetaparser_syntax.ggs', line 242
167, // index 49 : <select_arxmlmetaparser_5F_syntax_11>, in file 'arxmlmetaparser_syntax.ggs', line 242
170, // index 50 : <select_arxmlmetaparser_5F_syntax_11>, in file 'arxmlmetaparser_syntax.ggs', line 242
173, // index 51 : <select_arxmlmetaparser_5F_syntax_11>, in file 'arxmlmetaparser_syntax.ggs', line 242
176, // index 52 : <select_arxmlmetaparser_5F_syntax_11>, in file 'arxmlmetaparser_syntax.ggs', line 242
179, // index 53 : <select_arxmlmetaparser_5F_syntax_12>, in file 'arxmlmetaparser_syntax.ggs', line 271
185, // index 54 : <select_arxmlmetaparser_5F_syntax_12>, in file 'arxmlmetaparser_syntax.ggs', line 271
187, // index 55 : <select_arxmlmetaparser_5F_syntax_13>, in file 'arxmlmetaparser_syntax.ggs', line 272
188, // index 56 : <select_arxmlmetaparser_5F_syntax_13>, in file 'arxmlmetaparser_syntax.ggs', line 272
192, // index 57 : <select_arxmlmetaparser_5F_syntax_14>, in file 'arxmlmetaparser_syntax.ggs', line 274
195, // index 58 : <select_arxmlmetaparser_5F_syntax_14>, in file 'arxmlmetaparser_syntax.ggs', line 274
198, // index 59 : <select_arxmlmetaparser_5F_syntax_14>, in file 'arxmlmetaparser_syntax.ggs', line 274
201, // index 60 : <select_arxmlmetaparser_5F_syntax_14>, in file 'arxmlmetaparser_syntax.ggs', line 274
204, // index 61 : <select_arxmlmetaparser_5F_syntax_14>, in file 'arxmlmetaparser_syntax.ggs', line 274
207, // index 62 : <select_arxmlmetaparser_5F_syntax_15>, in file 'arxmlmetaparser_syntax.ggs', line 306
208, // index 63 : <select_arxmlmetaparser_5F_syntax_15>, in file 'arxmlmetaparser_syntax.ggs', line 306
213, // index 64 : <select_arxmlmetaparser_5F_syntax_15>, in file 'arxmlmetaparser_syntax.ggs', line 306
218, // index 65 : <select_arxmlmetaparser_5F_syntax_15>, in file 'arxmlmetaparser_syntax.ggs', line 306
223, // index 66 : <select_arxmlmetaparser_5F_syntax_16>, in file 'arxmlmetaparser_syntax.ggs', line 339
229, // index 67 : <select_arxmlmetaparser_5F_syntax_16>, in file 'arxmlmetaparser_syntax.ggs', line 339
231, // index 68 : <select_arxmlmetaparser_5F_syntax_17>, in file 'arxmlmetaparser_syntax.ggs', line 340
232, // index 69 : <select_arxmlmetaparser_5F_syntax_17>, in file 'arxmlmetaparser_syntax.ggs', line 340
236, // index 70 : <select_arxmlmetaparser_5F_syntax_18>, in file 'arxmlmetaparser_syntax.ggs', line 342
239, // index 71 : <select_arxmlmetaparser_5F_syntax_18>, in file 'arxmlmetaparser_syntax.ggs', line 342
242, // index 72 : <select_arxmlmetaparser_5F_syntax_18>, in file 'arxmlmetaparser_syntax.ggs', line 342
245, // index 73 : <select_arxmlmetaparser_5F_syntax_18>, in file 'arxmlmetaparser_syntax.ggs', line 342
248, // index 74 : <select_arxmlmetaparser_5F_syntax_18>, in file 'arxmlmetaparser_syntax.ggs', line 342
251, // index 75 : <select_arxmlmetaparser_5F_syntax_18>, in file 'arxmlmetaparser_syntax.ggs', line 342
254, // index 76 : <select_arxmlmetaparser_5F_syntax_18>, in file 'arxmlmetaparser_syntax.ggs', line 342
257, // index 77 : <select_arxmlmetaparser_5F_syntax_19>, in file 'arxmlmetaparser_syntax.ggs', line 375
262, // index 78 : <select_arxmlmetaparser_5F_syntax_19>, in file 'arxmlmetaparser_syntax.ggs', line 375
264, // index 79 : <select_arxmlmetaparser_5F_syntax_20>, in file 'arxmlmetaparser_syntax.ggs', line 400
265, // index 80 : <select_arxmlmetaparser_5F_syntax_20>, in file 'arxmlmetaparser_syntax.ggs', line 400
270, // index 81 : <select_arxmlmetaparser_5F_syntax_20>, in file 'arxmlmetaparser_syntax.ggs', line 400
275, // index 82 : <select_arxmlmetaparser_5F_syntax_20>, in file 'arxmlmetaparser_syntax.ggs', line 400
280, // index 83 : <select_arxmlmetaparser_5F_syntax_20>, in file 'arxmlmetaparser_syntax.ggs', line 400
285, // index 84 : <select_arxmlmetaparser_5F_syntax_21>, in file 'arxmlmetaparser_syntax.ggs', line 473
291, // index 85 : <select_arxmlmetaparser_5F_syntax_21>, in file 'arxmlmetaparser_syntax.ggs', line 473
293, // index 86 : <select_arxmlmetaparser_5F_syntax_22>, in file 'arxmlmetaparser_syntax.ggs', line 474
294, // index 87 : <select_arxmlmetaparser_5F_syntax_22>, in file 'arxmlmetaparser_syntax.ggs', line 474
298, // index 88 : <select_arxmlmetaparser_5F_syntax_23>, in file 'arxmlmetaparser_syntax.ggs', line 476
301, // index 89 : <select_arxmlmetaparser_5F_syntax_23>, in file 'arxmlmetaparser_syntax.ggs', line 476
304, // index 90 : <select_arxmlmetaparser_5F_syntax_23>, in file 'arxmlmetaparser_syntax.ggs', line 476
307, // index 91 : <select_arxmlmetaparser_5F_syntax_24>, in file 'arxmlmetaparser_syntax.ggs', line 506
313, // index 92 : <select_arxmlmetaparser_5F_syntax_24>, in file 'arxmlmetaparser_syntax.ggs', line 506
315, // index 93 : <select_arxmlmetaparser_5F_syntax_25>, in file 'arxmlmetaparser_syntax.ggs', line 507
316, // index 94 : <select_arxmlmetaparser_5F_syntax_25>, in file 'arxmlmetaparser_syntax.ggs', line 507
321, // index 95 : <select_arxmlmetaparser_5F_syntax_26>, in file 'arxmlmetaparser_syntax.ggs', line 530
327, // index 96 : <select_arxmlmetaparser_5F_syntax_26>, in file 'arxmlmetaparser_syntax.ggs', line 530
329, // index 97 : <select_arxmlmetaparser_5F_syntax_27>, in file 'arxmlmetaparser_syntax.ggs', line 531
330, // index 98 : <select_arxmlmetaparser_5F_syntax_27>, in file 'arxmlmetaparser_syntax.ggs', line 531
334, // index 99 : <select_arxmlmetaparser_5F_syntax_28>, in file 'arxmlmetaparser_syntax.ggs', line 533
337, // index 100 : <select_arxmlmetaparser_5F_syntax_28>, in file 'arxmlmetaparser_syntax.ggs', line 533
340, // index 101 : <select_arxmlmetaparser_5F_syntax_28>, in file 'arxmlmetaparser_syntax.ggs', line 533
343, // index 102 : <select_arxmlmetaparser_5F_syntax_28>, in file 'arxmlmetaparser_syntax.ggs', line 533
346, // index 103 : <select_arxmlmetaparser_5F_syntax_28>, in file 'arxmlmetaparser_syntax.ggs', line 533
349, // index 104 : <select_arxmlmetaparser_5F_syntax_28>, in file 'arxmlmetaparser_syntax.ggs', line 533
352, // index 105 : <select_arxmlmetaparser_5F_syntax_29>, in file 'arxmlmetaparser_syntax.ggs', line 566
356, // index 106 : <select_arxmlmetaparser_5F_syntax_29>, in file 'arxmlmetaparser_syntax.ggs', line 566
360, // index 107 : <select_arxmlmetaparser_5F_syntax_30>, in file 'arxmlmetaparser_syntax.ggs', line 607
366, // index 108 : <select_arxmlmetaparser_5F_syntax_30>, in file 'arxmlmetaparser_syntax.ggs', line 607
368, // index 109 : <select_arxmlmetaparser_5F_syntax_31>, in file 'arxmlmetaparser_syntax.ggs', line 608
369, // index 110 : <select_arxmlmetaparser_5F_syntax_31>, in file 'arxmlmetaparser_syntax.ggs', line 608
373, // index 111 : <select_arxmlmetaparser_5F_syntax_32>, in file 'arxmlmetaparser_syntax.ggs', line 610
376, // index 112 : <select_arxmlmetaparser_5F_syntax_32>, in file 'arxmlmetaparser_syntax.ggs', line 610
379, // index 113 : <select_arxmlmetaparser_5F_syntax_32>, in file 'arxmlmetaparser_syntax.ggs', line 610
382, // index 114 : <select_arxmlmetaparser_5F_syntax_32>, in file 'arxmlmetaparser_syntax.ggs', line 610
385, // index 115 : <select_arxmlmetaparser_5F_syntax_33>, in file 'arxmlmetaparser_syntax.ggs', line 636
391, // index 116 : <select_arxmlmetaparser_5F_syntax_33>, in file 'arxmlmetaparser_syntax.ggs', line 636
393, // index 117 : <select_arxmlmetaparser_5F_syntax_34>, in file 'arxmlmetaparser_syntax.ggs', line 637
394, // index 118 : <select_arxmlmetaparser_5F_syntax_34>, in file 'arxmlmetaparser_syntax.ggs', line 637
399, // index 119 : <select_arxmlmetaparser_5F_syntax_35>, in file 'arxmlmetaparser_syntax.ggs', line 681
405, // index 120 : <select_arxmlmetaparser_5F_syntax_35>, in file 'arxmlmetaparser_syntax.ggs', line 681
407, // index 121 : <select_arxmlmetaparser_5F_syntax_36>, in file 'arxmlmetaparser_syntax.ggs', line 682
408, // index 122 : <select_arxmlmetaparser_5F_syntax_36>, in file 'arxmlmetaparser_syntax.ggs', line 682
412, // index 123 : <select_arxmlmetaparser_5F_syntax_37>, in file 'arxmlmetaparser_syntax.ggs', line 684
415, // index 124 : <select_arxmlmetaparser_5F_syntax_37>, in file 'arxmlmetaparser_syntax.ggs', line 684
419, // index 125 : <select_arxmlmetaparser_5F_syntax_37>, in file 'arxmlmetaparser_syntax.ggs', line 684
423, // index 126 : <select_arxmlmetaparser_5F_syntax_37>, in file 'arxmlmetaparser_syntax.ggs', line 684
427, // index 127 : <select_arxmlmetaparser_5F_syntax_37>, in file 'arxmlmetaparser_syntax.ggs', line 684
431, // index 128 : <select_arxmlmetaparser_5F_syntax_37>, in file 'arxmlmetaparser_syntax.ggs', line 684
435, // index 129 : <select_arxmlmetaparser_5F_syntax_37>, in file 'arxmlmetaparser_syntax.ggs', line 684
438, // index 130 : <select_arxmlmetaparser_5F_syntax_37>, in file 'arxmlmetaparser_syntax.ggs', line 684
441, // index 131 : <select_arxmlmetaparser_5F_syntax_37>, in file 'arxmlmetaparser_syntax.ggs', line 684
444, // index 132 : <select_arxmlmetaparser_5F_syntax_37>, in file 'arxmlmetaparser_syntax.ggs', line 684
447, // index 133 : <select_arxmlmetaparser_5F_syntax_37>, in file 'arxmlmetaparser_syntax.ggs', line 684
450, // index 134 : <select_arxmlmetaparser_5F_syntax_38>, in file 'arxmlmetaparser_syntax.ggs', line 779
451, // index 135 : <select_arxmlmetaparser_5F_syntax_38>, in file 'arxmlmetaparser_syntax.ggs', line 779
455, // index 136 : <select_arxmlmetaparser_5F_syntax_39>, in file 'arxmlmetaparser_syntax.ggs', line 781
458, // index 137 : <select_arxmlmetaparser_5F_syntax_39>, in file 'arxmlmetaparser_syntax.ggs', line 781
461, // index 138 : <select_arxmlmetaparser_5F_syntax_39>, in file 'arxmlmetaparser_syntax.ggs', line 781
464, // index 139 : <select_arxmlmetaparser_5F_syntax_39>, in file 'arxmlmetaparser_syntax.ggs', line 781
467, // index 140 : <select_arxmlmetaparser_5F_syntax_39>, in file 'arxmlmetaparser_syntax.ggs', line 781
470, // index 141 : <select_arxmlmetaparser_5F_syntax_39>, in file 'arxmlmetaparser_syntax.ggs', line 781
473, // index 142 : <select_arxmlmetaparser_5F_syntax_39>, in file 'arxmlmetaparser_syntax.ggs', line 781
476, // index 143 : <select_arxmlmetaparser_5F_syntax_39>, in file 'arxmlmetaparser_syntax.ggs', line 781
479, // index 144 : <select_arxmlmetaparser_5F_syntax_40>, in file 'arxmlmetaparser_syntax.ggs', line 815
485, // index 145 : <select_arxmlmetaparser_5F_syntax_40>, in file 'arxmlmetaparser_syntax.ggs', line 815
487, // index 146 : <select_arxmlmetaparser_5F_syntax_41>, in file 'arxmlmetaparser_syntax.ggs', line 816
488, // index 147 : <select_arxmlmetaparser_5F_syntax_41>, in file 'arxmlmetaparser_syntax.ggs', line 816
492, // index 148 : <select_arxmlmetaparser_5F_syntax_42>, in file 'arxmlmetaparser_syntax.ggs', line 818
495, // index 149 : <select_arxmlmetaparser_5F_syntax_42>, in file 'arxmlmetaparser_syntax.ggs', line 818
498, // index 150 : <select_arxmlmetaparser_5F_syntax_42>, in file 'arxmlmetaparser_syntax.ggs', line 818
501, // index 151 : <select_arxmlmetaparser_5F_syntax_42>, in file 'arxmlmetaparser_syntax.ggs', line 818
504, // index 152 : <select_arxmlmetaparser_5F_syntax_42>, in file 'arxmlmetaparser_syntax.ggs', line 818
507, // index 153 : <select_arxmlmetaparser_5F_syntax_43>, in file 'arxmlmetaparser_syntax.ggs', line 854
513, // index 154 : <select_arxmlmetaparser_5F_syntax_43>, in file 'arxmlmetaparser_syntax.ggs', line 854
515, // index 155 : <select_arxmlmetaparser_5F_syntax_44>, in file 'arxmlmetaparser_syntax.ggs', line 855
516, // index 156 : <select_arxmlmetaparser_5F_syntax_44>, in file 'arxmlmetaparser_syntax.ggs', line 855
520, // index 157 : <select_arxmlmetaparser_5F_syntax_45>, in file 'arxmlmetaparser_syntax.ggs', line 857
523, // index 158 : <select_arxmlmetaparser_5F_syntax_45>, in file 'arxmlmetaparser_syntax.ggs', line 857
526, // index 159 : <select_arxmlmetaparser_5F_syntax_46>, in file 'arxmlmetaparser_syntax.ggs', line 885
527, // index 160 : <select_arxmlmetaparser_5F_syntax_46>, in file 'arxmlmetaparser_syntax.ggs', line 885
532, // index 161 : <select_arxmlmetaparser_5F_syntax_47>, in file 'arxmlmetaparser_syntax.ggs', line 918
538, // index 162 : <select_arxmlmetaparser_5F_syntax_47>, in file 'arxmlmetaparser_syntax.ggs', line 918
540, // index 163 : <select_arxmlmetaparser_5F_syntax_48>, in file 'arxmlmetaparser_syntax.ggs', line 919
541, // index 164 : <select_arxmlmetaparser_5F_syntax_48>, in file 'arxmlmetaparser_syntax.ggs', line 919
545, // index 165 : <select_arxmlmetaparser_5F_syntax_49>, in file 'arxmlmetaparser_syntax.ggs', line 921
548, // index 166 : <select_arxmlmetaparser_5F_syntax_49>, in file 'arxmlmetaparser_syntax.ggs', line 921
551, // index 167 : <select_arxmlmetaparser_5F_syntax_50>, in file 'arxmlmetaparser_syntax.ggs', line 948
557, // index 168 : <select_arxmlmetaparser_5F_syntax_50>, in file 'arxmlmetaparser_syntax.ggs', line 948
559, // index 169 : <select_arxmlmetaparser_5F_syntax_51>, in file 'arxmlmetaparser_syntax.ggs', line 949
560, // index 170 : <select_arxmlmetaparser_5F_syntax_51>, in file 'arxmlmetaparser_syntax.ggs', line 949
565, // index 171 : <select_arxmlmetaparser_5F_syntax_52>, in file 'arxmlmetaparser_syntax.ggs', line 973
571, // index 172 : <select_arxmlmetaparser_5F_syntax_52>, in file 'arxmlmetaparser_syntax.ggs', line 973
573, // index 173 : <select_arxmlmetaparser_5F_syntax_53>, in file 'arxmlmetaparser_syntax.ggs', line 974
574, // index 174 : <select_arxmlmetaparser_5F_syntax_53>, in file 'arxmlmetaparser_syntax.ggs', line 974
579, // index 175 : <select_arxmlmetaparser_5F_syntax_54>, in file 'arxmlmetaparser_syntax.ggs', line 997
585, // index 176 : <select_arxmlmetaparser_5F_syntax_54>, in file 'arxmlmetaparser_syntax.ggs', line 997
587, // index 177 : <select_arxmlmetaparser_5F_syntax_55>, in file 'arxmlmetaparser_syntax.ggs', line 998
588, // index 178 : <select_arxmlmetaparser_5F_syntax_55>, in file 'arxmlmetaparser_syntax.ggs', line 998
593, // index 179 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
594, // index 180 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
599, // index 181 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
604, // index 182 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
609, // index 183 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
614, // index 184 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
619, // index 185 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
624, // index 186 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
629, // index 187 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
634, // index 188 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
639, // index 189 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
644, // index 190 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
649, // index 191 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
654, // index 192 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
659, // index 193 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
664, // index 194 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
669, // index 195 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
674, // index 196 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
679, // index 197 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
684, // index 198 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
689, // index 199 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
694, // index 200 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
699, // index 201 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
704, // index 202 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
709, // index 203 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
714, // index 204 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
719, // index 205 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
724, // index 206 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
729, // index 207 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
734, // index 208 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
739, // index 209 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
744, // index 210 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
749, // index 211 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
754, // index 212 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
759, // index 213 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
764, // index 214 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
769, // index 215 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
774, // index 216 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
779, // index 217 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
784, // index 218 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
789, // index 219 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
794, // index 220 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
799, // index 221 : <select_arxmlmetaparser_5F_syntax_56>, in file 'arxmlmetaparser_syntax.ggs', line 1013
804 // index 222 : <>, in file '.ggs', line 0
} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                           L L ( 1 )    F I R S T    P R O D U C T I O N    I N D E X E S                             
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gFirstProductionIndexes_arxmlmetaparser_grammar [82] = {
0, // at 0 : <arxmlmetaparser_start_symbol>
1, // at 1 : <xml_header>
2, // at 2 : <xsd_annotation>
3, // at 3 : <xsd_appinfo>
4, // at 4 : <xsd_attribute>
5, // at 5 : <xsd_attributeGroup>
6, // at 6 : <xsd_choice>
7, // at 7 : <xsd_complexType>
8, // at 8 : <xsd_documentation>
9, // at 9 : <xsd_element>
10, // at 10 : <xsd_enumeration>
11, // at 11 : <xsd_extension>
12, // at 12 : <xsd_group>
13, // at 13 : <xsd_import>
14, // at 14 : <xsd_restriction>
15, // at 15 : <xsd_schema>
16, // at 16 : <xsd_sequence>
17, // at 17 : <xsd_simpleContent>
18, // at 18 : <xsd_simpleType>
19, // at 19 : <xsd_maxLength>
20, // at 20 : <xsd_pattern>
21, // at 21 : <xsd_whiteSpace>
22, // at 22 : <xsd_ignore_attributes>
23, // at 23 : <select_arxmlmetaparser_5F_syntax_0>
25, // at 24 : <select_arxmlmetaparser_5F_syntax_1>
27, // at 25 : <select_arxmlmetaparser_5F_syntax_2>
29, // at 26 : <select_arxmlmetaparser_5F_syntax_3>
31, // at 27 : <select_arxmlmetaparser_5F_syntax_4>
36, // at 28 : <select_arxmlmetaparser_5F_syntax_5>
38, // at 29 : <select_arxmlmetaparser_5F_syntax_6>
40, // at 30 : <select_arxmlmetaparser_5F_syntax_7>
42, // at 31 : <select_arxmlmetaparser_5F_syntax_8>
44, // at 32 : <select_arxmlmetaparser_5F_syntax_9>
46, // at 33 : <select_arxmlmetaparser_5F_syntax_10>
48, // at 34 : <select_arxmlmetaparser_5F_syntax_11>
53, // at 35 : <select_arxmlmetaparser_5F_syntax_12>
55, // at 36 : <select_arxmlmetaparser_5F_syntax_13>
57, // at 37 : <select_arxmlmetaparser_5F_syntax_14>
62, // at 38 : <select_arxmlmetaparser_5F_syntax_15>
66, // at 39 : <select_arxmlmetaparser_5F_syntax_16>
68, // at 40 : <select_arxmlmetaparser_5F_syntax_17>
70, // at 41 : <select_arxmlmetaparser_5F_syntax_18>
77, // at 42 : <select_arxmlmetaparser_5F_syntax_19>
79, // at 43 : <select_arxmlmetaparser_5F_syntax_20>
84, // at 44 : <select_arxmlmetaparser_5F_syntax_21>
86, // at 45 : <select_arxmlmetaparser_5F_syntax_22>
88, // at 46 : <select_arxmlmetaparser_5F_syntax_23>
91, // at 47 : <select_arxmlmetaparser_5F_syntax_24>
93, // at 48 : <select_arxmlmetaparser_5F_syntax_25>
95, // at 49 : <select_arxmlmetaparser_5F_syntax_26>
97, // at 50 : <select_arxmlmetaparser_5F_syntax_27>
99, // at 51 : <select_arxmlmetaparser_5F_syntax_28>
105, // at 52 : <select_arxmlmetaparser_5F_syntax_29>
107, // at 53 : <select_arxmlmetaparser_5F_syntax_30>
109, // at 54 : <select_arxmlmetaparser_5F_syntax_31>
111, // at 55 : <select_arxmlmetaparser_5F_syntax_32>
115, // at 56 : <select_arxmlmetaparser_5F_syntax_33>
117, // at 57 : <select_arxmlmetaparser_5F_syntax_34>
119, // at 58 : <select_arxmlmetaparser_5F_syntax_35>
121, // at 59 : <select_arxmlmetaparser_5F_syntax_36>
123, // at 60 : <select_arxmlmetaparser_5F_syntax_37>
134, // at 61 : <select_arxmlmetaparser_5F_syntax_38>
136, // at 62 : <select_arxmlmetaparser_5F_syntax_39>
144, // at 63 : <select_arxmlmetaparser_5F_syntax_40>
146, // at 64 : <select_arxmlmetaparser_5F_syntax_41>
148, // at 65 : <select_arxmlmetaparser_5F_syntax_42>
153, // at 66 : <select_arxmlmetaparser_5F_syntax_43>
155, // at 67 : <select_arxmlmetaparser_5F_syntax_44>
157, // at 68 : <select_arxmlmetaparser_5F_syntax_45>
159, // at 69 : <select_arxmlmetaparser_5F_syntax_46>
161, // at 70 : <select_arxmlmetaparser_5F_syntax_47>
163, // at 71 : <select_arxmlmetaparser_5F_syntax_48>
165, // at 72 : <select_arxmlmetaparser_5F_syntax_49>
167, // at 73 : <select_arxmlmetaparser_5F_syntax_50>
169, // at 74 : <select_arxmlmetaparser_5F_syntax_51>
171, // at 75 : <select_arxmlmetaparser_5F_syntax_52>
173, // at 76 : <select_arxmlmetaparser_5F_syntax_53>
175, // at 77 : <select_arxmlmetaparser_5F_syntax_54>
177, // at 78 : <select_arxmlmetaparser_5F_syntax_55>
179, // at 79 : <select_arxmlmetaparser_5F_syntax_56>
222, // at 80 : <>
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                    L L ( 1 )    D E C I S I O N    T A B L E S                                       
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gDecision_arxmlmetaparser_grammar [] = {
// At index 0 : <arxmlmetaparser_start_symbol> only one production, no choice
  -1,
// At index 1 : <xml_header> only one production, no choice
  -1,
// At index 2 : <xsd_annotation> only one production, no choice
  -1,
// At index 3 : <xsd_appinfo> only one production, no choice
  -1,
// At index 4 : <xsd_attribute> only one production, no choice
  -1,
// At index 5 : <xsd_attributeGroup> only one production, no choice
  -1,
// At index 6 : <xsd_choice> only one production, no choice
  -1,
// At index 7 : <xsd_complexType> only one production, no choice
  -1,
// At index 8 : <xsd_documentation> only one production, no choice
  -1,
// At index 9 : <xsd_element> only one production, no choice
  -1,
// At index 10 : <xsd_enumeration> only one production, no choice
  -1,
// At index 11 : <xsd_extension> only one production, no choice
  -1,
// At index 12 : <xsd_group> only one production, no choice
  -1,
// At index 13 : <xsd_import> only one production, no choice
  -1,
// At index 14 : <xsd_restriction> only one production, no choice
  -1,
// At index 15 : <xsd_schema> only one production, no choice
  -1,
// At index 16 : <xsd_sequence> only one production, no choice
  -1,
// At index 17 : <xsd_simpleContent> only one production, no choice
  -1,
// At index 18 : <xsd_simpleType> only one production, no choice
  -1,
// At index 19 : <xsd_maxLength> only one production, no choice
  -1,
// At index 20 : <xsd_pattern> only one production, no choice
  -1,
// At index 21 : <xsd_whiteSpace> only one production, no choice
  -1,
// At index 22 : <xsd_ignore_attributes> only one production, no choice
  -1,
//---- Added non terminal symbols from 'select' and 'repeat' instructions
// At index 23 : <select_arxmlmetaparser_5F_syntax_0>
C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_, -1, // Choice 1
C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_, -1, // Choice 2
  -1,
// At index 28 : <select_arxmlmetaparser_5F_syntax_1>
C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_, -1, // Choice 1
C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_, -1, // Choice 2
  -1,
// At index 33 : <select_arxmlmetaparser_5F_syntax_2>
C_Lexique_arxmlmetaparser_5F_scanner::kToken_appinfo, -1, // Choice 1
C_Lexique_arxmlmetaparser_5F_scanner::kToken_documentation, -1, // Choice 2
  -1,
// At index 38 : <select_arxmlmetaparser_5F_syntax_3>
C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_, -1, // Choice 1
C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_, -1, // Choice 2
  -1,
// At index 43 : <select_arxmlmetaparser_5F_syntax_4>
C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_, C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_, -1, // Choice 1
C_Lexique_arxmlmetaparser_5F_scanner::kToken_ref, -1, // Choice 2
C_Lexique_arxmlmetaparser_5F_scanner::kToken_type, -1, // Choice 3
C_Lexique_arxmlmetaparser_5F_scanner::kToken_name, -1, // Choice 4
C_Lexique_arxmlmetaparser_5F_scanner::kToken_use, -1, // Choice 5
  -1,
// At index 55 : <select_arxmlmetaparser_5F_syntax_5>
C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_, -1, // Choice 1
C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_, -1, // Choice 2
  -1,
// At index 60 : <select_arxmlmetaparser_5F_syntax_6>
C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_, -1, // Choice 1
C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_, -1, // Choice 2
  -1,
// At index 65 : <select_arxmlmetaparser_5F_syntax_7>
C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation, -1, // Choice 1
C_Lexique_arxmlmetaparser_5F_scanner::kToken_simpleType, -1, // Choice 2
  -1,
// At index 70 : <select_arxmlmetaparser_5F_syntax_8>
C_Lexique_arxmlmetaparser_5F_scanner::kToken_name, -1, // Choice 1
C_Lexique_arxmlmetaparser_5F_scanner::kToken_ref, -1, // Choice 2
  -1,
// At index 75 : <select_arxmlmetaparser_5F_syntax_9>
C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_, -1, // Choice 1
C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_, -1, // Choice 2
  -1,
// At index 80 : <select_arxmlmetaparser_5F_syntax_10>
C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_, -1, // Choice 1
C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_, -1, // Choice 2
  -1,
// At index 85 : <select_arxmlmetaparser_5F_syntax_11>
C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation, -1, // Choice 1
C_Lexique_arxmlmetaparser_5F_scanner::kToken_attribute, -1, // Choice 2
C_Lexique_arxmlmetaparser_5F_scanner::kToken_attributeGroup, -1, // Choice 3
C_Lexique_arxmlmetaparser_5F_scanner::kToken_choice, -1, // Choice 4
C_Lexique_arxmlmetaparser_5F_scanner::kToken_sequence, -1, // Choice 5
  -1,
// At index 96 : <select_arxmlmetaparser_5F_syntax_12>
C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_, -1, // Choice 1
C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_, -1, // Choice 2
  -1,
// At index 101 : <select_arxmlmetaparser_5F_syntax_13>
C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_, -1, // Choice 1
C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_, -1, // Choice 2
  -1,
// At index 106 : <select_arxmlmetaparser_5F_syntax_14>
C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation, -1, // Choice 1
C_Lexique_arxmlmetaparser_5F_scanner::kToken_choice, -1, // Choice 2
C_Lexique_arxmlmetaparser_5F_scanner::kToken_sequence, -1, // Choice 3
C_Lexique_arxmlmetaparser_5F_scanner::kToken_element, -1, // Choice 4
C_Lexique_arxmlmetaparser_5F_scanner::kToken_group, -1, // Choice 5
  -1,
// At index 117 : <select_arxmlmetaparser_5F_syntax_15>
C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_, C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_, -1, // Choice 1
C_Lexique_arxmlmetaparser_5F_scanner::kToken_abstract, -1, // Choice 2
C_Lexique_arxmlmetaparser_5F_scanner::kToken_mixed, -1, // Choice 3
C_Lexique_arxmlmetaparser_5F_scanner::kToken_name, -1, // Choice 4
  -1,
// At index 127 : <select_arxmlmetaparser_5F_syntax_16>
C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_, -1, // Choice 1
C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_, -1, // Choice 2
  -1,
// At index 132 : <select_arxmlmetaparser_5F_syntax_17>
C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_, -1, // Choice 1
C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_, -1, // Choice 2
  -1,
// At index 137 : <select_arxmlmetaparser_5F_syntax_18>
C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation, -1, // Choice 1
C_Lexique_arxmlmetaparser_5F_scanner::kToken_attribute, -1, // Choice 2
C_Lexique_arxmlmetaparser_5F_scanner::kToken_attributeGroup, -1, // Choice 3
C_Lexique_arxmlmetaparser_5F_scanner::kToken_choice, -1, // Choice 4
C_Lexique_arxmlmetaparser_5F_scanner::kToken_sequence, -1, // Choice 5
C_Lexique_arxmlmetaparser_5F_scanner::kToken_group, -1, // Choice 6
C_Lexique_arxmlmetaparser_5F_scanner::kToken_simpleContent, -1, // Choice 7
  -1,
// At index 152 : <select_arxmlmetaparser_5F_syntax_19>
C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_, -1, // Choice 1
C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_, -1, // Choice 2
  -1,
// At index 157 : <select_arxmlmetaparser_5F_syntax_20>
C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_, C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_, -1, // Choice 1
C_Lexique_arxmlmetaparser_5F_scanner::kToken_maxOccurs, -1, // Choice 2
C_Lexique_arxmlmetaparser_5F_scanner::kToken_minOccurs, -1, // Choice 3
C_Lexique_arxmlmetaparser_5F_scanner::kToken_type, -1, // Choice 4
C_Lexique_arxmlmetaparser_5F_scanner::kToken_name, -1, // Choice 5
  -1,
// At index 169 : <select_arxmlmetaparser_5F_syntax_21>
C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_, -1, // Choice 1
C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_, -1, // Choice 2
  -1,
// At index 174 : <select_arxmlmetaparser_5F_syntax_22>
C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_, -1, // Choice 1
C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_, -1, // Choice 2
  -1,
// At index 179 : <select_arxmlmetaparser_5F_syntax_23>
C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation, -1, // Choice 1
C_Lexique_arxmlmetaparser_5F_scanner::kToken_complexType, -1, // Choice 2
C_Lexique_arxmlmetaparser_5F_scanner::kToken_simpleType, -1, // Choice 3
  -1,
// At index 186 : <select_arxmlmetaparser_5F_syntax_24>
C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_, -1, // Choice 1
C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_, -1, // Choice 2
  -1,
// At index 191 : <select_arxmlmetaparser_5F_syntax_25>
C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_, -1, // Choice 1
C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_, -1, // Choice 2
  -1,
// At index 196 : <select_arxmlmetaparser_5F_syntax_26>
C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_, -1, // Choice 1
C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_, -1, // Choice 2
  -1,
// At index 201 : <select_arxmlmetaparser_5F_syntax_27>
C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_, -1, // Choice 1
C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_, -1, // Choice 2
  -1,
// At index 206 : <select_arxmlmetaparser_5F_syntax_28>
C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation, -1, // Choice 1
C_Lexique_arxmlmetaparser_5F_scanner::kToken_attribute, -1, // Choice 2
C_Lexique_arxmlmetaparser_5F_scanner::kToken_attributeGroup, -1, // Choice 3
C_Lexique_arxmlmetaparser_5F_scanner::kToken_choice, -1, // Choice 4
C_Lexique_arxmlmetaparser_5F_scanner::kToken_sequence, -1, // Choice 5
C_Lexique_arxmlmetaparser_5F_scanner::kToken_group, -1, // Choice 6
  -1,
// At index 219 : <select_arxmlmetaparser_5F_syntax_29>
C_Lexique_arxmlmetaparser_5F_scanner::kToken_name, -1, // Choice 1
C_Lexique_arxmlmetaparser_5F_scanner::kToken_ref, -1, // Choice 2
  -1,
// At index 224 : <select_arxmlmetaparser_5F_syntax_30>
C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_, -1, // Choice 1
C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_, -1, // Choice 2
  -1,
// At index 229 : <select_arxmlmetaparser_5F_syntax_31>
C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_, -1, // Choice 1
C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_, -1, // Choice 2
  -1,
// At index 234 : <select_arxmlmetaparser_5F_syntax_32>
C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation, -1, // Choice 1
C_Lexique_arxmlmetaparser_5F_scanner::kToken_choice, -1, // Choice 2
C_Lexique_arxmlmetaparser_5F_scanner::kToken_sequence, -1, // Choice 3
C_Lexique_arxmlmetaparser_5F_scanner::kToken_element, -1, // Choice 4
  -1,
// At index 243 : <select_arxmlmetaparser_5F_syntax_33>
C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_, -1, // Choice 1
C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_, -1, // Choice 2
  -1,
// At index 248 : <select_arxmlmetaparser_5F_syntax_34>
C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_, -1, // Choice 1
C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_, -1, // Choice 2
  -1,
// At index 253 : <select_arxmlmetaparser_5F_syntax_35>
C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_, -1, // Choice 1
C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_, -1, // Choice 2
  -1,
// At index 258 : <select_arxmlmetaparser_5F_syntax_36>
C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_, -1, // Choice 1
C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_, -1, // Choice 2
  -1,
// At index 263 : <select_arxmlmetaparser_5F_syntax_37>
C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation, -1, // Choice 1
C_Lexique_arxmlmetaparser_5F_scanner::kToken_attribute, -1, // Choice 2
C_Lexique_arxmlmetaparser_5F_scanner::kToken_attributeGroup, -1, // Choice 3
C_Lexique_arxmlmetaparser_5F_scanner::kToken_choice, -1, // Choice 4
C_Lexique_arxmlmetaparser_5F_scanner::kToken_sequence, -1, // Choice 5
C_Lexique_arxmlmetaparser_5F_scanner::kToken_group, -1, // Choice 6
C_Lexique_arxmlmetaparser_5F_scanner::kToken_simpleType, -1, // Choice 7
C_Lexique_arxmlmetaparser_5F_scanner::kToken_whiteSpace, -1, // Choice 8
C_Lexique_arxmlmetaparser_5F_scanner::kToken_maxLength, -1, // Choice 9
C_Lexique_arxmlmetaparser_5F_scanner::kToken_pattern, -1, // Choice 10
C_Lexique_arxmlmetaparser_5F_scanner::kToken_enumeration, -1, // Choice 11
  -1,
// At index 286 : <select_arxmlmetaparser_5F_syntax_38>
C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_, -1, // Choice 1
C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_, -1, // Choice 2
  -1,
// At index 291 : <select_arxmlmetaparser_5F_syntax_39>
C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation, -1, // Choice 1
C_Lexique_arxmlmetaparser_5F_scanner::kToken_attribute, -1, // Choice 2
C_Lexique_arxmlmetaparser_5F_scanner::kToken_attributeGroup, -1, // Choice 3
C_Lexique_arxmlmetaparser_5F_scanner::kToken_complexType, -1, // Choice 4
C_Lexique_arxmlmetaparser_5F_scanner::kToken_element, -1, // Choice 5
C_Lexique_arxmlmetaparser_5F_scanner::kToken_group, -1, // Choice 6
C_Lexique_arxmlmetaparser_5F_scanner::kToken_import, -1, // Choice 7
C_Lexique_arxmlmetaparser_5F_scanner::kToken_simpleType, -1, // Choice 8
  -1,
// At index 308 : <select_arxmlmetaparser_5F_syntax_40>
C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_, -1, // Choice 1
C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_, -1, // Choice 2
  -1,
// At index 313 : <select_arxmlmetaparser_5F_syntax_41>
C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_, -1, // Choice 1
C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_, -1, // Choice 2
  -1,
// At index 318 : <select_arxmlmetaparser_5F_syntax_42>
C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation, -1, // Choice 1
C_Lexique_arxmlmetaparser_5F_scanner::kToken_choice, -1, // Choice 2
C_Lexique_arxmlmetaparser_5F_scanner::kToken_sequence, -1, // Choice 3
C_Lexique_arxmlmetaparser_5F_scanner::kToken_element, -1, // Choice 4
C_Lexique_arxmlmetaparser_5F_scanner::kToken_group, -1, // Choice 5
  -1,
// At index 329 : <select_arxmlmetaparser_5F_syntax_43>
C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_, -1, // Choice 1
C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_, -1, // Choice 2
  -1,
// At index 334 : <select_arxmlmetaparser_5F_syntax_44>
C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_, -1, // Choice 1
C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_, -1, // Choice 2
  -1,
// At index 339 : <select_arxmlmetaparser_5F_syntax_45>
C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation, -1, // Choice 1
C_Lexique_arxmlmetaparser_5F_scanner::kToken_extension, -1, // Choice 2
  -1,
// At index 344 : <select_arxmlmetaparser_5F_syntax_46>
C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_, C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_, -1, // Choice 1
C_Lexique_arxmlmetaparser_5F_scanner::kToken_name, -1, // Choice 2
  -1,
// At index 350 : <select_arxmlmetaparser_5F_syntax_47>
C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_, -1, // Choice 1
C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_, -1, // Choice 2
  -1,
// At index 355 : <select_arxmlmetaparser_5F_syntax_48>
C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_, -1, // Choice 1
C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_, -1, // Choice 2
  -1,
// At index 360 : <select_arxmlmetaparser_5F_syntax_49>
C_Lexique_arxmlmetaparser_5F_scanner::kToken_annotation, -1, // Choice 1
C_Lexique_arxmlmetaparser_5F_scanner::kToken_restriction, -1, // Choice 2
  -1,
// At index 365 : <select_arxmlmetaparser_5F_syntax_50>
C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_, -1, // Choice 1
C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_, -1, // Choice 2
  -1,
// At index 370 : <select_arxmlmetaparser_5F_syntax_51>
C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_, -1, // Choice 1
C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_, -1, // Choice 2
  -1,
// At index 375 : <select_arxmlmetaparser_5F_syntax_52>
C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_, -1, // Choice 1
C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_, -1, // Choice 2
  -1,
// At index 380 : <select_arxmlmetaparser_5F_syntax_53>
C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_, -1, // Choice 1
C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_, -1, // Choice 2
  -1,
// At index 385 : <select_arxmlmetaparser_5F_syntax_54>
C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_, -1, // Choice 1
C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_, -1, // Choice 2
  -1,
// At index 390 : <select_arxmlmetaparser_5F_syntax_55>
C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C__2F_xsd_3A_, -1, // Choice 1
C_Lexique_arxmlmetaparser_5F_scanner::kToken__3C_xsd_3A_, -1, // Choice 2
  -1,
// At index 395 : <select_arxmlmetaparser_5F_syntax_56>
C_Lexique_arxmlmetaparser_5F_scanner::kToken__3F__3E_, C_Lexique_arxmlmetaparser_5F_scanner::kToken__3E_, C_Lexique_arxmlmetaparser_5F_scanner::kToken__2F__3E_, -1, // Choice 1
C_Lexique_arxmlmetaparser_5F_scanner::kToken_abstract, -1, // Choice 2
C_Lexique_arxmlmetaparser_5F_scanner::kToken_attributeFormDefault, -1, // Choice 3
C_Lexique_arxmlmetaparser_5F_scanner::kToken_attributeRef, -1, // Choice 4
C_Lexique_arxmlmetaparser_5F_scanner::kToken_base, -1, // Choice 5
C_Lexique_arxmlmetaparser_5F_scanner::kToken_category, -1, // Choice 6
C_Lexique_arxmlmetaparser_5F_scanner::kToken_CATEGORY, -1, // Choice 7
C_Lexique_arxmlmetaparser_5F_scanner::kToken_color, -1, // Choice 8
C_Lexique_arxmlmetaparser_5F_scanner::kToken_customType, -1, // Choice 9
C_Lexique_arxmlmetaparser_5F_scanner::kToken_elementFormDefault, -1, // Choice 10
C_Lexique_arxmlmetaparser_5F_scanner::kToken_encoding, -1, // Choice 11
C_Lexique_arxmlmetaparser_5F_scanner::kToken_enforceMinMultiplicity, -1, // Choice 12
C_Lexique_arxmlmetaparser_5F_scanner::kToken_globalElement, -1, // Choice 13
C_Lexique_arxmlmetaparser_5F_scanner::kToken_id, -1, // Choice 14
C_Lexique_arxmlmetaparser_5F_scanner::kToken_latestBindingTime, -1, // Choice 15
C_Lexique_arxmlmetaparser_5F_scanner::kToken_maxOccurs, -1, // Choice 16
C_Lexique_arxmlmetaparser_5F_scanner::kToken_minOccurs, -1, // Choice 17
C_Lexique_arxmlmetaparser_5F_scanner::kToken_mixed, -1, // Choice 18
C_Lexique_arxmlmetaparser_5F_scanner::kToken_name, -1, // Choice 19
C_Lexique_arxmlmetaparser_5F_scanner::kToken_namePlural, -1, // Choice 20
C_Lexique_arxmlmetaparser_5F_scanner::kToken_namespace, -1, // Choice 21
C_Lexique_arxmlmetaparser_5F_scanner::kToken_noteType, -1, // Choice 22
C_Lexique_arxmlmetaparser_5F_scanner::kToken_nsPrefix, -1, // Choice 23
C_Lexique_arxmlmetaparser_5F_scanner::kToken_qualifiedName, -1, // Choice 24
C_Lexique_arxmlmetaparser_5F_scanner::kToken_recommendedPackage, -1, // Choice 25
C_Lexique_arxmlmetaparser_5F_scanner::kToken_ref, -1, // Choice 26
C_Lexique_arxmlmetaparser_5F_scanner::kToken_roleElement, -1, // Choice 27
C_Lexique_arxmlmetaparser_5F_scanner::kToken_roleWrapperElement, -1, // Choice 28
C_Lexique_arxmlmetaparser_5F_scanner::kToken_schemaLocation, -1, // Choice 29
C_Lexique_arxmlmetaparser_5F_scanner::kToken_sequenceOffset, -1, // Choice 30
C_Lexique_arxmlmetaparser_5F_scanner::kToken_source, -1, // Choice 31
C_Lexique_arxmlmetaparser_5F_scanner::kToken_Splitkey, -1, // Choice 32
C_Lexique_arxmlmetaparser_5F_scanner::kToken_Status, -1, // Choice 33
C_Lexique_arxmlmetaparser_5F_scanner::kToken_StatusRevisionBegin, -1, // Choice 34
C_Lexique_arxmlmetaparser_5F_scanner::kToken_targetNamespace, -1, // Choice 35
C_Lexique_arxmlmetaparser_5F_scanner::kToken_type, -1, // Choice 36
C_Lexique_arxmlmetaparser_5F_scanner::kToken_typeElement, -1, // Choice 37
C_Lexique_arxmlmetaparser_5F_scanner::kToken_typeWrapperElement, -1, // Choice 38
C_Lexique_arxmlmetaparser_5F_scanner::kToken_use, -1, // Choice 39
C_Lexique_arxmlmetaparser_5F_scanner::kToken_value, -1, // Choice 40
C_Lexique_arxmlmetaparser_5F_scanner::kToken_version, -1, // Choice 41
C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlns_3A_AR, -1, // Choice 42
C_Lexique_arxmlmetaparser_5F_scanner::kToken_xmlns_3A_xsd, -1, // Choice 43
  -1,
// At index 484 : <> only one production, no choice
  -1,
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                            L L ( 1 )    D E C I S I O N    T A B L E S    I N D E X E S                              
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

static const int16_t gDecisionIndexes_arxmlmetaparser_grammar [82] = {
0, // at 0 : <arxmlmetaparser_start_symbol>
1, // at 1 : <xml_header>
2, // at 2 : <xsd_annotation>
3, // at 3 : <xsd_appinfo>
4, // at 4 : <xsd_attribute>
5, // at 5 : <xsd_attributeGroup>
6, // at 6 : <xsd_choice>
7, // at 7 : <xsd_complexType>
8, // at 8 : <xsd_documentation>
9, // at 9 : <xsd_element>
10, // at 10 : <xsd_enumeration>
11, // at 11 : <xsd_extension>
12, // at 12 : <xsd_group>
13, // at 13 : <xsd_import>
14, // at 14 : <xsd_restriction>
15, // at 15 : <xsd_schema>
16, // at 16 : <xsd_sequence>
17, // at 17 : <xsd_simpleContent>
18, // at 18 : <xsd_simpleType>
19, // at 19 : <xsd_maxLength>
20, // at 20 : <xsd_pattern>
21, // at 21 : <xsd_whiteSpace>
22, // at 22 : <xsd_ignore_attributes>
23, // at 23 : <select_arxmlmetaparser_5F_syntax_0>
28, // at 24 : <select_arxmlmetaparser_5F_syntax_1>
33, // at 25 : <select_arxmlmetaparser_5F_syntax_2>
38, // at 26 : <select_arxmlmetaparser_5F_syntax_3>
43, // at 27 : <select_arxmlmetaparser_5F_syntax_4>
55, // at 28 : <select_arxmlmetaparser_5F_syntax_5>
60, // at 29 : <select_arxmlmetaparser_5F_syntax_6>
65, // at 30 : <select_arxmlmetaparser_5F_syntax_7>
70, // at 31 : <select_arxmlmetaparser_5F_syntax_8>
75, // at 32 : <select_arxmlmetaparser_5F_syntax_9>
80, // at 33 : <select_arxmlmetaparser_5F_syntax_10>
85, // at 34 : <select_arxmlmetaparser_5F_syntax_11>
96, // at 35 : <select_arxmlmetaparser_5F_syntax_12>
101, // at 36 : <select_arxmlmetaparser_5F_syntax_13>
106, // at 37 : <select_arxmlmetaparser_5F_syntax_14>
117, // at 38 : <select_arxmlmetaparser_5F_syntax_15>
127, // at 39 : <select_arxmlmetaparser_5F_syntax_16>
132, // at 40 : <select_arxmlmetaparser_5F_syntax_17>
137, // at 41 : <select_arxmlmetaparser_5F_syntax_18>
152, // at 42 : <select_arxmlmetaparser_5F_syntax_19>
157, // at 43 : <select_arxmlmetaparser_5F_syntax_20>
169, // at 44 : <select_arxmlmetaparser_5F_syntax_21>
174, // at 45 : <select_arxmlmetaparser_5F_syntax_22>
179, // at 46 : <select_arxmlmetaparser_5F_syntax_23>
186, // at 47 : <select_arxmlmetaparser_5F_syntax_24>
191, // at 48 : <select_arxmlmetaparser_5F_syntax_25>
196, // at 49 : <select_arxmlmetaparser_5F_syntax_26>
201, // at 50 : <select_arxmlmetaparser_5F_syntax_27>
206, // at 51 : <select_arxmlmetaparser_5F_syntax_28>
219, // at 52 : <select_arxmlmetaparser_5F_syntax_29>
224, // at 53 : <select_arxmlmetaparser_5F_syntax_30>
229, // at 54 : <select_arxmlmetaparser_5F_syntax_31>
234, // at 55 : <select_arxmlmetaparser_5F_syntax_32>
243, // at 56 : <select_arxmlmetaparser_5F_syntax_33>
248, // at 57 : <select_arxmlmetaparser_5F_syntax_34>
253, // at 58 : <select_arxmlmetaparser_5F_syntax_35>
258, // at 59 : <select_arxmlmetaparser_5F_syntax_36>
263, // at 60 : <select_arxmlmetaparser_5F_syntax_37>
286, // at 61 : <select_arxmlmetaparser_5F_syntax_38>
291, // at 62 : <select_arxmlmetaparser_5F_syntax_39>
308, // at 63 : <select_arxmlmetaparser_5F_syntax_40>
313, // at 64 : <select_arxmlmetaparser_5F_syntax_41>
318, // at 65 : <select_arxmlmetaparser_5F_syntax_42>
329, // at 66 : <select_arxmlmetaparser_5F_syntax_43>
334, // at 67 : <select_arxmlmetaparser_5F_syntax_44>
339, // at 68 : <select_arxmlmetaparser_5F_syntax_45>
344, // at 69 : <select_arxmlmetaparser_5F_syntax_46>
350, // at 70 : <select_arxmlmetaparser_5F_syntax_47>
355, // at 71 : <select_arxmlmetaparser_5F_syntax_48>
360, // at 72 : <select_arxmlmetaparser_5F_syntax_49>
365, // at 73 : <select_arxmlmetaparser_5F_syntax_50>
370, // at 74 : <select_arxmlmetaparser_5F_syntax_51>
375, // at 75 : <select_arxmlmetaparser_5F_syntax_52>
380, // at 76 : <select_arxmlmetaparser_5F_syntax_53>
385, // at 77 : <select_arxmlmetaparser_5F_syntax_54>
390, // at 78 : <select_arxmlmetaparser_5F_syntax_55>
395, // at 79 : <select_arxmlmetaparser_5F_syntax_56>
484, // at 80 : <>
0} ;

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                             'arxmlmetaparser_start_symbol' non terminal implementation                               
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_arxmlmetaparser_5F_grammar::nt_arxmlmetaparser_5F_start_5F_symbol_parse (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  rule_arxmlmetaparser_5F_syntax_arxmlmetaparser_5F_start_5F_symbol_i0_parse(inLexique) ;
}

void cGrammar_arxmlmetaparser_5F_grammar::nt_arxmlmetaparser_5F_start_5F_symbol_ (GALGAS_arxmlMetaClassMap & parameter_1,
                                GALGAS_bool parameter_2,
                                C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  rule_arxmlmetaparser_5F_syntax_arxmlmetaparser_5F_start_5F_symbol_i0_(parameter_1, parameter_2, inLexique) ;
}

void cGrammar_arxmlmetaparser_5F_grammar::performIndexing (C_Compiler * /* inCompiler */,
             const C_String & /* inSourceFilePath */) {
}

void cGrammar_arxmlmetaparser_5F_grammar::performOnlyLexicalAnalysis (C_Compiler * inCompiler,
             const C_String & inSourceFilePath) {
  C_Lexique_arxmlmetaparser_5F_scanner * scanner = NULL ;
  macroMyNew (scanner, C_Lexique_arxmlmetaparser_5F_scanner (inCompiler, inSourceFilePath COMMA_HERE)) ;
  if (scanner->sourceText ().isValid ()) {
    scanner->performLexicalAnalysis () ;
  }
  macroDetachSharedObject (scanner) ;
}

void cGrammar_arxmlmetaparser_5F_grammar::performOnlySyntaxAnalysis (C_Compiler * inCompiler,
             const C_String & inSourceFilePath) {
  C_Lexique_arxmlmetaparser_5F_scanner * scanner = NULL ;
  macroMyNew (scanner, C_Lexique_arxmlmetaparser_5F_scanner (inCompiler, inSourceFilePath COMMA_HERE)) ;
  if (scanner->sourceText ().isValid ()) {
    scanner->performTopDownParsing (gProductions_arxmlmetaparser_grammar, gProductionNames_arxmlmetaparser_grammar, gProductionIndexes_arxmlmetaparser_grammar,
                                    gFirstProductionIndexes_arxmlmetaparser_grammar, gDecision_arxmlmetaparser_grammar, gDecisionIndexes_arxmlmetaparser_grammar, 804) ;
  }
  macroDetachSharedObject (scanner) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                        Grammar start symbol implementation                                           
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_arxmlmetaparser_5F_grammar::_performSourceFileParsing_ (C_Compiler * inCompiler,
                                GALGAS_lstring inFilePath,
                                GALGAS_arxmlMetaClassMap &  parameter_1,
                                GALGAS_bool  parameter_2
                                COMMA_LOCATION_ARGS) {
  if (inFilePath.isValid ()) {
    const GALGAS_string filePathAsString = inFilePath.getter_string (HERE) ;
    C_String filePath = filePathAsString.stringValue () ;
    if (! C_FileManager::isAbsolutePath (filePath)) {
      filePath = inCompiler->sourceFilePath ().stringByDeletingLastPathComponent ().stringByAppendingPathComponent (filePath) ;
    }
    if (C_FileManager::fileExistsAtPath (filePath)) {
    C_Lexique_arxmlmetaparser_5F_scanner * scanner = NULL ;
    macroMyNew (scanner, C_Lexique_arxmlmetaparser_5F_scanner (inCompiler, filePath COMMA_HERE)) ;
    if (scanner->sourceText ().isValid ()) {
      const bool ok = scanner->performTopDownParsing (gProductions_arxmlmetaparser_grammar, gProductionNames_arxmlmetaparser_grammar, gProductionIndexes_arxmlmetaparser_grammar,
                                                      gFirstProductionIndexes_arxmlmetaparser_grammar, gDecision_arxmlmetaparser_grammar, gDecisionIndexes_arxmlmetaparser_grammar, 804) ;
      if (ok && ! executionModeIsSyntaxAnalysisOnly ()) {
        cGrammar_arxmlmetaparser_5F_grammar grammar ;
        grammar.nt_arxmlmetaparser_5F_start_5F_symbol_ (parameter_1, parameter_2, scanner) ;
        }
      }else{
        C_String message ;
        message << "the '" << filePath << "' file exists, but cannot be read" ;
        const GALGAS_location errorLocation (inFilePath.getter_location (THERE)) ;
        inCompiler->semanticErrorAtLocation (errorLocation, message, TC_Array <C_FixItDescription> () COMMA_THERE) ;
      }
      macroDetachSharedObject (scanner) ;
    }else{
      C_String message ;
      message << "the '" << filePath << "' file does not exist" ;
      const GALGAS_location errorLocation (inFilePath.getter_location (THERE)) ;
      inCompiler->semanticErrorAtLocation (errorLocation, message, TC_Array <C_FixItDescription> () COMMA_THERE) ;
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_arxmlmetaparser_5F_grammar::_performSourceStringParsing_ (C_Compiler * inCompiler,
                                GALGAS_string inSourceString,
                                GALGAS_string inNameString,
                                GALGAS_arxmlMetaClassMap &  parameter_1,
                                GALGAS_bool  parameter_2
                                COMMA_UNUSED_LOCATION_ARGS) {
  if (inSourceString.isValid () && inNameString.isValid ()) {
    const C_String sourceString = inSourceString.stringValue () ;
    const C_String nameString = inNameString.stringValue () ;
    C_Lexique_arxmlmetaparser_5F_scanner * scanner = NULL ;
    macroMyNew (scanner, C_Lexique_arxmlmetaparser_5F_scanner (inCompiler, sourceString, nameString COMMA_HERE)) ;
    const bool ok = scanner->performTopDownParsing (gProductions_arxmlmetaparser_grammar, gProductionNames_arxmlmetaparser_grammar, gProductionIndexes_arxmlmetaparser_grammar,
                                                    gFirstProductionIndexes_arxmlmetaparser_grammar, gDecision_arxmlmetaparser_grammar, gDecisionIndexes_arxmlmetaparser_grammar, 804) ;
    if (ok && ! executionModeIsSyntaxAnalysisOnly ()) {
      cGrammar_arxmlmetaparser_5F_grammar grammar ;
      grammar.nt_arxmlmetaparser_5F_start_5F_symbol_ (parameter_1, parameter_2, scanner) ;
    }
    macroDetachSharedObject (scanner) ;
  }
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                      'xml_header' non terminal implementation                                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_arxmlmetaparser_5F_grammar::nt_xml_5F_header_parse (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  rule_arxmlmetaparser_5F_syntax_xml_5F_header_i1_parse(inLexique) ;
}

void cGrammar_arxmlmetaparser_5F_grammar::nt_xml_5F_header_ (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  rule_arxmlmetaparser_5F_syntax_xml_5F_header_i1_(inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                    'xsd_annotation' non terminal implementation                                      
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_arxmlmetaparser_5F_grammar::nt_xsd_5F_annotation_parse (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  rule_arxmlmetaparser_5F_syntax_xsd_5F_annotation_i2_parse(inLexique) ;
}

void cGrammar_arxmlmetaparser_5F_grammar::nt_xsd_5F_annotation_ (GALGAS_arxmlMetaClassMap & parameter_1,
                                GALGAS_arxmlMetaClassGraph & parameter_2,
                                GALGAS_lstring parameter_3,
                                C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  rule_arxmlmetaparser_5F_syntax_xsd_5F_annotation_i2_(parameter_1, parameter_2, parameter_3, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                     'xsd_appinfo' non terminal implementation                                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_arxmlmetaparser_5F_grammar::nt_xsd_5F_appinfo_parse (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  rule_arxmlmetaparser_5F_syntax_xsd_5F_appinfo_i3_parse(inLexique) ;
}

void cGrammar_arxmlmetaparser_5F_grammar::nt_xsd_5F_appinfo_ (GALGAS_arxmlMetaClassMap & parameter_1,
                                GALGAS_arxmlMetaClassGraph & parameter_2,
                                GALGAS_lstring parameter_3,
                                C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  rule_arxmlmetaparser_5F_syntax_xsd_5F_appinfo_i3_(parameter_1, parameter_2, parameter_3, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                    'xsd_attribute' non terminal implementation                                       
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_arxmlmetaparser_5F_grammar::nt_xsd_5F_attribute_parse (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  rule_arxmlmetaparser_5F_syntax_xsd_5F_attribute_i4_parse(inLexique) ;
}

void cGrammar_arxmlmetaparser_5F_grammar::nt_xsd_5F_attribute_ (GALGAS_arxmlMetaClassMap & parameter_1,
                                GALGAS_arxmlMetaClassGraph & parameter_2,
                                GALGAS_lstring parameter_3,
                                C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  rule_arxmlmetaparser_5F_syntax_xsd_5F_attribute_i4_(parameter_1, parameter_2, parameter_3, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                  'xsd_attributeGroup' non terminal implementation                                    
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_arxmlmetaparser_5F_grammar::nt_xsd_5F_attributeGroup_parse (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  rule_arxmlmetaparser_5F_syntax_xsd_5F_attributeGroup_i5_parse(inLexique) ;
}

void cGrammar_arxmlmetaparser_5F_grammar::nt_xsd_5F_attributeGroup_ (GALGAS_arxmlMetaClassMap & parameter_1,
                                GALGAS_arxmlMetaClassGraph & parameter_2,
                                GALGAS_lstring parameter_3,
                                C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  rule_arxmlmetaparser_5F_syntax_xsd_5F_attributeGroup_i5_(parameter_1, parameter_2, parameter_3, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                      'xsd_choice' non terminal implementation                                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_arxmlmetaparser_5F_grammar::nt_xsd_5F_choice_parse (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  rule_arxmlmetaparser_5F_syntax_xsd_5F_choice_i6_parse(inLexique) ;
}

void cGrammar_arxmlmetaparser_5F_grammar::nt_xsd_5F_choice_ (GALGAS_arxmlMetaClassMap & parameter_1,
                                GALGAS_arxmlMetaClassGraph & parameter_2,
                                GALGAS_lstring parameter_3,
                                C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  rule_arxmlmetaparser_5F_syntax_xsd_5F_choice_i6_(parameter_1, parameter_2, parameter_3, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                   'xsd_complexType' non terminal implementation                                      
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_arxmlmetaparser_5F_grammar::nt_xsd_5F_complexType_parse (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  rule_arxmlmetaparser_5F_syntax_xsd_5F_complexType_i7_parse(inLexique) ;
}

void cGrammar_arxmlmetaparser_5F_grammar::nt_xsd_5F_complexType_ (GALGAS_arxmlMetaClassMap & parameter_1,
                                GALGAS_arxmlMetaClassGraph & parameter_2,
                                GALGAS_lstring parameter_3,
                                C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  rule_arxmlmetaparser_5F_syntax_xsd_5F_complexType_i7_(parameter_1, parameter_2, parameter_3, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                  'xsd_documentation' non terminal implementation                                     
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_arxmlmetaparser_5F_grammar::nt_xsd_5F_documentation_parse (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  rule_arxmlmetaparser_5F_syntax_xsd_5F_documentation_i8_parse(inLexique) ;
}

void cGrammar_arxmlmetaparser_5F_grammar::nt_xsd_5F_documentation_ (GALGAS_arxmlMetaClassMap & parameter_1,
                                GALGAS_arxmlMetaClassGraph & parameter_2,
                                GALGAS_lstring parameter_3,
                                C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  rule_arxmlmetaparser_5F_syntax_xsd_5F_documentation_i8_(parameter_1, parameter_2, parameter_3, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                     'xsd_element' non terminal implementation                                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_arxmlmetaparser_5F_grammar::nt_xsd_5F_element_parse (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  rule_arxmlmetaparser_5F_syntax_xsd_5F_element_i9_parse(inLexique) ;
}

void cGrammar_arxmlmetaparser_5F_grammar::nt_xsd_5F_element_ (GALGAS_arxmlMetaClassMap & parameter_1,
                                GALGAS_arxmlMetaClassGraph & parameter_2,
                                GALGAS_lstring parameter_3,
                                C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  rule_arxmlmetaparser_5F_syntax_xsd_5F_element_i9_(parameter_1, parameter_2, parameter_3, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                   'xsd_enumeration' non terminal implementation                                      
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_arxmlmetaparser_5F_grammar::nt_xsd_5F_enumeration_parse (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  rule_arxmlmetaparser_5F_syntax_xsd_5F_enumeration_i10_parse(inLexique) ;
}

void cGrammar_arxmlmetaparser_5F_grammar::nt_xsd_5F_enumeration_ (GALGAS_arxmlMetaClassMap & parameter_1,
                                GALGAS_arxmlMetaClassGraph & parameter_2,
                                GALGAS_lstring parameter_3,
                                GALGAS_arxmlMetaSimpletype & parameter_4,
                                C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  rule_arxmlmetaparser_5F_syntax_xsd_5F_enumeration_i10_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                    'xsd_extension' non terminal implementation                                       
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_arxmlmetaparser_5F_grammar::nt_xsd_5F_extension_parse (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  rule_arxmlmetaparser_5F_syntax_xsd_5F_extension_i11_parse(inLexique) ;
}

void cGrammar_arxmlmetaparser_5F_grammar::nt_xsd_5F_extension_ (GALGAS_arxmlMetaClassMap & parameter_1,
                                GALGAS_arxmlMetaClassGraph & parameter_2,
                                GALGAS_lstring parameter_3,
                                C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  rule_arxmlmetaparser_5F_syntax_xsd_5F_extension_i11_(parameter_1, parameter_2, parameter_3, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                      'xsd_group' non terminal implementation                                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_arxmlmetaparser_5F_grammar::nt_xsd_5F_group_parse (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  rule_arxmlmetaparser_5F_syntax_xsd_5F_group_i12_parse(inLexique) ;
}

void cGrammar_arxmlmetaparser_5F_grammar::nt_xsd_5F_group_ (GALGAS_arxmlMetaClassMap & parameter_1,
                                GALGAS_arxmlMetaClassGraph & parameter_2,
                                GALGAS_lstring parameter_3,
                                C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  rule_arxmlmetaparser_5F_syntax_xsd_5F_group_i12_(parameter_1, parameter_2, parameter_3, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                      'xsd_import' non terminal implementation                                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_arxmlmetaparser_5F_grammar::nt_xsd_5F_import_parse (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  rule_arxmlmetaparser_5F_syntax_xsd_5F_import_i13_parse(inLexique) ;
}

void cGrammar_arxmlmetaparser_5F_grammar::nt_xsd_5F_import_ (GALGAS_arxmlMetaClassMap & parameter_1,
                                GALGAS_arxmlMetaClassGraph & parameter_2,
                                GALGAS_lstring parameter_3,
                                C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  rule_arxmlmetaparser_5F_syntax_xsd_5F_import_i13_(parameter_1, parameter_2, parameter_3, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                   'xsd_restriction' non terminal implementation                                      
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_arxmlmetaparser_5F_grammar::nt_xsd_5F_restriction_parse (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  rule_arxmlmetaparser_5F_syntax_xsd_5F_restriction_i14_parse(inLexique) ;
}

void cGrammar_arxmlmetaparser_5F_grammar::nt_xsd_5F_restriction_ (GALGAS_arxmlMetaClassMap & parameter_1,
                                GALGAS_arxmlMetaClassGraph & parameter_2,
                                GALGAS_lstring parameter_3,
                                GALGAS_arxmlMetaSimpletype & parameter_4,
                                C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  rule_arxmlmetaparser_5F_syntax_xsd_5F_restriction_i14_(parameter_1, parameter_2, parameter_3, parameter_4, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                      'xsd_schema' non terminal implementation                                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_arxmlmetaparser_5F_grammar::nt_xsd_5F_schema_parse (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  rule_arxmlmetaparser_5F_syntax_xsd_5F_schema_i15_parse(inLexique) ;
}

void cGrammar_arxmlmetaparser_5F_grammar::nt_xsd_5F_schema_ (GALGAS_arxmlMetaClassMap & parameter_1,
                                GALGAS_arxmlMetaClassGraph & parameter_2,
                                C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  rule_arxmlmetaparser_5F_syntax_xsd_5F_schema_i15_(parameter_1, parameter_2, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                     'xsd_sequence' non terminal implementation                                       
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_arxmlmetaparser_5F_grammar::nt_xsd_5F_sequence_parse (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  rule_arxmlmetaparser_5F_syntax_xsd_5F_sequence_i16_parse(inLexique) ;
}

void cGrammar_arxmlmetaparser_5F_grammar::nt_xsd_5F_sequence_ (GALGAS_arxmlMetaClassMap & parameter_1,
                                GALGAS_arxmlMetaClassGraph & parameter_2,
                                GALGAS_lstring parameter_3,
                                C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  rule_arxmlmetaparser_5F_syntax_xsd_5F_sequence_i16_(parameter_1, parameter_2, parameter_3, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                  'xsd_simpleContent' non terminal implementation                                     
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_arxmlmetaparser_5F_grammar::nt_xsd_5F_simpleContent_parse (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  rule_arxmlmetaparser_5F_syntax_xsd_5F_simpleContent_i17_parse(inLexique) ;
}

void cGrammar_arxmlmetaparser_5F_grammar::nt_xsd_5F_simpleContent_ (GALGAS_arxmlMetaClassMap & parameter_1,
                                GALGAS_arxmlMetaClassGraph & parameter_2,
                                GALGAS_lstring parameter_3,
                                C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  rule_arxmlmetaparser_5F_syntax_xsd_5F_simpleContent_i17_(parameter_1, parameter_2, parameter_3, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                    'xsd_simpleType' non terminal implementation                                      
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_arxmlmetaparser_5F_grammar::nt_xsd_5F_simpleType_parse (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  rule_arxmlmetaparser_5F_syntax_xsd_5F_simpleType_i18_parse(inLexique) ;
}

void cGrammar_arxmlmetaparser_5F_grammar::nt_xsd_5F_simpleType_ (GALGAS_arxmlMetaClassMap & parameter_1,
                                GALGAS_arxmlMetaClassGraph & parameter_2,
                                GALGAS_lstring parameter_3,
                                C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  rule_arxmlmetaparser_5F_syntax_xsd_5F_simpleType_i18_(parameter_1, parameter_2, parameter_3, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                    'xsd_maxLength' non terminal implementation                                       
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_arxmlmetaparser_5F_grammar::nt_xsd_5F_maxLength_parse (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  rule_arxmlmetaparser_5F_syntax_xsd_5F_maxLength_i19_parse(inLexique) ;
}

void cGrammar_arxmlmetaparser_5F_grammar::nt_xsd_5F_maxLength_ (GALGAS_arxmlMetaClassMap & parameter_1,
                                GALGAS_arxmlMetaClassGraph & parameter_2,
                                GALGAS_lstring parameter_3,
                                C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  rule_arxmlmetaparser_5F_syntax_xsd_5F_maxLength_i19_(parameter_1, parameter_2, parameter_3, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                     'xsd_pattern' non terminal implementation                                        
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_arxmlmetaparser_5F_grammar::nt_xsd_5F_pattern_parse (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  rule_arxmlmetaparser_5F_syntax_xsd_5F_pattern_i20_parse(inLexique) ;
}

void cGrammar_arxmlmetaparser_5F_grammar::nt_xsd_5F_pattern_ (GALGAS_arxmlMetaClassMap & parameter_1,
                                GALGAS_arxmlMetaClassGraph & parameter_2,
                                GALGAS_lstring parameter_3,
                                C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  rule_arxmlmetaparser_5F_syntax_xsd_5F_pattern_i20_(parameter_1, parameter_2, parameter_3, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                    'xsd_whiteSpace' non terminal implementation                                      
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_arxmlmetaparser_5F_grammar::nt_xsd_5F_whiteSpace_parse (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  rule_arxmlmetaparser_5F_syntax_xsd_5F_whiteSpace_i21_parse(inLexique) ;
}

void cGrammar_arxmlmetaparser_5F_grammar::nt_xsd_5F_whiteSpace_ (GALGAS_arxmlMetaClassMap & parameter_1,
                                GALGAS_arxmlMetaClassGraph & parameter_2,
                                GALGAS_lstring parameter_3,
                                C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  rule_arxmlmetaparser_5F_syntax_xsd_5F_whiteSpace_i21_(parameter_1, parameter_2, parameter_3, inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                                'xsd_ignore_attributes' non terminal implementation                                   
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

void cGrammar_arxmlmetaparser_5F_grammar::nt_xsd_5F_ignore_5F_attributes_parse (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  rule_arxmlmetaparser_5F_syntax_xsd_5F_ignore_5F_attributes_i22_parse(inLexique) ;
}

void cGrammar_arxmlmetaparser_5F_grammar::nt_xsd_5F_ignore_5F_attributes_ (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  rule_arxmlmetaparser_5F_syntax_xsd_5F_ignore_5F_attributes_i22_(inLexique) ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_arxmlmetaparser_5F_syntax_0' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_arxmlmetaparser_5F_grammar::select_arxmlmetaparser_5F_syntax_0 (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_arxmlmetaparser_5F_syntax_1' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_arxmlmetaparser_5F_grammar::select_arxmlmetaparser_5F_syntax_1 (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_arxmlmetaparser_5F_syntax_2' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_arxmlmetaparser_5F_grammar::select_arxmlmetaparser_5F_syntax_2 (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_arxmlmetaparser_5F_syntax_3' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_arxmlmetaparser_5F_grammar::select_arxmlmetaparser_5F_syntax_3 (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_arxmlmetaparser_5F_syntax_4' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_arxmlmetaparser_5F_grammar::select_arxmlmetaparser_5F_syntax_4 (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_arxmlmetaparser_5F_syntax_5' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_arxmlmetaparser_5F_grammar::select_arxmlmetaparser_5F_syntax_5 (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_arxmlmetaparser_5F_syntax_6' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_arxmlmetaparser_5F_grammar::select_arxmlmetaparser_5F_syntax_6 (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_arxmlmetaparser_5F_syntax_7' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_arxmlmetaparser_5F_grammar::select_arxmlmetaparser_5F_syntax_7 (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_arxmlmetaparser_5F_syntax_8' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_arxmlmetaparser_5F_grammar::select_arxmlmetaparser_5F_syntax_8 (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                       'select_arxmlmetaparser_5F_syntax_9' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_arxmlmetaparser_5F_grammar::select_arxmlmetaparser_5F_syntax_9 (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_arxmlmetaparser_5F_syntax_10' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_arxmlmetaparser_5F_grammar::select_arxmlmetaparser_5F_syntax_10 (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_arxmlmetaparser_5F_syntax_11' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_arxmlmetaparser_5F_grammar::select_arxmlmetaparser_5F_syntax_11 (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_arxmlmetaparser_5F_syntax_12' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_arxmlmetaparser_5F_grammar::select_arxmlmetaparser_5F_syntax_12 (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_arxmlmetaparser_5F_syntax_13' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_arxmlmetaparser_5F_grammar::select_arxmlmetaparser_5F_syntax_13 (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_arxmlmetaparser_5F_syntax_14' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_arxmlmetaparser_5F_grammar::select_arxmlmetaparser_5F_syntax_14 (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_arxmlmetaparser_5F_syntax_15' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_arxmlmetaparser_5F_grammar::select_arxmlmetaparser_5F_syntax_15 (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_arxmlmetaparser_5F_syntax_16' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_arxmlmetaparser_5F_grammar::select_arxmlmetaparser_5F_syntax_16 (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_arxmlmetaparser_5F_syntax_17' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_arxmlmetaparser_5F_grammar::select_arxmlmetaparser_5F_syntax_17 (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_arxmlmetaparser_5F_syntax_18' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_arxmlmetaparser_5F_grammar::select_arxmlmetaparser_5F_syntax_18 (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_arxmlmetaparser_5F_syntax_19' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_arxmlmetaparser_5F_grammar::select_arxmlmetaparser_5F_syntax_19 (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_arxmlmetaparser_5F_syntax_20' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_arxmlmetaparser_5F_grammar::select_arxmlmetaparser_5F_syntax_20 (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_arxmlmetaparser_5F_syntax_21' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_arxmlmetaparser_5F_grammar::select_arxmlmetaparser_5F_syntax_21 (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_arxmlmetaparser_5F_syntax_22' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_arxmlmetaparser_5F_grammar::select_arxmlmetaparser_5F_syntax_22 (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_arxmlmetaparser_5F_syntax_23' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_arxmlmetaparser_5F_grammar::select_arxmlmetaparser_5F_syntax_23 (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_arxmlmetaparser_5F_syntax_24' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_arxmlmetaparser_5F_grammar::select_arxmlmetaparser_5F_syntax_24 (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_arxmlmetaparser_5F_syntax_25' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_arxmlmetaparser_5F_grammar::select_arxmlmetaparser_5F_syntax_25 (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_arxmlmetaparser_5F_syntax_26' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_arxmlmetaparser_5F_grammar::select_arxmlmetaparser_5F_syntax_26 (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_arxmlmetaparser_5F_syntax_27' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_arxmlmetaparser_5F_grammar::select_arxmlmetaparser_5F_syntax_27 (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_arxmlmetaparser_5F_syntax_28' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_arxmlmetaparser_5F_grammar::select_arxmlmetaparser_5F_syntax_28 (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_arxmlmetaparser_5F_syntax_29' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_arxmlmetaparser_5F_grammar::select_arxmlmetaparser_5F_syntax_29 (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_arxmlmetaparser_5F_syntax_30' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_arxmlmetaparser_5F_grammar::select_arxmlmetaparser_5F_syntax_30 (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_arxmlmetaparser_5F_syntax_31' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_arxmlmetaparser_5F_grammar::select_arxmlmetaparser_5F_syntax_31 (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_arxmlmetaparser_5F_syntax_32' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_arxmlmetaparser_5F_grammar::select_arxmlmetaparser_5F_syntax_32 (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_arxmlmetaparser_5F_syntax_33' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_arxmlmetaparser_5F_grammar::select_arxmlmetaparser_5F_syntax_33 (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_arxmlmetaparser_5F_syntax_34' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_arxmlmetaparser_5F_grammar::select_arxmlmetaparser_5F_syntax_34 (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_arxmlmetaparser_5F_syntax_35' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_arxmlmetaparser_5F_grammar::select_arxmlmetaparser_5F_syntax_35 (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_arxmlmetaparser_5F_syntax_36' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_arxmlmetaparser_5F_grammar::select_arxmlmetaparser_5F_syntax_36 (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_arxmlmetaparser_5F_syntax_37' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_arxmlmetaparser_5F_grammar::select_arxmlmetaparser_5F_syntax_37 (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_arxmlmetaparser_5F_syntax_38' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_arxmlmetaparser_5F_grammar::select_arxmlmetaparser_5F_syntax_38 (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_arxmlmetaparser_5F_syntax_39' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_arxmlmetaparser_5F_grammar::select_arxmlmetaparser_5F_syntax_39 (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_arxmlmetaparser_5F_syntax_40' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_arxmlmetaparser_5F_grammar::select_arxmlmetaparser_5F_syntax_40 (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_arxmlmetaparser_5F_syntax_41' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_arxmlmetaparser_5F_grammar::select_arxmlmetaparser_5F_syntax_41 (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_arxmlmetaparser_5F_syntax_42' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_arxmlmetaparser_5F_grammar::select_arxmlmetaparser_5F_syntax_42 (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_arxmlmetaparser_5F_syntax_43' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_arxmlmetaparser_5F_grammar::select_arxmlmetaparser_5F_syntax_43 (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_arxmlmetaparser_5F_syntax_44' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_arxmlmetaparser_5F_grammar::select_arxmlmetaparser_5F_syntax_44 (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_arxmlmetaparser_5F_syntax_45' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_arxmlmetaparser_5F_grammar::select_arxmlmetaparser_5F_syntax_45 (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_arxmlmetaparser_5F_syntax_46' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_arxmlmetaparser_5F_grammar::select_arxmlmetaparser_5F_syntax_46 (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_arxmlmetaparser_5F_syntax_47' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_arxmlmetaparser_5F_grammar::select_arxmlmetaparser_5F_syntax_47 (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_arxmlmetaparser_5F_syntax_48' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_arxmlmetaparser_5F_grammar::select_arxmlmetaparser_5F_syntax_48 (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_arxmlmetaparser_5F_syntax_49' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_arxmlmetaparser_5F_grammar::select_arxmlmetaparser_5F_syntax_49 (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_arxmlmetaparser_5F_syntax_50' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_arxmlmetaparser_5F_grammar::select_arxmlmetaparser_5F_syntax_50 (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_arxmlmetaparser_5F_syntax_51' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_arxmlmetaparser_5F_grammar::select_arxmlmetaparser_5F_syntax_51 (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_arxmlmetaparser_5F_syntax_52' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_arxmlmetaparser_5F_grammar::select_arxmlmetaparser_5F_syntax_52 (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_arxmlmetaparser_5F_syntax_53' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_arxmlmetaparser_5F_grammar::select_arxmlmetaparser_5F_syntax_53 (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_arxmlmetaparser_5F_syntax_54' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_arxmlmetaparser_5F_grammar::select_arxmlmetaparser_5F_syntax_54 (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_arxmlmetaparser_5F_syntax_55' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_arxmlmetaparser_5F_grammar::select_arxmlmetaparser_5F_syntax_55 (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*
//                                                                                                                      
//                      'select_arxmlmetaparser_5F_syntax_56' added non terminal implementation                         
//                                                                                                                      
//---------------------------------------------------------------------------------------------------------------------*

int32_t cGrammar_arxmlmetaparser_5F_grammar::select_arxmlmetaparser_5F_syntax_56 (C_Lexique_arxmlmetaparser_5F_scanner * inLexique) {
  return inLexique->nextProductionIndex () ;
}

//---------------------------------------------------------------------------------------------------------------------*

