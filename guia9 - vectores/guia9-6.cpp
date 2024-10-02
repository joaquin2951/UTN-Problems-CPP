#include <iostream>
using namespace std;

void imprimir_vector(const int vec[], const int tf);
int seRepite(const int vec[], const int TF, int numeroRepetido);
int seRepiteRecursivo(const int vec[], int TF, int numeroRepetido);
bool todosIguales(const int vec[], const int TF);

int main() {
	int vec[] = {3,6,2,4,1,5,6,5,6,5,4,6,7};
	int n = 5;
	
	cout << sizeof(vec)/4 << " elementos en el arreglo entero" << endl;
	
	cout << "aparece el numero: " << n << ", " << seRepite(&vec[0], 13, n) << " veces en el arreglo" << endl;
	cout << "aparece el numero: " << n << ", " << seRepiteRecursivo(&vec[0], 13, n) << " veces en el arreglo (forma recursiva)" << endl;
	
	
	int vec2[] = {1,1,1,1,1};
	
	cout << endl << "vector2: " << endl; imprimir_vector(vec2,5);
	cout << "son todos iguales en vector2? " << boolalpha << todosIguales(vec2,5);
	
	
	return 0;
}

bool todosIguales(const int vec[], const int TF){
	bool iguales = true;
	int i = TF-1;
	
	while (iguales == true and i >= 0){
		if(vec[i] != vec[0])	
			iguales = false;
		
		i--;
	}
	
	return iguales;
}

int seRepiteRecursivo(const int vec[], int TF, int numeroRepetido){
	
	if(TF == 0){
		if(numeroRepetido == vec[TF])
			return 1;
		else 
			return 0;
	}
	else
		 if(vec[TF-1] == numeroRepetido)
				return 1 + (seRepiteRecursivo(&vec[0],TF-1,numeroRepetido));
		 else return 0 + (seRepiteRecursivo(&vec[0],TF-1,numeroRepetido));
	
}

int seRepite(const int vec[], const int TF, int numeroRepetido){
	int contadorRepeticiones = 0;
	
	for(int i = 0; i < TF; i++)
		if(vec[i] == numeroRepetido)
			contadorRepeticiones++;
	
	return contadorRepeticiones;
}

void imprimir_vector(const int vec[], const int tf){
		for(int i = 0; i < tf; i++)
			cout << vec[i] << endl;
		
}
