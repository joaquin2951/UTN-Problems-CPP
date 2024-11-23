#include <iostream>
using namespace std;

struct NodoLista{
	int info;
	struct NodoLista * siguiente;
};

typedef NodoLista * NodoListaPtr;



void mostrar_lista(NodoListaPtr startPtr);
void insertar_rec(NodoListaPtr * startPtr, int elemento);
bool eliminar(NodoListaPtr * startPtr, int elemento);
bool estaEnLista(NodoListaPtr startPtr, int elementoBuscado);

int main(int argc, char *argv[]) {

	NodoListaPtr startPtr = NULL;
	NodoListaPtr startPtr2 = NULL;
	NodoListaPtr startPtr3 = NULL;
	
	insertar_rec(&startPtr,2);
	insertar_rec(&startPtr,1);
	insertar_rec(&startPtr,7);
	
	insertar_rec(&startPtr2,7);
	insertar_rec(&startPtr2,9);
	insertar_rec(&startPtr2,19);
	insertar_rec(&startPtr2,1);
	insertar_rec(&startPtr2,5);
	
	
	mostrar_lista(startPtr);
	mostrar_lista(startPtr2);
	
	
	NodoListaPtr aux;
	aux = startPtr;
	while(aux != NULL)
	{
		if(!estaEnLista(startPtr3,aux->info))
			insertar_rec(&startPtr3,aux->info);
		
		aux = aux->siguiente;
	}
	
	aux = startPtr2;
	while(aux != NULL)
	{
		if(!estaEnLista(startPtr3,aux->info))
			insertar_rec(&startPtr3,aux->info);
		
		aux = aux->siguiente;
	}
	
	mostrar_lista(startPtr3);
	
	cout << "AÑADO NUEVOS ELEMENTOS: " << endl;
	insertar_rec(&startPtr3,10);
	insertar_rec(&startPtr3,77);
	insertar_rec(&startPtr3,23);
	insertar_rec(&startPtr3,77);
	insertar_rec(&startPtr3,98);
	insertar_rec(&startPtr3,104);
	insertar_rec(&startPtr3,77);
	insertar_rec(&startPtr3,123);
	insertar_rec(&startPtr3,99);
	insertar_rec(&startPtr3,77);	
	insertar_rec(&startPtr3,-1000);
	
	mostrar_lista(startPtr3);
	
	
	//eliminar numero en todas sus aparicioens
	int numero_a_eliminar = 77;
	int apariciones = 0;
	
	/*
	while(estaEnLista(startPtr3,numero_a_eliminar))
	{
		eliminar(&startPtr3,numero_a_eliminar);
	}
	*/
	
	while(eliminar(&startPtr3,numero_a_eliminar))
	{
		apariciones++;
	}
	
	cout << "numero de apariciones del numero eliminado: " << apariciones << endl;
	
	mostrar_lista(startPtr3);
	
	return 0;
}


bool eliminar(NodoListaPtr * startPtr, int elemento)
{

	NodoListaPtr actual;
	NodoListaPtr anterior;
	NodoListaPtr temp;
	
	bool eliminado;
		
		if( (*startPtr)->info == elemento)
		{
			temp = *startPtr;
			*startPtr = (*startPtr)->siguiente;
			delete temp;
			eliminado = true;
		}
		else{
		anterior = NULL;
		actual = *startPtr;
		
		while(actual != NULL && actual->info != elemento)
		{
			anterior = actual;
			actual = actual->siguiente;
		}
		
		
		if(anterior == NULL)
			eliminado = false;
		else if(actual == NULL)
			eliminado = false;
		else 
		{
			temp = actual;
			anterior->siguiente = actual->siguiente;
			delete temp;
			eliminado = true;
		}
		}
		
		
	return eliminado;
}


bool estaEnLista(NodoListaPtr startPtr, int elementoBuscado)
{
	bool esta = false;
	
	while(!esta && startPtr != NULL)
	{
		if(startPtr->info == elementoBuscado)
			esta = true;
		else
			startPtr = startPtr->siguiente;
	}
	
	return esta;
}

void insertar_rec(NodoListaPtr * startPtr, int elemento)
{
		if(*startPtr == NULL)
		{
			NodoListaPtr nuevoNodo;
			nuevoNodo = new NodoLista;
			if(nuevoNodo==NULL) cout << "NO HAY MAS MEMORIA" << endl;
			else{
				nuevoNodo->info = elemento;
				nuevoNodo->siguiente = NULL;
				*startPtr = nuevoNodo;
			}
			
		}
		else
		{
			insertar_rec( &(*startPtr)->siguiente, elemento);
		}
}

void mostrar_lista(NodoListaPtr startPtr)
{
	while(startPtr!=NULL)
	{
		cout << startPtr->info << "-->";
		startPtr=startPtr->siguiente;
	}
	cout << "NULL" << endl;
}
