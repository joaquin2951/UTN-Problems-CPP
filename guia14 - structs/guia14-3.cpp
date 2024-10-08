#include <iostream>
#include <ctime>
#include <cstdlib>
#define TAM 10
using namespace std;



struct alumno{
	int idUsuario;
	string clave = "aedd2024";
};

void ordenar_alumnos(alumno alumnos[],const int TF);
void inicializar_aleatorio(alumno alumnos[], const int TF);
void mostrar_estructura(alumno alumnos[], const int TF);
int estaAlumno(alumno alumnos[], const int TF, const int ID);

int main(int argc, char *argv[]) {
	alumno alumnos[TAM];
	int ID, posicion;
	
	inicializar_aleatorio(alumnos,TAM);
	alumnos[3].clave = "ZZZZZZ";
	mostrar_estructura(alumnos,TAM);
	
	
	cout << endl << endl << endl;
	cout << endl << endl << endl;
	cout << "ingrese ID de usuario: " << endl;
	cin >> ID; cin.ignore(); cin.clear();
	posicion = estaAlumno(alumnos,TAM,ID);
	
	
	cout << "posicion: " << posicion << endl;
	
	if( posicion != -1){
		
		if(alumnos[posicion].clave == "aedd2024"){
			cout << "puede ingresar nuevamente su clave: "; getline(cin,alumnos[posicion].clave);
			cout << "Clave cambiada con éxito." << endl;
		}else{
			cout << "usted ya ha cambiado su contraseña." << endl;
		}
		
	}else{
		cout << " ID INCORRECTO " << endl;
	}
	
	ordenar_alumnos(alumnos,TAM);
	mostrar_estructura(alumnos,TAM);
	
	return 0;
}

void ordenar_alumnos(alumno alumnos[],const int TF){
	
	bool intercambios = true;
	int pasada = 1;
	
	while(pasada < TF and intercambios){
		intercambios = false;
		
		for(int j = 0; j < TF-pasada; j++){
			if(alumnos[j].idUsuario > alumnos[j+1].idUsuario){
				swap(alumnos[j],alumnos[j+1]);
				intercambios = true;
			}
			
		}
		
		pasada++;
	}
	
}

	
	
	
int estaAlumno(alumno alumnos[], const int TF, const int ID){
	int posicion = 0;
	
	while(posicion < TF){
		if(alumnos[posicion].idUsuario == ID)
			return posicion;
		posicion++;
	}
	return -1;
}

void inicializar_aleatorio(alumno alumnos[], const int TF){
	srand(time(NULL));
	for(int i = 0; i < TF; i++){
		alumnos[i].idUsuario = (rand() % 90000)  + 10000;
	}
}

void mostrar_estructura(alumno alumnos[], const int TF){
	for(int i = 0; i < TF; i++){
		cout << alumnos[i].idUsuario << "  " << alumnos[i].clave << " | ";
	}
}
