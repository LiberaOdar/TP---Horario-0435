#include <iostream>
#include <cstring>

using namespace std;

char* funcionlee() {
    //char cad[100]="Hola ahora se punteros";
    char *cad;
    cad = new char[100];
    strcpy(cad,"Hola mundo");
    return cad;
}

int main() {
    char *pcad;
    //pcad=new char[100];//mal
    pcad=funcionlee();
    cout<<pcad<<endl;
    cout<<pcad[1]<<pcad[2]<<pcad[3];
    return 0;
}