#include <iostream>
using namespace std;

void infoMes(int mes);

int main() {
	
	int mes;
	cout<< " ingrese numero del mes: " ;  cin>>mes;
	
	infoMes(mes);
	
	
	return 0;
}

void infoMes(int mes){
	
	
	switch(mes){
		
	case 1: cout<< "enero | 30 dias" << endl; break;
	case 2: cout<< "febrero | 28 dias "<< endl; break;
	case 3: cout<< "marzo "<< endl; break;
	case 4: cout<< "abril "<< endl; break;
	case 5: cout<< "mayo "<< endl; break;
	case 6: cout<< "junio "<< endl; break;
	case 7: cout<< "julio "<< endl; break;
	case 8: cout<< "agosto "<< endl; break;
	case 9: cout<< "septiembre "<< endl; break;
	case 10: cout<< "octubre "<< endl; break;
	case 11: cout<< "noviembre "<< endl; break;
	case 12: cout<< "diciembre | 29 dias "<< endl; break;
		
	}
	
	
}
