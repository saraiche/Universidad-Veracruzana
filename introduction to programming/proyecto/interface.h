#ifndef INTERFACE_H
#define INTERFACE_H

#include<map>
#include<vector>
#include<string>
#include<fstream>
#include<stdlib.h>
#include<algorithm>
#include "mascotas.h"
using namespace std;

#ifdef _WIN32
#include<windows.h>   // lo unico que hago aqui es verificar si esta corriendo en windows o basados en unix
#endif

void limpia()
{
	#ifdef _WIN32   // si estoy en windows uso cls
		system("cls");
	#else
		system("clear"); /// si estoy en basados en unix uso clear ( mac os, linux, freebsd, android, etc)
	#endif
}

//// variables globales 
bool ok = false;

void pausa()
{
	cin.get();
	char enter = '\n';
	char sigue = cin.get();
	while( sigue != enter)
		sigue = cin.get();
	return;

}

string normaliza( string a)
{
	string ans = "";
	for( auto v: a)
		ans += tolower(v);
	return ans;
}


void guardar(vector < mascota > data, string dir)
{
	fstream archivo;
	archivo.open(dir.c_str(), ios::out);
	if( archivo.fail())
	{
		cout<<"No fue posible guardar, lo siento :(\n";
		return;
	}
	archivo<<data.size()<<"\n";
	for( auto a: data)
	{
		archivo<<a.getespecie()<<"~";
		archivo<<a.getnombre()<<"~";
		archivo<<a.getedad()<<"~";
		archivo<<a.getraza()<<"~ ";
		string cumple = a.getcumple();
		string temp = "";
		int it = 0 ;
		while( it < (int)cumple.size())
		{
			if( cumple[it] == '/')
			{
				archivo<<temp<<" ";
				temp = "";
			}
			else
				temp += cumple[it];
			it++;	
		}
		archivo<<temp<<"\n";
	}
	cout<<"Se guardo con exito :3\n";
	archivo.close(); /// fels good :)
}

mascota decode( string a, int dia, int mes, int anio)
{
	mascota objet;
	string temp = "";
	int it = 0 ;
	///especie
	while( it < (int)a.size() && a[it] != '~')
		temp += a[it++];
	objet.setespecie(temp);
	temp = "";
	it++;

	//nombre
	while( it < (int)a.size() && a[it] != '~')
		temp += a[it++];
	objet.setnombre(temp);
	temp = "";
	it++;
	//edad
	while( it < (int)a.size() && a[it] != '~')
		temp += a[it++];
	objet.setedad(atoi(temp.c_str()));
	temp = "";
	it++;

	//raza
	while( it < (int)a.size() && a[it] != '~')
		temp += a[it++];
	objet.setraza(temp);
	temp = "";
	it++;

	objet.setcumple(dia, mes, anio);

	return objet;
}

void abrir( vector < mascota > &content, map < string , int > &dirs, string dir)
{
	ifstream archivo(dir.c_str());
	int cantidad = 0;
	archivo >> cantidad;
	while( cantidad--)
	{
		string temp;
		archivo >> temp;
		//cout<<"----"<<temp<<"\n";
		int a,b,c;
		archivo>>a>>b>>c;
		content.push_back(decode(temp,a,b,c));
		dirs[normaliza(content.back().getnombre())] = content.size()-1;
	}
	archivo.close();
}

void menu()
{
	cout<<"\t--MENU DE OPCIONES--\n";
	cout<<"1) Agregar una mascota\n";
	cout<<"2) Quitar mascota\n";
	cout<<"3) Modificar Mascota\n";
	cout<<"4) Consultar\n";
	cout<<"5) Guardar\n";
	cout<<"6) Salir\n";
}

void add(vector < mascota > &current, map < string, int > &dirs ) 
{
	ok = false;
	limpia();
	string esp, name, raz;
	int num,dia,mes,anio;
	cout<<"Ingtesa la especie de la mascota\n";
	cin>>esp;
	cout<<"Ingresa el nombre de la mascota\n";
	cin>>name;
	cout<<"Ingrese la edad de "<<name<<"\n";
	cin>>num;
	cout<<"Ingrese la raza de "<<name<<"\n";
	cin>>raz;
	cout<<"Ingrese el Dia, Mes y Año de nacimiento de "<<name<<"\n";
	cin>>dia>>mes>>anio;
	if( dirs.find(normaliza(name)) != dirs.end())
	{
		cout<<"Ya hay una mascota con ese nombre\n";
		cout<<"No se puede ingresar :(, prueba de nuevo :) \n";
	}
	else
	{
		dirs[normaliza(name)] = (int)current.size();
		mascota nuevo(esp, name, num, raz, dia,mes, anio);
		current.push_back(nuevo);
		ok = true;
		cout<<"Mascotita ingresada :)\n";
	}
}

