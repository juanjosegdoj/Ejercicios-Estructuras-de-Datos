#include "TDACola.h"
#include <bits/stdc++.h>
#include <String.h>
#include "TDAPila.h"

using namespace std;

int main(int argc, char** argv) {
	int capacidad = 0;
	int opcion;
	string elemento;
	
	// creando pila para cuando haya que mover aviones
	TDAPila *cab=NULL;
	cab = inicializarP();  // inicializando pila
	
	// creando tdaCola 
	struct TDACola *col = NULL; 
	col = inicializar();
	
	// Creando pila aviones en espera 
	struct TDACola *colEsp = NULL;
	colEsp = inicializar();
	
	
	//cout<<"Cola inicializada";  
	do {
        system("CLS");
        cout<<"---- Apacamiento de aviones -----\n\n";
        cout<<"1. Mostrar Avion en la izquierda y la derecha\n";
        cout<<"2. hay aviones en el aparcamiento\n";
        cout<<"3. Entrada de un nuevo avion\n";
        cout<<"4. Darle salida al avion que esta a la derecha\n"; 
        cout<<"5. Salida de avion en especifico\n";
        cin>>opcion;
        switch (opcion)
        {
       		case 1:
       			if(!esVacia(col)){					   
	       			cout<<"Derecha: "<<col->inicio->info<<"\n";
	       			cout<<"Izquierda: "<< col->cola->info<<"\n";
	       		
				}else
					cout<<"Parqueadero vacio\n";
				system("Pause");
				break;
			case 2:
				if(esVacia(col))
					cout << "No hay aviones en el aparcamiento\n";
				else
					cout << "exiten aviones en el aparcamiento\n";
				system("Pause");
				break;				
			case 3:
					cout<<"Ingrese el matricula del avion: ";
					cin>>elemento;
					if(capacidad<12){
						ingresarCola(col, elemento);
						capacidad++;
					}else{
						ingresarCola(colEsp, elemento);
						cout << "parqueadero lleno, AVION EN ESPERA\n";
					}
					system("Pause");
					break;
			case 4:
				if (esVacia(col))	
					cout << "Parqueadero vacio\n" ;
				else
					cout<<"El avion "<<col->inicio->info<<" se le ha dado salido del aparcamiento\n";
					borrarCola(col);
					capacidad--;
					
					// Para ingresar un nuevo avion que esta en espera
					if(!esVacia(colEsp) && capacidad == 11){
						ingresarCola(col, colEsp->inicio->info);
						borrarCola(colEsp);
						capacidad++;
					}
					
				system("Pause");
				break;
			case 5:
				cout<<"Ingrese matricula de avion aparcado: ";
				cin>>elemento;	
				
				while(!esVacia(col) && col->inicio->info!=elemento){
					push(cab, col->inicio->info);  // añadiendo a pila
					borrarCola(col); 
				}
				if(esVacia(col)){
					cout << "La matricula ingresada no pertenece a ningún avion aparcado\n";
				}else{
					cout<<"El avion "<<col->inicio->info<<" ha salido del aparcamiento\n";
					borrarCola(col);
					capacidad--;
				}
				while(!Esvacia(cab)){  // mientras la pila no esté vacía, añada todo eso al aparcamiento que es la cola
					ingresarInicio(col, cab->tope->info);
					pop(cab);
				}
				cout << "\n";
				
				// Para ingresar un nuevo avion que esta en espera
				if(!esVacia(colEsp) && capacidad == 11){
					ingresarCola(col, colEsp->inicio->info);
					borrarCola(colEsp);
					capacidad++;
				}
				system("Pause");
				break;
		}
    } while (opcion !=50);
	return 0;
}					
				

