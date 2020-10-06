#include<bits/stdc++.h>
using namespace std;

int fechas[3][3];

int main()
{
	ios::sync_with_stdio(false);
	bool ok = true;
	cout<<"Ingrese su fecha de nacimiento en formato DIA/MES/AÑO\n";
	cin>>fechas[0][0]>>fechas[0][1]>>fechas[0][2];
	cout<<"Ingrese la fecha actual en formato DIA/MES/AÑO\n";
	cin>>fechas[1][0]>>fechas[1][1]>>fechas[1][2];
	int edad = ( fechas[1][2] - fechas[0][2]);
	if( fechas[0][1] == fechas[1][1])
	{
		if( fechas[1][0] < fechas[0][0])
			ok = false;
	}
	else if( fechas[1][1] < fechas[0][1] )
		ok = false;

	cout<<"Tu edad es: "<<(ok?edad:edad-1)<<"\n";


}