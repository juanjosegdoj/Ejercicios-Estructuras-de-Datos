#include "TDAListaDoble.h"

using namespace std;

int main(int argc, char** argv) {
	TDAListaDoble *cab=NULL;
	
	cab = Inicilizar();  // inicializar
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
	
	cab = ordenar(cab);
	int len = longitud(cab);
	if (len%2 == 0){
		
	}
	
	
}
