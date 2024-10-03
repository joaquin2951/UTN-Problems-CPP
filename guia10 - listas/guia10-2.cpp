#include <iostream>
using namespace std;

void mostrarvector(const int vec[], const int TL);
void ordenarVector(int vec[], const int TL);
void insertarElemVector(int vec[], int & TL, int elemento, int posicion);
int insertarMultiploX(int vec[], int & TL);

int main() {
	//const int TF = 500;
	int vec[] = {10,2,3,4,500}, TL, inserciones;
	TL = sizeof(vec)/4;
	
	cout << "TL: " << TL << endl;
	cout << "vector :   "; mostrarvector(&vec[0], TL); cout << endl;
	
	inserciones = insertarMultiploX(vec,TL);
	
	
	cout << "vector :   "; mostrarvector(&vec[0], TL); cout << endl << "TL: " << TL << endl << endl;
	cout << "elementos insertados: " << inserciones << endl;
	

	
	//cout << "vector ordenado:   "; ordenarVector(vec,TL); mostrarvector(vec,TL);
	
	
	
	
	return 0;
}

int insertarMultiploX(int vec[], int & TL){
	int inserciones = 0;
	
	for(int i = 0; i < TL; i++){
		if(vec[i] % 100 == 0){
			insertarElemVector(vec,TL,vec[i]+1,i);
			inserciones++;
			i++;
			
		}
		
	}
	return inserciones;
}
void insertarElemVector(int vec[], int & TL, int elemento, int posicion){
	
	for(int i = TL; i > posicion; i--){
		vec[i] = vec[i-1];
	}
	
	vec[posicion] = elemento;
	TL++;
}
void ordenarVector(int vec[], const int TL){
	for(int i = 0; i < TL-1; i++){
		
		for(int j = 1; j < TL; j++){
			
			if( vec[j] < vec[j-1] ){
				swap(vec[j], vec[j-1]);
			}
			
		}
	}
}
	

		
void mostrarvector(const int vec[], const int TL){
	for(int i = 0; i < TL; i++)
			cout << vec[i] << " ";
}
			
