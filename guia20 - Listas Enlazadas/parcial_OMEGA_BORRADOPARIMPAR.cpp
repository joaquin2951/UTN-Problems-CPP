#include <iostream>
using namespace std;

struct NodoLista
	{
	int info;
	struct NodoLista * sig;
};

typedef NodoLista * NodoListaPtr;


void imprimirLista(NodoListaPtr startPtr);
NodoListaPtr maximoLista(NodoListaPtr actual);
NodoListaPtr minimoLista(NodoListaPtr actual);
void insertarF(NodoListaPtr & L, int valor);
bool imparYDiv3(int valor);
void parcial3(NodoListaPtr * L);
void intercambio(int * a, int * b);
int main(int argc, char *argv[]) {
	NodoListaPtr L = NULL;
	
	int num;
	
	while(cin>>num)
	{
		insertarF(L,num);
	}
	
	//imprimirLista(L);
	
	parcial3(&L);
	
	imprimirLista(L);
	
	
	return 0;
}

NodoListaPtr maximoLista(NodoListaPtr actual)
{
	int mayor = actual->info;
	NodoListaPtr mayorPtr = actual;
	actual = actual->sig;
	
	while(actual!=NULL)
	{
		if(actual->info > mayor)
		{
			mayor = actual->info;
			mayorPtr = actual;
		}
		actual=actual->sig;
	}
	
	return mayorPtr;	
}


NodoListaPtr minimoLista(NodoListaPtr actual){
	int menor = actual->info;
	NodoListaPtr menorPtr = actual;
	actual = actual->sig;
	
	while(actual!=NULL)
	{
		if(actual->info < menor)
		{
			menor = actual->info;
			menorPtr = actual;
		}
		actual=actual->sig;
	}
	

	return menorPtr;
}

void imprimirLista(NodoListaPtr startPtr)
{
	if(startPtr == NULL)
		cout << "NULL" << endl;
	else{
		cout << startPtr->info << "-->";
		imprimirLista(startPtr->sig);
	}
	
}

bool imparYDiv3(int valor)
{
	return (valor % 2 != 0 and valor % 3 == 0);
}

void insertarF(NodoListaPtr & L, int valor)
{
	if(L == NULL)
	{
		
		NodoListaPtr nuevo;
		nuevo = new NodoLista;
		
		if(nuevo == NULL) cout << "no memoria" << endl;
		else{
			nuevo->info = valor;
			nuevo->sig = NULL;
			L = nuevo;
		}
		
	}
	else insertarF(L->sig, valor);
}

void intercambio(int * a, int * b)
{
	int aux;
	aux = *a;
	*a = *b;
	*b = aux;
}

void parcial3(NodoListaPtr * L)
{
	
	if(*L != NULL && (*L)->sig != NULL)
	{
		
		NodoListaPtr actual;
		NodoListaPtr anterior;
		NodoListaPtr temp;
		actual = (*L)->sig;
		anterior = *L;
		
		while(actual != NULL)
		{
			if(imparYDiv3(anterior->info) and actual->info % 2 == 0)
			{
				temp = actual;
				actual = actual->sig;
				anterior->sig = actual;
				
				delete temp;
			}
			
			anterior = actual;
			actual = actual->sig;
		}
		
		//cout << maximoLista(*L)->info << endl;;
		//cout << minimoLista(*L)->info<<endl;
		
		actual = *L;
		NodoListaPtr menor = minimoLista(actual);
		NodoListaPtr mayor = maximoLista(actual);
		
		cout << mayor->info - menor->info << endl;
		
		intercambio(&menor->info,&mayor->info);
		
	}
	

}
