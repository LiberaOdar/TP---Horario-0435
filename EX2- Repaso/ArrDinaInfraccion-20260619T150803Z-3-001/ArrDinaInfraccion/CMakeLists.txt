cmake_minimum_required(VERSION 4.0)
project(ArrDinaInfraccion)

set(CMAKE_CXX_STANDARD 20)

add_executable(ArrDinaInfraccion main.cpp
        Biblioteca/Vehiculo.h
        Biblioteca/Fecha.h
        Biblioteca/Conductor.h
        Biblioteca/Funciones.cpp
        Biblioteca/Funciones.h
        Biblioteca/Infraccion.h
)
