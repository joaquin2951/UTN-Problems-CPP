#include <iostream>
using namespace std;

struct Direccion{
	string nombre_calle;
	int altura;
};

struct Fecha{
	string dia;
	string mes;
	string anyo;
};

struct Persona{
	
	string nombre_apellido;
	Direccion direccion ;
	
	string DNI;
	string telefono;
	
	Fecha fecha_nacimiento;

	string tipo_visita; //Consulta, Estudio, Emergencia, etc.
	string area_atencion; //Traumatologia, Toxicologia, Radiología, etc.
	
	Fecha fecha_ingreso;
	Fecha fecha_egreso;
	
};


struct Hospital{
	Persona Pacientes[5000];//que ingresan / egresan
};

int main(int argc, char *argv[]) {
	
	return 0;
}

