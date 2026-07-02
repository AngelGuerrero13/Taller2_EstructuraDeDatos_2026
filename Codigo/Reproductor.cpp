#include "Reproductor.hpp"

//Constructor
Reproductor::Reproductor(){
    this->reproduciendo = false;
    this->cancionReproduciendo = nullptr;
    this->modoAleatorio = false;
    this->repeticion = 1;
}

//Getters
bool Reproductor::getReproduciendo(){
    return this->reproduciendo;
}
NodoCancion* Reproductor::getCancionReproduciendo(){
    return this->cancionReproduciendo;
}

//Setters
void Reproductor::setReproduciendo(bool reproduciendo){
    this->reproduciendo = reproduciendo;
}
void Reproductor::setCancionReproduciendo(NodoCancion* cancionReproduciendo){
    this->cancionReproduciendo = cancionReproduciendo;
}

//Metodos de reproductor

//Metodo que lee el archivo donde se encuentran las canciones y se enlazan en una lista
void Reproductor::leerArchivoCancion(string archivoCancion){

    ifstream archivo(archivoCancion);

    string linea;

    if(!archivo.is_open()){
        cout<<"Error. No se pudo abrir el archivo"<<endl;
        return;
    }

    while(getline(archivo,linea)){

        stringstream ss(linea);
        string idInterno;
        string nombreCancion;
        string nombreArtista;
        string nombreAlbum;
        string anio;
        string duracion;
        string ubicacionArchivo;

        getline(ss,idInterno,',');
        getline(ss,nombreCancion,',');
        getline(ss,nombreArtista,',');
        getline(ss,nombreAlbum,',');
        getline(ss,anio,',');
        getline(ss,duracion,',');
        getline(ss,ubicacionArchivo,',');

        int anioCancion = stoi(anio);
        int duracionSegundos = stoi(duracion);

        //Se crea la clase y se agrega a la lista tda

        Cancion* cancion = new Cancion(idInterno,nombreCancion,nombreArtista,nombreAlbum,anioCancion,duracionSegundos,ubicacionArchivo);

        this->canciones.insertarFinal(cancion);

    }
    archivo.close();

    //Se asigan la primera cancion que se esta reproduciendo que sera la cabeza de la lista de canciones, se debe asegurar que la lista no este vacia
    if(this->canciones.getCabeza() != nullptr){
        setCancionReproduciendo(this->canciones.getCabeza());
    }

    cout<<"Archivo leido correctamente. Total canciones: "<<canciones.getTotal()<<endl;
    cout<<"--------------------------------------------------------"<<endl;
}

void Reproductor::playPause(){
    //Si no hay ninguna cancion el metodo no hace nada
    if(this->cancionReproduciendo == nullptr){
        return;
    }

    //Variable booleana que invierte el estado en el que esta nuestra variable reproduciendo
    bool nuevoEstado = !this->getReproduciendo();
    //Se cambia el estado de reproduciendo
    this->setReproduciendo(nuevoEstado);

    //Mostrar el mensaje dependiendo del estado
    imprimirEstadoActual();

    guardarEstado();
}

void Reproductor::pistaAnterior(){
    //Se verifica que hay canciones reproduciendose
    if(this->cancionReproduciendo==nullptr){
        return;
    }

    //Si repeticion es 2 (se repite una) no hay siguiente
    if(this->repeticion == 2){
        imprimirEstadoActual();
        return;
    }

    //Se obtiene la cancion anterior de la cancion que se esta reproduciendo actualmente
    NodoCancion* anterior = this->getCancionReproduciendo()->getAnterior();
    
    //Se verifica que no estamos en la primera cancion (si es nullptr es la primera cancion)
    if(anterior != nullptr){
        //La cancion que se va a reproducir es la cancion anteriro
        this->setCancionReproduciendo(anterior);
    }

    //Se muestra la cancion que se reproduce ahora
    imprimirEstadoActual();

    guardarEstado();
}

