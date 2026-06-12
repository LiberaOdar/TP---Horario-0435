//
// Created by cueva.r on 10/06/2026.
//
#include "Funciones.h"
#include <iomanip>
#include <iostream>
#include <cstring>

using namespace std;

void leemedicos(Medico *arrmedico,const char*nombre) {
    ifstream arch(nombre,ios::in);
    if (not arch) {
        cout<<"Error al abrir archivo "<< nombre <<endl;
        exit(1);
    }
    int i=0;
    char c;
    //737393,Paul Matasanos,93.0
    while (true) {
        arch>>arrmedico[i].codigo;
        if (arch.eof())break;
        arch>>c;
        arch.getline(arrmedico[i].nombre,100,',');
        arch >> arrmedico[i].tarifa>>c;
        arch >> arrmedico[i].fecha.dia>>c;
        arch >> arrmedico[i].fecha.mes>>c;
        arch >> arrmedico[i].fecha.year;
        i++;
    }

}

void imprimedicos(Medico *arrmedico,const char*nombre) {
    ofstream arch(nombre,ios::out);
    if (not arch) {
        cout<<"Error al abrir archivo "<< nombre <<endl;
        exit(1);
    }
    for (int i=0;arrmedico[i].codigo;i++) {
        arch<<left<<setw(10)<<arrmedico[i].codigo<<" ";
        arch<<setw(20)<<arrmedico[i].nombre<<endl;
    }
}