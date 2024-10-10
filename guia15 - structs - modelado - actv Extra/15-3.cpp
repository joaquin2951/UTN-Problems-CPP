#include <iostream>
#include <ctime>
#include <cstdlib>
#include <windows.h>
using namespace std;

#define TAM_Facturas 5
struct Horario{
	int hora; // 0 a 23
	int minutos; // 0 a 59
};

struct Vehiculo{
	char tipo_vehiculo;//'M', 'A', 'C', 'P'
	string patente;
};

struct Arribo{
	Horario horario_arribado;
	Vehiculo Vehiculo_arribado;
};

struct Ticket{
	
	Arribo vehiculo_arribado;
	float monto;
	
};



struct Cabina{
	Ticket tickets_facturados[TAM_Facturas];
	int cantTickets_facturados = 0;//cant ticket facturados. TL.
};


struct Tunel{
	Cabina cabinas[3];
};


Arribo generarArribo(string patente);
void atenderArribo(const Arribo arribo, const int num_Cabina, char metodoPago, Tunel & tunel);
float totalDescuentosAplicados(const Tunel tunelAEDD);
float totalFacturado(const Tunel tunelAEDD);


int main(int argc, char *argv[]) {
	
	Tunel tunelAEDD;
	
	
	Arribo a1,a2,a3,a4;
	
	a1 = generarArribo("A2 132 ABC");
	Sleep(1000);
	a2 = generarArribo("B3 737 HCZ");
	
	
	atenderArribo(a1,0,'1',tunelAEDD);
	atenderArribo(a2,0,'2',tunelAEDD);
	
	cout << "A1: " << endl;
	cout << "Hora: " << a1.horario_arribado.hora << " |  minutos: " << a1.horario_arribado.minutos << endl;
	cout << "Patente: " << a1.Vehiculo_arribado.patente << " |  Tipo: " << a1.Vehiculo_arribado.tipo_vehiculo << endl;

	cout << endl;
	
	cout << "A2: " << endl;
	cout << "Hora: " << a2.horario_arribado.hora << " |  minutos: " << a2.horario_arribado.minutos << endl;
	cout << "Patente: " << a2.Vehiculo_arribado.patente << " |  Tipo: " << a2.Vehiculo_arribado.tipo_vehiculo << endl;
	
	
	cout << endl << endl;
	
	cout << "Cabina 0: " << endl;
	cout << "Total tickets: " << tunelAEDD.cabinas[0].cantTickets_facturados << endl;
	cout << "ticket 1: " << tunelAEDD.cabinas[0].tickets_facturados[0].monto << endl;
	cout << "ticket 2: " << tunelAEDD.cabinas[0].tickets_facturados[1].monto << endl;
	
	cout << "Total de descuentos: " << totalDescuentosAplicados(tunelAEDD) << "$" << endl;
	cout << "Total Facturado: " << totalFacturado(tunelAEDD) << "$" << endl;
	
	return 0;
}

float totalFacturado(const Tunel tunelAEDD){
	float total = 0.0;
	
	
	for(int cab = 0; cab < 3; cab++){//recorro cabinas
		for(int ticket = 0; ticket < tunelAEDD.cabinas[cab].cantTickets_facturados; ticket++){//recorro vec TicketsFacturados
			
			total+= tunelAEDD.cabinas[cab].tickets_facturados[ticket].monto;
			
			
		}
	}
	
	
	
	
	return total;
}


