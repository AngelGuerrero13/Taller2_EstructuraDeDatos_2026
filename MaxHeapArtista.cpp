#include "MaxHeapArtista.hpp"

MaxHeapArtista::MaxHeapArtista(int cap) {
    this->capacidad = cap;
    this->tamanoActual = 0;
    this->arreglo = new Artista*[cap];
}

MaxHeapArtista::~MaxHeapArtista() {
    delete[] arreglo;
}

void MaxHeapArtista::intercambiar(int i, int j) {
    Artista* temp = arreglo[i];
    arreglo[i] = arreglo[j];
    arreglo[j] = temp;
}

bool MaxHeapArtista::esMayor(Artista* a1, Artista* a2) {

    int rep1 = a1->getReproduccionesTotales();
    int rep2 = a2->getReproduccionesTotales();
    
    if (rep1 > rep2) {
        return true;
    }
    if (rep1 < rep2) {
        return false;
    }
    
    string nom1 = a1->getNombre();
    string nom2 = a2->getNombre();
    
    if (nom1 < nom2) {
        return true;
    } else {
        return false;
    }
}

void MaxHeapArtista::insertar(Artista* artista) {

    if (tamanoActual == capacidad){
        return;
    }

    arreglo[tamanoActual] = artista;
    flotar(tamanoActual++);
}

void MaxHeapArtista::flotar(int i) {

    while (i != 0 && esMayor(arreglo[i], arreglo[padre(i)])) {

        intercambiar(i, padre(i));
        i = padre(i);
    }
}

Artista* MaxHeapArtista::extraerMaximo() {

    if (tamanoActual <= 0){
        return nullptr;
    }

    Artista* maximo = arreglo[0];
    arreglo[0] = arreglo[tamanoActual - 1];
    tamanoActual--;
    
    hundir(0);
    return maximo;
}

void MaxHeapArtista::hundir(int i) {

    int mayor = i;
    int izq = 2 * i + 1;
    int der = 2 * i + 2;
    
    if (izq < tamanoActual && esMayor(arreglo[izq], arreglo[mayor])){
        mayor = izq;
    }

    if (der < tamanoActual && esMayor(arreglo[der], arreglo[mayor])){
        mayor = der;

    }
    if (mayor != i) {

        intercambiar(i, mayor);
        hundir(mayor);

    }
}