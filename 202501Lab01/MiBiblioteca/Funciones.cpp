//
// Created by cueva.r on 1/04/2026.
//
#include <iomanip>
#include <iostream>

#include "Funciones.h"

using namespace  std;
void leerdatos() {

}

void emitirreporte() {
    imprimecabecera();
}
void imprimecabecera(){
    cout << setw(80)<<"MINISTERIO DE TRANSPORTE"<<endl;
    cout << setw(85)<<"MULTAS IMPUESTAS A LAS COMPANIAS"<< endl;
    imprimelinea('=',120);
    imprimelinea('-',120);
}

void imprimelinea(char c,int n) {
    for(int i=0;i<n;i++)
        cout<<c;
    cout<<endl;
}