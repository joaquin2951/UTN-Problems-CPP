#include <iostream>
using namespace std;



bool es_magico(const int vec[], const int columnas);
int sumaDiagonal(const int vec[], const int columnas);
int sumaFila(const int vec[], const int columnas, int & posicion);
int sumaCol(const int vec[], const int columnas, int & posicion);

int main() {
	int cubo[] = {3,1,5
		            ,4,7,2
								,9,8,6}, colum;
	
	
	
	cout << "cantidad de columnas de su vector: "; cin >> colum;
	
  cout << boolalpha << es_magico(cubo,colum);
	
	
	return 0;
}



bool es_magico(const int vec[], const int columnas){
	int magico = true;
	int filas = columnas, sumDiag = sumaDiagonal(vec,columnas);
	int posFila = 0, posCol = 0;
	
	while(magico and posFila < columnas*filas){
		if(sumaFila(vec,columnas,posFila) != sumDiag or sumaCol(vec,columnas,posCol) != sumDiag)
			magico = false;
	}
	
	
	return magico;
}

	
int sumaCol(const int vec[], const int columnas, int & posicion){
	int suma = 0;
	for(int i = 0; i < (columnas*columnas); i+=columnas){
		suma = suma + vec[i+posicion];
	}
	
	posicion++;
	
	return suma;
}
	
int sumaFila(const int vec[], const int columnas, int & posicion){
	int suma = 0;
	
	for(int i = 0; i < columnas; i++){
		suma+= vec[i + posicion];
	}
	
	posicion+=columnas;
	
	return suma;
}
	
int sumaDiagonal(const int vec[], const int columnas){
	int fil, col, suma = 0;
	
	for(int i = 0; i < columnas*columnas; i++){
		fil = i / columnas; col = i % columnas;
		
		if(fil == col)
			suma+= vec[i];
	}
	
	return suma;
}
