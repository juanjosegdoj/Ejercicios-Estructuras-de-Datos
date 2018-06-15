#include <stdlib.h>
#include <string.h>
#include "vector.h" 
#include<iostream>
using namespace std;

int main()
{ 
    int *vec;
    int tam = 3;
    vec = crearVector(tam);
    
    cout << "Vector Generado \n";
    cout << vec[0] << endl;
    cout << vec[1] << endl;
    cout << vec[2] << endl;
    cout << vec[3] << endl;
    cout << vec[4] << endl;
    cout << "Antes de asignar: "<< vec[1000] << endl;
    vec[1000] = 666;
    cout << "Despues de asignar: "<< vec[1000] << endl;
    
    
    
    
    return 0;
}
