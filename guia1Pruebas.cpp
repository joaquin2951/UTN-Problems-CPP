#include <iostream>
using namespace std;
int b=23;
int main() {
	
	int a=5,b=4,c=10;
	
	
	if(a>b){
		cout<<b<<endl;
		int b = 2;
		int c = 5;
		cout<< ::b <<endl;
	}
	
	cout<<::b<<endl;
	
	return 0;
}

