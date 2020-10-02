#include<stdio.h>

float tiempo, precio;
float sueldo;

int main()
{
	printf("Ingrese la cantidad de tiempo trabajado en minutos:\n");
	scanf("%f", &tiempo);
	printf("Ingrese el sueldo correspondiente por hora trabajada:\n");
	scanf("%f",&precio);

	sueldo = tiempo / 60;
	sueldo *= precio;

	printf("El sueldo del trabajador es: %.2f  Pesos", sueldo);

}