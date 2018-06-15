#include <iostream> 
#include <String.h>
#include "TDACola.h"

struct TDA_oftalmologo{
	string nombre;
	int tiempoA;  // tiempo de atención
};

struct TDA_Entrada{   // esto hace las veces de un consultorio
	TDACola *cola;
	TDA_oftalmologo doctor;
};

string getNombre(TDA_oftalmologo doctor){
	return doctor.nombre;
}

void proximaPaciente(string nombOfta, TDA_Entrada entradas[], int tam){


	for(int i=0; i<tam; i++){
		if(getNombre(entradas[i].doctor) == nombOfta){
			if(esVacia(entradas[i].cola)){
				cout << "No hay ningun paciente en espera\n";
				return;
			}
			else{
				cout << "El paciente " << entradas[i].cola->inicio->info << " esta siendo atendido\n"; // pues ya salió de la cola
				borrarCola(entradas[i].cola);
				if(!esVacia(entradas[i].cola)){
					cout << "Paciente en espera: "  << entradas[i].cola->inicio->info << endl;
				}else{
					cout << "no hay ningun paciente en espera\n";
					return;
				}
			}
		}
	}
	system("pause");
}

void nuevoPaciente(string nombPac, string nombOfta, TDA_Entrada entradas[], int tam){
	int sw = 1;
	for(int i=0; i<tam; i++){
		if(getNombre(entradas[i].doctor) == nombOfta){
			ingresarCola(entradas[i].cola, nombPac);
			cout << "el doctor "+getNombre(entradas[i].doctor) << " tiene un nuevo paciente" <<endl;
			sw = 0;
		}
	}
	if(sw)
		cout << "No existe ningún doctor en la clínica con el nombre ingresado\n";
}

TDA_oftalmologo crearOftamologo(string nombre, int tiempoA){
	TDA_oftalmologo doctor;
	doctor.nombre = nombre;
	doctor.tiempoA = tiempoA;
	return doctor;
}



