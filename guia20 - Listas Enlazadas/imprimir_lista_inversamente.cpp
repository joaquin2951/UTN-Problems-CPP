#include <iostream>
using namespace std;


struct NodoLista
{
  char info;
	struct NodoLista * siguiente;
};



typedef NodoLista * NodoListaPtr;


void imprimir_inverso(NodoListaPtr startPtr);
void insertarFinal_rec(NodoListaPtr & startPtr, char c);


int main(int argc, char *argv[]) {
	
	NodoListaPtr lista = NULL;
	
	insertarFinal_rec(lista, 'x');
	insertarFinal_rec(lista, 'g');
	insertarFinal_rec(lista, 'f');
	insertarFinal_rec(lista, 'y');
	insertarFinal_rec(lista, 'a');
	
	
	imprimir_inverso(lista);
	
	return 0;
}


void imprimir_inverso(NodoListaPtr startPtr)
{
	if(startPtr == NULL)
	{
		cout << "NULL";
	}
	else
	{
		imprimir_inverso(startPtr->siguiente);
		cout << "-->" << startPtr->info;
	}
}
	
void insertarFinal_rec(NodoListaPtr & startPtr, char c){
	if(startPtr == NULL)
	{
		NodoListaPtr nuevo;
		nuevo = new NodoLista;
		if(nuevo != NULL){
			nuevo->info = c;
			nuevo->siguiente = NULL;
			startPtr = nuevo;
		}
		else
			 cout << "NO HAY MEMORIA" << endl;
	}else{
		insertarFinal_rec(startPtr->siguiente,c);
	}
}
