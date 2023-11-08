#include "Nodo.h"
#include <iostream>

Nodo::Nodo(const std::string& id, const std::string& nombre, double latitud, double longitud, int numPasajeros)
    : id(id), nombre(nombre), latitud(latitud), longitud(longitud), numPasajeros(numPasajeros) {}


std::string Nodo::getId() const {
    return id;
}

bool Nodo::operator==(const Nodo& other) const {
    return id == other.id;
}

std::string Nodo::getNombre() const {
    return nombre;
}

double Nodo::getLatitud() const {
    return latitud;
}

double Nodo::getLongitud() const {
    return longitud;
}

int Nodo::getNumPasajeros() const {
    return numPasajeros;
}

void Nodo::verNodo() const {
    std::cout << "(" << id << ") --> " << nombre << ", {Lat: " << latitud << ", Lon: " << longitud << "}" <<std::endl;
}

Nodo::Nodo(std::string basicString, int i) {

}

