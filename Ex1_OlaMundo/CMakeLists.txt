cmake_minimum_required(VERSION 3.21)
project(Ex1_OlaMundo C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Ex1_OlaMundo
        "Ola mundo.c")
