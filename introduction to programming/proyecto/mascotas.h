#ifndef MASCOTAS_H
#define MASCOTAS_H
///----- uwu -------
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

///------- owo------
/* 
declaro el using namespace std; para no usar 
el std:: antes de cada uso a un elemento de la stl
*/

class mascota
{
	private:
		string especie;
		string nombre;
		int edad;
		string raza;
		string cumple;
	public:
		void setespecie(string esp);
		void setnombre(string nom);
		void setedad(int ed);
		void setraza(string raz);
		void setcumple(int a, int b, int c);
		string getespecie();
		string getnombre();
		int getedad();
		string getraza();
		string getcumple();
		int maxstring_len();
		mascota();
		mascota(string esp, string nomb, int ed, string raz, int dia, int mes, int anio);
		///maybe more :3
};



#endif