#include <stdlib.h>
#include <string.h>
#include "vector.h" 
#include<iostream>
#include<math.h>
using namespace std;
double factorial(int num)
{
	double fact = 1;
	for(int i=2; i <= num; i++)
	{
		fact *= i;
	}
	return fact;
}

int main()
{
	// Devuelve el factorial de los numeros de un vector 
	
	int tam;
	cout << "Tamaño del vector: ";
	cin >> tam;
	
	
	int *vec;
    vec = crearVector(tam);
    
    cout << "factorial de todos los elementos del vector: " << endl;
    
    for(int i=0; i< tam; i++)
	{
		cout << factorial(vec[i]) << "  ";
	}

	return 0;
	
}
