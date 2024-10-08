#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;
#define TAM 5
#define TAMalquileres 500
struct Coche{
	int codigo;
	int categoria;
	float importe_alquiler;
};


struct Alquiler{
	int codigo;
	int num_cli;
	int dias_alq;
	float km_recorridos;
};


bool posicionCoche(const Coche c[], const int TL, int codigoBuscado);
void informar_totalabonadoenAlquiler(const Alquiler a[], const Coche c[], const int TL_Alq, const int TL_coches);

void listar_alquileres(Alquiler alquileres[], const int TL);
void bubblesort(Alquiler vec[],const int TL);
void mergesort(Coche vec[],int inicio, int fin);
void merge(Coche vec[],int inicio1,int final1, int inicio2,int final2);
void inicializar_aleatorio(Coche coches[], const int TL);
void inicializar_alquiler(Alquiler alquileres[], int & TL);
void visualizar(const Coche coches[], const int TL);
bool codigo_valido(const  Coche coches[],const int TL, const int codigo);
bool existeCodigo(const  Coche coches[], const  int TL, const int codigo);
bool esCorrelativo(const int codigo);
bool seRepite(const int codigo);



int main(int argc, char *argv[]) {
	Coche coches[TAM];
	Alquiler alquileres[TAMalquileres]; int TL = 0;
	
	inicializar_aleatorio(coches,TAM);
	mergesort(coches,0,TAM-1); cout << endl << endl;
	
	visualizar(coches,TAM);
	cout << endl << endl;
	
	
	inicializar_alquiler(alquileres, TL); 
	bubblesort(alquileres,TL);
	listar_alquileres(alquileres,TL);
	
	cout << endl << endl;
	
	informar_totalabonadoenAlquiler(alquileres,coches,TL,TAM);
	
	
	
	
	return 0;
}


void informar_totalabonadoenAlquiler(const Alquiler a[], const Coche c[], const int TL_Alq, const int TL_coches){
	
	float suma = 0.0;
	float total[200][2];// [nrocliente] [totalAbonado]
	int posicion_coche;
	int j = 0;//j es el TL de las filas de la matriz total[j][]
	
	for(int i = 0; i < TL_Alq ; i++){
		
		
		if(i > 0 and a[i].num_cli != a[i-1].num_cli){
			suma = 0.0;
			j++;
		}
		
			posicion_coche = posicionCoche(c,TL_coches,a[i].codigo);//buscar coche y devolver la posicion del mismo
			suma = suma + (c[posicion_coche].importe_alquiler * a[i].km_recorridos);
			
			total[j][1] = suma;
			total[j][0] = a[i].num_cli;
		
		
	}
	
	
	
	j++; //j = TL;
	
	//ordenar Matriz  _ Selection Sort
	
	for(int i = 0; i < j - 1; i++){
		
		int mayor = total[i][1];
		int posMayor = i;
		
		for(int k = 1; k < j; k++){
			
			if(total[k][1] > mayor){
				mayor = total[k][1];
				posMayor = k;
			}
			
			
		}
		
		if(posMayor != i){
			swap(total[i][1], total[posMayor][1]);
			swap(total[i][0], total[posMayor][0]);
		}
		
		
	}
	
	cout << "Nro. Cliente          Total $ abonados en alquiler" << endl;
	
	for(int fila = 0; fila < j; fila++){
		cout << endl;
		
		
			if(total[fila][1] > 100){
				cout << (int) total[fila][0] << "             ";
				cout << fixed << setprecision(2) << total[fila][1];
			}
				
		
	}

	
}

bool posicionCoche(const Coche c[], const int TL, int codigoBuscado){
		
	int inicio = 0, fin = TL - 1;
	int medio;
	
	while(inicio <= fin){
		
		medio = (inicio + fin) / 2;
		
		if(c[medio].codigo == codigoBuscado)
			return medio;
		else
			if(codigoBuscado > c[medio].codigo)
				inicio = medio+1;
		else
				fin = medio - 1;
				
	}
		
	return -1;//si no encuentra el coche
}
	
void listar_alquileres(Alquiler alquileres[], const int TL){
	for(int i = 0; i < TL; i++){
		cout << "cod_auto: " << alquileres[i].codigo;
		cout << " | ";
		cout << "num_cli: " << alquileres[i].num_cli;
		cout << " | ";
		cout << "dias_alq: " << alquileres[i].dias_alq;
		cout << " | ";
		cout << "km_rec: " << fixed << setprecision(2) << alquileres[i].km_recorridos << endl;
		
	}
}

void bubblesort(Alquiler vec[],const int TL){
		int pasadas = 1;
		int k; bool intercambios = true;
		
		while(intercambios && pasadas < TL){
			intercambios = false;
			k = 0;
			
			while(k < TL - pasadas){
				if(vec[k].num_cli > vec[k+1].num_cli){
					swap(vec[k],vec[k+1]);
					intercambios = true;
				}
					
				k++;
			}
			
			pasadas++;
		}
}

