#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct User{
	char name[30];
	char password[30];
};

int main(int argc, char *argv[]) {
	
	ifstream leer;
	ofstream escribir;
	fstream modificar;
	
	
	//CREAR USUARIO
	User newUser;
	strcpy(newUser.name,"ZiroHZ");
	strcpy(newUser.password,"ziro123");
	
	escribir.open("Usuarios.dat", ios::binary);
	escribir.write((char *) & newUser, sizeof(User));
	escribir.close();
	
	cout << "Registrado!" << endl << endl << endl;
	
	
	//LOGIN USUARIO
	char n[30],p[30];
	
	cout << "Username: "; gets(n);
	cout << "Password: "; gets(p);
	
	User u_get;
	leer.open("Usuarios.dat", ios::binary);
	leer.read((char*)&u_get, sizeof(User));
	leer.close();
	
	if(strcmp(n,u_get.name) == 0 and strcmp(p,u_get.password) == 0)
		cout << "LOGUEADO!" << endl;
	else
		cout << "DATOS INCORRECTOS!" << endl;
	
	
	cout << "Usuario correcto: " << u_get.name << " | " << u_get.password << endl;
	cout << "Tu ingresaste:    " << n << " | " << p << endl;
	
	
	
	
	return 0;
}

