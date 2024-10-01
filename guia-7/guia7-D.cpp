#include <iostream>
#include <cmath>
using namespace std;


int quantityCif(int number);
void reverseNumber(int & number);
int potencia(int base,int potencia);

int main() {
	
	int a;
	cin >> a;
	
	cout << "su numero tiene " << quantityCif(a) << " cifras" <<endl<<endl;
	reverseNumber(a);
	cout << endl<<  "dado vuelta, su numero es: " << a << endl;
	
	
	return 0;
}


void reverseNumber(int & number){
	
	int auxiliar = number;
	int i = quantityCif(number);
	number = 0;
	
	while(auxiliar > 0){
		cout<< "aux: "<<auxiliar<<" ";
		
		i--;
		number = number + ( (auxiliar%10) * potencia(10,i) );
		cout<<"number:"<<number<<endl;
		
		auxiliar = auxiliar / 10;
	}
	
	
}
int quantityCif(int number){
	int cantidad = 0;
	if(number == 0)
		cantidad++;
	if(number<0)
		number = number * -1;
	
	while (number > 0){
		number = number/10;
		cantidad++;
	}
	return cantidad;
}

	int potencia(int base,int potencia){
		int numero = base;
		if( potencia == 0 )
				numero = 1;
		else
			for(int i = 1; i < potencia; i++)
				numero = numero * base;
		
		return numero;
	}
