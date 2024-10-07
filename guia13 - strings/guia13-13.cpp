#include <iostream>
#include <string>
using namespace std;

string invString_recursivo(string frase);

int main(int argc, char *argv[]) {
	
	string txt;
	getline(cin,txt);
	
	txt = invString_recursivo(txt);
	cout << txt << endl;
	
	return 0;
}

string invString_recursivo(string frase){
	
	if(frase.length() < 2){
		return frase;
	}else{
		return frase[frase.length()-1] + invString_recursivo(frase.substr(0,frase.length()-1)); 
	}
	
}
