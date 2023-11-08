#include "GrafoDirigido.h"
#include <algorithm>
#include <iostream>

void GrafoDirigido::agregarNodo(const Nodo& nodo) {
    nodos.push_back(nodo);
}


void GrafoDirigido::agregarArista(const Arista& arista) {
    aristas.push_back(arista);
    grafo[arista.getNodoOrigen().getId()].push_back(&arista);
}

void GrafoDirigido::verGrafo() const {
    for (const Nodo& nodo : nodos) {
        nodo.verNodo();
        std::cout << "Aristas salientes:" << std::endl;
        if (grafo.find(nodo.getId()) != grafo.end()) {
            for (const Arista* arista : grafo.at(nodo.getId())) {
                arista->verArista();
            }
        } else {
            std::cout << "No hay aristas salientes para este nodo." << std::endl;
        }
        std::cout << "-----------------------" << std::endl;
    }
}



bool GrafoDirigido::buscarCamino(Nodo& origen, const Nodo& destino, std::vector<Nodo>& camino, int totalPasajeros) const {
    std::cout << "Las opciones para una ruta de buses desde " << origen.getNombre() << " hasta " << destino.getNombre() << ", incluyendo las rutas que recorren primero a las \nciudades con menos pasajeros y a las rutas que no recorren primero a las ciudades que tienen menos pasajeros (ADICIONAL).\n";
    std::cout << "-----------------------\n";
    std::vector<Nodo> caminoActual;
    caminoActual.push_back(origen);
    dfsTodasLasParadas(origen, destino, caminoActual, 0, totalPasajeros);

    return false;
}

void GrafoDirigido::mostrarTodosLosCaminos(const Nodo& origen, const Nodo& destino) const {
    std::cout << "Todos los caminos desde " << origen.getNombre() << " hasta " << destino.getNombre() << ":\n";
    std::vector<Nodo> caminoActual;
    caminoActual.push_back(origen);
    dfsTodosCaminos(origen, destino, caminoActual);

}

void GrafoDirigido::dfsTodosCaminos(const Nodo& nodoActual, const Nodo& destino, std::vector<Nodo>& caminoActual) const {
    if (nodoActual.getId() == destino.getId()) {
        // Se ha encontrado un camino hasta el destino.
        double pesoTotal = 0; // Variable para almacenar el total de pesos del camino
        for (size_t i = 0; i < caminoActual.size() - 1; i++) {
            std::string origenId = caminoActual[i].getId();
            std::string destinoId = caminoActual[i + 1].getId();
            for (const Arista& arista : aristas) {
                if (arista.getNodoOrigen().getId() == origenId && arista.getNodoDestino().getId() == destinoId) {
                    pesoTotal += arista.getPeso(); // Sumar el peso de la arista al total
                    break;
                }
            }
        }
        for (size_t i = 0; i < caminoActual.size() - 1; i++) {
            std::string origenId = caminoActual[i].getId();
            std::string destinoId = caminoActual[i + 1].getId();
            for (const Arista& arista : aristas) {
                if (arista.getNodoOrigen().getId() == origenId && arista.getNodoDestino().getId() == destinoId) {
                    std::cout << "Arista: " << origenId << " -> " << destinoId << " (Peso: " << arista.getPeso() << ")\n";
                    break;
                }
            }
        }
        std::cout << "Total de pesos del camino: " << pesoTotal << std::endl;
        std::cout << "-----------------------\n";
    } else {
        for (const Arista& arista : aristas) {
            if (arista.getNodoOrigen().getId() == nodoActual.getId()) {
                if (std::find(caminoActual.begin(), caminoActual.end(), arista.getNodoDestino()) == caminoActual.end()) {
                    caminoActual.push_back(arista.getNodoDestino());
                    dfsTodosCaminos(arista.getNodoDestino(), destino, caminoActual);
                    caminoActual.pop_back();
                }
            }
        }
    }
}

