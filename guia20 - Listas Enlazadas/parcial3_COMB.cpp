#include <stdlib.h>
#include <iostream>
using namespace std;
struct Nodo {
	int num;
	struct Nodo *sig;
};
typedef Nodo * NodoPtr;
void insertar( NodoPtr & sPtr, int valor );
void mostrarLista( NodoPtr actual );
void Parcial3( NodoPtr * L1 );
void ordenaDos(NodoPtr L1);


int main() {
	NodoPtr L1 = NULL;
	int valor;
	while ( cin >> valor )
		insertar( L1, valor );
	Parcial3( &L1 );
	
	return 0;
}
void insertar( NodoPtr & sPtr, int valor ) {
	NodoPtr nuevo;
	if (sPtr == NULL) {
		nuevo = new Nodo;
		if ( nuevo != NULL ) {
			nuevo->num = valor;
			nuevo->sig = NULL;
			sPtr = nuevo;}
		else cout << "No hay espacio";
	}
	else insertar (sPtr->sig, valor);
}

void ordenaDos(NodoPtr L1)
{
	
	NodoPtr actual = L1->sig;
	NodoPtr anterior = L1;

			int aux;
			aux = actual->num;
			actual->num = anterior->num;
			anterior->num = aux;

}

void Parcial3( NodoPtr * L1 ){
	
	if(*L1 != NULL && (*L1)->sig == NULL)
	{
		cout << "Lista inicialmente ordenada" << endl;
	}
	else if(*L1 != NULL)
	{
		
		int cantParejasOrdenadas = 0;
		NodoPtr actual = (*L1)->sig;
		NodoPtr anterior = *L1;
		
		while(actual != NULL)
		{
			if( anterior->num > actual->num )
			{
				ordenaDos(anterior);
				cantParejasOrdenadas++;
				actual = *L1;
			}
			
			anterior = actual;
			actual = actual->sig;
		}
		
		if(cantParejasOrdenadas == 0)
		{
			cout << "Lista inicialmente ordenada" << endl;
		}
		else
		{
			cantParejasOrdenadas = cantParejasOrdenadas*-1;
			
			actual = NULL;
			NodoPtr aux = *L1;
			insertar(actual,cantParejasOrdenadas);
			*L1 = actual;
			actual->sig = aux;
			mostrarLista( *L1 );
		}
	}
}
	void mostrarLista( NodoPtr actual ) {
		while ( actual != NULL ) {
			cout << actual->num << " -> ";
			actual = actual->sig;
		}
		cout << "NULL" << endl;
	}	
