#ifndef LISTA_SECUENCIAL_H
#define LISTA_SECUENCIAL_H

#include "Estructuras.h"

class ListaSecuencial {
private:
    Torre arregloTorres[100]; // Arreglo estático manual 
    int cantidadActual;

public:
    ListaSecuencial();
    void insertarTorre(Torre nuevaTorre); 
    void eliminarTorre(int id);           
    Torre* buscarTorre(int id);           
    void mostrarTorres();                 
    int contarTorresActivas();            
    Torre* obtenerTorrePorIndice(int indice);
};

#endif