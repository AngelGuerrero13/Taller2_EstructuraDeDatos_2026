#include "NodoAVL.hpp"

NodoAVL::NodoAVL(Cancion* c) {
    this->cancion = c;
    this->izquierdo = nullptr;
    this->derecho = nullptr;
    this->altura = 1; 
}

Cancion* NodoAVL::getCancion() {
    return this->cancion;
}

NodoAVL* NodoAVL::getIzquierdo() {
    return this->izquierdo;
}

NodoAVL* NodoAVL::getDerecho() {
    return this->derecho;
}

int NodoAVL::getAltura() {
    return this->altura;
}

void NodoAVL::setCancion(Cancion* c) {
    this->cancion = c;
}

void NodoAVL::setIzquierdo(NodoAVL* izq) {
    this->izquierdo = izq;
}

void NodoAVL::setDerecho(NodoAVL* der) {
    this->derecho = der;
}

void NodoAVL::setAltura(int alt) {
    this->altura = alt;
}

NodoAVL::~NodoAVL() {
    
    this->izquierdo = nullptr;
    this->derecho = nullptr;
}