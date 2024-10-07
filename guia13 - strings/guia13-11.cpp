#include <iostream>
#include <string>
using namespace std;

void rearmarFrase(string & frase, int & contFrases);

int main(int argc, char *argv[]) {

	int contadorFrases = 1;
	string fr;
	getline(cin,fr);
	
	rearmarFrase(fr, contadorFrases);
	
	cout << fr << endl;
	cout << "cantidad de frases : " << contadorFrases << endl;
	return 0;
}

void rearmarFrase(string & frase, int & contFrases){
	
	int i = 0, longfrase = frase.length();
	
	while(i < longfrase){
		
		if(frase[i-1] == '.'){
			contFrases++;
			if(frase[i] != '#'){
				
				frase[i] = toupper(frase[i]);
			}else{
				
					frase.erase(i,1);
					frase.insert(i,1,'\n');
					frase.insert(i+1,3,' ');
				  
			}
		}
		
		
		i++;
	}
	
	
}
