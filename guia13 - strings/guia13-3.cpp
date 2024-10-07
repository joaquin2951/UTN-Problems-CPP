#include <iostream>
using namespace std;


string Invertir(string frase);
bool palindromo(string frase);

int main() {
	
	string frase;
	
	getline(cin,frase);
	
	
	cout << "Long frase: " << frase.length() << endl;
	
	
	cout << boolalpha << palindromo(frase) << endl;
	
	cout << endl << endl << "frase: " << frase << endl;
	cout << "frase Inver: " << Invertir(frase) << endl;
	
	return 0;
}
bool palindromo(string frase){
	string fraseInvertida = Invertir(frase);
	bool iguales = true;
	int i = 0, inferior = 0, superior = frase.length() -1;
	
	while(iguales and i < frase.length() / 2){
		
		if(frase[inferior] == ' ')
			inferior++;
		if(fraseInvertida[superior] == ' ')
			superior--;
		
		if(frase[inferior] != fraseInvertida[superior])
			iguales = false;
		
		i++;
	}
	
	return iguales;
}
	
	string Invertir(string frase){
		int longitud = frase.length();
		string fraseInvertida = frase;
		
		for(int i = 0; i < longitud; i++){
			fraseInvertida[i] = frase[longitud-1-i];
		}
		
		return fraseInvertida;
	}
		
