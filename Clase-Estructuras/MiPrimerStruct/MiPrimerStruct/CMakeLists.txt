cmake_minimum_required(VERSION 4.0)
project(MiPrimerStruct)

set(CMAKE_CXX_STANDARD 20)

add_executable(MiPrimerStruct main.cpp
        Biblioteca/Medico.h
        Biblioteca/Funciones.cpp
        Biblioteca/Funciones.h
        Biblioteca/Fecha.h)
