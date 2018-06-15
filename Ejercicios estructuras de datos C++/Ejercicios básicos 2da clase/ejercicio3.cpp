#include <stdlib.h>
#include <string.h>
#include "vector.h" 
#include<iostream>
using namespace std;

int main()
{
	// Imprime la sumatoria de los números imapares de un vector
	
	int tam, suma = 0;
	cout << "Ingrese el tamaño: ";
	cin >> tam;
	
	int *vec;
    vec = crearVector(tam);
    
    for(int i=0; i< tam; i++)
	{
		if (vec[i] % 2 != 0)
		{
    		suma += vec[i];
		}
	}
	cout << "La sumatoria de los numeros impares: " << suma;
	
	return 0;
	
}
