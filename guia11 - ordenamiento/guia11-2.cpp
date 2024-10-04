#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;


void inicializar_aleatorio(int vec[],const int TL);
void mostrar_vector(const int vec[], const int TL);
void borrar_elemento(int vec[], int & TL, int posicionElemento);
void ordenarBurbuja(int vec[], const int TL);
int elimOrdenar(int vec[], int & TL, int X);

int main() {
	const int TF = 300;
	int numeros[TF], TL = TF, Elemeliminados;
	
	inicializar_aleatorio(numeros,TL);
	mostrar_vector(numeros,TL);
	
	cout << endl << "TL: " << TL;
	cout << endl << "---------------------" << endl << endl;
	
	Elemeliminados = elimOrdenar(numeros,TL,2);
	mostrar_vector(numeros,TL);
	
	cout << endl << "se han eliminado: " << Elemeliminados << " elementos" << endl;
	cout << "TL: " << TL << endl;
	
	return 0;
}


int elimOrdenar(int vec[], int & TL, int X){
	int eliminados = 0;
	
	for(int i = 0; i < TL; i++){
		if(vec[i] % X == 0){
				borrar_elemento(vec,TL,i);
				eliminados++;
				i--;
		}
	}
	ordenarBurbuja(vec,TL);
	
	return eliminados;
}

void ordenarBurbuja(int vec[], const int TL){
		
	bool intercambios = true;
	int pasada = 1;
	
	while(pasada < TL and intercambios){
		intercambios = false;
		
		for(int j = 0; j < TL-pasada; j++){
			if(vec[j] > vec[j+1]){
				swap(vec[j],vec[j+1]);
				intercambios = true;
			}
				
		}
		
		pasada++;
	}
	
		
	
	
}
	
void borrar_elemento(int vec[], int & TL, int posicionElemento){
	for(int i = posicionElemento; i < TL-1; i++){
		vec[i] = vec[i+1];
	}
	TL--;
}

void inicializar_aleatorio(int vec[],const int TL){
	srand(time(NULL));
	
	for(int i = 0; i < TL; i++){
	 vec[i] = rand()%150;	
	}
}

void mostrar_vector(const int vec[], const int TL){
		for(int i = 0; i < TL; i++){
			cout << vec[i] << " ";
		}
}
