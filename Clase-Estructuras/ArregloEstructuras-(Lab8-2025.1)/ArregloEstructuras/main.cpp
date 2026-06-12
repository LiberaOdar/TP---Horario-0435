#include <iostream>

#include "Biblioteca/EmpresasRegistradas.h"
#include "Biblioteca/Funciones.h"

int main() {
    int numdat;
    EmpresasRegistradas arrEmpresasRegistradas[50]{};

    numdat=leeempresas(arrEmpresasRegistradas,"EmpresasRegistradas.csv");
    leeplacas(arrEmpresasRegistradas,"PlacasRegistradas.csv");
    ordenaintercambio(arrEmpresasRegistradas,numdat);

    return 0;
}
