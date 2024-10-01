#include <iostream>
#include <iomanip>
using namespace std;

bool esPatente(char &a,char &b,char &c,char &d, char &e,char &f, char &g, int& digInc, int& letInc);
void esCorrecto(char &c1, char &c2, int& letrasIncorrectas);
void esCorrectoDig(char &c1, char &c2,char &c3, int& digitosIncorrectos);

int main() {
	char a,b,c,d,e,f,g;
	int digInc=0, letInc=0;
	
	cin>>a>>b>>c>>d>>e>>f>>g;
	
	cout<<"Es patente? : " << boolalpha <<esPatente(a,b,c,d,e,f,g,digInc,letInc) << endl;
	cout<<"Digitos incorrectos: "<< digInc<<endl<<"Letras Incorrectas: "<< letInc <<endl;
	
	cout<<endl<<"------------------"<<endl<<endl<<a<<b<<" "<<c<<d<<e<<" "<<f<<g<<endl;
	
	return 0;
}

void esCorrecto(char &c1, char &c2, int& letrasIncorrectas){
	
	if(c1 < 'A' or c1 > 'Z'){
		letrasIncorrectas++;
		c1 = '#';
	}
		
	if(c2 < 'A' or c2 > 'Z'){
		letrasIncorrectas++;
		c2 = '#';
	}
		
	
}
	
void esCorrectoDig(char &c1, char &c2,char &c3, int& digitosIncorrectos){
		
		if(c1 < '0' or c1 > '9'){
			digitosIncorrectos++;
			c1 = '-';
		}
		
		if(c2 < '0' or c2 > '9'){
			digitosIncorrectos++;
			c2 = '-';
		}
		
		if(c3 < '0' or c3 > '9'){
			digitosIncorrectos++;
			c3 = '-';
		}
		
}

bool esPatente(char &c1,char &c2,char &c3,char &c4, char &c5, char &c6, char &c7, int& digitosInc,int& letrasInc){
	
	bool bandera = false;

  esCorrecto(c1,c2,letrasInc);
	esCorrectoDig(c3,c4,c5,digitosInc);
	esCorrecto(c6,c7,letrasInc);
	
	if(digitosInc+letrasInc == 0)
		bandera = true;
	
	return bandera;
}



