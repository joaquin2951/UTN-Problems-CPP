//INTERFAZ
//PUBLICA
#ifndef CONTADOR_H
#define CONTADOR_H

struct contador{
	int valor;
};

contador crear(int valor);
void incrementar(contador & c, int pasos);
void decrementar(contador & c, int pasos);
int toInteger(const contador & c);

#endif
