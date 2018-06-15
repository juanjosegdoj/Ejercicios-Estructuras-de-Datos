#include <stdlib.h>
#include <string.h>
#include "vector.h" 
#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	// Devuelve las posiciones en donde está un número x
	
	int tam, x;
	cout << "Tamaño del vector: ";
	cin >> tam;
	
	cout << "Ingrese numero x: ";
	cin >> x;
	
	
	int *vec;
    vec = crearVector(tam);
    
    cout << "Posiciones donde está el numero " << x << ":  ";
    
    for(int i=0; i< tam; i++)
	{
		if(vec[i] == x)
		{
			cout << i << " ";
		}
	}

	return 0;
	
}
