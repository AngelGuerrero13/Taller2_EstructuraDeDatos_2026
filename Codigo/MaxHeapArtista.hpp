#include "Artista.hpp"

class MaxHeapArtista {
private:
    Artista** arreglo;
    int capacidad;
    int tamanoActual;

    int padre(int i);
    void intercambiar(int i, int j);
    void flotar(int i);
    void hundir(int i);
    bool esMayor(Artista* a1, Artista* a2);

public:
    MaxHeapArtista(int capacidad);
    
    void insertar(Artista* artista);
    Artista* extraerMaximo();
    bool estaVacio();

    ~MaxHeapArtista();
};