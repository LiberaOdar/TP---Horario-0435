cmake_minimum_required(VERSION 4.0)
project(NombresDinamicos)

set(CMAKE_CXX_STANDARD 20)

add_executable(NombresDinamicos main.cpp
        Biblioteca/Funciones.cpp
        Biblioteca/Funciones.h)
