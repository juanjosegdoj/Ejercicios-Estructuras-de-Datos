# include <iostream>
# include "TDAEstudiante.h"
# include <ctype.h>
# include <string.h>

using namespace std;


int SeleccionMenu(){
	// Muestra barra de opciones y permite la selección de la misma barra de opciones
	
	int select;
	cout << endl << "\n\n1.Seleccionar materias\n2. Pagar la matricula.\n3. A estudiar se dijo.\n4. Salir)\n";
	
	cout << "Seleccione opcion: ";
	cin >> select;
	
	if (select>= 1 and select <= 4)
	{
		return select;
	}
	else {
		return 0;
	}
}

void procesosMatricula()
{
	// todas las opciones para lograr el proceso de matricula
	
	char nombre[20];
	int identificacion;
	
	cout << "Ingrese su nombre: ";
	cin >> nombre;
	
	cout << "Ingrese su identificacion: ";
	cin >> identificacion;
		
	TDAestudiante alumno = CrearEstudiante(nombre,identificacion);  // creando un estudiante	
	int select = SeleccionMenu();
		
	while (4 != select)
	{
		if (select == 1)
		{
			alumno = SeleccionarMaterias(alumno);
		}
		else if (select == 2)
		{
			alumno = PagarMatricula(alumno);
		}
		else  // en su defecto opcion select = 3
		{
			a_estudiar(alumno);
			return ;
		}
		select = SeleccionMenu();
	}	
}

int main(int argc, char** argv) {
	
	// pregunta si quieres pertencer a la univesidad
	
	string ingrU;
	cout << "Hola y bienvenido, ¿Quieres hacer parte de la U?: si/no ";
	cin >> ingrU;
	
	if (ingrU == "no"){
		cout << "gracias por visitarnos, Adios";
		return 0;
	}
	else if (ingrU == "si")
	{
		procesosMatricula();
	} 
	else{
		cout << "No seleccionaste ninguna opción, suponemos que no te interesa, Adios";
	}
	
	return 0;
}
