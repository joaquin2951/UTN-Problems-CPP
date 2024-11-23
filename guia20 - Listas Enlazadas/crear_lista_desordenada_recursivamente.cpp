#include <iostream>
using namespace std;

struct NodoLista
{
	int info;
	struct NodoLista * siguiente;
};

typedef NodoLista * NodoListaPtr;


void insertar_desordenado_rec(NodoListaPtr * startPtr, int dato);
void mostrarLista(NodoListaPtr startPtr);
bool borrar_elemento(NodoListaPtr * startPtr, int dato);

int main(int argc, char *argv[]) {
	
	NodoListaPtr startPtr = NULL;
	
	
	int iteraciones; 
	int dato;
	
	cout << "i?"; cin >> iteraciones;
	
	for(int i = 0; i < iteraciones; i++)
	{
		cout << "dato? "; cin >> dato;
		insertar_desordenado_rec(&startPtr,dato);
	}
	
	mostrarLista(startPtr);

	
	while(borrar_elemento(&startPtr,4)){
		mostrarLista(startPtr);
	}
	
	
	
	return 0;
}


bool borrar_elemento(NodoListaPtr * startPtr, int dato)
{
	
	NodoListaPtr anterior;
	NodoListaPtr actual;

	actual = *startPtr;
	
	if(actual == NULL)
	{
		return 0;
	}
	else
	{
			while(actual != NULL && actual->info != dato)
			{
				anterior = actual;
				actual = actual->siguiente;
			}
			
			if(actual == NULL)
						return 0;
			else{
				anterior->siguiente = actual->siguiente;
				delete actual;
				return 1;
			}
	}
	
}


void insertar_desordenado_rec(NodoListaPtr * startPtr, int dato)
{

		if(*startPtr == NULL){
			
			NodoListaPtr nuevo;
			nuevo = new NodoLista;
			
			if(nuevo != NULL)
			{
				nuevo->info = dato;
				nuevo->siguiente = NULL;
				*startPtr = nuevo;
			}
			else
			{
				cout << "No hay memoria disponible" << endl;	
			}
			
			
		}
		else{
			insertar_desordenado_rec(&((*startPtr)->siguiente),dato);
		}

}

void mostrarLista(NodoListaPtr startPtr)
{
	if(startPtr == NULL)
		cout << "LISTA VACIA" << endl;
	else{
		while(startPtr!=NULL)
		{
			cout << startPtr->info << "->";
			startPtr = startPtr->siguiente;
		}
		cout << "NULL" << endl;
	}
}
