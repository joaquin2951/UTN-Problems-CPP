#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
	
	char vec[] = "hola mundo";
	
	cout << vec[0] << " " << vec[4] << " " << vec[9] << endl;
	cout << ":" << vec[10] << ":"  ;//Inicializar un arreglo de car�cter con una cadena agrega un car�cter \0 de terminaci�n.
	//se usa para marcar el final de una cadena.
	
	
	char test[] = {'a','b'};
	cout << "tamanio test: " << sizeof(test) << endl;
	
	int vec2[2];
	vec2[1] = rand()%100; cout << vec2[1] << " ";
	vec2[0] = rand()%100; cout << vec2[0] ;
	
	return 0;
}

