#include "nodoCancion.hpp"

NodoCancion::NodoCancion(Cancion* cancion){
    this->cancion = cancion;
    this->siguiente = nullptr;
    this->anterior = nullptr;
}
Cancion* NodoCancion::getCancion(){
    return this->cancion;
}
NodoCancion* NodoCancion::getSiguiente(){
    return this->siguiente;
}
NodoCancion* NodoCancion::getAnterior(){
    return this->anterior;
}
void NodoCancion::setCancion(Cancion* cancion){
    this->cancion = cancion;
}
void NodoCancion::setSiguiente(NodoCancion* siguiente){
    this->siguiente = siguiente;
}
void NodoCancion::setAnterior(NodoCancion* anterior){
    this->anterior = anterior;
}
NodoCancion::~NodoCancion(){
    cancion = nullptr;
    siguiente = nullptr;
    anterior = nullptr;
}
