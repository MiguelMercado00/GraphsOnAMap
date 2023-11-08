#include "Arista.h"
#include <iostream>

Arista::Arista(const Nodo& nodoOrigen, const Nodo& nodoDestino, double peso)
    : nodoOrigen(nodoOrigen), nodoDestino(nodoDestino), peso(peso) {}

const Nodo& Arista::getNodoOrigen() const {
    return nodoOrigen;
}

const Nodo Arista::getNodoDestino() const {
    return nodoDestino;
}

double Arista::getPeso() const {
    return peso;
}

void Arista::verArista() const {
    /*
    std::cout << "Nodo Origen: ";
    nodoOrigen.verNodo();
    std::cout << "Nodo Destino: ";
    nodoDestino.verNodo();
    std::cout << "Peso: " << peso << std::endl;
    */

    std::cout <<nodoOrigen.getId() << " --(" << peso <<" Km.)--> " << nodoDestino.getId() << std::endl;
}
