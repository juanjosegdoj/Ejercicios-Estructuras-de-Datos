#include <iostream> 
#include <String.h>
using namespace std;
/* Estructura del Nodo */
struct Nodo{
	string info;
	Nodo *sig;
} ;

/*  Por LUz Mery.   Crea el nodo de acuerdo a la informaci�n ingresada y coloca en NULL la siguiente posici�n*/
Nodo *crearNodo(string dato) 
{
	Nodo *nodoC;
	nodoC = new Nodo;
	nodoC->info = dato;
	nodoC->sig =NULL;
	return nodoC;
}

