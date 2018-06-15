#include <iostream> 
#include "TDAListaEstudiantes.h"
using namespace std;
/* Estructura del Nodo triple */

struct NodoCar{
	string carrera;
	TDAListaEstudiantes *stud;
	NodoCar *sig;
} ;


NodoCar *crearNodo(string dato, string nombre) 
{
	NodoCar *nodoC;
	nodoC = new NodoCar;
	nodoC->carrera = dato;
	nodoC->stud = crearListaE(nodoC->stud,nombre);		
	nodoC->sig =NULL;
	return nodoC;
}

