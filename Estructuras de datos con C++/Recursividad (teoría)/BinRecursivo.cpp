#include <iostream>

using namespace std;

string binarioNoRecursivo(int numero){
	int resto, divisor = 2;
	string binario = "";
	
	while(numero >= divisor){ 
		resto = numero % 2;
		if(resto == 1)
			binario = "1" + binario;
		else
			binario = "0" + binario;
			
    	numero = numero/divisor; 
    }
	if(numero == 1)
		binario = "1" + binario; 
	else
		binario = "0" + binario;
	return binario;
}

string binario(int dividendo){
	if(dividendo >= 2){
		if(dividendo % 2 == 1)
			return binario(dividendo/2)+"1";
		else
			return binario(dividendo/2)+"0";
	}else{
		if(dividendo == 1)
			return "1";
		else
			return "0";
	}	
}

int main(){
	int numero;
	while(true){	
		cout << "Ingrese el numero decimal a convertir a binario: ";
		cin >> numero;
		
		cout << "\n------CASO NO RECURSIVO --\n";
		cout << binarioNoRecursivo(numero) << endl;
		
		cout << "\n----  CASO RECURSIVO  ----\n";
		cout << binario(numero) << endl;
		
		
		if(binarioNoRecursivo(numero) == binario(numero)){
			cout << "Son iguales\n";
		}else{
			cout << "No dio mi Bro";
		}
		system("Pause");
		system("cls");
	}
}
