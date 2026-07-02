#pragma once
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <string>
#include "NodoCancion.hpp"
#include "ListaCancion.hpp"


using namespace std;

class Reproductor{
    private:
        ListaCancion canciones;
        bool reproduciendo;
        NodoCancion* cancionReproduciendo;
        bool modoAleatorio;
        int repeticion;
        ListaCancion listaReproduccion;
    public:
        //Constructor
        Reproductor();

        //Getters
        bool getReproduciendo();
        NodoCancion* getCancionReproduciendo();

        //Setters
        void setReproduciendo(bool reproduciendo);
        void setCancionReproduciendo(NodoCancion* cancionReproduciedo);

        //Metodos para el menu del sistema
        void leerArchivoCancion(string archivoCancion);
        void playPause();
        void pistaAnterior();
        void pistaSiguiente();
        void aleatorio();
        void Repeticion();
        void ListaReproduccion();
        void listadoCanciones();

        //Metodos auxiliares
        void mezclarLista();
        void imprimirEstadoActual();
        void saltarCancion(int posicion);
        void reproducirSeleccion(int posicion);
        void agregarCancionReproduccion(int posicion);
        void agregarCancionRegistro();
        void eliminarCancion(int posicion);
        void guardarEstado();
        void cargarEstado();
        void inicializar();
        
        //Destructor
        ~Reproductor();
};