#include <stdlib.h>
#include <string.h>
#include "vector.h" 
#include<iostream>
using namespace std;

int main()
{
	// Este programa devuelve el promedio de los datos de un vector
	
	int tam, suma = 0;
	cout << "Ingrese el tamaño: ";
	cin >> tam;
	
	int *vec;
    vec = crearVector(tam);
    
    for(int i=0; i< tam; i++)
	{
    	suma += vec[i];
	}
	cout << "El promedio del vector es: " << suma/tam;
	return 0;
}
