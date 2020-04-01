#ifndef Multilista_H
#define Multilista_H

#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;

struct cabecera{
	string caracteristicas;
	int pos;
};
	

struct info{
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
	int sigSexo,sigActividad, sigNHijos,sigCiudad;
};
	

class Multilista{
	int tamanio;
	
	cabecera ListaCab[12];
	info *Datos;
	public:
		Multilista(int tam){//Constructor de la clase multilista
			tamanio = tam+1;
			Datos= new info[tamanio];
			iniciar();
		}

void iniciar();
void mostrarListaCab();
void insertar(char ingid[3], char ingnombre[10], char ingapellido[20], char settipoid[2], char ingdocumento[15], char genero[2], char ingfijo[10], char ingcelular[10], char ingemail[30],
			 char ingfechaNac[10], char ingedad[2], char ingciudadNac[15], char ingpaisNac[15], char ingciudadRes[15], char ingdireccion[30], char ingbarrio[15], char ingactividad[25], char hijos[2], char ingnumhijos[2], char iglesia[15]);
void insertar_sexo(int);
void insertar_actividad(int);
void insertar_NumeroHijos(int);
void insertar_Ciudad(int);
void mostrar_sexo(int);
void mostrar_actividad();
void mostrar_Nhijos(int);
void mostrar_Ciudad();
int contarAsistentes(string );


};

//muestra los generos ordenados de la multilista
void Multilista::mostrar_sexo(int gen){
	int cont=0;
	int aux;
	if(gen==1){
		aux = ListaCab[0].pos;
	}else{
		aux = ListaCab[1].pos;
	}
	while(aux!=0){
		insertar_Ciudad(aux);
		aux = Datos[aux].sigSexo;
		cont++;
	}
	cout<<" es de: "<<cont<<endl;
	mostrar_Ciudad();	
}
//muestra los numeros de hijos ordenados de la multilista
void Multilista::mostrar_Nhijos(int rango){
	int aux;
	if(rango==1){
		aux = ListaCab[7].pos;
	} else if(rango==2){
		aux = ListaCab[8].pos;
	} else if(rango==3){
		aux = ListaCab[9].pos;
	} else{
		aux = ListaCab[10].pos;
	}
	
	while(aux!=0){
		insertar_Ciudad(aux);
		aux = Datos[aux].sigNHijos;
	}
	mostrar_Ciudad();

}
//muestra las ciudades ordenados de la multilista
void Multilista::mostrar_Ciudad(){
	int aux = ListaCab[11].pos;
	while(aux!=0){
		cout<<Datos[aux].nombre<<" "<<Datos[aux].cidres<<endl;
		aux = Datos[aux].sigCiudad;
	}
}
//muestra las actividades ordenados de la multilista
void Multilista::mostrar_actividad(){
	int aux = ListaCab[2].pos;
	int aux1 = ListaCab[3].pos;
	int aux2 = ListaCab[4].pos;
	int aux3 = ListaCab[5].pos;
	int aux4 = ListaCab[6].pos;
	while(aux!=0){
		cout<<Datos[aux].nombre<<" "<<Datos[aux].actividad<<endl;
		aux = Datos[aux].sigActividad;
	}
	while(aux1!=0){
		cout<<Datos[aux1].nombre<<" "<<Datos[aux1].actividad<<endl;
		aux1 = Datos[aux1].sigActividad;
	}
	while(aux2!=0){
		cout<<Datos[aux2].nombre<<" "<<Datos[aux2].actividad<<endl;
		aux2 = Datos[aux2].sigActividad;
	}
	while(aux3!=0){
		cout<<Datos[aux3].nombre<<" "<<Datos[aux3].actividad<<endl;
		aux3 = Datos[aux3].sigActividad;
	}
	while(aux4!=0){
		cout<<Datos[aux4].nombre<<" "<<Datos[aux4].actividad<<endl;
		aux3 = Datos[aux4].sigActividad;
	}	
}

//inicia la lista de cabezas asignandoles un valor de 0 
void Multilista::iniciar(){
	ListaCab[0].caracteristicas = "F  "; ListaCab[0].pos = 0;
	ListaCab[1].caracteristicas = "M  "; ListaCab[1].pos = 0;
	ListaCab[2].caracteristicas = "Artes"; ListaCab[2].pos = 0;
	ListaCab[3].caracteristicas = "Ingenieria"; ListaCab[3].pos = 0;
	ListaCab[4].caracteristicas = "Ciencias Sociales"; ListaCab[4].pos = 0;
	ListaCab[5].caracteristicas = "Areas de la salud"; ListaCab[5].pos = 0;
	ListaCab[6].caracteristicas = "Otros"; ListaCab[6].pos = 0;
	ListaCab[7].caracteristicas = "sin hijos"; ListaCab[7].pos = 0;
	ListaCab[8].caracteristicas = "1-2"; ListaCab[8].pos = 0;
	ListaCab[9].caracteristicas = "3-4"; ListaCab[9].pos = 0;
	ListaCab[10].caracteristicas = "+4"; ListaCab[10].pos = 0;
	ListaCab[11].caracteristicas = "Ciudad"; ListaCab[11].pos = 0;
}

