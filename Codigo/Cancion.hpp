#pragma once
#include <iostream>
using namespace std;

class Cancion{
    private:
        //Atributos
        string idInterno;
        string nombreCancion;
        string nombreArtista;
        string nombreAlbum;
        int anio;
        int duracionSegundos;
        string ubicacionArchivo;
    
    public:
        //Constructor
        Cancion(string idInterno,string nombreCancion,string nombreArtista,string nombreAlbum,int anio,int duracionSegundos,string ubicacionArchivo);
        
        //Getters
        string getId();
        string getNombreCancion();
        string getArtista();
        string getAlbum();
        int getAnio();
        string getDuracion();
        string getUbicacion();

        //Setters
        void setUbicacion(string ubicacion);

        //Destructor
        ~Cancion();

};
