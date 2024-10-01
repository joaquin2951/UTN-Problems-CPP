#include <iostream>
using namespace std;


int factorial(int numero);


int main() {
	
	cout << factorial(9) << endl;
	
	return 0;
}

int factorial(int numero){
	
	if(numero == 1)
		return 1;
	
	else
		return factorial(numero-1) * numero;
	
}
