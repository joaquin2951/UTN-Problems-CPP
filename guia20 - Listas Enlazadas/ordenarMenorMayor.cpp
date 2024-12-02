#include <iostream>
using namespace std;


struct NodoLista
{
		char info;
		struct NodoLista * sig;
};

typedef NodoLista  * NodoListaPtr;


void imprimirLista(NodoListaPtr actual);
void ordenarLista(NodoListaPtr L);
void intercambiar(char * a, char * b);
void insertarFinal(NodoListaPtr * L, char valor);
NodoListaPtr menorLista(NodoListaPtr L);



int main(int argc, char *argv[]) {
	
	NodoListaPtr Lista = NULL;
	
	insertarFinal(&Lista,'x');
	insertarFinal(&Lista,'f');
	insertarFinal(&Lista,'s');
	insertarFinal(&Lista,'z');
	insertarFinal(&Lista,'a');
	insertarFinal(&Lista,'f');
	insertarFinal(&Lista,'c');
	insertarFinal(&Lista,'c');
	insertarFinal(&Lista,'y');
	insertarFinal(&Lista,'t');
	insertarFinal(&Lista,'o');
	insertarFinal(&Lista,'d');
	insertarFinal(&Lista,'s');
	
	imprimirLista(Lista);
	
	ordenarLista(Lista);
	
	imprimirLista(Lista);
	
	return 0;
}

void imprimirLista(NodoListaPtr actual)
{
	if(actual == NULL)
		cout << "NULL" << endl;
	else{
		cout << actual->info << "-->";
		imprimirLista(actual->sig);
	}
}

void ordenarLista(NodoListaPtr L)
{
	if(L == NULL || L->sig == NULL)
		return;
	else
	{
		NodoListaPtr aux = menorLista(L->sig);
		if(L->info > aux->info)
			intercambiar(&L->info, &aux->info);
		
		ordenarLista(L->sig);
	}
}

void intercambiar(char * a, char * b)
{
	char aux;
	aux = *a;
	*a = *b;
	*b = aux;
}

void insertarFinal(NodoListaPtr * L, char valor)
{
	if(*L != NULL)
		insertarFinal( &(*L)->sig,valor );
	else
	{
			NodoListaPtr nuevo;
			if( (nuevo = new NodoLista) == NULL ) cout << "NO MEMORY" << endl;
			else
			{
				nuevo->info = valor;
				nuevo->sig = NULL;
				*L = nuevo;
			}
	}
}

NodoListaPtr menorLista(NodoListaPtr L)
{
	if(L == NULL || L->sig == NULL)
		return L;
	else
	{
		char menor = L->info;
		NodoListaPtr menorPtr = L;
		L = L->sig;
		
		while(L != NULL)
		{
			if(L->info < menor)
			{
				menor = L->info;
				menorPtr = L;
			}
			L = L->sig;
		}
		
		return menorPtr;
	}
}
