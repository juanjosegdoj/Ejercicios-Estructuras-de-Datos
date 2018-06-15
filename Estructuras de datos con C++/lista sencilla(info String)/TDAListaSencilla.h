#include "TDANodo.h"
#include <iostream> 
using namespace std; 
/*Nodo Incio de la Lista*/
struct TDALista{
	Nodo *inicio;
	Nodo *actual;
} ;

/*  Por LUz Mery.   Crea la Lista,  moviendo siempre la posición actial al elemento ingresado*/
TDALista *crearLista(TDALista *c, string dato){
    Nodo *aux;
	aux =  crearNodo(dato);
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
		while (aux != NULL){
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

TDALista *InsertOrden(TDALista *c, string dato){
	
	if (c == NULL){
		c = crearLista(c, dato);
		cout<<"se crea la lista"<<endl;
	}
	else {
		cout << "Prontos a ingresar nodo\n";
	    Nodo *aux, *auxAnt, *auxNew;
		aux=c->inicio;
		auxAnt = aux;
		auxNew = crearNodo(dato); 
		
			cout << "Recorriendo lista:  "<<aux->info <<" ---- "<<auxNew->info<<endl;
			int cont = 0;
			while (aux!=NULL && aux->info < auxNew->info ){
				
				cont++;
				cout << "poscion "<< cont << endl;
				auxAnt = aux;
				aux=aux->sig; 
			}
			if (aux==NULL){
				c->actual->sig = auxNew;
				c->actual = auxNew;
			}
			else {
				if (auxNew->info < c->inicio->info){
			
					auxNew->sig = c->inicio;
					c->inicio=auxNew;
				}	
				else
				{
					auxNew->sig= auxAnt->sig;
					auxAnt->sig=auxNew;
				}
			}
	}
	return c;
}

int buscar(string elemento, TDALista*c){
	// retorna 1 o 0 si existe un elemento en la lista sencilla
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

string elemEnPos(int index, TDALista*c){
	// el elemento en una posción ingresada
	if (c==NULL){
		return "NULL";
	}
	if(longitud(c)<=index){
		return "NULL";
	}
	else{
		Nodo *aux=c->inicio;
		for(int i=0; i<index; i++){
			aux = aux ->sig;
		}
		return aux->info;
	}
}

Nodo *BuscarElementNODO(string elemento, TDALista*c){
	// retorna el nodo donde fue encontrado el elemento
	
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


TDALista *eliminarElemento(string elemento, TDALista*c){
	
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
