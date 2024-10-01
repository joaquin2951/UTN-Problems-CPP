#include <iostream>
using namespace std;



void EdadActual(int dia, int mes, int anio,int & edad, int dayToday, int monthToday, int yearToday){
	
	
	if(	(mes < monthToday) or (mes == monthToday and dia <= dayToday) )
			edad = yearToday - anio;
	else
			edad = yearToday - anio - 1;
	
}


int main() {
	int dia,mes,anio, edad;
	cin>>dia>>mes>>anio;
	
	EdadActual(dia,mes,anio,edad,20,5,2024);
	
	cout << edad << endl;
	
	
	

	return 0;
}

