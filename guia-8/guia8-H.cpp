#include <iostream>
#include <windows.h>

using namespace std;

void CuentaRegresiva(int segundos);

int main() {
	
	CuentaRegresiva(35);
	
	
	return 0;
}
//Si faltan m�s de 10 segundos, s�lo hay que informar la cantidad de segundos que faltan 
//para el despegue, cada 10 segundos, 
//cuando el d�gito unidad es 0 (y hay que esperar la cantidad de segundos que corresponda).

void CuentaRegresiva(int segundos){
	
	if(segundos == 0)
		cout << "DESPEGUE" << endl;
	
	else 
		if(segundos <= 10){
		cout << segundos << endl;
		Sleep(1000);
		CuentaRegresiva(segundos-1);
	}else
			 {
				cout << segundos - (segundos%10) << endl;
				Sleep(10000);
				CuentaRegresiva(segundos - segundos%10 -10);
		}
	
	
}
