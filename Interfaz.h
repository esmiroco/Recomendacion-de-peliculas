
#ifndef INTERFAZ_H
#define INTERFAZ_H

#include "Recomendaciones.h"
#include "Lista.h"
#include "Pelicula.h"

class Interfaz {

private:
    Lista<Pelicula *> *lista_vistas;
    Lista<Pelicula *> *lista_no_vistas;
    Lista<Pelicula *> *lista_recomendadas;
    unsigned opcion;

public:
    //Constructor
    Interfaz(Recomendaciones recomendaciones);
    //PRE: Ninguna
    //POS: Muestra las acciones posibles por pantalla y redirige la accion segun la opcion ingresada
    void ejecutar_interfaz();

    //PRE: Objeto interfaz creado
    //POS: Muestra por pantalla las acciones posibles
    void mostrar_opciones();

    //PRE: Objeto interfaz creado
    //POS: Solicita por pantalla el ingreso de una opcion
    void solicitar_opcion();

    //PRE:  0 < opcion >= 3
    //POS: Segun el valor del atributo opcion realiza la accion correspondiente
    void redireccionar_opcion();

    //PRE: Ejecucion del metodo redireccionar_opcion
    //POS: Muestra por pantalla la lista de peliculas vistas
    void mostrar_peliculas_vistas();

    //PRE: Ejecucion del metodo redireccionar_opcion
    //POS: Muestra por pantalla la lista de peliculas no vistas
    void mostrar_peliculas_no_vistas();

    //PRE: Ejecucion del metodo redireccionar_opcion
    //POS: Muestra por pantalla la lista de peliculas recomendadas
    void mostrar_peliculas_recomendadas();

    //PRE: lista peliculas creada
    //POS: Borrar los elementos de una lista pertenecientes al puntero a lista pasado por parametro
    void borrar_lista(Lista<Pelicula *> *lista_aux);

    //Destructor
    ~Interfaz();

};

#endif //INTERFAZ_H
