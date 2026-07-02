#pragma once
#include "nodoCancion.hpp"

class ListaCancion{
    private:
        NodoCancion* cabeza;
        NodoCancion* cola;
        int total;
    
    public:
        //Constructor de la clase que sera la lista de canciones
        ListaCancion();

        //Getters
        NodoCancion* getCabeza();
        NodoCancion* getCola();
        int getTotal();

        //Setters
        void setCabeza(NodoCancion* cabeza);
        void setCola(NodoCancion* cola);
        void setTotal(int total);

        //Metodo para insertar las canciones al inicio
        void insertarInicio(Cancion* cancion);
        //Medoto para insertar las canciones al final
        void insertarFinal(Cancion* cancion);
        //Metodo para ver la lista de canciones
        void verLista();
        //Metodo para acceder a un nodo especifico
        NodoCancion* seleccionarNodo(int posicion);
        //Metoto para borrar nodo especifico
        void eliminarNodo(int posicion);
        //Metodo para vaciar la lista completa
        void vaciarLista();
        //Metodo para buscar cancion por id
        Cancion* buscarCancionId(string idBuscado);

        ~ListaCancion();
};