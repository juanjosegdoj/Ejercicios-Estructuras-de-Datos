#include "TDAPila.h"
#include <bits/stdc++.h>
#include <String.h>

int main(int argc, char** argv) {
	TDAPila *cab=NULL;
	int opcion;
	int elemento;
	cout<<"Pila inicializada";  	
	cab =inicializarP();
	do {
        system("CLS");
        cout<<"USO TDA Pila  \n\n\n";
        cout<<"1. Mostrar elemento en la pila\n";
        cout<<"2. Pila es vacia\n";
        cout<<"3. Agregar elemento a la pila\n";
        cout<<"4. Eliminar nodo" << endl;
        cin>>opcion;
        switch (opcion)
        {
       		case 1:
       			if (Esvacia(cab))	
					cout << "Lista vacia\n";
				else
					cout<<cab->tope->info<<"\n";
			case 2:
					cout<< Esvacia(cab);
					system("Pause");
					break;
			case 3:
					cout<<"Ingrese el elemento: ";
					cin>>elemento;
					push(cab,elemento);
					break;
			case 4:
				if (Esvacia(cab))	
					cout << "Lista vacia\n" ;
				else
					pop(cab);
	}
    } while (opcion !=50);
	return 0;
}					
				

