#include "ListaCancion.hpp"

class NodoTrie{
    private:
        char caracter;
        ListaCancion* listaCanciones;
        NodoTrie* primerHijo;
        NodoTrie* siguienteHermano;

    public:
        NodoTrie(char c);

        char getCaracter();
        ListaCancion* getListaCanciones();
        NodoTrie* getPrimerHijo();
        NodoTrie* getSiguienteHermano();

        void setCaracter(char c);
        void setPrimerHijo(NodoTrie* primerHijo);
        void setSiguienteHermano(NodoTrie* siguienteHermano);

        ~NodoTrie();
};