#include "TDACola.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
	struct TDACola *col = NULL; 
	col = inicializar();  // cola inicializada
	
	srand(time(NULL));
	
	int cantidadRecaudada = 0, cantidadHamburg = 0, num;
	int numPers = 10 + rand() % (71);   // random de número de personas 
   
    for(int i = 0; i < numPers; i++)   // quiere decir que hay 20 usuarios en la cola
    {
    	num = 1 + rand() % (5);    // entre 1 y 5
    	ingresarCola(col, num);
    }
	
	for(int i = 1; i <= numPers; i++){
		if(i % 10 == 0){
			cantidadRecaudada -= 4500;
		}
		cantidadRecaudada += col->inicio->info*4500;
		cantidadHamburg += col->inicio->info;
		borrarCola(col);
	}
	
	cout << "Personas atendidas: " << numPers << endl;
	cout << "Cantidad de hamburguesas vendidas es: " << cantidadHamburg << endl;
	cout << "Numero de haburguesas regaladas: " << numPers/10 << endl;
	cout << "La cantidad Recaudada es: " << cantidadRecaudada;

}					
	
