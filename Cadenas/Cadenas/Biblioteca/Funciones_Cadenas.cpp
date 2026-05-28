//
// Created by cueva.r on 27/05/2026.
//
#include <iostream>
#include <iomanip>
 using namespace std;
#include "Funciones_Cadenas.h"

int longitud(char*cadena){
    int i;
    for(i=0;cadena[i];i++);
    return i;
    }

void copiar(char *destino, const char *fuente){
    int i;
    for(i=0;fuente[i];i++) destino[i]= fuente[i];
    destino[i]= 0;
    }
int comparar(const char *cadena1,const char *cadena2){
    int i=0;
    while(cadena1[i]==cadena2[i]) {
        if (cadena1[i]==0) return 0;
        i++;
    }
    return cadena1[i]-cadena2[i];
    }

void concatenar(char *destino, const char *fuente){
    int pos;
    pos = longitud(destino);
    copiar(&destino[pos], fuente);
}