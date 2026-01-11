void agregarUsuario(char perfil[]){
	Usuario *nuevo = new Usuario;
	Usuario *aux=NULL;
	int sigue = 1;
	int i=0;
	
	primero=NULL;
	ultimo=NULL;
	
	if((strcmp(perfil, "Administrador")) == 0){
		if(primLista==NULL){
			nuevo->id = 771;
			printf("Id de Administrador: %d\n", nuevo->id);
			nuevo->perfil="Administrador";
		}
		else{
			//do{
				aux=ultLista;
				nuevo->id= (aux->id+1);
				printf("Id de Administrador: %d\n", nuevo->id);
				//i = validaId(primLista, nuevo->id);
			//}while(i==0);
			nuevo->perfil="Administrador";
		}
	}else{
		if(primLista==NULL){
			nuevo->id = 1;
			printf("Id de Personal: %d\n", nuevo->id);
			nuevo->perfil="Personal";
		}
		else{
			//do{
				aux=ultLista;
				nuevo->id= (aux->id+1);
				printf("Id de Personal: %d\n", nuevo->id);
				//i = validaId(primLista, nuevo->id);
			//}while(i==0);
			nuevo->perfil="Personal";
		}
	}
	cout<<"Nombre: ";
	getline(cin, nuevo->nombre);
	cout<<"Apellidos: ";
	getline(cin, nuevo->apellidos);
	cout<<"Correo: ";
	getline(cin, nuevo->correo);
	cout<<"Cargo: ";
	getline(cin, nuevo->cargo);
	cout<<"Contraseña: ";
	getline(cin, nuevo->contrasena);
	//strcpy(nuevo->estado, estado);
	nuevo->estado = "Activo";
	//strcpy(nuevo->perfil, perfil);
	
	/*
	while(sigue == 1){
		agregarFinal();
		//agregarPrimero();
		sigue = validaEntero("Teclea 1 para agregar otro: ");
	}*/
	//archivoEscritura(primero, nuevo->idLista );
	
	nuevo->sig = NULL;
	//nuevo->lista = primero;
	nuevo->lista = NULL;
	
	//archivoLectura(nuevo->idLista);
	
	if(primLista==NULL){
		primLista = nuevo;
		ultLista = nuevo;
	}else{
		ultLista->sig=nuevo;
		ultLista=nuevo;
	}
	
}

void mostrarUsuarioActivo(){
	system("cls");
	struct Usuario *aux = primLista;
	string activo="Activo";
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	cout<<endl<<endl<<"Mostrando la lista de usuarios"<<endl;
	cout<<"id"<<setw(15);
	cout<<"Nombre"<<setw(20);
	cout<<"Apellidos"<<setw(25);
	cout<<"Correo"<<setw(15);
	cout<<"Cargo"<<setw(15);
	cout<<"Estado"<<setw(20);
	cout<<"Perfil"<<endl;
	//cout<<"Lista(Primer nodo)"<<setw(10);
	while(aux!=NULL){
		if(aux->estado.compare(activo) == 0){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);	
			cout<<aux->id<<setw(15);
			cout<<aux->nombre<<setw(20);
			cout<<aux->apellidos<<setw(25);
			cout<<aux->correo<<setw(15);
			cout<<aux->cargo<<setw(15);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
			cout<<aux->estado<<setw(20);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<aux->perfil<<endl;
			//cout<<aux->lista<<endl;
		}
		
		aux = aux->sig;
	}
}

void mostrarUsuarioInactivo(){
	system("cls");
	struct Usuario *aux = primLista;
	string inactivo="Inactivo";
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	cout<<endl<<endl<<"Mostrando la lista de usuarios"<<endl;
	cout<<"id"<<setw(15);
	cout<<"Nombre"<<setw(20);
	cout<<"Apellidos"<<setw(25);
	cout<<"Correo"<<setw(15);
	cout<<"Cargo"<<setw(15);
	cout<<"Estado"<<setw(20);
	cout<<"Perfil"<<endl;
	//cout<<"Lista(Primer nodo)"<<setw(10);
	while(aux!=NULL){
		if(aux->estado.compare(inactivo) == 0){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);	
			cout<<aux->id<<setw(15);
			cout<<aux->nombre<<setw(20);
			cout<<aux->apellidos<<setw(25);
			cout<<aux->correo<<setw(15);
			cout<<aux->cargo<<setw(15);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
			cout<<aux->estado<<setw(20);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<aux->perfil<<endl;
		}
		
		aux = aux->sig;
	}
}

