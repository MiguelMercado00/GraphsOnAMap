#ifndef ARISTA_H
#define ARISTA_H

#include "Nodo.h"

class Arista {
public:
    Arista(const Nodo& nodoOrigen, const Nodo& nodoDestino, double peso);
    
    const Nodo& getNodoOrigen() const;
    const Nodo getNodoDestino() const;
    double getPeso() const;
    
    void verArista() const;

private:
    const Nodo& nodoOrigen;
    const Nodo& nodoDestino;
    double peso;
};

#endif
