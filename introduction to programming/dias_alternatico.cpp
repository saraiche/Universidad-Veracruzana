#include<iostream>
using namespace std;

int n;
string dias[] = {"Lunes","Martes","Miercoles","Jueves","Viernes","Sabado","Domingo" };
int main()
{
	cout<<"Ingrese el numero magico:\n";
	cin>>n;
	if( n < 1 || n > 7)
		cout<<"Numero no valido";
	else
		cout<<dias[n-1];

}