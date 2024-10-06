#include <iostream>
using namespace std;
//GUIA 12 EJERCICIO 9


#define A 3 //define cantidad de articulos
#define S 4 //define cantidad de sucursales

void imprimir_matriz(const int M[][A], const int filas, const int columnas);
void cantVendidaEmpresa(const int M[][A], const int filas, const int columnas);
int unidadesVendidasPorSucursal(const int M[][A], const int columnas, const int sucursalID);
int articuloVEndidoPorSucursal(const int M[][A], const int sucursalID, const int articuloID);
int sucursalQueVendioMasElArticulo(const int M[][A], const int filas, const int articuloID);

int main() {
	const int sucursales = S, articulos = A;  
	int matriz[sucursales][articulos] = {0},  cod_sucursal, cod_articulo, unid_vendidas;
	
	while(cod_sucursal != 0){
		cout << "ingrese el codigo de sucursal: "; cin >> cod_sucursal;
		
		if(cod_sucursal > 0 and cod_sucursal <= sucursales ){
			cout << "ingrese el codigo del articulo: "; cin >> cod_articulo; 
			if(cod_articulo > articulos or cod_articulo < 1){
				cout << "codigo de articulo inexistente" << endl << endl;
			}else{
				cout << "ingrese las unidades vendidas del articulo " << cod_articulo << ": "; cin >> unid_vendidas;
				matriz[cod_sucursal-1][cod_articulo-1] = unid_vendidas;
				cout << endl;
			}
		}else if(cod_sucursal == 0){
			cout << endl << "finalizando ingreso de datos" << endl;
		}else if(cod_sucursal < 0 or cod_sucursal > sucursales){
			cout << endl << "sucursal inexistente, intente nuevamente. " << endl << endl;
		}
		   
		
	}
	
	imprimir_matriz(matriz,sucursales,articulos); cout << endl << endl;
	cantVendidaEmpresa(matriz,sucursales,articulos);
	cout << "El total de unidades vendidas por la sucursal " << 3 << " es de: " << unidadesVendidasPorSucursal(matriz,articulos,3) << endl;
	cout << "La cantidad vendida de por la sucursal " << 1 << " del articulo " << 2 << 
					" es de : " << articuloVEndidoPorSucursal(matriz,1,2) << endl;
	
	cout << "La sucursal que vendio mas unidades del articulo " << 1 << " es la sucursal " <<
		       sucursalQueVendioMasElArticulo(matriz,S,1) << endl;
	
	
	return 0;
}


int sucursalQueVendioMasElArticulo(const int M[][A], const int filas, const int articuloID){
	int sucursalMax = 0;
	
	
	for(int fil = 1 ; fil < filas; fil++){
		
		if( M[fil-1][articuloID] < M[fil][articuloID] )
			sucursalMax = fil;
		
	}
	
	
	return sucursalMax+1;
}

int articuloVEndidoPorSucursal(const int M[][A], const int sucursalID, const int articuloID){
	return M[sucursalID-1][articuloID-1];
}

int unidadesVendidasPorSucursal(const int M[][A], const int columnas, const int sucursalID){
	int unidades = 0;
	for(int col = 0; col < columnas; col++){
		unidades = unidades + M[sucursalID-1][col];
	}
	
	return unidades;
}

void cantVendidaEmpresa(const int M[][A], const int filas, const int columnas){
	int cantVend;
	for(int col = 0; col < columnas; col++){
		cantVend = 0;
	
		for(int fil = 0; fil < filas; fil++){
		
			cantVend = cantVend + M[fil][col];
		}
		cout << "Cantidad total vendida del articulo " << col + 1 << " por la empresa: " << cantVend << endl;
	}
}

void imprimir_matriz(const int M[][A], const int filas, const int columnas){
	cout << "sucursales| " << "a1     a2     a3" << endl;
	for(int fil = 0 ; fil < filas; fil++){
		cout << "Sucursal " << fil+1 << "| ";
		for(int col = 0; col < columnas; col++)
			cout << M[fil][col] << "      "; 
			
		cout << endl;
	}
}
