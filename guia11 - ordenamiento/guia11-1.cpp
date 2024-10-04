#include <iostream>
using namespace std;

int cantRepetidos(const int vec[], const int TL);

int main() {
	int vec[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
								2 , 3 ,
								4, 4 , 4, 4, 4,4,4,4,4,
								5,5,5,5,5,5,5,5,5,5,5,
								6,6,6,6,6,6,6,6,6,6,7,
								7,8,9,10,11,
								12,12,12,12,12,12,12,12,12,12,
								200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,200,
								3};
	
	int tamanho = sizeof(vec) / 4, repetidos;
	
	repetidos = cantRepetidos(&vec[0], tamanho);
	cout << "La cantidad de elementos repetidos mas de 10 veces es de: " << repetidos << endl;
	
	return 0;
}

int cantRepetidos(const int vec[], const int TL){
	int repetidos = 0, i = 0, cont = 0;
	
	while(i < TL){
		while(vec[i+1] == vec[i] and i < TL){
			cont++;
			i++;
		}
			
		if(cont >= 10)
			repetidos++;
		
		cont = 0;
		i++;
	}
	
	
	return repetidos;
}
