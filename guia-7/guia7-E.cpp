#include <iostream>
using namespace std;

float mayor(float a, float b);
float menor(float a, float b);

int MenMay(float a, float b, float c, float & maor , float & menor);

int main() {
	float a,b,c,may,men;
	cin>>a>>b>>c;
	
	
	
	cout<<"codigo: "<<MenMay(a,b,c,may,men)<<endl;
	if(MenMay(a,b,c,may,men)!=-1){
		cout<<"mayor: "<<may<<endl;
		cout<<"menor: "<<men<<endl;
	}
	

	
	
	return 0;
}

int MenMay(float a, float b, float c, float & max , float & min){
	int i = -1;
	
	if(!(a==b and b==c)){
		max = mayor( mayor(a,b) , mayor(b,c) );
		min = menor( menor(a,b) , menor(b,c) );
		if(a==b or b==c or c==a)
			i = 0;
		else 
			i = 1;
	}
		
	
	return i;
}

float mayor(float a, float b){
	
	float grande;
	if(a>=b)
			grande = a;
	else grande = b;
	
	return grande;
}
	
	
float menor(float a, float b){
	float chico;
	if(a>=b)
		chico = b;
	else chico = a;
	
	return chico;
	
}
