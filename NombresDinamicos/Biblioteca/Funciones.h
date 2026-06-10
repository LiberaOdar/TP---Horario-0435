//
// Created by cueva.r on 5/06/2026.
//

#ifndef NOMBRESDINAMICOS_FUNCIONES_H
#define NOMBRESDINAMICOS_FUNCIONES_H
#include <fstream>
using namespace std;
    char*leecadena(ifstream &arch,char deli);
    void generaArchivoEnlace(const char *categoria,
        char *nombArch, char *enlace);
    void generareportes(char **catcod,char **catnom);
    void leecategoria(char **catcod,char **catnom,const char*nombre);
#endif //NOMBRESDINAMICOS_FUNCIONES_H