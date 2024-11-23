#include <iostream>
using namespace std;

struct NodoLista
{
		unsigned info;
		struct NodoLista * siguiente;
};

typedef NodoLista * NodoListaPtr;


void insertar(NodoListaPtr * startPtr, unsigned valor);
void mostrar_lista(NodoListaPtr startPtr);
void actualizar_lista(NodoListaPtr * startPtr);

int main(int argc, char *argv[]) {

	NodoListaPtr startPtr = NULL;
	
	insertar(&startPtr,4);
	insertar(&startPtr,5);
	insertar(&startPtr,6);
	insertar(&startPtr,3);
	insertar(&startPtr,2);
	insertar(&startPtr,1);
	insertar(&startPtr,7);
	insertar(&startPtr,9);
	insertar(&startPtr,78);
	insertar(&startPtr,45);
	insertar(&startPtr,45);
	insertar(&startPtr,34);
	insertar(&startPtr,96);
	insertar(&startPtr,98);
	insertar(&startPtr,57);
	
	
	mostrar_lista(startPtr);
	actualizar_lista(&startPtr);
	cout << "LISTA ACTUALIZADA " << endl;
	mostrar_lista(startPtr);
	
	return 0;
}

void actualizar_lista(NodoListaPtr * startPtr)
{
	
	if(*startPtr != NULL){
	
	bool ordenado;

	NodoListaPtr actual;
	NodoListaPtr anterior;
	NodoListaPtr temp;
	
	anterior = *startPtr;
	actual = (*startPtr)->siguiente;
	
	while(actual != NULL)
	{
		
		ordenado = true;
		
		while(ordenado && actual != NULL)
		{
			if(actual->info < anterior->info)
			{
				ordenado = false;
			}
			else
			{
				anterior = actual;
				actual = actual->siguiente;
			}
		}
		
		if(!ordenado)
		{
			temp = actual;
			anterior->siguiente = actual->siguiente;
			actual = actual->siguiente;
			delete temp;
		}
		
	}
	
	}
	else {cout << "LISTA VACIA." << endl;}
	
}


void mostrar_lista(NodoListaPtr startPtr)
{
	while(startPtr!=NULL)
	{
		cout << startPtr->info << "-->";
		startPtr = startPtr->siguiente;
	}
	cout << "NULL" << endl;
}

void insertar(NodoListaPtr * startPtr, unsigned valor)
{
	NodoListaPtr nuevo;
	NodoListaPtr actual;
	NodoListaPtr anterior;
	
	nuevo = new NodoLista;
	if(nuevo == NULL) { cout << "NO HAY MEMORIA DISPONIBLE " << endl; }
	else 
	{
			nuevo->info = valor;
			nuevo->siguiente = NULL;
			
			actual = *startPtr;
			anterior = NULL;
			
			while(actual != NULL)
			{
				anterior = actual;
				actual = actual->siguiente;
			}
			
			//una vez que actual es nulo...
			if(anterior == NULL)
					*startPtr = nuevo;
			else{
				actual = nuevo;
				anterior->siguiente = actual;
			}
				
			
	}
}
