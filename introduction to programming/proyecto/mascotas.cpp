#include<string>
#include"mascotas.h"
using namespace std;

void mascota::setespecie(string esp)
{
	this -> especie = esp;
}

void mascota::setnombre(string nom)
{
	this -> nombre = nom;
}

void mascota::setedad(int ed)
{
	this -> edad = ed;
}

void mascota::setraza(string raz)
{
	this -> raza = raz;
}

void mascota::setcumple(int a, int b, int c)
{
	// simple, sin validar la fecha, digamos que es un universo en donde el tiempo es relativo :3
	string ans = "";
	ans += to_string(a) + "/";
	ans += to_string(b) + "/";
	ans += to_string(c);
	this -> cumple = ans;
}


int mascota::maxstring_len()
{
	return max({ (int) this -> nombre.size(), (int) this -> raza.size(), 
		(int) this -> especie.size(), (int) this -> cumple.size()});
}
string mascota::getespecie()
{
	return this -> especie;
}

string mascota::getnombre()
{
	return this -> nombre;
}

int mascota::getedad()
{
	return this -> edad;
}

string mascota::getraza()
{
	return this -> raza;
}

string mascota::getcumple()
{
	return this -> cumple;
}

mascota::mascota(string esp, string nomb, int ed, string raz, int dia, int mes, int anio)
{
	this -> especie = esp;
	this -> nombre = nomb;
	this -> edad = ed;
	this -> raza = raz;
	setcumple(dia, mes, anio);
	//uwu
}

mascota::mascota()
{
	///uwu
}
