#include <iostream>
using namespace std;

void mostrarvector(const int vec[], const int TL);
int combinarVectores(const int vec1[], const int TL1, const int vec2[], const int TL2, int vec3[]);
void ordenarVector(int vec[], const int TL);

int main() {
	const int TF = 500;
	int vec1[] = { 1 , 3, 5 ,6 ,7, 33, -30 } , vec2[] = { -4,-50,3, 6, 9 , 10 , 20}, vec3[TF];
	int TL1 = sizeof(vec1) / 4, TL2 = sizeof(vec2)/4, TL3;
	
	TL3 = combinarVectores(vec1,TL1,vec2,TL2, vec3);
	
	cout << "vector 1 :   "; mostrarvector(&vec1[0], TL1); cout << endl;
	cout << "vector 2 :   "; mostrarvector(&vec2[0], TL2); cout << endl << endl << endl;
	
	cout << "vectores combinados:   "; mostrarvector(&vec3[0],TL3); cout << endl << endl;
	
	cout << "vector ordenado:   "; ordenarVector(vec3,TL3); mostrarvector(vec3,TL3);
	
	return 0;
}

void ordenarVector(int vec[], const int TL){
	for(int i = 0; i < TL-1; i++){
		
		for(int j = 1; j < TL; j++){
		
			if( vec[j] < vec[j-1] ){
				swap(vec[j], vec[j-1]);
			}
			
		}
	}
}

int combinarVectores(const int vec1[], const int TL1, const int vec2[], const int TL2, int vec3[]){
	int TL3 = TL1 + TL2;
	for(int i = 0; i < TL3; i++){
		if(i < TL1){
			vec3[i] = vec1[i];
		}else
			 vec3[i] = vec2[i-TL1];
	}
		
	return TL3;
}
	
void mostrarvector(const int vec[], const int TL){
	for(int i = 0; i < TL; i++){
		cout << vec[i] << " ";
	}
}
