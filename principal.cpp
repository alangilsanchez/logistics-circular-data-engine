#include "libreria.h"
/*	INTEGRANTES
	Nombre: Sanchez Zavala Alan Gilberto_177263
	Nombre: Alejandro Alberto Carreon Barbosa_178250
	Materia: Programación II
	Avance de proyecto
*/
int main(){
	system("mode con: cols=140 lines=100");

	primLista=NULL;
	ultLista=NULL;
	lecturaListaUsuarios();	//CARGA A LA ESTRUCTURA LOS REGISTROS DE USUARIOS
	lecturaListaRutas(); //CARGA A LA ESTRUCTURA LOS REGISTROS DE LAS RUTAS
	
	portada();
	datos();	
	menuProyecto();
	//escrituraLista();
	//escrituraListaRutas();
	//La funcion escrituraLista y escrituraListaRutas se invocan dentro del menu del proyecto, 
	//en la opcion "Salir del sistema" que es cuando termina
	return 0;
}
