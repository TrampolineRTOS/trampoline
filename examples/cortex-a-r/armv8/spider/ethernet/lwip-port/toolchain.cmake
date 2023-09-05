set(CMAKE_SYSTEM_NAME Generic)

set(CMAKE_C_COMPILER "arm-none-eabi-gcc")

set(CMAKE_C_FLAGS "-std=c99 -mcpu=cortex-r52 -mfloat-abi=soft -O0 -g")
set(CMAKE_EXE_LINKER_FLAGS "-nostdlib")

set(LWIP_COMPILER_FLAGS -std=c99 -mcpu=cortex-r52 -mfloat-abi=soft -O0 -g)

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

set(LWIP_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set (LWIP_INCLUDE_DIRS
    "${LWIP_DIR}/src/include"
    "${LWIP_DIR}/../lwip-port"
    "${LWIP_DIR}/.."
)
