#include <stdlib.h>
#include <string.h>
#include "vector.h" 
#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	// Devuelve las posiciones en donde est� un n�mero x
	
	int tam, x;
	cout << "Tama�o del vector: ";
	cin >> tam;
	
	cout << "Ingrese numero x: ";
	cin >> x;
	
	
	int *vec;
    vec = crearVector(tam);
    
    cout << "Posiciones donde est� el numero " << x << ":  ";
    
    for(int i=0; i< tam; i++)
	{
		if(vec[i] == x)
		{
			cout << i << " ";
		}
	}

	return 0;
	
}
