#include <iostream>
using namespace std;


int cantDig(int);

	
int main() {
	
	cout<<"cantDig = "<< cantDig(789) <<endl;
	
	return 0;
}


int cantDig(int number){
	
	// 10000
	int cifras = 0;
	
	if(number < 0)
		number = number * -1;
	
	if (number != 0) 
	{
		
		while((number) > 0){
			cifras++;
			number = number / 10;
		}
		
	}else
			cifras++;
	
	
	
	
	
	return cifras;
}
