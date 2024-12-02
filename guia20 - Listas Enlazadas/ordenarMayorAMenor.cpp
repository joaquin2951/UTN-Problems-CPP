#include <iostream>
using namespace std;

struct NodoLista
{
		int info;
		struct NodoLista * sig;
};

typedef NodoLista * NodoListaPtr;

void ordenarMayorAMenor(NodoListaPtr L);
NodoListaPtr MayorElemento(NodoListaPtr L);
void intercambiar(int * a, int * b);


void insertar_ordenado(NodoListaPtr * L, int valor);
void print_lista(NodoListaPtr actual);

int main(int argc, char *argv[]) {
	
	NodoListaPtr Lista = NULL;
	
	insertar_ordenado(&Lista,3);
	insertar_ordenado(&Lista,7);
	insertar_ordenado(&Lista,1);
	insertar_ordenado(&Lista,0);
	insertar_ordenado(&Lista,4);
	insertar_ordenado(&Lista,9);
	insertar_ordenado(&Lista,7);
	
	print_lista(Lista);
	
	ordenarMayorAMenor(Lista);
	
	print_lista(Lista);
	
	
	return 0;
}

void print_lista(NodoListaPtr actual)
{
	if(actual == NULL)
		cout << "NULL" << endl;
	else
	{
		cout << actual->info << "-->";
		print_lista(actual->sig);
	}
}


void insertar_ordenado(NodoListaPtr * L, int valor)
{
	NodoListaPtr actual;
	NodoListaPtr anterior;
	NodoListaPtr nuevo;
	
	if( (nuevo = new NodoLista) == NULL) cout << "NO MEMORY" << endl;
	else{
		nuevo->info = valor;
		nuevo->sig = NULL;
		
		anterior = NULL;
		actual = *L;
		
		
		while(actual != NULL && actual->info < valor)
		{
			anterior = actual;
			actual = actual->sig;
		}
		
		if(anterior == NULL)
		{
				nuevo->sig = *L;
				*L = nuevo;
		}
		else
		{
			
			nuevo->sig = actual;
			anterior->sig = nuevo;
			
		}
	}
	
	
}

void ordenarMayorAMenor(NodoListaPtr L)
{
	if(L == NULL || L->sig == NULL)
		return;
	else
	{
		NodoListaPtr mayor = MayorElemento(L->sig);
		if(L->info < mayor->info)
			intercambiar(&(L->info),&(mayor->info));
		
	
			ordenarMayorAMenor(L->sig);
	}
	
	
}

void intercambiar(int * a, int * b)
{
	int aux;
	aux = *a;
	*a = *b;
	*b = aux;
}

NodoListaPtr MayorElemento(NodoListaPtr L){
	
	
	if(L == NULL)
		return NULL;
	else if(L->sig == NULL)
		return L;
	else
	{
		int mayor =	L->info;
		NodoListaPtr mayorPtr = L;
		L = L->sig;
		
		while(L != NULL)
		{
			if(L->info > mayor)
			{
				mayor = L->info;
				mayorPtr = L;
			}
			L = L->sig;
		}
		
		return mayorPtr;
	}
	
}
