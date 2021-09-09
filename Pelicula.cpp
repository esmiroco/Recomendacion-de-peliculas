#include <iostream>
#include "Pelicula.h"

Pelicula::Pelicula(string nombre, string genero, string director, unsigned puntaje, Lista<string> *elenco) {
    this->nombre = nombre;
    this->genero = genero;
    this->director = director;
    this->puntaje = puntaje;
    this->elenco = elenco;
}

string Pelicula::obtener_genero() {
    return genero;
}

string Pelicula::obtener_director() {
    return director;
}

unsigned Pelicula::obtener_puntaje() {
    return puntaje;
}

Lista<string> *Pelicula::obtener_elenco() {
    return elenco;
}

unsigned Pelicula::cantidad_actores() {
    return elenco->obtener_tamanio();
}

void Pelicula::mostrar_pelicula() {
    cout << "Pelicula: " << nombre << endl;
    cout << "Genero: " << genero << endl;
    cout << "Director/a: " << director << endl;
    cout << "Puntaje: " << puntaje << endl;
    cout << "Elenco: ";

    for (unsigned i = 1; i <= elenco->obtener_tamanio(); i++) {
        cout << elenco->obtener_dato(i) << " ";
    }

    cout << "\n-------------------------------------------------------------\n";
}

Pelicula::~Pelicula() {
    
    delete elenco;

}
© 2020 GitHub, Inc.
Terms
Privacy
Security
Status
Help
Contact GitHub
Pricing
API
Training
Blog
About

