cmake_minimum_required(VERSION 3.19)

file(GLOB files_src CONFIGURE_DEPENDS "inc/*.h" "src/*.c")

add_library(Polytech-library
    ${files_src}
)