void inicializar_alquiler(Alquiler alquileres[], int & TL){
	srand(time(NULL));
	
	do{
		
		cout << "codigo de auto: "; cin >> alquileres[TL].codigo;
		
		do{
			cout << "Nro de cliente: "; cin >> alquileres[TL].num_cli; //numero de clientes va del 1 al 200
		}while(alquileres[TL].num_cli > 200 or alquileres[TL].num_cli < 0);
		
		
		cout << "Total dias de alquiler: cargado!  |  "; alquileres[TL].dias_alq = (rand() % 30) + 1;
		
		cout << "Km recorridos: cargado!" << endl << endl; alquileres[TL].km_recorridos = (float)((rand() % 3000) + 1)  / (float)((rand() % 1500) + 1);
			
		TL++;
		
	}while(TL < TAMalquileres and alquileres[TL-1].num_cli != 0);
	
	TL--;
	
}

void visualizar(const Coche coches[], const int TL){
	for(int i = 0; i < TL; i++)
		cout << "código: " << coches[i].codigo << " |  Categoría: " << coches[i].categoria << " |  Importe: " << coches[i].importe_alquiler << endl; 
	
}

void inicializar_aleatorio(Coche coches[], const int TL){
	srand(time(NULL));
	
	for(int i = 0; i < TL; i++){
		
		do{
			coches[i].codigo = (rand()%9000) + 1000; //numero aleatorio entre [1000 , 9999]
		}while(codigo_valido(coches,i,coches[i].codigo) == false);
		
		
			
		coches[i].categoria = (rand()%7) + 1;  //genera numeros aleatorios entre [1,7]
		
		coches[i].importe_alquiler = (rand()%150)  + 60; // numeros aleatorios entre [60 , 209]
		
	}
	
	
}

	
void mergesort(Coche vec[],int inicio, int fin){

	if(fin - inicio == 0)
		return;
	else{
		mergesort(vec,inicio,(inicio+fin)/2);
		mergesort(vec,((inicio+fin)/2) + 1, fin);
		merge(vec,inicio,(inicio+fin)/2, ((inicio+fin)/2)+1, fin);
	}
	
}
	
void merge(Coche vec[], int inicio1,int final1, int inicio2, int final2){
	
	int i, j , k; //declaro tres variables
	Coche c[TAM]; //declaramos un vector, del mismo tamaño que el vector que pasamos como parametro
	
	i = inicio1;
	j = inicio2;
	k = 0;
	
	while(i <= final1 && j <= final2)//primer bucle, con ambos iteradores en la condicion
		if(vec[i].codigo < vec[j].codigo)
			c[k++] = vec[i++];
		else
			c[k++] = vec[j++];
		
	//Luego, alguno de los iteradores i o j seguirá siendo menor al final1 o final2 respectivamente.
	while(i <= final1)
		c[k++] = vec[i++];
	
	while(j <= final2)
		c[k++] = vec[j++];
	
	
	for(k = 0; k <= final2 - inicio1; k++)//bucle final para pasar todo el vector ordenado al vector original
		vec[inicio1+k] = c[k];
	
	
}

bool codigo_valido(const Coche coches[],const int TL, const int codigo){
	//NO es codigo valido si:   1. YA EXISTE EN EL ARREGLO     2.HAY NUMEROS CORRELATIVOS (1234)    3.SE REPITE ALGUN NUMERO EN EL CODIGO (1213)
	if(!existeCodigo(coches,TL,codigo) and !esCorrelativo(codigo) and !seRepite(codigo))
		return true; //es codigo valido
	else
		return false;// NO es codigo valido
}

bool seRepite(const int codigo){
	int vec[4] = {codigo / 1000,(codigo / 100) % 10, (codigo / 10) % 10, (codigo % 10)  };
	
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			if(i != j  and vec[i] == vec[j])//SE REPITE ALGUN NUMERO EN EL ARREGLO?
				return true;//SI, SE REPITE
	
	return false;
}
	
bool esCorrelativo(const int codigo){
	int d4,d3,d2,d1;
	d4 = (codigo % 10); d3 = (codigo / 10) % 10; d2 = (codigo / 100) % 10; d1 =  codigo / 1000;
	
	if(d4 == d3+1 and d3 == d2+1 and d2 == d1+1)
		return true;
	return false;
}

bool existeCodigo(const Coche coches[], const  int TL, const int codigo){
		int i = 0;
		while(i < TL){
			if(coches[i].codigo == codigo)
				return true;
			i++;
		}
		
		return false;
}

		
		
		
		
//FALTA HACER: 
		
/* 
			MOSTRAR:
		•	Cada uno de los códigos de los autos que no fueron alquilados. 
		• Los números de los clientes que alquilaron autos más de 2 veces (sin importar cuántos kilómetros recorrieron). 
		• La categoría de auto más veces alquilada por los clientes. 
		• El auto por el que se recaudó más dinero en alquiler. 
		
		Nota: Para calcular el importe del alquiler de un auto se debe multiplicar el importe en $ por 
		km. por la cantidad de kilómetros recorridos. 
		
*/
