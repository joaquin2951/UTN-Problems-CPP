#include <iostream>
using namespace std;

bool tieneDigPares(int numero);

int main() {
	
	cout<<endl<<endl<<"---------"<<endl<<endl;
	
	cout << tieneDigPares(0) << endl;
	cout << tieneDigPares(50) << endl;
	cout << tieneDigPares(123) << endl;
	cout << tieneDigPares(43015) << endl;
	cout << tieneDigPares(1) << endl;
	cout << tieneDigPares(513) << endl;
	cout << tieneDigPares(53197) << endl;
	
	return 0;
}

bool tieneDigPares(int numero){
	
	if(numero < 10 and numero >= 0)
		if(numero % 2 == 0)
				return true;
		else
			return false;
	else
		return tieneDigPares(numero%10) + tieneDigPares(numero/10);
	
}
	
	
