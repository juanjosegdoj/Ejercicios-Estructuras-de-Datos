#include <iostream> 
using namespace std;
/* Estructura del Nodo */
struct Nodo{
	int info;
	Nodo *sig, *ant;
} ;

/*  Por LUz Mery.   Crea el nodo de acuerdo a la informaci�n ingresada y coloca en NULL la siguiente posici�n*/
Nodo *crearNodo(int dato) 
{
	Nodo *nodoC;
	nodoC = new Nodo;
	nodoC->info = dato;
	nodoC->sig =NULL;
	nodoC->ant = NULL;
	return nodoC;
}

