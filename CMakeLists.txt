cmake_minimum_required(VERSION 3.16)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

set(CMAKE_BUILD_PARALLEL_LEVEL 8)

project(E2I4_INDUS VERSION 1.0 LANGUAGES C ASM)

add_compile_definitions(
    "STM32F446xx"
)

add_compile_options(
    "-mcpu=cortex-m4"
    "-mthumb"
    #"-mfpu=fpv4-sp-d16"
    "-mfloat-abi=hard"

    "-fdata-sections"
    "-ffunction-sections"

    "-Wall"

    $<$<CONFIG:Debug>:-Og>
)

add_link_options(
    "-T${CMAKE_SOURCE_DIR}/STM32-files/stm32_flash.ld"
    "-mcpu=cortex-m4"
    "-mthumb"
    #"-mfpu=fpv4-sp-d16"
    "-mfloat-abi=hard"

    "-lc"
    "-lm"
    "-lnosys"
    "-Wl,-Map=${PROJECT_NAME}.map,--cref"
    "-Wl,--gc-sections"
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


file(GLOB TP_dirs CONFIGURE_DEPENDS "TP*")

foreach(TP_dir ${TP_dirs})
    file(GLOB Exo_dirs CONFIGURE_DEPENDS "${TP_dir}/*")

    foreach(Exo_dir ${Exo_dirs})
        add_subdirectory(${Exo_dir})
    endforeach()
endforeach()