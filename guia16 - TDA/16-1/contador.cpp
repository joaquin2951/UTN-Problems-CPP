//IMPLEMENTACION
//PRIVADA

#include "contador.h"




contador crear(int valor){
	contador C;
	C.valor = valor;
	return C;
}
	
void incrementar(contador & c, int pasos){
	c.valor+=pasos;
}
	
void decrementar(contador & c, int pasos){
	c.valor-=pasos;
}
	
int toInteger(const contador & c){
	return c.valor;
}
