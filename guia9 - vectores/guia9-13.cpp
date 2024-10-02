#include <iostream>
using namespace std;


void intercambio(int vec[], const int TL, int numeroA, int numeroB);
bool contenido(int vec[], const int TL,int numero);
int aparecePrimero(int vec[], const int TL, int nA, int nB);


int main() {
	

int vec[] = {1,2,3,4,5,10,-5,7};
int TL = sizeof(vec)/4;

intercambio(&vec[0],TL,3,10);

for(int i = 0; i < TL ; i++)
	cout << vec[i] << " ";


	return 0;
}

int aparecePrimero(int vec[], const int TL, int nA, int nB){
	
	for(int i=0; i < TL ; i++){
		if(vec[i] == nA)
			return nA;
		else if(vec[i] == nB)
			return nB;
	}
	
	return 0;
}



void intercambio(int vec[], const int TL, int numeroA, int numeroB){
	int posicion;
	
	if(contenido(vec,TL,numeroA) and contenido(vec,TL,numeroB)){
		
		if(aparecePrimero(vec,TL,numeroA,numeroB) == numeroB)
			swap(numeroA,numeroB);
		
		
		
		for(int i = 0; i < TL ; i++) {
			if(vec[i] == numeroA){
				posicion = i;

			}else if(vec[i] == numeroB){
				vec[posicion] = vec[i];
				vec[i] = numeroA;
			}
		}
		
	}else
		cout << "Uno de los numeros ingresados no está contenido en el arreglo" << endl;
	
	
}

bool contenido(int vec[], const int TL, int numero){
	for(int i = 0; i < TL ; i++)
		if(numero == vec[i])
			return true;
	return false;
}
