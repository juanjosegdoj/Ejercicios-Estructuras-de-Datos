#include "TDAListaDoble.h"

using namespace std;

int main(int argc, char** argv) {
	TDAListaDoble *cab=NULL;
	
	// inicializar
	cab = Inicilizar();
	int numero, opcion;
	char res;
	
	do {
		cout<<"Ingrese valor:  ";
		cin>>numero;
		
		if(!buscar(numero,cab)){
			cab = crearLista(cab, numero);
			cout << "Elemento ingresado\n";
		}else{
			cout << "El elemento ya esta\n";
		}
		
		
	    cout<<"Desea continuar S/N? ";
	    cin>>res;
	} while (res!='N' && res!='n');
	
	cout << "------------- Imprimir la lista -------------\n\n";
	ImprimirLista(cab);
}
