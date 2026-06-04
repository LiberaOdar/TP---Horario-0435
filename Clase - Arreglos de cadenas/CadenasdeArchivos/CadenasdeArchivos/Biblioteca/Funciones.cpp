//
// Created by cueva.r on 3/06/2026.
//

#include "Funciones.h"

#include <fstream>
#include <iomanip>
#include <cstring>
#include <iostream>

using namespace std;

void leearchivo(char **arreglo) {
    int i=0;
    ifstream arch("archivo.txt",ios::in);
    if (not arch) {
        cout << "Error al abrir el archivo.txt" << endl;
        exit(1);
    }
    while (true) {
        arreglo[i]=leecadena(arch,'\n');
        if (arch.eof())break;
        i++;
    }
}
/*
Carlos Enrique
Marco Aurelio
Mamut Pascal
*/
char*leecadena(ifstream &arch,char deli) {
    char cad[100],*pcad;
    arch.getline(cad,100,deli);
    if (arch.eof()) return nullptr;
    pcad=new char[strlen(cad)+1];
    strcpy(pcad,cad);
    return pcad;
}
void imprimirarreglo(char **arreglo) {
    ofstream arch("reporte.txt",ios::out);
    if (not arch) {
        cout << "Error al abrir el reporte.txt" << endl;
        exit(1);
    }
    for (int i=0;arreglo[i]!=nullptr;i++)
        arch<<left<<setw(4)<<i+1<<setw(20)<<arreglo[i]<<endl;

}

void libera(char **arreglo) {
    for (int i=0;arreglo[i]!=nullptr;i++)
        delete arreglo[i];

}