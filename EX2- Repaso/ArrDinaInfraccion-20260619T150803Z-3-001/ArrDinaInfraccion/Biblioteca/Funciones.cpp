//
// Created by cueva.r on 17/06/2026.
//

#include "Funciones.h"

#include <cstring>
#include <fstream>
#include <iostream>

#include "Conductor.h"
#include "Infraccion.h"
#include "Vehiculo.h"
using namespace std;

void leerVehiculos(Vehiculo *arrvehiculos,const char*nombre) {
    ifstream arch(nombre,ios::in);
    if (not arch.is_open()) {
        cout<<"Error al abrir el archivo "<<nombre<<endl;
        exit(1);
    }
    int i=0;
    while (true) {
        arch>>arrvehiculos[i].dni_propietario;
        if (arch.eof()) break;
        arch.get();
        arrvehiculos[i].placa=leercadenaexacta(arch,10,',');
        arrvehiculos[i].marca_modelo=leercadenaexacta(arch,50,'\n');
        i++;
    }
}

void leeInfracciones(Infraccion *arrinfracciones,const char*nombre) {
    ifstream arch(nombre,ios::in);
    if (not arch.is_open()) {
        cout<<"Error al abrir el archivo "<<nombre<<endl;
        exit(1);
    }
    int i=0;
    char c;
    while (true) {
        arch>>arrinfracciones[i].dni_conductor;
        if (arch.eof())break;
        arch.get();
        int aa,mm,dd;
        arch>>dd>>c>>mm>>c>>aa>>c;
        arrinfracciones[i].fecha_infraccion.dd=dd;
        arrinfracciones[i].fecha_infraccion.mm=mm;
        arrinfracciones[i].fecha_infraccion.aa=aa;
        arrinfracciones[i].fecha_infraccion.aammdd=aa*10000+mm*100+dd;
        arrinfracciones[i].codigo=leercadenaexacta(arch,5,',');
        arrinfracciones[i].descripcion=leercadenaexacta(arch,50,',');
        arrinfracciones[i].gravedad=leercadenaexacta(arch,50,',');
        arch >> arrinfracciones[i].monto;
        if (arrinfracciones[i].codigo[0]=='C')
            arrinfracciones[i].monto*=1.2;
        i++;
    }
}
void leeConductores(Conductor *arrconductores,const char*nombre) {
    ifstream arch(nombre,ios::in);
    if (not arch.is_open()) {
        cout<<"Error al abrir el archivo "<<nombre<<endl;
        exit(1);
    }
    int i=0;
    while (true) {
        arch >> arrconductores[i].dni;
        if (arch.eof())break;
        arch.get();
        arrconductores[i].nombre=leercadenaexacta(arch,50,',');
        arrconductores[i].apellido=leercadenaexacta(arch,50,',');
        arrconductores[i].licencia=leercadenaexacta(arch,10,'\n');
        arrconductores[i].infracciones=new Infraccion[10]{};
        i++;
    }
}

void actualizaconductor(Conductor *arrcond,
    Vehiculo *arrveh,Infraccion *arrinfra) {
    for (int i=0;arrcond[i].dni!=0;i++) {
        asignavehiculo(arrcond[i],arrveh);
//        asignainfracciones(arrcond[i],arrinfra);
    }
}

void asignavehiculo(Conductor &cond,Vehiculo *arrveh) {
    int pos=buscavehiculo(cond.dni,arrveh);
    if (pos!=-1) {
        cond.vehiculo=arrveh[pos];
    }

}

int buscavehiculo(int dni,Vehiculo *arrveh) {
    for (int i=0;arrveh[i].dni_propietario!=0;i++)
        if (dni==arrveh[i].dni_propietario)
            return i;
    return -1;
}

char *leercadenaexacta(ifstream &arch,int max,char deli) {
    char cad[max],*pt;
    arch.getline(cad,max,deli);
    if (arch.eof()) return nullptr;
    pt=new char[strlen(cad)+1];
    strcpy(pt,cad);
    return pt;
}
