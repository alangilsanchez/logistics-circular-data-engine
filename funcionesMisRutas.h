void RegistroMiRuta(){
	MisRutas *nuevo = new MisRutas;
	MisRutas *aux=NULL;
	int sigue = 1;
	int i=0;
	
	prim=NULL;
	ult=NULL;
	
	mostrarRutasActivas();
	
	nuevo->idRuta = validaEntero("Ruta a tomar: ");
	cout<<"Dia: ";
	getline(cin, nuevo->horario.dia);
	cout<<"Hora: ";
	getline(cin, nuevo->horario.hora);	
	nuevo->estado = "Activo";
	
	nuevo->sig = NULL;
		
	if(prim==NULL){
		prim = nuevo;
		ult = nuevo;
	}else{
		ult->sig=nuevo;
		ult=nuevo;
	}
	
}

void eliminaMiRuta(){
	system("cls");
	struct MisRutas *aux = prim;
	int opc=0;
	int sigue=0;
	int idRuta=0;
	string activo="Activo";
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
	printf("\n\n\n\t\t\tELIMINA MI RUTA\n");
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	cout<<endl<<endl<<"Mostrando la lista de mis rutas"<<endl;
	//cout<<"Ubicación"<<setw(10);
	cout<<"id Ruta"<<setw(15);
	cout<<"Dia"<<setw(20);
	cout<<"Hora"<<setw(15);
	cout<<"Estado"<<endl;
	//cout<<"Lista(Primer nodo)"<<setw(10);
	//cout<<"Siguiente"<<endl;
	while(aux!=NULL){
		if(aux->estado.compare(activo) == 0){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);	
			//cout<<aux<<setw(10);
			cout<<aux->idRuta<<setw(15);
			cout<<aux->horario.dia<<setw(20);
			cout<<aux->horario.hora<<setw(15);;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
			cout<<aux->estado<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
		}
		
		aux = aux->sig;
	}
	
	do{	
		idRuta = validaEntero("Id de ruta a eliminar: ");
	
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
		cout<<endl<<"Ruta a eliminar"<<endl;
		//cout<<"Ubicación"<<setw(10);
		cout<<"id Ruta"<<setw(15);
		cout<<"Dia"<<setw(20);
		cout<<"Hora"<<setw(15);
		cout<<"Estado"<<endl;
		aux=prim;
		while(aux!=NULL){
			if(idRuta == aux->idRuta){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
				cout<<aux->idRuta<<setw(15);
				cout<<aux->horario.dia<<setw(20);
				cout<<aux->horario.hora<<setw(25);;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
				cout<<aux->estado<<endl;
				
				
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
				opc = validaEntero("1 para CONFIRMAR...Otro para CANCELAR: ");
				switch(opc){
					case OPC1:
						aux->estado = "Inactivo";
						cout<<endl<<"RUTA ELIMINADO!! ";
						break;
					default:
						cout<<endl<<"ELIMINACIÓN DE RUTA CANCELADA!!";
						break;	
				}
			}
			aux = aux->sig;			
		}
		sigue = validaEntero("1 para eliminar otra RUTA... otro para REGRESAR: ");
	}while(sigue==1);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
}

