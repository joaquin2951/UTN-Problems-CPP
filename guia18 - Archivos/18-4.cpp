#include <iostream>
#include <fstream>

using namespace std;



int main(int argc, char *argv[]) {

	
	ofstream f; //archivo de tipo OUTPUT (ya que quiero escribir en él)
	int numero;
	int v[100];
	int v2[100];
	
	cout << "numero? "; cin >> numero;
	
	for(int i = 0; i < numero; i++)
		v[i] = i;
	
	
	f.open("18-4.bin",ios::binary);//abro archivo

	f.write((char *)v, sizeof(v));//escribo todo el bloque
	
	f.close();//cierro archivo
	
	cout << "escrito!" << endl;
	
	
	// LEER ARCHIVO //
	
	ifstream g;//archivo para leer
	
	g.open("18-4.bin", ios::binary);//Abro arch
	
	if(g.fail()){
		cout << "no se abrió el fich de lectura. " << endl;
	}
	else{
		
		g.read((char *)v2, sizeof(v2));
		
		
		for(int i = 0; i < numero; i++)
			cout << v2[i] << " ";
		
		
		g.close();//cierro arch
		cout << "leido" << endl;
		
	}
	
	
	return 0;
}

