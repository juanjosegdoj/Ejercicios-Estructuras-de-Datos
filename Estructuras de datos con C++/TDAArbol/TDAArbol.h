#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

struct Nodo{
	int dato;
	Nodo *der;
	Nodo *izq;
};
void menu();
Nodo *CrearNodo(int);
void Ingresar(Nodo*&, int);
void Borrar(Nodo *&, int);
bool Buscar(Nodo*, int);
Nodo *Nraiz = NULL;
void preOrden(Nodo*);
void postOrden(Nodo*);
void inOrden(Nodo*);


Nodo *CrearNodo(int eleing){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = eleing;
	nuevo_nodo->der = NULL;
	nuevo_nodo->izq = NULL;
	return nuevo_nodo;
}

void Ingresar(Nodo *&Nraiz, int eleing){
	if(Nraiz == NULL){
		Nodo *nuevo_nodo= CrearNodo(eleing);
		Nraiz = nuevo_nodo;
	}
	else if(Buscar(Nraiz, eleing)==true){
			cout<<"\nNumero Repetido";
	}
	else{
		int valorRaiz = Nraiz -> dato;
		if(eleing < valorRaiz){
			Ingresar(Nraiz->izq, eleing);
		}
		else{
			Ingresar(Nraiz->der,eleing);
		}
	}
}

void Eliminar(Nodo *Nraiz, int elemPop, Nodo *papa){
	
	if(Nraiz == NULL){
		cout << "Elemento no encontrado\n";
		return ;
	}
	else if(Nraiz->dato == elemPop){
		Nodo *copyNodo = Nraiz; // copia
		
		if(Nraiz->izq == NULL && Nraiz->der == NULL){
			if(papa->der == Nraiz){
				papa->der = NULL;
				delete(copyNodo);
			}else{
				papa->izq = NULL;
				delete(copyNodo);
			}
		}else if(Nraiz->izq == NULL){
			// trabajo con el derecho
			if(papa->der == Nraiz){
				papa->der = Nraiz->der;
			}else{
				papa->izq = Nraiz->der;
			}
			delete(copyNodo);
		}else if(Nraiz->der == NULL){
			// trabajo con el izquierdo
			if(papa->der == Nraiz){
				papa->der = Nraiz->izq;
			}else{
				papa->izq = Nraiz->izq;
			}
			delete(copyNodo);
		}else{
			cout << "Acabo de entrar a la funcion con 2 hijos\n";
			// si ha llegado hasta acá es porque tiene 2 hijos  
			Nodo *aux = Nraiz, *antToAux;  // raíz en su parte izquierda, y ahora a buscar el menor
			
			while(aux->der != NULL || aux->izq != NULL){    // buscando el mínimo dato de los mayores que la raíz
				antToAux = aux;
				cout << aux->dato <<" - ";
				if(aux->izq != NULL){
					aux = aux->izq;
				}else{
					aux = aux->der;
				}
			}
			cout << "EL minimo es "<< aux->dato << endl; 
			
			Nraiz->dato = aux->dato;
			if(antToAux->der == aux){
				antToAux->der = NULL;
			}else if(antToAux->izq == aux){
				antToAux->izq = NULL;
			}
			delete(aux);
		}
		return ;
	}
	else if(elemPop < Nraiz->dato){
		return Eliminar(Nraiz->izq, elemPop, Nraiz);
	}
	else{
		return Eliminar(Nraiz->der, elemPop, Nraiz);
	}
}

bool Buscar(Nodo *Nraiz, int eleing){
	if(Nraiz == NULL){
		return false;
	}
	else if(Nraiz->dato == eleing){
		return true;
	}
	else if(eleing < Nraiz->dato){
		return Buscar(Nraiz->izq, eleing);
	}
	else{
		return Buscar(Nraiz->der, eleing);
	}
}

void preOrden(Nodo *Nraiz){
	if(Nraiz == NULL){
		cout << " - ";
	}
	else{
		cout << "( ";
		cout << Nraiz->dato;
		inOrden(Nraiz->izq);
		inOrden(Nraiz->der);
		cout << ")";
	}
}

void postOrden (Nodo *Nraiz){
	if(Nraiz == NULL){
		cout << " - ";
	}
	else{
		cout << "( ";
		postOrden(Nraiz->izq);
		postOrden(Nraiz->der);
		cout << Nraiz->dato;
		cout << " )";
	}
}

void inOrden (Nodo *Nraiz){
	if(Nraiz == NULL){
		cout << " - ";
	}
	else{
		cout << "( ";
		inOrden(Nraiz->izq);
		cout << Nraiz->dato; 
		inOrden(Nraiz->der);
		cout << " )";
	}
}

void imprimirRecorrido(Nodo *Nraiz, int datoB){
	
	if(Nraiz == NULL){
		cout << "El dato no existe en el árbol\n";
		return ;
	}
	else if(Nraiz->dato == datoB){
		cout << " - " << Nraiz->dato << " - " << endl;
		return ;
	}
	else if(datoB < Nraiz->dato){
		cout << " - " << Nraiz->dato;
		imprimirRecorrido(Nraiz->izq, datoB);
	}
	else{
		cout << " - " << Nraiz->dato;
		imprimirRecorrido(Nraiz->der, datoB);
	}
}

void printNivel(Nodo *Nraiz, int nivel){
	if(Nraiz != NULL){
		printNivel(Nraiz->izq,nivel+1);
		cout << "(" << nivel << ")"<< Nraiz->dato << ", ";
		printNivel(Nraiz->der, nivel+1);
	}
}



int numHojas (Nodo *Nraiz){
	if(Nraiz != NULL){
		if(Nraiz->izq == NULL && Nraiz->der == NULL){
			return 1+numHojas(Nraiz->izq)+numHojas(Nraiz->der);
		}
		else
			return 0+numHojas(Nraiz->izq)+numHojas(Nraiz->der);
	}
}

int sumatoriaMultiplos(Nodo *Nraiz, int numero){
	if(Nraiz == NULL)
		return 0;
	else{
		if(Nraiz->dato%numero == 0)
			return Nraiz->dato+sumatoriaMultiplos(Nraiz->izq, numero)+sumatoriaMultiplos(Nraiz->der,numero);
		else
			return 0+sumatoriaMultiplos(Nraiz->izq,numero)+sumatoriaMultiplos(Nraiz->der, numero);
	}
}

int longitud(Nodo *Nraiz){
	if(Nraiz == NULL)
		return 0;
	else
		return 1+longitud(Nraiz->izq)+longitud(Nraiz->der);
}

void nodosEnRango(Nodo *Nraiz, int x1, int x2){
	if(Nraiz == NULL)
		return ;
	else{
		if(Nraiz->dato >= x1 && Nraiz->dato <= x2){
			cout << Nraiz->dato << " - ";
		}
		nodosEnRango(Nraiz->izq, x1,x2);
		nodosEnRango(Nraiz->der,x1,x2);
	}
}

int sumatoria(Nodo *Nraiz){
	if(Nraiz == NULL)
		return 0;
	else
		return Nraiz->dato+sumatoria(Nraiz->izq)+sumatoria(Nraiz->der);
}

