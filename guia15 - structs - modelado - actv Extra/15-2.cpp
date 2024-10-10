#include <iostream>
#include <string>
using namespace std;

#define TAM 10

struct Palabra{
	string termino; //25 caract. máx.
	char categoria; //0 = sustantivo, 1 = adjetivo, 2 = articulo, 3 = pronombre, 4 = verbo
	string definiciones[5];
};


int cantDeArticulos(const Palabra diccionario[], const int TL);
void encontrarPalabra(const Palabra diccionario[], const int TL, const string termino, bool & encontrado);
void agregarPalabra(Palabra diccionario[], int & TL, const Palabra palabra);
void OrdenarPalabras(Palabra diccionario[], int inicio, int fin);
void merge(Palabra diccionario[], int inicio1, int fin1, int inicio2, int fin2);

int main(int argc, char *argv[]) {
	
	
	cout << (int)'A' << endl;
	cout << (int)'Z' << endl;
	cout << 0 + (int)'A' << endl;
	cout << 1 + (int)'A' << endl;
	cout << 2 + (int)'A' << endl;
	cout << 25 + (int) 'A' << endl;
	
	Palabra diccionario[TAM];  int TL = 0;  bool encontrado = true;
	
	Palabra p1; p1.categoria = '0'; p1.termino = "Casa";
	Palabra p2; p2.categoria = '0'; p2.termino = "Sorengue";
	Palabra p3; p3.categoria = '0'; p3.termino = "Zalamanca";
	Palabra p4; p4.categoria = '0'; p4.termino = "Onomatopeya";
	Palabra p5; p5.categoria = '0'; p5.termino = "Abeja";
	Palabra p6; p6.categoria = '0'; p6.termino = "Dengue";
	
	agregarPalabra(diccionario,TL,p1); cout << "TL: " << TL << endl;
	agregarPalabra(diccionario,TL,p2); cout << "TL: " << TL << endl;
	agregarPalabra(diccionario,TL,p3); cout << "TL: " << TL << endl;
	agregarPalabra(diccionario,TL,p4); cout << "TL: " << TL << endl;
	agregarPalabra(diccionario,TL,p5); cout << "TL: " << TL << endl;
	agregarPalabra(diccionario,TL,p6); cout << "TL: " << TL << endl;
	
	for(int i = 0; i < TL; i++){
		cout << diccionario[i].termino << endl;
	}
	
	
	
	return 0;
}



void OrdenarPalabras(Palabra diccionario[], int inicio, int fin){
	//ordenamiento mergesort
	
	if(fin - inicio == 0)
		return;
	else{
		OrdenarPalabras(diccionario,inicio,(inicio + fin) / 2);
		OrdenarPalabras(diccionario, (inicio + fin) / 2 + 1, fin);
		merge(diccionario, inicio, (inicio + fin) / 2, (inicio + fin) / 2 + 1, fin);
	}
	
	
}

void merge(Palabra diccionario[], int inicio1, int fin1, int inicio2, int fin2){
	
	int i,j,k;
	i = inicio1;
	j = inicio2;
	k = 0;
	Palabra vec[TAM];
	
	while(i <= fin1 && j <= fin2)
		if(diccionario[i].termino < diccionario[j].termino)
			vec[k++] = diccionario[i++];
		else
			vec[k++] = diccionario[j++]; 
	
	while(i <= fin1)
		vec[k++] = diccionario[i++];
	
	while(j <= fin2)
		vec[k++] = diccionario[j++];
	
	
	
	for(k = 0; k < fin2 - inicio1 + 1; k++)
		diccionario[inicio1 + k] = vec[k];
	
	
}

void agregarPalabra(Palabra diccionario[], int & TL, const Palabra palabra){
	
	if(TL == TAM)
		cout << "No se puede agregar palabra." << endl;
	else if(TL == 0){
		diccionario[0] = palabra;
		TL++;
	}else{
		
		//buscamos la posición en la que hay que agregarla.
		int inferior = 0, superior = TL - 1;
		int medio, posicionInsertar = -1;
		
		if(palabra.termino < diccionario[0].termino)
			posicionInsertar = 0;
		else{
		
			while(inferior <= superior && posicionInsertar == -1){
				medio = (inferior + superior) / 2;
			
				if( diccionario[medio].termino <= palabra.termino && (diccionario[medio+1].termino >= palabra.termino || diccionario[medio+1].termino.empty()) ){
					posicionInsertar = medio+1;
				
				}else if( diccionario[medio].termino < palabra.termino){
				
					inferior = medio + 1;
					medio = (inferior + superior) / 2;
				
				}else{
				
					superior = medio - 1;
					medio = (inferior + superior) / 2;
				
				}
				
			}
		}
		
		//sabemos que debemos insertar la palabra en la posicionInsertar, por lo tanto , hay que desplazar el resto de palabras del diccionario
		//un lugar a la derecha.
		
		for(int i = TL; i > posicionInsertar; i--){
			diccionario[i] = diccionario[i - 1];
		}
		
		diccionario[posicionInsertar] = palabra;
		TL++;
		
	}
	
	
}


void encontrarPalabra(const Palabra diccionario[], const int TL, const string termino, bool & encontrado){
	
	//Algoritmo de busqueda binaria para buscar la palabra en un array ordenado.
	int inferior = 0, superior = TL-1, medio;
	encontrado = false;
	
	while(inferior <= superior && encontrado == false){
		
		medio = (inferior + superior) / 2;
		
		if(diccionario[medio].termino == termino){
			encontrado = true;
		}else 
			 if(diccionario[medio].termino < termino){
						inferior = medio + 1;
						medio = (inferior + superior) / 2;
			}else{
				 superior = medio - 1;
				 medio = (inferior + superior) / 2;
			 }
		
		
	}
	
	if(encontrado){//si lo encontró, está en la posición MEDIO del arreglo diccionario.
		
		int i = 0;
		
		while(i < 5 && !diccionario[medio].definiciones[i].empty()){
			cout << i+1 << " " << diccionario[medio].definiciones[i] << endl;
			i++;
		}
		
		
	}
	
}

int cantDeArticulos(const Palabra diccionario[], const int TL){
	int articulos = 0;
	
	for(int i = 0; i < TL; i++){
	
		if( diccionario[i].categoria == '2' )
				articulos++;
		
		
	}
	
	return articulos;
}
