#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string generarCorreo(string nombreUsuario, string dominio);


int main() {
	
	string nombreCompleto, dominio = "@frsf.utn.edu.ar", correo;
	cout << "ingresar apellido y nombre: " ; getline(cin,nombreCompleto);
	
	correo = generarCorreo(nombreCompleto,dominio);
	
	cout << correo << endl;
	
	return 0;
}

string generarCorreo(string nombreUsuario, string dominio){
	int posicionEspacio = nombreUsuario.find(' ');
	string correo;
	
	
	correo = nombreUsuario[posicionEspacio+1] + nombreUsuario.substr(0,posicionEspacio) + dominio;
	
	correo[0] = tolower(correo[0]); correo[1] = tolower(correo[1]);
	
	return correo;
}
	
