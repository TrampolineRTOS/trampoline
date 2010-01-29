
#include "types.h"
#include "classes.h"

#ifndef _MEMORY_H
#define _MEMORY_H

#define DEBUG_RCX_MEMORY 0

extern const byte typeSize[];

extern void memory_init ();
extern void memory_add_region (byte *region, byte *end);

extern void free_array (Object *objectRef);
extern void deallocate (TWOBYTES *ptr, TWOBYTES size);
extern Object *new_object_checked (const byte classIndex, byte *btAddr);
extern Object *new_object_for_class (byte classIndex);
extern Object *new_primitive_array (const byte primitiveType, STACKWORD length);
extern Object *reallocate_array(Object *obj, STACKWORD newlen);
extern Object *new_multi_array (byte elemType, byte totalDimensions, byte reqDimensions, STACKWORD *numElemPtr);
extern void make_word (byte *ptr, byte aSize, STACKWORD *aWordPtr);
extern void store_word (byte *ptr, byte aSize, STACKWORD aWord);
extern STACKWORD get_word(byte *ptr, byte aSize);
extern void zero_mem (TWOBYTES *ptr, TWOBYTES numWords);
extern int getHeapSize();
extern int getHeapFree();
extern int getRegionAddress();

#if DEBUG_RCX_MEMORY
extern void scan_memory (TWOBYTES *numNodes, TWOBYTES *biggest, TWOBYTES *freeMem);
#endif // DEBUG_RCX_MEMORY

#define HEADER_SIZE (sizeof(Object))
// Size of object header in 2-byte words
#define NORM_OBJ_SIZE ((HEADER_SIZE + 1) / 2)

#define get_array_element_ptr(ARR_,ESIZE_,IDX_) ((byte *) (ARR_) + (IDX_) * (ESIZE_) + HEADER_SIZE)

#define array_start(OBJ_)   ((byte *) (OBJ_) + HEADER_SIZE)
#define jbyte_array(OBJ_)   ((JBYTE *) array_start(OBJ_))
#define word_array(OBJ_)    ((STACKWORD *) array_start(OBJ_))
#define ref_array(OBJ_)     ((REFERENCE *) array_start(OBJ_))
#define jint_array(OBJ_)    ((JINT *) array_start(OBJ_))
#define jshort_array(OBJ_)  ((JSHORT *) array_start(OBJ_))
#define jchar_array(OBJ_)   ((JCHAR *) array_start(OBJ_))
#define jlong_array(OBJ_)   ((JLONG *) array_start(OBJ_))
#define jfloat_array(OBJ_)  ((JFLOAT *) array_start(OBJ_))

#endif // _MEMORY_H



