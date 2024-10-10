#include <iostream>
#include <string>

using namespace std;

struct Marcador{
	int golesTeamA;
	int golesTeamB;
};

struct Hora{
	int hs;
	int min;
	int seg;
};

struct Fecha{
	int dia;
	int mes;
	int anyo;
};

struct Llave{
	Fecha fecha_partido;
	Hora horario_partido;
	string ubicacion;
	string equipoA;
	string equipoB;
	Marcador marcador_final;
	int cant_equipos_cargados = 0;
};

struct Fixture{
	Llave llavesCuartos[4];
	Llave llavesSemis[2];
	Llave llaveFinal;
};


void cargarSemis(Fixture & mundial);
void cargarCuartos(Fixture & mundial);
void cargarResultadosCuartos(Fixture & mundial, const int num_llave);
void cargarResultadosSemis(Fixture & mundial, const int num_llave);
void cargarResultadosFinal(Fixture & mundial);
void informarResultados(const Fixture & mundial);

int main(int argc, char *argv[]) {
	
	Fixture qatar2022;
	
	cargarCuartos(qatar2022);
	
	cargarResultadosCuartos(qatar2022,0);
	cargarResultadosCuartos(qatar2022,1);
	cargarResultadosCuartos(qatar2022,2);
	cargarResultadosCuartos(qatar2022,3);
	
	cout << "Semis: " << endl;
	cout << qatar2022.llavesSemis[0].equipoA << " VS " << qatar2022.llavesSemis[0].equipoB << endl;
	cout << qatar2022.llavesSemis[1].equipoA << " VS " << qatar2022.llavesSemis[1].equipoB << endl;
//cargarSemis(qatar2022);
	
	cargarResultadosSemis(qatar2022,0);
	cargarResultadosSemis(qatar2022,1);
	
	cargarResultadosFinal(qatar2022);
	
	informarResultados(qatar2022);
	
	return 0;
}

void informarResultados(const Fixture & mundial){
	
	
	//calculo el ganador
	string ganador, segundo;
	
	if(mundial.llaveFinal.marcador_final.golesTeamA > 
		 mundial.llaveFinal.marcador_final.golesTeamB){
		
		ganador = mundial.llaveFinal.equipoA;
		segundo = mundial.llaveFinal.equipoB;
	}else{
		ganador = mundial.llaveFinal.equipoB;
		segundo = mundial.llaveFinal.equipoA;
	}
		
	
	
	cout << "GANADOR: " << ganador << endl;
	cout << "2do PUESTO: " << segundo << endl;
	
	
	
	
	
}
	
void cargarResultadosFinal(Fixture & mundial){
	cout << "goles de " << mundial.llaveFinal.equipoA << ": ";
	cin >> mundial.llaveFinal.marcador_final.golesTeamA;
	
	cout << "goles de " << mundial.llaveFinal.equipoB << ": ";
	cin >> mundial.llaveFinal.marcador_final.golesTeamB;
	
	string ganador;
	
	if(mundial.llaveFinal.marcador_final.golesTeamA > 
		 mundial.llaveFinal.marcador_final.golesTeamB){
		
		cout << "Ganador: " << mundial.llaveFinal.equipoA << endl;
		ganador = mundial.llaveFinal.equipoA;
		
	}else{
		cout << "Ganador: " << mundial.llaveFinal.equipoB << endl;
		ganador =  mundial.llaveFinal.equipoB ;
	}
	
	
	
}

void cargarResultadosSemis(Fixture & mundial, const int num_llave){
	
	cout << "goles de " << mundial.llavesSemis[num_llave].equipoA << ": ";
	cin >> mundial.llavesSemis[num_llave].marcador_final.golesTeamA;
	
	cout << "goles de " << mundial.llavesSemis[num_llave].equipoB << ": ";
	cin >> mundial.llavesSemis[num_llave].marcador_final.golesTeamB;
	
	string ganador;
	
	if(mundial.llavesSemis[num_llave].marcador_final.golesTeamA > 
		 mundial.llavesSemis[num_llave].marcador_final.golesTeamB){
		
		cout << "Ganador: " << mundial.llavesSemis[num_llave].equipoA << endl;
		ganador = mundial.llavesSemis[num_llave].equipoA;
		
	}else{
		cout << "Ganador: " << mundial.llavesSemis[num_llave].equipoB << endl;
		ganador =  mundial.llavesSemis[num_llave].equipoB;
	}
	
	
	
	if(mundial.llaveFinal.cant_equipos_cargados == 0){
		mundial.llaveFinal.equipoA = ganador;
		mundial.llaveFinal.cant_equipos_cargados++;
	}else{
		mundial.llaveFinal.equipoB = ganador;
		mundial.llaveFinal.cant_equipos_cargados++;
	}
	
	cout << "cantEquiposCargados para la FINAL: " << 	mundial.llaveFinal.cant_equipos_cargados << endl;
	
}




