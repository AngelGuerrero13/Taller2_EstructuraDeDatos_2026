#include "ArbolAVL.hpp"


ArbolAVL::ArbolAVL() { 
    raiz = nullptr; 
}

ArbolAVL::~ArbolAVL() {
    limpiarMemoria(raiz);
}

void ArbolAVL::limpiarMemoria(NodoAVL* nodo) {

    if (nodo != nullptr) {

        limpiarMemoria(nodo->getIzquierdo());
        limpiarMemoria(nodo->getDerecho());
        delete nodo;
    }
}

int ArbolAVL::altura(NodoAVL* N) {
    if (N == nullptr){

        return 0;
    }

    return N->getAltura();
}

int ArbolAVL::max(int a, int b) {

    if (a > b) {
        return a;
    } else {
        return b;
    }

}

NodoAVL* ArbolAVL::rotacionDerecha(NodoAVL* y) {

    NodoAVL* x = y->getIzquierdo();
    NodoAVL* T2 = x->getDerecho();

    //Rotación
    x->setDerecho(y);
    y->setIzquierdo(T2);

    //Actualizar alturas
    y->setAltura(max(altura(y->getIzquierdo()), altura(y->getDerecho())) + 1);
    x->setAltura(max(altura(x->getIzquierdo()), altura(x->getDerecho())) + 1);

    return x;
}

NodoAVL* ArbolAVL::rotacionIzquierda(NodoAVL* x) {

    NodoAVL* y = x->getDerecho();
    NodoAVL* T2 = y->getIzquierdo();

    // Rotación
    y->setIzquierdo(x);
    x->setDerecho(T2);

    //Actualizar alturas
    x->setAltura(max(altura(x->getIzquierdo()), altura(x->getDerecho())) + 1);
    y->setAltura(max(altura(y->getIzquierdo()), altura(y->getDerecho())) + 1);

    return y;
}

int ArbolAVL::obtenerBalance(NodoAVL* N) {

    if (N == nullptr){
        return 0;
    }

    return altura(N->getIzquierdo()) - altura(N->getDerecho());
}

void ArbolAVL::insertarCancion(Cancion* cancion) {
    raiz = insertar(raiz, cancion);
}

NodoAVL* ArbolAVL::insertar(NodoAVL* nodo, Cancion* cancion) {
    // Inserción
    if (nodo == nullptr){

        return new NodoAVL(cancion);
    }

    if (cancion->getNombreCancion() < nodo->getCancion()->getNombreCancion()){

        nodo->setIzquierdo(insertar(nodo->getIzquierdo(), cancion));

    }else if (cancion->getNombreCancion() > nodo->getCancion()->getNombreCancion()){

        nodo->setDerecho(insertar(nodo->getDerecho(), cancion));

    }else{
        return nodo;
    }

    //Actualizar altura
    nodo->setAltura(1 + max(altura(nodo->getIzquierdo()), altura(nodo->getDerecho())));

    //Balancear
    int balance = obtenerBalance(nodo);

    // Rotaciones
    if (balance > 1 && cancion->getNombreCancion() < nodo->getIzquierdo()->getCancion()->getNombreCancion()){

        return rotacionDerecha(nodo);
    }

    if (balance < -1 && cancion->getNombreCancion() > nodo->getDerecho()->getCancion()->getNombreCancion()){

        return rotacionIzquierda(nodo);
    }

    if (balance > 1 && cancion->getNombreCancion() > nodo->getIzquierdo()->getCancion()->getNombreCancion()) {
        nodo->setIzquierdo(rotacionIzquierda(nodo->getIzquierdo()));
        return rotacionDerecha(nodo);
    }
    
    if (balance < -1 && cancion->getNombreCancion() < nodo->getDerecho()->getCancion()->getNombreCancion()) {
        nodo->setDerecho(rotacionDerecha(nodo->getDerecho()));
        return rotacionIzquierda(nodo);
    }

    return nodo;
}

void ArbolAVL::inOrden(NodoAVL* nodo, ListaCancion* resultados) {

    if (nodo != nullptr) {

        inOrden(nodo->getIzquierdo(), resultados);
        resultados->insertarFinal(nodo->getCancion());
        inOrden(nodo->getDerecho(), resultados);
    }
}

ListaCancion* ArbolAVL::obtenerCancionesOrdenadas() {
    ListaCancion* resultados = new ListaCancion();
    inOrden(raiz, resultados);
    return resultados;
}