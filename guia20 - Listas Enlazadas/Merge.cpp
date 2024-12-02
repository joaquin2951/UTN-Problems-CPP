#include <iostream>
using namespace std;

struct NodoLista
{
		int info;
		struct NodoLista * sig;
};

typedef NodoLista * NodoListaPtr;

void verLista(NodoListaPtr startPtr);
void insertarF(NodoListaPtr & startPtr, int valor);
NodoListaPtr merge(NodoListaPtr L1, NodoListaPtr L2);
bool estaEnLista(NodoListaPtr L3, int valor);

int main(int argc, char *argv[]) {
	
	NodoListaPtr L1 = NULL, L2 = NULL, L3 = NULL;
	
	insertarF(L1,9);
	insertarF(L1,8);
	insertarF(L1,5);
	insertarF(L1,4);
	
	insertarF(L2,39);
	insertarF(L2,34);
	insertarF(L2,21);
	insertarF(L2,20);
	insertarF(L2,1);
	insertarF(L2,1);
	insertarF(L2,1);
	
	verLista(L1);
	verLista(L2);
	
	L3 = merge(L1,L2);
	verLista(L3);
	
	
	return 0;
}

bool estaEnLista(NodoListaPtr L3, int valor)
{
	while(L3 != NULL)
	{
		if(L3->info == valor)
			return true;
		else
			L3 = L3->sig;
	}
	
	return false;
}


NodoListaPtr merge(NodoListaPtr L1, NodoListaPtr L2)
{
	NodoListaPtr start = NULL;

	
	while(L1 != NULL && L2 != NULL)
	{
		if(L1->info > L2->info)
		{
		//	if(!estaEnLista(start,L1->info)) //para UNION
				insertarF(start,L1->info);
			L1 = L1->sig;
		}
		else
		{
		//	if(!estaEnLista(start,L2->info))// para UNION
				insertarF(start,L2->info);
			L2 = L2->sig;
		}
	}
	
	
	while(L1 != NULL)
	{
		//if(!estaEnLista(start,L1->info)) //para UNION
		insertarF(start,L1->info);
		L1 = L1->sig;
	}
	
	while(L2 != NULL)
	{
	//if(!estaEnLista(start,L2->info)) //para UNION
		insertarF(start,L2->info);
		L2 = L2->sig;
	}
	
	return start;
}


void insertarF(NodoListaPtr & startPtr, int valor)
{
	if(startPtr == NULL)
	{
		NodoListaPtr nuevo;
		if( (nuevo = new NodoLista) == NULL ) cout << "NO MEMORY" << endl;
		else
		{
			nuevo->info = valor;
			nuevo->sig = NULL;
			startPtr = nuevo;
		}
	}
	else insertarF(startPtr->sig, valor);
}

void verLista(NodoListaPtr startPtr)
{
	if(startPtr == NULL)
		cout << "NULL" << endl;
	else
		{
		cout << startPtr->info << " --> ";
		verLista(startPtr->sig);
	}
}



