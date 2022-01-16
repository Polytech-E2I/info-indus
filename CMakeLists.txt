cmake_minimum_required(VERSION 3.16)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

set(CMAKE_BUILD_PARALLEL_LEVEL 8)

project(E2I4_INDUS VERSION 1.0 LANGUAGES C ASM)

add_compile_definitions(
    "STM32F446xx"
)

set(ARCHFLAGS
    -mtune=cortex-m4
    -mthumb
    -march=armv7e-m
    -mfloat-abi=hard
    -mfpu=fpv4-sp-d16
)

add_compile_options(
    ${ARCHFLAGS}

    -fsingle-precision-constant

    -Wall
    -Wdouble-promotion

    -O0
    -Os
)

add_link_options(
    -T${CMAKE_SOURCE_DIR}/STM32-files/stm32_flash.ld

    ${ARCHFLAGS}

    -Wl,--gc-sections
)

include_directories(
    "STM32-files/"
    "STM32-files/cmsis_lib/include/"
    "STM32-files/Polytech-library/inc/"
    "STM32-files/Drivers/CMSIS/Include"
    "STM32-files/Drivers/CMSIS/Device/ST/STM32F4xx/Include/"
)

add_subdirectory("STM32-files/Polytech-library")
add_subdirectory("STM32-files/cmsis_lib")

set(STM32_SCRIPTS_DIR ${CMAKE_SOURCE_DIR}/STM32-files/scripts)
set(STM32_LOAD_CMD ${STM32_SCRIPTS_DIR}/stm32-load)
set(STM32_DBG_CMD ${STM32_SCRIPTS_DIR}/stm32-gdb)

file(GLOB TP_dirs CONFIGURE_DEPENDS "TP*")

foreach(TP_dir ${TP_dirs})
    file(GLOB Exo_dirs CONFIGURE_DEPENDS "${TP_dir}/*")

    foreach(Exo_dir ${Exo_dirs})
        add_subdirectory(${Exo_dir})
    endforeach()
endforeach()