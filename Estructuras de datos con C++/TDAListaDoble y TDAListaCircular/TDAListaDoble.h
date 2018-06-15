#include "TDANodoDoble.h"
#include <iostream> 

using namespace std; 
/*Nodo Incio de la Lista*/
struct TDAListaDoble{
	Nodo *inicio;
	Nodo *actual;
} ;

TDAListaDoble *Inicilizar(){
	TDAListaDoble *c;
	c = new TDAListaDoble;
	c->actual=NULL;
	c->inicio = NULL;
	return c;
}

/*  Por LUz Mery.   Crea la Lista,  moviendo siempre la posición actial al elemento ingresado*/

TDAListaDoble *crearLista(TDAListaDoble *c, int numero){
    Nodo *aux;
	aux =  crearNodo(numero) ;
	if (c->inicio==NULL){
		c->inicio = c->actual = aux;
	}
	else {
		aux->ant=c->actual;
		c->actual->sig = aux;
		c->actual=aux;
    }
	return c;
}

TDAListaDoble *addIzquierda(TDAListaDoble *c, int numero){
    Nodo *aux;
	aux =  crearNodo(numero) ;
	
	if (c->inicio==NULL){
		c->inicio = c->actual = aux;
	}
	else {
		aux->sig = c->inicio;
		c->inicio->ant=aux;
		c->inicio=aux;		
    }
	return c;
}


void ImprimirLista(TDAListaDoble *c){
	if (c->inicio==NULL){
		cout<<"\n"<<"La lista no está creada";
	}
	else {
	    Nodo *aux;
		aux=c->inicio;
		
		do{
			cout<<"\n"<<aux->info;
			aux=aux->sig;
		}while (aux != NULL);
	}
    cout<<"\n";   
}

int cantElementEnLista(int numero,TDAListaDoble *c){
	int cont = 0;
	if (c->inicio==NULL){
		return 0;
	}
	else {
	    Nodo *aux;
		aux=c->inicio;
		
		do{
			if(aux->info == numero)
				cont ++;
			aux=aux->sig;
		}while (aux != NULL);
	}
	return cont;  
}


int longitud(TDAListaDoble *c){
	int cont = 0;
	if (c->inicio==NULL){
		return 0;
	}
	else {
	    Nodo *aux;
		aux=c->inicio;
		
		do{
			cont ++;
			aux=aux->sig;
		}while (aux != NULL);
	}
	return cont;  
}

int buscar(int elemento, TDAListaDoble *c){
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

int buscarRec(int elemento, Nodo *aux){ // aux = c->inicio
	if(aux == NULL){
		return 0;
	}else if(aux->info == elemento){
		return 1;
	}else{
		buscarRec(elemento,aux->sig);
	}
}



void BorrarElemento(TDAListaDoble *c, Nodo *nodBorrar){
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
