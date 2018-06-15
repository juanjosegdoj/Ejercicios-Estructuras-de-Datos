#include <iostream> 
#include "TDAListaSencilla.h"
using namespace std; 
int main(int argc, char** argv) {
	TDALista *cab=NULL;
	int numero, opcion;
	char res;
	do {
        system("CLS");
        cout<<"USO TDA Lista  \n\n\n";
        cout<<"1.  Crear la lista\n";
        cout<<"2.  Imprimir la lista\n";
        cout<<"8.  Salir \n ";
        cin>>opcion;
        switch (opcion)
        {
            case 1:  	
				do {
					cout<<"Ingrese valor:  ";
					cin>>numero;
					cab = crearLista(cab, numero);
        			cout<<"Desea continuar S/N? ";
        			cin>>res;
				} while (res!='N' && res!='n');
                break;
            case 2:
            	ImprimirLista(cab);
            	system("Pause");
            	break;
           
        }
    } while (opcion !=8);
	return 0;
}
