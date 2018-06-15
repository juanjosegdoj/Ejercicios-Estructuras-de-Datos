
// indices.cpp: Ejemplo de ficheros de acceso aleatorio con índices.
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream> 
#include "TDAListaCarrera.h"

using namespace std;

struct stRegistro {
   char snBorrado;  // Campo que indica si el registro es borrado S->Borrado, N->No borrado
   char nombre[34];
   char apellido[2][34];
   char telefono[10];
   char ciudad[20];
   char carrera[20];
};


int Menu();
void Capturar(stRegistro &reg);
void EliminarRetornoLinea(char *cad);
void Leer(FILE *fa, stRegistro &reg, char *telefono);
void Insertar(FILE *fa, stRegistro &reg);
void Mostrar(stRegistro &reg);
void Listar(FILE *fa);
TDAListaCarrera *ordenar();
void printCarreras(TDAListaCarrera *cabCarrera);
void menuArchivos();


int main()
{
	TDAListaCarrera *cabCarreras=NULL;
	cabCarreras = ordenar();
	
	int option;
	string nomCarr;
	while(option != 4){
		system("cls");
		cout << "  MENU ESTUDIANTES \n\n";
		cout << "1. Mostrar estudiantes de todas las carreras\n";
		cout << "2. Menu de manejo de arhivos planos\n";
		cout << "3. Consultar estudiantes de una carrera en especifico\n";
		cout << "4. Salir del programa\n";
		cout << "Ingrese opcion: ";
		cin >> option;
		if(option == 1){
			printCarreras(cabCarreras);
		}else if(option == 2){
			menuArchivos();
		}else if(option == 3){
			cout << "Nombre carrera: ";
			cin >> nomCarr;
			printEstudCarr(cabCarreras, nomCarr);   // falta organizar esta parte y listo
			system("Pause");
		}	
	}
}

TDAListaCarrera *ordenar()   // Ordena los estudiantes por carreras
{
   stRegistro reg;
   FILE *fa;
   fa = fopen("indices.dat", "r+b");          // Este modo permite leer y escribir
   if(!fa) fa = fopen("indices.dat", "w+b");  // si el fichero no existe, lo crea
   
   TDAListaCarrera *cabCarreras=NULL;
   NodoCar *aux;
	
   //stRegistro reg;
   rewind(fa);
   system("cls");
   while(fread(&reg, sizeof(stRegistro), 1, fa)) {
   		int i;
		if(reg.snBorrado == 'S') {
			
			if(!buscar(reg.carrera, cabCarreras)){
	     // cuando se crea una nueva carrera, esto también incluye un nuevo estudiante
				cabCarreras = InsertOrden(cabCarreras,reg.carrera, reg.nombre);
			}else{			
				aux=cabCarreras->inicio;
				while (aux!=NULL){

					if(aux->carrera == reg.carrera){
						aux->stud = crearListaE(aux->stud,reg.nombre);
					}
					aux=aux->sig;
				}	
			}
		}
   }
   fclose(fa);
   return cabCarreras;
}


void printCarreras(TDAListaCarrera *cabCarreras)
{
	cout << "IMPRIMIENDO TODAS LAS CARRERAS \n\n";
   stRegistro reg;
   FILE *fa;
   int opcion;
   char telefono[10];

   fa = fopen("indices.dat", "r+b");          // Este modo permite leer y escribir
   if(!fa) fa = fopen("indices.dat", "w+b");  // si el fichero no existe, lo crea.
   ImprimirLista(cabCarreras);
   fclose(fa);
   system("Pause");
}

void menuArchivos()
{
	cout << "------------ MENU DE MANEJO DE ARCHIVOS ------------\n\n";
	
   stRegistro reg;
   FILE *fa;
   int opcion;
   char telefono[10];

   fa = fopen("indices.dat", "r+b");          // Este modo permite leer y escribir
   if(!fa) fa = fopen("indices.dat", "w+b");  // si el fichero no existe, lo crea.

   do {
      opcion = Menu();
      switch(opcion) {
         case '1': // Insertar registro
            Capturar(reg);
            Insertar(fa, reg);
            break;
         case '2': 
            Listar(fa);
            break;
     	}
   } while(opcion != '0');
   fclose(fa);
}

// Muestra un menú con las opciones disponibles y captura una opción del usuario
int Menu()
{
   char resp[20];

   do {
      system("cls");
      printf("MENU PRINCIPAL Estudiantes\n");
      printf("--------------\n\n");
      printf("1- Insertar registro\n");
      printf("2- Listar registro\n");
      printf("0- Salir\n");
      fgets(resp, 20, stdin);
   } while(resp[0] < '0' && resp[0] > '5');
   return resp[0];
}

// Permite que el usuario introduzca un registro por pantalla
void Capturar(stRegistro &reg)
{
   int i;
   char numero[6];

   system("cls");
   printf("Leer registro:\n\n");
   reg.snBorrado = 'S';
   printf("Nombre: ");
   fgets(reg.nombre, 34, stdin);
   EliminarRetornoLinea(reg.nombre);
   printf("Primer apellido: ");
   fgets(reg.apellido[0], 34, stdin);
   EliminarRetornoLinea(reg.apellido[0]);
   printf("Segundo apellido: ");
   fgets(reg.apellido[1], 34, stdin);
   EliminarRetornoLinea(reg.apellido[1]);
   printf("Teléfono: ");
   fgets(reg.telefono, 10, stdin);
   EliminarRetornoLinea(reg.telefono);
   printf("Ciudad: ");
   fgets(reg.ciudad, 20, stdin);
   EliminarRetornoLinea(reg.ciudad);
   
   printf("Carrera: ");
   fgets(reg.carrera, 20, stdin);
   EliminarRetornoLinea(reg.carrera);
   
}

// Elimina los caracteres de retorno de línea al final de cadena
void EliminarRetornoLinea(char *cad)
{
   int i;
   // la función fgets captura el retorno de línea, hay que eliminarlo:
   for(i = strlen(cad)-1; i >= 0 && cad[i] < ' '; i--) cad[i] = 0;
}

// Muestra un registro en pantalla, si no está marcado como borrado
void Mostrar(stRegistro &reg)
{
   int i;

   if(reg.snBorrado == 'S') {
      printf("Nombre: %s %s %s\n", reg.nombre, reg.apellido[0], reg.apellido[1]);
      printf("Ciudad: %s \n", reg.ciudad);
      printf("Numero de teléfono: %s\n", reg.telefono);
      printf("Nombre de carrera: %s\n", reg.carrera);
   }
   system("PAUSE");
}

// Añade un registro al archivo de datos
void Insertar(FILE *fa, stRegistro &reg)
{
   // Insertar al final:
   fseek(fa, 0, SEEK_END);
   fwrite(&reg, sizeof(stRegistro), 1, fa);
}


// Lista todos los registros del archivo de datos 
void Listar(FILE *fa)
{
   stRegistro reg; 
   rewind(fa);
   system("cls");
   while(fread(&reg, sizeof(stRegistro), 1, fa)) 
   		Mostrar(reg);
}

