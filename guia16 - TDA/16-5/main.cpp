#include <iostream>
#include "hora.h"

using namespace std;

#define cantEventos 3

struct Evento{
	string nombreEvento;
	int duracionEstimadaEnMinutos;
};

void cargarEvento(Evento & e, string nombre, int duracion);

int main()
{
	

	Evento eventos[cantEventos];
	Hora inicioPrimerEvento;
	
	cargarEvento(eventos[0],"Evento 1", 120);
	cargarEvento(eventos[1],"Evento 2", 120);
	cargarEvento(eventos[2],"Evento 3", 120);
	
	inicioPrimerEvento = ponerAHora(12,00,00);
	
	for(int event = 0; event < cantEventos; event++)
	{
		cout << eventos[event].nombreEvento << endl;
		cout << "Inicio: "; mostrar12(inicioPrimerEvento);
		adelantar(inicioPrimerEvento,eventos[event].duracionEstimadaEnMinutos);
		cout << "Fin: "; mostrar12(inicioPrimerEvento); 
	}
	
	
	
	/*
	Hora h1, h2;
	
	h1 = ponerAHora(6,30,50);
	h2 = ponerAHora(13,55,50);
	
	mostrar12(h2); 	mostrar24(h2);

	adelantar(h2,130);
	atrasar(h1,100);
	
	mostrar12(h2); mostrar12(h1);
	
	cout << diferenciaEnMinutos(h1,h2) << " min" << endl;
	cout << diferenciaEnSegundos(h1,h2) << " seg" << endl;
	*/
	
	
	return 0;
}

void cargarEvento(Evento & e, string nombre, int duracion){
	e.nombreEvento = nombre;
	e.duracionEstimadaEnMinutos = duracion;
}
