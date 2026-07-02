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
        void setPrimeroHijo(NodoTrie* primerHijo);
        void setsiguienteHermano(NodoTrie* siguienteHermano);

        ~NodoTrie();
};