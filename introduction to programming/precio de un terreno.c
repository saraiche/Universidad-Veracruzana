#include<stdio.h>

int main()
{
	double precio, base, altura;

	printf("Ingrese la medida en metros de la base del terreno:\n");
	scanf("%lf",&base);
	printf("Ingrese la medida en metros de la altura del terreno:\n");
	scanf("%lf",&altura);
	printf("ingrese el precio por metro de terreno:\n");
	scanf("%lf",&precio);

	auto ans = (altura*base) *precio;
	printf("El costo del terreno es: %.2lf Pesos\n",ans);

}