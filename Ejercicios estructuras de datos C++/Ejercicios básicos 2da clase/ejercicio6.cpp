#include <stdlib.h>
#include <string.h>
#include "vector.h" 
#include<iostream>
using namespace std;

int main()
{
	// Promedio de los números pares de un vector
	
	int tam, cant = 0, sumaP= 0;
	cout << "Ingrese el tamaño: ";
	cin >> tam;
	
	int *vec;
    vec = crearVector(tam);
    
    for(int i=0; i< tam; i++)
	{
		if (vec[i] % 2 == 0)
		{
			sumaP += vec[i];
    		cant++ ;
		}
	}
	cout << "La cantidad de numeros impares en el vector es: " << sumaP/cant;
	
	return 0;
	
}
