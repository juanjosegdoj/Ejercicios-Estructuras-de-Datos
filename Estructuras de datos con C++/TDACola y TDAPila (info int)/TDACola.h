#include "TDANodo.h"

using namespace std; 
/*Nodo Incio de la Lista*/
struct TDACola{
	Nodo *inicio;
	Nodo *cola;
};

TDACola *inicializar(){
	TDACola *p=new TDACola;
	p->inicio = NULL;
	p->cola = NULL;
	return p;
};

void ingresarCola(TDACola *col, int info){
	Nodo *aux;
	aux = crearNodo(info);
	if(col->inicio == NULL)
		col->inicio = col->cola = aux;
	else{
		col->cola->sig = aux;
		col->cola = aux;
	}
	cout << "Ingresado en cola: " << info << "\n";
}

void ingresarInicio(TDACola *col, int info){
	Nodo *aux;
	aux = crearNodo(info);
	
	if(col->inicio == NULL)
		col->inicio = col->cola = aux;
	else{
		aux->sig = col->inicio;
		col->inicio = aux;
	}
	cout << "Ingresado en inico: " << info << "\n";
}

int esVacia(TDACola *col){
	if(col->inicio == NULL)
		return 1;
	else
		return 0;
}

void borrarCola(TDACola *col){
	Nodo *aux;
	aux = col->inicio;
	if(col->inicio == col->cola){
		col->inicio = NULL;
		col->cola = NULL;
	}else
		col->inicio = aux->sig;
	cout << "Saliendo de cola: " << aux->info << "\n";
	delete(aux);
}
