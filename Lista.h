#ifndef LISTA_H
#define LISTA_H

#include "Nodo.h"

template<class Dato>
class Lista {

private:
    //Atributos
    Nodo<Dato> *primero;
    unsigned tamanio;

    //Metodos
    // PRE: 0 < pos <= tam
    // POST: devuelve un puntero al nodo
    Nodo<Dato> *obtener_nodo(unsigned pos);

public:
    //Metodos
    /*
    constructor
    PRE: ---
    POST: construye una lista vacia
    */
    Lista();

    /*
    metodo lista_vacia
    PRE: la lista fue creada
    POST: indica si la lista tiene elementos dentro o no
    */
    bool lista_vacia();

    /*
    metodo obtener_tamanio
    PRE: la lista fue creada
    POST: devuelve el tamanio de la lista
    */
    unsigned obtener_tamanio();

    /*
    metodo alta
    PRE: la lista fue creada
    POST: agrega un dato a la lista e incrementa en una unidad el tamanio
    */
    void alta(Dato f);

    /*
    metodo baja
    PRE: la lista fue creada
    POST: libera el nodo que esta en la posición pos
    */
    void baja(unsigned pos);

    /*
    metodo obtener_dato
    PRE: la lista fue creada
    POST: devuelve un puntero al dato de la posicion pos
    */
    Dato obtener_dato(unsigned pos);

    /*
    destructor
    PRE: la lista fue creada
    POST: elimina la lista
    */
    ~Lista();
};


template<class Dato>
Lista<Dato>::Lista() {
    primero = nullptr;
    tamanio = 0;
}

template<class Dato>
void Lista<Dato>::alta(Dato f) {
    Nodo<Dato> *pnodo = new Nodo<Dato>(f);

    if (this->lista_vacia()) {
        primero = pnodo;
    } else {
        Nodo<Dato> *paux = obtener_nodo(tamanio);
        pnodo->establecer_siguiente(paux->obtener_siguiente());
        paux->establecer_siguiente(pnodo);
    }
    tamanio++;
}

template<class Dato>
Dato Lista<Dato>::obtener_dato(unsigned pos) {
    return obtener_nodo(pos)->obtener_dato();
}

template<class Dato>
void Lista<Dato>::baja(unsigned pos) {
    Nodo<Dato> *paux = primero;
    if (pos == 1) {
        primero = paux->obtener_siguiente();
    } else {
        Nodo<Dato> *pant = obtener_nodo(pos - 1);
        paux = pant->obtener_siguiente();
        pant->establecer_siguiente(paux->obtener_siguiente());
    }
    delete paux;
    tamanio--;
}

template<class Dato>
unsigned Lista<Dato>::obtener_tamanio() {
    return tamanio;
}

template<class Dato>
Nodo<Dato> *Lista<Dato>::obtener_nodo(unsigned pos) {
    Nodo<Dato> *aux = primero;
    unsigned i = 1;
    while (i < pos) {
        aux = aux->obtener_siguiente();
        i++;
    }
    return aux;
}

template<class Dato>
bool Lista<Dato>::lista_vacia() {
    return (primero == nullptr);
}

template<class Dato>
Lista<Dato>::~Lista() {
    while (!(lista_vacia())) {
        baja(1);
    }
}

#endif //LISTA_H
