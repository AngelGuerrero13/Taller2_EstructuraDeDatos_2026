#include "MaxHeap.hpp"

MaxHeap::MaxHeap(int capacidadMaxima) {
    this->capacidad = capacidadMaxima;
    this->tamanoActual = 0;
    this->arreglo = new Cancion*[capacidadMaxima];
}

int MaxHeap::padre(int i) { return (i - 1) / 2; }
int MaxHeap::hijoIzquierdo(int i) { return (2 * i) + 1; }
int MaxHeap::hijoDerecho(int i) { return (2 * i) + 2; }

void MaxHeap::intercambiar(int i, int j) {
    Cancion* temp = arreglo[i];
    arreglo[i] = arreglo[j];
    arreglo[j] = temp;
}

string MaxHeap::minuscula(string palabra) {
    string min = "";
    for (char c : palabra){
        min += std::tolower(c);
    } 
    return min;
}


bool MaxHeap::esMayor(Cancion* c1, Cancion* c2) {

    // Criterio 1: Número de reproducciones
    if (c1->getReproducciones() != c2->getReproducciones()) {
        return c1->getReproducciones() > c2->getReproducciones();
    }
    
    // Criterio 2: Empate  Orden alfabético por Nombre de Canción
    string nom1 = minuscula(c1->getNombreCancion());
    string nom2 = minuscula(c2->getNombreCancion());
    if (nom1 != nom2) {
        return nom1 < nom2; 
    }

    // Criterio 3: Empate en Nombre -> Orden alfabético por Artista
    string art1 = minuscula(c1->getArtista());
    string art2 = minuscula(c2->getArtista());
    return art1 < art2;
}

void MaxHeap::insertar(Cancion* cancion) {
    if (tamanoActual == capacidad){
        return;        
    }

    // Insertamos al final del árbol
    int i = tamanoActual;
    arreglo[i] = cancion;
    tamanoActual++;

    flotar(i);
}

void MaxHeap::flotar(int i) {

    while (i != 0 && esMayor(arreglo[i], arreglo[padre(i)])) {

        intercambiar(i, padre(i));
        i = padre(i);
    }
}

Cancion* MaxHeap::extraerMaximo() {

    if (tamanoActual <= 0){
        return nullptr;
    }

    if (tamanoActual == 1) {
        
        tamanoActual--;
        return arreglo[0];
    }

    // Guardamos al N°1 actual (la raíz)
    Cancion* maximo = arreglo[0];

    // Movemos el último nodo a la raíz y achicamos el árbol
    arreglo[0] = arreglo[tamanoActual - 1];
    tamanoActual--;

    hundir(0);

    return maximo;
}

void MaxHeap::hundir(int i) {

    int mayor = i;
    int izq = hijoIzquierdo(i);
    int der = hijoDerecho(i);

    // Si el hijo izquierdo es mayor que la raíz actual
    if (izq < tamanoActual && esMayor(arreglo[izq], arreglo[mayor])) {
        mayor = izq;
    }
    // Si el hijo derecho es el mayor de los tres
    if (der < tamanoActual && esMayor(arreglo[der], arreglo[mayor])) {
        mayor = der;
    }

    // Si el mayor no es la raíz, intercambiamos y seguimos hundiendo recursivamente
    if (mayor != i) {
        intercambiar(i, mayor);
        hundir(mayor);
    }
}

bool MaxHeap::estaVacio() {
    return tamanoActual == 0;
}

MaxHeap::~MaxHeap() {
    
    delete[] this->arreglo;
}