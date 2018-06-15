#include "TDANodoEst.h"
#include <iostream> 
#include <string>

using namespace std;


using namespace std; 
/*Nodo Incio de la Lista*/
struct TDAListaEstudiantes{
	NodoEst *inicio;
	NodoEst *actual;
} ;

/*  Por LUz Mery.   Crea la Lista,  moviendo siempre la posición actial al elemento ingresado*/
TDAListaEstudiantes *crearListaE(TDAListaEstudiantes *c, string dato){
    NodoEst *aux;
	aux =  crearNodoE(dato) ;
	if (c==NULL){
		c= new TDAListaEstudiantes();
		c->inicio = c->actual = aux;
	}
	else {
		c->actual->sig = aux;
		c->actual=aux;
    }

	return c;
}


void ImprimirListaE(TDAListaEstudiantes *c){
	if (c==NULL){
		cout<<"\n"<<"La lista no está creada";
	}
	else {
	    NodoEst *aux;
		aux=c->inicio;
		while (aux!=NULL){
			cout<<"\n"<<aux->info;
			aux=aux->sig;
		}
	}
    cout<<"\n";
}

int longitudE(TDAListaEstudiantes *c){
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

int buscarE(string elemento, TDAListaEstudiantes*c){
	// retorna 1 o 0 si existe un elemento en la lista sencilla
	int encontrado;
	if (c==NULL){
		encontrado= 0;
	}
	else{
		NodoEst *aux=c->inicio;
		while(aux!=NULL && !encontrado){
			if(aux->info==elemento){
				encontrado=1;
			}
			aux = aux ->sig;
		}
	}	
	return encontrado;
}

string elemEnPosE(int index, TDAListaEstudiantes*c){
	// el elemento en una posción ingresada
	if (c==NULL){
		return "NULL";
	}
	if(longitudE(c)<=index){
		return "NULL";
	}
	else{
		NodoEst *aux=c->inicio;
		for(int i=0; i<index; i++){
			aux = aux ->sig;
		}
		return aux->info;
	}
}

NodoEst *BuscarElementNODOE(string elemento, TDAListaEstudiantes*c){
	// retorna el nodo donde fue encontrado el elemento
	
	NodoEst *aux;
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


TDAListaEstudiantes *eliminarElementoE(string elemento, TDAListaEstudiantes*c){   // en realidad busca solamente
	
	if ( longitudE(c) == 0){
		return c;
	}
	
	NodoEst *aux;
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

