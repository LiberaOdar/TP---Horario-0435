//
// Created by cueva on 11/06/2026.
//

#ifndef ESTRUCTURAS_FUNCIONES_H
#define ESTRUCTURAS_FUNCIONES_H
#include <fstream>
#include "EmpresasRegistradas.h"
#include "Fecha.h"
using namespace std;
int leeempresas(EmpresasRegistradas *arrempresas,const char*nombre);
char*leecadena(ifstream &arch,char deli);
void intercambio(EmpresasRegistradas &stri,EmpresasRegistradas &strj);
void ordenaintercambio(EmpresasRegistradas *arreglo,int n);
int buscarempresa(EmpresasRegistradas *arreglo,int dni);
void insertaplaca(char *placa, EmpresasRegistradas &strempresa);
void leeplacas(EmpresasRegistradas *arreglo,const char*nombre);
#endif //ESTRUCTURAS_FUNCIONES_H
