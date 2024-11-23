#include <iostream>
using namespace std;

struct Calificaciones
{
		int ID;
		float vec[6];
};

struct NodoLista
{
  Calificaciones info;
	struct NodoLista * siguiente;
};


struct NodoListaIntegrada
{
		int ID;
		float prom;
		struct NodoListaIntegrada * siguiente;
};

typedef NodoLista * NodoListaPtr;
typedef NodoListaIntegrada * NodoListaIntegradaPtr;

void insertar_ordenado(NodoListaPtr * startPtr, Calificaciones valor);
void insertar_ordenado_Lintegrada(NodoListaIntegradaPtr * startPtr, float prom, int ID);
void imprimir_ID(NodoListaPtr startPtr);
void combinarListas(NodoListaIntegradaPtr * startPtr, NodoListaPtr lista);
void ver_listaIntegrada(NodoListaIntegradaPtr startPtr);
float promedio(float vec[6]);
void generarListaIntegrada(NodoListaIntegradaPtr * listaIntegrada, NodoListaPtr lista1, NodoListaPtr lista2);

int main(int argc, char *argv[]) {
	
	NodoListaPtr lista1 = NULL;
	NodoListaPtr lista2 = NULL;
	NodoListaIntegradaPtr listaIntegrada = NULL;
	
	
	insertar_ordenado(&lista1,{9,{1,4,6.0,5,3.0,2}});
	insertar_ordenado(&lista1,{4,{10.0,4.0,6.7,7.7,8.0,9.0}});
	insertar_ordenado(&lista1,{7,{1.0,4.5,3.0,5.3,4.8,2.2}});
	
	insertar_ordenado(&lista2,{10,{1.9,7.6,4.4,7.3,4.2,1.4}});
	insertar_ordenado(&lista2,{3,{9.0,2.5,3.9,3.5,7.6,9.9}});
	insertar_ordenado(&lista2,{1,{9.0,4.6,1.5,5.8,2.6,10.0}});
	
	
	cout << "LISTA 1: " << endl;
	imprimir_ID(lista1);
	cout << "LISTA 2: " << endl;
	imprimir_ID(lista2);
	
	
	
	generarListaIntegrada(&listaIntegrada,lista1,lista2);

	
	
	//mostar Lista Integrada
	cout << endl << endl << "LISTA INTEGRADA" << endl;
	ver_listaIntegrada(listaIntegrada);
	
	return 0;
}




void ver_listaIntegrada(NodoListaIntegradaPtr startPtr)
{
	while(startPtr != NULL){
		cout << "prom: " << startPtr->prom << "  ID: " << startPtr->ID << " -->";
		startPtr = startPtr->siguiente;
	}
	cout << "NULL" << endl;
}

void combinarListas(NodoListaIntegradaPtr * startPtr, NodoListaPtr lista)
{
	float prom;
	int ID_alumno;
	
	while(lista != NULL)
	{
		prom = promedio(lista->info.vec);
		ID_alumno = lista->info.ID;
		insertar_ordenado_Lintegrada(&(*startPtr),prom,ID_alumno);
		lista = lista->siguiente;
	}
}


void generarListaIntegrada(NodoListaIntegradaPtr * listaIntegrada, NodoListaPtr lista1, NodoListaPtr lista2)
{
	//recorro toda la lista 1
	combinarListas((listaIntegrada),lista1);
	
	//recorro lista 2
	combinarListas((listaIntegrada),lista2);
}

void insertar_ordenado_Lintegrada(NodoListaIntegradaPtr * startPtr, float prom, int ID)
{
	NodoListaIntegradaPtr nuevo;
	NodoListaIntegradaPtr actual;
	NodoListaIntegradaPtr anterior;
	
	nuevo = new NodoListaIntegrada;
	
	if(nuevo != NULL){
		
		nuevo->ID = ID;
		nuevo->prom = prom;
		nuevo->siguiente = NULL;
		
		anterior = NULL;
		actual = *startPtr;
		
		
		while(actual != NULL && actual->prom > prom)
		{
			anterior = actual;
			actual = actual->siguiente;
		}
		
		if(anterior == NULL)
		{
			nuevo->siguiente = actual;
			*startPtr = nuevo;
		}
		else
		{
			nuevo->siguiente = anterior->siguiente;
			anterior->siguiente = nuevo;
		}
		
		
	}
	else
		 cout << "NO HAY MEMORIA" << endl;
	
}

float promedio(float vec[6])
{
	float pm = 0.0;
	
	for(int i = 0; i < 6; i++)
	{
		pm = pm + vec[i];
	}
	
	return (pm / 6.0);
}

void imprimir_ID(NodoListaPtr startPtr)
{
	while(startPtr!=NULL)
	{
		cout << startPtr->info.ID << "-->";
		startPtr = startPtr->siguiente;
	}
	cout << "NULL" << endl;
}

void insertar_ordenado(NodoListaPtr * startPtr, Calificaciones valor)
{
	NodoListaPtr nuevo;
	NodoListaPtr actual;
	NodoListaPtr anterior;
	
	nuevo = new NodoLista;
	
	if(nuevo != NULL)
	{
		
		nuevo->info = valor;
		nuevo->siguiente = NULL;
		
		anterior = NULL;
		actual = *startPtr;
		
		
		while(actual != NULL && (actual->info.ID) < valor.ID)
		{
			anterior = actual;
			actual = actual->siguiente;
		}
		
		
		if(anterior == NULL)
		{
			nuevo->siguiente = actual;
			*startPtr = nuevo;
		}
		else
		{
				nuevo->siguiente = anterior->siguiente;
				anterior->siguiente = nuevo;
		}
		
	}
	else
		 cout << "NO HAY MEMORIA" << endl;
	
}
