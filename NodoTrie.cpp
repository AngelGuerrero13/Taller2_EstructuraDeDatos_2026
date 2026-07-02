#include "NodoTrie.hpp"

NodoTrie::NodoTrie(char caracter){
    this->caracter = caracter;
    this->listaCanciones = new ListaCancion();
    this->primerHijo = nullptr;
    this->siguienteHermano = nullptr;
}

char NodoTrie::getCaracter(){
    return this->caracter;
}

ListaCancion* NodoTrie::getListaCanciones(){
    return this->listaCanciones;
}

NodoTrie* NodoTrie::getPrimerHijo(){
    return this->primerHijo;
}

NodoTrie* NodoTrie::getSiguienteHermano(){
    return this->siguienteHermano;
}

void NodoTrie::setCaracter(char caracter){
    this->caracter = caracter;
}

void NodoTrie::setPrimeroHijo(NodoTrie* primerHijo){
    this->primerHijo = primerHijo;
}

void NodoTrie::setsiguienteHermano(NodoTrie* siguienteHermano){
    this->siguienteHermano = siguienteHermano;
}

NodoTrie::~NodoTrie(){
    delete this->listaCanciones;
    this->primerHijo = nullptr;
    this->siguienteHermano = nullptr;
}