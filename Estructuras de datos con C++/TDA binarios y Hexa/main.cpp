//
//  main.cpp
//  binariosHexadecimales
//
//  Created by Jose Miguel Henao Cardona on 4/08/17.
//  Copyright © 2017 Jose Miguel Henao Cardona. All rights reserved.
//
# include <iostream>
# include <string.h>
# include <math.h>
# include <stdlib.h>
# include <map>
# include <ctype.h>
#include "binarios.h"
#include "hexadecimal.h"
using namespace std;

int main(int argc, const char * argv[]) {
      int resultado;
      char operador, condicion='S';
      while(condicion=='S' or condicion=='s'){
            int opcion;
            cout<<"Que de seas operar: "<<endl<<"1. Binarios"<<endl<<"2. Hexadecimales"<<endl<<"Ingresa opcion(1/2): "<<endl;
            cin>>opcion;
            if(opcion ==1){
                  struct TDAbinario numBin, numBin2, numResultado;
                  
                  cout << "Ingrese primer n˙mero (Bin): ";
                  cin >> numBin.numerostr;     // este n˙mero sÛlo deberÌa tener dÌgitos 1 y 0
                  cout << "Ingrese segundo n˙mero (Bin): ";
                  cin >> numBin2.numerostr;    // este n˙mero sÛlo deberÌa tener dÌgitos 1 y 0
                  cout << "Ingrese operador: ";
                  cin >> operador;
                  
                  numBin =  convertBinario(numBin);
                  numBin2 =  convertBinario(numBin2);
                  resultado = operacion(numBin.numerodec, numBin2.numerodec, operador);
                  
                  cout << endl << "Numero Resultado (Bin): " << convertDecimal(resultado);
                  
            }else if(opcion==2){
                  struct TDAhexa numHex, numHex2, numResultado;
                  
                  cout << "Ingrese primer n˙mero (Hex): ";
                  cin >> numHex.numerostr;     // este n˙mero sÛlo deberÌa tener dÌgitos 1 y 0
                  
                  cout << "Ingrese segundo n˙mero(Hex): ";
                  cin >> numHex2.numerostr;    // Garantizar que sean n˙meros en base 16
                  
                  cout << "Ingrese operaciÛn: ";   // Garantizar que sean n˙meros en base 16
                  cin >> operador;
                  
                  cout << "Operando:    " << numHex.numerostr << "  " <<  operador << "  " << numHex2.numerostr << " = ";
                  
                  numHex =  convertDecimal(numHex);
                  numHex2 =  convertDecimal(numHex2);
                  numResultado.numerodec = operacion(numHex.numerodec, numHex2.numerodec, operador);
                  
                  
                  char buffer[33];
                  
                  itoa (numResultado.numerodec,buffer,16);
                  cout << ("El resultado es : %s\n",buffer);
                  
            }else{
                  cout<<"ingresa una operación válida"<<endl;
            }
            cout<<endl<<"Desea continuar (S/N): "<<endl;
            cin>>condicion;
      }
      
      return 0;
}
