#include <iostream>
using namespace std;

int main() {
	
	const int TL = 5;
	int vec[TL], max;
	
	cin >> vec[0];
	max = vec[0];
	
	for(int i = 1 ; i < TL; i++){
		cin >> vec[i];
		if(max < vec[i])
			max = vec[i];
	}
	
	cout << "el numero mas grande del vector es: " << max << endl;
	
	return 0;
}

