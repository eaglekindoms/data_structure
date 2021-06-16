cmake_minimum_required(VERSION 3.19)
project(data_structure C CXX)

include_directories(data_struct/common)
set(CMAKE_C_STANDARD 99)
#add_compile_options(-fexec-charset=utf-8)

add_subdirectory(data_algo)
add_subdirectory(data_struct)

add_executable(main01 main.c)