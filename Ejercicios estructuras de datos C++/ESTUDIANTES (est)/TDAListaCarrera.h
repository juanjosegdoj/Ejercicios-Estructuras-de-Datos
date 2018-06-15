#include "TDANodoCar.h"
#include <iostream> 
using namespace std; 

struct TDAListaCarrera{
	NodoCar *inicio;
	NodoCar *actual;
} ;


TDAListaCarrera *crearLista(TDAListaCarrera *c, string dato, string nombre){
    NodoCar *aux;
    if(nombre != "NULL")
		aux =  crearNodo(dato,nombre) ;
		
	if (c==NULL){
		c = new TDAListaCarrera();
		c->inicio = c->actual = aux;
	}
	else {
		c->actual->sig = aux;
		c->actual=aux;
    }
	return c;
}


void ImprimirLista(TDAListaCarrera *c){
	if (c==NULL){
		cout<<"\n"<<"La lista no está creada";
	}
	else {
	    NodoCar *aux;
		aux=c->inicio;
		while (aux!=NULL){
			cout<<"\n---------"<<aux->carrera << "---------\n";
			ImprimirListaE(aux->stud);
			aux=aux->sig;
		}
	}
    cout<<"\n";
}

void printCarreras(TDAListaCarrera *c,string nomCarrera){
	if (c==NULL){
		cout<<"\n"<<"La lista no está creada";
	}
	else {
	    NodoCar *aux;
		aux=c->inicio;
		while (aux!=NULL){
			if(aux->carrera == nomCarrera){
				cout<<"\n---------"<<aux->carrera << "---------\n";
				ImprimirListaE(aux->stud);
			}
			
			aux=aux->sig;
		}
	}
    cout<<"\n";
}

void printEstudCarr(TDAListaCarrera *c, string nombreCarr){
	if (c==NULL){
		cout<<"\n"<<"La lista no está creada";
	}
	else {
	    NodoCar *aux;
		aux=c->inicio;
		while (aux!=NULL){
			if(nombreCarr == aux->carrera){
				cout << "Estudiantes de la carrera " << nombreCarr << endl;
				ImprimirListaE(aux->stud);
			}
			aux=aux->sig;
		}
	}
    cout<<"\n";
}

int longitud(TDAListaCarrera *c){
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

int buscar(string elemento, TDAListaCarrera*c){
	// retorna 1 o 0 si existe un elemento en la lista sencilla
	int encontrado;
	if (c==NULL){
		encontrado= 0;
	}
	else{
		NodoCar *aux=c->inicio;
		while(aux!=NULL && !encontrado){
			if(aux->carrera==elemento){
				encontrado=1;
			}
			aux = aux ->sig;
		}
	}	
	return encontrado;
}

string elemEnPos(int index, TDAListaCarrera*c){
	// el elemento en una posción ingresada
	if (c==NULL){
		return "NULL";
	}
	if(longitud(c)<=index){
		return "NULL";
	}
	else{
		NodoCar *aux=c->inicio;
		for(int i=0; i<index; i++){
			aux = aux ->sig;
		}
		return aux->carrera;
	}
}

NodoCar *BuscarElementNODO(string elemento, TDAListaCarrera*c){
	// retorna el nodo donde fue encontrado el elemento
	
	NodoCar *aux;
	bool encontrado = false;
	if (c==NULL){
		return NULL;
	}
	else{
		aux=c->inicio;
		while(aux!=NULL && !encontrado){
			if(aux->carrera==elemento){
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


TDAListaCarrera *eliminarElemento(string elemento, TDAListaCarrera*c){   // en realidad busca solamente
	
	if ( longitud(c) == 0){
		return c;
	}	
	NodoCar *aux;
	bool encontrado = false;
	if (c==NULL){
		return NULL;
	}
	
	else{
		aux=c->inicio;
		while(aux!=NULL && !encontrado){
			if(aux->carrera==elemento){
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

TDAListaCarrera *InsertOrden(TDAListaCarrera *c, string dato, string nombre){
	
	if (c == NULL){
		c = crearLista(c, dato,nombre);
	}
	else {
	    NodoCar *aux, *auxAnt, *auxNew;
		aux=c->inicio;
		auxAnt = aux;
		auxNew = crearNodo(dato,nombre); 
		
			int cont = 0;
			while (aux!=NULL && aux->carrera < auxNew->carrera ){
				
				cont++;
				auxAnt = aux;
				aux=aux->sig; 
			}
			if (aux==NULL){
				c->actual->sig = auxNew;
				c->actual = auxNew;
			}
			else {
				if (auxNew->carrera < c->inicio->carrera){
			
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
