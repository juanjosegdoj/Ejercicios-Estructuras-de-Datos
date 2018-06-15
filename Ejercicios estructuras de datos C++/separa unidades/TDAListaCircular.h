#include "TDANodo.h"
#include <iostream> 
using namespace std; 
/*Nodo Incio de la Lista*/
struct TDALista{
	Nodo *inicio;
	Nodo *actual;
} ;

TDALista *Inicilizar(){
	TDALista *c;
	c = new TDALista;
	c->actual=NULL;
	c->inicio = NULL;
	return c;
}

/*  Por LUz Mery.   Crea la Lista,  moviendo siempre la posición actial al elemento ingresado*/

TDALista *crearLista(TDALista *c, int numero){
    Nodo *aux;
	aux =  crearNodo(numero) ;
	if (c->inicio==NULL){
		c->inicio = c->actual = aux;
	}
	else {
		c->actual->sig = aux;
		c->actual=aux;
    }
    aux ->sig = c->inicio;
	return c;
}


void ImprimirLista(TDALista *c){
	if (c->inicio==NULL){
		cout<<"\n"<<"La lista no está creada";
	}
	else {
	    Nodo *aux;
		aux=c->inicio;
		do{
			cout<<"\n"<<aux->info;
			aux=aux->sig;
		}while (aux!=c->inicio);
}
    cout<<"\n";
}

int buscar(int elemento, TDALista*c){
	int encontrado;
	if (c->inicio==NULL){
		encontrado= 0;
	}
	else{
		Nodo *aux=c->inicio;
		while(aux!=NULL && !encontrado){
			if(aux->info==elemento){
				encontrado=1;
			}
			aux = aux ->sig;
		}
	}	
	return encontrado;
}


void BorrarElemento(TDALista *c, Nodo *nodBorrar){
	Nodo *ant;
	
	c->actual=c->inicio;
	while (c->actual!=nodBorrar){
		ant = c->actual;
		c->actual=c->actual->sig;
	}
	
	if (c->inicio==nodBorrar){
		c->actual=c->inicio=c->inicio->sig;
	}
	else {
		ant->sig=nodBorrar->sig;
		
	}
	delete(nodBorrar);
		
}
