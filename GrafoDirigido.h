#ifndef GRAFODIRIGIDO_H
#define GRAFODIRIGIDO_H

#include "Nodo.h"
#include "Arista.h"
#include <vector>
#include <map>
#include <functional>


class GrafoDirigido {
public:
    void agregarNodo(const Nodo& nodo);
    void agregarArista(const Arista& arista);
    void verGrafo() const;
    bool buscarCamino(Nodo& origen, const Nodo& destino, std::vector<Nodo>& camino, int totalPasajeros) const;
    void mostrarTodosLosCaminos(const Nodo& origen, const Nodo& destino) const;


private:
    std::vector<Nodo> nodos;
    std::vector<Arista> aristas;
    std::map<std::string, std::vector<const Arista*>> grafo;
    void dfsTodosCaminos(const Nodo& nodoActual, const Nodo& destino, std::vector<Nodo>& caminoActual) const;
    void dfsTodasLasParadas(const Nodo& nodoActual, const Nodo& destino, std::vector<Nodo>& caminoActual, int pasajerosAcumulados, int totalPasajeros) const;
};

#endif



/*

#ifndef GRAFODIRIGIDO_H
#define GRAFODIRIGIDO_H

#include "Nodo.h"
#include "Arista.h"
#include <vector>
#include <map>

class GrafoDirigido {
public:
    void agregarNodo(const Nodo& nodo);
    void agregarArista(const Arista& arista);
    void verGrafo() const;
    bool buscarCamino(const Nodo& origen, const Nodo& destino, std::vector<Nodo>& camino, double& pesoTotal) const;
    
private:
    std::vector<Nodo> nodos;
    std::vector<Arista> aristas;
    std::map<std::string, std::vector<const Arista*>> grafo;
};

#endif
//*/