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

	
	cargarLibro(b);
	
	
	ofstream escribir;//archivo para escribir en el
	escribir.open("inventario.bin", ios::binary);//es binario
	
	escribir.write((char *) &b, sizeof(Libro));//escribimos todo el libro
	
	escribir.close();//Cerramos archivo
	
	
	//Leer datos desde el archivo
	ifstream leer;//archivo para leer los datos y traerlos a una variable 
	Libro l;//la variable en la que almacenaremos los datos
	
	leer.open("inventario.bin",ios::binary);
	
	leer.read((char *) &l, sizeof(Libro));//leo el archivo binary
	
	leer.close();//lo cierro
	
	leerLibro(l);//imprimimos los datos en pantalla
	
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
}
