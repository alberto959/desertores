#ifndef Feligreses_H
#define Feligreses_H
#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include "Hijos.h" //Llama a la libreira Hijos.h
#include "Iglesia.h" //Llama a la libreira Iglesia.h
#include "Localidades.h" //Llama a la libreira Localidades.h
#include "Ciudades.h" //Llama a la libreira Ciudades.h
#include "Lista.h"		//Llama a la libreira Lista.h
using namespace std;


//Estructura nodoPersona que tiene los mismos parametros que Persona y una persona Siguiente y la conexion con nodoHijos y nodoIglesia
template <class T>
struct nodoPersona{
	string id;
	string nombre;
	string apellido;
	string settipoid;
	string numid;
	string genero;
	string telf;
	string telc;
	string mail;
	string fecnac;
	string edad;
	string cidnac;
	string paisnac;
	string cidres;
	string dire;
	string barrio;
	string actividad;
	string hijos;
	string numhijos;
	string iglesia;
	nodoHijos<T> nhijos;
	nodoIglesia<T> iglesiaNodo;
	nodoPersona<T> *sig;
};


//Clase persona que  tiene un nodoPersona,nodoHijos y nodoIglesia cada una con su respectiva cabeza
template<class T>
class persona{
	
	nodoPersona<T> *cabP;
	nodoHijos<T> *cabH;
	nodoIglesia<T> *cabI;
	public:
		persona(){//Constructor de la clase persona
			cabP = new nodoPersona<T>;
			cabP->id="";
			cabP->nombre="";
			cabP->apellido="";
			cabP->settipoid="";
			cabP->numid="";
			cabP->genero="";
			cabP->telf="";
			cabP->telc="";
			cabP->mail="";
			cabP->fecnac="";
			cabP->edad="";
			cabP->cidnac="";
			cabP->paisnac="";
			cabP->cidres="";
			cabP->dire="";
			cabP->barrio="";
			cabP->actividad="";
			cabP->hijos="";
			cabP->numhijos="";
			cabP->iglesia="";
		//	cabP->hijos=NULL;
			cabH=new nodoHijos<T>;
			cabH->idPadre="";
			cabH->nomb="";
			cabH->fechaNaci="";
			cabH->edad="";
			cabH->sig=0;
			cabH->ant=0;
		//	cabP->iglesia=NULL;
			cabI=new nodoIglesia<T>;
			cabI->nombreIglesia="";
			cabI->direccionIglesia="";
			cabI->barrioIglesia="";
			cabI->pastorIglesia="";
			cabI->sig=NULL;

			cabP->sig=NULL;
			
		}
		//Declaracion de los metodos de la clase Persona
	void insertarPersona(char ingid[3], char ingnombre[10], char ingapellido[20], char settipoid[2], char ingdocumento[15], char genero[2], char ingfijo[10], char ingcelular[10], char ingemail[30],
			 char ingfechaNac[10], char ingedad[2], char ingciudadNac[15], char ingpaisNac[15], char ingciudadRes[15], char ingdireccion[30], char ingbarrio[15], char ingactividad[25], char hijos[2], char ingnumhijos[2], char iglesia[15]);
	void insertarHijo(char idPadre[2], char nombreHijo[25], char fechanaci[10], char edad[2]);
	T retornarHijo(int pos);
	void imprimirPersona();
	nodoPersona<T> retornarPersona(int pos);
	T retornarNo(int pos);
	T retornarAp(int pos);
	T retornarFi(int pos);
	T retornarCe(int pos);
	T retornarEm(int pos);
	T retornarDi(int pos);
	T retornarBa(int pos);
	T retornarHi(int pos);
	T retornarNumHij(int pos);
	T retornarTi(int pos);
	T retornarNumId(int pos);
	T retornarGe(int pos);
	T retornarFn(int pos);
	T retornarEd(int pos);
	T retornarCn(int pos);
	T retornarPn(int pos);
	T retornarCr(int pos);
	T retornarAc(int pos);
	T retornarIglesia(int pos);
	
	void rePe();	
	//metodos de consulta
	
	void buscarIglesia(char iglesia[15]);
	
	
};

