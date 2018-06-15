#include <stdlib.h>
#include <string.h>
#include "vector.h" 
#include<iostream>
using namespace std;

int main()
{
	// Producto escalar de dos vectores
	
	int tam, suma = 0;
	cout << "Ingrese el tamaño: ";
	cin >> tam;
	
	int *vec1;
    vec1 = crearVector(tam);
	
	int *vec2;
    vec2 = crearVector(tam);    
    
    
    for(int i=0; i< tam; i++)
	{
		suma += vec1[i]*vec2[i];
	}
	
	cout << "El Vector resultado del producto escalar del vector 1 y 2 es: " << suma;
	
	return 0;
	
}
