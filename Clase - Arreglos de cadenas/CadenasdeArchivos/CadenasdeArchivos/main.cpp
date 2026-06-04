#include "Biblioteca/Funciones.h"


int main() {
    char* nombres[100]{}; //inic. con nullptr

    leearchivo(nombres);
    imprimirarreglo(nombres);
    libera(nombres);
    return 0;
}