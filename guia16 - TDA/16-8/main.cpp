#include <iostream>
#include "COLA.h"

using namespace std;

int main()
{
	
	Cola c;
	c = Crear();
//	cout << c.tl << endl;
	
	
	Push(c,70); cout << Front(c) << endl;
//	cout << c.tl << endl;
	
	Push(c,90); cout << Front(c) << endl;
//	cout << c.tl << endl;
	
	Push(c,20); cout << Front(c) << endl;
//	cout << c.tl << endl;
	
//	Push(c,120); cout << Front(c) << endl;
//	cout << c.tl << endl;
	
	cout << endl << endl << endl; 
	
	Pop(c); cout << Front(c) << endl;
	cout << c.tl << endl;
	
	Pop(c); cout << Front(c) << endl;
	cout << c.tl << endl;
	
	Pop(c); cout << Front(c) << endl;
	cout << c.tl << endl;
	
	//Pop(c); cout << Front(c) << endl;
	//cout << c.tl << endl;
	
	Pop(c);
	
	return 0;
	
}
