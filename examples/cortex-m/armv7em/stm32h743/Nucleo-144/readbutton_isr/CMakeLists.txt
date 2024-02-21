#to compile the project:
# mkdir _build
# cd _build
# cmake -D CMAKE_TOOLCHAIN_FILE=../readbutton_isr/compiler.cmake ..
# make
# make flash
cmake_minimum_required(VERSION 3.5)

# with this option, cmake will not try to compile a 
# simple test program (that may fail for an embedded target)
set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")

#project name
project(readbutton_isr_exe)
enable_language(C CXX ASM)


set(TRAMPOLINE_BASE_PATH ${CMAKE_SOURCE_DIR}/../../../../../..)
set(TRAMPOLINE_MACHINE_PATH ${TRAMPOLINE_BASE_PATH}/machines)
set(TRAMPOLINE_GOIL_TEMPLATES ${TRAMPOLINE_BASE_PATH}/goil/templates)
set(APP_GENERATED_PATH ${CMAKE_SOURCE_DIR}/readbutton_isr)

#goil
set(OILFILE ${CMAKE_SOURCE_DIR}/readbutton_isr.oil)
set(OILCOMPILER goil)
set(OILFLAGS -t=cortex-m/armv7em/stm32h743 --templates=${TRAMPOLINE_GOIL_TEMPLATES})

#cross compiler
include("readbutton_isr/compiler.cmake")

set(CFLAGS #CFLAGS
	#C flags from target options
	--specs=nosys.specs
	#C flags from .oil file
	-O0
)

set(PRECFLAGS #PRE CFLAGS
	#PRE C flags from target options
)

set(CXXFLAGS #C++ FLAGS
	#C++ flags from target options
	-fno-rtti
	-felide-constructors
	-fno-threadsafe-statics
	-fno-use-cxa-get-exception-ptr
	-fno-enforce-eh-specs
)

set(PRECXXFLAGS #PRE C++ FLAGS
	#PRE C++ flags from target options
)

set(COMMONFLAGS #COMMON FLAGS (C/C++/ASM)
	#common flags from target options
	-mcpu=cortex-m7
	-mthumb
	-mfloat-abi=soft
	-mfpu=fpv5-d16
	-DSTM32H743xx
	-g
	-Wno-unused-but-set-variable
	-Wmissing-field-initializers
	-nostartfiles
	-fno-builtin
	-fno-exceptions
	-nostdlib
	-ffunction-sections
	-fdata-sections
)

set(PRECOMMONFLAGS #PRE COMMON FLAGS (C/C++/ASM)
	#PRE common flags from target options
)

add_compile_options(
  ${PRECOMMONFLAGS}
  ${COMMONFLAGS}
  "$<$<COMPILE_LANGUAGE:C>:${PRECFLAGS}>"
  "$<$<COMPILE_LANGUAGE:C>:${CFLAGS}>"
  "$<$<COMPILE_LANGUAGE:CXX>:${PRECXXFLAGS}>"
  "$<$<COMPILE_LANGUAGE:CXX>:${CXXFLAGS}>"
  "$<$<COMPILE_LANGUAGE:ASM>:${PRECFLAGS}>"
  "$<$<COMPILE_LANGUAGE:ASM>:${CFLAGS}>"
)

#Application sources
set(APP_SRCS
	#--- C files of the application
	readbutton_isr.c
)

#Trampoline kernel sources 
set(TRAMPOLINE_OS_SRCS
	${TRAMPOLINE_BASE_PATH}/os/tpl_os_kernel.c
	${TRAMPOLINE_BASE_PATH}/os/tpl_os_timeobj_kernel.c
	${TRAMPOLINE_BASE_PATH}/os/tpl_os_action.c
	${TRAMPOLINE_BASE_PATH}/os/tpl_os_error.c
	${TRAMPOLINE_BASE_PATH}/os/tpl_os_os_kernel.c
	${TRAMPOLINE_BASE_PATH}/os/tpl_os_os.c
	${TRAMPOLINE_BASE_PATH}/os/tpl_os_interrupt_kernel.c
	${TRAMPOLINE_BASE_PATH}/os/tpl_os_task_kernel.c
	${TRAMPOLINE_BASE_PATH}/os/tpl_os_resource_kernel.c
	${TRAMPOLINE_BASE_PATH}/os/tpl_os_alarm_kernel.c
) 

#Trampoline generated files
set(APP_GENERATED_SRCS
	#os generated files
	${APP_GENERATED_PATH}/tpl_app_config.c
	${APP_GENERATED_PATH}/tpl_dispatch_table.c
	${APP_GENERATED_PATH}/tpl_invoque.S
	#platform dependant generated files
	${APP_GENERATED_PATH}/tpl_primary_irq.S
	${APP_GENERATED_PATH}/tpl_vectors.c
	${APP_GENERATED_PATH}/tpl_external_interrupts.c
	${APP_GENERATED_PATH}/tpl_app_interrupts.c
)

