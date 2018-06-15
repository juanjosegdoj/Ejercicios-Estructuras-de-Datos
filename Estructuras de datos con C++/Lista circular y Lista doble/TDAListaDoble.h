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

/*  Crea la Lista,  moviendo siempre la posición actual al elemento ingresado*/
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
	aux =  crearNodo(numero);
	
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

void borrarElemento(TDAListaDoble *c, Nodo *nodBorrar){
	Nodo *ant;
	c->actual = c->inicio;
	while (c->actual != nodBorrar){
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


void borrarIndex(TDAListaDoble *c, int pos){
	int cont = 1;
	if (c->inicio==NULL){
		cout<<"\n"<<"La lista no está creada";
	}
	else {
	    Nodo *aux;
		aux=c->inicio;
		
		do{
			if(cont == pos){
				borrarElemento(c, aux);
				return;
				cout << "Supuestamente borrado\n";
			}
			aux=aux->sig;
			cont++;
		}while (aux != NULL);
	}
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

int esVacia(TDAListaDoble *c){
	if(c->inicio == c->actual)
		return 1;
	else
		return 0;
}

TDAListaDoble *insertar(TDAListaDoble *c, int pos, int info){
	// Inserta un elemento info en la ListaDoble c, en la posicion pos
	// NOTA: Si se ingresa una posicion mayor al tamaño de la lista c, este elemento se inserta en la ultima posicio	
	int cont = 0;
	if(pos == 1){
		c = addIzquierda(c, info);
	}
	else if (c->inicio==NULL || pos>longitud(c)){
		c = crearLista(c,info);
	}
	else{
	    Nodo *aux, *aux2 = crearNodo(info);
		aux=c->inicio;
		do{
			cont++;
			cout<<"\n"<<aux->info;
			if(cont == pos-1){
				aux2->sig = aux->sig;
				aux->sig = aux2;
				aux2->ant = aux;
				aux2->sig->ant = aux2;
			}
			aux=aux->sig;
		}while (aux != NULL);
	}
    return c;  
}
 
TDAListaDoble *ordenar(TDAListaDoble *c){   // ordenamiento por inserción
	struct TDAListaDoble *c2 = Inicilizar();
	int tamanio = longitud(c), sw = 0, cont;
	c2 = crearLista(c2, c->inicio->info);
	borrarElemento(c, c->inicio);
	ImprimirLista(c2);
	Nodo *aux;
	for(int i=0; i<tamanio; i++){
		while(c->inicio != NULL){
			cont = 1;
		    aux = c2->inicio;
		    sw = 0;
			do{	
				cout << aux->info << " > " << c->inicio->info << endl;
				if(aux->info > c->inicio->info){
					c2 = insertar(c2,cont,c->inicio->info);
					borrarElemento(c,c->inicio);
					sw = 1;
				}
				aux=aux->sig;
				cont++;
			}while (aux != NULL && sw != 1);
			if(sw == 0){
				c2 = crearLista(c2, c->inicio->info);
				borrarElemento(c,c->inicio);
			}
		}
	}
	system("pause");
	return c2;	
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

void limpiarLista(TDAListaDoble *c){
	int lon = longitud(c);
	for(int i=0; i<lon ;i++){
		borrarElemento(c,c->inicio);
	}
}
