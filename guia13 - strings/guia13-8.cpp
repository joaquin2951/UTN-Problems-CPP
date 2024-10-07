#include <iostream>
#include <string>

using namespace std; 

void decodificarSenhal(string & senhal);

int main(int argc, char *argv[]) {
	
	string senal;
	getline(cin,senal);
	
	decodificarSenhal(senal);
	
	cout << senal << endl;
	
	
	return 0;
}


void decodificarSenhal(string & senhal){
	
	int i = 0;
	int longSenhal = senhal.length();
	
	while(i < longSenhal){
	
		if(senhal[i] >= '0' and senhal[i] <= '9'){
			senhal.erase(i,1);
			i--;
		}
		
		i++;
	}
	
	
}
