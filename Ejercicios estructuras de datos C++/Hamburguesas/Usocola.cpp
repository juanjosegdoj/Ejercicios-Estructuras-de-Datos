#include "TDACola.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	struct TDACola *col = NULL; 
	int opcion;
	int elemento;
	col = inicializar();
	cout<<"Cola inicializada";  
	do {
        system("CLS");
        cout<<"USO TDA Cola\n\n";
        cout<<"1. Mostrar inicio y cola\n";
        cout<<"2. cola es vacia\n";
        cout<<"3. Ingresar en Cola\n";
        cout<<"4. Ingresar en Incio\n";
        cout<<"5. Borrar en Cola" << endl;
        cin>>opcion;
        switch (opcion)
        {
       		case 1:
       			if(!esVacia(col)){					   
	       			cout<<"Inicio: "<<col->inicio->info<<"\n";
	       			cout<<"Cola: "<< col->cola->info<<"\n";
	       			system("Pause");
				}else
					cout<<"Lista vacía\n";
				break;
			case 2:
					cout<< esVacia(col) << "\n";
					system("Pause");
					break;				
			case 3:
					cout<<"Ingrese el elemento: ";
					cin>>elemento;
					ingresarCola(col, elemento);
					system("Pause");
					break;
			case 4:
					cout<<"Ingrese el elemento: ";
					cin>>elemento;
					ingresarInicio(col, elemento);
					system("Pause");
					break;	
			case 5:
				if (esVacia(col))	
					cout << "Lista vacia\n" ;
				else
					borrarCola(col);
				system("Pause");
		}
    } while (opcion !=50);
	return 0;
}					
				

