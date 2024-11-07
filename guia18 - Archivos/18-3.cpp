#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
	
	ifstream f;//leer archivo
	//	ofstream f2;//escribir archivo
	
	char empieza, termina;
	cout << "Empieza con: "; cin >> empieza;
	cout << "Termina con: "; cin >> termina;
	
	f.open("texto.txt");
	
	if(!f.fail())
	{
		
		bool terminado = false;
		bool existePalabra = false;
		char c;
		int palabras = 0,longitud = 0, mayor = 0;
		char e,t;
		
		while(!terminado)
		{
			//	f >> c;//NO LEE LOS ESPACIOS EN BLANCO
			f.get(c); //LEE LOS ESPACIOS EN BLANCO Y SALTOS DE LINEA
			
			
			
			if(!f.eof()){
				
				cout << c;
				
				if(c == ' ' || c == '\n' || c == '.')
				{
					
					if(e == empieza and t == termina)
						existePalabra = true;
					
					palabras++;
					
					if(longitud > mayor)
						mayor = longitud;
					
					longitud = 0; //arranca nueva palabra
				}else
				{
					
					if(longitud == 0) e = c;
					else t = c;
					
					longitud++;
				}
					
				
			}else
								terminado = true;
		}
		
		
		cout << endl << "Palabras : " << palabras << endl;
		cout << "Longitud de la palabra mas larga: " << mayor << endl;
		cout << "Existe palabra que empiece con " << empieza 
			<< " y termine con " << termina << " " 
			<< boolalpha << existePalabra;
		
		f.close();
	}
	
	
	
	return 0;
}

