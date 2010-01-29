/**
 * classes.h
 * Contains conterparts of special classes as C structs.
 */
 
#ifndef _CLASSES_H
#define _CLASSES_H

#include "types.h"

#define CLASS_MASK      0x00FF
#define CLASS_SHIFT     0

#define GC_MASK         0x2000
#define GC_SHIFT        13

#define IS_ARRAY_MASK   0x4000
#define IS_ARRAY_SHIFT  14

#define IS_ALLOCATED_MASK  0x8000
#define IS_ALLOCATED_SHIFT 15

#define ARRAY_LENGTH_MASK  0x01FF
#define ARRAY_LENGTH_SHIFT 0

#define ELEM_TYPE_MASK  0x1E00
#define ELEM_TYPE_SHIFT 9

#define FREE_BLOCK_SIZE_MASK 0x7FFF
#define FREE_BLOCK_SIZE_SHIFT 0

#define is_array(OBJ_)           ((OBJ_)->flags.objects.isArray)
#define is_allocated(OBJ_)       ((OBJ_)->flags.freeBlock.isAllocated)
#define get_monitor_count(OBJ_)  ((OBJ_)->monitorCount)
#define is_gc(OBJ_)              ((OBJ_)->flags.objects.mark)

// Double-check these data structures with the 
// Java declaration of each corresponding class.

/**
 * Object class native structure
 */
typedef struct S_Object
{
  /**
   * Object/block flags.
   * Free block:
   *  -- bits 0-14: Size of free block in words.
   *  -- bit 15   : Zero (not allocated).
   * Objects:
   *  -- bits 0-7 : Class index.
   *  -- bits 8-12: Unused.
   *  -- bit 13   : Garbage collection mark.
   *  -- bit 14   : Zero (not an array).
   *  -- bit 15   : One (allocated).
   * Arrays:
   *  -- bits 0-8 : Array length (0-511).
   *  -- bits 9-12: Element type.
   *  -- bit 13   : Garbage collection mark.
   *  -- bit 14   : One (is an array).
   *  -- bit 15   : One (allocated).
   */
   union _flags
   {
     TWOBYTES all;
     struct _freeBlock
     {
       TWOBYTES size:15;
       TWOBYTES isAllocated:1;
     }  __attribute__((packed)) freeBlock;
     struct _objects
     {
       byte     _class;
       byte     padding:5;
       byte     mark:1;
       byte     isArray:1;
       byte     isAllocated:1;
     }  __attribute__((packed)) objects;
     struct _arrays
     {
       TWOBYTES length:9;
       TWOBYTES type:4;
       TWOBYTES mark:1;
       TWOBYTES isArray:1;
       TWOBYTES isAllocated:1;
     } __attribute__((packed)) arrays;
   } __attribute__((packed)) flags;

  /**
   * Synchronization state.
   */
  byte monitorCount;
  byte threadId;

} __attribute__((packed)) Object;

/**
 * Thread class native structure
 */
typedef struct S_Thread
{
  Object _super;	     // Superclass object storage

  REFERENCE nextThread;      // Intrinsic circular list of threads
  JINT waitingOn;            // Object who's monitor we want
  JINT sleepUntil;           // Time to wake up
  JINT stackFrameArray;      // Array of stack frames
  JINT stackArray;           // The stack itself
  JBYTE stackFrameArraySize; // Number of stack frames in use.
  JBYTE monitorCount;        // Saved monitor depth for context switches
  JBYTE threadId;            // Unique thread ID
  JBYTE state;               // RUNNING, DEAD, etc.
  JBYTE priority;            // The priority
  JBYTE interruptState;      // INTERRUPT_CLEARED, INTERRUPT_REQUESTED, ...
  JBYTE daemon;              // true == daemon thread
} Thread;

/**
 * Runtime class native structure. Doesn't actually contain
 * any instance data. Maybe it ought to? Like ALL of the leJOS
 * specific runtime instance data?
 */
typedef struct S_Runtime
{
  Object _super;
} Runtime;

/**
 * String class native structure
 */
typedef struct S_String
{
  Object _super;

  REFERENCE characters;
} String;


#ifdef WIMPY_MATH

static inline TWOBYTES get_array_length (Object *obj)
{
   TWOBYTES aux;
   aux = obj->flags.all & ARRAY_LENGTH_MASK;
   #if (ARRAY_LENGTH_SHIFT == 0)
   return aux;
   #else
   return (aux >> ARRAY_LENGTH_SHIFT);
   #endif
}

static inline TWOBYTES get_element_type (Object *obj)
{
   TWOBYTES aux;
   aux = obj->flags.all & ELEM_TYPE_MASK;
   #if (ELEM_TYPE_SHIFT == 0)
   return aux;
   #else
   return (aux >> ELEM_TYPE_SHIFT);
   #endif
}

static inline TWOBYTES get_na_class_index (Object *obj)
{
   TWOBYTES aux;
   aux = obj->flags.all & CLASS_MASK;
   #if (CLASS_SHIFT == 0)
   return aux;
   #else
   return (aux >> CLASS_SHIFT);
   #endif
}

#else

#ifndef notdef
#define get_array_length(ARR_)   (((ARR_)->flags.all & ARRAY_LENGTH_MASK) >> ARRAY_LENGTH_SHIFT)
#define get_element_type(ARR_)   ((ARR_)->flags.all & ELEM_TYPE_MASK) >> ELEM_TYPE_SHIFT
#define get_na_class_index(OBJ_) (((OBJ_)->flags.all & CLASS_MASK) >> CLASS_SHIFT)
#define get_free_length(OBJ_)    (((OBJ_)->flags.all & FREE_BLOCK_SIZE_MASK) >> FREE_BLOCK_SIZE_SHIFT)
#else
#define get_array_length(ARR_)   ((ARR_)->flags.arrays.length)
#define get_element_type(ARR_)   ((ARR_)->flags.arrays.type)
#define get_na_class_index(OBJ_) ((OBJ_)->flags.objects.class)
#define get_free_length(OBJ_)    ((OBJ_)->flags.freeBlock.size)
#endif

#endif // WIMPY_MATH

#endif // _CLASSES_H