int inicioSecion(){	
	struct Usuario *aux=primLista;
	int op=1, i=0;
	string contra;
	string correo;
	string estado="Activo";
	string perfil1="Administrador";
	string perfil2="Personal";
	
	do{	
		aux=primLista;
		system("cls");
		//id = validaEntero("ID de usuario: ");
		printf("\nCorreo: ");
		getline(cin, correo);
		printf("\nContraseña: ");
		getline(cin, contra);
	
		while(aux!=NULL){
			if((aux->correo == correo) && ((aux->contrasena.compare(contra)) == 0 ) && ((aux->estado.compare(estado)) == 0) && ((aux->perfil.compare(perfil1)) == 0)){
				system("cls");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
				printf("BIENVENIDO ADMINISTRADOR!!");
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
				i=1;
				op=2;
				return i;
			}
			else{
				if((aux->correo == correo) && ((aux->contrasena.compare(contra)) == 0 ) && ((aux->estado.compare(estado)) == 0) && ((aux->perfil.compare(perfil2)) == 0)){
					system("cls");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
					printf("BIENVENIDO PERSONAL!!");
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
					i=2;
					op=2;
					return i;
				}
			}
			
			aux = aux->sig;
		}
		
		if(op==1){
			printf("\nRegistro no encontrado\n");
			op = validaEntero("Desea intentarlo de nuevo...1 para SI..otro para NO: ");
		}
	}while(op==1);
	return i;
}

