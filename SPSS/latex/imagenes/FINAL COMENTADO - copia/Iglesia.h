#ifndef Ilesia_H
#define Iglesia_H

#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>

using namespace std;


//Estructura nodoIglesia que tiene los parametros que tengra una iglesia ademas de una siguiente iglesia
template<class T>
struct nodoIglesia{
	string nombreIglesia;
	string direccionIglesia;
	string barrioIglesia;
	string pastorIglesia;
	nodoIglesia<T> *sig;	
};

//Clase  Iglesia que tiene un nodoIglesia que servira de cabeza
template<class T>
class Iglesia{
	nodoIglesia<T> *cab;
	public:
		Iglesia(){//Constructor de la clase Iglesia
			cab=new nodoIglesia<T>;
			cab->nombreIglesia="";
			cab->direccionIglesia="";
			cab->barrioIglesia="";
			cab->pastorIglesia="";
			cab->sig=NULL;
			
		}
			//Declaracion de los metodos de la clase Iglesia
	void insertarIglesia(char nombre[20], char direccion[30], char barrio[15], char pastor[20]);
	T retornarIglesia(int pos);
	void IglesiaNodo();
	void iglesiasMayorAsistencia(int asist);
};


//Metodo para insertar una iglesia y sera siempre insertado en la ultima posicion 
template<class T>
void Iglesia<T>::insertarIglesia(char nombre[20], char direccion[30], char barrio[15], char pastor[20]){
	
	string nombreAux(nombre);
	string direccionAux(direccion);
	string barrioAux(barrio);
	string pastorAux(pastor);
	
	nodoIglesia<T> *aux,*aux1=cab;
	aux= new nodoIglesia<T>;
	aux->nombreIglesia = nombreAux;
	aux->direccionIglesia = direccionAux;
	aux->barrioIglesia = barrioAux;
	aux->pastorIglesia = pastorAux;
	aux->sig=NULL;
	while(aux1->sig !=NULL){
		aux1=aux1->sig;
	}
	aux1->sig=aux;
}

//Metodo para retornar la iglesia en una posicion dada
template<class T>
T Iglesia<T>::retornarIglesia(int pos){
	
    int i;
	nodoIglesia<T> *aux,*aux1=cab;
	aux=new nodoIglesia<T>;
	for(i=1;i<=pos&& aux1->sig!=NULL;i++){
		aux1=aux1->sig;
	}
	
	return aux1->nombreIglesia;
}


//Metodo para imprimir todas las iglesia que estan insertadas
template<class T>
void Iglesia<T>::IglesiaNodo(){
	int cont=1;
	nodoIglesia<T> *aux,*aux1=cab;
	aux=new nodoIglesia<T>;
	while(aux1->sig!=NULL){
		aux1=aux1->sig;
		cout<<cont<<". "<<aux1->nombreIglesia<<endl;
		cont++;
	}
}
//Metodo para imprimir todas las iglesia que estan insertadas
template<class T>
void Iglesia<T>::iglesiasMayorAsistencia(int asist){
	int cont=1, contA=0;
	 Multilista multilista(0);
	nodoIglesia<T> *aux,*aux1=cab;
	aux=new nodoIglesia<T>;
	while(aux1->sig!=NULL){
		aux1=aux1->sig;
		contA=multilista->contarAsistentes(aux1->nombreIglesia);
		if(contA!=0){
			->buscarIglesia();
		cout<<cont<<". Feligreses:"<<contA<<" Pastor:"<<aux1->pastorIglesia<<" Iglesia"<<aux1->nombreIglesia<<endl;
		}d
		
		
		cont++;
	}
}




#endif
