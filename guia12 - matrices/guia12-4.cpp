#include <iostream>
using namespace std;
//GUIA 12 EJERCICIO 4

bool es_diagonal(int matriz[][3], int columnas);
int main() {
	const int TF = 3;
	int M[TF][TF] = { {1,0,0},
					  {2,5,0},
					  {0,0,8}};
	
	cout << "La matriz es Diagonal? " << boolalpha << es_diagonal(M,TF);
	
	
	return 0;
}

bool es_diagonal(int matriz[][3], int columnas){
	
	
	for(int fil = 0; fil < columnas; fil++){
		for(int col = 0; col < columnas; col++){
			if(fil != col and matriz[fil][col] != 0){
				return 0;
			}
		}
	}
	return 1;
}
