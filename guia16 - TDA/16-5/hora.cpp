#include <iostream>
#include "hora.h"

using namespace std;



Hora ponerAHora(int hs, int minutos, int seg)
{
	Hora h;
	h.hs = hs;
	h.min = minutos;
	h.seg = seg;
	
	return h;
}

void mostrar24(Hora h)
{
	cout << h.hs << ":" << h.min << ":" << h.seg << endl;
}

void mostrar12(Hora h)
{
	if(h.hs > 12)
		cout << h.hs - 12 << ":" << h.min << ":" << h.seg << " p.m." << endl;
	else
		cout << h.hs << ":" << h.min << ":" << h.seg << " a.m." << endl;
}

void adelantar(Hora & h, int minutos)
{
	h.min+=minutos;
	
	while(h.min >= 60)
	{
		h.min-=60;
		h.hs++;
	}
	
}

void atrasar(Hora & h, int minutos)
{
	h.min-=minutos;
	
	while(h.min < 0)
	{
		h.min++;
		h.seg-=60;
	}
}

int diferenciaEnSegundos(Hora h1, Hora h2)
{
	int seg1 = h1.min*60 + (h1.seg) + (h1.hs * 3600);
	int seg2 = h2.min*60 + (h2.seg) + (h2.hs * 3600);
	
	return seg1 > seg2? seg1 - seg2 : seg2 - seg1;
}

int diferenciaEnMinutos(Hora h1, Hora h2)
{
	int minutosH1 = h1.min + (h1.seg/60) + (h1.hs * 60);
	int minutosH2 = h2.min + (h2.seg/60) + (h2.hs * 60);
	
	return minutosH1 > minutosH2? minutosH1 - minutosH2 : minutosH2 - minutosH1;
}
