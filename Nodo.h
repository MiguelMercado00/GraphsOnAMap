#ifndef NODO_H
#define NODO_H

#include <string>

class Nodo {
public:
    Nodo(const std::string& id, const std::string& nombre, double latitud, double longitud, int numPasajeros);

    Nodo(std::string basicString, int i);

    std::string getId() const;
    std::string getNombre() const;
    
    double getLatitud() const;
    double getLongitud() const;
    int getNumPasajeros() const;
    void verNodo() const;
    bool operator==(const Nodo& other) const; 

private:
    std::string id;
    std::string nombre;
    double latitud;
    double longitud;
    int numPasajeros;
};

#endif
