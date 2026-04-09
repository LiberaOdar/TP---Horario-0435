//
// Created by cueva.r on 1/04/2026.
//
#include <iomanip>
#include <iostream>

#include "Funciones.h"

using namespace  std;


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
    for(int i=0;i<n;i++)cout<<c;
    cout<<endl;
}

void leefecha(int &dd,int &mm,int &aa) {
    char c;
    cin>>dd>>c>>mm>>c>>aa;
}
// Contreras/Chang/Johana-Cinthia
void leetexto(char delim) {
    int num=0;
    char c;
    cin>>ws;
    while (true) {
        c=cin.get();
        if (c==delim)break;
        cout<<c;
        num++;
    }
    for(int i=0;i<60-num;i++)cout<<" ";
}

void leerdatos() {
    int di,df,mi,mf,ai,af,dni;
    leefecha(di,mi,ai);
    leefecha(df,mf,af);
    while (true) {
        cin >> dni;
        if (cin.eof())break;
        cout<<"Representante Legal: ";
        leetexto(' ');
        cout<<"DNI: "<<dni<<endl;
        //while (cin.get()!='\n');
        leeinfracciones();
    }

}
// P599-629    12/12/2023  10:42:26      L
void leeinfracciones() {
    char letra,c,grave;
    int num1,num2,aa,mm,dd,hh,mi,ss;

    while (true) {
        cin>>letra>>num1>>c>>num2;
        leefecha(dd,mm,aa);
        leefecha(hh,mi,ss);
        cin >> grave;
        if (cin.get()=='\n')break;
    }

}