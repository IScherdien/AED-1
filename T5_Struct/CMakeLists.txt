cmake_minimum_required(VERSION 3.21)
project(T5_Struct C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(T5_Struct
        biblioteca.c
        biblioteca.h
        main.c)
