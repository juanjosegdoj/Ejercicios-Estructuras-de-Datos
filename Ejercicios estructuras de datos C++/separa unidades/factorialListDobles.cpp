#include "TDAListaDoble.h"

using namespace std;

int main(int argc, char** argv) {
	// dado un numero, se le saca el factorial, guardando las cifras en  diferentes nodos, cada nodo tiene máximo 3 dígitos
	
	TDAListaDoble *cab=NULL;
	// inicializar
	cab = Inicilizar();
	cab = crearLista(cab,1);
	int numero;
	cout << "Ingrese numero: ";
	cin >> numero;
	
	for(int i=2; i<=numero; i++){
		
		// primero hago la multiplicación
		Nodo *aux;
		aux=cab->actual;
		do{
			aux->info *= i;
			aux=aux->ant;
		}while (aux != NULL);
		
		
		// despues mueve los nodos que en su parte info tengan mas de 3 cifras, se pasan
		aux=cab->actual;
		do{
			if(aux->info >= 1000){
					
				if(aux->ant == NULL){
					cab = addIzquierda(cab, aux->info/1000);
				}else{
					aux->ant->info += aux->info/1000;
				}
				aux->info = aux->info % 1000;
			}
			aux=aux->ant;
		
		}while (aux != NULL);	
	}
	ImprimirLista(cab);
	
}
