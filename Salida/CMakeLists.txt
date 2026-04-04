cmake_minimum_required(VERSION 4.0)
project(Salida)

set(CMAKE_CXX_STANDARD 20)

add_executable(Salida main.cpp
        MiBiblioteca/Funciones.cpp
        MiBiblioteca/Funciones.h)
