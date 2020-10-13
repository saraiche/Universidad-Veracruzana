#include<iostream>
using namespace std;

int n;

int main()
{
	cout<<"Ingrese el numero magico:\n";
	cin>>n;
	switch(n)
	{
		case 1:
			cout<<"Lunes";
		case 2:
			cout<<"Martes";
			break;
		case 3:
			cout<<"Miercoles";
			break;
		case 4:
			cout<<"Jueves";
			break;
		case 5:
			cout<<"Viernes";
			break;
		case 6:
			cout<<"Sabado";
			break;
		case 7:
			cout<<"Domingo";
			break;
		default:
			cout<<"Numero no valido";
			break;

	}
}