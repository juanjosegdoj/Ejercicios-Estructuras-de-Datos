#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <map>

using namespace std;

void Punto_1A(){
    cout << "Especificaciones: Este programa pide infinitamente un número pues no hay ningún valor que altere el valor de var para cortar el ciclo, así que nunca imprime chao" << endl;

    int num;
    int var = 1;

    while (var == 1)
    {
        cout << "Emtre un número: ";
        cin >> num;
        cout << "Ingresó: " << num << '\n';
    }
    cout << "Chao\n";
}

void Punto_1B(){
    cout << "Especificaciones: Este programa imprime los números menores a 5, iniciando desde el número 0 " << endl;

    int countt = 0;
    while (countt < 5)
    {
        cout << countt << " Es menor de 5" << endl;
        countt++;
    }
    cout << countt << " Es mayor que 5\n";
}

void Punto_1C(){
    cout << "Especificaciones: imprime las potencias de dos en una misma línea y separados por un espacio" << endl;

    int potencia = 1;
    int i = 1;

    while (i <= 12){
        cout << potencia << " ";
        i++;

        potencia *= 2;
    }
    cout << "Chao!\n";
}

void Punto_1D(){
	cout << "Especificaciones: Este programa pide un número positivo, y lo sigue pidiendo hasta que sea ingresado" << endl;
    int numero;
    cout << "Esciba und número positivo: ";
    cin >> numero;

    while (numero < 0){
        cout << "¡Ha escrito un número negativo! Inténtelo de nuevo" << endl;

        cout << "Esciba un número positivo: ";
        cin >> numero;
    }
    cout << endl << "Gracias por su colaboración"<< endl;
}

void Punto_2(){
	// Este algoritmo cuenta los numero positivos, negativo y cero de una serie delimitada por el usuaio
    int prim = 0, segund = 1, new_, numSer;

    cout << "Ingrese el n número de la serie: ";
    cin >> numSer;

    cout << prim << " " << segund << " ";
    for(int i=0; i<numSer-2; i++){
        new_ = prim + segund;
        cout << new_ << " ";
        prim = segund;
        segund = new_;
    }

    int contadorPos = 0, contadorNeg = 0, suma = 0, numeroCab, numeroCola, intercambio;
    cout << "Ingrese un número cola: ";
    cin >> numeroCola;

    cout << "Ingrese un número cabeza: ";
    cin >> numeroCab;

    if (numeroCola > numeroCab){
        intercambio = numeroCola;
        numeroCola = numeroCab;
        numeroCab = intercambio;
    }

    for(int i=numeroCola; i<numeroCab ; ++i )
    {
        if (i == 0){
            cout << "un cero" << endl;
        }
        else if (i > 0){
            contadorNeg++;
        }
        else{
            contadorPos++;
        }
        suma += i;
    }

    cout << "Cantidad Negativos: " << contadorNeg << endl;
    cout << "Cantidad Positivos: " << contadorPos << endl;
    cout << "Suma de los números [0,n): " << suma ;
}

void Punto_3(){
	// imprime los numeros de la serie de fibonacii delimitado por un dato ingresado por el ususario
    int prim = 0, segund = 1, new_, numSer;

    cout << "Ingrese el n número de la serie: ";
    cin >> numSer;

    cout << prim << " " << segund << " ";
    for(int i=0; i<numSer-2; i++){
        new_ = prim + segund;
        cout << new_ << " ";
        prim = segund;
        segund = new_;
    }
}

void Punto_4(){
	// Dibujar un cuadrado de 3*3 con un simbolo ingresado por el usuario
	
    int lado;
    char simbolo;
    string linea = "";

    cout << "Dime el lado: ";
    cin >> lado;
   
    
    cout << "Dime el simbolo: ";
    cin >> simbolo;

	
    for(int i=0; i<lado; i++){
        linea += simbolo; 
    }
    
    for(int i=0; i<lado; i++){
    	cout << linea << endl;
	}
}

void Punto_5(){
	// Programa que pasa un número decimal a binario, octal y hexadecimal
	
  int i;
  char buffer [33];
  
  cout << ("Enter a number: ");
  cin >> i;
  
  itoa (i,buffer,10);
  cout << "decimal: " << buffer << endl;
  
  itoa (i,buffer,16);
  cout << "Hexadecimal: " << buffer << endl;
  
  itoa (i,buffer,8);
  cout << "Octal: " << buffer << endl;
  
  itoa (i,buffer,2);
  cout << "Binario: " << buffer << endl;
	
}

