#include <iostream>
using namespace std;

struct Informacion
{
	int num;
	char let;
};

struct NodoLista
{
	Informacion info;
	struct NodoLista * siguiente;
};

typedef NodoLista * NodoListaPtr;



void insertar_ordenado(NodoListaPtr &startPtr, Informacion valor);
void mostar_lista(NodoListaPtr startPtr);
bool estaEnLista(NodoListaPtr startPtr, int valor);



int main(int argc, char *argv[]) {
	
	NodoListaPtr lista1 = NULL;
	NodoListaPtr lista2 = NULL;
	
	insertar_ordenado(lista1,{1,'a'});
	insertar_ordenado(lista1,{7,'z'});
	insertar_ordenado(lista1,{5,'y'});
	insertar_ordenado(lista1,{3,'s'});
	insertar_ordenado(lista1,{10,'c'});
	
	insertar_ordenado(lista2,{300,'z'});
	insertar_ordenado(lista2,{4,'i'});
	insertar_ordenado(lista2,{7,'h'});
	insertar_ordenado(lista2,{9,'c'});
	insertar_ordenado(lista2,{5,'f'});
	insertar_ordenado(lista2,{32,'g'});
	insertar_ordenado(lista2,{1,'j'});
	insertar_ordenado(lista2,{50,'k'});
	insertar_ordenado(lista2,{11,'x'});
	insertar_ordenado(lista2,{43,'t'});
	
	mostar_lista(lista1);
	mostar_lista(lista2);
	
	
	NodoListaPtr aux;
	aux = lista1;
	
	while(aux != NULL)
	{
		if(estaEnLista(lista2,aux->info.num))
		{
			if(aux->info.let == 'z')
				 aux->info.let = 'a';
			else
				 aux->info.let = (char) (aux->info.let + 1);
		}
		
		aux = aux->siguiente;
	}
	
	cout << "NUEVA LISTA 1 " << endl;
	mostar_lista(lista1);
	
	return 0;
}

bool estaEnLista(NodoListaPtr startPtr, int valor){
	bool esta = false;
	while(!esta && startPtr != NULL)
	{
		if(valor == startPtr->info.num)
			esta = true;
		else
			startPtr = startPtr->siguiente;
	}
	
	return esta;
}

void mostar_lista(NodoListaPtr startPtr)
{
	while(startPtr != NULL){
		cout << startPtr->info.num << ":" << startPtr->info.let << " --> ";
		startPtr = startPtr->siguiente;
	}
	cout << "NULL" << endl;
}

void insertar_ordenado(NodoListaPtr &startPtr, Informacion valor)
{
	NodoListaPtr nuevo;
	NodoListaPtr actual;
	NodoListaPtr anterior;
	
	nuevo = new NodoLista;
	
	if(nuevo == NULL) cout << "NO HAY MEMORIA" << endl;
	else{
		
		nuevo->info = valor;
		nuevo->siguiente = NULL;
		
		anterior = NULL;
		actual = startPtr;
		
		while(actual != NULL && actual->info.num < valor.num)
		{
			anterior = actual;
			actual = actual->siguiente;
		}
		
		if(anterior==NULL)
		{
			nuevo->siguiente = actual;
			startPtr = nuevo;
		}
		else
		{
			nuevo->siguiente = anterior->siguiente;
			anterior->siguiente = nuevo;
		}
		
	}
	
}
