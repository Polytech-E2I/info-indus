cmake_minimum_required(VERSION 3.16)

if(${CMAKE_VERSION} VERSION_LESS 3.12)
    cmake_policy(VERSION ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION})
endif()

get_filename_component(Foldername ${CMAKE_CURRENT_SOURCE_DIR} NAME)

file(GLOB files_src CONFIGURE_DEPENDS "*.h" "*.c")

add_executable(${Foldername} ${files_src})