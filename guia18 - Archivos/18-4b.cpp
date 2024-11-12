#include <iostream>
#include <fstream>

using namespace std;



int main(int argc, char *argv[]) {
	
	
	ofstream f; //archivo de tipo OUTPUT (ya que quiero escribir en él)
	int numero;
	int i = 0;
	
	f.open("18-4.bin",ios::binary);//abro archivo
	
	cout << "numero? "; cin >> numero;
	
	for(i = 0; i < numero; i++)
	{
		f.write((char *)&i, sizeof(int));//escribo todo el bloque
	}
	
	
	f.close();//cierro archivo
	
	cout << "escrito!" << endl;
	
	
	// LEER ARCHIVO //
	
	ifstream g;//archivo para leer
	
	g.open("18-4.bin",ios::binary);//Abro arch
	
	if(g.fail())
		cout << "no se abrió el fich de lectura. " << endl;
	else{
		
		int salida;
		
		for(int i = 0; i < numero; i++)
		{
			g.read((char *)&salida, sizeof(int));
			cout << salida << " ";
		}
			
		g.close();//cierro arch
		cout << endl << "leido" << endl;
	
	}
	
	
	return 0;
}

