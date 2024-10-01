#include <iostream>
using namespace std;

int fibonacci(int num);

void fibonacciImpreso(int num);

void iccanobif(int num);

int main() {
	//cada término es siempre igual a la suma 
	//de los dos siguientes. 
	//Excepto por los dos últimos términos que siempre son iguales a 1
	
	iccanobif(5);
	
	cout <<"fibonacci: " << fibonacci(7) << endl;
	cout <<"fibonacci impreso: "; fibonacciImpreso(7);
	return 0;
}


// iccanobif(5) 5 3 2 1 1

// iccanobif(10) 55 34 21 13 8 5 3 2 1 1

void iccanobif(int num){
	int aux = 1;
	
	if(num == 1){
		cout << 1 << endl;
	}
	else if (num == 2){
		cout << 1 << endl;
	}
	else{
		
	}
	
}
	//ingreso 5 --> fibonacci(4) + fibonacci(3) | fibonacci(3)+fibonacci(2) | fibonacci(2) + fibonacci(1) | fibonacci(2) | fibonacci(1) ;
	//ingreso 3 --> fibonacci(2) + fibonacci(1) | fibonacci(2) | fibonacci(1)
	
	
	
	int fibonacci(int num){
		if(num == 1)
			return 1;
		else if(num == 2)
			return 1;
		else
			return fibonacci(num-1) + fibonacci(num-2);
	}

		void fibonacciImpreso(int num){
			if(num == 1)
				cout << fibonacci(1);
			else if (num == 2)
				cout << fibonacci(1);
			else {
				cout << fibonacci(num-1) + fibonacci(num-2);
				
			}
				
			
		}