#Trampoline target dependant files
set(TRAMPOLINE_MACHINE_SRCS
	${TRAMPOLINE_MACHINE_PATH}/cortex-m/tpl_machine_cortex.c
	${TRAMPOLINE_MACHINE_PATH}/cortex-m/tpl_sc_handler.S
	${TRAMPOLINE_MACHINE_PATH}/cortex-m/tpl_startup.S
	${TRAMPOLINE_MACHINE_PATH}/cortex-m/armv7em/tpl_ctx_switch.S
	${TRAMPOLINE_MACHINE_PATH}/cortex-m/armv7em/tpl_ctx_switch_under_it.S
	${TRAMPOLINE_MACHINE_PATH}/cortex-m/armv7em/tpl_interrupts.S
	${TRAMPOLINE_MACHINE_PATH}/cortex-m/armv7em/stm32h743/lib/pinAccess.c
	${TRAMPOLINE_MACHINE_PATH}/cortex-m/armv7em/stm32h743/handlers_stm32h743.c
	${TRAMPOLINE_MACHINE_PATH}/cortex-m/armv7em/stm32h743/startup_stm32h743.c
	${TRAMPOLINE_MACHINE_PATH}/cortex-m/armv7em/stm32h743/system_stm32h7xx.c
	${TRAMPOLINE_MACHINE_PATH}/cortex-m/armv7em/stm32h743/tpl_machine_stm32h743.c
	${TRAMPOLINE_MACHINE_PATH}/cortex-m/armv7em/stm32h743/tpl_trace.c
)

# Trampoline target library sources (drivers)
set(TARGET_LIBRARY_SRCS
)

#Include directories
include_directories(
	${TRAMPOLINE_BASE_PATH}/com
	${TRAMPOLINE_BASE_PATH}/debug
	${TRAMPOLINE_BASE_PATH}/ioc
	${TRAMPOLINE_BASE_PATH}/os
	${TRAMPOLINE_MACHINE_PATH}/cortex-m
	${TRAMPOLINE_MACHINE_PATH}/cortex-m/CMSIS/Include
	${TRAMPOLINE_MACHINE_PATH}/cortex-m/armv7em
	${TRAMPOLINE_MACHINE_PATH}/cortex-m/armv7em/stm32h743
	${TRAMPOLINE_MACHINE_PATH}/cortex-m/armv7em/stm32h743/CMSIS/Device/ST/STM32H7xx/Include
	${TRAMPOLINE_MACHINE_PATH}/cortex-m/armv7em/stm32h743/lib
	readbutton_isr
)

#Executable (should be defined after compile options)
add_executable(${PROJECT_NAME} 
    ${APP_SRCS}
    ${TRAMPOLINE_OS_SRCS}
    ${APP_GENERATED_SRCS}
	${TARGET_LIBRARY_SRCS}
    ${TRAMPOLINE_MACHINE_SRCS}
)

#Linker
set(LINKER_DIR ${APP_GENERATED_PATH})
set(LINKER_SCRIPT script.ld)
set(LINKER_FLAGS 
	#linker flags from target options
	--fatal-warnings
	--warn-common
	--no-undefined
	--gc-sections
	#linker flags from .oil file
	-Map=readbutton_isr.map
	#link script
	-L${LINKER_DIR}
 -T${LINKER_SCRIPT}
)

#
function(add_gcc_library libCmd)
  #use gcc to get the full path to libs (libgcc, libc)
  execute_process(
    COMMAND ${CMAKE_C_COMPILER} ${PRECOMMONFLAGS} ${PRECFLAGS} ${COMMONFLAGS} ${CFLAGS} ${libCmd}
    RESULT_VARIABLE returnValue
    OUTPUT_VARIABLE full_lib_path
    OUTPUT_STRIP_TRAILING_WHITESPACE)

  if (${returnValue} EQUAL 0)
    #ok, now extract only the directory
    get_filename_component(libgcc_path ${full_lib_path} DIRECTORY)
    set(libpath ${libgcc_path} PARENT_SCOPE)
  else()
    message("library ${libCmd} not found!")
  endif()
endfunction()

if(${CMAKE_C_COMPILER_ID} STREQUAL "GNU")
	add_gcc_library("-print-libgcc-file-name") #try to find libgcc
	list(APPEND LINKER_FLAGS -L${libpath} -lgcc)
	add_gcc_library("-print-file-name=libc.a") #try to find libc
	list(APPEND LINKER_FLAGS -L${libpath} -lc)
endif()

#should be defined after 'add_executable'
target_link_libraries(${PROJECT_NAME}
	${LINKER_FLAGS}
)

set_property(TARGET ${PROJECT_NAME} 
    PROPERTY LINK_DEPENDS ${LINKER_DIR}/${LINKER_SCRIPT}
)

#post build commands (bin file, flash, …)
# POSTBUILD rules
add_custom_command(OUTPUT ${PROJECT_NAME}.bin
    DEPENDS ${PROJECT_NAME}
    COMMAND ${CMAKE_OBJCOPY} -O binary ${PROJECT_NAME} ${PROJECT_NAME}.bin
	WORKING_DIRECTORY ${CMAKE_BUILD_DIR}
)

# POSTCOMMAND rules
add_custom_target(burn
	DEPENDS ${PROJECT_NAME}.bin
	COMMAND st-flash write ${PROJECT_NAME}.bin 0x8000000
)


#TODO: add alias avec dependance.
#add_custom_target(burn
#    DEPENDS flash
#)

#goil (will update generated files, and depends on .oil input file)
add_custom_command(OUTPUT ${APP_GENERATED_SRCS} 
    DEPENDS ${OILFILE}
    COMMAND ${OILCOMPILER} ${OILFLAGS} ${OILFILE}
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR} #build dir
    COMMENT "call Goil (.oil to code source)"
)

