void menuProyecto();
void registroUsuario();
void consultaUsuario();
void consultaRutas();
void adminUsu();
void adminRutas();
void adminRutasPasajeros();
void adminMisRutas(int op, int v);
void alerta(int op);
void menu1();
void menu2(int op,int v);
void menu(int,int,int &, int);

void menu(int x, int y, int &opc,int num){
	char tecla='\0'; // ' '
	opc = 1;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
	//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),26);
	gotoxy(x,y);
	printf("%c",16);
	do{
		if(kbhit()){
			tecla=getch();
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
			//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),17);
			gotoxy(x,y);
			printf("%c", 16);
			if(opc>1&&tecla==72){	//Flecha arriba
				y--;
				opc--;
			}
			if(opc<num &&tecla==80){	//Flecha abajo
				y++;
				opc++;
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
			//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),26);
			gotoxy(x,y);
			printf("%c",16);
		}
	}while(tecla!=13); //13--> Enter
}

void menuProyecto(){
	setlocale(LC_CTYPE, "Spanish");
	char estado[10]="Activo";
	int respuesta=0;
	int opc = 0;
	int x = 0;
	int y = 0;
	int i=0;
	int num=2;
	while(opc !=7){
		system("color 02");
		x = 25;
		y = 5;
		system("cls");
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),48);
		//gotoxy(x,y);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
		printf("\n\n\n\t\t\tSELECCIONA UNA OPCIÓN\n\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
		gotoxy(x,y);
		printf("1. Iniciar sesion\n");
		gotoxy(x,++y);
		printf("2. Salir del sistema\n");
		menu(22,5,opc,num);
		//system("color 10");
		system("cls");
		//SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),48);
		gotoxy(10,4);
		switch(opc){
			case OPC1:
				i = inicioSecion();
				if(i==1){
					menu1();
					//Menu para admin
				}else{
					if(i==2){
						menu2(1,0);
						//Menu para pasajero
					}
				}
				getch();
				break;
			case OPC2:
				escrituraListaUsuarios();
				escrituraListaRutas();
				system("color 60");
				printf("Adios!! :D");
				exit(0);	
		}
	}
	getch();
}

