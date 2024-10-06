#include <iostream>
#include <string>
using namespace std;

#define TAM 3

int palabraEnFila(const char Sopa[][TAM], const int columnas, const string palabra);

int main() {
	char Sopa[TAM][TAM] = {'a','n','a',
	                    'a','o','j',
	                    'z','y','x'
										 };
	
	string palabra;
	
	do{
	  cout << "Ingresar palabra a buscar: ";
		getline(cin,palabra);
	} while(palabra.length() > 10);
	
	
	int ubicacion = palabraEnFila(Sopa,TAM,palabra);
	
	if(ubicacion > -1){
		cout << "La palabra " << palabra << " está en la fila " << ubicacion << endl;
	}else{
		cout << "La palabra " << palabra << " no está en la sopa de letras" << endl;
	}
	
	
	
	return 0;
}

int palabraEnFila(const char Sopa[][TAM], const int columnas, const string palabra){
	int fil = 0, col, i, longPalabra = palabra.length();
	bool estaEnFila;
	
	while(fil < columnas){
		col = columnas-1;
		i = 0; estaEnFila = true;
		
		while(col >= (columnas-longPalabra) and estaEnFila){
			
			if(Sopa[fil][col] != palabra[i])
			 estaEnFila = false;
			else
				i++;
			
			
			if(i == longPalabra)
				return fil;
			else
				col--; 
		}
		
		fil++;
	}
	
	
	return -1;
}
