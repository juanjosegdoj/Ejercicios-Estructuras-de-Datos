#include <stdlib.h>
#include <string.h>
#include "vector.h" 
#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	// Devuelve los numeros multiplos del entero k
	
	int tam, k;
	cout << "Ingrese la cantidad de números para pobar el multiplo de k: ";
	cin >> tam;
	
	cout << "Ingrese el numero k: ";
	cin >> k;
	
	int *vec;
    vec = crearVector(tam);
    
    cout << "Los multiplos del numero "<< k << " son:  ";
      
    for(int i=0; i< tam; i++)
	{
		if (vec[i] % k == 0)
		{
			cout << vec[i] << "   ";
		}
	}

	
	return 0;
	
}
