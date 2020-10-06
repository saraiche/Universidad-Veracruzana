#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	double precio, base, altura;
	cout<<"Ingrese la medida en metros de la base del terreno:\n";
	cin>>base;
	cout<<"Ingrese la medida en metros de la altura del terreno:\n";
	cin>>altura;
	cout<<"ingrese el precio por metro de terreno:\n";
	cin>>precio;

	auto ans = (altura*base) *precio;
	cout<<"El costo del terreno es: "<<setprecision(2)<<fixed<<ans<<" Pesos\n";

}