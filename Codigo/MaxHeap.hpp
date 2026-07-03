#include "Cancion.hpp"
#include <string>

class MaxHeap{
    private:
        Cancion** arreglo; 
        int capacidad;
        int tamanoActual;

        int padre(int i);
        int hijoIzquierdo(int i);
        int hijoDerecho(int i);

        void flotar(int i);
        void hundir(int i);
        void intercambiar(int i, int j);

        bool esMayor(Cancion* cancion1, Cancion* cancion2);
        string minuscula(string palabra);

    public:
        MaxHeap(int capacidadMaxima);

        void insertar(Cancion* cancion);
        Cancion* extraerMaximo();
        bool estaVacio();

        ~MaxHeap();
};