void modificaMisRutas(){
	system("cls");
	struct MisRutas *aux = prim;
	int idRuta=0;
	int opc=0;
	int sigue=0;
	
	string activo="Activo";
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
	printf("\n\n\n\t\t\tMODIFICA MI RUTA\n");
		
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	cout<<endl<<endl<<"Mostrando la lista de mis rutas"<<endl;
	cout<<"id Ruta"<<setw(15);
	cout<<"Dia"<<setw(20);
	cout<<"Hora"<<setw(15);
	cout<<"Estado"<<endl;
	//cout<<"Lista(Primer nodo)"<<setw(10);
	//cout<<"Siguiente"<<endl;
	while(aux!=NULL){
		if(aux->estado.compare(activo) == 0){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);	
			//cout<<aux<<setw(10);
			cout<<aux->idRuta<<setw(15);
			cout<<aux->horario.dia<<setw(20);
			cout<<aux->horario.hora<<setw(15);;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
			cout<<aux->estado<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
		}
		
		aux = aux->sig;
	}
	/*
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	cout<<endl<<"Primer LISTA: "<<primLista;
	cout<<endl<<"Ultima LISTA: "<<ultLista;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);*/
	
	idRuta = validaEntero("Id de ruta a modificar: ");
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	cout<<endl<<"Ruta a eliminar"<<endl;
	//cout<<"Ubicación"<<setw(10);
	cout<<"id Ruta"<<setw(15);
	cout<<"Dia"<<setw(20);
	cout<<"Hora"<<setw(15);
	cout<<"Estado"<<endl;
	aux=prim;
	while(aux!=NULL){
		if(idRuta == aux->idRuta){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<aux->idRuta<<setw(15);
			cout<<aux->horario.dia<<setw(20);
			cout<<aux->horario.hora<<setw(25);;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
			cout<<aux->estado<<endl;
			
			do{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
				opc = validaEntero("1 para modificar DÍA...2 para modificar HORA: ");
				switch(opc){
					case OPC1:
						cout<<"DÍA: ";
						getline(cin, aux->horario.dia);
						cout<<endl<<"DÍA ACTUALIZADO!!: ";
						break;
					case OPC2:
						cout<<"HORA: ";
						getline(cin, aux->horario.hora);
						cout<<endl<<"HORA ACTUALIZADA!!: ";
						break;
					default:
						cout<<endl<<"OPCIÓN NO VALIDA!!: ";
						break;	
				}
				
				sigue = validaEntero("1 para volver a modificar... OTRO para Salir: ");
			}while(sigue==1);
		}
		aux = aux->sig;
		
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
}

void ConsultaMisRutas(){
	system("cls");
	struct MisRutas *aux = prim;
	string activo="Activo";
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	cout<<endl<<endl<<"Mostrando la lista de rutas agregadas"<<endl;
	cout<<"id Ruta"<<setw(15);
	cout<<"Dia"<<setw(20);
	cout<<"Hora"<<setw(15);
	cout<<"Estado"<<endl;
	//cout<<"Lista(Primer nodo)"<<setw(10);
	//cout<<"Siguiente"<<endl;
	while(aux!=NULL){
		if(aux->estado.compare(activo) == 0){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);	
			//cout<<aux<<setw(10);
			cout<<aux->idRuta<<setw(15);
			cout<<aux->horario.dia<<setw(20);
			cout<<aux->horario.hora<<setw(15);;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
			cout<<aux->estado<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
		}
		
		aux = aux->sig;
	}
}

void ConsultaMisRutasTomadas(){
	system("cls");
	struct MisRutas *aux = prim;
	string tomado="SI";
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	cout<<endl<<endl<<"Mostrando la lista de rutas tomadas"<<endl;
	cout<<"id Ruta"<<setw(15);
	cout<<"Dia"<<setw(20);
	cout<<"Hora"<<setw(15);
	cout<<"Tomo el Autobus"<<endl;
	//cout<<"Lista(Primer nodo)"<<setw(10);
	//cout<<"Siguiente"<<endl;
	while(aux!=NULL){
		if(aux->tomar.tomoBus.compare(tomado) == 0){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);	
			//cout<<aux<<setw(10);
			cout<<aux->idRuta<<setw(15);
			cout<<aux->horario.dia<<setw(20);
			cout<<aux->horario.hora<<setw(15);;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
			cout<<aux->tomar.tomoBus<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
		}
		
		aux = aux->sig;
	}
}

void ConsultaMisRutasNoTomadas(){
	system("cls");
	struct MisRutas *aux = prim;
	string tomado="NO";
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	cout<<endl<<endl<<"Mostrando la lista de rutas NO tomadas"<<endl;
	cout<<"id Ruta"<<setw(15);
	cout<<"Dia"<<setw(20);
	cout<<"Hora"<<setw(15);
	cout<<"Tomo el Autobus"<<endl;
	//cout<<"Lista(Primer nodo)"<<setw(10);
	//cout<<"Siguiente"<<endl;
	while(aux!=NULL){
		if(aux->tomar.tomoBus.compare(tomado) == 0){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);	
			//cout<<aux<<setw(10);
			cout<<aux->idRuta<<setw(15);
			cout<<aux->horario.dia<<setw(20);
			cout<<aux->horario.hora<<setw(15);;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
			cout<<aux->tomar.tomoBus<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
		}
		
		aux = aux->sig;
	}
}
