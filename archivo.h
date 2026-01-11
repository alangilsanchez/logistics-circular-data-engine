void archivoEscritura(Rutas *primero, int id){
	Rutas *aux = primero;
	char arch[20];
	itoa(id,arch,10);
	strcat(arch, ".xls");
	
	ofstream archivo(arch);
	while(aux!=NULL){
		archivo<<aux->idRuta<<endl;
		ultimo = aux;
		aux = aux->sig;
	}
	archivo.close();
}
//Cargar la informacion del archivo en la estructura
Rutas *archivoLectura(int id){
	Rutas *primero=NULL;
	Rutas *ultimo=NULL;
	Rutas *nuevo=NULL;
	char archivo[20];
	itoa(id,archivo,10);
	strcat(archivo, ".xls");
	
	ifstream arch(archivo);
	string linea,c;
	
	//muestra las listitas que están incluidas en la "GRAN lista"
	cout<<id<<endl;
	
	if(arch.fail()) cerr<<"Error al abrir el archivo"<<endl;
	else{
		while (getline(arch, linea)){
			nuevo = new Rutas;
			stringstream lee(linea);
			
			lee>>nuevo->idRuta;
			getline(lee, c, '\n');
			
			nuevo->sig=NULL;
			
			if(primero==NULL){
				primero = nuevo;
				ultimo = nuevo;
			}else{
				ultimo->sig=nuevo;
				ultimo=nuevo;
			}
		}
	}
	
	arch.close();
	return primero;
}
