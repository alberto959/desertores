#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <fstream>
#include <conio.h>
#include <cstdlib>
#include "Feligreses.h"		//Llama a la libreira Feligreses.h
#include "Lista.h"		//Llama a la libreira Lista.h
#include "Multilista.h"		//Llama a la libreira Multilista.h
#define MAX 208 	//Tamaño maximo para el archivo Personas.txt
#define MAX2 85		//Tamaño maximo para el archivo iglesias.txt
#define MAX3 39		//Tamaño maximo para el archivo Hijos.txt
#define MAX4 40		//Tamaño maximo para el archivo Paises.txt
#define MAX5 40     //Tamaño maximo para el archivo Localidades.txt

//Funcion la cual recupera la fecha del computador en el formato DD/MM/AAAA
string fecha(){
	time_t t;
  	struct tm *tm;
  	char fechayhora[100];

	t=time(NULL);
	tm=localtime(&t);
	strftime(fechayhora, 100, "%d/%m/%Y", tm);
	return fechayhora;
}

//Funcion para imprimir los datos que contenga un archivo
void print(FILE *fp){
	char ch;
	
	while((ch = fgetc(fp)) != EOF ){
		cout<<ch;
	}
}

void editar(string dato,int pos);	//Declaracion de la funcion editar
void eliminar(int pos);				//Declaracion de la funcion eliminar

