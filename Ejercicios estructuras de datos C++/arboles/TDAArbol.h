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
Nodo *Nraiz2 = NULL;
Nodo *Nraiz3 = NULL;
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


void imprimirEntreConNivel(Nodo *Nraiz, int nivel){
    if(Nraiz != NULL){
	    imprimirEntreConNivel(Nraiz->izq,nivel+1);
        cout << Nraiz->dato << "(" << nivel << ") - ";
        imprimirEntreConNivel(Nraiz->der,nivel+1);
    }
}

void Borrar(Nodo *&Nraiz, int elebor) {
   Nodo *actual;
   if (Nraiz ==NULL) {
        cout<<"\nÁrbol vacío";
   }
   
   else {
        actual = Nraiz;
        Nodo *padre=NULL;
        int encontrar =0;
        while(actual!=NULL && !encontrar) { 
            if(elebor== actual->dato) { 
                encontrar =1;
                if (Nraiz == actual) {
                    /*Elemento a borrar es la raiz*/
                }
                else {
                    if (actual->der==NULL && actual->izq==NULL)
                        if (padre->der == actual)
                            padre->der=NULL;
                        else
                            padre->izq=NULL;
                    else 
                        if (actual->izq==NULL && actual->der!=NULL)
                            if (padre->der == actual)
                                padre->der=actual->der;
                            else
                                padre->izq=actual->der;
                        else
                            if (actual->izq!=NULL && actual->der==NULL)
                                if (padre->der == actual)
                                    padre->der=actual->izq;
                                else
                                    padre->izq=actual->izq;
                            else {
                                Nodo *aux;
                                aux = actual->izq;
                                while (aux->der != NULL)
                                    aux= aux->der;
                                aux->der=actual->der;
                                if (padre->der == actual)
                                    padre->der=aux;
                                else
                                    padre->izq=aux;
                            }
                }
                    
            }
            else { 
                padre = actual;
                if(elebor > actual->dato) 
                    actual = actual->der;
                else 
                    actual = actual->izq; 
            }
    }
    if (encontrar == 0)
        cout<<"\nElemento NO encontrado";
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
	if (Nraiz != NULL){
		cout<< Nraiz->dato<<" ";
		preOrden(Nraiz->izq);
		preOrden(Nraiz->der);
	}
}

void printHojas (Nodo *Nraiz){
	if(Nraiz != NULL){
		if(Nraiz->izq == NULL && Nraiz->der == NULL){
			cout << Nraiz->dato << " - ";
			printHojas(Nraiz->izq);
			printHojas(Nraiz->der);
		}
		else{
			printHojas(Nraiz->izq);
			printHojas(Nraiz->der);
		}
	}
}

void postOrden (Nodo *Nraiz){
	if (Nraiz != NULL){
		postOrden(Nraiz->izq);
		postOrden(Nraiz->der);
		cout<< Nraiz->dato<<" "; 
	}
}


int numMayor(Nodo *Nraiz){
	if (Nraiz->der != NULL){
		return numMayor(Nraiz->der);
	}else{
		return Nraiz->dato;
	}
}

void inOrden (Nodo *Nraiz){
	if (Nraiz != NULL){
		inOrden(Nraiz->izq);
		cout<< Nraiz->dato<<" "; 
		inOrden(Nraiz->der);		
	}
}



