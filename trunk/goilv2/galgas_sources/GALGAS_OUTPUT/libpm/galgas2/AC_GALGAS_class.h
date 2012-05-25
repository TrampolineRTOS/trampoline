//---------------------------------------------------------------------------*
//                                                                           *
//  acPtr_class : Base class for GALGAS class                                *
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

#ifndef AC_GALGAS_CLASS_DEFINED
#define AC_GALGAS_CLASS_DEFINED

//---------------------------------------------------------------------------*

#include "galgas2/AC_GALGAS_root.h"

//---------------------------------------------------------------------------*

class C_String ;
class C_galgas_type_descriptor ;
class acPtr_class ;

//---------------------------------------------------------------------------*

class AC_GALGAS_class : public AC_GALGAS_root {
//--- Attribute
  protected : acPtr_class * mObjectPtr ;
  public : inline const acPtr_class * ptr (void) const { return mObjectPtr ; }

//--- Default constructor
  protected : AC_GALGAS_class (void) ;
  
//--- Constructor from pointer
  protected : AC_GALGAS_class (const acPtr_class * inPointer) ;
  
//--- Destructor
  protected : virtual ~ AC_GALGAS_class (void) ;

//--- Is valid
  public : virtual bool isValid (void) const { return NULL != mObjectPtr ; }
  
//--- Drop
  public : virtual void drop (void) ;
  
//--- Handle copy
  protected : AC_GALGAS_class (const AC_GALGAS_class & inSource) ;
  protected : AC_GALGAS_class & operator = (const AC_GALGAS_class & inSource) ;
  
//--- Dynamic Type Descriptor
  public : virtual const C_galgas_type_descriptor * dynamicTypeDescriptor (void) const ;

  public : virtual void description (C_String & ioString,
                                     const PMSInt32 inIndentation) const ;
} ;

//---------------------------------------------------------------------------*

#endif
