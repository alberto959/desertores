#ifndef Hijos_H
#define Hijos_H

#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>

using namespace std;

//Estructura nodoHijos que tiene los parametros que tendra Hijo ademas de un hijo anterior y uno sigueinte
template<class T>
struct nodoHijos{
	string idPadre;
	string nomb;
	string fechaNaci;
	string edad;
	nodoHijos<T> *sig,*ant;
};

//Clase Hijos que tiene un nodoHijos que servira como cabeza
template<class T>
class Hijos{
	nodoHijos<T> *cab;
	public:
		Hijos(){//Constructor de la clase hijos
			cab=new nodoHijos<T>;
			cab->idPadre="";
			cab->nomb="";
			cab->fechaNaci="";
			cab->edad="";
			cab->sig=0;
			cab->ant=0;
		}
		
	void insertarHijo(T dato, string fech, int edad);		//Declaracion de los metodos de la clase Hijos
	T retornarHijo(int pos);
};



#endif
