#include <stdlib.h>
#include <string.h>
#include "vector.h" 
#include<iostream>
using namespace std;

int main()
{
	// Dice si dos vectores son ortogonales
	
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
	
	if(suma == 0)
	{
		cout << "Los dos vectores SI son ortogonales";
	}
	else{
		cout << "Los dos vectores NO son ortogonales";
	}
	
	return 0;
	
}
