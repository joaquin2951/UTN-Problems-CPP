#ifndef COLA_H
#define COLA_H
//Interfaz - parte publica

#define tope 3
struct Cola
{
  int vec[tope];
	int tl;
};

Cola Crear();
void Push(Cola & c, int e);
void Pop(Cola & c);
int Front(Cola c);

#endif