//	--------------------------------------------------------------Metodos clase persona-------------------------------------------------------
//Metodo para imprimir a todas las personas con todos sus atributos
template<class T>
void persona<T>::imprimirPersona(){
    int i; // Auxiliar que ayudara con las iteracions del for
	nodoPersona<T> *aux,*aux1=cabP;  // Se declara un nodoPersona aux y aux1 empezara en la cabeza
	aux=new nodoPersona<T>;
	for(i=1;aux1->sig!=NULL;i++){  // Se hara esta iteracion mientras  la siguiente persona no sea null
		cout<<aux1->id<<" "<<aux1->nombre<<" "<<aux1->apellido<<" "<<aux1->settipoid<<" "<<aux1->numid<<" "<<aux1->genero<<" "<<aux1->telf<<" "<<aux1->telc<<endl;
		cout<<aux1->mail<<" "<<aux1->fecnac<<" "<<aux1->edad<<" "<<aux1->cidnac<<" "<<aux1->paisnac<<" "<<aux1->cidres<<" "<<aux1->dire<<" "<<aux1->barrio<<endl;
		cout<<aux1->actividad<<" "<<aux1->hijos<<" "<<aux1->numhijos<<" "<<aux1->iglesia<<endl;
		aux1=aux1->sig;
	}
	cout<<aux1->id<<" "<<aux1->nombre<<" "<<aux1->apellido<<" "<<aux1->settipoid<<" "<<aux1->numid<<" "<<aux1->genero<<" "<<aux1->telf<<" "<<aux1->telc<<endl;
	cout<<aux1->mail<<" "<<aux1->fecnac<<" "<<aux1->edad<<" "<<aux1->cidnac<<" "<<aux1->paisnac<<" "<<aux1->cidres<<" "<<aux1->dire<<" "<<aux1->barrio<<endl;
	cout<<aux1->actividad<<" "<<aux1->hijos<<" "<<aux1->numhijos<<" "<<aux1->iglesia<<endl;
}
//Metodo para insertar una persona
template <class T>
void persona<T>::insertarPersona(char ingid[3], char ingnombre[10], char ingapellido[20], char settipoid[2], char ingdocumento[15], char genero[2], char ingfijo[10], char ingcelular[10], char ingemail[30],
			 char ingfechaNac[10], char ingedad[2], char ingciudadNac[15], char ingpaisNac[15], char ingciudadRes[15], char ingdireccion[30], char ingbarrio[15], char ingactividad[25], char hijos[2], char ingnumhijos[2], char iglesia[15]){
	
	
	string idAux(ingid);			//Pasa todos los parametros de la funcion de char a string
	string nombreAux(ingnombre);
	string apellidoAux(ingapellido);
	string settAux(settipoid);
	string documentoAux(ingdocumento);
	string generoAux(genero);
	string fijoAux(ingfijo);
	string celularAux(ingcelular);
	string emailAux(ingemail);
	string fechaNacAux(ingfechaNac);
	string edadAux(ingedad);
	string ciudadNacAux(ingciudadNac);
	string paisNacAux(ingpaisNac);
	string ciudadResAux(ingciudadRes);
	string direccAux(ingdireccion);
	string barrioAux(ingbarrio);
	string actividadAux(ingactividad);
	string hijosAux(hijos);
	string numHijosAux(ingnumhijos);
	string iglesiaAux(iglesia);	
	

	nodoPersona<T> *aux, *aux1=cabP;
	aux = new nodoPersona<T>;				//Le da los valores en string a el nuevo nodo de persona
	aux->id = idAux;
	aux->nombre = nombreAux;
	aux->apellido= apellidoAux;
	aux->settipoid = settAux;
	aux->numid= documentoAux;
	aux->genero = generoAux;
	aux->telf= fijoAux;
	aux->telc = celularAux;
	aux->mail = emailAux;
	aux->fecnac= fechaNacAux;
	aux->edad = edadAux;
	aux->cidnac = ciudadNacAux;
	aux->paisnac= paisNacAux;
	aux->cidres = ciudadResAux;
	aux->dire = direccAux;
	aux->barrio = barrioAux;
	aux->actividad = actividadAux;
	aux->hijos = hijosAux;
	aux->numhijos = numHijosAux;
	aux->iglesia = iglesiaAux;
	
	aux->sig = NULL;
	
	while(aux1->sig != NULL){	//Con este ciclo nos aseguramos que quede insertado en la ultima posicion
		aux1 = aux1->sig;
	}
	
	aux1->sig = aux;	
	
	
}
//Metodo para retornar el id y el nombre de todas las personas agregadas
template<class T>
void persona<T>::rePe(){
	nodoPersona<T> *aux1=cabP;
	while(aux1->sig!=NULL){
		aux1=aux1->sig;
		cout<<aux1->id<<". "<<aux1->nombre<<endl;
	}
}

