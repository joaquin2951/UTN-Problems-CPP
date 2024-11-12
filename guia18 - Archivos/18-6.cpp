#include <iostream>
#include <fstream>
using namespace std;



struct Libro
{
	char titulo[30];
	char autor[30];
	char ISBN[30];
	float precio;
	int stock;
	int cant_vendida;
};

void leerLibro(const Libro b);
void cargarLibro(Libro & b);

int main(int argc, char *argv[]) {
	
	Libro b;
	
	ofstream escribir;//archivo para escribir en el
	escribir.open("inventario.bin", ios::binary);//es binario
	
	for(int books = 0; books < 3; books++)//Cargamos 3 libros
	{
		cargarLibro(b);
		escribir.write((char *) &b, sizeof(Libro));//escribimos todo el libro
	}
	
	escribir.close();//Cerramos archivo
	
	
	//Leer datos desde el archivo
	ifstream leer;//archivo para leer los datos y traerlos a una variable 
	Libro l;//la variable en la que almacenaremos los datos
	
	leer.open("inventario.bin",ios::binary);
	
	
	//RECUPERAR EL ARCHIVO DEL 3er LIBRO y mostrar en pantalla tit y autor
	leer.seekg(sizeof(Libro) * 2);
	leer.read((char * ) &l, sizeof(l));
	leer.close();
	
	cout << "TERCER LIBRO ALMACENADO: " << endl;
	cout << "autor: " << l.autor << endl;
	cout << "titulo: " << l.titulo << endl << endl << endl;
	
	
	//REEMPLAZAR EL 2do LIBRO CON UNO NUEVO
	fstream modificar_f;
	modificar_f.open("inventario.bin",ios::binary | ios::in | ios::out);
	
	if(!modificar_f)
	{
		cout << "No se abrio el archivo. " << endl;
		return 1;
	}
	
	cout << "NUEVO LIBRO: " << endl;
	Libro newBook;
	cargarLibro(newBook);
	
	modificar_f.seekp(1 * sizeof(Libro), ios::beg);//lo muevo al segundo libro
	modificar_f.write((char *)&newBook,sizeof(Libro));
	modificar_f.close();
	
	cout << endl << endl;
	
	//MOSTRAR POR PANTALLA EL INVENTARIO COMPLETO
	
	leer.open("inventario.bin", ios::binary);
	
	cout << "INVENTARIO COMPLETO" << endl;
	Libro lib;
	
	int books = 0;
	while(leer.read((char*) &lib, sizeof(Libro)))
	{
		cout << "Libro " << ++books << endl;
		leerLibro(lib);
	}
	
	
	leer.close();//lo cierro
	
	
	
	return 0;
}

void leerLibro(const Libro b)
{
	cout << b.titulo << endl;
	cout << b.autor << endl;
	cout << b.ISBN << endl;
	cout << b.precio << endl;
	cout << b.stock << endl;
	cout << b.cant_vendida << endl;
}

void cargarLibro(Libro & b)
{
	cout << "titulo: "; gets(b.titulo);
	cout << "autor: ";  gets(b.autor);
	cout << "ISBN: ";   gets(b.ISBN);
	cout << "Precio: "; cin >> b.precio;
	cout << "Stock: ";  cin >> b.stock;
	cout << "Vendido: ";cin >> b.cant_vendida;
	cin.ignore();
}
