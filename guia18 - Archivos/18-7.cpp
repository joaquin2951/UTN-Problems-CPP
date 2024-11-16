#include <iostream>
#include <fstream>
#include <ctime>
#include <cstring>

using namespace std;

#define MAX_NAME 11
#define MAX_PASS 37
#define MAX_USERS 3

struct Fecha{
	int dia;
	int mes;
	int anio;
};


struct User{
	char nombre[MAX_NAME];
	char clave[MAX_PASS];
	Fecha ultimo_acceso;
};

User init_User(char n[MAX_NAME], char p[MAX_PASS]);
Fecha fecha_actual();
void ver_users(User u[], int cantidad_a_ver);

int main(int argc, char *argv[]) {
	
	User usuarios[MAX_USERS];
	
	char nombre[MAX_NAME] = "Joaquin";
	char pass[MAX_PASS] = "123_5asd";
	
	usuarios[0] = init_User(nombre,pass);
	
	strcpy(nombre,"Azul"); strcpy(pass,"zzz 32!4az_");
	usuarios[1] = init_User(nombre,pass);
	
	strcpy(nombre,"Adolf"); strcpy(pass,"adolfito123");
	usuarios[2] = init_User(nombre,pass);
	
	
	ver_users(usuarios,MAX_USERS);
	

	//ESCRIBIR EN ARCHIVO
	fstream f;
	f.open("Usuarios.dat",ios::binary | ios::out | ios::in);
	
	if(f.fail())
		cout << "FALLO AL ABRIR" << endl;
	else
	{
		f.write((char *)usuarios,sizeof(usuarios));
		cout << "ARCHIVO GUARDADO" << endl;
	}
	
	


		cout << endl << endl << "EXTRAYENDO DATOS DE BINARIO..." << endl;
		User usuarios_leidos[MAX_USERS];
		
		f.seekg(0);
		f.read((char *)usuarios_leidos,sizeof(usuarios));
		f.close();
		
		ver_users(usuarios_leidos,MAX_USERS);
	

	
	
	return 0;
}

void ver_users(User u[], int cantidad_a_ver)
{
	
	for(int usuario = 0; usuario < cantidad_a_ver; usuario++){
	cout << "DATOS USUARIO " << usuario+1 << endl;
	cout << "Nombre: " << u[usuario].nombre << endl;
	cout << "Pass: " << u[usuario].clave << endl;
	cout << "Ultima Sesion: " << u[usuario].ultimo_acceso.dia << "/" << u[usuario].ultimo_acceso.mes << "/" << u[usuario].ultimo_acceso.anio << endl << endl;
	}
}

User init_User(char n[], char p[])
{
		User u;
		
		strcpy(u.nombre,n);
		strcpy(u.clave,p);
		
		u.ultimo_acceso = fecha_actual();
		
		return u;
}




Fecha fecha_actual()
{
	Fecha f;
	
	time_t ahora;
	tm *fecha;
	time(&ahora);
	fecha = localtime(&ahora);
	
	f.anio = fecha->tm_year+1900;
	f.mes  = fecha->tm_mon+1;
	f.dia  = fecha->tm_mday;
	
	
	return f;
}
