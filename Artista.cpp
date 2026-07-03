#include "Artista.hpp"

Artista::Artista(string nom) {
    this->nombre = nom;
    this->reproduccionesTotales = 0;
    this->canciones = new ArbolAVL();
    this->siguiente = nullptr;
}

string Artista::getNombre() {
    return this->nombre;
}

int Artista::getReproduccionesTotales() {
    return this->reproduccionesTotales;
}

ArbolAVL* Artista::getCanciones() {
    return this->canciones;
}

Artista* Artista::getSiguiente() {
    return this->siguiente;
}

void Artista::setReproduccionesTotales(int total) {
    this->reproduccionesTotales = total;
}

void Artista::setSiguiente(Artista* sig) {
    this->siguiente = sig;
}

void Artista::agregarCancion(Cancion* c) {
    this->canciones->insertarCancion(c);
    this->reproduccionesTotales += c->getReproducciones();
}

Artista::~Artista() {
    delete canciones;
}