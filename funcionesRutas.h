Rutas *registro(){
	Rutas *nuevo = new Rutas;
	Rutas *aux=NULL;
	
	if(primero==NULL){
		nuevo->idRuta = 1;
		printf("Id de Ruta: %d\n", nuevo->idRuta);
	}
	else{
		aux=ultimo;
		nuevo->idRuta= (aux->idRuta+1);
		printf("Id de Ruta: %d\n", nuevo->idRuta);
	}
	cout<<"Destino: ";
	getline(cin, nuevo->destino);
	cout<<"Paradas: ";
	getline(cin, nuevo->paradas);
	cout<<"Día: ";
	getline(cin, nuevo->horario.dia);
	cout<<"Horario: ";
	getline(cin, nuevo->horario.hora);
	nuevo->estado = "Activo";
	
	nuevo->sig=NULL;
	return nuevo;
}

void agregarRuta(){
	Rutas *nuevo = registro(); 
	if(primero==NULL){
		primero = nuevo;
		ultimo = nuevo;
	}else{
		ultimo->sig=nuevo;
		ultimo=nuevo;
	}	
}

void mostrarRutasActivas(){
	struct Rutas *aux = primero;
	string activo="Activo";
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	cout<<endl<<endl<<"Mostrando la lista completa"<<endl;
	//cout<<"Ubicación"<<setw(10);
	cout<<"Id RUTA"<<setw(20);
	cout<<"Destino"<<setw(30);
	cout<<"Paradas"<<setw(20);
	cout<<"Día"<<setw(15);
	cout<<"Horario"<<setw(10);
	cout<<"Estado"<<endl;
	//cout<<"Siguiente"<<endl;
	while(aux!=NULL){
		if(aux->estado.compare(activo) == 0){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			//cout<<aux<<setw(10);
			cout<<aux->idRuta<<setw(25);
			cout<<aux->destino<<setw(30);
			cout<<aux->paradas<<setw(20);
			cout<<aux->horario.dia<<setw(15);
			cout<<aux->horario.hora<<setw(10);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
			cout<<aux->estado<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			//cout<<aux->sig<<endl;
		}
		aux = aux->sig;
	}
	/*
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	cout<<endl<<"Primer NODO: "<<primero;
	cout<<endl<<"Ultimo NODO: "<<ultimo;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);*/
}

void mostrarRutasInactivas(){
	struct Rutas *aux = primero;
	string inactivo="Inactivo";
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	cout<<endl<<endl<<"Mostrando la lista completa"<<endl;
	//cout<<"Ubicación"<<setw(10);
	cout<<"Id RUTA"<<setw(20);
	cout<<"Destino"<<setw(30);
	cout<<"Paradas"<<setw(20);
	cout<<"Día"<<setw(15);
	cout<<"Horario"<<setw(10);
	cout<<"Estado"<<endl;
	//cout<<"Siguiente"<<endl;
	while(aux!=NULL){
		if(aux->estado.compare(inactivo) == 0){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			//cout<<aux<<setw(10);
			cout<<aux->idRuta<<setw(25);
			cout<<aux->destino<<setw(30);
			cout<<aux->paradas<<setw(20);
			cout<<aux->horario.dia<<setw(15);
			cout<<aux->horario.hora<<setw(10);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
			cout<<aux->estado<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			//cout<<aux->sig<<endl;
		}
		aux = aux->sig;
	}
	/*
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	cout<<endl<<"Primer NODO: "<<primero;
	cout<<endl<<"Ultimo NODO: "<<ultimo;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);*/
}

