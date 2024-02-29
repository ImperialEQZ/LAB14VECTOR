cmake_minimum_required(VERSION 3.26)
project(LAB14Vector C)

set(CMAKE_C_STANDARD 11)

add_executable(LAB14Vector main.c
        vector.h
        vector.c
        vectorVoid.h
        vectorVoid.c)
