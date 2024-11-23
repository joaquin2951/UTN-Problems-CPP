#include <iostream>
using namespace std;

struct NodoLista
{
	char info;
	struct NodoLista * siguiente;
};

typedef NodoLista * NodoListaPtr;


void insertar(NodoListaPtr & startPtr, char valor);
void mostrarLista(NodoListaPtr startPtr);

int main(int argc, char *argv[]) {
	
	NodoListaPtr startPtr = NULL;
	
	int iteraciones; 
	char dato;
	
	cout << "i?"; cin >> iteraciones;
	
	for(int i = 0; i < iteraciones; i++)
	{
		cout << "dato? "; cin >> dato;
		insertar(startPtr,dato);
	}
	
	mostrarLista(startPtr);
	
	mostrarLista(startPtr);
	
	mostrarLista(startPtr);
	
	return 0;
}


void mostrarLista(NodoListaPtr startPtr)
{
	if(startPtr == NULL)
		cout << "LISTA VACIA" << endl;
	else
		while(startPtr != NULL)
	{
		cout << startPtr->info << "-->";
		startPtr = startPtr->siguiente;
	}
		cout << "NULL" << endl;
}

void insertar(NodoListaPtr & startPtr, char valor)
{
	NodoListaPtr actual;
	NodoListaPtr anterior;
	NodoListaPtr nuevo;
	
	nuevo = new NodoLista;
	
	if(nuevo == NULL)
	{
		cout << "NO SE PUDO CREAR EL NUEVO NODO. NO HAY MEMORIA." << endl;
	}
	else
	{
		nuevo->info = valor;
		nuevo->siguiente = NULL;
		
		actual = startPtr;
		anterior = NULL;
		
		while(actual != NULL && valor > actual->info)
		{
			anterior = actual;
			actual = actual->siguiente;
		}
		
		if(anterior == NULL)
		{
			nuevo->siguiente = startPtr;
			startPtr = nuevo;
		}
		else
		{
			anterior->siguiente = nuevo;
			nuevo->siguiente = actual;
		}
		
	}
	
}
