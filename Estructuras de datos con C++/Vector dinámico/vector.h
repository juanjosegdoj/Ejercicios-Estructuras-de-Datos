#include <stdlib.h>
#include <string.h>
#include<iostream>
using namespace std;

int *crearVector(int n)
{
	int *vect1;
	/* Reservar memoria para almacenar n enteros */
	vect1 = new int (n);
	
	/* Verificamos que la asignación se haya realizado correctamente */
	if (vect1  == NULL) {
		/* Error al intentar reservar memoria */
		return NULL;
	}
	else {
		for (int i=0;i<n;i++){
			vect1[i] = rand() % 254; 
		}
		return vect1;
	}
}

void imprimirVector(int n, int * vect1)
{
		for (int i=0;i<n;i++){
			cout <<vect1[i]<<"\t";
		}
}