void Punto_6(){
	// Programa que de un numero ingresado dice si es positivo o no
	
	int numero;
	bool primo = true;
	cout << "Ingrese un número: "; 
	cin >> numero;
	
	while (numero < 2){
		cout << "Recuerde que el numero debe ser positivo" << endl;
		cout << "Ingrese un número: " << endl; 
		cin >> numero;
	}
	
	if(numero == 2 || numero == 1){
		primo = true;
	}
	
	else if( numero % 2 == 0)
	{
		primo = true;
	}
	else
	{
		for(int i=3; i<numero; i+=2)
		{
			if( numero % i == 0)
			{
				cout << "Numero divisible por: " << i << endl;
				i = numero;
				primo = false;
			}
		}
	}
	
	if (primo)
	{
		cout << "El numero " << numero << " es primo";
	} 
	else
	{
		cout << "El numero " << numero << " NO es primo";
	}
	
}

void Punto_7(){
	// imprime la suma de los numeros multiplos de 5 y 7 menores al numero ingresado 
	
	int numero, suma=0;
	cout << "Buscaremos los multiplos de 5 y 7 menores al numero: ";
	cin >> numero;
	
	for(int i=1; i<numero; i++)
	{
		if (i % 3 == 0 || i % 5 == 0){
			suma += i;
			cout << i << " ";
		}
	}
	cout << endl << "La suma de los numeros es: " << suma;
}

void Punto_8(){
	// imprime la cantidad de agua que queda en el tanque de un pueblo al final de cada semana 
	
	int litros = 10000;
	int semana = 1;
	while(litros >= 183)
	{
		litros -= 183; 
		cout << endl <<"Semana Nro " << semana << endl;
		cout << "Agua que queda en el tanque: " << litros << " litros" << endl;
		cout << "----------------------------------\n";
		semana++;
	}
	cout << endl << "Ya no hay suficiente agua para la próxima semana\nAgua restante en el tanque: " << litros << " litros";
}

void Punto_9(){
	// dice si un número es palíndromo o no
	string palabra;
	
	cout << "Ingrese una palabra: ";
	cin >> palabra;
	
	int longit = palabra.length();
	
	for(int i=0; i< (int)longit/2; i++)
	{
		if (palabra[i] != palabra[longit-1-i])
		{
			cout << "La palabra ingresada no es palindroma";
			return;
		}
	}
	cout << "La palabra ingresada es palindroma";
}

void Punto_10(){
	// dado un numero entero,muestra  por pantalla la suma y el número de sus cifras y además muestre el resultado de invertir el orden de sus cifras.
	string numero, revez="";
	int suma = 0;
	
	cout << "Ingrese un número entero: ";
	cin >> numero;
	
	
	for(int i=0; i < numero.size(); i++)
	{
		revez = numero[i] + revez;
		suma += (numero[i] - '0');   // con esto se convierte un char a int
	}
	cout << "La suma de las cifras de los números es: " << suma << endl;
	cout << "El número invertido : " << revez;
}

void Punto_11(){
	// Programa que dice si un ciclista es apto debido a una prueba de tiempo de 10 días
	double promedio = 0;
	bool apto1 = true, apto2 = true, apto3 = false;
	int rutaDias[10];
	
	for(int i=0; i<10; i++)
		rutaDias[i] = rand()%20;
	
	for(int i=0; i<10; i++){
		promedio += rutaDias[i];
		
		if(rutaDias[i] > 16)
			apto1 = false;
			
		if(rutaDias[i] > 16)  // b. Que al menos en una de las pruebas realice un tiempo mayor a 16 minutos.
			apto2 = true;  // la anterior quiere decir exactamente lo contrario que la primera condicion, o sea que cualquiera es apto 
	}
	if(((promedio+0.0)/10.0) <= 15)
	{
		apto3 = true;
	}
	if(apto1 || apto2 || apto3)
	{
		cout << "El competido es apto para la prueba de 5 Kilómetros";
	} else 
	{
		cout << "Lo siento, creo que debes buscar otra especialidad";
	}
}

