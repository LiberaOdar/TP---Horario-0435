//
// Created by cueva.r on 17/04/2026.
//
#include <iomanip>
#include <fstream>
#include <iostream>
#include "Funciones.h"

using namespace std;

void procesaarchivos(const char* nominfrac,
                     const char* nommulta,
                     const char* nomrepo) {

    ifstream archinf(nominfrac,ios::in);
    if (not archinf.is_open()) {
        cout << "Error al abrir archivo "<<nominfrac << endl;
        exit(1);
    }
    ifstream archmul(nommulta,ios::in);
    if (not archmul.is_open()) {
        cout << "Error al abrir archivo "<<nommulta << endl;
        exit(1);
    }
    ofstream repo(nomrepo,ios::out);
    if (not repo.is_open()) {
        cout << "Error al abrir archivo "<< nomrepo << endl;
        exit(1);
    }
    int dni;
    char c;

    while(true){
        archinf >> dni;
        if (archinf.eof())break;
        repo<<endl;
        leetexto(archinf,repo,' ');
        repo<<setw(20)<<dni<<endl;
        repo<<"Vehiculos Infraccionados:"<<endl;
        leeauto(archinf,archmul,repo);
        repo<<endl;
    }
}

void leeauto(ifstream &arch,ifstream &multa,
    ofstream &repo) {
    char tipo,c;
    int num1,num2,dd,mm,aa,codmulta;
    while(true) {
        arch>>tipo>>num1>>c>>num2;
        repo<<num1<<num2<<tipo<<setw(10)<<" ";
        leefechayhora(arch,dd,mm,aa);
        arch >> codmulta;
        repo<<setfill('0') << setw(2)<<dd<<"/"<<setw(2)<<mm<<"/"<<setw(2)<<aa<<setfill(' ')<<setw(10)<<codmulta;
        double monto= buscamulta(codmulta,multa,repo);
        repo<< endl;
        if (arch.get()=='\n')break;
    }
}

double buscamulta(int codmulta,ifstream &multa,
    ofstream&repo) {
    char gravedad;
    int codigo;
    double monto;
    multa.clear();
    multa.seekg(0,ios::beg);
    while(true) {
        multa>>gravedad;
        if (multa.eof())break;
        multa>>codigo;
        if (codigo==codmulta) {
                multa >> monto;
                repo<<setprecision(2)<<fixed<< setw(10)<<monto<<setw(5)<<" ";
                leetexto(multa,repo,'\n');
                return monto;
        }
        else while (multa.get()!='\n');
    }
}

int leefechayhora(ifstream &arch,int &dd,int &mm,int &aa) {
    char c;
    arch>>dd>>c>>mm>>c>>aa;
    if (c=='/')
        return aa*10000+mm*100+dd;
    if (c==':')
        return dd*3600+mm*60+aa;
    return 0;
}


void leetexto(ifstream &arch,
    ofstream &repo,char delim) {
    int num=0;
    char c;
    arch>>ws;
    while (true) {
        c=arch.get();
        if (c==delim)break;
        if (c=='*' or c=='/' or c=='-')
            repo <<" ";
        else {
            if (c>='a' and c<='z')
                c=c-'a'+'A';
            repo<<c;
        }
        num++;
    }
    for(int i=0;i<60-num;i++)repo<<" ";
}