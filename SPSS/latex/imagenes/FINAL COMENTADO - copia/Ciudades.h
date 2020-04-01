#ifndef Ciudades_H
#define Ciudades_H

#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>

using namespace std;
//Estructura nodoCiudad que tiene los mismos parametros que tenga Ciudad ademas de un siguiente Ciudad-Pais
template<class T>
struct nodoCiudad{
	string ciudad;
	string pais;
	nodoCiudad<T> *sig;	
};

//Clase Ciudad que tiene un nodoCiudad que servira de cabeza
template<class T>
class Ciudad{
	nodoCiudad<T> *cab;
	public:
		Ciudad(){//Constructor de la clase Ciudad
			cab=new nodoCiudad<T>;
			cab->ciudad="";
			cab->pais="";
			cab->sig=NULL;	
		}
			//Declaracion de los metodos de la clase Ciudad
	void insertarCiudad(char ciudad[15], char pais[15]);
	T retornarCiudad(int pos);
	T retornarPais(int pos);
	void ciud();
};
//Metodo pora insertar una ciudad en la ultima posicion disponible
template<class T>
void Ciudad<T>::insertarCiudad(char ciudad[15], char pais[15]){
	
	string ciudadAux(ciudad);
	string paisAux(pais);
	
	
	nodoCiudad<T> *aux,*aux1=cab;
	aux= new nodoCiudad<T>;
	aux->ciudad= ciudadAux;
	aux->pais = paisAux;
	aux->sig=NULL;
	while(aux1->sig !=NULL){
		aux1=aux1->sig;
	}
	aux1->sig=aux;
}

//Metodo para retornar la ciudad en una posicion dada
template<class T>
T Ciudad<T>::retornarCiudad(int pos){
	
    int i;
	nodoCiudad<T> *aux,*aux1=cab;
	aux=new nodoCiudad<T>;
	for(i=1;i<=pos&& aux1->sig!=NULL;i++){
		aux1=aux1->sig;
	}
	
	return aux1->ciudad;
}

//Metodo para retornar el pais en una posicion dada
template<class T>
T Ciudad<T>::retornarPais(int pos){
	
    int i;
	nodoCiudad<T> *aux,*aux1=cab;
	aux=new nodoCiudad<T>;
	for(i=1;i<=pos&& aux1->sig!=NULL;i++){
		aux1=aux1->sig;
	}
	
	return aux1->pais;
}

//Metodo para imprimir todas las ciudades insertadas
template<class T>
void Ciudad<T>::ciud(){
	int cont=1;
	nodoCiudad<T> *aux,*aux1=cab;
	aux=new nodoCiudad<T>;
	while(aux1->sig!=NULL){
		aux1=aux1->sig;
		cout<<cont<<". "<<aux1->ciudad<<endl;
		cont++;
	}
}

#endif
