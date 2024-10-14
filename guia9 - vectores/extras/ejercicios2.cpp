#include <iostream>
using namespace std;


int main() {
	
	const int TAMANHO = 4;
	double corriente[TAMANHO], voltio[TAMANHO], resistencia[TAMANHO];

	for(int i = 0; i < TAMANHO ; i++){
		cout << "corriente " << "i: "; cin >> corriente[i];
		cout << "resistencia " << "i: "; cin >> resistencia[i];
		voltio[i] = corriente[i]  * resistencia[i];
	}
	
	for(int i = 0 ; i < TAMANHO ; i++){
		cout << "CORRIENTE    RESISTENCIA    VOLTIOS" << endl;
		cout << "   " << corriente[i] << "              " << resistencia[i] << "             " << voltio[i] << endl;
	}
	
	return 0;
}

