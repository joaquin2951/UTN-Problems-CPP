#include <iostream>
using namespace std;
#define SIZE_NAME 10
#define SIZE 10

struct picture_info
{
		char name[SIZE_NAME];
		int date_time;
};

int main(int argc, char *argv[]) {
	picture_info pictures[SIZE];
	picture_info *ptr_pic[SIZE];
	
	pictures[5].date_time = 125;
	
	for(int i = 0; i < SIZE; i++)
	{
		ptr_pic[i] = &pictures[i];
	}
	
	
	cout << &pictures[5] << endl;
	cout << ptr_pic[5] << endl;
	
	cout << &(*ptr_pic[5]).name << endl;
	cout << &(*ptr_pic[5]).date_time << endl;
	
	return 0;
}