void modifica(){
	system("cls");
	struct Usuario *aux = primLista;
	int idUsuario=0;
	int opc=0;
	int sigue=0;
	
	string activo="Activo";
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
	printf("\n\n\n\t\t\tMODIFICA USUARIO\n");
		
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	cout<<endl<<endl<<"Mostrando la lista de usuarios"<<endl;
	cout<<"id"<<setw(15);
	cout<<"Nombre"<<setw(20);
	cout<<"Apellidos"<<setw(25);
	cout<<"Correo"<<setw(15);
	cout<<"Cargo"<<setw(15);
	cout<<"Estado"<<setw(20);
	cout<<"Perfil"<<endl;
	//cout<<"Lista(Primer nodo)"<<setw(10);
	//cout<<"Siguiente"<<endl;
	while(aux!=NULL){
		if(aux->estado.compare(activo) == 0){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);	
			//cout<<aux<<setw(10);
			cout<<aux->id<<setw(15);
			cout<<aux->nombre<<setw(20);
			cout<<aux->apellidos<<setw(25);
			cout<<aux->correo<<setw(15);
			cout<<aux->cargo<<setw(15);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
			cout<<aux->estado<<setw(20);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<aux->perfil<<endl;
			//cout<<aux->lista<<endl;
			//cout<<aux->sig<<endl;
		}
		
		aux = aux->sig;
	}
	/*
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	cout<<endl<<"Primer LISTA: "<<primLista;
	cout<<endl<<"Ultima LISTA: "<<ultLista;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);*/
	
	idUsuario = validaEntero("Id de usuario: ");
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	cout<<endl<<"Usuario a modificar"<<endl;
	//cout<<"Ubicación"<<setw(10);
	cout<<"id"<<setw(15);
	cout<<"Nombre"<<setw(20);
	cout<<"Apellidos"<<setw(25);
	cout<<"Correo"<<setw(15);
	cout<<"Cargo"<<setw(15);
	cout<<"Estado"<<setw(20);
	cout<<"Perfil"<<endl;
	aux=primLista;
	while(aux!=NULL){
		if(idUsuario == aux->id){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);	
			//cout<<aux<<setw(10);
			cout<<aux->id<<setw(15);
			cout<<aux->nombre<<setw(20);
			cout<<aux->apellidos<<setw(25);
			cout<<aux->correo<<setw(15);
			cout<<aux->cargo<<setw(15);
			cout<<aux->estado<<setw(20);
			cout<<aux->perfil<<endl<<endl;
			
			do{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
				opc = validaEntero("1 para modificar CORREO...2 para modificar CARGO...3 para modificar CONTRASEÑA: ");
				switch(opc){
					case OPC1:
						cout<<"CORREO: ";
						getline(cin, aux->correo);
						cout<<endl<<"CORREO ACTUALIZADO!!: ";
						break;
					case OPC2:
						cout<<"Cargo: ";
						getline(cin, aux->cargo);
						cout<<endl<<"Cargo ACTUALIZADO!!: ";
						break;
					case OPC3:
						cout<<"CONTRASEÑA: ";
						getline(cin, aux->contrasena);
						cout<<endl<<"CONTRASEÑA ACTUALIZADA!!: ";
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

void elimina(){
	system("cls");
	struct Usuario *aux = primLista;
	int idUsuario=0;
	int opc=0;
	int sigue=0;
	string activo="Activo";
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
	printf("\n\n\n\t\t\tELIMINA USUARIO\n");
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	cout<<endl<<endl<<"Mostrando la lista de usuarios"<<endl;
	//cout<<"Ubicación"<<setw(10);
	cout<<"id"<<setw(15);
	cout<<"Nombre"<<setw(20);
	cout<<"Apellidos"<<setw(25);
	cout<<"Correo"<<setw(15);
	cout<<"Cargo"<<setw(15);
	cout<<"Estado"<<setw(20);
	cout<<"Perfil"<<endl;
	//cout<<"Lista(Primer nodo)"<<setw(10);
	//cout<<"Siguiente"<<endl;
	while(aux!=NULL){
		if(aux->estado.compare(activo) == 0){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);	
			//cout<<aux<<setw(10);
			cout<<aux->id<<setw(15);
			cout<<aux->nombre<<setw(20);
			cout<<aux->apellidos<<setw(25);
			cout<<aux->correo<<setw(15);
			cout<<aux->cargo<<setw(15);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
			cout<<aux->estado<<setw(20);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<aux->perfil<<endl;
			//cout<<aux->lista<<endl;
			//cout<<aux->sig<<endl;
		}
		
		aux = aux->sig;
	}

	
	do{	
		idUsuario = validaEntero("Id de usuario: ");
	
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
		cout<<endl<<"Usuario a eliminar"<<endl;
		//cout<<"Ubicación"<<setw(10);
		cout<<"id"<<setw(15);
		cout<<"Nombre"<<setw(20);
		cout<<"Apellidos"<<setw(25);
		cout<<"Correo"<<setw(15);
		cout<<"Cargo"<<setw(15);
		cout<<"Estado"<<setw(20);
		cout<<"Perfil"<<endl;
		aux=primLista;
		while(aux!=NULL){
			if(idUsuario == aux->id){
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);	
				//cout<<aux<<setw(10);
				cout<<aux->id<<setw(15);
				cout<<aux->nombre<<setw(20);
				cout<<aux->apellidos<<setw(25);
				cout<<aux->correo<<setw(15);
				cout<<aux->cargo<<setw(15);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
				cout<<aux->estado<<setw(20);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
				cout<<aux->perfil<<endl<<endl;
				
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
				opc = validaEntero("1 para CONFIRMAR...Otro para CANCELAR: ");
				switch(opc){
					case OPC1:
						aux->estado = "Inactivo";
						cout<<endl<<"USUARIO ELIMINADO!! ";
						break;
					default:
						cout<<endl<<"ELIMINACIÓN DE USUARIO CANCELADA!!";
						break;	
				}
			}
			aux = aux->sig;			
		}
		sigue = validaEntero("1 para eliminar otro Usuario... otro para REGRESAR: ");
	}while(sigue==1);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
}

void mostrarUbiUsuario(){
	system("cls");
	struct Usuario *aux = primLista;
	string activo="Activo";
	string inactivo="Inactivo";
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	cout<<endl<<endl<<"Mostrando la lista de usuarios"<<endl;
	cout<<"Ubicación"<<setw(10);
	cout<<"id"<<setw(15);
	cout<<"Nombre"<<setw(20);
	cout<<"Apellidos"<<setw(25);
	cout<<"Correo"<<setw(15);
	cout<<"Cargo"<<setw(15);
	cout<<"Estado"<<setw(20);
	cout<<"Perfil"<<setw(15);
	//cout<<"Lista(Primer nodo)"<<setw(10);
	cout<<"Siguiente"<<endl;
	while(aux!=NULL){
		if(aux->estado.compare(activo) == 0){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);	
			cout<<aux<<setw(10);
			cout<<aux->id<<setw(15);
			cout<<aux->nombre<<setw(20);
			cout<<aux->apellidos<<setw(25);
			cout<<aux->correo<<setw(15);
			cout<<aux->cargo<<setw(15);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
			cout<<aux->estado<<setw(20);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<aux->perfil<<setw(15);
			//cout<<aux->lista<<endl;
			cout<<aux->sig<<endl;
		}else if(aux->estado.compare(inactivo) == 0){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);	
			cout<<aux<<setw(10);
			cout<<aux->id<<setw(15);
			cout<<aux->nombre<<setw(20);
			cout<<aux->apellidos<<setw(25);
			cout<<aux->correo<<setw(15);
			cout<<aux->cargo<<setw(15);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
			cout<<aux->estado<<setw(20);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<aux->perfil<<setw(15);
			//cout<<aux->lista<<endl;
			cout<<aux->sig<<endl;
		}		
		aux = aux->sig;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
	cout<<endl<<"Primer LISTA: "<<primLista;
	cout<<endl<<"Ultima LISTA: "<<ultLista;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
}
