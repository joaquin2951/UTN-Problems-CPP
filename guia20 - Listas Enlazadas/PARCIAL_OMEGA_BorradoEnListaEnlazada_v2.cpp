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
void borrarF(NodoListaPtr *sPtr);
bool esPar(NodoListaPtr nodo);

int main() {
	NodoListaPtr startPtr = NULL;
	int item;
	while ( cin >> item )
		insertar( &startPtr, item );
	Parcial4( &startPtr );
	mostrarLista( startPtr );
	return 0;
}


void borrarF(NodoListaPtr *sPtr)
{
	if( (*sPtr)->sig == NULL )
	{
		NodoListaPtr temp;
		temp = *sPtr;
		*sPtr = NULL;
		delete temp;
	}
	else borrarF( &(*sPtr)->sig );
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

bool esPar(NodoListaPtr nodo)
{
	return nodo->info % 2 == 0;
}

void Parcial4( NodoListaPtr * sPtr ){
	
	int contenido;
	int cantParejas = 0;
	int cantImpares = 0;
	
	NodoListaPtr actual = *sPtr;
	
	if(*sPtr == NULL){
		cout << cantParejas << " " << cantImpares << endl;
	}
	else if( (*sPtr)->sig == NULL )
	{
		if( !esPar(*sPtr) )
			cantImpares++;
		cout << cantParejas << " " << cantImpares << endl;
	}
	else
	{
		
		NodoListaPtr temp;
		NodoListaPtr anterior = NULL;
		
		//mientras los dos primeros sean impares...
		while(actual != NULL && actual->sig != NULL)
		{
			if(!esPar(actual) and !esPar(actual->sig))
			{
				contenido = actual->info + actual->sig->info;
				//	insertar(&actual,contenido);
				cantParejas++;
				
				temp = actual->sig->sig;
				actual->sig->sig = NULL;
				borrarF(&actual);
				
				actual->sig = NULL;
				borrarF(&actual);
				
				if(anterior == NULL)
				{
					*sPtr = NULL;
					insertar(sPtr,contenido);
					(*sPtr)->sig = temp;
					actual = *sPtr;
					
				}
				else{
					anterior->sig = NULL;
					insertar(&anterior->sig,contenido);
					anterior->sig->sig = temp;
					//anterior->sig = temp;
					actual = anterior->sig;
				}
				
				
				
			}
			else
			{
				anterior = actual;
				actual = actual->sig;
			}
			
		}
		
		
		
		actual = *sPtr;
		while(actual!=NULL)
		{
			if(!esPar(actual))
				cantImpares++;
			actual=actual->sig;
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
	
