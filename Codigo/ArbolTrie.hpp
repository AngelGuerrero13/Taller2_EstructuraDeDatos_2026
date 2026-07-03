#include "NodoTrie.hpp"
using namespace std;

class ArbolTrie{
    private:
        NodoTrie* raiz;

        NodoTrie* buscarHijo( NodoTrie* padre,char c);
        NodoTrie* agregarHijo(NodoTrie* padre,char c);
        void limpiarMemoria(NodoTrie* nodo);
        string minuscula(string palabra);
        void insertarSufijo(string sufijo, Cancion* cancion);
        bool contieneCancion(ListaCancion* lista, Cancion* cancion);

    public:
        ArbolTrie();

        void registrarCancion(Cancion* cancion);
        ListaCancion* buscarSubCadena(string subcadena);

        ~ArbolTrie();
};