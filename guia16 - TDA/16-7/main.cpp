#include <iostream>
#include "PILA.h"

using namespace std;

int main()
{
	Pila p;
	
	p = Crear();
	
	if(!Vacia(p))
		cout << Cima(p) << endl;
	else
		cout << "Esta vacia" << endl;
	
	Apilar(p,5);  cout << Cima(p) << " | " << p.tl << endl;
	Apilar(p,10); cout << Cima(p) << " | " << p.tl << endl;
	Apilar(p,3);  cout << Cima(p) << " | " << p.tl << endl;
	Apilar(p,78); cout << Cima(p) << " | " << p.tl << endl;
	
	Desapilar(p); cout << Cima(p) << endl; 
	Desapilar(p); cout << Cima(p) << endl;
	Desapilar(p); cout << Cima(p) << endl;
	Desapilar(p); cout << Cima(p) << endl;
	
	Apilar(p,130); Apilar(p,70);
	cout << Cima(p) << endl;
	
	if(!Vacia(p))
		cout << Cima(p) << endl;
	else
		cout << "Está vacia" << endl;
	
	return 0;
}
