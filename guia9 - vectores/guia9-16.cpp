#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;


void inicializarArreglo(int vec[], const int TL);
void Quini6(const int vec[], const int sorteados[], const int TL, const int numJ);

int main() {
	const int TF = 6;
	int numeroJugador, vec[TF], vec2[TF];
	
	srand(time(NULL));
	
	numeroJugador = rand()%100;
	
	cout << "Elija sus numeros entre 00 y 45, jugador numero " << numeroJugador << endl;
	inicializarArreglo(vec,TF);
	
	cout << "numeros que salieron sorteados: " << endl;
	inicializarArreglo(vec2,TF);
	
	Quini6(vec,vec2,TF,numeroJugador);
	
	return 0;
}

void Quini6(const int elegidos[], const int sorteados[], const int TL, const int numJ){
	bool esIgual = true;
	
	for(int i = 0; i < TL ; i++){
		if(esIgual == false) break;
		
		esIgual = false;
		for(int j = 0; j < TL ; j++){
			
			if(elegidos[i] == sorteados[j])
				esIgual = true;
			
		}
		
	}
	
	if(esIgual)
		cout << "el jugador numero " << numJ << " es el ganador" << endl;
	
}


void inicializarArreglo(int vec[], const int TL){
	for(int i = 0; i < TL ; i++){
		cout << "[" << i << "] = " ; cin >> vec[i];
	}
}
