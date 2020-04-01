#ifndef Lista_H
#define Lista_H

#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>

using namespace std;
//Estructura nodo que tendra el nombre de una iglesia y un id de un feligres
template <class T>
struct nodo{
	string iglesia;
	string id;
	nodo<T> *sig;
};

//Clase lista que tiene un nodo que servira como la cabeza
template <class T>
class lista{
	
	nodo<T> *cab;
	
	public:
		lista(){//Constructor de la clase lista
			cab = new nodo<T>;
			cab->iglesia="";
			cab->id="";
			cab->sig=NULL;
		}
	//Declaracion de los metodos de la clase lista
	void insertarLista(T dato, string id);
	void retornarLista();
};
//Metodo que sirve para insertar los datos de lista en la ultima posicion
template<class T>
void lista<T>::insertarLista(T dato, string id){
	nodo<T> *aux,*aux1=cab;
	aux= new nodo<T>;
	aux->iglesia=dato;
	aux->id=id;
	aux->sig=NULL;
	while(aux1->sig !=NULL){
		aux1=aux1->sig;
	}
	aux1->sig=aux;
}
//Metodo que retorna el id en una posicion 
template<class T>
void  lista<T>::retornarLista(){
    int i=0;
	nodo<T> *aux1=cab;
	while(aux1->sig!=NULL){
		aux1=aux1->sig;
		i++;
	}
	cout<<"El numero de feligreses de este genero es de: "<<i<<endl;
}

#endif
