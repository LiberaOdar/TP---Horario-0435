#include <iostream>

#include "Biblioteca/Funciones.h"
using namespace std;

int main() {
    char cadena[100]="P222-555/G111-111/A444-555/D52F-350";
    char nueva[20]="GCCK-673";
    char placa[20];
    int arrDNI[100]{},n;
    leeinfracciones(arrDNI,n);
    obtenerPlaca(cadena,1,placa);

    cout << placa << endl;
    return 0;
}
