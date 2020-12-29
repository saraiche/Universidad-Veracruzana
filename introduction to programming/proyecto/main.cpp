/// run on linux kernel 4.0 + 
/// run on  mac os version 10.x + 
/// dependences:
/*
GNU G++ 9.0.3 +
CLANG G++ 7.0 +
make for linux or mac os 
mascotas.h
mascotas.cpp
interface.h
*/
#include<map>
#include<vector>
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include "mascotas.h"
#include "interface.h"
using namespace std;

vector < mascota > contenido;
map < string, int > direccion;

int main()
{

	abrir(contenido, direccion, "registro.dat");
	bool ok = true;
	while( ok )
	{
		limpia();
		menu();
		int opcion = 0;
		cin>>opcion;
		if( opcion < 1 || opcion > 6 )
			cout<<"Nope\n";
		else
		{
			switch(opcion)
			{
				case 1:
					add(contenido, direccion);
					break;
				case 2:
					quitar(contenido, direccion);
					break;
				case 3:
					modificar(contenido, direccion);
					break;
				case 4:
					menu_consulta(contenido);
					break;
				case 5:
					guardar(contenido, "registro.dat");
					break;
				case 6:
					guardar(contenido, "registro.dat");
					cout<<"Adios :)\n";
					return 0;

			}
		}
		pausa();
	}

}
