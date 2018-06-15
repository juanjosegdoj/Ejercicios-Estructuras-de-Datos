#include <iostream> 
#include "TDAListaSencilla.h"
#include <String.h>

using namespace std; 
int main(int argc, char** argv) {
	TDALista *cab=NULL;
	int  opcion;
	string numero;
	int cont=0;
	Nodo *aux;
	char res;
	do {
        system("CLS");
        cout<<"USO TDA Lista  \n\n\n";
        cout<<"0.  Insertar en orden\n";
        cout<<"1.  Crear la lista\n";
        cout<<"2.  Imprimir la lista\n";
        cout<<"3.  Longitud de la lista\n";
        cout<<"4.  Adicionar un elemento a la lista\n";
        cout<<"5.  Buscar un elemento a la lista\n";
        cout<<"6.  Posición de un elemento de la lista\n";
        cout<<"7.  Borrar elemento de la lista\n";
        cout<<"8:  Elemento en una poscion indicada\n";
        cout<<"9.  Salir \n ";
        cin>>opcion;
        switch (opcion)
        {
        	case 0:				
				do {
					cout<<"Ingrese valor:  ";
					cin>>numero;
					cab = InsertOrden(cab, numero);
					cout<<cab->inicio->info<<"\n";
        			cout<<"Desea continuar S/N? ";
        			cin>>res;
				} while (res!='N' && res!='n');
                break;
                
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
            	cab = InsertOrden(cab,numero);
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
				cout << "listaSencilla["<< index << "] = "<< elemEnPos(index, cab) << "\n";	
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
