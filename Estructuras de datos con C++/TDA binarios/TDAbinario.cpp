# include <iostream>
# include <string.h>
# include <conio.h> 
# include <stdio.h> 
# include <typeinfo>
# include <math.h>
# include <stdlib.h>

/* Programa para reforzar lo que es un TDA, en este caso, con número binario. 
Invariante: Sólo acepta dígitos 0 y 1
Operacion: suma, resta, multiplicación y division (las mismas que cualquier número)
*/

using namespace std;

struct TDAbinario{
	char numerostr[100];    // la invariante es que el número estrictamente tiene dígitos 0 y 1 (está en char)
	int numerodec;          // numero en decimal int para operar
};

TDAbinario convertBinario(TDAbinario numBin){
	// Convierte números de decimal a Binario
	int suma = 0;
	int tamanio =  strlen(numBin.numerostr);
	
	for(int i=0 ; i< tamanio; i++){
		suma += (int(numBin.numerostr[i])-48)* pow( 2, tamanio-1-i );
	}
	numBin.numerodec = suma;
	return numBin;
}

string convertDecimal(int numDec){
	if (numDec == 0)
		return "0";
	// convierte un número de decimal a Binario
	
	int residuo = numDec;
	string numBin = "";
	
	while (residuo != 1)
	{
		if (residuo % 2 == 0)
		{
			numBin = "0" + numBin;
		}
		else
		{
			numBin = "1" + numBin;
		}
		residuo = residuo/2;
	}
	if (residuo % 2 == 0)
	{
		numBin = "0" + numBin;
	}
	else
	{
		numBin = "1" + numBin;
	}
	return numBin;
}

int operacion(int num1, int num2, char operador){
	// Devuelve la operacion de los dos TDAbinario en un nuevo archivo binario
	int result;
	
	if(operador == '+'){
		result = num1 + num2;
		return result;
	}
	else if(operador == '-'){
		result = num1 - num2;
		return result;
	}
	else if(operador == '*'){
		result = num1 * num2;
		return result;
	}
    else if (operador == '/'){
    	result = num1 / num2;
		return result;
	}
}

int main(int argc, char** argv) {	
	int resultado;
	char operador;
	
	struct TDAbinario numBin, numBin2, numResultado;
	cout << "Ingrese primer número (Bin): ";
	cin >> numBin.numerostr;     // este número sólo debería tener dígitos 1 y 0
	cout << "Ingrese segundo número: ";
	cin >> numBin2.numerostr;    // este número sólo debería tener dígitos 1 y 0
	cout << "Ingrese operador: ";
	cin >> operador;
	
	numBin =  convertBinario(numBin);
	numBin2 =  convertBinario(numBin2);
	resultado = operacion(numBin.numerodec, numBin2.numerodec, operador);
	
	cout << endl << "Numero Resultado (Dec): " << resultado;
	cout << endl << "Numero Resultado (Bin): " << convertDecimal(resultado);
		
}
