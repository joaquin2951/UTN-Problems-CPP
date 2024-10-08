#include <iostream>
#include <string>
using namespace std;


struct puntoPlano{
	float X;
	float Y;
	float Z;
};

struct linea{
	puntoPlano Puntos[50];
};

struct fecha{
	int dia;
	int mes;
	int anho;
};

struct persona{
	string nombre;
	string apellido;
	string DNI;
	int edad;
	fecha fechaNacimiento;
	string direccion;
	string telefono;
};

struct estudiante{
	persona Estudiante;
	int materiasCursadas;
	int materiasAprobadas;
	float promedioNotas;
	string nombreMaterias[14];
};

struct listaAlumnosCurso{
	const int cantEstudiantes = 5;
	estudiante Estudiantes[5];
	float porcentajeAprobados;
};

struct naipe{
	char valor; 
  string palo;
};

struct mazo{
	string tipoBaraja; //francesa, española, Uno...
	naipe baraja[50];
};

struct libro{
	string nombreLibro;
	string nombreAutor;
	string categoriaLibro;
	fecha fechaSalida;
	int numDeEdicion;
	float precio;
	int cantPaginas;
};

struct biblioteca{
	string nombreBiblioteca;
	string categorias[50];
	libro libros[500];
};

int main() {

	
	
	return 0;
}

