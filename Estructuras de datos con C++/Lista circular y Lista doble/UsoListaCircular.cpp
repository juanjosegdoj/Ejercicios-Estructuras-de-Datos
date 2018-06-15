#include <iostream> 
#include "TDAListaCircular.h"
using namespace std; 
int main(int argc, char** argv) {
	TDALista *cab=NULL;
	int buscarr = 0, josefo=0;
	Nodo *aux;
	cab=Inicializar();
	int nombre;
	int opcion;
	int lenght = 0;
	int cont=0;
	char res;
	do {
        system("CLS");
        cout<<"JUEGO JOSEFO  \n\n\n";
        cout<<"1.  Crear la lista\n";
        cout<<"2.  Imprimir la lista\n";
        cout<<"3.  Buscar un elemento a la lista\n";
        cout<<"4.  Borrar un elemento de la lista\n";
        cout<<"5.  Longitud de la lista\n";
		cout<<"6.  Jugar josefo\n";
		cout<<"50. Salir \n ";
        cin>>opcion;
        switch (opcion)
        {
            case 1:  	
				do {
					cout<<"Ingrese nombre:  ";
					cin>>nombre;
					cab = crearLista(cab, nombre);
        			cout<<"Desea continuar S/N? ";
        			cin>>res;
				} while (res!='N' && res!='n');
                break;
            case 2:
            
			    ImprimirLista(cab);
            	system("Pause");
            	break;
           case 3:
           	{
			   
            	cout<<"Ingrese el nombre:";
            	cin>>nombre;
				int buscarr = buscar(nombre , cab);
				if(buscarr == 1){
					cout<<"El elmento fue encontrado\n";
				}
				else
					{
					
            		cout<<"No existe "<<buscarr<<endl;
            	
				}system("Pause");
            	break;
            }
            case 4:				 
            
				cout<<"Ingrese nombre ";
            	cin>>nombre;
            	
            	aux = buscara(nombre,cab);
				// cuuenta los elmentos de la lista
				lenght = longitud(cab);
				
				if (lenght==1)
				{
					cab->inicio = NULL;
					cab->actual = NULL;
					cout<<"Elemento borrado & lista elminada\n";
				}
				else if(aux->info== 1)
				{
					BorrarElemento(cab,aux);
            		cout<<"Elemento borrado\n";
					
				}
				else 
				{
				            		
            		cout<<"El elemento no existe\n";
        	    }
            		system("Pause");
				
            	break;
			
			case 5: 
				  lenght = longitud(cab);
				  
				  cout<<"La logitud es "<<lenght<<"\n";
				  system("Pause");
				  break;
			case 6:
            	cout<<"Ingrese numero para juego:  ";
				cin >> josefo;
				cont = josefo;
				
				while(longitud(cab)!=1)
				{	
					Josefo(cab,josefo,cont);
				}
				system("Pause");
				break;
        }
    } while (opcion !=50);
	return 0;
}
// by  Duver Carmona  & Santiago Rios