//Funcion que servira como el cuerpo del programa ya que todas las operaciones ocurren aqui
void funcionPrincipal(int opcionPrincipal){
	
//	--------------------------------------------------------------Cargar Personas-------------------------------------------------------
	
	char line[MAX];		//Tamaño para el archivo Persona.txt
	char id[3];			//Parametros de un feligres para registrarlo
    char nombre[10];
  	char apellido[20];
    char tipoid[2]; 
    char cedula[10];
    char genero[2];
    char fijo[10];
    char celular[10];
    char email[30];
    char fechaNac[10];
    char edad[2];
    char ciudadNac[15];
    char paisNac[15];
    char ciudadRes[15];
    char direccion[30];
    char barrio[15];
    char actividad[15];
    char hijos[2];
    char numhijos[2];
    char iglesia[15];
    
    persona<string> Persona;		//Persona de tipo de dato string
    lista<string> Fem;				//Lista de tipo de dato string para las personas de genero femenino
	lista<string> Mas;				//Lista de tipo de dato string para las personas de genero masculino
	
    FILE *archivo=fopen("Personas.txt","rt");		//Abre el archivo con el nombre Personas.txt
    
    if(!archivo)            // Comparacion para saber si existe un archivo con ese nombre o no
        cout<<"No existe"<<endl;    // The file was not found.
    else
    	cout<<"Existe"<<endl;

    int i=0,num=0;			//Auxiliar para saber cuantas lineas tiene el archivo
    fgets(line,MAX,archivo);		//Lee la linea en la que esta
    //cout<<"| Id | Nombre | Apellido | Tipo ID | Cedula | Genero | Fijo | Celular | Email | Fecha Nacimiento |"<<endl;
    //cout<<"| Edad | Ciud Naci | Pais Naci | Ciud Resid | Direccion | Barrio | Actividad | Hijos | Num Hijos | Iglesia |"<<endl;
    while(!feof(archivo)){
    	num++;
    	fgets(line,MAX,archivo);		//Lee la linea en la que esta
	}
	Multilista multilista(num);
	rewind(archivo);
    
    while(!feof(archivo)) {	//Mientras exista que leer en el archivo
        i++;	//Aumenta el auxiliar en 1
        
        //la funcion sscanf es para leer lo que se encuentra en esa linea y cada : lo separa y le pasa esos valores a los parametros del feligres
        sscanf(line,"%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:]:%[^:\n]", id, nombre, apellido, tipoid, cedula, genero, fijo, celular, email, fechaNac, edad, ciudadNac, paisNac, ciudadRes, direccion, barrio, actividad, hijos, numhijos, iglesia); //%[^:]:
        //Limpia el buffer del teclado
    	fflush(stdin);
    //	cout<<"| "<<id<<" | "<<nombre<<" | "<<apellido<<" | "<<tipoid<<" | "<<cedula<<" | "<<genero<<" | "<<fijo<<" | "<<celular<<" | "<<email<<" | "<<fechaNac<<" | "<<endl;
   	//   cout<<"| "<<edad<<" | "<<ciudadNac<<" | "<<paisNac<<" | "<<ciudadRes<<" | "<<direccion<<" | "<<barrio<<" | "<<actividad<<" | "<<hijos<<" | "<<numhijos<<" | "<<iglesia<<endl;
		//Inserta la persona con los datos que recupero de la linea en la que se encuentra
		Persona.insertarPersona(id, nombre, apellido, tipoid, cedula, genero, fijo, celular, email, fechaNac, edad, ciudadNac, paisNac, ciudadRes, direccion, barrio, actividad, hijos, numhijos, iglesia);
		multilista.insertar(id, nombre, apellido, tipoid, cedula, genero, fijo, celular, email, fechaNac, edad, ciudadNac, paisNac, ciudadRes, direccion, barrio, actividad, hijos, numhijos, iglesia);
		if(Persona.retornarGe(i)=="F  "){
			Fem.insertarLista(iglesia,id);
		}else{
			Mas.insertarLista(iglesia,id);
		}
		fgets(line,MAX,archivo);	//Lee la siguiente linea
    }
    //cout<<"Line: "<<i<<endl;
    //	--------------------------------------------------------------Cargar iglesias-------------------------------------------------------
    
	char line2[MAX2];		//Tamaño maximo para el archivo iglesiaes.txt
	char nombreIglesia[20];		//Parametros que debe tener la iglesia
    char direccionIglesia[30];
    char barrioIglesia[15];
    char pastorIglesia[20];
	
	Iglesia<string> Iglesia;		//Iglesia de tipo de dato string
	
	FILE *Iglesias=fopen("Iglesias.txt","rt");		//Abre el archivo con el nombre Iglesias.txt		
    
    if(!Iglesias)      					//Comparacion para saber si existe el archivo o no
        cout<<"No existe"<<endl;   

    int j=0;	//Auxiliar para saber el numero de lineas que tiene el archivo Iglesias.txt
    fgets(line2,MAX2,Iglesias);		//Lee la primera linea del archivo Iglesias.txt
    
    //	cout<<"| Nombre Iglesia | Direccion Iglesia | Barrio Iglesia | Pastor Iglesia | "<<endl;
    
    while(!feof(Iglesias)) {		//Mientras exista siguiente linea para leer
        j++;		//Auto incremento del auxiliar
        //Lee la linea en la que se encuentra y separa por cada : y esos valores se los pasa a los parametros de Iglesia
        sscanf(line2,"%[^:]:%[^:]:%[^:]:%[^:\n]", nombreIglesia, direccionIglesia, barrioIglesia, pastorIglesia); //%[^:]:
    	fflush(stdin);		//Metodo para limpiar el buffer del teclado
		
    //	cout<<" | "<<nombreIglesia<<" | "<<direccionIglesia<<" | "<<barrioIglesia<<" | "<<pastorIglesia<<" | "<<endl;
    	
		Iglesia.insertarIglesia(nombreIglesia, direccionIglesia, barrioIglesia, pastorIglesia);		//Inserta una Iglesia con los parametros recuperados del archivo
    	
		fgets(line2,MAX2,Iglesias); 	//Lee la siguiente linea
	}
	//cout<<"Line: "<<j<<endl;
	
	//	--------------------------------------------------------------Cargar Hijos-------------------------------------------------------
    
	char line3[MAX3];			//Tamaño maximo para el archivo Hijos.txt
	char idPadre[2];		//Parametros de Hijo
	char nombreHijo[25];
    char fechaNacHijo[10];
    char edadHijo[2];
    
	
	FILE *hijosArch=fopen("Hijos.txt","rt");		//Abre el archivo con el nombre Hijos.txt
    
    if(!hijosArch)      				//Condicional para saber si existe un archivo con el nombre Hijos.txt o no
        cout<<"No existe"<<endl;   

    int k=0;						//Auxiliar para saber el numero de lineas del archivo Hijos.txt
    fgets(line3,MAX3,hijosArch);	//Lee la primer linea del archivo
    
    //	cout<<"| idPadre | Nombre Hijo | Fecha Naci Hijo | Edad Hijo | "<<endl;
    
    while(!feof(hijosArch)) {		//Mientras exista proxima linea para leer
        k++;						//Autoincremento a la variable auxiliar
        //Lee todo el dato de la linea y los separa por : y se los pone a los parametros de hijo
        sscanf(line3,"%[^:]:%[^:]:%[^:]:%[^:\n]", idPadre, nombreHijo, fechaNacHijo, edadHijo); //%[^:]:
    	fflush(stdin);				//Limpia el buffer del teclado
    //	cout<<" | "<<idPadre<<" | "<<nombreHijo<<" | "<<fechaNacHijo<<" | "<<edadHijo<<" | "<<endl;
    	
    	Persona.insertarHijo(idPadre, nombreHijo, fechaNacHijo, edadHijo);		//Inserta una persona con los parametros recuperados del archivo Hijos.txt
    	
		fgets(line3,MAX3,hijosArch); 	//Lee la siguiente linea del archvi
	}
	//cout<<"Line: "<<k<<endl;
	
	//	--------------------------------------------------------------Cargar Paises y Ciudades-------------------------------------------------------
    
	char line4[MAX4];		//Tamaño maximo para el archivo Paises.txt
	char ciudad[15];		//Parametros de Ciudad
	char pais[15];
	
	Ciudad<string> Ciudad;		//Ciudad de tipo de dato string
	
	FILE *paises=fopen("Paises.txt","rt");			//Abre el archivo Paises.txt
    
    if(!paises)      					//Condicional para saber si existe el archivo con el nombre Paises.txt o no
        cout<<"No existe"<<endl;   

    int m=0;		//Auxiliar para saber el numero maximo de lineas del archivo Paises.txt
    fgets(line4,MAX4,paises);		//Lee la primera linea del archivo
    
    //	cout<<"| Ciudad | Pais |"<<endl;
    
    while(!feof(paises)) {		//Mientras tenga otra linea para leer
        m++;		//Autoincremento a la variable aux
        //Lee la linea y los separa por : y le pasa esos valores a los parametros de Ciudad
        sscanf(line4,"%[^:]:%[^\n]", ciudad, pais); //%[^:]:
    	fflush(stdin);		//Limpia el buffer del teclado 
    
    //	cout<<" | "<<ciudad<<" | "<<pais<<" | "<<endl;
    	
    	Ciudad.insertarCiudad(ciudad, pais);		//Inserta la ciudad y pais con los datos recuperados del archivo
		    	
		fgets(line4,MAX4,paises); 	//Lee la siguiente linea
	}
	//cout<<"Line: "<<m<<endl;
	//	--------------------------------------------------------------Cargar Barrios y Localidades-------------------------------------------------------
    
	char line5[MAX5];		//Tamaño maximo para el archivo Localidades.txt
	char barrioRegistrado[15];		//Parametros de Localidad
	char localidad[15];
	
	Localidad<string> Localidad;		//Ciudad de tipo de dato string
	
	FILE *Localidades=fopen("Localidades.txt","rt");			//Abre el archivo Localidades.txt
    
    if(!Localidades)      					//Condicional para saber si existe el archivo con el nombre Localidades.txt o no
        cout<<"No existe"<<endl;   

    int b=0;		//Auxiliar para saber el numero maximo de lineas del archivo Localidades.txt
    fgets(line5,MAX5,Localidades);		//Lee la primera linea del archivo
    
    //	cout<<"| barrioRegistrado | Localidad |"<<endl;
    
    while(!feof(Localidades)) {		//Mientras tenga otra linea para leer
        b++;		//Autoincremento a la variable aux
        //Lee la linea y los separa por : y le pasa esos valores a los parametros de localidad
        sscanf(line5,"%[^:]:%[^:\n]", barrioRegistrado, localidad); //%[^:]:
    	fflush(stdin);		//Limpia el buffer del teclado 
    
    	//cout<<" | "<<barrioRegistrado<<" | "<<localidad<<" | "<<endl;
    	
    	Localidad.insertarLocalidad(localidad, barrioRegistrado);		//Inserta la localudad y barrio con los datos recuperados del archivo  	
		fgets(line5,MAX5,Localidades); 	//Lee la siguiente linea
	}
	//cout<<"Line: "<<b<<endl;
	
	//	--------------------------------------------------------------FUNCIONES DEL MENU -------------------------------------------------------

	switch(opcionPrincipal){		//Switch para las operaciones que se realizaran 
		case 1:{		//Agregar un nuevo feligres
			
		//	--------------------------------------------------------------AGREGAR FELIGRES -------------------------------------------------------
				
			char ingid[3];					//PARAMETROS DEL NUEVO FELIGRES
		    char ingnombre[10];
		    char ingapellido[20];
		    int ingtipoid; 					//Variable para ayudar con la eleccion del tipo de id
		    char settipoid[2]; 
		    char ingdocumento[15];
		    int inggenero;					//Variable para ayudar con la eleccion de genero
		    char aggenero[2];
		    char ingfijo[10];
		    char ingcelular[10];
		    char ingemail[30];
		    char ingfechaNac[10];
		    char ingedad[2];
		    int intciudad;				//Variable para ayudar a seleccionar una ciudad de nacimiento y el pais
		    char ingciudadNac[15];
		    char ingpaisNac[15];
		    int intresid;			//Variable para ayudar a seleccionar la ciudad actual donde recide
		    char ingciudadRes[15];
		    char ingdireccion[30];
		    int intbarrio;			//Variable para ayudar a seleccionar la barrio donde recide
		    char ingbarrio[15];
		    char ingactividad[25];
		    char aghijos;
		    char inghijos[2];
		    char ingnumhijos[2];
		    int ingIglesia;			//Variable para ayudar a seleccionar la iglesia
		    int edadPersona;
		    char agIglesia[15];
		    
		    char NombreHijo[25];		//Parametros de hijos
		    char FechaNaciHijo[10];
		    int edadHijo;
		    char agedadHijo[2];
		
			ofstream personas;			//Crea un fichero personas
		    personas.open("Personas.txt",ios::app);		//El fichero abre el archivo Personas.txt
		    
		    ofstream hijosArch2;			//Crea un fichero hijosArch2
		    hijosArch2.open("Hijos.txt",ios::app);	//El fichero abre el archivo Hijos.txt
		    
		    if(!personas)         //Condicional para saber si existe el archivo Personas.txt o no  
		        cout<<"No existe"<<endl;
		    
		    if(!hijosArch2)           
		        cout<<"No existe"<<endl;	//Condicional para saber si existe el archivo Hijos.txt
		        
		    int valorID = atoi(id);		//Auxiliar para saber el valor del id y el atoi es para cambiar de char a int
		    
			if(valorID>=i){		//Si el valorID es mayor o igual que el numero de linea del archivo Personas.txt aumenta en 1
		    	valorID++;
			}   
				//	--------------------------------------------------------------Pedir los datos para agregar -------------------------------------------------------
			cout<<"El id es: "<<endl;
			itoa(valorID, ingid, 10);		//Pasa de entero a char y este seria el id del feligres
			cout<<ingid;													
		
			cout<<endl<<"Ingrese Nombre"<<endl;
			cin>>ingnombre;
							
			cout<<"Ingrese Apellido"<<endl;
			cin>>ingapellido;
			do{									//Ciclo hasta que seleccione un tipo de id correcto
			cout<<"Ingrese Tipo de ID\n"
				"1. Cedula Ciudadania\n"
				"2. Cedula Extranjeria\n"
				"3. Tarjeta Identidad"<<endl;
			cin>>ingtipoid;
			switch(ingtipoid){
					case 1:
						settipoid[0] = 'C';
						settipoid[1] = 'C';
						settipoid[2] = ' ';
						break;
					case 2:
						settipoid[0] = 'C';
						settipoid[1] = 'E';
						settipoid[2] = ' ';
						break;
					case 3:
				    	settipoid[0] = 'T';
						settipoid[1] = 'I';
						settipoid[2] = ' ';
				    	break;
					default:
						cout<<"Dato incorrecto,intenta de nuevo"<<endl;
						break;
				}
				
			}while(ingtipoid>3 || ingtipoid<1);
			cout<<"Ingrese Numero de ID"<<endl;
			cin>>ingdocumento;
			
			do{								//Ciclo para que ingrese un genero correcto
			cout<<"Ingrese Sexo\n"
				"1. Femenino\n"
				"2. Masculino"<<endl;
			cin>>inggenero;
			
				switch(inggenero){
					case 1:
						aggenero[0] ='F';
						aggenero[1] =' ';
						aggenero[2] =' ';
						break;
					case 2:
						aggenero[0] ='M';
						aggenero[1] =' ';
						aggenero[2] =' ';
						break;
					default:
						cout<<"Dato incorrecto,Ingresalo de nuevo"<<endl;
						break;
				}	
			}while(inggenero>2 || inggenero<1 );
			
			cout<<"Ingrese Numero Telefono Fijo"<<endl;
			cin>>ingfijo;
			
			cout<<"Ingrese Numero Telefono Celular"<<endl;
			cin>>ingcelular;
		
			cout<<"Ingrese Email"<<endl;
			cin>>ingemail;																
			
			cout<<"Ingrese Fecha de Nacimiento Formato: DD/MM/AAAA"<<endl;
			cin>>ingfechaNac;
			
			string per1,dia3,dia4,mes3,mes4,actual,cad2;		
			string fechaN(ingfechaNac);				//Pasamos la fecha de char a string en una variable
			
			per1 = fechaN.substr (6);		//Este string recibe la fecha que ingreso el feligres y pone solo el año
			actual = fecha();				//Recupera la fecha del sistema
			cad2 = actual.substr (6);		//La fecha del sistema le deja solo el año
			dia3= fechaN.substr(0,2);		//Recupera el dia que nacio el feligres
			dia4=actual.substr(0,2);		//Recupera el dia actual 
					
			mes3=fechaN.substr(3,2);		//Recupera el mes de nacimiento del feligres
			mes4=actual.substr(3,2);		//Recupera el mes del sistema
			
			edadPersona=atoi(cad2.c_str())- atoi(per1.c_str());			//Edad del feligres
			
			if(mes3>mes4){						//Condicional para saber si ya cumplio años o aun no
				edadPersona= edadPersona-1;
			}else if(mes3==mes4 && dia3>dia4){
				edadPersona= edadPersona-1;
			}	
			itoa(edadPersona, ingedad, 10);
			
			
		
			do{												//Ciclo para que seleccione una ciudad y pais correctos
				cout<<"Ingrese Ciudad de Nacimiento"<<endl;
				Ciudad.ciud();
				cin>>intciudad;
				if(intciudad>m){
					cout<<"Dato incorrecto,ingresalo de nuevo"<<endl;
				}
			
			}while(intciudad>m);
			
			strcpy(ingciudadNac,Ciudad.retornarCiudad(intciudad).c_str());		//Este metodo copia el valor de un string a otro string
			cout<<ingciudadNac<<endl;
			
			cout<<"Pais de Nacimiento"<<endl;
			strcpy(ingpaisNac,Ciudad.retornarPais(intciudad).c_str());	
			cout<<ingpaisNac<<endl;
						
			do{													//Ciclo para que seleccione una ciudad de residencia valida
				cout<<"Ingrese Ciudad de Residencia"<<endl;
				Ciudad.ciud();
				cin>>intresid;
				if(intresid>m){
					cout<<"Dato incorrecto,ingresalo de nuevo"<<endl;
				}
			
			}while(intresid>m);
			strcpy(ingciudadRes,Ciudad.retornarCiudad(intresid).c_str());	
			cout<<ingciudadRes<<endl;	
			
			cin.ignore();	

			cout<<"Ingrese Direccion"<<endl;
			cin.getline(ingdireccion,30);
			
			do{													//Ciclo para que seleccione una barrio de residencia valida
				cout<<"Ingrese barrio de Residencia"<<endl;
				Localidad.Localidades();
				cin>>intbarrio;
				if(intbarrio>b){
					cout<<"Dato incorrecto,ingresalo de nuevo"<<endl;
				}
			
			}while(intbarrio>b);
			strcpy(ingbarrio,Localidad.retornarBarrio(intbarrio).c_str());	
			cout<<ingbarrio<<endl;
			
			cin.ignore();
			int opc;
			
			do{								//Ciclo para que seleccione una actividad valida
			cout<<"Ingrese Actividad Laboral"<<endl;
			cout<<"1. Artes\n2. Ingenieria\n3. Ciencias Sociales\n4. Areas de la salud\n5. Otros "<<endl;
			
			cin>>opc;
			switch(opc){
				case 1:
					ingactividad[0] = 'A';
					ingactividad[1] = 'r';
					ingactividad[2] = 't';
					ingactividad[3] = 'e';
					ingactividad[4] = 's';
					break;
				case 2:
					ingactividad[0] = 'I';
					ingactividad[1] = 'n';
					ingactividad[2] = 'g';
					ingactividad[3] = 'e';
					ingactividad[4] = 'n';
					ingactividad[5] = 'i';
					ingactividad[6] = 'e';
					ingactividad[7] = 'r';
					ingactividad[8] = 'i';
					ingactividad[9] = 'a';
					break;
				case 3:
					ingactividad[0] = 'C';
					ingactividad[1] = 'i';
					ingactividad[2] = 'e';
					ingactividad[3] = 'n';
					ingactividad[4] = 'c';
					ingactividad[5] = 'i';
					ingactividad[6] = 'a';
					ingactividad[7] = 's';
					ingactividad[8] = ' ';
					ingactividad[9] = 'S';
					ingactividad[10] = 'o';
					ingactividad[11] = 'c';
					ingactividad[12] = 'i';
					ingactividad[13] = 'a';
					ingactividad[14] = 'l';
					ingactividad[15] = 'e';
					ingactividad[16] = 's';
					break;
				case 4:
					ingactividad[0] = 'A';
					ingactividad[1] = 'r';
					ingactividad[2] = 'e';
					ingactividad[3] = 'a';
					ingactividad[4] = 's';
					ingactividad[5] = ' ';
					ingactividad[6] = 'd';
					ingactividad[7] = 'e';
					ingactividad[8] = ' ';
					ingactividad[9] = 'l';
					ingactividad[10] = 'a';
					ingactividad[11] = ' ';
					ingactividad[12] = 's';
					ingactividad[13] = 'a';
					ingactividad[14] = 'l';
					ingactividad[15] = 'u';
					ingactividad[16] = 'd';			
					break;
				case 5:
					ingactividad[0] = 'O';
					ingactividad[1] = 't';
					ingactividad[2] = 'r';
					ingactividad[3] = 'o';
					ingactividad[4] = 's';
					break;
				default:
					cout<<"Dato incorrecto, ingresalo de nuevo"<<endl;
					break;
				}
			}while(opc>5 || opc<1);	
			
			bool cond = false;			//Condicion para saber si selecciono una opcion valida
			do{
	
				cout<<"Tiene hijos? S o N"<<endl;
				cin>>aghijos;
			
				if(aghijos == 'S' || aghijos == 'N'){
					cond=true;
				}
				switch(aghijos){
					case 'S':
						cout<<"Ingrese el numero de hijos"<<endl;
						int numero;
						cin>>numero;
						inghijos[0] = 'S';
						inghijos[1] = ' ';
						inghijos[2] = ' ';
						
						
						itoa(numero,ingnumhijos,10);
						cout<<ingnumhijos<<endl;						
						for(int w=0; w<numero; w++){
							cout<<"Ingrese el nombre del hij@"<<endl;
							cin>>NombreHijo;
							cout<<"Ingrese el fecha de nacimiento del hij@  FORMATO: DD/MM/AAAA"<<endl;
							cin>>FechaNaciHijo;
							
							
							string fechaNH(FechaNaciHijo);				//Serie de pasos para recuperar la edad del hijo y saber si cumplio años ya o aun no
							
							string cad1 = fechaNH.substr (6);
							string actual = fecha();
							string cad2 = actual.substr (6);	
							string dia1=fechaNH.substr(0,2);
							string dia2=actual.substr(0,2);

							string mes1=fechaNH.substr(3,2);
							string mes2=actual.substr(3,2);

							edadHijo=atoi(cad2.c_str())- atoi(cad1.c_str());
							
							if(mes1>mes2){
								edadHijo= edadHijo-1;
							}else if(mes1==mes2 && dia1>dia2){
								edadHijo= edadHijo-1;
							}	
							
							itoa(edadHijo, agedadHijo, 10);
							cout<<agedadHijo<<endl;
							
							hijosArch2<<ingid<<":"<<NombreHijo<<":"<<FechaNaciHijo<<":"<<agedadHijo<<endl;		//Agrega el hijo al archivo Hijos.txt						
							Persona.insertarHijo(ingid, NombreHijo, FechaNaciHijo, agedadHijo);		//Inserta el hijo al feligres
							
						}
						hijosArch2.close();
						break;
					case 'N':
						ingnumhijos[0]='0';						
						inghijos[0]='N';
						inghijos[1] = ' ';
						inghijos[2] = ' ';
						break;
					default:
						cout<<"Dato incorrecto,ingresa de nuevo"<<endl;
						break;
				}
			}while(cond == false);
			
			do{					//Ciclo para que seleccione una iglesia valida
				cout<<"Ingrese el numero de la iglesia a la que pertenece"<<endl;
				Iglesia.IglesiaNodo();
				cin>>ingIglesia;
				if(ingIglesia>j){
					cout<<"Dato incorrecto,ingresalo de nuevo"<<endl;
				}
			
			}while(ingIglesia>j);
			strcpy(agIglesia,Iglesia.retornarIglesia(ingIglesia).c_str());	 
			
			//Metodo para insertar la persona
			Persona.insertarPersona(ingid, ingnombre, ingapellido, settipoid, ingdocumento, aggenero, ingfijo, ingcelular, ingemail, ingfechaNac, ingedad, 
				ingciudadNac, ingpaisNac, ingciudadRes, ingdireccion, ingbarrio, ingactividad, inghijos, ingnumhijos, agIglesia);
					
			if(aggenero[0]=='F'){			//Condicional para saber segun cual genero agregarlo a una lista de mujeres o a una de hombres
				Fem.insertarLista(agIglesia,ingid);
			}else{
				Mas.insertarLista(agIglesia,ingid);
			}
			// Agrega los datos de la persona al archivo Personas.txt
			personas<<ingid<<":"<<ingnombre<<":"<<ingapellido<<":"<<settipoid<<":"<<ingdocumento<<":"<<aggenero<<":"<<ingfijo<<":"<<ingcelular<<":"<<ingemail<<":"<<ingfechaNac<<":"<<ingedad<<":"
				<<ingciudadNac<<":"<<ingpaisNac<<":"<<ingciudadRes<<":"<<ingdireccion<<":"<<ingbarrio<<":"<<ingactividad<<":"<<inghijos<<":"<<ingnumhijos<<":"<<agIglesia<<":"<<endl;		
			
			personas.close();		//Cierra el fichero
			break;
		}
		case 2:{	//EL CASO 2 ES PARA INGRESAR UNA NUEVA IGLESIA
			//	--------------------------------------------------------------AGREGAR IGLESIA -------------------------------------------------------	
			
		//	Iglesia<string> Iglesia;
			
			char nombreIglesia[20];			//Parametros de la iglesia
		    char direccionIglesia[30];
		    char barrioIglesia[15];
		    char agenteIglesia[20];
		    int intbarrio;			//Variable para ayudar a seleccionar la barrio donde esta ubicada
		    
			ofstream iglesias2;		//Crea un fichero iglesias2
		    iglesias2.open("Iglesias.txt",ios::app);	//Abre el archivo Iglesias.txt
		    	//	--------------------------------------------------------------Pedir los datos para agregar -------------------------------------------------------
			cout<<"Ingrese nombre de la iglesia"<<endl;
			cin.getline(nombreIglesia,20);
			
			cout<<"Ingrese direccion de la iglesia"<<endl;
			cin.getline(direccionIglesia,30);
			
			do{													//Ciclo para que seleccione una barrio de la iglesia valida
				cout<<"Ingrese barrio de ubicacion"<<endl;
				Localidad.Localidades();
				cin>>intbarrio;
				if(intbarrio>b){
					cout<<"Dato incorrecto,ingresalo de nuevo"<<endl;
				}
			}while(intbarrio>b);
			strcpy(barrioIglesia,Localidad.retornarBarrio(intbarrio).c_str());	
			cin.ignore();
			
			cout<<"Ingrese el pastor de la iglesia"<<endl;
			cin.getline(pastorIglesia,20);
			
			Iglesia.insertarIglesia(nombreIglesia, direccionIglesia, barrioIglesia, pastorIglesia); 	//Inserta la iglesia con los parametros pedidos
			iglesias2<<nombreIglesia<<":"<<direccionIglesia<<":"<<barrioIglesia<<":"<<pastorIglesia<<":"<<endl;	//Agrega estos parametros al archivo Iglesias.txt
			
			iglesias2.close();
		
		break;
		}
		case 3:{		//Consultar datos
			//	-------------------------------------------------------------- CONSULTAR DATOS -------------------------------------------------------
			int opcion;
			do{				//Ciclo para que seleccione la consulta que desee realizar
				cout<<"Ingrese el numero de la consulta que desee realizar.\n"
		  			"1. Numero total de personas que asisten a una iglesia.\n"
		  			"2. Listado de personas que tienen un numero de hijos dado.\n"
		  			"3. Listado de personas que viven en una ciudad dada.\n"
		  			"4. Numero de iglesias  superior a un numero dado de feligreses.\n"
		  			"5. Numero de mujeres y numero de hombes.\n"
		  			"6. Listado de feligreses segun la edad y la actividad laboral.\n"
		  			"7. Salir."<<endl;
				cin>>opcion;
				switch(opcion){
					case 1:
						int ingIglesia;			//Variable para ayudar a seleccionar la iglesia
		    			char agIglesia[15];
						do{					//Ciclo para que seleccione una iglesia valida
							cout<<"Ingrese el numero de la iglesia a la que pertenece"<<endl;
							Iglesia.IglesiaNodo();
							cin>>ingIglesia;
							if(ingIglesia>j){
							cout<<"Dato incorrecto,ingresalo de nuevo"<<endl;
							}
						}while(ingIglesia>j);
						strcpy(agIglesia,Iglesia.retornarIglesia(ingIglesia).c_str());
						Persona.buscarIglesia(agIglesia);
						break;	
					case 2:
						int rango;
						cout<<"Ingrese el rango en el que desea realizar la consulta.\n"
		  					"1. Sin hijos.\n"
		  					"2. de 1 a 2 hijos.\n"
		  					"3. de 3 a 4 hijos.\n"
		  					"4. mas de 4 hijos."<<endl;
						cin>>rango;
						if(rango==1){
							multilista.mostrar_Nhijos(1);
						} else if(rango==2){
							multilista.mostrar_Nhijos(2);
						} else if(rango==3){
							multilista.mostrar_Nhijos(2);
						} else{
							multilista.mostrar_Nhijos(2);
						}
						
						break;
					case 3:	
						break;
					case 4:	
					int asist=0;
					cout<<"Ingrese la cantidad de asistentes a superar"
					cin>>asist;
					cout<<"IGLESIA QUE SUPERA LA CANTIDAD DE ASITENTES INGRESADA"
					
						break;
					case 5:	
						cout<<"CLASIFICACION SEGUN CIUDAD";
						cout<<"Numero de mujeres";		
						multilista.mostrar_sexo(1);
						cout<<"Numero de hombres";
						multilista.mostrar_sexo(2);						
						break;
					case 6:
						break;
					default:
						break;				
				}
			}while(opcion!=7);
			break;
		}	
		
		case 4:{		//OPCION PARA SELECCIONAR UNA PERSONA Y EDITAR
			//-------------------------------------------------------------- EDITAR DATOS -------------------------------------------------------
			int intid,sel;				
			int aux = atoi(id);		//Aux para saber cual es el ultimo id
		    
			if(aux>i){
		    	aux++;
			}   
			do{									//Ciclo para que seleccione una persona correcta
				cout<<"Que persona deseas editar"<<endl;
				Persona.rePe();
				cin>>intid;
				if(intid>aux){
					cout<<"Dato incorrecto,ingresalo de nuevo"<<endl;
				}
			
			}while(intid>aux);
			
			string  auxNom="",auxApe="",auxFij="",auxCel="",auxCor="",auxDir="",auxBar="",auxhij="",auxnumHij="";	//auxiliares para reemplezar alguna info
			
			auxNom=Persona.retornarNo(intid);				//Metodos que retornan todos los campos que vamos a editar
			auxApe=Persona.retornarAp(intid);
			auxFij=Persona.retornarFi(intid);
			auxCel=Persona.retornarCe(intid);
			auxCor=Persona.retornarEm(intid);
			auxDir=Persona.retornarDi(intid);
			auxBar=Persona.retornarBa(intid);
			auxhij=Persona.retornarHi(intid);
			auxnumHij=Persona.retornarNumHij(intid);
			
			
			do{					//Ciclo para que seleccione uno o variso campo para editar y luego salir 
				cout<<"Seleciona el dato que deseas editar:\n1.Nombre\n2.Apellido"
				"\n3.Telefono Fijo\n4.Telefono Celular\n5.Correo"
				"\n6.Direccion\n7.Barrio\n8.actualizar info hijos\n9.Salir\n";
				cin>>sel;
				switch(sel){
					case 1:
						cout<<"Seleccionaste nombre\nEl actual es: "<<auxNom<<endl;
						cout<<"Ingresa el nuevo dato: "<<endl;
						cin>>auxNom;
						cout<<"El nuevo nombre es: "<<auxNom<<endl;
						break;
						
					case 2:
						cout<<"Seleccionaste apellido\nEl actual es: "<<auxApe<<endl;
						cout<<"Ingresa el nuevo dato: "<<endl;
						cin>>auxApe;
						cout<<"El nuevo apellido  es: "<<auxApe<<endl;
						break;
					case 3:
						cout<<"Seleccionaste telefono fijo\nEl actual es: "<<auxFij<<endl;
						cout<<"Ingresa el nuevo dato: "<<endl;
						cin>>auxFij;
						cout<<"El nuevo fijo es: "<<auxFij<<endl;
						break;
						
					case 4:
						cout<<"Seleccionaste telefono celular\nEl actual es: "<<auxCel<<endl;
						cout<<"Ingresa el nuevo dato: "<<endl;
						cin>>auxCel;
						cout<<"El nuevo celular es: "<<auxCel<<endl;
						break;
						
					case 5:
						cout<<"Seleccionaste telefono Email\nEl actual es: "<<auxCor<<endl;
						cout<<"Ingresa el nuevo dato: "<<endl;
						cin>>auxCor;
						cout<<"El nuevo Email es: "<<auxCor<<endl;
						break;
						
					case 6:
						cout<<"Seleccionaste Direccion\nEl actual es: "<<auxDir<<endl;
						cout<<"Ingresa el nuevo dato: "<<endl;
						cin>>auxDir;
						cout<<"El nuevo dato es: "<<auxDir<<endl;
						break;
						
					case 7:
						cout<<"Seleccionaste Barrio\nEl actual es: "<<auxBar<<endl;
						cout<<"Ingresa el nuevo dato: "<<endl;
						cin>>auxBar;
						cout<<"El nuevo barrio es: "<<auxDir<<endl;
						break;
					
					case 8:
						if(auxhij=="N"){						//Si no tenia hijos pregunta si tuvo mas hijos si es un S ahora si tengra hijos
							cout<<"Ya tienes hijos? S o N"<<endl;
							cout<<"\nEl actual es: "<<auxhij<<endl;
							cout<<"Ingresa el nuevo dato: "<<endl;
							cin>>auxhij;
							
						}else{
							cout<<"Cuantos hijos mas tuviste?"<<endl;
						}
						cout<<"\nEl actual es: "<<auxnumHij<<endl;
						cout<<"Ingresa el nuevo dato: "<<endl;
						cin>>auxnumHij;
						cout<<"El nuevo Hijo es: "<<auxnumHij<<endl;
						break;
					
					default:
						break;
				}			
			}while(sel!=9);
			char auxid[2];
			itoa(intid, auxid, 10);
			string idaux(auxid);
			string dato;
			//Este string contiene todos los datos de la persona hasta los editados
			dato =idaux+":"+auxNom+":"+auxApe+":"+Persona.retornarTi(intid)+":"+Persona.retornarNumId(intid)+":"+Persona.retornarGe(intid)+":"+auxFij+":"+auxCel+":"+auxCor+":"+Persona.retornarFn(intid)+
				":"+Persona.retornarEd(intid)+":"+Persona.retornarCn(intid)+":"+Persona.retornarPn(intid)+":"+Persona.retornarCr(intid)+":"+auxDir+":"+auxBar+":"+Persona.retornarAc(intid)+
				":"+auxhij+":"+auxnumHij+":"+Persona.retornarIglesia(intid)+":";
				
			
			//convertir intid a entero
			fclose(archivo);		//Cierra el fichero
			editar(dato, intid);	//Llamado a la funcion editar
			break;
		
		}	
		case 5:{
			//	-------------------------------------------------------------- ELIMINAR DATOS -------------------------------------------------------
			int ideliminar;		
			cout<<"Ingrese el id del feligres que desea eliminar"<<endl;	//Selecciona la persona que desea eliminar
			Persona.rePe();
			cin>>ideliminar;
			fclose(archivo);	//Cierra el archivo
			eliminar(ideliminar);	//llama a la funcion eliminar
			break;
		}
		case 6:{//EL CASO 6 ES PARA INGRESAR UNA NUEVA LOCALIDAD
			//	--------------------------------------------------------------AGREGAR LOCALIDAD -------------------------------------------------------	
						
			char nombreLocalidad[15];			//Parametros de la localidad
		    char barrioLocalidad[15];

			ofstream localidades;		//Crea un fichero localidades
		    localidades.open("Localidades.txt",ios::app);	//Abre el archivo Localidades.txt
		    	//	--------------------------------------------------------------Pedir los datos para agregar -------------------------------------------------------
			cout<<"Ingrese nombre de la localidad"<<endl;
			cin.getline(nombreLocalidad,15);
			
			cout<<"Ingrese barrio de la localidad"<<endl;
			cin.getline(barrioLocalidad,15);
			
			
			Localidad.insertarLocalidad(nombreLocalidad,barrioLocalidad); 	//Inserta la localidad con los parametros pedidos
			localidades<<barrioLocalidad<<":"<<nombreLocalidad<<":"<<endl;	//Agrega estos parametros al archivo Iglesias.txt	
			localidades.close();	
			break;
		}
		case 7:{
			fclose(hijosArch);		//Cierra todos los ficheros
			fclose(archivo);
			fclose(Iglesias);
			exit(0);
			break;
		}		
	}
	
	
}

