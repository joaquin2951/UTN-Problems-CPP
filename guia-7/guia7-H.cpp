#include <iostream>
using namespace std;

void SeasonPrint(int month , int day);


int main() {
	// el otoño comienza el 21 de marzo,
	//el invierno el 21 de junio, 
	//la primavera el 21 de septiembre 
	//y el verano el 21 de diciembre

	
	int mes, dia;
	cin>>mes>>dia;
	
	SeasonPrint(mes,dia);
	
	
	
	
	
	return 0;
}

void SeasonPrint(int month , int day){
	
	if(day >= 21)
	switch(month){
	case 3://20 marzo verano  //21 marzo otoño
	case 4:
	case 5: cout << "otonio" << endl; break;
		
	case 6://20 junio otoño  //21 junio invierno
	case 7:
	case 8: cout << "invierno" << endl; break;
		
	case 9: //20 septiembre invierno  // 21 septiembre primavera
	case 10:
	case 11: cout << "primavera" << endl; break;
		
	case 12://20 diciembre primavera // 21 diciembre verano
	case 1:
	case 2:  cout << "verano" << endl; break;
	}
	
	else
		switch(month){
		
		case 4:
		case 5: 
		case 6: cout << "otonio" << endl; break;//20 junio otoño  
			
			
			
		case 7: //21 junio invierno
		case 8: 
		case 9: cout << "invierno" << endl; break; //20 septiembre invierno
		  
		
		case 10: // 21 septiembre primavera
		case 11: 
		case 12: cout << "primavera" << endl; break; //20 diciembre primavera 
		
			
		case 1:// 21 diciembre verano
		case 2:  
		case 3: cout << "verano" << endl; break;
		
	}


	
	
}
