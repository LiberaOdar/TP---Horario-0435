//
// Created by cueva.r on 3/06/2026.
//

#ifndef CADENASDEARCHIVOS_FUNCIONES_H
#define CADENASDEARCHIVOS_FUNCIONES_H
#include <fstream>
using namespace std;
    void leearchivo(char **arreglo);
    char*leecadena(ifstream &arch,char deli);
    void imprimirarreglo(char **arreglo);
    void libera(char **arreglo);
#endif //CADENASDEARCHIVOS_FUNCIONES_H