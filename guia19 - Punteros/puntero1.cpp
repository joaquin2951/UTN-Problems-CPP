#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	//inicializar punteros con NULL
	//void ptr no se puede desreferenciar
	//int *arrPtr = &arr[0];
	
	float num1 = 3.1415926, num2 = 0.12345;
	
	float *ptr_num;
	
	ptr_num = &num1;
	
	cout << *ptr_num << endl;
	
	ptr_num = &num2;
	
	cout << *ptr_num << endl;
	
	cout << "Dir num2 : " << (unsigned) &num2 << endl;
	cout << "Dir ptr_num : " << (unsigned) ptr_num << endl;
	
	
	
	return 0;
}

