//
// Created by cueva on 11/06/2026.
//

#include "Funciones.h"
#include <iostream>
#include <cstring>

using namespace std;
// 79672079,contreras chang johana cinthia,Chorrillos
// 77763722,farfan salazar margot,La Molina
int leeempresas(EmpresasRegistradas *arrempresas,const char*nombre) {
    ifstream arch(nombre,ios::in);
    if (not arch) {
        cout << "No se puede abrir el archivo "<< nombre << endl;
        exit(1);
    }
    int i=0;
    while (true) {
        arch >> arrempresas[i].dni;
        if (arch.eof())break;
        arch.get();
        arrempresas[i].nombre=leecadena(arch,',');
        arrempresas[i].distrito=leecadena(arch,'\n');
        i++;
    }
    return i;
}

void ordenaintercambio(EmpresasRegistradas *arreglo,int n) {

    for (int i=0;i<n-1;i++)
        for (int j=i+1;j<n;j++)
            if (strcmp(arreglo[i].distrito,arreglo[j].distrito)>0)
                intercambio(arreglo[i],arreglo[j]);
}
//12443643,M421-807
//90467829,P985-495
void leeplacas(EmpresasRegistradas *arreglo,const char*nombre) {
    ifstream arch(nombre,ios::in);
    if (not arch) {
        cout << "No se puede abrir el archivo "<< nombre << endl;
        exit(1);
    }
    int dni;
    char *placa;
    while (true) {
        arch >> dni;
        if (arch.eof())break;
        int ind=buscarempresa(arreglo,dni);
        if (ind!=-1) {
            arch.get();
            placa=leecadena(arch,'\n');
            insertaplaca(placa,arreglo[ind]);
        }
        else
            while (arch.get()!='\n');
    }
}

void insertaplaca(char *placa, EmpresasRegistradas &strempresa) {
    strempresa.placas[strempresa.numPlacas]=placa;
    strempresa.numPlacas++;
}

int buscarempresa(EmpresasRegistradas *arreglo,int dni) {
    for (int i=0;arreglo[i].dni!=0;i++)
        if (arreglo[i].dni==dni)
            return i;
    return -1;
}

void intercambio(EmpresasRegistradas &stri,EmpresasRegistradas &strj) {
    EmpresasRegistradas aux;
    aux=stri;
    stri=strj;
    strj=aux;
}


char*leecadena(ifstream &arch,char deli) {
    char cad[100],*pcad;
    arch.getline(cad,100,deli);
    if (arch.eof()) return nullptr;
    pcad=new char[strlen(cad)+1];
    strcpy(pcad,cad);
    return pcad;
}


