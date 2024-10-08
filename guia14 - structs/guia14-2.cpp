#include <iostream>
#include <string>
using namespace std;


struct direccion{
	string calle;
	int numero;
	string barrio;
};

struct fecha{
	int dia,mes,anho;
};

struct empleado{
	string nombre;
	direccion Direccion;
	fecha fechaNacimiento;
	char sexo;
	float sueldo;
	string categoria;
	fecha fechaIngreso;
};

void CargarDatos_empleado(empleado listaEmpleados[], const int TL);
void imprimirNombre(empleado listaEmpleados[], const int TL);
void aumentarSueldo(empleado listaEmpleados[], const int TL, int anhoActual);
void Listarmenores(empleado listaEmpleados[], const int TL, int anhoActual);
void ListarBarrio(empleado listaEmpleados[], const int TL, string nombreBarrio);
void ListarOperarioporBarrio(empleado listaEmpleados[], const int TL, string nombreBarrio);
void OrdenarEmpleados(empleado listaEmpleados[], const int TL);

int main() {
	const int cantEmpleados = 3;
	empleado Empleados[cantEmpleados];
	
	cout << Empleados[2].nombre << endl;
	cout << Empleados[2].sexo << endl;
	

	OrdenarEmpleados(Empleados,cantEmpleados);
	
	
	
	return 0;
}

void OrdenarEmpleados(empleado listaEmpleados[], const int TL){
	bool Ordenado = false;
	int pasadas = 1;
	
	while(Ordenado == false and pasadas < TL){
		for(int k = 0; k < TL - pasadas; k++){
			if( listaEmpleados[k].nombre > listaEmpleados[k+1].nombre ){
				swap(listaEmpleados[k],listaEmpleados[k+1]);
			}
		}
		pasadas++;
	}
	
	
}
	
	void ListarOperarioporBarrio(empleado listaEmpleados[], const int TL, string nombreBarrio){
		cout << "Operarios que viven en el Barrio " << nombreBarrio << ":" << endl;
		for(int i = 0; i < TL; i++){
			if(listaEmpleados[i].categoria == "Operario" and listaEmpleados[i].Direccion.barrio == nombreBarrio){
				cout << "empleado " << i << ": " << listaEmpleados[i].nombre << endl;
			}
		}
	}
		
		void ListarBarrio(empleado listaEmpleados[], const int TL, string nombreBarrio){
			cout << "Empleados que viven en el Barrio " << nombreBarrio << ":" << endl;
			for(int i = 0; i < TL; i++){
				if(listaEmpleados[i].Direccion.barrio == nombreBarrio){
					cout << "empleado " << i << ": " << listaEmpleados[i].nombre << endl;
				}
			}
		}
			
			void menores(empleado listaEmpleados[], const int TL, int anhoActual){
				cout << "Empleados menores de 25 anhos: " << endl;
				for(int i = 0; i < TL; i++){
					if( anhoActual - listaEmpleados[i].fechaNacimiento.anho < 25 ){
						cout << "empleado " << i << ": " << listaEmpleados[i].nombre << endl;
					}
				}
			}
				
				void aumentarSueldo(empleado listaEmpleados[], const int TL, int anhoActual){
					
					for(int i = 0; i < TL; i++){
						if(anhoActual - listaEmpleados[i].fechaIngreso.anho > 5){
							listaEmpleados[i].sueldo = listaEmpleados[i].sueldo + (listaEmpleados[i].sueldo * 0.15);
						}
					}
				}
					
					
					
					void imprimirNombre(empleado listaEmpleados[], const int TL){
						cout << "Empleados con sueldo mayor a 57500: " << endl;
						for(int i = 0; i < TL; i++){
							if(listaEmpleados[i].sueldo > 57500){
								cout << listaEmpleados[i].nombre << endl;
							}
						}
					}
						
void CargarDatos_empleado(empleado listaEmpleados[], const int TL){
							
							for(int i = 0; i < TL; i++){
								cout << "nombre: "; getline(cin, listaEmpleados[i].nombre);
								cout << "calle: ";  getline(cin, listaEmpleados[i].Direccion.calle);
								cout << "numero: "; cin >> listaEmpleados[i].Direccion.numero;
								cout << "barrio: "; getline(cin, listaEmpleados[i].Direccion.barrio);
								cout << "Fecha Nacimiento" << endl;;
								cout << " dia: "; cin >> listaEmpleados[i].fechaNacimiento.dia;
								cout << "mes: "; cin >> listaEmpleados[i].fechaNacimiento.mes;
								cout << "anho: "; cin >> listaEmpleados[i].fechaNacimiento.anho;
								cout << "sexo: "; cin >> listaEmpleados[i].sexo;
								cout << "sueldo: "; cin >> listaEmpleados[i].sueldo;
								cout << "categoria: "; getline(cin,listaEmpleados[i].categoria);
								cout << "fecha ingreso" << endl;
								cout << "dia: "; cin >> listaEmpleados[i].fechaIngreso.dia;
								cout << "mes: "; cin >> listaEmpleados[i].fechaIngreso.mes;
								cout << "anho: "; cin >> listaEmpleados[i].fechaIngreso.anho;
							}
							
}
							
