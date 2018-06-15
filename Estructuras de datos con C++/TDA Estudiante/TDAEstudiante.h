# include <iostream>
# include <string.h>

/*  Ejercicio de estructuras de un estudiante, en  donde se enfoca desde el proceso de matricula
1. Crear estudiante
2. Seleccionar materias 
3. Pagar la matricula
4. y por último, después de haber hecho todos los anteriores requisitos: a_estudiar()
*/


using namespace std;

struct TDAestudiante{
	// estructuta de la informacion de un estudiante y los booleanos que debe cumplir para estudiar
	
	string nombreEstudiante;
	int identificacionEstudiante;
	bool materiasSeleccionadas;
	bool matriculaCancelada;
};

TDAestudiante CrearEstudiante(string nombre,int documentoID){
	// Crea un nuevo estudiante que posiblemente se matricule
	
	struct TDAestudiante est;
	est.nombreEstudiante = nombre;
	est.identificacionEstudiante = documentoID;
	
	return est;	
}

TDAestudiante SeleccionarMaterias(TDAestudiante student){
	// funcion para seleccionar materias
	
	student.materiasSeleccionadas = true;
	cout << "\nMaterias selccionadas con éxito\n";
	return student;
}

TDAestudiante PagarMatricula(TDAestudiante student){
	// Cancelación del valor de la matricula, tendiendo en cuenta que ya debió haber seleccionado materias
	
	if (student.materiasSeleccionadas == false){
		cout << "Primero debe seleccionar las materias, antes de cancelar\nPago de matricula cancelado" << endl;
		return student;
	} 
	else {
		student.matriculaCancelada = true;
		cout << "El pago de la matricula se efectuó con éxito";
		return student;
	}
}

void a_estudiar(TDAestudiante student){
	// El estudiante incia a estudiar cuando ya ha seleccionado materias y cancelado matricula
	
	if(student.materiasSeleccionadas == false){
		cout << "No puedes estudiar sin haber seleccionado las materias y sin haber cancelado la matricula";
	}
	else if (student.materiasSeleccionadas == false){
		cout << "Antes de estudiar debes cancelar tu matricula";
	} else{
		cout << "---------------------------------------------------------------------\n";
		cout << "A estudiar se dijo, las clases incian pasado mañana, bienvenido a la U\n";
		cout << "---------------------------------------------------------------------\n";
	}
}


