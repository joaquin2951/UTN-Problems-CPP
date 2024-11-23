#include <iostream>
using namespace std;


//DE FORMA NORMAL Y DE FORMA RECURSIVA
struct NodoLista
{
	char info;
	struct NodoLista * siguiente;
};


typedef NodoLista * NodoListaPtr;


void insertar_rec(NodoListaPtr * startPtr, char valor);
void imprimir_rec(NodoListaPtr startPtr);
void liberarLista_recursivamente(NodoListaPtr * startPtr);
void liberarLista_iterativamente(NodoListaPtr * startPtr);
void eliminarPrimero(NodoListaPtr * startPtr);

int main(int argc, char *argv[]) {
	
	NodoListaPtr lista = NULL;
	
	insertar_rec(&lista,'a');
	insertar_rec(&lista,'b');
	insertar_rec(&lista,'c');
	
	imprimir_rec(lista);
	
	liberarLista_recursivamente(&lista);
	
	imprimir_rec(lista);
	
	cout << endl << "--------------------------------" << endl << endl;
	
	insertar_rec(&lista,'x');
	insertar_rec(&lista,'e');
	insertar_rec(&lista,'f');
	
	imprimir_rec(lista);
	
	liberarLista_iterativamente(&lista);
	
	imprimir_rec(lista);
	
	return 0;
}


void liberarLista_iterativamente(NodoListaPtr * startPtr)
{
	
	if(*startPtr == NULL)
		cout << "LISTA VACIA" << endl;
	else{
			while(*startPtr != NULL)
				eliminarPrimero(startPtr);
			cout << "Lista Liberada." << endl;
	}
	
	
}

void liberarLista_recursivamente(NodoListaPtr * startPtr)
{
	if(*startPtr == NULL)
		cout << "Lista Liberada." << endl;
	else
	{
		eliminarPrimero(& (*startPtr) ); // &(*startPtr) = &*startPtr = startPtr
		liberarLista_recursivamente(startPtr); //  &*startPtr = startPtr
	}
}

void eliminarPrimero(NodoListaPtr * startPtr)
{
	NodoListaPtr temp;
	temp = *startPtr;
	*startPtr = (*startPtr)->siguiente;
	delete temp;
}


void insertar_rec(NodoListaPtr * startPtr, char valor)
{
	if(*startPtr == NULL)
	{
		NodoListaPtr nuevo;
		if( (nuevo = new NodoLista) == NULL)
			cout << "NO HAY MEMORIA" << endl;
		else
		{
			nuevo->info = valor;
			nuevo->siguiente = NULL;
			*startPtr = nuevo;
		}
	}
	else insertar_rec(  &    (*startPtr)->siguiente  ,valor);
}

void imprimir_rec(NodoListaPtr startPtr)
{
	if(startPtr == NULL)
		cout << "NULL" << endl;
	else
	{
		cout << startPtr->info << "-->";
		imprimir_rec(startPtr->siguiente);
	}
}
