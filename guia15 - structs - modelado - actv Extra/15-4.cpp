#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

struct Producto{
	string marca;
	string descripcion;
	float precio;
};

struct Item{
	int cod_prod;
	int cantidad;
};

struct Pedidos{
	Item items[30];
	int cod_cli;
	int cant_items = 0; //TL del arreglo items[]
};

struct Caja{
	Pedidos pedidos[400];
	int TL = 0;//es el TL del arreglo pedidos[]
};

struct Venta{
	Pedidos pedido;
	float total_facturado;
};

struct Supermercado{
	Caja cajas[15];
	Venta ventas[1000];
	int TL = 0; //es el TL del arreglo ventas;
};


void agregarPedidoEnCaja(Pedidos pedido,const int numCaja, Supermercado & super);
void atenderSiguientePedido(Supermercado & super);
float facturarPedido(const Pedidos pedido);
float precioItem(int cod_producto, int cantidad_producto);
void marcaMasCara(const Producto matriz[20][100]);
void cajaMasLenta(const Caja cajas[]);
Producto matriz_prod[20][100]; //cod producto es la concatenacion del numero de fila seguido del numero de columna
//Cada elemento de la matriz corresponde a un PRODUCTO definido según su marca(string), descripcion(string) y precio Unitario (float)


int main(int argc, char *argv[]) {
	
	
	Supermercado COTO;
	
	srand(time(NULL));
	
	
	for(int i = 0; i < 20; i ++){
		for(int j = 0; j < 100; j++){
			matriz_prod[i][j].precio = rand() % 500 + 1;
		}
	}
	
	
	Pedidos p1, p2, p3;
	p1.cant_items = 3;
	p1.items[0].cantidad = 3; p1.items[0].cod_prod = 99;
	p1.items[1].cantidad = 10; p1.items[1].cod_prod = 1999;
	p1.items[2].cantidad = 5; p1.items[2].cod_prod = 155;
	
	p2.cant_items = 1;
	p2.items[0].cantidad = 10; p2.items[0].cod_prod = 180;
	
	p3.cant_items = 2;
	p3.items[0].cantidad = 7; p3.items[0].cod_prod = 400;
	p3.items[1].cantidad = 10; p3.items[1].cod_prod = 1515;
	

	agregarPedidoEnCaja(p1,1,COTO);
	agregarPedidoEnCaja(p2,1,COTO);
	agregarPedidoEnCaja(p3,13,COTO);
	
	cajaMasLenta(COTO.cajas);
	
	cout << "COTO.cajas[0].TL = " << COTO.cajas[0].TL << endl;
	cout << "COTO.cajas[1].TL = " << COTO.cajas[1].TL << endl;
	cout << "COTO.cajas[2].TL = " << COTO.cajas[2].TL << endl;
	cout << "COTO.cajas[3].TL = " << COTO.cajas[3].TL << endl;
	cout << "COTO.cajas[12].TL = " << COTO.cajas[12].TL << endl;
	cout << "COTO.cajas[14].TL = " << COTO.cajas[14].TL << endl;
	
	
	atenderSiguientePedido(COTO);//atiende p1 y p3
	cout << endl;
	atenderSiguientePedido(COTO);//atiende p2
	cout << endl; cout << endl;
	
	marcaMasCara(matriz_prod);

	
	
	return 0;
}

//Defina e implemente la función cajaMasLenta() que devuelve el NÚMERO 
//IDENTIFICADOR de la CAJA que tiene la COLA DE PEDIDOS más larga
void cajaMasLenta(const Caja cajas[]){
	
	int ID = 0;
	int cantPedidos = cajas[ID].TL;
	
	for(int i = 1; i < 15; i++){//recorro cajas
		
		if(cantPedidos < cajas[i].TL){
			ID = i;
			cantPedidos = cajas[i].TL;
		}
			
	}
	
	
	cout << "Caja más lenta: Caja " << ID << " con " << cantPedidos << " Pedidos" << endl;
	
}


