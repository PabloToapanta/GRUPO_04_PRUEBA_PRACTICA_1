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
    NodoEnemigo* primero; 
    NodoEnemigo* ultimo;  

public:
    ListaDobleEnlazada(); //Destructor
    ~ListaDobleEnlazada();
    void insertarFinal(Enemigo nuevoEnemigo); 
    void eliminarDestruido(int id);           
    NodoEnemigo* buscarEnemigo(int id);       
    void recorrerAdelante();                  
    void recorrerAtras();                     
    void actualizarPosiciones();    
    NodoEnemigo* obtenerPrimero();          
};

#endif