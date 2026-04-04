//
// Created by cueva.r on 1/04/2026.
//
#include <iostream>
#include <iomanip>
#include "Funciones.h"

using namespace  std;

void imprimefuncion() {
    int  nota=18;
    double promedio=15.4;
    char nombre[20]={'R','O','N','Y'};
    cout<<left <<setw(20)<< nombre<<setw(10)<< nota<<setw(10) <<right<<setprecision(2)<<fixed << promedio;
    cout <<setw(5)<<" "<<setfill('0')<<setw(8)<< 9942265 <<endl;

    cout<<setfill(' ')<<left <<setw(20)<< "Freddy_Paz"<<setw(10)<< 19<<setw(10)<<right << 18.0;
    cout <<setw(5)<<" " <<setfill('0')<<setw(8)<<773737 <<endl;

    cout<<left<<setfill('.') <<setw(30)<<"Galleta_Soda"<<right<<setw(10)<<3.0<<endl;
    cout <<left<<setw(30)<<"Coca-Cola" <<right<<setw(10)<<4.0<<endl;


}