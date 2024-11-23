#include <iostream>
using namespace std;

struct NodoLista
{
	int info;
	struct NodoLista * siguiente;
};

typedef NodoLista * NodoListaPtr;


void insertar(NodoListaPtr * startPtr, int valor);
void printLista(NodoListaPtr * startPtr);

int main(int argc, char *argv[]) {
	
	NodoListaPtr startPtr = NULL;//inicializo la lista, la dirección del primer elemento será NULL ya que por ahora no contiene nada.
	
	
	int valor, iteraciones;
	
	cout << "i? "; cin >> iteraciones;
	
	for(int i = 0; i < iteraciones; i++)
	{
		cout << "valor? "; cin >> valor;
		insertar(&startPtr,valor);
	}
	
	printLista(&startPtr);
	
	
	return 0;
}


void insertar(NodoListaPtr * startPtr, int valor)
{
	NodoListaPtr nuevo;//un puntero hacia el nuevo valor ingresado
	NodoListaPtr actual;//un puntero hacia el valor actual 
	NodoListaPtr anterior;//un puntero hacia el valor anterior
	
	nuevo = new NodoLista;//guardo la direccion de la nueva memoria que se generate
	
	if(nuevo != NULL) //si hay espacio disponible
	{
		nuevo->info = valor;
		nuevo->siguiente = NULL;
		
		anterior = NULL;
		actual = *startPtr;
		
		//Buscamos la posicion correcta en la lista, si queremos tenerla ordenada de menor a mayor...
		while(actual != NULL && valor > actual->info)
		{
			anterior = actual;
			actual = actual->siguiente;
		}
		
		//Si no entra al while, significa que actual == NULL en la primera iteracion, por lo tanto anterior se mantiene en NULL
		if(anterior == NULL)//NUNCA ENTRÓ AL while
		{
			nuevo->siguiente = *startPtr;
			*startPtr = nuevo;
		}
		else//ENTRÓ AL WHILE y NO ES EL PRIMER ELEMENTO EN LA LISTA
		{
			anterior->siguiente = nuevo;
			nuevo->siguiente = actual;
		}
	}
	else
	{
		cout << "no hay memoria disponible. No fue insertado el elemento." << endl;
	}
	
	
}


void printLista(NodoListaPtr * startPtr)
{
	NodoListaPtr actual;
	
	actual = *startPtr;
	
	if(actual == NULL)
		cout << "LISTA VACIA" << endl;
	else{
		
		while(actual != NULL)
		{
			cout << actual->info << "-->";
			actual = actual->siguiente;
		}
		cout << "NULL" << endl;
	}
}
