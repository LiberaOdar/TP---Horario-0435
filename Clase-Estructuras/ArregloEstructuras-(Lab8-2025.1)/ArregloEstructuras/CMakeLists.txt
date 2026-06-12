cmake_minimum_required(VERSION 4.0)
project(ArregloEstructuras)

set(CMAKE_CXX_STANDARD 20)

add_executable(ArregloEstructuras main.cpp
        Biblioteca/Funciones.cpp
        Biblioteca/EmpresasRegistradas.h
        Biblioteca/Fecha.h)
