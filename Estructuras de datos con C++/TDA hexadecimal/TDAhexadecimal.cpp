# include <iostream>
# include <string.h>
# include <math.h>
# include <stdlib.h>
# include <map>
# include <ctype.h>

/* Programa TDA hexa: opera números decimales suma, resta, multiplicacion y divison
*/

using namespace std;

struct TDAhexa{
	char numerostr[];    // El invariante son los números de más que puede tener o sea a, b, c, d 
	int numerodec;       // Se complementa de un número en decimal para las operaciones
};

TDAhexa convertDecimal(TDAhexa numHex){
	// devuelve un TDAhexa con el numero convertido a decimal
	
	for(int i = 0; numHex.numerostr[i]; i++)
		numHex.numerostr[i] = tolower(numHex.numerostr[i]); // <--convierte a minusculas 
	
	std::map<char,int> mymap;
	
	mymap['0'] = 0;   mymap['1'] = 1;   mymap['2'] = 2;   mymap['3'] = 3;   mymap['4'] = 4;    mymap['5'] = 5;
	mymap['6'] = 6;   mymap['7'] = 7;   mymap['8'] = 8;   mymap['9'] = 9;   mymap['a'] = 10;   mymap['b'] = 11;
	mymap['c'] = 12;  mymap['d'] = 13;  mymap['e'] = 14;  mymap['f'] = 15;
	
	int suma = 0;
	int tamanio =  strlen(numHex.numerostr);
	
	for(int i=0 ; i< tamanio; i++){
		suma += (mymap[numHex.numerostr[i]])* pow( 16, tamanio-1-i );
	}
	numHex.numerodec = suma;
	return numHex;
}


int operacion(int num1, int num2, char operador){
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
    	result = num1 / num2;   // obviamente el num2 debe ser diferente de cero
		return result;          // cuando son fracciones inexactas como esta 5/2, sólo se toma la parte entera
	}
}

int main(int argc, char** argv) {	
	char operador;
	struct TDAhexa numHex, numHex2, numResultado;
	
	cout << "Ingrese primer número (Hex): ";
	cin >> numHex.numerostr;     // este número sólo debería tener dígitos 1 y 0
	
	cout << "Ingrese segundo número: ";
	cin >> numHex2.numerostr;    // Garantizar que sean números en base 16
	
	cout << "Ingrese operación: ";   // Garantizar que sean números en base 16
	cin >> operador;
	
	cout << "Operando:    " << numHex.numerostr << "  " <<  operador << "  " << numHex2.numerostr << " = ";
	
	numHex =  convertDecimal(numHex);
	numHex2 =  convertDecimal(numHex2);
	numResultado.numerodec = operacion(numHex.numerodec, numHex2.numerodec, operador);
	
	
	char buffer[33];
	
	itoa (numResultado.numerodec,buffer,16);
	cout << ("El resultado es : %s\n",buffer);
		
}
