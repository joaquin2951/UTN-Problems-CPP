#include <stdlib.h>
#include <iostream>
#include <cstdio>
using namespace std;
struct NodoLista {
	int info;
	struct NodoLista *sig;
};
typedef NodoLista * NodoListaPtr;
void insertarFinal( NodoListaPtr *sPtr, int valor );
void printLista( NodoListaPtr actual );
int Parcial3( NodoListaPtr *sPtr );
int main() {
	NodoListaPtr startPtr = NULL;
	int item;
	while ( cin >> item )
		insertarFinal( &startPtr, item );
	cout << Parcial3( &startPtr ) << endl;
	printLista( startPtr );
	return 0;
}
void insertarFinal( NodoListaPtr *sPtr, int valor ) {
	NodoListaPtr nuevo;
	if (*sPtr == NULL) {
		nuevo = new NodoLista;
		if ( nuevo != NULL ) {
			nuevo->info = valor;
			nuevo->sig = NULL;
			*sPtr = nuevo;}
		else cout << "No hay espacio";
	}
	else insertarFinal (&(*sPtr)-> sig,valor);
}
int Parcial3( NodoListaPtr * sPtr ){
	
	int inserciones = 0;
	NodoListaPtr actual = *sPtr;
	if(actual != NULL)
	{
		NodoListaPtr temp;
		
		
		//Si es el primer nodo...
		if( (actual)->info % 2 != 0)
		{
			temp = actual;
			*sPtr = NULL;
			insertarFinal(sPtr,-1);
			(*sPtr)->sig = temp;
			inserciones++;
		}
		
		if(actual->sig != NULL)
		{
			NodoListaPtr anterior = actual;
			actual = actual->sig;
			
			while(actual != NULL)
			{
				
				if(actual->info % 2 != 0)
				{
					anterior->sig = NULL;
					insertarFinal(&anterior,-1);
					anterior->sig->sig = actual;
					inserciones++;
				}
				
				anterior = actual;
				actual = actual->sig;
			}
		}
		
	}
	
	return inserciones;
}
void printLista( NodoListaPtr actual ) {
	while ( actual != NULL ) {
		cout << actual->info << " -> ";
		actual = actual->sig;
	}
	cout << "NULL" << endl;
}