void GrafoDirigido::dfsTodasLasParadas(const Nodo& nodoActual, const Nodo& destino, std::vector<Nodo>& caminoActual, int pasajerosAcumulados, int totalPasajeros) const {
    if (nodoActual.getId() == destino.getId()) {
        // Se ha encontrado un camino hasta el destino.
        double pesoTotal = 0; // Variable para almacenar el total de pesos del camino
        int pasajerosTotal = 0; // Variable para almacenar el total de pasajeros del camino
        std::vector<bool> ciudadesVisitadas(nodos.size(), false); // Vector para hacer un seguimiento de las ciudades visitadas
        int ordenDeMenorAMayor = 0; // Variable para almacenar el orden de menor a mayor



        //Aquí compara el número de pasajeros que hay en Toledo y en Segovia, y el que tenga menos pasajeros de recorre primero
        if (nodoActual.getId() == "Madrid") {
            for (size_t i = 0; i < caminoActual.size() - 1; i++) {
                std::string origenId = caminoActual[i].getId();
                std::string destinoId = caminoActual[i + 1].getId();
                for (const Arista& arista : aristas) {
                    if (arista.getNodoOrigen().getId() == origenId && arista.getNodoDestino().getId() == destinoId) {
                        if (arista.getNodoDestino().getId() == "Toledo" || arista.getNodoDestino().getId() == "Segovia") {
                            if (arista.getNodoDestino().getNumPasajeros() < arista.getNodoOrigen().getNumPasajeros() || arista.getNodoDestino().getNumPasajeros() == arista.getNodoOrigen().getNumPasajeros()) {
                                std::swap(caminoActual[i], caminoActual[i + 1]);
                            }
                        }
                        break;
                    }
                }
            }
        }

        for (size_t i = 0; i < caminoActual.size() - 1; i++) {
            std::string origenId = caminoActual[i].getId();
            std::string destinoId = caminoActual[i + 1].getId();
            for (const Arista& arista : aristas) {
                if (arista.getNodoOrigen().getId() == origenId && arista.getNodoDestino().getId() == destinoId) {
                    pesoTotal += arista.getPeso(); // Sumar el peso de la arista al total
                    if (pasajerosTotal < 15) {
                        pasajerosTotal += arista.getNodoDestino().getNumPasajeros(); // Sumar los pasajeros de la arista al total
                    } else {
                        pasajerosTotal = 15; // Si se recogieron más de 15 pasajeros, se establece el total a 15
                    }
                    break;
                }
            }
        }
        // Se comprueba si se recogieron más de 15 pasajeros
        if (pasajerosTotal < 15) {
            pasajerosTotal += caminoActual.front().getNumPasajeros(); // Sumar los pasajeros del nodo origen al total
        } else {
            pasajerosTotal = 15; // Si se recogieron más de 15 pasajeros, se establece el total a 15
        }

        // Aquí se calcula si el último nodo hizo que se recogieran más de 15 pasajeros, y si es así, le resta el exedente
        if (pasajerosTotal > 15) {
            int pasajerosExedentes = pasajerosTotal - 15;
            std::cout << "No se recogieron " << pasajerosExedentes << " pasajeros en " << caminoActual[caminoActual.size() - 2].getNombre() << std::endl;
            pasajerosTotal -= pasajerosExedentes;
            pesoTotal -= pasajerosExedentes * 0.5;
        }

        // Se calcula los pasajeros faltantes restando los pasajeros totales con los pasajeros recogidos
        int pasajerosFaltantes = totalPasajeros - pasajerosTotal;
        for (const Nodo& nodo : caminoActual) {
            ciudadesVisitadas[std::distance(nodos.begin(), std::find(nodos.begin(), nodos.end(), nodo))] = true;
        }

        // Se dicen las ciudades en las que no se recogieron pasajeros y cuantos pasajeros no se recogieron en cada una
        for (size_t i = 0; i < ciudadesVisitadas.size(); i++) {
            if (!ciudadesVisitadas[i]) {
                int pasajerosNoRecogidos = nodos[i].getNumPasajeros();
                std::cout << "No se recogieron "<< pasajerosNoRecogidos << " pasajeros en " << nodos[i].getNombre() << std::endl;
            }
        }

        for (size_t i = 0; i < caminoActual.size() - 1; i++) {
            std::string origenId = caminoActual[i].getId();
            std::string destinoId = caminoActual[i + 1].getId();
            for (const Arista& arista : aristas) {
                if (arista.getNodoOrigen().getId() == origenId && arista.getNodoDestino().getId() == destinoId) {
                    std::cout << "Arista: " << origenId << " -> " << destinoId << " (Peso: " << arista.getPeso() << ")\n";
                    break;
                }
            }
        }



        std::cout << "Total de pesos del camino: " << pesoTotal << std::endl;
        std::cout << "Total de pasajeros recogidos: " << pasajerosTotal << std::endl;
        std::cout << "Pasajeros faltantes: " << pasajerosFaltantes << std::endl;
        std::cout << "-----------------------\n";


        // Aquí es donde se almacenan el pesoTotal de cada camino en el vector pesos






    } else {
        for (const Arista& arista : aristas) {
            if (arista.getNodoOrigen().getId() == nodoActual.getId()) {
                if (std::find(caminoActual.begin(), caminoActual.end(), arista.getNodoDestino()) == caminoActual.end()) {
                    int pasajerosEnArista = arista.getNodoDestino().getNumPasajeros();
                    if (pasajerosAcumulados + pasajerosEnArista <= 15) {
                        caminoActual.push_back(arista.getNodoDestino());
                        int nuevoPasajerosAcumulados = pasajerosAcumulados + pasajerosEnArista;
                        dfsTodasLasParadas(arista.getNodoDestino(), destino, caminoActual, nuevoPasajerosAcumulados, totalPasajeros);
                        caminoActual.pop_back();
                    } else if (arista.getNodoDestino().getId() == "Guadalajara") {
                        caminoActual.push_back(arista.getNodoDestino());
                        dfsTodasLasParadas(arista.getNodoDestino(), destino, caminoActual, pasajerosAcumulados, totalPasajeros);
                        caminoActual.pop_back();
                    }
                }
            }
        }
    }
}



