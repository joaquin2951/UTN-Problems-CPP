#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#define TF 5

void inicializar_teclado(int vec[], int tf);
void inicializar_aleatorio(int vec[], int tf);
void imprimir_vector(const int vec[], const int tf);
int mayor(const int vec[], const int tf);
float sumYprom(const int vec[], const int tf, int & sumatoria);
void arregloInverso(const int vec[], const int tf, int arregloAinvertir[]);

int main() {
	
	int TL , vec[TF], suma = 0, vecInv[TF];
	
	//inicializar_teclado(&vec[0],TF);
	inicializar_aleatorio(&vec[0],TF);
	
	imprimir_vector(&vec[0], TF);
	
	cout << "mayor: " << mayor(&vec[0],TF) << endl;
	
	cout << "promedio: " << sumYprom(&vec[0],TF,suma) << "  |  suma: "; 
	cout << suma << endl;
	
	arregloInverso(&vec[0],TF,&vecInv[0]);
	cout << "arreglo invertido: " << endl; imprimir_vector(&vecInv[0],TF);
	
	
	
	return 0;
}

void arregloInverso(const int vec[], const int tf, int arregloAinvertir[]){
	
	
	for(int i = 0; i < tf; i++)
		arregloAinvertir[i] = vec[tf-1-i];
	
	
}

float sumYprom(const int vec[], const int tf, int & sumatoria){
 
 for(int i = 0; i < tf; i++)
	 sumatoria = sumatoria + vec[i];
 
	return  ((float)sumatoria/tf);  //retorna el promedio de la sumatoria
}

int mayor(const int vec[], const int tf){
 int aux = vec[0];
 for(int i = 1; i < tf ; i++)
	 if(vec[i] > aux)
	 aux = vec[i];
	
 return aux;
}

void inicializar_aleatorio(int vec[], int tf){
	
	srand(time(NULL));
	
	for(int i = 0; i < tf; i++)
		vec[i] = rand()%100;
		
	
}


void inicializar_teclado(int vec[], int tf){
	for(int i = 0; i < tf; i++){
		cin >> vec[i] ;
	}
}

void imprimir_vector(const int vec[], const int tf){
	for(int i = 0; i < tf; i++)
		cout << vec[i] << endl;
	
}
