#include <iostream> 
#include "TDAListaSencilla.h"
#include <String.h>

using namespace std; 
int main(int argc, char** argv) {
	TDALista *cab=NULL;
	int  opcion;
	int numero;
	int cont=0;
	Nodo *aux;
	char res;
	do {
        system("CLS");
        cout<<"USO TDA Lista  \n\n\n";
        cout<<"1.  Crear la lista\n";
        cout<<"2.  Imprimir la lista\n";
        cout<<"3.  Longitud de la lista\n";
        cout<<"4.  Adicionar un elemento a la lista\n";
        cout<<"5.  Buscar un elemento a la lista\n";
        cout<<"6.  Posición de un elemento de la lista\n";
        cout<<"7.  Eliminar elemento en la poscion indicada\n";
        cout<<"8:  Eliminar elemento en la poscion indicada (lo mismo que 7)\n";
        cout<<"9.  Salir \n ";
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
				cont=longitud(cab);
            	cout<<"la longitud es:"<<cont<<endl;
            	system("Pause");
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
				cout<<"Ingrese elemento a buscar ";
				cin>>numero;
				
				aux = BuscarElementNODO(numero,cab);
				
				if (aux != NULL)
					cout<<"Elemento encontrado, poscion mem: " << aux;
				else
					cout<<"Elemento NO encontrado" << endl;
				system("Pause");
				break;
				
			case 7:
				cout << "Ingrese elemento a buscar: ";
				
				cin>>numero;
				
				aux = BuscarElementNODO(numero,cab);
				
				if (aux != NULL)
					cout<<"Elemento encontrado, poscion mem: " << aux;
				else
					cout<<"Elemento NO encontrado" << endl;
				system("Pause");
				break;				
				
        	case 8:
	        	int index;
	        	cout << "Ingrese elemento a buscar: ";
				cin>>index;
				
				if(index < longitud(cab)){  // no puede ser igual porque el index incia desde cero
					eliminarIndex(cab, index);
				}else
					cout << "El dato en la posicion " << index << " no existe en la lista\n";
				system("Pause");
	        	break;
        		
        	case 9: 
        		cout << "Saliendo del programa" << endl;
        		break;
        		
        	default:
        		cout << "Opcion no encontrada" << endl;
        		break;
        		
		}
    } while (opcion !=9);
	return 0;
}