void Reproductor::pistaSiguiente(){
    //Se verifica que hay canciones reproduciendose
    if(this->cancionReproduciendo==nullptr){
        return;
    }

    //Si repeticion es 2 (se repite una) no hay siguiente
    if(this->repeticion == 2){
        imprimirEstadoActual();
        return;
    }

    //Se obtiene la cancion siguiente de la cancion que se esta reproduciendo actualmente
    NodoCancion* siguiente = this->getCancionReproduciendo()->getSiguiente();
    
    //Se verifica que no estamos en la ultima cancion (si es nullptr es la ultima cancion)
    if(siguiente != nullptr){
        //La cancion que se va a reproducir es la cancion siguiente
        this->setCancionReproduciendo(siguiente);
    //Si no hay siguiente, llegamos al final y repetimos todas
    }else if(this->repeticion == 3){
        //Volvemos al inicio
        this->setCancionReproduciendo(this->canciones.getCabeza());
        //Si esta activado el modo aleatorio mezclamos la lista
        if(this->modoAleatorio){
            this->mezclarLista();
            //Como mezclarLista pone la cancion que se esta reproduciendo a la cabeza, apuntamos a la nueva cabeza
            this->setCancionReproduciendo(this->canciones.getCabeza());
        }
    //Si no hay siguiente y la repeticion esta desactivada retornamos
    }else{
        return;
    }

    //Se muestra la cancion que se reproduce ahora
    imprimirEstadoActual();

    guardarEstado();
}

void Reproductor::aleatorio(){
    //Se verifica hay una cancion reproduciendose
    if(this->cancionReproduciendo == nullptr){
        return;
    }

    //Variable booleana que invierte el estado en el que esta nuestra variable modoAleatorio
    this->modoAleatorio = !this->modoAleatorio;

    //Mezclamos si se activa el modo aleatorio (modoAleatorio == true);
    if(this->modoAleatorio){
        mezclarLista();
        cout<<"Modo aleatorio: Activado"<<endl;
    }else{
        cout<<"Modo aleatorio: Desactivado"<<endl;
    }

    imprimirEstadoActual();

    guardarEstado();
}

void Reproductor::Repeticion(){
    //Nos asegutamos de que hay canciones reproduciendose
    if(this->cancionReproduciendo == nullptr){
        return;
    }

    //Como debe ser un boton ciclico se debe cambiar el estado segun en cual se encuentre
    //Si es 1, se presiona una vez y cambia a 2
    if(this->repeticion == 1){
        this->repeticion = 2;
    //Si es 2, se presiona una vez y cambia a 3
    }else if(this->repeticion == 2){
        this->repeticion = 3;
    //Si no es 1,2,3 (se presiona cuando ya es 3), cambia a 1
    }else{
        this->repeticion = 1;
    }
    
    //Se imprime el nuevo estado
    imprimirEstadoActual();

    guardarEstado();
}

void Reproductor::ListaReproduccion(){
    
    cout<<"Lista de reproduccion actual: "<<endl;
    if(listaReproduccion.getCabeza() == nullptr){
        cout<<"Vacia"<<endl;
    }else{
        listaReproduccion.verLista();
    }

    char opcion;

    do{
        cout<<"Opciones:"<<endl;

        if(listaReproduccion.getCabeza() != nullptr){
            cout<<"S<num> - Saltar a la cancion seleccionada"<<endl;
        }

        cout<<"V - Volver al menu principal"<<endl;

        cin>>opcion;
        opcion = toupper(opcion);

        switch(opcion){
            case 'S':{
                int posicion;

                cout<<"Indicar posicion de la cancion"<<endl;
                cin>>posicion;

                saltarCancion(posicion);
                break;
            }
            case 'V':{
                break;
            }
        }

    }while(opcion!='V');

}

