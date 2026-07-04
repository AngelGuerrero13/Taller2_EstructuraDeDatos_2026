#include "Cancion.hpp"
#include "ListaCancion.hpp"
#include "NodoAVL.hpp"

class ArbolAVL {
private:
    NodoAVL* raiz;

    int altura(NodoAVL* N);
    int max(int a, int b);
    NodoAVL* rotacionDerecha(NodoAVL* y);
    NodoAVL* rotacionIzquierda(NodoAVL* x);
    int obtenerBalance(NodoAVL* N);
    NodoAVL* insertar(NodoAVL* nodo, Cancion* cancion);
    void inOrden(NodoAVL* nodo, ListaCancion* resultados);
    void limpiarMemoria(NodoAVL* nodo);

public:
    ArbolAVL();
    
    void insertarCancion(Cancion* cancion);
    ListaCancion* obtenerCancionesOrdenadas();

    ~ArbolAVL();
};