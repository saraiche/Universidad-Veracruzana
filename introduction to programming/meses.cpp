#include<iostream>
using namespace std;

int n;
	///31, 28, 31 ,30, 31, 30, 31, 31, 30 , 31 , 30 , 31 
int dias[] = {31, 28, 31 ,30, 31, 30, 31, 31, 30 , 31 , 30 , 31};
string mes[] = {"Enero tiene ", "Febrero tiene", "Marzo tiene ","Abril tiene ","Mayo tiene ",
"Junio tiene ","Julio tiene ","Agosto tiene ","Septiembre tiene ","Octubre tiene ","Noviembre tiene ", "Diciembre tiene "};

int main()
{
	cout<<"Ingrese el numero magico:\n";
	cin>>n;
	if( n < 1 || n > 12)
		cout<<"El mes no existe :(";
	else
	{
		cout<<mes[n-1]<<dias[n-1]<<" Dias";
	}
}