void Reproductor::listadoCanciones(){

    if(canciones.getCabeza()==nullptr){
        cout<<"No hay canciones registradas."<<endl;
        return;
    }

    char opcion;

    do{
        imprimirEstadoActual();
        cout<<""<<endl;
        cout<<"Canciones registradas: "<<endl;
        canciones.verLista();
        cout<<""<<endl;

        cout<<"Opciones:"<<endl;
        cout<<"R<num> - Reproducir cancion seleccionada"<<endl;
        cout<<"A<num> - Agregar cancion seleccionada al final de la lista de reproduccion actual"<<endl;
        cout<<"N - Agregar cancion al registro de canciones"<<endl;
        cout<<"D<num> - Eliminar cancion seleccionada"<<endl;
        cout<<"V - Volver al menu principal: "<<endl;

        cin>>opcion;
        opcion = toupper(opcion);

        switch(opcion){
            case 'R':{
                int posicion;

                cout<<"Indicar posicion de la cancion: "<<endl;
                cin>>posicion;

                reproducirSeleccion(posicion);

                break;
            }
            case 'A':{
                int posicion;

                cout<<"Indicar posicion de la cancion: "<<endl;
                cin>>posicion;

                agregarCancionReproduccion(posicion);

                break;
            }
            case 'N':{

                agregarCancionRegistro();

                break;
            }
            case 'D':{
                int posicion;

                cout<<"Indicar posicion de la cancion: "<<endl;
                cin>>posicion;

                eliminarCancion(posicion);

                break;
            }
            case 'V':{
                break;
            }
        }

    }while(opcion!='V');

}


//Metodos auxiliares
void Reproductor::mezclarLista(){
    //Se obtiene el total de canciones que tenemos para mezclar
    int n = this->listaReproduccion.getTotal();

    //Se verifica que exista mas de una cancion en la lista para mezclar
    if(n<=1 || this->cancionReproduciendo == nullptr){
        return;
    }

    //Se mueve la cancion que se esta reproduciendo a la cabeza para mezclar el resto de la lista
    NodoCancion* actual = this->cancionReproduciendo;

    if(actual != this->listaReproduccion.getCabeza()){

        actual->getAnterior()->setSiguiente(actual->getSiguiente());

        if(actual->getSiguiente() != nullptr){
            actual->getSiguiente()->setAnterior(actual->getAnterior());
        }else{
            this->listaReproduccion.setCola(actual->getAnterior());
        }

        //Colocar la cancion al inicio
        actual->setSiguiente(this->listaReproduccion.getCabeza());
        this->listaReproduccion.getCabeza()->setAnterior(actual);
        actual->setAnterior(nullptr);
        this->listaReproduccion.setCabeza(actual);
    }

    //Se itera el doble del tamaño de la lista para mezclar bien la lista
    for(int i=0;i<n*2;i++){

        //Se crea una variable con un indice aleatorio para mezclar la lista, pero es despues de la cabeza
        int posicionAzar=(rand()%(n-1))+1;

        //Nodo auxiliar para extraer canciones
        NodoCancion* aux = this->listaReproduccion.getCabeza();

        //Se busca un nodo al azar
        for(int j=0;j<posicionAzar;j++){
            aux=aux->getSiguiente();
        }

        //Si el nodo elegido es nulo o es la ultima cancion no hacemos esta iteracion
        if(aux == nullptr || aux == this->listaReproduccion.getCola()){
            continue;
        }

        aux->getAnterior()->setSiguiente(aux->getSiguiente());

        if(aux->getSiguiente() != nullptr){
            aux->getSiguiente()->setAnterior(aux->getAnterior());
        }

        //Se coloca al final de la lista
        NodoCancion* antiguaCola = this->listaReproduccion.getCola();
        
        antiguaCola->setSiguiente(aux);
        aux->setAnterior(antiguaCola);
        aux->setSiguiente(nullptr);

        //Se actualiza la cola de la lista
        this->listaReproduccion.setCola(aux);
    }

}

