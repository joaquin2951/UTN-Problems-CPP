//Implementacion - Parte Privada

#include <iostream>
#include "COLA.h"

using namespace std;


Cola Crear()
{
	Cola c;
	c.tl = -1;
	return c;
}

void Push(Cola & c, int e)
{
	c.tl++;
	
	if(c.tl == tope)
		cout << "No se pueden agregar mas elem." << endl;
	else
		c.vec[c.tl] = e;
}

void Pop(Cola & c)
{
	if(c.tl < 0)
		cout << "No se pueden sacar mas elem." << endl;
	else
	{
		for(int i = 0; i < c.tl; i++)
		{
			c.vec[i] = c.vec[i+1];
		}
		c.tl--;
	}
		
}

int Front(Cola c)
{
	return c.vec[0];
}
