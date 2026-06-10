#include "Biblioteca/Funciones.h"

int main() {
    char*catcod[150]{},*catnom[150]{};

    leecategoria(catcod,catnom,"Categorias.txt");
    generareportes(catcod,catnom);

    return 0;
}