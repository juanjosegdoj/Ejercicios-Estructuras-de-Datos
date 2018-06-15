#include <iostream>
#include <stdlib.h>


using namespace std;
bool validarBin(char num[]){
	bool esbinario = true;
	cout << "tamaño: "<< sizeof(num) << endl;
	for(int i=0; i<sizeof(num); i++)
	{
		cout << num[i] << ",  ";
		if(num[i] != '0' && num[i] != '1'){
			cout << "Entre parce";
			esbinario = false;
			i = sizeof(num);
		}
	}
	return esbinario;
}

int main()
{
	char num[20];
	cin >> num;
	cout << endl << validarBin(num);
	return 0;
}
