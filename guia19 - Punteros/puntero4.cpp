#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	
	int vec[] = {1,2,3,4,4,7,8,9,5,4};
	int *ptr_num = NULL;
	
	for(int i = 0; i < (unsigned)sizeof(vec)/sizeof(int); i++)
	{
			ptr_num = &vec[i];
			cout << (unsigned)ptr_num  
				 << " | " << ptr_num << endl;
	}
	
	
	return 0;
}

