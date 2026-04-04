//
// Created by cueva.r on 27/03/2026.
//
#include <iostream>
#include "Funciones.h"

using namespace std;

int suma(int a, int b) {
    cout << "La suma es:";
    return a + b;
}
void incrementa(int &num) {
    num=num+1;
}