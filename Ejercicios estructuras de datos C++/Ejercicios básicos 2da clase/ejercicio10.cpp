#include <stdlib.h>
#include <string.h>
#include "vector.h" 
#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	// Devuelve tres vectores, uno con los numeros mayores a k, otros los menores y otros los iguales
	
	int tam, k;
	cout << "Ingrese el tamaño: ";
	cin >> tam;
	
	cout << "Ingrese el numero k: ";
	cin >> k;
	
	int *vec;
    vec = crearVector(tam);
    
    
    int *mayores;
    mayores = crearVector(tam);
    int cont_may = 0;
	
	int *menores;
    menores = crearVector(tam);
    int cont_men = 0;
    
    int *iguales;
    iguales = crearVector(tam);
    int cont_igual = 0;
    
    
    for(int i=0; i< tam; i++)
	{
		if(vec[i] > k)
		{
			// Numeros mayores a k
			mayores[cont_may] = vec[i];
			cont_may++;
		}
		else if(vec[i] == k)
		{	
			// numeros iguales a k
			iguales[cont_igual] = vec[i];
			cont_igual++;
		}
		else
		{
			// numeroos menores a k	
			menores[cont_men] = vec[i];
			cont_men++;
		} 
	}
	
	cout << "Números mayores a " << k << ": ";
	imprimirVector(cont_may,mayores);
	cout << endl;
	
	cout << "Números menores a " << k << ": ";
	imprimirVector(cont_men,menores);
	cout << endl;
	
	
	cout << "Números iguales " << k << ": ";
	imprimirVector(cont_igual,iguales);
	cout << endl;
	
	return 0;
	
}
