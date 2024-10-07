#include <iostream>
#include <string>

#include <iomanip>
using namespace std;
//cin>>  no inclye espacios
//getline(cin,nombreVariable) incluye espacios, toda la linea
//getline(cin,nombrevariable,',') para delimitar 
//cin>>ws  (limpia el buffer)
//nombre.size() 
//nombre.lenght()
//nombre.find()    busca la primer ocurrencia
//nombre.rfind()   busca la ultima ocurrencia
//nombre.substr() 
//nombre.erase()

bool estaEnRango(string usuario);
bool esValido(string usuario);
bool ischar(char a);

int main() {
	string nuevoUsuario;
	
	cout << "introduzca nombre de usuario: " ;
	cin >> nuevoUsuario;
	
	cout << boolalpha << esValido(nuevoUsuario) << endl;
	
	
	return 0;
}

bool ischar(char a){
	if((a >= 'a' and a <= 'z') or (a >= 'A' and a <= 'Z'))
		return true;
	return false;
}

bool estaEnRango(string usuario){
	char let = usuario[0];
	if( (let >= 'a' and let <= 'z') or (let >= 'A' and let <= 'Z'))
		return true;
	return false;
}
	
	bool esValido(string usuario){
		bool validacion = true;
		int longFrase = usuario.length();
		
		if(longFrase !=8 or !estaEnRango(usuario))
			validacion = false;
		else{
			int i = 1;
			while ( i < longFrase ){
				if( !isdigit(usuario[i]) and !ischar(usuario[i]) )
					validacion = false;
				i++;
			}
		}
		
		
		
		return validacion;
	}
		
		