void modificaRuta(){
	system("cls");
	struct Rutas *aux = primero;
	int idRuta=0;
	int opc=0;
	int sigue=0;
	
	string activo="Activo";
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
	printf("\n\n\n\t\t\tMODIFICA RUTA\n");
		
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	cout<<endl<<endl<<"Mostrando la lista de rutas"<<endl;
	//cout<<"Ubicación"<<setw(10);
	cout<<"Id RUTA"<<setw(20);
	cout<<"Destino"<<setw(30);
	cout<<"Paradas"<<setw(20);
	cout<<"Día"<<setw(15);
	cout<<"Horario"<<setw(10);
	cout<<"Estado"<<endl;
	//cout<<"Siguiente"<<endl;
	while(aux!=NULL){
		if(aux->estado.compare(activo) == 0){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			//cout<<aux<<setw(10);
			cout<<aux->idRuta<<setw(25);
			cout<<aux->destino<<setw(30);
			cout<<aux->paradas<<setw(20);
			cout<<aux->horario.dia<<setw(15);
			cout<<aux->horario.hora<<setw(10);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
			cout<<aux->estado<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			//cout<<aux->sig<<endl;
		}
		
		aux = aux->sig;
	}
	/*
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	cout<<endl<<"Primer Ruta: "<<primLista;
	cout<<endl<<"Ultima Ruta: "<<ultLista;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);*/
	
	idRuta = validaEntero("Id de Ruta: ");
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	cout<<endl<<"Ruta a modificar"<<endl;
	//cout<<"Ubicación"<<setw(10);
	cout<<"Id RUTA"<<setw(20);
	cout<<"Destino"<<setw(30);
	cout<<"Paradas"<<setw(20);
	cout<<"Día"<<setw(15);
	cout<<"Horario"<<setw(10);
	cout<<"Estado"<<endl;
	//cout<<"Siguiente"<<endl;
	aux=primero;
	while(aux!=NULL){
		if(idRuta == aux->idRuta){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			//cout<<aux<<setw(10);
			cout<<aux->idRuta<<setw(25);
			cout<<aux->destino<<setw(30);
			cout<<aux->paradas<<setw(20);
			cout<<aux->horario.dia<<setw(15);
			cout<<aux->horario.hora<<setw(10);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
			cout<<aux->estado<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			//cout<<aux->sig<<endl;
			
			do{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
				opc = validaEntero("1 para modificar DESTINO...2 para modificar PARADAS...3 para modificar DÍA...4 para modificar HORARIO: ");
				switch(opc){
					case OPC1:
						cout<<"DESTINO: ";
						getline(cin, aux->destino);
						cout<<endl<<"DESTINO ACTUALIZADO!!: ";
						break;
					case OPC2:
						cout<<"PARADAS: ";
						getline(cin, aux->paradas);
						cout<<endl<<"PARADAS ACTUALIZADAS!!: ";
						break;
					case OPC3:
						cout<<"DÍA: ";
						getline(cin, aux->horario.dia);
						cout<<endl<<"DÍA ACTUALIZADO!!: ";
						break;
					case OPC4:
						cout<<"HORARIO: ";
						getline(cin, aux->horario.hora);
						cout<<endl<<"HORARIO ACTUALIZADA!!: ";
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

void eliminaRuta(){
	system("cls");
	struct Rutas *aux = primero;
	int idRuta=0;
	int opc=0;
	int sigue=0;
	
	string activo="Activo";
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
	printf("\n\n\n\t\t\tELIMINA RUTA\n");
		
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	cout<<endl<<endl<<"Mostrando la lista de rutas"<<endl;
	//cout<<"Ubicación"<<setw(10);
	cout<<"Id RUTA"<<setw(20);
	cout<<"Destino"<<setw(30);
	cout<<"Paradas"<<setw(20);
	cout<<"Día"<<setw(15);
	cout<<"Horario"<<setw(10);
	cout<<"Estado"<<endl;
	//cout<<"Siguiente"<<endl;
	while(aux!=NULL){
		if(aux->estado.compare(activo) == 0){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			//cout<<aux<<setw(10);
			cout<<aux->idRuta<<setw(25);
			cout<<aux->destino<<setw(30);
			cout<<aux->paradas<<setw(20);
			cout<<aux->horario.dia<<setw(15);
			cout<<aux->horario.hora<<setw(10);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
			cout<<aux->estado<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			//cout<<aux->sig<<endl;
		}
		
		aux = aux->sig;
	}
	/*
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	cout<<endl<<"Primer Ruta: "<<primLista;
	cout<<endl<<"Ultima Ruta: "<<ultLista;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);*/
	
	do{	
		idRuta = validaEntero("Id de Ruta: ");
	
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
		cout<<endl<<"Ruta a eliminar"<<endl;
		//cout<<"Ubicación"<<setw(10);
		cout<<"Id RUTA"<<setw(20);
		cout<<"Destino"<<setw(30);
		cout<<"Paradas"<<setw(20);
		cout<<"Día"<<setw(15);
		cout<<"Horario"<<setw(10);
		cout<<"Estado"<<endl;
		//cout<<"Siguiente"<<endl;
		aux=primero;
		while(aux!=NULL){
			if(idRuta == aux->idRuta){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
				//cout<<aux<<setw(10);
				cout<<aux->idRuta<<setw(25);
				cout<<aux->destino<<setw(30);
				cout<<aux->paradas<<setw(20);
				cout<<aux->horario.dia<<setw(15);
				cout<<aux->horario.hora<<setw(10);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
				cout<<aux->estado<<endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
				//cout<<aux->sig<<endl;
				
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
				opc = validaEntero("1 para CONFIRMAR...Otro para CANCELAR: ");
				switch(opc){
					case OPC1:
						aux->estado = "Inactivo";
						cout<<endl<<"RUTA ELIMINADA!! ";
						break;
					default:
						cout<<endl<<"ELIMINACIÓN DE RUTA CANCELADA!!";
						break;	
				}
			}
			aux = aux->sig;			
		}
		sigue = validaEntero("1 para eliminar otra Ruta... otro para REGRESAR: ");
	}while(sigue==1);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
}

void mostrarUbiRutas(){
	struct Rutas *aux = primero;
	string activo="Activo";
	string inactivo="Inactivo";
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	cout<<endl<<endl<<"Mostrando la lista completa"<<endl;
	cout<<"Ubicación"<<setw(10);
	cout<<"Id RUTA"<<setw(20);
	cout<<"Destino"<<setw(30);
	cout<<"Paradas"<<setw(20);
	cout<<"Día"<<setw(15);
	cout<<"Horario"<<setw(10);
	cout<<"Estado"<<setw(10);
	cout<<"Siguiente"<<endl;
	while(aux!=NULL){
		if(aux->estado.compare(activo) == 0){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<aux<<setw(10);
			cout<<aux->idRuta<<setw(25);
			cout<<aux->destino<<setw(30);
			cout<<aux->paradas<<setw(20);
			cout<<aux->horario.dia<<setw(15);
			cout<<aux->horario.hora<<setw(10);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
			cout<<aux->estado<<setw(10);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<aux->sig<<endl;
		}else if(aux->estado.compare(inactivo) == 0){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<aux<<setw(10);
			cout<<aux->idRuta<<setw(25);
			cout<<aux->destino<<setw(30);
			cout<<aux->paradas<<setw(20);
			cout<<aux->horario.dia<<setw(15);
			cout<<aux->horario.hora<<setw(10);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
			cout<<aux->estado<<setw(10);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<aux->sig<<endl;
		}
		aux = aux->sig;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	cout<<endl<<"Primer NODO: "<<primero;
	cout<<endl<<"Ultimo NODO: "<<ultimo;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
}
