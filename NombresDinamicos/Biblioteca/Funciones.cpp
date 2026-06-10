//
// Created by cueva.r on 5/06/2026.
//
#include <fstream>
#include <cstring>
#include <iostream>
#include "Funciones.h"

using namespace std;

void generareportes(char **catcod,char **catnom) {
    char nomarch[100],enlace[100];
    for (int i=0;catcod[i]!=nullptr;i++) {
        generaArchivoEnlace(catnom[i],nomarch,enlace);
        ofstream arch(nomarch,ios::out);
        if (not arch.is_open()) {
            cout << "Error al abrir el archivo " << nomarch;
            exit(1);
        }
        arch << catcod[i]<<endl;
    }
}

void generaArchivoEnlace(const char *categoria,
    char *nombArch, char *enlace) {
    char nombre[100];
    strcpy(nombre,categoria);
    for (int i=0;nombre[i];i++)
        if (i==0 or nombre[i-1]=='_')
            if (nombre[i]>='a' and nombre[i]<='z')
                nombre[i]-='a'-'A';

    strcpy(nombArch,"ArchivosDeReporte/");
    strcat(nombArch,nombre);
    strcat(nombArch,".txt");
    strcpy(enlace,"https://Laboratorio06_2025_2/ArchivosDeReporte/");
    strcat(enlace,nombre);
}

void leecategoria(char **catcod,char **catnom,const char*nombre) {
    ifstream arch(nombre,ios::in);
    if (not arch.is_open()) {
        cout << "No se encuentra el archivo "<<nombre<<endl;
        exit(1);
    }
    char cad[100];
    int i=0;
    while (true) {
        catcod[i]=leecadena(arch,' ');
        if (arch.eof())break;
        arch>>ws;
        catnom[i]=leecadena(arch,'\n');
        i++;
    }


}

char*leecadena(ifstream &arch,char deli) {
    char cad[100],*pcad;
    arch.getline(cad,100,deli);
    if (arch.eof()) return nullptr;
    pcad=new char[strlen(cad)+1];
    strcpy(pcad,cad);
    return pcad;
}