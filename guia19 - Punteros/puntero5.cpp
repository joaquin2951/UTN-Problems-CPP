#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(int argc, char *argv[]) {
	
	char palabra[20];
	char *ptr_c;
	
	gets(palabra);
	
	ptr_c=&palabra[strlen(palabra)-1];
	
	for(int i=0;i<strlen(palabra);i++)
		cout<<*(ptr_c-i);
	
	
	
	return 0;
}

