#include "Sistema.hpp"

Sistema::Sistema(){

}

void Sistema::menu(){
    char opcion;

    Reproductor reproductor;

    reproductor.inicializar();
    
    
    do{
        reproductor.imprimirEstadoActual();
        cout<<""<<endl;
        cout<<"W - Reproducir/Pausar"<<endl;
        cout<<"Q - Pista Anterior"<<endl;
        cout<<"E - Pista Siguiente"<<endl;
        cout<<"S - Activar/Descativar modo aleatorio"<<endl;
        cout<<"R - Repeticion (Desactivado/Repetir una/Repetir todas)"<<endl;
        cout<<"A - Ver lista de reproduccion actual"<<endl;
        cout<<"L - Listado de canciones"<<endl;
        cout<<"X - Salir"<<endl;
        cout<<"Ingrese Opcion:"<<endl;

        cin>>opcion;
        opcion = toupper(opcion);
        cout<<"--------------------------------------------------------"<<endl;

        switch(opcion){
            case 'W':{
                reproductor.playPause();
                cout<<"--------------------------------------------------------"<<endl;
                break;
            }
            case 'Q':{
                reproductor.pistaAnterior();
                cout<<"--------------------------------------------------------"<<endl;
                break;
            }
            case 'E':{
                reproductor.pistaSiguiente();
                cout<<"--------------------------------------------------------"<<endl;
                break;
            }
            case 'S':{
                reproductor.aleatorio();
                cout<<"--------------------------------------------------------"<<endl;
                break;
            }
            case 'R':{
                reproductor.Repeticion();
                cout<<"--------------------------------------------------------"<<endl;
                break;
            }
            case 'A':{
                reproductor.ListaReproduccion();
                cout<<"--------------------------------------------------------"<<endl;
                break;
            }
            case 'L':{
                reproductor.listadoCanciones();
                cout<<"--------------------------------------------------------"<<endl;
                break;
            }
            case 'X':{
                reproductor.~Reproductor();
                cout<<"Programa finalizado..."<<endl;
                cout<<"--------------------------------------------------------"<<endl;
                break;
            }
        }


    }while(opcion!='X');


}

Sistema::~Sistema(){

}