#pragma once
#include <iostream>
#include <string>
#include "Cancion.hpp"

using namespace std;

class NodoCancion{
    private:
        //Atributos
        Cancion* cancion;
        NodoCancion* siguiente;
        NodoCancion* anterior;

    public:
        //Constructor
        NodoCancion(Cancion* cancion);

        //Getters
        Cancion* getCancion();
        NodoCancion* getSiguiente();
        NodoCancion* getAnterior();

        //Setters
        void setCancion(Cancion* cancion);
        void setSiguiente(NodoCancion* siguiente);
        void setAnterior(NodoCancion* anterior);

        //Destructor
        ~NodoCancion();
};