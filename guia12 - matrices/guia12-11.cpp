#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

#define departamentos 5
#define meses 13

void ver_matriz(const float matriz[][meses], const int columnas, const int filas);
void cargar_matrizAleatorio(float matriz[][meses], const int cc, const int cf);
void promedioAnual(float matriz[][meses],const int cc, const int cf);
float promedioFila(float matriz[][meses], const int cc, const int fila);
void colAnual(float matriz[][meses],const int cc, const int cf);

int main() {
float clima[departamentos][meses];

cargar_matrizAleatorio(clima,meses,departamentos);

clima[0][0] = -1; clima[0][1] = -1; clima[2][2] = -1; clima[3][2] = -1;

ver_matriz(clima,meses-1,departamentos);
promedioAnual(clima,meses-1,departamentos);

cout << endl << endl << " ------------------------------------------------------ " << endl << endl;

colAnual(clima,meses,departamentos);
ver_matriz(clima,meses,departamentos);

	return 0;
}



void colAnual(float matriz[][meses],const int cc, const int cf){
	float prom;
	for(int fil = 0; fil < cf; fil++){
		prom = 0.0;
		for(int col = 0; col < cc-1; col++){
			prom+=matriz[fil][col];
		}
		matriz[fil][cc-1] = prom;
	}
}

void promedioAnual(float matriz[][meses],const int cc, const int cf){
	float prom; int cont;
	
	for(int fil = 0; fil < cf; fil++){
		prom = promedioFila(matriz,cc,fil); cont = 0;
		
		for(int col = 0; col < cc; col++){
			if(matriz[fil][col] == -1)
				matriz[fil][col] = prom;
				
		}
	
		
	}
}

	float promedioFila(float matriz[][meses], const int cc, const int fila){
		float promedio = 0.0; int cont = 0;
		for(int col = 0; col < cc; col++){
			if(matriz[fila][col] != -1){
				promedio+=matriz[fila][col];
				cont++;
			}
		}
			return promedio/(float)cont;
	}
	
void ver_matriz(const float matriz[][meses], const int columnas, const int filas){
	for(int fil = 0 ; fil < filas; fil++){
		for(int col = 0; col < columnas; col++){
			cout << matriz[fil][col] << "    ";
		}
		
		cout << endl;
	}
	
}

	void cargar_matrizAleatorio(float matriz[][meses], const int cc, const int cf){
		srand(time(NULL));
		for(int fil = 0; fil < cf; fil++){
			for(int col = 0; col < cc; col++){
				matriz[fil][col] = rand()%100;
			}
		}
	}
