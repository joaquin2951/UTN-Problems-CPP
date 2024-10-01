#include <iostream>
using namespace std;



void chrtoupper(char & character);

int main() {
	char a;
	cin>>a;
	
	chrtoupper(a);
	cout << a << endl;
	
	return 0;
}

void chrtoupper(char & character){
	
	if(character>='a' and character<='z')
			character = character - 32;
	
	
}
