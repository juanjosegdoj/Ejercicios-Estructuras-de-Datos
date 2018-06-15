#include <iostream> 
#include <String.h>
using namespace std;


struct NodoEst{
	string info;
	NodoEst *sig;
};


NodoEst *crearNodoE(string dato) 
{
	NodoEst *nodoC;
	nodoC = new NodoEst;
	nodoC->info = dato;
	nodoC->sig =NULL;
	return nodoC;
}

