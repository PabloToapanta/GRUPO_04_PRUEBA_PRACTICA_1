#include <iostream>
#include "ListaCircular.h" 

using namespace std;

// Constructor: Inicia los punteros en NULL
ListaCircular::ListaCircular() {
    ultimo = NULL;
    oleadaActual = NULL;
}

// Registro de Oleada: Inserta al final y mantiene la circularidad 
void ListaCircular::registrarOleada(Oleada nuevaOleada) {
    NodoOleada* nuevo = new NodoOleada();
    nuevo->dato = nuevaOleada;

    if (ultimo == NULL) {
        ultimo = nuevo;
        ultimo->siguiente = ultimo; // Se apunta a sí mismo para ser circular
        oleadaActual = ultimo;      // La primera registrada es la actual
    } else {
        nuevo->siguiente = ultimo->siguiente; // El nuevo apunta al primero
        ultimo->siguiente = nuevo;           // El viejo ultimo apunta al nuevo
        ultimo = nuevo;                      // Actualizamos quien es el ultimo
    }
}

// Avanzar: Mueve el puntero a la siguiente oleada y la devuelve 
Oleada* ListaCircular::avanzarSiguienteOleada() {
    if (oleadaActual != NULL) {
        oleadaActual = oleadaActual->siguiente;
        return &(oleadaActual->dato);
    }
    return NULL;
}

// Reiniciar: Vuelve el cursor al inicio de la lista 
void ListaCircular::reiniciarCiclo() {
    if (ultimo != NULL) {
        oleadaActual = ultimo->siguiente; // El siguiente del último es el primero
    }
}

// Mostrar: Recorre la lista circular una vez 
void ListaCircular::mostrarOleadas() {
    if (ultimo == NULL) {
        cout << "No hay oleadas registradas." << endl;
        return;
    }

    NodoOleada* aux = ultimo->siguiente; // Empezamos por el primero
    do {
        cout << "Oleada ID: " << aux->dato.idOleada 
             << " | Enemigos: " << aux->dato.cantidadEnemigos 
             << " | Vida: " << aux->dato.vidaBase << endl;
        aux = aux->siguiente;
    } while (aux != ultimo->siguiente); // Para cuando vuelve al inicio
}
