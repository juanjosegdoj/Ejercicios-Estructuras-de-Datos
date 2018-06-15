#include "TDANodo.h"
#include <iostream> 
using namespace std; 
/*Nodo Incio de la Lista*/
struct TDALista{
	Nodo *inicio;
	Nodo *actual;
} ;

/*  Por LUz Mery.   Crea la Lista,  moviendo siempre la posición actial al elemento ingresado*/

TDALista *crearLista(TDALista *c, int numero){
    Nodo *aux;
	aux =  crearNodo(numero) ;
	if (c==NULL){
		c= new TDALista();
		c->inicio = c->actual = aux;
	}
	else {
		c->actual->sig = aux;
		c->actual=aux;
    }
	return c;
}


void ImprimirLista(TDALista *c){
	if (c==NULL){
		cout<<"\n"<<"La lista no está creada";
	}
	else {
	
		c->actual=c->inicio;
		while (c->actual!=NULL){
			cout<<"\n"<<c->actual->info;
			c->actual=c->actual->sig;
		}
}	
	cout<<"\n";
}











