#include<iostream>
#include<conio.h>
#include<stdlib.h>
# include "TDAArbol.h"
using namespace std;


int main(){
	menu();
	return 0;

}

void menu(){
	int dato, opcion;
	int vec[20]={467,56,798,2,34,89,90,123,45,67,169,8,25,341,563,12,676,1067,1245,88};
	for (int i =0; i < 20; i++){
		Ingresar(Nraiz, vec[i]);
	}

	
	cout<<"\n";
	//inOrden(Nraiz);
	system("pause");
	do{
		cout<<"\t MENU"<<endl;
		cout<<"1. Opción 1."<<endl;
		cout<<"2. Opción 2"<<endl;
		cout<<"4. numero mayor"<<endl;
		cout<<"5. Hojas del arbol"<<endl;
 		cout<<"Opcion:";
		cin>>opcion;

		switch(opcion){
			case 1: 
				system("pause");
				break;
			case 2: 
				system("pause");
				break;
			case 3:
				imprimirEntreConNivel(Nraiz, 0);
				system("pause");
				break;
			case 4:
				numMayor(Nraiz);
				system("pause");
				break;
			case 5:
				printHojas(Nraiz);
				system("pause");
				break;
		}
		system("cls");
	}while(opcion!=7);
}