void Reproductor::imprimirEstadoActual(){
    if(this->cancionReproduciendo == nullptr){
        return;
    }

    //Se imprime estado de reproduccion
    if(this->getReproduciendo()){
        cout<<"Reproduciendo ";
    }else{
        cout<<"En pausa ";
    }

    if(this->modoAleatorio || this->repeticion>1){
        cout<<"(";

        //Se imprime el indicador de modo aleatorio
        if(this->modoAleatorio){
            cout<<"S";
            //SI hay repeticion se pone guion
            if(this->repeticion > 1){
                cout<<"-";
            }
        }

        //Se imprime el estado de repeticion
        if(this->repeticion == 2){
            cout<<"R1";//Repetir una
        }else if(this->repeticion == 3){
            cout<<"RA";//Repetir todas(all)
        }

        cout<<")";
    }

    //Nombre de la cancion
    cout<<": "<<this->cancionReproduciendo->getCancion()->getNombreCancion()<<" - "<<this->cancionReproduciendo->getCancion()->getArtista()<<endl;
}

void Reproductor::saltarCancion(int posicion){
    //Validamos que una cancion se este reproduciendo
    if(this->cancionReproduciendo == nullptr){
        cout << "No hay ninguna canción reproduciéndose." << endl;
        return;
    }
    
    //Buscamos la cancion seleccionada por medio de la siguiente a la actual, la actual se esta reproduciendo(fuera de las canciones pendientes)
    NodoCancion* cancionLista = this->cancionReproduciendo->getSiguiente();
    //Puntero auxiliar para guardad la cancion
    NodoCancion* cancionSaltar = nullptr;
    //Para comparar el indice de la cancion
    int contador = 1;
    //Buscamos la cancion y la guardamos en la variable cancionSaltar.
    while(cancionLista != nullptr){
        if(contador == posicion){
            cancionSaltar = cancionLista;
            break;
        }
        cancionLista = cancionLista->getSiguiente();
        contador ++;
    }

    //Validamos si la cancion existe
    if(cancionSaltar == nullptr){
        cout<<"Error: la posicion seleccionada no existe en la cola."<<endl;
        return;
    }

    //Eliminamos las demas canciones, detras de la cancion que buscamos
    NodoCancion* cancionBorrar = this->cancionReproduciendo->getSiguiente();
    //Borramos las canciones
    while(cancionBorrar != cancionSaltar){
        NodoCancion* aux = cancionBorrar;

        cancionBorrar = cancionBorrar->getSiguiente();
        //Eliminamos la cancion
        delete aux;
        //Reducimos el numero de canciones en la lista de reproduccion
        int total = this->listaReproduccion.getTotal() - 1;
        this->listaReproduccion.setTotal(total);
    }

    //La cabeza actual apunta a la cancion a la que saltamos
    this->listaReproduccion.setCabeza(cancionSaltar);
    cancionSaltar->setAnterior(nullptr);

    //Saltamos a la cancion seleccionada y la reproducimos
    setCancionReproduciendo(cancionSaltar);
    this->reproduciendo = true;

    imprimirEstadoActual();

    guardarEstado();
}

void Reproductor::reproducirSeleccion(int posicion){
    //Buscamos el nodo en la posicion indicada
    NodoCancion* nodoSeleccion = this->canciones.seleccionarNodo(posicion);

    //Si el nodo seleccionado es nulo, no se encuentra en la lista
    if(nodoSeleccion == nullptr){
        cout<<"Error: Posicion no valida"<<endl;
        return;
    }

    //Guardamos la cancion seleccionada
    Cancion* cancionSeleccion = nodoSeleccion->getCancion();
    
    this->cancionReproduciendo = nullptr;

    //Vaciamos la lista
    this->listaReproduccion.vaciarLista();
    //Insertamos la cancion seleccionada a la nueva lista de reproduccion
    this->listaReproduccion.insertarFinal(cancionSeleccion);
    //El reproductor apunta a esta nueva cancion
    this->setCancionReproduciendo(this->listaReproduccion.getCabeza());

    //Agregamos el resto de canciones
    NodoCancion* aux = this->canciones.getCabeza();
    while(aux != nullptr){
        if(aux->getCancion() != cancionSeleccion){
            this->listaReproduccion.insertarFinal(aux->getCancion());
        }
        aux = aux->getSiguiente();
    }

    //Mezclamos el resto de canciones de forma aleatoria
    mezclarLista();

    //Reproducimos la cancion actual
    this->reproduciendo = true;

    guardarEstado();
}

