#include <iostream>
using namespace std;

struct NodoLista
{
  int info;
	struct NodoLista * siguiente;
};

typedef NodoLista * NodoListaPtr;

void insertar_desordenado(NodoListaPtr * startPtr,int dato);
void imprimir_lista(NodoListaPtr startPtr);

int main(int argc, char *argv[]) {
	
	NodoListaPtr startPtr = NULL;
	
	int iteraciones; 
	int dato;
	
	cout << "i?"; cin >> iteraciones;
	
	for(int i = 0; i < iteraciones; i++)
	{
		cout << "dato? "; cin >> dato;
		insertar_desordenado(&startPtr,dato);
	}
	
	
	imprimir_lista(startPtr);
	
	
	

	return 0;
}

void insertar_desordenado(NodoListaPtr * startPtr,int dato)
{
	NodoListaPtr actual;
	NodoListaPtr nuevo;
	NodoListaPtr anterior;
	
	nuevo = new NodoLista;
	
	if(nuevo != NULL)
	{
		nuevo->info = dato;
		nuevo->siguiente = NULL;
		
		actual = *startPtr;
		anterior = NULL;
		
		while(actual != NULL)
		{
			anterior = actual;
			actual = actual -> siguiente;
		}
		
		if(anterior == NULL)
		{
			*startPtr = nuevo;
		}
		else
		{
			anterior->siguiente = nuevo;
		}
		
		
	}
	else
		cout << "NO HAY MEMORIA PARA UN NUEVO NODO." << endl;
}

void imprimir_lista(NodoListaPtr startPtr)
{
	if(startPtr == NULL)
		cout << "LISTA VACIA" << endl;
	else{
		while(startPtr != NULL)
		{
			cout << startPtr->info << "-->";
			startPtr = startPtr->siguiente;
		}
		cout << "NULL" << endl;
	}
}
