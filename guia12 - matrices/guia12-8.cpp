#include <iostream>
using namespace std;

#define fila 6
#define columna 6

void llenarEspiral(int matriz[][columna], int columnas, int filas);
void ver_matriz(const int matriz[][columna], const int columnas, const int filas);

int main() {
	
	int matriz[fila][columna] = {0};
	
	llenarEspiral(matriz,columna,fila);
	ver_matriz(matriz,columna,fila);
	
	return 0;
}

void llenarEspiral(int matriz[][6], int columnas, int filas){
	int movCol = columnas-1, movFilas = filas-1, numero = 1, filActual = 0, colActual = columnas-1;
	bool bajar = true;
	bool izq = true;
	
	for(int i = 0; i < columnas; i++){
		matriz[0][i] = numero; numero++;
	}
	
		
		
	while(movCol > 0 or movFilas > 0){
	
		if(bajar == true){
			int j = 0;
			
				while(j < movFilas){
					filActual++;
					matriz[filActual][colActual] = numero;
					numero++;
					j++;
				}
				
				movFilas--;
				bajar = false;
			}else if(bajar == false){
			int j = 0;
			
			while(j < movFilas){
				filActual--;
				matriz[filActual][colActual] = numero;
				numero++;
				j++;
			}
			
			movFilas--;
			bajar = true;
		}
		
			
		if(izq == true){
				int j = 0;
				
				while(j < movCol){
					colActual--;
					matriz[filActual][colActual] = numero;
					numero++;
					j++;
				}
				
				movCol--;
				izq = false;
			}else if(izq == false){
			int j = 0;
			
			while(j < movCol){
				colActual++;
				matriz[filActual][colActual] = numero;
				numero++;
				j++;
			}
			
			movCol--;
			izq = true;
		}
	}
	
	
}

	
	
	void ver_matriz(const int matriz[][columna], const int columnas, const int filas){
		for(int fil = 0 ; fil < filas; fil++){
			for(int col = 0; col < columnas; col++){
				cout << matriz[fil][col] << "    ";
			}
				
				cout << endl;
		}
		
	}
