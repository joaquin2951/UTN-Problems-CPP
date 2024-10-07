#include <iostream>
#include <string>
using namespace std;

string nuevaFecha(string fecha);

int main(int argc, char *argv[]) {
	
	string fecha; //MMDDYYYY
	
	cin >> fecha;
	
	fecha = nuevaFecha(fecha);
	cout << fecha << endl;
	
	
	return 0;
}

string nuevaFecha(string fecha){
	
	string nuevaFecha;
	string mes;
	
	
	
	switch(atoi(((fecha.substr(0,2)).c_str()))){
		case 1: mes = "enero"; break;
		case 2: mes = "febrero"; break;
		case 3: mes = "marzo"; break;
		case 4: mes = "abril"; break;
		case 5: mes = "mayo"; break;
		case 6: mes = "junio"; break;
		case 7: mes = "julio"; break;
		case 8: mes = "agosto"; break;
		case 9: mes = "septiembre"; break;
		case 10: mes = "octubre"; break;
		case 11: mes = "noviembre"; break;
		case 12: mes = "diciembre"; break;
		default: mes = "| mes incorrecto |";
	}
	
	nuevaFecha = fecha.substr(2,2) + " de " + mes + " del " + fecha.substr(4,4);
	
	return nuevaFecha;
}