void porcentajeAnimals(int animals[], char name[15], int tam){
	// imprime el porcentaje de un cojunto de animales de tipo de animal name 

	double menor1 = 0;  // menores o iguales a un año
	double menor3 = 0;  // de mas de un año y menos de 3
	double mayors = 0;  // mayores o iguales a 3 
	
	cout << "Datos edades:  ";
	for(int i=0; i< tam; i++)
	{
		cout << animals[i] << ";  ";
		if (animals[i] <= 1)
			menor1++;
		else if(animals[i] < 3)
			menor3++;
		else
			mayors++;
	}	
	
	cout << "\n\n         ---- Porcentaje de "<< name <<"  clasificado en edades(anios)  ----\n";
	cout << "             _ Menores o iguales un anio: " << (menor1/tam)*100<<  "%"<< endl;
	cout << "             _ Mayores a 1 anio y menores a 3 anios: " << (menor3/tam) *100 << "%"<< endl;
	cout << "             _ Mayores o iguales a 3 anios : " << (mayors/tam)*100 <<  "%"<< endl;
	
}
void Punto_12(){
	/* Programa determina el porcentaje de animales (ya sea chimpances, jirafas o elefantes) que hay 
	en las siguientes tres categorías de edades: de 0 a 1 año, de más de 1 año y menos de 3 y de 3 o más años
	*/
		int opcion;
	
	int elefantes[20];
	int jirafas[15];
	int chimpances[40];
	
	for(int i=0; i<75; i++)
		if (i< 20)
			elefantes[i] = rand()%10;   // crea edades de elefantes entre 0 y 9
		else if (i < 35)
			jirafas[i-20] = rand()%8;   // crea edades de jirafas entre 0 y 7
			
		else
			chimpances[i-35] = rand()%10;   // crea edades de elefantes entre 0 y 9
			

	cout << "¿Qué tipo de animales se van a estudiar?\n 1. Elfefantes.\n 2. Jirafas.\n 3. Chimpances \n";
	cout << "  ::";
	cin >> opcion;
	
	
	if(opcion == 1)
		porcentajeAnimals(elefantes, "Elefantes",20);
		
	else if(opcion == 2)
		porcentajeAnimals(jirafas, "Jirafas",15);
		
	else if(opcion == 3)
		porcentajeAnimals(chimpances, "Chimpances",40);
		
	else
		cout << "La opcion ingresada no existe" << endl;
	
}

void Punto_13(){
	// Programa para calcular cuánto se le debe pagar a un obrero por horas habituales más horas extras
	int horas;
	cout << "Cuántas horas trabajo el empleado: ";
	cin >> horas;
	
	if (horas <= 40)
		cout << "A este empleado se le debe pagar " << horas*20;
	else
		cout << "A este empleado se le debe pagar " << 40*20 + (horas-40)*25;
}

int main()
{
	while (true){
		int num;
		cout << "Ingrese número: ";
		cin >> num;
		switch (num) {
		case 1:
		  cout << "El punto 1 no se imprime debido a que es infinito, pero hace lo siguiente: ";
		  cout << "Especificaciones: Este programa pide infinitamente un número pues no hay ningún valor que altere el valor de var para cortar el ciclo, así que nunca imprime chao\n\n";
		  
		  Punto_1B();
		  cout << endl;
		  Punto_1C();
		  cout << endl;
		  Punto_1D();
		  cout << endl;
		  break;
		case 2:
		  Punto_2();
		  cout << endl;
		  break;
		case 3:
		  Punto_3();
		  cout << endl;
		  break;
		case 4:
		  Punto_4();
		  cout << endl;
		  break;
		case 5:
		  Punto_5();
		  cout << endl;
		  break;
		case 6:
		  Punto_6();
		  cout << endl;
		  break;
		case 7:
		  Punto_7();
		  cout << endl;
		  break;
		case 8:
		  Punto_8();
		  cout << endl;
		  break;
		case 9:
		  Punto_9();
		  cout << endl;
		  break;
		case 10:
		  Punto_10();
		  cout << endl;
		  break;
		case 11:
		  Punto_11();
		  cout << endl;
		  break;
		case 12:
		  Punto_12();
		  cout << endl;
		  break;
		case 13:
		  Punto_13();
		  cout << endl;
		  break;
		  
		default:
		  cout << "El dato ingresado no es punto" << endl;
		  break;
		}
	}
    return 0;
}
