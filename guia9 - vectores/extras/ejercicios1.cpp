#include <iostream>
using namespace std;

int llenarArreglo(double vec[], int TL);
void imprimirArreglo(double vec[], int TL);

int main() {

	const int TAMANHO = 5;
	double temp[TAMANHO];
	double promedio;
	
	promedio = (double)llenarArreglo(temp,TAMANHO) / 5.00;
	imprimirArreglo(temp,TAMANHO);
	
	cout << " promedio = " << promedio;
	
	return 0;
}


int llenarArreglo(double vec[], int TL){
	int suma = 0;
	for(int i = 0; i < TL ; i++){
		cin >> vec[i];
		suma = suma + vec[i];
	}
	
	return suma;
}
	
void imprimirArreglo(double vec[], int TL){
	
	for(int i = 0; i < TL ; i++)
		cout << "[ " << i << " ] = " << vec[i] << endl;
		
}
