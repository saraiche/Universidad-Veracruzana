/*
ID: Joseph
LANG: C++17
TASK: 
*/
#include<iomanip>
#include<iostream>
using namespace std;



int main()
{
	ios::sync_with_stdio(false);


	double precio, descuento;
	double horas;

	cout<<"Ingrese las horas  trabajadas: ";
	cin>>horas;
	cout<<"Ingrese el sueldo por hora: ";
	cin>>precio;
	double sueldo = double ( horas * precio );
	descuento = ( sueldo > 3000 ? ( 10 * sueldo ) / 100 : -200);
	cout<<"El sueldo sin descuento es: "<<setprecision(2)<<fixed<<sueldo<<" Pesos\n";
	cout<<"El sueldo con descuento es: "<<setprecision(2)<<fixed<<sueldo - descuento<<" Pesos\n";


}

