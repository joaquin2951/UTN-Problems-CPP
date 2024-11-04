#ifndef HORA_H
#define HORA_H
struct Hora{
	int hs;
	int min;
	int seg;
};

Hora ponerAHora(int hs, int minutos, int seg);
void mostrar24(Hora h);
void mostrar12(Hora h);
void adelantar(Hora & h, int minutos);
void atrasar(Hora & h, int minutos);
int diferenciaEnMinutos(Hora h1, Hora h2);
int diferenciaEnSegundos(Hora h1, Hora h2);
#endif