void Reproductor::agregarCancionReproduccion(int posicion){
    //Buscamos el nodo en la posicion indicada
    NodoCancion* nodoSeleccion = this->canciones.seleccionarNodo(posicion);

    //Si el nodo seleccionado es nulo, no se encuentra en la lista
    if(nodoSeleccion == nullptr){
        cout<<"Error: Posicion no valida"<<endl;
        return;
    }

    //Guardamos la cancion seleccionada
    Cancion* cancionSeleccion = nodoSeleccion->getCancion();

    //Agregamos la cancion al final de la lista de reproduccion
    this->listaReproduccion.insertarFinal(cancionSeleccion);

    guardarEstado();

    cout<<"Cancion "<<cancionSeleccion->getNombreCancion()<<" agregada al final de la lista de reproduccion."<<endl;
}

void Reproductor::agregarCancionRegistro(){
    //Los atributos que tendra la cancion en el archivo
    string idInterno;
    string nombreCancion;
    string nombreArtista;
    string nombreAlbum;
    int anio;
    int duracionSegundos;
    string ubicacion;

    //Limpiar buffer
    cin.ignore(1000, '\n');

    cout<<"----Agregar nueva cancion al registro----"<<endl;

    idInterno = to_string(this->canciones.getTotal()+1);

    cout<<"Nombre de la cancion: ";
    getline(cin,nombreCancion);

    cout<<"Nombre del artista: ";
    getline(cin,nombreArtista);

    cout<<"Nombre del album: ";
    getline(cin,nombreAlbum);

    cout<<"Año de lanzamiento: ";
    cin>>anio;

    cout<<"Duracion de la cancion(en segundos): ";
    cin>>duracionSegundos;

    cout<<"Ubicaciond el archivo: ";
    getline(cin,ubicacion);

    //Creamos la nueva cancion
    Cancion* cancionNueva = new Cancion(idInterno,nombreCancion,nombreArtista,nombreAlbum,anio,duracionSegundos,ubicacion);
    //La agregamos al final de la lista de canciones para no leer nuevamente todo el archivo
    this->canciones.insertarFinal(cancionNueva);

    //Abrimos el archivo en modo sobreescritura
    ofstream archivo("music_source.txt",ios::app);

    if(archivo.is_open()){
        //Agregamos el formato que debe tener la cancion en el archivo
        archivo<<idInterno<<","<<nombreCancion<<","<<nombreArtista<<","<<nombreAlbum<<","<<anio<<","<<duracionSegundos<<","<<ubicacion<<endl;
        archivo.close();
        cout<<"Cancion registrada exitosamente en el archivo"<<endl;
    }else{
        cout<<"Error: No se pudo abrir el archivo"<<endl;
    }

    guardarEstado();

}

