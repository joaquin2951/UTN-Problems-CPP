#include <stdlib.h>
#include <iostream>
#include <cstdio>
using namespace std;
struct NodoLista {
	int info;
	struct NodoLista *sig;
};
typedef NodoLista * NodoListaPtr;
void insertar( NodoListaPtr *sPtr, int valor );
void mostrarLista( NodoListaPtr actual );
void Parcial4( NodoListaPtr *sPtr );



int main() {
	NodoListaPtr startPtr = NULL;
	int item;
	while ( cin >> item )
		insertar( &startPtr, item );
	Parcial4( &startPtr );
	mostrarLista( startPtr );
	return 0;
}



void insertar( NodoListaPtr *sPtr, int valor ) {
	NodoListaPtr nuevo;
	if (*sPtr == NULL) {
		nuevo = new NodoLista;
		if ( nuevo != NULL ) {
			nuevo->info = valor;
			nuevo->sig = NULL;
			*sPtr = nuevo;}
		else cout << "No hay espacio";
	}
	else insertar (&(*sPtr)-> sig,valor);
}


void Parcial4( NodoListaPtr * sPtr ){

	int contenido;
	int cantParejas = 0;
	int cantImpares = 0;
	
	
	NodoListaPtr actual = *sPtr;
	
	
	if(actual == NULL || actual->sig == NULL){
		if(actual!=NULL and actual->info % 2 != 0)
			cantImpares++;
		cout << cantParejas << " " << cantImpares << endl;
	}
	else{
		
			while(actual != NULL && actual->sig != NULL)
			{
				
				if(actual->info % 2 !=0 and (actual->sig)->info % 2 != 0){
				NodoListaPtr temp;
				temp = actual->sig;
				
				contenido = actual->info + actual->sig->info;
				actual->info = contenido;
				actual->sig = temp->sig;
				delete temp;
				
				cantParejas++;
				}
				else
					 actual = actual->sig;
			}
			
			actual = actual->sig;
		
	
		
		actual = *sPtr;
		
		while(actual!=NULL)
		{
			if(actual->info % 2 != 0)
				cantImpares++;
			actual = actual->sig;
		}
		
		cout << cantParejas << " " << cantImpares << endl;
	}
	
	
	
}
	void mostrarLista( NodoListaPtr actual ) {
		while ( actual != NULL ) {
			cout << actual->info << " -> ";
			actual = actual->sig;
		}
		cout << "NULL" << endl;
	}
