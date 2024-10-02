#include <iostream>
using namespace std;

int cantDig(int numero);
int sumaDeDig(int numero, int cantDigitos);
int esDistinto(int numero, int vec[]);

int main() {

	int vec[500];
	
	
	for(int i = 0; i < 10; i++){
		
		cout << "[" << i << "] = " ;
		cin >> vec[i];
		
	};
	
	
	int i = 10;
	
	do{
		cin >> vec[i];
		
		i++;
	}
	while( esDistinto(vec[i-1], &vec[0]) );
	
	
	cout << "numero: " << vec[i-1] << endl;
	
	return 0;
}

int esDistinto(int numero, int vec[]){
	
	for(int i = 0; i < 10; i++)
		if(sumaDeDig(numero,cantDig(numero))  == vec[i])
			return false;
	
	
	return true;
}
	
int cantDig(int numero){
	int digitos = 1;
	
	while(numero/10 != 0){
		numero/=10;
		digitos++;
	}
	
	return digitos;
}
	
int sumaDeDig(int numero, int cantDigitos){
	int suma = 0;
	for(int i = 0; i < cantDigitos; i++){
		suma = suma + numero%10;
		numero = numero / 10;
	}
	return suma;
}
