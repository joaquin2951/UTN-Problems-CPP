#include <iostream>
using namespace std;

void mostrarVec(const int vec[], int TL);
void cargarVec(int vec[], int TL);
int maximo(const int vec[], int TL);
int maxRecursivo(const int vec[], int TL);

int main() {
	const int TAMANHO = 4;
	int vector[TAMANHO];
	
	cargarVec(vector,TAMANHO);
	mostrarVec(vector,TAMANHO);
	
	cout << "maximo: " << maximo(vector,TAMANHO);
	cout << "maximo recursivo: " << maxRecursivo(vector,TAMANHO);
	return 0;
}


void mostrarVec(const int vec[], int TL){
	for(int i = 0; i < TL; i++)
		cout << "vec[" << i << "] = " << vec[i] << endl;
}
	
void cargarVec(int vec[], int TL){
	for(int i = 0; i < TL; i++)
		cin >> vec[i];
}
	
	
int maximo(const int vec[], int TL){
	int mx = vec[0];
	for(int i = 1; i < TL; i++)
		if(mx < vec[i])
			mx = vec[i];
	return mx;
}
	
	
	
int maxRecursivo(const int vec[], int TL){
	
	//caso base
	if(TL == 1)
		return vec[0];	
	
	//caso general
	else{
		int aux = maxRecursivo(&vec[1],TL-1);//con &vec[1] le digo a la funcion que el vector arranca en en la posicion de memoria de vec[1]. Ignorando vec[0].
		if(vec[0] > aux)
			return vec[0];
		else
			return aux;
	}
		
	//1,3,2  TL = 3. 
	//aux = maxRec( [3,2] , TL = 2) --> aux = maxRec( [2] , TL = 1 ) --> return 2;
	//
}