//Metodo para retornar el nombre de la persona en una posicion
template<class T>
nodoPersona<T> persona<T>::retornarPersona(int pos){
    int i;
	nodoPersona<T> *aux1=cabP;
	for(i=1;i<=pos&& aux1->sig!=NULL;i++){
		aux1=aux1->sig;
	}
	return aux1;
}


//Metodo par retornar el nombre de la persona en una posicion
template<class T>
T persona<T>::retornarNo(int pos){
    int i;
	nodoPersona<T> *aux1=cabP;
	for(i=1;i<=pos&& aux1->sig!=NULL;i++){
		aux1=aux1->sig;
	}
	return aux1->nombre;
}
//Metodo par retornar el apellido de la persona en una posicion
template<class T>
T persona<T>::retornarAp(int pos){
    int i;
	nodoPersona<T> *aux1=cabP;
	for(i=1;i<=pos&& aux1->sig!=NULL;i++){
		aux1=aux1->sig;
	}
	return aux1->apellido;
}

//Metodo par retornar el telefono fijo de la persona en una posicion
template<class T>
T persona<T>::retornarFi(int pos){
    int i;
	nodoPersona<T> *aux1=cabP;
	for(i=1;i<=pos&& aux1->sig!=NULL;i++){
		aux1=aux1->sig;
	}
	return aux1->telf;
}

//Metodo par retornar el telefono celular de la persona en una posicion
template<class T>
T persona<T>::retornarCe(int pos){
    int i;
	nodoPersona<T> *aux1=cabP;
	for(i=1;i<=pos&& aux1->sig!=NULL;i++){
		aux1=aux1->sig;
	}
	return aux1->telc;
}

//Metodo par retornar el correo de la persona en una posicion
template<class T>
T persona<T>::retornarEm(int pos){
    int i;
	nodoPersona<T> *aux1=cabP;
	for(i=1;i<=pos&& aux1->sig!=NULL;i++){
		aux1=aux1->sig;
	}
	return aux1->mail;
}


//Metodo par retornar la direccion  de la persona en una posicion
template<class T>
T persona<T>::retornarDi(int pos){
    int i;
	nodoPersona<T> *aux1=cabP;
	for(i=1;i<=pos&& aux1->sig!=NULL;i++){
		aux1=aux1->sig;
	}
	return aux1->dire;
}

//Metodo par retornar el barrio de la persona en una posicion
template<class T>
T persona<T>::retornarBa(int pos){
    int i;
	nodoPersona<T> *aux1=cabP;
	for(i=1;i<=pos&& aux1->sig!=NULL;i++){
		aux1=aux1->sig;
	}
	return aux1->barrio;
}

//Metodo par retornar si tiene hijos o no de la persona en una posicion
template<class T>
T persona<T>::retornarHi(int pos){
    int i;
	nodoPersona<T> *aux1=cabP;
	for(i=1;i<=pos&& aux1->sig!=NULL;i++){
		aux1=aux1->sig;
	}
	return aux1->hijos;
}

//Metodo par retornar el numero de hijos de la persona en una posicion
template<class T>
T persona<T>::retornarNumHij(int pos){
    int i;
	nodoPersona<T> *aux1=cabP;
	for(i=1;i<=pos&& aux1->sig!=NULL;i++){
		aux1=aux1->sig;
	}
	return aux1->numhijos;
}

//Metodo par retornar el tipo de id de la persona en una posicion
template<class T>
T persona<T>::retornarTi(int pos){
    int i;
	nodoPersona<T> *aux1=cabP;
	for(i=1;i<=pos&& aux1->sig!=NULL;i++){
		aux1=aux1->sig;
	}
	return aux1->settipoid;
}

//Metodo par retornar el numero de id de la persona en una posicion
template<class T>
T persona<T>::retornarNumId(int pos){
    int i;
	nodoPersona<T> *aux1=cabP;
	for(i=1;i<=pos&& aux1->sig!=NULL;i++){
		aux1=aux1->sig;
	}
	return aux1->numid;
}

//Metodo par retornar el genero de la persona de la persona en una posicion
template<class T>
T persona<T>::retornarGe(int pos){
    int i;
	nodoPersona<T> *aux1=cabP;
	for(i=1;i<=pos&& aux1->sig!=NULL;i++){
		aux1=aux1->sig;
	}
	return aux1->genero;
}

