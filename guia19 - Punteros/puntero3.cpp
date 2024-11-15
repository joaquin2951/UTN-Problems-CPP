#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main(int argc, char *argv[]) {
	
int vec[10];

srand(time(NULL));

for(int i = 0; i < 10; i++)
	vec[i] = rand()%100;

	
int *ptr_vec[10] = {NULL};

for(int i = 0; i < 10; i++)
	ptr_vec[i] = &vec[i];

for(int i = 0; i < 10; i++)
	cout << vec[i] << " "; 
cout << endl;

for(int i = 0; i < 10; i++)
	cout << *ptr_vec[i] << " "; 
	return 0;
}

