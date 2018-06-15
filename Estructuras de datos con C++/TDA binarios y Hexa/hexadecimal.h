# include <iostream>
# include <string.h>
# include <math.h>
# include <stdlib.h>
# include <map>
# include <ctype.h>

/* Programa TDA hexa: opera n˙meros decimales suma, resta, multiplicacion y divison
 */

using namespace std;

struct TDAhexa{
      char numerostr[];    // El invariante son los n˙meros de m·s que puede tener o sea a, b, c, d
      int numerodec;       // Se complementa de un n˙mero en decimal para las operaciones
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





//endif /* hexadecimal_h */
