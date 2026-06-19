#include "Biblioteca/Conductor.h"
#include "Biblioteca/Funciones.h"
#include "Biblioteca/Infraccion.h"
#include "Biblioteca/Vehiculo.h"

int main() {
    Vehiculo *vehiculos=new Vehiculo[160]{};
    Infraccion *infracciones=new Infraccion[160]{};
    Conductor *conductores=new Conductor[120]{};

    leerVehiculos(vehiculos,"vehiculos.csv");


    return 0;
}
