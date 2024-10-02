#include <iostream>
using namespace std;

bool todos_distintos(int vec[], int TL);

int main() {
	
	int vec[] = {1,2,3,4,5}; // TL = sizeof(vec) / 4
	int vec2[] = {2,2,2,6};
	int vec3[] = {1,-9,5,2};
	int vec4[] = {9,9,9,9,9,9};
	
	cout << boolalpha << todos_distintos(vec,sizeof(vec)/4) << endl;
	cout << boolalpha << todos_distintos(vec2,sizeof(vec2)/4) << endl;
	cout << boolalpha << todos_distintos(vec3,sizeof(vec3)/4) << endl;
	cout << boolalpha << todos_distintos(vec4,sizeof(vec4)/4) << endl;
	//cout << sizeof(vec)/4;
	
	return 0;
}


bool todos_distintos(int vec[], int TL){
	
	for(int i = 0; i < TL; i++)
		for(int j = i+1; j < TL ; j++ )
			if(vec[i] == vec[j])
				return false;
		
	
	return true;
}