//Main donde se llama a la funcion principal 
int main(int argc, char** argv) {

	int opcion, dato;	
	do{				//Ciclo para que seleccione las operaciones que desee realizar
		cout<<"Ingrese el numero de la operacion que desee realizar.\n"
		  "1. Agregar Feligres.\n"
		  "2. Agregar Iglesia.\n"
		  "3. Consultar Datos.\n"
		  "4. Editar Datos.\n"
		  "5. Eliminar Datos.\n"
		  "6. Agregar Localidad.\n"
		  "7. Salir."<<endl;
		cin>>opcion;
		switch(opcion){
			case 1:
				funcionPrincipal(1);	//Llama a la funcion y el caso 1 que seria agregar feligres

				break;
			case 2:
				funcionPrincipal(2);		//Llama a la funcion y el caso 2 que seria agregar iglesia

				break;
			case 3:	
				funcionPrincipal(3);	//Llama a la funcion y el caso 3 que seria consultar datos
				break;
			case 4:	
				funcionPrincipal(4);	//Llama a la funcion y el caso 4 que seria agregar editar feligres
				break;
			case 5:
				funcionPrincipal(5);	//Llama a la funcion y el caso 5 que seria eliminar feligres
				break;
			case 6:
				funcionPrincipal(6);	//Llama a la funcion y el caso 6 que seria agregar localidad
				break;
			case 7:
				funcionPrincipal(7);
				break;			
		}
	}while(opcion!=0);

}