//------------------------------------------------------------------------------- se queda
void registroUsuario(){
	setlocale(LC_CTYPE, "Spanish");
	char perfil[15];
	int opc = 0;
	int x = 0;
	int y = 0;
	int num=3;
	
	while(opc !=3){
		system("color 02");
		x = 25;
		y = 5;
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
		printf("\n\n\n\t\t\t---------- REGISTRAR Administrado o Personal ----------\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
		gotoxy(x,y);
		printf("a) Usuario Administrador\n");
		gotoxy(x,++y);
		printf("b) Usuario Personal\n");
		gotoxy(x,++y);
		printf("c) Regresar\n");
		gotoxy(x,++y);
		menu(22,5,opc,num);
		system("cls");
		gotoxy(10,4);
		switch(opc){
			case OPC1:
				strcpy(perfil,"---------- Administrador ----------");
				printf("Usuario Administrador\n");
				agregarUsuario(perfil);
				menu1();
				getch();
				break;
			case OPC2:
				strcpy(perfil,"---------- Personal ----------");
				printf("Usuario Pasajero\n");
				agregarUsuario(perfil);
				menu1();
				getch();
				break;
			case OPC3:
				menu1();
				getch();
				break;
		}
	}
	getch();
}
//------------------------------------------------------------------------------- ------------------
//------------------------------------------------------------------------------- se queda
void consultaUsuario(){
	setlocale(LC_CTYPE, "Spanish");
	int opc = 0;
	int x = 0;
	int y = 0;
	int num=3;
	
	while(opc !=3){
		system("color 02");
		x = 25;
		y = 5;
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
		printf("\n\n\n\t\t\t---------- CONSULTA USUARIOS ----------\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
		gotoxy(x,y);
		printf("a) Usuarios Registrados\n");
		gotoxy(x,++y);
		printf("b) Usuarios Inactivos\n");
		gotoxy(x,++y);
		printf("c) Regresar\n");
		gotoxy(x,++y);
		menu(22,5,opc,num);
		system("cls");
		gotoxy(10,4);
		switch(opc){
			case OPC1:
				mostrarUsuarioActivo();
				getch();
				consultaUsuario();
				getch();
				break;
			case OPC2:
				mostrarUsuarioInactivo();
				getch();
				consultaUsuario();
				getch();
				break;
			case OPC3:
				adminUsu();
				getch();
				break;
		}
	}
}
//------------------------------------------------------------------------------- ------------------

//------------------------------------------------------------------------------- se queda
void adminUsu(){
	setlocale(LC_CTYPE, "Spanish");
	int opc = 0;
	int x = 0;
	int y = 0;
	int num=6;
	
	while(opc !=3){
		system("color 02");
		x = 25;
		y = 5;
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
		printf("\n\n\n\t\t\t---------- ADMINISTRAR PERSONAL ----------\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
		gotoxy(x,y);
		printf("a) Registrar PERSONAL\n");
		gotoxy(x,++y);
		printf("b) Consultar PERSONAL\n");
		gotoxy(x,++y);
		printf("c) Modificar PERSONAL\n");
		gotoxy(x,++y);
		printf("d) Eliminar PERSONAL\n");
		gotoxy(x,++y);
		printf("e) Mostrar Ubicaciones de memoria\n");
		gotoxy(x,++y);
		printf("f) Regresar\n");
		gotoxy(x,++y);
		menu(22,5,opc,num);
		system("cls");
		gotoxy(10,4);
		switch(opc){
			case OPC1:
				registroUsuario();
				adminUsu();
				getch();
				break;
			case OPC2:
				consultaUsuario();
				adminUsu();
				getch();
				break;
			case OPC3:
				modifica();
				adminUsu();
				getch();
				break;
			case OPC4:
				elimina();
				adminUsu();
				getch();
				break;
			case OPC5:
				mostrarUbiUsuario();
				getch();
				adminUsu();
				break;
			case OPC6:
				menu1();
				getch();
				break;
		}
	}
}
//--------------------------------------------------------------------------------------------------------

void consultaRutas(){
	setlocale(LC_CTYPE, "Spanish");
	char perfil[15];
	int opc = 0;
	int x = 0;
	int y = 0;
	int num=3;
	
	while(opc !=3){
		system("color 02");
		x = 25;
		y = 5;
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
		printf("\n\n\n\t\t\tCONSULTA RUTAS\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
		gotoxy(x,y);
		printf("a) Rutas Activas\n");
		gotoxy(x,++y);
		printf("b) Rutas Inactivas\n");
		gotoxy(x,++y);
		printf("c) Regresar\n");
		gotoxy(x,++y);
		menu(22,5,opc,num);
		system("cls");
		gotoxy(10,4);
		switch(opc){
			case OPC1:
				mostrarRutasActivas();
				getch();
				consultaRutas();
				getch();
				break;
			case OPC2:
				mostrarRutasInactivas();
				getch();
				consultaRutas();
				getch();
				break;
			case OPC3:
				adminRutas();
				getch();
				break;
		}
	}
}

void adminRutas(){
	setlocale(LC_CTYPE, "Spanish");
	int opc = 0;
	int x = 0;
	int y = 0;
	int num=6;
	
	while(opc !=3){
		system("color 02");
		x = 25;
		y = 5;
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
		printf("\n\n\n\t\t\tADMINISTRAR RUTAS\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
		gotoxy(x,y);
		printf("a) Registrar Ruta\n");
		gotoxy(x,++y);
		printf("b) Consultar Rutas\n");
		gotoxy(x,++y);
		printf("c) Modificar Rutas\n");
		gotoxy(x,++y);
		printf("d) Eliminar Rutas\n");
		gotoxy(x,++y);
		printf("e) Mostrar Ubicaciones de memoria\n");
		gotoxy(x,++y);
		printf("f) Regresar\n");
		gotoxy(x,++y);
		menu(22,5,opc,num);
		system("cls");
		gotoxy(10,4);
		switch(opc){
			case OPC1:
				agregarRuta();
				adminRutas();
				getch();
				break;
			case OPC2:
				consultaRutas();
				adminRutas();
				getch();
				break;
			case OPC3:
				modificaRuta();
				adminRutas();
				getch();
				break;
			case OPC4:
				eliminaRuta();
				adminRutas();
				getch();
				break;
			case OPC5:
				mostrarUbiRutas();
				getch();
				adminRutas();
				break;
			case OPC6:
				menu1();
				getch();
				break;
		}
	}
}
void adminRutasPasajeros(){
	setlocale(LC_CTYPE, "Spanish");
	int opc = 0;
	int x = 0;
	int y = 0;
	int num=7;
	
	while(opc !=3){
		system("color 02");
		x = 25;
		y = 5;
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
		printf("\n\n\n\t\t\tADMINISTRAR LAS RUTAS POR PASAJERO\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
		gotoxy(x,y);
		printf("a) Consultar por IdPasajero\n");
		gotoxy(x,++y);
		printf("b) Consultar por rutas mas solicitadas\n");
		gotoxy(x,++y);
		printf("c) Consultar por rutas menos solicitadas\n");
		gotoxy(x,++y);
		printf("d) Consultar por pasajeros que SI tomaron el autobus\n");
		gotoxy(x,++y);
		printf("e) Consultar por pasajeros que NO tomaron el autobus\n");
		gotoxy(x,++y);
		printf("f) Consultar por pasajeros que tomaron y se bajaron del autobus\n");
		gotoxy(x,++y);
		printf("g) Regresar\n");
		gotoxy(x,++y);
		menu(22,5,opc,num);
		system("cls");
		gotoxy(10,4);
		switch(opc){
			case OPC1:
				menu1();
				getch();
				break;
			case OPC2:
				menu1();
				getch();
				break;
			case OPC3:
				menu1();
				getch();
				break;
			case OPC4:
				menu1();
				getch();
				break;
			case OPC5:
				menu1();
				getch();
				break;
			case OPC6:
				menu1();
				getch();
				break;
			case OPC7:
				menu1();
				getch();
				break;
		}
	}
}

//------------------------------------------------------------------------------- se queda
void menu1(){
	setlocale(LC_CTYPE, "Spanish");
	int opc = 0;
	int x = 0;
	int y = 0;
	int num=4;
	
	while(opc !=3){
		system("color 02");
		x = 25;
		y = 5;
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
		printf("\n\n\n\t\t\t---------- ADMINISTRADOR ----------\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
		gotoxy(x,y);
		printf("a) Administrar Personal\n");
		gotoxy(x,++y);
		printf("b) Administrar Menu\n");
		gotoxy(x,++y);
		printf("c) Generar reportes \n");
		gotoxy(x,++y);
		printf("d) Cerrar sesión\n");
		gotoxy(x,++y);
		menu(22,5,opc,num);
		system("cls");
		gotoxy(10,4);
		switch(opc){
			case OPC1:
				adminUsu();
				menu1();
				getch();
				break;
			case OPC2:
				adminRutas();
				menu1();
				getch();
				break;
			case OPC3:
				adminRutasPasajeros();
				getch();
				break;
			case OPC4:
				menuProyecto();
				getch();
				break;
		}
	}
}
//------------------------------------------------------------------------------- -------------------------------

void adminMisRutas(int op, int v){
	setlocale(LC_CTYPE, "Spanish");
	int opc = 0;
	int x = 0;
	int y = 0;
	int num=5;
	
	while(opc !=3){
		system("color 02");
		x = 25;
		y = 5;
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
		printf("\n\n\n\t\t\tADMINISTRAR MIS RUTAS\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
		gotoxy(x,y);
		printf("a) Registrar Ruta a tomar\n");
		gotoxy(x,++y);
		printf("b) Eliminar Ruta a tomar\n");
		gotoxy(x,++y);
		printf("c) Modificar Ruta a tomar\n");
		gotoxy(x,++y);
		printf("d) Consultar horarios\n");
		gotoxy(x,++y);
		printf("e) Regresar\n");
		gotoxy(x,++y);
		menu(22,5,opc,num);
		system("cls");
		gotoxy(10,4);
		switch(opc){
			case OPC1:
				RegistroMiRuta();
				menu2(op,v);
				getch();
				break;
			case OPC2:
				eliminaMiRuta();
				menu2(op,v);
				getch();
				break;
			case OPC3:
				modificaMisRutas();
				menu2(op,v);
				getch();
				break;
			case OPC4:
				ConsultaMisRutas();
				menu2(op,v);
				getch();
				break;
			case OPC5:
				menu2(op,v);
				getch();
				break;
		}
	}	
}

void alerta(int op){
	setlocale(LC_CTYPE, "Spanish");
	int x2= 80;
	int y2 = 6;
	
	gotoxy(x2,y2);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
	if(op==1){
		printf("EL AUTOBUS ACABA DE LLEGAR");
	}else if(op==2){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
		printf("ABORDO DEL AUTOBUS");
	}else if(op==3){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
		printf("BAJANDO DEL AUTOBUS");
	}
	else if(op==4){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
		printf("AUTOBUS EN SU TRAYECTO");
	}
	
	x2=78;
	y2=5;
	for(int i=0; i<27; i++){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		gotoxy(x2++,y2);
		printf("%c", 177);
	}
	y2=7;
	x2=78;
	for(int i=0; i<27; i++){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		gotoxy(x2++,y2);
		printf("%c", 177);
	}
	x2=78;
	y2=6;
	gotoxy(x2++,y2);
	printf("%c", 177);
	x2=104;
	y2=6;
	gotoxy(x2++,y2);
	printf("%c", 177);
}
void menu2(int op,int v){
	setlocale(LC_CTYPE, "Spanish");
	int opc = 0;
	int x = 0;
	int y = 0;
	int num=6;

	while(opc !=3){
		system("color 02");
		x = 25;
		y = 5;
		system("cls");
		alerta(op);
		gotoxy(25,0);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
		printf("\n\n\n\t\t\tBIENVENIDO PASAJERO\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
		gotoxy(x,y);
		printf("a) Administrar mis Rutas\n");
		gotoxy(x,++y);
		printf("b) Tomar autobus\n");
		gotoxy(x,++y);
		printf("c) Bajar del autobus\n");
		gotoxy(x,++y);
		printf("d) Rutas tomadas\n");
		gotoxy(x,++y);
		printf("e) Rutas no tomadas\n");
		gotoxy(x,++y);
		printf("f) Cerrar sesión\n");
		gotoxy(x,++y);
		menu(22,5,opc,num);
		system("cls");
		gotoxy(10,4);
		switch(opc){
			case OPC1:
				adminMisRutas(op,v);
				menu2(op,v);
				getch();
				break;
			case OPC2:
				if(v<1){
					op=2;
					v++;
					menu2(op,v);
					getch();
				}else{
					menu2(op,v);
				}
				break;
			case OPC3:
				if(v==1){
					op=3;
					v++;
					menu2(op,v);
					getch();	
				}else if(v>1){
					op=4;
					menu2(op,v);
				}else{
					menu2(op,v);
				}
				break;
			case OPC4:
				ConsultaMisRutasTomadas();
				getch();
				menu2(op,v);
				getch();
				break;
			case OPC5:
				ConsultaMisRutasNoTomadas();
				getch();
				menu2(op,v);
				getch();
				break;
			case OPC6:
				menuProyecto();
				getch();
				break;
		}
	}
}
