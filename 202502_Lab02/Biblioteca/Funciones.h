//
// Created by cueva.r on 17/04/2026.
//

#ifndef LAB2_FUNCIONES_H
#define LAB2_FUNCIONES_H
#include <fstream>
using namespace std;
    void procesaarchivos(const char* nominfrac,
                         const char* nommulta,
                         const char* nomrepo);
    void leetexto(ifstream &arch,
        ofstream &repo,char delim);
    void leeauto(ifstream &arch,ifstream &multa,
    ofstream &repo);
    int leefechayhora(ifstream &arch,int &dd,int &mm,int &aa);
    double buscamulta(int codmulta,ifstream &multa,ofstream &);
#endif //LAB2_FUNCIONES_H