#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
using namespace std;

#define TAM_CHAR 40
#define TAM_LINEA 2
#define TAM_PAGINAS 3

struct Linea
{
 	char c[TAM_CHAR];
};

struct Pagina
{
	Linea lineas[TAM_LINEA];
};

struct Libro
{
	Pagina paginas[TAM_PAGINAS];
};


void guardarTexto(Libro & b);
void modificarTexto(string nombre_archivo, int num_linea);
void imprimirPagina(string nombre_archivo, int num_pagina);
void imprimirLibro_desdeArchivo(string nombre_archivo);
void imprimirLibro(Libro b);

int main(int argc, char *argv[]) {
	
	Libro b;
	
	strcpy(b.paginas[0].lineas[0].c,"Hola soy joaquin,");
	strcpy(b.paginas[0].lineas[1].c,"Me gusta el arte.");
	
	strcpy(b.paginas[1].lineas[0].c,"Estamos navegando,");
	strcpy(b.paginas[1].lineas[1].c,"En un mundo sin final");
	
	strcpy(b.paginas[2].lineas[0].c,"Y en esta ultima pagina...");
	strcpy(b.paginas[2].lineas[1].c,"Adios.");
	
	
	cout << "IMPRESO DESDE MEMORIA: " << endl;
	imprimirLibro(b);
	guardarTexto(b);
	
	cout << endl << "-----------------" << endl << endl;
	
	cout << "IMPRESO DESDE ARCHIVO: " << endl;
	imprimirLibro_desdeArchivo("EditorDeTexto.bin");
	
	cout << endl << "-----------------" << endl << endl;
	
	cout << "IMPRIMO PAGINA 2 DESDE ARCHIVO " << endl;
	imprimirPagina("EditorDeTexto.bin",2);
	
	cout << endl << "-----------------" << endl << endl;
	
	int i;
	cout << "MODIFICAREMOS LINEA " ; cin >> i; cin.ignore();
	modificarTexto("EditorDeTexto.bin",i); cout << endl;
	
	imprimirLibro_desdeArchivo("EditorDeTexto.bin");
	
	return 0;
}

void modificarTexto(string nombre_archivo, int num_linea)
{
	char nueva_linea[TAM_CHAR];
	cout << "Qué dirá la nueva línea? "; gets(nueva_linea);
	
	fstream f(nombre_archivo,ios::binary | ios::out | ios::in);
	
	if(!f)
		cout << "Error al abrir archivo. " << endl;
	else
	{
		if(sizeof(Linea) * (num_linea - 1) >= f.seekg(0,ios::end).tellg())
			cout << "No existe esa linea";
		else
		{
			f.seekp(sizeof(Linea) * (num_linea-1));
			f.write((char *)&nueva_linea,sizeof(Linea));
			f.close();
			cout << "Escritura realizada. " << endl;
		}
	}
	
}

void imprimirPagina(string nombre_archivo, int num_pagina)
{
	ifstream f;
	f.open(nombre_archivo,ios::binary);
	
	Pagina p;
	
	if(f.fail())
		cout << "Error al abrir archivo." << endl;
	else
	{
		
		if(sizeof(Pagina)*(num_pagina-1) >= f.seekg(0,ios::end).tellg())
		{
			cout << "No existe esa página" << endl;
		}
		else{
		f.seekg(sizeof(Pagina) * (num_pagina-1));
	  f.read((char *)&p, sizeof(Pagina));
		f.close();
		
		cout << "Pagina obtenida: " << endl;
		for(int i = 0; i < TAM_LINEA; i++)
			cout << p.lineas[i].c << endl;
		
		}
	}
}


void imprimirLibro(Libro b)
{
	for(int P = 0; P < TAM_PAGINAS; P++){
		
		cout << "Pagina " << P+1 << endl;
		
		for(int L = 0; L < TAM_LINEA; L++)
		{
			cout << b.paginas[P].lineas[L].c << endl;
		}
		
		cout << endl << endl;
	}
}

void imprimirLibro_desdeArchivo(string nombre_archivo)
{
	ifstream f;
	f.open(nombre_archivo,ios::binary);
	
	Libro b;
	
	if(f.fail())
		cout << "Error al abrir archivo." << endl;
	else
	{
		f.read((char *)&b, sizeof(Libro));
		f.close();
		
		cout << "Libro obtenido: " << endl;
		
		
		for(int P = 0; P < TAM_PAGINAS; P++){
			
			cout << "Pagina " << P+1 << endl;
			
			for(int L = 0; L < TAM_LINEA; L++)
			{
				cout << b.paginas[P].lineas[L].c << endl;
			}
			
			cout << endl << endl;
		}
		
	}
}



void guardarTexto(Libro & b)
{
	ofstream f;
	f.open("EditorDeTexto.bin", ios::binary);
	
	if(f.fail())
		cout << "Error al abri fichero" << endl;
	else
	{
		f.write((char *)&b, sizeof(Libro));
		f.close();
		cout << "Libro guardado con éxito." << endl;
	}
}
