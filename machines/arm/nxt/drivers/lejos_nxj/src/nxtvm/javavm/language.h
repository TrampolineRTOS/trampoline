
#include "types.h"
#include "classes.h"
#include "memory.h"

#ifndef _LANGUAGE_H
#define _LANGUAGE_H


#define STATIC_INITIALIZER 0

// Class flags:

#define C_INITIALIZED 0x01
#define C_ARRAY       0x02
#define C_HASCLINIT   0x04
#define C_INTERFACE   0x08

typedef struct S_MasterRecord
{
  TWOBYTES magicNumber;
  TWOBYTES constantTableOffset;
  
  /**
   * Offset to STATICFIELD[].
   */
  TWOBYTES staticFieldsOffset;
  TWOBYTES staticStateOffset;
  
  /**
   * Size of all static state in 2-byte words.
   */
  TWOBYTES staticStateLength;
  TWOBYTES numStaticFields;
  
  /**
   * Offset to sequence of class indices (bytes).
   */
  TWOBYTES entryClassesOffset;
  byte numEntryClasses;
  byte lastClass;
} MasterRecord;

typedef struct S_ClassRecord
{
  /**
   * Space occupied by instance in 2-byte words.
   */
  TWOBYTES classSize;
  /**
   * Offset of method table (in bytes) starting from
   * the beginning of the entire binary.
   */
  TWOBYTES methodTableOffset;
  /**
   * Offset to table of bytes containing types of fields.
   * Useful for initializing objects.
   */
  TWOBYTES instanceTableOffset;
  byte numInstanceFields;
  byte numMethods;
  byte parentClass;
  byte cflags;
} __attribute__((packed)) ClassRecord;

// Method flags:

#define M_NATIVE       0x01
#define M_SYNCHRONIZED 0x02
#define M_STATIC       0x04

typedef struct S_MethodRecord
{
  // Unique id for the signature of the method
  TWOBYTES signatureId;
  // Offset to table of exception information
  TWOBYTES exceptionTable;
  TWOBYTES codeOffset;
  // Number of 32-bit locals (long is counted as 2 locals).
  byte numLocals;
  // Maximum size of local operand stack, in 32-bit words.
  byte maxOperands;
  // It should be such that stackTop-numParameters unwinds the stack.
  // The receiver in non-static methods is counted as one word. 
  byte numParameters;
  // Number of exception handlers
  byte numExceptionHandlers;
  byte mflags;
} MethodRecord;

typedef struct S_ExceptionRecord
{
  TWOBYTES start;
  TWOBYTES end;
  TWOBYTES handler; 
  // The index of a Throwable class.
  byte classIndex; 
} ExceptionRecord;

typedef struct S_ConstantRecord
{
  /**
   * Offset to bytes of constant.
   */
  TWOBYTES offset;
  /**
   * Type of constant.
   */
  byte constantType;
  /**
   * Size of constant. Length of Utf8 entry for strings.
   */
  byte constantSize;
} ConstantRecord;

typedef TWOBYTES STATICFIELD;

extern void *installedBinary;

extern byte get_class_index (Object *obj);
extern void dispatch_virtual (Object *obj, TWOBYTES signature, byte *rAddr);
extern MethodRecord *find_method (ClassRecord *classRec, TWOBYTES signature);
extern STACKWORD instance_of (Object *obj, byte classIndex);
extern void do_return (byte numWords);
extern boolean dispatch_static_initializer (ClassRecord *aRec, byte *rAddr);
extern boolean dispatch_special (MethodRecord *methodRecord, byte *retAddr);
void dispatch_special_checked (byte classIndex, byte methodIndex, byte *retAddr, byte *btAddr);
extern void handle_field (byte hiByte, byte loByte, boolean doPut, boolean aStatic, byte *btAddr);

#define install_binary(PTR_)        (installedBinary=(PTR_))
#define get_master_record()         ((MasterRecord *) installedBinary)
#define get_magic_number()          get_master_record()->magicNumber
#define get_binary_base()           ((byte *) installedBinary)
#define get_class_base()            ((ClassRecord *) (get_binary_base() + sizeof(MasterRecord)))

#define get_class_record(CLASSIDX_) (get_class_base() + (CLASSIDX_))
#define get_method_table(CREC_)     ((MethodRecord *) (get_binary_base() + (CREC_)->methodTableOffset))

#define get_field_table(CREC_)      ((byte *) (get_binary_base() + (CREC_)->instanceTableOffset))

#define get_field_type(CR_,I_)      (*(get_field_table(CR_) + (I_)))

#define get_method_record(CR_,I_)   (get_method_table(CR_) + (I_)) 

#define get_constant_base()         ((ConstantRecord *) (get_binary_base() + get_master_record()->constantTableOffset))

#define get_constant_record(IDX_)   (get_constant_base() + (IDX_))

#define get_constant_ptr(CR_)       (get_binary_base() + (CR_)->offset)

#define class_size(CLASSIDX_)       (get_class_record(CLASSIDX_)->classSize)

#define is_initialized(CREC_)       (((CREC_)->cflags & C_INITIALIZED) != 0)
#define is_array_class(CREC_)       (((CREC_)->cflags & C_ARRAY) != 0)
#define has_clinit(CREC_)           (((CREC_)->cflags & C_HASCLINIT) != 0)
#define is_interface(CREC_)         (((CREC_)->cflags & C_INTERFACE) != 0)

#define set_initialized(CLASSREC_)   ((CLASSREC_)->cflags |= C_INITIALIZED)
#define set_uninitialized(CLASSREC_) ((CLASSREC_)->cflags &= ~C_INITIALIZED)

#define is_synchronized(MREC_)      (((MREC_)->mflags & M_SYNCHRONIZED) != 0)
#define is_native(MREC_)            (((MREC_)->mflags & M_NATIVE) != 0)
#define get_code_ptr(MREC_)         (get_binary_base() + (MREC_)->codeOffset)

#define get_static_fields_base()    (get_binary_base() + get_master_record()->staticFieldsOffset)
#define get_static_state_base()     (get_binary_base() + get_master_record()->staticStateOffset)
#define get_static_field_offset(R_) ((R_) & 0x0FFF)

#define get_num_entry_classes()     (get_master_record()->numEntryClasses)
#define get_entry_classes_base()    (get_binary_base() + get_master_record()->entryClassesOffset)
#define get_entry_class(N_)         (*(get_entry_classes_base() + (N_)))

static inline void initialize_binary()
{
  MasterRecord *mrec;
  byte i;
  
  mrec = get_master_record();

/*  printf("Got master record\n");
  printf("Base is %d\n",get_binary_base());
  printf("Offset is %d\n",(int) mrec->staticStateOffset); */

  /* printf("Length is %d\n",(int) mrec->staticStateLength);*/
  zero_mem ((TWOBYTES *) (get_binary_base() + mrec->staticStateOffset),
            mrec->staticStateLength);
//  printf("Zeroed memory\n");
  for (i = 0; i <= mrec->lastClass; i++)
  {
    set_uninitialized (get_class_record (i)); 	  
  }
}  

#endif // _LANGUAGE_H









