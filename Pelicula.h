  
#ifndef PELICULA_H
#define PELICULA_H

#include <string>
#include "Lista.h"

using namespace std;

class Pelicula {

private:
    //Atributos
    string nombre;
    string genero;
    string director;
    unsigned puntaje;
    Lista<string> *elenco;

public:
    //Metodos
    //PRE: -
    //POST: Crea un objeto de tipo Pelicula y le asigna los valores pasados por parametro a los atributos correspondientes
    Pelicula(string nombre, string genero, string director, unsigned puntaje, Lista<string> *elenco);

    //PRE: -
    //POST: Devuelve el genero de la pelicula
    string obtener_genero();

    //PRE: -
    //POST: Devuelve el nombre del director de la pelicula
    string obtener_director();

    //PRE: -
    //POST: Devuelve el puntaje de la pelicula
    unsigned obtener_puntaje();

    //PRE: -
    //POST: Devuelve un puntero al elenco de la pelicula
    Lista<string> *obtener_elenco();

    //PRE: -
    //POST: Devuelve la cantidad de actores de la pelicula
    unsigned cantidad_actores();

    //PRE: -
    //POST: Muestra por pantalla los atributos correspondientes a la pelicula
    void mostrar_pelicula();

    //PRE: -
    //POST: Elimina el objeto de tipo Pelicula. Libera la memoria que se usa para elenco, los demás atributos están en el stack
    ~Pelicula();
};

#endif //PELICULA_H
