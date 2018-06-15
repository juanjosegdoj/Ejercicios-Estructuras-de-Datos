#include "TDANodo.h"
#include <iostream> 
using namespace std; 
/*Nodo Incio de la Lista*/
struct TDAPila{
	Nodo *tope;
	Nodo *actual;
} ;

TDAPila *inicializar( ){
	TDAPila *p=new TDAPila;
	p->tope= NULL;
	p->actual= NULL;
	return p;
}

int Esvacia(TDAPila *p){
	if(p->tope == NULL){
		return 1;
	}
	else{
		return 0;
	}
}
void push(TDAPila *p, int elemento){
	Nodo *aux;
	aux= crearNodo(elemento);	
	aux->sig = p->tope;
	p->tope= aux;
	cout << "Elemento añadido con exito\n";
	system("Pause");
}

void pop(TDAPila *p){
	Nodo *aux;
	aux =p->tope;
	p->tope = p->tope->sig;
	delete(aux);
	cout << "Elemento eliminado con exito\n";
	system("Pause");
}

