#include <iostream>
#include <iomanip>

using namespace std;


bool esMayuscula(char character);

int main(){
	
	
	
	cout<< boolalpha	<<esMayuscula('S')<<endl;
	
	
	return 0;
}

	bool esMayuscula(char character){
		
		
		return (character>= 'A' and character <= 'Z');	
	}
