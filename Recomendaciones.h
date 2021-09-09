#ifndef RECOMENDACIONES_H
#define RECOMENDACIONES_H

using namespace std;

#include <string>
#include <fstream>
#include "Lista.h"
#include "Pelicula.h"

const int PUNTAJE_MINIMO = 7;

class Recomendaciones {

private:
    //Atributos
    Lista<Pelicula *> *lista_recomendadas;
    Lista<Pelicula *> *lista_vistas;
    Lista<Pelicula *> *lista_no_vistas;

    //Metodos
    //PRE: -
    //POS: Devuelve true si las peliculas comparadas cumplen con [hay coincidencia en el género y (en el director o uno de los actores)] o [puntaje >= 7]
    bool comparar_peliculas(Pelicula *pelicula_no_vista, Pelicula *pelicula_vista);

    //PRE: -
    //POS: Devuelve true si las peliculas comparadas pertenecen al mismo genero, caso contrario devuelve false
    bool coincidencia_genero(Pelicula *pelicula_no_vista, Pelicula *pelicula_vista);

    //PRE: -
    //POS: Devuelve true si las peliculas comparadas tienen el mismo director, caso contrario devuelve false
    bool coincidencia_director(Pelicula *pelicula_no_vista, Pelicula *pelicula_vista);

    //PRE: -
    //POS: Devuelve true si el puntaje de la peli_no_vista es >= a PUNTAJE_MINIMO
    bool puntaje_suficiente(Pelicula *pelicula_no_vista);

    //PRE: -
    //POST: Devuelve true si las peliculas comparadas tienen 1 actor en comun, caso contrario devuelve false
    bool coincidencia_actores(Pelicula *pelicula_no_vista, Pelicula *pelicula_vista);

    //PRE: -
    //POS: Lee el archivo y carga lista_peliculas o lanza una excepcion dependiendo del estado del archivo
    void cargar_datos(string nombre_archivo, Lista<Pelicula *> *lista_peliculas);

    //PRE: El archivo debe estar abierto correctamente
    //POS: Crea una lista con los actores y devuelve un puntero a ella
    Lista<string> *cargar_lista_actores(ifstream &archivo);

    //PRE: -
    //POST: Si las peliculas del atributo lista_no_vistas son >= a PUNTAJE_MINIMO las agrega a lista_recomendadas
    void cargar_recomendadas_segun_puntaje();

    //PRE: -
    //POST: Compara las peliculas del atributo lista_vistas con pelicula_no_vista y si esta cumple con los criterios devuelve true
    bool pelicula_es_recomendada(Pelicula *pelicula_no_vista);

    //PRE: -
    //POS: Lanza un expcecion por pantalla que la memoria fue liberada correctamente
    void verificar_memoria_liberada();

    //PRE: -
    //POST: Elimina los nodos de lista_aux y libera la memoria
    void borrar_lista(Lista<Pelicula *> *lista_aux);

public:
    //Metodos
    //PRE: -
    //POST: Asigna una lista vacía a cada atributo
    Recomendaciones();

    //PRE: -
    //POST: Carga los atributos lista_no_vistas y lista_vistas con los archivos que se le pasen por parametro.
    void cargar_datos(string nombre_archivo_vistas, string nombre_archivo_no_vistas);

    //PRE: -
    //POS: Si lista_vistas esta vacia carga las peliculas recomendadas segun puntaje, de lo contrario las carga comparando las peliculas de lista_no_vistas y lista_vistas
    void crear_lista_recomendadas();

    //PRE: -
    //POS: Devuelve un puntero al atributo lista_recomendadas
    Lista<Pelicula *> *obtener_lista_recomendadas();

    //PRE: -
    //POS: Devuelve un puntero al atributo lista_vistas
    Lista<Pelicula *> *obtener_lista_vistas();

    //PRE: -
    //POS: Devuelve un puntero al atributo lista_no_vistas
    Lista<Pelicula *> *obtener_lista_no_vistas();

    //PRE: -
    //POST: Elimina los atributos de la clase y libera la memoria
    ~Recomendaciones();
};

#endif //RECOMENDACIONES_H