float totalDescuentosAplicados(const Tunel tunelAEDD){
	float total = 0.0;
	
	//recorro cada cabina del tunel
	for(int cabina = 0; cabina < 3; cabina++){
	
		
		//recorro todos los TICKETS de la cabina que estoy recorriendo
		for(int ticket = 0; ticket < tunelAEDD.cabinas[cabina].cantTickets_facturados; ticket++){
			
			//obtengo el tipo de Vehiculo
			char tipoVehiculo = tunelAEDD.cabinas[cabina].tickets_facturados[ticket].vehiculo_arribado.Vehiculo_arribado.tipo_vehiculo;
			
			//veo el descuento según que tipo es
			float montoPagadoPorVehiculo = tunelAEDD.cabinas[cabina].tickets_facturados[ticket].monto;//monto pagado por el vehicula que está siendo estudiado.
				
			switch(tipoVehiculo){//verificamos qué tipo de vehiculo es.
				case 'M': total+= (50.0 - montoPagadoPorVehiculo);  break;//nos da el total del descuento que se le hizo al vehiculo
				case 'A': total+= (120.0 - montoPagadoPorVehiculo); break;
				case 'C': total+= (245.0 - montoPagadoPorVehiculo); break;
				case 'P': total+= (400.0 - montoPagadoPorVehiculo); break;
			}
			
			
			
		}//fin recorrido tickets
		
	}//fin recorrido cabinas
	
	
	return total;
}



void atenderArribo(const Arribo arribo, const int num_Cabina, const char metodoPago, Tunel & tunel){
	//num_cabina aceptado está en el rango [0,2] y metodoPago aceptado pertenece a [1,2]
	
	
	Ticket nuevoTicket;
	float monto = 0.0;
	nuevoTicket.vehiculo_arribado = arribo;
	
	switch(nuevoTicket.vehiculo_arribado.Vehiculo_arribado.tipo_vehiculo){
		case 'M': monto+= 50.0;  break;
		case 'A': monto+= 120.0; break;
		case 'C': monto+= 245.0; break;
		
		case 'P': monto = 400.0; 
								if(nuevoTicket.vehiculo_arribado.horario_arribado.hora >= 0 && nuevoTicket.vehiculo_arribado.horario_arribado.hora < 3){
									//entre las 00 y las 2:59
									monto = monto - (monto * 0.10); // 10% descuento
								
								}
								else if(nuevoTicket.vehiculo_arribado.horario_arribado.hora == 3 && nuevoTicket.vehiculo_arribado.horario_arribado.minutos == 0){
									monto = monto - (monto * 0.10); // 10% descuento
								}
							break;
	}
	//metodoPago 1 --> contado (5% descuento) ,  metodoPago 2 --> tarjetaTunel (15%)   NO INCLUYE A VEHICULOS TIPO 'P'
	
	switch(metodoPago){
		
		case '1':   if(nuevoTicket.vehiculo_arribado.Vehiculo_arribado.tipo_vehiculo != 'P') 
									monto = monto - (monto * 0.05);//descuento de 5%
								break;
							
		case '2':  	if(nuevoTicket.vehiculo_arribado.Vehiculo_arribado.tipo_vehiculo != 'P') 
									monto = monto - (monto * 0.15);//descuento de 5%
								break;
	
	}
	
	
	nuevoTicket.monto = monto; //cargamos el monto final
	
	
	tunel.cabinas[num_Cabina].tickets_facturados[tunel.cabinas[num_Cabina].cantTickets_facturados] = nuevoTicket;
	
	tunel.cabinas[num_Cabina].cantTickets_facturados++;
}




Arribo generarArribo(string patente){
	
	srand(time(NULL));
	
	Arribo nuevoArribo;
	nuevoArribo.Vehiculo_arribado.patente = patente;
	
	int tipoVehiculo;
	tipoVehiculo = rand() % 4;
	
	switch(tipoVehiculo){
		case 0: nuevoArribo.Vehiculo_arribado.tipo_vehiculo = 'M'; break;
		case 1: nuevoArribo.Vehiculo_arribado.tipo_vehiculo = 'A'; break;
		case 2: nuevoArribo.Vehiculo_arribado.tipo_vehiculo = 'C'; break;
		case 3: nuevoArribo.Vehiculo_arribado.tipo_vehiculo = 'P'; break;
	}
	
	int hora, min;
	
	hora = rand() % 24;
	min = rand() % 60;
	
	nuevoArribo.horario_arribado.hora = hora;
	nuevoArribo.horario_arribado.minutos = min;
	
	
	return nuevoArribo;
}
