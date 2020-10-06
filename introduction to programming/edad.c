#include<stdio.h>

int fechas[3][3];

int main()
{
	
	bool ok = true;
	printf("Ingrese su fecha de nacimiento en formato DIA/MES/AÑO\n");
	scanf("%d %d %d",&fechas[0][0],&fechas[0][1],&fechas[0][2]);
	printf("Ingrese la fecha actual en formato DIA/MES/AÑO\n");
	scanf("%d %d %d",&fechas[1][0],&fechas[1][1],&fechas[1][2]);
	int edad = ( fechas[1][2] - fechas[0][2]);
	if( fechas[0][1] == fechas[1][1])
	{
		if( fechas[1][0] < fechas[0][0])
			ok = false;
	}
	else if( fechas[1][1] < fechas[0][1] )
		ok = false;

	printf("Tu edad es: %d\n",(ok?edad:edad-1));


}