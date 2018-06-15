#include <stdlib.h>
#include <string.h>
#include "vector.h" 
#include<iostream>
using namespace std;

int main()
{
	// Imprime la cantidad de numeros impares en el vector
	
	int tam, cant = 0;
	cout << "Ingrese el tamaño: ";
	cin >> tam;
	
	int *vec;
    vec = crearVector(tam);
    
    for(int i=0; i< tam; i++)
	{
		if (vec[i] % 2 == 0)
		{
    		cant++ ;
		}
	}
	cout << "La cantidad de numeros impares en el vector es: " << cant;
	
	return 0;
	
}
