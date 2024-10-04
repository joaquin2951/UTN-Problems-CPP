#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void inicializar_aleatorio(int vec[],const int TL);
void mostrar_vector(const int vec[], const int TL);
void Uno(const int A[], const int TLA, const int B[], const int TLB, const bool C);
bool esEnArreglo(const int vec[], const int TL, const int elemBuscado);
void BurbujaAsc(int vec[], const int TL);
void BurbujaDesc(int vec[], const int TL);

int main() {
	const int TF = 200;
	int A[TF], B[TF], TL = TF;
	
	inicializar_aleatorio(A,TL);
	inicializar_aleatorio(B,TL);
	
	mostrar_vector(A,TL);
	cout << endl << "--------------------" << endl;
	mostrar_vector(B,TL);
	cout << endl << "--------------------" << endl;
	
	Uno(A,TL,B,TL,0);
	
	return 0;
}

void Uno(const int A[], const int TLA, const int B[], const int TLB, const bool C){
	int V[400], TLV = 0, j = 0;
		
		while(j < TLB){
			
			if ( esEnArreglo(A,TLA,B[j]) == true and esEnArreglo(V,TLV,B[j]) == false ){
				V[TLV] = B[j];
				TLV++;
			}
			
			j++;
		}
		
		if(C){
			BurbujaAsc(V, TLV);
		}else{
			BurbujaDesc(V,TLV);
		}

		for(int k = 0; k < TLV; k++)
					cout << V[k] << " ";
		
		cout << endl << endl << "TLV: " << TLV << endl << "TLA: " << TLA << endl << "TLB: " << TLB << endl;
		
	
}

	void BurbujaDesc(int vec[], const int TL){
		int pasadas = 1;
		bool intercambios = true;
		
		while(pasadas < TL && intercambios){
			intercambios = false;
			for( int j = 0; j < TL-pasadas; j++ ){
				if(vec[j] < vec[j+1]){
					intercambios = true;
					swap(vec[j],vec[j+1]);
				}
			}
		}
	}
	
	void BurbujaAsc(int vec[], const int TL){
	 int pasadas = 1;
	 bool intercambios = true;
		
	 while(pasadas < TL && intercambios){
		 intercambios = false;
		 for( int j = 0; j < TL-pasadas; j++ ){
			 if(vec[j] > vec[j+1]){
				 intercambios = true;
				 swap(vec[j],vec[j+1]);
			 }
		 }
	 }
	 
	}
	
bool esEnArreglo(const int vec[], const int TL, const int elemBuscado){
		
	for(int i = 0; i < TL; i++)
		if(vec[i] == elemBuscado)
			return true;
	
	return false;
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
		
