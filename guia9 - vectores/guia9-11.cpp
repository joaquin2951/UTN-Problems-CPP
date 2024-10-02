#include <iostream>
using namespace std;

int main() {
	int contadorCaracteres[26] = {0}; // 'a' - 97 = 0;    'z' - 97 = 26; 
	char character;
	
	cout << "ingrese caracter: ";
	
	while(cin >> character){
		
		contadorCaracteres[(int)character-97]++;
		cout << "ingrese caracter: ";
		
	}
	
	for(int i = 0; i < 26; i++){
		if(contadorCaracteres[i] > 0)
			cout << (char)(i+97) << " aparece " << contadorCaracteres[i] << " veces"<< endl;
	}
	
	return 0;
}

