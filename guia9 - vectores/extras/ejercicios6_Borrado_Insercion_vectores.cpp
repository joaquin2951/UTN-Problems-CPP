#include <iostream>
using namespace std;

void mostrarVec(const int vec[], int TL);
void cargarVec(int vec[], int TL);
void insertarElemento(int vec[], int & TL, const int elemento, const int posicion);
void borrarElemento(int vec[], int & TL, const int posicion);

int main() {
	const int TF = 100;
	int TL = 5;
	int vec[TF],pos,elem;
	
	
	cargarVec(&vec[0],TL);
	mostrarVec(&vec[0],TL);
	
	cout << "elemento a insertar? "; cin >> elem;
	cout << "posicion a insertarlo? "; cin >> pos;
	
	insertarElemento(&vec[0],TL,elem,pos); 
	mostrarVec(&vec[0],TL);
	
	
	cout << "posicion de elemento a borrar? "; cin >> pos;
	borrarElemento(vec,TL,pos);
	mostrarVec(&vec[0],TL);
	
	return 0;
}

void insertarElemento(int vec[], int & TL, const int elemento, const int posicion){
		
	  //if (TL == TF) return;     si declaro un TF global.
	
		for(int i = TL ; i > posicion; i--){
			vec[i] = vec[i-1];
		}
		
		vec[posicion] = elemento;
		TL++;
}

void borrarElemento(int vec[], int & TL, const int posicion){
	
	if(posicion >= TL) return;
	
	for(int i = posicion; i < TL-1; i++)
			vec[i] = vec[i+1];
		
		TL--;
}

void mostrarVec(const int vec[], int TL){
	for(int i = 0; i < TL; i++)
		cout << "vec[" << i << "] = " << vec[i] << endl;
}
	
void cargarVec(int vec[], int TL){
		for(int i = 0; i < TL; i++)
			cin >> vec[i];
}

		
