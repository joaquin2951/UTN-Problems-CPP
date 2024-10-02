#include <iostream>

using namespace std;

void inicializar_teclado(float vec[], int TL);
float maximoVec(const float vec[], int TL);
float minimoVec(const float vec[], int TL);
void normalizarVector(float vec[], const int TL, float maximo, float minimo);
void imprimir_vector(const float vec[], const int tf);

int main() {
	const int TF = 5;
	float X[TF], maximo, minimo;
	
	cout << "incializar vector: " << endl;
	inicializar_teclado(X,TF);
	
	maximo = maximoVec(&X[0], TF);
	minimo = minimoVec(&X[0], TF);
	
	cout << "maximo: " << maximo << "  |  minimo: " << minimo << endl;
	
	cout << "vector normalizado! " << endl;
	normalizarVector(&X[0],TF,maximo,minimo);
	imprimir_vector(&X[0],TF);
	
	
	
	return 0;
}


void normalizarVector(float vec[], const int TL, float maximo, float minimo){
	for(int i = 0; i < TL ; i++)
		vec[i] = ( (vec[i] - minimo) / (maximo - minimo) )  * 100;
}

float maximoVec(const float vec[], int TL){
	float max = vec[0];
	for(int i = 1 ; i < TL; i++)
		if(max < vec[i])
		max = vec[i];
	
	return max;
}

float minimoVec(const float vec[], int TL){
	float min = vec[0];
	for(int i = 1 ; i < TL; i++)
		if(min > vec[i])
			min = vec[i];
	
	return min;
}

void inicializar_teclado(float vec[], int TL){
	for(int i = 0; i < TL; i++){
		cout << "vec[" << i << "] = "; cin >> vec[i] ;
	}
}

void imprimir_vector(const float vec[], const int tf){
		for(int i = 0; i < tf; i++)
			cout << "vec[" << i << "] = " << vec[i] << endl;
		
}
