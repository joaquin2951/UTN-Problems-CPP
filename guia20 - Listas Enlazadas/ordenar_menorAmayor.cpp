#include <iostream>
using namespace std;

struct NodoLista
{
		char info;
		struct NodoLista * sig;
};

typedef NodoLista * NodoListaPtr;


void print_lista(NodoListaPtr actual);
void insert_final(NodoListaPtr * startPtr, char valor);
NodoListaPtr menorLista(NodoListaPtr actual);
NodoListaPtr menorListaRecursivo(NodoListaPtr actual);
void ordenarMenorMayor(NodoListaPtr actual);
void ordenarMenorMayorIterativo(NodoListaPtr actual);
void intercambiar(char * a, char * b);


int main(int argc, char *argv[]) {
		NodoListaPtr lista = NULL;
		NodoListaPtr lista2 = NULL;
		
		
		insert_final(&lista,'x');  insert_final(&lista2,'y'); 
		insert_final(&lista,'f');		insert_final(&lista2,'x'); 
		insert_final(&lista,'z');  insert_final(&lista2,'a'); 
		insert_final(&lista,'a'); insert_final(&lista2,'a'); 
		insert_final(&lista,'y'); insert_final(&lista2,'b'); 
		insert_final(&lista,'e');
		
		cout << "LISTA 1: "; print_lista(lista);
		
		cout << "menor de la lista: " << menorLista(lista)->info << endl;
	//	cout << "menor de la lista: " << menorListaRecursivo(lista)->info << endl;
		
	
	cout << "ORDEN ITERATIVO: " ; ordenarMenorMayorIterativo(lista);
	print_lista(lista);
	
	cout << endl << endl;
	
	cout << "LISTA 2: "; print_lista(lista2);
	cout << "menor de la lista: " << menorListaRecursivo(lista2)->info << endl;
	cout << "ORDEN RECURSIVO: " ; ordenarMenorMayor(lista2);
	print_lista(lista2);

		
	
		
	return 0;
}

void ordenarMenorMayorIterativo(NodoListaPtr actual)
{
	if(actual != NULL || actual->sig != NULL)
	{
			NodoListaPtr siguiente = NULL;;
			
			while(actual != NULL)
			{
				
				siguiente = actual->sig;
				
				while(siguiente != NULL)
				{
					
					if(actual->info > siguiente->info)
						intercambiar(&(actual->info), &(siguiente->info));
					
						siguiente = siguiente->sig;
				}
				
				
				actual = actual->sig;
			}
	}

}

void ordenarMenorMayor(NodoListaPtr actual)
{
	if(actual == NULL || actual->sig == NULL)
		return;
	else
	{
		NodoListaPtr aux = menorLista(actual->sig);
		
		if(actual->info > aux->info)
			intercambiar(&(actual->info), &(aux->info));
		
		ordenarMenorMayor(actual->sig);

	}
}



NodoListaPtr menorLista(NodoListaPtr actual)
{
	char menor = actual->info;
	NodoListaPtr menorPtr = actual, aux = actual->sig;
	
	while(aux != NULL)
	{
		if(aux->info < menor)
		{
			menor = aux->info;
			menorPtr = aux;
		}
		aux = aux->sig;
	}
	
	return menorPtr;
}

NodoListaPtr menorListaRecursivo(NodoListaPtr actual){
	
	
	
	NodoListaPtr aux = menorListaRecursivo(actual->sig);
	
	if(actual->info < aux->info)
		return actual;
	else
		return aux;
	
	
}

void intercambiar(char * a, char * b)
{
	char aux;
	aux = *a;
	*a = *b;
	*b = aux;
}

void print_lista(NodoListaPtr actual)
{
	if(actual == NULL)
		cout << "NULL" << endl;
	else{
		cout << actual->info << "-->";
		print_lista(actual->sig);
	}
}

void insert_final(NodoListaPtr * startPtr, char valor)
{
	if(*startPtr == NULL)
	{
		NodoListaPtr nuevo = new NodoLista;
		if(nuevo == NULL) cout << "NO MEMORY" << endl;
		else{
			nuevo->info = valor;
			nuevo->sig = NULL;
			*startPtr = nuevo;
		}
	}
	else insert_final( &(*startPtr)->sig , valor);
}

