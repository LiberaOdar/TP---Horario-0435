cmake_minimum_required(VERSION 4.0)
project(Cadenas)

set(CMAKE_CXX_STANDARD 20)

add_executable(Cadenas main.cpp
        Biblioteca/Funciones_Cadenas.cpp
        Biblioteca/Funciones_Cadenas.h)
