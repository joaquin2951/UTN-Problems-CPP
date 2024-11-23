#include <iostream>
using namespace std;

struct NodoLista
{
		int info;
		struct NodoLista * siguiente;
};

typedef NodoLista * NodoListaPtr;

void insertar(NodoListaPtr * startPtr, int valor);
void ver(NodoListaPtr startPtr);
void ordenar(NodoListaPtr * startPtr);

int main(int argc, char *argv[]) {
	NodoListaPtr lista = NULL;
	insertar(&lista,4);
	insertar(&lista,0);
	insertar(&lista,1);
	insertar(&lista,2);
	insertar(&lista,-3);
	
	ver(lista);
	
	ordenar(&lista);
	
	ver(lista);
	return 0;
}

void ordenar(NodoListaPtr * startPtr)
{
	
	NodoListaPtr actual;
	
	actual = *startPtr;
	
	if(actual == NULL){ cout << "lista vacia" << endl; }
	else if(actual->siguiente == NULL){ cout << "Ordenada. Solo hay un elemento." << endl;}
	else{
		
		NodoListaPtr sig;
		
		while(actual != NULL)
		{
			sig = actual->siguiente;
			
			while(sig != NULL)
			{
				
				if(sig->info < actual->info)
				{
					int aux;
					aux = sig->info;
					sig->info = actual->info;
					actual->info = aux;
				}
				
				sig = sig->siguiente;
			}
			
			actual=actual->siguiente;
			
		}
	}
	
	
	
	
	
}


void ver(NodoListaPtr startPtr)
{
	while(startPtr != NULL)
	{
		cout << startPtr->info << "-->";
		startPtr = startPtr->siguiente;
	}
	cout << "NULL" << endl;
}

void insertar(NodoListaPtr * startPtr, int valor){
	NodoListaPtr nuevo;
	NodoListaPtr actual;
	NodoListaPtr anterior;
	
	nuevo = new NodoLista;
	
	if(nuevo != NULL)
	{
		nuevo->info = valor;
		nuevo->siguiente = NULL;
		
		anterior = NULL;
		actual = *startPtr;
		
		while(actual != NULL)
		{
			anterior = actual;
			actual = actual->siguiente;
		}
		
		if(anterior == NULL)
		{
			nuevo->siguiente = actual;
			*startPtr = nuevo;
		}else
		{
			nuevo->siguiente = actual;
			anterior->siguiente = nuevo;
		}
	}
	else{
		cout << "sin memoria" << endl;
	}
}
