#include<iomanip>
#include<iostream>
using namespace std;

double tiempo, sueldo;
double precio;

int main()
{
	ios_base::sync_with_stdio(false);
	
	cout<<"Ingrese la cantidad de tiempo trabajado en minutos:\n";
	cin>>tiempo;
	cout<<"Ingrese el sueldo correspondiente por hora trabajada:\n";
	cin>>precio;

	sueldo = ( tiempo / 60);
	sueldo *= precio;

	cout<<"El sueldo del trabajador es: "<<setprecision(2)<<fixed<<sueldo<<" Pesos";


}