#include <iostream>
using namespace std;

struct Coordenadas
{
		float X;
		float Y;
};

struct Ciudad
{
		string nombre;
		Coordenadas coordenadas;
		int num_reg;//se asigna aleatoriamente
};

struct NodoLista
{
	Ciudad info;
	struct NodoLista * siguiente;
};

typedef NodoLista * NodoListaPtr;


void insertar_rec(NodoListaPtr & startPtr, Ciudad c);
void mostrar_lista(NodoListaPtr startPtr);
void nombre_numRegbajo(NodoListaPtr startPtr);
bool ordenadaAlfabeticamente(NodoListaPtr startPtr);
void eliminar_ordNegativa(NodoListaPtr * startPtr);

int main(int argc, char *argv[]) {
	
	NodoListaPtr startPtr = NULL;
	Ciudad ciudad;
	
	
	ciudad.nombre = "Buenos Aires"; ciudad.coordenadas.X = -3.3; ciudad.coordenadas.Y = -5.34; ciudad.num_reg = 1; 
	insertar_rec(startPtr,ciudad);
	
	ciudad.nombre = "Cordoba"; ciudad.coordenadas.X = 0.0; ciudad.coordenadas.Y = -0.01; ciudad.num_reg = 4; 
	insertar_rec(startPtr,ciudad);
	
	
	ciudad.nombre = "Salta"; ciudad.coordenadas.X = 1.0; ciudad.coordenadas.Y = -13.5; ciudad.num_reg = 8; 
	insertar_rec(startPtr,ciudad);
	
	ciudad.nombre = "Santa Fe"; ciudad.coordenadas.X = 5.3; ciudad.coordenadas.Y = 3.1; ciudad.num_reg = 2; 
	insertar_rec(startPtr,ciudad);
	

	mostrar_lista(startPtr);
	
	cout << endl << endl;
	nombre_numRegbajo(startPtr);
	
	cout << "está ordenada alfabeticamente? " << boolalpha << ordenadaAlfabeticamente(startPtr) << endl;
	
	
	
	cout << "Las ciudades con ordenada (Y) negativa fueron eliminadas" << endl;
	eliminar_ordNegativa(&startPtr);
	mostrar_lista(startPtr);
	
	return 0;
}


void eliminar_ordNegativa(NodoListaPtr * startPtr)
{

	NodoListaPtr temp;
	
	if(*startPtr == NULL) cout << "lista vacia" << endl; //si la lista esta vacia
	else//si hay al menos un elemento
	{
		NodoListaPtr anterior;
		NodoListaPtr actual;
		
		anterior = NULL;
		actual = *startPtr;
		
		while(actual != NULL && (actual->info).coordenadas.Y < 0.0)//mientras el primer elemento tenga coord neg lo borramos
		{
			temp = actual;
			actual = actual->siguiente;
			*startPtr = actual;
			delete temp;
		}
		
		if(actual != NULL){
			anterior = actual;
			actual = actual->siguiente;
		}
		
		while(actual != NULL)
		{
			
			if(actual->info.coordenadas.Y < 0)
			{
					temp = actual;
					anterior->siguiente = actual->siguiente;
					actual = actual->siguiente;
					delete temp;
			}
			else
			{
				anterior = actual;
				actual = actual->siguiente;
			}
			
		}
		
	}

	
}


bool ordenadaAlfabeticamente(NodoListaPtr startPtr)
{
	bool ordenada = true;
	NodoListaPtr anterior = startPtr;
	NodoListaPtr actual = startPtr->siguiente;
	
	while(actual != NULL && ordenada)
	{
		
		if(anterior->info.nombre > actual->info.nombre)
			ordenada = false;
		else{
			anterior = actual;
			actual = actual->siguiente;
		}
		
	}
	
	return ordenada;
}

void nombre_numRegbajo(NodoListaPtr startPtr)
{
	 int menor = startPtr->info.num_reg;
	 string nombre = startPtr->info.nombre;
	 
	 NodoListaPtr actual = startPtr->siguiente;
	 
	 while(actual != NULL)
	 {
		
		 if(actual->info.num_reg < menor)
		 {
			 menor = actual->info.num_reg;
			 nombre = actual->info.nombre;
		 }
		
		 actual = actual->siguiente;
	 }
	 
	 
	 cout << "Ciudad con el numero de registro más bajo: " << nombre << "  con el número: " << menor << endl;
	 
}

void mostrar_lista(NodoListaPtr startPtr)
{
	while(startPtr!=NULL)
	{
		cout << (startPtr->info).nombre << "-->";
		startPtr = startPtr->siguiente;
	}
	cout << "NULL" << endl;
}

void insertar_rec(NodoListaPtr & startPtr, Ciudad c)
{
	if(startPtr == NULL)
	{
		NodoListaPtr nuevo;
		nuevo = new NodoLista;
		
		if(nuevo == NULL)
		{
			cout << "NO HAY ESPACIO" << endl;
		}
		else
		{
			nuevo->info = c;
			nuevo->siguiente = NULL;
			
			startPtr = nuevo;
		}
	}
	else
	{
		insertar_rec(startPtr->siguiente,c);
	}
}
