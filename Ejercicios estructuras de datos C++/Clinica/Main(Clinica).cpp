#include "clinica.h"
#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;


int main(int argc, char** argv) {
	srand(time(NULL));
	
	int opcion, numDoct, random;
	string namePac, nameDoc;
	
	numDoct = 2+rand()%11;   // entre 2 y 12 doctores pueden haber en la clínica
	
	cout << "Numero de doctores en la clinica " << numDoct << endl;
	system("Pause");
	string muchosNombres[20] = {"Andres","Esteban","Camilo","Ana","Josefo","Gloria","Estefania","Anyi","Lucas",
	"Fabio","Marina","Camila","Eustasio","Roberto","Armando","Carlos","Victor","Ester","Felipe","Sofia"};
	
	TDA_Entrada entradas[numDoct];	
	
	for(int i=0; i<numDoct; i++){    
		random = rand()%20;
		while(muchosNombres[random] == "1"){
			random = rand()%20;
		}
		
		entradas[i].doctor = crearOftamologo(muchosNombres[random],1+rand()%60);
		entradas[i].cola = inicializar();
		muchosNombres[random] = "1";
	}
	
	do {
        system("CLS");
        cout<<"     Clinica y legumbrería la tortugas\n\n";
        cout<<"1. Ingresar nuevo paciente\n";
        cout<<"2. Indicar consultorios liberados\n";
        cout<<"3. Proximo paciente\n";
        cout<<"4. Salir\n  :";
        cin>>opcion;
        switch (opcion)
        {
       		case 1:
       			cout << "Nombre del paciente: ";
       			cin >> namePac;
       			cout << "Nombre del doctor: ";
       			cin >> nameDoc;
       			nuevoPaciente(namePac, nameDoc, entradas, numDoct);
       			system("pause");
				break;
			case 2:
				for(int i=0; i<numDoct; i++){
					if(esVacia(entradas[i].cola)){
						cout << "El doctor " << entradas[i].doctor.nombre << " tiene el consultorio liberado\n";
					}else{
						cout << "El próxima paciente del doctor " << entradas[i].doctor.nombre << " es: " << entradas[i].cola->inicio->info << endl;
					}
				}
				system("pause");
				break;
			case 3:
       			cout << "Nombre del doctor: ";
       			cin >> nameDoc;
				proximaPaciente(nameDoc,entradas,numDoct);
				system("pause");
				break;
		}
	} while(opcion != 4);
}
