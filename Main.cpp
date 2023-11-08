
#include <iostream>
#include "Nodo.h"
#include "Arista.h"
#include "GrafoDirigido.h"
#include <ctime>
#include <cstdlib>
#include <vector>


int main() {

    std::srand(std::time(nullptr));

    int minPasajeros = 5;
    int maxPasajeros = 10;


    Nodo nodoA("Madrid", "Madrid", 40.4, -3.7, minPasajeros + std::rand() % (maxPasajeros - minPasajeros + 1));
    Nodo nodoB("Toledo", "Toledo", 39.8, -4.0, minPasajeros + std::rand() % (maxPasajeros - minPasajeros + 1));
    Nodo nodoC("Segovia", "Segovia", 40.9, -4.1, minPasajeros + std::rand() % (maxPasajeros - minPasajeros + 1));
    Nodo nodoD("Ávila", "Ávila", 40.6, -4.7, minPasajeros + std::rand() % (maxPasajeros - minPasajeros + 1));
    Nodo nodoE("Guadalajara", "Guadalajara", 40.6, -3.1, 0);

    Arista aristaAB(nodoA, nodoB, 72.5);
    Arista aristaAC(nodoA, nodoC, 91.6);
    Arista aristaBC(nodoB, nodoC, 159.0);
    Arista aristaCD(nodoC, nodoD, 64.3);
    Arista aristaCE(nodoC, nodoE, 153.0);
    Arista aristaDE(nodoD, nodoE, 171.0);
    Arista aristaAE(nodoA, nodoE, 66.6);

    GrafoDirigido grafo;
    grafo.agregarNodo(nodoA);
    grafo.agregarNodo(nodoB);
    grafo.agregarNodo(nodoC);
    grafo.agregarNodo(nodoD);
    grafo.agregarNodo(nodoE);

    grafo.agregarArista(aristaAB);
    grafo.agregarArista(aristaAC);
    grafo.agregarArista(aristaBC);
    grafo.agregarArista(aristaCD);
    grafo.agregarArista(aristaCE);
    grafo.agregarArista(aristaDE);
    grafo.agregarArista(aristaAE);

    std::cout << "Punto 1: " << std::endl;
    std::cout << "" << std::endl;
    grafo.verGrafo();

    Nodo origen = nodoA;
    Nodo destino = nodoE;

    grafo.mostrarTodosLosCaminos(origen, destino);

    std::cout << "Punto 2: " << std::endl;
    std::cout << "" << std::endl;

    Arista aristaDB(nodoD, nodoB, 133.0);
    Arista aristaDA(nodoD, nodoA, 102.0);
    grafo.agregarArista(aristaDB);
    grafo.agregarArista(aristaDA);

    //Mostrar todos los pasajeros de cada nodo
    std::cout << "Pasajeros en cada ciudad(Nodo): " << std::endl;

    std::cout << "Madrid: " << nodoA.getNumPasajeros() << std::endl;
    std::cout << "Toledo: " << nodoB.getNumPasajeros() << std::endl;
    std::cout << "Segovia: " << nodoC.getNumPasajeros() << std::endl;
    std::cout << "Avila: " << nodoD.getNumPasajeros() << std::endl;
    std::cout << "Guadalajara no se recogen pasajeros: " << nodoE.getNumPasajeros() << std::endl;
    //Se almacena el total de pasajeros
    int totalPasajeros = nodoA.getNumPasajeros() + nodoB.getNumPasajeros() + nodoC.getNumPasajeros() + nodoD.getNumPasajeros() + nodoE.getNumPasajeros();
    //Se imprimen el total de pasajeros
    std::cout << "Total de pasajeros: " << totalPasajeros << std::endl;
    std::cout << "" << std::endl;
    std::vector<Nodo> nodos;

    //Mostrar todos los caminos desde Madrid hasta Guadalajara
    grafo.buscarCamino(origen, destino, nodos, totalPasajeros);

    return 0;
    }








