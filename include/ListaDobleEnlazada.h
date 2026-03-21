#ifndef LISTA_DOBLE_ENLAZADA_H
#define LISTA_DOBLE_ENLAZADA_H

#include "Estructuras.h"

struct NodoEnemigo {
    Enemigo dato;
    NodoEnemigo* siguiente;
    NodoEnemigo* anterior;
};

class ListaDobleEnlazada {
private:
    NodoEnemigo* primero; // [cite: 38]
    NodoEnemigo* ultimo;  // [cite: 38]

public:
    ListaDobleEnlazada(); //Destructor
    ~ListaDobleEnlazada();
    void insertarFinal(Enemigo nuevoEnemigo); // [cite: 41]
    void eliminarDestruido(int id);           // [cite: 42]
    NodoEnemigo* buscarEnemigo(int id);       // [cite: 43]
    void recorrerAdelante();                  // [cite: 44]
    void recorrerAtras();                     // [cite: 45]
    void actualizarPosiciones();    
    NodoEnemigo* obtenerPrimero();          // [cite: 46]
};

#endif