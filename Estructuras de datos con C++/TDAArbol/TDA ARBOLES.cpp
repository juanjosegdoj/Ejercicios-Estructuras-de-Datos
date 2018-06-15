#include<iostream>
#include<conio.h>
#include<stdlib.h>
# include "TDAArbol.h"
#include "String.h"
using namespace std;


int main(){
	/*
	// para ingresar los datos de una árbol de tacada
	int vec[20]={467,56,798,2,34,89,90,123,45,67,169,8,25,341,563,12,676,1067,1245,88};
	for (int i =0; i < 20; i++){
		Ingresar(Nraiz, vec[i]);
	}
	
	
	// para hacer el de la cantidad de palabras en el texto
	char str[] ="- This, a sample string.";
  	char * pch;
  	//printf ("Splitting string \"%s\" into tokens:\n",str);
  	pch = strtok (str," ,.-");
  	while (pch != NULL)
  	{
   		//printf ("%s\n",pch);
   		cout << pch << endl;
    	pch = strtok (NULL, " ,.-");
  	}
  	return 0;
	*/
	menu();
	return 0;

}

void menu(){
	int dato, opcion;
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
		cout<<"10  Sumatoria de los números del arbol (pt9a)"<<endl;
		cout<<"11  Sumatoria de los números multiplios de un dato ingresado (pt9b)"<<endl;
		cout<<"12  Numeros del arbol en un rango [x1,x2] (pt10)"<< endl;
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
				cout<<"\nDigite un numero: ";
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
				cout<<"\nDigite el numero: ";
				cin>>dato;
				if(Buscar(Nraiz,dato))
					imprimirRecorrido(Nraiz,dato);
				else
					cout << "El elemento ingresado, no existe en el árbol\n";
				system("Pause");
				break;
			
			case 10:
				cout << "Sumatoria de los números del arbol: " << sumatoria(Nraiz) << endl;
				system("pause");
				break;
			
			case 11:
				cout<<"\nDigite el numero: ";
				cin>>dato;
				cout << "Sumatoria de los números del arbol multiplos de "<< dato << " es: " << sumatoriaMultiplos(Nraiz, dato) << endl;
				system("Pause");
				break;
			
			case 12:
				int x1,x2;
				cout<<"Devuelve el numero de claves del arbol dentro de un rango [x1,x2]\n";
				cout<<"x1: ";
				cin >> x1;
				cout<<"x2: ";
				cin >> x2;
				nodosEnRango(Nraiz,x1,x2);
				system("Pause");
				break;
				
			case 13:
				printNivel(Nraiz,0);
				system("Pause");
				break;
				
			case 14:
				Ingresar(Nraiz, 36);
				Ingresar(Nraiz, 16);
				Ingresar(Nraiz, 51);
				Ingresar(Nraiz, 8);
				Ingresar(Nraiz, 41);
				Ingresar(Nraiz, 84);
				break;
		}
		system("cls");
	}while(opcion != 15);
}