//Metodo par retornar la fecha de nacimiento de la persona en una posicion
template<class T>
T persona<T>::retornarFn(int pos){
    int i;
	nodoPersona<T> *aux1=cabP;
	for(i=1;i<=pos&& aux1->sig!=NULL;i++){
		aux1=aux1->sig;
	}
	return aux1->fecnac;
}

//Metodo par retornar la edad de la persona en una posicion
template<class T>
T persona<T>::retornarEd(int pos){
    int i;
	nodoPersona<T> *aux1=cabP;
	for(i=1;i<=pos&& aux1->sig!=NULL;i++){
		aux1=aux1->sig;
	}
	return aux1->edad;
}

//Metodo par retornar la ciudad de nacimiento de la persona en una posicion
template<class T>
T persona<T>::retornarCn(int pos){
    int i;
	nodoPersona<T> *aux1=cabP;
	for(i=1;i<=pos&& aux1->sig!=NULL;i++){
		aux1=aux1->sig;
	}
	return aux1->cidnac;
}

//Metodo par retornar el pais de nacimiento  de la persona en una posicion
template<class T>
T persona<T>::retornarPn(int pos){
    int i;
	nodoPersona<T> *aux1=cabP;
	for(i=1;i<=pos&& aux1->sig!=NULL;i++){
		aux1=aux1->sig;
	}
	return aux1->paisnac;
}

//Metodo par retornar la ciudad de residencia de la persona en una posicion
template<class T>
T persona<T>::retornarCr(int pos){
    int i;
	nodoPersona<T> *aux1=cabP;
	for(i=1;i<=pos&& aux1->sig!=NULL;i++){
		aux1=aux1->sig;
	}
	return aux1->cidres;
}

//Metodo par retornar la actividad  de la persona en una posicion
template<class T>
T persona<T>::retornarAc(int pos){
    int i;
	nodoPersona<T> *aux1=cabP;
	for(i=1;i<=pos&& aux1->sig!=NULL;i++){
		aux1=aux1->sig;
	}
	return aux1->actividad;
}

//Metodo par retornar el nombre de la iglesia de la persona en una posicion
template<class T>
T persona<T>::retornarIglesia(int pos){
    int i;
	nodoPersona<T> *aux1=cabP;
	for(i=1;i<=pos&& aux1->sig!=NULL;i++){
		aux1=aux1->sig;
	}
	return aux1->iglesia;
}


//	--------------------------------------------------------------Metodos consulta clase persona-------------------------------------------------------
//Metodo para insertar un hijo a la persona y se guarda en en forma ascendente segun la edad y con el id del padre sabremos quien es el padre
template<class T>
void persona<T>::insertarHijo(char idPadre[2], char nombre[25], char fech[10], char edad[2]){

	string idAux(idPadre);
	string nomAux(nombre);
	string fechaAux(fech);
	string edadAux(edad);
	
	nodoHijos<T> *aux,*auxT,*aux1=cabH;
	aux=new nodoHijos<T>;
	aux->idPadre = idAux;
	aux->nomb = nomAux;
	aux->fechaNaci = fechaAux;
	aux->edad = edadAux;
	aux->sig=0;
	while(aux1->sig != 0 && aux1->edad < aux->edad){
		aux1=aux1->sig;
	}
	auxT=aux1;
	if(aux1->edad > aux->edad){
			auxT=aux1;
            aux1=aux;
			aux=auxT;
			aux1->ant=aux->ant;
			aux->ant->sig=aux1;
	}
	aux1->sig=aux;
	aux->ant=aux1;

}

//Metodo para retornar el nombre del hijo en una posicion dada
template<class T>
T persona<T>::retornarHijo(int pos){
    int i;
	nodoHijos<T> *aux1=cabH;
	for(i=1;i<=pos&& aux1->sig!=NULL;i++){
		aux1=aux1->sig;
	}
	return aux1->nomb;
}


//Metod para buscar cuantas personas estan en una iglesia
template<class T>
void persona<T>::buscarIglesia(char iglesia[15]){
	string iglesiaAux(iglesia);
	int cont=0;
	nodoPersona<T> *aux1=cabP;
	while(aux1->sig!=NULL){
		aux1=aux1->sig;
		if(aux1->iglesia==iglesiaAux){
			cont++;
		}
	}
	cout<<"El numero de personas en la iglesia "<<iglesiaAux<<" es de: "<<cont<<endl;
}



#endif