void quitar(vector < mascota > &current, map < string, int > &dirs ) 
{
	limpia();
	string name;
	cout<<"Ingresa el nombre de la mascota a eliminar\n";
	cin>>name;
	name = normaliza(name);
	if( dirs.find(name) != dirs.end() )
	{
		int it = dirs[name];
		current.erase(current.begin() + it);
		dirs.erase(name);
		cout<<"Mascotita elininada, presiona enter :)";
	}
	else
		cout<<"La mascota no esta :(\n";
	return;
}

void modificar(vector < mascota > &current, map< string, int > &dirs)
{
	limpia();
	string name = "";
	cout<<"Ingresa el nombre de la mascota a editar :) \n";
	cin>>name;
	name = normaliza(name);
	if( dirs.find(name) != dirs.end())
	{
		int it = dirs[ name ];
		//cout<<it<<" <---\n"; /// borrar luego
		dirs.erase(name);
		//pausa();
		add(current, dirs);
		if( ok )
		{
			current[it] = current.back();
			dirs[normaliza(current.back().getnombre())] = it;
			current.pop_back();
			cout<<"Mascota Editada :)";	
		}
		else
		{
			dirs[name] = it;
			cout<<"No se pudo editar :(";
		}


		cout<<"\n";
	}
	else
		cout<<"La mascota no esta :(\n";

	ok = false;
}

void espaciado( int a)
{
	while(a--) cout<<" ";
}

void consultar(vector < mascota > current)
{
	limpia();
		int maxsize = 0 ;
		for( mascota a: current)
			maxsize = max( maxsize, a.maxstring_len());
		espaciado(2*maxsize);
		cout<<"\t MASCOTA\n";
		cout<<"Especie";
		espaciado(maxsize+abs(7 - maxsize));
		cout<<"Nombre";
		espaciado(maxsize+ abs(6 - maxsize));
		cout<<"Edad";
		espaciado(maxsize + abs(4 - maxsize));
		cout<<"Raza";
		espaciado(maxsize + abs(4 - maxsize));
		cout<<"Cumple\n\n";
		int cc = 0;
		for( mascota a: current )
		{
			cout<<++cc<<") ";
			cout<<a.getespecie();
				espaciado(maxsize-2 + abs((int)a.getespecie().size() - maxsize));
			cout<<a.getnombre();
				espaciado(maxsize + abs( (int) a.getnombre().size() - maxsize ));
			cout<<a.getedad();
				espaciado(maxsize + abs( (int)to_string(a.getedad()).size() - maxsize ));
			cout<<a.getraza();
				espaciado(maxsize + abs( ( int )a.getraza().size() - maxsize));
			cout<<a.getcumple()<<"\n";
		}
		cout<<"\nDa enter cuando acabes de ver :)\n";

	

}


void mostrar_raza(vector < mascota > current)
{
	limpia();
	string raza;
	cout<<"Escribe la raza que quieres buscar\n";
	cin>>raza;
	bool existe = false;
	cout<<"\n\t Mostrando mascotas de Raza "<<raza<<"\n";
	int contador = 0;
	for( mascota a: current)
		if( normaliza(a.getraza()) == normaliza(raza))
		{
			existe = true;
			cout<<++contador<<") "<<a.getespecie()<<" "<<a.getnombre()<<" ";
			cout<<a.getedad()<<" "<<a.getraza()<<" "<<a.getcumple()<<"\n";
		}
	if( !existe)
	{
		cout<<"No hay mascotas de la raza "<<raza<<":(\n";
		cout<<"Presiona enter para salir :)\n";
	}
	else
		cout<<"Presiona enter cuando hayas visto todo :D\n";
}

void mostrar_menor(vector < mascota > current)
{
	limpia();
	vector < mascota > menores;
	int mini = (1 << 10);
	for( mascota a: current)
		if( mini > a.getedad() ) 
			mini = a.getedad(); 
	for( mascota a: current)
		if( a.getedad() == mini)
			menores.push_back(a);
	cout<<"\t Mostrando las mascotas de menor edad\n\n";
	for(int c = 0 ; c<menores.size(); c++)
	{
		cout<<c+1<<") "<<menores[c].getespecie()<<" "<<menores[c].getnombre()<<" ";
		cout<<menores[c].getedad()<<" "<<menores[c].getraza()<<" "<<menores[c].getcumple()<<"\n";
	}

	cout<<"\n Presiona enter cuando quieras salir :3\n";

}


void menu_consulta(vector < mascota > current)
{
	limpia();
	if( !current.size())
	{
		cout<<"Lo siento pero aun no hay mascotas aqui :(\n";
		cout<<"Ingresa mascotas e intenta de nuevo :)\n";
	}
	else
	{
		int opcion = 0 ;
		cout<<"1) Mostrar todo\n";
		cout<<"2) Mostrar por raza\n";
		cout<<"3) Mostrar las mascotas menores\n";
		cin>>opcion;
		if(opcion < 1 || opcion > 3 ) 
			cout<<"Opcion Incorreta :(\n";
		else
		{
			switch(opcion)
			{
				case 1:
					consultar(current);
					break;
				case 2:
					mostrar_raza(current);
					break;
				case 3:
					mostrar_menor(current);
					break;

			}
		}

	}

}


#endif