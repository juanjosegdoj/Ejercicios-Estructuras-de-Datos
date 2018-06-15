#include "TDACola.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
	struct TDACola *col = NULL; 
	col = inicializar();  // cola inicializada
	
	srand(time(NULL));
	
	int tiemEsp, num, emp1 = 0, emp2 = 0, tiempo = 0;
	cout << "Ingrese tiempo de espera: ";
	cin >> tiemEsp;
   
    cout << "tiempos: ";
    for(int i = 1; i <= 20; i++)   // quiere decir que hay 20 usuarios en la cola
    {
    	num = 1 + rand() % (tiemEsp);    // entre 1 y tiempo de espera
    	ingresarCola(col, num);
    	cout << num << "  ,";
    }
	
	cout << "\n\n";
	emp1 = col->inicio->info;
	borrarCola(col);
	
	emp2 = col->inicio->info;
	borrarCola(col);
	
	// empezamos a atender a los clientes
	while(!esVacia(col)){		
		tiempo ++;
		cout << "Tiempo " << tiempo << endl;
		emp1--;
		emp2--;
		if (emp1 == 0){
			emp1 = col->inicio->info;
			borrarCola(col);
			cout << "	Empleado 1, despacha cliente\n";
		}
		if (emp2 == 0){
			emp2 = col->inicio->info;
			borrarCola(col);
			cout << "	Empleado 2, despacha cliente\n";
		}
	}
	
	while(emp2>= 0 || emp1 >= 0){
		tiempo ++;
		cout << "Tiempo " << tiempo << endl;
		emp1--;
		emp2--;
		if (emp1 == 0){
			cout << "	Empleado 1, despacha cliente\n";
		}
		if (emp2 == 0){
			
			cout << "	Empleado 2, despacha cliente\n";
		}
		
	}
	
}					
	
