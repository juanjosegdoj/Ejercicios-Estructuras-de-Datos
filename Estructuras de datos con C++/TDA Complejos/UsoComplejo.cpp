#include <stdlib.h>
#include <string.h>
#include "TDAComplejo.h"
#include<iostream>
using namespace std;


int main()
{ 
    complejo r,n1,n2,*r2;
    n1.real=3;
    n1.imaginario = 2;
   
    n2.real=1;
    n2.imaginario = -2;
    r = sumar(n1,n2);
    imprimirComplejo(r,"Respuesta Suma:  ");
    r = restar(n1,n2);
    imprimirComplejo(r,"Respuesta Resta:  ");
    r = multiplicar(n1,n2);
    imprimirComplejo(r,"Respuesta Multiplicación:  ");
    r = dividir(n1,n2);
    imprimirComplejo(r,"Respuesta División:  ");
    return 0;
}