void eliminar(int del_line_num){
	FILE *archOrig, *archAux;	//Crea dos archivos uno original y otro aux
	int line_num = 0;
	char str[200];
	string contenido;
	string reemplazar;
	
	archOrig = fopen("Personas.txt","r");		//el original abre el archivo antes de modificar
	cout<<"antes de la modificacion"<<endl;
	print(archOrig);
	rewind(archOrig);
		
	archAux = fopen("replica.txt", "w");		//El auxiliar abre el archivo replica.txt
				
	while(fgets(str, 199, archOrig) != NULL){		//Mientras pueda leer otra linea
		line_num++;
		
		if(line_num != del_line_num){	//Si el numero de linea es igual al id que se selecciono para despedir no se escribe en el archvi replica
			fputs(str, archAux);
		}
	}
	
	cout<<"SI se realizo el proceso"<<endl;
	fclose(archOrig);		//Cierra ambos files
	fclose(archAux);
	remove("Personas.txt");		//Elimina el archivo Personas.txt
	rename("replica.txt","Personas.txt");	//Cambia el nombre de replica.txt a Personas.txt
	cout<<"Cambio de nombre"<<endl;
}

void editar(string dato, int pos){
	
		char linea[200];
		strcpy(linea,dato.c_str());
	
		FILE *archOrig, *archAux;		//Crea dos archivos uno original y otro aux
		int del_line_num;
		int line_num = 0;
		char str[200];
		string contenido;
		string reemplazar;
		
		archOrig = fopen("Personas.txt","r");		//el original abre el archivo antes de modificar
		//cout<<"antes de la modificacion"<<endl;
		//print(archOrig);
		//rewind(archOrig);
			
		archAux = fopen("replica.txt", "w");			//El auxiliar abre el archivo replica.txt
					
		while(fgets(str, 199, archOrig) != NULL){	//Mientras pueda leer otra linea
			line_num++;
			
			if(line_num != pos){				//Si el id que selecciono para editar no es igual a la linea lo escribe normal
				fputs(str, archAux);
			}else{
				fputs(linea, archAux);			//Si no escribe el nuevo feligres con los datos modificados
			}
		}
		
		fclose(archOrig);		//Cierra los files
		fclose(archAux);
		remove("Personas.txt");			//Elimina Personas.txt
		rename("replica.txt","Personas.txt");		//Cambia el nombre de replica.txt a Personas.txt
		
}