//metodo el cual inserta los datos en la ultima posicion del arreglo que este libre 
void Multilista::insertar(char ingid[3], char ingnombre[10], char ingapellido[20], char settipoid[2], char ingdocumento[15], char genero[2], char ingfijo[10], char ingcelular[10], char ingemail[30],
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
	int i=0;
	while(i<tamanio){ //inserta en la ultima posicion del arreglo
		if(Datos[i].id == ""){ //inserta todos los datos 
			Datos[i].id=idAux;
			Datos[i].nombre=nombreAux;
			Datos[i].apellido=apellidoAux;
			Datos[i].settipoid=settAux;
			Datos[i].numid=documentoAux;
			Datos[i].genero=generoAux;
			Datos[i].telf=fijoAux;
			Datos[i].telc=celularAux;
			Datos[i].mail=emailAux;
			Datos[i].fecnac=fechaNacAux;
			Datos[i].edad=edadAux;
			Datos[i].cidnac=ciudadNacAux;
			Datos[i].paisnac=paisNacAux;
			Datos[i].cidres=ciudadResAux;
			Datos[i].dire=direccAux;
			Datos[i].barrio=barrioAux;
			Datos[i].actividad=actividadAux;
			Datos[i].hijos=hijosAux;
			Datos[i].numhijos=numHijosAux;
			Datos[i].iglesia=iglesiaAux;
			insertar_sexo(i);
			insertar_actividad(i);
			insertar_NumeroHijos(i);
			break;
		}else{
			i++;
		}
	}
	if(i==tamanio){
		cout<<"Lo siento no pueden ingresar mas valores"<<endl;
	}	
}
//inserta el ciudad de menor a mayor
void Multilista::insertar_Ciudad(int i){
	int j,aux;
	if(ListaCab[11].pos==0){
		Datos[i].sigCiudad =0;
		ListaCab[11].pos = i;
	} else {
		j = ListaCab[11].pos;
		
		if(strcmp(Datos[i].cidres.c_str(),Datos[j].cidres.c_str())<=0){
			ListaCab[11].pos = i;
			Datos[i].sigCiudad = j;	
		} else{
			while(strcmp(Datos[i].cidres.c_str(),Datos[j].cidres.c_str())>0 && j!=10){
				aux = j;
				j = Datos[j].sigCiudad;
			}
			Datos[i].sigCiudad = j;
			Datos[aux].sigCiudad = i;	
		}		 
	}	
}
//insertar segun el numero de hijos en el ultimo
void Multilista::insertar_NumeroHijos(int i){
	int opcion,j,aux,numH;	
	numH= atoi(Datos[i].numhijos.c_str());
	if(numH==0){
		opcion = 0;
	} else if(numH>0 && numH<3){
		opcion = 1;
	} else if(numH==3 || numH==4){
		opcion = 2;
	} else{
		opcion = 3;
	} 
		
	switch(opcion){
		case 0:
			if(ListaCab[7].pos==0){
				Datos[i].sigNHijos =0;
				ListaCab[7].pos = i;
			} else {
				j = ListaCab[7].pos;
				while(j!=0){
					aux = j;
					j = Datos[j].sigNHijos;	
				}
				Datos[i].sigNHijos = j;
				Datos[aux].sigNHijos = i;
			}
		break;
		case 1:
			if(ListaCab[8].pos==0){
				Datos[i].sigNHijos =0;
				ListaCab[8].pos = i;
			} else {
				j = ListaCab[8].pos;
				while(j!=0){
					aux = j;
					j = Datos[j].sigNHijos;	
				}
				Datos[i].sigNHijos = j;
				Datos[aux].sigNHijos = i;
			}
		break;
		case 2:
			if(ListaCab[9].pos==0){
				Datos[i].sigNHijos =0;
				ListaCab[9].pos = i;
			} else {
				j = ListaCab[9].pos;
				while(j!=0){
					aux = j;
					j = Datos[j].sigNHijos;	
				}
				Datos[i].sigNHijos = j;
				Datos[aux].sigNHijos = i;
			}
		break;
		case 3:
			if(ListaCab[10].pos==0){
				Datos[i].sigNHijos =0;
				ListaCab[10].pos = i;
			} else {
				j = ListaCab[10].pos;
				while(j!=0){
					aux = j;
					j = Datos[j].sigNHijos;	
				}
				Datos[i].sigNHijos = j;
				Datos[aux].sigNHijos = i;
			}
		break;
	
	}
}
//inserta el actividad al ultimo
void Multilista::insertar_actividad(int i){
	int opcion,j,aux;
	if(Datos[i].actividad=="Artes"){
		opcion = 0;
	} else if(Datos[i].actividad=="Ingenieria"){
		opcion = 1;
	} else if(Datos[i].actividad=="Ciencias Sociales"){
		opcion = 2;
	} else if(Datos[i].actividad=="Areas de la salud"){
		opcion = 3;
	} else{
		opcion = 4;
	}
		
	switch(opcion){
		case 0:
			if(ListaCab[2].pos==0){
				Datos[i].sigActividad =0;
				ListaCab[2].pos = i;
			} else {
				j = ListaCab[2].pos;
				while(j!=0){
					aux = j;
					j = Datos[j].sigActividad;	
				}
				Datos[i].sigActividad = j;
				Datos[aux].sigActividad = i;
			}
		break;
		case 1:
			if(ListaCab[3].pos==0){
				Datos[i].sigActividad =0;
				ListaCab[3].pos = i;
			} else {
				j = ListaCab[3].pos;
				while(j!=0){
					aux = j;
					j = Datos[j].sigActividad;	
				}
				Datos[i].sigActividad = j;
				Datos[aux].sigActividad = i;
			}
		break;
		case 2:
			if(ListaCab[4].pos==0){
				Datos[i].sigActividad =0;
				ListaCab[4].pos = i;
			} else {
				j = ListaCab[4].pos;
				while(j!=0){
					aux = j;
					j = Datos[j].sigActividad;	
				}
				Datos[i].sigActividad = j;
				Datos[aux].sigActividad = i;
			}
		break;
		case 3:
			if(ListaCab[5].pos==0){
				Datos[i].sigActividad =0;
				ListaCab[5].pos = i;
			} else {
				j = ListaCab[5].pos;
				while(j!=0){
					aux = j;
					j = Datos[j].sigActividad;	
				}
				Datos[i].sigActividad = j;
				Datos[aux].sigActividad = i;
			}
		break;
		case 4:
			if(ListaCab[6].pos==0){
				Datos[i].sigActividad =0;
				ListaCab[6].pos = i;
			} else {
				j = ListaCab[6].pos;
				while(j!=0){
					aux = j;
					j = Datos[j].sigActividad;	
				}
				Datos[i].sigActividad = j;
				Datos[aux].sigActividad = i;
			}
		break;
		
	}
}

