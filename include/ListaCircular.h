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
    void registrarOleada(Oleada nuevaOleada); // [cite: 49]
    void mostrarOleadas();                    // [cite: 50]
    Oleada* avanzarSiguienteOleada();         // [cite: 51]
    void reiniciarCiclo();                    // [cite: 52]
};

#endif