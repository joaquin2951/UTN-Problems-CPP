#include <iostream>
using namespace std;

bool estanEnCelda(const int mat[][3], const int mat2[][3], const int cf, const int cc);
bool esta(const int mat[][3], const int cf, const int cc, const int valorBuscado);
bool estanEnDiagPrinc(const int mat[][3], const int mat2[][3], const int cf, const int cc);
bool estaEnDiagSec(const int mat[][3], const int mat2[][3], const int cf, const int cc);

int main() {
	
	int A[3][3] = {1,2,3,
	                4,5,6,
	                7,8,9};
	
	int B[3][3] = {7,2,3,
									4,7,6,
									5,8,3};
	
	cout << "Todos los numeros de la diagonal secundaria de A: " << endl;
	cout << "Están en alguna celda de la matriz B: " << boolalpha << estanEnCelda(A,B,3,3) << endl;
	cout << "Están en la Diag Princ de B en cualquier orden: " << boolalpha << estanEnDiagPrinc(A,B,3,3) << endl;
	cout << "Están en la Diag Sec de B en mismo orden: " << boolalpha << estaEnDiagSec(A,B,3,3) << endl;
	return 0;
}



bool estaEnDiagSec(const int mat[][3], const int mat2[][3], const int cf, const int cc){
	bool esta = true;
	int fil = 0, col = cc-1;
	
	while(esta and col >= 0){
		if(mat[fil][col] != mat2[fil][col])
			esta = false;
			
	fil++; col--;		
	}
	
	return esta;
}

bool estanEnDiagPrinc(const int mat[][3], const int mat2[][3], const int cf, const int cc){
	
	bool estan = true;
	int fil = 0, col = cc-1;
	
	while(col >= 0 and estan == true){
		
	 estan = false;
			
	
			for(int i = 0; i < cf; i++)
				if(mat2[i][i] == mat[fil][col])
					estan = true;
			
			
		fil++; col--;
	}
	
	
	return estan;
}

bool estanEnCelda(const int mat[][3], const int mat2[][3], const int cf, const int cc){
	bool estan = true;
	int fil = 0, col = cc-1;
	
	while( estan == true and col >= 0 ){
		
		if( esta(mat2,cf,cc,mat[fil][col]) == false )
			estan = false;
		
		fil++;
		col--;
	}
	
	return estan;
}

	
bool esta(const int mat[][3], const int cf, const int cc, const int valorBuscado){
		bool encontrado = false;
		int fil = 0, col;
		
		while(fil < cf and encontrado == false){
			col = 0;
			while(col < cc and encontrado == false){
				
				if(valorBuscado == mat[fil][col])
					encontrado = true;
				
				col++;
			}
			fil++;
		}
		
		return encontrado;
}
