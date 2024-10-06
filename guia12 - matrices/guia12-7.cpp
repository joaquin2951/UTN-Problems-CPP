#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

#define filas 20
#define columnas 10

void JUGADA(int matriz[][columnas], const int cc, const int cf);
void cargar_matrizAleatorio(int matriz[][columnas], const int cc, const int cf);
void ver_matriz(const int matriz[][columnas], const int cc, const int cf);

int main() {
	int matriz[filas][columnas];
	//0 vacio, 1 rojo, 2 verde
	cargar_matrizAleatorio(matriz,columnas, filas);
	ver_matriz(matriz,columnas, filas);
	
	
	JUGADA(matriz,columnas,filas);
	
	cout << endl << endl << "---------------------------------------" << endl << endl;
	ver_matriz(matriz,columnas,filas);   //para ver la matriz luego de todos los cambios
	
	return 0;
}

void JUGADA(int matriz[][columnas], const int cc, const int cf){
	int contdeDos;
	
	for(int fil = 0; fil < cf ; fil++){
		contdeDos = 0; //cuenta las apariciones de los 2.
		for(int col = 1; col < cc; col++){
			
			if(matriz[fil][col] == matriz[fil][col-1] and matriz[fil][col] == 2){
					contdeDos++;
			}else{
			 contdeDos = 0;
			}
			
			if(contdeDos == 2){
				matriz[fil][col] = 0;
				matriz[fil][col-2] = 0;
			}
			
			
			
		}
	}
}


void cargar_matrizAleatorio(int matriz[][columnas], const int cc, const int cf){
	srand(time(NULL));
	for(int fil = 0; fil < cf; fil++){
		for(int col = 0; col < cc; col++){
			matriz[fil][col] = rand()%3;
		}
	}
}

void ver_matriz(const int matriz[][columnas], const int cc, const int cf){
	for(int fil = 0; fil < cf; fil++){
		for(int col = 0; col < cc; col++){
			cout << matriz[fil][col] << "   ";
		}
		cout << endl;
	}
}
