#ifndef FECHA_H
#define FECHA_H

struct Fecha
{
		int dia;
		int mes;
		int anio;
};

Fecha cargarFecha(int d, int m, int a);
int dia(Fecha f);
int mes(Fecha f);
int anio(Fecha f);
int esValida(Fecha f);
int diferenciaFecha(Fecha f1, Fecha f2);
int diaSemanaFecha(Fecha f);
void mostrarFechaEuropea(Fecha f);
void mostrarFechaAmericana(Fecha f);


#endif
