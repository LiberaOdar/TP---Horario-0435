//
// Created by cueva.r on 1/04/2026.
//
#include <iomanip>
#include <iostream>
#include <climits>
#include "Funciones.h"
#define ESP 10

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

int leefechayhora(int &dd,int &mm,int &aa) {
    char c;
    cin>>dd>>c>>mm>>c>>aa;
    if (c=='/')
        return aa*10000+mm*100+dd;
    if (c==':')
        return dd*3600+mm*60+aa;
}
// Contreras/Chang/Johana-Cinthia
void leetexto(char delim) {
    int num=0;
    char c;
    cin>>ws;
    while (true) {
        c=cin.get();
        if (c==delim)break;
        if (c=='*' or c=='/' or c=='-')
            cout <<" ";
        else {
            if (c>='a' and c<='z')
                c=c-'a'+'A';
            cout<<c;
        }
        num++;
    }
    for(int i=0;i<60-num;i++)cout<<" ";
}

void leerdatos() {
    int di,df,mi,mf,ai,af,dni;
    int maxdni,mindni;
    double totalmax=-999999,totalmin=999999,total;
    int fechaini=leefechayhora(di,mi,ai);
    int fechafin=leefechayhora(df,mf,af);
    while (true) {
        cin >> dni;
        if (cin.eof())break;
        cout<<endl<<"Representante Legal: ";
        leetexto(' ');
        cout<<"DNI: "<<dni<<endl;
        total=leeinfracciones(fechaini,fechafin);
        if (total<totalmin) {
            totalmin=total;
            mindni=dni;
        }
        if (total>totalmax) {
            totalmax=total;
            maxdni=dni;
        }
    }
    cout <<endl;
    imprimelinea('*',40);
    cout <<"El minimo DNI es: "<<mindni<<endl;
    cout <<"El minimo Total es: "<<totalmin<<endl;
    imprimelinea('*',40);
    cout <<endl<<"El maximo DNI es: "<<maxdni<<endl;
    cout <<"El maximo Total es: "<<totalmax<<endl;

}
// P599-629    12/12/2023  10:42:26      L
double leeinfracciones(int fechaini,int fechafin) {
    char letra,c,grave;
    int num1,num2,aa,mm,dd,hh,mi,ss;
    double total;
    while (true) {
        cin>>letra>>num1>>c>>num2;
        int fechaux=leefechayhora(dd,mm,aa);
        int horaux=leefechayhora(hh,mi,ss);
        cin >> grave;
        //if (fechaux<=fechafin and fechaini<=fechaux) {
        imprimedatosfijos(letra,num1,num2,dd,mm,aa,hh,mi,ss,grave);
        total=imprimedatoscalculados(letra,grave,fechaux,horaux,fechaini,fechafin);
        cout << endl;
        //}
        if (cin.get()=='\n')break;
    }
    return total;
}

double imprimedatoscalculados(char letra,char grave,int fecha,int hora,
    int fechaini,int fechafin) {
    double multa,total;
    if (grave=='L')multa=158.33;
    if (grave=='G')multa=516.75;
    if (grave=='M')multa=3920.25;
    total=multa;
    cout << setw(10) << setprecision(2)<<fixed<<multa;
    cout << setw(10)<< calculatipo(letra,multa,total);
    cout << setw(10)<< calculafecha(multa,fecha,fechaini,fechafin,total);
    cout << setw(10)<<calculahora(hora,multa,total);
    cout << setw(10)<<total;
    return total;
}

double calculahora(int hora,double multa,double &total) {
    if (hora>=4*3600+30*60 and hora<=11*3600+25*60) {
        total+=multa*0.085;
        return multa*0.085;
    }

    if (hora>11*3600+25*60 and hora<=20*3600+40*60) {
        total+=multa*0.058;
        return multa*0.058;
    }
    if (hora>20*3600+30*60 and hora<=23*3600+59*60) {
        total+=multa*0.037;
        return multa*0.037;
    }
    if (hora>=0 and hora<4*3600+30*60) {
        total+=multa*0.037;
        return multa*0.037;
    }

}

double calculatipo(char letra,double multa,double &total) {
    if (letra=='P') {
        total+=multa*0.027;
        return multa*0.027;
    }
    if (letra=='M') {
            total+=multa*0.117;
            return multa*0.117;
    }
    if (letra=='C') {
        total+=multa*0.153;
        return multa*0.153;
    }
}

double calculafecha(double multa,int fecha,int fechaini,int fechafin,double &total) {
    if (fecha<fechaini) {
        total+=multa*0.1075;
        return multa*0.1075;
    }
    if (fecha>=fechaini and fecha<=fechafin) {
        total+=multa*0.0725;
        return multa*0.0725;
    }
    return 0;
}

void imprimedatosfijos(char letra,int num1,int num2,int dd,int mm,int aa,
    int hh, int mi,int ss,char grave ) {
    if (letra=='P')cout<<setfill(' ' ) <<left<<setw(10)<< "PEQUENO";
    if (letra=='M')cout <<setfill(' ' ) <<left<<setw(10)<< "MEDIANO";
    if (letra=='C')cout <<setfill(' ' ) <<left<<setw(10)<< "GRANDE";
    cout << setw(ESP)<<" "<<letra<<num1 <<num2<<setw(ESP)<<" ";
    cout <<right<<setfill('0')<< setw(2)<<dd<<"/"<<setw(2)<<mm<<"/"<<setw(4)<<aa<<setfill(' ' ) ;
    cout <<setw(ESP)<<" "<<setfill('0')<<setw(2)<<hh<<":"<<setw(2)<<mi<<":"<<setw(2)<<ss<<setfill(' ' ) ;
    if ('L'==grave) cout <<setw(2*ESP) << "LEVE";
    if ('G'==grave) cout <<setw(2*ESP) << "GRAVE";
    if ('M'==grave) cout <<setw(2*ESP) << "MUY GRAVE";
}
