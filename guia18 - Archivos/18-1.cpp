#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
	
	ofstream EscribirEnArchivo;
	ifstream LeerArchivo;
	
	char c[30];
	
	EscribirEnArchivo.open("Digitos.txt");
	
	if(EscribirEnArchivo.fail()){
		cout << "No se abrio" << endl;
	}
	else
	{
		cout << "Abierto para escribir" << endl;
		
		for(int i = 0; i < 30; i++)
		{
			c[i] = i + 48;
			EscribirEnArchivo << c[i];
		}
			
			
		cout << "Datos cargados. " << endl;
		
		EscribirEnArchivo << 'B';
		EscribirEnArchivo << '\n';
		EscribirEnArchivo << 'z';
		EscribirEnArchivo.close();
	}
	
		
	
	

	LeerArchivo.open("Digitos.txt");
	
	if(LeerArchivo.fail()){
		cout << "no se abrio" << endl;
	}else
	{
		cout << "Abierto para leer" << endl;
		char x;
		int cont = 0;
		bool terminado = false;
		
		while(!terminado)
		{
			LeerArchivo >> x; 
			if(!LeerArchivo.eof()){
				cout << "x: " << x << endl;
				if(isalnum(x)) cont++;
			}
			else
				terminado = true;
		}
		
		cout << "Cantidad de digitos y letras: " << cont << endl;
		LeerArchivo.close();
	}

	
	return 0;
}

