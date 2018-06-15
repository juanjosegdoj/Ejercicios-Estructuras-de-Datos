#include "TDAListaDoble.h"

using namespace std;

int main(int argc, char** argv) {
	TDAListaDoble *cab=NULL, *cab2 = NULL;
	
	cab = Inicilizar();  // inicializar
	cab2 = Inicilizar();
	int numero;
	char res;
	
	// Agrrgando elementos a lista doble
	do {
		cout<<"Ingrese valor:  ";
		cin>>numero;
		cab = crearLista(cab, numero);
	    cout<<"Desea continuar S/N? ";
	    cin>>res;
	}while (res!='N' && res!='n');
	
	
}
