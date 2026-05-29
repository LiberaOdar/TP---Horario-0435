//
// Created by cueva on 28/05/2026.
//
#include <iostream>
#include <fstream>
#include <iomanip>
#include "Funciones_Cadenas.h"
#include "Funciones.h"

using namespace std;


void leeinfracciones(int *arrDNI,int &numdat) {
    int fecha,dni;
    char placa[10];

    numdat=0;
    ifstream arch("InfraccionesCometidas.txt",ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir el archivo InfraccionesCometidas.txt" << endl;
        exit(1);
    }
    ofstream alma("PlacasRegistradas.txt",ios::out);
    if (not arch.is_open()) {
        cout << "No se puede abrir el archivo PlacasRegistradas.txt";
        exit(1);
    }
    while (true) {
        fecha=leefecha(arch);
        if (arch.eof()) break;
        arch >> placa >> dni;
        alma << dni <<" "<<placa<<endl;
        while (arch.get()!='\n');
        int pos=buscarbinario(dni,arrDNI,numdat);
        if (pos==-1)
            insertaordenado(dni,arrDNI,numdat);
    }
}
int buscarbinario(int dni,int *arrDNI,int numdat) {
    int liminf=0,limsup=numdat-1,medio;
    while (true) {
        if (liminf>limsup)
            return -1;
        medio=(liminf+limsup)/2;
        if (dni==arrDNI[medio])
            return medio;
        if (dni<arrDNI[medio])
            limsup=medio-1;
        else
            liminf=medio+1;
    }
}



void reportemultas(int *arrDNI,int numdat) {
    char placa[20];
    int dni;
    ifstream arch("PlacasRegistradas.txt",ios::in);
    if (not arch.is_open()) {
        cout << "Error al abrir el archivo PlacasRegistradas.txt" << endl;
        exit(1);
    }
    ofstream repo("Reporte.txt",ios::out);
    if (not arch.is_open()) {
        cout << "No se puede abrir el archivo Reporte.txt";
        exit(1);
    }
    for (int i=0;i<numdat;i++) {

    }
}

void obtenerPlaca(const char*listaDePlacas,int n,
    char *placa) {
    if (n<1) return;
    int cant=1;
    for (int i=0;listaDePlacas[i]!=0;i++)
        if (listaDePlacas[i]=='/')cant++;
    if (n>cant) return;
    int inicio=0,actual=1;
    while (actual<n) {
        if (listaDePlacas[inicio]=='/')actual++;
        inicio++;
    }
    int k=0;
    while (listaDePlacas[inicio]!=0 and
        listaDePlacas[inicio]!='/') {
        placa[k]=listaDePlacas[inicio];
        k++;
        inicio++;
    }
    placa[k]=0;
}


int leefecha(ifstream &arch) {
    int dd,mm,aa;
    char c;
    arch>>dd;
    if (arch.eof()) return 0;
    arch>>c>>mm>>c>>aa;
    return aa*10000+mm*100+dd;
}


void insertaordenado(int dni,int*arrDNI,int &numdato) {
    int pos;
    pos=numdato-1;
    while (pos>=0 and arrDNI[pos]>dni) {
        arrDNI[pos+1]=arrDNI[pos]; //subiendo 1
        pos--;
    }
    arrDNI[pos+1]=dni;
    numdato++;
}


