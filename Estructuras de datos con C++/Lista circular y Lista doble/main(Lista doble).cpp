#include "TDAListaDoble.h"

using namespace std;

int main(int argc, char** argv) {
	TDAListaDoble *cab=NULL;
	
	// inicializar
	cab = Inicilizar();
	
	
	int numero, opcion, pos;
	int cont=0;
	Nodo *aux;
	char res;
	do {
        system("CLS");
        cout<<"USO TDA Lista  \n\n\n";
        cout<<"1.  Crear la lista\n";
        cout<<"2.  Imprimir la lista\n";
        cout<<"3.  add por izquierda\n";
        cout<<"4.  Adicionar un elemento a la lista\n";
        cout<<"5.  Buscar un elemento a la lista\n";
        cout<<"6.  Insertar elemento\n";
        cout<<"7.  Limpiar Lista\n";
        cout<<"8:  Ordenar Lista\n";
        cout<<"9.  Borrar el elemento en la posicion n\n";
        cout<<"10.  Salir \n ";
        
        cin>>opcion;
        switch (opcion)
        {
            case 1:  	
				do {
					cout<<"Ingrese valor:  ";
					cin>>numero;
					cab = crearLista(cab, numero);
        			cout<<"Desea continuar S/N? ";
        			cin>>res;
				} while (res!='N' && res!='n');
                break;
                
            case 2:
            	ImprimirLista(cab);
            	system("Pause");
            	break;
            	      
            case 3:
            	cout<<"Ingrese valor";
            	cin>>numero;
            	cab = addIzquierda(cab,numero);
            	break;

            case 4:
            	cout<<"Ingrese valor";
            	cin>>numero;
            	cab = crearLista(cab,numero);
            	break;
            	
			case 5:
            	cout<<"Ingrese valor a buscar:  ";
				cin>>numero;
				if (buscar(numero,cab))
					cout<<"Elemento encontrado";
				else
					cout<<"Elemento NO encontrado";
				system("Pause");
				break;
			
			case 6:	
				cout<<"Ingrese valor: ";
            	cin>>numero;
            	cout<<"Ingrese posicion: ";
            	cin>>pos;
            	cab = insertar(cab,pos,numero);            	
				break;
				
			case 7:
				limpiarLista(cab);
				break;
			
			case 8:
				if(longitud(cab) == 1){
					cout << "Para ordenar deben haber mínimo 2 elementos.\n";
				}else{
					cab = ordenar(cab);
				}
				break;
				
			case 9:
            	cout<<"Ingrese posicion: ";
            	cin>>pos;
            	borrarIndex(cab, pos);
				break;
			
        	case 10: 
        		cout << "Saliendo del programa" << endl;
        		break;
        		
        	default:
        		cout << "Opcion no encontrada" << endl;
        		break;
        		
		}
    } while (opcion != 10);
	return 0;
}
