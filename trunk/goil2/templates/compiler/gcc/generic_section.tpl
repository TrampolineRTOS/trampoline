/*
 * $OBJ$ $NAME$ section for type $KIND$$SUBKIND$ of size $SIZE$
 */
#ifdef APP_$OBJ$_$NAME$_START_$CONT$_$KIND$$SUBKIND$$SIZE$
  #undef APP_$OBJ$_$NAME$_START_$CONT$_$KIND$$SUBKIND$$SIZE$
  #ifdef CURRENT_LINKER_$TYPE$_SECTION
    #error "Starting a new section while a section is already started"
  #else
    #undef MEMMAP_ERROR
    #undef CURRENT_LINKER_$TYPE$_SECTION_NAME
    #define CURRENT_LINKER_$TYPE$_SECTION_NAME __attribute__ ((section (".$OBJ$_$NAME$$CONT$$KIND$$SUBKIND$$SIZE$")))
    #define CURRENT_LINKER_$TYPE$_SECTION
  #endif
#endif
#ifdef APP_$OBJ$_$NAME$_STOP_$CONT$_$KIND$$SUBKIND$$SIZE$
	#undef APP_$OBJ$_$NAME$_STOP_$CONT$_$KIND$$SUBKIND$$SIZE$
  #ifdef CURRENT_LINKER_$TYPE$_SECTION
    #undef MEMMAP_ERROR
    #undef CURRENT_LINKER_$TYPE$_SECTION
    #undef CURRENT_LINKER_$TYPE$_SECTION_NAME
    #define CURRENT_LINKER_$TYPE$_SECTION_NAME
  #else
    #error "No section started"
  #endif
#endif