//inserta el genero al ultimo
void Multilista::insertar_sexo(int i){
	int opcion,j,aux;
	if(Datos[i].genero=="F  "){
		opcion = 0;
	} else{
		opcion = 1;
	} 
	
	switch(opcion){
		case 0:
			if(ListaCab[0].pos==0){
				Datos[i].sigSexo =0;
				ListaCab[0].pos = i;
			} else {
				j = ListaCab[0].pos;
				while(j!=0){
					aux = j;
					j = Datos[j].sigSexo;	
				}
				Datos[i].sigSexo = j;
				Datos[aux].sigSexo = i;
			}
		break;
		case 1:
			if(ListaCab[1].pos==0){
				Datos[i].sigSexo =0;
				ListaCab[1].pos = i;
			} else {
				j = ListaCab[1].pos;
				while(j!=0){
					aux = j;
					j = Datos[j].sigSexo;	
				}
				Datos[i].sigSexo = j;
				Datos[aux].sigSexo = i;
			}
		break;
		
	}
}

//muestra la lista de cabezas
void Multilista::mostrarListaCab(){
	for(int i=0;i< 12;i++){
		cout<<ListaCab[i].caracteristicas<<" "<<ListaCab[i].pos<<endl;
	}
}
//muestra la lista de cabezas
int Multilista::contarAsistentes(string iglesia){
	int cont=0;
	int aux = ListaCab[11].pos;
	while(aux!=0){
		cout<<Datos[aux].nombre<<" "<<Datos[aux].cidres<<endl;
		aux = Datos[aux].sigCiudad;
	}
	Multilista multilista(0);
	if(	multilista->Datos->iglesia==iglesia){
		cont++;
	}
	return cont;
}

#endif
