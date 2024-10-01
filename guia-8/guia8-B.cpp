#include <iostream>
using namespace std;

int cantDig(int numero);

int main() {
	
	
	cout << cantDig(0) << endl;
	cout << cantDig(50) << endl;
	cout << cantDig(123) << endl;
	cout << cantDig(43015) << endl;
	cout << cantDig(-1) << endl;
	cout << cantDig(-500) << endl;
	cout << cantDig(-43015) << endl;
	
	return 0;
}

int cantDig(int numero){
	if(numero < 0)
		return cantDig(numero*-1);
	else
		if(numero < 10)
			return 1;
	
		else	
			return 1 + (cantDig(numero/10));
	
}
