#include <iostream>
using namespace std;

struct NodoLista
{
		int info;
		struct NodoLista * siguiente;
};

typedef NodoLista * NodoListaPtr;


void insertar_ord(NodoListaPtr * startPtr, int valor);
void merge(NodoListaPtr lista1, NodoListaPtr lista2, NodoListaPtr * lista3);
void imprimir(NodoListaPtr startPtr);
void borrar(NodoListaPtr * startPtr, int valor);
void insertar_rec(NodoListaPtr * startPtr, int valor);

int main(int argc, char *argv[]) {
	
  NodoListaPtr lista1 = NULL;
	NodoListaPtr lista2 = NULL;
	NodoListaPtr lista3 = NULL;
	
	insertar_ord(&lista1,1);
	insertar_ord(&lista1,200);
	insertar_ord(&lista1,0);
	insertar_ord(&lista1,4);
	insertar_ord(&lista1,4);
	insertar_ord(&lista1,7);
	
	insertar_ord(&lista2,9);
	insertar_ord(&lista2,3);
	insertar_ord(&lista2,200);
	insertar_ord(&lista2,-1);
	insertar_ord(&lista2,77);
	insertar_ord(&lista2,39);
	
	
	cout << "LISTA 1" << endl;
	imprimir(lista1);
	cout << "LISTA 2" << endl;
	imprimir(lista2);
	
	merge(lista1,lista2,&lista3);
	cout << "LISTA 3" << endl;
	imprimir(lista3);
	
	
	return 0;
}

void merge(NodoListaPtr lista1, NodoListaPtr lista2, NodoListaPtr * lista3)
{

	
	while(lista1 != NULL && lista2 != NULL)
	{
		if(lista1->info < lista2->info)
		{
			insertar_rec(&*lista3,lista1->info);
			lista1 = lista1->siguiente;
		}
		else{
			insertar_rec(&*lista3,lista2->info);
			lista2 = lista2->siguiente;
		}
	}
	
	
	while(lista1 != NULL)
	{
		insertar_rec(&*lista3,lista1->info);
		lista1 = lista1->siguiente;
	}
	
	while(lista2 != NULL)
	{
		insertar_rec(&*lista3,lista2->info);
		lista2 = lista2->siguiente;
	}
	
}

void insertar_rec(NodoListaPtr * startPtr, int valor)
{
	if(*startPtr == NULL)
	{
		NodoListaPtr nuevo;
		nuevo = new NodoLista;
		if(nuevo == NULL) cout << "NO HAY MEMORIA" << endl;
		else
		{
			nuevo->info = valor;
			nuevo->siguiente = NULL;
			*startPtr = nuevo;
		}
	}
	else insertar_rec(&((*startPtr)->siguiente),valor);
}

void imprimir(NodoListaPtr startPtr)
{
	if(startPtr == NULL)
		cout << "LISTA VACIA" << endl;
	else{
		while(startPtr!= NULL)
		{
			cout << startPtr->info << "-->";
			startPtr = startPtr->siguiente;
		}
		cout << "NULL" << endl;
	}
}

void insertar_ord(NodoListaPtr * startPtr, int valor)
{
	NodoListaPtr nuevo;
	NodoListaPtr anterior;
	NodoListaPtr actual;
	
	nuevo = new NodoLista;
	
	if(nuevo != NULL)
	{
		nuevo->info = valor;
		nuevo->siguiente = NULL;
		
		anterior = NULL;
		actual = *startPtr;
		
		while(actual != NULL && actual->info < valor)
		{
			anterior = actual;
			actual = actual->siguiente;
		}
		
		
		if(anterior == NULL)
		{
			nuevo->siguiente = *startPtr;
			*startPtr = nuevo;
		}
		else
		{
			nuevo->siguiente = actual;
			anterior->siguiente = nuevo;
		}
	}
	else
		 cout << "NO HAY MEMORIA DISP." << endl;
	
}
