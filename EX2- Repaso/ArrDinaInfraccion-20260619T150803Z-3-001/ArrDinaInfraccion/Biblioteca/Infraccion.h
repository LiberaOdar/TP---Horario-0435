//
// Created by cueva.r on 17/06/2026.
//

#ifndef ARRDINAINFRACCION_INFRACCION_H
#define ARRDINAINFRACCION_INFRACCION_H
#include "Fecha.h"

struct Infraccion {
        Fecha fecha_infraccion;
        char *codigo;
        char* descripcion;
        char* gravedad;
        double monto;
        int dni_conductor;
    };



#endif //ARRDINAINFRACCION_INFRACCION_H