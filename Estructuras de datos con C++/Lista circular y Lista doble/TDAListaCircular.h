#include "TDANodo.h"
#include <iostream> 
using namespace std; 
struct TDALista{
	Nodo *inicio;
	Nodo *actual;
};
TDALista *Inicializar(){
	TDALista *c;
	c = new TDALista;
	c->actual=NULL;
	c->inicio = NULL;
	return c;
}
TDALista *crearLista(TDALista *c, int nombre){
    Nodo *aux;
	aux =  crearNodo(nombre) ;
	if (c->inicio==NULL){
		
		c->inicio = c->actual = aux;
	}
	else {
		c->actual->sig = aux;
		c->actual=aux;
    }
    aux->sig = c->inicio;
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
		}while (aux != c->inicio);
	}
    cout<<"\n";
}
int buscar(int nombre, TDALista*c){  // devuelve 1(true) si lo encuentra, 0(false) si no lo encuentra
	int encontrado;
	
	if (c->inicio==NULL){
		encontrado = 0;
	}
	else{
		Nodo *aux=c->inicio;
		do
		{
			if(aux->info == nombre){
				encontrado=1;	
			}
			aux = aux ->sig;
		}while(aux!=c->inicio && !encontrado);	
	}	
	return encontrado;
}
// Develve la dirección de memoria donde se encuentra el dato "nombre" en el TDALista
Nodo *buscara(int nombre, TDALista*c){
	int  encontrado;
	Nodo *aux = NULL;	
	if (c->inicio==NULL){
		encontrado = 0;
		aux->info = 0;
	}
	else{
		aux=c->inicio;
		do{
			if(aux->info==nombre){
				encontrado = 1;
				aux->info = 1;
			}
			else{
				aux = aux ->sig;
			}
		}while(aux!=c->inicio && !encontrado);	
	}
	return aux;	
}
// Borra elementos
void BorrarElemento(TDALista *c, Nodo *nodBorrar){
	Nodo *ant;
	ant = c->inicio;	
	while (ant->sig!=nodBorrar){
		ant = ant->sig;
	}
	if (c->inicio==nodBorrar){
		c->inicio = c->inicio->sig;
		c->actual->sig = c->inicio;
	}
	else {
		ant->sig=nodBorrar->sig;	
	}
	delete(nodBorrar);
}
// devuelve la longitud de la lista
int longitud(TDALista *c)
{
	int contador=0;
	if (c->inicio==NULL){
		cout<<"\n"<<"La lista no está creada\n";
	}
	else {
	    Nodo *aux;
		aux=c->inicio;
		do{
			contador++;
			aux=aux->sig;
		}while (aux!=c->inicio);
	}
	return contador;
}
// borra le elemneto cada n posicion
TDALista *Josefo(TDALista *c, int numero, int cont)
{
	Nodo * ptr; 	
	if(cont == numero)
	{	
		ptr = c->inicio;
		cout<<cont;
		cont = 0;
		BorrarElemento(c,ptr);
		cout<<"longitud actual:"<<longitud(c)<<endl;
		ImprimirLista(c);
	}
	else
		cont++;
	return c;
}
