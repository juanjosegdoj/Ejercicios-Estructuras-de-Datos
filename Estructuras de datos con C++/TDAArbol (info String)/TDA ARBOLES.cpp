#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include "TDAArbol.h"
#include "String.h"
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>

using namespace std;

template<typename Out>

void split(const std::string &s, char delim, Out result) {
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        *(result++) = item;
    }
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    split(s, delim, std::back_inserter(elems));
    return elems;
}


int main(){

	
	/*
	// para ingresar los datos de una árbol de tacada
	int vec[20]={467,56,798,2,34,89,90,123,45,67,169,8,25,341,563,12,676,1067,1245,88};
	for (int i =0; i < 20; i++){
		Ingresar(Nraiz, vec[i]);
	}
	
	*/
	menu();
	return 0;

}

void menu(){
	string dato;
	int opcion;
	do{
		cout<<"\t MENU"<<endl;
		cout<<"1. Ingresar un numero."<<endl;
		cout<<"2. Buscar elemento."<<endl;
        cout<<"3. Imprimir Preorden"<<endl;
		cout<<"4. Imprimir Postorden"<<endl;
		cout<<"5. Imprimir inOrden"<<endl;
		cout<<"6. Borrar Elemento"<<endl;
		cout<<"7. Numero de hojas (pt7)"<<endl;
		cout<<"8  Numero de hijos (pt8)"<<endl;
		cout<<"9. Imprimir recorrido de elemento (pt6)"<<endl;
		cout<<"10  Texto para cantidad de palabras en texto"<<endl;
		cout<<"13  Imprimir datos con sus niveles\n";
		cout<<"14. Crear un arbol aleatorio"<<endl;
		cout<<"15. Salir."<<endl;
		cout<<"Opcion:";
		cin>>opcion;

		switch(opcion){
			case 1: cout<<"\nDigite un numero: ";
				cin>>dato;
				Ingresar(Nraiz, dato);
				cout<<"\n";
				system("pause");
				break;
				
			case 2: cout<<"\nEscriba el numero que desea buscar: ";
					cin>>dato;
					if(Buscar(Nraiz, dato)==true){
						cout<<"\nNumero "<<dato<<" encontrado en el arbol.\n";
					}
					else{
						cout<<"Numero no encontrado.\n";
					}
					cout<<"\n";
					system("pause");
					break;
					
			case 3: preOrden(Nraiz);
					system("pause");
					break;
					
			case 4: postOrden(Nraiz);
					system("pause");
					break;
					
			case 5: inOrden(Nraiz);
					system("pause");
					break;
					
			case 6: 
				cout<<"\nIngrese un dato a borrar: ";
				cin>>dato;
				Eliminar(Nraiz, dato, NULL);
				cout<<"\n";
				system("pause");
				break;
				
			case 7: 
				cout << "el numero de hojas es: " << numHojas(Nraiz) << endl;
				system("pause");
				break;
				
			case 8: 
				cout << "el numero de hijos es: " << longitud(Nraiz)-1 << endl;
				system("pause");
				break;
				
			case 9:
				cout<<"\nDigite el dato: ";
				cin>>dato;
				if(Buscar(Nraiz,dato))
					imprimirRecorrido(Nraiz,dato);
				else
					cout << "El elemento ingresado, no existe en el árbol\n";
				system("Pause");
				break;
			
			case 10:
				string texto;
				cout << "Ingrese texto: ";
				cin>>texto;
				
				vector<string> palabras = split(texto, ' ');
				
				for(int i=0; i<palabras.size(); i++){
					Ingresar(Nraiz, palabras[i]);
				}
				
				for(int i=0; i<palabras.size(); i++){
					cout << palabras[i];
				}
				palabrasRepetidas(Nraiz);
				system("Pause");
				break;
						
			case 13:
				printNivel(Nraiz,0);
				system("Pause");
				break;
				
			case 14:
				Ingresar(Nraiz, "36");
				Ingresar(Nraiz, "16");
				Ingresar(Nraiz, "51");
				Ingresar(Nraiz, "8");
				Ingresar(Nraiz, "41");
				Ingresar(Nraiz, "84");
				break;
		system("cls");
	}while(opcion != 15);
}

