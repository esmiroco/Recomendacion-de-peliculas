#ifndef NODO_H
#define NODO_H

template<class Dato>
class Nodo {

private:
    //Atributos
    Dato dato;
    Nodo<Dato> *psig;

public:
    //Metodos
    /*
    constructor
    PRE: ---
    POST: Crea un nodo con el dato d y el puntero a NULL
    */
    Nodo(Dato d);

    /*
    metodo obtener_dato
    PRE: el nodo fue creado
    POST: devuelve el dato que contiene el nodo
    */
    Dato obtener_dato();

    /*
    metodo establecer_siguiente
    PRE: el nodo fue creado
    POST: el puntero al siguiente nodo apuntará a psig
    */
    void establecer_siguiente(Nodo *ps);

    /*
    metodo obtener_siguiente
    PRE: el nodo fue creado
    POST: Devuelve el puntero al siguiente nodo
    */
    Nodo<Dato> *obtener_siguiente();
};


template<class Dato>
Nodo<Dato>::Nodo(Dato d) {
    dato = d;
    psig = nullptr;
}

template<class Dato>
Dato Nodo<Dato>::obtener_dato() {
    return dato;
}

template<class Dato>
void Nodo<Dato>::establecer_siguiente(Nodo *ps) {
    psig = ps;
}

template<class Dato>
Nodo<Dato> *Nodo<Dato>::obtener_siguiente() {
    return psig;
}


#endif //NODO_H
