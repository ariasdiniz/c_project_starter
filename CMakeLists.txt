cmake_minimum_required(VERSION 3.15)

project(cgen)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3")

file(GLOB_RECURSE SOURCE "src/*.c" "src/*.h")
file(GLOB_RECURSE LIB "lib/*.c" "lib/*.h")

add_executable(
                cgen
                main.c
                ${SOURCE}
                ${LIB})

include_directories(src)
include_directories(lib)
