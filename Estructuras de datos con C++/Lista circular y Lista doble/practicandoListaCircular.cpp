#include <iostream> 
#include "TDAListaCircular.h"
using namespace std; 
int main(int argc, char** argv) {
	TDALista *c = NULL;
	char res;
	c = Inicializar();
	int num, numero;
		
	
	do {
		cout<<"Ingrese valor:  ";
		cin>>numero;
		c = crearLista(c, numero);
        cout<<"Desea continuar S/N? ";
        cin>>res;
	} while (res!='N' && res!='n');
	
	cout << "Ingrese elemento clave: ";
	cin >> num;
	
	Nodo *aux;
	aux=c->inicio;
	do{	
		if(aux->info <= num){
			cout << "Entra elemento: " << aux->info << endl;
			BorrarElemento(c, aux);
			aux = c->inicio;
		}
		aux=aux->sig;
		cout << "-";
	
	}while (aux != c->inicio);
	
	
	
	cout << "\nLista resultante\n\n";
	ImprimirLista(c);
}

