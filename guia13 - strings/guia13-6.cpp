#include <iostream>
#include <string>
using namespace std;

void reemplazarPalabra(string & frase, const string palabra);

int main() {
	string frase, palabraProhibida;
	cout << "frase: "; getline(cin,frase);
	cout << "palabra prohibida: "; getline(cin,palabraProhibida);
	
	
	reemplazarPalabra(frase,palabraProhibida);
	
	cout << "frase: " << frase << endl;
	
	
	
	return 0;
}

void reemplazarPalabra(string & frase, const string palabra){
	int longPalabra = palabra.length();
	int longFrase = frase.length();
	int posicion = 0;
	
	while(frase.find(palabra,posicion) < longFrase){
		posicion = frase.find(palabra,posicion);
		int j = 0;
		
		while(j < longPalabra){
				frase.replace(posicion,1,"X");
				posicion++;
				j++;
		}
		
		
		
	}
	
}
