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
	    Nodo *aux;
		aux=c->inicio;
		while (aux!=NULL){
			cout<<"\n"<<aux->info;
			aux=aux->sig;
		}
}
    cout<<"\n";
}
int longitud(TDALista *c){
	int cont;
	if(c==NULL){
		cont=0;
	}else{
	c->actual=c->inicio;
	while(c->actual!=NULL){
		c->actual=c->actual->sig;
		cont++;
	}
	c->actual=c->inicio;
	while (c->actual->sig!=NULL)
		c->actual=c->actual->sig;
	return cont;
}
}
int buscar(int elemento, TDALista*c){
	int encontrado;
	if (c==NULL){
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
Nodo *BuscarElementNODO(int elemento, TDALista*c){
	Nodo *aux;
	bool encontrado = false;
	if (c==NULL){
		return NULL;
	}
	else{
		aux=c->inicio;
		while(aux!=NULL && !encontrado){
			if(aux->info==elemento){
				encontrado = true;
			}else
				aux = aux ->sig;
		}
	}	
	if (encontrado)
		return aux;
	else
		return NULL;
}


TDALista *eliminarElemento(int elemento, TDALista*c){
	
	if ( longitud(c) == 0){
		return c;
	}
	
	Nodo *aux;
	bool encontrado = false;
	if (c==NULL){
		return NULL;
	}
	
	else{
		aux=c->inicio;
		while(aux!=NULL && !encontrado){
			if(aux->info==elemento){
				encontrado = true;
			}else
				aux = aux ->sig;
		}
	}	
	if (encontrado)
		return c;
	else
		return NULL;
}