void cargarResultadosCuartos(Fixture & mundial, const int num_llave){
	
	cout << "goles de " << mundial.llavesCuartos[num_llave].equipoA << ": ";
	cin >> mundial.llavesCuartos[num_llave].marcador_final.golesTeamA;
	
	cout << "goles de " << mundial.llavesCuartos[num_llave].equipoB << ": ";
	cin >> mundial.llavesCuartos[num_llave].marcador_final.golesTeamB;
	
	string ganador;
	
	if(mundial.llavesCuartos[num_llave].marcador_final.golesTeamA > 
		mundial.llavesCuartos[num_llave].marcador_final.golesTeamB){
		
		cout << "Ganador: " << mundial.llavesCuartos[num_llave].equipoA << endl;
		ganador = mundial.llavesCuartos[num_llave].equipoA;
		
	}else{
		cout << "Ganador: " << mundial.llavesCuartos[num_llave].equipoB << endl;
		ganador =  mundial.llavesCuartos[num_llave].equipoB;
	}
	
	
	int posicionLLaveSgte;
	
	if(num_llave < 2){
		
			posicionLLaveSgte = 0;
		
	}else{
		
			posicionLLaveSgte = 1;
		
	}
	
	if(mundial.llavesSemis[posicionLLaveSgte].cant_equipos_cargados == 0){
		mundial.llavesSemis[posicionLLaveSgte].equipoA = ganador;
		mundial.llavesSemis[posicionLLaveSgte].cant_equipos_cargados++;
	}else{
		mundial.llavesSemis[posicionLLaveSgte].equipoB = ganador;
		mundial.llavesSemis[posicionLLaveSgte].cant_equipos_cargados++;
	}
			
	cout << "cantEquiposCargados para SEMIS: " << 	mundial.llavesSemis[posicionLLaveSgte].cant_equipos_cargados << endl;
	
}


void cargarSemis(Fixture & mundial){
		int llave;
		
		for(llave = 0; llave < 2; llave++){
			
			cout << "Fecha" << endl;
			cout << "dia: "; cin >> mundial.llavesSemis[llave].fecha_partido.dia;
			cout << "mes: "; cin >> mundial.llavesSemis[llave].fecha_partido.mes;
			cout << "anyo: "; cin >> mundial.llavesSemis[llave].fecha_partido.anyo;
			
			cout << "Hora" << endl;
			cout << "hs: "; cin >> mundial.llavesSemis[llave].horario_partido.hs;
			cout << "min: "; cin >> mundial.llavesSemis[llave].horario_partido.min;
			cout << "seg: "; cin >> mundial.llavesSemis[llave].horario_partido.seg;
			
			cin.ignore(100,'\n');
			cout << "Ubicacion: "; getline(cin,mundial.llavesSemis[llave].ubicacion);
			
		}
}
	
void cargarCuartos(Fixture & mundial){
	
	int llave;
	
	for(llave = 0; llave < 4; llave++){
		
		cout << "Ingrese el nombre de los equipos que juegan en la llave " << llave << endl;
		cout << "Equipo A: "; getline(cin,mundial.llavesCuartos[llave].equipoA);
		cout << "Equipo B: "; getline(cin,mundial.llavesCuartos[llave].equipoB);
		
		/*
		cout << "Fecha" << endl;
		cout << "dia: "; cin >> mundial.llavesCuartos[llave].fecha_partido.dia;
		cout << "mes: "; cin >> mundial.llavesCuartos[llave].fecha_partido.mes;
		cout << "anyo: "; cin >> mundial.llavesCuartos[llave].fecha_partido.anyo;
		
		cout << "Hora" << endl;
		cout << "hs: "; cin >> mundial.llavesCuartos[llave].horario_partido.hs;
		cout << "min: "; cin >> mundial.llavesCuartos[llave].horario_partido.min;
		cout << "seg: "; cin >> mundial.llavesCuartos[llave].horario_partido.seg;
		
		cin.ignore(100,'\n');
		cout << "Ubicacion: "; getline(cin,mundial.llavesCuartos[llave].ubicacion);
		*/
		
	}
	
	
}
