#include "Cancion.hpp"
#include "ListaCancion.hpp"

class NodoAVL{
    private:
        Cancion* cancion;
        NodoAVL* izquierdo;
        NodoAVL* derecho;
        int altura;

    public:
        NodoAVL(Cancion* cancion);

        Cancion* getCancion();
        NodoAVL* getIzquierdo();
        NodoAVL* getDerecho();
        int getAltura();

        void setCancion(Cancion* cancion);
        void setIzquierdo(NodoAVL* izq);
        void setDerecho(NodoAVL* der);
        void setAltura(int alt);

        ~NodoAVL();
};