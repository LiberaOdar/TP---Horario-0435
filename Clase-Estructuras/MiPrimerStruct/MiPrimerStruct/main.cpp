#include <cstring>
#include <iostream>

#include "Biblioteca/Funciones.h"
#include "Biblioteca/Medico.h"
using namespace std;

int main() {
    Medico stmedico1;
    Medico stmedico2{7777,"Chaparro",100};
    Medico arrstmedico[50]{};

    leemedicos(arrstmedico,"medicos.csv");
    imprimedicos(arrstmedico,"reporte.txt");
    ///////////////////////////////////
    stmedico1.codigo = 5555;
    stmedico1.tarifa = 99.50;
    strcpy(stmedico1.nombre, "Dolores");

    cout << stmedico1.codigo << endl;
    cout << stmedico1.nombre << endl;
    cout << stmedico1.tarifa << endl;
///////////////////////////////////////////////
    arrstmedico[0].codigo = 5555;
    arrstmedico[0].tarifa = 99.50;
    strcpy(arrstmedico[0].nombre, "Dolores");
    cout << "Con arreglo:"<<endl;
    cout << arrstmedico[0].codigo << endl;
    cout << arrstmedico[0].nombre[0] << endl;
    cout << arrstmedico[0].tarifa << endl;


    return 0;
}