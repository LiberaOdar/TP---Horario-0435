//
// Created by cueva.r on 10/06/2026.
//

#ifndef MIPRIMERSTRUCT_FUNCIONES_H
#define MIPRIMERSTRUCT_FUNCIONES_H
#include <fstream>
#include "Medico.h"
using namespace std;
    char*leecadena(ifstream &arch,char deli);
    void leemedicos(Medico *arrmedico,const char*nombre);
    void imprimedicos(Medico *arrmedico,const char*nombre);
#endif //MIPRIMERSTRUCT_FUNCIONES_H