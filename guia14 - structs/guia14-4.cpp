#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

struct ciudadano{
	int edad;
	char voto;
};


void inicializar_aleatorio(ciudadano Ciudadanos[],const int TF);
void mostrar_estructura(ciudadano Ciudadanos[], const int TF);
void porcentaje18a40(ciudadano Ciudadanos[],const int TF);
void porcentaje41a60(ciudadano Ciudadanos[],const int TF);
void porcentajeMasDe60(ciudadano Ciudadanos[],const int TF);

int main(int argc, char *argv[]) {
	
	ciudadano poblacion[10];
	inicializar_aleatorio(poblacion,10);
	mostrar_estructura(poblacion,10);
	
	porcentaje18a40(poblacion,10);
	porcentaje41a60(poblacion,10);
	porcentajeMasDe60(poblacion,10);
	
	return 0;
}


void porcentaje18a40(ciudadano Ciudadanos[],const int TF){
	int votoR = 0, votoA = 0;
	
	for(int i = 0; i < TF; i++){
			if(Ciudadanos[i].edad >= 18 and Ciudadanos[i].edad <= 40){
				if(Ciudadanos[i].voto == 'R'){
					votoR++;
				}else{
					votoA++;
				}
			}
	}
	
	cout << "porcentaje de votos [18,40] años para R: " << (float)(votoR*100.0) / (float)(votoR + votoA) << "%" << endl;
	cout << "porcentaje de votos [18,40] años para A: " << (float)(votoA*100.0) / (float)(votoR + votoA) << "%" << endl;
}
	
void porcentaje41a60(ciudadano Ciudadanos[],const int TF){
	int votoR = 0, votoA = 0;
	
	for(int i = 0; i < TF; i++){
		if(Ciudadanos[i].edad >= 41 and Ciudadanos[i].edad <= 60){
			if(Ciudadanos[i].voto == 'R'){
				votoR++;
			}else{
				votoA++;
			}
		}
	}
	
	cout << "porcentaje de votos [41,60] años para R: " << (float)(votoR*100.0) / (float)(votoR + votoA) << "%" << endl;
	cout << "porcentaje de votos [41,60] años para A: " << (float)(votoA*100.0) / (float)(votoR + votoA) << "%" << endl;
}
	
void porcentajeMasDe60(ciudadano Ciudadanos[],const int TF){
	int votoR = 0, votoA = 0;
	
	for(int i = 0; i < TF; i++){
		if(Ciudadanos[i].edad > 60){
			if(Ciudadanos[i].voto == 'R'){
				votoR++;
			}else{
				votoA++;
			}
		}
	}
	
	cout << "porcentaje de votos mayor a 60 años para R: " << (float)(votoR*100.0) / (float)(votoR + votoA) << "%" << endl;
	cout << "porcentaje de votos mayor a 60 años para A: " << (float)(votoA*100.0) / (float)(votoR + votoA) << "%" << endl;
}


void inicializar_aleatorio(ciudadano Ciudadanos[],const int TF){
	srand(time(NULL));
	
	for(int i = 0; i < TF; i++){
		Ciudadanos[i].edad = (rand() % 70) + 18;
		
		switch(rand() % 2){
			case 0: Ciudadanos[i].voto = 'R'; break; 
			case 1: Ciudadanos[i].voto = 'A'; break;
		}
		
	}

}

void mostrar_estructura(ciudadano Ciudadanos[], const int TF){
	for(int i = 0; i < TF; i++){
		cout << Ciudadanos[i].edad << " " << Ciudadanos[i].voto << "  |  ";
	}
	cout << endl << endl;
}
