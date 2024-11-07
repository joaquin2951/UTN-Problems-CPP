#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {

	ifstream f; // leer archivo;
	ofstream f2; // escribir  archivo;
	char c;

	
	cout << "Cantidad para sumar en clave: "; cin >> c;
	
	f.open("original.txt");
	
	if(!f.fail())
	{
		cout << "Abierto" << endl;
		char obtenido;
		bool terminado = false;
		
		f2.open("enclave.txt");
		
		while(!terminado)
		{
			f >> obtenido;
			
			if(!f.eof())
			{
				cout << "obtenido: " << obtenido << endl;
				obtenido = (char)(obtenido + c);
				cout << "obtenido + c = " << obtenido << endl;
				f2 << obtenido;
			}else{
				terminado = true;
				f2.close();
			}
		}
		f.close();
		
	}
	
	
	
	//Desencriptamos la contraseña:
	
	
	
	f.open("enclave.txt");
	if(!f.fail())
	{
		
		cout << "DESENCRIPTANDO.... " << endl << endl;
		
		bool acabado = false;
		char p;
		while(!acabado)
		{
			f >> p;
			if(!f.eof())
				cout << (char) (p-c);
			else
				acabado = true;
		}
		f.close();
	}
	
	
	return 0;
}

