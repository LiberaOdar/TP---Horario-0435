#include <iostream>
#include <cstring>

using namespace std;

int main() {
    char cad1[50]="Hola ";
    char cad2[50],cad3[50]="Gata",cad4[50]="Gato";
    char scad[1000];
    strcpy(cad2,"Mundo");
    cout << cad1 <<endl;
    cout << cad2 <<endl;
    strcat(cad1,cad2);
    cout << cad1 <<endl;
    cout << scad <<endl;
    strcpy(scad,cad1);
    cout << scad <<endl;
    cout << strlen(scad)<<endl;
    /*
    if (comparar(cad3,cad4)==0)
        cout << "funciona"<<endl;
    cout << comparar(cad3,cad4) << endl;

    cin >> scad;
    cout << scad <<endl;
    cin.getline(scad,1000,',');
    cout << scad <<endl;
    cin.getline(scad,1000,',');
    cout << scad <<endl;
*/


    return 0;
}