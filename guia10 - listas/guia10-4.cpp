#include <iostream>
using namespace std;
bool todosPositivos(const int vec[], const int TL);
float promedioVec(const int vec[], const int TL);
void eliminarElemento(int vec[], int & TL, const int posicion);
void imprimirvector(const int vec[], const int TL);
int eliminarImpares(int vec[], int & TL, int & diferencia);

int main() {
	
	int vec[] = {1,2,3,4,7,9,12,14,15,20};	
	int TL = sizeof(vec)/4;
	
	
	
	if(todosPositivos(&vec[0],TL)){
		imprimirvector(&vec[0],TL);
		int diferencia = 0;
		int paresEliminados = eliminarImpares(vec,TL,diferencia);
		
		cout << endl << endl << "Nuevo vector actualizado: " << endl; imprimirvector(&vec[0],TL);
		cout << endl << "La cantidad de numeros impares eliminados es de: "  << paresEliminados;
		cout << endl << "La mayor diferencia entre dos pares consecutivos es: " << diferencia;
	}
	else
										cout << "NO todos los elementos del vector son positivos. " << endl;
	
	return 0;
}


int eliminarImpares(int vec[], int & TL, int & diferencia){//hacerlo suponiendo que NO PODEMOS ORDENAR EL VECTOR y está desordenado.
	int imparesEliminados = 0;
	
	for(int i = 0; i < TL; i++){
		for(int j = i+1; j < TL; j++){
			if(vec[j] % 2 == 0 and vec[j-1] % 2 == 0){
				if(vec[j] - vec[j-1] > diferencia)
					diferencia = vec[j] - vec[j-1];
			}
			else
			if(vec[j] % 2 != 0 and vec[j-1] % 2 == 0 and vec[j+1] % 2 == 0){
				imparesEliminados++;
				eliminarElemento(vec,TL,j);
				j--;
			}
			
		}
	}
	
	
	return imparesEliminados;
}
	
	void eliminarElemento(int vec[], int & TL, const int posicion){
		for(int i = posicion; i < TL-1; i++)
			vec[i] = vec[i+1];
		
		TL--;
	}
		
		
			
			bool todosPositivos(const int vec[], const int TL){
				for(int i = 0; i < TL ; i++)
					if(vec[i] <= 0)
					return false;
				return true;
			}
				
				void imprimirvector(const int vec[], const int TL){
					for(int i = 0; i < TL; i++)
						cout << vec[i] << " ";
				}
					
