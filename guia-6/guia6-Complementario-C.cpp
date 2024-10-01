#include <iostream>
using namespace std;

bool Patente(char caracter, int iteracion);

int main() {
	char a;
	int i = 0;
	
	while ( i < 7 ){
		
		cin>>a;
		
		if(not Patente(a,i)){
				cout<<"El caracter "<< a << " no pertenece a la Patente Argentina" << endl;
		    return 1;
		}
		
		i++;
	}
	
	cout << "Felicidades, su patente es Argentina" << endl;
	
	return 0;
}

bool Patente(char caracter, int iteracion){
	
	bool cumple = false;
	
	if(iteracion <= 1 or iteracion >=5){
				if(caracter >='0' and caracter <= '9' )
						cumple = true;
				
	}
	else
		 if(iteracion > 1 or iteracion < 5){
				if(caracter >='A' and caracter <= 'Z' )
						cumple = true;
	}
	
	
	
	return cumple;
}
