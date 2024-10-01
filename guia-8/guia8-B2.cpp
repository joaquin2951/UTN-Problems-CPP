#include <iostream>
using namespace std;

int cantDigPares(int numero);

int main() {
	
	
	cout << cantDigPares(0) << endl;
	cout << cantDigPares(50) << endl;
	cout << cantDigPares(123) << endl;
	cout << cantDigPares(43015) << endl;
	cout << cantDigPares(1) << endl;
	cout << cantDigPares(500) << endl;
	cout << cantDigPares(43015) << endl;
	
	return 0;
}

int cantDigPares(int numero){
	
	if(numero < 10 and numero >= 0) {
		if((numero%10) % 2 == 0)
			return 1;
		else
			return 0;
	}
	else
		return cantDigPares(numero%10) + cantDigPares(numero/10);
	
}
	
