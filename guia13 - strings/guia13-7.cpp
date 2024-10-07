#include <iostream>
#include <string>


using namespace std;


bool sonAnagramas(string & palabra1, string & palabra2);
void ordenamientoBurbuja(string & palabra);

int main(int argc, char *argv[]) {
	string p1, p2;
	
	getline(cin,p1); getline(cin,p2);
	
	
	cout << boolalpha << sonAnagramas(p1,p2) << endl;
	cout << p1 << " " << p2 << endl;
	
	
	return 0;
}



void ordenamientoBurbuja(string & palabra){
	int pasadas, j, longitud;
	longitud = palabra.length();
	
	for(pasadas = 1; pasadas < longitud ; pasadas++){
		for(j = 0; j < longitud-pasadas; j++){
			
			if(palabra[j] > palabra[j+1]){
				swap(palabra[j],palabra[j+1]);
			}
			
		}
	}
	
}

bool sonAnagramas(string & palabra1, string & palabra2){
	
	int longPalabra = palabra1.length(), long2 = palabra2.length();
	bool sonAnagrama = true;
	
	if(longPalabra != long2){
		sonAnagrama = false;
	}
	else{
		ordenamientoBurbuja(palabra1); ordenamientoBurbuja(palabra2);
		if(palabra1 != palabra2)
			sonAnagrama = false;
	}
	
	
return sonAnagrama;
}
