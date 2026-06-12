//
// Created by cueva.r on 10/06/2026.
//

#ifndef MIPRIMERSTRUCT_MEDICO_H
#define MIPRIMERSTRUCT_MEDICO_H
#include "Fecha.h"
    struct Medico {
        int codigo;
        char nombre[100];
        double tarifa;
        Fecha fecha;
    };
#endif //MIPRIMERSTRUCT_MEDICO_H