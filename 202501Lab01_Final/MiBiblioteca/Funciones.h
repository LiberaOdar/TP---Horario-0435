//
// Created by cueva.r on 1/04/2026.
//

#ifndef INC_202501LAB01_FUNCIONES_H
#define INC_202501LAB01_FUNCIONES_H

    void imprimecabecera();
    void emitirreporte();
    void imprimelinea(char ,int );
    void leetexto(char delim);
    int leefechayhora(int &dd,int &mm,int &aa);
    void leerdatos();
    double leeinfracciones(int,int);
    void imprimedatosfijos(char letra,int num1,int num2,int dd,int mm,int aa,
    int hh, int mi,int ss, char );
    double imprimedatoscalculados(char letra,char grave,int fecha,int hora,
    int fechaini,int fechafin);
    double calculatipo(char letra,double multa, double&);
    double calculafecha(double multa,int fecha,int fechaini,int fechafin,double&);
    double calculahora(int hora,double multa, double&);
#endif //INC_202501LAB01_FUNCIONES_H