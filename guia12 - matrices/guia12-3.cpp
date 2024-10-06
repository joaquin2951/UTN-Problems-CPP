#include <iostream>
using namespace std;


#define N 3

bool esTriangularSuperior(const int matriz[][N], const int filas);


int main() {
	
int matriz[N][N] = { {0, 2, 3},
											{0 ,4, 6},
											{0, 0, 91}
};
	
cout << boolalpha << esTriangularSuperior(matriz,N);

	return 0;
}


bool esTriangularSuperior(const int matriz[][N], const int filas){
	bool triangular = true;
	int fil = 1, col, maxCol = 1;
	
	while(triangular and fil < filas){
		col = 0;
		
		while(triangular and col < maxCol){
			if(matriz[fil][col] != 0)
				triangular = false;
			
			col++;
		}
		
		
		maxCol++;
		fil++;
	}
	
	return triangular;
}
