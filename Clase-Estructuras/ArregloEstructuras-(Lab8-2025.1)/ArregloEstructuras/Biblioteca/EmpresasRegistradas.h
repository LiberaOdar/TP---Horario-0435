//
// Created by cueva.r on 12/06/2026.
//

#ifndef ARREGLOESTRUCTURAS_EMPRESASREGISTRADAS_H
#define ARREGLOESTRUCTURAS_EMPRESASREGISTRADAS_H
#include "Fecha.h"

struct EmpresasRegistradas {
    int dni;
    char* nombre;
    char*distrito;
    char *placas[10];
    int numPlacas;
    Fecha fechaDeInfraccion;
    Fecha fechaDePago;
    double totalDeMultas;
    double totalPagado;
    int cantidadDeFaltas;
};

#endif //ARREGLOESTRUCTURAS_EMPRESASREGISTRADAS_H