#include "TDAListaDoble.h"

using namespace std;

int main(int argc, char** argv) {
	TDAListaDoble *cab=NULL, *cab2= NULL;
	
	int cont = 0;
	
	// inicializar
	cab = Inicilizar();
	cab2 = Inicilizar();
	int numero, opcion;
	char res;
	
	// añadiendo todo
	do {
		cout<<"Ingrese valor:  ";
		cin>>numero;
		cab = crearLista(cab, numero);
	    cout<<"Desea continuar S/N? ";
	    cin>>res;
	} while (res!='N' && res!='n');
	
	
	// empiezo a recorrer
	if (cab->inicio==NULL){
		cout<<"\n"<<"La lista no está creada";
	}
	else {
	    Nodo *aux;
		aux=cab->inicio;
		
		do{
			if(!buscar(aux->info,cab2)){
				cab2 = crearLista(cab2, aux->info);  
			}
			cout << "0\t";
			aux=aux->sig;
		}while (aux != NULL);
	}
	
    cout<<"\n";
	
	cout << "------------- Cantidad -------------\n\n";
	cout << "El numero de elemntos diferentes es: " << longitud(cab2) << endl;
	ImprimirLista(cab2);
}
