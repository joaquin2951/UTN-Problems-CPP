#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;

int main(int argc, char *argv[]) {
	ofstream num;//creamos y abrimos el arcivo binario
	
	num.open("numeros.bin",ios::binary);
	
	int n;
	cout<<"ingrese la cantidad: ";cin >>n;
	if(num){
		
		for(int i=0;i<n;i++)
			num.write((char *)(& i),sizeof(int));

		num.close();
		
	}
	else{
		cout<<"no se pudo abrir el archivo "<<endl;
	}
	
	
	ifstream leer_numeros("numeros.bin",ios::binary);
	if(leer_numeros)
	{
		int nu;
		
		for(int i = 0; i < n; i++)
		{
			leer_numeros.read((char *)(& nu),sizeof(int));
			cout << nu << " | ";
		}
		
		leer_numeros.close();
	}
	
	return 0;
}

