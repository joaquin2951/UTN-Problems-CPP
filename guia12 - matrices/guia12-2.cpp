#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

#define categorias 4
#define localidades 50


using namespace std;

void cargar_matriz(int matriz[][localidades],const int filas, const int columnas);
void cargar_matrizAleatorio(int matriz[][localidades],const int filas, const int columnas);
void imprimir_matriz(const  int matriz[][localidades],const int filas, const int columnas);
void cantPasajerosLocalidad(const int matriz[][localidades], const int filas, const int columnas);
void cantPasajerosCategoria(const int matriz[][localidades], const int filas, const int columnas);
void localidadesSinPasaje(const int matriz[][localidades], const int filas, const int columnas);
bool seVendioPasajeEnCategoria(const int matriz[][localidades], const int filas, const int columnas);


int main() {
int pasajes[categorias][localidades];	 //Categorias 0 al 3  y localidades 0 al 49
string destino[localidades]; //nombres de las localidades , ordenadas por cod de destino

cargar_matrizAleatorio(pasajes,categorias,localidades);
pasajes[0][2] = 0; pasajes[1][2] = 0; pasajes[2][2] = 0; pasajes[3][2] = 0;
pasajes[2][0] = 0; pasajes[2][1] = 0; pasajes[2][2] = 0;

imprimir_matriz(pasajes,categorias,localidades);
cout << endl << endl;
cantPasajerosLocalidad(pasajes,categorias,localidades); cout << endl;
cantPasajerosCategoria(pasajes,categorias,localidades); cout << endl;
localidadesSinPasaje(pasajes,categorias,localidades);   cout << endl;
	
	return 0;
}





void localidadesSinPasaje(const int matriz[][localidades], const int filas, const int columnas){
	bool noVendio;
	int fil, col=0;
	
	for(col; col < columnas; col++){
		fil = 0; noVendio = true;
		
		while(noVendio and fil < filas){
				if(matriz[fil][col] != 0)
					noVendio = false;
				
				fil++;
		}
		
		if(noVendio)
					cout << "La localidad " << col << " no vendio ningun pasaje" << endl;
	}
	
	
}

void cantPasajerosCategoria(const int matriz[][localidades], const int filas, const int columnas){
	int pasajeros;
	bool noSeVendio = false;
	for(int fil = 0; fil < filas; fil++){
		pasajeros = 0;
		for(int col = 0; col < columnas; col++){
			pasajeros+=matriz[fil][col];
		}
		cout << "La cantidad de pasajeros en la categoria " << fil << " es de: " << pasajeros << endl;
		if(pasajeros == 0)
			noSeVendio = true;
	}
	
	if(noSeVendio == true)
		cout << "No se vendio ningun pasaje en al menos una categoria de avion " << endl;
}

void cargar_matriz(int matriz[][localidades],int filas, int columnas){
	for(int fil = 0; fil < filas; fil++){
		for(int col = 0; col < columnas; col++){
			cout << "[" << fil << "][" << col <<"] = ";
			cin >> matriz[fil][col];
		}
	}
}

void imprimir_matriz(const  int matriz[][localidades],const int filas, const int columnas){
	for(int fil = 0; fil < filas; fil++){
		cout << endl;
		for(int col = 0; col < columnas; col++){
			cout << matriz[fil][col] << "  ";
			
		}
	}
}

void cantPasajerosLocalidad(const int matriz[][localidades], const int filas, const int columnas){
	int cantPasajeros, localMin = 0, min = 0, masDeMil = 0;
	for(int col = 0 ; col < columnas; col++){//recorre por localidad
		cantPasajeros = 0;
			for(int fil = 0; fil < filas; fil++){//recorre las categorias
				cantPasajeros = cantPasajeros + matriz[fil][col];
			}
			cout << "La cantidad de pasajeros en la localidad " << col << " es de: " << cantPasajeros << endl;
			
			if(cantPasajeros > 1000)
				masDeMil++;
			
			if(col == 0){
				min = cantPasajeros;
			}else{
				if(cantPasajeros < min){
					min = cantPasajeros;
					localMin = col;
				}
			}
		}
	cout << endl << "La localidad a la que viajo menos cantidad de pasajeros es la localidad " << localMin << endl;
	cout << "En " << masDeMil << " localidades viajaron mas de 1000 pasajeros" << endl;
}

void cargar_matrizAleatorio(int matriz[][localidades],const int filas, const int columnas){
		srand(time(NULL));
		
		
		for(int fil = 0; fil < filas; fil++){
			for(int col = 0; col < columnas; col++){
				matriz[fil][col] = rand() % 1000;
			}
		}
		
}
