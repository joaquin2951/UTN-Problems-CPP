#ifndef CUENTA_H
#define CUENTA_H
struct Fecha{
	int dia;
	int mes;
	int anio;
};

struct Movimiento{
		Fecha fecha_operacion;
		char tipo_transaccion;
		float monto;
};

struct Cuenta{
	int numero;
	float saldo;
	Movimiento movimientos[10];
	int tl_mov;
};

void Inicializar_Cuenta(Cuenta & c);
void Depositar(Cuenta & c, float monto);
void Extraer(Cuenta & c, float monto);
void ConsultarUltimosMov(Cuenta c);
void mostrarSaldo(Cuenta c);
#endif
