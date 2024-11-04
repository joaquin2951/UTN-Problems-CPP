#include <iostream>
#include <ctime>
#include "cuenta.h"

using namespace std;

void mostrarSaldo(Cuenta c){
	cout << "Saldo Actual: " << c.saldo << endl;
}
	
void Inicializar_Cuenta(Cuenta & c)
{
	cout << "numero cuenta: ";
	cin >> c.numero;
	cout << "saldo inicial: ";
	cin >> c.saldo;
	
	c.tl_mov = 0;
	
	mostrarSaldo(c);
}

void Depositar(Cuenta & c, float monto)
{
	c.saldo+= monto;
	mostrarSaldo(c);
	
	srand(time(NULL));
	
	c.movimientos[c.tl_mov].monto = monto;
	c.movimientos[c.tl_mov].tipo_transaccion = 'd';
	c.movimientos[c.tl_mov].fecha_operacion.dia = rand()%30;
	c.movimientos[c.tl_mov].fecha_operacion.mes = rand()%12 + 1;
	c.movimientos[c.tl_mov].fecha_operacion.anio = rand()%25 + 2000;
	
	c.tl_mov++;
}

void Extraer(Cuenta & c, float monto)
{
	if(c.saldo < monto)
		cout << "No se puede extraer esa cantidad." << endl;
	else
	{
		c.saldo = c.saldo - monto;
		srand(time(NULL));
		
		c.movimientos[c.tl_mov].monto = monto;
		c.movimientos[c.tl_mov].tipo_transaccion = 'e';
		c.movimientos[c.tl_mov].fecha_operacion.dia = rand()%30;
		c.movimientos[c.tl_mov].fecha_operacion.mes = rand()%12 + 1;
		c.movimientos[c.tl_mov].fecha_operacion.anio = rand()%25 + 2000;
		
		c.tl_mov++;
	}
		
	
	mostrarSaldo(c);
}

void ConsultarUltimosMov(Cuenta c)
{
	for(int i = 0; i < c.tl_mov; i++)
	{
		cout << "Movimiento " << i+1 << endl;
		cout << "Fecha de Operacion: ";
		cout << c.movimientos[i].fecha_operacion.dia << " / " << c.movimientos[i].fecha_operacion.mes << " / " <<  c.movimientos[i].fecha_operacion.anio << endl;
		cout << "Tipo de transacción: ";
		cout << c.movimientos[i].tipo_transaccion << endl;
		cout << "Monto de transaccion: ";
		cout << c.movimientos[i].monto << endl;
		
		cout << endl << endl;
	}
}
