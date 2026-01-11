#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <iostream> //cout, cin, fixed, endl kbhit--> Determina si se presiona una tecla
#include <fstream> //ofstream, ifstream
#include <sstream> //stringstream
#include <iomanip> //setw
#include <stdlib.h> //malloc
#include <string.h> // String
#include <time.h>
#include <ctype.h> //isdigit -> retorna cero si no es digito
#include <locale.h> //setlocale
#include <windows.h> // SetConsole

using namespace std;

void gotoxy(int x, int y){
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dWPos;
	dWPos.X =x;
	dWPos.Y =y;
	SetConsoleCursorPosition(hcon,dWPos);
}
				 
enum MENU { OPC1=1, OPC2, OPC3, OPC4, OPC5, OPC6, OPC7};

//ESTRUCTURA PARA EL HORARIO DE LAS RUTAS
struct Horario{
	string dia;
	string hora;
};
//ESTRUCTURA PARA LAS RUTAS
struct Rutas{
	int idRuta;
	string destino;
	string paradas;
	Horario horario;
	string estado;
	
	struct Rutas *sig;//Siguiente
}*primero, *ultimo;

//ESTRUCTURA PARA LA ALERTA TOMAR AUTOBUS
struct Tomar{
	string pasajero;
	int idRuta;
	string tomoBus;
};
//ESTRUCTURA PARA LA ALERTA BAJAR DEL AUTOBUS
struct Bajar{
	string pasajero;
	int idRuta;
	string tomoBus;
};

//ESTRUCUTRA PARA LAS RUTAS DE LOS USUARIOS
struct MisRutas{
	int idRuta;
	Horario horario;
	Tomar tomar;
	Bajar bajar;
	string estado;
	struct MisRutas *sig;//Siguiente
}*prim, *ult;


//ESTRUCTURA PARA LOS USUARIOS
struct Usuario{
	int id;
	string nombre;
	string apellidos;
	string correo;
	string cargo;
	string contrasena;
	string estado;
	string perfil;
	MisRutas *lista;
	Usuario *sig;
}*primLista, *ultLista;

#include "decorar.h"
#include "validaciones.h"
#include "funcionesRutas.h"
#include "funcionesMisRutas.h"
#include "funciones.h"
#include "archivoRutas.h"
#include "archivo.h"
#include "archivoListas.h"
#include "menu.h"