void Reproductor::eliminarCancion(int posicion){
    //Identificamos la cancion a eliminar
    NodoCancion* cancionEliminar = this->canciones.seleccionarNodo(posicion);

    //Verificamos que existe
    if(cancionEliminar == nullptr){
        cout<<"Error: No se encontro la cancion"<<endl;
        return;
    }

    string nombreEliminar = cancionEliminar->getCancion()->getNombreCancion();

    //Eliminamos la cancion de la lista de canciones
    this->canciones.eliminarNodo(posicion);

    //Ahora eliminamos la cancion del archivo
    ofstream archivo("music_source.txt");

    if(archivo.is_open()){

        NodoCancion* aux = this->canciones.getCabeza();

        while(aux != nullptr){
            Cancion* cancion = aux->getCancion();

            archivo<<cancion->getId()<<","<<cancion->getNombreCancion()<<","<<cancion->getArtista()<<","<<cancion->getAlbum()<<","<<cancion->getAnio()<<","<<cancion->getDuracion()<<","<<cancion->getUbicacion()<<endl;
            
            aux = aux->getSiguiente();
        }
        archivo.close();
        cout<<"La cancion "<<nombreEliminar<<" ha sido eliminada exitosamente"<<endl;
    }else{
        cout<<"Error: No se pudo eliminar la cancion"<<endl;
    }

    guardarEstado();
}

void Reproductor::guardarEstado(){

    ofstream archivo("status.cfg");

    if(!archivo.is_open()){
        return;
    }

    //Verificamos si hay una cancion reproduciendose y guardamos su id
    if(this->cancionReproduciendo != nullptr){
        archivo<<this->cancionReproduciendo->getCancion()->getId()<<",";
    }else{
        archivo<<"NULL,";
    }
    //Guardamos el modo en que se encuetra la lista, en que repeticion esta, si se esta reproduciendo o no
    archivo<<this->modoAleatorio<<","<<this->repeticion<<","<<this->reproduciendo<<endl;

    //Guardamos la lista de resproduccion
    NodoCancion* aux = this->listaReproduccion.getCabeza();

    while(aux != nullptr){
        archivo<<aux->getCancion()->getId();

        if(aux->getSiguiente() != nullptr){

            archivo<<",";
        }

        aux = aux->getSiguiente();
    }

    archivo.close();
}

void Reproductor::cargarEstado(){

    ifstream archivo("status.cfg");

    if(!archivo.is_open()){
        return;
    }

    string lineaCabeza;
    string lineaCola;
    //Leemos el estado que se guarda en el archivo
    if(getline(archivo,lineaCabeza)){

        stringstream ss(lineaCabeza);

        string idInterno;
        string modoAl;
        string rep;
        string repro;

        getline(ss,idInterno,',');
        getline(ss,modoAl,',');
        getline(ss,rep,',');
        getline(ss,repro,',');

        this->modoAleatorio = (modoAl == "1");
        this->repeticion = stoi(rep);
        this->reproduciendo = (repro=="1");

        //Cargamos la cola
        if (getline(archivo, lineaCola) && !lineaCola.empty()) {

            stringstream ssCola(lineaCola);
            string id;

            this->listaReproduccion.vaciarLista();
            
            while (getline(ssCola, id, ',')) {
                //Buscamos la canción en la lista de canciones
                Cancion* cancion = this->canciones.buscarCancionId(id); 

                if(cancion != nullptr){
                    this->listaReproduccion.insertarFinal(cancion);
                }
            }
        }

        //Asignar cancionReproduciendo buscando el ID en la nueva listaReproduccion
        if (idInterno != "NULL") {

             NodoCancion* aux = this->listaReproduccion.getCabeza();

             while(aux != nullptr) {

                 if(aux->getCancion()->getId() == idInterno) {

                     this->cancionReproduciendo = aux;
                     break;
                 }

                 aux = aux->getSiguiente();

             }
        }
    }

    archivo.close();
}

void Reproductor::inicializar() {

    ifstream source("music_source.txt");

    if (!source.is_open()) {
        cout << "Error Crítico: music_source.txt no encontrado. No se puede iniciar." << endl;
        return; 
    }
    source.close();

    //Cargar biblioteca
    this->leerArchivoCancion("music_source.txt");

    //Cargar estado previo
    this->cargarEstado();
}

//Destructor
Reproductor::~Reproductor(){
    //Guardamos el estado
    guardarEstado();
    //Eliminamos las listas para liberar memoria
    this->listaReproduccion.vaciarLista();
    this->canciones.vaciarLista();
}