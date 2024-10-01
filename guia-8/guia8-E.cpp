#include <iostream>
using namespace std;

void Inverso(int num);

int main() {
	
	Inverso(501341);
	
	return 0;
}

void Inverso(int num){
	
	if(num<10)
		cout<<num;
	else{
		cout << num%10 << " ";
		Inverso(num/10);
	}
	
}
