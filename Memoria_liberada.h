#ifndef MEMORIA_LIBERADA_H_
#define MEMORIA_LIBERADA_H_

#include <exception>

using namespace std;

class Memoria_liberada : public exception {

public:
    virtual const char *what() const throw() {
        return "La memoria ha sido liberada por completo";
    }

} memoria_liberada;


#endif //MEMORIA_LIBERADA_H
