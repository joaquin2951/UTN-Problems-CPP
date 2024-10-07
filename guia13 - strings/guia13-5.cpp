#include <iostream>
#include <string>
using namespace std;


int cantPalabras(string frase);

int main() {

	string str;
	int cantCaracteres, cantidadPalabras;
	
	getline(cin,str);
	
	cantCaracteres = str.length();
	cantidadPalabras = cantPalabras(str);
	
	cout << "cant caracteres: " << cantCaracteres << endl;
	cout << "cant de palabras: " << cantidadPalabras << endl;
	
	return 0;
}


int cantPalabras(string frase){
	int palabras = 0;
	int i = 0;
	
	while(i < frase.length()){
		
		if(frase[i] == ' ' or frase[i] == '.'){
			palabras++;
		}
		
		i++;
	}
	
	
	
	return palabras;
}
