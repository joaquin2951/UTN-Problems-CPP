#include <iostream>
using namespace std;

int suma(int N);

int main() {
	
	cout<<suma(5)<<endl;
	
	
	return 0;
}


int suma(int N){
	
	if(N==2)
		return 2;
	else
		if(N%2 == 0)
			return N + suma(N-1);
		else
			return suma(N-1);
	
	
}
