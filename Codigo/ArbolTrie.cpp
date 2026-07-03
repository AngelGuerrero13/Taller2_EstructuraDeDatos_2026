#include "ArbolTrie.hpp"

ArbolTrie::ArbolTrie() {
    raiz = new NodoTrie('\0'); 
}

void ArbolTrie::limpiarMemoria(NodoTrie* nodo) {

    if (nodo == nullptr) return;
    
    limpiarMemoria(nodo->getPrimerHijo());
    limpiarMemoria(nodo->getSiguienteHermano());
    
    delete nodo;
}

string ArbolTrie::minuscula(string palabra) {

    string minuscula = "";

    for (char c : palabra) {

        minuscula += tolower(c);

    }

    return minuscula;
}

NodoTrie* ArbolTrie::buscarHijo(NodoTrie* padre, char c) {
    
    NodoTrie* actual = padre->getPrimerHijo();

    while (actual != nullptr) { 

        if (actual->getCaracter() == c){
            return actual;
        }

        actual = actual->getSiguienteHermano();

    }
    return nullptr;
}

NodoTrie* ArbolTrie::agregarHijo(NodoTrie* padre, char c) {

    NodoTrie* nuevo = new NodoTrie(c);

    if (padre->getPrimerHijo() == nullptr) {

        padre->setPrimerHijo(nuevo);

    } else {

        NodoTrie* actual = padre->getPrimerHijo();

        while (actual->getSiguienteHermano() != nullptr) {

            actual = actual->getSiguienteHermano();
        }

        actual->setSiguienteHermano(nuevo);
    }
    return nuevo;
}

bool ArbolTrie::contieneCancion(ListaCancion* lista, Cancion* cancion) {

    NodoCancion* aux = lista->getCabeza();

    while (aux != nullptr) {

        if (aux->getCancion() == cancion){
            return true;
        } 
        aux = aux->getSiguiente();
    }
    return false;
}

void ArbolTrie::insertarSufijo(string sufijo, Cancion* cancion) {

    NodoTrie* actual = raiz;

    for (char c : sufijo) {

        NodoTrie* hijo = buscarHijo(actual, c);

        if (hijo == nullptr) {
            hijo = agregarHijo(actual, c);
        }

        actual = hijo;
        
        
        if (!contieneCancion(actual->getListaCanciones(), cancion)) {
            
            actual->getListaCanciones()->insertarFinal(cancion);
        }
    }
}

void ArbolTrie::registrarCancion(Cancion* cancion){

    string textoCompleto = cancion->getNombreCancion() + " " + cancion->getArtista();
    string textoMin = minuscula(textoCompleto);
    
    for (size_t i = 0; i < textoMin.length(); i++) {

        insertarSufijo(textoMin.substr(i), cancion);

    }
}

ListaCancion* ArbolTrie::buscarSubCadena(string subcadena) {

    string subMin = minuscula(subcadena);
    ListaCancion* resultados = new ListaCancion(); 
    
    NodoTrie* actual = raiz;

    for (char c : subMin) {

        actual = buscarHijo(actual, c);
        if (actual == nullptr){
            return resultados;
        }
    }
    
    NodoCancion* aux = actual->getListaCanciones()->getCabeza();

    while (aux != nullptr) {
        
        resultados->insertarFinal(aux->getCancion());
        aux = aux->getSiguiente();
    }
    
    return resultados;
}

ArbolTrie::~ArbolTrie() {
    limpiarMemoria(raiz);
}