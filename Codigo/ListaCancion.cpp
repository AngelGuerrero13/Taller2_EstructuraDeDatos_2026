#include "ListaCancion.hpp"

ListaCancion::ListaCancion(){
    cabeza = nullptr;
    cola = nullptr;
    total = 0;
}

//Getters
NodoCancion* ListaCancion::getCabeza(){
    return this->cabeza;
}

NodoCancion* ListaCancion::getCola(){
    return this->cola;
}

int ListaCancion::getTotal(){
    return this->total;
}

//Setters
void ListaCancion::setCabeza(NodoCancion* cabeza){
    this->cabeza = cabeza;
}
void ListaCancion::setCola(NodoCancion* cola){
    this->cola = cola;
}
void ListaCancion::setTotal(int total){
    this->total = total;
}
void ListaCancion::insertarInicio(Cancion* cancion){
    //Se crea nuevo nodoCancion con la cancion dada por parametro
    NodoCancion* cancionNueva = new NodoCancion(cancion);

    //Si no hay ninguna cancion en la lista, cancionNueva es la primera en ser insertada
    if(cabeza==nullptr){
        cabeza = cancionNueva;
        cola = cancionNueva;
        //Aseguramos que sea la primera cancion
        cancionNueva->setSiguiente(nullptr);
        cancionNueva->setAnterior(nullptr);
    
    //En caso contrario ya hay canciones en la lista y cancionNueva es la anteriro a cabeza(primera cancion), y cabeza ahora es la cancion nueva
    }else{
        //El anterior de la cabeza es la nueva cancion
        cabeza->setAnterior(cancionNueva);
        //El siguiente a nuestra nueva cancion es nuestra antigua cabeza
        cancionNueva->setSiguiente(cabeza);
        //Se actualiza la cabeza
        cabeza = cancionNueva;
        //el anterior a nuestra nueva cabeza debe ser nullptr porque es la primera
        cabeza->setAnterior(nullptr);
    }
    total++;
}

void ListaCancion::insertarFinal(Cancion* cancion){
    //Se crea nuevo nodoCancion con la cancion dada por parametro
    NodoCancion* cancionNueva = new NodoCancion(cancion);

    //Si no hay ninguna cancion en la lista, cancionNueva es la primera en ser insertada
    if(cabeza==nullptr){
        cabeza = cancionNueva;
        cola = cancionNueva;

        //Aseguramos que sea la primera cancion
        cancionNueva->setSiguiente(nullptr);
        cancionNueva->setAnterior(nullptr);
    
    //En caso contrario ya hay canciones en la lista y cancionNueva es la siguiente a la cola(ultima cancion), y cola ahora es la cancion nueva
    }else{
        //El siguiente de la cola actual es la nueva cancion
        cola->setSiguiente(cancionNueva);
        //El anterior de nuestra nueva cancion es la cola antigua
        cancionNueva->setAnterior(cola);
        //Actualizamos la cola
        cola = cancionNueva;
        //El siguiente de nuestra nueva cola es nullptr porque es el ultimo nodo
        cola->setSiguiente(nullptr);
    }
    total++;
}

void ListaCancion::verLista(){

    NodoCancion* actual = cabeza;
    int numero = 1;

    if(cabeza==nullptr){
        cout<<"Lista vacia"<<endl;
        return;
    }

    while(actual!=nullptr){
        //Imprimimos la cancion
        cout<<numero<<". "<<actual->getCancion()->getNombreCancion()<<" - "<<actual->getCancion()->getArtista()<<endl;
        //Avanzamos al siguiente
        actual=actual->getSiguiente();
        //aumentamos el indice
        numero++;
    }

}

NodoCancion* ListaCancion::seleccionarNodo(int posicion){
    //Verificar que esta dentro de los parametros, como la lista comienza en 1 y no puede ser mayor al total de canciones de la lista, esto son los limites
    if(posicion < 1 || posicion > this->total){
        return nullptr;
    }

    NodoCancion* aux;

    //Si la posicion es menor a la mitad del total de canciones, recorremos de arriba hacia abajo
    if(posicion <= this->total/2){
        //Vamos desde la cabeza hasta la posicion indicada
        aux = this->cabeza;
        //Avanzamos hasta llegar al nodo de la posicion
        for(int i = 1;i < posicion; i++){
            aux = aux->getSiguiente();
        }
    //Si la posicion es mayor a la mitad del total de canciones, recorremos de abajo hacia arriba
    }else{
        //Vamos desde la cola hasta la posicion indicada
        aux = this->cola;
        //Avanzamos hasta llegas al nodo de la posicion
        for(int i = this->total; i > posicion; i--){
            aux = aux->getAnterior();
        }
    }

    return aux;
}

void ListaCancion::eliminarNodo(int posicion){
    NodoCancion* cancionEliminar = seleccionarNodo(posicion);

    if(cancionEliminar == nullptr){
        return;
    }

    //Si la cancion a eliminar es la cabeza, se cambia la cabeza
    if(cancionEliminar == this->cabeza){
        //Ahora la cabeza es la cancion siguiente en la lista
        this->cabeza = cancionEliminar->getSiguiente();

        //Si la cabeza es diferente de nulo, se debe cambiar el anterior al que apunta para desvincular la cabeza anterior
        if(this->cabeza != nullptr){
            this->cabeza->setAnterior(nullptr);
        }
    //Si es la cola hay que hacer el mismo proceso
    }else if(cancionEliminar == this->cola){
        //Ahora la cola es la cancion anterior en la lista
        this->cola = cancionEliminar->getAnterior();

        //Si la cola es diferente de nulo, se debe cambiar el siguiente al que apunta para desvincular la cola anterior
        if(this->cola != nullptr){
            this->cola->setSiguiente(nullptr);
        }
    //Si no es ninguna de las anterirores, se encuentra en medio de la lista
    }else{
        //El siguiente de la cancion anterior es el siguiente de mi cancion a eliminar
        cancionEliminar->getAnterior()->setSiguiente(cancionEliminar->getSiguiente());
        //El anterior de la cancion siguiente es el anterior de mi cancion a eliminar
        cancionEliminar->getSiguiente()->setAnterior(cancionEliminar->getAnterior());
    }

    delete cancionEliminar->getCancion();
    delete cancionEliminar;
    this->total--;
}

void ListaCancion::vaciarLista(){
    //variable NodoCancion que apunta a cabeza para moverse en la lista
    NodoCancion* actual = cabeza;

    while(actual!=nullptr){
        //Puntero para no perder el enlace hasta borrar toda la lista
        NodoCancion* siguiente = actual ->getSiguiente();
        //Se borra el nodo de la lista
        delete actual;
        //avanzamos al siguiente
        actual = siguiente;
    }

    this->cabeza = nullptr;
    this->cola = nullptr;
    this->total = 0;
}

Cancion* ListaCancion::buscarCancionId(string idBuscado){
    
    NodoCancion* aux = this->cabeza;
    
    while (aux != nullptr) {
        // Comparamos el ID de la canción del nodo actual con el buscado
        if (aux->getCancion()->getId() == idBuscado) {
            return aux->getCancion();
        }
        aux = aux->getSiguiente();
    }
    
    return nullptr; 
}

ListaCancion::~ListaCancion(){
   vaciarLista(); 
}