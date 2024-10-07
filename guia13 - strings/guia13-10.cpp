#include <iostream>
using namespace std;


void contarVocales(int vocales[], string telegrama);
int espaciosvacios(string telegrama);
int cantPalabrasMayores(string telegrama);
int cantPalabras(string telegrama);

int main(int argc, char *argv[]) {
	string telegrama;
	int vocales[5] = {0};
	int espaciosEnblanco;
	int cantPalabrasLargas = 0;
	float costo;
	
	getline(cin,telegrama);
	
	contarVocales(vocales,telegrama);
	espaciosEnblanco = espaciosvacios(telegrama);
	cantPalabrasLargas = cantPalabrasMayores(telegrama);
	costo = 5.2 * (float)(cantPalabras(telegrama)) ;
	
	cout << "Cantidad de palabras con más de 7 letras: " << cantPalabrasLargas << endl;
	
	cout << "ocurrencia de vocales: " << vocales[0] + vocales[1] + vocales[2] + vocales[3] + vocales[4] << endl;
	cout << "a : " << vocales[0] << endl;
	cout << "e : " << vocales[1] << endl;
	cout << "i : " << vocales[2] << endl;
	cout << "o : " << vocales[3] << endl;
	cout << "u : " << vocales[4] << endl;
	
	cout << "Espacios en blanco: " << (float)(espaciosEnblanco*100.0) / (float)(telegrama.length()) << "%" << endl;
	cout << "Costo del telegrama: " << "$" << costo << endl;
	
	
	return 0;
}

int cantPalabras(string telegrama){
	int cant = 0;
	int i = 0, longtel = telegrama.length();
	
	while(i < longtel){
		if(telegrama[i] == ' ' or telegrama[i] == '.')
			cant++;
		i++;
	}
	return cant;
}

int cantPalabrasMayores(string telegrama){
	int palabras7 = 0;
	int i = 0, longTel = telegrama.length();
	string palabra;
	
	while(i <= longTel){
		
			if(telegrama[i] == ' ' or telegrama[i] == '.'){
				palabra = telegrama.substr(0,i);
				if(palabra.length() > 7)
					palabras7++;
				
				telegrama.erase(0,i+1);
				i = -1;
				longTel = telegrama.length();
			}
		
		i++;
	}
	
	
	return palabras7;
}

int espaciosvacios(string telegrama){
	int longTelegrama = telegrama.length();
	int i = 0;
	int vacios = 0;
	
	while(i < longTelegrama){
		if(telegrama[i] == ' ')
			vacios++;
		
		i++;
	}
	
	
	return vacios;
}

void contarVocales(int vocales[], string telegrama){
	
	int longTelegrama = telegrama.length();
	int i = 0;
	
	while(i < longTelegrama){
		
		switch(telegrama[i]){
		case 'a': vocales[0]++; break;
		case 'e': vocales[1]++; break;
		case 'i': vocales[2]++; break;
		case 'o': vocales[3]++; break;
		case 'u': vocales[4]++; break;
		}
		
		i++;
	}
	
}
