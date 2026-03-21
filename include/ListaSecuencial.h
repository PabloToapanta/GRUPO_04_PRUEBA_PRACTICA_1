#ifndef LISTA_SECUENCIAL_H
#define LISTA_SECUENCIAL_H

#include "Estructuras.h"

class ListaSecuencial {
private:
    Torre arregloTorres[100]; // Arreglo estático manual [cite: 31, 75]
    int cantidadActual;

public:
    ListaSecuencial();
    void insertarTorre(Torre nuevaTorre); // [cite: 33]
    void eliminarTorre(int id);           // [cite: 34]
    Torre* buscarTorre(int id);           // [cite: 35]
    void mostrarTorres();                 // [cite: 36]
    int contarTorresActivas();            // [cite: 37]
    Torre* obtenerTorrePorIndice(int indice);
};

#endif