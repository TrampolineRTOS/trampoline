/*
 * OS section for type $KIND$$SUBKIND$ of size $SIZE$
 */
#ifdef OS_START_$CONT$_$KIND$$SUBKIND$$SIZE$
  #undef OS_START_$CONT$_$KIND$$SUBKIND$$SIZE$
  #ifdef CURRENT_LINKER_$TYPE$_SECTION
    #error "Starting a $SECTION$ while a section is already started"
  #else
    #undef MEMMAP_ERROR
    #pragma ghs section $SECTION_KIND$="$SECTION$"
    #define CURRENT_LINKER_$TYPE$_SECTION
  #endif
#endif

#ifdef OS_STOP_$CONT$_$KIND$$SUBKIND$$SIZE$
	#undef OS_STOP_$CONT$_$KIND$$SUBKIND$$SIZE$
  #ifdef CURRENT_LINKER_$TYPE$_SECTION
    #undef MEMMAP_ERROR
    #undef CURRENT_LINKER_$TYPE$_SECTION
  #else
    #error "No section $SECTION$ started"
  #endif
#endif