void marcaMasCara(const Producto matriz[20][100]){
	
	float precioMasCaro = matriz[0][18].precio;
	int filaMasCara = 0, colMasCara = 18;
	
	if(precioMasCaro < matriz[1][8].precio){
		precioMasCaro = matriz[1][8].precio;
		filaMasCara = 1, colMasCara = 8;
	}
			

	//recorro toda la fila 18
	for(int col = 0; col < 100; col++){
		
		if(precioMasCaro < matriz[18][col].precio){
			precioMasCaro = matriz[18][col].precio;
			filaMasCara = 18, colMasCara = col;
		}
			
	}
	
	
	cout << "El prod más caro tiene codigo: " << filaMasCara << colMasCara << " y valor: " << matriz_prod[filaMasCara][colMasCara].precio << endl;
	
}

float precioItem(int cod_producto, int cantidad_producto){
	int concatenacion;
	float precio = 0.0;
	bool encontrado = false;
	int fil = 0;
	int col;
	
	while(fil < 20 && encontrado == false){
		col = 0;
		while(col < 100 && encontrado == false){
			
			if(col < 10)
				concatenacion = (fil * 10) + col;
			else
				concatenacion = (fil * 100) + col;
			
			if(concatenacion == cod_producto){
				precio = (float) matriz_prod[fil][col].precio * (float) cantidad_producto;
				encontrado = true;
			}
			
			col++;
		}
		fil++;
	}
	
	return precio;
}

float facturarPedido(const Pedidos pedido){
	float total = 0.0;
	int cod_producto;
	int cantidad_producto;
		
	for(int i = 0; i < pedido.cant_items; i++){//recorro todos los items (productos) que haya
		
		cod_producto = pedido.items[i].cod_prod;//asigno codigo del producto
		cantidad_producto = pedido.items[i].cantidad;//asigno la cantidad que me llevo de ese producto
		
		total = total + precioItem(cod_producto, cantidad_producto);
		
		
	}
	
	
	return total;
}


void atenderSiguientePedido(Supermercado & super){
	
	//genera una VENTA para cada caja cuya COLA DE PEDIDOS tenga PEDIDOS pendientes de ser atendido.
	//como resultado, se debe RETORNAR la lista de VENTAS generadas y el TOTAL facturado en este conjunto.
	Pedidos primerPedido;
	float facturado_all_boxes = 0.0;
	int TLinicial_ventas;
	
	TLinicial_ventas = super.TL;
	
	
	for(int i = 0; i < 15; i++){//recorro todas las cajas
		
		if(super.cajas[i].TL > 0){//si la caja tiene pedidos en cola
			
			
			primerPedido = super.cajas[i].pedidos[0];//tomo el primer pedido que llegó a la cola 
			
			super.ventas[super.TL].pedido = primerPedido;
			
			super.ventas[super.TL].total_facturado = facturarPedido(primerPedido);//total facturado en ESA VENTA.
			
			facturado_all_boxes = facturado_all_boxes + super.ventas[super.TL].total_facturado;
			
			super.TL++;//incremento ya que se realizó una venta
			
			//saco el pedido de la cola
			for(int j = 0; j < (int)(super.cajas[i].TL) - 1; j++){
				
					super.cajas[i].pedidos[j] = super.cajas[i].pedidos[j+1];
					
			}
			super.cajas[i].TL--;//tiene un pedido menos ya que fue atendido
			
			
			
		}
		
	}
	
	
	cout << "Ventas generadas: ";
	
	for(int r = TLinicial_ventas; r < super.TL; r++)
		cout << fixed << setprecision(2) << super.ventas[r].total_facturado << " ";
	
	
	cout << endl << "total facturado por todas las cajas: " << fixed << setprecision(2) << facturado_all_boxes << endl;
	
	
}


void agregarPedidoEnCaja(Pedidos pedido,const int numCaja, Supermercado & super){
	
	if(numCaja < 16 and numCaja > 0){
		
		if(super.cajas[numCaja - 1].TL < 400){
			
			super.cajas[numCaja - 1].pedidos[super.cajas[numCaja - 1].TL] = pedido;
			super.cajas[numCaja - 1].TL++;//se incrementa en 1 la cantidad de pedidos en esa caja
			
		}else{
			cout << "No se pueden agregar más pedidos a la caja" << endl;
		}
		
		
		
		
	}else{
		cout << "numero de caja incorrecto" << endl;
	}
	
}
