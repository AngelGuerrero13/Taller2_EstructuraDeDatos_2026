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
        int reproducciones;
    
    public:
        //Constructor
        Cancion(string idInterno,string nombreCancion,string nombreArtista,string nombreAlbum,int anio,int duracionSegundos,string ubicacionArchivo,int reproducciones);
        
        //Getters
        string getId();
        string getNombreCancion();
        string getArtista();
        string getAlbum();
        int getAnio();
        string getDuracion();
        string getUbicacion();
        int getReproducciones();

        //Setters
        void setUbicacion(string ubicacion);

        void aumentarReproduccion();

        //Destructor
        ~Cancion();

};
