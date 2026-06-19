//
// Created by cueva.r on 17/06/2026.
//

#ifndef ARRDINAINFRACCION_FUNCIONES_H
#define ARRDINAINFRACCION_FUNCIONES_H
#include <fstream>
#include "Conductor.h"
#include "Vehiculo.h"

using namespace  std;
    char *leercadenaexacta(ifstream &arch,int max,char deli);
    void leerVehiculos(Vehiculo *arrvehiculos,const char*nombre);
    void asignavehiculo(Conductor &cond,Vehiculo *arrveh);
    int buscavehiculo(int dni,Vehiculo *arrveh);
#endif //ARRDINAINFRACCION_FUNCIONES_H