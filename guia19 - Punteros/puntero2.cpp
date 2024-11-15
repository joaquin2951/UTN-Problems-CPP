#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	float numeros[] = {0.1,0.2,0.3,0.4,0.5};
	
	float *ptr_num = NULL;
	
	
for(int i = 0; i < 5; i++)
	cout << numeros[i] << " ";

cout << endl;

ptr_num = numeros;

cout << "direccion: " << ptr_num << endl;

for(int i=0; i < 5; i++)
	cout << *(ptr_num+i) << " ";

cout << endl;
cout << "direccion pnum+3: " << ptr_num + 3 << endl;
cout << "valor en direccion que apunta pnum+3: " << *(ptr_num+3) << endl;


ptr_num = &numeros[3];

cout << ptr_num - 2 << endl;
cout << *(ptr_num-2) << endl;

	return 0;
}

