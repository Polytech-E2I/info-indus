cmake_minimum_required(VERSION 3.19)

file(GLOB files_src CONFIGURE_DEPENDS "include/*.h" "source/*.c")

add_library(cmsis_lib
    ${files_src}
)