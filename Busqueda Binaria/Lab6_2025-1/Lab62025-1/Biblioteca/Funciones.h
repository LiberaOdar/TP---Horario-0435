//
// Created by cueva on 28/05/2026.
//

#ifndef LAB62025_1_FUNCIONES_H
#define LAB62025_1_FUNCIONES_H
#include <fstream>
using namespace std;


int leefecha(ifstream &arch);
void insertaordenado(int dni,int*arrDNI,int &numdato);
void leeinfracciones(int *arrDNI,int& );
void reportemultas(int *arrDNI,int numdat);
int buscarbinario(int dni,int *arrDNI,int numdat);
void obtenerPlaca(const char*listaDePlacas,int n,
    char *placa);
#endif //LAB62025_1_FUNCIONES_H