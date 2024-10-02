#include <iostream>
using namespace std;

void rotacionIzq(int vec[], const int TL);
void rotacionDer(int vec[], const int TL);
void imprimirVec(const int vec[], const int TL);

int main() {
	
	int vec[] = {1,2,3,4,5,7,9};
	int TL = sizeof(vec)/4;
	
	imprimirVec(&vec[0],TL);
	
	rotacionIzq(&vec[0],TL);
	cout << endl << "rotacion realizada: " << endl;
	imprimirVec(&vec[0],TL);
	
	rotacionDer(&vec[0],TL);
	cout << endl << "rotacion realizada: " << endl;
	imprimirVec(&vec[0],TL);
	
	return 0;
}


void rotacionIzq(int vec[], const int TL){
	int aux = vec[0];
	for(int i = 0; i < TL-1; i++)
		vec[i] = vec[i+1];
	
	vec[TL-1] = aux;
}

void rotacionDer(int vec[], const int TL){
	int aux = vec[TL-1];
	for(int i = TL-1; i > 0; i--)
		vec[i] = vec[i-1];
		
	vec[0] = aux;
}

void imprimirVec(const int vec[], const int TL){
	for(int i = 0; i < TL ; i++)
		cout << vec[i] << " ";
}
