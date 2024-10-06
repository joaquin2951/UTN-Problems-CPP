#include <iostream>
using namespace std;
//GUIA 12 - ejercicio 1
void cargarMatriz(int M[][3], const int filas, const int columnas );
void calcularFila(const int M[][3], int puntos[], const int filas, const int columnas);
int mayor(const int puntos[],const int filas, int & posicionFacultad);
void desempenho(const int vec[], const int filas);
int main() {
	const int TF = 3;
	int M[TF][TF], puntos[TF] = {0};
	int TL = TF, posicionFacultad = 0;
	
	cargarMatriz(M,TL,TL);
	calcularFila(M,puntos,TL,TL);
	
	cout << endl << endl;
	for(int i = 0; i < TF; i++)
		cout << puntos[i] << " ";
	
	cout << "El mayor puntaje conseguido es de: " << mayor(puntos,TL,posicionFacultad);
	cout << " Fueron conseguidos por la facultad: " << posicionFacultad;
	
	cout << endl;
	desempenho(puntos,TL);
	
	return 0;
}

void desempenho(const int vec[], const int filas){
	bool malDesempenho = false;
	int i = 0, posicion;
	while(i < filas and malDesempenho == false){
		if(vec[i] == 0){
			malDesempenho = true;
			cout << "La facultad " << i << " obtuvo 0 puntos" << endl;
		}
		
		i++;
	}

}

int mayor(const int puntos[],const int filas, int & posicionFacultad){
	int mayor = puntos[0];
	for(int i = 1; i < filas; i++){
		if(mayor < puntos[i]){
			mayor = puntos[i];
			posicionFacultad = i;
		}
	}
	
	return mayor;
}
void calcularFila(const int M[][3], int puntos[] ,const int filas, const int columnas){
	for(int fil = 0; fil < filas; fil++){
		for(int col = 0; col < columnas; col++){
			puntos[fil] = puntos[fil] + M[fil][col];
		}
	}
}

void cargarMatriz(int M[][3], const int filas, const int columnas ){
	
	for(int i = 0; i < filas; i++)
		for(int j = 0; j < columnas; j++){
		
		if(i != j){
		cout << "Matriz[" << i << "]["<< j << "] = ";
		cin >> M[i][j];
	}
			
		else{
			M[i][j] = 0;
			cout << "Matriz[" << i << "]["<< j << "] = 0";
		}
			cout << endl;
	}
}
