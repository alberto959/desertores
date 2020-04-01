#ifndef Localidades_H
#define Localidades_H

#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>

using namespace std;

//Estructura nodoLocalidad que tiene los mismos parametros que tenga Localidad ademas de un siguiente Localidad-Barrio
template<class T>
struct nodoLocalidad{
	string localidad;
	string barrio;
	nodoLocalidad<T> *sig;	
};
//Clase Localidad que tiene un nodoLocalidad que servira de cabeza
template<class T>
class Localidad{
	nodoLocalidad<T> *cab;
	public:
		Localidad(){//Constructor de la clase Localidad
			cab=new nodoLocalidad<T>;
			cab->localidad="";
			cab->barrio="";
			cab->sig=NULL;	
		}
			//Declaracion de los metodos de la clase Localidad
	void insertarLocalidad(char localidad[15], char barrio[15]);
	T retornarLocalidad(int pos);
	T retornarBarrio(int pos);
	void Localidades();
};

//Metodo pora insertar una localidad en la ultima posicion disponible
template<class T>
void Localidad<T>::insertarLocalidad(char localidad[15], char barrio[15]){
	
	string localidadAux(localidad);
	string barrioAux(barrio);
	
	
	nodoLocalidad<T> *aux,*aux1=cab;
	aux= new nodoLocalidad<T>;
	aux->localidad= localidadAux;
	aux->barrio = barrioAux;
	aux->sig=NULL;
	while(aux1->sig !=NULL){
		aux1=aux1->sig;
	}
	aux1->sig=aux;
}

//Metodo para retornar la localidad en una posicion dada
template<class T>
T Localidad<T>::retornarLocalidad(int pos){
	
    int i;
	nodoLocalidad<T> *aux,*aux1=cab;
	aux=new nodoLocalidad<T>;
	for(i=1;i<=pos&& aux1->sig!=NULL;i++){
		aux1=aux1->sig;
	}
	
	return aux1->localidad;
}

//Metodo para retornar el barrio en una posicion dada
template<class T>
T Localidad<T>::retornarBarrio(int pos){
	
    int i;
	nodoLocalidad<T> *aux,*aux1=cab;
	aux=new nodoLocalidad<T>;
	for(i=1;i<=pos&& aux1->sig!=NULL;i++){
		aux1=aux1->sig;
	}
	
	return aux1->barrio;
}

//Metodo para imprimir todas las localidades insertadas
template<class T>
void Localidad<T>::Localidades(){
	int cont=1;
	nodoLocalidad<T> *aux,*aux1=cab;
	aux=new nodoLocalidad<T>;
	while(aux1->sig!=NULL){
		aux1=aux1->sig;
		cout<<cont<<". "<<aux1->barrio<<endl;
		cont++;
	}
}

#endif
