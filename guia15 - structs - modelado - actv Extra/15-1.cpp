#include <iostream>
#include <string>
using namespace std;

#define TAM 5

struct dia{
	int fecha;
	string nombre_dia;
};

struct semana{
	dia dias[7];
};

struct mes{
	string nombre;
	int num_mes;
	semana semanas[TAM];
};

struct Calendario{
	mes meses[12];
};

void cargarOctubre(Calendario & calendar);


int main(int argc, char *argv[]) {
	
	Calendario year2021;
	cargarOctubre(year2021);
	
	
	cout << year2021.meses[9].nombre << endl;
	cout << year2021.meses[9].num_mes << endl << endl;
	
	int diasMostrados = 0;
	
	for(int i = 0; i < 5; i++){
		
		
		for(int j = 0; j < 7; j++){
			
			if(diasMostrados < 31){
				cout << year2021.meses[9].semanas[i].dias[j].fecha << " " << year2021.meses[9].semanas[i].dias[j].nombre_dia << endl;
				diasMostrados++;
			}
			
			
		}
		
	}
	
	
	
	return 0;
}


void cargarOctubre(Calendario & calendar){
	
	int cantSemanas;
	//cantSemanas = 31 / 7;
		

	calendar.meses[9].nombre = "Octubre";
	calendar.meses[9].num_mes = 10;
		
		
	cantSemanas = 0;
	int dia = 0;//dia de la semana
		
	for(int totalDias = 1; totalDias <= 31; totalDias++){
	
			
				calendar.meses[9].semanas[cantSemanas].dias[dia].fecha = totalDias;
				
				if( cantSemanas == 0 and dia == 0)
					calendar.meses[9].semanas[cantSemanas].dias[dia].nombre_dia = "Lunes";
				else{
					switch(calendar.meses[9].semanas[cantSemanas].dias[dia-1].nombre_dia[0]){
					case 'L' :  calendar.meses[9].semanas[cantSemanas].dias[dia].nombre_dia = "Martes";  break;
					case 'J' :  calendar.meses[9].semanas[cantSemanas].dias[dia].nombre_dia = "Viernes";  break;
					case 'V' :  calendar.meses[9].semanas[cantSemanas].dias[dia].nombre_dia = "Sábado";  break;
					case 'S' :  calendar.meses[9].semanas[cantSemanas].dias[dia].nombre_dia = "Domingo";  break;
					case 'D' :  calendar.meses[9].semanas[cantSemanas].dias[dia].nombre_dia = "Lunes";  break;
					case 'M': 
										if(calendar.meses[9].semanas[cantSemanas].dias[dia-1].nombre_dia == "Martes")
												calendar.meses[9].semanas[cantSemanas].dias[dia].nombre_dia = "Miércoles";
										else
											calendar.meses[9].semanas[cantSemanas].dias[dia].nombre_dia = "Jueves";
										break;
					}
				}
				
				dia++;
				
				if(dia == 7){
					cantSemanas++;
					dia = 0;
				}
			
			
	}
		
		
}
