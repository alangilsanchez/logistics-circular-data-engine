void escrituraListaRutas(){
	Rutas *aux = primero;
	
	ofstream archivo("ListaDeRutas.xls");
	while(aux!=NULL){
		archivo<<aux->idRuta<<"\t";
		archivo<<aux->destino<<"\t";
		archivo<<aux->paradas<<"\t";
		archivo<<aux->horario.dia<<"\t";
		archivo<<aux->horario.hora<<"\t";
		archivo<<aux->estado<<"\n";
		aux = aux->sig;
	}
	archivo.close();
}

//Listas de listas
//Cargar la informacion del archivo en la estructura
void lecturaListaRutas(){
	Rutas *nuevo=NULL;
	
	ifstream arch("ListaDeRutas.xls");
	string linea,c;
	
	if(arch.fail()) cerr<<"No se encuentra ninguna Ruta"<<endl;
	else{
		while (getline(arch, linea)){
			nuevo = new Rutas;
			stringstream lee(linea);
			
			lee>>nuevo->idRuta;
			getline(lee, c, '\t');
			getline(lee, nuevo->destino, '\t');
			getline(lee, nuevo->paradas, '\t');
			getline(lee, nuevo->horario.dia, '\t');
			getline(lee, nuevo->horario.hora, '\t');
			getline(lee, nuevo->estado, '\t');
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
}
