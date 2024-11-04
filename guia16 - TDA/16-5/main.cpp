#include <iostream>
#include "cuenta.h"
#include <windows.h>

#define MAXcli 2

using namespace std;



int main()
{
	
	Cuenta clientes[MAXcli];
	
	int tl_cli = 0;
	char option;
	
	/*
	Inicializar_Cuenta(clientes[0]);
	
	Depositar(clientes[0],500.20);
	
	Extraer(clientes[0],700);
	Extraer(clientes[0],222.33);
	
	
	ConsultarUltimosMov(clientes[0]);
	
	*/
	
	while(option != 'X')
	{
		
		system("cls");
		
		cout << "1. Inicializar Cliente" << endl;
		cout << "2. Depositar" << endl;
		cout << "3. Extraer" << endl;
		cout << "4. Consultar Saldo" << endl;
		cout << "5. Consultar Ultimos Mov" << endl;
		
		cin >> option;
		int d;
		
		switch(option)
		{
		case '1': if(tl_cli < MAXcli)
		{
			Inicializar_Cuenta(clientes[tl_cli]);
			tl_cli++;
		}
		else 
								 cout << "No se pueden crear mas clientes."; 
		break;
		
		case '2': 
			
			cout << "En que numero de cliente depositar? ";
			cin >> d;
			if(d < tl_cli){
				float monto;
				cout << "Monto? "; cin >> monto;
				Depositar(clientes[d], monto);
			}
			else
				 cout << "no existe ese cliente." << endl;
			break;
			
			
		case '3': 
			
			cout << "En que numero de cliente extraer? ";
			cin >> d;
			if(d < tl_cli){
				float monto;
				cout << "Monto? "; cin >> monto;
				Extraer(clientes[d], monto);
			}
			else
				 cout << "no existe ese cliente." << endl;
			break;
			
			
		case '4': 
			
			cout << "En que numero de cliente ver saldo? ";
			cin >> d;
			if(d < tl_cli)
				mostrarSaldo(clientes[d]);
			else
				cout << "no existe ese cliente." << endl;
			break;
			
			
		case '5':
			
			cout << "En que numero de cliente consultar mov? ";
			cin >> d;
			if(d < tl_cli){
				ConsultarUltimosMov(clientes[d]);
			}
			else
				 cout << "no existe ese cliente." << endl;
			break;
			
			
		}
		
		
		system("pause");
		
	}
	
	
	
	
	
	
	
	
	return 0;
}
