#ifndef LISTA_CIRCULAR_H
#define LISTA_CIRCULAR_H

#include "Estructuras.h"

struct NodoOleada {
    Oleada dato;
    NodoOleada* siguiente;
};

class ListaCircular {
private:
    NodoOleada* ultimo; 
    NodoOleada* oleadaActual;

public:
    ListaCircular();
    ~ListaCircular(); // CORRECCIÓN: Destructor añadido para evitar fugas de memoria
    
    void registrarOleada(Oleada nuevaOleada);
    void mostrarOleadas();
    Oleada* avanzarSiguienteOleada();
    void reiniciarCiclo();
};

#endif