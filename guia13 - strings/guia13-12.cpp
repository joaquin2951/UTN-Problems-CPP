#include <iostream>
#include <string>

using namespace std;   //'A' = 65  'Z' = 90

void cifrar_desplazamiento(string & frase, const int desplazamiento);
string todoMayus(string frase);

int main(int argc, char *argv[]) {
	
	string frase;
	getline(cin,frase);

	cifrar_desplazamiento(frase, 1);
	
	cout << frase << endl;
	
	return 0;
}

void cifrar_desplazamiento(string & frase, const int desplazamiento){
	
	frase = todoMayus(frase);
	int i = 0, longFrase = frase.length();
	int nuevoValor;
	
	while(i < longFrase){
		
		if(frase[i] >= 'A' and frase[i] <= 'Z'){
			
			nuevoValor = ( (int)(frase[i]) ) + desplazamiento;
			
			while(nuevoValor > 90){
				nuevoValor = nuevoValor - 26;
			}
			
			frase[i] = (char)(nuevoValor);
		}
		
		i++;
	}
	
}

string todoMayus(string frase){
	
	int i = 0, longFrase = frase.length();
	while(i < longFrase){
		
		if(frase[i] >= 'a' and frase[i] <= 'z'){
			frase[i] = toupper(frase[i]);
		}
		
		i++;
	}
	
	
	
	return frase;
}
