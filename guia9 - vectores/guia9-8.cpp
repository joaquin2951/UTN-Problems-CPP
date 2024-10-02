#include <iostream>
using namespace std;

int mayorEnRango(const int vec[], const int TL, const int inf, const int sup);

int main() {
	
	int vec[] = {3,2,4,32,-4,-12,4,5} , TL;
	TL = sizeof(vec) / 4;
	
	cout << "tamanho arreglo: " << TL << endl;
	cout << "mayor: " << mayorEnRango(vec,TL,4,7); //el mayor del rango [ vec[4] , vec[7] ];
	
	return 0;
}

int mayorEnRango(const int vec[], const int TL, const int inf, const int sup){
	int mayor = vec[inf];
	
	for(int i = inf; i <= sup; i++)
		if( vec[i] > mayor )
			mayor = vec[i];
	
	return mayor; 
}
