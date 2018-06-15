#include <stdlib.h>
#include <string.h>
#include "vector.h" 
#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	// Devuelve la norma de un vector
	
	int tam, suma = 0;
	cout << "Ingrese el tamaño: ";
	cin >> tam;
	
	int *vec1;
    vec1 = crearVector(tam);
	 
    
    
    for(int i=0; i< tam; i++)
	{
		suma += vec1[i] * vec1[i];
	}
	
	cout << "La norma del vector es: " << sqrt(suma);
	
	return 0;
	
}
