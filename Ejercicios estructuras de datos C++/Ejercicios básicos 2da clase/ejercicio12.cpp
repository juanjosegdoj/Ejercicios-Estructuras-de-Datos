#include <stdlib.h>
#include <string.h>
#include "vector.h" 
#include<iostream>
#include<math.h>
using namespace std;

bool primo(int num)
{
	if (num <= 2)
	{
		return true;
	}
	
	if (num % 2 == 0)
	{
		return false;
	}
	for(int i=3; i<num; i++)
	{
		if (num % i == 0)
		{
			return false;
		}	
	}
	return true;
}

int main()
{
	// Devuelve los numeros primos de un vector
	
	int tam;
	cout << "Tamaño del vector: ";
	cin >> tam;
	
	
	int *vec;
    vec = crearVector(tam);
    
    cout << "Numeros primos del vector: " << endl;
    
    for(int i=0; i< tam; i++)
	{
		if(primo(vec[i]))
		{
			cout << vec[i];
		}
	}

	return 0;
	
}
