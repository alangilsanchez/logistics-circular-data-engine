//Lista de listas
//Crear el archivo o actualizarlo
void escrituraListaUsuarios(){
	Usuario *aux = primLista;
	
	ofstream archivo("ListaDeUsuarios.xls");
	while(aux!=NULL){
		archivo<<aux->id<<"\t";
		archivo<<aux->nombre<<"\t";
		archivo<<aux->apellidos<<"\t";
		archivo<<aux->correo<<"\t";
		archivo<<aux->cargo<<"\t";
		archivo<<aux->contrasena<<"\t";
		archivo<<aux->estado<<"\t";
		archivo<<aux->perfil<<"\n";
		aux = aux->sig;
	}
	archivo.close();
}
//Listas de listas
//Cargar la informacion del archivo en la estructura
void lecturaListaUsuarios(){
	Usuario *nuevo=NULL;
	
	ifstream arch("ListaDeUsuarios.xls");
	string linea,c;
	
	if(arch.fail()) cerr<<"No se encuentra ningun usuario"<<endl;
	else{
		while (getline(arch, linea)){
			nuevo = new Usuario;
			stringstream lee(linea);
			
			lee>>nuevo->id;
			getline(lee, c, '\t');
			getline(lee, nuevo->nombre, '\t');
			getline(lee, nuevo->apellidos, '\t');
			getline(lee, nuevo->correo, '\t');
			getline(lee, nuevo->cargo, '\t');
			getline(lee, nuevo->contrasena, '\t');
			getline(lee, nuevo->estado, '\t');
			getline(lee, nuevo->perfil, '\t');
			getline(lee, c, '\n');
			
			//nuevo->lista=archivoLectura(nuevo->id);
			nuevo->lista=NULL;
			nuevo->sig=NULL;
			
			if(primLista==NULL){
				primLista = nuevo;
				ultLista = nuevo;
			}else{
				ultLista->sig=nuevo;
				ultLista=nuevo;
			}
		}
	}
	arch.close();
}
