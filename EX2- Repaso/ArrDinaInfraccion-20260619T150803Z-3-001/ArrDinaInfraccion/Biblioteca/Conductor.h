//
// Created by cueva.r on 17/06/2026.
//

#ifndef ARRDINAINFRACCION_CONDUCTOR_H
#define ARRDINAINFRACCION_CONDUCTOR_H
#include "Infraccion.h"
#include "Vehiculo.h"

struct Conductor {
    int dni;
    char *nombre;
    char *apellido;
    char *licencia;
    Vehiculo vehiculo;
    Infraccion *infracciones;
    int cantidad_infracciones;
};

#endif //ARRDINAINFRACCION_CONDUCTOR_H