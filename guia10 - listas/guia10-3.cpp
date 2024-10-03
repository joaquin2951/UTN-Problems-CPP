#include <iostream>
using namespace std;
bool todosPositivos(const int vec[], const int TL);
float promedioVec(const int vec[], const int TL);
void eliminarElemento(int vec[], int & TL, const int posicion);
void imprimirvector(const int vec[], const int TL);
int eliminarRepetidos(int vec[], int & TL, float & promedio);

int main() {
	
	int vec[] = {1,2,3,4,5,2,4,6,6,6};	
	int TL = sizeof(vec)/4;
	
	
	
	if(todosPositivos(&vec[0],TL)){
		imprimirvector(&vec[0],TL);
		float promedio = 0.0;
		int paresEliminados = eliminarRepetidos(vec,TL,promedio);
		
		cout << endl << endl << "Nuevo vector actualizado: " << endl; imprimirvector(&vec[0],TL);
		cout << endl << "La cantidad de numeros pares eliminados es de: "  << paresEliminados;
		cout << endl << "El promedio de la suma del vector resultante es: " << promedio;
	}
	else
			cout << "NO todos los elementos del vector son positivos. " << endl;
	
	return 0;
}


int eliminarRepetidos(int vec[], int & TL, float & promedio){//hacerlo suponiendo que NO PODEMOS ORDENAR EL VECTOR y está desordenado.
	int paresEliminados = 0;
	
	for(int i = 0; i < TL; i++){
		for(int j = i+1; j < TL; j++){
			if(vec[j] == vec[i]){
				
				if(vec[j] % 2 == 0)
					paresEliminados++;
				
				eliminarElemento(vec,TL,j);
				j--;
			}
		}
	}
	
	promedio = promedioVec(vec,TL);
	return paresEliminados;
}

void eliminarElemento(int vec[], int & TL, const int posicion){
	for(int i = posicion; i < TL-1; i++)
		vec[i] = vec[i+1];
	
	TL--;
}

	float promedioVec(const int vec[], const int TL){
			float promedio = 0;
			for(int i = 0; i < TL; i++)
				promedio = promedio + (float)vec[i];
			
			promedio = promedio / TL;
			return promedio;
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
